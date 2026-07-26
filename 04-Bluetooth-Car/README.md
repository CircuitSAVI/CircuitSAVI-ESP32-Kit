#  Project 04: ESP32 Bluetooth Car

## 📋 Components Required
- ESP32 Development Board
- L298N Motor Driver Module
- 2x BO Motors with Wheels
- Robot Chassis Kit
- Battery Pack
- Android Phone with Bluetooth Terminal/Controller App
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


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Select Board: ESP32 Dev Module and choose the correct COM Port.
3. Upload the code to ESP32.
4. Turn on Bluetooth on your smartphone and pair with device named ESP32_BT_Car.
5. Open any Bluetooth Car Controller App and send commands (F: Forward, B: Backward, L: Left, R: Right, S: Stop).
