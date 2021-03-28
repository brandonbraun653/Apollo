/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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
 *  \file      pmhal_pmmc_modinc.h
 *
 *  \brief     Contains the list of modules to be included for compilation
 */

#ifndef PMHAL_PMMC_MODINC_H_
#define PMHAL_PMMC_MODINC_H_

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/**
 * \brief Comment off the (#defined) modules which you do not want to include
 */
#define BUILDCFG_PMHAL_PMMC_MOD_PMMC
#define BUILDCFG_PMHAL_PMMC_MOD_MLB0
#define BUILDCFG_PMHAL_PMMC_MOD_DSS0
#define BUILDCFG_PMHAL_PMMC_MOD_MCBSP0
#define BUILDCFG_PMHAL_PMMC_MOD_MCASP0
#define BUILDCFG_PMHAL_PMMC_MOD_MCASP1
#define BUILDCFG_PMHAL_PMMC_MOD_MCASP2
#define BUILDCFG_PMHAL_PMMC_MOD_DCAN0
#define BUILDCFG_PMHAL_PMMC_MOD_DCAN1
#define BUILDCFG_PMHAL_PMMC_MOD_EMIF0
#define BUILDCFG_PMHAL_PMMC_MOD_MMCHS0
#define BUILDCFG_PMHAL_PMMC_MOD_MMCHS1
#define BUILDCFG_PMHAL_PMMC_MOD_GPMC0
#define BUILDCFG_PMHAL_PMMC_MOD_ELM0
#define BUILDCFG_PMHAL_PMMC_MOD_SPI0
#define BUILDCFG_PMHAL_PMMC_MOD_SPI1
#define BUILDCFG_PMHAL_PMMC_MOD_SPI2
#define BUILDCFG_PMHAL_PMMC_MOD_SPI3
#define BUILDCFG_PMHAL_PMMC_MOD_ICSS0
#define BUILDCFG_PMHAL_PMMC_MOD_ICSS1
#define BUILDCFG_PMHAL_PMMC_MOD_USB0
#define BUILDCFG_PMHAL_PMMC_MOD_USB1
#define BUILDCFG_PMHAL_PMMC_MOD_NSS0
#define BUILDCFG_PMHAL_PMMC_MOD_PCIE0
#define BUILDCFG_PMHAL_PMMC_MOD_OTP0
#define BUILDCFG_PMHAL_PMMC_MOD_GPIO0
#define BUILDCFG_PMHAL_PMMC_MOD_GPIO1
#define BUILDCFG_PMHAL_PMMC_MOD_TIMER64_0
#define BUILDCFG_PMHAL_PMMC_MOD_TIMER64_1
#define BUILDCFG_PMHAL_PMMC_MOD_TIMER64_2
#define BUILDCFG_PMHAL_PMMC_MOD_TIMER64_3
#define BUILDCFG_PMHAL_PMMC_MOD_TIMER64_4
#define BUILDCFG_PMHAL_PMMC_MOD_TIMER64_5
#define BUILDCFG_PMHAL_PMMC_MOD_TIMER64_6
#define BUILDCFG_PMHAL_PMMC_MOD_SEC_MGR0
#define BUILDCFG_PMHAL_PMMC_MOD_MSGMGR0
#define BUILDCFG_PMHAL_PMMC_MOD_BOOTCFG0
#define BUILDCFG_PMHAL_PMMC_MOD_ARM_BOOTROM0
#define BUILDCFG_PMHAL_PMMC_MOD_DSP_BOOTROM0
#define BUILDCFG_PMHAL_PMMC_MOD_DEBUGSS0
#define BUILDCFG_PMHAL_PMMC_MOD_UART0
#define BUILDCFG_PMHAL_PMMC_MOD_UART1
#define BUILDCFG_PMHAL_PMMC_MOD_UART2
#define BUILDCFG_PMHAL_PMMC_MOD_EHRPWM0
#define BUILDCFG_PMHAL_PMMC_MOD_EHRPWM1
#define BUILDCFG_PMHAL_PMMC_MOD_EHRPWM2
#define BUILDCFG_PMHAL_PMMC_MOD_EHRPWM3
#define BUILDCFG_PMHAL_PMMC_MOD_EHRPWM4
#define BUILDCFG_PMHAL_PMMC_MOD_EHRPWM5
#define BUILDCFG_PMHAL_PMMC_MOD_EQEP0
#define BUILDCFG_PMHAL_PMMC_MOD_EQEP1
#define BUILDCFG_PMHAL_PMMC_MOD_EQEP2
#define BUILDCFG_PMHAL_PMMC_MOD_ECAP0
#define BUILDCFG_PMHAL_PMMC_MOD_ECAP1
#define BUILDCFG_PMHAL_PMMC_MOD_I2C0
#define BUILDCFG_PMHAL_PMMC_MOD_I2C1
#define BUILDCFG_PMHAL_PMMC_MOD_I2C2
#define BUILDCFG_PMHAL_PMMC_MOD_CP_TRACER0
#define BUILDCFG_PMHAL_PMMC_MOD_CP_TRACER1
#define BUILDCFG_PMHAL_PMMC_MOD_EDMA0
#define BUILDCFG_PMHAL_PMMC_MOD_EDMA1
#define BUILDCFG_PMHAL_PMMC_MOD_SEMAPHORE0
#define BUILDCFG_PMHAL_PMMC_MOD_INTC0
#define BUILDCFG_PMHAL_PMMC_MOD_GIC0
#define BUILDCFG_PMHAL_PMMC_MOD_QSPI0
#define BUILDCFG_PMHAL_PMMC_MOD_ARM_64B_COUNTER0
#define BUILDCFG_PMHAL_PMMC_MOD_TETRIS0
#define BUILDCFG_PMHAL_PMMC_MOD_CGEM0
#define BUILDCFG_PMHAL_PMMC_MOD_MSMC0
#define BUILDCFG_PMHAL_PMMC_MOD_DFS_SS0
#define BUILDCFG_PMHAL_PMMC_MOD_CBASS0
#define BUILDCFG_PMHAL_PMMC_MOD_SMARTREFLEX0
#define BUILDCFG_PMHAL_PMMC_MOD_EFUSE0
#define BUILDCFG_PMHAL_PMMC_MOD_BOARD0
#define BUILDCFG_PMHAL_PMMC_MOD_CIC0
#define BUILDCFG_PMHAL_PMMC_MOD_PSC0

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/* None */

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

#endif /* PMHAL_PMMC_MODINC_H_ */

