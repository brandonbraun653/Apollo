/**
 * \file   soc.c
 *
 * \brief  This file contains the implementation of the APIs that get the
 *         SoC-specific details for StarterWare.
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

#include "types.h"
#include "soc.h"
#include "console_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 *  \brief Structure to store SOC ID and string pair.
 */
typedef struct socFamilyIdString
{
    socFamilyId_t socFamilyId;
    /**< SOC family ID. */
    const char * socFamilyIdStr;
    /**< Pointer to SOC family ID string. */
} socFamilyIdString_t;

/**
 *  \brief Structure to store core ID and string pair.
 */
typedef struct socCoreIdString
{
    socCoreId_t socCoreId;
    /**< Core ID. */
    const char * socCoreIdStr;
    /**< Pointer to core ID string. */
} socCoreIdString_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Contains the ID to string mappings for SoC Family IDs. */
static socFamilyIdString_t gSocFamilyIdStrTable[] =
{
    {SOC_FAMILY_ID_UNKNOWN, "UNKNOWN"},
    {SOC_FAMILY_ID_AM335X,  "AM335X" },
    {SOC_FAMILY_ID_AM43XX,  "AM43XX" },
};

/** \brief Contains the ID to string mappings for core IDs. */
static socCoreIdString_t gSocCoreIdStrTable[] =
{
    {SOC_CORE_ID_UNKNOWN, "UNKNOWN"},
    {SOC_CORE_ID_A8 ,     "A8"     },
    {SOC_CORE_ID_A9,      "A9"     },
};

/** \brief Number of entries in SOC Family ID string table. */
#define SOC_FAMILY_NUM_ID_STR_ENTRIES  (sizeof (gSocFamilyIdStrTable) / \
                                        sizeof (socFamilyIdString_t))

/** \brief Number of entries in Core ID string table. */
#define SOC_CORE_NUM_ID_STR_ENTRIES    (sizeof (gSocCoreIdStrTable) / \
                                        sizeof (socCoreIdString_t))


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

socFamilyId_t SOCGetSocFamilyId(void)
{
    socFamilyId_t socFamilyId = SOC_FAMILY_ID_UNKNOWN;

#ifdef AM335X_FAMILY_BUILD
    /* Platform is AM335X */
    socFamilyId = SOC_FAMILY_ID_AM335X;
#endif

#ifdef AM43XX_FAMILY_BUILD
    /* Platform is AM43XX */
    socFamilyId = SOC_FAMILY_ID_AM43XX;
#endif

    return (socFamilyId);
}

socCoreId_t SOCGetCoreId(void)
{
    socCoreId_t coreId = SOC_CORE_ID_UNKNOWN;

#ifdef BUILD_A8
    /* Core is A8 */
    coreId = SOC_CORE_ID_A8;
#endif

#ifdef BUILD_A9
    /* Core is A9 */
    coreId = SOC_CORE_ID_A9;
#endif

    return (coreId);
}

const char * SOCGetSocFamilyName(void)
{
    const char * socFamilyIdStr = NULL;
    socFamilyId_t socFamilyId;
    uint32_t entryCnt;

    socFamilyId = SOCGetSocFamilyId();
    if (socFamilyId >= SOC_FAMILY_ID_MAX)
    {
        socFamilyId = SOC_FAMILY_ID_UNKNOWN;
    }

    for (entryCnt = 0u; entryCnt < SOC_FAMILY_NUM_ID_STR_ENTRIES; entryCnt++)
    {
        if (gSocFamilyIdStrTable[entryCnt].socFamilyId == socFamilyId)
        {
            socFamilyIdStr = gSocFamilyIdStrTable[entryCnt].socFamilyIdStr;
            break;
        }
    }

    return (socFamilyIdStr);
}

const char * SOCGetCoreName(void)
{
    const char * socCoreIdStr = NULL;
    socCoreId_t socCoreId;
    uint32_t entryCnt;

    socCoreId = SOCGetCoreId();
    if (socCoreId >= SOC_CORE_ID_MAX)
    {
        socCoreId = SOC_CORE_ID_UNKNOWN;
    }

    for (entryCnt = 0u; entryCnt < SOC_CORE_NUM_ID_STR_ENTRIES; entryCnt++)
    {
        if (gSocCoreIdStrTable[entryCnt].socCoreId == socCoreId)
        {
            socCoreIdStr = gSocCoreIdStrTable[entryCnt].socCoreIdStr;
            break;
        }
    }

    return (socCoreIdStr);
}

void SOCPrintInfo(void)
{
    CONSOLEUtilsPrintf(" SoC                   : [%s]\r\n",
        SOCGetSocFamilyName());
    CONSOLEUtilsPrintf(" Core                  : [%s]\r\n", SOCGetCoreName());

    return;
}

