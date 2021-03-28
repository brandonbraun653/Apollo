/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *  \file  usb_host_test.c
 *
 *  \brief usb host diagnostic test file
 *
 *  Operation: This application code is the main routine for device
 *  mass storage class example. This layer enables the clocks
 *  for USB mass storage device, implements phy on logic
 *  and configures the interrupts for USB.
 *  This layer will read all the incoming interrupts and pass
 *  this interrupts to the lower layers to be processed and
 *  the required actions are taken by the lower layer.
 *
 *  Supported SoCs: AM65xx.
 *
 *  Supported Platforms: am65xx_evm & am65xx_idk.
 *
 */

#include "usb_host_test.h"

/**
 *  \brief    main entry point for USB core interrupt handler  
 *
 *  \param    pUsbParam           [IN]       USB Parameters
 *
 */
void usbCoreIntrHandler(void* pUsbParam)
{
#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
    /*
     * ARM9 core does not support passing arguments to ISR handler.
     * The arugument *pUsbParam is not valid for ARM9 core.
     */

    /*Clears the interrupt*/
    usb_osalClearInterrupt(SYS_INT_USB0);

    USB_coreIrqHandler(usb_host_params.usbHandle,
                        &usb_host_params);
#else
    USB_coreIrqHandler(((USB_Params*)pUsbParam)->usbHandle, 
                        (USB_Params*)pUsbParam);
#endif
}

/**
 *  \brief      callback from the MSC driver  
 *
 *  \param      ulInstance         [IN]       USB instance used
 *              ulEvent            [IN]       one of the events defined
 *                                            by the driver.
 *              pvData             [IN]       pointer to data passed into
 *                                            the initial call to register
 *
 *  \operation    This function handles callback events from the MSC driver.
 *    The only events currently handled are the MSC_EVENT_OPEN and 
 *    MSC_EVENT_CLOSE.This allows the main routine to know when an MSC device
 *    has been detected and enumerated and when an MSC device has been removed
 *    from the system.
 *
 */
void MSCCallback(void *ulInstance, uint32_t ulEvent, void *pvData)
{
    /* Determine the event.*/
    switch(ulEvent)
    {
        /* Called when the device driver has successfully enumerated an MSC
           device.*/
        case MSC_EVENT_OPEN:
        {
            /* Proceed to the enumeration state.*/
            g_eState = STATE_DEVICE_ENUM;
            break;
        }
        /* Called when the device driver has been unloaded due to error or
           the device is no longer present.*/
        case MSC_EVENT_CLOSE:
        {
            /* Go back to the "no device" state and wait for a new connection.*/
            g_eState = STATE_NO_DEVICE;
            break;
        }

        default:
        {
            break;
        }
    }
}

/**
 *  \brief    Used to register interrupt for USB host
 *
 *  \param    usbParams        [IN]      Parameters used 
 *                                       for configuring USB
 *
 */
static void usbHostIntrConfig(USB_Params* usbParams)
{
#if defined(SOC_AM65XX)
    /* we are not utilizing interrupt in host mode for xHCI yet.
       if we enable interrupt, the interrupt pre-empts the main while loop that
       handles the USB host events. So return here */
    return;

#else
#if defined(_TMS320C6X)

    HwiP_Handle hwiHandle = NULL;
    OsalRegisterIntrParams_t interruptRegParams;

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.name=NULL;
    interruptRegParams.corepacConfig.corepacEventNum=SYS_INT_USB0; /* Event going in to CPU */
    interruptRegParams.corepacConfig.intVecNum= OSAL_REGINT_INTVEC_EVENT_COMBINER; /* Host Interrupt vector */
    interruptRegParams.corepacConfig.isrRoutine = (void (*)(uintptr_t))usbCoreIntrHandler;
    interruptRegParams.corepacConfig.arg = (uintptr_t)usbParams;

    Osal_RegisterInterrupt(&interruptRegParams,&hwiHandle);

#else
    int32_t mainIntNo = 0;
    HwiP_Params hwiInputParams;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
    hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)usbParams;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;
   
    if (usbParams->instanceNo == 0) 
    {
        mainIntNo = SYS_INT_USB0;
    } 
#if !defined(SOC_OMAPL137) && !defined(SOC_OMAPL138)
    else 
    {
        mainIntNo = SYS_INT_USB1;
    }

    hwiInputParams.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif


    usb_osalRegisterInterrupt(mainIntNo,
                              (HwiP_Fxn)usbCoreIntrHandler,
							  &hwiInputParams);
#endif


#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
    /* configure the interrupt router for MCU (R5) build */
    usb_configIntRouter(usbParams->instanceNo);
#endif

    USB_irqConfig(usbParams->usbHandle, usbParams);
#endif   
}

void setupMMUForUSB()
{
#if defined(evmAM437x)
    /* this is the USB IP memory. Map it just in case the MMU example has not done so */
    static mmuMemRegionConfig_t regionDev =
            {   
                0x48380000,     /* USB0 & USB1 */
                2,              /* Number of pages */
                1U*MEM_SIZE_MB, /* Page size - 1MB */
                MMU_MEM_ATTR_DEVICE_SHAREABLE,
                MMU_CACHE_POLICY_WB_WA, /* Inner - Invalid here */
                MMU_CACHE_POLICY_WB_WA, /* Outer - Invalid here */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

    /* this is the noncached area that the DWC driver uses */
    static mmuMemRegionConfig_t regionDDR =
            {   
                0xA0000000,     /* APP_UNCACHED_DATA_BLK3_MEM */
                2,              /* Number of pages */
                1U*MEM_SIZE_MB, /* Page size - 1MB */
                MMU_MEM_ATTR_DEVICE_SHAREABLE,
                MMU_CACHE_POLICY_WB_WA, /* Inner - Invalid here */
                MMU_CACHE_POLICY_WB_WA, /* Outer - Invalid here */
                MMU_ACCESS_CTRL_PRV_RW_USR_RW,
                FALSE /* Non Secure memory */
            };

    MMUMemRegionMap(&regionDev, (uint32_t*)pageTable);
    MMUMemRegionMap(&regionDDR, (uint32_t*)pageTable);

#endif

#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
    /* Sets up 'Level 1" page table entries.*/
    uint32_t index;
	for(index = 0; index < (4*1024); index++)
    {
        pageTable[index] = (index << 20) | 0x00000C12;
    }

    /* Disable Instruction Cache*/
	CSL_CP15ICacheDisable();

    /* Configures translation table base register
	* with pagetable base address.
	*/
    CSL_CP15TtbSet((unsigned int )pageTable);

    /* Enables MMU */
    CSL_CP15MMUEnable();

	/* Enable Data Cache */
    CSL_CP15DCacheEnable();
#endif
}
/**
 *  \brief    Opens the USB Driver and performs the fat fs read write test
 *            to verify USB Host test.
 *
 *  \return   int8_t
 *               0 - on data comparison match
 *              -1 - on data comparison mismatch.
 *
 */
int8_t BoardDiag_run_usbHost_test(void)
{
#if !(defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138)))
    USB_Params  usb_host_params;
#endif
    USB_Handle  usb_handle;
    int         rc;
    int8_t ret = -1;
#if !defined(DIAG_COMPLIANCE_TEST)
#if ((defined (am65xx_idk)) || (defined (am65xx_evm)))
    uint8_t appBoard;
    bool boardConnect = false;
#endif
#endif
#ifdef DIAG_STRESS_TEST
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;
#endif

#if !defined(DIAG_COMPLIANCE_TEST)
#if defined(am65xx_evm)
    Board_STATUS status;
    USB_Config* usb_config;
#endif
#endif

#if (defined(evmAM335x) || defined (evmAM437x))
	MMUConfigAndEnable();
#endif

#if (!(defined(SOC_AM65XX)))
    /* set up MMU page for APP_UNCACHED_DATA_BLK3_MEM and for USB */
    setupMMUForUSB();
#endif

    /* Enable Data Cache */
#if (defined(evmAM335x) || defined (evmAM437x))
    CACHEEnable(CACHE_DCACHE, CACHE_INNER_OUTER);
#endif

    /* setup timer for delay and timer functions */
    delayTimerSetup();

    UART_printf("\nUSB Host MSC example!!\n\n");

#if !defined(DIAG_COMPLIANCE_TEST)
    while(!boardConnect)
    {
        UART_printf("Select the options below on which application has to be run\n\n"
                    "1.CP board\n2.Serdes Board\n");
        UART_scanFmt("%d",&appBoard);
        if(appBoard == 1)
        {
            usb_host_params.instanceNo   = USB_INSTANCE_CP;
            boardConnect = true;
        }
        else if(appBoard == 2)
        {
/* Enable USB30 bit for USB3.0 configuration  */
#if defined(am65xx_evm)
    BoardDiag_enableI2C(0, CSL_WKUP_I2C0_CFG_BASE);
    /* Check if SerDes application card is detected */
    if(Board_detectBoard(SERDES_BRD_DETECT))
    {
        status = Board_init(BOARD_INIT_SERDES_PHY);
        if(status != BOARD_SOK)
        {
            return -1;
        }
        USB_getConfig(USB_INSTANCE_SER, &usb_config);

        if (usb_config!=0)
        {
            usb_config->usb30Enabled = 1;
        }
    }
    else
    {
        UART_printf("\nSerDes Application Card not Connected!!\n");
        UART_printf("Exiting the Test...\n");
        return -1;
    }
    BoardDiag_enableI2C(0, CSL_I2C0_CFG_BASE);
#endif
            usb_host_params.instanceNo   = USB_INSTANCE_SER;
            boardConnect =  true;
        }
        else
        {
            UART_printf("Please enter a valid option\n");
            boardConnect = false;
        }
    }
#else
	usb_host_params.instanceNo   = USB_INSTANCE_CP;
#endif

    usb_host_params.usbMode      = USB_HOST_MSC_MODE;

    usb_handle = USB_open(usb_host_params.instanceNo, &usb_host_params);

    if (usb_handle == 0) 
    {
        /* failed to open the USB driver */
        return ret;
    }

    /* Setup the INT Controller */
    usbHostIntrConfig (&usb_host_params);

    /* Initialize the file system. */
    FATFS_init();

    /* Open an instance of the mass storage class driver.*/
    g_ulMSCInstance = USBHMSCDriveOpen(usb_host_params.instanceNo, 0, MSCCallback);

    while(1)
    {
        rc = USBHCDMain(usb_host_params.instanceNo, g_ulMSCInstance);
        if (rc != NO_ERROR)
        {
            UART_printf("USBHCDMain failed with this error: 0x%x\n", rc);
            break;
        }

        if(g_eState == STATE_DEVICE_ENUM)
        {
            /* Take it easy on the Mass storage device if it is slow to
             start up after connecting.*/

            if(USBHMSCDriveReady(g_ulMSCInstance) != 0)
            {
                /* Wait about 100ms before attempting to check if the
                   device is ready again.*/
                usb_osalDelayMs(100);
            }

            /* USBMSC FATFS initialization */
            FATFS_open(0U, NULL, &fatfsHandle);
#ifdef DIAG_STRESS_TEST

            UART_printf("\n\nRunning USB Host Sensor Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
            UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

            for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
            {
                /* Check if there a input from console to break the test */
                rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
                if((rdBuf == 'b') || (rdBuf == 'B'))
                {
                    UART_printf("Received Test Termination... Exiting the Test\n");
                    iteration++;
                    break;
                }

                ret = FSShellAppUtilsCmdMkTxtFile();
                if (ret == 0)
                {
                    UART_printf("\n\n\n\nIteration : %d USB Host Sensor Test Passed\n",iteration);
                    passCount++;
                }
                else
                {
                    UART_printf("\n\n\n\nUSB Host Sensor Test Failed at iteration - %d\n",iteration);
                    failCount++;
                }
            }

            UART_printf("\n\nUSB Host Sensor Stress Test Status\n");
            UART_printf("===================================\n");
            UART_printf("Number of Times Executed - %d\n", (iteration - 1));
            UART_printf("Pass Count - %d\n", passCount);
            UART_printf("Fail Count - %d\n", failCount);

            if((iteration != 0) && (failCount == 0))
            {
                UART_printf("Overall Status - PASS\n\n\n" );
            }
            else
            {
                UART_printf("Overall Status - FAIL\n\n\n" );
                ret = -1;
            }
            break;
        }
    }
#else
        ret = FSShellAppUtilsCmdMkTxtFile();
        break;
        }
    }
#endif

    USBHMSCDriveClose(g_ulMSCInstance);
    return ret;
}

/**
 *  \brief   usb host Diagnostic test main function
 *
 *  \return  int - usb host Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    int8_t ret = 0;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    UART_printf("\n*************************************************\n");
    UART_printf  ("*                  USB Host Test                *\n");
    UART_printf  ("*************************************************\n");

    ret = BoardDiag_run_usbHost_test();
    if(ret == 0)
    {
        UART_printf("\nUSB Host test Passed\n");
    }
    else
    {
        UART_printf("\nUSB Host test Failed\n");
    }
    return ret;
}
