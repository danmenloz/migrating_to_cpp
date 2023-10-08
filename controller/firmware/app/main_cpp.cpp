
#include "main.h"
#include "stm32l4xx_hal_gpio.h"

class LED {
 public:
  LED() {}

  void toggle() { HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin); }
};

int main_cpp(void) {
  LED led;

  // The following loop is the main loop for our C++ application.
  // We don't expect it to ever return.
  while (true) {
    led.toggle();

    // We are using this nasty for loop to delay our application
    // by ~ 500 ms.
    for (volatile int i = 0; i < 1000000; ++i)
      ;
  }

  return 42;
}
