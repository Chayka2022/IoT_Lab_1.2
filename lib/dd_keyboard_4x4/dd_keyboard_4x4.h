#ifndef KEYPAD_MANAGER_H
#define KEYPAD_MANAGER_H

#include <Keypad.h>

class dd_keyboard_4x4 {
public:
    dd_keyboard_4x4();  // Constructor
    char getKey();  // Function to get pressed key
private:
    Keypad keypad;  // Keypad object
};

#endif // KEYPAD_MANAGER_H
