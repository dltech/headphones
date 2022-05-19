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

/*  */
#define BATMON_CTL  MMIO32(AON_BATMON + 0x00)

/*  */
#define MEASCFG     MMIO32(AON_BATMON + 0x04)

/*  */
#define TEMPP0      MMIO32(AON_BATMON + 0x0c)

/*  */
#define TEMPP1      MMIO32(AON_BATMON + 0x10)

/*  */
#define TEMPP2      MMIO32(AON_BATMON + 0x14)

/*  */
#define BATMONP0    MMIO32(AON_BATMON + 0x18)

/*  */
#define BATMONP1    MMIO32(AON_BATMON + 0x1c)

/*  */
#define IOSTRP0     MMIO32(AON_BATMON + 0x20)

/*  */
#define FLASHPUMPP0 MMIO32(AON_BATMON + 0x24)

/*  */
#define BAT         MMIO32(AON_BATMON + 0x28)

/*  */
#define BATUPD      MMIO32(AON_BATMON + 0x2c)

/*  */
#define TEMP        MMIO32(AON_BATMON + 0x30)

/*  */
#define TEMPUPD     MMIO32(AON_BATMON + 0x34)

#endif
