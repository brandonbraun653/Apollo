/*
 *  Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
/**
 *  \file     dcan_loopback_rtos_main.c
 *
 *  \brief    This file contains the RTOS specific implementation for
 *			  executing the DCAN test
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/osal/RegisterIntr.h>

#include <ti/csl/example/dcan/dcanLoopback/dcan_loopback_app.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define DCAN_MAX_FRAMES (8U)

/* ========================================================================== */
/*                         Global Variables                                   */
/* ========================================================================== */

volatile uint32_t testDone = 1;
uint32_t gDcanAppInstance;
uint32_t msgLstErrCnt, dataMissMatchErrCnt, dcanRxErr = STW_EFAIL;
volatile uint32_t dcanRxDone;
uint32_t intrRegister;
int32_t  count;
extern char gMainMenuOption;

dcanRxParams_t appDcanRxPrms[DCAN_MAX_MSG_LENGTH];
dcanTxParams_t appDcanTxPrms[DCAN_MAX_MSG_LENGTH];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Configure the DCAN interrupts to interrupt controller.
 *
 */
void DCANAppConfigIntr(void);

/**
 * \brief   DCAN Interrupt 0 line service routine. This function will clear the
 *          status of the Tx/Rx message object interrupts. Handles the transmit
 *          interrupts and load the received data in buffer. Also checks for
 *          valid received data.
 *
 */
static void DCANAppIsr();

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 * ======== Receive DCAN Data ========
 */

uint32_t dcanReceiveData(uint32_t msgLstErrCnt, uint32_t dataMissMatchErrCnt, int16_t buffIndex)
{
    uint32_t dataLength = 0U, timeOut = 100U;
    int32_t retVal = STW_SOK;

    /* Wait for interface to become free */
    DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_RX_IF_REG);
	retVal = DCANGetData(gDcanAppInstance,
	                     DCAN_RX_MSG_OBJ,
                         DCAN_APP_RX_IF_REG,
                         &(appDcanRxPrms[buffIndex]),
                         timeOut);

    if (retVal == STW_SOK)
    {
        /* Check if sent data is lost or not */
		if (appDcanRxPrms[buffIndex].msgLostFlag == TRUE)
        {
            msgLstErrCnt++;
        }

        /* Check if sent data has been received */
        if (appDcanRxPrms[buffIndex].dataLength == appDcanTxPrms[buffIndex].dataLength)
        {
                while (dataLength < appDcanRxPrms[buffIndex].dataLength)
                {
                    if (appDcanRxPrms[buffIndex].msgData[dataLength] !=
                        appDcanTxPrms[buffIndex].msgData[dataLength])
                    {
                        retVal = STW_EFAIL;
                        dataMissMatchErrCnt++;
                    }
                    dataLength++;
                }
        }
        else
        {
            retVal = STW_EFAIL;
        }
    }
    return retVal;
}

/*
 * ======== DCAN Loopback Test ========
 */

int32_t dcanLoopbackTest(void)
{
    int32_t               retVal    = STW_SOK;
    int32_t               errStatus = STW_SOK;
    dcanCfgParams_t       appDcanCfgPrms;
    dcanMsgObjCfgParams_t appDcanTxCfgPrms;
    dcanMsgObjCfgParams_t appDcanRxCfgPrms;
    dcanBitTimeParams_t   appDcanBitTimePrms;
    uint32_t timeOut = 100U, numOfFrames;;
    int16_t i, frameIndex, byteIndex;
    volatile uint8_t txBuffer[DCAN_MAX_FRAMES * DCAN_MAX_MSG_LENGTH];
    uint8_t buff[DCAN_MAX_MSG_LENGTH];

    numOfFrames=0;

    if (gDcanAppInstance == DCAN1_APP_INST)
    {
        PRINT_MSG("\nDCAN External Loopback Test App: DCAN1 MSG OBJ 1 (TX) to DCAN1 MSG OBJ 2 (RX)\n");
#if defined (__TI_ARM_V7M4__)
        /* DRM_SUSPEND_CTRL_DCAN1 - SUSPEND_SEL(Suspend source selection) as
         * IPU1_C0
         * & SENS_CTRL(Sensitivity control) as 1 means suspend signal must reach
         * the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN1,
                    ((DRM_SUSPEND_SRC_IPU1_C0 << 4) | 0x1));
#elif defined (__ARM_ARCH_7A__)
        /* DRM_SUSPEND_CTRL_DCAN1 - SUSPEND_SEL(Suspend source selection) as
         * MPU_C0
         * & SENS_CTRL(Sensitivity control) as 1 means suspend signal must reach
         * the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN1,
                    ((DRM_SUSPEND_SRC_MPU_C0 << 4) | 0x1));
#elif defined (_TMS320C6X)
        /* DRM_SUSPEND_CTRL_DCAN1 - SUSPEND_SEL(Suspend source selection) as
         * DSP1
         * & SENS_CTRL(Sensitivity control) as 1 means suspend signal must reach
         * the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN1,
                    ((DRM_SUSPEND_SRC_C66_C0 << 4) | 0x1));
#endif
    }
    else
    {
        PRINT_MSG("\nDCAN Internal Loopback Test App: DCAN2 MSG OBJ 1 (TX) to DCAN2 MSG OBJ 2 (RX)\n");
#if defined (__TI_ARM_V7M4__)
        /* DRM_SUSPEND_CTRL_DCAN2 - SUSPEND_SEL(Suspend source selection) as
         * IPU1_C0 & SENS_CTRL(Sensitivity control) as 1 means suspend signal
         *  must reach the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN2,
                    ((DRM_SUSPEND_SRC_IPU1_C0 << 4) | 0x1));
#elif defined (__ARM_ARCH_7A__)
        /* DRM_SUSPEND_CTRL_DCAN2 - SUSPEND_SEL(Suspend source selection) as
         * MPU_C0 & SENS_CTRL(Sensitivity control) as 1 means suspend signal
         * must reach the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN2,
                    ((DRM_SUSPEND_SRC_MPU_C0 << 4) | 0x1));
#elif defined (_TMS320C6X)
        /* DRM_SUSPEND_CTRL_DCAN2 - SUSPEND_SEL(Suspend source selection) as
         * DSP1 & SENS_CTRL(Sensitivity control) as 1 means suspend signal
         * must reach the peripheral-IP  */
        HW_WR_REG32(DRM_SUSPEND_CTRL_DCAN2,
                    ((DRM_SUSPEND_SRC_C66_C0 << 4) | 0x1));
#endif
    }
    PRINT_MSG("\nEnter the number of frames to be transmitted(1 to 8):");
    SCAN_MSG("%d",&numOfFrames);
    if((numOfFrames > DCAN_MAX_FRAMES) || (numOfFrames <= 0))
    {
        PRINT_MSG("\nEnter a number between 1 to 8\n");
        return -1;
    }
    for(byteIndex = 0; byteIndex < numOfFrames; byteIndex++)
    {
		memset(buff, 0, sizeof(buff));
		PRINT_MSG("Please enter exactly 8 characters for frame[%02d]: ", (byteIndex+1));
		SCAN_MSG("%s",buff);
		for(frameIndex = 0; frameIndex < DCAN_MAX_MSG_LENGTH; frameIndex++)
		{
			txBuffer[(DCAN_MAX_MSG_LENGTH * byteIndex ) + frameIndex] = buff[frameIndex];
		}
    }
    DCANAppInitParams(&appDcanCfgPrms,
                    &appDcanTxCfgPrms,
                    &appDcanRxCfgPrms,
                    &appDcanTxPrms[0],
                    gMainMenuOption);

    if (gDcanAppInstance == DCAN1_APP_INST)
    {
        DCAN1Prcm_clck_ram();
    }
    else
    {
        DCAN2Prcm_clck_ram();
    }

    /* Reset the DCAN IP */
    retVal = DCANReset(gDcanAppInstance, timeOut);
    if (retVal == STW_SOK)
    {
        /* Set the desired bit rate based on input clock */
        DCANSetMode(gDcanAppInstance, DCAN_MODE_INIT);
        errStatus = DCANCalculateBitTimeParams(DCAN_APP_INPUT_CLK,
                                                DCAN_APP_BIT_RATE,
                                                &appDcanBitTimePrms);
        if (errStatus != DCAN_BIT_RATE_ERR_NONE)
        {
            return errStatus;
        }
        DCANSetBitTime(gDcanAppInstance, &appDcanBitTimePrms);
        DCANSetMode(gDcanAppInstance, DCAN_MODE_NORMAL);

        /* Configure DCAN controller */
        DCANConfig(gDcanAppInstance, &appDcanCfgPrms);
    }

    count = 0;
    /* Frame Transmission */
    for(byteIndex = 0; byteIndex < numOfFrames; byteIndex++)
    {
        dcanRxDone = FALSE;
        for(i=0; i<DCAN_MAX_MSG_LENGTH; i++)
        {
            appDcanTxPrms[byteIndex].msgData[i] = txBuffer[(DCAN_MAX_MSG_LENGTH * byteIndex)+i];
        }
        appDcanTxPrms[byteIndex].dataLength = DCAN_MAX_MSG_LENGTH;

		if (retVal == STW_SOK)
		{
			/* Wait for interface to become free */
			DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_RX_IF_REG);
			retVal = DCANConfigMsgObj(gDcanAppInstance,
									DCAN_RX_MSG_OBJ,
									DCAN_APP_RX_IF_REG,
									&appDcanRxCfgPrms);

			/* Wait for config to be copied to internal message RAM */
			DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_RX_IF_REG);
		}
		if (retVal == STW_SOK)
		{
			/* Wait for interface to become free */
			DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
			retVal = DCANConfigMsgObj(gDcanAppInstance,
									DCAN_TX_MSG_OBJ+(uint32_t)byteIndex,
									DCAN_APP_TX_IF_REG,
									&appDcanTxCfgPrms);
			/* Wait for config to be copied to internal message RAM */
			DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
		}
		/* Set the Clear interrupt pending bit */
		DCANIntrClearStatus(gDcanAppInstance, DCAN_RX_MSG_OBJ, DCAN_APP_RX_IF_REG);
		DCANIntrClearStatus(gDcanAppInstance, DCAN_TX_MSG_OBJ+(uint32_t)count, DCAN_APP_TX_IF_REG);
		if (retVal == STW_SOK)
		{
			/* Wait for interface to become free */
			DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
			retVal = DCANTransmitData(gDcanAppInstance,
									DCAN_TX_MSG_OBJ+(uint32_t)byteIndex,
									DCAN_APP_TX_IF_REG,
									&appDcanTxPrms[byteIndex],
									timeOut);
			count = byteIndex;

			/* Wait for config to be copied to internal message RAM */
			DCANAppWaitForIfReg(gDcanAppInstance, DCAN_APP_TX_IF_REG);
			while((dcanRxDone == FALSE));
			if(dcanRxErr != STW_SOK )
				break;
		}
    }/* End Of Transmission */

    if (((msgLstErrCnt == 0) &&
         (dataMissMatchErrCnt == 0)) && (dcanRxErr == STW_SOK))
    {
        if (gMainMenuOption == DCAN_EXT_LOOPBACK_TEST)
        {
            PRINT_MSG("\nDCAN -- External Loopback Testmode test Passed!! \n");
        }
        else
        {
            PRINT_MSG("\nDCAN -- Internal Loopback Testmode test Passed!! \n");
        }
    }
    else
    {
        if (gMainMenuOption == DCAN_EXT_LOOPBACK_TEST)
        {
            PRINT_MSG("\nDCAN -- External Loopback Testmode test Failed!! \n");
        }
        else
        {
            PRINT_MSG("\nDCAN -- Internal Loopback Testmode test Failed!! \n");
        }
    }
    PRINT_MSG("\nReceived Frames are:\n");
	for(byteIndex = 0; byteIndex < numOfFrames; byteIndex++)
    {

        PRINT_MSG("\nFrame[%02d]: ", (byteIndex+1));
        for(i = 0; i < DCAN_MAX_MSG_LENGTH; i++)
            PRINT_MSG("%c", appDcanRxPrms[byteIndex].msgData[i]);
        PRINT_MSG("\n");
    }
    return retVal;
}

/*
 *  ======== DCANAppConfigIntr ========
 */
void DCANAppConfigIntr(void)
{
    CSL_XbarIrq intrSource;
    OsalRegisterIntrParams_t interruptRegParams;
    HwiP_Handle hwiPHandlePtr;
    int32_t retVal = 0;

    if (gDcanAppInstance == DCAN1_APP_INST)
    {
        /* Interrupt source for DCAN instance1 */
        intrSource = CSL_XBAR_DCAN1_IRQ_INT0;
    }
    else
    {
        /* Interrupt source for DCAN instance2 */
        intrSource = CSL_XBAR_DCAN2_IRQ_INT0;
    }
    /* XBar configuration */
#if defined (__ARM_ARCH_7A__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_50, intrSource);
#elif defined (__TI_ARM_V7M4__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_30, intrSource);
#elif defined (_TMS320C6X)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_XBAR_INST_DSP1_IRQ_50, intrSource);
#endif

        /* Initialize with defaults */
        Osal_RegisterInterrupt_initParams(&interruptRegParams);

        /* Populate the interrupt parameters */
        interruptRegParams.corepacConfig.arg = NULL;
        interruptRegParams.corepacConfig.name = NULL;
        interruptRegParams.corepacConfig.isrRoutine = DCANAppIsr;
        interruptRegParams.corepacConfig.priority = 0x20U;
#if defined (__ARM_ARCH_7A__) /* Interrupt Parameters specific to ARM core */
        interruptRegParams.corepacConfig.triggerSensitivity =  OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
        interruptRegParams.corepacConfig.intVecNum = 82; /* Corresponds to MPU_IRQ_50 (32 + MPU_IRQ_50) */
        interruptRegParams.corepacConfig.corepacEventNum = 0;
#elif defined (__TI_ARM_V7M4__) /* Interrupt Parameters specific to M4 core */
        interruptRegParams.corepacConfig.intVecNum = 30; /* Corresponds to IPU1_IRQ_30 */
        interruptRegParams.corepacConfig.corepacEventNum = 0;
#elif defined (_TMS320C6X) /* Interrupt Parameters specific to DSP core */
        interruptRegParams.corepacConfig.intVecNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
        interruptRegParams.corepacConfig.corepacEventNum = 50; /* Corresponds to DSP1_IRQ_50 */
#endif
        /* Register interrupts */
        if( !intrRegister )
        {
        retVal = Osal_RegisterInterrupt(&interruptRegParams, &hwiPHandlePtr);
        if(retVal != OSAL_INT_SUCCESS) {
            PRINT_MSG("\n\nError: Osal_RegisterInterrupt Failed!!!");
        }
        else
            intrRegister = (uint32_t) TRUE;
        }
}
/*
 *  ======== DCANAppIsr ========
 */
static void DCANAppIsr(void)
{
    int32_t retVal = STW_EFAIL;

    msgLstErrCnt = 0U;
    dataMissMatchErrCnt = 0U;
    dcanRxErr = STW_EFAIL;

    if(DCANHasRxMsgArrived(gDcanAppInstance, DCAN_RX_MSG_OBJ) == TRUE)
    {
        retVal = dcanReceiveData(msgLstErrCnt, dataMissMatchErrCnt, count);
        if (retVal == STW_SOK)
        {
            DCANGetErrStatus(gDcanAppInstance);
        }
        dcanRxErr = retVal;
        /* Set the Receive complete Flag */
        dcanRxDone = (uint32_t) TRUE;
    }
	DCANIntrClearStatus(gDcanAppInstance, DCAN_RX_MSG_OBJ, DCAN_APP_RX_IF_REG);
	DCANIntrClearStatus(gDcanAppInstance, DCAN_TX_MSG_OBJ+(uint32_t)count, DCAN_APP_TX_IF_REG);
}

/*
 *  ======== dcanTestTask ========
 */
Void dcanTestTask(UArg a0, UArg a1)
{
    int32_t retVal = STW_EFAIL;

    /* DCAN Test function call*/
    retVal = execTest();
    if(retVal == STW_SOK)
        while (testDone) ;
}

/*
 *  ======== main ========
 */
Int main()
{
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);
    /* Create Task to run the DCAN Loopback Test */
    task = Task_create(dcanTestTask, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
    BIOS_start();    /* does not return */
    return(0);
}

/********************************* End of file ******************************/
