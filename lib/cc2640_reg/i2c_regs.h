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

/* Slave Own Address */
#define SOAR    MMIO32(I2C0 + 0x000)
// I2C slave own address. OAR

/* Slave Status */
#define SSTAT   MMIO32(I2C0 + 0x004)
// First byte received
#define FBR     0x4
// Transmit request
#define TREQ    0x2
// Receive request
#define RREQ    0x1

/* Slave Control */
#define SCTL    MMIO32(I2C0 + 0x004)
// Device active
#define DA    0x1

/* Slave Data */
#define SDR     MMIO32(I2C0 + 0x008)
// Data for transfer. DATA

/* Slave Interrupt Mask */
#define SIMR    MMIO32(I2C0 + 0x00c)
// Stop condition interrupt mask
#define STOPIM     0x4
// Start condition interrupt mask
#define STARTIM    0x2
// Data interrupt mask
#define DATAIM     0x1

/* Slave Raw Interrupt Status */
#define SRIS    MMIO32(I2C0 + 0x010)
// Stop condition raw interrupt status
#define STOPRIS     0x4
// Start condition raw interrupt status
#define STARTRIS    0x2
// Data raw interrupt status
#define DATARIS     0x1

/* Slave Masked Interrupt Status */
#define SMIS    MMIO32(I2C0 + 0x014)
// Stop condition masked interrupt status
#define STOPMIS     0x4
// Start condition masked interrupt status
#define STARTMIS    0x2
// Data masked interrupt status
#define DATAMIS     0x1

/* Slave Interrupt Clear */
#define SICR    MMIO32(I2C0 + 0x018)
// Stop condition interrupt clear
#define STOPIC     0x4
// Start condition interrupt clear
#define STARTIC    0x2
// Data interrupt clear
#define DATAIC     0x1

/* Master Salve Address */
#define MSA     MMIO32(I2C0 + 0x800)
// I2C master slave address
#define SA_SFT  1
#define SA_MSK  0x7f
// Receive or Send
#define RS     0x1

/* Master Status */
#define MSTAT   MMIO32(I2C0 + 0x804)
// Bus busy
#define BUSBSY      0x40
// I2C idle
#define IDLE        0x20
// Arbitration lost
#define ARBLST      0x10
// Data Was Not Acknowledge
#define DATACK_N    0x08
// Address Was Not Acknowledge
#define ADRACK_N    0x04
// Error
#define ERR         0x02
// I2C busy
#define I2C_BUSY    0x01

/* Master Control */
#define MCTRL   MMIO32(I2C0 + 0x804)
// Data acknowledge enable
#define ACK         0x8
// if the cycle stops at the end of the data cycle or continues on to START.
#define STOP        0x4
// This bit-field generates the Start or Repeated Start condition.
#define I2C_START   0x2
// I2C master enable
#define RUN         0x1

/* Master Data */
#define MDR     MMIO32(I2C0 + 0x808)
// When Read: Last RX Data is returned. DATA

/* I2C Master Timer Period */
#define MTPR    MMIO32(I2C0 + 0x80c)
// Must be set to 0 to set TPR. If set to 1, a write to TPR will be ignored.
#define TPR_7   0x8
// SCL clock period
#define TPR_MSK 0x7f
#define TPR_SFT 0

/* Master Interrupt Mask */
#define MIMR    MMIO32(I2C0 + 0x810)
// 1: The master interrupt is sent to the interrupt controller when the MRIS.RIS
#define IM   0x1

/* Master Raw Interrupt Status */
#define MRIS    MMIO32(I2C0 + 0x814)
// Raw interrupt status
#define I2C_RIS   0x1

/* Master Masked Interrupt Status */
#define MMIS    MMIO32(I2C0 + 0x818)
// Masked interrupt status
#define I2C_MIS   0x1

/* Master Interrupt Clear */
#define MICR    MMIO32(I2C0 + 0x81c)
// Interrupt clear
#define IC   0x1

/* Master Configuration */
#define MCR     MMIO32(I2C0 + 0x820)
// I2C slave function enable
#define SFE     0x20
// I2C master function enable
#define MFE     0x10
// I2C loopback
#define LPBK    0x01

#endif
