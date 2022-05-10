/*
 * Simple CC2640 headphones
 * Interrupts and Events registers
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
/* */
#define MCUWUSEL		MMIO32(AON_EVENT + 0x00)

/* */
#define AUXWUSEL		MMIO32(AON_EVENT + 0x04)

/* */
#define EVTOMCUSEL		MMIO32(AON_EVENT + 0x08)

/* */
#define RTCSEL  		MMIO32(AON_EVENT + 0x0c)




/* */
#define CPUIRQSEL0  	MMIO32(EVENT + 0x000)

/* */
#define CPUIRQSEL1  	MMIO32(EVENT + 0x004)

/* */
#define CPUIRQSEL2  	MMIO32(EVENT + 0x008)

/* */
#define CPUIRQSEL3  	MMIO32(EVENT + 0x00c)

/* */
#define CPUIRQSEL4  	MMIO32(EVENT + 0x010)

/* */
#define CPUIRQSEL5  	MMIO32(EVENT + 0x014)

/* */
#define CPUIRQSEL6  	MMIO32(EVENT + 0x018)

/* */
#define CPUIRQSEL7  	MMIO32(EVENT + 0x01c)

/* */
#define CPUIRQSEL8  	MMIO32(EVENT + 0x020)

/* */
#define CPUIRQSEL9  	MMIO32(EVENT + 0x024)

/* */
#define CPUIRQSEL10  	MMIO32(EVENT + 0x028)

/* */
#define CPUIRQSEL11  	MMIO32(EVENT + 0x02c)

/* */
#define CPUIRQSEL12  	MMIO32(EVENT + 0x030)

/* */
#define CPUIRQSEL13  	MMIO32(EVENT + 0x034)

/* */
#define CPUIRQSEL14  	MMIO32(EVENT + 0x038)

/* */
#define CPUIRQSEL15  	MMIO32(EVENT + 0x03c)

/* */
#define CPUIRQSEL16  	MMIO32(EVENT + 0x040)

/* */
#define CPUIRQSEL17  	MMIO32(EVENT + 0x044)

/* */
#define CPUIRQSEL18  	MMIO32(EVENT + 0x048)

/* */
#define CPUIRQSEL19  	MMIO32(EVENT + 0x04c)

/* */
#define CPUIRQSEL20  	MMIO32(EVENT + 0x050)

/* */
#define CPUIRQSEL21  	MMIO32(EVENT + 0x054)

/* */
#define CPUIRQSEL22  	MMIO32(EVENT + 0x058)

/* */
#define CPUIRQSEL23  	MMIO32(EVENT + 0x05c)

/* */
#define CPUIRQSEL24  	MMIO32(EVENT + 0x060)

/* */
#define CPUIRQSEL25  	MMIO32(EVENT + 0x064)

/* */
#define CPUIRQSEL26  	MMIO32(EVENT + 0x068)

/* */
#define CPUIRQSEL27  	MMIO32(EVENT + 0x06c)

/* */
#define CPUIRQSEL28  	MMIO32(EVENT + 0x070)

/* */
#define CPUIRQSEL29  	MMIO32(EVENT + 0x074)

/* */
#define CPUIRQSEL30  	MMIO32(EVENT + 0x078)

/* */
#define CPUIRQSEL31  	MMIO32(EVENT + 0x07c)

/* */
#define CPUIRQSEL32  	MMIO32(EVENT + 0x080)

/* */
#define CPUIRQSEL33  	MMIO32(EVENT + 0x084)

/* */
#define RFCSEL0       	MMIO32(EVENT + 0x100)
#define RFCSEL1       	MMIO32(EVENT + 0x104)
#define RFCSEL2       	MMIO32(EVENT + 0x108)
#define RFCSEL3       	MMIO32(EVENT + 0x10c)
#define RFCSEL4       	MMIO32(EVENT + 0x110)
#define RFCSEL5       	MMIO32(EVENT + 0x114)
#define RFCSEL6       	MMIO32(EVENT + 0x118)
#define RFCSEL7       	MMIO32(EVENT + 0x11c)
#define RFCSEL8       	MMIO32(EVENT + 0x120)
#define RFCSEL9       	MMIO32(EVENT + 0x124)

/* */
#define GPT0ACAPTSEL  	MMIO32(EVENT + 0x200)

/* */
#define GPT0BCAPTSEL  	MMIO32(EVENT + 0x204)

/* */
#define GPT1ACAPTSEL  	MMIO32(EVENT + 0x300)

/* */
#define GPT1BCAPTSEL  	MMIO32(EVENT + 0x304)

/* */
#define GPT2ACAPTSEL  	MMIO32(EVENT + 0x400)
#define GPT2BCAPTSEL  	MMIO32(EVENT + 0x404)

/* */
#define UDMACH1SSEL  	MMIO32(EVENT + 0x508)
#define UDMACH1BSEL  	MMIO32(EVENT + 0x50c)
#define UDMACH2SSEL  	MMIO32(EVENT + 0x510)
#define UDMACH2BSEL  	MMIO32(EVENT + 0x514)
#define UDMACH3SSEL  	MMIO32(EVENT + 0x518)
#define UDMACH3BSEL  	MMIO32(EVENT + 0x51c)
#define UDMACH4SSEL  	MMIO32(EVENT + 0x520)
#define UDMACH4BSEL  	MMIO32(EVENT + 0x524)
#define UDMACH5SSEL  	MMIO32(EVENT + 0x528)
#define UDMACH5BSEL  	MMIO32(EVENT + 0x52c)
#define UDMACH6SSEL  	MMIO32(EVENT + 0x530)
#define UDMACH6BSEL  	MMIO32(EVENT + 0x534)
#define UDMACH7SSEL  	MMIO32(EVENT + 0x538)
#define UDMACH7BSEL  	MMIO32(EVENT + 0x53c)
#define UDMACH8SSEL  	MMIO32(EVENT + 0x540)
#define UDMACH8BSEL  	MMIO32(EVENT + 0x544)
#define UDMACH9SSEL  	MMIO32(EVENT + 0x548)
#define UDMACH9BSEL  	MMIO32(EVENT + 0x54c)
#define UDMACH10SSEL  	MMIO32(EVENT + 0x550)
#define UDMACH10BSEL  	MMIO32(EVENT + 0x554)
#define UDMACH11SSEL  	MMIO32(EVENT + 0x558)
#define UDMACH11BSEL  	MMIO32(EVENT + 0x55c)
#define UDMACH12SSEL  	MMIO32(EVENT + 0x560)
#define UDMACH12BSEL  	MMIO32(EVENT + 0x564)
#define UDMACH13SSEL  	MMIO32(EVENT + 0x56c)
#define UDMACH13BSEL  	MMIO32(EVENT + 0x574)
#define UDMACH14SSEL  	MMIO32(EVENT + 0x57c)
#define UDMACH14BSEL  	MMIO32(EVENT + 0x580)
#define UDMACH15SSEL  	MMIO32(EVENT + 0x584)
#define UDMACH15BSEL  	MMIO32(EVENT + 0x588)
#define UDMACH16SSEL  	MMIO32(EVENT + 0x58c)
#define UDMACH16BSEL  	MMIO32(EVENT + 0x5a8)
#define UDMACH17SSEL  	MMIO32(EVENT + 0x5ac)
#define UDMACH17BSEL  	MMIO32(EVENT + 0x5b0)
#define UDMACH18SSEL  	MMIO32(EVENT + 0x5b4)
#define UDMACH18BSEL  	MMIO32(EVENT + 0x5b8)
#define UDMACH19SSEL  	MMIO32(EVENT + 0x5bc)
#define UDMACH19BSEL  	MMIO32(EVENT + 0x5c0)
#define UDMACH20SSEL  	MMIO32(EVENT + 0x5c4)
#define UDMACH20BSEL  	MMIO32(EVENT + 0x600)
#define UDMACH21SSEL  	MMIO32(EVENT + 0x604)
#define UDMACH21BSEL  	MMIO32(EVENT + 0x00)
#define UDMACH22SSEL  	MMIO32(EVENT + 0x00)
#define UDMACH22BSEL  	MMIO32(EVENT + 0x00)
#define UDMACH23SSEL  	MMIO32(EVENT + 0x00)
#define UDMACH23BSEL  	MMIO32(EVENT + 0x00)
#define UDMACH24SSEL  	MMIO32(EVENT + 0x00)
#define UDMACH24BSEL  	MMIO32(EVENT + 0x00)

#define GPT3ACAPTSEL  	MMIO32(EVENT + 0x00)
#define GPT3BCAPTSEL  	MMIO32(EVENT + 0x00)
#define AUXSEL0       	MMIO32(EVENT + 0x00)
#define CM3NMISEL0  	MMIO32(EVENT + 0x00)
#define I2SSTMPSEL0  	MMIO32(EVENT + 0x00)
#define FRZSEL0       	MMIO32(EVENT + 0x00)
#define SWEV          	MMIO32(EVENT + 0x00)
