Arduino Robot with Ultrasonic Sensors
This Arduino project is a simple robot that uses ultrasonic sensors to navigate and avoid obstacles. The robot is controlled by an L298N motor driver, and three ultrasonic sensors are used to detect objects in front, left, and right directions.

Hardware Requirements
Arduino board
L298N motor driver
Ultrasonic sensors (3)
DC motors with wheels
Chassis for the robot
Power supply for the motors
Software Requirements
Arduino IDE
NewPing Library
Wiring
Connect the ultrasonic sensors to the trig and echo pins on the Arduino.
Connect the L298N motor driver to control the DC motors for movement.
Code Explanation
The NewPing library is used for interfacing with the ultrasonic sensors.
Motor control pins are defined for the L298N driver.
The SonarSensor function calculates the distance using the ultrasonic sensor.
The moveStop, moveForward, moveBackward, turnRight, and turnLeft functions control the movement of the robot.
In the loop function, the sensors are used to detect obstacles, and the robot takes appropriate actions to avoid collisions.
Usage
Install the NewPing library in your Arduino IDE.
Upload the provided code to your Arduino board.
Power up the robot and observe its behavior as it navigates and avoids obstacles.
Notes
Ensure that the ultrasonic sensors are correctly connected to the Arduino.
Adjust the distance thresholds in the code based on your robot's specifications and environment.
