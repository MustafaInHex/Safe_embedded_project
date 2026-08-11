# SAFE Embedded System (ATmega32)

#Description
An embedded C project for the ATmega32 microcontroller. This project features modular drivers for keypad input, LCD display, EEPROM storage, and various I/O operations (LEDs, Buttons, Seven-Segment).

# Components & Tools
*   **Microcontroller:** ATmega32
*   **Simulation:** Proteus Design Suite
*   **Language:** Embedded C
*   **Peripherals:** Keypad, LCD, LEDs, Seven-Segment Display, EEPROM

# Project Structure
*   `SAFE (MY CODE).cproj` - Main project file.
*   `KEYPAD.c/.h` - Keypad driver.
*   `LCD.c/.h` - LCD driver.
*   `DIO.c/.h` - Digital I/O driver.
*   `EEPROM.c/.h` - EEPROM driver.
*   `BUTTON.c/.h` - Button handling.
*   `LED.c/.h` - LED control.
*   `SEVENEGMENT.c/.h` - Seven-segment display driver.

# How to Run
1. Open the `design.DBK` or `design.PWI` file in Proteus.
2. Compile the code in your IDE (e.g., Atmel Studio / AVR Studio).
3. Load the generated `.hex` file into the ATmega32 in Proteus.
4. Run the simulation.
