#  Project 03: ESP32 Line Follower Car

## 📋 Components Required
- ESP32 Development Board
- 2x IR Sensor Modules
- L298N Motor Driver Module
- 2x BO Motors with Wheels
- Robot Chassis Kit
- Battery Pack
- Jumper Wires


##  Direct Wiring Connections

### 1. L298N Motor Driver -> ESP32
* IN1 -> GPIO 27 (ESP32)
* IN2 -> GPIO 26 (ESP32)
* IN3 -> GPIO 25 (ESP32)
* IN4 -> GPIO 33 (ESP32)
* ENA -> GPIO 14 (ESP32)
* ENB -> GPIO 12 (ESP32)
* GND -> GND (ESP32 - Common Ground)

### 2. IR Sensor Modules -> ESP32
* Left IR VCC -> 3.3V / 5V (ESP32)
* Left IR GND -> GND (ESP32)
* Left IR OUT -> GPIO 34 (ESP32)
* Right IR VCC -> 3.3V / 5V (ESP32)
* Right IR GND -> GND (ESP32)
* Right IR OUT -> GPIO 35 (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Select Board: ESP32 Dev Module and choose the correct COM Port.
3. Upload the code to ESP32.
4. Place the robot car on a track with a dark line over a light surface.
5. Turn on power supply and adjust IR potentiometer sensitivity if needed.
