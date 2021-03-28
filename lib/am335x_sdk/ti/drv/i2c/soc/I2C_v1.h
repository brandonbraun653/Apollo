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
/** ============================================================================
 *  @file       I2C_v1.h
 *
 *  @brief      I2C driver implementation for a am57x I2C controller.
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

#ifndef I2C__V1_H
#define I2C__V1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drv/i2c/I2C.h>

#define I2C_MAX_NUM_OWN_SLAVE_ADDR    (4U)

/* I2C function table pointer */
extern const I2C_FxnTable I2C_v1_FxnTable;

/*!
 *  @brief Function to set interrupt path
 *
 *  This function will configure the interrupt path to the destination CPU
*   using DMSC firmware via sciclient. if setIntrPath is set to TRUE,
*   a path is set, else the interrupt path is released
 */
typedef int32_t (*I2C_socCfgIntrPathFxn)(const void *pHwAttrs, bool setIntrPath);

/*!
 *  @brief  I2C V1 Hardware attributes
 */
typedef struct I2C_HwAttrs_s {
    /*! I2C Peripheral base address */
    uint32_t baseAddr;
    /*! I2C Peripheral interrupt vector */
    uint32_t intNum;
    /*! I2C Peripheral interrupt vector */
    uint32_t eventId;
    /*! I2C input functional clock */
    uint32_t funcClk;
    /*! enable Interrupt */
    bool enableIntr;
    /**< I2C own slave addresses for multi-slave channels,
         if only one slave channel is supported, set the
         slave address to ownSlaveAddr[0] */
    uint32_t ownSlaveAddr[I2C_MAX_NUM_OWN_SLAVE_ADDR];
    /*! Function pointer to set interrupt router path */
    I2C_socCfgIntrPathFxn configSocIntrPath;
} I2C_HwAttrs;

/*!
 *  @brief  I2C operating modes
 */
typedef enum I2C_operMode_e {
    /*! Interrupt blocking mode */
    I2C_OPER_MODE_BLOCKING,
    /*! Interrupt callback mode */
    I2C_OPER_MODE_CALLBACK,
    /*! Polling based blocking mode */
    I2C_OPER_MODE_POLLING
} I2C_operMode;

/*!
 *  @brief  I2C mode
 *
 *  This enum defines the state of the I2C driver's state-machine. Do not
 *  modify.
 */
typedef enum I2C_Mode_e {
    I2C_IDLE_MODE = 0,          /* I2C is not performing a transaction */
    I2C_WRITE_MODE = 1,         /* I2C is currently performing write operations */
    I2C_READ_MODE = 2,          /* I2C is currently performing read operations */
    I2C_SLAVE_XFER_MODE = 3,    /* I2C is trasferring in slave mode */
    I2C_SLAVE_RESTART_MODE = 4, /* I2C is restarting trasfer in slave mode */
    I2C_ERROR = 0xFF            /* I2C error has occurred, exit gracefully */
} I2C_Mode;

/**<
 *  @brief  I2C V1 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct I2C_v1_Object_s {
    /* I2C OS specific objects */
    void*    mutex;              /* Grants exclusive access to I2C */
    void*    transferComplete;   /* Notify finished I2C transfer */
    void*    hwi;                /* Hwi object */
    int32_t      waitTimeout;        /* Waiting time out */

    I2C_Params          i2cParams;          /* Stores I2C parameters */

    I2C_Mode            mode;               /* Stores the I2C state */
    I2C_operMode        operMode;           /* Operational mode */

    /* I2C transaction variables */
    I2C_Transaction    *currentTransaction; /* Pointer to current I2C
                                               transaction */
    uint8_t            *writeBufIdx;        /* Internal inc. writeBuf index */
    uint32_t            writeCountIdx;      /* Internal dec. writeCounter */
    uint8_t            *readBufIdx;         /* Internal inc. readBuf index */
    uint32_t            readCountIdx;       /* Internal dec. readCounter */

    /* I2C transaction pointers for I2C_MODE_CALLBACK */
    I2C_Transaction    *headPtr;        /* Head ptr for queued transactions */
    I2C_Transaction    *tailPtr;        /* Tail ptr for queued transactions */

    bool                isOpen;         /* flag to indicate module is open */
    uint32_t            intStatusErr;   /* interrupt status error */

} I2C_v1_Object;

#ifdef __cplusplus
}
#endif

#endif /* _I2C_V1_H */
