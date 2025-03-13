#include "system_manager.h"

void SystemManager::systemInit() {
    initSerial(UART_BAUDRATE);
    LCD_4x4.init();  
    LCD_4x4.displayMessage("Introduce PIN code:", 0, 0);

    pinManager.loadPin();
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

void SystemManager::systemLoop() {
    char key = Keyboard.getKey();  // Read key press

    if (key) {
        // Handle numeric key input
        if (key >= '0' && key <= '9' && pinIndex < 4) {
            enteredPin[pinIndex++] = key;
            enteredPin[pinIndex] = '\0';  // Null-terminate string
            LCD_4x4.updatePinDisplay(enteredPin);
        }

        // Handle 'C' key to delete the last symbol
        if (key == 'C' && pinIndex > 0) {
            enteredPin[--pinIndex] = '\0';  // Remove last character
            LCD_4x4.updatePinDisplay(enteredPin);
        }

        // Handle 'A' key to check the PIN
        if (key == 'A') {
            if (pinIndex == 4) {
                if (pinManager.checkPin(enteredPin)) {
                    LCD_4x4.clearRow(2);
                    LCD_4x4.displayMessage("Access Granted!", 0, 2);
                    digitalWrite(LED_PIN, HIGH);
                } else {
                    LCD_4x4.clearRow(2);
                    LCD_4x4.displayMessage("Wrong PIN code!", 0, 2);
                    delay(2000);
                    digitalWrite(LED_PIN, LOW);
                }
            } else {
                LCD_4x4.clearRow(2);
                LCD_4x4.displayMessage("PIN code too short!", 0, 2);
            }

            // Reset PIN input
            memset(enteredPin, 0, sizeof(enteredPin));
            pinIndex = 0;
            LCD_4x4.updatePinDisplay("");
        }
    }
}
