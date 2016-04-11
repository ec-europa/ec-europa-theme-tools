<?php
/**
 * @file
 * This file contains examples of hooks nexteuropa_inpage_nav can implement.
 */

/**
 * Alter hook for the inpage navigation.
 *
 * @param string $field
 *   The the field it is currently acting on.
 * @param object $element
 *   The render array.
 */
function hook_nexteuropa_inpage_nav_add($field, $element) {
  // Example.
  return [
    $element['field_name']['#field_name'] => [
      'weight' => $element['field_name']['#weight'],
      'heading' => [
        'id' => 'bar',
        'label' => 'foo',
      ],
      'children' => '',
    ],
  ];
}
