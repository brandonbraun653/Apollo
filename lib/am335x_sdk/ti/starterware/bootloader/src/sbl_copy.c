/**
 *  \file  sbl_platform_uart.c
 *
 * \brief  This file contain functions which compute ASCII for standard
 *         operations.
 *
 *  \copyright Copyright (C) 2013-2017 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <types.h>
#include "console_utils.h"
#include "sbl.h"
#include "sbl_platform.h"
#include "hw_types.h"
#if defined(BOOT_MMCSD)
#include "sbl_mmcsd.h"
#endif
#if defined(BOOT_UART)
#include "sbl_uart.h"
#endif
#if defined(BOOT_QSPI)
#include "sbl_qspi.h"
#endif
#if defined(BOOT_NAND)
#include "sbl_nand.h"
#endif
#if defined(BOOT_MCSPI)
#include "sbl_mcspi.h"
#endif
#include "sbl_copy.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * \brief This function copies Image
 *
 * \param  none
 *
 * \return none
 */
void SBLCopyImage(uint32_t *pEntryPoint, uint32_t* imageSize)
{
    uint32_t instNum = 0U;

    *imageSize = 0;

#if defined(BOOT_MMCSD)
    SBLMmcsdCopy(pEntryPoint, imageSize, instNum);
#elif defined(BOOT_UART)
    SBLUartCopy(pEntryPoint, imageSize, instNum);
#elif defined(BOOT_QSPI)
    SBLQspiCopy(pEntryPoint, instNum);
#elif defined(BOOT_NAND)
    SBLNandCopy(pEntryPoint, instNum);
#elif defined(BOOT_MCSPI)
    SBLMcspiCopy(pEntryPoint, instNum);
#else
    #error Unsupported boot mode !!
#endif
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */




/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
