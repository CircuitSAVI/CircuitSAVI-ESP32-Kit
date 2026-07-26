#  Project 13: ESP32 Wireless Communication (ESP-NOW)

## 📋 Components Required
- 2x ESP32 Development Boards (Transmitter and Receiver)
- 1x Push Button
- 1x LED with 220 Ohm Resistor
- Breadboard and Jumper Wires

##  Direct Wiring Connections

### 1. Transmitter ESP32 Connections
* Push Button -> GPIO 4 (ESP32) and GND

### 2. Receiver ESP32 Connections
* LED Anode (+) -> GPIO 2 (via 220 Ohm Resistor)
* LED Cathode (-) -> GND (ESP32)


## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Find the target ESP32 Receiver MAC Address using `WiFi.macAddress()` and update the `receiverAddress` array in [code.ino](code.ino).
3. Select Board: ESP32 Dev Module and choose the correct COM Port.
4. Upload the code to both ESP32 units (with updated peer MAC addresses).
5. Press the button on the transmitter board to wirelessly toggle the LED on the receiving ESP32 without relying on a WiFi router.
