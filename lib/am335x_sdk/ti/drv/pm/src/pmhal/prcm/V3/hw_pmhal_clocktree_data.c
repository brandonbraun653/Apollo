/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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

/**
 *  \file      hw_pmhal_clocktree_data.c
 *
 *  \brief     This file contains macros and data-structures pertaining to
 *              StarterWare PMHAL_PRCM clocktree implementation.
 *
 *  \warning   This file is auto generated. So avoid manual changes.
 *              If manual changes are required the implications of the
 *              change in this and other auto generated files has to be
 *              completely understood.
 */

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#include "stdint.h"
#include "stdio.h"
#include "hw_pmhal_clocktree_data.h"
#include "hw_pmhal_data.h"

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

#define VSIZE_TYPE(vec, type) (sizeof (vec) / sizeof (type))

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
 */
pmhalClockTreeProp       PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_prop =
{
    PMHAL_ROOT_CLK,
    NULL
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
 */
pmhalClockTreeProp       PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_prop =
{
    PMHAL_ROOT_CLK,
    NULL
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_ROOT_CLK_TCLKIN
 */
pmhalClockTreeProp       PMHAL_PRCM_ROOT_CLK_TCLKIN_prop =
{
    PMHAL_ROOT_CLK,
    NULL
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_ROOT_CLK_CLK_RC32K
 */
pmhalClockTreeProp       PMHAL_PRCM_ROOT_CLK_CLK_RC32K_prop =
{
    PMHAL_ROOT_CLK,
    NULL
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768
 */
pmhalClockTreeProp       PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768_prop =
{
    PMHAL_ROOT_CLK,
    NULL
};

/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_GFX_FCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_GFX_FCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_GFX_FCLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER7_CLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER7_CLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER7_CLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER2_CLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER2_CLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER2_CLK_MUX - PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER3_CLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER3_CLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER3_CLK_MUX - PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER4_CLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER4_CLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER4_CLK_MUX - PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER5_CLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER5_CLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER5_CLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER6_CLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER6_CLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER6_CLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_LCD_GCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_LCD_GCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_LCD_GCLK_MUX - PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX -
                           PMHAL_PRCM_MUX_MIN]
};

/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};

/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER1_GCLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_TIMER0_GCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER0_GCLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_WDT0_GCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_WDT0_GCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_WDT0_GCLK_MUX -
                           PMHAL_PRCM_MUX_MIN]
};
#endif
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MUX_WDT1_GCLK_MUX
 */
pmhalClockTreeProp       PMHAL_PRCM_MUX_WDT1_GCLK_MUX_prop =
{
    PMHAL_MUX,
    &pmhalMultiplexerElems[PMHAL_PRCM_MUX_WDT1_GCLK_MUX - PMHAL_PRCM_MUX_MIN]
};

/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_GFX_FCLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_GFX_FCLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_GFX_FCLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_EMIF_GCLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_EMIF_GCLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_EMIF_GCLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_CORE_100M
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_CORE_100M_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_CORE_100M - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_UART_CLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_UART_CLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_UART_CLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_MMC_CLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_MMC_CLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_MMC_CLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_CLK_24MHZ
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_CLK_24MHZ_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_CLK_24MHZ - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_CPSW_50MHZ_CLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_CPSW_50MHZ_CLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_CPSW_5MHZ_CLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_CPSW_5MHZ_CLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_CLKOUT2
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_CLKOUT2_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_CLKOUT2 - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_L4_RTC_GCLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_L4_RTC_GCLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_L4_RTC_GCLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_VTP_CLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_VTP_CLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_VTP_CLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_L4_WKUP_GCLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_L4_WKUP_GCLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_L4_WKUP_GCLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_UART0_CLK
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_UART0_CLK_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_UART0_CLK - PMHAL_PRCM_DIV_MIN]
};
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_DIV_SYSCLK1
 */
pmhalClockTreeProp       PMHAL_PRCM_DIV_SYSCLK1_prop =
{
    PMHAL_DIV,
    &pmhalDividerElems[PMHAL_PRCM_DIV_SYSCLK1 - PMHAL_PRCM_DIV_MIN]
};

/**
 *  \brief Structure defining property structures for PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeProp       PMHAL_PRCM_DPLL_PER_prop =
{
    PMHAL_DPLL,
    &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN]
};
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_DPLL_MPU
 */
pmhalClockTreeProp       PMHAL_PRCM_DPLL_MPU_prop =
{
    PMHAL_DPLL,
    &pmhalDpllElems[PMHAL_PRCM_DPLL_MPU - PMHAL_PRCM_DPLL_MIN]
};
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_DPLL_DDR
 */
pmhalClockTreeProp       PMHAL_PRCM_DPLL_DDR_prop =
{
    PMHAL_DPLL,
    &pmhalDpllElems[PMHAL_PRCM_DPLL_DDR - PMHAL_PRCM_DPLL_MIN]
};
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_DPLL_DISP
 */
pmhalClockTreeProp       PMHAL_PRCM_DPLL_DISP_prop =
{
    PMHAL_DPLL,
    &pmhalDpllElems[PMHAL_PRCM_DPLL_DISP - PMHAL_PRCM_DPLL_MIN]
};
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeProp       PMHAL_PRCM_DPLL_CORE_prop =
{
    PMHAL_DPLL,
    &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN]
};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_AES0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_AES0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_AES0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES1
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_AES1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_AES1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_AES1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_CLKDIV32K
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_CLKDIV32K_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_CLKDIV32K -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_CPGMAC0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_CPGMAC0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_CPGMAC0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_DCAN0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_DCAN0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_DCAN0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_DCAN1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_DCAN1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_DCAN1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_DES
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_DES_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_DES -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_DMA4_CRYPTO
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_DMA4_CRYPTO_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_DMA4_CRYPTO -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_ELM
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_ELM_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_ELM -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_EMIF
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_EMIF_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_EMIF -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_EMIF_FW
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_EMIF_FW_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_EMIF_FW -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_EPWMSS0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_EPWMSS0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_EPWMSS0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_EPWMSS1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_EPWMSS1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_EPWMSS1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_EPWMSS2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_EPWMSS2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_EPWMSS2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_GPIO1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPIO1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPIO1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_GPIO2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPIO2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPIO2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_GPIO3
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPIO3_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPIO3 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_GPIO4
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPIO4_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPIO4 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_GPIO5
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPIO5_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPIO5 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_GPIO6
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPIO6_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPIO6 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_GPMC
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPMC_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPMC -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_I2C1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_I2C1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_I2C1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_I2C2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_I2C2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_I2C2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_ICSS
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_ICSS_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_ICSS -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_IEEE5000
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_IEEE5000_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_IEEE5000 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_L3
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_L3_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_L3 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_L3_INSTR
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_L3_INSTR_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_L3_INSTR -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_L4FW
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_L4FW_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_L4FW -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_L4LS
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_L4LS_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_L4LS -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_L4_HS
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_L4_HS_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_L4_HS -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_LCDC
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_LCDC_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_LCDC -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_MAILBOX0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MAILBOX0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MAILBOX0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_MAILBOX1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MAILBOX1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MAILBOX1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_MCASP0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MCASP0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MCASP0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
/**
 *  \brief Structure defining property structures for PMHAL_PRCM_MOD_MCASP1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MCASP1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MCASP1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MCASP2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MCASP2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MCASP2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MLB
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MLB
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MLB_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MLB -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MLB */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MMC0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MMC0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MMC0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MMC1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MMC1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MMC1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MMC2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MMC2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MMC2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MSTR_EXPS
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MSTR_EXPS_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MSTR_EXPS -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_OCMCRAM
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_OCMCRAM_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_OCMCRAM -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCPWP
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_OCPWP
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_OCPWP_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_OCPWP -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCPWP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PCIE
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_PCIE
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_PCIE_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_PCIE -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PCIE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_PKA
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_PKA_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_PKA -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_RNG
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_RNG_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_RNG -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SHA0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SHA0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SHA0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SLV_EXPS
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SLV_EXPS_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SLV_EXPS -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SPARE0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SPARE0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SPARE0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SPARE1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SPARE1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SPARE1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SPI0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SPI0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SPI0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SPI1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SPI1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SPI1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SPI2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SPI2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SPI2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SPI3
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SPI3_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SPI3 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SPINLOCK
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SPINLOCK_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SPINLOCK -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER3
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER3_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER3 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER4
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER4_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER4 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER5
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER5_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER5 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER6
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER6_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER6 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER7
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER7_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER7 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TPCC
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TPCC_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TPCC -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TPTC0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TPTC0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TPTC0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TPTC1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TPTC1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TPTC1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TPTC2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TPTC2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TPTC2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_UART1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_UART1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_UART1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_UART2
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_UART2_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_UART2 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_UART3
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_UART3_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_UART3 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_UART4
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_UART4_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_UART4 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_UART5
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_UART5_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_UART5 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_USB0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_USB0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_USB0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_BITBLT
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_BITBLT_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_BITBLT -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_GFX
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GFX_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GFX -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MMU
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MMU_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MMU -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MMU_CFG
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MMU_CFG_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MMU_CFG -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_ADC_TSC
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_ADC_TSC_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_ADC_TSC -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_CONTROL
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_CONTROL_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_CONTROL -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_DEBUGSS
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_DEBUGSS_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_DEBUGSS -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_GPIO0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_GPIO0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_GPIO0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_I2C0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_I2C0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_I2C0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_L4WKUP
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_L4WKUP_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_L4WKUP -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SMARTREFLEX0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SMARTREFLEX0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SMARTREFLEX0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_SMARTREFLEX1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_SMARTREFLEX1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_SMARTREFLEX1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_TIMER1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_TIMER1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_TIMER1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_UART0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_UART0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_UART0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_WDT0
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_WDT0_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_WDT0 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_WDT1
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_WDT1_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_WDT1 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_WKUP_M3
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_WKUP_M3_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_WKUP_M3 -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_CEFUSE
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_CEFUSE_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_CEFUSE -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_RTCSS
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_RTCSS_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_RTCSS -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_MPU
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_MPU_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_MPU -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE
/**
 *  \brief Structure defining property structures for
 *         PMHAL_PRCM_MOD_EFUSE
 */
pmhalClockTreeProp       PMHAL_PRCM_MOD_EFUSE_prop =
{
    PMHAL_MOD,
    &pmhalModuleElems[PMHAL_PRCM_MOD_EFUSE -
                      (PMHAL_PRCM_MOD_LOWER_BOUND + 1U)]
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE */

/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_GFX_FCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_GFX_FCLK_MUX_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE,
    PMHAL_PRCM_DPLL_PER
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER7_CLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER7_CLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER2_CLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER2_CLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER3_CLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER3_CLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER4_CLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER4_CLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER5_CLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER5_CLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER6_CLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER6_CLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE,
    PMHAL_PRCM_DPLL_CORE
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_LCD_GCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_LCD_GCLK_MUX_inNodes[] = {
    PMHAL_PRCM_DPLL_DISP,
    PMHAL_PRCM_DPLL_CORE,
    PMHAL_PRCM_DPLL_PER
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1,
    PMHAL_PRCM_DPLL_DISP
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768,
    PMHAL_PRCM_DIV_SYSCLK1,
    PMHAL_PRCM_DPLL_DDR,
    PMHAL_PRCM_DPLL_PER,
    PMHAL_PRCM_MUX_LCD_GCLK_MUX
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_CLK_RC32K,
    PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_RC32K,
    PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768
};
#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_TIMER0_GCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
    PMHAL_PRCM_ROOT_CLK_TCLKIN,
    PMHAL_PRCM_ROOT_CLK_CLK_RC32K
};

/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_WDT0_GCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_WDT0_GCLK_MUX_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE,
    PMHAL_PRCM_DIV_L3_ICLK
};
#endif

/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MUX_WDT1_GCLK_MUX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MUX_WDT1_GCLK_MUX_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_CLK_RC32K,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};

/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_GFX_FCLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_GFX_FCLK_inNodes[] = {
    PMHAL_PRCM_MUX_GFX_FCLK_MUX
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_EMIF_GCLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_EMIF_GCLK_inNodes[] = {
    PMHAL_PRCM_DPLL_DDR
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_CORE_100M
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_CORE_100M_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_UART_CLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_UART_CLK_inNodes[] = {
    PMHAL_PRCM_DPLL_PER
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_MMC_CLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_MMC_CLK_inNodes[] = {
    PMHAL_PRCM_DPLL_PER
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_CLK_24MHZ
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_CLK_24MHZ_inNodes[] = {
    PMHAL_PRCM_DIV_UART_CLK
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_CPSW_50MHZ_CLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_CPSW_5MHZ_CLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_inNodes[] = {
    PMHAL_PRCM_DIV_CPSW_50MHZ_CLK
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_CLKOUT2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_CLKOUT2_inNodes[] = {
    PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_L4_RTC_GCLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_L4_RTC_GCLK_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_VTP_CLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_VTP_CLK_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_L4_WKUP_GCLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_L4_WKUP_GCLK_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_UART0_CLK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_UART0_CLK_inNodes[] = {
    PMHAL_PRCM_DPLL_PER
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DIV_SYSCLK1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DIV_SYSCLK1_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE
};

/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DPLL_PER_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DPLL_MPU
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DPLL_MPU_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DPLL_DDR
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DPLL_DDR_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DPLL_DISP
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DPLL_DISP_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeNodeId     PMHAL_PRCM_DPLL_CORE_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_AES0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_AES0_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_AES1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_AES1_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_CLKDIV32K
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_CLKDIV32K_inNodes[] = {
    PMHAL_PRCM_DIV_CLK_24MHZ
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_CPGMAC0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_CPGMAC0_inNodes[] = {
    PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX,
    PMHAL_PRCM_DPLL_CORE,
    PMHAL_PRCM_DIV_CPSW_5MHZ_CLK,
    PMHAL_PRCM_DIV_CPSW_50MHZ_CLK,
    PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_DCAN0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_DCAN0_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_DCAN1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_DCAN1_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_DES
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_DES_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_DMA4_CRYPTO
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_DMA4_CRYPTO_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_ELM
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_ELM_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_EMIF
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_EMIF_inNodes[] = {
    PMHAL_PRCM_DIV_EMIF_GCLK,
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_EMIF_FW
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_EMIF_FW_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_EPWMSS0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_EPWMSS0_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_EPWMSS1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_EPWMSS1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_EPWMSS2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_EPWMSS2_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPIO1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPIO1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPIO2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPIO2_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPIO3
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPIO3_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPIO4
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPIO4_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPIO5
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPIO5_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPIO6
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPIO6_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPMC
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPMC_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_I2C1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_I2C1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_I2C2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_I2C2_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_ICSS
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_ICSS_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1,
    PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX,
    PMHAL_PRCM_DPLL_PER
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_IEEE5000
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_IEEE5000_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_L3
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_L3_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_L3_INSTR
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_L3_INSTR_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_L4FW
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_L4FW_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_L4LS
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_L4LS_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_L4_HS
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_L4_HS_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_LCDC
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_LCDC_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1,
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_MUX_LCD_GCLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MAILBOX0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MAILBOX0_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MAILBOX1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MAILBOX1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MCASP0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MCASP0_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MCASP1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MCASP1_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MCASP2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MCASP2_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MLB
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MLB
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MLB_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MLB */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MMC0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MMC0_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_MMC_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MMC1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MMC1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_MMC_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MMC2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MMC2_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_MMC_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MSTR_EXPS
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MSTR_EXPS_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_OCMCRAM
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_OCMCRAM_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCPWP
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_OCPWP
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_OCPWP_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCPWP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PCIE
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_PCIE
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_PCIE_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PCIE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_PKA
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_PKA_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_RNG
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_RNG_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SHA0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SHA0_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SLV_EXPS
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SLV_EXPS_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SPARE0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SPARE0_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SPARE1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SPARE1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SPI0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SPI0_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SPI1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SPI1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SPI2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SPI2_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SPI3
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SPI3_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SPINLOCK
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SPINLOCK_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER2_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_MUX_TIMER2_CLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER3
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER3_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_MUX_TIMER3_CLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER4
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER4_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_MUX_TIMER4_CLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER5
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER5_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_MUX_TIMER5_CLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER6
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER6_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_MUX_TIMER6_CLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER7
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER7_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_MUX_TIMER7_CLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TPCC
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TPCC_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TPTC0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TPTC0_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TPTC1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TPTC1_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TPTC2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TPTC2_inNodes[] = {
    PMHAL_PRCM_DIV_SYSCLK1
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_UART1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_UART1_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_UART2
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_UART2_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_UART3
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_UART3_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_UART4
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_UART4_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_UART5
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_UART5_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DIV_UART_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_USB0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_USB0_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_DPLL_PER
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_BITBLT
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_BITBLT_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE,
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GFX
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GFX_inNodes[] = {
    PMHAL_PRCM_DIV_GFX_FCLK,
    PMHAL_PRCM_DPLL_CORE
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MMU
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MMU_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MMU_CFG
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MMU_CFG_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_ADC_TSC
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_ADC_TSC_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_CONTROL
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_CONTROL_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_DEBUGSS
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_DEBUGSS_inNodes[] = {
    PMHAL_PRCM_DPLL_CORE,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_GPIO0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_GPIO0_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_I2C0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_I2C0_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_DIV_UART0_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_L4WKUP
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_L4WKUP_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SMARTREFLEX0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SMARTREFLEX0_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_SMARTREFLEX1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_SMARTREFLEX1_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER0_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_MUX_TIMER0_GCLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_TIMER1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_TIMER1_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_UART0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_UART0_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_DIV_UART0_CLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_WDT0
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_WDT0_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_MUX_WDT0_GCLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_WDT1
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_WDT1_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK,
    PMHAL_PRCM_MUX_WDT1_GCLK_MUX
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_WKUP_M3
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_WKUP_M3_inNodes[] = {
    PMHAL_PRCM_DIV_L4_WKUP_GCLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_CEFUSE
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_CEFUSE_inNodes[] = {
    PMHAL_PRCM_DIV_CORE_100M,
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_RTCSS
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_RTCSS_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
    PMHAL_PRCM_DIV_L4_RTC_GCLK
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_MPU
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_MPU_inNodes[] = {
    PMHAL_PRCM_DPLL_MPU
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE
/**
 *  \brief Structure defining InNodes of PMHAL_PRCM_MOD_EFUSE
 */
pmhalClockTreeNodeId     PMHAL_PRCM_MOD_EFUSE_inNodes[] = {
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE */

/**
 *  \brief Structure defining Node List Elements
 */
const pmhalClockTreeNode prcmNodes[] =
{
    {&PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_prop,
     NULL,
     0},
    {&PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_prop,
     NULL,
     0},
    {&PMHAL_PRCM_ROOT_CLK_TCLKIN_prop,
     NULL,
     0},
    {&PMHAL_PRCM_ROOT_CLK_CLK_RC32K_prop,
     NULL,
     0},
    {&PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768_prop,
     NULL,
     0},
    {&PMHAL_PRCM_MUX_GFX_FCLK_MUX_prop,
     PMHAL_PRCM_MUX_GFX_FCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_GFX_FCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_TIMER7_CLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER7_CLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER7_CLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_TIMER2_CLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER2_CLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER2_CLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_TIMER3_CLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER3_CLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER3_CLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_TIMER4_CLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER4_CLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER4_CLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_TIMER5_CLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER5_CLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER5_CLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_TIMER6_CLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER6_CLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER6_CLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_prop,
     PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_LCD_GCLK_MUX_prop,
     PMHAL_PRCM_MUX_LCD_GCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_LCD_GCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_prop,
     PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_prop,
     PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_prop,
     PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
    {&PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_prop,
     PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_MUX_WDT0_GCLK_MUX_prop,
     PMHAL_PRCM_MUX_WDT0_GCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_WDT0_GCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
#endif
    {&PMHAL_PRCM_MUX_WDT1_GCLK_MUX_prop,
     PMHAL_PRCM_MUX_WDT1_GCLK_MUX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MUX_WDT1_GCLK_MUX_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_GFX_FCLK_prop,
     PMHAL_PRCM_DIV_GFX_FCLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_GFX_FCLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_EMIF_GCLK_prop,
     PMHAL_PRCM_DIV_EMIF_GCLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_EMIF_GCLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_CORE_100M_prop,
     PMHAL_PRCM_DIV_CORE_100M_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_CORE_100M_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_UART_CLK_prop,
     PMHAL_PRCM_DIV_UART_CLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_UART_CLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_MMC_CLK_prop,
     PMHAL_PRCM_DIV_MMC_CLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_MMC_CLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_CLK_24MHZ_prop,
     PMHAL_PRCM_DIV_CLK_24MHZ_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_CLK_24MHZ_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_prop,
     PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_prop,
     PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_prop,
     PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_CLKOUT2_prop,
     PMHAL_PRCM_DIV_CLKOUT2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_CLKOUT2_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_L4_RTC_GCLK_prop,
     PMHAL_PRCM_DIV_L4_RTC_GCLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_L4_RTC_GCLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_VTP_CLK_prop,
     PMHAL_PRCM_DIV_VTP_CLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_VTP_CLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_L4_WKUP_GCLK_prop,
     PMHAL_PRCM_DIV_L4_WKUP_GCLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_L4_WKUP_GCLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_UART0_CLK_prop,
     PMHAL_PRCM_DIV_UART0_CLK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_UART0_CLK_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DIV_SYSCLK1_prop,
     PMHAL_PRCM_DIV_SYSCLK1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DIV_SYSCLK1_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DPLL_PER_prop,
     PMHAL_PRCM_DPLL_PER_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_PER_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DPLL_MPU_prop,
     PMHAL_PRCM_DPLL_MPU_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_MPU_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DPLL_DDR_prop,
     PMHAL_PRCM_DPLL_DDR_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_DDR_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DPLL_DISP_prop,
     PMHAL_PRCM_DPLL_DISP_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_DISP_inNodes,
                pmhalClockTreeNodeId)},
    {&PMHAL_PRCM_DPLL_CORE_prop,
     PMHAL_PRCM_DPLL_CORE_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_CORE_inNodes,
                pmhalClockTreeNodeId)},
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
    {&PMHAL_PRCM_MOD_AES0_prop,
     PMHAL_PRCM_MOD_AES0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_AES0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES1
    {&PMHAL_PRCM_MOD_AES1_prop,
     PMHAL_PRCM_MOD_AES1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_AES1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
    {&PMHAL_PRCM_MOD_CLKDIV32K_prop,
     PMHAL_PRCM_MOD_CLKDIV32K_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_CLKDIV32K_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    {&PMHAL_PRCM_MOD_CPGMAC0_prop,
     PMHAL_PRCM_MOD_CPGMAC0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_CPGMAC0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    {&PMHAL_PRCM_MOD_DCAN0_prop,
     PMHAL_PRCM_MOD_DCAN0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DCAN0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    {&PMHAL_PRCM_MOD_DCAN1_prop,
     PMHAL_PRCM_MOD_DCAN1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DCAN1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
    {&PMHAL_PRCM_MOD_DES_prop,
     PMHAL_PRCM_MOD_DES_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DES_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
    {&PMHAL_PRCM_MOD_DMA4_CRYPTO_prop,
     PMHAL_PRCM_MOD_DMA4_CRYPTO_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DMA4_CRYPTO_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    {&PMHAL_PRCM_MOD_ELM_prop,
     PMHAL_PRCM_MOD_ELM_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_ELM_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    {&PMHAL_PRCM_MOD_EMIF_prop,
     PMHAL_PRCM_MOD_EMIF_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_EMIF_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
    {&PMHAL_PRCM_MOD_EMIF_FW_prop,
     PMHAL_PRCM_MOD_EMIF_FW_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_EMIF_FW_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    {&PMHAL_PRCM_MOD_EPWMSS0_prop,
     PMHAL_PRCM_MOD_EPWMSS0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    {&PMHAL_PRCM_MOD_EPWMSS1_prop,
     PMHAL_PRCM_MOD_EPWMSS1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    {&PMHAL_PRCM_MOD_EPWMSS2_prop,
     PMHAL_PRCM_MOD_EPWMSS2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    {&PMHAL_PRCM_MOD_GPIO1_prop,
     PMHAL_PRCM_MOD_GPIO1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    {&PMHAL_PRCM_MOD_GPIO2_prop,
     PMHAL_PRCM_MOD_GPIO2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    {&PMHAL_PRCM_MOD_GPIO3_prop,
     PMHAL_PRCM_MOD_GPIO3_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO3_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    {&PMHAL_PRCM_MOD_GPIO4_prop,
     PMHAL_PRCM_MOD_GPIO4_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO4_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    {&PMHAL_PRCM_MOD_GPIO5_prop,
     PMHAL_PRCM_MOD_GPIO5_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO5_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
    {&PMHAL_PRCM_MOD_GPIO6_prop,
     PMHAL_PRCM_MOD_GPIO6_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO6_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    {&PMHAL_PRCM_MOD_GPMC_prop,
     PMHAL_PRCM_MOD_GPMC_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPMC_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    {&PMHAL_PRCM_MOD_I2C1_prop,
     PMHAL_PRCM_MOD_I2C1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_I2C1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    {&PMHAL_PRCM_MOD_I2C2_prop,
     PMHAL_PRCM_MOD_I2C2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_I2C2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    {&PMHAL_PRCM_MOD_ICSS_prop,
     PMHAL_PRCM_MOD_ICSS_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_ICSS_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
    {&PMHAL_PRCM_MOD_IEEE5000_prop,
     PMHAL_PRCM_MOD_IEEE5000_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_IEEE5000_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    {&PMHAL_PRCM_MOD_L3_prop,
     PMHAL_PRCM_MOD_L3_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_L3_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
    {&PMHAL_PRCM_MOD_L3_INSTR_prop,
     PMHAL_PRCM_MOD_L3_INSTR_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_L3_INSTR_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
    {&PMHAL_PRCM_MOD_L4FW_prop,
     PMHAL_PRCM_MOD_L4FW_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_L4FW_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
    {&PMHAL_PRCM_MOD_L4LS_prop,
     PMHAL_PRCM_MOD_L4LS_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_L4LS_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
    {&PMHAL_PRCM_MOD_L4_HS_prop,
     PMHAL_PRCM_MOD_L4_HS_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_L4_HS_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    {&PMHAL_PRCM_MOD_LCDC_prop,
     PMHAL_PRCM_MOD_LCDC_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_LCDC_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    {&PMHAL_PRCM_MOD_MAILBOX0_prop,
     PMHAL_PRCM_MOD_MAILBOX0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MAILBOX0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1
    {&PMHAL_PRCM_MOD_MAILBOX1_prop,
     PMHAL_PRCM_MOD_MAILBOX1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MAILBOX1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    {&PMHAL_PRCM_MOD_MCASP0_prop,
     PMHAL_PRCM_MOD_MCASP0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    {&PMHAL_PRCM_MOD_MCASP1_prop,
     PMHAL_PRCM_MOD_MCASP1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
    {&PMHAL_PRCM_MOD_MCASP2_prop,
     PMHAL_PRCM_MOD_MCASP2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MLB
    {&PMHAL_PRCM_MOD_MLB_prop,
     PMHAL_PRCM_MOD_MLB_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MLB_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MLB */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    {&PMHAL_PRCM_MOD_MMC0_prop,
     PMHAL_PRCM_MOD_MMC0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMC0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    {&PMHAL_PRCM_MOD_MMC1_prop,
     PMHAL_PRCM_MOD_MMC1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMC1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    {&PMHAL_PRCM_MOD_MMC2_prop,
     PMHAL_PRCM_MOD_MMC2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMC2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
    {&PMHAL_PRCM_MOD_MSTR_EXPS_prop,
     PMHAL_PRCM_MOD_MSTR_EXPS_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MSTR_EXPS_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
    {&PMHAL_PRCM_MOD_OCMCRAM_prop,
     PMHAL_PRCM_MOD_OCMCRAM_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_OCMCRAM_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCPWP
    {&PMHAL_PRCM_MOD_OCPWP_prop,
     PMHAL_PRCM_MOD_OCPWP_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_OCPWP_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCPWP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PCIE
    {&PMHAL_PRCM_MOD_PCIE_prop,
     PMHAL_PRCM_MOD_PCIE_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_PCIE_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PCIE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
    {&PMHAL_PRCM_MOD_PKA_prop,
     PMHAL_PRCM_MOD_PKA_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_PKA_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
    {&PMHAL_PRCM_MOD_RNG_prop,
     PMHAL_PRCM_MOD_RNG_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_RNG_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
    {&PMHAL_PRCM_MOD_SHA0_prop,
     PMHAL_PRCM_MOD_SHA0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SHA0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
    {&PMHAL_PRCM_MOD_SLV_EXPS_prop,
     PMHAL_PRCM_MOD_SLV_EXPS_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SLV_EXPS_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
    {&PMHAL_PRCM_MOD_SPARE0_prop,
     PMHAL_PRCM_MOD_SPARE0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPARE0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
    {&PMHAL_PRCM_MOD_SPARE1_prop,
     PMHAL_PRCM_MOD_SPARE1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPARE1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    {&PMHAL_PRCM_MOD_SPI0_prop,
     PMHAL_PRCM_MOD_SPI0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    {&PMHAL_PRCM_MOD_SPI1_prop,
     PMHAL_PRCM_MOD_SPI1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    {&PMHAL_PRCM_MOD_SPI2_prop,
     PMHAL_PRCM_MOD_SPI2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    {&PMHAL_PRCM_MOD_SPI3_prop,
     PMHAL_PRCM_MOD_SPI3_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI3_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    {&PMHAL_PRCM_MOD_SPINLOCK_prop,
     PMHAL_PRCM_MOD_SPINLOCK_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPINLOCK_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    {&PMHAL_PRCM_MOD_TIMER2_prop,
     PMHAL_PRCM_MOD_TIMER2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    {&PMHAL_PRCM_MOD_TIMER3_prop,
     PMHAL_PRCM_MOD_TIMER3_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER3_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    {&PMHAL_PRCM_MOD_TIMER4_prop,
     PMHAL_PRCM_MOD_TIMER4_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER4_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    {&PMHAL_PRCM_MOD_TIMER5_prop,
     PMHAL_PRCM_MOD_TIMER5_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER5_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    {&PMHAL_PRCM_MOD_TIMER6_prop,
     PMHAL_PRCM_MOD_TIMER6_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER6_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    {&PMHAL_PRCM_MOD_TIMER7_prop,
     PMHAL_PRCM_MOD_TIMER7_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER7_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    {&PMHAL_PRCM_MOD_TPCC_prop,
     PMHAL_PRCM_MOD_TPCC_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TPCC_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
    {&PMHAL_PRCM_MOD_TPTC0_prop,
     PMHAL_PRCM_MOD_TPTC0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    {&PMHAL_PRCM_MOD_TPTC1_prop,
     PMHAL_PRCM_MOD_TPTC1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    {&PMHAL_PRCM_MOD_TPTC2_prop,
     PMHAL_PRCM_MOD_TPTC2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    {&PMHAL_PRCM_MOD_UART1_prop,
     PMHAL_PRCM_MOD_UART1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    {&PMHAL_PRCM_MOD_UART2_prop,
     PMHAL_PRCM_MOD_UART2_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART2_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    {&PMHAL_PRCM_MOD_UART3_prop,
     PMHAL_PRCM_MOD_UART3_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART3_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
    {&PMHAL_PRCM_MOD_UART4_prop,
     PMHAL_PRCM_MOD_UART4_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART4_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
    {&PMHAL_PRCM_MOD_UART5_prop,
     PMHAL_PRCM_MOD_UART5_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART5_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
    {&PMHAL_PRCM_MOD_USB0_prop,
     PMHAL_PRCM_MOD_USB0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_USB0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
    {&PMHAL_PRCM_MOD_BITBLT_prop,
     PMHAL_PRCM_MOD_BITBLT_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_BITBLT_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    {&PMHAL_PRCM_MOD_GFX_prop,
     PMHAL_PRCM_MOD_GFX_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GFX_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
    {&PMHAL_PRCM_MOD_MMU_prop,
     PMHAL_PRCM_MOD_MMU_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMU_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG
    {&PMHAL_PRCM_MOD_MMU_CFG_prop,
     PMHAL_PRCM_MOD_MMU_CFG_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMU_CFG_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    {&PMHAL_PRCM_MOD_ADC_TSC_prop,
     PMHAL_PRCM_MOD_ADC_TSC_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_ADC_TSC_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    {&PMHAL_PRCM_MOD_CONTROL_prop,
     PMHAL_PRCM_MOD_CONTROL_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_CONTROL_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    {&PMHAL_PRCM_MOD_DEBUGSS_prop,
     PMHAL_PRCM_MOD_DEBUGSS_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DEBUGSS_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    {&PMHAL_PRCM_MOD_GPIO0_prop,
     PMHAL_PRCM_MOD_GPIO0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    {&PMHAL_PRCM_MOD_I2C0_prop,
     PMHAL_PRCM_MOD_I2C0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_I2C0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
    {&PMHAL_PRCM_MOD_L4WKUP_prop,
     PMHAL_PRCM_MOD_L4WKUP_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_L4WKUP_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
    {&PMHAL_PRCM_MOD_SMARTREFLEX0_prop,
     PMHAL_PRCM_MOD_SMARTREFLEX0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SMARTREFLEX0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
    {&PMHAL_PRCM_MOD_SMARTREFLEX1_prop,
     PMHAL_PRCM_MOD_SMARTREFLEX1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SMARTREFLEX1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    {&PMHAL_PRCM_MOD_TIMER0_prop,
     PMHAL_PRCM_MOD_TIMER0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    {&PMHAL_PRCM_MOD_TIMER1_prop,
     PMHAL_PRCM_MOD_TIMER1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
    {&PMHAL_PRCM_MOD_UART0_prop,
     PMHAL_PRCM_MOD_UART0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    {&PMHAL_PRCM_MOD_WDT0_prop,
     PMHAL_PRCM_MOD_WDT0_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_WDT0_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
    {&PMHAL_PRCM_MOD_WDT1_prop,
     PMHAL_PRCM_MOD_WDT1_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_WDT1_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
    {&PMHAL_PRCM_MOD_WKUP_M3_prop,
     PMHAL_PRCM_MOD_WKUP_M3_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_WKUP_M3_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
    {&PMHAL_PRCM_MOD_CEFUSE_prop,
     PMHAL_PRCM_MOD_CEFUSE_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_CEFUSE_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    {&PMHAL_PRCM_MOD_RTCSS_prop,
     PMHAL_PRCM_MOD_RTCSS_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_RTCSS_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
    {&PMHAL_PRCM_MOD_MPU_prop,
     PMHAL_PRCM_MOD_MPU_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MPU_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE
    {&PMHAL_PRCM_MOD_EFUSE_prop,
     PMHAL_PRCM_MOD_EFUSE_inNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_EFUSE_inNodes,
                pmhalClockTreeNodeId)},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE */
};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_GFX_FCLK_MUX connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MUX_GFX_FCLK_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_UART_CLK connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DIV_UART_CLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_MMC_CLK connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DIV_MMC_CLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_LCD_GCLK_MUX connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_ICSS connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MOD_ICSS_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_UART0_CLK connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DIV_UART0_CLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_USB0 connected to PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MOD_USB0_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_DCO_LDO,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     PMHAL_PRCM_CLK_USB_PLL_CLK};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_PER connected to PMHAL_PRCM_DPLL_INP_CLKINP
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_PER connected to PMHAL_PRCM_DPLL_INP_CLKINPULOW
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining to-nodes structures for PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeInputEdge     PMHAL_PRCM_DPLL_PER_toNodes[] =
{
    {PMHAL_PRCM_DPLL_INP_CLKINP,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp},
    {PMHAL_PRCM_DPLL_INP_CLKINPULOW,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp},
    {PMHAL_PRCM_MUX_GFX_FCLK_MUX,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MUX_GFX_FCLK_MUX_edgeProp},
    {PMHAL_PRCM_DIV_UART_CLK,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DIV_UART_CLK_edgeProp},
    {PMHAL_PRCM_DIV_MMC_CLK,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DIV_MMC_CLK_edgeProp},
    {PMHAL_PRCM_MUX_LCD_GCLK_MUX,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp},
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    {PMHAL_PRCM_MOD_ICSS,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MOD_ICSS_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
    {PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_edgeProp},
    {PMHAL_PRCM_DIV_UART0_CLK,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_DIV_UART0_CLK_edgeProp},
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
    {PMHAL_PRCM_MOD_USB0,
     &PMHAL_PRCM_DPLL_PER_PMHAL_PRCM_MOD_USB0_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_MPU connected to PMHAL_PRCM_DPLL_MPU
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_MPU_PMHAL_PRCM_MOD_MPU_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_MPU - PMHAL_PRCM_DPLL_MIN],
     PMHAL_PRCM_CLK_MPU_CLK};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_MPU connected to PMHAL_PRCM_DPLL_INP_CLKINP
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_MPU_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_MPU - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_MPU connected to PMHAL_PRCM_DPLL_INP_CLKINPULOW
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_MPU_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_MPU - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining to-nodes structures for PMHAL_PRCM_DPLL_MPU
 */
pmhalClockTreeInputEdge     PMHAL_PRCM_DPLL_MPU_toNodes[] =
{
    {PMHAL_PRCM_DPLL_INP_CLKINP,
     &PMHAL_PRCM_DPLL_MPU_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp},
    {PMHAL_PRCM_DPLL_INP_CLKINPULOW,
     &PMHAL_PRCM_DPLL_MPU_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp},
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
    {PMHAL_PRCM_MOD_MPU,
     &PMHAL_PRCM_DPLL_MPU_PMHAL_PRCM_MOD_MPU_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_EMIF_GCLK connected to PMHAL_PRCM_DPLL_DDR
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_DIV_EMIF_GCLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_DDR - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX connected to PMHAL_PRCM_DPLL_DDR
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_DDR - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_DDR connected to PMHAL_PRCM_DPLL_INP_CLKINP
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_DDR - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_DDR connected to PMHAL_PRCM_DPLL_INP_CLKINPULOW
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_DDR - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining to-nodes structures for PMHAL_PRCM_DPLL_DDR
 */
pmhalClockTreeInputEdge     PMHAL_PRCM_DPLL_DDR_toNodes[] =
{
    {PMHAL_PRCM_DPLL_INP_CLKINP,
     &PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp},
    {PMHAL_PRCM_DPLL_INP_CLKINPULOW,
     &PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp},
    {PMHAL_PRCM_DIV_EMIF_GCLK,
     &PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_DIV_EMIF_GCLK_edgeProp},
    {PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX,
     &PMHAL_PRCM_DPLL_DDR_PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_edgeProp}
};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_LCD_GCLK_MUX connected to PMHAL_PRCM_DPLL_DISP
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_DISP_PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M2,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_DISP - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_DISP connected to PMHAL_PRCM_DPLL_INP_CLKINP
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_DISP_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_DISP - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_DISP connected to PMHAL_PRCM_DPLL_INP_CLKINPULOW
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_DISP_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_DISP - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining to-nodes structures for PMHAL_PRCM_DPLL_DISP
 */
pmhalClockTreeInputEdge     PMHAL_PRCM_DPLL_DISP_toNodes[] =
{
    {PMHAL_PRCM_DPLL_INP_CLKINP,
     &PMHAL_PRCM_DPLL_DISP_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp},
    {PMHAL_PRCM_DPLL_INP_CLKINPULOW,
     &PMHAL_PRCM_DPLL_DISP_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp},
    {PMHAL_PRCM_MUX_LCD_GCLK_MUX,
     &PMHAL_PRCM_DPLL_DISP_PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp}
};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_L4_WKUP_GCLK connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_DEBUGSS connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_DEBUGSS_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_BITBLT connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_BITBLT_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     PMHAL_PRCM_CLK_GFX_L3_GCLK};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_GFX connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_GFX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     PMHAL_PRCM_CLK_GFX_L3_GCLK};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_MMU connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_MMU_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     PMHAL_PRCM_CLK_GFX_L3_GCLK};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_GFX_FCLK_MUX connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MUX_GFX_FCLK_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_SYSCLK1 connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_SYSCLK1_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX connected to
 *         PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_L4_RTC_GCLK connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_L4_RTC_GCLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M4,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M5,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MOD_CPGMAC0 connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_CPGMAC0_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M5,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     PMHAL_PRCM_CLK_CPSW_250MHZ_CLK};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DIV_CPSW_50MHZ_CLK connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M5,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_MUX_LCD_GCLK_MUX connected to PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp
    =
    {PMHAL_PRCM_DPLL_POST_DIV_M5,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_CORE connected to PMHAL_PRCM_DPLL_INP_CLKINP
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining property structure for
 *         PMHAL_PRCM_DPLL_CORE connected to PMHAL_PRCM_DPLL_INP_CLKINPULOW
 */
pmhalClockTreeEdgeProp
    PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp
    =
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
     0};

/**
 *  \brief Structure defining to-nodes structures for PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeInputEdge     PMHAL_PRCM_DPLL_CORE_toNodes[] =
{
    {PMHAL_PRCM_DPLL_INP_CLKINP,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DPLL_INP_CLKINP_edgeProp},
    {PMHAL_PRCM_DPLL_INP_CLKINPULOW,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DPLL_INP_CLKINPULOW_edgeProp},
    {PMHAL_PRCM_DIV_L4_WKUP_GCLK,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    {PMHAL_PRCM_MOD_DEBUGSS,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_DEBUGSS_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
    {PMHAL_PRCM_MOD_BITBLT,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_BITBLT_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    {PMHAL_PRCM_MOD_GFX,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_GFX_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
    {PMHAL_PRCM_MOD_MMU,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_MMU_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */
    {PMHAL_PRCM_MUX_GFX_FCLK_MUX,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MUX_GFX_FCLK_MUX_edgeProp},
    {PMHAL_PRCM_DIV_SYSCLK1,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_SYSCLK1_edgeProp},
    {PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_edgeProp},
    {PMHAL_PRCM_DIV_L4_RTC_GCLK,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_L4_RTC_GCLK_edgeProp},
    {PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_edgeProp},
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    {PMHAL_PRCM_MOD_CPGMAC0,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MOD_CPGMAC0_edgeProp},
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
    {PMHAL_PRCM_DIV_CPSW_50MHZ_CLK,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_edgeProp},
    {PMHAL_PRCM_MUX_LCD_GCLK_MUX,
     &PMHAL_PRCM_DPLL_CORE_PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp}
};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX -
                        PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_CPSW_5MHZ_CLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_edgeProp =
{PMHAL_PRCM_DIV_CPSW_5MHZ_CLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_CPSW_5MHZ_CLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_CPSW_50MHZ_CLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_edgeProp =
{PMHAL_PRCM_DIV_CPSW_50MHZ_CLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_CPSW_50MHZ_CLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_edgeProp =
{PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_ROOT_CLK_SYS_CLKIN
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp =
{PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
 NULL,
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_CORE_100M
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_CORE_100M_edgeProp =
{PMHAL_PRCM_DIV_CORE_100M,
 &pmhalDividerElems[PMHAL_PRCM_DIV_CORE_100M - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_SYSCLK1
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_SYSCLK1_edgeProp =
{PMHAL_PRCM_DIV_SYSCLK1,
 &pmhalDividerElems[PMHAL_PRCM_DIV_SYSCLK1 - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_EMIF_GCLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_EMIF_GCLK_edgeProp =
{PMHAL_PRCM_DIV_EMIF_GCLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_EMIF_GCLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_ROOT_CLK_CLK_32KHZ
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp =
{PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
 NULL,
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_UART_CLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_UART_CLK_edgeProp =
{PMHAL_PRCM_DIV_UART_CLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_UART_CLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX -
                        PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_LCD_GCLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_LCD_GCLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_LCD_GCLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_MMC_CLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_MMC_CLK_edgeProp =
{PMHAL_PRCM_DIV_MMC_CLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_MMC_CLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER2_CLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER2_CLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER2_CLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER2_CLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER3_CLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER3_CLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER3_CLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER3_CLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER4_CLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER4_CLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER4_CLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER4_CLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER5_CLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER5_CLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER5_CLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER5_CLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER6_CLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER6_CLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER6_CLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER6_CLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER7_CLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER7_CLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER7_CLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER7_CLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_GFX_FCLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_GFX_FCLK_edgeProp =
{PMHAL_PRCM_DIV_GFX_FCLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_GFX_FCLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_L4_WKUP_GCLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp =
{PMHAL_PRCM_DIV_L4_WKUP_GCLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_L4_WKUP_GCLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_UART0_CLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_UART0_CLK_edgeProp =
{PMHAL_PRCM_DIV_UART0_CLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_UART0_CLK - PMHAL_PRCM_DIV_MIN],
 0U};

#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER0_GCLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER0_GCLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER0_GCLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};
#endif

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_TIMER1_GCLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_TIMER1_GCLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_WDT0_GCLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_WDT0_GCLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_WDT0_GCLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_WDT0_GCLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};
#endif

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_MUX_WDT1_GCLK_MUX
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_MUX_WDT1_GCLK_MUX_edgeProp =
{PMHAL_PRCM_MUX_WDT1_GCLK_MUX,
 &pmhalMultiplexerElems[PMHAL_PRCM_MUX_WDT1_GCLK_MUX - PMHAL_PRCM_MUX_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DIV_L4_RTC_GCLK
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DIV_L4_RTC_GCLK_edgeProp =
{PMHAL_PRCM_DIV_L4_RTC_GCLK,
 &pmhalDividerElems[PMHAL_PRCM_DIV_L4_RTC_GCLK - PMHAL_PRCM_DIV_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DPLL_CORE
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DPLL_CORE_edgeProp =
{PMHAL_PRCM_DPLL_CORE,
 &pmhalDpllElems[PMHAL_PRCM_DPLL_CORE - PMHAL_PRCM_DPLL_MIN],
 0U};

/**
 *  \brief Structure defining edge property structure for
 *         PMHAL_PRCM_DPLL_PER
 */
pmhalClockTreeEdgeProp    PMHAL_PRCM_DPLL_PER_edgeProp =
{PMHAL_PRCM_DPLL_PER,
 &pmhalDpllElems[PMHAL_PRCM_DPLL_PER - PMHAL_PRCM_DPLL_MIN],
 0U};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_CPGMAC0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_CPGMAC0_fromNodes[] = {
    {PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK,
     &PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_edgeProp},
    {PMHAL_PRCM_CLK_CPSW_250MHZ_CLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_CPSW_5MHZ_CLK,
     &PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_edgeProp},
    {PMHAL_PRCM_CLK_CPSW_50MHZ_CLK,
     &PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_edgeProp},
    {PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK,
     &PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_DCAN0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_DCAN0_fromNodes[] = {
    {PMHAL_PRCM_CLK_CAN_CLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_DCAN1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_DCAN1_fromNodes[] = {
    {PMHAL_PRCM_CLK_CAN_CLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_DMA4_CRYPTO
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_DMA4_CRYPTO_fromNodes[] = {
    {PMHAL_PRCM_CLK_DMA_L3_GCLK,
     &PMHAL_PRCM_DIV_SYSCLK1_edgeProp},
    {PMHAL_PRCM_CLK_DMA_L4S_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_EMIF
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_EMIF_fromNodes[] = {
    {PMHAL_PRCM_CLK_EMIF_GCLK,
     &PMHAL_PRCM_DIV_EMIF_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_L3_GCLK,
     &PMHAL_PRCM_DIV_SYSCLK1_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GPIO1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GPIO1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_GPIO_1_GDBCLK,
     &PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GPIO2
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GPIO2_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_GPIO_2_GDBCLK,
     &PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GPIO3
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GPIO3_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_GPIO_3_GDBCLK,
     &PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GPIO4
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GPIO4_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_GPIO_4_GDBCLK,
     &PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GPIO5
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GPIO5_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_GPIO_5_GDBCLK,
     &PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GPIO6
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GPIO6_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_GPIO_6_GDBCLK,
     &PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_I2C1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_I2C1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_I2C_FCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_I2C2
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_I2C2_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_I2C_FCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_ICSS
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_ICSS_fromNodes[] = {
    {PMHAL_PRCM_CLK_ICSS_IEP_GCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_ICSS_OCP_GCLK,
     &PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_edgeProp},
    {PMHAL_PRCM_CLK_ICSS_UART_GCLK,
     &PMHAL_PRCM_DPLL_PER_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_L3
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_L3_fromNodes[] = {
    {PMHAL_PRCM_CLK_L3_GCLK,
     &PMHAL_PRCM_DIV_SYSCLK1_edgeProp},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_LCDC
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_LCDC_fromNodes[] = {
    {PMHAL_PRCM_CLK_LCD_L3_GCLK,
     &PMHAL_PRCM_DIV_SYSCLK1_edgeProp},
    {PMHAL_PRCM_CLK_LCD_L4S_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_LCD_GCLK,
     &PMHAL_PRCM_MUX_LCD_GCLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_MCASP0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_MCASP0_fromNodes[] = {
    {PMHAL_PRCM_CLK_MCASP_FCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_MCASP1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_MCASP1_fromNodes[] = {
    {PMHAL_PRCM_CLK_MCASP_FCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_MCASP2
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_MCASP2_fromNodes[] = {
    {PMHAL_PRCM_CLK_MCASP_FCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_MMC0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_MMC0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_MMC_FCLK,
     &PMHAL_PRCM_DIV_MMC_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_MMC1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_MMC1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_MMC_FCLK,
     &PMHAL_PRCM_DIV_MMC_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_MMC2
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_MMC2_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_MMC_FCLK,
     &PMHAL_PRCM_DIV_MMC_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_SPI0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_SPI0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_SPI1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_SPI1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_SPI2
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_SPI2_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_SPI3
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_SPI3_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER2
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER2_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_TIMER2_GCLK,
     &PMHAL_PRCM_MUX_TIMER2_CLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER3
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER3_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_TIMER3_GCLK,
     &PMHAL_PRCM_MUX_TIMER3_CLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER4
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER4_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_TIMER4_GCLK,
     &PMHAL_PRCM_MUX_TIMER4_CLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER5
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER5_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_TIMER5_GCLK,
     &PMHAL_PRCM_MUX_TIMER5_CLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER6
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER6_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_TIMER6_GCLK,
     &PMHAL_PRCM_MUX_TIMER6_CLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER7
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER7_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_TIMER7_GCLK,
     &PMHAL_PRCM_MUX_TIMER7_CLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_UART1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_UART1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_UART2
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_UART2_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_UART3
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_UART3_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_UART4
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_UART4_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_UART5
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_UART5_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     &PMHAL_PRCM_DIV_UART_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_USB0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_USB0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L3S_GCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp},
    {PMHAL_PRCM_CLK_USB_PLL_CLK,
     &PMHAL_PRCM_DPLL_PER_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_BITBLT
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_BITBLT_fromNodes[] = {
    {PMHAL_PRCM_CLK_GFX_L3_GCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_L4LS_GFX_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GFX
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GFX_fromNodes[] = {
    {PMHAL_PRCM_CLK_GFX_FCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_GFX_L3_GCLK,
     &PMHAL_PRCM_DIV_GFX_FCLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_ADC_TSC
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_ADC_TSC_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_ADC_FCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_DEBUGSS
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_DEBUGSS_fromNodes[] = {
    {PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_L3_AON_GCLK,
     &PMHAL_PRCM_DPLL_CORE_edgeProp},
    {PMHAL_PRCM_CLK_DBGSYSCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_GPIO0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_GPIO0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_GPIO0_GDBCLK,
     &PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_I2C0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_I2C0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_I2C0_GFCLK,
     &PMHAL_PRCM_DIV_UART0_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_SMARTREFLEX0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_SMARTREFLEX0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_SR_SYSCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_SMARTREFLEX1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_SMARTREFLEX1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_SR_SYSCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_TIMER0_GCLK,
     &PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_TIMER1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_TIMER1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_TIMER1_GCLK,
     &PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_UART0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_UART0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_UART0_GFCLK,
     &PMHAL_PRCM_DIV_UART0_CLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_WDT0
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_WDT0_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_WDT0_GCLK,
     &PMHAL_PRCM_MUX_WDT0_GCLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_WDT1
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_WDT1_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     &PMHAL_PRCM_DIV_L4_WKUP_GCLK_edgeProp},
    {PMHAL_PRCM_CLK_WDT1_GCLK,
     &PMHAL_PRCM_MUX_WDT1_GCLK_MUX_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_CEFUSE
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_CEFUSE_fromNodes[] = {
    {PMHAL_PRCM_CLK_L4_CEFUSE_GCLK,
     &PMHAL_PRCM_DIV_CORE_100M_edgeProp},
    {PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK,
     &PMHAL_PRCM_ROOT_CLK_SYS_CLKIN_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
/**
 *  \brief Structure defining FromNodes of PMHAL_PRCM_MOD_RTCSS
 */
pmhalClockTreeInputEdge        PMHAL_PRCM_MOD_RTCSS_fromNodes[] = {
    {PMHAL_PRCM_CLK_RTC_32KCLK,
     &PMHAL_PRCM_ROOT_CLK_CLK_32KHZ_edgeProp},
    {PMHAL_PRCM_CLK_L4_RTC_GCLK,
     &PMHAL_PRCM_DIV_L4_RTC_GCLK_edgeProp}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */

const pmhalClockTreeOutputEdge prcmEdges[] =
{
    {PMHAL_PRCM_DPLL_PER,
     PMHAL_PRCM_DPLL_PER_toNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_PER_toNodes, pmhalClockTreeInputEdge)},
    {PMHAL_PRCM_DPLL_MPU,
     PMHAL_PRCM_DPLL_MPU_toNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_MPU_toNodes, pmhalClockTreeInputEdge)},
    {PMHAL_PRCM_DPLL_DDR,
     PMHAL_PRCM_DPLL_DDR_toNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_DDR_toNodes, pmhalClockTreeInputEdge)},
    {PMHAL_PRCM_DPLL_DISP,
     PMHAL_PRCM_DPLL_DISP_toNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_DISP_toNodes, pmhalClockTreeInputEdge)},
    {PMHAL_PRCM_DPLL_CORE,
     PMHAL_PRCM_DPLL_CORE_toNodes,
     VSIZE_TYPE(PMHAL_PRCM_DPLL_CORE_toNodes, pmhalClockTreeInputEdge)},
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    {PMHAL_PRCM_MOD_CPGMAC0,
     PMHAL_PRCM_MOD_CPGMAC0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_CPGMAC0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    {PMHAL_PRCM_MOD_DCAN0,
     PMHAL_PRCM_MOD_DCAN0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DCAN0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    {PMHAL_PRCM_MOD_DCAN1,
     PMHAL_PRCM_MOD_DCAN1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DCAN1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
    {PMHAL_PRCM_MOD_DMA4_CRYPTO,
     PMHAL_PRCM_MOD_DMA4_CRYPTO_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DMA4_CRYPTO_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    {PMHAL_PRCM_MOD_EMIF,
     PMHAL_PRCM_MOD_EMIF_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_EMIF_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    {PMHAL_PRCM_MOD_GPIO1,
     PMHAL_PRCM_MOD_GPIO1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    {PMHAL_PRCM_MOD_GPIO2,
     PMHAL_PRCM_MOD_GPIO2_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO2_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    {PMHAL_PRCM_MOD_GPIO3,
     PMHAL_PRCM_MOD_GPIO3_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO3_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    {PMHAL_PRCM_MOD_GPIO4,
     PMHAL_PRCM_MOD_GPIO4_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO4_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    {PMHAL_PRCM_MOD_GPIO5,
     PMHAL_PRCM_MOD_GPIO5_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO5_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
    {PMHAL_PRCM_MOD_GPIO6,
     PMHAL_PRCM_MOD_GPIO6_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO6_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    {PMHAL_PRCM_MOD_I2C1,
     PMHAL_PRCM_MOD_I2C1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_I2C1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    {PMHAL_PRCM_MOD_I2C2,
     PMHAL_PRCM_MOD_I2C2_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_I2C2_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    {PMHAL_PRCM_MOD_ICSS,
     PMHAL_PRCM_MOD_ICSS_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_ICSS_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    {PMHAL_PRCM_MOD_L3,
     PMHAL_PRCM_MOD_L3_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_L3_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    {PMHAL_PRCM_MOD_LCDC,
     PMHAL_PRCM_MOD_LCDC_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_LCDC_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    {PMHAL_PRCM_MOD_MCASP0,
     PMHAL_PRCM_MOD_MCASP0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    {PMHAL_PRCM_MOD_MCASP1,
     PMHAL_PRCM_MOD_MCASP1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
    {PMHAL_PRCM_MOD_MCASP2,
     PMHAL_PRCM_MOD_MCASP2_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP2_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    {PMHAL_PRCM_MOD_MMC0,
     PMHAL_PRCM_MOD_MMC0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMC0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    {PMHAL_PRCM_MOD_MMC1,
     PMHAL_PRCM_MOD_MMC1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMC1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    {PMHAL_PRCM_MOD_MMC2,
     PMHAL_PRCM_MOD_MMC2_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_MMC2_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    {PMHAL_PRCM_MOD_SPI0,
     PMHAL_PRCM_MOD_SPI0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    {PMHAL_PRCM_MOD_SPI1,
     PMHAL_PRCM_MOD_SPI1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    {PMHAL_PRCM_MOD_SPI2,
     PMHAL_PRCM_MOD_SPI2_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI2_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    {PMHAL_PRCM_MOD_SPI3,
     PMHAL_PRCM_MOD_SPI3_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SPI3_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    {PMHAL_PRCM_MOD_TIMER2,
     PMHAL_PRCM_MOD_TIMER2_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER2_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    {PMHAL_PRCM_MOD_TIMER3,
     PMHAL_PRCM_MOD_TIMER3_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER3_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    {PMHAL_PRCM_MOD_TIMER4,
     PMHAL_PRCM_MOD_TIMER4_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER4_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    {PMHAL_PRCM_MOD_TIMER5,
     PMHAL_PRCM_MOD_TIMER5_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER5_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    {PMHAL_PRCM_MOD_TIMER6,
     PMHAL_PRCM_MOD_TIMER6_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER6_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    {PMHAL_PRCM_MOD_TIMER7,
     PMHAL_PRCM_MOD_TIMER7_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER7_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    {PMHAL_PRCM_MOD_UART1,
     PMHAL_PRCM_MOD_UART1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    {PMHAL_PRCM_MOD_UART2,
     PMHAL_PRCM_MOD_UART2_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART2_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    {PMHAL_PRCM_MOD_UART3,
     PMHAL_PRCM_MOD_UART3_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART3_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
    {PMHAL_PRCM_MOD_UART4,
     PMHAL_PRCM_MOD_UART4_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART4_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
    {PMHAL_PRCM_MOD_UART5,
     PMHAL_PRCM_MOD_UART5_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART5_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
    {PMHAL_PRCM_MOD_USB0,
     PMHAL_PRCM_MOD_USB0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_USB0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
    {PMHAL_PRCM_MOD_BITBLT,
     PMHAL_PRCM_MOD_BITBLT_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_BITBLT_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    {PMHAL_PRCM_MOD_GFX,
     PMHAL_PRCM_MOD_GFX_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GFX_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    {PMHAL_PRCM_MOD_ADC_TSC,
     PMHAL_PRCM_MOD_ADC_TSC_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_ADC_TSC_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    {PMHAL_PRCM_MOD_DEBUGSS,
     PMHAL_PRCM_MOD_DEBUGSS_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_DEBUGSS_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    {PMHAL_PRCM_MOD_GPIO0,
     PMHAL_PRCM_MOD_GPIO0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    {PMHAL_PRCM_MOD_I2C0,
     PMHAL_PRCM_MOD_I2C0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_I2C0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
    {PMHAL_PRCM_MOD_SMARTREFLEX0,
     PMHAL_PRCM_MOD_SMARTREFLEX0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SMARTREFLEX0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
    {PMHAL_PRCM_MOD_SMARTREFLEX1,
     PMHAL_PRCM_MOD_SMARTREFLEX1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_SMARTREFLEX1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    {PMHAL_PRCM_MOD_TIMER0,
     PMHAL_PRCM_MOD_TIMER0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    {PMHAL_PRCM_MOD_TIMER1,
     PMHAL_PRCM_MOD_TIMER1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
    {PMHAL_PRCM_MOD_UART0,
     PMHAL_PRCM_MOD_UART0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_UART0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    {PMHAL_PRCM_MOD_WDT0,
     PMHAL_PRCM_MOD_WDT0_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_WDT0_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
    {PMHAL_PRCM_MOD_WDT1,
     PMHAL_PRCM_MOD_WDT1_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_WDT1_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
    {PMHAL_PRCM_MOD_CEFUSE,
     PMHAL_PRCM_MOD_CEFUSE_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_CEFUSE_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
    #ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    {PMHAL_PRCM_MOD_RTCSS,
     PMHAL_PRCM_MOD_RTCSS_fromNodes,
     VSIZE_TYPE(PMHAL_PRCM_MOD_RTCSS_fromNodes, pmhalClockTreeInputEdge)},
    #endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
};

pmhalClockTree prcmGraph = {
    VSIZE_TYPE(prcmNodes, pmhalClockTreeNode),
    prcmNodes,
    VSIZE_TYPE(prcmEdges, pmhalClockTreeOutputEdge), /* edges max */
    prcmEdges                                   /* edges[] */
};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif
