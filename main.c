/* --------------------------------------------------------------
   Application: 01 - Rev1
   Release Type: Baseline Multitask Skeleton Starter Code 
   Class: Real Time Systems - Su 2025
   AI Use: Commented inline
   Context: Healthcare LED indicates a heartbeat and message showcases vitals
---------------------------------------------------------------*/

#include <stdio.h> 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_2  // GPIO2 LED

// Todo blink an LED at 2 Hz : represents the heartbeat
void heartbeat_task(void *pvParameters) 
{
    bool heartbeat_on = false; // keeps track of LED status
    while (1) 
    {
  
        gpio_set_level(LED_PIN, heartbeat_on); //sets GPIO level based on heartbeat_on status
        printf("Heartbeat LED %s\n", heartbeat_on ? "ON" : "OFF");// prints status of LED
        heartbeat_on = !heartbeat_on; //toggle heartbeat_on for next cycle
        vTaskDelay(pdMS_TO_TICKS(250));  // delay of 250 ms

    }

    vTaskDelete(NULL); //delete task
}

// Todo print message : patient vitals (used AI to figure out how to print time properly)
void vitals_task(void *pvParameters) 
{ 
    int time = 0; //counter variable
    while (1) 
    {
      //prints vitals and current system tick time. 
        printf("Vitals Good | HR: 120 bpm | SpO2: 98%% | time=%lu ms\n", //used AI
               (unsigned long)(xTaskGetTickCount() * portTICK_PERIOD_MS));
        vTaskDelay(pdMS_TO_TICKS(10000)); // delay of 10 seconds
    }

    vTaskDelete(NULL); //delete task
}

//Main application (used AI to come up with variable names)
void app_main() 
{
    // Initialize heartbeat LED
    gpio_reset_pin(LED_PIN); //resets GPIO pin 
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT); //configure LED pin as an output

    // Create both tasks with equal priority
    xTaskCreate(heartbeat_task, "HeartbeatTask", 2048, NULL, 1, NULL);
    xTaskCreate(vitals_task, "VitalsTask", 2048, NULL, 1, NULL);
}
