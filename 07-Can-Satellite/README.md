#  Project 07: ESP32 Can Satellite Telemetry System

## 📋 Components Required
- ESP32 Development Board
- BMP280 Barometric Pressure Sensor Module
- MPU6050 Accelerometer and Gyroscope Module
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. I2C Bus Connections (Shared Pins)
* ESP32 SDA -> GPIO 21
* ESP32 SCL -> GPIO 22

### 2. BMP280 Sensor -> ESP32
* VCC -> 3.3V (ESP32)
* GND -> GND (ESP32)
* SDA -> GPIO 21 (ESP32)
* SCL -> GPIO 22 (ESP32)

### 3. MPU6050 Sensor -> ESP32
* VCC -> 3.3V (ESP32)
* GND -> GND (ESP32)
* SDA -> GPIO 21 (ESP32)
* SCL -> GPIO 22 (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Install required libraries via Library Manager:
   - Adafruit BMP280 Library
   - Adafruit MPU6050
   - Adafruit Unified Sensor
3. Select Board: ESP32 Dev Module and choose the correct COM Port.
4. Upload the code to ESP32.
5. Open Serial Monitor (115200 Baud) to view real-time altitude, pressure, and orientation telemetry data.
