// Motor Driver Pins (L298N / L293D)
const int ENA = 14;
const int IN1 = 27;
const int IN2 = 26;
const int IN3 = 25;
const int IN4 = 33;
const int ENB = 12;

// IR Sensor Pins
const int LEFT_IR = 34;
const int RIGHT_IR = 35;

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void loop() {
  int leftState = digitalRead(LEFT_IR);
  int rightState = digitalRead(RIGHT_IR);

  if (leftState == LOW && rightState == LOW) {
    moveForward();
  } else if (leftState == HIGH && rightState == LOW) {
    turnLeft();
  } else if (leftState == LOW && rightState == HIGH) {
    turnRight();
  } else {
    stopCar();
  }
}
