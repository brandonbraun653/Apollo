/**
 * \file   countdown_timer_app_main.c
 *
 * \brief  Enrty point to the Countdown timer example, which configures the IP
 *         ,utils and executes a sample application for DMTimer. The application 
 *         will count down from 9-0 ( configurable by user).
 *
 *         Application Configuration:
 *
 *             Modules Used:
 *                 DMTimer
 *                 ConsoleUtils
 *
 *             Configurable parameters:
 *                 refer dmtimer_app.h.
 *
 *             
 *         Mode of Timer - Timer mode(Auto reload)
 *
 *         Application Use Case
 *             The application demonstrates DMTimer in Autoreload mode
 *             of operation. In the example, for every overflow of DMTimer
 *             the counter register is reloaded with contents of overflow
 *             register. This sequence is continued 10 times and at each
 *             overflow a decrementing value is printed on the serial
 *             console showcasing the DMTimer as a down counter.
 *
 *         Running the example:
 *             On execution, the example will count down from 9 - 0 and stop.
 *             The time interval between each count is approximate to 700ms.
 *
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "board.h"
#include "soc.h"
#include "chipdb.h"
#include "console_utils.h"
#include "interrupt.h"
#include "error.h"
#include "cache.h"
#include "example_utils_mmu.h"
/* Application header files */
#include "countdown_timer_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API gets the the first valid instance number of a module,
 *          starting from the max number.
 *
 * \param   pAppObj  pointer to application count down object
 *                   - #dmtimerAppCdt_t 
 * \retval  TRUE    A valid module instance was found and copied to passed param.
 * \retval  FALSE   A valid module instance was not found. 
 */
static uint32_t DmtimerAppGetInstNum(dmtimerAppCdt_t *pAppObj);

/**
 * \brief   This API gets the soc info - base address and interrupt line number 
 *          of the DMTIMER instance.
 *
 * \param   pAppObj  pointer to application count down object
 *                   - #dmtimerAppCdt_t 
 * \retval  TRUE    A valid base address and interrupt line number was found 
 *                  and copied to passed param.
 * \retval  FALSE   Either of the two , base address or interrupt line number
*                   was not found. 
 */
static uint32_t DmtimerAppGetSocInfo(dmtimerAppCdt_t *pAppObj);

/**
 * \brief   This is the OVERFLOW ISR for the Count down timer.
 *
 * \param   intrId - interrupt handler param - Interrupt ID
 * \param   cpuId  - interrupt handler param - CPU ID    
 * \param   pUserParam - Param passed by user to the interrupt handler
 */
void DmtimerAppCountdownIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/** \brief global flag updated in Interrupt service routine to indicate timer 
 *  overflow.*/
static volatile uint32_t gDmtimerIsrFlag = 0;
 
/** \brief Application default configuration */
static const dmtimerAppCdt_t DMTIMER_APPCDT_DEFAULT =
{
    10U,                         /* cntValue */
    {
        (uint32_t)DMTIMER_MODE_CFG_AUTORLD_CMP_DISABLE,/* configMode */        
        0xFF000000U,            /* timerInitialCount */
        0xFF000000U,            /* timerReloadCount */        
        0x0U,                   /* isClockPrescalerEnabled */       
        0x0U,                   /* ClockPrescalerRatio */
        INTC_TRIG_HIGH_LEVEL,   /* trigType */              
        100U,                   /* intrLine */        
        1U,                     /* intrEnable */       
        (uint32_t)DMTIMER_INTR_MASK_OVF, /*intrFlag  */
        NULL,                   /* pFnIntrHandler */
        NULL,                   /* pUserParam */
        2U,                     /* instNum */
        (uint32_t)NULL          /* instAddr */               
    }
};

/** \brief Global object for the DMTIMER count down application. */
static dmtimerAppCdt_t gDmtimerCdtApp;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = S_PASS;
    /* Initialize the global object with Countdown timer application. */
    gDmtimerCdtApp = DMTIMER_APPCDT_DEFAULT;
    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);    

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();    
    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);
    
    CONSOLEUtilsPrintf("\n StarterWare DMTIMER - Countdown timer Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);
    
    /* Print SOC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Perform initialization of Interrupt controller*/
    status = INTCInit(FALSE);
   
    if (S_PASS == status)
    {      
       /*Find the instance on which to run this application or else dmtimer 
         instance 2 will be used as default. */
        status = DmtimerAppGetInstNum(&gDmtimerCdtApp);
        if (S_PASS == status)
        {
            /* Get SoC info -instance base address and interrupt line number*/
            status = DmtimerAppGetSocInfo(&gDmtimerCdtApp);
            if (S_PASS == status)
            {
                /* Initialise the application parameters */
                DMTIMERAppCountdownTimerInit(&gDmtimerCdtApp);  
                /* Countdown timer use case with count down from 10 to 0 */
                DMTIMERAppCountdownTimerRun(&gDmtimerCdtApp);
    
                CONSOLEUtilsPrintf("\n Application Complete \n");  
            }
            else
            {
                CONSOLEUtilsPrintf("\n Application not supported in this SOC - \
                exiting app! \n"); 
            }    
        }
        else
        {
            CONSOLEUtilsPrintf("\n This example is not supported on this SOC as\
            no dmtimer instance could be found to support this example\
            - exiting app! \n"); 
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Interrupt configuration failed - exiting app!\n");
    }    
    while (1); 
}

void DMTIMERAppCountdownTimerInit(dmtimerAppCdt_t *pCountdownTimerObj)
{
    /*initialize the object ISR function pointer  with application ISR*/
    pCountdownTimerObj->dmtimerObj.pFnIntrHandler = &(DmtimerAppCountdownIsr); 
    /*initialise the ISR user param with address of Countdown timer object */
    pCountdownTimerObj->dmtimerObj.pUserParam = (void*)pCountdownTimerObj; 
    
    /* call the peripheral config API */
    DMTIMERAppInit((dmtimerAppCfg_t*)&(pCountdownTimerObj->dmtimerObj));   
}

void DMTIMERAppCountdownTimerRun(dmtimerAppCdt_t *pCountdownTimerObj)
{
    CONSOLEUtilsPrintf("\n  DMTIMER DOWN COUNTER: ");
    /* Start the DMTimer */
    DMTIMEREnable(pCountdownTimerObj->dmtimerObj.instAddr, TRUE);

    while(pCountdownTimerObj->cntValue)
    {
        if(gDmtimerIsrFlag == 1)
        {
            CONSOLEUtilsPrintf("\b%d",(pCountdownTimerObj->cntValue - 1));
            pCountdownTimerObj->cntValue--;
            gDmtimerIsrFlag = 0U;
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
/*This function returns the first valid instance of the dmtimer module. This 
  function uses CHIPDBModuleMaxInstanceNumber() to get the max number of 
  instances present and then checks whether that particular instance is valid.*/
static uint32_t DmtimerAppGetInstNum(dmtimerAppCdt_t *pAppObj)
{
    uint32_t status = E_FAIL;
    uint32_t maxNumInst = CHIPDBModuleMaxInstanceNumber(CHIPDB_MOD_ID_DMTIMER);
    /*Cycle through max number of instances.*/
    while (maxNumInst >= 1)
    {     
        if (CHIPDBIsResourcePresent(CHIPDB_MOD_ID_DMTIMER, (maxNumInst - 1U)) 
            == TRUE)
            {
                pAppObj->dmtimerObj.instNum = maxNumInst - 1U;
                status = S_PASS;
                break;               
            }    
        else
            {
                --maxNumInst;   
            }        
    }
    return(status);
}

static uint32_t DmtimerAppGetSocInfo(dmtimerAppCdt_t *pAppObj)
{
    uint32_t status = E_FAIL;

    pAppObj->dmtimerObj.instAddr =
    CHIPDBBaseAddress(CHIPDB_MOD_ID_DMTIMER, pAppObj->dmtimerObj.instNum); 
      
    /* Get the interupt line number */ 
    pAppObj->dmtimerObj.intrLine = 
    ChipDBInterruptNum( CHIPDB_MOD_ID_DMTIMER,
                    pAppObj->dmtimerObj.instNum, 0U);

    if (CHIPDB_INVALID_ADDRESS == pAppObj->dmtimerObj.instNum)
    {
        status = E_FAIL;
        CONSOLEUtilsPrintf("DMTIMER instance has invalid base \
         address!\n");               
    }
    else if (CHIPDB_INVALID_INTERRUPT_NUM == pAppObj->dmtimerObj.instNum)
    {
        status = E_FAIL;
        CONSOLEUtilsPrintf("DMTIMER instance has invalid interrupt \
        line number!\n");                   
    }
    else
    {
        /* all checks have passed , we have a dmtimer instance with 
        valid base address and interrupt line number. */
        status = S_PASS;            
    }                                   
    return(status);    
}

/*
* DMTimer interrupt service routine. This ISR sets the shared variable on 
* hitting an overflow interrupt - this is not a generic ISR
*/
void DmtimerAppCountdownIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    dmtimerAppCdt_t *pCountdownTimerObj = 
                                (dmtimerAppCdt_t *)pUserParam; 
    /* Disable the DMTimer interrupts */
    DMTimerIntDisable(pCountdownTimerObj->dmtimerObj.instAddr,
        DMTIMER_INTR_MASK_OVF);

    /* Clear the status of the interrupt flags */         
    DMTimerIntStatusClear(pCountdownTimerObj->dmtimerObj.instAddr,
                                        DMTIMER_INTR_MASK_OVF);
    gDmtimerIsrFlag = 1U;

    /* Enable the DMTimer interrupts */
    DMTimerIntEnable(pCountdownTimerObj->dmtimerObj.instAddr,
                                            DMTIMER_INTR_MASK_OVF);                                          
}