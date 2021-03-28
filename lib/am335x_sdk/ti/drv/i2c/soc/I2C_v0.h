/*
 * Copyright (c) 2015 - 2016, Texas Instruments Incorporated
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
 *  @file       I2C_v0.h
 *
 *  @brief      I2C driver implementation for I2C IP V0 controller.
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

#ifndef I2C_V0_H
#define I2C_V0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_device_interrupt.h>
#include <ti/drv/i2c/I2C.h>

/* I2C function table pointer */
extern const I2C_FxnTable I2C_v0_FxnTable;

/*!
 *  @brief  I2C IP V0 Hardware attributes
 */
typedef struct I2C_HwAttrs_s {
    /*! I2C Peripheral base address */
    uint32_t baseAddr;
    /*! I2C Peripheral interrupt vector */
    uint32_t intNum;
    /*! I2C Peripheral CorePac intc event ID */
    uint32_t eventId;
    /* intc mux number, Keystone inc mux is Chip Interrupt Controller
       if assigned -1, system resource manager will decide the mux num */
    int32_t intcMuxNum;
    /* intc mux input event ID, for Keystone, it is the input event to CIC
       if assigned -1, system resource manager will decide the mux input event ID */
    int32_t intcMuxInEvent;
    /* intc mux output event ID, for Keystone, it is the Host interrupt num
       if assigned -1, system resource manager will decide the mux output event ID */
    int32_t intcMuxOutEvent;
    /*! I2C input functional clock */
    uint32_t funcClk;
    /*! enable Interrupt */
    bool     enableIntr;
    /**< I2C own slave addresses */
    uint32_t ownSlaveAddr;

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

/*!
 *  @brief  I2C IP V0 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct I2C_v0_Object_s {
    /* I2C OS specific objects */
    void*               mutex;              /* Grants exclusive access to I2C */
    void*               transferComplete;   /* Notify finished I2C transfer */
    void*               hwi;                /* Hwi object */
    int32_t             waitTimeout;        /* Waiting time out */

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
    I2C_Transaction    *headPtr;            /* Head ptr for queued transactions */
    I2C_Transaction    *tailPtr;            /* Tail ptr for queued transactions */

    bool                isOpen;             /* flag to indicate module is open */
    uint32_t            intStatusErr;       /* interrupt status error */

} I2C_v0_Object;

/* Invalid Intc Mux number, intc Mux not used if assigned INVALID_INTC_MUX_NUM */
#define INVALID_INTC_MUX_NUM      0xffff

#ifdef __cplusplus
}
#endif

#endif /* I2C_V0_H */
