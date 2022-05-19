#ifndef H_TRNG_REGS
#define H_TRNG_REGS
/*
 * Simple CC2640 headphones
 * Random Number Generator registers
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
#define OUT0        MMIO32(TRNG + 0x0000)

/*  */
#define OUT1        MMIO32(TRNG + 0x0004)

/*  */
#define IRQFLAGSTAT MMIO32(TRNG + 0x0008)

/*  */
#define IRQFLAGMASK MMIO32(TRNG + 0x000c)

/*  */
#define IRQFLAGCLR  MMIO32(TRNG + 0x0010)

/*  */
#define TRNG_CTL    MMIO32(TRNG + 0x0014)

/*  */
#define TRNG_CFG0   MMIO32(TRNG + 0x0018)

/*  */
#define ALARMCNT    MMIO32(TRNG + 0x001c)

/*  */
#define FROEN       MMIO32(TRNG + 0x0020)

/*  */
#define FRODETUNE   MMIO32(TRNG + 0x0024)

/*  */
#define ALARMMASK   MMIO32(TRNG + 0x0028)

/*  */
#define ALARMSTOP   MMIO32(TRNG + 0x002c)

/*  */
#define LFSR0       MMIO32(TRNG + 0x0030)

/*  */
#define LFSR1       MMIO32(TRNG + 0x0034)

/*  */
#define LFSR2       MMIO32(TRNG + 0x0038)

/*  */
#define HWOPT       MMIO32(TRNG + 0x0078)

/*  */
#define HWVER0      MMIO32(TRNG + 0x007c)

/*  */
#define IRQSTATMASK MMIO32(TRNG + 0x1fd8)

/*  */
#define HWVER1      MMIO32(TRNG + 0x1fe0)

/*  */
#define IRQSET      MMIO32(TRNG + 0x1fec)

/*  */
#define SWRESET     MMIO32(TRNG + 0x1ff0)

/*  */
#define IRQSTAT     MMIO32(TRNG + 0x1ff8)


#endif
