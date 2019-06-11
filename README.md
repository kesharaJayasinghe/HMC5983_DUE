# HMC5983_DUE
Arduino library for HMC5983 Magnetometer.

This library can be used to obtain data from HMC5983 magnetometer with Arduino Due's second I2C / TWI interface (SDA1, SCL1).

# Note:
Arduino Due's SDA1 and SCL1 lines does not have internal pullup resistors. Therfore two pullup resistors must be added on SDA1 and SCL1 lines.
Some HMC5983 modules may already have pullup resistors added on these lines.
