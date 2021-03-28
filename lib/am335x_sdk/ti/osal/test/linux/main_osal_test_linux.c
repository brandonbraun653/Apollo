/**
 *  \file   main_osal_test_linux.c
 *
 *  \brief  OSAL driver test application main file for linux.
 *
 */

/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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
#include <stdio.h>
#include <string.h>

/* Header file */
#include <ti/osal/osal.h>

/*
 *  ======== Semaphore test function ========
 */
bool OSAL_semaphore_test()
{
    SemaphoreP_Params semParams;
    SemaphoreP_Handle handle1, handle2;

    /* Test 1: counting mode, no timeout */
    SemaphoreP_Params_init(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    semParams.name = "countingSemaphore";
    handle1 = SemaphoreP_create(0, &semParams);
    if (handle1 == NULL)
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
    if (SemaphoreP_delete(handle1) != SemaphoreP_OK)
    {
		return false;
    }

    /* Test 2: binary mode, with timeout */
    SemaphoreP_Params_init(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    semParams.name = "binarySemaphore";

    handle2 = SemaphoreP_create(1, &semParams);
    if (handle2 == NULL)
    {
                return false;
    }
    if (SemaphoreP_pend(handle2, 10) != SemaphoreP_TIMEOUT)
    {
                return false;
    }
    if (SemaphoreP_delete(handle2) != SemaphoreP_OK)
    {
                return false;
    }

    return true;
}

/*
 *  ======== main test function ========
 */
void osal_test()
{
    bool testFail = false;

    if(OSAL_semaphore_test() == true)
    {
        printf("\n Semaphore tests have passed. \n");
    }
    else
    {
        printf("\n Semaphore tests have failed. \n");
        testFail = true;
    }

    if(testFail == true)
    {
        printf("\n Some tests have failed. \n");
    }
    else
    {
        printf("\n All tests have passed. \n");
    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    osal_test();

    return (0);
}

