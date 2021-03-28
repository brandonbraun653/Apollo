/**
 * \file     frame_tx_rx_app_main.c
 *
 * \brief    Example application main source file, which configures the DCAN IP
 *           to transmit or receive the CAN frames based on the users choice
 *           between 2 CAN nodes.
 *
 * \details  The example can be used to transmit or receive frames.
 *           If Transmit option is selected then either a single CAN frame
 *           where data bytes ranging from 1-8 bytes can be transmitted or
 *           transmit multiple CAN frames with data bytes in each frame fixed
 *           to 8.
 *           If application is configured to receive it can receive CAN frames
 *           with Standard or extended ID.
 *           The frames recived by the application will be looped back to the
 *           sender.
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *            http://www.ti.com/
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
#include "dcan.h"
#include "console_utils.h"

/* Application header files */
#include "dcan_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/**
 * \name    Macros used by DCAN application.
 */

/** @{ */
/** \brief DCAN connector instance number.
 */
#define DCAN_CONNECTOR_INST_NUM             (0U)

/** \brief Bitrate to be used on the CAN bus.
 */
#define DCAN_BIT_RATE                     (1000000U)

/** \brief Input clock used for the DCAN module.
 */
#define DCAN_INPUT_CLK                    (24000000U)

/** \brief Maximum data bytes allowed per frame.
 */
#define DCAN_MAX_BYTES_PER_FRAME          (8U)

/** \brief Receive message object ID.
 */
#define DCAN_RX_MSG_ID                    (0U)

/** \brief    Configure the transmit frame ID.
 *
 *  \details  This macro has to be commented if a CAN frame with extended ID
 *            has to be transmitted.
 */
#define DCAN_STD_ID
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief    Enumerates the values used to represent the number of messages
 *            to be transmitted.
 */
typedef enum dcanTxMsg
{
    DCAN_TX_MSG_SINGLE = 1U,
    /**< DCAN transmit Single message. */
    DCAN_TX_MSG_MULTIPLE = 2U
    /**< DCAN transmit multiple messages. */
} dcanTxMsg_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief     Fetch board information.
 *
 * \details   This function will check if DCAN support is present on the board
 *            and accordingly provide the DCAN controllers instance number
 *            and instance ID.
 *
 * \param     pObj       Pointer to the DCAN application configuration
 *                       structure.
 *
 * \retval    #S_PASS - DCAN support is present on the board.
 * \retVal    #E_FAIL - DCAN support is not present on the board.
 */
static int32_t DcanAppBoardInfoGet(dcanAppCfgObj_t *pObj);

/**
 * \brief     Fetch the DCAN instance address.
 *
 * \param     pObj       Pointer to the DCAN application configuration
 *                       structure.
 *
 * \retval    #S_PASS - DCAN instance is present.
 * \retVal    #E_FAIL - DCAN instance is not present.
 */
static int32_t DcanAppSocInfoGet(dcanAppCfgObj_t *pObj);

/**
 * \brief   Transmit CAN frames.
 *
 * \param   pObj       Pointer to the DCAN application configuration
 *                     structure.
 */
static void DcanFrameTransmit(dcanAppCfgObj_t *pObj);

/**
 * \brief   Receive CAN frames.
 *
 * \param   pObj       Pointer to the DCAN application configuration
 *                     structure.
 */
static void DcanFrameReceive(dcanAppCfgObj_t *pObj);

/**
 * \brief   Transfer single/multiple CAN frames.
 *
 * \param   pObj          Pointer to the DCAN application configuration
 *                        structure.
 * \param   numOfFrames   Single/Multiple frames to be transmitted.
 *          numOfFrames can take values from the following enum
 *          #dcanTxMsg_t
 */
static void DcanMsgTransfer(dcanAppCfgObj_t *pObj, uint32_t numOfFrames);

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

/** \brief Global object for the CAN Tx Rx application. */
static dcanAppCfgObj_t gDcanTxRx;

/* CAN frame details */
#ifdef DCAN_STD_ID
/* CAN frame control parameters for transmitting standard ID. */
static uint32_t gDcanTxCtrlParam = (DCAN_DATA_FRAME | DCAN_MSG_TX_DIR);
/* CAN frame standard ID. */
static uint32_t gDcanId = 0x01U;
#else
/* CAN frame control parameters for transmitting extended ID. */
static uint32_t gDcanTxCtrlParam = (DCAN_EXT_FRAME |
                                    DCAN_DATA_FRAME |
                                    DCAN_MSG_TX_DIR);
/* CAN frame extended ID. */
static uint32_t gDcanId = 0x2000U;
#endif
/* Variable to store CAN data. */
uint32_t gDcanData[2U];
/* CAN control parameters for receiving a frame. */
static uint32_t gDcanRxCtrlParam = (DCAN_DATA_FRAME | DCAN_MSG_RX_DIR);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = S_PASS;
    uint32_t index = 0U;
    uint32_t input = 0U;

    gDcanTxRx = DCANAPPTXRX_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare DCAN Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get board info */
    status = DcanAppBoardInfoGet(&gDcanTxRx);

    if (S_PASS == status)
    {
        /* Get SOC information. */
        status = DcanAppSocInfoGet(&gDcanTxRx);

        if (S_PASS == status)
        {
            /* Initialize the DCAN application. */
            status = DCANAppInit(&gDcanTxRx);

            if (S_PASS == status)
            {
                index = gDcanTxRx.maxMsgObjs;

                while(index > 0)
                {
                    /* Invalidate the DCAN message objects. */
                    DCANAppInvalidateMsgObject(gDcanTxRx.instAddr,
                                               index,
                                               DCAN_IF_REG_NUM_2);

                    index--;
                }

                index = 1U;

                while(1U == index)
                {
                    CONSOLEUtilsPrintf("Please Input\n1) CAN frame transmit\n");
                    CONSOLEUtilsPrintf("2) CAN frame receive\n\n");

                    CONSOLEUtilsPrintf("User Input = ");
                    CONSOLEUtilsScanf("%d", &input);
                    CONSOLEUtilsPrintf("\n\n");

                    switch(input)
                    {
                        case 1:DcanFrameTransmit(&gDcanTxRx);
                               index = 0U;
                               break;
                        case 2:DcanFrameReceive(&gDcanTxRx);
                               index = 0U;
                               break;
                        default:CONSOLEUtilsPrintf("Invalid option selected!!\n");
                               break;
                    }
                }
            }
            else
            {
                CONSOLEUtilsPrintf("\r\nFAILURE!!!\r\n");
                CONSOLEUtilsPrintf("DCAN application initialization Failed!!\n");
            }
        }
        else
        {
            /* DCAN support is not present on this SOC. */
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\r\nFAILURE!!!\r\n");
        CONSOLEUtilsPrintf("This example is not supported on this board\n");
    }
    return(status);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t DcanAppBoardInfoGet(dcanAppCfgObj_t *pObj)
{
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t dcanInstNum;

    /* Get the DCAN connector data on the board. */
    modId = BOARDGetDeviceCtrlModId(DEVICE_ID_DCAN_CONNECTOR,
                                    DCAN_CONNECTOR_INST_NUM);

    if (CHIPDB_MOD_ID_DCAN == modId)
    {
        dcanInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_DCAN_CONNECTOR,
                                                   DCAN_CONNECTOR_INST_NUM);

        if ((INVALID_INST_NUM == dcanInstNum))
        {
            CONSOLEUtilsPrintf("Invalid DCAN board data!\n");
        }
        else
        {
            CONSOLEUtilsPrintf("DCAN Instance number: %d\n", dcanInstNum);
            pObj->instNum = dcanInstNum;
            status = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Device is not available on this board!\n");
    }

    return (status);
}

static int32_t DcanAppSocInfoGet(dcanAppCfgObj_t *pObj)
{
    int32_t status = S_PASS;

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
            if(BOARD_ICEV2 == BOARDGetId())
            {
                pObj->appIntrCfg.intrLine = 52U;
            }
            else
            {
                pObj->appIntrCfg.intrLine = 55U;
            }
            pObj->maxMsgObjs = 64U;
        }
        else
        {
            CONSOLEUtilsPrintf("DCAN interrupts not supported on the SOC.\n");

            status = E_FAIL;
        }

        /* TODO: Need to update the interrupt Numberdata base of ChipDB */
        /*
        pObj->appIntrCfg.intrLine = ChipDBInterruptNum(CHIPDB_MOD_ID_DCAN,
                                          0, 0);
        */

        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_DCAN, pObj->instNum);
        CONSOLEUtilsPrintf("The instance address is %x\n", pObj->instAddr);
    }
    else
    {
        CONSOLEUtilsPrintf("DCAN support is not available on this SOC!\n");
    }

    return (status);
}

static void DcanMsgTransfer(dcanAppCfgObj_t *pObj, uint32_t numOfFrames)
{
    uint8_t *pDataCopy;
    uint32_t index = 0U;
    uint32_t startTx = 0U;
    /* Buffer used to hold CAN frame data for multiple frames. */
    uint32_t dataBuf[10U] = {0x30303030, 0x31313131, 0x32323232, 0x33333333,
                             0x34343434, 0x35353535, 0x36363636, 0x37373737,
                             0x38383838, 0x39393939};

    /* Buffer used to hold CAN frame data for a single frame. */
    uint8_t buffer[9U];

    pDataCopy = (uint8_t *) &gDcanData;

    pObj->appIntrCfg.intrCount = 1U;

    pObj->appCtrl.ctrlParams = gDcanRxCtrlParam;
    pObj->appCtrl.canId = DCAN_RX_MSG_ID;

    /*
    ** Configure a receive message object to accept CAN
    ** frames with standard ID.
    */
    DCANAppMsgObjectConfig(pObj, DCAN_MANUAL_MODE);

    pObj->appCtrl.ctrlParams = (DCAN_EXT_FRAME |
                                 DCAN_MSG_RX_DIR |
                                 DCAN_DATA_FRAME);

    pObj->appCtrl.canId = DCAN_RX_MSG_ID;

    /*
    ** Configure a receive message object to accept CAN
    ** frames with extended ID.
    */
    DCANAppMsgObjectConfig(pObj, DCAN_MANUAL_MODE);

    if (DCAN_TX_MSG_SINGLE == numOfFrames)
    {
        CONSOLEUtilsPrintf("Please input data not exceeding 8 characters\n");

        CONSOLEUtilsGets(buffer, (DCAN_MAX_BYTES_PER_FRAME + 1U));

        pObj->appIntrCfg.frameLen = 0U;

        while(buffer[pObj->appIntrCfg.frameLen] != '\0')
        {
            pDataCopy[pObj->appIntrCfg.frameLen] = buffer[pObj->appIntrCfg.frameLen];
            pObj->appIntrCfg.frameLen++;
        }

        CONSOLEUtilsPrintf("\r\n");

        /* Populate the can_frame structure with the CAN frame information */
        pObj->appCtrl.canId = gDcanId;
        pObj->appCtrl.ctrlParams = gDcanTxCtrlParam;
        pObj->appCtrl.dataLengthCode = pObj->appIntrCfg.frameLen;
        pObj->appCtrl.pData = (uint32_t *)gDcanData;

        pObj->appIntrCfg.totalFrames = 1U;

        /* Configure a transmit message object */
        DCANAppMsgObjectConfig(pObj, DCAN_MANUAL_MODE);

        /* Start the CAN transfer */
        DCANAppStartTransfer(pObj);
    }
    else if(DCAN_TX_MSG_MULTIPLE == numOfFrames)
    {
        pObj->appIntrCfg.frameLen = DCAN_MAX_BYTES_PER_FRAME;

        CONSOLEUtilsPrintf("Please enter the number of frames to be");
        CONSOLEUtilsPrintf(" transmitted:\r\n");
        CONSOLEUtilsScanf("%d", &pObj->appIntrCfg.totalFrames);
        CONSOLEUtilsPrintf("\n");

        pObj->appCtrl.canId = gDcanId;
        pObj->appCtrl.ctrlParams = gDcanTxCtrlParam;
        pObj->appCtrl.dataLengthCode = DCAN_MAX_BYTES_PER_FRAME;

        for (index = 0U; index < pObj->appIntrCfg.totalFrames; index++)
        {
            gDcanData[0U] = dataBuf[index % 10U];
            gDcanData[1U] = dataBuf[index % 10U];

            pObj->appCtrl.pData = (uint32_t *)gDcanData;

            pObj->appIntrCfg.txCtrl = 1U;
            pObj->appIntrCfg.rxCtrl = 1U;

            /* Configure a transmit message object */
            DCANAppMsgObjectConfig(pObj, DCAN_MANUAL_MODE);

            if(startTx == 0U)
            {
                /* Start the CAN transfer */
                DCANAppStartTransfer(pObj);

                startTx = 1U;
            }

            CONSOLEUtilsPrintf("%d%c", (index + 1U), ':');

            while(pObj->appIntrCfg.txCtrl || pObj->appIntrCfg.rxCtrl);

            pObj->appIntrCfg.intrCount++;
        }
    }
    else
    {
        /* Incorrect transmit frame selection. */
    }
}

static void DcanFrameTransmit(dcanAppCfgObj_t *pObj)
{
    uint32_t index = 1U;
    uint32_t input = 0U;

    while(1U == index)
    {
        CONSOLEUtilsPrintf("Please Input\n1) Transmit a single data frame\n");
        CONSOLEUtilsPrintf("2) Transmit 'n' data frames\n\nUser Input = ");

        CONSOLEUtilsScanf("%d", &input);
        CONSOLEUtilsPrintf("\n\n");

        switch(input)
        {
            case 1:DcanMsgTransfer(pObj, DCAN_TX_MSG_SINGLE);
                   index = 0U;
                   break;
            case 2:DcanMsgTransfer(pObj, DCAN_TX_MSG_MULTIPLE);
                   index = 0U;
                   break;
            default:CONSOLEUtilsPrintf("Invalid option selected!!\n");
                   break;
        }
    }
}

static void DcanFrameReceive(dcanAppCfgObj_t *pObj)
{
    pObj->appCtrl.appLoopBk = TRUE;

    CONSOLEUtilsPrintf("*** Waiting for data ***\n\n");

    /*
    ** Configure a receive message object to accept CAN
    ** frames with standard ID.
    */
    pObj->appCtrl.ctrlParams = gDcanRxCtrlParam;
    pObj->appCtrl.canId = DCAN_RX_MSG_ID;

    DCANAppMsgObjectConfig(pObj, DCAN_MANUAL_MODE);

    /*
    ** Configure a receive message object to accept CAN
    ** frames with extended ID.
    */
    pObj->appCtrl.ctrlParams = (DCAN_EXT_FRAME |
                                 DCAN_MSG_RX_DIR |
                                 DCAN_DATA_FRAME);

    pObj->appCtrl.canId = DCAN_RX_MSG_ID;

    DCANAppMsgObjectConfig(pObj, DCAN_MANUAL_MODE);

    /* Start the CAN transfer */
    DCANAppStartTransfer(pObj);
}
