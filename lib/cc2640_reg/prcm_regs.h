#ifndef H_PRCM_REGS
#define H_PRCM_REGS
/*
 * Simple CC2640 headphones
 * Power, Reset, and Clock Management registers
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

/* Controls clock source selects */
#define CTL0                    MMIO32(AUX_DDI0_OSC + 0x00)
// Set based on the accurate high frequency XTAL.
#define XTAL_IS_24M                 0x80000000
//...
#define BYPASS_XOSC_LF_CLK_QUAL     0x20000000
//...
#define BYPASS_RCOSC_LF_CLK_QUAL    0x10000000
//...
#define DOUBLER_START_DURATION_SFT  26
#define DOUBLER_START_DURATION_MSK  0x3
//...
#define DOUBLER_RESET_DURATION      0x02000000
//...
#define FORCE_KICKSTART_EN          0x00400000
// 1: Allows switching of sclk_hf source.
#define ALLOW_SCLK_HF_SWITCHING     0x00010000
//...
#define HPOSC_MODE_EN               0x00004000
//...
#define RCOSC_LF_TRIMMED            0x00001000
//...
#define XOSC_HF_POWER_MODE          0x00000800
//Bypass XOSC_LF and use the digital input clock from AON for the xosc_lf clock.
#define XOSC_LF_DIG_BYPASS          0x00000400
// Enable clock loss detection and hence the indicators to system controller.
#define CLK_LOSS_EN                 0x00000200
// Source select for aclk_tdc.
#define ACLK_TDC_SRC_SEL            0x00000100
// Source select for aclk_ref
#define ACLK_REF_SRC_SEL_RCOSC_HF   0x00000000
#define ACLK_REF_SRC_SEL_XOSC_HF    0x00000020
#define ACLK_REF_SRC_SEL_RCOSC_LF   0x00000040
#define ACLK_REF_SRC_SEL_XOSC_LF    0x00000060
//...
#define SPARE4                      0x00000010
// Source select for sclk_lf.
#define SCLK_LF_SRC_SEL_RCOSC_HF    0x00000000
#define SCLK_LF_SRC_SEL_XOSC_HF     0x00000004
#define SCLK_LF_SRC_SEL_RCOSC       0x00000008
#define SCLK_LF_SRC_SEL_XOSC        0x0000000c
//...
#define SCLK_MF_SRC_SEL             0x00000002
// Source select for sclk_hf.
#define SCLK_HF_SRC_SEL             0x00000001

/* This register contains OSC_DIG configuration */
#define CTL1                    MMIO32(AUX_DDI0_OSC + 0x04)
//...
#define RCOSCHFCTRIMFRACT_SFT   12
#define RCOSCHFCTRIMFRACT_MSK   0x1f
//...
#define RCOSCHFCTRIMFRACT_EN    0x00020000
//...
#define SPARE2_SFT              2
#define SPARE2_MSK              0x7fff
//...
#define XOSC_HF_FAST_START_SFT  0
#define XOSC_HF_FAST_START_MSK  0x3

/* RADC External Configuration */
#define RADCEXTCFG              MMIO32(AUX_DDI0_OSC + 0x08)
//...
#define HPM_IBIAS_WAIT_CNT_SFT  22
#define HPM_IBIAS_WAIT_CNT_MSK  0x3ff
//...
#define LPM_IBIAS_WAIT_CNT_SFT  16
#define LPM_IBIAS_WAIT_CNT_MSK  0x3f
//...
#define IDAC_STEP_SFT           12
#define IDAC_STEP_MSK           0xf
//...
#define RADC_DAC_TH_SFT         6
#define RADC_DAC_TH_MSK         0x3f
//...
#define RADC_MODE_IS_SAR        0x00000020

/* Amplitude Compensation Control */
#define AMPCOMPCTL              MMIO32(AUX_DDI0_OSC + 0x0c)
//...
#define SPARE31                         0x80000000
//...
#define AMPCOMP_REQ_MODE                0x40000000
//...
#define AMPCOMP_FSM_UPDATE_RATE_SFT     28
#define AMPCOMP_FSM_UPDATE_RATE_MSK     0x3
//...
#define AMPCOMP_SW_CTRL                 0x08000000
//...
#define AMPCOMP_SW_EN                   0x04000000
//...
#define IBIAS_OFFSET_SFT                20
#define IBIAS_OFFSET_MSK                0xf
//...
#define IBIAS_INIT_SFT                  16
#define IBIAS_INIT_MSK                  0xf
//...
#define LPM_IBIAS_WAIT_CNT_FINAL_SFT    8
#define LPM_IBIAS_WAIT_CNT_FINAL_MSK    0xff
//...
#define CAP_STEP_SFT                    4
#define CAP_STEP_MSK                    0xf
//...
#define IBIASCAP_HPTOLP_OL_CNT_SFT      0
#define IBIASCAP_HPTOLP_OL_CNT_MSK      0xf

/* Amplitude Compensation Threshold 1 */
#define AMPCOMPTH1              MMIO32(AUX_DDI0_OSC + 0x10)
//...
#define SPARE24_SFT                 24
#define SPARE24_MSK                 0xff
//...
#define HPMRAMP3_LTH_SFT            18
#define HPMRAMP3_LTH_MSK            0x3f
//...
#define SPARE16_SFT                 16
#define SPARE16_MSK                 0x3
//...
#define HPMRAMP3_HTH_SFT            10
#define HPMRAMP3_HTH_MSK            0xf
//...
#define IBIASCAP_LPTOHP_OL_CNT_SFT  6
#define IBIASCAP_LPTOHP_OL_CNT_MSK  0xf
//...
#define HPMRAMP1_TH_SFT             0
#define HPMRAMP1_TH_MSK             0x3f

/* Amplitude Compensation Threshold 2 */
#define AMPCOMPTH2              MMIO32(AUX_DDI0_OSC + 0x14)
//...
#define LPMUPDATE_LTH_SFT       26
#define LPMUPDATE_LTH_MSK       0x3f
//...
#define SPARE24_SFT             24
#define SPARE24_MSK             0x3
//...
#define LPMUPDATE_HTH_SFT       18
#define LPMUPDATE_HTH_MSK       0x3f
//...
#define SPARE16_SFT             16
#define SPARE16_MSK             0x3
//...
#define ADC_COMP_AMPTH_LPM_SFT  10
#define ADC_COMP_AMPTH_LPM_MSK  0x3f
//...
#define SPARE8_SFT              8
#define SPARE8_MSK              0x3
//...
#define ADC_COMP_AMPTH_HPM_SFT  2
#define ADC_COMP_AMPTH_HPM_MSK  0x3f
//...
#define SPARE0_SFT              0
#define SPARE0_MSK              0x3

/* Analog Bypass Values 1 */
#define ANABYPASSVAL1           MMIO32(AUX_DDI0_OSC + 0x18)
//...
#define XOSC_HF_ROW_Q12_SFT     16
#define XOSC_HF_ROW_Q12_MSK     0xf
//...
#define XOSC_HF_COLUMN_Q12_SFT  0
#define XOSC_HF_COLUMN_Q12_MSK  0xffff

/* ANABYPASSVAL2 Register */
#define ANABYPASSVAL2           MMIO32(AUX_DDI0_OSC + 0x1c)
//...
#define XOSC_HF_IBIASTHERM_SFT  0
#define XOSC_HF_IBIASTHERM_MSK  0x3fff

/* Analog Test Control */
#define ATESTCTL	            MMIO32(AUX_DDI0_OSC + 0x20)
//...
#define SPARE30_SFT     16
#define SPARE30_MSK     0xf
//...
#define SCLK_LF_AUX_EN  0x20000000

/* ADC Doubler Nanoamp Control */
#define ADCDOUBLERNANOAMPCTL    MMIO32(AUX_DDI0_OSC + 0x24)
//...
#define NANOAMP_BIAS_ENABLE 0x01000000
//...
#define SPARE23             0x00800000
//...
#define ADC_SH_MODE_EN      0x00000020
//...
#define ADC_SH_VBUF_EN      0x00000010
//...
#define ADC_IREF_CTRL_SFT   0
#define ADC_IREF_CTRL_MSK   0x2

/* XOSCHF Control */
#define XOSCHFCTL               MMIO32(AUX_DDI0_OSC + 0x28)

/* Low Frequency Oscillator Control */
#define LFOSCCTL                MMIO32(AUX_DDI0_OSC + 0x2c)

/* RCOSCHF Control */
#define RCOSCHFCTL              MMIO32(AUX_DDI0_OSC + 0x30)

/* This register contains status signals from OSC_DIG */
#define STAT0                   MMIO32(AUX_DDI0_OSC + 0x34)

/* Status 1 */
#define STAT1                   MMIO32(AUX_DDI0_OSC + 0x38)

/* This register contains status signals from AMPCOMP FSM */
#define STAT2                   MMIO32(AUX_DDI0_OSC + 0x3c)
// DC Bias read by RADC during SAR mode
#define ADC_DCBIAS_SFT      26
#define ADC_DCBIAS_MSK      0x3f
// Indication of threshold is met for hpm_ramp1
#define HPM_RAMP1_THMET     0x02000000
// Indication of threshold is met for hpm_ramp2
#define HPM_RAMP2_THMET     0x01000000
// Indication of threshold is met for hpm_ramp3
#define HPM_RAMP3_THMET     0x00800000
// xosc_hf amplitude compensation FSM
#define RAMPSTATE_SFT       12
#define RAMPSTATE_MSK       0xf
// ampcomp_req
#define AMPCOMP_REQ         0x00000008
// amplitude of xosc_hf is within the required threshold (set by DDI).
#define XOSC_HF_AMPGOOD     0x00000004
// frequency of xosc_hf is good to use for the digital clocks
#define XOSC_HF_FREQGOOD    0x00000002
// frequency of xosc_hf is within +/- 20 ppm and xosc_hf is good for radio.
#define XOSC_HF_RF_FREQGOOD 0x00000001


/* Power Management */
#define PWRCTL                  MMIO32(AON_SYSCTL + 0x0)
// Select to use DCDC regulator for VDDR in active mode.
#define DCDC_ACTIVE     0x00000004
// Status of source for VDDRsupply.
#define EXT_REG_MODE    0x00000002
// Select to use DCDC regulator during recharge of VDDR.
#define DCDC_EN         0x00000001

/* Reset Management */
#define RESETCTL                MMIO32(AON_SYSCTL + 0x0)
// Cold reset register.
#define SYSRESET            0x80000000
//...
#define BOOT_DET_1_CLR      0x02000000
//...
#define BOOT_DET_0_CLR      0x01000000
//...
#define BOOT_DET_1_SET      0x00020000
//...
#define BOOT_DET_0_SET      0x00010000
// A Wakeup from SHUTDOWN on an IO event has occurred.
#define WU_FROM_SD          0x00008000
// A wakeup from SHUTDOWN on an IO event has occurred.
#define GPIO_WU_FROM_SD     0x00004000
//...
#define BOOT_DET_1          0x00002000
//...
#define BOOT_DET_0          0x00001000
// Override of VDDS_LOSS_EN.
#define VDDS_LOSS_EN_OVR    0x00000800
// Override of VDDR_LOSS_EN.
#define VDDR_LOSS_EN_OVR    0x00000400
// Override of VDD_LOSS_EN.
#define VDD_LOSS_EN_OVR     0x00000200
// Controls reset generation in case VDDS is lost.
#define VDDS_LOSS_EN        0x00000080
// Controls reset generation in case VDDR is lost.
#define VDDR_LOSS_EN        0x00000040
// Controls reset generation in case VDD is lost.
#define VDD_LOSS_EN         0x00000020
// Controls reset generation in case SCLK_LF is lost.
#define CLK_LOSS_EN         0x00000010
// Shows the source of the last system reset.
#define RESET_SRC_POR       0x00000000
#define RESET_SRC_PIN       0x00000002
#define RESET_SRC_BOD_VDDS  0x00000004
#define RESET_SRC_BOD_VDD   0x00000006
#define RESET_SRC_BOD_VDDR  0x00000008
#define RESET_SRC_CLK_LOSS  0x0000000a
#define RESET_SRC_SYSRESET  0x0000000c
#define RESET_SRC_PRCM      0x0000000e

/* Sleep Mode */
#define SLEEPCTL                MMIO32(AON_SYSCTL + 0x0)
// Controls the I/O pad sleep mode.
#define IO_PAD_SLEEP_DIS    0x00000001


/* MCU Clock Management */
#define MCUCLK                  MMIO32(AON_WUC + 0x00)
// MCU bootcode will set this bit when RCOSC_HF is calibrated.
#define RCOSC_HF_CAL_DONE   0x00000004
//Controls the clk src for the entire MCU domain while MCU is requesting pwdn.
#define PWR_DWN_SRC_SCLK_LF 0x00000001

/* AUX Clock Management */
#define AUXCLK                  MMIO32(AON_WUC + 0x04)
//
#define PWR_DWN_SRC_SCLK_LF 0x00000800
// Select the AUX clock divider for SCLK_HF.
#define SCLK_HF_DIV2        0x00000000
#define SCLK_HF_DIV4        0x00000100
#define SCLK_HF_DIV8        0x00000200
#define SCLK_HF_DIV16       0x00000300
#define SCLK_HF_DIV32       0x00000400
#define SCLK_HF_DIV64       0x00000500
#define SCLK_HF_DIV128      0x00000600
#define SCLK_HF_DIV256      0x00000700
// Selects the clock source for AUX.
#define SRC_SCLK_HF         0x00000001
#define SRC_SCLK_HF         0x00000004

/* MCU Configuration */
#define MCUCFG                  MMIO32(AON_WUC + 0x08)
//...
#define VIRT_OFF            0x00020000
//...
#define FIXED_WU_EN         0x00010000
//This register controls which of the banks that has retention during MCU pwroff
#define SRAM_RET_EN_DIS     0x00000000
#define SRAM_RET_EN_BANK0   0x00000001
#define SRAM_RET_EN_BANK0_1 0x00000003
#define SRAM_RET_EN_BANK1_2 0x00000007
#define SRAM_RET_EN_BANK0_3 0x0000000f

/* This register contains power management related signals for the AUX domain.*/
#define AUXCFG                  MMIO32(AON_WUC + 0x0c)
// This bit controls retention mode for the AUX_RAM:BANK0.
#define RAM_RET_EN  0x00000001

/* This register contains events and control signals for the AUX domain. */
#define AUXCTL                  MMIO32(AON_WUC + 0x10)
// Reset request for AUX.
#define RESET_REQ       0x80000000
// Enables (1) or disables (0) AUX_SCE execution.
#define SCE_RUN_EN      0x00000004
// Writing 1 sets the software event to the AUX domain
#define SWEV            0x00000002
// Forces the AUX domain into active mode, overriding the requests.
#define AUX_FORCE_ON    0x00000001

/* Power Status */
#define PWRSTAT                 MMIO32(AON_WUC + 0x14)
// Indicates the AUX powerdown state when AUX domain is powered up.
#define AUX_PWR_DWN         0x00000200
// Indicates JTAG power state.
#define JTAG_PD_ON          0x00000040
// Indicates AUX power state.
#define AUX_PD_ON           0x00000020
// Indicates MCU power state.
#define MCU_PD_ON           0x00000010
// Indicates that AUX Bus is connected.
#define AUX_BUS_CONNECTED   0x00000004
// Indicates Reset Done from AUX.
#define AUX_RESET_DONE      0x00000002

/* Shutdown Control */
#define SHUTDOWN                MMIO32(AON_WUC + 0x18)
// Writing a 1 to this bit forces a shutdown request.
#define EN  0x00000001

/* This register contains various chip level control and debug bitfields. */
#define CTL0                    MMIO32(AON_WUC + 0x20)
// Controls whether MCU and AUX requesting to be powered off will enable a
// transition to powerdown:
#define PWR_DWN_DIS     0x00000100
//...
#define AUX_SRAM_ERASE  0x00000008
//...
#define MCU_SRAM_ERASE  0x00000004

/* Control 1 */
#define CTL1                    MMIO32(AON_WUC + 0x24)
// Indicates source of last MCU Voltage Domain warm reset request.
#define MCU_RESET_SRC   0x00000002
// Indicates type of last MCU Voltage Domain reset.
#define MCU_WARM_RESET  0x00000001

/* Recharge Controller Configuration */
#define RECHARGECFG             MMIO32(AON_WUC + 0x30)
// Enable adaptive recharge
#define ADAPTIVE_EN     0x80000000
// Gain factor for adaptive recharge algorithm
#define C2_SFT              20
#define C2_MSK              0xf
#define C2_SFT              16
#define C2_MSK              0xf
//This register defines the maximum period that the recharge algorithm can take
#define MAX_PER_M_SFT       11
#define MAX_PER_M_MSK       0x1f
#define MAX_PER_E_SFT       8
#define MAX_PER_E_MSK       0x7
// Number of 32 KHz clocks between activation of recharge controller.
#define RECHARGE_PER_M_SFT  3
#define RECHARGE_PER_M_MSK  0x1f
#define RECHARGE_PER_E_SFT  0
#define RECHARGE_PER_E_MSK  0x7

/* Recharge Controller Status */
#define RECHARGESTAT            MMIO32(AON_WUC + 0x34)
// The last 4 VDDR samples, bit 0 being the newest.
#define VDDR_SMPLS_SFT      16
#define VDDR_SMPLS_MSK      0xf
// The maximum value of recharge period seen with VDDR>threshold.
#define MAX_USED_PER_SFT    0
#define MAX_USED_PER_MSK    0xffff

/* Oscillator Configuration */
#define OSCCFG                  MMIO32(AON_WUC + 0x38)
// Number of 32 KHz clocks between oscillator amplitude calibrations.
#define PER_M_SFT  3
#define PER_M_MSK  0x1f
#define PER_E_SFT  0
#define PER_E_MSK  0x7

/* JTAG Configuration */
#define JTAGCFG                 MMIO32(AON_WUC + 0x40)
// Controls JTAG PowerDomain power state.
#define JTAG_PD_FORCE_ON    0x00000100

/* JTAG USERCODE */
#define JTAGUSERCODE            MMIO32(AON_WUC + 0x44)
//USER_CODE


/* Infrastructure Clock Division Factor For Run Mode */
#define INFRCLKDIVR             MMIO32(PRCM + 0x000)
/* Infrastructure Clock Division Factor For Sleep Mode */
#define INFRCLKDIVS             MMIO32(PRCM + 0x004)
/* Infrastructure Clock Division Factor For DeepSleep Mode */
#define INFRCLKDIVDS            MMIO32(PRCM + 0x008)
// Division rate for clocks driving modules in the MCU_AON domain.
#define RATIO_DIV1   0x00000000
#define RATIO_DIV2   0x00000001
#define RATIO_DIV8   0x00000002
#define RATIO_DIV32  0x00000003

/* MCU Voltage Domain Control */
#define VDCTL                   MMIO32(PRCM + 0x00c)
// Request WUC to power down the MCU voltage domain
#define MCU_VD  0x00000004
// Request WUC to switch to uLDO.
#define ULDO    0x00000001

/* Load PRCM Settings To CLKCTRL Power Domain */
#define CLKLOADCTL              MMIO32(PRCM + 0x028)
// Status of LOAD.
#define LOAD_DONE   0x00000002
// 1: Load settings to CLKCTRL.
#define LOAD        0x00000001

/* RFC Clock Gate */
#define RFCCLKG                 MMIO32(PRCM + 0x02c)
// 1: Enable clock if RFC power domain is on
#define CLK_EN    0x00000001

/* VIMS Clock Gate */
#define VIMSCLKG                MMIO32(PRCM + 0x030)
//CLK_EN

/* TRNG, CRYPTO And UDMA Clock Gate For Run Mode */
#define SECDMACLKGR             MMIO32(PRCM + 0x03c)
/* TRNG, CRYPTO And UDMA Clock Gate For Sleep Mode */
#define SECDMACLKGS             MMIO32(PRCM + 0x040)
/* TRNG, CRYPTO And UDMA Clock Gate For Deep Sleep Mode */
#define SECDMACLKGDS            MMIO32(PRCM + 0x044)
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define DMA_CLK_EN      0x00000100
//...
#define TRNG_CLK_EN     0x00000002
//...
#define CRYPTO_CLK_EN   0x00000001

/* GPIO Clock Gate For Run Mode */
#define GPIOCLKGR               MMIO32(PRCM + 0x048)
/* GPIO Clock Gate For Sleep Mode */
#define GPIOCLKGS               MMIO32(PRCM + 0x04c)
/* GPIO Clock Gate For Deep Sleep Mode */
#define GPIOCLKGDS              MMIO32(PRCM + 0x050)
// CLK_EN

/* GPT Clock Gate For Run Mode */
#define GPTCLKGR                MMIO32(PRCM + 0x054)
/* GPT Clock Gate For Sleep Mode */
#define GPTCLKGS                MMIO32(PRCM + 0x058)
/* GPT Clock Gate For Deep Sleep Mode */
#define GPTCLKGDS               MMIO32(PRCM + 0x05c)
//...
#define CLK_EN_GPT0 0x00000001
#define CLK_EN_GPT1 0x00000002
#define CLK_EN_GPT2 0x00000004
#define CLK_EN_GPT3 0x00000008

/* I2C Clock Gate For Run Mode */
#define I2CCLKGR                MMIO32(PRCM + 0x060)
/* I2C Clock Gate For Sleep Mode */
#define I2CCLKGS                MMIO32(PRCM + 0x064)
/* I2C Clock Gate For Deep Sleep Mode */
#define I2CCLKGDS               MMIO32(PRCM + 0x068)
// CLK_EN

/* UART Clock Gate For Run Mode */
#define UARTCLKGR               MMIO32(PRCM + 0x06c)
/* UART Clock Gate For Sleep Mode */
#define UARTCLKGS               MMIO32(PRCM + 0x070)
/* UART Clock Gate For Deep Sleep Mode*/
#define UARTCLKGDS              MMIO32(PRCM + 0x074)
// CLK_EN

/* SSI Clock Gate For Run Mode */
#define SSICLKGR                MMIO32(PRCM + 0x078)
/* SSI Clock Gate For Sleep Mode */
#define SSICLKGS                MMIO32(PRCM + 0x07c)
/* SSI Clock Gate For Deep Sleep Mode */
#define SSICLKGDS               MMIO32(PRCM + 0x080)
//...
#define CLK_EN_SSI0 0x00000001
#define CLK_EN_SSI1 0x00000002

/* I2S Clock Gate For Run Mode */
#define I2SCLKGR                MMIO32(PRCM + 0x084)
/* I2S Clock Gate For Sleep Mode */
#define I2SCLKGS                MMIO32(PRCM + 0x088)
/* I2S Clock Gate For Deep Sleep Mode */
#define I2SCLKGDS               MMIO32(PRCM + 0x08c)
// CLK_EN

/* CPUCLKDIV Register */
#define CPUCLKDIV               MMIO32(PRCM + 0x0b8)
//...
#define CPUCLKDIV_RATIO 0x00000001

/* I2S Clock Control */
#define I2SBCLKSEL              MMIO32(PRCM + 0x0c8)
//...
#define SPARE_SFT   1
#define SPARE_MSK   0x7fffffff
// BCLK source selector
#define I2S_SRC 0x00000001

/* GPT Scalar */
#define GPTCLKDIV               MMIO32(PRCM + 0x0cc)
// Scalar used for GPTs.
#define GPT_RATIO_DIV1   0x00000000
#define GPT_RATIO_DIV2   0x00000001
#define GPT_RATIO_DIV4   0x00000002
#define GPT_RATIO_DIV8   0x00000003
#define GPT_RATIO_DIV16  0x00000004
#define GPT_RATIO_DIV32  0x00000005
#define GPT_RATIO_DIV64  0x00000006
#define GPT_RATIO_DIV128 0x00000007
#define GPT_RATIO_DIV256 0x00000008

/* I2S Clock Control */
#define I2SCLKCTL               MMIO32(PRCM + 0x0d0)
// On the I2S serial interface, data and WCLK is sampled and clocked.
#define SMPL_ON_POSEDGE     0x00000008
// Decides how the WCLK division ratio is calculated.
#define WCLK_PHASE_SINGLE   0x00000000
#define WCLK_PHASE_DUAL     0x00000002
#define WCLK_PHASE_USER     0x00000004
// 1: Enables the generation of MCLK, BCLK and WCLK
#define I2S_EN              0x00000001

/* MCLK Division Ratio */
#define I2SMCLKDIV              MMIO32(PRCM + 0x0d4)
// An unsigned factor of the division ratio used to generate MCLK [2-1024].
#define MDIV_MSK    0x3ff

/* BCLK Division Ratio */
#define I2SBCLKDIV              MMIO32(PRCM + 0x0d8)
// An unsigned factor of the division ratio used to generate I2S BCLK [2-1024].
#define BDIV_MSK    0x3ff

/* WCLK Division Ratio */
#define I2SWCLKDIV              MMIO32(PRCM + 0x0dc)
// ratio
#define WDIV_MSK    0x3ff

/* SW Initiated Resets */
#define SWRESET                 MMIO32(PRCM + 0x10c)
//...
#define MCU 0x00000004

/* WARM Reset Control And Status */
#define WARMRESET               MMIO32(PRCM + 0x110)
// 1: A warm system reset event triggered by the below listed sources.
#define WR_TO_PINRESET  0x00000004
// 1: A system CPU LOCKUP event has occured since last SW clear of the register.
#define LOCKUP_STAT     0x00000002
// 1: A WDT event has occured since last SW clear of the register.
#define WDT_STAT        0x00000001

/* Power Domain Control */
#define PDCTL0                  MMIO32(PRCM + 0x12c)
// PERIPH Power domain.
#define PERIPH_ON   0x00000004
// SERIAL Power domain.
#define SERIAL_ON   0x00000002
// 1: RFC power domain powered on
#define RFC_ON      0x00000001

/* RFC Power Domain Control */
#define PDCTL0RFC               MMIO32(PRCM + 0x130)
// Alias for PDCTL0.RFC_ON
#define ON  0x00000001

/* SERIAL Power Domain Control */
#define PDCTL0SERIAL            MMIO32(PRCM + 0x134)
//ON

/* PERIPH Power Domain Control */
#define PDCTL0PERIPH            MMIO32(PRCM + 0x138)
//ON

/* Power Domain Status */
#define PDSTAT0                 MMIO32(PRCM + 0x140)
// PERIPH_ON
// SERIAL_ON
// RFC_ON

/* RFC Power Domain Status */
#define PDSTAT0RFC              MMIO32(PRCM + 0x144)
//ON

/* SERIAL Power Domain Status */
#define PDSTAT0SERIAL           MMIO32(PRCM + 0x148)
//ON

/* PERIPH Power Domain Status */
#define PDSTAT0PERIPH           MMIO32(PRCM + 0x14c)
//ON

/* Power Domain Control */
#define PDCTL1                  MMIO32(PRCM + 0x17c)
// 1: VIMS power domain is powered whenever the BUS power domain is powered.
#define VIMS_MODE   0x00000008
// 1: RFC power domain powered on
#define RFC_ON      0x00000004
// 1: Initiates power-on of the CPU power domain.
#define CPU_ON      0x00000002

/* CPU Power Domain Direct Control */
#define PDCTL1CPU               MMIO32(PRCM + 0x184)
//ON

/* RFC Power Domain Direct Control */
#define PDCTL1RFC               MMIO32(PRCM + 0x188)
//ON

/* VIMS Mode Direct Control */
#define PDCTL1VIMS              MMIO32(PRCM + 0x18c)
//ON

/* Power Manager Status */
#define PDSTAT1                 MMIO32(PRCM + 0x194)
// 1: BUS domain is currently accessible
#define BUS_ON      0x00000010
// 1: VIMS domain is currently accessible
#define VIMS_MODE   0x00000008
// 1: RFC domain is currently accessible
#define RFC_ON      0x00000004
// 1: CPU and BUS domains are both currently accessible
#define CPU_ON      0x00000002

/* BUS Power Domain Direct Read Status */
#define PDSTAT1BUS              MMIO32(PRCM + 0x198)
//ON

/* RFC Power Domain Direct Read Status */
#define PDSTAT1RFC              MMIO32(PRCM + 0x19c)
//ON

/* CPU Power Domain Direct Read Status */
#define PDSTAT1CPU              MMIO32(PRCM + 0x1a0)
//ON

/* VIMS Mode Direct Read Status */
#define PDSTAT1VIMS             MMIO32(PRCM + 0x1a4)
//ON

/* Control To RFC */
#define RFCBITS                 MMIO32(PRCM + 0x1cc)
//READ

/* Selected RFC Mode */
#define RFCMODESEL              MMIO32(PRCM + 0x1d0)
// Selects the set of commands that the RFC will accept.
#define CURR_MODE0  0x00000000
#define CURR_MODE1  0x00000001
#define CURR_MODE2  0x00000002
#define CURR_MODE3  0x00000003
#define CURR_MODE4  0x00000004
#define CURR_MODE5  0x00000005
#define CURR_MODE6  0x00000006
#define CURR_MODE7  0x00000007

/* Allowed RFC Modes */
#define RFCMODEHWOPT            MMIO32(PRCM + 0x1d4)
// Permitted RFC modes. More than one mode can be permitted.
#define AVAIL_MODE0  0x00000000
#define AVAIL_MODE1  0x00000001
#define AVAIL_MODE2  0x00000002
#define AVAIL_MODE3  0x00000003
#define AVAIL_MODE4  0x00000004
#define AVAIL_MODE5  0x00000005
#define AVAIL_MODE6  0x00000006
#define AVAIL_MODE7  0x00000007

/* Power Profiler Register */
#define PWRPROFSTAT             MMIO32(PRCM + 0x1e0)
// SW can use these bits to timestamp the application.
#define VALUE_MSK   0xff

/* Memory Retention Control */
#define RAMRETEN                MMIO32(PRCM + 0x224)
// 1: Retention for RFC SRAM enabled
#define RFC         0x00000004
// 1: Memory retention enabled
#define VIMS_TRAM   0x00000001
#define VIMS_CRAM   0x00000002

#endif
