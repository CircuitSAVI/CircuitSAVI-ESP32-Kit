#  Project 01: ESP32 Ultrasonic Radar

## 📋 Components Required
- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Jumper Wires and Breadboard


##  Direct Wiring Connections

### 1. HC-SR04 Ultrasonic Sensor -> ESP32
* VCC -> 5V / VIN (ESP32)
* GND -> GND (ESP32)
* Trig -> GPIO 5 (ESP32)
* Echo -> GPIO 18 (ESP32)

### 2. SG90 Servo Motor -> ESP32
* Red (VCC) -> 5V / VIN (ESP32)
* Brown/Black (GND) -> GND (ESP32)
* Orange/Yellow (Signal) -> GPIO 19 (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Install ESP32 Board package and ESP32Servo library if not already installed.
3. Select Board: ESP32 Dev Module and the correct COM Port.
4. Click Upload.
5. Open Serial Monitor (115200 Baud) to view live angle and distance telemetry data.
