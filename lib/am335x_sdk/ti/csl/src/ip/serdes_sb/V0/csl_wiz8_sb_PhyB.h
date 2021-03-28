/**
 * @file csl_wiz8_sb_PhyB.h
 *
 * @brief
 *  Header file for functional layer of CSL SERDES.
 *
 *  It contains the various function declarations
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015-2018, Texas Instruments, Inc.
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

#ifdef __cplusplus
extern "C" {
#endif

void csl_wiz8_sb_PhyB_10p3125G_156p25MHz_cmu1(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125G_16bit_312p5MHz_lane1(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125G_16bit_312p5MHz_lane2(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125G_16bit_lane1(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125G_16bit_lane2(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125G_312p5MHz_cmu1(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125G_312p5_comlane(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125G_comlane(uint32_t base_addr);
void csl_wiz8_sb_PhyB_10p3125Gbps_16bit_156p25MHz(uint32_t base_addr);
void csl_wiz8_sb_PhyB_1p25G_156p25MHz_cmu0(uint32_t base_addr);
void csl_wiz8_sb_PhyB_1p25G_156p25MHz_comlane(uint32_t base_addr);
void csl_wiz8_sb_PhyB_1p25G_312p5MHz_cmu0(uint32_t base_addr);
void csl_wiz8_sb_PhyB_1p25G_312p5MHz_comlane(uint32_t base_addr);
void csl_wiz8_sb_PhyB_Firmware(uint32_t base_addr);
void csl_wiz8_sb_PhyB_IEEE_1558_en_lane1(uint32_t base_addr);
void csl_wiz8_sb_PhyB_IEEE_1558_en_lane2(uint32_t base_addr);
void csl_wiz8_sb_PhyB_aneg_lane1(uint32_t base_addr);
void csl_wiz8_sb_PhyB_aneg_lane2(uint32_t base_addr);
void csl_wiz8_sb_PhyB_aneg_lane_312p5_lane1(uint32_t base_addr);
void csl_wiz8_sb_PhyB_aneg_lane_312p5_lane2(uint32_t base_addr);
void csl_wiz8_sb_PhyB_reset_clr(uint32_t base_addr);

#ifdef __cplusplus
}
#endif
