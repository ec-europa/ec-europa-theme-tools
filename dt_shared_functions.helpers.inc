<?php

/**
 * @file
 * This file contains the shared helper functions between dt_core and cwt_core.
 */

/**
 * Custom function returning additional views configuration.
 *
 * @return array
 *   Array of extra settings for views.
 */
function _dt_shared_functions_additional_views_config() {
  $settings = [
    'dt_shared_functions_views_config_title' => [
      '#title' => t('Title'),
      '#type' => 'textfield',
      '#description' => t('The title to display in the counter result.'),
      '#required' => FALSE,
    ],
    'dt_shared_functions_views_config_hidecount' => [
      '#title' => t('Hide count'),
      '#type' => 'checkbox',
      '#description' => t('Hides the result count from the title.'),
      '#required' => FALSE,
    ],
  ];

  drupal_alter('dt_shared_functions_views_config', $settings);

  return $settings;
}

/**
 * Helper function to return the token group.
 *
 * We predefine this in a helper so that we can use it in multiple files, and in
 * case it ever changes, we can do it in a centralized location.
 *
 * @return string
 *   The name of the token group we use.
 */
function _dt_shared_function_get_token_type() {
  return 'dt_tokens';
}

/**
 * Helper function to delete menu, menu links, taxonomies.
 *
 * @param string $name
 *   The name item.
 * @param string $type
 *   The type of the item.
 * @param string $op
 *   The operation to execute.
 */
function _dt_shared_functions_delete($name, $type = 'menu', $op = 'items') {
  switch ($type) {
    case 'menu':
      if ($op == 'items') {
        menu_delete_links($name);
      }
      else {
        menu_delete(['menu_name' => $name]);
      }
      break;

    case 'vocabulary':
      if ($op == 'items') {
        $voc = taxonomy_vocabulary_machine_name_load($name);
        if (!empty($voc)) {
          $terms = taxonomy_get_tree($voc->vid);
          foreach ($terms as $term) {
            taxonomy_term_delete($term->tid);
          }
        }
      }
      else {
        $voc = taxonomy_vocabulary_machine_name_load($name);
        if (!empty($voc)) {
          taxonomy_vocabulary_delete($voc->vid);
        }
      }
      break;

    case 'node':
      $node_type = [$name];
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->propertyCondition('type', $node_type, 'IN');
      $result = $query->execute();
      foreach ($result['node'] as $node) {
        node_delete($node->nid);
      }
      break;
  }
}

/**
 * Copy values from source to destination filed.
 *
 * @param string $entity_type
 *   The type of entity, like: node.
 * @param string $bundle
 *   Entity bundle, like: page.
 * @param string $source_field_name
 *   Source field name, like: field_core_link.
 * @param string $destination_field_name
 *   Destination field, like: field_core_links.
 * @param bool $append
 *   If we should append or replace.
 * @param bool $clear
 *   If true, then the old value will be set empty.
 *
 * @throws \Exception
 *   Exception when no source field with the given name.
 *   Exception when no destination field with the given name.
 *   Exception when source and destination are not the same field type.
 *
 * @todo: Refactor this so it can work in a batch operation.
 */
function _dt_shared_field_value_copy($entity_type, $bundle, $source_field_name, $destination_field_name, $append = FALSE, $clear = FALSE) {
  // Source and destination field info.
  $source_field_info = field_info_field($source_field_name);
  $destination_field_info = field_info_field($destination_field_name);

  // Error handling.
  if (!$source_field_info) {
    throw new Exception(
      t('There is not any %source (source field) with this name.', [
        '%source' => $source_field_name,
      ])
    );
  }
  if (!$destination_field_info) {
    throw new Exception(
      t('There is not any %source (source field) with this name.', [
        '%source' => $destination_field_name,
      ])
    );
  }
  if ($source_field_info['type'] != $destination_field_info['type']) {
    throw new Exception(
      t('%source (source) and %destination (destination) are not the same field type.', [
        '%source' => $source_field_name,
        '%destination' => $destination_field_name,
      ])
    );
  }
  // Source field  is a multiple one.
  $source_field_is_multiple = ($source_field_info['cardinality'] != 1);
  // Destination field is a multiple one.
  $destination_field_is_multiple = ($destination_field_info['cardinality'] != 1);

  // Query the entities.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $entity_type)
    ->entityCondition('bundle', $bundle);
  $result = $query->execute();

  // Use the result if any.
  if (isset($result[$entity_type])) {
    // Get the entity ids from result.
    $ids = array_keys($result[$entity_type]);
    // Load entities using ids.
    $entities = entity_load($entity_type, $ids, [], TRUE);
    foreach ($entities as $entity) {
      $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);

      // Check the source field for value.
      if ($append
        && isset($entity_wrapper->$source_field_name)
        && $entity_wrapper->$source_field_name->value()
      ) {
        // Append the data.
        $newdata = array_merge($entity_wrapper->$destination_field_name->value(), $entity_wrapper->$source_field_name->value());
        // Set the new data.
        $entity_wrapper->$destination_field_name = $newdata;
        // If our clear parameter is true, we have to delete the old data.
        if ($clear) {
          $entity_wrapper->$source_field_name = NULL;
        }
        // And save the entity.
        $entity_wrapper->save();
      }
      elseif (
        isset($entity_wrapper->$source_field_name)
        && $entity_wrapper->$source_field_name->value()
        && $entity_wrapper->$destination_field_name->value() == NULL
      ) {
        // Same cardinality.
        if ($source_field_is_multiple == $destination_field_is_multiple) {
          $entity_wrapper->$destination_field_name = $entity_wrapper->$source_field_name->value();
        }
        // Source is multiple field, but destination not,
        // than take the first element.
        elseif ($source_field_is_multiple && !$destination_field_is_multiple) {
          $entity_wrapper->$destination_field_name = reset($entity_wrapper->$source_field_name->value());
        }
        // Source is single element field, but destination not,
        // than use an array wrapper.
        else {
          // Take the first item of array.
          $entity_wrapper->$destination_field_name = [$entity_wrapper->$source_field_name->value()];
        }
        // If our clear parameter is true, we have to delete the old data.
        if ($clear) {
          $entity_wrapper->$source_field_name = NULL;
        }
        // Save the entity.
        $entity_wrapper->save();
      }
    }
  }
}

/**
 * Get the final content language after applying translations and fallbacks.
 *
 * @param object $node
 *   The node object to get the language for.
 *
 * @return string
 *   The language of the content.
 */
function _dt_shared_functions_content_language($node) {
  // Load potential relevant languages in the correct fallback order.
  $content_language_order = _dt_shared_functions_content_language_order();
  $content_language = $node->language;
  // Find first available translation that is applicable.
  if (!empty($content_language_order)) {
    foreach ($content_language_order as $language_code) {
      $translation = entity_translation_get_existing_language('node', $node, $language_code);
      // We have a translation so lets use it.
      if ($translation == $language_code) {
        $content_language = $language_code;
        break;
      }
      $content_language = $translation;
    }
  }

  return $content_language;
}

/**
 * Get the languages that are applicable in the right order of fallback.
 *
 * @return array
 *   List of languages in their order.
 */
function _dt_shared_functions_content_language_order() {
  global $language;
  // Get the first few languages of our fallback array. If we have a 2nd
  // language parameter set, we have to work with an additional language. If
  // not, we only need one.
  // Set our maximum languages to check.
  $max_languages = 1;
  // First we get our url parameters.
  $parameters = drupal_get_query_parameters();
  // Check if the 2nd-language parameter is set.
  if (isset($parameters['2nd-language']) && $parameters['2nd-language'] !== 'en') {
    // Extend maximum to include the 2nd-language.
    $max_languages = 2;
  }
  // Get the maximum extra languages.
  $fallback_languages = array_slice(language_fallback_get_candidates(), 0, $max_languages);
  // Add our current site language to the array.
  if (!in_array($language->language, $fallback_languages)) {
    array_unshift($fallback_languages, $language->language);
  }
  else {
    // Our default language is in the array but might not be the first. So we
    // move it.
    // Get the key of the language.
    $main_language_key = array_search($language->language, $fallback_languages);
    // Store it temporary.
    $prepend_language = $fallback_languages[$main_language_key];
    // Remove the item.
    unset($fallback_languages[$main_language_key]);
    // Then add it to the front.
    array_unshift($fallback_languages, $prepend_language);
  }

  return $fallback_languages;
}

/**
 * Removing 2 conflicting theme settings.
 */
function _dt_shared_functions_disable_anchors() {
  $dt_themes = ['information', 'political', 'europa', 'commissioner'];
  foreach ($dt_themes as $theme) {
    // Target correct variable.
    $target_settings = 'theme_' . $theme . '_settings';
    // Get the current settings.
    $theme_settings = variable_get($target_settings, FALSE);
    // If settings are not there, configure it, otherwise adapt them.
    if (!$theme_settings) {
      $theme_settings = [
        'bootstrap_anchors_fix' => 0,
        'bootstrap_anchors_smooth_scrolling' => 0,
      ];
    }
    else {
      $theme_settings['bootstrap_anchors_fix'] = 0;
      $theme_settings['bootstrap_anchors_smooth_scrolling'] = 0;
    }

    // Store the settings again.
    variable_set($target_settings, $theme_settings);
  }
}

/**
 * Helper function to get the readable language from a language code.
 *
 * @param string $langcode
 *   The langcode to get the language object for.
 *
 * @return object
 *   The language object.
 */
function _dt_shared_functions_get_language_obj($langcode, $type = 'name') {
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
function _dt_shared_functions_contactphone_patterns($label) {
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
function _dt_shared_functions_datepopup_accessibilty($form, $fields) {
  foreach ($fields as $field_name) {
    if (isset($form['#info']["filter-{$field_name}"]['label']) && !empty($form['#info']["filter-{$field_name}"]['label'])) {
      // Set the label title.
      $form[$field_name]['#title_label'] = $form['#info']["filter-{$field_name}"]['label'];
      // Remove the (date) label.
      unset($form['#info']["filter-{$field_name}"]['label']);
      // Process which element in after_build.
      $form[$field_name]['#after_build'][] = '_dt_shared_functions_datepopup_accessibilty_build';
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
function _dt_shared_functions_datepopup_accessibilty_build($element, &$form_state) {
  // Switch labels.
  $element['date']['#title'] = $element['#title_label'];
  // Add date picker classes.
  _dt_shared_functions_add_datepicker($element['date']);
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
function _dt_shared_functions_datepopup_accessibilty_nosearchapi_build($element, &$form_state) {
  // Switch labels.
  $element['value']['date']['#title'] = $element['#title'];
  // Make sure we see popup label.
  $element['value']['date']['#title_display'] = 'before';
  // Add date picker classes.
  _dt_shared_functions_add_datepicker($element['value']['date']);

  return $element;
}

/**
 * Helper to set the wrapper around the date fields.
 *
 * @param array $element
 *    Element to set the wrapper upon.
 */
function _dt_shared_functions_add_datepicker(&$element) {
  $element['#prefix'] = '<div class="date-picker">';
  $element['#suffix'] = '<span class="date-picker--icon icon--calendar"></span></div>';
}

/**
 * Custom submit function for the theme setting form.
 */
function _dt_shared_functions_theme_settings_submit(&$form, &$form_state) {
  $override = $form_state['values']['dt_latest_visibility'] == 1 ? TRUE : FALSE;
  variable_set('dt_shared_functions_dt_latest_visibility', $override);
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
function _dt_shared_functions_get_blocks_content($delta) {
  $result = [];

  switch ($delta) {
    case 'dt_shared_functions_user_menu':
      $result = [
        '#markup' => theme('site_user_menu'),
      ];
      break;
  }

  return $result;
}

/**
 * Helper function to sort an array list of values.
 *
 * @param string $a
 *   String to be processed.
 * @param string $b
 *   String to be processed.
 *
 * @return int
 *   Calculated value.
 */
function _dt_shared_functions_compare_ascii($a, $b) {
  setlocale(LC_ALL, "en_US.utf8");

  $at = iconv(mb_detect_encoding($a), 'ascii//TRANSLIT', $a);
  $bt = iconv(mb_detect_encoding($b), 'ascii//TRANSLIT', $b);

  return strcmp($at, $bt);
}
