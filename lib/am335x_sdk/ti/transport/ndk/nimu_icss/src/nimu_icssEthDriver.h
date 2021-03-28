/**
 *   @file nimu_icssEthDriver.h
 *   @brief
 *      Include file for local functions  and local data types  used to implement NDK NIMU transport interface for ICSS
 */

/* Copyright (C) 2015-2018 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef NIMU_ICSS_ETHDRIVER_H_
#define NIMU_ICSS_ETHDRIVER_H_

#include "ti/drv/icss_emac/icss_emacDrv.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Function to register callback function to process periodic protocol processing
*
* @param callBack	Callback function pointer
* @param userArg    User defined generic argument
*
* @retval none
*/
void NIMU_ICSS_registerPeriodicCb(ICSS_EmacCallBack callBack, void *userArg);

/**
* @internal
* @brief Opens and configures EMAC. Configures Interrupts
*
* @param pi  NIMU_IcssPdInfo structure pointer.
*
* @retval Success(0) or failure(Error Codes defined)
*/
int32_t NIMU_ICSS_open( NIMU_IcssPdInfo *pi );
/**
* @internal
* @brief Closes EMAC and disables interrupts.
*
* @param pi  NIMU_IcssPdInfo structure pointer.
*
* @retval none
*/
void NIMU_ICSS_close( NIMU_IcssPdInfo *pi );
/**
* @internal
* @brief Routine to send out a packet.
*
* @param pi  NIMU_IcssPdInfo structure pointer.
*
* @retval none
*/
void NIMU_ICSS_pktTxNext( NIMU_IcssPdInfo *pi );
/**
* @internal
* @brief This function is called at least every 100ms, faster in a
*      polling environment. The fTimerTick flag is set only when
*      called on a 100ms event.
*
* @param pi  NIMU_IcssPdInfo structure pointer.
* @param fTimerTick Flag for timer, set when called on a 100ms event..
*
* @retval none
*/
void NIMU_ICSS_pktPoll( NIMU_IcssPdInfo *pi, uint32_t fTimerTick );
/**
* @internal
* @brief Low level driver Ioctl interface. This interface can be used for
*  ALE configuration,control,statistics
*
* @param pi  NIMU_IcssPdInfo structure pointer.
* @param cmd Ioctl command.
* @param pBuf Ioctl buffer with commands and params to set/get  configuration from hardware.
* @param size Size of Ioctl buffer
*
* @retval none
*/
int32_t NIMU_ICSS_pktIoctl(NIMU_IcssPdInfo *pi, uint32_t cmd, void* param, uint32_t size);


void NIMU_ICSS_interruptRx(void* queueNum,void* handle); /* misra warning */

#ifdef __cplusplus
}
#endif

#endif /* NIMU_ICSS_ETHDRIVER_H_ */
