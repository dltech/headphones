#ifndef H_TIMER_REGS
#define H_TIMER_REGS
/*
 * Simple CC2640 headphones
 * timer registers
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
#define CFG0         MMIO32(GPT0 + 0x000)
#define CFG1         MMIO32(GPT1 + 0x000)
#define CFG2         MMIO32(GPT2 + 0x000)
#define CFG3         MMIO32(GPT3 + 0x000)
// GPT Configuration
#define CFG_32BIT   0x00000000
#define CFG_16BIT   0x00000004

/* Timer A Mode */
#define TAMR0        MMIO32(GPT0 + 0x004)
#define TAMR1        MMIO32(GPT1 + 0x004)
#define TAMR2        MMIO32(GPT2 + 0x004)
#define TAMR3        MMIO32(GPT3 + 0x004)
// Timer Compare Action Select
#define TCACT_DIS_CMP                           0x0000
#define TCACT_DIS_TOUT_TOGGLE                   0x2000
#define TCACT_DIS_TOUT_CLEAR                    0x4000
#define TCACT_DIS_TOUT_SET                      0x6000
#define TCACT_DIS_TOUT_TOGGLE_SET_IMMEDIATELY   0x8000
#define TCACT_DIS_TOUT_TOGGLE_CLEAR_IMMEDIATELY 0xa000
#define TCACT_DIS_TOUT_CLEAR_SET_IMMEDIATELY    0xc000
#define TCACT_DIS_TOUT_SET_CLEAR_IMMEDIATELY    0xe000
// One-Shot/Periodic Interrupt Disable
#define TACINTD                                 0x1000
// GPTM Timer A PWM Legacy Operation
#define TAPLO                                   0x0800
// Timer A Match Register Update mode
#define TAMRSU                                  0x0400
// GPTM Timer A PWM Interrupt Enable
#define TAPWMIE                                 0x0200
// GPT Timer A PWM Interval Load Write
#define TAILD                                   0x0100
// GPT Timer A Snap-Shot Mode
#define TASNAPS                                 0x0080
// GPT Timer A Wait-On-Trigger
#define TAWOT                                   0x0040
// GPT Timer A Match Interrupt Enable
#define TAMIE                                   0x0020
// GPT Timer A Count Direction
#define TACDIR                                  0x0010
// GPT Timer A Alternate Mode
#define TAAMS                                   0x0008
// GPT Timer A Capture Mode
#define TACM                                    0x0004
// GPT Timer A Mode
#define TAMR_ONE_SHOT   0x1
#define TAMR_PERIODIC   0x2
#define TAMR_CAPTURE    0x3

/* Timer B Mode */
#define TBMR0        MMIO32(GPT0 + 0x008)
#define TBMR1        MMIO32(GPT1 + 0x008)
#define TBMR2        MMIO32(GPT2 + 0x008)
#define TBMR3        MMIO32(GPT3 + 0x008)
// Timer Compare Action Select
// One-Shot/Periodic Interrupt Disable
#define TBCINTD                                 0x1000
// GPTM Timer B PWM Legacy Operation
#define TBPLO                                   0x0800
// Timer B Match Register Update mode
#define TBMRSU                                  0x0400
// GPTM Timer B PWM Interrupt Enable
#define TBPWMIE                                 0x0200
// GPT Timer B PWM Interval Load Write
#define TBILD                                   0x0100
// GPT Timer B Snap-Shot Mode
#define TBSNAPS                                 0x0080
// GPT Timer B Wait-On-Trigger
#define TBWOT                                   0x0040
// GPT Timer B Match Interrupt Enable
#define TBMIE                                   0x0020
// GPT Timer B Count Direction
#define TBCDIR                                  0x0010
// GPT Timer B Alternate Mode
#define TBAMS                                   0x0008
// GPT Timer B Capture Mode
#define TBCM                                    0x0004
// GPT Timer B Mode
#define TBMR_ONE_SHOT                           0x1
#define TBMR_PERIODIC                           0x2
#define TBMR_CAPTURE                            0x3

/* Control */
#define CTL0         MMIO32(GPT0 + 0x00c)
#define CTL1         MMIO32(GPT1 + 0x00c)
#define CTL2         MMIO32(GPT2 + 0x00c)
#define CTL3         MMIO32(GPT3 + 0x00c)
// GPT Timer B PWM Output Level
#define TBPWML                  0x4000
// GPT Timer B Event Mode
#define TBEVENT_POSITIVE_EDGE   0x0000
#define TBEVENT_NEGATIVE_EDGE   0x0400
#define TBEVENT_BOTH_EDGES      0x0c00
// GPT Timer B Stall Enable
#define TBSTALL                 0x0200
// GPT Timer B Enable
#define TBEN                    0x0100
// GPT Timer A PWM Output Level
#define TAPWML                  0x0040
// GPT Timer A Event Mode
#define TAEVENT_POSITIVE_EDGE   0x0000
#define TAEVENT_NEGATIVE_EDGE   0x0004
#define TAEVENT_BOTH_EDGES      0x000c
// GPT Timer A Stall Enable
#define TASTALL                 0x0002
// GPT Timer A Enable
#define TAEN                    0x0001

/* Synch Register */
#define SYNC0        MMIO32(GPT0 + 0x010)
#define SYNC1        MMIO32(GPT1 + 0x010)
#define SYNC2        MMIO32(GPT2 + 0x010)
#define SYNC3        MMIO32(GPT3 + 0x010)
// Synchronize GPT Timer 3.
#define SYNC3_NO    0x00
#define SYNC3_TOUTA 0x40
#define SYNC3_TOUTB 0x80
#define SYNC3_BOTH  0xc0
// Synchronize GPT Timer 2.
#define SYNC2_NO    0x00
#define SYNC2_TOUTA 0x10
#define SYNC2_TOUTB 0x20
#define SYNC2_BOTH  0x30
// Synchronize GPT Timer 1.
#define SYNC1_NO    0x00
#define SYNC1_TOUTA 0x04
#define SYNC1_TOUTB 0x08
#define SYNC1_BOTH  0x0c
// Synchronize GPT Timer 0.
#define SYNC0_NO    0x00
#define SYNC0_TOUTA 0x01
#define SYNC0_TOUTB 0x02
#define SYNC0_BOTH  0x03

/* Interrupt Mask */
#define IMR0         MMIO32(GPT0 + 0x018)
#define IMR1         MMIO32(GPT1 + 0x018)
#define IMR2         MMIO32(GPT2 + 0x018)
#define IMR3         MMIO32(GPT3 + 0x018)
// Enabling this bit will make the RIS.DMABRIS interrupt propagate to MIS.DMABMIS
#define DMABIM  0x2000
// Enabling this bit will make the RIS.TBMRIS interrupt propagate to MIS.TBMMIS
#define TBMIM   0x0800
// Enabling this bit will make the RIS.CBERIS interrupt propagate to MIS.CBEMIS
#define CBEIM   0x0400
// Enabling this bit will make the RIS.CBMRIS interrupt propagate to MIS.CBMMIS
#define CBMIM   0x0200
// Enabling this bit will make the RIS.TBTORIS interrupt propagate to MIS.TBTOMIS
#define TBTOIM  0x0100
// Enabling this bit will make the RIS.DMAARIS interrupt propagate to MIS.DMAAMIS
#define DMAAIM  0x0020
// Enabling this bit will make the RIS.TAMRIS interrupt propagate to MIS.TAMMIS
#define TAMIM   0x0010
// Enabling this bit will make the RIS.CAERIS interrupt propagate to MIS.CAEMIS
#define CAEIM   0x0004
// Enabling this bit will make the RIS.CAMRIS interrupt propagate to MIS.CAMMIS
#define CAMIM   0x0002
// Enabling this bit will make the RIS.TATORIS interrupt propagate to MIS.TATOMIS
#define TATOIM  0x0001

/* Raw Interrupt Status */
#define RIS0         MMIO32(GPT0 + 0x01c)
#define RIS1         MMIO32(GPT1 + 0x01c)
#define RIS2         MMIO32(GPT2 + 0x01c)
#define RIS3         MMIO32(GPT3 + 0x01c)
// GPT Timer B DMA Done Raw Interrupt Status
#define DMABRIS 0x2000
// GPT Timer B Match Raw Interrupt
#define TBMRIS  0x0800
// GPT Timer B Capture Mode Event Raw Interrupt
#define CBERIS  0x0400
// GPT Timer B Capture Mode Match Raw Interrupt
#define CBMRIS  0x0200
// GPT Timer B Time-out Raw Interrupt
#define TBTORIS 0x0100
// GPT Timer A DMA Done Raw Interrupt Status
#define DMAARIS 0x0020
// GPT Timer A Match Raw Interrupt
#define TAMRIS  0x0010
// GPT Timer A Capture Mode Event Raw Interrupt
#define CAERIS  0x0004
// GPT Timer A Capture Mode Match Raw Interrupt
#define CAMRIS  0x0002
// GPT Timer A Time-out Raw Interrupt
#define TATORIS 0x0001

/* Masked Interrupt Status */
#define MIS0         MMIO32(GPT0 + 0x020)
#define MIS1         MMIO32(GPT1 + 0x020)
#define MIS2         MMIO32(GPT2 + 0x020)
#define MIS3         MMIO32(GPT3 + 0x020)
// GPT Timer B DMA Done Masked Interrupt Status
#define DMABMIS 0x2000
// GPT Timer B Match Masked Interrupt
#define TBMMIS  0x0800
// GPT Timer B Capture Mode Event Masked Interrupt
#define CBEMIS  0x0400
// GPT Timer B Capture Mode Match Masked Interrupt
#define CBMMIS  0x0200
// GPT Timer B Time-out Masked Interrupt
#define TBTOMIS 0x0100
// GPT Timer A DMA Done Masked Interrupt Status
#define DMAAMIS 0x0020
// GPT Timer A Match Masked Interrupt
#define TAMMIS  0x0010
// GPT Timer A Capture Mode Event Masked Interrupt
#define CAEMIS  0x0004
// GPT Timer A Capture Mode Match Masked Interrupt
#define CAMMIS  0x0002
// GPT Timer A Time-out Masked Interrupt
#define TATOMIS 0x0001

/* Interrupt Clear */
#define ICLR0        MMIO32(GPT0 + 0x024)
#define ICLR1        MMIO32(GPT1 + 0x024)
#define ICLR2        MMIO32(GPT2 + 0x024)
#define ICLR3        MMIO32(GPT3 + 0x024)
// GPT Timer B DMA Done Interrupt Status clear
#define DMABINT     0x2000
// GPT Timer B Match Interrupt clear
#define TBMCINT     0x0800
// GPT Timer B Capture Mode Event Interrupt clear
#define CBECINT     0x0400
// GPT Timer B Capture Mode Match Interrupt clear
#define CBMCINT     0x0200
// GPT Timer B Time-out Interrupt clear
#define TBTOCINT    0x0100
// GPT Timer A DMA Done Interrupt Status clear
#define DMAAINT     0x0020
// GPT Timer A Match Interrupt clear
#define TAMCINT     0x0010
// GPT Timer A Capture Mode Event Interrupt clear
#define CAECINT     0x0004
// GPT Timer A Capture Mode Match Interrupt clear
#define CAMCINT     0x0002
// GPT Timer A Time-out Interrupt clear
#define TATOCINT    0x0001

/* Timer A Interval Load Register */
#define TAILR0       MMIO32(GPT0 + 0x028)
#define TAILR1       MMIO32(GPT1 + 0x028)
#define TAILR2       MMIO32(GPT2 + 0x028)
#define TAILR3       MMIO32(GPT3 + 0x028)
// GPT Timer A Interval Load Register

/* Timer B Interval Load Register */
#define TBILR0       MMIO32(GPT0 + 0x02c)
#define TBILR1       MMIO32(GPT1 + 0x02c)
#define TBILR2       MMIO32(GPT2 + 0x02c)
#define TBILR3       MMIO32(GPT3 + 0x02c)
// GPT Timer B Interval Load Register

/* Timer A Match Register */
#define TAMATCHR0    MMIO32(GPT0 + 0x030)
#define TAMATCHR1    MMIO32(GPT1 + 0x030)
#define TAMATCHR2    MMIO32(GPT2 + 0x030)
#define TAMATCHR3    MMIO32(GPT3 + 0x030)

/* Timer B Match Register */
#define TBMATCHR0    MMIO32(GPT0 + 0x034)
#define TBMATCHR1    MMIO32(GPT1 + 0x034)
#define TBMATCHR2    MMIO32(GPT2 + 0x034)
#define TBMATCHR3    MMIO32(GPT3 + 0x034)

/* Timer A Pre-scale */
#define TAPR0        MMIO32(GPT0 + 0x038)
#define TAPR1        MMIO32(GPT1 + 0x038)
#define TAPR2        MMIO32(GPT2 + 0x038)
#define TAPR3        MMIO32(GPT3 + 0x038)
#define TAPSR_MSK   0xff

/* Timer B Pre-scale */
#define TBPR0        MMIO32(GPT0 + 0x03c)
#define TBPR1        MMIO32(GPT1 + 0x03c)
#define TBPR2        MMIO32(GPT2 + 0x03c)
#define TBPR3        MMIO32(GPT3 + 0x03c)
#define TBPSR_MSK   0xff

/* Timer A Pre-scale Match */
#define TAPMR0       MMIO32(GPT0 + 0x040)
#define TAPMR1       MMIO32(GPT1 + 0x040)
#define TAPMR2       MMIO32(GPT2 + 0x040)
#define TAPMR3       MMIO32(GPT3 + 0x040)
// In 16 bit mode this field holds bits 23 to 16.
#define TAPSMR_MSK   0xff

/* Timer B Pre-scale Match */
#define TBPMR0       MMIO32(GPT0 + 0x044)
#define TBPMR1       MMIO32(GPT1 + 0x044)
#define TBPMR2       MMIO32(GPT2 + 0x044)
#define TBPMR3       MMIO32(GPT3 + 0x044)
// In 16 bit mode this field holds bits 23 to 16.
#define TBPSMR_MSK   0xff

/* Timer A Register */
#define TAR0         MMIO32(GPT0 + 0x048)
#define TAR1         MMIO32(GPT1 + 0x048)
#define TAR2         MMIO32(GPT2 + 0x048)
#define TAR3         MMIO32(GPT3 + 0x048)
// GPT Timer A Register

/* Timer B Register */
#define TBR0         MMIO32(GPT0 + 0x04c)
#define TBR1         MMIO32(GPT1 + 0x04c)
#define TBR2         MMIO32(GPT2 + 0x04c)
#define TBR3         MMIO32(GPT3 + 0x04c)
// GPT Timer B Register

/* Timer A Value */
#define TAV0         MMIO32(GPT0 + 0x050)
#define TAV1         MMIO32(GPT1 + 0x050)
#define TAV2         MMIO32(GPT2 + 0x050)
#define TAV3         MMIO32(GPT3 + 0x050)
// GPT Timer A Register

/* Timer B Value */
#define TBV0         MMIO32(GPT0 + 0x054)
#define TBV1         MMIO32(GPT1 + 0x054)
#define TBV2         MMIO32(GPT2 + 0x054)
#define TBV3         MMIO32(GPT3 + 0x054)
// GPT Timer B Register

/* Timer A Pre-scale Snap-shot */
#define TAPS0        MMIO32(GPT0 + 0x05c)
#define TAPS1        MMIO32(GPT1 + 0x05c)
#define TAPS2        MMIO32(GPT2 + 0x05c)
#define TAPS3        MMIO32(GPT3 + 0x05c)
// GPT Timer A Pre-scaler
#define PSS_MSK   0xff

/* Timer B Pre-scale Snap-shot */
#define TBPS0        MMIO32(GPT0 + 0x060)
#define TBPS1        MMIO32(GPT1 + 0x060)
#define TBPS2        MMIO32(GPT2 + 0x060)
#define TBPS3        MMIO32(GPT3 + 0x060)
// GPT Timer B Pre-scaler

/* Timer A Pre-scale Value */
#define TAPV0        MMIO32(GPT0 + 0x064)
#define TAPV1        MMIO32(GPT1 + 0x064)
#define TAPV2        MMIO32(GPT2 + 0x064)
#define TAPV3        MMIO32(GPT3 + 0x064)
// GPT Timer A Pre-scaler Value
#define PSV_MSK   0xff

/* Timer B Pre-scale Value */
#define TBPV0        MMIO32(GPT0 + 0x068)
#define TBPV1        MMIO32(GPT1 + 0x068)
#define TBPV2        MMIO32(GPT2 + 0x068)
#define TBPV3        MMIO32(GPT3 + 0x068)
// GPT Timer B Pre-scaler Value

/* DMA Event */
#define DMAEV0       MMIO32(GPT0 + 0x06c)
#define DMAEV1       MMIO32(GPT1 + 0x06c)
#define DMAEV2       MMIO32(GPT2 + 0x06c)
#define DMAEV3       MMIO32(GPT3 + 0x06c)
// GPT Timer B Match DMA Trigger Enable
#define TBMDMAEN    0x800
// GPT Timer B Capture Event DMA Trigger Enable
#define CBEDMAEN    0x400
// GPT Timer B Capture Match DMA Trigger Enable
#define CBMDMAEN    0x200
// GPT Timer B Time-Out DMA Trigger Enable
#define TBTODMAEN   0x100
// GPT Timer A Match DMA Trigger Enable
#define TAMDMAEN    0x010
// GPT Timer A Capture Event DMA Trigger Enable
#define CAEDMAEN    0x004
// GPT Timer A Capture Match DMA Trigger Enable
#define CAMDMAEN    0x002
// GPT Timer A Time-Out DMA Trigger Enable
#define TATODMAEN   0x001

/* Peripheral Version */
#define VERSION0     MMIO32(GPT0 + 0xfb0)
#define VERSION1     MMIO32(GPT1 + 0xfb0)
#define VERSION2     MMIO32(GPT2 + 0xfb0)
#define VERSION3     MMIO32(GPT3 + 0xfb0)
// Timer Revision.

/* Combined CCP Output */
#define ANDCCP0      MMIO32(GPT0 + 0xfb4)
#define ANDCCP1      MMIO32(GPT1 + 0xfb4)
#define ANDCCP2      MMIO32(GPT2 + 0xfb4)
#define ANDCCP3      MMIO32(GPT3 + 0xfb4)
// Enables AND operation of the CCP outputs for timers A and B.
#define CCP_AND_EN   0x1

#endif
