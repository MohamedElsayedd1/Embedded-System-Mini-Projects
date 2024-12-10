
# Keypad with LCD Display on AVR Microcontroller

This project demonstrates how to interface a **4x4 Keypad** with an **LCD display** using an AVR microcontroller (e.g., ATmega32). The program captures a key press from the keypad and displays the corresponding character on the LCD screen.

![Keypad-LCD](https://github.com/MohamedElsayedd1/Embedded-System-Mini-Projects/blob/main/3.%20LCD_And_Keypad_Interface/keypad_lcd_interface.gif)


## Features

- **Keypad Handling**: Detects key presses and translates them into characters.
- **Single Key Detection**: Displays a key only once per press.
- **LCD Integration**: Shows the pressed key on the LCD in real-time.
- **Debounce Logic**: Prevents multiple detections from a single press due to mechanical bounce.

---

## How It Works

1. **Keypad Initialization**:
   - Rows are configured as outputs.
   - Columns are configured as inputs with pull-up resistors.

2. **Key Press Detection**:
   - Scans each row and checks for a column signal.
   - Returns the corresponding character.

3. **LCD Display**:
   - Displays the detected character only once per key press.

4. **Debouncing**:
   - Implements a delay to ensure clean detection.

---

## Hardware Requirements

- **Microcontroller**: AVR-based MCU (e.g., ATmega32).
- **LCD**: 16x2 or similar.
- **Keypad**: 4x4 matrix keypad.
- **Miscellaneous**: Pull-up resistors, jumper wires, breadboard.

---

## Software Requirements

- **IDE**: Atmel Studio, Microchip Studio, or any AVR-compatible IDE.
- **Libraries**:
  - Keypad library (included in the project).
  - LCD library (included in the project).
- **Toolchain**: AVR-GCC.

---
