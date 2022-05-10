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
/* Wake-up Selector For MCU */
#define MCUWUSEL		MMIO32(AON_EVENT + 0x00)
#define WU3_EV_SHIFT  24
#define WU2_EV_SHIFT  16
#define WU1_EV_SHIFT  8
#define WU0_EV_SHIFT  0

/* Wake-up Selector For AUX */
#define AUXWUSEL		MMIO32(AON_EVENT + 0x04)

/* Event Selector For MCU Event Fabric */
#define EVTOMCUSEL		MMIO32(AON_EVENT + 0x08)
#define AON_PROG2_EV  16
#define AON_PROG1_EV  8
#define AON_PROG0_EV  0

/* RTC Capture Event Selector For AON_RTC */
#define RTCSEL  		MMIO32(AON_EVENT + 0x0c)
#define RTC_CH1_CAPT_EV  0x3f

/* Output Selection for CPU Interrupt n */
#define CPUIRQSEL0  	MMIO32(EVENT + 0x000)
#define EV_IOC      0x04

#define CPUIRQSEL1  	MMIO32(EVENT + 0x004)
#define EV_I2C      0x09

#define CPUIRQSEL2  	MMIO32(EVENT + 0x008)
#define EV_CPE      0x1e

#define CPUIRQSEL3  	MMIO32(EVENT + 0x00c)
#define CPUIRQSEL4  	MMIO32(EVENT + 0x010)
#define EV_AON_RTC  0x07

#define CPUIRQSEL5  	MMIO32(EVENT + 0x014)
#define EV_UART0    0x24

#define CPUIRQSEL6  	MMIO32(EVENT + 0x018)
#define EV_AUX0     0x1c

#define CPUIRQSEL7  	MMIO32(EVENT + 0x01c)
#define EV_SSI0     0x22

#define CPUIRQSEL8  	MMIO32(EVENT + 0x020)
#define EV_SSI1     0x23

#define CPUIRQSEL9  	MMIO32(EVENT + 0x024)
#define EV_CPE      0x1b

#define CPUIRQSEL10  	MMIO32(EVENT + 0x028)
#define EV_RFC      0x1a

#define CPUIRQSEL11  	MMIO32(EVENT + 0x02c)
#define EV_RFC_DOORBELL 0x19

#define CPUIRQSEL12  	MMIO32(EVENT + 0x030)
#define EV_I2S      0x08

#define CPUIRQSEL13  	MMIO32(EVENT + 0x034)
#define EV_AUX1     0x1d

#define CPUIRQSEL14  	MMIO32(EVENT + 0x038)
#define EV_WD       0x18

#define CPUIRQSEL15  	MMIO32(EVENT + 0x03c)
#define EV_GPT0A    0x10

#define CPUIRQSEL16  	MMIO32(EVENT + 0x040)
#define EV_GPT0B    0x11

#define CPUIRQSEL17  	MMIO32(EVENT + 0x044)
#define EV_GPT1A    0x12

#define CPUIRQSEL18  	MMIO32(EVENT + 0x048)
#define EV_GPT1B    0x13

#define CPUIRQSEL19  	MMIO32(EVENT + 0x04c)
#define EV_GPT2A    0x0c

#define CPUIRQSEL20  	MMIO32(EVENT + 0x050)
#define EV_GPT2B    0x0d

#define CPUIRQSEL21  	MMIO32(EVENT + 0x054)
#define EV_GPT3A    0x0e

#define CPUIRQSEL22  	MMIO32(EVENT + 0x058)
#define EV_GPT3B    0x0f

#define CPUIRQSEL23  	MMIO32(EVENT + 0x05c)
#define EV_CRYPTO   0x5d

#define CPUIRQSEL24  	MMIO32(EVENT + 0x060)
#define EV_DMA_DONE 0x27

#define CPUIRQSEL25  	MMIO32(EVENT + 0x064)
#define EV_DMA_ERR  0x26

#define CPUIRQSEL26  	MMIO32(EVENT + 0x068)
#define EV_FLASH    0x15

#define CPUIRQSEL27  	MMIO32(EVENT + 0x06c)
#define EV_SWEV     0x64

#define CPUIRQSEL28  	MMIO32(EVENT + 0x070)
#define EV_AUX      0x0b

#define CPUIRQSEL29  	MMIO32(EVENT + 0x074)
#define EV_AON      0x01

#define CPUIRQSEL30  	MMIO32(EVENT + 0x078)
// r/w definitions
#define EV30_INACTIVE       0x00
#define EV30_AON1           0x02
#define EV30_AON2           0x03
#define EV30_I2S            0x08
#define EV30_AUX0           0x0a
#define EV30_DMA_CH0        0x14
#define EV30_DMA_CH18       0x16
#define EV30_CRYPTO         0x5e
#define EV30_AON_WKUP       0x69
#define EV30_AUX_COMPB      0x6b
#define EV30_AUX_TDC        0x6c
#define EV30_AUX_TIMER0     0x6d
#define EV30_AUX_TIMER1     0x6e
#define EV30_AUX_SEMAPHORE  0x6f
#define EV30_AUX_ADC_DONE   0x70
#define EV30_AUX_ADC_FIFO   0x71
#define EV30_AUX_OBSMUX0    0x72
#define AUX_RTC             0x77
#define ASSERTED            0x79

#define CPUIRQSEL31  	MMIO32(EVENT + 0x07c)
#define EV_AUX_COMPA 0x6a

#define CPUIRQSEL32  	MMIO32(EVENT + 0x080)
#define EV_AUX_ADC   0x73

#define CPUIRQSEL33  	MMIO32(EVENT + 0x084)
#define EV_TRNG      0x68

/* Output Selection for RFC Event n */
#define RFCSEL0       	MMIO32(EVENT + 0x100)
#define EV0_GPT0A    0x3d

#define RFCSEL1       	MMIO32(EVENT + 0x104)
#define EV1_GPT0B    0x3e

#define RFCSEL2       	MMIO32(EVENT + 0x108)
#define EV2_GPT1A    0x3f

#define RFCSEL3       	MMIO32(EVENT + 0x10c)
#define EV3_GPT1B    0x40

#define RFCSEL4       	MMIO32(EVENT + 0x110)
#define EV4_GPT2A    0x41

#define RFCSEL5       	MMIO32(EVENT + 0x114)
#define EV5_GPT2B    0x42

#define RFCSEL6       	MMIO32(EVENT + 0x118)
#define EV6_GPT3A    0x43

#define RFCSEL7       	MMIO32(EVENT + 0x11c)
#define EV4_GPT3B    0x44

#define RFCSEL8       	MMIO32(EVENT + 0x120)
#define EV8_RTC      0x77

#define RFCSEL9       	MMIO32(EVENT + 0x124)

/* Output Selection for GPTn n */
#define GPT0ACAPTSEL  	MMIO32(EVENT + 0x200)
#define GPT0BCAPTSEL  	MMIO32(EVENT + 0x204)

#define GPT1ACAPTSEL  	MMIO32(EVENT + 0x300)
#define GPT1BCAPTSEL  	MMIO32(EVENT + 0x304)

#define GPT2ACAPTSEL  	MMIO32(EVENT + 0x400)
#define GPT2BCAPTSEL  	MMIO32(EVENT + 0x404)

/* Output Selection for DMA Channel n SREQ */
#define UDMACH1SSEL  	MMIO32(EVENT + 0x508)
#define EV1_UART0_RX_SINGLE 0x31

/* Output Selection for DMA Channel n REQ */
#define UDMACH1BSEL  	MMIO32(EVENT + 0x50c)
#define EV1_UART0_RX_BURST  0x30

#define UDMACH2SSEL  	MMIO32(EVENT + 0x510)
#define EV2_UART0_TX_SINGLE 0x33

#define UDMACH2BSEL  	MMIO32(EVENT + 0x514)
#define EV2_UART0_RX_BURST  0x32

#define UDMACH3SSEL  	MMIO32(EVENT + 0x518)
#define EV3_SSI0_RX_SINGLE  0x29

#define UDMACH3BSEL  	MMIO32(EVENT + 0x51c)
#define EV1_SSI0_RX_BURST   0x28

#define UDMACH4SSEL  	MMIO32(EVENT + 0x520)
#define EV4_SSI0_TX_SINGLE  0x2b

#define UDMACH4BSEL  	MMIO32(EVENT + 0x524)
#define EV4_SSI0_TX_BURST   0x2a

#define UDMACH5SSEL  	MMIO32(EVENT + 0x528)
#define UDMACH5BSEL  	MMIO32(EVENT + 0x52c)
#define UDMACH6SSEL  	MMIO32(EVENT + 0x530)
#define UDMACH6BSEL  	MMIO32(EVENT + 0x534)
#define UDMACH7SSEL  	MMIO32(EVENT + 0x538)
#define EV7_AUX_SINGLE      0x75

#define UDMACH7BSEL  	MMIO32(EVENT + 0x53c)
#define EV7_AUX_BURST       0x76

#define UDMACH8SSEL  	MMIO32(EVENT + 0x540)
#define UDMACH8BSEL  	MMIO32(EVENT + 0x544)
#define EV8_AUX             0x75

#define UDMACH9SSEL  	MMIO32(EVENT + 0x548)
#define UDMACH9BSEL  	MMIO32(EVENT + 0x54c)
#define UDMACH10SSEL  	MMIO32(EVENT + 0x550)
#define UDMACH10BSEL  	MMIO32(EVENT + 0x554)
#define UDMACH11SSEL  	MMIO32(EVENT + 0x558)
#define UDMACH11BSEL  	MMIO32(EVENT + 0x55c)
#define UDMACH12SSEL  	MMIO32(EVENT + 0x560)
#define UDMACH12BSEL  	MMIO32(EVENT + 0x564)
#define EV12_GPT0A          0x4d
#define EV12_GPT0B          0x4e
#define EV12_GPT1A          0x4f
#define EV12_GPT1B          0x50
#define EV12_GPT2A          0x51
#define EV12_GPT2B          0x52
#define EV12_GPT3A          0x53
#define EV12_GPT3B          0x54

#define UDMACH13BSEL  	MMIO32(EVENT + 0x56c)
#define EV13_AON_EV2        0x03

#define UDMACH14BSEL  	MMIO32(EVENT + 0x574)
#define UDMACH15BSEL  	MMIO32(EVENT + 0x57c)
#define EV15_AON_RTC        0x07

#define UDMACH16SSEL  	MMIO32(EVENT + 0x580)
#define EV16_SSI1_RX_SINGLE 0x2d

#define UDMACH16BSEL  	MMIO32(EVENT + 0x584)
#define EV16_SSI1_RX_BURST  0x2c

#define UDMACH17SSEL  	MMIO32(EVENT + 0x588)
#define EV17_SSI1_TX_SINGLE 0x2f

#define UDMACH17BSEL  	MMIO32(EVENT + 0x58c)
#define EV17_SSI1_TX_BURST  0x2e

#define UDMACH21SSEL  	MMIO32(EVENT + 0x5a8)
#define UDMACH21BSEL  	MMIO32(EVENT + 0x5ac)
#define EV21_SW0            0x64

#define UDMACH22SSEL  	MMIO32(EVENT + 0x5b0)
#define UDMACH22BSEL  	MMIO32(EVENT + 0x5b4)
#define EV22_SW1            0x65

#define UDMACH23SSEL  	MMIO32(EVENT + 0x5b8)
#define UDMACH23BSEL  	MMIO32(EVENT + 0x5bc)
#define EV23_SW2            0x66

#define UDMACH24SSEL  	MMIO32(EVENT + 0x5c0)
#define UDMACH24BSEL  	MMIO32(EVENT + 0x5c4)
#define EV24_SW3            0x67

/* Output Selection for GPT3 0 */
#define GPT3ACAPTSEL  	MMIO32(EVENT + 0x600)
#define GPT3BCAPTSEL  	MMIO32(EVENT + 0x604)

/* Output Selection for AUX Subscriber 0 */
#define AUXSEL0       	MMIO32(EVENT + 0x700)
#define EV_AUX_GPT2A        0x0c
#define EV_AUX_GPT2B        0x0d
#define EV_AUX_GPT3A        0x0e
#define EV_AUX_GPT3B        0x0f
#define EV_AUX_GPT0A        0x10
#define EV_AUX_GPT0B        0x11
#define EV_AUX_GPT1A        0x12
#define EV_AUX_GPT1B        0x13

/* Output Selection for NMI Subscriber 0 */
#define CM3NMISEL0  	MMIO32(EVENT + 0x800)
#define EV_CM3_WD       0x63

/* Output Selection for I2S Subscriber 0 */
#define I2SSTMPSEL0  	MMIO32(EVENT + 0x900)
// rw type
#define EV_INACTIVE   0x00
#define EV_ASSERTED   0x79

/* Output Selection for FRZ Subscriber */
#define FRZSEL0       	MMIO32(EVENT + 0xa00)
// rw type
#define EV_CPU_HALT   0x78

/* Set or Clear Software Events */
#define SWEV          	MMIO32(EVENT + 0xf00)
// Writing "1" to this bit when the value is "0" triggers the Software n event.
#define SWEV3   0x01000000
#define SWEV2   0x00010000
#define SWEV1   0x00000100
#define SWEV0   0x00000001
