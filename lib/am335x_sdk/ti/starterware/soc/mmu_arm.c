/**
 *  \file   mmu_arm.c
 *
 *  \brief  APIs for configuring MMU in ARM. API's are provided for 
 *          initializing MMU and configuring memory regions.
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
#include "mmu.h"
#include "cp15.h"
#include "error.h"
#include "misc.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** Alignment for Page Table - shall be aligned to 16KB boundary. */
#define MMU_PAGETABLE_ALIGN_SIZE                          (16U*1024U)


#define MMU_PAGETABLE_ENTRY_FAULT                         (0x00U)
#define MMU_PAGEBOUND_SHIFT                               (20U)

/** \brief Page table base address mask for first level descriptors. */
#define MMU_PAGETABLE_ADDR_MASK                           (0xFFF00000U)
/** \brief Page table base address shift for first level descriptors. */
#define MMU_PAGETABLE_ADDR_SHIFT                          (20U)
/** \brief Section base address. */
#define MMU_PGADDR_SECTION                                (0xFFFU)
/** \brief SSuper-section base address. Ignoring extended base address. */
#define MMU_PGADDR_SUPER_SECTION                          (0xFF0U)

/** \brief Page type mask for section & super-section. */
#define MMU_PGTYPE_MASK                                   (0x00040002U)
/** \brief Page type - Section which is 1MB. */
#define MMU_PGTYPE_SECTION                                (0x00000002U)
/** \brief Page type - Super-section which is 16MB. */
#define MMU_PGTYPE_SUPER_SECTION                          (0x00040002U)

/** \brief Memory Type is normal - Non Shareable */
#define MMU_MEMTYPE_NORMAL_NON_SHAREABLE                  (0x00004000U)
/** \brief Memory Type is normal - Shareable */
#define MMU_MEMTYPE_NORMAL_SHAREABLE                      (0x00014000U)
/** \brief Inner cache policy bit shift */
#define MMU_INNER_CACHE_POLICY_SHIFT                      (2U)
/** \brief Outer cache policy bit shift */
#define MMU_OUTER_CACHE_POLICY_SHIFT                      (12U)

/** \brief Non secure bit shift */
#define MMU_NON_SECURE_MASK                               (0x00080000U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Defines a static global information table for access control 
 *         permissions defined in ARM. The order of entries in the table  
 *                   should be as per the enum "mmuAccessCtrl_t". These values represent 
 *                   the configuration in the page table entry.
 */
static const uint32_t gMmuAccessCtrl[] = 
                {
                        0x00000000U, /* MMU_ACCESS_CTRL_PRV_NA_USR_NA */
                        0x00000400U, /* MMU_ACCESS_CTRL_PRV_RW_USR_NA */
                        0x00000800U, /* MMU_ACCESS_CTRL_PRV_RW_USR_RO */
                        0x00000C00U, /* MMU_ACCESS_CTRL_PRV_RW_USR_RW */
                        0x00008400U, /* MMU_ACCESS_CTRL_PRV_RO_USR_NA */
                        0x00008C00U, /* MMU_ACCESS_CTRL_PRV_RO_USR_RO */
                        0x00000010U  /* MMU_ACCESS_CTRL_PRV_NO_EXEC */
                };


/** \brief Defines a static global information table for memory attributes
 *         defined in ARM. The order of entries in the table should be as per
 *         the enum "mmuMemAttr_t". These values represent the configuration 
 *                   in the page table entry.
 */
static const uint32_t gMmuMemAttr[] = 
                {
                        0x00000000U, /* MMU_MEM_ATTR_SO_SHAREABLE */
                        0x00000004U, /* MMU_MEM_ATTR_DEVICE_SHAREABLE */
                        0x00002000U, /* MMU_MEM_ATTR_DEVICE_NON_SHAREABLE */
                        0x00014000U, /* MMU_MEM_ATTR_NORMAL_SHAREABLE */
                        0x00004000U  /* MMU_MEM_ATTR_NORMAL_NON_SHAREABLE */
                };
                                        
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void MMUInit(uint32_t *pMasterPt, uint32_t numPageTableEntry)
{
   /* Invalidate the TLB entries */
    CP15TlbInvalidate();

    /* Set domain access rights */
    CP15DomainAccessClientSet();

    /* Disable TEX remapping, Access Flag usage and alignment check */
    CP15ControlFeatureDisable( CP15_CONTROL_TEXREMAP
                               | CP15_CONTROL_ACCESSFLAG
                               | CP15_CONTROL_ALIGN_CHCK
                               | CP15_CONTROL_MMU);

    /* Configure the TTB Control register to use only TTB0 */
    CP15TtbCtlTtb0Config();

    /* Set the master page table with fault entries */
    for(; numPageTableEntry !=0; numPageTableEntry--)
    {
        *pMasterPt++ = MMU_PAGETABLE_ENTRY_FAULT;
    }
}


int32_t MMUMemRegionMap(mmuMemRegionConfig_t *pRegion, uint32_t *pMasterPt)
{
    uint32_t *pPageTablePtr;
    uint32_t ptEntry = 0;
    int32_t status = S_PASS;
    int32_t index;
        
    if(pMasterPt == NULL)
        status = E_INVALID_PARAM;

    /* Get the first entry in the page table to set */
    pPageTablePtr = pMasterPt + (pRegion->startAddr >> MMU_PAGEBOUND_SHIFT);

    /* Set the pointer to the last entry */
    pPageTablePtr += (pRegion->numPages - 1); 

    /* Get the start Address MSB 3 nibbles, Ignore extended address.
       And set the page type (section or super-section). */        
           
    /* Page size is 1MB -> page type is section*/
    if((S_PASS == status) &&(MEM_SIZE_MB == pRegion->pgSize))
    {
        ptEntry = ((pRegion->startAddr) & 
                    (MMU_PGADDR_SECTION << MMU_PAGETABLE_ADDR_SHIFT)) |
                                (MMU_PGTYPE_SECTION);
    } 
    /* Page size is 16MB -> page type is super-section. */
    else if ((16U * MEM_SIZE_MB) == pRegion->pgSize)
    {
        ptEntry = ((pRegion->startAddr) & 
                    (MMU_PGADDR_SUPER_SECTION << MMU_PAGETABLE_ADDR_SHIFT)) | 
                                (MMU_PGTYPE_SUPER_SECTION);        
    }
    else
    {
        status = E_INVALID_PARAM;
    }
                
    /* Update the page table entry with Access Permissions. */
    if((S_PASS == status) && (pRegion->accessCtrl <= MMU_ACCESS_CTRL_MAX))
    {
        ptEntry |= gMmuAccessCtrl[pRegion->accessCtrl];
    }
    else
    {
        status = E_INVALID_PARAM;
    }
        
    /* Update the page table entry with security type. */
    if((S_PASS == status) && (pRegion->isMemSecure == TRUE))
    {
        ptEntry &= ~MMU_NON_SECURE_MASK;
    }
    else if(pRegion->isMemSecure == FALSE)
    {
        ptEntry |= MMU_NON_SECURE_MASK;
    }
    else
    {
        status = E_INVALID_PARAM;
    }            
        
    /* Set the memory type (SO, Device, Normal). */
    if((S_PASS == status) && (pRegion->memAttrib <= MMU_MEM_ATTR_MAX))
    {
          ptEntry |= gMmuMemAttr[pRegion->memAttrib];
    }
    else
    {
        status = E_INVALID_PARAM;
    }
        
    /* Inner and outer cache policies - Applicable for normal memory only. */
    if((S_PASS == status) && 
        ((MMU_MEM_ATTR_NORMAL_SHAREABLE == pRegion->memAttrib) || 
                (MMU_MEM_ATTR_NORMAL_NON_SHAREABLE == pRegion->memAttrib)))
    {
        ptEntry |= (pRegion->innerCachePolicy << MMU_INNER_CACHE_POLICY_SHIFT)|
                   (pRegion->outerCachePolicy << MMU_OUTER_CACHE_POLICY_SHIFT);
    }
                
    /* Set the entries in the page table for the region attributes */
    if(S_PASS == status)
    {
        for(index = (pRegion->numPages - 1); index >= 0; index--)
        {
            *pPageTablePtr-- = ptEntry + (index << MMU_PAGEBOUND_SHIFT);
        }
    }
    return status;
}


void MMUEnable(uint32_t *masterPt)
{
    /* Set TTB0 register */
    CP15Ttb0Set((uint32_t)masterPt);

    /* Enable MMU */
    CP15MMUEnable();
}


void MMUDisable(void)
{
    /* Disable MMU */
    CP15MMUDisable();
}

