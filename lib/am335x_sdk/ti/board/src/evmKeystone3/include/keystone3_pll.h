/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 
#ifndef _KEYSTONE3_PLL_H_
#define _KEYSTONE3_PLL_H_

/**
 * \file   keystone3_pll.h
 *
 * \brief  AM65x idk PLL configurations header file
 *
 * This file includes the structures, enums and register offsets
 * for PLL configurations
 *
 */
#include "board_internal.h"
#include "board_pll.h"
#include "ti/csl/soc.h"
#include <ti/csl/hw_types.h>

#define MAIN_PSC_BASE               (0x00400000)
#define PSC_PID                     (0x44827A00)

/**
 *  \brief  This macro is used to set the perticular bit fields in the pll
 *          controller registers.
 *
 *  \param  regaddrs - Address of the pll controller register
 *  \param  value    - value to write into the register
 *  \param  width    - bitfield width
 *  \param  lshift   - left shift value
 *
 */
#define SETBITS(regaddrs, value, width, lshift) \
                regaddrs = (regaddrs & ~(((1<<width)-1)<<lshift)) | \
                ((value & ((1<<width)-1)) << lshift)

/**
 *  \brief  Read the perticular bit fields in the pll controller registers 
 *
 *  \param  regaddrs - Address of the pll controller register
 *  \param  width    - bitfield width
 *  \param  rshift   - right shift value
 *
 */
#define READBITS(regaddrs, width, rshift) \
                ((regaddrs & (((1<<width)-1) << rshift)) >> rshift)

/**
 *
 * \brief PLL controller type
 *
 * This enumeration defines PLL controller types
 *
 */
typedef enum
{
    CSL_MCU_PLL,    /*  MCU  PLL  */
    CSL_MAIN_PLL,   /*  MAIN PLL  */
    CSL_ARM0_PLL,   /*  ARM0 PLL  */
    CSL_ARM1_PLL,   /*  ARM1 PLL  */
    CSL_DDR_PLL,    /*  DDR  PLL  */
    CSL_PER0_PLL,   /*  PER0 PLL  */
    CSL_PER1_PLL,   /*  PER1 PLL  */
    CSL_CPSW_PLL,   /*  CPSW PLL  */
    CSL_DSS_PLL     /*  DSS  PLL  */
    
} CSL_PllcType;
 
/**
 *  \brief This structure defines the base addressess and controller
 *         adressess for various PLL controller.
 *
 */
typedef struct
{
	uint32_t pllbaseaddrs;
	uint32_t ctrlbaseaddrs;
} keystonePllcReg;

/**
 *
 * \brief PLL controller type
 *
 * This enumeration defines PLL types
 *
 */
typedef enum
{
	PLL_TYPEOF_ADPLLLJM,
	PLL_TYPEOF_ADPLLM
} PllcType;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         PLL controller.
 *
 */
typedef struct
{
	CSL_PllcType pll;
    /**< PLL controller type */
    PllcType pll_type;
    /**< PLL type */
    uint32_t hsdiv_exist;
    /**< PLL HSDIV exist status */
    uint32_t ctrl_exist;
    /**< PLL control exist staus */    
	uint32_t m_frac_mult;
    /**< PLL fractional multiplication ratio */
	uint32_t m_int_mult;
    /**< PLL  multiplication ratio */
	uint32_t sd_div;
    /**< PLL sd divider */
	uint32_t n_div;
    /**< PLL n divider */
	uint32_t m1_div;
    /**< PLL bypass output divider */
	uint32_t m2_div;
    /**< DCO output divider */
	uint32_t m3_div;
    /**< CLKOUTHIF output divider */
	uint32_t hsdiv4;
    /**< High speed divider 4 */
	uint32_t hsdiv3;
    /**< High speed divider 3 */
	uint32_t hsdiv2;
    /**< High speed divider 2 */
	uint32_t hsdiv1;
    /**< High speed divider 1 */
    uint32_t bpdiv_val; 
    /**< PLL controller bp divider */
    uint32_t od1_val;
    /**< PLL controller od1 divider */
    uint32_t div1_val;
    /**< PLL controller div1 divider */
} pllcConfig;

extern const keystonePllcReg keystonePllcRegs[];
extern const keystonePllcReg keystoneM3PllcRegs[];
extern const pllcConfig pllcConfigs[];

extern uint32_t Board_getNumPllcConfigs(void);
 
#endif  /* _KEYSTONE3_PLL_H_ */

