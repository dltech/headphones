#ifndef H_MEMORY_REGS
#define H_MEMORY_REGS
/*
 * Simple CC2640 headphones
 * Versatile Instruction Memory System registers
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

/* FMC and Efuse Status */
#define FLASH_STAT          MMIO32(FLASH + 0x001c)
// Efuse scanning detected if fuse ROM is blank.
#define EFUSE_BLANK     0x8000
// Efuse scanning resulted in timeout error.
#define EFUSE_TIMEOUT   0x4000
// Efuse scanning resulted in scan chain CRC error.
#define EFUSE_CRC_ERROR 0x2000
// Same as EFUSEERROR.CODE
#define EFUSE_ERRCODE   ((FLASH_STAT >> 8) & 0x1f)
// Status indicator of flash sample and hold sequencing logic.
#define SAMHOLD_DIS     0x0004
// Fast version of the FMC FMSTAT.BUSY bit.
#define BUSY            0x0002
// Power state of the flash sub-system.
#define POWER_MODE      0x0001

/* CFG Register */
#define CFG                 MMIO32(FLASH + 0x0024)
//...
#define STANDBY_MODE_SEL    0x100
// STANDBY_PW_SEL
//...
#define DIS_EFUSECLK        0x020
//...
#define DIS_READACCESS      0x010
//...
#define ENABLE_SWINTF       0x008
//...
#define DIS_STANDBY         0x002
//...
#define DIS_IDLE            0x001

/* SYSCODE_START Register */
#define SYSCODE_START       MMIO32(FLASH + 0x0028)
// SYSCODE_START

/* FLASH_SIZE Register */
#define FLASH_SIZE          MMIO32(FLASH + 0x002c)
// SECTORS

/* FWLOCK Register */
#define FWLOCK              MMIO32(FLASH + 0x003c)
// FWLOCK

/* FWFLAG Register */
#define FWFLAG              MMIO32(FLASH + 0x0040)
// FWFLAG

/* EFUSE Register */
#define EFUSE               MMIO32(FLASH + 0x1000)
// INSTRUCTION
// DUMPWORD

/* EFUSEADDR Register */
#define EFUSEADDR           MMIO32(FLASH + 0x1004)
// BLOCK
// ROW

/* DATAUPPER Register */
#define DATAUPPER           MMIO32(FLASH + 0x1008)
// SPARE
// ...
#define P   0x4
// ...
#define R   0x2
// ...
#define EEN 0x1

/* DATALOWER Register */
#define DATALOWER           MMIO32(FLASH + 0x100c)
// DATA

/* EFUSECFG Register */
#define EFUSECFG            MMIO32(FLASH + 0x1010)
// ...
#define IDLEGATING  0x100
// SLAVEPOWER
// ...
#define GATING      0x001

/* EFUSESTAT Register */
#define EFUSESTAT           MMIO32(FLASH + 0x1014)
// ...
#define RESETDONE   0x1

/* ACC Register */
#define ACC                 MMIO32(FLASH + 0x1018)
// ...
#define ACCUMULATOR_MSK 0xffffff

/* BOUNDARY Register */
#define BOUNDARY            MMIO32(FLASH + 0x101c)
//...
#define DISROW0                 0x800000
//...
#define SPARE                   0x400000
//...
#define EFC_SELF_TEST_ERROR     0x200000
//...
#define EFC_INSTRUCTION_INFO    0x100000
//...
#define EFC_INSTRUCTION_ERROR   0x080000
//...
#define EFC_AUTOLOAD_ERROR      0x040000
//OUTPUTENABLE
//...
#define SYS_ECC_SELF_TEST_EN    0x002000
//...
#define SYS_ECC_OVERRIDE_EN     0x001000
//...
#define EFC_FDI                 0x000800
//...
#define SYS_DIEID_AUTOLOAD_EN   0x000400
// SYS_REPAIR_EN
// SYS_WS_READ_STATES
// INPUTENABLE

/* EFUSEFLAG Register */
#define EFUSEFLAG           MMIO32(FLASH + 0x1020)
//...
#define KEY     0x1

/* EFUSEKEY Register */
#define EFUSEKEY            MMIO32(FLASH + 0x1024)
// CODE

/* EFUSERELEASE Register */
#define EFUSERELEASE        MMIO32(FLASH + 0x1028)
// ODPYEAR
// ODPMONTH
// ODPDAY
// EFUSEYEAR
// EFUSEMONTH
// EFUSEDAY

/* EFUSEPINS Register */
#define EFUSEPINS           MMIO32(FLASH + 0x102c)
//...
#define EFC_SELF_TEST_DONE      0x8000
//...
#define EFC_SELF_TEST_ERROR     0x4000
//...
#define SYS_ECC_SELF_TEST_EN    0x2000
//...
#define EFC_INSTRUCTION_INFO    0x1000
//...
#define EFC_INSTRUCTION_ERROR   0x0800
//...
#define EFC_AUTOLOAD_ERROR      0x0400
//...
#define SYS_ECC_OVERRIDE_EN     0x0200
//...
#define EFC_READY               0x0100
//...
#define EFC_FCLRZ               0x0080
//...
#define SYS_DIEID_AUTOLOAD_EN   0x0040
//SYS_REPAIR_EN
//SYS_WS_READ_STATES

/* EFUSECRA Register */
#define EFUSECRA            MMIO32(FLASH + 0x1030)
// DATA

/* */
#define EFUSEREAD           MMIO32(FLASH + 0x1034)
//DATABIT
//READCLOCK
//...
#define DEBUG   0x8
//...
#define SPARE   0x4
//MARGIN

/* EFUSEPROGRAM Register */
#define EFUSEPROGRAM        MMIO32(FLASH + 0x1038)
//...
#define COMPAREDISABLE  0x40000000
//CLOCKSTALL
//...
#define VPPTOVDD        0x00002000
//ITERATIONS
//WRITECLOCK

/* EFUSEERROR Register */
#define EFUSEERROR          MMIO32(FLASH + 0x103c)
//...
#define DONE    0x20
// CODE

/* SINGLEBIT Register */
#define SINGLEBIT           MMIO32(FLASH + 0x1040)
//FROMN
//...
#define FROM0   0x1

/* TWOBIT Register */
#define TWOBIT              MMIO32(FLASH + 0x1044)
//FROMN
//FROM0

/* SELFTESTCYC Register */
#define SELFTESTCYC         MMIO32(FLASH + 0x1048)
// CYCLES

/* SELFTESTSIGN Register */
#define SELFTESTSIGN        MMIO32(FLASH + 0x104c)
// SIGNATURE

/* FRDCTL Register */
#define FRDCTL              MMIO32(FLASH + 0x2000)
//RWAIT
//RM

/* FSPRD Register */
#define FSPRD               MMIO32(FLASH + 0x2004)
//DIS_PREEMPT
//RMBSEM
//...
#define RM1 0x2
//...
#define RM0 0x1

/* FEDACCTL1 Register */
#define FEDACCTL1           MMIO32(FLASH + 0x2008)
//SUSP_IGNR
//EDACEN

/* FEDACSTAT Register */
#define FEDACSTAT           MMIO32(FLASH + 0x201c)
//...
#define RVF_INT     0x2000000
//...
#define FSM_DONE    0x1000000
//ERR_PRF_FLG

/* FBPROT Register */
#define FBPROT              MMIO32(FLASH + 0x2030)
//...
#define PROTL1DIS   0x1

/* FBSE Register */
#define FBSE                MMIO32(FLASH + 0x2034)
//BSE

/* FBBUSY Register */
#define FBBUSY              MMIO32(FLASH + 0x2038)
// BUSY

/* FBAC Register */
#define FBAC                MMIO32(FLASH + 0x203c)
//...
#define OTPPROTDIS  0x10000
//BAGP
//VREADS

/* FBFALLBACK Register */
#define FBFALLBACK          MMIO32(FLASH + 0x2040)
//FSM_PWRSAV
//REG_PWRSAV
//BANKPWR7
//BANKPWR6
//BANKPWR5
//BANKPWR4
//BANKPWR3
//BANKPWR2
//BANKPWR1
//BANKPWR0

/* FBPRDY Register */
#define FBPRDY              MMIO32(FLASH + 0x2044)
//...
#define BANKBUSY    0x10000
//...
#define PUMPRDY     0x08000
//...
#define BANKRDY     0x00001

/* FPAC1 Register */
#define FPAC1               MMIO32(FLASH + 0x2048)
//PSLEEPTDIS
//PUMPRESET_PW
//PUMPPWR

/* FPAC2 Register */
#define FPAC2               MMIO32(FLASH + 0x204c)
//PAGP

/* FMAC Register */
#define FMAC                MMIO32(FLASH + 0x2050)
// BANK

/* FMSTAT Register */
#define FMSTAT              MMIO32(FLASH + 0x2054)
//...
#define RVSUSP  0x20000
//...
#define RDVER   0x10000
//...
#define RVF     0x08000
//...
#define ILA     0x04000
//...
#define DBF     0x02000
//...
#define PGV     0x01000
//...
#define PCV     0x00800
//...
#define EV      0x00400
//...
#define CV      0x00200
//...
#define BUSY    0x00100
//...
#define ERS     0x00080
//...
#define PGM     0x00040
//...
#define INVDAT  0x00020
//...
#define CSTAT   0x00010
//...
#define VOLSTAT 0x00008
//...
#define ESUSP   0x00004
//...
#define PSUSP   0x00002
//...
#define SLOCK   0x00001

/* FLOCK Register */
#define FLOCK               MMIO32(FLASH + 0x2064)
//ENCOM

/* FVREADCT Register */
#define FVREADCT            MMIO32(FLASH + 0x2080)
//VREADCT

/* FVHVCT1 Register */
#define FVHVCT1             MMIO32(FLASH + 0x2084)
// TRIM13_E
// VHVCT_E
// TRIM13_PV
// VHVCT_PV

/* FVHVCT2 Register */
#define FVHVCT2             MMIO32(FLASH + 0x2088)
//TRIM13_P
//VHVCT_P

/* FVHVCT3 Register */
#define FVHVCT3             MMIO32(FLASH + 0x208c)
//WCT
//VHVCT_READ

/* FVNVCT Register */
#define FVNVCT              MMIO32(FLASH + 0x2090)
//VCG2P5CT
//VIN_CT

/* FVSLP Register */
#define FVSLP               MMIO32(FLASH + 0x2094)
//VSL_P

/* FVWLCT Register */
#define FVWLCT              MMIO32(FLASH + 0x2098)
//VWLCT_P

/* FEFUSECTL Register */
#define FEFUSECTL           MMIO32(FLASH + 0x209c)
//CHAIN_SEL
//...
#define WRITE_EN    0x20000
//...
#define BP_SEL      0x10000
//...
#define EF_CLRZ     0x00100
//...
#define EF_TEST     0x00010
//EFUSE_EN

/* FEFUSESTAT Register */
#define FEFUSESTAT          MMIO32(FLASH + 0x20a0)
//...
#define SHIFT_DONE  0x1

/* FEFUSEDATA Register */
#define FEFUSEDATA          MMIO32(FLASH + 0x20a4)
//FEFUSEDATA

/* FSEQPMP Register */
#define FSEQPMP             MMIO32(FLASH + 0x20a8)
//TRIM_3P4
//TRIM_1P7
//TRIM_0P8
//VIN_AT_X
//...
#define VIN_BY_PASS 0x100
//SEQ_PUMP

/* FBSTROBES Register */
#define FBSTROBES           MMIO32(FLASH + 0x2100)
//...
#define ECBIT           0x1000000
//...
#define RWAIT2_FLCLK    0x0040000
//...
#define RWAIT_FLCLK     0x0020000
//...
#define FLCLKEN         0x0010000
//...
#define CTRLENZ         0x0000100
//...
#define NOCOLRED        0x0000040
//...
#define PRECOL          0x0000020
//...
#define TI_OTP          0x0000010
//...
#define OTP             0x0000008
//...
#define TEZ             0x0000004

/* FPSTROBES Register */
#define FPSTROBES           MMIO32(FLASH + 0x2104)
//...
#define EXECUTEZ    0x100
//...
#define V3PWRDNZ    0x002
//...
#define V5PWRDNZ    0x001

/* FBMODE Register */
#define FBMODE              MMIO32(FLASH + 0x2108)
//MODE

/* FTCR Register */
#define FTCR                MMIO32(FLASH + 0x210c)
//TCR

/* FADDR Register */
#define FADDR               MMIO32(FLASH + 0x2110)
//FADDR

/* FTCTL Register */
#define FTCTL               MMIO32(FLASH + 0x211c)
//...
#define WDATA_BLK_CLR   0x10000
//...
#define TEST_EN         0x00002

/* FWPWRITE0 Register */
#define FWPWRITE0           MMIO32(FLASH + 0x2120)
//FWPWRITE0

/* FWPWRITE1 Register */
#define FWPWRITE1           MMIO32(FLASH + 0x2124)
//FWPWRITE1

/* FWPWRITE2 Register */
#define FWPWRITE2           MMIO32(FLASH + 0x2128)
//FWPWRITE2

/* FWPWRITE3 Register */
#define FWPWRITE3           MMIO32(FLASH + 0x212c)
//FWPWRITE3

/* FWPWRITE4 Register */
#define FWPWRITE4           MMIO32(FLASH + 0x2130)
//FWPWRITE4

/* FWPWRITE5 Register */
#define FWPWRITE5           MMIO32(FLASH + 0x2134)
//FWPWRITE5

/* FWPWRITE6 Register */
#define FWPWRITE6           MMIO32(FLASH + 0x2138)
//FWPWRITE6

/* FWPWRITE7 Register */
#define FWPWRITE7           MMIO32(FLASH + 0x213c)
//FWPWRITE7

/* FWPWRITE_ECC Register */
#define FWPWRITE_ECC        MMIO32(FLASH + 0x2140)
//ECCBYTES07_00
//ECCBYTES15_08
//ECCBYTES23_16
//ECCBYTES31_24

/* FSWSTAT Register */
#define FSWSTAT             MMIO32(FLASH + 0x2144)
//...
#define SAFELV  0x1

/* FSM_GLBCTL Register */
#define FSM_GLBCTL          MMIO32(FLASH + 0x2200)
//...
#define CLKSEL  0x1

/* FSM_STATE Register */
#define FSM_STATE           MMIO32(FLASH + 0x2204)
//...
#define CTRLENZ     0x800
//...
#define EXECUTEZ    0x400
//...
#define FSM_ACT     0x100
//...
#define TIOTP_ACT   0x080
//...
#define OTP_ACT     0x040

/* FSM_STAT Register */
#define FSM_STAT            MMIO32(FLASH + 0x2208)
//...
#define NON_OP      0x4
//...
#define OVR_PUL_CNT 0x2
//...
#define INV_DAT     0x1

/* FSM_CMD Register */
#define FSM_CMD             MMIO32(FLASH + 0x220c)
//FSMCMD

/* FSM_PE_OSU Register */
#define FSM_PE_OSU          MMIO32(FLASH + 0x2210)
//PGM_OSU
//ERA_OSU

/* FSM_VSTAT Register */
#define FSM_VSTAT           MMIO32(FLASH + 0x2214)
//VSTAT_CNT

/* FSM_PE_VSU Register */
#define FSM_PE_VSU          MMIO32(FLASH + 0x2218)
//PGM_VSU
//ERA_VSU

/* FSM_CMP_VSU Register */
#define FSM_CMP_VSU         MMIO32(FLASH + 0x221c)
//ADD_EXZ

/* FSM_EX_VAL Register */
#define FSM_EX_VAL          MMIO32(FLASH + 0x2220)
//REP_VSU
//EXE_VALD

/* FSM_RD_H Register */
#define FSM_RD_H            MMIO32(FLASH + 0x2224)
//RD_H

/* FSM_P_OH Register */
#define FSM_P_OH            MMIO32(FLASH + 0x2228)
//PGM_OH

/* FSM_ERA_OH Register */
#define FSM_ERA_OH          MMIO32(FLASH + 0x222c)
//ERA_OH

/* FSM_SAV_PPUL Register */
#define FSM_SAV_PPUL        MMIO32(FLASH + 0x2230)
//SAV_P_PUL

/* FSM_PE_VH Register */
#define FSM_PE_VH           MMIO32(FLASH + 0x2234)
//PGM_VH
//ERA_VH

/* FSM_PRG_PW Register */
#define FSM_PRG_PW          MMIO32(FLASH + 0x2240)
//PROG_PUL_WIDTH

/* FSM_ERA_PW Register */
#define FSM_ERA_PW          MMIO32(FLASH + 0x2244)
//FSM_ERA_PW

/* FSM_SAV_ERA_PUL Register */
#define FSM_SAV_ERA_PUL     MMIO32(FLASH + 0x2254)
//SAV_ERA_PUL

/* FSM_TIMER Register */
#define FSM_TIMER           MMIO32(FLASH + 0x2258)
//FSM_TIMER

/* FSM_MODE Register */
#define FSM_MODE            MMIO32(FLASH + 0x225c)
//RDV_SUBMODE
//PGM_SUBMODE
//ERA_SUBMODE
//SUBMODE
//SAV_PGM_CMD
//...
#define SAV_ERA_MODE    0x100
//SAV_ERA_MODE
//MODE
//CMD

/* FSM_PGM Register */
#define FSM_PGM             MMIO32(FLASH + 0x2260)
//PGM_BANK
//PGM_ADDR

/* FSM_ERA Register */
#define FSM_ERA             MMIO32(FLASH + 0x2264)
//ERA_BANK
//ERA_ADDR

/* FSM_PRG_PUL Register */
#define FSM_PRG_PUL         MMIO32(FLASH + 0x2268)
//BEG_EC_LEVEL
//MAX_PRG_PUL

/* FSM_ERA_PUL Register */
#define FSM_ERA_PUL         MMIO32(FLASH + 0x226c)
//MAX_EC_LEVEL
//MAX_ERA_PUL

/* FSM_STEP_SIZE Register */
#define FSM_STEP_SIZE       MMIO32(FLASH + 0x2270)
//EC_STEP_SIZE

/* FSM_PUL_CNTR Register */
#define FSM_PUL_CNTR        MMIO32(FLASH + 0x2274)
//CUR_EC_LEVEL
//PUL_CNTR

/* FSM_EC_STEP_HEIGHT Register */
#define FSM_EC_STEP_HEIGHT  MMIO32(FLASH + 0x2278)
//EC_STEP_HEIGHT

/* FSM_ST_MACHINE Register */
#define FSM_ST_MACHINE      MMIO32(FLASH + 0x227c)
//...
#define DO_PRECOND      0x800000
//...
#define FSM_INT_EN      0x400000
//...
#define ALL_BANKS       0x200000
//...
#define CMPV_ALLOWED    0x100000
//...
#define RANDOM          0x080000
//...
#define RV_SEC_EN       0x040000
//...
#define RV_RES          0x020000
//...
#define RV_INT_EN       0x010000
//...
#define ONE_TIME_GOOD   0x004000
//...
#define DO_REDU_COL     0x000800
//DBG_SHORT_ROW
//...
#define PGM_SEC_COF_EN  0x000020
//...
#define PREC_STOP_EN    0x000010
//...
#define DIS_TST_EN      0x000008
//...
#define CMD_EN          0x000004
//...
#define INV_DATA        0x000002
//...
#define OVERRIDE        0x000001

/* FSM_FLES Register */
#define FSM_FLES            MMIO32(FLASH + 0x2280)
//BLK_TIOTP
//BLK_OTP

/* FSM_WR_ENA Register */
#define FSM_WR_ENA          MMIO32(FLASH + 0x2288)
//WR_ENA

/* FSM_ACC_PP Register */
#define FSM_ACC_PP          MMIO32(FLASH + 0x228c)
//FSM_ACC_PP

/* FSM_ACC_EP Register */
#define FSM_ACC_EP          MMIO32(FLASH + 0x2290)
//FSM_ACC_PP

/* FSM_ADDR Register */
#define FSM_ADDR            MMIO32(FLASH + 0x22a0)
//BANK
//CUR_ADDR

/* FSM_SECTOR Register */
#define FSM_SECTOR          MMIO32(FLASH + 0x22a4)
//...
#define SECT_ERASED_SHF             16
#define SECT_ERASED_MSK             0xffff
//...
#define FSM_SECTOR_EXTENSION_SHF    8
#define FSM_SECTOR_EXTENSION_MSK    0xff
//...
#define SECTOR_SHF                  4
#define SECTOR_MSK                  0xf
//...
#define SEC_OUT_SHF                 0
#define SEC_OUT_MSK                 0xf

/* FMC_REV_ID Register */
#define FMC_REV_ID          MMIO32(FLASH + 0x22a8)
//...
#define MOD_VERSION_SHF 12
#define MOD_VERSION_MSK 0xfffff
//...
#define CONFIG_CRC_SHF  0
#define CONFIG_CRC_MSK  0xfff

/* FSM_ERR_ADDR Register */
#define FSM_ERR_ADDR        MMIO32(FLASH + 0x22ac)
//...
#define FSM_ERR_ADDR_SHF 8
#define FSM_ERR_ADDR_MSK 0xffffff
//...
#define FSM_ERR_BANK_SHF 0
#define FSM_ERR_BANK_MSK 0xf

/* FSM_PGM_MAXPUL Register */
#define FSM_PGM_MAXPUL      MMIO32(FLASH + 0x22b0)
//...
#define FSM_PGM_MAXPUL_MSK 0xfff

/* FSM_EXECUTE Register */
#define FSM_EXECUTE         MMIO32(FLASH + 0x22b4)
//...
#define SUSPEND_NOW_SHF 16
#define SUSPEND_NOW_MSK 0xf
//...
#define FSMEXECUTE_SHF  0
#define FSMEXECUTE_MSK  0x1f

/* FSM_SECTOR1 Register */
#define FSM_SECTOR1         MMIO32(FLASH + 0x22c0)

/* FSM_SECTOR2 Register */
#define FSM_SECTOR2         MMIO32(FLASH + 0x22c4)

/* FSM_BSLE0 Register */
#define FSM_BSLE0           MMIO32(FLASH + 0x22e0)

/* FSM_BSLE1 Register */
#define FSM_BSLE1           MMIO32(FLASH + 0x22e4)

/* FSM_BSLP0 Register */
#define FSM_BSLP0           MMIO32(FLASH + 0x22f0)

/* FSM_BSLP1 Register */
#define FSM_BSLP1           MMIO32(FLASH + 0x22f4)

/* FCFG_BANK Register */
#define FCFG_BANK           MMIO32(FLASH + 0x2400)
//...
#define EE_BANK_WIDTH_SHF   20
#define EE_BANK_WIDTH_MSK   0xfff
//...
#define EE_NUM_BANK_SHF     16
#define EE_NUM_BANK_MSK     0xf
//...
#define MAIN_BANK_WIDTH_SHF 4
#define MAIN_BANK_WIDTH_MSK 0xfff
//...
#define MAIN_NUM_BANK_SHF   0
#define MAIN_NUM_BANK_MSK   0xf

/* FCFG_WRAPPER Register */
#define FCFG_WRAPPER        MMIO32(FLASH + 0x2404)
//...
#define FAMILY_TYPE_SHF 24
#define FAMILY_TYPE_MSK 0xff
//...
#define MEM_MAP         0x100000
//...
#define CPU2_SHF        16
#define CPU2_MSK        0xf
//...
#define EE_IN_MAIN_SHF  12
#define EE_IN_MAIN_MSK  0xf
//...
#define ROM             0x000800
//...
#define IFLUSH          0x000400
//...
#define SIL3            0x000200
//...
#define ECCA            0x000100
//...
#define AUTO_SUSP_SHF   6
#define AUTO_SUSP_MSK   0x3
//...
#define UERR_SHF        4
#define UERR_MSK        0x3
//...
#define CPU_TYPE1_SHF   0
#define CPU_TYPE1_MSK   0xf

/* FCFG_BNK_TYPE Registe */
#define FCFG_BNK_TYPE       MMIO32(FLASH + 0x2408)
//...
#define B7_TYPE_SHF 28
#define B7_TYPE_MSK 0xf
//...
#define B6_TYPE_SHF 24
#define B6_TYPE_MSK 0xf
//...
#define B5_TYPE_SHF 20
#define B5_TYPE_MSK 0xf
//...
#define B4_TYPE_SHF 16
#define B4_TYPE_MSK 0xf
//...
#define B3_TYPE_SHF 12
#define B3_TYPE_MSK 0xf
//...
#define B2_TYPE_SHF 8
#define B2_TYPE_MSK 0xf
//...
#define B1_TYPE_SHF 4
#define B1_TYPE_MSK 0xf
//...
#define B0_TYPE_SHF 0
#define B0_TYPE_MSK 0xf

/* FCFG_B0_START Register */
#define FCFG_B0_START       MMIO32(FLASH + 0x2410)
//...
#define B0_MAX_SECTOR_SHF 28
#define B0_MAX_SECTOR_MSK 0xf
//...
#define B0_MUX_FACTOR_SHF 24
#define B0_MUX_FACTOR_MSK 0xf
//...
#define B0_START_ADDR_SHF 0
#define B0_START_ADDR_MSK 0xffffff

/* FCFG_B1_START Register */
#define FCFG_B1_START       MMIO32(FLASH + 0x2414)
//...
#define B1_MAX_SECTOR_SHF 28
#define B1_MAX_SECTOR_MSK 0xf
//...
#define B1_MUX_FACTOR_SHF 24
#define B1_MUX_FACTOR_MSK 0xf
//...
#define B1_START_ADDR_SHF 0
#define B1_START_ADDR_MSK 0xffffff

/* FCFG_B2_START Register */
#define FCFG_B2_START       MMIO32(FLASH + 0x2418)
//...
#define B2_MAX_SECTOR_SHF 28
#define B2_MAX_SECTOR_MSK 0xf
//...
#define B2_MUX_FACTOR_SHF 24
#define B2_MUX_FACTOR_MSK 0xf
//...
#define B2_START_ADDR_SHF 0
#define B2_START_ADDR_MSK 0xffffff

/* FCFG_B3_START Register */
#define FCFG_B3_START       MMIO32(FLASH + 0x241c)
//...
#define B3_MAX_SECTOR_SHF 28
#define B3_MAX_SECTOR_MSK 0xf
//...
#define B3_MUX_FACTOR_SHF 24
#define B3_MUX_FACTOR_MSK 0xf
//...
#define B3_START_ADDR_SHF 0
#define B3_START_ADDR_MSK 0xffffff

/* FCFG_B4_START Register */
#define FCFG_B4_START       MMIO32(FLASH + 0x2420)
//...
#define B4_MAX_SECTOR_SHF 28
#define B4_MAX_SECTOR_MSK 0xf
//...
#define B4_MUX_FACTOR_SHF 24
#define B4_MUX_FACTOR_MSK 0xf
//...
#define B4_START_ADDR_SHF 0
#define B4_START_ADDR_MSK 0xffffff

/* FCFG_B5_START Register */
#define FCFG_B5_START       MMIO32(FLASH + 0x2424)
//...
#define B5_MAX_SECTOR_SHF 28
#define B5_MAX_SECTOR_MSK 0xf
//...
#define B5_MUX_FACTOR_SHF 24
#define B5_MUX_FACTOR_MSK 0xf
//...
#define B5_START_ADDR_SHF 0
#define B5_START_ADDR_MSK 0xffffff

/* FCFG_B6_START Register */
#define FCFG_B6_START       MMIO32(FLASH + 0x2428)
//...
#define B6_MAX_SECTOR_SHF 28
#define B6_MAX_SECTOR_MSK 0xf
//...
#define B6_MUX_FACTOR_SHF 24
#define B6_MUX_FACTOR_MSK 0xf
//...
#define B6_START_ADDR_SHF 0
#define B6_START_ADDR_MSK 0xffffff

/* FCFG_B7_START Register */
#define FCFG_B7_START       MMIO32(FLASH + 0x242C)
//...
#define B7_MAX_SECTOR_SHF 28
#define B7_MAX_SECTOR_MSK 0xf
//...
#define B7_MUX_FACTOR_SHF 24
#define B7_MUX_FACTOR_MSK 0xf
//...
#define B7_START_ADDR_SHF 0
#define B7_START_ADDR_MSK 0xffffff

/* FCFG_B0_SSIZE0 Register */
#define FCFG_B0_SSIZE0      MMIO32(FLASH + 0x2430)
//...
#define B0_NUM_SECTORS_SHF  16
#define B0_NUM_SECTORS_MSK  0xfff
//...
#define B0_SECT_SIZE_SHF    0
#define B0_SECT_SIZE_MSK    0xf

/* Displays current VIMS mode and line buffer status */
#define STAT        MMIO32(VIMS + 0x00)
// -=-

/* Configure VIMS mode and line buffer settings */
#define CTL         MMIO32(VIMS + 0x04)
// Icode/Dcode flash line buffer status
#define IDCODE_LB_DIS   0x20
// Sysbus flash line buffer control
#define SYSBUS_LB_DIS   0x10
// VIMS mode change status
#define MODE_CHANGING   0x08
// This bit is set when invalidation of the cache memory is active / ongoing
#define INV             0x04
// Current VIMS mode
#define MODE_GPRAM      0x0
#define MODE_CACHE      0x1
#define MODE_VIMS_OFF   0x3

#endif
