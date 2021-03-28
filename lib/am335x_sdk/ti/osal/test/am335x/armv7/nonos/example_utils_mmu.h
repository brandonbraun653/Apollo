/**
 *  \file   example_utils_mmu.h
 *
 *  \brief  This file defines MMU example util which configures DDR, OCMC RAM
 *          and Device memory regions to fixed configuration. The applications 
 *          can call the API to configure and enable MMU. If different 
 *          configuration is needed for an example then such configurations has
 *          to be handled with in that example.
 */
 
/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef EXAMPLE_UTILS_MMU_H_
#define EXAMPLE_UTILS_MMU_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief  Number of entries in a page table. This is only for first level 
            page table. */
#define MMU_PAGETABLE_NUM_ENTRY           (4096U)

/** \brief  Alignment for Page Table. The Page Table shall be aligned to 16KB 
 *          boundary.
 *
 * Note: This alignment is based on ARM, for other arch if a different value 
 *       is required this macro should be moved to arch specific file.
 */
#define MMU_PAGETABLE_ALIGN_SIZE          (16U * MEM_SIZE_KB)

/** Memory definitions for MMU Configurations. */
/* TODO: Need to get the below data from chip/board db. */
#define START_ADDR_DDR                    (0x80000000U)
#define START_ADDR_DEV                    (0x44000000U)
#define START_ADDR_L2_SRAM                (0x40500000U)
#define START_ADDR_QSPI                   (0x30000000U)

/* Section size is 1MB, below macros are multiples of 1MB. */
#define NUM_SECTIONS_DDR                  (128U)
#define NUM_SECTIONS_DEV                  (960U)
#define NUM_SECTIONS_OCMC                 (1U)
#define NUM_SECTIONS_L2_SRAM              (1U)
#define NUM_SECTIONS_QSPI                 (64U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

extern volatile uint32_t pageTable[MMU_PAGETABLE_NUM_ENTRY];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

void MMUConfigAndEnable(void);

#ifdef __cplusplus
}
#endif
#endif /* EXAMPLE_UTILS_MMU_H_ */
