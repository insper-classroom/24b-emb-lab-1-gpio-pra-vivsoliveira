#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 2;
const int LED_PIN_RO = 3;
const int LED_PIN_B = 4;
const int LED_PIN_Y = 5;
const int BTN_PIN_R = 16;
const int LED = 18;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_RO);
  gpio_set_dir(LED_PIN_RO, GPIO_OUT);

  gpio_init(LED_PIN_B);
  gpio_set_dir(LED_PIN_B, GPIO_OUT);

  gpio_init(LED_PIN_Y);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);

  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);
  gpio_put(LED, 0);

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {

      gpio_put(LED, 1);
      for (int i = 0; i < 512; i++) {
        gpio_put(LED_PIN_R, 1);
        sleep_ms(10);
        gpio_put(LED_PIN_R, 0);

        gpio_put(LED_PIN_RO, 1);
        sleep_ms(10);
        gpio_put(LED_PIN_RO, 0);

        gpio_put(LED_PIN_B, 1);
        sleep_ms(10);
        gpio_put(LED_PIN_B, 0);

        gpio_put(LED_PIN_Y, 1);
        sleep_ms(10);
        gpio_put(LED_PIN_Y, 0);
      }
      gpio_put(LED, 0);
      while (!gpio_get(BTN_PIN_R)) {
        // Mantém o loop até o botão ser liberado
      }
      sleep_ms(10);
    }
  }
}
