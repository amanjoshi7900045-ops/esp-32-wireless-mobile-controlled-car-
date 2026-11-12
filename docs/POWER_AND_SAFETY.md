# Power Supply and Electrical Safety

The project uses separate logic and motor power domains.

## ESP32 logic supply
A regulated 5V USB power bank or USB adapter can power the ESP32 through its USB connector. This is a convenient independent supply during motor testing.

## Motor supply
The four DC motors draw substantially more current at startup and when stalled than while free-running. Select a motor supply only after checking:
- Motor rated voltage
- Motor stall current (per motor)
- Combined current for the two motors on each L298N channel
- L298N current and thermal limits
- Battery pack continuous discharge rating and BMS rating

## Existing 3-cell holder
The build history mentions a holder for three 18650 cells. Its internal configuration and protection were not confirmed. Do not assume it is a 3S pack or connect it based on wire colour alone. If a genuine 3S pack is confirmed, its nominal voltage is 11.1V and full-charge voltage is 12.6V, but this must be confirmed from pack documentation or measurement before use.

Use a charger specifically matched to the verified pack configuration and chemistry. Use a suitable BMS/protection circuit. Never short lithium-ion cells.

## Switch
The KC03 switch is marked with AC ratings and has three terminals. Those markings do not identify which terminal is common, normally open or normally closed, and do not prove its DC suitability. Identify the exact switch model and terminal arrangement from its datasheet or have a competent person check continuity with a meter. Do not guess terminal function from shape or colour.

## Safe test sequence
1. Disconnect battery power while wiring.
2. Verify the battery pack, voltage, polarity, BMS and charger.
3. Verify motor and driver ratings.
4. Connect common ground between ESP32 and L298N.
5. Power ESP32 by regulated USB and motor driver from the verified motor supply.
6. Raise the wheels off the floor.
7. Test STOP, then each direction briefly.
8. Stop immediately if wiring, battery or driver heats abnormally.
