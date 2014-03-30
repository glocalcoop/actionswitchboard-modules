<?php
/**
 * @file
 * asb_features.features.workflow_access.inc
 */

/**
 * Implements hook_workflow_access_features_default_settings().
 */
function asb_features_workflow_access_features_default_settings() {
  $workflows = array();

  $workflows['Goal Recommendation'] = array();
  $workflows['Goal Recommendation']['Needs Review'] = array();
  $workflows['Goal Recommendation']['Needs Review']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Needs Review']['Facilitator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Needs Review']['Super Facilitator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Needs Review']['workflow_features_author_name'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Needs Review']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Needs Review']['Schemer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Needs Review']['Scheme Leader'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Needs Review']['NGO Contact'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Approved'] = array();
  $workflows['Goal Recommendation']['Approved']['authenticated user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Approved']['administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Approved']['Schemer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Approved']['Scheme Leader'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Approved']['Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Approved']['Super Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Approved']['NGO Contact'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Approved']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Rejected'] = array();
  $workflows['Goal Recommendation']['Rejected']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Rejected']['Facilitator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Rejected']['Super Facilitator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Rejected']['workflow_features_author_name'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 1,
  );
  $workflows['Goal Recommendation']['Rejected']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Rejected']['Schemer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Rejected']['Scheme Leader'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Goal Recommendation']['Rejected']['NGO Contact'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );

  $workflows['Scheme Creation'] = array();
  $workflows['Scheme Creation']['Needs Review'] = array();
  $workflows['Scheme Creation']['Needs Review']['workflow_features_author_name'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Needs Review']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Needs Review']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Needs Review']['administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Needs Review']['Schemer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Needs Review']['Scheme Leader'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Needs Review']['Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Needs Review']['Super Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Needs Review']['NGO Contact'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Rejected'] = array();
  $workflows['Scheme Creation']['Rejected']['workflow_features_author_name'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Rejected']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Rejected']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Rejected']['administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Rejected']['Schemer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Rejected']['Scheme Leader'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Rejected']['Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Rejected']['Super Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Rejected']['NGO Contact'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Active'] = array();
  $workflows['Scheme Creation']['Active']['anonymous user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Active']['authenticated user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Active']['administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Active']['Schemer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Active']['Scheme Leader'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Active']['Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Active']['Super Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Active']['NGO Contact'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Active']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Completed'] = array();
  $workflows['Scheme Creation']['Completed']['anonymous user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Completed']['authenticated user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Completed']['administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Completed']['Schemer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Completed']['Scheme Leader'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Completed']['Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Completed']['Super Facilitator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Scheme Creation']['Completed']['NGO Contact'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Scheme Creation']['Completed']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 0,
  );

  return $workflows;
}
