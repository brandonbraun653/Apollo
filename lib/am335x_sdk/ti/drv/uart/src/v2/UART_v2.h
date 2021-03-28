/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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
 *  @file       UART_v2.h
 *
 *  @brief      UART driver implementation for a PRU UART FW.
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/uart/UART.h>
 *  #include <ti/drv/uart/soc/UART_soc.h>
 *  @endcode
 *
 *
 *  ============================================================================
 */

#ifndef _UART_V2_H_
#define _UART_V2_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
//#include <ti/csl/cslr_device.h>
#include <ti/csl/cslr_icss.h>
#include <ti/drv/uart/UART.h>
//#include <ti/drv/uart/src/v1/UART_v1.h>
#include <ti/drv/uart/firmware/icss_uart/src/icss_uart.h>
#include <ti/drv/uart/soc/fw_mem_section.h>
//#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/uart/soc/tiuart_pruss_intc_mapping.h>

// PRU UART FW instance IDs
#define UART_INSTANCE_ID0               ( 0U )
#define UART_INSTANCE_ID1               ( 1U )
#define UART_INSTANCE_ID2               ( 2U )
// PRU UART FW maximum number of instance per PRU
#define UART_MAX_INSTANCE_PER_PRU       ( 3U )

// PRU UART FW SoC pinmux macros - AM335x
// input selection mask
#define UART_PRU_GPI_SELECT_MASK        ( 0xFFFFFFF0U ) // AM437x, 0xFFFEFFF0U
// output selection mask
#define UART_PRU_GPO_SELECT_MASK        ( 0xFFFFFFD8U ) // AM437x, 0xFFFBFFF0U
// input pin mux setting:   pull-up enabled, receiver enabled
#define UART_PRU_GPI_INPUT_ENABLE       ( 0x00000030U ) // AM437x, 0x00040000U
// output pin mux setting:  pullup/pulldown disabled, receiver disabled
#define UART_PRU_GPO_OUTPUT_ENABLE      ( 0x00000008U ) // AM437x, 0x00010000U
#define UART_PRU_PINMUX_GPI_MODE        ( 0x00000001U )
#define UART_PRU_PINMUX_GPO_MODE        ( 0x00000002U )

// UART API baud rates supported by PRU UART FW
#define BAUD_RATE_300                   ( 300 )     // 300 baud / sec
#define BAUD_RATE_600                   ( 600 )     // 600 baud / sec
#define BAUD_RATE_1200                  ( 1200 )    // 1200 baud / sec
#define BAUD_RATE_2400                  ( 2400 )    // 2400 baud / sec
#define BAUD_RATE_4800                  ( 4800 )    // 4800 baud / sec
#define BAUD_RATE_9600                  ( 9600 )    // 9600 baud / sec
#define BAUD_RATE_14400                 ( 14400 )   // 14400 baud / sec
#define BAUD_RATE_19200                 ( 19200 )   // 19200 baud / sec
#define BAUD_RATE_28800                 ( 28800 )   // 28800 baud / sec
#define BAUD_RATE_38400                 ( 38400 )   // 38400 baud / sec
#define BAUD_RATE_57600                 ( 57600 )   // 57600 baud / sec
#define BAUD_RATE_115200                ( 115200 )  // 115200 baud /sec
#define UART_NUM_BAUD_RATE              ( 12 )      // number of supported baud rates

#if defined(SOC_AM335x) || defined(SOC_AM335X)
#define UART_ICSS_INTC_SECR0            ( CSL_ICSSM_INTC_SECR0 )    // PRU UART FW, ICSS IEP SECR0 macro
#endif

/* UART function table pointer */
extern const UART_FxnTable UART_v2_FxnTable;

// UART maximum number of ICSS instances
#define UART_MAX_ICSS_INSTANCE          ( 3U )

// UART number of PRU instances per ICSS
#define UART_PRU_INSTANCE_PER_ICSS      ( 2U )

/*!
 *  @brief  UART ICSS instance IDs
 */
typedef enum UART_ICSS_INSTANCE_e {
    /*! Instance 0 */
    UART_ICSS_INSTANCE0 = 0,
    /*! Instance 1 */
    UART_ICSS_INSTANCE1 = 1,
    /*! Instance 2 */
    UART_ICSS_INSTANCE2 = 2,
    /*! Instance 2 */
    UART_ICSS_INSTANCE_NONE = 0xFF
} UART_ICSS_INSTANCE;

/*!
 *  @brief  PRU UART FW Image Memory Pointers
 */
typedef struct UART_ICSS_Mem_Ptr_s {
    /* UART LLD specific objects */
    uint32_t *  dram0MemBufferStart;    /* pointer to DMEM0 memory buffer start for PRU0 */
    uint32_t *  iram0MemBufferStart;    /* pointer to IMEM0 memory buffer start for PRU0 */
    uint32_t *  dram0MemBufferEnd;      /* pointer to DMEM0 memory buffer end for PRU0 */
    uint32_t *  iram0MemBufferEnd;      /* pointer to IMEM0 memory buffer end for PRU0 */
    uint32_t *  dram1MemBufferStart;    /* pointer to DMEM1 memory buffer start for PRU1 */
    uint32_t *  iram1MemBufferStart;    /* pointer to DMEM1 memory buffer start for PRU1 */
    uint32_t *  dram1MemBufferEnd;      /* pointer to DMEM1 memory buffer end for PRU1 */
    uint32_t *  iram1MemBufferEnd;      /* pointer to DMEM1 memory buffer end for PRU1 */

} UART_ICSS_Mem_Ptr;

/*!
 *  @brief      UART PRUICSS IO Pin Mux hardware attributes
 *
 *  UART PRU FW PRU SOC Input/Output pin mux register structure
 */
typedef struct UART_PRU_IOPinMuxAttrs_s {
    uint32_t    baseRegAddr;          /* Control Module Base register */
    uint8_t     pinNum;               /* PRU Pin Number for FW */
    uint8_t     inputModeVal;         /* PRU Pin value for GPI */
    uint8_t     outputModeVal;        /* PRU Pin value for GPO */

} UART_PRU_IOPinMuxAttrs;

/*!
 *  @brief  UART V2 Software (FW) IP attributes
 */
typedef struct UART_SWIPAttrs_s {
    uint32_t                  gCfgAddr;         /* UART global configuration address */
    uint32_t                  baseAddr;         /* UART instance base address */
    uint32_t                  txBuff;           /* UART instance Tx buffer base address */
    uint32_t                  rxBuff;           /* UART instance Rx buffer base address */
    uint32_t                  hostIntNum;       /* UART instance Host interrupt number */
    UART_ICSS_INSTANCE        icssInstId;       /* UART ICSS instance ID */
    PRUSS_PruCores            pruInstId;        /* UART PRU core ID */
    const UART_ICSS_Mem_Ptr * icssMemBuff;      /* Pointer to PRU UART FW ICSS IMEM/DMEM addresses */
    UART_PRU_IOPinMuxAttrs    txPin;            /* UART instance Tx output pin mux register */
    UART_PRU_IOPinMuxAttrs    rxPin;            /* UART instance Rx input pin mux register */
    UART_PRU_IOPinMuxAttrs    ctsPin;           /* UART instance CTS input pin mux register */
    UART_PRU_IOPinMuxAttrs    rtsPin;           /* UART instance RTS output pin mux register */
    uint32_t                  uartInstId;       /* UART instance ID on PRU */
    uint8_t                   txIcssIntcSysEvt; /* UART instance Tx ICSS INTC System Event */
    uint8_t                   rxIcssIntcSysEvt; /* UART instance Rx ICSS INTC System Event */
    bool                      enableIntr;       /* enable interrupts flag */
    bool                      enableHwFcPins;   /* enable hardware flow control pins flag */

} UART_SWIPAttrs;

/**<
 *  @brief  UART V2 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UART_V2_Object_s {
    /* UART control variables */
    UART_Params         params;         /* Configured UART parameters */

    /* UART SYS/BIOS objects */
    void *              hwi;            /* HWI object */
    void *              writeSem;       /* UART write semaphore*/
    void *              readSem;        /* UART read semaphore */

    /* UART write variables */
    const void *        writeBuf;       /* Buffer data pointer */
    size_t              writeCount;     /* Number of Chars sent */
    size_t              writeSize;      /* Chars remaining in buffer */
    uint32_t            writeCR;        /* Write a return character */

    /* UART receive variables */
    void *              readBuf;        /* Buffer data pointer */
    size_t              readCount;      /* Number of Chars read */
    size_t              readSize;       /* Chars remaining in buffer */
    uint32_t            lineStatusErr;  /* Line Status error (framing error, parity error) indication */

    uint32_t            isOpen;         /* flag to indicate module is open */

    UART_Transaction *  readTrans;     /* Pointer to the current read transaction */
    UART_Transaction *  writeTrans;    /* Pointer to the current write transaction */
    
    uint32_t            txDataSent;     /* flag to indicate whether to invoke callback function */

    UART_Transaction    rdTrans;        /* read transaction data */
    UART_Transaction    wrTrans;        /* write transaction data */

} UART_V2_Object;

/**<
 *  @brief  I2C PRU Config Mode
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UART_PRU_funct_mode_s {
    /* UART LLD specific objects */
    uint32_t            instanceCnt;    /* Number of UART FW instances executing on PRU */
    uint32_t            pruGCfgAddr;    /* UART PRU FW global configuration address */
    PRUSS_PruCores      pruInstId;      /* PRU core ID */
    void *              pruInstLock;    /* PRU access (r/w) lock */
    PRUICSS_Handle      pruIcssHandle;  /* PRU ICSS instance handle */
    /* UART FW instance handles */
    uintptr_t           handlePtr[UART_MAX_INSTANCE_PER_PRU];

} UART_PRU_funct_mode;

/**<
 *  @brief  UART ICSS Config Mode
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UART_ICSS_funct_mode_s {
    /* UART LLD specific objects */
    UART_PRU_funct_mode pruMode[UART_PRU_INSTANCE_PER_ICSS]; /* PRU0/1 running mode of ICSS */

} UART_ICSS_funct_mode;

#ifdef __cplusplus
}
#endif


#endif /* _UART_V2_H_ */
