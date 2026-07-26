#  Project 02: ESP32 Autonomous Car

## 📋 Components Required
- ESP32 Development Board
- L298N Motor Driver Module
- 2x BO Motors with Wheels
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Robot Chassis Kit
- 7.4V or 12V Li-ion Battery Pack
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

### 2. Ultrasonic Sensor -> ESP32
* VCC -> 5V / VIN (ESP32)
* GND -> GND (ESP32)
* Trig -> GPIO 5 (ESP32)
* Echo -> GPIO 18 (ESP32)

### 3. Servo Motor -> ESP32
* VCC (Red) -> 5V / VIN (ESP32)
* GND (Brown/Black) -> GND (ESP32)
* Signal (Orange) -> GPIO 19 (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Ensure ESP32 board support and ESP32Servo library are installed.
3. Select Board: ESP32 Dev Module and correct COM Port.
4. Upload code to ESP32.
5. Place the chassis on the ground and turn on motor power to observe autonomous obstacle avoidance.
