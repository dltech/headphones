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

/* */
#define EXT_LF_CLK          MMIO32(CCFG + 0xfa8)

/* */
#define MODE_CONF_1         MMIO32(CCFG + 0xfac)

/* */
#define SIZE_AND_DIS_FLAGS  MMIO32(CCFG + 0xfb0)

/* */
#define MODE_CONF           MMIO32(CCFG + 0xfb4)

/* */
#define VOLT_LOAD_0         MMIO32(CCFG + 0xfb8)

/* */
#define VOLT_LOAD_1         MMIO32(CCFG + 0xfbc)

/* */
#define RTC_OFFSET          MMIO32(CCFG + 0xfc0)

/* */
#define FREQ_OFFSET         MMIO32(CCFG + 0xfc4)

/* */
#define IEEE_MAC_0          MMIO32(CCFG + 0xfc8)

/* */
#define IEEE_MAC_1          MMIO32(CCFG + 0xfcc)

/* */
#define IEEE_BLE_0          MMIO32(CCFG + 0xfd0)

/* */
#define IEEE_BLE_1          MMIO32(CCFG + 0xfd4)

/* */
#define BL_CONFIG           MMIO32(CCFG + 0xfd8)

/* */
#define ERASE_CONF          MMIO32(CCFG + 0xfdc)

/* */
#define CCFG_TI_OPTIONS     MMIO32(CCFG + 0xfe0)

/* */
#define CCFG_TAP_DAP_0      MMIO32(CCFG + 0xfe4)

/* */
#define CCFG_TAP_DAP_1      MMIO32(CCFG + 0xfe8)

/* */
#define IMAGE_VALID_CONF    MMIO32(CCFG + 0xfec)

/* */
#define CCFG_PROT_31_0      MMIO32(CCFG + 0xff0)

/* */
#define CCFG_PROT_63_32     MMIO32(CCFG + 0xff4)

/* */
#define CCFG_PROT_95_64     MMIO32(CCFG + 0xff8)

/* */
#define CCFG_PROT_127_96    MMIO32(CCFG + 0xffc)



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

/* */
#define SOC_ADC_REF_TRIM_AND_OFFSET_EXT MMIO32(FCFG1 + 0x36c)

/* */
#define AMPCOMP_TH1                     MMIO32(FCFG1 + 0x370)

/* */
#define AMPCOMP_TH2                     MMIO32(FCFG1 + 0x374)

/* */
#define AMPCOMP_CTRL1                   MMIO32(FCFG1 + 0x378)

/* */
#define ANABYPASS_VALUE2                MMIO32(FCFG1 + 0x37c)

/* */
#define CONFIG_MISC_ADC                 MMIO32(FCFG1 + 0x380)

/* */
#define VOLT_TRIM                       MMIO32(FCFG1 + 0x388)

/* */
#define OSC_CONF                        MMIO32(FCFG1 + 0x38c)

/* */
#define FREQ_OFFSET                     MMIO32(FCFG1 + 0x390)

/* */
#define CAP_TRIM                        MMIO32(FCFG1 + 0x394)

/* */
#define MISC_OTP_DATA_1                 MMIO32(FCFG1 + 0x398)

/* */
#define PWD_CURR_20C                    MMIO32(FCFG1 + 0x39c)
#define PWD_CURR_35C                    MMIO32(FCFG1 + 0x3a0)
#define PWD_CURR_50C                    MMIO32(FCFG1 + 0x3a4)
#define PWD_CURR_65C                    MMIO32(FCFG1 + 0x3a8)
#define PWD_CURR_80C                    MMIO32(FCFG1 + 0x3ac)
#define PWD_CURR_95C                    MMIO32(FCFG1 + 0x3b0)
#define PWD_CURR_110C                   MMIO32(FCFG1 + 0x3b4)
#define PWD_CURR_125C                   MMIO32(FCFG1 + 0x3b8)
