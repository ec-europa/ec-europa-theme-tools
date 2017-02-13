<?php

/**
 * @file
 * Display Suite NE Bootstrap Three Columns Stacked.
 *
 * This layout is as followed:
 *
 * | 9 | 3 | <- header
 * | 12    |
 * | 4 | 8 |
 * | 9 | 3 |
 * | 3 | 9 | | 12 |
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">

  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <div class="row">
    <<?php print $left_header_wrapper; ?> class="col-lg-9 <?php print $left_header_classes; ?>">
      <?php print $left_header; ?>
    </<?php print $left_header_wrapper; ?>>
    <<?php print $right_header_wrapper; ?> class="col-lg-3 <?php print $right_header_classes; ?>">
      <?php print $right_header; ?>
    </<?php print $right_header_wrapper; ?>>
  </div>

  <?php if (isset($top_top) && !empty($top_top)): ?>
    <div class="row">
      <<?php print $top_top_wrapper; ?> class="col-lg-12 <?php print $top_top_classes; ?>">
        <?php print $top_top; ?>
      </<?php print $top_top_wrapper; ?>>
    </div>
  <?php endif; ?>

  <?php if ((isset($top_middle_left) && !empty($top_middle_left)) || (isset($top_middle_right) && !empty($top_middle_right))): ?>
    <div class="row">
      <?php if (isset($top_middle_left) && !empty($top_middle_left)): ?>
        <<?php print $top_middle_left_wrapper; ?> class="col-lg-5 <?php print $top_middle_left_classes; ?>">
        <?php print $top_middle_left; ?>
        </<?php print $top_middle_left_wrapper; ?>>
      <?php endif; ?>
      <?php if (isset($top_middle_right) && !empty($top_middle_right)): ?>
        <<?php print $top_middle_right_wrapper; ?> class="col-lg-7 <?php print $top_middle_right_classes; ?>">
        <?php print $top_middle_right; ?>
        </<?php print $top_middle_right_wrapper; ?>>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ((isset($top_bottom_left) && !empty($top_bottom_left)) || (isset($top_bottom_right) && !empty($top_bottom_right))): ?>
    <div class="row">
    <?php if (isset($top_bottom_left) && !empty($top_bottom_left)): ?>
      <<?php print $top_bottom_left_wrapper; ?> class="col-lg-9 <?php print $top_bottom_left_classes; ?>">
      <?php print $top_bottom_left; ?>
      </<?php print $top_bottom_left_wrapper; ?>>
    <?php endif; ?>
    <?php if (isset($top_bottom_right) && !empty($top_bottom_right)): ?>
      <<?php print $top_bottom_right_wrapper; ?> class="col-lg-3 <?php print $top_bottom_right_classes; ?>">
      <?php print $top_bottom_right; ?>
      </<?php print $top_bottom_right_wrapper; ?>>
    <?php endif; ?>
    </div>
  <?php endif; ?>

  <div class="row">
    <?php if (isset($left) && !empty($left)): ?>
      <<?php print $left_wrapper; ?> class="col-lg-3 <?php print $left_classes; ?>">
        <?php print $left; ?>
      </<?php print $left_wrapper; ?>>
    <?php endif; ?>

    <?php if (isset($left) && !empty($left)): ?>
      <<?php print $central_wrapper; ?> class="col-lg-9 <?php print $central_classes; ?>">
    <?php else: ?>
      <<?php print $central_wrapper; ?> class="col-lg-12 <?php print $central_classes; ?>">
    <?php endif; ?>
      <?php print $central; ?>
    </<?php print $central_wrapper; ?>>
  </div>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
