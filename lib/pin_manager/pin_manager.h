#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <ArduinoJson.h>  // Include ArduinoJson library

class PinManager {
public:
    PinManager();
    void loadPin();  // Load the correct PIN from JSON
    bool checkPin(const char* enteredPin);  // Compare entered PIN

private:
    char storedPin[5];  // Store correct PIN (4 digits + null terminator)
};

#endif
