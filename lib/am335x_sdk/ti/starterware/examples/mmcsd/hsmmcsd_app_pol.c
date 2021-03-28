/**
 *  \file  hsmmcsd_app_pol.c
 *
 *  \brief This file contains functions which interface interactively
 *         with the user through the serial console to perform some
 *         utility operations.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_cm_per.h"
#if defined(AM335X_FAMILY_BUILD)
#include "soc_am335x.h"
#include "hw_control_am335x.h"
#elif defined(AM43XX_FAMILY_BUILD)
#include "am437x.h"
#include "hw_control_am43xx.h"
#endif /* if defined(AM335X_FAMILY_BUILD) */
#include "hs_mmcsd.h"
#include "board.h"
#include "prcm.h"
#include "mmcsd_lib.h"
#include "hsmmcsd_lib_port.h"
#include "console_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#if defined(AM335X_FAMILY_BUILD)

/** \brief MMCSD Controller case address. */
#define MMCSD_BASE                     (SOC_MMCHS_0_REGS)

/** \brief Input frequency on initialization. */
#define MMCSD_IN_FREQ                  (96000000U) /* 96MHz */

/** \brief Output frequency on initialization. */
#define MMCSD_INIT_FREQ                (400000U)   /* 400kHz */

/** \brief Card block size. */
#define MMCSD_BLK_SIZE                 (512U)

/** \brief Card voltage level configuration. */
#define MMCSD_OCR                      (MMCSD_LIB_OCR_VDD_3P0_3P1 | MMCSD_LIB_OCR_VDD_3P1_3P2)

#elif defined(AM43XX_FAMILY_BUILD)

/** \brief MMCSD Controller case address. */
#define MMCSD_BASE                     (SOC_MMCSD0_REG)

/** \brief Input frequency on initialization. */
#define MMCSD_IN_FREQ                  (96000000U) /* 96MHz */

/** \brief Output frequency on initialization. */
#define MMCSD_INIT_FREQ                (400000U)   /* 400kHz */

/** \brief Card block size. */
#define MMCSD_BLK_SIZE                 (512U)

/** \brief Card voltage level configuration. */
#define MMCSD_OCR                      (MMCSD_LIB_OCR_VDD_3P0_3P1 | MMCSD_LIB_OCR_VDD_3P1_3P2)

#endif /* if defined(AM335X_FAMILY_BUILD) */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This function initializes the controller struct.\n
 *
 * \param  pCtrl         It holds the mmcsd control information.
 * \param  pCard         It holds the mmcsd card information.
 * \param  instNum       Controller instance number.
 */
static void HSMMCSDAppPolControllerSetup(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCardInfo_t *pCard, uint32_t instNum);

/**
 * \brief  This function Check the command status.
 *
 * \param  pCtrl  MMCSD controller info.
 *
 * \retval status Command status.
 */
static uint32_t HSMMCSDAppPolCmdStatusGet(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief  This function gets the Xfer status.\n
 *
 * \param  pCtrl   MMCSD controller info.\n
 *
 * \retval status  Xfer status.\n
 */
static uint32_t HSMMCSDAppPolXferStatusGet(mmcsdLibCtrlInfo_t *pCtrl);

/**
* \brief  This function setup the controller and DMA for Xfer.\n
*
* \param  pCtrl    MMCSD controller info.\n
* \param  rwFlag   Read/Write flag.\n
* \param  blkSize  Block Size.\n
* \param  nBlks    Number of Blocks.\n
*/
static void HSMMCSDAppPolXferSetup(mmcsdLibCtrlInfo_t *pCtrl,
                                   unsigned char rwFlag,
                                   void *ptr,
                                   uint32_t blkSize,
                                   uint32_t nBlks);

/**
* \brief  This function Check the command status.\n
*
* \param  pCtrl  MMCSD controller info.\n
*
* \retval status command status.\n
*/
static uint32_t HSMMCSDAppPolStatusGet(mmcsdLibCtrlInfo_t *pCtrl);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief Receiver buffer for blocking input operations. */
volatile uint32_t xferPend = FALSE;

/** \brief Receiver buffer for blocking input operations. */
volatile uint32_t cmdCompFlag = FALSE;

/** \brief Receiver buffer for blocking input operations. */
volatile uint32_t cmdTimeout = FALSE;

/** \brief Receiver buffer for blocking input operations. */
volatile uint32_t errFlag = 0U;

/** \brief Receiver buffer for blocking input operations. */
uint32_t dataLen = 0U;

/** \brief Receiver buffer for blocking input operations. */
volatile uint8_t *pDataBuffer = NULL;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void HSMMCSDAppPolInit(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCardInfo_t *pCard, uint32_t instNum)
{
    int32_t status = S_PASS;
    boardId_t boardId;

    /* Enable clock for MMCSD and do the PINMUXing */
    status = PINMUXModuleConfig(CHIPDB_MOD_ID_MMCSD, instNum, NULL);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Pin Muxing failed !\n");
    }

    PRCMModuleEnable(CHIPDB_MOD_ID_MMCSD, instNum, 0U);

    /* Basic controller initializations */
    HSMMCSDAppPolControllerSetup(pCtrl, pCard, instNum);

    /* Get the board Id */
    boardId = BOARDGetId();

    /* First check, if card is insterted */
    /* Do not check card insertion status for ICEv2 */


    if (boardId == BOARD_ICEV2)
    {
         CONSOLEUtilsPrintf("\nMMC/SD Card Detect Pin Not Used on Hardware\n");
    }
    else
    {
        while(1)
        {
            if (FALSE == MMCSDLibCardPresent(pCtrl))
            {
                CONSOLEUtilsPuts("MMC/SD Card not found\n\r");
            }
            else
            {
                break;
            }
        }
    }

    /* Initialize the MMCSD controller */
    MMCSDLibCtrlInit(pCtrl);

    HSMMCSDIntrStatusEnable(pCtrl->baseAddr, pCtrl->intrMask);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t HSMMCSDAppPolCmdStatusGet(mmcsdLibCtrlInfo_t *pCtrl)
{
    uint32_t status = FALSE;

     while ((FALSE == cmdCompFlag) && (FALSE == cmdTimeout))
    {
        status = HSMMCSDAppPolStatusGet(pCtrl);
    }

    if (cmdCompFlag)
    {
        HSMMCSDIntrClear(pCtrl->baseAddr,
                                   HS_MMCSD_INTR_MASK_CMDCOMP);
        status = TRUE;
        cmdCompFlag = FALSE;
    }

    if (cmdTimeout)
    {
        HSMMCSDIntrClear(pCtrl->baseAddr,
                                   HS_MMCSD_INTR_MASK_CMDTIMEOUT);
        status = FALSE;
        cmdTimeout = FALSE;
    }

    return status;
}

static uint32_t HSMMCSDAppPolXferStatusGet(mmcsdLibCtrlInfo_t *pCtrl)
{
    volatile uint32_t status = FALSE;
    volatile uint32_t temp;
    uint32_t cnt;

    while(TRUE)
    {
        status = HSMMCSDAppPolStatusGet(pCtrl);

        if (status & HS_MMCSD_INTR_MASK_BUFRDRDY)
        {
            HSMMCSDIntrClear(pCtrl->baseAddr,
                                   HS_MMCSD_INTR_MASK_BUFRDRDY);

            if (pDataBuffer != NULL)
            {
                for (cnt = 0U; cnt < dataLen; cnt += 4U)
                {
                    HSMMCSDGetData(pCtrl->baseAddr, (uint8_t *)&temp, 4U);
                    pDataBuffer[cnt] = *((uint8_t*)&temp);
                    pDataBuffer[cnt + 1U] = *((uint8_t*)&temp + 1U);
                    pDataBuffer[cnt + 2U] = *((uint8_t*)&temp + 2U);
                    pDataBuffer[cnt + 3U] = *((uint8_t*)&temp + 3U);
                }
            }
        }

        if (status & HS_MMCSD_INTR_MASK_BUFWRRDY)
        {
            HSMMCSDIntrClear(pCtrl->baseAddr,
                                   HS_MMCSD_INTR_MASK_BUFWRRDY);

            if (pDataBuffer != NULL)
            {
                for (cnt = 0; cnt < dataLen; cnt+=4)
                {
                    *((uint8_t*)&temp) = pDataBuffer[cnt];
                    *((uint8_t*)&temp + 1U) = pDataBuffer[cnt + 1U];
                    *((uint8_t*)&temp + 2U) = pDataBuffer[cnt + 2U];
                    *((uint8_t*)&temp + 3U) = pDataBuffer[cnt + 3U];
                    HW_WR_REG32((pCtrl->baseAddr + HS_MMC_SD_DATA), temp);
                }
            }
        }

        if (status & HS_MMCSD_INTR_MASK_DATATIMEOUT)
        {
            HSMMCSDIntrClear(pCtrl->baseAddr,
                                   HS_MMCSD_INTR_MASK_DATATIMEOUT);
            status = FALSE;
            xferPend = FALSE;
            break;
        }

        if (status & HS_MMCSD_INTR_MASK_TRNFCOMP)
        {
            HSMMCSDIntrClear(pCtrl->baseAddr,
                                   HS_MMCSD_INTR_MASK_TRNFCOMP);
            status = TRUE;
            xferPend = FALSE;
            break;
        }
    }

    return status;
}

static void HSMMCSDAppPolXferSetup(mmcsdLibCtrlInfo_t *pCtrl, unsigned char rwFlag, void *ptr,
                             uint32_t blkSize, uint32_t nBlks)
{
    HSMMCSDIntrClear(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_TRNFCOMP);

    if (rwFlag == 1)
    {
        HSMMCSDIntrClear(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
        HSMMCSDIntrStatusEnable(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
        HSMMCSDIntrStatusDisable(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
    }
    else
    {
        HSMMCSDIntrClear(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
        HSMMCSDIntrStatusEnable(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
        HSMMCSDIntrStatusDisable(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
    }

    HSMMCSDBlkLenSet(pCtrl->baseAddr, blkSize);
    dataLen = (nBlks * blkSize);
    pDataBuffer = ptr;
    xferPend = TRUE;
}

static uint32_t HSMMCSDAppPolStatusGet(mmcsdLibCtrlInfo_t *pCtrl)
{
    volatile uint32_t status = 0U;

    status = HSMMCSDIntrStatus(pCtrl->baseAddr);

    if (status & HS_MMCSD_INTR_MASK_CMDCOMP)
    {
        cmdCompFlag = TRUE;
    }

    if (status & HS_MMCSD_INTR_MASK_ERR)
    {
        errFlag = status & 0xFFFF0000;

        if (errFlag & HS_MMCSD_INTR_MASK_CMDTIMEOUT)
        {
            cmdTimeout = TRUE;
        }
    }

    return status;
}

static void HSMMCSDAppPolControllerSetup(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCardInfo_t *pCard, uint32_t instNum)
{
    pCtrl->baseAddr = MMCSD_BASE;
    pCtrl->pfnCtrlInit = HSMMCSDLibPortCtrlInit;
    pCtrl->pfnXferSetup = HSMMCSDAppPolXferSetup;
    pCtrl->pfnCmdStatusGet = HSMMCSDAppPolCmdStatusGet;
    pCtrl->pfnXferStatusGet = HSMMCSDAppPolXferStatusGet;
    pCtrl->pfnCardPresent = HSMMCSDLibPortIsCardPresent;
    pCtrl->pfnCmdSend = HSMMCSDLibPortCmdSend;
    pCtrl->pfnBusWidthConfig = HSMMCSDLibPortBusWidthConfig;
    pCtrl->pfnBusFreqConfig = HSMMCSDLibPortBusFreqConfig;
    pCtrl->intrMask = (HS_MMCSD_INTR_MASK_CMDCOMP | HS_MMCSD_INTR_MASK_CMDTIMEOUT |
                            HS_MMCSD_INTR_MASK_DATATIMEOUT | HS_MMCSD_INTR_MASK_TRNFCOMP);
    pCtrl->pfnIntrEnable = HSMMCSDLibPortIntrEnable;
    pCtrl->busWidth = (MMCSD_LIB_BUS_WIDTH_1BIT | MMCSD_LIB_BUS_WIDTH_4BIT);
    pCtrl->highspeed = 1U;
    pCtrl->ocr = MMCSD_OCR;
    pCtrl->pCard = pCard;
    pCtrl->ipClk = MMCSD_IN_FREQ;
    pCtrl->opClk = MMCSD_INIT_FREQ;
    pCard->pCtrl = pCtrl;
    pCtrl->dmaEnable = FALSE;

    cmdCompFlag = FALSE;
    cmdTimeout = FALSE;
}

