/******************************************************************************
 * Copyright (c) 2017 Texas Instruments Incorporated - http://www.ti.com
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/
 
#ifndef BOARD_PLL_H
#define BOARD_PLL_H

#include <ti/csl/soc.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \file   board_pll.h
 *
 * \brief  AM65x EVM PLL configurations header file
 *
 * This file includes the structures, enums and register offsets
 * for PLL configurations
 *
 */


/*PLL register offsets */
#define PLL_KICK0_OFFSET            (0x0010)
#define PLL_KICK1_OFFSET            (0x0014)
#define PLL_FREQ_CTRL0_OFFSET       (0x0020)
#define PLL_FREQ_CTRL1_OFFSET       (0x0024)
#define PLL_CLKDIV_OFFSET           (0x0028)
#define PLL_PROG_OFFSET             (0x002C)
#define PLL_CTRL_OFFSET             (0x0030)
#define PLL_STAT_OFFSET             (0x0034)
#define PLL_HSDIV_CLKDIV_OFFSET     (0x0120)
#define PLL_HSDIV_CTRL_OFFSET       (0x0124)
#define PLL_HSDIV_STAT_OFFSET       (0x0128)


/* PLL controller register offsets */
#define PLL_CTRL_PLLCTL_OFFSET      (0x0100)
#define PLL_CTRL_OCSEL_OFFSET       (0x0104)
#define PLL_CTRL_PREDIV_OFFSET      (0x0114)
#define PLL_CTRL_PLLDIV1_OFFSET     (0x0118)
#define PLL_CTRL_PLLDIV2_OFFSET     (0x011C)
#define PLL_CTRL_PLLDIV3_OFFSET     (0x0120)
#define PLL_CTRL_OSCDIV1_OFFSET     (0x0124)
#define PLL_CTRL_POSTDIV_OFFSET     (0x0128)
#define PLL_CTRL_BPDIV_OFFSET       (0x012C)
#define PLL_CTRL_PLLCMD_OFFSET      (0x0138)
#define PLL_CTRL_PLLSTAT_OFFSET     (0x013C)
#define PLL_CTRL_ALNCTL_OFFSET      (0x0140)
#define PLL_CTRL_CKEN_OFFSET        (0x0148)
#define PLL_CTRL_CKSTAT_OFFSET      (0x014C)
#define PLL_CTRL_SYSTAT_OFFSET      (0x0150)
#define PLL_CTRL_PLLDIV4_OFFSET     (0x0160)
#define PLL_CTRL_PLLDIV5_OFFSET     (0x0164)
#define PLL_CTRL_PLLDIV6_OFFSET     (0x0168)
#define PLL_CTRL_PLLDIV7_OFFSET     (0x016C)
#define PLL_CTRL_PLLDIV8_OFFSET     (0x0170)
#define PLL_CTRL_PLLDIV9_OFFSET     (0x0174)
#define PLL_CTRL_PLLDIV10_OFFSET    (0x0178)
#define PLL_CTRL_PLLDIV11_OFFSET    (0x017C)
#define PLL_CTRL_PLLDIV12_OFFSET    (0x0180)
#define PLL_CTRL_PLLDIV13_OFFSET    (0x0184)
#define PLL_CTRL_PLLDIV14_OFFSET    (0x0188)
#define PLL_CTRL_PLLDIV15_OFFSET    (0x018C)
#define PLL_CTRL_PLLDIV16_OFFSET    (0x0190)

#define KICK0_UNLOCK                0x68EF3490
#define KICK1_UNLOCK                0xD172BC5A
#define KICK_LOCK                   0x00000000

#define M3_MCU_OFFSET               (0x20000000)
#define M3_MAIN_OFFSET				(0x80000000)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* BOARD_PLL_H */

