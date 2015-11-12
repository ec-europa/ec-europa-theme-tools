<?php
/**
 * @file
 * Adding BEM related custom theme functions.
 */

<<<<<<< HEAD:lib/modules/nexteuropa_formatters/nexteuropa_formatters.theme.inc
 /**
  * Returns HTML for a list or nested list of items.
  *
  * @param array $variables
  *   An associative array containing:
  *   - items: An array of items to be displayed in the list. If an item is a
  *     string, then it is used as is. If an item is an array, then the "data"
  *     element of the array is used as the contents of the list item. If item
  *     is an array with a "children" element, those children are displayed in a
  *     nested list. All other elements are treated as attributes of the list
  *     item element.
  *   - type: The type of list to return (e.g. "ul", "ol").
  *   - attributes: The attributes applied to the listing element.
  *   - modifier: The modifier applied to the listing element.
  */
=======
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
>>>>>>> 14357719795bd856c5313eeb355934e098a06b13:project/modules/custom/nexteuropa_formatters/nexteuropa_formatters.theme.inc
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
