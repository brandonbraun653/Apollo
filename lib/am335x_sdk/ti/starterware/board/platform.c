/**
 * \file   platform.c
 *
 * \brief  This file contains the implementation of the APIs that abstract the
 *         platform-specific details for StarterWare.
 *
 */

/*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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
#include <platform.h>
#include <console_utils.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 *  struct platformIdString_t
 *  \brief Structure to store board ID and string pair.
 */
typedef struct
{
    platformId_t platformId;
    /**< Platform ID. */
    const char  *platformIdStr;
    /**< Pointer to Platform ID string. */
} platformIdString_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static platformIdString_t  gPlatformIdStrTable[] =
{
    {PLATFORM_ID_UNKNOWN, "UNKNOWN"},
    {PLATFORM_ID_EVM,     "EVM"    },
    {PLATFORM_ID_SIM,     "SIM"    },
    {PLATFORM_ID_ZEBU,    "ZEBU"   },
    {PLATFORM_ID_VIRTIO,  "VIRTIO" }
};

/** \brief Number of entries in Platform ID string table. */
#define PLATFORM_NUM_ID_STR_ENTRIES     (sizeof (gPlatformIdStrTable) / \
                                             sizeof (platformIdString_t))

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

platformId_t PLATFORMGetId(void)
{
    platformId_t platformId = PLATFORM_ID_UNKNOWN;

#ifdef PLATFORM_EVM_SI
    /* Platform is EVM */
    platformId = PLATFORM_ID_EVM;
#endif

#ifdef PLATFORM_SIM
    /* Platform is Simulator */
    platformId = PLATFORM_ID_SIM;
#endif

#ifdef PLATFORM_ZEBU
    /* Platform is Zebu */
    platformId = PLATFORM_ID_ZEBU;
#endif

#ifdef PLATFORM_VIRTIO
    /* Platform is Virtio */
    platformId = PLATFORM_ID_VIRTIO;
#endif

    return (platformId);
}

const char * PLATFORMGetString(void)
{
    platformId_t platformId;
    const char    *platformIdStr = NULL;
    uint32_t         entryCnt;

    platformId = PLATFORMGetId();
    if (platformId >= PLATFORM_ID_MAX)
    {
        platformId = PLATFORM_ID_UNKNOWN;
    }

    for (entryCnt = 0u; entryCnt < PLATFORM_NUM_ID_STR_ENTRIES; entryCnt++)
    {
        if (gPlatformIdStrTable[entryCnt].platformId == platformId)
        {
            platformIdStr = gPlatformIdStrTable[entryCnt].platformIdStr;
            break;
        }
    }

    return (platformIdStr);
}

void PLATFORMPrintInfo(void)
{
    CONSOLEUtilsPrintf(
              " Platform              : [%s]\r\n", PLATFORMGetString());

    return;
}

