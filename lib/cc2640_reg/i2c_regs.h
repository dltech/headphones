#ifndef H_I2C_REGS
#define H_I2C_REGS
/*
 * Simple CC2640 headphones
 * Inter-Integrated Circuit (I2C) Interface registers
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
#define SOAR    MMIO32(I2C0 + 0x000)

/*  */
#define SSTAT   MMIO32(I2C0 + 0x004)

/*  */
#define SCTL    MMIO32(I2C0 + 0x004)

/*  */
#define SDR     MMIO32(I2C0 + 0x008)

/*  */
#define SIMR    MMIO32(I2C0 + 0x00c)

/*  */
#define SRIS    MMIO32(I2C0 + 0x010)

/*  */
#define SMIS    MMIO32(I2C0 + 0x014)

/*  */
#define SICR    MMIO32(I2C0 + 0x018)

/*  */
#define MSA     MMIO32(I2C0 + 0x800)

/*  */
#define MSTAT   MMIO32(I2C0 + 0x804)

/*  */
#define MCTRL   MMIO32(I2C0 + 0x804)

/*  */
#define MDR     MMIO32(I2C0 + 0x808)

/*  */
#define MTPR    MMIO32(I2C0 + 0x80c)

/*  */
#define MIMR    MMIO32(I2C0 + 0x810)

/*  */
#define MRIS    MMIO32(I2C0 + 0x814)

/*  */
#define MMIS    MMIO32(I2C0 + 0x818)

/*  */
#define MICR    MMIO32(I2C0 + 0x81c)

/*  */
#define MCR     MMIO32(I2C0 + 0x820)

#endif
