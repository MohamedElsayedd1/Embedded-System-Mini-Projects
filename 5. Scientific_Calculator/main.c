#include "./KEYPAD/keypad.h"
#include "./LCD/lcd.h"
#include "ScientificCalculator.h"

#ifndef F_CPU
#define F_CPU 1000000UL // 1 MHz
#endif

#define MAX_INPUT_LENGTH 100

keypad_t kpad1 = {
    .keypad_rows = {
        {PORTC_, pin0}, {PORTC_, pin1}, {PORTC_, pin2}, {PORTC_, pin3},
        {PORTC_, pin4}, {PORTC_, pin5}, {PORTC_, pin6}, {PORTC_, pin7}
    },
    .keypad_columns = {
        {PORTD_, pin0}, {PORTD_, pin1}, {PORTD_, pin2}, {PORTD_, pin3}
    }
};

void parse_keypad_input(keypad_t *kpad, char *input_str);

int main() {
    keypad_initialize(&kpad1);
    lcd_initialize();

    char input_str[MAX_INPUT_LENGTH] = "";
    char output_str[MAX_INPUT_LENGTH];

    while (1) {
        parse_keypad_input(&kpad1, input_str);

        if (strlen(input_str) > 0) {
            float res = calculate(input_str); // calculate(input_str);
            floatToString(res, output_str);
            lcd_send_command(_LCD_CLEAR); // Clear before displaying result
            lcd_send_string_pos(output_str, 0, 0); // Display at top-left corner
        }
    }

    return 0;
}

void parse_keypad_input(keypad_t *kpad, char *input_str) {
    uint8_t current_key = '\0';
    size_t length = strlen(input_str);

    while (1) {
        current_key = keypad_get_value(kpad);

        if (current_key != '\0' && current_key != '#' && current_key != '=') {
            // Valid key pressed
            if (current_key == 'C') {  // Cos
                strcat(input_str, "cos");
                lcd_send_string("cos");
            } 
            else if (current_key == 'S') {  // Sin
                strcat(input_str, "sin");
                lcd_send_string("sin");
            } 
            else if (current_key == 'T') {  // Tan
                strcat(input_str, "tan");
                lcd_send_string("tan");
            } 
            else if (current_key == 'L') {  // modulus
                strcat(input_str, "%");
                lcd_send_char_data('%');
            } 
            else if (current_key == 'A') {  // Arcsin
                strcat(input_str, "arcsin");
                lcd_send_string("arcsin");
            } 
            else if (current_key == 'R') {  // Arccos
                strcat(input_str, "arccos");
                lcd_send_string("arccos");
            } 
            else if (current_key == 'S') {  // Arctan
                strcat(input_str, "arctan");
                lcd_send_string("arctan");
            } 
            else if (current_key == 'P') {  // power ^
                strcat(input_str, "^");
                lcd_send_char_data('^');
            } 
            else if (current_key == 'E') {  // Ln
                strcat(input_str, "ln");
                lcd_send_string("ln");
            } 
            else if (current_key == 'F') {  // Log
                strcat(input_str, "log");
                lcd_send_string("log");
            } 
            else if (current_key == 'G') {  // Exp (e^x)
                strcat(input_str, "e");
                lcd_send_char_data('e');
            } 
            else if (current_key == 'H') {  // Square root 
                strcat(input_str, "sqrt");
                lcd_send_string("sqrt");
            } 
            else if (current_key == 'I') {  // (
                strcat(input_str, "(");
                lcd_send_char_data('(');
            } 
            else if (current_key == 'J') {  // )
                strcat(input_str, ")");
                lcd_send_char_data(')');
            } 
            else{
                lcd_send_char_data(current_key); // Display key on LCD
                input_str[length++] = current_key;
                input_str[length] = '\0';
            }

        } else if (current_key == '#') { 
            length = 0;
            input_str[0] = '\0';
            lcd_send_command(_LCD_CLEAR);
            break;
        } else if (current_key == '=') { 
            input_str[length] = '\0';
            break;
        }
    }
}
