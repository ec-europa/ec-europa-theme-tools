<?php

/**
 * @file
 * Display Suite NE Bootstrap structured content.
 */
?>

<div class="listing listing--navigation">

<?php if (!isset($prevent_link)): ?>
  <div class="listing__item-link">
<?php else: ?>
  <div class="listing__item-nolink">
<?php endif; ?>

    <h2 class="listing__section-title">
      <?php print $title; ?>
    </h2>

    <?php if ($description && !$children): ?>
      <p class="listing__description">
        <?php print $description; ?>
      </p>
    <?php endif; ?>

  </div>

  <?php if ($children): ?>
    <?php print $children; ?>
  <?php endif; ?>

  <?php if (($children || $description) && $links): ?>
    <hr class="listing__separator">
  <?php endif; ?>

  <?php if ($links): ?>
    <?php print $links; ?>
  <?php endif; ?>

</div>
