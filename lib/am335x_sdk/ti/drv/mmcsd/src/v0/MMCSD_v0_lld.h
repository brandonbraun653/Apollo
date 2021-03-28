/**
 *  \file     MMCSD_v0_lld.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of High Speed MMC/SD controller.
 *            This also contains some related macros, enums and structures.
 *  
 *  \copyright Copyright (C) 2017 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef  MMCSD_V0_LLD_H_
#define  MMCSD_V0_LLD_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/cslr_mmcsd.h>

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */
#define MMCSD_MAX_WORDS_IN_FIFO         16U
/**< MMCSD FIFO size : No of words in FIFO. Current value is for 64 bytes FIFO*/
#define MMCSD_INIT_FREQ_MAX             400000U
/**< The maximum init frequency during card identification                    */
#define MMCSD_INIT_CLOCK                215000U
/**< MMCSD Init clock in Hz(card identification mode should be < 400KHz)      */
#define MMC_CLOCK                       20000000U
/**< MMC clock in Hz during data transfer mode                                */
#define SD_CLOCK                        25000000U
/**< SD clock in Hz during data transfer mode                                 */
#define SD_HIGH_SPEED_CLOCK             50000000U
/**< SD High Speed clock in Hz                                                */
#define MMCSD_TIME_OUT_COUNT            0xFFFFFFU
/**< MMCSD card timeout count                                                 */
#define MMCSD_IO_DEPTH              20U
/**<MMCSD number of tries   >*/
#define MMCSD_NUM_OF_TRIES			0x1000U
/**< Asynchronous IO Depth. Specifies the max number of IOs
 * that can be pending at any time											  */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the controller's interrupt masks. */
typedef enum mmcsdIntrMask
{
    MMCSD_INTR_MASK_DATADONE = CSL_MMCSD_MMCIM_EDATDNE_MASK,
    /**< Data Done interrupt. */
    MMCSD_INTR_MASK_BUSYDONE = CSL_MMCSD_MMCIM_EBSYDNE_MASK,
    /**< Busy done interrupt. */
    MMCSD_INTR_MASK_RSPDONE = CSL_MMCSD_MMCIM_ERSPDNE_MASK,
    /**< Response Done interrupt. */
    MMCSD_INTR_MASK_TOUTRD = CSL_MMCSD_MMCIM_ETOUTRD_MASK,
    /**< Read timeout interrupt. */
    MMCSD_INTR_MASK_TOUTRS = CSL_MMCSD_MMCIM_ETOUTRS_MASK,
    /**< Response timeout interrupt. */
    MMCSD_INTR_MASK_CRCWR = CSL_MMCSD_MMCIM_ECRCWR_MASK,
    /**< Write Data CRC error interrupt. */
    MMCSD_INTR_MASK_CRCRD = CSL_MMCSD_MMCIM_ECRCRD_MASK,
    /**< Read Data CRC error interrupt. */
    MMCSD_INTR_MASK_CRCRS = CSL_MMCSD_MMCIM_ECRCRS_MASK,
    /**< Response Data CRC error interrupt. */
    MMCSD_INTR_MASK_DXRDY = CSL_MMCSD_MMCIM_EDXRDY_MASK,
    /**< Data Transmit Register Ready interrupt. */
    MMCSD_INTR_MASK_DRRDY = CSL_MMCSD_MMCIM_EDRRDY_MASK,
    /**< Data Receive Register Ready interrupt. */
    MMCSD_INTR_MASK_DATED = CSL_MMCSD_MMCIM_EDATED_MASK,
    /**< Edge detect interrupt. */
    MMCSD_INTR_MASK_TRNDNE = CSL_MMCSD_MMCIM_ETRNDNE_MASK,
    /**< Transfer Done interrupt. */
    MMCSD_INTR_MASK_CCS = CSL_MMCSD_MMCIM_ECCS_MASK
    /**< Command completion signal interrupt. */
}mmcsdIntrMask_t;

#define MMCSD_EVENT_ERROR_DATA_CRC  (MMCSD_INTR_MASK_CRCRD |\
										MMCSD_INTR_MASK_CRCWR)

									 
#define MMCSD_EVENT_ERROR       (MMCSD_INTR_MASK_CRCRS | \
									MMCSD_EVENT_ERROR_DATA_CRC | \
									MMCSD_INTR_MASK_TOUTRS     |  \
									MMCSD_INTR_MASK_TOUTRD) 
								
								
/**\brief MMCSD line characteristics                                          */
typedef enum
{
    MMCSD_LINECHR_PUSHPULL  = 0,
    MMCSD_LINECHR_OPENDRAIN = 1
}mmcsdLineChr_t;

/**\brief MMCSD response type                                                 */
typedef enum
{
    MMCSD_RESPTYPE_NO   = 0,
    MMCSD_RESPTYPE_R1   = 1,
    MMCSD_RESPTYPE_R2   = 2,
    MMCSD_RESPTYPE_R3   = 3,
    MMCSD_RESPTYPE_R4   = 4,
    MMCSD_RESPTYPE_R5   = 5,
    MMCSD_RESPTYPE_R6   = 6
}mmcsdRespType_t;

/**\brief MMCSD response Busy                                                 */
typedef enum
{
    MMCSD_RESPBUSY_NO   = 0,
    MMCSD_RESPBUSY_YES  = 1
}mmcsdRespBusy_t;

/**\brief MMCSD command type                                                  */
typedef enum
{
    MMCSD_CMDTYPE_BC    = 0,
    MMCSD_CMDTYPE_BCR   = 1,
    MMCSD_CMDTYPE_AC    = 2,
    MMCSD_CMDTYPE_ADTC  = 3
}mmcsdCmdType_t;

/**\brief MMCSD command direction                                             */
typedef enum
{
    MMCSD_DIR_WRITE     = 0,
    MMCSD_DIR_READ      = 1,
    MMCSD_DIR_DONTCARE  = 2
}mmcsdXferType_t;

/**\brief MMCSD event type*/
typedef enum
{

    MMCSD_EVENT_EOFCMD              = (1 << 2),
    /**< for commands with response, an end of
     * Command + Response; for commands without response,
     * an end of Command                                                      */
    MMCSD_EVENT_READ                = (1 << 10),
    /**< data available with controller for reading                           */

    MMCSD_EVENT_WRITE               = (1 << 9),
    /**< data required by controller for writing                              */

    MMCSD_EVENT_ERROR_CMDCRC        = (1 << 7),
    /**< Error detected in the CRC during commannd
     * - response phase                                                       */

    MMCSD_EVENT_ERROR_DATACRC       = ((1 << 6)|(1 << 5)),
    /**< Error detected in the CRC during data transfer                       */

    MMCSD_EVENT_ERROR_CMDTIMEOUT    = (1 << 4),
    /**< Timeout detected during commannd - response phase                    */

    MMCSD_EVENT_ERROR_DATATIMEOUT   = (1 << 3),
    /**< Timeout detected during data transfer                                */

    MMCSD_EVENT_CARD_EXITBUSY       = (1 << 1),
    /**< Card has exited busy state                                           */

    MMCSD_EVENT_BLOCK_XFERRED       = 1
    /**< block transfer done                                                  */
}mmcsdEvent;

/**
 * \brief Structure for MMCSD command.
 */
typedef struct mmcsdCmd {
    uint32_t cmdId;
    /**< Command ID uses standard MMCSD card commands. */
    uint32_t cmdType;
    /**< Command type uses #mmcsdCmdType_t. */
    uint32_t rspType;
    /**< Response type uses #mmcsdRspType_t. */
    uint32_t xferType;
    /**< Command direction uses #mmcsdXferType_t. */
	uint32_t busy;
	/**< Busy type uses #mmcsdBusyType_t. */
	uint32_t lineChr;
	/**< Line Characteristics uses #mmcsdLineChr_t */
} mmcsdCmd_t;


/** \brief Structure holding the hs mmcsd controller command object. */
typedef struct mmcsdCmdObj
{
    mmcsdCmd_t cmd;
    /**< Command to be passed to the controller/card. */
    uint32_t cmdArg;
    /**< Argument for the command. */
    uint32_t enableData;
    /**< This flag enables/disables data transfer. This can take following
         two values:
         - TRUE  - Enable data transfer
         - FALSE - Disable data transfer. */
    uint32_t numBlks;
    /**< Transfer data length in number of blocks (multiple of BLEN). This can
         take values in the following range:
         1 <= numBlks <= 65535. Value of 0 means Stop count. */
    uint32_t enableDma;
    /**< This flag enables/disables Dma. This can take following two values:
         - TRUE  - Enable DMA.
         - FALSE - Disable DMA. */
}mmcsdCmdObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef MMCSD_V0_LLD_H_ */
