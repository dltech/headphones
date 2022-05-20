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

/* Control 0 */
#define SSI_CR0     MMIO32(SSI0 + 0x00)
// Serial clock rate
#define SCR_SFT 8
#define SCR_MSK 0xff
// CLKOUT phase (Motorola SPI frame format only)
#define SPH 0x80
// CLKOUT polarity (Motorola SPI frame format only)
#define SPO 0x40
// Frame format.
#define FRF_SPI 0x00
#define FRF_TI  0x10
#define FRF_NM  0x20
// Data Size Select.
#define DSS_4BIT    0x3
#define DSS_5BIT    0x4
#define DSS_6BIT    0x5
#define DSS_7BIT    0x6
#define DSS_8BIT    0x7
#define DSS_9BIT    0x8
#define DSS_10BIT   0x9
#define DSS_11BIT   0xa
#define DSS_12BIT   0xb
#define DSS_13BIT   0xc
#define DSS_14BIT   0xd
#define DSS_15BIT   0xe
#define DSS_16BIT   0xf

/* Control 1 */
#define SSI_CR1     MMIO32(SSI0 + 0x04)
// Slave-mode output disabled.
#define SOD 0x8
// Master or slave mode select.
#define MS  0x4
// Synchronous serial interface enable.
#define SSE 0x2
// Loop back mode.
#define LBM 0x1

/* Data */
#define SSI_DR      MMIO32(SSI0 + 0x08)
// Transmit/receive data. DATA

/* Status */
#define SSI_SR      MMIO32(SSI0 + 0x0c)
// Serial interface busy.
#define BSY 0x10
// Receive FIFO full.
#define RFF 0x08
// Receive FIFO not empty.
#define RNE 0x04
// Transmit FIFO not full.
#define TNF 0x02
// Transmit FIFO empty.
#define TFE 0x01

/* Clock Prescale */
#define SSI_CPSR    MMIO32(SSI0 + 0x10)
// Clock prescale divisor. CPSDVSR

/* Interrupt Mask Set and Clear */
#define SSI_IMSC    MMIO32(SSI0 + 0x14)
// Transmit FIFO interrupt mask.
#define TXIM    0x08
// Receive FIFO interrupt mask.
#define RXIM    0x04
// Receive timeout interrupt mask.
#define RTIM    0x02
// Receive overrun interrupt mask.
#define RORIM   0x01

/* Raw Interrupt Status */
#define SSI_RIS     MMIO32(SSI0 + 0x18)
// Raw transmit FIFO interrupt status.
#define TXRIS    0x08
// Raw interrupt state of receive FIFO interrupt.
#define RXRIS    0x04
// Raw interrupt state of receive timeout interrupt.
#define RTRIS    0x02
// Raw interrupt state of receive overrun interrupt.
#define RORRIS   0x01

/* Masked Interrupt Status */
#define SSI_MIS     MMIO32(SSI0 + 0x1c)
// Masked interrupt state of transmit FIFO interrupt.
#define TXMIS    0x08
// Masked interrupt state of receive FIFO interrupt.
#define RXMIS    0x04
// Masked interrupt state of receive timeout interrupt.
#define RTMIS    0x02
// Masked interrupt state of receive overrun interrupt.
#define RORMIS   0x01

/* Interrupt Clear */
#define SSI_ICR     MMIO32(SSI0 + 0x20)
// Clear the receive timeout interrupt.
#define SSI_RTIC    0x2
// Clear the receive overrun interrupt.
#define RORIC       0x1

/* DMA Control */
#define SSI_DMACR   MMIO32(SSI0 + 0x24)
// Transmit DMA enable.
#define SSI_TXDMAE  0x2
// Receive DMA enable.
#define SSI_RXDMAE  0x1

#endif
