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
