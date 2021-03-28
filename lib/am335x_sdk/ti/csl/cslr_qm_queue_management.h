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
#ifndef CSLR_QM_QUEUE_MANAGEMENT_H_
#define CSLR_QM_QUEUE_MANAGEMENT_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Created substructure CSL_Qm_queue_managementQueue_mgmt_groupRegs to maintain
 *          compatibility because of new RL generation process 
 *      b) RL is still a superset supporting all existing Keystone-2 family devices
 */
/**************************************************************************
* Register Overlay Structure for QUEUE_MGMT_GROUP
**************************************************************************/
typedef struct {
    volatile Uint32 QUEUE_REG_A;
    volatile Uint32 QUEUE_REG_B;
    volatile Uint32 QUEUE_REG_C;
    volatile Uint32 QUEUE_REG_D;
} CSL_Qm_queue_managementQueue_mgmt_groupRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    CSL_Qm_queue_managementQueue_mgmt_groupRegs QUEUE_MGMT_GROUP[8192];
} CSL_Qm_queue_managementRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* QUEUE_REG_A */
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_A(n)                  (0x0U + ((n) * (0x10U)))

/* QUEUE_REG_B */
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_B(n)                  (0x4U + ((n) * (0x10U)))

/* QUEUE_REG_C */
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C(n)                  (0x8U + ((n) * (0x10U)))

/* QUEUE_REG_D */
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D(n)                  (0xCU + ((n) * (0x10U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* QUEUE_REG_A */

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_A_QUEUE_ENTRY_COUNT_MASK  (0x0007FFFFU)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_A_QUEUE_ENTRY_COUNT_SHIFT  (0U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_A_QUEUE_ENTRY_COUNT_RESETVAL  (0x00000000U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_A_QUEUE_ENTRY_COUNT_MAX  (0x0007ffffU)

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_A_RESETVAL            (0x00000000U)

/* QUEUE_REG_B */

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_B_QUEUE_BYTE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_B_QUEUE_BYTE_COUNT_SHIFT  (0U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_B_QUEUE_BYTE_COUNT_RESETVAL  (0x00000000U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_B_QUEUE_BYTE_COUNT_MAX  (0xffffffffU)

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_B_RESETVAL            (0x00000000U)

/* QUEUE_REG_C */

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_HEAD_TAIL_MASK      (0x80000000U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_HEAD_TAIL_SHIFT     (31U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_HEAD_TAIL_RESETVAL  (0x00000000U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_HEAD_TAIL_MAX       (0x00000001U)

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_PACKET_SIZE_MASK    (0x0001FFFFU)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_PACKET_SIZE_SHIFT   (0U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_PACKET_SIZE_RESETVAL  (0x00000000U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_PACKET_SIZE_MAX     (0x0001ffffU)

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_C_RESETVAL            (0x00000000U)

/* QUEUE_REG_D */

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_PTR_MASK       (0xFFFFFFF0U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_PTR_SHIFT      (4U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_PTR_RESETVAL   (0x00000000U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_PTR_MAX        (0x0fffffffU)

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_INFO_MASK      (0x0000000FU)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_INFO_SHIFT     (0U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_INFO_RESETVAL  (0x00000000U)
#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_DESC_INFO_MAX       (0x0000000fU)

#define CSL_QM_QUEUE_MANAGEMENT_QUEUE_REG_D_RESETVAL            (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
