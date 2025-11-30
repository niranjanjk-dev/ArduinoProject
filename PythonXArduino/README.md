# 🐍 Arduino X Python: Integration Experiments

Welcome to **ArduinoXPython**! This repository explores different methods of integrating Python with Arduino hardware. It contains examples and experiments using various libraries to bridge the gap between high-level scripting and low-level hardware control.

## 🚀 Approaches Covered

This repository demonstrates three distinct ways to make Python talk to Arduino:

1.  **Reduino:** * *Concept:* Write Python code that gets **compiled and uploaded** to the Arduino.
    * *Use case:* Standalone robots/devices that run without a computer connected.
    
2.  **PyFirmata:** * *Concept:* The Arduino runs a "server" sketch (StandardFirmata), and Python acts as the remote control.
    * *Use case:* Real-time control, prototyping, and testing directly from a PC.

3.  **PySerial:** * *Concept:* Classic serial communication. Python sends text/bytes; Arduino reads them and reacts.
    * *Use case:* Data logging, dashboards, and custom communication protocols.

---

## 🛠️ Hardware Requirements

* **Microcontroller:** Arduino Uno, Nano, or Mega.
* **Connection:** USB A-to-B cable.
* **Sensors/Actuators:** LEDs, Ultrasonic Sensors (HC-SR04), etc., depending on the script.

---

## 💻 Software Setup (Linux/Fedora)

It is recommended to use a Python virtual environment to manage dependencies.

### 1. Clone and Setup
```bash
# Clone the repo
git clone [https://github.com/YOUR_USERNAME/ArduinoXPython.git](https://github.com/YOUR_USERNAME/ArduinoXPython.git)
cd ArduinoXPython

# Create virtual environment (Python 3.12 recommended)
python -m venv .venv

# Activate environment
source .venv/bin/activate
