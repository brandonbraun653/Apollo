/**
 *
 * \file    GPMC_v1.h
 *
 * \brief   This file contains the GPMC controller specific struct
 *          definition, macros and function prototypes.
 *
 ******************************************************************************/


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
 *
 */



#ifndef _GPMC_V1_H_
#define _GPMC_V1_H_

#include <ti/csl/src/ip/gpmc/V1/gpmc.h>
#include <ti/csl/src/ip/elm/V0/elm.h>
#include <ti/drv/gpmc/GPMC.h>

/*!
 *  \brief  Get device size (bus width)
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_GETDEVSIZE           (GPMC_CMD_RESERVED + 0U)

/*!
 *  \brief  Get device chip select base address
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_GETDEVADDR           (GPMC_CMD_RESERVED + 1U)

/* Below are NAND device commands */

/*!
 *  \brief  Set NAND command to GPMC controller
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_SETNANDCMD           (GPMC_CMD_RESERVED + 16U)

/*!
 *  \brief  Set NAND address to GPMC controller
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_SETNANDADDR          (GPMC_CMD_RESERVED + 17U)

/*!
 *  \brief  Write NAND DATA to GPMC controller
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_WRNANDDATA           (GPMC_CMD_RESERVED + 18U)

/*!
 *  \brief  Read NAND DATA from GPMC controller
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_RDNANDDATA           (GPMC_CMD_RESERVED + 19U)

/*!
 *  \brief  Get wait pin status from GPMC controller
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_GETWAITPINSTATUS     (GPMC_CMD_RESERVED + 20U)

/*!
 *  \brief  Enable or disable ECC
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ECCCONTROL           (GPMC_CMD_RESERVED + 21U)

/*
 *  \brief  Get ECC configuration information
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ECCGETINFO           (GPMC_CMD_RESERVED + 22U)

/*!
 *  \brief  Read/Write ECC size config
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ECCSETSIZE           (GPMC_CMD_RESERVED + 23U)

/*!
 *  \brief  get ECC result
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ECCGETRESULT         (GPMC_CMD_RESERVED + 24U)

/*!
 *  \brief  Get ECC BCH result
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ECCGETBCHRESULT      (GPMC_CMD_RESERVED + 25U)

/* Error Location Module commands */
/*!
 *  \brief  Sets the fragments of syndrome polynomial for
 *          error-location processing
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ELMSETSYNDFRGMT      (GPMC_CMD_RESERVED + 32U)

/*!
 *  \brief  Start the error-location processing
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ELMSTARTERRLOCPROC   (GPMC_CMD_RESERVED + 33U)

/*!
 *  \brief  Get the ELM interrupt status
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ELMGETINTSTATUS      (GPMC_CMD_RESERVED + 34U)

/*!
 *  \brief  Clear the ELM interrupt status
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ELMCLRINTSTATUS      (GPMC_CMD_RESERVED + 35U)

/*!
 *  \brief  Get the ELM error location processing status
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ELMGETERRLOCPROCSTATUS (GPMC_CMD_RESERVED + 36U)

/*!
 *  \brief  Get the number of errors
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ELMGETNUMERRS        (GPMC_CMD_RESERVED + 37U)

/*!
 *  \brief  Get the ELM error location bit address
 *
 *  Command code used with GPMC_control()
 */
#define GPMC_V1_CMD_ELMGETERRLOCADDR     (GPMC_CMD_RESERVED + 38U)


/*!
 *  \brief  Macro which defines number of the shift bits
 *          of the chip select base address
 */
#define GPMC_CS_BASE_ADDR_SHIFT  (0x18U)

/*!
 *  \brief  Macro which defines the invalid value of the interrupt mux number
 */
#define INVALID_INTC_MUX_NUM     (0xffffU)

/*!
 *  \brief  GPMC operation modes
 */
typedef enum gpmcOperMode_s {
    GPMC_OPER_MODE_BLOCKING,
    GPMC_OPER_MODE_POLLING,
    GPMC_OPER_MODE_CALLBACK
} gpmcOperMode;

/*!
 *  \brief  Nand ECC alogorithm typedef
 */
typedef enum GPMC_v1_nandEccAlgo_s
{
    GPMC_NAND_ECC_ALGO_NONE          = 0x00U,
    GPMC_NAND_ECC_ALGO_HAMMING_1BIT,
    GPMC_NAND_ECC_ALGO_BCH_4BIT,
    GPMC_NAND_ECC_ALGO_BCH_8BIT,
    GPMC_NAND_ECC_ALGO_BCH_16BIT

} GPMC_v1_nandEccAlgo;


/*!
 *  \brief  Structure holding the timing parameters
 */
typedef struct GPMC_v1_timingParams
{
    uint32_t    csOnTime;
    /**< Chip Select assertion time. */
    uint32_t    csRdOffTime;
    /**< Chip Select Read de-assertion time. */
    uint32_t    csWrOffTime;
    /**< Chip Select Write de-assertion time. */
    uint32_t    advOnTime;
    /**< ADV Assertion time. */
    uint32_t    advRdOffTime;
    /**< ADV Read de-assertion time. */
    uint32_t    advWrOffTime;
    /**< ADV Write de-assertion time. */
    uint32_t    advAadMuxOnTime;
    /**< ADV Assertion time in an AADMultiplexed access. */
    uint32_t    advAadMuxRdOffTime;
    /**< ADV Read de-assertion time in an AADMultiplexed access. */
    uint32_t    advAadMuxWrOffTime;
    /**< ADV Write de-assertion time in an AADMultiplexed access. */
    uint32_t    weOnTtime;
    /**< WE assertion time. */
    uint32_t    weOffTime;
    /**< WE de-assertion time. */
    uint32_t    oeOnTime;
    /**< OE assertion time. */
    uint32_t    oeOffTime;
    /**< OE de-assertion time. */
    uint32_t    oeAadMuxOnTime;
    /**< OE assertion time in an AADMultiplexed access. */
    uint32_t    oeAadMuxOffTime;
    /**< OE de-assertion time in an AADMultiplexed access. */
    uint32_t    pageBurstAccess;
    /**< Multiple access word delay. */
    uint32_t    rdAccessTime;
    /**< Start-cycle to first valid delay. */
    uint32_t    wrAcessTime;
    /**< Delay from StartAccessTime to the CLK rising edge. */
    uint32_t    rdCycleTime;
    /**< Total read cycle time. */
    uint32_t    wrCycleTime;
    /**< Total write cycle time. */
    uint32_t    wrDataOnMuxBusTime;
    /**< Write Data on Mux Bus Time. */
    uint32_t    cycle2CycleDelay;
    /**< Chip Select high pulse delay between two successive accesses. */
    uint32_t    cycleDelaySameChipSel;
    /**< Value to control adding of cycle2cycle delay between two successive
         accesses to the same chip select. */
    uint32_t    cycleDelayDiffChipSel;
    /**< Value to control adding of cycle2cycle delay between two successive
         accesses to the different chip select. */
    uint32_t    busTurnAroundTime;
    /**< Bus turn around time between two successive
         accesses to the same chip-select (read to write)
         or to a different chip-select(read to read and read to write)
         in GPMC_FCLK cycles. */
} GPMC_v1_timingParams_t;


/******************************************************************************
*          Structures to be passed to GPMC_soc
******************************************************************************/

/* GPMC function table pointer */
extern const GPMC_FxnTable GPMC_FxnTable_v1;


/*!
 *  @brief  GPMC_v1 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct GPMC_v1_Object_s {
    /* GPMC OS specific objects */
    void                *mutex;              /* instance lock */
    void                *transferComplete;   /*! Transfer complete lock */
    void                *hwi;                /*! Hwi object */
    uint32_t             waitTimeout;        /* Wait time out count */
    GPMC_Params          gpmcParams;         /* input parameters */
    GPMC_TransactionType transType;          /* Read or Write Transaction */
    uint32_t             intrPollMode;       /* Interrupt or polling mode */
    uint8_t             *writeBufIdx;        /* Internal inc. writeBuf index */
    uint32_t             writeCountIdx;      /* Internal dec. writeCounter */
    uint8_t             *readBufIdx;         /* Internal inc. readBuf index */
    uint32_t             readCountIdx;       /* Internal dec. readCounter */
    bool                 isOpen;             /* flag to indicate module is open */

} GPMC_v1_Object;

/*!
 *  @brief  GPMC Hardware attributes
 */
typedef struct GPMC_v1_HwAttrs_s {
    /*! GPMC IP V1 Peripheral base address. */
    uint32_t                gpmcBaseAddr;
    /*! device type, NAND or NOR like */
    uint32_t                devType;
    /*! device size, 8-bit, 16-bit or 32-bit bus width */
    uint32_t                devSize;
    /*! address and data multiplexed protocol */
    uint32_t                addrDataMux;
    /*! Current Active chip select in use by the memory controller */
    uint32_t                timeLatency;
    /*! Signals timing latencies scalar factor */
    uint32_t                chipSel;
    /*! Chip select base address (A29 - A24) */
    uint32_t                chipSelBaseAddr;
    /*! Chip select address mask size */
    uint32_t                chipSelAddrSize;
    /*! GPMC IP V1 Peripheral CorePac interrupt vector */
    uint32_t                intrNum;
    /*! GPMC IP V1 Peripheral CorePac intc event ID */
    uint32_t                eventId;
    /*! interrupt controller mux number.
        K2: CIC number
        AM: Xbar instance number
        -1: reserved for Resource Manager */
    int32_t                 intcMuxNum;
    /*! interrupt controller mux input event ID.
        K2: CIC input event;
        AM: Xbar mux input event;
        -1: reserved for Resource Manager */
    int32_t                 intcMuxInEvent;
    /*! interrupt controller mux output event ID.
        K2: host int num, output int from CIC;
        AM: Xbar input index;
        -1: reserved for Resource Manager */
    int32_t                 intcMuxOutEvent;
    /*! Enable GPMC interrupt. */
    bool                    intrEnable;
    /*! Wait pin Number to which the Ready/Busy pin is connected. */
    uint32_t                waitPinNum;
    /*! Wait pin polarity  */
    uint32_t                waitPinPol;
    /*! Structure holding the timing parameters for the device. */
    GPMC_v1_timingParams_t  timingParams;
    /*! Error Location Module base address for ECC computation. */
    uint32_t                elmBaseAddr;
    /**< ECC algorithm supported by the controller. */
    GPMC_v1_nandEccAlgo     eccAlgo;

} GPMC_v1_HwAttrs;

#endif  // _GPMC_V1_H_
