<?php

namespace Drupal\dt_shared_functions;

use Drupal\nexteuropa_token\Entity\UrlTokenHandler;

/**
 * Class DtUrlTokenHandler.
 *
 * @package Drupal\dt_shared_functions
 */
class DtUrlTokenHandler extends UrlTokenHandler {

  /**
   * {@inheritdoc}
   */
  public function getEntityUrl($entity_type, $entity) {
    $uri = entity_uri($entity_type, $entity);
    return url($uri['path'], ['absolute' => FALSE]);
  }

}
