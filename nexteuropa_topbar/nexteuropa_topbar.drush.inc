<?php

/**
 * @file
 * Nexteuropa footer drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @see drush_parse_command()
 */
function nexteuropa_topbar_drush_command() {
  $items = [];

  $items['ec-topbar-setup'] = [
    'description' => t('Apply theme settings to determine the user menu appearence.'),
    'drupal dependencies' => ['features'],
    'aliases' => ['ectopbar'],
  ];

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function nexteuropa_topbar_drush_help($section) {
  switch ($section) {
    case 'drush:ec-topbar-setup':
      return dt('Apply theme settings to determine the user menu appearence.');
  }
}

/**
 * Retrieve the theme setting and align the db.
 */
function drush_nexteuropa_topbar_ec_topbar_setup() {
  $user_menu = theme_get_setting('ec_europa_user_menu', 'europa');
  _nexteuropa_topbar_handle_user_menu($user_menu);
}
