<?php

/**
 * @file
 * Site switcher tab - political and info sites options.
 */

/**
 * Returns HTML for the element.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - modifier: The modifier applied to the element.
 *
 * @return string
 *   The markup itself.
 */
function theme_site_switcher_menu($variables) {
  global $language;
  $parameters = drupal_get_query_parameters();

  $modifier = isset($variables['modifier']) ? $variables['modifier'] : "";

  $title = [
    '#prefix' => '<h4 class="footer__title">',
    '#markup' => t('European Commission'),
    '#suffix' => '</h4>',
  ];

  $output = drupal_render($title);

  // Array of sites in the correct order.
  $sites = [
    [
      'label' => t("Commission and its priorities"),
      'url' => variable_get('site_switcher_political_url', 'http://ec.europa.eu/') . 'index_' . $language->prefix . '.htm',
    ],
    [
      'label' => t("Policies, information and services"),
      'url' => variable_get('site_switcher_info_url', 'https://ec.europa.eu/info/') . 'index_' . $language->prefix . (isset($parameters['2nd-language']) ? '?2nd-language=' . $parameters['2nd-language'] : ''),
    ],
  ];

  $output .= "<ul class='footer__menu menu nav'>";
  foreach ($sites as $site) {
    $output .= '<li class="footer__menu-item">' . l($site['label'], $site['url']) . '</li>';
  }
  $output .= "</ul>";

  return $output;
}
