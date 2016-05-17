<?php
/**
 * @file
 * Contains the FacetApi widget for DT.
 */

/**
 * Widget that renders facets as a list of clickable checkboxes.
 *
 * This widget renders facets in the same way as FacetapiWidgetLinks but uses
 * JavaScript to transform the links into checkboxes followed by the facet.
 */
class DtFacetapiWidgetCheckboxLinks extends FacetapiWidgetLinks {

  /**
   * Overrides FacetapiWidgetLinks::init().
   *
   * Adds additional JavaScript settings and CSS.
   */
  public function init() {
    parent::init();
    $this->jsSettings['makeCheckboxes'] = 1;
    drupal_add_css(drupal_get_path('module', 'facetapi') . '/facetapi.css');
    drupal_add_js(drupal_get_path('module', 'dt_shared_functions') . '/js/facet_api_trigger_link.js', 'file');
  }

  /**
   * {@inheritdoc}
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    // Sets each item's theme hook, builds item list.
    $this->setThemeHooks($element);
    $element = [
      '#theme' => 'dt_shared_functions_facet_item_list',
      '#items' => $this->buildListItems($element),
      '#attributes' => $this->build['#attributes'],
      '#type' => 'div',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildListItems($build) {
    $settings = $this->settings->settings;

    // Initializes links attributes, adds rel="nofollow" if configured.
    $attributes = ($settings['nofollow']) ? ['rel' => 'nofollow'] : [];
    $attributes += ['class' => $this->getItemClasses()];

    // Builds rows.
    $items = [];
    foreach ($build as $value => $item) {
      $row = [
        'class' => [
          'checkbox',
          'checkbox--facet',
        ],
      ];

      // Allow adding classes via altering.
      if (isset($item['#class'])) {
        $attributes['class'] = array_merge($attributes['class'], $item['#class']);
      }
      // Initializes variables passed to theme hook.
      $variables = [
        'text' => $item['#markup'],
        'path' => $item['#path'],
        'count' => $item['#count'],
        'options' => [
          'attributes' => $attributes,
          'html' => $item['#html'],
          'query' => $item['#query'],
        ],
      ];

      // Adds the facetapi-zero-results class to items that have no results.
      if (!$item['#count']) {
        $variables['options']['attributes']['class'][] = 'facetapi-zero-results';
      }

      // Add an ID to identify this link.
      $variables['options']['attributes']['id'] = drupal_html_id('facetapi-link');

      // If the item has no children, it is a leaf.
      if (empty($item['#item_children'])) {
        $row['class'][] = 'leaf';
      }
      else {
        // If the item is active or the "show_expanded" setting is selected,
        // show this item as expanded so we see its children.
        if ($item['#active'] || !empty($settings['show_expanded'])) {
          $row['class'][] = 'expanded';
          $row['children'] = $this->buildListItems($item['#item_children']);
        }
        else {
          $row['class'][] = 'collapsed';
        }
      }

      // Gets theme hook, adds last minute classes.
      $class = ($item['#active']) ? 'facetapi-active' : 'facetapi-inactive';
      $variables['options']['attributes']['class'][] = $class;

      // Themes the link, adds row to items. We enfore the theme to the inactive
      // one. But we do modify the checkbox later.
      $row['data'] = theme('facetapi_link_inactive', $variables);

      // Checkbox state.
      $checkbox_identifier = drupal_clean_css_identifier($variables['text']);
      $checkbox_state = $item['#active'] == 1 ? ' checked="checked"' : '';
      $row['prefix'] = '<input type="checkbox"' . $checkbox_state . ' class="facetapi-checkbox-trigger" id="' . $checkbox_identifier . '"><label for="' . $checkbox_identifier . '"></label>';

      // Add the row to the item list.
      $items[] = $row;
    }

    return $items;
  }

}
