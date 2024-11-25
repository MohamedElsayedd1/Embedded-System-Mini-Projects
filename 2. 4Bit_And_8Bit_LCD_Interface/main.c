#include "./LCD/lcd.h"
#include "./KEYPAD/keypad.h"

// Define the CPU clock frequency
#ifndef F_CPU
#define F_CPU 1000000UL // 1 MHz
#endif

int main(){
    uint32_t number = 5099;
    char num_str[11];
    covert_num_to_str(number, num_str);

    uint8_t const custm_char1[] = {
        0x00,
        0x06,
        0x0F,
        0x0F,
        0x07,
        0x03,
        0x01,
        0x00
    };

    uint8_t const custm_char2[] = {
        0x00,
        0x0C,
        0x1E,
        0x1E,
        0x1C,
        0x18,
        0x10,
        0x00
    };

    lcd_initialize();
    lcd_send_string_pos("Q1:Capital of Egypt?", 1, 1);
    lcd_send_string_pos("1) Cairo  2) Rome", 2, 1);
    lcd_send_string_pos(num_str, 4, 1);

    lcd_send_custom_char(custm_char1, 4, 8, 0);
    lcd_send_custom_char(custm_char2, 4, 9, 1);
    
    while(1){
        for (int i = 1; i < 5; i++){
            lcd_send_string_pos("\"Mohamed Elsayed\"", 3, i);
            _delay_ms(250);
            lcd_send_char_data_pos(' ', 3, i);
        }
        lcd_send_string_pos("                       ", 3, 1);
    }
    return 0;
}

