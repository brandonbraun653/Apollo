/**********************************************************************
 * Copyright (C) 2012-2019 Cadence Design Systems, Inc.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************
 * WARNING: This file is auto-generated using api-generator utility.
 *          api-generator: 13.04.5beed88
 *          Do not edit it manually.
 **********************************************************************
 * Cadence Core Driver for USB SSP DRD
 **********************************************************************/

#ifndef USB_SSP_DRD_IF_H
#define USB_SSP_DRD_IF_H

/* parasoft-begin-suppress MISRA2012-RULE-1_1_a_c90-2 "C90 - limits, DRV-3906" */
/* parasoft-begin-suppress MISRA2012-RULE-1_1_b_c90-2 "C90 - limits, DRV-3906" */

#include "cdn_xhci_if.h"
#include "cusb_ch9_if.h"
#include "cusbd_if.h"
#include "cusbdma_if.h"
#include "list_if.h"
#include "cdn_stdtypes.h"
#include "cdn_errno.h"
#include "usb_ssp_drd_regs.h"
#include "cdn_xhci_structs_if.h"
#include "cusbd_structs_if.h"

/** @defgroup ConfigInfo  Configuration and Hardware Operation Information
 *  The following definitions specify the driver operation environment that
 *  is defined by hardware configuration or client code. These defines are
 *  located in the header file of the core driver.
 *  @{
 */

/**********************************************************************
* Defines
**********************************************************************/
/** Timeout value for waiting for DRD Ready. */
#define	USB_SSP_DRD_NRDY_TIMEOUT 20U

/** DID value of compatible hardware. */
#define	USB_SSP_DRD_DID_VALUE 0x0004024EU

/** RID value of compatible hardware. */
#define	USB_SSP_DRD_RID_VALUE 0x200U

/** Macro for disabling/enabling all interrupts. */
#define	USB_SSP_DRD_ALL_INTERRUPTS 0xFFFFFFFFU

/**
 *  @}
 */


/** @defgroup DataStructure Dynamic Data Structures
 *  This section defines the data structures used by the driver to provide
 *  hardware information, modification and dynamic operation of the driver.
 *  These data structures are defined in the header file of the core driver
 *  and utilized by the API.
 *  @{
 */

/**********************************************************************
 * Forward declarations
 **********************************************************************/
typedef struct USB_SSP_DRD_Config_s USB_SSP_DRD_Config;
typedef struct USB_SSP_DRD_Callbacks_s USB_SSP_DRD_Callbacks;
typedef struct USB_SSP_DRD_State_s USB_SSP_DRD_State;
typedef struct USB_SSP_DRD_PrivData_s USB_SSP_DRD_PrivData;
typedef struct USB_SSP_DRD_SysReq_s USB_SSP_DRD_SysReq;


/**********************************************************************
 * Enumerations
 **********************************************************************/
/** Current mode of controller. Regards hardware strap mode and software enabled operation */
typedef enum
{
    /** Controller strapped or works in DRD. */
    USB_SSP_DRD_DRD = 0U,
    /** Controller strapped or works as HOST. */
    USB_SSP_DRD_HOST = 1U,
    /** Controller strapped or works as DEVICE. */
    USB_SSP_DRD_DEV = 2U,
    /** Controller strap error. */
    USB_SSP_DRD_ILLEGAL = 3U
} USB_SSP_DRD_Mode;

/**********************************************************************
 * Callbacks
 **********************************************************************/
/** This is a generic callback. It is used to controll depended host and device drivers. */
typedef uint32_t (*USB_SSP_DRD_GenericCallback)(USB_SSP_DRD_PrivData* privData);

/** Type definition for interrupt handler specific for current state. */
typedef uint32_t (*USB_SSP_DRD_InterruptHandler)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of ID pin level change to high. */
typedef uint32_t (*USB_SSP_DRD_EventIdUp)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of ID pin level change to low. */
typedef uint32_t (*USB_SSP_DRD_EventIdDown)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of ID pin level change to high and VBUS level change to low. */
typedef uint32_t (*USB_SSP_DRD_EventIdUpVBusDown)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of ID pin level change to high and VBUS level change to high. */
typedef uint32_t (*USB_SSP_DRD_EventIdUpVBusUp)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of ID pin level change to low and VBUS level change to low. */
typedef uint32_t (*USB_SSP_DRD_EventIdDownVBusDown)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of ID pin level change to low and VBUS level change to high. */
typedef uint32_t (*USB_SSP_DRD_EventIdDownVBusUp)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of forcing DRD mode. */
typedef uint32_t (*USB_SSP_DRD_EventEnableDrd)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of forcing host mode. */
typedef uint32_t (*USB_SSP_DRD_EventEnableHost)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of forcing device mode. */
typedef uint32_t (*USB_SSP_DRD_EventEnableDev)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of disabling host mode. */
typedef uint32_t (*USB_SSP_DRD_EventDisableHost)(USB_SSP_DRD_PrivData* privData);

/** Type definition for transition function for an event of disabling device mode. */
typedef uint32_t (*USB_SSP_DRD_EventDisableDev)(USB_SSP_DRD_PrivData* privData);

/**
 *  @}
 */

/** @defgroup DriverFunctionAPI Driver Function API
 *  Prototypes for the driver API functions. The user application can link statically to the
 *  necessary API functions and call them directly.
 *  @{
 */

/**********************************************************************
 * API methods
 **********************************************************************/

/**
 * Returns the memory requirements for a driver instance.
 * @param[out] sysReq Returns the memory requirements for given configuration.
 * @return CDN_EOK On success.
 * @return CDN_EINVAL If config contains invalid values or not supported.
 */
uint32_t USB_SSP_DRD_Probe(USB_SSP_DRD_SysReq* sysReq);

/**
 * Instantiates the USB_SSP_DRD Core Driver, given the required blocks
 * of memory (this includes initializing the instance and the
 * underlying hardware). If a client configuration is required (likely
 * to always be true), it is passed in also. Returns an instance
 * pointer, which the client must maintain and pass to all other
 * driver functions. (except probe).
 * @param[in] privData Pointer to driver's private data object.
 * @param[in] config Specifies driver/hardware configuration.
 * @param[in] callbacks Event Handlers and Callbacks.
 * @return CDN_EOK On success
 * @return CDN_EINVAL If illegal/inconsistent values in 'config' doesn't support feature(s) required by 'config' parameters.
 * @return CDN_EIO if operation failed
 */
uint32_t USB_SSP_DRD_Init(USB_SSP_DRD_PrivData* privData, const USB_SSP_DRD_Config* config, const USB_SSP_DRD_Callbacks* callbacks);

/**
 * USB_SSP_DRD Core Driver's ISR. Platform-specific code is
 * responsible for ensuring this gets called when the corresponding
 * hardware's interrupt is asserted. Registering the ISR should be
 * done after calling init, and before calling start. The driver's ISR
 * will not attempt to lock any locks, but will perform client
 * callbacks. If the client wishes to defer processing to non-
 * interrupt time, it is responsible for doing so. This function must
 * not be called after calling destroy and releasing private data
 * memory.
 * @param[in] privData Pointer to driver's private data object filled by init.
 * @return CDN_EOK on success
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_Isr(USB_SSP_DRD_PrivData* privData);

/**
 * Start the USB_SSP_DRD driver, enabling interrupts. This is called
 * after the client has successfully initialized the driver and hooked
 * the driver's ISR (the isr member of this struct) to the IRQ.
 * @param[in] privData Pointer to driver's private data object.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_Start(USB_SSP_DRD_PrivData* privData);

/**
 * The client may call this to disable the hardware (disabling its IRQ
 * at the source and disconnecting it if applicable). Also, a best-
 * effort is made to cancel any pending transactions.
 * @param[in] privData Pointer to driver's private data object.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_Stop(const USB_SSP_DRD_PrivData* privData);

/**
 * This performs an automatic stop and then de-initializes the driver.
 * The client may not make further requests on this instance.
 * @param[in] privData Pointer to driver's private data object.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_Destroy(const USB_SSP_DRD_PrivData* privData);

/**
 * Checks if controller is ready.
 * @param[in] privData Pointer to driver's private data object.
 * @param[out] isReady Will tell if controller is ready.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_CheckIfReady(USB_SSP_DRD_PrivData* privData, bool* isReady);

/**
 * Checks strap mode of controller.
 * @param[in] privData Pointer to driver's private data object.
 * @param[out] strapMode Will tell how controller is strapped.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_CheckStrapMode(USB_SSP_DRD_PrivData* privData, USB_SSP_DRD_Mode* strapMode);

/**
 * Checks current operation mode of controller.
 * @param[in] privData Pointer to driver's private data object.
 * @param[out] operationMode Will tell operation mode of controller.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_CheckOperationMode(const USB_SSP_DRD_PrivData* privData, USB_SSP_DRD_Mode* operationMode);

/**
 * Sets operation mode of controller.
 * @param[in] privData Pointer to driver's private data object.
 * @param[in] operationMode Mode of operation that should be set for controller.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_SetOperationMode(USB_SSP_DRD_PrivData* privData, const USB_SSP_DRD_Mode operationMode);

/**
 * Checks if there is an unhndled interrupt pending.
 * @param[in] privData Pointer to driver's private data object.
 * @param[out] interruptVect Interrupt Vector value.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_CheckIrq(const USB_SSP_DRD_PrivData* privData, uint32_t* interruptVect);

/**
 * This function will process an interrupt that is pending.
 * @param[in] privData Pointer to driver's private data object.
 * @return CDN_EOK on success
 * @return CDN_EIO if operation failed
 * @return CDN_EINVAL if input parameters are invalid
 */
uint32_t USB_SSP_DRD_ProcessIrq(USB_SSP_DRD_PrivData* privData);

/**
 *  @}
 */


/* parasoft-end-suppress MISRA2012-RULE-1_1_b_c90-2 */
/* parasoft-end-suppress MISRA2012-RULE-1_1_a_c90-2 */

#endif	/* USB_SSP_DRD_IF_H */
