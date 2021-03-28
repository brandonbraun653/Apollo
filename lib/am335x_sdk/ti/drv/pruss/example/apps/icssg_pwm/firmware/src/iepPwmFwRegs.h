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

#ifndef _IEP_PWM_FW_REGS_H_
#define _IEP_PWM_FW_REGS_H_

#include <ti/csl/cslr_icss.h>

/* PWM Firmware information registers */
typedef struct IepPwmInfoFwRegs_s
{
    volatile Uint32  FwMagicNumber;         /* Firmware Magic Number Fw Reg */
    volatile Uint32  FwType;                /* Firmware Type Information Fw Reg */
    volatile Uint32  FwVersion;             /* Firmware Version Information Fw Reg */
    volatile Uint32  FwFeature;             /* Firmware Feature Information Fw Reg */
    volatile Uint32  FwExtendedFeature;     /* Firmware Extended Feature Information Fw Reg */
} IepPwmInfoFwRegs;

/* PWM Firmware Control/Status registers */
typedef struct IepPwmCtrlFwRegs_s
{
    volatile Uint32  PWM_CTRL;              /* PWM Control Fw Reg */
    volatile Uint32  PWM_STAT;              /* PWM Status Fw Reg */
} IepPwmCtrlFwRegs;

/* IEP PWM Firmware registers */
typedef struct IepPwmFwRegs_s
{
    volatile Uint32  IEP_PWM_RECFG;         /* IEP PWM Reconfiguration Fw Reg */
    volatile Uint32  IEP_PWM_MODE;          /* IEP PWM Mode Fw Reg */
    volatile Uint32  IEP_PWM_EN;            /* IEP PWM Enable Fw Reg */
    volatile Uint32  IEP_PWM_PRD_COUNT;     /* IEP PWM Period Count Fw Reg */
    volatile Uint32  IEP_PWM0_DC_COUNT;     /* IEP PWM0 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM1_DC_COUNT;     /* IEP PWM1 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM2_DC_COUNT;     /* IEP PWM2 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM3_DC_COUNT;     /* IEP PWM3 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM4_DC_COUNT;     /* IEP PWM4 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM5_DC_COUNT;     /* IEP PWM5 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM6_DC_COUNT;     /* IEP PWM6 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM7_DC_COUNT;     /* IEP PWM7 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM8_DC_COUNT;     /* IEP PWM8 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM9_DC_COUNT;     /* IEP PWM9 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM10_DC_COUNT;    /* IEP PWM10 Duty Cycle Count Fw Reg */
    volatile Uint32  IEP_PWM11_DC_COUNT;    /* IEP PWM11 Duty Cycle Count Fw Reg */
    volatile Uint16  IEP_PWM0_1_DB_COUNT;   /* IEP PWM0/1 Dead Band Cycle Count Fw Reg */
    volatile Uint16  IEP_PWM2_3_DB_COUNT;   /* IEP PWM2/3 Dead Band Cycle Count Fw Reg */
    volatile Uint16  IEP_PWM4_5_DB_COUNT;   /* IEP PWM4/5 Dead Band Cycle Count Fw Reg */
    volatile Uint16  IEP_PWM6_7_DB_COUNT;   /* IEP PWM6/7 Dead Band Cycle Count Fw Reg */
    volatile Uint16  IEP_PWM8_9_DB_COUNT;   /* IEP PWM8/9 Dead Band Cycle Count Fw Reg */
    volatile Uint16  IEP_PWM10_11_DB_COUNT; /* IEP PWM10/11 Dead Band Cycle Count Fw Reg */
} IepPwmFwRegs;

#endif /* _IEP_PWM_FW_REGS_H_ */
