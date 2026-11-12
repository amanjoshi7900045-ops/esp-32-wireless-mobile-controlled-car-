# Wiring and GPIO Pin Map

## Control signals

| L298N terminal | ESP32 GPIO | Function |
|---|---:|---|
| ENA | 25 | Left channel enable |
| IN1 | 26 | Left channel direction |
| IN2 | 27 | Left channel direction |
| ENB | 14 | Right channel enable |
| IN3 | 32 | Right channel direction |
| IN4 | 33 | Right channel direction |

These pins must match the uploaded firmware. If the L298N has ENA/ENB jumpers fitted, note that the sketch actively drives those enable pins; remove or retain jumpers only in accordance with the module's design and the actual wiring.

## Motor outputs
- Pair the two left-side motors to OUT1 and OUT2.
- Pair the two right-side motors to OUT3 and OUT4.
- Check polarity so both motors on one side propel the chassis in the same direction.
- The L298N is a dual-channel driver. Verify its practical current and thermal limits against the combined current of the two motors on each channel.

## Ground and power
- ESP32 GND must connect to L298N GND.
- ESP32 may be powered from a regulated 5V USB power bank/adapter.
- Motor supply goes to the L298N motor supply input only after its voltage and polarity are verified.
- Do not connect an unverified battery pack to ESP32 pins.
- Do not connect L298N 5V output to ESP32 VIN/5V while the ESP32 is being powered from USB unless the board/driver power arrangement has been specifically checked to avoid back-feeding.

## Important
This is a signal map, not a substitute for identifying the exact terminals on the physical module. Disconnect all batteries while wiring. Confirm the L298N terminal labels from the board silkscreen.
