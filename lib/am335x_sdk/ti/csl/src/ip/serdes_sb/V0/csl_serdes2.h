/**
 * @file csl_serdes2.h
 *
 * @brief
 *  Header file for functional layer of CSL SERDES.
 *
 *  It contains the various enumerations, structure definitions and function
 *  declarations
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2013-2016, Texas Instruments, Inc.
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
 * @defgroup CSL_SERDES
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This is the top level SERDES API with enumerations for various supported
   reference clocks, link rates, lane control rates across different modules.
 *
 *
 * @subsection References
 *
 * ============================================================================
 */
#ifndef CSL_SERDES_V0_H_
#define CSL_SERDES_V0_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <string.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/csl_serdes_restore_default.h>
extern CSL_Uint64 CSL_tscRead (void);
typedef enum
{
   CSL_SERDES_REF_CLOCK_100M        =   0,
   CSL_SERDES_REF_CLOCK_122p88M     =   1,
   CSL_SERDES_REF_CLOCK_125M        =   2,
   CSL_SERDES_REF_CLOCK_153p6M     =    3,
   CSL_SERDES_REF_CLOCK_156p25M     =   4,
   CSL_SERDES_REF_CLOCK_312p5M      =   5
} CSL_SERDES_REF_CLOCK;

typedef enum
{
   CSL_SERDES_LINK_RATE_1p25G        =   0,
   CSL_SERDES_LINK_RATE_3p125G        =   1,
   CSL_SERDES_LINK_RATE_4p9152G      =   2,
   CSL_SERDES_LINK_RATE_5G           =   3,
   CSL_SERDES_LINK_RATE_6p144G       =   4,
   CSL_SERDES_LINK_RATE_6p25G        =   5,
   CSL_SERDES_LINK_RATE_7p3728G      =   6,
   CSL_SERDES_LINK_RATE_9p8304G      =   7,
   CSL_SERDES_LINK_RATE_10G          =   8,
   CSL_SERDES_LINK_RATE_10p3125G     =   9,
   CSL_SERDES_LINK_RATE_12p5G        =   10
} CSL_SERDES_LINK_RATE;

typedef enum
{
    CSL_SERDES_LOOPBACK_ENABLED   =  0,
    CSL_SERDES_LOOPBACK_DISABLED  =  1
} CSL_SERDES_LOOPBACK;

typedef enum
{
    CSL_SERDES_STATUS_PLL_NOT_LOCKED = 0,
    CSL_SERDES_STATUS_PLL_LOCKED     = 1
} CSL_SERDES_STATUS;

typedef enum
{
    CSL_SERDES_NO_ERR               = 0,
    CSL_SERDES_INVALID_REF_CLOCK    = 1,
    CSL_SERDES_INVALID_LANE_RATE    = 2
} CSL_SERDES_RESULT;

typedef enum
{
    CSL_SERDES_LANE_FULL_RATE      = 0,
    CSL_SERDES_LANE_HALF_RATE      = 1,
    CSL_SERDES_LANE_QUARTER_RATE   = 2
} CSL_SERDES_LANE_CTRL_RATE;

typedef enum
{
    CSL_SERDES_LANE_ENABLE_NO_ERR           = 0,
    CSL_SERDES_LANE_ENABLE_INVALID_RATE     = 1,
    CSL_SERDES_LANE_ENABLE_PERIPHERAL_BASE_NOT_SET      = 2,
    CSL_SERDES_LANE_ENABLE_ITERATION_MODE_NOT_SET     = 3,
    CSL_SERDES_LANE_ENABLE_SIG_UNDETECTED            = 4 
} CSL_SERDES_LANE_ENABLE_STATUS;

typedef enum
{
    SERDES_10GE = 0,
    SERDES_AIF2_B8     = 1,
    SERDES_AIF2_B4     = 2,
    SERDES_SRIO     = 3,
    SERDES_PCIe     = 4,
    SERDES_HYPERLINK     = 5,
    SERDES_SGMII     = 6,
    SERDES_DFE       = 7,
    SERDES_IQN       = 8
} csl_serdes_phy_type;

#define CSL_SERDES_MAX_LANES                4
#define CSL_SERDES_MAX_TAPS                 5
#define CSL_SERDES_MAX_COMPARATORS          5
#define CSL_SERDES_TBUS_SIZE                155
#define CSL_SERDES_PHY_A_1LANE_QUAD_MUX     0x4ebe
#define CSL_SERDES_PHY_A_2LANE_NO_MUX       0x4eb8
#define CSL_SERDES_PHY_A_2LANE_QUAD_MUX     0x4ebc
#define CSL_SERDES_PHY_A_4LANE_NO_MUX       0x4eb9
#define CSL_SERDES_PHY_A_4LANE_QUAD_MUX     0x4ebd
#define CSL_SERDES_PHY_B_2LANE_NO_MUX       0x4eba
#define CSL_SERDES_ATT_BOOST_NUM_REPEAT     20
#define CSL_SERDES_ATT_BOOST_REPEAT_MEAN    14

typedef struct CSL_SERDES_TBUS_DUMP
{
    uint32_t    taddr[CSL_SERDES_TBUS_SIZE];
    uint32_t    tbus_data[CSL_SERDES_TBUS_SIZE];
} CSL_SERDES_TBUS_DUMP_T;

typedef struct CSL_SERDES_TAP_OFFSETS
{
    uint32_t   tap1_offsets[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap2_offsets[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap3_offsets[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap4_offsets[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap5_offsets[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   cmp_offsets[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_COMPARATORS];
    uint32_t   izerocmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_COMPARATORS];
    uint32_t   izerotap1[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   izerotap2[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   izerotap3[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   izerotap4[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   izerotap5[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap1_offsets_tmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap2_offsets_tmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap3_offsets_tmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap4_offsets_tmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
    uint32_t   tap5_offsets_tmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
} CSL_SERDES_TAP_OFFSETS_T;

typedef struct CSL_SERDES_DLEV_OUT
{
    uint32_t   delay[CSL_SERDES_MAX_LANES];
    int32_t   tap_values[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
} CSL_SERDES_DLEV_OUT_T;

typedef struct CSL_SERDES_TX_COEFF
{
    uint32_t tx_att[CSL_SERDES_MAX_LANES];
    uint32_t tx_vreg[CSL_SERDES_MAX_LANES];
    uint32_t cm_coeff[CSL_SERDES_MAX_LANES];
    uint32_t c1_coeff[CSL_SERDES_MAX_LANES];
    uint32_t c2_coeff[CSL_SERDES_MAX_LANES];
}CSL_SERDES_TX_COEFF_T;

typedef struct CSL_SERDES_RX_COEFF
{
    int32_t rx_att[CSL_SERDES_MAX_LANES];
    int32_t rx_boost[CSL_SERDES_MAX_LANES];
    int32_t att_start[CSL_SERDES_MAX_LANES];
    int32_t boost_start[CSL_SERDES_MAX_LANES];
    int32_t force_att_val[CSL_SERDES_MAX_LANES];
    int32_t force_boost_val[CSL_SERDES_MAX_LANES];
}CSL_SERDES_RX_COEFF_T;

typedef struct CSL_SERDES_LINK_STAT
{
    uint32_t current_state[CSL_SERDES_MAX_LANES];
    uint32_t lane_down[CSL_SERDES_MAX_LANES];
}CSL_SERDES_LINK_STAT_T;

typedef enum
{
    CSL_SERDES_FORCE_ATT_BOOST_DISABLED  =  0,
    CSL_SERDES_FORCE_ATT_BOOST_ENABLED   =  1
} CSL_SERDES_FORCE_ATT_BOOST;

typedef enum
{
    CSL_SERDES_LANE_ENABLE_COMMON_INIT  = 1,    
    CSL_SERDES_LANE_ENABLE_LANE_INIT   = 2,
    CSL_SERDES_LANE_ENABLE_LANE_INIT_NO_WAIT   = 3
} CSL_SERDES_LANE_ENABLE_ITERATION_MODE;

typedef enum
{
    CSL_SERDES_FUNCTIONAL_MODE  =  0,
    CSL_SERDES_DIAGNOSTIC_MODE   =  1
} CSL_SERDES_OPERATING_MODE;

typedef struct CSL_SERDES_TX_TERM
{
    uint32_t tx_term_p;
    uint32_t tx_term_n;
}CSL_SERDES_TX_TERM_T;

typedef struct CSL_SERDES_LANE_ENABLE_PARAMS
{
    uint32_t base_addr;
    uint32_t num_lanes;
    CSL_SERDES_REF_CLOCK ref_clock;
    CSL_SERDES_LINK_RATE linkrate;
    CSL_SERDES_TX_COEFF_T tx_coeff;
    CSL_SERDES_RX_COEFF_T rx_coeff;
    CSL_SERDES_FORCE_ATT_BOOST forceattboost;
    uint8_t lane_mask;
    csl_serdes_phy_type phy_type;
    uint32_t polarity[CSL_SERDES_MAX_LANES];
    CSL_SERDES_LANE_CTRL_RATE lane_ctrl_rate[CSL_SERDES_MAX_LANES];
    CSL_SERDES_LOOPBACK loopback_mode[CSL_SERDES_MAX_LANES];  
    CSL_SERDES_OPERATING_MODE operating_mode;
    uint32_t peripheral_base_addr;
    CSL_SERDES_LANE_ENABLE_ITERATION_MODE iteration_mode;
    CSL_SERDES_TAP_OFFSETS_T tapOffsets;
}CSL_SERDES_LANE_ENABLE_PARAMS_T;


static inline void CSL_SerdesWriteTbusAddr(uint32_t base_addr,
                                             int32_t    iSelect,
                                             int32_t    iOffset)
{
  int32_t isPhyA;
  int32_t isNotFourLaner;
  isNotFourLaner=(*(volatile uint32_t *)(base_addr + 0x1fc0)>>16)&0x0ffff;
  isPhyA    = (isNotFourLaner != CSL_SERDES_PHY_B_2LANE_NO_MUX);
  if ((isNotFourLaner==CSL_SERDES_PHY_A_4LANE_NO_MUX)
       ||(isNotFourLaner==CSL_SERDES_PHY_A_4LANE_QUAD_MUX))
      {
          isNotFourLaner=0;
      }
  else
      {
          isNotFourLaner=1;
      }
  if ((iSelect)&&(isNotFourLaner))
      {
          iSelect++;
      }
 if (isPhyA) 
    {
       CSL_FINSR(*(volatile uint32_t *)(base_addr+0x0008), 31,24,
                                        (uint32_t)((iSelect) << 5) + iOffset);
    }
  else 
    {
       CSL_FINSR(*(volatile uint32_t *)(base_addr+0x00fc), 26,16,
                                        ((iSelect) << 8) + iOffset);
    }
}

static inline uint32_t CSL_SerdesReadTbusVal(uint32_t base_addr)
{
      int32_t isPhyA;
      int32_t isNotFourLaner;
      uint32_t iTmp;
      isNotFourLaner=(*(volatile uint32_t *)(base_addr + 0x1fc0)>>16)&0x0ffff;
      isPhyA    = (isNotFourLaner != CSL_SERDES_PHY_B_2LANE_NO_MUX);
       if(isPhyA)
       {
          iTmp  = (*(volatile uint32_t *)(base_addr + 0x0ec) >> 24) & 0x0ff;
          iTmp |=((*(volatile uint32_t *)(base_addr + 0x0fc) >> 16) & 0x00f00);
       }
       else
       {
          iTmp  = (*(volatile uint32_t *)(base_addr + 0x0f8) >> 16) & 0x0fff;
       }
       return(iTmp);
}

static inline uint64_t CSL_Serdes_GetTimestamp()
{
    return CSL_tscRead();
}

static inline void CSL_Serdes_CycleDelay (uint64_t count)
{
  uint64_t sat = 0;
  if (count <= 0)
  return;
#if defined(_TMS320C6X)
  sat = CSL_Serdes_GetTimestamp() + (uint64_t)count;
  while (CSL_Serdes_GetTimestamp() < sat);
#else
  for(sat=0;sat<count;sat++);
#endif
}

static inline void CSL_SerdesSetTXIdle(uint32_t base_addr,
                         uint32_t lane_num,
                         csl_serdes_phy_type phy_type)
{
    if(phy_type != SERDES_10GE)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num + 1) + 0x0b8),17,16,3);
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + (lane_num*4) + 0x020),25,24,3);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num + 1) + 0x028),21,20,0);
}

static inline void CSL_SerdesClearTXIdle(uint32_t base_addr,
                       uint32_t lane_num,
                       csl_serdes_phy_type phy_type)
{
    if(phy_type != SERDES_10GE)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num + 1) + 0x0b8),17,16,0);
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + (lane_num*4) + 0x020),25,24,0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num + 1) + 0x028),21,20,3);
}

static inline void CSL_SerdesWaitForSignalDetect(uint32_t base_addr,
                                              uint8_t  lane_mask)
{
    while((*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x034) & lane_mask) != lane_mask);
}

static inline void CSL_SerdesWaitForSignalDetectPerLane(uint32_t base_addr,
                                                     uint32_t lane_num)
{
    while((*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x034) & lane_num) != lane_num);
}

static inline uint32_t CSL_SerdesReadSigDet(uint32_t base_addr,
                                                     uint32_t lane_num)
{
    uint32_t retval;
    retval = (CSL_SERDES_STATUS)CSL_FEXTR(*(volatile uint32_t *)
                  (base_addr + 0x1ff4), (0 + lane_num), (0 + lane_num));
    return retval;
}

static inline void CSL_SerdesSetWaitAfter(uint32_t base_addr)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x034),17,16,3);
}

static inline void CSL_SerdesClearWaitAfter(uint32_t base_addr)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x034),17,16,0);
}

static inline void CSL_SerdesClearWaitAfterPerLane(uint32_t base_addr, uint32_t lane_num)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x034),(12+lane_num),(12+lane_num),1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x034),(4+lane_num),(4+lane_num),1);
}

static inline void CSL_SerdesSetHyperlinkPattern(uint32_t base_addr)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x0c8),5,0,0x00f);
}

static inline void CSL_SerdesSetTXTermValue(uint32_t base_addr,
                                              uint32_t num_lanes,
                                              uint32_t term_val)
{
    uint32_t lane_num;
    for(lane_num=0;lane_num<num_lanes;lane_num++)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x7c),31,24, term_val); 
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x7c),20,20, 0x1);
    }
}

static inline void CSL_SerdesSetLanePolarity(uint32_t base_addr,
                                               uint32_t lane_num,
                                               uint32_t polarity)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x20 + (lane_num*4)),9,9,1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fc0 + 0x20 + (lane_num*4)),8,8, polarity);
}

static inline void CSL_SERDES_DISABLE_PLL_AND_LANES(uint32_t            base_addr,
                                                      uint32_t            num_lanes)
{
     uint32_t lane_num;
     CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x34),31,29,(uint32_t)0x04);
     for(lane_num=0;lane_num<num_lanes;lane_num++)
     {
         CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),31,29,(uint32_t)0x04);
         CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),15,13,0x04);  
     }
}

static inline void CSL_SERDES_SHUTDOWN(uint32_t            base_addr,
                                         uint32_t            num_lanes)
{
     uint32_t lane_num;
     CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x34),31,29,(uint32_t)0x04);
     for(lane_num=0;lane_num<num_lanes;lane_num++)
     {
         CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),31,29,(uint32_t)0x04);
         CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),15,13,0x04);  
     }
     CSL_SerDes_Restore_Default(base_addr);
}

static inline void CSL_SERDES_DISABLE_PLL(uint32_t            base_addr,
                                            csl_serdes_phy_type phy_type)
{
     CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x34),31,29,(uint32_t)0x04);
}

static inline void CSL_Serdes_Lane_Disable(uint32_t            base_addr,
                                              uint32_t            lane_num)
{
     CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),31,29,(uint32_t)0x4);
     CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),15,13,0x4);
}

static inline void CSL_Serdes_Lane_Enable(uint32_t               base_addr,
                                             uint32_t               lane_num)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),31,29,(uint32_t)0x07);
    CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),15,13,0x07);
}

static inline void CSL_Serdes_Force_Signal_Detect_Low(uint32_t               base_addr,
                                                        uint32_t               num_lanes,
                                                        uint8_t                lane_mask)
{
    uint32_t lane_num;
    for(lane_num=0; lane_num<num_lanes; lane_num++)
    {
        if ((lane_mask & (1<<lane_num))!=0)
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x04),2,1, 0x2);
        }
    }
}

static inline void CSL_Serdes_Force_Signal_Detect_Enable(uint32_t               base_addr,
                                                    uint32_t               lane_num)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x04),2,1,0);
}

static inline void CSL_SERDES_CONFIG_ATT_BOOST(uint32_t            base_addr,
                                                uint32_t            lane_num,
                                                int32_t            att,
                                                int32_t            boost,
                                                csl_serdes_phy_type phy_type)
{
 if(phy_type != SERDES_10GE)
 {
     if(att!=-1)
     {
         CSL_FINSR(*(volatile uint32_t *)(base_addr+0xa00+0x84),0,0,0);
         CSL_FINSR(*(volatile uint32_t *)(base_addr+0xa00+0x8c),24,24,0);
         CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x8c),11,8,att);
     }
     if(boost!=-1)
     {
         CSL_FINSR(*(volatile uint32_t *)(base_addr+0xa00+0x84),1,1,0);
         CSL_FINSR(*(volatile uint32_t *)(base_addr+0xa00+0x8c),25,25,0);
         CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x8c),15,12,boost);
     }
 }
 else
 {
    CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x98),13,13,0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x8c),15,12,boost);
    CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x8c),11,8,att);  
 }
}

static inline uint32_t CSL_SerdesReadSelectedTbus(uint32_t base_addr,
                                                    int32_t     iSelect,
                                                    int32_t     iOffset)
{
    CSL_SerdesWriteTbusAddr(base_addr,iSelect,iOffset);   
    return(CSL_SerdesReadTbusVal(base_addr));             
}

static inline uint32_t CSL_SERDES_READ_ATT_BOOST(uint32_t            base_addr,
                                                uint32_t            lane_num,
                                                csl_serdes_phy_type phy_type)
{
    return CSL_SerdesReadSelectedTbus(base_addr, lane_num + 1, (phy_type==SERDES_10GE)?0x10:0x11);
}

static inline uint32_t CSL_SerdesGetTXTermValues(uint32_t base_addr,
                                                   csl_serdes_phy_type        phy_type)
{
    uint32_t temp;
    if(phy_type == SERDES_10GE)
    {
        temp = CSL_SerdesReadSelectedTbus(base_addr, 1, 0x1a) & 0x00ff;
    }
    else
    {
        temp = CSL_SerdesReadSelectedTbus(base_addr, 1, 0x1b) & 0x00ff;
    }
    return temp;
}

static inline void CSL_SerdesWaitForRXValidPerLane(uint32_t base_addr,
                                              uint8_t  lane_num,
                                              csl_serdes_phy_type phy_type)
{
    uint32_t stat;
    uint32_t timeout = 100000000;

    if(phy_type != SERDES_PCIe)
    {
        stat = (CSL_SerdesReadSelectedTbus(base_addr, lane_num+1, 0x2) & 0x020)>>5;
        while ((stat != 1) && (timeout != 0))
        {
            stat = (CSL_SerdesReadSelectedTbus(base_addr, lane_num+1, 0x2) & 0x020)>>5;
            timeout--;
        }
    }
    else
    {
        stat = (CSL_SerdesReadSelectedTbus(base_addr, lane_num+1, 0x2) & 0x008)>>3;
        while ((stat != 1) && (timeout != 0))
        {
            stat = (CSL_SerdesReadSelectedTbus(base_addr, lane_num+1, 0x2) & 0x008)>>3;
            timeout--;
        }
    }
}

static inline void CSL_SerdesWaitForSigDet(uint32_t base_addr, uint32_t lane_num)
{
    uint32_t retval = 0;
    while(retval != 1)
    {
        retval = (CSL_SERDES_STATUS)CSL_FEXTR(*(volatile uint32_t *)
                  (base_addr + 0x1ff4), (0 + lane_num), (0 + lane_num));
    }
}

static inline void CSL_SerdesWaitForRXValid(uint32_t base_addr,uint32_t num_lanes,
                                              uint8_t  lane_mask, csl_serdes_phy_type phy_type)
{
    uint32_t lane_num;
    for(lane_num=0; lane_num<num_lanes; lane_num++)
        {
            if ((lane_mask & (1<<lane_num))!=0)
            {
                CSL_SerdesWaitForRXValidPerLane(base_addr, lane_num, phy_type);
            }
        }
}

static inline void csl_serdes_tbus_dump(uint32_t                   base_addr,
                                          CSL_SERDES_TBUS_DUMP_T     *pTbusDump,
                                          csl_serdes_phy_type        phy_type)
{
    uint32_t i,j;
    uint32_t count = 0;
    if (phy_type == SERDES_10GE)
    {
        for(i = 0; i < 6; i++)
        {
            for (j = 0; j < 67; j++)
            {
                pTbusDump->taddr[count] = (i << 8) | j;
                CSL_FINSR(*(volatile uint32_t *)(base_addr+0x00fc), 26, 16,
                pTbusDump->taddr[count]);
                pTbusDump->tbus_data[count] = CSL_SerdesReadTbusVal(base_addr);
                count++;
            }
        }
    }
    else
    {
        for(i = 0; i < 5; i++)
            {
                for (j = 0; j < 31; j++)
                {
                    pTbusDump->taddr[count] = (i << 5) | j;
                    CSL_FINSR(*(volatile uint32_t *)(base_addr+0x0008), 31, 24,
                    pTbusDump->taddr[count]);
                    pTbusDump->tbus_data[count] = (*(uint32_t *) (base_addr + 0x00EC));
                    pTbusDump->tbus_data[count] = (pTbusDump->tbus_data[count] & 0xFF000000) >> 24;
                    pTbusDump->tbus_data[count] = pTbusDump->tbus_data[count] |
                    (((*(uint32_t *) (base_addr + 0x00FC)) >> 16) & 0x00000F00);
                }
        }
    }
}

static inline void CSL_SERDES_CONFIG_CM_C1_C2(uint32_t            base_addr,
                                                uint32_t            lane_num,
                                                uint32_t            CMcoeff,
                                                uint32_t            C1coeff,
                                                uint32_t            C2coeff,
                                                csl_serdes_phy_type phy_type)
{
 if(phy_type != SERDES_10GE)
 {
     CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x8),15,12,CMcoeff);
     CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x8),4,0,C1coeff);
     CSL_FINSR(*(volatile uint32_t *)(base_addr+(lane_num*0x200)+0x200+0x8),11,8,C2coeff);
 }
 else
 {
     CSL_FINSR(*(volatile uint32_t *)(base_addr +(lane_num*0x200)+0x200+0x8),11,8,CMcoeff);
     CSL_FINSR(*(volatile uint32_t *)(base_addr +(lane_num*0x200)+0x200+0x8),4,0,C1coeff);
     CSL_FINSR(*(volatile uint32_t *)(base_addr +(lane_num*0x200)+0x200+0x8),7,5,C2coeff);
     CSL_FINSR(*(volatile uint32_t *)(base_addr +(lane_num*0x200)+0x200+0x4),18,18,C2coeff>>3);
 }
}

static inline CSL_SERDES_RESULT CSL_Serdes_Deassert_Reset(uint32_t            base_addr,
                                                            csl_serdes_phy_type phy_type,
                                                            uint32_t            isBlock,
                                                            uint32_t            num_lanes,
                                                            uint8_t             lane_mask)
{
    int32_t isNotFourLaner, iTmp, lane_num;
    uint32_t retval = CSL_SERDES_STATUS_PLL_LOCKED;
    isNotFourLaner=(*(volatile uint32_t *)(base_addr + 0x1fc0)>>16)&0x0ffff;
    if ((isNotFourLaner==CSL_SERDES_PHY_A_4LANE_NO_MUX)
       ||(isNotFourLaner==CSL_SERDES_PHY_A_4LANE_QUAD_MUX))
    {
        isNotFourLaner=0;
    }
    else
    {
        isNotFourLaner=1;
    }
    for(lane_num=0;(uint32_t)lane_num<num_lanes;lane_num++)
    {
        if ((lane_mask & (1<<lane_num))!=0)
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x28),29,29, 0x0);
        }
    }
    if(isBlock)
    {
        if(phy_type != SERDES_PCIe)
        {
            do
            {
                retval = CSL_SERDES_STATUS_PLL_LOCKED;
                for(lane_num=0; (uint32_t)lane_num < num_lanes; lane_num++)
                {
                    if ((lane_mask & (1<<lane_num))!=0)
                    {
                        if(isNotFourLaner)
                        {
                            retval &= (CSL_SERDES_STATUS)CSL_FEXTR(*(volatile uint32_t *)
                            (base_addr + 0xa00 + 0x1f8), (29+lane_num), (29+lane_num));
                        }
                        else
                        {
                            retval &= (CSL_SERDES_STATUS)CSL_FEXTR(*(volatile uint32_t *)
                            (base_addr + 0xa00 + 0x1f8), (28+lane_num), (28+lane_num));
                        }
                    }
                }
            }while(retval != CSL_SERDES_STATUS_PLL_LOCKED);
        }
        else
        {
            for(lane_num=0;(uint32_t)lane_num<num_lanes;lane_num++)
            {
                if ((lane_mask & (1<<lane_num))!=0)
                {
                    iTmp = (CSL_SerdesReadSelectedTbus(base_addr, lane_num+1, 0x02) & 0x0010) >> 4;
                    while(iTmp!=0)
                    iTmp = (CSL_SerdesReadSelectedTbus(base_addr, lane_num+1, 0x02) & 0x0010) >> 4;
                }
            }
        }
    }
    return CSL_SERDES_NO_ERR;
}

static inline void CSL_Serdes_Assert_Reset(uint32_t               base_addr,
                                             csl_serdes_phy_type    phy_type,
                                             uint8_t                lane_mask)
{
    uint32_t lane_num;
    for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
    {
        if ((lane_mask & (1<<lane_num))!=0)
        {
            uint32_t uiTmp0,uiTmp1,uiTmpO;
            uiTmp0=CSL_SerdesReadSelectedTbus(base_addr,lane_num+1,0); 
            uiTmp1=CSL_SerdesReadSelectedTbus(base_addr,lane_num+1,1); 
            uiTmpO =  0;                          
            uiTmpO |= ((uiTmp1>>9)&0x003)<<1;     
            uiTmpO |= ((uiTmp0   )&0x003)<<3;     
            uiTmpO |= ((uiTmp0>>2)&0x1FF)<<5;     
            uiTmpO |= (1<<14);                    
            uiTmpO &= ~0x60;                      
            CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x28),29,15, uiTmpO);
        }
    }
}

static inline void CSL_SerdesGetAverageOffsets(uint32_t                   base_addr,
                                                 uint32_t                   num_lanes,
                                                 csl_serdes_phy_type        phy_type,
                                                 uint8_t                    lane_mask,
                                                 CSL_SERDES_TAP_OFFSETS_T   *pTapOffsets)
{
  uint32_t i,j,lane_num,comp_no;
  uint32_t iMinCmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_COMPARATORS];
  uint32_t iMaxCmp[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_COMPARATORS];
  uint32_t iMinTap1[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMaxTap1[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMinTap2[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMaxTap2[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMinTap3[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMaxTap3[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMinTap4[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMaxTap4[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMinTap5[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iMaxTap5[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iZeroCmpCnt[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_COMPARATORS];
  uint32_t iZeroTap1Cnt[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iZeroTap2Cnt[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iZeroTap3Cnt[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iZeroTap4Cnt[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t iZeroTap5Cnt[CSL_SERDES_MAX_LANES][CSL_SERDES_MAX_TAPS];
  uint32_t cmp_offset_tmp,tap1_offset_tmp,tap2_offset_tmp,tap3_offset_tmp;
  uint32_t tap4_offset_tmp,tap5_offset_tmp;
  for(lane_num=0;lane_num<num_lanes;lane_num++)
  {
      if ((lane_mask & (1<<lane_num))!=0)
      {
          for(j=0;j<CSL_SERDES_MAX_TAPS;j++)
          {
              pTapOffsets->cmp_offsets[lane_num][j] =0;
              pTapOffsets->tap1_offsets[lane_num][j]=0;
              pTapOffsets->tap2_offsets[lane_num][j]=0;
              pTapOffsets->tap3_offsets[lane_num][j]=0;
              pTapOffsets->tap4_offsets[lane_num][j]=0;
              pTapOffsets->tap5_offsets[lane_num][j]=0;
              iMinCmp[lane_num][j] =0x0ffffff; iMaxCmp[lane_num][j] =0;
              iMinTap1[lane_num][j]=0x0ffffff; iMaxTap1[lane_num][j]=0;
              iMinTap2[lane_num][j]=0x0ffffff; iMaxTap2[lane_num][j]=0;
              iMinTap3[lane_num][j]=0x0ffffff; iMaxTap3[lane_num][j]=0;
              iMinTap4[lane_num][j]=0x0ffffff; iMaxTap4[lane_num][j]=0;
              iMinTap5[lane_num][j]=0x0ffffff; iMaxTap5[lane_num][j]=0;
              iZeroCmpCnt[lane_num][j] =0;
              iZeroTap1Cnt[lane_num][j]=0;
              iZeroTap2Cnt[lane_num][j]=0;
              iZeroTap3Cnt[lane_num][j]=0;
              iZeroTap4Cnt[lane_num][j]=0;
              iZeroTap5Cnt[lane_num][j]=0;
          }
      }
  }
for(i=0;i<100;i++)
{
    uint32_t iTmp;
    CSL_Serdes_Assert_Reset(base_addr, phy_type, lane_mask);
    CSL_Serdes_Deassert_Reset(base_addr, phy_type, 1, CSL_SERDES_MAX_LANES, lane_mask);
    iTmp= *(volatile uint32_t *)(base_addr + 0x1fc0 + 0x34);
    iTmp >>= 8;
    iTmp &= 0x0f;
    if(phy_type==SERDES_10GE)
    {
        for(lane_num=0;lane_num<num_lanes;lane_num++)
        {
            if ((lane_mask & (1<<lane_num))!=0)
            {
                for(comp_no=1;comp_no<CSL_SERDES_MAX_COMPARATORS;comp_no++)
                {
                    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x8c),23,21,comp_no);
                    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0fc),26,16,
                    0x11+((lane_num+2)<<8));
                    cmp_offset_tmp=(CSL_SerdesReadTbusVal(base_addr) & 0x0ff0)>>4;
                    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0fc),26,16,
                    0x11+((lane_num+2)<<8));
                    tap1_offset_tmp=(CSL_SerdesReadTbusVal(base_addr) & 0x000f)<<3;
                    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0fc),26,16,
                    0x12+((lane_num+2)<<8));
                    tap1_offset_tmp = tap1_offset_tmp | ((CSL_SerdesReadTbusVal(base_addr) & 0x0e00)>>9);
                    tap2_offset_tmp = (CSL_SerdesReadTbusVal(base_addr) & 0x01f8)>>3;
                    tap3_offset_tmp=(CSL_SerdesReadTbusVal(base_addr) & 0x007)<<3;
                    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0fc),26,16,
                    0x13+((lane_num+2)<<8));
                    tap3_offset_tmp= tap3_offset_tmp | ((CSL_SerdesReadTbusVal(base_addr) & 0xe00)>>9);
                    tap4_offset_tmp=(CSL_SerdesReadTbusVal(base_addr) & 0x01f8)>>3;
                    tap5_offset_tmp=(CSL_SerdesReadTbusVal(base_addr) & 0x0007)<<3;
                    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0fc),26,16,
                    0x14+((lane_num+2)<<8));
                    tap5_offset_tmp=tap5_offset_tmp | ((CSL_SerdesReadTbusVal(base_addr) & 0x0e00)>>9);
                      pTapOffsets->cmp_offsets[lane_num][comp_no] =
                      pTapOffsets->cmp_offsets[lane_num][comp_no]+cmp_offset_tmp;
                      pTapOffsets->tap1_offsets[lane_num][comp_no] =
                      pTapOffsets->tap1_offsets[lane_num][comp_no]+tap1_offset_tmp;
                      pTapOffsets->tap2_offsets[lane_num][comp_no] =
                      pTapOffsets->tap2_offsets[lane_num][comp_no]+tap2_offset_tmp;
                      pTapOffsets->tap3_offsets[lane_num][comp_no] =
                      pTapOffsets->tap3_offsets[lane_num][comp_no]+tap3_offset_tmp;
                      pTapOffsets->tap4_offsets[lane_num][comp_no] =
                      pTapOffsets->tap4_offsets[lane_num][comp_no]+tap4_offset_tmp;
                      pTapOffsets->tap5_offsets[lane_num][comp_no] =
                      pTapOffsets->tap5_offsets[lane_num][comp_no]+tap5_offset_tmp;
                      if (cmp_offset_tmp>iMaxCmp[lane_num][comp_no])
                      iMaxCmp[lane_num][comp_no]=cmp_offset_tmp;
                      if (cmp_offset_tmp<iMinCmp[lane_num][comp_no])
                      iMinCmp[lane_num][comp_no]=cmp_offset_tmp;
                      if (tap1_offset_tmp>iMaxTap1[lane_num][comp_no])
                      iMaxTap1[lane_num][comp_no]=tap1_offset_tmp;
                      if (tap1_offset_tmp<iMinTap1[lane_num][comp_no])
                      iMinTap1[lane_num][comp_no]=tap1_offset_tmp;
                      if (tap2_offset_tmp>iMaxTap2[lane_num][comp_no])
                      iMaxTap2[lane_num][comp_no]=tap2_offset_tmp;
                      if (tap2_offset_tmp<iMinTap2[lane_num][comp_no])
                      iMinTap2[lane_num][comp_no]=tap2_offset_tmp;
                      if (tap3_offset_tmp>iMaxTap3[lane_num][comp_no])
                      iMaxTap3[lane_num][comp_no]=tap3_offset_tmp;
                      if (tap3_offset_tmp<iMinTap3[lane_num][comp_no])
                      iMinTap3[lane_num][comp_no]=tap3_offset_tmp;
                      if (tap4_offset_tmp>iMaxTap4[lane_num][comp_no])
                      iMaxTap4[lane_num][comp_no]=tap4_offset_tmp;
                      if (tap4_offset_tmp<iMinTap4[lane_num][comp_no])
                      iMinTap4[lane_num][comp_no]=tap4_offset_tmp;
                      if (tap5_offset_tmp>iMaxTap5[lane_num][comp_no])
                      iMaxTap5[lane_num][comp_no]=tap5_offset_tmp;
                      if (tap5_offset_tmp<iMinTap5[lane_num][comp_no])
                      iMinTap5[lane_num][comp_no]=tap5_offset_tmp;
                      if (cmp_offset_tmp==0)
                      {
                      pTapOffsets->izerocmp[lane_num][comp_no] =i;
                      iZeroCmpCnt[lane_num][comp_no]++;
                      }
                      if (tap1_offset_tmp==0)
                      {
                      pTapOffsets->izerotap1[lane_num][comp_no]=i;
                      iZeroTap1Cnt[lane_num][comp_no]++;
                      }
                      if (tap2_offset_tmp==0)
                      {
                      pTapOffsets->izerotap2[lane_num][comp_no]=i;
                      iZeroTap2Cnt[lane_num][comp_no]++;
                      }
                      if (tap3_offset_tmp==0)
                      {
                      pTapOffsets->izerotap3[lane_num][comp_no]=i;
                      iZeroTap3Cnt[lane_num][comp_no]++;
                      }
                      if (tap4_offset_tmp==0)
                      {
                      pTapOffsets->izerotap4[lane_num][comp_no]=i;
                      iZeroTap4Cnt[lane_num][comp_no]++;
                      }
                      if (tap5_offset_tmp==0)
                      {
                      pTapOffsets->izerotap5[lane_num][comp_no]=i;
                      iZeroTap5Cnt[lane_num][comp_no]++;
                      }
                }
            }
          }
       }
     else
      {
         for(lane_num=0;lane_num<num_lanes;lane_num++)
         {
             if ((lane_mask & (1<<lane_num))!=0)
             {
                 for(comp_no=1; comp_no<CSL_SERDES_MAX_COMPARATORS; comp_no++)
                 {
                    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x8c),23,21, comp_no);
                     CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x008),31,24, 0x12+((lane_num+1)<<5));
                     cmp_offset_tmp=(CSL_SerdesReadTbusVal(base_addr) & 0x0ff0)>>4;
                     pTapOffsets->cmp_offsets[lane_num][comp_no] =
                     pTapOffsets->cmp_offsets[lane_num][comp_no]+cmp_offset_tmp;
                 }
              }
          }
      }
    }
  if(phy_type==SERDES_10GE)
  {
      for(lane_num=0;lane_num<num_lanes;lane_num++)
      {
          if ((lane_mask & (1<<lane_num))!=0)
          {
              for(comp_no=1; comp_no<CSL_SERDES_MAX_COMPARATORS; comp_no++)
              {
                pTapOffsets->cmp_offsets[lane_num][comp_no]  =
                pTapOffsets->cmp_offsets[lane_num][comp_no]/100;
                pTapOffsets->tap1_offsets[lane_num][comp_no] =
                pTapOffsets->tap1_offsets[lane_num][comp_no]/100;
                pTapOffsets->tap2_offsets[lane_num][comp_no] =
                pTapOffsets->tap2_offsets[lane_num][comp_no]/100;
                pTapOffsets->tap3_offsets[lane_num][comp_no] =
                pTapOffsets->tap3_offsets[lane_num][comp_no]/100;
                pTapOffsets->tap4_offsets[lane_num][comp_no] =
                pTapOffsets->tap4_offsets[lane_num][comp_no]/100;
                pTapOffsets->tap5_offsets[lane_num][comp_no] =
                pTapOffsets->tap5_offsets[lane_num][comp_no]/100;
              }
          }
      }
    }
   else
   {
       for(lane_num=0;lane_num<num_lanes;lane_num++)
       {
           if ((lane_mask & (1<<lane_num))!=0)
           {
               for(comp_no=1;comp_no<CSL_SERDES_MAX_COMPARATORS;comp_no++)
               {
                  pTapOffsets->cmp_offsets[lane_num][comp_no] =
                  pTapOffsets->cmp_offsets[lane_num][comp_no]/100;
               }
           }
       }
    }
  }

  static inline void CSL_Serdes_Write_Offsets(uint32_t                   base_addr,
                                                         uint32_t                   lane_num,
                                                         uint32_t                   comp_no,
                                                         CSL_SERDES_TAP_OFFSETS_T   *pTapOffsets)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0xF0),27,26, lane_num+1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x98),24,24,1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),2,2, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x30),7,5, comp_no);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),31,31,(uint32_t)1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x9C),7,0,
    pTapOffsets->cmp_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),30,24,
    pTapOffsets->tap1_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),5,0,
    pTapOffsets->tap2_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),13,8,
    pTapOffsets->tap3_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),21,16,
    pTapOffsets->tap4_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),29,24,
    pTapOffsets->tap5_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),10,10, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),10,10, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x98),24,24,0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),2,2, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),31,31,(uint32_t)0);
}

static inline void CSL_Serdes_Write_Offsets_RX_Calibration(uint32_t                   base_addr,
                                                         uint32_t                   lane_num,
                                                         uint32_t                   comp_no,
                                                         CSL_SERDES_TAP_OFFSETS_T   *pTapOffsets)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0xF0),27,26, lane_num+1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x98),24,24,1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),2,2, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x30),7,5, comp_no);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),31,31,(uint32_t)1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x9C),7,0,
    pTapOffsets->cmp_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),30,24,
    pTapOffsets->tap1_offsets_tmp[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),5,0,
    pTapOffsets->tap2_offsets_tmp[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),13,8,
    pTapOffsets->tap3_offsets_tmp[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),21,16,
    pTapOffsets->tap4_offsets_tmp[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),29,24,
    pTapOffsets->tap5_offsets_tmp[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),10,10, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),10,10, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00 + 0x98),24,24,0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2c),2,2, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5c),31,31,(uint32_t)0);
}

static inline void CSL_Serdes_Write_Offsets_PHYB(uint32_t                  base_addr,
                                                              uint32_t                  lane_num,
                                                              uint32_t                  fsm_select,
                                                              uint32_t                  comp_no,
                                                              CSL_SERDES_TAP_OFFSETS_T *pTapOffsets)
{
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),16,16, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),16,16, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),18,18, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x4c),5,2, fsm_select);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),24,17,
    pTapOffsets->cmp_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),18,18, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),17,17, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),23,17,
    pTapOffsets->tap1_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 0x2);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17,
    pTapOffsets->tap2_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 0x4);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17,
    pTapOffsets->tap3_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 0x8);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17,
    pTapOffsets->tap4_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 0x10);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17,
    pTapOffsets->tap5_offsets[lane_num][comp_no]);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),16,16, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),16,16, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),18,18, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),17,17, 0x0);
}

static inline void CSL_Serdes_PHYA_Init_Config(uint32_t                  base_addr,
                                                     uint32_t                  lane_num)
{
    uint32_t    comp_no, comp_no_adjust, tap1_offset, tap1val, tap2val, tap3val, tap4val, tap5val;
    for(comp_no=1;comp_no<CSL_SERDES_MAX_COMPARATORS;comp_no++)
    {
        if(comp_no%2)
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x8C),23,21, comp_no);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x008),31,24, 0x12+((lane_num+1)<<5));
            tap1_offset=(CSL_SerdesReadTbusVal(base_addr) & 0x000f)<<3;
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x008),31,24, 0x13+((lane_num+1)<<5)); 
            tap1_offset=tap1_offset|((CSL_SerdesReadTbusVal(base_addr) & 0x0e00)>>9); 
            tap1val = tap1_offset-14;
            tap2val = tap3val = tap4val = tap5val = 31;
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00+0xF0),27,26, lane_num+1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2C),2,2, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x30),7,5, comp_no);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5C),31,31, (uint32_t)1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),30,24, tap1val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5C),6,0, tap2val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5C),13,8, tap3val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5C),21,16, tap4val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5C),29,24, tap5val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2C),10,10, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2C),10,10, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x2C),2,2, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x5C),31,31, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),16,16, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),16,16, 1);
            if (comp_no==1)
            {
                comp_no_adjust=1;
            }
            else if (comp_no == 2)
            {
                comp_no_adjust=2;
            }
            else if (comp_no == 3)
            {
                comp_no_adjust=4;
            }
            else if (comp_no == 4)
            {
                comp_no_adjust=8;
            }
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x4C),5,2, comp_no_adjust);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),17,17, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),23,17, tap1val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 2);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17, tap2val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 4);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17, tap3val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 8);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17, tap4val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),23,19, 16);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),22,17, tap5val);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 1);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),29,29, 0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),16,16, 0x0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x48),16,16, 0x0);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x58),17,17, 0x0);
         }
    }
}

static inline void CSL_SerdesWriteAverageOffsets(uint32_t                 base_addr,
                                                   uint32_t                 num_lanes,
                                                   uint32_t                 lane_mask,
                                                   csl_serdes_phy_type      phy_type,
                                                   CSL_SERDES_TAP_OFFSETS_T *pTapOffsets)
{
    uint32_t i,lane_num,comp_no;
    if(phy_type==SERDES_10GE)
    {
        for(lane_num=0;lane_num<num_lanes;lane_num++)
        {
            if ((lane_mask & (1<<lane_num))!=0)
            {
                i = 1;
                for(comp_no=1; comp_no<CSL_SERDES_MAX_COMPARATORS; comp_no++)
                {
                    CSL_Serdes_Write_Offsets(base_addr, lane_num,comp_no, pTapOffsets);
                    CSL_Serdes_Write_Offsets_PHYB(base_addr, lane_num, i, comp_no, pTapOffsets);
                    i = i*2;
                }
            }
        }
    }
    else
    {
        for(lane_num=0;lane_num<num_lanes;lane_num++)
        {
            if ((lane_mask & (1<<lane_num))!=0)
            {
                for(comp_no=1; comp_no<CSL_SERDES_MAX_COMPARATORS; comp_no++)
                {
                    CSL_Serdes_Write_Offsets(base_addr,lane_num,comp_no, pTapOffsets);
                }
            }
        }
    }
}

static inline void CSL_Serdes_PHYB_Init_Config(uint32_t              base_addr,
                                                      uint32_t              num_lanes,
                                                      csl_serdes_phy_type   phy_type,
                                                      uint8_t               lane_mask,
                                                      CSL_SERDES_TAP_OFFSETS_T *pTapOffsets)
{
    uint32_t lane_num;
    CSL_Serdes_Force_Signal_Detect_Low(base_addr, num_lanes, lane_mask);
    CSL_Serdes_CycleDelay(10000);
    CSL_SerdesGetAverageOffsets(base_addr,num_lanes, phy_type, lane_mask, pTapOffsets);
    CSL_SerdesWriteAverageOffsets(base_addr, num_lanes, lane_mask, phy_type, pTapOffsets);
    CSL_Serdes_CycleDelay(10000);
    for(lane_num=0;lane_num<num_lanes;lane_num++)
    {
        if ((lane_mask & (1<<lane_num))!=0)
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x04),2,1, 0x0);
        }
    }
    CSL_Serdes_CycleDelay(10000);
}
static inline void CSL_SerdesRXAttBoostConfig_PhyB(uint32_t              base_addr,
                                                 uint32_t              lane_num,
                                                 csl_serdes_phy_type   phy_type,
                                                 uint8_t              lane_mask)
{
    uint32_t boost_read=0, att_read=0,att_start;
    att_start = (*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x8c)>>8)&0xF;
    att_read = (CSL_SerdesReadSelectedTbus(base_addr, lane_num + 1, (phy_type==SERDES_10GE)?0x10:0x11)>>4)&0xF;
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x8c),11,8, att_read); 
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + ((phy_type==SERDES_10GE)?0x9c:0x84)),0,0, 0x0); 
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x8c),24,24,0);
    if(phy_type == SERDES_10GE)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x98),14,14, 1); 
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x98),14,14, 0);
    }
    else
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0xac),11,11, 1); 
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0xac),11,11, 0);
    }
    CSL_SerdesWaitForRXValidPerLane(base_addr, lane_num, phy_type);
    CSL_Serdes_CycleDelay(300000);
    boost_read = (CSL_SerdesReadSelectedTbus(base_addr, lane_num + 1, (phy_type==SERDES_10GE)?0x10:0x11)>>8)&0xF;
    if(boost_read == 0)
    {
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),2,2,1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),18,12,0x2);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),9,3,0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),10,10,1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),10,10,0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),2,2,0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),18,12,0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),9,3,0);
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x8c),11,8, att_start);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + ((phy_type==SERDES_10GE)?0x9c:0x84)),0,0, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x8c),24,24,1);
}

static inline void CSL_SerdesRXAttConfig_PhyA(uint32_t              base_addr,
                                                    uint32_t              num_lanes,
                                                    csl_serdes_phy_type   phy_type,
                                                    uint8_t              lane_mask)
{
    uint32_t att_read[CSL_SERDES_MAX_LANES],att_start[CSL_SERDES_MAX_LANES];
    uint32_t lane_num;
    for(lane_num=0; lane_num<num_lanes; lane_num++)
    {
        att_start[lane_num] = (*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x8c)>>8)&0xF;
    }
    for(lane_num=0; lane_num<num_lanes; lane_num++)
    {   
        att_read[lane_num] = (CSL_SerdesReadSelectedTbus(base_addr, lane_num + 1, (phy_type==SERDES_10GE)?0x10:0x11)>>4)&0xF;
    }
    for(lane_num=0; lane_num<num_lanes; lane_num++)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x8c),11,8, att_read[lane_num]); 
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x84),0,0, 0x0); 
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x8c),24,24,0); 
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x98),7,7, 1); 
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x98),7,7, 0); 
    CSL_Serdes_CycleDelay(300000);
    CSL_SerdesWaitForRXValid(base_addr, num_lanes, lane_mask, phy_type);
    for(lane_num=0; lane_num<num_lanes; lane_num++)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x8c),11,8, att_start[lane_num]);
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x84),0,0, 0x1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x8c),24,24,1);
}

static inline void CSL_SerdesRXBoostConfig_PhyA(uint32_t              base_addr,
                                                     uint32_t              lane_num,
                                                     csl_serdes_phy_type   phy_type,
                                                     uint8_t              lane_mask)
{
    uint32_t boost_read;
    CSL_SerdesWaitForRXValidPerLane(base_addr, lane_num, phy_type);
    boost_read = (CSL_SerdesReadSelectedTbus(base_addr, lane_num + 1, (phy_type==SERDES_10GE)?0x10:0x11)>>8)&0xF;
    if(boost_read == 0)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),2,2,1);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),18,12,0x2);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),9,3,0x1);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),10,10,1);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),10,10,0);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),2,2,0);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),18,12,0);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num * 0x200) + 0x200 + 0x2c),9,3,0);
    }
}

static inline void CSL_SerdesRXAttBoostConfig(uint32_t              base_addr,
                                             uint32_t              lane_num,
                                             uint32_t              num_lanes,
                                             csl_serdes_phy_type   phy_type,
                                             uint8_t              lane_mask)
{
    uint32_t i=0;
    if(phy_type == SERDES_10GE)
    {
        CSL_SerdesRXAttBoostConfig_PhyB(base_addr, lane_num, phy_type, lane_mask);
    }
    else
    {
        CSL_SerdesRXAttConfig_PhyA(base_addr, num_lanes, phy_type, lane_mask);
        for(i=0; i< num_lanes; i++)
        {
            if((lane_mask & (1<<i)) != 0)
            {
                CSL_SerdesRXBoostConfig_PhyA(base_addr, i, phy_type, lane_mask);
            }
        }
    }
}

static inline void CSL_Serdes_Write_32_Mask(uint32_t base_addr,
                              uint32_t mask_value,
                              uint32_t set_value)
{
  uint32_t temp;
  temp=(*(volatile uint32_t *)(base_addr));
  temp &= mask_value;
  temp |= ((~mask_value)&set_value);
  *(volatile uint32_t *)(base_addr) = temp;
}
static inline CSL_SERDES_LANE_ENABLE_STATUS CSL_SerdesSetLaneRate
(
 uint32_t base_addr,
 uint32_t lane_num,
 CSL_SERDES_LANE_CTRL_RATE lane_ctrl_rate,
 CSL_SERDES_LINK_RATE linkrate,
 csl_serdes_phy_type phy_type
)
{
    if (lane_ctrl_rate == CSL_SERDES_LANE_FULL_RATE)
    {
        if(phy_type == SERDES_SGMII)
        {
            return CSL_SERDES_LANE_ENABLE_INVALID_RATE;
        }
        else
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),28,26, 0x4);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),12,10, 0x4);
        }
    }
    if (lane_ctrl_rate == CSL_SERDES_LANE_QUARTER_RATE)
    {
        if(!(phy_type == SERDES_DFE || phy_type == SERDES_IQN 
	     || phy_type == SERDES_AIF2_B8 || phy_type == SERDES_AIF2_B4))
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),28,26, 0x6);
        }
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),12,10, 0x6);
    }
    if (lane_ctrl_rate == CSL_SERDES_LANE_HALF_RATE)
    {
        if(!(phy_type == SERDES_DFE || phy_type == SERDES_IQN
  	     || phy_type == SERDES_AIF2_B8 || phy_type == SERDES_AIF2_B4))
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),28,26, 0x5);
        }
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),12,10, 0x5);
    }
    if(phy_type == SERDES_SGMII || phy_type == SERDES_DFE || phy_type == SERDES_SRIO
      || phy_type == SERDES_AIF2_B8 || phy_type == SERDES_AIF2_B4)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),7,6,0x03);
    }
    if(phy_type == SERDES_SGMII)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),23,21,(uint32_t)0x04);
        CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),5,3,0x04);
    }
    else if(phy_type == SERDES_10GE)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),23,21,(uint32_t)0x07);
        CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),5,3,0x07);
    }
    else if(phy_type != SERDES_PCIe)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),23,21,(uint32_t)0x06);
        CSL_FINSR(*(volatile uint32_t *)(base_addr +0x1fc0 + 0x20 + (lane_num*4)),5,3,0x06);
    }
    if(phy_type == SERDES_10GE && linkrate == CSL_SERDES_LINK_RATE_10p3125G)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),23,21, 0x7);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num), 5, 3, 0x7);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),16,16, 0x1);
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1fe0 + 4*lane_num),19,19, 0x1);
    }
    return CSL_SERDES_LANE_ENABLE_NO_ERR;
}

static inline void CSL_SerdesSetLoopback
(
 uint32_t base_addr,
 uint32_t lane_num,
 CSL_SERDES_LOOPBACK loopback_mode,
 csl_serdes_phy_type phy_type
)
{    
    if (loopback_mode == CSL_SERDES_LOOPBACK_ENABLED)
    {
        if(phy_type == SERDES_10GE)
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1)),7,0, 0x04);
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1) + 0x04),2,1,3);
        }
        else
        {
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x200*(lane_num+1)),31,24, (uint32_t)0x40);
        }
    }
}

static inline void CSL_SerdesPllEnable
(
 uint32_t base_addr,
 csl_serdes_phy_type phy_type,
 CSL_SERDES_LINK_RATE link_rate
)
{
    if(phy_type == SERDES_10GE)
    {
        CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00), 7, 0, (uint32_t)0x1f);
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1ff4),31,29, (uint32_t)0x7);
    if(phy_type== SERDES_10GE)
    {
        if (link_rate == CSL_SERDES_LINK_RATE_10p3125G)
            CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x1ff4), 27, 25, 0x7 );
    }
}

static inline CSL_SERDES_STATUS CSL_SerdesGetPLLStatus
(
 uint32_t base_addr,
 csl_serdes_phy_type phy_type
)
{
    CSL_SERDES_STATUS retval;
    retval = (CSL_SERDES_STATUS)CSL_FEXTR(*(volatile uint32_t *)(base_addr + 0x1ff4), 28, 28);
    return retval;
}

static inline CSL_SERDES_STATUS CSL_SerdesGetSigDetStatus
(
 uint32_t base_addr,
 uint32_t num_lanes,
 uint8_t lane_mask,
 csl_serdes_phy_type phy_type
)
{
    uint32_t lane_num;
    CSL_SERDES_STATUS retval = CSL_SERDES_STATUS_PLL_LOCKED;
    for (lane_num=0; lane_num < num_lanes; lane_num++)
    {
        if ((lane_mask & (1<<lane_num))!=0)
        {
            retval = (CSL_SERDES_STATUS)(retval & CSL_FEXTR(*(volatile uint32_t *)(base_addr + 0x1ff4), (0 + lane_num), (0 + lane_num)));
        }
    }
    return retval;
}

static inline CSL_SERDES_STATUS CSL_SerdesGetStatus
(
 uint32_t base_addr,
 uint32_t num_lanes,
 uint8_t lane_mask,
 csl_serdes_phy_type phy_type
)
{
    uint32_t lane_num;
    CSL_SERDES_STATUS retval = CSL_SERDES_STATUS_PLL_LOCKED;
    for (lane_num=0; lane_num < num_lanes; lane_num++)
    {
        if ((lane_mask & (1<<lane_num))!=0)
        {
            if(phy_type!= SERDES_PCIe)
            {
                retval = (CSL_SERDES_STATUS)(retval & CSL_FEXTR(*(volatile uint32_t *)(base_addr + 0x1ff4), (8 + lane_num), (8 + lane_num)));
            }
            else
            {
                retval = (CSL_SERDES_STATUS)(retval & CSL_FEXTR(*(volatile uint32_t *)(base_addr + 0x1ff4), (0 + lane_num), (0 + lane_num)));
            }
        }
    }
    return retval;
}

static inline uint32_t CSL_Serdes_EyeMonitorDLLovr(uint32_t base_addr, uint32_t lane_num, uint32_t phase_num, 
                                                     uint32_t t_offset, uint32_t phase_shift, csl_serdes_phy_type phy_type)
{
    uint32_t tbus_data, delay, partial_eye;
    uint32_t eye_scan_errors;
    uint32_t i, error_free = 0, start_bin, end_bin = 0;
    uint32_t eye_scan_errors_array[1][128];
    uint32_t MAX_DLY=128;
    if (t_offset==0) t_offset++;
    if(phase_num == 1) 
    {
        CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x002C, 0xFF3FFFFF, 0x00400000);
        CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x0030, 0xFFFFFFE0, 0x00000011);
    }
    else 
    {
        CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x002C, 0xFF3FFFFF, 0x00800000);
        CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x0030, 0xFFFFFFE0, 0x00000009);
    }
    CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x00B8, 0xFFFF00FF, 0x00004000);
    if(phase_num == 1) 
    {
        CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x00B8, 0x0000FFFF, 0xFFEF0000);
    } 
    else 
    {
        CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x00B8, 0x0000FFFF, 0xFFF60000);
    }
    CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x00BC, 0xFFF00000, 0x000FFFFF);
    tbus_data = CSL_SerdesReadSelectedTbus(base_addr,lane_num+1,0x02);
    tbus_data = tbus_data;
    CSL_Serdes_CycleDelay(300000);
    for (i = 0; i < MAX_DLY; i=i+t_offset)
    {
        CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x002C, 0x00FFFFFF, (i & 0x0ff) << 24);
        CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x0030, 0xFFFFFFFC, phase_shift);
        CSL_Serdes_CycleDelay(5000);
        CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x00B8, 0xFFFF00FF, 0x0000C000);
        CSL_Serdes_CycleDelay(500000);
        eye_scan_errors  = (CSL_SerdesReadSelectedTbus(base_addr,lane_num+1,((phy_type!=SERDES_10GE))?0x1A:0x19) << 4);
        eye_scan_errors |= ((CSL_SerdesReadSelectedTbus(base_addr,lane_num+1,((phy_type!=SERDES_10GE))?0x1B:0x1A) & 0x0F00) >> 8);
        eye_scan_errors_array[0][i] = eye_scan_errors;
        CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x00B8, 0xFFFF00FF, 0x00004000);
    }
    partial_eye = 0;
    error_free = 0;
    for (i = 0; i < MAX_DLY; i=i+t_offset)
    {
        if (i == 0) 
        {
            if (eye_scan_errors_array[0][i] < 16384) 
            {
                partial_eye = 1;
            }
        } 
        else 
        {
            if (eye_scan_errors_array[0][i] > 16384+3000) 
            {
                partial_eye = 0;
            }
        }
        if ((eye_scan_errors_array[0][i] < 16384) && (partial_eye == 0) && (error_free == 0)) {
            if (!((eye_scan_errors_array[0][i-1] > 16384) && (eye_scan_errors_array[0][i+1] > 16384))){
            error_free = 1;
            start_bin = i;
        } 
        } else if ((eye_scan_errors_array[0][i] > 16384) && (partial_eye == 0) && (error_free == 1)) {
            if (!((eye_scan_errors_array[0][i-1] < 16384) && (eye_scan_errors_array[0][i+1] < 16384))){
            end_bin = i;
            break;
        }
    }
    }
    delay = (end_bin - start_bin)/4+start_bin;
      CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x0030, 0xFFFFFF00, 0x00000000);
      CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x002C, 0xFFFFFF00, 0x00000003);
      CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x0098, 0xFEFFFFFF, 0x00000000);
      CSL_Serdes_Write_32_Mask(base_addr+0x0a00+0x00B8, 0xFFFF3FFF, 0x00000000);
      CSL_Serdes_Write_32_Mask(base_addr+0x200*(lane_num+1)+0x002C, 0xFF3FFFFF, 0x00000000);
      return delay;
}
static inline uint32_t CSL_Serdes_Set_DLEV_patt_adapt(uint32_t base_addr, uint32_t lane_num, uint32_t pattern,CSL_SERDES_TAP_OFFSETS_T *pTapOffsets, csl_serdes_phy_type phy_type)
{
    uint32_t DLEVP_TEMP,DLEVN_TEMP,DLEVAVG_TEMP;
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x158),14,8, pattern);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x98),14,14, 1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x98),14,14, 0);
    CSL_SerdesWaitForRXValidPerLane(base_addr, lane_num, phy_type);
    DLEVP_TEMP = (CSL_SerdesReadSelectedTbus(base_addr,lane_num + 1,0x44) & 0x0ff0) >>4;
    DLEVN_TEMP = (CSL_SerdesReadSelectedTbus(base_addr,lane_num + 1,0x45) & 0x0ff);
    if (pTapOffsets->cmp_offsets[lane_num][4] <= 120)
    {
        DLEVAVG_TEMP = pTapOffsets->cmp_offsets[lane_num][4]-DLEVN_TEMP;
    }
    else if (pTapOffsets->cmp_offsets[lane_num][4] >= 134)
    {
        DLEVAVG_TEMP = DLEVP_TEMP-pTapOffsets->cmp_offsets[lane_num][4];
    }
    else
    {
        DLEVAVG_TEMP = (DLEVP_TEMP-DLEVN_TEMP)/2;
    }
    return DLEVAVG_TEMP;
}
static inline void CSL_Serdes_RX_Calibration_PHYB(uint32_t base_addr,
                                           uint32_t lane_num,
                                           csl_serdes_phy_type phy_type,
                                           CSL_SERDES_TAP_OFFSETS_T *pTapOffsets,
                                           CSL_SERDES_DLEV_OUT_T *pDLEVOut)
{
    uint32_t iAtt,iBoost,comp_no, att_start,boost_start;
    uint32_t delay_ovr = 0;
    int32_t DLEVAVG_TEMP[6];
    pDLEVOut->delay[lane_num] = delay_ovr = CSL_Serdes_EyeMonitorDLLovr(base_addr, lane_num, 0, 1, 0, phy_type);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x164),15,15, 1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x164),16,16, 1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x164),31,26, (128+delay_ovr) & 0x3F);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + 0xa00 + 0x168),2,0, (128+delay_ovr)>>6);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x9c),1,1, 0);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x9c),0,0, 0);
    att_start =((*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x8c) >>8) & 0xF);
    boost_start =((*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x8c) >>12) & 0xF);
    iAtt=iBoost= CSL_SerdesReadSelectedTbus(base_addr,lane_num + 1,0x10);
    iAtt   = (iAtt   >> 4) & 0x0f;
    iBoost = (iBoost >> 8) & 0x0f;
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x8c),11,8, iAtt);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x8c),15,12, iBoost);
    DLEVAVG_TEMP[0] = CSL_Serdes_Set_DLEV_patt_adapt(base_addr,lane_num, 0x71, pTapOffsets, phy_type);
    DLEVAVG_TEMP[1] = CSL_Serdes_Set_DLEV_patt_adapt(base_addr,lane_num, 0x61, pTapOffsets, phy_type);
    DLEVAVG_TEMP[2] = CSL_Serdes_Set_DLEV_patt_adapt(base_addr,lane_num, 0x79, pTapOffsets, phy_type);
    DLEVAVG_TEMP[3] = CSL_Serdes_Set_DLEV_patt_adapt(base_addr,lane_num, 0x75, pTapOffsets, phy_type);
    DLEVAVG_TEMP[4] = CSL_Serdes_Set_DLEV_patt_adapt(base_addr,lane_num, 0x73, pTapOffsets, phy_type);
    DLEVAVG_TEMP[5] = CSL_Serdes_Set_DLEV_patt_adapt(base_addr,lane_num, 0x70, pTapOffsets, phy_type);
    pDLEVOut->tap_values[lane_num][0]  = (DLEVAVG_TEMP[0]-DLEVAVG_TEMP[1])/2;
    pDLEVOut->tap_values[lane_num][1]  = (DLEVAVG_TEMP[0]-DLEVAVG_TEMP[2])/-2;
    pDLEVOut->tap_values[lane_num][2]  = (DLEVAVG_TEMP[0]-DLEVAVG_TEMP[3])/-2;
    pDLEVOut->tap_values[lane_num][3]  = (DLEVAVG_TEMP[0]-DLEVAVG_TEMP[4])/-2;
    pDLEVOut->tap_values[lane_num][4]  = (DLEVAVG_TEMP[0]-DLEVAVG_TEMP[5])/2;
    pDLEVOut->tap_values[lane_num][0] = pDLEVOut->tap_values[lane_num][0] - pDLEVOut->tap_values[lane_num][0]/3;
    for(comp_no=1;comp_no<5;comp_no++) 
    {
        if((comp_no==1)||(comp_no==3))
        {
            pTapOffsets->tap1_offsets_tmp[lane_num][comp_no] = pDLEVOut->tap_values[lane_num][0] + pTapOffsets->tap1_offsets[lane_num][comp_no];
            pTapOffsets->tap2_offsets_tmp[lane_num][comp_no] = pDLEVOut->tap_values[lane_num][1] + pTapOffsets->tap2_offsets[lane_num][comp_no];
            pTapOffsets->tap3_offsets_tmp[lane_num][comp_no] = pDLEVOut->tap_values[lane_num][2] + pTapOffsets->tap3_offsets[lane_num][comp_no];
            pTapOffsets->tap4_offsets_tmp[lane_num][comp_no] = pDLEVOut->tap_values[lane_num][3] + pTapOffsets->tap4_offsets[lane_num][comp_no];
            pTapOffsets->tap5_offsets_tmp[lane_num][comp_no] = pDLEVOut->tap_values[lane_num][4] + pTapOffsets->tap5_offsets[lane_num][comp_no];
        }
        else
        {
            pTapOffsets->tap1_offsets_tmp[lane_num][comp_no] = pTapOffsets->tap1_offsets[lane_num][comp_no];
            pTapOffsets->tap2_offsets_tmp[lane_num][comp_no] = pTapOffsets->tap2_offsets[lane_num][comp_no];
            pTapOffsets->tap3_offsets_tmp[lane_num][comp_no] = pTapOffsets->tap3_offsets[lane_num][comp_no];
            pTapOffsets->tap4_offsets_tmp[lane_num][comp_no] = pTapOffsets->tap4_offsets[lane_num][comp_no];
            pTapOffsets->tap5_offsets_tmp[lane_num][comp_no] = pTapOffsets->tap5_offsets[lane_num][comp_no];
        }
        CSL_Serdes_Write_Offsets_RX_Calibration(base_addr, lane_num,comp_no, pTapOffsets);
    }
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x8c),11,8, att_start);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x8c),15,12, boost_start);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x9c),1,1, 1);
    CSL_FINSR(*(volatile uint32_t *)(base_addr + (lane_num*0x200) + 0x200 + 0x9c),0,0, 1);
}

static inline int32_t CSL_Serdes_Check_Link_Status
(
    uint32_t serdes_base_addr,
    uint32_t peripheral_base_addr,
    uint32_t num_lanes,
    uint32_t lane_mask,
    CSL_SERDES_LINK_STAT_T *link_stat
)
{
    int32_t loss, blk_lock, lane_num, status, blk_errs, pcsr_rx_stat;
    status=1;
    for(lane_num=0; lane_num<CSL_SERDES_MAX_LANES; lane_num++)
    {
        if ((lane_mask & (1<<lane_num))!=0)
        {
        loss = (*(volatile uint32_t *)(serdes_base_addr + 0x1fc0 + 0x20 + (lane_num*4)) & 0xF);
        pcsr_rx_stat = (*(volatile uint32_t *)(peripheral_base_addr + 0xc + (lane_num*0x80)));
        blk_lock = (pcsr_rx_stat >> 30) & 0x1;                              
        blk_errs = (pcsr_rx_stat >> 16) & 0x0ff;
        if (blk_errs)
        {
            blk_lock=0;
        }
        switch(link_stat->current_state[lane_num])
        {
        case 0:                                            
               if ( !loss && blk_lock)
               {
                   CSL_FINSR(*(volatile uint32_t *)(serdes_base_addr + 0x200*(lane_num+1) + 0x04),2,1,0);
                   link_stat->current_state[lane_num]=1;
               }
               else
               {
                   if (!blk_lock)
                   {
                       CSL_FINSR(*(volatile uint32_t *)(serdes_base_addr + 0x200*(lane_num+1) + 0x04),2,1, 0x2);
                       CSL_Serdes_CycleDelay(10000);
                       CSL_FINSR(*(volatile uint32_t *)(serdes_base_addr + 0x200*(lane_num+1) + 0x04),2,1, 0x0);
                   }
               }
               break;
        case 1: 
               if (!blk_lock)
               {
                   link_stat->lane_down[lane_num] = 1;
                   link_stat->current_state[lane_num]=2;
               }
               break;
        case 2:
               if (blk_lock)
               {
                   link_stat->current_state[lane_num]=1;
               }
               else
               {             
                   CSL_FINSR(*(volatile uint32_t *)(serdes_base_addr + 0x200*(lane_num+1) + 0x04),2,1, 0x2);
                   CSL_Serdes_CycleDelay(10000);
                   CSL_FINSR(*(volatile uint32_t *)(serdes_base_addr + 0x200*(lane_num+1) + 0x04),2,1, 0x0);
                   link_stat->current_state[lane_num]=0;
               }
               break;
        }
    if (blk_errs)
    {
        CSL_FINSR(*(volatile uint32_t *)(peripheral_base_addr + 0x08 + (lane_num * 0x80)),7,0, 0x19);
        CSL_FINSR(*(volatile uint32_t *)(peripheral_base_addr + 0x08 + (lane_num * 0x80)),7,0, 0x00);
    }
    status &= (link_stat->current_state[lane_num] == 1);
        }
   }
    return status;
}

static inline void CSL_SerdesHS_Init_Config(const CSL_SERDES_LANE_ENABLE_PARAMS_T
		                              *serdes_lane_enable_params)
{
    uint32_t lane_num;
    if(serdes_lane_enable_params->phy_type != SERDES_10GE)
    {
        if (serdes_lane_enable_params->linkrate >= CSL_SERDES_LINK_RATE_9p8304G)
        {
            CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0xA00 + 0xbc),28,24,0x1e);
        }
    }
    for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
    {
        if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
        {
            CSL_SerdesSetTXIdle(serdes_lane_enable_params->base_addr, lane_num, serdes_lane_enable_params->phy_type);
        }
    }
    if (serdes_lane_enable_params->linkrate >= CSL_SERDES_LINK_RATE_9p8304G)
    {
	if(serdes_lane_enable_params->phy_type != SERDES_10GE)
        {
            CSL_Serdes_Force_Signal_Detect_Low(serdes_lane_enable_params->base_addr,
                                               serdes_lane_enable_params->num_lanes,
                                               serdes_lane_enable_params->lane_mask);
            if(serdes_lane_enable_params->linkrate >= CSL_SERDES_LINK_RATE_9p8304G)
            {
                for(lane_num=0; lane_num<serdes_lane_enable_params->num_lanes; lane_num++)
                {
                    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x78),30,24, 0x7F);
                }
            }
        }
	else
        {
            CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0xA00 + 0x10C),7,0, 0xFF);
        }
    }
}

static inline void CSL_SerdesPCIe_Lane_Enable(const CSL_SERDES_LANE_ENABLE_PARAMS_T
                                                *serdes_lane_enable_params)
{
    uint32_t lane_num;
#if 0
    CSL_SERDES_STATUS pllstat;
#endif
    for(lane_num=0;lane_num<serdes_lane_enable_params->num_lanes;lane_num++)
    {
        CSL_SerdesSetLoopback(serdes_lane_enable_params->base_addr,
                              lane_num,
                              serdes_lane_enable_params->loopback_mode[lane_num],
                              serdes_lane_enable_params->phy_type);
    }
    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->peripheral_base_addr + 0x180C), 9, 8, serdes_lane_enable_params->num_lanes);
    for(lane_num=0;lane_num<serdes_lane_enable_params->num_lanes;lane_num++)
    {
        if (serdes_lane_enable_params->lane_ctrl_rate[lane_num] == CSL_SERDES_LANE_FULL_RATE)
        {
            CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->peripheral_base_addr + 0x180C),17,17, 0x1); 
        }
    }
#if 0
    do
    {
        pllstat = CSL_SerdesGetStatus(serdes_lane_enable_params->base_addr,
                                      serdes_lane_enable_params->num_lanes,
                                      serdes_lane_enable_params->lane_mask,
                                      serdes_lane_enable_params->phy_type);
    }while(pllstat == CSL_SERDES_STATUS_PLL_NOT_LOCKED);
#endif
}

static inline CSL_SERDES_LANE_ENABLE_STATUS CSL_SerdesLaneEnable_Lane_Init_RX(
         CSL_SERDES_LANE_ENABLE_PARAMS_T *serdes_lane_enable_params)
{
    uint32_t lane_num;
    CSL_SERDES_LINK_STAT_T link_stat;
    CSL_SERDES_DLEV_OUT_T pDLEVOut;
    CSL_SERDES_LANE_ENABLE_STATUS status = CSL_SERDES_LANE_ENABLE_NO_ERR;
    memset(&link_stat, 0, sizeof(link_stat));
    if(serdes_lane_enable_params->operating_mode == CSL_SERDES_FUNCTIONAL_MODE)
    {
        if(serdes_lane_enable_params->phy_type == SERDES_PCIe)
        {
            return CSL_SERDES_LANE_ENABLE_NO_ERR;
        } 
        for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
        {
            if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
            {
                CSL_Serdes_Force_Signal_Detect_Enable(serdes_lane_enable_params->base_addr, lane_num);
            }
        }
        if(serdes_lane_enable_params->forceattboost == CSL_SERDES_FORCE_ATT_BOOST_DISABLED)
        {
            if(serdes_lane_enable_params->iteration_mode == CSL_SERDES_LANE_ENABLE_LANE_INIT)
            {
                for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
                {
                    if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                    {
                        CSL_SerdesWaitForSigDet(serdes_lane_enable_params->base_addr, lane_num);
                    }
                }
            }
            else if(serdes_lane_enable_params->iteration_mode == CSL_SERDES_LANE_ENABLE_LANE_INIT_NO_WAIT)
            {
                for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
                {
                    if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                    {
                        status = (CSL_SERDES_LANE_ENABLE_STATUS)CSL_SerdesReadSigDet(serdes_lane_enable_params->base_addr, 
                                                                 lane_num);
                        if(!status) 
                        {
                            return CSL_SERDES_LANE_ENABLE_SIG_UNDETECTED;
                        }
                        else 
                        {
                            status = CSL_SERDES_LANE_ENABLE_NO_ERR;
                        }
                    }
                }
            }
            if((serdes_lane_enable_params->phy_type == SERDES_10GE) ||
			    ((serdes_lane_enable_params->linkrate >= CSL_SERDES_LINK_RATE_5G)))
            {
                for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
                {
                    if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                    {
                    	if(serdes_lane_enable_params->lane_ctrl_rate[lane_num]==CSL_SERDES_LANE_FULL_RATE)
                    	{
                    		CSL_SerdesWaitForRXValidPerLane(serdes_lane_enable_params->base_addr, lane_num, serdes_lane_enable_params->phy_type);
                    	}
                    }
                }
            }
            if(serdes_lane_enable_params->phy_type == SERDES_10GE)
            {
                for(lane_num=0; lane_num<CSL_SERDES_MAX_LANES; lane_num++)
                {
                    if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                    {
                        CSL_SerdesRXAttBoostConfig_PhyB(serdes_lane_enable_params->base_addr, lane_num,
                                                    serdes_lane_enable_params->phy_type,
                                                    serdes_lane_enable_params->lane_mask);
                    }
                }
            }
			else if (serdes_lane_enable_params->linkrate >= CSL_SERDES_LINK_RATE_5G)
			{
			    for(lane_num=0; lane_num<CSL_SERDES_MAX_LANES; lane_num++)
			   	{
					if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
					{
					    if(serdes_lane_enable_params->lane_ctrl_rate[lane_num]==CSL_SERDES_LANE_FULL_RATE)
					    {
					    	CSL_SerdesRXBoostConfig_PhyA(serdes_lane_enable_params->base_addr, lane_num,
														serdes_lane_enable_params->phy_type,
														serdes_lane_enable_params->lane_mask);
						}
			    	}
			    }
			}
        }
        if(serdes_lane_enable_params->phy_type == SERDES_10GE)
        {
            for(lane_num=0; lane_num<CSL_SERDES_MAX_LANES; lane_num++)
            {
                if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                {
                	CSL_Serdes_RX_Calibration_PHYB(serdes_lane_enable_params->base_addr, lane_num, serdes_lane_enable_params->phy_type,
                			                       &serdes_lane_enable_params->tapOffsets, &pDLEVOut);
                }
            }
            status = (CSL_SERDES_LANE_ENABLE_STATUS)CSL_Serdes_Check_Link_Status(serdes_lane_enable_params->base_addr,
                                                        serdes_lane_enable_params->peripheral_base_addr,
                                                        CSL_SERDES_MAX_LANES,
                                                        serdes_lane_enable_params->lane_mask,
                                                        &link_stat);
        }
        if(serdes_lane_enable_params->forceattboost == CSL_SERDES_FORCE_ATT_BOOST_DISABLED)
        {
            for(lane_num=0; lane_num<CSL_SERDES_MAX_LANES; lane_num++)
            {
                if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                {
                    CSL_SerdesClearWaitAfterPerLane(serdes_lane_enable_params->base_addr, lane_num);
                }
            }
        }
        else
        {
            CSL_SerdesClearWaitAfter(serdes_lane_enable_params->base_addr);
        }
    } 
    return status;
}

static inline CSL_SERDES_LANE_ENABLE_STATUS CSL_SerdesLaneEnable
(
         CSL_SERDES_LANE_ENABLE_PARAMS_T *serdes_lane_enable_params
)
{
    uint32_t lane_num, term_val;
    CSL_SERDES_STATUS   pllstat;
    CSL_SERDES_LANE_ENABLE_STATUS status = CSL_SERDES_LANE_ENABLE_NO_ERR;
    if(serdes_lane_enable_params->iteration_mode == 0)
    {
        return CSL_SERDES_LANE_ENABLE_ITERATION_MODE_NOT_SET;
    }
    if (serdes_lane_enable_params->phy_type == SERDES_10GE || serdes_lane_enable_params->phy_type == SERDES_PCIe)
    {
        if(serdes_lane_enable_params->peripheral_base_addr == 0)
        {
            return CSL_SERDES_LANE_ENABLE_PERIPHERAL_BASE_NOT_SET;
        }
    }
    if(serdes_lane_enable_params->iteration_mode == CSL_SERDES_LANE_ENABLE_COMMON_INIT)
    {
        if(serdes_lane_enable_params->phy_type == SERDES_PCIe)
        {
            CSL_SerdesPCIe_Lane_Enable(serdes_lane_enable_params);
            return CSL_SERDES_LANE_ENABLE_NO_ERR;
        }
	    CSL_SerdesHS_Init_Config(serdes_lane_enable_params);
        for(lane_num=0; lane_num<CSL_SERDES_MAX_LANES; lane_num++)
        {
            if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
            {
                CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x8c),11,8,
                                                 serdes_lane_enable_params->rx_coeff.att_start[lane_num]);
                CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x8c),15,12,
                                                 serdes_lane_enable_params->rx_coeff.boost_start[lane_num]);
                CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x84),27,24,
                                                 serdes_lane_enable_params->rx_coeff.att_start[lane_num]);
                CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x84),31,28,
                                                 serdes_lane_enable_params->rx_coeff.boost_start[lane_num]);
                CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x84),19,16,
                                                 serdes_lane_enable_params->rx_coeff.att_start[lane_num]);
                CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x84),23,20,
                                                 serdes_lane_enable_params->rx_coeff.boost_start[lane_num]);
            }
        }
        if(serdes_lane_enable_params->phy_type == SERDES_HYPERLINK)
        {
            if(serdes_lane_enable_params->operating_mode == CSL_SERDES_FUNCTIONAL_MODE)
            {
                CSL_SerdesSetHyperlinkPattern(serdes_lane_enable_params->base_addr);
            }
        }
        CSL_Serdes_Assert_Reset(serdes_lane_enable_params->base_addr,
                                serdes_lane_enable_params->phy_type,
                                serdes_lane_enable_params->lane_mask);
        for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
        {
            if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
            {
                if (serdes_lane_enable_params->phy_type == SERDES_10GE)
                {
                    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x04),29,26,
                                                     serdes_lane_enable_params->tx_coeff.tx_att[lane_num]);
                }
                else
                {
                    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x04),28,25,
                                                     serdes_lane_enable_params->tx_coeff.tx_att[lane_num]);
                }
                if (serdes_lane_enable_params->phy_type == SERDES_10GE)
                {
                    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0xa4),2,0,
                                                     serdes_lane_enable_params->tx_coeff.tx_vreg[lane_num]);
                }
                else
                {
                    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x84),7,5,
                                                     serdes_lane_enable_params->tx_coeff.tx_vreg[lane_num]);
                }
                CSL_SERDES_CONFIG_CM_C1_C2(serdes_lane_enable_params->base_addr, lane_num,
                                           serdes_lane_enable_params->tx_coeff.cm_coeff[lane_num],
                                           serdes_lane_enable_params->tx_coeff.c1_coeff[lane_num],
                                           serdes_lane_enable_params->tx_coeff.c2_coeff[lane_num],
                                           serdes_lane_enable_params->phy_type);
                if(serdes_lane_enable_params->forceattboost)
                {
                    CSL_SERDES_CONFIG_ATT_BOOST(serdes_lane_enable_params->base_addr, lane_num,
                                                serdes_lane_enable_params->rx_coeff.force_att_val[lane_num],
                                                serdes_lane_enable_params->rx_coeff.force_boost_val[lane_num],
                                                serdes_lane_enable_params->phy_type);
                }
            }
        }
        CSL_Serdes_Force_Signal_Detect_Low(serdes_lane_enable_params->base_addr,
                                           CSL_SERDES_MAX_LANES,
                                           serdes_lane_enable_params->lane_mask);
        status = (CSL_SERDES_LANE_ENABLE_STATUS)CSL_Serdes_Deassert_Reset(serdes_lane_enable_params->base_addr,
                                                                          serdes_lane_enable_params->phy_type, 0,
                                                                          CSL_SERDES_MAX_LANES,
                                                                          serdes_lane_enable_params->lane_mask);
        for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
        {
            if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
            {
                status = (CSL_SERDES_LANE_ENABLE_STATUS)(status | (CSL_SerdesSetLaneRate(serdes_lane_enable_params->base_addr, lane_num,
                                      serdes_lane_enable_params->lane_ctrl_rate[lane_num],
                                      serdes_lane_enable_params->linkrate,
                                      serdes_lane_enable_params->phy_type)));
            }
        }
        for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
        {
            if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
            {
                CSL_SerdesSetLoopback(serdes_lane_enable_params->base_addr, lane_num, serdes_lane_enable_params->loopback_mode[lane_num], serdes_lane_enable_params->phy_type);
            }
        }
        if (serdes_lane_enable_params->phy_type != SERDES_10GE)
        {
            for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
            {
                if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                {
                    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x30),11,11,0x1);
                    CSL_FINSR(*(volatile uint32_t *)(serdes_lane_enable_params->base_addr + 0x200*(lane_num+1) + 0x30),13,12,0x0);
                }
            }
        }
        CSL_SerdesPllEnable(serdes_lane_enable_params->base_addr,serdes_lane_enable_params->phy_type,serdes_lane_enable_params->linkrate);
        do
        {
            pllstat = CSL_SerdesGetPLLStatus(serdes_lane_enable_params->base_addr,
                                             serdes_lane_enable_params->phy_type);
        }while(pllstat == CSL_SERDES_STATUS_PLL_NOT_LOCKED);
        for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
        {
            if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
            {
                CSL_Serdes_Lane_Enable(serdes_lane_enable_params->base_addr, lane_num);
            }
        }
        do
        {
            pllstat = CSL_SerdesGetStatus(serdes_lane_enable_params->base_addr,
                                          CSL_SERDES_MAX_LANES,
                                          serdes_lane_enable_params->lane_mask,
                                          serdes_lane_enable_params->phy_type);
        }while(pllstat == CSL_SERDES_STATUS_PLL_NOT_LOCKED);
        CSL_Serdes_CycleDelay(5000);
        term_val = CSL_SerdesGetTXTermValues(serdes_lane_enable_params->base_addr,
                                  serdes_lane_enable_params->phy_type);
        CSL_SerdesSetTXTermValue(serdes_lane_enable_params->base_addr,
                                 CSL_SERDES_MAX_LANES,
                                 term_val);
        if(serdes_lane_enable_params->operating_mode == CSL_SERDES_FUNCTIONAL_MODE)
        {
            if(serdes_lane_enable_params->phy_type == SERDES_10GE)
            {
                CSL_Serdes_PHYB_Init_Config(serdes_lane_enable_params->base_addr,
                                                 CSL_SERDES_MAX_LANES,
                                                 serdes_lane_enable_params->phy_type,
                                                 serdes_lane_enable_params->lane_mask,
                                                 &serdes_lane_enable_params->tapOffsets);
            }
            if(serdes_lane_enable_params->phy_type != SERDES_10GE)
            {
                if (serdes_lane_enable_params->linkrate >= CSL_SERDES_LINK_RATE_9p8304G)
                {
                    for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
                    {
                        if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                        {
                            CSL_Serdes_PHYA_Init_Config(serdes_lane_enable_params->base_addr, lane_num);
                        }
                    }
                }
            }
            for(lane_num=0;lane_num<CSL_SERDES_MAX_LANES;lane_num++)
            {
                if ((serdes_lane_enable_params->lane_mask & (1<<lane_num))!=0)
                {
                    CSL_SerdesClearTXIdle(serdes_lane_enable_params->base_addr, lane_num,
                                          serdes_lane_enable_params->phy_type);
                }
            }
        }
    } 
    else
    {
        status = CSL_SerdesLaneEnable_Lane_Init_RX(serdes_lane_enable_params);
    }
    return status;
}
#ifdef __cplusplus
}
#endif
#endif
/* @} */

