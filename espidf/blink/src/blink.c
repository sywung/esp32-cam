/* blink.c
   閃光燈間隔1秒明滅
*/
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include <stdio.h>

// 閃光燈在 esp32-cam 為 GPIO4, 在 platformio.ini 中設定

#define BLINK_GPIO (gpio_num_t) CONFIG_BLINK_GPIO

void app_main() {
  // 選擇 GPIO4 為 GPIO 輸出。 (多功能腳位設定)
  gpio_pad_select_gpio(BLINK_GPIO);

  /* 設定 GPIO 為 push/pull 輸出 */
  gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

  while (1) {
    /* 閃光燈關 */
    printf("Turning off the FLASH\n");
    gpio_set_level(BLINK_GPIO, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    /* 閃光燈開 */
    printf("Turning on the FLASH\n");
    gpio_set_level(BLINK_GPIO, 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
