#ifndef UPS_CONTROLPAD_H
#define UPS_CONTROLPAD_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include "led.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
	K00, K01, K02, K03, K04, \
	K10, K11, K12, K13, K14, \
	K20, K21, K22, K23, K24, \
	K30, K31, K32, K33, K34, \
	K40, K41, K42, K43, K44, \
	K50, K51, K52, K53, K54, \
	K60, K61, K62, K63, K64  \
) \
{ \
	{ KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04 }, \
	{ KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14 }, \
	{ KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24 }, \
	{ KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34 }, \
	{ KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44 }, \
	{ KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54 }, \
	{ KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64 } \
} 

void matrix_init_user(void);
void matrix_scan_user(void);
void led_set_user(uint8_t usb_led);

void keypad_led(uint8_t led_matrix[7], uint8_t blue_led);


#endif