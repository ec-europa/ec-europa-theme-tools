<?php

/**
 * @file
 * EntityReference selection handler.
 */

/**
 * The handler class.
 */
class DtSharedFunctionsEntityReferenceSelectionHandler extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $target_entity_type = $field['settings']['target_type'];

    // Check if the entity type does exist and has a base table.
    $entity_info = entity_get_info($target_entity_type);
    if (empty($entity_info['base table'])) {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }

    if ($field['settings']['handler'] == 'extended_base') {
      return new DtSharedFunctionsEntityReferenceSelectionHandler($field, $instance, $entity_type, $entity);
    }
    // Fall back to the original handler.
    return parent::getInstance($field, $instance, $entity_type, $entity);
  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    // We use not the system name but readable name.
    $node_types = &drupal_static('dt_shared_functions_node_types');
    if (!isset($node_types)) {
      $node_types = _node_types_build()->names;
    }
    $label = parent::getLabel($entity) . ' (' . (isset($node_types[$entity->type]) ? $node_types[$entity->type] : $entity->type) . '-' . $entity->nid . ')';
    return $label;
  }

}
