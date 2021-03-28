/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_CKGEN_PRM_H
#define CSLR_CKGEN_PRM_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 CM_CLKSEL_SYSCLK1_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 CM_CLKSEL_WKUPAON_REG;
    volatile Uint32 CM_CLKSEL_ABE_PLL_REF_REG;
    volatile Uint32 CM_CLKSEL_SYS_REG;
    volatile Uint32 CM_CLKSEL_ABE_PLL_BYPAS_REG;
    volatile Uint32 CM_CLKSEL_ABE_PLL_SYS_REG;
    volatile Uint32 CM_CLKSEL_ABE_24M_REG;
    volatile Uint32 CM_CLKSEL_ABE_SYS_REG;
    volatile Uint32 CM_CLKSEL_HDMI_MCASP_AUX_REG;
    volatile Uint32 CM_CLKSEL_HDMI_TIMER_REG;
    volatile Uint32 CM_CLKSEL_MCASP_SYS_REG;
    volatile Uint32 CM_CLKSEL_MLBP_MCASP_REG;
    volatile Uint32 CM_CLKSEL_MLB_MCASP_REG;
    volatile Uint32 CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 CM_CLKSEL_SYS_CLK1_32K_REG;
    volatile Uint32 CM_CLKSEL_TIMER_SYS_REG;
    volatile Uint32 CM_CLKSEL_VIDEO1_MCASP_AUX_REG;
    volatile Uint32 CM_CLKSEL_VIDEO1_TIMER_REG;
    volatile Uint32 CM_CLKSEL_VIDEO2_MCASP_AUX_REG;
    volatile Uint32 CM_CLKSEL_VIDEO2_TIMER_REG;
    volatile Uint32 CM_CLKSEL_CLKOUTMUX0_REG;
    volatile Uint32 CM_CLKSEL_CLKOUTMUX1_REG;
    volatile Uint32 CM_CLKSEL_CLKOUTMUX2_REG;
    volatile Uint32 CM_CLKSEL_HDMI_PLL_SYS_REG;
    volatile Uint32 CM_CLKSEL_VIDEO1_PLL_SYS_REG;
    volatile Uint32 CM_CLKSEL_VIDEO2_PLL_SYS_REG;
    volatile Uint32 CM_CLKSEL_ABE_CLK_DIV_REG;
    volatile Uint32 CM_CLKSEL_ABE_GICLK_DIV_REG;
    volatile Uint32 CM_CLKSEL_AESS_FCLK_DIV_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 CM_CLKSEL_EVE_CLK_REG;
    volatile Uint32 CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG;
    volatile Uint32 CM_CLKSEL_ABE_LP_CLK_REG;
    volatile Uint32 CM_CLKSEL_ADC_GFCLK_REG;
    volatile Uint32 CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG;
} CSL_ckgen_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Select the SYS CLK for SYSCLK1_32K_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG                     (0x0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYSCLK1       (CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG)


/* Control the functional clock source of WKUPAON, PRM and Smart Reflex 
 * functional clock. */
#define CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG                     (0x8U)
/* Below define for backward compatibility */
#define CM_CLKSEL_WKUPAON       (CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG)


/* Control the source of the reference clock for DPLL_ABE */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG                 (0xCU)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_REF   (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG)


/* Software sets the SYS_CLK configuration corresponding to the frequency of 
 * SYS_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG                         (0x10U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS           (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG)


/* Control the source of the bypass clock for DPLL_ABE */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG               (0x14U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_BYPAS  (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG)


/* Control the source of the SYS clock for DPLL_ABE */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG                 (0x18U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_SYS   (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG)


/* Select the ABE_24M_FCLK for TIMERS subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG                     (0x1CU)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_24M       (CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG)


/* Select the SYS CLK for IPU subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG                     (0x20U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SYS       (CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG)


/* Select the HDMI_CLK for MCASP subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG              (0x24U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG)


/* Select the HDMI_CLK for TIMER subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG                  (0x28U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER    (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG)


/* Select the SYS CLK for ABE_24M_FCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG                   (0x2CU)
/* Below define for backward compatibility */
#define CM_CLKSEL_MCASP_SYS     (CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG)


/* Select the MLBP_CLK for MCASP subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG                  (0x30U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP    (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG)


/* Select the MLB_CLK for MCASP subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG                   (0x34U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP     (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG)


/* Select the PER_ABE_X1_GFCLK_CLK for MCASP subsystems. [warm reset 
 * insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG  (0x38U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG)


/* Control the source of the SYS clock for GPIO, WD _TIMER,KBD. */
#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG                (0x40U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_32K  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG)


/* Select the SYS CLK for TIMERS subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG                   (0x44U)
/* Below define for backward compatibility */
#define CM_CLKSEL_TIMER_SYS     (CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG)


/* Select the VIDEO1_CLK for MCASP subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG            (0x48U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG)


/* Select the VIDEO1_CLK for TIMER subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG                (0x4CU)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG)


/* Select the VIDEO2_CLK for MCASP subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG            (0x50U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG)


/* Select the VIDEO2_CLK for TIMER subsystems. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG                (0x54U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG)


/* Control the source of the CLKOUTMUX0 */
#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG                  (0x58U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0    (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG)


/* Control the source of the CLKOUTMUX1 */
#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG                  (0x5CU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1    (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG)


/* Control the source of the CLKOUTMUX2 */
#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG                  (0x60U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2    (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG)


/* Control the source of the SYS clock for DPLL_HDMI */
#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG                (0x64U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_PLL_SYS  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG)


/* Control the source of the SYS clock for DPLL_VIDEO1 */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG              (0x68U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_PLL_SYS  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG)


/* Control the source of the SYS clock for DPLL_VIDEO1 */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG              (0x6CU)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_PLL_SYS  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG)


/* Select the ABE_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG                 (0x70U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV   (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG)


/* Select the ABE_GICLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG               (0x74U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_GICLK_DIV  (CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG)


/* Select the AESS_FCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG               (0x78U)
/* Below define for backward compatibility */
#define CM_CLKSEL_AESS_FCLK_DIV  (CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG)


/* Control the source of the EVE_CLK for EVE1, EVE2, EVE3, EVE4 */
#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG                     (0x80U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_CLK       (CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG)


/* Select the USB_OTG_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG       (0x84U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG)


/* Select the CORE_DPLL_OUT_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG  (0x88U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG)


/* Select the DSP_GFCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG         (0x8CU)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG)


/* Select the EMIF_PHY_GCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG     (0x90U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG)


/* Select the EMU_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG           (0x94U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG)


/* Select the FUNC_96M_AON_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG  (0x98U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG)


/* Select the GMAC_250M_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG     (0x9CU)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG)


/* Select the GPU_GCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG          (0xA0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG)


/* Select the HDMI_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG          (0xA4U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG)


/* Select the IVA_GCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG          (0xA8U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG)


/* Select the L3INIT_480M_GFCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG  (0xACU)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG)


/* Select the MPU_GCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG          (0xB0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG)


/* Select the PCIE1_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG         (0xB4U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG)


/* Select the PCIE2_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG         (0xB8U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG)


/* Select the PER_ABE_X1_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG    (0xBCU)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG)


/* Select the SATA_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG          (0xC0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG)


/* Select the SECURE_32K_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG    (0xC4U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG)


/* Select the SYS_CLK1. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG          (0xC8U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG)


/* Select the SYS_CLK2. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG          (0xCCU)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG)


/* Select the VIDEO1_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG        (0xD0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG)


/* Select the VIDEO2_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG        (0xD4U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG)


/* Select the ABE_LP_CLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG                  (0xD8U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_LP_CLK    (CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG)


/* Control the source of the ADC_GFCLK clock for */
#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG                   (0xDCU)
/* Below define for backward compatibility */
#define CM_CLKSEL_ADC_GFCLK     (CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG)


/* Select the EVE_GFCLK. [warm reset insensitive] */
#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG         (0xE0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_CLKSEL_SYSCLK1_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_MASK         (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYSCLK1_CLKSEL_MASK                 (CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_RESETVAL     (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_SHIFT        (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYSCLK1_CLKSEL_SHIFT                (CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_SYSCLK_DIV_6  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYSCLK1_CLKSEL_SYSCLK_DIV_6         (CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_SYSCLK_DIV_6)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_SYSCLK_DIV_10  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYSCLK1_CLKSEL_SYSCLK_DIV_10        (CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_CLKSEL_SYSCLK_DIV_10)


#define CSL_CKGEN_PRM_CM_CLKSEL_SYSCLK1_REG_RESETVAL            (0x00000000U)

/* CM_CLKSEL_WKUPAON_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_MASK         (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_WKUPAON_CLKSEL_MASK                 (CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_RESETVAL     (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_SHIFT        (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_WKUPAON_CLKSEL_SHIFT                (CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_SEL_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_WKUPAON_CLKSEL_SEL_SYS_CLK          (CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_SEL_SYS_CLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_SEL_ABE_X1_LP_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_WKUPAON_CLKSEL_SEL_ABE_X1_LP_CLK    (CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_CLKSEL_SEL_ABE_X1_LP_CLK)


#define CSL_CKGEN_PRM_CM_CLKSEL_WKUPAON_REG_RESETVAL            (0x00000000U)

/* CM_CLKSEL_ABE_PLL_REF_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_MASK     (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_REF_CLKSEL_MASK             (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_SHIFT    (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_REF_CLKSEL_SHIFT            (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_SEL_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_REF_CLKSEL_SEL_SYS_CLK      (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_SEL_SYS_CLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_SEL_SYS_32K  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_REF_CLKSEL_SEL_SYS_32K      (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_CLKSEL_SEL_SYS_32K)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_REF_REG_RESETVAL        (0x00000000U)

/* CM_CLKSEL_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_MASK         (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL_MASK                 (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_RESETVAL     (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_SHIFT        (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL_SHIFT                (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_UNSET        (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL_UNSET                (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_UNSET)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__12_MHZ      (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL__12_MHZ              (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__12_MHZ)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_RESERVED     (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL_RESERVED             (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__16_8_MHZ    (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL__16_8_MHZ            (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__16_8_MHZ)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__19_2_MHZ    (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL__19_2_MHZ            (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__19_2_MHZ)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__26_MHZ      (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL__26_MHZ              (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__26_MHZ)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_RESERVED1    (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL_RESERVED1            (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__38_4_MHZ    (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_SYS_CLKSEL__38_4_MHZ            (CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_SYS_CLKSEL__38_4_MHZ)


#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_REG_RESETVAL                (0x00000000U)

/* CM_CLKSEL_ABE_PLL_BYPAS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_BYPAS_CLKSEL_MASK           (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_BYPAS_CLKSEL_SHIFT          (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_SEL_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_BYPAS_CLKSEL_SEL_SYS_CLK    (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_SEL_SYS_CLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_SEL_ABE_X1_LP_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_BYPAS_CLKSEL_SEL_ABE_X1_LP_CLK  (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_CLKSEL_SEL_ABE_X1_LP_CLK)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_BYPAS_REG_RESETVAL      (0x00000000U)

/* CM_CLKSEL_ABE_PLL_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_MASK     (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_SYS_CLKSEL_MASK             (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_SHIFT    (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_SYS_CLKSEL_SHIFT            (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_SYS_CLKSEL_SEL_SYS_CLK1     (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PLL_SYS_CLKSEL_SEL_SYS_CLK2     (CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_PLL_SYS_REG_RESETVAL        (0x00000000U)

/* CM_CLKSEL_ABE_24M_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_MASK         (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_24M_CLKSEL_MASK                 (CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_RESETVAL     (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_SHIFT        (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_24M_CLKSEL_SHIFT                (CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_SYSCLK_DIV_8  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_24M_CLKSEL_SYSCLK_DIV_8         (CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_SYSCLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_SYSCLK_DIV_16  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_24M_CLKSEL_SYSCLK_DIV_16        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_CLKSEL_SYSCLK_DIV_16)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_24M_REG_RESETVAL            (0x00000000U)

/* CM_CLKSEL_ABE_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_MASK         (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SYS_CLKSEL_MASK                 (CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_RESETVAL     (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_SHIFT        (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SYS_CLKSEL_SHIFT                (CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_SYSCLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SYS_CLKSEL_SYSCLK_DIV_1         (CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_SYSCLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_SYSCLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SYS_CLKSEL_SYSCLK_DIV_2         (CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_CLKSEL_SYSCLK_DIV_2)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_SYS_REG_RESETVAL            (0x00000000U)

/* CM_CLKSEL_HDMI_MCASP_AUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_MASK          (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_SHIFT         (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_CLK_DIV_1     (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_CLK_DIV_2     (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_CLK_DIV_4     (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_CLK_DIV_8     (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_CLK_DIV_16    (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_RESERVED  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_RESERVED      (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_RESERVED1  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_RESERVED1     (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_RESERVED2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_MCASP_AUX_CLKSEL_RESERVED2     (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_CLKSEL_RESERVED2)


#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_MCASP_AUX_REG_RESETVAL     (0x00000000U)

/* CM_CLKSEL_HDMI_TIMER_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_MASK      (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_MASK              (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_SHIFT     (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_SHIFT             (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_CLK_DIV_1         (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_CLK_DIV_2         (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_CLK_DIV_4         (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_CLK_DIV_8         (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_CLK_DIV_16        (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_22  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_CLK_DIV_22        (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_22)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_32  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_CLK_DIV_32        (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_RESERVED  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_TIMER_CLKSEL_RESERVED          (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_CLKSEL_RESERVED)


#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_TIMER_REG_RESETVAL         (0x00000000U)

/* CM_CLKSEL_MCASP_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_MASK       (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MCASP_SYS_CLKSEL_MASK               (CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_RESETVAL   (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_SHIFT      (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MCASP_SYS_CLKSEL_SHIFT              (CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_SYSCLK_DIV_8  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MCASP_SYS_CLKSEL_SYSCLK_DIV_8       (CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_SYSCLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_SYSCLK_DIV_16  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MCASP_SYS_CLKSEL_SYSCLK_DIV_16      (CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_CLKSEL_SYSCLK_DIV_16)


#define CSL_CKGEN_PRM_CM_CLKSEL_MCASP_SYS_REG_RESETVAL          (0x00000000U)

/* CM_CLKSEL_MLBP_MCASP_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_MASK      (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_MASK              (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_SHIFT     (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_SHIFT             (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_CLK_DIV_1         (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_CLK_DIV_2         (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_CLK_DIV_4         (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_CLK_DIV_8         (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_CLK_DIV_16        (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_RESERVED  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_RESERVED          (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_RESERVED1  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_RESERVED1         (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_RESERVED2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLBP_MCASP_CLKSEL_RESERVED2         (CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_CLKSEL_RESERVED2)


#define CSL_CKGEN_PRM_CM_CLKSEL_MLBP_MCASP_REG_RESETVAL         (0x00000000U)

/* CM_CLKSEL_MLB_MCASP_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_MASK       (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_MASK               (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_RESETVAL   (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_SHIFT      (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_SHIFT              (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_CLK_DIV_1          (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_CLK_DIV_2          (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_CLK_DIV_4          (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_CLK_DIV_8          (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_CLK_DIV_16         (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_RESERVED   (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_RESERVED           (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_RESEREVD1  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_RESEREVD1          (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_RESEREVD1)

#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_RESERVED2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MLB_MCASP_CLKSEL_RESERVED2          (CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_CLKSEL_RESERVED2)


#define CSL_CKGEN_PRM_CM_CLKSEL_MLB_MCASP_REG_RESETVAL          (0x00000000U)

/* CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_RESERVED  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_RESERVED1  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_RESERVED2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_CLKSEL_RESERVED2  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_CLKSEL_RESERVED2)


#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_GFCLK_MCASP_AUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_SYS_CLK1_32K_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_MASK    (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_32K_CLKSEL_MASK            (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_SHIFT   (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_32K_CLKSEL_SHIFT           (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_32K_CLKSEL_SEL_SYS_CLK1    (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_SEL_SYS_CLK32K  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_32K_CLKSEL_SEL_SYS_CLK32K  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_CLKSEL_SEL_SYS_CLK32K)


#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_32K_REG_RESETVAL       (0x00000000U)

/* CM_CLKSEL_TIMER_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_MASK       (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_TIMER_SYS_CLKSEL_MASK               (CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_RESETVAL   (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_SHIFT      (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_TIMER_SYS_CLKSEL_SHIFT              (CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_SYSCLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_TIMER_SYS_CLKSEL_SYSCLK_DIV_1       (CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_SYSCLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_SYSCLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_TIMER_SYS_CLKSEL_SYSCLK_DIV_2       (CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_CLKSEL_SYSCLK_DIV_2)


#define CSL_CKGEN_PRM_CM_CLKSEL_TIMER_SYS_REG_RESETVAL          (0x00000000U)

/* CM_CLKSEL_VIDEO1_MCASP_AUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_MASK        (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_SHIFT       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_CLK_DIV_1   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_CLK_DIV_2   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_CLK_DIV_4   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_CLK_DIV_8   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_RESERVED  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_RESERVED    (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_RESERVED1  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_RESERVED1   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_RESERVED2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_MCASP_AUX_CLKSEL_RESERVED2   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_CLKSEL_RESERVED2)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_MCASP_AUX_REG_RESETVAL   (0x00000000U)

/* CM_CLKSEL_VIDEO1_TIMER_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_MASK    (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_MASK            (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_SHIFT   (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_SHIFT           (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_CLK_DIV_1       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_CLK_DIV_2       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_CLK_DIV_4       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_CLK_DIV_8       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_CLK_DIV_16      (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_22  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_CLK_DIV_22      (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_22)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_32  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_CLK_DIV_32      (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_RESERVED  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_TIMER_CLKSEL_RESERVED        (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_CLKSEL_RESERVED)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_TIMER_REG_RESETVAL       (0x00000000U)

/* CM_CLKSEL_VIDEO2_MCASP_AUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_MASK        (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_SHIFT       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_CLK_DIV_1   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_CLK_DIV_2   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_CLK_DIV_4   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_CLK_DIV_8   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_RESERVED  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_RESERVED    (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_RESERVED1  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_RESERVED1   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_RESERVED2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_MCASP_AUX_CLKSEL_RESERVED2   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_CLKSEL_RESERVED2)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_MCASP_AUX_REG_RESETVAL   (0x00000000U)

/* CM_CLKSEL_VIDEO2_TIMER_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_MASK    (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_MASK            (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_SHIFT   (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_SHIFT           (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_CLK_DIV_1       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_CLK_DIV_2       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_CLK_DIV_4       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_CLK_DIV_8       (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_CLK_DIV_16      (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_22  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_CLK_DIV_22      (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_22)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_32  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_CLK_DIV_32      (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_RESERVED  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_TIMER_CLKSEL_RESERVED        (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_CLKSEL_RESERVED)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_TIMER_REG_RESETVAL       (0x00000000U)

/* CM_CLKSEL_CLKOUTMUX0_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_MASK      (0x0000001FU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_MASK              (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SHIFT     (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SHIFT             (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_SYS_CLK1      (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_SYS_CLK2      (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_ABE_CLKOUT  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_ABE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_ABE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_MPU_CLKOUT  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_MPU_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_MPU_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_DSP_CLKOUT  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_DSP_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_DSP_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_IVA_CLKOUT  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_IVA_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_IVA_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_GPU_CLKOUT  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_GPU_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_GPU_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_CORE_CLKOUT  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_CORE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_CORE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_DDR_CLKOUT  (0x00000008U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_DDR_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_DDR_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_GMAC_CLKOUT  (0x00000009U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_GMAC_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_GMAC_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_VIDEO2_CLKOUT  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_VIDEO2_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_VIDEO2_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_VIDEO1_CLKOUT  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_VIDEO1_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_VIDEO1_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_HDMI_CLKOUT  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_HDMI_CLKOUT   (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_HDMI_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_PER_CLKOUT  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_PER_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_PER_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_USB_CLKOUT  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_USB_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_USB_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_SATA_CLKOUT  (0x00000010U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_SATA_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_SATA_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_PCIE2_CLKOUT  (0x00000011U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_PCIE2_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_PCIE2_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_PCIE1_CLKOUT  (0x00000012U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_PCIE1_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_PCIE1_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_DEBUG_CLKOUT  (0x00000013U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_DEBUG_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_DEBUG_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_RC_CLK  (0x00000014U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_RC_CLK        (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_RC_CLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_EVE_CLKOUT  (0x00000015U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_SEL_DPLL_EVE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_SEL_DPLL_EVE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED  (0x00000016U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED          (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED1  (0x00000017U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED1         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED2  (0x00000018U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED2         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED2)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED3  (0x00000019U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED3         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED3)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED4  (0x0000001aU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED4         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED4)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED5  (0x0000001bU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED5         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED5)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED6  (0x0000001cU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED6         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED6)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED7  (0x0000001dU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED7         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED7)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED8  (0x0000001eU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED8         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED8)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED9  (0x0000001fU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX0_CLKSEL_RESERVED9         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_CLKSEL_RESERVED9)


#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX0_REG_RESETVAL         (0x00000000U)

/* CM_CLKSEL_CLKOUTMUX1_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_MASK      (0x0000001FU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_MASK              (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SHIFT     (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SHIFT             (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_SYS_CLK1      (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_SYS_CLK2      (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_ABE_CLKOUT  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_ABE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_ABE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_MPU_CLKOUT  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_MPU_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_MPU_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_DSP_CLKOUT  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_DSP_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_DSP_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_IVA_CLKOUT  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_IVA_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_IVA_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_GPU_CLKOUT  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_GPU_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_GPU_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_CORE_CLKOUT  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_CORE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_CORE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_DDR_CLKOUT  (0x00000008U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_DDR_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_DDR_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_GMAC_CLKOUT  (0x00000009U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_GMAC_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_GMAC_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_VIDEO2_CLKOUT  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_VIDEO2_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_VIDEO2_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_VIDEO1_CLKOUT  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_VIDEO1_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_VIDEO1_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_HDMI_CLKOUT  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_HDMI_CLKOUT   (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_HDMI_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_PER_CLKOUT  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_PER_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_PER_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_USB_CLKOUT  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_USB_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_USB_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_SATA_CLKOUT  (0x00000010U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_SATA_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_SATA_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_PCIE2_CLKOUT  (0x00000011U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_PCIE2_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_PCIE2_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_PCIE1_CLKOUT  (0x00000012U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_PCIE1_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_PCIE1_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_DEBUG_CLKOUT  (0x00000013U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_DEBUG_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_DEBUG_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_RC_CLK  (0x00000014U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_RC_CLK        (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_RC_CLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_EVE_CLKOUT  (0x00000015U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_SEL_DPLL_EVE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_SEL_DPLL_EVE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED  (0x00000016U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED          (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED1  (0x00000017U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED1         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED2  (0x00000018U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED2         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED2)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED3  (0x00000019U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED3         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED3)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED4  (0x0000001aU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED4         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED4)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED5  (0x0000001bU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED5         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED5)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED6  (0x0000001cU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED6         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED6)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED7  (0x0000001dU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED7         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED7)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED8  (0x0000001eU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED8         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED8)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED9  (0x0000001fU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX1_CLKSEL_RESERVED9         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_CLKSEL_RESERVED9)


#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX1_REG_RESETVAL         (0x00000000U)

/* CM_CLKSEL_CLKOUTMUX2_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_MASK      (0x0000001FU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_MASK              (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SHIFT     (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SHIFT             (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_SYS_CLK1      (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_SYS_CLK2      (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_ABE_CLKOUT  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_ABE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_ABE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_MPU_CLKOUT  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_MPU_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_MPU_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_DSP_CLKOUT  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_DSP_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_DSP_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_IVA_CLKOUT  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_IVA_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_IVA_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_GPU_CLKOUT  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_GPU_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_GPU_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_CORE_CLKOUT  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_CORE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_CORE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_DDR_CLKOUT  (0x00000008U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_DDR_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_DDR_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_GMAC_CLKOUT  (0x00000009U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_GMAC_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_GMAC_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_VIDEO2_CLKOUT  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_VIDEO2_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_VIDEO2_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_VIDEO1_CLKOUT  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_VIDEO1_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_VIDEO1_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_HDMI_CLKOUT  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_HDMI_CLKOUT   (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_HDMI_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_PER_CLKOUT  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_PER_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_PER_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_USB_CLKOUT  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_USB_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_USB_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_USB_OTG_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_SATA_CLKOUT  (0x00000010U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_SATA_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_SATA_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_PCIE2_CLKOUT  (0x00000011U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_PCIE2_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_PCIE2_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_PCIE1_CLKOUT  (0x00000012U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_PCIE1_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_PCIE1_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_DEBUG_CLKOUT  (0x00000013U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_DEBUG_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_DEBUG_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_RC_CLK  (0x00000014U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_RC_CLK        (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_RC_CLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_EVE_CLKOUT  (0x00000015U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_SEL_DPLL_EVE_CLKOUT  (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_SEL_DPLL_EVE_CLKOUT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED  (0x00000016U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED          (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED1  (0x00000017U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED1         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED2  (0x00000018U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED2         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED2)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED3  (0x00000019U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED3         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED3)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED4  (0x0000001aU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED4         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED4)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED5  (0x0000001bU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED5         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED5)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED6  (0x0000001cU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED6         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED6)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED7  (0x0000001dU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED7         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED7)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED8  (0x0000001eU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED8         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED8)

#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED9  (0x0000001fU)
/* Below define for backward compatibility */
#define CM_CLKSEL_CLKOUTMUX2_CLKSEL_RESERVED9         (CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_CLKSEL_RESERVED9)


#define CSL_CKGEN_PRM_CM_CLKSEL_CLKOUTMUX2_REG_RESETVAL         (0x00000000U)

/* CM_CLKSEL_HDMI_PLL_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_MASK    (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_PLL_SYS_CLKSEL_MASK            (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_SHIFT   (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_PLL_SYS_CLKSEL_SHIFT           (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_PLL_SYS_CLKSEL_SEL_SYS_CLK1    (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_PLL_SYS_CLKSEL_SEL_SYS_CLK2    (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2)


#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_PLL_SYS_REG_RESETVAL       (0x00000000U)

/* CM_CLKSEL_VIDEO1_PLL_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_PLL_SYS_CLKSEL_MASK          (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_PLL_SYS_CLKSEL_SHIFT         (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_PLL_SYS_CLKSEL_SEL_SYS_CLK1  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_PLL_SYS_CLKSEL_SEL_SYS_CLK2  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_PLL_SYS_REG_RESETVAL     (0x00000000U)

/* CM_CLKSEL_VIDEO2_PLL_SYS_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_PLL_SYS_CLKSEL_MASK          (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_PLL_SYS_CLKSEL_SHIFT         (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_PLL_SYS_CLKSEL_SEL_SYS_CLK1  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_PLL_SYS_CLKSEL_SEL_SYS_CLK2  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_CLKSEL_SEL_SYS_CLK2)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_PLL_SYS_REG_RESETVAL     (0x00000000U)

/* CM_CLKSEL_ABE_CLK_DIV_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_MASK     (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_MASK             (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_SHIFT    (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_SHIFT            (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_CLK_DIV_1        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_CLK_DIV_2        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_CLK_DIV_4        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_CLK_DIV_8        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_CLK_DIV_16       (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_RESERVED  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_RESERVED         (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_RESERVED1  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_RESERVED1        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_RESERVED1)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_RESERVED2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLK_DIV_CLKSEL_RESERVED2        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_CLKSEL_RESERVED2)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_CLK_DIV_REG_RESETVAL        (0x00000000U)

/* CM_CLKSEL_ABE_GICLK_DIV_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_GICLK_DIV_CLKSEL_MASK           (CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_GICLK_DIV_CLKSEL_SHIFT          (CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_GICLK_DIV_CLKSEL_CLK_DIV_1      (CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_GICLK_DIV_CLKSEL_CLK_DIV_2      (CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_CLKSEL_CLK_DIV_2)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_GICLK_DIV_REG_RESETVAL      (0x00000000U)

/* CM_CLKSEL_AESS_FCLK_DIV_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_AESS_FCLK_DIV_CLKSEL_MASK           (CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_AESS_FCLK_DIV_CLKSEL_SHIFT          (CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_AESS_FCLK_DIV_CLKSEL_CLK_DIV_1      (CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_AESS_FCLK_DIV_CLKSEL_CLK_DIV_2      (CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_CLKSEL_CLK_DIV_2)


#define CSL_CKGEN_PRM_CM_CLKSEL_AESS_FCLK_DIV_REG_RESETVAL      (0x00000000U)

/* CM_CLKSEL_EVE_CLK_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_MASK         (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_CLK_CLKSEL_MASK                 (CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_RESETVAL     (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_SHIFT        (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_CLK_CLKSEL_SHIFT                (CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_SEL_EVE_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_CLK_CLKSEL_SEL_EVE_GFCLK        (CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_SEL_EVE_GFCLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_SEL_EVE_GCLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_CLK_CLKSEL_SEL_EVE_GCLK         (CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_CLKSEL_SEL_EVE_GCLK)


#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_CLK_REG_RESETVAL            (0x00000000U)

/* CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_MASK   (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_USB_OTG_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_CORE_DPLL_OUT_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_MASK     (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_SHIFT    (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_DSP_GFCLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_EMIF_PHY_GCLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_MASK       (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_SHIFT      (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_RESERVED   (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EMU_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_EMU_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_FUNC_96M_AON_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_GMAC_250M_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_MASK      (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_SHIFT     (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_GPU_GCLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_GPU_GCLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_MASK      (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_SHIFT     (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_HDMI_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_HDMI_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_MASK      (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_SHIFT     (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_IVA_GCLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_IVA_GCLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_L3INIT_480M_GFCLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_MASK      (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_SHIFT     (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_MPU_GCLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_MPU_GCLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_MASK     (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_SHIFT    (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE1_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_MASK     (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_SHIFT    (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_PCIE2_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_PER_ABE_X1_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_MASK      (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_SHIFT     (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SATA_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_SATA_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_MASK  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_SHIFT  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_SECURE_32K_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_MASK      (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_SHIFT     (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK1_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK1_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_MASK      (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_SHIFT     (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_SYS_CLK2_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_SYS_CLK2_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_MASK    (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_SHIFT   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO1_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_MASK    (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_SHIFT   (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_VIDEO2_CLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

/* CM_CLKSEL_ABE_LP_CLK_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_MASK      (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_LP_CLK_CLKSEL_MASK              (CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_SHIFT     (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_LP_CLK_CLKSEL_SHIFT             (CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_CLK_DIV_16  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_LP_CLK_CLKSEL_CLK_DIV_16        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_CLK_DIV_32  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_LP_CLK_CLKSEL_CLK_DIV_32        (CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_CLKSEL_CLK_DIV_32)


#define CSL_CKGEN_PRM_CM_CLKSEL_ABE_LP_CLK_REG_RESETVAL         (0x00000000U)

/* CM_CLKSEL_ADC_GFCLK_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_MASK       (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ADC_GFCLK_CLKSEL_MASK               (CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_RESETVAL   (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SHIFT      (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ADC_GFCLK_CLKSEL_SHIFT              (CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SEL_SYS_CLK1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ADC_GFCLK_CLKSEL_SEL_SYS_CLK1       (CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SEL_SYS_CLK1)

#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SEL_SYS_CLK2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ADC_GFCLK_CLKSEL_SEL_SYS_CLK2       (CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ADC_GFCLK_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_RESERVED   (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_ADC_GFCLK_CLKSEL_RESERVED           (CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_CLKSEL_RESERVED)


#define CSL_CKGEN_PRM_CM_CLKSEL_ADC_GFCLK_REG_RESETVAL          (0x00000000U)

/* CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG */

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_MASK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_MASK     (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_MASK)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_SHIFT    (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_1  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_1)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_2  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_2)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_4  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_4)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_8  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_8)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16  (0x00000004U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_16  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_16)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32  (0x00000005U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_CLK_DIV_32  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_CLK_DIV_32)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED  (0x00000006U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_RESERVED  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED)

#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1  (0x00000007U)
/* Below define for backward compatibility */
#define CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_CLKSEL_RESERVED1  (CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_CLKSEL_RESERVED1)


#define CSL_CKGEN_PRM_CM_CLKSEL_EVE_GFCLK_CLKOUTMUX_REG_RESETVAL  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
