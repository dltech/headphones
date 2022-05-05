/*
 * Simple CC2640 headphones
 * Memory map for peripherial
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

#define SSI0         0x40000000
#define UART0        0x40001000
#define I2C0         0x40002000
#define SSI1         0x40008000
#define GPT0         0x40010000
#define GPT1         0x40011000
#define GPT2         0x40012000
#define GPT3         0x40013000
#define UDMA0        0x40020000
#define I2S0         0x40021000
#define GPIO         0x40022000
#define CRYPTO       0x40024000
#define TRNG         0x40028000
#define FLASH        0x40030000
#define VIMS         0x40034000
#define RFC_PWR      0x40040000
#define RFC_DBELL    0x40041000
#define RFC_RAT      0x40043000
#define WDT          0x40080000
#define IOC          0x40081000
#define PRCM         0x40082000
#define EVENT        0x40083000
#define SMPH         0x40084000
#define AON_SYSCTL   0x40090000
#define AON_WUC      0x40091000
#define AON_RTC      0x40092000
#define AON_EVENT    0x40093000
#define AON_IOC      0x40094000
#define AON_BATMON   0x40095000
#define AON_AIODIO0  0x400c1000
#define AUX_AIODIO1  0x400c2000
#define AUX_TDCIF    0x400c4000
#define AUX_EVCTL    0x400c5000
#define AUX_WUC      0x400c6000
#define AUX_TIMER    0x400c7000
#define AUX_SMPH     0x400c8000
#define AUX_ANAIF    0x400c9000
#define AUX_DDI0_OSC 0x400ca000
#define AUX_ADI4     0x400cb000
#define AUX_RAM      0x400E0000
#define AUX_SCE      0x400E1000
#define FCFG1        0x50001000
#define CCFG         0x50003000

// access to register with specified address
#define  MMIO32(addr)		(*(volatile uint32_t *)(addr))
