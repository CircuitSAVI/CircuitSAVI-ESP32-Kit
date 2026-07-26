#include <ESP32Servo.h>

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;
const int SERVO_PIN = 19;

Servo radarServo;

long readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  radarServo.attach(SERVO_PIN);
}

void loop() {
  for (int angle = 15; angle <= 165; angle += 2) {
    radarServo.write(angle);
    delay(30);
    long distance = readDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
  
  for (int angle = 165; angle >= 15; angle -= 2) {
    radarServo.write(angle);
    delay(30);
    long distance = readDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
}
