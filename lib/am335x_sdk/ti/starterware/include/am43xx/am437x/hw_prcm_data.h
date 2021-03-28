/**
 *  \file      hw_prcm_data.h
 *
 *  \brief     This file contains macros and data-structures pertaining to
 *              StarterWare PRCM (internal) implementation.
 *
 *  \warning   This file is auto generated. So avoid manual changes.
 *              If manual changes are required the implications of the
 *              change in this and other auto generated files has to be
 *              completely understood.
 */

/* Copyright (c) 2013 Texas Instruments Inc - http://www.ti.com */

/*
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


#ifndef HW_PRCM_DATA_H
#define HW_PRCM_DATA_H

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */
#include "agraph.h"
#include "chipdb.h"
#include "hw_prcm.h"
#include "hw_prcm_modinc.h"
#include "hw_chipdb_prcm_rid.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/** \brief PRCM Optional clock enable */
#define PRCM_OPT_CLOCK_ENABLE           (1U)

/** \brief PRCM Bypass modes shift */
#define PRCM_CLKMODE_DPLL_EN_SHIFT      PRCM_CM_CLKMODE_DPLL_MPU_EN_SHIFT
/** \brief PRCM Bypass modes mask */
#define PRCM_CLKMODE_DPLL_EN_MASK       PRCM_CM_CLKMODE_DPLL_MPU_EN_MASK

/** \brief PRCM Idle state shift */
#define PRCM_IDLEST_DPLL_ST_CLK_SHIFT   PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_SHIFT
/** \brief PRCM Idle state shift */
#define PRCM_IDLEST_DPLL_ST_CLK_MASK    PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_MASK

/** \brief PRCM ADPLLS Multiplier shift */
#define PRCM_ADPLLS_CLKSEL_MULT_SHIFT   PRCM_CM_CLKSEL_DPLL_MPU_MULT_SHIFT
/** \brief PRCM ADPLLS Multiplier mask */
#define PRCM_ADPLLS_CLKSEL_MULT_MASK    PRCM_CM_CLKSEL_DPLL_MPU_MULT_MASK
/** \brief PRCM ADPLLS Divider shift */
#define PRCM_ADPLLS_CLKSEL_DIV_SHIFT    PRCM_CM_CLKSEL_DPLL_MPU_DIV_SHIFT
/** \brief PRCM ADPLLS Divider mask */
#define PRCM_ADPLLS_CLKSEL_DIV_MASK     PRCM_CM_CLKSEL_DPLL_MPU_DIV_MASK

/** \brief PRCM ADPLLLJ Multiplier shift */
#define PRCM_ADPLLLJ_CLKSEL_MULT_SHIFT  PRCM_CM_CLKSEL_DPLL_PER_MULT_SHIFT
/** \brief PRCM ADPLLLJ Multiplier mask */
#define PRCM_ADPLLLJ_CLKSEL_MULT_MASK   PRCM_CM_CLKSEL_DPLL_PER_MULT_MASK
/** \brief PRCM ADPLLLJ Divider shift */
#define PRCM_ADPLLLJ_CLKSEL_DIV_SHIFT   PRCM_CM_CLKSEL_DPLL_PER_DIV_SHIFT
/** \brief PRCM ADPLLLJ Divider mask */
#define PRCM_ADPLLLJ_CLKSEL_DIV_MASK    PRCM_CM_CLKSEL_DPLL_PER_DIV_MASK

/** \brief DPLL Drift guard shift */
#define PRCM_DPLL_DRIFTGUARD_EN_SHIFT   PRCM_CM_CLKMODE_DPLL_MPU_DRIFTGUARD_EN_SHIFT
/** \brief DPLL Drift guard mask */
#define PRCM_DPLL_DRIFTGUARD_EN_MASK    PRCM_CM_CLKMODE_DPLL_MPU_DRIFTGUARD_EN_MASK

/** \brief DPLL Ramp level shift */
#define PRCM_DPLL_RAMP_LEVEL_SHIFT      PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_SHIFT
/** \brief DPLL Ramp level mask */
#define PRCM_DPLL_RAMP_LEVEL_MASK       PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_MASK

/** \brief DPLL Ramp Rate shift */
#define PRCM_DPLL_RAMP_RATE_SHIFT       PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_SHIFT
/** \brief DPLL Ramp Rate mask */
#define PRCM_DPLL_RAMP_RATE_MASK        PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_MASK

/** \brief DPLL Relock ramp enable shift */
#define PRCM_DPLL_RELOCK_RAMP_EN_SHIFT  PRCM_CM_CLKMODE_DPLL_MPU_RELOCK_RAMP_EN_SHIFT
/** \brief DPLL Relock ramp enable mask */
#define PRCM_DPLL_RELOCK_RAMP_EN_MASK   PRCM_CM_CLKMODE_DPLL_MPU_RELOCK_RAMP_EN_MASK

/** \brief DPLL bypass clock selection shift */
#define PRCM_DPLL_BYP_SHIFT             PRCM_CM_CLKSEL_DPLL_MPU_BYP_SHIFT
/** \brief DPLL bypass clock selection mask */
#define PRCM_DPLL_BYP_MASK              PRCM_CM_CLKSEL_DPLL_MPU_BYP_MASK

/** \brief PRCM module mode shift */
#define PRCM_MODULE_MODE_SHIFT          PRCM_CM_PER_L3_CLKCTRL_MODULEMODE_SHIFT
/** \brief PRCM module mode mask */
#define PRCM_MODULE_MODE_MASK           PRCM_CM_PER_L3_CLKCTRL_MODULEMODE_MASK

/** \brief PRCM Clock control - idle state shift */
#define PRCM_CLKCTRL_IDLEST_SHIFT       PRCM_CM_PER_L3_CLKCTRL_IDLEST_SHIFT
/** \brief PRCM Clock control - idle state mask */
#define PRCM_CLKCTRL_IDLEST_MASK        PRCM_CM_PER_L3_CLKCTRL_IDLEST_MASK

/** \brief PRCM Clock control - standby state shift */
#define PRCM_CLKCTRL_STBYST_SHIFT       PRCM_CM_PER_TPTC0_CLKCTRL_STBYST_SHIFT
/** \brief PRCM Clock control - standby state mask */
#define PRCM_CLKCTRL_STBYST_MASK        PRCM_CM_PER_TPTC0_CLKCTRL_STBYST_MASK

/** \brief PRCM Clock domain transition shift */
#define PRCM_CLKSTCTRL_CLKTRCTRL_SHIFT  PRCM_CM_PER_L3_CLKSTCTRL_CLKTRCTRL_SHIFT
/** \brief PRCM Clock domain transition mask */
#define PRCM_CLKSTCTRL_CLKTRCTRL_MASK   PRCM_CM_PER_L3_CLKSTCTRL_CLKTRCTRL_MASK

/** \brief PRCM Clock domain status shift */
#define PRCM_PWRSTST_POWERSTATEST_SHIFT PRCM_PM_MPU_PWRSTST_POWERSTATEST_SHIFT
/** \brief PRCM Clock domain status mask */
#define PRCM_PWRSTST_POWERSTATEST_MASK  PRCM_PM_MPU_PWRSTST_POWERSTATEST_MASK

/** \brief DPLL Low power mode enable shift */
#define PRCM_CLKMODE_DPLL_LPMODE_EN_SHIFT PRCM_CM_CLKMODE_DPLL_MPU_LPMODE_EN_SHIFT
/** \brief DPLL Low power mode enable mask */
#define PRCM_CLKMODE_DPLL_LPMODE_EN_MASK  PRCM_CM_CLKMODE_DPLL_MPU_LPMODE_EN_MASK

/* Macros for invalid value */
#define PRCM_INVALID_REGADDR    (0xFFFFFFFFU)
/** \brief PRCM Invalid address */
#define PRCM_INVALID_BITFIELD   (0xFFFFFFFFU)
/** \brief PRCM Invalid bit-field */
#define PRCM_INVALID_SHIFT      (0xFFFFFFFFU)
/** \brief PRCM Invalid shift */
#define PRCM_INVALID_MASK       (0U)
/** \brief PRCM Invalid mask */

/*----------------------------------------------------------------------------*/
/**
 * \brief Clock-tree node types
 */
typedef enum
{
    PRCM_MOD,
    PRCM_MIN = PRCM_MOD,
    /*!< Lower bound (inclusive) */
    PRCM_DPLL,
    PRCM_MUX,
    PRCM_DIV,
    PRCM_ROOT_CLK,
    PRCM_MAX = PRCM_ROOT_CLK,
    /*!< Enum Upper bound */
    PRCM_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmNodeType_t;

/*----------------------------------------------------------------------------*/
/**
 * \brief Modules (Clk Tree leaf nodes)
 */
typedef enum
{
    PRCM_MOD_MIN_ = PRCM_NODE_MAX,
    /*!< Enum Lower bound placeholder */
#ifdef BUILDCFG_PRCM_MOD_CEFUSE
    PRCM_MOD_CEFUSE,
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
    PRCM_MOD_DEBUGSS,
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PRCM_MOD_DSS
    PRCM_MOD_DSS,
#endif /* BUILDCFG_PRCM_MOD_DSS */
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
    PRCM_MOD_EMIF_FW,
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_DDRPHY
    PRCM_MOD_DDRPHY,
#endif /* BUILDCFG_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PRCM_MOD_DLL
    PRCM_MOD_DLL,
#endif /* BUILDCFG_PRCM_MOD_DLL */
#ifdef BUILDCFG_PRCM_MOD_DLL_AGING
    PRCM_MOD_DLL_AGING,
#endif /* BUILDCFG_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PRCM_MOD_EMIF
    PRCM_MOD_EMIF,
#endif /* BUILDCFG_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GPMC
    PRCM_MOD_GPMC,
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_MMC0
    PRCM_MOD_MMC0,
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
    PRCM_MOD_MMC1,
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PRCM_MOD_MMC2
    PRCM_MOD_MMC2,
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
    PRCM_MOD_OCMCRAM,
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_OTFA_EMIF
    PRCM_MOD_OTFA_EMIF,
#endif /* BUILDCFG_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GFX
    PRCM_MOD_GFX,
#endif /* BUILDCFG_PRCM_MOD_GFX */
#ifdef BUILDCFG_PRCM_MOD_GPIO1
    PRCM_MOD_GPIO1,
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO2
    PRCM_MOD_GPIO2,
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PRCM_MOD_GPIO3
    PRCM_MOD_GPIO3,
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PRCM_MOD_GPIO4
    PRCM_MOD_GPIO4,
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PRCM_MOD_GPIO5
    PRCM_MOD_GPIO5,
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
    PRCM_MOD_MAG_CARD,
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PRCM_MOD_L3
    PRCM_MOD_L3,
#endif /* BUILDCFG_PRCM_MOD_L3 */
#ifdef BUILDCFG_PRCM_MOD_L3_INSTR
    PRCM_MOD_L3_INSTR,
#endif /* BUILDCFG_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PRCM_MOD_L4FW
    PRCM_MOD_L4FW,
#endif /* BUILDCFG_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PRCM_MOD_L4LS
    PRCM_MOD_L4LS,
#endif /* BUILDCFG_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PRCM_MOD_L4_HS
    PRCM_MOD_L4_HS,
#endif /* BUILDCFG_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PRCM_MOD_ICSS
    PRCM_MOD_ICSS,
#endif /* BUILDCFG_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PRCM_MOD_IEEE5000
    PRCM_MOD_IEEE5000,
#endif /* BUILDCFG_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PRCM_MOD_LCDC
    PRCM_MOD_LCDC,
#endif /* BUILDCFG_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PRCM_MOD_MSTR_EXPS
    PRCM_MOD_MSTR_EXPS,
#endif /* BUILDCFG_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PRCM_MOD_SLV_EXPS
    PRCM_MOD_SLV_EXPS,
#endif /* BUILDCFG_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PRCM_MOD_TPCC
    PRCM_MOD_TPCC,
#endif /* BUILDCFG_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PRCM_MOD_TPTC0
    PRCM_MOD_TPTC0,
#endif /* BUILDCFG_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PRCM_MOD_TPTC1
    PRCM_MOD_TPTC1,
#endif /* BUILDCFG_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PRCM_MOD_TPTC2
    PRCM_MOD_TPTC2,
#endif /* BUILDCFG_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PRCM_MOD_DCAN0
    PRCM_MOD_DCAN0,
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PRCM_MOD_DCAN1
    PRCM_MOD_DCAN1,
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PRCM_MOD_ELM
    PRCM_MOD_ELM,
#endif /* BUILDCFG_PRCM_MOD_ELM */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS0
    PRCM_MOD_EPWMSS0,
#endif /* BUILDCFG_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS1
    PRCM_MOD_EPWMSS1,
#endif /* BUILDCFG_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS2
    PRCM_MOD_EPWMSS2,
#endif /* BUILDCFG_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS3
    PRCM_MOD_EPWMSS3,
#endif /* BUILDCFG_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS4
    PRCM_MOD_EPWMSS4,
#endif /* BUILDCFG_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS5
    PRCM_MOD_EPWMSS5,
#endif /* BUILDCFG_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PRCM_MOD_ERMC
    PRCM_MOD_ERMC,
#endif /* BUILDCFG_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PRCM_MOD_HDQ1W
    PRCM_MOD_HDQ1W,
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PRCM_MOD_I2C1
    PRCM_MOD_I2C1,
#endif /* BUILDCFG_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PRCM_MOD_I2C2
    PRCM_MOD_I2C2,
#endif /* BUILDCFG_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
    PRCM_MOD_MCASP0,
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
    PRCM_MOD_QSPI,
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_SPI0
    PRCM_MOD_SPI0,
#endif /* BUILDCFG_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PRCM_MOD_SPI1
    PRCM_MOD_SPI1,
#endif /* BUILDCFG_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PRCM_MOD_SPI2
    PRCM_MOD_SPI2,
#endif /* BUILDCFG_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PRCM_MOD_SPI3
    PRCM_MOD_SPI3,
#endif /* BUILDCFG_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PRCM_MOD_SPI4
    PRCM_MOD_SPI4,
#endif /* BUILDCFG_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER10
    PRCM_MOD_TIMER10,
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PRCM_MOD_TIMER11
    PRCM_MOD_TIMER11,
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PRCM_MOD_TIMER2
    PRCM_MOD_TIMER2,
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER3
    PRCM_MOD_TIMER3,
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PRCM_MOD_TIMER4
    PRCM_MOD_TIMER4,
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER5
    PRCM_MOD_TIMER5,
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PRCM_MOD_TIMER6
    PRCM_MOD_TIMER6,
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PRCM_MOD_TIMER7
    PRCM_MOD_TIMER7,
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PRCM_MOD_TIMER8
    PRCM_MOD_TIMER8,
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PRCM_MOD_TIMER9
    PRCM_MOD_TIMER9,
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PRCM_MOD_UART1
    PRCM_MOD_UART1,
#endif /* BUILDCFG_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PRCM_MOD_UART2
    PRCM_MOD_UART2,
#endif /* BUILDCFG_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PRCM_MOD_UART3
    PRCM_MOD_UART3,
#endif /* BUILDCFG_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PRCM_MOD_UART4
    PRCM_MOD_UART4,
#endif /* BUILDCFG_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PRCM_MOD_UART5
    PRCM_MOD_UART5,
#endif /* BUILDCFG_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
    PRCM_MOD_CPGMAC0,
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PRCM_MOD_MAILBOX0
    PRCM_MOD_MAILBOX0,
#endif /* BUILDCFG_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PRCM_MOD_MCASP1
    PRCM_MOD_MCASP1,
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PRCM_MOD_SPARE0
    PRCM_MOD_SPARE0,
#endif /* BUILDCFG_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE1
    PRCM_MOD_SPARE1,
#endif /* BUILDCFG_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
    PRCM_MOD_SPINLOCK,
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_MPU
    PRCM_MOD_MPU,
#endif /* BUILDCFG_PRCM_MOD_MPU */
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
    PRCM_MOD_OCP_WP_NOC,
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PRCM_MOD_RTC
    PRCM_MOD_RTC,
#endif /* BUILDCFG_PRCM_MOD_RTC */
#ifdef BUILDCFG_PRCM_MOD_AES0
    PRCM_MOD_AES0,
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
    PRCM_MOD_CRYPTODMA,
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
    PRCM_MOD_DES,
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_PKA
    PRCM_MOD_PKA,
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_RNG
    PRCM_MOD_RNG,
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_SHA0
    PRCM_MOD_SHA0,
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
    PRCM_MOD_SMARTREFLEX0,
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
    PRCM_MOD_SMARTREFLEX1,
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
    PRCM_MOD_USB_PHY0_ALWAYS_ON,
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
    PRCM_MOD_USB_PHY1_ALWAYS_ON,
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_WDT0
    PRCM_MOD_WDT0,
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
    PRCM_MOD_WDT1,
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_TPMSS
    PRCM_MOD_TPMSS,
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
    PRCM_MOD_USBPHYOCP2SCP0,
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
    PRCM_MOD_USBPHYOCP2SCP1,
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
    PRCM_MOD_USB_OTG_SS0,
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
    PRCM_MOD_USB_OTG_SS1,
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
    PRCM_MOD_USIM0,
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
    PRCM_MOD_USIM1,
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
    PRCM_MOD_VPFE0,
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
    PRCM_MOD_VPFE1,
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
    PRCM_MOD_ADC_TSC,
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
    PRCM_MOD_CLKDIV32K,
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
    PRCM_MOD_CONTROL,
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
    PRCM_MOD_GPIO0,
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
    PRCM_MOD_I2C0,
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_L4WKUP
    PRCM_MOD_L4WKUP,
#endif /* BUILDCFG_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
    PRCM_MOD_SYNCTIMER,
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
    PRCM_MOD_TIMER0,
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
    PRCM_MOD_TIMER1,
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_UART0
    PRCM_MOD_UART0,
#endif /* BUILDCFG_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
    PRCM_MOD_WKUP_M3,
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PRCM_MOD_EFUSE
    PRCM_MOD_EFUSE,
#endif /* BUILDCFG_PRCM_MOD_EFUSE */
    PRCM_MOD_MAX_,
    /*!< Enum Upper bound placeholder */
    PRCM_MOD_MAX = (PRCM_MOD_MAX_ - 1),
    /*!< Enum Upper bound */
    PRCM_MOD_MIN = (PRCM_NODE_MAX + 1),
    /*!< Enum Lower bound */
    PRCM_MOD_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmModuleId_t;

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */
/**
 *  \brief Structure defining register bit-field.
 */
typedef struct
{
    uint32_t regAddr;
    /**< Register address */
    uint32_t mask;
    /**< Mask for bit-field */
    uint32_t shift;
    /**< Shift for bit-field from LSB */
}regBitField_t;

/**
 *  \brief Structure defining the properties of clock.
 */
typedef struct
{
    regBitField_t pClkCtrlBitField;
    regBitField_t clkActivityBitField;
}prcmClock_t;

/**
 *  \brief  Structure defining the properties of divider.
 *          Divider is defined as one input and one output.
 *
 *  In order to optimize for memory, if the pDividerBitValue is Null, the index
 *  of the pSupportedDivision array will be the bit-field configuration value.
 *  Example:
 *     prcmClockDivder_t div1 =
 *     {
 *         [ 1, 2, 4, 0]
 *         , NULL
 *     }
 *     prcmClockDivder_t div2 =
 *     {
 *         [ 1, 4, 0]
 *         , [1, 2]
 *     };
 */
typedef struct
{
    /*regBitField_t* pDivCtrlBitField;  TODO : fix auto-generation for pointer */
    regBitField_t pDivCtrlBitField;
    /**< Register bit-field info. If this filed is invalid, then this is a
         fixed divider and can be programmed. In this case the value
         pSupportedDivision[0] gives the fixed division value. */
    const uint8_t* pSupportedDivision;
    /**< Division factor of the divider. */
    const uint8_t* pDividerBitValue;
    /**< Bit field configuration value to achieve the above division. */
}prcmClockDivider_t;

/**
 *  \brief Structure defining the properties of multiplexer.
 *         The link to input clocks are part of the graph's edge property.
 */
typedef struct
{
    regBitField_t muxSelBitField;
    /**< Multiplexer configuration bit-field. */
}prcmMultiplexer_t;

/**
 *  \brief Structure defining the properties of pll post divider.
 */
typedef struct
{
    const prcmDpllPostDivId_t postDivId;
    /**< Unique Id of the post divider. */
    regBitField_t postDivBitField;
    /**< Divider configuration bit-field. */
}prcmDpllPostDiv_t;

/**
 *  Each PLL in the Soc has to be instantiated with the below data.
 */
typedef struct
{
    const uint32_t pllClkModeRegAddr;
    /**< Clock mode register address. It has configurations for bypass mode,
         clock ramp, auto-recalibration, low power mode, spread spectrum
         configuration etc... */
    const uint32_t pllIdleStatusRegAddr;
    /**< Idle state register address. It indicates the DPLL lock/unlock(bypass)
         status. */
    const uint32_t invalid; /* TODO  remove after fixing auto-gen */
    const uint32_t pllClkSelRegAddr;
    /**< Clock select register. It has configurations for DPLL multiplier,
         divider, duty cycle correction  and bypass clock selection
         configurations. */
    const uint32_t pllClkSel2RegAddr;
    /**< Clock select2 register. This register provides DPLL fractional
         multiplier factor control and BandWidth Control for PER DPLL. */
    const uint32_t pllSscDeltaMstepRegAddr;
    /**< Delta MStep register. It controls the DeltaMStep parameter which is
         used for Spread Spectrum Clocking technique. */
    const uint32_t pllSscModfreqDivRegAddr;
    /**< Modulation frequency divide register. It controls the Modulation
         Frequency (FM) for Spread Spectrum Clocking technique . */
    const uint32_t pllClkDcoLdoRegAddr;
    /**< CLKDCOLOD register address. It includes control and status for
         CLKDCOLDO configuration. */
    const uint32_t invmask; /* TODO  remove after fixing auto-gen */
    const uint32_t dpllType;
    /**< Indicates DPLL type - ADPLLS or ADPLLLJ. */
    const uint32_t pllModesSupportedMask;
    /**< Modes - bypass (including type) and lock mode. */
    prcmDpllPostDiv_t *postDividers;
    /**< List of post dividers available in this DPLL. */
    uint8_t postDividersMax;
    /**< Number of post dividers in this DPLL. */
    /*uint8_t isDccSupported;   TODO  include after fixing auto-gen */
    /**< Flag to indicate if duty cycle correction is supported. */
}prcmDpll_t;

/**
 *  Root clock configuration value.
 */
typedef struct
{
    const float supportedClockRate;
    /**< Clock rate in kHz */
    const uint8_t configValue;
    /**< Bit-field configuration value corresponding to above clock rate. */
}prcmRootClockValues_t;

/**
 *  Root clock fields to get the clock rate.
 */
typedef struct
{
    const uint32_t regAddr;
    /**< Root clock rate read register address */
    const uint32_t maskFreqSrc;
    /**< Root clock frequency source select shift */
    const uint32_t shiftFreqSrc;
    /**< Root clock frequency source select mask */
    const uint32_t maskFreqSel1;
    /**< Root clock frequency source1 shift */
    const uint32_t shiftFreqSel1;
    /**< Root clock frequency source1 mask */
    const uint32_t maskFreqSel2;
    /**< Root clock frequency source2 shift */
    const uint32_t shiftFreqSel2;
    /**< Root clock frequency source2 mask */
}regBitFieldRootClk_t;

/**
 *  \brief Structure defining the properties of the root clock.
 */
typedef struct
{
    const prcmRootClkType_t rootClkType;
    /**< Root clock type indicating fixed/configurable root clock. */
    const prcmRootClockValues_t *pClockRateConfig;
    /**< Supported clock rates and corresponding configuration value. */
    const regBitFieldRootClk_t* pClkCtrlBitField;
    /**< Register bit field to read the root clock. */
    /*uint8_t maxPossibleRates; TODO : Add in auto-generation */
    /**< Number of clock frequency values supported. */
}prcmRootClk_t;

/**
 *  \brief Structure defining the reset properties of a voltage domain. This
 *         is added for place holder to which Power domains can link to.
 */
typedef struct
{
    const prcmVdId_t vdId;
    /**< Voltage domain ID. */
}prcmVoltageDomain_t;

/**
 *  \brief Structure defining the reset properties of a power domain.
 *
 *  These parameters define the properties to configure the reset of a power
 *  domain.
 */
typedef struct
{
    regBitField_t rstCtrlBitField;
    /**< Reset control bit field. */
    regBitField_t rstStBitField;
    /**< Reset status bit field. */
}prcmReset_t;

/**
 *  \brief Structure defining the power domain properties.
 *
 *  These parameters define the properties of power domain and allow to
 *  configure PD to different states.
 */
typedef struct
{
    const prcmVdId_t vdId;
    /**< Voltage domain ID to which this power domain belongs to. */
    const uint32_t pwrStateCtrlRegAddr;
    /**< Power domain state control register address - ON/OFF/Retention */
    const uint32_t pwrStateStatusRegAddr;
    /**< Power domain state status register address - ON/OFF/Retention */
    const uint32_t pwrDownStatesMask;
    /**< Supported power down states mask */
    const prcmPhyMemId_t *phyMemoryId;
    /**< Memory present in the PD */
    const uint8_t numMemoryModules;
    /**< Number of memory elements present in the power domain. */
    const prcmResetId_t resetId;
    /**< Reset domain ID to which the power domain belongs to. */
}prcmPowerDomain_t;

/**
 *  \brief Structure defining the physical memory.
 *
 *  These parameters define the properties of the physical memory and allow to
 *  configure the memory state.
 */
typedef struct
{
    const uint32_t memOnState;
    /**< State of the memory when PD is in ON state */
    const uint32_t memRetState;
    /**< State of the memory when PD is in RET state */
    const uint32_t pwrOnStateCtrlShift;
    /**< Bit position for 'ON' state control in the Power state control
         register. The register offset is taken from the power domain info. */
    const uint32_t pwrRetStateCtrlShift;
    /**< Bit position for 'RET' state control in the Power state control
         register. The register offset is taken from the power domain info. */
}prcmPhysicalMemory_t;

/**
 *  \brief Structure defining the clock domain.
 *
 *  These parameters define the properties of the clock domain and enable
 *  clock domain control.
 */
typedef struct
{
    const prcmPdId_t powerDomainId;
    /**< Power domain ID to which clock domain belongs to. */
    const uint32_t clkStCtrlAddr;
    /**< Clock state(gated/ungated) status control register address. */
    uint32_t clkDomainCapability;
    /**< Bit map indicating the capability of the clock domain.
         It can take any of the values from #prcmClockDomainControl_t */
    const prcmModuleId_t* pFirstModPtr;
    /**< Pointer to module array which has list of modules belonging to this
         clock domain. */
    const uint8_t numModulesInCd;
    /**< Number of modules in the clock domain. */
    uint32_t enabledModCount;  /* TODO : remove after fixing in auto-generation. */
}prcmClkDomain_t;

/**
 *  \brief Structure defining the MODULE definition.
 *
 *  These parameters define the properties of a module and allow to configure,
 *  read status and traverse the tree.
 */
typedef struct
{
    const prcmCdId_t clockDomainId;
    /**< Clock domain ID to which this module belongs to. */
    const prcmRetentionType_t retentionType;
    /**< Module retention type. */
    const uint32_t clkCtrlRegAddr;
    /**< Clock mode register address. */
    const uint32_t minOpp; /* TODO : Talk to Akshay on how to get this info. */
    /**< Min Device level OPP at which this module can operate. This will be
         used for core OPP transitions. */
    const prcmClockId_t *funcClkId;
    /**< List of functional clock's belonging to this module. */
    const prcmClockId_t *optClkId;
    /**< List of optional clock's belonging to this module. */
    const uint8_t maxFuncClock;
    /**< Number of functional clocks. */
    const uint8_t maxOptionalClock;
    /**< Number of optional clocks. */
    const uint8_t isStandbySuported;
    /**< Flag indicating whether standby protocol is supported for this
         module. */
    const uint8_t moduleMode;
    /**< Bit map indicating the capability of module - Enable, disable,
         automatic. It can take any of the values from #prcmModuleMode_t. */

    /* TODO: The following fields are NA in some devices. Need to check if we
       can group such fields under conditional compilation to save memory of
       devices which don't need them.
       - Static and dynamic dependency
       - Wakeup dependencies (reg, mask, shift ?)
       - Context register
    */
}prcmModule_t;

/* ========================================================================== */
/*                        Global Variables Declarations                       */
/* ========================================================================== */
extern agraph prcmGraph;

/* Need to review this change. */
extern const prcmClkDomain_t prcmClockDomainElems[];
#ifdef __cplusplus
extern const prcmModule_t prcmModuleElems[];
extern const prcmPowerDomain_t prcmPowerDomainElems[];
#endif

extern const chipdbResourceIdInfo_t resourceIdModuleIdInstMap[];

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/**
 * \brief     Get the PRCM ModuleId, given the Module-Instance ResourceId
 *
 * \param[in] resourceId Resource ID of module-instance pair
 *
 * \retval    Module ID in PRCM domain
 */
prcmModuleId_t PRCMGetModuleId(moduleInstanceId_t resourceId);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* HW_PRCM_DATA_H */
