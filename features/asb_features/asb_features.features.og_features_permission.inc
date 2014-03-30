<?php
/**
 * @file
 * asb_features.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function asb_features_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:scheme:add user'
  $permissions['node:scheme:add user'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
    ),
  );

  // Exported og permission: 'node:scheme:administer group'
  $permissions['node:scheme:administer group'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
    ),
  );

  // Exported og permission: 'node:scheme:approve and deny subscription'
  $permissions['node:scheme:approve and deny subscription'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
    ),
  );

  // Exported og permission: 'node:scheme:create announcement content'
  $permissions['node:scheme:create announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:create event content'
  $permissions['node:scheme:create event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:create update content'
  $permissions['node:scheme:create update content'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
      'Schemer' => 'Schemer',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:scheme:delete any announcement content'
  $permissions['node:scheme:delete any announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:delete any event content'
  $permissions['node:scheme:delete any event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:delete any update content'
  $permissions['node:scheme:delete any update content'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
    ),
  );

  // Exported og permission: 'node:scheme:delete own announcement content'
  $permissions['node:scheme:delete own announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:delete own event content'
  $permissions['node:scheme:delete own event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:delete own update content'
  $permissions['node:scheme:delete own update content'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
      'Schemer' => 'Schemer',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:scheme:manage members'
  $permissions['node:scheme:manage members'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:manage permissions'
  $permissions['node:scheme:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:manage roles'
  $permissions['node:scheme:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:subscribe'
  $permissions['node:scheme:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:scheme:subscribe without approval'
  $permissions['node:scheme:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:unsubscribe'
  $permissions['node:scheme:unsubscribe'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
      'Schemer' => 'Schemer',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:scheme:update any announcement content'
  $permissions['node:scheme:update any announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:update any event content'
  $permissions['node:scheme:update any event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:update any update content'
  $permissions['node:scheme:update any update content'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
    ),
  );

  // Exported og permission: 'node:scheme:update group'
  $permissions['node:scheme:update group'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
    ),
  );

  // Exported og permission: 'node:scheme:update own announcement content'
  $permissions['node:scheme:update own announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:update own event content'
  $permissions['node:scheme:update own event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:scheme:update own update content'
  $permissions['node:scheme:update own update content'] = array(
    'roles' => array(
      'Scheme Leader' => 'Scheme Leader',
      'Schemer' => 'Schemer',
      'member' => 'member',
    ),
  );

  return $permissions;
}
