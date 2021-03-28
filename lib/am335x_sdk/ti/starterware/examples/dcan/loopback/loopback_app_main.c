/**
 * \file     loopback_app_main.c
 *
 * \brief    Example application main source file, which configures the DCAN IP
 *           to transmit and receive CAN frames using internal loopback.
 *           DMA is used for data transfer.
 *
 *      APPLICATION CONFIGURATION:
 *      --------------------------
 *          Modules used:
 *              DCAN
 *              EDMA
 *              Uart
 *              Interrupt controller
 *
 *      FUNCTIONALITY:
 *      --------------
 *        This application functions as follows.
 *
 *        1.OBTAIN DATA TO TRANSMIT:
 *            1. Initialize UART console.
 *            2. Obtain the frames to be transmitted from the user.
 *               The user is given an option to choose between one and ten
 *               frames. The user also inputs eight bytes of data for each
 *               frame.
 *            3. Store the obtained data in a source buffer in memory.
 *
 *        2.DMA CONFIGURATION:
 *            1. Configure EDMA for two events: DCAN0 IF1 event, DCAN0 IF3
 *               event.
 *            2. Configure EDMA control registers and PaRAM sets to transfer data
 *               from source buffer in memory to Data registers of IF1 register
 *               set on IF1 DMA event. This is the data to be transmitted.
 *               So, IF1 event is the transmit event.
 *            3. Configure EDMA control registers and PaRAM sets to transfer data
 *               from Data registers of IF3 register set to destination buffer in
 *               memory on IF3 DMA event. This is the data received.
 *               So, IF3 event is the receive event.
 *            4. Configure EDMA to transfer one frame data per DMA event.
 *
 *        3.DCAN CONFIGURATION:
 *            1. Initialize DCAN IP and configure DCAN interrupt.
 *            2. Enable internal loopback mode to receive frames transmitted.
 *            3. Enable DMA request lines for IF1 and IF3.
 *            4. Configure receive message objects to receive data frame.
 *            5. Configure IF3 to automatically update data registers with
 *               data of frame received.
 *            6. Configure IF1 CMD register to generate DMA request after every
 *               transfer from IF1 regsister set to message RAM.
 *
 *        4.FRAME TRANSMISSION:
 *            1. Enable transmit interrupts and start sending data.
 *            2. When transmitting frames, data from IF1 register set is moved
 *               to message RAM by the application. This will generate a DMA
 *               transmit event to move next frame data from memory to IF1 for
 *               transmission.
 *
 *        5.FRAME RECEPTION:
 *            1. As soon as a frame is transmitted, it is received through internal
 *               loopback. The data is automatically copied from message RAM to data
 *               registers of IF3 which then generates a DMA receive event to copy
 *               the data to destination buffer.
 *            2. When all frames are received, print them on the UART console.
 *            3. Frame transmit and receive operations are independent of each other.
 *
 *      RUNNING THE EXAMPLE:
 *      --------------------
 *          Connect the serial port and configure the terminal in host PC. Load
 *          and execute the application binary. Provide frame count between 1 and
 *          10. Then provide exactly eight bytes of data for each frame. Once they
 *          are received and transferred to memory, they are displayed.
 *
 */

/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
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

#include "soc_control.h"
#include "board.h"
#include "console_utils.h"
#include "soc.h"
#include "dcan.h"

/* Application header files */
#include "dcan_app.h"

#ifdef RTOS_BUILD
#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/osal/RegisterIntr.h>
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/**
 * \name    Macros used by DCAN loopback application.
 */

/** @{ */
/** \brief Maximum DCAN frames the application supports.
 */
#define MAX_FRAMES                          (10U)

/** \brief DCAN connector instance number.
 */
#define DCAN_CONNECTOR_INST_NUM             (0U)

/** \brief Bitrate to be used on the CAN bus.
 */
#define DCAN_BIT_RATE                       (1000000U)

/** \brief Input clock used for the DCAN module.
 */
#define DCAN_INPUT_CLK                      (24000000U)

/** \brief Maximum data bytes allowed per frame.
 */
#define DCAN_MAX_BYTES_PER_FRAME            (8U)

/** \brief Receive message object ID.
 */
#define DCAN_RX_MSG_ID                      (0U)

/** \brief    Configure the transmit frame ID.
 *
 *  \details  This macro has to be commented if a CAN frame with extended ID
 *            has to be transmitted.
 */
#define DCAN_STD_ID
/** @} */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Application default configuration */
static const dcanAppCfgObj_t DCANAPPTXRX_DEFAULT =
{
    0U,                               /* instNum */
    0U,                               /* instAddr */
    DCAN_INPUT_CLK,                   /* inputClk */
    DCAN_BIT_RATE,                    /* bitRate */
    0U,                               /* maxMsgObjs */
    0U,                               /* msgObjNum */
    {
        INTC_TRIG_HIGH_LEVEL,         /* trigType */
        0U,                           /* intrLine */
        16U,                          /* intrPriority */
        FALSE,                        /* enableSecureIntr */
        0U,                           /* errVal */
        0U,                           /* txCtrl */
        0U,                           /* rxCtrl */
        1U,                           /* intrCount */
        0U,                           /* totalFrames */
        0U,                           /* frameLen*/
        NULL                          /* pFnIntrHandler */
    },
    {
        0U,                           /* commType */
        0U,                           /* frame */
        0U,                           /* ctrlParams */
        0U,                           /* canId */
        0U,                           /* dataLengthCode */
        NULL,                         /* pData */
        FALSE                         /* appLoopBk */
    }
};

/** \brief Global object for the CAN Tx Rx. */
dcanAppCfgObj_t gDcanTxRx;

/** \brief CAN frame details */
#ifdef DCAN_STD_ID
/** \brief CAN frame control parameters for transmitting standard ID. */
static uint32_t gDcanTxCtrlParam = (DCAN_DATA_FRAME | DCAN_MSG_TX_DIR);

/** \brief CAN frame standard ID. */
static uint32_t gDcanId = 0x01U;
#else
/** \brief CAN frame control parameters for transmitting extended ID. */
static uint32_t gDcanTxCtrlParam = (DCAN_EXT_FRAME |
                                    DCAN_DATA_FRAME |
                                    DCAN_MSG_TX_DIR);

/** \brief CAN frame extended ID. */
static uint32_t gDcanId = 0x2000U;
#endif

/** \brief CAN control parameters for receiving a frame. */
static uint32_t gDcanRxCtrlParam = (DCAN_DATA_FRAME | DCAN_MSG_RX_DIR);

/** \brief Source buffer to store DCAN data to be transmitted.  */
volatile uint8_t srcBuffer[DCAN_MAX_BYTES_PER_FRAME * MAX_FRAMES];

/** \brief Destination buffer to store DCAN data received.  */
volatile uint8_t dstBuffer[DCAN_MAX_BYTES_PER_FRAME * MAX_FRAMES];

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief     Fetch the DCAN instance address.
 *
 * \param     pObj       Pointer to the DCAN loopback application configuration
 *                       structure.
 */
static void DcanInfoGet(dcanAppCfgObj_t *pObj);

/**
 * \brief   Transfer single/multiple CAN frames.
 *
 * \param   pObj          Pointer to the DCAN configuration
 *                        structure.
 * \param   numOfFrames   Single/Multiple frames to be transmitted.
 *          numOfFrames can take values between 1 and MAX_FRAMES
 */
static void DcanMsgTransfer(dcanAppCfgObj_t *pObj, uint32_t numOfFrames);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int dcanTest(void)
{
    int32_t status = S_PASS;
    uint8_t buff[DCAN_MAX_BYTES_PER_FRAME];
    uint32_t byteIndex, frameIndex;
    uint32_t numOfFrames = 0;

    status = BOARDInit(NULL);

    if(S_PASS == status)
    {
        /* Initialize the UART console */
        CONSOLEUtilsInit();
        /* Select the console type based on compile time check */
        CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

        CONSOLEUtilsPrintf("\nStarterWare DCAN loopback Application!!\n\n");
        CONSOLEUtilsPrintf("Please enter the number of frames (from 1 to %d) to transmit: ", MAX_FRAMES);
        CONSOLEUtilsScanf("%d", &numOfFrames);
        CONSOLEUtilsPrintf("\n");

        if(numOfFrames > 0 && numOfFrames <= MAX_FRAMES)
            status = S_PASS;
        else
            status = E_FAIL;
    }

    if(S_PASS == status)
    {
        for(frameIndex = 0; frameIndex < numOfFrames; frameIndex++)
        {
            CONSOLEUtilsPrintf("Please enter exactly 8 characters for frame %02d: ",frameIndex+1);
            CONSOLEUtilsGets(buff, DCAN_MAX_BYTES_PER_FRAME + 1U);

            for(byteIndex = 0; byteIndex < DCAN_MAX_BYTES_PER_FRAME; byteIndex++)
            {
                srcBuffer[(DCAN_MAX_BYTES_PER_FRAME * frameIndex) + byteIndex] = buff[byteIndex];
            }
        }

        /* Initialize DMA */
        DcanAppDmaInitialize(numOfFrames);

        /* Configure DMA for DCAN data transfer */
        DcanAppDmaTransfer((uint8_t*)srcBuffer, (uint8_t*)dstBuffer, DCAN_MAX_BYTES_PER_FRAME);

        gDcanTxRx = DCANAPPTXRX_DEFAULT;

        /* Get CAN instance address */
        DcanInfoGet(&gDcanTxRx);

        /* Initialize the DCAN */
        DCANAppInit(&gDcanTxRx);

        uint32_t index = gDcanTxRx.maxMsgObjs;
        while(index > 0)
        {
            /* Invalidate the DCAN message objects. */
            DCANAppInvalidateMsgObject(gDcanTxRx.instAddr,
                    index,
                    DCAN_IF_REG_NUM_2);
            index--;
        }

        /* Enable internal loopback mode */
        DCANTestModeEnable(gDcanTxRx.instAddr, DCAN_TEST_MODE_MASK_LPBACK, TRUE);

        /* Configure DCAN for DMA operation */
        DCANAppDmaConfig(gDcanTxRx.instAddr, TRUE);

        /* Transmit frames */
        DcanMsgTransfer(&gDcanTxRx, numOfFrames);

        /* Wait until reception is complete */
        while(DcanAppDmaReceptionCompleteStatus() != TRUE);

        /* Stop DCAN data transfer */
        DCANAppStopTransfer(&gDcanTxRx);

        /* Disable internal loopback mode */
        DCANTestModeEnable(gDcanTxRx.instAddr, DCAN_TEST_MODE_MASK_LPBACK, FALSE);

        /* Disable DCAN DMA request lines */
        DCANAppDmaConfig(gDcanTxRx.instAddr, FALSE);

        CONSOLEUtilsPrintf("\nFrame reception complete");

        for(frameIndex = 0; frameIndex < numOfFrames; frameIndex++)
        {
            CONSOLEUtilsPrintf("\nFrame %02d data: ",frameIndex+1);
            for(byteIndex = 0; byteIndex < DCAN_MAX_BYTES_PER_FRAME; byteIndex++)
            {
                CONSOLEUtilsPrintf("%c", dstBuffer[(DCAN_MAX_BYTES_PER_FRAME * frameIndex) + byteIndex]);
            }
        }
    }
    else
        CONSOLEUtilsPrintf("Invalid input\n");
    return (status);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void DcanInfoGet(dcanAppCfgObj_t *pObj)
{
    pObj->instNum = 0;

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_DCAN, pObj->instNum))
    {
        /* Update the Interrupt Line number */
        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            pObj->appIntrCfg.intrLine = 84U;
            pObj->maxMsgObjs = 64U;
        }
        else if(SOC_FAMILY_ID_AM335X == SOCGetSocFamilyId())
        {
            pObj->appIntrCfg.intrLine = 52U;
            pObj->maxMsgObjs = 64U;
        }

        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_DCAN, pObj->instNum);
    }
}

static void DcanMsgTransfer(dcanAppCfgObj_t *pObj, uint32_t numOfFrames)
{
    uint32_t index = 0U;
    uint32_t startTx = 0U;

    pObj->appIntrCfg.intrCount = 1U;

    pObj->appCtrl.ctrlParams = gDcanRxCtrlParam;
    pObj->appCtrl.canId = DCAN_RX_MSG_ID;

    /*
    ** Configure a receive message object to accept CAN
    ** frames with standard ID.
    */
    DCANAppMsgObjectConfig(pObj, DCAN_DMA_MODE);

    pObj->appCtrl.ctrlParams = (DCAN_EXT_FRAME |
                                 DCAN_MSG_RX_DIR |
                                 DCAN_DATA_FRAME);

    pObj->appCtrl.canId = DCAN_RX_MSG_ID;

    /*
    ** Configure a receive message object to accept CAN
    ** frames with extended ID.
    */
    DCANAppMsgObjectConfig(pObj, DCAN_DMA_MODE);

    pObj->appIntrCfg.frameLen = DCAN_MAX_BYTES_PER_FRAME;
    pObj->appIntrCfg.totalFrames = numOfFrames;

    pObj->appCtrl.canId = gDcanId;
    pObj->appCtrl.ctrlParams = gDcanTxCtrlParam;
    pObj->appCtrl.dataLengthCode = DCAN_MAX_BYTES_PER_FRAME;

    for (index = 0U; index < numOfFrames; index++)
    {
        pObj->appIntrCfg.txCtrl = 1U;

        /* Configure a transmit message object */
        DCANAppMsgObjectConfig(pObj, DCAN_DMA_MODE);

        if(startTx == 0U)
        {
            /* Start the CAN transfer */
            DCANAppStartTransfer(pObj);

            startTx = 1U;
        }

        while(pObj->appIntrCfg.txCtrl);

        pObj->appIntrCfg.intrCount++;
    }
}

#ifdef RTOS_BUILD
Void dcanTestTask(UArg a0, UArg a1)
{
    dcanTest();
}

int main(void)
{
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(dcanTestTask, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    BIOS_start();    /* does not return */
    return 0;
}
#else
int main(void)
{
    dcanTest();
    return 0;
}
#endif

