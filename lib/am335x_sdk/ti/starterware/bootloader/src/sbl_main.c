/**
 *  \file  sbl_main.c
 *
 * \brief  This file contain main function which of secondary bootloader.
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
#include "error.h"
#include "console_utils.h"
#include "sbl_copy.h"
#include "sbl_platform.h"
#include "board.h"
#include "cache.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function abort the bootloader.
 */
void SblAbort(void);

/**
 * \brief This function jumps to the application.
 */
static void (*pfnSBLAppEntry)();

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

uint32_t gSblEntryPoint = 0U;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    uint32_t status;
    uint32_t imageSize;

    status = BOARDInit(NULL);
    if(status != S_PASS)
    {
        return 1;
    }
#ifndef DDRLESS
    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\nStarterWare Boot Loader \n");
#endif

    /* Configures PLL and DDR controller*/
    SBLPlatformConfig();

    /* Copies application from non-volatile flash memory to RAM */
    SBLCopyImage(&gSblEntryPoint, &imageSize);

#ifdef SECURE_BOOT
    /* authenticate the boot image and decrypt in place if need to */
    if (SBL_authentication((void*)gSblEntryPoint, imageSize) != 0)
    {
        CONSOLEUtilsPuts("Boot Image authentication failed!\r\n\n");
        SblAbort();
    }
    else
    {
        CONSOLEUtilsPuts("Boot Image authentication passed!\r\n\n");
    }

    /* flush the caches associated with the boot image */
    CACHEDataCleanInvRange((uint32_t*)gSblEntryPoint, imageSize);
#endif

#ifndef DDRLESS
    CONSOLEUtilsPuts("Jumping to StarterWare Application...\r\n\n");
#endif

    /* Do any post-copy config before leaving boot loader */
    SBLPlatformConfigPostBoot();

    /* Giving control to the application */
    pfnSBLAppEntry = (void (*)(void)) gSblEntryPoint;

    (*pfnSBLAppEntry)( );

    return 0;
}

void SblAbort(void)
{
    while(1);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
