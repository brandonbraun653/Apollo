/**
 *  \file   MMCSD_soc.c
 *
 *  \brief  AM572x SoC specific MMCSD hardware attributes.
 *
 *   This file contains the hardware attributes of MMCSD peripheral like
 *   base address, interrupt number etc.
 */

/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdint.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>


#define CSL_EDMA3_CHA_MMC1_RX    61
#define CSL_EDMA3_CHA_MMC1_TX    60
#define CSL_EDMA3_CHA_MMC2_RX    47
#define CSL_EDMA3_CHA_MMC2_TX    46
#define CSL_EDMA3_CHA_MMC3_RX    52
#define CSL_EDMA3_CHA_MMC3_TX    53
#define CSL_EDMA3_CHA_MMC4_RX    57
#define CSL_EDMA3_CHA_MMC4_TX    56

extern MMCSD_Error MMCSD_iodelayFxn (uint32_t instanceNum,
                              MMCSD_v1_IodelayParams *iodelayParams);

extern uint32_t MMCSD_inputClockControl(uint32_t instNum, uint32_t *clock_freq_req_ptr,MMCSD_inputClkCtrlMode_e mode);

/* MMCSD configuration structure */
MMCSD_v1_HwAttrs MMCSDInitCfg[MMCSD_CNT] =
{
    {
        1,
#ifdef _TMS320C6X
        CSL_DSP_MMC1_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
		75,/* DSP1_IRQ_75 is available to use, hence using it */
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_MMC1_REGS,
        115, /* Corresponds to MPU_IRQ_83 (32 + MPU_IRQ_83) */
		0,  /* Event ID is not used by A15 */
#else
        CSL_IPU_MMC1_REGS,
        66, /* Corresponds to IPU1_IRQ_66 */
		0,
#endif
        96000000U,
        400000U,
        MMCSD_CARD_SD,
        (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT),
		(MMCSD_BUS_VOLTAGE_1_8V | MMCSD_BUS_VOLTAGE_3_0V),
        1,
        0,
        &MMCSD_iodelayFxn,
		NULL,
		MMCSD_inputClockControl,
        1,  /*Enable DMA by default */
        CSL_EDMA3_CHA_MMC1_RX,
        CSL_EDMA3_CHA_MMC1_TX,
        0U,
        0U,
        0U,
        0U,
        0U,
        NULL,
#ifdef _TMS320C6X
		MUXINTCP_CROSSBAR_MUXNUM_DSP1, /* Crossbar default DSP1 */
        CSL_XBAR_MMC1_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_DSP1_IRQ_75 /* Crossbar Instance number for DSP_IRQ75 */
#elif defined(__TI_ARM_V7M4__)
		MUXINTCP_CROSSBAR_MUXNUM_IPU1, /* Crossbar default for IPU1 */
        CSL_XBAR_MMC1_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_IPU1_IRQ_66  /* Cross bar instance number for IRQ66 used in eventNum */ 
#else
		MUXINTCP_CROSSBAR_MUXNUM_MPU, /* Crossbar default for MPU */
        CSL_XBAR_MMC1_IRQ,/* Crossbar mux in */
		CSL_XBAR_INST_MPU_IRQ_83 /* Cross bar instance number for IRQ83 used in eventNum */ 
#endif	
    },
    {
        2,
#ifdef _TMS320C6X
        CSL_DSP_MMC2_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
		76,/* DSP1_IRQ_76 is available to use, hence using it */
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_MMC2_REGS,
        118, /* Corresponds to MPU_IRQ_86 (32 + MPU_IRQ_86) */
		0,
#else
        CSL_IPU_MMC2_REGS,
        67,/* Corresponds to IPU1_IRQ_67 */
		0,
#endif
		96000000U,
        400000U,
        MMCSD_CARD_EMMC,
        MMCSD_BUS_WIDTH_8BIT,
  	    (MMCSD_BUS_VOLTAGE_3_0V),
        1,
        0,
        &MMCSD_iodelayFxn,
		NULL,
		MMCSD_inputClockControl,
        1,  /*Enable DMA by default */
        CSL_EDMA3_CHA_MMC2_RX,
        CSL_EDMA3_CHA_MMC2_TX,
        0U,
        0U,
        0U,
        0U,
        0U,
		NULL,
#ifdef _TMS320C6X
		MUXINTCP_CROSSBAR_MUXNUM_DSP1, /* Crossbar default DSP1 */
        CSL_XBAR_MMC2_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_DSP1_IRQ_76 /* Crossbar Instance number for DSP_IRQ76 used in eventNum  */
#elif defined(__TI_ARM_V7M4__)
		MUXINTCP_CROSSBAR_MUXNUM_IPU1, /* Crossbar default for IPU1 */
        CSL_XBAR_MMC2_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_IPU1_IRQ_67  /* Cross bar instance number for IRQ67 used in eventNum */ 
#else
		MUXINTCP_CROSSBAR_MUXNUM_MPU, /* Crossbar default for MPU */
        CSL_XBAR_MMC2_IRQ,/* Crossbar mux in */
		CSL_XBAR_INST_MPU_IRQ_84 /* Cross bar instance number for IRQ84 used in eventNum */ 
#endif	
		
    },
    {
        3,
#ifdef _TMS320C6X
        CSL_DSP_MMC3_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
        77,/* DSP1_IRQ_77 is available to use, hence using it */
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_MMC3_REGS,
        126, /* Corresponds to MPU_IRQ_94 (32 + MPU_IRQ_94) */
		0,
#else
        CSL_IPU_MMC3_REGS,
        68,/* Corresponds to IPU1_IRQ_68 */
		0,
#endif
		96000000U,
        400000U,
        MMCSD_CARD_SD,
        (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT),
 	    (MMCSD_BUS_VOLTAGE_1_8V | MMCSD_BUS_VOLTAGE_3_0V),
        1,
        0,
        &MMCSD_iodelayFxn,
		NULL,
		MMCSD_inputClockControl,
        1,  /*Enable DMA by default */
        CSL_EDMA3_CHA_MMC3_RX,
        CSL_EDMA3_CHA_MMC3_TX,
        0U,
        0U,
        0U,
        0U,
        0U,
		NULL,
#ifdef _TMS320C6X
		MUXINTCP_CROSSBAR_MUXNUM_DSP1, /* Crossbar default DSP1 */
        CSL_XBAR_MMC3_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_DSP1_IRQ_77 /* Crossbar Instance number for DSP_IRQ77 used in eventNum */
#elif defined(__TI_ARM_V7M4__)
		MUXINTCP_CROSSBAR_MUXNUM_IPU1, /* Crossbar default for IPU1 */
        CSL_XBAR_MMC3_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_IPU1_IRQ_68  /* Cross bar instance number for IRQ68 used in eventNum */ 
#else
		MUXINTCP_CROSSBAR_MUXNUM_MPU, /* Crossbar default for MPU */
        CSL_XBAR_MMC3_IRQ,/* Crossbar mux in */
		CSL_XBAR_INST_MPU_IRQ_94 /* Cross bar instance number for IRQ94 used in eventNum */ 
#endif	
		
    },
    {
        4,
#ifdef _TMS320C6X
        CSL_DSP_MMC4_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
        78,/* DSP1_IRQ_78 is available to use, hence using it */
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_MMC4_REGS,
        128,/* Corresponds to MPU_IRQ_96 (32 + MPU_IRQ_96) */
		0,
#else
        CSL_IPU_MMC4_REGS,
        69,/* Corresponds to IPU1_IRQ_69 */
		0,
#endif
		96000000U,
        400000U,
        MMCSD_CARD_SD,
        (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT),
 	    (MMCSD_BUS_VOLTAGE_1_8V | MMCSD_BUS_VOLTAGE_3_0V),
        1,
        0,
        &MMCSD_iodelayFxn,
		NULL,
		MMCSD_inputClockControl,
        1,  /*Enable DMA by default */
        CSL_EDMA3_CHA_MMC4_RX,
        CSL_EDMA3_CHA_MMC4_TX,
        0U,
        0U,
        0U,
        0U,
        0U,
		NULL,
#ifdef _TMS320C6X
		MUXINTCP_CROSSBAR_MUXNUM_DSP1, /* Crossbar default DSP1 */
        CSL_XBAR_MMC4_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_DSP1_IRQ_78 /* Crossbar Instance number for DSP_IRQ78 used in eventNum */
#elif defined(__TI_ARM_V7M4__)
		MUXINTCP_CROSSBAR_MUXNUM_IPU1, /* Crossbar default for IPU1 */
        CSL_XBAR_MMC4_IRQ, /* Crossbar mux in */
		CSL_XBAR_INST_IPU1_IRQ_69  /* Cross bar instance number for IRQ69 used in eventNum */ 
#else
		MUXINTCP_CROSSBAR_MUXNUM_MPU, /* Crossbar default for MPU */
        CSL_XBAR_MMC4_IRQ,/* Crossbar mux in */
		CSL_XBAR_INST_MPU_IRQ_96 /* Cross bar instance number for IRQ96 used in eventNum */ 
#endif	
    }
};


/* MMCSD objects */
MMCSD_v1_Object MMCSDObjects[MMCSD_CNT];


/* MMC configuration structure */
const MMCSD_Config_list MMCSD_config = {
    {
        &MMCSD_v1_FxnTable,
        &MMCSDObjects[0],
        &MMCSDInitCfg[0]
    },

    {
        &MMCSD_v1_FxnTable,
        &MMCSDObjects[1],
        &MMCSDInitCfg[1]
    },

    {
        &MMCSD_v1_FxnTable,
        &MMCSDObjects[2],
        &MMCSDInitCfg[2]
    },

    {
        &MMCSD_v1_FxnTable,
        &MMCSDObjects[3],
        &MMCSDInitCfg[3]
    },

    {NULL, NULL, NULL}
};

/* This function converts the local L2 address to a global address and
*  will be used for DMA transactions which need a global addresses.
*/
uint32_t MMCSD_soc_l2_global_addr (uint32_t addr)
{
    if ((addr >= 0x800000) && (addr < 0x1000000))
    {
    #ifdef _TMS320C6X
        uint32_t coreNum;

        /* Get the core number. */
        coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

        /* Compute the global address. */
        return ((1 << 30) | (coreNum << 24) | (addr & 0x00ffffff));
    #else
        return addr;
    #endif
    }
    else
    {
       /* non-L2 address range */
       return addr;
    }
}


/* This function reads/controls the input functional clock which is provided to the MMC controllers by the system.
 * This function has two modes:-
 * MMCSD_INPUT_CLOCK_CTRL_GET: This mode reads the system's CLKCTRL registers and returns the
 *                             input functional clock to the MMC instance. The input argument clk_freq_req_ptr is set to NULL
 *                             This is typically used during the initialization MMCSD_open() to find the actual input clock
 *                             set by the system and to update the hwAttrs.inputClk accordingly.
 *
 *
 * MMCSD_INPUT_CLOCK_CTRL_GET: In this mode, this function takes an argument(*clk_freq_req_ptr) which
 *                             contains the desired functional clock value provided to MMC. This value is chosen by the driver
 *                             depending upon the speed chosen for a card operation. This function then checks whether
 *                             the functional clock provided by the system is sufficient to satisfy the desired clock (*clk_freq_req_ptr)
 *                             and if not, it changes the system's clock module's CLKCTRL registers to match it.
 *                             For example, during initialization of UHS-1 SD Card, if the driver finds the need to switch to the
 *                             highest speed (192 Mhz), the driver calls this function which changes the input clock
 *
 * RETURN: Returns the functional clock value which drives the MMC. In case of any error, 0 is returned
 */
uint32_t MMCSD_inputClockControl(uint32_t  instNum, uint32_t *clk_freq_req_ptr,MMCSD_inputClkCtrlMode_e mode)
{

  uint32_t curr_clk_div=0,curr_clk_src_bitval=0,curr_clk_src_val=0,curr_clk_output=0;
  uint32_t div_shift=0,clk_div_needed=0,clk_output_needed=0;
  uint32_t clock_freq_req,ret=0;
  Bool clk_change_needed=FALSE;
  /* Find out the existing functional clock values from the system.(_MMC_CLKCTRL)  */
  switch (instNum)
  {
     case 1:
	   curr_clk_div=HW_RD_FIELD32(SOC_L3INIT_CM_CORE_BASE + CM_L3INIT_MMC1_CLKCTRL,CM_L3INIT_MMC1_CLKCTRL_CLKSEL_DIV);
	   curr_clk_src_bitval=HW_RD_FIELD32(SOC_L3INIT_CM_CORE_BASE + CM_L3INIT_MMC1_CLKCTRL,CSL_L3INIT_CM_CORE_CM_L3INIT_MMC2_CLKCTRL_REG_CLKSEL_SOURCE);

	   if(curr_clk_src_bitval==CSL_L3INIT_CM_CORE_CM_L3INIT_MMC1_CLKCTRL_REG_CLKSEL_SOURCE_SEL_128M) {
		  curr_clk_src_val=128000000;/* 128 Mhz clock */
 	   } else if (curr_clk_src_bitval==CSL_L3INIT_CM_CORE_CM_L3INIT_MMC1_CLKCTRL_REG_CLKSEL_SOURCE_SEL_192M) {
		  curr_clk_src_val=192000000;/* 192 Mhz clock */
       }
	   break;
     case 2:
  	   curr_clk_div=HW_RD_FIELD32(SOC_L3INIT_CM_CORE_BASE + CM_L3INIT_MMC2_CLKCTRL,CM_L3INIT_MMC2_CLKCTRL_CLKSEL_DIV);
  	   curr_clk_src_bitval=HW_RD_FIELD32(SOC_L3INIT_CM_CORE_BASE + CM_L3INIT_MMC2_CLKCTRL,CSL_L3INIT_CM_CORE_CM_L3INIT_MMC2_CLKCTRL_REG_CLKSEL_SOURCE);

  	   if(curr_clk_src_bitval==CSL_L3INIT_CM_CORE_CM_L3INIT_MMC2_CLKCTRL_REG_CLKSEL_SOURCE_SEL_128M) {
  		  curr_clk_src_val=128000000;/* 128 Mhz clock */
    	} else if (curr_clk_src_bitval==CSL_L3INIT_CM_CORE_CM_L3INIT_MMC2_CLKCTRL_REG_CLKSEL_SOURCE_SEL_192M) {
  		  curr_clk_src_val=192000000;/* 192 Mhz clock */
        }
        break;

     case 3:
    	curr_clk_div=HW_RD_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC3_CLKCTRL,CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV);
    	curr_clk_src_bitval=HW_RD_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC3_CLKCTRL,CM_L4PER_MMC3_CLKCTRL_CLKSEL_MUX);

       if(curr_clk_src_bitval==CM_L4PER_MMC3_CLKCTRL_CLKSEL_MUX_SEL_FUNC_48M_CLK) {
     	 curr_clk_src_val=48000000;/* 48 Mhz clock */
       } else if (curr_clk_src_bitval==CM_L4PER_MMC3_CLKCTRL_CLKSEL_MUX_SEL_FUNC_192M_CLK) {
    	 curr_clk_src_val=192000000;/* 192 Mhz clock */
       }
       break;

     case 4:
     	curr_clk_div=HW_RD_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC4_CLKCTRL,CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV);
     	curr_clk_src_bitval=HW_RD_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC4_CLKCTRL,CM_L4PER_MMC4_CLKCTRL_CLKSEL_MUX);

        if(curr_clk_src_bitval==CM_L4PER_MMC4_CLKCTRL_CLKSEL_MUX_SEL_FUNC_48M_CLK) {
      	 curr_clk_src_val=48000000;/* 48 Mhz clock */
        } else if (curr_clk_src_bitval==CM_L4PER_MMC4_CLKCTRL_CLKSEL_MUX_SEL_FUNC_192M_CLK) {
     	 curr_clk_src_val=192000000;/* 192 Mhz clock */
        }
        break;

     default:
        break;
   }
   /* Find the clock output of the system, i.e input functional clock to the MMC.
    * For AM57xx. 0 means CLK/1,  DIV=1 means CLK/2, DIV=2 means CLK/4, DIV=3 is RESERVED */
   curr_clk_output=curr_clk_src_val/(1<<curr_clk_div);

   switch(mode)
   {

      case MMCSD_INPUT_CLOCK_CTRL_GET:
        /* Return the default clock input value from the system */
        ret=curr_clk_output;
        break;
      case MMCSD_INPUT_CLOCK_CTRL_SET:

     	  /*Sets the clock input to match the *clock_freq_req */
    	  clk_change_needed=FALSE;
    	  if (clk_freq_req_ptr!=NULL) {
    		  clock_freq_req=*clk_freq_req_ptr;
    	  } else {
    		  break;
    	  }
    	    /* Clock requested is higher than the current value.
    	     * Find the the biggest clock input which satisfies the req clock */
    	   for(div_shift=4;div_shift>0;div_shift--) {
    	      if((curr_clk_src_val/(1<<div_shift)) > clock_freq_req) {
    	       	break;
    	      }
    	  }
    	   clk_div_needed = div_shift;
    	   clk_output_needed = curr_clk_src_val/(1<<clk_div_needed);


           if((clock_freq_req <=curr_clk_output)   || (curr_clk_output == clk_output_needed) ) {
    	      /* Clock already set, nothing to do */
    	      ret=curr_clk_output;
    	      clk_change_needed=FALSE;
            } else {
            	clk_change_needed=TRUE;
            }
            break;
      default:
    	  /* Non supported option */
    	  ret=0;
    	  break;
   }
    /* We do not change clk source here. That depends on the system' configuration. We can
     * only change dividers
     */
    if(clk_change_needed) {
       ret=clk_output_needed;
       switch (instNum)
       {
         case 1:
     	   HW_WR_FIELD32(SOC_L3INIT_CM_CORE_BASE + CM_L3INIT_MMC1_CLKCTRL,CM_L3INIT_MMC1_CLKCTRL_CLKSEL_DIV,clk_div_needed);
           break;
       case 2:
     	   HW_WR_FIELD32(SOC_L3INIT_CM_CORE_BASE + CM_L3INIT_MMC2_CLKCTRL,CM_L3INIT_MMC2_CLKCTRL_CLKSEL_DIV,clk_div_needed);
           break;

       case 3:
     	   HW_WR_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC3_CLKCTRL,CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV,clk_div_needed);
           break;

       case 4:
     	   HW_WR_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC4_CLKCTRL,CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV,clk_div_needed);
           break;

		default:
    	   break;
    }
  }

   return(ret);

}
