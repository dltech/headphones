#ifndef H_UART_REGS
#define H_UART_REGS
/*
 * Simple CC2640 headphones
 * Universal Asynchronous Receiver/Transmitter (UART) registers
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
#define UART_DR     MMIO32(UART0 + 0x00)

/*  */
#define UART_RSR    MMIO32(UART0 + 0x04)

/*  */
#define UART_ECR    MMIO32(UART0 + 0x04)

/*  */
#define UART_FR     MMIO32(UART0 + 0x18)

/*  */
#define UART_IBRD   MMIO32(UART0 + 0x24)

/*  */
#define UART_FBRD   MMIO32(UART0 + 0x28)

/*  */
#define UART_LCRH   MMIO32(UART0 + 0x2c)

/*  */
#define UART_CTL    MMIO32(UART0 + 0x30)

/*  */
#define UART_IFLS   MMIO32(UART0 + 0x34)

/*  */
#define UART_IMSC   MMIO32(UART0 + 0x38)

/*  */
#define UART_RIS    MMIO32(UART0 + 0x3c)

/*  */
#define UART_MIS    MMIO32(UART0 + 0x40)

/*  */
#define UART_ICR    MMIO32(UART0 + 0x44)

/*  */
#define UART_DMACTL MMIO32(UART0 + 0x48)


#endif
