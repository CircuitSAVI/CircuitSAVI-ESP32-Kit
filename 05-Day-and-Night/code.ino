const int LDR_PIN = 34;
const int LED_PIN = 2;
const int THRESHOLD = 1500;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Status: Night Detected - LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Status: Day Detected - LED OFF");
  }

  delay(500);
}
