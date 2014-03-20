<?php


/**
 * Delete a single membership from group.
 */
function asb_scheme_approve_membership($form, &$form_state, $group_type, $gid, $og_membership) {
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));
  $group = entity_load_single($group_type, $gid);
  $label = entity_label($group_type, $group);
  $account = user_load($og_membership->etid);

  // You can't delete the group manager.
  if ($group->uid == $account->uid) {
    drupal_set_message(t("You can't remove membership of the group manager"));
    drupal_goto('group/' . $group_type . '/' . $gid . '/admin/people');
  }

  // Add group membership form. We still don't have the user or state.
  $form_state['og_membership'] = $og_membership;

  $membership = $form_state['og_membership'];
  $membership->state = 1;
  $membership->save();
  drupal_set_message(t('The membership was approved.'));
  drupal_goto($group_type .'/' .$gid .'/' . 'group');
  return;
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