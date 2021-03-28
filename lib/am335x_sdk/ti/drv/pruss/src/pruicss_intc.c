 /**
 * @file      pruicss_intc.c
 *
 * @brief     This file contains interrupts handling function of
 *            PRU Subsystem. There are APIs here to configuring the ICS INTC,
              registering the IRQ/event and waiting for event.
 */

/*
* Copyright (C) 2015-2018 Texas Instruments Incorporated - http://www.ti.com/
*
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
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/pruss/src/pruicss_osal.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_intc.h>
#include <ti/csl/hw_types.h>

#include <ti/osal/SemaphoreP.h>
#include <ti/osal/HwiP.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * @brief   Sets System-Channel Map registers: \n
 *
 * @param   sysevt         system event number
 * @param   channel        Host channel number.
 * @param   polarity       polarity of event.
 * @param   type           Type of event.
 * @param   baseaddr    .  base address of PRUICSS
 *
 * @return   None.
 */
static void PRUICSS_intcSetCmr(uint8_t sysevt,
                               uint8_t channel,
                               uint8_t polarity,
                               uint8_t type,
                               uintptr_t baseaddr);
/**
 * \brief    Sets Channel-Host Map registers: \n
 *
 * \param    channel         Channel number.
 * \param    host            Host number.
 * @param    baseaddr        base address of PRUICSS
 *
 * \return   None.
 */
static void PRUICSS_intcSetHmr(uint8_t channel,
                               uint8_t host,
                               uintptr_t baseaddr);

/**
 * \brief   PRUICSS interrupt handler
 *
 * \param   arg PRUICSS handler pointer
 *
 *
 * \return  None.
 *
 **/
static void PRUICSS_hwiIntHandler(uintptr_t ptrPpruEvtoutNum);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/*static volatile PRUICSS_IrqFunMap pruEvntOutFnMapArray[PRUICSSDRV_MAX_WAIT_EVENTS]
                                                    [PRUICSSDRV_MAX_WAIT_EVENTS];*/

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * @brief  This function does Interrupt-Channel-host mapping.
 *
 * @param   handle                Pruss's driver handle
 * @param   prussintc_init_data   The pointer to structure containing mapping information.
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruIntcInit(PRUICSS_Handle handle, const PRUICSS_IntcInitData * prussintc_init_data)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    PRUICSS_V1_Object    *object;

    uint32_t i = 0, mask1 = 0, mask2 = 0;

    uintptr_t temp_addr = 0U;

    int32_t ret_val = PRUICSS_RETURN_SUCCESS;

    object = (PRUICSS_V1_Object *)handle->object;
    hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
    baseaddr = hwAttrs->baseAddr;

    if ((object->instance >= PRUICCSS_INSTANCE_ONE) &&
        (object->instance < PRUICCSS_INSTANCE_MAX))
    {
        baseaddr = hwAttrs->prussIntcRegBase;
    }
    else
    {
        ret_val = PRUICSS_RETURN_FAILURE;
    }
   
    if(ret_val == PRUICSS_RETURN_SUCCESS)
    {
        HW_WR_FIELD32((baseaddr + CSL_ICSSINTC_SIPR0), CSL_ICSSINTC_SIPR0_POLARITY_31_0, 0xFFFFFFFFU);

        HW_WR_FIELD32((baseaddr + CSL_ICSSINTC_SIPR1), CSL_ICSSINTC_SIPR0_POLARITY_31_0, 0xFFFFFFFFU);

        HW_WR_FIELD32((baseaddr + CSL_ICSSINTC_SITR0), CSL_ICSSINTC_SIPR0_POLARITY_31_0, 0xFFFFFFFFU);

        HW_WR_FIELD32((baseaddr + CSL_ICSSINTC_SITR1), CSL_ICSSINTC_SIPR0_POLARITY_31_0, 0xFFFFFFFFU);

        for (i = 0; i < (PRUICSS_NUM_PRU_SYS_EVTS + 3U) >> 2; i++)
        {
            temp_addr = ((baseaddr +  CSL_ICSSINTC_CMR0 ) + (i << 2));
            CSL_REG32_WR(temp_addr, 0);
        }
        for (i = 0;
             ((prussintc_init_data->sysevt_to_channel_map[i].sysevt != 0xFF)
             && (prussintc_init_data->sysevt_to_channel_map[i].channel != 0xFF));
             i++)
        {
            PRUICSS_intcSetCmr(prussintc_init_data->sysevt_to_channel_map[i].sysevt,
                               prussintc_init_data->sysevt_to_channel_map[i].channel,
                               ((uint8_t)(~(prussintc_init_data->sysevt_to_channel_map[i].polarity)))&0x01U,
                               ((uint8_t)(~(prussintc_init_data->sysevt_to_channel_map[i].type)))&0x01U,
                               baseaddr);
        }

        for (i = 0; i < (PRUICSS_NUM_PRU_HOSTS + 3U) >> 2; i++)
        {
            temp_addr = (baseaddr  +  CSL_ICSSINTC_HMR0 + (i << 2));
            CSL_REG32_WR(temp_addr, 0);
        }
        for (i = 0;
               ((i<PRUICSS_NUM_PRU_HOSTS) &&
               (prussintc_init_data->channel_to_host_map[i].channel != 0xFF) &&
               (prussintc_init_data->channel_to_host_map[i].host != 0xFF));
               i++)
        {
            PRUICSS_intcSetHmr(prussintc_init_data->channel_to_host_map[i].channel,
                               prussintc_init_data->channel_to_host_map[i].host,
                               baseaddr);
        }


        mask1 = mask2 = 0;
        for (i = 0; (uint8_t)prussintc_init_data->sysevts_enabled[i] != 0xFFU; i++)
        {
            if (prussintc_init_data->sysevts_enabled[i] < 32)
            {
                mask1 = mask1 + (((uint32_t)1U) << (prussintc_init_data->sysevts_enabled[i]));
            }
            else if (prussintc_init_data->sysevts_enabled[i] < 64)
            {
                mask2 = mask2 + (((uint32_t)1U) << (prussintc_init_data->sysevts_enabled[i] - 32));
            }
            else
            {
                /* Error */
                ret_val = PRUICSS_RETURN_FAILURE;
                break;
            }
        }
    }
   
    if(ret_val == PRUICSS_RETURN_SUCCESS)
    {
        HW_WR_FIELD32((baseaddr  + CSL_ICSSINTC_ESR0),CSL_ICSSINTC_ESR0_ENABLE_SET_31_0, mask1);

        HW_WR_FIELD32((baseaddr  + CSL_ICSSINTC_SECR0),CSL_ICSSINTC_SECR0_ENA_STATUS_31_0, mask1);

        HW_WR_FIELD32((baseaddr  + CSL_ICSSINTC_ERS1),CSL_ICSSINTC_ERS1_ENABLE_SET_63_32, mask2);

        HW_WR_FIELD32((baseaddr  + CSL_ICSSINTC_SECR1),CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, mask2);

        HW_WR_FIELD32((baseaddr  + CSL_ICSSINTC_HIER),CSL_ICSSINTC_HIER_ENABLE_HINT,prussintc_init_data->host_enable_bitmask);

        HW_WR_FIELD32((baseaddr  + CSL_ICSSINTC_GER),CSL_ICSSINTC_GER_ENABLE_HINT_ANY, 0x1);
    }
    return ret_val;
}


/**
 * @brief  This function Registers an Interrupt Handler for an event.\n
 *
 * @param   pruEvtoutNum   The ARM side event number.\n
 *
 * @param   handle         Pruss's driver handle
 *
 * @param  intrNum        Interrupt number of MPU/C66x
 *
 * @param  eventNum       Event number of PRUICSS
 *
 * @param  waitEnable     Flag specifying whether application can wait on this interrupt
 *                using PRUICSSPruWaitEvent function
 *
 * @param   irqHandler     Pointer to a function which will be called on interrupt.\n
 *
 * \return  0 in case of successful registration, -1 otherwise. \n
 */
int32_t PRUICSS_registerIrqHandler(PRUICSS_Handle handle,
                                   uint32_t pruEvtoutNum,
                                   int32_t intrNum,
                                   int32_t eventNum,
                                   uint8_t waitEnable,
                                   PRUICSSDRV_IRQ_HANDLER irqHandler
                                  )
{
    PRUICSS_V1_Object          *object;
    SemaphoreP_Params           semParams;
    HwiP_Params                 hwiParams;
      
    HwiP_Handle hwiHandle=NULL;
    void*    semHandle = NULL;
   object = (PRUICSS_V1_Object*)handle->object;

    int32_t ret_val = PRUICSS_RETURN_SUCCESS;

    if ((pruEvtoutNum >= PRUICSS_MAX_WAIT_EVENTS) || (irqHandler == NULL))
    {
        ret_val = PRUICSS_RETURN_FAILURE;
    }
    else
    {
        /* create a Semaphore Instance */
        if(waitEnable)
        {
            PRUICSS_osalSemParamsInit(&semParams);
            semParams.mode = SemaphoreP_Mode_BINARY;
            semHandle = PRUICSS_osalCreateBlockingLock(0, &semParams);

            if(NULL == semHandle)
            {
                ret_val = PRUICSS_RETURN_FAILURE;
            }
        }
                
        if(ret_val == PRUICSS_RETURN_SUCCESS)
        {
            PRUICSS_osalHwiParamsInit(&hwiParams);
            hwiParams.arg = (uintptr_t)(&object->pruEvntOutFnMapArray[pruEvtoutNum]);
            hwiParams.evtId = eventNum;
            hwiParams.priority = 0x20;
            hwiHandle = PRUICSS_osalRegisterInterrupt(intrNum,PRUICSS_hwiIntHandler,&hwiParams);
        }

        if ((hwiHandle == NULL) && (ret_val == PRUICSS_RETURN_SUCCESS))
        {
            if(NULL != semHandle)
            {
                PRUICSS_osalDeleteBlockingLock(semHandle);
            }
            ret_val = PRUICSS_RETURN_FAILURE;
        }

        if(ret_val == PRUICSS_RETURN_SUCCESS)
        {
            object->pruEvntOutFnMapArray[pruEvtoutNum].semHandle = semHandle;
            object->pruEvntOutFnMapArray[pruEvtoutNum].irqHandler = irqHandler;
            object->pruEvntOutFnMapArray[pruEvtoutNum].handle = handle;
            ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    return(ret_val);
}

/**
 * @brief  This function Registers an Interrupt Handler for an event.\n
 *
 * @param   pruEvtoutNum   The ARM side event number.\n
 *
 * @param   handle         Pruss's driver handle
 *
 * @param  intrCfg        pointer to interrupt configuration parameter
 *
 * \return  0 in case of successful registration, -1 otherwise. \n
 */

#ifndef __LINUX_USER_SPACE
int32_t PRUICSS_registerIrqHandler2(PRUICSS_Handle handle,
                                   PRUICSS_IntrCfg const * intrCfg)

{
    PRUICSS_V1_Object          *object;
    SemaphoreP_Params           semParams;
    HwiP_Handle hwiHandle = NULL;
    void*    semHandle = NULL;
    object = (PRUICSS_V1_Object *)handle->object;
    HwiP_Params           hwiInputParams;
    MuxIntcP_inParams       muxInParams;
    MuxIntcP_outParams      muxOutParams = {0U, 0U, NULL};
    HwiP_Fxn    hwiFxn;
    int32_t ret_val = PRUICSS_RETURN_SUCCESS;

    if ((intrCfg->pruEvtoutNum >= PRUICSS_MAX_WAIT_EVENTS) || (intrCfg->irqHandler == NULL))
    {
        ret_val = PRUICSS_RETURN_FAILURE;
    }
    else
    {
        /* create a Semaphore Instance */
        if(intrCfg->waitEnable)
        {
            PRUICSS_osalSemParamsInit(&semParams);
            semParams.mode = SemaphoreP_Mode_BINARY;
            semHandle = PRUICSS_osalCreateBlockingLock(0, &semParams);

            if(NULL == semHandle)
            {
                ret_val = PRUICSS_RETURN_FAILURE;
            }
        }
                
        if(ret_val == PRUICSS_RETURN_SUCCESS)
        {


        PRUICSS_osalHwiParamsInit(&hwiInputParams);
    
        if (intrCfg->intcMuxNum != PRUSS_INVALID_INTC_MUX_NUM)
        {
            /* Setup Chip Interrupt Controller */
            muxInParams.arg         = (uintptr_t)(&object->pruEvntOutFnMapArray[intrCfg->pruEvtoutNum]);
            muxInParams.muxNum      = intrCfg->intcMuxNum;
            muxInParams.muxInEvent  = intrCfg->intcMuxInEvent;
            muxInParams.muxOutEvent =  intrCfg->intcMuxOutEvent;
            muxInParams.muxIntcFxn  = (MuxIntcFxn)(&PRUICSS_hwiIntHandler);
        
            PRUICSS_osalMuxIntcSetup(&muxInParams, &muxOutParams);
        
            hwiFxn                  = (HwiP_Fxn)muxOutParams.muxIntcFxn;
            hwiInputParams.arg = muxOutParams.arg;
        }
        else
        {
            hwiFxn                  = (HwiP_Fxn)(&PRUICSS_hwiIntHandler);
            hwiInputParams.arg = (uintptr_t)(&object->pruEvntOutFnMapArray[intrCfg->pruEvtoutNum]);
        }
        /* Setup Hardware Interrupt Controller */
        hwiInputParams.name = NULL;
        hwiInputParams.priority = 0x20;
    
        hwiInputParams.evtId = intrCfg->eventId;    /*eventNum */


#if defined (__ARM_ARCH_7A__) && defined (SOC_K2G)
        hwiInputParams.triggerSensitivity =2; /* use trigger type edge */
#endif
        hwiHandle = PRUICSS_osalRegisterInterrupt(intrCfg->intNum,hwiFxn,&hwiInputParams);
    }

        if ((hwiHandle == NULL) && (ret_val == PRUICSS_RETURN_SUCCESS))
        {
            if(NULL != semHandle)
            {
                PRUICSS_osalDeleteBlockingLock(semHandle);
            }
            ret_val = PRUICSS_RETURN_FAILURE;
        }
    
        if(ret_val == PRUICSS_RETURN_SUCCESS)
        {
            object->pruEvntOutFnMapArray[intrCfg->pruEvtoutNum].semHandle = semHandle;
            object->pruEvntOutFnMapArray[intrCfg->pruEvtoutNum].irqHandler = intrCfg->irqHandler;
            object->pruEvntOutFnMapArray[intrCfg->pruEvtoutNum].handle = handle;
            ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }    
    return(ret_val);
    }
#endif

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
static void PRUICSS_hwiIntHandler(uintptr_t  ptrPpruEvtoutNum)
{
    PRUICSS_IrqFunMap *pruFunMap;

    pruFunMap = (PRUICSS_IrqFunMap*)ptrPpruEvtoutNum;

    if(pruFunMap != NULL)
    {
        pruFunMap->irqHandler(pruFunMap->handle);
        if(pruFunMap->semHandle != NULL)
        {
          PRUICSS_osalPostLock(pruFunMap->semHandle);
        }
    }
}

static void PRUICSS_intcSetCmr( uint8_t sysevt,
                                uint8_t channel,
                                uint8_t polarity,
                                uint8_t type,
                                uintptr_t baseaddr)
{
    uintptr_t temp_addr1 = 0U;
    uintptr_t temp_addr2 = 0U;

    temp_addr1 = ((baseaddr)+(CSL_ICSSINTC_CMR0 + (((uint32_t)sysevt) & ~((uint32_t)0x3U))));
    CSL_REG32_WR(temp_addr1, CSL_REG32_RD(temp_addr1) | ((((uint32_t)channel) & ((uint32_t)0xFU)) << ((((uint32_t)sysevt) & ((uint32_t)0x3U)) << 3U)));

    if(sysevt < 32U)
    {
        temp_addr1 = (baseaddr + CSL_ICSSINTC_SIPR0);
        temp_addr2 = (baseaddr + CSL_ICSSINTC_SITR0);
        CSL_REG32_WR(temp_addr1, CSL_REG32_RD (temp_addr1) & ~(((uint32_t)polarity) << sysevt));
        CSL_REG32_WR(temp_addr2, CSL_REG32_RD (temp_addr2) & ~(((uint32_t)type) << sysevt));
    }
    else
    {
        temp_addr1 = (baseaddr + CSL_ICSSINTC_SIPR1);
        temp_addr2 = (baseaddr + CSL_ICSSINTC_SITR1);
        CSL_REG32_WR(temp_addr1, CSL_REG32_RD(temp_addr1) & ~(((uint32_t)polarity) << (sysevt - 32U)));
        CSL_REG32_WR(temp_addr2, CSL_REG32_RD(temp_addr2) & ~(((uint32_t)type) << (sysevt - 32U)));
    }
}


static void PRUICSS_intcSetHmr( uint8_t channel,
                                uint8_t host,
                                uintptr_t baseaddr)
{
    uintptr_t temp_addr1 = 0U;
    uintptr_t temp_addr2 = 0U;

    temp_addr1 = ((baseaddr) + (CSL_ICSSINTC_HMR0 + (((uint32_t)channel) & ~((uint32_t)0x3U))));
    temp_addr2 = ((baseaddr) + (CSL_ICSSINTC_HMR0 + (((uint32_t)channel) & ~((uint32_t)0x3U))));
    CSL_REG32_WR(temp_addr1, CSL_REG32_RD(temp_addr2) | ((((uint32_t)host) & ((uint32_t)0xFU)) << ((((uint32_t)channel) & ((uint32_t)0x3U)) << 3U)));
}

/**
 * @brief  This function clears all Interrupt-Channel-host mapping.
 *
 * @param   handle                Pruss's driver handle
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruIntcClear(PRUICSS_Handle handle)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    PRUICSS_V1_Object    *object;

    uint32_t i = 0;

    uintptr_t temp_addr = 0U;

    int32_t ret_val = PRUICSS_RETURN_SUCCESS;

    /* verify the handle */
    if (handle != NULL)
    {
        object = (PRUICSS_V1_Object *)handle->object;
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;

        /* verify the instance */
        if ((object->instance >= PRUICCSS_INSTANCE_ONE) &&
            (object->instance < PRUICCSS_INSTANCE_MAX))
        {
            baseaddr = hwAttrs->prussIntcRegBase;
        }
        else
        {
            ret_val = PRUICSS_RETURN_FAILURE;
        }
    
        if(ret_val == PRUICSS_RETURN_SUCCESS)
        {
            for (i = 0; i < PRUICSS_NUM_PRU_SYS_EVTS >> 2; i++)
            {
                temp_addr = ((baseaddr +  CSL_ICSSINTC_CMR0 ) + (i << 2));
                CSL_REG32_WR(temp_addr, 0);
            }
        
            for (i = 0; i < (PRUICSS_NUM_PRU_HOSTS + 3U) >> 2; i++)
            {
                temp_addr = (baseaddr  +  CSL_ICSSINTC_HMR0 + (i << 2));
                CSL_REG32_WR(temp_addr, 0);
            }

            CSL_REG32_WR(baseaddr + CSL_ICSSINTC_ESR0, 0);

            CSL_REG32_WR(baseaddr + CSL_ICSSINTC_SECR0, 0);

            CSL_REG32_WR(baseaddr + CSL_ICSSINTC_ERS1, 0);

            CSL_REG32_WR(baseaddr + CSL_ICSSINTC_SECR1, 0);

            CSL_REG32_WR(baseaddr + CSL_ICSSINTC_HIER, 0);

            CSL_REG32_WR(baseaddr + CSL_ICSSINTC_GER, 0);
        }
        else
        {
            ret_val = PRUICSS_RETURN_FAILURE;
        }
    }
    else
    {
        ret_val = PRUICSS_RETURN_FAILURE;
    }

    return ret_val;
}

