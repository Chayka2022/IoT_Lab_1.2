#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <Arduino.h>
#include "serial_manager.h"
#include "dd_keyboard_4x4.h"
#include "dd_LCD_4x2(I2C).h"
#include "pin_manager.h"

class SystemManager {
public:
    void systemInit();
    void systemLoop();

private:
    dd_LCD_4x4 LCD_4x4 = dd_LCD_4x4(0x27, 20, 4);
    dd_keyboard_4x4 Keyboard;
    PinManager pinManager;

    char enteredPin[5] = "";  // Buffer for entered PIN
    uint8_t pinIndex = 0;
};

#endif
