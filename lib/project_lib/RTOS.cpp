#include "RTOS.h"
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads; 
int16_t adc0, adc1, adc2, adc3;
int count = 0;

void print(){
 printf("I come from libray\n");
}

void begin(){
    if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}
void Task_Call_library(void *pvParameters){
  for(;;){
    (void)pvParameters;
    print();
    vTaskDelay(1000);
  }
}
TaskHandle_t task1Handle=NULL;
void Task_Hello(void *pvParameters){
  (void)pvParameters;
  Serial.println("Hello World ");
  vTaskDelete(task1Handle);
}

void Task_Count(void *pvParameters){
  for(;;){
  (void)pvParameters;
  count= count +1;
  Serial.println(count);
  vTaskDelay(500);
  }
}

void Task_Read(void *pvParameters){
  for(;;){
    (void)pvParameters;
    adc1 = ads.readADC_SingleEnded(1);
    Serial.println(adc1);
    vTaskDelay(500);
  }
}
void begin_RTOS(){
  xTaskCreatePinnedToCore(Task_Hello, "Task_Hello", 4096, NULL, 2, &task1Handle, ARDUINO_RUNNING_CORE);
  xTaskCreatePinnedToCore(Task_Count, "Task_Count", 2048, NULL,2, NULL, ARDUINO_RUNNING_CORE);
  xTaskCreatePinnedToCore(Task_Read, "Task_Read", 2048, NULL,1, NULL, ARDUINO_RUNNING_CORE);
  xTaskCreatePinnedToCore(Task_Call_library, "Task_Call_library", 2048, NULL,1, NULL, ARDUINO_RUNNING_CORE);
}