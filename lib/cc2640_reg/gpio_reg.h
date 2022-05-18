#ifndef H_GPIO_REGS
#define H_GPIO_REGS
/*
 * Simple CC2640 headphones
 * GPIO registers
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

/* Internal. Only to be used through TI provided API. */
#define IOSTRMIN	MMIO32(AON_IOC + 0x00)
#define IOSTRMED	MMIO32(AON_IOC + 0x04)
#define IOSTRMAX	MMIO32(AON_IOC + 0x08)
/* IO Latch Control */
#define IOCLATCH	MMIO32(AON_IOC + 0x0c)
// Controls latches between MCU IOC and AON_IOC.
#define	LATCH_EN	0x01

/* SCLK_LF External Output Control */
#define CLK32KCTL	MMIO32(AON_IOC + 0x10)
// 0: Output enable active. SCLK_LF output on IO pin that has
#define OE_N		0x01

/* Alias register for byte access to each bit in DOUT31_0
	Data Out 3 to 0 */
#define DOUT3_0		MMIO32(GPIO + 0x00)
// Sets the state of the pin that is configured as DIO#3
#define	DIO3	0x01000000
// Sets the state of the pin that is configured as DIO#2
#define	DIO2	0x00010000
// Sets the state of the pin that is configured as DIO#1
#define	DIO1	0x00000100
// Sets the state of the pin that is configured as DIO#0
#define	DIO0	0x00000001

/* Data Out 4 to 7 */
#define DOUT7_4		MMIO32(GPIO + 0x04)
// Sets the state of the pin that is configured as DIO#7
#define	DIO7	0x01000000
// Sets the state of the pin that is configured as DIO#6
#define	DIO6	0x00010000
// Sets the state of the pin that is configured as DIO#5
#define	DIO5	0x00000100
// Sets the state of the pin that is configured as DIO#4
#define	DIO4	0x00000001

/* Data Out 8 to 11 */
#define DOUT11_8	MMIO32(GPIO + 0x08)
// Sets the state of the pin that is configured as DIO#11
#define	DIO11	0x01000000
// Sets the state of the pin that is configured as DIO#10
#define	DIO10	0x00010000
// Sets the state of the pin that is configured as DIO#9
#define	DIO9	0x00000100
// Sets the state of the pin that is configured as DIO#8
#define	DIO8	0x00000001

/* Data Out 12 to 15 */
#define DOUT15_12	MMIO32(GPIO + 0x0c)
// Sets the state of the pin that is configured as DIO#15
#define	DIO15	0x01000000
// Sets the state of the pin that is configured as DIO#14
#define	DIO14	0x00010000
// Sets the state of the pin that is configured as DIO#13
#define	DIO13	0x00000100
// Sets the state of the pin that is configured as DIO#12
#define	DIO12	0x00000001

/* Data Out 16 to 19 */
#define DOUT19_16	MMIO32(GPIO + 0x10)
// Sets the state of the pin that is configured as DIO#19
#define	DIO19	0x01000000
// Sets the state of the pin that is configured as DIO#18
#define	DIO18	0x00010000
// Sets the state of the pin that is configured as DIO#17
#define	DIO17	0x00000100
// Sets the state of the pin that is configured as DIO#16
#define	DIO16	0x00000001

/* Data Out 20 to 23 */
#define DOUT23_20	MMIO32(GPIO + 0x14)
// Sets the state of the pin that is configured as DIO#23
#define	DIO23	0x01000000
// Sets the state of the pin that is configured as DIO#22
#define	DIO22	0x00010000
// Sets the state of the pin that is configured as DIO#21
#define	DIO21	0x00000100
// Sets the state of the pin that is configured as DIO#20
#define	DIO20	0x00000001

/* Data Out 24 to 27 */
#define DOUT27_24	MMIO32(GPIO + 0x18)
// Sets the state of the pin that is configured as DIO#27
#define	DIO27	0x01000000
// Sets the state of the pin that is configured as DIO#26
#define	DIO26	0x00010000
// Sets the state of the pin that is configured as DIO#25
#define	DIO25	0x00000100
// Sets the state of the pin that is configured as DIO#24
#define	DIO24	0x00000001

/* Data Out 28 to 31 */
#define DOUT31_28	MMIO32(GPIO + 0x1c)
// Sets the state of the pin that is configured as DIO#31
#define	DIO31	0x01000000
// Sets the state of the pin that is configured as DIO#30
#define	DIO30	0x00010000
// Sets the state of the pin that is configured as DIO#29
#define	DIO29	0x00000100
// Sets the state of the pin that is configured as DIO#28
#define	DIO28	0x00000001

/* Data Output for DIO 0 to 31 */
#define DOUT31_0	MMIO32(GPIO + 0x80)
// Sets the state of the pin that is configured as DIO#3
#define	DIO3	0x01000000
// Sets the state of the pin that is configured as DIO#2
#define	DIO2	0x00010000
// Sets the state of the pin that is configured as DIO#1
#define	DIO1	0x00000100
// Sets the state of the pin that is configured as DIO#0
#define	DIO0	0x00000001

/* Data Out Set */
#define DOUTSET31_0	MMIO32(GPIO + 0x90)
// dio pins
#define	DIOS31	0x80000000
#define	DIOS30	0x40000000
#define	DIOS29	0x20000000
#define	DIOS28	0x10000000
#define	DIOS27	0x08000000
#define	DIOS26	0x04000000
#define	DIOS25	0x02000000
#define	DIOS24	0x01000000
#define	DIOS23	0x00800000
#define	DIOS22	0x00400000
#define	DIOS21	0x00200000
#define	DIOS20	0x00100000
#define	DIOS19	0x00080000
#define	DIOS18	0x00040000
#define	DIOS17	0x00020000
#define	DIOS16	0x00010000
#define	DIOS15	0x00008000
#define	DIOS14	0x00004000
#define	DIOS13	0x00002000
#define	DIOS12	0x00001000
#define	DIOS11	0x00000800
#define	DIOS10	0x00000400
#define	DIOS9	0x00000200
#define	DIOS8	0x00000100
#define	DIOS7	0x00000080
#define	DIOS6	0x00000040
#define	DIOS5	0x00000020
#define	DIOS4	0x00000010
#define	DIOS3	0x00000008
#define	DIOS2	0x00000004
#define	DIOS1	0x00000002
#define	DIOS0	0x00000001

/* Data Out Clear */
#define DOUTCLR31_0	MMIO32(GPIO + 0xa0)

/* Data Out Toggle */
#define DOUTTGL31_0	MMIO32(GPIO + 0xb0)

/* Data Input from DIO 0 to 31 */
#define DIN32_0		MMIO32(GPIO + 0xc0)

/* Data Output Enable for DIO 0 to 31 */
#define DOE31_0		MMIO32(GPIO + 0xd0)

/* Event Register for DIO 0 to 31 */
#define EVFLAGS31_0	MMIO32(GPIO + 0xe0)

/* Configuration of DIO0 */
#define	IOCFG0		MMIO32(IOC + 0x00)
// 1: Input hysteresis enable
#define	HYST_EN					0x40000000
// 1: Input enabled
#define	IE						0x20000000
// wakeup config
#define	WU_CFG_LOW				0x10000000
#define	WU_CFG_HIGH				0x18000000
#define	WU_CFG_EN				0x10000000
#define	WU_CFG_DIS				0x00000000
#define	WU_CFG_MSK				0x18000000
// IO Mode
#define	IOMODE_NORMAL			0x00000000
#define	IOMODE_INV				0x01000000
#define	IOMODE_OPENDR			0x04000000
#define	IOMODE_OPENDR_INV		0x05000000
#define	IOMODE_OPENSRC			0x06000000
#define	IOMODE_OPENSRC_INV		0x07000000
#define	IOMODE_MSK				0x07000000
// 1: Enable interrupt generation for this IO
#define	EDGE_IRQ_EN				0x00040000
// Enable generation of edge detection events on this IO
#define	EDGE_DET_NONE			0x00000000
#define	EDGE_DET_NEGATIVE		0x00010000
#define	EDGE_DET_POSITIVE		0x00020000
#define	EDGE_DET_BOTH			0x00030000
#define	EDGE_DET_MSK			0x00030000
// Pull control
#define	PULL_CTL_DWN			0x00002000
#define	PULL_CTL_UP				0x00004000
#define	PULL_CTL_DIS			0x00006000
#define	PULL_CTL_MSK			0x00006000
// 1: Enables reduced slew rate in output driver.
#define	SLEW_RED				0x00001000
// Selects IO current mode of this IO.
#define	IOCURR_2MA				0x00000000
#define	IOCURR_4MA				0x00000400
#define	IOCURR_8MA				0x00000800
#define	IOCURR_MSK				0x00000c00
// Select source for drive strength control of this IO.
#define	IOSTR_AUTO				0x00000000
#define	IOSTR_MIN				0x00000100
#define	IOSTR_MED				0x00000200
#define	IOSTR_MAX				0x00000300
#define	IOSTR_MSK				0x00000300
// Selects usage for DIO
#define	PORT_ID_GPIO			0x00000000
#define	PORT_ID_SCLK_LF			0x00000007
#define	PORT_ID_AUX_IO			0x00000008
#define	PORT_ID_SSI0RX			0x00000009
#define	PORT_ID_SSI0_TX			0x0000000a
#define	PORT_ID_SSI0_FSS		0x0000000b
#define	PORT_ID_SSI0_CLK		0x0000000c
#define	PORT_ID_I2C_MSSDA		0x0000000d
#define	PORT_ID_I2C_MSSCL		0x0000000e
#define	PORT_ID_UART0_RX		0x0000000f
#define	PORT_ID_UART0_TX		0x00000010
#define	PORT_ID_UART0_CTS		0x00000011
#define	PORT_ID_UART0_RTS		0x00000012
#define	PORT_ID_EVENT0			0x00000017
#define	PORT_ID_EVENT1			0x00000018
#define	PORT_ID_EVENT2			0x00000019
#define	PORT_ID_EVENT3			0x0000001a
#define	PORT_ID_EVENT4			0x0000001b
#define	PORT_ID_EVENT5			0x0000001c
#define	PORT_ID_EVENT6			0x0000001d
#define	PORT_ID_EVENT7			0x0000001e
#define	PORT_ID_CPU_SWV			0x00000020
#define	PORT_ID_SSI1_RX			0x00000021
#define	PORT_ID_SSI1_TX			0x00000022
#define	PORT_ID_SSI1_FSS		0x00000023
#define	PORT_ID_SSI1_CLK		0x00000024
#define	PORT_ID_I2S_AD0			0x00000025
#define	PORT_ID_I2S_AD1			0x00000026
#define	PORT_ID_I2S_WCLK		0x00000027
#define	PORT_ID_I2S_BCLK		0x00000028
#define	PORT_ID_I2S_MCLK		0x00000029
#define	PORT_ID_RF_TRACE		0x0000002e
#define	PORT_ID_RF_DATA_OUT0	0x0000002f
#define	PORT_ID_RF_DATA_OUT1	0x00000030
#define	PORT_ID_RF_DATA_OUT2	0x00000031
#define	PORT_ID_RF_DATA_OUT3	0x00000032
#define	PORT_ID_RF_DATA_IN0		0x00000033
#define	PORT_ID_RF_DATA_IN1		0x00000034
#define	PORT_ID_RF_SMI_DATA_OUT	0x00000035
#define	PORT_ID_RF_SMI_DATA_IN	0x00000036
#define	PORT_ID_RF_SMI_CMD_OUT	0x00000037
#define	PORT_ID_RF_SMI_CMD_IN	0x00000038
#define	PORT_ID_MSK				0x0000003f

/* Configuration of DIO1 */
#define	IOCFG1		MMIO32(IOC + 0x04)
/* Configuration of DIO2 */
#define	IOCFG2		MMIO32(IOC + 0x08)
/* Configuration of DIO3 */
#define	IOCFG3		MMIO32(IOC + 0x0c)
/* Configuration of DIO4 */
#define	IOCFG4		MMIO32(IOC + 0x10)
/* Configuration of DIO5 */
#define	IOCFG5		MMIO32(IOC + 0x14)
/* Configuration of DIO6 */
#define	IOCFG6		MMIO32(IOC + 0x18)
/* Configuration of DIO7 */
#define	IOCFG7		MMIO32(IOC + 0x1c)
/* Configuration of DIO8 */
#define	IOCFG8		MMIO32(IOC + 0x20)
/* Configuration of DIO9 */
#define	IOCFG9		MMIO32(IOC + 0x24)
/* Configuration of DIO10 */
#define	IOCFG10		MMIO32(IOC + 0x28)
/* Configuration of DIO11 */
#define	IOCFG11		MMIO32(IOC + 0x2c)
/* Configuration of DIO12 */
#define	IOCFG12		MMIO32(IOC + 0x30)
/* Configuration of DIO13 */
#define	IOCFG13		MMIO32(IOC + 0x34)
/* Configuration of DIO14 */
#define	IOCFG14		MMIO32(IOC + 0x38)
/* Configuration of DIO15 */
#define	IOCFG15		MMIO32(IOC + 0x3c)
/* Configuration of DIO16 */
#define	IOCFG16		MMIO32(IOC + 0x40)
/* Configuration of DIO17 */
#define	IOCFG17		MMIO32(IOC + 0x44)
/* Configuration of DIO18 */
#define	IOCFG18		MMIO32(IOC + 0x48)
/* Configuration of DIO19 */
#define	IOCFG19		MMIO32(IOC + 0x4c)
/* Configuration of DIO20 */
#define	IOCFG20		MMIO32(IOC + 0x50)
/* Configuration of DIO21 */
#define	IOCFG21		MMIO32(IOC + 0x54)
/* Configuration of DIO22 */
#define	IOCFG22		MMIO32(IOC + 0x58)
/* Configuration of DIO23 */
#define	IOCFG23		MMIO32(IOC + 0x5c)
/* Configuration of DIO24 */
#define	IOCFG24		MMIO32(IOC + 0x60)
/* Configuration of DIO25 */
#define	IOCFG25		MMIO32(IOC + 0x64)
/* Configuration of DIO26 */
#define	IOCFG26		MMIO32(IOC + 0x68)
/* Configuration of DIO27 */
#define	IOCFG27		MMIO32(IOC + 0x6c)
/* Configuration of DIO28 */
#define	IOCFG28		MMIO32(IOC + 0x70)
/* Configuration of DIO29 */
#define	IOCFG29		MMIO32(IOC + 0x74)
/* Configuration of DIO30 */
#define	IOCFG30		MMIO32(IOC + 0x78)
/* Configuration of DIO31 */
#define	IOCFG31		MMIO32(IOC + 0x7c)

#endif
