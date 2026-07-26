#  Project 06: ESP32 Signal System

## 📋 Components Required
- ESP32 Development Board
- Red LED
- Yellow LED
- Green LED
- 3x 220 Ohm Resistors
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. Traffic LEDs -> ESP32
* Red LED Anode (+) -> GPIO 25 (via 220 Ohm Resistor)
* Yellow LED Anode (+) -> GPIO 26 (via 220 Ohm Resistor)
* Green LED Anode (+) -> GPIO 27 (via 220 Ohm Resistor)
* All LED Cathodes (-) -> GND (ESP32 Common Ground)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Select Board: ESP32 Dev Module and pick the correct COM Port.
3. Upload the code to ESP32.
4. Watch the traffic signal light sequence execute automatically.
