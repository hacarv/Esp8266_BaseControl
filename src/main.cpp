#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <ContinuousStepper.h>
#include "config.h"
#include "LDR.h"
#include "LED.h"
#include "ServoMotor.h"
#include "Potentiometer.h"
#include "StepperMotor.h"
#include "WiFiConnection.h"
#include "WebSocketHandler.h"

// WebSocket server
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

// Global instances for devices
LDR ldr;
LED led;
ServoMotor servoMotor;
Potentiometer potentiometer;
StepperMotor stepperMotor;

// Constants and variables
unsigned long lastLDRReadTime = 0;
unsigned long lastPotentiometerReadTime = 0;
const unsigned long readInterval = 10; // 10ms interval for reading LDR and Potentiometer

void checkDeviceConnections() {
  if (!ldr.isConnected()) {
    String message = "{\"error\":\"LDR not connected\"}";
    notifyClients(message);
    Serial.println(message);
  }
  if (!led.isConnected()) {
    String message = "{\"error\":\"LED not connected\"}";
    notifyClients(message);
    Serial.println(message);
  }
  if (!servoMotor.isConnected()) {
    String message = "{\"error\":\"Servo Motor not connected\"}";
    notifyClients(message);
    Serial.println(message);
  }
  if (!potentiometer.isConnected()) {
    String message = "{\"error\":\"Potentiometer not connected\"}";
    notifyClients(message);
    Serial.println(message);
  }
  if (!stepperMotor.isConnected()) {
    String message = "{\"error\":\"Stepper Motor not connected\"}";
    notifyClients(message);
    Serial.println(message);
  }
}

void setup() {
  Serial.begin(115200);
  setupWiFi();
  
  ldr.begin(LDR_PIN);
  led.begin();
  servoMotor.begin(SERVO_PIN);
  potentiometer.begin(POTENTIOMETER_PIN);
  stepperMotor.begin(STEPPER_PIN1, STEPPER_PIN2, STEPPER_PIN3);

  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);
  server.begin();

  checkDeviceConnections();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastLDRReadTime >= readInterval) {
    ldr.readAndNotify(currentMillis);
    lastLDRReadTime = currentMillis;
  }

  if (currentMillis - lastPotentiometerReadTime >= readInterval) {
    potentiometer.readAndNotify(currentMillis);
    lastPotentiometerReadTime = currentMillis;
  }

  led.update();
  servoMotor.update();
  stepperMotor.update();
}
