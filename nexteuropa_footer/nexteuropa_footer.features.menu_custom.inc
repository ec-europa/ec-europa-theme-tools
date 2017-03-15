<?php
/**
 * @file
 * nextueuropa_footer.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nexteuropa_footer_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-nexteuropa-social-media.
  $menus['menu-nexteuropa-social-media'] = array(
    'menu_name' => 'menu-nexteuropa-social-media',
    'title' => 'Follow the European Commission',
    'description' => 'List of social networks links for the European Commission',
    'language' => 'und',
    'i18n_mode' => 5,
  );

  $menus['menu-nexteuropa-service-links'] = array(
    'menu_name' => 'menu-nexteuropa-service-links',
    'title' => 'Nexteuropa service links',
    'description' => 'Links to be put in the banner, according to IPG',
    'language' => 'und',
    'i18n_mode' => 5,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Follow the European Commission');
  t('Nexteuropa service links');


  return $menus;
}
