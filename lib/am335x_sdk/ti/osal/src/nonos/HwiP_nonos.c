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
 *  ======== HwiP_nonos.c ========
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ti/osal/src/nonos/Nonos_config.h>

extern uint32_t  gOsalHwiAllocCnt, gOsalHwiPeak;

/*
 *  ======== HwiP_clearInterrupt ========
 */
void HwiP_clearInterrupt(int32_t interruptNum)
{
    OsalArch_clearInterrupt((uint32_t)interruptNum);
}

/*
 *  ======== HwiP_create ========
 */
HwiP_Handle HwiP_create(int32_t interruptNum, HwiP_Fxn hwiFxn,
                        const HwiP_Params *params)
{
    HwiP_Handle handle;
    handle = OsalArch_HwiPCreate(interruptNum,hwiFxn,params);

    /* Update statistics for successful allocation */
    if (handle != NULL_PTR)
    {
        gOsalHwiAllocCnt++;
        if (gOsalHwiAllocCnt > gOsalHwiPeak)
        {
            gOsalHwiPeak = gOsalHwiAllocCnt;
        }
    }
    return (handle);
}

/*
 *  ======== HwiP_delete ========
 */
HwiP_Status HwiP_delete(HwiP_Handle handle)
{
    HwiP_Status status;

    OSAL_Assert((handle == NULL_PTR));

    if(handle!=NULL_PTR) {
      status = OsalArch_HwiPDelete(handle);

      if (status == HwiP_OK)
      {
        if (gOsalHwiAllocCnt > 0U)
        {
            gOsalHwiAllocCnt--;
        }
      }
   }
   else
   {
      status = HwiP_FAILURE;
   }

    return (status);
}

/*
 *  ======== HwiP_disable ========
 */
uintptr_t HwiP_disable(void)
{
    return (OsalArch_globalDisableInterrupt());
}

/*
 *  ======== HwiP_disableInterrupt ========
 */
void HwiP_disableInterrupt(int32_t interruptNum)
{
    OsalArch_disableInterrupt((uint32_t)interruptNum);
    return;
}

/*
 *  ======== HwiP_enableInterrupt ========
 */
void HwiP_enableInterrupt(int32_t interruptNum)
{
    OsalArch_enableInterrupt((uint32_t)interruptNum);
    return;
}

int32_t HwiP_post(uint32_t interruptNum)
{
#if defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200) || defined(SOC_TPR12)
   return(OsalArch_postInterrupt(interruptNum));
#else
   return (osal_UNSUPPORTED);
#endif
}


/*
 *  ======== HwiP_Params_init ========
 */
void HwiP_Params_init(HwiP_Params *params)
{
    params->name     = (char *) NULL_PTR;
    params->arg      = 0;
    params->priority = HWIP_USE_DEFAULT_PRIORITY;
    params->evtId    = 0;
    params->enableIntr = TRUE;
#if defined (__ARM_ARCH_7A__) || defined(__aarch64__) || defined (__TI_ARM_V7R4__)
    params->triggerSensitivity = (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LEVEL;
#if !defined (SOC_AM437x) &&  !defined(SOC_AM335x) && !defined (__TI_ARM_V7R4__)
    {
       Osal_HwAttrs hwAttrs;
	   (void)Osal_getHwAttrs(&hwAttrs);
	   if(hwAttrs.hwAccessType==OSAL_HWACCESS_UNRESTRICTED)
		{
	      /* Do GIC init only in the case of unrestricted hw access */
    OsalArch_gicInit();
		}
	  }
#endif
#endif
}

/*
 *  ======== HwiP_restore ========
 */
void HwiP_restore(uintptr_t key)
{
  OsalArch_globalRestoreInterrupt(key);
  return;
}

#ifdef _TMS320C6X
/*
 *  ======== HwiP_getHandle ========
 *  Returns the HwiP handle associated with an interrupt number
  */
HwiP_Handle HwiP_getHandle(int32_t interruptNum)
{
   return(OsalArch_getHandle(interruptNum));
}

/*
 *  ======== HwiP_getEventId ========
 *  Returns the Event ID associated with an interrupt
  */
int32_t HwiP_getEventId(int32_t interruptNum)
{
  return(OsalArch_getEventId(interruptNum));
}
#endif
