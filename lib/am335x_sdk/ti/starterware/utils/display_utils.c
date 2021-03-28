/**
 *  \file     display_utils.c
 *
 *  \brief    This file contains the display utility APIs. These will be used
 *            to display image on the LCD.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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
#include "display_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DISPLAYUtilsInit(void)
{
    int32_t status = E_FAIL;

    status = DISPLAYUtilsModuleInit();

    return status;
}


int32_t DISPLAYUtilsConfig(uint32_t frmBufAddr,
                           uint32_t frmBufSize,
                           uint32_t inputFrmWidth,
                           uint32_t inputFrmHeight,
                           uint32_t inputFrmFormat,
                           DISPLAYUtilsIsrCallbackFxn pFnIsrCb)
{
    int32_t status = E_FAIL;

    if (NULL != frmBufAddr)
    {
        status = DISPLAYUtilsIpConfig(frmBufAddr, frmBufSize, inputFrmWidth,
            inputFrmHeight, inputFrmFormat, pFnIsrCb);
    }

    return status;
}


void DISPLAYUtilsStartDisplay(void)
{
    DISPLAYUtilsIpDisplayEnable();
}


void DISPLAYUtilsStopDisplay(void)
{
    DISPLAYUtilsIpDisplayDisable();
}


displayUtilsRes_t DISPLAYUtilsGetDisplayResolution(void)
{
    displayUtilsRes_t dispRes;

    DISPLAYUtilsIpGetDisplayResolution(&dispRes.width, &dispRes.height);

    return dispRes;
}

/* ========================================================================== */
/*                      Internal Function Definitions                         */
/* ========================================================================== */

/* None */
