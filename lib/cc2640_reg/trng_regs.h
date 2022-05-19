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

/* Random Number Readout Value */
#define OUT0        MMIO32(TRNG + 0x0000)
// LSW of 64- bit random value.
#define OUT1        MMIO32(TRNG + 0x0004)
// MSW of 64-bit random value.

/* Interrupt Status */
#define IRQFLAGSTAT MMIO32(TRNG + 0x0008)
// 1: Indicates that the TRNG is busy generating entropy
#define NEED_CLOCK      0x80000000
// 1: The number of FROs shut down
#define SHUTDOWN_OVF    0x00000002
// 1: Data are available in OUT0 and OUT1.
#define RDY             0x00000001

/* Interrupt Mask */
#define IRQFLAGMASK MMIO32(TRNG + 0x000c)
// 1: Allow IRQFLAGSTAT.SHUTDOWN_OVF to activate the interrupt from this module.
// 1: Allow IRQFLAGSTAT.RDY to activate the interrupt from this module.

/* Interrupt Flag Clear */
#define IRQFLAGCLR  MMIO32(TRNG + 0x0010)
// 1: Clear IRQFLAGSTAT.SHUTDOWN_OVF.
// 1: Clear IRQFLAGSTAT.RDY.

/* Control */
#define TRNG_CTL    MMIO32(TRNG + 0x0014)
// This field determines the number of samples.
#define STARTUP_CYCLES_SFT  16
#define STARTUP_CYCLES_MSK  0xffff
// 1: Starts TRNG, gathering entropy from the FROs
#define TRNG_EN             0x00000400
// 1: Remove XNOR feedback from the main LFSR.
#define NO_LFSR_FB          0x00000004
// 1: Enables access to the TESTCNT and LFSR0/LFSR1/LFSR2 registers.
#define TEST_MODE           0x00000002


/* Configuration 0 */
#define TRNG_CFG0   MMIO32(TRNG + 0x0018)
// This field determines the maximum number of samples taken to re-generate.
#define MAX_REFILL_CYCLES_SFT   16
#define MAX_REFILL_CYCLES_MSK   0xffff
// directly controls the number of clock cycles between samples from the FROs.
#define SMPL_DIV_SFT            8
#define SMPL_DIV_MSK            0xf
// This field determines the minimum number of samples taken to re-generate.
#define MIN_REFILL_CYCLES_SFT   0
#define MIN_REFILL_CYCLES_MSK   0xff

/* Alarm Control */
#define ALARMCNT    MMIO32(TRNG + 0x001c)
// This field determines the maximum number of samples taken to re-generate.
#define SHUTDOWN_CNT_SFT    24
#define SHUTDOWN_CNT_MSK    0x3f
// directly controls the number of clock cycles between samples from the FROs.
#define SHUTDOWN_THR_SFT    16
#define SHUTDOWN_THR_MSK    0x1f
// This field determines the minimum number of samples taken to re-generate.
#define ALARM_THR_SFT       0
#define ALARM_THR_MSK       0xff

/* FRO Enable */
#define FROEN       MMIO32(TRNG + 0x0020)
// Enable bits for the individual FROs. FRO_MASK

/* FRO De-tune Bit */
#define FRODETUNE   MMIO32(TRNG + 0x0024)
// De-tune bits for the individual FROs. FRO_MASK

/* Alarm Event */
#define ALARMMASK   MMIO32(TRNG + 0x0028)
// Logging bits for the 'alarm events' of individual FROs. FRO_MASK

/* Alarm Shutdown */
#define ALARMSTOP   MMIO32(TRNG + 0x002c)
// A '1' in bit [n] indicates FRO 'n' experienced more than one 'alarm event'
// in quick succession and has been turned off. FRO_FLAGS

/* LFSR Readout Value */
#define LFSR0       MMIO32(TRNG + 0x0030)
// Bits [31:0] of the main entropy accumulation LFSR. LFSR_31_0
#define LFSR1       MMIO32(TRNG + 0x0034)
// Bits [63:32] of the main entropy accumulation LFSR.
#define LFSR2       MMIO32(TRNG + 0x0038)
// Bits [80:64] of the main entropy accumulation LFSR.

/* TRNG Engine Options Information */
#define HWOPT       MMIO32(TRNG + 0x0078)
// Number of FROs implemented in this TRNG, value 24 (decimal).
#define NR_OF_FROS_SFT  6
#define NR_OF_FROS_MSK  0x3f

/* EIP Number And Core Revision */
#define HWVER0      MMIO32(TRNG + 0x007c)
// This field determines the maximum number of samples taken to re-generate.
#define HW_MAJOR_VER_SFT    24
#define HW_MAJOR_VER_MSK    0xf
// directly controls the number of clock cycles between samples from the FROs.
#define HW_MINOR_VER_SFT    20
#define HW_MINOR_VER_MSK    0xf
// This field determines the minimum number of samples taken to re-generate.
#define HW_PATCH_LVL_SFT    16
#define HW_PATCH_LVL_MSK    0xf
// This field determines the minimum number of samples taken to re-generate.
#define EIP_NUM_COMPL_SFT   8
#define EIP_NUM_COMPL_MSK   0xff
// This field determines the minimum number of samples taken to re-generate.
#define EIP_NUM_SFT         0
#define EIP_NUM_MSK         0xff

/*  */
#define IRQSTATMASK MMIO32(TRNG + 0x1fd8)
// Shutdown Overflow.
#define SHUTDOWN_OVF    0x2
// New random value available.
#define RND_RDY         0x1

/* TRNG Revision Number */
#define HWVER1      MMIO32(TRNG + 0x1fe0)
// The revision number of this module is Rev 2.0. 7-0 REV

/* Interrupt Set */
#define IRQSET      MMIO32(TRNG + 0x1fec)
// Software should not rely on the value of a reserved.

/* SW Reset Control */
#define SWRESET     MMIO32(TRNG + 0x1ff0)
// Write '1' to soft reset , reset will be low for 4-5 clock cycles.
#define RND_RESET   0x1

/* Interrupt Status */
#define IRQSTAT     MMIO32(TRNG + 0x1ff8)
// TRNG Interrupt status.
#define RND_STAT    0x1

#endif
