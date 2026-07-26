# Project 08: ESP32 Temperature System

## 📋 Components Required
- ESP32 Development Board
- DHT11 Temperature and Humidity Sensor
- 0.96 inch I2C OLED Display (128x64)
- 10k Ohm Resistor (Pull-up for DHT11 data pin if module not used)
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. DHT11 Sensor -> ESP32
* VCC -> 3.3V / 5V (ESP32)
* GND -> GND (ESP32)
* Data -> GPIO 4 (ESP32)

### 2. OLED Display (I2C) -> ESP32
* VCC -> 3.3V (ESP32)
* GND -> GND (ESP32)
* SDA -> GPIO 21 (ESP32)
* SCL -> GPIO 22 (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Install required libraries via Library Manager:
   - DHT sensor library by Adafruit
   - Adafruit SSD1306
   - Adafruit GFX Library
3. Select Board: ESP32 Dev Module and pick the correct COM Port.
4. Upload the code to ESP32.
5. Check real-time temperature and humidity readings displayed on both OLED screen and Serial Monitor (115200 Baud).
