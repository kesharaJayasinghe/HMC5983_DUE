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

void HMC5983_due::read(){
	Wire1.beginTransmission((byte)HMC5983_ADDRESS_MAG);
	Wire1.write(HMC5983_REGISTER_MAG_OUT_X_H_M);
	Wire1.endTransmission();
	Wire1.requestFrom((byte)HMC5983_ADDRESS_MAG, (byte)6);

	while(Wire1.available() < 6);

	uint8_t xhi = Wire1.read();
	uint8_t xlo = Wire1.read();
	uint8_t zhi = Wire1.read();
	uint8_t zlo = Wire1.read();
	uint8_t yhi = Wire1.read();
	uint8_t ylo = Wire1.read();

	_magData.x = (int16_t)(xlo | ((int16_t)xhi << 8));
	_magData.y = (int16_t)(ylo | ((int16_t)yhi << 8));
	_magData.z = (int16_t)(zlo | ((int16_t)zhi << 8));

	_magData.orienation = 0.0;
}

bool HMC5983_due::begin(){
	Wire1.begin();
	write1(HMC5983_ADDRESS_MAG, HMC5983_REGISTER_MAG_MR_REG_M, 0x00);
	setMagGain(HMC5983_MAGGAIN_1_3);
	return true;
}

void HMC5983_due::setMagGain(hmc5983MagGain gain){
	write1(HMC5983_ADDRESS_MAG, HMC5983_REGISTER_MAG_CRB_REG_M, (byte)gain);
	_magGain = gain;

	switch(gain){
		case HMC5983_MAGGAIN_1_3:
			_hmc5983_Gauss_LSB_XY = 1100;
			_hmc5983_Gauss_LSB_Z  = 980;
			break;
		case HMC5983_MAGGAIN_1_9:
			_hmc5983_Gauss_LSB_XY = 855;
			_hmc5983_Gauss_LSB_Z  = 760;
			break;
		case HMC5983_MAGGAIN_2_5:
			_hmc5983_Gauss_LSB_XY = 670;
			_hmc5983_Gauss_LSB_Z  = 600;
			break;
		case HMC5983_MAGGAIN_4_0:
			_hmc5983_Gauss_LSB_XY = 450;
			_hmc5983_Gauss_LSB_Z  = 400;
			break;
		case HMC5983_MAGGAIN_4_7:
			_hmc5983_Gauss_LSB_XY = 400;
			_hmc5983_Gauss_LSB_Z  = 255;
			break;
		case HMC5983_MAGGAIN_5_6:
			_hmc5983_Gauss_LSB_XY = 330;
			_hmc5983_Gauss_LSB_Z  = 295;
			break;
		case HMC5983_MAGGAIN_8_1:
			_hmc5983_Gauss_LSB_XY = 230;
			_hmc5983_Gauss_LSB_Z  = 205;
			break;						

	}
}

bool HMC5983_due::getEvent(sensors_event_t *event){
	memset(event, 0, sizeof(sensors_event_t));
	read();

	event->magnetic.x = _magData.x / _hmc5983_Gauss_LSB_XY * SENSORS_GAUSS_TO_MICROTESLA;
	event->magnetic.y = _magData.y / _hmc5983_Gauss_LSB_XY * SENSORS_GAUSS_TO_MICROTESLA;
	event->magnetic.z = _magData.z / _hmc5983_Gauss_LSB_Z * SENSORS_GAUSS_TO_MICROTESLA;

	return true;
}
