<?php

/**
 * @file
 * Contains \Drupal\dt_shared_functions\LanguageTokenHandler.
 */

namespace Drupal\dt_shared_functions;

/**
 * Class UpdatedateTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class UpdatedateTokenHandler extends \Drupal\nexteuropa_token\TokenAbstractHandler {

  const TOKEN_NAME = 'dt_update_date';

  /**
   * {@inheritdoc}
   *
   * This will return the update date if it might have been set in our custom
   * field. The fallback is the node update date.
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
            $date_updated = NULL;

            // Try to get the date. __isset mostly returns true, therefor we do
            // a second check and not an else statement.
            if ($node_object->__isset('field_core_date_updated')) {
              $date_updated = $node_object->field_core_date_updated->value();
            }

            // Fall back to entity creation date.
            if (is_null($date_updated)) {
              $date_updated = $node_object->changed->value();
            }

            // Set the replacement.
            if (isset($date_updated) && !is_null($date_updated)) {
              // Format it for output.
              $date_updated = format_date($date_updated, 'custom', 'd/m/Y');
              // Add it to our replacement array.
              $replacements[$original] = $date_updated;
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
      'name' => t("DT Update date"),
      'description' => t("The update date of the node. Date updated with fallback to update date."),
    );
  }

}
