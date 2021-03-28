/**
 * @file csl_serdes3_usb.h
 *
 * @brief
 *  Header file for functional layer of CSL SERDES.
 *
 *  It contains the various enumerations, structure definitions and function
 *  declarations
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017, Texas Instruments, Inc.
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
 * @defgroup CSL_SERDES_USB SERDES USB
 * @ingroup CSL_SERDES_API
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This module deals with setting up SERDES configuration for USB. The API flow should be as follows:   \n
 *
 * CSL_serdesUSBInit (baseAddr, numLanes, refClock, rate);
 *
 * CSL_serdesLaneEnable (&serdesLaneEnableParams);
 *
 * @subsection References
 *
 * ============================================================================
 */

#include <ti/csl/csl_serdes.h>
#include <ti/csl/csl_serdes_usb.h>
#include <ti/csl/src/ip/serdes_sb/V1/csl_wiz8m_sb.h>


CSL_SerdesResult CSL_serdesUSBInit
(
 uint32_t            baseAddr,
 uint32_t            numLanes,
 CSL_SerdesRefClock  refClock,
 CSL_SerdesLinkRate  rate
)
{

    CSL_SerdesResult result = CSL_SERDES_NO_ERR;

    CSL_serdesDisablePllAndLanes(baseAddr, numLanes);
    CSL_serdesPorReset(baseAddr);

	/* CMU_WAIT has to be set to a lower value for fast sim before loading the config since the CMU ticker kicks off in the config */
	#ifdef CSL_SERDES_FAST_SIM_MODE
        /* temp!! RXEQ disabled temporarilily until stable Gen3 is achieved */
        CSL_serdesRxEqDisable(baseAddr);
		CSL_serdesSetCMUWaitVal(baseAddr, 20);
	#endif

    if (!(refClock == CSL_SERDES_REF_CLOCK_20M || refClock == CSL_SERDES_REF_CLOCK_100M))
    {
        result = CSL_SERDES_INVALID_REF_CLOCK;
    }

    if (numLanes == 1)
    {
        if (refClock == CSL_SERDES_REF_CLOCK_20M && rate == CSL_SERDES_LINK_RATE_5G)
        {
            csl_wiz8m_sb_refclk20p0MHz_16b_5p0Gbps_USB_1l1c_sr(baseAddr);
        }
	if (refClock == CSL_SERDES_REF_CLOCK_100M && rate == CSL_SERDES_LINK_RATE_5G)
        {
            csl_wiz8m_sb_refclk100p0MHz_16b_5p0Gbps_USB_1l1c_sr(baseAddr);
        }
    }

    if (rate != CSL_SERDES_LINK_RATE_5G)
    {
        result = CSL_SERDES_INVALID_LANE_RATE;
    }

    /* For Fast Sim mode, enable fast_sim_o after config load */
#ifdef CSL_SERDES_FAST_SIM_MODE
    CSL_serdesFastSimEnable(baseAddr);
#endif

    /* Update for USB3.0 - Might go away when having official config from Rambus */

    /* COMREQ_R014, Increase Averaging (csr_ebstadapt_num_bounce_o = 0x7) */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0x14)), 18,16,0x7);

    /*COMRXEQ_R010, csr_catt_num_bounce_o = 0x7  */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0x10)), 10,8,0x7);

    /* COMRXEQ_R018, CSR_EBSTADAPT_PATTERN_MATCH_THRESHOLD_O = d64, x40 */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0x18)), 22,16,0x40);

     
    /* LANE_R14C, increase slicer common mode voltage ahb_pma_ln_sr_slicer_vcm_sel_o = 0x2 */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesLaneMap(baseAddr, 0,  0x14C)), 3, 2, 0x2);

    /* LANE_R060 Change selc/selr settings,  ahb_pma_ln_rx_selc_o = 0x4.   Try setting the  to 7 for short. 4 for long */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesLaneMap(baseAddr, 0,  0x60)), 10, 8, 0x7);

    /* LANE_R060 ahb_pma_ln_rx_selr_o = 0x2  Try setting the  to 0 for short. 2 for long */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesLaneMap(baseAddr, 0,  0x60)), 6, 4, 0x0);


    //high boost value =  more boost
    //high ATT value = low ATT  (inverse relationship)

    /* Forcing CDR_CONTROL_ATT_CTRL_O to 0(default 1 in USB config) */
    /*setting laneNum = 0 */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesLaneMap(baseAddr, 0,  0x48)), 9, 9, 0x0); 

    /* Forcing AHB_PMA_LN_AGC_THSEL_O to 0(default 7 in USB config) */
    /* setting laneNum = 0.  Lower value of AGC results in lower Att , higher attentuation */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesLaneMap(baseAddr, 0,  0x58)), 21, 19, 0x0);  


    /* Forcing the BOOST adapt mode to 2 */
    /* Forcing to Edge based 0x2 (Data Level based works better in loopback) */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0x28)), 27,26,0x2); 

    /* Ceiling ATT val at 3 */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0x14)), 4,2,0x3);

    /* This will be overwritten when we force ATT/BOOST or force start values */
    /* calibration Rate1 default FF */   
    /* DFE on, using Coarse ATT, Level and edge based Boost */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0xC)), 7,0,0x6F);

    /* csr_rxeq_init_run_rate1_o*/
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0x4)), 23,16,0x6F);

    /* calibration Rate2 default FF*/
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0xC)), 15,8,0x6F);

    /* csr_rxeq_init_run_rate2_o*/
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesComRXEQMap(baseAddr, 0x4)), 31,24,0x6F);

    /* setting detect threshold to 75 mv (0x2) 200mv (0x7) */
    /* LANE_R058, AHB LANE 0x5A [2:0] ahb_pma_ln_sd_thsel_div4_o = 0x3 */
    CSL_FINSR(*(volatile uint32_t *)(CSL_serdesLaneMap(baseAddr, 0,  0x58)), 18, 16, 0x2);

    return result;
}
