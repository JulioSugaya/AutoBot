#include "OTA.h"
#include "FaceBehavior.h"
#include "Movements.h"
#include "Sensors.h"
#include "WebServer.h"

static int taskCore = 1;
int value = 0;
float distancia;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  setupOTA();
  
  Serial.printf("\nsetup() em core: %d\n", xPortGetCoreID());//Mostra no monitor em qual core o setup() foi chamado
  
  xTaskCreatePinnedToCore(
    faceBehavior,   /* Function to implement the task */
    "faceBehavior", /* Name of the task */
    10000,      /* Stack size in words */
    NULL,       /* Task input parameter */
    0,          /* Priority of the task */
    NULL,       /* Task handle. */
    taskCore
  );  /* Core where the task should run */
  
  ArduinoOTA.setHostname("AutoBotESP32_001");

  server.begin();

  displaySetup();

  motorsSetup();
}

void loop() {
  ArduinoOTA.handle();
  
  ultrasonic.measure();
  distancia = ultrasonic.get_cm();
  delay(1000);
  Serial.println("Leitura do Sensor de Distancia usando FreeRTOS:");
  Serial.println(distancia);
  
  webServerProcess();
}

void faceBehavior(void * pvParameters){
  blinkEyes();
  if(distancia < 10){
    drawFearEyes();
  }
}
