/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       GPMC.h
 *
 *  @brief      GPMC driver interface
 *
 *  The GPMC header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/gpmc/GPMC.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef GPMC_H
#define GPMC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*!
 * Common GPMC_control command code reservation offset.
 * GPMC driver implementations should offset command codes with GPMC_CMD_RESERVED
 * growing positively
 *
 * Example implementation specific command codes:
 * @code
 * #define GPMCXYZ_COMMAND0         GPMC_CMD_RESERVED + 0
 * #define GPMCXYZ_COMMAND1         GPMC_CMD_RESERVED + 1
 * @endcode
 */
#define GPMC_CMD_RESERVED            (32U)

/*!
 * Common GPMC_control status code reservation offset.
 * GPMC driver implementations should offset status codes with
 * GPMC_STATUS_RESERVED growing negatively.
 *
 * Example implementation specific status codes:
 * @code
 * #define GPMCXYZ_STATUS_ERROR0    GPMC_STATUS_RESERVED - 0
 * #define GPMCXYZ_STATUS_ERROR1    GPMC_STATUS_RESERVED - 1
 * #define GPMCXYZ_STATUS_ERROR2    GPMC_STATUS_RESERVED - 2
 * @endcode
 */
#define GPMC_STATUS_RESERVED         (-((int32_t)32))

/*!
 * \brief   Successful status code returned by GPMC_control().
 *
 * GPMC_control() returns GPMC_STATUS_SUCCESS if the control code was executed
 * successfully.
 */
#define GPMC_STATUS_SUCCESS          ((int32_t)(0))

/*!
 * \brief   Generic error status code returned by GPMC_control().
 *
 * GPMC_control() returns GPMC_STATUS_ERROR if the control code was not executed
 * successfully.
 */
#define GPMC_STATUS_ERROR            (-((int32_t)1))

/*!
 * \brief   An error status code returned by GPMC_control() for undefined
 * command codes.
 *
 * GPMC_control() returns GPMC_STATUS_UNDEFINEDCMD if the control code is not
 * recognized by the driver implementation.
 */
#define GPMC_STATUS_UNDEFINEDCMD     (-((int32_t)2))

/*!
 *  @brief    Wait forever define
 */
#define GPMC_WAIT_FOREVER (~(0U))

/*!
 *  @brief    Maximum GPMC config count
 */
#define GPMC_MAX_CONFIG_CNT        (2U)
/*!
 *  @brief      A handle that is returned from a GPMC_open() call.
 */
typedef struct GPMC_Config_s      *GPMC_Handle;

/*!
 *  @brief      Type of the GPMC transaction.
 */
typedef enum GPMC_TransactionType_e {
    GPMC_TRANSACTION_TYPE_READ = 0,  /*!< Read transaction */
    GPMC_TRANSACTION_TYPE_WRITE      /*!< Write transaction */
} GPMC_TransactionType;

/*!
 *  @brief      Status codes that are set by the GPMC driver.
 */
typedef enum GPMC_TransactionStatus_s {
    GPMC_TRANSFER_COMPLETED = 0,
    GPMC_TRANSFER_STARTED,
    GPMC_TRANSFER_CANCELED,
    GPMC_TRANSFER_FAILED,
    GPMC_TRANSFER_CSN_DEASSERT

} GPMC_TransactionStatus;

/*!
 *  @brief
 *  A ::GPMC_Transaction data structure is used with GPMC_transfer().
 */
typedef struct GPMC_Transaction_s {
    /* User input (write-only) fields */
	GPMC_TransactionType   transType; /*!< transaction type */
    uint32_t               offset;    /*!< offset address of the memory device */
    uint32_t               count;     /*!< Number of bytes for this transaction */
    void                  *txBuf;     /*!< void * to a buffer with data to be transmitted */
    void                  *rxBuf;     /*!< void * to a buffer to receive data */
    void                  *arg;       /*!< Argument to be passed to the callback function */

    /* User output (read-only) fields */
    GPMC_TransactionStatus status;     /*!< Status code set by GPMC_transfer */

} GPMC_Transaction;

/*!
 *  @brief      The definition of a callback function used by the GPMC driver
 *              when used in ::GPMC_MODE_CALLBACK
 *
 *  @param      GPMC_Handle          GPMC_Handle
 *  @param      GPMC_Transaction*    GPMC_Transaction*
 */
typedef void (*GPMC_CallbackFxn)(GPMC_Handle handle,
                                 GPMC_Transaction * transaction);

/*!
 *  @brief
 *
 *  GPMC transfer mode determines the whether the GPMC controller operates
 *  synchronously or asynchronously. In ::GPMC_MODE_BLOCKING mode GPMC_transfer()
 *  blocks code execution until the GPMC transaction has completed. In
 *  ::GPMC_MODE_CALLBACK GPMC_transfer() does not block code execution and instead
 *  calls a ::GPMC_CallbackFxn callback function when the transaction has
 *  completed.
 */
typedef enum GPMC_TransferMode_s {
    /*!
     * GPMC_transfer() blocks execution. This mode can only be used when called
     * within a Task context
     */
    GPMC_MODE_BLOCKING,
    /*!
     * GPMC_transfer() does not block code execution and will call a
     * ::GPMC_CallbackFxn. This mode can be used in a Task, Swi, or Hwi context.
     */
    GPMC_MODE_CALLBACK

} GPMC_TransferMode;

/*!
 *  @brief GPMC Parameters
 *
 *  GPMC Parameters are used to with the GPMC_open() call. Default values for
 *  these parameters are set using GPMC_Params_init().
 *
 *  @sa         GPMC_Params_init()
 */
typedef struct GPMC_Params_s {
    GPMC_TransferMode    transferMode;        /*!< Blocking or Callback mode */
    uint32_t             transferTimeout;     /*!< Transfer timeout in system
                                                 ticks (Not supported with all
                                                 implementations */
    GPMC_CallbackFxn     transferCallbackFxn; /*!< Callback function pointer */

} GPMC_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              GPMC_init().
 */
typedef void (*GPMC_InitFxn)(GPMC_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              GPMC_open().
 */
typedef GPMC_Handle (*GPMC_OpenFxn)(GPMC_Handle handle,
                                    const GPMC_Params *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              GPMC_close().
 */
typedef void (*GPMC_CloseFxn)(GPMC_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              GPMC_transfer().
 */
typedef bool (*GPMC_TransferFxn)(GPMC_Handle handle,
                                 GPMC_Transaction *transaction);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              GPMC_control().
 */
typedef int32_t (*GPMC_ControlFxn)(GPMC_Handle handle,
                                   uint32_t cmd,
                                   void *arg);


/*!
 *  @brief      The definition of a GPMC function table that contains the
 *              required set of functions to control a specific GPMC driver
 *              implementation.
 */
typedef struct GPMC_FxnTable_s {
    /*! Function to initialize the given data object */
    GPMC_InitFxn             initFxn;

    /*! Function to open the specified peripheral */
    GPMC_OpenFxn             openFxn;

    /*! Function to close the specified peripheral */
    GPMC_CloseFxn            closeFxn;

    /*! Function to initiate a GPMC data transfer */
    GPMC_TransferFxn         transferFxn;

    /*! Function to implementation specific control function */
    GPMC_ControlFxn          controlFxn;

} GPMC_FxnTable;

/*!
 *  @brief GPMC Global configuration
 *
 *  The GPMC_Config structure contains a set of pointers used to characterize
 *  the GPMC driver implementation.
 *
 *  This structure needs to be defined before calling GPMC_init() and it must
 *  not be changed thereafter.
 *
 *  @sa     GPMC_init()
 */
typedef struct GPMC_Config_s {
    /*! Pointer to a table of driver-specific implementations of GPMC APIs */
    GPMC_FxnTable const *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void const          *hwAttrs;
} GPMC_Config;


typedef GPMC_Config GPMC_config_list[GPMC_MAX_CONFIG_CNT];


/*!
 *  @brief  Function to close a GPMC peripheral specified by the GPMC handle
 *
 *  @pre    GPMC_open() has to be called first.
 *
 *  @param  handle A GPMC handle returned from GPMC_open()
 *
 *  @sa     GPMC_open()
 */
extern void GPMC_close(GPMC_Handle handle);


/*!
 *  @brief  This function initializes the GPMC module.
 *
 *  @pre    The GPMC_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other GPMC driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern void GPMC_init(void);

/*!
 *  @brief  This function opens a given GPMC peripheral.
 *
 *  @pre    GPMC controller has been initialized using GPMC_init()
 *
 *  @sa     GPMC_init()
 *  @sa     GPMC_close()
 */
extern GPMC_Handle GPMC_open(uint32_t index, GPMC_Params *params);

/*!
 *  @brief  Function to initialize the GPMC_Params struct to its defaults
 *
 */
extern void GPMC_Params_init(GPMC_Params *params);

/*!
 *  @brief  Function to perform GPMC transactions
 *
 *  @return true if started successfully; else false
 *
 *  @sa     GPMC_open
 *  @sa     GPMC_transferCancel
 */
extern bool GPMC_transfer(GPMC_Handle handle, GPMC_Transaction *transaction);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          GPMC_Handle.
 *
 *  @pre    GPMC_open() has to be called first.
 *
 *  @param  handle      A GPMC handle returned from GPMC_open()
 *
 *  @param  cmd         A command value defined by the driver specific
 *                      implementation
 *
 *  @param  arg         An optional R/W (read/write) argument that is
 *                      accompanied with cmd
 *
 *  @return Implementation specific return codes. Negative values indicate
 *          unsuccessful operations.
 *
 *  @sa     GPMC_open()
 */
extern int32_t GPMC_control(GPMC_Handle handle, uint32_t cmd, void *arg);

#ifdef __cplusplus
}
#endif

#endif /* _GPMC_H */
