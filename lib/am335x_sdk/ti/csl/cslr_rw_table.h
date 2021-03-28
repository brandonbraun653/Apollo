/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_RWTABLE_H_
#define CSLR_RWTABLE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 DUCATI_RW_PID1;
    volatile Uint32 DUCATI_RW_PID2;
    volatile Uint32 DMLED_SW_CTRL_REG;
} CSL_RwTableRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* DUCATI_RW_PID1 */
#define CSL_RWTABLE_DUCATI_RW_PID1                              (0x0U)

/* DUCATI_RW_PID2 */
#define CSL_RWTABLE_DUCATI_RW_PID2                              (0x4U)

/* Reserved for DMLED testing */
#define CSL_RWTABLE_DMLED_SW_CTRL_REG                           (0x8U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* DUCATI_RW_PID1 */

#define CSL_RWTABLE_DUCATI_RW_PID1_BASEADD1_MASK                (0xFFFFFFFFU)
#define CSL_RWTABLE_DUCATI_RW_PID1_BASEADD1_SHIFT               (0U)
#define CSL_RWTABLE_DUCATI_RW_PID1_BASEADD1_RESETVAL            (0x00000000U)
#define CSL_RWTABLE_DUCATI_RW_PID1_BASEADD1_MAX                 (0xffffffffU)

#define CSL_RWTABLE_DUCATI_RW_PID1_RESETVAL                     (0x00000000U)

/* DUCATI_RW_PID2 */

#define CSL_RWTABLE_DUCATI_RW_PID2_BASEADD2_MASK                (0xFFFFFFFFU)
#define CSL_RWTABLE_DUCATI_RW_PID2_BASEADD2_SHIFT               (0U)
#define CSL_RWTABLE_DUCATI_RW_PID2_BASEADD2_RESETVAL            (0x00000000U)
#define CSL_RWTABLE_DUCATI_RW_PID2_BASEADD2_MAX                 (0xffffffffU)

#define CSL_RWTABLE_DUCATI_RW_PID2_RESETVAL                     (0x00000000U)

/* DMLED_SW_CTRL_REG */

#define CSL_RWTABLE_DMLED_SW_CTRL_REG_STATUSBIT_MASK            (0x00000001U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_STATUSBIT_SHIFT           (0U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_STATUSBIT_RESETVAL        (0x00000000U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_STATUSBIT_MAX             (0x00000001U)

#define CSL_RWTABLE_DMLED_SW_CTRL_REG_EXECBIT_MASK              (0x00000002U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_EXECBIT_SHIFT             (1U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_EXECBIT_RESETVAL          (0x00000000U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_EXECBIT_MAX               (0x00000001U)

#define CSL_RWTABLE_DMLED_SW_CTRL_REG_SYNCBIT_MASK              (0x00000004U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_SYNCBIT_SHIFT             (2U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_SYNCBIT_RESETVAL          (0x00000000U)
#define CSL_RWTABLE_DMLED_SW_CTRL_REG_SYNCBIT_MAX               (0x00000001U)

#define CSL_RWTABLE_DMLED_SW_CTRL_REG_RESETVAL                  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
