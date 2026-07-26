#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>

#define SS_PIN 5
#define RST_PIN 22
#define SERVO_PIN 13
#define BUZZER_PIN 12

MFRC522 rfid(SS_PIN, RST_PIN);
Servo lockServo;

// Authorized UID bytes (Replace with your tag's UID)
byte authorizedUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();

  lockServo.attach(SERVO_PIN);
  lockServo.write(0); // Locked position

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Smart Door Lock System Ready.");
  Serial.println("Scan RFID Tag/Card...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("Card UID:");
  bool accessGranted = true;

  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);

    if (rfid.uid.uidByte[i] != authorizedUID[i]) {
      accessGranted = false;
    }
  }
  Serial.println();

  if (accessGranted) {
    Serial.println("Access Granted! Unlocking door...");
    tone(BUZZER_PIN, 2000, 200);
    lockServo.write(90); // Unlock position
    delay(5000);         // Keep open for 5 seconds

    Serial.println("Locking door...");
    lockServo.write(0);  // Lock position
  } else {
    Serial.println("Access Denied!");
    for (int i = 0; i < 3; i++) {
      tone(BUZZER_PIN, 1000, 100);
      delay(150);
    }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
