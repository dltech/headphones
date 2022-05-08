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

/* Pin Direction */
#define AIFDIRCFG		MMIO32(I2S0 + 0x08)
// Configures the AD2 audio data pin usage
#define	AD2_NO  0x0000
#define	AD2_IN  0x0100
#define	AD2_OUT 0x0200
// Configures the AD1 audio data pin usage
#define	AD1_NO  0x0000
#define	AD1_IN  0x0010
#define	AD1_OUT 0x0020
// Configures the AD0 audio data pin usage
#define	AD1_NO  0x0000
#define	AD1_IN  0x0001
#define	AD1_OUT 0x0002

/* Serial Interface Format Configuration */
#define AIFFMTCFG		MMIO32(I2S0 + 0x0c)
// The number of BCLK periods between a WCLK edge and MSB of the first word
#define DATA_DELAY_SHIFT	8
// The size of each word stored to or loaded from memory:
#define	MEM_LEN_24	0x80
// On the serial audio interface, data (and wclk) is sampled and clocked out
#define	SMPL_EDGE	0x40
// Selects dual- or single-phase format.
#define	DUAL_PHASE	0x20
// Number of bits per word (8-24)
#define	WORD_LEN    0x0f

/* Word Selection Bit Mask for Pin 0 */
#define AIFWMASK0		MMIO32(I2S0 + 0x10)
// Bit-mask indicating valid channels in a frame on AD0.
#define	I2S_MSK	0xff
/* Word Selection Bit Mask for Pin 1 */
#define AIFWMASK1		MMIO32(I2S0 + 0x14)

/* Audio Interface PWM Debug Value */
#define AIFPWMVALUE		MMIO32(I2S0 + 0x1c)
// The value written to this register determines the width of the active high
#define	PULSE_WIDTH_MSK	0xffff

/* DMA Input Buffer Next Pointer */
#define AIFINPTRNEXT	MMIO32(I2S0 + 0x20)

/* DMA Input Buffer Current Pointer */
#define AIFINPTR		MMIO32(I2S0 + 0x24)

/* DMA Output Buffer Next Pointer */
#define AIFOUTPTRNEXT	MMIO32(I2S0 + 0x28)

/* DMA Output Buffer Current Pointer */
#define AIFOUTPTR		MMIO32(I2S0 + 0x2c)

/* Samplestamp Generator Control Register */
#define STMPCTL			MMIO32(I2S0 + 0x34)
// Low until the output pins are ready to be started by the samplestamp generator.
#define	OUT_RDY	0x4
// Low until the input pins are ready to be started by the samplestamp generator.
#define	IN_RDY	0x2
// Enables the samplestamp generator.
#define	STMP_EN	0x1

/* Captured XOSC Counter Value, Capture Channel 0 */
#define STMPXCNTCAPT0	MMIO32(I2S0 + 0x38)
// The value of the samplestamp XOSC counter
#define CAPT_VALUE_MSK  0xffff

/* XOSC Period Value */
#define STMPXPER		MMIO32(I2S0 + 0x3c)
// The number of 24 MHz clock cycles in the previous WCLK period
#define	VALUE_MSK	    0xffff

/* Captured WCLK Counter Value, Capture Channel 0 */
#define STMPWCNTCAPT0	MMIO32(I2S0 + 0x40)
// The value of the samplestamp WCLK counter
#define CAPT_VALUE      0xffff

/* WCLK Counter Period Value */
#define STMPWPER		MMIO32(I2S0 + 0x44)
// Used to define when STMPWCNT is to be reset so number of WCLK edges are found

/* WCLK Counter Trigger Value for Input Pins */
#define STMPINTRIG		MMIO32(I2S0 + 0x48)
// Compare value used to start the incoming audio streams.
#define IN_START_WCNT   0xffff

/* WCLK Counter Trigger Value for Output Pins */
#define STMPOUTTRIG		MMIO32(I2S0 + 0x4c)
// Compare value used to start the outgoing audio streams.
#define OUT_START_WCNT  0xffff

/* WCLK Counter Set Operation */
#define STMPWSET		MMIO32(I2S0 + 0x50)
// Sets the running WCLK counter equal to the written value.

/* WCLK Counter Add Operation */
#define STMPWADD		MMIO32(I2S0 + 0x54)
// Adds the written value to the running WCLK counter.
#define VALUE_INC       0xffff

/* XOSC Minimum Period Value Minimum Value of STMPXPER */
#define STMPXPERMIN		MMIO32(I2S0 + 0x58)

/* Current Value of WCNT */
#define STMPWCNT		MMIO32(I2S0 + 0x5c)
// Current value of the WCLK counter
#define CURR_VALUE      0xffff

/* Current Value of XCNT */
#define STMPXCNT		MMIO32(I2S0 + 0x60)

/* no information */
#define STMPXCNTCAPT1	MMIO32(I2S0 + 0x64)

/* Captured WCLK Counter Value, Capture Channel 1 */
#define STMPWCNTCAPT1	MMIO32(I2S0 + 0x68)
// Channel 1 is idle and can not be sampled from an external event as with Channel 0

/* Interrupt Mask Register */
#define IRQMASK			MMIO32(I2S0 + 0x70)
// IRQFLAGS.AIF_DMA_IN interrupt mask
// IRQFLAGS.AIF_DMA_OUT interrupt mask
// IRQFLAGS.WCLK_TIMEOUT interrupt mask
// IRQFLAGS.BUS_ERR interrupt mask
// IRQFLAGS.WCLK_ERR interrupt mask
// IRQFLAGS.PTR_ERR interrupt mask.

/* Raw Interrupt Status Register */
#define IRQFLAGS		MMIO32(I2S0 + 0x74)
// Set when condition for this bit field event occurs
// Set when condition for this bit field event occurs
// Set when the sample stamp generator does not detect a positive WCLK edge.
// Set when a DMA operation is not completed in time
// Set when an unexpected WCLK edge, when two WCLK edges are less than 4 BCLK ...
// Set when AIFINPTRNEXT or AIFOUTPTRNEXT has not been loaded

/* Interrupt Set Register */
#define IRQSET			MMIO32(I2S0 + 0x78)
// Sets the interrupt of IRQFLAGS.AIF_DMA_IN
// Sets the interrupt of IRQFLAGS.AIF_DMA_OUT
// Sets the interrupt of IRQFLAGS.WCLK_TIMEOUT
// Sets the interrupt of IRQFLAGS.BUS_ERR
// Sets the interrupt of IRQFLAGS.WCLK_ERR
// Sets the interrupt of IRQFLAGS.PTR_ERR

/* Interrupt Clear Register */
#define IRQCLR			MMIO32(I2S0 + 0x7c)
// Clears the interrupt of IRQFLAGS.AIF_DMA_IN
#define	AIF_DMA_IN      0x20
// Clears the interrupt of IRQFLAGS.AIF_DMA_OUT
#define	AIF_DMA_OUT	    0x10
// Clears the interrupt of IRQFLAGS.WCLK_TIMEOUT
#define	WCLK_TIMEOUT    0x08
// Clears the interrupt of IRQFLAGS.BUS_ERR
#define	BUS_ERR         0x04
// Clears the interrupt of IRQFLAGS.WCLK_ERR
#define	WCLK_ERR        0x02
// Clears the interrupt of IRQFLAGS.PTR_ERR
#define	PTR_ERR         0x01
