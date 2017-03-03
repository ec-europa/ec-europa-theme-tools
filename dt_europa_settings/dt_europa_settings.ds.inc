<?php
/**
 * @file
 * dt_europa_settings.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_europa_settings_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'europa_content_type_label';
  $ds_field->label = 'Content type label';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:content-type]',
      'format' => 'basic_html',
    ),
    'use_token' => 1,
  );
  $export['europa_content_type_label'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'collapse_button';
  $ds_field->label = 'Collapse button';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
    'comment' => 'comment',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<button class="btn btn-collapse" type="button" data-toggle="collapse" data-target="#collapse" aria-expanded="false" aria-controls="collapse"><span class="toggling-text"></span>[node:field-core-collapse-button-text]<i class="icon icon--blue-dark icon--down"></i></button>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['europa_collapse_button'] = $ds_field;

  return $export;
}
