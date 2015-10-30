/**
 * @file
 * In-page nav related behaviors.
 */

(function ($) {
  Drupal.behaviors.inpage_navigation = {
    fixWidth: function($e, $parent) {
      // Adjust width dinamcally to parent.
      var blockWidth = 'auto';
      blockWidth = $parent.width() + 'px';
      $e.css({
        'width' : blockWidth
      });
    },

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

    attach: function (context) {
      $('.inpage-nav').once('page-navigation', function () {
        var $inPageActive = false,
            $inPage = $(this),
            $inPageBlock = $inPage.parents('.inpage-nav__wrapper'),
            $inPageBlockParent = $inPageBlock.parent(),
            inPageBlockHeight = $inPageBlock.height(),
            inPageBlockTop = $inPageBlock.offset().top,
            $inPageList = $('.inpage-nav__list', $inPage),
            title = Drupal.settings.inpage_navigation.node_title;

        // Calculate width on window resize, and check offset height of in-page
        // nav block.
        $(window).resize(function(e) {
          Drupal.behaviors.inpage_navigation.fixWidth($inPageBlock, $inPageBlockParent);

          inPageBlockTop = $inPageBlock.offset().top;
          inPageBlockHeight = $inPageBlock.height();

          // Refresh scrollspy.
          $('body').scrollspy('refresh');
        });

        var $navBar = $('<div class="inpage-nav__navbar-wrapper is-scrollspy-target"><nav class="navbar navbar-default navbar-fixed-top inpage-nav__navbar"><div class="container inpage-nav__container"><div class="navbar-header inpage-nav__header"  data-toggle="collapse" data-target="#inpage-navigation-list" aria-expanded="false" aria-controls="navbar"><button type="button" class="navbar-toggle collapsed inpage-nav__toggle"><span class="sr-only">' + Drupal.t("Toggle navigation") + '</span><span class="inpage-nav__icon-arrow icon icon--arrow-down"></span></button><span class="navbar-brand inpage-nav__help">' + Drupal.t('On this page') + '</span><div class="inpage-nav__current-wrapper"><span class="navbar-brand inpage-nav__current">' + title + '</span></div></div><div class="navbar-collapse collapse" id="inpage-navigation-list"><span class="inpage-nav__title" >' + title + '</span>' + $inPage.html() + '</div></div></nav>'),
            $navBarHeader = $('.inpage-nav__header', $navBar),
            $navBarCurrent = $('.inpage-nav__current', $navBar),
            $navBarTitle = $('.inpage-nav__title', $navBar),
            $navBarHelp = $('.inpage-nav__help', $navBar),
            $navBarList = $('.inpage-nav__list', $navBar);

        $navBarList.addClass('nav inpage-nav__list--navbar');
        $('body').append($navBar);

        enquire.register("screen and (min-width: 992px)", {
          // Desktop.
          match : function() {
            // Adding function that is calculating and adding inpage-nav block
            // width. This is due to usage of position: fixed on the inpage-nav
            // element.
            Drupal.behaviors.inpage_navigation.fixWidth($inPageBlock, $inPageBlockParent);

            // Remove class that adds overflow: hidden to body.
            $('body').removeClass('is-inpage-nav-open');
            $inPageBlock.affix('checkPosition');
          },

          setup: function() {
            // Hide if clicked outside.
            $('.inpage-nav__navbar', $navBar).click(function(e) {
              $('#inpage-navigation-list').collapse('hide');
            });

            // Page navigation scroll spy.
            $('body').scrollspy({
                target: '.is-scrollspy-target'
            });

            $navBar.on('show.bs.collapse', function() {
              $navBar.addClass('is-collapsing');
            });

            $navBar.on('shown.bs.collapse', function() {
              $navBar.addClass('is-collapsed');
              $navBar.removeClass('is-collapsing');
            });

            $navBar.on('hide.bs.collapse', function() {
              $navBar.removeClass('is-collapsed');
              $('body').removeClass('is-inpage-nav-open');
            });

            $navBar.on("activate.bs.scrollspy", function(e) {
              // Set title to current;.
              Drupal.behaviors.inpage_navigation.currentTitle($navBar, $navBarCurrent);
            });

            // Affix.
            $inPageBlock.affix({
              offset: {
                top: function () {
                  return (Math.floor($inPageBlock.parent().offset().top) - 30);
                },
                bottom: function () {
                  return ($('.footer').outerHeight(true) + $('.footer-top').outerHeight(true) + 20);
                }
              }
            });

            $(window).scroll(function(e) {
              $window = $(this);
              // Set title to current;.
              Drupal.behaviors.inpage_navigation.currentTitle($navBar, $navBarCurrent);

              // Show navbar if scroll is under the block.
              var docViewTop = $window.scrollTop(),
                  docViewBottom = docViewTop + $window.height(),
                  inPageBottom = inPageBlockTop + inPageBlockHeight - 5;

              if (inPageBottom <= docViewTop) {
                $navBar.addClass('is-active');
              }
              else {
                $navBar.removeClass('is-active');
                $('#inpage-navigation-list').collapse('hide');
              }
            });
          },

          // Mobile.
          unmatch : function() {
            // Collapse navbar on changing to mobile behavior.
            if ($('.inpage-nav__navbar-wrapper').hasClass('is-collapsed')) {
              $('#inpage-navigation-list').collapse('hide');
            }

            $navBar.on('show.bs.collapse', function() {
              $('body').addClass('is-inpage-nav-open');
            });

            $navBar.on('hide.bs.collapse', function() {
              $('body').removeClass('is-inpage-nav-open');
            });
          }
        });
      });
    }
  }
})(jQuery);
