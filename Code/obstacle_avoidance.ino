#include <Servo.h>

// Ultrasonic pins
#define trigPin A0
#define echoPin A1

// Motor pins (L298N / L293D Motor Shield)
#define ENA 5
#define IN1 6
#define IN2 7
#define ENB 9
#define IN3 8
#define IN4 11

Servo myservo;

long duration;
int distance;
int leftDistance;
int rightDistance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  myservo.attach(10);
  myservo.write(90); // center position

  Serial.begin(9600);
}

// distance measure function
int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

// move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

// stop robot
void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// turn right
void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(500);
}

// turn left
void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(500);
}

void loop() {

  distance = getDistance();

  if (distance > 25) {
    forward();
  } else {

    stopRobot();
    delay(300);

    // check right
    myservo.write(20);
    delay(500);
    rightDistance = getDistance();

    // check left
    myservo.write(160);
    delay(500);
    leftDistance = getDistance();

    // back to center
    myservo.write(90);
    delay(300);

    if (rightDistance > leftDistance) {
      turnRight();
    } else {
      turnLeft();
    }
  }
}
