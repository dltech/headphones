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

/* Data */
#define UART_DR     MMIO32(UART0 + 0x00)
// UART Overrun Error
#define OE          0x800
// UART Break Error
#define BE          0x400
// UART Parity Error
#define PE          0x200
// UART Framing Error
#define FE          0x100
// Data transmitted or received
#define DATA_SFT    0
#define DATA_MSK    0xff

/* Status */
#define UART_RSR    MMIO32(UART0 + 0x04)
/* Error Clear */
#define UART_ECR    MMIO32(UART0 + 0x04)
// UART Overrun Error
#define RSR_OE  0x8
// UART Break Error
#define RSR_BE  0x4
// UART Parity Error
#define RSR_PE  0x2
// UART Framing Error
#define RSR_FE  0x1

/* Flag */
#define UART_FR     MMIO32(UART0 + 0x18)
// UART Transmit FIFO Empty
#define TXFE    0x80
// UART Receive FIFO Full
#define RXFF    0x40
// UART Transmit FIFO Full
#define TXFF    0x20
// UART Receive FIFO Empty
#define RXFE    0x10
// UART Busy
#define BUSY    0x08
// Clear To Send
#define CTS     0x01

/* Integer Baud-Rate Divisor */
#define UART_IBRD   MMIO32(UART0 + 0x24)
// The integer baud rate divisor. DIVINT

/* Fractional Baud-Rate Divisor */
#define UART_FBRD   MMIO32(UART0 + 0x28)
// Fractional Baud-Rate Divisor. DIVFRAC

/* Line Control */
#define UART_LCRH   MMIO32(UART0 + 0x2c)
// UART Stick Parity Select
#define SPS     0x80
// UART Word Length
#define WLEN5   0x00
#define WLEN6   0x20
#define WLEN7   0x40
#define WLEN8   0x60
// UART Enable FIFOs
#define FEN     0x10
// UART Two Stop Bits Select
#define STP2    0x08
// UART Even Parity Select
#define EPS     0x04
// UART Parity Enable
#define PEN     0x02
// UART Send Break
#define BRK     0x01

/* Control */
#define UART_CTL    MMIO32(UART0 + 0x30)
// CTS hardware flow control enable
#define CTSEN   0x8000
// RTS hardware flow control enable
#define RTSEN   0x4000
// Request to Send
#define RTS     0x0800
// UART Receive Enable
#define RXE     0x0200
// UART Transmit Enable
#define TXE     0x0100
// UART Loop Back Enable:
#define LBE     0x0080
// UART Enable
#define UARTEN  0x0001

/* Interrupt FIFO Level Select */
#define UART_IFLS   MMIO32(UART0 + 0x34)
// Receive interrupt FIFO level select
#define RXSEL1_8    0x00
#define RXSEL2_8    0x08
#define RXSEL4_8    0x10
#define RXSEL6_8    0x18
#define RXSEL7_8    0x20
// Transmit interrupt FIFO level select
#define TXSEL1_8    0x00
#define TXSEL2_8    0x01
#define TXSEL4_8    0x02
#define TXSEL6_8    0x03
#define TXSEL7_8    0x04

/* Interrupt Mask Set/Clear */
#define UART_IMSC   MMIO32(UART0 + 0x38)
// Overrun error interrupt mask.
#define OEIM    0x400
// Break error interrupt mask.
#define BEIM    0x200
// Parity error interrupt mask.
#define PEIM    0x100
// Framing error interrupt mask.
#define FEIM    0x080
// Receive timeout interrupt mask.
#define RTIM    0x040
// Transmit interrupt mask.
#define TXIM    0x020
// Receive interrupt mask.
#define RXIM    0x010
// Clear to Send (CTS) modem interrupt mask.
#define CTSMIM  0x002

/* Raw Interrupt Status */
#define UART_RIS    MMIO32(UART0 + 0x3c)
// Overrun error interrupt status.
#define OERIS    0x400
// Break error interrupt status.
#define BERIS    0x200
// Parity error interrupt status.
#define PERIS    0x100
// Framing error interrupt status.
#define FERIS    0x080
// Receive timeout interrupt status.
#define RTRIS    0x040
// Transmit interrupt status.
#define TXRIS    0x020
// Receive interrupt status.
#define RXRIS    0x010
// Clear to Send (CTS) modem interrupt status.
#define CTSMIM   0x002

/* Masked Interrupt Status */
#define UART_MIS    MMIO32(UART0 + 0x40)
// Overrun error masked interrupt status.
#define OEMIS   0x400
// Break error masked interrupt status.
#define BEMIS   0x200
// Parity error masked interrupt status.
#define PEMIS   0x100
// Framing error masked interrupt status.
#define FEMIS   0x080
// Receive timeout masked interrupt status.
#define RTMIS   0x040
// Transmit masked interrupt status.
#define TXMIS   0x020
// Receive masked interrupt status.
#define RXMIS   0x010
// Clear to Send (CTS) modem masked interrupt status.
#define CTSMMIS 0x002

/* Interrupt Clear */
#define UART_ICR    MMIO32(UART0 + 0x44)
// Overrun error masked interrupt status.
#define OEIC   0x400
// Break error masked interrupt status.
#define BEIC   0x200
// Parity error masked interrupt status.
#define PEIC   0x100
// Framing error masked interrupt status.
#define FEIC   0x080
// Receive timeout masked interrupt status.
#define RTIC   0x040
// Transmit masked interrupt status.
#define TXIC   0x020
// Receive masked interrupt status.
#define RXIC   0x010
// Clear to Send (CTS) modem masked interrupt status.
#define CTSMIC 0x002

/* DMA Control */
#define UART_DMACTL MMIO32(UART0 + 0x48)
// DMA on error.
#define DMAONERR    0x4
// Transmit DMA enable.
#define TXDMAE      0x2
// Receive DMA enable.
#define RXDMAE      0x1


#endif
