# HMC5983_DUE
## Arduino library for HMC5983 Magnetometer.

Library for obtaining data from HMC5983 magnetometer sensor. with Arduino Due's second I2C / TWI interface (SDA1, SCL1).

Sensor: Honeywell HMC5983 

Tested Microcontroller: Atmel SAM3X8E [Arduino Due]

## Note:
Arduino Due's SDA1 and SCL1 lines does not have internal pullup resistors. Therfore two pullup resistors must be added on SDA1 and SCL1 lines.
