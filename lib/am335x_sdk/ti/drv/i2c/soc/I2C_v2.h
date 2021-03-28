/*
 * Copyright (c) 2014-2018, Texas Instruments Incorporated
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
 *  @file       I2C_v2.h
 *
 *  @brief      I2C driver implementation for a PRU I2C FW.
 *
 *  The I2C header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/i2c/I2C.h>
 *  #include <ti/drv/i2c/soc/I2C_soc.h>
 *  @endcode
 *
 *
 *  ============================================================================
 */

#ifndef I2C__V2_H
#define I2C__V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/cslr_icss.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_v1.h>
#include <ti/drv/i2c/firmware/icss_i2c/src/icss_i2c.h>
#include <ti/drv/i2c/soc/fw_mem_section.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/i2c/soc/tii2c_pruss_intc_mapping.h>

#define I2C_INSTANCE_ID0              (0U)
#define I2C_INSTANCE_ID1              (1U)
#define I2C_INSTANCE_ID2              (2U)
#define I2C_INSTANCE_ID3              (3U)

#define MAX_ICSS_INSTANCE             (3U)

#define	I2C_PRU_PINMUX_GPI_MODE      (0x00000001U)
#define	I2C_PRU_PINMUX_GPO_MODE      (0x00000002U)

// PRU UART FW SoC pinmux macros
#if defined(SOC_AM335x) || defined(SOC_AM335X)
#define	I2C_PRU_GPI_INPUT_ENABLE     (0x00000020U)
#define	I2C_PRU_GPI_SELECT_MASK      (0xFFFFFFF0U)
#define	I2C_PRU_GPO_PULLUP_DISABLE   (0x00000008U)
#define	I2C_PRU_GPO_SELECT_MASK      (0xFFFFFFD8U)

#elif defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_AM437x) || defined(SOC_AM437X)
#define	I2C_PRU_GPI_INPUT_ENABLE     (0x00040000U)
#define	I2C_PRU_GPI_SELECT_MASK      (0xFFFEFFF0U)
#define	I2C_PRU_GPO_PULLUP_DISABLE   (0x00010000U)
#define	I2C_PRU_GPO_SELECT_MASK      (0xFFFBFFF0U)

#endif

#if defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_AM571x) || defined(SOC_K2G)
#define I2C_ICSS_INTC_SECR0            (CSL_ICSSINTC_SECR0)
#elif defined(SOC_AM335x) || defined(SOC_AM437x)
#define I2C_ICSS_INTC_SECR0            (CSL_ICSSM_INTC_SECR0)
#endif

/* I2C function table pointer */
extern const I2C_FxnTable I2C_v2_FxnTable;

/*!
 *  @brief  I2C operating modes
 */
typedef enum I2C_ICSS_INSTANCE_e {
    /*! Instance 0 */
    I2C_ICSS_INSTANCE0 = 0,
    /*! Instance 1 */
    I2C_ICSS_INSTANCE1 = 1,
    /*! Instance 2 */
    I2C_ICSS_INSTANCE2 = 2,
    /*! Instance 2 */
    I2C_ICSS_INSTANCE_NONE = 0xFF
} I2C_ICSS_INSTANCE;

/*!
 *  @brief  I2C FW Image Memory Ptr
 */
typedef struct ICSS_Mem_Ptr_s {
    /* I2C LLD specific objects */
    uint32_t*           dram0MemBufferStart;       /* pointer to .data memory buffer for PRU0 */
    uint32_t*           iram0MemBufferStart;       /* pointer to .data memory buffer for PRU0 */
    uint32_t*           dram0MemBufferEnd;       /* pointer to .data memory buffer for PRU0 */
    uint32_t*           iram0MemBufferEnd;       /* pointer to .data memory buffer for PRU0 */
    uint32_t*           dram1MemBufferStart;       /* pointer to .data memory buffer for PRU1 */
    uint32_t*           iram1MemBufferStart;       /* pointer to .data memory buffer for PRU1 */
    uint32_t*           dram1MemBufferEnd;       /* pointer to .data memory buffer for PRU1 */
    uint32_t*           iram1MemBufferEnd;       /* pointer to .data memory buffer for PRU1 */

} ICSS_Mem_Ptr;


/*!
 *  @brief      PRUICSS IO Pin Mux hardware attributes
 *
 *  I2C PRU SOC Input/Output pin mux register structure
 */
typedef struct I2C_PRU_IOPinMuxAttrs_s {
    uint32_t    baseRegAddr;          /* Control Module Base register */
    uint8_t     pinNum;               /* PRU Pin Number for FW */
    uint8_t     inputModeVal;         /* PRU Pin value for GPI */
    uint8_t     outputModeVal;        /* PRU Pin value for GPO */

} I2C_PRU_IOPinMuxAttrs;

/*!
 *  @brief  I2C Fifo sizes
 */
typedef enum I2C_TrigLvl_e {
    I2C_TRIGLVL_8 = 1,         /**< Trigger Level 8    */
    I2C_TRIGLVL_16 = 2,       /**< Trigger Level 16   */
    I2C_TRIGLVL_32 = 4,       /**< Trigger Level 32   */
    I2C_TRIGLVL_64 = 8,       /**< Trigger Level 64   */
    I2C_TRIGLVL_128 = 16,     /**< Trigger Level 128   */
    I2C_TRIGLVL_256 = 32,     /**< Trigger Level 256   */

} I2C_TrigLvl;

/*!
 *  @brief  I2C V2 Hardware attributes
 */
typedef struct I2C_SwIPAttrs_s {
    uint32_t                 baseAddr;                /*! I2C Peripheral base address */
    uint32_t                 configAddr;              /*! I2C Peripheral configuration address */
    uint32_t                 intNum;                  /*! I2C Peripheral interrupt vector id */
#if defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x)
    uint32_t                 HostXbarNumber;          /*! I2C Peripheral Host cross bar output id */
    CSL_XbarIrq              PRUXbarNumber;           /*! I2C Peripheral PRU cross bar input id */
#endif
    uint32_t                 eventId;                 /*! I2C Peripheral interrupt input id only for C66 */
    I2C_ICSS_INSTANCE        icssInstance;            /*! I2C working ICSS Instance number */
    PRUSS_PruCores           pruInstance;             /*! I2C working PRU Instance number */
#if defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x)
    CSL_XbarIrqCpuId         cpuId;                   /*! I2C HOST Core CPU id */
#endif
    const ICSS_Mem_Ptr      *icssMemBuffer;           /*! Handle to PRU Instance */
    I2C_PRU_IOPinMuxAttrs    sclOutputPin;            /*! I2C output pin mux register for writing SCL */
    I2C_PRU_IOPinMuxAttrs    sdaOutputPin;            /*! I2C output pin mux register for writing SDA */
    I2C_PRU_IOPinMuxAttrs    sdaInputPin;             /*! I2C input pin mux register for reading SDA */
    I2C_TrigLvl              rxFifoSize;              /*! I2C rx fifo buffer size level */
    I2C_TrigLvl              txFifoSize;              /*! I2C tx fifo buffer size level */
    uint32_t                 i2cInstId;
    bool                     enableIntr;              /*! enable Interrupt */

} I2C_SwIPAttrs;

/*!
 *  @brief  I2C mode
 *
 *  This enum defines the state of the I2C driver's state-machine. Do not
 *  modify.
 */
typedef enum I2C_ConfigMode_e {
    I2C_ICSS_NO_CONFIG = 0,          /* I2C is not performing a transaction */
    I2C_ICSS_1MHZ_MODE = 1,          /* I2C is currently configured for 1 MHz mode */
    I2C_ICSS_400KHZ_MODE = 2,        /* I2C is currently configured for 400 KHz mode */
    I2C_ICSS_100KHZ_MODE = 3,        /* I2C is currently configured for 100 KHz mode */
    I2C_ICSS_ERROR = 0xFF                 /* I2C error has occurred, exit gracefully */
} I2C_ConfigMode;

/*!
 *  @brief  I2C CMD 
 *
 *  This are the smbus command for smbus operation
 */
typedef enum I2C_TransferCmd_e {
    STANDARD_I2C_CMD,                /* Standard I2C read and write transaction */
    STANDARD_LOOPBACK_CMD,           /* Loopback command for driver verification */
    SMBUS_QUICK_CMD,                 /* SMBUS quick cmd for I2C instance */
    SMBUS_SEND_BYTE_CMD,             /* SMBUS send byte cmd for I2C instance */
    SMBUS_RECEIVE_BYTE_CMD,          /* SMBUS recieve byte cmd for I2C instance */
    SMBUS_WRITE_BYTE_CMD,            /* SMBUS write byte cmd for I2C instance */
    SMBUS_READ_BYTE_CMD,             /* SMBUS read byte cmd for I2C instance */
    SMBUS_WRITE_WORD_CMD,            /* SMBUS write word cmd for I2C instance */
    SMBUS_READ_WORD_CMD,             /* SMBUS read word for I2C instance */
    SMBUS_BLOCK_WRITE_CMD,           /* SMBUS block write for I2C instance */
    SMBUS_BLOCK_READ_CMD             /* SMBUS block read for I2C instance */
} I2C_TransferCmd;

/**<
 *  @brief  I2C transaction Command
 *
 *  This structure defines the nature of the I2C transaction Command.
 *
 *  I2C SMBUS mode:
 *  This structure specifies the SMBUS command and the sub command
 *  code required with the command.
 */
typedef struct I2C_TransactionCmd_s {
    I2C_TransferCmd     transferCmd;        /*!< This is to indicate whether transaction is normal i2c read/write 
                                                 command or special SMBUS command */
    uint8_t             cmdCode;            /*!< This is used for SMBUS subcommand field */
} I2C_TransactionCmd;

/**<
 *  @brief  I2C V2 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct I2C_v2_Object_s {
    /* I2C OS specific objects */
    void*               mutex;              /* Grants exclusive access to I2C */
    void*               hwi;                /* Hwi object */

    I2C_Params          i2cParams;          /* Stores I2C parameters */

    I2C_Mode            mode;               /* Stores the I2C state */
    I2C_operMode        operMode;           /* Operational mode */
    I2C_ConfigMode      configMode;         /* Current config mode of instance */
    
    void*               cmdAckSem;          /* Hwi object */
    uint32_t            currentCmd;         /* stores the current command being passed */

    /* I2C transaction variables */
    I2C_Transaction    *currentTransaction; /* Pointer to current I2C transaction */
    uint8_t            *writeBufIdx;        /* Internal inc. writeBuf index */
    uint32_t            writeCountIdx;      /* Internal dec. writeCounter */
    uint8_t            *readBufIdx;         /* Internal inc. readBuf index */
    uint32_t            readCountIdx;       /* Internal dec. readCounter */
    I2C_TransactionCmd  transactionCmd;     /* for transferring SMBUS command and code */

    /* I2C transaction pointers for I2C_MODE_CALLBACK */
    I2C_Transaction    *headPtr;            /* Head ptr for queued transactions */
    I2C_Transaction    *tailPtr;            /* Tail ptr for queued transactions */

    bool                isOpen;             /* flag to indicate module is open */
    uint32_t            intStatusErr;       /* interrupt status error */

} I2C_v2_Object;

/**<
 *  @brief  I2C PRU Config Mode
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PRU_funct_mode_s {
    /* I2C LLD specific objects */
    I2C_ConfigMode      pruConfig;         /* PRU Running configuration */
    uint32_t            instanceCnt;       /* Number of I2C instance running */
    uint32_t            pruConfigAddr;     /* Configuration address for the particular PRU */
    PRUSS_PruCores      pruInstance;       /*! I2C working PRU Instance number */
    void               *pruInstLock;
    PRUICSS_Handle      pruIcssHandle;     /* Handle to PRU Instance*/
    uintptr_t           handlePtr[4];      /* Pointers to max 4 handle which PRU can support*/

} PRU_funct_mode;

/**<
 *  @brief  I2C ICSS Config Mode
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct ICSS_funct_mode_s {
    /* I2C LLD specific objects */
    PRU_funct_mode      pruMode[2];       /* PRU0/1 running mode of ICSS */

} ICSS_funct_mode;

#ifdef __cplusplus
}
#endif

#endif /* _I2C_V2_H */

