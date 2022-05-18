#ifndef H_WDT_REGS
#define H_WDT_REGS
/*
 * Simple CC2640 headphones
 * Watchdog Timer registers
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

/* Configuration */
#define WDT_LOAD    MMIO32(WDT + 0x000)
// This register is the 32-bit interval value used by the 32-bit counter. WDTLOAD

/* Current Count Value */
#define VALUE       MMIO32(WDT + 0x004)
// This register contains the current count value of the timer. WDTVALUE

/* Control */
#define WDT_CTL     MMIO32(WDT + 0x008)
// WDT Interrupt Type.
#define INTTYPE 0x4
// WDT Reset Enable.
#define RESEN   0x2
// WDT Interrupt Enable.
#define INTEN   0x1

/* Interrupt Clear */
#define ICR         MMIO32(WDT + 0x00c)
// This register is the interrupt clear register. WDTICR

/* Raw Interrupt Status */
#define RIS         MMIO32(WDT + 0x010)
// This register is the raw interrupt status register.
#define WDTRIS   0x1

/* Masked Interrupt Status */
#define MIS         MMIO32(WDT + 0x014)
// This register is the masked interrupt status register.
#define WDTMIS   0x1

/* Test Mode */
#define TEST        MMIO32(WDT + 0x418)
// WDT Stall Enable
#define STALL   0x100
// The test enable bit
#define TEST_EN 0x001

/* Interrupt Cause Test Mode */
#define INT_CAUS    MMIO32(WDT + 0x41c)
// Indicates that the cause of an interrupt was a reset generated but blocked
#define CAUSE_RESET 0x2
// Replica of RIS.WDTRIS
#define CAUSE_INTR  0x1

/* Lock */
#define LOCK        MMIO32(WDT + 0xc00)
// WDT Lock WDTLOCK

#endif
