#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0 
#else
#define ARDUINO_RUNNING_CORE 1 
#endif

#include <SPI.h>
#include <RTOS.h>

static u_int8_t hello;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  begin();
  begin_RTOS();
 
}

void loop() {
  // put your main code here, to run repeatedly:
} 