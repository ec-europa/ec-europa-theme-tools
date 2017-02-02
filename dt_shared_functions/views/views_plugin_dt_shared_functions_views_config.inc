<?php
/**
 * @file
 * Definition of views_plugin_dt_shared_views_config.
 *
 * @codingStandardsIgnoreFile
 * We can ignore coding standards.
 */

/**
 * The base plugin to handle digital transformation configs.
 */
class views_plugin_dt_shared_functions_views_config extends views_plugin_display_extender {

  /**
   * Default values.
   */
  function options_definition() {
    $options = parent::option_definition();
    foreach (_dt_shared_functions_additional_views_config() as $key => $config) {
      $options[$key] = ['default' => ''];
    }
    return $options;
  }
  function options_definition_alter(&$options) {
    foreach (_dt_shared_functions_additional_views_config() as $key => $config) {
      $options[$key] = ['default' => ''];
    }
  }

  /**
   * Defines where within the Views admin UI the new settings will be visible.
   */
  function options_summary(&$categories, &$options) {
    $categories['digital_transformation'] = [
      'title' => t('Digital Transformation'),
      'column' => 'second',
    ];
    $options['digital_transformation'] = [
      'category' => 'digital_transformation',
      'title' => t('Digital transformation settings'),
      'value' => t('Configure'),
    ];
  }

  /**
   * Defines the form.
   */
  function options_form(&$form, &$form_state) {
    if ($form_state['section'] == 'digital_transformation') {
      $form['#title'] .= t('Digital transformation specific settings');
      // Preserve the custom settings form.
      $form += _dt_shared_functions_additional_views_config();
      foreach (_dt_shared_functions_additional_views_config() as $key => $config) {
        // Keep default values if set.
        $form[$key]['#default_value'] = $this->display->get_option($key) ? $this->display->get_option($key) : '';
      }
    }
  }

  /**
   * Saves the form values.
   */
  function options_submit(&$form, &$form_state) {
    if ($form_state['section'] == 'digital_transformation') {
      foreach (_dt_shared_functions_additional_views_config() as $key => $config) {
        $this->display->set_option($key, $form_state['values'][$key]);
      }
    }
  }

}
