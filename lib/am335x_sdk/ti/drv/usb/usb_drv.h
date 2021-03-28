/*
 * Copyright (c) 2014-2019, Texas Instruments Incorporated
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
/** ============================================================================
 *  @file       usb_drv.h
 *
 *  @brief      USB driver interface
 *
 *  The USB header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/usb/usb_drv.h>
 *  @endcode
 *
 *  # Operation #
 *  The USB driver
 *
 *  The APIs in this driver serve as an interface to a typical TI-RTOS
 *  application. The specific peripheral implementations are responsible to
 *  create all the OS specific primitives to allow for thread-safe
 *  operation.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  USB_Handle      handle;
 *  USB_Params      params;
 *
 *  USB_Params_init(&params);
 *
 *  handle = USB_open(someUSB_configIndexValue, &params);
 *  if (!handle) {
 *      System_printf("USB did not open");
 *  }
 *  @endcode
 *
 *  # Implementation #
 *
 *  This module serves as the main interface for TI-RTOS
 *  applications. Its purpose is to redirect the module's APIs to specific
 *  peripheral implementations which are specified using a pointer to a
 *  USB_FxnTable.
 *
 *  The USB driver interface module is joined (at link time) to a
 *  NULL-terminated array of USB_Config data structures named *USB_config*.
 *  *USB_config* is implemented in the application with each entry being an
 *  instance of a USB peripheral. Each entry in *USB_config* contains a:
 *  - (USB_FxnTable *) to a set of functions that implement a USB peripheral
 *  - (void *) data object that is associated with the USB_FxnTable
 *  - (void *) hardware attributes that are associated to the USB_FxnTable
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_USB__include
#define ti_drivers_USB__include

#ifdef __cplusplus
extern "C" {
#endif


#define USB_ERROR  -1

/******************************************************************************
 * The below macro defines the number USB Instances.
 *
 ******************************************************************************/

/*!
 *  @brief      A handle that is returned from a USB_open() call.
 */
typedef struct  USB_Config          *USB_Handle;


/*!
 *  @brief      USB mode settings
 *
 *  This enum 
 *  configured USB.
 */
typedef enum USB_Mode {
    USB_UNKNOWN_MODE,
    USB_HOST_MSC_MODE,
    USB_DEVICE_MSC_MODE,
    USB_HOST_AC_MODE, /*USB Audio class Host mode*/
    USB_DEVICE_AC_MODE,
    USB_DEVICE_BULK_MODE,
    USB_DEVICE_CDC_MODE
} USB_Mode;

/*!
 *  @brief    Basic USB Parameters
 */
typedef struct USB_Params {
    USB_Mode        usbMode;        /*!< Mode for the controller */
    uint32_t        instanceNo;     /* the controller that this instance run on */
    USB_Handle      usbHandle;
    void*           drvData;        /* pointer to private driver config structure */
    void*           usbClassData;   /* pointer to USB Class (MSC, Video, Audio, HID, etc.) data */

    void*           readSem;        /* read semaphore */
    void*           writeSem;       /* write semaphore */
} USB_Params;




/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USB_init().
 */
typedef void        (*USB_InitFxn)           (USB_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USB_OpenFxn().
 */
typedef USB_Handle  (*USB_OpenFxn)           (USB_Handle handle,
                                             USB_Params *params);


/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USB_IrqConfigFxn().
 */
typedef void        (*USB_IrqConfigFxn)     (USB_Handle handle,
                                             USB_Params* params);

/*!
 *  @brief      A handler for USB interrupts driver specific implementation of
 *              ISR handler.
 */
typedef void        (*USB_IsrHandlerFxn)     (USB_Handle handle, USB_Params* arg);

/*!
 *  @brief      The definition of a USB function table that contains the
 *              required set of functions to control a specific USB driver
 *              implementation.
 */
typedef struct USB_FxnTable {
    /*! Function to open the specified peripheral */
    USB_OpenFxn            openFxn;

    /* interrupt Enabler for IP specified interrupts */
    USB_IrqConfigFxn       irqConfigFxn;

    /* interrupt handler */
    USB_IsrHandlerFxn      irqCoreFxn;
    USB_IsrHandlerFxn      irqMiscFxn;
    
} USB_FxnTable;


/*! @brief USB Global configuration */
typedef struct USB_Config {
    /*! Pointer to a table of a driver-specific implementation of USB functions */
    USB_FxnTable const    *fxnTablePtr;
    uint32_t              isOpened;
    uint32_t              handleCppiDmaInApp; /* if this is TRUE, AM3 CPPI DMA
                                                 handler needs to be registered and
                                                 handled in user application.
                                                 This setting has no effect on AM4,
                                                 AM5, K2s */
    uint32_t              dmaEnabled;         /* DMA is optional in AM3 only */
    uint32_t              usb30Enabled;       /* TRUE if USB3.0 Super Speed is
                                                 enabled. Set to False if USB3.0 SS
                                                 is not required. Set to False if USB3.0 SS
                                                 is not required. Used in SOC that has 
                                                 shared SERDES */

    USB_Params            *usbParams;

    uint32_t              usb2PhyRefClkFreq;  /* frequency (KHz) of the ref clock that's the 
                                                 the USB2.0 PHY is running at */

    uint32_t              vbusDivider;        /* VBUS divider. 1: VBUS goes through a divider
                                               *               0: no divider */
    uint32_t              serdesId;           /* SERDES instance being used with this USB
                                                 instance */

} USB_Config;


/*!
 *  @brief  Function to initialize a given USB peripheral specified by the
 *          particular index value. The parameter specifies which mode the USB
 *          will operate.
 *
 *  @pre    
 *
 *  @param  index         Physical USB instance number
 *
 *  @param  params        Pointer to an parameter block, required.
 *
 *  @return A USB_Handle on success or a NULL on an error or if it has been
 *          already opened
 *
 *  @sa     USB_close
 */
extern USB_Handle USB_open(unsigned int index, USB_Params *params);

/*!
 *  @brief  Function to setup peripheral internal IRQ settings.
 *
 *  @pre    USB controller needs to open previously
 *
 *  @param  handle        handle to the USB instance which has been openned
 *
 *  @param  params        Pointer to an parameter block, required.
 *
 */
extern void USB_irqConfig(USB_Handle handle, USB_Params *params);

/*!
 *  @brief  core IRQ handler from USB driver.
 *
 *  @pre    USB controller needs to open previously
 *
 */
extern void USB_coreIrqHandler(USB_Handle handle, USB_Params *params);

/*!
 *  @brief  misc IRQ handler from USB driver.
 *
 *  @pre    USB controller needs to open previously
 *
 */
extern void USB_miscIrqHandler(USB_Handle handle, USB_Params *params);

/*!
 *  @brief  return USB driver configuration block.
 *
 *  @pre    none
            can be called any time even before the usb_open()
 *
 */
extern void USB_getConfig(uint32_t usbInstanceNo, USB_Config** usbConfig);


#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_USB__include */
