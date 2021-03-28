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
#ifndef CSLR_L4PER_PRM_H
#define CSLR_L4PER_PRM_H

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
    volatile Uint32 PM_L4PER_PWRSTCTRL_REG;
    volatile Uint32 PM_L4PER_PWRSTST_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 RM_L4PER2_L4PER2_CONTEXT_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 RM_L4PER3_L4PER3_CONTEXT_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 RM_L4PER2_PRUSS1_CONTEXT_REG;
    volatile Uint8  RSVD3[4];
    volatile Uint32 RM_L4PER2_PRUSS2_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER10_WKDEP_REG;
    volatile Uint32 RM_L4PER_TIMER10_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER11_WKDEP_REG;
    volatile Uint32 RM_L4PER_TIMER11_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER2_WKDEP_REG;
    volatile Uint32 RM_L4PER_TIMER2_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER3_WKDEP_REG;
    volatile Uint32 RM_L4PER_TIMER3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER4_WKDEP_REG;
    volatile Uint32 RM_L4PER_TIMER4_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER9_WKDEP_REG;
    volatile Uint32 RM_L4PER_TIMER9_CONTEXT_REG;
    volatile Uint8  RSVD4[4];
    volatile Uint32 RM_L4PER_ELM_CONTEXT_REG;
    volatile Uint32 PM_L4PER_GPIO2_WKDEP_REG;
    volatile Uint32 RM_L4PER_GPIO2_CONTEXT_REG;
    volatile Uint32 PM_L4PER_GPIO3_WKDEP_REG;
    volatile Uint32 RM_L4PER_GPIO3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_GPIO4_WKDEP_REG;
    volatile Uint32 RM_L4PER_GPIO4_CONTEXT_REG;
    volatile Uint32 PM_L4PER_GPIO5_WKDEP_REG;
    volatile Uint32 RM_L4PER_GPIO5_CONTEXT_REG;
    volatile Uint32 PM_L4PER_GPIO6_WKDEP_REG;
    volatile Uint32 RM_L4PER_GPIO6_CONTEXT_REG;
    volatile Uint8  RSVD5[4];
    volatile Uint32 RM_L4PER_HDQ1W_CONTEXT_REG;
    volatile Uint8  RSVD6[4];
    volatile Uint32 RM_L4PER2_PWMSS2_CONTEXT_REG;
    volatile Uint8  RSVD7[4];
    volatile Uint32 RM_L4PER2_PWMSS3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_I2C1_WKDEP_REG;
    volatile Uint32 RM_L4PER_I2C1_CONTEXT_REG;
    volatile Uint32 PM_L4PER_I2C2_WKDEP_REG;
    volatile Uint32 RM_L4PER_I2C2_CONTEXT_REG;
    volatile Uint32 PM_L4PER_I2C3_WKDEP_REG;
    volatile Uint32 RM_L4PER_I2C3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_I2C4_WKDEP_REG;
    volatile Uint32 RM_L4PER_I2C4_CONTEXT_REG;
    volatile Uint32 RM_L4PER_L4PER1_CONTEXT_REG;
    volatile Uint32 RM_L4PER2_PWMSS1_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER13_WKDEP_REG;
    volatile Uint32 RM_L4PER3_TIMER13_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER14_WKDEP_REG;
    volatile Uint32 RM_L4PER3_TIMER14_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER15_WKDEP_REG;
    volatile Uint32 RM_L4PER3_TIMER15_CONTEXT_REG;
    volatile Uint8  RSVD8[16];
    volatile Uint32 PM_L4PER_MCSPI1_WKDEP_REG;
    volatile Uint32 RM_L4PER_MCSPI1_CONTEXT_REG;
    volatile Uint32 PM_L4PER_MCSPI2_WKDEP_REG;
    volatile Uint32 RM_L4PER_MCSPI2_CONTEXT_REG;
    volatile Uint32 PM_L4PER_MCSPI3_WKDEP_REG;
    volatile Uint32 RM_L4PER_MCSPI3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_MCSPI4_WKDEP_REG;
    volatile Uint32 RM_L4PER_MCSPI4_CONTEXT_REG;
    volatile Uint32 PM_L4PER_GPIO7_WKDEP_REG;
    volatile Uint32 RM_L4PER_GPIO7_CONTEXT_REG;
    volatile Uint32 PM_L4PER_GPIO8_WKDEP_REG;
    volatile Uint32 RM_L4PER_GPIO8_CONTEXT_REG;
    volatile Uint32 PM_L4PER_MMC3_WKDEP_REG;
    volatile Uint32 RM_L4PER_MMC3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_MMC4_WKDEP_REG;
    volatile Uint32 RM_L4PER_MMC4_CONTEXT_REG;
    volatile Uint32 PM_L4PER_TIMER16_WKDEP_REG;
    volatile Uint32 RM_L4PER3_TIMER16_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_QSPI_WKDEP_REG;
    volatile Uint32 RM_L4PER2_QSPI_CONTEXT_REG;
    volatile Uint32 PM_L4PER_UART1_WKDEP_REG;
    volatile Uint32 RM_L4PER_UART1_CONTEXT_REG;
    volatile Uint32 PM_L4PER_UART2_WKDEP_REG;
    volatile Uint32 RM_L4PER_UART2_CONTEXT_REG;
    volatile Uint32 PM_L4PER_UART3_WKDEP_REG;
    volatile Uint32 RM_L4PER_UART3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_UART4_WKDEP_REG;
    volatile Uint32 RM_L4PER_UART4_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_MCASP2_WKDEP_REG;
    volatile Uint32 RM_L4PER2_MCASP2_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_MCASP3_WKDEP_REG;
    volatile Uint32 RM_L4PER2_MCASP3_CONTEXT_REG;
    volatile Uint32 PM_L4PER_UART5_WKDEP_REG;
    volatile Uint32 RM_L4PER_UART5_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_MCASP5_WKDEP_REG;
    volatile Uint32 RM_L4PER2_MCASP5_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_MCASP6_WKDEP_REG;
    volatile Uint32 RM_L4PER2_MCASP6_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_MCASP7_WKDEP_REG;
    volatile Uint32 RM_L4PER2_MCASP7_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_MCASP8_WKDEP_REG;
    volatile Uint32 RM_L4PER2_MCASP8_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_MCASP4_WKDEP_REG;
    volatile Uint32 RM_L4PER2_MCASP4_CONTEXT_REG;
    volatile Uint8  RSVD9[4];
    volatile Uint32 RM_L4SEC_AES1_CONTEXT_REG;
    volatile Uint8  RSVD10[4];
    volatile Uint32 RM_L4SEC_AES2_CONTEXT_REG;
    volatile Uint8  RSVD11[4];
    volatile Uint32 RM_L4SEC_DES3DES_CONTEXT_REG;
    volatile Uint8  RSVD12[4];
    volatile Uint32 RM_L4SEC_FPKA_CONTEXT_REG;
    volatile Uint8  RSVD13[4];
    volatile Uint32 RM_L4SEC_RNG_CONTEXT_REG;
    volatile Uint8  RSVD14[4];
    volatile Uint32 RM_L4SEC_SHA2MD51_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_UART7_WKDEP_REG;
    volatile Uint32 RM_L4PER2_UART7_CONTEXT_REG;
    volatile Uint8  RSVD15[4];
    volatile Uint32 RM_L4SEC_DMA_CRYPTO_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_UART8_WKDEP_REG;
    volatile Uint32 RM_L4PER2_UART8_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_UART9_WKDEP_REG;
    volatile Uint32 RM_L4PER2_UART9_CONTEXT_REG;
    volatile Uint32 PM_L4PER2_DCAN2_WKDEP_REG;
    volatile Uint32 RM_L4PER2_DCAN2_CONTEXT_REG;
    volatile Uint8  RSVD16[4];
    volatile Uint32 RM_L4SEC_SHA2MD52_CONTEXT_REG;
} CSL_l4per_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register controls the L4PER power state to reach upon a domain sleep
 * transition */
#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG                    (0x0U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL      (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG)


/* This register provides a status on the current L4PER power domain state.
 * [warm reset insensitive] */
#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG                      (0x4U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST        (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG)


/* This register contains dedicated L4_PER2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG              (0xCU)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG)


/* This register contains dedicated L4_PER3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG              (0x14U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG)


/* This register contains dedicated PRUSS0 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG              (0x1CU)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG)


/* This register contains dedicated PRUSS1 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG              (0x24U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER10 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG                (0x28U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG)


/* This register contains dedicated TIMER10 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG              (0x2CU)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER10_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER11 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG                (0x30U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG)


/* This register contains dedicated TIMER11 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG              (0x34U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER11_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER2 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG                 (0x38U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP   (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG)


/* This register contains dedicated TIMER2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG               (0x3CU)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER3 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG                 (0x40U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP   (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG)


/* This register contains dedicated TIMER3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG               (0x44U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER3_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER4 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG                 (0x48U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP   (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG)


/* This register contains dedicated TIMER4 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG               (0x4CU)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER4_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER9 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG                 (0x50U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP   (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG)


/* This register contains dedicated TIMER9 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG               (0x54U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER9_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG)


/* This register contains dedicated ELM context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG                  (0x5CU)
/* Below define for backward compatibility */
#define RM_L4PER_ELM_CONTEXT    (CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG)


/* This register controls wakeup dependency based on GPIO2 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG                  (0x60U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP    (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG)


/* This register contains dedicated GPIO2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG                (0x64U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG)


/* This register controls wakeup dependency based on GPIO3 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG                  (0x68U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP    (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG)


/* This register contains dedicated GPIO3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG                (0x6CU)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO3_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG)


/* This register controls wakeup dependency based on GPIO4 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG                  (0x70U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP    (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG)


/* This register contains dedicated GPIO4 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG                (0x74U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO4_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG)


/* This register controls wakeup dependency based on GPIO5 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG                  (0x78U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP    (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG)


/* This register contains dedicated GPIO5 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG                (0x7CU)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO5_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG)


/* This register controls wakeup dependency based on GPIO6 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG                  (0x80U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP    (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG)


/* This register contains dedicated GPIO6 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG                (0x84U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO6_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG)


/* This register contains dedicated HDQ1W context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG                (0x8CU)
/* Below define for backward compatibility */
#define RM_L4PER_HDQ1W_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG)


/* This register contains dedicated PWMSS2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG              (0x94U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG)


/* This register contains dedicated PWMSS3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG              (0x9CU)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS3_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG)


/* This register controls wakeup dependency based on I2C1 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG                   (0xA0U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP     (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG)


/* This register contains dedicated I2C1 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG                 (0xA4U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C1_CONTEXT   (CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG)


/* This register controls wakeup dependency based on I2C2 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG                   (0xA8U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP     (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG)


/* This register contains dedicated I2C2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG                 (0xACU)
/* Below define for backward compatibility */
#define RM_L4PER_I2C2_CONTEXT   (CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG)


/* This register controls wakeup dependency based on I2C3 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG                   (0xB0U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP     (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG)


/* This register contains dedicated I2C3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG                 (0xB4U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C3_CONTEXT   (CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG)


/* This register controls wakeup dependency based on I2C4 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG                   (0xB8U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP     (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG)


/* This register contains dedicated I2C4 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG                 (0xBCU)
/* Below define for backward compatibility */
#define RM_L4PER_I2C4_CONTEXT   (CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG)


/* This register contains dedicated L4_PER1 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG               (0xC0U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG)


/* This register contains dedicated PWMSS1 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG              (0xC4U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS1_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER13 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG                (0xC8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG)


/* This register contains dedicated TIMER13 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG             (0xCCU)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER13_CONTEXT  (CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER14 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG                (0xD0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG)


/* This register contains dedicated TIMER14 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG             (0xD4U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER14_CONTEXT  (CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER15 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG                (0xD8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG)


/* This register contains dedicated TIMER15 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG             (0xDCU)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER15_CONTEXT  (CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG)


/* This register controls wakeup dependency based on MCSPI1 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG                 (0xF0U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP   (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG)


/* This register contains dedicated MCSPI1 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG               (0xF4U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI1_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG)


/* This register controls wakeup dependency based on MCSPI2 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG                 (0xF8U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP   (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG)


/* This register contains dedicated MCSPI2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG               (0xFCU)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG)


/* This register controls wakeup dependency based on MCSPI3 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG                 (0x100U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP   (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG)


/* This register contains dedicated MCSPI3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG               (0x104U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI3_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG)


/* This register controls wakeup dependency based on MCSPI4 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG                 (0x108U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP   (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG)


/* This register contains dedicated MCSPI4 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG               (0x10CU)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI4_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG)


/* This register controls wakeup dependency based on GPIO7 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG                  (0x110U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP    (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG)


/* This register contains dedicated GPIO7 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG                (0x114U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO7_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG)


/* This register controls wakeup dependency based on GPIO8 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG                  (0x118U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP    (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG)


/* This register contains dedicated GPIO8 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG                (0x11CU)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO8_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG)


/* This register controls wakeup dependency based on MMC3 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG                   (0x120U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP     (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG)


/* This register contains dedicated MMC3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG                 (0x124U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT   (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG)


/* This register controls wakeup dependency based on MMC4 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG                   (0x128U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP     (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG)


/* This register contains dedicated MMC4 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG                 (0x12CU)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT   (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG)


/* This register controls wakeup dependency based on TIMER16 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG                (0x130U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG)


/* This register contains dedicated TIMER16 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG             (0x134U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER16_CONTEXT  (CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG)


/* This register controls wakeup dependency based on QSPI service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG                  (0x138U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP    (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG)


/* This register contains dedicated QSPI context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG                (0x13CU)
/* Below define for backward compatibility */
#define RM_L4PER2_QSPI_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG)


/* This register controls wakeup dependency based on UART1 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG                  (0x140U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP    (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG)


/* This register contains dedicated UART1 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG                (0x144U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG)


/* This register controls wakeup dependency based on UART2 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG                  (0x148U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP    (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG)


/* This register contains dedicated UART2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG                (0x14CU)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG)


/* This register controls wakeup dependency based on UART3 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG                  (0x150U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP    (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG)


/* This register contains dedicated UART3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG                (0x154U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG)


/* This register controls wakeup dependency based on UART4 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG                  (0x158U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP    (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG)


/* This register contains dedicated UART4 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG                (0x15CU)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG)


/* This register controls wakeup dependency based on MCASP2 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG                (0x160U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG)


/* This register contains dedicated MCASP2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG              (0x164U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG)


/* This register controls wakeup dependency based on MCASP3 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG                (0x168U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG)


/* This register contains dedicated MCASP3 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG              (0x16CU)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP3_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG)


/* This register controls wakeup dependency based on UART5 service requests. */
#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG                  (0x170U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP    (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG)


/* This register contains dedicated UART5 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG                (0x174U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT  (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG)


/* This register controls wakeup dependency based on MCASP5 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG                (0x178U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG)


/* This register contains dedicated MCASP5 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG              (0x17CU)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP5_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG)


/* This register controls wakeup dependency based on MCASP6 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG                (0x180U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG)


/* This register contains dedicated MCASP6 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG              (0x184U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP6_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG)


/* This register controls wakeup dependency based on MCASP7 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG                (0x188U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG)


/* This register contains dedicated MCASP7 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG              (0x18CU)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP7_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG)


/* This register controls wakeup dependency based on MCASP8 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG                (0x190U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG)


/* This register contains dedicated MCASP8 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG              (0x194U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP8_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG)


/* This register controls wakeup dependency based on MCASP4 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG                (0x198U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG)


/* This register contains dedicated MCASP4 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG              (0x19CU)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP4_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG)


/* This register contains dedicated AES1 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG                 (0x1A4U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES1_CONTEXT   (CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG)


/* This register contains dedicated AES2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG                 (0x1ACU)
/* Below define for backward compatibility */
#define RM_L4SEC_AES2_CONTEXT   (CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG)


/* This register contains dedicated DES3DES context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG              (0x1B4U)
/* Below define for backward compatibility */
#define RM_L4SEC_DES3DES_CONTEXT  (CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG)


/* This register contains dedicated FPKA context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG                 (0x1BCU)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT   (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG)


/* This register contains dedicated RNG context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG                  (0x1C4U)
/* Below define for backward compatibility */
#define RM_L4SEC_RNG_CONTEXT    (CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG)


/* This register contains dedicated SHA2MD51 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG             (0x1CCU)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD51_CONTEXT  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG)


/* This register controls wakeup dependency based on UART7 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG                 (0x1D0U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP   (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG)


/* This register contains dedicated UART7 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG               (0x1D4U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG)


/* This register contains dedicated DMA_CRYPTO context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG           (0x1DCU)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG)


/* This register controls wakeup dependency based on UART8 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG                 (0x1E0U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP   (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG)


/* This register contains dedicated UART8 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG               (0x1E4U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG)


/* This register controls wakeup dependency based on UART9 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG                 (0x1E8U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP   (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG)


/* This register contains dedicated UART9 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG               (0x1ECU)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG)


/* This register controls wakeup dependency based on DCAN2 service requests. */
#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG                 (0x1F0U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP   (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG)


/* This register contains dedicated DCAN2 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG               (0x1F4U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG)


/* This register contains dedicated SHA2MD52 context statuses. [warm reset
 * insensitive] */
#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG             (0x1FCU)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD52_CONTEXT  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PM_L4PER_PWRSTCTRL_REG */

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_RETSTATE_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_NONRETAINED_BANK_RETSTATE_MASK  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_RETSTATE_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_RETSTATE_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_RETSTATE_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_NONRETAINED_BANK_RETSTATE_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_RETSTATE_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_RETSTATE_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_NONRETAINED_BANK_RETSTATE_MEM_OFF  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_RETSTATE_MEM_OFF)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_ONSTATE_MASK  (0x000C0000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_NONRETAINED_BANK_ONSTATE_MASK  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_ONSTATE_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_ONSTATE_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_NONRETAINED_BANK_ONSTATE_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_ONSTATE_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_NONRETAINED_BANK_ONSTATE_MEM_ON  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_NONRETAINED_BANK_ONSTATE_MEM_ON)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_RETSTATE_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_RETAINED_BANK_RETSTATE_MASK  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_RETSTATE_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_RETSTATE_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_RETSTATE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_RETAINED_BANK_RETSTATE_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_RETSTATE_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_RETSTATE_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_RETAINED_BANK_RETSTATE_MEM_RET  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_RETSTATE_MEM_RET)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_ONSTATE_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_RETAINED_BANK_ONSTATE_MASK  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_ONSTATE_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_ONSTATE_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_RETAINED_BANK_ONSTATE_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_ONSTATE_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_RETAINED_BANK_ONSTATE_MEM_ON  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RETAINED_BANK_ONSTATE_MEM_ON)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOGICRETSTATE_MASK         (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOGICRETSTATE_SHIFT        (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOGICRETSTATE_LOGIC_RET    (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_RET)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOGICRETSTATE_LOGIC_OFF    (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_OFF)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOWPOWERSTATECHANGE_MASK   (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOWPOWERSTATECHANGE_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOWPOWERSTATECHANGE_EN     (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_LOWPOWERSTATECHANGE_DIS    (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_MASK    (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_POWERSTATE_MASK            (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_RESETVAL  (0x00000003U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_SHIFT   (0U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_POWERSTATE_SHIFT           (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_RESERVED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_POWERSTATE_RESERVED        (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_RESERVED)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_INACT   (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_POWERSTATE_INACT           (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_INACT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_RET     (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_POWERSTATE_RET             (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_RET)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_ON      (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTCTRL_POWERSTATE_ON              (CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_POWERSTATE_ON)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTCTRL_REG_RESETVAL           (0x000f0107U)

/* PM_L4PER_PWRSTST_REG */

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_MASK    (0x00100000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_INTRANSITION_MASK            (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_SHIFT   (20U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_INTRANSITION_SHIFT           (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_NO      (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_INTRANSITION_NO              (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_NO)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_ONGOING  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_INTRANSITION_ONGOING         (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_INTRANSITION_ONGOING)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_MASK    (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LOGICSTATEST_MASK            (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_SHIFT   (2U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LOGICSTATEST_SHIFT           (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_ON      (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LOGICSTATEST_ON              (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_ON)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_OFF     (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LOGICSTATEST_OFF             (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LOGICSTATEST_OFF)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MASK  (0x00000030U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_RETAINED_BANK_STATEST_MASK   (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_RETAINED_BANK_STATEST_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_RETAINED_BANK_STATEST_MEM_ON  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MEM_ON)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_RETAINED_BANK_STATEST_MEM_RET  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MEM_RET)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_RETAINED_BANK_STATEST_MEM_OFF  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_MEM_OFF)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_RETAINED_BANK_STATEST_RESERVED  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RETAINED_BANK_STATEST_RESERVED)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_MASK  (0x000000C0U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_NONRETAINED_BANK_STATEST_MASK  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_NONRETAINED_BANK_STATEST_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_NONRETAINED_BANK_STATEST_MEM_ON  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_MEM_ON)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_NONRETAINED_BANK_STATEST_RESERVED1  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_RESERVED1)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_NONRETAINED_BANK_STATEST_MEM_OFF  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_MEM_OFF)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_NONRETAINED_BANK_STATEST_RESERVED  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_NONRETAINED_BANK_STATEST_RESERVED)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_MASK    (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_POWERSTATEST_MASK            (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_SHIFT   (0U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_POWERSTATEST_SHIFT           (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_ON      (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_POWERSTATEST_ON              (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_ON)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_RESERVED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_POWERSTATEST_RESERVED        (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_RESERVED)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_RET     (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_POWERSTATEST_RET             (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_RET)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_POWERSTATEST_INACTIVE        (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_POWERSTATEST_INACTIVE)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LASTPOWERSTATEENTERED_MASK   (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT  (24U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LASTPOWERSTATEENTERED_SHIFT  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LASTPOWERSTATEENTERED_ON     (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_ON)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LASTPOWERSTATEENTERED_OFF    (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LASTPOWERSTATEENTERED_RET    (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_RET)

#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE  (CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE)


#define CSL_L4PER_PRM_PM_L4PER_PWRSTST_REG_RESETVAL             (0x000000f7U)

/* RM_L4PER2_L4PER2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_L4PER2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_L4PER2_CONTEXT_REG_RESETVAL     (0x00000003U)

/* RM_L4PER3_L4PER3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER3_L4PER3_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER3_L4PER3_CONTEXT_REG_RESETVAL     (0x00000003U)

/* RM_L4PER2_PRUSS1_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTMEM_PRUSS1_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTMEM_PRUSS1_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTMEM_PRUSS1_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS1_CONTEXT_LOSTMEM_PRUSS1_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_LOSTMEM_PRUSS1_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_PRUSS1_CONTEXT_REG_RESETVAL     (0x00000101U)

/* RM_L4PER2_PRUSS2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTMEM_PRUSS2_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTMEM_PRUSS2_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTMEM_PRUSS2_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_PRUSS2_CONTEXT_LOSTMEM_PRUSS2_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_LOSTMEM_PRUSS2_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_PRUSS2_CONTEXT_REG_RESETVAL     (0x00000101U)

/* PM_L4PER_TIMER10_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER10_WKDEP_WKUPDEP_TIMER10_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_WKUPDEP_TIMER10_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER10_WKDEP_REG_RESETVAL       (0x00000000U)

/* RM_L4PER_TIMER10_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_TIMER10_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER_TIMER11_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER11_WKDEP_WKUPDEP_TIMER11_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_WKUPDEP_TIMER11_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER11_WKDEP_REG_RESETVAL       (0x00000000U)

/* RM_L4PER_TIMER11_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_TIMER11_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER_TIMER2_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER2_WKDEP_WKUPDEP_TIMER2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_WKUPDEP_TIMER2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER2_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_TIMER2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_TIMER2_CONTEXT_REG_RESETVAL      (0x00000001U)

/* PM_L4PER_TIMER3_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER3_WKDEP_WKUPDEP_TIMER3_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_WKUPDEP_TIMER3_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER3_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_TIMER3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_TIMER3_CONTEXT_REG_RESETVAL      (0x00000001U)

/* PM_L4PER_TIMER4_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER4_WKDEP_WKUPDEP_TIMER4_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_WKUPDEP_TIMER4_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER4_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_TIMER4_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_TIMER4_CONTEXT_REG_RESETVAL      (0x00000001U)

/* PM_L4PER_TIMER9_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER9_WKDEP_WKUPDEP_TIMER9_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_WKUPDEP_TIMER9_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER9_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_TIMER9_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_TIMER9_CONTEXT_REG_RESETVAL      (0x00000001U)

/* RM_L4PER_ELM_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_ELM_CONTEXT_LOSTCONTEXT_DFF_MASK     (CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_ELM_CONTEXT_LOSTCONTEXT_DFF_SHIFT    (CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_ELM_CONTEXT_LOSTCONTEXT_DFF_LOST     (CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_ELM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_ELM_CONTEXT_REG_RESETVAL         (0x00000001U)

/* PM_L4PER_GPIO2_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_SHIFT  (14U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_SHIFT  (17U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_SHIFT  (19U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO2_WKDEP_WKUPDEP_GPIO2_IRQ2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_WKUPDEP_GPIO2_IRQ2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO2_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_GPIO2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO2_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO2_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO2_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_GPIO2_CONTEXT_REG_RESETVAL       (0x00000002U)

/* PM_L4PER_GPIO3_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_SHIFT  (14U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_SHIFT  (17U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_SHIFT  (19U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO3_WKDEP_WKUPDEP_GPIO3_IRQ2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_WKUPDEP_GPIO3_IRQ2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO3_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_GPIO3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO3_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO3_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO3_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO3_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_GPIO3_CONTEXT_REG_RESETVAL       (0x00000002U)

/* PM_L4PER_GPIO4_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_SHIFT  (14U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_SHIFT  (17U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_SHIFT  (19U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO4_WKDEP_WKUPDEP_GPIO4_IRQ2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_WKUPDEP_GPIO4_IRQ2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO4_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_GPIO4_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO4_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO4_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO4_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO4_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_GPIO4_CONTEXT_REG_RESETVAL       (0x00000002U)

/* PM_L4PER_GPIO5_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_SHIFT  (14U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_SHIFT  (17U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_SHIFT  (19U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO5_WKDEP_WKUPDEP_GPIO5_IRQ2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_WKUPDEP_GPIO5_IRQ2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO5_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_GPIO5_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO5_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO5_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO5_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO5_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_GPIO5_CONTEXT_REG_RESETVAL       (0x00000002U)

/* PM_L4PER_GPIO6_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_SHIFT  (14U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_SHIFT  (17U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_SHIFT  (19U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO6_WKDEP_WKUPDEP_GPIO6_IRQ2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_WKUPDEP_GPIO6_IRQ2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO6_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_GPIO6_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO6_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO6_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO6_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO6_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_GPIO6_CONTEXT_REG_RESETVAL       (0x00000002U)

/* RM_L4PER_HDQ1W_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_MASK   (CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_LOST   (CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_HDQ1W_CONTEXT_REG_RESETVAL       (0x00000001U)

/* RM_L4PER2_PWMSS2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_PWMSS2_CONTEXT_REG_RESETVAL     (0x00000001U)

/* RM_L4PER2_PWMSS3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS3_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS3_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_PWMSS3_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER_I2C1_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C1_WKDEP_WKUPDEP_I2C1_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_WKUPDEP_I2C1_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C1_WKDEP_REG_RESETVAL          (0x0000b000U)

/* RM_L4PER_I2C1_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C1_CONTEXT_LOSTCONTEXT_RFF_MASK    (CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C1_CONTEXT_LOSTCONTEXT_RFF_SHIFT   (CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C1_CONTEXT_LOSTCONTEXT_RFF_LOST    (CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_I2C1_CONTEXT_REG_RESETVAL        (0x00000002U)

/* PM_L4PER_I2C2_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C2_WKDEP_WKUPDEP_I2C2_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_WKUPDEP_I2C2_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C2_WKDEP_REG_RESETVAL          (0x0000b000U)

/* RM_L4PER_I2C2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_I2C2_CONTEXT_REG_RESETVAL        (0x00000001U)

/* PM_L4PER_I2C3_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C3_WKDEP_WKUPDEP_I2C3_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_WKUPDEP_I2C3_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C3_WKDEP_REG_RESETVAL          (0x0000b000U)

/* RM_L4PER_I2C3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C3_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C3_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C3_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_I2C3_CONTEXT_REG_RESETVAL        (0x00000001U)

/* PM_L4PER_I2C4_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_I2C4_WKDEP_WKUPDEP_I2C4_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_WKUPDEP_I2C4_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_I2C4_WKDEP_REG_RESETVAL          (0x0000b000U)

/* RM_L4PER_I2C4_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C4_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C4_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C4_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_I2C4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_I2C4_CONTEXT_REG_RESETVAL        (0x00000001U)

/* RM_L4PER_L4PER1_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_L4PER1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_L4PER1_CONTEXT_REG_RESETVAL      (0x00000003U)

/* RM_L4PER2_PWMSS1_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_PWMSS1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_PWMSS1_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER_TIMER13_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER13_WKDEP_WKUPDEP_TIMER13_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_WKUPDEP_TIMER13_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER13_WKDEP_REG_RESETVAL       (0x00000000U)

/* RM_L4PER3_TIMER13_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER13_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER13_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER13_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER13_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER3_TIMER13_CONTEXT_REG_RESETVAL    (0x00000001U)

/* PM_L4PER_TIMER14_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER14_WKDEP_WKUPDEP_TIMER14_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_WKUPDEP_TIMER14_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER14_WKDEP_REG_RESETVAL       (0x00000000U)

/* RM_L4PER3_TIMER14_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER14_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER14_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER14_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER14_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER3_TIMER14_CONTEXT_REG_RESETVAL    (0x00000001U)

/* PM_L4PER_TIMER15_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER15_WKDEP_WKUPDEP_TIMER15_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_WKUPDEP_TIMER15_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER15_WKDEP_REG_RESETVAL       (0x00000000U)

/* RM_L4PER3_TIMER15_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER15_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER15_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER15_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER15_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER3_TIMER15_CONTEXT_REG_RESETVAL    (0x00000001U)

/* PM_L4PER_MCSPI1_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI1_WKDEP_WKUPDEP_MCSPI1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_WKUPDEP_MCSPI1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI1_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_MCSPI1_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MCSPI1_CONTEXT_REG_RESETVAL      (0x00000001U)

/* PM_L4PER_MCSPI2_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI2_WKDEP_WKUPDEP_MCSPI2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_WKUPDEP_MCSPI2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI2_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_MCSPI2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MCSPI2_CONTEXT_REG_RESETVAL      (0x00000001U)

/* PM_L4PER_MCSPI3_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI3_WKDEP_WKUPDEP_MCSPI3_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_WKUPDEP_MCSPI3_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI3_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_MCSPI3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI3_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI3_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MCSPI3_CONTEXT_REG_RESETVAL      (0x00000001U)

/* PM_L4PER_MCSPI4_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MCSPI4_WKDEP_WKUPDEP_MCSPI4_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_WKUPDEP_MCSPI4_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MCSPI4_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER_MCSPI4_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI4_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI4_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI4_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MCSPI4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MCSPI4_CONTEXT_REG_RESETVAL      (0x00000001U)

/* PM_L4PER_GPIO7_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_SHIFT  (14U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_SHIFT  (17U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_SHIFT  (19U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO7_WKDEP_WKUPDEP_GPIO7_IRQ2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_WKUPDEP_GPIO7_IRQ2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO7_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_GPIO7_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO7_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO7_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO7_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO7_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_GPIO7_CONTEXT_REG_RESETVAL       (0x00000002U)

/* PM_L4PER_GPIO8_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_SHIFT  (14U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_SHIFT  (17U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_SHIFT  (19U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_GPIO8_WKDEP_WKUPDEP_GPIO8_IRQ2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_WKUPDEP_GPIO8_IRQ2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_GPIO8_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_GPIO8_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO8_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO8_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO8_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_GPIO8_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_GPIO8_CONTEXT_REG_RESETVAL       (0x00000002U)

/* PM_L4PER_MMC3_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_MPU_MASK     (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_MPU_SHIFT    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU2_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU2_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP1_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP1_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_SDMA_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_SDMA_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU1_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU1_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP2_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP2_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE1_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE1_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE2_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE2_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE3_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE3_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE4_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE4_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC3_WKDEP_WKUPDEP_MMC3_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_WKUPDEP_MMC3_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC3_WKDEP_REG_RESETVAL          (0x00000000U)

/* RM_L4PER_MMC3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTMEM_NONRETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTMEM_NONRETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTMEM_NONRETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC3_CONTEXT_LOSTMEM_NONRETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MMC3_CONTEXT_REG_RESETVAL        (0x00000101U)

/* PM_L4PER_MMC4_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_MPU_MASK     (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_MPU_SHIFT    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU2_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU2_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP1_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP1_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_SDMA_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_SDMA_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU1_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU1_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP2_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP2_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE1_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE1_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE2_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE2_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE3_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE3_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE4_MASK    (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE4_SHIFT   (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_MMC4_WKDEP_WKUPDEP_MMC4_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_WKUPDEP_MMC4_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_MMC4_WKDEP_REG_RESETVAL          (0x00000000U)

/* RM_L4PER_MMC4_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTMEM_NONRETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTMEM_NONRETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTMEM_NONRETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_MMC4_CONTEXT_LOSTMEM_NONRETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_MMC4_CONTEXT_REG_RESETVAL        (0x00000101U)

/* PM_L4PER_TIMER16_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_TIMER16_WKDEP_WKUPDEP_TIMER16_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_WKUPDEP_TIMER16_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_TIMER16_WKDEP_REG_RESETVAL       (0x00000000U)

/* RM_L4PER3_TIMER16_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER16_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER16_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER16_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER3_TIMER16_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER3_TIMER16_CONTEXT_REG_RESETVAL    (0x00000001U)

/* PM_L4PER2_QSPI_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_MPU_MASK    (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_MPU_SHIFT   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU2_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP1_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU1_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP2_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE1_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE2_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE3_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE4_MASK   (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_QSPI_WKDEP_WKUPDEP_QSPI_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_WKUPDEP_QSPI_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_QSPI_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER2_QSPI_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_QSPI_CONTEXT_LOSTCONTEXT_DFF_MASK   (CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_QSPI_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_QSPI_CONTEXT_LOSTCONTEXT_DFF_LOST   (CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_QSPI_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_QSPI_CONTEXT_REG_RESETVAL       (0x00000001U)

/* PM_L4PER_UART1_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_MPU_MASK   (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART1_WKDEP_WKUPDEP_UART1_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_WKUPDEP_UART1_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART1_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_UART1_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART1_CONTEXT_REG_RESETVAL       (0x00000102U)

/* PM_L4PER_UART2_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_MPU_MASK   (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART2_WKDEP_WKUPDEP_UART2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_WKUPDEP_UART2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART2_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_UART2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART2_CONTEXT_REG_RESETVAL       (0x00000102U)

/* PM_L4PER_UART3_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_MPU_MASK   (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART3_WKDEP_WKUPDEP_UART3_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_WKUPDEP_UART3_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART3_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_UART3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART3_CONTEXT_REG_RESETVAL       (0x00000102U)

/* PM_L4PER_UART4_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_MPU_MASK   (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART4_WKDEP_WKUPDEP_UART4_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_WKUPDEP_UART4_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART4_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_UART4_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART4_CONTEXT_REG_RESETVAL       (0x00000102U)

/* PM_L4PER2_MCASP2_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP2_WKDEP_WKUPDEP_MCASP2_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_WKUPDEP_MCASP2_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP2_WKDEP_REG_RESETVAL       (0x0000b000U)

/* RM_L4PER2_MCASP2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_MCASP2_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER2_MCASP3_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP3_WKDEP_WKUPDEP_MCASP3_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_WKUPDEP_MCASP3_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP3_WKDEP_REG_RESETVAL       (0x0000b000U)

/* RM_L4PER2_MCASP3_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP3_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP3_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_MCASP3_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER_UART5_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_MPU_MASK   (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER_UART5_WKDEP_WKUPDEP_UART5_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_WKUPDEP_UART5_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER_UART5_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L4PER_UART5_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTCONTEXT_RFF_MASK   (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTCONTEXT_RFF_LOST   (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER_UART5_CONTEXT_REG_RESETVAL       (0x00000102U)

/* PM_L4PER2_MCASP5_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP5_WKDEP_WKUPDEP_MCASP5_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_WKUPDEP_MCASP5_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP5_WKDEP_REG_RESETVAL       (0x0000b000U)

/* RM_L4PER2_MCASP5_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP5_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP5_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP5_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP5_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_MCASP5_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER2_MCASP6_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP6_WKDEP_WKUPDEP_MCASP6_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_WKUPDEP_MCASP6_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP6_WKDEP_REG_RESETVAL       (0x0000b000U)

/* RM_L4PER2_MCASP6_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP6_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP6_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP6_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP6_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_MCASP6_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER2_MCASP7_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP7_WKDEP_WKUPDEP_MCASP7_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_WKUPDEP_MCASP7_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP7_WKDEP_REG_RESETVAL       (0x0000b000U)

/* RM_L4PER2_MCASP7_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP7_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP7_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP7_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP7_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_MCASP7_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER2_MCASP8_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP8_WKDEP_WKUPDEP_MCASP8_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_WKUPDEP_MCASP8_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP8_WKDEP_REG_RESETVAL       (0x0000b000U)

/* RM_L4PER2_MCASP8_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP8_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP8_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP8_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP8_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_MCASP8_CONTEXT_REG_RESETVAL     (0x00000001U)

/* PM_L4PER2_MCASP4_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_IRQ_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_IRQ_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_SHIFT  (13U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_SHIFT  (15U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_MCASP4_WKDEP_WKUPDEP_MCASP4_DMA_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_WKUPDEP_MCASP4_DMA_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_MCASP4_WKDEP_REG_RESETVAL       (0x0000b000U)

/* RM_L4PER2_MCASP4_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP4_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP4_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP4_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_MCASP4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_MCASP4_CONTEXT_REG_RESETVAL     (0x00000001U)

/* RM_L4SEC_AES1_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES1_CONTEXT_LOSTCONTEXT_RFF_MASK    (CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES1_CONTEXT_LOSTCONTEXT_RFF_SHIFT   (CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES1_CONTEXT_LOSTCONTEXT_RFF_LOST    (CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_AES1_CONTEXT_REG_RESETVAL        (0x00000002U)

/* RM_L4SEC_AES2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES2_CONTEXT_LOSTCONTEXT_RFF_MASK    (CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES2_CONTEXT_LOSTCONTEXT_RFF_SHIFT   (CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES2_CONTEXT_LOSTCONTEXT_RFF_LOST    (CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_AES2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_AES2_CONTEXT_REG_RESETVAL        (0x00000002U)

/* RM_L4SEC_DES3DES_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4SEC_DES3DES_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4SEC_DES3DES_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_DES3DES_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_DES3DES_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_DES3DES_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4SEC_FPKA_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTMEM_NONRETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTMEM_NONRETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTMEM_NONRETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_FPKA_CONTEXT_LOSTMEM_NONRETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_LOSTMEM_NONRETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_FPKA_CONTEXT_REG_RESETVAL        (0x00000101U)

/* RM_L4SEC_RNG_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4SEC_RNG_CONTEXT_LOSTCONTEXT_RFF_MASK     (CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4SEC_RNG_CONTEXT_LOSTCONTEXT_RFF_SHIFT    (CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_RNG_CONTEXT_LOSTCONTEXT_RFF_LOST     (CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_RNG_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_RNG_CONTEXT_REG_RESETVAL         (0x00000002U)

/* RM_L4SEC_SHA2MD51_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD51_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD51_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD51_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD51_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD51_CONTEXT_REG_RESETVAL    (0x00000002U)

/* PM_L4PER2_UART7_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART7_WKDEP_WKUPDEP_UART7_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_WKUPDEP_UART7_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART7_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER2_UART7_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART7_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_UART7_CONTEXT_REG_RESETVAL      (0x00000102U)

/* RM_L4SEC_DMA_CRYPTO_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_DMA_CRYPTO_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_DMA_CRYPTO_CONTEXT_REG_RESETVAL  (0x00000102U)

/* PM_L4PER2_UART8_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART8_WKDEP_WKUPDEP_UART8_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_WKUPDEP_UART8_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART8_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER2_UART8_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART8_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_UART8_CONTEXT_REG_RESETVAL      (0x00000102U)

/* PM_L4PER2_UART9_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_UART9_WKDEP_WKUPDEP_UART9_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_WKUPDEP_UART9_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_UART9_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER2_UART9_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTMEM_RETAINED_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTMEM_RETAINED_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_UART9_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_LOSTMEM_RETAINED_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_UART9_CONTEXT_REG_RESETVAL      (0x00000102U)

/* PM_L4PER2_DCAN2_WKDEP_REG */

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_MPU_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_MPU_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_MPU_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_MPU_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_MPU_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP1_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU2_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_SDMA_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_SHIFT  (3U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_SDMA_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_SDMA_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_SDMA_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_SDMA_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU1_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_IPU1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_IPU1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP2_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_DSP2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_DSP2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE1_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE1_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE1_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE1_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE1_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE2_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE2_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE2_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE2_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE2_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE3_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE3_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE3_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE3_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE3_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE4_MASK  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_MASK)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_RESETVAL  (0x00000000U)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE4_SHIFT  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_SHIFT)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE4_ENABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_ENABLED)

#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L4PER2_DCAN2_WKDEP_WKUPDEP_DCAN2_EVE4_DISABLED  (CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_WKUPDEP_DCAN2_EVE4_DISABLED)


#define CSL_L4PER_PRM_PM_L4PER2_DCAN2_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L4PER2_DCAN2_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTMEM_DCAN_BANK_MASK  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTMEM_DCAN_BANK_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTMEM_DCAN_BANK_LOST  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTMEM_DCAN_BANK_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTMEM_DCAN_BANK_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4PER2_DCAN2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4PER2_DCAN2_CONTEXT_REG_RESETVAL      (0x00000101U)

/* RM_L4SEC_SHA2MD52_CONTEXT_REG */

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD52_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD52_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD52_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4SEC_SHA2MD52_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_L4PER_PRM_RM_L4SEC_SHA2MD52_CONTEXT_REG_RESETVAL    (0x00000002U)

#ifdef __cplusplus
}
#endif
#endif
