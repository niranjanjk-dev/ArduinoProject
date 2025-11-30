# 🔊 Ultrasonic Distance Alarm

A minimalist distance detection system. It uses an ultrasonic sensor to detect proximity, triggering visual (LED) and audio (Buzzer) alerts as objects get closer.

## 📦 Hardware List
* **Controller:** Arduino Uno R3
* **Sensor:** HC-SR04 Ultrasonic Module
* **Audio:** 5V Active Piezo Buzzer
* **Visual:** 3x LEDs (Green,Yellow,Red(#Any Color of your choice))
* **Passive:** 3x Resistors (220Ω or 330Ω)
* **Wiring:** Jumper Wires (M-to-M) & Breadboard
* **Power:** 9V/12V DC Adapter or USB


## 🔌 Wiring Diagram (Pinout)

| Component | Arduino Pin |
|-----------|-------------|
| **Trig**  | D6          |
| **Echo**  | D7          |
| **Buzzer**| D9          |
| **LED 1** | D2          |
| **LED 2** | D3          |
| **LED 3** | D4          |

> *Note: Update the pin numbers above to match your specific code.*

## 🚀 Usage
1.  Connect the circuit as per the pinout table.
2.  Upload the code (Python/Reduino or C++).
3.  Move an object in front of the sensor to test the alarm threshold.