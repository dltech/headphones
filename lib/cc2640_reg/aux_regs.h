#ifndef H_AUX_REGS
#define H_AUX_REGS
/*
 * Simple CC2640 headphones
 * AUX – Sensor Controller with Digital and Analog Peripherals registers
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

/* MUX0 Register */
#define MUX0            MMIO32(AUX_ADI4 + 0x0)
//...
#define COMPA_REF_MSK   0xf
#define COMPA_REF_SFT   0

/* MUX1 Register */
#define MUX1            MMIO32(AUX_ADI4 + 0x1)
//COMPA_IN

/* MUX2 Register */
#define MUX2            MMIO32(AUX_ADI4 + 0x2)
//...
#define ADCCOMPB_IN_MSK 0x1f
#define ADCCOMPB_IN_SFT 3
//...
#define COMPB_REF_MSK   0x7
#define COMPB_REF_SFT   0

/* MUX3 Register */
#define MUX3            MMIO32(AUX_ADI4 + 0x3)
// ADCCOMPB_IN

/* Strength and trim control for current source. */
#define ISRC            MMIO32(AUX_ADI4 + 0x4)
// Adjust current from current source.
#define TRIM_NO     0x00
#define TRIM_0P25U  0x04
#define TRIM_0P5U   0x08
#define TRIM_1P0U   0x10
#define TRIM_2P0U   0x20
#define TRIM_4P5U   0x40
#define TRIM_11P75U 0x80
// Current source enable.
#define COMPB_REF_MSK   0x7

/* Control COMPA and COMPB comparators. */
#define COMP            MMIO32(AUX_ADI4 + 0x5)
// Enables 400kohm resistance from COMPA reference node to ground.
#define COMPA_REF_RES_EN    0x80
// Enables 2uA IPTAT current from ISRC to COMPA reference node.
#define COMPA_REF_CURR_EN   0x40
// COMPB voltage reference trim temperature coded.
#define COMPB_TRIM_DIVNO    0x00
#define COMPB_TRIM_DIV2     0x08
#define COMPB_TRIM_DIV3     0x18
#define COMPB_TRIM_DIV4     0x38
// COMPB enable
#define COMPB_EN            0x04
// COMPA enable
#define COMPA_EN            0x01

/* MUX4 Register */
#define MUX4            MMIO32(AUX_ADI4 + 0x7)
// COMPA_REF

/* ADC Sample Control. */
#define ADC0            MMIO32(AUX_ADI4 + 0x8)
//  ADC Sampling mode: 1: Asynchronous mode, 0: Synchronous mode.
#define SMPL_MODE               0x80
// Controls the sampling duration before conversion when the ADC is operated.
#define SMPL_CYCLE_EXP_2P7US    0x18
#define SMPL_CYCLE_EXP_5P3US    0x20
#define SMPL_CYCLE_EXP_10P6US   0x28
#define SMPL_CYCLE_EXP_21P3US   0x30
#define SMPL_CYCLE_EXP_42P6US   0x38
#define SMPL_CYCLE_EXP_85P3US   0x40
#define SMPL_CYCLE_EXP_170US    0x48
#define SMPL_CYCLE_EXP_341US    0x50
#define SMPL_CYCLE_EXP_682US    0x58
#define SMPL_CYCLE_EXP_1P37MS   0x60
#define SMPL_CYCLE_EXP_2P73MS   0x68
#define SMPL_CYCLE_EXP_5P46MS   0x70
#define SMPL_CYCLE_EXP_10P9MS   0x78
// Reset ADC digital subchip, active low.
#define ADC_RESET_N             0x02
// ADC Enable
#define ADC_EN                  0x01

/* ADC Comparator Control. */
#define ADC1            MMIO32(AUX_ADI4 + 0x9)
//...
#define SCALE_DIS   0x1

/* Control reference used by the ADC. */
#define ADCREF0         MMIO32(AUX_ADI4 + 0xa)
// Keep ADCREF powered up in IDLE state when ADC0.SMPL_MODE = 0.
#define REF_ON_IDLE 0x40
//...
#define IOMUX       0x20
//...
#define EXT         0x10
// ADC reference source.
#define SRC         0x08
// ADC reference module enable.
#define ADC_REF_EN  0x01

/* Control reference used by the ADC. */
#define ADCREF0         MMIO32(AUX_ADI4 + 0xb)
// Trim output voltage of ADC fixed reference.
#define VTRIM_1P430V   0x00
#define VTRIM_1P435V   0x01
#define VTRIM_1P425V   0x3f
#define VTRIM_1P600V   0x1f
#define VTRIM_1P300V   0x20


/* General Purpose Input Output Data Out */
#define GPIODOUT0       MMIO32(AON_AIODIO0 + 0x00)
#define GPIODOUT1       MMIO32(AON_AIODIO1 + 0x00)
// Write 1 to bit index n in this bit vector to set AUXIO[8i+n].
#define IO7 0x80
#define IO6 0x40
#define IO5 0x20
#define IO4 0x10
#define IO3 0x08
#define IO2 0x04
#define IO1 0x02
#define IO0 0x01

/* Input Output Mode */
#define IOMODE0         MMIO32(AON_AIODIO0 + 0x04)
#define IOMODE1         MMIO32(AON_AIODIO1 + 0x04)
// Select mode for AUXIO[8i+7].
#define OUTPUT_IO(n)        (0x0<<(n*2))
#define INPUT_IO(n)         (0x1<<(n*2))
#define OD_IO(n)            (0x2<<(n*2))
#define OPEN_SOURSE_IO(n)   (0x3<<(n*2))

/* General Purpose Input Output Data In */
#define GPIODIN0        MMIO32(AON_AIODIO0 + 0x08)
#define GPIODIN1        MMIO32(AON_AIODIO1 + 0x08)
// IO7_0

/* General Purpose Input Output Data Out Set */
#define GPIODOUTSET0    MMIO32(AON_AIODIO0 + 0x0c)
#define GPIODOUTSET1    MMIO32(AON_AIODIO1 + 0x0c)
// IO7_0

/* General Purpose Input Output Data Out Clear */
#define GPIODOUTCLR0    MMIO32(AON_AIODIO0 + 0x10)
#define GPIODOUTCLR1    MMIO32(AON_AIODIO1 + 0x10)
// IO7_0

/* General Purpose Input Output Data Out Toggle */
#define GPIODOUTTGL0    MMIO32(AON_AIODIO0 + 0x14)
#define GPIODOUTTGL1    MMIO32(AON_AIODIO1 + 0x14)
// IO7_0

/* General Purpose Input Output Digital Input Enable */
#define GPIODIE0        MMIO32(AON_AIODIO0 + 0x18)
#define GPIODIE1        MMIO32(AON_AIODIO1 + 0x18)
// IO7_0


/* AUX_SCE wakeup vector 0 and 1 configuration */
#define VECCFG0         MMIO32(AUX_EVCTL + 0x00)
// Vector 1 trigger event polarity.
#define VEC1_POL    0x00004000
// Vector 1 trigger enable.
#define VEC1_EN     0x00002000
// Select vector 1 trigger source event.
#define VEC1_EV_AON_RTC_CH2                 0x0000
#define VEC1_EV_AON_AUX_COMPA               0x0100
#define VEC1_EV_AON_AUX_COMPB               0x0200
#define VEC1_EV_AON_TDC_DONE                0x0300
#define VEC1_EV_AON_TIMER0_EV               0x0400
#define VEC1_EV_AON_TIMER1_EV               0x0500
#define VEC1_EV_AON_SMPH_AUTOTAKE_DONE      0x0600
#define VEC1_EV_AON_ADC_DONE                0x0700
#define VEC1_EV_AON_ADC_FIFO_ALMOST_FULL    0x0800
#define VEC1_EV_AON_OBSMUX0                 0x0900
#define VEC1_EV_AON_OBSMUX1                 0x0a00
#define VEC1_EV_AON_AON_SW                  0x0b00
#define VEC1_EV_AON_AON_PROG_WU             0x0c00
#define VEC1_EV_AON_AUXIO0                  0x0d00
#define VEC1_EV_AON_AUXIO1                  0x0e00
#define VEC1_EV_AON_AUXIO2                  0x0f00
#define VEC1_EV_AON_AUXIO3                  0x1000
#define VEC1_EV_AON_AUXIO4                  0x1100
#define VEC1_EV_AON_AUXIO5                  0x1200
#define VEC1_EV_AON_AUXIO6                  0x1300
#define VEC1_EV_AON_AUXIO7                  0x1400
#define VEC1_EV_AON_AUXIO8                  0x1500
#define VEC1_EV_AON_AUXIO9                  0x1600
#define VEC1_EV_AON_AUXIO10                 0x1700
#define VEC1_EV_AON_AUXIO11                 0x1800
#define VEC1_EV_AON_AUXIO12                 0x1900
#define VEC1_EV_AON_AUXIO13                 0x1a00
#define VEC1_EV_AON_AUXIO14                 0x1b00
#define VEC1_EV_AON_AUXIO15                 0x1c00
#define VEC1_EV_AON_ACLK_REF                0x1d00
#define VEC1_EV_AON_MCU_EV                  0x1e00
#define VEC1_EV_AON_DC_IRQ                  0x1f00
// Vector 0 trigger event polarity.
#define VEC0_POL    0x00000040
// Vector 0 trigger enable.
#define VEC0_EN     0x00000020
// Select vector 0 trigger source event.
#define VEC0_EV_AON_RTC_CH2                 0x00
#define VEC0_EV_AON_AUX_COMPA               0x01
#define VEC0_EV_AON_AUX_COMPB               0x02
#define VEC0_EV_AON_TDC_DONE                0x03
#define VEC0_EV_AON_TIMER0_EV               0x04
#define VEC0_EV_AON_TIMER1_EV               0x05
#define VEC0_EV_AON_SMPH_AUTOTAKE_DONE      0x06
#define VEC0_EV_AON_ADC_DONE                0x07
#define VEC0_EV_AON_ADC_FIFO_ALMOST_FULL    0x08
#define VEC0_EV_AON_OBSMUX0                 0x09
#define VEC0_EV_AON_OBSMUX1                 0x0a
#define VEC0_EV_AON_AON_SW                  0x0b
#define VEC0_EV_AON_AON_PROG_WU             0x0c
#define VEC0_EV_AON_AUXIO0                  0x0d
#define VEC0_EV_AON_AUXIO1                  0x0e
#define VEC0_EV_AON_AUXIO2                  0x0f
#define VEC0_EV_AON_AUXIO3                  0x10
#define VEC0_EV_AON_AUXIO4                  0x11
#define VEC0_EV_AON_AUXIO5                  0x12
#define VEC0_EV_AON_AUXIO6                  0x13
#define VEC0_EV_AON_AUXIO7                  0x14
#define VEC0_EV_AON_AUXIO8                  0x15
#define VEC0_EV_AON_AUXIO9                  0x16
#define VEC0_EV_AON_AUXIO10                 0x17
#define VEC0_EV_AON_AUXIO11                 0x18
#define VEC0_EV_AON_AUXIO12                 0x19
#define VEC0_EV_AON_AUXIO13                 0x1a
#define VEC0_EV_AON_AUXIO14                 0x1b
#define VEC0_EV_AON_AUXIO15                 0x1c
#define VEC0_EV_AON_ACLK_REF                0x1d
#define VEC0_EV_AON_MCU_EV                  0x1e
#define VEC0_EV_AON_DC_IRQ                  0x1f

/* AUX_SCE event vectors 2 and 3 configuration */
#define VECCFG1         MMIO32(AUX_EVCTL + 0x04)
// Vector 3 trigger event polarity.
#define VEC3_POL    0x00004000
// Vector 3 trigger enable.
#define VEC3_EN     0x00002000
// Select vector 3 trigger source event.
#define VEC3_EV_AON_RTC_CH2                 0x0000
#define VEC3_EV_AON_AUX_COMPA               0x0100
#define VEC3_EV_AON_AUX_COMPB               0x0200
#define VEC3_EV_AON_TDC_DONE                0x0300
#define VEC3_EV_AON_TIMER0_EV               0x0400
#define VEC3_EV_AON_TIMER1_EV               0x0500
#define VEC3_EV_AON_SMPH_AUTOTAKE_DONE      0x0600
#define VEC3_EV_AON_ADC_DONE                0x0700
#define VEC3_EV_AON_ADC_FIFO_ALMOST_FULL    0x0800
#define VEC3_EV_AON_OBSMUX0                 0x0900
#define VEC3_EV_AON_OBSMUX1                 0x0a00
#define VEC3_EV_AON_AON_SW                  0x0b00
#define VEC3_EV_AON_AON_PROG_WU             0x0c00
#define VEC3_EV_AON_AUXIO0                  0x0d00
#define VEC3_EV_AON_AUXIO1                  0x0e00
#define VEC3_EV_AON_AUXIO2                  0x0f00
#define VEC3_EV_AON_AUXIO3                  0x1000
#define VEC3_EV_AON_AUXIO4                  0x1100
#define VEC3_EV_AON_AUXIO5                  0x1200
#define VEC3_EV_AON_AUXIO6                  0x1300
#define VEC3_EV_AON_AUXIO7                  0x1400
#define VEC3_EV_AON_AUXIO8                  0x1500
#define VEC3_EV_AON_AUXIO9                  0x1600
#define VEC3_EV_AON_AUXIO10                 0x1700
#define VEC3_EV_AON_AUXIO11                 0x1800
#define VEC3_EV_AON_AUXIO12                 0x1900
#define VEC3_EV_AON_AUXIO13                 0x1a00
#define VEC3_EV_AON_AUXIO14                 0x1b00
#define VEC3_EV_AON_AUXIO15                 0x1c00
#define VEC3_EV_AON_ACLK_REF                0x1d00
#define VEC3_EV_AON_MCU_EV                  0x1e00
#define VEC3_EV_AON_DC_IRQ                  0x1f00
// Vector 2 trigger event polarity.
#define VEC2_POL    0x00000040
// Vector 2 trigger enable.
#define VEC2_EN     0x00000020
// Select vector 2 trigger source event.
#define VEC2_EV_AON_RTC_CH2                 0x00
#define VEC2_EV_AON_AUX_COMPA               0x01
#define VEC2_EV_AON_AUX_COMPB               0x02
#define VEC2_EV_AON_TDC_DONE                0x03
#define VEC2_EV_AON_TIMER0_EV               0x04
#define VEC2_EV_AON_TIMER1_EV               0x05
#define VEC2_EV_AON_SMPH_AUTOTAKE_DONE      0x06
#define VEC2_EV_AON_ADC_DONE                0x07
#define VEC2_EV_AON_ADC_FIFO_ALMOST_FULL    0x08
#define VEC2_EV_AON_OBSMUX0                 0x09
#define VEC2_EV_AON_OBSMUX1                 0x0a
#define VEC2_EV_AON_AON_SW                  0x0b
#define VEC2_EV_AON_AON_PROG_WU             0x0c
#define VEC2_EV_AON_AUXIO0                  0x0d
#define VEC2_EV_AON_AUXIO1                  0x0e
#define VEC2_EV_AON_AUXIO2                  0x0f
#define VEC2_EV_AON_AUXIO3                  0x10
#define VEC2_EV_AON_AUXIO4                  0x11
#define VEC2_EV_AON_AUXIO5                  0x12
#define VEC2_EV_AON_AUXIO6                  0x13
#define VEC2_EV_AON_AUXIO7                  0x14
#define VEC2_EV_AON_AUXIO8                  0x15
#define VEC2_EV_AON_AUXIO9                  0x16
#define VEC2_EV_AON_AUXIO10                 0x17
#define VEC2_EV_AON_AUXIO11                 0x18
#define VEC2_EV_AON_AUXIO12                 0x19
#define VEC2_EV_AON_AUXIO13                 0x1a
#define VEC2_EV_AON_AUXIO14                 0x1b
#define VEC2_EV_AON_AUXIO15                 0x1c
#define VEC2_EV_AON_ACLK_REF                0x1d
#define VEC2_EV_AON_MCU_EV                  0x1e
#define VEC2_EV_AON_DC_IRQ                  0x1f

/* Sensor Controller Engine Wait Event Selection */
#define SCEWEVSEL       MMIO32(AUX_EVCTL + 0x08)
// Select event source to connect to AUX_SCE:WUSTAT.EV_SIGNALS bit 7.
#define WEV7_EV_AON_RTC_CH2                 0x00
#define WEV7_EV_AON_AUX_COMPA               0x01
#define WEV7_EV_AON_AUX_COMPB               0x02
#define WEV7_EV_AON_TDC_DONE                0x03
#define WEV7_EV_AON_TIMER0_EV               0x04
#define WEV7_EV_AON_TIMER1_EV               0x05
#define WEV7_EV_AON_SMPH_AUTOTAKE_DONE      0x06
#define WEV7_EV_AON_ADC_DONE                0x07
#define WEV7_EV_AON_ADC_FIFO_ALMOST_FULL    0x08
#define WEV7_EV_AON_OBSMUX0                 0x09
#define WEV7_EV_AON_OBSMUX1                 0x0a
#define WEV7_EV_AON_AON_SW                  0x0b
#define WEV7_EV_AON_AON_PROG_WU             0x0c
#define WEV7_EV_AON_AUXIO0                  0x0d
#define WEV7_EV_AON_AUXIO1                  0x0e
#define WEV7_EV_AON_AUXIO2                  0x0f
#define WEV7_EV_AON_AUXIO3                  0x10
#define WEV7_EV_AON_AUXIO4                  0x11
#define WEV7_EV_AON_AUXIO5                  0x12
#define WEV7_EV_AON_AUXIO6                  0x13
#define WEV7_EV_AON_AUXIO7                  0x14
#define WEV7_EV_AON_AUXIO8                  0x15
#define WEV7_EV_AON_AUXIO9                  0x16
#define WEV7_EV_AON_AUXIO10                 0x17
#define WEV7_EV_AON_AUXIO11                 0x18
#define WEV7_EV_AON_AUXIO12                 0x19
#define WEV7_EV_AON_AUXIO13                 0x1a
#define WEV7_EV_AON_AUXIO14                 0x1b
#define WEV7_EV_AON_AUXIO15                 0x1c
#define WEV7_EV_AON_ACLK_REF                0x1d
#define WEV7_EV_AON_MCU_EV                  0x1e
#define WEV7_EV_AON_DC_IRQ                  0x1f

/* This register contains a collection of event flags routed to AON_EVENT. */
#define EVTOAONFLAGS    MMIO32(AUX_EVCTL + 0x0c)
// Set when level selected by EVTOAONPOL.TIMER1_EV occurs on EVSTAT0.TIMER1_EV.
#define TIMER1_EV   0x100
// Set when level selected by EVTOAONPOL.TIMER0_EV occurs on EVSTAT0.TIMER0_EV.
#define TIMER0_EV   0x080
// Set when level selected by EVTOAONPOL.TDC_DONE occurs on EVSTAT0.TDC_DONE.
#define TDC_DONE    0x040
// Set when level selected by EVTOAONPOL.ADC_DONE occurs on EVSTAT0.ADC_DONE.
#define ADC_DONE    0x020
// Set when level selected by EVTOAONPOL.AUX_COMPB occurs on EVSTAT0.AUX_COMPB.
#define AUX_COMPB   0x010
// Set when level selected by EVTOAONPOL.AUX_COMPA occurs on EVSTAT0.AUX_COMPA.
#define AUX_COMPA   0x008
// This event flag is set when software writes a 1 to SWEVSET.SWEV2.
#define SWEV2       0x004
// This event flag is set when software writes a 1 to SWEVSET.SWEV1.
#define SWEV1       0x002
// This event flag is set when software writes a 1 to SWEVSET.SWEV0.
#define SWEV0       0x001

/* Event source polarity configuration for EVTOAONFLAGS. */
#define EVTOAONPOL      MMIO32(AUX_EVCTL + 0x10)
// Select the level of EVSTAT0.TIMER1_EV that sets EVTOAONFLAGS.TIMER1_EV.
#define TIMER1_EV   0x100
// Select the level of EVSTAT0.TIMER0_EV that sets EVTOAONFLAGS.TIMER0_EV.
#define TIMER0_EV   0x080
// Select level of EVSTAT0.TDC_DONE that sets EVTOAONFLAGS.TDC_DONE.
#define TDC_DONE    0x040
// Select the level of EVSTAT0.ADC_DONE that sets EVTOAONFLAGS.ADC_DONE.
#define ADC_DONE    0x020
// Select the edge of EVSTAT0.AUX_COMPB that sets EVTOAONFLAGS.AUX_COMPB.
#define AUX_COMPB   0x010
// Select the edge of EVSTAT0.AUX_COMPA that sets EVTOAONFLAGS.AUX_COMPA.
#define AUX_COMPA   0x008

/* Direct Memory Access Control */
#define DMACTL          MMIO32(AUX_EVCTL + 0x14)
// UDMA0 Request mode
#define REQ_MODE    0x4
// uDMA ADC interface enable.
#define ADC_DMA_EN  0x2
// Select FIFO watermark level required to trigger a UDMA0 transfer of ADC FIFO.
#define ADC_SEL     0x1

/* Set software event flags from AUX domain to AON and MCU domains. */
#define SWEVSET         MMIO32(AUX_EVCTL + 0x18)
// Software event flag 2.
#define SWEV2   0x4
// Software event flag 1.
#define SWEV1   0x2
// Software event flag 0.
#define SWEV0   0x1

/* Register holds events 0:15 of the 32-bit ev bus that is schs to AUX clock. */
#define EVSTAT0         MMIO32(AUX_EVCTL + 0x1c)
// AUXIO2 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 2.
#define AUXIO2                  0x8000
// AUXIO1 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 1.
#define AUXIO1                  0x4000
// AUXIO0 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 0.
#define AUXIO0                  0x2000
// AON_EVENT:AUXWUSEL.WUn_EV
#define AON_PROG_WU             0x1000
// AON_WUC:AUXCTL.SWEV
#define AON_SW                  0x0800
// Observation input 1 from IOC.
#define OBSMUX1                 0x0400
// Observation input 0 from IOC.
#define OBSMUX0                 0x0200
// AUX_ANAIF:ADCFIFOSTAT.ALMOST_FULL
#define ADC_FIFO_ALMOST_FULL    0x0100
// AUX_ANAIF ADC conversion done event.
#define ADC_DONE                0x0080
// See AUX_SMPH:AUTOTAKE.SMPH_ID for description.
#define SMPH_AUTOTAKE_DONE      0x0040
// AUX_TIMER1_EV event, see AUX_TIMER:T1TARGET for description.
#define TIMER1_EV               0x0020
// AUX_TIMER0_EV event, see AUX_TIMER:T0TARGET for description.
#define TIMER0_EV               0x0010
// AUX_TDC:STAT.DONE
#define TDC_DONE                0x0008
// Comparator B output
#define AUX_COMPB               0x0004
// Comparator A output
#define AUX_COMPA               0x0002
// AON_RTC:EVFLAGS.CH2
#define AON_RTC_CH2             0x0001

/* Event Status 1. Current event source levels, 31:16 */
#define EVSTAT1         MMIO32(AUX_EVCTL + 0x20)
// The logical function for this event is configurable.
#define ADC_IRQ     0x8000
// Event from EVENT configured by EVENT:AUXSEL0.
#define MCU_EV      0x4000
// TDC reference clock.
#define ACLK_REF    0x2000
// AUXIO15 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 7.
#define AUXIO15     0x1000
// AUXIO14 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 6.
#define AUXIO14     0x0800
// AUXIO13 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 5.
#define AUXIO13     0x0400
// AUXIO12 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 4.
#define AUXIO12     0x0200
// AUXIO11 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 3.
#define AUXIO11     0x0100
// AUXIO10 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 2.
#define AUXIO10     0x0080
// AUXIO9 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 1.
#define AUXIO9      0x0040
// AUXIO8 pin level, read value corresponds to AUX_AIODIO1:GPIODIN bit 0.
#define AUXIO8      0x0020
// AUXIO7 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 7.
#define AUXIO7      0x0010
// AUXIO6 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 6.
#define AUXIO6      0x0008
// AUXIO5 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 5.
#define AUXIO5      0x0004
// AUXIO4 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 4.
#define AUXIO4      0x0002
// AUXIO3 pin level, read value corresponds to AUX_AIODIO0:GPIODIN bit 3.
#define AUXIO3      0x0001


/*Event To MCU Polarity.Event source polarity configuration for EVTOMCUFLAGS. */
#define EVTOMCUPOL      MMIO32(AUX_EVCTL + 0x24)
// Select the event source level that sets EVTOMCUFLAGS.ADC_IRQ.
#define ADC_IRQ                 0x400
// Select the event source level that sets EVTOMCUFLAGS.OBSMUX0.
#define OBSMUX0                 0x200
// Select the event source level that sets EVTOMCUFLAGS.ADC_FIFO_ALMOST_FULL.
#define ADC_FIFO_ALMOST_FULL    0x100
// Select the event source level that sets EVTOMCUFLAGS.ADC_DONE.
#define ADC_DONE                0x080
// Select the event source level that sets EVTOMCUFLAGS.SMPH_AUTOTAKE_DONE.
#define SMPH_AUTOTAKE_DONE      0x040
// Select the event source level that sets EVTOMCUFLAGS.TIMER1_EV.
#define TIMER1_EV               0x020
// Select the event source level that sets EVTOMCUFLAGS.TIMER0_EV.
#define TIMER0_EV               0x010
// Select the event source level that sets EVTOMCUFLAGS.TDC_DONE.
#define TDC_DONE                0x008
// Select the event source level that sets EVTOMCUFLAGS.AUX_COMPB.
#define AUX_COMPB               0x004
// Select the event source level that sets EVTOMCUFLAGS.AUX_COMPA.
#define AUX_COMPA               0x002
// Select the event source level that sets EVTOMCUFLAGS.AON_WU_EV.
#define AON_WU_EV               0x001

/* Events to MCU Flags */
#define EVTOMCUFLAGS    MMIO32(AUX_EVCTL + 0x28)
// This event flag is set when level selected by EVTOMCUPOL.ADC_IRQ
// This event flag is set when level selected by EVTOMCUPOL.ADC_FIFO_ALMOST_FULL
// This event flag is set when level selected by EVTOMCUPOL.ADC_DONE
// This event flag is set when level selected by EVTOMCUPOL.SMPH_AUTOTAKE_DONE
// This event flag is set when level selected by EVTOMCUPOL.TIMER1_EV
// This event flag is set when level selected by EVTOMCUPOL.TIMER0_EV
// This event flag is set when level selected by EVTOMCUPOL.TDC_DONE
// This event flag is set when level selected by EVTOMCUPOL.AUX_COMPB
// This event flag is set when level selected by EVTOMCUPOL.AUX_COMPA
// This event flag is set when level selected by EVTOMCUPOL.AON_WU_EV

/* Combined Event To MCU Mask */
#define COMBEVTOMCUMASK MMIO32(AUX_EVCTL + 0x2c)
// EVTOMCUFLAGS.ADC_IRQ contribution to the AUX_COMB event.
// EVTOMCUFLAGS.MCU_OBSMUX0 contribution to the AUX_COMB event.
// EVTOMCUFLAGS.ADC_FIFO_ALMOST_FULL contribution to the AUX_COMB event.
// EVTOMCUFLAGS.ADC_DONE contribution to the AUX_COMB event.
// EVTOMCUFLAGS.SMPH_AUTOTAKE_DONE contribution to the AUX_COMB event.
// EVTOMCUFLAGS.TIMER1_EV contribution to the AUX_COMB event.
// EVTOMCUFLAGS.TIMER0_EV contribution to the AUX_COMB event.
// EVTOMCUFLAGS.TDC_DONE contribution to the AUX_COMB event.
// EVTOMCUFLAGS.AUX_COMPB contribution to the AUX_COMB event.
// EVTOMCUFLAGS.AUX_COMPA contribution to the AUX_COMB event.
// EVTOMCUFLAGS.AON_WU_EV contribution to the AUX_COMB event.

/* Vector Flags */
#define VECFLAGS        MMIO32(AUX_EVCTL + 0x34)
// Vector flag 3.
#define VEC3    0x8
// Vector flag 3.
#define VEC2    0x3
// Vector flag 3.
#define VEC1    0x2
// Vector flag 3.
#define VEC0    0x1

/* Events To MCU Flags Clear. Clear event flags in EVTOMCUFLAGS. */
#define EVTOMCUFLAGSCLR MMIO32(AUX_EVCTL + 0x38)
// Write 1 to clear EVTOMCUFLAGS.ADC_IRQ.
// Write 1 to clear EVTOMCUFLAGS.MCU_OBSMUX0.
// Write 1 to clear EVTOMCUFLAGS.ADC_FIFO_ALMOST_FULL.
// Write 1 to clear EVTOMCUFLAGS.ADC_DONE.
// Write 1 to clear EVTOMCUFLAGS.SMPH_AUTOTAKE_DONE.
// Write 1 to clear EVTOMCUFLAGS.TIMER1_EV.
// Write 1 to clear EVTOMCUFLAGS.TIMER0_EV.
// Write 1 to clear EVTOMCUFLAGS.TDC_DONE.
// Write 1 to clear EVTOMCUFLAGS.AUX_COMPB.
// Write 1 to clear EVTOMCUFLAGS.AUX_COMPA.
// Write 1 to clear EVTOMCUFLAGS.AON_WU_EV.

/* Events To AON Clear. Clear event flags in EVTOAONFLAGS. */
#define EVTOAONFLAGSCLR MMIO32(AUX_EVCTL + 0x3c)
// Write 1 to clear EVTOAONFLAGS.TIMER1_EV.
// Write 1 to clear EVTOAONFLAGS.TIMER0_EV.
// Write 1 to clear EVTOAONFLAGS.TDC_DONE.
// Write 1 to clear EVTOAONFLAGS.ADC_DONE.
// Write 1 to clear EVTOAONFLAGS.AUX_COMPB.
// Write 1 to clear EVTOAONFLAGS.AUX_COMPA.
// Write 1 to clear EVTOAONFLAGS.SWEV2.
// Write 1 to clear EVTOAONFLAGS.SWEV1.
// Write 1 to clear EVTOAONFLAGS.SWEV0.

/* Vector Flags Clear. Strobes for clearing flags in VECFLAGS. */
#define VECFLAGSCLR     MMIO32(AUX_EVCTL + 0x40)
// Clear vector flag 3.
// Clear vector flag 2.
// Clear vector flag 1.
// Clear vector flag 0.


/* Semaphore 0 */
#define MSMPH0          MMIO32(AUX_SMPH + 0x00)
#define MSMPH1          MMIO32(AUX_SMPH + 0x04)
#define MSMPH2          MMIO32(AUX_SMPH + 0x08)
#define MSMPH3          MMIO32(AUX_SMPH + 0x0c)
#define MSMPH4          MMIO32(AUX_SMPH + 0x10)
#define MSMPH5          MMIO32(AUX_SMPH + 0x14)
#define MSMPH6          MMIO32(AUX_SMPH + 0x18)
#define MSMPH7          MMIO32(AUX_SMPH + 0x1c)
// Request or release of semaphore.
#define SMPH_STAT   0x1

/* Auto Take. Sticky Request for Single Semaphore. */
#define AUTOTAKE        MMIO32(AUX_SMPH + 0x20)
// Write the semaphore ID,0x0-0x7, to SMPH_ID to request this semaphore until
// it is granted. SMPH_ID


/* Control */
#define AUX_CTL         MMIO32(AUX_TDCIF + 0x00)
// TDC commands.
#define CMD_CLEAR           0x0
#define CMD_SYNC_START      0x1
#define CMD_ASYNC_START     0x2
#define CMD_FORCE_TO_IDLE   0x3

/* Status */
#define AUX_STAT        MMIO32(AUX_TDCIF + 0x04)
// TDC measurement saturation flag.
#define SAT         0x80
// TDC measurement complete flag.
#define TDC_DONE    0x40
// TDC state machine status.
#define TDC_STATE_WAIT_START            0x00
#define TDC_STATE_WAIT_STARTSTOPCNTEN   0x04
#define TDC_STATE_IDLE                  0x06
#define TDC_STATE_CLRCNT                0x07
#define TDC_STATE_WAIT_STOP             0x08
#define TDC_STATE_WAIT_STOPCNTDOWN      0x0c
#define TDC_STATE_GETRESULTS            0x0e
#define TDC_STATE_POR                   0x0f
#define TDC_STATE_WAIT_CLRCNT_DONE      0x16
#define TDC_WAIT_STARTFALL              0x1e
#define TDC_FORCESTOP                   0x2e

/* Result of last TDC conversion */
#define RESULT          MMIO32(AUX_TDCIF + 0x08)
// TDC conversion result. VALUE

/* Saturation Configuration */
#define SATCFG          MMIO32(AUX_TDCIF + 0x0c)
// Saturation limit.
#define LIMIT12 0x3
#define LIMIT13 0x4
#define LIMIT14 0x5
#define LIMIT15 0x6
#define LIMIT16 0x7
#define LIMIT17 0x8
#define LIMIT18 0x9
#define LIMIT19 0xa
#define LIMIT20 0xb
#define LIMIT21 0xc
#define LIMIT22 0xd
#define LIMIT23 0xe
#define LIMIT24 0xf

/* Trigger Source. Select source and polarity for TDC start and stop events. */
#define TRIGSRC         MMIO32(AUX_TDCIF + 0x10)
// Polarity of stop source.
#define STOP_POL     0x00002000
// Select stop source from the asynchronous AUX event bus.
#define STOP_SRC_AON_RTC_CH2                 0x0000
#define STOP_SRC_AON_AUX_COMPA               0x0100
#define STOP_SRC_AON_AUX_COMPB               0x0200
#define STOP_SRC_AON_TDC_DONE                0x0300
#define STOP_SRC_AON_TIMER0_EV               0x0400
#define STOP_SRC_AON_TIMER1_EV               0x0500
#define STOP_SRC_AON_SMPH_AUTOTAKE_DONE      0x0600
#define STOP_SRC_AON_ADC_DONE                0x0700
#define STOP_SRC_AON_ADC_FIFO_ALMOST_FULL    0x0800
#define STOP_SRC_AON_OBSMUX0                 0x0900
#define STOP_SRC_AON_OBSMUX1                 0x0a00
#define STOP_SRC_AON_AON_SW                  0x0b00
#define STOP_SRC_AON_AON_PROG_WU             0x0c00
#define STOP_SRC_AON_AUXIO0                  0x0d00
#define STOP_SRC_AON_AUXIO1                  0x0e00
#define STOP_SRC_AON_AUXIO2                  0x0f00
#define STOP_SRC_AON_AUXIO3                  0x1000
#define STOP_SRC_AON_AUXIO4                  0x1100
#define STOP_SRC_AON_AUXIO5                  0x1200
#define STOP_SRC_AON_AUXIO6                  0x1300
#define STOP_SRC_AON_AUXIO7                  0x1400
#define STOP_SRC_AON_AUXIO8                  0x1500
#define STOP_SRC_AON_AUXIO9                  0x1600
#define STOP_SRC_AON_AUXIO10                 0x1700
#define STOP_SRC_AON_AUXIO11                 0x1800
#define STOP_SRC_AON_AUXIO12                 0x1900
#define STOP_SRC_AON_AUXIO13                 0x1a00
#define STOP_SRC_AON_AUXIO14                 0x1b00
#define STOP_SRC_AON_AUXIO15                 0x1c00
#define STOP_SRC_AON_ACLK_REF                0x1d00
#define STOP_SRC_AON_MCU_EV                  0x1e00
#define STOP_SRC_AON_DC_IRQ                  0x1f00
// Polarity of start source.
#define START_POL     0x00000020
// Select start source from the asynchronous AUX event bus.
#define START_SRC_AON_RTC_CH2                 0x00
#define START_SRC_AON_AUX_COMPA               0x01
#define START_SRC_AON_AUX_COMPB               0x02
#define START_SRC_AON_TDC_DONE                0x03
#define START_SRC_AON_TIMER0_EV               0x04
#define START_SRC_AON_TIMER1_EV               0x05
#define START_SRC_AON_SMPH_AUTOTAKE_DONE      0x06
#define START_SRC_AON_ADC_DONE                0x07
#define START_SRC_AON_ADC_FIFO_ALMOST_FULL    0x08
#define START_SRC_AON_OBSMUX0                 0x09
#define START_SRC_AON_OBSMUX1                 0x0a
#define START_SRC_AON_AON_SW                  0x0b
#define START_SRC_AON_AON_PROG_WU             0x0c
#define START_SRC_AON_AUXIO0                  0x0d
#define START_SRC_AON_AUXIO1                  0x0e
#define START_SRC_AON_AUXIO2                  0x0f
#define START_SRC_AON_AUXIO3                  0x10
#define START_SRC_AON_AUXIO4                  0x11
#define START_SRC_AON_AUXIO5                  0x12
#define START_SRC_AON_AUXIO6                  0x13
#define START_SRC_AON_AUXIO7                  0x14
#define START_SRC_AON_AUXIO8                  0x15
#define START_SRC_AON_AUXIO9                  0x16
#define START_SRC_AON_AUXIO10                 0x17
#define START_SRC_AON_AUXIO11                 0x18
#define START_SRC_AON_AUXIO12                 0x19
#define START_SRC_AON_AUXIO13                 0x1a
#define START_SRC_AON_AUXIO14                 0x1b
#define START_SRC_AON_AUXIO15                 0x1c
#define START_SRC_AON_ACLK_REF                0x1d
#define START_SRC_AON_MCU_EV                  0x1e
#define START_SRC_AON_DC_IRQ                  0x1f

/* Trigger Counter. Stop-counter control and status. */
#define TRIGCNT         MMIO32(AUX_TDCIF + 0x14)
// Number of stop events to ignore when AUX_TDC:TRIGCNTCFG.EN is 1. CNT

/* Trigger Counter Load. Stop-counter load. */
#define TRIGCNTLOAD     MMIO32(AUX_TDCIF + 0x18)
// Number of stop events to ignore when AUX_TDC:TRIGCNTCFG.EN is 1. CNT

/* Trigger Counter Configuration. Stop-counter configuration. */
#define TRIGCNTCFG      MMIO32(AUX_TDCIF + 0x1c)
// Enable stop-counter.
#define TRIGCNT_EN  0x1

/* Prescaler Control */
#define PRECTL          MMIO32(AUX_TDCIF + 0x20)
// Prescaler reset.
#define RESET_N 0x000080
// Prescaler ratio.
#define RATIO   0x0000040
// Prescaler event source.
#define SRC_AON_RTC_CH2                 0x00
#define SRC_AON_AUX_COMPA               0x01
#define SRC_AON_AUX_COMPB               0x02
#define SRC_AON_TDC_DONE                0x03
#define SRC_AON_TIMER0_EV               0x04
#define SRC_AON_TIMER1_EV               0x05
#define SRC_AON_SMPH_AUTOTAKE_DONE      0x06
#define SRC_AON_ADC_DONE                0x07
#define SRC_AON_ADC_FIFO_ALMOST_FULL    0x08
#define SRC_AON_OBSMUX0                 0x09
#define SRC_AON_OBSMUX1                 0x0a
#define SRC_AON_AON_SW                  0x0b
#define SRC_AON_AON_PROG_WU             0x0c
#define SRC_AON_AUXIO0                  0x0d
#define SRC_AON_AUXIO1                  0x0e
#define SRC_AON_AUXIO2                  0x0f
#define SRC_AON_AUXIO3                  0x10
#define SRC_AON_AUXIO4                  0x11
#define SRC_AON_AUXIO5                  0x12
#define SRC_AON_AUXIO6                  0x13
#define SRC_AON_AUXIO7                  0x14
#define SRC_AON_AUXIO8                  0x15
#define SRC_AON_AUXIO9                  0x16
#define SRC_AON_AUXIO10                 0x17
#define SRC_AON_AUXIO11                 0x18
#define SRC_AON_AUXIO12                 0x19
#define SRC_AON_AUXIO13                 0x1a
#define SRC_AON_AUXIO14                 0x1b
#define SRC_AON_AUXIO15                 0x1c
#define SRC_AON_ACLK_REF                0x1d
#define SRC_AON_MCU_EV                  0x1e
#define SRC_AON_DC_IRQ                  0x1f

/* Prescaler Counter */
#define PRECNT          MMIO32(AUX_TDCIF + 0x24)
// Prescaler counter value. 15-0 CNT


/* Timer n Configuration */
#define T0CFG           MMIO32(AUX_TIMER + 0x00)
#define T1CFG           MMIO32(AUX_TIMER + 0x04)
// Tick source polarity for Timer n.
#define TICK_SRC_POL    0x2000
// Select Timer n tick source from the synchronous event bus.
#define TICK_SRC_AON_RTC_CH2                 0x0000
#define TICK_SRC_AON_AUX_COMPA               0x0100
#define TICK_SRC_AON_AUX_COMPB               0x0200
#define TICK_SRC_AON_TDC_DONE                0x0300
#define TICK_SRC_AON_TIMER0_EV               0x0400
#define TICK_SRC_AON_TIMER1_EV               0x0500
#define TICK_SRC_AON_SMPH_AUTOTAKE_DONE      0x0600
#define TICK_SRC_AON_ADC_DONE                0x0700
#define TICK_SRC_AON_ADC_FIFO_ALMOST_FULL    0x0800
#define TICK_SRC_AON_OBSMUX0                 0x0900
#define TICK_SRC_AON_OBSMUX1                 0x0a00
#define TICK_SRC_AON_AON_SW                  0x0b00
#define TICK_SRC_AON_AON_PROG_WU             0x0c00
#define TICK_SRC_AON_AUXIO0                  0x0d00
#define TICK_SRC_AON_AUXIO1                  0x0e00
#define TICK_SRC_AON_AUXIO2                  0x0f00
#define TICK_SRC_AON_AUXIO3                  0x1000
#define TICK_SRC_AON_AUXIO4                  0x1100
#define TICK_SRC_AON_AUXIO5                  0x1200
#define TICK_SRC_AON_AUXIO6                  0x1300
#define TICK_SRC_AON_AUXIO7                  0x1400
#define TICK_SRC_AON_AUXIO8                  0x1500
#define TICK_SRC_AON_AUXIO9                  0x1600
#define TICK_SRC_AON_AUXIO10                 0x1700
#define TICK_SRC_AON_AUXIO11                 0x1800
#define TICK_SRC_AON_AUXIO12                 0x1900
#define TICK_SRC_AON_AUXIO13                 0x1a00
#define TICK_SRC_AON_AUXIO14                 0x1b00
#define TICK_SRC_AON_AUXIO15                 0x1c00
#define TICK_SRC_AON_ACLK_REF                0x1d00
#define TICK_SRC_AON_MCU_EV                  0x1e00
#define TICK_SRC_AON_DC_IRQ                  0x1f00
// Prescaler division ratio.
#define PRE_DIV1        0x00
#define PRE_DIV2        0x10
#define PRE_DIV4        0x20
#define PRE_DIV8        0x30
#define PRE_DIV16       0x40
#define PRE_DIV32       0x50
#define PRE_DIV64       0x60
#define PRE_DIV128      0x70
#define PRE_DIV256      0x80
#define PRE_DIV512      0x90
#define PRE_DIV1024     0xa0
#define PRE_DIV2048     0xb0
#define PRE_DIV4096     0xc0
#define PRE_DIV8192     0xd0
#define PRE_DIV16384    0xe0
#define PRE_DIV32768    0xf0
// Timer n mode. Configure source for Timer 0 prescaler.
#define MODE    0x2
// Timer n reload mode.
#define RELOAD  0x1

/*  */

/* Timer 0 Control */
#define T0CTL           MMIO32(AUX_TIMER + 0x08)
#define T1CTL           MMIO32(AUX_TIMER + 0x14)
// Timer enable.
#define AUX_TIMER_EN    0x1

/* Timer Target */
#define T0TARGET        MMIO32(AUX_TIMER + 0x0c)
#define T1TARGET        MMIO32(AUX_TIMER + 0x10)
// Timer target value. VALUE


/* Module Clock Enable. Clock enable for each module in the AUX domain */
#define MODCLKEN0       MMIO32(AUX_WUC + 0x00)
#define MODCLKEN1       MMIO32(AUX_WUC + 0x5c)
// Enables (1) or disables (0) clock for AUX_ADI4.
#define AUX_ADI4        0x80
// Enables (1) or disables (0) clock for AUX_DDI0_OSC.
#define AUX_DDI0_OSC    0x40
// Enables (1) or disables (0) clock for AUX_TDCIF.
#define TDC             0x20
// Enables (1) or disables (0) clock for AUX_ANAIF.
#define ANAIF           0x10
// Enables (1) or disables (0) clock for AUX_TIMER.
#define TIMER           0x08
// Enables (1) or disables (0) clock for AUX_AIODIO1.
#define AIODIO1         0x04
// Enables (1) or disables (0) clock for AUX_AIODIO0.
#define AIODIO0         0x02
// Enables (1) or disables (0) clock for AUX_SMPH.
#define MODE_SMPH       0x01

/* Power Off Request. Requests power off request for the AUX domain. */
#define PWROFFREQ       MMIO32(AUX_WUC + 0x04)
// 1: Request to power down AUX.
#define REQ 0x01

/* Power Down Request. Request from AUX for system to enter power down. */
#define PWRDWNREQ       MMIO32(AUX_WUC + 0x08)
// 1: Request for system to be in power down mode. REQ 0x01

/* Power Down Acknowledgment */
#define PWRDWNACK       MMIO32(AUX_WUC + 0x0c)
// Power down acknowledgment
#define ACK 0x01

/* Low Frequency Clock Request */
#define CLKLFREQ        MMIO32(AUX_WUC + 0x10)
// 1: Request low frequency clock SCLK_LF as the clock source for AUX. REQ 0x01

/* Low Frequency Clock Acknowledgment */
#define CLKLFACK        MMIO32(AUX_WUC + 0x14)
// 1: the low frequency clock SCLK_LF is the clock source for AUX. ACK 0x01

/* Wake-up Event Flags. Status of wake-up events from the AON domain. */
#define WUEVFLAGS       MMIO32(AUX_WUC + 0x28)
// Indicates pending event from AON_RTC_CH2 compare.
#define AON_RTC_CH2 0x4
// Indicates pending event triggered by system CPU to AON_WUC:AUXCTL.SWEV.
#define AON_SW      0x2
// Indicates pending event triggered by the sources selected in ...
#define AON_PROG_WU 0x1

/* Wake-up Event Clear. Clears wake-up events from the AON domain. */
#define WUEVCLR         MMIO32(AUX_WUC + 0x2c)
// Set to clear the WUEVFLAGS.AON_RTC_CH2 wake-up event.
// Set to clear the WUEVFLAGS.AON_SW wake-up event.
// Set to clear the WUEVFLAGS.AON_PROG_WU wake-up event.

/* ADC Clock Control. Controls the ADC internal clock. */
#define ADCCLKCTL       MMIO32(AUX_WUC + 0x30)
// Acknowledges the last value written to REQ.
#define CLK_ACK 0x2
// Enables(1) or disables (0) the ADC internal clock.
#define CLK_REQ 0x1

/* TDC Clock Control */
#define TDCCLKCTL       MMIO32(AUX_WUC + 0x34)
// Acknowledges the last value written to REQ. CLK_ACK 0x2
// Enables(1) or disables (0) the TDC counter clock source. CLK_REQ 0x1

/* Reference Clock Control */
#define REFCLKCTL       MMIO32(AUX_WUC + 0x38)
// Acknowledges the last value written to REQ. CLK_ACK 0x2
// Enables(1) or disables (0) the TDC reference clock source. CLK_REQ 0x1

/* Real Time Counter Sub Second Increment */
#define RTCSUBSECINC0   MMIO32(AUX_WUC + 0x3c)
// Bits 15:0 of the RTC sub-second increment value.
#define RTCSUBSECINC0   MMIO32(AUX_WUC + 0x40)
// Bits 23:16 of the RTC sub-second increment value.

/* Real Time Counter Sub Second Increment Control */
#define RTCSUBSECINCCTL MMIO32(AUX_WUC + 0x44)
// Acknowledgment of the UPD_REQ.
#define UPD_ACK 0x2
// Signal that a new real time counter sub second increment value is available.
#define UPD_REQ 0x1

/* MCU Bus Control */
#define MCUBUSCTL       MMIO32(AUX_WUC + 0x48)
// Requests the AUX domain bus to be disconnected from the MCU domain bus.
#define DISCONNECT_REQ  0x1

/* MCU Bus Status */
#define MCUBUSSTAT      MMIO32(AUX_WUC + 0x4c)
// Indicates whether the buses are currently disconnected
#define DISCONNECTED    0x2
// Acknowledges reception of the bus disconnection request.
#define DISCONNECT_ACK  0x1

/* AON Domain Control Status. Status of AUX domain control from AON_WUC. */
#define AONCTLSTAT      MMIO32(AUX_WUC + 0x50)
// Indicates whether the buses are currently disconnected
#define AUX_FORCE_ON    0x2
// Acknowledges reception of the bus disconnection request.
#define SCE_RUN_EN      0x1

/* AUX Input Output Latch */
#define AUXIOLATCH      MMIO32(AUX_WUC + 0x54)
// Opens (1) or closes (0) the AUX_AIODIO0/AUX_AIODIO1 signal latching.
#define AUX_LATCH_EN    0x1


/* ADC Control */
#define ADCCTL          MMIO32(AUX_ANAIF + 0x10)
// Select active polarity for START_SRC event.
#define START_POL   0x2000
// Select ADC trigger event source from the asynchronous AUX event bus.
#define ANAIF_START_SRC_AON_RTC_CH2                 0x00
#define ANAIS_START_SRC_AON_AUX_COMPA               0x01
#define ANAIS_START_SRC_AON_AUX_COMPB               0x02
#define ANAIS_START_SRC_AON_TDC_DONE                0x03
#define ANAIS_START_SRC_AON_TIMER0_EV               0x04
#define ANAIS_START_SRC_AON_TIMER1_EV               0x05
#define ANAIS_START_SRC_AON_SMPH_AUTOTAKE_DONE      0x06
#define ANAIS_START_SRC_AON_AON_SW                  0x0b
#define ANAIF_START_SRC_AON_AON_PROG_WU             0x0c
#define ANAIF_START_SRC_AON_AUXIO0                  0x0d
#define ANAIF_START_SRC_AON_AUXIO1                  0x0e
#define ANAIF_START_SRC_AON_AUXIO2                  0x0f
#define ANAIF_START_SRC_AON_AUXIO3                  0x10
#define ANAIF_START_SRC_AON_AUXIO4                  0x11
#define ANAIF_START_SRC_AON_AUXIO5                  0x12
#define ANAIF_START_SRC_AON_AUXIO6                  0x13
#define ANAIF_START_SRC_AON_AUXIO7                  0x14
#define ANAIF_START_SRC_AON_AUXIO8                  0x15
#define ANAIF_START_SRC_AON_AUXIO9                  0x16
#define ANAIF_START_SRC_AON_AUXIO10                 0x17
#define ANAIF_START_SRC_AON_AUXIO11                 0x18
#define ANAIF_START_SRC_AON_AUXIO12                 0x19
#define ANAIF_START_SRC_AON_AUXIO13                 0x1a
#define ANAIF_START_SRC_AON_AUXIO14                 0x1b
#define ANAIF_START_SRC_AON_AUXIO15                 0x1c
#define ANAIF_START_SRC_AON_ACLK_REF                0x1d
#define ANAIF_START_SRC_AON_MCU_EV                  0x1e
#define ANAIF_START_SRC_AON_DC_IRQ                  0x1f
// ADC interface command.
#define CMD_DISABLE_ADC 0x0
#define CMD_ENABLE_ADC  0x1
#define CMD_FLUSH_ADC   0x3

/* ADC FIFO Status. FIFO can hold up to four ADC samples. */
#define ADCFIFOSTAT     MMIO32(AUX_ANAIF + 0x14)
// FIFO overflow flag.
#define OVERFLOW    0x10
// FIFO underflow flag.
#define UNDERFLOW   0x08
// FIFO full flag.
#define FULL        0x04
// FIFO almost full flag.
#define ALMOST_FULL 0x02
// FIFO empty flag.
#define EMPTY       0x01

/* ADC FIFO */
#define ADCFIFO         MMIO32(AUX_ANAIF + 0x18)
// FIFO data. 11-0 DATA

/* ADC Trigger */
#define ADCTRIG         MMIO32(AUX_ANAIF + 0x1c)
// Manual ADC trigger.
#define START       0x01

/* Current Source Control */
#define ISRCCTL         MMIO32(AUX_ANAIF + 0x20)
// 1: ISRC drives current ADI_4_AUX:ISRC.TRIM to COMPA_IN.  EN = 0x1

#endif
