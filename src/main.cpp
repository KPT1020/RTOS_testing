#define ESP32_RTOS

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0 
#else
#define ARDUINO_RUNNING_CORE 1 
#endif

#include <SPI.h>
#include <RTOS.h>
#include <OTA.h>
#include <credentials.h>


static u_int8_t hello;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupOTA("TemplateSketch", mySSID, myPASSWORD);

  begin();
  begin_RTOS();
  show_IP();

}

void loop() {
//   #ifdef defined(ESP32_RTOS) && defined(ESP32)
// #else // If you do not use FreeRTOS, you have to regulary call the handle method.
//   ArduinoOTA.handle();
// #endif
//   // put your main code here, to run repeatedly:
} 