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
    'instance_settings' => array(
      'modifier' => '',
      'classes' => '',
    ),
  );

  $formatters['context_nav'] = array(
    'label' => t('Context Nav'),
    'description' => t('This fieldgroup renders the context nav wrapper'),
    'instance_settings' => array(
      'modifier' => '',
      'classes' => '',
    ),
  );

  $formatters['section_group'] = array(
    'label' => t('Section Group'),
    'description' => t('Section Group wrapper that should be used in display suite regions that are being wrapped with Section class'),
    'instance_settings' => array(
      'modifier' => '',
      'layout' => '',
      'classes' => '',
    ),
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
 *
 * It might be possible that the #options only contains "None", this has been
 * added as a temporary placeholder. Whenever a new modifier is being added to
 * the system, we should add it here.
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

    case 'context_nav':
      $form['instance_settings']['modifier'] = array(
        '#title' => t('Modifiers'),
        '#type' => 'select',
        '#options' => array(
          '' => t('None'),
        ),
        '#default_value' => isset($group->format_settings['instance_settings']['modifier']) ? $group->format_settings['instance_settings']['modifier'] : '',
      );
      break;

    case 'section_group':
      $form['instance_settings']['modifier'] = array(
        '#title' => t('Modifiers'),
        '#type' => 'select',
        '#options' => array(
          '' => t('None'),
          'section__group--full-width' => t('Full width'),
          'section__group--highlight-grey' => t('Highlight Grey'),
          'section__group--highlight-yellow' => t('Highlight Yellow'),
        ),
        '#default_value' => isset($group->format_settings['instance_settings']['modifier']) ? $group->format_settings['instance_settings']['modifier'] : '',
      );

      $form['instance_settings']['layout'] = array(
        '#title' => t('Extra Layout'),
        '#type' => 'select',
        '#options' => array(
          '' => t('None'),
          'col-md-8' => t('Column 8'),
          'col-md-9' => t('Column 9'),
        ),
        '#default_value' => isset($group->format_settings['instance_settings']['layout']) ? $group->format_settings['instance_settings']['layout'] : '',
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

      // Add our modifiers and classes.
      $modifier_and_classes = '';
      // Add only those with data.
      if (isset($group->format_settings['instance_settings']['modifier']) && $group->format_settings['instance_settings']['modifier'] !== '') {
        $modifier_and_classes .= ' ' . $group->format_settings['instance_settings']['modifier'];
      }
      if (isset($group->format_settings['instance_settings']['classes']) && $group->format_settings['instance_settings']['classes'] !== '') {
        $modifier_and_classes .= ' ' . $group->format_settings['instance_settings']['classes'];
      }

      $add['#prefix'] = '<div class="meta' . $modifier_and_classes . '">';
      $add['#suffix'] = '</div>';

      $element += $add;
      break;

    // Context nav.
    case 'context_nav':

      $add = array(
        '#type' => 'markup',
        '#weight' => $group->weight,
        '#id' => $id,
        '#attached' => array(
          'js' => array(drupal_get_path('module', 'nexteuropa_formatters') . '/js/context-nav.js'),
        ),
      );

      // Add our modifiers and classes.
      $modifier_and_classes = '';
      // Add only those with data.
      if (isset($group->format_settings['instance_settings']['modifier']) && $group->format_settings['instance_settings']['modifier'] !== '') {
        $modifier_and_classes .= ' ' . $group->format_settings['instance_settings']['modifier'];
      }
      if (isset($group->format_settings['instance_settings']['classes']) && $group->format_settings['instance_settings']['classes'] !== '') {
        $modifier_and_classes .= ' ' . $group->format_settings['instance_settings']['classes'];
      }

      // Add it.
      $add['#prefix'] = '<div class="context-nav' . $modifier_and_classes . '">';
      $add['#suffix'] = '</div>';

      $element += $add;
      break;

    case 'section_group':
      $add = array(
        '#type' => 'markup',
        '#weight' => $group->weight,
        '#id' => $id,
      );

      // Add our modifiers and classes.
      $modifier_and_classes = '';
      // Add only those with data.
      if (isset($group->format_settings['instance_settings']['modifier']) && $group->format_settings['instance_settings']['modifier'] !== '') {
        $modifier_and_classes .= ' ' . $group->format_settings['instance_settings']['modifier'];
      }
      if (isset($group->format_settings['instance_settings']['classes']) && $group->format_settings['instance_settings']['classes'] !== '') {
        $modifier_and_classes .= ' ' . $group->format_settings['instance_settings']['classes'];
      }

      if (isset($group->format_settings['instance_settings']['layout']) && $group->format_settings['instance_settings']['layout'] !== '') {
        switch ($group->format_settings['instance_settings']['layout']) {
          case 'col-md-8':
            $add['#prefix'] = '<div class="section__group row' . $modifier_and_classes . '"><div class="col-md-8">';
            $add['#suffix'] = '</div></div>';
            break;

          case 'col-md-9':
            $add['#prefix'] = '<div class="section__group row' . $modifier_and_classes . '"><div class="col-md-9">';
            $add['#suffix'] = '</div></div>';
            break;
        }
      }
      else {
        $add['#prefix'] = '<div class="section__group' . $modifier_and_classes . '">';
        $add['#suffix'] = '</div>';
      }

      $element += $add;
      break;
  }
}
