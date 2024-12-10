#include "keypad.h"


uint8_t *PORT_REGISTERS[] = {&PORTA, &PORTB, &PORTC, &PORTD};
uint8_t *DDR_REGISTERS[] = {&DDRA, &DDRB, &DDRC, &DDRD};
uint8_t *PIN_REGISTERS[] = {&PINA, &PINB, &PINC, &PIND};

// Define the keypad layout
const char KEYPAD_VALUES[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
    {'7', '8', '9', '/'},  // Row 1
    {'4', '5', '6', '*'},  // Row 2
    {'1', '2', '3', '-'},  // Row 3
    {'#', '0', '=', '+'},  // Row 4
    {'C', 'S', 'T', 'L'},  // 'C' for Cos, 'S' for Sin, 'T' for Tan, 'L' for Ln
    {'A', 'R', 'S', 'P'},  // 'A' for Arcsin, 'R' for Arccos, 'S' for Sqrt, 'P' for Exp
    {'E', 'F', 'G', 'H'},  // 'E' for Ln, F for Log, G for Exp(e^), H for power(^)
    {'I', 'J', 'K', 'L'}   // I for '(', J for ')' 
};



void keypad_initialize(keypad_t *kpad){
    // Set ROWS as output
    for (int i = 0; i < KEYPAD_ROWS; i++){
        SET_BIT(*DDR_REGISTERS[kpad->keypad_rows[i].port], kpad->keypad_rows[i].pin);
    }
    
    // Set Columns as input
    for (int i = 0; i < KEYPAD_COLUMNS; i++){ 
        CLEAR_BIT(*DDR_REGISTERS[kpad->keypad_columns[i].port], kpad->keypad_columns[i].pin);
    }
}

uint8_t keypad_get_value(keypad_t *kpad) {
    // Iterate over each row
    for (int row = 0; row < KEYPAD_ROWS; row++) {
        // Set the current row HIGH and all others LOW
        for (int r = 0; r < KEYPAD_ROWS; r++) {
            if (r == row) {
                SET_BIT(*PORT_REGISTERS[kpad->keypad_rows[r].port], kpad->keypad_rows[r].pin);
            } else {
                CLEAR_BIT(*PORT_REGISTERS[kpad->keypad_rows[r].port], kpad->keypad_rows[r].pin);
            }
        }

        // Check each column for a pressed key
        for (int col = 0; col < KEYPAD_COLUMNS; col++) {
            if (READ_BIT(*PIN_REGISTERS[kpad->keypad_columns[col].port], kpad->keypad_columns[col].pin) == 1) {
                //while (READ_BIT(*PIN_REGISTERS[kpad->keypad_columns[col].port], kpad->keypad_columns[col].pin) == 1); // Wait for release
                _delay_ms(300); // Debouncing
                // Return the corresponding key value
                return KEYPAD_VALUES[row][col];
            }
        }
    }

    // Return 0 if no key is pressed
    return 0;
}

