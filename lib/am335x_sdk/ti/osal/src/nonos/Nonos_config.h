/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== Nonos_config.h ========
 *  This file allows a user to modify the behavior of the TI-RTOS
 *  implementation for the driver RTOS port.
 */

#ifndef ti_osal_src_noos_config__include
#define ti_osal_src_noos_config__include

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/osal/osal.h>
#include <ti/osal/soc/osal_soc.h>
#include <ti/csl/csl_types.h>

/* Host emulation defines _TMS320C6X which needs to be */
#if defined (HOST_EMULATION)
	#if defined (__C7100__)
		#undef _TMS320C6X
	#endif
#endif

#ifdef _TMS320C6X
#include <ti/csl/src/intc/csl_intc.h>
#include <ti/csl/src/intc/csl_intcAux.h>
#include <ti/csl/csl_cacheAux.h>
#include <ti/csl/csl_chipAux.h>
#include <ti/csl/arch/csl_arch.h>

typedef struct hwi_struct {
      uint32_t                      intNum;
      CSL_IntcObj                   intcObj;
      CSL_IntcHandle                handle;
 } Hwi_Struct;
#elif defined (__aarch64__)
#include <ti/csl/arch/a53/csl_a53.h>
#include <ti/csl/arch/a53/interrupt.h>
#include <ti/csl/arch/a53/csl_a53v8misc.h>

typedef struct hwi_struct {
  uint32_t                          intNum;
} Hwi_Struct;

#elif defined (__ARM_ARCH_7A__) && !defined (SOC_AM437x) &&  !defined(SOC_AM335x)
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_armGic.h>
#include <ti/csl/csl_armGicAux.h>

typedef struct hwi_struct {
  uint32_t                          intNum;
  CSL_ArmGicIntrParams_t            gicParams;
} Hwi_Struct;
#elif defined (__TI_ARM_V7R4__)
#include <ti/csl/arch/csl_arch.h>
typedef struct hwi_struct {
    uint32_t                      intNum;
} Hwi_Struct;
#elif defined (__TI_ARM_V7M4__) || defined(__TI_ARM_V5__)
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/soc.h>
#if	defined(__TI_ARM_V7M4__)
#include <ti/csl/cslr_unicache_cfg.h>
#endif

typedef struct hwi_struct {
    uint32_t                      intNum;
} Hwi_Struct;
#elif defined(SOC_AM437x) || defined(SOC_AM335x)
typedef struct hwi_struct {
  uint32_t     intNum;
  HwiP_Fxn     fxn;
  void*        arg;
} Hwi_Struct;
#else
typedef struct hwi_struct {
  /* TBD */
  uint32_t reserved;
} Hwi_Struct;
#endif


/* TimeStamp Provider structure */
typedef struct timeStamp_struct
{
    uint32_t    lo;
    uint32_t    hi;
}TimeStamp_Struct;


#define  TIMERP_EVENT_NOT_AVAILABLE (-(int32_t) (1u))
#define  TIMERP_INTR_USER_CONFIGURE (-(int32_t) (2u))
#define  TIMERP_EVENT_USER_CONFIGURE (-(int32_t) (3u))

/*
 *  @brief    TimerP Information structure
 *
 *  Structure that contains the timer info table for the
 *  non-os use case for default initializations
 */
typedef struct TimerP_dmTimerDefault_s {
    const char  *name;       /*< Name of the timer instance. Memory must
                             persist for the life of the clock instance.
                             This can be used for debugging purposes, or
                             set to NULL if not needed. */
    uint32_t baseAddr;   /*< timer base address */
    int32_t  intNum;     /*< timer Interrupt number */
    int32_t  eventId;    /*< timer event Id */
} TimerP_dmTimerDefault;


/*
 *  @brief    TimerP 64bit Timer Information structure
 *
 *  Structure that contains the timer info table for the
 *  non-os use case for default initializations
 */
typedef struct TimerP_timer64Default_s {
    const char    *name;   /*< Name of the timer instance. Memory must
                             persist for the life of the clock instance.
                             This can be used for debugging purposes, or
                             set to NULL if not needed. */
    uint32_t baseAddr;     /*< timer base address */
    int32_t  intNumLo;     /*< timer Interrupt number for timer Lo*/
    int32_t  intNumHi;     /*< timer Interrupt number for timer Hi*/
    int32_t  eventIdLo;    /*< timer lo event Id */
    int32_t  eventIdHi;    /*< timer hi event Id */
} TimerP_timer64Default;

/*
 *  @brief    TimerP RTI Information structure
 *
 *  Structure that contains the timer info table for the
 *  non-os use case for default initializations
 */
typedef struct TimerP_rtiTimerDefault_s {
    const char  *name;       /*< Name of the timer instance. Memory must
                             persist for the life of the clock instance.
                             This can be used for debugging purposes, or
                             set to NULL if not needed. */
    uint32_t baseAddr;   /*< timer base address */
    int32_t  intNum;     /*< timer Interrupt number */
    int32_t  eventId;    /*< timer event Id (C66x only) */
} TimerP_rtiTimerDefault;

#if defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_DRA72x) || defined(SOC_DRA75x) || defined(SOC_DRA78x) || defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2E) || defined(SOC_K2L) || defined(SOC_K2G) || defined(SOC_C6678) ||defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138) || defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200) || defined(SOC_TPR12)

/* This function returns the lower 32 bits of the
 * internal frequency set for the timer
 */
int32_t TimerP_getDefaultFreqLo(uint32_t timerId);

/* This function returns the higher 32 bits of the
 * internal frequency set for the timer
 */
int32_t TimerP_getDefaultFreqHi(uint32_t timerId);

#if defined (BUILD_MCU)
/*
 * This function update the default configurations in the timer info
 * table if the running core is R5.
 *
 * The timer info table configures MCU domain's DM Timer instances by
 * default for R5, TimerP_updateDefaultInfoTbl() is called when
 * TimerP_getTimerBaseAddr()is called first time to overwrite the defaut
 * configurations with the configurations of Main domain's DM Timer
 * instances if R5 is on the Main domain
 */
void TimerP_updateDefaultInfoTbl(void);

/*
 * This function maps the ID to respective ID for that core for timer
 * to function. There are multiple R5SS present in SOCs requiring this
 * change. Example: J721e has two R5FSS, one in MAIN and other in MCU.
 */
uint32_t TimerP_mapId(uint32_t id);
#endif

/* Reference the default initializations for the dmtimers */
extern  TimerP_dmTimerDefault gDmTimerPInfoTbl[TimerP_numTimerDevices];

/* Reference the default initializations for the timer 64 */
extern  TimerP_timer64Default gTimer64InfoTbl[TimerP_numTimerDevices];

/* Reference the default initializations for the rtitimers */
extern  TimerP_rtiTimerDefault gRtiTimerPInfoTbl[TimerP_numTimerDevices];
#endif

/* This function enables the interrupt for a given interrupt number */
void OsalArch_enableInterrupt(uint32_t intNum);

/* This function disables the interrupt for a given interrupt number */
void OsalArch_disableInterrupt(uint32_t intNum);

/* Below function clears interrupt in the chip level */
void OsalArch_clearInterrupt(uint32_t intNum);

/* Below function globally disable interrupt in the chip level */
uintptr_t OsalArch_globalDisableInterrupt(void);

/* Below function posts an interrupt */
int32_t OsalArch_postInterrupt(uint32_t intNum);

/* Below function globally restore interrupt in the chip level */
void OsalArch_globalRestoreInterrupt (uintptr_t restoreValue);

/* Below function initializes the intc module,
   this is needed only once per start */
void OsalArch_oneTimeInit(void);

/* Below function registers the interrupt for a given ISR */
HwiP_Handle OsalArch_HwiPCreate(int32_t interruptNum, HwiP_Fxn hwiFxn,
                          const HwiP_Params *params);

/* Below function deletes/frees up the HwiP handle created */
HwiP_Status OsalArch_HwiPDelete(HwiP_Handle handle);

/*Below function implements the time in micro seconds read */
void             osalArch_TimestampGet64(TimeStamp_Struct *timeStamp);
void             osalArch_TimestampInit(void);
int32_t  osalArch_TimeStampGetFreqKHz(void);
extern           void osal_TimestampProvider_initCCNT(void);
extern           uint32_t osal_TimestampProvider_getOverflowCCNT(void);

#if defined (__ARM_ARCH_7A__) || defined(__aarch64__)
#if !defined (SOC_AM437x) &&  !defined(SOC_AM335x)
/* Check if GIC is enabled or not */
void OsalArch_gicInit(void);
#endif
#endif

#ifdef _TMS320C6X
/* Returns the HwiP_Handle corresponding to an interrupt number */
HwiP_Handle OsalArch_getHandle(int32_t interruptNum);

/* Returns the event ID corresponding to a interrupt number*/
int32_t OsalArch_getEventId(int32_t interruptNum);
#endif

extern Osal_HwAttrs  gOsal_HwAttrs;


#ifndef NULL_PTR
#define NULL_PTR ((void *)0x0)
#endif
/*
 * Dummy function to check size during compile time
 *  ======== HwiP_compileTime_SizeChk ========
 */
void OsalArch_compileTime_SizeChk(void);
void SemaphoreP_compileTime_SizeChk(void);
void HwiP_compileTime_SizeChk(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_src_noos_config__include */
