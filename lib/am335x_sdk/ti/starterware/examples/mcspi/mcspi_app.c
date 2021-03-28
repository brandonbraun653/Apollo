/**
 * \file   mcspi_app.c
 *
 * \brief  Source file containing the MCSPI IP related configuration functions.
 *         These functions will be called by example application.
 *
 */

/**
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
#include "chipdb.h"
#include "pinmux.h"
#include "error.h"
#include "console_utils.h"
#include "interrupt.h"
#include "prcm.h"
#include "mcspi.h"

/* Application header files */
#include "mcspi_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Configure the MCSPI interrupts to interrupt controller.
 *
 * \param   pCfgMcspi      Pointer to the MCSPI configuration structure.
 *          pCfgMcspi will point to structure of type
 *          #mcspiAppCfgObj_t
 *
 * \retval  S_PASS         Interrupt configuration successful.
 * \retVal  E_FAIL         Interrupt configuration failed.
 *
 */
static int32_t McspiAppIntrConfig(mcspiAppCfgObj_t *pCfgMcspi);

/**
 * \brief   MCSPI Interrupt Service Routine. This function will clear the
 *          status of the Tx/Rx interrupts when generated. Will write the
 *          Tx data on transmit data register and also will put the
 *          received data from receive data register to a location in memory.
 *
 * \param   intrId         Interrupt ID.
 * \param   cpuId          CPU ID.
 * \param   pUserParam     User parameters.
 */
static void McspiAppFlashIsr(uint32_t intrId, uint32_t cpuId, void *pUserParam);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Flag used to control the flow between MCSPI ISR and the application flow. */
static uint32_t gMcspiAppIsrFlag = 1U;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t MCSPIAppInit(mcspiAppCfgObj_t *pCfgMcspi)
{
    int32_t status = S_PASS;

    /* Clock Configuration. */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_MCSPI, pCfgMcspi->instNum, 0U);

    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Clock Configuration failed !\n");
    }
    else
    {
        /* Perform the MCSPI pinmux. */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_MCSPI, pCfgMcspi->instNum, NULL);

        if (S_PASS != status)
        {
            CONSOLEUtilsPrintf("\n Pin Muxing failed !\n");
        }
        else
        {
            if(MCSPI_INTERRUPT_MODE == pCfgMcspi->pAppFlag.comFlag)
            {
                /* Register the MCSPI interrupts. */
                McspiAppIntrConfig(pCfgMcspi);

                /* Reset the MCSPI instance.*/
                McSPIReset(pCfgMcspi->instAddr);

                if (TRUE == pCfgMcspi->pAppFlag.csFlag)
                {
                    /* Enable CS. */
                    MCSPICsEnable(pCfgMcspi->instAddr, TRUE);

                    /* Set the CS polarity. */
                    MCSPISetCsPol(pCfgMcspi->instAddr,
                                  pCfgMcspi->channelNum,
                                  pCfgMcspi->pAppCfg.csPolarity);
                }
                else if (FALSE == pCfgMcspi->pAppFlag.csFlag)
                {
                    /**
                     *  Disable CS. In this scenario the CS will be handled
                     *  externally. E.g. would be using an external GPIO pin
                     *  or the CS pin of slave device is pulled to the required
                     *  polarity as default.
                     */
                    MCSPICsEnable(pCfgMcspi->instAddr, FALSE);
                }

                if (MCSPI_MODE_MASTER == pCfgMcspi->pAppFlag.modeFlag)
                {
                    /* Perform the necessary configuration for master mode.*/
                    MCSPIModeConfig(pCfgMcspi->instAddr,
                                    pCfgMcspi->channelNum,
                                    pCfgMcspi->pAppFlag.modeFlag,
                                    pCfgMcspi->pAppCfg.channel,
                                    pCfgMcspi->pAppCfg.txRxMode,
                                    pCfgMcspi->pAppCfg.pinMode);

                    /* Configure the clock speed on the bus. */
                    MCSPIClkConfig(pCfgMcspi->instAddr,
                                   pCfgMcspi->channelNum,
                                   pCfgMcspi->inClk,
                                   pCfgMcspi->outClk,
                                   pCfgMcspi->pAppCfg.clkMode);
                }
                else if (MCSPI_MODE_SLAVE == pCfgMcspi->pAppFlag.modeFlag)
                {
                    /* Perform the necessary configuration for slave mode.*/
                    MCSPIModeConfig(pCfgMcspi->instAddr,
                                    pCfgMcspi->channelNum,
                                    pCfgMcspi->pAppFlag.modeFlag,
                                    pCfgMcspi->pAppCfg.channel,
                                    pCfgMcspi->pAppCfg.txRxMode,
                                    pCfgMcspi->pAppCfg.pinMode);
                }

                /* Configure the word length. */
                McSPIWordLengthSet(pCfgMcspi->instAddr,
                                   pCfgMcspi->channelNum,
                                   pCfgMcspi->pAppCfg.wordLength);

                /* Enable/disable the Tx FIFO. */
                McSPITxFIFOConfig(pCfgMcspi->instAddr,
                                  pCfgMcspi->channelNum,
                                  pCfgMcspi->pAppCfg.txFifoCfg);

                /* Enable/disable the Rx FIFO. */
                McSPIRxFIFOConfig(pCfgMcspi->instAddr,
                                  pCfgMcspi->channelNum,
                                  pCfgMcspi->pAppCfg.rxFifoCfg);
            }
            else if(MCSPI_DMA_MODE == pCfgMcspi->pAppFlag.comFlag)
            {
                CONSOLEUtilsPrintf("\n DMA mode is not supported !\n");
            }
        }
    }
    return(status);
}

void MCSPIAppTransfer(mcspiAppCfgObj_t *pCfgMcspi)
{
    pCfgMcspi->intrCfg.pTxBuf = pCfgMcspi->pTx;
    pCfgMcspi->intrCfg.pRxBuf = pCfgMcspi->pRx;

    if (TRUE == pCfgMcspi->pAppFlag.csFlag)
    {
        /* SPIEN line is forced to low state.*/
        McSPICSAssert(pCfgMcspi->instAddr, pCfgMcspi->channelNum);
    }

    if (MCSPI_INTERRUPT_MODE == pCfgMcspi->pAppFlag.comFlag)
    {
        /* Enable the Tx/Rx interrupts of MCSPI.*/
        McSPIIntEnable(pCfgMcspi->instAddr, pCfgMcspi->pAppCfg.intrMask);

        /* Enable the MCSPI channel for communication.*/
        MCSPIChEnable(pCfgMcspi->instAddr, pCfgMcspi->channelNum, TRUE);

        /* Wait until control returns back from MCSPI ISR.*/
        while(gMcspiAppIsrFlag);

        gMcspiAppIsrFlag = 1U;

        if (TRUE == pCfgMcspi->pAppFlag.csFlag)
        {
            /* Force SPIEN line to the inactive state.*/
            McSPICSDeAssert(pCfgMcspi->instAddr, pCfgMcspi->channelNum);
        }

        /* Disable the MCSPI channel.*/
        MCSPIChEnable(pCfgMcspi->instAddr, pCfgMcspi->channelNum, FALSE);
    }
    else if (MCSPI_DMA_MODE == pCfgMcspi->pAppFlag.comFlag)
    {
        CONSOLEUtilsPrintf("\n DMA mode is not supported !\n");
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t McspiAppIntrConfig(mcspiAppCfgObj_t *pCfgMcspi)
{
    int32_t retVal = S_PASS;
    intcIntrParams_t mcspiAppIntrParams;

    /* Initialize the interrupt controller. */
    INTCInit(FALSE);

    mcspiAppIntrParams.triggerType = pCfgMcspi->intrCfg.trigType;
    mcspiAppIntrParams.priority = pCfgMcspi->intrCfg.intrPriority;
    mcspiAppIntrParams.pFnIntrHandler = McspiAppFlashIsr;
    mcspiAppIntrParams.pUserParam = pCfgMcspi;
    mcspiAppIntrParams.isIntrSecure = pCfgMcspi->intrCfg.isIntrSecure;

    if(S_PASS !=
       INTCConfigIntr(pCfgMcspi->intrCfg.intrLine, &mcspiAppIntrParams, FALSE))
    {
        CONSOLEUtilsPuts("Configuration failed for MCSPI interrupt.\r\n");

        retVal = E_FAIL;
    }

    return (retVal);
}

static void McspiAppFlashIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    uint32_t intrSts = 0U;
    mcspiAppCfgObj_t *instObj = (mcspiAppCfgObj_t *) pUserParam;

    /* Read the MCSPI interrupt status. */
    intrSts = McSPIIntStatusGet(instObj->instAddr);

    while(intrSts)
    {
        /* Check for Tx empty status. */
        if(MCSPI_INTR_TX_EMPTY(instObj->channelNum) ==
          (intrSts & MCSPI_INTR_TX_EMPTY(instObj->channelNum)))
        {
            /* Clear the Tx empty status. */
            McSPIIntStatusClear(instObj->instAddr,
                           MCSPI_INTR_TX_EMPTY(instObj->channelNum));

            instObj->dataLength--;

            /* Program the data to be transmitted. */
            McSPITransmitData(instObj->instAddr,
                              instObj->channelNum,
                             (unsigned int)(*instObj->intrCfg.pTxBuf++));

            /* Check if data transfer is complete. */
            if(!instObj->dataLength)
            {
                /* Disable the Tx empty interrupt. */
                McSPIIntDisable(instObj->instAddr,
                                 MCSPI_INTR_TX_EMPTY(instObj->channelNum));

                /* Clear the Tx empty status. */
                McSPIIntStatusClear(instObj->instAddr,
                                MCSPI_INTR_TX_EMPTY(instObj->channelNum));
            }
        }

        /* Check for Rx full status. */
        if(MCSPI_INTR_RX_FULL(instObj->channelNum) ==
          (intrSts & MCSPI_INTR_RX_FULL(instObj->channelNum)))
        {
            /* Clear the Rx full status. */
            McSPIIntStatusClear(instObj->instAddr,
                           MCSPI_INTR_RX_FULL(instObj->channelNum));

            /* Read the received data. */
            *instObj->intrCfg.pRxBuf++ =
                          (unsigned char) McSPIReceiveData(instObj->instAddr,
                                                           instObj->channelNum);

            if(!instObj->dataLength)
            {
                /* Disable the Rx full interrupt. */
                McSPIIntDisable(instObj->instAddr,
                                 MCSPI_INTR_RX_FULL(instObj->channelNum));

                gMcspiAppIsrFlag = 0U;
            }
        }

        /* Read the MCSPI interrupt status. */
        intrSts = McSPIIntStatusGet(instObj->instAddr);
    }
}
