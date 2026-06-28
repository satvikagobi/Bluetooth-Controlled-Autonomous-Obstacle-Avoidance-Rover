# Bluetooth-Controlled-Autonomous-Obstacle-Avoidance-Rover
This project is a Bluetooth-controlled and autonomous smart robot car developed using Arduino Uno. The robot can be operated manually using a mobile phone through the HC-05 Bluetooth module, where directional commands are sent to control its movement. It can move forward, backward, left, right, and stop based on user input.

In addition to manual control, the robot also has an obstacle avoidance mode. In this mode, an ultrasonic sensor is used to detect obstacles in front of the robot, and a servo motor rotates the sensor to scan left and right directions. Based on the distance measured, the Arduino decides the safest path and controls the L298N motor driver to navigate accordingly.

The system uses a dual-mode operation, allowing switching between manual and autonomous control. This makes the robot useful for understanding basic concepts of embedded systems, wireless communication, sensor integration, and robotics control systems.
