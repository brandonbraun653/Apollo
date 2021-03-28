/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
 /**
 *  \defgroup DRV_MMCSD_MODULE MMCSD Driver
 *
 *  @{
 */
 
 /**
 *  \ingroup DRV_MMCSD_MODULE
 *  \defgroup DRV_MMCSD_API_MODULE MMCSD Driver API
 *            MMCSD driver interface
 *
 *  @{
 */
/** ============================================================================
 *  @file       MMCSD.h
 *
 *  @brief      MMCSD driver interface
 *
 *  The SD header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/mmcsd/MMCSD.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef MMCSD_H
#define MMCSD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/*@{*/

/**
 *  @def  MMCSD_OK
 *        MMCSD return code -- Function executed successfully
 */
#define MMCSD_OK	                             (0)

/**
 *  @def  MMCSD_CMD_RESERVED
 *        MMCSD driver implementations should offset command codes with
 *        MMCSD_CMD_RESERVED growing positively
 */
#define MMCSD_CMD_RESERVED                           (32U)

/**
 *  @def  MMCSD_ERR
 *        MMCSD return code -- Function executed failed
 */
#define MMCSD_ERR                                   (-(1))

/**
 *  @def  MMCSD_UNDEFINEDCMD
 *        MMCSD_control() returns MMCSD_UNDEFINEDCMD if the control code is not
 *        recognized by the driver implementation.
 */
#define MMCSD_UNDEFINEDCMD                          (-(2))


/**
 *  @def  MMCSD_ERR_1P8V_SWITCH_CARD_NOT_RESPONDING
 *        MMCSD_Open() returns this if a 1.8V switch was attempted by the controller
 *        with the consent of the card (S18A=1), but the card stopped responding thereafter.
 */
#define MMCSD_ERR_1P8V_SWITCH_CARD_NOT_RESPONDING   (-(3))

/**
 *  @def  MMCSD_ERR_1P8V_SWITCH_MMCIO_SWITCH_FAILURE
 *        MMCSD_Open() returns this if changing the MMC controller's voltage to 1.8V stopped
 *        the controller working with CMD and DAT lines always powered low. In other words, the 1.8V
 *        switch was not succesful as far as the controller is concerned.
 */
#define MMCSD_ERR_1P8V_SWITCH_MMCIO_SWITCH_FAILURE  (-(4))

/**
 *  @def  MMCSD_ERR_1P8V_SWITCH_CARD_CMD11_FAILURE
 *        MMCSD_Open() returns this if the card indicated that a switch is possible via ACMD41 (S18A=1)
 *        but stopped responding to CMD11. It could be that some cards may not support CMD11 switch eventhough
 *        they advertise it
 */
#define MMCSD_ERR_1P8V_SWITCH_CARD_CMD11_FAILURE    (-(5))

/**
 *  @def  MMCSD_ERR_1P8V_SWITCH_CARD_CMD11_FAILURE
 *        MMCSD_Control(SET_BUS_FREQ) returns this if a switch to a frequency/mode is not supported by the card.
 *        The busFreq should be selected among four types 25MBPS,50MBPS,SDR50/DDR50 (100MBps), SDR104 (200MBPs).
 */
#define MMCSD_ERR_INVALID_FREQ                       (-(6))

/**
 *  @def  MMCSD_ERR_FREQ_SWITCH_UNSUCCESSFUL
 *        MMCSD_Control(SET_BUS_FREQ) returns this if a switch to a frequency switch was attempted but failed.
 */
#define MMCSD_ERR_FREQ_SWITCH_UNSUCCESSFUL           (-(7))

/**
 *  @def  MMCSD_ERR_VOLTAGE_SWITCH_FAILURE
 *        The user defined function MMCSD_voltageSwitchFxn() returns this if a switch to a desired voltage
 *        was attempted but failed.
 */
#define MMCSD_ERR_VOLTAGE_SWITCH_FAILURE             (-(8))

/**
 *  @def  MMCSD_ERR_SET_SOC_INTERRUPT_PATH
 *        Error encountered in setting SOC interrupt path
 *        was attempted but failed.
 */
#define MMCSD_ERR_SET_SOC_INTERRUPT_PATH             (-(9))

/**
 *  @def  MMCSD_ERR_REL_SOC_INTERRUPT_PATH
 *        Error encountered in setting SOC interrupt path
 *        was attempted but failed.
 */
#define MMCSD_ERR_REL_SOC_INTERRUPT_PATH             (-(10))
/**
 *  @def  MMCSD_ERR_REL_SOC_INTERRUPT_PATH
 *        Error encountered in setting SOC interrupt path
 *        was attempted but failed.
 */

#define MMCSD_ERR_TUNING_CMD_ERROR             (-(11))

/*@}*/
/** @} */

/*!
 *  @brief      Return status of MMCSD.
 */
typedef int32_t                MMCSD_Error;

/*!
 *  @brief      A handle that is returned from a MMCSD_open() call.
 */
typedef void                  *MMCSD_Handle;

/*!
 *  @brief      A handle that is returned from a MMCSD_open() call.
 */
typedef void                  *MMCSD_Params;

/*!
 *  @brief  MMCSD callback function
 *
 *  User definable callback function prototype. The MMCSD driver will call the
 *  defined function and pass in the I2C driver's handle, the pointer to the I2C
 *  transaction that just completed, and the return value of I2C_transfer.
 *
 *  @param  MMCSD_Handle          MMCSD_Handle

 *  @param  bool                Results of the I2C transaction
 */
typedef void (*MMCSD_CardDetectCallbackFxn)(MMCSD_Handle handle, uint32_t temp);

/*!
 *  @brief  SD Parameters
 *
 *  SD parameters are used to with the MMCSD_open() call. Default values for
 *  these parameters are set using MMCSD_Params_init().
 *
 *  @sa     MMCSD_Params_init()
 */
typedef struct MMCSD_ConfigParams_s {
    void             *custom;     /*!< Custom argument used by driver
                                       implementation */
    MMCSD_CardDetectCallbackFxn cardDetectCallback; /*! Card detect callback */
} MMCSD_ConfigParams;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_close().
 */
typedef MMCSD_Error (*MMCSD_CloseFxn)    (MMCSD_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
typedef MMCSD_Error (*MMCSD_ControlFxn)  (MMCSD_Handle handle,
                                          uint32_t cmd,
                                          const void *arg);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_init().
 */
typedef MMCSD_Error (*MMCSD_InitFxn)     (MMCSD_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_open().
 */
typedef MMCSD_Error (*MMCSD_OpenFxn) (MMCSD_Handle handle,
                                      MMCSD_Params params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_write().
 */
typedef MMCSD_Error (*MMCSD_WriteFxn) (MMCSD_Handle handle,
                                       uint8_t *buf,
                                       uint32_t block,
                                       uint32_t numBlks);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_read().
 */
typedef MMCSD_Error (*MMCSD_ReadFxn) (MMCSD_Handle handle,
                                      uint8_t *buf,
                                      uint32_t block,
                                      uint32_t numBlks);

/*!
 *  @brief      The definition of a SD function table that contains the
 *              required set of functions to control a specific SD driver
 *              implementation.
 */
typedef struct MMCSD_FxnTable_s {
    /*! Function to close the specified peripheral */
    MMCSD_CloseFxn             closeFxn;

    /*! Function to implementation specific control function */
    MMCSD_ControlFxn           controlFxn;

    /*! Function to initialize the given data object */
    MMCSD_InitFxn              initFxn;

    /*! Function to open the specified peripheral */
    MMCSD_OpenFxn              openFxn;

    /*! Function to initiate a MMC data write */
    MMCSD_WriteFxn             writeFxn;

    /*! Function to initiate a MMC data read */
    MMCSD_ReadFxn              readFxn;
} MMCSD_FxnTable;

/* SD function table pointer */
extern const MMCSD_FxnTable MMCSD_fxnTable;

/*!
 *  @brief  SD Global configuration
 *
 *  The MMCSD_Config structure contains a set of pointers used to characterize
 *  the SD driver implementation.
 *
 *  This structure needs to be defined before calling MMCSD_init() and it must
 *  not be changed thereafter.
 *
 *  @sa     MMCSD_init()
 */
typedef struct MMCSD_Config_s {
    /*! Pointer to a table of driver-specific implementations of SD APIs */
    MMCSD_FxnTable const *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                 *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void           const *hwAttrs;
} MMCSD_Config;

/*!
 *  @brief  Parameters of the media attached to the controller
 *
 *  The MMCSD_mediaParams structure contains the characteristics of the
 *  media (SD/eMMC/MMC) attached to the controller
 *
 */

typedef struct MMCSD_mediaParams_s {
    /*! Size of the block in bytes */
    uint32_t blockSize;
    
    /*! Number of blocks present */
    uint64_t blockCount;

    /*! Size of the media (SD/eMMC/MMC) in bytes */
    uint64_t size;

} MMCSD_mediaParams;


#define MMCSD_MAX_CONFIG_CNT       (5U) 
typedef MMCSD_Config MMCSD_Config_list[MMCSD_MAX_CONFIG_CNT];

extern const MMCSD_Config_list MMCSD_config;

/*!
 *  @brief  Function to close a SD peripheral specified by the SD handle
 *
 *  @pre    MMCSD_open() had to be called first.
 *
 *  @param  handle  A MMCSD_Handle returned from MMCSD_open
 *
 *  @sa     MMCSD_open()
 */
extern MMCSD_Error MMCSD_close(MMCSD_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          MMCSD_Handle.
 *
 *  @pre    MMCSD_open() has to be called first.
 *
 *  @param  handle      A SD handle returned from MMCSD_open()
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
 *  @sa     MMCSD_open()
 */
extern MMCSD_Error MMCSD_control(MMCSD_Handle handle, uint32_t cmd, void *arg);

/*!
 *  @brief  Function to initializes the SD module
 *
 *  @pre    The MMCSD_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other SD driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern MMCSD_Error MMCSD_init(void);

/*!
 *  @brief  Function to initialize a given SD peripheral specified by the
 *          particular index value. The parameter specifies which mode the SD
 *          will operate.
 *
 *  @pre    SD controller has been initialized
 *
 *  @param  index         Logical peripheral number for the SD indexed into
 *                        the MMCSD_config table
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values. All the fields in this structure are
 *                        RO (read-only).
 *  @param  handle        A pointer to the MMCSD_Handle
 *
 *  @return A MMCSD_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     MMCSD_init()
 *  @sa     MMCSD_close()
 */
extern MMCSD_Error MMCSD_open(uint32_t index,
                              MMCSD_Params params,
                              MMCSD_Handle *handle);

/*!
 *  @brief  Function to initialize the MMCSD_Params struct to its defaults
 *
 *  @param  params      An pointer to MMCSD_Params structure for
 *                      initialization
 *
 */
extern MMCSD_Error MMCSD_Params_init(MMCSD_Params params);

/*!
 *  @brief  Function that handles the SD write for SYS/BIOS
 *
 *  @param  handle      A MMCSD_Handle
 *  @param  buf         A pointer to buffer
 *  @param  block       Start block to write.
 *  @param  numBlks     Number of blocks to be read.
 *
 *  @return true on successful write
 *          false on an error, such as a SD bus fault
 *
 *  @sa     MMCSD_open
 */
extern MMCSD_Error MMCSD_write(MMCSD_Handle handle,
                               uint8_t *buf,
                               uint32_t block,
                               uint32_t numBlks);

/*!
 *  @brief  Function that handles the SD read for SYS/BIOS
 *
 *  @param  handle      A MMCSD_Handle
 *  @param  buf         A pointer to buffer
 *  @param  block       Start block to read.
 *  @param  numBlks     Number of blocks to be read.
 *
 *  @return true on successful read
 *          false on an error, such as a SD bus fault
 *
 *  @sa     MMCSD_open
 */
extern MMCSD_Error MMCSD_read(MMCSD_Handle handle,
                              uint8_t *buf,
                              uint32_t block,
                              uint32_t numBlks);

#ifdef __cplusplus
}
#endif

#endif /* _MMCSD_H_ */
/* @} */
