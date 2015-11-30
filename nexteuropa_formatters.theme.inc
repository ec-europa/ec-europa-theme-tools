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
function theme_nexteuropa_bem_item_list($variables) {
  $items = $variables['items'];
  $type = $variables['type'];
  $subtype = in_array($type, array('ul', 'ol')) ? 'li' : 'div';
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
      $attributes = array('class' => array('listing__item'));
      $children = array();
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
        $data .= theme_nexteuropa_bem_item_list(array(
          'items' => $children,
          'title' => NULL,
          'type' => $type,
          'attributes' => $attributes,
        ));
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
 *   Accepts: $variables['node']->field_core_file.
 *
 * @return string
 *   Markup of transleations.
 */
function theme_nexteuropa_file_translations($variables) {
  $files_count = isset($variables['node']->field_core_file) ? count($variables['node']->field_core_file) : 0;

  if ($files_count > 1) {
    $files = $variables['node']->field_core_file;
    $nid = $variables['node']->nid;
    $output = '<div class="file__translations">';
    // Building the link.
    $link = array(
      '#type' => 'link',
      '#options' => array(
        'fragment' => 'file__translations-' . $nid,
        'html' => TRUE,
      ),
      '#attributes' => array(
        'class' => array('file__translations-control', 'pull-right'),
        'data-toggle' => array('collapse'),
        'aria-expanded' => array('false'),
        'aria-controls' => array('file__translations-' . $nid),
        'title' => t('Click to see translations'),
      ),
      '#title' => t("All languages @count", array('@count' => $files_count))
      . " <span class='icon icon--down-blue'></span>",
    );
    // Attaching the link.
    $output .= render($link);

    // Building the list.
    $table = array(
      'rows' => array(),
      'attributes' => array(
        'class' => array('collapse', 'pull-right', 'file__translations-table'),
        'id' => array('file__translations-' . $nid),
      ),
    );
    foreach ($files as $lang => $file) {
      $languages = locale_language_list();
      $language = isset($languages[$lang]) ? $languages[$lang] : NULL;;
      $file_info = reset($file);
      $file_object = file_load($file_info['fid']);
      $file_object->filename = t('@language version', array('@language' => $language));
      $file_url = array(
        'path' => file_create_url($file_info['uri']),
        'options' => array(
          'attributes' => array(
            'class' => array('file__btn', 'btn'),
          ),
        ),
      );
      $file_markup = _europa_file_markup($file_object, $file_url, 'file--bare');
      $table['rows'][] = array(
        'data' => array($file_markup),
      );
    }
    $output .= theme_table($table);
    $output .= '</div>';
    return $output;
  }
  return '';
}
