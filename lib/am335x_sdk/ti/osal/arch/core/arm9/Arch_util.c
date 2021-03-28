/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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
    bool        used;
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
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#else
/* TI compiler */
#pragma diag_suppress 179
#endif
    OSAL_COMPILE_TIME_SIZE_CHECK (sizeof(HwiP_nonOs),OSAL_NONOS_HWIP_SIZE_BYTES);
#if defined(__GNUC__) && !defined(__ti__)
#pragma GCC diagnostic pop
#endif
}

/* This function enables the interrupt for a given interrupt number */
void OsalArch_enableInterrupt(uint32_t intNum)
{
    Intc_SystemEnable((unsigned int)intNum);
    return;
}

/* This function disables the interrupt for a given interrupt number */
void OsalArch_disableInterrupt(uint32_t intNum)
{
    Intc_SystemDisable((uint32_t)intNum);
    return;
}

/* Below function clears interrupt in the chip level */
void OsalArch_clearInterrupt(uint32_t intNum)
{
    IntSystemStatusClear((uint32_t)intNum);
    return;
}
/* Below function globally disable interrupt in the chip level */
uintptr_t OsalArch_globalDisableInterrupt(void)
{
    uintptr_t status = Intc_IntDisable();

    return (status);
}

/* Below function globally restore interrupt in the chip level */
void OsalArch_globalRestoreInterrupt (uintptr_t restoreValue)
{
   Intc_IntEnable((uint32_t) restoreValue);
}

/* Below function registers the interrupt for a given ISR */
HwiP_Handle OsalArch_HwiPCreate(int32_t interruptNum, HwiP_Fxn hwiFxn,
                          const HwiP_Params *params)
{
    uint32_t i;
	uint32_t channelNo;
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
      retHandle  = (HwiP_Handle)&hwiPool[i];
    }
    else
    {
      retHandle  = (HwiP_Handle)(NULL_PTR);
    }

    if (retHandle != (HwiP_Handle) NULL_PTR)
    {
        Intc_Init();

        /* Enable the interrupt */
        OsalArch_globalRestoreInterrupt(0);
    
        /* Registering the Interrupt Service Routine(ISR). */
        Intc_IntRegister((uint32_t)interruptNum, (IntrFuncPtr) hwiFxn);

        /*Set the channel number for a system interrupt. Channel numbers 0-1
          are mapped to FIQ and Channel numbers 2-31 are mapped to IRQ of ARM.*/
        channelNo = ((params->priority > 31) || (params->priority < 2)) ? 0x12U : params->priority;
        IntChannelSet((uint32_t)interruptNum, channelNo);

        /* Enabling the interrupt if configured */
        if (params->enableIntr == TRUE)
        {
            /* Enabling the interrupt in INTC. */
            OsalArch_enableInterrupt(interruptNum);
        }
        else
        {
            /* Disabling the interrupt in INTC. */
            OsalArch_disableInterrupt(interruptNum);
        }

        /* Enable the Globle interrupt AINTC */
        IntMasterIRQEnable();
        IntGlobalEnable();
        IntIRQEnable();
    }

    return ( (HwiP_Handle) (retHandle) );  /* __TI_ARM_V5__ */

}

/* Below function deletes the hwi created */
HwiP_Status OsalArch_HwiPDelete(HwiP_Handle handle)
{
    HwiP_nonOs *hwi_hnd = (HwiP_nonOs*) handle;
    uintptr_t   key;

    /* mark that index as free */
    key = OsalArch_globalDisableInterrupt();
    hwi_hnd->used = FALSE;
    OsalArch_globalRestoreInterrupt(key);

    return (HwiP_OK);
}

/* Nothing past this point */
