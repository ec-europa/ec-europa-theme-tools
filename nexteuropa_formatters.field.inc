<?php

/**
 * @file
 * Adding BEM related custom field formatters.
 */

global $_nexteuropa_formatters_listing_view_modes;
$_nexteuropa_formatters_listing_view_modes = array('title', 'meta', 'teaser');

/**
 * Implements hook_field_formatter_info().
 */
function nexteuropa_formatters_field_formatter_info() {
  return array(
    'context_nav_item' => array(
      'label' => t('Context nav item'),
      'field types' => array(
        'text',
        'entityreference',
        'link_field',
      ),
      'settings' => array(
        'expander_has_expander' => FALSE,
        'expander_trim_at' => 0,
        'expander_trim_to' => 0,
      ),
    ),
    'link_button_default' => array(
      'label' => 'Link button default',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'link_button_primary' => array(
      'label' => 'Link button primary',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'link_button_secondary' => array(
      'label' => 'Link button secondary',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'link_button_call_for_action' => array(
      'label' => 'Link button call for action',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'link_button_block' => array(
      'label' => 'Link button block',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'link_listing_title' => array(
      'label' => 'Listing title',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'entity_reference_section' => array(
      'label' => 'Entity reference section group',
      'field types' => array(
        'entityreference',
      ),
      'settings' => array(
        'view_mode' => 'default',
        'links' => TRUE,
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function nexteuropa_formatters_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();

  if ($display['type'] == 'context_nav_item') {
    $element['expander_has_expander'] = array(
      '#title' => t('Has expander'),
      '#type' => 'checkbox',
      '#size' => 1,
      '#default_value' => $settings['expander_has_expander'],
    );
    $element['expander_trim_at'] = array(
      '#title' => t('Trim at'),
      '#type' => 'textfield',
      '#size' => 2,
      '#default_value' => $settings['expander_trim_at'],
      '#element_validate' => array('element_validate_integer'),
    );
    $element['expander_trim_to'] = array(
      '#title' => t('Trim to'),
      '#type' => 'textfield',
      '#size' => 2,
      '#default_value' => $settings['expander_trim_to'],
      '#element_validate' => array('element_validate_integer'),
    );
  }

  return $element;
}

/**
 * Helper function to select the right class.
 *
 * @param string $formatter
 *   Formatter name.
 *
 * @return string
 *   Class connected to formatter.
 */
function _nexteuropa_formatters_field_formatter_view_classes($formatter) {
  switch ($formatter) {
    case 'link_button_default':
      return 'btn btn-default';

    case 'link_button_primary':
      return 'btn btn-primary';

    case 'link_button_secondary':
      return 'btn btn-secondary';

    case 'link_button_call_for_action':
      return 'btn btn-ctn';

    case 'link_button_block':
      return 'btn btn-default btn-block';

    case 'link_listing_title':
      return 'listing__title';

    case 'entity_reference_section':
      return 'section__item';
  }
  return '';
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function nexteuropa_formatters_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  if ($field['type'] == 'entityreference') {
    $target_ids = array();

    // Collect every possible entity attached to any of the entities.
    foreach ($entities as $id => $entity) {
      foreach ($items[$id] as $delta => $item) {
        if (isset($item['target_id'])) {
          $target_ids[] = $item['target_id'];
        }
      }
    }

    if ($target_ids) {
      $target_entities = entity_load($field['settings']['target_type'], $target_ids);
    }
    else {
      $target_entities = array();
    }

    // Iterate through the fieldable entities again to attach the loaded data.
    foreach ($entities as $id => $entity) {
      $rekey = FALSE;

      foreach ($items[$id] as $delta => $item) {
        // Check whether the referenced entity could be loaded.
        if (isset($target_entities[$item['target_id']])) {
          // Replace the instance value with the term data.
          $items[$id][$delta]['entity'] = $target_entities[$item['target_id']];
          // Check whether the user has access to the referenced entity.
          $has_view_access = (entity_access('view', $field['settings']['target_type'], $target_entities[$item['target_id']]) !== FALSE);
          $has_update_access = (entity_access('update', $field['settings']['target_type'], $target_entities[$item['target_id']]) !== FALSE);
          $items[$id][$delta]['access'] = ($has_view_access || $has_update_access);
        }
        // Otherwise, unset the instance value, since the entity does not exist.
        else {
          unset($items[$id][$delta]);
          $rekey = TRUE;
        }
      }

      if ($rekey) {
        // Rekey the items array.
        $items[$id] = array_values($items[$id]);
      }
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function nexteuropa_formatters_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  if (!empty($items)) {
    $formatter = $display['type'];
    switch ($formatter) {
      case 'context_nav_item':
        $layout_field_settings = ds_get_field_settings($entity_type, $entity->type, 'full');
        $field_name = $field['field_name'];
        if (isset($layout_field_settings[$field_name]['formatter_settings']['ft']['lb'])) {
          $label_altered = $layout_field_settings[$field_name]['formatter_settings']['ft']['lb'];
        }
        $wrapper_label = (isset($label_altered) ? $label_altered : $instance['label']);

        // Apply custom label to the element.
        $element = array_merge(
          $element,
          _nexteuropa_formatters_get_context_nav_wrapper(
            $wrapper_label,
            isset($display['settings']['expander_has_expander']) ? $display['settings']['expander_has_expander'] : FALSE,
            isset($display['settings']['expander_trim_at']) ? $display['settings']['expander_trim_at'] : FALSE,
            isset($display['settings']['expander_trim_to']) ? $display['settings']['expander_trim_to'] : FALSE
          )
        );

        switch ($field['type']) {
          case 'entityreference':
            $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
            foreach ($items as $delta => $item) {

              if ($label = $handler->getLabel($item['entity'])) {
                if ($uri = entity_uri($field['settings']['target_type'], $item['entity'])) {
                  $link_url = isset($item['entity']->legacy) ? $item['entity']->legacy : $uri['path'];
                  $link = l($label, $link_url, $uri['options']);
                  $element[$delta] = array(
                    '#prefix' => '<span class="context-nav__item">',
                    '#markup' => $link,
                    '#suffix' => '</span>',
                  );
                }
                else {
                  $element[$delta] = array('#markup' => check_plain($label));
                }
              }
            }
            break;

          case 'link_field':
            foreach ($items as $delta => $item) {
              $link = l($item['title'], $item['url'], array('attributes' => $item['attributes']));
              $element[$delta] = array(
                '#markup' => '<span class="context-nav__item">' . $link . '</span>',
              );
            }
            break;

          case 'text':
            foreach ($items as $delta => $item) {
              $element[$delta] = array(
                '#markup' => '<span class="context-nav__item">' . $item['safe_value'] . '</span>',
              );
            }
            break;
        }
        break;

      case 'link_button_default':
      case 'link_button_primary':
      case 'link_button_secondary':
      case 'link_button_call_for_action':
      case 'link_button_block':
        switch ($field['type']) {
          case 'link_field':
            foreach ($items as $delta => $item) {
              // Set attribute from formatter settings.
              $item['attributes']['class'] = _nexteuropa_formatters_field_formatter_view_classes($formatter);

              // Call theme function of link module (theme_link_formatter_link_
              // default).
              $element[$delta] = array(
                '#theme' => 'link_formatter_link_default',
                '#element' => $item,
                '#field' => $instance,
                '#display' => $display,
              );
            }
            break;

          case 'taxonomy_term_reference':
            foreach ($items as $delta => $item) {
              $term = taxonomy_term_load($item['tid']);
              $link = isset($term->legacy) ? $term->legacy : url('taxonomy/term/' . $item['tid']);

              $element[$delta] = array(
                '#type' => 'link',
                '#title' => $term->name,
                '#href' => $link,
                '#options' => array(
                  'attributes' => array(
                    'class' => _nexteuropa_formatters_field_formatter_view_classes($formatter),
                  ),
                ),
              );
            }
            break;

        }
        // Multiple field wrapper.
        if (($field['cardinality'] == -1) && ($formatter != 'link_button_block')) {
          $element['#prefix'] = '<div class="btn-group">';
          $element['#suffix'] = '</div>';
        }
        break;

      // Listing title item.
      case 'link_listing_title':
        $element = _nexteuropa_formatters_link_listing_title_field_formatter_view($field, $instance, $items, $display, $formatter, $element);
        break;

      case 'entity_reference_section':
        // Preconfigure entityreference_field_formatter_view().
        // section__item
        $new_display = $display;
        $new_display['type'] = 'entityreference_entity_view';
        $element = entityreference_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $new_display);
        foreach ($element as $delta => $item) {
          $key_of_node = key($element[$delta]['node']);
          $element[$delta]['node'][$key_of_node]['#prefix'] = '<div class="section__item">';
          $element[$delta]['node'][$key_of_node]['#suffix'] = '</div>';
        }

        // Multiple field wrapper.
        if ($field['cardinality'] == -1) {
          $element['#prefix'] = '<div class="section section--row-two">';
          $element['#suffix'] = '</div>';
        }
        break;
    }
  }
  return $element;
}

/**
 * Helper function to link listing title field view.
 */
function _nexteuropa_formatters_link_listing_title_field_formatter_view($field, $instance, $items, $display, $formatter, $element) {
  foreach ($items as $delta => $item) {
    // Set attribute from formatter settings.
    $item['attributes']['class'] = _nexteuropa_formatters_field_formatter_view_classes($formatter);

    // Call theme function of link module (theme_link_formatter_link_default).
    $element[$delta] = array(
      '#theme' => 'link_formatter_link_default',
      '#element' => $item,
      '#field' => $instance,
      '#display' => $display,
      '#prefix' => '<div class="listing__item">',
      '#suffix' => '</div>',
    );
  }
  if ($field['cardinality'] == -1) {
    $element['#prefix'] = '<div class="listing listing--title">';
    $element['#suffix'] = '</div>';
    return $element;
  }
  return $element;
}

/**
 * Implements hook_field_formatter_info_alter().
 */
function nexteuropa_formatters_field_formatter_info_alter(&$info) {
  $info['entityreference_entity_view']['settings'] += array(
    'nexteuropa_listing_columns' => 'default',
    'nexteuropa_listing_modifier' => '',
    'nexteuropa_listing_wrapper_modifier' => '',
  );
}

/**
 * Implements hook_field_formatter_settings_form_alter().
 */
function nexteuropa_formatters_field_formatter_settings_form_alter(&$settings_form, $context) {
  global $_nexteuropa_formatters_listing_view_modes;

  if (
    $context['instance']['display'][$context['view_mode']]['type'] == 'entityreference_entity_view' &&
    in_array($context['instance']['display'][$context['view_mode']]['settings']['view_mode'], $_nexteuropa_formatters_listing_view_modes)
  ) {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];
    $settings_form['nexteuropa_listing_columns'] = array(
      '#type' => 'select',
      '#title' => t('BEM: Listing layout'),
      '#options' => array(
        'default' => t('Default'),
        'two_columns' => t('Two Columns'),
        'three_columns' => t('Three Columns'),
        'row_two' => t('Row with two items'),
        'row_three' => t('Row with three items'),
      ),
      '#default_value' => $settings['nexteuropa_listing_columns'],
    );

    $settings_form['nexteuropa_listing_modifier'] = array(
      '#type' => 'textfield',
      '#title' => t('BEM: Listing Modifier'),
      '#default_value' => $settings['nexteuropa_listing_modifier'],
      '#description' => t('Class names separated by spaces.'),
    );

    $settings_form['nexteuropa_listing_wrapper_modifier'] = array(
      '#type' => 'textfield',
      '#title' => t('BEM: Listing Wrapper Modifier'),
      '#default_value' => $settings['nexteuropa_listing_wrapper_modifier'],
      '#description' => t('Class names separated by spaces.'),
    );
  }
}

/**
 * Implements hook_field_formatter_settings_summary_alter().
 */
function nexteuropa_formatters_field_formatter_settings_summary_alter(&$summary, $context) {
  global $_nexteuropa_formatters_listing_view_modes;
  if (
    $context['instance']['display'][$context['view_mode']]['type'] == 'entityreference_entity_view' &&
    in_array($context['instance']['display'][$context['view_mode']]['settings']['view_mode'], $_nexteuropa_formatters_listing_view_modes)
  ) {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];
    if (isset($settings['nexteuropa_listing_columns'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: List layout') . ': ' . $settings['nexteuropa_listing_columns'];
    }

    if (isset($settings['nexteuropa_listing_modifier']) && !empty($settings['nexteuropa_listing_modifier'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: Listing Modifier') . ': ' . $settings['nexteuropa_listing_modifier'];
    }

    if (isset($settings['nexteuropa_listing_wrapper_modifier']) && !empty($settings['nexteuropa_listing_wrapper_modifier'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: Listing Wrapper Modifier') . ': ' . $settings['nexteuropa_listing_wrapper_modifier'];
    }
  }
}

/**
 * Implements hook_preprocess_field().
 */
function nexteuropa_formatters_preprocess_field(&$variables) {
  if (isset($variables['element']['#formatter']) && $variables['element']['#formatter'] == 'entityreference_entity_view') {
    $entity_type = $variables['element']['#entity_type'];
    $field_name  = $variables['element']['#field_name'];
    $bundle      = $variables['element']['#bundle'];
    $view_mode   = $variables['element']['#view_mode'];

    // Fetch the instance settings and default display settings.
    $info = field_info_instance($entity_type, $field_name, $bundle);
    $formatter_settings = $info['display']['default']['settings'];
    if (isset($info['display'][$view_mode]['settings'])) {
      $formatter_settings = $info['display'][$view_mode]['settings'] + $formatter_settings;
    }
    // Make the setting available in the field template.
    $variables['nexteuropa_listing_columns'] = $formatter_settings['nexteuropa_listing_columns'];
    $variables['nexteuropa_listing_modifier'] = $formatter_settings['nexteuropa_listing_modifier'];
    $variables['nexteuropa_listing_wrapper_modifier'] = $formatter_settings['nexteuropa_listing_wrapper_modifier'];
  }
}
