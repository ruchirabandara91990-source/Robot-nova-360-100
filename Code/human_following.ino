/* 
arduino code file
Object Tracking | Human Following Robot | Arduino | how to make 
made by Robotechnica youtube channel
29/06/2021
*/

const int trigPin = 7;
const int echoPin = 6;
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;


void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  Serial.begin(9600);
}
long duration, distance;

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;

  Serial.println(distance);

  if (20 <= distance  &&  distance <= 30)
  {
    digitalWrite(in1, HIGH); // forward
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }

  if (distance < 20) {
    digitalWrite(in1, LOW);  // backward
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    }

  if (30 < distance ) {
    digitalWrite(in1, LOW);  // stop
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(50);
    }
}
