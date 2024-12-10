# Digital Clock on ATmega32

This project implements a digital clock using an ATmega32 microcontroller, 7-segment displays, and a multiplexing technique. The clock displays hours, minutes, and seconds, and updates every second.

![Digital Clock](https://github.com/MohamedElsayedd1/Embedded-System-Mini-Projects/blob/main/1.%20Digital-Clock/DigitalClock.gif)

## Features

- **Real-time Clock:** Displays hours, minutes, and seconds.
- **Time Format:** 24-hour format.
- **Efficient Multiplexing:** Uses a single PORT for driving multiple 7-segment displays.
- **Custom Delay Implementation:** Provides accurate timing with `_delay_ms()`.

## Hardware Requirements

- **Microcontroller:** ATmega32
- **Display:** 6 common-cathode 7-segment displays
- **Control Pins:**
  - `PORTC`: Segment control (6 pins for digit enable/disable).
  - `PORTA`: 4 pins for data output to the 7-segment display.
- **Power Supply:** 5V regulated power supply.
- **Miscellaneous:**
  - Resistors for current limiting on 7-segment displays.
  - Connecting wires and a breadboard or PCB.

## Software Requirements

- **Development Environment:**
  - AVR GCC compiler
  - AVRDUDE or similar flashing tool
  - Atmel Studio (optional) or any compatible IDE
- **Programming Language:** C

## Circuit Diagram

### Connections:

1. **7-Segment Displays:**
   - Connect the cathodes of all 7-segment displays to `PORTA` (pins PA0-PA3).
   - Connect the control pins for each 7-segment display to `PORTC` (pins PC0-PC5).

2. **Power Supply:**
   - VCC → +5V
   - GND → GND

### Control Logic:

- Each 7-segment display is enabled by setting its corresponding pin on `PORTC` (e.g., `EN1`, `EN2`, etc.).
- Only one display is enabled at a time using multiplexing.

Refer to the microcontroller and 7-segment datasheets for precise pin configurations.

## How It Works

1. **Initialization:**
   - Configure `PORTA` and `PORTC` as output ports.
   - Initialize variables for hours, minutes, and seconds.

2. **Time Update:**
   - The clock starts at `23:59:50` and increments the time every second.
   - After `23:59:59`, the time resets to `00:00:00`.

3. **Multiplexing:**
   - Each digit of the time is displayed sequentially on its respective 7-segment display.
   - A small delay ensures persistence of vision, making it appear as if all displays are lit simultaneously.

4. **Timing:**
   - The delay between updates is calibrated to match 1 second of real time using `_delay_ms()`.

## How to Build and Upload

1. Clone this repository:
   ```bash
   git clone https://github.com/MohamedElsayedd1/digital-clock-atmega32.git
   cd digital-clock-atmega32
