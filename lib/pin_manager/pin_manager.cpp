#include "pin_manager.h"

PinManager::PinManager() {
    strcpy(storedPin, "0000");  // Default PIN before loading
}

void PinManager::loadPin() {
    const char* jsonString = R"({"pin": "1234"})";  // Simulated JSON

    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, jsonString);

    if (!error) {
        strcpy(storedPin, doc["pin"]);  // Store the correct PIN
    }
}

bool PinManager::checkPin(const char* enteredPin) {
    return strcmp(enteredPin, storedPin) == 0;  // Compare PINs
}
