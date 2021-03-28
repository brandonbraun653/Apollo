/*
 *  Copyright (c) Texas Instruments Incorporated 2018
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
 */

/**
 *  \file utils_prf.c
 *
 *  \brief Profiling API utility file.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <string.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/utils/Load.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/drv/fvid2/fvid2.h>
#include <ti/csl/csl_types.h>

#include "utils_prf.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

typedef struct
{
    uint32_t        isAlloc;
    char            name[32];
    TaskP_Handle    pTsk;
    uint64_t        totalTskThreadTime;
} Utils_PrfLoadObj;

typedef struct
{
    Utils_PrfTsHndl  tsObj[UTILS_PRF_MAX_HNDL];
    Utils_PrfLoadObj loadObj[UTILS_PRF_MAX_HNDL];
} Utils_PrfObj;

typedef struct
{
    uint64_t totalSwiThreadTime;
    uint64_t totalHwiThreadTime;
    uint64_t totalTime;
    uint64_t totalIdlTskTime;
} Utils_AccPrfLoadObj;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static Utils_PrfObj        gUtils_prfObj;
static Utils_AccPrfLoadObj gUtils_accPrfLoadObj;
static uint32_t               gUtils_startLoadCalc = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t Utils_prfInit(void)
{
    memset(&gUtils_prfObj, 0, sizeof (gUtils_prfObj));
    memset(&gUtils_accPrfLoadObj, 0, sizeof (Utils_AccPrfLoadObj));

    return (0);
}

int32_t Utils_prfDeInit(void)
{
    return (0);
}

Utils_PrfTsHndl *Utils_prfTsCreate(const char *name)
{
    uint32_t        hndlId;
    uint32_t        cookie;
    Utils_PrfTsHndl *pHndl = NULL;

    cookie = Hwi_disable();

    for (hndlId = 0; hndlId < UTILS_PRF_MAX_HNDL; hndlId++)
    {
        pHndl = &gUtils_prfObj.tsObj[hndlId];

        if(FALSE == pHndl->isAlloc)
        {
            /* One less for NULL character */
            strncpy(pHndl->name, name, ((uint32_t) sizeof (pHndl->name) - 1U));
            pHndl->name[sizeof (pHndl->name) - 1U] = (UInt8) '\0';
            pHndl->isAlloc = (uint32_t) TRUE;
            Utils_prfTsReset(pHndl);
            break;
        }
    }

    Hwi_restore(cookie);

    return (pHndl);
}

int32_t Utils_prfTsDelete(Utils_PrfTsHndl *pHndl)
{
    pHndl->isAlloc = (uint32_t) FALSE;
    return (0);
}

uint64_t Utils_prfTsBegin(Utils_PrfTsHndl *pHndl)
{
    pHndl->startTs = Utils_prfTsGet64();

    return (pHndl->startTs);
}

uint64_t Utils_prfTsEnd(Utils_PrfTsHndl *pHndl, uint32_t numFrames)
{
    return (Utils_prfTsDelta(pHndl, pHndl->startTs, numFrames));
}

uint64_t Utils_prfTsDelta(Utils_PrfTsHndl *pHndl,
                           uint64_t              startTime,
                           uint32_t              numFrames)
{
    uint64_t endTs;
    uint32_t cookie;

    endTs = Utils_prfTsGet64();

    cookie = Hwi_disable();

    pHndl->totalTs += (endTs - pHndl->startTs);
    pHndl->count++;
    pHndl->numFrames += numFrames;

    Hwi_restore(cookie);

    return (endTs);
}

int32_t Utils_prfTsReset(Utils_PrfTsHndl *pHndl)
{
    uint32_t cookie;

    cookie = Hwi_disable();

    pHndl->totalTs   = 0;
    pHndl->count     = 0;
    pHndl->numFrames = 0;

    Hwi_restore(cookie);

    return (0);
}

uint64_t Utils_prfTsGet64(void)
{
    uint64_t curTs;
    Types_Timestamp64 ts64;

    Timestamp_get64(&ts64);

    curTs = ((uint64_t) ts64.hi << 32) | ts64.lo;

    return (curTs);
}

uint32_t Utils_prfTsGetFreq(void)
{
    Types_FreqHz    cpuHz;
    uint32_t        cpuKhz;

    Timestamp_getFreq(&cpuHz);

    cpuKhz = cpuHz.lo / (uint32_t) 1000U; /* convert to Khz */

    return cpuKhz;
}

int32_t Utils_prfTsPrint(Utils_PrfTsHndl *pHndl, uint32_t resetAfterPrint, uint32_t trace)
{
    uint32_t       cpuKhz;
    uint32_t       timeMs, fps, fpc;
    Types_FreqHz cpuHz;

    Timestamp_getFreq(&cpuHz);

    cpuKhz = cpuHz.lo / (uint32_t) 1000U; /* convert to Khz */

    timeMs = pHndl->totalTs / cpuKhz;

    if(0U == timeMs)
    {
        fps = 0U;
    }
    else
    {
        fps = (pHndl->numFrames * (uint32_t) 1000U) / timeMs;
    }
    if(0U == pHndl->count)
    {
        fpc = 0U;
    }
    else
    {
        fpc = pHndl->numFrames / pHndl->count;
    }

    GT_7trace(
        trace, GT_INFO,
        " %d: PRF : %s : t: %d ms, count: %d, frames: %d, fps: %d, fpc: %d \r\n",
        Utils_getCurTimeInMsec(),
        pHndl->name,
        timeMs,       /* in msecs    */
        pHndl->count,
        pHndl->numFrames,
        fps,       /* frames per second */
        fpc        /* frames per count */
        );

    if(resetAfterPrint)
    {
        Utils_prfTsReset(pHndl);
    }

    return (0);
}

int32_t Utils_prfTsPrintAll(uint32_t resetAfterPrint, uint32_t trace)
{
    uint32_t        hndlId;
    Utils_PrfTsHndl *pHndl;

    GT_0trace(trace, GT_INFO, "\r\n");

    for (hndlId = 0; hndlId < UTILS_PRF_MAX_HNDL; hndlId++)
    {
        pHndl = &gUtils_prfObj.tsObj[hndlId];

        if(TRUE == pHndl->isAlloc)
        {
            Utils_prfTsPrint(pHndl, resetAfterPrint, trace);
        }
    }

    GT_0trace(trace, GT_INFO, "\r\n");

    return (0);
}

int32_t Utils_prfLoadRegister(TaskP_Handle pTsk, const char *name)
{
    uint32_t            hndlId;
    uint32_t            cookie;
    int32_t             status = STW_EFAIL;
    Utils_PrfLoadObj   *pHndl;

    cookie = Hwi_disable();

    for (hndlId = 0; hndlId < UTILS_PRF_MAX_HNDL; hndlId++)
    {
        pHndl = &gUtils_prfObj.loadObj[hndlId];

        if(FALSE == pHndl->isAlloc)
        {
            pHndl->isAlloc = (uint32_t) TRUE;
            pHndl->pTsk    = pTsk;
            /* One less for NULL character */
            strncpy(pHndl->name, name, ((uint32_t) sizeof (pHndl->name) - 1U));
            pHndl->name[sizeof (pHndl->name) - 1U] = (UInt8) '\0';
            status = STW_SOK;
            break;
        }
    }

    Hwi_restore(cookie);

    return (status);
}

int32_t Utils_prfLoadUnRegister(TaskP_Handle pTsk)
{
    uint32_t            hndlId;
    uint32_t            cookie;
    int32_t             status = STW_EFAIL;
    Utils_PrfLoadObj   *pHndl;

    cookie = Hwi_disable();

    for (hndlId = 0; hndlId < UTILS_PRF_MAX_HNDL; hndlId++)
    {
        pHndl = &gUtils_prfObj.loadObj[hndlId];

        if((TRUE == pHndl->isAlloc) && (pHndl->pTsk == pTsk))
        {
            pHndl->isAlloc = (uint32_t) FALSE;
            status         = STW_SOK;
            break;
        }
    }

    Hwi_restore(cookie);

    return (status);
}

int32_t Utils_prfLoadPrintAll(uint32_t printTskLoad)
{
    uint32_t            hwiLoad, swiLoad, tskLoad, hndlId, cpuLoad;
    Utils_PrfLoadObj   *pHndl;
    uint32_t            trace = (GT_INFO1 | GT_TraceState_Enable);

    hwiLoad = (uint32_t) ((gUtils_accPrfLoadObj.totalHwiThreadTime *
                         (uint64_t) 100U) / gUtils_accPrfLoadObj.totalTime);
    swiLoad = (uint32_t) ((gUtils_accPrfLoadObj.totalSwiThreadTime *
                         (uint64_t) 100U) / gUtils_accPrfLoadObj.totalTime);
    cpuLoad = (uint32_t) 100U -
              (uint32_t) ((gUtils_accPrfLoadObj.totalIdlTskTime *
                         (uint64_t) 100U) /
                        gUtils_accPrfLoadObj.totalTime);

    GT_0trace(trace, GT_INFO, "\r\n");
    GT_4trace(trace, GT_INFO,
              " %d: LOAD: CPU: %d%%, HWI: %d%%, SWI:%d%% \r\n",
              Utils_getCurTimeInMsec(),
              cpuLoad,
              hwiLoad,
              swiLoad);

    if(((uint32_t) TRUE) == printTskLoad)
    {
        for (hndlId = 0; hndlId < UTILS_PRF_MAX_HNDL; hndlId++)
        {
            pHndl = &gUtils_prfObj.loadObj[hndlId];

            if(TRUE == pHndl->isAlloc)
            {
                tskLoad = (uint32_t) ((pHndl->totalTskThreadTime *
                                     (uint64_t) 100U) /
                                    gUtils_accPrfLoadObj.totalTime);

                GT_3trace(trace, GT_INFO,
                          " %d: LOAD: TSK: %s: %d%% \r\n",
                          Utils_getCurTimeInMsec(),
                          pHndl->name,
                          tskLoad);
            }
        }
    }

    GT_0trace(trace, GT_INFO, "\r\n");

    return (0);
}

void Utils_prfLoadCalcStart(void)
{
    uint32_t cookie;

    cookie = Hwi_disable();
    gUtils_startLoadCalc = (uint32_t) TRUE;
    Hwi_restore(cookie);

    return;
}

void Utils_prfLoadCalcStop(void)
{
    uint32_t cookie;

    cookie = Hwi_disable();
    gUtils_startLoadCalc = FALSE;
    Hwi_restore(cookie);

    return;
}

void Utils_prfLoadCalcReset(void)
{
    uint32_t            hndlId;
    Utils_PrfLoadObj   *pHndl;

    gUtils_accPrfLoadObj.totalHwiThreadTime = 0;
    gUtils_accPrfLoadObj.totalSwiThreadTime = 0;
    gUtils_accPrfLoadObj.totalTime          = 0;
    gUtils_accPrfLoadObj.totalIdlTskTime    = 0;

    /* Reset the performace loads accumulator */
    for (hndlId = 0; hndlId < UTILS_PRF_MAX_HNDL; hndlId++)
    {
        pHndl = &gUtils_prfObj.loadObj[hndlId];

        if(((uint32_t) TRUE == pHndl->isAlloc) &&
            (pHndl->pTsk != NULL))
        {
            pHndl->totalTskThreadTime = 0;
        }
    }

    return;
}

/* Function called by Loadupdate for each update cycle */
void Utils_prfLoadUpdate(void)
{
    uint32_t            hndlId;
    Load_Stat           hwiLoadStat, swiLoadStat, tskLoadStat, idlTskLoadStat;
    TaskP_Handle        idlTskHndl = NULL;
    Utils_PrfLoadObj   *pHndl;

    if(((uint32_t) TRUE) == (uint32_t) gUtils_startLoadCalc)
    {
        idlTskHndl = Task_getIdleTask();

        /* Get the all loads first */
        Load_getGlobalHwiLoad(&hwiLoadStat);
        Load_getGlobalSwiLoad(&swiLoadStat);
        Load_getTaskLoad(idlTskHndl, &idlTskLoadStat);

        gUtils_accPrfLoadObj.totalHwiThreadTime += hwiLoadStat.threadTime;
        gUtils_accPrfLoadObj.totalSwiThreadTime += swiLoadStat.threadTime;
        gUtils_accPrfLoadObj.totalTime          += hwiLoadStat.totalTime;
        gUtils_accPrfLoadObj.totalIdlTskTime    += idlTskLoadStat.threadTime;

        /* Call the load updated function of each registered task one by one
         * along with the swiLoad, hwiLoad, and Task's own load */
        for (hndlId = 0; hndlId < UTILS_PRF_MAX_HNDL; hndlId++)
        {
            pHndl = &gUtils_prfObj.loadObj[hndlId];

            if(((uint32_t) TRUE == pHndl->isAlloc) &&
                (pHndl->pTsk != NULL))
            {
                Load_getTaskLoad(pHndl->pTsk, &tskLoadStat);
                pHndl->totalTskThreadTime += tskLoadStat.threadTime;
            }
        }
    }

    return;
}

uint32_t Utils_getCurTimeInMsec(void)
{
    uint64_t curTimeMsec, curTimeUsec;

    curTimeUsec = TimerP_getTimeInUsecs();
    curTimeMsec = (curTimeUsec / 1000U);

    return ((uint32_t) curTimeMsec);
}
