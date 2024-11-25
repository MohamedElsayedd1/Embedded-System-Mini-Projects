#include <util/delay.h>
#include "MemMap.h"

#define MCU_CLK_FREQ            1000000UL

#define SET_BIT(REG,BIT_POS)    (REG |= (1 << BIT_POS))
#define RESET_BIT(REG,BIT_POS)  (REG &= ~(1 << BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS) (REG ^= (1 << BIT_POS))
#define READ_BIT(REG,BIT_POS)   ((REG >> BIT_POS) & 0x01)

#define CATHODE_7SEG_CRTL_PIN   4
#define ANODE_7SEG_CRTL_PIN     5

#define EN1                     0xFE
#define EN2                     0xFD
#define EN3                     0xFB
#define EN4                     0xF7
#define EN5                     0xEF
#define EN6                     0xDF
#define EN_ALL                  0x00
#define DIS_ALL                 0xFF

#define DELAY_TIME             5

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH
} gpio_state_t;

void myDelay(uint32_t delay){
    while(delay--);
}

void GPIO_Init(){
    DDRA = 0x0F;
    DDRC = 0x3F;
}

gpio_state_t PC0_Btn_Prevstate = GPIO_LOW;
uint8_t _7Seg[] = {0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b0110, 0b0111, 0b1000, 0b1001};
uint8_t hours = 23, minutes = 59, seconds = 50;

int main(){
    GPIO_Init();
    
    while(1){

        // 30ms * 33 = 1000ms = 1sec
        uint8_t count = 0;
        for(count = 0; count < 33; count++){
            // Enable First Digit Of Hours
            PORTC = EN1;
            // Write First Digit Of Hours
            PORTA = hours / 10;
            // Add Delay
            _delay_ms(DELAY_TIME);
            // Disbale All Chip Select
            PORTC = DIS_ALL;

            // Enable Second Digit Of Hours
            PORTC = EN2;
            // Write Second Digit Of Hours
            PORTA = hours % 10;
            // Add Delay
            _delay_ms(DELAY_TIME);
            // Disbale All Chip Select
            PORTC = DIS_ALL;

            // Enable First Digit Of Minutes
            PORTC = EN3;
            // Write First Digit Of Minutes
            PORTA = minutes / 10;
            // Add Delay
            _delay_ms(DELAY_TIME);
            // Disbale All Chip Select
            PORTC = DIS_ALL;

            // Enable Second Digit Of Minutes
            PORTC = EN4;
            // Write Second Digit Of Minutes
            PORTA = minutes % 10;
            // Add Delay
            _delay_ms(DELAY_TIME);
            // Disbale All Chip Select
            PORTC = DIS_ALL;

            // Enable First Digit Of Seconds
            PORTC = EN5;
            // Write First Digit Of Seconds
            PORTA = seconds / 10;
            // Add Delay
            _delay_ms(DELAY_TIME);
            // Disbale All Chip Select
            PORTC = DIS_ALL;

            // Enable Second Digit Of Seconds
            PORTC = EN6;
            // Write Second Digit Of Seconds
            PORTA = seconds % 10;
            // Add Delay
            _delay_ms(DELAY_TIME);
            // Disbale All Chip Select
            PORTC = DIS_ALL;
        }
        seconds++;
        if(seconds >= 60){
            seconds = 0;
            minutes++;
            if(minutes >= 60){
                minutes = 0;
                hours++;
                if(hours >= 24){
                    hours = 0;
                }
            }
        }
    }
    return 0;
}