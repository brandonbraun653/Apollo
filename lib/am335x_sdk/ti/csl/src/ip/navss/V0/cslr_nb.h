/********************************************************************
 * Copyright (C) 2017-2020 Texas Instruments Incorporated.
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
 *  Name        : cslr_nb.h
*/
#ifndef CSLR_NB_H_
#define CSLR_NB_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : Config port MMR
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint8_t  Resv_16[12];
    volatile uint32_t THREADMAP;                 /* Thread Map Register */
} CSL_nbRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_NB_PID                                                             (0x00000000U)
#define CSL_NB_THREADMAP                                                       (0x00000010U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_NB_PID_MINOR_MASK                                                  (0x0000003FU)
#define CSL_NB_PID_MINOR_SHIFT                                                 (0x00000000U)
#define CSL_NB_PID_MINOR_MAX                                                   (0x0000003FU)

#define CSL_NB_PID_CUSTOM_MASK                                                 (0x000000C0U)
#define CSL_NB_PID_CUSTOM_SHIFT                                                (0x00000006U)
#define CSL_NB_PID_CUSTOM_MAX                                                  (0x00000003U)

#define CSL_NB_PID_MAJOR_MASK                                                  (0x00000700U)
#define CSL_NB_PID_MAJOR_SHIFT                                                 (0x00000008U)
#define CSL_NB_PID_MAJOR_MAX                                                   (0x00000007U)

#define CSL_NB_PID_RTL_MASK                                                    (0x0000F800U)
#define CSL_NB_PID_RTL_SHIFT                                                   (0x0000000BU)
#define CSL_NB_PID_RTL_MAX                                                     (0x0000001FU)

#define CSL_NB_PID_FUNC_MASK                                                   (0x0FFF0000U)
#define CSL_NB_PID_FUNC_SHIFT                                                  (0x00000010U)
#define CSL_NB_PID_FUNC_MAX                                                    (0x00000FFFU)

#define CSL_NB_PID_BU_MASK                                                     (0x30000000U)
#define CSL_NB_PID_BU_SHIFT                                                    (0x0000001CU)
#define CSL_NB_PID_BU_MAX                                                      (0x00000003U)

#define CSL_NB_PID_SCHEME_MASK                                                 (0xC0000000U)
#define CSL_NB_PID_SCHEME_SHIFT                                                (0x0000001EU)
#define CSL_NB_PID_SCHEME_MAX                                                  (0x00000003U)

/* THREADMAP */

#define CSL_NB_THREADMAP_THREADMAP_MASK                                        (0x0000FFFFU)
#define CSL_NB_THREADMAP_THREADMAP_SHIFT                                       (0x00000000U)
#define CSL_NB_THREADMAP_THREADMAP_MAX                                         (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : Config port MMR
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t MEMATTR64K[64];            /* Memory Attributes for 64K regions */
    volatile uint32_t MEMATTR16M0[128];          /* Memory Attributes for first 16M regions */
} CSL_nb_mem_attrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_NB_MEM_ATTR_MEMATTR64K(MEMATTR64K)                                 (0x00000000U+((MEMATTR64K)*0x4U))
#define CSL_NB_MEM_ATTR_MEMATTR16M0(MEMATTR16M0)                               (0x00000100U+((MEMATTR16M0)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MEMATTR64K */

#define CSL_NB_MEM_ATTR_MEMATTR64K_INNER_MASK                                  (0x00000003U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_INNER_SHIFT                                 (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_INNER_MAX                                   (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR64K_INNER_VAL_NO_ALLOCATE                       (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_INNER_VAL_WR_ALLOCATE                       (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_INNER_VAL_RD_ALLOCATE                       (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_INNER_VAL_RD_WR_ALLOCATE                    (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR64K_OUTER_MASK                                  (0x0000000CU)
#define CSL_NB_MEM_ATTR_MEMATTR64K_OUTER_SHIFT                                 (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_OUTER_MAX                                   (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR64K_OUTER_VAL_NO_ALLOCATE                       (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_OUTER_VAL_WR_ALLOCATE                       (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_OUTER_VAL_RD_ALLOCATE                       (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_OUTER_VAL_RD_WR_ALLOCATE                    (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR64K_SDOMAIN_MASK                                (0x00000030U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_SDOMAIN_SHIFT                               (0x00000004U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_SDOMAIN_MAX                                 (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR64K_SDOMAIN_VAL_NON_SHARED                      (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_SDOMAIN_VAL_INNER_SHARED                    (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_SDOMAIN_VAL_OUTER_SHARED                    (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_SDOMAIN_VAL_SYSTEM_SHARED                   (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR64K_MEMTYPE_MASK                                (0x000000C0U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_MEMTYPE_SHIFT                               (0x00000006U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_MEMTYPE_MAX                                 (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR64K_MEMTYPE_VAL_DEVICE                          (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_MEMTYPE_VAL_WRITEBACK                       (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_MEMTYPE_VAL_WRITETHROUGH                    (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR64K_MEMTYPE_VAL_NON_CACHEABLE                   (0x00000003U)

/* MEMATTR16M0 */

#define CSL_NB_MEM_ATTR_MEMATTR16M0_INNER_MASK                                 (0x00000003U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_INNER_SHIFT                                (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_INNER_MAX                                  (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR16M0_INNER_VAL_NO_ALLOCATE                      (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_INNER_VAL_WR_ALLOCATE                      (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_INNER_VAL_RD_ALLOCATE                      (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_INNER_VAL_RD_WR_ALLOCATE                   (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR16M0_OUTER_MASK                                 (0x0000000CU)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_OUTER_SHIFT                                (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_OUTER_MAX                                  (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR16M0_OUTER_VAL_NO_ALLOCATE                      (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_OUTER_VAL_WR_ALLOCATE                      (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_OUTER_VAL_RD_ALLOCATE                      (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_OUTER_VAL_RD_WR_ALLOCATE                   (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR16M0_SDOMAIN_MASK                               (0x00000030U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_SDOMAIN_SHIFT                              (0x00000004U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_SDOMAIN_MAX                                (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR16M0_SDOMAIN_VAL_NON_SHARED                     (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_SDOMAIN_VAL_INNER_SHARED                   (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_SDOMAIN_VAL_OUTER_SHARED                   (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_SDOMAIN_VAL_SYSTEM_SHARED                  (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR16M0_MEMTYPE_MASK                               (0x000000C0U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_MEMTYPE_SHIFT                              (0x00000006U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_MEMTYPE_MAX                                (0x00000003U)

#define CSL_NB_MEM_ATTR_MEMATTR16M0_MEMTYPE_VAL_DEVICE                         (0x00000000U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_MEMTYPE_VAL_WRITEBACK                      (0x00000001U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_MEMTYPE_VAL_WRITETHROUGH                   (0x00000002U)
#define CSL_NB_MEM_ATTR_MEMATTR16M0_MEMTYPE_VAL_NON_CACHEABLE                  (0x00000003U)

#ifdef __cplusplus
}
#endif
#endif
