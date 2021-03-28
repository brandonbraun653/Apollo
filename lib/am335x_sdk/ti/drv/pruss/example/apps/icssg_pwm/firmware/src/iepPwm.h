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

#ifndef _IEP_PWM_H_
#define _IEP_PWM_H_

#include <ti/csl/tistdtypes.h>
#include "iepPwmFwRegs.h"
#include "iepPwmHwRegs.h"

/* Return status codes */
#define IEP_STS_RECFG_PRD_COUNT     ( 1 )   /* no error, IEP Period Count reconfiguration */
#define IEP_STS_NERR                ( 0 )   /* no error */
#define IEP_STS_ERR_INV_IEP_ID      ( -1 )  /* error, invalid IEP ID */
#define IPE_STS_ERR_INV_DC_COUNT    ( -2 )  /* error, invalid Duty Cycle Count */

/* IEPs per ICSSG */
#define ICSSG_NUM_IEP               ( 2 )

/* PWM sets per IEP */
#define IEP_NUM_PWM_SET             ( 2 )       

/* Number of PWMs per Differential PWM pair */
#define NUM_PWM_PER_DIFF_PWM        ( 2 )
/* Number of differential PWMs per PWM set */
#define DIFF_PWM_PER_SET            ( 3 )
/* Number of single-ended PWMs per PWM set, two sets per IEP */
#define SNGL_PWM_PER_SET            ( DIFF_PWM_PER_SET * NUM_PWM_PER_DIFF_PWM )

/* IEP maximum number of Differential PWMs */
#define IEP_MAX_NUM_DIFF_PWM        ( IEP_NUM_PWM_SET * DIFF_PWM_PER_SET )
/* IEP maximum number of Single-Ended PWMs */
#define IEP_MAX_NUM_SNGL_PWM        ( IEP_NUM_PWM_SET * SNGL_PWM_PER_SET )

#define DEF_COUNT_INC_PER_CLK       ( 5 )   /* IEP counter default increments per tick */

#define IEP_CMP_STATUS_CMP0_MASK    ( 0x1 )
#define IEP_CMP_STATUS_CMP1_12_MASK ( 0x1FFE )
#define IEP_CMP_STATUS_CMP0_12_MASK ( IEP_CMP_STATUS_CMP0_MASK | IEP_CMP_STATUS_CMP1_12_MASK )


/* IEP IDs */
typedef enum IepId_e
{
    IEP_ID_0 = 0,   /* IEP 0 ID */
    IEP_ID_1 = 1    /* IEP 1 ID */
} IepId;

/* Latch Actions */
typedef enum IepLatchAction_e
{
    /* Latch Action: None */
    LATCH_ACTION_None = 0, 
    /* Latch Action: Latch 0 -- don't calculate LHS/RHS DC*/
    LATCH_ACTION_Latch_0    = 1, 
    /* Latch Action: Latch 100 -- don't calculate LHS/RHS DC */
    LATCH_ACTION_Latch_100  = 2, 
    /* Latch Action: Latch x, x!=0, x!=100, calculate LHS/RHS DC */
    LATCH_ACTION_Latch_New  = 3
} IepLatchAction;

/* Left-Hand Side Actions */
typedef enum IepPwmLhsAction_e
{
    /* LHS Action: None */
    LHS_ACTION_None                                     = 0, 
    /* LHS Action: Set IEP CMP Shadow Register to new value Y */
    LHS_ACTION_Set_CmpSr_DcLhsY                         = 1, 
    /* LHS Action: Set IEP CMP Shadow Register to old (latched) value X &
       enable Shadow Register update */
    LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate      = 2,
    /* LHS Action: Set IEP CMP Shadow Register to new value Y &
       enable Shadow Register update */
    LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate      = 3,
    /* RHS Action: Set IEP CMP Shadow Register early in CMP0 Period & 
       enable Shadow Register update */
    LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate  = 4,
    /* RHS Action: Set IEP CMP Shadow Register > CMP0 Period & 
       enable Shadow Register update */
    LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate      = 5
} IepPwmLhsAction;

/* Right-Hand Side Actions */
typedef enum IepPwmRhsAction_e
{
    /* RHS Action: None */
    RHS_ACTION_None                                     = 0, 
    /* RHS Action: Set IEP CMP Shadow Register to new value Y & 
       enable Shadow Register update */
    RHS_ACTION_Set_CmpSr_DcRhsY_And_EnableSrUpdate      = 1,
    /* RHS Action: Set IEP CMP Shadow Register > CMP0 Period & 
       enable Shadow Register update */
    RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate      = 2    
} IepPwmRhsAction;

/* IEP PWM State Machine configurations */
typedef enum IepSm_Config_e
{
    IEP_SM_CONFIG_NONE      = 0,    /* IEP SM Configuration, IEP0 & 1 disabled */
    IEP_SM_CONFIG_IEP1      = 1,    /* IEP SM Configuration, IEP0 disabled, IEP1 enabled */
    IEP_SM_CONFIG_IEP0      = 2,    /* IEP SM Configuration, IEP0 enabled, IEP1 disabled */
    IEP_SM_CONFIG_IEP0_1    = 3     /* IEP SM Configuration, IEP0 & 1 enabled */
} IepSm_Config;

/* IEP PWM State Machine states */
typedef enum IepSm_States_e
{
    IEP_SM_STATE_UNINIT     = 0,    /* IEP SM State, Uninitialized */
    IEP_SM_STATE_INIT       = 1,    /* IEP SM State, Initialization */
    IEP_SM_STATE_LHS        = 2,    /* IEP SM State, Left-Hand Side */
    IEP_SM_STATE_RHS        = 3,    /* IEP SM State, Right-Hand Side */
    IEP_SM_STATE_LHS_RECFG  = 4,    /* IEP SM State, Left-Hand Side Reconfiguration */
    IEP_SM_STATE_RHS_RECFG  = 5,    /* IEP SM State, Right-Hand Side Reconfiguration */
} IepSm_States;


/* ICSSG IEP PWM control object */
typedef struct IcssgIepPwmCtrlObj_s
{
    Bool                        iepPwmGblEn[ICSSG_NUM_IEP];             /* IEP PWM global disable/enable flags */
    CSL_IcssCfgRegs		*pIcssgCfgHwRegs;                       /* ICSSG CFG registers, init to CSL_ICSS_CFG_BASE */
    IepPwmCtrlFwRegs            *pIepPwmCtrlFwRegs;                     /* IEP PWM FW control registers, init to &PWM_CTRL */
} IcssgIepPwmCtrlObj;

/* ICSSG IEP PWM object */
typedef struct IcssgIepPwmObj_s
{
    IepId                       iepId;                                  /* IEP ID, init to 0 or 1 */
    Uint32                      iepPwmMode;                             /* IEP mode */
    Uint32                      iepPwmEn;                               /* IEP enable */
    Uint32                      iepPwmPeriodCount;                      /* IEP period count */
    Uint32                      iepPwmDcCount[IEP_MAX_NUM_SNGL_PWM];    /* IEP PWM calculated duty cycle count for Symmetric PWM */
    Uint16                      iepPwmDbCount[IEP_MAX_NUM_DIFF_PWM];    /* IEP PWM dead band cycle count for differential mode PWM */
    Uint16                      iepPwmSnglEn;                           /* Bits 11-0 determine if single-ended mode enabled */
    Uint8                       iepPwmDiffEn;                           /* Bits 5-0 determine if differential mode enabled */
    Uint16                      iepPwmSnglUpdEn;                        /* Bits 11-0 determine if single-ended mode update enabled */
    Uint8                       iepPwmDiffUpdEn;                        /* Bits 5-0 determine if differential mode update enabled */
    Uint32                      iepPwmDcCountLhs[IEP_MAX_NUM_SNGL_PWM]; /* IEP PWM calculated duty cycle count for Left-Hand Side of Symmetric PWM */
    Uint32                      iepPwmDcCountRhs[IEP_MAX_NUM_SNGL_PWM]; /* IEP PWM calculated duty cycle count for Right-Hand Side of Symmetric PWM */
    IepSm_States                iepPwmState;                            /* State Machine current state */
    Bool                        iepPwmRhsRecfgFlag;                     /* init to FALSE, set to TRUE if RHS reconfig required */
    IepPwmRhsAction             iepPwmRhsAction[IEP_MAX_NUM_SNGL_PWM];  /* IEP PWM RHS action */
    IepPwmFwRegs                *pIepPwmFwRegs;                         /* IEP PWM FW registers, init to &IEPx_PWM_RECFG */
    CSL_icss_g_pr1_iep1_slvRegs *pIepHwRegs;                            /* IEP hardware registers base address, init to CSL_ICSS_IEP_CFG_BASE */
    IepPwmTripHwRegs            *pIepPwmTripHwRegs;                     /* IEP PWM Trip Configuration hardware registers base address. IEP0: init to ICSSG_PWM0, IEP1: init to ICSSG_PWM2. */
    IepPwmStateCfgHwRegs        *pPwmStateCfgHwRegs;                    /* IEP PWM State Configuration hardware registers base address. IEP0: init to ICSSG_PWM0_0, IEP1: init to ICSSG_PWM2_0. */
    volatile uint32_t           *iepCmpSrAddr[IEP_MAX_NUM_SNGL_PWM];    /* IEP CMP Shadow Register address table -- used to circumvent gap in CMP SR MM addresses */
    
} IcssgIepPwmObj;

extern IcssgIepPwmCtrlObj gIcssgIepPwmCtrlObj;  /* IEP PWM control object */
extern IcssgIepPwmObj gIcssgIep0PwmObj;         /* IEP 0 PWM object */
extern IcssgIepPwmObj gIcssgIep1PwmObj;         /* IEP 1 PWM object */

/* Reset PWM FW control object */
Int32 resetPwmCtrlObj(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
);

/* Wait for PWM enable flag from Host.
   Flag indicates to FW that initialization can commence. */
Int32 waitPwmEnFlag(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
);

/* Initialize PWM FW control */
Int32 initPwmCtrl(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
);

/* Reset IEP PWM object */
Int32 resetIepPwmObj(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    IepId iepId
);

/* Initialize IEP PWM object
 * 
 *  Initial Configuration is located in Host I/F FW Regs.
 *  Default Initial Configuration is loaded in DMEM load (static data).
 *  Host can overwrite Default Initial Configuration *before* FW execution.
 *
 *  Initial Configuration Applied whether Host_RECFG != 0 or not, i.e. Host_RECFG not checked.
 *  Initial Configuration is only place PWM MODE is configured.
*/
Int32 initIepPwm(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj, 
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Set PWM FW initialization flag.
   Flag indicates to Host that FW initialization is complete. */
Int32 setPwmFwInitFlag(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
);

/* Get IEP PWM State Machine configuration:
    - IEP0 disabled, IEP1 disabled
    - IEP0 disabled, IEP1 enabled
    - IEP0 enabled, IEP1 disabled
    - IEP0 enabled, IEP1 enabled */
IepSm_Config getIepPwmSmConfig(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
);

/* Initialize IEP PWM State Machine */
void initIepPwmSm(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Execute IEP PWM State Machine */
Int32 execIepPwmSm(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool txHostEvt
);

#endif /* _IEP_PWM_H_ */
