<?php

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * "OG membership" entity Views definitions.
 */
class AsbSchemeViewsController extends OgMembershipViewsController {
  
  /**
   * Override views_data().
   */
  public function views_data() {
    $data = parent::views_data();
    dsm($data);
    // Link to delete membership.
    $data['og_membership']['dbutton_membership'] = array(
      'field' => array(
        'title' => t('Delete Button'),
        'help' => t('Provide a simple delete button fo the membership.'),
        'handler' => 'asb_scheme_handler_field_og_membership_delete_button',
      ),
    );

    return $data;
  }
}
