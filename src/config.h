#ifndef CONFIG_H
#define CONFIG_H

// WiFi configuration
#define SSID "your_SSID"
#define PASSWORD "your_PASSWORD"

// Access Point configuration
#define AP_SSID "ESP8266_AP"
#define AP_PASSWORD "your_AP_PASSWORD"

// Pin configuration
#define LDR_PIN A0 // ESP8266 typically has a single ADC pin labeled A0
#define LED_PIN D1
#define SERVO_PIN D2
#define POTENTIOMETER_PIN A0
#define STEPPER_PIN1 D5
#define STEPPER_PIN2 D6
#define STEPPER_PIN3 D7
#define STEPPER_PIN4 D8

// JSON Keys
#define LDR_KEY "ldr"
#define LED_KEY "led"
#define SERVO_KEY "servo"
#define POTENTIOMETER_KEY "potentiometer"
#define STEPPER_KEY "stepper"
#define ERROR_KEY "error"

#endif // CONFIG_H
