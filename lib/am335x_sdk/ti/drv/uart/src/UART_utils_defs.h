/**
 *  \file  UART_utils_defs.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         use user interface example utils.
 *
 */

/*
 * Copyright (C) 2013-2015 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef UART_UTILS_DEFS_H_
#define UART_UTILS_DEFS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stdarg.h>


#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Maximum number of characters user can input. */
#define UART_UTILS_INPUT_SIZE_MAX                (128U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Enumerates data type configurations.
 */
typedef enum UART_UtilsDataType
{
    UART_UTILS_DATA_TYPE_MIN = 0,
    /**< First value of enumeration. Can be used used for validation. */
    UART_UTILS_DATA_TYPE_CHAR = UART_UTILS_DATA_TYPE_MIN,
    /**< Char. */
    UART_UTILS_DATA_TYPE_DECIMAL = 1,
    /**< Signed decimal. */
    UART_UTILS_DATA_TYPE_HEX = 2,
    /**< Hexadecimal. */
    UART_UTILS_DATA_TYPE_UNSIGN_DECIMAL = 3,
    /**< Unsigned decimal. */
    UART_UTILS_DATA_TYPE_STR = 4,
    /**< String. */
    UART_UTILS_DATA_TYPE_MAX = 5
    /**< Invalid data type. */
} UART_UtilsDataType_t;

/**
 *  \brief Enumerates data read status.
 */
typedef enum UART_UtilsReadStatus
{
    UART_UTILS_READ_STATUS_MIN = 0,
    /**< First value of enumeration. Can be used used for validation. */
    UART_UTILS_READ_STATUS_CONTINUE = UART_UTILS_READ_STATUS_MIN,
    /**< Read in progress. Applicable for non-blocking interface. */
    UART_UTILS_READ_STATUS_TERMINATE = 1,
    /**< Reached a termination condition (newline character). */
    UART_UTILS_READ_STATUS_MAX = 2
    /**< Invalid read status. */
} UART_UtilsReadStatus_t;

/**
 *  \brief Enumerates steps to get non-blocking input.
 */
typedef enum UART_UtilsInputStatus
{
    UART_UTILS_INPUT_STATUS_MIN = 0,
    /**< First value of enumeration. Can be used used for validation. */
    UART_UTILS_INPUT_STATUS_INIT = UART_UTILS_INPUT_STATUS_MIN,
    /**< Initialize. */
    UART_UTILS_INPUT_STATUS_READ = 1,
    /**< Read. */
    UART_UTILS_INPUT_STATUS_DECODE = 2,
    /**< Decode. */
    UART_UTILS_INPUT_STATUS_MAX = 3
    /**< Invalid state. */
} UART_UtilsInputStatus_t;

/**
 *  \brief Structure defining parameters for string data type.
 *
 *  These configurations are used to determine the parameters required for
 *  string.
 */
typedef struct UART_UtilsStringParams
{
    uint32_t type : 4;
    /**< Data type. Refer #UART_UtilsDataType_t. */
    uint32_t reserved : 20;
    /**< Reserved for extended purpose. */
    uint32_t size : 8;
    /**< Configuration to display page item. */
} UART_UtilsStringParams_t;

/**
 *  \brief Structure defining parameters of a data type.
 *
 *  These configurations are used to determine the parameters required of a
 *  data type.
 */
typedef struct UART_UtilsDataTypeParams
{
    uint32_t type : 4;
    /**< Data type. Refer #UART_UtilsDataType_t. */
    uint32_t reserved : 28;
    /**< Reserved for extended purpose. */
} UART_UtilsDataTypeParams_t;

/**
 *  \brief Structure defining a buffer.
 *
 *  These configurations are used to determine the buffer parameters and buffer.
 */
typedef struct UART_UtilsBuf
{
    uint8_t* pBuf;
    /**< Pointer to the start index of buffer. */
    uint32_t* curBufIndex;
    /**< Represents the current index. */
    uint32_t bufSize;
    /**< Buffer size. For maximum size refer #UART_UTILS_INPUT_SIZE_MAX. */
} UART_UtilsBuf_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef UART_UTILS_DEFS_H_ */
