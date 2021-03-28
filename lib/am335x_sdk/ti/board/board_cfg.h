/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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
 *
 */

#ifndef BOARD_CFG_TOP_H
#define BOARD_CFG_TOP_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(evmAM335x)
#include <ti/board/src/evmAM335x/include/board_cfg.h>

#elif defined (icev2AM335x)
#include <ti/board/src/icev2AM335x/include/board_cfg.h>

#elif defined (iceAMIC110)
#include <ti/board/src/iceAMIC110/include/board_cfg.h>

#elif defined (skAM335x)
#include <ti/board/src/skAM335x/include/board_cfg.h>

#elif defined (bbbAM335x)
#include <ti/board/src/bbbAM335x/include/board_cfg.h>

#elif defined (idkAM437x)
#include <ti/board/src/idkAM437x/include/board_cfg.h>

#elif defined (evmAM437x)
#include <ti/board/src/evmAM437x/include/board_cfg.h>

#elif defined (skAM437x)
#include <ti/board/src/skAM437x/include/board_cfg.h>

#elif defined (evmAM572x)
#include <ti/board/src/evmAM572x/include/board_cfg.h>

#elif defined (evmOMAPL137)
#include <ti/board/src/evmOMAPL137/include/board_cfg.h>

#elif defined (lcdkOMAPL138)
#include <ti/board/src/lcdkOMAPL138/include/board_cfg.h>

#elif defined (idkAM572x)
#include <ti/board/src/idkAM572x/include/board_cfg.h>

#elif defined (idkAM574x)
#include <ti/board/src/idkAM574x/include/board_cfg.h>

#elif defined (evmAM571x)
#include <ti/board/src/evmAM571x/include/board_cfg.h>

#elif defined (idkAM571x)
#include <ti/board/src/idkAM571x/include/board_cfg.h>

#elif defined (evmK2E)
#include <ti/board/src/evmK2E/include/board_cfg.h>

#elif defined (evmK2L)
#include <ti/board/src/evmK2L/include/board_cfg.h>

#elif defined (evmK2G)
#include <ti/board/src/evmK2G/include/board_cfg.h>

#elif defined (iceK2G)
#include <ti/board/src/iceK2G/include/board_cfg.h>

#elif defined (evmK2H)
#include <ti/board/src/evmK2H/include/board_cfg.h>

#elif defined (evmK2K)
#include <ti/board/src/evmK2H/include/board_cfg.h>

#elif defined (evmC6657)
#include <ti/board/src/evmC6657/include/board_cfg.h>

#elif defined (evmC6678)
#include <ti/board/src/evmC6678/include/board_cfg.h>

#elif defined (evmDRA72x)
#include <ti/board/src/evmDRA72x/include/board_cfg.h>

#elif defined (evmDRA75x)
#include <ti/board/src/evmDRA75x/include/board_cfg.h>

#elif defined (SOC_DRA78x)
#include <ti/board/src/evmDRA78x/include/board_cfg.h>

#elif defined (am65xx_idk)
#include <ti/board/src/am65xx_idk/include/board_cfg.h>

#elif defined (am65xx_evm)
#include <ti/board/src/am65xx_evm/include/board_cfg.h>

#elif defined (j721e_sim)
#include <ti/board/src/j721e_sim/include/board_cfg.h>

#elif defined (j721e_qt)
#include <ti/board/src/j721e_sim/include/board_cfg.h>

#elif defined (j721e_evm)
#include <ti/board/src/j721e_evm/include/board_cfg.h>

#elif defined (j7200_evm)
#include <ti/board/src/j7200_evm/include/board_cfg.h>

#elif defined (tpr12_evm)
#include <ti/board/src/tpr12_evm/include/board_cfg.h>

#endif

#ifdef __cplusplus
}
#endif

#endif
