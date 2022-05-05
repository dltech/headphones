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
// Sets the state of the pin that is configured as DIO#3
#define	DIO3	0x01000000
// Sets the state of the pin that is configured as DIO#2
#define	DIO2	0x00010000
// Sets the state of the pin that is configured as DIO#1
#define	DIO1	0x00000100
// Sets the state of the pin that is configured as DIO#0
#define	DIO0	0x00000001

/* Data Out 28 to 31 */
#define DOUT31_28	MMIO32(GPIO + 0x1c)
// Sets the state of the pin that is configured as DIO#3
#define	DIO3	0x01000000
// Sets the state of the pin that is configured as DIO#2
#define	DIO2	0x00010000
// Sets the state of the pin that is configured as DIO#1
#define	DIO1	0x00000100
// Sets the state of the pin that is configured as DIO#0
#define	DIO0	0x00000001

/* */
#define DOUT31_0	MMIO32(GPIO + 0x80)
// Sets the state of the pin that is configured as DIO#3
#define	DIO3	0x01000000
// Sets the state of the pin that is configured as DIO#2
#define	DIO2	0x00010000
// Sets the state of the pin that is configured as DIO#1
#define	DIO1	0x00000100
// Sets the state of the pin that is configured as DIO#0
#define	DIO0	0x00000001

/* */
#define DOUTSET31_0	MMIO32(GPIO + 0x90)

/* */
#define DOUTCLR31_0	MMIO32(GPIO + 0xa0)

/* */
#define DOUTTGL31_0	MMIO32(GPIO + 0xb0)

/* */
#define DIN32_0		MMIO32(GPIO + 0xc0)

/* */
#define DOE31_0		MMIO32(GPIO + 0xd0)

/* */
#define EVFLAGS31_0	MMIO32(GPIO + 0xe0)


