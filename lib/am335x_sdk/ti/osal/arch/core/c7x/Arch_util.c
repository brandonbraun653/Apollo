/*
 * Copyright (c) 2016-2018, Texas Instruments Incorporated
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
 *  ======== HwiP_tirtos.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/osal/src/nonos/Nonos_config.h>
#include <ti/csl/tistdtypes.h>

/* Local structure definition */
typedef struct HwiP_nonOs_s {
    Bool        used;
    Hwi_Struct  hwi;
} HwiP_nonOs;

/* Local hwi structures */
static HwiP_nonOs hwiStructs[OSAL_NONOS_CONFIGNUM_HWI] = {{0}};


/*
 * Dummy function to check size during compile time
 *  ======== HwiP_compileTime_SizeChk ========
 */

void OsalArch_compileTime_SizeChk(void)
{
    #pragma diag_suppress 179
    OSAL_COMPILE_TIME_SIZE_CHECK (sizeof(HwiP_nonOs),OSAL_NONOS_HWIP_SIZE_BYTES);
}

static bool gFirstTime = FALSE;
//TODO: Integrate to CSL once C7x arch is supported
//static CSL_IntcContext               gContext;
//static CSL_IntcEventHandlerRecord    gEventRecord[OSAL_NONOS_CONFIGNUM_HWI];

/* This function enables the interrupt for a given interrupt number */
void OsalArch_enableInterrupt(uint32_t intNum)
{
    //TODO: Integrate to CSL once C7x arch is supported
    return;
}

/* This function disables the interrupt for a given interrupt number */
void OsalArch_disableInterrupt(uint32_t intNum)
{
    //TODO: Integrate to CSL once C7x arch is supported
    return;
}

/* Below function clears interrupt in the chip level */
void OsalArch_clearInterrupt(uint32_t intNum)
{
    //TODO: Integrate to CSL once C7x arch is supported
    return;
}
/* Below function globally disable interrupt in the chip level */
uintptr_t OsalArch_globalDisableInterrupt(void)
{
  //TODO: Integrate to CSL once C7x arch is supported
  return 0;
}

/* Below function globally restore interrupt in the chip level */
void OsalArch_globalRestoreInterrupt (uintptr_t restoreValue)
{
    //TODO: Integrate to CSL once C7x arch is supported
}

/* Below function registers the interrupt for a given ISR */
HwiP_Handle OsalArch_HwiPCreate(int32_t interruptNum, HwiP_Fxn hwiFxn,
                          const HwiP_Params *params)
{
    Hwi_Struct                   *hwi_handle = (Hwi_Struct *) NULL_PTR;
    //CSL_IntcParam                 vectId;

    uint32_t i;
    uintptr_t key;

    uintptr_t         temp;
    HwiP_nonOs       *hwiPool;
    uint32_t          maxHwi;
    HwiP_Handle       retHandle;

    /* Check if user has specified any memory block to be used, which gets
     * the precedence over the internal static memory block
     */
    if (gOsal_HwAttrs.extHwiPBlock.base != (uintptr_t)NULL_PTR)
    {
        /* pick up the external memory block configured */
        hwiPool        = (HwiP_nonOs *) gOsal_HwAttrs.extHwiPBlock.base;
        temp           = ((uintptr_t) hwiPool) + gOsal_HwAttrs.extHwiPBlock.size;
        maxHwi         = (uint32_t)(temp/(sizeof(Hwi_Struct)));
    }
    else
    {
        /* Pick up the internal static memory block */
        hwiPool        = (HwiP_nonOs *) &hwiStructs[0];
        maxHwi         = OSAL_NONOS_CONFIGNUM_HWI;
    }

    if (params == NULL_PTR)
    {
        return (NULL_PTR);
    }

    key = OsalArch_globalDisableInterrupt();
    for (i = 0u; i < maxHwi; i++) {
        if (hwiPool[i].used == FALSE) {
            hwiPool[i].used = TRUE;
            break;
        }
    }
    OsalArch_globalRestoreInterrupt(key);

    if (i != maxHwi)
    {
      hwi_handle = &(hwiPool[i].hwi);
      retHandle  = (HwiP_Handle)&hwiPool[i];
    }
    else
    {
      retHandle  = (HwiP_Handle)(NULL_PTR);
    }

    if (hwi_handle != (Hwi_Struct *) NULL_PTR)
    {
         //if (gFirstTime == FALSE) {
         //  /* record the index in the handle */
         //  gContext.numEvtEntries      = OSAL_NONOS_CONFIGNUM_HWI;
         //  gContext.eventhandlerRecord = gEventRecord;
         //  //TODO: Integrate to CSL once C7x arch is supported
         //  //CSL_intcInit(&gContext);
         //  gFirstTime = TRUE;
         //}

         //TODO: Integrate to CSL once C7x arch is supported
         //CSL_intcGlobalNmiEnable();
         //CSL_intcGlobalEnable(NULL_PTR);
         //vectId = (CSL_IntcParam)interruptNum;
         //
         //hwi_handle->handle = CSL_intcOpen (&hwi_handle->intcObj, params->evtId, &vectId, NULL_PTR);
         //
         //if(hwi_handle->handle != NULL_PTR)
         //{
         //    CSL_IntcEventHandlerRecord  evtHandler;
         //    evtHandler.handler = (CSL_IntcEventHandler)hwiFxn;
         //    evtHandler.arg     = (void *) params->arg;
         //
         //    CSL_intcPlugEventHandler(hwi_handle->handle, &evtHandler);
         //    CSL_intcHwControl(hwi_handle->handle,CSL_INTC_CMD_EVTCLEAR,NULL_PTR);
         //    CSL_intcHwControl(hwi_handle->handle,CSL_INTC_CMD_EVTENABLE,NULL_PTR);
         //}
         //else
         //{
         //    /* Free the pool */
         //    hwiPool[i].used = FALSE;
         //    retHandle = (HwiP_Handle *) NULL_PTR;
         //}
    }

    return ( (HwiP_Handle) (retHandle) );  /* _TMS320C6X */
}

HwiP_Status OsalArch_HwiPDelete(HwiP_Handle handle)
{
    //TODO: Integrate to CSL once C7x arch is supported
    //CSL_Status  status = CSL_SOK;
    HwiP_nonOs *hwi_hnd = (HwiP_nonOs*) handle;
    uintptr_t   key;
    HwiP_Status ret_val;

    /* mark that handle as free */
    key = OsalArch_globalDisableInterrupt();
    hwi_hnd->used = FALSE;
    OsalArch_globalRestoreInterrupt(key);
    //status = CSL_intcClose(hwi_hnd->hwi.handle);

    //if (status == CSL_SOK)
    //{
      ret_val = (HwiP_OK);
    //}
    //else
    //{
    //  ret_val = (HwiP_FAILURE);
    //}
    return (ret_val);
}

/*
 *  ======== HwiP_getHandle ========
 *  Returns the HwiP handle associated with an interrupt number
  */
HwiP_Handle OsalArch_getHandle(int32_t interruptNum)
{
   Hwi_Struct *handle= (Hwi_Struct *) NULL_PTR;
   return((HwiP_Handle)handle);
}
/*
 *  ======== HwiP_getEventId ========
 *  Returns the Event ID associated with an interrupt
  */
int32_t OsalArch_getEventId(int32_t interruptNum)
{
    return(-1);
}

/* Below function posts the interrupt */
int32_t OsalArch_postInterrupt(uint32_t intrNum)
{
    return (-1);
}
/* Nothing past this point */
