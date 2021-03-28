/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the
 *	  distribution.
 *
 *	* Neither the name of Texas Instruments Incorporated nor the names of
 *	  its contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
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
 */

#include <ti/csl/tistdtypes.h>
#include "firmware_version.h"
#include "iepPwmFwRegs.h"

/* PWM Info defaults */
#define DEF_FW_MAGIC_NUMBER     ( 0x4D575047 )                              /* Firmware Magic Number - GPWM */
#define DEF_FW_TYPE             ( ICSSG_PWM_FIRMWARE_TYPE )                 /* Firmware Type */
#define DEF_FW_VERSION          ( ICSSG_PWM_FIRMWARE_VERSION )              /* Firmware Version */
#define DEF_FW_FEATURE          ( ICSSG_PWM_FIRMWARE_FEATURE )              /* Firmware Feature */
#define DEF_FW_EXTENDED_FEATURE ( ICSSG_PWM_FIRMWARE_EXTENDED_FEATURE_PTR ) /* Firmware Extended Feature */

/* PWM control defaults */
#define DEF_PWM_CTRL            ( 0x00000000 )  /* PWM control - IEP0 & IEP1 PWMs disabled */
#define DEF_PWM_STAT            ( 0x00000000 )  /* PWM status - IEP0 & IEP1 PWM ACK disabled, FW initialization flag uninitialized */
#define DEF_PWM_RECFG           ( 0x00000000 )  /* Default no reconfiguration request */

#define DEF_PWM_MODE            ( 0x00000000 )  /* Default all PWMs are Single-Ended */
#define DEF_PWM_EN              ( 0x00000000 )  /* Default all PWMs are disabled */

/* IEP clock @ 200 MHz */
#define DEF_PRD_COUNT           ( 0x0007A120 )  /* Default Period Count, PWM freq 1 kHz */
#define DEF_DC_COUNT            ( 0x0007A120 )  /* Default DC Count, 50% Duty Cycle PWM freq 1 kHz */
#define DEF_DB_COUNT            ( 0x0A00 )      /* Default DB Count, 2.56 usec. */

/* FW Info register defaults */
#pragma RETAIN(gIepPwmInfoFwRegs)
#pragma DATA_SECTION(gIepPwmInfoFwRegs, ".initDataFwRegs")
const IepPwmInfoFwRegs gIepPwmInfoFwRegs = 
{
    DEF_FW_MAGIC_NUMBER,    /* FwMagicNumber */
    DEF_FW_TYPE,            /* FwType */
    DEF_FW_VERSION,         /* FwVersion */
    DEF_FW_FEATURE,         /* FwFeature */
    DEF_FW_EXTENDED_FEATURE /* FwExtendedFeature - Reserved for future use */
};

/* FW PWM Control/Status register defaults */
#pragma RETAIN(gIepPwmCtrlFwRegs)
#pragma DATA_SECTION(gIepPwmCtrlFwRegs, ".initDataFwRegs")
const IepPwmCtrlFwRegs gIepPwmCtrlFwRegs = 
{
    DEF_PWM_CTRL,   /* PWM_CTRL */
    DEF_PWM_STAT    /* PWM_STAT */
};

/* FW IEP0 PWM register defaults */
#pragma RETAIN(gIep0PwmFwRegs)
#pragma DATA_SECTION(gIep0PwmFwRegs, ".initDataFwRegs")
const IepPwmFwRegs gIep0PwmFwRegs = 
{
    DEF_PWM_RECFG,  /* IEP0_PWM_RECFG */
    DEF_PWM_MODE,   /* IEP0_PWM_MODE */
    DEF_PWM_EN,     /* IEP0_PWM_EN */
    DEF_PRD_COUNT,  /* IEP0_PWM_PRD_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM0_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM1_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM2_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM3_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM4_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM5_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM6_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM7_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM8_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM9_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM10_DC_COUNT */
    DEF_DC_COUNT,   /* IEP0_PWM11_DC_COUNT */
    DEF_DB_COUNT,   /* IEP0_PWM0_1_DEADBAND */
    DEF_DB_COUNT,   /* IEP0_PWM2_3_DEADBAND */
    DEF_DB_COUNT,   /* IEP0_PWM4_5_DEADBAND */
    DEF_DB_COUNT,   /* IEP0_PWM6_7_DEADBAND */
    DEF_DB_COUNT,   /* IEP0_PWM8_9_DEADBAND */
    DEF_DB_COUNT,   /* IEP0_PWM10_11_DEADBAND */
};

/* FW IEP1 PWM register defaults */
#pragma RETAIN(gIep1PwmFwRegs)
#pragma DATA_SECTION(gIep1PwmFwRegs, ".initDataFwRegs")
const IepPwmFwRegs gIep1PwmFwRegs = 
{
    DEF_PWM_RECFG,  /* IEP1_PWM_RECFG */
    DEF_PWM_MODE,   /* IEP1_PWM_MODE */
    DEF_PWM_EN,     /* IEP1_PWM_EN */
    DEF_PRD_COUNT,  /* IEP1_PWM_PRD_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM0_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM1_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM2_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM3_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM4_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM5_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM6_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM7_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM8_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM9_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM10_DC_COUNT */
    DEF_DC_COUNT,   /* IEP1_PWM11_DC_COUNT */
    DEF_DB_COUNT,   /* IEP1_PWM0_1_DEADBAND */
    DEF_DB_COUNT,   /* IEP1_PWM2_3_DEADBAND */
    DEF_DB_COUNT,   /* IEP1_PWM4_5_DEADBAND */
    DEF_DB_COUNT,   /* IEP1_PWM6_7_DEADBAND */
    DEF_DB_COUNT,   /* IEP1_PWM8_9_DEADBAND */
    DEF_DB_COUNT,   /* IEP1_PWM10_11_DEADBAND */
};

