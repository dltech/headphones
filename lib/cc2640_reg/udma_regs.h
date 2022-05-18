#ifndef H_UDMA_REGS
#define H_UDMA_REGS
/*
 * Simple CC2640 headphones
 * Micro Direct Memory Access (μDMA) registers
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

/* Status */
#define STATUS              MMIO32(UDMA0 + 0x000)
// 0x1: Controller includes the integration test logic
#define TEST_INCLUDES   0x10000000
#define TEST_MSK        0xf0000000
#define TEST_SFT        28
// Register value returns number of available uDMA channels minus one.
#define TOTALCHANNELS_SFT   16
#define TOTALCHANNELS_MSK   0x1f
// Current state of the control state machine.
#define STATE_IDLE              0x00000000
#define STATE_READ_CONTROLLER   0x00000010
#define STATE_READ_SOURCE_END   0x00000020
#define STATE_READ_DST          0x00000030
#define STATE_READ_SOURCE       0x00000040
#define STATE_WRITE_DEST        0x00000050
#define STATE_WAIT              0x00000060
#define STATE_WRITE_CONTROLLER  0x00000070
#define STATE_STALLED           0x00000080
#define STATE_DONE              0x00000090
#define STATE_TRANS             0x000000a0

/* Configuration */
#define CFG                 MMIO32(UDMA0 + 0x004)
// Sets the AHB-Lite bus protocol protection state.
#define PRTOCTRL_CACHE      0x00000080
#define PRTOCTRL_BUFFER     0x00000040
#define PRTOCTRL_PRIVILEGED 0x00000020
// Enables the controller.
#define MASTERENABLE        0x00000001

/* Channel Control Data Base Pointer */
#define CTRL                MMIO32(UDMA0 + 0x008)
// This register point to the base address for the primary data structures.
#define BASEPTR_SFT 10
#define BASEPTR_MSK 0x3fffff

/* Channel Alternate Control Data Base Pointer */
#define ALTCTRL             MMIO32(UDMA0 + 0x00c)
//BASEPTR

/* Channel Wait On Request Status */
#define WAITONREQ           MMIO32(UDMA0 + 0x010)
// Channel wait on request status. CHNLSTATUS

/* Channel Software Request */
#define SOFTREQ             MMIO32(UDMA0 + 0x014)
// Set the appropriate bit to generate a software uDMA request on the
// corresponding uDMA channel. CHNLS

/* Channel Set UseBurst */
#define SETBURST            MMIO32(UDMA0 + 0x018)
// Returns the useburst status, or disables individual channels from generating
// single uDMA requests. CHNLS.

/* Channel Clear UseBurst */
#define CLEARBURST          MMIO32(UDMA0 + 0x01c)
// Set the appropriate bit to enable single transfer requests. CHNLS

/* Channel Set Request Mask */
#define SETREQMASK          MMIO32(UDMA0 + 0x020)
// Returns the burst and single request mask status, or disables the
// corresponding channel from generating uDMA requests. CHNLS

/* Clear Channel Request Mask */
#define CLEARREQMASK        MMIO32(UDMA0 + 0x024)
// Set the appropriate bit to enable DMA request for the channel. CHNLS

/* Set Channel Enable */
#define SETCHANNELEN        MMIO32(UDMA0 + 0x028)
// Returns the enable status of the channels, or enables the corresponding
// channels. CHNLS

/* Clear Channel Enable */
#define CLEARCHANNELEN      MMIO32(UDMA0 + 0x02c)
// Set the appropriate bit to disable the corresponding uDMA channel. CHNLS

/* Channel Set Primary-Alternate */
#define SETCHNLPRIALT       MMIO32(UDMA0 + 0x030)
// Returns the channel control data structure status, or selects the alternate
// data structure for the corresponding uDMA channel. CHNLS

/* Channel Clear Primary-Alternate */
#define CLEARCHNLPRIALT     MMIO32(UDMA0 + 0x034)
// Clears the appropriate bit to select the primary data structure for the
// corresponding uDMA channel. CHNLS

/* Set Channel Priority */
#define SETCHNLPRIORITY     MMIO32(UDMA0 + 0x038)
// Returns the channel priority mask status, or sets the channel priority to
// high. CHNLS

/* Clear Channel Priority */
#define CLEARCHNLPRIORITY   MMIO32(UDMA0 + 0x03c)
// Clear the appropriate bit to select the default priority level for the
// specified uDMA channel. CHNLS

/* Error Status and Clear */
#define ERROR               MMIO32(UDMA0 + 0x04c)
// Returns the status of bus error flag in uDMA, or clears this bit
#define STATUS  0x00000001

/* Channel Request Done */
#define REQDONE             MMIO32(UDMA0 + 0x504)
// Reflects the uDMA done status for the given channel, channel [Ch]. It's a
// sticky done bit. Unless cleared by writing a 1, it holds the value of 1.

/* Channel Request Done Mask */
#define DONEMASK            MMIO32(UDMA0 + 0x520)
// Controls the propagation of the uDMA done and active state to the assigned
// peripheral. Specifically used for software channels. CHNLS

#endif
