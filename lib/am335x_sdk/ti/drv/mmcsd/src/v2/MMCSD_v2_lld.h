/**
 *  \file     hs_mmcsd.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of High Speed MMC/SD controller.
 *            This also contains some related macros, enums and structures.
 *
 *  \details  programming sequence of MMC/SD controller is:
 *            -# Perform soft reset using the API #HSMMCSDSoftReset.
 *            -# Perform reset of all the lines MMC/SD controller using the
 *               API #HSMMCSDLinesReset.
 *            -# Set the supported voltages using the API
 *               #HSMMCSDSetSupportedVoltage.
 *            -# Perform the MMC/SD controller's system configuration using the
 *               API #HSMMCSDSystemConfig.
 *            -# Set the controller's bus width using the API
 *               #HSMMCSDSetBusWidth.
 *            -# Set the bus voltage using the API #HSMMCSDSetBusVolt.
 *            -# Power on the controller's bus using the API
 *               #HSMMCSDBusPowerOnCtrl. The second parameter should be passed
 *               is HS_MMCSD_PWR_CTRL_ON.
 *            -# Set the bus frequency using the API #HSMMCSDSetBusFreq.
 *            -# Send the initialization stream using the API
 *               #HSMMCSDInitStreamSend.
 *            -# Enable the required interrupts of the controller using the
 *               API #HSMMCSDIntrEnable.
 *
 *  \copyright Copyright (C) 2013-2015 Texas Instruments Incorporated -
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

#ifndef  HS_MMCSD_V2_LLD_H_
#define  HS_MMCSD_V2_LLD_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/cslr_mmchs.h>

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */

typedef enum hsMmcsdCmdType
{
    HS_MMCSD_CMD_TYPE_OTHER = CSL_MMCHS_CMD_CMD_TYPE_NORMAL,
    /**< Others commands. */
    HS_MMCSD_CMD_TYPE_BUS_SUSPEND = CSL_MMCHS_CMD_CMD_TYPE_SUSPEND,
    /**< Upon CMD52 "Bus Suspend" operation. */
    HS_MMCSD_CMD_TYPE_FUNC_SEL = CSL_MMCHS_CMD_CMD_TYPE_RESUME,
    /**< Upon CMD52 "Function Select" operation. */
    HS_MMCSD_CMD_TYPE_IO_ABORT = CSL_MMCHS_CMD_CMD_TYPE_ABORT
    /**< Upon CMD12 or CMD52 "I/O Abort" command. */
}hsMmcsdCmdType_t;


/**\brief MMCSD command type                                                  */
typedef enum
{
    MMCSD_CMDTYPE_BC    = 0,
    MMCSD_CMDTYPE_BCR   = 1,
    MMCSD_CMDTYPE_AC    = 2,
    MMCSD_CMDTYPE_ADTC  = 3
}mmcsdCmdType_t;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/** \brief Enumerates the list of response types. */
typedef enum hsMmcsdRspType
{
    HS_MMCSD_RSP_TYPE_NONE = CSL_MMCHS_CMD_RSP_TYPE_NORSP,
    /**< No response. */
    HS_MMCSD_RSP_TYPE_LEN_136 = CSL_MMCHS_CMD_RSP_TYPE_LGHT36,
    /**< Response Length 136 bits. */
    HS_MMCSD_RSP_TYPE_LEN_48 = CSL_MMCHS_CMD_RSP_TYPE_LGHT48,
    /**< Response Length 48 bits. */
    HS_MMCSD_RSP_TYPE_LEN_48_BUSY = CSL_MMCHS_CMD_RSP_TYPE_LGHT48B
    /**< Response Length 48 bits with busy after response. */
}hsMmcsdRspType_t;


/** \brief Enumerates the list of response types. */
typedef enum hsMmcsdXferType
{
    HS_MMCSD_XFER_TYPE_TX = CSL_MMCHS_CMD_DDIR_WRITE,
    /**< Data Write (host to card). */
    HS_MMCSD_XFER_TYPE_RX = CSL_MMCHS_CMD_DDIR_READ
    /**< Data Read (card to host). */
}hsMmcsdXferType_t;


/** \brief Structure holding the hs mmcsd controller system configurations. */
typedef struct hsMmcsdSysCfg
{
    uint32_t clockActivity;
    /**< Configuration of clock activity during wake up period. This can take
         values from the following enum #hsMmcsdClkAct_t. */
    uint32_t standbyMode;
    /**< standby mode configuration. This can take values from the following
         enum #hsMmcsdStandbyMode_t. */
    uint32_t idleMode;
    /**< Idle mode configuration. This can take values from the following
         enum #hsMmcsdIdleMode_t. */
    uint32_t enableWakeup;
    /**< Wake up enable/disable control. This can take following two values
         - TRUE  - Enable Wakeup
         - FALSE - Disable wakeup */
    uint32_t enableAutoIdle;
    /**< Auto idle enable/disable control. This can take following two values
         - TRUE  - Enable auto idle.
         - FALSE - Disable auto idle. */
}hsMmcsdSysCfg_t;


/**
 * \brief Structure for MMCSD command.
 */
typedef struct hsMmcsdCmd {
    uint32_t cmdId;
    /**< Command ID uses standard MMCSD card commands. */
    uint32_t cmdType;
    /**< Command type uses #hsMmcsdCmdType_t. */
    uint32_t rspType;
    /**< Response type uses #hsMmcsdRspType_t. */
    uint32_t xferType;
    /**< Command direction uses #hsMmcsdXferType_t. */
} hsMmcsdCmd_t;


/** \brief Structure holding the hs mmcsd controller command object. */
typedef struct hsMmcsdCmdObj
{
    hsMmcsdCmd_t cmd;
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
}hsMmcsdCmdObj_t;


/** \brief Structure to save the MMCSD context. */
typedef struct hsMmcsdCtx
{
    uint32_t capa;
    /**< Value of the capabilities register. */
    uint32_t systemConfig;
    /**< Value of the system configuration register. */
    uint32_t ctrlInfo;
    /**< Value of the control information register. */
    uint32_t hostCtrl;
    /**< Value of the host control register. */
    uint32_t sysCtrl;
    /**< Value of the system control register. */
    uint32_t pState;
    /**< Value of the present state register. */
}hsMmcsdCtx_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Function Declarations                              */
/* ========================================================================== */

/* ========================================================================== */
/*                   Deprecated Function Declarations                         */
/* ========================================================================== */

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef HS_MMCSD_H_ */
