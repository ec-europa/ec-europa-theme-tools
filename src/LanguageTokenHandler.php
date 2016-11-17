<?php

namespace Drupal\dt_shared_functions;

use Drupal\nexteuropa_token\TokenAbstractHandler;

/**
 * Class LanguageTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class LanguageTokenHandler extends TokenAbstractHandler {

  const CONTENT_LANGUAGE = 'dt_content_language';
  const INTERFACE_LANGUAGE = 'dt_interface_language';

  /**
   * {@inheritdoc}
   */
  public function hookTokens($type, $tokens, array $data = [], array $options = []) {
    global $language;
    $replacements = [];

    // Our tokens.
    if ($type == _dt_shared_function_get_token_type()) {
      foreach ($tokens as $name => $original) {
        switch ($name) {
          case self::CONTENT_LANGUAGE:
            if ($node = menu_get_object()) {
              $languages = language_list();
              // If we can load our node, we will use that for our language.
              $content_language = _dt_shared_functions_content_language($node);
              $language_token_value = isset($languages[$content_language]) ? $languages[$content_language]->prefix : LANGUAGE_NONE;
            }
            else {
              // On other cases we fall back to interface.
              $language_token_value = $language->prefix;
            }
            // Set the replacement.
            $replacements[$original] = $language_token_value;
            break;

          case self::INTERFACE_LANGUAGE:
            // Set the replacement.
            $replacements[$original] = $language->prefix;
            break;
        }
      }
    }

    return $replacements;
  }

  /**
   * {@inheritdoc}
   */
  public function hookTokenInfoAlter(&$data) {
    $token = _dt_shared_function_get_token_type();
    // And the token.
    $data['tokens'][$token][self::CONTENT_LANGUAGE] = [
      'name' => t("DT Content language"),
      'description' => t("The real language of the content - not the interface."),
    ];
    $data['tokens'][$token][self::INTERFACE_LANGUAGE] = [
      'name' => t("DT Interface language"),
      'description' => t("The langauge of the interface."),
    ];
  }

}
