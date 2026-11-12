# Project Report: ESP32 4WD Wi-Fi Controlled Car

**Student:** [Student Name]  
**Department:** [Department]  
**Institution:** [Institution]  
**Guide:** [Project Guide]  
**Academic year:** [Year]

## Abstract
This project develops a four-wheel-drive mobile car controlled wirelessly using an ESP32 development board. The ESP32 is configured as a local Wi-Fi access point and hosts a browser-based control page. A phone joins the ESP32 network and sends movement commands. The ESP32 translates these commands into logic signals for an L298N dual H-bridge motor driver, which controls left and right pairs of DC geared motors. The project combines embedded programming, Wi-Fi communication, motor-driver interfacing and basic robotics. During development, the ESP32 was connected to a Linux computer, firmware upload succeeded, and serial startup output was observed after reset. A phone-control sketch and GPIO mapping have been prepared. Final battery-powered driving tests remain pending because the battery-holder configuration, protection, motor current and driver thermal limits must be verified.

## 1. Introduction
A four-wheel mobile robot provides a practical platform for learning embedded systems and motion control. A wired controller restricts the operator's movement. This project uses the ESP32's built-in Wi-Fi to provide a local wireless control link from a phone browser. The system does not need a home router or internet connection when operating in access-point mode.

## 2. Problem Statement
A wired control arrangement makes a small mobile platform less convenient to operate and demonstrate. The project addresses this by providing direct phone-to-ESP32 wireless control through a locally hosted webpage.

## 3. Objectives
- Build a four-wheel mobile platform.
- Use ESP32 as the controller and Wi-Fi access point.
- Host a simple control webpage.
- Interface the ESP32 with an L298N motor driver.
- Provide forward, backward, left, right and stop commands.
- Verify the power arrangement and test safely before final demonstration.

## 4. Components
- 38-pin ESP32 DevKit-style board
- 4WD chassis and four TT-style DC geared motors
- L298N HW-095 dual H-bridge driver
- Breadboard and jumper wires
- USB data cable
- Three-cell 18650 holder and KC03 switch (final configuration not verified)
- Wi-Fi-enabled phone

## 5. System Architecture
Phone browser → ESP32 Wi-Fi access point/web server → GPIO control signals → L298N driver → left and right motor pairs.

The motor supply and ESP32 logic supply are separate. ESP32 GND and L298N GND must be connected to establish a common signal reference.

## 6. GPIO Connections
| L298N | ESP32 GPIO | Role |
|---|---:|---|
| ENA | 25 | Left channel enable |
| IN1 | 26 | Left direction |
| IN2 | 27 | Left direction |
| ENB | 14 | Right channel enable |
| IN3 | 32 | Right direction |
| IN4 | 33 | Right direction |

The two left motors are intended to be paired on one channel and the two right motors on the other. Confirm physical polarity so the two motors on each side propel in the same direction.

## 7. Software and Operation
The Arduino IDE is used to compile and upload the sketch. The ESP32 starts an access point:
- SSID: ESP32_CAR
- Password: car12345
- Address: http://192.168.4.1

The phone connects to this network and opens the address. The page provides Forward, Backward, Left, Right and Stop commands. The ESP32 updates the L298N input pins in response.

## 8. Development Progress
The ESP32 was connected to a Linux computer running Zorin OS. The serial port used during setup was /dev/ttyUSB0. Arduino IDE upload was successful during development. The Serial Monitor initially appeared blank; pressing RESET exposed the boot output. The L298N GPIO mapping and browser-control approach were then prepared.

## 9. Testing and Results
**Observed during development:** USB connection and serial communication; successful firmware upload; boot output after reset.  
**Prepared:** Wi-Fi access-point control sketch, browser interface and motor GPIO map.  
**Not confirmed:** final phone connection, physical motor movement under battery power, continuous operation, battery performance and driver temperature.

These distinctions are important: a prepared control sketch is not evidence that the final powered car has passed a movement test.

## 10. Challenges
- Diagnosing an initially blank Serial Monitor.
- Planning separate logic and motor power supplies.
- Identifying the battery holder configuration and switch terminals.
- Ensuring the driver can handle the combined current of two motors per channel.
- Ensuring paired motors rotate in the same physical direction.

## 11. Safety
Do not connect the unverified three-cell holder to the ESP32 or L298N based only on wire colour. Verify pack configuration, voltage, polarity, BMS rating and charger. Check motor rated voltage and stall current and the L298N's thermal/current limits. Identify the switch terminals from its datasheet or with a continuity meter. Use a regulated 5V USB supply for the ESP32, a suitable verified motor supply for the driver, and common ground. Raise the wheels during initial direction tests.

## 12. Limitations and Future Scope
Current scope is manual phone-browser control. Future improvements can include PWM speed control, ultrasonic/IR obstacle detection, line following, battery monitoring, a more efficient motor driver, telemetry and autonomous navigation.

## 13. Conclusion
The project brings together ESP32 programming, local Wi-Fi communication and H-bridge motor control on a 4WD platform. The controller setup, successful firmware upload and browser-control design represent the main development milestones. Safe completion requires verification of the battery, motor and driver ratings followed by documented movement tests.

## References
- Espressif Systems, ESP32 Series Datasheet and Technical Reference Manual.
- Arduino documentation for Arduino IDE and ESP32 board support.
- STMicroelectronics, L298 Dual Full-Bridge Driver Datasheet.
- Manufacturer documentation for the actual ESP32 board, motors, battery and switch.
