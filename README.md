# SecureVault: Advanced Electronic Bank Locker System

## Description
A high-security embedded access control system designed to simulate a modern bank locker. This project goes beyond basic password entry by implementing advanced anti-tamper algorithms, brute-force protection, timed lockouts, and a master override system to ensure maximum physical and digital security.

## Component Usage & Technical Implementation

### Keypad
*   **Usage:** The primary secure input interface.
*   **Role:** Used by the user to input the secret password, the master override code, and to navigate the password-changing menu. The firmware includes debouncing logic to ensure accurate keystroke registration.

### LCD Display (16x2)
*   **Usage:** The Human-Machine Interface (HMI).
*   **Role:** Provides real-time system feedback. It displays prompts ("Enter Password", "Access Granted"), security warnings and counting the time ("System Locked: 4:59 "), and guides the user through the password modification process.

### Buzzer
*   **Usage:** Audio feedback and alarm system.
*   **Role:** Emits distinct audio tones for different events: a short beep for successful keypresses, a pleasant chime for "Access Granted", and a continuous alarm sound to alert users during a security lockout or failed attempt.

### LEDs (Status Indicators)
*   **Usage:** Visual system status.
*   **Role:** A Green LED indicates the locker is unlocked and operational. A Red LED flashes to indicate a failed password attempt or an active security lockout.

###  Push Buttons
*   **Usage:** Hardware control and navigation.
*   **Role:** Used for specific system functions such as "Enter/Confirm", "Clear/Backspace", or simulating the physical locking/unlocking mechanism of the locker door.

##  Key Software Features & Security Logic

###  Multi-Tier Brute-Force Protection
*   **The Problem:** Simple password systems are vulnerable to guessing or brute-force attacks.
*   **The Solution:** The system implements a strict, escalating security state machine:
    1.  **Phase 1:** The user is allowed **5 incorrect trials**.
    2.  **Phase 2 (Timed Lockout):** Upon the 5th failure, the system enters a hard lock for **5 minutes**, displaying a countdown on the LCD.
    3.  **Phase 3 (Final Warning):** After the timeout, the user is granted exactly **3 final trials**.
    4.  **Phase 4 (Permanent Lock):** If the 3 final trials fail, the system locks indefinitely. It will no longer accept the user password and requires the Master Code to reset.

###  Master Override & Password Management
*   **Master Code Access:** A hidden, hard-coded "Master Code" acts as an administrative backdoor. 
*   **Unlocking the System:** If the system enters a "Permanent Lock" (Phase 4), only the Master Code can reset the system and restore normal operation.
*   **Password Modification:** To change the user password, the system requires the Master Code first. This prevents unauthorized users from changing the password even if they have temporary access to the keypad.

##  Real-World Applications
*   **Banking & Finance:** Secure deposit boxes and vault access control.
*   **Hospitality:** Electronic safes in hotel rooms.
*   **Smart Home Security:** Secure rooms, gun safes, or server room access.
*   **Corporate Offices:** Restricted area access control with admin override capabilities.

##  Project Structure
*   `/Src` - Contains all the main C source code files (main logic, keypad driver, LCD driver, security state machine).
*   `/Inc` - Contains all the C header files for modular code organization.
*   `/Proteus` - Contains the Proteus simulation design files and schematics.

## 🔧 How to Run the Simulation
1. Open the `.DBK` or `.PWI` file located in the `Proteus` folder using Proteus Design Suite.
2. Compile the Embedded C code in your IDE (e.g., Atmel Studio / AVR Studio).
3. Load the generated `.hex` file into the microcontroller component in Proteus.
4. Run the simulation. Test the normal password entry, intentionally fail 5 times to trigger the 5-minute lockout, and use the Master Code to test the override and password-changing features.
# How to Run
1. Open the `design.DBK` or `design.PWI` file in Proteus.
2. Compile the code in your IDE (e.g., Atmel Studio / AVR Studio).
3. Load the generated `.hex` file into the ATmega32 in Proteus.
4. Run the simulation.
