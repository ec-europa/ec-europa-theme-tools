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
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $options = [];
    $entity_type = $this->field['settings']['target_type'];

    $query = $this->buildEntityFieldQuery($match, $match_operator);
    if ($limit > 0) {
      $query->range(0, $limit);
    }

    $results = $query->execute();

    if (!empty($results[$entity_type])) {
      $entities = entity_load($entity_type, array_keys($results[$entity_type]));
      foreach ($entities as $entity_id => $entity) {
        list(, , $bundle) = entity_extract_ids($entity_type, $entity);
        $options[$bundle][$entity_id] = check_plain($this->getFormLabel($entity));
      }
    }

    return $options;
  }

  /**
   * Generates the form label.
   *
   * @param object $entity
   *   The entity to get the label for.
   * @param bool $include_id
   *   To include or not include the node id to the label.
   *
   * @return string
   *   The label for the entity.
   */
  public function getFormLabel($entity, $include_id = TRUE) {
    // We use not the system name but readable name.
    $node_types = &drupal_static('dt_shared_functions_node_types');
    if (!isset($node_types)) {
      $node_types = _node_types_build()->names;
    }

    // Build the label.
    $label = parent::getLabel($entity);
    $label .= ' (' . (isset($node_types[$entity->type]) ? $node_types[$entity->type] : $entity->type);
    if ($include_id) {
      $label .= ' - ' . $entity->nid;
    }
    $label .= ')';

    return $label;
  }

}
