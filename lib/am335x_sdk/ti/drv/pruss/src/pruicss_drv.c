/*
* Copyright (C) 2015-2019 Texas Instruments Incorporated - http://www.ti.com/
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
/** ============================================================================
 * @file      pruicss_drv.c
 *
 * @brief     This file contains device abstraction layer APIs for the
 *            PRU Subsystem. There are APIs here to enable/disable the
 *            PRU instance, Load program to PRU and Write to PRU memory.
 ============================================================================*/
#include <stdint.h>
#include <string.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/pruss/src/pruicss_osal.h>

#include <ti/csl/cslr.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_pru_ctrl.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_intc.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_cfg.h>
#include <ti/csl/hw_types.h>

#include <ti/osal/SemaphoreP.h>

/*****************************************************************************/
/*                      INTERNAL MACRO DEFINITIONS                           */
/*****************************************************************************/
/* Value that needs to be written to bit 0 of PRU_ICSS CTRL register to soft reset PRU*/
#define PRUICSS_PRU_SOFT_RESET_VAL                    ((uint32_t)0U)

static uintptr_t pruicss_get_ctrl_addr (PRUICSS_HwAttrs const *hwAttrs,
                                        uint8_t pruNum);

static uintptr_t pruicss_get_ctrl_addr (PRUICSS_HwAttrs const *hwAttrs,
                                        uint8_t pruNum)
{
    uintptr_t baseaddr = 0U;

    if (hwAttrs != NULL)
    {
        switch (pruNum)
        {
            case PRUICCSS_PRU0:
                baseaddr = hwAttrs->prussPru0CtrlRegBase;
                break;
            case PRUICCSS_PRU1:
                baseaddr = hwAttrs->prussPru1CtrlRegBase;
                break;
            case PRUICCSS_RTU0:
                baseaddr = hwAttrs->prussRtu0CtrlRegBase;
                break;
            case PRUICCSS_RTU1:
                baseaddr = hwAttrs->prussRtu1CtrlRegBase;
                break;
            case PRUICCSS_TPRU0:
                baseaddr = hwAttrs->prussTxPru0CtrlRegBase;
                break;
            case PRUICCSS_TPRU1:
                baseaddr = hwAttrs->prussTxPru1CtrlRegBase;
                break;
            default:
                break;
        }
    }
    return baseaddr;
}

/**************************************************************************/
/*                     API FUNCTION DEFINITIONS                           */
/**************************************************************************/
/**
 * @brief   This function creates the handle for the PRUICSS instance \n
 *
 * @param   config   configuration structure of PRUICSS.
 * @param   instance PRUICSS instance no.
 *
 * @return  PRUICSS handle. \n
 */
PRUICSS_Handle  PRUICSS_create(PRUICSS_Config *config, int32_t instance)
{
    PRUICSS_Handle handle;
    PRUICSS_V1_Object *object;
    PRUICSS_HwAttrs      const    *hwAttrs;
    uintptr_t temp_addr = 0U;
    uint32_t temp_val;

    if ((config == NULL) || (instance < PRUICCSS_INSTANCE_ONE) ||  (instance >= PRUICCSS_INSTANCE_MAX))
    {
        return NULL;
    }
    handle = (PRUICSS_Config *)&config[instance-1];
    hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
    object = (PRUICSS_V1_Object*)handle->object;
    object->instance = instance;
    temp_addr = (hwAttrs->prussCfgRegBase + CSL_ICSSCFG_REVID);
    temp_val = CSL_REG32_RD(temp_addr) & 0xFFFFU;
    object->pruicss_version = temp_val;
    return(&config[instance-1]);
}

/**
 * @brief  This function sets the buffer pointer for PRU. The contents of this buffer will be \n
 *         loaded to IRAM.\n
 *
 * @param   handle     Pruss's driver handle
 * @param   pruNum     The PRU number.\n
 * @param   buffer     Pointer to buffer.\n
 * @param   numBytes   Number of bytes in the buffer.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_setPRUBuffer(PRUICSS_Handle handle,
                               uint32_t pruNum,
                               void *buffer,
                               uint32_t numBytes
                               )
{
    PRUICSS_V1_Object           *object;
    int32_t                      ret_val = PRUICSS_RETURN_FAILURE;

    if ((handle != NULL) && (pruNum  < PRUICSS_MAX_PRU))
    {
        if(buffer != NULL)
        {
          object = (PRUICSS_V1_Object *)handle->object;
          object->pruBinBuff[pruNum] = buffer;
          object->buffLen[pruNum] = numBytes;
          ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    return ret_val;
}

/**
 * @brief    Resets PRU: \n
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum     PRU instance number[0 or 1].
 *
 * @return   0 in case of successful reset, -1 otherwise.
 */
int32_t PRUICSS_pruReset(PRUICSS_Handle handle, uint8_t pruNum)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;

    if ((handle != NULL) && (pruNum < PRUICSS_MAX_PRU))
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        baseaddr = pruicss_get_ctrl_addr (hwAttrs, pruNum);
        if(baseaddr != 0U)
        {
            HW_WR_REG32((baseaddr) + CSL_ICSSPRUCTRL_CONTROL, 0);
            ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    return ret_val;
}
/**
 * @brief    Disables PRU: \n
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum     PRU instance number[0 or 1].
 *
 * @return   0 in case of successful disable, -1 otherwise.
 **/
int32_t PRUICSS_pruDisable(PRUICSS_Handle handle, uint8_t pruNum)
{
    uintptr_t baseaddr = 0;
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;

    if ((handle != NULL) && (pruNum < PRUICSS_MAX_PRU))
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        baseaddr = pruicss_get_ctrl_addr (hwAttrs, pruNum);
        if(baseaddr != 0U) 
        {
           HW_WR_FIELD32((baseaddr), CSL_ICSSPRUCTRL_CONTROL_ENABLE, CSL_ICSSPRUCTRL_CONTROL_ENABLE_RESETVAL);
           ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    return ret_val;
}

/**
 * @brief    Enables PRU: \n
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum     PRU instance number[0 or 1].
 *
 * @return   0 in case of successful enable, -1 otherwise.
 **/
int32_t PRUICSS_pruEnable(PRUICSS_Handle handle,uint8_t pruNum)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;

    if ((handle != NULL) && (pruNum < PRUICSS_MAX_PRU))
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        baseaddr = pruicss_get_ctrl_addr (hwAttrs, pruNum);
        if(baseaddr != 0U)
        {
            HW_WR_FIELD32((baseaddr), CSL_ICSSPRUCTRL_CONTROL_ENABLE, CSL_ICSSPRUCTRL_CONTROL_ENABLE_MAX);
            ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    return ret_val;
}
/**
 * @brief    Enables PRU Cycle Counter: \n
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum     PRU instance number[0 or 1].
 *
 * @return   0 in case of successful enable, -1 otherwise.
 **/
int32_t PRUICSS_pruCounterEnable(PRUICSS_Handle handle, uint8_t pruNum)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;

    if ((handle != NULL) && (pruNum < PRUICSS_MAX_PRU))
    {
        hwAttrs = (const PRUICSS_HwAttrs *)handle->hwAttrs;
        baseaddr = pruicss_get_ctrl_addr (hwAttrs, pruNum);
        if(baseaddr != 0U)
        {
            HW_WR_FIELD32((baseaddr), CSL_ICSSPRUCTRL_CONTROL_COUNTER_ENABLE, CSL_ICSSPRUCTRL_CONTROL_COUNTER_ENABLE_MAX);
            ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    return ret_val;
}

void  pruicss_get_mem_info(uint32_t pruMem, PRUICSS_HwAttrs const *hwAttrs, PRUSS_MemInfo *pMemInfo)
{
    switch(pruMem)
    {
        case PRU_ICSS_DATARAM(0U):
            pMemInfo->addr = hwAttrs->prussPru0DramBase;
            pMemInfo->size = hwAttrs->prussPru0DramSize;
            break;
        case PRU_ICSS_DATARAM(1U):
            pMemInfo->addr = hwAttrs->prussPru1DramBase;
            pMemInfo->size = hwAttrs->prussPru1DramSize;
            break;
        case PRU_ICSS_SHARED_RAM:
            pMemInfo->addr = hwAttrs->prussSharedDramBase;
            pMemInfo->size = hwAttrs->prussSharedDramSize;
            break;
        case PRU_ICSS_IRAM_PRU(0U):
            pMemInfo->addr = hwAttrs->prussPru0IramBase;
            pMemInfo->size = hwAttrs->prussPru0IramSize;
            break;
        case PRU_ICSS_IRAM_PRU(1U):
            pMemInfo->addr = hwAttrs->prussPru1IramBase;
            pMemInfo->size = hwAttrs->prussPru1IramSize;
            break;
        case PRU_ICSS_IRAM_RTU(0U):
            pMemInfo->addr = hwAttrs->prussRtu0IramBase;
            pMemInfo->size = hwAttrs->prussRtu0IramSize;
            break;
        case PRU_ICSS_IRAM_RTU(1U):
            pMemInfo->addr = hwAttrs->prussRtu1IramBase;
            pMemInfo->size = hwAttrs->prussRtu1IramSize;
            break;
        case PRU_ICSS_IRAM_TXPRU(0U):
            pMemInfo->addr = hwAttrs->prussTxPru0IramBase;
            pMemInfo->size = hwAttrs->prussTxPru0IramSize;
            break;
         case PRU_ICSS_IRAM_TXPRU(1U):
            pMemInfo->addr = hwAttrs->prussTxPru1IramBase;
            pMemInfo->size = hwAttrs->prussTxPru1IramSize;
            break;
        default:
            pMemInfo->addr = 0U;
            pMemInfo->size = 0U;
            break;
    }
}

/**
 *
 *  @brief   This function writes the given data to PRU memory
 *
 * @param    handle     Pruss's driver handle
 * @param    pruMem     PRU Memory Macro
 * @param    wordoffset Offset at which the write will happen.
 * @param    source_mem Source memory[ Array of uint32_tegers ]
 * @param    bytelength Total number of bytes to be writen
 *
 * pruMem can have the following values
 *      PRU_ICSS_SHARED_RAM\n
 *      PRU_ICSS_DATARAM(n) where n is the PRU number\n
 *      PRU_ICSS_IRAM(n) where n = 0 for PRU0,n = 1 for PRU1, n = 2 for RTU0, n = 3 for RTU1, maintaing this for backward compabitility , should use macros below\n
 *      PRU_ICSS_IRAM_PRU(n) where n = 0 for PRU0,n = 1 for PRU1\n
 *      PRU_ICSS_IRAM_RTU(n) where n = 0 for RTU0,n = 1 for RTU1\n
 *      PRU_ICSS_IRAM_TXPRU(n) where n = 0 for TXPRU0,n = 1 for TXPRU1
 * @return                   word length written or 0 on error.
 *
 **/
int32_t PRUICSS_pruWriteMemory(
                                 PRUICSS_Handle handle,
                                 uint32_t pruMem,
                                 uint32_t wordoffset,
                                 const uint32_t *source_mem,
                                 uint32_t bytelength
                               )
{
    uintptr_t temp_addr = 0U;
    int32_t i, wordlength = 0;
    PRUSS_MemInfo memInfo = {0U, 0U};
    PRUICSS_HwAttrs const *hwAttrs;

    if (handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        pruicss_get_mem_info(pruMem, hwAttrs, &memInfo);

        if (memInfo.addr != 0U)
        {
            wordlength = (bytelength + 3U) >> 2U;
            for (i = 0; i < wordlength; i++)
            {
                temp_addr = (memInfo.addr + (i << 2) + wordoffset);
                CSL_REG32_WR(temp_addr, source_mem[i]);
            }
        }
    }
    return wordlength;
}

/**
 *
 *  @brief   This function intialize the PRU memory to zero
 *
 * @param    handle     Pruss's driver handle
 * @param    pruMem     PRU Memory Macro
 *
 * pruMem can have the following values
 *      PRU_ICSS_SHARED_RAM\n
 *      PRU_ICSS_DATARAM(n) where n is the PRU number\n
 *      PRU_ICSS_IRAM(n) where n = 0 for PRU0,n = 1 for PRU1, n = 2 for RTU0, n = 3 for RTU1, maintaing this for backward compabitility , should use macros below\n
 *      PRU_ICSS_IRAM_PRU(n) where n = 0 for PRU0,n = 1 for PRU1\n
 *      PRU_ICSS_IRAM_RTU(n) where n = 0 for RTU0,n = 1 for RTU1\n
 *      PRU_ICSS_IRAM_TXPRU(n) where n = 0 for TXPRU0,n = 1 for TXPRU1
 * @return                   word length written or 0 on error.
 *
 **/
int32_t PRUICSS_pruInitMemory(
                                 PRUICSS_Handle handle,
                                 uint32_t pruMem
                               )
{
    uintptr_t               temp_addr = 0U;
    uint32_t                 i = 0;
    PRUSS_MemInfo           memInfo = {0U, 0U};
    PRUICSS_HwAttrs const   *hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;

    if (handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        pruicss_get_mem_info(pruMem, hwAttrs, &memInfo);
        if(memInfo.size > 0)
        {
            for (i = 0U; i < memInfo.size; i = i+4U)
            {
                temp_addr = (memInfo.addr+ (uint32_t)i);
                HW_WR_REG32(temp_addr,(uint32_t)0x0);
            }
        }
    }
    return (int32_t)memInfo.size;
}
/**
 *
 *  @brief   This function reads from PRU memory and stores in block of memory
 *
 * @param     handle     Pruss's driver handle
 * @param     pruMem         PRU Memory Macro
 * @param     wordoffset     Offset at which the read will happen.
 * @param     dest_mem       Destination memory[ Array of uint32_tegers ]
 * @param     bytelength     Total number of bytes to be read
 *
 * pruMem can have the following values
 *      PRU_ICSS_SHARED_RAM\n
 *      PRU_ICSS_DATARAM(n) where n is the PRU number\n
 *      PRU_ICSS_IRAM(n) where n = 0 for PRU0,n = 1 for PRU1, n = 2 for RTU0, n = 3 for RTU1, maintaing this for backward compabitility , should use macros below\n
 *      PRU_ICSS_IRAM_PRU(n) where n = 0 for PRU0,n = 1 for PRU1\n
 *      PRU_ICSS_IRAM_RTU(n) where n = 0 for RTU0,n = 1 for RTU1\n
 *      PRU_ICSS_IRAM_TXPRU(n) where n = 0 for TXPRU0,n = 1 for TXPRU1
 * @return                    word length read or 0 on error.
 *
 **/
int32_t PRUICSS_pruReadMemory(
        PRUICSS_Handle handle,
        uint32_t pruMem,
        uint32_t wordoffset,
        uint32_t *dest_mem,
        uint32_t bytelength
        )
{
    uintptr_t               temp_addr = 0U;
    uint32_t                i, wordlength = 0U;
    PRUSS_MemInfo           memInfo = {0U, 0U};
    PRUICSS_HwAttrs const   *hwAttrs;

    if (handle != NULL)
    {
        wordlength = (bytelength + 3U) >> 2U;
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        pruicss_get_mem_info(pruMem, hwAttrs, &memInfo);

        if (memInfo.addr != 0)
        {
            for (i = 0; i < wordlength; i++)
            {
                temp_addr = (memInfo.addr+ (i << 2) + wordoffset);
                dest_mem[i] = CSL_REG32_RD(temp_addr);
            }
        }
    }
    return (int32_t)wordlength;
}

/**
 * @brief  This function Generates an INTC event \n
 *
 * @param   handle     Pruss's driver handle
 * @param   eventnum   The INTC Event number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 **/
int32_t PRUICSS_pruSendEvent(PRUICSS_Handle handle,uint32_t eventnum)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;
    uintptr_t temp_addr = 0U;
    uint32_t temp_var = 0U;

    if (handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        baseaddr = hwAttrs->prussIntcRegBase;
        if(eventnum < 32U)
        {
            temp_addr = (baseaddr + CSL_ICSSINTC_SRSR0);
            temp_var = (((uint32_t)1U) << eventnum);
            HW_WR_FIELD32(temp_addr, CSL_ICSSINTC_SRSR0_RAW_STATUS_31_0, temp_var);
        }
        else
        {
            temp_addr = (baseaddr + CSL_ICSSINTC_SRSR1);
            temp_var = (((uint32_t)1U) << (eventnum - 32U));
            HW_WR_FIELD32(temp_addr, CSL_ICSSINTC_SRSR1_RAW_STATUS_63_32, temp_var);
        }
        ret_val = PRUICSS_RETURN_SUCCESS;
    }
    return  ret_val;
}

/**
 * @brief  This function clears an INTC event \n
 *
 * @param   handle     Pruss's driver handle
 * @param   eventnum   The INTC Event number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 **/
int32_t PRUICSS_pruClearEvent(PRUICSS_Handle handle,uint32_t eventnum)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;

    if (handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        baseaddr = hwAttrs->prussIntcRegBase;
        HW_WR_FIELD32((baseaddr + CSL_ICSSINTC_SICR), CSL_ICSSINTC_SICR_STATUS_CLR_INDEX, eventnum);
        ret_val = PRUICSS_RETURN_SUCCESS;
    }
    return  ret_val;
}

/**
 * @brief  This function waits for a Syatem event to happen \n
 *
 * @param   handle         Pruss's driver handle
 * @param   pruEvtoutNum   The AINTC Event number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruWaitEvent(PRUICSS_Handle handle,uint32_t pruEvtoutNum )
{
    PRUICSS_V1_Object           *object;
    int32_t                      ret_val = PRUICSS_RETURN_FAILURE;

    if ((handle != NULL) && (pruEvtoutNum < PRUICSS_MAX_WAIT_EVENTS))
    {
        object = (PRUICSS_V1_Object *)handle->object;
        if (object->pruEvntOutFnMapArray[pruEvtoutNum].semHandle != NULL)
        {
            PRUICSS_osalPendLock(object->pruEvntOutFnMapArray[pruEvtoutNum].semHandle,PRUICSS_WAIT_FOREVER);
            ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    return ret_val;
}

/**
 * @brief  This function returns the address of PRU components.
 *
 * @param   handle       Pruss's driver handle
 * @param   pru_ram_id   PRU components' Id. \n
 * @param   address      Memory to which address to be copied. \n
 *
 * @return 0 in case of success, -1 otherwise. \n
 **/
int32_t PRUICSS_mapPruMem(PRUICSS_Handle handle,uint32_t pru_ram_id, void **address)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs      const    *hwAttrs;
    uintptr_t temp_addr = 0U;
    int32_t ret_val = PRUICSS_RETURN_SUCCESS;

    hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
    baseaddr = hwAttrs->baseAddr;

    switch (pru_ram_id) {
    case PRUICSS_PRU0_DATARAM:
        temp_addr = (baseaddr + PRU_ICSS_DATARAM(0U));
        *address = (void*)(temp_addr);
        break;
    case PRUICSS_PRU1_DATARAM:
        temp_addr = (baseaddr + PRU_ICSS_DATARAM(1U));
        *address = (void*)(temp_addr);
        break;
    case PRUICSS_SHARED_DATARAM:
        temp_addr = (baseaddr + PRU_ICSS_SHARED_RAM);
        *address = (void*)(temp_addr);
        break;
    default:
        *address = 0;
        ret_val = PRUICSS_RETURN_FAILURE;
        break;
    }
    return ret_val;
}

/**
 * @brief  This function returns the base address of peripheral IO modules.
 *
 * @param   handle   Pruss's driver handle
 * @param   per_id   Peripheral Module's Id.
 * @param   address  Memory to which address to be copied. \n
 *
 *
 * @return 0 in case of success, -1 otherwise. \n
 **/
 int32_t PRUICSS_mapPeripheralIO(PRUICSS_Handle handle,uint32_t per_id,
               void **address)
{
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_SUCCESS;

    if (handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        switch (per_id)
        {
            case PRUICSS_CFG:
                *address = (void*)(hwAttrs->prussCfgRegBase);
                break;
            case PRUICSS_UART:
                *address = (void*)(hwAttrs->prussUartRegBase);
                break;
            case PRUICSS_IEP:
                *address = (void*)(hwAttrs->prussIepRegBase);
                break;
            case PRUICSS_ECAP:
                *address = (void*)(hwAttrs->prussEcapRegBase);
                break;
            case PRUICSS_MII_RT:
                *address = (void*)( hwAttrs->prussMiiRtCfgRegBase);
                break;
            case PRUICSS_MDIO:
                *address = (void*)(hwAttrs->prussMiiMdioRegBase);
                break;
            default:
                *address = 0;
                ret_val = PRUICSS_RETURN_FAILURE;
                break;
        }
    }
    else
    {
        ret_val = PRUICSS_RETURN_FAILURE;
    }
    return ret_val;
}

void PRUICSS_enableOCPMasterAccess(PRUICSS_Handle handle )
{
    uintptr_t baseaddr =0U;
    PRUICSS_HwAttrs      const    *hwAttrs;

    if (handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        baseaddr = hwAttrs->prussCfgRegBase;
        HW_WR_FIELD32((baseaddr + CSL_ICSSCFG_SYSCFG),CSL_ICSSCFG_SYSCFG_STANDBY_INIT, 0);
    }
}

/**
 * @brief    Detects the Chip Type \n
 *
 * @return   0
 */
uint32_t PRUICSS_detectHWVersion(void)
{
    return 0U;
}

/**
 * @brief    Get PRU ICSS version : \n
 *
 * @param    handle     Pruss's driver handle
 *
 * @return   ICSS HW version
 **/
uint32_t PRUICSS_getICSSVersion(PRUICSS_Handle handle)
{
    PRUICSS_V1_Object    *object;
    object = (PRUICSS_V1_Object *)handle->object;
    return object->pruicss_version;
}

/**
 * @brief   This function Executes the program in the specified PRU \n
 *
 * @param   handle    Pruss's driver handle
 * @param   pruNum    PRU instance number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruExecProgram(PRUICSS_Handle handle,int32_t pruNum)
{
    PRUICSS_V1_Object           *object;
    int32_t                      ret_val = PRUICSS_RETURN_FAILURE;

    if(handle != NULL)
    {
        object = (PRUICSS_V1_Object *)handle->object;
        if((object->pruBinBuff[pruNum] != NULL) && (object->buffLen[pruNum] != 0U) && (pruNum <  PRUICSS_MAX_PRU))
        {
            PRUICSS_pruDisable(handle,(uint8_t)pruNum);
            if (pruNum <= PRUICCSS_RTU1)
            {
                PRUICSS_pruInitMemory(handle,PRU_ICSS_IRAM((uint32_t)pruNum));
                PRUICSS_pruWriteMemory(handle,PRU_ICSS_IRAM((uint32_t)pruNum),0U,(uint32_t *) object->pruBinBuff[pruNum],object->buffLen[pruNum]);
            }
            else
            {
                if (pruNum == PRUICCSS_TPRU0)
                {
                    PRUICSS_pruInitMemory(handle,PRU_ICSS_IRAM_TXPRU(0U));
                    PRUICSS_pruWriteMemory(handle,PRU_ICSS_IRAM_TXPRU(0U),0U,(uint32_t *) object->pruBinBuff[pruNum],object->buffLen[pruNum]);
                }
                else
                {
                    PRUICSS_pruInitMemory(handle,PRU_ICSS_IRAM_TXPRU(1U));
                    PRUICSS_pruWriteMemory(handle,PRU_ICSS_IRAM_TXPRU(1U),0U,(uint32_t *) object->pruBinBuff[pruNum],object->buffLen[pruNum]);
                }
            }
            PRUICSS_pruReset(handle,(uint8_t)pruNum);
            PRUICSS_pruEnable(handle,(uint8_t)pruNum);
            ret_val = PRUICSS_RETURN_SUCCESS;
        }
    }
    
    return(ret_val);
}


/**
 * \brief  This function generates and INTC event, waits for AINTC event and
 *             clears an INTC event \n
 *
 * @param   handle         Pruss's driver handle
 * @param   sendEventNum   Event number.\n
 * @param   pruEvtoutNum   PRU Event number.\n
 * @param   ackEventNum    Acknowlodegement event number.\n
 *
 * \return  0 in case of successful transition, -1 otherwise. \n
 */
 int32_t PRUICSS_pruSendWaitCearEvent(  PRUICSS_Handle handle,
                                        uint32_t sendEventNum,
                                        uint32_t pruEvtoutNum,
                                        uint32_t ackEventNum
                                     )
{
    PRUICSS_pruSendEvent(handle,sendEventNum);
    PRUICSS_pruWaitEvent(handle,pruEvtoutNum);
    PRUICSS_pruClearEvent(handle,ackEventNum);
    return PRUICSS_RETURN_SUCCESS;
}

/**
 * @brief   Configure PIN_MUX_SEL
 *
 * @param   handle          Pruss's driver handle
 * @param   regVal          value to be written
 *
 * @return  None.
 *
 **/
void PRUICSS_pinMuxConfig(PRUICSS_Handle handle, uint64_t regVal)
{
    uintptr_t baseaddr;
    PRUICSS_HwAttrs const *hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;

    if (handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        baseaddr = hwAttrs->prussCfgRegBase;
        HW_WR_FIELD32((baseaddr + CSL_ICSSCFG_PIN_MX),CSL_ICSSCFG_PIN_MX_PIN_MUX_SEL, regVal);
    }
}

/**
 * \brief  This API gets the SoC level of PRUICSS intial configuration
 *
 * \param  cfg       Pointer to PRUICSS SOC initial config.
 *
 * \return 0 success
 *
 */
int32_t PRUICSS_socGetInitCfg( PRUICSS_Config **cfg)
{

#ifndef __LINUX_USER_SPACE
    *cfg = &pruss_config[0];
#endif

    return PRUICSS_RETURN_SUCCESS;
}

/**
 * \brief  This API sets the SoC level of PRUICSS intial configuration
 *
 * \param  cfg       Pointer to PRUICSS SOC initial config.
 *
 * \return           0 success
 *
 */
int32_t PRUICSS_socSetInitCfg(PRUICSS_Config const *cfg)
{
#ifndef __LINUX_USER_SPACE
    uint32_t len  = sizeof(PRUICSS_Config) * (PRUICCSS_INSTANCE_MAX -1U);
    memcpy(&pruss_config, cfg, len);
#endif
    return PRUICSS_RETURN_SUCCESS;
}

/**
 * \brief  This API updates the constant table  for specified constant table entry
             which have write permissions.
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum PRU number[0 or 1] for which constant table is being updated.
 * @param    constantTblEntry contant table entry being updated
 * @param    constantTblVal contant table value to be written
 *
 * \return           0 success, -1 on error
 *
 */
int32_t PRUICSS_setConstantTblEntry(PRUICSS_Handle handle, uint8_t pruNum, int32_t constantTblEntry, uint32_t constantTblVal)
{
    PRUICSS_HwAttrs const   *hwAttrs = NULL;
    uint32_t baseaddr = 0U;
    uintptr_t tempaddr = 0U;
    uint32_t tempval = 0U;
    uint32_t currentval = 0U;
    int32_t ret_val = PRUICSS_RETURN_SUCCESS;

    static uint32_t pruicssConstantIndex[PRUICCSS_ConstTblEntryMax] =
    {
        CSL_ICSSPRUCTRL_CTBIR0,     /*For enry 24, PRU-ICSS PRU0 Data RAM */
        CSL_ICSSPRUCTRL_CTBIR0,     /*For enry 25, PRU-ICSS PRU1 Data RAM */
        CSL_ICSSPRUCTRL_CTBIR1,     /*For enry 26, PRU-ICSS IEP */
        CSL_ICSSPRUCTRL_CTBIR1,     /*For enry 27, PRU-ICSS MII_RT*/
        CSL_ICSSPRUCTRL_CTPPR0,     /*For enry 28, PRU-ICSS Shared RAM*/
        CSL_ICSSPRUCTRL_CTPPR0,     /*For enry 29, TPCC*/
        CSL_ICSSPRUCTRL_CTPPR1,     /*For enry 30, L3 OCMC0 */
        CSL_ICSSPRUCTRL_CTPPR1      /*For enry 31, EMIF0 DDR Base */
    };

    /* verify constant table index is within valid range */
    if (((constantTblEntry < 0) || (constantTblEntry >= PRUICCSS_ConstTblEntryMax)) || (pruNum > PRUICSS_MAX_PRU))
    {
        ret_val = PRUICSS_RETURN_FAILURE;
    }
    else
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        if(PRUICCSS_PRU0 == pruNum) 
        {
            baseaddr = hwAttrs->prussPru0CtrlRegBase;
        }
        else if(PRUICCSS_PRU1 == pruNum)
        {
            baseaddr = hwAttrs->prussPru1CtrlRegBase;
        }
        else
        {
            ret_val = PRUICSS_RETURN_FAILURE;
        }
        if (ret_val == PRUICSS_RETURN_SUCCESS)
        {
            tempaddr = baseaddr + pruicssConstantIndex[constantTblEntry];
            switch (constantTblEntry)
            {
                case PRUICCSS_ConstTblEntryC24:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTBIR0_C24_BLK_INDEX_MASK));
                    tempval = CSL_ICSSPRUCTRL_CTBIR0_C24_BLK_INDEX_MASK & constantTblVal;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                case PRUICCSS_ConstTblEntryC25:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTBIR0_C25_BLK_INDEX_MASK));
                    tempval = constantTblVal << CSL_ICSSPRUCTRL_CTBIR0_C25_BLK_INDEX_SHIFT;
                    tempval = CSL_ICSSPRUCTRL_CTBIR0_C25_BLK_INDEX_MASK & tempval;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                case PRUICCSS_ConstTblEntryC26:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTBIR1_C26_BLK_INDEX_MASK));
                    tempval = constantTblVal << CSL_ICSSPRUCTRL_CTBIR1_C26_BLK_INDEX_SHIFT;
                    tempval = CSL_ICSSPRUCTRL_CTBIR1_C26_BLK_INDEX_MASK & tempval;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                case PRUICCSS_ConstTblEntryC27:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTBIR1_C27_BLK_INDEX_MASK));
                    tempval = constantTblVal << CSL_ICSSPRUCTRL_CTBIR1_C27_BLK_INDEX_SHIFT;
                    tempval = CSL_ICSSPRUCTRL_CTBIR1_C27_BLK_INDEX_MASK & tempval;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                case PRUICCSS_ConstTblEntryC28:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTPPR0_C28_POINTER_MASK));
                    tempval = constantTblVal << CSL_ICSSPRUCTRL_CTPPR0_C28_POINTER_SHIFT;
                    tempval &= CSL_ICSSPRUCTRL_CTPPR0_C28_POINTER_MASK;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                case PRUICCSS_ConstTblEntryC29:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTPPR0_C29_POINTER_MASK));
                    tempval = constantTblVal << CSL_ICSSPRUCTRL_CTPPR0_C29_POINTER_SHIFT;
                    tempval &= CSL_ICSSPRUCTRL_CTPPR0_C29_POINTER_MASK;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                case PRUICCSS_ConstTblEntryC30:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTPPR1_C30_POINTER_MASK));
                    tempval = constantTblVal << CSL_ICSSPRUCTRL_CTPPR1_C30_POINTER_SHIFT;
                    tempval &= CSL_ICSSPRUCTRL_CTPPR1_C30_POINTER_MASK;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                case PRUICCSS_ConstTblEntryC31:
                {
                    currentval = HW_RD_REG32(tempaddr);
                    currentval &=  (~((uint32_t)CSL_ICSSPRUCTRL_CTPPR1_C31_POINTER_MASK));
                    tempval = constantTblVal << CSL_ICSSPRUCTRL_CTPPR1_C31_POINTER_SHIFT;
                    tempval &= CSL_ICSSPRUCTRL_CTPPR1_C31_POINTER_MASK;
                    HW_WR_REG32(tempaddr,(uint32_t)(currentval |tempval));
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
    return ret_val;
}

/**
 * \brief  This API configures the General Purpose Mux Selector field of
 *          the General Purpose Config Register (PRUSS_GPCFG)
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum PRU number[0 or 1].
 * @param    mode PRU-ICSS wrap mux selection
 *
 * \return           0 success, -1 on error
 *
 */
int32_t PRUICSS_setGpMuxSel(PRUICSS_Handle handle, uint8_t pruNum, uint32_t mode)
{
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;

    if(handle != NULL)
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        switch (pruNum)
        {
            case PRUICCSS_PRU0:
                HW_WR_FIELD32((hwAttrs->prussCfgRegBase+CSL_ICSSCFG_GPCFG0), CSL_ICSSCFG_GPCFG0_PRU0_GP_MUX_SEL, mode);
                ret_val = PRUICSS_RETURN_SUCCESS;
                break;
            case PRUICCSS_PRU1:
                HW_WR_FIELD32((hwAttrs->prussCfgRegBase+CSL_ICSSCFG_GPCFG1), CSL_ICSSCFG_GPCFG0_PRU0_GP_MUX_SEL, mode);
                ret_val = PRUICSS_RETURN_SUCCESS;
                break;
            default:
                break;
        }
    }
    return ret_val;
    
}

/**
 * \brief  This API configures the source of the IEP clock to be either
 *          IEP CLK as the source or Interface Bus CLK as the source (such as OCP/ICLK/VCLK)
 *          This is accomplished by updating the IEP clock field of the General Purpose Config 
 *          Register (PRUSS_GPCFG)
 *
 * @param    handle     Pruss's driver handle
 * @param    source source of the IEP clock (0 == IEP CLK, 1 == OCP/ICLK/VCLK)
 *
 * \return           0 success, -1 on error
 *
 */
int32_t PRUICSS_setIepClkSrc(PRUICSS_Handle handle,  uint32_t source)
{
    PRUICSS_HwAttrs      const    *hwAttrs;
    int32_t ret_val = PRUICSS_RETURN_FAILURE;

    if ((handle != NULL) && ((source == 1U) || (source == 0U)))
    {
        hwAttrs = (PRUICSS_HwAttrs const *)handle->hwAttrs;
        HW_WR_FIELD32((hwAttrs->prussCfgRegBase+CSL_ICSSCFG_IEPCLK), CSL_ICSSCFG_IEPCLK_OCP_EN, source);
        ret_val = PRUICSS_RETURN_SUCCESS;
    }
    return ret_val;
}

/*****************************END OF FILE************************************/
