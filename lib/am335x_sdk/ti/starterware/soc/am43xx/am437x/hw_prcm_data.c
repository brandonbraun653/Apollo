/**
 *  \file      hw_prcm_data.c
 *
 *  \brief     This file contains macros and data-structures pertaining to
 *              StarterWare PRCM (internal) implementation.
 *              
 *  \warning   This file is auto generated. So avoid manual changes. 
 *              If manual changes are required the implications of the 
 *              change in this and other auto generated files has to be 
 *              completely understood.
 */

/* Copyright (c) 2013-2018 Texas Instruments Inc - http://www.ti.com */

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

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include "hw_prcm_data.h"
#include "am437x.h"


/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */
#define VSIZE_TYPE(vec, type) (sizeof(vec)/sizeof(type))

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */
typedef struct {
  moduleInstanceId_t  resId;
  prcmModuleId_t      modId;
} resourceIdModuleIdPair_t;


CATTR(prcmVoltageDomainElems)
const prcmVoltageDomain_t prcmVoltageDomainElems[] = 
{
    { /* PRCM_VD_CORE */
        PRCM_VD_CORE,
    },
    { /* PRCM_VD_MPU */
        PRCM_VD_MPU,
    },
    { /* PRCM_VD_RTC */
        PRCM_VD_RTC,
    },
    { /* PRCM_VD_TAMPER */
        PRCM_VD_TAMPER,
    },

};

/*----------------------------------------------------------------------------*/ 
CATTR(phyMemIdList)
const prcmPhyMemId_t PRCM_PD_GFX_phyMemIdList[] = 
{
    PRCM_PHY_MEM_GFX, 
};

CATTR(phyMemIdList)
const prcmPhyMemId_t PRCM_PD_MPU_phyMemIdList[] = 
{
    PRCM_PHY_MEM_MPU_L1, 
    PRCM_PHY_MEM_MPU_L2, 
    PRCM_PHY_MEM_MPU_RAM, 
};

CATTR(phyMemIdList)
const prcmPhyMemId_t PRCM_PD_PER_phyMemIdList[] = 
{
    PRCM_PHY_MEM_DSSMEM, 
    PRCM_PHY_MEM_UART, 
    PRCM_PHY_MEM_BANK1, 
    PRCM_PHY_MEM_BANK2, 
    PRCM_PHY_MEM_DMEM0, 
    PRCM_PHY_MEM_DMEM1, 
    PRCM_PHY_MEM_DMEM2, 
    PRCM_PHY_MEM_DMEM3, 
    PRCM_PHY_MEM_IMEM0, 
    PRCM_PHY_MEM_IMEM1, 
    PRCM_PHY_MEM_IMEM2, 
    PRCM_PHY_MEM_IMEM3, 
    PRCM_PHY_MEM_PRUSS0_MEM, 
    PRCM_PHY_MEM_PRUSS1_MEM, 
    PRCM_PHY_MEM_LCD_CORE_PALETTE_RAM, 
    PRCM_PHY_MEM_LCD_DMA_FIFO_RAM, 
    PRCM_PHY_MEM_MEMORYBANKNONAME, 
    PRCM_PHY_MEM_MBOXSRAM, 
    PRCM_PHY_MEM_MSHSI2COCP_MEMORY, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_CPPI, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ADDR, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_DB, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_INFO, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ST, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_STATE, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_STATISTICS, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_DB, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_INFO, 
    PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_ST, 
    PRCM_PHY_MEM_DMA_CRYPTO, 
    PRCM_PHY_MEM_PKA_MEM, 
    PRCM_PHY_MEM_USB, 
    PRCM_PHY_MEM_WB0, 
    PRCM_PHY_MEM_WB1, 
};

CATTR(phyMemIdList)
const prcmPhyMemId_t PRCM_PD_WKUP_phyMemIdList[] = 
{
    PRCM_PHY_MEM_DEBUGSS, 
};



CATTR(prcmPowerDomainElems) 
const prcmPowerDomain_t prcmPowerDomainElems[] = 
{
    { /* PRCM_PD_CUST_EFUSE */
        PRCM_VD_CORE,
        (SOC_PRM_CEFUSE_REG + PRCM_PM_CEFUSE_PWRSTCTRL),
        (SOC_PRM_CEFUSE_REG + PRCM_PM_CEFUSE_PWRSTST),
        (PRCM_PM_CEFUSE_PWRSTCTRL_POWERSTATE_MASK),
        NULL,
        0,
        PRCM_RST_MIN,
    },
    { /* PRCM_PD_GFX */
        PRCM_VD_CORE,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_BITFIELD,
        PRCM_PD_GFX_phyMemIdList,
        VSIZE_TYPE(PRCM_PD_GFX_phyMemIdList, prcmPhyMemId_t),
        PRCM_RST_MIN,
    },
    { /* PRCM_PD_MPU */
        PRCM_VD_MPU,
        (SOC_PRM_MPU_REG + PRCM_PM_MPU_PWRSTCTRL),
        (SOC_PRM_MPU_REG + PRCM_PM_MPU_PWRSTST),
        (PRCM_PM_MPU_PWRSTCTRL_POWERSTATE_MASK),
        PRCM_PD_MPU_phyMemIdList,
        VSIZE_TYPE(PRCM_PD_MPU_phyMemIdList, prcmPhyMemId_t),
        PRCM_RST_MIN,
    },
    { /* PRCM_PD_PER */
        PRCM_VD_CORE,
        (SOC_PRM_PER_REG + PRCM_PM_PER_PWRSTCTRL),
        (SOC_PRM_PER_REG + PRCM_PM_PER_PWRSTST),
        (PRCM_PM_PER_PWRSTCTRL_POWERSTATE_MASK),
        PRCM_PD_PER_phyMemIdList,
        VSIZE_TYPE(PRCM_PD_PER_phyMemIdList, prcmPhyMemId_t),
        PRCM_RST_MIN,
    },
    { /* PRCM_PD_RTC */
        PRCM_VD_RTC,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_BITFIELD,
        NULL,
        0,
        PRCM_RST_MIN,
    },
    { /* PRCM_PD_STD_EFUSE */
        PRCM_VD_CORE,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_BITFIELD,
        NULL,
        0,
        PRCM_RST_MIN,
    },
    { /* PRCM_PD_TAMPER */
        PRCM_VD_TAMPER,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_BITFIELD,
        NULL,
        0,
        PRCM_RST_MIN,
    },
    { /* PRCM_PD_WKUP */
        PRCM_VD_CORE,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_BITFIELD,
        PRCM_PD_WKUP_phyMemIdList,
        VSIZE_TYPE(PRCM_PD_WKUP_phyMemIdList, prcmPhyMemId_t),
        PRCM_RST_MIN,
    },

};

/*----------------------------------------------------------------------------*/ 
CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_CEFUSE_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_CEFUSE
    PRCM_MOD_CEFUSE,
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_GFX_L3_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_GFX
    PRCM_MOD_GFX,
#endif /* BUILDCFG_PRCM_MOD_GFX */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_MPU_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_MPU
    PRCM_MOD_MPU,
#endif /* BUILDCFG_PRCM_MOD_MPU */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_L3_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_DDRPHY
    PRCM_MOD_DDRPHY,
#endif /* BUILDCFG_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PRCM_MOD_DLL
    PRCM_MOD_DLL,
#endif /* BUILDCFG_PRCM_MOD_DLL */
#ifdef BUILDCFG_PRCM_MOD_DLL_AGING
    PRCM_MOD_DLL_AGING,
#endif /* BUILDCFG_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
    PRCM_MOD_OCMCRAM,
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_L3
    PRCM_MOD_L3,
#endif /* BUILDCFG_PRCM_MOD_L3 */
#ifdef BUILDCFG_PRCM_MOD_L3_INSTR
    PRCM_MOD_L3_INSTR,
#endif /* BUILDCFG_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PRCM_MOD_L4FW
    PRCM_MOD_L4FW,
#endif /* BUILDCFG_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PRCM_MOD_L4_HS
    PRCM_MOD_L4_HS,
#endif /* BUILDCFG_PRCM_MOD_L4_HS */
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
#ifdef BUILDCFG_PRCM_MOD_AES0
    PRCM_MOD_AES0,
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
    PRCM_MOD_CRYPTODMA,
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
    PRCM_MOD_DES,
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_SHA0
    PRCM_MOD_SHA0,
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
    PRCM_MOD_VPFE0,
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
    PRCM_MOD_VPFE1,
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_CPSW_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
    PRCM_MOD_CPGMAC0,
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_DSS_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_DSS
    PRCM_MOD_DSS,
#endif /* BUILDCFG_PRCM_MOD_DSS */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_ICSS_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_ICSS
    PRCM_MOD_ICSS,
#endif /* BUILDCFG_PRCM_MOD_ICSS */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_L3S_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_GPMC
    PRCM_MOD_GPMC,
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_MMC2
    PRCM_MOD_MMC2,
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
    PRCM_MOD_MAG_CARD,
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PRCM_MOD_IEEE5000
    PRCM_MOD_IEEE5000,
#endif /* BUILDCFG_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
    PRCM_MOD_MCASP0,
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
    PRCM_MOD_QSPI,
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_MCASP1
    PRCM_MOD_MCASP1,
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
    PRCM_MOD_USB_OTG_SS0,
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
    PRCM_MOD_USB_OTG_SS1,
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_L4LS_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
    PRCM_MOD_EMIF_FW,
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_MMC0
    PRCM_MOD_MMC0,
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
    PRCM_MOD_MMC1,
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
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
#ifdef BUILDCFG_PRCM_MOD_L4LS
    PRCM_MOD_L4LS,
#endif /* BUILDCFG_PRCM_MOD_L4LS */
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
#ifdef BUILDCFG_PRCM_MOD_MAILBOX0
    PRCM_MOD_MAILBOX0,
#endif /* BUILDCFG_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE0
    PRCM_MOD_SPARE0,
#endif /* BUILDCFG_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE1
    PRCM_MOD_SPARE1,
#endif /* BUILDCFG_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
    PRCM_MOD_SPINLOCK,
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_PKA
    PRCM_MOD_PKA,
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_RNG
    PRCM_MOD_RNG,
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
    PRCM_MOD_USBPHYOCP2SCP0,
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
    PRCM_MOD_USBPHYOCP2SCP1,
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
    PRCM_MOD_USIM0,
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
    PRCM_MOD_USIM1,
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_LCDC_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_LCDC
    PRCM_MOD_LCDC,
#endif /* BUILDCFG_PRCM_MOD_LCDC */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_PER_OCPWP_L3_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
    PRCM_MOD_OCP_WP_NOC,
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_RTC_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_RTC
    PRCM_MOD_RTC,
#endif /* BUILDCFG_PRCM_MOD_RTC */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_STD_EFUSE_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_EFUSE
    PRCM_MOD_EFUSE,
#endif /* BUILDCFG_PRCM_MOD_EFUSE */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_TAMPER_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_TPMSS
    PRCM_MOD_TPMSS,
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_L4_WKUP_AON_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
    PRCM_MOD_USB_PHY0_ALWAYS_ON,
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
    PRCM_MOD_USB_PHY1_ALWAYS_ON,
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
    PRCM_MOD_CLKDIV32K,
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PRCM_MOD_L4WKUP
    PRCM_MOD_L4WKUP,
#endif /* BUILDCFG_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
    PRCM_MOD_SYNCTIMER,
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
    PRCM_MOD_WKUP_M3,
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_L3S_TSC_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
    PRCM_MOD_ADC_TSC,
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_L3_AON_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
    PRCM_MOD_DEBUGSS,
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
};

CATTR(clockDomainModuleList)
const prcmModuleId_t PRCM_CD_WKUP_modules [] = 
{
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
    PRCM_MOD_SMARTREFLEX0,
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
    PRCM_MOD_SMARTREFLEX1,
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_WDT0
    PRCM_MOD_WDT0,
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
    PRCM_MOD_WDT1,
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
    PRCM_MOD_CONTROL,
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
    PRCM_MOD_GPIO0,
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
    PRCM_MOD_I2C0,
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
    PRCM_MOD_TIMER0,
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
    PRCM_MOD_TIMER1,
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_UART0
    PRCM_MOD_UART0,
#endif /* BUILDCFG_PRCM_MOD_UART0 */
};


CATTR(prcmClockDomainElems)
const prcmClkDomain_t prcmClockDomainElems[] = 
{
    { /* PRCM_CD_CEFUSE */
        PRCM_PD_CUST_EFUSE,
        (SOC_CM_CEFUSE_REG + PRCM_CM_CEFUSE_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_SW_SLEEP | PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_CEFUSE_modules,
        VSIZE_TYPE(PRCM_CD_CEFUSE_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_GFX_L3 */
        PRCM_PD_GFX,
        (SOC_CM_GFX_REG + PRCM_CM_GFX_L3_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_SW_SLEEP | PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_GFX_L3_modules,
        VSIZE_TYPE(PRCM_CD_GFX_L3_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_MPU */
        PRCM_PD_MPU,
        (SOC_CM_MPU_REG + PRCM_CM_MPU_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_HW_AUTO | PRCM_CD_CLK_TRANS_SW_SLEEP | PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_MPU_modules,
        VSIZE_TYPE(PRCM_CD_MPU_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_L3 */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_L3_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_PER_L3_modules,
        VSIZE_TYPE(PRCM_CD_PER_L3_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_CPSW */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_CPSW_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_SW_SLEEP | PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_PER_CPSW_modules,
        VSIZE_TYPE(PRCM_CD_PER_CPSW_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_EMIF */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_EMIF_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        NULL,
        0,
        0,
    },
    { /* PRCM_CD_PER_DSS */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_DSS_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_PER_DSS_modules,
        VSIZE_TYPE(PRCM_CD_PER_DSS_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_ICSS */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_ICSS_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_SW_SLEEP | PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_PER_ICSS_modules,
        VSIZE_TYPE(PRCM_CD_PER_ICSS_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_L3S */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_L3S_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_SW_SLEEP | PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_PER_L3S_modules,
        VSIZE_TYPE(PRCM_CD_PER_L3S_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_L4LS */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_L4LS_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_PER_L4LS_modules,
        VSIZE_TYPE(PRCM_CD_PER_L4LS_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_LCDC */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_LCDC_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_SW_SLEEP | PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_PER_LCDC_modules,
        VSIZE_TYPE(PRCM_CD_PER_LCDC_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_PER_OCPWP_L3 */
        PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_OCPWP_L3_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_PER_OCPWP_L3_modules,
        VSIZE_TYPE(PRCM_CD_PER_OCPWP_L3_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_RTC */
        PRCM_PD_RTC,
        (SOC_CM_RTC_REG + PRCM_CM_RTC_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_RTC_modules,
        VSIZE_TYPE(PRCM_CD_RTC_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_STD_EFUSE */
        PRCM_PD_STD_EFUSE,
        PRCM_INVALID_REGADDR,
        PRCM_CD_CLK_TRANS_NO_SLEEP,
        PRCM_CD_STD_EFUSE_modules,
        VSIZE_TYPE(PRCM_CD_STD_EFUSE_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_TAMPER */
        PRCM_PD_TAMPER,
        (SOC_CM_TAMPER_REG + PRCM_CM_TAMPER_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_TAMPER_modules,
        VSIZE_TYPE(PRCM_CD_TAMPER_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_L4_WKUP_AON */
        PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_L4_WKUP_AON_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP),
        PRCM_CD_L4_WKUP_AON_modules,
        VSIZE_TYPE(PRCM_CD_L4_WKUP_AON_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_L3S_TSC */
        PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_L3S_TSC_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_L3S_TSC_modules,
        VSIZE_TYPE(PRCM_CD_L3S_TSC_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_L3_AON */
        PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_L3_AON_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_L3_AON_modules,
        VSIZE_TYPE(PRCM_CD_L3_AON_modules, prcmModuleId_t),
        0,
    },
    { /* PRCM_CD_WKUP */
        PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_CLKSTCTRL),
        (PRCM_CD_CLK_TRANS_NO_SLEEP | PRCM_CD_CLK_TRANS_SW_SLEEP),
        PRCM_CD_WKUP_modules,
        VSIZE_TYPE(PRCM_CD_WKUP_modules, prcmModuleId_t),
        0,
    },

};

/*----------------------------------------------------------------------------*/ 
CATTR(prcmDpllElems)
const prcmDpll_t prcmDpllElems[] = 
{
    { /* PRCM_DPLL_CORE */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_CORE),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_CORE),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_CORE),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_CORE),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_CORE),
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_MASK,
        (PRCM_DPLL_BYP_MODE_LP_BYP_MODE | PRCM_DPLL_BYP_MODE_LOCK_MODE | PRCM_DPLL_BYP_MODE_FR_BYP_MODE | PRCM_DPLL_BYP_MODE_MN_BYP_MODE),
        PRCM_DPLL_TYPE_ADPLLS,
        NULL/* \todo postDividers[] */,
        0/* \todo postDividersMax */,
    },
    { /* PRCM_DPLL_DDR */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DDR),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DDR),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DDR),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_DDR),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_DDR),
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_MASK,
        (PRCM_DPLL_BYP_MODE_MN_BYP_MODE | PRCM_DPLL_BYP_MODE_LP_BYP_MODE | PRCM_DPLL_BYP_MODE_FR_BYP_MODE | PRCM_DPLL_BYP_MODE_LOCK_MODE),
        PRCM_DPLL_TYPE_ADPLLS,
        NULL/* \todo postDividers[] */,
        0/* \todo postDividersMax */,
    },
    { /* PRCM_DPLL_DISP */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DISP),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DISP),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DISP),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_DISP),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_DISP),
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_MASK,
        (PRCM_DPLL_BYP_MODE_LOCK_MODE | PRCM_DPLL_BYP_MODE_FR_BYP_MODE | PRCM_DPLL_BYP_MODE_LP_BYP_MODE | PRCM_DPLL_BYP_MODE_MN_BYP_MODE),
        PRCM_DPLL_TYPE_ADPLLS,
        NULL/* \todo postDividers[] */,
        0/* \todo postDividersMax */,
    },
    { /* PRCM_DPLL_EXTDEV */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_EXTDEV),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL2_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_EXTDEV),
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_MASK,
        (PRCM_DPLL_BYP_MODE_LOCK_MODE | PRCM_DPLL_BYP_MODE_LP_BYP_MODE | PRCM_DPLL_BYP_MODE_MN_BYP_MODE),
        PRCM_DPLL_TYPE_ADPLLLJ,
        NULL/* \todo postDividers[] */,
        0/* \todo postDividersMax */,
    },
    { /* PRCM_DPLL_MPU */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_MPU),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_MPU),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_MPU),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_MPU),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_MPU),
        PRCM_INVALID_REGADDR,
        PRCM_INVALID_MASK,
        (PRCM_DPLL_BYP_MODE_MN_BYP_MODE | PRCM_DPLL_BYP_MODE_LOCK_MODE | PRCM_DPLL_BYP_MODE_FR_BYP_MODE | PRCM_DPLL_BYP_MODE_LP_BYP_MODE),
        PRCM_DPLL_TYPE_ADPLLS,
        NULL/* \todo postDividers[] */,
        0/* \todo postDividersMax */,
    },
    { /* PRCM_DPLL_PER */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_PER),
        PRCM_INVALID_REGADDR,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL2_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_CLKDCOLDO_DPLL_PER),
        PRCM_INVALID_MASK,
        (PRCM_DPLL_BYP_MODE_LP_BYP_MODE | PRCM_DPLL_BYP_MODE_LOCK_MODE | PRCM_DPLL_BYP_MODE_MN_BYP_MODE),
        PRCM_DPLL_TYPE_ADPLLLJ,
        NULL/* \todo postDividers[] */,
        0/* \todo postDividersMax */,
    },

};

/*----------------------------------------------------------------------------*/ 
#ifdef BUILDCFG_PRCM_MOD_CEFUSE
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_CEFUSE_funcClkMandatory[] = 
{
    PRCM_CLK_CUST_EFUSE_SYSCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */

#ifdef BUILDCFG_PRCM_MOD_DSS
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_DSS_funcClkMandatory[] = 
{
    PRCM_CLK_DSS_GCLK, 
    PRCM_CLK_DSS_SYSCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_DSS */

#ifdef BUILDCFG_PRCM_MOD_MMC0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_MMC0_funcClkMandatory[] = 
{
    PRCM_CLK_MMC_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_MMC0 */

#ifdef BUILDCFG_PRCM_MOD_MMC1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_MMC1_funcClkMandatory[] = 
{
    PRCM_CLK_MMC_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_MMC1 */

#ifdef BUILDCFG_PRCM_MOD_MMC2
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_MMC2_funcClkMandatory[] = 
{
    PRCM_CLK_MMC_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_MMC2 */

#ifdef BUILDCFG_PRCM_MOD_GFX
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_GFX_funcClkMandatory[] = 
{
    PRCM_CLK_GFX_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_GFX */

#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_MAG_CARD_funcClkMandatory[] = 
{
    PRCM_CLK_MGC_FGCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */

#ifdef BUILDCFG_PRCM_MOD_ICSS
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_ICSS_funcClkMandatory[] = 
{
    PRCM_CLK_ICSS_IEP_GCLK, 
    PRCM_CLK_ICSS_UART_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_ICSS */

#ifdef BUILDCFG_PRCM_MOD_LCDC
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_LCDC_funcClkMandatory[] = 
{
    PRCM_CLK_LCD_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_LCDC */

#ifdef BUILDCFG_PRCM_MOD_DCAN0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_DCAN0_funcClkMandatory[] = 
{
    PRCM_CLK_CAN_CLK, 
};
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */

#ifdef BUILDCFG_PRCM_MOD_DCAN1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_DCAN1_funcClkMandatory[] = 
{
    PRCM_CLK_CAN_CLK, 
};
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */

#ifdef BUILDCFG_PRCM_MOD_HDQ1W
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_HDQ1W_funcClkMandatory[] = 
{
    PRCM_CLK_HDQ1W_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */

#ifdef BUILDCFG_PRCM_MOD_I2C1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_I2C1_funcClkMandatory[] = 
{
    PRCM_CLK_I2C_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_I2C1 */

#ifdef BUILDCFG_PRCM_MOD_I2C2
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_I2C2_funcClkMandatory[] = 
{
    PRCM_CLK_I2C_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_I2C2 */

#ifdef BUILDCFG_PRCM_MOD_MCASP0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_MCASP0_funcClkMandatory[] = 
{
    PRCM_CLK_MCASP_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */

#ifdef BUILDCFG_PRCM_MOD_QSPI
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_QSPI_funcClkMandatory[] = 
{
    PRCM_CLK_SPI_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_QSPI */

#ifdef BUILDCFG_PRCM_MOD_SPI0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_SPI0_funcClkMandatory[] = 
{
    PRCM_CLK_SPI_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SPI0 */

#ifdef BUILDCFG_PRCM_MOD_SPI1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_SPI1_funcClkMandatory[] = 
{
    PRCM_CLK_SPI_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SPI1 */

#ifdef BUILDCFG_PRCM_MOD_SPI2
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_SPI2_funcClkMandatory[] = 
{
    PRCM_CLK_SPI_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SPI2 */

#ifdef BUILDCFG_PRCM_MOD_SPI3
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_SPI3_funcClkMandatory[] = 
{
    PRCM_CLK_SPI_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SPI3 */

#ifdef BUILDCFG_PRCM_MOD_SPI4
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_SPI4_funcClkMandatory[] = 
{
    PRCM_CLK_SPI_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SPI4 */

#ifdef BUILDCFG_PRCM_MOD_TIMER10
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER10_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER10_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */

#ifdef BUILDCFG_PRCM_MOD_TIMER11
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER11_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER11_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */

#ifdef BUILDCFG_PRCM_MOD_TIMER2
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER2_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER2_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */

#ifdef BUILDCFG_PRCM_MOD_TIMER3
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER3_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER3_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */

#ifdef BUILDCFG_PRCM_MOD_TIMER4
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER4_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER4_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */

#ifdef BUILDCFG_PRCM_MOD_TIMER5
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER5_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER5_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */

#ifdef BUILDCFG_PRCM_MOD_TIMER6
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER6_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER6_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */

#ifdef BUILDCFG_PRCM_MOD_TIMER7
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER7_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER7_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */

#ifdef BUILDCFG_PRCM_MOD_TIMER8
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER8_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER8_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */

#ifdef BUILDCFG_PRCM_MOD_TIMER9
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER9_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER9_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */

#ifdef BUILDCFG_PRCM_MOD_UART1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_UART1_funcClkMandatory[] = 
{
    PRCM_CLK_UART_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_UART1 */

#ifdef BUILDCFG_PRCM_MOD_UART2
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_UART2_funcClkMandatory[] = 
{
    PRCM_CLK_UART_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_UART2 */

#ifdef BUILDCFG_PRCM_MOD_UART3
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_UART3_funcClkMandatory[] = 
{
    PRCM_CLK_UART_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_UART3 */

#ifdef BUILDCFG_PRCM_MOD_UART4
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_UART4_funcClkMandatory[] = 
{
    PRCM_CLK_UART_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_UART4 */

#ifdef BUILDCFG_PRCM_MOD_UART5
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_UART5_funcClkMandatory[] = 
{
    PRCM_CLK_UART_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_UART5 */

#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_CPGMAC0_funcClkMandatory[] = 
{
    PRCM_CLK_CPSW_CPTS_RFT_CLK, 
    PRCM_CLK_CPSW_250MHZ_CLK, 
    PRCM_CLK_CPSW_5MHZ_CLK, 
    PRCM_CLK_CPSW_50MHZ_CLK, 
};
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */

#ifdef BUILDCFG_PRCM_MOD_MCASP1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_MCASP1_funcClkMandatory[] = 
{
    PRCM_CLK_MCASP_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */

#ifdef BUILDCFG_PRCM_MOD_MPU
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_MPU_funcClkMandatory[] = 
{
    PRCM_CLK_MPU_CLK, 
};
#endif /* BUILDCFG_PRCM_MOD_MPU */

#ifdef BUILDCFG_PRCM_MOD_RTC
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_RTC_funcClkMandatory[] = 
{
    PRCM_CLK_RTC_32KCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_RTC */

#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_SMARTREFLEX0_funcClkMandatory[] = 
{
    PRCM_CLK_SR_SYSCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */

#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_SMARTREFLEX1_funcClkMandatory[] = 
{
    PRCM_CLK_SR_SYSCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */

#ifdef BUILDCFG_PRCM_MOD_WDT0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_WDT0_funcClkMandatory[] = 
{
    PRCM_CLK_WDT0_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_WDT0 */

#ifdef BUILDCFG_PRCM_MOD_WDT1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_WDT1_funcClkMandatory[] = 
{
    PRCM_CLK_WDT1_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_WDT1 */

#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_ADC_TSC_funcClkMandatory[] = 
{
    PRCM_CLK_ADC_FCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */

#ifdef BUILDCFG_PRCM_MOD_I2C0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_I2C0_funcClkMandatory[] = 
{
    PRCM_CLK_I2C0_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_I2C0 */

#ifdef BUILDCFG_PRCM_MOD_TIMER0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER0_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER0_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */

#ifdef BUILDCFG_PRCM_MOD_TIMER1
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_TIMER1_funcClkMandatory[] = 
{
    PRCM_CLK_TIMER1_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */

#ifdef BUILDCFG_PRCM_MOD_UART0
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_UART0_funcClkMandatory[] = 
{
    PRCM_CLK_UART0_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_UART0 */

#ifdef BUILDCFG_PRCM_MOD_EFUSE
CATTR(funcClkMandatory)
const prcmClockId_t PRCM_MOD_EFUSE_funcClkMandatory[] = 
{
    PRCM_CLK_STD_EFUSE_SYSCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_EFUSE */



#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_DEBUGSS_funcClkOptional[] = 
{
    PRCM_CLK_DEBUG_CLKA_GCLK, 
    PRCM_CLK_DEBUG_CLKB_GCLK, 
    PRCM_CLK_DEBUG_CLKC_GCLK, 
    PRCM_CLK_DBGSYSCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */

#ifdef BUILDCFG_PRCM_MOD_GPIO1
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_GPIO1_funcClkOptional[] = 
{
    PRCM_CLK_GPIO_1_GDBCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */

#ifdef BUILDCFG_PRCM_MOD_GPIO2
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_GPIO2_funcClkOptional[] = 
{
    PRCM_CLK_GPIO_2_GDBCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */

#ifdef BUILDCFG_PRCM_MOD_GPIO3
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_GPIO3_funcClkOptional[] = 
{
    PRCM_CLK_GPIO_3_GDBCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */

#ifdef BUILDCFG_PRCM_MOD_GPIO4
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_GPIO4_funcClkOptional[] = 
{
    PRCM_CLK_GPIO_4_GDBCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */

#ifdef BUILDCFG_PRCM_MOD_GPIO5
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_GPIO5_funcClkOptional[] = 
{
    PRCM_CLK_GPIO_5_GDBCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */

#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_USB_PHY0_ALWAYS_ON_funcClkOptional[] = 
{
    PRCM_CLK_USBPHY_32KHZ_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */

#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_USB_PHY1_ALWAYS_ON_funcClkOptional[] = 
{
    PRCM_CLK_USBPHY_32KHZ_GCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */

#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_USB_OTG_SS0_funcClkOptional[] = 
{
    PRCM_CLK_USB_PLL_CLK, 
};
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */

#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_USB_OTG_SS1_funcClkOptional[] = 
{
    PRCM_CLK_USB_PLL_CLK, 
};
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */

#ifdef BUILDCFG_PRCM_MOD_USIM0
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_USIM0_funcClkOptional[] = 
{
    PRCM_CLK_USIM0_FCLK, 
    PRCM_CLK_USIM0_FCLK32, 
};
#endif /* BUILDCFG_PRCM_MOD_USIM0 */

#ifdef BUILDCFG_PRCM_MOD_USIM1
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_USIM1_funcClkOptional[] = 
{
    PRCM_CLK_USIM1_FCLK, 
    PRCM_CLK_USIM1_FCLK32, 
};
#endif /* BUILDCFG_PRCM_MOD_USIM1 */

#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_CLKDIV32K_funcClkOptional[] = 
{
    PRCM_CLK_24MHZ, 
};
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */

#ifdef BUILDCFG_PRCM_MOD_GPIO0
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_GPIO0_funcClkOptional[] = 
{
    PRCM_CLK_GPIO0_GDBCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */

#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
CATTR(funcClkOptional)
const prcmClockId_t PRCM_MOD_SYNCTIMER_funcClkOptional[] = 
{
    PRCM_CLK_SYNCTIMER32K_GFCLK, 
};
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */



CATTR(prcmModuleElems)
const prcmModule_t prcmModuleElems[] = 
{
#ifdef BUILDCFG_PRCM_MOD_CEFUSE
    { /* PRCM_MOD_CEFUSE */
        PRCM_CD_CEFUSE,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_CEFUSE_REG + PRCM_CM_CEFUSE_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_CEFUSE_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_CEFUSE_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
    { /* PRCM_MOD_DEBUGSS */
        PRCM_CD_L3_AON,
        PRCM_RT_NO_RETENTION,
        PRCM_INVALID_REGADDR,
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_DEBUGSS_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_DEBUGSS_funcClkOptional, prcmClockId_t),
        TRUE,
        PRCM_MODULE_MODE_DISABLED,
    },
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PRCM_MOD_DSS
    { /* PRCM_MOD_DSS */
        PRCM_CD_PER_DSS,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_DSS_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_DSS_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_DSS_funcClkMandatory, prcmClockId_t),
        0,
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_DSS */
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
    { /* PRCM_MOD_EMIF_FW */
        PRCM_CD_PER_L4LS,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EMIF_FW_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_DDRPHY
    { /* PRCM_MOD_DDRPHY */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        PRCM_INVALID_REGADDR,
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        PRCM_MODULE_MODE_DISABLED,
    },
#endif /* BUILDCFG_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PRCM_MOD_DLL
    { /* PRCM_MOD_DLL */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_DLL_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_DLL */
#ifdef BUILDCFG_PRCM_MOD_DLL_AGING
    { /* PRCM_MOD_DLL_AGING */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_DLL_AGING_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PRCM_MOD_EMIF
    { /* PRCM_MOD_EMIF */
        PRCM_CD_UNDEF,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EMIF_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GPMC
    { /* PRCM_MOD_GPMC */
        PRCM_CD_PER_L3S,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_GPMC_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_MMC0
    { /* PRCM_MOD_MMC0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MMC0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_MMC0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_MMC0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
    { /* PRCM_MOD_MMC1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MMC1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_MMC1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_MMC1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PRCM_MOD_MMC2
    { /* PRCM_MOD_MMC2 */
        PRCM_CD_PER_L3S,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MMC2_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_MMC2_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_MMC2_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
    { /* PRCM_MOD_OCMCRAM */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_OCMCRAM_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_OTFA_EMIF
    { /* PRCM_MOD_OTFA_EMIF */
        PRCM_CD_UNDEF,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_OTFA_EMIF_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GFX
    { /* PRCM_MOD_GFX */
        PRCM_CD_GFX_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_GFX_REG + PRCM_CM_GFX_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_GFX_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_GFX_funcClkMandatory, prcmClockId_t),
        0,
        TRUE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GFX */
#ifdef BUILDCFG_PRCM_MOD_GPIO1
    { /* PRCM_MOD_GPIO1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_GPIO1_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_GPIO1_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO2
    { /* PRCM_MOD_GPIO2 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO2_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_GPIO2_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_GPIO2_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PRCM_MOD_GPIO3
    { /* PRCM_MOD_GPIO3 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO3_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_GPIO3_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_GPIO3_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PRCM_MOD_GPIO4
    { /* PRCM_MOD_GPIO4 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO4_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_GPIO4_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_GPIO4_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PRCM_MOD_GPIO5
    { /* PRCM_MOD_GPIO5 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO5_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_GPIO5_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_GPIO5_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
    { /* PRCM_MOD_MAG_CARD */
        PRCM_CD_PER_L3S,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MAG_CARD_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_MAG_CARD_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_MAG_CARD_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PRCM_MOD_L3
    { /* PRCM_MOD_L3 */
        PRCM_CD_PER_L3,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_L3_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_L3 */
#ifdef BUILDCFG_PRCM_MOD_L3_INSTR
    { /* PRCM_MOD_L3_INSTR */
        PRCM_CD_PER_L3,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_L3_INSTR_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PRCM_MOD_L4FW
    { /* PRCM_MOD_L4FW */
        PRCM_CD_PER_L3,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_L4FW_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PRCM_MOD_L4LS
    { /* PRCM_MOD_L4LS */
        PRCM_CD_PER_L4LS,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_L4LS_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PRCM_MOD_L4_HS
    { /* PRCM_MOD_L4_HS */
        PRCM_CD_PER_L3,
        PRCM_RT_PARTIAL_RETENTION,
        PRCM_INVALID_REGADDR,
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        PRCM_MODULE_MODE_DISABLED,
    },
#endif /* BUILDCFG_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PRCM_MOD_ICSS
    { /* PRCM_MOD_ICSS */
        PRCM_CD_PER_ICSS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_ICSS_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_ICSS_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_ICSS_funcClkMandatory, prcmClockId_t),
        0,
        TRUE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PRCM_MOD_IEEE5000
    { /* PRCM_MOD_IEEE5000 */
        PRCM_CD_PER_L3S,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_IEEE5000_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PRCM_MOD_LCDC
    { /* PRCM_MOD_LCDC */
        PRCM_CD_PER_LCDC,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_LCDC_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_LCDC_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_LCDC_funcClkMandatory, prcmClockId_t),
        0,
        TRUE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PRCM_MOD_MSTR_EXPS
    { /* PRCM_MOD_MSTR_EXPS */
        PRCM_CD_PER_L3,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MSTR_EXPS_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PRCM_MOD_SLV_EXPS
    { /* PRCM_MOD_SLV_EXPS */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SLV_EXPS_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PRCM_MOD_TPCC
    { /* PRCM_MOD_TPCC */
        PRCM_CD_PER_L3,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TPCC_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PRCM_MOD_TPTC0
    { /* PRCM_MOD_TPTC0 */
        PRCM_CD_PER_L3,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TPTC0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PRCM_MOD_TPTC1
    { /* PRCM_MOD_TPTC1 */
        PRCM_CD_PER_L3,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TPTC1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PRCM_MOD_TPTC2
    { /* PRCM_MOD_TPTC2 */
        PRCM_CD_PER_L3,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TPTC2_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PRCM_MOD_DCAN0
    { /* PRCM_MOD_DCAN0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_DCAN0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_DCAN0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_DCAN0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PRCM_MOD_DCAN1
    { /* PRCM_MOD_DCAN1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_DCAN1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_DCAN1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_DCAN1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PRCM_MOD_ELM
    { /* PRCM_MOD_ELM */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_ELM_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_ELM */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS0
    { /* PRCM_MOD_EPWMSS0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS1
    { /* PRCM_MOD_EPWMSS1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS2
    { /* PRCM_MOD_EPWMSS2 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS2_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS3
    { /* PRCM_MOD_EPWMSS3 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS3_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS4
    { /* PRCM_MOD_EPWMSS4 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS4_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS5
    { /* PRCM_MOD_EPWMSS5 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS5_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PRCM_MOD_ERMC
    { /* PRCM_MOD_ERMC */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_ERMC_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PRCM_MOD_HDQ1W
    { /* PRCM_MOD_HDQ1W */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_HDQ1W_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_HDQ1W_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_HDQ1W_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PRCM_MOD_I2C1
    { /* PRCM_MOD_I2C1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_I2C1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_I2C1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PRCM_MOD_I2C2
    { /* PRCM_MOD_I2C2 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_I2C2_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_I2C2_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_I2C2_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
    { /* PRCM_MOD_MCASP0 */
        PRCM_CD_PER_L3S,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MCASP0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_MCASP0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_MCASP0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
    { /* PRCM_MOD_QSPI */
        PRCM_CD_PER_L3S,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_QSPI_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_QSPI_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_QSPI_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_SPI0
    { /* PRCM_MOD_SPI0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_SPI0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_SPI0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PRCM_MOD_SPI1
    { /* PRCM_MOD_SPI1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_SPI1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_SPI1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PRCM_MOD_SPI2
    { /* PRCM_MOD_SPI2 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI2_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_SPI2_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_SPI2_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PRCM_MOD_SPI3
    { /* PRCM_MOD_SPI3 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI3_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_SPI3_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_SPI3_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PRCM_MOD_SPI4
    { /* PRCM_MOD_SPI4 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI4_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_SPI4_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_SPI4_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER10
    { /* PRCM_MOD_TIMER10 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER10_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER10_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER10_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PRCM_MOD_TIMER11
    { /* PRCM_MOD_TIMER11 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER11_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER11_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER11_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PRCM_MOD_TIMER2
    { /* PRCM_MOD_TIMER2 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER2_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER2_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER2_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER3
    { /* PRCM_MOD_TIMER3 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER3_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER3_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER3_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PRCM_MOD_TIMER4
    { /* PRCM_MOD_TIMER4 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER4_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER4_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER4_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER5
    { /* PRCM_MOD_TIMER5 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER5_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER5_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER5_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PRCM_MOD_TIMER6
    { /* PRCM_MOD_TIMER6 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER6_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER6_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER6_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PRCM_MOD_TIMER7
    { /* PRCM_MOD_TIMER7 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER7_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER7_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER7_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PRCM_MOD_TIMER8
    { /* PRCM_MOD_TIMER8 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER8_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER8_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER8_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PRCM_MOD_TIMER9
    { /* PRCM_MOD_TIMER9 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER9_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER9_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER9_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PRCM_MOD_UART1
    { /* PRCM_MOD_UART1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_UART1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_UART1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_UART1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PRCM_MOD_UART2
    { /* PRCM_MOD_UART2 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_UART2_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_UART2_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_UART2_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PRCM_MOD_UART3
    { /* PRCM_MOD_UART3 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_UART3_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_UART3_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_UART3_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PRCM_MOD_UART4
    { /* PRCM_MOD_UART4 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_UART4_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_UART4_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_UART4_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PRCM_MOD_UART5
    { /* PRCM_MOD_UART5 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_UART5_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_UART5_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_UART5_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
    { /* PRCM_MOD_CPGMAC0 */
        PRCM_CD_PER_CPSW,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_CPGMAC0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_CPGMAC0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_CPGMAC0_funcClkMandatory, prcmClockId_t),
        0,
        TRUE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PRCM_MOD_MAILBOX0
    { /* PRCM_MOD_MAILBOX0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MAILBOX0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PRCM_MOD_MCASP1
    { /* PRCM_MOD_MCASP1 */
        PRCM_CD_PER_L3S,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_MCASP1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_MCASP1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_MCASP1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PRCM_MOD_SPARE0
    { /* PRCM_MOD_SPARE0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPARE0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE1
    { /* PRCM_MOD_SPARE1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPARE1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
    { /* PRCM_MOD_SPINLOCK */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SPINLOCK_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_MPU
    { /* PRCM_MOD_MPU */
        PRCM_CD_MPU,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_MPU_REG + PRCM_CM_MPU_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_MPU_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_MPU_funcClkMandatory, prcmClockId_t),
        0,
        TRUE,
        (PRCM_MODULE_MODE_AUTO | PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_MPU */
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
    { /* PRCM_MOD_OCP_WP_NOC */
        PRCM_CD_PER_OCPWP_L3,
        PRCM_RT_PARTIAL_RETENTION,
        PRCM_INVALID_REGADDR,
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        PRCM_MODULE_MODE_DISABLED,
    },
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PRCM_MOD_RTC
    { /* PRCM_MOD_RTC */
        PRCM_CD_RTC,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_RTC_REG + PRCM_CM_RTC_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_RTC_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_RTC_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_RTC */
#ifdef BUILDCFG_PRCM_MOD_AES0
    { /* PRCM_MOD_AES0 */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_AES0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
    { /* PRCM_MOD_CRYPTODMA */
        PRCM_CD_PER_L3,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_CRYPTODMA_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
    { /* PRCM_MOD_DES */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_DES_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_PKA
    { /* PRCM_MOD_PKA */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_PKA_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_RNG
    { /* PRCM_MOD_RNG */
        PRCM_CD_PER_L4LS,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_RNG_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_SHA0
    { /* PRCM_MOD_SHA0 */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_SHA0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
    { /* PRCM_MOD_SMARTREFLEX0 */
        PRCM_CD_WKUP,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_SMARTREFLEX0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_SMARTREFLEX0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
    { /* PRCM_MOD_SMARTREFLEX1 */
        PRCM_CD_WKUP,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_SMARTREFLEX1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_SMARTREFLEX1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
    { /* PRCM_MOD_USB_PHY0_ALWAYS_ON */
        PRCM_CD_L4_WKUP_AON,
        PRCM_RT_NO_RETENTION,
        PRCM_INVALID_REGADDR,
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_USB_PHY0_ALWAYS_ON_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_USB_PHY0_ALWAYS_ON_funcClkOptional, prcmClockId_t),
        FALSE,
        PRCM_MODULE_MODE_DISABLED,
    },
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
    { /* PRCM_MOD_USB_PHY1_ALWAYS_ON */
        PRCM_CD_L4_WKUP_AON,
        PRCM_RT_NO_RETENTION,
        PRCM_INVALID_REGADDR,
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_USB_PHY1_ALWAYS_ON_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_USB_PHY1_ALWAYS_ON_funcClkOptional, prcmClockId_t),
        FALSE,
        PRCM_MODULE_MODE_DISABLED,
    },
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_WDT0
    { /* PRCM_MOD_WDT0 */
        PRCM_CD_WKUP,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_WDT0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_WDT0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_WDT0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
    { /* PRCM_MOD_WDT1 */
        PRCM_CD_WKUP,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_WDT1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_WDT1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_WDT1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_TPMSS
    { /* PRCM_MOD_TPMSS */
        PRCM_CD_TAMPER,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_TAMPER_REG + PRCM_CM_TAMPER_TPMSS_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
    { /* PRCM_MOD_USBPHYOCP2SCP0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_USBPHYOCP2SCP0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
    { /* PRCM_MOD_USBPHYOCP2SCP1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_USBPHYOCP2SCP1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
    { /* PRCM_MOD_USB_OTG_SS0 */
        PRCM_CD_PER_L3S,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_USB_OTG_SS0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_USB_OTG_SS0_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_USB_OTG_SS0_funcClkOptional, prcmClockId_t),
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
    { /* PRCM_MOD_USB_OTG_SS1 */
        PRCM_CD_PER_L3S,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_USB_OTG_SS1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_USB_OTG_SS1_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_USB_OTG_SS1_funcClkOptional, prcmClockId_t),
        TRUE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
    { /* PRCM_MOD_USIM0 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_USIM0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_USIM0_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_USIM0_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
    { /* PRCM_MOD_USIM1 */
        PRCM_CD_PER_L4LS,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_USIM1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_USIM1_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_USIM1_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
    { /* PRCM_MOD_VPFE0 */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_VPFE0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
    { /* PRCM_MOD_VPFE1 */
        PRCM_CD_PER_L3,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_PER_REG + PRCM_CM_PER_VPFE1_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
    { /* PRCM_MOD_ADC_TSC */
        PRCM_CD_L3S_TSC,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_ADC_TSC_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_ADC_TSC_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_ADC_TSC_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
    { /* PRCM_MOD_CLKDIV32K */
        PRCM_CD_L4_WKUP_AON,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_CLKDIV32K_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_CLKDIV32K_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_CLKDIV32K_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
    { /* PRCM_MOD_CONTROL */
        PRCM_CD_WKUP,
        PRCM_RT_FULL_RETENTION,
        PRCM_INVALID_REGADDR,
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        PRCM_MODULE_MODE_DISABLED,
    },
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
    { /* PRCM_MOD_GPIO0 */
        PRCM_CD_WKUP,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_GPIO0_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_GPIO0_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_GPIO0_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
    { /* PRCM_MOD_I2C0 */
        PRCM_CD_WKUP,
        PRCM_RT_FULL_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_I2C0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_I2C0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_I2C0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_L4WKUP
    { /* PRCM_MOD_L4WKUP */
        PRCM_CD_L4_WKUP_AON,
        PRCM_RT_PARTIAL_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_L4WKUP_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
    { /* PRCM_MOD_SYNCTIMER */
        PRCM_CD_L4_WKUP_AON,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_SYNCTIMER_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        PRCM_MOD_SYNCTIMER_funcClkOptional,
        0,
        VSIZE_TYPE(PRCM_MOD_SYNCTIMER_funcClkOptional, prcmClockId_t),
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
    { /* PRCM_MOD_TIMER0 */
        PRCM_CD_WKUP,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_TIMER0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
    { /* PRCM_MOD_TIMER1 */
        PRCM_CD_WKUP,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_TIMER1_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_TIMER1_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_TIMER1_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_ENABLED | PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_UART0
    { /* PRCM_MOD_UART0 */
        PRCM_CD_WKUP,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_UART0_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_UART0_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_UART0_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
    { /* PRCM_MOD_WKUP_M3 */
        PRCM_CD_L4_WKUP_AON,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_M3_CLKCTRL),
        0/* \todo minOpp*/,
        NULL,
        NULL,
        0,
        0,
        TRUE,
        (PRCM_MODULE_MODE_DISABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PRCM_MOD_EFUSE
    { /* PRCM_MOD_EFUSE */
        PRCM_CD_STD_EFUSE,
        PRCM_RT_NO_RETENTION,
        (SOC_CM_CEFUSE_REG + PRCM_CM_CEFUSE_CLKCTRL),
        0/* \todo minOpp*/,
        PRCM_MOD_EFUSE_funcClkMandatory,
        NULL,
        VSIZE_TYPE(PRCM_MOD_EFUSE_funcClkMandatory, prcmClockId_t),
        0,
        FALSE,
        (PRCM_MODULE_MODE_DISABLED | PRCM_MODULE_MODE_ENABLED),
    },
#endif /* BUILDCFG_PRCM_MOD_EFUSE */

};

/*----------------------------------------------------------------------------*/ 
CATTR(prcmPhysicalMemoryElems)
const prcmPhysicalMemory_t prcmPhysicalMemoryElems[] = 
{
    { /* PRCM_PHY_MEM_DEBUGSS */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_DSSMEM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_UART */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_BANK1 */
        MEM_ON_SOFTWARE_CONTROL,
        MEM_RET_SOFTWARE_CONTROL,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_BANK2 */
        MEM_ON_SOFTWARE_CONTROL,
        MEM_RET_SOFTWARE_CONTROL,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_GFX */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_PRM_PM_GFX_PWRSTCTRL_MEM_RETSTATE_SHIFT,
        PRCM_PRM_PM_GFX_PWRSTCTRL_MEM_ONSTATE_SHIFT,
    },
    { /* PRCM_PHY_MEM_DMEM0 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_DMEM1 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_DMEM2 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_DMEM3 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_IMEM0 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_IMEM1 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_IMEM2 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_IMEM3 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_PRUSS0_MEM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_PRUSS1_MEM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_LCD_CORE_PALETTE_RAM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_LCD_DMA_FIFO_RAM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_MEMORYBANKNONAME */
        MEM_ON_SOFTWARE_CONTROL,
        MEM_RET_SOFTWARE_CONTROL,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_MBOXSRAM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_MSHSI2COCP_MEMORY */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_CPPI */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ADDR */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_DB */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_INFO */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ST */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_STATE */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_STATISTICS */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_DB */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_INFO */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_ST */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_MPU_L1 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_PM_MPU_PWRSTCTRL_L1_RETSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTCTRL_L1_ONSTATE_SHIFT,
    },
    { /* PRCM_PHY_MEM_MPU_L2 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_SOFTWARE_CONTROL,
        PRCM_PM_MPU_PWRSTCTRL_L2_RETSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTCTRL_L2_ONSTATE_SHIFT,
    },
    { /* PRCM_PHY_MEM_MPU_RAM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_SOFTWARE_CONTROL,
        PRCM_PM_MPU_PWRSTCTRL_RAM_RETSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTCTRL_RAM_ONSTATE_SHIFT,
    },
    { /* PRCM_PHY_MEM_DMA_CRYPTO */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_PKA_MEM */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_USB */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_RETENTION,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_WB0 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },
    { /* PRCM_PHY_MEM_WB1 */
        MEM_ON_ALWAYS_ON,
        MEM_RET_ALWAYS_OFF,
        PRCM_INVALID_SHIFT,
        PRCM_INVALID_SHIFT,
    },

};

/*----------------------------------------------------------------------------*/ 
CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_MPU_PLL_clkFreqKHzList[] = 
{
    { 0.0, 0/* \todo config value */ },
};

CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_SYS_CLKIN_clkFreqKHzList[] = 
{
    { 12000.0, 0/* \todo config value */ },
};

CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_TCLKIN_clkFreqKHzList[] = 
{
    { 26000.0, 0/* \todo config value */ },
};

CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_32K_MOSC_clkFreqKHzList[] = 
{
    { 32.768, 0/* \todo config value */ },
};

CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_32K_PER_clkFreqKHzList[] = 
{
    { 32.768, 0/* \todo config value */ },
};

CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_32K_RC_clkFreqKHzList[] = 
{
    { 32.768, 0/* \todo config value */ },
};

CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_32K_RTC_clkFreqKHzList[] = 
{
    { 32.768, 0/* \todo config value */ },
};

CATTR(clkFreqKHzList)
const prcmRootClockValues_t PRCM_ROOT_CLK_32K_TPM_clkFreqKHzList[] = 
{
    { 32.768, 0/* \todo config value */ },
};



CATTR(rootClockElems)
const prcmRootClk_t rootClockElems[] = 
{
    { /* PRCM_ROOT_CLK_MPU_PLL */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_MPU_PLL_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },
    { /* PRCM_ROOT_CLK_SYS_CLKIN */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_SYS_CLKIN_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },
    { /* PRCM_ROOT_CLK_TCLKIN */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_TCLKIN_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },
    { /* PRCM_ROOT_CLK_32K_MOSC */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_32K_MOSC_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },
    { /* PRCM_ROOT_CLK_32K_PER */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_32K_PER_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },
    { /* PRCM_ROOT_CLK_32K_RC */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_32K_RC_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },
    { /* PRCM_ROOT_CLK_32K_RTC */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_32K_RTC_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },
    { /* PRCM_ROOT_CLK_32K_TPM */
        PRCM_ROOT_CLK_FREQ_MIN,
        PRCM_ROOT_CLK_32K_TPM_clkFreqKHzList,
        NULL/* \todo pCLkCtrlBitFIeld */,
    },

};

/*----------------------------------------------------------------------------*/ 
CATTR(divRatios)
uint8_t PRCM_DIV_CORE_L4_divRatios[] = 
{ 2, };

CATTR(divRatios)
uint8_t PRCM_DIV_CORE_25M_divRatios[] = 
{ 8, };

CATTR(divRatios)
uint8_t PRCM_DIV_SYSCLK_divRatios[] = 
{ 1, };

CATTR(divRatios)
uint8_t PRCM_DIV_CLKOUT1SEL0DIV_divRatios[] = 
{ 1, 2, 3, 4, };

CATTR(divRatios)
uint8_t PRCM_DIV_CLKOUT1SEL2DIV1_divRatios[] = 
{ 1, 2, 3, 4, 5, 6, 7, 8, };

CATTR(divRatios)
uint8_t PRCM_DIV_CLKOUT1SEL2DIV2_divRatios[] = 
{ 1, 2, 4, 8, 16, 32, };

CATTR(divRatios)
uint8_t PRCM_DIV_CLKOUT2_DIV1_divRatios[] = 
{ 1, 2, 3, 4, 5, 6, 7, 8, };

CATTR(divRatios)
uint8_t PRCM_DIV_CLKOUT2_DIV2_divRatios[] = 
{ 1, 2, 4, 8, 16, 32, };

CATTR(divRatios)
uint8_t PRCM_DIV_DLL_AGING_CLK_divRatios[] = 
{ 8, 16, 32, };

CATTR(divRatios)
uint8_t PRCM_DIV_GFX_FCLK_divRatios[] = 
{ 1, 2, };

CATTR(divRatios)
uint8_t PRCM_DIV_PERS_CLK_divRatios[] = 
{ 4, };

CATTR(divRatios)
uint8_t PRCM_DIV_MMC_divRatios[] = 
{ 2, };

CATTR(divRatios)
uint8_t PRCM_DIV_PDA2CAD8896B3447FD_divRatios[] = 
{ 16, };

CATTR(divRatios)
uint8_t PRCM_DIV_CPSW_125MHZ_OCP_divRatios[] = 
{ 2, };

CATTR(divRatios)
uint8_t PRCM_DIV_CPSW_50M_divRatios[] = 
{ 2, 5, };

CATTR(divRatios)
uint8_t PRCM_DIV_CPSW_5M_divRatios[] = 
{ 10, };

CATTR(divRatios)
uint8_t PRCM_DIV_USIM_FCLK_divRatios[] = 
{ 5, };

CATTR(divRatios)
uint8_t PRCM_DIV_VTP_CLK_divRatios[] = 
{ 2, };

CATTR(divRatios)
uint8_t PRCM_DIV_CLK_DIV_24_divRatios[] = 
{ 8, };

CATTR(divRatios)
uint8_t PRCM_DIV_UART5_divRatios[] = 
{ 4, };



CATTR(prcmDividerElems)
const prcmClockDivider_t prcmDividerElems[] =
{
    { /* PRCM_DIV_CORE_L4 */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CORE_L4_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CORE_25M */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CORE_25M_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_SYSCLK */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_SYSCLK_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CLKOUT1SEL0DIV */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CLKOUT1SEL0DIV_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CLKOUT1SEL2DIV1 */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CLKOUT1SEL2DIV1_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CLKOUT1SEL2DIV2 */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CLKOUT1SEL2DIV2_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CLKOUT2_DIV1 */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CLKOUT2_DIV1_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CLKOUT2_DIV2 */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CLKOUT2_DIV2_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_DLL_AGING_CLK */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_DLL_AGING_CLK_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_GFX_FCLK */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_GFX_FCLK_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_PERS_CLK */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_PERS_CLK_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_MMC */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_MMC_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_PDA2CAD8896B3447FD */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_PDA2CAD8896B3447FD_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CPSW_125MHZ_OCP */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CPSW_125MHZ_OCP_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CPSW_50M */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CPSW_50M_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CPSW_5M */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CPSW_5M_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_USIM_FCLK */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_USIM_FCLK_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_VTP_CLK */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_VTP_CLK_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_CLK_DIV_24 */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_CLK_DIV_24_divRatios,
        NULL/* \todo divBitValue[] */
    },
    { /* PRCM_DIV_UART5 */ 
        {0, 0, 0}/* \todo divCtlBF */,
        PRCM_DIV_UART5_divRatios,
        NULL/* \todo divBitValue[] */
    },

};

/*----------------------------------------------------------------------------*/ 
CATTR(prcmMultiplexerElems) 
const prcmMultiplexer_t prcmMultiplexerElems[] =
{
    { /* PRCM_MUX_CLKOUT1SEL2 */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_CLKOUT1 */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_CLKOUT_32K */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_CLKOUT1_MUX1 */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_CLKOUT1_MUX2 */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_CLKOUT1_MUX3 */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_SGX_CLKSEL */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_MAG_FCLK */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_ICSS_OCP_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK), PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_MASK, PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_LCD_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK), PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_MASK, PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER10_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER10_CLK), PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER11_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER11_CLK), PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER1_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER1_CLK), PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER2_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER2_CLK), PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER3_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER3_CLK), PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER4_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER4_CLK), PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER5_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER5_CLK), PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER6_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER6_CLK), PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER8_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER8_CLK), PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER9_CLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER9_CLK), PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_CPTS_RFT */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK), PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_MASK, PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_USBPHY_32KHZ */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_WDT0 */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_WDT1 */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_WDT1_CLK), PRCM_CM_DPLL_CLKSEL_WDT1_CLK_MASK, PRCM_CM_DPLL_CLKSEL_WDT1_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_USIM0_FCLK */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_USIM1_FCLK */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_USIM_DBCLKMUX */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_USIM_DBCLK), PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_MASK, PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_SHIFT }, 
    },
    { /* PRCM_MUX_GPIO_DBCLK */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK), PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_MASK, PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_SHIFT }, 
    },
    { /* PRCM_MUX_SYNCTIMER32K */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK), PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_MASK, PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER0 */ 
        { PRCM_INVALID_REGADDR, PRCM_INVALID_MASK, PRCM_INVALID_SHIFT }, 
    },
    { /* PRCM_MUX_TIMER1 */ 
        { (SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER1_CLK), PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_MASK, PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_SHIFT }, 
    },

};

/*----------------------------------------------------------------------------*/ 
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_MPU_PLL_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_MPU_PLL] };
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_SYS_CLKIN_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_SYS_CLKIN] };
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_TCLKIN_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_TCLKIN] };
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_32K_MOSC_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_32K_MOSC] };
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_32K_PER_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_32K_PER] };
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_32K_RC_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_32K_RC] };
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_32K_RTC_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_32K_RTC] };
CATTR(prop)
const ag_prop PRCM_ROOT_CLK_32K_TPM_prop =
    { PRCM_ROOT_CLK, &rootClockElems[PRCM_ROOT_CLK_32K_TPM] };
CATTR(prop)
const ag_prop PRCM_MUX_CLKOUT1SEL2_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_CLKOUT1SEL2-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_CLKOUT1_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_CLKOUT1-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_CLKOUT_32K_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_CLKOUT_32K-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_CLKOUT1_MUX1_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_CLKOUT1_MUX1-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_CLKOUT1_MUX2_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_CLKOUT1_MUX2-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_CLKOUT1_MUX3_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_CLKOUT1_MUX3-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_SGX_CLKSEL_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_SGX_CLKSEL-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_MAG_FCLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_MAG_FCLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_ICSS_OCP_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_ICSS_OCP_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_LCD_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_LCD_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER10_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER10_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER11_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER11_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER1_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER1_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER2_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER2_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER3_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER3_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER4_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER4_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER5_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER5_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER6_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER6_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER8_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER8_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER9_CLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER9_CLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_CPTS_RFT_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_CPTS_RFT-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_USBPHY_32KHZ_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_USBPHY_32KHZ-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_WDT0_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_WDT0-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_WDT1_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_WDT1-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_USIM0_FCLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_USIM0_FCLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_USIM1_FCLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_USIM1_FCLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_USIM_DBCLKMUX_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_USIM_DBCLKMUX-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_GPIO_DBCLK_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_GPIO_DBCLK-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_SYNCTIMER32K_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_SYNCTIMER32K-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER0_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER0-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_MUX_TIMER1_prop =
    { PRCM_MUX, &prcmMultiplexerElems[PRCM_MUX_TIMER1-PRCM_MUX_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CORE_L4_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CORE_L4-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CORE_25M_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CORE_25M-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_SYSCLK_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_SYSCLK-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CLKOUT1SEL0DIV_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CLKOUT1SEL0DIV-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CLKOUT1SEL2DIV1_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CLKOUT1SEL2DIV1-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CLKOUT1SEL2DIV2_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CLKOUT1SEL2DIV2-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CLKOUT2_DIV1_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CLKOUT2_DIV1-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CLKOUT2_DIV2_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CLKOUT2_DIV2-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_DLL_AGING_CLK_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_DLL_AGING_CLK-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_GFX_FCLK_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_GFX_FCLK-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_PERS_CLK_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_PERS_CLK-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_MMC_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_MMC-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_PDA2CAD8896B3447FD_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_PDA2CAD8896B3447FD-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CPSW_125MHZ_OCP_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CPSW_125MHZ_OCP-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CPSW_50M_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CPSW_50M-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CPSW_5M_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CPSW_5M-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_USIM_FCLK_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_USIM_FCLK-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_VTP_CLK_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_VTP_CLK-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_CLK_DIV_24_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_CLK_DIV_24-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DIV_UART5_prop =
    { PRCM_DIV, &prcmDividerElems[PRCM_DIV_UART5-PRCM_DIV_MIN] };
CATTR(prop)
const ag_prop PRCM_DPLL_CORE_prop =
    { PRCM_DPLL, &prcmDpllElems[PRCM_DPLL_CORE-PRCM_DPLL_MIN] };
CATTR(prop)
const ag_prop PRCM_DPLL_DDR_prop =
    { PRCM_DPLL, &prcmDpllElems[PRCM_DPLL_DDR-PRCM_DPLL_MIN] };
CATTR(prop)
const ag_prop PRCM_DPLL_DISP_prop =
    { PRCM_DPLL, &prcmDpllElems[PRCM_DPLL_DISP-PRCM_DPLL_MIN] };
CATTR(prop)
const ag_prop PRCM_DPLL_EXTDEV_prop =
    { PRCM_DPLL, &prcmDpllElems[PRCM_DPLL_EXTDEV-PRCM_DPLL_MIN] };
CATTR(prop)
const ag_prop PRCM_DPLL_MPU_prop =
    { PRCM_DPLL, &prcmDpllElems[PRCM_DPLL_MPU-PRCM_DPLL_MIN] };
CATTR(prop)
const ag_prop PRCM_DPLL_PER_prop =
    { PRCM_DPLL, &prcmDpllElems[PRCM_DPLL_PER-PRCM_DPLL_MIN] };

#ifdef BUILDCFG_PRCM_MOD_CEFUSE
CATTR(prop)
const ag_prop PRCM_MOD_CEFUSE_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_CEFUSE - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
CATTR(prop)
const ag_prop PRCM_MOD_DEBUGSS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DEBUGSS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PRCM_MOD_DSS
CATTR(prop)
const ag_prop PRCM_MOD_DSS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DSS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DSS */
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
CATTR(prop)
const ag_prop PRCM_MOD_EMIF_FW_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EMIF_FW - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_DDRPHY
CATTR(prop)
const ag_prop PRCM_MOD_DDRPHY_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DDRPHY - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PRCM_MOD_DLL
CATTR(prop)
const ag_prop PRCM_MOD_DLL_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DLL - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DLL */
#ifdef BUILDCFG_PRCM_MOD_DLL_AGING
CATTR(prop)
const ag_prop PRCM_MOD_DLL_AGING_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DLL_AGING - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PRCM_MOD_EMIF
CATTR(prop)
const ag_prop PRCM_MOD_EMIF_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EMIF - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GPMC
CATTR(prop)
const ag_prop PRCM_MOD_GPMC_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GPMC - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_MMC0
CATTR(prop)
const ag_prop PRCM_MOD_MMC0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MMC0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
CATTR(prop)
const ag_prop PRCM_MOD_MMC1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MMC1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PRCM_MOD_MMC2
CATTR(prop)
const ag_prop PRCM_MOD_MMC2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MMC2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
CATTR(prop)
const ag_prop PRCM_MOD_OCMCRAM_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_OCMCRAM - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_OTFA_EMIF
CATTR(prop)
const ag_prop PRCM_MOD_OTFA_EMIF_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_OTFA_EMIF - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GFX
CATTR(prop)
const ag_prop PRCM_MOD_GFX_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GFX - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GFX */
#ifdef BUILDCFG_PRCM_MOD_GPIO1
CATTR(prop)
const ag_prop PRCM_MOD_GPIO1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GPIO1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO2
CATTR(prop)
const ag_prop PRCM_MOD_GPIO2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GPIO2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PRCM_MOD_GPIO3
CATTR(prop)
const ag_prop PRCM_MOD_GPIO3_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GPIO3 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PRCM_MOD_GPIO4
CATTR(prop)
const ag_prop PRCM_MOD_GPIO4_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GPIO4 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PRCM_MOD_GPIO5
CATTR(prop)
const ag_prop PRCM_MOD_GPIO5_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GPIO5 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
CATTR(prop)
const ag_prop PRCM_MOD_MAG_CARD_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MAG_CARD - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PRCM_MOD_L3
CATTR(prop)
const ag_prop PRCM_MOD_L3_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_L3 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_L3 */
#ifdef BUILDCFG_PRCM_MOD_L3_INSTR
CATTR(prop)
const ag_prop PRCM_MOD_L3_INSTR_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_L3_INSTR - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PRCM_MOD_L4FW
CATTR(prop)
const ag_prop PRCM_MOD_L4FW_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_L4FW - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PRCM_MOD_L4LS
CATTR(prop)
const ag_prop PRCM_MOD_L4LS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_L4LS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PRCM_MOD_L4_HS
CATTR(prop)
const ag_prop PRCM_MOD_L4_HS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_L4_HS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PRCM_MOD_ICSS
CATTR(prop)
const ag_prop PRCM_MOD_ICSS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_ICSS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PRCM_MOD_IEEE5000
CATTR(prop)
const ag_prop PRCM_MOD_IEEE5000_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_IEEE5000 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PRCM_MOD_LCDC
CATTR(prop)
const ag_prop PRCM_MOD_LCDC_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_LCDC - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PRCM_MOD_MSTR_EXPS
CATTR(prop)
const ag_prop PRCM_MOD_MSTR_EXPS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MSTR_EXPS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PRCM_MOD_SLV_EXPS
CATTR(prop)
const ag_prop PRCM_MOD_SLV_EXPS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SLV_EXPS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PRCM_MOD_TPCC
CATTR(prop)
const ag_prop PRCM_MOD_TPCC_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TPCC - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PRCM_MOD_TPTC0
CATTR(prop)
const ag_prop PRCM_MOD_TPTC0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TPTC0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PRCM_MOD_TPTC1
CATTR(prop)
const ag_prop PRCM_MOD_TPTC1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TPTC1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PRCM_MOD_TPTC2
CATTR(prop)
const ag_prop PRCM_MOD_TPTC2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TPTC2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PRCM_MOD_DCAN0
CATTR(prop)
const ag_prop PRCM_MOD_DCAN0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DCAN0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PRCM_MOD_DCAN1
CATTR(prop)
const ag_prop PRCM_MOD_DCAN1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DCAN1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PRCM_MOD_ELM
CATTR(prop)
const ag_prop PRCM_MOD_ELM_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_ELM - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_ELM */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS0
CATTR(prop)
const ag_prop PRCM_MOD_EPWMSS0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EPWMSS0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS1
CATTR(prop)
const ag_prop PRCM_MOD_EPWMSS1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EPWMSS1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS2
CATTR(prop)
const ag_prop PRCM_MOD_EPWMSS2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EPWMSS2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS3
CATTR(prop)
const ag_prop PRCM_MOD_EPWMSS3_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EPWMSS3 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS4
CATTR(prop)
const ag_prop PRCM_MOD_EPWMSS4_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EPWMSS4 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS5
CATTR(prop)
const ag_prop PRCM_MOD_EPWMSS5_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EPWMSS5 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PRCM_MOD_ERMC
CATTR(prop)
const ag_prop PRCM_MOD_ERMC_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_ERMC - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PRCM_MOD_HDQ1W
CATTR(prop)
const ag_prop PRCM_MOD_HDQ1W_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_HDQ1W - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PRCM_MOD_I2C1
CATTR(prop)
const ag_prop PRCM_MOD_I2C1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_I2C1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PRCM_MOD_I2C2
CATTR(prop)
const ag_prop PRCM_MOD_I2C2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_I2C2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
CATTR(prop)
const ag_prop PRCM_MOD_MCASP0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MCASP0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
CATTR(prop)
const ag_prop PRCM_MOD_QSPI_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_QSPI - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_SPI0
CATTR(prop)
const ag_prop PRCM_MOD_SPI0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPI0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PRCM_MOD_SPI1
CATTR(prop)
const ag_prop PRCM_MOD_SPI1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPI1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PRCM_MOD_SPI2
CATTR(prop)
const ag_prop PRCM_MOD_SPI2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPI2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PRCM_MOD_SPI3
CATTR(prop)
const ag_prop PRCM_MOD_SPI3_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPI3 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PRCM_MOD_SPI4
CATTR(prop)
const ag_prop PRCM_MOD_SPI4_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPI4 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER10
CATTR(prop)
const ag_prop PRCM_MOD_TIMER10_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER10 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PRCM_MOD_TIMER11
CATTR(prop)
const ag_prop PRCM_MOD_TIMER11_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER11 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PRCM_MOD_TIMER2
CATTR(prop)
const ag_prop PRCM_MOD_TIMER2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER3
CATTR(prop)
const ag_prop PRCM_MOD_TIMER3_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER3 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PRCM_MOD_TIMER4
CATTR(prop)
const ag_prop PRCM_MOD_TIMER4_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER4 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER5
CATTR(prop)
const ag_prop PRCM_MOD_TIMER5_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER5 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PRCM_MOD_TIMER6
CATTR(prop)
const ag_prop PRCM_MOD_TIMER6_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER6 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PRCM_MOD_TIMER7
CATTR(prop)
const ag_prop PRCM_MOD_TIMER7_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER7 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PRCM_MOD_TIMER8
CATTR(prop)
const ag_prop PRCM_MOD_TIMER8_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER8 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PRCM_MOD_TIMER9
CATTR(prop)
const ag_prop PRCM_MOD_TIMER9_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER9 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PRCM_MOD_UART1
CATTR(prop)
const ag_prop PRCM_MOD_UART1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_UART1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PRCM_MOD_UART2
CATTR(prop)
const ag_prop PRCM_MOD_UART2_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_UART2 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PRCM_MOD_UART3
CATTR(prop)
const ag_prop PRCM_MOD_UART3_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_UART3 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PRCM_MOD_UART4
CATTR(prop)
const ag_prop PRCM_MOD_UART4_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_UART4 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PRCM_MOD_UART5
CATTR(prop)
const ag_prop PRCM_MOD_UART5_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_UART5 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
CATTR(prop)
const ag_prop PRCM_MOD_CPGMAC0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_CPGMAC0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PRCM_MOD_MAILBOX0
CATTR(prop)
const ag_prop PRCM_MOD_MAILBOX0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MAILBOX0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PRCM_MOD_MCASP1
CATTR(prop)
const ag_prop PRCM_MOD_MCASP1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MCASP1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PRCM_MOD_SPARE0
CATTR(prop)
const ag_prop PRCM_MOD_SPARE0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPARE0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE1
CATTR(prop)
const ag_prop PRCM_MOD_SPARE1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPARE1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
CATTR(prop)
const ag_prop PRCM_MOD_SPINLOCK_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SPINLOCK - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_MPU
CATTR(prop)
const ag_prop PRCM_MOD_MPU_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_MPU - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_MPU */
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
CATTR(prop)
const ag_prop PRCM_MOD_OCP_WP_NOC_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_OCP_WP_NOC - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PRCM_MOD_RTC
CATTR(prop)
const ag_prop PRCM_MOD_RTC_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_RTC - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_RTC */
#ifdef BUILDCFG_PRCM_MOD_AES0
CATTR(prop)
const ag_prop PRCM_MOD_AES0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_AES0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
CATTR(prop)
const ag_prop PRCM_MOD_CRYPTODMA_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_CRYPTODMA - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
CATTR(prop)
const ag_prop PRCM_MOD_DES_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_DES - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_PKA
CATTR(prop)
const ag_prop PRCM_MOD_PKA_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_PKA - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_RNG
CATTR(prop)
const ag_prop PRCM_MOD_RNG_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_RNG - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_SHA0
CATTR(prop)
const ag_prop PRCM_MOD_SHA0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SHA0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
CATTR(prop)
const ag_prop PRCM_MOD_SMARTREFLEX0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SMARTREFLEX0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
CATTR(prop)
const ag_prop PRCM_MOD_SMARTREFLEX1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SMARTREFLEX1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
CATTR(prop)
const ag_prop PRCM_MOD_USB_PHY0_ALWAYS_ON_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USB_PHY0_ALWAYS_ON - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
CATTR(prop)
const ag_prop PRCM_MOD_USB_PHY1_ALWAYS_ON_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USB_PHY1_ALWAYS_ON - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_WDT0
CATTR(prop)
const ag_prop PRCM_MOD_WDT0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_WDT0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
CATTR(prop)
const ag_prop PRCM_MOD_WDT1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_WDT1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_TPMSS
CATTR(prop)
const ag_prop PRCM_MOD_TPMSS_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TPMSS - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
CATTR(prop)
const ag_prop PRCM_MOD_USBPHYOCP2SCP0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USBPHYOCP2SCP0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
CATTR(prop)
const ag_prop PRCM_MOD_USBPHYOCP2SCP1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USBPHYOCP2SCP1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
CATTR(prop)
const ag_prop PRCM_MOD_USB_OTG_SS0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USB_OTG_SS0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
CATTR(prop)
const ag_prop PRCM_MOD_USB_OTG_SS1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USB_OTG_SS1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
CATTR(prop)
const ag_prop PRCM_MOD_USIM0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USIM0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
CATTR(prop)
const ag_prop PRCM_MOD_USIM1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_USIM1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
CATTR(prop)
const ag_prop PRCM_MOD_VPFE0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_VPFE0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
CATTR(prop)
const ag_prop PRCM_MOD_VPFE1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_VPFE1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
CATTR(prop)
const ag_prop PRCM_MOD_ADC_TSC_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_ADC_TSC - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
CATTR(prop)
const ag_prop PRCM_MOD_CLKDIV32K_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_CLKDIV32K - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
CATTR(prop)
const ag_prop PRCM_MOD_CONTROL_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_CONTROL - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
CATTR(prop)
const ag_prop PRCM_MOD_GPIO0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_GPIO0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
CATTR(prop)
const ag_prop PRCM_MOD_I2C0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_I2C0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_L4WKUP
CATTR(prop)
const ag_prop PRCM_MOD_L4WKUP_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_L4WKUP - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
CATTR(prop)
const ag_prop PRCM_MOD_SYNCTIMER_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_SYNCTIMER - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
CATTR(prop)
const ag_prop PRCM_MOD_TIMER0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
CATTR(prop)
const ag_prop PRCM_MOD_TIMER1_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_TIMER1 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_UART0
CATTR(prop)
const ag_prop PRCM_MOD_UART0_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_UART0 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
CATTR(prop)
const ag_prop PRCM_MOD_WKUP_M3_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_WKUP_M3 - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PRCM_MOD_EFUSE
CATTR(prop)
const ag_prop PRCM_MOD_EFUSE_prop =
    { PRCM_MOD, &prcmModuleElems[PRCM_MOD_EFUSE - PRCM_MOD_MIN] };
#endif /* BUILDCFG_PRCM_MOD_EFUSE */


/*----------------------------------------------------------------------------*/
CATTR(inNodes)
const ag_node_id PRCM_MUX_CLKOUT1SEL2_inNodes[] = {
    PRCM_MUX_CLKOUT_32K,
    PRCM_ROOT_CLK_MPU_PLL,
    PRCM_DIV_SYSCLK,
    PRCM_DPLL_DDR,
    PRCM_DPLL_DISP,
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_CLKOUT1_inNodes[] = {
    PRCM_DIV_CLKOUT1SEL2DIV2,
    PRCM_MUX_CLKOUT_32K,
    PRCM_DIV_CLKOUT1SEL0DIV,
    PRCM_DPLL_EXTDEV,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_CLKOUT_32K_inNodes[] = {
    PRCM_ROOT_CLK_32K_RTC,
    PRCM_ROOT_CLK_32K_TPM,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_CLKOUT1_MUX1_inNodes[] = {
    PRCM_MUX_CLKOUT_32K,
    PRCM_DIV_SYSCLK,
    PRCM_DPLL_DDR,
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_CLKOUT1_MUX2_inNodes[] = {
    PRCM_ROOT_CLK_MPU_PLL,
    PRCM_DPLL_DISP,
    PRCM_DPLL_EXTDEV,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_CLKOUT1_MUX3_inNodes[] = {
    PRCM_MUX_CLKOUT1_MUX1,
    PRCM_MUX_CLKOUT1_MUX2,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_SGX_CLKSEL_inNodes[] = {
    PRCM_DIV_SYSCLK,
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_MAG_FCLK_inNodes[] = {
    PRCM_DPLL_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_ICSS_OCP_CLK_inNodes[] = {
    PRCM_DIV_SYSCLK,
    PRCM_DPLL_DISP,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_LCD_CLK_inNodes[] = {
    PRCM_DPLL_CORE,
    PRCM_DPLL_DISP,
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER10_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_ROOT_CLK_32K_TPM,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER11_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_ROOT_CLK_32K_TPM,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER1_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER2_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER3_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER4_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER5_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER6_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER8_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_ROOT_CLK_32K_TPM,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER9_CLK_inNodes[] = {
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_ROOT_CLK_32K_TPM,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_CPTS_RFT_inNodes[] = {
    PRCM_DPLL_CORE,
    PRCM_DIV_SYSCLK,
    PRCM_DPLL_DISP,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_USBPHY_32KHZ_inNodes[] = {
    PRCM_ROOT_CLK_32K_RTC,
    PRCM_ROOT_CLK_32K_TPM,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_WDT0_inNodes[] = {
    PRCM_ROOT_CLK_32K_TPM,
    PRCM_ROOT_CLK_32K_RC,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_WDT1_inNodes[] = {
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_32K_RC,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_USIM0_FCLK_inNodes[] = {
    PRCM_DIV_USIM_FCLK,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_USIM1_FCLK_inNodes[] = {
    PRCM_DIV_USIM_FCLK,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_USIM_DBCLKMUX_inNodes[] = {
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_32K_MOSC,
    PRCM_ROOT_CLK_32K_RC,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_GPIO_DBCLK_inNodes[] = {
    PRCM_ROOT_CLK_32K_RTC,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_32K_MOSC,
    PRCM_ROOT_CLK_32K_TPM,
    PRCM_ROOT_CLK_32K_RC,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_SYNCTIMER32K_inNodes[] = {
    PRCM_ROOT_CLK_32K_RTC,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_32K_TPM,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER0_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_ROOT_CLK_32K_TPM,
    PRCM_ROOT_CLK_32K_RC,
};
CATTR(inNodes)
const ag_node_id PRCM_MUX_TIMER1_inNodes[] = {
    PRCM_ROOT_CLK_32K_RTC,
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_ROOT_CLK_32K_TPM,
    PRCM_ROOT_CLK_32K_RC,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CORE_L4_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CORE_25M_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_SYSCLK_inNodes[] = {
    PRCM_DPLL_CORE,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CLKOUT1SEL0DIV_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CLKOUT1SEL2DIV1_inNodes[] = {
    PRCM_MUX_CLKOUT1SEL2,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CLKOUT1SEL2DIV2_inNodes[] = {
    PRCM_DIV_CLKOUT1SEL2DIV1,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CLKOUT2_DIV1_inNodes[] = {
    PRCM_MUX_CLKOUT1_MUX3,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CLKOUT2_DIV2_inNodes[] = {
    PRCM_DIV_CLKOUT2_DIV1,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_DLL_AGING_CLK_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_GFX_FCLK_inNodes[] = {
    PRCM_MUX_SGX_CLKSEL,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_PERS_CLK_inNodes[] = {
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_MMC_inNodes[] = {
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_PDA2CAD8896B3447FD_inNodes[] = {
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CPSW_125MHZ_OCP_inNodes[] = {
    PRCM_DPLL_CORE,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CPSW_50M_inNodes[] = {
    PRCM_DPLL_CORE,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CPSW_5M_inNodes[] = {
    PRCM_DIV_CPSW_50M,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_USIM_FCLK_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_VTP_CLK_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_CLK_DIV_24_inNodes[] = {
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_DIV_UART5_inNodes[] = {
    PRCM_DPLL_PER,
};
CATTR(inNodes)
const ag_node_id PRCM_DPLL_CORE_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DPLL_DDR_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DPLL_DISP_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DPLL_EXTDEV_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DPLL_MPU_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
CATTR(inNodes)
const ag_node_id PRCM_DPLL_PER_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};

#ifdef BUILDCFG_PRCM_MOD_CEFUSE
CATTR(inNodes)
const ag_node_id PRCM_MOD_CEFUSE_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
CATTR(inNodes)
const ag_node_id PRCM_MOD_DEBUGSS_inNodes[] = {
    PRCM_DIV_SYSCLK,
    PRCM_DPLL_DISP,
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_DPLL_PER,
};
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PRCM_MOD_DSS
CATTR(inNodes)
const ag_node_id PRCM_MOD_DSS_inNodes[] = {
    PRCM_MUX_LCD_CLK,
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_DSS */
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
CATTR(inNodes)
const ag_node_id PRCM_MOD_EMIF_FW_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_DDRPHY
CATTR(inNodes)
const ag_node_id PRCM_MOD_DDRPHY_inNodes[] = {
    PRCM_DPLL_DDR,
};
#endif /* BUILDCFG_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PRCM_MOD_DLL
CATTR(inNodes)
const ag_node_id PRCM_MOD_DLL_inNodes[] = {
    PRCM_DPLL_DDR,
};
#endif /* BUILDCFG_PRCM_MOD_DLL */
#ifdef BUILDCFG_PRCM_MOD_DLL_AGING
CATTR(inNodes)
const ag_node_id PRCM_MOD_DLL_AGING_inNodes[] = {
    PRCM_DIV_DLL_AGING_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PRCM_MOD_EMIF
CATTR(inNodes)
const ag_node_id PRCM_MOD_EMIF_inNodes[] = {
    PRCM_DIV_SYSCLK,
    PRCM_DPLL_DDR,
};
#endif /* BUILDCFG_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GPMC
CATTR(inNodes)
const ag_node_id PRCM_MOD_GPMC_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_MMC0
CATTR(inNodes)
const ag_node_id PRCM_MOD_MMC0_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_MMC,
};
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
CATTR(inNodes)
const ag_node_id PRCM_MOD_MMC1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_MMC,
};
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PRCM_MOD_MMC2
CATTR(inNodes)
const ag_node_id PRCM_MOD_MMC2_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_MMC,
};
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
CATTR(inNodes)
const ag_node_id PRCM_MOD_OCMCRAM_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_OTFA_EMIF
CATTR(inNodes)
const ag_node_id PRCM_MOD_OTFA_EMIF_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GFX
CATTR(inNodes)
const ag_node_id PRCM_MOD_GFX_inNodes[] = {
    PRCM_DIV_SYSCLK,
    PRCM_DIV_GFX_FCLK,
};
#endif /* BUILDCFG_PRCM_MOD_GFX */
#ifdef BUILDCFG_PRCM_MOD_GPIO1
CATTR(inNodes)
const ag_node_id PRCM_MOD_GPIO1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_32K_PER,
};
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO2
CATTR(inNodes)
const ag_node_id PRCM_MOD_GPIO2_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_32K_PER,
};
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PRCM_MOD_GPIO3
CATTR(inNodes)
const ag_node_id PRCM_MOD_GPIO3_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_32K_PER,
};
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PRCM_MOD_GPIO4
CATTR(inNodes)
const ag_node_id PRCM_MOD_GPIO4_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_32K_PER,
};
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PRCM_MOD_GPIO5
CATTR(inNodes)
const ag_node_id PRCM_MOD_GPIO5_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_32K_PER,
};
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
CATTR(inNodes)
const ag_node_id PRCM_MOD_MAG_CARD_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_MAG_FCLK,
};
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PRCM_MOD_L3
CATTR(inNodes)
const ag_node_id PRCM_MOD_L3_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_L3 */
#ifdef BUILDCFG_PRCM_MOD_L3_INSTR
CATTR(inNodes)
const ag_node_id PRCM_MOD_L3_INSTR_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PRCM_MOD_L4FW
CATTR(inNodes)
const ag_node_id PRCM_MOD_L4FW_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PRCM_MOD_L4LS
CATTR(inNodes)
const ag_node_id PRCM_MOD_L4LS_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PRCM_MOD_L4_HS
CATTR(inNodes)
const ag_node_id PRCM_MOD_L4_HS_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PRCM_MOD_ICSS
CATTR(inNodes)
const ag_node_id PRCM_MOD_ICSS_inNodes[] = {
    PRCM_DIV_SYSCLK,
    PRCM_MUX_ICSS_OCP_CLK,
    PRCM_DPLL_PER,
};
#endif /* BUILDCFG_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PRCM_MOD_IEEE5000
CATTR(inNodes)
const ag_node_id PRCM_MOD_IEEE5000_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PRCM_MOD_LCDC
CATTR(inNodes)
const ag_node_id PRCM_MOD_LCDC_inNodes[] = {
    PRCM_MUX_LCD_CLK,
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PRCM_MOD_MSTR_EXPS
CATTR(inNodes)
const ag_node_id PRCM_MOD_MSTR_EXPS_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PRCM_MOD_SLV_EXPS
CATTR(inNodes)
const ag_node_id PRCM_MOD_SLV_EXPS_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PRCM_MOD_TPCC
CATTR(inNodes)
const ag_node_id PRCM_MOD_TPCC_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PRCM_MOD_TPTC0
CATTR(inNodes)
const ag_node_id PRCM_MOD_TPTC0_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PRCM_MOD_TPTC1
CATTR(inNodes)
const ag_node_id PRCM_MOD_TPTC1_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PRCM_MOD_TPTC2
CATTR(inNodes)
const ag_node_id PRCM_MOD_TPTC2_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PRCM_MOD_DCAN0
CATTR(inNodes)
const ag_node_id PRCM_MOD_DCAN0_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PRCM_MOD_DCAN1
CATTR(inNodes)
const ag_node_id PRCM_MOD_DCAN1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PRCM_MOD_ELM
CATTR(inNodes)
const ag_node_id PRCM_MOD_ELM_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_ELM */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS0
CATTR(inNodes)
const ag_node_id PRCM_MOD_EPWMSS0_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS1
CATTR(inNodes)
const ag_node_id PRCM_MOD_EPWMSS1_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS2
CATTR(inNodes)
const ag_node_id PRCM_MOD_EPWMSS2_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS3
CATTR(inNodes)
const ag_node_id PRCM_MOD_EPWMSS3_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS4
CATTR(inNodes)
const ag_node_id PRCM_MOD_EPWMSS4_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS5
CATTR(inNodes)
const ag_node_id PRCM_MOD_EPWMSS5_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PRCM_MOD_ERMC
CATTR(inNodes)
const ag_node_id PRCM_MOD_ERMC_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PRCM_MOD_HDQ1W
CATTR(inNodes)
const ag_node_id PRCM_MOD_HDQ1W_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PDA2CAD8896B3447FD,
};
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PRCM_MOD_I2C1
CATTR(inNodes)
const ag_node_id PRCM_MOD_I2C1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PRCM_MOD_I2C2
CATTR(inNodes)
const ag_node_id PRCM_MOD_I2C2_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
CATTR(inNodes)
const ag_node_id PRCM_MOD_MCASP0_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
CATTR(inNodes)
const ag_node_id PRCM_MOD_QSPI_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_SPI0
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPI0_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PRCM_MOD_SPI1
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPI1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PRCM_MOD_SPI2
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPI2_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PRCM_MOD_SPI3
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPI3_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PRCM_MOD_SPI4
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPI4_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER10
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER10_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER10_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PRCM_MOD_TIMER11
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER11_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER11_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PRCM_MOD_TIMER2
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER2_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER2_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER3
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER3_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER3_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PRCM_MOD_TIMER4
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER4_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER4_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER5
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER5_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER5_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PRCM_MOD_TIMER6
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER6_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER6_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PRCM_MOD_TIMER7
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER7_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER1_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PRCM_MOD_TIMER8
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER8_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER8_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PRCM_MOD_TIMER9
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER9_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_TIMER9_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PRCM_MOD_UART1
CATTR(inNodes)
const ag_node_id PRCM_MOD_UART1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PRCM_MOD_UART2
CATTR(inNodes)
const ag_node_id PRCM_MOD_UART2_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PRCM_MOD_UART3
CATTR(inNodes)
const ag_node_id PRCM_MOD_UART3_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PRCM_MOD_UART4
CATTR(inNodes)
const ag_node_id PRCM_MOD_UART4_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PRCM_MOD_UART5
CATTR(inNodes)
const ag_node_id PRCM_MOD_UART5_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_PERS_CLK,
};
#endif /* BUILDCFG_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
CATTR(inNodes)
const ag_node_id PRCM_MOD_CPGMAC0_inNodes[] = {
    PRCM_DIV_CPSW_125MHZ_OCP,
    PRCM_DIV_CPSW_5M,
    PRCM_DIV_CPSW_50M,
    PRCM_MUX_CPTS_RFT,
    PRCM_DPLL_CORE,
};
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PRCM_MOD_MAILBOX0
CATTR(inNodes)
const ag_node_id PRCM_MOD_MAILBOX0_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PRCM_MOD_MCASP1
CATTR(inNodes)
const ag_node_id PRCM_MOD_MCASP1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PRCM_MOD_SPARE0
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPARE0_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE1
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPARE1_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
CATTR(inNodes)
const ag_node_id PRCM_MOD_SPINLOCK_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_MPU
CATTR(inNodes)
const ag_node_id PRCM_MOD_MPU_inNodes[] = {
    PRCM_DPLL_MPU,
};
#endif /* BUILDCFG_PRCM_MOD_MPU */
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
CATTR(inNodes)
const ag_node_id PRCM_MOD_OCP_WP_NOC_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PRCM_MOD_RTC
CATTR(inNodes)
const ag_node_id PRCM_MOD_RTC_inNodes[] = {
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_RTC */
#ifdef BUILDCFG_PRCM_MOD_AES0
CATTR(inNodes)
const ag_node_id PRCM_MOD_AES0_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
CATTR(inNodes)
const ag_node_id PRCM_MOD_CRYPTODMA_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
CATTR(inNodes)
const ag_node_id PRCM_MOD_DES_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_PKA
CATTR(inNodes)
const ag_node_id PRCM_MOD_PKA_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_RNG
CATTR(inNodes)
const ag_node_id PRCM_MOD_RNG_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_SHA0
CATTR(inNodes)
const ag_node_id PRCM_MOD_SHA0_inNodes[] = {
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
CATTR(inNodes)
const ag_node_id PRCM_MOD_SMARTREFLEX0_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
CATTR(inNodes)
const ag_node_id PRCM_MOD_SMARTREFLEX1_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
CATTR(inNodes)
const ag_node_id PRCM_MOD_USB_PHY0_ALWAYS_ON_inNodes[] = {
    PRCM_MUX_USBPHY_32KHZ,
};
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
CATTR(inNodes)
const ag_node_id PRCM_MOD_USB_PHY1_ALWAYS_ON_inNodes[] = {
    PRCM_MUX_USBPHY_32KHZ,
};
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_WDT0
CATTR(inNodes)
const ag_node_id PRCM_MOD_WDT0_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_MUX_WDT0,
};
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
CATTR(inNodes)
const ag_node_id PRCM_MOD_WDT1_inNodes[] = {
    PRCM_MUX_WDT1,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_TPMSS
CATTR(inNodes)
const ag_node_id PRCM_MOD_TPMSS_inNodes[] = {
    PRCM_DIV_CORE_25M,
};
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
CATTR(inNodes)
const ag_node_id PRCM_MOD_USBPHYOCP2SCP0_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
CATTR(inNodes)
const ag_node_id PRCM_MOD_USBPHYOCP2SCP1_inNodes[] = {
    PRCM_DIV_CORE_L4,
};
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
CATTR(inNodes)
const ag_node_id PRCM_MOD_USB_OTG_SS0_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DPLL_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
CATTR(inNodes)
const ag_node_id PRCM_MOD_USB_OTG_SS1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DPLL_PER,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
CATTR(inNodes)
const ag_node_id PRCM_MOD_USIM0_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_USIM0_FCLK,
    PRCM_MUX_USIM_DBCLKMUX,
};
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
CATTR(inNodes)
const ag_node_id PRCM_MOD_USIM1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_MUX_USIM1_FCLK,
    PRCM_MUX_USIM_DBCLKMUX,
};
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
CATTR(inNodes)
const ag_node_id PRCM_MOD_VPFE0_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
CATTR(inNodes)
const ag_node_id PRCM_MOD_VPFE1_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_DIV_SYSCLK,
};
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
CATTR(inNodes)
const ag_node_id PRCM_MOD_ADC_TSC_inNodes[] = {
    PRCM_DIV_CORE_L4,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
CATTR(inNodes)
const ag_node_id PRCM_MOD_CLKDIV32K_inNodes[] = {
    PRCM_DIV_CLK_DIV_24,
};
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
CATTR(inNodes)
const ag_node_id PRCM_MOD_CONTROL_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
CATTR(inNodes)
const ag_node_id PRCM_MOD_GPIO0_inNodes[] = {
    PRCM_MUX_GPIO_DBCLK,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
CATTR(inNodes)
const ag_node_id PRCM_MOD_I2C0_inNodes[] = {
    PRCM_DIV_UART5,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_L4WKUP
CATTR(inNodes)
const ag_node_id PRCM_MOD_L4WKUP_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
CATTR(inNodes)
const ag_node_id PRCM_MOD_SYNCTIMER_inNodes[] = {
    PRCM_MUX_SYNCTIMER32K,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER0_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_MUX_TIMER0,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
CATTR(inNodes)
const ag_node_id PRCM_MOD_TIMER1_inNodes[] = {
    PRCM_MUX_TIMER1,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_UART0
CATTR(inNodes)
const ag_node_id PRCM_MOD_UART0_inNodes[] = {
    PRCM_DIV_UART5,
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
CATTR(inNodes)
const ag_node_id PRCM_MOD_WKUP_M3_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PRCM_MOD_EFUSE
CATTR(inNodes)
const ag_node_id PRCM_MOD_EFUSE_inNodes[] = {
    PRCM_ROOT_CLK_SYS_CLKIN,
};
#endif /* BUILDCFG_PRCM_MOD_EFUSE */


/*----------------------------------------------------------------------------*/ 
CATTR(prcmNodes)
const ag_node prcmNodes[] =
{
    { &PRCM_ROOT_CLK_MPU_PLL_prop, NULL, 0 }, 
    { &PRCM_ROOT_CLK_SYS_CLKIN_prop, NULL, 0 }, 
    { &PRCM_ROOT_CLK_TCLKIN_prop, NULL, 0 }, 
    { &PRCM_ROOT_CLK_32K_MOSC_prop, NULL, 0 }, 
    { &PRCM_ROOT_CLK_32K_PER_prop, NULL, 0 }, 
    { &PRCM_ROOT_CLK_32K_RC_prop, NULL, 0 }, 
    { &PRCM_ROOT_CLK_32K_RTC_prop, NULL, 0 }, 
    { &PRCM_ROOT_CLK_32K_TPM_prop, NULL, 0 }, 
    { &PRCM_MUX_CLKOUT1SEL2_prop, PRCM_MUX_CLKOUT1SEL2_inNodes, VSIZE_TYPE(PRCM_MUX_CLKOUT1SEL2_inNodes, ag_node_id) }, 
    { &PRCM_MUX_CLKOUT1_prop, PRCM_MUX_CLKOUT1_inNodes, VSIZE_TYPE(PRCM_MUX_CLKOUT1_inNodes, ag_node_id) }, 
    { &PRCM_MUX_CLKOUT_32K_prop, PRCM_MUX_CLKOUT_32K_inNodes, VSIZE_TYPE(PRCM_MUX_CLKOUT_32K_inNodes, ag_node_id) }, 
    { &PRCM_MUX_CLKOUT1_MUX1_prop, PRCM_MUX_CLKOUT1_MUX1_inNodes, VSIZE_TYPE(PRCM_MUX_CLKOUT1_MUX1_inNodes, ag_node_id) }, 
    { &PRCM_MUX_CLKOUT1_MUX2_prop, PRCM_MUX_CLKOUT1_MUX2_inNodes, VSIZE_TYPE(PRCM_MUX_CLKOUT1_MUX2_inNodes, ag_node_id) }, 
    { &PRCM_MUX_CLKOUT1_MUX3_prop, PRCM_MUX_CLKOUT1_MUX3_inNodes, VSIZE_TYPE(PRCM_MUX_CLKOUT1_MUX3_inNodes, ag_node_id) }, 
    { &PRCM_MUX_SGX_CLKSEL_prop, PRCM_MUX_SGX_CLKSEL_inNodes, VSIZE_TYPE(PRCM_MUX_SGX_CLKSEL_inNodes, ag_node_id) }, 
    { &PRCM_MUX_MAG_FCLK_prop, PRCM_MUX_MAG_FCLK_inNodes, VSIZE_TYPE(PRCM_MUX_MAG_FCLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_ICSS_OCP_CLK_prop, PRCM_MUX_ICSS_OCP_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_ICSS_OCP_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_LCD_CLK_prop, PRCM_MUX_LCD_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_LCD_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER10_CLK_prop, PRCM_MUX_TIMER10_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER10_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER11_CLK_prop, PRCM_MUX_TIMER11_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER11_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER1_CLK_prop, PRCM_MUX_TIMER1_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER1_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER2_CLK_prop, PRCM_MUX_TIMER2_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER2_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER3_CLK_prop, PRCM_MUX_TIMER3_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER3_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER4_CLK_prop, PRCM_MUX_TIMER4_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER4_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER5_CLK_prop, PRCM_MUX_TIMER5_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER5_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER6_CLK_prop, PRCM_MUX_TIMER6_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER6_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER8_CLK_prop, PRCM_MUX_TIMER8_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER8_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER9_CLK_prop, PRCM_MUX_TIMER9_CLK_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER9_CLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_CPTS_RFT_prop, PRCM_MUX_CPTS_RFT_inNodes, VSIZE_TYPE(PRCM_MUX_CPTS_RFT_inNodes, ag_node_id) }, 
    { &PRCM_MUX_USBPHY_32KHZ_prop, PRCM_MUX_USBPHY_32KHZ_inNodes, VSIZE_TYPE(PRCM_MUX_USBPHY_32KHZ_inNodes, ag_node_id) }, 
    { &PRCM_MUX_WDT0_prop, PRCM_MUX_WDT0_inNodes, VSIZE_TYPE(PRCM_MUX_WDT0_inNodes, ag_node_id) }, 
    { &PRCM_MUX_WDT1_prop, PRCM_MUX_WDT1_inNodes, VSIZE_TYPE(PRCM_MUX_WDT1_inNodes, ag_node_id) }, 
    { &PRCM_MUX_USIM0_FCLK_prop, PRCM_MUX_USIM0_FCLK_inNodes, VSIZE_TYPE(PRCM_MUX_USIM0_FCLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_USIM1_FCLK_prop, PRCM_MUX_USIM1_FCLK_inNodes, VSIZE_TYPE(PRCM_MUX_USIM1_FCLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_USIM_DBCLKMUX_prop, PRCM_MUX_USIM_DBCLKMUX_inNodes, VSIZE_TYPE(PRCM_MUX_USIM_DBCLKMUX_inNodes, ag_node_id) }, 
    { &PRCM_MUX_GPIO_DBCLK_prop, PRCM_MUX_GPIO_DBCLK_inNodes, VSIZE_TYPE(PRCM_MUX_GPIO_DBCLK_inNodes, ag_node_id) }, 
    { &PRCM_MUX_SYNCTIMER32K_prop, PRCM_MUX_SYNCTIMER32K_inNodes, VSIZE_TYPE(PRCM_MUX_SYNCTIMER32K_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER0_prop, PRCM_MUX_TIMER0_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER0_inNodes, ag_node_id) }, 
    { &PRCM_MUX_TIMER1_prop, PRCM_MUX_TIMER1_inNodes, VSIZE_TYPE(PRCM_MUX_TIMER1_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CORE_L4_prop, PRCM_DIV_CORE_L4_inNodes, VSIZE_TYPE(PRCM_DIV_CORE_L4_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CORE_25M_prop, PRCM_DIV_CORE_25M_inNodes, VSIZE_TYPE(PRCM_DIV_CORE_25M_inNodes, ag_node_id) }, 
    { &PRCM_DIV_SYSCLK_prop, PRCM_DIV_SYSCLK_inNodes, VSIZE_TYPE(PRCM_DIV_SYSCLK_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CLKOUT1SEL0DIV_prop, PRCM_DIV_CLKOUT1SEL0DIV_inNodes, VSIZE_TYPE(PRCM_DIV_CLKOUT1SEL0DIV_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CLKOUT1SEL2DIV1_prop, PRCM_DIV_CLKOUT1SEL2DIV1_inNodes, VSIZE_TYPE(PRCM_DIV_CLKOUT1SEL2DIV1_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CLKOUT1SEL2DIV2_prop, PRCM_DIV_CLKOUT1SEL2DIV2_inNodes, VSIZE_TYPE(PRCM_DIV_CLKOUT1SEL2DIV2_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CLKOUT2_DIV1_prop, PRCM_DIV_CLKOUT2_DIV1_inNodes, VSIZE_TYPE(PRCM_DIV_CLKOUT2_DIV1_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CLKOUT2_DIV2_prop, PRCM_DIV_CLKOUT2_DIV2_inNodes, VSIZE_TYPE(PRCM_DIV_CLKOUT2_DIV2_inNodes, ag_node_id) }, 
    { &PRCM_DIV_DLL_AGING_CLK_prop, PRCM_DIV_DLL_AGING_CLK_inNodes, VSIZE_TYPE(PRCM_DIV_DLL_AGING_CLK_inNodes, ag_node_id) }, 
    { &PRCM_DIV_GFX_FCLK_prop, PRCM_DIV_GFX_FCLK_inNodes, VSIZE_TYPE(PRCM_DIV_GFX_FCLK_inNodes, ag_node_id) }, 
    { &PRCM_DIV_PERS_CLK_prop, PRCM_DIV_PERS_CLK_inNodes, VSIZE_TYPE(PRCM_DIV_PERS_CLK_inNodes, ag_node_id) }, 
    { &PRCM_DIV_MMC_prop, PRCM_DIV_MMC_inNodes, VSIZE_TYPE(PRCM_DIV_MMC_inNodes, ag_node_id) }, 
    { &PRCM_DIV_PDA2CAD8896B3447FD_prop, PRCM_DIV_PDA2CAD8896B3447FD_inNodes, VSIZE_TYPE(PRCM_DIV_PDA2CAD8896B3447FD_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CPSW_125MHZ_OCP_prop, PRCM_DIV_CPSW_125MHZ_OCP_inNodes, VSIZE_TYPE(PRCM_DIV_CPSW_125MHZ_OCP_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CPSW_50M_prop, PRCM_DIV_CPSW_50M_inNodes, VSIZE_TYPE(PRCM_DIV_CPSW_50M_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CPSW_5M_prop, PRCM_DIV_CPSW_5M_inNodes, VSIZE_TYPE(PRCM_DIV_CPSW_5M_inNodes, ag_node_id) }, 
    { &PRCM_DIV_USIM_FCLK_prop, PRCM_DIV_USIM_FCLK_inNodes, VSIZE_TYPE(PRCM_DIV_USIM_FCLK_inNodes, ag_node_id) }, 
    { &PRCM_DIV_VTP_CLK_prop, PRCM_DIV_VTP_CLK_inNodes, VSIZE_TYPE(PRCM_DIV_VTP_CLK_inNodes, ag_node_id) }, 
    { &PRCM_DIV_CLK_DIV_24_prop, PRCM_DIV_CLK_DIV_24_inNodes, VSIZE_TYPE(PRCM_DIV_CLK_DIV_24_inNodes, ag_node_id) }, 
    { &PRCM_DIV_UART5_prop, PRCM_DIV_UART5_inNodes, VSIZE_TYPE(PRCM_DIV_UART5_inNodes, ag_node_id) }, 
    { &PRCM_DPLL_CORE_prop, PRCM_DPLL_CORE_inNodes, VSIZE_TYPE(PRCM_DPLL_CORE_inNodes, ag_node_id) }, 
    { &PRCM_DPLL_DDR_prop, PRCM_DPLL_DDR_inNodes, VSIZE_TYPE(PRCM_DPLL_DDR_inNodes, ag_node_id) }, 
    { &PRCM_DPLL_DISP_prop, PRCM_DPLL_DISP_inNodes, VSIZE_TYPE(PRCM_DPLL_DISP_inNodes, ag_node_id) }, 
    { &PRCM_DPLL_EXTDEV_prop, PRCM_DPLL_EXTDEV_inNodes, VSIZE_TYPE(PRCM_DPLL_EXTDEV_inNodes, ag_node_id) }, 
    { &PRCM_DPLL_MPU_prop, PRCM_DPLL_MPU_inNodes, VSIZE_TYPE(PRCM_DPLL_MPU_inNodes, ag_node_id) }, 
    { &PRCM_DPLL_PER_prop, PRCM_DPLL_PER_inNodes, VSIZE_TYPE(PRCM_DPLL_PER_inNodes, ag_node_id) }, 

#ifdef BUILDCFG_PRCM_MOD_CEFUSE
    { &PRCM_MOD_CEFUSE_prop, PRCM_MOD_CEFUSE_inNodes, VSIZE_TYPE(PRCM_MOD_CEFUSE_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
    { &PRCM_MOD_DEBUGSS_prop, PRCM_MOD_DEBUGSS_inNodes, VSIZE_TYPE(PRCM_MOD_DEBUGSS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PRCM_MOD_DSS
    { &PRCM_MOD_DSS_prop, PRCM_MOD_DSS_inNodes, VSIZE_TYPE(PRCM_MOD_DSS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DSS */
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
    { &PRCM_MOD_EMIF_FW_prop, PRCM_MOD_EMIF_FW_inNodes, VSIZE_TYPE(PRCM_MOD_EMIF_FW_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_DDRPHY
    { &PRCM_MOD_DDRPHY_prop, PRCM_MOD_DDRPHY_inNodes, VSIZE_TYPE(PRCM_MOD_DDRPHY_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PRCM_MOD_DLL
    { &PRCM_MOD_DLL_prop, PRCM_MOD_DLL_inNodes, VSIZE_TYPE(PRCM_MOD_DLL_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DLL */
#ifdef BUILDCFG_PRCM_MOD_DLL_AGING
    { &PRCM_MOD_DLL_AGING_prop, PRCM_MOD_DLL_AGING_inNodes, VSIZE_TYPE(PRCM_MOD_DLL_AGING_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PRCM_MOD_EMIF
    { &PRCM_MOD_EMIF_prop, PRCM_MOD_EMIF_inNodes, VSIZE_TYPE(PRCM_MOD_EMIF_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GPMC
    { &PRCM_MOD_GPMC_prop, PRCM_MOD_GPMC_inNodes, VSIZE_TYPE(PRCM_MOD_GPMC_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_MMC0
    { &PRCM_MOD_MMC0_prop, PRCM_MOD_MMC0_inNodes, VSIZE_TYPE(PRCM_MOD_MMC0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
    { &PRCM_MOD_MMC1_prop, PRCM_MOD_MMC1_inNodes, VSIZE_TYPE(PRCM_MOD_MMC1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PRCM_MOD_MMC2
    { &PRCM_MOD_MMC2_prop, PRCM_MOD_MMC2_inNodes, VSIZE_TYPE(PRCM_MOD_MMC2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
    { &PRCM_MOD_OCMCRAM_prop, PRCM_MOD_OCMCRAM_inNodes, VSIZE_TYPE(PRCM_MOD_OCMCRAM_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_OTFA_EMIF
    { &PRCM_MOD_OTFA_EMIF_prop, PRCM_MOD_OTFA_EMIF_inNodes, VSIZE_TYPE(PRCM_MOD_OTFA_EMIF_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GFX
    { &PRCM_MOD_GFX_prop, PRCM_MOD_GFX_inNodes, VSIZE_TYPE(PRCM_MOD_GFX_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GFX */
#ifdef BUILDCFG_PRCM_MOD_GPIO1
    { &PRCM_MOD_GPIO1_prop, PRCM_MOD_GPIO1_inNodes, VSIZE_TYPE(PRCM_MOD_GPIO1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO2
    { &PRCM_MOD_GPIO2_prop, PRCM_MOD_GPIO2_inNodes, VSIZE_TYPE(PRCM_MOD_GPIO2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PRCM_MOD_GPIO3
    { &PRCM_MOD_GPIO3_prop, PRCM_MOD_GPIO3_inNodes, VSIZE_TYPE(PRCM_MOD_GPIO3_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PRCM_MOD_GPIO4
    { &PRCM_MOD_GPIO4_prop, PRCM_MOD_GPIO4_inNodes, VSIZE_TYPE(PRCM_MOD_GPIO4_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PRCM_MOD_GPIO5
    { &PRCM_MOD_GPIO5_prop, PRCM_MOD_GPIO5_inNodes, VSIZE_TYPE(PRCM_MOD_GPIO5_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
    { &PRCM_MOD_MAG_CARD_prop, PRCM_MOD_MAG_CARD_inNodes, VSIZE_TYPE(PRCM_MOD_MAG_CARD_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PRCM_MOD_L3
    { &PRCM_MOD_L3_prop, PRCM_MOD_L3_inNodes, VSIZE_TYPE(PRCM_MOD_L3_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_L3 */
#ifdef BUILDCFG_PRCM_MOD_L3_INSTR
    { &PRCM_MOD_L3_INSTR_prop, PRCM_MOD_L3_INSTR_inNodes, VSIZE_TYPE(PRCM_MOD_L3_INSTR_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PRCM_MOD_L4FW
    { &PRCM_MOD_L4FW_prop, PRCM_MOD_L4FW_inNodes, VSIZE_TYPE(PRCM_MOD_L4FW_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PRCM_MOD_L4LS
    { &PRCM_MOD_L4LS_prop, PRCM_MOD_L4LS_inNodes, VSIZE_TYPE(PRCM_MOD_L4LS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PRCM_MOD_L4_HS
    { &PRCM_MOD_L4_HS_prop, PRCM_MOD_L4_HS_inNodes, VSIZE_TYPE(PRCM_MOD_L4_HS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PRCM_MOD_ICSS
    { &PRCM_MOD_ICSS_prop, PRCM_MOD_ICSS_inNodes, VSIZE_TYPE(PRCM_MOD_ICSS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PRCM_MOD_IEEE5000
    { &PRCM_MOD_IEEE5000_prop, PRCM_MOD_IEEE5000_inNodes, VSIZE_TYPE(PRCM_MOD_IEEE5000_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PRCM_MOD_LCDC
    { &PRCM_MOD_LCDC_prop, PRCM_MOD_LCDC_inNodes, VSIZE_TYPE(PRCM_MOD_LCDC_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PRCM_MOD_MSTR_EXPS
    { &PRCM_MOD_MSTR_EXPS_prop, PRCM_MOD_MSTR_EXPS_inNodes, VSIZE_TYPE(PRCM_MOD_MSTR_EXPS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PRCM_MOD_SLV_EXPS
    { &PRCM_MOD_SLV_EXPS_prop, PRCM_MOD_SLV_EXPS_inNodes, VSIZE_TYPE(PRCM_MOD_SLV_EXPS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PRCM_MOD_TPCC
    { &PRCM_MOD_TPCC_prop, PRCM_MOD_TPCC_inNodes, VSIZE_TYPE(PRCM_MOD_TPCC_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PRCM_MOD_TPTC0
    { &PRCM_MOD_TPTC0_prop, PRCM_MOD_TPTC0_inNodes, VSIZE_TYPE(PRCM_MOD_TPTC0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PRCM_MOD_TPTC1
    { &PRCM_MOD_TPTC1_prop, PRCM_MOD_TPTC1_inNodes, VSIZE_TYPE(PRCM_MOD_TPTC1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PRCM_MOD_TPTC2
    { &PRCM_MOD_TPTC2_prop, PRCM_MOD_TPTC2_inNodes, VSIZE_TYPE(PRCM_MOD_TPTC2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PRCM_MOD_DCAN0
    { &PRCM_MOD_DCAN0_prop, PRCM_MOD_DCAN0_inNodes, VSIZE_TYPE(PRCM_MOD_DCAN0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PRCM_MOD_DCAN1
    { &PRCM_MOD_DCAN1_prop, PRCM_MOD_DCAN1_inNodes, VSIZE_TYPE(PRCM_MOD_DCAN1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PRCM_MOD_ELM
    { &PRCM_MOD_ELM_prop, PRCM_MOD_ELM_inNodes, VSIZE_TYPE(PRCM_MOD_ELM_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_ELM */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS0
    { &PRCM_MOD_EPWMSS0_prop, PRCM_MOD_EPWMSS0_inNodes, VSIZE_TYPE(PRCM_MOD_EPWMSS0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS1
    { &PRCM_MOD_EPWMSS1_prop, PRCM_MOD_EPWMSS1_inNodes, VSIZE_TYPE(PRCM_MOD_EPWMSS1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS2
    { &PRCM_MOD_EPWMSS2_prop, PRCM_MOD_EPWMSS2_inNodes, VSIZE_TYPE(PRCM_MOD_EPWMSS2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS3
    { &PRCM_MOD_EPWMSS3_prop, PRCM_MOD_EPWMSS3_inNodes, VSIZE_TYPE(PRCM_MOD_EPWMSS3_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS4
    { &PRCM_MOD_EPWMSS4_prop, PRCM_MOD_EPWMSS4_inNodes, VSIZE_TYPE(PRCM_MOD_EPWMSS4_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS5
    { &PRCM_MOD_EPWMSS5_prop, PRCM_MOD_EPWMSS5_inNodes, VSIZE_TYPE(PRCM_MOD_EPWMSS5_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PRCM_MOD_ERMC
    { &PRCM_MOD_ERMC_prop, PRCM_MOD_ERMC_inNodes, VSIZE_TYPE(PRCM_MOD_ERMC_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PRCM_MOD_HDQ1W
    { &PRCM_MOD_HDQ1W_prop, PRCM_MOD_HDQ1W_inNodes, VSIZE_TYPE(PRCM_MOD_HDQ1W_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PRCM_MOD_I2C1
    { &PRCM_MOD_I2C1_prop, PRCM_MOD_I2C1_inNodes, VSIZE_TYPE(PRCM_MOD_I2C1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PRCM_MOD_I2C2
    { &PRCM_MOD_I2C2_prop, PRCM_MOD_I2C2_inNodes, VSIZE_TYPE(PRCM_MOD_I2C2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
    { &PRCM_MOD_MCASP0_prop, PRCM_MOD_MCASP0_inNodes, VSIZE_TYPE(PRCM_MOD_MCASP0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
    { &PRCM_MOD_QSPI_prop, PRCM_MOD_QSPI_inNodes, VSIZE_TYPE(PRCM_MOD_QSPI_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_SPI0
    { &PRCM_MOD_SPI0_prop, PRCM_MOD_SPI0_inNodes, VSIZE_TYPE(PRCM_MOD_SPI0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PRCM_MOD_SPI1
    { &PRCM_MOD_SPI1_prop, PRCM_MOD_SPI1_inNodes, VSIZE_TYPE(PRCM_MOD_SPI1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PRCM_MOD_SPI2
    { &PRCM_MOD_SPI2_prop, PRCM_MOD_SPI2_inNodes, VSIZE_TYPE(PRCM_MOD_SPI2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PRCM_MOD_SPI3
    { &PRCM_MOD_SPI3_prop, PRCM_MOD_SPI3_inNodes, VSIZE_TYPE(PRCM_MOD_SPI3_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PRCM_MOD_SPI4
    { &PRCM_MOD_SPI4_prop, PRCM_MOD_SPI4_inNodes, VSIZE_TYPE(PRCM_MOD_SPI4_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER10
    { &PRCM_MOD_TIMER10_prop, PRCM_MOD_TIMER10_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER10_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PRCM_MOD_TIMER11
    { &PRCM_MOD_TIMER11_prop, PRCM_MOD_TIMER11_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER11_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PRCM_MOD_TIMER2
    { &PRCM_MOD_TIMER2_prop, PRCM_MOD_TIMER2_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER3
    { &PRCM_MOD_TIMER3_prop, PRCM_MOD_TIMER3_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER3_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PRCM_MOD_TIMER4
    { &PRCM_MOD_TIMER4_prop, PRCM_MOD_TIMER4_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER4_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER5
    { &PRCM_MOD_TIMER5_prop, PRCM_MOD_TIMER5_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER5_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PRCM_MOD_TIMER6
    { &PRCM_MOD_TIMER6_prop, PRCM_MOD_TIMER6_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER6_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PRCM_MOD_TIMER7
    { &PRCM_MOD_TIMER7_prop, PRCM_MOD_TIMER7_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER7_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PRCM_MOD_TIMER8
    { &PRCM_MOD_TIMER8_prop, PRCM_MOD_TIMER8_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER8_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PRCM_MOD_TIMER9
    { &PRCM_MOD_TIMER9_prop, PRCM_MOD_TIMER9_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER9_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PRCM_MOD_UART1
    { &PRCM_MOD_UART1_prop, PRCM_MOD_UART1_inNodes, VSIZE_TYPE(PRCM_MOD_UART1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PRCM_MOD_UART2
    { &PRCM_MOD_UART2_prop, PRCM_MOD_UART2_inNodes, VSIZE_TYPE(PRCM_MOD_UART2_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PRCM_MOD_UART3
    { &PRCM_MOD_UART3_prop, PRCM_MOD_UART3_inNodes, VSIZE_TYPE(PRCM_MOD_UART3_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PRCM_MOD_UART4
    { &PRCM_MOD_UART4_prop, PRCM_MOD_UART4_inNodes, VSIZE_TYPE(PRCM_MOD_UART4_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PRCM_MOD_UART5
    { &PRCM_MOD_UART5_prop, PRCM_MOD_UART5_inNodes, VSIZE_TYPE(PRCM_MOD_UART5_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
    { &PRCM_MOD_CPGMAC0_prop, PRCM_MOD_CPGMAC0_inNodes, VSIZE_TYPE(PRCM_MOD_CPGMAC0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PRCM_MOD_MAILBOX0
    { &PRCM_MOD_MAILBOX0_prop, PRCM_MOD_MAILBOX0_inNodes, VSIZE_TYPE(PRCM_MOD_MAILBOX0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PRCM_MOD_MCASP1
    { &PRCM_MOD_MCASP1_prop, PRCM_MOD_MCASP1_inNodes, VSIZE_TYPE(PRCM_MOD_MCASP1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PRCM_MOD_SPARE0
    { &PRCM_MOD_SPARE0_prop, PRCM_MOD_SPARE0_inNodes, VSIZE_TYPE(PRCM_MOD_SPARE0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE1
    { &PRCM_MOD_SPARE1_prop, PRCM_MOD_SPARE1_inNodes, VSIZE_TYPE(PRCM_MOD_SPARE1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
    { &PRCM_MOD_SPINLOCK_prop, PRCM_MOD_SPINLOCK_inNodes, VSIZE_TYPE(PRCM_MOD_SPINLOCK_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_MPU
    { &PRCM_MOD_MPU_prop, PRCM_MOD_MPU_inNodes, VSIZE_TYPE(PRCM_MOD_MPU_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_MPU */
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
    { &PRCM_MOD_OCP_WP_NOC_prop, PRCM_MOD_OCP_WP_NOC_inNodes, VSIZE_TYPE(PRCM_MOD_OCP_WP_NOC_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PRCM_MOD_RTC
    { &PRCM_MOD_RTC_prop, PRCM_MOD_RTC_inNodes, VSIZE_TYPE(PRCM_MOD_RTC_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_RTC */
#ifdef BUILDCFG_PRCM_MOD_AES0
    { &PRCM_MOD_AES0_prop, PRCM_MOD_AES0_inNodes, VSIZE_TYPE(PRCM_MOD_AES0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
    { &PRCM_MOD_CRYPTODMA_prop, PRCM_MOD_CRYPTODMA_inNodes, VSIZE_TYPE(PRCM_MOD_CRYPTODMA_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
    { &PRCM_MOD_DES_prop, PRCM_MOD_DES_inNodes, VSIZE_TYPE(PRCM_MOD_DES_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_PKA
    { &PRCM_MOD_PKA_prop, PRCM_MOD_PKA_inNodes, VSIZE_TYPE(PRCM_MOD_PKA_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_RNG
    { &PRCM_MOD_RNG_prop, PRCM_MOD_RNG_inNodes, VSIZE_TYPE(PRCM_MOD_RNG_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_SHA0
    { &PRCM_MOD_SHA0_prop, PRCM_MOD_SHA0_inNodes, VSIZE_TYPE(PRCM_MOD_SHA0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
    { &PRCM_MOD_SMARTREFLEX0_prop, PRCM_MOD_SMARTREFLEX0_inNodes, VSIZE_TYPE(PRCM_MOD_SMARTREFLEX0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
    { &PRCM_MOD_SMARTREFLEX1_prop, PRCM_MOD_SMARTREFLEX1_inNodes, VSIZE_TYPE(PRCM_MOD_SMARTREFLEX1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
    { &PRCM_MOD_USB_PHY0_ALWAYS_ON_prop, PRCM_MOD_USB_PHY0_ALWAYS_ON_inNodes, VSIZE_TYPE(PRCM_MOD_USB_PHY0_ALWAYS_ON_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
    { &PRCM_MOD_USB_PHY1_ALWAYS_ON_prop, PRCM_MOD_USB_PHY1_ALWAYS_ON_inNodes, VSIZE_TYPE(PRCM_MOD_USB_PHY1_ALWAYS_ON_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_WDT0
    { &PRCM_MOD_WDT0_prop, PRCM_MOD_WDT0_inNodes, VSIZE_TYPE(PRCM_MOD_WDT0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
    { &PRCM_MOD_WDT1_prop, PRCM_MOD_WDT1_inNodes, VSIZE_TYPE(PRCM_MOD_WDT1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_TPMSS
    { &PRCM_MOD_TPMSS_prop, PRCM_MOD_TPMSS_inNodes, VSIZE_TYPE(PRCM_MOD_TPMSS_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
    { &PRCM_MOD_USBPHYOCP2SCP0_prop, PRCM_MOD_USBPHYOCP2SCP0_inNodes, VSIZE_TYPE(PRCM_MOD_USBPHYOCP2SCP0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
    { &PRCM_MOD_USBPHYOCP2SCP1_prop, PRCM_MOD_USBPHYOCP2SCP1_inNodes, VSIZE_TYPE(PRCM_MOD_USBPHYOCP2SCP1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
    { &PRCM_MOD_USB_OTG_SS0_prop, PRCM_MOD_USB_OTG_SS0_inNodes, VSIZE_TYPE(PRCM_MOD_USB_OTG_SS0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
    { &PRCM_MOD_USB_OTG_SS1_prop, PRCM_MOD_USB_OTG_SS1_inNodes, VSIZE_TYPE(PRCM_MOD_USB_OTG_SS1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
    { &PRCM_MOD_USIM0_prop, PRCM_MOD_USIM0_inNodes, VSIZE_TYPE(PRCM_MOD_USIM0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
    { &PRCM_MOD_USIM1_prop, PRCM_MOD_USIM1_inNodes, VSIZE_TYPE(PRCM_MOD_USIM1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
    { &PRCM_MOD_VPFE0_prop, PRCM_MOD_VPFE0_inNodes, VSIZE_TYPE(PRCM_MOD_VPFE0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
    { &PRCM_MOD_VPFE1_prop, PRCM_MOD_VPFE1_inNodes, VSIZE_TYPE(PRCM_MOD_VPFE1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
    { &PRCM_MOD_ADC_TSC_prop, PRCM_MOD_ADC_TSC_inNodes, VSIZE_TYPE(PRCM_MOD_ADC_TSC_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
    { &PRCM_MOD_CLKDIV32K_prop, PRCM_MOD_CLKDIV32K_inNodes, VSIZE_TYPE(PRCM_MOD_CLKDIV32K_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
    { &PRCM_MOD_CONTROL_prop, PRCM_MOD_CONTROL_inNodes, VSIZE_TYPE(PRCM_MOD_CONTROL_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
    { &PRCM_MOD_GPIO0_prop, PRCM_MOD_GPIO0_inNodes, VSIZE_TYPE(PRCM_MOD_GPIO0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
    { &PRCM_MOD_I2C0_prop, PRCM_MOD_I2C0_inNodes, VSIZE_TYPE(PRCM_MOD_I2C0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_L4WKUP
    { &PRCM_MOD_L4WKUP_prop, PRCM_MOD_L4WKUP_inNodes, VSIZE_TYPE(PRCM_MOD_L4WKUP_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
    { &PRCM_MOD_SYNCTIMER_prop, PRCM_MOD_SYNCTIMER_inNodes, VSIZE_TYPE(PRCM_MOD_SYNCTIMER_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
    { &PRCM_MOD_TIMER0_prop, PRCM_MOD_TIMER0_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
    { &PRCM_MOD_TIMER1_prop, PRCM_MOD_TIMER1_inNodes, VSIZE_TYPE(PRCM_MOD_TIMER1_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_UART0
    { &PRCM_MOD_UART0_prop, PRCM_MOD_UART0_inNodes, VSIZE_TYPE(PRCM_MOD_UART0_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
    { &PRCM_MOD_WKUP_M3_prop, PRCM_MOD_WKUP_M3_inNodes, VSIZE_TYPE(PRCM_MOD_WKUP_M3_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PRCM_MOD_EFUSE
    { &PRCM_MOD_EFUSE_prop, PRCM_MOD_EFUSE_inNodes, VSIZE_TYPE(PRCM_MOD_EFUSE_inNodes, ag_node_id) }, 
#endif /* BUILDCFG_PRCM_MOD_EFUSE */

};

/*----------------------------------------------------------------------------*/
/*
 * \note  This array is sorted in ascending order of ResourceIds
 *        for fast binary search lookup.
 */
CATTR(resourceIdModuleIdPairElems)
const resourceIdModuleIdPair_t resourceIdModuleIdPairElems[] = {
#ifdef BUILDCFG_PRCM_MOD_MPU
    { CHIPDB_RES_ID_MPU, PRCM_MOD_MPU }, 
#endif /* BUILDCFG_PRCM_MOD_MPU */
#ifdef BUILDCFG_PRCM_MOD_DSS
    { CHIPDB_RES_ID_DSS, PRCM_MOD_DSS }, 
#endif /* BUILDCFG_PRCM_MOD_DSS */
#ifdef BUILDCFG_PRCM_MOD_EMIF
    { CHIPDB_RES_ID_EMIF, PRCM_MOD_EMIF }, 
#endif /* BUILDCFG_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GPMC
    { CHIPDB_RES_ID_GPMC, PRCM_MOD_GPMC }, 
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_DCAN0
    { CHIPDB_RES_ID_DCAN0, PRCM_MOD_DCAN0 }, 
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PRCM_MOD_DCAN1
    { CHIPDB_RES_ID_DCAN1, PRCM_MOD_DCAN1 }, 
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
    { CHIPDB_RES_ID_GPIO0, PRCM_MOD_GPIO0 }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_GPIO1
    { CHIPDB_RES_ID_GPIO1, PRCM_MOD_GPIO1 }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO2
    { CHIPDB_RES_ID_GPIO2, PRCM_MOD_GPIO2 }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PRCM_MOD_GPIO3
    { CHIPDB_RES_ID_GPIO3, PRCM_MOD_GPIO3 }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PRCM_MOD_GPIO4
    { CHIPDB_RES_ID_GPIO4, PRCM_MOD_GPIO4 }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PRCM_MOD_GPIO5
    { CHIPDB_RES_ID_GPIO5, PRCM_MOD_GPIO5 }, 
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
    { CHIPDB_RES_ID_I2C0, PRCM_MOD_I2C0 }, 
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_I2C1
    { CHIPDB_RES_ID_I2C1, PRCM_MOD_I2C1 }, 
#endif /* BUILDCFG_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PRCM_MOD_I2C2
    { CHIPDB_RES_ID_I2C2, PRCM_MOD_I2C2 }, 
#endif /* BUILDCFG_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
    { CHIPDB_RES_ID_MCASP0, PRCM_MOD_MCASP0 },
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_SPI0
    { CHIPDB_RES_ID_MCSPI0, PRCM_MOD_SPI0 }, 
#endif /* BUILDCFG_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PRCM_MOD_SPI1
    { CHIPDB_RES_ID_MCSPI1, PRCM_MOD_SPI1 }, 
#endif /* BUILDCFG_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PRCM_MOD_SPI2
    { CHIPDB_RES_ID_MCSPI2, PRCM_MOD_SPI2 }, 
#endif /* BUILDCFG_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PRCM_MOD_SPI3
    { CHIPDB_RES_ID_MCSPI3, PRCM_MOD_SPI3 }, 
#endif /* BUILDCFG_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PRCM_MOD_SPI4
    { CHIPDB_RES_ID_MCSPI4, PRCM_MOD_SPI4 }, 
#endif /* BUILDCFG_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
    { CHIPDB_RES_ID_QSPI, PRCM_MOD_QSPI }, 
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_UART0
    { CHIPDB_RES_ID_UART0, PRCM_MOD_UART0 }, 
#endif /* BUILDCFG_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PRCM_MOD_UART1
    { CHIPDB_RES_ID_UART1, PRCM_MOD_UART1 }, 
#endif /* BUILDCFG_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PRCM_MOD_UART2
    { CHIPDB_RES_ID_UART2, PRCM_MOD_UART2 }, 
#endif /* BUILDCFG_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PRCM_MOD_UART3
    { CHIPDB_RES_ID_UART3, PRCM_MOD_UART3 }, 
#endif /* BUILDCFG_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PRCM_MOD_UART4
    { CHIPDB_RES_ID_UART4, PRCM_MOD_UART4 }, 
#endif /* BUILDCFG_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PRCM_MOD_UART5
    { CHIPDB_RES_ID_UART5, PRCM_MOD_UART5 }, 
#endif /* BUILDCFG_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS0
    { CHIPDB_RES_ID_PWMSS0, PRCM_MOD_EPWMSS0 }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS1
    { CHIPDB_RES_ID_PWMSS1, PRCM_MOD_EPWMSS1 }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS2
    { CHIPDB_RES_ID_PWMSS2, PRCM_MOD_EPWMSS2 }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS3
    { CHIPDB_RES_ID_PWMSS3, PRCM_MOD_EPWMSS3 }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS4
    { CHIPDB_RES_ID_PWMSS4, PRCM_MOD_EPWMSS4 }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS5
    { CHIPDB_RES_ID_PWMSS5, PRCM_MOD_EPWMSS5 }, 
#endif /* BUILDCFG_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
    { CHIPDB_RES_ID_SPINLOCK, PRCM_MOD_SPINLOCK }, 
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_HDQ1W
    { CHIPDB_RES_ID_HDQ1W, PRCM_MOD_HDQ1W }, 
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PRCM_MOD_AES0
    { CHIPDB_RES_ID_AES, PRCM_MOD_AES0 }, 
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_RNG
    { CHIPDB_RES_ID_RNG, PRCM_MOD_RNG }, 
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_PKA
    { CHIPDB_RES_ID_PKA, PRCM_MOD_PKA }, 
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
    { CHIPDB_RES_ID_CRYPTODMA, PRCM_MOD_CRYPTODMA }, 
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
    { CHIPDB_RES_ID_DES, PRCM_MOD_DES }, 
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_SHA0
    { CHIPDB_RES_ID_SHA, PRCM_MOD_SHA0 }, 
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_GFX
    { CHIPDB_RES_ID_GFX, PRCM_MOD_GFX }, 
#endif /* BUILDCFG_PRCM_MOD_GFX */
#ifdef BUILDCFG_PRCM_MOD_TPCC
    { CHIPDB_RES_ID_EDMA3CC, PRCM_MOD_TPCC }, 
#endif /* BUILDCFG_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PRCM_MOD_TPTC0
    { CHIPDB_RES_ID_EDMA3TC0, PRCM_MOD_TPTC0 }, 
#endif /* BUILDCFG_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PRCM_MOD_TPTC1
    { CHIPDB_RES_ID_EDMA3TC1, PRCM_MOD_TPTC1 }, 
#endif /* BUILDCFG_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PRCM_MOD_TPTC2
    { CHIPDB_RES_ID_EDMA3TC2, PRCM_MOD_TPTC2 },
#endif /* BUILDCFG_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PRCM_MOD_OTFA_EMIF
    { CHIPDB_RES_ID_OTFA, PRCM_MOD_OTFA_EMIF }, 
#endif /* BUILDCFG_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PRCM_MOD_TPMSS
    { CHIPDB_RES_ID_TPMSS, PRCM_MOD_TPMSS }, 
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
    { CHIPDB_RES_ID_VPFE0, PRCM_MOD_VPFE0 }, 
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
    { CHIPDB_RES_ID_VPFE1, PRCM_MOD_VPFE1 }, 
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
    { CHIPDB_RES_ID_CPSW, PRCM_MOD_CPGMAC0 }, 
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
    { CHIPDB_RES_ID_USIM0, PRCM_MOD_USIM0 }, 
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
    { CHIPDB_RES_ID_USIM1, PRCM_MOD_USIM1 }, 
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
    { CHIPDB_RES_ID_ADC0, PRCM_MOD_ADC_TSC },
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PRCM_MOD_MMC0
    { CHIPDB_RES_ID_MMCSD0, PRCM_MOD_MMC0 }, 
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
    { CHIPDB_RES_ID_MMCSD1, PRCM_MOD_MMC1 }, 
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PRCM_MOD_MMC2
    { CHIPDB_RES_ID_MMCSD2, PRCM_MOD_MMC2 }, 
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
    { CHIPDB_RES_ID_DMTIMER0, PRCM_MOD_TIMER0 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER2
    { CHIPDB_RES_ID_DMTIMER2, PRCM_MOD_TIMER2 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER3
    { CHIPDB_RES_ID_DMTIMER3, PRCM_MOD_TIMER3 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PRCM_MOD_TIMER4
    { CHIPDB_RES_ID_DMTIMER4, PRCM_MOD_TIMER4 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER5
    { CHIPDB_RES_ID_DMTIMER5, PRCM_MOD_TIMER5 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PRCM_MOD_TIMER6
    { CHIPDB_RES_ID_DMTIMER6, PRCM_MOD_TIMER6 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PRCM_MOD_TIMER7
    { CHIPDB_RES_ID_DMTIMER7, PRCM_MOD_TIMER7 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PRCM_MOD_TIMER8
    { CHIPDB_RES_ID_DMTIMER8, PRCM_MOD_TIMER8 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PRCM_MOD_TIMER9
    { CHIPDB_RES_ID_DMTIMER9, PRCM_MOD_TIMER9 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PRCM_MOD_TIMER10
    { CHIPDB_RES_ID_DMTIMER10, PRCM_MOD_TIMER10 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PRCM_MOD_TIMER11
    { CHIPDB_RES_ID_DMTIMER11, PRCM_MOD_TIMER11 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
    { CHIPDB_RES_ID_DMTIMER1_1MS, PRCM_MOD_TIMER1 }, 
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_WDT0
    { CHIPDB_RES_ID_WDT0, PRCM_MOD_WDT0 }, 
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
    { CHIPDB_RES_ID_WDT1, PRCM_MOD_WDT1 }, 
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
    { CHIPDB_RES_ID_OCP_WP_NOC, PRCM_MOD_OCP_WP_NOC }, 
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
    { CHIPDB_RES_ID_SMARTREFLEX0, PRCM_MOD_SMARTREFLEX0 }, 
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
    { CHIPDB_RES_ID_SMARTREFLEX1, PRCM_MOD_SMARTREFLEX1 }, 
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_RTC
    { CHIPDB_RES_ID_RTCSS, PRCM_MOD_RTC },
#endif /* BUILDCFG_PRCM_MOD_RTC */
#ifdef BUILDCFG_PRCM_MOD_ICSS
    { CHIPDB_RES_ID_PRU_ICSS0, PRCM_MOD_ICSS },
#endif /* BUILDCFG_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
    { CHIPDB_RES_ID_CONTROL_MODULE, PRCM_MOD_CONTROL }, 
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
    { CHIPDB_RES_ID_DEBUGSS, PRCM_MOD_DEBUGSS }, 
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
    { CHIPDB_RES_ID_OCMCRAM, PRCM_MOD_OCMCRAM }, 
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
    { CHIPDB_RES_ID_SYNCTIMER, PRCM_MOD_SYNCTIMER }, 
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_ERMC
    { CHIPDB_RES_ID_ERMC, PRCM_MOD_ERMC }, 
#endif /* BUILDCFG_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PRCM_MOD_ELM
    { CHIPDB_RES_ID_ELM, PRCM_MOD_ELM }, 
#endif /* BUILDCFG_PRCM_MOD_ELM */
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
    { CHIPDB_RES_ID_EMIF_FW, PRCM_MOD_EMIF_FW }, 
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
    { CHIPDB_RES_ID_WKUP_PROC, PRCM_MOD_WKUP_M3 }, 
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
    { CHIPDB_RES_ID_USB_PHY_OCP2SCP0, PRCM_MOD_USBPHYOCP2SCP0 },
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
    { CHIPDB_RES_ID_USB_PHY_OCP2SCP1, PRCM_MOD_USBPHYOCP2SCP1 },
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
    { CHIPDB_RES_ID_USB_OTG_SS0, PRCM_MOD_USB_OTG_SS0 },
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
    { CHIPDB_RES_ID_USB_OTG_SS1, PRCM_MOD_USB_OTG_SS1 },
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */

};

/*----------------------------------------------------------------------------*/
/*
 * \note  This array is sorted in ascending order of ResourceIds
 *        for fast binary search lookup.
 */
CATTR(resourceIdModuleIdInstMap)
const chipdbResourceIdInfo_t resourceIdModuleIdInstMap[] = {
#ifdef BUILDCFG_PRCM_MOD_CEFUSE
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PRCM_MOD_DEBUGSS
    {CHIPDB_MOD_ID_DEBUGSS, 0U},
#endif /* BUILDCFG_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PRCM_MOD_DSS
    {CHIPDB_MOD_ID_DSS, 0U},
#endif /* BUILDCFG_PRCM_MOD_DSS */
#ifdef BUILDCFG_PRCM_MOD_EMIF_FW
    {CHIPDB_MOD_ID_EMIF_FW, 0U},
#endif /* BUILDCFG_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PRCM_MOD_DDRPHY
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PRCM_MOD_DLL
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_DLL */
#ifdef BUILDCFG_PRCM_MOD_DLL_AGING
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PRCM_MOD_EMIF
    {CHIPDB_MOD_ID_EMIF, 0U},
#endif /* BUILDCFG_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GPMC
    {CHIPDB_MOD_ID_GPMC, 0U},
#endif /* BUILDCFG_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PRCM_MOD_MMC0
    {CHIPDB_MOD_ID_MMCSD, 0U},
#endif /* BUILDCFG_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PRCM_MOD_MMC1
    {CHIPDB_MOD_ID_MMCSD, 1U},
#endif /* BUILDCFG_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PRCM_MOD_MMC2
    {CHIPDB_MOD_ID_MMCSD, 2U},
#endif /* BUILDCFG_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PRCM_MOD_OCMCRAM
    {CHIPDB_MOD_ID_OCMCRAM, 0U},
#endif /* BUILDCFG_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PRCM_MOD_OTFA_EMIF
    {CHIPDB_MOD_ID_OTFA, 0U},
#endif /* BUILDCFG_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PRCM_MOD_GFX
    {CHIPDB_MOD_ID_GFX, 0U},
#endif /* BUILDCFG_PRCM_MOD_GFX */
#ifdef BUILDCFG_PRCM_MOD_GPIO1
    {CHIPDB_MOD_ID_GPIO, 1U},
#endif /* BUILDCFG_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PRCM_MOD_GPIO2
    {CHIPDB_MOD_ID_GPIO, 2U},
#endif /* BUILDCFG_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PRCM_MOD_GPIO3
    {CHIPDB_MOD_ID_GPIO, 3U},
#endif /* BUILDCFG_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PRCM_MOD_GPIO4
    {CHIPDB_MOD_ID_GPIO, 4U},
#endif /* BUILDCFG_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PRCM_MOD_GPIO5
    {CHIPDB_MOD_ID_GPIO, 5U},
#endif /* BUILDCFG_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PRCM_MOD_MAG_CARD
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PRCM_MOD_L3
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_L3 */
#ifdef BUILDCFG_PRCM_MOD_L3_INSTR
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PRCM_MOD_L4FW
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PRCM_MOD_L4LS
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PRCM_MOD_L4_HS
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PRCM_MOD_ICSS
    {CHIPDB_MOD_ID_PRU_ICSS, 0U},
#endif /* BUILDCFG_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PRCM_MOD_IEEE5000
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PRCM_MOD_LCDC
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PRCM_MOD_MSTR_EXPS
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PRCM_MOD_SLV_EXPS
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PRCM_MOD_TPCC
    {CHIPDB_MOD_ID_EDMA3CC, 0U},
#endif /* BUILDCFG_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PRCM_MOD_TPTC0
    {CHIPDB_MOD_ID_EDMA3TC, 0U},
#endif /* BUILDCFG_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PRCM_MOD_TPTC1
    {CHIPDB_MOD_ID_EDMA3TC, 1U},
#endif /* BUILDCFG_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PRCM_MOD_TPTC2
    {CHIPDB_MOD_ID_EDMA3TC, 2U},
#endif /* BUILDCFG_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PRCM_MOD_DCAN0
    {CHIPDB_MOD_ID_DCAN, 0U},
#endif /* BUILDCFG_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PRCM_MOD_DCAN1
    {CHIPDB_MOD_ID_DCAN, 1U},
#endif /* BUILDCFG_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PRCM_MOD_ELM
    {CHIPDB_MOD_ID_ELM, 0U},
#endif /* BUILDCFG_PRCM_MOD_ELM */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS0
    {CHIPDB_MOD_ID_PWMSS, 0U},
#endif /* BUILDCFG_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS1
    {CHIPDB_MOD_ID_PWMSS, 1U},
#endif /* BUILDCFG_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS2
    {CHIPDB_MOD_ID_PWMSS, 2U},
#endif /* BUILDCFG_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS3
    {CHIPDB_MOD_ID_PWMSS, 3U},
#endif /* BUILDCFG_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS4
    {CHIPDB_MOD_ID_PWMSS, 4U},
#endif /* BUILDCFG_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PRCM_MOD_EPWMSS5
    {CHIPDB_MOD_ID_PWMSS, 5U},
#endif /* BUILDCFG_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PRCM_MOD_ERMC
    {CHIPDB_MOD_ID_ERMC, 0U},
#endif /* BUILDCFG_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PRCM_MOD_HDQ1W
    {CHIPDB_MOD_ID_HDQ1W, 0U},
#endif /* BUILDCFG_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PRCM_MOD_I2C1
    {CHIPDB_MOD_ID_I2C, 1U},
#endif /* BUILDCFG_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PRCM_MOD_I2C2
    {CHIPDB_MOD_ID_I2C, 2U},
#endif /* BUILDCFG_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PRCM_MOD_MCASP0
    {CHIPDB_MOD_ID_MCASP, 0U},
#endif /* BUILDCFG_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PRCM_MOD_QSPI
    {CHIPDB_MOD_ID_QSPI, 0U},
#endif /* BUILDCFG_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PRCM_MOD_SPI0
    {CHIPDB_MOD_ID_MCSPI, 0U},
#endif /* BUILDCFG_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PRCM_MOD_SPI1
    {CHIPDB_MOD_ID_MCSPI, 1U},
#endif /* BUILDCFG_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PRCM_MOD_SPI2
    {CHIPDB_MOD_ID_MCSPI, 2U},
#endif /* BUILDCFG_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PRCM_MOD_SPI3
    {CHIPDB_MOD_ID_MCSPI, 3U},
#endif /* BUILDCFG_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PRCM_MOD_SPI4
    {CHIPDB_MOD_ID_MCSPI, 4U},
#endif /* BUILDCFG_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER10
    {CHIPDB_MOD_ID_DMTIMER, 10U},
#endif /* BUILDCFG_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PRCM_MOD_TIMER11
    {CHIPDB_MOD_ID_DMTIMER, 11U},
#endif /* BUILDCFG_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PRCM_MOD_TIMER2
    {CHIPDB_MOD_ID_DMTIMER, 2U},
#endif /* BUILDCFG_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PRCM_MOD_TIMER3
    {CHIPDB_MOD_ID_DMTIMER, 3U},
#endif /* BUILDCFG_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PRCM_MOD_TIMER4
    {CHIPDB_MOD_ID_DMTIMER, 4U},
#endif /* BUILDCFG_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PRCM_MOD_TIMER5
    {CHIPDB_MOD_ID_DMTIMER, 5U},
#endif /* BUILDCFG_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PRCM_MOD_TIMER6
    {CHIPDB_MOD_ID_DMTIMER, 6U},
#endif /* BUILDCFG_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PRCM_MOD_TIMER7
    {CHIPDB_MOD_ID_DMTIMER, 7U},
#endif /* BUILDCFG_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PRCM_MOD_TIMER8
    {CHIPDB_MOD_ID_DMTIMER, 8U},
#endif /* BUILDCFG_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PRCM_MOD_TIMER9
    {CHIPDB_MOD_ID_DMTIMER, 9U},
#endif /* BUILDCFG_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PRCM_MOD_UART1
    {CHIPDB_MOD_ID_UART, 1U},
#endif /* BUILDCFG_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PRCM_MOD_UART2
    {CHIPDB_MOD_ID_UART, 2U},
#endif /* BUILDCFG_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PRCM_MOD_UART3
    {CHIPDB_MOD_ID_UART, 3U},
#endif /* BUILDCFG_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PRCM_MOD_UART4
    {CHIPDB_MOD_ID_UART, 4U},
#endif /* BUILDCFG_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PRCM_MOD_UART5
    {CHIPDB_MOD_ID_UART, 5U},
#endif /* BUILDCFG_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PRCM_MOD_CPGMAC0
    {CHIPDB_MOD_ID_CPSW, 0U},
#endif /* BUILDCFG_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PRCM_MOD_MAILBOX0
    {CHIPDB_MOD_ID_MAILBOX, 0U},
#endif /* BUILDCFG_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PRCM_MOD_MCASP1
    {CHIPDB_MOD_ID_MCASP, 1U},
#endif /* BUILDCFG_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PRCM_MOD_SPARE0
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PRCM_MOD_SPARE1
    {CHIPDB_MOD_ID_INVALID, 1U},
#endif /* BUILDCFG_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PRCM_MOD_SPINLOCK
    {CHIPDB_MOD_ID_SPINLOCK, 0U},
#endif /* BUILDCFG_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PRCM_MOD_MPU
    {CHIPDB_MOD_ID_MPU, 0U},
#endif /* BUILDCFG_PRCM_MOD_MPU */
#ifdef BUILDCFG_PRCM_MOD_OCP_WP_NOC
    {CHIPDB_MOD_ID_OCP_WP_NOC, 0U},
#endif /* BUILDCFG_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PRCM_MOD_RTC
    {CHIPDB_MOD_ID_RTC, 0U},
#endif /* BUILDCFG_PRCM_MOD_RTC */
#ifdef BUILDCFG_PRCM_MOD_AES0
    {CHIPDB_MOD_ID_AES, 0U},
#endif /* BUILDCFG_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PRCM_MOD_CRYPTODMA
    {CHIPDB_MOD_ID_CRYPTODMA, 0U},
#endif /* BUILDCFG_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PRCM_MOD_DES
    {CHIPDB_MOD_ID_DES, 0U},
#endif /* BUILDCFG_PRCM_MOD_DES */
#ifdef BUILDCFG_PRCM_MOD_PKA
    {CHIPDB_MOD_ID_PKA, 0U},
#endif /* BUILDCFG_PRCM_MOD_PKA */
#ifdef BUILDCFG_PRCM_MOD_RNG
    {CHIPDB_MOD_ID_RNG, 0U},
#endif /* BUILDCFG_PRCM_MOD_RNG */
#ifdef BUILDCFG_PRCM_MOD_SHA0
    {CHIPDB_MOD_ID_SHA, 0U},
#endif /* BUILDCFG_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX0
    {CHIPDB_MOD_ID_SMARTREFLEX, 0U},
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PRCM_MOD_SMARTREFLEX1
    {CHIPDB_MOD_ID_SMARTREFLEX, 1U},
#endif /* BUILDCFG_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PRCM_MOD_WDT0
    {CHIPDB_MOD_ID_WDT, 0U},
#endif /* BUILDCFG_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PRCM_MOD_WDT1
    {CHIPDB_MOD_ID_WDT, 1U},
#endif /* BUILDCFG_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PRCM_MOD_TPMSS
    {CHIPDB_MOD_ID_TPMSS, 0U},
#endif /* BUILDCFG_PRCM_MOD_TPMSS */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
    {CHIPDB_MOD_ID_USB_PHY_OCP2SCP, 0U},
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
    {CHIPDB_MOD_ID_USB_PHY_OCP2SCP, 1U},
#endif /* BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS0
    {CHIPDB_MOD_ID_USB_OTG_SS, 0U},
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PRCM_MOD_USB_OTG_SS1
    {CHIPDB_MOD_ID_USB_OTG_SS, 1U},
#endif /* BUILDCFG_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PRCM_MOD_USIM0
    {CHIPDB_MOD_ID_USIM, 0U},
#endif /* BUILDCFG_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PRCM_MOD_USIM1
    {CHIPDB_MOD_ID_USIM, 1U},
#endif /* BUILDCFG_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PRCM_MOD_VPFE0
    {CHIPDB_MOD_ID_VPFE, 0U},
#endif /* BUILDCFG_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PRCM_MOD_VPFE1
    {CHIPDB_MOD_ID_VPFE, 1U},
#endif /* BUILDCFG_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PRCM_MOD_ADC_TSC
    {CHIPDB_MOD_ID_ADC0, 0U},
#endif /* BUILDCFG_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PRCM_MOD_CLKDIV32K
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PRCM_MOD_CONTROL
    {CHIPDB_MOD_ID_CONTROL_MODULE, 0U},
#endif /* BUILDCFG_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PRCM_MOD_GPIO0
    {CHIPDB_MOD_ID_GPIO, 0U},
#endif /* BUILDCFG_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PRCM_MOD_I2C0
    {CHIPDB_MOD_ID_I2C, 0U},
#endif /* BUILDCFG_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PRCM_MOD_L4WKUP
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PRCM_MOD_SYNCTIMER
    {CHIPDB_MOD_ID_SYNCTIMER, 0U},
#endif /* BUILDCFG_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PRCM_MOD_TIMER0
    {CHIPDB_MOD_ID_DMTIMER, 0U},
#endif /* BUILDCFG_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PRCM_MOD_TIMER1
    {CHIPDB_MOD_ID_DMTIMER1_1MS, 1U},
#endif /* BUILDCFG_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PRCM_MOD_UART0
    {CHIPDB_MOD_ID_UART, 0U},
#endif /* BUILDCFG_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PRCM_MOD_WKUP_M3
    {CHIPDB_MOD_ID_WKUP_PROC, 0U},
#endif /* BUILDCFG_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PRCM_MOD_EFUSE
    {CHIPDB_MOD_ID_INVALID, 0U},
#endif /* BUILDCFG_PRCM_MOD_EFUSE */

};

/*----------------------------------------------------------------------------*/
static uint8_t prcmGraphVisited[ BITNSLOTS(VSIZE_TYPE(prcmNodes, ag_node)) ] = {0}; 

agraph prcmGraph = {
    VSIZE_TYPE(prcmNodes, ag_node)
    , prcmNodes 
    , 0 /* edges max */
    , NULL /* edges[] */
    , prcmGraphVisited
};

/* ========================================================================== */
/*                            Function Definitions                            */
/* ========================================================================== */

prcmModuleId_t PRCMGetModuleId(moduleInstanceId_t resourceId)
{
    uint32_t high = VSIZE_TYPE(resourceIdModuleIdPairElems, resourceIdModuleIdPair_t);
    uint32_t low = 0;
    uint32_t mid = 0;
  
    while(low <= high)
    {
        mid = low + (high - low)/2;
        if(resourceId == resourceIdModuleIdPairElems[mid].resId)
        {
            return resourceIdModuleIdPairElems[mid].modId;
        }
        else if(resourceId < resourceIdModuleIdPairElems[mid].resId)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return PRCM_MOD_UNDEF;
}
#ifdef __cplusplus
}
#endif /* __cplusplus */

