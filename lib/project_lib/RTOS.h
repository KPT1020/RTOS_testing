#ifndef RTOS_h
#define RTOS_h
#include <Arduino.h>
#include <Adafruit_ADS1X15.h>

extern Adafruit_ADS1115 ads; 
extern TaskHandle_t task1Handle;

void print(void);
void Task_Call_library(void *pvParameters);
void Task_Read(void *pvParameters);
void Task_Count(void *pvParameters);
void Task_Hello(void *pvParameters);

void begin();
void begin_RTOS();

#endif