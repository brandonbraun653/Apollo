/**
 *  \file     am43xx_gs70_phy_driver.h
 *
 *  \brief    This file contains APIs for manipulating the AM43xx USB phy. 
 *            AM43xx has GS70 USB phy which is a USB 2.0 capable phy. 
 *  
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef  USB_AM43XX_GS70_PHY_DRIVER_H
#define  USB_AM43XX_GS70_PHY_DRIVER_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */
/* None */
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/* None */
/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API turns on the AM43xx USB GS70 phy. VBUS detect, and session 
 *          comparators are turned on.             
 *  
 * \param   instNum         instance number of the controller instance 
 *                          whose Phy is to be turned on.  
 *
 **/ 
void USBAm43Gs70PhyOn(uint32_t instNum);

/**
 * \brief   This API Inverts the DP/DM polarity coopared with the normal  
 *          polarity of the port.
 *          
 * \param   instNum         instance number of the controller instance 
 *                          whose Phy polarity needs to be inverted.  
 *
 **/
void USBAm43Gs70PhyInvPolarity(uint32_t instNum);

/**
 * \brief   This API enables PHy based wake up for USB module. When enabled 
 *          PHy clock is kept on during Power down and this feature can be used
 *          for System bring up.          
 *          
 * \param   instNum         instance number of the controller instance 
 *                          whose phy wake feature needs to be enabled.  
 *
 **/
void USBAm43Gs70PhyEnableWakeUp(uint32_t instNum);
/**
 * \brief   This function returns the wakeup status of the USB Phy. 
 *                 
 * \param   instNum         instance number of the controller instance 
 *                          whose phy wake feature needs to be probed. 
 * \retval  Value 1or 0    1 if wakeup is enabled and 0 other wise. 
 *   
 **/     
uint32_t USBAm43Gs70PhyGetWakeUpStatus(uint32_t instNum);
   
/* ========================================================================== */
/*                   Deprecated Function Declarations                         */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef USB_AM43XX_GS70_PHY_DRIVER_H */
