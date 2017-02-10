<?php

/**
 * @file
 * dt_europa_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_europa_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return ["version" => "1"];
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return ["version" => "1"];
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return ["version" => "2"];
  }
}

/**
 * Implements hook_image_default_styles().
 */
function dt_europa_settings_image_default_styles() {
  $styles = [];

  // Exported image style: header_image_breakpoints_theme_europa_medium_1x.
  $styles['header_image_breakpoints_theme_europa_medium_1x'] = [
    'label' => 'header_image_breakpoints_theme_europa_medium_1x',
    'effects' => [
      11 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 738,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_medium_2x.
  $styles['header_image_breakpoints_theme_europa_medium_2x'] = [
    'label' => 'header_image_breakpoints_theme_europa_medium_2x',
    'effects' => [
      10 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 738,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_mobile_1x.
  $styles['header_image_breakpoints_theme_europa_mobile_1x'] = [
    'label' => 'header_image_breakpoints_theme_europa_mobile_1x',
    'effects' => [
      7 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 290,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_mobile_2x.
  $styles['header_image_breakpoints_theme_europa_mobile_2x'] = [
    'label' => 'header_image_breakpoints_theme_europa_mobile_2x',
    'effects' => [
      6 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 290,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_narrow_1x.
  $styles['header_image_breakpoints_theme_europa_narrow_1x'] = [
    'label' => 'header_image_breakpoints_theme_europa_narrow_1x',
    'effects' => [
      9 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 450,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_narrow_2x.
  $styles['header_image_breakpoints_theme_europa_narrow_2x'] = [
    'label' => 'header_image_breakpoints_theme_europa_narrow_2x',
    'effects' => [
      8 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 450,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_normal_1x.
  $styles['header_image_breakpoints_theme_europa_normal_1x'] = [
    'label' => 'header_image_breakpoints_theme_europa_normal_1x',
    'effects' => [
      13 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 962,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_normal_2x.
  $styles['header_image_breakpoints_theme_europa_normal_2x'] = [
    'label' => 'header_image_breakpoints_theme_europa_normal_2x',
    'effects' => [
      12 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 962,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_wide_1x.
  $styles['header_image_breakpoints_theme_europa_wide_1x'] = [
    'label' => 'header_image_breakpoints_theme_europa_wide_1x',
    'effects' => [
      15 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 0,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_breakpoints_theme_europa_wide_2x.
  $styles['header_image_breakpoints_theme_europa_wide_2x'] = [
    'label' => 'header_image_breakpoints_theme_europa_wide_2x',
    'effects' => [
      14 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 1140,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: header_image_module_picture_empty_srcset_1x.
  $styles['header_image_module_picture_empty_srcset_1x'] = [
    'label' => 'header_image_module_picture_empty_srcset_1x',
    'effects' => [
      5 => [
        'name' => 'image_scale',
        'data' => [
          'width' => 1140,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ],
        'weight' => 1,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_medium_1x.
  $styles['highlight_image_breakpoints_theme_europa_medium_1x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_medium_1x',
    'effects' => [
      23 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 546,
          'height' => 365,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_medium_2x.
  $styles['highlight_image_breakpoints_theme_europa_medium_2x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_medium_2x',
    'effects' => [
      24 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 546,
          'height' => 365,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_mobile_1x.
  $styles['highlight_image_breakpoints_theme_europa_mobile_1x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_mobile_1x',
    'effects' => [
      25 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 290,
          'height' => 193,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_mobile_2x.
  $styles['highlight_image_breakpoints_theme_europa_mobile_2x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_mobile_2x',
    'effects' => [
      26 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 290,
          'height' => 193,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_narrow_1x.
  $styles['highlight_image_breakpoints_theme_europa_narrow_1x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_narrow_1x',
    'effects' => [
      27 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 546,
          'height' => 364,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_narrow_2x.
  $styles['highlight_image_breakpoints_theme_europa_narrow_2x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_narrow_2x',
    'effects' => [
      28 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 546,
          'height' => 364,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_normal_1x.
  $styles['highlight_image_breakpoints_theme_europa_normal_1x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_normal_1x',
    'effects' => [
      29 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 546,
          'height' => 364,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_normal_2x.
  $styles['highlight_image_breakpoints_theme_europa_normal_2x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_normal_2x',
    'effects' => [
      30 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 546,
          'height' => 364,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_wide_1x.
  $styles['highlight_image_breakpoints_theme_europa_wide_1x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_wide_1x',
    'effects' => [
      31 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 360,
          'height' => 240,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_breakpoints_theme_europa_wide_2x.
  $styles['highlight_image_breakpoints_theme_europa_wide_2x'] = [
    'label' => 'highlight_image_breakpoints_theme_europa_wide_2x',
    'effects' => [
      32 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 360,
          'height' => 240,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: highlight_image_module_picture_empty_srcset_1x.
  $styles['highlight_image_module_picture_empty_srcset_1x'] = [
    'label' => 'highlight_image_module_picture_empty_srcset_1x',
    'effects' => [
      33 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 360,
          'height' => 240,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_medium_1x.
  $styles['teaser_image_breakpoints_theme_europa_medium_1x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_medium_1x',
    'effects' => [
      2 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_medium_2x.
  $styles['teaser_image_breakpoints_theme_europa_medium_2x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_medium_2x',
    'effects' => [
      4 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 250,
          'height' => 167,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_mobile_1x.
  $styles['teaser_image_breakpoints_theme_europa_mobile_1x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_mobile_1x',
    'effects' => [
      6 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 290,
          'height' => 193,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_mobile_2x.
  $styles['teaser_image_breakpoints_theme_europa_mobile_2x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_mobile_2x',
    'effects' => [
      8 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 290,
          'height' => 193,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_narrow_1x.
  $styles['teaser_image_breakpoints_theme_europa_narrow_1x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_narrow_1x',
    'effects' => [
      10 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 450,
          'height' => 300,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_narrow_2x.
  $styles['teaser_image_breakpoints_theme_europa_narrow_2x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_narrow_2x',
    'effects' => [
      12 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 450,
          'height' => 300,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_normal_1x.
  $styles['teaser_image_breakpoints_theme_europa_normal_1x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_normal_1x',
    'effects' => [
      14 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_normal_2x.
  $styles['teaser_image_breakpoints_theme_europa_normal_2x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_normal_2x',
    'effects' => [
      16 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 250,
          'height' => 167,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_wide_1x.
  $styles['teaser_image_breakpoints_theme_europa_wide_1x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_wide_1x',
    'effects' => [
      18 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_breakpoints_theme_europa_wide_2x.
  $styles['teaser_image_breakpoints_theme_europa_wide_2x'] = [
    'label' => 'teaser_image_breakpoints_theme_europa_wide_2x',
    'effects' => [
      20 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 250,
          'height' => 167,
          'retinafy' => 1,
        ],
        'weight' => 2,
      ],
    ],
  ];

  // Exported image style: teaser_image_module_picture_empty_srcset_1x.
  $styles['teaser_image_module_picture_empty_srcset_1x'] = [
    'label' => 'teaser_image_module_picture_empty_srcset_1x',
    'effects' => [
      22 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];

  return $styles;
}
