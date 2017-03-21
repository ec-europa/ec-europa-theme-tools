<?php

/**
 * @file
 * Europa settings helpers.
 */

/**
 * Helper function to return the token group.
 *
 * We predefine this in a helper so that we can use it in multiple files, and in
 * case it ever changes, we can do it in a centralized location.
 *
 * @return string
 *   The name of the token group we use.
 */
function _dt_europa_settings_get_token_type() {
  return 'europa_tokens';
}

/**
 * Get the final content language after applying translations and fallbacks.
 *
 * @param object $node
 *   The node object to get the language for.
 *
 * @return string
 *   The language of the content.
 */
function _dt_europa_settings_content_language($node) {
  // Load potential relevant languages in the correct fallback order.
  $content_language_order = _dt_shared_functions_content_language_order();
  $content_language = $node->language;
  // Find first available translation that is applicable.
  if (!empty($content_language_order)) {
    foreach ($content_language_order as $language_code) {
      $translation = entity_translation_get_existing_language('node', $node, $language_code);
      // We have a translation so lets use it.
      if ($translation == $language_code) {
        $content_language = $language_code;
        break;
      }
      $content_language = $translation;
    }
  }

  return $content_language;
}

/**
 * Get the languages that are applicable in the right order of fallback.
 *
 * @return array
 *   List of languages in their order.
 */
function _dt_europa_settings_content_language_order() {
  global $language;
  // Get the first few languages of our fallback array. If we have a 2nd
  // language parameter set, we have to work with an additional language. If
  // not, we only need one.
  // Set our maximum languages to check.
  $max_languages = 1;
  // First we get our url parameters.
  $parameters = drupal_get_query_parameters();
  // Check if the 2nd-language parameter is set.
  if (isset($parameters['2nd-language']) && $parameters['2nd-language'] !== 'en') {
    // Extend maximum to include the 2nd-language.
    $max_languages = 2;
  }
  // Get the maximum extra languages.
  $fallback_languages = array_slice(language_fallback_get_candidates(), 0, $max_languages);
  // Add our current site language to the array.
  if (!in_array($language->language, $fallback_languages)) {
    array_unshift($fallback_languages, $language->language);
  }
  else {
    // Our default language is in the array but might not be the first. So we
    // move it.
    // Get the key of the language.
    $main_language_key = array_search($language->language, $fallback_languages);
    // Store it temporary.
    $prepend_language = $fallback_languages[$main_language_key];
    // Remove the item.
    unset($fallback_languages[$main_language_key]);
    // Then add it to the front.
    array_unshift($fallback_languages, $prepend_language);
  }

  return $fallback_languages;
}
