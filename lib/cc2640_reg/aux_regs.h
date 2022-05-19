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

/*  */
#define MUX0            MMIO32(AUX_ADI4 + 0x0)

/*  */
#define MUX1            MMIO32(AUX_ADI4 + 0x1)

/*  */
#define MUX2            MMIO32(AUX_ADI4 + 0x2)

/*  */
#define MUX3            MMIO32(AUX_ADI4 + 0x3)

/*  */
#define ISRC            MMIO32(AUX_ADI4 + 0x4)

/*  */
#define COMP            MMIO32(AUX_ADI4 + 0x5)

/*  */
#define MUX4            MMIO32(AUX_ADI4 + 0x7)

/*  */
#define ADC0            MMIO32(AUX_ADI4 + 0x8)

/*  */
#define ADC1            MMIO32(AUX_ADI4 + 0x9)

/*  */
#define ADCREF0         MMIO32(AUX_ADI4 + 0xa)

/*  */
#define ADCREF0         MMIO32(AUX_ADI4 + 0xb)



/*  */
#define GPIODOUT0       MMIO32(AON_AIODIO0 + 0x00)
#define GPIODOUT1       MMIO32(AON_AIODIO1 + 0x00)

/*  */
#define IOMODE0         MMIO32(AON_AIODIO0 + 0x04)
#define IOMODE1         MMIO32(AON_AIODIO1 + 0x04)

/*  */
#define GPIODIN0        MMIO32(AON_AIODIO0 + 0x08)
#define GPIODIN1        MMIO32(AON_AIODIO1 + 0x08)

/*  */
#define GPIODOUTSET0    MMIO32(AON_AIODIO0 + 0x0c)
#define GPIODOUTSET1    MMIO32(AON_AIODIO1 + 0x0c)

/*  */
#define GPIODOUTCLR0    MMIO32(AON_AIODIO0 + 0x10)
#define GPIODOUTCLR1    MMIO32(AON_AIODIO1 + 0x10)

/*  */
#define GPIODOUTTGL0    MMIO32(AON_AIODIO0 + 0x14)
#define GPIODOUTTGL1    MMIO32(AON_AIODIO1 + 0x14)

/*  */
#define GPIODIE0        MMIO32(AON_AIODIO0 + 0x18)
#define GPIODIE1        MMIO32(AON_AIODIO1 + 0x18)


/*  */
#define VECCFG0         MMIO32(AUX_EVCTL + 0x00)

/*  */
#define VECCFG1         MMIO32(AUX_EVCTL + 0x04)

/*  */
#define SCEWEVSEL       MMIO32(AUX_EVCTL + 0x08)

/*  */
#define EVTOAONFLAGS    MMIO32(AUX_EVCTL + 0x0c)

/*  */
#define EVTOAONPOL      MMIO32(AUX_EVCTL + 0x10)

/*  */
#define DMACTL          MMIO32(AUX_EVCTL + 0x14)

/*  */
#define SWEVSET         MMIO32(AUX_EVCTL + 0x18)

/*  */
#define EVSTAT0         MMIO32(AUX_EVCTL + 0x1c)

/*  */
#define EVSTAT1         MMIO32(AUX_EVCTL + 0x20)

/*  */
#define EVTOMCUPOL      MMIO32(AUX_EVCTL + 0x24)

/*  */
#define EVTOMCUFLAGS    MMIO32(AUX_EVCTL + 0x28)

/*  */
#define COMBEVTOMCUMASK MMIO32(AUX_EVCTL + 0x2c)

/*  */
#define VECFLAGS        MMIO32(AUX_EVCTL + 0x34)

/*  */
#define EVTOMCUFLAGSCLR MMIO32(AUX_EVCTL + 0x38)

/*  */
#define EVTOAONFLAGSCLR MMIO32(AUX_EVCTL + 0x3c)

/*  */
#define VECFLAGSCLR     MMIO32(AUX_EVCTL + 0x40)


/*  */
#define MSMPH0          MMIO32(AUX_SMPH + 0x00)

/*  */
#define MSMPH1          MMIO32(AUX_SMPH + 0x04)

/*  */
#define MSMPH2          MMIO32(AUX_SMPH + 0x08)

/*  */
#define MSMPH3          MMIO32(AUX_SMPH + 0x0c)

/*  */
#define MSMPH4          MMIO32(AUX_SMPH + 0x10)

/*  */
#define MSMPH5          MMIO32(AUX_SMPH + 0x14)

/*  */
#define MSMPH6          MMIO32(AUX_SMPH + 0x18)

/*  */
#define MSMPH7          MMIO32(AUX_SMPH + 0x1c)

/*  */
#define AUTOTAKE        MMIO32(AUX_SMPH + 0x20)


/*  */
#define AUX_CTL         MMIO32(AUX_TDCIF + 0x00)

/*  */
#define AUX_STAT        MMIO32(AUX_TDCIF + 0x04)

/*  */
#define RESULT          MMIO32(AUX_TDCIF + 0x08)

/*  */
#define SATCFG          MMIO32(AUX_TDCIF + 0x0c)

/*  */
#define TRIGSRC         MMIO32(AUX_TDCIF + 0x10)

/*  */
#define TRIGCNT         MMIO32(AUX_TDCIF + 0x14)

/*  */
#define TRIGCNTLOAD     MMIO32(AUX_TDCIF + 0x18)

/*  */
#define TRIGCNTCFG      MMIO32(AUX_TDCIF + 0x1c)

/*  */
#define PRECTL          MMIO32(AUX_TDCIF + 0x20)

/*  */
#define PRECNT          MMIO32(AUX_TDCIF + 0x24)


/*  */
#define T0CFG           MMIO32(AUX_TIMER + 0x00)

/*  */
#define T1CFG           MMIO32(AUX_TIMER + 0x04)

/*  */
#define T0CTL           MMIO32(AUX_TIMER + 0x08)

/*  */
#define T0TARGET        MMIO32(AUX_TIMER + 0x0c)

/*  */
#define T1TARGET        MMIO32(AUX_TIMER + 0x10)

/*  */
#define T1CTL           MMIO32(AUX_TIMER + 0x14)


/*  */
#define MODCLKEN0       MMIO32(AUX_WUC + 0x00)

/*  */
#define PWROFFREQ       MMIO32(AUX_WUC + 0x04)

/*  */
#define PWRDWNREQ       MMIO32(AUX_WUC + 0x08)

/*  */
#define PWRDWNACK       MMIO32(AUX_WUC + 0x0c)

/*  */
#define CLKLFREQ        MMIO32(AUX_WUC + 0x10)

/*  */
#define CLKLFACK        MMIO32(AUX_WUC + 0x14)

/*  */
#define WUEVFLAGS       MMIO32(AUX_WUC + 0x28)

/*  */
#define WUEVCLR         MMIO32(AUX_WUC + 0x2c)

/*  */
#define ADCCLKCTL       MMIO32(AUX_WUC + 0x30)

/*  */
#define TDCCLKCTL       MMIO32(AUX_WUC + 0x34)

/*  */
#define REFCLKCTL       MMIO32(AUX_WUC + 0x38)

/*  */
#define RTCSUBSECINC0   MMIO32(AUX_WUC + 0x3c)

/*  */
#define RTCSUBSECINC0   MMIO32(AUX_WUC + 0x40)

/*  */
#define RTCSUBSECINCCTL MMIO32(AUX_WUC + 0x44)

/*  */
#define MCUBUSCTL       MMIO32(AUX_WUC + 0x48)

/*  */
#define MCUBUSSTAT      MMIO32(AUX_WUC + 0x4c)

/*  */
#define AONCTLSTAT      MMIO32(AUX_WUC + 0x50)

/*  */
#define AUXIOLATCH      MMIO32(AUX_WUC + 0x54)

/*  */
#define MODCLKEN1       MMIO32(AUX_WUC + 0x5c)


/*  */
#define ADCCTL          MMIO32(AUX_ANAIF + 0x10)

/*  */
#define ADCFIFOSTAT     MMIO32(AUX_ANAIF + 0x14)

/*  */
#define ADCFIFO         MMIO32(AUX_ANAIF + 0x18)

/*  */
#define ADCTRIG         MMIO32(AUX_ANAIF + 0x1c)

/*  */
#define ISRCCTL         MMIO32(AUX_ANAIF + 0x20)

#endif
