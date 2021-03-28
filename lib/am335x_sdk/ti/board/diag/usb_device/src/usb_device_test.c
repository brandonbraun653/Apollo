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
 *  \file  usb_device_test.c
 *
 *  \brief usb device diagnostic test file
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

#include "usb_device_test.h"

int32_t gUsbIntNo;

/**
 *  \brief    main entry point for USB Miscs interrupt handler.
 *
 *  \param    pUsbParam           [IN]       USB Parameters
 *
 */
void usbMiscIntrHandler(void* pUsbParam)
{
    USB_miscIrqHandler(((USB_Params*)pUsbParam)->usbHandle,
                        (USB_Params*)pUsbParam);
}

/**
 *  \brief    main entry point for USB core interrupt handler.
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

    USB_coreIrqHandler(usb_dev_params.usbHandle,
                        &usb_dev_params);
#else
    USB_coreIrqHandler(((USB_Params*)pUsbParam)->usbHandle,
                        (USB_Params*)pUsbParam);
#endif
}

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
static void usb_configIntRouter(uint32_t portNum)
{
    CSL_IntrRouterCfg  intrRouterCfg;
    uint32_t           outIntrNum;

    /* Initialize Main to MCU Interrupt Router conifg structure */
    intrRouterCfg.pIntrRouterRegs = (CSL_intr_router_cfgRegs *)(uintptr_t)
                                       (CSL_MAIN2MCU_LVL_INTRTR0_CFG_BASE);

    intrRouterCfg.pIntdRegs       = (CSL_intr_router_intd_cfgRegs *)(uintptr_t)NULL;

    /* number of input ints */
    intrRouterCfg.numInputIntrs   = MAIN2MCU_LVL_INTRTR0_NUM_INTPUT_INTRS;

    /* number of output ints */
    intrRouterCfg.numOutputIntrs  = MAIN2MCU_LVL_INTRTR0_NUM_OUTPUT_INTRS;

    /*
     * Route USB int to MAIN2MCU int router output.
     * USB example codes running on R5 (MCU) core registers MAIN2MCU int router
     * output as USB MCU interrupt
     */
    if (portNum == 0)
    {
        outIntrNum = SYS_INT_USB0 - CSL_MCU0_INTR_MAIN2MCU_LVL_INTR0_OUTL_0;
        CSL_intrRouterCfgMux(&intrRouterCfg, MAIN2MCU_USB0_INT, outIntrNum);
    }
    else
    {
        outIntrNum = SYS_INT_USB1 - CSL_MCU0_INTR_MAIN2MCU_LVL_INTR0_OUTL_0;
        CSL_intrRouterCfgMux(&intrRouterCfg, MAIN2MCU_USB1_INT, outIntrNum);
    }
}
#endif

/**
 *  \brief    Used to register interrupt for USB device
 *
 *  \param    usbDevParams        [IN]      Parameters used
 *                                          for configuring USB
 *
 */
static void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams)
{
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
    interruptRegParams.corepacConfig.arg = (uintptr_t)usbDevParams;

    Osal_RegisterInterrupt(&interruptRegParams,&hwiHandle);

#else
    HwiP_Params hwiInputParams;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
	hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)usbDevParams;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;

    if (usbDevParams->instanceNo == 0)
    {
        gUsbIntNo = SYS_INT_USB0;
    }
#if !defined(SOC_OMAPL137) && !defined(SOC_OMAPL138)
    else
    {
        gUsbIntNo = SYS_INT_USB1;
    }

    hwiInputParams.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif
    /* Initialize the object ISR fucntion with application ISR */
    usb_osalRegisterInterrupt(gUsbIntNo,
                              (HwiP_Fxn)usbCoreIntrHandler,
                              &hwiInputParams);
#endif

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
    /* configure the interrupt router for MCU (R5) build */
    usb_configIntRouter(usbDevParams->instanceNo);
#endif

    /* Interrupt handler has been installed, enable required interrupts */
    USB_irqConfig(usbHandle, usbDevParams);


}

/**
 *  \brief    format the ramDisk with FAT16 format and have a readme.txt
 *            file as content the disk image is a FAT16 formatted from Linux.
 *
 */
static void formatRamDisk(void)
{
    uint32_t* wp;
    uint32_t  i;
    uint32_t j = FF_ENTRY_FC;

    for(i = 0; i < sizeof(gRamDisk); i++)
    {
        gRamDisk[i] = 0x00;
    }

    wp = (uint32_t*)gRamDisk;

    /* copy the MBR */
    for (i = 0; i<sizeof(img_mbr)/4; i++)
    {
        wp[i] = img_mbr[i];
    }

    /* manually fill the end of BPR / Boot Sector */
    gRamDisk[BS_SIGN_OFFSET]     = BOOT_SECTOR_SIGNATURE_55;
    gRamDisk[BS_SIGN_OFFSET + 1] = BOOT_SECTOR_SIGNATURE_AA;

    /* the FAT#1 - created by mkfs.vfat */
    wp[FF_ENTRY_0]     = FATFS_MEDIA_DESCRIPTOR_0;
    wp[FF_ENTRY_0 + 1] = FATFS_MEDIA_DESCRIPTOR_1;

    /* the FAT#2 - created by mkfs.vfat */
    wp[FF_ENTRY_1]     = FATFS_MEDIA_DESCRIPTOR_0;
    wp[FF_ENTRY_1 + 1] = FATFS_MEDIA_DESCRIPTOR_1;

    /* root dir */
    for (i = 0; i<sizeof(img_rd)/4; i++)
    {
        wp[FF_DIR_CLUSTER + i] = img_rd[i];
    }

    /* copy file content */
    //memcpy(&wp[FF_ENTRY_FC], img_fc, sizeof(img_fc));
    for(i = 0; i < sizeof(img_fc); i++)
    {
        wp[j] = img_fc[i];
        j++;
    }

    /* update the size of the file content */
    wp[FF_ENTRY_FS] = sizeof(img_fc)-1;
}

void setupMMUForUSB(void)
{
#if defined(SOC_AM437x)
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
 *  \brief    Opens the USB Driver and performs device test
 *
 *  \return   int8_t
 *               0 - on data comparison match
 *              -1 - on data comparison mismatch.
 *
 */
int8_t BoardDiag_run_usbDevice_test(void)
{
    USB_Params  usb_dev_params;
    USB_Handle  usb_handle;
    int8_t ret = -1;
    char p = 'n',ch = ' ';
    Board_STATUS status;
    Board_initCfg boardCfg;

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
        return ret;
    }

#if (!(defined(SOC_AM65XX)))
    setupMMUForUSB();
#endif

    /* setup timer for delay and timer functions */
#if (defined(evmAM335x) || defined (evmAM437x)) || defined (evmOMAPL137) || defined (lcdkOMAPL138)
    delayTimerSetup(); /* MAXIE_TBD:- Need to verify Whether the #if protection is need */
#endif

    UART_printf("\nUSB Device MSC Application!!\n");

    /* Initialize the RAMDisk */
    RAMDISKUtilsInit((uint8_t *)gRamDisk, sizeof(gRamDisk));
    formatRamDisk();

    UART_printf("\nRAM Disk Initialization Successful\n");

    usb_dev_params.usbMode = USB_DEVICE_MSC_MODE;
    usb_dev_params.instanceNo = USB_DEV_INSTANCE;    /*TDB USB device instance should be updated */
    usb_dev_params.usbClassData = (void*)&g_sMSCDevice;

    usb_handle = USB_open(usb_dev_params.instanceNo, &usb_dev_params);
    if (usb_handle == 0)
    {
        UART_printf("\nFailed to open USB driver\n");
        return ret;
    }

    usbdIntrConfig(usb_handle, &usb_dev_params);

    UART_printf("\nUSB Device Configuration Complete.\n");
    UART_printf("Check USB Device Enumeration on Host PC\n");
    UART_printf("New Drive Appears on Host PC after Enumeration is Successful.\n");
    UART_printf("Verify the Text File in the Enumerated USB Drive.\n");

    UART_printf("\nEnter the Character 'b' to Terminate the Test\n");

    while(1)
    {
        ch = BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((ch == 'b') || (ch == 'B'))
        {
            UART_printf("USB Device Test is Ended\n\n");
            break;
        }
    }

    /* Disable USB interrupt */
    usb_osalDisableInterruptNum(gUsbIntNo);

    UART_printf("Press 'y' to verify pass, or any other character to indicate failure: ");
    UART_scanFmt("%c", &p);
    if ( (p == 'y') || (p == 'Y') )
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/**
 *  \brief   usb device Diagnostic test main function.
 *
 *  \return  int - usb device Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main()
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

    UART_printf("\n*********************************************\n");
    UART_printf  ("*                 USB Device Test           *\n");
    UART_printf  ("*********************************************\n");

    UART_printf("\nRunning USB Device test...\n");
    ret = BoardDiag_run_usbDevice_test();
    if(ret == 0)
    {
        UART_printf("\nUSB Device test Passed\n");
    }
    else
    {
        UART_printf("\nUSB Device test Failed\n");
    }

    return ret;
}
