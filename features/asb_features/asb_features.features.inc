<?php
/**
 * @file
 * asb_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function asb_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "block_machine_name" && $api == "") {
    return array("version" => "");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "msnf" && $api == "msnf") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "taxonomy_display" && $api == "taxonomy_display") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function asb_features_image_default_styles() {
  $styles = array();

  // Exported image style: asb_scheme_leader_thumb.
  $styles['asb_scheme_leader_thumb'] = array(
    'name' => 'asb_scheme_leader_thumb',
    'label' => 'asb_scheme_leader_thumb',
    'effects' => array(
      16 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: asb_scheme_preview_thumb.
  $styles['asb_scheme_preview_thumb'] = array(
    'name' => 'asb_scheme_preview_thumb',
    'label' => 'asb_scheme_preview_thumb',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 325,
          'height' => 187,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: asb_scheme_slideshow_full.
  $styles['asb_scheme_slideshow_full'] = array(
    'name' => 'asb_scheme_slideshow_full',
    'label' => 'asb_scheme_slideshow_full',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 666,
          'height' => 370,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: footer_thumbnail.
  $styles['footer_thumbnail'] = array(
    'name' => 'footer_thumbnail',
    'label' => 'footer_thumbnail',
    'effects' => array(
      17 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 70,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: scheme_admin_profile.
  $styles['scheme_admin_profile'] = array(
    'name' => 'scheme_admin_profile',
    'label' => 'scheme_admin_profile',
    'effects' => array(),
  );

  // Exported image style: scheme_overview.
  $styles['scheme_overview'] = array(
    'name' => 'scheme_overview',
    'label' => 'scheme_overview',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 325,
          'height' => 187,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_image_default.
  $styles['user_image_default'] = array(
    'name' => 'user_image_default',
    'label' => 'user_image_default',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_image_profile.
  $styles['user_image_profile'] = array(
    'name' => 'user_image_profile',
    'label' => 'user_image_profile',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 214,
          'height' => 214,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_image_scheme_leader.
  $styles['user_image_scheme_leader'] = array(
    'name' => 'user_image_scheme_leader',
    'label' => 'user_image_scheme_leader',
    'effects' => array(
      15 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_image_schemer.
  $styles['user_image_schemer'] = array(
    'name' => 'user_image_schemer',
    'label' => 'user_image_schemer',
    'effects' => array(
      14 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_message_type().
 */
function asb_features_default_message_type() {
  $items = array();
  $items['group_content'] = entity_import('message_type', '{
    "name" : "group_content",
    "description" : "Group Content",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:field-og-ref:title] content added\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : " \\u003Cp\\u003E[message:field-og-ref:title] content added\\u003C\\/p\\u003E\\n "
        },
        {
          "value" : "\\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E[message:field-node-ref-with-og:author] posted a new [message:field-node-ref-with-og:content-type] to \\u003Ca href=\\u0022[message:field-og-ref:url]\\u0022\\u003E[message:field-og-ref:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EYou can \\u003Ca href=\\u0022[message:field-node-ref-with-og:url]\\u0022\\u003Ego here to read it or comment on it\\u003C\\/a\\u003E on the Action Switchboard.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EHere\\u0026#39;s the full message:\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref-with-og:node-teaser]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EIf you don\\u0026#39;t wish to receive email notificatons please visit your \\u003Ca href=\\u0022[site:url]user\\/[message:user:uid]\\/message-subscribe\\u0022\\u003ESubscriptions Page.\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : " \\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-node-ref-with-og:author] posted a new [message:field-node-ref-with-og:content-type] to \\u003Ca href=\\u0022[message:field-og-ref:url]\\u0022\\u003E[message:field-og-ref:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can \\u003Ca href=\\u0022[message:field-node-ref-with-og:url]\\u0022\\u003Ego here to read it or comment on it\\u003C\\/a\\u003E on the Action Switchboard.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EHere\\u0027s the full message:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref-with-og:node-teaser]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u00a0\\u003C\\/p\\u003E\\n\\u003Cp\\u003EIf you don\\u0027t wish to receive email notificatons please visit your \\u003Ca href=\\u0022[site:url]user\\/[message:user:uid]\\/message-subscribe\\u0022\\u003ESubscriptions Page.\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n "
        },
        {
          "value" : "\\u003Cp\\u003E[message:field-node-ref-with-og:author] posted a new [message:field-node-ref-with-og:content-type] to \\u003Ca href=\\u0022[message:field-og-ref:url]\\u0022\\u003E[message:field-og-ref:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EIt says:\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E[message:field-node-ref-with-og:node-teaser]\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : " \\u003Cp\\u003E[message:field-node-ref-with-og:author] posted a new [message:field-node-ref-with-og:content-type] to \\u003Ca href=\\u0022[message:field-og-ref:url]\\u0022\\u003E[message:field-og-ref:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n\\u003Cp\\u003EIt says:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-node-ref-with-og:node-teaser]\\u003C\\/p\\u003E\\n "
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function asb_features_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'book' => array(
      'name' => t('Book page'),
      'base' => 'node_content',
      'description' => t('<em>Books</em> have a built-in hierarchical navigation. Use for handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'document' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => t('Use this content type for Action Switchboard Documentation.  This includes help pages, homework pages, and other informative documentation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'goal' => array(
      'name' => t('Goal'),
      'base' => 'node_content',
      'description' => t('Goals are particular things we want to accomplish as part of an issue.'),
      'has_title' => '1',
      'title_label' => t('Goal Name'),
      'help' => '',
    ),
    'issue' => array(
      'name' => t('Issue'),
      'base' => 'node_content',
      'description' => t('This is a visionary goal.  What would you like to see changed?'),
      'has_title' => '1',
      'title_label' => t('Issue Name'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scheme' => array(
      'name' => t('Scheme'),
      'base' => 'node_content',
      'description' => t('Propose a scheme for the Yes Labs.'),
      'has_title' => '1',
      'title_label' => t('Scheme Name'),
      'help' => '',
    ),
    'update' => array(
      'name' => t('Update'),
      'base' => 'node_content',
      'description' => t('Add an update to your scheme. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_workflow_default_workflows().
 */
function asb_features_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Goal Recommendation
  $workflows['Goal Recommendation'] = array(
    'name' => 'Goal Recommendation',
    'tab_roles' => 'author,3,6',
    'options' => 'a:4:{s:16:"comment_log_node";s:1:"0";s:15:"comment_log_tab";s:1:"0";s:13:"name_as_title";s:1:"1";s:12:"watchdog_log";s:1:"0";}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Goal Recommendation',
      ),
      1 => array(
        'state' => 'Needs Review',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Goal Recommendation',
      ),
      2 => array(
        'state' => 'Approved',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Goal Recommendation',
      ),
      3 => array(
        'state' => 'Rejected',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Goal Recommendation',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name,administrator,Facilitator,Super Facilitator',
        'state' => '(creation)',
        'target_state' => 'Needs Review',
      ),
      1 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => '(creation)',
        'target_state' => 'Approved',
      ),
      2 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => '(creation)',
        'target_state' => 'Rejected',
      ),
      3 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Needs Review',
        'target_state' => 'Approved',
      ),
      4 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Needs Review',
        'target_state' => 'Rejected',
      ),
      5 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Approved',
        'target_state' => 'Needs Review',
      ),
      6 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Approved',
        'target_state' => 'Rejected',
      ),
      7 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Rejected',
        'target_state' => 'Needs Review',
      ),
      8 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Rejected',
        'target_state' => 'Approved',
      ),
    ),
    'node_types' => array(
      0 => 'goal',
    ),
  );

  // Exported workflow: Scheme Creation
  $workflows['Scheme Creation'] = array(
    'name' => 'Scheme Creation',
    'tab_roles' => '3,6,7',
    'options' => 'a:4:{s:16:"comment_log_node";s:1:"1";s:15:"comment_log_tab";s:1:"1";s:13:"name_as_title";s:1:"0";s:12:"watchdog_log";s:1:"1";}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Scheme Creation',
      ),
      1 => array(
        'state' => 'Needs Review',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Scheme Creation',
      ),
      2 => array(
        'state' => 'Rejected',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Scheme Creation',
      ),
      3 => array(
        'state' => 'Active',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Scheme Creation',
      ),
      4 => array(
        'state' => 'Completed',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Scheme Creation',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name,administrator,Facilitator,Super Facilitator',
        'state' => '(creation)',
        'target_state' => 'Needs Review',
      ),
      1 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => '(creation)',
        'target_state' => 'Rejected',
      ),
      2 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => '(creation)',
        'target_state' => 'Active',
      ),
      3 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => '(creation)',
        'target_state' => 'Completed',
      ),
      4 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Needs Review',
        'target_state' => 'Rejected',
      ),
      5 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Needs Review',
        'target_state' => 'Active',
      ),
      6 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Needs Review',
        'target_state' => 'Completed',
      ),
      7 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Rejected',
        'target_state' => 'Needs Review',
      ),
      8 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Rejected',
        'target_state' => 'Active',
      ),
      9 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Rejected',
        'target_state' => 'Completed',
      ),
      10 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Active',
        'target_state' => 'Needs Review',
      ),
      11 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Active',
        'target_state' => 'Completed',
      ),
      12 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Completed',
        'target_state' => 'Needs Review',
      ),
      13 => array(
        'roles' => 'administrator,Facilitator,Super Facilitator',
        'state' => 'Completed',
        'target_state' => 'Active',
      ),
    ),
    'node_types' => array(
      0 => 'scheme',
    ),
  );

  return $workflows;
}
