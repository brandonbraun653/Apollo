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

/**
 *  \ingroup DRV_SPI_MODULE
 *  \defgroup DRV_SPI_MCSPI_MODULE SPI Driver MCSPI API
 *            Multi-Channel SPI driver interface
 *  @{
 */

/** ============================================================================
 *  @file       MCSPI.h
 *
 *  @brief      Multi-Channel SPI driver interface
 *
 *  The MCSPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/spi/MCSPI.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef MCSPI_H
#define MCSPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/spi/SPI.h>

/*!
 *  @brief    Max number of MCSPI peripheral instances
 */
#define MCSPI_MAX_NUM_INSTANCES     (SPI_MAX_CONFIG_CNT)

/*!
 *  @brief    Max number of channels of a MCSPI peripheral instance
 */
#define MCSPI_MAX_NUM_CHANNELS      (4U)

/*!
 *  @brief      A handle that is returned from a MCSPI_open() call.
 */
typedef struct MCSPI_Config_s      *MCSPI_Handle;

/*!
 *  @brief      The definition of a callback function used by the MCSPI driver
 *              when used in ::SPI_MODE_CALLBACK
 */
typedef void         (*MCSPI_CallbackFxn) (MCSPI_Handle       handle,
                                           SPI_Transaction   *transaction);

/*!
 *  @brief MCSPI Parameters
 *
 *  MCSPI Parameters are used to with the MCSPI_open() call. Default values for
 *  these parameters are set using MCSPI_Params_init().
 *
 *  @sa         MCSPI_Params_init()
 */
typedef struct MCSPI_Params_s {
    SPI_TransferMode    transferMode;       /*!< Blocking or Callback mode */
    uint32_t            transferTimeout;    /*!< Transfer timeout in system
                                                 ticks (Not supported with all
                                                 implementations */
    MCSPI_CallbackFxn   transferCallbackFxn;/*!< Callback function pointer */
    SPI_Mode            mode;               /*!< Master or Slave mode, all the channels on the same
                                                 instance should have the same mode */
    uint32_t            bitRate;            /*!< SPI bit rate in Hz in single channle mode */
    uint32_t            dataSize;           /*!< SPI data frame size in bits in single channle mode */
    SPI_FrameFormat     frameFormat;        /*!< SPI frame format in single channle mode */
    void               *custom;             /*!< Custom argument used by driver
                                                 implementation */

} MCSPI_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MCSPI_close().
 */
typedef void         (*MCSPI_CloseFxn)    (MCSPI_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MCSPI_control().
 */
typedef int32_t      (*MCSPI_ControlFxn)  (MCSPI_Handle handle,
                                           uint32_t     cmd,
                                           const void  *arg);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MCSPI_init().
 */
typedef void         (*MCSPI_InitFxn)     (MCSPI_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MCSPI_open().
 */
typedef MCSPI_Handle (*MCSPI_OpenFxn)     (MCSPI_Handle        handle,
                                           const MCSPI_Params *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MCSPI_transfer().
 */
typedef bool         (*MCSPI_TransferFxn) (MCSPI_Handle     handle,
                                           SPI_Transaction *transaction);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MCSPI_transferCancel().
 */
typedef void         (*MCSPI_TransferCancelFxn) (MCSPI_Handle handle);

/*!
 *  @brief      The definition of a MCSPI function table that contains the
 *              required set of functions to control a specific MCSPI driver
 *              implementation.
 */
typedef struct MCSPI_FxnTable_s {
    /*! Function to close the specified peripheral */
    MCSPI_CloseFxn            closeFxn;

    /*! Function to implementation specific control function */
    MCSPI_ControlFxn          controlFxn;

    /*! Function to initialize the given data object */
    MCSPI_InitFxn             mcspiInitFxn;

    /*! Function to open the specified peripheral */
    MCSPI_OpenFxn             openFxn;

    /*! Function to initiate a MCSPI data transfer */
    MCSPI_TransferFxn         transferFxn;

    /*! Function to cancel MCSPI data transfer */
    MCSPI_TransferCancelFxn   transferCancelFxn;

} MCSPI_FxnTable;

/*!
 *  @brief MCSPI Global configuration
 *
 *  The MCSPI_Config structure contains a set of pointers used to characterize
 *  the MCSPI driver implementation.
 *
 *  This structure needs to be defined before calling MCSPI_init() and it must
 *  not be changed thereafter.
 *
 *  @sa     MCSPI_init()
 */
typedef struct MCSPI_Config_s {
    /*! Pointer to a table of driver-specific implementations of MCSPI APIs */
    MCSPI_FxnTable const *fxnTablePtr;

    /*! Pointer to a SPI instance specific configuration data object */
    SPI_Handle            handle;

    /*! channel number */
    uint32_t              chnNum;

} MCSPI_Config;

typedef MCSPI_Config MCSPI_config_list[MCSPI_MAX_NUM_INSTANCES][MCSPI_MAX_NUM_CHANNELS];

/*!
 *  @brief  Function to close a channel of a SPI peripheral specified by the MCSPI handle
 *
 *  @pre    MCSPI_open() has to be called first.
 *
 *  @param  handle A MCSPI handle returned from MCSPI_open()
 *
 *  @sa     MCSPI_open()
 */
extern void MCSPI_close(MCSPI_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a
 *          channel of a SPI peripheral specified by the MCSPI handle.
 *
 *  @pre    MCSPI_open() has to be called first.
 *
 *  @param  handle      A MCSPI handle returned from MCSPI_open()
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
 *  @sa     MCSPI_open()
 */
extern int32_t MCSPI_control(MCSPI_Handle handle, uint32_t cmd, void *arg);

/*!
 *  @brief  This function initializes the MCSPI module.
 *
 *  @pre    The MCSPI_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other MCSPI driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern void MCSPI_init(void);

/*!
 *  @brief  This function opens a given channel of a given MCSPI peripheral.
 *
 *  @pre    MCSPI controller has been initialized using MCSPI_init()
 *
 *  @param  idx           Logical peripheral number for the MCSPI indexed into
 *                        the MCSPI_config table
 *
 *  @param  channel       Channel number of the SPI peripheral
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values. All the fields in this structure are
 *                        RO (read-only).
 *
 *  @return A MCSPI_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     MCSPI_init()
 *  @sa     MCSPI_close()
 */
extern MCSPI_Handle MCSPI_open(uint32_t idx, uint32_t channel, MCSPI_Params *params);

/*!
 *  @brief  Function to initialize the MCSPI_Params struct to its defaults
 *
 *  @param  params      An pointer to MCSPI_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      transferMode        = SPI_MODE_BLOCKING
 *      transferTimeout     = SPI_WAIT_FOREVER
 *      transferCallbackFxn = NULL
 *      mode                = SPI_MASTER
 *      bitRate             = 1000000 (Hz)
 *      dataSize            = 8 (bits)
 *      frameFormat         = SPI_POL0_PHA0
 */
extern void MCSPI_Params_init(MCSPI_Params *params);

/*!
 *  @brief  Function to perform SPI transactions on a channel of
 *          a SPI peripheral specified by the MCSPI handle.
 *
 *  If the MCSPI is in ::SPI_MASTER mode, it will immediately start the
 *  transaction. If the MCSPI is in ::SPI_SLAVE mode, it prepares itself for a
 *  transaction with a SPI master.
 *
 *  In ::SPI_MODE_BLOCKING, MCSPI_transfer will block task execution until the
 *  transaction has completed.
 *
 *  In ::SPI_MODE_CALLBACK, MCSPI_transfer() does not block task execution and
 *  calls a ::MCSPI_CallbackFxn. This makes the MCSPI_tranfer() safe to be used
 *  within a Task, Swi, or Hwi context. The ::SPI_Transaction structure must
 *  stay persistent until the MCSPI_transfer function has completed!
 *
 *  @param  handle      A MCSPI_Handle
 *
 *  @param  spiTrans    A pointer to a SPI_Transaction. All of the fields within
 *                      transaction except SPI_Transaction.count and
 *                      SPI_Transaction.status are WO (write-only) unless
 *                      otherwise noted in the driver implementations. If a
 *                      transaction timeout has occured, SPI_Transaction.count
 *                      will contain the number of frames that were transferred.
 *
 *  @return true if started successfully; else false
 *
 *  @sa     MCSPI_open
 *  @sa     MCSPI_transferCancel
 */
extern bool MCSPI_transfer(MCSPI_Handle handle, SPI_Transaction *spiTrans);

/*!
 *  @brief  Function to cancel SPI transactions on channel of a
 *          SPI peripheral specified by the MCSPI handle.
 *
 *  In ::SPI_MODE_BLOCKING, MCSPI_transferCancel has no effect.
 *
 *  In ::SPI_MODE_CALLBACK, MCSPI_transferCancel() will stop an MCSPI transfer if
 *  if one is in progress.
 *  If a transaction was in progress, its callback function will be called
 *  in context from which this API is called from. The ::MCSPI_CallbackFxn
 *  function can determine if the transaction was successful or not by reading
 *  the ::SPI_Status status value in the ::SPI_Transaction structure.
 *
 *  @param  handle      A MCSPI_Handle
 *
 *  @sa     MCSPI_open
 *  @sa     MCSPI_transfer
 */
extern void MCSPI_transferCancel(MCSPI_Handle handle);

#ifdef __cplusplus
}
#endif

#endif /* _MCSPI_H */

/* @} */
