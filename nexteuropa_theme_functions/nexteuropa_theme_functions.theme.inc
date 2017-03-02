<?php

/**
 * @file
 * Site user menu.
 */

if (!function_exists('theme_site_user_menu')) {

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
  function theme_site_user_menu($variables) {
    global $user;

    if (module_exists('ecas')) {
      $logout_url = url('/ecaslogout');
    }
    else {
      $logout_url = url('/user/logout');
    }

    $items = [];
    $items[] = [
      'data' => t('Logged in as %username', ['%username' => format_username($user)]),
      'class' => ['site-user-menu__option'],
    ];
    $items[] = [
      'data' => l(t('Logout'), $logout_url),
      'class' => ['site-user-menu__option'],
    ];

    $variables = [
      'items' => $items,
      'attributes' => [
        'class' => [
          'site-user-menu__list',
        ],
      ],
    ];

    return theme('item_list', $variables);
  }

}
