/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 * 
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

#ifndef TIMESYNC_EXAMPLE_SOC_DEFINES_AM57XX_H
#define TIMESYNC_EXAMPLE_SOC_DEFINES_AM57XX_H

#include <ti/drv/i2c/I2C.h>
#include <ti/board/board_cfg.h>

#if defined(__ARM_ARCH_7A__)
#include <ti/csl/csl_armGicAux.h>
#endif

/* Change this define to switch between PRUICSS for AM571x */
#define PRUICSS_INSTANCE        (2u)
#define  ICSS_INSTANCE          (2u)

#define CONTROL_CORE_IO 0x4A002558
#define  TIMESYNC_APP_TIMER_ID               (~(uint32_t) 0u) /* Any timer */

extern void timeSync_example_socHwInit(void);
extern void timeSync_example_socgetMACAddress(uint32_t portNum, uint8_t *pMacAddr);
extern void timeSync_example_configureInterrupts(uint32_t portNum, ICSSEMAC_InitConfig *switchEmacCfg);
extern void timeSync_example_crossbarConfig(uint32_t portNum, uint8_t instance);
extern icssVersion_t timeSync_exampleSoCGetIcssVersion(void);
extern uint8_t timeSync_example_loadFirmware(void);

/* external global variables */
extern uint8_t lclMac[6];
extern TimeSync_ParamsHandle_t timeSyncHandle;
extern PRUICSS_Handle pruIcssHandle;
extern ICSS_EmacHandle emachandle;

#endif /* TIMESYNC_EXAMPLE_SOC_DEFINES_AM57XX_H */
