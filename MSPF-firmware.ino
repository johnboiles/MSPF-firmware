#include <Arduino.h>
#include "inttypes.h"

#define DEBUG_LED LED_BUILTIN

#define LED_INPUT_MIN_PIN 0
#define LED_INPUT_MAX_PIN 19
#define LED_OUTPUT_PIN 23

#define BUTTON_COUNT 20

// Buttons can only be pressed once a second, this keeps track of when they were last pressed
// Buttons are ready to be fired when their respective counter gets down to 0
int ButtonCounters[BUTTON_COUNT];

void setup() {
    Serial.begin(115200);

    // See https://www.pjrc.com/teensy/td_pulse.html
//    pinMode(LED_OUTPUT_PIN, OUTPUT);
//    analogWriteFrequency(LED_OUTPUT_PIN, 38000);
//    analogWrite(LED_OUTPUT_PIN, 230);

//    pinMode(DEBUG_LED, OUTPUT);

    for (int i = 0; i < BUTTON_COUNT; i++) {
        pinMode(i, INPUT_PULLUP);
        ButtonCounters[i] = 0;
    }
}

void loop() {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        // Check if the input is active
        bool input = digitalRead(i);
        if (!input) {
            if (ButtonCounters[i] == 0) {
                char output = 'a' + i;
                Serial.print(output);
            }
            ButtonCounters[i] = 10;
        } else {
            if (ButtonCounters[i] > 0) {
                ButtonCounters[i]--;
            }
        }
    }
    delay(10);

//    bool input = digitalRead(2);
//    if (input) {
//        digitalWrite(DEBUG_LED, HIGH);
//    } else {
//        digitalWrite(DEBUG_LED, LOW);
//    }
//    delay(10);
//    incrementTime();
//    if (Time > 1000) {
//        digitalWrite(DEBUG_LED, HIGH);
//        delay(500);
//        digitalWrite(DEBUG_LED, LOW);
//        delay(500);
//        digitalWrite(DEBUG_LED, HIGH);
//        delay(500);
//        digitalWrite(DEBUG_LED, LOW);
//        delay(500);
//        Time = 0;
//    }
}
