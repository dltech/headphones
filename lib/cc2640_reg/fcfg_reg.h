/*
 * Simple CC2640 headphones
 * Device Configuration registers
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

/* Extern LF clock configuration */
#define EXT_LF_CLK          MMIO32(CCFG + 0xfa8)
// Unsigned integer, selecting the DIO to supply external 32kHz clock as SCLK_LF
#define DIO_SFT             24
#define DIO_MSK             0xff
// Unsigned integer, defining the input frequency of the external clock.
#define RTC_INCREMENT_SFT   0
#define RTC_INCREMENT_MSK   0xffffff

/* Mode Configuration 1 */
#define MODE_CONF_1         MMIO32(CCFG + 0xfac)
// Minimum voltage for when DC/DC should be used if alternate DC/DC setting isen
#define ALT_DCDC_VMIN_1P75      0x00000000
#define ALT_DCDC_VMIN_1P81      0x00100000
#define ALT_DCDC_VMIN_1P88      0x00200000
#define ALT_DCDC_VMIN_1P94      0x00300000
#define ALT_DCDC_VMIN_2P00      0x00400000
#define ALT_DCDC_VMIN_2P06      0x00500000
#define ALT_DCDC_VMIN_2P13      0x00600000
#define ALT_DCDC_VMIN_2P19      0x00700000
#define ALT_DCDC_VMIN_2P25      0x00800000
#define ALT_DCDC_VMIN_2P31      0x00900000
#define ALT_DCDC_VMIN_2P38      0x00a00000
#define ALT_DCDC_VMIN_2P44      0x00b00000
#define ALT_DCDC_VMIN_2P50      0x00c00000
#define ALT_DCDC_VMIN_2P56      0x00d00000
#define ALT_DCDC_VMIN_2P63      0x00e00000
#define ALT_DCDC_VMIN_2P69      0x00f00000
#define ALT_DCDC_VMIN_SFT       20
#define ALT_DCDC_VMIN_MSK       0xf
// Enable DC/DC dithering if alternate DC/DC setting is enabled.
#define ALT_DCDC_DITHER_EN      0x00080000
// Inductor peak current if alternate DC/DC setting is enabled.
#define ALT_DCDC_IPEAK_31M      0x00000000
#define ALT_DCDC_IPEAK_35M      0x00010000
#define ALT_DCDC_IPEAK_39M      0x00020000
#define ALT_DCDC_IPEAK_43M      0x00030000
#define ALT_DCDC_IPEAK_47M      0x00040000
#define ALT_DCDC_IPEAK_51M      0x00050000
#define ALT_DCDC_IPEAK_55M      0x00060000
#define ALT_DCDC_IPEAK_59M      0x00070000
#define ALT_DCDC_IPEAK_SFT      16
#define ALT_DCDC_IPEAK_MSK      0x7
// Signed delta value for IBIAS_INIT.
#define DELTA_IBIAS_INIT_SFT    12
#define DELTA_IBIAS_INIT_MSK    0xf
// Signed delta value for IBIAS_OFFSET.
#define DELTA_IBIAS_OFFSET_SFT  8
#define DELTA_IBIAS_OFFSET_MSK  0xf
// Unsigned value of maximum XOSC startup time (worst case) in units of 100us.
#define XOSC_MAX_START_SFT      0
#define XOSC_MAX_START_MSK      0xff

/* CCFG Size and Disable Flags */
#define SIZE_AND_DIS_FLAGS  MMIO32(CCFG + 0xfb0)
// Total size of CCFG in bytes.
#define SIZE_OF_CCFG_SFT        16
#define SIZE_OF_CCFG_MSK        0xffff
// Reserved for future use.
#define DISABLE_FLAGS_SFT       8
#define DISABLE_FLAGS_MSK       0xff
// Disable TCXO.
#define DIS_TCXO                0x00000008
// Disable GPRAM (or use the 8K VIMS RAM as CACHE RAM).
#define DIS_GPRAM               0x00000004
// Disable alternate DC/DC settings.
#define DIS_ALT_DCDC_SETTING    0x00000002
// Disable XOSC override functionality.
#define DIS_XOSC_OVR            0x00000001

/* Mode Configuration 0 */
#define MODE_CONF           MMIO32(CCFG + 0xfb4)
// Signed delta value to apply to the VDDR_TRIM_SLEEP target, minus one.
#define VDDR_TRIM_SLEEP_DELTA_M7    0x80000000
#define VDDR_TRIM_SLEEP_DELTA_M6    0x90000000
#define VDDR_TRIM_SLEEP_DELTA_M5    0xa0000000
#define VDDR_TRIM_SLEEP_DELTA_M4    0xb0000000
#define VDDR_TRIM_SLEEP_DELTA_M3    0xc0000000
#define VDDR_TRIM_SLEEP_DELTA_M2    0xd0000000
#define VDDR_TRIM_SLEEP_DELTA_M1    0xe0000000
#define VDDR_TRIM_SLEEP_DELTA_M0    0xf0000000
#define VDDR_TRIM_SLEEP_DELTA_1     0x00000000
#define VDDR_TRIM_SLEEP_DELTA_2     0x10000000
#define VDDR_TRIM_SLEEP_DELTA_3     0x20000000
#define VDDR_TRIM_SLEEP_DELTA_4     0x30000000
#define VDDR_TRIM_SLEEP_DELTA_5     0x40000000
#define VDDR_TRIM_SLEEP_DELTA_6     0x50000000
#define VDDR_TRIM_SLEEP_DELTA_7     0x60000000
#define VDDR_TRIM_SLEEP_DELTA_8     0x70000000
#define VDDR_TRIM_SLEEP_DELTA_SFT   28
#define VDDR_TRIM_SLEEP_DELTA_MSK   0xf
// DC/DC during recharge in powerdown.
#define DCDC_RECHARGE               0x08000000
// DC/DC in active mode.
#define DCDC_ACTIVE                 0x04000000
// Reserved for future use.
#define VDDR_EXT_LOAD               0x02000000
// VDDS BOD level.
#define VDDS_BOD_LEVEL              0x01000000
// Select source for SCLK_LF.
#define SCLK_LF_OPTION_31P25        0x00000000
#define SCLK_LF_OPTION_EXT          0x00400000
#define SCLK_LF_OPTION_31P768       0x00800000
#define SCLK_LF_OPTION_RCOSC        0x00c00000
// 0x0: RTOS/driver temperature compensates
#define VDDR_TRIM_SLEEP_TC          0x00200000
// Reserved for future use.
#define RTC_COMP                    0x00100000
// Reserved for future use.
#define XOSC_FREQ_HPOSC             0x00040000
#define XOSC_FREQ_48M               0x00080000
#define XOSC_FREQ_24M               0x000c0000
// Enable modification (delta) to XOSC cap-array.
#define XOSC_CAP_MOD                0x00020000
// Reserved for future use.
#define HF_COMP                     0x00010000
// Signed 8-bit value, directly modifying trimmed XOSC cap-array step value.
#define XOSC_CAPARRAY_DELTA_SFT     8
#define XOSC_CAPARRAY_DELTA_MSK     0xff
// The minimum decoupling capacitance (worst case) on VDDR, in units of 100nF.
#define VDDR_CAP_SFT                0
#define VDDR_CAP_MSK                0xff

/* Voltage Load 0 */
#define VOLT_LOAD_0         MMIO32(CCFG + 0xfb8)
// Reserved for future use.
#define VDDR_EXT_TP45_MSK   0xff
#define VDDR_EXT_TP45_SFT   24
// Reserved for future use.
#define VDDR_EXT_TP25_MSK   0xff
#define VDDR_EXT_TP25_SFT   16
// Reserved for future use.
#define VDDR_EXT_TP5_MSK    0xff
#define VDDR_EXT_TP5_SFT    8
// Reserved for future use.
#define VDDR_EXT_TM15_MSK   0xff
#define VDDR_EXT_TM15_SFT   0

/* Voltage Load 1 */
#define VOLT_LOAD_1         MMIO32(CCFG + 0xfbc)
// Reserved for future use.
#define VDDR_EXT_TP125_MSK  0xff
#define VDDR_EXT_TP125_SFT  24
// Reserved for future use.
#define VDDR_EXT_TP105_MSK  0xff
#define VDDR_EXT_TP105_SFT  16
// Reserved for future use.
#define VDDR_EXT_TP85_MSK   0xff
#define VDDR_EXT_TP85_SFT   8
// Reserved for future use.
#define VDDR_EXT_TM65_MSK   0xff
#define VDDR_EXT_TM65_SFT   0

/* Real Time Clock Offset */
#define RTC_OFFSET          MMIO32(CCFG + 0xfc0)
// Reserved for future use.
#define RTC_COMP_P0_MSK  0xffff
#define RTC_COMP_P0_SFT  16
// Reserved for future use.
#define RTC_COMP_P1_MSK  0xff
#define RTC_COMP_P1_SFT  8
// Reserved for future use.
#define RTC_COMP_P2_MSK  0xff
#define RTC_COMP_P2_SFT  0

/* Frequency Offset */
#define FREQ_OFFSET         MMIO32(CCFG + 0xfc4)
// Reserved for future use.
#define HF_COMP_P0_MSK  0xffff
#define HF_COMP_P0_SFT  16
// Reserved for future use.
#define HF_COMP_P1_MSK  0xff
#define HF_COMP_P1_SFT  8
// Reserved for future use.
#define HF_COMP_P2_MSK  0xff
#define HF_COMP_P2_SFT  0

/* IEEE MAC Address 0 */
#define IEEE_MAC_0          MMIO32(CCFG + 0xfc8)
/* IEEE MAC Address 1 */
#define IEEE_MAC_1          MMIO32(CCFG + 0xfcc)
// ADDR

/* IEEE BLE Address 0 */
#define IEEE_BLE_0          MMIO32(CCFG + 0xfd0)
/* IEEE BLE Address 1 */
#define IEEE_BLE_1          MMIO32(CCFG + 0xfd4)
// ADDR

/* Bootloader Configuration */
#define BL_CONFIG           MMIO32(CCFG + 0xfd8)
// Bootloader enable.
#define BOOTLOADER_ENABLE   0xc5000000
// Sets the active level of the selected DIO number BL_PIN_NUMBER
#define BL_LEVEL            0x00010000
// DIO number that is level checked if the boot loader backdoor is enabled.
#define BL_PIN_NUMBER_SFT   8
#define BL_PIN_NUMBER_MSK   0xff
// Enables the boot loader backdoor.
#define BL_ENABLE           0x000000c5

/* Erase Configuration */
#define ERASE_CONF          MMIO32(CCFG + 0xfdc)
// Chip erase.
#define CHIP_ERASE_DIS_N    0x00000100
// Bank erase.
#define BANK_ERASE_DIS_N    0x00000001

/* TI Options */
#define CCFG_TI_OPTIONS     MMIO32(CCFG + 0xfe0)
// TI Failure Analysis.
#define TI_FA_ENABLE    0xc5

/* Test Access Points Enable 0 */
#define CCFG_TAP_DAP_0      MMIO32(CCFG + 0xfe4)
// Enable CPU DAP.
#define CPU_DAP_ENABLE  0x00c50000
// Enable PRCM TAP.
#define PRCM_TAP_ENABLE 0x0000c500
// Enable Test TAP.
#define TEST_TAP_ENABLE 0x000000c5

/* Test Access Points Enable 1 */
#define CCFG_TAP_DAP_1      MMIO32(CCFG + 0xfe8)
// Enable CPU DAP.
#define PBIST2_TAP_ENABLE 0x00c50000
// Enable PRCM TAP.
#define PBIST1_TAP_ENABLE 0x0000c500
// Enable Test TAP.
#define WUC_TAP_ENABLE    0x000000c5

/* Image Valid */
#define IMAGE_VALID_CONF    MMIO32(CCFG + 0xfec)
// IMAGE_VALID

/* Protect Sectors */
#define CCFG_PROT_31_0      MMIO32(CCFG + 0xff0)
// 0: Sector protected
#define WRT_PROT_SEC_31 0x80000000
#define WRT_PROT_SEC_30 0x40000000
#define WRT_PROT_SEC_29 0x20000000
#define WRT_PROT_SEC_28 0x10000000
#define WRT_PROT_SEC_27 0x08000000
#define WRT_PROT_SEC_26 0x04000000
#define WRT_PROT_SEC_25 0x02000000
#define WRT_PROT_SEC_24 0x01000000
#define WRT_PROT_SEC_23 0x00800000
#define WRT_PROT_SEC_22 0x00400000
#define WRT_PROT_SEC_21 0x00200000
#define WRT_PROT_SEC_20 0x00100000
#define WRT_PROT_SEC_19 0x00080000
#define WRT_PROT_SEC_18 0x00040000
#define WRT_PROT_SEC_17 0x00020000
#define WRT_PROT_SEC_16 0x00010000
#define WRT_PROT_SEC_15 0x00008000
#define WRT_PROT_SEC_14 0x00004000
#define WRT_PROT_SEC_13 0x00002000
#define WRT_PROT_SEC_12 0x00001000
#define WRT_PROT_SEC_11 0x00000800
#define WRT_PROT_SEC_10 0x00000400
#define WRT_PROT_SEC_9  0x00000200
#define WRT_PROT_SEC_8  0x00000100
#define WRT_PROT_SEC_7  0x00000080
#define WRT_PROT_SEC_6  0x00000040
#define WRT_PROT_SEC_5  0x00000020
#define WRT_PROT_SEC_4  0x00000010
#define WRT_PROT_SEC_3  0x00000008
#define WRT_PROT_SEC_2  0x00000004
#define WRT_PROT_SEC_1  0x00000002
#define WRT_PROT_SEC_0  0x00000001
/* Protect Sectors 32-63 */
#define CCFG_PROT_63_32     MMIO32(CCFG + 0xff4)
#define WRT_PROT_SEC_63 0x80000000
#define WRT_PROT_SEC_62 0x40000000
#define WRT_PROT_SEC_61 0x20000000
#define WRT_PROT_SEC_60 0x10000000
#define WRT_PROT_SEC_59 0x08000000
#define WRT_PROT_SEC_58 0x04000000
#define WRT_PROT_SEC_57 0x02000000
#define WRT_PROT_SEC_56 0x01000000
#define WRT_PROT_SEC_55 0x00800000
#define WRT_PROT_SEC_54 0x00400000
#define WRT_PROT_SEC_53 0x00200000
#define WRT_PROT_SEC_52 0x00100000
#define WRT_PROT_SEC_51 0x00080000
#define WRT_PROT_SEC_50 0x00040000
#define WRT_PROT_SEC_49 0x00020000
#define WRT_PROT_SEC_48 0x00010000
#define WRT_PROT_SEC_47 0x00008000
#define WRT_PROT_SEC_46 0x00004000
#define WRT_PROT_SEC_45 0x00002000
#define WRT_PROT_SEC_44 0x00001000
#define WRT_PROT_SEC_43 0x00000800
#define WRT_PROT_SEC_42 0x00000400
#define WRT_PROT_SEC_41 0x00000200
#define WRT_PROT_SEC_40 0x00000100
#define WRT_PROT_SEC_39 0x00000080
#define WRT_PROT_SEC_38 0x00000040
#define WRT_PROT_SEC_37 0x00000020
#define WRT_PROT_SEC_36 0x00000010
#define WRT_PROT_SEC_35 0x00000008
#define WRT_PROT_SEC_34 0x00000004
#define WRT_PROT_SEC_33 0x00000002
#define WRT_PROT_SEC_32 0x00000001
/* Protect Sectors 64-95 */
#define CCFG_PROT_95_64     MMIO32(CCFG + 0xff8)
#define WRT_PROT_SEC_95 0x80000000
#define WRT_PROT_SEC_94 0x40000000
#define WRT_PROT_SEC_93 0x20000000
#define WRT_PROT_SEC_92 0x10000000
#define WRT_PROT_SEC_91 0x08000000
#define WRT_PROT_SEC_90 0x04000000
#define WRT_PROT_SEC_89 0x02000000
#define WRT_PROT_SEC_88 0x01000000
#define WRT_PROT_SEC_87 0x00800000
#define WRT_PROT_SEC_86 0x00400000
#define WRT_PROT_SEC_85 0x00200000
#define WRT_PROT_SEC_84 0x00100000
#define WRT_PROT_SEC_83 0x00080000
#define WRT_PROT_SEC_82 0x00040000
#define WRT_PROT_SEC_81 0x00020000
#define WRT_PROT_SEC_80 0x00010000
#define WRT_PROT_SEC_79 0x00008000
#define WRT_PROT_SEC_78 0x00004000
#define WRT_PROT_SEC_77 0x00002000
#define WRT_PROT_SEC_76 0x00001000
#define WRT_PROT_SEC_75 0x00000800
#define WRT_PROT_SEC_74 0x00000400
#define WRT_PROT_SEC_73 0x00000200
#define WRT_PROT_SEC_72 0x00000100
#define WRT_PROT_SEC_71 0x00000080
#define WRT_PROT_SEC_70 0x00000040
#define WRT_PROT_SEC_69 0x00000020
#define WRT_PROT_SEC_68 0x00000010
#define WRT_PROT_SEC_67 0x00000008
#define WRT_PROT_SEC_66 0x00000004
#define WRT_PROT_SEC_65 0x00000002
#define WRT_PROT_SEC_64 0x00000001
/* Protect Sectors 96-127 */
#define CCFG_PROT_127_96    MMIO32(CCFG + 0xffc)
// 0: Sector protected
#define WRT_PROT_SEC_127 0x80000000
#define WRT_PROT_SEC_126 0x40000000
#define WRT_PROT_SEC_125 0x20000000
#define WRT_PROT_SEC_124 0x10000000
#define WRT_PROT_SEC_123 0x08000000
#define WRT_PROT_SEC_122 0x04000000
#define WRT_PROT_SEC_121 0x02000000
#define WRT_PROT_SEC_120 0x01000000
#define WRT_PROT_SEC_119 0x00800000
#define WRT_PROT_SEC_118 0x00400000
#define WRT_PROT_SEC_117 0x00200000
#define WRT_PROT_SEC_116 0x00100000
#define WRT_PROT_SEC_115 0x00080000
#define WRT_PROT_SEC_114 0x00040000
#define WRT_PROT_SEC_113 0x00020000
#define WRT_PROT_SEC_112 0x00010000
#define WRT_PROT_SEC_111 0x00008000
#define WRT_PROT_SEC_110 0x00004000
#define WRT_PROT_SEC_109 0x00002000
#define WRT_PROT_SEC_108 0x00001000
#define WRT_PROT_SEC_107 0x00000800
#define WRT_PROT_SEC_106 0x00000400
#define WRT_PROT_SEC_105 0x00000200
#define WRT_PROT_SEC_104 0x00000100
#define WRT_PROT_SEC_103 0x00000080
#define WRT_PROT_SEC_102 0x00000040
#define WRT_PROT_SEC_101 0x00000020
#define WRT_PROT_SEC_100 0x00000010
#define WRT_PROT_SEC_99  0x00000008
#define WRT_PROT_SEC_98  0x00000004
#define WRT_PROT_SEC_97  0x00000002
#define WRT_PROT_SEC_96  0x00000001

/* Misc configurations */
#define MISC_CONF_1                     MMIO32(FCFG1 + 0x0a0)
// HW minor revision number
#define DEVICE_MINOR_REV_MSK    0xff

/* MISC_CONF_2 Register */
#define MISC_CONF_2                     MMIO32(FCFG1 + 0x0a4)
// Default value holds log information from production test.
#define HPOSC_COMP_P3_MSK       0xff

/* CONFIG_RF_FRONTEND_DIVn Register */
#define CONFIG_RF_FRONTEND_DIV5         MMIO32(FCFG1 + 0x0c4)
#define CONFIG_RF_FRONTEND_DIV6         MMIO32(FCFG1 + 0x0c8)
#define CONFIG_RF_FRONTEND_DIV10        MMIO32(FCFG1 + 0x0cc)
#define CONFIG_RF_FRONTEND_DIV12        MMIO32(FCFG1 + 0x0d0)
#define CONFIG_RF_FRONTEND_DIV15        MMIO32(FCFG1 + 0x0d4)
#define CONFIG_RF_FRONTEND_DIV30        MMIO32(FCFG1 + 0x0d8)
//...
#define IFAMP_IB_MSK            0xf
#define IFAMP_IB_SFT            28
//...
#define LNA_IB_MSK              0xf
#define LNA_IB_SFT              24
//...
#define IFAMP_TRIM_MSK          0x1f
#define IFAMP_TRIM_SFT          19
//...
#define CTL_PA0_TRIM_MSK        0x1f
#define CTL_PA0_TRIM_SFT        14
//...
#define RFLDO_TRIM_OUTPUT_MSK   0x7f
#define RFLDO_TRIM_OUTPUT_MSK   0

/* CONFIG_SYNTH_DIVn Register */
#define CONFIG_SYNTH_DIV5               MMIO32(FCFG1 + 0x0dc)
#define CONFIG_SYNTH_DIV6               MMIO32(FCFG1 + 0x0e0)
#define CONFIG_SYNTH_DIV10              MMIO32(FCFG1 + 0x0e4)
#define CONFIG_SYNTH_DIV12              MMIO32(FCFG1 + 0x0e8)
#define CONFIG_SYNTH_DIV15              MMIO32(FCFG1 + 0x0ec)
#define CONFIG_SYNTH_DIV30              MMIO32(FCFG1 + 0x0f0)
//...
#define RFC_MDM_DEMIQMC0_MSK    0xffff
#define RFC_MDM_DEMIQMC0_SFT    12
//...
#define LDOVCO_TRIM_OUTPUT_MSK  0x3f
#define LDOVCO_TRIM_OUTPUT_SFT  6
//...
#define SLDO_TRIM_OUTPUT_MSK    0x3f
#define SLDO_TRIM_OUTPUT_SFT    0

/* */
#define CONFIG_MISC_ADC_DIV5            MMIO32(FCFG1 + 0x0f4)
#define CONFIG_MISC_ADC_DIV6            MMIO32(FCFG1 + 0x0f8)
#define CONFIG_MISC_ADC_DIV10           MMIO32(FCFG1 + 0x0fc)
#define CONFIG_MISC_ADC_DIV12           MMIO32(FCFG1 + 0x100)
#define CONFIG_MISC_ADC_DIV15           MMIO32(FCFG1 + 0x104)
#define CONFIG_MISC_ADC_DIV30           MMIO32(FCFG1 + 0x108)
//...
#define RSSI_OFFSET_MSK     0xff
#define RSSI_OFFSET_SFT     9
//...
#define QUANTCTLTHRES_MSK   0x7
#define QUANTCTLTHRES_SFT   6
//...
#define DACTRIM_MSK         0x3f
#define DACTRIM_SFT         0

/* Shadow of DIE_ID_0 register in eFuse */
#define SHDW_DIE_ID_0                   MMIO32(FCFG1 + 0x118)
//ID_31_0
/* Shadow of DIE_ID_1 register in eFuse */
#define SHDW_DIE_ID_1                   MMIO32(FCFG1 + 0x11c)
//ID_63_32
/* Shadow of DIE_ID_2 register in eFuse */
#define SHDW_DIE_ID_2                   MMIO32(FCFG1 + 0x120)
//ID_95_64
/* Shadow of DIE_ID_3 register in eFuse */
#define SHDW_DIE_ID_3                   MMIO32(FCFG1 + 0x124)
//ID_127_96

/* SHDW_OSC_BIAS_LDO_TRIM Register */
#define SHDW_OSC_BIAS_LDO_TRIM          MMIO32(FCFG1 + 0x138)
//...
#define SET_RCOSC_HF_COARSE_RESISTOR_SFT    27
#define SET_RCOSC_HF_COARSE_RESISTOR_MSK    0x3
//...
#define TRIMMAG_SFT                         23
#define TRIMMAG_MSK                         0xf
//...
#define TRIMIREF_SFT                        18
#define TRIMIREF_MSK                        0x1f
//...
#define ITRIM_DIG_LDO_SFT                   16
#define ITRIM_DIG_LDO_MSK                   0x3
//...
#define VTRIM_DIG_SFT                       12
#define VTRIM_DIG_MSK                       0xf
//...
#define VTRIM_COARSE_SFT                    8
#define VTRIM_COARSE_MSK                    0xf
//...
#define RCOSCHF_CTRIM_SFT                   0
#define RCOSCHF_CTRIM_MSK                   0xff

/* SHDW_ANA_TRIM Register */
#define SHDW_ANA_TRIM                   MMIO32(FCFG1 + 0x13c)
//...
#define BOD_BANDGAP_TRIM_CNF_SFT    25
#define BOD_BANDGAP_TRIM_CNF_MSK    0x3
//...
#define VDDR_ENABLE_PG1             0x1000000
//...
#define VDDR_OK_HYS                 0x0800000
//...
#define IPTAT_TRIM_SFT              21
#define IPTAT_TRIM_MSK              0x3
//...
#define VDDR_TRIM_SFT               16
#define VDDR_TRIM_MSK               0x1f
//...
#define TRIMBOD_INTMODE_SFT         11
#define TRIMBOD_INTMODE_MSK         0x1f
//...
#define TRIMBOD_EXTMODE_SFT         6
#define TRIMBOD_EXTMODE_MSK         0x1f
//...
#define TRIMTEMP_SFT                0
#define TRIMTEMP_MSK                0x3f

/* FLASH_NUMBER Register */
#define FLASH_NUMBER                    MMIO32(FCFG1 + 0x164)
//Number of the manufacturing lot that produced this unit.
//LOT_NUMBER

/* FLASH_COORDINATE Register */
#define FLASH_COORDINATE                MMIO32(FCFG1 + 0x16c)
//X coordinate of this unit on the wafer.
#define XCOORDINATE_SFT 16
#define XCOORDINATE_MSK 0xffff
//Y coordinate of this unit on the wafer.
#define YCOORDINATE_SFT 0
#define YCOORDINATE_MSK 0xffff

/* FLASH_E_P Register */
#define FLASH_E_P                       MMIO32(FCFG1 + 0x170)
//...
#define PSU_SFT     24
#define PSU_MSK     0xff
//...
#define ESU_SFT     16
#define ESU_MSK     0xff
//...
#define PVSU_SFT    8
#define PVSU_MSK    0xff
//...
#define EVSU_SFT    0
#define EVSU_MSK    0xff

/* FLASH_C_E_P_R Register */
#define FLASH_C_E_P_R                   MMIO32(FCFG1 + 0x174)
//...
#define RVSU_SFT            24
#define RVSU_MSK            0xff
//...
#define PV_ACCESS_SFT       16
#define PV_ACCESS_MSK       0xff
//...
#define A_EXEZ_SETUP_SFT    12
#define A_EXEZ_SETUP_MSK    0xf
//...
#define CVSU_SFT            0
#define CVSU_MSK            0xfff

/* FLASH_P_R_PV Register */
#define FLASH_P_R_PV                    MMIO32(FCFG1 + 0x178)
//...
#define PH_SFT     24
#define PH_MSK     0xff
//...
#define RH_SFT     16
#define RH_MSK     0xff
//...
#define PVH_SFT    8
#define PVH_MSK    0xff
//...
#define PVH2_SFT   0
#define PVH2_MSK   0xff

/* FLASH_EH_SEQ Register */
#define FLASH_EH_SEQ                    MMIO32(FCFG1 + 0x17c)
//...
#define EH_SFT              24
#define EH_MSK              0xff
//...
#define SEQ_SFT             16
#define SEQ_MSK             0xff
//...
#define VSTAT_SFT           12
#define VSTAT_MSK           0xf
//...
#define SM_FREQUENCY_SFT    0
#define SM_FREQUENCY_MSK    0xfff

/* FLASH_VHV_E Register */
#define FLASH_VHV_E                     MMIO32(FCFG1 + 0x180)
//...
#define VHV_E_START_SFT         16
#define VHV_E_START_MSK         0xffff
//...
#define VHV_E_STEP_HIGHT_SFT    0
#define VHV_E_STEP_HIGHT_MSK    0xffff

/* FLASH_PP Register */
#define FLASH_PP                        MMIO32(FCFG1 + 0x184)
//...
#define PUMP_SU_SFT 24
#define PUMP_SU_MSK 0xff
//...
#define MAX_PP_SFT  0
#define MAX_PP_MSK  0xffff

/* FLASH_PROG_EP Register */
#define FLASH_PROG_EP                   MMIO32(FCFG1 + 0x188)
//...
#define MAX_EP_SFT      16
#define MAX_EP_MSK      0xffff
//...
#define PROGRAM_PW_SFT  0
#define PROGRAM_PW_MSK  0xffff

/* FLASH_ERA_PW Register */
#define FLASH_ERA_PW                    MMIO32(FCFG1 + 0x18c)
// ERASE_PW

/* */
#define FLASH_VHV                       MMIO32(FCFG1 + 0x190)
//...
#define TRIM13_P_SFT    24
#define TRIM13_P_MSK    0xf
//...
#define VHV_P_SFT       16
#define VHV_P_MSK       0xf
//...
#define TRIM13_E_SFT    8
#define TRIM13_E_MSK    0xf
//...
#define VHV_E_SFT       0
#define VHV_E_MSK       0xf

/* FLASH_VHV_PV Register */
#define FLASH_VHV_PV                    MMIO32(FCFG1 + 0x194)
//...
#define TRIM13_PV_SFT   24
#define TRIM13_PV_MSK   0xf
//...
#define VHV_PV_SFT      16
#define VHV_PV_MSK      0xf
//...
#define VCG2P5_SFT      8
#define VCG2P5_MSK      0xf
//...
#define VINH_SFT        0
#define VINH_MSK        0xf

/* FLASH_V Register */
#define FLASH_V                         MMIO32(FCFG1 + 0x198)
//...
#define VSL_P_SFT   24
#define VSL_P_MSK   0xff
//...
#define VWL_P_SFT   16
#define VWL_P_MSK   0xff
//...
#define V_READ_SFT  8
#define V_READ_MSK  0xff

/* User Identification. */
#define USER_ID                         MMIO32(FCFG1 + 0x294)
//...
#define PG_REV_SFT      28
#define PG_REV_MSK      0xf
//...
#define VER_SFT         26
#define VER_MSK         0x3
//...
#define SEQUENCE_SFT    19
#define SEQUENCE_MSK    0xf
//...
#define PKG_SFT         16
#define PKG_MSK         0x7
//...
#define PROTOCOL_SFT    12
#define PROTOCOL_MSK    0xf

/* FLASH_OTP_DATA3 Register */
#define FLASH_OTP_DATA3                 MMIO32(FCFG1 + 0x2b0)
//...
#define EC_STEP_SIZE_SFT    24
#define EC_STEP_SIZE_MSK    0x1ff
//...
#define DO_PRECOND          0x400000
//...
#define MAX_EC_LEVEL_SFT    18
#define MAX_EC_LEVEL_MSK    0xf
//...
#define TRIM_1P7_SFT        16
#define TRIM_1P7_MSK        0x3
//...
#define FLASH_SIZEE_SFT     8
#define FLASH_SIZE_MSK      0xff
//...
#define WAIT_SYSCODE_SFT    0
#define WAIT_SYSCODE_MSK    0xff

/* ANA2_TRIM Register */
#define ANA2_TRIM                       MMIO32(FCFG1 + 0x2b4)
//...
#define RCOSCHFCTRIMFRACT_EN            0x80000000
//...
#define RCOSCHFCTRIMFRACT_SFT           26
#define RCOSCHFCTRIMFRACT_MSK           0x1f
//...
#define SET_RCOSC_HF_FINE_RESISTOR_SFT  23
#define SET_RCOSC_HF_FINE_RESISTOR_MSK  0x3
//...
#define ATESTLF_UDIGLDO_IBIAS_TRIM      0x00400000
//...
#define NANOAMP_RES_TRIM_SFT            16
#define NANOAMP_RES_TRIM_MSK            0x3f
//...
#define DITHER_EN                       0x00000800
//...
#define DCDC_IPEAK_SFT                  8
#define DCDC_IPEAK_MSK                  0x7
//...
#define DEAD_TIME_TRIM_SFT              6
#define DEAD_TIME_TRIM_MSK              0x3
//...
#define DCDC_LOW_EN_SEL_SFT             3
#define DCDC_LOW_EN_SEL_MSK             0x7
//...
#define DCDC_HIGH_EN_SEL_SFT            0
#define DCDC_HIGH_EN_SEL_MSK            0x7

/* LDO_TRIM Register */
#define LDO_TRIM                        MMIO32(FCFG1 + 0x2b8)
//...
#define VDDR_TRIM_SLEEP_SFT     24
#define VDDR_TRIM_SLEEP_MSK     0x1f
//...
#define GLDO_CURSRC_SFT         16
#define GLDO_CURSRC_MSK         0x7
//...
#define ITRIM_DIGLDO_LOAD_SFT   11
#define ITRIM_DIGLDO_LOAD_MSK   0x3
//...
#define ITRIM_UDIGLDO_SFT       8
#define ITRIM_UDIGLDO_MSK       0x7
//...
#define VTRIM_DELTA_SFT         0
#define VTRIM_DELTA_MSK         0x7

/* MAC_BLE_0 Register */
#define MAC_BLE_0                       MMIO32(FCFG1 + 0x2e8)
// ADDR_0_31
/* MAC_BLE_1 Register */
#define MAC_BLE_1                       MMIO32(FCFG1 + 0x2ec)
// ADDR_32_63

/* MAC IEEE 802.15.4 Address 0 */
#define MAC_15_4_0                      MMIO32(FCFG1 + 0x2f0)
// ADDR_0_31
/* MAC IEEE 802.15.4 Address 1 */
#define MAC_15_4_1                      MMIO32(FCFG1 + 0x2f4)
//ADDR_32_63

/* FLASH_OTP_DATA4 Register */
#define FLASH_OTP_DATA4                 MMIO32(FCFG1 + 0x308)
//...
#define STANDBY_MODE_SEL_INT_WRT    0x80000000
//...
#define STANDBY_PW_SEL_INT_WRT_SFT  29
#define STANDBY_PW_SEL_INT_WRT_MSK  0x3
//...
#define DIS_STANDBY_INT_WRT         0x10000000
//...
#define DIS_IDLE_INT_WRT            0x08000000
//...
#define VIN_AT_X_INT_WRT_SFT        24
#define VIN_AT_X_INT_WRT_MSK        0x7
//...
#define STANDBY_MODE_SEL_EXT_WRT    0x00800000
//...
#define STANDBY_PW_SEL_EXT_WRT_SFT  21
#define STANDBY_PW_SEL_EXT_WRT_MSK  0x3
//...
#define DIS_STANDBY_EXT_WRT         0x00100000
//...
#define DIS_IDLE_EXT_WRT            0x00080000
//...
#define VIN_AT_X_EXT_WRT_SFT        16
#define VIN_AT_X_EXT_WRT_MSK        0x7
//...
#define STANDBY_MODE_SEL_INT_RD     0x00008000
//...
#define STANDBY_PW_SEL_INT_RD_SFT   13
#define STANDBY_PW_SEL_INT_RD_MSK   0x3
//...
#define DIS_STANDBY_INT_RD          0x00001000
//...
#define DIS_IDLE_INT_RD_WRT         0x00000800
//...
#define VIN_AT_X_INT_RD_SFT         8
#define VIN_AT_X_INT_RD_MSK         0x7
//...
#define STANDBY_MODE_SEL_EXT_RD     0x00000080
//...
#define STANDBY_PW_SEL_EXT R_RD_SFT 5
#define STANDBY_PW_SEL_EXT R_RD_MSK 0x3
//...
#define DIS_STANDBY_EXT_RD_WRT      0x00000010
//...
#define DIS_IDLE_EXT_RD_WRT         0x00000008
//...
#define VIN_AT_X_EXT_RD_SFT         0
#define VIN_AT_X_EXT_RD_MSK         0x7

/* Miscellaneous Trim Parameters */
#define MISC_TRIM                       MMIO32(FCFG1 + 0x30c)
//...
#define TEMPVSLOPE_SFT  0
#define TEMPVSLOPE_MSK  0xff

/* RCOSC_HF_TEMPCOMP Register */
#define RCOSC_HF_TEMPCOMP               MMIO32(FCFG1 + 0x310)
//...
#define FINE_RESISTOR_SFT       24
#define FINE_RESISTOR_MSK       0xff
//...
#define CTRIM_SFT               16
#define CTRIM_MSK               0xff
//...
#define CTRIMFRACT_QUAD_SFT     8
#define CTRIMFRACT_QUAD_MSK     0xff
//...
#define CTRIMFRACT_SLOPE_SFT    0
#define CTRIMFRACT_SLOPE_MSK    0xff

/* IcePick Device Identification */
#define ICEPICK_DEVICE_ID               MMIO32(FCFG1 + 0x318)
// Field used to distinguish revisions of the device.
#define CTRIM_SFT           28
#define CTRIM_MSK           0xf
// Field used to identify silicon die.
#define WAFER_ID_SFT        12
#define WAFER_ID_MSK        0xffff
// Manufacturer code.
#define MANUFACTURER_ID_SFT 0
#define MANUFACTURER_ID_MSK 0xfff

/* Factory Configuration (FCFG1) Revision */
#define FCFG1_REVISION                  MMIO32(FCFG1 + 0x31c)
//REV

/* Misc OTP Data */
#define MISC_OTP_DATA                   MMIO32(FCFG1 + 0x320)
//...
#define RCOSC_HF_ITUNE_SFT      28
#define RCOSC_HF_ITUNE_MSK      0xf
//...
#define RCOSC_HF_CRIM_SFT       20
#define RCOSC_HF_CRIM_MSK       0xff
//...
#define PER_M_SFT               15
#define PER_M_MSK               0x1ff
//...
#define PER_E_SFT               12
#define PER_E_MSK               0x7
//...
#define PO_TAIL_RES_TRIM_SFT    8
#define PO_TAIL_RES_TRIM_MSK    0xf
//The revision of the test program used in the production process.
#define TEST_PROGRAM_REV_SFT    0
#define TEST_PROGRAM_REV_MSK    0xff

/* IO Configuration */
#define IOCONF                          MMIO32(FCFG1 + 0x344)
// Number of available DIOs.
#define GPIO_CNT_SFT    0
#define GPIO_CNT_MSK    0x7f

/* CONFIG_IF_ADC Register */
#define CONFIG_IF_ADC                   MMIO32(FCFG1 + 0x34c)
//...
#define FF2ADJ_SFT                  28
#define FF2ADJ_MSK                  0xf
//...
#define FF3ADJ_SFT                  24
#define FF3ADJ_MSK                  0xf
//...
#define INT3ADJ_SFT                 20
#define INT3ADJ_MSK                 0xf
//...
#define FF1ADJ_SFT                  16
#define FF1ADJ_MSK                  0xf
//...
#define AAFCAP_SFT                  14
#define AAFCAP_MSK                  0x3
//...
#define INT2ADJ_SFT                 10
#define INT2ADJ_MSK                 0xf
//...
#define IFDIGLDO_TRIM_OUTPUT_SFT    5
#define IFDIGLDO_TRIM_OUTPUT_MSK    0x1f
//...
#define IFANALDO_TRIM_OUTPUT_SFT    0
#define IFANALDO_TRIM_OUTPUT_MSK    0x1f

/* CONFIG_OSC_TOP Register */
#define CONFIG_OSC_TOP                  MMIO32(FCFG1 + 0x350)
//...
#define XOSC_HF_ROW_Q12_SFT     26
#define XOSC_HF_ROW_Q12_MSK     0xf
//...
#define XOSC_HF_COLUMN_Q12_SFT  10
#define XOSC_HF_COLUMN_Q12_MSK  0xffff
//...
#define RCOSCLF_CTUNE_TRIM_SFT  2
#define RCOSCLF_CTUNE_TRIM_MSK  0xff
//...
#define RCOSCLF_RTUNE_TRIM_SFT  0
#define RCOSCLF_RTUNE_TRIM_MSK  0x3

/* CONFIG_RF_FRONTEND Register */
#define CONFIG_RF_FRONTEND              MMIO32(FCFG1 + 0x354)
//...
#define IFAMP_IB_SFT            28
#define IFAMP_IB_MSK            0xf
//...
#define LNA_IB_SFT              24
#define LNA_IB_MSK              0xf
//...
#define IFAMP_TRIM_SFT          19
#define IFAMP_TRIM_MSK          0x1f
//...
#define CTL_PA0_TRIM_SFT        14
#define CTL_PA0_TRIM_MSK        0x1f
//...
#define PATRIMCOMPLETE_N_MSK    0x2000
//...
#define RFLDO_TRIM_OUTPUT_SFT   0
#define RFLDO_TRIM_OUTPUT_MSK   0x7f

/* CONFIG_SYNTH Register */
#define CONFIG_SYNTH                    MMIO32(FCFG1 + 0x358)
//...
#define RFC_MDM_DEMIQMC0_SFT    12
#define RFC_MDM_DEMIQMC0_MSK    0xffff
//...
#define LDOVCO_TRIM_OUTPUT_SFT  6
#define LDOVCO_TRIM_OUTPUT_MSK  0x3f
//...
#define SLDO_TRIM_OUTPUT_SFT    0
#define SLDO_TRIM_OUTPUT_MSK    0x3f

/* AUX_ADC Gain in Absolute Reference Mode */
#define SOC_ADC_ABS_GAIN                MMIO32(FCFG1 + 0x35c)
// SOC_ADC gain in absolute reference mode at temperature 1 (30C).
#define SOC_ADC_ABS_GAIN_TEMP1_SFT    0
#define SOC_ADC_ABS_GAIN_TEMP1_MSK    0xffff

/* AUX_ADC Gain in Relative Reference Mode */
#define SOC_ADC_REL_GAIN                MMIO32(FCFG1 + 0x360)
// SOC_ADC gain in relative reference mode at temperature 1 (30C).
#define SOC_ADC_REL_GAIN_TEMP1_SFT    0
#define SOC_ADC_REL_GAIN_TEMP1_MSK    0xffff

/* AUX_ADC Temperature Offsets in Absolute Reference Mode */
#define SOC_ADC_OFFSET_INT              MMIO32(FCFG1 + 0x368)
// SOC_ADC offset in relative reference mode at temperature 1 (30C).
#define SOC_ADC_REL_OFFSET_TEMP1_SFT    16
#define SOC_ADC_REL_OFFSET_TEMP1_MSK    0xff
// SOC_ADC offset in absolute reference mode at temperature 1 (30C).
#define SOC_ADC_ABS_OFFSET_TEMP1_SFT    0
#define SOC_ADC_ABS_OFFSET_TEMP1_MSK    0xff

/* SOC_ADC_REF_TRIM_AND_OFFSET_EXT Register */
#define SOC_ADC_REF_TRIM_AND_OFFSET_EXT MMIO32(FCFG1 + 0x36c)
//...
#define SOC_ADC_REF_VOLTAGE_TRIM_TEMP1_SFT    0
#define SOC_ADC_REF_VOLTAGE_TRIM_TEMP1_MSK    0x3f

/* AMPCOMP_TH1 Register */
#define AMPCOMP_TH1                     MMIO32(FCFG1 + 0x370)
//...
#define HPMRAMP3_LTH_SFT            18
#define HPMRAMP3_LTH_MSK            0x3f
//...
#define HPMRAMP3_HTH_SFT            10
#define HPMRAMP3_HTH_MSK            0x3f
//...
#define IBIASCAP_LPTOHP_OL_CNT_SFT  6
#define IBIASCAP_LPTOHP_OL_CNT_MSK  0xf
//...
#define HPMRAMP1_TH_SFT             0
#define HPMRAMP1_TH_MSK             0x3f

/* AMPCOMP_TH2 Register */
#define AMPCOMP_TH2                     MMIO32(FCFG1 + 0x374)
//...
#define LPMUPDATE_LTH_SFT       26
#define LPMUPDATE_LTH_MSK       0x3f
//...
#define LPMUPDATE_HTM_SFT       18
#define LPMUPDATE_HTM_MSK       0x3f
//...
#define ADC_COMP_AMPTH_LPM_SFT  10
#define ADC_COMP_AMPTH_LPM_MSK  0xf
//...
#define ADC_COMP_AMPTH_HPM_SFT  0
#define ADC_COMP_AMPTH_HPM_MSK  0x3f

/* AMPCOMP_CTRL1 Register */
#define AMPCOMP_CTRL1                   MMIO32(FCFG1 + 0x378)
//...
#define AMPCOMP_REQ_MODE                0x40000000
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

/* ANABYPASS_VALUE2 Register */
#define ANABYPASS_VALUE2                MMIO32(FCFG1 + 0x37c)
//...
#define XOSC_HF_IBIASTHERM_SFT  0
#define XOSC_HF_IBIASTHERM_MSK  0x3fff

/* CONFIG_MISC_ADC Register */
#define CONFIG_MISC_ADC                 MMIO32(FCFG1 + 0x380)
//...
#define RSSITRIMCOMPLETE_N  0x00020000
//...
#define RSSI_OFFSET_SFT     9
#define RSSI_OFFSET_MSK     0xff
//...
#define QUANTCTLTHRES_SFT   6
#define QUANTCTLTHRES_MSK   0x7
//...
#define DACTRIM_SFT         0
#define DACTRIM_MSK         0x3f

/* VOLT_TRIM Register */
#define VOLT_TRIM                       MMIO32(FCFG1 + 0x388)
//...
#define VDDR_TRIM_HH_SFT        24
#define VDDR_TRIM_HH_MSK        0x1f
//...
#define VDDR_TRIM_H_SFT         16
#define VDDR_TRIM_H_MSK         0x1f
//...
#define VDDR_TRIM_SLEEP_H_SFT   8
#define VDDR_TRIM_SLEEP_H_MSK   0x1f
//...
#define TRIMBOD_H_SFT           0
#define TRIMBOD_H_MSK           0x1f

/* OSC Configuration */
#define OSC_CONF                        MMIO32(FCFG1 + 0x38c)
// Trim value for DDI_0_OSC:ADCDOUBLERNANOAMPCTL.ADC_SH_VBUF_EN.
#define ADC_SH_VBUF_EN                  0x20000000
// Trim value for DDI_0_OSC:ADCDOUBLERNANOAMPCTL.ADC_SH_MODE_EN.
#define ADC_SH_MODE_EN                  0x10000000
// Trim value for DDI_0_OSC:ATESTCTL.ATESTLF_RCOSCLF_IBIAS_TRIM.
#define ATESTLF_RCOSCLF_IBIAS_TRIM      0x08000000
// Trim value for DDI_0_OSC:LFOSCCTL.XOSCLF_REGULATOR_TRIM.
#define XOSCLF_REGULATOR_TRIM_SFT       25
#define XOSCLF_REGULATOR_TRIM_MSK       0x3
// Trim value for DDI_0_OSC:LFOSCCTL.XOSCLF_CMIRRWR_RATIO.
#define XOSCLF_CMIRRWR_RATIO_SFT        21
#define XOSCLF_CMIRRWR_RATIO_MSK        0xf
// Trim value for DDI_0_OSC:LFOSCCTL.XOSCLF_CMIRRWR_RATIO.
#define XOSC_HF_FAST_START_SFT          19
#define XOSC_HF_FAST_START_MSK          0x3
// 1: XOSC_HF available (default)
#define XOSC_OPTION                     0x00040000
//...
#define HPOSC_OPTION                    0x00020000
//...
#define HPOSC_BIAS_HOLD_MODE_EN         0x00010000
//...
#define HPOSC_CURRMIRR_RATIO_SFT        12
#define HPOSC_CURRMIRR_RATIO_MSK        0xf
//...
#define HPOSC_BIAS_RES_SET_SFT          8
#define HPOSC_BIAS_RES_SET_MSK          0xf
//...
#define HPOSC_FILTER_EN                 0x00000080
//...
#define HPOSC_BIAS_RECHARGE_DELAY_SFT   5
#define HPOSC_BIAS_RECHARGE_DELAY_MSK   0x3
//...
#define HPOSC_SERIES_CAP_SFT            1
#define HPOSC_SERIES_CAP_MSK            0x3
//...
#define HPOSC_DIV3_BYPASS               0x00000001

/* FREQ_OFFSET Register */
#define FREQ_OFFSET                     MMIO32(FCFG1 + 0x390)
//...
#define HPOSC_COMP_P0_SFT   16
#define HPOSC_COMP_P0_MSK   0xffff
//...
#define HPOSC_COMP_P1_SFT   8
#define HPOSC_COMP_P1_MSK   0xff
//...
#define HPOSC_COMP_P2_SFT   0
#define HPOSC_COMP_P2_MSK   0xff

/* CAP_TRIM Register */
#define CAP_TRIM                        MMIO32(FCFG1 + 0x394)
//...
#define FLUX_CAP_0P28_TRIM_SFT  16
#define FLUX_CAP_0P28_TRIM_MSK  0xffff
//...
#define FLUX_CAP_0P4_TRIM_SFT   0
#define FLUX_CAP_0P4_TRIM_MSK   0xffff

/* MISC_OTP_DATA_1 Register */
#define MISC_OTP_DATA_1                 MMIO32(FCFG1 + 0x398)
//...
#define PEAK_DET_ITRIM_SFT                  27
#define PEAK_DET_ITRIM_MSK                  0x3
//...
#define HP_BUF_ITRIM_SFT                    24
#define HP_BUF_ITRIM_MSK                    0x7
//...
#define LP_BUF_ITRIM_SFT                    22
#define LP_BUF_ITRIM_MSK                    0x3
//...
#define DBLR_LOOP_FILTER_RESET_VOLTAGE_SFT  20
#define DBLR_LOOP_FILTER_RESET_VOLTAGE_MSK  0x3
//...
#define HPM_IBIAS_WAIT_CNT_SFT              10
#define HPM_IBIAS_WAIT_CNT_MSK              0x3ff
//...
#define LPM_IBIAS_WAIT_CNT_SFT              4
#define LPM_IBIAS_WAIT_CNT_MSK              0x3f
//...
#define IDAC_STEP_SFT                       0
#define IDAC_STEP_MSK                       0xf

/* Power Down Current Control xC */
#define PWD_CURR_20C                    MMIO32(FCFG1 + 0x39c)
#define PWD_CURR_35C                    MMIO32(FCFG1 + 0x3a0)
#define PWD_CURR_50C                    MMIO32(FCFG1 + 0x3a4)
#define PWD_CURR_65C                    MMIO32(FCFG1 + 0x3a8)
#define PWD_CURR_80C                    MMIO32(FCFG1 + 0x3ac)
#define PWD_CURR_95C                    MMIO32(FCFG1 + 0x3b0)
#define PWD_CURR_110C                   MMIO32(FCFG1 + 0x3b4)
#define PWD_CURR_125C                   MMIO32(FCFG1 + 0x3b8)
// Additional maximum current, in units of 1uA, with cache retention
#define DELTA_CACHE_REF_SFT 24
#define DELTA_CACHE_REF_MSK 0xff
// Additional maximum current, in 1uA units, with RF memory retention
#define DELTA_RFMEM_RET_SFT 16
#define DELTA_RFMEM_RET_MSK 0xff
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-powermode
#define DELTA_XOSC_LPM_SFT  8
#define DELTA_XOSC_LPM_MSK  0xff
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define BASELINE_SFT        0
#define BASELINE_MSK        0xff
