<?php

/**
 * @file
 * Contains \Drupal\dt_shared_functions\DtUrlTokenHandler.
 */

namespace Drupal\dt_shared_functions;

/**
 * Class DtUrlTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class DtUrlTokenHandler extends \Drupal\nexteuropa_token\Entity\UrlTokenHandler {

  /**
   * {@inheritdoc}
   */
  public function getEntityUrl($entity_type, $entity) {
    $uri = entity_uri($entity_type, $entity);
    return url($uri['path'], array('absolute' => FALSE));
  }

}
