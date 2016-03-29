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
      'value' => t('Configure (%summary)', ['%summary' => $this->get_current_config_summary()]),
    ];
  }

  /**
   * Defines the form.
   */
  function options_form(&$form, &$form_state) {
    if ($form_state['section'] == 'digital_transformation') {
      $form['#title'] .= t('Digital transformation specific settings');

      foreach (_dt_shared_functions_additional_views_config() as $key => $config) {
        $form[$key] = [
          '#title' => $config['title'],
          '#type' => $config['type'],
          '#description' => $config['description'],
          '#required' => $config['required'],
          '#default_value' => $this->display->get_option($key),
        ];
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

  /**
   * Returns a list of current config.
   *
   * @return string
   *   Comma separated list of config.
   */
  private function get_current_config_summary() {
    $summary = [];
    foreach (_dt_shared_functions_additional_views_config() as $key => $config) {
      $setting = $this->display->get_option($key);
      if (!empty($setting)) {
        $summary[] = $config['title'] . ':' . $setting;
      }
    }
    return implode(', ', $summary);
  }

}
