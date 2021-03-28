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
#ifndef CSLR_QMSS_H_
#define CSLR_QMSS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for LINKING_RAM
**************************************************************************/
typedef struct {
    volatile Uint32 LRAM_W0;
} CSL_QmssLinking_ramRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION_REG;
    volatile Uint8  RSVD0[131068];
    CSL_QmssLinking_ramRegs	LINKING_RAM[16384];
} CSL_QmssRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* LRAM_W0 */
#define CSL_QMSS_LRAM_W0(n)                                     (0x20000U + ((n) * (0x4U)))

/* REVISION_REG */
#define CSL_QMSS_REVISION_REG                                   (0x0U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* LRAM_W0 */

#define CSL_QMSS_LRAM_W0_REGION_NUM_MASK                        (0x003C0000U)
#define CSL_QMSS_LRAM_W0_REGION_NUM_SHIFT                       (18U)
#define CSL_QMSS_LRAM_W0_REGION_NUM_RESETVAL                    (0x00000000U)
#define CSL_QMSS_LRAM_W0_REGION_NUM_MAX                         (0x0000000fU)

#define CSL_QMSS_LRAM_W0_DESC_SIZE_MASK                         (0x0003C000U)
#define CSL_QMSS_LRAM_W0_DESC_SIZE_SHIFT                        (14U)
#define CSL_QMSS_LRAM_W0_DESC_SIZE_RESETVAL                     (0x00000000U)
#define CSL_QMSS_LRAM_W0_DESC_SIZE_MAX                          (0x0000000fU)

#define CSL_QMSS_LRAM_W0_NEXT_INDEX_MASK                        (0x00003FFFU)
#define CSL_QMSS_LRAM_W0_NEXT_INDEX_SHIFT                       (0U)
#define CSL_QMSS_LRAM_W0_NEXT_INDEX_RESETVAL                    (0x00000000U)
#define CSL_QMSS_LRAM_W0_NEXT_INDEX_MAX                         (0x00003fffU)

#define CSL_QMSS_LRAM_W0_RESETVAL                               (0x00000000U)

/* REVISION_REG */

#define CSL_QMSS_REVISION_REG_SCHEME_MASK                       (0xC0000000U)
#define CSL_QMSS_REVISION_REG_SCHEME_SHIFT                      (30U)
#define CSL_QMSS_REVISION_REG_SCHEME_RESETVAL                   (0x00000000U)
#define CSL_QMSS_REVISION_REG_SCHEME_MAX                        (0x00000003U)

#define CSL_QMSS_REVISION_REG_FUNCTION_MASK                     (0x0FFF0000U)
#define CSL_QMSS_REVISION_REG_FUNCTION_SHIFT                    (16U)
#define CSL_QMSS_REVISION_REG_FUNCTION_RESETVAL                 (0x00000000U)
#define CSL_QMSS_REVISION_REG_FUNCTION_MAX                      (0x00000fffU)

#define CSL_QMSS_REVISION_REG_REVRTL_MASK                       (0x0000F800U)
#define CSL_QMSS_REVISION_REG_REVRTL_SHIFT                      (11U)
#define CSL_QMSS_REVISION_REG_REVRTL_RESETVAL                   (0x00000000U)
#define CSL_QMSS_REVISION_REG_REVRTL_MAX                        (0x0000001fU)

#define CSL_QMSS_REVISION_REG_REVMAJ_MASK                       (0x00000700U)
#define CSL_QMSS_REVISION_REG_REVMAJ_SHIFT                      (8U)
#define CSL_QMSS_REVISION_REG_REVMAJ_RESETVAL                   (0x00000000U)
#define CSL_QMSS_REVISION_REG_REVMAJ_MAX                        (0x00000007U)

#define CSL_QMSS_REVISION_REG_REVCUSTOM_MASK                    (0x000000C0U)
#define CSL_QMSS_REVISION_REG_REVCUSTOM_SHIFT                   (6U)
#define CSL_QMSS_REVISION_REG_REVCUSTOM_RESETVAL                (0x00000000U)
#define CSL_QMSS_REVISION_REG_REVCUSTOM_MAX                     (0x00000003U)

#define CSL_QMSS_REVISION_REG_REVMIN_MASK                       (0x0000003FU)
#define CSL_QMSS_REVISION_REG_REVMIN_SHIFT                      (0U)
#define CSL_QMSS_REVISION_REG_REVMIN_RESETVAL                   (0x00000000U)
#define CSL_QMSS_REVISION_REG_REVMIN_MAX                        (0x0000003fU)

#define CSL_QMSS_REVISION_REG_RESETVAL                          (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
