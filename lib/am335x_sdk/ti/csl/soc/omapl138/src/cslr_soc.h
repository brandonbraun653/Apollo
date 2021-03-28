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
#include <ti/csl/soc/omapl138/src/cslr_soc_baseaddress.h>
#include <ti/csl/soc/omapl138/src/cslr_interrupt.h>

#ifndef CSLR_SOC_H
#define CSLR_SOC_H

#ifdef __cplusplus
extern "C"
{
#endif
/*************************** LPSC Numbers of peripherals **********************/
/* Even though this are defined in cslr_psc<soc>.h, we are redefining here we *
 * need to have same macros in the driver, for use across multiple Socs       */

/*When PWRM is not enabled, we would be using the psc apis provided by the    *
 * driver. These APIs use rCSL based LPSC number and hence are mapped to rCSL *
 * macros/ENUMS.                                                              */
#ifndef BIOS_PWRM_ENABLE

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
	CSL_PSC_EDMA_CC1    =16,
	CSL_PSC_USB20       =17,   /*PSC1*/
	CSL_PSC_USB11       =18,   /*PSC1*/
	CSL_PSC_GPIO        =19,   /*PSC1*/
	CSL_PSC_UHPI        =20,   /*PSC1*/
	CSL_PSC_EMAC        =21,   /*PSC1*/
	CSL_PSC_DDR         =22,   /*PSC1*/
	CSL_PSC_MCASP0      =23,   /*PSC1*/
	CSL_PSC_SATA        =24,   /*PSC1*/
	CSL_PSC_VPIF        =25,   /*PSC1*/
	CSL_PSC_SPI1        =26,  /*PSC1*/
	CSL_PSC_I2C1        =27,  /*PSC1*/
	CSL_PSC_UART1       =28,  /*PSC1*/
	CSL_PSC_UART2       =29,  /*PSC1*/
	CSL_PSC_MCBSP0      =30,  /*PSC1*/
	CSL_PSC_MCBSP1      =31,  /*PSC1*/
	CSL_PSC_LCDC        =32,  /*PSC1*/
	CSL_PSC_EPWM        =33,  /*PSC1*/
	CSL_PSC_MMCSD1      =34,
	CSL_PSC_UPP         =35,
	CSL_PSC_ECAP        =36,
	CSL_PSC_EDMA_TC2    =37,
	// CSL_PSC #22-23 not used
	CSL_PSC_SCR_F0      =38,
	CSL_PSC_SCR_F1      =39,
	CSL_PSC_SCR_F2      =40,
	CSL_PSC_SCR_F6      =41,
	CSL_PSC_SCR_F7      =42,
	CSL_PSC_SCR_F8      =43,
	CSL_PSC_BR_F7       =44,
	CSL_PSC_SHARED_RAM  =45
} CSL_Psc1Peripheral;

/* Peripherals in PSC0                                                        */
#define    CSL_LPSC_NUMBER_EDMA3_0_CC_0         CSL_PSC_CC0
#define    CSL_LPSC_NUMBER_EDMA3_0_TC_0         CSL_PSC_TC0
#define    CSL_LPSC_NUMBER_EDMA3_0_TC_1         CSL_PSC_TC1
#define    CSL_LPSC_NUMBER_EMIFA_0              CSL_PSC_EMIFA
#define    CSL_LPSC_NUMBER_SPI_0                CSL_PSC_SPI0
#define    CSL_LPSC_NUMBER_MMCSD_0              CSL_PSC_MMCSD0
#define    CSL_LPSC_NUMBER_UART_0               CSL_PSC_UART0
#define    CSL_LPSC_NUMBER_SCR_0                CSL_PSC_SCR0_SS
#define    CSL_LPSC_NUMBER_SCR_1                CSL_PSC_SCR1_SS
#define    CSL_LPSC_NUMBER_SCR_2                CSL_PSC_SCR2_SS
#define    CSL_LPSC_NUMBER_DSP                  CSL_PSC_DSP

/* Peripherals in PSC1                                                        */
#define    CSL_LPSC_NUMBER_EDMA3_1_CC_0         CSL_PSC_CC1
#define    CSL_LPSC_NUMBER_USB_0                CSL_PSC_USB0
#define    CSL_LPSC_NUMBER_USB_1                CSL_PSC_USB1
#define    CSL_LPSC_NUMBER_GPIO_0               CSL_PSC_GPIO
#define    CSL_LPSC_NUMBER_UHPI_0               CSL_PSC_UHPI
#define    CSL_LPSC_NUMBER_EMAC_0               CSL_PSC_EMAC
#define    CSL_LPSC_NUMBER_DDR2_MDDR_0          CSL_PSC_DDR2_MDDR
#define    CSL_LPSC_NUMBER_MCASP_0              CSL_PSC_MCASP0
#define    CSL_LPSC_NUMBER_SATA_0               CSL_PSC_SATA
#define    CSL_LPSC_NUMBER_VPIF_0               CSL_PSC_VPIF
#define    CSL_LPSC_NUMBER_SPI_1                CSL_PSC_SPI1
#define    CSL_LPSC_NUMBER_I2C_1                CSL_PSC_I2C1
#define    CSL_LPSC_NUMBER_UART_1               CSL_PSC_UART1
#define    CSL_LPSC_NUMBER_UART_2               CSL_PSC_UART2
#define    CSL_LPSC_NUMBER_MCBSP_0              CSL_PSC_MCBSP0
#define    CSL_LPSC_NUMBER_MCBSP_1              CSL_PSC_MCBSP1
#define    CSL_LPSC_NUMBER_LCDC_0               CSL_PSC_LCDC
#define    CSL_LPSC_NUMBER_EHRPWM_0             CSL_PSC_EHRPWM
#define    CSL_LPSC_NUMBER_MMCSD_1              CSL_PSC_MMCSD1
#define    CSL_LPSC_NUMBER_UPP_0                CSL_PSC_UPP
#define    CSL_LPSC_NUMBER_ECAP_0               CSL_PSC_ECAP0_1_2
#define    CSL_LPSC_NUMBER_EDMA3_1_TC_1         CSL_PSC_TC2
#define    CSL_LPSC_NUMBER_SCRF_0               CSL_PSC_SCRF0_SS
#define    CSL_LPSC_NUMBER_SCRF_1               CSL_PSC_SCRF1_SS
#define    CSL_LPSC_NUMBER_SCRF_2               CSL_PSC_SCRF2_SS
#define    CSL_LPSC_NUMBER_SCRF_6               CSL_PSC_SCRF6_SS
#define    CSL_LPSC_NUMBER_SCRF_7               CSL_PSC_SCRF7_SS
#define    CSL_LPSC_NUMBER_SCRF_8               CSL_PSC_SCRF8_SS
#define    CSL_LPSC_NUMBER_BR_F7_0              CSL_PSC_BR_F7
#define    CSL_LPSC_NUMBER_SHRAM                CSL_PSC_SHRAM

#else

/* When power management is defined, the straight LPSC numbers are            *
 * not useful for the driver and hence these macros are mapped to             *
 * PWRM specific ID, to be used in PWRM APIs                                  */
    
/* Peripherals in PSC0                                                        */
#define    CSL_LPSC_NUMBER_EDMA3_0_CC_0         Power_RSRC_EDMA3_CC_0
#define    CSL_LPSC_NUMBER_EDMA3_0_TC_0         Power_RSRC_EDMA3_TC_0
#define    CSL_LPSC_NUMBER_EDMA3_0_TC_1         Power_RSRC_EDMA3_TC_1
#define    CSL_LPSC_NUMBER_EMIFA_0              Power_RSRC_EMIFA
#define    CSL_LPSC_NUMBER_SPI_0                Power_RSRC_SPI_0
#define    CSL_LPSC_NUMBER_MMCSD_0              Power_RSRC_MMCSD_0
#define    CSL_LPSC_NUMBER_UART_0               Power_RSRC_UART_0
#define    CSL_LPSC_NUMBER_SCR_0                Power_RSRC_END
#define    CSL_LPSC_NUMBER_SCR_1                Power_RSRC_END
#define    CSL_LPSC_NUMBER_SCR_2                Power_RSRC_END
#define    CSL_LPSC_NUMBER_DSP                  Power_RSRC_END

/* Peripherals in PSC0                                                        */
#define    CSL_LPSC_NUMBER_EDMA3_1_CC_0         Power_RSRC_EDMA3_CC_1
#define    CSL_LPSC_NUMBER_USB_0                Power_RSRC_USB0
#define    CSL_LPSC_NUMBER_USB_1                Power_RSRC_USB1
#define    CSL_LPSC_NUMBER_GPIO_0               Power_RSRC_GPIO
#define    CSL_LPSC_NUMBER_UHPI_0               Power_RSRC_UHPI
#define    CSL_LPSC_NUMBER_EMAC_0               Power_RSRC_EMAC
#define    CSL_LPSC_NUMBER_DDR2_MDDR_0          Power_RSRC_DDR2
#define    CSL_LPSC_NUMBER_MCASP_0              Power_RSRC_MCASP_0
#define    CSL_LPSC_NUMBER_SATA_0               Power_RSRC_SATA
#define    CSL_LPSC_NUMBER_VPIF_0               Power_RSRC_VPIF
#define    CSL_LPSC_NUMBER_SPI_1                Power_RSRC_SPI_1
#define    CSL_LPSC_NUMBER_I2C_1                Power_RSRC_I2C_1
#define    CSL_LPSC_NUMBER_UART_1               Power_RSRC_UART_1
#define    CSL_LPSC_NUMBER_UART_2               Power_RSRC_UART_2
#define    CSL_LPSC_NUMBER_MCBSP_0              Power_RSRC_MCBSP_0
#define    CSL_LPSC_NUMBER_MCBSP_1              Power_RSRC_MCBSP_1
#define    CSL_LPSC_NUMBER_LCDC_0               Power_RSRC_LCDC
#define    CSL_LPSC_NUMBER_EHRPWM_0             Power_RSRC_EHRPWM
#define    CSL_LPSC_NUMBER_MMCSD_1              Power_RSRC_MMCSD_1
#define    CSL_LPSC_NUMBER_UPP_0                Power_RSRC_UPP
#define    CSL_LPSC_NUMBER_ECAP_0               Power_RSRC_ECAP
#define    CSL_LPSC_NUMBER_EDMA3_1_TC_1         Power_RSRC_EDMA3_TC_2
#define    CSL_LPSC_NUMBER_SCRF_0               Power_RSRC_END
#define    CSL_LPSC_NUMBER_SCRF_1               Power_RSRC_END
#define    CSL_LPSC_NUMBER_SCRF_2               Power_RSRC_END
#define    CSL_LPSC_NUMBER_SCRF_6               Power_RSRC_END
#define    CSL_LPSC_NUMBER_SCRF_7               Power_RSRC_END
#define    CSL_LPSC_NUMBER_SCRF_8               Power_RSRC_END
#define    CSL_LPSC_NUMBER_BR_F7_0              Power_RSRC_END
#define    CSL_LPSC_NUMBER_SHRAM                Power_RSRC_END

#endif


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
#define    CSL_LPSC_INST_UART_0                 CSL_PSC_0
#define    CSL_LPSC_INST_SCR_0                  CSL_PSC_0
#define    CSL_LPSC_INST_SCR_1                  CSL_PSC_0
#define    CSL_LPSC_INST_SCR_2                  CSL_PSC_0
#define    CSL_LPSC_INST_DSP                    CSL_PSC_0

/* Peripherals in PSC0                                                        */
#define    CSL_LPSC_INST_EDMA3_1_CC_0           CSL_PSC_1
#define    CSL_LPSC_INST_USB_0                  CSL_PSC_1
#define    CSL_LPSC_INST_USB_1                  CSL_PSC_1
#define    CSL_LPSC_INST_GPIO_0                 CSL_PSC_1
#define    CSL_LPSC_INST_UHPI_0                 CSL_PSC_1
#define    CSL_LPSC_INST_EMAC_0                 CSL_PSC_1
#define    CSL_LPSC_INST_DDR2_MDDR_0            CSL_PSC_1
#define    CSL_LPSC_INST_MCASP_0                CSL_PSC_1
#define    CSL_LPSC_INST_SATA_0                 CSL_PSC_1
#define    CSL_LPSC_INST_VPIF_0                 CSL_PSC_1
#define    CSL_LPSC_INST_SPI_1                  CSL_PSC_1
#define    CSL_LPSC_INST_I2C_1                  CSL_PSC_1
#define    CSL_LPSC_INST_UART_1                 CSL_PSC_1
#define    CSL_LPSC_INST_UART_2                 CSL_PSC_1
#define    CSL_LPSC_INST_MCBSP_0                CSL_PSC_1
#define    CSL_LPSC_INST_MCBSP_1                CSL_PSC_1
#define    CSL_LPSC_INST_LCDC_0                 CSL_PSC_1
#define    CSL_LPSC_INST_EHRPWM_0               CSL_PSC_1
#define    CSL_LPSC_INST_MMCSD_1                CSL_PSC_1
#define    CSL_LPSC_INST_UPP_0                  CSL_PSC_1
#define    CSL_LPSC_INST_ECAP_0                 CSL_PSC_1
#define    CSL_LPSC_INST_EDMA3_1_TC_1           CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_0                 CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_1                 CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_2                 CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_6                 CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_7                 CSL_PSC_1
#define    CSL_LPSC_INST_SCRF_8                 CSL_PSC_1
#define    CSL_LPSC_INST_BR_F7_0                CSL_PSC_1
#define    CSL_LPSC_INST_SHRAM                  CSL_PSC_1

/*************************** EDMA RELATED DEFINES  ****************************/
#ifdef __cplusplus
}
#endif
#endif /* CSLR_SOC_H_ */
