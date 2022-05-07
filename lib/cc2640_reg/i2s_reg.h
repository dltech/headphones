/*
 * Simple CC2640 headphones
 * I2S registers
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

/* WCLK Source Selection */
#define AIFWCLKSRC		MMIO32(I2S0 + 0x00)
// Inverts WCLK source (pad or internal) when set.
#define	WCLK_INV		0x4
// Selects WCLK source for AIF
#define	WCLK_SRC_NO		0x0
#define	WCLK_SRC_EXT	0x1
#define	WCLK_SRC_INT	0x2

/* DMA Buffer Size Configuration */
#define AIFDMACFG		MMIO32(I2S0 + 0x04)
// Defines the length of the DMA buffer.
#define	END_FRAME_IDX_MSK	0xff

#define AIFDIRCFG		MMIO32(I2S0 + 0x08)
// 
#define		0x
// 
#define		0x
// 
#define		0x

#define AIFFMTCFG		MMIO32(I2S0 + 0x0c)
#define AIFWMASK0		MMIO32(I2S0 + 0x10)
#define AIFWMASK1		MMIO32(I2S0 + 0x14)
#define AIFPWMVALUE		MMIO32(I2S0 + 0x1c)
#define AIFINPTRNEXT	MMIO32(I2S0 + 0x20)
#define AIFPWMVALUE		MMIO32(I2S0 + 0x24)
#define AIFOUTPTR		MMIO32(I2S0 + 0x28)
#define AIFOUTPTRNEXT	MMIO32(I2S0 + 0x2c)
#define AIFOUTPTR		MMIO32(I2S0 + 0x34)
#define STMPCTL			MMIO32(I2S0 + 0x38)
#define STMPXCNTCAPT0	MMIO32(I2S0 + 0x3c)
#define STMPXPER		MMIO32(I2S0 + 0x40)
#define STMPWCNTCAPT0	MMIO32(I2S0 + 0x44)
#define STMPWPER		MMIO32(I2S0 + 0x48)
#define STMPINTRIG		MMIO32(I2S0 + 0x4c)
#define STMPOUTTRIG		MMIO32(I2S0 + 0x50)
#define STMPWADD		MMIO32(I2S0 + 0x54)
#define STMPXPERMIN		MMIO32(I2S0 + 0x58)
#define STMPWCNT		MMIO32(I2S0 + 0x5c)
#define STMPXCNT		MMIO32(I2S0 + 0x60)
#define STMPXCNTCAPT1	MMIO32(I2S0 + 0x64)
#define STMPWCNTCAPT1	MMIO32(I2S0 + 0x68)
#define IRQMASK			MMIO32(I2S0 + 0x70)
#define IRQFLAGS		MMIO32(I2S0 + 0x74)
#define IRQSET			MMIO32(I2S0 + 0x78)
#define IRQCLR			MMIO32(I2S0 + 0x7c)

