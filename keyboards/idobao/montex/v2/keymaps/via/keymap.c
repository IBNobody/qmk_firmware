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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┌───┬───┬───┬───┐
     * │Esc│ ` │Tab│MO1│Bsp│
     * ├───┼───┼───┼───┼───┤
     * │ , │Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Gui│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │Alt│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │Shi│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │Ctr│ 0     │ . │   │
     * └───┴───────┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,    KC_GRAVE, KC_TAB,  MO(1),   KC_BSPC,
        KC_COMMA,  KC_NLCK,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_LGUI,   KC_P7,    KC_P8,   KC_P9,   KC_PPLS,
        KC_LALT,   KC_P4,    KC_P5,   KC_P6,
        KC_LSHIFT, KC_P1,    KC_P2,   KC_P3,   KC_PENT,
        KC_LCTRL,  KC_P0,             KC_PDOT
    ),

    /*
     * ┌───┌───┐───┬───┬───┐
     * │Rst│MO3│MO2│MO1│Bsp│
     * ├───┼───┘───┼───┼───┤
     * │ , │Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Gui│Hom│ ↑ │PgU│   │
     * ├───┼───┼───┼───┤ + │
     * │Alt│ ← │   │ → │   │
     * ├───┼───┼───┼───┤───┤
     * │Shi│End│ ↓ │PgD│   │
     * ├───┼───┴───┼───┤Ent│
     * │Ctr│Insert │Del│   │
     * └───┴───────┴───┘───┘
     */
    [1] = LAYOUT(
        RESET,   MO(3),   MO(2),   _______, _______,
        _______, _______, _______, _______, _______,
        _______, KC_HOME, KC_UP,   KC_PGUP,
        _______, KC_LEFT, XXXXXXX, KC_RGHT, _______,
        _______, KC_END,  KC_DOWN, KC_PGDN,
        _______, KC_INS,           KC_DEL,  _______
    ),

    /*  RGB stuff
     * ┌───┌───┐───┬───┬───┐
     * │   │Tog│MO2│MO1│Mod│
     * ├───┼───┘───┼───┼───┤
     * │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤
     * │   │Hu+│Br+│St+│   │
     * ├───┼───┼───┼───┤   │
     * │   │Sp-│   │Sp+│   │
     * ├───┼───┼───┼───┤───┤
     * │   │Hu-│Br-│St-│   │
     * ├───┼───┴───┼───┤   │
     * │   │       │   │   │
     * └───┴───────┴───┘───┘
     */
    [2] = LAYOUT(
        XXXXXXX, RGB_TOG, _______, _______, RGB_MOD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_HUI, RGB_VAI, RGB_SAI, XXXXXXX,
        XXXXXXX, RGB_SPD, XXXXXXX, RGB_SPI,
        XXXXXXX, RGB_HUD, RGB_VAD, RGB_SAD, XXXXXXX,
        XXXXXXX, XXXXXXX,          XXXXXXX
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,           _______
    )
};
