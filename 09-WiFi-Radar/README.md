#  Project 09: ESP32 WiFi Radar

## 📋 Components Required
- ESP32 Development Board
- SG90 Servo Motor
- 0.96 inch I2C OLED Display (128x64)
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. SG90 Servo Motor -> ESP32
* VCC (Red) -> 5V / VIN (ESP32)
* GND (Brown/Black) -> GND (ESP32)
* Signal (Orange) -> GPIO 19 (ESP32)

### 2. OLED Display (I2C) -> ESP32
* VCC -> 3.3V (ESP32)
* GND -> GND (ESP32)
* SDA -> GPIO 21 (ESP32)
* SCL -> GPIO 22 (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Install required libraries via Library Manager:
   - Adafruit SSD1306
   - Adafruit GFX Library
   - ESP32Servo
3. Select Board: ESP32 Dev Module and choose the correct COM Port.
4. Upload the code to ESP32.
5. Watch the servo sweep back and forth as the ESP32 scans nearby WiFi networks and displays their SSID and RSSI signal strength on the OLED screen.
