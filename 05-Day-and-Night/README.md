#  Project 05: ESP32 Day and Night Light System

## 📋 Components Required
- ESP32 Development Board
- LDR (Light Dependent Resistor) Sensor Module
- 5mm LED
- 220 Ohm Resistor
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. LDR Sensor Module -> ESP32
* VCC -> 3.3V (ESP32)
* GND -> GND (ESP32)
* AO (Analog Output) -> GPIO 34 (ESP32)

### 2. LED -> ESP32
* Anode (Long Leg) -> GPIO 2 (ESP32 via 220 Ohm Resistor)
* Cathode (Short Leg) -> GND (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Select Board: ESP32 Dev Module and choose the correct COM Port.
3. Upload the code to ESP32.
4. Open Serial Monitor (115200 Baud) to view light values.
5. Cover the LDR sensor to simulate night time and watch the LED turn ON automatically.
