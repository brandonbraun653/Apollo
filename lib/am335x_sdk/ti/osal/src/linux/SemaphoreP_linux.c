/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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
 *  ======== SemaphoreP_linux.c ========
 */
#include <ti/osal/SemaphoreP.h>
#include <ti/osal/osal.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <semaphore.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

/*
 *  ======== SemaphoreP_create ========
 */
SemaphoreP_Handle SemaphoreP_create(uint32_t count,
                                    const SemaphoreP_Params *params)
{
    sem_t *handle;

    /* Creates a COUNTING semaphore */
    handle = sem_open(params->name, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH, count);
    if (handle == SEM_FAILED)
    {
        return NULL;
    }
    return ((SemaphoreP_Handle)handle);
}


/*
 *  ======== SemaphoreP_delete ========
 */
SemaphoreP_Status SemaphoreP_delete(SemaphoreP_Handle handle)
{
    OSAL_Assert((handle == NULL));

    int ret;

    ret = sem_close((sem_t *)handle);
    if (ret < 0) {
        return SemaphoreP_FAILURE;
    }

    return (SemaphoreP_OK);
}

/*
 *  ======== SemaphoreP_Params_init ========
 */
void SemaphoreP_Params_init(SemaphoreP_Params *params)
{
    OSAL_Assert((params == NULL));

    params->mode = SemaphoreP_Mode_COUNTING;
    params->name = NULL;
}

/*
 *  ======== SemaphoreP_pend ========
 */
SemaphoreP_Status SemaphoreP_pend(SemaphoreP_Handle handle, uint32_t timeout)
{
    OSAL_Assert((handle == NULL));

    int ret;
    struct timespec ts;
    int timeout_ns = timeout*1000;

    if (timeout == SemaphoreP_WAIT_FOREVER) {
        ret = sem_wait((sem_t *)handle);
    } else {
        clock_gettime(CLOCK_REALTIME, &ts);
        ts.tv_sec += (timeout_ns)/1000000000;
        ts.tv_nsec += timeout_ns%1000000000;

        ret = sem_timedwait((sem_t *)handle, &ts);
    }
    if (ret < 0) {
        if (errno == ETIMEDOUT) {
                return (SemaphoreP_TIMEOUT);
        } else {
                return (SemaphoreP_FAILURE);
        }
    }

    return (SemaphoreP_OK);
}

/*
 *  ======== SemaphoreP_post ========
 */
SemaphoreP_Status SemaphoreP_post(SemaphoreP_Handle handle)
{
    OSAL_Assert((handle == NULL));

    int ret;

    ret = sem_post((sem_t *)handle);
    if (ret < 0) {
        return (SemaphoreP_FAILURE);
    }

    return (SemaphoreP_OK);
}

/*
 *  ======== SemaphoreP_postFromClock ========
 */
SemaphoreP_Status SemaphoreP_postFromClock(SemaphoreP_Handle handle)
{
    return (SemaphoreP_post(handle));
}

/*
 *  ======== SemaphoreP_postFromISR ========
 */
SemaphoreP_Status SemaphoreP_postFromISR(SemaphoreP_Handle handle)
{
    return (SemaphoreP_post(handle));
}

/* Nothing past this point */
