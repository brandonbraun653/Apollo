/*
 * Copyright (c) 2014-2019, Texas Instruments Incorporated
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
 *  \defgroup DRV_UART_MODULE UART Driver
 *
 *  @{
 */
/* @} */

/**
 *  \ingroup DRV_UART_MODULE
 *  \defgroup DRV_UART_API_MODULE UART Driver API
 *            UART driver interface
 *
 *  @{
 */

/** ============================================================================
 *  @file       UART.h
 *
 *  @brief      UART driver interface
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/uart/UART.h>
 *  @endcode
 *
 *  # Operation #
 *  The UART driver simplifies reading and writing to any of the UART
 *  peripherals on the board with multiple modes of operation and performance.
 *  These include blocking, non-blocking, and polling as well as text/binary
 *  mode, echo and return characters. The boards UART peripheral and pins must
 *  be configured before initializing the UART driver. The application
 *  initializes the UART driver by calling UART_init() and is then ready to
 *  open a UART by calling UART_open() and passing in a UART parameters data
 *  structure.
 *
 *  The APIs in this driver serve as an interface to a typical TI-RTOS
 *  application. The specific peripheral implementations are responsible to
 *  create all the OS specific primitives to allow for thread-safe
 *  operation.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  UART_Handle      handle;
 *  UART_Params      params;
 *
 *  UART_Params_init(&params);
 *  params.baudRate  = someNewBaudRate;
 *  params.writeDataMode = UART_DATA_BINARY;
 *  params.readDataMode = UART_DATA_BINARY;
 *  params.readReturnMode = UART_RETURN_FULL;
 *  params.readEcho = UART_ECHO_OFF;
 *  handle = UART_open(someUART_configIndexValue, &params);
 *  if (!handle) {
 *      System_printf("UART did not open");
 *  }
 *  @endcode
 *
 *  ## Writing data #
 *
 *  @code
 *  const unsigned char hello[] = "Hello World\n";
 *
 *  ret = UART_write(handle, hello, sizeof(hello));
 *  System_printf("The UART wrote %d bytes\n", ret);
 *  @endcode
 *
 *  ## Reading data #
 *
 *  @code
 *  unsigned char rxBuffer[20];
 *
 *  ret = UART_read(handle, rxBuffer, sizeof(rxBuffer));
 *  System_printf("The UART read %d bytes\n", ret);
 *  @endcode
 *
 *  # Implementation #
 *
 *  This module serves as the main interface for TI-RTOS
 *  applications. Its purpose is to redirect the module's APIs to specific
 *  peripheral implementations which are specified using a pointer to a
 *  UART_FxnTable.
 *
 *  The UART driver interface module is joined (at link time) to a
 *  NULL-terminated array of UART_Config data structures named *UART_config*.
 *  *UART_config* is implemented in the application with each entry being an
 *  instance of a UART peripheral. Each entry in *UART_config* contains a:
 *  - (UART_FxnTable *) to a set of functions that implement a UART peripheral
 *  - (void *) data object that is associated with the UART_FxnTable
 *  - (void *) hardware attributes that are associated to the UART_FxnTable
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_UART__include
#define ti_drivers_UART__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>


#define UART_SUCCESS ((int32_t)(0))
#define UART_ERROR   (-((int32_t)1))

/*!
 *  @brief      A handle that is returned from a UART_open() call.
 */
typedef struct  UART_Config_s          *UART_Handle;

/*!
 *  @brief      The definition of a callback function used by the UART driver
 *              when used in ::UART_MODE_CALLBACK
 *
 *  @param      UART_Handle             UART_Handle
 *
 *  @param      buf                     Pointer to read/write buffer
 *
 *  @param      count                   Number of elements read/written
 */
typedef void        (*UART_Callback)    (UART_Handle handle, void *buf, size_t count);

/*!
 *  @brief    UART transaction timeout define
 */
#define UART_NO_WAIT       ((uint32_t)0U)
#define UART_WAIT_FOREVER  (~((uint32_t)0U))

/*!
 *  @brief    Transfer API version.
 */
typedef enum UART_TransferApiVer_s {
    UART_TRANSFER_API_VER_1 = 1,
	UART_TRANSFER_API_VER_2 = 2

} UART_TransferApiVer;

/*!
 *  @brief    Transfer status codes that are set by the UART driver.
 */
typedef enum UART_TransferStatus_s {
    UART_TRANSFER_STATUS_SUCCESS = 0,
    UART_TRANSFER_STATUS_TIMEOUT,     /* Time out error */
    UART_TRANSFER_STATUS_ERROR_BI,    /* Break condition error */
    UART_TRANSFER_STATUS_ERROR_FE,    /* Framing error */
    UART_TRANSFER_STATUS_ERROR_PE,    /* Parity error */
    UART_TRANSFER_STATUS_ERROR_OE,    /* Overrun error */
    UART_TRANSFER_STATUS_ERROR_OTH    /* Other error */

} UART_TransferStatus;

/*!
 *  @brief
 *  A ::UART_Transaction data structure is used with UART_read2(),  UART_write2() and UART_Callback2()
 */
typedef struct UART_Transaction_s {
    /* User input (write-only) fields */
    void               *buf;        /**< void * to a buffer with data to be transferred */
    uint32_t            timeout;    /**< Timeout for this transaction */

    /* User input (write-only) and output (read-only) fields */
    uint32_t            count;      /**< Number of bytes for this transaction */

    /* User output (read-only) fields */
    UART_TransferStatus status;     /**< Status code set by UART_read2() and UART_write2() */

    /* Driver-use only fields */
} UART_Transaction;

/*!
 *  @brief      The definition of a callback2 function used by the UART driver
 *              when used in ::UART_MODE_CALLBACK
 *
 *  @param      UART_Handle             UART_Handle
 *
 *  @param  transaction A pointer to a UART_Transaction. All of the fields within
 *                      transaction except UART_Transaction.count and
 *                      UART_Transaction.status are WO (write-only) unless
 *                      otherwise noted in the driver implementations. If a
 *                      transaction timeout or error has occured,
 *                      UART_Transaction.count will contain the number of bytes
 *                      that were transferred.
 */
typedef void        (*UART_Callback2)   (UART_Handle handle, UART_Transaction *transaction);

/*!
 *  @brief      UART mode settings
 *
 *  This enum defines the read and write modes for the
 *  configured UART.
 */
typedef enum UART_Mode_e {
    /*!
      *  Uses a semaphore to block while data is being sent.  Context of the call
      *  must be a Task.
      */
    UART_MODE_BLOCKING,

    /*!
      *  Non-blocking and will return immediately.  When the transfer by the Hwi
      *  is finished the configured callback function is called.
      */
    UART_MODE_CALLBACK,
} UART_Mode;

/*!
 *  @brief      UART return mode settings
 *
 *  This enumeration defines the return modes for UART_read and UART_readPolling.
 *  UART_RETURN_FULL unblocks or performs a callback when the read buffer has
 *  been filled.
 *  UART_RETURN_NEWLINE unblocks or performs a callback whenever a newline
 *  character has been received.
 */
typedef enum UART_ReturnMode_e {
    /*! Unblock/callback when buffer is full. */
    UART_RETURN_FULL,

    /*! Unblock/callback when newline character is received. */
    UART_RETURN_NEWLINE
} UART_ReturnMode;

/*!
 *  @brief      UART data mode settings
 *
 *  This enumeration defines the data mode for read and write.
 *  If the DataMode is text for write, write will add a return before a newline
 *  character.  If the DataMode is text for a read, read will replace a return
 *  with a newline.  This effectively treats all device line endings as LF and
 *  all host PC line endings as CRLF.
 */
typedef enum UART_DataMode_e {
    UART_DATA_BINARY,  /*!< Data is not processed */
    UART_DATA_TEXT     /*!< Data is processed according to above */
} UART_DataMode;

/*!
 *  @brief      UART echo settings
 *
 *  This enumeration defines if the driver will echo data.
 */
typedef enum UART_Echo_e {
    UART_ECHO_OFF = 0,  /*!< Data is not echoed */
    UART_ECHO_ON = 1    /*!< Data is echoed */
} UART_Echo;

/*!
 *  @brief    UART data length settings
 *
 *  This enumeration defines the UART data lengths.
 */

typedef enum UART_LEN_e {
    UART_LEN_5 = 0,        /*!< Data length is 5 */
    UART_LEN_6 = 1,        /*!< Data length is 6 */
    UART_LEN_7 = 2,        /*!< Data length is 7 */
    UART_LEN_8 = 3,        /*!< Data length is 8 */
#ifdef PRU_ICSS_FW  // PRU UART FW SW IP only
    UART_LEN_9 = 4         /*!< Data length is 9 */
#endif
} UART_LEN;

/*!
 *  @brief    UART stop bit settings
 *
 *  This enumeration defines the UART stop bits.
 */
typedef enum UART_STOP_e {
    UART_STOP_ONE = 0,     /*!< One stop bit */
    UART_STOP_TWO = 1,     /*!< Two stop bits */
#ifdef PRU_ICSS_FW  // PRU UART FW SW IP only, currently unsupported by HW IP driver
    UART_STOP_ONEP5 = 2    /*!< One plus one half stop bits */
#endif
} UART_STOP;

/*!
 *  @brief    UART parity type settings
 *
 *  This enumeration defines the UART parity types.
 */
typedef enum UART_PAR_e {
    UART_PAR_NONE = 0,  /*!< No parity */
    UART_PAR_EVEN = 1,  /*!< Parity bit is even */
    UART_PAR_ODD  = 2,  /*!< Parity bit is odd */
    UART_PAR_ZERO = 3,  /*!< Parity bit is always zero */
    UART_PAR_ONE  = 4   /*!< Parity bit is always one */
} UART_PAR;

#ifdef PRU_ICSS_FW // PRU UART FW only
/*!
 *  @brief    UART flow control settings
 *
 *  This enumeration defines the UART parity types.
 */
typedef enum UART_FC_TYPE_e {
    UART_FC_NONE = 0,   /*!< No flow control */
    UART_FC_HW   = 1    /*!< Hardware flow control */
} UART_FC_TYPE;
#endif

/*!
 *  @brief    Basic UART Parameters
 */
typedef struct UART_Params_s {
    UART_Mode       readMode;           /*!< Mode for all read calls */
    UART_Mode       writeMode;          /*!< Mode for all write calls */
    uint32_t        readTimeout;        /*!< Timeout for read semaphore */
    uint32_t        writeTimeout;       /*!< Timeout for write semaphore */
    UART_Callback   readCallback;       /*!< Pointer to read callback */
    UART_Callback   writeCallback;      /*!< Pointer to write callback */
    UART_ReturnMode readReturnMode;     /*!< Receive return mode */
    UART_DataMode   readDataMode;       /*!< Type of data being read */
    UART_DataMode   writeDataMode;      /*!< Type of data being written */
    UART_Echo       readEcho;           /*!< Echo received data back */
    uint32_t        baudRate;           /*!< Baud rate for UART */
    UART_LEN        dataLength;         /*!< Data length for UART */
    UART_STOP       stopBits;           /*!< Stop bits for UART */
    UART_PAR        parityType;         /*!< Parity bit type for UART */
    UART_Callback2  readCallback2;      /**< Pointer to read callback2 */
    UART_Callback2  writeCallback2;     /**< Pointer to write callback2 */
#ifdef PRU_ICSS_FW // PRU UART FW only, currently unsupported by HW IP driver
    UART_FC_TYPE    flowControlType;    /*!< Flow Control type */
    uint8_t         hwFlowControlThr;   /*!< Hardware flow Control threshold, 0-0x100 */
#endif
} UART_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_CloseFxn().
 */
typedef void        (*UART_CloseFxn)          (UART_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_control().
 */
typedef int32_t         (*UART_ControlFxn)        (UART_Handle handle,
                                               uint32_t cmd,
                                               void *arg);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_init().
 */
typedef void        (*UART_InitFxn)           (UART_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_OpenFxn().
 */
typedef UART_Handle (*UART_OpenFxn)           (UART_Handle handle,
                                               const UART_Params *params);
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_ReadFxn().
 */
typedef int32_t     (*UART_ReadFxn)           (UART_Handle handle, void *buffer,
                                               size_t size);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_ReadPollingFxn().
 */
typedef int32_t     (*UART_ReadPollingFxn)    (UART_Handle handle, void *buffer,
                                               size_t size);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_ReadCancelFxn().
 */
typedef void        (*UART_ReadCancelFxn)     (UART_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_CloseFxn().
 */
typedef int32_t     (*UART_WriteFxn)          (UART_Handle handle,
                                               const void *buffer,
                                               size_t size);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_WritePollingFxn().
 */
typedef int32_t     (*UART_WritePollingFxn)   (UART_Handle handle,
                                               const void *buffer,
                                               size_t size);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_WriteCancelFxn().
 */
typedef void        (*UART_WriteCancelFxn)    (UART_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_ReadFxn2().
 */
typedef int32_t     (*UART_ReadFxn2)          (UART_Handle handle,
                                               UART_Transaction *transaction);
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_WriteFxn2().
 */
typedef int32_t     (*UART_WriteFxn2)         (UART_Handle handle,
                                               UART_Transaction *transaction);

/*!
 *  @brief      The definition of a UART function table that contains the
 *              required set of functions to control a specific UART driver
 *              implementation.
 */
typedef struct UART_FxnTable_s {
    /*! Function to close the specified peripheral */
    UART_CloseFxn           closeFxn;
    /*! Function to implementation specific control function */
    UART_ControlFxn         controlFxn;
    /*! Function to initialize the given data object */
    UART_InitFxn            uartInitFxn;
    /*! Function to open the specified peripheral */
    UART_OpenFxn            openFxn;
    /*! Function to read from the specified peripheral */
    UART_ReadFxn            readFxn;
    /*! Function to read via polling from the specified peripheral */
    UART_ReadPollingFxn     readPollingFxn;
    /*! Function to cancel a read from the specified peripheral */
    UART_ReadCancelFxn      readCancelFxn;
    /*! Function to write from the specified peripheral */
    UART_WriteFxn           writeFxn;
    /*! Function to write via polling from the specified peripheral */
    UART_WritePollingFxn    writePollingFxn;
    /*! Function to cancel a write from the specified peripheral */
    UART_WriteCancelFxn     writeCancelFxn;
    /*! Function to read from the specified peripheral */
    UART_ReadFxn2           readFxn2;
    /*! Function to write from the specified peripheral */
    UART_WriteFxn2          writeFxn2;
    
} UART_FxnTable;


/*! @brief UART Global configuration */
typedef struct UART_Config_s {
    /*! Pointer to a table of a driver-specific implementation of UART functions */
    UART_FxnTable const    *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                   *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void          const    *hwAttrs;
} UART_Config;

#define UART_MAX_CONFIG_CNT (14U)  
typedef UART_Config UART_config_list[UART_MAX_CONFIG_CNT];


/*!
 *  @brief  Function to closes a given UART peripheral specified by the UART
 *  handle.
 *
 *  @pre    UART_open() had to be called first.
 *
 *  @param  uartHnd A UART_Handle returned from UART_open
 *
 *  @sa     UART_open
 */
extern void UART_close(UART_Handle uartHnd);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          UART_Handle.
 *
 *  @pre    UART_open() has to be called first.
 *
 *  @param  uartHnd A UART handle returned from UART_open()
 *
 *  @param  cmd     A command value defined by the driver specific implementation
 *
 *  @param  arg     An optional argument that is accompanied with cmd
 *
 *  @return Implementation specific return codes. Negative values indicate
 *          unsuccessful operations.
 *
 *  @sa     UART_open()
 */
extern int32_t UART_control(UART_Handle uartHnd, uint32_t cmd, void *arg);

/*!
 *  @brief  Function to initializes the UART module
 *
 *  @pre    The UART controller needs to be powered up and clocked. The
 *          UART_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other UART driver APIs.
 */
extern void UART_init(void);

/*!
 *  @brief  Function to initialize a given UART peripheral specified by the
 *          particular index value. The parameter specifies which mode the UART
 *          will operate.
 *
 *  @pre    UART controller has been initialized
 *
 *  @param  idx           Logical peripheral number indexed into the HWAttrs
 *                        table
 *
 *  @param  uartParams    Pointer to an parameter block, if NULL it will use
 *                        default values
 *
 *  @return A UART_Handle on success or a NULL on an error or if it has been
 *          already opened
 *
 *  @sa     UART_close
 */
extern UART_Handle UART_open(uint32_t idx, UART_Params *uartParams);

/*!
 *  @brief  Function to initialize the UART_Params struct to its defaults
 *
 *  Defaults values are:
 *  readMode = UART_MODE_BLOCKING;
 *  writeMode = UART_MODE_BLOCKING;
 *  readTimeout = BIOS_WAIT_FOREVER;
 *  writeTimeout = BIOS_WAIT_FOREVER;
 *  readCallback = NULL;
 *  writeCallback = NULL;
 *  readReturnMode = UART_RETURN_NEWLINE;
 *  writeDataMode = UART_DATA_TEXT;
 *  readDataMode = UART_DATA_TEXT;
 *  readEcho = UART_ECHO_ON;
 *  baudRate = 115200;
 *  stopBits = UART_STOP_ONE;
 *  parityType = UART_PAR_NONE;
 *
 *  @param  uartParams  Parameter structure to initialize
 */
extern void UART_Params_init(UART_Params *uartParams);


/*!
 *  @brief  Function that writes data to a UART
 *
 *  This function initiates an operation to write data to a UART controller.
 *
 *  In UART_MODE_BLOCKING, UART_write will block task execution until all
 *  the data in buffer has been written.
 *
 *  In UART_MODE_CALLBACK, UART_write does not block task execution an calls a
 *  callback function specified by writeCallback.
 *
 *  @param  uartHnd     A UART_Handle
 *
 *  @param  buffer      A pointer to buffer containing data to be written
 *
 *  @param  size        The number of bytes in buffer that should be written
 *                      onto the UART.
 *
 *  @return Returns the number of bytes that have been written to the UART,
 *          UART_ERROR on an error.
 */
extern int32_t UART_write(UART_Handle uartHnd, const void *buffer, size_t size);

/*!
 *  @brief  Function that writes data to a UART
 *
 *  This function initiates an operation to write data to a UART controller.
 *
 *  UART_write will not return until all the data was written to the UART.
 *
 *  @param  uartHnd     A UART_Handle
 *
 *  @param  buffer      A pointer to buffer containing data to be written
 *
 *  @param  size        The number of bytes in buffer that should be written
 *                      onto the UART.
 *
 *  @return Returns the number of bytes that have been written to the UART,
 *          UART_ERROR on an error.
 */
extern int32_t UART_writePolling(UART_Handle uartHnd, const void *buffer,
                             size_t size);

/*!
 *  @brief  Function that cancels a UART_write function call.
 *
 *  This function cancels an operation to write data to a UART controller
 *  when in UART_MODE_CALLBACK.
 *
 *  @param  handle      A UART_Handle
 */
extern void UART_writeCancel(UART_Handle handle);

/*!
 *  @brief  Function that read data from a UART
 *
 *  This function initiates an operation to read data from a UART controller.
 *
 *  In UART_MODE_BLOCKING, UART_read will block task execution until all
 *  the data in buffer has been read.
 *
 *  In UART_MODE_CALLBACK, UART_read does not block task execution an calls a
 *  callback function specified by readCallback.
 *
 *  @param  handle      A UART_Handle
 *
 *  @param  buffer      A pointer to an empty buffer in which data should be
 *                      written to
 *
 *  @param  size        The number of bytes to be written into buffer
 *
 *  @return Returns the number of bytes that have been read from the UART,
 *          UART_ERROR on an error.
 */
extern int32_t UART_read(UART_Handle handle, void *buffer, size_t size);

/*!
 *  @brief  Function that reads data from a UART
 *
 *  This function initiates an operation to read data from a UART controller.
 *
 *  UART_readPolling will not return until size data was read to the UART.
 *
 *  @param  handle      A UART_Handle
 *
 *  @param  buffer      A pointer to an empty buffer in which data should be
 *                      written to
 *
 *  @param  size        The number of bytes to be written into buffer
 *
 *  @return Returns the number of bytes that have been read from the UART,
 *          UART_ERROR on an error.
 */
extern int32_t UART_readPolling(UART_Handle handle, void *buffer, size_t size);

/*!
 *  @brief  Function that cancels a UART_read function call.
 *
 *  This function cancels an operation to read data from a UART controller
 *  when in UART_MODE_CALLBACK.
 *
 *  @param  handle      A UART_Handle
 */
extern void UART_readCancel(UART_Handle handle);

/*!
 *  @brief  Extended function that read data from a UART
 *
 *  This function initiates an operation to read data from a UART controller.
 *
 *  In UART_MODE_BLOCKING, UART_read2 will block task execution until all
 *  the data in buffer has been read.
 *
 *  In UART_MODE_CALLBACK, UART_read2 does not block task execution an calls a
 *  callback function specified by readCallback.
 *
 *  @param  handle      A UART_Handle
 *
 *  @param  uartTrans   A pointer to a UART_Transaction. All of the fields within
 *                      transaction except UART_Transaction.count and
 *                      UART_Transaction.status are WO (write-only) unless
 *                      otherwise noted in the driver implementations. If a
 *                      transaction timeout or error has occured,
 *                      UART_Transaction.count will contain the number of bytes
 *                      that were transferred. In the callback mode, the application
 *                      allocates transaction memory and UART driver owns the pointer
 *                      unitil it is returned to the application via the callback
 *                      function, thus the memory should not be allocated on the
 *                      stack, and dynamic free must occur in the callback (not
 *                      immediately after calling read2/write2)
 *
 *  @return Returns UART_SUCCESS or UART_ERROR on an error.
 */
extern int32_t UART_read2(UART_Handle handle, UART_Transaction *uartTrans);

/*!
 *  @brief  Extended function that writes data to a UART
 *
 *  This function initiates an operation to write data to a UART controller.
 *
 *  In UART_MODE_BLOCKING, UART_write will block task execution until all
 *  the data in buffer has been written.
 *
 *  In UART_MODE_CALLBACK, UART_write does not block task execution an calls a
 *  callback function specified by writeCallback.
 *
 *  @param  handle      A UART_Handle
 *
 *  @param  uartTrans   A pointer to a UART_Transaction. All of the fields within
 *                      transaction except UART_Transaction.count and
 *                      UART_Transaction.status are WO (write-only) unless
 *                      otherwise noted in the driver implementations. If a
 *                      transaction timeout or error has occured,
 *                      UART_Transaction.count will contain the number of bytes
 *                      that were transferred. In the callback mode, the application
 *                      allocates transaction memory and UART driver owns the pointer
 *                      unitil it is returned to the application via the callback
 *                      function, thus the memory should not be allocated on the
 *                      stack, and dynamic free must occur in the callback (not
 *                      immediately after calling read2/write2)
 *
 *  @return Returns UART_SUCCESS or UART_ERROR on an error.
 */
extern int32_t UART_write2(UART_Handle handle, UART_Transaction *uartTrans);

/*!
 *  @brief  Function to initialize the UART_Transaction struct to its defaults
 *
 *  @param  uartTrans   A pointer to a UART_Transaction to be initialized. 
 *
 *  @return    uartTrans initialized with default values such as:
 *             uartTrans->buf = NULL;
 *             uartTrans->timeout = UART_WAIT_FOREVER;
 *             uartTrans->count = 0;
 *             uartTrans->status = UART_TRANSFER_STATUS_SUCCESS;
 */
extern void UART_transactionInit(UART_Transaction *uartTrans);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_UART__include */

/* @} */
