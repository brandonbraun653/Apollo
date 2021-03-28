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

#include <string.h>
#include <ti/csl/soc.h>
#include "icssg_iep_pwm.h"
#include "iepPwmFwRegs.h"
#include "iepPwmHwRegs.h"
#include "iepPwm.h"

/* Define to synchronize IEP0 & 1 clocks. */
//#define IEP_SYNC_CLK_EN
/* Define to enable Tx Host interrupt on IEP0 CMP0 */
//#define TX_HOST_INT


#define CLK_TO_COUNT(x)         ( DEF_COUNT_INC_PER_CLK * x )   /* For default increment per clock, compute count corresponding to number of IEP clocks */
#define COUNT_TO_CLK(x)         ( x / DEF_COUNT_INC_PER_CLK )   /* For default increment per clock, compute IEP clocks corresponding to count */

#define CMP_SR_EARLY_VAL        ( DEF_COUNT_INC_PER_CLK )       /* CMP "Early in Period" value */

/* Index of "sacrificial" PWM in set */
#define SACR_PWM_IDX            ( 0 )

/* Single-Ended PWM Initial State Configuration register */
/* Active state Toggle:0000, Trip state HiZ:0000, Initial state L/L:0101 */
#define SNGL_PWM_STATE_INIT \
    ((PWM_ACT_TOGGLE<<10) | (PWM_ACT_TOGGLE<<8) | (PWM_TRIP_HIZ<<6) | (PWM_TRIP_HIZ<<4) | (PWM_INIT_LO<<2) | (PWM_INIT_LO<<0))
/* Differential PWM Initial State Configuration register */
/* Active state Toggle:0000, Trip state HiZ:0000, Initial state H/L:1001 */
#define DIFF_PWM_STATE_INIT \
    ((PWM_ACT_TOGGLE<<10) | (PWM_ACT_TOGGLE<<8) | (PWM_TRIP_HIZ<<6) | (PWM_TRIP_HIZ<<4) | (PWM_INIT_HI<<2) | (PWM_INIT_LO<<0))

/* Action Table Rows.
 * Each Action Table Row corresponds to a requested Duty Cycle update.
 *  DC_old: latched (current) Duty Cycle
 *  DC_new: requested (new) Duty Cycle 
 */
typedef enum IepPwmActionTableRow_e 
{
    AT_Row01_DcOldX_DcNewX      = 0,    /* DC_old=x, DC_new=x */ 
    AT_Row02_DcOldX_DcNewY      = 1,    /* DC_old=x, DC_new=y */
    AT_Row03_DcOldX_DcNew0      = 2,    /* DC old=x, DC_new=0 */
    AT_Row04_DcOldX_DcNew100    = 3,    /* DC_old=x, DC_new=100 */
    AT_Row05_DcOld0_DcNewY      = 4,    /* DC_old=0, DC_new=y */
    AT_Row06_DcOld0_DcNew0      = 5,    /* DC_old=0, DC_new=0 */
    AT_Row07_DcOld0_DcNew100    = 6,    /* DC_old=0, DC_new=100 */
    AT_Row08_DcOld100_DcNewY    = 7,    /* DC_old=100, DC_new=y */
    AT_Row09_DcOld100_DcNew0    = 8,    /* DC_old=100, DC_new=0 */
    AT_Row10_DcOld100_DcNew100  = 9,    /* DC_old=100, DC_new=100 */
    AT_NROW
} IepPwmActionTableRow;

/* Action Table Entry.
 * Latch, Left-Hand Side, and Right-Hand Side actions to take 
 * for a requested Duty Cycle update.
 */
typedef struct IepPwmActionTableEntry_s
{
    IepLatchAction  latchAction;
    IepPwmLhsAction lhsAction;
    IepPwmRhsAction rhsAction;
} IepPwmActionTableEntry;

/* Action Table: no Enable reconfiguration & En_old==Disabled */
static const IepPwmActionTableEntry gActT1_EnRecfgNo_EnOldDisable[AT_NROW] = 
{
    /* DC_old = DC_new = x */
    {LATCH_ACTION_None,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = x, DC_new = y */
    {LATCH_ACTION_Latch_New,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = x, DC_new = 0 */
    {LATCH_ACTION_Latch_0,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = x, DC_new = 100 */
    {LATCH_ACTION_Latch_100,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = 0, DC_new = y */
    {LATCH_ACTION_Latch_New,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = 0, DC_new = 0 */ 
    {LATCH_ACTION_None,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = 0, DC_new = 100 */
    {LATCH_ACTION_Latch_100,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = 100, DC_new = y */
    {LATCH_ACTION_Latch_New,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = 100, DC_new = 0 */
    {LATCH_ACTION_Latch_0,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = 100, DC_new = 100 */
    {LATCH_ACTION_None,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
};

/* Action table: no Enable reconfiguration, En_old==Enabled */
static const IepPwmActionTableEntry gActT2_EnRecfgNo_EnOldEnable[AT_NROW] = 
{
    /* DC_old = DC_new = x */
    {LATCH_ACTION_None,
     LHS_ACTION_None,                
     RHS_ACTION_None},  
    /* DC_old = x, DC_new = y */
    {LATCH_ACTION_Latch_New,
     LHS_ACTION_Set_CmpSr_DcLhsY,    
     RHS_ACTION_None}, 
    /* DC_old = x, DC_new = 0 */
    {LATCH_ACTION_Latch_0,
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate, 
     RHS_ACTION_None},
    /* DC_old = x, DC_new = 100 */
    {LATCH_ACTION_Latch_100,    
     LHS_ACTION_None, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate}, 
    /* DC_old = 0, DC_new = y */
    {LATCH_ACTION_Latch_New,    
     LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate, 
     RHS_ACTION_None}, 
    /* DC_old = 0, DC_new = 0 */ 
    {LATCH_ACTION_None,   
     LHS_ACTION_None, 
     RHS_ACTION_None}, 
    /* DC_old = 0, DC_new = 100 */
    {LATCH_ACTION_Latch_100,    
     LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate}, 
    /* DC_old = 100, DC_new = y */
    {LATCH_ACTION_Latch_New,    
     LHS_ACTION_None, 
     RHS_ACTION_Set_CmpSr_DcRhsY_And_EnableSrUpdate}, 
    /* DC_old = 100, DC_new = 0 */
    {LATCH_ACTION_Latch_0,      
     LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate}, 
    /* DC_old = 100, DC_new = 100 */
    {LATCH_ACTION_None,   
     LHS_ACTION_None, 
     RHS_ACTION_None} 
};

/* Action table: Enable reconfiguration, En_new==Enabled */
static const IepPwmActionTableEntry gActT3_EnRecfgYes_EnNewEnable[AT_NROW] = 
{
    /* DC_old = DC_new = x */
    {LATCH_ACTION_None,
     LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate,                
     RHS_ACTION_None},  
    /* DC_old = x, DC_new = y */
    {LATCH_ACTION_Latch_New,
     LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate,    
     RHS_ACTION_None}, 
    /* DC_old = x, DC_new = 0 */
    {LATCH_ACTION_Latch_0,
     LHS_ACTION_None, 
     RHS_ACTION_None},
    /* DC_old = x, DC_new = 100 */
    {LATCH_ACTION_Latch_100,    
     LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate}, 
    /* DC_old = 0, DC_new = y */
    {LATCH_ACTION_Latch_New,    
     LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate, 
     RHS_ACTION_None}, 
    /* DC_old = 0, DC_new = 0 */ 
    {LATCH_ACTION_None,   
     LHS_ACTION_None, 
     RHS_ACTION_None}, 
    /* DC_old = 0, DC_new = 100 */
    {LATCH_ACTION_Latch_100,    
     LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate}, 
    /* DC_old = 100, DC_new = y */
    {LATCH_ACTION_Latch_New,    
     LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate, 
     RHS_ACTION_None}, 
    /* DC_old = 100, DC_new = 0 */
    {LATCH_ACTION_Latch_0,      
     LHS_ACTION_None, 
     RHS_ACTION_None}, 
    /* DC_old = 100, DC_new = 100 */
    {LATCH_ACTION_None,   
     LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate} 
};

/* Action table: Enable reconfiguration, En_new==Enabled */
static const IepPwmActionTableEntry gActT4_EnRecfgYes_EnNewDisable[AT_NROW] = 
{
    /* DC_old = DC_new = x */
    {LATCH_ACTION_None,
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate,                
     RHS_ACTION_None},  
    /* DC_old = x, DC_new = y */
    {LATCH_ACTION_Latch_New,
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate,    
     RHS_ACTION_None}, 
    /* DC_old = x, DC_new = 0 */
    {LATCH_ACTION_Latch_0,
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate, 
     RHS_ACTION_None},
    /* DC_old = x, DC_new = 100 */
    {LATCH_ACTION_Latch_100,    
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate, 
     RHS_ACTION_None}, 
    /* DC_old = 0, DC_new = y */
    {LATCH_ACTION_Latch_New,    
     LHS_ACTION_None, 
     RHS_ACTION_None}, 
    /* DC_old = 0, DC_new = 0 */ 
    {LATCH_ACTION_None,   
     LHS_ACTION_None, 
     RHS_ACTION_None}, 
    /* DC_old = 0, DC_new = 100 */
    {LATCH_ACTION_Latch_100,    
     LHS_ACTION_None, 
     RHS_ACTION_None}, 
    /* DC_old = 100, DC_new = y */
    {LATCH_ACTION_Latch_New,    
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate}, 
    /* DC_old = 100, DC_new = 0 */
    {LATCH_ACTION_Latch_0,      
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate}, 
    /* DC_old = 100, DC_new = 100 */
    {LATCH_ACTION_None,   
     LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate, 
     RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate} 
};


IcssgIepPwmCtrlObj gIcssgIepPwmCtrlObj; /* IEP PWM control object */
IcssgIepPwmObj gIcssgIep0PwmObj;        /* IEP 0 PWM object */
IcssgIepPwmObj gIcssgIep1PwmObj;        /* IEP 1 PWM object */    

/* State Machine function, perform LHS processing */
static void iepPwmLhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* State Machine function, perform RHS processing */
static void iepPwmRhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* State Machine function, perform LHS reconfiguration.
 Check Host reconfiguration request.
 Perform Initialization reconfiguration. */
static Int32 iepPwmConfigLhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* State Machine Function, perform RHS reconfiguration.
 Apply pending Host reconfiguration request.
 Perform Initialization reconfiguration. 
    
 IEP PWM object has private information required to perform RHS update.
 This information is set appropriately in LHS (Host) Reconfiguration. */
static Int32 iepPwmConfigRhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Latch IEP PWM mode.
   IEP PWM mode can't change after Initialization. */
static void latchIepPwmMode(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Update IEP Period Count */
static void updateIepPwmPeriodCount(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Reset IEP CMPx.
    - Set CMPx inside CMP0 period for 1/6 of PWMs in each Set. This forces PWM Set Initial->Active State.
    - Set CMPx outside CMP0 period for other 5/6 PWMs in each Set. */
static void resetIepPwmCmpx(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Initialize PWMs */
static void initPwm(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Reinitialize PWMs */
static void reinitPwm(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Latch IEP PWM Enable */
static void latchIepPwmEn(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Latch IEP PWM Period Count */
static void latchIepPwmPeriodCount(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Latch IEP PWM Duty Cycle Counts */
static void latchIepPwmDcCounts(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool recfgFlag
);

/* Latch IEP PWM Deadband Counts */
static void latchIepPwmDbCount(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool recfgFlag
);

/* Calculate IEP PWM Single-Ended and Differential Enable
 *
 *  pIcssgIepPwmObj (I): Pointer to IEP PWM object
 *  pIepPwmSnglEn   (O): Pointer to IEP PWM single-ended enable
 *  pIepPwmDiffEn   (O): Pointer to IEP PWM differential enable
 *
 * IEP_PWM_MODE & IEP_PWM_EN: Host I/F FW Regs.
 * iepPwmSnglEn & iepPwmDiffEn: FW private Regs (or PRU registers), used for processing PWMs.
 *
 */ 
static void calcIepPwmSnglDiffEn(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Uint16 *pIepPwmSnglEn, 
    Uint8 *pIepPwmDiffEn
);

/* Latch IEP PWM Single-Ended and Differential Enable */
static void latchIepPwmSnglDiffEn(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Uint16 iepPwmSnglEn,
    Uint8 iepPwmDiffEn
);

/* Calculate & Latch IEP PWM LHS/RHS Duty Cycle Counts */
static Int32 calcAndLatchIepPwmDcLhsRhsCount(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool recfgFlag
);

/* Initialize IEP PWM CMPx Shadow Registers */
static Int32 initIepPwmCmpxShReg(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Determine initial LHS/RHS actions */
static Int32 getInitLhsAction(
    Bool initToActPwm, 
    Bool pwmEn, 
    Uint32 iepPwmDcCount, 
    Uint32 pwmPeriodCount, 
    IepPwmLhsAction *pActionLhs, 
    IepPwmRhsAction *pActionRhs
);

/* Initial update IEP PWM CMPx Shadow Register, Single-Ended Mode */
static void execInitLhsActionSngl(
    IepPwmLhsAction actionLhs, 
    Uint32 iepPwmPeriodCount, 
    Uint32 iepPwmDcCountLhs, 
    volatile uint32_t **pIepCmpSrAddr, 
    Uint16 *pIepPwmSnglUpdEn, 
    Uint8 pwmIdx
);

/* Initial update IEP PWM CMPx Shadow Registers, Differential Mode */
static void execInitLhsActionDiff(
    IepPwmLhsAction actionLhs, 
    Uint32 iepPwmPeriodCount, 
    Uint32 iepPwmDcCountLhs, 
    volatile uint32_t **pIepCmpSrAddr,
    Uint8 *pIepPwmDiffUpdEn, 
    Uint8 dPwmIdx
);

/* Update IEP PWM CMPx Shadow Registers.
   PWM Enable and DC Count reconfiguration handled jointly. */
static Int32 updateIepPwmCmpxShRegPwmEnDc(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Stash RHS action */
static void stashRhsAction(
    IepPwmRhsAction actionRhs, 
    Bool *pIepPwmRhsRecfgFlag, 
    IepPwmRhsAction *pIepPwmRhsAction
);

/* Get Action Table row, Single-Ended PWM
 *   recfgIepPwmDcCount  : (I) IEP PWM DC count reconfiguration mask
 *   iepPwmDcCountOld    : (I) Old (latched) IEP PWM DC count
 *   iepPwmDcCountNew    : (I) New (input) IEP PWM DC count
 *   pwmIdx              : (I) Single-Ended PWM index, 0...IEP_PWM_MODE_SNGL-1
 *   pwmPeriodCount      : (I) PWM period count
 *   pRowIdx             : (O) address of row index 
 */
static Int32 getActionTableRowSngl(
    Uint16 recfgDcCount, 
    Uint8 pwmIdx, 
    Uint32 iepPwmDcCountOld, 
    Uint32 iepPwmDcCountNew, 
    Uint32 pwmPeriodCount, 
    Uint8 *pRowIdx
);

/* Get Action Table row, Differential PWM
 *  recfgDcCount        : (I) IEP PWM DC count reconfiguration mask
 *  iepPwmDcCountOld    : (I) Old (latched) IEP PWM DC count
 *  iepPwmDcCountNew    : (I) New (input) IEP PWM DC count
 *  pwmIdx              : (I) Differential PWM index, 0...IEP_PWM_MODE_DIFF-1
 *  pwmPeriodCount      : (I) PWM period
 *  pRowIdx             : (O) address of row index
 */
static Int32 getActionTableRowDiff(
    Uint16 recfgDcCount, 
    Uint8 dPwmIdx, 
    Uint32 iepPwmDcCountOld, 
    Uint32 iepPwmDcCountNew, 
    Uint32 pwmPeriodCount, 
    Uint8 *pRowIdx
);

/* Calculate IEP PWM LHS/RHS Duty Cycle Counts
 *  actionLatch             : (I)   Latch Action
 *  iepPwmDcCountNew        : (I)   New (input) IEP PWM DC count
 *  pIepPwmDcCountLhsNew    : (O)   IEP PWM DC LHS count
 *  pIepPwmDcCountRhsNew    : (O)   IEP PWM DC RHS count
 */
static void calcDcLatchAction(
    IepLatchAction actionLatch, 
    Uint32 iepPwmDcCountNew, 
    Uint32 *pIepPwmDcCountLhsNew, 
    Uint32 *pIepPwmDcCountRhsNew
);

/* Calculate DC LHS/RHS for DC */
static void calcDcLhsRhs(
    Uint32 dcCount, 
    Uint32 *pDcCountLhs, 
    Uint32 *pDcCountRhs
);

/* Execute LHS action, Single-Ended PWM
 *  iepPwmDcCountLhsOld : (I) scalar, old DC LHS
 *  iepPwmDcCountLhsNew : (I) scalar, new DC LHS
 *  pIepCmpSrBase       : (I) base pointer for CMP SRs
 *  pIepPwmSnglUpdEn    : (I) single-ended signal update enable
 *  pwmIdx              : (I) 0...IEP_MAX_NUM_SNGL_PWM-1
 *  iepPwmPeriodCount   : (I) IEP CMP0 period count
 */
static void execLhsActionSngl(
    IepPwmLhsAction lhsAction, 
    Uint32 iepPwmDcCountLhsOld, 
    Uint32 iepPwmDcCountLhsNew, 
    volatile uint32_t **pIepCmpSrAddr, 
    Uint16 *pIepPwmSnglUpdEn, 
    Uint8 pwmIdx, 
    Uint32 iepPwmPeriodCount
);

/* Execute LHS action, Differential PWM
 *  iepPwmDcCountLhsOld : (I) scalar, old DC LHS
 *  iepPwmDcCountLhsNew : (I) scalar, new DC LHS
 *  pIepCmpSrBase       : (I) base pointer for CMP SRs
 *  pIepPwmDiffUpdEn    : (I) single-ended signal update enable
 *  dPwmIdx             : (I) 0...IEP_MAX_NUM_DIFF_PWM-1
 *  iepPwmPeriodCount   : (I) IEP CMP0 period count
 */
static void execLhsActionDiff(
    IepPwmLhsAction lhsAction, 
    Uint32 iepPwmDcCountLhsOld, 
    Uint32 iepPwmDcCountLhsNew, 
    volatile uint32_t **pIepCmpSrAddr, 
    Uint8 *pIepPwmDiffUpdEn, 
    Uint8 dPwmIdx, 
    Uint32 iepPwmPeriodCount
);


/* Execute (LHS) DC latch action
 *  actionLatch             : (I)   Latch Action
 *  pIepPwmDcCountOld       : (I)   Pointer to old (latched) IEP PWM DC count
 *  pIepPwmDcCountLhsOld    : (I)   Pointer to IEP PWM DC LHS count
 *  pIepPwmDcCountRhsOld    : (I)   Pointer to IEP PWM DC RHS count
 *  iepPwmDcCountNew        : (I)   new IEP PWM DC count
 *  iepPwmDcCountLhsNew     : (I)   new IEP PWM DC LHS count
 *  iepPwmDcCountRhsNew     : (I)   new IEP PWM DC RHS count 
 */
static void execDcLatchAction(
    IepLatchAction actionLatch, 
    Uint32 *pIepPwmDcCountOld, 
    Uint32 *pIepPwmDcCountLhsOld, 
    Uint32 *pIepPwmDcCountRhsOld, 
    Uint32 iepPwmDcCountNew, 
    Uint32 iepPwmDcCountLhsNew, 
    Uint32 iepPwmDcCountRhsNew
);

/* Execute stashed RHS actions */
static void execRhsActionStash(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

/* Update IEP PWM CMPx Shadow Registers for DB reconfiguration. */
static Int32 updateIepPwmCmpxShRegDb(
    IcssgIepPwmObj *pIcssgIepPwmObj
);

#ifdef TX_HOST_INT
volatile register uint32_t __R31;
#endif

/* ------------------------------------------------------------------------- *
 * External Functions                                                        *
 * ------------------------------------------------------------------------- */

/* Reset PWM FW control object */
Int32 resetPwmCtrlObj(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
)
{
    Uint8 i;
    
    for (i = 0; i < ICSSG_NUM_IEP; i++)
    {
        pIcssgIepPwmCtrlObj->iepPwmGblEn[i] = FALSE;
    }
    
    pIcssgIepPwmCtrlObj->pIcssgCfgHwRegs = (CSL_IcssCfgRegs *)CSL_ICSS_CFG_BASE;
    pIcssgIepPwmCtrlObj->pIepPwmCtrlFwRegs = (IepPwmCtrlFwRegs *)ICSSG_IEPPWM_PWM_CTRL_ADDR;
    return IEP_STS_NERR;
}

/* Reset IEP PWM object */
Int32 resetIepPwmObj(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    IepId iepId
)
{
    CSL_IcssCfgRegs *pruIcssgCfg = (CSL_IcssCfgRegs *)CSL_ICSS_CFG_BASE;
    CSL_icss_g_pr1_iep1_slvRegs *pIepHwRegs;
    volatile uint32_t *pIepCmpSr;
    Uint8 pwmIdx;
    
    memset(pIcssgIepPwmObj, 0, sizeof(IcssgIepPwmObj));
    pIcssgIepPwmObj->iepId = iepId;
    if (iepId == IEP_ID_0) {
        pIcssgIepPwmObj->pIepPwmFwRegs = (IepPwmFwRegs *)ICSSG_PWM_IEP0_PWM_BASE_ADDR;
        pIcssgIepPwmObj->pIepHwRegs = (CSL_icss_g_pr1_iep1_slvRegs *)ICSS_IEP0_CFG_BASE;
        pIcssgIepPwmObj->pIepPwmTripHwRegs = (IepPwmTripHwRegs *)(&pruIcssgCfg->PWM0);
        pIcssgIepPwmObj->pPwmStateCfgHwRegs = (IepPwmStateCfgHwRegs *)(&pruIcssgCfg->PWM0_0);
    }
    else if (iepId == IEP_ID_1) {
        pIcssgIepPwmObj->pIepPwmFwRegs = (IepPwmFwRegs *)ICSSG_PWM_IEP1_PWM_BASE_ADDR;
        pIcssgIepPwmObj->pIepHwRegs = (CSL_icss_g_pr1_iep1_slvRegs *)ICSS_IEP1_CFG_BASE;
        pIcssgIepPwmObj->pIepPwmTripHwRegs = (IepPwmTripHwRegs *)(&pruIcssgCfg->PWM2);
        pIcssgIepPwmObj->pPwmStateCfgHwRegs = (IepPwmStateCfgHwRegs *)(&pruIcssgCfg->PWM2_0);
    }
    else {
        return IEP_STS_ERR_INV_IEP_ID;
    }
    
    pIepHwRegs = pIcssgIepPwmObj->pIepHwRegs;
    
    /* Initialize CMP Shadow Register address table */
    /* CMP1-6 */
    pIepCmpSr = &pIepHwRegs->CMP1_REG1;
    for (pwmIdx = 0; pwmIdx < SNGL_PWM_PER_SET; pwmIdx++)
    {
        pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx] = pIepCmpSr;
        pIepCmpSr += 2; /* CMP regs are 64 bit */
    }
    pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx] = pIepCmpSr; /* CMP7 SR */
    pIepCmpSr += 4; /* account for 64-bit gap in CMP register MM */
    /* CMP7-12 */
    for (pwmIdx = SNGL_PWM_PER_SET+1; pwmIdx < IEP_MAX_NUM_SNGL_PWM; pwmIdx++)
    {
        pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx] = pIepCmpSr;
        pIepCmpSr += 2; /* CMP regs are 64 bit */
    }
    
    return IEP_STS_NERR;
}

/* Wait for PWM enable flag from Host.
   Flag indicates to FW that initialization can commence. */
Int32 waitPwmEnFlag(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
)
{
    IepPwmCtrlFwRegs *pIepPwmCtrlFwRegs = pIcssgIepPwmCtrlObj->pIepPwmCtrlFwRegs;
    Uint8 pwmEn;
    
    do {
        pwmEn = (pIepPwmCtrlFwRegs->PWM_CTRL & PWM_CTRL_PWM_EN_MASK) >> PWM_CTRL_PWM_EN_SHIFT;
    } while (pwmEn == BF_PWM_EN_DISABLE);
    
    pIepPwmCtrlFwRegs->PWM_STAT |= BF_PWM_EN_ACK_ENABLE << PWM_STAT_PWM_EN_ACK_SHIFT;   /* PWM_STAT:PWM_EN_ACK=1 */
    
    return IEP_STS_NERR;
}

/* Initialize PWM FW control */
Int32 initPwmCtrl(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
)
{
    IepPwmCtrlFwRegs *pIepPwmCtrlFwRegs = pIcssgIepPwmCtrlObj->pIepPwmCtrlFwRegs; 
    volatile Uint32 iepClkReg;
    Uint8 i;
#ifdef IEP_SYNC_CLK_EN
    Bool iepSync;
#endif

    for (i = 0; i < ICSSG_NUM_IEP; i++)
    {
        /* Latch IEP PWM global enable.
           Global enable can't change after Initialization. */
        pIcssgIepPwmCtrlObj->iepPwmGblEn[i] = 
            (Bool)((pIepPwmCtrlFwRegs->PWM_CTRL >> (PWM_CTRL_IEP0_PWM_GBL_EN_SHIFT+i) ) & IEP_PWM_GBL_EN_MASK);
        /* Acknowledge IEP PWM global enable */
        pIepPwmCtrlFwRegs->PWM_STAT |= (Uint32)pIcssgIepPwmCtrlObj->iepPwmGblEn[i] << (PWM_CTRL_IEP0_PWM_GBL_EN_SHIFT+i);
    }
    
#ifdef IEP_SYNC_CLK_EN
    iepSync = TRUE;
    for (i = 0; i < ICSSG_NUM_IEP; i++)
    {
        /* Update IEP clock synchronization flag.
           All IEPs must be enabled for IEP clock synchronization to be enabled. */
        iepSync = iepSync && pIcssgIepPwmCtrlObj->iepPwmGblEn[i];
    }
    if (iepSync == TRUE) {
        /* Set IEP0 & 1 synchronization */
        
        /* Read ICSSG_IEPCLK_REG HW register */
        iepClkReg = pIcssgIepPwmCtrlObj->pIcssgCfgHwRegs->IEPCLK_REG;
        /* ICSSG_IEPCLK_REG:IEP1_SLV_EN=0 */
        iepClkReg &= ~CSL_ICSS_G_PR1_CFG_SLV_IEPCLK_REG_IEP1_SLV_EN_MASK;
        /* ICSSG_IEPCLK_REG:IEP1_SLV_EN=1,
           IEP1 Master Counter Slave enable is Enabled */
        iepClkReg |= 1<< CSL_ICSS_G_PR1_CFG_SLV_IEPCLK_REG_IEP1_SLV_EN_SHIFT;
        /* Write ICSSG_IEPCLK_REG HW register */
        pIcssgIepPwmCtrlObj->pIcssgCfgHwRegs->IEPCLK_REG = iepClkReg;
    }
#endif
    
    return IEP_STS_NERR;
}

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
)
{
    IepId iepId = pIcssgIepPwmObj->iepId;
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    Uint16 iepPwmSnglEn;
    Uint8 iepPwmDiffEn;
    Int32 status = IEP_STS_NERR;
    
    /* Latch IEP PWM global enable.
       Global enable can't change after Initialization. */
    /* Acknowledge IEP PWM global enable */
    
    /* Configure PWMs */
    
    if (pIcssgIepPwmCtrlObj->iepPwmGblEn[iepId] == TRUE) {
        /* Latch IEP PWM mode.
           IEP PWM mode can't change after Initialization. */
        latchIepPwmMode(pIcssgIepPwmObj);
        
        /* Update IEP Period Count */
        updateIepPwmPeriodCount(pIcssgIepPwmObj);

        /* Reset IEP0 CMPx.
            - Set CMPx inside CMP0 period for 1/6 of PWMs in each Set. This forces PWM Set Initial->Active State.
            - Set CMPx outside CMP0 period for other 5/6 PWMs in each Set. */
        resetIepPwmCmpx(pIcssgIepPwmObj);
        
        /* Initialize PWMs */
        initPwm(pIcssgIepPwmObj);
        
        /* Latch IEP PWM Enable */
        latchIepPwmEn(pIcssgIepPwmObj);
        
        /* Latch Period Count */
        latchIepPwmPeriodCount(pIcssgIepPwmObj);
        
        /* Latch IEP PWM Duty Cycle Counts */
        latchIepPwmDcCounts(pIcssgIepPwmObj, FALSE);
        
        /* Latch IEP PWM Deadband Counts */
        latchIepPwmDbCount(pIcssgIepPwmObj, FALSE);
        
        /* Calculate & Latch Single-Ended and Differential PWM Enable */
        calcIepPwmSnglDiffEn(pIcssgIepPwmObj, &iepPwmSnglEn, &iepPwmDiffEn);
        latchIepPwmSnglDiffEn(pIcssgIepPwmObj, iepPwmSnglEn, iepPwmDiffEn);

        /* Calculate & Latch LHS/RHS Duty Cycle Counts */
        calcAndLatchIepPwmDcLhsRhsCount(pIcssgIepPwmObj, FALSE);    

        /* Clear reconfiguration flags whether set or not */
        pIepPwmFwRegs->IEP_PWM_RECFG = 0;
    }
         
    return status;
}

/* Set PWM FW initialization flag.
   Flag indicates to Host that FW initialization is complete. */
Int32 setPwmFwInitFlag(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
)
{
    IepPwmCtrlFwRegs *pIepPwmCtrlFwRegs = pIcssgIepPwmCtrlObj->pIepPwmCtrlFwRegs; 
    pIepPwmCtrlFwRegs->PWM_STAT |= BF_PWM_FW_INIT_INIT << PWM_STAT_FW_INIT_SHIFT;   /* PWM_STAT:FW_INIT=1 */
    
    return IEP_STS_NERR;
}

/* Get IEP PWM State Machine configuration:
    - IEP0 disabled, IEP1 disabled
    - IEP0 disabled, IEP1 enabled
    - IEP0 enabled, IEP1 disabled
    - IEP0 enabled, IEP1 enabled */
IepSm_Config getIepPwmSmConfig(
    IcssgIepPwmCtrlObj *pIcssgIepPwmCtrlObj
)
{
    Bool iep0PwmGblEn, iep1PwmGblEn;
    IepSm_Config ret;
    
    
    iep0PwmGblEn = pIcssgIepPwmCtrlObj->iepPwmGblEn[0];
    iep1PwmGblEn = pIcssgIepPwmCtrlObj->iepPwmGblEn[1];
    
    if (iep0PwmGblEn == FALSE) {
        ret = (iep1PwmGblEn == FALSE) ? IEP_SM_CONFIG_NONE : IEP_SM_CONFIG_IEP1;
    }
    else {
        ret = (iep1PwmGblEn == FALSE) ? IEP_SM_CONFIG_IEP0 : IEP_SM_CONFIG_IEP0_1;
    }
    
    return ret;
}

/* Initialize IEP PWM State Machine */
void initIepPwmSm(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_INIT;
    
    /* Enable IEP Counter */
    pIcssgIepPwmObj->pIepHwRegs->GLOBAL_CFG_REG |= 0x1;
}

/* Execute IEP PWM State Machine */
Int32 execIepPwmSm(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool txHostEvt
)
{
    CSL_icss_g_pr1_iep1_slvRegs *pIepHwRegs = pIcssgIepPwmObj->pIepHwRegs;
    uint32_t cmpStatus;
    Int32 status = IEP_STS_NERR;
    
    cmpStatus = pIepHwRegs->CMP_STATUS_REG;
    if (pIcssgIepPwmObj->iepPwmState == IEP_SM_STATE_INIT) {
        if ((cmpStatus & IEP_CMP_STATUS_CMP0_MASK) == IEP_CMP_STATUS_CMP0_MASK) { /* CMP0 event has occurred */
            pIepHwRegs->CMP_STATUS_REG = IEP_CMP_STATUS_CMP0_12_MASK;   /* clear CMP0-12 events */
#ifdef TX_HOST_INT
            if (txHostEvt == TRUE) {
                __R31 = 16 + TRIGGER_HOST_EVT; /* trigger Host interrupt on IEP CMP0 event */
            }
#endif
            
            /* Initialize IEP PWM CMPx Shadow Registers */
            status = initIepPwmCmpxShReg(pIcssgIepPwmObj);
            
            if (status == IEP_STS_NERR) {
                /* Update State to Left-Hand Side */
                pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_LHS;
            }
            else {
                /* Update state to Left-Hand Side (Host) Reconfiguration */
                pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_LHS_RECFG;
            }
        }
    }
    if (pIcssgIepPwmObj->iepPwmState == IEP_SM_STATE_LHS) {
        if ((cmpStatus & IEP_CMP_STATUS_CMP0_MASK) == IEP_CMP_STATUS_CMP0_MASK) { /* CMP0 event has occurred */
            pIepHwRegs->CMP_STATUS_REG = IEP_CMP_STATUS_CMP0_12_MASK;   /* clear CMP0-12 events */
#ifdef TX_HOST_INT
            if (txHostEvt == TRUE) {
                __R31 = 16 + TRIGGER_HOST_EVT; /* trigger Host interrupt on IEP CMP0 event */
            }
#endif
            /* Perform LHS processing */
            iepPwmLhs(pIcssgIepPwmObj);
            
            /* Update state to Left-Hand Side (Host) Reconfiguration */
            pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_LHS_RECFG;
        }
    }
    else if (pIcssgIepPwmObj->iepPwmState == IEP_SM_STATE_RHS) {
        if ((cmpStatus & IEP_CMP_STATUS_CMP0_MASK) == IEP_CMP_STATUS_CMP0_MASK) { /* CMP0 event has occurred */
            pIepHwRegs->CMP_STATUS_REG = IEP_CMP_STATUS_CMP0_12_MASK;   /* clear CMP0-12 events */
#ifdef TX_HOST_INT
            if (txHostEvt == TRUE) {
                __R31 = 16 + TRIGGER_HOST_EVT; /* trigger Host interrupt on IEP CMP0 event */
            }
#endif

            /* Perform RHS processing */
            iepPwmRhs(pIcssgIepPwmObj);
            
            /* Update state to Right-Hand Side Reconfiguration */
            pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_RHS_RECFG;
        }
    }
    else if (pIcssgIepPwmObj->iepPwmState == IEP_SM_STATE_LHS_RECFG) {
        /* Perform PWM reconfiguration, if requested by Host.
           Reconfiguration can only occur at start of PWM cycle after LHS.
           Reconfiguration actions:
            - PRU FW updates internal state using information in Host I/F FW Regs corresponding to RECFG bit mask.
            - PRU FW performs required writes to HW registers.
        */
        
        /* Perform LHS reconfiguration */
        status = iepPwmConfigLhs(pIcssgIepPwmObj);
        
        if (status < 0) {
            /* Update state to Left-Hand Side (Host) Reconfiguration */
            pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_LHS_RECFG;                
        }
        else if (status == IEP_STS_NERR) {
            /* Update state to Right-Hand Side */
            pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_RHS;
        }
        else { /* IEP_STS_RECFG_PRD_COUNT */
            /* Update State to Init */
            pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_INIT;
        }
    }
    else if (pIcssgIepPwmObj->iepPwmState == IEP_SM_STATE_RHS_RECFG) {
        /* Perform PWM RHS reconfiguration, if required by pending Host reconfiguration request.
           Reconfiguration can only occur in middle of PWM cycle before RHS.
           Reconfiguration actions:
            - PRU FW updates internal state.
            - PRU FW performs required writes to HW registers.
        */
        
        /* Perform RHS reconfiguration */
        status = iepPwmConfigRhs(pIcssgIepPwmObj);
        
        if (status == IEP_STS_NERR) {
            /* Update State to Left-Hand Side */
            pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_LHS;
        }
        else {
            /* Update state to Left-Hand Side (Host) Reconfiguration */
            pIcssgIepPwmObj->iepPwmState = IEP_SM_STATE_LHS_RECFG;
        }
    }
    
    return status;
}


/* ------------------------------------------------------------------------- *
 * Private Functions                                                         *
 * ------------------------------------------------------------------------- */

/* State Machine function, perform LHS processing */
static void iepPwmLhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    Uint32 *pIepPwmDcCount;
    Uint16 *pIepPwmDbCount;
    volatile uint32_t *pShadowReg;
    Uint8 pwmIdx, dPwmIdx;
    
    /* Process Left-Hand Side CMP Shadow Registers */
    
    /* Process Single-Ended PWMs */
    pIepPwmDcCount = &pIcssgIepPwmObj->iepPwmDcCountLhs[0];     /* init pointer to PWM Duty Cycle Count */
    for (pwmIdx = 0; pwmIdx < IEP_MAX_NUM_SNGL_PWM; pwmIdx++)
    {
        if (((pIcssgIepPwmObj->iepPwmSnglUpdEn >> pwmIdx) & 0x1) == 1) { /* check PWM update enabled */
            /* Write to CMP SR for PWM */
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx]; /* set pointer to CMP Shadow Register */
            *pShadowReg = pIcssgIepPwmObj->iepPwmPeriodCount - *pIepPwmDcCount;
        }
        pIepPwmDcCount++;
    }
    
    /* Process Differential PWMs */
    pIepPwmDcCount = &pIcssgIepPwmObj->iepPwmDcCountLhs[0];     /* init pointer to PWM Duty Cycle Count */
    pIepPwmDbCount = &pIcssgIepPwmObj->iepPwmDbCount[0];        /* init pointer to PWM Deadband Count */
    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        if (((pIcssgIepPwmObj->iepPwmDiffUpdEn >> dPwmIdx) & 0x1) == 1) { /* check PWM update enabled */
            /* Write CMP SR for POS PWM */
            pwmIdx = dPwmIdx << 1;
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx];     /* set pointer to CMP Shadow Register */
            *pShadowReg = pIcssgIepPwmObj->iepPwmPeriodCount - *pIepPwmDcCount;
            /* Write CMP SR for NEG PWM.
               Increment CMP SR pointer by 2 since CMP registers are 64 bit. */
            pwmIdx++;
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx];     /* set pointer to CMP Shadow Register */
            *pShadowReg = pIcssgIepPwmObj->iepPwmPeriodCount - *pIepPwmDcCount - *pIepPwmDbCount;
        }
        pIepPwmDcCount += 2;    /* differential pair use same Duty Cycle Count */
        pIepPwmDbCount++;
    }   
}

/* State Machine function, perform RHS processing */
static void iepPwmRhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    Uint32 *pIepPwmDcCount;
    Uint16 *pIepPwmDbCount;
    volatile uint32_t *pShadowReg;
    Uint8 pwmIdx, dPwmIdx;
    
    /* Process Right-Hand Side CMP Shadow Registers */
    
    /* Process Single-Ended PWMs */
    pIepPwmDcCount = &pIcssgIepPwmObj->iepPwmDcCountRhs[0];     /* init pointer to PWM Duty Cycle Count */
    for (pwmIdx = 0; pwmIdx < IEP_MAX_NUM_SNGL_PWM; pwmIdx++)
    {
        if (((pIcssgIepPwmObj->iepPwmSnglUpdEn >> pwmIdx) & 0x1) == 1) { /* check PWM update enabled */
            /* Write to CMP SR for PWM */
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx]; /* set pointer to CMP Shadow Register */
            *pShadowReg = *pIepPwmDcCount;
        }
        pIepPwmDcCount++;
        pShadowReg += 2;    /* CMP registers are 64 bit */
    }
    
    /* Process Differential PWMs */    
    pIepPwmDcCount = &pIcssgIepPwmObj->iepPwmDcCountRhs[0];     /* init pointer to PWM Duty Cycle Count */
    pIepPwmDbCount = &pIcssgIepPwmObj->iepPwmDbCount[0];        /* init pointer to PWM Deadband Count */
    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        if (((pIcssgIepPwmObj->iepPwmDiffUpdEn >> dPwmIdx) & 0x1) == 1) { /* check PWM update enabled */
            /* Write CMP SR for POS PWM */
            pwmIdx = dPwmIdx << 1;
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx]; /* set pointer to CMP Shadow Register */
            *pShadowReg = *pIepPwmDcCount;
            /* Write CMP SR for NEG PWM.
               Increment CMP SR pointer by 2 since CMP registers are 64 bit. */
            pwmIdx++;
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx]; /* set pointer to CMP Shadow Register */
            *pShadowReg = *pIepPwmDcCount + *pIepPwmDbCount;
        }
        pIepPwmDcCount += 2;    /* differential pair use same Duty Cycle Count */
        pIepPwmDbCount++;
    }
}

/* State Machine function, perform LHS reconfiguration.
 Check Host reconfiguration request.
 Perform Initialization reconfiguration. */
static Int32 iepPwmConfigLhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    CSL_icss_g_pr1_iep1_slvRegs *pIepHwRegs = pIcssgIepPwmObj->pIepHwRegs;
    Uint16 iepPwmSnglEn;
    Uint8 iepPwmDiffEn;
    Int32 status = IEP_STS_NERR;
    
    /* Check for Host reconfiguration request.
       Host reconfiguration isn't allowed during Initialization. */
       
    if (pIepPwmFwRegs->IEP_PWM_RECFG != 0) {
        /* Perform LHS Reconfiguration */
        
        if (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_PRD_COUNT_MASK) {
            /* PWM Period Count reconfiguration -- affects all PWM for IEP.
               Note: reconfiguration flag is cleared below because of 
               dependencies on other reconfigurations on Period Count 
               reconfiguration.
            */
            
            /* Update IEP PWM Period Count */
            updateIepPwmPeriodCount(pIcssgIepPwmObj);

            /* Reset IEP0 CMPx.
                - Set CMPx inside CMP0 period for 1/6 of PWMs in each Set. This forces PWM Set Initial->Active State.
                - Set CMPx outside CMP0 period for other 5/6 PWMs in each Set. */
            resetIepPwmCmpx(pIcssgIepPwmObj);
            
            /* Re-initialize PWMs. 
               Place PWMs in Init State. */
            reinitPwm(pIcssgIepPwmObj);
            
            if (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK) {
                
                /* Latch IEP PWM Enable */
                latchIepPwmEn(pIcssgIepPwmObj);
                
                /* Calculate & Latch Single-Ended and Differential PWM Enable */
                calcIepPwmSnglDiffEn(pIcssgIepPwmObj, &iepPwmSnglEn, &iepPwmDiffEn);
                latchIepPwmSnglDiffEn(pIcssgIepPwmObj, iepPwmSnglEn, iepPwmDiffEn);
                
                pIepPwmFwRegs->IEP_PWM_RECFG &= ~IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK;                    
            }
            
            if (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK) {
                /* Latch IEP PWM Duty Cycle Counts */
                latchIepPwmDcCounts(pIcssgIepPwmObj, TRUE);

                /* Calculate & Latch LHS/RHS Duty Cycle Counts */
                calcAndLatchIepPwmDcLhsRhsCount(pIcssgIepPwmObj, FALSE);
                
                pIepPwmFwRegs->IEP_PWM_RECFG &= ~IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK;
            }
            
            /* Set return status so State Machine executes INIT state */
            status = IEP_STS_RECFG_PRD_COUNT;
        }
        else {
            /* Enable/Disable & DC Count reconfiguration.
               Enable and DC Count reconfiguration must be handled jointly.
             
               Skip this reconfiguration if Period Count reconfigured
               since all CMPx already updated as part of Period Count reconfiguration. 
            */
            if (pIepPwmFwRegs->IEP_PWM_RECFG & (IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK | IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK)) {
                /* PWM Enable and Duty Cycle Count reconfiguration.
                   Update IEP PWM CMPx Shadow Registers. */
                updateIepPwmCmpxShRegPwmEnDc(pIcssgIepPwmObj);
                
                if (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK) {
                    pIepPwmFwRegs->IEP_PWM_RECFG &= ~IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK;
                }
                if (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK) {
                    pIepPwmFwRegs->IEP_PWM_RECFG &= ~IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK;
                }
            }
        }
        
        if (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_MASK) {
            /* PWM Deadband Count reconfiguration.           
               Update IEP PWM CMPx Shadow Registers. */
            updateIepPwmCmpxShRegDb(pIcssgIepPwmObj);
            
            pIepPwmFwRegs->IEP_PWM_RECFG &= ~IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_MASK;
        }

        if (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_PRD_COUNT_MASK) {
            /* Latch Period */
            latchIepPwmPeriodCount(pIcssgIepPwmObj);
            /* Enable IEP0 Counter */
            pIepHwRegs->GLOBAL_CFG_REG |= 0x1;
            
            pIepPwmFwRegs->IEP_PWM_RECFG &= ~IEP_PWM_RECFG_RECFG_IEP_PWM_PRD_COUNT_MASK;                
        }
    }
    
    return status;
}

/* State Machine Function, perform RHS reconfiguration.
 Apply pending Host reconfiguration request.
 Perform Initialization reconfiguration. 
    
 IEP PWM object has private information required to perform RHS update.
 This information is set appropriately in LHS (Host) Reconfiguration. */
static Int32 iepPwmConfigRhs(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    Int32 status = IEP_STS_NERR;
    
    if (pIcssgIepPwmObj->iepPwmRhsRecfgFlag == TRUE) {
        /* Perform RHS Reconfiguration for pending Host reconfiguration */
        execRhsActionStash(pIcssgIepPwmObj);
        
        pIcssgIepPwmObj->iepPwmRhsRecfgFlag = FALSE;
    }
    
    return status;
}

/* Latch IEP PWM mode.
   IEP PWM mode can't change after Initialization. */
static void latchIepPwmMode(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    pIcssgIepPwmObj->iepPwmMode = pIepPwmFwRegs->IEP_PWM_MODE;
}

/* Update IEP Period Count */
static void updateIepPwmPeriodCount(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    CSL_icss_g_pr1_iep1_slvRegs *pIepHwRegs = pIcssgIepPwmObj->pIepHwRegs;

    /* Disable IEP Counter */
    pIepHwRegs->GLOBAL_CFG_REG &= ~(0x1);
    //HW_WR_FIELD32(pIepHwRegs->GLOBAL_CFG_REG, CSL_ICSS_G_PR1_IEP1_SLV_GLOBAL_CFG_REG_CNT_ENABLE, ~(0x1)); // *** CSL call

    /* Set Counter value to 1 */
    pIepHwRegs->COUNT_REG0 = 0x1;
    pIepHwRegs->COUNT_REG1 = 0;
    //HW_WR_REG32(pIepHwRegs->COUNT_REG0, 0x1); // *** CSL call
    //HW_WR_REG32(pIepHwRegs->COUNT_REG1, 0x0); // *** CSL call

    /* Clear shadow mode in order to be able to write to the Active registers */
    pIepHwRegs->CMP_CFG_REG &= ~(0x1 << CSL_ICSS_G_PR1_IEP1_SLV_CMP_CFG_REG_SHADOW_EN_SHIFT);
        
    /* Load the Period Shadow/Active registers */
    pIepHwRegs->CMP0_REG0 = pIepPwmFwRegs->IEP_PWM_PRD_COUNT - DEF_COUNT_INC_PER_CLK;
    pIepHwRegs->CMP0_REG1 = pIepPwmFwRegs->IEP_PWM_PRD_COUNT - DEF_COUNT_INC_PER_CLK;

    /* Enable Shadow Mode */
    pIepHwRegs->CMP_CFG_REG |= (0x1 << CSL_ICSS_G_PR1_IEP1_SLV_CMP_CFG_REG_SHADOW_EN_SHIFT);
    
    /* Clear CMP0 Compare Events */
    pIepHwRegs->CMP_STATUS_REG = 0x1;

    /* Enable Counter Reset on CMP0 event */
    /* Enable CMP0 Compare Events */
    pIepHwRegs->CMP_CFG_REG |= (0x1 << CSL_ICSS_G_PR1_IEP1_SLV_CMP_CFG_REG_CMP0_RST_CNT_EN_SHIFT
        | (0x1 << CSL_ICSS_G_PR1_IEP1_SLV_CMP_CFG_REG_CMP_EN_SHIFT));
}

/* Reset IEP CMPx.
    - Set CMPx inside CMP0 period for 1/6 of PWMs in each Set. This forces PWM Set Initial->Active State.
    - Set CMPx outside CMP0 period for other 5/6 PWMs in each Set. */
static void resetIepPwmCmpx(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    CSL_icss_g_pr1_iep1_slvRegs *pIepHwRegs = pIcssgIepPwmObj->pIepHwRegs;
    volatile Uint32 *pIepCmpReg;
    Uint8 pwmIdx;
    
    /* Clear shadow mode in order to be able to write to the Active registers */
    pIepHwRegs->CMP_CFG_REG &= ~(0x1 << CSL_ICSS_G_PR1_IEP1_SLV_CMP_CFG_REG_SHADOW_EN_SHIFT);
   
    /* Set 0 PWMs */
    pIepCmpReg = &pIepHwRegs->CMP1_REG0;
    for (pwmIdx = 0; pwmIdx < SNGL_PWM_PER_SET; pwmIdx++)
    {
        *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT+5;   /* outside period */
        pIepCmpReg++;
        *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT+5;   /* outside period */
        pIepCmpReg++;
    }
    pIepCmpReg = &pIepHwRegs->CMP1_REG0 + (SACR_PWM_IDX << 1);
    *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT/2;   /* inside period for "sacrificial" toggle */
    pIepCmpReg++;
    *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT/2;   /* inside period for "sacrificial" toggle */
        
    /* Set 1 PWMs */
    pIepHwRegs->CMP7_REG0 = pIepPwmFwRegs->IEP_PWM_PRD_COUNT+5; /* inside period for "sacrificial" toggle */
    pIepHwRegs->CMP7_REG1 = pIepPwmFwRegs->IEP_PWM_PRD_COUNT+5; /* inside period for "sacrificial" toggle */
    pIepCmpReg = &pIepHwRegs->CMP8_REG0;
    for (pwmIdx = 1; pwmIdx < SNGL_PWM_PER_SET; pwmIdx++)
    {
        *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT+5;      /* outside period */
        pIepCmpReg++;
        *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT+5;      /* outside period */
        pIepCmpReg++;
    }
    if (SACR_PWM_IDX != 0) {
        pIepCmpReg = &pIepHwRegs->CMP8_REG0 + ((SACR_PWM_IDX-1) << 1);
    }
    else {
        pIepCmpReg = &pIepHwRegs->CMP7_REG0;
    }
    *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT/2;   /* inside period for "sacrificial" toggle */
    pIepCmpReg++;
    *pIepCmpReg = pIepPwmFwRegs->IEP_PWM_PRD_COUNT/2;   /* inside period for "sacrificial" toggle */

    /* Enable Shadow Mode */
    pIepHwRegs->CMP_CFG_REG |= (0x1 << CSL_ICSS_G_PR1_IEP1_SLV_CMP_CFG_REG_SHADOW_EN_SHIFT);
    
    /* Clear CMP1-12 Compare Events */
    pIepHwRegs->CMP_STATUS_REG = 0x1FFE;
    
    /* Enable CMP1-12 Compare Events */
    pIepHwRegs->CMP_CFG_REG |= (0x1FFE << 1);
    
    /* Reset Single-Ended and Differential PWM Update Enable */
    pIcssgIepPwmObj->iepPwmDiffUpdEn = 0;
    pIcssgIepPwmObj->iepPwmSnglUpdEn = 0;    
}

/* Initialize PWMs */
static void initPwm(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmTripHwRegs *pIepPwmTripHwRegs = pIcssgIepPwmObj->pIepPwmTripHwRegs;
    IepPwmStateCfgHwRegs *pPwmStateCfgHwRegs = pIcssgIepPwmObj->pPwmStateCfgHwRegs;
    volatile Uint32 *pPwmStateCfgReg;
    Uint8 i, j, dPwmIdx;
    Uint8 offset, regOffset;
    Uint32 pwmStateCfgReg;
    
    /* Default state */
    pIepPwmTripHwRegs->ICSSG_PWM0 = 0;  /* PWM 0-5 */
    pIepPwmTripHwRegs->ICSSG_PWM1 = 0;  /* PWM 6-11 */

    /* Configure PWM (Active, Trip, Init) State.
        - ICSSG_PWM0_0,1,2
        - ICSSG_PWM1_0,1,2 */
    pPwmStateCfgReg = &pPwmStateCfgHwRegs->ICSSG_PWM0_0;
    for (i = 0; i < IEP_NUM_PWM_SET; i++)
    {
        dPwmIdx = i * DIFF_PWM_PER_SET;
        for (j = 0; j < DIFF_PWM_PER_SET; j++)
        {
            if ((pIcssgIepPwmObj->iepPwmMode >> (dPwmIdx+j)) & 0x1) {
                /* Differential PWMs */
                *pPwmStateCfgReg = DIFF_PWM_STATE_INIT;
            }
            else {
                /* Single-Ended PWMs */
                *pPwmStateCfgReg = SNGL_PWM_STATE_INIT;
            }
            pPwmStateCfgReg++;
        }
    }
    
    /*  Update PWM State configuration for "sacrificial" PWMs.
     *  Index of sacrificial PWM is the same for both PWM Sets. 
     *  Sacrificial PWM initial state is normal PWM state inverted.
     *
     *  Index Sacrificial PWM   PWM State Config Reg    Bits in Config Reg  Bits to Write, SE PWM   Bits to Write, Diff PWM
     *  0                       0                       0-1                 10b (INIT HI)           10b (INIT HI)  
     *  1                       0                       2-3                 10b (INIT HI)           01b (INIT LO)
     *  2                       1                       0-1                 10b (INIT HI)           10b (INIT HI) 
     *  3                       1                       2-3                 10b (INIT HI)           01b (INIT LO)
     *  4                       2                       0-1                 10b (INIT HI)           10b (INIT HI) 
     *  5                       2                       2-3                 10b (INIT HI)           01b (INIT LO)
     */
    /* Set 0 */
    dPwmIdx = SACR_PWM_IDX/2;
    offset = SACR_PWM_IDX & 0x1;
    regOffset = offset << 1;
    pPwmStateCfgReg = &pPwmStateCfgHwRegs->ICSSG_PWM0_0 + dPwmIdx;
    pwmStateCfgReg = *pPwmStateCfgReg;
    pwmStateCfgReg &= ~(0x3 << regOffset);
    if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
        /* Differential PWM */
        if (offset & 0x1) {
            pwmStateCfgReg |= (PWM_INIT_LO << regOffset);
        }
        else {
            pwmStateCfgReg |= (PWM_INIT_HI << regOffset);
        }
    }
    else {
        /* Single-Ended PWM */
        pwmStateCfgReg |= (PWM_INIT_HI << regOffset);
    }
    *pPwmStateCfgReg = pwmStateCfgReg; /* write config */
    /* Set 1 */    
    dPwmIdx = DIFF_PWM_PER_SET + SACR_PWM_IDX/2;
    offset = SACR_PWM_IDX & 0x1;
    regOffset = offset << 1;
    pPwmStateCfgReg = &pPwmStateCfgHwRegs->ICSSG_PWM0_0 + dPwmIdx;
    pwmStateCfgReg = *pPwmStateCfgReg;
    pwmStateCfgReg &= ~(0x3 << regOffset);
    if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
        /* Differential PWM */
        if (offset & 0x1) {
            pwmStateCfgReg |= (PWM_INIT_LO << regOffset);
        }
        else {
            pwmStateCfgReg |= (PWM_INIT_HI << regOffset);
        }
    }
    else {
        /* Single-Ended PWM */
        pwmStateCfgReg |= (PWM_INIT_HI << regOffset);
    }
    *pPwmStateCfgReg = pwmStateCfgReg; /* write config */

    /* Create a trip reset event to put all signals into the Init state */
    pIepPwmTripHwRegs->ICSSG_PWM0 = PWM_TRIP_RESET_MASK;    /* PWM 0-5 */
    pIepPwmTripHwRegs->ICSSG_PWM1 = PWM_TRIP_RESET_MASK;    /* PWM 6-11 */
    /* Clear the trip event to allow signals to leave the init state (when a CMP occurs) */
    pIepPwmTripHwRegs->ICSSG_PWM0 = 0;                      /* PWM 0-5 */
    pIepPwmTripHwRegs->ICSSG_PWM1 = 0;                      /* PWM 6-11 */
}

/* Reinitialize PWMs */
static void reinitPwm(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmTripHwRegs *pIepPwmTripHwRegs = pIcssgIepPwmObj->pIepPwmTripHwRegs;

    /* Create a trip reset event to put all signals into the Init state */
    pIepPwmTripHwRegs->ICSSG_PWM0 = PWM_TRIP_RESET_MASK;    /* PWM 0-5 */
    pIepPwmTripHwRegs->ICSSG_PWM1 = PWM_TRIP_RESET_MASK;    /* PWM 6-11 */
    /* Clear the trip event to allow signals to leave the init state (when a CMP occurs) */
    pIepPwmTripHwRegs->ICSSG_PWM0 = 0;                      /* PWM 0-5 */
    pIepPwmTripHwRegs->ICSSG_PWM1 = 0;                      /* PWM 6-11 */
}

/* Latch IEP PWM Enable */
static void latchIepPwmEn(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    pIcssgIepPwmObj->iepPwmEn = pIepPwmFwRegs->IEP_PWM_EN;
}

/* Latch IEP PWM Period Count */
static void latchIepPwmPeriodCount(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    pIcssgIepPwmObj->iepPwmPeriodCount = pIepPwmFwRegs->IEP_PWM_PRD_COUNT;
}

/* Latch IEP PWM Duty Cycle Counts */
static void latchIepPwmDcCounts(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool recfgFlag
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    volatile Uint32 *pIepPwmDcCount;
    Uint16 recfgDcCount;
    Uint8 dPwmIdx, pwmIdx;
    
    if (recfgFlag == TRUE) {
        /* Get Duty Cycle reconfiguration */
        recfgDcCount = (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK) >> IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_SHIFT;
    }
    else {
        /* Set Duty Cycle reconfiguration reconfiguration to full mask */
        recfgDcCount = IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK >> IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_SHIFT;
    }
    
    /* Compute LHS/RHS Duty Cycle counts */
    pIepPwmDcCount = &pIepPwmFwRegs->IEP_PWM0_DC_COUNT; /* Init pointer to IEP PWM Duty Cycle Count */
    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        pwmIdx = dPwmIdx << 1;
        if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
            /* Differential PWM */
            
            /* Check if reconfiguration bit set.
               For Differential PWM, only "even" reconfiguration bits checked for each PWM pair. */
            if ((recfgDcCount >> pwmIdx) & 0x1) {
                /* LHS 2*i, POS/NEG */
                pIcssgIepPwmObj->iepPwmDcCount[pwmIdx] = *pIepPwmDcCount;
            }
        }
        else {
            /* Single-Ended PWM */
            
            /* Check if reconfiguration bit set.
               For Single-Ended PWM, all reconfiguration bits checked. */
            if ((recfgDcCount >> pwmIdx) & 0x1) {
                /* LHS 2*i, POS */
                pIcssgIepPwmObj->iepPwmDcCount[pwmIdx] = *pIepPwmDcCount;
            }
            if ((recfgDcCount >> (pwmIdx+1)) & 0x1) {
                /* LHS 2*i+1, NEG */
                pIcssgIepPwmObj->iepPwmDcCount[pwmIdx+1] = *(pIepPwmDcCount+1);
            }
        }
        
        pIepPwmDcCount += 2; /* update pointer to IEP PWM Duty Cycle Count */
    }
}

/* Latch IEP PWM Deadband Counts */
static void latchIepPwmDbCount(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool recfgFlag
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    volatile Uint16 *pIepPwmDbCount;
    Uint8 dbCountRecfg;
    Uint8 dPwmIdx;

    if (recfgFlag == TRUE) {
        /* Get Deadband reconfiguration register */
        dbCountRecfg = (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_MASK) >> IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_SHIFT;
    }
    else {
        /* Set Deadband reconfiguration register to full mask */
        dbCountRecfg = IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_MASK >> IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_SHIFT;
    }
    
    pIepPwmDbCount = &pIepPwmFwRegs->IEP_PWM0_1_DB_COUNT; /* init pointer to IEP PWM Deadband Count */
    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        if ( (dbCountRecfg >> dPwmIdx) & 0x1 ) {
            /* Latch updated PWM Deadband Count IEP PWM object */
            pIcssgIepPwmObj->iepPwmDbCount[dPwmIdx] = *pIepPwmDbCount;
        }
        pIepPwmDbCount++;
    }
}

/* Calculate IEP PWM Single-Ended and Differential Enable */ 
static void calcIepPwmSnglDiffEn(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Uint16 *pIepPwmSnglEn, 
    Uint8 *pIepPwmDiffEn
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    Uint16 iepPwmSnglEn;
    Uint8 iepPwmDiffEn;
    Uint8 dPwmIdx, pwmIdx;
    
    iepPwmSnglEn = 0;
    iepPwmDiffEn = 0;
    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        pwmIdx = dPwmIdx << 1;
        if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
            /* Differential PWM */
            if ((pIepPwmFwRegs->IEP_PWM_EN >> pwmIdx) & 0x1) {
                /* Differential PWM enabled */
                iepPwmDiffEn |= 1 << dPwmIdx;
            }
        }
        else {
            /* Single-Ended PWM */
            if ((pIepPwmFwRegs->IEP_PWM_EN >> pwmIdx) & 0x1) {
                /* Single-Ended PWM enabled */
                iepPwmSnglEn |= 1 << pwmIdx;
            }
            if ((pIepPwmFwRegs->IEP_PWM_EN >> (pwmIdx+1)) & 0x1) {
                /* Single-Ended PWM enabled */
                iepPwmSnglEn |= 1 << (pwmIdx+1);
            }
        }
    }

    *pIepPwmSnglEn = iepPwmSnglEn;
    *pIepPwmDiffEn = iepPwmDiffEn;
}

/* Latch IEP PWM Single-Ended and Differential Enable */
static void latchIepPwmSnglDiffEn(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Uint16 iepPwmSnglEn,
    Uint8 iepPwmDiffEn
)
{
    pIcssgIepPwmObj->iepPwmSnglEn = iepPwmSnglEn;
    pIcssgIepPwmObj->iepPwmDiffEn = iepPwmDiffEn;
}

/* Calculate & Latch IEP PWM LHS/RHS Duty Cycle Counts */
static Int32 calcAndLatchIepPwmDcLhsRhsCount(
    IcssgIepPwmObj *pIcssgIepPwmObj, 
    Bool recfgFlag
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    Uint16 recfgDcCount; 
    Uint32 pwmPeriodCount;
    volatile Uint32 *pIepPwmDcCount;
    Uint8 dPwmIdx, pwmIdx;
    Uint32 dcCount, temp;
    Int32 status = IEP_STS_NERR;
    
    
    if (recfgFlag == TRUE) {
        /* Get Duty Cycle reconfiguration */
        recfgDcCount = (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK) >> IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_SHIFT;
    }
    else {
        /* Set Duty Cycle reconfiguration to full mask */
        recfgDcCount = IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK >> IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_SHIFT;    
    }
    
    /* Calculate PWM period.
       PWM period is 2 IEP CMP0 periods. */
    pwmPeriodCount = pIcssgIepPwmObj->iepPwmPeriodCount << 1;
    
    /* Compute LHS/RHS Duty Cycle counts */
    pIepPwmDcCount = &pIepPwmFwRegs->IEP_PWM0_DC_COUNT;   /* Init pointer to IEP PWM Duty Cycle Count */
    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        pwmIdx = dPwmIdx << 1;
        if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
            /* Differential PWM */
            
            /* Check if reconfiguration bit set.
               For Differential PWM, only "even" reconfiguration bits checked for each PWM pair. */
            if ((recfgDcCount >> pwmIdx) & 0x1) {
                dcCount = *pIepPwmDcCount;
                if ((dcCount > 0) && (dcCount < pwmPeriodCount)) {
                    /* Calculate and latch DC count LHS/RHS */
                    temp = COUNT_TO_CLK(dcCount)/2;
                    temp = CLK_TO_COUNT(temp);
                    pIcssgIepPwmObj->iepPwmDcCountLhs[pwmIdx] = temp;   /* LHS 2*i, POS/NEG */
                    pIcssgIepPwmObj->iepPwmDcCountRhs[pwmIdx] = temp;   /* LHS 2*i, POS/NEG */
                    if ((COUNT_TO_CLK(dcCount) & 0x1) == 1) {
                        pIcssgIepPwmObj->iepPwmDcCountRhs[pwmIdx] += DEF_COUNT_INC_PER_CLK; /* RHS 2*i, POS/NEG */
                    }
                }
                else if ((dcCount == 0) || (dcCount == pwmPeriodCount)) {
                    /* No LHS/RHS in case DC count 0 or 100 */
                    ;
                }
                else {
                    /* error, invalid DC count */
                    status = IPE_STS_ERR_INV_DC_COUNT;
                }
            }
        }
        else {
            /* Single-Ended PWM */
            
            /* Check if reconfiguration bit set.
               For Single-Ended PWM, all reconfiguration bits checked. */
            if ((recfgDcCount >> pwmIdx) & 0x1) {
                dcCount = *pIepPwmDcCount;
                if ((dcCount > 0) && (dcCount < pwmPeriodCount)) {
                    temp = COUNT_TO_CLK(dcCount)/2;
                    temp = CLK_TO_COUNT(temp);
                    pIcssgIepPwmObj->iepPwmDcCountLhs[pwmIdx] = temp;   /* LHS 2*i, POS */
                    pIcssgIepPwmObj->iepPwmDcCountRhs[pwmIdx] = temp;   /* RHS 2*i, POS */
                    if ((COUNT_TO_CLK(dcCount) & 0x1) == 1) {
                        pIcssgIepPwmObj->iepPwmDcCountRhs[pwmIdx] += DEF_COUNT_INC_PER_CLK; /* RHS 2*i, POS */
                    }
                }
                else if ((dcCount == 0) || (dcCount == pwmPeriodCount)) {
                    /* No LHS/RHS in case DC count 0 or 100 */
                    ;
                }
                else {
                    /* error, invalid DC count */
                    status = IPE_STS_ERR_INV_DC_COUNT;
                }
            }
            if ((recfgDcCount >> (pwmIdx+1)) & 0x1) {
                dcCount = *(pIepPwmDcCount+1);
                if ((dcCount > 0) && (dcCount < pwmPeriodCount)) {
                    temp = COUNT_TO_CLK(dcCount)/2;
                    temp = CLK_TO_COUNT(temp);
                    pIcssgIepPwmObj->iepPwmDcCountLhs[pwmIdx+1] = temp;    /* LHS 2*i+1, NEG */
                    pIcssgIepPwmObj->iepPwmDcCountRhs[pwmIdx+1] = temp;    /* RHS 2*i+1, NEG */
                    if ((COUNT_TO_CLK(dcCount) & 0x1) == 1) {
                        pIcssgIepPwmObj->iepPwmDcCountRhs[pwmIdx+1] += DEF_COUNT_INC_PER_CLK;  /* RHS 2*i+1, NEG */
                    }
                }
                else if ((dcCount == 0) || (dcCount == pwmPeriodCount)) {
                    /* No LHS/RHS in case DC count 0 or 100 */
                    ;
                }
                else {
                    /* error, invalid DC count */
                    status = IPE_STS_ERR_INV_DC_COUNT;
                }
            }
        }
            
        pIepPwmDcCount += 2;
    }
    
    return status;
}

/* Initialize IEP PWM CMPx Shadow Registers */
static Int32 initIepPwmCmpxShReg(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    Uint32 *pIepPwmDcCount;
    Uint32 *pIepPwmDcCountLhs;
    IepPwmRhsAction *pIepPwmRhsAction;
    Bool *pIepPwmRhsRecfgFlag;
    Uint32 iepPwmPeriodCount, pwmPeriodCount;
    Uint16 *pIepPwmSnglUpdEn;
    Uint8 *pIepPwmDiffUpdEn;
    volatile uint32_t **pIepCmpSrAddr;
    IepPwmLhsAction actionLhs;
    IepPwmRhsAction actionRhs;
    Uint8 dPwmIdx, pwmIdx;
    Bool pwmEn;
    
    /* Get latched IEP PWM DC count array */
    pIepPwmDcCount = &pIcssgIepPwmObj->iepPwmDcCount[0];
    /* Get latched IEP PWM DC LHS count array */
    pIepPwmDcCountLhs = &pIcssgIepPwmObj->iepPwmDcCountLhs[0];
    /* Get RHS action array */
    pIepPwmRhsAction = &pIcssgIepPwmObj->iepPwmRhsAction[0];
    /* Get pointer to RHS reconfiguration flag */
    pIepPwmRhsRecfgFlag = &pIcssgIepPwmObj->iepPwmRhsRecfgFlag;
    /* Get Single-Ended & Differential PWM Update Enable */
    pIepPwmSnglUpdEn = &pIcssgIepPwmObj->iepPwmSnglUpdEn;
    pIepPwmDiffUpdEn = &pIcssgIepPwmObj->iepPwmDiffUpdEn;
    /* Get IEP CMP Shadow Registers array */
    pIepCmpSrAddr = &pIcssgIepPwmObj->iepCmpSrAddr[0];
    
    /* Get IEP CMP0 period */
    iepPwmPeriodCount = pIcssgIepPwmObj->iepPwmPeriodCount;
    /* Calculate PWM period.
       PWM period is 2 IEP CMP0 periods. */
    pwmPeriodCount = iepPwmPeriodCount << 1;
    
    /* Initialize flag to disable execution of RHS Reconfiguration */
    *pIepPwmRhsRecfgFlag = FALSE;

    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
            /* Process Differential PWM */
            
            /* Get PWM enable */
            pwmEn = (Bool)((pIcssgIepPwmObj->iepPwmDiffEn >> dPwmIdx) & 0x1);
            
            pwmIdx = dPwmIdx << 1; /* multiply by 2 for differential PWM */
            
            /* Determine Initial LHS/RHS actions */
            getInitLhsAction(FALSE, pwmEn, pIepPwmDcCount[pwmIdx], pwmPeriodCount, 
                &actionLhs, &actionRhs);

            /* Execute LHS action */
            execInitLhsActionDiff(actionLhs, 
                iepPwmPeriodCount, 
                pIepPwmDcCountLhs[pwmIdx], 
                pIepCmpSrAddr, 
                pIepPwmDiffUpdEn,
                dPwmIdx);
            
            /* Stash RHS action */
            stashRhsAction(actionRhs, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
        }
        else {
            /* Process Single-Ended PWMs */
            
            for (pwmIdx = dPwmIdx<<1; pwmIdx < ((dPwmIdx<<1) + NUM_PWM_PER_DIFF_PWM); pwmIdx++)
            {
                /* Get PWM enable */
                pwmEn = (Bool)((pIcssgIepPwmObj->iepPwmSnglEn >> pwmIdx) & 0x1);
                    
                /* Determine Initial LHS/RHS actions */
                getInitLhsAction(FALSE, pwmEn, pIepPwmDcCount[pwmIdx], pwmPeriodCount, 
                    &actionLhs, &actionRhs);
                
                /* Execute LHS action */
                execInitLhsActionSngl(actionLhs, 
                    iepPwmPeriodCount, 
                    pIepPwmDcCountLhs[pwmIdx], 
                    pIepCmpSrAddr, 
                    pIepPwmSnglUpdEn, 
                    pwmIdx);
                
                /* Stash RHS action */
                stashRhsAction(actionRhs, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
            }
        }
    }
    
    /* Process "sacrificial PWMs".
       Previously applied settings are overwritten for these PWMs. */           
    /* Determine Initial LHS/RHS actions */
    
    pwmIdx = SACR_PWM_IDX; /* "sacrificial" PWM index */
    /* Get PWM enable */    
    pwmEn = (Bool)((pIcssgIepPwmObj->iepPwmSnglEn >> pwmIdx) & 0x1);    
    getInitLhsAction(TRUE, pwmEn, pIepPwmDcCount[pwmIdx], pwmPeriodCount, 
        &actionLhs, &actionRhs);
    /* Execute LHS action */
    execInitLhsActionSngl(actionLhs, 
        iepPwmPeriodCount, 
        pIepPwmDcCountLhs[pwmIdx], 
        pIepCmpSrAddr, 
        pIepPwmSnglUpdEn, 
        pwmIdx);
    /* Stash RHS action */
    stashRhsAction(actionRhs, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
    
    pwmIdx = SNGL_PWM_PER_SET + SACR_PWM_IDX; /* "sacrificial" PWM index */
    /* Get PWM enable */
    pwmEn = (Bool)((pIcssgIepPwmObj->iepPwmSnglEn >> pwmIdx) & 0x1);    
    getInitLhsAction(TRUE, pwmEn, pIepPwmDcCount[pwmIdx], pwmPeriodCount, 
        &actionLhs, &actionRhs);
    /* Execute LHS action */
    execInitLhsActionSngl(actionLhs, 
        iepPwmPeriodCount, 
        pIepPwmDcCountLhs[pwmIdx], 
        pIepCmpSrAddr, 
        pIepPwmSnglUpdEn, 
        pwmIdx);
    /* Stash RHS action */
    stashRhsAction(actionRhs, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
    
    return IEP_STS_NERR;
}

/* Determine initial LHS/RHS actions */
static Int32 getInitLhsAction(
    Bool initToActPwm, 
    Bool pwmEn, 
    Uint32 iepPwmDcCount, 
    Uint32 pwmPeriodCount, 
    IepPwmLhsAction *pActionLhs, 
    IepPwmRhsAction *pActionRhs
)
{
    if (initToActPwm == FALSE) {
        /* Determine LHS/RHS actions for non "sacrificial" PWMs */
        
        if (pwmEn == TRUE) {
            if ((iepPwmDcCount > 0) && 
                (iepPwmDcCount < pwmPeriodCount)) {
                /* DC = x, x!=0, x!=100 */
                *pActionLhs = LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate;
                *pActionRhs = RHS_ACTION_None;
            }
            else if (iepPwmDcCount == 0) {
                /* DC count is 0 */
                *pActionLhs = LHS_ACTION_None;
                *pActionRhs = RHS_ACTION_None;
            }
            else if (iepPwmDcCount == pwmPeriodCount) {
                /* DC count is 100 */
                *pActionLhs = LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate;
                *pActionRhs = RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate;
            }
            else {
                /* Error, invalid DC count */
                
                /* PWM disabled in case of invalid DC count */
                *pActionLhs = LHS_ACTION_None;
                *pActionRhs = RHS_ACTION_None;
                /* Indicate error to caller */
                return IPE_STS_ERR_INV_DC_COUNT;
            }
        }
        else {
            /* PWM disabled, no action required */
            *pActionLhs = LHS_ACTION_None;
            *pActionRhs = RHS_ACTION_None;
        }
    }
    else {
        /* Determine LHS/RHS actions for "sacrificial" PWMs */
        
        if (pwmEn == TRUE) {
            if ((iepPwmDcCount > 0) && 
                (iepPwmDcCount < pwmPeriodCount)) {
                /* DC = x, x!=0, x!=100 */
                *pActionLhs = LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate;
                *pActionRhs = RHS_ACTION_None;
            }
            else if (iepPwmDcCount == 0) {
                /* DC count is 0 */
                *pActionLhs = LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate;
                *pActionRhs = RHS_ACTION_None;
            }
            else if (iepPwmDcCount == pwmPeriodCount) {
                /* DC count is 100 */
                *pActionLhs = LHS_ACTION_None;
                *pActionRhs = RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate;
            }
            else {
                /* Error, invalid DC count */
                
                /* PWM disabled in case of invalid DC count */
                *pActionLhs = LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate;
                *pActionRhs = RHS_ACTION_None;
                /* Indicate error to caller */
                return IPE_STS_ERR_INV_DC_COUNT;
            }            
        }
        else {
            /* PWM disabled */
            *pActionLhs = LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate;
            *pActionRhs = RHS_ACTION_None;
        }
    }
        
    return IEP_STS_NERR;
}

/* Initial update IEP PWM CMPx Shadow Register, Single-Ended Mode */
static void execInitLhsActionSngl(
    IepPwmLhsAction actionLhs, 
    Uint32 iepPwmPeriodCount, 
    Uint32 iepPwmDcCountLhs, 
    volatile uint32_t **pIepCmpSrAddr, 
    Uint16 *pIepPwmSnglUpdEn, 
    Uint8 pwmIdx
)
{
    volatile uint32_t *pCmpSr;
    
    pCmpSr = pIepCmpSrAddr[pwmIdx];
    
    switch (actionLhs)
    {
        case LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate:
            *pCmpSr = iepPwmPeriodCount - iepPwmDcCountLhs; /* Write LHS value to CMP Shadow Register */
            *pIepPwmSnglUpdEn |= 1<<pwmIdx;                 /* Enable CMP SR update */
            break;
            
        case LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate:
            *pCmpSr = CMP_SR_EARLY_VAL;                     /* Write LHS value to CMP Shadow Register */
            *pIepPwmSnglUpdEn |= 1<<pwmIdx;                 /* Enable CMP SR update */
            break;

        case LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate:
            *pCmpSr = iepPwmPeriodCount;                    /* Write LHS value to CMP Shadow Register */
            *pIepPwmSnglUpdEn &= ~(1<<pwmIdx);              /* Enable CMP SR update */
            break;
            
        case LHS_ACTION_None:
        case LHS_ACTION_Set_CmpSr_DcLhsY:
        case LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate:
        default:
            break;
    }
}

/* Initial update IEP PWM CMPx Shadow Registers, Differential Mode */
static void execInitLhsActionDiff(
    IepPwmLhsAction actionLhs, 
    Uint32 iepPwmPeriodCount, 
    Uint32 iepPwmDcCountLhs, 
    volatile uint32_t **pIepCmpSrAddr, 
    Uint8 *pIepPwmDiffUpdEn, 
    Uint8 dPwmIdx
)
{
    volatile uint32_t *pCmpSrPos, *pCmpSrNeg;
    Uint8 pwmIdx;
    Uint32 temp;
    
    pwmIdx = dPwmIdx << 1; /* multiply by 2 for differential PWM */
    pCmpSrPos = pIepCmpSrAddr[pwmIdx];
    pCmpSrNeg = pIepCmpSrAddr[pwmIdx+1];

    switch (actionLhs)
    {
        case LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate:
            temp = iepPwmPeriodCount - iepPwmDcCountLhs;        /* Compute LHS SR value */
            *pCmpSrPos = temp;                                  /* Write LHS value to CMP Shadow Register, POS */
            *pCmpSrNeg = temp;                                  /* Write LHS value to CMP Shadow Register, NEG */
            *pIepPwmDiffUpdEn |= 1<<dPwmIdx;                    /* Enable CMP SR update */
            break;
            
        case LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate:
            *pCmpSrPos = CMP_SR_EARLY_VAL;                      /* Write LHS value to CMP Shadow Register, POS */
            *pCmpSrNeg = CMP_SR_EARLY_VAL;                      /* Write LHS value to CMP Shadow Register, NEG */
            *pIepPwmDiffUpdEn |= 1<<dPwmIdx;                    /* Enable CMP SR update */
            break;
            
        case LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate:
            /* Write same LHS value to both CMP Shadow Registers in differential pair */
            *pCmpSrPos = iepPwmPeriodCount;                     /* Write LHS value to CMP Shadow Register, POS */
            *pCmpSrNeg = iepPwmPeriodCount;                     /* Write LHS value to CMP Shadow Register, NEG */
            /* Disable CMP SR update */
            *pIepPwmDiffUpdEn &= ~(1<<dPwmIdx);                 /* Disable CMP SR update */
            break;            
            
        case LHS_ACTION_None:
        case LHS_ACTION_Set_CmpSr_DcLhsY:
        case LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate:
        default:
            break;
    }
}

/* Update IEP PWM CMPx Shadow Registers.
   PWM Enable and DC Count reconfiguration handled jointly. */
static Int32 updateIepPwmCmpxShRegPwmEnDc(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    Uint16 recfgDcCount;
    volatile uint32_t *pIepPwmDcCountNew;
    Uint32 *pIepPwmDcCountOld, *pIepPwmDcCountLhsOld, *pIepPwmDcCountRhsOld;
    IepPwmRhsAction *pIepPwmRhsAction;
    Bool *pIepPwmRhsRecfgFlag;
    Uint16 *pIepPwmSnglUpdEn;
    Uint8 *pIepPwmDiffUpdEn;
    volatile uint32_t **pIepCmpSrAddr;
    Uint32 iepPwmPeriodCount, pwmPeriodCount;
    Uint8 pwmIdx, dPwmIdx;
    const IepPwmActionTableEntry *pTable;
    Uint8 rowIdx;
    Uint32 iepPwmDcCountLhsNew, iepPwmDcCountRhsNew;
    Uint16 iepPwmSnglEn;
    Uint8 iepPwmDiffEn;
    Int32 status = IEP_STS_NERR;
 
    /* Get Duty Cycle reconfiguration */
    recfgDcCount = (pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK) >> IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_SHIFT;
    /* Get input (new) IEP PWM DC count array */
    pIepPwmDcCountNew = &pIepPwmFwRegs->IEP_PWM0_DC_COUNT;
    /* Get latched (old) IEP PWM DC count array */
    pIepPwmDcCountOld = &pIcssgIepPwmObj->iepPwmDcCount[0];
    /* Get latched (old) IEP PWM DC LHS/RHS count arrays */
    pIepPwmDcCountLhsOld = &pIcssgIepPwmObj->iepPwmDcCountLhs[0];
    pIepPwmDcCountRhsOld = &pIcssgIepPwmObj->iepPwmDcCountRhs[0];
    /* Get RHS action array */
    pIepPwmRhsAction = &pIcssgIepPwmObj->iepPwmRhsAction[0];
    /* Get pointer to RHS reconfiguration flag */
    pIepPwmRhsRecfgFlag = &pIcssgIepPwmObj->iepPwmRhsRecfgFlag;
    /* Get Single-Ended & Differential PWM Update Enable */
    pIepPwmSnglUpdEn = &pIcssgIepPwmObj->iepPwmSnglUpdEn;
    pIepPwmDiffUpdEn = &pIcssgIepPwmObj->iepPwmDiffUpdEn;    
    /* Get IEP CMP Shadow Registers array */
    pIepCmpSrAddr = &pIcssgIepPwmObj->iepCmpSrAddr[0];
    
    /* Get IEP CMP0 period */
    iepPwmPeriodCount = pIcssgIepPwmObj->iepPwmPeriodCount;
    /* Calculate PWM period.
       PWM period is 2 IEP CMP0 periods. */
    pwmPeriodCount = pIcssgIepPwmObj->iepPwmPeriodCount << 1;

    /* Init flag to disable execution of RHS Reconfiguration */
    *pIepPwmRhsRecfgFlag = FALSE;

    if ((pIepPwmFwRegs->IEP_PWM_RECFG & IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK) == 0) {
        /* No change to PWM Enable */
        
        for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
        {
            if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
                /* Process Differential PWM */
                
                /* Select Action Table */
                if ((pIcssgIepPwmObj->iepPwmDiffEn >> dPwmIdx) & 0x1) {
                    /* No Enable Reconfiguration, PWM enabled */
                    pTable = gActT2_EnRecfgNo_EnOldEnable;
                }
                else {
                    /* No Enable Reconfiguration, PWM disabled */
                    pTable = gActT1_EnRecfgNo_EnOldDisable;
                }
                
                pwmIdx = dPwmIdx << 1; /* multiply by 2 for differential PWM */
                
                /* Determine Action Table Row */
                status = getActionTableRowDiff(recfgDcCount, dPwmIdx, 
                    pIepPwmDcCountOld[pwmIdx], pIepPwmDcCountNew[pwmIdx], 
                    pwmPeriodCount, &rowIdx);
                if (status != IEP_STS_NERR) {
                    return status;
                }
                
                /* Calculate new LHS/RHS */
                calcDcLatchAction(pTable[rowIdx].latchAction, 
                    pIepPwmDcCountNew[pwmIdx], 
                    &iepPwmDcCountLhsNew, 
                    &iepPwmDcCountRhsNew);
                
                /* Execute LHS action */
                execLhsActionDiff(pTable[rowIdx].lhsAction, 
                    pIepPwmDcCountLhsOld[pwmIdx], iepPwmDcCountLhsNew, 
                    pIepCmpSrAddr, 
                    pIepPwmDiffUpdEn,
                    dPwmIdx, 
                    iepPwmPeriodCount);
                
                /* Stash RHS action */
                stashRhsAction(pTable[rowIdx].rhsAction, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
                
                /* Execute DC latch */
                execDcLatchAction(pTable[rowIdx].latchAction, 
                    &pIepPwmDcCountOld[pwmIdx], &pIepPwmDcCountLhsOld[pwmIdx], &pIepPwmDcCountRhsOld[pwmIdx],
                    pIepPwmDcCountNew[pwmIdx], iepPwmDcCountLhsNew, iepPwmDcCountRhsNew);                
            }
            else {
                /* Process Single-Ended PWMs */
                
                for (pwmIdx = dPwmIdx<<1; pwmIdx < ((dPwmIdx<<1) + NUM_PWM_PER_DIFF_PWM); pwmIdx++)
                {
                    /* Select Action Table */
                    if ((pIcssgIepPwmObj->iepPwmSnglEn >> pwmIdx) & 0x1) {
                        /* No Enable Reconfiguration, PWM enabled */
                        pTable = gActT2_EnRecfgNo_EnOldEnable;
                    }
                    else {
                        /* No Enable Reconfiguration, PWM disabled */
                        pTable = gActT1_EnRecfgNo_EnOldDisable;
                    }
                    
                    /* Determine Action Table Row */
                    status = getActionTableRowSngl(recfgDcCount, pwmIdx, 
                        pIepPwmDcCountOld[pwmIdx], pIepPwmDcCountNew[pwmIdx], 
                        pwmPeriodCount, &rowIdx);
                    if (status != IEP_STS_NERR) {
                        return status;
                    }
                    
                    /* Calculate new LHS/RHS */
                    calcDcLatchAction(pTable[rowIdx].latchAction, 
                        pIepPwmDcCountNew[pwmIdx], 
                        &iepPwmDcCountLhsNew, 
                        &iepPwmDcCountRhsNew);
                    
                    /* Execute LHS action */
                    execLhsActionSngl(pTable[rowIdx].lhsAction, 
                        pIepPwmDcCountLhsOld[pwmIdx], iepPwmDcCountLhsNew, 
                        pIepCmpSrAddr, 
                        pIepPwmSnglUpdEn,
                        pwmIdx, 
                        iepPwmPeriodCount);
                    
                    /* Stash RHS action */
                    stashRhsAction(pTable[rowIdx].rhsAction, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
                    
                    /* Execute DC latch */
                    execDcLatchAction(pTable[rowIdx].latchAction, 
                        &pIepPwmDcCountOld[pwmIdx], &pIepPwmDcCountLhsOld[pwmIdx], &pIepPwmDcCountRhsOld[pwmIdx],
                        pIepPwmDcCountNew[pwmIdx], iepPwmDcCountLhsNew, iepPwmDcCountRhsNew);
                }
            }
        }
    }
    else {
        /* Change to PWM Enable */
    
        /* Calculate Single-Ended and Differential PWM Enable */
        calcIepPwmSnglDiffEn(pIcssgIepPwmObj, &iepPwmSnglEn, &iepPwmDiffEn);
        
        for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
        {
            if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
                /* Process Differential PWM */
                
                /* Select Action Table */
                if (!((pIcssgIepPwmObj->iepPwmDiffEn >> dPwmIdx) & 0x1) &&
                    ((iepPwmDiffEn >> dPwmIdx) & 0x1)) {
                    /* Enable Reconfiguration, PWM enabled */
                    pTable = gActT3_EnRecfgYes_EnNewEnable;
                }
                else if (((pIcssgIepPwmObj->iepPwmDiffEn >> dPwmIdx) & 0x1) &&
                    !((iepPwmDiffEn >> dPwmIdx) & 0x1)) {
                    /* Enable Reconfiguration, PWM disabled */
                    pTable = gActT4_EnRecfgYes_EnNewDisable;
                }    
                else if (!((pIcssgIepPwmObj->iepPwmDiffEn >> dPwmIdx) & 0x1) &&
                    !((iepPwmDiffEn >> dPwmIdx) & 0x1)) {
                    /* No Enable Reconfiguration, PWM disabled */
                    pTable = gActT1_EnRecfgNo_EnOldDisable;
                }   
                else {
                    /* No Enable Reconfiguration, PWM enabled */
                    pTable = gActT2_EnRecfgNo_EnOldEnable;
                }
                
                pwmIdx = dPwmIdx << 1;
                
                /* Determine Action Table Row */
                status = getActionTableRowDiff(recfgDcCount, dPwmIdx, 
                    pIepPwmDcCountLhsOld[pwmIdx], pIepPwmDcCountNew[pwmIdx], 
                    pwmPeriodCount, &rowIdx);
                if (status != IEP_STS_NERR) {
                    return status;
                }
                
                /* Calculate new LHS/RHS */
                calcDcLatchAction(pTable[rowIdx].latchAction, 
                    pIepPwmDcCountNew[pwmIdx], 
                    &iepPwmDcCountLhsNew, 
                    &iepPwmDcCountRhsNew);
                
                /* Execute LHS action */
                execLhsActionDiff(pTable[rowIdx].lhsAction, 
                    pIepPwmDcCountLhsOld[pwmIdx], iepPwmDcCountLhsNew, 
                    pIepCmpSrAddr, 
                    pIepPwmDiffUpdEn,
                    dPwmIdx, 
                    iepPwmPeriodCount);
                
                /* Stash RHS action */
                stashRhsAction(pTable[rowIdx].rhsAction, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
                
                /* Execute DC latch */
                execDcLatchAction(pTable[rowIdx].latchAction, 
                    &pIepPwmDcCountOld[pwmIdx], &pIepPwmDcCountLhsOld[pwmIdx], &pIepPwmDcCountRhsOld[pwmIdx],
                    pIepPwmDcCountNew[pwmIdx], iepPwmDcCountLhsNew, iepPwmDcCountRhsNew);            
                
            }
            else {
                /* Process Single-Ended PWMs */
                
                for (pwmIdx = dPwmIdx<<1; pwmIdx < ((dPwmIdx<<1) + NUM_PWM_PER_DIFF_PWM); pwmIdx++)
                {
                    /* Select Action Table */
                    if (!((pIcssgIepPwmObj->iepPwmSnglEn >> pwmIdx) & 0x1) &&
                        ((iepPwmSnglEn >> pwmIdx) & 0x1)) {
                        /* Enable Reconfiguration, PWM enabled */
                        pTable = gActT3_EnRecfgYes_EnNewEnable;
                    }
                    else if (((pIcssgIepPwmObj->iepPwmSnglEn >> pwmIdx) & 0x1) &&
                        !((iepPwmSnglEn >> pwmIdx) & 0x1)) {
                        /* Enable Reconfiguration, PWM disabled */
                        pTable = gActT4_EnRecfgYes_EnNewDisable;
                    }
                    else if (!((pIcssgIepPwmObj->iepPwmSnglEn >> pwmIdx) & 0x1) &&
                        (!(iepPwmSnglEn >> pwmIdx) & 0x1)) {
                        /* No Enable Reconfiguration, PWM disabled */
                        pTable = gActT1_EnRecfgNo_EnOldDisable;
                    }
                    else {
                        /* No Enable Reconfiguration, PWM enabled */
                        pTable = gActT2_EnRecfgNo_EnOldEnable;
                    }

                    /* Determine Action Table Row */
                    status = getActionTableRowSngl(recfgDcCount, pwmIdx, 
                        pIepPwmDcCountOld[pwmIdx], pIepPwmDcCountNew[pwmIdx], 
                        pwmPeriodCount, &rowIdx);
                    if (status != IEP_STS_NERR) {
                        return status;
                    }
                    
                    /* Calculate new LHS/RHS */
                    calcDcLatchAction(pTable[rowIdx].latchAction, 
                        pIepPwmDcCountNew[pwmIdx], 
                        &iepPwmDcCountLhsNew, 
                        &iepPwmDcCountRhsNew);
                    
                    /* Execute LHS action */
                    execLhsActionSngl(pTable[rowIdx].lhsAction, 
                        pIepPwmDcCountLhsOld[pwmIdx], iepPwmDcCountLhsNew, 
                        pIepCmpSrAddr, 
                        pIepPwmSnglUpdEn,
                        pwmIdx, 
                        iepPwmPeriodCount);
                    
                    /* Stash RHS action */
                    stashRhsAction(pTable[rowIdx].rhsAction, pIepPwmRhsRecfgFlag, &pIepPwmRhsAction[pwmIdx]);
                    
                    /* Execute DC latch */
                    execDcLatchAction(pTable[rowIdx].latchAction, 
                        &pIepPwmDcCountOld[pwmIdx], &pIepPwmDcCountLhsOld[pwmIdx], &pIepPwmDcCountRhsOld[pwmIdx],
                        pIepPwmDcCountNew[pwmIdx], iepPwmDcCountLhsNew, iepPwmDcCountRhsNew);        
                }
            }
        }
        
        /* Latch Single-Ended and Differential PWM Enable */
        latchIepPwmSnglDiffEn(pIcssgIepPwmObj, iepPwmSnglEn, iepPwmDiffEn);            
    }
    
   return status;
}

/* Get Action Table row, Single-Ended PWM */
static Int32 getActionTableRowSngl(
    Uint16 recfgDcCount, 
    Uint8 pwmIdx, 
    Uint32 iepPwmDcCountOld, 
    Uint32 iepPwmDcCountNew, 
    Uint32 pwmPeriodCount, 
    Uint8 *pRowIdx
)
{
    Int32 status = IEP_STS_NERR;
    
    if ((recfgDcCount >> pwmIdx) & 0x1) {
        /* Possible change to PWM DC count */
        if ((iepPwmDcCountOld > 0) && (iepPwmDcCountOld < pwmPeriodCount)) {
            if (iepPwmDcCountNew == iepPwmDcCountOld) {
                /* new DC count is x */
                *pRowIdx = AT_Row01_DcOldX_DcNewX;
            }
            else if ((iepPwmDcCountNew > 0) && (iepPwmDcCountNew < pwmPeriodCount)) {
                /* new DC count is y, x!=y */
                *pRowIdx = AT_Row02_DcOldX_DcNewY;
            }
            else if (iepPwmDcCountNew == 0) {
                /* new DC count is 0 */
                *pRowIdx = AT_Row03_DcOldX_DcNew0;
            }
            else if (iepPwmDcCountNew == pwmPeriodCount) {
                /* new DC count is 100 */
                *pRowIdx = AT_Row04_DcOldX_DcNew100;
            }
            else {
                /* error, invalid DC count */
                status = IPE_STS_ERR_INV_DC_COUNT;
            }
        }
        else if (iepPwmDcCountOld == 0) { /* old DC count is 0 */
            if ((iepPwmDcCountNew > 0) && (iepPwmDcCountNew < pwmPeriodCount)) {
                /* new DC count !=0, !=100 */
                *pRowIdx = AT_Row05_DcOld0_DcNewY;
            }
            else if (iepPwmDcCountNew == 0) {
                /* new DC count is 0 */
                *pRowIdx = AT_Row06_DcOld0_DcNew0;
            }
            else if (iepPwmDcCountNew == pwmPeriodCount) {
                /* new DC count is 100 */
                *pRowIdx = AT_Row10_DcOld100_DcNew100;
            }
            else {
                /* error, invalid DC count */
                status = IPE_STS_ERR_INV_DC_COUNT;
            }
        }       
        else if (iepPwmDcCountOld == pwmPeriodCount) { /* old DC count is 100 */
            if ((iepPwmDcCountNew > 0) && (iepPwmDcCountNew < pwmPeriodCount)) {
                /* new DC count !=0, !=100 */
                *pRowIdx = AT_Row08_DcOld100_DcNewY;
            }
            else if (iepPwmDcCountNew == 0) {
                /* new DC count is 0 */
                *pRowIdx = AT_Row09_DcOld100_DcNew0;
            }
            else if (iepPwmDcCountNew == pwmPeriodCount) {
                /* new DC count is 100 */
                *pRowIdx = AT_Row10_DcOld100_DcNew100;
            }
            else {
                /* error, invalid DC count */
                status = IPE_STS_ERR_INV_DC_COUNT;
            }
        }    
        else {
            /* error, invalid DC count */
            status = IPE_STS_ERR_INV_DC_COUNT;            
        }
    }
    else {
        /* No change to PWM DC count */
        if ((iepPwmDcCountOld > 0) && (iepPwmDcCountOld < pwmPeriodCount)) {
            /* latched DC count !=0, !=100 */
            *pRowIdx = AT_Row01_DcOldX_DcNewX;
        }
        else if (iepPwmDcCountOld == 0) {
            /* old DC count is 0 */
            *pRowIdx = AT_Row06_DcOld0_DcNew0;
        }
        else if (iepPwmDcCountOld == pwmPeriodCount) {
            /* old DC count is 100 */
            *pRowIdx = AT_Row10_DcOld100_DcNew100;
        }
        else {
            /* error, invalid DC count */
            status = IPE_STS_ERR_INV_DC_COUNT;
        }            
    }
    
    return status;
}

/* Get Action Table row, Differential PWM */
static Int32 getActionTableRowDiff(
    Uint16 recfgDcCount, 
    Uint8 dPwmIdx, 
    Uint32 iepPwmDcCountOld, 
    Uint32 iepPwmDcCountNew, 
    Uint32 pwmPeriodCount, 
    Uint8 *pRowIdx
)
{
    Int32 status = IEP_STS_NERR;
    Uint8 pwmIdx;
    
    pwmIdx = dPwmIdx << 1;  /* multiply by 2 for differential PWM */
        
    if ((recfgDcCount >> pwmIdx) & 0x1) {
        /* Possible change to PWM DC count */
        if ((iepPwmDcCountOld > 0) && (iepPwmDcCountOld < pwmPeriodCount)) {
            if (iepPwmDcCountNew == iepPwmDcCountOld) {
                /* new DC count is x */
                *pRowIdx = AT_Row01_DcOldX_DcNewX;
            }
            else if ((iepPwmDcCountNew > 0) && (iepPwmDcCountNew < pwmPeriodCount)) {
                /* new DC count is y, x!=y */
                *pRowIdx = AT_Row02_DcOldX_DcNewY;
            }
            else if (iepPwmDcCountNew == 0) {
                /* new DC count is 0 */
                *pRowIdx = AT_Row03_DcOldX_DcNew0;
            }
            else if (iepPwmDcCountNew == pwmPeriodCount) {
                /* new DC count is 100 */
                *pRowIdx = AT_Row04_DcOldX_DcNew100;
            }
            else {
                /* error, invalid DC count */
                status = IPE_STS_ERR_INV_DC_COUNT;
            }
        }
        else if (iepPwmDcCountOld == 0) { /* old DC count is 0 */
            if ((iepPwmDcCountNew > 0) && (iepPwmDcCountNew < pwmPeriodCount)) {
                /* new DC count !=0, !=100 */
                *pRowIdx = AT_Row05_DcOld0_DcNewY;
            }
            else if (iepPwmDcCountNew == 0) {
                /* new DC count is 0 */
                *pRowIdx = AT_Row06_DcOld0_DcNew0;
            }
            else if (iepPwmDcCountNew == pwmPeriodCount) {
                /* new DC count is 100 */
                *pRowIdx = AT_Row10_DcOld100_DcNew100;
            }
            else {
                /* error, invalid DC count */
                status = IPE_STS_ERR_INV_DC_COUNT;
            }
        }
        else if (iepPwmDcCountOld == pwmPeriodCount) { /* old DC count is 100 */
            if ((iepPwmDcCountNew > 0) && (iepPwmDcCountNew < pwmPeriodCount)) {
                /* new DC count !=0, !=100 */
                *pRowIdx = AT_Row08_DcOld100_DcNewY;
            }
            else if (iepPwmDcCountNew == 0) {
                /* new DC count is 0 */
                *pRowIdx = AT_Row09_DcOld100_DcNew0;
            }
            else if (iepPwmDcCountNew == pwmPeriodCount) {
                /* new DC count is 100 */
                *pRowIdx = AT_Row10_DcOld100_DcNew100;
            }
            else {
                /* error, invalid DC count */
                status = IPE_STS_ERR_INV_DC_COUNT;
            }
        }
        else {
            /* error, invalid DC count */
            status = IPE_STS_ERR_INV_DC_COUNT;
        }
    }
    else {
        /* No change to PWM DC count */
        if ((iepPwmDcCountOld > 0) && (iepPwmDcCountOld < pwmPeriodCount)) {
            /* latched DC count !=0, !=100 */
            *pRowIdx = AT_Row01_DcOldX_DcNewX;
        }
        else if (iepPwmDcCountOld == 0) {
            /* old DC count is 0 */
            *pRowIdx = AT_Row06_DcOld0_DcNew0;
        }
        else if (iepPwmDcCountOld == pwmPeriodCount) {
            /* old DC count is 100 */
            *pRowIdx = AT_Row10_DcOld100_DcNew100;
        }
    }
    
    return status;
}

/* Calculate IEP PWM LHS/RHS Duty Cycle Counts */
static void calcDcLatchAction(
    IepLatchAction actionLatch, 
    Uint32 iepPwmDcCountNew, 
    Uint32 *pIepPwmDcCountLhsNew, 
    Uint32 *pIepPwmDcCountRhsNew
)
{
    Uint32 dcCountLhs, dcCountRhs;
    
    switch (actionLatch)
    {
        /* New DC count is 0 or 100.
           Don't calculate LHS/RHS. */
        case LATCH_ACTION_Latch_0:
        case LATCH_ACTION_Latch_100:
            break;
        /* New DC count !=0, !=100.
           Calculate LHS/RHS. */
        case LATCH_ACTION_Latch_New:
            calcDcLhsRhs(iepPwmDcCountNew, &dcCountLhs, &dcCountRhs);
            *pIepPwmDcCountLhsNew = dcCountLhs;
            *pIepPwmDcCountRhsNew = dcCountRhs;
            break;
        case LATCH_ACTION_None:
        default:
            break;
    }
}

/* Calculate DC LHS/RHS for DC */
static void calcDcLhsRhs(
    Uint32 dcCount, 
    Uint32 *pDcCountLhs, 
    Uint32 *pDcCountRhs
)
{
    Uint32 dcCountLhs, dcCountRhs;
    
    dcCountLhs = COUNT_TO_CLK(dcCount)/2;
    dcCountLhs = CLK_TO_COUNT(dcCountLhs);
    dcCountRhs = dcCountLhs;
    if ((COUNT_TO_CLK(dcCount) & 0x1) == 1) {   /* DC count is odd, distribute extra clocks to RHS */
        dcCountRhs += DEF_COUNT_INC_PER_CLK;
    }
        
    *pDcCountLhs = dcCountLhs;
    *pDcCountRhs = dcCountRhs;
}

/* Execute LHS action, Single-Ended PWM */
static void execLhsActionSngl(
    IepPwmLhsAction lhsAction, 
    Uint32 iepPwmDcCountLhsOld, 
    Uint32 iepPwmDcCountLhsNew, 
    volatile uint32_t **pIepCmpSrAddr,
    Uint16 *pIepPwmSnglUpdEn, 
    Uint8 pwmIdx, 
    Uint32 iepPwmPeriodCount
)
{
    volatile uint32_t *pCmpSr;

    pCmpSr = pIepCmpSrAddr[pwmIdx];
    
    switch (lhsAction)
    {
        case LHS_ACTION_Set_CmpSr_DcLhsY:
            *pCmpSr = iepPwmPeriodCount - iepPwmDcCountLhsNew;  /* Write LHS value to CMP Shadow Register */
            break;
            
        case LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate:
            *pCmpSr = iepPwmPeriodCount - iepPwmDcCountLhsOld;  /* Write LHS value to CMP Shadow Register */
            *pIepPwmSnglUpdEn |= 1<<pwmIdx;                     /* Enable CMP SR update */
                
            break;
        case LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate:
            *pCmpSr = iepPwmPeriodCount - iepPwmDcCountLhsNew;  /* Write LHS value to CMP Shadow Register */
            *pIepPwmSnglUpdEn |= 1<<pwmIdx;                     /* Enable CMP SR update */
            break;
        
        case LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate:
            *pCmpSr = CMP_SR_EARLY_VAL;                         /* Write LHS value to CMP Shadow Register */
            *pIepPwmSnglUpdEn |= 1<<pwmIdx;                     /* Enable CMP SR update */
            break;
            
        case LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate:
            *pCmpSr = iepPwmPeriodCount;                        /* Write LHS value to CMP Shadow Register */
            *pIepPwmSnglUpdEn &= ~(1<<pwmIdx);                  /* Enable CMP SR update */
            break;
            
        case LHS_ACTION_None:
        default:
            break;
    }
}

/* Execute LHS action, Differential PWM */
static void execLhsActionDiff(
    IepPwmLhsAction lhsAction, 
    Uint32 iepPwmDcCountLhsOld, 
    Uint32 iepPwmDcCountLhsNew, 
    volatile uint32_t **pIepCmpSrAddr,
    Uint8 *pIepPwmDiffUpdEn, 
    Uint8 dPwmIdx, 
    Uint32 iepPwmPeriodCount
)
{
    volatile uint32_t *pCmpSrPos, *pCmpSrNeg;
    Uint8 pwmIdx;
    Uint32 temp;
    
    pwmIdx = dPwmIdx << 1;   /* multiply by 2 for differential PWM */
    pCmpSrPos = pIepCmpSrAddr[pwmIdx];
    pCmpSrNeg = pIepCmpSrAddr[pwmIdx+1];
    
    switch (lhsAction)
    {
        case LHS_ACTION_Set_CmpSr_DcLhsY:
            /* Write same LHS value to both CMP Shadow Registers in differential pair */
            temp = iepPwmPeriodCount - iepPwmDcCountLhsNew;
            *pCmpSrPos = temp;
            *pCmpSrNeg = temp;
            break;
            
        case LHS_ACTION_Set_CmpSr_DcLhsX_And_EnableSrUpdate:
            /* Write same LHS value to both CMP Shadow Registers in differential pair */
            temp = iepPwmPeriodCount - iepPwmDcCountLhsOld;
            *pCmpSrPos = temp;
            *pCmpSrNeg = temp;
            /* Enable CMP SR update */
            *pIepPwmDiffUpdEn |= 1<<dPwmIdx;
            break;

        case LHS_ACTION_Set_CmpSr_DcLhsY_And_EnableSrUpdate:
            /* Write same LHS value to both CMP Shadow Registers in differential pair */
            temp = iepPwmPeriodCount - iepPwmDcCountLhsNew;
            *pCmpSrPos = temp;
            *pCmpSrNeg = temp;
            /* Enable CMP SR update */
            *pIepPwmDiffUpdEn |= 1<<dPwmIdx;
            break;
        
        case LHS_ACTION_Set_CmpSr_EarlyInPrd_And_EnableSrUpdate:
            /* Write same LHS value to both CMP Shadow Registers in differential pair */
            *pCmpSrPos = CMP_SR_EARLY_VAL;
            *pCmpSrNeg = CMP_SR_EARLY_VAL;
            /* Enable CMP SR update */
            *pIepPwmDiffUpdEn |= 1<<dPwmIdx;
            break;
            
        case LHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate:
            /* Write same LHS value to both CMP Shadow Registers in differential pair */
            *pCmpSrPos = iepPwmPeriodCount;
            *pCmpSrNeg = iepPwmPeriodCount;
            /* Disable CMP SR update */
            *pIepPwmDiffUpdEn &= ~(1<<dPwmIdx);
            break;
            
        case LHS_ACTION_None:
        default:
            break;
    }
}

/* Stash RHS action */
static void stashRhsAction(
    IepPwmRhsAction actionRhs, 
    Bool *pIepPwmRhsRecfgFlag, 
    IepPwmRhsAction *pIepPwmRhsAction
)
{
    if (actionRhs != RHS_ACTION_None) {
        *pIepPwmRhsRecfgFlag = TRUE;
    }
    
    *pIepPwmRhsAction = actionRhs;
}
    
/* Execute (LHS) DC latch action */
static void execDcLatchAction(
    IepLatchAction actionLatch, 
    Uint32 *pIepPwmDcCountOld, 
    Uint32 *pIepPwmDcCountLhsOld, 
    Uint32 *pIepPwmDcCountRhsOld, 
    Uint32 iepPwmDcCountNew, 
    Uint32 iepPwmDcCountLhsNew, 
    Uint32 iepPwmDcCountRhsNew
)
{
    switch (actionLatch)
    {
        /* New DC count is 0 or 100.
           Latch new DC, don't calculate & latch corresponding LHS/RHS. */
        case LATCH_ACTION_Latch_0:
        case LATCH_ACTION_Latch_100:
            *pIepPwmDcCountOld = iepPwmDcCountNew;
            break;
        /* New DC count !=0, !=100.
           Latch new DC latch corresponding LHS/RHS DC. */
        case LATCH_ACTION_Latch_New:
            *pIepPwmDcCountOld = iepPwmDcCountNew;
            *pIepPwmDcCountLhsOld = iepPwmDcCountLhsNew;
            *pIepPwmDcCountRhsOld = iepPwmDcCountRhsNew;
            break;
        case LATCH_ACTION_None:
        default:
            break;    
    }
}

/* Execute stashed RHS actions */
static void execRhsActionStash(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    Uint32 *pIepPwmDcCountRhs;
    Uint16 *pIepPwmDbCount;
    Uint16 *pIepPwmSnglUpdEn;
    Uint8 *pIepPwmDiffUpdEn;
    volatile uint32_t **pIepCmpSrAddr;
    Uint32 iepPwmPeriodCount;
    IepPwmRhsAction *pIepPwmRhsAction;
    Uint32 dcRhsY;
    volatile uint32_t *pCmpSr;
    Uint8 pwmIdx, dPwmIdx;
    
    /* Get latched IEP PWM DC RHS count array */
    pIepPwmDcCountRhs = &pIcssgIepPwmObj->iepPwmDcCountRhs[0];
    /* Get Deadband count array */
    pIepPwmDbCount = &pIcssgIepPwmObj->iepPwmDbCount[0];   
    /* Get Single-Ended & Differential PWM Update Enable */
    pIepPwmSnglUpdEn = &pIcssgIepPwmObj->iepPwmSnglUpdEn;
    pIepPwmDiffUpdEn = &pIcssgIepPwmObj->iepPwmDiffUpdEn;
    /* Get IEP CMP Shadow Registers array */
    pIepCmpSrAddr = &pIcssgIepPwmObj->iepCmpSrAddr[0];    
    /* Get period */
    iepPwmPeriodCount = pIcssgIepPwmObj->iepPwmPeriodCount;
    /* Get RHS action array */
    pIepPwmRhsAction = &pIcssgIepPwmObj->iepPwmRhsAction[0];
    
    if (pIcssgIepPwmObj->iepPwmRhsRecfgFlag == TRUE) {
        for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
        {
            if ((pIcssgIepPwmObj->iepPwmMode >> dPwmIdx) & 0x1) {
                /* Process Differential PWM */
                
                pwmIdx = dPwmIdx << 1;
                switch(pIepPwmRhsAction[pwmIdx])
                {
                    case RHS_ACTION_Set_CmpSr_DcRhsY_And_EnableSrUpdate:
                        dcRhsY = pIepPwmDcCountRhs[pwmIdx];
                        
                        pCmpSr = pIepCmpSrAddr[pwmIdx];
                        *pCmpSr = dcRhsY;                           /* Write RHS value to CMP Shadow Register */
                        pwmIdx++;
                        pCmpSr = pIepCmpSrAddr[pwmIdx];
                        *pCmpSr = dcRhsY + pIepPwmDbCount[dPwmIdx]; /* Write RHS value to CMP Shadow Register */
                        
                        *pIepPwmDiffUpdEn |= 1<<dPwmIdx;            /* Enable CMP SR update */
                        break;
                        
                    case RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate:
                        dcRhsY = pIepPwmDcCountRhs[pwmIdx];
                        
                        /* Write same LHS value to both CMP Shadow Registers in differential pair */
                        pCmpSr = pIepCmpSrAddr[pwmIdx];
                        *pCmpSr = iepPwmPeriodCount;                /* Write value greater than Period to Shadow Register */
                        pwmIdx++;
                        pCmpSr = pIepCmpSrAddr[pwmIdx];
                        *pCmpSr = iepPwmPeriodCount;                /* Write value greater than Period to Shadow Register */
                        
                        /* Enable CMP SR update */
                        *pIepPwmDiffUpdEn &= ~(1<<dPwmIdx);         /* Disable CMP SR update */
                        break;
                        
                    case RHS_ACTION_None:
                    default:
                        break;
                }
                pIepPwmRhsAction[pwmIdx] = RHS_ACTION_None;
            }
            else {
                /* Process Single-Ended PWMs */
                
                for (pwmIdx = dPwmIdx<<1; pwmIdx < ((dPwmIdx<<1) + NUM_PWM_PER_DIFF_PWM); pwmIdx++)
                {
                    switch (pIepPwmRhsAction[pwmIdx])
                    {
                        case RHS_ACTION_Set_CmpSr_DcRhsY_And_EnableSrUpdate:
                            dcRhsY = pIepPwmDcCountRhs[pwmIdx];
                            pCmpSr = pIepCmpSrAddr[pwmIdx];
                            *pCmpSr = dcRhsY;                       /* Write RHS value to CMP Shadow Register */
                            *pIepPwmSnglUpdEn |= 1<<pwmIdx;         /* Enable CMP SR update */
                            break;
                        case RHS_ACTION_Set_CmpSr_GtPrd_And_DisableSrUpdate:
                            pCmpSr = pIepCmpSrAddr[pwmIdx];
                            *pCmpSr = iepPwmPeriodCount;            /* Write value greater than Period to CMP Shadow Register */
                            *pIepPwmSnglUpdEn &= ~(1<<pwmIdx);      /* Disable CMP SR update */
                            break;
                        case RHS_ACTION_None:
                        default:
                            break;
                    }
                    pIepPwmRhsAction[pwmIdx] = RHS_ACTION_None;                    
                }
            }
        }
    }
}

/* Update IEP PWM CMPx Shadow Registers for DB reconfiguration. */
static Int32 updateIepPwmCmpxShRegDb(
    IcssgIepPwmObj *pIcssgIepPwmObj
)
{
    IepPwmFwRegs *pIepPwmFwRegs = pIcssgIepPwmObj->pIepPwmFwRegs;
    Uint32 *pIepPwmDcCount;
    volatile Uint16 *pIepPwmDbCount;
    volatile uint32_t *pShadowReg;
    Uint8 pwmIdx, dPwmIdx;
    
    pIepPwmDcCount = &pIcssgIepPwmObj->iepPwmDcCountLhs[0];     /* init pointer to PWM Duty Cycle Count */
    pIepPwmDbCount = &pIepPwmFwRegs->IEP_PWM0_1_DB_COUNT;       /* init pointer to PWM Deadband Count */
    for (dPwmIdx = 0; dPwmIdx < IEP_MAX_NUM_DIFF_PWM; dPwmIdx++)
    {
        if (((pIcssgIepPwmObj->iepPwmDiffUpdEn >> dPwmIdx) & 0x1) == 1) { /* check PWM update enabled */
            /* Write CMP SR for POS PWM */
            pwmIdx = dPwmIdx << 1;
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx];     /* set pointer to CMP Shadow Register */
            *pShadowReg = pIcssgIepPwmObj->iepPwmPeriodCount - *pIepPwmDcCount;
            /* Write CMP SR for NEG PWM.
               Increment CMP SR pointer by 2 since CMP registers are 64 bit. */
            pwmIdx++;
            pShadowReg = pIcssgIepPwmObj->iepCmpSrAddr[pwmIdx];     /* set pointer to CMP Shadow Register */
            *pShadowReg = pIcssgIepPwmObj->iepPwmPeriodCount - *pIepPwmDcCount - *pIepPwmDbCount;
        }
        pIepPwmDcCount += 2;    /* differential pair use same Duty Cycle Count */
        pIepPwmDbCount++;
    }
    
    /* Latch IEP PWM Deadband Count */
    latchIepPwmDbCount(pIcssgIepPwmObj, TRUE);
    
    return IEP_STS_NERR;
}
