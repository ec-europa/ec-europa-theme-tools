<?php
/**
 * @file
 * Views implementation.
 */

/**
 * Implements hook_views_plugins().
 */
function nexteuropa_views_views_plugins() {
  $path = drupal_get_path('module', 'nexteuropa_views');

  $plugins = array(
    'style' => array(
      'nexteuropa_bem_listing' => array(
        'title' => t('Nexteuropa BEM listing'),
        'help' => t('Display items using BEM Listing component.'),
        'path' => $path,
        'handler' => 'views_plugin_style_nexteuropa_listing',
        'theme' => 'views_view_nexteuropa_listing',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => TRUE,
        'type' => 'normal',
      ),
    ),
  );

  return $plugins;
}
