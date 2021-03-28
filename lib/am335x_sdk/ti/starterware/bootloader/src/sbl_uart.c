/**
 *  \file  sbl_uart.c
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

#include "types.h"
#include "hw_types.h"
#include "console_utils.h"
#include "xmodem.h"
#include "board.h"
#include "chipdb.h"
#include "sbl.h"
#include "sbl_platform.h"
#include "sbl_uart.h"

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

uint32_t SBLUartCopy(uint32_t *pEntryPoint, uint32_t* imageSize, uint32_t instNum)
{
    uint32_t retVal = TRUE;
    uint32_t baseAddr = 0U;
    int32_t  receivedSize = 0;

    baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_UART, instNum);

    xmodemConfigBaseAddr(baseAddr);

    CONSOLEUtilsPrintf("\nPlease transfer file with XMODEM protocol...\n");
    receivedSize =  xmodemReceive((uint8_t *)SBL_PLATFORM_DDR_START_ADDR,
                      SBL_PLATFORM_IMAGE_SIZE);

    if(receivedSize < 0)
    {
        CONSOLEUtilsPrintf("\nXmodem receive error\n");
        *imageSize = 0;
        retVal = FALSE;
    }

    if(TRUE == retVal)
    {
        CONSOLEUtilsPrintf("\nXmodem received %d bytes\n", receivedSize);
        CONSOLEUtilsPrintf("\nCopying application image from UART"
                           " to RAM is done\n");
        
        *imageSize = receivedSize;
    }

    *pEntryPoint = SBL_PLATFORM_DDR_START_ADDR;

    return retVal;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
