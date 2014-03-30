<?php
/**
 * @file
 * asb_features.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function asb_features_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:scheme:Scheme Leader'.
  $roles['node:scheme:Scheme Leader'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'scheme',
    'name' => 'Scheme Leader',
  );

  // Exported OG Role: 'node:scheme:Schemer'.
  $roles['node:scheme:Schemer'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'scheme',
    'name' => 'Schemer',
  );

  return $roles;
}
