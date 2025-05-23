#include "dd_led.h"

void dd_led_setup(dd_led_t *led, int pin) 
{
    led->led_pin = pin;
    pinMode(led->led_pin, OUTPUT);
}

void dd_turn_led_on(dd_led_t *led) 
{
    digitalWrite(led->led_pin, HIGH);
}

void dd_turn_led_off(dd_led_t *led) 
{
    digitalWrite(led->led_pin, LOW);
}

