/*
 * Copyright (c) 2014-2016, Texas Instruments Incorporated
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
 *  @file       MMCSD_v2.h
 *
 *  @brief      MMC driver implementation for a am57x MMC controller.
 *
 *  ============================================================================
 */

#ifndef MMCSD_v2__H
#define MMCSD_v2__H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ti/csl/soc.h>
#include <ti/drv/mmcsd/MMCSD.h>

/** \brief Card bus width configuration for 1-bit mode. */
#define MMCSD_BUS_WIDTH_1BIT            (1U)

/** \brief Card bus width configuration for 4-bit mode. */
#define MMCSD_BUS_WIDTH_4BIT            (4U)

/** \brief Card bus width configuration for 8-bit mode. */
#define MMCSD_BUS_WIDTH_8BIT            (8U)

/** \brief Card bus frequency configuration for 25 Mbps. */
#define MMCSD_TRANSPEED_25MBPS          (0x32U)

/** \brief Card bus frequency configuration for 50 Mbps. */
#define MMCSD_TRANSPEED_50MBPS          (0x5AU)

/** \brief Card bus frequency configuration for 25 Mbps. */
#define MMCSD_TRANSPEED_DEFAULT         (0x32U)

/** \brief Card bus frequency configuration for 50 Mbps. */
#define MMCSD_TRANSPEED_HS              (0x5AU)

/** \brief Card bus frequency configuration for 25 Mbps. */
#define MMCSD_TRANSPEED_SDR12           (0x32U)

/** \brief Card bus frequency configuration for 50 Mbps. */
#define MMCSD_TRANSPEED_SDR25           (0x5AU)

/** \brief Card bus frequency configuration for 100 Mbps. */
#define MMCSD_TRANSPEED_SDR50           (0xBU)

/** \brief Card bus frequency configuration for 200 Mbps. */
#define MMCSD_TRANSPEED_SDR104          (0x2BU)

/** \brief Card bus frequency configuration for 100 Mbps. */
#define MMCSD_TRANSPEED_DDR50           (0x3BU)

/** \brief Card bus frequency configuration for 200 Mbps. */
#define MMCSD_TRANSPEED_HS200           (0x2BU)

/** \brief Card bus frequency configuration for 200 Mbps. */
#define MMCSD_TRANSPEED_HS400           (0x4BU)


/** \brief MMC any loop back. */
#define MMCSD_LOOPBACK_ANY              (0x0U)

/** \brief MMC internal loop back. */
#define MMCSD_LOOPBACK_INTERNAL         (0x1U)

/** \brief MMC pad loop back. */
#define MMCSD_LOOPBACK_PAD              (0x2U)

/** \brief MMC any operating voltage. */
#define MMCSD_VOLTAGE_ANY               (0x0U)

#if defined(SOC_AM65XX)
/* HS400 has been descoped for AM65x */
#define MMCSD_SUPPORT_MMC_HS400_DISABLED 1
#endif

/** \brief MMC 3.3V operating voltage. */
typedef enum {
    MMCSD_BUS_VOLTAGE_1_8V = 0x1U,
	MMCSD_BUS_VOLTAGE_3_0V = 0x2U,
	MMCSD_BUS_VOLTAGE_3_3V = 0x4U
}  MMCSD_BusVoltage_e;

typedef enum {
    MMCSD_SUPPORT_SD_DS = 0x1U, /* DS/SDR12 (if UHS) */
    MMCSD_SUPPORT_SD_HS = 0x2U, /* HS/SDR25 (if UHS) */
    MMCSD_SUPPORT_SD_SDR50 = 0x4U, /* SDR50 (UHS) */
    MMCSD_SUPPORT_SD_DDR50 = 0x8U, /* DDR50 (UHS) */
    MMCSD_SUPPORT_SD_SDR104 = 0x10U, /* SDR104 (UHS) */
    MMCSD_SUPPORT_SD_ALL = 0xFFU, /* All modes */
} MMCSD_SupportedSDModes_e;

typedef enum {
    MMCSD_SUPPORT_MMC_DS = 0x1U, /* DS (Up to 26Mhz) */
    MMCSD_SUPPORT_MMC_HS_SDR = 0x2U, /* HS (Up to 52Mhz) */
    MMCSD_SUPPORT_MMC_HS_DDR = 0x4U, /* HS (Up to 52Mhz) */
    MMCSD_SUPPORT_MMC_HS200 = 0x8U, /* HS200 (Up to 200Mhz) */
    MMCSD_SUPPORT_MMC_HS400 = 0x10U, /* HS400 (Up to 400mhz) */
    MMCSD_SUPPORT_MMC_HS400_ES = 0x20U, /* HS400 Enhanced Strobe (Up to 400mhz) */
    MMCSD_SUPPORT_MMC_ALL   = 0xFFU, /* All modes */
} MMCSD_SupportedMMCModes_e;

/** \brief Determines the type of card is SD. */
#define MMCSD_CARD_SD                   (0U)

/** \brief Determines the type of card is MMC. */
#define MMCSD_CARD_MMC                  (1U)

/** \brief Determines the type of card is MMC. */
#define MMCSD_CARD_EMMC                 (2U)

/** \brief  Set bus width of MMCSD. */
#define MMCSD_CMD_SETBUSWIDTH           (MMCSD_CMD_RESERVED + 0U)

/** \brief  Set bus frequency of MMCSD. */
#define MMCSD_CMD_SETFREQUENCY          (MMCSD_CMD_RESERVED + 1U)

/** \brief  Get bus width of MMCSD. */
#define MMCSD_CMD_GETBUSWIDTH           (MMCSD_CMD_RESERVED + 2U)

/** \brief  Get bus frequency of MMCSD. */
#define MMCSD_CMD_GETFREQUENCY          (MMCSD_CMD_RESERVED + 3U)

/** \brief  Get media (SD/eMMC/MMC) parameters */
#define MMCSD_CMD_GETMEDIAPARAMS        (MMCSD_CMD_RESERVED + 4U)

/** \brief  Set boot partition of eMMC */
#define MMCSD_CMD_ENABLEBOOTPARTITION   (MMCSD_CMD_RESERVED + 5U)
/* MMC function table pointer */
extern const MMCSD_FxnTable MMCSD_v2_FxnTable;

/** \brief  Invalid Mux num */
#define MMCSD_INVALID_MUXNUM            (-1)

/** \brief  Invalid Mux In/Out event num */
#define MMCSD_INVALID_MUX_EVENTNUM      (-1)

/*!
 *  @brief  MMC runtime IO delay configration
 *
 *  This structure defines the parameters for the MMC iodelay configuration.
 */
typedef struct MMCSD_v2_IodelayParams_s {
    uint32_t deviceType;       /*!< MMC device type */
    uint32_t transferSpeed;    /*!< MMC transfer speed */
    uint32_t operatingVoltage; /*!< MMC peripheral operating voltage */
    uint32_t loopBackType;     /*!< MMC peripheral loop back type */
} MMCSD_v2_IodelayParams;

/*!
 *  @brief      A function pointer to configure iodelay.
 */
typedef MMCSD_Error (*MMCSD_v2_iodelayFxn) (uint32_t instanceNum,
                                            MMCSD_v2_IodelayParams *iodelayParams);


/*!
 *  @brief      A function pointer to set the voltage of the MMC I/O Cells and PBAIS to the desired voltage.
 */
typedef MMCSD_Error (*MMCSD_v2_SwitchVoltage) (uint32_t controllerNum, MMCSD_BusVoltage_e voltage);

/*!
 *  @brief      Sets the SOC interrupt path ( aggregators, routers etc) from source to the destination CPU
 */
typedef MMCSD_Error (*MMCSD_v2_socConfigIntrPath) (const void *hwAttrs_ptr,bool setIntrPath);


/*!
 *  @brief      ENUMs to read/configure the input clock to the MMC controller.
 */
typedef enum {
   MMCSD_INPUT_CLOCK_CTRL_GET, /* Returns the input clock to MMC'n' */
   MMCSD_INPUT_CLOCK_CTRL_SET  /* Sets the input clock to MMC'n' as per a value */
} MMCSD_inputClkCtrlMode_e;

/*!
 *  @brief      A function pointer to read/configure the input clock to the MMC controller.
 */
typedef uint32_t (*MMCSD_v2_inputClockControl) (uint32_t instNum, uint32_t *clkFreq,MMCSD_inputClkCtrlMode_e);

/*!
 *  @brief  MMC transaction
 *
 *  This structure defines the nature of the MMC transaction. This structure
 *  specifies the buffer and buffer's size that is to be written to or read from
 *  the MMC slave peripheral.
 */
typedef struct MMCSD_v2_Transaction_s {
    uint32_t cmd;   /*!< Command as per MMC device specification */
    uint32_t flags; /*!< Command flag as per MMC device specification */
    uint32_t arg;   /*!< Command argument as per MMC device specification */

    void    *dataBuf;  /*!< buffer containing data to be read into or written */
    size_t  blockSize; /*!< Number of bytes to be transferred per block */
    size_t  blockCount;  /*!< Number of block to be transferred */

    uint32_t response[4]; /*!< Command response per MMC device specification */
} MMCSD_v2_Transaction;
/*!
 *  @brief  MMC_v2 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct MMCSD_v2_Object_s {
    /* MMCSD OS specific objects */
    void                  *commandMutex;       /*! Grants exclusive access to MMCSD */
    void                  *transferMutex;      /*! Grants exclusive access to MMCSD */
    void                  *commandComplete;    /*! Notify finished MMCSD command */
    void                  *dataBufferCopyComplete; /*! Notify finished dataBuffer Copying */
    void                  *transferComplete;   /*! Notify finished MMCSD transfer */
    void                  *hwi;                /*! Hwi object */
    void                  *writeSem;           /*! MMC write semaphore*/
    void                  *readSem;            /*! MMC read semaphore */

    uint32_t               cardType;    /*! Type of card. */
    uint32_t               rca;         /*! Relative card address. */
    uint32_t               scr[2];      /*! First value of enumeration. Can be used
                                            used for validation. */
    uint32_t               csd[4];      /*! Card specific data. */
    uint8_t                ecsd[512];   /*! eMMC specific data. */
    uint32_t               cid[4];      /*! Card identification register. */
    uint32_t               ocr;         /*! Operation condition register. */
    uint8_t                sdVer;       /*! Version of card. */
    uint8_t                busWidth;    /*! Bus width. */
    uint8_t                tranSpeed;   /*! Transfer speed. */
    uint8_t                highCap;     /*! Is card of high capacity. */
	bool                   cmd23Supported; /*! Does the card support CMD23 */
    bool                   uhsCard;     /*! flag to indicate if the card is UHS */
    uint8_t				   support1_8V; /*! Does card support 1.8V. */
	uint8_t                switched_to_v18; /*! Has the card switched to 1.8V */
    uint32_t               blockSize;   /*! Size of a block. */
    uint64_t               blockCount;  /*! Number of blocks. */
    uint64_t               size;        /*! Size of the card in bytes. */

    MMCSD_ConfigParams     MMCSDConfigParams; /*! Stores MMCSD parameters */

    volatile uint32_t               cmdComp;            /*! Command completion flag */
    volatile uint32_t               cmdTimeout;         /*! Command timeout flag */
    volatile uint32_t               cmdCRCError;         /*! Command CRC error flag */
    volatile uint32_t               cmdEBError;         /*! Command CRC error flag */
    volatile uint32_t               cmdIndexError;         /*! Command Index error flag */
	
    volatile uint32_t               dataCRCError;         /*! Data CRC error flag */
    volatile uint32_t               dataEBError;         /*! Data end bit error */

	volatile uint32_t               cmdError;           /*! Any error in processing of the command */
	
    volatile uint32_t               xferInProgress;     /*! Command completion flag */
    volatile uint32_t               xferComp;           /*! Transfer completion flag */
    volatile uint32_t               xferTimeout;        /*! Transfer timeout flag */

    uint8_t               *dataBufIdx;         /*! Internal inc. dataBuf index */
    uint32_t               dataBlockCount;     /*! Internal dec. blockCounter */
    uint32_t               dataBlockSize;      /*! Internal dec. blockCounter */

    /* SD write variables */
    uint8_t               *writeBufIdx;        /*! Internal inc. dataBuf index */
    uint32_t               writeBlockCount;    /*! Internal dec. blockCounter */

    /* SD read variables */
    uint8_t               *readBufIdx;         /*! Internal inc. dataBuf index */
    uint32_t               readBlockCount;     /*! Internal dec. blockCounter */

    uint32_t               isOpen;             /*! flag to indicate module is open */
    uint32_t               edmaLinkChPhyAddr;
    uint32_t               edmaLinkChId;
    uint32_t               Txtcc;
	bool                   manualTuning;     /*! flag to enable Manual tuning. Disabled by default */
} MMCSD_v2_Object;

typedef enum {
	MMCSD_HW_PHY,
	MMCSD_SW_PHY,
	MMCSD_NO_PHY
} MMCSD_PhyType_e;

typedef enum {
	MMCSD_AUTO_HW_TUNING,  /* Lets the controller tune after setting Enable Tuning bit to 1 and sending tuning pattern (CMD19/21)  */
	MMCSD_MANUAL_SW_TUNING /* Manually set the itap values and send tuning pattern (CMD19/21) */
} MMCSD_TuningType_e;


/*!
 *  @brief  MMCAm57x Hardware attributes
 */
typedef struct MMCSD_v2_HwAttrs_s {
    /*! MMC Peripheral instance number */
    uint32_t            instNum;
    /*! MMC Peripheral base address */
    uintptr_t            baseAddr;
    /*! MMC Secondary Subsystem address */
    uintptr_t            ssBaseAddr;

    /*! MMC Peripheral phy address  */
    uintptr_t            phyBaseAddr;

    /*! MMC Peripheral interrupt vector */
    uint32_t            intNum;
    /*! MMC Peripheral interrupt vector */
    uint32_t            eventId;
    /*! MMC input functional clock */
    uint32_t            inputClk;
    /*! MMC output clock */
    uint32_t            outputClk;
    /*! Type of card. */
    uint32_t            cardType;
    /*! Supported bus width */
    uint32_t            supportedBusWidth;

    /*! Supported bus voltage */
    uint32_t            supportedBusVoltages;

    /*! Is high speed supported */
    uint32_t            isHighSpeed;
    /*! MMC enable interrupt */
    uint32_t            enableInterrupt;
    /*! MMC iodelay configuration */
    MMCSD_v2_iodelayFxn iodelayFxn;
    /*! MMC Voltage Switch function */
    MMCSD_v2_SwitchVoltage switchVoltageFxn;
    /*! MMC input clock control function */
    MMCSD_v2_inputClockControl inputClockControl;
    uint32_t            enableDma;
   /*EDMA related Hardware configuration details*/
    /*! EDMA event number of Receiver*/
    uint32_t          rxDmaEventNumber;
    /*! EDMA event number of Transmitter*/
    uint32_t          txDmaEventNumber;
    /*! EDMA Transfer Controller No.of TX channel*/
    uint32_t          edmaTxTCC;
    /*! EDMA Transfer Controller No.of Rx channel*/
    uint32_t          edmaRxTCC;
    /*! EDMA Transfer Controller No.of TX channel*/
    uint32_t          edmaTxTC;
    /*! EDMA Transfer Controller No.of Rx channel*/
    uint32_t          edmaRxTC;
    uint32_t          version;
    void*             edmaHandle;
    /*!  Mux for IRQ routing. Set to MMCSD_INVALID_MUXNUM if not applicable */
    int32_t           muxNum;
    /* 
	   For Keystone C66, this represents the input event to CIC
       For AM/DRAx devices, this represents the event number input to the crossbar
       Set to MMCSD_INVALID_MUX_EVENTNUM if this is invalid to the SOC
     */
    int32_t           muxInEvent;
    /* 
	   For Keystone C66, this represents the output event to CIC 
       For AM/DRAx devices, this represents the crossbar instance number
       Set to MMCSD_INVALID_MUX_EVENTNUM if this is invalid to the SOC
     */
    int32_t           muxOutEvent;
    /* Supported Rates. This is to limit the SD/eMMC cards to the rates 
     * enabled in the bitmask below. Normally, during bootup, the card will switch to
     * the highest possible rate for best throughput. The below limits it 
     * and can be used for testing purposes */
     
     uint32_t supportedModes;
    
     MMCSD_v2_socConfigIntrPath configSocIntrPath;
     MMCSD_PhyType_e phyType; /* HW/SW phy */
     MMCSD_TuningType_e tuningType; /*! This selects manual SW tuning or auto HW tuning for SDR104/HS200/HS400 modes  */ 
} MMCSD_v2_HwAttrs;


/* ISR function */
void MMCSD_v2_hwiFxn(uintptr_t arg);
/* SOC APIs to configure/reconfigure HwAttrs before MMCSD_init() */
extern int32_t MMCSD_socGetInitCfg(uint32_t index, MMCSD_v2_HwAttrs *cfg);
extern int32_t MMCSD_socSetInitCfg(uint32_t index, const MMCSD_v2_HwAttrs *cfg);
extern MMCSD_Error MMCSD_configSocIntrPath(const void *hwAttrs_ptr, bool setIntrPath);
extern MMCSD_v2_HwAttrs MMCSDInitCfg[];
extern MMCSD_v2_Object MMCSDObjects[];

MMCSD_Error MMCSD_socPhyInit(MMCSD_v2_HwAttrs const *hwAttrs);
MMCSD_Error MMCSD_socPhyDisableDLL(MMCSD_v2_HwAttrs const *hwAttrs);
MMCSD_Error MMCSD_socPhyConfigure(MMCSD_v2_HwAttrs const *hwAttrs,uint32_t phyMod, uint32_t phy_clk_freq, uint32_t phyDriverType);

/* Manual tuning functions */
MMCSD_Error mmcsd_tuning_procedure_SD_manual(MMCSD_Handle handle);
MMCSD_Error mmcsd_tuning_procedure_EMMC_manual(MMCSD_Handle handle);

/* Core tuning functions */
uint32_t mmcsd_send_tuning_eMMC(MMCSD_Handle handle);
uint32_t mmcsd_send_tuning(MMCSD_Handle handle);
#ifdef __cplusplus
}
#endif


#endif /* _MMCSD_v2_H */
