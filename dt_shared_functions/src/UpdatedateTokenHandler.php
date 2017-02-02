<?php

namespace Drupal\dt_shared_functions;

use Drupal\nexteuropa_token\TokenAbstractHandler;

/**
 * Class UpdatedateTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class UpdatedateTokenHandler extends TokenAbstractHandler {

  const TOKEN_NAME = 'dt_update_date';

  /**
   * {@inheritdoc}
   *
   * This will return the update date if it might have been set in our custom
   * field. The fallback is the node update date.
   */
  public function hookTokens($type, $tokens, array $data = [], array $options = []) {
    $replacements = [];

    if ($type == _dt_shared_function_get_token_type()) {
      foreach ($tokens as $name => $original) {
        if ($name == self::TOKEN_NAME) {

          if (isset($data['node']) || isset($data['entity']) && $data['entity_type'] == 'node') {
            $entity = isset($data['node']) ? $data['node'] : $data['entity'];
            // Get the node object.
            $node_object = entity_metadata_wrapper('node', $entity);

            // Init our date.
            $date_updated = NULL;

            if ($node_object->__isset('field_core_date_updated')) {
              $date_updated = $node_object->field_core_date_updated->value();
            }
            $replacements[$original] = (!empty($date_updated)) ? format_date($date_updated, 'custom', 'd/m/Y') :
              format_date($node_object->changed->value(), 'custom', 'd/m/Y');
          }
        }
      }
    }

    return $replacements;
  }

  /**
   * {@inheritdoc}
   */
  public function hookTokenInfoAlter(&$data) {
    // Define the token.
    $data['tokens'][_dt_shared_function_get_token_type()][self::TOKEN_NAME] = [
      'name' => t("DT Update date"),
      'description' => t("The update date of the node. Date updated with fallback to update date."),
    ];
  }

}
