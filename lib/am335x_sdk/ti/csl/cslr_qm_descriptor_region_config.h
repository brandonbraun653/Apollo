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
#ifndef CSLR_QM_DESCRIPTOR_REGION_CONFIG_H_
#define CSLR_QM_DESCRIPTOR_REGION_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Created substructure CSL_Qm_descriptor_region_configMemory_region_base_address_groupRegs to maintain
 *          compatibility because of new RL generation process 
 *      b) RL is still a superset supporting all existing Keystone-2 family devices
 */
/**************************************************************************
* Register Overlay Structure for MEMORY_REGION_BASE_ADDRESS_GROUP
**************************************************************************/
typedef struct {
    volatile Uint32 MEMORY_REGION_BASE_ADDRESS_REG;
    volatile Uint32 MEMORY_REGION_START_INDEX_REG;
    volatile Uint32 MEMORY_REGION_DESCRIPTOR_SETUP_REG;
    volatile Uint8  RSVD0[4];
} CSL_Qm_descriptor_region_configMemory_region_base_address_groupRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    CSL_Qm_descriptor_region_configMemory_region_base_address_groupRegs MEMORY_REGION_BASE_ADDRESS_GROUP[64];
} CSL_Qm_descriptor_region_configRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* MEMORY_REGION_BASE_ADDRESS_REG */
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_BASE_ADDRESS_REG(n)  (0x0U + ((n) * (0x10U)))

/* MEMORY_REGION_START_INDEX_REG */
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_START_INDEX_REG(n)  (0x4U + ((n) * (0x10U)))

/* MEMORY_REGION_DESCRIPTOR_SETUP_REG */
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG(n)  (0x8U + ((n) * (0x10U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* MEMORY_REGION_BASE_ADDRESS_REG */

#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_BASE_ADDRESS_REG_REGR_BASE_MASK  (0xFFFFFFFFU)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_BASE_ADDRESS_REG_REGR_BASE_SHIFT  (0U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_BASE_ADDRESS_REG_REGR_BASE_RESETVAL  (0x00000000U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_BASE_ADDRESS_REG_REGR_BASE_MAX  (0xffffffffU)

#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_BASE_ADDRESS_REG_RESETVAL  (0x00000000U)

/* MEMORY_REGION_START_INDEX_REG */

#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_START_INDEX_REG_START_INDEX_MASK  (0x0007FFFFU)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_START_INDEX_REG_START_INDEX_SHIFT  (0U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_START_INDEX_REG_START_INDEX_RESETVAL  (0x00000000U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_START_INDEX_REG_START_INDEX_MAX  (0x0007ffffU)

#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_START_INDEX_REG_RESETVAL  (0x00000000U)

/* MEMORY_REGION_DESCRIPTOR_SETUP_REG */

#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_DESC_SIZE_MASK  (0x1FFF0000U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_DESC_SIZE_SHIFT  (16U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_DESC_SIZE_RESETVAL  (0x00000000U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_DESC_SIZE_MAX  (0x00001fffU)

#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_REG_SIZE_MASK  (0x0000000FU)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_REG_SIZE_SHIFT  (0U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_REG_SIZE_RESETVAL  (0x00000000U)
#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_REG_SIZE_MAX  (0x0000000fU)

#define CSL_QM_DESCRIPTOR_REGION_CONFIG_MEMORY_REGION_DESCRIPTOR_SETUP_REG_RESETVAL  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
