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
#ifndef CSLR_QM_QUEUE_STATUS_CONFIG_H_
#define CSLR_QM_QUEUE_STATUS_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Created substructure CSL_Qm_queue_status_configQueue_status_config_groupRegs to maintain
 *          compatibility because of new RL generation process
 *      b) Modified REG_X to QUEUE_STATUS_CONFIG_REG_X for maintaining back compatibility
 */

/**************************************************************************
* Register Overlay Structure for qm_queue_status_config
**************************************************************************/
typedef struct  {
    volatile Uint32 QUEUE_STATUS_CONFIG_REG_A;
    volatile Uint32 QUEUE_STATUS_CONFIG_REG_B;
    volatile Uint32 QUEUE_STATUS_CONFIG_REG_C;
    volatile Uint32 QUEUE_STATUS_CONFIG_REG_D;
} CSL_Qm_queue_status_configQueue_status_config_groupRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Qm_queue_status_configQueue_status_config_groupRegs QUEUE_STATUS_CONFIG_GROUP[8192];
} CSL_Qm_queue_status_configRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* REG_A */
#define CSL_QM_QUEUE_STATUS_CONFIG_REG_A(n)                     (0x0U + ((n) * (0x10U)))

/* REG_B */
#define CSL_QM_QUEUE_STATUS_CONFIG_REG_B(n)                     (0x4U + ((n) * (0x10U)))

/* REG_C */
#define CSL_QM_QUEUE_STATUS_CONFIG_REG_C(n)                     (0x8U + ((n) * (0x10U)))

/* REG_D */
#define CSL_QM_QUEUE_STATUS_CONFIG_REG_D(n)                     (0xCU + ((n) * (0x10U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REG_A */

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_A_QUEUE_ENTRY_COUNT_MASK (0x0007FFFFu)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_A_QUEUE_ENTRY_COUNT_SHIFT (0x00000000u)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_A_QUEUE_ENTRY_COUNT_RESETVAL (0x00000000u)

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_A_RESETVAL (0x00000000u)

/* QUEUE_STATUS_CONFIG_REG_B */

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_B_QUEUE_BYTE_COUNT_MASK (0xFFFFFFFFu)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_B_QUEUE_BYTE_COUNT_SHIFT (0x00000000u)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_B_QUEUE_BYTE_COUNT_RESETVAL (0x00000000u)

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_B_RESETVAL (0x00000000u)

/* QUEUE_STATUS_CONFIG_REG_C */

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_C_PACKET_SIZE_MASK (0x0001FFFFu)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_C_PACKET_SIZE_SHIFT (0x00000000u)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_C_PACKET_SIZE_RESETVAL (0x00000000u)

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_C_RESETVAL (0x00000000u)

/* QUEUE_STATUS_CONFIG_REG_D */

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_D_THRESHOLD_MASK (0x0000000Fu)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_D_THRESHOLD_SHIFT (0x00000000u)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_D_THRESHOLD_RESETVAL (0x00000000u)

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_D_THRESHOLD_HILO_MASK (0x00000080u)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_D_THRESHOLD_HILO_SHIFT (0x00000007u)
#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_D_THRESHOLD_HILO_RESETVAL (0x00000000u)

#define CSL_QM_QUEUE_STATUS_CONFIG_QUEUE_STATUS_CONFIG_REG_D_RESETVAL (0x00000000u)

#ifdef __cplusplus
}
#endif
#endif
