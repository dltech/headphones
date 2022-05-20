#ifndef H_BATMON_REGS
#define H_BATMON_REGS
/*
 * Simple CC2640 headphones
 * Battery Monitor and Temperature Sensor registers
 *
 * Copyright 2022 Mikhail Belkin <dltech174@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "memorymap.h"

/* CTL Register */
#define BATMON_CTL  MMIO32(AON_BATMON + 0x00)
//...
#define CALC_EN 0x2
//...
#define MEAS_EN 0x1

/* MEASCFG Register */
#define MEASCFG     MMIO32(AON_BATMON + 0x04)
// PER

/* TEMPP0 Register */
#define TEMPP0      MMIO32(AON_BATMON + 0x0c)
// CFG

/* TEMPP1 Register */
#define TEMPP1      MMIO32(AON_BATMON + 0x10)
// CFG

/* TEMPP2 Register */
#define TEMPP2      MMIO32(AON_BATMON + 0x14)
// CFG

/* BATMONP0 Register */
#define BATMONP0    MMIO32(AON_BATMON + 0x18)
// CFG

/* BATMONP1 Register */
#define BATMONP1    MMIO32(AON_BATMON + 0x1c)
// CFG

/* IOSTRP0 Register */
#define IOSTRP0     MMIO32(AON_BATMON + 0x20)
//...
#define CFG2_SFT    4
#define CFG2_MSK    0x3
//...
#define CFG1_SFT    0
#define CFG1_MSK    0xf

/* FLASHPUMPP0 Register */
#define FLASHPUMPP0 MMIO32(AON_BATMON + 0x24)
//...
#define FALLB               0x100
//...
#define HIGHLIM_SFT         6
#define HIGHLIM_MSK         0x3
//...
#define LOWLIM              0x020
//...
#define OVR                 0x010
//...
#define FLASHPUMP_CFG_SFT   0
#define FLASHPUMP_CFG_MSK   0xf


/* Last Measured Battery Voltage */
#define BAT         MMIO32(AON_BATMON + 0x28)
// voltage formula, volts * by 1000
#define BAT_VOLTAGE     ((BAT>>8)+((BAT&0xff)*4))

/* Battery Update. Indicates BAT Updates */
#define BATUPD      MMIO32(AON_BATMON + 0x2c)
// 1: New battery voltage is present.
#define BAT_STAT    0x1

/* Temperature. Last Measured Temperature in Degrees Celsius */
#define TEMP        MMIO32(AON_BATMON + 0x30)
// Integer part (signed) of temperature value.
#define TEMP_SFT    8
#define TEMP_MSK    0x1ff

/* Temperature Update. Indicates TEMP Updates */
#define TEMPUPD     MMIO32(AON_BATMON + 0x34)
// 1: New temperature is present.
#define TEMP_STAT    0x1

#endif
