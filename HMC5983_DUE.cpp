#include "Arduino.h"
#include <Wire.h>
#include <limits.h>
#include "HMC5983.h"

static double _hmc5983_Gauss_LSB_XY = 1100.0;
static double _hmc5983_gauss_LSB_z = 980.0;

void HMC5983_due::write1(byte address, byte reg, byte value){
    Wire1.beginTransmission(address);
    Wire1.write((uint8_t)reg);
    Wire1.write((uint8_t)value);
    Wire1.endTransmission();
}

void HMC5983_due::read1(byte address, byte reg){
	byte value;
	Wire1.beginTransmission(address);
	Wire1.write((uint8_t)reg);
	Wire1.endTransmission();
	Wire1.requestFrom(address, (byte)1);
	value = Wire1.read();
	Wire1.endTransmission();
	return value;
}
