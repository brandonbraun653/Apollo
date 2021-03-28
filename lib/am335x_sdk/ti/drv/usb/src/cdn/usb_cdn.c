/**
 * @file   usb_cdn.c
 *
 * @brief  Top level CDN usb functions
 */
/*
 * Copyright (c) 2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================*/

#include "types.h"
#include "error.h"

/* pdk includes */
#include <ti/drv/usb/usb_drv.h>

#include "hw_usb.h"

#ifdef USE_CDN_XHCI
#include "cdn_xhci_structs_if.h"
#include "cdn_xhci_if.h"
#include "usbssp_regs_macros.h"
#else
#include "usb_hcd_xhci.h"
#endif

#include "usb_hcd_xhci.h"
#include "hw_types.h"
#include "xhci_soc.h"

#include "cdn_log.h"

#include "UsbDefs.h"
#include "usb_cdn_dcd.h"
#include "usb_cdn.h"
#include "usb_dcd_interface.h"

#include "usblib.h"
#include "usbhost.h"
#include "usb_osal.h"
#include "debug.h"
#include "error.h"


/* USB MSC class related header files */
#include "usbdmsc.h"
#include "usb_dev_dman.h"
#include "usb_wrapper.h"

/* Bulk */
#include "usbdbulk.h"

/****************************************************************************** */
/* global USB info */
/****************************************************************************** */
tUSBInstanceObject  g_USBInstance[USB_NUM_INSTANCE];

/* The following USB memory has to be in a non-cached memory section
   User application is responsible for directing this section and 
   setting MMU attribute of this mem block */
USB_MEM_S g_usb_global __attribute__ ((section (".bss:extMemNonCache:usbXhci")));


#ifdef USE_CDN_XHCI
#define XHCI_CORE_OFFSET  (0x10000)
uint32_t gSocXhciBase[]   =   {USB0_XHCI_WRAPPER_BASE_ADDR + XHCI_CORE_OFFSET,
                               USB1_XHCI_WRAPPER_BASE_ADDR + XHCI_CORE_OFFSET};
#endif


/* USB_cdn functions */
USB_Handle   USB_open_cdn(USB_Handle handle, USB_Params *params);
void         USB_irqConfig_cdn(USB_Handle handle, USB_Params* params);
void         USB_irqCore_cdn(USB_Handle handle, USB_Params* params);
void         USB_irqMisc_cdn(USB_Handle handle, USB_Params* params);



/*
 * \brief USB main interrupt handler.
 * It gets all the interrupts for host, device and the wrapper layer.
 * Here it is decided which kind of interrupt has occured
 * and required fucntions are called
 */
void usbCdnDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/* \brief core interrupt handler */
void usbCdnDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam);


/* other functions from the core driver */
void usbPhyOn(uint32_t portNumber, uint32_t invertPol);
void usbClockCfg(uint32_t portNumber);

/* regular prototypes */
static void setupCdnDev(USB_Params* params);
static void setupCdnHost(USB_Params* params);

extern void saveDeviceDescriptor(uint32_t ulIndex, uint8_t* buffer);
extern void saveConfigDescriptor(uint32_t ulIndex, uint8_t* buffer, uint32_t length);


#ifdef _DEBUG_
uint32_t g_dbg_enable_log  = 0;
uint32_t g_dbg_log_lvl = DBG_CRIT;
uint32_t g_dbg_log_cnt = 0;
uint32_t g_dbg_state = 0;
#endif

void USB_Host_Init(uint32_t instanceNo);

/*
 *  ======== USB_open_dwc ========
 */
USB_Handle USB_open_cdn(USB_Handle handle, USB_Params *params)
{
    SemaphoreP_Params           semParams;

    if (handle->isOpened == 1) 
    {
        /* this handle has been used; */
        return 0;
    }

    /* mark used */
    handle->isOpened = 1;

    /* save the handle for interrupt handler */
    params->usbHandle = handle;
    handle->usbParams = params;

    /* initialize semaphores for the driver to use 
       Currently only USB generic bulk transport demo uses semaphore
     */
    usb_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;

    params->writeSem = usb_osalCreateBlockingLock(0, &semParams);
    params->readSem = usb_osalCreateBlockingLock(0, &semParams);

    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            setupCdnHost(params);
            break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
            setupCdnDev(params);
            break;

        default:
            return 0;
    }

    return handle;
}

void USB_irqConfig_cdn(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            //usb_set_wrapper(params->instanceNo);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        break;

        default:
            return;
    }
}

/*
 *  ======== irq main handler ========
 */
void USB_irqCore_cdn(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            usbHostIntrHandler(params->drvData);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
            usbCdnDcdCoreIntrHandler(0, 0, params->drvData);
        break;

        default:
            return;
    }
}

/*
 *  ======== irq main handler ========
 */
void USB_irqMisc_cdn(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            usbHostIntrHandler(params->drvData);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
            usbCdnDcdMiscIntrHandler(0, 0, params->drvData);
        break;

        default:
            return;
    }
}

/*
 *  ======== setup dev  ========
 */
void setupCdnDev(USB_Params* params)
{
    int32_t status = S_PASS;
    usbCdnDcdDevice_t* cdnDcd;

    /* clear the memory since it could be in NOLOAD memory */
    memset(&g_usb_global.drv_instances[params->instanceNo], 0, 
            sizeof(drv_instance_u));
    
    cdnDcd = &g_usb_global.drv_instances[params->instanceNo].cdnDcd;
    cdnDcd->instanceNo = params->instanceNo;

    usbPhyOn(params->instanceNo, 0); /* port No and no invert polarity */

    usbClockCfg(params->instanceNo);
    usb_wrapper_setup_device_mode(params->instanceNo);

    usbDcd_t * pDcdCoreInterface = NULL;

    USBDInitCoreObject();
    status = USBDcdIntfRegisterDcd( &pDcdCoreInterface, (const char*)"cdn_driver" );

    if ( S_PASS == status)
    {
        /* this initialisation should be done in the dwc3 device control driver */
        cdnDcd->pDcdCore = pDcdCoreInterface;
        pDcdCoreInterface->dcdActions.pFnDcInit         = &USBCdnDcdInit;
        pDcdCoreInterface->dcdActions.pFnConfigDevChara = &USBCdnDcdConfigDevChara;
        pDcdCoreInterface->dcdActions.pFnEndpt0Req      = &USBCdnDcdEp0Req;
        pDcdCoreInterface->dcdActions.pFnEndptReq       = &USBCdnDcdEpReq;
        pDcdCoreInterface->privateData                  = cdnDcd;
    }

    params->drvData = (void*)cdnDcd;

    switch (params->usbMode)
    {
        case USB_DEVICE_MSC_MODE:

            /* Call the USB Msc init function here
               This call registers the class driver with the protocol layer */
            USBDMSCInit((void *) pDcdCoreInterface->pGadgetObject,
                        (tUSBDMSCDevice *)params->usbClassData);
            break;


        case USB_DEVICE_BULK_MODE:
            USBDBulkInit((void *) pDcdCoreInterface->pGadgetObject,
                        (tUSBDBulkDevice *)params->usbClassData, params);
            break;

        default:
            break;
    }
}

/****************************************************************************** 
 *
 * The global that holds all of the host drivers in use in the application. 
 * In this case, only the MSC class is loaded.
 * 
 ****************************************************************************** */
static tUSBHostClassDriver const * const g_ppHostClassDrivers[] =
{
    &g_USBHostMSCClassDriver
};

/****************************************************************************** 
 * 
 * This global holds the number of class drivers in the g_ppHostClassDrivers 
 * list.
 *
 ****************************************************************************** */
#define NUM_CLASS_DRIVERS       (sizeof(g_ppHostClassDrivers) /               \
                                 sizeof(g_ppHostClassDrivers[0]))

/****************************************************************************** 
 * 
 * The size of the host controller's memory pool in bytes.
 * 
 ****************************************************************************** */
#define HCD_MEMORY_SIZE         128

/****************************************************************************** 
 *
 * The memory pool to provide to the Host controller driver. 
 *
 ****************************************************************************** */
unsigned char g_pHCDPool[HCD_MEMORY_SIZE];

/*
 *  ======== setup MSC host  ========
 */
static void setupCdnHostMsc(USB_Params* params)
{
#ifdef USE_CDN_XHCI
    USBSSP_DriverResourcesT* xhciData;

    xhciData = &g_usb_global.drv_instances[params->instanceNo].xhci_driver_resources;
#else
    XHCI_DATA_S*  xhciData;

    xhciData = &g_usb_global.drv_instances[params->instanceNo].xhciData;
#endif

    /* clear the memory since it could be in NOLOAD memory */
    memset(&g_usb_global.drv_instances[params->instanceNo], 0, 
           sizeof(drv_instance_u));


    /* setup the wrapper */
    usb_wrapper_setup_host_mode(params->instanceNo);

    /*
     * Init the clock, power domains, and USB controller.
     */
    USB_Host_Init(params->instanceNo);
    
    /* 
     * Initialize the power configuration.  This sets the power enable signal 
     * to be active high and does not enable the power fault. */
    USBHCDPowerConfigInit(params->instanceNo, USBHCD_VBUS_AUTO_HIGH);

    /*
     * Register the host class drivers. 
     * */
    USBHCDRegisterDrivers(params->instanceNo,
                          g_ppHostClassDrivers,
                          NUM_CLASS_DRIVERS);

    /* 
     * Initialize the usblib host controller. 
     */
    USBHCDInit(params->instanceNo, g_pHCDPool, HCD_MEMORY_SIZE);

    /* setup interrup call back user parametter */
    params->drvData = (void*)xhciData;
}


static void setupCdnHost(USB_Params* params)
{
    setupCdnHostMsc(params);
}


#ifdef USE_CDN_XHCI

extern void USBHCDDisconnect(uint32_t ulIndex);

 
/* enabling compliance mode for xHCI1.1 
 * Compliance mode seems to require SERDES turned on
 * If SERDES is not turned on, the xHCI does not not working properly 
 * Only do this if the config asks us to enable USB3.0 
 */

#define PRINT_COMPLIANCE_STATUS (1)

extern USB_Config USB_config[3];

void enableComplianceMode(uint32_t instanceNumber)
{
    uint32_t regVal = 0;
    USB_Config* usbConfig = &USB_config[instanceNumber];
    uint32_t baseAddr = 0;
    uint32_t PP = 0, CCS=0, PED=0, PR=0, PLS=0;

    baseAddr = (instanceNumber==0)?(USB0_XHCI_WRAPPER_BASE_ADDR+USB_XHCI_CORE_OFFSET):
                (USB1_XHCI_WRAPPER_BASE_ADDR+USB_XHCI_CORE_OFFSET);

    if (usbConfig->usb30Enabled == TRUE) /* SOC support */
    {
        /* wait until port finishes resetting */
        while (1)
        {
            regVal = HW_RD_REG32(baseAddr + XHCI_USB_PORTSC2);
            PR = HW_GET_FIELD(regVal,  XHCI_USB_PORTSC2_PR);
            if (PR == 0) break;
        }

        /* attempt to turn on compliance mode */
        debug_printf("Enable compliance mode\n");

        /* CTE can only be set to 1 if port is in disconnected state and with PLS = RX_detect*/
        debug_printf("checking to see if we are in disconnected state\n");
        regVal = HW_RD_REG32(baseAddr + XHCI_USB_PORTSC2);

        PP  = HW_GET_FIELD(regVal,  XHCI_USB_PORTSC2_PP);
        CCS = HW_GET_FIELD(regVal,  XHCI_USB_PORTSC2_CCS);
        PED = HW_GET_FIELD(regVal,  XHCI_USB_PORTSC2_PED);
        PR  = HW_GET_FIELD(regVal,  XHCI_USB_PORTSC2_PR);
        PLS = HW_GET_FIELD(regVal,  XHCI_USB_PORTSC2_PLS);

        debug_printf("PORTSC2 = 0x%x. PP=%d. CCS=%d. PED=%d. PR=%d. PLS=%d\n",
                      regVal, PP,CCS, PED, PR, PLS);

        if ((PP != 1)|| (CCS!=0) || (PED!=0) || (PR!=0) )
        {
            debug_printf("Port is not in disconnected state while trying to enable CTE\n");
        }

        regVal = 0;
        HW_SET_FIELD(regVal, XHCI_USB_PORTSC2_PP,  0x1);     /* PP = 1 */
        HW_WR_REG32(baseAddr + XHCI_USB_PORTSC2, regVal);    /* write PP to PORTSC */

        regVal = HW_RD_REG32(baseAddr + XHCI_USB_PORTSC2);

        HW_SET_FIELD(regVal, XHCI_USB_PORTSC2_LWS, 0x1);     /* LWS = 1 to write to PLS */
        HW_SET_FIELD(regVal, XHCI_USB_PORTSC2_PLS, XHCI_USB_PORTSC2_PLS_COMPLIANCEMODE);
       
        HW_WR_REG32(baseAddr + XHCI_USB_PORTSC2, regVal);    /* write PLS to PORTSC */

        regVal = HW_RD_REG32(baseAddr + XHCI_USB_PORTSC2);

        HW_SET_FIELD(regVal, XHCI_USB_PORTSC2_LWS, 0x0);     /* LWS = 0 */
        HW_WR_REG32(baseAddr + XHCI_USB_PORTSC2, regVal);    /* write it again */

#if defined(PRINT_COMPLIANCE_STATUS)
        uint32_t timeOut = 0;

        /* if required, print to console if we get to compliance state or not
         * for operational confirmation. But we don't want this to interfere
         * with normal usual operation since this operation delays the code 
         * execution a bit which might not be always desired. */
        debug_printf("checking to see if we are in compliance state\n");

        while(1)
        {
            regVal = HW_RD_REG32(baseAddr + XHCI_USB_PORTSC2);

            PLS = HW_GET_FIELD(regVal,  XHCI_USB_PORTSC2_PLS);

            if (PLS == 10)
            {
                debug_printf("PORTSC2 = 0x%x. PLS=%d. Port is in compliance state\n", regVal, PLS);
                break;
            }

            usb_osalDelayMs(100);
            timeOut++;

            if (timeOut > 10)   /* wait for about 1 second */
            {
                debug_printf("Time out while waiting for compliance state. PORTSC2 = 0x%x. PLS=%d\n",
                             regVal, PLS);

                break;
            }
        }
#endif
    }
}


/* call back from Cadence driver when a port is disconnect */
void xhciPortChangeCallback(uint32_t portStatus, uint8_t portId)
{
    if ((portStatus & USBSSP__PORTSC1USB3__CCS_MASK) == 1U) {
        /* something connected to host port */;
    } else {
        /* port disconnect happens */
        USBHCDDisconnect(0);
    }
}

/* main init for xhci */
void USB_Host_Init(uint32_t instNo) 
{
    USBSSP_DriverResourcesT * xhciRes = 0;

    xhciRes = &g_usb_global.drv_instances[instNo].xhci_driver_resources;

#ifdef _DEBUG_
    g_dbg_enable_log = 0xFFFFFFFF;
    g_dbg_log_lvl = DBG_WARN;
#endif

    usbPhyOn(instNo, 0); /* no invert polarity */
    usbClockCfg(instNo);

    xhciRes->preportChangeDetectCallback = xhciPortChangeCallback;
    USBSSP_Init(xhciRes, gSocXhciBase[instNo]);

#ifdef ENABLE_COMPLIANCE_TEST
    /* enable xhci compliance - only enable if necessary. It prevents normal USB operation. */
    enableComplianceMode(instNo);
#endif
}

volatile static uint32_t epIN, epOUT;
volatile static uint32_t epInComplete, epOutComplete;

static inline uint8_t epAddrToIndex(uint8_t epAddr) {

    uint8_t epNum = epAddr & (~0x80);
    uint8_t epDir = epAddr & 0x80;
    uint8_t epIndex = (2 * epNum) + ((epDir > 0) ? 1 : 0);
    return epIndex;
}

static uint8_t findEpBulk(uint8_t * conf, int inFlag, uint32_t confLen) {

    int index = 0;
    uint8_t ret = 0;

    while (index < confLen) {
        if ((conf[index + 1] == CH9_USB_DT_ENDPOINT) && conf[index + 3] == CH9_USB_EP_BULK) {

            uint8_t epAddr = conf[index + 2];

            if ((inFlag != 0) && ((epAddr & 0x80) > 0)) {
                ret = epAddr;
                break;
            }
            if ((inFlag == 0) && ((epAddr & 0x80) == 0)) {
                ret = epAddr;
                break;
            }
        }
        index += conf[index];
    }
    return epAddrToIndex(ret);
}

uint32_t xhci_enum(uint32_t instNo) {
    uint32_t result;
    uint32_t conf_length;

    USBSSP_DriverResourcesT * ssp_ref = 0;

    ssp_ref = &g_usb_global.drv_instances[instNo].xhci_driver_resources;

    result = USBSSP_GetDescriptor(ssp_ref, CH9_USB_DT_DEVICE);

    if ((result != 0) && (result != CDN_ETIMEDOUT))
    {
        /* if we get any error other than timeout error */
        return result;
    }
    
    if (result == CDN_ETIMEDOUT)
    {
        /* if we get timeout error for this first host request it means we 
         * might not have a device plugged in. This is normal with USB host.
         * So  translate this error to an OK  so that the application
         * can start again */
        return NO_DEVICE_CONNECTED;
    }

    saveDeviceDescriptor(instNo, ssp_ref->ep0Buff);

    result = USBSSP_GetDescriptor(ssp_ref, CH9_USB_DT_CONFIGURATION);
    if (result != 0) return result;

    conf_length = (uint32_t) ssp_ref->ep0Buff[2] | ((uint32_t) ssp_ref->ep0Buff[3] << 8);
    saveConfigDescriptor(instNo, ssp_ref->ep0Buff, conf_length);

    result = USBSSP_SetConfiguration(ssp_ref, 1);
    if (result != 0) return result;

    epIN = findEpBulk(ssp_ref->ep0Buff, 1, conf_length);
    epOUT = findEpBulk(ssp_ref->ep0Buff, 0, conf_length);

    debug_printf("%s:%d. Finish enumeration. epIn=0x%x. epOut=0x%x\n", 
                __FUNCTION__, __LINE__, epIN, epOUT);

    return 0;
}

#undef _DEBUG_
static void outTransferComplete(USBSSP_DriverResourcesT * arg) 
{
#ifdef _DEBUG_
    int completion_code = (((uint32_t*) arg)[2] >> 24) & 0xFF;
    int endpoint_index = (((uint32_t*) arg)[3] >> 16) & 0x1F;

    debug_printf("Transfer complete on endpoint: %d. compCode=0x%x\n", 
                  endpoint_index, completion_code);
#endif
    epOutComplete = 1;
}

static void inTransferComplete(USBSSP_DriverResourcesT * arg) 
{
#ifdef _DEBUG_
    int completion_code = (((uint32_t*) arg)[2] >> 24) & 0xFF;
    int endpoint_index = (((uint32_t*) arg)[3] >> 16) & 0x1F;

    debug_printf("Transfer complete on endpoint: %d. compCode=0x%x\n", 
                  endpoint_index, completion_code);
#endif
    epInComplete = 1;
}

/*--------------------------------------------------------------------
 * This function implements a Write on the Specified BULKOUTEndpoint 
 *-------------------------------------------------------------------*/ 
uint32_t USBHostWrite(uint32_t instanceNumber,
                      uint8_t uEndPoint, 
                      uint8_t *puData, 
                      uint32_t uSize) 
{
    uint32_t result = 0;
    USBSSP_DriverResourcesT * ssp_ref = 0;
    epOutComplete = 0;

    ssp_ref = &g_usb_global.drv_instances[instanceNumber].xhci_driver_resources;

#ifdef _DEBUG_
    debug_printf("inst: %d, uEndPoint: 0x%x, epOut=0x%x, puData: %08x, uSize: %ld\n", 
                  instanceNumber, uEndPoint, epOUT, (uintptr_t) puData, uSize);
#endif

    /* push the data from cache out */
    usb_osalCacheWb(puData, uSize);

    result = USBSSP_TransferData(ssp_ref, epOUT, (uintptr_t) puData, uSize, outTransferComplete);

    while (epOutComplete == 0) {
    }

#ifdef _DEBUG_
    int i;
    debug_printf("DATA OUT: ");

    for (i = 0; i < 8; i++)
        debug_printf("%02x ", puData[i]);

    debug_printf("\n");
#endif

    return result;
}


uint32_t USBHostRead(uint32_t instanceNumber, 
                     uint8_t uEndPoint, 
                     uint8_t *puData, 
                     uint32_t uSize) 
{
    uint32_t result = 0;
    USBSSP_DriverResourcesT * ssp_ref = 0;

    epInComplete = 0;

    ssp_ref = &g_usb_global.drv_instances[instanceNumber].xhci_driver_resources;

#ifdef _DEBUG_
    debug_printf("inst: %d, uEndPoint: 0x%x, epIN=0x%x, puData: %08x, uSize: %ld\n", 
                instanceNumber, uEndPoint, epIN, (uintptr_t) puData, uSize);
#endif

    /* write back and invalidate the cache line first */
    usb_osalCacheWbInv(puData, uSize);

    result = USBSSP_TransferData(ssp_ref, epIN, (uintptr_t)puData, 
                                 uSize, inTransferComplete);

    while (epInComplete == 0) {
    }

#ifdef _DEBUG_
    int i;
    debug_printf("DATA IN: ");

    for (i = 0; i < 8; i++)
        debug_printf("%02x ", puData[i]);

    debug_printf("\n");
#endif

    return result;
}



uint32_t xhci_reset_device(uint32_t instanceNumber) {
    //    vDbgMsg(DBG_EXTERNAL_STACK, DBG_FYI, "instanceNumber: %d\n", instanceNumber);
    //    vDbgMsg(DBG_EXTERNAL_STACK, DBG_FYI, "NOT IMPLEMENTED!\n", 0);
    return 0;
}



uint32_t USBHostControlTransfer(uint32_t instanceNumber, 
                                usbSetupPkt_t *pSetupPkt, 
                                uint8_t* pData, uint32_t uSize) 
{
    uint32_t result;
    USBSSP_DriverResourcesT * ssp_ref = 0;

    ssp_ref = &g_usb_global.drv_instances[instanceNumber].xhci_driver_resources;

    debug_printf("instanceNumber: %d, puData: %08x, uSize: %ld\n", 
                  instanceNumber, (uintptr_t) pData, uSize);

    result = USBSSP_ControlTransfer(ssp_ref, (CH9_UsbSetup *) pSetupPkt, pData);
    return result;
}


void usbHostIntrHandler(void * pdata) {
    USBSSP_Isr((USBSSP_DriverResourcesT *) pdata);
}


void USBHCDConfigureEndpoints(uint32_t ulIndex, 
                              tUSBHostDevice *pDevice, 
                              uint32_t* inPipe, uint32_t* outPipe) 
{
    debug_printf("%s:%d. inPipe=0x%x. outPipe=0x%x. to be implemented\n", 
                __FUNCTION__, __LINE__, (uintptr_t)inPipe, (uintptr_t)outPipe);
}

#endif /* USE_CDN_XHCI */

