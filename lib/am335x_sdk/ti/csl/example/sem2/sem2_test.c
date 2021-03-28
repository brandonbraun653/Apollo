/**
 *   @file  sem2_test.c
 *
 *   @brief   
 *      This is the Example test code for the SEM CSL Functional layer.
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
#include <ti/csl/soc.h>
#include <ti/csl/csl_semAux.h>

/**********************************************************************
 ************************** Local Definitions *************************
 **********************************************************************/

/* This is the CORE Number on which this code is executing. */
#define MASTER_ID           0

/**********************************************************************
 ************************* SEM TEST FUNCTIONS *************************
 **********************************************************************/

/**
 *  @b Description
 *  @n  
 *      The function tests the semaphore module using the direct access 
 *      method. The test does the following:-
 *       - Ensures that the Semaphore resource is free
 *       - Acquires the semaphore using the Direct Access Method.
 *       - Direct Access Method should *not* update SEMFLAGS
 *       - Ensures that the Semaphore Status API correctly reports the resource as ACQUIRED.
 *       - Release the semaphore
 *       - Ensures that the Semaphore Status API correctly reports the resource as FREE
 *       - Make sure there were no errors reported by the SEM Module.
 *      
 *  @param[in]  semNumber
 *      Semaphore number on which the test is executed.
 *
 *  @retval
 *      Success -  0
 *  @retval
 *      Error   -  <0
 */
static Int32 test_sem_direct_access (Uint8 semNumber)
{
    printf ("Debug: Testing Semaphore Direct Access Method...\n");

    /* Get the status of the semaphore: Semaphore should *not* be acquired. */
    if (CSL_semIsFree (semNumber) == FALSE)
        return -1;

    /* Acquire the semaphore. */
    if (CSL_semAcquireDirect(semNumber) == 0)
        return -1;

    /* Direct Access Method should *NOT* update the SEMFLAG Registers. */
    if (CSL_semGetFlags(MASTER_ID) != 0)
        return -1;
    
    /* Get the status of the semaphore: Semaphore should *not* be free */
    if (CSL_semIsFree (semNumber) == TRUE)
        return -1;
   
    /* Now we release the semaphore. */
    CSL_semReleaseSemaphore (semNumber);

    /* Get the status of the semaphore: Semaphore should *not* be acquired. */
    if (CSL_semIsFree (semNumber) == FALSE)
        return -1;

    /* Ensure there were no errors reported by the SEM Module. */
    if (CSL_semGetErrorCode() != 0)
        return -1;

    /* Test has passed successfully. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      The function tests the semaphore module using the indirect access method.
 *      The test does the following:-
 *       - Ensures that the Semaphore resource is free
 *       - Acquires the semaphore using the Indirect Access Method.
 *       - This is done by polling the SEMFLAG to ensure that the corresponding bit is set.
 *       - Ensures that the Semaphore Status API correctly reports the resource as ACQUIRED.
 *       - Release the semaphore
 *       - Ensures that the Semaphore Status API correctly reports the resource as FREE
 *       - Make sure there were no errors reported by the SEM Module.
 *
 *  @param[in]  semNumber
 *      Semaphore number on which the test is executed.
 *
 *  @retval
 *      Success -  0
 *  @retval
 *      Error   -  <0
 */
static Int32 test_sem_indirect_access (Uint8 semNumber)
{
    Uint32  semFlags;

    printf ("Debug: Testing Semaphore Indirect Access Method...\n");

    /* Get the status of the semaphore: Semaphore should be *not* be acquired. */
    if (CSL_semIsFree (semNumber) == FALSE)
        return -1;

    /* Make sure there are no pending flags. */
    if (CSL_semGetFlags(MASTER_ID) != 0)
        return -1; 

    /* Acquire the semaphore. */
    CSL_semAcquireIndirect(semNumber);

    /* We should now get an interrupt and a notification in the SEMFLAGL register that the semaphore resource 
     * was granted to us. */
    while (1)
    {
        semFlags = CSL_semGetFlags(MASTER_ID);
        if (semFlags & (1 << semNumber))
        {
            /* YES. Corresponding bit was set; this implies that the resource is available. */            
            break;
        }
    }

    /* OK; we can clear the flags now. */
    CSL_semClearFlags (MASTER_ID, semFlags);

    /* Reread the flags and make sure it is set to 0. */
    if(CSL_semGetFlags(MASTER_ID) != 0)
        return -1;
    
    /* Get the status of the semaphore: Semaphore should *not* be free */
    if (CSL_semIsFree (semNumber) == TRUE)
        return -1;
   
    /* Now we release the semaphore. */
    CSL_semReleaseSemaphore (semNumber);
 
    /* Get the status of the semaphore: Semaphore should *not* be acquired. */
    if (CSL_semIsFree (semNumber) == FALSE)
        return -1;

    /* Make sure there are no errors reported by the SEM module. */
    if (CSL_semGetErrorCode() != 0)
        return -1;

    /* Test has passed successfully */
    return 0;        
}

/**
 *  @b Description
 *  @n  
 *      The function tests the semaphore module using the combined access method. The
 *      function does the following:-
 *       - Ensures that the Semaphore resource is free
 *       - Acquires the semaphore using the Combined Access Method.
 *          o Since there is just 1 master accesing this; we should get the semaphore immediately.
 *          0 This should *not* update SEMFLAGS
 *       - Ensures that the Semaphore Status API correctly reports the resource as ACQUIRED.
 *       - Release the semaphore
 *       - Ensures that the Semaphore Status API correctly reports the resource as FREE
 *       - Make sure there were no errors reported by the SEM Module.
 *
 *  @param[in]  semNumber
 *      Semaphore number on which the test is executed.
 *
 *  @retval
 *      Success -  0
 *  @retval
 *      Error   -  <0
 */
static Int32 test_sem_combined_access (Uint8 semNumber)
{
    printf ("Debug: Testing Semaphore Combined Access Method...\n");

    /* Get the status of the semaphore: Semaphore should *not* be acquired. */
    if (CSL_semIsFree (semNumber) == FALSE)
        return -1;

    /* Make sure there are no pending flags. */
    if (CSL_semGetFlags(MASTER_ID) != 0)
        return -1; 

    /* Acquire the semaphore. */
    if (CSL_semAcquireCombined(semNumber) == 0)
        return -1;

    /* Get the status of the semaphore: Semaphore should *not* be free */
    if (CSL_semIsFree (semNumber) == TRUE)
        return -1;
    
    /* Now we release the semaphore. */
    CSL_semReleaseSemaphore (semNumber);
 
    /* Get the status of the semaphore: Semaphore should *not* be acquired. */
    if (CSL_semIsFree (semNumber) == FALSE)
        return -1;

    /* Make sure the SEM Module has not reported any errors. */
    if (CSL_semGetErrorCode() != 0)
        return -1;

    /* Combined Access Method Semaphore test passed. */
    return 0;
}

/**
 *  @b Description
 *  @n  
 *      The function tests the semaphore error codes.
 *      The test does the following:-
 *       - Ensures that the Semaphore resource is free
 *       - Acquires the semaphore using the Direct Access Method.
 *       - Ensures that the Semaphore Status API correctly reports the resource as ACQUIRED.
 *       - Tries to acquire the semaphore again.
 *       - This should report an Error Code of 0x3.
 *
 *      The second test in this function is to 
 *       - Clear the previous error. 
 *       - Release the semaphore which was not previously acquired.
 *       - This should report an Error Code of 0x1.
 *
 *  @param[in]  semNumber
 *      Semaphore number on which the test is executed.
 *
 *  @retval
 *      Success -  0
 *  @retval
 *      Error   -  <0
 */
static Int32 test_sem_error (Uint8 semNumber)
{
    printf ("Debug: Testing Semaphore Error...\n");

    /* Get the status of the semaphore: Semaphore should *not* be acquired. */
    if (CSL_semIsFree (semNumber) == FALSE)
        return -1;

    /* Acquire the semaphore. */
    if (CSL_semAcquireDirect(semNumber) == 0)
        return -1;

    /* Get the status of the semaphore: Semaphore should *not* be free. */
    if (CSL_semIsFree (semNumber) == TRUE)
        return -1;

    /* Make sure the SEM Module has not reported any errors. */
    if (CSL_semGetErrorCode() != 0)
        return -1;

    /* OK lets start the test now: Acquire the semaphore again; this should fail.*/
    if (CSL_semAcquireDirect(semNumber) == 1)
        return -1;

    /* This should cause an error to be set in the SEM Module and the error code should be 3. */
    if (CSL_semGetErrorCode() != 3)
        return -1;
    
    /* Good; now we clear the error code */
    CSL_semClearError ();

    /* write 0x10 to SEM_EOI to re-arm SEMERR */
    *(Uint32*)(0x0264000C) = 0x10;

    /* Make sure the error code is reset. */
    if (CSL_semGetErrorCode() != 0)
        return -1;

    /* Try and free a semaphore which is already free. 
     *  This should cause another error. */
    CSL_semReleaseSemaphore(semNumber+1);

    /* Make sure the error code is reset. */
    if (CSL_semGetErrorCode() != 1)
        return -1;

    /* Good; now we clear the error code */
    CSL_semClearError ();

    /* Make sure the error code is reset. */
    if (CSL_semGetErrorCode() != 0)
        return -1;
    
    /* Error Code Test passed */
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
    Uint8   semNumber = 2; 

    printf ("************************************************\n");
    printf ("************* SEM2 Testing 2X Style ************\n");
    printf ("************************************************\n");

    /* Test the Direct Access Method */
    if (test_sem_direct_access (semNumber) < 0)
    {
        printf ("Error: Testing Semaphore Direct Access Method FAILED\n");
        return;
    }
    printf ("Debug: Testing Semaphore Direct Access Method Passed\n");

    /* Test the Indirect Access Method. */    
    if (test_sem_indirect_access (semNumber) < 0)
    {
        printf ("Error: Testing Semaphore Indirect Access Method FAILED\n");
        return;
    }
    printf ("Debug: Testing Semaphore Indirect Access Method Passed\n");

    /* Test the Combined Access Method. */
    if (test_sem_combined_access (semNumber) < 0)
    {
        printf ("Error: Testing Semaphore Combined Access Method FAILED\n");
        return;
    }
    printf ("Debug: Testing Semaphore Combined Access Method Passed\n");

    /* Test the error. */
    if (test_sem_error (semNumber) < 0)
    {
        printf ("Error: Testing Semaphore Error FAILED\n");
        return;
    }
    printf ("Debug: Testing Semaphore Error Passed\n");
    
    /* SEM2 testing has been completed. */
    printf ("**************************************************\n");
    printf ("************* SEM2 Testing Completed *************\n");
    printf ("**************************************************\n");
    return;
}
