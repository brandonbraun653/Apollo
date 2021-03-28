/******************************************************************************
 * Copyright (c) 2015-2017 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

#include "board_internal.h"
#include "66AK2G0x_pinmux.h"

Board_STATUS Board_pinmuxConfig (void)
{
    pinmuxModuleCfg_t* pModuleData = NULL;
    pinmuxPerCfg_t* pInstanceData = NULL;
    uint32_t i, j, k;

    for(i = 0; (CHIPDB_MOD_ID_INVALID != gK2G0xPinmuxData[i].moduleId); i++)
    {
        pModuleData = gK2G0xPinmuxData[i].modulePinCfg;
        for(j = 0; (CHIPDB_INVALID_INSTANCE_NUM != pModuleData[j].modInstNum); j++)
        {
            pInstanceData = pModuleData[j].instPins;
            for(k = 0; (PINMUX_INVALID_PIN != pInstanceData[k].pinOffset); k++)
            {
                HW_WR_REG32((CSL_BOOT_CFG_REGS + pInstanceData[k].pinOffset),
                                pInstanceData[k].pinSettings);
            }
        }
    }
    return BOARD_SOK;
}
