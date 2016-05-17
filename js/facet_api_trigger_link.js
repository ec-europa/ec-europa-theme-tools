/**
 * @file
 * When a checkbox for facetapi-checkbox is clicked, we trigger the link.
 */

(function ($) {
  Drupal.behaviors.dt_shared_functions = {
    attach: function (context) {
      $("input[type='checkbox'].facetapi-checkbox-trigger").change(function(){
        location.href = $(this).siblings('a').attr('href');
      });
    }
  }
})(jQuery);
