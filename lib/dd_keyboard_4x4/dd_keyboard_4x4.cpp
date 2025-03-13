#include "dd_keyboard_4x4.h"

// Define the keypad layout
const byte ROW_NUM    = 4;    // Four rows
const byte COLUMN_NUM = 4;    // Four columns
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Define the row and column pin connections
byte pin_rows[ROW_NUM] = {2, 3, 4, 5};  // Rows connected to pins 2-5
byte pin_column[COLUMN_NUM] = {6, 7, 8, 9};  // Columns connected to pins 6-9

// Create keypad object
dd_keyboard_4x4::dd_keyboard_4x4() : keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM ) {}

// Get pressed key
char dd_keyboard_4x4::getKey() {
    return keypad.getKey();
}
