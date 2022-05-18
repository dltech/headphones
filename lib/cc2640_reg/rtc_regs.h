#ifndef H_RTC_REGS
#define H_RTC_REGS
/*
 * Simple CC2640 headphones
 * Real-Time Clock registers
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

/* Event Flags, RTC Status */
#define RTC_CTL     MMIO32(AON_RTC + 0x00)
// Eventmask selecting which delayed events that form the combined event.
#define COMB_EV_MASK_NO     0x00000
#define COMB_EV_MASK_CH0    0x10000
#define COMB_EV_MASK_CH1    0x20000
#define COMB_EV_MASK_CH2    0x40000
// Number of SCLK_LF clock cycles waited before generating delayed events.
#define EV_DELAY_NO 0x000
#define EV_DELAY1   0x100
#define EV_DELAY2   0x200
#define EV_DELAY4   0x300
#define EV_DELAY8   0x400
#define EV_DELAY16  0x500
#define EV_DELAY32  0x600
#define EV_DELAY48  0x700
#define EV_DELAY64  0x800
#define EV_DELAY80  0x900
#define EV_DELAY96  0xa00
#define EV_DELAY112 0xb00
#define EV_DELAY128 0xc00
#define EV_DELAY144 0xd00
// RTC Counter reset.
#define RESET       0x00080
// RTC_4KHZ is a 4 KHz reference output, tapped from SUBSEC.VALUE bit 19.
#define RTC_4KHZ_EN 0x00004
// RTC_UPD is a 16 KHz signal used to sync up the radio timer.
#define RTC_UPD_EN  0x00002
// Enable RTC counter
#define RTC_EN      0x00001

/* Event Flags, RTC Status */
#define EVFLAGS     MMIO32(AON_RTC + 0x04)
// Channel 2 event flag, set when CHCTL.CH2_EN = 1.
#define CH2 0x10000
// Channel 1 event flag, set when CHCTL.CH1_EN = 1.
#define CH1 0x00100
// Channel 0 event flag, set when CHCTL.CH0_EN = 1.
#define CH0 0x00001

/* Second Counter Value, Integer Part */
#define SEC         MMIO32(AON_RTC + 0x08)
// Unsigned integer representing Real Time Clock in seconds. VALUE

/* Second Counter Value, Fractional Part */
#define SUBSEC      MMIO32(AON_RTC + 0x0c)
// Unsigned integer representing Real Time Clock in fractions of a second

/* Subseconds Increment */
#define SUBSECINC   MMIO32(AON_RTC + 0x10)
// This value compensates for a SCLK_LF clock which has an offset from 32768 Hz.

/* Channel Configuration */
#define CHCTL       MMIO32(AON_RTC + 0x14)
// Set to enable continuous operation of Channel 2
#define CH2_CONT_EN 0x40000
// RTC Channel 2 Enable
#define CH2_EN      0x10000
// Set Channel 1 mode
#define CH1_CAPT_EN 0x00200
// RTC Channel 1 Enable
#define CH1_EN      0x00100
// RTC Channel 0 Enable
#define CH0_EN      0x00001

/* Channel n Compare Value */
#define CH0CMP      MMIO32(AON_RTC + 0x18)
#define CH1CMP      MMIO32(AON_RTC + 0x1c)
#define CH2CMP      MMIO32(AON_RTC + 0x20)
// RTC Channel n compare value.

/* Channel 2 Compare Value Auto-increment */
#define CH2CMPINC   MMIO32(AON_RTC + 0x24)
// VALUE

/* Channel 1 Capture Value */
#define CH1CAPT     MMIO32(AON_RTC + 0x28)
// Value of SEC.VALUE bits 15:0 at capture time.
#define SEC_SFT     16
#define SEC_MSK     0xffff
// Value of SUBSEC.VALUE bits 31:16 at capture time.
#define SUBSEC_SFT  0
#define SUBSEC_MSK  0xffff

/* AON Synchronization */
#define SYNC        MMIO32(AON_RTC + 0x2c)
// 1 if there are no outstanding write requests between MCU and AON.
#define WBUSY   0x1

#endif
