<?php

namespace Drupal\dt_shared_functions;

use Drupal\nexteuropa_token\TokenAbstractHandler;

/**
 * Class PublishdateTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class PublishdateTokenHandler extends TokenAbstractHandler {

  const TOKEN_NAME = 'dt_publish_date';

  /**
   * {@inheritdoc}
   *
   * This will return the publish date if it might have been set in our custom
   * field. The fallback is the node creation date.
   */
  public function hookTokens($type, $tokens, array $data = [], array $options = []) {
    $replacements = [];

    if ($type == _dt_shared_function_get_token_type()) {
      foreach ($tokens as $name => $original) {
        if ($name == self::TOKEN_NAME) {

          if (isset($data['node'])) {
            // Get the node object.
            $node_object = entity_metadata_wrapper('node', $data['node']);

            // Init our date.
            $date_published = NULL;

            if ($node_object->__isset('field_core_date_published')) {
              $date_published = $node_object->field_core_date_published->value();
            }
            $replacements[$original] = (!empty($date_published)) ? format_date($date_published, 'custom', 'd/m/Y') :
              format_date($node_object->created->value(), 'custom', 'd/m/Y');
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
      'name' => t("DT Publish date"),
      'description' => t("The publish date of the node. First published with fallback to creation date."),
    ];
  }

}
