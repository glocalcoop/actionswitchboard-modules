<?php
/**
 * @file
 * asb_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function asb_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = 'Controls the blocks displayed on the facilitator dashboard page.';
  $context->tag = 'user-interface';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard' => 'dashboard',
        'dashboard/*' => 'dashboard/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'Facilitator' => 'Facilitator',
        'Super Facilitator' => 'Super Facilitator',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-notifications' => array(
          'module' => 'quicktabs',
          'delta' => 'notifications',
          'region' => 'content',
          'weight' => '-10',
        ),
        'quicktabs-schemes' => array(
          'module' => 'quicktabs',
          'delta' => 'schemes',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-90f7e874863d363adf55056301e69084' => array(
          'module' => 'views',
          'delta' => '90f7e874863d363adf55056301e69084',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls the blocks displayed on the facilitator dashboard page.');
  t('user-interface');
  $export['dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard_schemers';
  $context->description = 'Controls the blocks displayed on non-facilitator dashboard page.';
  $context->tag = 'user-interface';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~dashboard' => '~dashboard',
      ),
    ),
    'path' => array(
      'values' => array(
        'dashboard' => 'dashboard',
        'dashboard/*' => 'dashboard/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'Scheme Leader' => 'Scheme Leader',
        'Schemer' => 'Schemer',
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-notifications' => array(
          'module' => 'quicktabs',
          'delta' => 'notifications',
          'region' => 'content',
          'weight' => '-10',
        ),
        'quicktabs-schemes_for_schemers' => array(
          'module' => 'quicktabs',
          'delta' => 'schemes_for_schemers',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls the blocks displayed on non-facilitator dashboard page.');
  t('user-interface');
  $export['dashboard_schemers'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Front page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-scheme_overview-block_4' => array(
          'module' => 'views',
          'delta' => 'scheme_overview-block_4',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-scheme_overview-block_2' => array(
          'module' => 'views',
          'delta' => 'scheme_overview-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-scheme_overview-block_3' => array(
          'module' => 'views',
          'delta' => 'scheme_overview-block_3',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-scheme_overview-block_1' => array(
          'module' => 'views',
          'delta' => 'scheme_overview-block_1',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-d85f9e9e1e55d3b106572c4bda859677' => array(
          'module' => 'views',
          'delta' => 'd85f9e9e1e55d3b106572c4bda859677',
          'region' => 'bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'goal';
  $context->description = 'Goal contextual layout (mostly for sidebars)';
  $context->tag = 'node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'goal' => 'goal',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Goal contextual layout (mostly for sidebars)');
  t('node');
  $export['goal'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'goal_add';
  $context->description = 'Add blocks to goal add';
  $context->tag = 'node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'goal' => 'goal',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content',
          'weight' => '-50',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add blocks to goal add');
  t('node');
  $export['goal_add'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'goal_taxonomy';
  $context->description = 'Display criteria for goals (taxonomy terms)';
  $context->tag = 'taxonomy';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'goals/*' => 'goals/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-66bdec9b9f4ce57f714b9d45808dd248' => array(
          'module' => 'views',
          'delta' => '66bdec9b9f4ce57f714b9d45808dd248',
          'region' => 'content',
          'weight' => '-10',
        ),
        'asb_issues-goals_tree' => array(
          'module' => 'asb_issues',
          'delta' => 'goals_tree',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display criteria for goals (taxonomy terms)');
  t('taxonomy');
  $export['goal_taxonomy'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'help_section';
  $context->description = 'Help sections contextual layouts';
  $context->tag = 'Help/FAQ';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'help/*' => 'help/*',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'asb' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'zen' => array(
        'disable' => array(
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Help sections contextual layouts');
  t('Help/FAQ');
  $export['help_section'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'issue';
  $context->description = 'Issue contextual layout (primarily for sidebar)';
  $context->tag = 'node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'issue' => 'issue',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-eb7a64d23c068dfaccc0361020005420' => array(
          'module' => 'views',
          'delta' => 'eb7a64d23c068dfaccc0361020005420',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-a122a7f7eb2bfd084c9e859000fac58a' => array(
          'module' => 'views',
          'delta' => 'a122a7f7eb2bfd084c9e859000fac58a',
          'region' => 'content',
          'weight' => '-9',
        ),
        'asb_issues-goals_tree' => array(
          'module' => 'asb_issues',
          'delta' => 'goals_tree',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Issue contextual layout (primarily for sidebar)');
  t('node');
  $export['issue'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'navigation';
  $context->description = 'Blocks that should always appear.';
  $context->tag = 'all-pages';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-asb_util-1' => array(
          'module' => 'menu_block',
          'delta' => 'asb_util-1',
          'region' => 'header',
          'weight' => '-10',
        ),
        'menu-menu-social-links' => array(
          'module' => 'menu',
          'delta' => 'menu-social-links',
          'region' => 'header',
          'weight' => '-9',
        ),
        'asb_scheme-user_message' => array(
          'module' => 'asb_scheme',
          'delta' => 'user_message',
          'region' => 'header',
          'weight' => '-8',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'views-goal_taxonomy_test-block' => array(
          'module' => 'views',
          'delta' => 'goal_taxonomy_test-block',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'views-inspiration_footer-block' => array(
          'module' => 'views',
          'delta' => 'inspiration_footer-block',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'menu-menu-as' => array(
          'module' => 'menu',
          'delta' => 'menu-as',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that should always appear.');
  t('all-pages');
  $export['navigation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'no_scheme_filter';
  $context->description = 'This shows the scheme filter block on some pages.';
  $context->tag = 'scheme-filter';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~dashboard' => '~dashboard',
        '~dashboard/*' => '~dashboard/*',
        '~civicrm' => '~civicrm',
        '~civicrm/*' => '~civicrm/*',
        '~user/register' => '~user/register',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-69eb07f162c05071e120e05770838423' => array(
          'module' => 'views',
          'delta' => '69eb07f162c05071e120e05770838423',
          'region' => 'search',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This shows the scheme filter block on some pages.');
  t('scheme-filter');
  $export['no_scheme_filter'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'other_dashboards';
  $context->description = 'Extra displays for dashboard like contexts.';
  $context->tag = 'user-interface';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'scheme-message' => 'scheme-message',
        'facilitator-dashboard' => 'facilitator-dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-schemes' => array(
          'module' => 'quicktabs',
          'delta' => 'schemes',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Extra displays for dashboard like contexts.');
  t('user-interface');
  $export['other_dashboards'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scheme';
  $context->description = 'Context for scheme block placement (particularly in sidebar)';
  $context->tag = 'Scheme';
  $context->conditions = array(
    'author' => array(
      'values' => array(
        'is_not_author' => 'is_not_author',
      ),
    ),
    'node' => array(
      'values' => array(
        'scheme' => 'scheme',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'asb_scheme-group_info' => array(
          'module' => 'asb_scheme',
          'delta' => 'group_info',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-scheme_members-block_1' => array(
          'module' => 'views',
          'delta' => 'scheme_members-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-scheme_contribute-block' => array(
          'module' => 'views',
          'delta' => 'scheme_contribute-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-scheme_contribute-block_1' => array(
          'module' => 'views',
          'delta' => 'scheme_contribute-block_1',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-scheme_contribute-block_2' => array(
          'module' => 'views',
          'delta' => 'scheme_contribute-block_2',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for scheme block placement (particularly in sidebar)');
  t('Scheme');
  $export['scheme'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scheme_author';
  $context->description = 'Context for scheme block placement (particularly in sidebar)';
  $context->tag = 'Scheme';
  $context->conditions = array(
    'author' => array(
      'values' => array(
        'is_author' => 'is_author',
      ),
    ),
    'node' => array(
      'values' => array(
        'scheme' => 'scheme',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-925ec4f76f8d53da36cf50cc845b8316' => array(
          'module' => 'views',
          'delta' => '925ec4f76f8d53da36cf50cc845b8316',
          'region' => 'sidebar_second',
          'weight' => '-43',
        ),
        'asb_scheme-group_info' => array(
          'module' => 'asb_scheme',
          'delta' => 'group_info',
          'region' => 'sidebar_second',
          'weight' => '-42',
        ),
        'views-scheme_members-block_1' => array(
          'module' => 'views',
          'delta' => 'scheme_members-block_1',
          'region' => 'sidebar_second',
          'weight' => '-41',
        ),
        'views-scheme_contribute-block' => array(
          'module' => 'views',
          'delta' => 'scheme_contribute-block',
          'region' => 'sidebar_second',
          'weight' => '-40',
        ),
        'views-scheme_contribute-block_1' => array(
          'module' => 'views',
          'delta' => 'scheme_contribute-block_1',
          'region' => 'sidebar_second',
          'weight' => '-39',
        ),
        'views-scheme_contribute-block_2' => array(
          'module' => 'views',
          'delta' => 'scheme_contribute-block_2',
          'region' => 'sidebar_second',
          'weight' => '-38',
        ),
        'asb_scheme-facilitator_contact' => array(
          'module' => 'asb_scheme',
          'delta' => 'facilitator_contact',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for scheme block placement (particularly in sidebar)');
  t('Scheme');
  $export['scheme_author'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scheme_creation';
  $context->description = 'Scheme creation contextual layouts';
  $context->tag = 'Scheme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/add/scheme' => 'node/add/scheme',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'asb' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'zen' => array(
        'disable' => array(
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scheme');
  t('Scheme creation contextual layouts');
  $export['scheme_creation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = 'User Profile context';
  $context->tag = 'User';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'form' => 'form',
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'asb' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'navigation' => 0,
          'search' => 0,
          'tour' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'zen' => array(
        'disable' => array(
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  t('User Profile context');
  $export['user_profile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile_no_edit';
  $context->description = 'Display for the user profile page when not editing.';
  $context->tag = 'User';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-467d272784c6e1a84b15cc4f6b486792' => array(
          'module' => 'views',
          'delta' => '467d272784c6e1a84b15cc4f6b486792',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-741a73ef0a114f623b54449caf2fc4fb' => array(
          'module' => 'views',
          'delta' => '741a73ef0a114f623b54449caf2fc4fb',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-997f8cf8c2d78c2a03a9bb156443c392' => array(
          'module' => 'views',
          'delta' => '997f8cf8c2d78c2a03a9bb156443c392',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display for the user profile page when not editing.');
  t('User');
  $export['user_profile_no_edit'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_registration';
  $context->description = 'User registration contextual layout';
  $context->tag = 'User';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'register' => 'register',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'asb' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'zen' => array(
        'disable' => array(
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  t('User registration contextual layout');
  $export['user_registration'] = $context;

  return $export;
}
