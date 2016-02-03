/**
 * @file
 * In-page nav related behaviors.
 */

(function ($) {
  Drupal.behaviors.inpage_navigation = {
    currentTitle: function($navBar, $navBarCurrent) {
      // Clear title for In page nav navbar title if nothing selected.
      var currentItem = $("li.active > a", $navBar);
      if (currentItem.length == 0) {
        $navBarCurrent.text(Drupal.settings.inpage_navigation.node_title);
      }
      else {
        $navBarCurrent.text(currentItem.text());
      }
    },

    attach: function () {
      $('.inpage-nav').once('page-navigation', function () {
        // Variables.
        var $title = Drupal.settings.inpage_navigation.node_title,
          $inPage = $('.inpage-nav'),
          $navBar = $('<div class="inpage-nav__navbar-wrapper is-scrollspy-target"><nav class="navbar navbar-default navbar-fixed-top inpage-nav__navbar"><div class="container inpage-nav__container"><div class="navbar-header inpage-nav__header"  data-toggle="collapse" data-target="#inpage-navigation-list" aria-expanded="false" aria-controls="navbar"><button type="button" class="navbar-toggle collapsed inpage-nav__toggle"><span class="sr-only">' + Drupal.t("Toggle navigation") + '</span><span class="inpage-nav__icon-arrow icon icon--arrow-down"></span></button><span class="navbar-brand inpage-nav__help">' + Drupal.t('On this page') + '</span><div class="inpage-nav__current-wrapper"><span class="navbar-brand inpage-nav__current">' + $title + '</span></div></div><div class="navbar-collapse collapse" id="inpage-navigation-list"><span class="inpage-nav__title" >' + $title + '</span>' + $inPage.html() + '</div></div></nav>'),
          $navBarCurrent = $('.inpage-nav__current', $navBar),
          $navBarList = $('.inpage-nav__list', $navBar),
          $selector = '.inpage-nav',
          $selectorMobile = '.inpage-nav__navbar-wrapper',
          $topOffset = GetOffsetTop('.inpage-nav__wrapper'),
          $screenWidth = $(window).width(),
          $body = $('body');

        // Add the navbar.
        $body.append($navBar);

        $navBarList.addClass('nav inpage-nav__list--navbar');

        // Scrollspy setup.
        $body.scrollspy({
          target: '.is-scrollspy-target'
        });

        // Hide if clicked outside.
        $('.inpage-nav__navbar', $navBar).click(function(e) {
          $('#inpage-navigation-list').collapse('hide');
        });

        // Initially trigger the scroll calculations.
        TriggerScroll($screenWidth, $topOffset, $selectorMobile, $selector, $navBar, $navBarCurrent);

        // When we resize the window we should recalculate the top. We use the onresize here as the jquery.resize function
        // can be unregistered.
        window.onresize = function() {
          $topOffset = GetOffsetTop('.inpage-nav__wrapper');
          $screenWidth = $(window).width();
          // Reinitialize the scroll function.
          TriggerScroll($screenWidth, $topOffset, $selectorMobile, $selector, $navBar, $navBarCurrent);
          // Reset scrollspy.
          $body.scrollspy('refresh');
        };

        $(window).scroll(function () {
          TriggerScroll($screenWidth, $topOffset, $selectorMobile, $selector, $navBar, $navBarCurrent);
        });
      });
    }
  };

  function TriggerScroll(screenWidth, topOffset, selectorMobile, selector, $navBar, $navBarCurrent) {
    // Check resolution behaviour.
    if (screenWidth <= 991) {
      InpageToggle(selectorMobile, selector, 'mobile');
      InpageUnfix(selector);
      // Add the navbar if needed.
      if ($(window).scrollTop() > topOffset) {
        Drupal.behaviors.inpage_navigation.currentTitle($navBar, $navBarCurrent);
        $(selectorMobile).show();
        $(selector).hide();
      }
      else {
        $(selectorMobile).hide();
        $(selector).show();
      }
    }
    else {
      InpageToggle(selectorMobile, selector, 'desktop');
      if ($(window).scrollTop() > topOffset) {
        InpageFix(selector);
      }
      else {
        InpageUnfix(selector);
      }
    }
  }

  function InpageToggle(mobile, desktop, state) {
    if (state == 'desktop') {
      $(desktop).show();
      $(mobile).hide();
    }
    else {
      $(mobile).show();
    }
  }

  function InpageUnfix(selector) {
    $(selector).closest('.inpage-nav__wrapper').css({
      'position': 'relative'
    });
  }

  function InpageFix(selector) {
    $(selector).closest('.inpage-nav__wrapper').css({
      'position': 'fixed',
      'top': 0,
      'width': $(selector).closest('.block__content').width() + 'px'
    });
  }

  function GetOffsetTop(selector) {
    var $element = $(selector).offset();
    return $element.top;
  }

})(jQuery);
