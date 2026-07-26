#  Project 12: ESP32 Web Hosting

## 📋 Components Required
- ESP32 Development Board
- Onboard LED (GPIO 2) or external LED with 220 Ohm Resistor
- Local WiFi Network Connection
- Breadboard and Jumper Wires


##  Direct Wiring Connections

### 1. External LED (Optional - Uses Built-in LED on GPIO 2 by default)
* LED Anode (+) -> GPIO 2 (via 220 Ohm Resistor)
* LED Cathode (-) -> GND (ESP32)



## 🚀 How to Run Code
1. Open [code.ino](code.ino) in Arduino IDE.
2. Update the `ssid` and `password` variables in [code.ino](code.ino) with your local WiFi credentials.
3. Select Board: ESP32 Dev Module and pick the correct COM Port.
4. Upload the code to ESP32.
5. Open Serial Monitor (115200 Baud) to find the local IP address assigned to ESP32.
6. Open any browser on a device connected to the same WiFi network and enter the ESP32 IP address to access the hosted web interface.
