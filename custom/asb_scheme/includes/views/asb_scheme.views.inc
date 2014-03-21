<?php

/**
 * @file
 * Provides support for the Views module.
 */

function asb_scheme_views_data() {
  $data = array();
  $data['og_membership']['approve_button_membership'] = array(
      'field' => array(
          'title' => t('Approve Button'),
          'help' => t('Provide a simple button to approve the membership.'),
          'handler' => 'asb_scheme_handler_field_og_membership_approve_button',
      ),
  );
  $data['og_membership']['delete_button_membership'] = array(
      'field' => array(
          'title' => t('Delete Button'),
          'help' => t('Provide a simple button to delete the membership.'),
          'handler' => 'asb_scheme_handler_field_og_membership_delete_button',
      ),
  );
  return $data;
}
