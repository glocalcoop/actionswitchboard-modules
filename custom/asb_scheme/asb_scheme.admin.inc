<?php


/**
 * Approve a single membership from group.
 */
function asb_scheme_approve_membership($form, &$form_state, $group_type, $gid, $og_membership) {
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));
  $group = entity_load_single($group_type, $gid);
  $label = entity_label($group_type, $group);
  $account = user_load($og_membership->etid);

  // You can't approve the group manager.
  if ($group->uid == $account->uid) {
    drupal_set_message(t("You can't approve membership of the group manager"));
    drupal_goto($group_type . '/' . $gid . '/group');
  }

  // Add group membership form. We still don't have the user or state.
  $form_state['og_membership'] = $og_membership;
  $membership = $form_state['og_membership'];
  $membership->state = 1;

  $membership->save();
  $path = explode('&', current_path());
  if(count($path) > 1){
    $goto = $path[1];
    $message = explode('/',$goto);
    $thread_id = $message[2];
    $tag_ids = array(2);
    global $user;
    privatemsg_filter_remove_tags(array($thread_id), $tag_ids, $user);
  }else{
    $goto = $group_type .'/' .$gid .'/' . 'group';
  }
  drupal_set_message(t('The membership was approved.'));
  drupal_goto($goto);
  return;
}

/**
 * This code could be used to do non-confirmation removals.
 * I think it's a bad idea, but if the policy gets changed,
 * we can use this code.
 */
/**
 * Delete a single membership from group.
 */
/* function asb_scheme_delete_membership($form, &$form_state, $group_type, $gid, $og_membership) { */
/*   og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group"))); */
/*   $group = entity_load_single($group_type, $gid); */
/*   $label = entity_label($group_type, $group); */
/*   $account = user_load($og_membership->etid); */

/*   // You can't delete the group manager. */
/*   if ($group->uid == $account->uid) { */
/*     drupal_set_message(t("You can't remove membership of the group manager")); */
/*     drupal_goto('group/' . $group_type . '/' . $gid . '/admin/people'); */
/*   } */

/*   // Add group membership form. We still don't have the user or state. */
/*   $form_state['og_membership'] = $og_membership; */
/*   $membership = $form_state['og_membership']; */

/*   $membership->delete(); */
/*   $path = explode('&', current_path()); */
/*   if(count($path) > 1){ */
/*     $goto = $path[1]; */
/*     $message = explode('/',$goto); */
/*     $thread_id = $message[2]; */
/*     $tag_ids = array(2); */
/*     global $user; */
/*     privatemsg_filter_remove_tags(array($thread_id), $tag_ids, $user); */
/*   }else{ */
/*     $goto = $group_type .'/' .$gid .'/' . 'group'; */
/*   } */
/*   drupal_set_message(t('The membership was rejected.')); */
/*   drupal_goto($goto); */
/*   return; */
/* } */

/**
 * Delete a single membership from group.
 */
function asb_scheme_delete_membership($form, &$form_state, $group_type, $gid, $og_membership) {
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));
  $group = entity_load_single($group_type, $gid);
  $label = entity_label($group_type, $group);
  $account = user_load($og_membership->etid);

  // You can't delete the group manager.
  if ($group->uid == $account->uid) {
    drupal_set_message(t("You can't remove membership of the group manager"));
    drupal_goto($group_type . '/' . $gid . '/group');
  }

  $path = explode('&', current_path());
  $form_state['goto'] = $path;
  // Add group membership form. We still don't have the user or state.
  $form_state['og_membership'] = $og_membership;
  return confirm_form($form,
    t('Remove membership in group @group', array('@group' => $label)),
    $group_type . '/' . $gid . '/group',
    t('Are you sure you would like to remove the membership for the user @user', array('@user' => $account->name)),
    t('Remove'),
    t('Cancel')
  );
}

/**
 * Submit handler;Delete the membership.
 */
function asb_scheme_delete_membership_submit($form, &$form_state) {
  $path = $form_state['goto'];
  $membership = $form_state['og_membership'];
  $group_type = $membership->group_type;
  $gid = $membership->gid;
  if(count($path) > 1){
    $goto = $path[1];
    $message = explode('/',$goto);
    $thread_id = $message[2];
    $tag_ids = array(2);
    global $user;
    privatemsg_filter_remove_tags(array($thread_id), $tag_ids, $user);
  }else{
    $goto = $group_type .'/' .$gid .'/' . 'group';
  }
  $membership->delete();
  // $form_state['redirect'] = 'group/' . $membership->group_type . '/' . $membership->gid . '/admin/people';
  $form_state['redirect'] = $goto;
  drupal_set_message(t('The membership was removed.'));
}

/**
 * Provide an overview of the administrator menu items.
 *
 * This function taken from og_ui.admin.inc
 * 
 * @param $entity_type
 *   The entity type.
 * @param $etid
 *   The entity ID.
 */
function asb_scheme_group_admin_overview($entity_type, $etid) {
  og_set_breadcrumb($entity_type, $etid);

  $items = og_ui_get_group_admin($entity_type, $etid);
  foreach ($items as &$item) {
    // Re-format the URL.
    $item['href'] = "group/$entity_type/$etid/" . $item['href'];
    // Imitate the menu_get_item() content, so we can pass it to
    // theme_admin_block_content(), so we add the localized_options key.
    $item['localized_options'] = array();
  }

  $form['admin_block_content'] = array('#theme' => 'admin_block_content', '#content' => $items);
  // $form = "Hi mom";
  // list($view_name, $display) = explode(':', variable_get('og_ui_admin_people_view', 'scheme_members_admin:default'));
  $view_name = 'scheme_members_admin';
  $display = 'default';
  // We can't use views_embed_view() as we have exposed filter, and we need to
  // make sure the path is overriden to the current URL.
  // @see http://drupal.org/node/525592#comment-1968604
  $view = views_get_view($view_name, $display);
  $view->set_arguments(array('node', $etid));
  $view->override_url = $_GET['q'];
  $preview = $view->preview();
  return $preview;
}

