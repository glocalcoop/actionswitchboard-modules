<?php
/**
 * @file
 * asb_features..inc
 */

/**
 * Implements hook_default_block_machine_name_boxes().
 */
function asb_features_default_block_machine_name_boxes() {
  $export = array();

  $block_machine_name_boxes = new stdClass();
  $block_machine_name_boxes->machine_name = 'goal_recommendation_help';
  $export['goal_recommendation_help'] = $block_machine_name_boxes;

  return $export;
}
