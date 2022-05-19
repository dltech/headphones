#ifndef H_TRNG_REGS
#define H_TRNG_REGS
/*
 * Simple CC2640 headphones
 * Cryptography registers
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

/* DMA Channel n Control */
#define DMACH0CTL       MMIO32(CRYPTO + 0x000)
#define DMACH1CTL       MMIO32(CRYPTO + 0x020)
// Channel priority
#define PRIO        0x2
// DMA Channel 0 Control
#define CRYPTO_EN   0x1

/* DMA Channel 0 External Address */
#define DMACH0EXTADDR   MMIO32(CRYPTO + 0x004)
#define DMACH1EXTADDR   MMIO32(CRYPTO + 0x024)
// Channel external address value. ADDR

/* DMA Channel 0 Length */
#define DMACH0LEN       MMIO32(CRYPTO + 0x00c)
#define DMACH1LEN       MMIO32(CRYPTO + 0x02c)
// DMA transfer length in bytes.  15-0 LEN

/* DMA Controller Status */
#define DMASTAT         MMIO32(CRYPTO + 0x018)
// Reflects possible transfer errors on the AHB port.
#define PORT_ERR    0x20000
// This register field indicates if DMA channel 1 is active or not.
#define CH1_ACTIVE  0x00002
// This register field indicates if DMA channel 0 is active or not.
#define CH0_ACTIVE  0x00001

/* DMA Controller Software Reset */
#define DMASWRESET      MMIO32(CRYPTO + 0x01c)
// Software reset enable
#define DMASW_RESET 0x1

/* DMA Controller Master Configuration */
#define DMABUSCFG       MMIO32(CRYPTO + 0x078)
// Maximum burst size that can be performed on the AHB bus
#define AHB_MST1_BURST_SIZE_4BYTE   0x2000
#define AHB_MST1_BURST_SIZE_8BYTE   0x3000
#define AHB_MST1_BURST_SIZE_16BYTE  0x4000
#define AHB_MST1_BURST_SIZE_32BYTE  0x5000
#define AHB_MST1_BURST_SIZE_64BYTE  0x6000
// Idle transfer insertion between consecutive burst transfers on AHB
#define AHB_MST1_IDLE_EN            0x0800
// Burst length type of AHB transfer
#define AHB_MST1_INCR_EN            0x0400
// Locked transform on AHB
#define AHB_MST1_LOCK_EN            0x0200
// Endianess for the AHB master
#define AHB_MST1_BIGEND             0x0100

/* DMA Controller Port Error */
#define DMAPORTERR      MMIO32(CRYPTO + 0x07c)
// A 1 indicates that the Crypto peripheral has detected an AHB bus error
#define AHB_ERR 0x1000
// Indicates which channel was serviced last by the AHB master port.
#define LAST_CH 0x0200

/* DMA Controller Version */
#define DMAHWVER        MMIO32(CRYPTO + 0x0fc)
// Major version number
#define HW_MAJOR_VER_SFT    24
#define HW_MAJOR_VER_MSK    0xf
// Minor version number
#define HW_MINOR_VER_SFT    20
#define HW_MINOR_VER_MSK    0xf
// Patch level.
#define HW_PATCH_LVL_SFT    16
#define HW_PATCH_LVL_MSK    0xf
// Bit-by-bit complement of the VER_NUM field bits.
#define VER_NUM_COMPL_SFT   8
#define VER_NUM_COMPL_MSK   0xff
// Version number of the DMA Controller (209)
#define VER_NUM_SFT         0
#define VER_NUM_MSK         0xff

/* Key Write Area */
#define KEYWRITEAREA    MMIO32(CRYPTO + 0x400)
// 1h = This RAM area is selected to be written
#define RAM_AREA7   0x80
// 1h = This RAM area is selected to be written
#define RAM_AREA6   0x40
// 1h = This RAM area is selected to be written
#define RAM_AREA5   0x20
// 1h = This RAM area is selected to be written
#define RAM_AREA4   0x10
// 1h = This RAM area is selected to be written
#define RAM_AREA3   0x08
// 1h = This RAM area is selected to be written
#define RAM_AREA2   0x04
// 1h = This RAM area is selected to be written
#define RAM_AREA1   0x02
// 1h = This RAM area is selected to be written
#define RAM_AREA0   0x01

/* Key Written Area Status */
#define KEYWRITTENAREA  MMIO32(CRYPTO + 0x404)
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN7   0x80
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN6   0x40
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN5   0x20
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN4   0x10
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN3   0x08
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN2   0x04
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN1   0x02
// 1h = This RAM area is written with valid key information
#define RAM_AREA_WRITTEN0   0x01

/* This register defines the size of the keys that are written with DMA. */
#define KEYSIZE         MMIO32(CRYPTO + 0x408)
// Key size
#define SIZE_128BIT 0x1
#define SIZE_192BIT 0x2
#define SIZE_256BIT 0x3

/* Key Read Area */
#define KEYREADAREA     MMIO32(CRYPTO + 0x40c)
// Key store operation busy status flag (read only)
#define KEY_BUSY    0x80000000
// Selects the area of the key store RAM from where the key needs to be read
#define RAM_AREA0   0x0
#define RAM_AREA1   0x1
#define RAM_AREA2   0x2
#define RAM_AREA3   0x3
#define RAM_AREA4   0x4
#define RAM_AREA5   0x5
#define RAM_AREA6   0x6
#define RAM_AREA7   0x7

/* Clear AES_KEY2/GHASH Key */
#define AESKEY2(n)      MMIO32(CRYPTO + 0x500 + (n*4))
// AESKEY2.* bits 31+x:0+x or AES_GHASH_H.* bits 31+x:0+x. KEY2

/* Clear Clear AES_KEY3 */
#define AESKEY3(n)      MMIO32(CRYPTO + 0x510 + (n*4))
// AESKEY3.* bits 31+x:0+x or AESKEY2.* bits 159+x:128+. KEY2

/* AES Initialization Vector */
#define AESIV(n)        MMIO32(CRYPTO + 0x540 + (n*4))
// The interpretation of this field depends on the crypto operation mode. IV

/* AES Input/Output Buffer Control */
#define AESCTL          MMIO32(CRYPTO + 0x550)
// The Host is permitted to write the next context.
#define CONTEXT_RDY         0x80000000
// block(s) is/are available for the Host to retrieve
#define SAVED_CONTEXT_RDY   0x40000000
// IV must be read before the AES engine can start a new operation.
#define SAVE_CONTEXT        0x20000000
// Defines M that indicates the length of the authentication field for CCM oper
#define CCM_M_SFT           22
#define CCM_M_MSK           0x7
// Defines L that indicates the width of the length field for CCM operations
#define CCM_L_SFT           19
#define CCM_L_MSK           0x7
// AES-CCM mode enable.
#define CCM                 0x00040000
// MAC mode enable.
#define CBC_MAC             0x00008000
// Specifies the counter width for AES-CTR mode
#define CTR_WIDTH_32BIT     0x000
#define CTR_WIDTH_64BIT     0x080
#define CTR_WIDTH_96BIT     0x100
#define CTR_WIDTH_128BIT    0x180
// AES-CTR mode enable
#define CTR                 0x00000040
// CBC mode enable
#define CBC                 0x00000020
// This field specifies the key size.
#define KEY_SIZE_128        0x08
// 0 : Decrypt operation is performed. 1 : Encrypt operation is performed.
#define DIR                 0x00000004
// 1: 16-byte AES input buffer is empty.
#define INPUT_RDY           0x00000002
// 1: indicates that an AES output block is available to be retrieved.
#define OUTPUT_RDY          0x00000001

/* Crypto Data Length LSW */
#define AESDATALEN0     MMIO32(CRYPTO + 0x554)
// the Length values to the Crypto peripheral. LEN_LSW

/* Crypto Data Length MSW */
#define AESDATALEN1     MMIO32(CRYPTO + 0x558)
// Bits [60:32] of the combined data length.

/* AES Authentication Length */
#define AESAUTHLEN      MMIO32(CRYPTO + 0x55c)
// Authentication data length in bytes for combined mode

/* Data Input/Output */
#define AESDATAOUT0     MMIO32(CRYPTO + 0x560)
#define AESDATAOUT1     MMIO32(CRYPTO + 0x564)
#define AESDATAOUT2     MMIO32(CRYPTO + 0x568)
#define AESDATAOUT3     MMIO32(CRYPTO + 0x56c)
// Data register 0 for output block data from the Crypto peripheral.

/* AES Data Input/Output */
#define AESDATAIN0      MMIO32(CRYPTO + 0x560)
#define AESDATAIN1      MMIO32(CRYPTO + 0x564)
#define AESDATAIN2      MMIO32(CRYPTO + 0x568)
#define AESDATAIN3      MMIO32(CRYPTO + 0x56c)
// Data registers for input block data to the Crypto peripheral.

/* AES Tag Output */
#define AESTAGOUT(n)    MMIO32(CRYPTO + 0x570 + (n*4))
// This register contains the authentication TAG for the combined and
// authentication-only modes. TAG

/* Master Algorithm Select */
#define ALGSEL          MMIO32(CRYPTO + 0x700)
// If this bit is set, the DMA operation includes a TAG
#define ALG_TAG     0x80000000
// If set to 1, the AES data is loaded via DMA
#define AES         0x00000002
// If set to 1, selects the Key Store to be loaded via DMA.
#define KEY_STORE   0x00000001

/* Master Protection Control */
#define DMAPROTCTL      MMIO32(CRYPTO + 0x704)
// Select AHB transfer protection control for DMA transfers
#define PRIVILEGED_EN   0x1

/* Software Reset */
#define CRYPTO_SWRESET  MMIO32(CRYPTO + 0x740)
// Select AHB transfer protection control for DMA transfers
#define AES_RESET   0x1

/* Control Interrupt Configuration */
#define IRQTYPE         MMIO32(CRYPTO + 0x780)
// If this bit is 0, the interrupt output is a pulse.
#define LEVEL   0x1

/* Interrupt Enable */
#define IRQEN           MMIO32(CRYPTO + 0x784)
// This bit enables IRQSTAT.DMA_IN_DONE as source for IRQ.
#define DMA_IN_DONE     0x2
// This bit enables IRQSTAT.RESULT_AVAIL as source for IRQ.
#define RESULT_AVAIL    0x1

/* Interrupt Clear */
#define IRQCLR          MMIO32(CRYPTO + 0x788)
// If 1 is written to this bit, IRQSTAT.DMA_BUS_ERR is cleared.
#define DMA_BUS_ERR     0x80000000
// If 1 is written to this bit, IRQSTAT.KEY_ST_WR_ERR is cleared.
#define KEY_ST_WR_ERR   0x40000000
// If 1 is written to this bit, IRQSTAT.KEY_ST_RD_ERR is cleared.
#define KEY_ST_RD_ERR   0x20000000
// If 1 is written to this bit, IRQSTAT.DMA_IN_DONE is cleared.
#define DMA_IN_DONE     0x00000002
// If 1 is written to this bit, IRQSTAT.RESULT_AVAIL is cleared.
#define RESULT_AVAIL    0x00000001

/* Interrupt Set */
#define CRYPTO_IRQSET   MMIO32(CRYPTO + 0x78c)
// If 1 is written to this bit, IRQSTAT.DMA_IN_DONE is set.
#define DMA_IN_DONE     0x2
// If 1 is written to this bit, IRQSTAT.RESULT_AVAIL is set.
#define RESULT_AVAIL    0x1

/* Interrupt Status */
#define CRYPTO_IRQSTAT  MMIO32(CRYPTO + 0x790)
// This bit is set when a DMA bus error is detected during a DMA operation
// This bit is set when a write error is detected during the DMA write oper.
//This bit will be set when a read error is detected during the read of a key.
// This bit returns the status of DMA data in done interrupt.
// This bit is set high when the Crypto peripheral has a result available.

/* CTRL Module Version */
#define HWVER           MMIO32(CRYPTO + 0x7fc)
// Major version number
#define HW_MAJOR_VER_SFT    23
#define HW_MAJOR_VER_MSK    0xf
// Minor version number
#define HW_MINOR_VER_SFT    20
#define HW_MINOR_VER_MSK    0xf
// Patch level, starts at 0 at first delivery of this version.
#define HW_PATCH_LVL_SFT    16
#define HW_PATCH_LVL_MSK    0xf
// These bits simply contain the complement of VER_NUM (0x87),
#define VER_NUM_COMPL_SFT   8
#define VER_NUM_COMPL_MSK   0xff
// The version number for the Crypto peripheral, this field contains the 120.
#define VER_NUM_SFT         0
#define VER_NUM_MSK         0xff

#endif
