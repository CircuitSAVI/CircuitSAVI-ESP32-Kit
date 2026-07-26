#include <esp_now.h>
#include <WiFi.h>

const int BUTTON_PIN = 4;
const int LED_PIN = 2;

// Replace with Receiver ESP32 MAC Address: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}
uint8_t receiverAddress[] = {0x24, 0x6F, 0x28, 0xAB, 0xCD, 0xEF};

typedef struct struct_message {
  bool buttonState;
} struct_message;

struct_message outgoingData;
struct_message incomingData;

esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Last Packet Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingDataBytes, int len) {
  memcpy(&incomingData, incomingDataBytes, sizeof(incomingData));
  digitalWrite(LED_PIN, incomingData.buttonState ? HIGH : LOW);
  Serial.print("Received Remote Command. LED State: ");
  Serial.println(incomingData.buttonState ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  bool currentButtonState = (digitalRead(BUTTON_PIN) == LOW);
  
  static bool lastState = false;
  if (currentButtonState != lastState) {
    outgoingData.buttonState = currentButtonState;
    esp_now_send(receiverAddress, (uint8_t *) &outgoingData, sizeof(outgoingData));
    lastState = currentButtonState;
    delay(50);
  }
}
