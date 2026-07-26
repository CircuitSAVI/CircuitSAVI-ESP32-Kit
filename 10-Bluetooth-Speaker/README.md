#  Project 10: ESP32 Bluetooth Speaker

## 📋 Components Required
- ESP32 Development Board
- MAX98357A I2S Amplifier Module
- 4 Ohm or 8 Ohm Speaker
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. MAX98357A I2S DAC -> ESP32
* LRC (WS) -> GPIO 25 (ESP32)
* BCLK -> GPIO 26 (ESP32)
* DIN -> GPIO 22 (ESP32)
* VIN -> 5V / VIN (ESP32)
* GND -> GND (ESP32)

### 2. Speaker -> MAX98357A Amplifier
* Speaker Positive (+) -> MAX98357A Output (+)
* Speaker Negative (-) -> MAX98357A Output (-)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Install the required library:
   - Search for ESP32-A2DP by Phil Schatzmann in Library Manager and install it.
3. Select Board: ESP32 Dev Module and choose the correct COM Port.
4. Upload the code to ESP32.
5. Turn on Bluetooth on your smartphone or PC and pair with ESP32-Audio-Speaker. Play any audio track to hear sound through the connected speaker.
