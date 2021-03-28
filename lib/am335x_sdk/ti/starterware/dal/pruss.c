/**
 * \file      pruss.c
 *
 * \brief     This file contains device abstraction layer APIs for the
 *            PRU Subsystem. There are APIs here to enable/disable the
 *            PRU instance, Load program to PRU and Write to PRU memory.
 */

/*
* Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
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
#include "types.h"
#include "hw/hw_types.h"
#include "pruss.h"
#include "am437x.h"
#include "hw/hw_icss.h"
#include "hw/hw_icss_pru_ctrl.h"
#include "hw/hw_icss_intc.h"
#include "hw/hw_icss_cfg.h"

/*****************************************************************************/
/*                      INTERNAL MACRO DEFINITIONS                           */
/*****************************************************************************/

/**************************************************************************/
/*                     API FUNCTION DEFINITIONS                           */
/**************************************************************************/

int32_t PRUSSDrvPruReset(uint8_t pruNum,uint32_t baseAddr)
{
    int32_t retVal = 0;

    if(PRU0 == pruNum)
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_PRU_CTRL(0)),
                       HW_ICSS_PRU_CTRL_CONTROL_SOFT_RST_N,
                       HW_ICSS_PRU_CTRL_CONTROL_SOFT_RST_N_ENABLE);
    }
    else if(PRU1 == pruNum)
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_PRU_CTRL(1)),
                       HW_ICSS_PRU_CTRL_CONTROL_SOFT_RST_N,
                       HW_ICSS_PRU_CTRL_CONTROL_SOFT_RST_N_ENABLE);
    }
    else
    {
        retVal = -1;
    }

    return retVal;
}

int32_t PRUSSDrvPruDisable(uint8_t pruNum,uint32_t baseAddr)
{
    int32_t retVal = 0;

    if(PRU0 == pruNum)
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_PRU_CTRL(0)),
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE,
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE_DISABLE);
    }
    else if(PRU1 == pruNum)
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_PRU_CTRL(1)),
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE,
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE_DISABLE);
    }
    else
    {
        retVal = -1;
    }

    return retVal;
}

int32_t PRUSSDrvPruEnable(uint8_t pruNum,uint32_t baseAddr)
{
    int32_t retVal = 0;

    if(PRU0 == pruNum)
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_PRU_CTRL(0)),
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE,
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE_ENABLE);
    }
    else if(PRU1 == pruNum)
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_PRU_CTRL(1)),
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE,
                       HW_ICSS_PRU_CTRL_CONTROL_ENABLE_ENABLE);
    }
    else
    {
        retVal = -1;
    }

    return retVal;
}

uint32_t PRUSSDrvPruWriteMemory(uint32_t pruMem,
                                uint32_t wordOffSet,
                                uint32_t *sourceMem,
                                uint32_t byteLength,
				uint32_t baseAddr)
{
    uint32_t i, wordLength;

    /* Adjust length as multiple of 4 bytes */
    wordLength = (byteLength + 3U) >> 2U;

    for (i = 0U; i < wordLength; i++)
    {
        HWREG( baseAddr + pruMem + (i << 2U) + wordOffSet ) = sourceMem[i];
    }
    return wordLength;
}

int32_t PRUSSDrvPruSendEvent(uint32_t eventNum,uint32_t baseAddr)
{
    if(eventNum < 32U)
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_INTC + HW_ICSS_INTC_SRSR0),
	               HW_ICSS_INTC_SRSR0_RAW_STATUS_31_0, (1U << eventNum));
    }
    else
    {
        HW_WR_FIELD32((baseAddr + PRU_ICSS_INTC + HW_ICSS_INTC_SRSR1),
	               HW_ICSS_INTC_SRSR1_RAW_STATUS_63_32, (1U << (eventNum - 32U)));
    }

    return  0;
}

int32_t PRUSSDrvPruClearEvent(uint32_t eventNum,uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + PRU_ICSS_INTC + HW_ICSS_INTC_SICR),
                   HW_ICSS_INTC_SICR_STATUS_CLR_INDEX, eventNum);
    return 0;
}

int32_t PRUSSDrvMapPruMem(uint32_t pruRamId, void **address,uint32_t baseAddr)
{
    int32_t retVal = 0;

    switch (pruRamId)
    {
        case PRU0_DATARAM:
            *address = (void*)( baseAddr + PRU_ICSS_DATARAM(0));
            break;
        case PRU1_DATARAM:
            *address = (void*)(baseAddr + PRU_ICSS_DATARAM(1));
            break;
        case PRUSS_SHARED_DATARAM:
            *address = (void*) baseAddr + PRU_ICSS_SHARED_RAM;
            break;
        default:
            *address = 0;
             retVal = -1;
    }
    return retVal;
}

int32_t PRUSSDrvMapPeripheralIo(uint32_t perId, void **address,uint32_t baseAddr)
{
    int32_t retVal = 0;

    switch (perId)
    {
        case PRUSS_CFG:
            *address = (void*)( baseAddr + PRU_ICSS_CFG);
            break;
        case PRUSS_UART:
            *address = (void*)( baseAddr + PRU_ICSS_UART);
            break;
        case PRUSS_IEP:
            *address = (void*)( baseAddr + PRU_ICSS_IEP);
            break;
        case PRUSS_ECAP:
            *address = (void*)( baseAddr + PRU_ICSS_ECAP);
            break;
        case PRUSS_MII_RT:
            *address = (void*)( baseAddr + PRU_ICSS_MIIRT);
            break;
        case PRUSS_MDIO:
            *address = (void*)( baseAddr + PRU_ICSS_MDIO);
            break;
        default:
            *address = 0;
            retVal = -1;
    }

    return retVal;
}

void PRUSSEnableOcpMasterAccess(uint32_t baseAddr )
{
    HW_WR_FIELD32((baseAddr + PRU_ICSS_CFG + HW_ICSS_CFG_SYSCFG),
                   HW_ICSS_CFG_SYSCFG_STANDBY_INIT, 0);
}

uint32_t PRUSSDetectHwVersion(void)
{
    return 1;
}
