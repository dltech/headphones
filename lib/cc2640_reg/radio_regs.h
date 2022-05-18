#ifndef H_RADIO_REGS
#define H_RADIO_REGS
/*
 * Simple CC2640 headphones
 * radio registers
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

/* Radio Timer Counter Value */
#define RATCNT      MMIO32(RFC_RAT + 0x04)

/* Timer Channel 0 Capture/Compare Register */
#define RATCH0VAL	MMIO32(RFC_RAT + 0x80)
/* Timer Channel 1 Capture/Compare Register */
#define RATCH1VAL	MMIO32(RFC_RAT + 0x84)
/* Timer Channel 2 Capture/Compare Register */
#define RATCH2VAL	MMIO32(RFC_RAT + 0x88)
/* Timer Channel 3 Capture/Compare Register */
#define RATCH3VAL	MMIO32(RFC_RAT + 0x8c)
/* Timer Channel 4 Capture/Compare Register */
#define RATCH4VAL	MMIO32(RFC_RAT + 0x90)
/* Timer Channel 5 Capture/Compare Register */
#define RATCH5VAL	MMIO32(RFC_RAT + 0x94)
/* Timer Channel 6 Capture/Compare Register */
#define RATCH6VAL	MMIO32(RFC_RAT + 0x98)
/* Timer Channel 7 Capture/Compare Register */
#define RATCH7VAL	MMIO32(RFC_RAT + 0x9c)

/* Doorbell Command Register */
#define CMDR        MMIO32(RFC_DBELL + 0x00)
// Raises an interrupt to the Command and packet engine (CPE) upon write.

/* Doorbell Command Status Register */
#define CMDSTA      MMIO32(RFC_DBELL + 0x04)
// Status of the last command used

/* Interrupt Flags From RF Hardware Modules */
#define RFHWIFG     MMIO32(RFC_DBELL + 0x08)
// Radio timer channel 7 interrupt flag.
#define RATCH7      0x80000
// Radio timer channel 6 interrupt flag.
#define RATCH6      0x40000
// Radio timer channel 5 interrupt flag.
#define RATCH5      0x20000
// Radio timer channel 4 interrupt flag.
#define RATCH4      0x10000
// Radio timer channel 3 interrupt flag.
#define RATCH3      0x08000
// Radio timer channel 2 interrupt flag.
#define RATCH2      0x04000
// Radio timer channel 1 interrupt flag.
#define RATCH1      0x02000
// Radio timer channel 0 interrupt flag.
#define RATCH0      0x01000
// RF engine software defined interrupt 2 flag.
#define RFESOFT2    0x00800
// RF engine software defined interrupt 1 flag.
#define RFESOFT1    0x00400
// RF engine software defined interrupt 0 flag.
#define RFESOFT0    0x00200
// RF engine command done interrupt flag.
#define RFEDONE     0x00100
// Debug tracer system tick interrupt flag.
#define TRCTK       0x00040
// Modem synchronization word detection interrupt flag.
#define MDMSOFT     0x00020
// Modem FIFO output interrupt flag.
#define MDMOUT      0x00010
// Modem FIFO input interrupt flag.
#define MDMIN       0x00008
// Modem command done interrupt flag.
#define MDMDONE     0x00004
// Frequency synthesizer calibration accelerator interrupt flag.
#define FSCA        0x00002

/* Interrupt Enable For RF Hardware Modules */
#define RFHWIEN     MMIO32(RFC_DBELL + 0x0c)
// Interrupt enable for RFHWIFG.RATCH7.
// Interrupt enable for RFHWIFG.RATCH6.
// Interrupt enable for RFHWIFG.RATCH5.
// Interrupt enable for RFHWIFG.RATCH4.
// Interrupt enable for RFHWIFG.RATCH3.
// Interrupt enable for RFHWIFG.RATCH2.
// Interrupt enable for RFHWIFG.RATCH1.
// Interrupt enable for RFHWIFG.RATCH0.
// Interrupt enable for RFHWIFG.RFESOFT2.
// Interrupt enable for RFHWIFG.RFESOFT1.
// Interrupt enable for RFHWIFG.RFESOFT0.
// Interrupt enable for RFHWIFG.RFEDONE.
// Interrupt enable for RFHWIFG.TRCTK.
// Interrupt enable for RFHWIFG.MDMSOFT.
// Interrupt enable for RFHWIFG.MDMOUT.
// Interrupt enable for RFHWIFG.MDMIN.
// Interrupt enable for RFHWIFG.MDMDONE.
// Interrupt enable for RFHWIFG.FSCA.

/* Interrupt Flags For Command and Packet Engine Generated Interrupts */
#define RFCPEIFG    MMIO32(RFC_DBELL + 0x10)
// The command and packet engine (CPE) has observed an unexpected error.
#define INTERNAL_ERROR          0x80000000
// The command and packet engine (CPE) boot is finished.
#define BOOT_DONE               0x40000000
// it has opened access to RF Core modules and memories.
#define MODULES_UNLOCKED        0x20000000
// The phase-locked loop in frequency synthesizer has reported loss of lock.
#define SYNTH_NO_LOCK           0x10000000
// Interrupt flag 27.
#define IRQ27                   0x08000000
// Packet reception stopped before packet was done.
#define RX_ABORTED              0x04000000
// Specified number of bytes written to partial read Rx buffer.
#define RX_N_DATA_WRITTEN       0x02000000
// Data written to partial read Rx buffer.
#define RX_DATA_WRITTEN         0x01000000
// Rx queue data entry changing state to finished.
#define RX_ENTRY_DONE           0x00800000
// Packet received that did not fit in Rx queue.
#define RX_BUF_FULL             0x00400000
// LL control packet received with CRC OK
#define RX_CTRL_ACK             0x00200000
// LL control packet received with CRC OK, not to be ignored.
#define RX_CTRL                 0x00100000
// Packet received with CRC OK, not to be ignored, no payload.
#define RX_EMPTY                0x00080000
// Packet received, but can be ignored.
#define RX_IGNORED              0x00040000
// acket received with CRC error.
#define RX_NOK                  0x00020000
// Packet received correctly.
#define RX_OK                   0x00010000
// Interrupt flag 15.
#define IRQ15                   0x00008000
// Interrupt flag 14.
#define IRQ14                   0x00004000
// Interrupt flag 13.
#define IRQ13                   0x00002000
// Interrupt flag 12.
#define IRQ12                   0x00001000
// A buffer change is complete after CMD_BLE_ADV_PAYLOAD.
#define TX_BUFFER_CHANGED       0x00000800
// Tx queue data entry state changed to finished.
#define TX_ENTRY_DONE           0x00000400
// Packet retransmitted.
#define TX_RETRANS              0x00000200
// Acknowledgement received on a transmitted LL control packet and ack transmitted
#define TX_CTRL_ACK_ACK         0x00000100
// Acknowledgement received on a transmitted LL control packet.
#define TX_CTRL_ACK             0x00000080
// Transmitted LL control packet.
#define TX_CTRL                 0x00000040
// Acknowledgement received on a transmitted packet.
#define TX_ACK                  0x00000020
// Packet transmitted.
#define TX_DONE                 0x00000010
// The last foreground radio operation command in a chain of commands has finished.
#define LAST_FG_COMMAND_DONE    0x00000008
// A foreground radio operation command has finished.
#define FG_COMMAND_DONE         0x00000004
// The last radio operation command in a chain of commands has finished.
#define LAST_COMMAND_DONE       0x00000002
// A radio operation has finished.
#define COMMAND_DONE            0x00000001

/* Interrupt Enable For Command and Packet Engine Generated Interrupts */
#define RFCPEIEN    MMIO32(RFC_DBELL + 0x14)
// Interrupt enable for RFCPEIFG.INTERNAL_ERROR.
// Interrupt enable for RFCPEIFG.BOOT_DONE.
// Interrupt enable for RFCPEIFG.MODULES_UNLOCKED.
// Interrupt enable for RFCPEIFG.SYNTH_NO_LOCK.
// Interrupt enable for RFCPEIFG.IRQ27.
// Interrupt enable for RFCPEIFG.RX_ABORTED.
// Interrupt enable for RFCPEIFG.RX_N_DATA_WRITTEN.
// Interrupt enable for RFCPEIFG.RX_DATA_WRITTEN.
// Interrupt enable for RFCPEIFG.RX_ENTRY_DONE.
// Interrupt enable for RFCPEIFG.RX_BUF_FULL.
// Interrupt enable for RFCPEIFG.RX_CTRL_ACK.
// Interrupt enable for RFCPEIFG.RX_CTRL.
// Interrupt enable for RFCPEIFG.RX_EMPTY.
// Interrupt enable for RFCPEIFG.RX_IGNORED.
// Interrupt enable for RFCPEIFG.RX_NOK.
// Interrupt enable for RFCPEIFG.RX_OK.
// Interrupt enable for RFCPEIFG.IRQ15.
// Interrupt enable for RFCPEIFG.IRQ14.
// Interrupt enable for RFCPEIFG.IRQ13.
// Interrupt enable for RFCPEIFG.IRQ12.
// Interrupt enable for RFCPEIFG.TX_BUFFER_CHANGED.
// Interrupt enable for RFCPEIFG.TX_ENTRY_DONE.
// Interrupt enable for RFCPEIFG.TX_RETRANS.
// Interrupt enable for RFCPEIFG.TX_CTRL_ACK_ACK.
// Interrupt enable for RFCPEIFG.TX_CTRL_ACK.
// Interrupt enable for RFCPEIFG.TX_CTRL.
// Interrupt enable for RFCPEIFG.TX_ACK.
// Interrupt enable for RFCPEIFG.TX_DONE.
// Interrupt enable for RFCPEIFG.LAST_FG_COMMAND_DONE.
// Interrupt enable for RFCPEIFG.FG_COMMAND_DONE.
// Interrupt enable for RFCPEIFG.LAST_COMMAND_DONE.
// Interrupt enable for RFCPEIFG.COMMAND_DONE.

/* Interrupt Vector Selection For Command and Packet Engine Generated Interrupts */
#define RFCPEISL    MMIO32(RFC_DBELL + 0x18)
// Select which CPU interrupt vector the RFCPEIFG.INTERNAL_ERROR interrupt.
// Select which CPU interrupt vector theRFCPEIFG.BOOT_DONE interrupt.
// Select which CPU interrupt vector theRFCPEIFG.MODULES_UNLOCKED interrupt.
// Select which CPU interrupt vector theRFCPEIFG.SYNTH_NO_LOCK interrupt.
// Select which CPU interrupt vector theRFCPEIFG.IRQ27 interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_ABORTED interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_N_DATA_WRITTEN interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_DATA_WRITTEN interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_ENTRY_DONE interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_BUF_FULL interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_CTRL_ACK interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_CTRL interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_EMPTY interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_IGNORED interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_NOK interrupt.
// Select which CPU interrupt vector theRFCPEIFG.RX_OK interrupt.
// Select which CPU interrupt vector theRFCPEIFG.IRQ15 interrupt.
// Select which CPU interrupt vector theRFCPEIFG.IRQ14 interrupt.
// Select which CPU interrupt vector theRFCPEIFG.IRQ13 interrupt.
// Select which CPU interrupt vector theRFCPEIFG.IRQ12 interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_BUFFER_CHANGED interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_ENTRY_DONE interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_RETRANS interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_CTRL_ACK_ACK interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_CTRL_ACK interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_CTRL interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_ACK interrupt.
// Select which CPU interrupt vector theRFCPEIFG.TX_DONE interrupt.
// Select which CPU interrupt vector theRFCPEIFG.LAST_FG_COMMAND_DONE interrupt.
// Select which CPU interrupt vector theRFCPEIFG.FG_COMMAND_DONE interrupt.
// Select which CPU interrupt vector theRFCPEIFG.LAST_COMMAND_DONE interrupt.
// Select which CPU interrupt vector theRFCPEIFG.COMMAND_DONE interrupt.

/* Doorbell Command Acknowledgement Interrupt Flag */
#define RFACKIFG    MMIO32(RFC_DBELL + 0x1c)
// Interrupt flag for Command ACK
#define ACKFLAG 0x1

/* RF Core General Purpose Output Control */
#define SYSGPOCTL   MMIO32(RFC_DBELL + 0x20)
// Selects which signal to output on the RF Core GPO line 3.
#define GPOCTL3_CPE_GPO_0   0x0000
#define GPOCTL3_CPE_GPO_1   0x1000
#define GPOCTL3_CPE_GPO_2   0x2000
#define GPOCTL3_CPE_GPO_3   0x3000
#define GPOCTL3_MCE_GPO_0   0x4000
#define GPOCTL3_MCE_GPO_1   0x5000
#define GPOCTL3_MCE_GPO_2   0x6000
#define GPOCTL3_MCE_GPO_3   0x7000
#define GPOCTL3_RFE_GPO_0   0x8000
#define GPOCTL3_RFE_GPO_1   0x9000
#define GPOCTL3_RFE_GPO_2   0xa000
#define GPOCTL3_RFE_GPO_3   0xb000
#define GPOCTL3_RAT_GPO_0   0xc000
#define GPOCTL3_RAT_GPO_1   0xd000
#define GPOCTL3_RAT_GPO_2   0xe000
#define GPOCTL3_RAT_GPO_3   0xf000
// Selects which signal to output on the RF Core GPO line 2.
#define GPOCTL2_CPE_GPO_0   0x0000
#define GPOCTL2_CPE_GPO_1   0x0100
#define GPOCTL2_CPE_GPO_2   0x0200
#define GPOCTL2_CPE_GPO_3   0x0300
#define GPOCTL2_MCE_GPO_0   0x0400
#define GPOCTL2_MCE_GPO_1   0x0500
#define GPOCTL2_MCE_GPO_2   0x0600
#define GPOCTL2_MCE_GPO_3   0x0700
#define GPOCTL2_RFE_GPO_0   0x0800
#define GPOCTL2_RFE_GPO_1   0x0900
#define GPOCTL2_RFE_GPO_2   0x0a00
#define GPOCTL2_RFE_GPO_3   0x0b00
#define GPOCTL2_RAT_GPO_0   0x0c00
#define GPOCTL2_RAT_GPO_1   0x0d00
#define GPOCTL2_RAT_GPO_2   0x0e00
#define GPOCTL2_RAT_GPO_3   0x0f00
// Selects which signal to output on the RF Core GPO line 1.
#define GPOCTL1_CPE_GPO_0   0x0000
#define GPOCTL1_CPE_GPO_1   0x0010
#define GPOCTL1_CPE_GPO_2   0x0020
#define GPOCTL1_CPE_GPO_3   0x0030
#define GPOCTL1_MCE_GPO_0   0x0040
#define GPOCTL1_MCE_GPO_1   0x0050
#define GPOCTL1_MCE_GPO_2   0x0060
#define GPOCTL1_MCE_GPO_3   0x0070
#define GPOCTL1_RFE_GPO_0   0x0080
#define GPOCTL1_RFE_GPO_1   0x0090
#define GPOCTL1_RFE_GPO_2   0x00a0
#define GPOCTL1_RFE_GPO_3   0x00b0
#define GPOCTL1_RAT_GPO_0   0x00c0
#define GPOCTL1_RAT_GPO_1   0x00d0
#define GPOCTL1_RAT_GPO_2   0x00e0
#define GPOCTL1_RAT_GPO_3   0x00f0
// Selects which signal to output on the RF Core GPO line 0.
#define GPOCTL0_CPE_GPO_0   0x0000
#define GPOCTL0_CPE_GPO_1   0x0001
#define GPOCTL0_CPE_GPO_2   0x0002
#define GPOCTL0_CPE_GPO_3   0x0003
#define GPOCTL0_MCE_GPO_0   0x0004
#define GPOCTL0_MCE_GPO_1   0x0005
#define GPOCTL0_MCE_GPO_2   0x0006
#define GPOCTL0_MCE_GPO_3   0x0007
#define GPOCTL0_RFE_GPO_0   0x0008
#define GPOCTL0_RFE_GPO_1   0x0009
#define GPOCTL0_RFE_GPO_2   0x000a
#define GPOCTL0_RFE_GPO_3   0x000b
#define GPOCTL0_RAT_GPO_0   0x000c
#define GPOCTL0_RAT_GPO_1   0x000d
#define GPOCTL0_RAT_GPO_2   0x000e
#define GPOCTL0_RAT_GPO_3   0x000f

/* RF Core Power Management and Clock Enable */
#define PWMCLKEN    MMIO32(RFC_PWR + 0x00)
// Enable clock to the RF Core Tracer (RFCTRC) module.
#define RFCTRC  0x200
// Enable clock to the Frequency Synthesizer Calibration Accelerator
#define FSCA    0x100
// Enable clock to the Packet Handling Accelerator (PHA) module.
#define PHA     0x080
// Enable clock to the Radio Timer (RAT) module.
#define RAT     0x040
// Enable clock to the RF Engine RAM module.
#define RFERAM  0x020
// Enable clock to the RF Engine (RFE) module.
#define RFE     0x010
// Enable clock to the Modem RAM module.
#define MDMRAM  0x010
// Enable clock to the Modem (MDM) module.
#define MDM     0x008
// Enable clock to the Command and Packet Engine (CPE) RAM module.
#define CPERAM  0x004
// Enable processor clock (hclk) to the Command and Packet Engine (CPE).
#define CPE     0x002
// Enable essential clocks for the RF Core interface.
#define RFC     0x001

#endif
