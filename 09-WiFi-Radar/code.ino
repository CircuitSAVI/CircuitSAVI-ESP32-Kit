#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int SERVO_PIN = 19;
Servo radarServo;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  radarServo.attach(SERVO_PIN);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.println("WiFi Radar Ready");
  display.display();
  delay(1000);
}

void scanAndDisplay(int angle) {
  radarServo.write(angle);
  delay(200);

  int n = WiFi.scanNetworks();

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Angle: ");
  display.print(angle);
  display.println(" deg");

  display.print("Networks Found: ");
  display.println(n);
  display.println("---------------------");

  if (n > 0) {
    for (int i = 0; i < min(n, 3); ++i) {
      display.print(i + 1);
      display.print(": ");
      display.print(WiFi.SSID(i).substring(0, 10));
      display.print(" (");
      display.print(WiFi.RSSI(i));
      display.println(")");
    }
  } else {
    display.println("No networks found");
  }

  display.display();

  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print(" | Networks Found: ");
  Serial.println(n);
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 30) {
    scanAndDisplay(angle);
  }

  for (int angle = 180; angle >= 0; angle -= 30) {
    scanAndDisplay(angle);
  }
}
