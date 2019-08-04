#ifndef __HMC5983_H__
#define __HMC5983_H__

#include "Arduino.h"
#include <Wire.h>

#define HMC5983_ADDRESS_MAG  0x1E

typedef enum{
    HMC5983_REGISTER_MAG_CRA_REG_M             = 0x00,
    HMC5983_REGISTER_MAG_MR_REG_M              = 0x02,
    HMC5983_REGISTER_MAG_OUT_X_H_M             = 0x03,
    HMC5983_REGISTER_MAG_OUT_X_L_M             = 0x04,
    HMC5983_REGISTER_MAG_OUT_Z_H_M             = 0x05,
    HMC5983_REGISTER_MAG_OUT_Z_L_M             = 0x06,
    HMC5983_REGISTER_MAG_OUT_Y_H_M             = 0x07,
    HMC5983_REGISTER_MAG_OUT_Y_L_M             = 0x08,
    HMC5983_REGISTER_MAG_SR_REG_Mg             = 0x09,
    HMC5983_REGISTER_MAG_IRA_REG_M             = 0x0A,
    HMC5983_REGISTER_MAG_IRB_REG_M             = 0x0B,
    HMC5983_REGISTER_MAG_IRC_REG_M             = 0x0C,
    HMC5983_REGISTER_MAG_TEMP_OUT_H_M          = 0x31,
    HMC5983_REGISTER_MAG_TEMP_OUT_L_M          = 0x32
} hmc5983MagRegisters_t;

typedef enum{
    HMC5983_MAGGAIN_1_3                        = 0x20,  // +/- 1.3
    HMC5983_MAGGAIN_1_9                        = 0x40,  // +/- 1.9
    HMC5983_MAGGAIN_2_5                        = 0x60,  // +/- 2.5
    HMC5983_MAGGAIN_4_0                        = 0x80,  // +/- 4.0
    HMC5983_MAGGAIN_4_7                        = 0xA0,  // +/- 4.7
    HMC5983_MAGGAIN_5_6                        = 0xC0,  // +/- 5.6
    HMC5983_MAGGAIN_8_1                        = 0xE0   // +/- 8.1
} hmc5983MagGain;
