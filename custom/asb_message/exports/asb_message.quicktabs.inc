<?php

/**
 * Implements hook_quicktabs_default_quicktabs()
 * 
 * Ensure our quictabs get created
 */
function asb_message_quicktabs_default_quicktabs() {
  $export = array();
  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'notifications';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Notifications';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'asb_message_delta_pmessages',
      'hide_title' => 1,
      'title' => 'Messages',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_scheme_messages-block_1',
      'hide_title' => 1,
      'title' => 'Updates',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'views_delta_2880e86ff984f3de669e71c0155d2bbc',
      'hide_title' => 1,
      'title' => 'Following',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Asbtabs';
  $quicktabs->options = array();

  $export['notifications'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'schemes';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Schemes';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_scheme_list_for_users-block',
      'hide_title' => 1,
      'title' => 'All',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_scheme_list_for_users-block_1',
      'hide_title' => 1,
      'title' => 'I\'ve Adopted',
      'weight' => '-98',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'views_delta_scheme_user_groups-block_2',
      'hide_title' => 1,
      'title' => 'I\'m Running',
      'weight' => '-97',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'views_delta_scheme_user_groups-block_1',
      'hide_title' => 1,
      'title' => 'I\'m a Member',
      'weight' => '-96',
      'type' => 'block',
    ),
    4 => array(
      'bid' => 'views_delta_scheme_user_groups-block_3',
      'hide_title' => 1,
      'title' => 'I\'m Following',
      'weight' => '-96',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Asbtabs';
  $quicktabs->options = array();

  $export['schemes'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'schemes_for_schemers';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Schemes';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_scheme_list_for_users-block_2',
      'hide_title' => 1,
      'title' => 'All',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_scheme_user_groups-block_2',
      'hide_title' => 1,
      'title' => 'I\'m Running',
      'weight' => '-97',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'views_delta_scheme_user_groups-block_3',
      'hide_title' => 1,
      'title' => 'I\'m Following',
      'weight' => '-97',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'views_delta_scheme_user_groups-block_1',
      'hide_title' => 1,
      'title' => 'I\'m a Member',
      'weight' => '-96',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Asbtabs';
  $quicktabs->options = array();

  $export['schemes_for_schemers'] = $quicktabs;

  return $export;
}
