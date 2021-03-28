/**  
 * @file csl_serdes2_10ge_10ge.h
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
 * @defgroup CSL_SERDES_10GE SERDES 10GE
 * @ingroup CSL_SERDES_API
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This module deals with setting up SERDES configuration for 10GE. 
   The API flow should be as follows:   \n
 * CSL_10GeSerdesTXBClkMode(base_addr, link_rate);
 * 
 * CSL_10GeSerdesInit (base_addr, ref_clock, rate);
 *
 * CSL_10GeSerdesLaneConfig (base_addr, ref_clock, rate, lane_num);
 *
 * CSL_10GeSerdesComEnable (base_addr, rate);
 *
 * CSL_SerdesLaneEnable (&serdes_lane_enable_params);
 *
 * CSL_10GeSerdesEnableXGMIIPort (base_addr);
 *
 *******************************************************************************
 * The new CSL_10GeSerdesFirmwareInit API replaces all the APIs mentioned above. 
   The new API flow is:
 *
 * CSL_10GeSerdesFirmwareInit(base_addr,
                      *pFWCfg,
                  link_loss_timeout,
                  txbclk_enable,
                  num_lanes);
 *
 * @subsection References
 *    
 * ============================================================================
 */ 
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_serdes.h>
#include <ti/csl/src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    CSL_SERDES_FORCE_10G    =   0,
    CSL_SERDES_FORCE_1G  =  1,
    CSL_SERDES_DEFAULT   =  2
} CSL_SERDES_10G_ADVERTISE_RATE;

typedef struct CSL_SERDES_10G_FW_CFG_T
{
    Bool                             enable_autoneg[CSL_SERDES_MAX_LANES];
    CSL_SERDES_10G_ADVERTISE_RATE    advertise_rate[CSL_SERDES_MAX_LANES];
    Bool                             enable_txpause[CSL_SERDES_MAX_LANES]; 
    Bool                             enable_rxpause[CSL_SERDES_MAX_LANES];
    Bool                             enable_10Gtrain[CSL_SERDES_MAX_LANES];
    Bool                             enable_fec[CSL_SERDES_MAX_LANES]; 
}CSL_SERDES_10G_FW_CFG_T;

static inline CSL_SERDES_RESULT CSL_10GeSerdesInit
(
        uint32_t  base_addr,
        CSL_SERDES_REF_CLOCK  ref_clock,
        CSL_SERDES_LINK_RATE  rate
)
{
    if (ref_clock != CSL_SERDES_REF_CLOCK_156p25M)
    {
        return CSL_SERDES_INVALID_REF_CLOCK;
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x34), 31, 29, (uint32_t)0x4);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x34), 27, 25, (uint32_t)0x4); 
    if (ref_clock == CSL_SERDES_REF_CLOCK_156p25M && rate == CSL_SERDES_LINK_RATE_10p3125G)
    {
        csl_wiz8_sb_PhyB_1p25G_156p25MHz_cmu0(base_addr);
        csl_wiz8_sb_PhyB_10p3125G_156p25MHz_cmu1(base_addr);
    }
    if (ref_clock == CSL_SERDES_REF_CLOCK_156p25M && rate == CSL_SERDES_LINK_RATE_1p25G)
    {
        csl_wiz8_sb_PhyB_1p25G_156p25MHz_cmu0(base_addr);
        csl_wiz8_sb_PhyB_10p3125G_156p25MHz_cmu1(base_addr);
    }
    if (!(rate == CSL_SERDES_LINK_RATE_10p3125G || rate == CSL_SERDES_LINK_RATE_1p25G))
    {
        return CSL_SERDES_INVALID_LANE_RATE;
    }
    return CSL_SERDES_NO_ERR;
}

static inline void CSL_10GeSerdesLaneConfig
(
        uint32_t base_addr,
        CSL_SERDES_REF_CLOCK ref_clock,
        CSL_SERDES_LINK_RATE rate,
        uint32_t lane_num
)
{
    if (ref_clock == CSL_SERDES_REF_CLOCK_156p25M && rate == CSL_SERDES_LINK_RATE_10p3125G)
    {
        if (lane_num == 0)
        {
            csl_wiz8_sb_PhyB_10p3125G_16bit_lane1(base_addr);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x180),4,4, 0x0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x1C0),9,9, 0x0);
        }
        else if (lane_num == 1)
        {
            csl_wiz8_sb_PhyB_10p3125G_16bit_lane2(base_addr);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x180),4,4, 0x0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x1C0),9,9, 0x0);
        }       
    }
    if (ref_clock == CSL_SERDES_REF_CLOCK_156p25M && rate == CSL_SERDES_LINK_RATE_1p25G)
    {
        if (lane_num == 0)
        {
            csl_wiz8_sb_PhyB_aneg_lane1(base_addr);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x180),4,4, 0x0);         
        }
        else if (lane_num == 1)
        {
            csl_wiz8_sb_PhyB_aneg_lane2(base_addr);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x180),4,4, 0x0);         
        }
    }
}

static inline void CSL_10GeSerdesComEnable
(
        uint32_t base_addr,
        CSL_SERDES_LINK_RATE rate
)
{
    if(rate == CSL_SERDES_LINK_RATE_10p3125G)
    {
        csl_wiz8_sb_PhyB_10p3125G_comlane(base_addr);
    }
    if(rate == CSL_SERDES_LINK_RATE_1p25G)
    {
        csl_wiz8_sb_PhyB_1p25G_156p25MHz_comlane(base_addr);
    }
}

static inline void CSL_10GeSerdesTXBClkMode
(
        uint32_t base_addr,
        CSL_SERDES_LINK_RATE rate
)
{
    if (rate == CSL_SERDES_LINK_RATE_1p25G)
    {
        *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x20000000;
        *(volatile uint32_t *)(base_addr + 0x1ff4) = 0x00380000;
        *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x00000000;
    }
    else
    {
        return;
    }
}

static inline void CSL_10GeSerdesEnableXGMIIPort
(
        uint32_t base_addr
)
{
    *(volatile uint32_t *)(base_addr + 0x0c) = 0x3;
}

static inline void CSL_10GeSerdesDisableXGMIIPort
(
        uint32_t base_addr
)
{
    *(volatile uint32_t *)(base_addr + 0x0c) = 0x0;
}

static inline void CSL_10GeSerdesFirmwareInit
(
        uint32_t base_addr,
        CSL_SERDES_10G_FW_CFG_T *pFWCfg,
        uint64_t link_loss_timeout,
        uint32_t txbclk_enable,
        uint32_t num_lanes
)
  {
    uint32_t i, count;
    uint32_t lane_config = 0;
    uint32_t lane_tmp[CSL_SERDES_MAX_LANES] = {0, 0, 0, 0};
    *(volatile uint32_t *)(base_addr + 0x1fc0 + 0x34) = 0x88000000;
    *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x20000000;
    for(i=0;i<=1000;i++);
    *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x00000000;
    if (txbclk_enable)
    {
      *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x20000000;
      *(volatile uint32_t *)(base_addr + 0x1ff4) = 0xee380000;
      *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x00000000;
    }
    for(i= 0; i < num_lanes ; i++)
    {
      CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*i),31,29, (uint32_t)0x7);
      CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*i),15,13, 0x7);
    }
    *(volatile uint32_t *)(base_addr + 0x1ff0) = link_loss_timeout;
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1ff4), 31, 29, (uint32_t)0x7 );
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1ff4), 27, 25, 0x7 );
    for(i= 0; i < num_lanes ; i++)
    {
        lane_tmp[i] |= ((pFWCfg->enable_autoneg[i] & 0x1)<<7);
        if (pFWCfg->advertise_rate[i] != CSL_SERDES_FORCE_1G)
        {
          lane_tmp[i] |= ((0x1 & 0x1)<<6);
        }
        else
        {
          lane_tmp[i] |= ((0x0 & 0x1)<<6);
        }
        if (pFWCfg->advertise_rate[i] != CSL_SERDES_FORCE_10G)
        {
          lane_tmp[i] |= ((0x1 & 0x1)<<5);
        }
        else
        {
          lane_tmp[i] |= ((0x0 & 0x1)<<5);
        }
        lane_tmp[i] |= ((pFWCfg->enable_txpause[i] & 0x1)<<4);
        lane_tmp[i] |= ((pFWCfg->enable_rxpause[i] & 0x1)<<3);
        lane_tmp[i] |= ((pFWCfg->enable_10Gtrain[i] & 0x1)<<2);
        lane_tmp[i] |= ((pFWCfg->enable_fec[i] & 0x1)<<1);
           if(i == 0)
           {
             lane_tmp[i] = (lane_tmp[i]<<16);
           }
           else if (i == 1)
           {
             lane_tmp[i] = (lane_tmp[i]<<8);
           }           
        lane_config |= lane_tmp[i];
    }
    *(volatile uint32_t *)(base_addr + 0x1fc4) = 0x0000ffc0;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000; 
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00009C9C;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x60000000; 
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00000000;
    *(volatile uint32_t *)(base_addr + 0x1fcc) = 0x00276400;    
    *(volatile uint32_t *)(base_addr + 0x1fcc) = lane_config;   
    csl_wiz8_sb_PhyB_Firmware(base_addr);
    *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x3c000000;
    count = 0;
    while(1)
        {
            count++;
            if (count > 5000)
            break;
        }
    *(volatile uint32_t *)(base_addr + 0x1fd0) = 0x1c000000;
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x000), 23, 16, 0x80);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xc10), 31, 24, 0x40);
    *(volatile uint32_t *)(base_addr + 0x1fd0) = 0xdc000000;
  }
  
/* @} */

#ifdef __cplusplus
}
#endif
