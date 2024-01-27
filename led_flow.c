#include <stdio.h>
#include <unistd.h>
#include "pico/stdlib.h"

#define LED_COUNT 5

int main() {
    stdio_init_all();

    gpio_init_mask((1 << LED_COUNT) - 1);
    gpio_set_dir_out_masked((1 << LED_COUNT) - 1);

    for (int iteration = 0; iteration < 10; ++iteration) {
        for (int n = 0; n < LED_COUNT; ++n) {
            gpio_put(n, true);
            sleep_ms(50);
        }

        for (int n = 0; n < LED_COUNT; ++n) {
            gpio_put(n, false);
            sleep_ms(50);
        }
    }

    return 0;
}

