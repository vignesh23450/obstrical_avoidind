#include <VarSpeedServo.h>
VarSpeedServo myservo1;
VarSpeedServo myservo2;
const int servoPin1 = 9; // the digital pin used for the first servo
const int servoPin2 = 10; // the digital pin used for the second servo
const int inputPin = 2;

int ledPin = 13;  // LED connected to digital pin 13

void setup() {
   Serial.begin(9600);
   pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo1.write(0,255,false); // set the intial position of the servo, as fast as possible, run in background
  myservo2.attach(servoPin2);  // attaches the servo on pin 9 to the servo object
  myservo2.write(0,255,true);  // set the intial position of the servo, as fast as possible, wait until done
  delay(15); // Delay to allow the servo to reach the desired position

}

void loop() {
  int state = digitalRead(inputPin);
  Serial.println(state);
  delay(100);
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      myservo1.write(180,200,true); // set the intial position of the servo, as fast as possible, run in background
      delay(500);
       myservo2.write(90,255,true);  // set the intial position of the servo, as fast as possible, wait until done
      delay(15); // Delay to allow the servo to reach the desired position
  
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);
      
       myservo2.write(0,255,true);  // set the intial position of the servo, as fast as possible, run in background
      delay(15); // Delay to allow the servo to reach the desired position
  
    } else if (command == '2') {
      digitalWrite(ledPin, LOW);
      myservo1.write(0,200,true); // set the intial position of the servo, as fast as possible, wait until done
       myservo2.write(90,255,false);  // set the intial position of the servo, as fast as possible, run in background
      delay(15); // Delay to allow the servo to reach the desired position
  
    }
  }
}