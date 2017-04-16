<?php
/**
 * @file
 * dt_europa_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_europa_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_field_template';
  $strongarm->value = 1;
  $export['ds_extras_field_template'] = $strongarm;

  return $export;
}
