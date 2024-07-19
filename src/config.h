#ifndef CONFIG_H
#define CONFIG_H

// WiFi configuration
const char *SSID = "your_SSID";
const char *PASSWORD = "your_PASSWORD";

// Access Point configuration
const char *AP_SSID = "ESP8266_AP";
const char *AP_PASSWORD = "your_AP_PASSWORD";

// Pin configuration
const int LDR_PIN = A0;
const int LED_PIN = D2;
const int SERVO_PIN = D5;
const int POTENTIOMETER_PIN = 1;
const int STEPPER_PIN1 = D6;
const int STEPPER_PIN2 = D7;
const int STEPPER_PIN3 = D8;
const int STEPPER_PIN4 = D9;

// JSON Keys
const char *LDR_KEY = "ldr";
const char *LED_KEY = "led";
const char *SERVO_KEY = "servo";
const char *POTENTIOMETER_KEY = "potentiometer";
const char *STEPPER_KEY = "stepper";
const char *ERROR_KEY = "error";

#endif // CONFIG_H
