<?php

/**
 * @file
 * Adding BEM related custom theme functions.
 */

/**
 * Returns HTML for a list or nested list of items.
 *
 * @param array $variables
 *   An associative array containing:
 *   - items: An array of items to be displayed in the list. If an item is a
 *     string, then it is used as is. If an item is an array, then the "data"
 *     element of the array is used as the contents of the list item. If an item
 *     is an array with a "children" element, those children are displayed in a
 *     nested list. All other elements are treated as attributes of the list
 *     item element.
 *   - type: The type of list to return (e.g. "ul", "ol").
 *   - attributes: The attributes applied to the listing element.
 *   - modifier: The modifier applied to the listing element.
 *
 * @return string
 *   Return $output.
 */
function theme_nexteuropa_bem_item_list(array $variables) {
  $items = $variables['items'];
  $type = $variables['type'];
  $subtype = in_array($type, ['ul', 'ol']) ? 'li' : 'div';
  $attributes = $variables['attributes'];
  $modifiers = $variables['modifiers'];

  $attributes['class'][] = 'listing';
  $attributes['class'] = array_merge($attributes['class'], $modifiers);

  $output = '';

  if (!empty($items)) {
    $output .= '<div class="listing__wrapper">';
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = ['class' => ['listing__item']];
      $children = [];
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $render_variables = [
          'items' => $children,
          'title' => NULL,
          'type' => $type,
          'attributes' => $attributes,
        ];
        $data .= theme('nexteuropa_bem_item_list', $render_variables);
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }

      $output .= '<' . $subtype . drupal_attributes($attributes) . '>' . $data . "</$subtype>\n";
    }
    $output .= "</$type>";
    $output .= '</div>';
  }
  return $output;
}

/**
 * Returns markup for a list of file translations.
 *
 * @param array $variables
 *   The variables to render.
 *
 * @return string
 *   Markup of translations.
 */
function theme_nexteuropa_file_translations(array $variables) {
  $node = $variables['node'];
  $files_count = isset($node->field_core_file) ? count($node->field_core_file) : 0;

  if ($files_count > 1) {
    $content_langcode = _nexteuropa_theme_functions_get_content_language_langcode();
    $displayed_langcode = entity_translation_get_existing_language($node->type, $node);

    // Remove one from the count, if the current language is in the list.
    if (isset($node->field_core_file[$displayed_langcode])) {
      $files_count--;
    }

    $files = $node->field_core_file;
    $nid = $node->nid;

    $output = '<div class="file__translations">';
    // Building the link.
    $link = [
      '#href' => '',
      '#type' => 'link',
      '#attached' => [
        'js' => [
          [
            'data' => drupal_get_path('theme', 'europa') . '/js/components/file.js',
            'options' => [
              'group' => JS_LIBRARY,
              'preprocess' => TRUE,
              'every_page' => TRUE,
            ],
          ],
        ],
      ],
      '#options' => [
        'fragment' => 'file__translations-' . $nid,
        'external' => TRUE,
      ],
      '#attributes' => [
        'class' => ['file__translations-control'],
        'title' => t('Click to see translations', [], ['langcode' => $content_langcode]),
        'data-toggle' => ['collapse'],
        'aria-expanded' => ['false'],
        'aria-controls' => ['file__translations-' . $nid],
      ],
      '#title' => t('Available languages (@count)', ['@count' => $files_count], ['langcode' => $content_langcode]),
    ];
    // Attaching the link.
    $output .= render($link);

    // Building the list.
    $list = [
      'title' => NULL,
      'items' => [],
      'type' => 'ul',
      'attributes' => [
        'class' => [
          'collapse',
          'file__translations-list',
        ],
        'id' => ['file__translations-' . $nid],
      ],
    ];

    // Before we start listing translations, we unset our source language.
    unset($files[$displayed_langcode]);

    $languages = locale_language_list();
    $languages_order = array_flip(array_keys($languages));

    foreach ($files as $lang => $file) {
      $language = isset($languages[$lang]) ? $languages[$lang] : NULL;
      $file_info = reset($file);
      $file_object = file_load($file_info['fid']);
      // Add our language.
      $file_object->language = $lang;
      $file_object->filename = $language;
      $file_markup = _nexteuropa_formatters_file_markup($file_object, 'file--bare', TRUE);
      $key = isset($languages_order[$lang]) ? $languages_order[$lang] : count($list['items']);
      $list['items'][$key] = [
        'class' => ['file__translations-item'],
        'data' => $file_markup,
      ];
    }
    // Reorder according to array key.
    ksort($list['items']);

    // @todo Change implementation to display help text through settings.
    $show_helptext = FALSE;
    if ($show_helptext) {
      $list['items'][] = [
        'class' => ['file__translations-details'],
        'data' => t('Looking for another language and it is not in the list? !link', ['!link' => l(t('Find out why.'), "#")], ['langcode' => $content_langcode]),
      ];
    }

    $output .= theme('item_list', $list);
    $output .= '</div>';

    return $output;
  }

  return '';
}
