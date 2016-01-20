<?php

/**
 * @file
 * Contains \Drupal\dt_shared_functions\LanguageTokenHandler.
 */

namespace Drupal\dt_shared_functions;

/**
 * Class PublishdateTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class PublishdateTokenHandler extends \Drupal\nexteuropa_token\TokenAbstractHandler {

  const TOKEN_NAME = 'dt_publish_date';

  /**
   * {@inheritdoc}
   *
   * This will return the publish date if it might have been set in our custom
   * field. The fallback is the node creation date.
   */
  public function hookTokens($type, $tokens, array $data = array(), array $options = array()) {
    $replacements = array();

    if ($type == _dt_shared_function_get_token_type()) {
      foreach ($tokens as $name => $original) {
        if ($name == self::TOKEN_NAME) {

          if (isset($data['node'])) {
            // Get the node object.
            $node_object = entity_metadata_wrapper('node', $data['node']);

            // Init our date.
            $date_published = NULL;

            // Try to get the date. __isset mostly returns true, therefor we do
            // a second check and not an else statement.
            if ($node_object->__isset('field_core_date_published')) {
              $date_published = $node_object->field_core_date_published->value();
            }

            // Fall back to entity creation date.
            if (is_null($date_published)) {
              $date_published = $node_object->created->value();
            }

            // Set the replacement.
            if (isset($date_published) && !is_null($date_published)) {
              // Format it for output.
              $date_published = format_date($date_published, 'custom', 'd/m/Y');
              // Add it to our replacement array.
              $replacements[$original] = $date_published;
            }
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
    $data['tokens'][_dt_shared_function_get_token_type()][self::TOKEN_NAME] = array(
      'name' => t("DT Publish date"),
      'description' => t("The publish date of the node. First published with fallback to creation date."),
    );
  }

}
