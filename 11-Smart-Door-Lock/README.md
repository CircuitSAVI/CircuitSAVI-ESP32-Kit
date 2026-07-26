#  Project 11: ESP32 Smart Door Lock

## 📋 Components Required
- ESP32 Development Board
- RC522 RFID Module (with Tag/Card)
- SG90 Servo Motor
- Active Buzzer
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. RC522 RFID Module -> ESP32 (SPI)
* VCC -> 3.3V (ESP32)
* RST -> GPIO 22 (ESP32)
* GND -> GND (ESP32)
* MISO -> GPIO 19 (ESP32)
* MOSI -> GPIO 23 (ESP32)
* SCK -> GPIO 18 (ESP32)
* SDA (SS) -> GPIO 5 (ESP32)

### 2. SG90 Servo Motor -> ESP32
* VCC (Red) -> 5V / VIN (ESP32)
* GND (Brown/Black) -> GND (ESP32)
* Signal (Orange) -> GPIO 13 (ESP32)

### 3. Active Buzzer -> ESP32
* Positive (+) -> GPIO 12 (ESP32)
* Negative (-) -> GND (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Install required libraries via Library Manager:
   - MFRC522 by githublink
   - ESP32Servo
3. Scan your RFID card in the Serial Monitor first to get its UID, then update the authorizedUID array in [code.ino](code.ino).
4. Select Board: ESP32 Dev Module and pick the correct COM Port.
5. Upload the code to ESP32.
6. Scan the authorized RFID tag to unlock the servo mechanism with audio feedback.
