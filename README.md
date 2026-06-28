# Bluetooth-Controlled-Autonomous-Obstacle-Avoidance-Rover
This project presents the design and development of a smart robotic rover system based on the Arduino Uno microcontroller. The system is capable of both manual wireless control via Bluetooth and autonomous navigation with obstacle avoidance, making it a dual-mode intelligent robotic platform.

In manual mode, the robot is controlled using a smartphone application through the HC-05 Bluetooth module, which receives wireless commands and transmits them to the Arduino. Based on the received instructions, the Arduino processes the signals and drives the motors accordingly using an L298N motor driver circuit, enabling movement in all directions such as forward, backward, left, right, and stop.

In autonomous mode, the robot utilizes an ultrasonic sensor (HC-SR04) mounted on a servo motor to detect obstacles and measure distances in its environment. The servo allows the sensor to rotate and scan different directions, enabling the system to analyze available paths. When an obstacle is detected within a predefined range, the robot automatically stops, evaluates alternative directions, and selects the safest path to continue navigation.

The system is powered by a dual lithium-ion battery setup, ensuring sufficient energy supply for both logic and motor operations. The Arduino Uno acts as the central processing unit, coordinating communication between the Bluetooth module, sensors, and motor driver to achieve smooth and intelligent control.

Overall, this project demonstrates an efficient integration of embedded systems, wireless communication, sensor-based decision making, and robotic control, forming a foundational model for real-world applications such as autonomous vehicles, industrial automation, and smart mobility systems.
