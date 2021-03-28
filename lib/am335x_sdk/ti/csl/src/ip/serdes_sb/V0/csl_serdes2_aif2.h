/**
 * @file csl_serdes2_aif2.h
 *
 * @brief
 *  Header file for functional layer of CSL SERDES AIF2.
 *
 *  It contains the various enumerations, structure definitions and function
 *  declarations
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2013-2018, Texas Instruments, Inc.
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
/** ============================================================================
 *
 * @defgroup CSL_SERDES_AIF2 SERDES AIF2
 * @ingroup CSL_SERDES_API
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This module deals with setting up SERDES configuration for AIF2. The API flow should be as follows:   \n
 *
 * CSL_AIF2SerdesInitB8 (base_addr, ref_clock, rate); or/and CSL_AIF2SerdesInitB4 (base_addr, ref_clock, rate);
 *
 * CSL_AIF2SerdesLaneConfig (base_addr, ref_clock, rate, lane_num);
 *
 * CSL_AIF2SerdesComEnable (base_addr);
 *
 * CSL_AIF2SerdesLaneEnable (base_addr, lane_num, link_rate);
 *
 * CSL_AIF2SerdesLoopbackEnable (base_addr, lane_num, loopback_mode);
 *
 * CSL_AIF2SerdesPllEnableB8 (base_addr); or/and  CSL_AIF2SerdesPllEnableB4 (base_addr);
 *
 * CSL_AIF2SerdesGetStatusB8/B4 (base_addr); or/and  CSL_AIF2SerdesGetStatusB4 (base_addr);
 *
 * @subsection References
 *
 * ============================================================================
 */
#include <ti/csl/csl_serdes.h>
#include <ti/csl/csl_aif2.h>
#include <ti/csl/src/ip/serdes_sb/V0/csl_wiz8_sb.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline CSL_SERDES_RESULT CSL_AIF2SerdesInitB8
(
 uint32_t  base_addr,
 CSL_SERDES_REF_CLOCK  ref_clock,
 CSL_SERDES_LINK_RATE  rate
)
{
    CSL_SerdesSetWaitAfter(base_addr);
    CSL_SERDES_DISABLE_PLL_AND_LANES(base_addr, CSL_SERDES_MAX_LANES);
    if (!(ref_clock == CSL_SERDES_REF_CLOCK_122p88M || ref_clock == CSL_SERDES_REF_CLOCK_153p6M))
    {
        return CSL_SERDES_INVALID_REF_CLOCK;
    } 
    if (ref_clock == CSL_SERDES_REF_CLOCK_122p88M && rate == CSL_SERDES_LINK_RATE_4p9152G)
    {   
        csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_122p88M && rate == CSL_SERDES_LINK_RATE_6p144G)
    {
        csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_153p6M && rate == CSL_SERDES_LINK_RATE_6p144G)
    {
        csl_wiz8_sb_refclk153p6MHz_20bit_6p144Gbps(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_153p6M && rate == CSL_SERDES_LINK_RATE_4p9152G)
    {
        csl_wiz8_sb_refclk153p6MHz_20bit_4p9152Gbps_sr1(base_addr);
    }
    if (!( (rate == CSL_SERDES_LINK_RATE_4p9152G) || (rate == CSL_SERDES_LINK_RATE_6p144G) ))
    {
        return CSL_SERDES_INVALID_LANE_RATE;
    }
    return CSL_SERDES_NO_ERR;
}

static inline CSL_SERDES_RESULT CSL_AIF2SerdesInitB4
(
 uint32_t  base_addr,
 CSL_SERDES_REF_CLOCK  ref_clock,
 CSL_SERDES_LINK_RATE  rate
)
{
    CSL_SerdesSetWaitAfter(base_addr);
    CSL_SERDES_DISABLE_PLL_AND_LANES(base_addr, CSL_SERDES_MAX_LANES);
    if (!(ref_clock == CSL_SERDES_REF_CLOCK_122p88M || ref_clock == CSL_SERDES_REF_CLOCK_153p6M))
    {
        return CSL_SERDES_INVALID_REF_CLOCK;
    } 
    if (ref_clock == CSL_SERDES_REF_CLOCK_122p88M && rate == CSL_SERDES_LINK_RATE_4p9152G)
    {   
        csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps_2l1c(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_122p88M && rate == CSL_SERDES_LINK_RATE_6p144G)
    {
        csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps_2l1c(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_153p6M && rate == CSL_SERDES_LINK_RATE_6p144G)
    {
        csl_wiz8_sb_refclk153p6MHz_20bit_6p144Gbps_2l1c(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_153p6M && rate == CSL_SERDES_LINK_RATE_4p9152G)
    {
        csl_wiz8_sb_refclk153p6MHz_20bit_4p9152Gbps_2l1c_sr1(base_addr);
    }
    if (!( (rate == CSL_SERDES_LINK_RATE_4p9152G) || (rate == CSL_SERDES_LINK_RATE_6p144G) ))
    {
        return CSL_SERDES_INVALID_LANE_RATE;
    }
    return CSL_SERDES_NO_ERR;
}

static inline void CSL_AIF2SerdesLaneConfig
(
 uint32_t base_addr,
 CSL_SERDES_REF_CLOCK ref_clock,
 CSL_SERDES_LINK_RATE rate,
 uint32_t lane_num
)
{
	return;
}

static inline void CSL_AIF2SerdesComEnable
(
 uint32_t base_addr
)
{
	return;
}

static inline void CSL_AIF2SerdesPllEnableB8
(
 uint32_t aif2_ctrl_base_addr,
 uint32_t aif2_serdes_base_addr
)
{
    *(volatile uint32_t *)(aif2_ctrl_base_addr + 0xB000) = 0x00000003;
    CSL_FINSR(*(volatile uint32_t *)(aif2_serdes_base_addr + 0x1FC0 + 0x34), 31, 29, (uint32_t)0x7);
}

static inline void CSL_AIF2SerdesPllEnableB4
(
 uint32_t aif2_ctrl_base_addr,
 uint32_t aif2_serdes_base_addr
)
{
    *(volatile uint32_t *)(aif2_ctrl_base_addr + 0xB004) = 0x00000003;
    CSL_FINSR(*(volatile uint32_t *)(aif2_serdes_base_addr + 0x1FC0 + 0x34), 31, 29, (uint32_t)0x7);
}

static inline void CSL_AIF2LinkClkEnable
(
 uint32_t base_addr,
 uint32_t link_num
)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xB01C), (uint32_t) link_num, (uint32_t) link_num, 0x0);
}
static inline void CSL_AIF2LinkClkDisable
(
 uint32_t base_addr,
 uint32_t link_num
)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xB01C), (uint32_t) link_num, (uint32_t) link_num, 0x1);
}

static inline void CSL_AIF2SerdesLaneDisable
(
 uint32_t base_addr,
 uint32_t lane_num
)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),31,29, (uint32_t)0x4);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),15,13, (uint32_t)0x4);
}

static inline void CSL_AIF2SerdesLaneReset
(
 uint32_t base_addr,
 uint32_t lane_num
)
{
    return;
}

static inline CSL_SERDES_STATUS CSL_AIF2SerdesGetStatusB8
(
 uint32_t base_addr
)
{
    CSL_SERDES_STATUS retval;
    retval = (CSL_SERDES_STATUS)CSL_FEXTR(*(volatile uint32_t *)(base_addr + 0xB010), 0, 0);
    return retval;
}

static inline CSL_SERDES_STATUS CSL_AIF2SerdesGetStatusB4
(
 uint32_t base_addr
)
{
    CSL_SERDES_STATUS retval;
    retval = (CSL_SERDES_STATUS)CSL_FEXTR(*(volatile uint32_t *)(base_addr + 0xB014), 0, 0);
    return retval;
}

static inline void CSL_AIF2SerdesLaneEnable
(
 uint32_t aif2_ctrl_base_addr,
 uint32_t aif2_serdes_base_addr,
 uint32_t lane_num,
 uint32_t link_rate
) 
{
    if(link_rate == CSL_AIF2_LINK_RATE_8x)
    {
        *(volatile uint32_t *)(aif2_ctrl_base_addr + 0x8000 + (0x800*lane_num) + 0x04) = 0x00000000;
    }
    else if(link_rate == CSL_AIF2_LINK_RATE_4x)
    {
        *(volatile uint32_t *)(aif2_ctrl_base_addr + 0x8000 + (0x800*lane_num) + 0x04) = 0x00000020;
    }
    else
    {
        *(volatile uint32_t *)(aif2_ctrl_base_addr + 0x8000 + (0x800*lane_num) + 0x04) = 0x00000040;
    }
    *(volatile uint32_t *)(aif2_ctrl_base_addr + 0x8000 + (0x800*lane_num) + 0x00) = 0x00000003;
    *(volatile uint32_t *)(aif2_ctrl_base_addr + 0x8000 + (0x800*lane_num) + 0x10) = 0x00000003;
    *(volatile uint32_t *)(aif2_ctrl_base_addr + 0x8000 + (0x800*lane_num) + 0x14) = 0x00000000;
    CSL_FINSR(*(volatile uint32_t *)(aif2_serdes_base_addr + 0x1fe0 + 4*(lane_num&3)),31,29, (uint32_t)0x7);
    CSL_FINSR(*(volatile uint32_t *)(aif2_serdes_base_addr + 0x1fe0 + 4*(lane_num&3)),15,13, (uint32_t)0x7);
     CSL_SerdesClearWaitAfter(aif2_serdes_base_addr);   
}

static inline void CSL_AIF2SerdesLoopbackEnable
(
 uint32_t base_addr,
 uint32_t lane_num,
 CSL_SERDES_LOOPBACK loopback_mode
)
{
    if (loopback_mode == CSL_SERDES_LOOPBACK_ENABLED)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1)),30,30, (uint32_t)0x1);
    }
}

static inline void CSL_AIF2SerdesClkSelB4
(
 uint32_t base_addr
)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xB018), 1, 0, 0x2);
}
static inline void CSL_AIF2SerdesShutdown
(
 uint32_t base_addr
) 
{
    uint32_t i=0;
    for(i=0; i<4; i++)
    {
        CSL_AIF2SerdesLaneDisable(base_addr, i);
    } 
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1FC0 + 0x34), 31, 29, (uint32_t)0x4);
}

static inline uint32_t CSL_AIF2SerdesIsReset
(
 uint32_t base_addr
)
{
	uint32_t serdesIsReset;
	serdesIsReset = (CSL_FEXTR(*(volatile uint32_t *)(base_addr + 0xa00), 4, 0) == 0);
	return (serdesIsReset);
}
/* @} */

#ifdef __cplusplus
}
#endif
