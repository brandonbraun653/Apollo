/**
 *  \file  dev_msc.c
 *
 *  \brief This application code is the main routine for device
 *         mass storage class example. This layer enables the clocks
 *         for USB mass storage device, implements phy on logic
 *         and configures the interrupts for USB.
 *         This layer will read all the incoming interrupts and pass
 *         this interrupts to the lower layers to be processed and
 *         the required actions are taken by the lower layer.
 *
 */

/**
 * \copyright  Copyright (C) 2015-2020 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"

#include <ti/board/board.h>

#include "error.h"
#if (defined(SOC_AM335x) || defined (SOC_AM437x))
#include "cache.h"
#include "mmu.h"
#include "example_utils_mmu.h"

#endif
#include <ti/drv/usb/usb_drv.h>
#include <ti/drv/usb/usb_osal.h>

#include "usbdmsc.h"
#include "usb_msc_structs.h"

/* Ramdisk utils header file */
#include "ramdiskutils.h"
#include "ti/drv/usb/example/common/diskimg.h"

#include "ti/drv/usb/example/common/timer.h"
#include "ti/drv/usb/example/common/hardware.h"
#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
/* Needed for MMU configuration of OMAPL137 ARM core*/
#include "ti/csl/arch/arm9/V0/csl_cp15.h"
#endif

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
#include "intRouter.h"
#endif


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define NON_SECURE_MODE FALSE

#define SOC_CACHELINE_SIZE_MAX               (64)

#if (defined (evmAM335x) || defined(evmAM437x) || defined(evmOMAPL137) || \
    defined(lcdkOMAPL138) || defined(j721e_evm))
#define USB_DEV_INSTANCE                     0
#elif (defined (am65xx_evm) || defined (am65xx_idk))
#define USB_DEV_INSTANCE                     1
#else
#error "Unsupported Board. \r\n"
#endif

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
#define RAM_DISK_MEMORY_SIZE         2
#else
#define RAM_DISK_MEMORY_SIZE         16
#endif
#if defined(__IAR_SYSTEMS_ICC__)
#pragma data_alignment=(SOC_CACHELINE_SIZE_MAX)
uint8_t gRamDisk[RAM_DISK_MEMORY_SIZE*1024*1024];
#else
uint8_t gRamDisk[RAM_DISK_MEMORY_SIZE*1024*1024] __attribute__ ((aligned(SOC_CACHELINE_SIZE_MAX)))
                                  __attribute__ ((section (".bss:extMemCache:ramdisk")));
#endif

/* on AM335x SOC, we might need to reset the USB core and restart
   the USB stack. This flag is for that purpose. It's set to 1
   when the USB stack detects the USB cable is disconnected. */
uint32_t g_resetUsb = 0;

/* main entry point for USB Miscs interrupt handler */
void usbMiscIntrHandler(void* pUsbParam);

/* main entry point for USB core interrupt handler */
#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
/*
 * ARM9 core does not support passing arguments to ISR handler.
 * The arugument *pUsbParam is not valid for ARM9 core.
 * Hence, usb_dev_params is made global and is used to access USB params
 * inside ISR for ARM9 core.
 */
USB_Params usb_dev_params;
#endif
void usbCoreIntrHandler(void* pUsbParam);


void consolePrintf(const char *pcString, ...);
void setupMMUForUSB(void);
void formatRamDisk(void);

#if (defined (SOC_AM335x))
static void resetUsb(USB_Params*  usbDdevParams);
#endif
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/* format the ramDisk with FAT16 format and have a readme.txt file as content
 * the disk image is a FAT16 formatted from Linux
 */
void formatRamDisk(void)
{
    uint32_t* wp;
    uint32_t  i;

    memset(gRamDisk, 0, sizeof(gRamDisk));

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
    memcpy(&wp[FF_ENTRY_FC], img_fc, sizeof(img_fc));

    /* update the size of the file content */
    wp[FF_ENTRY_FS] = sizeof(img_fc)-1;
}
volatile uint32_t emuwait_board=1;
int main()
{
#if !(defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138)))
    USB_Params  usb_dev_params;
#endif
    USB_Handle  usb_handle;

    Board_initCfg boardCfg;
    Board_STATUS board_status;
    
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
    board_status = Board_init(boardCfg);
    if(board_status!=BOARD_SOK) {
		while(emuwait_board);
	}
#if (defined(evmAM335x) || defined (evmAM437x))
    MMUConfigAndEnable();
#endif
    setupMMUForUSB();

    /* Enable Data Cache */
#if (defined(evmAM335x) || defined (evmAM437x))
    CACHEEnable(CACHE_DCACHE, CACHE_INNER_OUTER);
#endif

    /* setup timer for delay and timer functions */
#if (defined(evmAM335x) || defined (evmAM437x)) || defined (evmOMAPL137) || defined (lcdkOMAPL138)
    delayTimerSetup();

#endif
    consolePrintf("\n Bare-metal USB device MSC Application!!\n");

    /* Initialize the RAMDisk */
    RAMDISKUtilsInit((uint8_t *)gRamDisk, sizeof(gRamDisk));
    formatRamDisk();

    consolePrintf("\nPassed RAMDISKUtilsInit function\n");

    usb_dev_params.usbMode = USB_DEVICE_MSC_MODE;
    usb_dev_params.instanceNo = USB_DEV_INSTANCE;
    usb_dev_params.usbClassData = (void*)&g_sMSCDevice;
    
    usb_handle = USB_open(usb_dev_params.instanceNo, &usb_dev_params);

    if (usb_handle == 0) 
    {
        // failed to open the USB driver
        consolePrintf("\nFailed to open USB driver\n");
        while(1);
    }

    usbdIntrConfig(usb_handle, &usb_dev_params);

    consolePrintf("\nDone configuring USB driver and its interrupts. Ready to use\n");

    while(1)
    {
        /* Main while loop. All USB dev events are handled in interrupt context */

#if (defined (SOC_AM335x))
        if (g_resetUsb == 1)
        {
            /* we were signaled to reset the USB. Do it here */
            g_resetUsb = 0;
            usb_handle->isOpened = 0;

            resetUsb(&usb_dev_params);
        }
#endif
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams)
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
    int32_t mainIntNo = 0;
    HwiP_Params hwiInputParams;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
	hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)usbDevParams;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;

    if (usbDevParams->instanceNo == 0)
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
    /* Initialize the object ISR fucntion with application ISR */
    usb_osalRegisterInterrupt(mainIntNo,
                              (HwiP_Fxn)usbCoreIntrHandler,
                              &hwiInputParams);

#endif

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
    /* configure the interrupt router for MCU (R5) build */
    usb_configIntRouter(usbDevParams->instanceNo,TRUE);
#endif

    /* Interrupt handler has been installed, enable required interrupts */
    USB_irqConfig(usbHandle, usbDevParams);

}

/* main entry point for USB Miscs interrupt handler */
void usbMiscIntrHandler(void* pUsbParam)
{
    USB_miscIrqHandler(((USB_Params*)pUsbParam)->usbHandle, 
                        (USB_Params*)pUsbParam);
}

/* main entry point for USB core interrupt handler */
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


#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
static volatile unsigned int pageTable[4*1024]__attribute__((aligned(16*1024)));


#else
/*AM335x and AM437x: pageTable is defined in exampleutils library
 * of starterware.
 */
#define MMU_PAGETABLE_NUM_ENTRY           (4096U)
extern volatile uint32_t pageTable[MMU_PAGETABLE_NUM_ENTRY];
#endif

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


/* 
 * In AM335x, CPPI DMA and MUSB could get into a bad state which the USB seems
 * to send bulk IN with bogus data immediately after an IN token received from 
 * USB host.  This bad state normally happens after USB cable is unplugged
 * while a bulk-in transfer is happening. Cleaning up CPPI/USB pending/stuck
 * transaction does not work yet. Reset the USBSS and USB stack instead for now
 * for AM335x to solve the issue. Please note that this function resets the
 * whole USBSS which resets both USB instances.
 */
#if (defined (SOC_AM335x))
#define USB_USBSS_BASE_ADDR     (0x47400000u)
#define USB_USBSS_SYSCONFIG     (0x10u)
#define USB_USBSS_SOFT_RESET    (1<<0)

static void resetUsb(USB_Params*  usbDdevParams)
{
    USB_Handle usb_handle;
    uint32_t regVal;

    /* soft reset the USB controller */
    regVal = HWREGH(USB_USBSS_BASE_ADDR + USB_USBSS_SYSCONFIG);
    HWREG(USB_USBSS_BASE_ADDR + USB_USBSS_SYSCONFIG) = regVal | USB_USBSS_SOFT_RESET;

    /* restart the USB stack */
    usb_handle = USB_open(usbDdevParams->instanceNo, usbDdevParams);
    usb_handle->handleCppiDmaInApp = TRUE;

    USB_irqConfig(usb_handle, usbDdevParams);
}
#endif

