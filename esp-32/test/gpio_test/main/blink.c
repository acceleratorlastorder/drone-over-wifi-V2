#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define waitInterval_MS 2000

void setAllLevelOfGPIO(uint32_t level){

  uint32_t result = NULL;
for (size_t i = 0; i < 33; i++) {
  if (i == 20 || i == 24 || i == 28 || i == 29 || i == 30 || i == 31) {
    continue;
  }
  gpio_set_level((gpio_num_t)i, level);
  result = gpio_get_level((gpio_num_t)i);
  printf("GPIO_NUM_%d has level set to : %d\n", (gpio_num_t)i, result);
}
}



void getAllLevel(){
uint32_t result = NULL;

for (size_t i = 0; i < 40; i++) {

  if (i == 20 || i == 24 || i == 28 || i == 29 || i == 30 || i == 31) {
    continue;
  }
  result = gpio_get_level(i);
  printf("GPIO_NUM_%d has level set to : %d\n", i, result);

}

}

void app_main()
{
getAllLevel();


 int x = 15;
  while (x > 0) {
    printf("hoping for all level set 1\n");
    setAllLevelOfGPIO(1);
    vTaskDelay(waitInterval_MS / portTICK_PERIOD_MS);
  /*  setAllLevelOfGPIO(0);
    printf("all gpioSEt to 0.\n");
    getAllLevel();
    vTaskDelay(waitInterval_MS / portTICK_PERIOD_MS);
*/
    printf("iteration before restart: %d\n", x);
    x--;
  }
  printf("Restarting now.\n");
  fflush(stdout);
  esp_restart();
}
