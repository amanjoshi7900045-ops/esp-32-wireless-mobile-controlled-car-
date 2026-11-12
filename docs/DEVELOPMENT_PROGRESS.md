# Development Progress Log

This document records only progress shared during the project conversation. It does not imply that pending tests have passed.

## Project hardware
- Classic ESP32 38-pin DevKit-style board (not the alternate USB-C board that was considered).
- Four-wheel chassis with four yellow TT-style geared motors.
- L298N HW-095 dual H-bridge motor driver.
- Breadboard and jumper wires.
- Battery holder for three 18650 cells and a KC03 three-terminal switch were discussed.

## Computer and firmware setup
- Development computer runs Zorin OS/Linux.
- ESP32 serial port was identified as /dev/ttyUSB0.
- Arduino IDE was installed and configured.
- The ESP32 was connected using a USB data cable.
- An upload completed successfully during development.
- Serial Monitor initially appeared blank; pressing RESET caused startup/boot output to appear.

## Motor control design
Recorded GPIO mapping:
- ENA: GPIO25
- IN1: GPIO26
- IN2: GPIO27
- ENB: GPIO14
- IN3: GPIO32
- IN4: GPIO33

Intended motor grouping:
- Left two motors on one L298N channel.
- Right two motors on the other L298N channel.

## Phone control interface
A browser-based control approach was prepared:
- Access point SSID: ESP32_CAR
- Password: car12345
- Local address: http://192.168.4.1
- Commands: Forward, Backward, Left, Right, Stop

The repository sketch implements this interface. Re-upload and live verification should be performed against the physical wiring before claiming a successful drive test.

## Pending / unverified
- Exact internal series/parallel configuration of the three-cell holder.
- Battery pack voltage, polarity, BMS and continuous current rating.
- Correct terminal identification and DC suitability of the three-terminal switch.
- Motor rated voltage and stall current.
- L298N current/thermal suitability for two motors per channel.
- Final battery-powered motor movement and sustained operation.

## Next recommended steps
1. Confirm the exact battery pack specification and switch terminal arrangement.
2. Confirm motor rated voltage and stall current.
3. Confirm the L298N can safely drive the paired motors; upgrade the driver if required.
4. Test each motor individually at a safe, regulated voltage.
5. Test movement with wheels raised, then a short ground test.
6. Record actual observations, photos and test duration.
