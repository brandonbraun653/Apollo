/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 * 
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


#include <src/example.h>

PRUICSS_Handle pruIcssHandle;
ICSS_EmacHandle emachandle;

uint8_t lclMac[6];

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**PTP EDMA scratch memory offsets in L3 OCMC*/
#define IEP_CONFIG_ADJ_OFFSET               0xC200

/**
 * @def ECAP_CLR_CONFIG_OFFSET
 *      L3 OCMC memory offset where
 *      ECAP Config used for IEP adjustment is stored
 *      Size is 4 bytes
 */
#define ECAP_CLR_CONFIG_OFFSET              IEP_CONFIG_ADJ_OFFSET + 0x10

/*PTP min/max offset values*/
#define PTP_MIN_OFFSET_INIT_VAL     999999
#define PTP_MAX_OFFSET_INIT_VAL     -100000

TimeSync_ParamsHandle_t timeSyncHandle;

extern char *LocalIPAddr;
extern ICSS_EmacBaseAddrCfgParams icss_EmacBaseAddrCfgParams[3];

/* Static IP Address settings for Interface 0 */
char *ipAddr      = "192.168.1.4";
char *ipMask      = "255.255.255.0";
char *ipGateway   = "192.168.1.1";

/***********************************************************************/
/* local functions declaration                                         */
/***********************************************************************/
uint8_t timeSync_example_ICSS_EmacTestDrvInit(ICSS_EmacHandle handle, uint8_t instance);

void TaskFxn(UArg a0, UArg a1);

void timeSync_example_printConfig(ICSSEMAC_Handle emachandle)
{

    NIMU_IF_REQ device;
    uint8_t macId[6], check_ip = 1;
    char macAdd[32];

    device.index = 1;
    device.name[0] = 0;
    /*Print IP address, MAC address and UART menu options*/

    if(check_ip)
    {
        /*Print IP address*/
        UART_printf("\n\rIP Address \t: ");
        UART_printf(ipAddr);

        /*Print MAC address*/
        NIMUIoctl(NIMU_GET_DEVICE_MAC, &device, macId, sizeof(macId));
        sprintf(macAdd, "%x:%x:%x:%x:%x:%x", (char)macId[0], (char)macId[1],
                (char)macId[2], (char)macId[3], (char)macId[4], (char)macId[5]);
        UART_printf("\n\rMac Id \t\t: ");
        UART_printf(macAdd);
    }

    UART_printf("\n\rTime Sync Example Application Menu Options. Press key (Upper/Lower)\n");
    UART_printf("*******************************************\n\r");
    UART_printf("S : Show Statistics\n\r");
    UART_printf("H : Help menu. Shows details on all the options\n\r");
    UART_printf("P : Show PTP/1588 status\n\r");
    UART_printf("********************************************\n\r");

}

/*Used to track min/max offset from master
 * Useful for testing*/
int32_t min_offset = PTP_MIN_OFFSET_INIT_VAL;
int32_t max_offset = PTP_MAX_OFFSET_INIT_VAL;

void timeSync_example_monitorPTPStatus_Task(UArg arg0, UArg arg1)
{
    TimeSync_ParamsHandle_t timeSyncHandle = NULL;
    timeSyncHandle = (TimeSync_ParamsHandle_t)arg0;

    while(1)
    {
        if(timeSyncHandle->tsRunTimeVar->stateMachine &
                TS_STATE_MACHINE_DEVICE_IN_SYNC)
        {
            if(timeSyncHandle->tsRunTimeVar->currOffset < min_offset)
            {
                min_offset = timeSyncHandle->tsRunTimeVar->currOffset;
            }

            if(timeSyncHandle->tsRunTimeVar->currOffset > max_offset)
            {
                max_offset = timeSyncHandle->tsRunTimeVar->currOffset;
            }
        }

        TaskP_sleep(200);
    }
}


/**
 *  @brief  Function which checks if PTP is synchronized or not
 *
 *  @retval  None
 */
uint8_t timeSync_example_isGPTPSynchronized()
{

    if(timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_DEVICE_IN_SYNC)
    {
        return TRUE;
    }

    else
    {
        return FALSE;
    }
}


/* Tasks */

/**When clock goes into sync for very time
 * set this.
 */
uint8_t deviceInSync = 0;

/**If clock goes out of sync and dut was in sync
 * then set this*/
uint8_t ptpError = 0;

/**
 * @brief alive task - indicates running host processor by blinkind LED
 * also counts states and other conditions signaling
 *
 * @param arg0 not used
 * @param arg1 not used
 */
void timeSync_example_taskLedBlink(UArg arg0, UArg arg1)
{
    uint8_t dutInSync = 0;
    UART_printf("\n\rSYS/BIOS Time Sync Sample application: Creating timeSync_example_taskLedBlink ");

    /*First LED is used to indicate Time synchronization
     * and second LED is used to indicate Ring health
     */

    /*The sequence is like this for LED 0 (PTP LED)
     * PTP : Slow blinking Green : No master
     * PTP : Fast blinking Green : Synchronizing
     * PTP : Steady Green : Synchronized
     * PTP : Slow blinking Red : No master (recovered from fault)
     * PTP : Fast blinking Red : Synchronizing (recovered from fault)
     * PTP : Steady Red : Synchronized (recovered from fault)
     * PTP : Steady Blue : Is master
     */
    do
    {
        if(!timeSyncHandle->timeSyncConfig.isMaster)
        {
            /*Turn blue off*/
            Board_setTriColorLED(BOARD_TRICOLOR0_YELLOW, 0);

            dutInSync = timeSync_example_isGPTPSynchronized();

            if((TRUE == dutInSync) && (deviceInSync == 0))
            {
                deviceInSync = 1;
            }

            if((deviceInSync == 1) && (FALSE == dutInSync))
            {
                /*Turn green off*/
                Board_setTriColorLED(BOARD_TRICOLOR0_GREEN, 0);
                ptpError = 1;
            }

            if(dutInSync)
            {
                if(ptpError)
                {
                    Board_setTriColorLED(BOARD_TRICOLOR0_RED, 1);
                    TaskP_sleep(1000);
                }

                else
                {
                    Board_setTriColorLED(BOARD_TRICOLOR0_GREEN, 1);
                    TaskP_sleep(1000);
                }
            }

            else if(timeSyncHandle->tsRunTimeVar->stateMachine &
                    TS_STATE_MACHINE_FIRST_ADJUSTMENT_DONE)
            {
                if(ptpError)
                {
                    Board_setTriColorLED(BOARD_TRICOLOR0_RED, 0);
                    TaskP_sleep(200);
                    Board_setTriColorLED(BOARD_TRICOLOR0_RED, 1);
                    TaskP_sleep(200);
                }

                else
                {
                    Board_setTriColorLED(BOARD_TRICOLOR0_GREEN, 0);
                    TaskP_sleep(200);
                    Board_setTriColorLED(BOARD_TRICOLOR0_GREEN, 1);
                    TaskP_sleep(200);
                }

            }

            else
            {
                if(ptpError)
                {
                    Board_setTriColorLED(BOARD_TRICOLOR0_RED, 0);
                    TaskP_sleep(800);
                    Board_setTriColorLED(BOARD_TRICOLOR0_RED, 1);
                    TaskP_sleep(200);
                }

                else
                {
                    Board_setTriColorLED(BOARD_TRICOLOR0_GREEN, 0);
                    TaskP_sleep(800);
                    Board_setTriColorLED(BOARD_TRICOLOR0_GREEN, 1);
                    TaskP_sleep(200);
                }
            }

        }

        else
        {
            /*Turn green off*/
            Board_setTriColorLED(BOARD_TRICOLOR0_GREEN, 0);

            deviceInSync = 0;
            dutInSync = 0;
            Board_setTriColorLED(BOARD_TRICOLOR0_YELLOW, 1);
            TaskP_sleep(200);
            Board_setTriColorLED(BOARD_TRICOLOR0_YELLOW, 0);
            TaskP_sleep(800);
        }

    } while(1);

}

/**
 * @brief LED task for second LED
 *
 * @param arg0 not used
 * @param arg1 not used
 */
void timeSync_example_taskLedBlink2(UArg arg0, UArg arg1)
{
    UART_printf("\n\rSYS/BIOS Time Sync Sample application: Creating timeSync_example_taskLedBlink2 ");

    /*Give an initial delay to make sure LED's are initialized*/
    TaskP_sleep(1000);
    /**
     * Sequence for LED 1 (Device Status LED)
     * Blink second LED Green color on and off
     */
    Board_setTriColorLED(BOARD_TRICOLOR1_YELLOW, 0);
    Board_setTriColorLED(BOARD_TRICOLOR1_GREEN, 0);
    Board_setTriColorLED(BOARD_TRICOLOR1_RED, 0);

    while(1)
    {
        Board_setTriColorLED(BOARD_TRICOLOR1_GREEN, 0);
        TaskP_sleep(800);
        Board_setTriColorLED(BOARD_TRICOLOR1_GREEN, 1);
        TaskP_sleep(200);
    }
}


void timeSync_example_printPTPSubMenu(void)
{

    UART_printf("********************************************\n\r");
    UART_printf("\n\rPTP Sub Menu Options. Press key (Upper/Lower)\n");
    UART_printf("C : Change PTP configuration (to master if slave and vice versa)\n\r");
    UART_printf("S : Show PTP/1588 status\n\r");
    UART_printf("R : Reset min max values\n\r");
    UART_printf("********************************************\n\r");

}
/*This is kept in application for now*/
/**Temporary placeholder to copy packets*/
static uint8_t  tempFrame[ICSS_EMAC_MAXMTU];
/**PTP MAC ID for comparison*/
uint8_t timeSyncMAC[6] = {0x1, 0x1b, 0x19, 0x0, 0x0, 0x0};
uint8_t linkLocalMAC[6] = {0x1, 0x80, 0xc2, 0x0, 0x0, 0xE};

void timeSync_example_processHighPrioFrames(uint32_t *queue_number, void *userArg)
{

    int16_t size = 0;
    ICSS_EmacRxArgument rxArg;
    uint8_t *dstMacId;

    ICSSEMAC_Handle icssEmacHandle = timeSyncHandle->emacHandle;

    rxArg.icssEmacHandle = icssEmacHandle;
    rxArg.destAddress = (uint32_t)(tempFrame);
    rxArg.more = 0;
    rxArg.queueNumber = *queue_number;
    rxArg.port = TIMESYNC_TEST_PORT_NUM;

    if(((((ICSS_EmacObject *)
            icssEmacHandle->object)->callBackHandle)->rxCallBack)->callBack != NULL)
    {
        size = ((((ICSS_EmacObject *)
                  icssEmacHandle->object)->callBackHandle)->rxCallBack)->callBack(&rxArg,
                          ((((ICSS_EmacObject *)
                             icssEmacHandle->object)->callBackHandle)->rxCallBack)->userArg);
    }

    dstMacId = tempFrame;

    if(COMPARE_MAC(dstMacId, timeSyncMAC))
    {
        TimeSync_processPTPFrame(timeSyncHandle, tempFrame, rxArg.port, size, 0);
    }

    else if(COMPARE_MAC(dstMacId, linkLocalMAC))
    {
        TimeSync_processPTPFrame(timeSyncHandle, tempFrame, rxArg.port, size, 1);
    }

    else
    {
        /* No action */
    }
}

/***********************************************************************/
/* function definitions                                                */
/***********************************************************************/
void timeSync_example_port1linkResetCallBack(uint8_t linkStatus, void *arg2)
{
    /*
    Here arg2 already points to timeSyncHandle because of the registered callBack
    Yet, explicit usage of timeSyncHandle keeping futuristic approach wherein we 
    might want to add other callbacks and access to handles other than timeSyncHandle
    */

    TimeSync_Port1linkResetCallBack(linkStatus, (void *)(timeSyncHandle));
}

void timeSync_example_port2linkResetCallBack(uint8_t linkStatus, void *arg2)
{
    /*
    Here arg2 already points to timeSyncHandle because of the registered callBack
    Yet, explicit usage of timeSyncHandle keeping futuristic approach wherein 
    we might want to add other callbacks and access to handles other than timeSyncHandle
    */

    TimeSync_Port2linkResetCallBack(linkStatus, (void *)(timeSyncHandle));
}


void timesync_example_printPTPStatus(TimeSync_ParamsHandle_t timeSyncHandle)
{
    char pBuf[1024];
    uint64_t seconds = 0;
    uint32_t nanoseconds = 0;

    if(!TimeSync_isEnabled(timeSyncHandle))
    {
        UART_printf("\n\r PTP is disabled. Forgot to call ptpEnable() ?");
    }

    else
    {

        sprintf(pBuf, "\n\rPeer Delay on P1 :\t\t\t%d ns",
                (int)timeSyncHandle->tsRunTimeVar->pathDelay[0]);
        UART_printf(pBuf);
        sprintf(pBuf, "\n\rPeer Delay on P2 :\t\t\t%d ns",
                (int)timeSyncHandle->tsRunTimeVar->pathDelay[1]);
        UART_printf(pBuf);

        if(timeSyncHandle->timeSyncConfig.isMaster)
        {
            UART_printf("\n\r\n\r--------DUT configured as Master---------");
        }

        else
        {
            UART_printf("\n\r\n\r--------DUT configured as Slave---------");

            TimeSync_getCurrentTime(timeSyncHandle, &nanoseconds, &seconds);

            UART_printf("\n\r*********PTP/1588 Params********");
            sprintf(pBuf, "\n\rClock Drift :\t\t\t\t%d ns",
                    (int)timeSyncHandle->tsRunTimeVar->clockDrift);
            UART_printf(pBuf);
            sprintf(pBuf, "\n\rCurr offset :\t\t\t\t%d ns",
                    (int)timeSyncHandle->tsRunTimeVar->currOffset);
            UART_printf(pBuf);

            sprintf(pBuf, "\n\rMin offset :\t\t\t\t%d ns",
                    (int)min_offset);
            UART_printf(pBuf);
            sprintf(pBuf, "\n\rMax offset :\t\t\t\t%d ns",
                    (int)max_offset);
            UART_printf(pBuf);
            sprintf(pBuf, "\n\rNum Sync Missed :\t\t\t%d",
                    (int)(int)timeSyncHandle->numSyncMissed);
            UART_printf(pBuf);

            sprintf(pBuf, "\n\rUTC Offset (Seconds field) :\t\t%ld seconds",
                    (long int)seconds);
            UART_printf(pBuf);
            sprintf(pBuf, "\n\rMaster connected on Port :\t\t%d",
                    (int)timeSyncHandle->tsRunTimeVar->syncPortNum);
            UART_printf(pBuf);
            UART_printf("\n\r*******************************");

        }

    }
}


/*
 *  ---UART Menu task---
 */
void timeSync_example_taskUartMenu(UArg arg0, UArg arg1)
{
    ICSSEMAC_Handle emachandle;
    char rxByte;

    UART_printf("\n\rSYS/BIOS Time Sync Sample application: Creating timeSync_example_taskUartMenu ");

    /* Wait for PRU load complete */
    TaskP_sleep(3000);
    emachandle = (ICSSEMAC_Handle)arg0;

    while(1)
    {
        UART_printf("\n\r\n\r");
        timeSync_example_printConfig(emachandle);

        rxByte = (char) UART_getc();

        if((rxByte == 'P') || (rxByte == 'p'))
        {
            timeSync_example_printPTPSubMenu();
            rxByte = (char) UART_getc();

            if((rxByte == 's') || (rxByte == 'S'))
            {
                timesync_example_printPTPStatus(timeSyncHandle);
            }

            else if((rxByte == 'c') || (rxByte == 'C'))
            {
                if(timeSyncHandle->timeSyncConfig.isMaster)
                {
                    TimeSync_disableMaster(timeSyncHandle);
                    UART_printf("\n\r\n\r--------DUT configured as Slave---------");
                }

                else
                {
                    TimeSync_enableMaster(timeSyncHandle);
                    UART_printf("\n\r\n\r--------DUT configured as Master---------");
                }
            }

            else if((rxByte == 'r') || (rxByte == 'R'))
            {
                min_offset = PTP_MIN_OFFSET_INIT_VAL;
                max_offset = PTP_MAX_OFFSET_INIT_VAL;
                ptpError = 0;
                deviceInSync = 0;

                /*Turn red off*/
                Board_setTriColorLED(BOARD_TRICOLOR0_RED, 0);

            }

            else
            {
                UART_printf("\n\r\n\rSorry didnt catch that. Unknown input\n\r");
                UART_printf("\n\r");
            }


        }

        else if((rxByte == 'R') || (rxByte == 'r'))
        {
            //runRxTxTest(emachandle);

        }

        else if((rxByte == 'C') || (rxByte == 'c'))
        {
            /* This has RED configuration...what is RED configuration */
            /* timeSync_example_printConfiguration(emachandle); */

        }

        else if((rxByte == 'H') || (rxByte == 'h'))
        {
             UART_printf("\n\r\n\rTime Sync Example \n\r");

        }

        else
        {
            UART_printf("\n\r\n\rSorry didnt catch that. Unknown input\n\r");
            UART_printf("\n\r");
        }

    }
}

/*
 *    ---task to initialize PRU---
 */
Void timeSync_example_pruIcssTask(UArg a0, UArg a1)
{
    Uint8 firmwareLoad_done = FALSE;

    UART_printf("\n\rSYS/BIOS Time Sync Sample application: Creating timeSync_example_pruIcssTask ");

    /* setup the industrial LEDs */
    Board_i2cLedInit();
    gpioLedPinmuxConfig();

    GPIO_init();

    while(NIMU_ICSS_getNdkStatus(0)== NIMU_STAT_PROGRESS || NIMU_ICSS_getNdkStatus(0)==NIMU_STAT_UNKNOWN)
    {
        Task_sleep(100);
    }

    /* Load the firmware on the SOC*/
    firmwareLoad_done = timeSync_example_loadFirmware();

    if( firmwareLoad_done)
    {

        /*Packet processing callback*/
        ((((ICSS_EmacObject *)
           emachandle->object)->callBackHandle)->rxRTCallBack)->callBack =
               (ICSS_EmacCallBack)timeSync_example_processHighPrioFrames;
        ((((ICSS_EmacObject *)
           emachandle->object)->callBackHandle)->rxRTCallBack)->userArg = emachandle;

        TimeSync_drvInit(timeSyncHandle);

        /*Start PTP Engine*/
        TimeSync_drvEnable(timeSyncHandle);

        PRUICSS_pruEnable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(pruIcssHandle, ICSS_EMAC_PORT_2-1);

    }

    UART_printf("\n\rSYS/BIOS Time Sync Sample application: Firmware download and TimeSync Driver Init complete...\n ");

}

/**
 *  @brief  Function which calls an API in the event of a synchronization loss
 *
 *  @retval  None
 */
void timeSync_example_syncLossCallback()
{
    /*This indicates a loss of time sync
     Call your function here which handles sync loss*/
     return;
}

/**
 *  @brief  Function to initialize the PTP driver handle
 *
 *          Does Memory allocation, EDMA param configuration
 *
 *
 *  @param   timeSyncHandle   [in]  PTP driver handle
 *  @param   emachandle  [in]  EMAC LLD handle
 *
 *  @retval  Error status
 *
 */
int8_t timeSync_example_initICSSPtpHandle(TimeSync_ParamsHandle_t timeSyncHandle,
                                      ICSS_EmacHandle emachandle)
{
    int8_t returnVal = TIME_SYNC_OK;
    timeSyncHandle->emacHandle = emachandle;

    /*Configure PTP. These variables must be configured before doing anything else*/
    timeSyncHandle->timeSyncConfig.config = BOTH;
    timeSyncHandle->timeSyncConfig.type = P2P;
    timeSyncHandle->timeSyncConfig.protocol = IEEE_802_3;
    timeSyncHandle->timeSyncConfig.tickPeriod = 1000;
    timeSyncHandle->txprotocol = 0;
    timeSyncHandle->timeSyncConfig.icssVersion = timeSync_exampleSoCGetIcssVersion();

    timeSyncHandle->edmaConfig = (emdaConfig_t *)malloc(sizeof(emdaConfig_t));
    timeSyncHandle->edmaConfig->ecapPwmssBaseAddr = SOC_PWMSS1_IECAP_BASE;
    timeSyncHandle->edmaConfig->edmaEcapEvt0ChNum = 38U;
    timeSyncHandle->edmaConfig->edmaEcapEvt0LinkChNum = 39U;
    timeSyncHandle->edmaConfig->edmaEcapClearChNum = 40U;
    timeSyncHandle->edmaConfig->edmaEcapClearLinkChNum = 41U;

    /*scratch memory for ECAP EDMA IEP compensation scheme
     * the offsets are in L3 OCMC RAM and must not overlap with memory
     * used for queues*/
    timeSyncHandle->edmaConfig->iep_config_adj_offset = IEP_CONFIG_ADJ_OFFSET;
    timeSyncHandle->edmaConfig->iep_ecap_config_offset = ECAP_CLR_CONFIG_OFFSET;

    timeSyncHandle->tsSyntInfo = (timeSync_SyntInfo_t *)malloc(sizeof(
                                     timeSync_SyntInfo_t));

    if(timeSyncHandle->tsSyntInfo == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->tsNrrInfo[0] = (timeSync_NrrInfo_t *)malloc(sizeof(
                                       timeSync_NrrInfo_t));

    if(timeSyncHandle->tsNrrInfo[0] == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->tsNrrInfo[1] = (timeSync_NrrInfo_t *)malloc(sizeof(
                                       timeSync_NrrInfo_t));

    if(timeSyncHandle->tsNrrInfo[1] == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->syncParam[0] = (syncParam_t *)malloc(sizeof(syncParam_t));

    if(timeSyncHandle->syncParam[0] == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->syncParam[1] = (syncParam_t *)malloc(sizeof(syncParam_t));

    if(timeSyncHandle->syncParam[1] == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->tsRunTimeVar = (timeSync_RuntimeVar_t *)malloc(sizeof(
                                       timeSync_RuntimeVar_t));

    if(timeSyncHandle->tsRunTimeVar == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->delayParams = (delayReqRespParams_t *)malloc(sizeof(
                                      delayReqRespParams_t));

    if(timeSyncHandle->delayParams == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->offsetAlgo  = (timeSync_Offset_Stable_Algo_t *)malloc(sizeof(
                                      timeSync_Offset_Stable_Algo_t));

    if(timeSyncHandle->offsetAlgo == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    /*Allocate Rx and Tx packet buffers*/
    returnVal = TimeSync_alloc_PktBuffer(timeSyncHandle);

    if(returnVal != TIME_SYNC_OK)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    /*Set only if a custom Tx LLD API is used*/
    timeSyncHandle->timeSyncConfig.custom_tx_api = 0;
    /*Set to 1 if Rx timestamps are coming from shared RAM*/
    timeSyncHandle->timeSyncConfig.timestamp_from_shared_ram = 1;

    /* Emac mode else set to 0 */
    timeSyncHandle->timeSyncConfig.emac_mode = 1;


    timeSyncHandle->rxTimestamp_gPTP = (timeStamp *)malloc(sizeof(timeStamp));

    timeSyncHandle->timeSyncConfig.domainNumber[0] = 0;
    timeSyncHandle->timeSyncConfig.domainNumber[1] = 0;

    timeSyncHandle->timeSyncConfig.logAnnounceRcptTimeoutInterval =
        DEFAULT_ANNOUNCE_TIMEOUT_LOG_INTERVAL;
    timeSyncHandle->timeSyncConfig.logAnnounceSendInterval =
        DEFAULT_ANNOUNCE_SEND_LOG_INTERVAL;
    timeSyncHandle->timeSyncConfig.logPDelReqPktInterval =
        DEFAULT_PDELAY_REQ_LOG_INTERVAL;
    timeSyncHandle->timeSyncConfig.logSyncInterval = DEFAULT_SYNC_SEND_LOG_INTERVAL;
    /*No asymmetry*/
    timeSyncHandle->timeSyncConfig.asymmetryCorrection[0] = 0;
    timeSyncHandle->timeSyncConfig.asymmetryCorrection[1] = 0;
    timeSyncHandle->timeSyncConfig.pdelayBurstNumPkts =
        3;      /*3 frames sent in a burst*/
    timeSyncHandle->timeSyncConfig.pdelayBurstInterval =
        200;   /*gap between each frame is 100ms*/
    timeSyncHandle->timeSyncConfig.sync0_interval =
        1000000;      /*1 milisec value*/
    /*Register callback*/
    timeSyncHandle->timeSyncConfig.timeSyncSyncLossCallBackfn =
        (TimeSync_SyncLossCallBack_t)timeSync_example_syncLossCallback;

    /*Configure Master params*/
    timeSyncHandle->timeSyncConfig.isMaster = 0;
    timeSyncHandle->timeSyncConfig.masterParams.priority1 = TIMESYNC_DEFAULT_PRIO_1;
    timeSyncHandle->timeSyncConfig.masterParams.priority2 = TIMESYNC_DEFAULT_PRIO_2;
    timeSyncHandle->timeSyncConfig.masterParams.clockAccuracy =
        TIMESYNC_DEFAULT_CLOCK_ACCURACY; /*greater than 10s */
    timeSyncHandle->timeSyncConfig.masterParams.clockClass =
        TIMESYNC_DEFAULT_CLOCK_CLASS;
    timeSyncHandle->timeSyncConfig.masterParams.clockVariance =
        TIMESYNC_DEFAULT_CLOCK_VARIANCE;
    timeSyncHandle->timeSyncConfig.masterParams.stepRemoved =
        TIMESYNC_DEFAULT_STEPS_REMOVED;
    timeSyncHandle->timeSyncConfig.masterParams.UTCOffset = TIMESYNC_UTC_OFFSET;
    timeSyncHandle->timeSyncConfig.masterParams.timeSource =
        TIMESYNC_DEFAULT_TIME_SOURCE; /*Internal oscillator*/

    timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TIMESCALE_INDEX] =
        1;
    timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX] =
        1;

    return TIME_SYNC_OK;
}

uint8_t timeSync_example_ICSS_EmacTestDrvInit(ICSS_EmacHandle handle, uint8_t instance) {
    uint8_t retVal = (uint8_t) -1;

    /* LLD attributes mallocs */
    handle->object = (ICSS_EmacObject*)malloc(sizeof(ICSS_EmacObject));
    handle->hwAttrs= (ICSS_EmacHwAttrs*)malloc(sizeof(ICSS_EmacHwAttrs));

    /* Callback mallocs */
    ICSS_EmacCallBackObject* callBackObj = (ICSS_EmacCallBackObject*)malloc(sizeof(ICSS_EmacCallBackObject));

    callBackObj->learningExCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxRTCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->txCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    ((ICSS_EmacObject*)handle->object)->callBackHandle = callBackObj;

    /*Allocate memory for learning*/
    ((ICSS_EmacObject*)handle->object)->macTablePtr = (HashTable_t*)malloc(NUM_PORTS * sizeof(HashTable_t));

    /*Allocate memory for PRU Statistics*/
    ((ICSS_EmacObject*)handle->object)->pruStat = (ICSS_EmacPruStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacPruStatistics_t));

    /*Allocate memory for Host Statistics*/
    ((ICSS_EmacObject*)handle->object)->hostStat = (ICSS_EmacHostStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacHostStatistics_t));

    /*Allocate memory for Storm Prevention*/
    ((ICSS_EmacObject*)handle->object)->stormPrevPtr = (stormPrevention_t*)malloc(NUM_PORTS * sizeof(stormPrevention_t));

    /* Base address initialization */
    if(NULL == ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg) {
        ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg =
                        (ICSS_EmacBaseAddressHandle_T)malloc(sizeof(ICSS_EmacBaseAddrCfgParams));
    }
    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg;

    ICSS_EmacSocGetInitCfg((instance-1), emacBaseAddr );

    /*      Restricting l3OcmcBaseAddr to 0x40xxxx00.
      *  This is done because L3 OCMC Base Address must be 256 byte aligned and to support OCMC memory usage for Linux Power Management.
     */
    emacBaseAddr->dataRam0BaseAddr = icss_EmacBaseAddrCfgParams[instance -1].dataRam0BaseAddr;
    emacBaseAddr->dataRam1BaseAddr = icss_EmacBaseAddrCfgParams[instance -1].dataRam1BaseAddr;
    emacBaseAddr->l3OcmcBaseAddr =  icss_EmacBaseAddrCfgParams[instance - 1].l3OcmcBaseAddr;
    emacBaseAddr->prussCfgRegs =  icss_EmacBaseAddrCfgParams[instance -   1].prussCfgRegs;
    emacBaseAddr->prussIepRegs =  icss_EmacBaseAddrCfgParams[instance -   1].prussIepRegs;
    emacBaseAddr->prussIntcRegs = icss_EmacBaseAddrCfgParams[instance -   1].prussIntcRegs;
    emacBaseAddr->prussMiiMdioRegs = icss_EmacBaseAddrCfgParams[instance -1].prussMiiMdioRegs;
    emacBaseAddr->prussMiiRtCfgRegsBaseAddr = icss_EmacBaseAddrCfgParams[instance -1].prussMiiRtCfgRegsBaseAddr;
    emacBaseAddr->prussPru0CtrlRegs = icss_EmacBaseAddrCfgParams[instance - 1].prussPru0CtrlRegs;
    emacBaseAddr->prussPru1CtrlRegs = icss_EmacBaseAddrCfgParams[instance - 1].prussPru1CtrlRegs;
    emacBaseAddr->sharedDataRamBaseAddr = icss_EmacBaseAddrCfgParams[instance -1].sharedDataRamBaseAddr;
    ICSS_EmacSocSetInitCfg((instance-1), emacBaseAddr );
    return retVal;
}


/*
 *  ======== TAskFxn: FTP server init task ========
 */
void TaskFxn(UArg a0, UArg a1)
{
    UART_printf("\n\rSYS/BIOS Ethernet/IP (NIMU_ICSS) Sample application, EVM IP address I/F 0: %s\n\r", ipAddr);
    #ifdef idkAM572x
    UART_printf("\n\rSYS/BIOS Ethernet/IP (NIMU_ICSS) Sample application, EVM IP address I/F 1: %s\n\r", LocalIPAddr);
    #endif
}

/*
 * ======== stackInitHook ========
 * hook called from ti_nkd_config_Global_stackThread() to run user setup code
 */
typedef unsigned char UINT8;

void stackInitHook(HANDLE hCfg)
{
    CI_IPNET NA;
    CI_ROUTE RT;

    /* Add IP address for interface 1 */
    NA.IPAddr = inet_addr(ipAddr);
    NA.IPMask = inet_addr(ipMask);
    CfgAddEntry(hCfg, CFGTAG_IPNET, 1, 0, sizeof(CI_IPNET),
                (UINT8 *)&NA, 0);

    /*
     * Add gateway for interface 1
     * --> I *think* the below should work but you may need different values ...
     */
    bzero(&RT, sizeof(RT));
    RT.IPDestAddr = 0;
    RT.IPDestMask = 0;
    RT.IPGateAddr = inet_addr(ipGateway);

    CfgAddEntry(hCfg, CFGTAG_ROUTE, 0, 0,
                sizeof(CI_ROUTE), (UINT8 *)&RT, 0);

}

/*
 *  ======== main ========
 */
int main()
{
    TaskP_Params taskParams;
    int32_t ret;
    PRUICSS_Config  *pruIcssCfg;
    ICSS_EmacInitConfig* switchEmacCfg;

    Board_initCfg cfg;
    Board_IDInfo info;
    memset(&cfg, 0, sizeof(Board_initCfg));
    cfg = TIMESYNC_EXAMPLE_BOARD_CFG;

    Board_init(cfg);

    memset(&info, 0,sizeof(Board_IDInfo));
    Board_getIDInfo(&info);

#ifdef _TMS320C6X
    /* Clear pre-fetch bit in MAR to make OCMC un-cacheable */
    Cache_setMar((xdc_Ptr)0x4b000000U, 0x10000U, 0);
    Cache_setMar((xdc_Ptr)0x40000000U, 0x10000U, 0);
#endif

    UART_printf("\nTimeSync Driver Version - ");
    UART_printf(TIMESYNC_DRV_VERSION_STR);

    UART_printf("\nBoard name \t: ");
    UART_printf(info.boardName);

    UART_printf("\n\rChip Revision \t: ");
    UART_printf(info.version);

    /* Soc specific initialization for the platform */
    timeSync_example_socHwInit();

#ifdef _TMS320C6X
    /* Clear pre-fetch bit in MAR to make OCMC un-cacheable */
    Cache_setMar((xdc_Ptr)0x4b000000U, 0x10000U, 0);
    Cache_setMar((xdc_Ptr)0x40000000U, 0x10000U, 0);
#endif
    ret  = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if (ret  != PRUICSS_RETURN_SUCCESS)
        return (ret);
    pruIcssHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg,PRUICSS_INSTANCE);

    /*Port I initializations*/
    emachandle = (ICSS_EmacHandle)malloc(sizeof(ICSS_EmacConfig));

    switchEmacCfg = (ICSS_EmacInitConfig*)malloc(sizeof(ICSS_EmacInitConfig));

    if ((emachandle == NULL) || (switchEmacCfg == NULL))
    {
        UART_printf("main: malloc returned null\n");
    }

    /* Allocate the timesync module */\
    timeSyncHandle = (TimeSync_ParamsHandle_t)malloc(sizeof(TimeSync_ParamsHandle));
#if defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x)
    timeSync_example_crossbarConfig(TIMESYNC_TEST_PORT_NUM, PRUICSS_INSTANCE);
#endif
    timeSync_example_configureInterrupts(TIMESYNC_TEST_PORT_NUM, switchEmacCfg);

    timeSync_example_ICSS_EmacTestDrvInit(emachandle, ICSS_INSTANCE);

    if(timeSync_example_initICSSPtpHandle(timeSyncHandle, emachandle) != TIME_SYNC_OK)
    {
        System_abort("TimeSync memory allocation failed");
    }

    /*Registering Port 1 Link break callback */
    ICSS_EmacRegisterPort0ISRCallback(timeSyncHandle->emacHandle,
                                      (ICSS_EmacCallBack)timeSync_example_port1linkResetCallBack,
                                      (void *)(timeSyncHandle));
    /*Registering Port 2 Link break callback */
    ICSS_EmacRegisterPort1ISRCallback(timeSyncHandle->emacHandle,
                                      (ICSS_EmacCallBack)timeSync_example_port2linkResetCallBack,
                                      (void *)(timeSyncHandle));
    ((ICSS_EmacObject*)emachandle->object)->pruIcssHandle = pruIcssHandle;
    ((ICSS_EmacObject*)emachandle->object)->emacInitcfg = switchEmacCfg;

    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    if (TIMESYNC_TEST_PORT_NUM == 0)
    {
        ICSS_EmacInit(emachandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
    }
    else
    {
        ICSS_EmacInit(emachandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
    }
    TaskP_Params_init(&taskParams);
    taskParams.priority = 5;
    taskParams.name = (uint8_t *)"LEDTask";
    TaskP_create(timeSync_example_taskLedBlink, &taskParams);

    TaskP_Params_init(&taskParams);
    taskParams.priority = 5;
    taskParams.name = (uint8_t *)"LEDTask";
    TaskP_create(timeSync_example_taskLedBlink2, &taskParams);

    TaskP_Params_init(&taskParams);
    taskParams.priority = 15;
    taskParams.name = (uint8_t *) "SwitchTask";
    TaskP_create((Task_FuncPtr)timeSync_example_pruIcssTask, &taskParams);

    TaskP_Params_init(&taskParams);
    taskParams.priority = 1;
    taskParams.name = (uint8_t *)"UARTMenuTask";
    taskParams.arg0 = (void *)emachandle;
    TaskP_create(timeSync_example_taskUartMenu, &taskParams);

    TaskP_Params_init(&taskParams);
    taskParams.priority = 6;
    taskParams.arg0 = (void *)timeSyncHandle;
    taskParams.name = (uint8_t *)"PTPStatusTask";
    TaskP_create(timeSync_example_monitorPTPStatus_Task, &taskParams);

    TaskP_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.name = (uint8_t*)"port0_rxTaskFnc";
    taskParams.stacksize = 0x1000;
    taskParams.arg0 = (void *)emachandle;

    ((ICSS_EmacObject*)emachandle->object)->rxTaskHandle = TaskP_create((Task_FuncPtr)ICSS_EMacOsRxTaskFnc, &taskParams);

    if(((ICSS_EmacObject*)emachandle->object)->rxTaskHandle==NULL)
    {
        return -2;
    }
    TaskP_Params_init(&taskParams);
    taskParams.priority = 10;
    taskParams.name = (uint8_t*)"port0_linkTaskFnc";
    taskParams.stacksize = 0x1000;
    taskParams.arg0 = (void *)emachandle;
    ((ICSS_EmacObject*)emachandle->object)->linkTaskHandle = TaskP_create((Task_FuncPtr)ICSS_EMacOsLinkTaskFnc, &taskParams);

    if(((ICSS_EmacObject*)emachandle->object)->linkTaskHandle==NULL)
    {
        return -2;
    }

    PRUICSS_pinMuxConfig(pruIcssHandle, 0x0); // PRUSS pinmuxing

    TaskP_Params_init(&taskParams);
    taskParams.priority = 5;
    taskParams.stacksize = 0x1400;
    TaskP_create ((Task_FuncPtr)TaskFxn, &taskParams);

    if(OSDRV_addNetifEntry((NIMUInitFn)&NIMU_ICSS_EmacInit,emachandle) == 0)
        BIOS_exit(0);

    BIOS_start();
    return(0);
}


