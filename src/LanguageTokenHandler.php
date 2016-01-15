<?php

/**
 * @file
 * Contains \Drupal\dt_shared_functions\LanguageTokenHandler.
 */

namespace Drupal\dt_shared_functions;

/**
 * Class LanguageTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class LanguageTokenHandler extends \Drupal\nexteuropa_token\TokenAbstractHandler {

  const TOKEN_TYPE = 'dt_tokens';
  const CONTENT_LANGUAGE = 'dt_content_language';
  const INTERFACE_LANGUAGE = 'dt_interface_language';

  /**
   * {@inheritdoc}
   */
  public function hookTokens($type, $tokens, array $data = array(), array $options = array()) {
    $replacements = array();

    if ($type == self::TOKEN_TYPE) {
      foreach ($tokens as $name => $original) {
        if ($name == self::CONTENT_LANGUAGE || $name == self::INTERFACE_LANGUAGE) {

          if ($node = menu_get_object() && $name == self::CONTENT_LANGUAGE) {
            // If we can load our node, we will use that for our language.
            $language_token_value = _dt_shared_functions_content_language($node);
          }
          else {
            global $language;
            // On other cases we fall back to interface..
            $language_token_value = $language->language;
          }

          // Set the replacement.
          $replacements[$original] = $language_token_value;
        }
      }
    }

    return $replacements;
  }

  /**
   * {@inheritdoc}
   */
  public function hookTokenInfoAlter(&$data) {
    // Define the group.
    $data['types'][self::TOKEN_TYPE] = array(
      'name' => t('Dt tokens'),
      'description' => t('Dt custom tokens'),
    );
    // And the token.
    $data['tokens'][self::TOKEN_TYPE][self::CONTENT_LANGUAGE] = array(
      'name' => t("DT Content language"),
      'description' => t("The real language of the content - not the interface."),
    );
    $data['tokens'][self::TOKEN_TYPE][self::INTERFACE_LANGUAGE] = array(
      'name' => t("DT Interface language"),
      'description' => t("The langauge of the interface."),
    );
  }

}
