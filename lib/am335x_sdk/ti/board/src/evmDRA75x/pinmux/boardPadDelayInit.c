/**
 * \file  boardPadDelayInit.c
 *
 * \brief   This file contain manual/virtual iodelay mode definitions
 *
 * \copyright Copyright (CU) 2018 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

#include <stdint.h>
#include "board_internal.h"
#include "boardPadDelay.h"

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (pad_1_0, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t pad_1_0[] = {
#else
const boardPadDelayCfg_t pad_1_0[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
#if defined (SOC_DRA75x)
    #include <ti/board/src/evmDRA75x/pinmux/boardPadDelayGpmc_1_0.h>
    #include <ti/board/src/evmDRA75x/pinmux/boardPadDelayCommon_1_0.h>
#elif defined (SOC_DRA72x)
    #include <ti/board/src/evmDRA72x/pinmux/boardPadDelayGpmc_1_0.h>
    #include <ti/board/src/evmDRA72x/pinmux/boardPadDelayCommon_1_0.h>
#endif
};

#if defined(_TMS320C6X) || defined(__TI_ARM_V7M4__)
#    pragma DATA_SECTION (pad_2_0, "BOARD_IO_DELAY_DATA");
const boardPadDelayCfg_t pad_2_0[] = {
#else
const boardPadDelayCfg_t pad_2_0[] __attribute__((section("BOARD_IO_DELAY_DATA"))) = {
#endif
#if defined (SOC_DRA75x)
    #include <ti/board/src/evmDRA75x/pinmux/boardPadDelayGpmc_2_0.h>
    #include <ti/board/src/evmDRA75x/pinmux/boardPadDelayCommon_2_0.h>
#elif defined (SOC_DRA72x)
    #include <ti/board/src/evmDRA72x/pinmux/boardPadDelayGpmc_2_0.h>
    #include <ti/board/src/evmDRA72x/pinmux/boardPadDelayCommon_2_0.h>
#endif
};

const boardPadDelayCfg_t *boardPadGetCfg(uint32_t *size)
{
    const boardPadDelayCfg_t *pad;
    volatile uint32_t siliconRev = Board_getSiliconRev();

    if (siliconRev < 2U)
    {
        pad = pad_1_0;
        *size = sizeof(pad_1_0) / sizeof(boardPadDelayCfg_t);
    }
    else
    {
        pad = pad_2_0;
        *size = sizeof(pad_2_0) / sizeof(boardPadDelayCfg_t);
    }

    return pad;
}
