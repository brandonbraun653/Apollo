/**
 *   @file  timer_test.c
 *
 *   @brief   
 *      This is the Example test code for the TIMER CSL Functional layer.
 *      The code also uses utilizes the INTC CSL functional layer to determine
 *      if the timers are functioning properly. 
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2008, 2009 Texas Instruments, Inc.
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

#include <stdio.h>
#include <string.h>
#include <ti/csl/csl_tmr.h>
#include <ti/csl/csl_tmrAux.h>
#include <ti/csl/src/intc/csl_intc.h>
#include <ti/csl/src/intc/csl_intcAux.h>

/**********************************************************************
 ************************** Local Definitions *************************
 **********************************************************************/

/* Maximum delay to wait for to detect spurious interrupts. */
#define  MAX_DELAY                  0xFFFF

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Global Handle which keeps track of the WATCH-DOG Timer. */
CSL_TmrHandle   wdTmr;

/* INTC Objects */ 
CSL_IntcObj                  tmrIntcObj;
CSL_IntcContext              context;
CSL_IntcEventHandlerRecord   EventHandler[30];

/* Global Variable for the INTC Module; useful for debugging. */
CSL_IntcRegsOvly    gIntcRegisters    = (CSL_IntcRegsOvly)CSL_CGEM0_5_REG_BASE_ADDRESS_REGS;

/* Counter for Timer ISR */
volatile Int32 timerISRCounter = 0;

/**********************************************************************
 ************************ TIMER TEST FUNCTIONS ************************
 **********************************************************************/

/**
 *  @b Description
 *  @n  
 *      This is the Timer ISR handler which is invoked when the timer expires
 *
 *  @param[in]  arg
 *      Event ID which caused the ISR to be invoked.
 *
 *  @retval
 *      Not Applicable.
 */
static void TimerInterruptHandler (void *arg)
{
    /* Increment the number of interrupts detected. */
    timerISRCounter++;

    /* Clear the event ID. */
    CSL_intcEventClear((CSL_IntcEventId)arg);
}

/**
 *  @b Description
 *  @n  
 *      This is the Watch Dog ISR handler which is invoked when the Watch Dog 
 *      timer expires. 
 *
 *  @param[in]  arg
 *      Event ID which caused the ISR to be invoked.
 *
 *  @retval
 *      Not Applicable.
 */
static void WatchDogTimerHandler (void *arg)
{
    Uint16  loadVal;

    /* Increment the number of interrupts detected. */
    timerISRCounter++;

    /* Watchdog timer service key1 */
    loadVal = CSL_TMR_WDTCR_WDKEY_CMD1;
    CSL_tmrHwControl(wdTmr, CSL_TMR_CMD_LOAD_WDKEY, (Uint16 *)&loadVal);
                               
    /* Watchdog timer service key2 */
    loadVal = CSL_TMR_WDTCR_WDKEY_CMD2;
    CSL_tmrHwControl(wdTmr, CSL_TMR_CMD_LOAD_WDKEY, (Uint16 *)&loadVal);

    /* Clear the event ID. */
    CSL_intcEventClear((CSL_IntcEventId)arg);
}

/**
 *  @b Description
 *  @n  
 *      The functions initializes the INTC module.
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static Int32 intc_init (void)
{
    CSL_IntcGlobalEnableState   state;

    /* INTC module initialization */
    context.eventhandlerRecord = EventHandler;
    context.numEvtEntries      = 10;
    if (CSL_intcInit(&context) != CSL_SOK) 
        return -1;

    /* Enable NMIs */
    if (CSL_intcGlobalNmiEnable() != CSL_SOK) 
        return -1;
 
    /* Enable global interrupts */
    if (CSL_intcGlobalEnable(&state) != CSL_SOK) 
        return -1;

    /* INTC has been initialized successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      This funtion is used to test the LO Timer. 
 *
 *  @param[in]  IntcInstance
 *      Timer Instance Number 
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static Int32 test_lo_single_shot_timer (Uint8 IntcInstance)
{
    CSL_TmrHandle               hTmr;
    CSL_TmrObj                  TmrObj;
    CSL_Status                  intStat, status;
    CSL_TmrHwSetup              hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_IntcEventHandlerRecord  EventRecord;
    CSL_IntcParam               vectId;
    Uint32                      LoadValue = 100;
    CSL_IntcHandle              tmrIntcHandle;
    CSL_TmrEnamode              TimeCountMode = CSL_TMR_ENAMODE_ENABLE;
    Uint32                      count;

    /* Clear local data structures */
    memset(&TmrObj, 0, sizeof(CSL_TmrObj));
    printf("Debug: Testing Low Timer (Unchained) in Single Shot Mode...\n");

    /**************************************************************
     ********************** INTC related code *********************
     **************************************************************/
     
    /* Open INTC */
    vectId = CSL_INTC_VECTID_12;
    tmrIntcHandle = CSL_intcOpen(&tmrIntcObj, CSL_GEM_TINTLN, &vectId, &intStat);
    if (tmrIntcHandle == NULL)
        return -1;
 
    /* Bind ISR to Interrupt */
    EventRecord.handler = (CSL_IntcEventHandler)&TimerInterruptHandler;
    EventRecord.arg     = (void *)CSL_GEM_TINTLN;
    CSL_intcPlugEventHandler(tmrIntcHandle, &EventRecord);

    /* Event Enable */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTENABLE, NULL);
 
    /**************************************************************
     ********************** Timer related code ********************
     **************************************************************/
   
    /* Open the timer. */ 
    hTmr =  CSL_tmrOpen(&TmrObj, IntcInstance, NULL, &status);
    if (hTmr == NULL)
        return -1;

    /* Open the timer with the defaults. */
    CSL_tmrHwSetup(hTmr, &hwSetup);

    /* Stop the Timer */
    status = CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET_TIMLO, NULL);
    
    /* Set the timer mode to unchained dual mode */
    hwSetup.tmrTimerMode = CSL_TMR_TIMMODE_DUAL_UNCHAINED;
    CSL_tmrHwSetup(hTmr, &hwSetup);

    /* Reset the timer ISR Counter. */
    timerISRCounter = 0;

    /* Load the period register */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_LOAD_PRDLO, (void *)&LoadValue);

    /* Start the timer with one shot */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_START_TIMLO, (void *)&TimeCountMode);

    /* INTC related code */
    while (timerISRCounter != 1);

    /* Good. The timer ISR was invoked; now we wait for some time and make
     * sure that the ISR was not invoked again since this is a ONE SHOT
     * Timer. */
    for (LoadValue = 0; LoadValue < MAX_DELAY; LoadValue++);

    /* Timer ISR Counter should still be the same */
    if (timerISRCounter != 1)
        return -1;

    /* Also the LOW Count Register should remain at the value 0. */
    CSL_tmrGetTimLoCount(hTmr, &count);
    if (count != 0)
        return -1;
 
    /**************************************************************/

    /* Disable the interrupts. */    
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTDISABLE, NULL);
      
    /* Stop the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET_TIMLO, NULL);

    /* Close the Timer and Interrupt Handles. */
    CSL_tmrClose(hTmr);
    CSL_intcClose(tmrIntcHandle);    
 
    /* Test has been completed successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      This function is used to test the HI Timer in Single Shot Mode
 *
 *  @param[in]  IntcInstance
 *      Timer Instance Number 
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static Int32 test_high_single_shot_timer (Uint8 IntcInstance)
{
    CSL_TmrHandle               hTmr;
    CSL_TmrObj                  TmrObj;
    CSL_Status                  status;
    CSL_TmrHwSetup              hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_IntcEventHandlerRecord  EventRecord;
    CSL_IntcParam               vectId;
    CSL_IntcHandle              tmrIntcHandle;
    Uint32                      LoadValue = 100;    
    CSL_TmrEnamode              TimeCountMode = CSL_TMR_ENAMODE_ENABLE;
    Uint32                      count;

    /* Clear local data structures */
    memset(&TmrObj, 0, sizeof(CSL_TmrObj));
    printf("Debug: Testing High Timer (Unchained) in Single Shot Mode...\n");
    
    /**************************************************************
     ********************** INTC related code *********************
     **************************************************************/
     
    /* Open INTC */
    vectId = CSL_INTC_VECTID_13;
    tmrIntcHandle = CSL_intcOpen(&tmrIntcObj, CSL_GEM_TINTHN, &vectId, NULL);
    if (tmrIntcHandle == NULL)
        return -1;
   
    /* Bind ISR to Interrupt */
    EventRecord.handler = (CSL_IntcEventHandler)&TimerInterruptHandler;
    EventRecord.arg     = (void *)CSL_GEM_TINTLN;
    CSL_intcPlugEventHandler(tmrIntcHandle, &EventRecord);
  
    /* Event Enable */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTENABLE, NULL);
       
    /**************************************************************
     ********************** Timer related code ********************
     **************************************************************/
   
    /* Open the timer. */  
    hTmr =  CSL_tmrOpen(&TmrObj, IntcInstance, NULL, &status);
    if (hTmr == NULL) 
        return -1;

    /* Open the timer with the defaults. */
    CSL_tmrHwSetup(hTmr, &hwSetup);

    /* Stop the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET_TIMHI, NULL);
 
    /* Set the timer mode to unchained dual mode */
    hwSetup.tmrTimerMode = CSL_TMR_TIMMODE_DUAL_UNCHAINED;
    CSL_tmrHwSetup(hTmr, &hwSetup);
   
    /* Reset the timer ISR Counter. */
    timerISRCounter = 0;
    
    /* Load the period register */
    status = CSL_tmrHwControl(hTmr, CSL_TMR_CMD_LOAD_PRDHI, (void *)&LoadValue);

    /* Start the timer in SINGLE SHOT Mode. */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_START_TIMHI, (void *)&TimeCountMode);
     
    /* Wait for the timer interrupts to fire...*/
    while (timerISRCounter != 1);

    /* Good. The timer ISR was invoked; now we wait for some time and make
     * sure that the ISR was not invoked again since this is a ONE SHOT
     * Timer. */
    for (LoadValue = 0; LoadValue < MAX_DELAY; LoadValue++);

    /* Timer ISR Counter should still be the same */
    if (timerISRCounter != 1)
        return -1;

    /* Also the HIGH Count Register should remain at the value 0. */
    CSL_tmrGetTimHiCount(hTmr, &count);
    if (count != 0)
        return -1;

    /**************************************************************/
   
    /* Disable the events. */ 
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTDISABLE, NULL);
     
    /* Stop the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET_TIMHI, NULL);
    
    /* Close the Tmr and Interrupt handles. */
    CSL_tmrClose(hTmr);
    CSL_intcClose(tmrIntcHandle);

    /* Test has completed successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      This function is used to test the HI Timer in Continuous Mode
 *
 *  @param[in]  IntcInstance
 *      Timer Instance Number 
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static Int32 test_high_continuous_timer (Uint8 IntcInstance)
{
    CSL_TmrHandle               hTmr;
    CSL_TmrObj                  TmrObj;
    CSL_Status                  status;
    CSL_TmrHwSetup              hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_IntcEventHandlerRecord  EventRecord;
    CSL_IntcParam               vectId;
    CSL_IntcHandle              tmrIntcHandle;
    Uint32                      LoadValue = 1000;
    CSL_TmrEnamode              TimeCountMode = CSL_TMR_ENAMODE_CONT;
    Uint32                      count;

    /* Clear local data structures */
    memset(&TmrObj, 0, sizeof(CSL_TmrObj));
    printf("Debug: Testing High Timer (Unchained) in Continuous Mode....\n");
    
    /**************************************************************
     ********************** INTC related code *********************
     **************************************************************/
     
    /* Open INTC */
    vectId = CSL_INTC_VECTID_13;
    tmrIntcHandle = CSL_intcOpen(&tmrIntcObj, CSL_GEM_TINTHN, &vectId, NULL);
    if (tmrIntcHandle == NULL)
        return -1;
   
    /* Bind ISR to Interrupt */
    EventRecord.handler = (CSL_IntcEventHandler)&TimerInterruptHandler;
    EventRecord.arg     = (void *)CSL_GEM_TINTLN;
    CSL_intcPlugEventHandler(tmrIntcHandle, &EventRecord);
  
    /* Event Enable */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTENABLE, NULL);
       
    /**************************************************************
     ********************** Timer related code ********************
     **************************************************************/
   
    /* Open the timer. */  
    hTmr =  CSL_tmrOpen(&TmrObj, IntcInstance, NULL, &status);
    if (hTmr == NULL) 
        return -1;

    /* Open the timer with the defaults. */
    CSL_tmrHwSetup(hTmr, &hwSetup);

    /* Stop the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET_TIMHI, NULL);
     
    /* Set the timer mode to unchained dual mode */
    hwSetup.tmrTimerMode = CSL_TMR_TIMMODE_DUAL_UNCHAINED;
    CSL_tmrHwSetup(hTmr, &hwSetup);
   
    /* Reset the timer ISR Counter. */
    timerISRCounter = 0;
    
    /* Load the period register */
    status = CSL_tmrHwControl(hTmr, CSL_TMR_CMD_LOAD_PRDHI, (void *)&LoadValue);

    /* Start the timer in CONTINUOUS Mode. */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_START_TIMHI, (void *)&TimeCountMode);
     
    /* Wait for the timer interrupts to fire...*/
    while (timerISRCounter <= 5);

    /* Since the HIGH Counter is operating in Continuous Mode; the value here should
     * be non-zero. Though there is a small probability that the value here could be 0. */
    CSL_tmrGetTimHiCount(hTmr, &count);
    if (count == 0)
    {
        /* Taking into account the small probability; lets confirm out again. 
         * This time for sure the value should be non-zero. */
        CSL_tmrGetTimHiCount(hTmr, &count);
        if (count == 0)
            return -1;
    }

    /**************************************************************/
   
    /* Disable the events. */ 
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTDISABLE, NULL);
     
    /* Stop the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET_TIMHI, NULL);
    
    /* Close the Tmr and Interrupt handles. */
    CSL_tmrClose(hTmr);
    CSL_intcClose(tmrIntcHandle);

    /* Test has completed successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      This function is used to test the timers while operating in CHAINED mode.
 *
 *  @param[in]  IntcInstance
 *      Timer Instance Number 
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static Int32 test_chained_timer (Uint8 IntcInstance)
{
    CSL_TmrHandle               hTmr;        
    CSL_TmrObj                  TmrObj;
    CSL_Status                  status;
    CSL_IntcEventHandlerRecord  EventRecord;
    CSL_IntcHandle              tmrIntcHandle;    
    CSL_IntcParam               vectId;
    Uint32                      LoadValue = 100;
    Uint32                      LoadValue1 = 0;
    Uint8                       preScalValue = 0;
    CSL_TmrHwSetup              hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_TmrEnamode              TimeCountMode = CSL_TMR_ENAMODE_ENABLE;   

    /* Clear local data structures */
    memset(&TmrObj, 0, sizeof(CSL_TmrObj));
    printf("Debug: Testing Timer (Chained) in Single Shot Mode....\n");
    
    /**************************************************************
     ********************** INTC related code *********************
     **************************************************************/

    /* Open INTC */
    vectId = CSL_INTC_VECTID_12;
    tmrIntcHandle = CSL_intcOpen(&tmrIntcObj, CSL_GEM_TINTLN, &vectId, NULL);
    if (tmrIntcHandle == NULL)
        return -1;
       
    /* Bind ISR to Interrupt */
    EventRecord.handler = (CSL_IntcEventHandler)&TimerInterruptHandler;
    EventRecord.arg     = (void *)CSL_GEM_TINTLN;
    CSL_intcPlugEventHandler(tmrIntcHandle, &EventRecord);
    
    /* Event Enable */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTENABLE, NULL);
     
    /**************************************************************
     ********************** Timer related code ********************
     **************************************************************/

    /* Open the timer. */
    hTmr =  CSL_tmrOpen(&TmrObj, IntcInstance, NULL, &status);
    if (hTmr == NULL) 
        return -1;

    /* Open the timer with the defaults. */
    CSL_tmrHwSetup(hTmr, &hwSetup);
       
    /* Reset the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET64, NULL);

    /* Set the timer mode to dual chained mode */
    hwSetup.tmrTimerMode = CSL_TMR_TIMMODE_DUAL_CHAINED;
    CSL_tmrHwSetup(hTmr, &hwSetup);

    /* Reset the timer ISR Counter. */
    timerISRCounter = 0;
 
    /* Load the prescale value */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_LOAD_PSCHI, (void *)&preScalValue);

    /* Load the period register */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_LOAD_PRDLO, (void *)&LoadValue);

    /* Load the period register */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_LOAD_PRDHI, (void *)&LoadValue1);
 
    /* Start the timer with SINGLE SHOT Mode. */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_START64, (void *)&TimeCountMode);

    /* Wait for the timer interrupts to fire...*/
    while (timerISRCounter != 1);

    /* Good. The timer ISR was invoked; now we wait for some time and make
     * sure that the ISR was not invoked again since this is a ONE SHOT
     * Timer. */
    for (LoadValue = 0; LoadValue < MAX_DELAY; LoadValue++);

    /* Timer ISR Counter should still be the same */
    if (timerISRCounter != 1)
        return -1;

    /**************************************************************/
 
    /* Disable the events. */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTDISABLE, NULL);
    
    /* Stop the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET64, NULL);

    /* Close the Tmr and interrupt handles */
    CSL_tmrClose(hTmr);
    CSL_intcClose(tmrIntcHandle);

    /* Test has completed successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      This function is used to test the General Purpose Timer.
 *
 *  @param[in]  IntcInstance
 *      Timer Instance Number 
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static Int32 test_gp_timer (Uint8 IntcInstance)
{
    CSL_IntcHandle              tmrIntcHandle;        
    CSL_TmrHandle               hTmr;        
    CSL_TmrObj                  TmrObj;
    CSL_IntcEventHandlerRecord  EventRecord;
    CSL_IntcParam               vectId;
    CSL_Status                  status;    
    CSL_TmrHwSetup              hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_TmrEnamode              TimeCountMode = CSL_TMR_ENAMODE_ENABLE;
    Uint32                      delayCount;

    /* Clear local data structures */
    memset(&TmrObj, 0, sizeof(CSL_TmrObj));
    printf("Debug: Testing 64bit Timer in Single Shot Mode...\n");
    
    /**************************************************************
     ********************** INTC related code *********************
     **************************************************************/
  
    /* Open INTC */
    vectId = CSL_INTC_VECTID_12;
    tmrIntcHandle = CSL_intcOpen(&tmrIntcObj, CSL_GEM_TINTLN, &vectId, NULL);

    /* Bind ISR to Interrupt */
    EventRecord.handler = (CSL_IntcEventHandler)&TimerInterruptHandler;
    EventRecord.arg     = (void *)CSL_GEM_TINTLN;
    CSL_intcPlugEventHandler(tmrIntcHandle, &EventRecord);
    
    /* Event Enable */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTENABLE, NULL);

    /**************************************************************
     ********************** Timer related code ********************
     **************************************************************/

    /* Open the timer. */
    hTmr = CSL_tmrOpen(&TmrObj, IntcInstance, NULL, &status); 
    if (hTmr == NULL)
        return -1;

    /* Set the timer mode to 64bit GP Timer Mode and set the PRD registers */
    hwSetup.tmrTimerMode     = CSL_TMR_TIMMODE_GPT;
    hwSetup.tmrTimerPeriodLo = 0x0f;
    hwSetup.tmrTimerPeriodHi = 0x00;
    CSL_tmrHwSetup(hTmr, &hwSetup);

    /* Reset the timer ISR Counter. */
    timerISRCounter = 0;
 
    /* Reset the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET64, NULL);
 
    /* Start the timer in SINGLE SHOT Mode. */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_START64, (void *)&TimeCountMode);

    /* INTC related code */
    while (timerISRCounter != 1);

    /* Good. The timer ISR was invoked; now we wait for some time and make
     * sure that the ISR was not invoked again since this is a ONE SHOT
     * Timer. */
    for (delayCount = 0; delayCount < MAX_DELAY; delayCount++);

    /* Timer ISR Counter should still be the same */
    if (timerISRCounter != 1)
        return -1;
    
    /**************************************************************/
 
    /* Disable the interrupts. */ 
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTDISABLE, NULL);

    /* Stop the Timer */
    CSL_tmrHwControl(hTmr, CSL_TMR_CMD_RESET64, NULL);

    /* Close the Tmr and interrupt handles */
    CSL_tmrClose(hTmr);
    CSL_intcClose(tmrIntcHandle);

    /* Test has been completed successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      This function is used to test the timer in watchdog mode.
 *
 *  @param[in]  IntcInstance
 *      Timer Instance Number 
 *
 *  @retval
 *      Success -   0
 *  @retval
 *      Error   -   <0
 */
static Int32 test_wd_timer (Uint8 IntcInstance)
{
    CSL_IntcHandle              tmrIntcHandle;        
    CSL_TmrObj                  TmrObj;
    CSL_Status                  status;
    CSL_IntcParam               vectId;
    CSL_IntcEventHandlerRecord  EventRecord;
    Uint16                      loadVal;
    CSL_TmrHwSetup              hwSetup = CSL_TMR_HWSETUP_DEFAULTS;
    CSL_TmrEnamode              TimeCountMode = CSL_TMR_ENAMODE_CONT;

    /* Clear local data structures */
    memset(&TmrObj, 0, sizeof(CSL_TmrObj));
    printf("Debug: Testing Watch Dog Timer...\n");

    /**************************************************************
     ********************** INTC related code *********************
     **************************************************************/
    
    /* Open INTC */
    vectId = CSL_INTC_VECTID_12;
    tmrIntcHandle = CSL_intcOpen(&tmrIntcObj, CSL_GEM_TINTLN, &vectId, NULL);
    if (tmrIntcHandle == NULL)
        return -1;
       
    /* Bind ISR to Interrupt */
    EventRecord.handler = (CSL_IntcEventHandler)&WatchDogTimerHandler;
    EventRecord.arg     = (void *)CSL_GEM_TINTLN;
    CSL_intcPlugEventHandler(tmrIntcHandle, &EventRecord);
    
    /* Event Enable */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTENABLE, NULL);
     
    /**************************************************************/

    /* Open the timer. */
    wdTmr = CSL_tmrOpen(&TmrObj, IntcInstance, NULL, &status);
    if (wdTmr == NULL) 
        return -1;

    /* Set the timer mode to WATCHDOG mode */
    hwSetup.tmrTimerMode    = CSL_TMR_TIMMODE_WDT;
    hwSetup.tmrPulseWidthLo = CSL_TMR_PWID_THREECLKS;
    hwSetup.tmrClksrcLo     = CSL_TMR_CLKSRC_INTERNAL;
    hwSetup.tmrClockPulseLo = CSL_TMR_CP_PULSE;
    hwSetup.tmrClockPulseHi = CSL_TMR_CP_PULSE; 
    hwSetup.tmrIpGateLo     = CSL_TMR_CLOCK_INP_NOGATE;
        
    /* load the PRDLO */
    hwSetup.tmrTimerPeriodLo = 0x100;

    /* load the PRDHI */
    hwSetup.tmrTimerPeriodHi = 0x0;

    /* Configure the timer. */
    CSL_tmrHwSetup(wdTmr, &hwSetup);

    /* Reset the timer ISR counter. */
    timerISRCounter = 0;

    /* Reset the Timer */
    CSL_tmrHwControl(wdTmr, CSL_TMR_CMD_RESET64, NULL);

    /* Start the timer in CONTINUOUS Mode. */
    CSL_tmrHwControl(wdTmr, CSL_TMR_CMD_START_WDT, (void *)&TimeCountMode);
                               
    /* Watchdog timer service key1 */
    loadVal = CSL_TMR_WDTCR_WDKEY_CMD1;
    CSL_tmrHwControl(wdTmr, CSL_TMR_CMD_LOAD_WDKEY, (Uint16 *)&loadVal);
 
    /* Watchdog timer service key2 */
    loadVal = CSL_TMR_WDTCR_WDKEY_CMD2;
    CSL_tmrHwControl(wdTmr, CSL_TMR_CMD_LOAD_WDKEY, (Uint16 *)&loadVal);

    /* Wait for the timer interrupts to fire; since the watchdog timers run continuously
     * we wait for at least 5 interrupts to fire... */
    while (timerISRCounter != 5);

    /**************************************************************/

    /* Disable the events. */
    CSL_intcHwControl(tmrIntcHandle, CSL_INTC_CMD_EVTDISABLE, NULL);
    
    /* Close the Tmr and interrupt handles */
    CSL_tmrClose(wdTmr);
    CSL_intcClose(tmrIntcHandle);

    /* Test has completed successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      Entry point for the test code.
 *
 *  @retval
 *      Not Applicable.
 */
void main (void)
{    
    printf ("**************************************************\n");
    printf ("****************** Timer Testing  ****************\n");
    printf ("**************************************************\n");

    /* Initialize the INTC Module. */
    if (intc_init() < 0)
    {
        printf ("Error: Initialization of the INTC module failed\n");
        return;
    }

    /* Initialize timer CSL module */
    CSL_tmrInit(NULL);

    /* Start the testing for the LOW Timer. */
    if (test_lo_single_shot_timer(CSL_TMR_0) < 0)
    {
        printf("Error: Testing Low Timer (Unchained) in Single Shot Mode FAILED\n");
        return;
    }
    printf("Debug: Testing Low Timer (Unchained) in Single Shot Mode Passed\n");

    /* Start the testing for the High Timer. */
    if (test_high_single_shot_timer(CSL_TMR_0) < 0)
    {
        printf("Error: Testing High Timer (Unchained) in Single Shot Mode FAILED\n");
        return;
    }
    printf("Debug: Testing High Timer (Unchained) in Single Shot Mode Passed\n");

    /* Start the testing for the High Timer in Continuous Mode. */
    if (test_high_continuous_timer(CSL_TMR_0) < 0)
    {
        printf("Error: Testing High Timer (Unchained) in Continuous Mode FAILED\n");
        return;
    }
    printf("Debug: Testing High Timer (Unchained) in Continuous Mode Passed\n");

    /* Start the testing for the 64bit General Purpose Timer. */
    if (test_gp_timer(CSL_TMR_0) < 0)
    {
        printf("Error: Testing 64bit Timer in Single Shot Mode FAILED\n");
        return;
    }
    printf("Debug: Testing 64bit Timer in Single Shot Mode Passed\n");
 
    /* Start the testing for the the timers in Chained Mode. */
    if (test_chained_timer(CSL_TMR_0) < 0)
    {
        printf("Error: Testing Timer (Chained) in Single Shot Mode FAILED\n");
        return;
    }
    printf("Debug: Testing Timer (Chained) in Single Shot Mode Passed\n");

    /* Start the testing for Watch Dog. */
    if (test_wd_timer(CSL_TMR_0) < 0)
    {
        printf("Error: Testing Watch Dog Timer FAILED\n");
        return;
    }
    printf("Debug: Testing Watch Dog Timer Passed\n");

    /* All the timer tests have passed. */
    printf ("**************************************************\n");
    printf ("************* Timer Testing Successful ***********\n");
    printf ("**************************************************\n");

    return; 
}


