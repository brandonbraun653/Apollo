/**
 *   @file  cpintc_test.c
 *
 *   @brief   
 *      This is the Example test code for the CPINTC Functional layer. The code 
 *      also utilizes the INTC CSL functional layer to determine that routing 
 *      of system interrupts to the GEM cores is done properly.
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2009 Texas Instruments, Inc.
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
#include <ti/csl/src/intc/csl_intc.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_cpIntcAux.h>

/**********************************************************************
 ************************** Local Definitions *************************
 **********************************************************************/

/* Limit Defintions: Maximum number of system interrupts and channels */
#define MAX_NUM_SYSTEM_INTERRUPTS   200
#define MAX_NUM_CHANNELS            12

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Intc variable declarartion */
CSL_CPINTC_Handle           hnd;
CSL_IntcContext             intcContext; 
CSL_IntcEventHandlerRecord  EventHandler[30];
CSL_IntcObj                 intcObj;
CSL_IntcHandle              hTest; 
CSL_IntcGlobalEnableState   state;
CSL_IntcEventHandlerRecord  EventRecord;
CSL_IntcParam               vectId;

/* Global Registers which display the INTC and CPINTC Memory Maps. */
CSL_IntcRegsOvly    gIntcRegisters    = (CSL_IntcRegsOvly)CSL_CGEM0_5_REG_BASE_ADDRESS_REGS;
CSL_CPINTC_RegsOvly gCPIntc0Registers = (CSL_CPINTC_RegsOvly)CSL_CP_INTC_0_REGS;
CSL_CPINTC_RegsOvly gCPIntc1Registers = (CSL_CPINTC_RegsOvly)CSL_CP_INTC_1_REGS;

/* This is an array which keeps track of total number of interrupts received 
 * per system interrupt. */
volatile Int32 InterruptReceived[MAX_NUM_SYSTEM_INTERRUPTS];

/* This is a global counter which keeps track of the errors. */
volatile Int32 InterruptErrorCounter = 0;

/**********************************************************************
 ************************ CPINTC TEST FUNCTIONS ***********************
 **********************************************************************/

/**
 *  @b Description
 *  @n  
 *      This is the TEST ISR Handler which has been installed.
 *      This simply increments a global variable which counts
 *      the number of interrupts which have been received.
 *
 *  @retval
 *      Not Applicable.
 */
static void test_isr_handler (void* handle)
{
    Uint32  rawStatus;
    Uint32  sysIntr = 0;
    
    /* Get the RAW status register we read only register 0 as we are interested 
     * only in System Interrupts 0-31. */
    CSL_CPINTC_getRawInterruptStatus(hnd, 0, &rawStatus);
    if (rawStatus != 0)
    {
        /* There are interrupts between 0-31 pending. */
        while (rawStatus != 0)
        {
            /* Check if the interrupt is pending or not? */
            if (rawStatus & 0x1)
            {
                /* Interrupt is pending... Record it */
                InterruptReceived[sysIntr]++;

                /* Clear the pending system interrupt. */
                CSL_CPINTC_clearSysInterrupt(hnd, sysIntr);                
            }

            /* Goto the next bit. */
            rawStatus = rawStatus >> 1;
            sysIntr++;
        }
    }
}

/**
 *  @b Description
 *  @n
 *      This test case does the following:-
 *       - Enables System Interrupt 3
 *       - Enable all Host Interrupts
 *       - Generates 20 system interrupts.
 *      Test Case passes if all 20 system interrupts were detected
 *      else the test case fails. 
 *
 *  @retval
 *      Success     -   0
 *  @retval
 *      Error       -   <0 
 */
static Int32 test_working_sys_interrupts (void)
{
    Uint16  index;

    printf ("Debug: Testing Multiple System Interrupts...\n");
    
    /* Ensure the system interrupts are enabled. */
    CSL_CPINTC_enableSysInterrupt (hnd, 3);
    
    /* Ensure that the host interrupts are enabled. */
    CSL_CPINTC_enableHostInterrupt (hnd, 3);
    CSL_CPINTC_enableAllHostInterrupt(hnd);
    
    /* Reset the global counters. */
    for (index = 0; index < MAX_NUM_SYSTEM_INTERRUPTS; index++)  
        InterruptReceived[index] = 0;
    InterruptErrorCounter = 0;
    
    /* Generate the system interrupts */    
    for (index = 0; index < 20; index++)
    {
    	int counter;
        ((CSL_CPINTC_RegsOvly)CSL_CP_INTC_0_REGS)->STATUS_SET_INDEX_REG = 3;
        for (counter = 0; counter < 50; counter++) 
        asm(" nop 5");
    }
    
    /* Spin around till all the interrupt are detected. */
    while (InterruptReceived[3] != 20);

    /* Check if there were any errors. */
    if (InterruptErrorCounter != 0)
        return -1;        
    
    /* The test case has passed. */
    return 0;
}

/**
 *  @b Description
 *  @n
 *      This test case does the following:-
 *       - Disables System Interrupt 3
 *       - Enables all Host Interrupts
 *       - Generates system interrupts 3
 *      Test Case passes if the ISR has not been invoked else the
 *      test fails.  
 *
 *  @retval
 *      Success     -   0
 *  @retval
 *      Error       -   <0 
 */
static Int32 test_disable_sys_interrupt (void)
{
    Uint16  index;

    printf ("Debug: Testing Disable System Interrupt...\n");
    
    /* Disable system interrupt 3 */
    CSL_CPINTC_disableSysInterrupt (hnd, 3);
    
    /* Ensure that the host interrupts are enabled. */
    CSL_CPINTC_enableHostInterrupt (hnd, 3);
    CSL_CPINTC_enableAllHostInterrupt(hnd);    
    
    /* Reset the global counters. */
    for (index = 0; index < MAX_NUM_SYSTEM_INTERRUPTS; index++)  
        InterruptReceived[index] = 0;
    InterruptErrorCounter = 0;
      
    /* Generate system interrupt 3 */    
    ((CSL_CPINTC_RegsOvly)CSL_CP_INTC_0_REGS)->STATUS_SET_INDEX_REG = 3;
    
    /* Loop around for some time; delay */    
    for (index = 0; index < 0xFFF; index++);
    
    /* Ensure that there the Interrupt Received counter has not gone up. */
    if (InterruptReceived[3] != 0)
        return -1;
    
    /* Check if there were any errors. */
    if (InterruptErrorCounter != 0)
        return -1;        
        
    /* Test Case has passed. */
    return 0;
}

/**
 *  @b Description
 *  @n
 *      This test case does the following:-
 *       - Enables System Interrupt 3
 *       - Disables all Host Interrupts
 *       - Enables Host Interrupt 3
 *       - Generates system interrupts 3
 *      Test Case passes if the ISR has not been invoked else the
 *      test fails.  
 *
 *  @retval
 *      Success     -   0
 *  @retval
 *      Error       -   <0 
 */
static Int32 test_disable_all_host_interrupt (void)
{
    Uint16  index;

    printf ("Debug: Testing Disable All Host Interrupt...\n");
    
    /* Enable system interrupt 3 */
    CSL_CPINTC_enableSysInterrupt (hnd, 3);
    
    /* Ensure that the host interrupts is individually enabled. */
    CSL_CPINTC_enableHostInterrupt (hnd, 3);
    
    /* Ensure that the global host interrupts are disabled. */
    CSL_CPINTC_disableAllHostInterrupt(hnd);    
        
    /* Reset the global counters. */
    for (index = 0; index < MAX_NUM_SYSTEM_INTERRUPTS; index++)  
        InterruptReceived[index] = 0;
    InterruptErrorCounter = 0;
        
    /* Generate system interrupt 3 */
    ((CSL_CPINTC_RegsOvly)CSL_CP_INTC_0_REGS)->STATUS_SET_INDEX_REG = 3;
    
    /* Loop around for some time; delay */    
    for (index = 0; index < 0xFFF; index++);
    
    /* Ensure that there the Interrupt Received counter has not gone up. */
    if (InterruptReceived[3] != 0)
        return -1;
        
    /* Check if there were any errors. */
    if (InterruptErrorCounter != 0)
        return -1;        
        
    /* Test Case has passed. */
    return 0;
}

/**
 *  @b Description
 *  @n
 *      This test case does the following:-
 *       - Enables System Interrupt 3
 *       - Enables all Host Interrupts
 *       - Enables Host Interrupt 3
 *       - Generates system interrupts 4
 *      Test Case passes if the ISR has not been invoked else the
 *      test fails.  
 *
 *  @retval
 *      Success     -   0
 *  @retval
 *      Error       -   <0 
 */
static Int32 test_spurious_sys_interrupt (void)
{
    Uint16  index;

    printf ("Debug: Testing spurious system Interrupt...\n");
    
    /* Enable system interrupt 3 */
    CSL_CPINTC_enableSysInterrupt (hnd, 3);
    
    /* Ensure that all the global host interrupts are enabled. */
    CSL_CPINTC_enableAllHostInterrupt(hnd);        
    
    /* Ensure that the host interrupts is individually disabled. */
    CSL_CPINTC_enableHostInterrupt (hnd, 3);
            
    /* Reset the global counters. */
    for (index = 0; index < MAX_NUM_SYSTEM_INTERRUPTS; index++)  
        InterruptReceived[index] = 0;
    InterruptErrorCounter = 0;
        
    /* Generate system interrupt 4 */
    ((CSL_CPINTC_RegsOvly)CSL_CP_INTC_0_REGS)->STATUS_SET_INDEX_REG = 4;
    
    /* Loop around for some time; delay */    
    for (index = 0; index < 0xFFF; index++);
    
    /* Ensure that there the Interrupt Received counter has not gone up. */
    if (InterruptReceived[4] != 0)
        return -1;
        
    /* Check if there were any errors. */
    if (InterruptErrorCounter != 0)
        return -1;
        
    /* Test Case has passed. */
    return 0;    
}

/**
 *  @b Description
 *  @n
 *      This test case does the following:-
 *       - Enables System Interrupt 3
 *       - Enables all Host Interrupts
 *       - Disables Host Interrupt 3
 *       - Generates system interrupts 3
 *      Test Case passes if the ISR has not been invoked else the
 *      test fails.  
 *
 *  @retval
 *      Success     -   0
 *  @retval
 *      Error       -   <0 
 */
static Int32 test_disable_host_interrupt (void)
{
    Uint16  index;

    printf ("Debug: Testing disable host Interrupt...\n");
    
    /* Enable system interrupt 3 */
    CSL_CPINTC_enableSysInterrupt (hnd, 3);
    
    /* Ensure that all the global host interrupts are enabled. */
    CSL_CPINTC_enableAllHostInterrupt(hnd);        
    
    /* Ensure that the host interrupts is individually disabled. */
    CSL_CPINTC_disableHostInterrupt (hnd, 3);
            
    /* Reset the global counters. */
    for (index = 0; index < MAX_NUM_SYSTEM_INTERRUPTS; index++)  
        InterruptReceived[index] = 0;
    InterruptErrorCounter = 0;
        
    /* Generate system interrupt 3 */
    ((CSL_CPINTC_RegsOvly)CSL_CP_INTC_0_REGS)->STATUS_SET_INDEX_REG = 3;
    
    /* Loop around for some time; delay */    
    for (index = 0; index < 0xFFF; index++);
    
    /* Ensure that there the Interrupt Received counter has not gone up. */
    if (InterruptReceived[3] != 0)
        return -1;
        
    /* Check if there were any errors. */
    if (InterruptErrorCounter != 0)
        return -1;
        
    /* Test Case has passed. */
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
    Uint32  rawStatus;
    Uint16  index;

    printf ("**************************************************\n");
    printf ("****************** CPINTC Testing ****************\n");
    printf ("**************************************************\n");

    /************************************************
     *************** INTC Configuration ************* 
     ************************************************/
    
    printf ("Debug: GEM-INTC Configuration...\n");
    
    /* INTC module initialization */
    intcContext.eventhandlerRecord = EventHandler;
    intcContext.numEvtEntries      = 10;
    if (CSL_intcInit(&intcContext) != CSL_SOK) 
    {
        printf("Error: GEM-INTC initialization failed\n");
        return;
    }    
    
    /* Enable NMIs */
    if (CSL_intcGlobalNmiEnable() != CSL_SOK) 
    {
        printf("Error: GEM-INTC global NMI enable failed\n");
        return;
    }
 
    /* Enable global interrupts */
    if (CSL_intcGlobalEnable(&state) != CSL_SOK) 
    {
        printf ("Error: GEM-INTC global enable failed\n");
        return;
    }

    /* Open the INTC Module for Vector ID: 4 and Event ID: 63 (C6678) 59 (C6670) 
     * 	Refer to the interrupt architecture and mapping document for the Event ID  (INTC0_OUT3)*/
    vectId = CSL_INTC_VECTID_4;
    hTest = CSL_intcOpen (&intcObj, 63, &vectId , NULL);
    if (hTest == NULL) 
    {
        printf("Error: GEM-INTC Open failed\n");
        return;
    }
    
    /* Register an call-back handler which is invoked when the event occurs. */
    EventRecord.handler = &test_isr_handler;
    EventRecord.arg = 0;
    if (CSL_intcPlugEventHandler(hTest,&EventRecord) != CSL_SOK) 
    {
        printf("Error: GEM-INTC Plug event handler failed\n");
        return;
    }
    
    /* Enabling the events. */
    if (CSL_intcHwControl(hTest,CSL_INTC_CMD_EVTENABLE, NULL) != CSL_SOK) 
    {
        printf("Error: GEM-INTC CSL_INTC_CMD_EVTENABLE command failed\n");
        return;
    }

    printf ("Debug: GEM-INTC Configuration Completed\n");
 
    /**************************************************
     ************* CPINTC-0 Configuration ************* 
     **************************************************/

    printf ("Debug: CPINTC-0 Configuration...\n");
     
    /* Open the handle to the CPINT Instance */
    hnd = CSL_CPINTC_open(0);
    if (hnd == 0)
    {
        printf ("Error: Unable to open CPINTC-0\n");
        return;       
    }
    
    /* Disable all host interrupts. */
    CSL_CPINTC_disableAllHostInterrupt(hnd);
    
    /* Configure no nesting support in the CPINTC Module. */
    CSL_CPINTC_setNestingMode (hnd, CPINTC_NO_NESTING);

   	/* We now map System Interrupt 0 - 3 to channel 3 */
  	CSL_CPINTC_mapSystemIntrToChannel (hnd, 0 , 2);
   	CSL_CPINTC_mapSystemIntrToChannel (hnd, 1 , 4);
  	CSL_CPINTC_mapSystemIntrToChannel (hnd, 2 , 5);
   	CSL_CPINTC_mapSystemIntrToChannel (hnd, 3 , 3);
   	
   	/* We now enable system interrupt 0 - 3 */
   	CSL_CPINTC_enableSysInterrupt (hnd, 0);
   	CSL_CPINTC_enableSysInterrupt (hnd, 1);
   	CSL_CPINTC_enableSysInterrupt (hnd, 2);
   	CSL_CPINTC_enableSysInterrupt (hnd, 3);
   	
   	/* We enable host interrupts. */
   	CSL_CPINTC_enableHostInterrupt (hnd, 3);
   	
   	/* Enable all host interrupts also. */
   	CSL_CPINTC_enableAllHostInterrupt(hnd);
   	
    printf ("Debug: CPINTC-0 Configuration Completed\n");
    
    /* Testing the CSL API. */
    printf ("***************************************\n");
    printf ("Testing the CSL API for CPINTC-0  \n");
    printf ("****************************************\n");
    
    /* Test Case: Ensure the system interrupts are being generated and the 
     * registered ISR is invoked. */    
    if (test_working_sys_interrupts() < 0)
        printf ("Error: Testing Multiple System Interrupts FAILED\n");
    else
        printf ("Debug: Testing Multiple System Interrupts Passed\n");
   
    /* Test Case: Test and ensure the if the system interrupt is disabled
     * the registered ISR is not invoked. */        
    if (test_disable_sys_interrupt() < 0)
        printf ("Error: Testing Disable System Interrupt FAILED\n");
    else
        printf ("Debug: Testing Disable System Interrupt Passed\n");

    /* Test Case: Ensure the if all host interrupts are disabled then 
     * the registered ISR is not invoked. */            
    if (test_disable_all_host_interrupt() < 0)
        printf ("Error: Testing Disable All Host Interrupt FAILED\n");
    else
        printf ("Debug: Testing Disable All Host Interrupt Passed\n");
    
    /* Test Case: Ensure the a spurious system interrupt does not invoke
     * the registered ISR */            
    if (test_spurious_sys_interrupt() < 0)
        printf ("Error: Testing spurious system Interrupt FAILED\n");
    else
        printf ("Debug: Testing spurious system Interrupt Passed\n");
            
    /* Test Case: Ensure the if host interrupts are disabled then the registered 
     * ISR is not invoked. */            
    if (test_disable_host_interrupt() < 0)
        printf ("Error: Testing disable host Interrupt FAILED\n");
    else
        printf ("Debug: Testing disable host Interrupt Passed\n");

    printf ("***************************************\n");
    printf ("CSL API testing for CPINTC-0 Completed \n");
    printf ("****************************************\n");

    /**************************************************
     ************* CPINTC-1 Configuration ************* 
     **************************************************/

    printf ("Debug: CPINTC-1 Configuration...\n");
    
    /* Open the handle to the CPINT Instance */
    hnd = CSL_CPINTC_open(1);
    if (hnd == 0)
    {
        printf ("Error: Unable to open CPINT instance 1\n");
        return;       
    }    
    
    /* Disable all host interrupts. */
    CSL_CPINTC_disableAllHostInterrupt(hnd);
        
    /* Configure no nesting support in the CPINTC Module. */
    CSL_CPINTC_setNestingMode (hnd, CPINTC_NO_NESTING);
           
    /* We now map System Interrupt 5 to channel 0 */
    CSL_CPINTC_mapSystemIntrToChannel (hnd, 5 , 0);
    
    /* We now enable system interrupt 5 */
    CSL_CPINTC_enableSysInterrupt (hnd, 5);

    /* We enable host interrupts. */
    CSL_CPINTC_enableHostInterrupt (hnd, 10);

    /* Enable all host interrupts also. */
    CSL_CPINTC_enableAllHostInterrupt(hnd);

    printf ("Debug: CPINTC-1 Configuration Completed\n");

    /* Testing the CSL API. */
    printf ("***************************************\n");
    printf ("Testing the CSL API for CPINTC-1  \n");
    printf ("****************************************\n");

    /* Reset the global counters. */
    for (index = 0; index < MAX_NUM_SYSTEM_INTERRUPTS; index++)  
        InterruptReceived[index] = 0;
    InterruptErrorCounter = 0;    

    /* Read the RAW Status register to ensure there are no interrupts pending 
     * at this time. */
    CSL_CPINTC_getRawInterruptStatus(hnd, 0, &rawStatus);
    if (rawStatus != 0)
    {
        printf ("Error: CPINTC-1 interrupt is already pending\n");
        return;
    }

    printf ("Debug: Testing detection of system interrupts on CPINTC-1\n");
        
    /* Generate System Interrupt 5. */
    ((CSL_CPINTC_RegsOvly)CSL_CP_INTC_1_REGS)->STATUS_SET_INDEX_REG = 5;
   
    /* We should have a pending interrupt. */
    CSL_CPINTC_getRawInterruptStatus(hnd, 0, &rawStatus);
    if (rawStatus != 0)
    {
        Uint32 sysIntr = 0;

        /* There are interrupts between 0-31 pending. */
        while (rawStatus != 0)
        {
            /* Check if the interrupt is pending or not? */
            if (rawStatus & 0x1)
                InterruptReceived[sysIntr]++;

            /* Goto the next bit. */
            rawStatus = rawStatus >> 1;
            sysIntr++;
        }
       
        /* Make sure that we received System Interrupt 5 */ 
        if (InterruptReceived[5] != 0)
            printf ("Debug: Testing detection of system interrupts on CPINTC-1 Passed\n");
        else
            printf ("Error: Testing detection of system interrupts on CPINTC-1 FAILED\n");            
    }
    else
    {
        /* Error: No pending interrupt detected */
        printf ("Error: Testing detection of system interrupts on CPINTC-1 FAILED\n");            
    }

    printf ("***************************************\n");
    printf ("CSL API testing for CPINTC-1 Completed \n");
    printf ("****************************************\n");
   
    /**************************************************
     ************* CPINTC-2 Configuration ************* 
     **************************************************/

    printf ("Debug: CPINTC-2 Configuration...\n");
    
    /* Open the handle to the CPINT Instance */
    hnd = CSL_CPINTC_open(2);
    if (hnd == 0)
    {
        printf ("Error: Unable to open CPINT instance 2\n");
        return;       
    }    
    
    /* Disable all host interrupts. */
    CSL_CPINTC_disableAllHostInterrupt(hnd);
        
    /* Configure no nesting support in the CPINTC Module. */
    CSL_CPINTC_setNestingMode (hnd, CPINTC_NO_NESTING);
           
    /* We now map System Interrupt 20 to channel 0 */
    CSL_CPINTC_mapSystemIntrToChannel (hnd, 20 , 0);
    
    /* We now enable system interrupt 5 */
    CSL_CPINTC_enableSysInterrupt (hnd, 20);

    /* We enable host interrupts. */
    CSL_CPINTC_enableHostInterrupt (hnd, 10);

    /* Enable all host interrupts also. */
    CSL_CPINTC_enableAllHostInterrupt(hnd);

    printf ("Debug: CPINTC-2 Configuration Completed\n");

    /* Testing the CSL API. */
    printf ("***********************************\n");
    printf ("Testing the CSL API for CPINTC-2  \n");
    printf ("***********************************\n");    
   
    /* Reset the global counters. */
    for (index = 0; index < MAX_NUM_SYSTEM_INTERRUPTS; index++)  
        InterruptReceived[index] = 0;
    InterruptErrorCounter = 0;
   
    /* Read the RAW Status register to ensure there are no interrupts pending 
     * at this time. */
    CSL_CPINTC_getRawInterruptStatus(hnd, 0, &rawStatus);
    if (rawStatus != 0)
    {
        printf ("Error: CPINTC-1 interrupt is already pending\n");
        return;
    }

    printf ("Debug: Testing detection of system interrupts on CPINTC-2\n");
        
    /* Generate System Interrupt 20. */
    ((CSL_CPINTC_RegsOvly)CSL_CP_INTC_2_REGS)->STATUS_SET_INDEX_REG = 20;
   
    /* We should have a pending interrupt. */
    CSL_CPINTC_getRawInterruptStatus(hnd, 0, &rawStatus);
    if (rawStatus != 0)
    {
        Uint32 sysIntr = 0;

        /* There are interrupts between 0-31 pending. */
        while (rawStatus != 0)
        {
            /* Check if the interrupt is pending or not? */
            if (rawStatus & 0x1)
                InterruptReceived[sysIntr]++;

            /* Goto the next bit. */
            rawStatus = rawStatus >> 1;
            sysIntr++;
        }
       
        /* Make sure that we received System Interrupt 20 */ 
        if (InterruptReceived[20] != 0)
            printf ("Debug: Testing detection of system interrupts on CPINTC-2 Passed\n");
        else
            printf ("Error: Testing detection of system interrupts on CPINTC-2 FAILED\n");
    }
    else
    {
        /* Error: No pending interrupt detected */
        printf ("Error: Testing detection of system interrupts on CPINTC-2 FAILED\n");
    }    

    /* CPINTC-2 CSL API testing has been completed. */
    printf ("***************************************\n");
    printf ("CSL API testing for CPINTC-2 Completed \n");
    printf ("****************************************\n");    

    /* CPINTC Testing has been completed. */
    printf ("**************************************************\n");
    printf ("************* CPINTC Testing Completed ***********\n");
    printf ("**************************************************\n");
    
    return;    
}
