/*
 * Copyright (C) 2014-2019 Texas Instruments Incorporated - 
 * http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */



#include "types.h"

#include <ti/board/board.h>

#if (defined(SOC_AM335x) || defined (SOC_AM437x))
#include "example_utils_mmu.h"
#include "mmu.h"

#include "cache.h"
#endif

#include <ti/fs/fatfs/FATFS.h>

#include "fatfs_port_usbmsc.h"
#include "fs_shell_app_utils.h"

#include <ti/drv/usb/usb_drv.h>
#include <ti/drv/usb/usb_osal.h>
#include "usblib.h"
#include "usbhost.h"
#include "usbhmsc.h"

#include "ti/drv/usb/example/common/timer.h"
#include "ti/drv/usb/example/common/hardware.h"

#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
#include "ti/csl/arch/arm9/V0/csl_cp15.h"
#endif

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
#include "intRouter.h"
#endif


//*****************************************************************************
//
// The instance data for the MSC driver.
//
//*****************************************************************************
tUSBHMSCInstance* g_ulMSCInstance = 0;

#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
/* USB param struture variable should be used as global variable because
 * ARM9 does not support interrupt hander with arguments
 */
USB_Params usb_host_params;
#endif

//*****************************************************************************
//
// Hold the current state for the application.
//
//*****************************************************************************
typedef enum
{
    //
    // No device is present.
    //
    STATE_NO_DEVICE,

    //
    // Mass storage device is being enumerated.
    //
    STATE_DEVICE_ENUM,

    //
    // Mass storage device is ready.
    //
    STATE_DEVICE_READY,

    //
    // An unsupported device has been attached.
    //
    STATE_UNKNOWN_DEVICE,

    //
    // A power fault has occurred.
    //
    STATE_POWER_FAULT
} tState;

volatile tState g_eState;


//*****************************************************************************
//
// FAT fs variables.
//
//*****************************************************************************
/* USBMSC function table for USB implementation */
FATFS_DrvFxnTable FATFS_drvFxnTable = {
    FATFSPortUSBDiskClose,      // closeDrvFxn
    FATFSPortUSBDiskIoctl,      // controlDrvFxn
    FATFSPortUSBDiskInitialize, // initDrvFxn
    FATFSPortUSBDiskOpen,       // openDrvFxn
    FATFSPortUSBDiskWrite,      // writeDrvFxn
    FATFSPortUSBDiskRead        // readDrvFxn
};

/* FATFS configuration structure */
FATFS_HwAttrs FATFS_initCfg[_VOLUMES] =
{
    {
        0U
    },
    {
        1U
    },
    {
        2U
    },
    {
        3U
    }
};

/* FATFS objects */
FATFS_Object FATFS_objects[_VOLUMES];

/* FATFS configuration structure */
const FATFS_Config FATFS_config[_VOLUMES + 1] = {
    {
        &FATFS_drvFxnTable,
        &FATFS_objects[0],
        &FATFS_initCfg[0]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[1],
         &FATFS_initCfg[1]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[2],
         &FATFS_initCfg[2]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[3],
         &FATFS_initCfg[3]
    },
    {NULL, NULL, NULL}
};

FATFS_Handle fatfsHandle = NULL;
uint32_t     g_fsHasOpened = 0;

/* ========================================================================== */
/*                                Prototypes                                  */
/* ========================================================================== */
void usbHostIntrConfig(USB_Params* usbParams);
void MSCCallback(void* classInstance, uint32_t ulEvent, void *pvData);
void consolePrintf(const char *pcString, ...);
void setupMMUForUSB(void);

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#if (defined(evmOMAPL137) || defined(lcdkOMAPL138) || defined(SOC_AM65XX) \
     || defined(SOC_J721E))
#define USB_INSTANCE            0       /* USB #0 (the HOST port) on the EVM */
#else
#define USB_INSTANCE            1		/* USB #1 (the HOST port) on the EVM */
#endif

#define NO_ERROR                0


//*****************************************************************************
/* main entry point for USB host core interrupt handler 
 * Matching interrupt call-back function API */
//*****************************************************************************
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

//*****************************************************************************
//
//*****************************************************************************
int main(void)
{
#if !(defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138)))
    USB_Params  usb_host_params;
#endif
    USB_Handle  usb_handle;

#ifdef USB3SS_EN
    USB_Config* usb_config;
#endif

    int         rc;
    

    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

#if (defined(evmAM335x) || defined (evmAM437x))
	MMUConfigAndEnable();
#endif

    /* set up MMU page for APP_UNCACHED_DATA_BLK3_MEM and for USB */
    setupMMUForUSB();

    /* Enable Data Cache */
#if (defined(evmAM335x) || defined (evmAM437x))
    CACHEEnable(CACHE_DCACHE, CACHE_INNER_OUTER);
#endif

    /* set up timer for delay and timer functions */
    delayTimerSetup();
    consolePrintf("\nBare-metal USB Host MSC example!!\n");

    /*osalTimerTest();*/

#ifdef USB3SS_EN
    USB_getConfig(USB_INSTANCE, &usb_config);

    if (usb_config!=0)
    {
        usb_config->usb30Enabled = 1;
    }
#endif

    usb_host_params.usbMode      = USB_HOST_MSC_MODE;
    usb_host_params.instanceNo   = USB_INSTANCE; 

    usb_handle = USB_open(usb_host_params.instanceNo, &usb_host_params);

    if (usb_handle == 0) 
    {
        // failed to open the USB driver
        while(1);
    }

    //
    //Setup the INT Controller
    //
	usbHostIntrConfig (&usb_host_params);

    //
    // Initialize the file system.
    //
    FATFS_init();

    //
    // Open an instance of the mass storage class driver.
    //
    g_ulMSCInstance = USBHMSCDriveOpen(usb_host_params.instanceNo, 0, MSCCallback);


    while(1) {    
        rc = USBHCDMain(USB_INSTANCE, g_ulMSCInstance);

        if (rc != NO_ERROR)
        {
            consolePrintf("USBHCDMain failed with this error: 0x%x\n", rc);
            while(1);
        }

        if(g_eState == STATE_DEVICE_ENUM)
        {
            //
            // Take it easy on the Mass storage device if it is slow to
            // start up after connecting.
            //
            if(USBHMSCDriveReady(g_ulMSCInstance) != 0)
            {
                //
                // Wait about 100ms before attempting to check if the
                // device is ready again.
                //
                usb_osalDelayMs(100);
            }

            if (!g_fsHasOpened)
            {
                /* USBMSC FATFS initialization */
                rc = FATFS_open(0U, NULL, &fatfsHandle);
                if (rc != FR_OK)
                {
                    consolePrintf("Failed to open FATFS\n");
                }
                else
                {
                    g_fsHasOpened = 1;
                }
            }

            FSShellAppUtilsProcess();
        }        
    }
}




void usbHostIntrConfig(USB_Params* usbParams)
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
    usb_configIntRouter(usbParams->instanceNo,TRUE);
#endif

    USB_irqConfig(usbParams->usbHandle, usbParams);
#endif    
}



//*****************************************************************************
//
// This is the callback from the MSC driver.
//
// \param ulInstance is the driver instance which is needed when communicating
// with the driver.
// \param ulEvent is one of the events defined by the driver.
// \param pvData is a pointer to data passed into the initial call to register
// the callback.
//
// This function handles callback events from the MSC driver.  The only events
// currently handled are the MSC_EVENT_OPEN and MSC_EVENT_CLOSE.  This allows
// the main routine to know when an MSC device has been detected and
// enumerated and when an MSC device has been removed from the system.
//
// \return Returns \e true on success or \e false on failure.
//
//*****************************************************************************
void
MSCCallback(void* classInstance, uint32_t ulEvent, void *pvData)
{
    //
    // Determine the event.
    //
    switch(ulEvent)
    {
        //
        // Called when the device driver has successfully enumerated an MSC
        // device.
        //
        case MSC_EVENT_OPEN:
        {
            //
            // Proceed to the enumeration state.
            //
            g_eState = STATE_DEVICE_ENUM;
            break;
        }

        //
        // Called when the device driver has been unloaded due to error or
        // the device is no longer present.
        //
        case MSC_EVENT_CLOSE:
        {
            //
            // Go back to the "no device" state and wait for a new connection.
            //
            g_eState = STATE_NO_DEVICE;
            g_fsHasOpened = 0;

            break;
        }

        default:
        {
            break;
        }
    }
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
