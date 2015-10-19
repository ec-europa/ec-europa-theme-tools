<?php

/**
 * @file
 * Field groups configuration.
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nexteuropa_formatters_ctools_plugin_api($module, $api) {
  if ($module == 'field_group' && $api == 'field_group') {
    return array('version' => 1);
  }
}

/**
 * Implements hook_field_group_formatter_info().
 */
function nexteuropa_formatters_field_group_formatter_info() {
  $formatters = array();

  $formatters['meta_wrapper'] = array(
    'label' => t('Meta Wrapper'),
    'description' => t('This fieldgroup renders meta component wrapper'),
    'instance_settings' => array('modifier' => ''),
  );

  foreach (array_keys($formatters) as $key) {
    $formatter = &$formatters[$key];
    $formatter['instance_settings']['required_fields'] = 1;
  }

  return array(
    'form' => $formatters,
    'display' => $formatters,
  );
}

/**
 * Implements hook_field_group_format_settings().
 */
function nexteuropa_formatters_field_group_format_settings($group) {

  // Add a wrapper for extra settings to use by others.
  $form = array(
    'instance_settings' => array(
      '#tree' => TRUE,
      '#weight' => 5,
    ),
  );

  switch ($group->format_type) {
    case 'meta_wrapper':
      $form['instance_settings']['modifier'] = array(
        '#title' => t('Modifiers'),
        '#type' => 'select',
        '#options' => array(
          '' => t('None'),
          'meta--header' => t('Meta header'),
        ),
        '#default_value' => isset($group->format_settings['instance_settings']['modifier']) ? $group->format_settings['instance_settings']['modifier'] : '',
      );
      break;
  }

  return $form;
}

/**
 * Implements hook_field_group_pre_render().
 */
function nexteuropa_formatters_field_group_pre_render(&$element, $group, &$form) {
  // You can prepare some variables to use in the logic.
  $view_mode = isset($form['#view_mode']) ? $form['#view_mode'] : 'form';
  $id = $form['#entity_type'] . '_' . $form['#bundle'] . '_' . $view_mode . '_' . $group->group_name;

  // Each formatter type can have whole different set of element properties.
  switch ($group->format_type) {
    // Normal or collapsible div.
    case 'meta_wrapper':
      $add = array(
        '#type' => 'markup',
        '#weight' => $group->weight,
        '#id' => $id,
      );

      // Start with an empty modifier.
      $modifier = '';

      // Check if it is set and has a value. We do this because we dont want an
      // empty space after a class.
      if (isset($group->format_settings['instance_settings']['modifier']) && $group->format_settings['instance_settings']['modifier'] !== '') {
        $modifier = ' ' . $group->format_settings['instance_settings']['modifier'];
      }

      // Add it.
      $add['#prefix'] = '<div class="meta' . $modifier . '">';
      $add['#suffix'] = '</div>';

      $element += $add;
      break;
  }
}
