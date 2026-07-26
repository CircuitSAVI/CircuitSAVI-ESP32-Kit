#include <WiFi.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 5;
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      Serial.print("BLE Device: ");
      Serial.print(advertisedDevice.getName().c_str());
      Serial.print(" | Address: ");
      Serial.print(advertisedDevice.getAddress().toString().c_str());
      Serial.print(" | RSSI: ");
      Serial.println(advertisedDevice.getRSSI());
    }
};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);

  Serial.println("WiFi and BLE Network Analyzer Initialized.");
}

void loop() {
  Serial.println("\n--- Starting WiFi Scan ---");
  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("No WiFi networks found.");
  } else {
    Serial.print(n);
    Serial.println(" WiFi networks found:");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (RSSI: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dBm) Channel: ");
      Serial.print(WiFi.channel(i));
      Serial.print(" Security: ");
      Serial.println(WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "Open" : "Secured");
      delay(10);
    }
  }

  Serial.println("\n--- Starting BLE Scan ---");
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  Serial.print("Total BLE Devices Found: ");
  Serial.println(foundDevices.getCount());
  pBLEScan->clearResults();

  delay(5000);
}
