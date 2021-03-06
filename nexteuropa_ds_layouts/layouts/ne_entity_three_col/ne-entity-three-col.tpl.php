<?php

/**
 * @file
 * Display Suite NE Bootstrap Three-Six-Three Stacked.
 */
?>

<<?php print $layout_wrapper . $layout_attributes; ?> class="<?php print $classes; ?>">

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

  <!-- Page Header -->
  <div class="page-header<?php print isset($header_back) ? ' page-header--image' : ''; ?>">
    <nav class="page-navigation" role="navigation">
      <div class="container-fluid">
        <?php print render($header_bottom); ?>
      </div>
    </nav>
  
  <?php if (theme_get_setting('ec_europa_improved_website', 'europa') && theme_get_setting('ec_europa_improved_identification', 'europa')): ?>
    <?php if (!$is_front || $is_front && theme_get_setting('ec_europa_improved_website_home', 'europa')): ?>
    <div class="container-fluid page-header__site-identification">
      <h3><?php print $site_name; ?></h3>
    </div>
    <?php endif; ?>
  <?php endif; ?>
  
  <?php if (!empty($left_header)): ?>
    <div class="container-fluid page-header__hero-title">
      <div class="row padding-reset">
        <<?php print $left_header_wrapper; ?> class="col-lg-9 <?php print $left_header_classes; ?>">
          <?php print $left_header; ?>
        </<?php print $left_header_wrapper; ?>>

      <?php if (!empty($right_header)): ?>
        <<?php print $right_header_wrapper; ?> class="col-lg-3 <?php print $right_header_classes; ?>">
          <?php print $right_header; ?>
        </<?php print $right_header_wrapper; ?>>
      <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>
  </div>

<?php if (!empty($bottom_header)): ?>
  <div class="page-bottom-header <?php print isset($header_bottom_modifier) ? $header_bottom_modifier : ''; ?>">
    <<?php print $bottom_header_wrapper; ?> class="<?php print $bottom_header_classes; ?>">
      <?php print $bottom_header; ?>
    </<?php print $bottom_header_wrapper; ?>>
  </div>
<?php endif; ?>

  <div class="page-content">
    
    <?php if (!empty($local_tabs)): ?>
      <div class="tabs-row">
        <div class="container-fluid">
          <?php print $local_tabs; ?>
        </div>
      </div>
    <?php endif; ?>

    <div class="container-fluid">
    
    <?php if (!empty($top) || !empty($messages)): ?>
      <div class="row">
        <section class="section section--content-top col-md-12 <?php print $top_classes; ?>">
        
        <?php if (!empty($messages)): ?>
          <?php print $messages; ?>
        <?php endif; ?>

          <?php print $top; ?>
        </section>
      </div>
    <?php endif; ?>

      <div class="row">
        <a id="main-content" tabindex="-1"></a>
      <?php if (!empty($right)): ?>
        <<?php print $right_wrapper; ?> class="<?php print $right_classes; ?>">
          <?php print $right; ?>
        </<?php print $right_wrapper; ?>>
      <?php endif; ?>

      <?php if (!empty($left)): ?>
        <<?php print $left_wrapper; ?> class="<?php print $left_classes; ?>">
          <?php print $left; ?>
        </<?php print $left_wrapper; ?>>
      <?php endif; ?>

        <section class="<?php print $central_classes; ?>">
          <?php print $central; ?>
        </section>

      </div>

    </div>
  </div>

</<?php print $layout_wrapper; ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>
