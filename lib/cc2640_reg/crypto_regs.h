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
#define HW_MAJOR_VER
#define HW_MAJOR_VER
// Minor version number
#define HW_MINOR_VER
// Patch level.
#define HW_PATCH_LVL
// Bit-by-bit complement of the VER_NUM field bits.
#define VER_NUM_COMPL
// Version number of the DMA Controller (209)
#define VER_NUM

/*  */
#define KEYWRITEAREA    MMIO32(CRYPTO + 0x400)

/*  */
#define KEYWRITTENAREA  MMIO32(CRYPTO + 0x404)

/*  */
#define KEYSIZE         MMIO32(CRYPTO + 0x408)

/*  */
#define KEYREADAREA     MMIO32(CRYPTO + 0x40c)


//aeskey



/*  */
#define AESCTL          MMIO32(CRYPTO + 0x550)

/*  */
#define AESDATALEN0     MMIO32(CRYPTO + 0x554)

/*  */
#define AESDATALEN1     MMIO32(CRYPTO + 0x558)

/*  */
#define AESAUTHLEN      MMIO32(CRYPTO + 0x55c)

/*  */
#define AESDATAOUT0     MMIO32(CRYPTO + 0x560)

/*  */
#define AESDATAIN0      MMIO32(CRYPTO + 0x560)

/*  */
#define AESDATAOUT1     MMIO32(CRYPTO + 0x564)

/*  */
#define AESDATAIN1      MMIO32(CRYPTO + 0x564)

/*  */
#define AESDATAOUT1     MMIO32(CRYPTO + 0x568)

/*  */
#define AESDATAIN1      MMIO32(CRYPTO + 0x568)

/*  */
#define AESDATAOUT1     MMIO32(CRYPTO + 0x56c)

/*  */
#define AESDATAIN1      MMIO32(CRYPTO + 0x56c)

// aes tag out


/*  */
#define ALGSEL          MMIO32(CRYPTO + 0x700)

/*  */
#define DMAPROTCTL      MMIO32(CRYPTO + 0x704)

/*  */
#define SWRESET         MMIO32(CRYPTO + 0x740)

/*  */
#define IRQTYPE         MMIO32(CRYPTO + 0x780)

/*  */
#define IRQEN           MMIO32(CRYPTO + 0x784)

/*  */
#define IRQCLR          MMIO32(CRYPTO + 0x788)

/*  */
#define IRQSET          MMIO32(CRYPTO + 0x78c)

/*  */
#define IRQSTAT         MMIO32(CRYPTO + 0x790)

/*  */
#define HWVER           MMIO32(CRYPTO + 0x7fc)

#endif
