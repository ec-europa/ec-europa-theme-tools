<?php
/**
 * @file
 * dt_europa_settings.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_europa_settings_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ec_europa_ct|ec_europa_node';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ec_europa_ct';
  $ds_fieldsetting->view_mode = 'ec_europa_node';
  $ds_fieldsetting->settings = array(
    'europa_content_type_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|ec_europa_ct|ec_europa_node'] = $ds_fieldsetting;

  return $export;
}
