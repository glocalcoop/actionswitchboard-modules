<?php
/**
 * @file
 * asb_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function asb_features_user_default_roles() {
  $roles = array();

  // Exported role: Facilitator.
  $roles['Facilitator'] = array(
    'name' => 'Facilitator',
    'weight' => 6,
  );

  // Exported role: NGO Contact.
  $roles['NGO Contact'] = array(
    'name' => 'NGO Contact',
    'weight' => 8,
  );

  // Exported role: Scheme Leader.
  $roles['Scheme Leader'] = array(
    'name' => 'Scheme Leader',
    'weight' => 5,
  );

  // Exported role: Schemer.
  $roles['Schemer'] = array(
    'name' => 'Schemer',
    'weight' => 4,
  );

  // Exported role: Super Facilitator.
  $roles['Super Facilitator'] = array(
    'name' => 'Super Facilitator',
    'weight' => 7,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  // Exported role: anonymous user.
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
    'weight' => 0,
  );

  // Exported role: authenticated user.
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
    'weight' => 2,
  );

  return $roles;
}
