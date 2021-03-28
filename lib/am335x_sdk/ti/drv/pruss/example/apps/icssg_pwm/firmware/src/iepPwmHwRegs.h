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
 
#ifndef _IEP_PWM_HW_REGS_H_
#define _IEP_PWM_HW_REGS_H_

#include <ti/csl/tistdtypes.h>
#include <ti/csl/soc.h>

/* IEP0/1 HW register base addresses */
#define ICSS_IEP0_CFG_BASE  ( CSL_ICSS_IEP0_CFG_BASE )
#define ICSS_IEP1_CFG_BASE  ( CSL_ICSS_IEP1_CFG_BASE )

/* PWM trip reset event mask */
#define PWM_TRIP_RESET_MASK ( CSL_ICSSCFG_PWM0_PWM0_TRIP_RESET_MASK )

/* ICSSG_PWM0m_n, set m=0...4, pos/neg signal n=0...3 */
#define PWM_INIT_HIZ            ( 0 )
#define PWM_INIT_LO             ( 1 )
#define PWM_INIT_HI             ( 2 )
#define PWM_TRIP_HIZ            ( 0 )
#define PMW_TRIP_LO             ( 1 )
#define PWM_TRIP_HI             ( 2 )
#define PWM_ACT_TOGGLE          ( 0 )
#define PMW_ACT_LO              ( 1 )
#define PWM_ACT_HI              ( 2 )

/* IEP PWM Trip Configuration hardware registers */
typedef struct IepPwmTripHwRegs_s
{
    volatile Uint32  ICSSG_PWM0;    /* IEP PWM Set 1/2 */
    volatile Uint32  ICSSG_PWM1;    /* IEP PWM Set 2/2 */
} IepPwmTripHwRegs;

/* IEP PWM State Configuration hardware registers */
typedef struct IepPwmStateCfgHwRegs_s
{
    volatile Uint32  ICSSG_PWM0_0;  /* IEP PWM Set 1, PWM0 */
    volatile Uint32  ICSSG_PWM0_1;  /* IEP PWM Set 1, PWM1 */
    volatile Uint32  ICSSG_PWM0_2;  /* IEP PWM Set 1, PWM2 */
    volatile Uint32  ICSSG_PWM1_0;  /* IEP PWM Set 2, PWM0 */
    volatile Uint32  ICSSG_PWM1_1;  /* IEP PWM Set 2, PWM1 */
    volatile Uint32  ICSSG_PWM1_2;  /* IEP PWM Set 2, PWM2 */
} IepPwmStateCfgHwRegs;

#endif /* #define _IEP_PWM_HW_REGS_H_ */
