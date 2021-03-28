/**
 * \file   cacheUart.c
 *
 * \brief  This file has the functions which handles the data transfer to Uart
 *         port. The initialization and uart configuration functions are also
 *         defined here. These functions are intended to be used with Cache demo
 *         application.
 */

/*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
*
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
#include "error.h"
#include "chipdb.h"
#include "prcm.h"
#include "pinmux.h"
#include "soc.h"
#include "board.h"
#include "uart.h"
#include "misc.h"
#include "dma.h"
#include "dma_utils.h"
#include "uart_app.h"
#include "cache_mmu_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief UART instance number */
#define CACHE_UART_INST_NUM     (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets the board information specific to UART
 *
 * \param   pObj        Pointer to the pin object.
 *
 * \retval  S_PASS      Board info successful retrieved. Buzzer is connected to
 *                      GPIO on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - Buzzer device may not be available on this board.
 *                      - Buzzer may not be connected to GPIO on this board.
 */
static int32_t CACHEAppUartBoardInfoGet(uartAppObj_t *pObj);

/**
 * \brief   This API gets the soc info - base address of UART instance.
 *
 * \param   pObj        Pointer to the pin object.
 *
 * \retval  S_PASS      SoC information successfully retrieved.
 * \retval  E_FAIL      SOC info retrieval is failed. Resource is not present.
 */
static int32_t CACHEAppUartSocInfoGet(uartAppObj_t *pObj);

/**
 * \brief   This API is call back function to handle EDMA event.
 *
 * \param   chNum       Channel number on which call back function occured.
 * \param   xferStatus  Transfer status on the EDMA channel number.
 */
static void CACHEAppUartDmaCallBack(uint32_t chNum, uint32_t xferStatus);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Global object for the UART IP configuration. */
static uartAppObj_t gCACHEAppUartObj;

/** \brief Global status for UART DMA action status. */
volatile uint32_t gCACHEAppUartTxStatus = FALSE;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* This function initializes the UART instance for use. */
void CACHEAppUartInitialize(uint32_t uartInstNum)
{
    uint32_t status = S_PASS;

    uartAppDmaCfg_t *pUartDmaCfg = &(gCACHEAppUartObj.uartAppCfg.dmaCfg);

    /* Initialize the global IP configuration with default configuration. */
    gCACHEAppUartObj = UARTAPPOBJ_DEFAULT;
    gCACHEAppUartObj.uartAppCfg.enableDma = TRUE;

    status = BOARDInit(NULL);

    /* Get board info */
    status = CACHEAppUartBoardInfoGet(&gCACHEAppUartObj);

    if (S_PASS == status)
    {
        /* Get SoC info */
        status = CACHEAppUartSocInfoGet(&gCACHEAppUartObj);

        if(S_PASS == status)
        {
            /* UART IP configuration */
            status = UARTAppInit(&gCACHEAppUartObj);

            if(S_PASS == status)
            {
                status = DMAUtilsInit(pUartDmaCfg->dmaType,
                    pUartDmaCfg->rxEvtInfo.instNum, NULL);
            }
        }
    }
}

void CACHEAppUartTransfer(uint8_t* pBuffer, uint32_t bufLength)
{
    UARTAppDmaTxSetup(&gCACHEAppUartObj, pBuffer, 1U, bufLength);
    UARTAppDmaXferStart(&gCACHEAppUartObj, UART_DMA_EVT_TX);

    /* Enabling UART in DMA Mode*/
    UARTDmaEnable(gCACHEAppUartObj.instAddr, UART_DMA_MODE_MODE1);

    /* Wait for return from callback */
    while(FALSE == gCACHEAppUartTxStatus);
    gCACHEAppUartTxStatus = FALSE;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t CACHEAppUartBoardInfoGet(uartAppObj_t *pObj)
{
    int32_t status = S_PASS;

    /* Check which UART instance is brought out on the board. */
    /* TBD: Hard-code for now */
    pObj->instNum = CACHE_UART_INST_NUM;

    return (status);
}

static int32_t CACHEAppUartSocInfoGet(uartAppObj_t *pObj)
{
    uint32_t status = S_PASS;

    /* Get the base address of the Module */
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_UART, pObj->instNum))
    {
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_UART, pObj->instNum);

        pObj->uartAppCfg.dmaCfg.pFxnCallBack = &CACHEAppUartDmaCallBack;

        /* Update the Interrupt Line number */
        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            pObj->uartAppCfg.uartAppIntrCfg.intrLine = 104U;

            pObj->uartAppCfg.dmaCfg.dmaType = DMA_TYPE_ENHACED;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.dmaType = DMA_TYPE_ENHACED;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.instNum = 0U;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.evtToChMapType = DMA_UTILS_EVENT_MAP_TYPE_DIRECT;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.evtNum = 27U;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.chNum = 27U;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.xferIdx = 27U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.instNum = 0U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.evtToChMapType = DMA_UTILS_EVENT_MAP_TYPE_DIRECT;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.evtNum = 26U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.chNum = 26U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.xferIdx = 26U;
        }
        else
        {
            pObj->uartAppCfg.uartAppIntrCfg.intrLine = 72U;

            pObj->uartAppCfg.dmaCfg.dmaType = DMA_TYPE_ENHACED;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.dmaType = DMA_TYPE_ENHACED;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.instNum = 0U;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.evtToChMapType = DMA_UTILS_EVENT_MAP_TYPE_DIRECT;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.evtNum = 26U;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.chNum = 26U;
            pObj->uartAppCfg.dmaCfg.rxEvtInfo.xferIdx = 26U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.instNum = 0U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.evtToChMapType = DMA_UTILS_EVENT_MAP_TYPE_DIRECT;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.evtNum = 26U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.chNum = 26U;
            pObj->uartAppCfg.dmaCfg.txEvtInfo.xferIdx = 26U;
        }
    }
    else
    {
        status = E_FAIL;
    }

    return status;
}

void CACHEAppUartDmaCallBack(uint32_t chNum, uint32_t xferStatus)
{
    uint32_t status = S_PASS;
    uartAppObj_t *pUartObj = &gCACHEAppUartObj;

    if(pUartObj->uartAppCfg.dmaCfg.txEvtInfo.chNum == chNum)
    {
        gCACHEAppUartTxStatus = TRUE;
        UARTAppDmaXferStop(pUartObj, UART_DMA_EVT_TX);
    }
    else if(pUartObj->uartAppCfg.dmaCfg.rxEvtInfo.chNum == chNum)
    {
        UARTAppDmaXferStop(pUartObj, UART_DMA_EVT_RX);
    }
    else
    {
        status = E_FAIL;
    }

    if(S_PASS == status)
    {
        /* Disabling DMA feature in UART. */
        UARTDMADisable(gCACHEAppUartObj.instAddr);
    }
}
