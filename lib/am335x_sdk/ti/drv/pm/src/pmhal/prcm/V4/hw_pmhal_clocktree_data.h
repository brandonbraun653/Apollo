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
 *  \file      hw_pmhal_clocktree_data.h
 *
 *  \brief     This file contains macros and data-structures pertaining to
 *              StarterWare PRCM (internal) clocktree implementation.
 *
 *  \warning   This file is auto generated. So avoid manual changes.
 *              If manual changes are required the implications of the
 *              change in this and other auto generated files has to be
 *              completely understood.
 */

#ifndef HW_PMHAL_CLOCKTREE_DATA_H_
#define HW_PMHAL_CLOCKTREE_DATA_H_

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#include "pmhal_clocktree.h"
#include "pmhal_prcm.h"

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/**
 * \brief Clock-tree Edge Availble Clock Nodes
 */
typedef enum pmhalEdgeNodes
{
    PMHAL_EDGE_LOWER_BOUND = -1,
    /**< Lower bound Place Holder(inclusive) */
    PMHAL_EDGE_DPLL_PER,
    /**< PM HAL Dpll Element PER */
    PMHAL_EDGE_DPLL_MPU,
    /**< PM HAL Dpll Element MPU */
    PMHAL_EDGE_DPLL_DDR,
    /**< PM HAL Dpll Element DDR */
    PMHAL_EDGE_DPLL_DISP,
    /**< PM HAL Dpll Element DISP */
    PMHAL_EDGE_DPLL_CORE,
    /**< PM HAL Dpll Element CORE */
    PMHAL_EDGE_DPLL_EXTDEV,
    /**< PM HAL Dpll Element EXTDEV */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    PMHAL_EDGE_MOD_CPGMAC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA
    PMHAL_EDGE_MOD_CRYPTODMA,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    PMHAL_EDGE_MOD_DCAN0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    PMHAL_EDGE_MOD_DCAN1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    PMHAL_EDGE_MOD_DSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    PMHAL_EDGE_MOD_EMIF,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    PMHAL_EDGE_MOD_GPIO1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    PMHAL_EDGE_MOD_GPIO2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    PMHAL_EDGE_MOD_GPIO3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    PMHAL_EDGE_MOD_GPIO4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    PMHAL_EDGE_MOD_GPIO5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_HDQ1W
    PMHAL_EDGE_MOD_HDQ1W,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    PMHAL_EDGE_MOD_I2C1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    PMHAL_EDGE_MOD_I2C2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    PMHAL_EDGE_MOD_ICSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    PMHAL_EDGE_MOD_L3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
    PMHAL_EDGE_MOD_L4FW,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    PMHAL_EDGE_MOD_LCDC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
    PMHAL_EDGE_MOD_MAG_CARD,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    PMHAL_EDGE_MOD_MCASP0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    PMHAL_EDGE_MOD_MCASP1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    PMHAL_EDGE_MOD_MMC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    PMHAL_EDGE_MOD_MMC1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    PMHAL_EDGE_MOD_MMC2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC
    PMHAL_EDGE_MOD_OCP_WP_NOC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    PMHAL_EDGE_MOD_QSPI,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    PMHAL_EDGE_MOD_SPI0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    PMHAL_EDGE_MOD_SPI1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    PMHAL_EDGE_MOD_SPI2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    PMHAL_EDGE_MOD_SPI3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
    PMHAL_EDGE_MOD_SPI4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER10
    PMHAL_EDGE_MOD_TIMER10,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER11
    PMHAL_EDGE_MOD_TIMER11,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    PMHAL_EDGE_MOD_TIMER2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    PMHAL_EDGE_MOD_TIMER3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    PMHAL_EDGE_MOD_TIMER4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    PMHAL_EDGE_MOD_TIMER5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    PMHAL_EDGE_MOD_TIMER6,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    PMHAL_EDGE_MOD_TIMER7,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER8
    PMHAL_EDGE_MOD_TIMER8,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER9
    PMHAL_EDGE_MOD_TIMER9,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    PMHAL_EDGE_MOD_UART1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    PMHAL_EDGE_MOD_UART2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    PMHAL_EDGE_MOD_UART3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
    PMHAL_EDGE_MOD_UART4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
    PMHAL_EDGE_MOD_UART5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0
    PMHAL_EDGE_MOD_USB_OTG_SS0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1
    PMHAL_EDGE_MOD_USB_OTG_SS1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM0
    PMHAL_EDGE_MOD_USIM0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM1
    PMHAL_EDGE_MOD_USIM1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
    PMHAL_EDGE_MOD_VPFE0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
    PMHAL_EDGE_MOD_VPFE1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    PMHAL_EDGE_MOD_GFX,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    PMHAL_EDGE_MOD_ADC_TSC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    PMHAL_EDGE_MOD_DEBUGSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    PMHAL_EDGE_MOD_GPIO0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    PMHAL_EDGE_MOD_I2C0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
    PMHAL_EDGE_MOD_SMARTREFLEX0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
    PMHAL_EDGE_MOD_SMARTREFLEX1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
    PMHAL_EDGE_MOD_SYNCTIMER,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    PMHAL_EDGE_MOD_TIMER0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    PMHAL_EDGE_MOD_TIMER1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
    PMHAL_EDGE_MOD_UART0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    PMHAL_EDGE_MOD_WDT0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
    PMHAL_EDGE_MOD_WDT1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
    PMHAL_EDGE_MOD_CEFUSE,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    PMHAL_EDGE_MOD_RTCSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
    PMHAL_EDGE_MOD_COUNT,
    /**< Enum Upper bound placeholder */
    PMHAL_EDGE_UNDEF
    /**< Undefined value */
} pmhalEdgeNodes_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

extern pmhalClockTree pmhalPrcmGraph;

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif /* HW_PMHAL_DATA_H_ */
