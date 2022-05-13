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

/* */
#define STAT        MMIO32(VIMS + 0x00)
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
