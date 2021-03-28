/**
 *  \file   main_osal_test.c
 *
 *  \brief  OSAL driver test application main file.
 *
 */

/*
 * Copyright (C) 2016-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
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
 *
 */

#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#if defined (SOC_J721E) || defined(SOC_J7200)
// workaround for A72 does not supported in SYS/BIOS yet
#if defined (BUILD_C7X_1)
#ifndef BARE_METAL
#include <ti/sysbios/family/c7x/Hwi.h>
#endif //BARE_METAL
#endif //BUILD_C7X_1
#else
#include <xdc/cfg/global.h>
#endif
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/osal/TaskP.h>
#include <ti/osal/SwiP.h>
#endif

#include <stdio.h>
#include <string.h>

/* TI-RTOS Header files */
#include <ti/osal/osal.h>
#include "OSAL_log.h"

#include "OSAL_board.h"
/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/
#define TWO_TIMER_INTERRUPT_TEST 0
//#define QT_BUILD

#include <ti/csl/soc.h>

#if defined (__C7100__)
#include <ti/csl/csl_clec.h>
#include <ti/csl/arch/csl_arch.h>
#endif
#include <ti/csl/tistdtypes.h>
#ifdef BARE_METAL
#if !defined(SOC_TPR12)
#include <ti/csl/csl_timer.h>
#endif
#include <ti/csl/arch/csl_arch.h>

#if   defined (SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x)
#undef  TWO_TIMER_INTERRUPT_TEST
#define TWO_TIMER_INTERRUPT_TEST 1
#endif

#else
void ErrorHandler(Error_Block *eb)
{
    System_printf("ErrorHandler: ");
    Error_print(eb);
}
#endif

void Osal_appC7xPreInit(void);

#undef  ENABLE_GET_TIME_TEST
#if defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_AM572x) || defined(SOC_K2G) || defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_J7200)|| defined(SOC_TPR12)
#define ENABLE_GET_TIME_TEST     1
#endif

#ifndef NULL_PTR
#define NULL_PTR ((void *)0x0)
#endif

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
#if defined (__TI_ARM_V5__)
TimerP_Handle handle;
#endif

/*
 *  ======== Board_initOSAL ========
 */
void Board_initOSAL(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  status;
#if defined(evmK2E) || defined(evmC6678)
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#endif
    status = Board_init(boardCfg);

    if (status != BOARD_SOK)
    {
        OSAL_log(" Board_init() is not successful...unexpected results may happen \n");
    }

    return;
}


/*
 *  ======== HWI test function ========
 */
volatile   uint64_t gTestlocalTimeout = 0x300000U;

#if (defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200) || defined (SOC_TPR12)) && (!defined(BUILD_C66X_1))&&(!defined(BUILD_C66X_2))&&(!defined(BUILD_C7X_1))
#define INT_NUM_IRQ 32
#define LOOP_CNT    100
volatile uint64_t gFlagIRQ = 0;

void myIsrIRQ(uintptr_t arg)
{
    gFlagIRQ = 1;
    gTestlocalTimeout = 0x300000;
}
bool  OSAL_core_hwi_test()
{

    HwiP_Params hwiParams;
    HwiP_Handle handle;
    volatile int intCount = 0;
    int32_t ret;
    bool test_pass=true;

    HwiP_Params_init(&hwiParams);

    OSAL_log("Creating Hwi myIsr \n");
    handle = HwiP_create(INT_NUM_IRQ, myIsrIRQ, &hwiParams);
    if (handle == NULL_PTR) {
      OSAL_log("Failed to create the HwiP handle \n");
      test_pass = false;
    }

    if (test_pass == true)
    {
        while (intCount != LOOP_CNT)
        {
            ret=HwiP_post(INT_NUM_IRQ);

            if(ret==osal_UNSUPPORTED)
            { /* In case of unsupported SOC/error */
              OSAL_log("HwiP_post unsupported/failed!\n");
              test_pass=false;
              break;
            }

            /* Wait for software timeout, ISR should hit
             * otherwise return the test as failed */
            while (gTestlocalTimeout != 0U)
            {
              gTestlocalTimeout--;
              if (gFlagIRQ)
              {
                gFlagIRQ = 0;
                intCount++;
                break;
              }
            }
            /* Wait is over - did not get any interrupts posted/received
             * declare the test as fail
             */
            if (gTestlocalTimeout == 0)
            {
              OSAL_log("Failed to get interrupts \n");
              test_pass = false;
              break;
            }
        }

        OSAL_log("%d IRQs received. Test over !\n",intCount);
        ret = HwiP_delete(handle);
        if (ret != HwiP_OK)
        {
          OSAL_log(" Failed to delete HwiP handle \n");
          test_pass= false;
        }
    }

    return test_pass;
}
#endif

bool OSAL_hwi_test()
{
#if (defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200) || defined (SOC_TPR12)) && (!defined(BUILD_C66X_1))&&(!defined(BUILD_C66X_2))&&(!defined(BUILD_C7X_1))
  OSAL_core_hwi_test();
#endif
  return true;
}

typedef enum UT_Timer_Type_s {
    UT_Timer_DMTIMER = 0,
    UT_Timer_TIMER64 = 1,
    UT_Timer_RTITIMER = 2
} UT_Timer_Type_t;


#if defined(SOC_AM335x)
#define CM_PER_TIMER3_CLKCTRL             (0x44e00084)
#define CM_DPLL_CLKSEL_TIMER3_CLK         (0x44e0050c)
UT_Timer_Type_t  timer_type    =          UT_Timer_DMTIMER;
#define OSAL_TEST_TIMER_ID                (1U)
#define OSAL_TEST_TIMER_PERIOD            (5000U)
#elif defined(SOC_AM437x)
#define CM_PER_TIMER3_CLKCTRL             (0x44DF8800 + 0x538)
#define CM_DPLL_CLKSEL_TIMER3_CLK         (0x44DF4200 + 0x8)
UT_Timer_Type_t  timer_type  =            UT_Timer_DMTIMER;
#define OSAL_TEST_TIMER_ID                (3U)
#define OSAL_TEST_TIMER_PERIOD            (5000U)

#elif defined(SOC_K2E) || defined(SOC_K2L)
UT_Timer_Type_t  timer_type =             UT_Timer_TIMER64;
#define OSAL_TEST_TIMER_ID                (TimerP_ANY)
#define OSAL_TEST_TIMER_PERIOD            (5000U)
#elif defined(SOC_K2H) || defined(SOC_K2K)
UT_Timer_Type_t  timer_type =             UT_Timer_TIMER64;
#define OSAL_TEST_TIMER_ID                (8U)
#define OSAL_TEST_TIMER_PERIOD            (5000U)
#elif defined(SOC_K2G)
UT_Timer_Type_t  timer_type =             UT_Timer_TIMER64;
#define OSAL_TEST_TIMER_ID                (1U)
#define OSAL_TEST_TIMER_ID2               (2U)
#define OSAL_TEST_TIMER_PERIOD            (5000U)
#elif defined(SOC_AM572x) || defined (SOC_AM574x)
UT_Timer_Type_t  timer_type   =           UT_Timer_DMTIMER;
  #if defined (__ARM_ARCH_7A__)
    #define OSAL_TEST_TIMER_ID                (1U)
    #define OSAL_TEST_TIMER_ID2               (9U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #elif   defined (_TMS320C6X)
    #define OSAL_TEST_TIMER_ID                (4U)
    #define OSAL_TEST_TIMER_ID2               (5U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #else
    #define OSAL_TEST_TIMER_ID                (8U)
    #define OSAL_TEST_TIMER_ID2               (10U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #endif
#elif defined(SOC_AM571x)
UT_Timer_Type_t  timer_type   =           UT_Timer_DMTIMER;
  #if defined (__ARM_ARCH_7A__)
    #define OSAL_TEST_TIMER_ID                (1U)
    #define OSAL_TEST_TIMER_ID2               (9U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #elif   defined (_TMS320C6X)
    #define OSAL_TEST_TIMER_ID                (4U)
    #define OSAL_TEST_TIMER_ID2               (5U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #else
    #define OSAL_TEST_TIMER_ID                (8U)
    #define OSAL_TEST_TIMER_ID2               (10U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #endif
#elif defined(SOC_OMAPL137) || defined (SOC_OMAPL138)
UT_Timer_Type_t  timer_type =             UT_Timer_TIMER64;
#define OSAL_TEST_TIMER_ID                (1U)
#define OSAL_TEST_TIMER_PERIOD            (5000U)

#elif defined(SOC_AM65XX)
  UT_Timer_Type_t  timer_type    =          UT_Timer_DMTIMER;
  #if defined (__TI_ARM_V7R4__)
    #define OSAL_TEST_TIMER_ID                (1U)
    #define OSAL_TEST_TIMER_ID2               (2U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #else
    #define OSAL_TEST_TIMER_ID                (4U)
    #define OSAL_TEST_TIMER_ID2               (5U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #endif
#elif defined(SOC_J721E) || defined(SOC_J7200)
  UT_Timer_Type_t  timer_type    =          UT_Timer_DMTIMER;
  #if defined (__TI_ARM_V7R4__)
    #define OSAL_TEST_TIMER_ID                (1U)
    #define OSAL_TEST_TIMER_ID2               (2U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #elif defined (BUILD_C66X_1)
    #define OSAL_TEST_TIMER_ID                (2U)
    #define OSAL_TEST_TIMER_ID2               (3U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #elif defined (BUILD_C66X_2)
    #define OSAL_TEST_TIMER_ID                (2U)
    #define OSAL_TEST_TIMER_ID2               (3U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #elif defined (BUILD_C7X_1)
    #define OSAL_TEST_TIMER_ID                (1U)
    #define OSAL_TEST_TIMER_ID2               (2U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #else
    #define OSAL_TEST_TIMER_ID                (2U)
    #define OSAL_TEST_TIMER_ID2               (5U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #endif
#elif defined(SOC_TPR12)
    UT_Timer_Type_t  timer_type =           UT_Timer_RTITIMER;
#define OSAL_TEST_TIMER_ID                    (TimerP_ANY)
#if defined(QT_BUILD)
#define OSAL_TEST_TIMER_PERIOD                (500U)
#else
#define OSAL_TEST_TIMER_PERIOD                (5000U)
#endif
#else
UT_Timer_Type_t  timer_type   =           UT_Timer_DMTIMER;
  #if defined (__ARM_ARCH_7A__)
    #define OSAL_TEST_TIMER_ID                (1U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #elif   defined (_TMS320C6X)
    #define OSAL_TEST_TIMER_ID                (4U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #else
    #define OSAL_TEST_TIMER_ID                (8U)
    #define OSAL_TEST_TIMER_PERIOD            (5000U)
  #endif
#endif

#if defined(QT_BUILD)
#define      OSAL_GET_TIME_MAX_SAMPLES  (10U)
#else
#define      OSAL_GET_TIME_MAX_SAMPLES  (20U)
#endif
volatile uint32_t timerIsrCount = 0;
volatile uint32_t timerIsr2Count = 0;

#if defined (ENABLE_GET_TIME_TEST)
uint64_t     gTestTimeRd[OSAL_GET_TIME_MAX_SAMPLES];
#endif

void timerIsr(void *arg)
{
#if defined(BARE_METAL) && defined(__TI_ARM_V5__)
    TimerP_ClearInterrupt(handle);
#endif
#if defined (ENABLE_GET_TIME_TEST)
    if (timerIsrCount < OSAL_GET_TIME_MAX_SAMPLES)
    {
        gTestTimeRd[timerIsrCount] = TimerP_getTimeInUsecs();
    }
#endif
    timerIsrCount++;
}


#if    TWO_TIMER_INTERRUPT_TEST
void timerIsr2(void *arg)
{
    timerIsr2Count++;
}
#endif

/*
 * ========= Osal Delay Test function =========
 */
#if defined(QT_BUILD)
#define OSAL_DELAY_TIME         1
#else
#define OSAL_DELAY_TIME         1000
#endif
bool Osal_delay_test(void)
{
   int32_t i;
  /* This test assumes that Board init has been already
   * called outside this function
   */
   /* Notice a '.' on terminal for every 1 second */
   for (i=0; i<10;i++) {
      Osal_delay(OSAL_DELAY_TIME);
      OSAL_log(".");
   }
   OSAL_log("\n");

  return(true);
}

#if defined (ENABLE_GET_TIME_TEST)
/*
 * ========= Osal getTime Test function =========
 */
bool Osal_getTime_test(void)
{
   int32_t      i;
   bool         retVal   = true;

   OSAL_log(" \n     time read in micro seconds is \n ");
   for (i = 0; i < OSAL_GET_TIME_MAX_SAMPLES; i++)
   {
       OSAL_log(" %d \n ", (uint32_t) gTestTimeRd[i]);
   }

   return(retVal);
}
#endif

/*
 *  ======== Timer test function ========
 */
#if defined(QT_BUILD)
#define TIMER_COUNT_THRESH      10
#else
#define TIMER_COUNT_THRESH      100
#endif

bool OSAL_timer_test()
{
    TimerP_Params timerParams;
#if !defined (__TI_ARM_V5__)
    /* Timer handle is defined as global for OMAPL13x ARM9 core since
       it is required for clearing the interrupt from ISR */
    TimerP_Handle handle;
#endif

#if    TWO_TIMER_INTERRUPT_TEST
    TimerP_Handle handle2;
#endif
    TimerP_Status timerStatus;
    Osal_HwAttrs  hwAttrs;

#ifdef BARE_METAL
    int32_t       id    = OSAL_TEST_TIMER_ID;
#else
    int32_t       id    = TimerP_ANY;
#endif

#if defined(SOC_AM437x)
    /* We can't use Timer_ANY for Sys BIOS as it allocates Timer0 which is
     * firewalled on HS device and hence changing the Test Timer ID = 3 for
     * both HS and GP parts
     */
    id                  = OSAL_TEST_TIMER_ID;
#endif

#if defined(SOC_J721E) || defined(SOC_J7200)
#if !defined(BARE_METAL)
#if defined(BUILD_C66X_1) || defined(BUILD_C66X_2) || defined(BUILD_C7X_1)
    id                  = OSAL_TEST_TIMER_ID;
#endif
#endif
#endif
    volatile      int32_t i;
    uint32_t      prevCount, ctrlBitmap = OSAL_HWATTR_SET_OSALDELAY_TIMER_BASE ;
    bool          ret = true;
    int32_t       osal_ret;

#if (defined (SOC_AM437x) || defined (SOC_AM335x))
    *(unsigned int*)CM_DPLL_CLKSEL_TIMER3_CLK = 0x1; /* high frequency input clock */

    // enable the TIMER
    *(unsigned int*)CM_PER_TIMER3_CLKCTRL = 0x2; /* Module is explicitly enabled */
#endif

    /* Set the timer base for the osal delay */
    Osal_getHwAttrs(&hwAttrs);

#if defined (SOC_AM437x)
    hwAttrs.osalDelayTimerBaseAddr = (uintptr_t) 0x48040000U; /* DMTIMER2 */
#endif

#if defined (OSAL_TEST_CPU_FREQ_KHZ)
    hwAttrs.cpuFreqKHz = OSAL_TEST_CPU_FREQ_KHZ;
    ctrlBitmap        |= OSAL_HWATTR_SET_CPU_FREQ;
#endif

    /* This API should return osal_OK for AM3/AM4 and return unsupported for other Socs */
    osal_ret = Osal_setHwAttrs(ctrlBitmap, &hwAttrs);

#if defined (SOC_AM437x) || defined (SOC_AM335x)
    if (osal_ret == osal_OK) {
      ret = true;
    }
    else {
      ret = false;
    }
#else
    if ((osal_ret == osal_UNSUPPORTED) ||
       (osal_ret == osal_OK)) {
      ret = true;
    }
    else {
      ret = false;
    }
#endif /* (SOC_AM437x) || defined (SOC_AM335x) */

    TimerP_Params_init(&timerParams);
    timerParams.runMode    = TimerP_RunMode_CONTINUOUS;
    timerParams.startMode  = TimerP_StartMode_USER;
    timerParams.periodType = TimerP_PeriodType_MICROSECS;
    timerParams.period     = OSAL_TEST_TIMER_PERIOD;

#if defined(SOC_J721E) || defined(SOC_J7200)
#if defined(BUILD_C66X_1)
    /* the Eevnt 21 is used for DMTimer0 by SYS/BIOS by default, so we need to use a different one here for DMTimer2 */
	timerParams.eventId    = 22;
    /* the Interrupt 14 is used for DMTimer0 by SYS/BIOS by default, so we need to use a different one here for DMTimer2 */
    timerParams.intNum     = 15;
    OSAL_log("\n set intNum=%d, id=%d,  \n", timerParams.intNum, id);
#endif
#if defined(BUILD_C66X_2)
    /* the Eevnt 20 is used for DMTimer0 by SYS/BIOS by default, so we need to use a different one here for DMTimer2 */
	timerParams.eventId    = 22;
    /* the Interrupt 14 is used for DMTimer0 by SYS/BIOS by default, so we need to use a different one here for DMTimer2 */
    timerParams.intNum     = 15;
#endif

#if defined(BUILD_C7X_1)
    timerParams.intNum     = 15;
    OSAL_log("\n set intNum=%d, id=%d,  \n", timerParams.intNum, id);
#endif
#endif

#if !defined(SOC_J721E) || defined(SOC_J7200)
#if defined(_TMS320C6X)
    timerParams.intNum     = 15;
    OSAL_log("\n set intNum=%d, id=%d,  \n", timerParams.intNum, id);
#endif
#endif

    if (timer_type == UT_Timer_TIMER64)
    {
      timerParams.timerMode = TimerP_Timer64Mode_UNCHAINED;
      timerParams.timerHalf = TimerP_Timer64Half_LOWER;
    }
    handle = TimerP_create(id, (TimerP_Fxn)&timerIsr, &timerParams);

    /* don't expect the handle to be null */
    if (handle == NULL_PTR)
    {
      OSAL_log("\n Timer Create error \n");
      ret = false;
    }

#if defined(ENABLE_GET_TIME_TEST)
     TimerP_getTimeInUsecs();
#endif

#if    TWO_TIMER_INTERRUPT_TEST

#if (defined(_TMS320C6X) && (!defined(SOC_J721E) ))
    timerParams.intNum     = 14;
#endif

    if (ret == true)  {
      handle2 = TimerP_create(OSAL_TEST_TIMER_ID2, (TimerP_Fxn)&timerIsr2, &timerParams);
      /* don't expect the handle to be null */
      if (handle2 == NULL_PTR)
      {
        OSAL_log("\n Timer Create error for handle2 \n");
        ret = false;
      }
    }
#endif

    if (ret == true)
    {
      timerIsrCount = 0U;
      timerStatus = TimerP_start(handle);

      if (timerStatus != TimerP_OK) {
        OSAL_log("Err: Coult not start the timer %d \n", id);
        ret = false;
      }

#if    TWO_TIMER_INTERRUPT_TEST
      timerIsr2Count = 0U;
      timerStatus = TimerP_start(handle2);

      if (timerStatus != TimerP_OK) {
        OSAL_log("Err: Coult not start the timer %d \n", id + 1);
        ret = false;
      }

      while (1)
      {
        if (timerIsr2Count >= 100U) {
          timerStatus = TimerP_stop(handle2);
          if (timerStatus != TimerP_OK) {
            OSAL_log("Err: Coult not stop the timer %d \n", id);
            ret = false;
          }
          break;
        }
      }
#endif

      while (1)
      {
        if (timerIsrCount >= TIMER_COUNT_THRESH) {
          timerStatus = TimerP_stop(handle);
          if (timerStatus != TimerP_OK) {
            OSAL_log("Err: Coult not stop the timer %d \n", id);
            ret = false;
          }

          break;
        }
      }

      /* Latch the ISR count after the timer stops */
      prevCount = (timerIsrCount);

      /* Give some time for all pending interrupts to be processed */
      for(i = 0; i < 1000; i++)
      {
        asm (" nop ");
      }

      /* Now check if timer ISR gets kicked in
       * timer ISR should not be kicked in */
      if (ret == true)
      {
         for (i = 0; i < 50000; i++);

         if (prevCount != timerIsrCount)
         {
           OSAL_log(" Error: Timer appears to be not stopped via OSAL calls, val1 = %u and val2 = %u \n ", prevCount, timerIsrCount);
           ret = false;
         }
         else
         {
           OSAL_log("  TimerTestLog: got %u ticks from timer id = %d \n", timerIsrCount, id);
#if    TWO_TIMER_INTERRUPT_TEST
           OSAL_log("  TimerTestLog: got %u ticks from timer id = %d \n", timerIsr2Count, id+1);
#endif
         }
       }
    }

    if (handle != NULL_PTR)
    {
      if (TimerP_delete(handle) != TimerP_OK)
      {
        ret = false;
      }
    }
    return (ret);
}

/*
 *  ======== Clock test function ========
 */
bool OSAL_clock_test()
{
    return true;
}

#ifdef MANUAL_CACHE_TEST

#if defined (__ARM_ARCH_7A__)
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_armGicAux.h>
#elif defined (_TMS320C6X)
#include <ti/csl/csl_cacheAux.h>
#endif

#if defined (SOC_AM437x) || defined(SOC_AM335x)
#include <ti/starterware/include/chipdb.h>
#include <ti/starterware/include/armv7a/pl310.h>
#include <ti/starterware/include/armv7a/pl310_config.h>
#endif

#define BUF_LEN 256
#define LOCAL_CPU_WRITE_PATTERN_1 0xA1A1A1A1
#define LOCAL_CPU_WRITE_PATTERN_2 0xA2A2A2A2
#define LOCAL_CPU_WRITE_PATTERN_3 0xA3A3A3A3

#define ALTERNATE_CPU_WRITE_PATTERN_1 0xB1B1B1B1
#define ALTERNATE_CPU_WRITE_PATTERN_2 0xB2B2B2B2
#define ALTERNATE_CPU_WRITE_PATTERN_3 0xB3B3B3B3

#if defined (__ARM_ARCH_7A__)
uint32_t ddr_buf[BUF_LEN] __attribute__((aligned(256))); // GCC way of aligning
#elif defined (_TMS320C6X)
#pragma DATA_SECTION(ddr_buf,".cachetest_ddrbuf")
#pragma DATA_ALIGN(ddr_buf,256)
uint32_t ddr_buf[BUF_LEN];
#elif defined(__TI_ARM_V7M4__)
uint32_t ddr_buf[BUF_LEN];
#endif
void OSAL_cache_test_fill_buf(uint32_t *buf, int len,uint32_t pattern) {
  int i;
  for(i=0;i<len;i++) {
     buf[i]=pattern;
  }
}
/* Returns FALSE if all the buffer is not 'pattern'. This will read the contents though */
bool OSAL_cache_test_check_buf(uint32_t *buf, int len,uint32_t pattern) {
  int i;
  bool match=TRUE;
  for(i=0;i<len;i++) {
     if(buf[i]!=pattern) {
       match=FALSE;
     }
  }
  return(match);
}

#if defined (SOC_AM572x) || defined (SOC_AM574x)
bool OSAL_cache_test()
{

  bool match,res=TRUE;
#if defined (__ARM_ARCH_7A__)
  CSL_a15EnableCache();
#elif defined(_TMS320C6X)
    /* Enable for most of the DDR3 memory , especially the first two MAR regions where ddr_buf will reside */
    CACHE_enableCaching(128);
    CACHE_enableCaching(129);
    CACHE_setL1DSize(CACHE_L1_4KCACHE);
    CACHE_setL2Size(CACHE_1024KCACHE);
#endif
  OSAL_log("This manual cache test is a CCS based test. Please do the following\n");
  OSAL_log("1) On the local CPU open two memory windows for the address 0x%x\n: One CPU view and One Physical memory view\n",&ddr_buf[0]);
  OSAL_log("2) Connect an alternate CPU (for example if local cpu is A15, open a c66/m4 as the alternate CPU\n");
  OSAL_log("3) On the alternate CPU ( preferably a different window through (CCS->New Window)) Open the address 0x%x\n with a physical memory view\n",&ddr_buf[0]);

  OSAL_log("\n**** Forcing a read to get the buffer cached() ******\n");
  OSAL_cache_test_check_buf(ddr_buf,BUF_LEN,0); /* Checking for dummy pattern, just to force the cache read */

  OSAL_log("\n**** Testing Cache_Invalidate() ******\n");

  OSAL_log("\nWriting  0x%x local ddr memory\n",LOCAL_CPU_WRITE_PATTERN_1);
    /************************ TEST for CacheP_Inv() *********************/
    /* A15- Write LOCAL_CPU_WRITE_PATTERN_1 in to ddr_buf[0] */
    OSAL_cache_test_fill_buf(ddr_buf,BUF_LEN,LOCAL_CPU_WRITE_PATTERN_1);

    /* Check in the alternate cpu window (m4/c66x/a15) if it can see it (Physical memory). It shouldnt if cache is enabled. */
    OSAL_log("\nCheck in the alternate cpu window (m4/c66x/a15) if it can see it (Physical memory). It shouldn't appear as it is still in cache\n");

    OSAL_log("\nInvalidating cache.\n");
    /* Now OSAL_CacheInv() - Invalidates and writes back cache() */
    CacheP_Inv(ddr_buf,BUF_LEN*sizeof(uint32_t));

    OSAL_log("\nCheck in alternate cpu window (m4/c66x/a15) if it can see it (Physical memory). For A15 it should (Invalidate also writes back for A15), for others it should not \n");

    OSAL_log("\nNow write(%d 32-bit words) of pattern 0x%x on the alternate CPU physical memory window (a15/m4/c66x) \n",BUF_LEN,ALTERNATE_CPU_WRITE_PATTERN_1);
    OSAL_log("\nCheck if this pattern 0x%x has made it to the physical memory view of this cpu.It should. \n",ALTERNATE_CPU_WRITE_PATTERN_1);

#if defined(__ARM_ARCH_7A__)
    /* The below invalidate test is to account for ARM prefetching. On A15 Cache Inv writes back too. To see any changes AFTER the DDR was
    externally modified, a Cache Invalidate is required */
    CacheP_Inv(ddr_buf,BUF_LEN*sizeof(uint32_t));
#endif
    OSAL_log("\nChecking if local CPU read fetches the 0x%x value updated by the alternate cpu core\n",ALTERNATE_CPU_WRITE_PATTERN_1);
    /* Now read the value on A15 now */
    match=OSAL_cache_test_check_buf(ddr_buf,BUF_LEN,ALTERNATE_CPU_WRITE_PATTERN_1);
    if(match==TRUE) {
        OSAL_log("\nPattern matched. OSAL_CacheInv() Test passed\n");
    } else {
        OSAL_log("\n OSAL_CacheInv() Test failed\n");
    }

    /************************ TEST for CacheP_wb() *********************/
    OSAL_log("\n**** Testing Cache_WriteBack() ******\n");

    OSAL_log("\nWriting  0x%x local ddr memory\n",LOCAL_CPU_WRITE_PATTERN_2);
    /* local cpu- Write LOCAL_CPU_WRITE_PATTERN_2 in to ddr_buf[0] */
    OSAL_cache_test_fill_buf(ddr_buf,BUF_LEN,LOCAL_CPU_WRITE_PATTERN_2);

    OSAL_log("\nCheck in the alternate cpu window (m4/c66x/a15) if the pattern 0x%x can be seen it (Physical memory). It shouldn't appear as it is still in cache\n",LOCAL_CPU_WRITE_PATTERN_2);

    OSAL_log("\nWriting back cache.\n");
    /* Now OSAL_CacheWb() - Writes back cache() */
    CacheP_wb(ddr_buf,BUF_LEN*sizeof(uint32_t));

    /* Check in DSP window if it can see it (Physical memory). It should now. */
    OSAL_log("\nCheck in alternate cpu window (m4/c66x/a15) and verify that the 0x%x is seen in Physical memory\n",LOCAL_CPU_WRITE_PATTERN_2);

    /* If so, write back portion is tested. */
    OSAL_log("\nNow write the pattern 0x%x on the alternate CPU physical memory window (a15/m4/c66x) \n",ALTERNATE_CPU_WRITE_PATTERN_2);
    /* Since, on this local cpu, we just wrote back cache() only, and not invalidated, the ALTERNATE_CPU_WRITE_PATTERN_2 wont be seen in the local cpu's cached memory
       Read Variable on A15 to ensure CPU Read(). The value should be the old LOCAL_CPU_WRITE_PATTERN_2.. and NOT the ALTERNATE_CPU_WRITE_PATTERN_2.. which the alternate CPU wrote. */
    match=OSAL_cache_test_check_buf(ddr_buf,BUF_LEN,LOCAL_CPU_WRITE_PATTERN_2);
    if(match==TRUE) {
        OSAL_log("\nPattern matched. OSAL_Cache_Writeback() Test passed\n");
     } else {
        OSAL_log("\n OSAL_Cache_Writeback() Test failed\n");
     }

    /************************ TEST for CacheP_wbInv() *********************/
     OSAL_log("\n**** Testing Cache_WriteBack_Invalidate() ******\n");

     OSAL_log("\nWriting  0x%x local ddr memory\n",LOCAL_CPU_WRITE_PATTERN_3);

     /* local cpu- Write LOCAL_CPU_WRITE_PATTERN_3 in to ddr_buf[0] */
     OSAL_cache_test_fill_buf(ddr_buf,BUF_LEN,LOCAL_CPU_WRITE_PATTERN_3);

     OSAL_log("\nCheck in the alternate cpu window (m4/c66x/a15) if the pattern 0x%x can be seen it (Physical memory). It shouldn't appear as it is still in cache\n",LOCAL_CPU_WRITE_PATTERN_3);

     OSAL_log("\nWriting back cache and invalidating it.\n");

     /* Now OSAL_CacheWbInv() - Writes back cache and invalidate() */
      CacheP_wbInv(ddr_buf,BUF_LEN*sizeof(uint32_t));

      /* Check in DSP window if it can see it (Physical memory). It should now. */
      OSAL_log("\nCheck in alternate cpu window (m4/c66x/a15) and verify that the 0x%x is seen in Physical memory. If not it is a failure \n",LOCAL_CPU_WRITE_PATTERN_3);


      OSAL_log("\nNow write the pattern 0x%x on the alternate CPU physical memory window (a15/m4/c66x) \n",ALTERNATE_CPU_WRITE_PATTERN_3);

#if defined(__ARM_ARCH_7A__)
    /* This is due to ARM prefetching */
     CacheP_Inv(ddr_buf,BUF_LEN*sizeof(uint32_t));
#endif

    /* Since, on local cpu, we not only wrote back cache but also invalidated it,the local cpu should be able the alternate pattern now */
    match=OSAL_cache_test_check_buf(ddr_buf,BUF_LEN,ALTERNATE_CPU_WRITE_PATTERN_3);
    if(match==TRUE) {
        OSAL_log("\nPattern matched. OSAL_Cache_WritebackInvalidate() Test passed\n");
     } else {
        OSAL_log("\nOSAL_Cache_WritebackInvalidate() Test failed\n");
     }

     return(res);
}
#endif /* SOC_AM572x || SOC_AM574x */
#endif /* MANUAL_CACHE_TEST */

/*
 *  ======== Extended memory block test function ========
 * This test aims at testing the create and delete functions that
 * are enhanced to support extended memory blocks for SemaphoreP and HwiP
 */
#define OSAL_TEST_NUM_EXT_SEMAPHORES    (1U)
#define OSAL_TEST_NUM_EXT_HWIPS         (1U)

#if defined (BARE_METAL)
#define SEMP_BLOCK_SIZE (OSAL_TEST_NUM_EXT_SEMAPHORES * OSAL_NONOS_SEMAPHOREP_SIZE_BYTES)
#define HWIP_BLOCK_SIZE (OSAL_TEST_NUM_EXT_HWIPS * OSAL_NONOS_HWIP_SIZE_BYTES)
uint8_t semPMemBlock[SEMP_BLOCK_SIZE];
uint8_t hwiPMemBlock[HWIP_BLOCK_SIZE];
#else
#define SEMP_BLOCK_SIZE (OSAL_TEST_NUM_EXT_SEMAPHORES * OSAL_TIRTOS_SEMAPHOREP_SIZE_BYTES)
#define HWIP_BLOCK_SIZE (OSAL_TEST_NUM_EXT_HWIPS * OSAL_TIRTOS_HWIP_SIZE_BYTES)
uint8_t semPMemBlock[SEMP_BLOCK_SIZE];
uint8_t hwiPMemBlock[HWIP_BLOCK_SIZE];
#endif

static void myIsr(void)
{
}

bool OSAL_ExtBlock_test(void)
{
    SemaphoreP_Params semParams;
    HwiP_Params       hwiParams;
    Osal_HwAttrs      hwAttrs;
    int32_t           osal_ret;
    uint32_t          ctrlBitMap = ( OSAL_HWATTR_SET_SEMP_EXT_BASE |
                                     OSAL_HWATTR_SET_HWIP_EXT_BASE);
    SemaphoreP_Handle semHandle;
    HwiP_Handle       hwiHandle;

    /* Set the timer base for the osal delay */
    osal_ret = Osal_getHwAttrs(&hwAttrs);
    if (osal_ret != osal_OK)
    {
        return (false);
    }

    /* This API should return osal_OK for AM3/AM4 and return unsupported for other Socs */
    hwAttrs.extSemaphorePBlock.base = (uintptr_t) &semPMemBlock[0];
    hwAttrs.extSemaphorePBlock.size = SEMP_BLOCK_SIZE;
    hwAttrs.extHwiPBlock.size       = HWIP_BLOCK_SIZE;
    hwAttrs.extHwiPBlock.base       = (uintptr_t) &hwiPMemBlock[0];
    osal_ret = Osal_setHwAttrs(ctrlBitMap, &hwAttrs);
    if (osal_ret != osal_OK)
    {
        return (false);
    }

    /* Default parameter initialization */
    SemaphoreP_Params_init(&semParams);

    /* create the semaphore block */
    semHandle = SemaphoreP_create(0, &semParams);
    if (semHandle == (SemaphoreP_Handle) NULL_PTR)
    {
        return (false);
    }

    /* Verify the block created is in the extended memory block range */
    if (semHandle != (SemaphoreP_Handle) &semPMemBlock[0])
    {
        return(false);
    }

    /* delete the semaphore block */
    osal_ret = SemaphoreP_delete(semHandle);
    if (osal_ret != (SemaphoreP_Status) SemaphoreP_OK)
    {
        return (false);
    }


    /* Default parameter initialization */
    HwiP_Params_init(&hwiParams);

    /* create the hwi block */
    hwiHandle = HwiP_create(8, (HwiP_Fxn)myIsr, &hwiParams);
    if (hwiHandle == (HwiP_Handle) NULL_PTR)
    {
        return (false);
    }

    /* Verify the block created is in the extended memory block range */
    if (hwiHandle != (HwiP_Handle) &hwiPMemBlock[0])
    {
        return(false);
    }

    /* delete the hwi block */
    osal_ret = HwiP_delete(hwiHandle);
    if (osal_ret != (HwiP_Status) HwiP_OK)
    {
        return (false);
    }

    /* Clear the extended block base for next tests */
    /* This API should return osal_OK for AM3/AM4 and return unsupported for other Socs */
    hwAttrs.extSemaphorePBlock.base = (uintptr_t) NULL_PTR;
    hwAttrs.extSemaphorePBlock.size = 0;
    hwAttrs.extHwiPBlock.size       = 0;
    hwAttrs.extHwiPBlock.base       = (uintptr_t) NULL_PTR;
    osal_ret = Osal_setHwAttrs(ctrlBitMap, &hwAttrs);
    if (osal_ret != osal_OK)
    {
        return (false);
    }
    return(true);

}


/*
 *  ======== Semaphore test function ========
 */
bool OSAL_semaphore_test()
{
    SemaphoreP_Params semParams;
    SemaphoreP_Handle handle1, handle2;

    SemaphoreP_Params_init(&semParams);

    /* Test 1: counting mode, no timeout */
    semParams.mode = SemaphoreP_Mode_COUNTING;
    handle1 = SemaphoreP_create(0, &semParams);
    if (handle1 == NULL_PTR)
    {
        return false;
    }
    if (SemaphoreP_post(handle1) != SemaphoreP_OK)
    {
        return false;
    }
    if (SemaphoreP_pend(handle1, 0) != SemaphoreP_OK)
    {
        return false;
    }

    /* Test 2: binary mode, with timeout */
    semParams.mode = SemaphoreP_Mode_BINARY;
    handle2 = SemaphoreP_create(1, &semParams);
    if (handle2 == NULL_PTR)
    {
        return false;
    }
    if (SemaphoreP_pend(handle2, 0) != SemaphoreP_OK)
    {
        return false;
    }
    if (SemaphoreP_pend(handle2, 10) != SemaphoreP_TIMEOUT)
    {
        return false;
    }

    if (SemaphoreP_delete(handle1) != SemaphoreP_OK)
    {
        return false;
    }

    if (SemaphoreP_delete(handle2) != SemaphoreP_OK)
    {
        return false;
    }

    return true;
}

#ifndef BARE_METAL

/*
 *  ======== Queue test function ========
 */
typedef struct Test_Queue_Buf_s
{
    Osal_Queue_Elem lnk;
    uint32_t        index;
    uint8_t*        pkt;

} Test_Queue_Buf;

bool OSAL_queue_test()
{
    Osal_Queue_Elem queueList;
    Osal_Queue_Handle   handle;
    Test_Queue_Buf buf[10], *pBuf;
    int i;

    Osal_Queue_construct((void *)&queueList, (void *)NULL);
    handle = Osal_Queue_handle((void *)&queueList);

    if (handle == NULL_PTR)
    {
        OSAL_log("Failed to create queue \n");
        return false;
    }

    for (i = 0; i < 10; i++)
    {
        buf[i].index = (uint32_t)i;
        buf[i].pkt = NULL;
    }

    /* Test 1: queue push/pop test */
    for (i = 0; i < 10; i++)
    {
        Osal_Queue_put(handle, (Osal_Queue_Elem *)&buf[i]);
    }

    for (i = 0; i < 10; i++)
    {
        pBuf = (Test_Queue_Buf *)Osal_Queue_get(handle);

        if (pBuf == NULL_PTR)
        {
            OSAL_log("Failed to pop queue element %d \n", i);
            return false;
        }

        if (pBuf->index != i)
        {
            OSAL_log("Pop element %d, but expect %d \n", pBuf->index, i);
            return false;

        }
    }

    /* Test 2: queue empty test */
    if (!Osal_Queue_empty(handle))
    {
        OSAL_log("Empty queue check failed\n");
        return false;
    }

    pBuf = (Test_Queue_Buf *)Osal_Queue_get(handle);

    if (pBuf != (Test_Queue_Buf *)&queueList)
    {
        OSAL_log("Queue is still not empry with element %p handle %p queue struct %p\n", pBuf, handle, &queueList);
        return false;
    }

    return true;
}

volatile bool gFlagSwi;
void mySwiFxn(uintptr_t arg0, uintptr_t arg1)
{
    gFlagSwi = 1U;
}

bool OSAL_swi_test()
{
    SwiP_Handle handle;
    SwiP_Params swiParams;
    SwiP_Status status;
    bool        retVal = true;

    SwiP_Params_init(&swiParams);
    handle = SwiP_create((SwiP_Fxn)&mySwiFxn, &swiParams);
    if (handle == NULL_PTR)
    {
        OSAL_log("Failed to create software interrupt \n");
        retVal = false;
    }

    if (retVal == true)
    {
        gFlagSwi = 0;
        status = SwiP_post(handle);
        if (status != SwiP_OK)
        {
            OSAL_log("Failed to post software interrupt \n");
            retVal = false;
        }
    }

    if (retVal == true)
    {
        gTestlocalTimeout = 0x300000U;
        while (gTestlocalTimeout != 0U)
        {
            gTestlocalTimeout--;
            if (gFlagSwi)
            {
                gFlagSwi = 0;
                retVal = true;
                break;
            }
        }

        if (gTestlocalTimeout == 0)
        {
            OSAL_log("Failed to get software interrupt \n");
            retVal = false;
        }
    }

    if (retVal == true)
    {
        status = SwiP_delete(&handle);
        if (status != SwiP_OK)
        {
            OSAL_log("Failed to delete software interrupt \n");
            retVal = false;
        }
    }

    return (retVal);
}
#endif

/*
 *  ======== main test function ========
 */
#ifdef BARE_METAL
void osal_test()
#else
void osal_test(UArg arg0, UArg arg1)
#endif
{
    bool testFail = false;
    Osal_StaticMemStatus pMemStats;

    if(OSAL_hwi_test() == true)
    {
        OSAL_log("\n HWI tests have passed. \n");
    }
    else
    {
        OSAL_log("\n HWI tests have failed. \n");
        testFail = true;
    }

#ifdef ENABLE_TIMER_TEST
    if(OSAL_timer_test() == true)
    {
        OSAL_log("\n Timer tests have passed. \n");
    }
    else
    {
        OSAL_log("\n Timer tests have failed. \n");
        testFail = true;
    }
#endif

/* The test does not support below SoCs */
#if !defined(SOC_TDA2XX) && !defined(SOC_TDA2PX) && !defined(SOC_TDA2EX) && !defined(SOC_TDA3XX)
  OSAL_log("\n Running Osal_Delay test:");

  if(Osal_delay_test() == true)
  {
      OSAL_log("\n Osal_Delay  tests have passed. \n");
  }
  else
  {
      OSAL_log("\n Osal_Delay  tests have failed. \n");
      testFail = true;
  }
#endif

#ifdef ENABLE_GET_TIME_TEST
    OSAL_log("\n Running Osal_getTime test:");

    if(Osal_getTime_test() == true)
    {
        OSAL_log("\n Osal_getTime  tests have passed. \n");
    }
    else
    {
        OSAL_log("\n Osal_getTime  tests have failed. \n");
        testFail = true;
    }
#endif

    if(OSAL_clock_test() == true)
    {
        OSAL_log("\n Clock tests have passed. \n");
    }
    else
    {
        OSAL_log("\n Clock tests have failed. \n");
        testFail = true;
    }

    if(OSAL_semaphore_test() == true)
    {
        OSAL_log("\n Semaphore tests have passed. \n");
    }
    else
    {
        OSAL_log("\n Semaphore tests have failed. \n");
        testFail = true;
    }

#ifdef ENABLE_EXT_BLOCK_TEST

    if(OSAL_ExtBlock_test() == true)
    {
        OSAL_log("\n Extended Memory Block tests for HwiP/SwiP have passed. \n");
    }
    else
    {
        OSAL_log("\n Extended Memory Block tests for HwiP/SwiP have failed. \n");
        testFail = true;
    }
#endif

    #ifdef MANUAL_CACHE_TEST
    /* This test is valid only for MANUAL testing */
    OSAL_cache_test();
    #endif

    /* Now print the static memory statistics */
    if(Osal_getStaticMemStatus(&pMemStats) == osal_OK)
    {
       OSAL_log("\n Semaphore Statistics:     \
                 \n  PeakSemObjs    = %u,     \
                 \n  numMaxSemObjs  = %u,     \
                 \n  numFreeSemObjs = %u \n", \
                 pMemStats.peakSemObjs,       \
                 pMemStats.numMaxSemObjs,     \
                 pMemStats.numFreeSemObjs);

       OSAL_log("\n Hwi Statistics:           \
                 \n  PeakHwiObjs    = %u,     \
                 \n  numMaxHwiObjs  = %u,     \
                 \n  numFreeHwiObjs = %u \n", \
                 pMemStats.peakHwiObjs,       \
                 pMemStats.numMaxHwiObjs,     \
                 pMemStats.numFreeHwiObjs);

       OSAL_log("\n Timer Statistics:           \
                 \n  PeakTimerObjs    = %u,     \
                 \n  numMaxTimerObjs  = %u,     \
                 \n  numFreeTimerObjs = %u \n", \
                 pMemStats.peakTimerObjs,       \
                 pMemStats.numMaxTimerObjs,     \
                 pMemStats.numFreeTimerObjs);

    }
    else
    {
      testFail = true;
      OSAL_log("\n Memory Statistics query failed \n");
    }

#ifndef BARE_METAL
    if(OSAL_swi_test() == true)
    {
        OSAL_log("\n SWI tests have passed. \n");
    }
    else
    {
        OSAL_log("\n SWI tests have failed. \n");
        testFail = true;
    }

    if(OSAL_queue_test() == true)
    {
        OSAL_log("\n Queue tests have passed. \n");
    }
    else
    {
        OSAL_log("\n Queue tests have failed. \n");
        testFail = true;
    }
#endif

    if(testFail == true)
    {
        OSAL_log("\n Some tests have failed. \n");
    }
    else
    {
        OSAL_log("\n All tests have passed. \n");
    }

#ifdef BARE_METAL
    while (1)
    {
    }
#endif

}

#ifdef BUILD_C7X_1
void sysIdleLoop(void)
{
   __asm(" IDLE");
}

#include <ti/sysbios/family/c7x/Hwi.h>
#include <ti/csl/csl_clec.h>
void C7x_ConfigureTimerOutput()
{
    CSL_ClecEventConfig   cfgClec;
    CSL_CLEC_EVTRegs     *clecBaseAddr = (CSL_CLEC_EVTRegs*)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;

    uint32_t input         = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_TIMER0_INTR_PEND_0 + 992; /* Used for Timer Interrupt */
    uint32_t corepackEvent = 14;

    /* Configure CLEC */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = TRUE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_CPU_ALL;
    cfgClec.extEvtNum         = 0;
    cfgClec.c7xEvtNum         = corepackEvent;
    CSL_clecConfigEvent(clecBaseAddr, input, &cfgClec);

    input         = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_TIMER1_INTR_PEND_0 + 992; /* Used for Timer Interrupt */
    corepackEvent = 15;

    /* Configure CLEC */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = TRUE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_CPU_ALL;
    cfgClec.extEvtNum         = 0;
    cfgClec.c7xEvtNum         = corepackEvent;
    CSL_clecConfigEvent(clecBaseAddr, input, &cfgClec);
}

#endif

#if defined(BUILD_C66X_1) || defined(BUILD_C66X_2)
/* To set C66 timer interrupts on J7ES VLAB */
void C66xTimerInterruptInit(void)
{
    /*
     * The C66 INTR_ROUTER on J7ES VLAB is not directly addressable by the
     * C66 core itself, so we need to use the RAT.
     *
     * RAT is hard-coded at 0x07ff0000 for J7ES C66.  Choose an arbitrary
     * RAT entry (2nd entry) at offset 0x30.  Region entries start at 0x20.
     */
    volatile int *RAT = (volatile int *)0x07ff0030;
    /* Choose an arbitrary virtual address for intr_router RAT mapping */
    volatile int *intr_router = (volatile int *)0x20000000;

    /* program virtual address to REGION_BASE */
    RAT[1] = (int)intr_router;
    /* program C66_0 INTR_ROUTER physical addr to REGION_TRANS_L */
#ifdef BUILD_C66X_1
    RAT[2] = 0x00ac0000;
#endif
#ifdef BUILD_C66X_2
    RAT[2] = 0x00ad0000;
#endif
    /* enable region and set size to 512 B */
    RAT[0] = 0x80000009;

    /*
     * intr_router[12] corresponds to output event #21, which is what we
     * set eventId to in .cfg file.
     *     - bit 16 enables the entry
     *     - lower bits define input event (#1 for dmtimer #0)
     * intr_router[13] corresponds to output event #22, which is what we
     * set eventId to in this file.
     *     - bit 16 enables the entry
     *     - lower bits define input event (#3 for dmtimer #2)
     */
#ifdef BUILD_C66X_1
    intr_router[12] = 0x00010001;
    intr_router[13] = 0x00010003;
#endif
    /*
     * intr_router[11] corresponds to output event #20, which is what we
     * set eventId to in .cfg file.
     *     - bit 16 enables the entry
     *     - lower bits define input event (#1 for dmtimer #0)
     * intr_router[13] corresponds to output event #22, which is what we
     * set eventId to in this file.
     *     - bit 16 enables the entry
     *     - lower bits define input event (#3 for dmtimer #2)
     */
#ifdef BUILD_C66X_2
    intr_router[11] = 0x00010001;
    intr_router[13] = 0x00010003;
#endif
}

void sysIdleLoop(void)
{
   __asm(" IDLE");
}

#endif

/*
 *  ======== main ========
 */
int main(void)
{
#if defined(BUILD_C66X_1) || defined(BUILD_C66X_2)
/* To set C66 timer interrupts on J7ES VLAB */
    C66xTimerInterruptInit();
#endif

    Osal_appC7xPreInit();

#ifdef BUILD_C7X_1
    C7x_ConfigureTimerOutput();
#endif

    Board_initOSAL();

#ifdef BARE_METAL
    osal_test();
#else
    /* All other platforms have the task created under RTSC cfg file
     * hence not needed to be created again as below
     * For AM65XX TPR12 and J7 the common RTSC cfg file is used and hence there is
     * no test application specific task is created in teh RTSC cfg file
     */
#if defined (SOC_AM65XX) || defined (SOC_J721E) || defined(SOC_J7200) || defined(SOC_TPR12)
    TaskP_Params taskParams;
    Error_Block  eb;
    TaskP_Params_init(&taskParams);
    taskParams.pErrBlk = &eb;
    System_printf("Creating Task \n");
    TaskP_create(osal_test, &taskParams);
#endif
    /* Start BIOS */
    BIOS_start();
#endif
    return (0);
}

#if defined(BUILD_MPU) || defined (__C7100__)
extern void Osal_initMmuDefault(void);
void InitMmu(void)
{
    Osal_initMmuDefault();
}
#endif

void Osal_appC7xPreInit(void)
{
#if defined (__C7100__)
    CSL_ClecEventConfig cfgClec;
    CSL_CLEC_EVTRegs   *clecBaseAddr = (CSL_CLEC_EVTRegs*) CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;
    uint32_t            i, maxInputs = 2048U;

    /* make secure claim bit to FALSE so that after we switch to non-secure mode
     * we can program the CLEC MMRs
     */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = FALSE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_DISABLE;
    cfgClec.extEvtNum         = 0U;
    cfgClec.c7xEvtNum         = 0U;
    for(i = 0U; i < maxInputs; i++)
    {
        CSL_clecConfigEvent(clecBaseAddr, i, &cfgClec);
    }
#endif

    return;
}
