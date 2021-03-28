/**
 *  \file     usb_xhci_hcd.c
 *
 *  \brief    Provides APIs for the USB xHCI module in host mode. This acts as 
*             the HAL layer that accesses the hardware.
 *
 *  \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
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
#include "hw_types.h"
#include "string.h"
#include "error.h"
#include "debug.h"

#include "hw_usb.h"

#include "hw_dwc_usb.h"
#include "usb_hcd_xhci.h"
#include "UsbDefs.h"
#include "usb_dwc.h"
#include "usb_drv.h"

#include "usblib.h"
#include "usbhost.h"
#include "usb_osal.h"

#include "usb_wrapper.h"


/*Function Declarations */

void     USB_Host_Init(uint32_t instanceNumber);

uint32_t USBHostConfigureEndpoint(uint32_t instanceNumber, 
                                  uint8_t  uEndPoint,
                                  uint16_t MaxPayload,
                                  uint16_t uNAKPollInterval,
                                  uint32_t TransferRing,
                                  uint8_t  EPType);

uint32_t USBHostGetDeviceDescriptor(uint32_t instanceNumber, uint8_t uAddress);
uint32_t USBHostSetAddress(uint8_t uAddress);
uint32_t USBHostSetConfiguration(uint32_t instanceNumber);
uint32_t USBHostGetConfigurationDescriptor(uint32_t instanceNumber);
void     USBH_PHYConfig(void);
uint32_t xhci_enum(uint32_t instanceNumber);
void     USBHCDTerm(uint32_t portIndex);
static uint32_t xhci_handle_psc_event(uint32_t instanceNumber, 
                                      struct xhci_event_cmd* ptrEvent);

extern   USB_MEM_S        g_usb_global;

uint32_t gSocUsbInstAddrArray[]     =   {USB0_DWC_WRAPPER_BASE_ADDR,
                                         USB1_DWC_WRAPPER_BASE_ADDR};

uint32_t gSocUsbControllerInstOffsetArray[]  = {USB_DWC_CORE_OFFSET,
                                                USB_DWC_CORE_OFFSET};

uint32_t gSocUsbWrapperInstOffsetArray[]  = {0x0U,0x0U};


/**
* \brief Enumeration for different modes supported by a controller instance.
*/
typedef enum controllerMode
{
    CONTROLLER_MODE_HOST                = 1U,
    /**< controller functions as a host only.*/
    CONTROLLER_MODE_DEVICE              = 2U,
    /**< controller functions as a device only.*/
    CONTROLLER_MODE_DUAL_ROLE_DEVICE     = 3U
    /**< controller functions as both host and device.*/

}controllerMode_t;

uint32_t XhciRegBaseAddr(uint32_t instNum) 
{
    return(gSocUsbInstAddrArray[instNum] + gSocUsbControllerInstOffsetArray[instNum]); 
}

uint32_t UsbWrapRegBaseAddr(uint32_t instNum) 
{
    return(gSocUsbInstAddrArray[instNum] + gSocUsbWrapperInstOffsetArray[instNum]); 
}

uint32_t USBSSGetGlobalHostIntrStatus(uint32_t instNum) 
{
    uint32_t regVal = HW_RD_REG32(XhciRegBaseAddr(instNum) + DWC_USB_GSTS);   
    /* Host interrupt status bit is at the 7th position.*/    
    regVal &= (0x1<<7);
    return(regVal);
}

uint32_t USBSSGetGlobalDevIntrStatus(uint32_t instNum) 
{
    uint32_t regVal = HW_RD_REG32(XhciRegBaseAddr(instNum) + DWC_USB_GSTS);
    /* Host interrupt status bit is at the 8th position.*/    
    regVal &= (0x1<<8);
    return(regVal);
}

uint32_t USBSSGetGlobalOTGIntrStatus(uint32_t instNum) 
{
    uint32_t regVal = HW_RD_REG32(XhciRegBaseAddr(instNum) + DWC_USB_GSTS);
    /* Host interrupt status bit is at the 11th position.*/    
    regVal &= (0x1<<11);
    return(regVal);
}



void XHCIIsrEntryActions (uint32_t instNum) 
{
    
    /* 1. Disable further xHC interrupts.*/
    HW_WR_FIELD32((XhciRegBaseAddr(instNum) + DWC_USB_USBCMD), DWC_USB_USBCMD_INTE, 0x00);
    /*2. Clear the present interrupt. */
    HW_WR_FIELD32((XhciRegBaseAddr(instNum) + DWC_USB_USBSTS), DWC_USB_USBSTS_EINT, 0x01);
    HW_WR_FIELD32((XhciRegBaseAddr(instNum) + DWC_USB_IMAN(INTERUPTER1)), DWC_USB_IMAN_IP, 
            DWC_USB_IMAN_IP_IDLE);
}

void XHCIIsrExitActions (uint32_t instNum) 
{
    
    /* 1. Enable further xHC interrupts.*/
    HW_WR_FIELD32((XhciRegBaseAddr(instNum) + DWC_USB_USBCMD), DWC_USB_USBCMD_INTE, 0x01);

}


void XHCIIntrEnable (uint32_t instNum) 
{
    /* 1. Enable xHC interrupts.*/
    HW_WR_FIELD32((XhciRegBaseAddr(instNum) + DWC_USB_USBCMD), DWC_USB_USBCMD_INTE, 0x01);
}


void XHCIIntrDisable (uint32_t instNum) 
{   
    /* 1. Disable xHC interrupts.*/
    HW_WR_FIELD32((XhciRegBaseAddr(instNum) + DWC_USB_USBCMD), DWC_USB_USBCMD_INTE, 0x00);
}



/*--------------------------------------------------
--------------------------------------------------*/
static void xhci_wait_for_event(uint32_t baseAddr)
{
#if (defined(SOC_K2G) || defined (SOC_AM65XX) || defined (SOC_J721E))
    /* use USBSTS instead of IMAN since USBSTS_EINT can be set from any interrupter */
    while ((HW_RD_FIELD32(baseAddr + DWC_USB_USBSTS, DWC_USB_USBSTS_EINT) != 1));

#elif (defined(SOC_AM574x) || defined(SOC_AM572x)||defined(SOC_AM571x)||defined(AM57XX_FAMILY_BUILD)||defined(AM43XX_FAMILY_BUILD)||defined(SOC_AM437x) || defined (SOC_DRA72x) || defined (SOC_DRA75x))

    while ((HW_RD_REG32(baseAddr + DWC_USB_IMAN(1)) & DWC_USB_IMAN_IP_MASK) 
        != DWC_USB_IMAN_IP_PENDING);
#else
#error "SOC family is unknown"
#endif

}


/*--------------------------------------------------
--------------------------------------------------*/
static uint32_t xhci_pending_event(uint32_t baseAddr)
{
#if (defined(SOC_K2G) || defined (SOC_AM65XX) || defined(SOC_J721E))
    if (HW_RD_FIELD32(baseAddr + DWC_USB_USBSTS, DWC_USB_USBSTS_EINT) == 1)
#elif (defined(SOC_AM574x) || defined(SOC_AM572x)||defined(SOC_AM571x)||\
      defined(AM57XX_FAMILY_BUILD)||\
      defined(AM43XX_FAMILY_BUILD)||defined(SOC_AM437x) || \
      defined (SOC_DRA72x) || defined (SOC_DRA75x))
    /* use this IMAN for AM5/AM4 devices. */
    if (HW_RD_FIELD32(baseAddr + DWC_USB_IMAN(1), DWC_USB_IMAN_IP) == 
         DWC_USB_IMAN_IP_PENDING) 
#else
#error "SOC family is unknown"
#endif
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*--------------------------------------------------
--------------------------------------------------*/
static uint32_t Command_Completion_Handler(uint32_t instanceNumber)
{
    union xhci_transfer_event *lv_ptrTRB;
    uint32_t regval = 0x0;
    uint32_t compCode = 0;
    uint32_t baseAddr;
    uint32_t temp;

    XHCI_DATA_S* xhciData = 0;
   
    baseAddr = XhciRegBaseAddr(instanceNumber); 
    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;

    
    /*debug_printf("%s. byEventRingIdex=%d. xhciData->PtrEvent=0x%x\n",  */
    /*                    __FUNCTION__, xhciData->byEventRingIndex, (uint32_t)xhciData->PtrEvent);  */

    HW_WR_FIELD32(baseAddr + DWC_USB_USBSTS, DWC_USB_USBSTS_EINT, 0x01);
    
    HW_SET_FIELD(regval, DWC_USB_IMAN_IE, DWC_USB_IMAN_IE_EN); 
    HW_SET_FIELD(regval, DWC_USB_IMAN_IP, DWC_USB_IMAN_IP_PENDING); 
    HW_WR_REG32(baseAddr + DWC_USB_IMAN(1), regval);
    
    /* ERDP needs to be written with the Enqueue pointer which is next event's address */
    /* If same event is written IP is not cleared since Event ring did not get cleared */

    if((EVENT_RING_SIZE-1) == xhciData->byEventRingIndex)
    {
        regval = (uint32_t) &(xhciData->Command_Completion_Event[0])|ERST_EHB;
        HW_WR_REG32(baseAddr + DWC_USB_ERDP_LO(1), regval);    
        HW_WR_REG32(baseAddr + DWC_USB_ERDP_HI(1), 0x0);        
    }
    else
    {
        temp = xhciData->byEventRingIndex+1;
        ASSERT(temp < 16);

        temp = temp & 0xFF;     /* bound enforcement - MISRA C */
        regval = (uint32_t) &xhciData->Command_Completion_Event[temp]|ERST_EHB;
        HW_WR_REG32(baseAddr + DWC_USB_ERDP_LO(1), regval);    
        HW_WR_REG32(baseAddr + DWC_USB_ERDP_HI(1), 0x0);      
        
    }

    /*Clear the TRB Fields */
    lv_ptrTRB =  (union xhci_transfer_event *)xhciData->PtrEvent->command_trb_ptr_lo;

    compCode = GET_COMP_CODE(xhciData->PtrEvent->completioncode);

    /*Check which endpoint caused this event */
    if((TRB_TO_EP_INDEX(xhciData->PtrEvent->trb_slotid) == xhciData->uBulkINDB )&& 
       (TRB_FIELD_TO_TYPE(lv_ptrTRB->normal_trb.flags) == TRB_T_NORMAL))
    {
    	xhciData->uBulkINCompletion++;

        if(COMP_SUCCESS == compCode)
        {
        	xhciData->uBulkINSuccesfulCompletion++;
            /*DebugArray[temp++%512]=(uint32_t)xhciData->PtrEvent->command_trb_ptr_lo; */
        }

    }
    else if(TRB_TO_EP_INDEX(xhciData->PtrEvent->trb_slotid) == xhciData->uBulkOUTDB)
    {
    	xhciData->uBulkOUTCompletion++;
    }
    else
    {
    }

 
    /*if(COMP_SUCCESS == compCode) */
    {
    	xhciData->countofCompletion++;
        if(EVENT_RING_SIZE-1 == xhciData->byEventRingIndex)
        {
            xhciData->byEventRingIndex = 0;
            xhciData->PtrEvent = &xhciData->Command_Completion_Event[0];
        }
        else
        {
            xhciData->PtrEvent++;
            xhciData->byEventRingIndex++;
        }

        /* re-enable interrupt */
        usbDwcDcdEnableWrapperIntr(UsbWrapRegBaseAddr(instanceNumber));
    }

    return compCode;
}

extern int32_t usbClockSSCfg(void);

#ifdef USB3_DEBUG
extern void usb30Debug(void);
#endif

#define XHCI_PORT_RO    ((1<<0) | (1<<3) | (0xf<<10) | (1<<30))
#define XHCI_PORT_RWS    ((0xf<<5) | (1<<9) | (0x3<<14) | (0x7<<25))

extern USB_Config USB_config[3];

/* enabling compliance mode for xHCI1.1 
 * Compliance mode seems to require SERDES turned on
 * If SERDES is not turned on, the xHCI does not not working properly 
 * Only do this if the config asks us to enable USB3.0 
 */
void enableComplianceMode(uint32_t instanceNumber)
{
    uint32_t regVal = 0;
    USB_Config* usbConfig = &USB_config[instanceNumber];
    uint32_t baseAddr = 0;
    uint32_t PP = 0, CCS=0, PED=0, PR=0;

    baseAddr = XhciRegBaseAddr(instanceNumber); 

    if ((instanceNumber == 0) && /* only port #0 supports SS */
       (usbConfig->usb30Enabled == TRUE) /* SOC support */)
    {

        while (1)
        {
            regVal = HW_RD_REG32(baseAddr + DWC_USB_PORTSC2);
            PR = HW_GET_FIELD(regVal,  DWC_USB_PORTSC2_PR);
            if (PR == 0) break;
        }

        /* attempt to turn on compliance mode */
        debug_printf("Enable compliance mode\n");

        /* CTE can only be set to 1 if port is in disconnected state and with PLS = RX_detect*/
        debug_printf("checking to see if we are in disconnected state\n");
        regVal = HW_RD_REG32(baseAddr + DWC_USB_PORTSC2);

        PP  = HW_GET_FIELD(regVal,  DWC_USB_PORTSC2_PP);
        CCS = HW_GET_FIELD(regVal,  DWC_USB_PORTSC2_CCS);
        PED = HW_GET_FIELD(regVal,  DWC_USB_PORTSC2_PED);
        PR  = HW_GET_FIELD(regVal,  DWC_USB_PORTSC2_PR);

        debug_printf("PORTSC2 = 0x%x. PP=%d. CCS=%d. PED=%d. PR=%d. PLS=%d\n",
                      regVal, PP,CCS, PED, PR, (HW_GET_FIELD(regVal,  DWC_USB_PORTSC2_PLS)));

        if ((PP != 1)|| (CCS!=0) || (PED!=0) || (PR!=0) )
        {
            debug_printf("Port is not in disconnected state while trying to enable CTE\n");
        }

        regVal = 0;
        HW_SET_FIELD(regVal, DWC_USB_PORTSC2_PP,  0x1);     /* PP = 1 */
        HW_WR_REG32(baseAddr + DWC_USB_PORTSC2, regVal);    /* write PP to PORTSC */

        regVal = HW_RD_REG32(baseAddr + DWC_USB_PORTSC2);

        HW_SET_FIELD(regVal, DWC_USB_PORTSC2_LWS, 0x1);     /* LWS = 1 to write to PLS */
        HW_SET_FIELD(regVal, DWC_USB_PORTSC2_PLS, DWC_USB_PORTSC2_PLS_COMPLIANCEMODE);
       
        HW_WR_REG32(baseAddr + DWC_USB_PORTSC2, regVal);    /* write PLS to PORTSC */

        regVal = HW_RD_REG32(baseAddr + DWC_USB_PORTSC2);

        HW_SET_FIELD(regVal, DWC_USB_PORTSC2_LWS, 0x0);     /* LWS = 0 */
        HW_WR_REG32(baseAddr + DWC_USB_PORTSC2, regVal);    /* write it again */

#if defined(PRINT_COMPLIANCE_STATUS)
        uint32_t timeOut = 0;
	uint32_t PLS=0;

        /* if required, print to console if we get to compliance state or not
         * for operational confirmation. But we don't want this to interfere
         * with normal usual operation since this operation delays the code 
         * execution a bit which might not be always desired. */
        debug_printf("checking to see if we are in compliance state\n");

        while(1)
        {
            regVal = HW_RD_REG32(baseAddr + DWC_USB_PORTSC2);

            PLS = HW_GET_FIELD(regVal,  DWC_USB_PORTSC2_PLS);

            if (PLS == 10)
            {
                debug_printf("PORTSC2 = 0x%x. PLS=%d. Port is in compliance state\n", regVal, PLS);
                break;
            }

            usb_osalDelayMs(100);
            timeOut++;

            if (timeOut > 10)   /* wait for 1.1 second */
            {
                debug_printf("Time out while waiting for compliance state. PORTSC2 = 0x%x. PLS=%d\n",
                             regVal, PLS);

                break;
            }
        }
#endif
    }
}


/*--------------------------------------------------
--------------------------------------------------*/
void USB_Host_Init(uint32_t instanceNumber)
{
    /*xHCI specific initialization */
    /*Initialize the Data Structures, Device Context ,etc. */
    uint32_t temp_address;
    uint32_t cszField;
    uint32_t baseAddr;
    uint32_t regVal;
    uint32_t maxPort;
    uint32_t i;
    XHCI_DATA_S* xhciData = 0;

#if DOING_SERDES_AFTER_CORE_INIT
    USB_Config* usbConfig = &USB_config[instanceNumber];
#endif

    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr = XhciRegBaseAddr(instanceNumber); 

    xhciData->usbInstance = instanceNumber;

    usbPhyOn(instanceNumber, 0); /* no invert polarity */
    usbClockCfg(instanceNumber);

    xhciData->scratchPadPointer     = (uint32_t)&(xhciData->scratchpadBuffer[0]);

    xhciData->dcbaa.slot0_addresslo = (uint32_t)&(xhciData->scratchPadPointer);
    xhciData->dcbaa.slot0_addresshi = 0; /*We use only 32 bit address */
    xhciData->dcbaa.slot1_addresslo = (uint32_t)&(xhciData->xhci_context.Slot_Context); /*64 byte aligned */
    xhciData->dcbaa.slot1_addresshi = 0; /*We use only 32 bit address */
    xhciData->dcbaa.slot2_addresslo = 0; /*64 byte aligned */
    xhciData->dcbaa.slot2_addresshi = 0; /*We use only 32 bit address */
    
    xhciData->bulkINRingCycleState        = xhciData->bulkOUTRingCycleState = 1;
    xhciData->byCommandRingIndex          = 0;
    xhciData->byCtrlTransferRingIndex     = 0;
    xhciData->byEventRingIndex            = 0;
    xhciData->byEpOUTRingIndex            = 0;
    xhciData->byEpINRingIndex             = 0;

    xhciData->countofINs = xhciData->countofOUTs = xhciData->countofCompletion = 0;
    xhciData->uBulkINCompletion = xhciData->uBulkOUTCompletion = 0;
    xhciData->uBulkINSuccesfulCompletion =0;

    /* validate if the XHC's Context Size (CSZ) against the assumed configuration */
    cszField = HW_RD_FIELD32(baseAddr + DWC_USB_HCCPARAMS, DWC_USB_HCCPARAMS_CSZ);

    /* When cszField is 0, xHCI uses 32 bytes for slot_context.
     * If it's 1, slot_context size is 64 bytes */
    if  (((cszField == 0) && (sizeof(struct xhci_slot_context) > sizeof(uint32_t)*8)) ||
         ((cszField == 1) && (sizeof(struct xhci_slot_context) == sizeof(uint32_t)*8))) 
    {
        debug_printf("wrong CSZ configuration\n");
        return;
    }

    /* make sure max port number config is valid */
    maxPort = (HW_RD_REG32(baseAddr + DWC_USB_HCSPARAMS1) >> 24) & 0xF;
    if (maxPort > MAX_XHCI_PORT)
    {
        debug_printf("wrong max port configuration\n");
        return;
    }

    /*Refer to Section 4.2 Host Initialization section of xHCI Spec */

    /*Doing Host Controller Reset */
    HW_WR_FIELD32(baseAddr + DWC_USB_USBCMD, DWC_USB_USBCMD_HCRST, 1U);
    while((HW_RD_REG32(baseAddr + DWC_USB_USBCMD) & DWC_USB_USBCMD_HCRST_MASK) != 0); 

    /* wait for Controller Not Ready to go 0 */
    while(HW_RD_FIELD32(baseAddr + DWC_USB_USBSTS, DWC_USB_USBSTS_CNR));
    
    /*Setting the DWC3 controller for Host mode operation */
    regVal = HW_RD_REG32(baseAddr + DWC_USB_GCTL); 
    regVal  &= ~(3 << DWC_USB_GCTL_PRTCAPDIR_SHIFT); /* prtcapdir clr - tt - This line seems crucial **** */
    HW_WR_REG32(baseAddr + DWC_USB_GCTL, regVal); 
    regVal |= (DWC_USB_GCTL_PRTCAPDIR_HST << DWC_USB_GCTL_PRTCAPDIR_SHIFT);
    HW_WR_REG32(baseAddr + DWC_USB_GCTL, regVal );

#ifdef SOC_AM65XX
    /* xHCI v1.1 disable Compliance mode by default */
    enableComplianceMode(instanceNumber);
#endif

    /* USB3.0 */
    /*regVal = HW_RD_REG32(baseAddr + DWC_USB_GUSB3PIPECTL); */
    /*HW_WR_FIELD32(baseAddr + DWC_USB_GUSB3PIPECTL, DWC_USB_GUSB3PIPECTL_LFPSFILT, 1); */
    HW_WR_REG32(baseAddr + DWC_USB_GUSB3PIPECTL, 0x00040002); /* this value gives a much cleaner LSSM */


    /*Write to Config Register. Doing this after the host rst above.  */
    /*otherwise enable_slot command will fail */
    HW_WR_FIELD32(baseAddr + DWC_USB_CONFIG, DWC_USB_CONFIG_MAXSLOTSEN, NO_OF_SLOTS);

    /* Device context base address pointer */
    /*This one was creating trouble as our allingnment was 64byte  */
    temp_address = (uint32_t)&xhciData->dcbaa;
    HW_WR_REG32(baseAddr + DWC_USB_DCBAAP_LO, temp_address);
    HW_WR_REG32(baseAddr + DWC_USB_DCBAAP_HI, 0x0);  /* we are only using 32 bit address */

    /*This is used for sending Commands to the controller */
    /* Set ring cycle state to 1  */
    temp_address = (uint32_t)((uint32_t)&(xhciData->Command_Ring)[0]);
    HW_SET_FIELD(temp_address, DWC_USB_CRCR_LO_RCS, 0x01); 

    HW_WR_REG32(baseAddr + DWC_USB_CRCR_LO, temp_address);
    HW_WR_REG32(baseAddr + DWC_USB_CRCR_HI, 0x0);

    /*Initialize Event Segment xHCI Section 6.5 details the structure */
    xhciData->Event_Ring_Segment_Entry.seg_addr_lo = 
         (uint32_t) &xhciData->Command_Completion_Event[xhciData->byEventRingIndex];
    xhciData->Event_Ring_Segment_Entry.seg_size = 16;
    
    /* definitiion is #define DWC_USB_ERSTSZ(n)   (0x468U + ((n-1) * 0x20U)) */
    /* hence to set interrupter 0 use 1 as param  */
    HW_WR_FIELD32(baseAddr + DWC_USB_ERSTSZ(1), DWC_USB_ERSTSZ_ERS_TBL_SIZE, EVENT_RING_SEGMENTS_SIZE);

    temp_address = (uint32_t) &xhciData->Event_Ring_Segment_Entry;
    HW_WR_REG32(baseAddr + DWC_USB_ERSTBA_LO(1), temp_address);
    HW_WR_REG32(baseAddr + DWC_USB_ERSTBA_HI(1), 0x0);

    temp_address = (uint32_t) &xhciData->Command_Completion_Event[xhciData->byEventRingIndex];
    HW_WR_REG32(baseAddr + DWC_USB_ERDP_LO(1), temp_address);    
    HW_WR_REG32(baseAddr + DWC_USB_ERDP_HI(1), 0x0);

    /*The last entries in the rings should be link TRBs to make it a circular ring */
    /*xHCI Section 4.9.2 */
    xhciData->EP0_Transfer_Ring[EP0_TRANSFER_RING_SIZE-1].normal_trb.bufferlo= 
                    (uint32_t)&xhciData->EP0_Transfer_Ring[0]; /*Link it to first TRB */
    xhciData->EP0_Transfer_Ring[EP0_TRANSFER_RING_SIZE-1].normal_trb.bufferhi=0;
    xhciData->EP0_Transfer_Ring[EP0_TRANSFER_RING_SIZE-1].normal_trb.transfer_len = 0;
    xhciData->EP0_Transfer_Ring[EP0_TRANSFER_RING_SIZE-1].normal_trb.flags = TRB_TYPE(TRB_LINK)|TRB_CYCLE;

    xhciData->Command_Ring[COMMAND_RING_SIZE-1].command_trb_ptr_lo= 
                    (uint32_t)&xhciData->Command_Ring[0]; /*Link it to first TRB */
    xhciData->Command_Ring[COMMAND_RING_SIZE-1].command_trb_ptr_hi=0;
    xhciData->Command_Ring[COMMAND_RING_SIZE-1].completioncode = 0;
    xhciData->Command_Ring[COMMAND_RING_SIZE-1].trb_slotid = TRB_TYPE(TRB_LINK)|TRB_CYCLE;

    /*Initialize the Event Ring with Zero entries */
    memset(xhciData->Command_Completion_Event,0, (16 * EVENT_RING_SIZE));

    for (i=0; i<MAX_XHCI_PORT; i++)
    {
        xhciData->xhciPortState[i] = USB_HOST_UNKNOWN;
    }
    
    /*Disabling Interrupt Throttling timer */
    HW_WR_REG32(baseAddr + DWC_USB_IMOD(1), 0);  /* both IMODI and IMODC = 0 */
 
    HW_WR_FIELD32(baseAddr + DWC_USB_IMAN(1), DWC_USB_IMAN_IE, DWC_USB_IMAN_IE_EN);
 
    HW_WR_FIELD32(baseAddr + DWC_USB_USBCMD, DWC_USB_USBCMD_INTE, 0x01);

    HW_WR_FIELD32(baseAddr + DWC_USB_USBCMD, DWC_USB_USBCMD_R_S, 0x01);

#if DOING_SERDES_AFTER_CORE_INIT
#ifdef SOC_AM65XX
    if ((instanceNumber == 0) && /* only port #0 supports SS */
       (usbConfig->usb30Enabled == TRUE) /* SOC support */)
    {
        /* failing to enable SERDES for USB3.0 would still enable USB2.0 
           so not failing here */
        if (usbClockSSCfg() != 0)
        {
            debug_printf("Error when enabling Super Speed\n");
        }
    }
#endif
#endif

#ifdef USB3_DEBUG
    usb30Debug();
#endif
} /* USB_Host_Init */




uint32_t USBHostConfigureEndpoint(uint32_t instanceNumber, 
                                  uint8_t  uEndPoint,
                                  uint16_t MaxPayload, 
                                  uint16_t uNAKPollInterval,
                                  uint32_t TransferRing,
                                  uint8_t  EPType)
{
    uint32_t DCI = 0;
    uint32_t direction = 0;
    uint32_t compCode = 0;
    uint32_t baseAddr = 0;
    uint32_t rc = 0;
    struct xhci_event_cmd* cmdTrb;

    XHCI_DATA_S* xhciData = 0;

    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr = XhciRegBaseAddr(instanceNumber); 

    debug_printf("%s. EP=%d. pks=%d. epType=%d\n", 
                __FUNCTION__, uEndPoint, MaxPayload, EPType);

    if (EPType == BULK_OUT_EP) 
    {
        direction = USB_HOST_OUT;
    } 
    else if (EPType == BULK_IN_EP) 
    {
        direction = USB_HOST_IN;
    }

    DCI = ((uEndPoint*2)+direction)-1;      /*Refer xHCI Section 4.5.1 for DCI. Out direction is 0. */
                                            /*Slot context is not in out EP_Context array so doing -1 here */

    xhciData->xhci_context.EndPoint_Context[DCI].epinfo0 = EP_INTERVAL(uNAKPollInterval); /*Rest of Fields should be Zero */
                                                                                /* for USB2.0 Endpoints */
    xhciData->xhci_context.EndPoint_Context[DCI].epinfo1 = (EP_TYPE(EPType)|
                                                  MAX_PACKET(MaxPayload)|
                                                  MAX_BURST(0)|
                                                  ERROR_COUNT(3));  /* Error count 3 sec 4.8.2.1 in xHCI Spec */

    xhciData->xhci_context.EndPoint_Context[DCI].TRDeqPtrLo = (TransferRing | EP_CTX_CYCLE_MASK);

    if(uEndPoint) /* Do this step for EPnums other than Zero */
    {
        cmdTrb = &xhciData->Command_Ring[xhciData->byCommandRingIndex];

        xhciData->xhci_context.Input_Control_Context.add_flags =  (1<< (DCI+1)) | 1; /* A0 = 1 */

        /*Set Context Entries to DCI */
        xhciData->xhci_context.Slot_Context.device_info0 = (LAST_CTX(DCI+1)| 
                                                  (0 << 26)   |           /* not a hub */
                                                  (0 << 25)   |           /* mtt */
                                                  ((xhciData->xhciPortSpeed & 0xF) << 20)); 

        cmdTrb->command_trb_ptr_lo = (uint32_t) &(xhciData->xhci_context.Input_Control_Context);
        cmdTrb->trb_slotid = TRB_TYPE(TRB_CONFIG_EP);
        cmdTrb->trb_slotid |= TRB_CYCLE | 
                              SLOT_ID_FOR_TRB(xhciData->Slot_ID);

        xhciData->byCommandRingIndex++;
        HW_WR_REG32(baseAddr + DWC_USB_DB(1), DB_VALUE_HOST);   /* Command Ring */
        
        /*Wait for Pending interrupt */
        xhciData->expectingTrbType = TRB_COMMAND_COMPLETION;
        xhci_wait_for_event(baseAddr);

        if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_COMMAND_COMPLETION)
        {
            compCode = Command_Completion_Handler(instanceNumber);

            if (COMP_SUCCESS != compCode)
            {
                return (ERR_USB_HOST_CONFIG_EP_FAILED|compCode);
            }
        }
        else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
        {
            debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                        __LINE__, xhciData->PtrEvent); 

            rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

            if (rc != NO_ERROR) 
            {
                return rc;
            }
        }
        else 
        {
            debug_printf("%d. unexpected TRB type. ptrEvent=0x%x. TRB type=%d\n", 
                        __LINE__, xhciData->PtrEvent, 
                        TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid)); 

            return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
        }
    }

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    return NO_ERROR;

} /* USBHostConfigureEndpoint */


uint32_t USBHostGetDeviceDescriptor(uint32_t instanceNumber, uint8_t uAddress)
{
    uint32_t doorbell_val = 0x0;
    uint32_t compCode = 0;
    uint32_t baseAddr = 0;
    uint32_t rc = 0;

    XHCI_DATA_S* xhciData = 0;
    uint32_t     ctrlRingIdx = 0;

    union xhci_transfer_event* ep0Ring;
   
 
    baseAddr = XhciRegBaseAddr(instanceNumber); 
    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;
    ep0Ring  = xhciData->EP0_Transfer_Ring;

    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*Setup Stge */
    ep0Ring[ctrlRingIdx].control_trb.bmRequestType = (USB_RTYPE_DIR_IN|
                                                                USB_RTYPE_STANDARD|
                                                                USB_RTYPE_DEVICE);

    ep0Ring[ctrlRingIdx].control_trb.bRequest = 6U;
    ep0Ring[ctrlRingIdx].control_trb.wValue = 0x100;
    ep0Ring[ctrlRingIdx].control_trb.wIndex = 0;
    ep0Ring[ctrlRingIdx].control_trb.wLength = xhciData->ep0MaxPs; 
    ep0Ring[ctrlRingIdx].control_trb.transfer_len = 8;
    ep0Ring[ctrlRingIdx].control_trb.flags = TRB_TYPE(TRB_SETUP)|
                                                       TRB_IDT|TRB_CYCLE;

    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*Data Stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferlo= (uint32_t)(xhciData->uDataReceived);
    ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;  /*only 32 bit address used */
    ep0Ring[ctrlRingIdx].normal_trb.transfer_len = xhciData->ep0MaxPs; 
    ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_DATA)|
                                                      TRB_DIR_IN|TRB_CYCLE;/*|TRB_ISP; */
    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*status Stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferlo= 0; 
    /*Data Buffer Pointer Zero for uint32_t stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;
    ep0Ring[ctrlRingIdx].normal_trb.transfer_len = 0;
    ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_T_STATUS)|TRB_CYCLE|TRB_IOC;

    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /* Ring the Slot1 door bell. */
    doorbell_val = DB_VALUE(0,0);
    HW_WR_REG32(baseAddr + DWC_USB_DB(2), doorbell_val);
    
    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_TRANSFER;
    xhci_wait_for_event(baseAddr);

    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_TRANSFER)
    {
        compCode = Command_Completion_Handler(instanceNumber);
        if ((COMP_SUCCESS != compCode) && (COMP_SHORT_PACKET != compCode))
        {
            return (ERR_USB_HOST_GET_DEV_DESC | compCode);
        }

        saveDeviceDescriptor(instanceNumber, xhciData->uDataReceived);
    }
    else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    {
        debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                    __LINE__, xhciData->PtrEvent); 

        rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

        if (rc != NO_ERROR) 
        {
            return rc;
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    return NO_ERROR;

} /* USBHostGetDeviceDescriptor */



uint32_t USBHostGetConfigurationDescriptor(uint32_t instanceNumber)
{
    uint8_t  uNumEndPoints   =0;
    uint32_t compCode = 0;
    uint32_t rc;
    uint32_t ci = 0;

    tEndpointDescriptor_t *pEndPointDesc    = NULL;
    tConfigDescriptor_t *pConfigDesc    = NULL;
    tInterfaceDescriptor_t *pInterfaceDesc = NULL;

    uint16_t packetSize = 0;
    uint16_t wTotalLength = 0;
    uint32_t baseAddr;
    uint32_t ctrlRingIdx = 0;
    union xhci_transfer_event* ep0Ring;
    
    XHCI_DATA_S* xhciData = 0;


    xhciData    = &g_usb_global.drv_instances[instanceNumber].xhciData;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));
    ep0Ring     = xhciData->EP0_Transfer_Ring;
    baseAddr    = XhciRegBaseAddr(instanceNumber); 

    /*Setup Stge */
    ep0Ring[ctrlRingIdx].control_trb.bmRequestType = USB_RTYPE_DIR_IN|
                                                     USB_RTYPE_STANDARD|
                                                     USB_RTYPE_DEVICE;;
    ep0Ring[ctrlRingIdx].control_trb.bRequest = 6U;
    ep0Ring[ctrlRingIdx].control_trb.wValue = 0x200;
    ep0Ring[ctrlRingIdx].control_trb.wIndex = 0;
    ep0Ring[ctrlRingIdx].control_trb.wLength = xhciData->ep0MaxPs; /*uEP0Size; */
    ep0Ring[ctrlRingIdx].control_trb.transfer_len = 8;
    ep0Ring[ctrlRingIdx].control_trb.flags = TRB_TYPE(TRB_SETUP)|
                                             TRB_IDT|TRB_CYCLE;
    
    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*Data Stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferlo= (uint32_t)(xhciData->uDataReceived);
    ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;  /*only 32 bit address used */
    ep0Ring[ctrlRingIdx].normal_trb.transfer_len = xhciData->ep0MaxPs; /*uEP0Size; */
    ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_DATA)|
                                            TRB_DIR_IN|TRB_CYCLE;/*|TRB_ISP; */

    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*status Stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferlo= 0; /*no data for status stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;
    ep0Ring[ctrlRingIdx].normal_trb.transfer_len = 0;
    ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_T_STATUS)|TRB_CYCLE|TRB_IOC;

    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    HW_WR_REG32(baseAddr + DWC_USB_DB(2), DB_VALUE(0,0));
        
    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_TRANSFER;
    xhci_wait_for_event(baseAddr);

    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_TRANSFER)
    {
        compCode = Command_Completion_Handler(instanceNumber);

        /*if (COMP_SUCCESS != compCode)  */
        if ((COMP_SUCCESS != compCode) && (COMP_SHORT_PACKET != compCode))
        {
            return (ERR_USB_HOST_GET_CONF_DESC | compCode);
        }
    }
    else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    {
        debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                    __LINE__, xhciData->PtrEvent); 

        rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

        if (rc != NO_ERROR) 
        {
            return rc;
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    pConfigDesc = (tConfigDescriptor_t*) &xhciData->uDataReceived[0];

    /* safely getting the wTotalLength incase of unaligned read */
    wTotalLength = ((uint8_t*)pConfigDesc)[3]<<8 | ((uint8_t*)pConfigDesc)[2];

#if 1
    if(wTotalLength > xhciData->ep0MaxPs)
    {
        /*IF the EP0 size is lesser than the Config descriptor length read the complete */
        /*Config descriptor again */

        /*Setup Stge */
        ep0Ring[ctrlRingIdx].control_trb.bmRequestType = USB_RTYPE_DIR_IN|
                                                                   USB_RTYPE_STANDARD|
                                                                   USB_RTYPE_DEVICE;
        ep0Ring[ctrlRingIdx].control_trb.bRequest = 6U;
        ep0Ring[ctrlRingIdx].control_trb.wValue = 0x200;
        ep0Ring[ctrlRingIdx].control_trb.wIndex = 0;
        ep0Ring[ctrlRingIdx].control_trb.wLength = wTotalLength;
        ep0Ring[ctrlRingIdx].control_trb.transfer_len = 8;
        ep0Ring[ctrlRingIdx].control_trb.flags = TRB_TYPE(TRB_SETUP)|TRB_IDT|TRB_CYCLE;

        xhciData->byCtrlTransferRingIndex++;
        ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

        /*Data Stage */
        ep0Ring[ctrlRingIdx].normal_trb.bufferlo= (uint32_t)xhciData->uDataReceived;
        ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0; /*only 32 bit address used */
        ep0Ring[ctrlRingIdx].normal_trb.transfer_len = wTotalLength;
        ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_DATA)|
                                                          TRB_DIR_IN|TRB_CYCLE;
        xhciData->byCtrlTransferRingIndex++;
        ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

        /*Status Stage */
        ep0Ring[ctrlRingIdx].normal_trb.bufferlo= 0; /*Data Buffer Pointer Zero for this stage */
        ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;
        ep0Ring[ctrlRingIdx].normal_trb.transfer_len = 0;
        ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_T_STATUS)|TRB_CYCLE|TRB_IOC;

        xhciData->byCtrlTransferRingIndex++;
        ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

        HW_WR_REG32(baseAddr + DWC_USB_DB(2), DB_VALUE(0,0));
        
        /*Wait for Pending interrupt */
        xhciData->expectingTrbType = TRB_TRANSFER;
        xhci_wait_for_event(baseAddr);

        if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_TRANSFER)
        {
            compCode = Command_Completion_Handler(instanceNumber);

            if ((COMP_SUCCESS != compCode) && (COMP_SHORT_PACKET != compCode))
            {
                return (ERR_USB_HOST_GET_CONF_DESC | compCode);
            }
        }
        else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
        {
            debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                        __LINE__, xhciData->PtrEvent); 

            rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

            if (rc != NO_ERROR) 
            {
                return rc;
            }
        }
        else 
        {
            return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
        }
    }

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

#endif

    /* copy the descriptor data to usblib */
    saveConfigDescriptor(instanceNumber, xhciData->uDataReceived, wTotalLength);

    /*Parse the configuration descriptor */
    /*Checks if Configuration descriptor type is correct and number of interfaces supported is >0 */
    /*This assumes that the first interface and configuration is always with Mass storage compliance */
    /*Should we support multiple configuration/interface parsing? */
    if ((pConfigDesc->bDescriptorType != USB_DESCRIPTOR_TYPE_CONFIG) || 
        (pConfigDesc->bNumInterfaces == 0))
    {
        return ERROR_USB_HOST_DEVICE_NOTSUPPORTED;
    }

    pInterfaceDesc = (tInterfaceDescriptor_t*) ((unsigned char *)pConfigDesc + pConfigDesc->bLength);
    /*Parse the interface descriptor too which is returned after Configuration descriptor */
    /*Check for Interface descriptor and Mass Storage Class */
    if((pInterfaceDesc->bDescriptorType != USB_DESCRIPTOR_TYPE_INTERFACE) || 
       (pInterfaceDesc->bInterfaceClass != USB_INTERFACE_CLASS_MSC))
    {
        return ERROR_USB_HOST_DEVICE_NOTSUPPORTED;
    }
    /*Check if Interface Subclass is compliant */
    /*We support only SCSI Transparent Command Set */
    if(pInterfaceDesc->bInterfaceSubClass != USB_INTERFACE_SUBCLASS_SCSI)
    {
        return ERROR_USB_HOST_DEVICE_NOTSUPPORTED;
    }
    /*Check if InterfaceProtocol is compliant */
    /*Only Bulk Only Transport(BOT) is supported */
    if(pInterfaceDesc->bInterfaceProtocol != USB_INTERFACE_PROTOCOL_MASS_STORAGE)
    {
        return ERROR_USB_HOST_DEVICE_NOTSUPPORTED;
    }

    /*Number of Endpoints shall atleast be 2 for MSC BOT protocol */
    uNumEndPoints = pInterfaceDesc->bNumEndpoints;
    if(uNumEndPoints < USB_MIN_ENDPOINT_MSC_BOT)
    {
        return ERROR_USB_HOST_DEVICE_NOTSUPPORTED;
    }

    /*Parsing the Endpoint Descriptors received from GET_Configuration */

    ci = pConfigDesc->bLength + pInterfaceDesc->bLength;

    while (ci < wTotalLength)
    {
        pEndPointDesc = (tEndpointDescriptor_t*) &xhciData->uDataReceived[ci];
        ci += pEndPointDesc->bLength;

        if((pEndPointDesc->bmAttributes & USB_EP_ATTR_TYPE_MASK) == USB_EP_ATTR_BULK)
        {
            if(pEndPointDesc->bEndpointAddress & USB_EP_DESC_DIR_IN)
            {
                /*Configure the EndPoint as a BULK IN endpoint */
                /*NAKPollInterval and MaxPacket Size are to be configured as read from Descriptor */
                /*Always operate in High speed mode */

                /*TBD: Check the Speed at the end of reset and set the speed here. */

                /* get the packet size from the EndpointDescriptor_t.wMaxPacketSize. 
                   Beware of unalignment read in ARM. It could cause unalignment exception. 
                   Make sure we use -mno-unaligned-access compilation flag to allow byte access */
                packetSize = pEndPointDesc->wMaxPacketSize;

                /* Endpoint address will contain DIR bit set so masking it off while 
                   calculating endpoint address */
                /* Store the Bulk IN endpoint number for further Reads */
                xhciData->uBulkINEPNum = (pEndPointDesc->bEndpointAddress & 0xF);

                rc = USBHostConfigureEndpoint(instanceNumber,
                                              xhciData->uBulkINEPNum,
                                              packetSize,
                                              0x0,
                                              (uint32_t)xhciData->BulkIN_Transfer_Ring,
                                              BULK_IN_EP);

                if (rc != NO_ERROR) 
                {
                    return rc;
                }

                xhciData->uBulkINDB = ((xhciData->uBulkINEPNum *2) + USB_HOST_IN)-1;
            }
            else
            {
                /*Configure as BULK OUT endpoint */
                /*Configure the EndPoint as a BULK IN endpoint */
                /*NAKPollInterval and MaxPacket Size are to be configured as read from Descriptor */
                /*Always operate in High speed mode */
                /*//TBD: Check the Speed at the end of reset and set the speed here. */
                xhciData->uBulkOUTEPNum = pEndPointDesc->bEndpointAddress;

                /* get the EndpointDescriptor_t.wMaxPacketSize. Beware: unalignment read
                   in ARM could cause unalignment exception */
                /* packetSize = (((uint8_t*)pEndPointDesc)[4]<<8)|((uint8_t*)pEndPointDesc)[5]; */
                packetSize = pEndPointDesc->wMaxPacketSize;
                                
                rc = USBHostConfigureEndpoint(instanceNumber,
                                              xhciData->uBulkOUTEPNum,
                                              packetSize,
                                              0,
                                              (uint32_t)xhciData->BulkOUT_Transfer_Ring,
                                              BULK_OUT_EP);
                
                if (rc != NO_ERROR) 
                {
                    return rc;
                }

                /* door bell target for transferring associated with this endpoint. */
                xhciData->uBulkOUTDB = ((xhciData->uBulkOUTEPNum *2) + USB_HOST_OUT)-1;

            }/*End else */
        }/*End of if Bulk Check */
    
    }/*End For */


    xhciData->xhciPortState[xhciData->xhciPortNum-1] = USB_HOST_ENUMERATED;

    return NO_ERROR;

} /* USBHostGetConfigurationDescriptor */


uint32_t USBHostSetConfiguration(uint32_t instanceNumber)
{
    uint32_t compCode = 0;
    uint32_t baseAddr = 0;
    uint32_t rc = 0;
    uint32_t     ctrlRingIdx = 0;
    XHCI_DATA_S* xhciData = 0;
    union xhci_transfer_event* ep0Ring;   

 
    xhciData    = &g_usb_global.drv_instances[instanceNumber].xhciData;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));
    baseAddr    = XhciRegBaseAddr(instanceNumber); 
    ep0Ring     = xhciData->EP0_Transfer_Ring;

    /*Setup Stge */
    ep0Ring[ctrlRingIdx].control_trb.bmRequestType = 
                                        USB_RTYPE_DIR_OUT|
                                        USB_RTYPE_STANDARD|
                                        USB_RTYPE_DEVICE;

    ep0Ring[ctrlRingIdx].control_trb.bRequest = 
                                        USB_BREQUEST_SET_CONFIGURATION;

    ep0Ring[ctrlRingIdx].control_trb.wValue = 
                                        USB_HOST_DEVICE_CONFIGURATION;

    ep0Ring[ctrlRingIdx].control_trb.wIndex = 0;
    ep0Ring[ctrlRingIdx].control_trb.wLength = 0;
    ep0Ring[ctrlRingIdx].control_trb.transfer_len = 8;
    ep0Ring[ctrlRingIdx].control_trb.flags = 
                                        TRB_TYPE(TRB_SETUP)|TRB_IDT|TRB_CYCLE;
    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*status Stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferlo= 0; 
    /*Data Buffer Pointer Zero for uint32_t stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;
    ep0Ring[ctrlRingIdx].normal_trb.transfer_len = 0;
    ep0Ring[ctrlRingIdx].normal_trb.flags = 
                                    TRB_TYPE(TRB_T_STATUS)|TRB_CYCLE|TRB_IOC;

    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    HW_WR_REG32(baseAddr + DWC_USB_DB(2), DB_VALUE(0,0));

    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_TRANSFER;
    xhci_wait_for_event(baseAddr);

    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_TRANSFER)
    {
        compCode = Command_Completion_Handler(instanceNumber);

        if ((COMP_SUCCESS != compCode) && (COMP_SHORT_PACKET != compCode))
        /*if (COMP_SUCCESS != compCode)  */
        {
            return (ERR_USB_HOST_SET_CONF_DESC | compCode);
        }
    }
    else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    {
        debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                    __LINE__, xhciData->PtrEvent); 

        rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

        if (rc != NO_ERROR) 
        {
            return rc;
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }


    xhciData->xhciPortState[xhciData->xhciPortNum-1] = USB_HOST_CONFIGURED;
    
    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    return NO_ERROR;

} /* USBHostSetConfiguration */


/*--------------------------------------------------------------------
 * This function implements a Write on the Specified BULKOUTEndpoint 
 *-------------------------------------------------------------------*/ 
uint32_t USBHostWrite(uint32_t instanceNumber, 
                      uint8_t uEndPoint, 
                      uint8_t *puData, 
                      uint32_t uSize)
{

    /*Form the TD for the transfer Ring */
    uint32_t doorbell_target = 0x0; 
    uint32_t compCode = 0;
    uint32_t baseAddr = 0;
    uint32_t rc = 0;
    uint32_t bulkRingIdx = 0;
    XHCI_DATA_S* xhciData = 0;
    union xhci_transfer_event* bulkOutRing; 

    xhciData    = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr    = XhciRegBaseAddr(instanceNumber); 
    bulkRingIdx = (xhciData->byEpOUTRingIndex % (BULKOUT_TRANSFER_RING_SIZE-1));
    bulkOutRing = xhciData->BulkOUT_Transfer_Ring;

    /*
    debug_printf("%s.xhciData->byEpOUTRingIndex=%d\n", 
                    __FUNCTION__, xhciData->byEpOUTRingIndex);
    */

    usb_osalCacheWb(puData, uSize);

    bulkOutRing[bulkRingIdx].normal_trb.bufferlo = (uint32_t) puData;
    bulkOutRing[bulkRingIdx].normal_trb.bufferhi = 0;    /*Only 32bit used */
    bulkOutRing[bulkRingIdx].normal_trb.transfer_len = uSize; 
    bulkOutRing[bulkRingIdx].normal_trb.flags = TRB_TYPE(TRB_T_NORMAL)|
                                                TRB_IOC|
                                                xhciData->bulkOUTRingCycleState;
    xhciData->byEpOUTRingIndex++;

    if(xhciData->byEpOUTRingIndex == BULKOUT_TRANSFER_RING_SIZE-1)
    {
        bulkOutRing[BULKOUT_TRANSFER_RING_SIZE-1].normal_trb.bufferlo=
                                                    (uint32_t)&bulkOutRing[0]; /*Link it to first TRB */
        bulkOutRing[BULKOUT_TRANSFER_RING_SIZE-1].normal_trb.bufferhi=0;
        bulkOutRing[BULKOUT_TRANSFER_RING_SIZE-1].normal_trb.transfer_len = 0;
        bulkOutRing[BULKOUT_TRANSFER_RING_SIZE-1].normal_trb.flags = TRB_TYPE(TRB_LINK)|
                                                                     xhciData->bulkOUTRingCycleState|
                                                                     LINK_TOGGLE;

        /*Toggle the state */
        xhciData->bulkOUTRingCycleState = (xhciData->bulkOUTRingCycleState ? 0:1);
        xhciData->byEpOUTRingIndex =0;
    }

    doorbell_target = DB_VALUE(xhciData->uBulkOUTDB,0);
    HW_WR_REG32(baseAddr + DWC_USB_DB(2), doorbell_target);
    xhciData->countofOUTs++;

    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_TRANSFER;
    xhci_wait_for_event(baseAddr);

    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_TRANSFER)
    {
        compCode = Command_Completion_Handler(instanceNumber);

        /*if (COMP_SUCCESS != compCode)  */
        if ((COMP_SUCCESS != compCode) && (COMP_SHORT_PACKET != compCode))
        {
            debug_printf("%s returns %d\n", __FUNCTION__, compCode);
            return (ERR_USB_HOST_WRITE | compCode);
        }
    }
    else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    {
        debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                    __LINE__, xhciData->PtrEvent); 

        rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

        if (rc != NO_ERROR) 
        {
            return rc;
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    return NO_ERROR;
} /* USBHostWrite */
                    


/*--------------------------------------------------------------------
 * Bulk In handling 
 *-------------------------------------------------------------------*/ 
uint32_t USBHostRead(uint32_t instanceNumber, 
                     uint8_t uEndPoint, 
                     uint8_t *puData, 
                     uint32_t uSize)
{
    uint32_t doorbell_target = 0;
    uint32_t compCode = 0;
    uint32_t baseAddr = 0;
    uint32_t rc = 0;

    uint32_t bulkRingIdx = 0;
    XHCI_DATA_S* xhciData = 0;
    union xhci_transfer_event* bulkInRing = 0; 

    xhciData    = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr    = XhciRegBaseAddr(instanceNumber);
    bulkRingIdx = (xhciData->byEpINRingIndex % (BULKIN_TRANSFER_RING_SIZE-1));
    bulkInRing  = xhciData->BulkIN_Transfer_Ring;

    //usb_osalCacheInvalidate(puData, uSize);
    usb_osalCacheWbInv(puData, uSize);

    /*
    debug_printf("%s. xhciData->byEpINRingIndex=%d. TRB addr=0x%x\n",
                        __FUNCTION__, xhciData->byEpINRingIndex,
                        (uint32_t)&bulkInRing[bulkRingIdx].normal_trb);
    */

    /*Form the TD for the transfer Ring */
    bulkInRing[bulkRingIdx].normal_trb.bufferlo = (uint32_t) puData;
    bulkInRing[bulkRingIdx].normal_trb.bufferhi = 0; /* 32 bit only */
    bulkInRing[bulkRingIdx].normal_trb.transfer_len = uSize; /*Only 32bit address used */
    bulkInRing[bulkRingIdx].normal_trb.flags = TRB_TYPE(TRB_T_NORMAL)|
                                               TRB_IOC|TRB_ISP|
											   xhciData->bulkINRingCycleState;
    xhciData->byEpINRingIndex++;

    if(xhciData->byEpINRingIndex == BULKIN_TRANSFER_RING_SIZE-1)
    {
        /*Link it to first TRB */
        bulkInRing[BULKIN_TRANSFER_RING_SIZE-1].normal_trb.bufferlo=(uint32_t)&bulkInRing[0]; 
        
        bulkInRing[BULKIN_TRANSFER_RING_SIZE-1].normal_trb.bufferhi = 0;
        bulkInRing[BULKIN_TRANSFER_RING_SIZE-1].normal_trb.transfer_len = 0;
        bulkInRing[BULKIN_TRANSFER_RING_SIZE-1].normal_trb.flags = TRB_TYPE(TRB_LINK)|
                                                                   xhciData->bulkINRingCycleState|
                                                                   LINK_TOGGLE;

        /*Toggle the state */
        xhciData->bulkINRingCycleState = (xhciData->bulkINRingCycleState ? 0:1);
        xhciData->byEpINRingIndex =0;
    }

    doorbell_target = DB_VALUE(xhciData->uBulkINDB, 0);
    HW_WR_REG32(baseAddr + DWC_USB_DB(2), doorbell_target); 

    xhciData->countofINs++;

    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_TRANSFER;
    xhci_wait_for_event(baseAddr);

    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_TRANSFER)
    {
        compCode = Command_Completion_Handler(instanceNumber);

        /*if (COMP_SUCCESS != compCode)  */
        if ((COMP_SUCCESS != compCode) && (COMP_SHORT_PACKET != compCode))
        {
            return (ERR_USB_HOST_READ | compCode);
        }
    }
    else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    {
        debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                    __LINE__, xhciData->PtrEvent); 

        rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

        if (rc != NO_ERROR) 
        {
            return rc;
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;
    
    return NO_ERROR;
} /* USBHostRead */


uint32_t USB_HOST_xHCI_Address_Device(uint32_t instanceNumber, uint32_t Speed)
{
    uint32_t                compCode = 0;
    uint32_t                baseAddr = 0;
    uint32_t                rc = 0;
    XHCI_DATA_S*            xhciData = 0;
    xhci_context_wrapper_t* xhciContext = 0;

    xhciData    = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr    = XhciRegBaseAddr(instanceNumber); 
    xhciContext = &xhciData->xhci_context;
   
    /*4.3.3 Device Slot Initialization */
    memset(xhciContext, 0, sizeof(xhci_context_wrapper_t));

    xhciContext->Input_Control_Context.add_flags |= 0x3; /* A0 and A1 set */

    /*Set Context Entries to 1 */
    xhciContext->Slot_Context.device_info0 |= (LAST_CTX(1)| 
                                              (0 << 26)   | /* not a hub */
                                              ((Speed & 0xF) << 20)); /* Init speed and Port */

    xhciContext->Slot_Context.device_info1 |= ROOT_HUB_PORT(xhciData->xhciPortNum) | 
                                              NUM_HUB_PORTS(0); /* no hub support yet...  */
                                                                /* number of ports on hub goes here */

    xhciContext->Slot_Context.ttinfo = 0;   /* no hub support ... yet. */
    xhciContext->Slot_Context.SlotState_Devadd = 0;

    xhciContext->EndPoint_Context[0].epinfo1 |= (EP_TYPE(CTRL_EP)|
                                                MAX_PACKET(xhciData->ep0MaxPs)|
                                                MAX_BURST(0)|
                                                ERROR_COUNT(3)); /* Error count 3 sec 4.8.2.1 in xHCI Spec */

    xhciContext->EndPoint_Context[0].TRDeqPtrLo |= EP_CTX_CYCLE_MASK; /*DCS Set to 1 */
    xhciContext->EndPoint_Context[0].TRDeqPtrLo |= (uint32_t) &xhciData->EP0_Transfer_Ring[0];

    /*Form the Address device command Sec 6.4.3.4 in xHCI spec */
    xhciData->Command_Ring[xhciData->byCommandRingIndex].command_trb_ptr_lo = 
                        (uint32_t)&xhciContext->Input_Control_Context;

    xhciData->Command_Ring[xhciData->byCommandRingIndex++].trb_slotid       = 
                        (TRB_TYPE(TRB_ADDRESS_DEVICE)|0x01 | SLOT_ID_FOR_TRB(xhciData->Slot_ID));

    /* Command Ring */
    HW_WR_REG32(baseAddr + DWC_USB_DB(1), DB_VALUE_HOST);
    
    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_COMMAND_COMPLETION;
    xhci_wait_for_event(baseAddr);

    /*Check if Command Completion event has come for the Set address command */
    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_COMMAND_COMPLETION)
    {
        compCode = Command_Completion_Handler(instanceNumber);

        if (COMP_SUCCESS != compCode) 
        {
            return (ERR_USB_HOST_SET_ADDRESS_FAILED | compCode);
        }
    }
    else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    {
        debug_printf("%d. unexpected PSC ptrEvent=0x%x\n", 
                    __LINE__, xhciData->PtrEvent); 

        rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

        if (rc != NO_ERROR) 
        {
            return rc;
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    return NO_ERROR;
} /* USB_HOST_xHCI_Address_Device */
    

/* TODO: making this host driver supports multiple slots at once. 
         Right now only one slot is enabled at a time) */
uint32_t xhci_disable_slot(uint32_t instanceNumber)
{
    uint32_t        compCode = 0;
    uint32_t        baseAddr;
    uint32_t        xhciPortNum =  0;
    uint32_t        portSc = 0;
    XHCI_DATA_S*    xhciData = 0;


    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr = XhciRegBaseAddr(instanceNumber); 

    xhciData->PtrEvent =  &xhciData->Command_Completion_Event[xhciData->byEventRingIndex];

    /*Check if Event Received is PSC Event and check uint32_t in PORTSC1 */
    if((TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC))
    {
        
        xhciPortNum = (xhciData->PtrEvent->command_trb_ptr_lo >> 24) & 0xF;            

        if (xhciPortNum == 2) portSc = DWC_USB_PORTSC2; else
        if (xhciPortNum == 1) portSc = DWC_USB_PORTSC1;

        if (!(HW_RD_REG32(baseAddr + portSc) & DWC_USB_PORTSC1_CCS_MASK))
        {
            /* this event was a PSC but not a CSC event. quit */
            return NO_ERROR;
        }

        debug_printf("-> DEV DISCONNECTED!\n"); 

        xhciData->xhciPortState[xhciPortNum-1] = USB_HOST_DEV_DETACHED; 
        
        /*Clear this change event so that further events can be reported         */
        HW_WR_FIELD32(baseAddr + portSc, DWC_USB_PORTSC1_CSC, 0x1);

        compCode = Command_Completion_Handler(instanceNumber);

        if (COMP_SUCCESS != compCode) 
        {
            return (ERR_USB_HOST_DISABLE_SLOT_FAILED | compCode);
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    xhciData->Command_Ring[xhciData->byCommandRingIndex++].trb_slotid = 
                (xhciData->Slot_ID <<24)|(TRB_TYPE(TRB_DISABLE_SLOT)|TRB_CYCLE);
        
    HW_WR_REG32(baseAddr + DWC_USB_DB(1), DB_VALUE_HOST);

    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_COMMAND_COMPLETION;
    xhci_wait_for_event(baseAddr);

    /*Completion Event will be Command Completion event code */
    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_COMMAND_COMPLETION)
    {
    	xhciData->Slot_ID = (uint8_t) TRB_TO_SLOT_ID(xhciData->PtrEvent->trb_slotid);
        xhciData->xhciPortState[xhciPortNum-1] = USB_HOST_SLOT_DISABLED;
        compCode = Command_Completion_Handler(instanceNumber);

        if (COMP_SUCCESS != compCode) 
        {
            return (ERR_USB_HOST_DISABLE_SLOT_FAILED | compCode);
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    debug_printf("-> SLOT_DISABLED! Slot_ID=%d\n", xhciData->Slot_ID);

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    return NO_ERROR;
} /* xhci_disable_slot */


/* Reset Device as mentioned in 4.6.11? */
uint32_t xhci_reset_device(uint32_t instanceNumber)
{
    uint32_t        compCode = 0;
    uint32_t        baseAddr;
    XHCI_DATA_S*    xhciData = 0;


    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr = XhciRegBaseAddr(instanceNumber); 

    memset(&xhciData->Command_Ring[xhciData->byCommandRingIndex], 0, 
           sizeof(struct xhci_event_cmd));

    xhciData->Command_Ring[xhciData->byCommandRingIndex++].trb_slotid = 
            (xhciData->Slot_ID <<24)|(TRB_TYPE(TRB_RESET_DEVICE)|TRB_CYCLE);
        
    HW_WR_REG32(baseAddr + DWC_USB_DB(1), DB_VALUE_HOST);

    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_COMMAND_COMPLETION;
    xhci_wait_for_event(baseAddr);

    /*Completion Event will be Command Completion event code */
    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_COMMAND_COMPLETION)
    {
    	xhciData->Slot_ID = (uint8_t) TRB_TO_SLOT_ID(xhciData->PtrEvent->trb_slotid);
        compCode = Command_Completion_Handler(instanceNumber);

        if (COMP_SUCCESS != compCode) 
        {
            return (ERR_USB_HOST_DEVICE_RESET_FAILED | compCode);
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    debug_printf("device reset! Slot_ID=%d\n", xhciData->Slot_ID);

    /* finish waiting for response from XHCI */    
    xhciData->expectingTrbType = 0;

    return NO_ERROR;
} /* xhci_reset_device */


static uint32_t xhci_handle_psc_event(uint32_t instanceNumber, 
                                      struct xhci_event_cmd* ptrEvent)
{
    uint32_t        portNum=0;
    uint32_t        maxPort = 0;
    uint32_t        portScVal = 0;
    uint32_t        compCode = 0;
    uint32_t        regVal;
    uint32_t        baseAddr = 0;
    uint32_t        portStatusReg = 0;
    XHCI_DATA_S*    xhciData = 0;

    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;

    if (!((instanceNumber == 0) || (instanceNumber == 1)))
    {
        return ERR_USB_HOST_BAD_DATA; 
    }

    baseAddr = XhciRegBaseAddr(instanceNumber); 

    /*Check if Event Received is PSC Event and check for port connection  */
    if(TRB_FIELD_TO_TYPE(ptrEvent->trb_slotid) == TRB_PSC)
    {
        portNum = (ptrEvent->command_trb_ptr_lo >> 24) & 0xF;            

        /* make sure the port number is valid - maxPort has been checked at 
           init time in USB_Host_Init */
        maxPort = (HW_RD_REG32(baseAddr + DWC_USB_HCSPARAMS1) >> 24) & 0xF;

        if ((portNum > maxPort) || (portNum == 0))
        {
            return ERR_USB_HOST_BAD_DATA;
        }

        debug_printf("-> PSC on port %d\n", portNum); 
        if (portNum == 1) 
        {
            portStatusReg = DWC_USB_PORTSC1;
            portScVal = HW_RD_REG32(baseAddr + portStatusReg); 
        }
        else if (portNum == 2)
        {   
            portStatusReg = DWC_USB_PORTSC2;
            portScVal = HW_RD_REG32(baseAddr + portStatusReg);
        }

        /* record PSC events */
        /* xhci port number goes from 1. Our xhciPortState indexed from 0. So -1 */
        if (portScVal & DWC_USB_PORTSC1_CCS_MASK) 
        {
            /* though we've already checked the portNum range, but MISRAC - KW still 
               complains about this error. Do extra checking here */
            if ((portNum>0) && (portNum<3))
            {
                xhciData->xhciPortState[(portNum-1)] = USB_HOST_DEV_CONNECTED;
            }
        }
        /* need to validate previous state before changing state to PORT_RESET. */
        /*else if (portScVal & DWC_USB_PORTSC1_PRC_MASK)  */
        /*{ */
        /*    if ((portNum>0) && (portNum<3)) */
        /*       xhciData->xhciPortState[portNum-1] = USB_HOST_PORT_RESET; */
        /*}  */
        else if ((portScVal & DWC_USB_PORTSC1_CCS_MASK) == 0) 
        {
            if ((portNum>0) && (portNum<3))
            {
                xhciData->xhciPortState[(portNum-1)] = USB_HOST_DEV_DETACHED; 
            }
        } 
            
        /*Clear this change event so that further events can be reported         */
        regVal = HW_RD_REG32(baseAddr + portStatusReg); 
        
        HW_SET_FIELD(regVal, DWC_USB_PORTSC1_CSC, 0x1); 
        HW_SET_FIELD(regVal, DWC_USB_PORTSC1_PED, 0x0); 
        HW_WR_REG32(baseAddr + portStatusReg, regVal);

        compCode = Command_Completion_Handler(instanceNumber);

        if (COMP_SUCCESS != compCode) 
        {
            return (ERR_USB_HOST_DEVICE_CONNECT_FAILED | compCode);
        }

        /* finish handling the psc event. Now look to see if extra event pending
           this happens psc event happens while the driver waits for an event other 
           than PSC event. Continue waiting and then consume it */
        if ((xhciData->expectingTrbType != TRB_PSC) &&
            (xhciData->expectingTrbType != 0))
        {
            debug_printf("Getting PSC while waiting for a different response. Continue waiting for it\n");

            xhci_wait_for_event(baseAddr);

            if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) != xhciData->expectingTrbType)
            {
                debug_printf("Getting unexpected event again. Give up\n");
                return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
            }

            compCode = Command_Completion_Handler(instanceNumber);

            if ((COMP_SUCCESS != compCode))
            {
                debug_printf("got error code: %d\n", compCode);
                return (ERR_USB_HOST_PSC_HANDLING_FAILED | compCode);
            }
        }
    }
    return NO_ERROR;
} /* xhci_handling_psc_event */



uint32_t xhci_enum(uint32_t instanceNumber)
{
    uint32_t        rc = NO_ERROR;
    uint32_t        regVal = 0;
    uint32_t        compCode = 0;
    uint32_t        baseAddr;
    uint32_t        portNum;
    uint32_t        portStatusReg;
    uint32_t        enumIsDone = 0;

    struct          xhci_event_cmd*  ptrEvent;
    XHCI_DATA_S*    xhciData = 0;

    xhciData = &g_usb_global.drv_instances[instanceNumber].xhciData;

    baseAddr = XhciRegBaseAddr(instanceNumber); 

    portNum = 0;
    xhciData->expectingTrbType = 0;


    while(!enumIsDone)
    {
        if (portNum == 0) 
        {
            portStatusReg = DWC_USB_PORTSC1;
        }
        else if (portNum == 1)
        {   
            portStatusReg = DWC_USB_PORTSC2;
        }

        switch (xhciData->xhciPortState[portNum])
        {

            case USB_HOST_UNKNOWN:
            {
                /*Wait for Pending interrupt */
                /*xhci_wait_for_event(baseAddr); */
                if (!xhci_pending_event(baseAddr)) 
                {
                    break;
                }

                xhciData->PtrEvent =  
                        &xhciData->Command_Completion_Event[xhciData->byEventRingIndex];

                ptrEvent = xhciData->PtrEvent;

                debug_printf("got intr. portNum = %d. ptrEvent=0x%x\n", portNum, ptrEvent);

                /*Check if Event Received is PSC Event and check for port connection  */
                if(TRB_FIELD_TO_TYPE(ptrEvent->trb_slotid) == TRB_PSC)
                {
                    xhciData->expectingTrbType = TRB_PSC;

                    /* handling psc. command_completioned_handler is called */
                    /* inside and will advance the ptrEvent ptr on its own. */
                    rc = xhci_handle_psc_event(instanceNumber, ptrEvent);
                    if (rc != NO_ERROR) 
                        return rc;
                }

                break;
            }

            case USB_HOST_DEV_CONNECTED:
            {
                /* USB3.0 port is mapped to PORTSC2 (as mentioned in 4.24.2.2 */
                if (portNum == 1) /* which means root hub port #2 (xhciPortNum = 2) */
                {
                    debug_printf("Using USB3.0 initialization sequence\n");

                    /* for USB3.0, advance the state machine without reset the port. */
                    xhciData->xhciPortState[portNum] = USB_HOST_PORT_RESET;
                } 
                else 
                {
                    debug_printf("xhciPortNum!=2. Using USB2.0 initialization sequence\n");
                    debug_printf("about to do port reset! PORTSC%d=0x%x\n", 
                                 portNum+1,
                                 HW_RD_REG32(baseAddr + portStatusReg)); 

                    /*Port Reset */
                    usb_osalDelayMs(125);	/* delay 125ms before resetting the device */

                    HW_WR_FIELD32(baseAddr + portStatusReg, DWC_USB_PORTSC1_PR, 0x01);
                   
                    /*Wait for Pending interrupt */
                    xhciData->expectingTrbType = TRB_PSC;
                    xhci_wait_for_event(baseAddr);

                    usb_osalDelayMs(125);	/* delay 125ms after reset. // needed for Galileo */

                    /*Check if Port uint32_t Change event has come and  */
                    /*Port Reset has happened */
                    if((TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC) && 
                       (HW_RD_REG32( baseAddr + portStatusReg) & DWC_USB_PORTSC1_PRC_MASK))
                    {
                        /* Port Reset Change has happened. Clear it now.  */
                        /* note that we should NOT also write 1 to PED bit  */
                        regVal = HW_RD_REG32(baseAddr + portStatusReg);
                        HW_SET_FIELD(regVal, DWC_USB_PORTSC1_PRC, 0x1); 
                        HW_SET_FIELD(regVal, DWC_USB_PORTSC1_PED, 0x0); /* writing 1 to PED will disable port.  */
                        HW_WR_REG32(baseAddr + portStatusReg, regVal);
                        
                        compCode = Command_Completion_Handler(instanceNumber);

                        if (COMP_SUCCESS != compCode) 
                        {
                            return (ERR_USB_HOST_DEVICE_RESET_FAILED | compCode);
                        }

                        xhciData->xhciPortState[portNum] = USB_HOST_PORT_RESET;
                    }
                    else 
                    {
                        debug_printf("failed to do PORT RESET. ptrEvent=0x%x. TRB type=%d.\n", 
                                      xhciData->PtrEvent, 
                                      TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid)); 
  
                        debug_printf("failed to reset! PORTSC%d=0x%x\n", 
                                      portNum+1,
                                      HW_RD_REG32(baseAddr + portStatusReg)); 

                        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
                    }
                } /* if (portNum==1) */

                break;
            }

            case USB_HOST_PORT_RESET:
            {
                usb_osalDelayMs(15);	/* delay 15ms after resetting the device */

                /*Get the Slot Context using Enable Slot command 4.3.2 in xHCI Spec */
                /*Slot_Type[bit 16-20] = 0; // according to 7.2.2.1.4 */
                xhciData->Command_Ring[xhciData->byCommandRingIndex++].trb_slotid = 
                                                (TRB_TYPE(TRB_ENABLE_SLOT)|TRB_CYCLE);

                regVal = HW_RD_REG32(baseAddr + portStatusReg);

                if (HW_GET_FIELD(regVal, DWC_USB_PORTSC1_PED) != 1)
                {
                    debug_printf("Port did not change to enabled. PORTSC%d=0x%x\n", 
                                 portNum+1, regVal); 
                }

                debug_printf("about to do enable slot. PORTSC%d=0x%x\n", 
                            portNum+1, regVal);

                HW_WR_REG32(baseAddr + DWC_USB_DB(1), DB_VALUE_HOST);

                /*Wait for Pending interrupt */
                xhciData->expectingTrbType = TRB_COMMAND_COMPLETION;
                xhci_wait_for_event(baseAddr);

                /*Completion Event will be Command Completion event code */
                if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_COMMAND_COMPLETION)
                {
                    xhciData->Slot_ID = (uint8_t) TRB_TO_SLOT_ID(xhciData->PtrEvent->trb_slotid);

                    compCode = Command_Completion_Handler(instanceNumber);

                    if ((COMP_SUCCESS != compCode) || (xhciData->Slot_ID == 0))
                    {
                        return (ERR_USB_HOST_DEVICE_GET_SLOT_FAILED | compCode);
                    }
                }
                else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
                {
                    debug_printf("PSC rx while waiting EnableSlot rsp. ptrEvent=0x%x\n", 
                                 xhciData->PtrEvent); 

                    rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

                    /* received PSC out of expected sequence. 
                       Return to proceed again later based on new PSC events */
                    if (rc != NO_ERROR) 
                    {
                        return rc;
                    }
                    else
                    {
                        continue;
                    }
                }
                else  
                {
                    debug_printf("failed to do Enable Slot. ptrEvent=0x%x\n", 
                                 xhciData->PtrEvent); 

                    return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
                }

                xhciData->xhciPortState[portNum] = USB_HOST_SLOT_ENABLED;

                /* since this port gets this far, we update the xhciPortNum  */
                /* with this portNumber */
                /* xhciPortNum goes from 1. portNum goes from 0. */
                xhciData->xhciPortNum = portNum + 1; 

                xhciData->xhciPortSpeed = HW_RD_FIELD32(baseAddr + portStatusReg, 
                                                        DWC_USB_PORTSC1_PORTSPEED); 
                
                switch (xhciData->xhciPortSpeed)
                {
                    case XHCI_PORT_SPEED_FS:
                    case XHCI_PORT_SPEED_HS:
                        xhciData->ep0MaxPs = 64;

                        break;
                    case XHCI_PORT_SPEED_LS:
                        xhciData->ep0MaxPs = 8; 
                        break;
                    case XHCI_PORT_SPEED_SS:
                        xhciData->ep0MaxPs = 512; 
                        break;
                    default:
                        /* error, we shouldn't get here */
                        debug_printf("unknown port speed %d\n", 
                                      xhciData->xhciPortSpeed); 

                        return ERR_USB_HOST_BAD_DATA;
                }

                break;
            }

            case USB_HOST_SLOT_ENABLED:
            {
                debug_printf("about to set Address\n"); 
                rc = USB_HOST_xHCI_Address_Device(instanceNumber, xhciData->xhciPortSpeed) ;    
                if (rc != NO_ERROR) return rc;

                debug_printf("about to get device descriptor\n"); 
                rc = USBHostGetDeviceDescriptor(instanceNumber, USB_HOST_DEVICE_ADDRESS);
                if (rc != NO_ERROR) return rc;

                debug_printf("about to get Configuration descriptor\n"); 
                rc = USBHostGetConfigurationDescriptor(instanceNumber);
                if (rc != NO_ERROR) return rc;

                debug_printf("about to set Configuration\n"); 
                rc = USBHostSetConfiguration(instanceNumber);    
                if (rc != NO_ERROR) return rc;

                /* print out to notify user if we run as USB3.0 
                   we can only get here if the PORT & slot are enabled. So if portNum==1 it means 
                   we are running as USB3.0
                 */
                if (portNum==1)
                {
                    debug_printf("Successfully enumerated with USB3.0\n");
                }

                enumIsDone = 1;

                /*TBD Retry logic */

                break;
            }

            case USB_HOST_DEV_DETACHED:
                /* fall through */
            default:
                break;

        } /* end switch */

        portNum++;
        if (portNum > 1) portNum = 0;

    } /* end while */
    return NO_ERROR;
}

#if 0
uint32_t USBHostClearFeature(uint8_t uEndPoint,uint16_t uFeature)
{
    /*Setup Stge */
        ep0Ring[ctrlRingIdx].control_trb.bmRequestType = USB_RTYPE_DIR_OUT|USB_RTYPE_STANDARD|USB_RTYPE_ENDPOINT;
        ep0Ring[ctrlRingIdx].control_trb.bRequest = USB_BREQUEST_CLEAR_FEATURE;
        ep0Ring[ctrlRingIdx].control_trb.wValue = uFeature;
        ep0Ring[ctrlRingIdx].control_trb.wIndex = uEndPoint;
        if(uEndPoint == uBulkINEPNum)
        {
            ep0Ring[ctrlRingIdx].control_trb.wIndex |= 0x80;
        }
        ep0Ring[ctrlRingIdx].control_trb.wLength = 0;
        ep0Ring[ctrlRingIdx].control_trb.transfer_len = 8;
        ep0Ring[ctrlRingIdx].control_trb.flags = TRB_TYPE(TRB_SETUP)|TRB_IDT|TRB_CYCLE;
        ctrlRingIdx_INC;
    
        /*status Stage */
        ep0Ring[ctrlRingIdx].normal_trb.bufferlo= 0; /*Data Buffer Pointer Zero for uint32_t stage */
        ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;
        ep0Ring[ctrlRingIdx].normal_trb.transfer_len = 0;
        ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_uint32_t)|TRB_CYCLE|TRB_IOC;
        ctrlRingIdx_INC;
        DWC_USB3_DB_1(XhciRegBaseAddr(instanceNumber))= DB_VALUE(0,0);

}
#endif

void usb_set_wrapper(uint32_t instanceNumber)
{
    usbDwcDcdEnableWrapperIntr(UsbWrapRegBaseAddr(instanceNumber));
}



/* finding which USB event has happened */
uint32_t 
USBIntStatusControl(uint32_t usbBaseAddr)
{

    uint32_t ulStatus = 0;
#if 0
    /* re-enumeration doesn't work on AM437 or AM57xx yet. Not needed this */
    /* code at this time. */
    uint32_t portSC = 0;
    
    uint32_t portScReg;

    if (xhciData->xhciPortNum == 1) portScReg = DWC_USB_PORTSC1; else
        if (xhciData->xhciPortNum == 2) portScReg = DWC_USB_PORTSC2; 

    /*debug_printf("."); */

    /*  looking at what causes the interrupt */
    xhciData->PtrEvent =  &Command_Completion_Event[xhciData->byEventRingIndex];

	if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    { 
        portSC = HW_RD_REG32(usbBaseAddr + portScReg);

        if (portSC & DWC_USB_PORTSC1_CCS_MASK) 
        {
            ulStatus |= USB_DWC_INT_CONNECT;
        } 
        else if (portSC & DWC_USB_PORTSC1_PRC_MASK) 
        {
            ulStatus |= USB_DWC_INT_RESET;
        } 
        else if ((portSC & DWC_USB_PORTSC1_CCS_MASK) == 0) 
        {
            ulStatus |= USB_DWC_INT_DISCONNECT;
        } 
    
    }
#endif
    return ulStatus;
}


uint32_t 
USBHostControlTransfer(uint32_t instanceNumber,  
                       usbSetupPkt_t *pSetupPkt, uint8_t* pData, uint32_t uSize)
{
    uint32_t        compCode = 0;
    uint32_t        baseAddr = 0;
    uint32_t        rc = 0;
    XHCI_DATA_S*    xhciData = 0;
    uint32_t        ctrlRingIdx = 0;
    union xhci_transfer_event* ep0Ring;   


    xhciData    = &g_usb_global.drv_instances[instanceNumber].xhciData;
    baseAddr    = XhciRegBaseAddr(instanceNumber); 
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));
    ep0Ring     = xhciData->EP0_Transfer_Ring;

    /*Setup Stge */
    ep0Ring[ctrlRingIdx].control_trb.bmRequestType = pSetupPkt->bmRequestType;
    ep0Ring[ctrlRingIdx].control_trb.bRequest = pSetupPkt->bRequest;
    ep0Ring[ctrlRingIdx].control_trb.wValue = pSetupPkt->wValue;
    ep0Ring[ctrlRingIdx].control_trb.wIndex = pSetupPkt->wIndex;
    ep0Ring[ctrlRingIdx].control_trb.wLength = pSetupPkt->wLength;
    ep0Ring[ctrlRingIdx].control_trb.transfer_len = 8;
    ep0Ring[ctrlRingIdx].control_trb.flags = TRB_TYPE(TRB_SETUP)|
                                                       TRB_IDT|TRB_CYCLE;
    xhciData->byCtrlTransferRingIndex++;    
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*Data Stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferlo= (uint32_t)pData; 
    ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;  /*only 32 bit address used */
    ep0Ring[ctrlRingIdx].normal_trb.transfer_len = uSize;
    ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_DATA)|
                                                      TRB_DIR_IN|TRB_CYCLE;

    xhciData->byCtrlTransferRingIndex++;
    ctrlRingIdx = (xhciData->byCtrlTransferRingIndex % (EP0_TRANSFER_RING_SIZE -1));

    /*status Stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferlo= 0; /*Data Buffer Pointer Zero for uint32_t stage */
    ep0Ring[ctrlRingIdx].normal_trb.bufferhi=0;
    ep0Ring[ctrlRingIdx].normal_trb.transfer_len = 0;
    ep0Ring[ctrlRingIdx].normal_trb.flags = TRB_TYPE(TRB_T_STATUS)|
                                                      TRB_CYCLE|TRB_IOC;

    xhciData->byCtrlTransferRingIndex++;
    
    HW_WR_REG32(baseAddr + DWC_USB_DB(2), DB_VALUE(0,0));
        
    /*Wait for Pending interrupt */
    xhciData->expectingTrbType = TRB_TRANSFER;
    xhci_wait_for_event(baseAddr);

    if(TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_TRANSFER)
    {
        compCode = Command_Completion_Handler(instanceNumber);

        /*if (COMP_SUCCESS != compCode)  */
        if ((COMP_SUCCESS != compCode) && (COMP_SHORT_PACKET != compCode))
        {
            return (ERR_USB_HOST_CTRL_TRANSFER_FAILED | compCode);
        }
    }

    else if (TRB_FIELD_TO_TYPE(xhciData->PtrEvent->trb_slotid) == TRB_PSC)
    {
        debug_printf("unexpected PSC ptrEvent=0x%x\n", xhciData->PtrEvent); 

        rc = xhci_handle_psc_event(instanceNumber, xhciData->PtrEvent);

        if (rc != NO_ERROR) 
        {
            return rc;
        }
    }
    else 
    {
        return ERR_USB_HOST_UNEXPECTED_TRB_TYPE;
    }

    return NO_ERROR;
} /* USBHostControlTransfer */




/****************************************************************************** */
/* This function sets up the host end points based on the received config */
/* descriptors from the externally connected USB device. */
/*! */
/*! \return none */
/****************************************************************************** */
void USBHCDConfigureEndpoints(uint32_t ulIndex, 
                              tUSBHostDevice *pDevice, 
                              uint32_t* inPipe,
                              uint32_t* outPipe)
{
    /* nothing to do for AM437x at this time. */
    *inPipe = 0;
    *outPipe = 0;
}

