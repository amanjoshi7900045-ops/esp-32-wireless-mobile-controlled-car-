# ESP32 4WD Wi-Fi Controlled Car

A four-wheel-drive mobile robot controlled from a phone browser through a local Wi-Fi network created by an ESP32.

## Project status
This repository documents the prototype and the progress reported during development. The ESP32 was connected to a Linux computer, Arduino IDE upload was successful, and serial startup output was observed after pressing RESET. The browser-control firmware and GPIO pin map are included. **Final battery-powered motor testing is not yet verified**; do not treat it as completed.

## Features
- ESP32 runs as a Wi-Fi access point (no router or internet required).
- Phone connects to the ESP32 network and opens a local web page.
- Browser controls: Forward, Backward, Left, Right and Stop.
- L298N dual H-bridge drives left and right motor pairs.

## Hardware
- 38-pin ESP32 DevKit-style development board
- 4WD chassis with four TT-style DC geared motors
- L298N (HW-095) dual H-bridge module
- Jumper wires / breadboard
- USB data cable
- Battery holder and switch (final battery wiring and ratings still need verification)
- Phone with Wi-Fi and a browser

## GPIO mapping
| L298N | ESP32 |
|---|---:|
| ENA | GPIO 25 |
| IN1 | GPIO 26 |
| IN2 | GPIO 27 |
| ENB | GPIO 14 |
| IN3 | GPIO 32 |
| IN4 | GPIO 33 |

Motor arrangement: left-side motors are paired on one channel; right-side motors on the other. Confirm the physical polarity of both motors in each pair so they propel in the same direction.

## Upload and use
1. Open `firmware/esp32_4wd_wifi_car.ino` in Arduino IDE.
2. Install/select the ESP32 Arduino board support and select the correct ESP32 board and serial port.
3. Upload the sketch using a USB data cable.
4. Connect the phone to Wi-Fi **ESP32_CAR** (password **car12345**).
5. Open **http://192.168.4.1** in the phone browser.
6. Test commands with the wheels raised clear of the floor before any ground test.

If the firmware has been changed, the actual SSID/password/IP are determined by the values in the uploaded sketch.

## Power and safety — read before connecting a battery
- Power the ESP32 separately from a regulated 5V USB source (power bank/USB adapter is suitable).
- Power the motors through the L298N motor-supply input using a correctly rated, verified motor supply.
- Connect ESP32 GND to L298N GND so the control signals share a reference.
- Do not connect an unverified lithium battery holder directly to ESP32 3V3, VIN or USB.
- The existing holder has three 18650 positions, but its internal series/parallel configuration and protection were not confirmed. Do not assume its voltage.
- Verify battery polarity, pack voltage, BMS current rating and matching charger before use. Have the pack and three-terminal switch wiring checked with appropriate test equipment.
- Check the four motors' rated voltage and stall current. Two motors per L298N channel may exceed the driver's practical current/thermal capability. Stop if the driver or wiring heats excessively.

## Repository structure
- `firmware/` — ESP32 Arduino sketch
- `docs/` — wiring, parts, progress, safety, report and presentation source documents

## Documentation
- [Development progress](docs/DEVELOPMENT_PROGRESS.md)
- [Wiring guide](docs/WIRING_AND_PINMAP.md)
- [Power and safety](docs/POWER_AND_SAFETY.md)
- [Project report (Markdown)](docs/PROJECT_REPORT.md)
- [Presentation outline (Markdown)](docs/PRESENTATION_OUTLINE.md)

## Current known limitations
- Battery pack configuration and final motor power wiring are unverified.
- Four-motor load/current and L298N thermal performance are unverified.
- Actual movement tests using the final battery setup have not been confirmed.
- Speed control, sensors and autonomous navigation are future enhancements.
