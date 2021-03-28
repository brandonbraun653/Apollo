/******************************************************************************
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
#include "csl_types.h"
#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \file   board_pll.h
 *
 * \brief  TPR12 EVM PLL configurations header file
 *
 * This file includes the structures, enums and register offsets
 * for PLL configurations
 *
 */

/*PLL register offsets */
#define PLL_CORE_PWRCTRL                    CSL_MSS_TOPRCM_PLL_CORE_PWRCTRL
#define PLL_CORE_CLKCTRL                    CSL_MSS_TOPRCM_PLL_CORE_CLKCTRL
#define PLL_CORE_TENABLE                    CSL_MSS_TOPRCM_PLL_CORE_TENABLE
#define PLL_CORE_TENABLEDIV                 CSL_MSS_TOPRCM_PLL_CORE_TENABLEDIV
#define PLL_CORE_M2NDIV                     CSL_MSS_TOPRCM_PLL_CORE_M2NDIV
#define PLL_CORE_MN2DIV                     CSL_MSS_TOPRCM_PLL_CORE_MN2DIV
#define PLL_CORE_FRACDIV                    CSL_MSS_TOPRCM_PLL_CORE_FRACDIV
#define PLL_CORE_BWCTRL                     CSL_MSS_TOPRCM_PLL_CORE_BWCTRL
#define PLL_CORE_FRACCTRL                   CSL_MSS_TOPRCM_PLL_CORE_FRACCTRL
#define PLL_CORE_STATUS                     CSL_MSS_TOPRCM_PLL_CORE_STATUS
#define PLL_CORE_HSDIVIDER                  CSL_MSS_TOPRCM_PLL_CORE_HSDIVIDER
#define PLL_CORE_HSDIVIDER_CLKOUT0          CSL_MSS_TOPRCM_PLL_CORE_HSDIVIDER_CLKOUT0
#define PLL_CORE_HSDIVIDER_CLKOUT1          CSL_MSS_TOPRCM_PLL_CORE_HSDIVIDER_CLKOUT1
#define PLL_CORE_HSDIVIDER_CLKOUT2          CSL_MSS_TOPRCM_PLL_CORE_HSDIVIDER_CLKOUT2
#define PLL_CORE_HSDIVIDER_CLKOUT3          CSL_MSS_TOPRCM_PLL_CORE_HSDIVIDER_CLKOUT3
#define PLL_DSP_PWRCTRL                     CSL_MSS_TOPRCM_PLL_DSP_PWRCTRL
#define PLL_DSP_CLKCTRL                     CSL_MSS_TOPRCM_PLL_DSP_CLKCTRL
#define PLL_DSP_TENABLE                     CSL_MSS_TOPRCM_PLL_DSP_TENABLE
#define PLL_DSP_TENABLEDIV                  CSL_MSS_TOPRCM_PLL_DSP_TENABLEDIV
#define PLL_DSP_M2NDIV                      CSL_MSS_TOPRCM_PLL_DSP_M2NDIV
#define PLL_DSP_MN2DIV                      CSL_MSS_TOPRCM_PLL_DSP_MN2DIV
#define PLL_DSP_FRACDIV                     CSL_MSS_TOPRCM_PLL_DSP_FRACDIV
#define PLL_DSP_BWCTRL                      CSL_MSS_TOPRCM_PLL_DSP_BWCTRL
#define PLL_DSP_FRACCTRL                    CSL_MSS_TOPRCM_PLL_DSP_FRACCTRL
#define PLL_DSP_STATUS                      CSL_MSS_TOPRCM_PLL_DSP_STATUS
#define PLL_DSP_HSDIVIDER                   CSL_MSS_TOPRCM_PLL_DSP_HSDIVIDER
#define PLL_DSP_HSDIVIDER_CLKOUT0           CSL_MSS_TOPRCM_PLL_DSP_HSDIVIDER_CLKOUT0
#define PLL_DSP_HSDIVIDER_CLKOUT1           CSL_MSS_TOPRCM_PLL_DSP_HSDIVIDER_CLKOUT1
#define PLL_DSP_HSDIVIDER_CLKOUT2           CSL_MSS_TOPRCM_PLL_DSP_HSDIVIDER_CLKOUT2
#define PLL_DSP_HSDIVIDER_CLKOUT3           CSL_MSS_TOPRCM_PLL_DSP_HSDIVIDER_CLKOUT3
#define PLL_PER_PWRCTRL                     CSL_MSS_TOPRCM_PLL_PER_PWRCTRL
#define PLL_PER_CLKCTRL                     CSL_MSS_TOPRCM_PLL_PER_CLKCTRL
#define PLL_PER_TENABLE                     CSL_MSS_TOPRCM_PLL_PER_TENABLE
#define PLL_PER_TENABLEDIV                  CSL_MSS_TOPRCM_PLL_PER_TENABLEDIV
#define PLL_PER_M2NDIV                      CSL_MSS_TOPRCM_PLL_PER_M2NDIV
#define PLL_PER_MN2DIV                      CSL_MSS_TOPRCM_PLL_PER_MN2DIV
#define PLL_PER_FRACDIV                     CSL_MSS_TOPRCM_PLL_PER_FRACDIV
#define PLL_PER_BWCTRL                      CSL_MSS_TOPRCM_PLL_PER_BWCTRL
#define PLL_PER_FRACCTRL                    CSL_MSS_TOPRCM_PLL_PER_FRACCTRL
#define PLL_PER_STATUS                      CSL_MSS_TOPRCM_PLL_PER_STATUS
#define PLL_PER_HSDIVIDER                   CSL_MSS_TOPRCM_PLL_PER_HSDIVIDER
#define PLL_PER_HSDIVIDER_CLKOUT0           CSL_MSS_TOPRCM_PLL_PER_HSDIVIDER_CLKOUT0
#define PLL_PER_HSDIVIDER_CLKOUT1           CSL_MSS_TOPRCM_PLL_PER_HSDIVIDER_CLKOUT1
#define PLL_PER_HSDIVIDER_CLKOUT2           CSL_MSS_TOPRCM_PLL_PER_HSDIVIDER_CLKOUT2
#define PLL_PER_HSDIVIDER_CLKOUT3           CSL_MSS_TOPRCM_PLL_PER_HSDIVIDER_CLKOUT3

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* BOARD_PLL_H */

