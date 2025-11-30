# 🎙️ Voice Controlled Home Automation System

A smart home prototype that controls lighting, ventilation, and a display using voice commands. It utilizes an Arduino and an offline voice recognition module (VC-02) to process commands and execute actions instantly.

## 📦 Hardware List
* **Controller:** Arduino Uno R3 (or Nano)
* **Voice Module:** VC-02 (Offline Voice Recognition Module)
* **Display:** 16x2 LCD with I2C Interface
* **Actuators:** * 1x 5V Fan (requires Relay or Transistor driver)
  * 3x LEDs (Red, Green, Blue)
* **Passive:** 3x Resistors (220Ω or 330Ω) for LEDs
* **Wiring:** Jumper Wires (M-to-M & M-to-F) & Breadboard
* **Power:** 9V Battery (via DC Jack/VIN) or USB Cable

## 🔌 Wiring Diagram (Pinout)

### 1. Voice Module (VC-02)
| VC-02 Pin | Arduino Pin |             Note                |
|-----------|-------------|---------------------------------|
| **TX**    | D2          | Module Transmits to Arduino RX  |
| **RX**    | D3          | Module Receives from Arduino TX |
| **VCC**   | 5V          |      **Do not** use 3.3V        |
| **GND**   | GND         |         Common Ground           |

### 2. Output Devices
|   Component   | Arduino Pin |
|---------------|-------------|
| **Red LED**   |     D4      |
| **Green LED** |     D5      |
| **Blue LED**  |     D6      |
|    **Fan**    |     D7      |
| **LCD SDA**   |  A4(Or SAD) |
| **LCD SCL**   |  A5(Or SCL) |

> *Note: For the Fan, connect Pin D7 to the Signal pin of your Relay/MOSFET module. Do not connect the motor directly to the Arduino pin.*

## 🗣️ Voice Command Hex Codes
You must configure your VC-02 module firmware with these specific Hexadecimal parameters for the system to recognize commands.

|      Action   | Hex Code |      Spoken Command Examples             |
|:--------------|:---------|:-----------------------------------------|
| **Red ON**    |   `11`   | "Turn on red light", "Red light on"      |
| **Red OFF**   |   `10`   | "Turn off red light", "Red light off"    |
| **Green ON**  |   `21`   | "Turn on green light", "Green on"        |
| **Green OFF** |   `20`   | "Turn off green light", "Green off"      |
| **Blue ON**   |   `31`   | "Turn on blue light", "Blue on"          |
| **Blue OFF**  |   `30`   | "Turn off blue light", "Blue off"        |
| **Fan ON**    |   `41`   | "Start fan", "Turn on fan"               |
| **Fan OFF**   |   `40`   | "Stop fan", "Turn off fan"               |
| **LCD ON**    |   `51`   | "Screen on", "Display on"                |
| **LCD OFF**   |   `50`   | "Screen off", "Display off"              |
| **All Off**   |   `60`   | "Turn everything off", "All lights off"  |
| **Shutdown**  |   `70`   | "Shutdown system", "System off"          |
| **Clear LCD** |   `80`   | "Clear screen", "Clear display"          |

## 🚀 Usage
1. **Configure Module:** Flash the VC-02 module with the Hex codes listed above using the manufacturer's tool.
2. **Wire Circuit:** Connect all components according to the wiring table.
3. **Upload Code:** Connect the Arduino to your PC and upload the `voice_hex_logic.ino` file.
    * *Note: Unplug the VC-02 TX/RX wires while uploading to avoid errors.*
4. **Power Up:** Connect the 9V battery or USB. The LCD should display "System Ready".
5. **Test:** Say "Turn on Red Light". The Red LED should glow, and the LCD should confirm the action.