/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the
 *	  distribution.
 *
 *	* Neither the name of Texas Instruments Incorporated nor the names of
 *	  its contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
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
 */

#include "iepPwmFwRegs.h"
#include "iepPwmHwRegs.h"
#include "iepPwm.h"
#include "icssg_iep_pwm.h"
#include "resource_table_empty.h"

void main(void)
{
    Int32 status;
    IepSm_Config iepSmConfig;
    
    /* Reset PWM FW control object */
    status = resetPwmCtrlObj(&gIcssgIepPwmCtrlObj);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }
    
    /* Reset IEP 0 PWM object */
    status = resetIepPwmObj(&gIcssgIep0PwmObj, IEP_ID_0);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }
    
    /* Reset IEP 1 PWM object */
    status = resetIepPwmObj(&gIcssgIep1PwmObj, IEP_ID_1);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }
    
    /* Wait for PWM enable flag from Host, indicates FW init can commence */
    status = waitPwmEnFlag(&gIcssgIepPwmCtrlObj);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }

    /* Initialize PWM FW control */
    status = initPwmCtrl(&gIcssgIepPwmCtrlObj);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }

    /* Initialize IEP0 PWM */
    status = initIepPwm(&gIcssgIepPwmCtrlObj, &gIcssgIep0PwmObj);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }
    
    /* Initialize IEP1 PWM */
    status = initIepPwm(&gIcssgIepPwmCtrlObj, &gIcssgIep1PwmObj);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }
    
    /* Set PWM FW init flag, indicate FW init complete to Host */
    status = setPwmFwInitFlag(&gIcssgIepPwmCtrlObj);
    if (status != IEP_STS_NERR)
    {
        /* Indicate Error to Host */
        ;
    }
    
    /* Get State Machine configuration */
    iepSmConfig = getIepPwmSmConfig(&gIcssgIepPwmCtrlObj);
        
    /* Execute State Machine(s) */
    if (iepSmConfig == IEP_SM_CONFIG_IEP0)
    {
        /* IEP0 PWM enabled */
        initIepPwmSm(&gIcssgIep0PwmObj);
        while (1)
        {
            gIcssgIep0PwmObj.pIepHwRegs->CMP_STATUS_REG = IEP_CMP_STATUS_CMP1_12_MASK;  /* clear all but CMP0 events */
            status = execIepPwmSm(&gIcssgIep0PwmObj, TRUE);
            if (status != IEP_STS_NERR)
            {
                /* Indicate Error to Host */
                ;
            }
        }
    }
    else if (iepSmConfig == IEP_SM_CONFIG_IEP1)
    {
        /* IEP1 PWM enabled */
        initIepPwmSm(&gIcssgIep1PwmObj);
        while (1)
        {
            gIcssgIep1PwmObj.pIepHwRegs->CMP_STATUS_REG = IEP_CMP_STATUS_CMP1_12_MASK;  /* clear all but CMP0 events */
            status = execIepPwmSm(&gIcssgIep1PwmObj, TRUE);
            if (status != IEP_STS_NERR)
            {
                /* Indicate Error to Host */
                ;
            }
        }        
    }
    else if (iepSmConfig == IEP_SM_CONFIG_IEP0_1)
    {
        /* IEP0 & IEP1 PWM enabled */
        initIepPwmSm(&gIcssgIep0PwmObj);
        initIepPwmSm(&gIcssgIep1PwmObj);
        while (1)
        {
            gIcssgIep0PwmObj.pIepHwRegs->CMP_STATUS_REG = IEP_CMP_STATUS_CMP1_12_MASK;  /* clear all but CMP0 events */
            gIcssgIep1PwmObj.pIepHwRegs->CMP_STATUS_REG = IEP_CMP_STATUS_CMP1_12_MASK;  /* clear all but CMP0 events */
            
            status = execIepPwmSm(&gIcssgIep0PwmObj, TRUE);
            if (status != IEP_STS_NERR)
            {
                /* Indicate Error to Host */
                ;
            }
            
            status = execIepPwmSm(&gIcssgIep1PwmObj, FALSE);
            if (status != IEP_STS_NERR)
            {
                /* Indicate Error to Host */
                ;
            }
        }
    }
    else /* iepSmConfig == IEP_SM_CONFIG_NONE */
    {
        /* Nothing to do */
        while (1)
            ;
    }       
}
