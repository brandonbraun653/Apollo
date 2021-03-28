/*
 * Copyright (c) 2015 - 2018, Texas Instruments Incorporated
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

/**
 *  \defgroup DRV_OSAL_MODULE OSAL
 *
 *  @{
 */
/* @} */

/**
 *  \ingroup DRV_OSAL_MODULE
 *  \defgroup DRV_OSAL_API OSAL_API
 *            OSAL interface
 *
 *  @{
 */
/** ============================================================================
 *  @file       osal.h
 *
 *  @brief      OS Abstraction Layer header
 *
 *  ============================================================================
 */

#ifndef ti_OSAL__include
#define ti_OSAL__include

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/osal/HwiP.h>
#include <ti/osal/MuxIntcP.h>
#include <ti/osal/SemaphoreP.h>
#include <ti/osal/CacheP.h>
#include <ti/osal/TimerP.h>
#include <ti/osal/RegisterIntr.h>
#include <ti/osal/Queue.h>
#ifdef _TMS320C6X
#include <ti/osal/EventCombinerP.h>
#endif

/*********************************************************************
 * @def osal_OK
 * OSAL operation successful
 *********************************************************************/
#define osal_OK        (0)

/*********************************************************************
 * @def osal_FAILURE
 * OSAL operation failed
 *********************************************************************/
#define osal_FAILURE  (-(int32_t)(1))

/*********************************************************************
 * @def osal_UNSUPPORTED
 * OSAL operation is not supported
 *********************************************************************/
#define osal_UNSUPPORTED       (-(int32_t)(2))

/*********************************************************************
 * @def osal_NOMEM
 * OSAL operation is not successful due to internal osal static memory
 * is full. Application would need to create additional memory blocks
 * during startup by calling @ref Osal_setHwAttrs API to set the additional
 * memory blocks for semaphoreP and hwiP
 *********************************************************************/
#define osal_NOMEM             (-(int32_t)(3))

/*********************************************************************
 * @def OSAL_NONOS_SEMAPHOREP_SIZE_BYTES
 * Semaphorep handle size for non-os use case
 * Application can use this size to provide a secondary extended
 * memory block for semaphore creation when all the memory  (internal to osal)
 * are utilized
 *
 *********************************************************************/
#define  OSAL_NONOS_SEMAPHOREP_SIZE_BYTES ((uint32_t) 48U)

/*********************************************************************
 * @def OSAL_NONOS_HWI_SIZE_BYTES
 * HwiP handle size for non-os use case
 * Application can use this size to provide a secondary extended
 * memory block for hwip creation when all the memory  (internal to osal)
 * are utilized
 *********************************************************************/
#define  OSAL_NONOS_HWIP_SIZE_BYTES ((uint32_t) 48U)

/*********************************************************************
 * @def OSAL_TIRTOS_SEMAPHOREP_SIZE_BYTES
 * Semaphorep handle size for non-os use case
 * Application can use this size to provide a secondary extended
 * memory block for semaphore creation when all the memory  (internal to osal)
 * are utilized
 *
 *********************************************************************/
#define  OSAL_TIRTOS_SEMAPHOREP_SIZE_BYTES ((uint32_t) 96U)

/*********************************************************************
 * @def OSAL_TIRTOS_HWI_SIZE_BYTES
 * HwiP handle size for non-os use case
 * Application can use this size to provide a secondary extended
 * memory block for hwip creation when all the memory  (internal to osal)
 * are utilized
 *********************************************************************/
#define  OSAL_TIRTOS_HWIP_SIZE_BYTES (96U)

/**
 *  \brief This structure holds static memory status parameters of OSAL
 *         library
 */
typedef struct Osal_StaticMemoryStatus
{
    uint32_t peakSemObjs;
    uint32_t numMaxSemObjs;
    uint32_t numFreeSemObjs;

    uint32_t peakTimerObjs;
    uint32_t numMaxTimerObjs;
    uint32_t numFreeTimerObjs;

    uint32_t peakHwiObjs;
    uint32_t numMaxHwiObjs;
    uint32_t numFreeHwiObjs;
} Osal_StaticMemStatus;

/**
 *  \brief This enum defines the multiple thread types used under OSAL
 *         library
 */
typedef enum Osal_ThreadType_e {
    Osal_ThreadType_Hwi,   /*!< Current thread is a Hwi  */
    Osal_ThreadType_Swi,   /*!< Current thread is a Swi  */
    Osal_ThreadType_Task,  /*!< Current thread is a Task */
    Osal_ThreadType_Main   /*!< Current thread is Main   */
} Osal_ThreadType;

/* Internal function for assert */
extern void Osal_DebugP_assert(int32_t expression, const char *file, int32_t line);
/*!
 *  @brief  Assert checking function
 *
 *  If the expression is evaluated to true, the API does nothing.
 *  If it is evaluated to false, the underlying RTOS port implementation
 *  handles the assert via its mechanisms.
 *
 *  @param  expression Expression to evaluate
 */
/* in real code use TI's version of OSAL_Assert (which is also fatal for OSAL_Assert(1)*/
#define OSAL_Assert(expression) (Osal_DebugP_assert((int32_t)((expression)?1:0),\
                                                  __FILE__, __LINE__))

/*!
 *  @brief  Function to get the current thread type.
 *
 *
 *  @return current thread type
 */
extern Osal_ThreadType Osal_getThreadType(void);

/*!
 *  @brief  Function to get the delay/sleep.
 *
 *  @param  nTicks number of ticks
 *
 *  #@note  for bare metal application it is number of 1ms ticks
 *
 *          Prerequisites: Board_init() to be called before 
 *          invoking this API
 *
 *  @return osal_OK for success, osal_FAILURE on failure
 */
extern int32_t Osal_delay(uint32_t nTicks);

/*!
 *  @brief  Osal hw access type 
 *
 */
typedef enum {
  OSAL_HWACCESS_UNRESTRICTED, /* No restriction on hardware access or configuration */
  OSAL_HWACCESS_RESTRICTED    /* Restrictive access to hardware such as GIC */
} Osal_HwAccessType;

/*!
 *  @brief  Osal memory address range
 *
 */
typedef struct Osal_memRange_s {
  uintptr_t    base;          /**< Start address value */
  uint32_t     size;          /**< size in bytes */
} Osal_memRange;

/*!
 *  @brief  Osal hw attributes structure
 *
 */
typedef struct Osal_HwAttrs_s
{
   /* CPU frequency in KHz */
   int32_t  cpuFreqKHz;
   /* External Clock value in KHz */
   int32_t  extClkKHz;
#if defined(gnu_targets_arm_A15F)
   /* Set Target processor list */
   uint32_t a15TargetProcMask;
#endif
#ifdef _TMS320C6X
   int32_t ECM_intNum[4]; /* Interrupt numbers for Event combiner groups (0-3)*/
#endif
   Osal_HwAccessType hwAccessType;
   /* Below timer base configuration is applicable for only AM335x/AM437x SoCs
    * It is not applicable and should not be set for other SoCs
    * Osal setHwAttrs API would return failure (osal_UNSUPPORTED) if attempted to
    * be set for SoCs other than AM335x and AM437x.
    */
   uintptr_t     osalDelayTimerBaseAddr;
   Osal_memRange  extSemaphorePBlock;
   Osal_memRange  extHwiPBlock;
} Osal_HwAttrs;


/*!
 * bit map to set external clock in Osal_HwAttr default value
 */
#define  OSAL_HWATTR_SET_EXT_CLK    (0x00000001U)

/*!
 * bit map to set Event combiner interrupt numbers in the Osal_HwAttr
 */
#define  OSAL_HWATTR_SET_ECM_INT      (0x00000002U)

/*!
 * bit map to set the hardware access type
 */
#define OSAL_HWATTR_SET_HWACCESS_TYPE (0x00000004U)

/*!
 * bit map to set the osal_delay Timer base address
 */
#define OSAL_HWATTR_SET_OSALDELAY_TIMER_BASE (0x00000008U)

/*!
 * bit map to set the extended SemaphoreP memory block for additional SemaphoreP needs
 */
#define OSAL_HWATTR_SET_SEMP_EXT_BASE   (0x00000010U)

/*!
 * bit map to set the extended HwiP memory block for additional HwiP needs
 */
#define OSAL_HWATTR_SET_HWIP_EXT_BASE   (0x00000020U)

/*!
 * bit map to set the CPU frequency
 */
#define OSAL_HWATTR_SET_CPU_FREQ        (0x00000040U)

/*!
 * bit map to set the target processor list to direct interrupts to specific core
 */
#define OSAL_HWATTR_SET_TARG_PROC_LIST  (0x00000080)


/*!
 *  @brief  Function to set the Hw Attributes
 *
 *  @param  ctrlBitMap control bit map as defined by the OSAL_HWATTR_SET control bits
 *
 *  @param  hwAttrs    pointer to Osal_HwAttrs structure
 *
 *  @return osal_OK for success, osal_FAILURE on failure and
 *   osal_UNSUPPORTED for unsupported configurations
 *   osal_UNSUPPORTED is a non fatal error and applications
 *   can continue processing if they get this error code.
 *   Osal would be configured to utilize default timer for
 *   Osal_delay() API. The default timer address for AM437x and
 *   AM335x SoCs are found under ti/osal/soc/'<'soc_part'>'/osal_soc.h
 *   For other SoCs the time base address is not applicable and
 *   the API returns osal_UNSUPPORTED as the return value.
 */
extern int32_t Osal_setHwAttrs(uint32_t ctrlBitMap, const Osal_HwAttrs *hwAttrs);

/*!
 *  @brief  Function to get the Hw Attributes
 *
 *  @param  hwAttrs  pointer to Osal_HwAttrs structure
 *
 *  @return osal_OK for success, osal_FAILURE on failure
 */
extern int32_t Osal_getHwAttrs(Osal_HwAttrs *hwAttrs);

/*!
 *  @brief  Function to get the static memory usage of OSAL library
 *
 *  @param  pMemStat  pointer to Osal_StaticMemStatus structure
 *
 *  @return osal_OK for success, osal_FAILURE on failure
 */
extern int32_t Osal_getStaticMemStatus(Osal_StaticMemStatus *pMemStat);

/*!
 *  @brief  Function to get the core ID of the running Core.
 *
 *  @return core ID of the running core
 */
extern int32_t Osal_getCoreId(void);

/*! 
 * @brief external references for Osal Hw Attribute structure 
 */
extern Osal_HwAttrs  gOsal_HwAttrs;

/*!
 * This macro generates compilier error if postulate is false, so 
 * allows 0 overhead compile time size check.  This "works" when
 * the expression contains sizeof() which otherwise doesn't work
 * with preprocessor */
#define OSAL_COMPILE_TIME_SIZE_CHECK(x,y)                              \
   do {                                                                 \
       struct {                                                 \
         uint8_t NegativeSizeIfPostulateFalse[(y) + 1U - (x)];         \
       } PostulateCheck;                                              \
   }                                                                   \
   while ((bool)false)

#ifdef __cplusplus
}
#endif

#endif /* ti_OSAL__include */
/* @} */
