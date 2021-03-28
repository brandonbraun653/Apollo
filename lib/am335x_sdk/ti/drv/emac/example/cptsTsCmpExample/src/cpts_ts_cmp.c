/**  
 * @file cpts_ts_cmp.c
 *
 *   @n This examples demonstrates how to use of CPTS CSL APIs to trigger the CPTS 
 *      Timestamp Compare events, generate TS_COMP output pluses and/or adjust the 
 *      phase of TS_COMP output clock with NUDGE.
 *
 * @brief 
 *  Example to illustrate the usage of CPTS module to generate TS_COMP output  
 *  clocks in both non-toggle and toggle modes by invoking CPTS CSL.
 *
 * 	This example application does the following:
 * 	    (1) Initializes: Configure and enable the CPTS module.
 * 	    (2) Measure the CPTS clock rate.
 *      (3) Program CPTS in non-toggle mode, generate 4000KHz TS_COMP output pulses 
 *          for a specified duration
 *      (4) Program CPTS in toggle mode, generate 400KHz TS_COMP output clocks with 
 *          pre-determined Nudge values for a specified duration
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015, Texas Instruments, Inc.
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
#include <ti/drv/emac/example/cptsTsCmpExample/src/cpts_ts_cmp.h>
#include <stdio.h>

/**************************************************************
************************** DEFINITIONS ************************
***************************************************************/

/**************************************************************
**************** EXAMPLE APP FUNCTIONS ************************
***************************************************************/
#define CORE_SPEED                 600000000
#define CPTS_TS_COMP_RATE          4000

#define NUM_TS_CMP_OUTPUT_CLOCKS    4000*10

int32_t cpts_ts_cmp_nudge[10] = { -2, 1, 1, 0, 5, -2, -2, 1, -2, 0};
uint32_t dbg_ts_cmp_timestamp[1000];

uint32_t core_speed = CORE_SPEED;

/** ============================================================================
 *   @n@b Cpts_TsCmpApp
 *
 *   @b Description
 *   @n Example application that sets up the application, sends, receives
 *      data.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return
 *   @n None
 *
 * =============================================================================
 */
#ifdef __LINUX_USER_SPACE
void* Cpts_TsCmpApp (void *args)
#else
void Cpts_TsCmpApp (void)
#endif
{
	int32_t			i,j;
    int             fPass = 1;
    uint32_t        startTime, cptsClkRate, cptsTsCmpPeriod, core4kPeriod;;
    CSL_CPTS_EVENTINFO  cptsEventInfo1, cptsEventInfo2;
    uint32_t        tsNextHi, tsNextLo, tsNextLoTmp;
    

    System_printf ("**************************************************\n");
    System_printf ("***** CPTS Timestamp Compare Example Starts ******\n");
    System_printf ("**************************************************\n");
    System_flush();
    
    core4kPeriod = core_speed/CPTS_TS_COMP_RATE;
    
    /* Configure the CPTS in non-toggle mode */
    Config_CPTS(0);        
                
    /* Measure CPTS period  */
    CSL_CPTS_popEvent(); 
    CSL_CPTS_TSEventPush();
    startTime = TSCL;
    
    while (!CSL_CPTS_isRawInterruptStatusBitSet());
    CSL_CPTS_getEventInfo(&cptsEventInfo1);
    CSL_CPTS_popEvent(); 
    
    CycleDelayTo(startTime + core_speed/100);
    
    CSL_CPTS_TSEventPush();
    
    while (!CSL_CPTS_isRawInterruptStatusBitSet());
    CSL_CPTS_getEventInfo(&cptsEventInfo2);
    CSL_CPTS_popEvent(); 
    
    cptsClkRate = cptsEventInfo2.timeStamp - cptsEventInfo1.timeStamp;
    
    /* truncate the last two digits and convert to clock rate per second */
    cptsClkRate = cptsClkRate/100*10000;
    
    System_printf ("CPTS Clock Rate = %d per seconds\n", cptsClkRate);
    
    
    /* Program CPTS in non-toggle mode, generate TS_COMP output clocks */
    cptsTsCmpPeriod = cptsClkRate/CPTS_TS_COMP_RATE;
    System_printf ("CPTS Non-toggle mode: generate %d TS_CMP output pulse with period = %d\n", 
                    NUM_TS_CMP_OUTPUT_CLOCKS, cptsTsCmpPeriod);
    System_flush();
    
    /* find the start time */                
    CSL_CPTS_popEvent(); 
    CSL_CPTS_TSEventPush();
    startTime = TSCL;
    
    while (!CSL_CPTS_isRawInterruptStatusBitSet());
    CSL_CPTS_getEventInfo(&cptsEventInfo1);
    CSL_CPTS_popEvent(); 
    
    /* Generate the first pulse after half of the expected duration */
    tsNextHi = cptsEventInfo1.timeStampHi;
    tsNextLo = cptsEventInfo1.timeStamp + cptsTsCmpPeriod/2;
    if(tsNextLo < cptsEventInfo1.timeStamp)
        tsNextHi++;
    CSL_CPTS_setTSCompVal(tsNextLo, tsNextHi, cptsTsCmpPeriod/2);
    
    for (i = 0, j = 0; i < NUM_TS_CMP_OUTPUT_CLOCKS; i++)
    {
        CycleDelayTo(startTime + core4kPeriod);
        startTime += core4kPeriod;
        
        CSL_CPTS_getEventInfo(&cptsEventInfo1);
        CSL_CPTS_popEvent(); 
        
        tsNextLoTmp = tsNextLo + cptsTsCmpPeriod;
        if(tsNextLoTmp < tsNextLo)
            tsNextHi++;
        tsNextLo = tsNextLoTmp;    
        CSL_CPTS_setTSCompVal(tsNextLo, tsNextHi, cptsTsCmpPeriod/2);
        
        dbg_ts_cmp_timestamp[j++] = cptsEventInfo1.timeStamp;
        if(j >= 1000)j = 0;
        
    }    
                    
    /* Program CPTS in toggle mode, generate TS_COMP output clocks with periodic Nudge updates*/
    System_printf ("CPTS toggle mode: generate %d TS_CMP output pulse with period = %d and per-determined nudge\n", 
                    NUM_TS_CMP_OUTPUT_CLOCKS, cptsTsCmpPeriod);
    System_flush();
                    
    Config_CPTS(1);                    
                 
    /* find the start time */                
    CSL_CPTS_popEvent(); 
    CSL_CPTS_TSEventPush();
    startTime = TSCL;
    
    while (!CSL_CPTS_isRawInterruptStatusBitSet());
    
    CSL_CPTS_getEventInfo(&cptsEventInfo1);
    CSL_CPTS_popEvent(); 
    
    /* Generate the first pulse after half of the expected duration */
    tsNextHi = cptsEventInfo1.timeStampHi;
    tsNextLo = cptsEventInfo1.timeStamp + cptsTsCmpPeriod/2;
    if(tsNextLo < cptsEventInfo1.timeStamp)
        tsNextHi++;
    CSL_CPTS_setTSCompVal(tsNextLo, tsNextHi, cptsTsCmpPeriod/2);
    
    for (i =0; i < NUM_TS_CMP_OUTPUT_CLOCKS; i++)
    {
        CycleDelayTo(startTime + core4kPeriod);
        startTime += core4kPeriod;
        
        CSL_CPTS_setTSCompNudge(cpts_ts_cmp_nudge[i%10]);
    }    

    if(fPass)
        System_printf("All tests have passed!\n");
    System_printf ("**************************************************\n");
    System_printf ("****** CPTS Timestamp Compare Example Ends *******\n");
    System_printf ("**************************************************\n");
    System_flush();

    /* Example application done. Return success */
    APP_exit (0);
}

/* Nothing past this point */

