/*
 * Auto-generated CSL section
 */
/*
 *
 * Copyright (C) 2011 - 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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
/*
 * Auto-generated CSL section
 * PSC Configuration V0.6
 */
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/soc/k2g/src/cslr_soc_baseaddress.h>
#include <ti/csl/soc/k2g/src/cslr_interrupt.h>

#ifndef CSLR_SOC_DEVICE_H
#define CSLR_SOC_DEVICE_H

#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Auto-generated CSL section
 */
#define CSL_PSC_PD_ALWAYSON 0
#define CSL_PSC_PD_DEBUG 1
#define CSL_PSC_PD_NSS 2
#define CSL_PSC_PD_SA 3
#define CSL_PSC_PD_TERANET 4
#define CSL_PSC_PD_SYS_COMP 5
#define CSL_PSC_PD_SR 6
#define CSL_PSC_PD_MSMC 7
#define CSL_PSC_PD_C66X_COREPAC_0 8
#define CSL_PSC_PD_ARM 9
#define CSL_PSC_PD_ASRC 10
#define CSL_PSC_PD_ICSS 11
#define CSL_PSC_PD_DSS 12
#define CSL_PSC_PD_PCIE 13
#define CSL_PSC_PD_USB 14
#define CSL_PSC_PD_DDR3 15
#define CSL_PSC_PD_SPARE0 16
#define CSL_PSC_PD_SPARE1 17

/*
 * Auto-generated CSL section
 */
#define CSL_PSC_LPSC_ALWAYSON 0
#define CSL_PSC_LPSC_PMMC 1
#define CSL_PSC_LPSC_DEBUG 2
#define CSL_PSC_LPSC_NSS 3
#define CSL_PSC_LPSC_SA 4
#define CSL_PSC_LPSC_TERANET 5
#define CSL_PSC_LPSC_SYS_COMP 6
#define CSL_PSC_LPSC_QSPI 7
#define CSL_PSC_LPSC_MMC 8
#define CSL_PSC_LPSC_GPMC 9
#define CSL_PSC_LPSC_MLB  11
#define CSL_PSC_LPSC_EHRPWM 12
#define CSL_PSC_LPSC_EQEP 13
#define CSL_PSC_LPSC_ECAP 14
#define CSL_PSC_LPSC_MCASP 15
#define CSL_PSC_LPSC_SR 16
#define CSL_PSC_LPSC_MSMC 17
#define CSL_PSC_LPSC_C66X_COREPAC_0 18
#define CSL_PSC_LPSC_ARM 19
#define CSL_PSC_LPSC_ASRC 20
#define CSL_PSC_LPSC_ICSS 21
#define CSL_PSC_LPSC_DSS 23
#define CSL_PSC_LPSC_PCIE 24
#define CSL_PSC_LPSC_USB_0 25
#define CSL_PSC_LPSC_USB_1 26
#define CSL_PSC_LPSC_DDR3 27
#define CSL_PSC_LPSC_SPARE0_LPSC0 28
#define CSL_PSC_LPSC_SPARE0_LPSC1 29
#define CSL_PSC_LPSC_SPARE1_LPSC0 30
#define CSL_PSC_LPSC_SPARE1_LPSC1 31

#ifndef CSL_MODIFICATION
#define SOC_UART0_BASE                 (CSL_UART_0_REGS)
#define SOC_DSP_L1P_BASE               (CSL_C66X_COREPAC_LOCAL_L1P_SRAM_REGS)
#define SOC_DSP_L1D_BASE               (CSL_C66X_COREPAC_LOCAL_L1D_SRAM_REGS)
#define SOC_DSP_L2_BASE                (CSL_C66X_COREPAC_LOCAL_L2_SRAM_REGS)
#define SOC_DSP_ICFG_BASE              (CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS - 0x800000U)
#endif

#ifdef __cplusplus
}
#endif
#endif /* CSLR_SOC_H_ */
