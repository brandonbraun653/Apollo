/******************************************************************************
 *
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
 *
 ******************************************************************************/

#ifndef USB_SSP_DRD_HW_H
#define USB_SSP_DRD_HW_H

#include "usb_ssp_drd_regs.h"
#include "usb_ssp_drd_if.h"
#include "usb_ssp_drd_structs_if.h"

uint32_t readDID(USB_SspDrdRegs* regsBase);
uint32_t readRID(USB_SspDrdRegs* regsBase);
USB_SSP_DRD_Mode readStrapMode(USB_SspDrdRegs* regsBase);
bool checkIfControllerIsReady(USB_SspDrdRegs* regsBase);
void readIdVbus(USB_SspDrdRegs* regsBase, uint32_t* idVal, uint32_t* vBus);
void enableAllInterrupts(USB_SspDrdRegs* regsBase);
void clearAllInterrupts(USB_SspDrdRegs* regsBase);
uint32_t readInterruptVector(USB_SspDrdRegs* regsBase);
USB_SSP_DRD_Mode readDrdMode(USB_SspDrdRegs* regsBase);
uint32_t enableIdPullup(USB_SspDrdRegs* regsBase);
void enableHwAHost(USB_SspDrdRegs* regsBase);
void enableBPeripheral(USB_SspDrdRegs* regsBase);
void disableHostDevice(USB_SspDrdRegs* regsBase);
void enableFastSim(USB_SspDrdRegs* regsBase);
void switchOtg2ToPeripheral(USB_SspDrdRegs* regsBase);


#endif /* USB_SSP_DRD_HW_H */
