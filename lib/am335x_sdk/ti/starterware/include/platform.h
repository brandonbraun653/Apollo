/**
 *  \file  platform.h
 *
 *  \brief This file contains platform specific defines.
 *
 *  The SoC can be integrated into different platform types such as EVM, Zebu,
 *  simulator etc. This file defines such platform specific aspects.
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

#ifndef PLATFORM_H_
#define PLATFORM_H_

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
 *  \brief Platform ID.
 */
typedef enum platformId
{
    PLATFORM_ID_UNKNOWN = 0x0001u,
    /**< Unknown platform. */
    PLATFORM_ID_EVM = 0x0002u,
    /**< EVMs. */
    PLATFORM_ID_SIM = 0x0004u,
    /**< Simulator. */
    PLATFORM_ID_ZEBU = 0x0008u,
    /**< Zebu presilicon platform. */
    PLATFORM_ID_VIRTIO = 0x0010u,
    /**< Virtio presilicon platform. */
    PLATFORM_ID_MAX = 0xFFFFu
    /**< Max Platform ID. */
} platformId_t;


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief Returns the platform ID.
 *
 *  \retval Platform_ID             On success.
 *  \retval PLATFORM_ID_UNKNOWN     Otherwise.
 */
platformId_t PLATFORMGetId(void);

/**
 *  \brief Function to get the name of the platform in printable string.
 *
 *  \retval Platform_name   Returns a const pointer to the string. If the
 *                          platform is not known, then it returns the string as
 *                          "UNKNOWN".
 */
const char * PLATFORMGetString(void);

/**
 *  \brief Funtion to print the platform information
 *
 */
void PLATFORMPrintInfo(void);


#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif /* #ifndef PLATFORM_H_ */
