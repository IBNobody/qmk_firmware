#include "ups_controlpad.h"
#include "pcf8574.h"

__attribute__ ((weak))
void matrix_init_user(void) {
	// leave this function blank - it can be defined in a keymap file
};

__attribute__ ((weak))
void matrix_scan_user(void) {
	// leave this function blank - it can be defined in a keymap file
}

__attribute__ ((weak))
void led_set_user(uint8_t usb_led) {
	// leave this function blank - it can be defined in a keymap file
}

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	
	
	print("LEDs\n");
	
	PORTD &= ~(1<<0);
	PORTD &= ~(1<<1);
	
	pcf8574_init();
	
	matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

	matrix_scan_user();
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	uint8_t led_matrix[7];
	for (int n=0; n<7; n++)
	{
		led_matrix[n] = 0;
	}

    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    	keypad_led(led_matrix, 1);
    } else {
    	keypad_led(led_matrix, 0);

    }


	led_set_user(usb_led);
}

void keypad_led(uint8_t led_matrix[7], uint8_t blue_led)
{
//    1.2   1.1   1.0   0.4   0.3   0.2   0.1   0.0
//    3.0   2.4   2.3   2.2   2.1   2.0   1.4   1.3
//    4.3   4.2   4.1   4.0   3.4   3.3   3.2   3.1
//    6.1   6.0   5.4   5.3   5.2   5.1   5.0   4.4
//    N/A   N/A   N/A   N/A   LED   6.4   6.3   6.2

	uint8_t extender[5];

	extender[0] = ~ ( (led_matrix[0] & 0b11111)       | ((led_matrix[1] & 0b00111) << 5)                                   );
	extender[1] = ~ (((led_matrix[1] & 0b11000) >> 3) | ((led_matrix[2] & 0b11111) << 2) | ((led_matrix[3] & 0b00001) << 7));
	extender[2] = ~ (((led_matrix[3] & 0b11110) >> 1) | ((led_matrix[4] & 0b01111) << 4)                                   );
	extender[3] = ~ (((led_matrix[4] & 0b10000) >> 4) | ((led_matrix[5] & 0b11111) << 1) | ((led_matrix[6] & 0b00011) << 6));
	extender[4] = ~ (((led_matrix[6] & 0b11100) >> 2) | ((blue_led & 0x01) << 3)                                           );
             
    print("\nExtender\n");
	for (uint8_t n=0; n<5; n++)
	{
		print_val_bin8(extender[n]);
		pcf8574_setoutput(n, extender[n]);
	}
}

