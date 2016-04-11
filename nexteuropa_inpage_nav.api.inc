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
  if (isset($element['announcement_block']) && isset($element['announcement_block'][0]['#markup'])) {
    // Get the anchors from the markup.
    $anchors = _nexteuropa_inpage_nav_get_anchors_from_markup($element['announcement_block'][0]['#markup']);
    // We just use the first anchor.
    return [
      $element['announcement_block']['#field_name'] => [
        'weight' => $element['announcement_block']['#weight'],
        'heading' => is_array($anchors) ? $anchors[0] : [],
        'children' => '',
      ],
    ];
  }
  return [];
}
