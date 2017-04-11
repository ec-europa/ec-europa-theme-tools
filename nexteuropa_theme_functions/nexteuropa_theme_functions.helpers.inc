<?php

/**
 * @file
 * This file contains the shared helper functions for the Next Europa theme.
 */

/**
 * Helper function to get the readable language from a language code.
 *
 * @param string $langcode
 *   The langcode to get the language object for.
 *
 * @return object
 *   The language object.
 */
function _nexteuropa_theme_functions_get_language_obj($langcode, $type = 'name') {
  $languages = locale_language_list($type);

  return isset($languages[$langcode]) ? $languages[$langcode] : NULL;
}

/**
 * Helper function for contact phone fields.
 *
 * This function returns an array that will help
 * in validation/visualization of parts of
 * phone number number fields.
 *
 * @param string $label
 *   Field label, shoud display at errors.
 *
 * @return array
 *   Available patterns.
 */
function _nexteuropa_theme_functions_contactphone_patterns($label) {
  $patterns = [
    'phone_label' => [
      'pattern' => '/\s?\(([^)]+)\)$/',
      'return_key' => 0,
    ],
    'country_prefix' => [
      'pattern' => '/^(\+[0-9]{2,3}\s?)/',
      'return_key' => 0,
      'required' => TRUE,
      'explain' => t('Country code missing or in wrong format, ex:+32'),
    ],
    'telephone' => [
      'pattern' => '/^(\+[0-9]{2,3}\s+)((([0-9]{1,4})\s?)+)(\s?\(([^)]+)\))?$/',
      'return_key' => 2,
      'required' => 1,
      'explain' => t('@label is missing or with wrong format (+cc r xxx xx xx (description))', ['@label' => $label]),
    ],
  ];
  return $patterns;
}

/**
 * Helper function for the markup of the file caption.
 *
 * @param array $variables
 *   An associative array containing:
 *   - editorial_section: The editorial section for which the highlights are
 *     rendered.
 * @param string $field_name
 *   Field name with the caption or description.
 */
function _nexteuropa_theme_functions_file_caption(&$variables, $field_name) {
  // Check if the field has a caption.
  if (!empty($variables['content'][$field_name])) {
    // Resets the HTML of the field and adds the wrapper for the caption.
    $variables['content'][$field_name]['#theme'] = 'ds_field_reset';
    $variables['content'][$field_name]['#prefix'] = '<span class="file__caption">';
    $variables['content'][$field_name]['#suffix'] = '</span>';
  }
}

/**
 * Helper function for submit handler.
 *
 * @see nexteuropa_theme_functions_form_alter()
 */
function _nexteuropa_theme_functions_file_callback_helper($options) {
  $now = variable_get('dt_shared_functions_dt_file_' . $options['option'] . '_' . $options['bundle'] . '_' . $options['field_name'], TRUE);
  if (!$now) {
    variable_set('dt_shared_functions_dt_file_' . $options['option'] . '_' . $options['bundle'] . '_' . $options['field_name'], TRUE);
    $class = 'status';
    if ($options['option'] == 'use_component') {
      $message = t('You will use the dt file upload component in your frontend theme.');
    }
    else {
      $message = t('The upload button will be visible when a file is selected.');
    }
  }
  else {
    variable_set('dt_shared_functions_dt_file_' . $options['option'] . '_' . $options['bundle'] . '_' . $options['field_name'], FALSE);
    $class = 'warning';
    if ($options['option'] == 'use_component') {
      $message = t('You will not use anymore the dt file upload component in your frontend theme.');
    }
    else {
      $message = t('The upload button will not be visible in this instance.');
    }
  }

  $output = '<div id="dt_file_' . $options['option'] . '_wrapper">';
  $output .= '<div class="alert messages ' . $class . '"><p>' . $message . '</p></div>';
  $output .= '</div>';

  return $output;
}

/**
 * Helper for label date_popup accessibility, search api related.
 *
 * @param object $form
 *    The form object.
 * @param array $fields
 *    Array with the fields to be processed.
 *
 * @return mixed
 *   Returns form object.
 */
function _nexteuropa_theme_functions_datepopup_accessibilty($form, $fields) {
  foreach ($fields as $field_name) {
    if (isset($form['#info']["filter-{$field_name}"]['label']) && !empty($form['#info']["filter-{$field_name}"]['label'])) {
      // Set the label title.
      $form[$field_name]['#title_label'] = $form['#info']["filter-{$field_name}"]['label'];
      // Remove the (date) label.
      unset($form['#info']["filter-{$field_name}"]['label']);
      // Process which element in after_build.
      $form[$field_name]['#after_build'][] = '_nexteuropa_theme_functions_datepopup_accessibilty_build';
    }
  }
  return $form;
}

/**
 * Helper function to process at the element level.
 *
 * @param array $element
 *    Current element.
 * @param array $form_state
 *    Form state.
 *
 * @return mixed
 *   Returns element.
 */
function _nexteuropa_theme_functions_datepopup_accessibilty_build($element, &$form_state) {
  // Switch labels.
  $element['date']['#title'] = $element['#title_label'];
  // Add date picker classes.
  _nexteuropa_theme_functions_add_datepicker($element['date']);
  return $element;
}

/**
 * Helper function to process at the element level, for non-search api.
 *
 * @param array $element
 *    Current element.
 * @param array $form_state
 *    Form state.
 *
 * @return mixed
 *   Returns element.
 */
function _nexteuropa_theme_functions_datepopup_accessibilty_nosearchapi_build($element, &$form_state) {
  // Switch labels.
  $element['value']['date']['#title'] = $element['#title'];
  // Make sure we see popup label.
  $element['value']['date']['#title_display'] = 'before';
  // Add date picker classes.
  _nexteuropa_theme_functions_add_datepicker($element['value']['date']);

  return $element;
}

/**
 * Helper to set the wrapper around the date fields.
 *
 * @param array $element
 *    Element to set the wrapper upon.
 */
function _nexteuropa_theme_functions_add_datepicker(&$element) {
  $element['#prefix'] = '<div class="date-picker">';
  $element['#suffix'] = '<span class="date-picker--icon icon--calendar"></span></div>';
}

/**
 * Function to generate the site user menu.
 *
 * @param string $delta
 *   The delta.
 *
 * @return array
 *   Result to be rendered.
 */
function _nexteuropa_theme_functions_get_blocks_content($delta) {
  $result = [];

  switch ($delta) {
    case 'dt_shared_functions_user_menu':
      if (user_is_logged_in()) {
        $result = [
          '#markup' => theme('site_user_menu'),
        ];
      }
      else {
        if (module_exists('ecas')) {
          $result = [
            '#markup' => l(t('Log in'), 'ecas', ['attributes' => ['class' => ['site-user-menu__list']]]),
          ];
        }
      }
      break;
  }

  return $result;
}
