/**
 *  \file  pinmux.c
 *
 * \brief  This file contains the implementations for pinmux API's. These API's 
 *         identify the corresponding board data, extract the pin 
 *         configurations and configure the pad control register.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
#include "pinmux.h"
#include "board.h"
#include "chipdb.h"
#include "error.h"
#include "hw_types.h"
#include "debug.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static const boardData_t* pBoardData = NULL;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t PINMUXModuleConfig(chipdbModuleID_t moduleId, uint32_t instNum, 
                                                              void* pParam1)
{
    pinmuxModuleCfg_t* pModuleData = NULL;
    pinmuxPerCfg_t* pInstanceData = NULL;
    volatile const pinmuxBoardCfg_t* pPinmuxData  = NULL;
    uint32_t ctrlModBase = CHIPDBBaseAddress(CHIPDB_MOD_ID_CONTROL_MODULE, 0);
    int32_t status = E_FAIL;
    uint32_t index = 0;
    
    /* Get board Data */
    if(NULL == pBoardData)
    {
        pBoardData = BOARDGetData();
    }
    
    /* Get module Data */
    if(NULL != pBoardData)
    {
       pPinmuxData = pBoardData->pPinmuxData;
       ASSERT(NULL != pPinmuxData);
        
        status = E_INVALID_MODULE_ID;
        for(index = 0; ((S_PASS != status) && 
            (CHIPDB_MOD_ID_INVALID != pPinmuxData[index].moduleId)); index++)
        {
            if(pPinmuxData[index].moduleId == moduleId)
            {
                pModuleData = pPinmuxData[index].modulePinCfg;
                ASSERT(NULL != pModuleData);
                status = S_PASS;
            }
        }
    }
    else
    {
        status = E_FAIL;
    }

    /* Get instance Data */
    if(S_PASS == status)
    {
        status = E_INST_NOT_SUPP;
        for(index = 0; ((S_PASS != status) && 
          (CHIPDB_INVALID_INSTANCE_NUM != pModuleData[index].modInstNum)); index++)
        {
            if(pModuleData[index].modInstNum == instNum)
            {
                pInstanceData = pModuleData[index].instPins;
                ASSERT(NULL != pInstanceData)
                status = S_PASS;
            }
        }
    }
        
    /* Configure Pinmux */
    if(S_PASS == status)
    {
		for(index = 0; ((uint16_t)PINMUX_INVALID_PIN != 
									  pInstanceData[index].pinOffset); index++)
		{
			if(NULL != pParam1)
			{
				if(pInstanceData[index].optParam == *(uint16_t*)pParam1)
				{
					HW_WR_REG32((ctrlModBase + pInstanceData[index].pinOffset),
								pInstanceData[index].pinSettings);
                    status = S_PASS;
					break;
				}
			}
			else
			{
				HW_WR_REG32((ctrlModBase + pInstanceData[index].pinOffset),
								pInstanceData[index].pinSettings);
			}
		}
		if((NULL != pParam1) && ((uint16_t)PINMUX_INVALID_PIN == pInstanceData[index].pinOffset))
		{
			status = E_FAIL;
		}
    }
    
    return status;
}

/* TODO: Other API definitions to be added. */

