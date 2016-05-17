<?php
/**
 * @file
 * This file contains examples of hooks that can be implemented.
 */

/**
 * This hook allows you to alter the settings array used by dt shared functions.
 *
 * The array index is the name of the configuration.
 * All array keys are required:
 *  - title -> Title of the field.
 *  - type -> form type, see form api.
 *  - description -> description of the field.
 *  - required -> True/False.
 *
 * @param array $settings
 *   Argument by reference containing the settings.
 */
function hook_dt_shared_functions_views_config_alter(&$settings) {
  $settings['dt_shared_functions_views_config_title'] = [
    'title' => t('Title'),
    'type' => 'textfield',
    'description' => t('The title to display in the counter result.'),
    'required' => FALSE,
  ];
}

/**
 * This hook allows you to alter the configuration of facet blocks.
 *
 * For this hook to take effect, a cache clear is required.
 *
 * @param array $blocks
 *   The array of facet blocks. Passed by reference.
 * @param string $block_identifier
 *   The identifying string of the block.
 */
function hook_dt_shared_functions_facet_block_alter(&$blocks, $block_identifier) {
  // Based on the block idetnifier we change the title.
  switch ($block_identifier) {
    case 'field_core_location:country':
      $block_title = t('Country');
      break;

    case 'status':
      $block_title = '<none>';
      break;
  }

  // Modify block title if it's set.
  if (isset($block_title)) {
    $block['title'] = $block_title;
  }
}
