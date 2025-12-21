# Projects

Application: Formula Bharat | Embedded Vehicle Control Systems

As part of a performance-focused control system for a Formula Bharat prototype, I have developed a fully integrated Active Aero and Transmission Logic Unit, combining embedded programming, actuator interfacing, and pneumatic system control for high-speed, track-ready functionality.

System Overview:

Gear Shifting Subsystem
Features a non-blocking, staged logic sequence written in C++ for the Arduino platform. It controls 3/2 pneumatic solenoid valves that actuate the sequential transmission via high-speed pneumatic cylinders. Gear engagement and clutch timing are precisely orchestrated using millisecond-level delays, improving shift consistency and reducing mechanical wear.

Clutch Synchronization
A digital control signal activates a pneumatic clutch actuator with pre-shift and post-shift delays, coordinated via logic-controlled BJT switches. This ensures minimal drivetrain shock and smoother transitions under load.

Aero Deployment Subsystem
An active aerodynamic control module is mechanically linked to brake input using a long-arm microswitch positioned to trigger at approximately 20 percent brake application. Upon activation, it energizes dual aero actuators through high-current BJT switching circuits, lifting aerodynamic surfaces for increased downforce during deceleration or cornering.

Hardware Architecture
Designed for thermal and vibrational robustness, the system utilizes a custom PCB populated with 2N2222A BJTs for switching, flyback diodes for inductive load protection, and dedicated output channels for each actuator. All components are selected for automotive-grade reliability in high-vibration, high-heat environments.

This unit serves as an integrated logic controller that unifies both mechanical actuation and aerodynamic adaptation, enhancing both performance and safety under race conditions.
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/932fe8c8-c43c-4ddd-863e-b91db111d3b4" />

<img width="624" height="482" alt="image" src="https://github.com/user-attachments/assets/45739331-09eb-4843-91c9-278b09dea960" />

<img width="624" height="579" alt="image" src="https://github.com/user-attachments/assets/598fd4c7-40da-48ca-b43e-d0707315bd7e" />

<img width="720" height="1280" alt="image" src="https://github.com/user-attachments/assets/1ae43c8e-3e05-440c-8b8a-efc4d72de63d" />

<img width="400" height="300" alt="image" src="https://github.com/user-attachments/assets/510457c1-24bc-490d-a8cf-12902b9c9ee5" />
