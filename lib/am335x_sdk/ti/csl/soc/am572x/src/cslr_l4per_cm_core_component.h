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
#ifndef CSLR_L4PER_CM_CORE_COMPONENT_H
#define CSLR_L4PER_CM_CORE_COMPONENT_H

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
    volatile Uint32 CM_L4PER_CLKSTCTRL_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 CM_L4PER_DYNAMICDEP_REG;
    volatile Uint32 CM_L4PER2_L4_PER2_CLKCTRL_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 CM_L4PER3_L4_PER3_CLKCTRL_REG;
    volatile Uint32 CM_L4PER2_PRUSS1_CLKCTRL_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 CM_L4PER2_PRUSS2_CLKCTRL_REG;
    volatile Uint8  RSVD3[4];
    volatile Uint32 CM_L4PER_TIMER10_CLKCTRL_REG;
    volatile Uint8  RSVD4[4];
    volatile Uint32 CM_L4PER_TIMER11_CLKCTRL_REG;
    volatile Uint8  RSVD5[4];
    volatile Uint32 CM_L4PER_TIMER2_CLKCTRL_REG;
    volatile Uint8  RSVD6[4];
    volatile Uint32 CM_L4PER_TIMER3_CLKCTRL_REG;
    volatile Uint8  RSVD7[4];
    volatile Uint32 CM_L4PER_TIMER4_CLKCTRL_REG;
    volatile Uint8  RSVD8[4];
    volatile Uint32 CM_L4PER_TIMER9_CLKCTRL_REG;
    volatile Uint8  RSVD9[4];
    volatile Uint32 CM_L4PER_ELM_CLKCTRL_REG;
    volatile Uint8  RSVD10[4];
    volatile Uint32 CM_L4PER_GPIO2_CLKCTRL_REG;
    volatile Uint8  RSVD11[4];
    volatile Uint32 CM_L4PER_GPIO3_CLKCTRL_REG;
    volatile Uint8  RSVD12[4];
    volatile Uint32 CM_L4PER_GPIO4_CLKCTRL_REG;
    volatile Uint8  RSVD13[4];
    volatile Uint32 CM_L4PER_GPIO5_CLKCTRL_REG;
    volatile Uint8  RSVD14[4];
    volatile Uint32 CM_L4PER_GPIO6_CLKCTRL_REG;
    volatile Uint8  RSVD15[4];
    volatile Uint32 CM_L4PER_HDQ1W_CLKCTRL_REG;
    volatile Uint8  RSVD16[4];
    volatile Uint32 CM_L4PER2_PWMSS2_CLKCTRL_REG;
    volatile Uint8  RSVD17[4];
    volatile Uint32 CM_L4PER2_PWMSS3_CLKCTRL_REG;
    volatile Uint8  RSVD18[4];
    volatile Uint32 CM_L4PER_I2C1_CLKCTRL_REG;
    volatile Uint8  RSVD19[4];
    volatile Uint32 CM_L4PER_I2C2_CLKCTRL_REG;
    volatile Uint8  RSVD20[4];
    volatile Uint32 CM_L4PER_I2C3_CLKCTRL_REG;
    volatile Uint8  RSVD21[4];
    volatile Uint32 CM_L4PER_I2C4_CLKCTRL_REG;
    volatile Uint8  RSVD22[4];
    volatile Uint32 CM_L4PER_L4_PER1_CLKCTRL_REG;
    volatile Uint32 CM_L4PER2_PWMSS1_CLKCTRL_REG;
    volatile Uint32 CM_L4PER3_TIMER13_CLKCTRL_REG;
    volatile Uint8  RSVD23[4];
    volatile Uint32 CM_L4PER3_TIMER14_CLKCTRL_REG;
    volatile Uint8  RSVD24[4];
    volatile Uint32 CM_L4PER3_TIMER15_CLKCTRL_REG;
    volatile Uint8  RSVD25[20];
    volatile Uint32 CM_L4PER_MCSPI1_CLKCTRL_REG;
    volatile Uint8  RSVD26[4];
    volatile Uint32 CM_L4PER_MCSPI2_CLKCTRL_REG;
    volatile Uint8  RSVD27[4];
    volatile Uint32 CM_L4PER_MCSPI3_CLKCTRL_REG;
    volatile Uint8  RSVD28[4];
    volatile Uint32 CM_L4PER_MCSPI4_CLKCTRL_REG;
    volatile Uint8  RSVD29[4];
    volatile Uint32 CM_L4PER_GPIO7_CLKCTRL_REG;
    volatile Uint8  RSVD30[4];
    volatile Uint32 CM_L4PER_GPIO8_CLKCTRL_REG;
    volatile Uint8  RSVD31[4];
    volatile Uint32 CM_L4PER_MMC3_CLKCTRL_REG;
    volatile Uint8  RSVD32[4];
    volatile Uint32 CM_L4PER_MMC4_CLKCTRL_REG;
    volatile Uint8  RSVD33[4];
    volatile Uint32 CM_L4PER3_TIMER16_CLKCTRL_REG;
    volatile Uint8  RSVD34[4];
    volatile Uint32 CM_L4PER2_QSPI_CLKCTRL_REG;
    volatile Uint8  RSVD35[4];
    volatile Uint32 CM_L4PER_UART1_CLKCTRL_REG;
    volatile Uint8  RSVD36[4];
    volatile Uint32 CM_L4PER_UART2_CLKCTRL_REG;
    volatile Uint8  RSVD37[4];
    volatile Uint32 CM_L4PER_UART3_CLKCTRL_REG;
    volatile Uint8  RSVD38[4];
    volatile Uint32 CM_L4PER_UART4_CLKCTRL_REG;
    volatile Uint8  RSVD39[4];
    volatile Uint32 CM_L4PER2_MCASP2_CLKCTRL_REG;
    volatile Uint8  RSVD40[4];
    volatile Uint32 CM_L4PER2_MCASP3_CLKCTRL_REG;
    volatile Uint8  RSVD41[4];
    volatile Uint32 CM_L4PER_UART5_CLKCTRL_REG;
    volatile Uint8  RSVD42[4];
    volatile Uint32 CM_L4PER2_MCASP5_CLKCTRL_REG;
    volatile Uint8  RSVD43[4];
    volatile Uint32 CM_L4SEC_CLKSTCTRL_REG;
    volatile Uint32 CM_L4SEC_STATICDEP_REG;
    volatile Uint32 CM_L4SEC_DYNAMICDEP_REG;
    volatile Uint8  RSVD44[4];
    volatile Uint32 CM_L4PER2_MCASP8_CLKCTRL_REG;
    volatile Uint8  RSVD45[4];
    volatile Uint32 CM_L4PER2_MCASP4_CLKCTRL_REG;
    volatile Uint8  RSVD46[4];
    volatile Uint32 CM_L4SEC_AES1_CLKCTRL_REG;
    volatile Uint8  RSVD47[4];
    volatile Uint32 CM_L4SEC_AES2_CLKCTRL_REG;
    volatile Uint8  RSVD48[4];
    volatile Uint32 CM_L4SEC_DES3DES_CLKCTRL_REG;
    volatile Uint8  RSVD49[4];
    volatile Uint32 CM_L4SEC_FPKA_CLKCTRL_REG;
    volatile Uint8  RSVD50[4];
    volatile Uint32 CM_L4SEC_RNG_CLKCTRL_REG;
    volatile Uint8  RSVD51[4];
    volatile Uint32 CM_L4SEC_SHA2MD51_CLKCTRL_REG;
    volatile Uint8  RSVD52[4];
    volatile Uint32 CM_L4PER2_UART7_CLKCTRL_REG;
    volatile Uint8  RSVD53[4];
    volatile Uint32 CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG;
    volatile Uint8  RSVD54[4];
    volatile Uint32 CM_L4PER2_UART8_CLKCTRL_REG;
    volatile Uint8  RSVD55[4];
    volatile Uint32 CM_L4PER2_UART9_CLKCTRL_REG;
    volatile Uint8  RSVD56[4];
    volatile Uint32 CM_L4PER2_DCAN2_CLKCTRL_REG;
    volatile Uint8  RSVD57[4];
    volatile Uint32 CM_L4SEC_SHA2MD52_CLKCTRL_REG;
    volatile Uint32 CM_L4PER2_CLKSTCTRL_REG;
    volatile Uint32 CM_L4PER2_DYNAMICDEP_REG;
    volatile Uint32 CM_L4PER2_MCASP6_CLKCTRL_REG;
    volatile Uint32 CM_L4PER2_MCASP7_CLKCTRL_REG;
    volatile Uint32 CM_L4PER2_STATICDEP_REG;
    volatile Uint32 CM_L4PER3_CLKSTCTRL_REG;
    volatile Uint32 CM_L4PER3_DYNAMICDEP_REG;
} CSL_l4per_cm_core_componentRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG      (0x0U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG)


/* This register controls the dynamic domain depedencies from L4PER domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG     (0x8U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG)


/* This register manages the L4_PER2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG  (0xCU)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG)


/* This register manages the L4_PER3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG  (0x14U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG)


/* This register manages the PRUSS clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG  (0x18U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG)


/* This register manages the PRUSS clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG  (0x20U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG)


/* This register manages the TIMER10 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG  (0x28U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG)


/* This register manages the TIMER11 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG  (0x30U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG)


/* This register manages the TIMER2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG  (0x38U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG)


/* This register manages the TIMER3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG  (0x40U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG)


/* This register manages the TIMER4 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG  (0x48U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG)


/* This register manages the TIMER9 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG  (0x50U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG)


/* This register manages the ELM clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG    (0x58U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG)


/* This register manages the GPIO2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG  (0x60U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG)


/* This register manages the GPIO3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG  (0x68U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG)


/* This register manages the GPIO4 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG  (0x70U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG)


/* This register manages the GPIO5 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG  (0x78U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG)


/* This register manages the GPIO6 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG  (0x80U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG)


/* This register manages the HDQ1W clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG  (0x88U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG)


/* This register manages the PWMSS1 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG  (0x90U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG)


/* This register manages the PWMSS2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG  (0x98U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG)


/* This register manages the I2C1 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG   (0xA0U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG)


/* This register manages the I2C2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG   (0xA8U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG)


/* This register manages the I2C3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG   (0xB0U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG)


/* This register manages the I2C4 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG   (0xB8U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG)


/* This register manages the L4_PER1 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG  (0xC0U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG)


/* This register manages the PWMSS0 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG  (0xC4U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG)


/* This register manages the TIMER13 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG  (0xC8U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG)


/* This register manages the TIMER14 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG  (0xD0U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG)


/* This register manages the TIMER15 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG  (0xD8U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG)


/* This register manages the MCSPI1 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG  (0xF0U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG)


/* This register manages the MCSPI2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG  (0xF8U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG)


/* This register manages the MCSPI3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG  (0x100U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG)


/* This register manages the MCSPI4 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG  (0x108U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG)


/* This register manages the GPIO7 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG  (0x110U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG)


/* This register manages the GPIO8 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG  (0x118U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG)


/* This register manages the MMC3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG   (0x120U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG)


/* This register manages the MMC4 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG   (0x128U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG)


/* This register manages the TIMER16 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG  (0x130U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG)


/* This register manages the QSPI clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG  (0x138U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG)


/* This register manages the UART1 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG  (0x140U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG)


/* This register manages the UART2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG  (0x148U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG)


/* This register manages the UART3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG  (0x150U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG)


/* This register manages the UART4 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG  (0x158U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG)


/* This register manages the MCASP2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG  (0x160U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG)


/* This register manages the MCASP3 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG  (0x168U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG)


/* This register manages the UART5 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG  (0x170U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG)


/* This register manages the MCASP5 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG  (0x178U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG      (0x180U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG)


/* This register controls the static domain depedencies from L4SEC domain
 * towards 'target' domains. It is relevant only for domain having system
 * initiator(s). */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG      (0x184U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG)


/* This register controls the dynamic domain depedencies from L4SEC domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG     (0x188U)
/* Below define for backward compatibility */
#define CM_L4SEC_DYNAMICDEP  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG)


/* This register manages the MCASP8 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG  (0x190U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG)


/* This register manages the MCASP4 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG  (0x198U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG)


/* This register manages the AES1 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG   (0x1A0U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG)


/* This register manages the AES2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG   (0x1A8U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG)


/* This register manages the DES3DES clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG  (0x1B0U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG)


/* This register manages the FPKA clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG   (0x1B8U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG)


/* This register manages the RNG clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG    (0x1C0U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG)


/* This register manages the SHA2MD51 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG  (0x1C8U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG)


/* This register manages the UART7 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG  (0x1D0U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG)


/* This register manages the DMA_CRYPTO clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG  (0x1D8U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG)


/* This register manages the UART8 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG  (0x1E0U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG)


/* This register manages the UART9 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG  (0x1E8U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG)


/* This register manages the DCAN2 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG  (0x1F0U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG)


/* This register manages the SHA2MD52 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG  (0x1F8U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG     (0x1FCU)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG)


/* This register controls the dynamic domain depedencies from L4PER2 domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG    (0x200U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG)


/* This register manages the MCASP6 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG  (0x204U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG)


/* This register manages the MCASP7 clocks. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG  (0x208U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG)


/* This register controls the static domain depedencies from L4PER2 domain
 * towards 'target' domains. It is relevant only for domain having system
 * initiator(s). */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG     (0x20CU)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG     (0x210U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG)


/* This register controls the dynamic domain depedencies from L4PER3 domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG    (0x214U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_L4PER_CLKSTCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKTRCTRL_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKTRCTRL_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKTRCTRL_NO_SLEEP         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKTRCTRL_SW_SLEEP         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKTRCTRL_SW_WKUP          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKTRCTRL_HW_AUTO          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER10_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER10_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER10_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER10_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER10_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER11_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER11_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER11_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER11_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER11_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER2_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_SHIFT  (11U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER2_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER2_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER2_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER2_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER3_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER3_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER3_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER3_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER3_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER4_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_SHIFT  (13U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER4_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER4_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER4_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER4_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER9_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_SHIFT  (14U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER9_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER9_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_TIMER9_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_TIMER9_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_12M_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_SHIFT  (19U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_12M_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_12M_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_12M_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_12M_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_MASK  (0x00100000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_48M_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_SHIFT  (20U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_48M_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_48M_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_48M_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_48M_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_MASK  (0x00400000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC3_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC3_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC3_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC3_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC3_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART1_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_SHIFT  (15U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART1_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART1_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART1_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART1_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART2_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART2_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART2_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART2_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART2_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART3_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_SHIFT  (17U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART3_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART3_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART3_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART3_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART4_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART4_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART4_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART4_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART4_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_MASK  (0x00800000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC4_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_SHIFT  (23U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC4_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC4_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_MMC4_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_MMC4_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_MASK  (0x00200000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_96M_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_SHIFT  (21U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_96M_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_96M_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_96M_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_96M_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_GPIO_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_GPIO_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_GPIO_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_GPIO_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_GPIO_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_SHIFT  (25U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_MASK  (0x04000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART5_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_SHIFT  (26U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART5_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART5_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_UART5_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_UART5_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_L3_GICLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_L3_GICLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_L3_GICLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_L3_GICLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_L3_GICLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_MASK  (0x08000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_32K_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_SHIFT  (27U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_32K_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_32K_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_CLKSTCTRL_CLKACTIVITY_L4PER_32K_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_CLKACTIVITY_L4PER_32K_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_CLKSTCTRL_REG_RESETVAL  (0x00000000U)

/* CM_L4PER_DYNAMICDEP_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_L3INIT_DYNDEP_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L3INIT_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT  (7U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_L3INIT_DYNDEP_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_L3INIT_DYNDEP_ENABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_DSS_DYNDEP_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_DSS_DYNDEP_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_DSS_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_DSS_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_DSS_DYNDEP_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_DSS_DYNDEP_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_DSS_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_DSS_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_DSS_DYNDEP_ENABLED        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_DSS_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L4SEC_DYNDEP_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_L4SEC_DYNDEP_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L4SEC_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L4SEC_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L4SEC_DYNDEP_SHIFT  (14U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_L4SEC_DYNDEP_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L4SEC_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L4SEC_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_L4SEC_DYNDEP_ENABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_L4SEC_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_WINDOWSIZE_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_WINDOWSIZE_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_WINDOWSIZE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_WINDOWSIZE_RESETVAL  (0x00000004U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_WINDOWSIZE_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_WINDOWSIZE_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_WINDOWSIZE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_WINDOWSIZE_MAX  (0x0000000fU)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_IPU_DYNDEP_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_IPU_DYNDEP_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_IPU_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_IPU_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT  (3U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_IPU_DYNDEP_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_DYNAMICDEP_IPU_DYNDEP_ENABLED        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_DYNAMICDEP_REG_RESETVAL  (0x04004188U)

/* CM_L4PER2_L4_PER2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_MODULEMODE_AUTO     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_L4_PER2_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_L4_PER2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4PER3_L4_PER3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_MODULEMODE_AUTO     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_L4_PER3_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_L4_PER3_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4PER2_PRUSS1_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_STBYST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_STBYST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_STBYST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_STBYST_STANDBY       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS1_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS1_CLKCTRL_REG_RESETVAL  (0x00070000U)

/* CM_L4PER2_PRUSS2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_STBYST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_STBYST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_STBYST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_STBYST_STANDBY       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PRUSS2_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PRUSS2_CLKCTRL_REG_RESETVAL  (0x00070000U)

/* CM_L4PER_TIMER10_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_SYS_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_ABE_GICLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_ABE_GICLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_ABE_GICLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_RESERVED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_RESERVED1     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_RESERVED2     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_RESERVED3     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_CLKSEL_RESERVED4     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER10_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER10_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_TIMER11_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_SYS_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_ABE_GICLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_ABE_GICLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_ABE_GICLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_RESERVED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_RESERVED1     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_RESERVED2     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_RESERVED3     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER11_CLKCTRL_CLKSEL_RESERVED4     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER11_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_TIMER2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_SYS_CLK2   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_ABE_GICLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_ABE_GICLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_ABE_GICLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_SEL_HDMI_CLK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_RESERVED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_RESERVED1      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_RESERVED2      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_RESERVED3      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER2_CLKCTRL_CLKSEL_RESERVED4      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_TIMER3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_SYS_CLK2   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_SEL_HDMI_CLK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_RESERVED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_RESERVED1      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_RESERVED2      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_RESERVED3      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER3_CLKCTRL_CLKSEL_RESERVED4      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_TIMER4_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_SYS_CLK2   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_SEL_HDMI_CLK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_RESERVED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_RESERVED1      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_RESERVED2      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_RESERVED3      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER4_CLKCTRL_CLKSEL_RESERVED4      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER4_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_TIMER9_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_SYS_CLK2   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_SEL_HDMI_CLK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_RESERVED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_RESERVED1      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_RESERVED2      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_RESERVED3      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER_TIMER9_CLKCTRL_CLKSEL_RESERVED4      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_TIMER9_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_ELM_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_IDLEST_MASK              (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_IDLEST_SHIFT             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_IDLEST_DISABLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_IDLEST_IDLE              (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_IDLEST_FUNC              (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_IDLEST_TRANS             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_MODULEMODE_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_MODULEMODE_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_ELM_CLKCTRL_MODULEMODE_AUTO          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_ELM_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4PER_GPIO2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_OPTFCLKEN_DBCLK_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_MODULEMODE_AUTO        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO2_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_GPIO3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_OPTFCLKEN_DBCLK_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_MODULEMODE_AUTO        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO3_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_GPIO4_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_OPTFCLKEN_DBCLK_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_MODULEMODE_AUTO        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO4_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_GPIO5_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_OPTFCLKEN_DBCLK_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_MODULEMODE_AUTO        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO5_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO5_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_GPIO6_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_OPTFCLKEN_DBCLK_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_MODULEMODE_AUTO        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO6_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO6_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_HDQ1W_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_MODULEMODE_ENABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_HDQ1W_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_HDQ1W_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_PWMSS2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS2_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_PWMSS3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS3_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_I2C1_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_MODULEMODE_RESERVED_1   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_MODULEMODE_ENABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C1_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C1_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_I2C2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_MODULEMODE_RESERVED_1   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_MODULEMODE_ENABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C2_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_I2C3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_MODULEMODE_RESERVED_1   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_MODULEMODE_ENABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C3_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_I2C4_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_MODULEMODE_RESERVED_1   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_MODULEMODE_ENABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_I2C4_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_I2C4_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_L4_PER1_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_MODULEMODE_AUTO      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_L4_PER1_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_L4_PER1_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4PER2_PWMSS1_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_PWMSS1_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_PWMSS1_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER3_TIMER13_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_MODULEMODE_ENABLE   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_SYS_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_RESERVED1    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_RESERVED2    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_RESERVED3    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER13_CLKCTRL_CLKSEL_RESERVED4    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER13_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER3_TIMER14_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_MODULEMODE_ENABLE   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_SYS_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_RESERVED1    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_RESERVED2    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_RESERVED3    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER14_CLKCTRL_CLKSEL_RESERVED4    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER14_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER3_TIMER15_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_MODULEMODE_ENABLE   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_SYS_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_RESERVED1    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_RESERVED2    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_RESERVED3    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER15_CLKCTRL_CLKSEL_RESERVED4    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER15_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_MCSPI1_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI1_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_MCSPI2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI2_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_MCSPI3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI3_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_MCSPI4_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MCSPI4_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MCSPI4_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_GPIO7_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_OPTFCLKEN_DBCLK_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_MODULEMODE_AUTO        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO7_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO7_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_GPIO8_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_OPTFCLKEN_DBCLK_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_OPTFCLKEN_DBCLK_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_MODULEMODE_AUTO        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_GPIO8_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO8_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_MMC3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_MODULEMODE_RESERVED_1   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_MODULEMODE_ENABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_MUX_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_MUX_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_MUX_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_MUX_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MASK  (0x06000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_SHIFT  (25U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV_MMCCLK_DIV_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV_MMCCLK_DIV_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV_MMCCLK_DIV_4  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_4)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_CLKSEL_DIV_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_CLKSEL_DIV_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_OPTFCLKEN_CLK32K_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_OPTFCLKEN_CLK32K_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC3_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_MMC4_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_MODULEMODE_RESERVED_1   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_MODULEMODE_ENABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_MUX_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_MUX_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_MUX_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_MUX_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_MUX_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MASK  (0x06000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_SHIFT  (25U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV_MMCCLK_DIV_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV_MMCCLK_DIV_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV_MMCCLK_DIV_4  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_MMCCLK_DIV_4)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_CLKSEL_DIV_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_CLKSEL_DIV_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_OPTFCLKEN_CLK32K_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_OPTFCLKEN_CLK32K_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_EN  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_EN)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_MMC4_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_DIS  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_OPTFCLKEN_CLK32K_FCLK_DIS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_MMC4_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER3_TIMER16_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_MODULEMODE_ENABLE   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_TIMER_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK1_32K_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_SYS_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_SYS_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_SEL_HDMI_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED1  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_RESERVED1    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED2  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_RESERVED2    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED3  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_RESERVED3    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED4  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER3_TIMER16_CLKCTRL_CLKSEL_RESERVED4    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_CLKSEL_RESERVED4)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_TIMER16_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_QSPI_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_SOURCE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_SOURCE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_SEL_FUNC_128M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_SOURCE_SEL_FUNC_128M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_SEL_FUNC_128M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_SEL_PER_QSPI_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_SOURCE_SEL_PER_QSPI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_SOURCE_SEL_PER_QSPI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_ENABLED  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_MODULEMODE_ENABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_ENABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_MASK  (0x06000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_DIV_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_SHIFT  (25U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_DIV_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_DIV1  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_DIV_DIV1        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_DIV1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_DIV2  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_DIV_DIV2        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_DIV2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_DIV4  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_DIV_DIV4        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_DIV4)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_QSPI_CLKCTRL_CLKSEL_DIV_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_CLKSEL_DIV_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_QSPI_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_UART1_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_MODULEMODE_ENABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_CLKSEL_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_CLKSEL_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART1_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART1_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_UART2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_MODULEMODE_ENABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_CLKSEL_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_CLKSEL_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART2_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_UART3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_MODULEMODE_ENABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_CLKSEL_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_CLKSEL_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART3_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_UART4_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_MODULEMODE_ENABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_CLKSEL_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_CLKSEL_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART4_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART4_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_MCASP2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AUX_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AUX_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKX_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_MASK  (0xF0000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SHIFT  (28U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP2_CLKCTRL_CLKSEL_AHCLKR_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_CLKSEL_AHCLKR_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_MCASP3_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AUX_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AUX_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP3_CLKCTRL_CLKSEL_AHCLKX_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP3_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER_UART5_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_IDLEST_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_IDLEST_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_IDLEST_DISABLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_IDLEST_IDLE            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_IDLEST_FUNC            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_IDLEST_TRANS           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_MODULEMODE_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_MODULEMODE_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_MODULEMODE_DISABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_MODULEMODE_ENABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_MODULEMODE_RESERVED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_CLKSEL_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_CLKSEL_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER_UART5_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_UART5_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_MCASP5_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AUX_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AUX_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP5_CLKCTRL_CLKSEL_AHCLKX_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP5_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_CLKSTCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKACTIVITY_L4SEC_L3_GICLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKACTIVITY_L4SEC_L3_GICLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKACTIVITY_L4SEC_L3_GICLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKACTIVITY_L4SEC_L3_GICLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKACTIVITY_L4SEC_L3_GICLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKTRCTRL_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKTRCTRL_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKTRCTRL_NO_SLEEP         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKTRCTRL_SW_SLEEP         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKTRCTRL_SW_WKUP          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_CLKSTCTRL_CLKTRCTRL_HW_AUTO          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_CLKSTCTRL_REG_RESETVAL  (0x00000000U)

/* CM_L4SEC_STATICDEP_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_EMIF_STATDEP_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_SHIFT  (4U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_EMIF_STATDEP_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_EMIF_STATDEP_ENABLED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_ENABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_EMIF_STATDEP_DISABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_EMIF_STATDEP_DISABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L3MAIN1_STATDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_L3MAIN1_STATDEP_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L3MAIN1_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L3MAIN1_STATDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_L3MAIN1_STATDEP_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_L3MAIN1_STATDEP_ENABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_L4PER_STATDEP_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_SHIFT  (13U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_L4PER_STATDEP_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_L4PER_STATDEP_ENABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_ENABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_STATICDEP_L4PER_STATDEP_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_L4PER_STATDEP_DISABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_STATICDEP_REG_RESETVAL  (0x00000020U)

/* CM_L4SEC_DYNAMICDEP_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_L4SEC_DYNAMICDEP_L3MAIN1_DYNDEP_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_L3MAIN1_DYNDEP_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_L4SEC_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_L3MAIN1_DYNDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DYNAMICDEP_L3MAIN1_DYNDEP_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_L3MAIN1_DYNDEP_DISABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DYNAMICDEP_REG_RESETVAL  (0x00000000U)

/* CM_L4PER2_MCASP8_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AUX_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AUX_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP8_CLKCTRL_CLKSEL_AHCLKX_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP8_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_MCASP4_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AUX_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AUX_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP4_CLKCTRL_CLKSEL_AHCLKX_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP4_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_AES1_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_MODULEMODE_AUTO         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_MODULEMODE_RESERVED_2   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES1_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES1_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_AES2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_MODULEMODE_AUTO         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_MODULEMODE_RESERVED_2   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_AES2_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_AES2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_DES3DES_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_MODULEMODE_AUTO      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_DES3DES_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DES3DES_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_FPKA_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_IDLEST_MASK             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_IDLEST_SHIFT            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_IDLEST_DISABLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_IDLEST_IDLE             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_IDLEST_FUNC             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_IDLEST_TRANS            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_MODULEMODE_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_MODULEMODE_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_MODULEMODE_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_MODULEMODE_RESERVED_1   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_MODULEMODE_ENABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_FPKA_CLKCTRL_MODULEMODE_RESERVED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_FPKA_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_RNG_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_IDLEST_MASK              (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_IDLEST_SHIFT             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_IDLEST_DISABLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_IDLEST_IDLE              (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_IDLEST_FUNC              (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_IDLEST_TRANS             (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_MODULEMODE_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_MODULEMODE_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_MODULEMODE_DISABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_MODULEMODE_AUTO          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_MODULEMODE_RESERVED_2    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_RNG_CLKCTRL_MODULEMODE_RESERVED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_RNG_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_SHA2MD51_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_MODULEMODE_AUTO     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD51_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD51_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_UART7_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_CLKSEL_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_CLKSEL_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART7_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART7_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_IDLEST_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_IDLEST_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_IDLEST_DISABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_IDLEST_IDLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_IDLEST_FUNC       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_IDLEST_TRANS      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_STBYST_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_STBYST_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_STBYST_FUNC       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_STBYST_STANDBY    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_MODULEMODE_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_MODULEMODE_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_DMA_CRYPTO_CLKCTRL_MODULEMODE_AUTO   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_DMA_CRYPTO_CLKCTRL_REG_RESETVAL  (0x00070001U)

/* CM_L4PER2_UART8_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_CLKSEL_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_CLKSEL_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART8_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART8_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_UART9_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_CLKSEL_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_CLKSEL_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_SEL_FUNC_48M_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_UART9_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_CLKSEL_SEL_FUNC_192M_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_UART9_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_DCAN2_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_IDLEST_MASK           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_IDLEST_SHIFT          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_IDLEST_DISABLE        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_IDLEST_IDLE           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_IDLEST_FUNC           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_IDLEST_TRANS          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_DISABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_ENABLE     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_DCAN2_CLKCTRL_MODULEMODE_RESERVED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DCAN2_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4SEC_SHA2MD52_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_IDLEST_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_IDLEST_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_IDLEST_DISABLE      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_IDLEST_IDLE         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_IDLEST_FUNC         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_IDLEST_TRANS        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_MODULEMODE_MASK     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_MODULEMODE_SHIFT    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_MODULEMODE_AUTO     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4SEC_SHA2MD52_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4SEC_SHA2MD52_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_CLKSTCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKTRCTRL_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKTRCTRL_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKTRCTRL_NO_SLEEP        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKTRCTRL_SW_SLEEP        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKTRCTRL_SW_WKUP         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKTRCTRL_HW_AUTO         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKX_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_SHIFT  (17U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKX_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKX_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKX_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_SHIFT  (13U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_PER_192M_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_PER_192M_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_IEP_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_SHIFT  (14U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_IEP_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_IEP_CLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_IEP_CLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_IEP_CLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_DCAN2_SYS_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_SHIFT  (15U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_DCAN2_SYS_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_DCAN2_SYS_CLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_DCAN2_SYS_CLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_DCAN2_SYS_CLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART7_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART7_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART7_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART7_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART7_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART8_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART8_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART8_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART8_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART8_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART9_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_SHIFT  (11U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART9_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART9_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_UART9_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_UART9_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_L4PER2_L3_GICLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_L4PER2_L3_GICLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_L4PER2_L3_GICLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_L4PER2_L3_GICLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_L4PER2_L3_GICLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKR_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKR_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKR_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AHCLKR_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AHCLKR_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AUX_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_SHIFT  (19U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AUX_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AUX_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP2_AUX_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP2_AUX_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_MASK  (0x00100000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AHCLKX_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_SHIFT  (20U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AHCLKX_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AHCLKX_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AHCLKX_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_MASK  (0x00200000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AUX_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_SHIFT  (21U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AUX_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AUX_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP3_AUX_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP3_AUX_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_MASK  (0x00400000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AHCLKX_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AHCLKX_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AHCLKX_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AHCLKX_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AHCLKX_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_SHIFT  (25U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AHCLKX_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AHCLKX_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AHCLKX_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_MASK  (0x00800000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AUX_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_SHIFT  (23U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AUX_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AUX_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP4_AUX_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP4_AUX_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_MASK  (0x04000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AHCLKX_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_SHIFT  (26U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AHCLKX_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AHCLKX_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AHCLKX_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AHCLKX_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_SHIFT  (28U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AHCLKX_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AHCLKX_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AHCLKX_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AUX_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_SHIFT  (29U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AUX_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AUX_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP7_AUX_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP7_AUX_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AHCLKX_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_SHIFT  (30U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AHCLKX_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AHCLKX_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AHCLKX_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AUX_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_SHIFT  (31U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AUX_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AUX_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP8_AUX_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP8_AUX_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AUX_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AUX_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AUX_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP5_AUX_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP5_AUX_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_MASK  (0x08000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AUX_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_SHIFT  (27U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AUX_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AUX_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_MCASP6_AUX_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_MCASP6_AUX_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_CLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_ICSS_CLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_ICSS_CLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_QSPI_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_QSPI_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_QSPI_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_CLKSTCTRL_CLKACTIVITY_QSPI_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_CLKACTIVITY_QSPI_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_CLKSTCTRL_REG_RESETVAL  (0x00000000U)

/* CM_L4PER2_DYNAMICDEP_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_L3INIT_DYNDEP_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L3INIT_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT  (7U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_L3INIT_DYNDEP_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_L3INIT_DYNDEP_ENABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_WINDOWSIZE_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_WINDOWSIZE_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_WINDOWSIZE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_WINDOWSIZE_RESETVAL  (0x00000004U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_WINDOWSIZE_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_WINDOWSIZE_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_WINDOWSIZE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_WINDOWSIZE_MAX  (0x0000000fU)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_IPU_DYNDEP_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_IPU_DYNDEP_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_IPU_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_IPU_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT  (3U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_IPU_DYNDEP_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_IPU_DYNDEP_ENABLED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_GMAC_DYNDEP_MASK  (0x00400000U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_GMAC_DYNDEP_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_GMAC_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_GMAC_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_GMAC_DYNDEP_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_GMAC_DYNDEP_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_GMAC_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_GMAC_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_GMAC_DYNDEP_ENABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_GMAC_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_ATL_DYNDEP_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_ATL_DYNDEP_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_ATL_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_ATL_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_ATL_DYNDEP_SHIFT  (6U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_ATL_DYNDEP_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_ATL_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_ATL_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_ATL_DYNDEP_ENABLED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_ATL_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L4CFG_DYNDEP_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_L4CFG_DYNDEP_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L4CFG_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L4CFG_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L4CFG_DYNDEP_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_L4CFG_DYNDEP_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L4CFG_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L4CFG_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_DYNAMICDEP_L4CFG_DYNDEP_ENABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_L4CFG_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_DYNAMICDEP_REG_RESETVAL  (0x044010c8U)

/* CM_L4PER2_MCASP6_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AUX_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AUX_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP6_CLKCTRL_CLKSEL_AHCLKX_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP6_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_MCASP7_CLKCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AUX_CLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AUX_CLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_PER_ABE_X1_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO1_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_VIDEO2_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AUX_CLK_SEL_HDMI_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AUX_CLK_SEL_HDMI_CLK)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_IDLEST_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_IDLEST_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_IDLEST_DISABLE       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_IDLEST_IDLE          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_IDLEST_FUNC          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_IDLEST_TRANS         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_MODULEMODE_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_MODULEMODE_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_MODULEMODE_DISABLED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_MODULEMODE_ENABLE    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_MODULEMODE_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_MASK   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ABE_SYS_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_FUNC_24M_GFCLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1  (0x00000005U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0  (0x00000006U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_ATL_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_ATL_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2  (0x00000007U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_SYS_SLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_SYS_SLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK0)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1  (0x00000009U)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK1)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2  (0x0000000aU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK2  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK2)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3  (0x0000000bU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK3  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_XREF_CLK3)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK  (0x0000000cU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_MLB_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLB_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK  (0x0000000dU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_SEL_MLBP_CLK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_SEL_MLBP_CLK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED  (0x0000000eU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_RESERVED  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1  (0x0000000fU)
/* Below define for backward compatibility */
#define CM_L4PER2_MCASP7_CLKCTRL_CLKSEL_AHCLKX_RESERVED1  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_CLKSEL_AHCLKX_RESERVED1)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_MCASP7_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* CM_L4PER2_STATICDEP_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU2_STATDEP_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU2_STATDEP_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU2_STATDEP_ENABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_ENABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU2_STATDEP_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU2_STATDEP_DISABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP1_STATDEP_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_SHIFT  (1U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP1_STATDEP_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP1_STATDEP_ENABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_ENABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP1_STATDEP_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP1_STATDEP_DISABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP2_STATDEP_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP2_STATDEP_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP2_STATDEP_ENABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_ENABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_DSP2_STATDEP_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_DSP2_STATDEP_DISABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_MASK  (0x00800000U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU1_STATDEP_MASK         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_SHIFT  (23U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU1_STATDEP_SHIFT        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU1_STATDEP_ENABLED      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_ENABLED)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_IPU1_STATDEP_DISABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_IPU1_STATDEP_DISABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_L3MAIN1_STATDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_L3MAIN1_STATDEP_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_L3MAIN1_STATDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_L3MAIN1_STATDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_L3MAIN1_STATDEP_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER2_STATICDEP_L3MAIN1_STATDEP_ENABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER2_STATICDEP_REG_RESETVAL  (0x00000020U)

/* CM_L4PER3_CLKSTCTRL_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKTRCTRL_MASK            (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKTRCTRL_SHIFT           (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKTRCTRL_NO_SLEEP        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKTRCTRL_SW_SLEEP        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKTRCTRL_SW_WKUP         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKTRCTRL_HW_AUTO         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_L4PER3_L3_GICLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_L4PER3_L3_GICLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_L4PER3_L3_GICLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_L4PER3_L3_GICLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_L4PER3_L3_GICLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER13_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER13_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER13_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER13_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER13_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER14_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER14_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER14_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER14_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER14_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER15_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_SHIFT  (11U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER15_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER15_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER15_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER15_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER16_GFCLK_MASK  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_RESETVAL  (0x00000000U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER16_GFCLK_SHIFT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER16_GFCLK_INACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_INACT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_CLKSTCTRL_CLKACTIVITY_TIMER16_GFCLK_ACT  (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_CLKACTIVITY_TIMER16_GFCLK_ACT)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_CLKSTCTRL_REG_RESETVAL  (0x00000000U)

/* CM_L4PER3_DYNAMICDEP_REG */

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_WINDOWSIZE_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_WINDOWSIZE_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_WINDOWSIZE_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_WINDOWSIZE_RESETVAL  (0x00000004U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_WINDOWSIZE_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_WINDOWSIZE_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_WINDOWSIZE_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_WINDOWSIZE_MAX  (0x0000000fU)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L3MAIN1_DYNDEP_MASK      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3MAIN1_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L3MAIN1_DYNDEP_ENABLED   (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_CAM_DYNDEP_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_CAM_DYNDEP_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_CAM_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_CAM_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_CAM_DYNDEP_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_CAM_DYNDEP_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_CAM_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_CAM_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_CAM_DYNDEP_ENABLED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_CAM_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_IPU_DYNDEP_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_IPU_DYNDEP_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_IPU_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_IPU_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT  (3U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_IPU_DYNDEP_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_IPU_DYNDEP_ENABLED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L3INIT_DYNDEP_MASK       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3INIT_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT  (7U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L3INIT_DYNDEP_SHIFT      (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L3INIT_DYNDEP_ENABLED    (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RTC_DYNDEP_MASK  (0x00800000U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_RTC_DYNDEP_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RTC_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RTC_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RTC_DYNDEP_SHIFT  (23U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_RTC_DYNDEP_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RTC_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RTC_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_RTC_DYNDEP_ENABLED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RTC_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_VPE_DYNDEP_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_VPE_DYNDEP_MASK          (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_VPE_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_VPE_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_VPE_DYNDEP_SHIFT  (31U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_VPE_DYNDEP_SHIFT         (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_VPE_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_VPE_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_VPE_DYNDEP_ENABLED       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_VPE_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L4CFG_DYNDEP_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L4CFG_DYNDEP_MASK        (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L4CFG_DYNDEP_MASK)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L4CFG_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L4CFG_DYNDEP_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L4CFG_DYNDEP_SHIFT       (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L4CFG_DYNDEP_SHIFT)

#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L4CFG_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4PER3_DYNAMICDEP_L4CFG_DYNDEP_ENABLED     (CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_L4CFG_DYNDEP_ENABLED)


#define CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER3_DYNAMICDEP_REG_RESETVAL  (0x848012a8U)

#ifdef __cplusplus
}
#endif
#endif
