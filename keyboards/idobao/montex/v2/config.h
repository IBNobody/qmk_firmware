/* Copyright 2022 IDOBAOKB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see &lt;http://www.gnu.org/licenses/&gt;.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
/* NB: VENDOR_ID & PRODUCT_ID et.al. moved to `info.json` */
// #define VENDOR_ID       0x6964  // "id"
// #define PRODUCT_ID      0x0227  // 0x0027 | 0x02 = v2 designator (for VIA)
// #define DEVICE_VER      0x0002
// #define MANUFACTURER    IDOBAO
// #define PRODUCT         Montex ID27

/* Key Matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 5

/* Keyboard Matrix Assignments */

#define MATRIX_ROW_PINS { D4, D6, D7, B4, B5, C6 }
#define MATRIX_COL_PINS { D5, D3, D2, D1, D0 }
// #define UNUSED_PINS {}
#define DIODE_DIRECTION ROW2COL

/* Other settings */

/* Debounce reduces chatter (unintended double-presses) - set 0 if
   debouncing is not needed */
#define DEBOUNCE 5

/* LED Matrix & Animations */
#define RGB_DI_PIN B1

#if defined(RGB_DI_PIN) && defined(RGB_MATRIX_ENABLE)
    #define DRIVER_LED_TOTAL 31  // The number of LEDs connected

    // #define RGBLIGHT_ANIMATIONS  // don't use, please explicitly define
    // #define RGB_MATRIX_FRAMEBUFFER_EFFECTS  // don't use, too few key to make it look good
    #define RGB_MATRIX_KEYPRESSES

    #define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180 // Limit to vendor-recommended value

    // RGB Matrix Animation modes. Explicitly enabled
    // For full list of effects, see:
    // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
    // *** For the ones commented out, don't use, too few key to make it look good ***
    #define ENABLE_RGB_MATRIX_SOLID_COLOR
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    // #define ENABLE_RGB_MATRIX_BAND_SAT
    // #define ENABLE_RGB_MATRIX_BAND_VAL
    // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    // #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    // #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    // #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    // #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_HUE_BREATHING
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    #define ENABLE_RGB_MATRIX_HUE_WAVE
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN
    #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

    /* enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined */
    // #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    // #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

    /* enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined */
    // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    // define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_SPLASH
    // #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    // #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
