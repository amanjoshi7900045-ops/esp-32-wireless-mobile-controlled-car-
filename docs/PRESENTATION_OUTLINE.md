# ESP32 4WD Wi-Fi Controlled Car — Presentation Outline

## Slide 1 — Title
ESP32 4WD Wi-Fi Controlled Car  
Design, Development and Prototype Progress

## Slide 2 — Project Overview
A four-wheel-drive mobile robot controlled from a phone browser through a local Wi-Fi network created by the ESP32. No external router or internet is required for the direct access-point control link.

## Slide 3 — Problem Statement and Objectives
A wired controller restricts operator movement. Objectives: build a 4WD platform, use ESP32 Wi-Fi access-point mode, provide browser controls, interface an L298N driver and verify the power system safely.

## Slide 4 — Components
38-pin ESP32 DevKit-style board; 4WD chassis with four TT motors; L298N HW-095; jumper wires/breadboard; USB cable; phone; battery holder and switch (configuration not yet verified).

## Slide 5 — System Architecture
Phone browser → ESP32 Wi-Fi AP/web server → GPIO signals → L298N → left and right motor pairs. Logic and motor power are separate; grounds share a common reference.

## Slide 6 — GPIO Mapping
ENA–GPIO25; IN1–GPIO26; IN2–GPIO27; ENB–GPIO14; IN3–GPIO32; IN4–GPIO33. Left motor pair on one channel; right motor pair on the other.

## Slide 7 — Software and Wi-Fi
Arduino IDE; ESP32 access point; SSID ESP32_CAR; password car12345; local URL http://192.168.4.1. Browser commands: Forward, Backward, Left, Right and Stop.

## Slide 8 — Working Principle
Phone sends a browser request; ESP32 interprets the command; GPIO signals control the L298N; the driver changes motor direction; the paired wheels move the chassis.

## Slide 9 — Development Progress
ESP32 connected to Zorin OS/Linux; /dev/ttyUSB0 used during setup; Arduino upload succeeded; Serial Monitor boot output observed after RESET; GPIO and web-control sketch prepared.

## Slide 10 — Challenges
Serial monitor troubleshooting; battery configuration uncertainty; switch terminal identification; high startup/stall current; L298N thermal/current limits; paired motor polarity.

## Slide 11 — Safety and Future Scope
Verify pack voltage, polarity, BMS and charger; verify motor ratings and driver limits; use separate regulated logic/motor supplies and common ground. Future: PWM speed, sensors, obstacle avoidance, line following and telemetry.

## Slide 12 — Conclusion
The prototype demonstrates the integration of embedded programming, Wi-Fi control and motor-driver interfacing. Final battery-powered driving results must be recorded after electrical verification and safe movement testing.
