# Scientific Calculator on ATmega32

This project implements a scientific calculator using an ATmega32 microcontroller, a 4x4 keypad, and an LCD display. The calculator can perform basic arithmetic operations as well as advanced scientific functions like trigonometric calculations, logarithms, square roots, and exponents.

![Scientific Calculator](https://github.com/MohamedElsayedd1/Embedded-System-Mini-Projects/blob/main/5.%20Scientific_Calculator/CalculatorSimulation.gif)

## Features

- **Basic Operations:** Addition, subtraction, multiplication, and division.
- **Scientific Functions:**
  - Trigonometric functions (`sin`, `cos`, `tan`, `arcsin`, `arccos`, `arctan`).
  - Logarithmic functions (`log`, `ln`).
  - Exponentials (`e^x`).
  - Square root (`√`).
  - Modulus operator (`%`).
  - Parentheses for complex expressions.
  - Power operator (`^`).
- **Interactive Input:**
  - Keypad allows users to input mathematical expressions.
  - LCD displays real-time input and results.

## Hardware Requirements

- **Microcontroller:** ATmega32
- **LCD Display:** 16x2 character LCD
- **Keypad:** 4x4 matrix keypad
- **Power Supply:** 5V regulated power supply
- **Miscellaneous:**
  - Resistors and capacitors as needed for LCD and keypad interfacing.
  - Connecting wires and a breadboard or PCB.

## Software Requirements

- **Development Environment:** 
  - AVR GCC compiler
  - AVRDUDE or similar flashing tool
  - Atmel Studio (optional) or any compatible IDE
- **Programming Language:** C
- **Libraries Used:**
  - Keypad library (`keypad.h`)
  - LCD library (`lcd.h`)
  - Custom functions for mathematical calculations (`ScientificCalculator.h`)

## Circuit Diagram

Connect the hardware as follows:

1. **LCD:**
   - RS → PORTB0
   - RW → PORTB1
   - Enable → PORTB2
   - Data Pins (D4-D7) → PORTB4, PORTB5, PORTB6, PORTB7

2. **Keypad:**
   - Rows (R1-R4) → PORTC0 to PORTC3
   - Columns (C1-C4) → PORTD0 to PORTD3

3. **Power Supply:**
   - VCC → +5V
   - GND → GND

Refer to your specific hardware datasheets for pin configurations.

## How to Build and Upload

1. Clone this repository:
   ```bash
   git clone https://github.com/MohamedElsayedd1/scientific-calculator-atmega32.git
   cd scientific-calculator-atmega32
