#ifndef H_SSI_REGS
#define H_SSI_REGS
/*
 * Simple CC2640 headphones
 * Synchronous Serial Interface (SSI) registers
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
#define SSI_CR0     MMIO32(SSI0 + 0x)

/*  */
#define SSI_CR1     MMIO32(SSI0 + 0x)

/*  */
#define SSI_DR      MMIO32(SSI0 + 0x)

/*  */
#define SSI_SR      MMIO32(SSI0 + 0x)

/*  */
#define SSI_CPSR    MMIO32(SSI0 + 0x)

/*  */
#define SSI_IMSC    MMIO32(SSI0 + 0x)

/*  */
#define SSI_RIS     MMIO32(SSI0 + 0x)

/*  */
#define SSI_MIS     MMIO32(SSI0 + 0x)

/*  */
#define SSI_ICR     MMIO32(SSI0 + 0x)

/*  */
#define SSI_DMACR   MMIO32(SSI0 + 0x)


#endif
