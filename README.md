Project Name: Arduino Gesture Controlled Unity Racer (or similar descriptive name)
Sub Heading: Integrating an Arduino Distance Sensor for Hand Gesture Lane Changes in a 3D Racing Game
## Tech Stack:
Engine: Unity
Language: C# (for Unity scripting)
Hardware: Arduino (C/C++ for Arduino sketch), Distance Sensor (Likely HC-SR04 Ultrasonic Sensor or similar IR distance sensor, based on description)
Communication: Serial Communication (between Arduino and Unity)
## Project Overview:
Idea & USP: To create a more immersive or alternative control scheme for a simple Unity racing game by integrating physical hand gestures detected by an Arduino sensor. The unique selling proposition was using a readily available distance sensor to interpret hand swipes (left/right) as commands to switch lanes, moving beyond traditional keyboard input.
Summary: This project involved a 3D, three-lane car racing game built in Unity. Players controlled a car that needed to switch between lanes. Two control methods were implemented: standard arrow key input and a novel system using an Arduino connected to a distance sensor. By waving their hand left or right in front of the sensor, the player could trigger a corresponding lane change in the Unity game. The system detected the swipe by measuring sudden changes in the distance between the hand and the sensor.
Result/Status: A functional prototype developed approximately 5 years ago, demonstrating both keyboard control and the Arduino-based gesture control for lane switching within the Unity game. Served as an early exploration of hardware-software integration for game control.
## Key Features:
3D Lane-Based Racing Gameplay: Simple core game mechanic involving a car moving forward and switching between three distinct lanes.
Dual Control Schemes: Offered flexibility by allowing lane changes via both standard keyboard arrow keys and the custom Arduino gesture system.
Arduino Distance Sensor Input: Utilized an Arduino microcontroller to read real-time distance data from a sensor measuring proximity in front of it.
Hand Gesture Recognition: Implemented custom logic (likely on Arduino or processed in Unity) to interpret a rapid change in distance readings as a directional swipe (left or right).
Unity-Arduino Integration: Established real-time serial communication between the Arduino (sending sensor data or interpreted swipe events) and the Unity game (receiving the data and triggering the car's lane change).
## Challenges and Solutions:
Challenge 1: Establishing reliable real-time communication and integration between the Arduino microcontroller and the Unity game engine, which was perceived as lacking straightforward, well-documented methods at the time (~5 years ago).
Solution: Implemented serial communication. This involved writing an Arduino sketch to continuously read the distance sensor and send processed data (either raw distance, changes in distance, or interpreted "swipe left"/"swipe right" commands) over the USB serial port. On the Unity side, a C# script used the System.IO.Ports.SerialPort class to connect to the correct COM port, read the incoming serial data stream asynchronously, parse the data, and translate it into game actions (triggering the car's lane change function).
Challenge 2: Developing robust gesture detection logic to reliably distinguish intentional hand swipes from noise or other movements based on distance sensor readings.
Solution: The logic focused on detecting a sudden change in the measured distance rather than absolute distance values. A threshold was likely set for the magnitude and speed of this change to register the start of a potential swipe. The direction could be inferred based on whether the distance rapidly decreased then increased (swipe across) or based on which side of a central point the change occurred if multiple sensors were hypothetically used (though description implies one). The gesture was likely registered as complete when the distance reading stabilized or returned beyond a certain threshold after the initial rapid change. Tuning sensitivity thresholds and timing parameters through trial and error was crucial.
## Timeline:
Estimated development duration: 3 weeks 
## What I Learned:
Unity-Arduino Serial Communication: Implementing bidirectional data transfer between a physical computing platform (Arduino) and a game engine (Unity) via serial ports.
Hardware Interfacing: Connecting external sensors (distance sensor) to an Arduino microcontroller and writing code to read sensor values accurately.
Real-Time Input Processing: Handling potentially noisy, continuous data streams from physical hardware within a software application.
Custom Gesture Recognition: Designing and implementing algorithms to interpret raw sensor data (distance changes) into meaningful, discrete game commands (directional swipes).
Debugging Hardware/Software Systems: Troubleshooting issues that could originate in the physical wiring, Arduino code, serial communication protocol, or Unity C# script.
Basic 3D Game Logic: Implementing fundamental gameplay mechanics like player movement and lane switching within the Unity environment.
Exploring Alternative Input Methods: Gaining experience in creating and evaluating non-traditional control schemes for interactive applications.
