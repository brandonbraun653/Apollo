/**
 *  \file  console_utils_defs.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         use user interface example utils.
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

#ifndef CONSOLE_UTILS_DEFS_H_
#define CONSOLE_UTILS_DEFS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include "hw_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Maximum number of characters user can input. */
#define CONSOLE_UTILS_INPUT_SIZE_MAX                (128U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Enumerates data type configurations.
 */
typedef enum consoleUtilsDataType
{
    CONSOLE_UTILS_DATA_TYPE_MIN,
    /**< First value of enumeration. Can be used used for validation. */
    CONSOLE_UTILS_DATA_TYPE_CHAR = CONSOLE_UTILS_DATA_TYPE_MIN,
    /**< Char. */
    CONSOLE_UTILS_DATA_TYPE_DECIMAL,
    /**< Signed decimal. */
    CONSOLE_UTILS_DATA_TYPE_HEX,
    /**< Hexadecimal. */
    CONSOLE_UTILS_DATA_TYPE_UNSIGN_DECIMAL,
    /**< Unsigned decimal. */
    CONSOLE_UTILS_DATA_TYPE_STR,
    /**< String. */
    CONSOLE_UTILS_DATA_TYPE_MAX
    /**< Invalid data type. */
} consoleUtilsDataType_t;

/**
 *  \brief Enumerates data read status.
 */
typedef enum consoleUtilsReadStatus
{
    CONSOLE_UTILS_READ_STATUS_MIN,
    /**< First value of enumeration. Can be used used for validation. */
    CONSOLE_UTILS_READ_STATUS_CONTINUE = CONSOLE_UTILS_READ_STATUS_MIN,
    /**< Read in progress. Applicable for non-blocking interface. */
    CONSOLE_UTILS_READ_STATUS_TERMINATE,
    /**< Reached a termination condition (newline character). */
    CONSOLE_UTILS_READ_STATUS_MAX
    /**< Invalid read status. */
} consoleUtilsReadStatus_t;

/**
 *  \brief Enumerates steps to get non-blocking input.
 */
typedef enum consoleUtilsInputStatus
{
    CONSOLE_UTILS_INPUT_STATUS_MIN,
    /**< First value of enumeration. Can be used used for validation. */
    CONSOLE_UTILS_INPUT_STATUS_INIT = CONSOLE_UTILS_INPUT_STATUS_MIN,
    /**< Initialize. */
    CONSOLE_UTILS_INPUT_STATUS_READ,
    /**< Read. */
    CONSOLE_UTILS_INPUT_STATUS_DECODE,
    /**< Decode. */
    CONSOLE_UTILS_INPUT_STATUS_MAX
    /**< Invalid state. */
} consoleUtilsInputStatus_t;

/**
 *  \brief Structure defining parameters for string data type.
 *
 *  These configurations are used to determine the parameters required for
 *  string.
 */
typedef struct consoleUtilsStringParams
{
    uint32_t type : 4;
    /**< Data type. Refer #consoleUtilsDataType_t. */
    uint32_t reserved : 20;
    /**< Reserved for extended purpose. */
    uint32_t size : 8;
    /**< Configuration to display page item. */
} consoleUtilsStringParams_t;

/**
 *  \brief Structure defining parameters of a data type.
 *
 *  These configurations are used to determine the parameters required of a
 *  data type.
 */
typedef struct consoleUtilsDataTypeParams
{
    uint32_t type : 4;
    /**< Data type. Refer #consoleUtilsDataType_t. */
    uint32_t reserved : 28;
    /**< Reserved for extended purpose. */
} consoleUtilsDataTypeParams_t;

/**
 *  \brief Union defining configuration of a data type.
 *
 *  These configurations are used to determine the data type.
 */
typedef union consoleUtilsDataTypeConfig
{
    consoleUtilsDataTypeParams_t config;
    /**< Generic data type parameters. */
    consoleUtilsStringParams_t stringConfig;
    /**< String data type parameters. */
    uint32_t value;
    /**< Configuration value of data type. */
} consoleUtilsDataTypeConfig_t;

/**
 *  \brief Structure defining a buffer.
 *
 *  These configurations are used to determine the buffer parameters and buffer.
 */
typedef struct consoleUtilsBuf
{
    uint8_t* pBuf;
    /**< Pointer to the start index of buffer. */
    uint32_t* curBufIndex;
    /**< Represents the current index. */
    uint32_t bufSize;
    /**< Buffer size. For maximum size refer #CONSOLE_UTILS_INPUT_SIZE_MAX. */
} consoleUtilsBuf_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef CONSOLE_UTILS_DEFS_H_ */
