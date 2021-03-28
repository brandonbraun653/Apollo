/**
 *  \file  dmtimer_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to configurable parameters in dmtimer peripheral.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#ifndef DMTIMER_APP_H_
#define DMTIMER_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "interrupt.h"
#include "dmtimer.h"


#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/* None */
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding configurable DMTIMER configuration parameters. */
typedef struct dmtimerAppCfg
{
    uint32_t configMode;
    /**< operating mode of the timer. */
    uint32_t timerInitialCount;
    /**< initial value of the counter. */
    uint32_t timerReloadCount;
    /**< Value to be reloaded. */
    uint32_t enableClockPrescaler;
    /**< Enable or disable prescaler - takes values TRUE or FALSE  */
    uint32_t clockPrescalerRatio;
    /**< prescaler divider ratio. */    
    intcTrigType_t trigType;
    /**< Interrupt type edge or level . */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t intrEnable;    
    /**< Interrupt enable/disable. */
    uint32_t intrMask;
    /**< Interrupt Masks. - Overflow , capture or Match 
     *  and a combination of these values.*/
    void (*pFnIntrHandler)(uint32_t intrId, uint32_t cpuId, void* pUserParam);
    /**< Function pointer to Interrupt handler which needs to be 
     *  registered with the interrupt Controller.- Application needs
     *  to initialize this. If set to null then polling Mode is assumed     
     */
    void *pUserParam;  
    /**< Parameter to be passed to the Interrupt handler function */     
    uint32_t        instNum;
    /**< DMTIMER instance number. */
    uint32_t        instAddr;
    /**< DMTIMER instance address. */
     
 }dmtimerAppCfg_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   DMTIMER IP configuration initialization api.
 *
 * \param   pDmtimerObj dmtimer configurable parameter object 
 *          - #dmtimerAppCfg_t
 */
void DMTIMERAppInit(dmtimerAppCfg_t *pDmtimerObj);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef DMTIMER_APP_H_ */
