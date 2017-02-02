<?php

/**
 * @file
 * Contains accessibility specific hooks and implementations.
 *
 * This is created as a seperate file so that we at one point take it out to a
 * separate feature.
 */

/**
 * Implements hook_preprocess_hook().
 *
 * Here we set the src attribute to the image url.
 */
function dt_shared_functions_preprocess_image_srcset(&$variables) {
  $variables['uri'] = $variables['srcset'][0]['uri'];
}
