/**
 *  \file  soc.h
 *
 *  \brief This file contains abstracts out SoC-specific information such as
 *  SoC ID, CPU revision etc.
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

#ifndef SOC_H_
#define SOC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \brief SOC Family ID.
 */
typedef enum socFamilyId
{
    SOC_FAMILY_ID_UNKNOWN = 0x0001U,
    /**< Unknown SOC family. */
    SOC_FAMILY_ID_AM335X = 0x0002U,
    /**< AM335X SOC family. */
    SOC_FAMILY_ID_AM43XX = 0x0004U,
    /**< AM43XX SOC family. */
    SOC_FAMILY_ID_MAX = 0xFFFFU
    /**< Max SOC family ID. */
} socFamilyId_t;

/**
 *  \brief Core ID.
 */
typedef enum socCoreId
{
    SOC_CORE_ID_UNKNOWN = 0x0001U,
    /**< Unknown Core. */
    SOC_CORE_ID_A8 = 0x0002U,
    /**< A8 Core. */
    SOC_CORE_ID_A9 = 0x0004U,
    /**< A9 Core. */
    SOC_CORE_ID_MAX = 0xFFFFU
    /**< Max CORE ID. */
} socCoreId_t;


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief Returns the SOC Family ID.
 *
 *  \retval SoC_Family_ID on success.
 */
socFamilyId_t SOCGetSocFamilyId(void);

/**
 *  \brief Returns the Core ID.
 *
 *  \retval Core_ID on success.
 */
socCoreId_t SOCGetCoreId(void);

/**
 *  \brief Function to get the name of the SOC Family in printable string.
 *
 *  \retval SoC_Family_Name Returns a const pointer to the string. If the SOC is
 *                          not known, then it returns the string as "UNKNOWN".
 */
const char * SOCGetSocFamilyName(void);

/**
 *  \brief Function to get the name of the Core in printable string.
 *
 *  \retval Core_Name       Returns a const pointer to the string. If the Core
 *                          not known, then it returns the string as "UNKNOWN".
 */
const char * SOCGetCoreName(void);

/**
 *  \brief Funtion to print all the platform information like CPU revision,
 *  CPU type...
 *
 */
void SOCPrintInfo(void);


#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif /* #ifndef SOC_H_ */
