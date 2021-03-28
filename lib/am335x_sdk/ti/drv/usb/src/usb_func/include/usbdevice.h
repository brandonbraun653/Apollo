/******************************************************************************
 * 
 * usbdevice.h - types and definitions used during USB enumeration. 
 * 
 ****************************************************************************** */
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2016
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


#ifndef PDK__USBDEVICE_H
#define PDK__USBDEVICE_H

/******************************************************************************
 * 
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 * 
 ****************************************************************************** */
#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************** 
 * 
 *  \addtogroup device_api 
 *  @{
 * 
 ****************************************************************************** */

/******************************************************************************
 * 
 *  The maximum number of independent interfaces that any single device
 *  implementation can support.  Independent interfaces means interface
 *  descriptors with different bInterfaceNumber values - several interface
 *  descriptors offering different alternative settings but the same interface
 *  number count as a single interface.
 * 
 ****************************************************************************** */
#define USB_MAX_INTERFACES_PER_DEVICE 8

/****************************************************************************** 
 * 
 * Close the Doxygen group. 
 * @} 
 * 
 ****************************************************************************** */

/******************************************************************************
 * 
 * The default USB endpoint FIFO configuration structure.  This structure
 * contains definitions to set all USB FIFOs into single buffered mode with
 * no DMA use.  Each endpoint's FIFO is sized to hold the largest maximum
 * packet size for any interface alternate setting in the current config
 * descriptor.  A pointer to this structure may be passed in the psFIFOConfig
 * field of the tDeviceInfo structure passed to USBCDCInit if the application 
 * does not require any special handling of the USB controller FIFO.
 * 
 ****************************************************************************** */
extern const tFIFOConfig g_sUSBDefaultFIFOConfig;

/******************************************************************************
 * 
 * Public APIs offered by the USB library device control driver.
 * 
 ****************************************************************************** */
extern void USBDCDInit(uint32_t ulIndex, tDeviceInfo *psDevice);
extern void USBDCDTerm(uint32_t ulIndex);
extern void USBDCDStallEP0(uint32_t ulIndex);
extern void USBDCDRequestDataEP0(uint32_t ulIndex, uint8_t *pucData,
                                 uint32_t ulSize);
extern void USBDCDSendDataEP0(uint32_t ulIndex, uint8_t *pucData,
                              uint32_t ulSize);
extern void USBDCDSetDefaultConfiguration(uint32_t ulIndex,
                                          uint32_t ulDefaultConfig);
extern uint32_t USBDCDConfigDescGetSize(const tConfigHeader *psConfig);
extern uint32_t USBDCDConfigDescGetNum(const tConfigHeader *psConfig,
                                            uint32_t ulType);
extern tDescriptorHeader *USBDCDConfigDescGet(const tConfigHeader *psConfig,
                                              uint32_t ulType,
                                              uint32_t ulIndex,
                                              uint32_t *pulSection);
extern uint32_t
       USBDCDConfigGetNumAlternateInterfaces(const tConfigHeader *psConfig,
                                             uint8_t ucInterfaceNumber);
extern tInterfaceDescriptor *
       USBDCDConfigGetInterface(const tConfigHeader *psConfig,
                                uint32_t ulIndex, uint32_t ulAltCfg,
                                uint32_t *pulSection);
extern tEndpointDescriptor *
       USBDCDConfigGetInterfaceEndpoint(const tConfigHeader *psConfig,
                                        uint32_t ulInterfaceNumber,
                                        uint32_t ulAltCfg,
                                        uint32_t ulIndex);
extern void USBDCDPowerStatusSet(uint32_t ulIndex, uint8_t ucPower);
extern uint32_t USBDCDRemoteWakeupRequest(uint32_t ulIndex);

/******************************************************************************
 *
 * Early releases of the USB library had the following function named
 * incorrectly.  This macro ensures that any code which used the previous name
 * will still operate as expected.
 *
 ****************************************************************************** */
#ifndef DEPRECATED
#define USBCDCConfigGetInterfaceEndpoint(a, b, c, d)                          \
            USBDCDConfigGetInterfaceEndpoint((a), (b), (c), (d))
#endif

/******************************************************************************
 * 
 * Device mode interrupt handler for controller index 0.
 *
 ****************************************************************************** */
extern void USB0DeviceIntHandler(void);
extern void USB1DeviceIntHandler(void);

/******************************************************************************
 *
 * Mark the end of the C bindings section for C++ compilers.
 * 
 ***************************************************************************** */
#ifdef __cplusplus
}
#endif

#endif /* PDK__USBDEVICE_H */

