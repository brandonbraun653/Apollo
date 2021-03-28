/**  
 * @file csl_serdes2_ethernet.h
 *
 * @brief 
 *  Header file for functional layer of CSL SERDES. 
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
 * @defgroup CSL_SERDES_ETHERNET SERDES ETHERNET
 * @ingroup CSL_SERDES_API
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This module deals with setting up SERDES configuration for ETHERNET. The API flow should be as follows:   \n
 *
 * CSL_EthernetSerdesInit (base_addr, ref_clock, rate);
 *
 * CSL_SerdesLaneEnable (&serdes_init_params);
 * @subsection References
 *    
 * ============================================================================
 */ 
#include <ti/csl/csl_serdes.h>
#include <ti/csl/src/ip/serdes_sb/V0/csl_wiz8_sb.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline CSL_SERDES_RESULT CSL_EthernetSerdesInit
(
 uint32_t  base_addr,
 CSL_SERDES_REF_CLOCK  ref_clock,
 CSL_SERDES_LINK_RATE  rate
)
{
    CSL_SerdesSetWaitAfter(base_addr);
    CSL_SERDES_DISABLE_PLL_AND_LANES(base_addr, CSL_SERDES_MAX_LANES);
    if (!(ref_clock == CSL_SERDES_REF_CLOCK_125M || ref_clock == CSL_SERDES_REF_CLOCK_156p25M))
    {
        return CSL_SERDES_INVALID_REF_CLOCK;
    }
    if (ref_clock == CSL_SERDES_REF_CLOCK_125M && rate == CSL_SERDES_LINK_RATE_1p25G)
    {   
        csl_wiz8_sb_refclk125MHz_10bit_5Gbps(base_addr);
    }
    if (ref_clock == CSL_SERDES_REF_CLOCK_125M && rate == CSL_SERDES_LINK_RATE_3p125G)
    {
    	csl_wiz8_sb_refclk125MHz_20bit_6p25Gbps(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_156p25M && rate == CSL_SERDES_LINK_RATE_1p25G)
    {
        csl_wiz8_sb_refclk156p25MHz_10bit_5Gbps(base_addr);
    }
    else if (ref_clock == CSL_SERDES_REF_CLOCK_156p25M && rate == CSL_SERDES_LINK_RATE_3p125G)
    {
    	csl_wiz8_sb_refclk156p25MHz_20bit_6p25Gbps(base_addr);
    }
    if (!(rate == CSL_SERDES_LINK_RATE_1p25G || rate == CSL_SERDES_LINK_RATE_3p125G))
    {
        return CSL_SERDES_INVALID_LANE_RATE;
    }
    return CSL_SERDES_NO_ERR;
}
/* @} */
/* nothing past this point */
#ifdef __cplusplus
}
#endif
