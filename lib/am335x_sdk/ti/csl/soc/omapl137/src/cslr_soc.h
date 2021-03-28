/*
 * Auto-generated CSL section
 */
/*
 *
 * Copyright (C) 2011 - 2012 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/csl/soc/omapl137/src/cslr_soc_baseaddress.h>
#include <ti/csl/soc/omapl137/src/cslr_interrupt.h>

#ifndef CSLR_SOC_H
#define CSLR_SOC_H

#ifdef __cplusplus
extern "C"
{
#endif
/*************************** LPSC Numbers of peripherals **********************/
/* Some of the SoC parts support Power management and hence need to use PWRM
 * specific Macro. To have the common code base between the SOC parts,        *
 * even though this are defined in cslr_psc<soc>.h                            *
 * as in some SOC part PWRM specific macros hasto be                          */

/* Peripherals in PSC0                                                        */


typedef enum {
    CSL_PSC_CC               = 0,
    CSL_PSC_TC0              = 1,
    CSL_PSC_TC1              = 2,
    CSL_PSC_EMIFA            = 3,
    CSL_PSC_SPI0             = 4,
    CSL_PSC_MMCSD0           = 5,
    CSL_PSC_AINTC            = 6,
    CSL_PSC_ARM_RAMROM       = 7,
    CSL_PSC_SECCNTL_KEYMGR   = 8,
    CSL_PSC_UART0            = 9,
    CSL_PSC_SCR0_SS          = 10,
    CSL_PSC_SCR1_SS          = 11,
    CSL_PSC_SCR2_SS          = 12,
    CSL_PSC_RESV0            = 13,
    CSL_PSC_ARM              = 14,
    CSL_PSC_DSP              = 15

} CSL_Psc0Peripheral;

typedef enum {
    CSL_PSC_USB0         = 17,
    CSL_PSC_USB1         = 18,
    CSL_PSC_GPIO         = 19,
    CSL_PSC_UHPI         = 20,
    CSL_PSC_EMAC         = 21,
    CSL_PSC_EMIFB        = 22,
    CSL_PSC_MCASP0       = 23,
    CSL_PSC_MCASP1       = 24,
    CSL_PSC_MCASP2       = 25,
    CSL_PSC_SPI1         = 26,
    CSL_PSC_I2C1         = 27,
    CSL_PSC_UART1        = 28,
    CSL_PSC_UART2        = 29,
    CSL_PSC_LCDC         = 32,
    CSL_PSC_EHRPWM0_1_2  = 33,
    CSL_PSC_ECAP0_1_2    = 36,
    CSL_PSC_EQEP0_1_2    = 37,
    CSL_PSC_SCR8_SS      = 40,
    CSL_PSC_SCR7_SS      = 41,
    CSL_PSC_SCR12_SS     = 42,
    CSL_PSC_SHRAM        = 47
} CSL_Psc1Peripheral;


#define    CSL_LPSC_NUMBER_EDMA3_0_CC_0         CSL_PSC_CC
#define    CSL_LPSC_NUMBER_EDMA3_0_TC_0         CSL_PSC_TC0
#define    CSL_LPSC_NUMBER_EDMA3_0_TC_1         CSL_PSC_TC1
#define    CSL_LPSC_NUMBER_EMIFA_0              CSL_PSC_EMIFA
#define    CSL_LPSC_NUMBER_SPI_0                CSL_PSC_SPI0
#define    CSL_LPSC_NUMBER_MMCSD_0              CSL_PSC_MMCSD0
#define    CSL_LPSC_NUMBER_AINTC_0              CSL_PSC_AINTC
#define    CSL_LPSC_NUMBER_ARM_RAMROM_0         CSL_PSC_ARM_RAMROM
#define    CSL_LPSC_NUMBER_SECCNTL_KEYMGR_0     CSL_PSC_SECCNTL_KEYMGR
#define    CSL_LPSC_NUMBER_UART_0               CSL_PSC_UART0
#define    CSL_LPSC_NUMBER_SCR_0                CSL_PSC_SCR0_SS
#define    CSL_LPSC_NUMBER_SCR_1                CSL_PSC_SCR1_SS
#define    CSL_LPSC_NUMBER_SCR_2                CSL_PSC_SCR2_SS
#define    CSL_LPSC_NUMBER_ARM                  CSL_PSC_ARM
#define    CSL_LPSC_NUMBER_DSP                  CSL_PSC_DSP


/* Peripherals in PSC1                                                        */

#define    CSL_LPSC_NUMBER_USB_0                CSL_PSC_USB0
#define    CSL_LPSC_NUMBER_USB_1                CSL_PSC_USB1
#define    CSL_LPSC_NUMBER_GPIO_0               CSL_PSC_GPIO
#define    CSL_LPSC_NUMBER_UHPI_0               CSL_PSC_UHPI
#define    CSL_LPSC_NUMBER_EMAC_0               CSL_PSC_EMAC
#define    CSL_LPSC_NUMBER_EMIFB_0              CSL_PSC_EMIFB
#define    CSL_LPSC_NUMBER_MCASP_0              CSL_PSC_MCASP0
#define    CSL_LPSC_NUMBER_MCASP_1              CSL_PSC_MCASP1
#define    CSL_LPSC_NUMBER_MCASP_2              CSL_PSC_MCASP2
#define    CSL_LPSC_NUMBER_SPI_1                CSL_PSC_SPI1
#define    CSL_LPSC_NUMBER_I2C_1                CSL_PSC_I2C1
#define    CSL_LPSC_NUMBER_UART_1               CSL_PSC_UART1
#define    CSL_LPSC_NUMBER_UART_2               CSL_PSC_UART2
#define    CSL_LPSC_NUMBER_LCDC_0               CSL_PSC_LCDC
#define    CSL_LPSC_NUMBER_EHRPWM_0             CSL_PSC_EHRPWM0_1_2
#define    CSL_LPSC_NUMBER_EHRPWM_1             CSL_PSC_EHRPWM0_1_2
#define    CSL_LPSC_NUMBER_EHRPWM_2             CSL_PSC_EHRPWM0_1_2
#define    CSL_LPSC_NUMBER_ECAP_0               CSL_PSC_ECAP0_1_2
#define    CSL_LPSC_NUMBER_ECAP_1               CSL_PSC_ECAP0_1_2
#define    CSL_LPSC_NUMBER_EQEP_0               CSL_PSC_EQEP0_1_2
#define    CSL_LPSC_NUMBER_EQEP_1               CSL_PSC_EQEP0_1_2
#define    CSL_LPSC_NUMBER_EDMA3_1_TC_1         CSL_PSC_TC2
#define    CSL_LPSC_NUMBER_SCRF_7               CSL_PSC_SCRF7_SS
#define    CSL_LPSC_NUMBER_SCRF_8               CSL_PSC_SCRF8_SS
#define    CSL_LPSC_NUMBER_SHRAM                CSL_PSC_SHRAM



#define    CSL_LPSC_INSTANCE_MAX            2u
#define    CSL_LPSC_NUMBER_MAX              32u

/************************  PSC instances of peripherals **********************/
/* In some SOCs, the peripherals are spread across more that one LPSC. Hence *
 * the knowledge of the PSC instance on which they reside is important for   *
 * driver                                                                    */

#define    CSL_LPSC_INST_EDMA3_0_CC_0           CSL_PSC_0
#define    CSL_LPSC_INST_EDMA3_0_TC_0           CSL_PSC_0
#define    CSL_LPSC_INST_EDMA3_0_TC_1           CSL_PSC_0
#define    CSL_LPSC_INST_EMIFA_0                CSL_PSC_0
#define    CSL_LPSC_INST_SPI_0                  CSL_PSC_0
#define    CSL_LPSC_INST_MMCSD_0                CSL_PSC_0
#define    CSL_LPSC_INST_AINTC_0                CSL_PSC_0
#define    CSL_LPSC_INST_ARM_RAMROM_0           CSL_PSC_0
#define    CSL_LPSC_INST_SECCNTL_KEYMGR_0       CSL_PSC_0
#define    CSL_LPSC_INST_UART_0                 CSL_PSC_0
#define    CSL_LPSC_INST_SCR_0                  CSL_PSC_0
#define    CSL_LPSC_INST_SCR_1                  CSL_PSC_0
#define    CSL_LPSC_INST_SCR_2                  CSL_PSC_0
#define    CSL_LPSC_INST_ARM                    CSL_PSC_0
#define    CSL_LPSC_INST_DSP                    CSL_PSC_0



/* Peripherals in PSC0                                                        */
#define    CSL_LPSC_INST_USB_0                  CSL_PSC_1
#define    CSL_LPSC_INST_USB_1                  CSL_PSC_1
#define    CSL_LPSC_INST_GPIO_0                 CSL_PSC_1
#define    CSL_LPSC_INST_UHPI_0                 CSL_PSC_1
#define    CSL_LPSC_INST_EMAC_0                 CSL_PSC_1
#define    CSL_LPSC_INST_EMIFB_0                CSL_PSC_1
#define    CSL_LPSC_INST_MCASP_0                CSL_PSC_1
#define    CSL_LPSC_INST_MCASP_1                CSL_PSC_1
#define    CSL_LPSC_INST_MCASP_2                CSL_PSC_1
#define    CSL_LPSC_INST_SPI_1                  CSL_PSC_1
#define    CSL_LPSC_INST_I2C_1                  CSL_PSC_1
#define    CSL_LPSC_INST_UART_1                 CSL_PSC_1
#define    CSL_LPSC_INST_UART_2                 CSL_PSC_1
#define    CSL_LPSC_INST_LCDC_0                 CSL_PSC_1
#define    CSL_LPSC_INST_EHRPWM_0               CSL_PSC_1
#define    CSL_LPSC_INST_EHRPWM_1               CSL_PSC_1
#define    CSL_LPSC_INST_EHRPWM_2               CSL_PSC_1
#define    CSL_LPSC_INST_ECAP_0                 CSL_PSC_1
#define    CSL_LPSC_INST_ECAP_1                 CSL_PSC_1
#define    CSL_LPSC_INST_EQEP_0                 CSL_PSC_1
#define    CSL_LPSC_INST_EQEP_1                 CSL_PSC_1
#define    CSL_LPSC_INST_EDMA3_1_TC_1           CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_7                 CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_8                 CSL_PSC_1
#define    CSL_LPSC_INST_SHRAM                  CSL_PSC_1

#ifdef __cplusplus
}
#endif
#endif /* CSLR_SOC_H_ */
