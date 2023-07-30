#include <NewPing.h>  //Ultrasonic sensor function library. You must install this library

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

//sensor pins f
#define trigPin1 8
#define echoPin1 9
#define trigPin2 10
#define echoPin2 11
#define trigPin3 12
#define echoPin3 13

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup() {
  Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  delay(2000);
}

void loop() {
 SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
SonarSensor(trigPin3, echoPin3);
FrontSensor = distance;

Serial.print(LeftSensor);
Serial.print(" - ");
Serial.print(FrontSensor);
Serial.print(" - ");
Serial.println(RightSensor);


if (FrontSensor <= 20) {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);

    if (RightSensor>= LeftSensor) {
      turnRight();
      moveStop();
    } else {
      turnLeft();
      moveStop();
    }
  } else {
    moveForward();
  }
  
}



void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = ((duration/2) / 29.1);

}

void moveStop() {

  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}
void moveForward() 
{
  //goesForward = true;
  //if (!goesForward) 
  {

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
}

void moveBackward() 
{
  //goesForward = false;
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight() {

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

  delay(500);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void turnLeft() {

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}



