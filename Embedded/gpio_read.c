#include <stdint.h>

#define DEBOUNCE_TIME_MS 20 // debounce interval, adjust as needed

// Call gpio_read() to read the button pin: returns 0 if pressed (active low), 1 if not
extern int gpio_read();

int debounce_button(void) {
    static uint16_t counter = 0;
    static uint8_t button_state = 0;

    if (gpio_read() == 0) { // Button pressed (active LOW)
        if (counter < DEBOUNCE_TIME_MS)
            counter++;
        else
            button_state = 1; // Button stable and pressed
    } else {
        counter = 0;
        button_state = 0;
    }

    return button_state; // 1 if pressed AND debounced, else 0
}
