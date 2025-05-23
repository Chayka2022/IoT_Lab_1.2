#ifndef DD_LED_H
#define DD_LED_H

#include <Arduino.h>

typedef struct dd_led {
    int led_pin;
} dd_led_t; //алиас, псевдоним для структуры

void dd_led_setup(dd_led_t *led, int pin);

void dd_turn_led_on(dd_led_t *led);

void dd_turn_led_off(dd_led_t *led);

#endif