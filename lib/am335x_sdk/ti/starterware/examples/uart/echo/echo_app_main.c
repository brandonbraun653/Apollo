/**
 * \file   echo_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case.
 *
 * \detail Application demonstrates the Receive/Transmit features
 *         of UART using a FIFO.
 *         Interrupt features related to FIFO trigger levels are
 *         demonstrated for reading/writing to the FIFO.
 *
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
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "cache.h"
#include "example_utils_mmu.h"
#include "console_utils.h"
#include "dma_utils.h"

/* Application header files */
#include "uart_app.h"
#include "echo_app.h"


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* None */

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
static int32_t UartAppBoardInfoGet(uartAppObj_t *pObj);

/**
 * \brief   This API gets the soc info - base address of UART instance.
 *
 * \param   pObj        Pointer to the pin object.
 *
 * \retval  S_PASS      SoC information successfully retrieved.
 * \retval  E_FAIL      SOC info retrieval is failed. Resource is not present.
 */
static int32_t UartAppSocInfoGet(uartAppObj_t *pObj);

/**
 * \brief   UART Echo use case function.
 *
 * \param   pUartObj      Pointer to the UART app object.
 *
 * \retval  S_PASS      Use case successful.
 * \retval  E_FAIL      Use case failed.
 */
static int32_t UartAppEcho(uartAppObj_t *pUartObj);


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Global object for the UART IP configuration. */
static uartAppObj_t gUartAppObj;

/** \brief Data buffer holding the String to be transmitted. */
static uint8_t gUartAppTxDataBuf[] =
    "\r\nPlease enter 10 bytes. They will be echoed back to Console\r\n";


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int main(void)
{
    int32_t status = S_PASS;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();

    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    /* Initialize the global IP configuration with default configuration. */
    gUartAppObj = UARTAPPOBJ_DEFAULT;
    gUartAppObj.uartAppCfg.enableIntr = TRUE;

    status = BOARDInit(NULL);

    /* Get board info */
    status = UartAppBoardInfoGet(&gUartAppObj);

    if (S_PASS == status)
    {
        /* Get SoC info */
        status = UartAppSocInfoGet(&gUartAppObj);

        if(S_PASS == status)
        {
            /* UART IP configuration */
            status = UARTAppInit(&gUartAppObj);

            if(S_PASS == status)
            {
                status = UartAppEcho(&gUartAppObj);
            }
        }
    }

    return (status);
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t UartAppBoardInfoGet(uartAppObj_t *pObj)
{
    int32_t status = S_PASS;

    pObj->instNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_CONSOLE, 0U);

    return (status);
}

static int32_t UartAppSocInfoGet(uartAppObj_t *pObj)
{
    uint32_t status = S_PASS;

    /* Get the base address of the Module */
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_UART, pObj->instNum))
    {
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_UART, pObj->instNum);

        /* Update the Interrupt Line number */
        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            pObj->uartAppCfg.uartAppIntrCfg.intrLine = 104U;

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
        else
        {
            if (pObj->instNum == 0)
            {
                pObj->uartAppCfg.uartAppIntrCfg.intrLine = 72U;

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
            else if (pObj->instNum == 5) /* ICE v1 */
            {
                pObj->uartAppCfg.uartAppIntrCfg.intrLine = 46U;
                /* TBD: DMA Channels to be configured through cross bar */
            }
            else if (pObj->instNum == 3) /* ICE v2 */
            {
                pObj->uartAppCfg.uartAppIntrCfg.intrLine = 44U;
                /* TBD :DMA Channels to be configured through cross bar */
            }
        }
    }
    else
    {
        status = E_FAIL;
    }

    return status;
}

static int32_t UartAppEcho(uartAppObj_t *pUartObj)
{
    int32_t status = S_PASS;

    UARTIntrEnable(pUartObj->instAddr, (UART_INTR_RX_THRESHOLD |
        UART_INTR_TX_THRESHOLD));

    while(1)
    {
        if(TRUE == pUartObj->isTxFifoEmpty)
        {
            /* Write the Tx Data to the FIFO. */
            UARTFifoWrite(pUartObj->instAddr, gUartAppTxDataBuf,
                sizeof(gUartAppTxDataBuf));

            /* Set it to False to disable the Transmission. */
            pUartObj->isTxFifoEmpty = FALSE;

        }
        /*
        ** If the number of received bytes is same as the number of bytes
        ** to be echoed.
        */
        if(pUartObj->numRdBytesISR == pUartObj->numRdBytes)
        {
            /* Wait till FIFO becomes empty. */
            while(FALSE == UARTIsSpaceAvail(pUartObj->instAddr));
            UARTIntrDisable(pUartObj->instAddr, UART_INTR_RX_THRESHOLD);
            break;
        }
    }
    return status;
}

void UartAppDmaCallBack(uint32_t chNum, uint32_t xferStatus)
{
    uartAppObj_t *pUartObj = &gUartAppObj;

    if(pUartObj->uartAppCfg.dmaCfg.txEvtInfo.chNum == chNum)
    {
        UARTAppDmaXferStop(pUartObj, UART_DMA_EVT_TX);
    }
    else if(pUartObj->uartAppCfg.dmaCfg.rxEvtInfo.chNum == chNum)
    {
        UARTAppDmaXferStop(pUartObj, UART_DMA_EVT_RX);
    }
    else
    {
        /* This case will not occur as no other interrupts are enabled. */
    }
}
