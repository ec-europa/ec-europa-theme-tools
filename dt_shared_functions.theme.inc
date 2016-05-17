<?php
/**
 * @file
 * Contains all theme related functions for dt_shared_functions.
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
 *   - title: The title of the list.
 *   - type: The type of list to return (e.g. "ul", "ol", "div").
 *   - sub_type: The type of list to return for the child elements.
 *   - attributes: The attributes applied to the list element.
 *
 * @return string
 *   The markup.
 */
function theme_dt_shared_functions_facet_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $sub_type = $variables['sub_type'];
  $attributes = $variables['attributes'];

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $output = '<div class="item-list">';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
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
            if (!in_array($key, ['prefix', 'suffix'])) {
              $attributes[$key] = $value;
            }
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_dt_shared_functions_facet_item_list([
          'items' => $children,
          'title' => NULL,
          'type' => $type,
          'sub_type' => $sub_type,
          'attributes' => $attributes,
        ]);
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }

      // Set prefix and suffix if not set.
      if (!isset($item['prefix'])) {
        $item['prefix'] = '';
      }
      if (!isset($item['suffix'])) {
        $item['suffix'] = '';
      }

      $output .= '<' . $sub_type . ' ' . drupal_attributes($attributes) . '>' . $item['prefix'] . $data . $item['suffix'] . "</$sub_type>\n";
    }
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}
