#include <stdio.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#include "hardware/spi.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hardware/gpio.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>


void gpio_callback(uint gpio, uint32_t event_mask) {
  
}

void initgpios () {
  for(int i = 0; i < 8; i++) {
    gpio_init(i);
    gpio_set_dir(i, GPIO_OUT);     
  }    
}

void main()
{
  stdio_init_all();
  initgpios();  
  int portvalue = 0;
  
  while(1) {      
    scanf("%i", &portvalue);
    portvalue = getchar();
    //printf("portvalue %i\n", portvalue);  
    gpio_clr_mask(255);
    gpio_set_mask(portvalue);
  }      
}