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
 * \file    PowerPRCM_deviceInit.c
 *
 * \brief   This file contains the BUS communication utility functions to
 *          communicate with the PMIC.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <ti/drv/pm/pmhal.h>
#include <ti/drv/pm/pmlib.h>
#include <ti/drv/pm/PowerExtended.h>
#include <ti/csl/hw_types.h>
#include <PowerPRCM_deviceInit.h>
#if defined (SOC_TDA2EX)
#include <ti/drv/pm/include/pmic/pmhal_tps65917.h>
#elif defined (SOC_AM571x) || defined (SOC_AM572x)
#include <ti/drv/pm/include/pmic/pmhal_tps659037.h>
#else
#include <ti/drv/pm/include/pmic/pmhal_tps659039.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Device Package read Shift */
#define POWERPRCM_PACKAGE_BIT_SHIFT (16U)

/** \brief Device Package read Mask */
#define POWERPRCM_PACKAGE_BIT_MASK  (0x30000U)

/** \brief Device Package read address */
#define POWERPRCM_PACKAGE_READ_ADDR \
    (SOC_CTRL_MODULE_WKUP_CORE_REGISTERS_BASE + CTRL_WKUP_STD_FUSE_DIE_ID_2)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x)
pmlibSysConfigPowerStateParams_t inputTable[] =
{{PMHAL_PRCM_MOD_DMA_SYSTEM,          PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DSP1,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DSP2,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DSS,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DMM,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF_OCP_FW,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
#if (defined (__ARM_ARCH_7A__) || defined (_TMS320C6X))
 {PMHAL_PRCM_MOD_EVE1,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_EVE2,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_EVE3,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_EVE4,                PMLIB_SYS_CONFIG_AUTO_CG       },
#endif
 {PMHAL_PRCM_MOD_CPGMAC,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER5,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER6,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER7,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER8,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
#if !defined (__TI_ARM_V7M4__)
 {PMHAL_PRCM_MOD_IPU1,                PMLIB_SYS_CONFIG_AUTO_CG       },
#endif
 {PMHAL_PRCM_MOD_IVA,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_SL2,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_IEEE1500_2_OCP,      PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_MMC1,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_CTRL_MODULE_BANDGAP, PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_INSTR,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_MAIN_2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPMC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_MAIN_1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU_EDMA,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU_PCIESS,          PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMC_RAM1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMC_RAM2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMC_RAM3,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VCP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VCP2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPCC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_CFG,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCP2SCP2,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SAR_ROM,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SPINLOCK,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX1,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX10,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX11,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX12,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX13,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX2,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX3,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX4,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX5,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX6,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX7,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX8,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX9,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C3,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C4,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER1,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER10,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER11,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER2,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER3,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER4,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER9,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_ELM,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCSPI1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO3,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO4,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO5,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO6,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO7,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO8,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER2,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP3,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP6,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_QSPI,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER3,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER13,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER14,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER15,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER16,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DMA_CRYPTO,          PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_MPU,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MPU_MPU_DBG,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VIP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VIP2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VIP3,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VPE,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DEBUG_LOGIC,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MPU_EMU_DBG,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_COUNTER_32K,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_WKUP,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SAR_RAM,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER12,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_WD_TIMER2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED}};
#endif

#if defined (SOC_AM572x)
pmlibSysConfigPowerStateParams_t inputTable[] =
{{PMHAL_PRCM_MOD_DMA_SYSTEM,          PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DSP1,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DSP2,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DSS,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DMM,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF_OCP_FW,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_CPGMAC,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER5,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER6,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER7,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER8,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
#if !defined (__TI_ARM_V7M4__)
 {PMHAL_PRCM_MOD_IPU1,                PMLIB_SYS_CONFIG_AUTO_CG       },
#endif
 {PMHAL_PRCM_MOD_IVA,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_SL2,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_IEEE1500_2_OCP,      PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_MMC1,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_CTRL_MODULE_BANDGAP, PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_INSTR,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_MAIN_2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPMC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_MAIN_1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU_EDMA,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU_PCIESS,          PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMC_RAM1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMC_RAM2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMC_RAM3,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VCP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VCP2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPCC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_CFG,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCP2SCP2,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SAR_ROM,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SPINLOCK,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX1,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX10,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX11,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX12,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX13,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX2,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX3,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX4,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX5,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX6,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX7,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX8,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX9,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C3,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C4,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER1,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER10,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER11,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER2,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER3,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER4,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER9,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_ELM,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCSPI1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO3,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO4,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO5,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO6,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO7,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO8,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER2,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP3,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP6,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_QSPI,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER3,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER13,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER14,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER15,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER16,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DMA_CRYPTO,          PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_MPU,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MPU_MPU_DBG,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VIP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VIP2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VIP3,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VPE,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DEBUG_LOGIC,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MPU_EMU_DBG,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_COUNTER_32K,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_WKUP,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SAR_RAM,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER12,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_WD_TIMER2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED}};
#endif

#if defined (SOC_AM571x) || defined (SOC_TDA2EX)
pmlibSysConfigPowerStateParams_t inputTable[] =
{{PMHAL_PRCM_MOD_IVA,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DMA_SYSTEM,          PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_DSP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DMM,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF_OCP_FW,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_CPGMAC,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C5,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER5,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER6,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER7,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER8,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
#if !defined (__TI_ARM_V7M4__)
 {PMHAL_PRCM_MOD_IPU1,                PMLIB_SYS_CONFIG_AUTO_CG       },
#endif
 {PMHAL_PRCM_MOD_SL2,                 PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_IEEE1500_2_OCP,      PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_MMC1,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_MMC2,                PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_CTRL_MODULE_BANDGAP, PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DLL_AGING,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_INSTR,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_MAIN_2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPMC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_MAIN_1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU_EDMA,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU_PCIESS,          PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMC_RAM1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VCP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VCP2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPCC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_CFG,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCP2SCP2,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SAR_ROM,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SPINLOCK,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX1,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX10,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX11,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX12,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX13,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX2,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX3,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX4,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX5,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX6,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX7,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX8,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX9,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C3,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C4,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER1,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER10,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER11,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER2,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER3,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER4,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER9,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_ELM,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCSPI1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO3,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO4,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO5,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO6,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO7,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO8,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER2,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP3,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP6,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_QSPI,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_PER3,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER13,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER14,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER15,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER16,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DMA_CRYPTO,          PMLIB_SYS_CONFIG_AUTO_CG       },
 {PMHAL_PRCM_MOD_MPU,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MPU_MPU_DBG,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VIP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_VPE,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DEBUG_LOGIC,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MPU_EMU_DBG,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_COUNTER_32K,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_WKUP,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SAR_RAM,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER12,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_WD_TIMER2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DSS,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DES3DES,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
};

#endif

const uint32_t numTableEntries = sizeof (inputTable) /
                                 sizeof (pmlibSysConfigPowerStateParams_t);

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

uint32_t PRCM_GetSiliconRev();

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PRCM_ConfigAllVoltageRails(uint32_t level, uint32_t siliconPkgType)
{
    pmErrCode_t     retVal = PM_SUCCESS;
    pmhalVmOppId_t  oppId;
    const pmhalPmicOperations_t *pmicOps;
    uint32_t        siliconRev;
#if defined (SOC_TDA2EX) || defined (SOC_AM571x)
    uint32_t        ivaAvsVolt, gpuAvsVolt, dspeveAvsVolt;
    pmhalPrcmVdId_t maxAvsVdId;
    pmhalPrcmVdId_t gangedVoltageRails[3U] = {PMHAL_PRCM_VD_IVAHD,
                                              PMHAL_PRCM_VD_GPU,
                                              PMHAL_PRCM_VD_DSPEVE};
    uint32_t        voltageCount = 0U;
#else
    pmhalPrcmVdId_t vdId;
#endif

    /* Register the I2C functions with the PMIC Communication to ensure the
     * PMIC can be communicated with I2C driver specific to SBL
     */

    if (level > Power_NUMPERFLEVELS)
    {
        retVal = PM_FAIL;
    }
    else
    {
        oppId  = (pmhalVmOppId_t) level;
        retVal = PM_SUCCESS;
    }
    if (retVal == PM_SUCCESS)
    {
        /*
         * Get the pmic ops and register with the pmic interface.
         */
#if defined (SOC_TDA2EX)
        pmicOps = PMHALTps65917GetPMICOps();
#elif defined (SOC_AM571x) || defined (SOC_AM572x)
        pmicOps = PMHALTps659037GetPMICOps();
#else
        pmicOps = PMHALTps659039GetPMICOps();
#endif
        retVal = PMHALPmicRegister(pmicOps);

        retVal = PMHALVMSetOpp(PMHAL_PRCM_VD_MPU, oppId, PM_TIMEOUT_INFINITE);

        /* Do not perform CORE AVS for ES1.0 Samples */
        siliconRev = PRCM_GetSiliconRev();
        if (0U != siliconRev)
        {
            /* VD_CORE can only support OPP_NOM */
            retVal |= PMHALVMSetOpp(PMHAL_PRCM_VD_CORE,
                                    PMHAL_VM_OPP_NOM,
                                    PM_TIMEOUT_INFINITE);
        }

#if defined (SOC_TDA2EX) || defined (SOC_AM571x)
        /* On TDA2EX EVM the IVAHD, GPU and DSP EVE rails are ganged. We find
         * the
         * maximum AVS voltage on these lines and then set the voltage to that
         * value
         */
        ivaAvsVolt    = PMHALVMGetAVS0EfuseVoltage(PMHAL_PRCM_VD_IVAHD, oppId);
        gpuAvsVolt    = PMHALVMGetAVS0EfuseVoltage(PMHAL_PRCM_VD_GPU, oppId);
        dspeveAvsVolt = PMHALVMGetAVS0EfuseVoltage(PMHAL_PRCM_VD_DSPEVE, oppId);

        if ((ivaAvsVolt >= gpuAvsVolt) && (ivaAvsVolt >= dspeveAvsVolt))
        {
            maxAvsVdId = PMHAL_PRCM_VD_IVAHD;
        }
        else if ((gpuAvsVolt >= dspeveAvsVolt) && (gpuAvsVolt >= ivaAvsVolt))
        {
            maxAvsVdId = PMHAL_PRCM_VD_GPU;
        }
        else
        {
            maxAvsVdId = PMHAL_PRCM_VD_DSPEVE;
        }

        retVal |= PMHALVMSetOpp(maxAvsVdId,
                                oppId, PM_TIMEOUT_INFINITE);
        /* Once the AVS and ABB is done for the voltage rail for which the AVS
         * EFUSE value is the highest. It is important to perform the ABB
         * configuration for the other voltage rails.
         */
        for (voltageCount = 0U;
             voltageCount < sizeof (gangedVoltageRails) /
             sizeof (pmhalPrcmVdId_t);
             voltageCount++)
        {
            if (gangedVoltageRails[voltageCount] != maxAvsVdId)
            {
                retVal |= PMHALVMEnableABB(gangedVoltageRails[voltageCount],
                                           oppId);
            }
            if (PM_SUCCESS != retVal)
            {
                break;
            }
        }
#else
        /*
         * Set the voltage for PMHAL_PRCM_VD_IVAHD, PMHAL_PRCM_VD_DSPEVE
         * and PMHAL_PRCM_VD_GPU.
         */
        for (vdId = PMHAL_PRCM_VD_IVAHD; vdId < PMHAL_PRCM_VD_RTC; vdId++)
        {
            retVal |= PMHALVMSetOpp(vdId,
                                    oppId, PM_TIMEOUT_INFINITE);
        }
#endif
    }
    return (int32_t) retVal;
}

void PRCM_UnlockControlIODSS(void)
{
    uint32_t tmpVar;
    /*Unlock CTRL_CORE_CONTROL_IO_2 for DSS access*/
    tmpVar = HW_RD_REG32(SOC_CTRL_MODULE_CORE_BASE + CTRL_CORE_CONTROL_IO_2 +
                         (uint32_t) 0x100);
    tmpVar |= 0x00000001U;
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_BASE + CTRL_CORE_CONTROL_IO_2 +
                (uint32_t) 0x100, tmpVar);
}

int32_t PRCM_InitModulePowerState()
{
    int32_t retVal = PM_SUCCESS;

    pmlibSysConfigErrReturn_t resultReturn[sizeof (inputTable) /
                                           sizeof (
                                               pmlibSysConfigPowerStateParams_t)
    ];

    const pmlibSysConfigPowerStateParams_t des3desDependency =
    {PMHAL_PRCM_MOD_L3_INSTR, PMLIB_SYS_CONFIG_ALWAYS_ENABLED};

    retVal = PMLIBSysConfigSetPowerState(&des3desDependency, 1U,
                                         PM_TIMEOUT_INFINITE, NULL);
#if defined (__TI_ARM_V7M4__)
    /* DES3DES does not complete its power sequence if the A15 is debug halted
     * Write to the DRM suspend control to ensure even if A15 is debug halted
     * the test case passes.
     */
    HW_WR_REG32(SOC_I_DRM_BASE + 0x23c, 0x50);

#endif

    retVal = PMLIBSysConfigSetPowerState(inputTable, (uint32_t) numTableEntries,
                                         PM_TIMEOUT_INFINITE,
                                         resultReturn);

    return retVal;
}

int32_t PRCM_ConfigAllDPLL(uint32_t level, uint32_t siliconPkgType)
{
    pmhalPrcmDpllConfig_t *dpllMpuCfg  = 0U;
    pmhalPrcmDpllConfig_t *dpllIvaCfg  = 0U;
    pmhalPrcmDpllConfig_t *dpllAbeCfg  = 0U;
    pmhalPrcmDpllConfig_t *dpllGmacCfg = 0U;
    pmhalPrcmDpllConfig_t *dpllDspCfg  = 0U;
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
    pmhalPrcmDpllConfig_t *dpllEveCfg = 0U;
#endif
    pmhalPrcmDpllConfig_t *dpllGpuCfg  = 0U;
    pmhalPrcmDpllConfig_t *dpllPcieCfg = 0U;
    pmhalPrcmDpllConfig_t *dpllCoreCfg = 0U;
    pmhalPrcmDpllConfig_t *dpllPerCfg = 0U;
    int32_t retVal   = 0;
    uint32_t sysFreq = 0;
    uint32_t opp;
    pmhalPrcmSysClkVal_t   sysClkFreq = PMHAL_PRCM_SYSCLK_20_MHZ;

    if (level > Power_PERFLEVEL_HIGH)
    {
        retVal = PM_FAIL;
    }
    else
    {
        opp    = level;
        retVal = PM_SUCCESS;
    }

    if (retVal == PM_SUCCESS)
    {
        sysFreq = PMHALCMGetSysClockFreq();

        if (sysFreq == 20000U)
        {
            sysClkFreq = PMHAL_PRCM_SYSCLK_20_MHZ;
        }
        else if (sysFreq == 19200U)
        {
            sysClkFreq = PMHAL_PRCM_SYSCLK_19_2_MHZ;
            /* PMHAL_PRCM_SYSCLK_19_2_MHZ is not tested in tda2xx*/
        }
        else
        {
            /* To remove MISRA C error */
        }
        /*Configure DPLL_CORE - L4_PER_L3_GICLK - UART1 Interface clock*/
        /*Configure prcm_dpll_core*/
        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_CORE,
                        sysClkFreq,
                        opp,
                        siliconPkgType,
                        &dpllCoreCfg);

        /* This selects CORE_IPU_ISS_BOOST_CLK as IPU functional clock */
        PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_IPU1_GFCLK_MUX, PMHAL_PRCM_DPLL_CORE);

        /* Config DPLL_CORE*/
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_CORE,
                                    dpllCoreCfg,
                                    PM_TIMEOUT_INFINITE);

        /*Configure DPLL_PER - UART1_GFCLK - UART1 Functional clock*/
        /*Configure prcm_dpll_per*/
        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_PER,
                        sysClkFreq,
                        opp,
                        siliconPkgType,
                        &dpllPerCfg);

        /* Config DPLL_PER */
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_PER,
                                    dpllPerCfg,
                                    PM_TIMEOUT_INFINITE);
        PMHALCMSetCdClockMode(PMHAL_PRCM_CD_COREAON,
                                PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP,
                                PM_TIMEOUT_INFINITE);

#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)

        if ((Power_PERFLEVEL_LOW == opp) &&
            (POWERPRCM_PACKAGE_TYPE_2 != siliconPkgType))
        {
            /* POWERPRCM_PACKAGE_TYPE_2 is for 17x17 package,
             * MPU opp Low is supported only for 17x17 package */
            opp = Power_PERFLEVEL_NOM;
        }
#endif

        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_MPU,
                              sysClkFreq,
                              opp,
                              siliconPkgType,
                              &dpllMpuCfg);
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_MPU,
                                      dpllMpuCfg,
                                      PM_TIMEOUT_INFINITE);

        if (retVal == PM_SUCCESS)
        {
            /*Configure prcm_dpll_dsp*/
            opp = level;
            PRCM_getDpllStructure(PMHAL_PRCM_DPLL_DSP,
                                  sysClkFreq,
                                  opp,
                                  siliconPkgType,
                                  &dpllDspCfg);
            retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_DSP,
                                          dpllDspCfg,
                                          PM_TIMEOUT_INFINITE);
        }
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
        if (retVal == PM_SUCCESS)
        {
            /*Configure prcm_dpll_eve*/
            PRCM_getDpllStructure(PMHAL_PRCM_DPLL_EVE,
                                  sysClkFreq,
                                  opp,
                                  siliconPkgType,
                                  &dpllEveCfg);
            retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_EVE,
                                          dpllEveCfg,
                                          PM_TIMEOUT_INFINITE);
        }
#endif
        if (retVal == PM_SUCCESS)
        {
            /*Configure prcm_dpll_iva*/
            PRCM_getDpllStructure(PMHAL_PRCM_DPLL_IVA,
                                  sysClkFreq,
                                  opp,
                                  siliconPkgType,
                                  &dpllIvaCfg);
            retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_IVA,
                                          dpllIvaCfg,
                                          PM_TIMEOUT_INFINITE);
        }
        if (retVal == PM_SUCCESS)
        {
            /*Configure prcm_dpll_gpu*/
            if (opp == Power_PERFLEVEL_HIGH)
            {
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
                /* GPU doesnot support OPP HIGH; configuring for OPP NOM */
                opp = Power_PERFLEVEL_NOM;
#endif
            }
            PRCM_getDpllStructure(PMHAL_PRCM_DPLL_GPU,
                                  sysClkFreq,
                                  opp,
                                  siliconPkgType,
                                  &dpllGpuCfg);

            retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_GPU,
                                          dpllGpuCfg,
                                          PM_TIMEOUT_INFINITE);
        }
        if (retVal == PM_SUCCESS)
        {
            /*configure prcm_dpll_gmac*/
            PRCM_getDpllStructure(PMHAL_PRCM_DPLL_GMAC,
                                  sysClkFreq,
                                  Power_PERFLEVEL_NOM,
                                  siliconPkgType,
                                  &dpllGmacCfg);
            retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_GMAC,
                                          dpllGmacCfg,
                                          PM_TIMEOUT_INFINITE);
        }
        if (retVal == PM_SUCCESS)
        {
            /*configure prcm_dpll_abe*/
            /* ADAS use-cases do not use ABE DPLL and this configuration is done
             * to
             * simplify SW maintenance between ADAS and DRI variants
             * Select SYSCLK2 as source
             * Output = 451.584 MHz
             * Provides enough headroom so the McASP can evenly divide this down
             * to multiple different sampling rates as the module does not
             * contain a multiplier.
             */

            HW_WR_FIELD32(
                SOC_CKGEN_PRM_BASE + CM_CLKSEL_ABE_PLL_SYS,
                CM_CLKSEL_ABE_PLL_SYS_CLKSEL,
                CM_CLKSEL_ABE_PLL_SYS_CLKSEL_SEL_SYS_CLK2);

            PRCM_getDpllStructure(PMHAL_PRCM_DPLL_ABE,
                                  sysClkFreq,
                                  Power_PERFLEVEL_NOM,
                                  siliconPkgType,
                                  &dpllAbeCfg);
            retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_ABE,
                                          dpllAbeCfg,
                                          PM_TIMEOUT_INFINITE);
        }
        if (retVal == PM_SUCCESS)
        {
            /*Configure prcm_dpll_pcie_ref*/
            PRCM_getDpllStructure(PMHAL_PRCM_DPLL_PCIE_REF,
                                  sysClkFreq,
                                  Power_PERFLEVEL_NOM,
                                  siliconPkgType,
                                  &dpllPcieCfg);
            retVal = PMHALCMDpllConfigure(
                PMHAL_PRCM_DPLL_PCIE_REF,
                dpllPcieCfg,
                PM_TIMEOUT_INFINITE);
        }
        /* Select the mux and divider .*/
        PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_MMC1_FCLK_MUX, PMHAL_PRCM_DPLL_PER);
        PMHALCMDpllSetClockDivider(PMHAL_PRCM_DIV_MMC1_FCLK, (uint32_t) 2);
    }
    return retVal;
}

uint32_t PRCM_GetPackageType(void)
{
    uint32_t packageType =
        HW_RD_FIELD32(POWERPRCM_PACKAGE_READ_ADDR, POWERPRCM_PACKAGE_BIT);

    return packageType;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

uint32_t PRCM_GetSiliconRev()
{
    uint32_t siliconRev;

    siliconRev = HW_RD_REG32(
        SOC_CTRL_MODULE_WKUP_CORE_REGISTERS_BASE + CTRL_WKUP_ID_CODE);

    siliconRev = (siliconRev & 0xF0000000U) >> 28U;

    return (siliconRev);
}

inline void delayLoop(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < (1000U * delay); ++i)
    {}
}

