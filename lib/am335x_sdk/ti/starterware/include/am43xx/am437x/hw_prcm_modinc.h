/**
 *  @file      hw_prcm_modinc.h
 *
 *  @brief     Contains the list of modules to be included for compilation
 *
 *  @warning   This file is auto generated. So avoid manual changes. 
 *              If manual changes are required the implications of the 
 *              change in this and other auto generated files has to be 
 *              completely understood.
 */

/* Copyright (c) 2013 - 2018 Texas Instruments Inc - http://www.ti.com */

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

#ifndef HW_PRCM_MODINC_H
#define HW_PRCM_MODINC_H 

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */


/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/*
 * __attribute__ hint to compiler supported?
 */
#define ATTRIBUTE_SUPPORTED 1
#ifdef ATTRIBUTE_SUPPORTED
    #if defined(__GNUC__)
	    #define ATTR(name) __attribute__((section(name)))
	#elif defined(__IAR_SYSTEMS_ICC__)
		#define ATTR(name)
	#endif
#else
  #define ATTR(name)
#endif /* ATTRIBUTE_SUPPORTED */

#define CATTR(name) ATTR(".const:"#name)

/** 
 * Comment off the (#defined) modules which you do not want to include
 */
#define BUILDCFG_PRCM_MOD_CEFUSE
#define BUILDCFG_PRCM_MOD_DEBUGSS
#define BUILDCFG_PRCM_MOD_DSS
#define BUILDCFG_PRCM_MOD_EMIF_FW
#define BUILDCFG_PRCM_MOD_DDRPHY
#define BUILDCFG_PRCM_MOD_DLL
#define BUILDCFG_PRCM_MOD_DLL_AGING
#define BUILDCFG_PRCM_MOD_EMIF
#define BUILDCFG_PRCM_MOD_GPMC
#define BUILDCFG_PRCM_MOD_MMC0
#define BUILDCFG_PRCM_MOD_MMC1
#define BUILDCFG_PRCM_MOD_MMC2
#define BUILDCFG_PRCM_MOD_OCMCRAM
#define BUILDCFG_PRCM_MOD_OTFA_EMIF
#define BUILDCFG_PRCM_MOD_GFX
#define BUILDCFG_PRCM_MOD_GPIO1
#define BUILDCFG_PRCM_MOD_GPIO2
#define BUILDCFG_PRCM_MOD_GPIO3
#define BUILDCFG_PRCM_MOD_GPIO4
#define BUILDCFG_PRCM_MOD_GPIO5
#define BUILDCFG_PRCM_MOD_MAG_CARD
#define BUILDCFG_PRCM_MOD_L3
#define BUILDCFG_PRCM_MOD_L3_INSTR
#define BUILDCFG_PRCM_MOD_L4FW
#define BUILDCFG_PRCM_MOD_L4LS
#define BUILDCFG_PRCM_MOD_L4_HS
#define BUILDCFG_PRCM_MOD_ICSS
#define BUILDCFG_PRCM_MOD_IEEE5000
#define BUILDCFG_PRCM_MOD_LCDC
#define BUILDCFG_PRCM_MOD_MSTR_EXPS
#define BUILDCFG_PRCM_MOD_SLV_EXPS
#define BUILDCFG_PRCM_MOD_TPCC
#define BUILDCFG_PRCM_MOD_TPTC0
#define BUILDCFG_PRCM_MOD_TPTC1
#define BUILDCFG_PRCM_MOD_TPTC2
#define BUILDCFG_PRCM_MOD_DCAN0
#define BUILDCFG_PRCM_MOD_DCAN1
#define BUILDCFG_PRCM_MOD_ELM
#define BUILDCFG_PRCM_MOD_EPWMSS0
#define BUILDCFG_PRCM_MOD_EPWMSS1
#define BUILDCFG_PRCM_MOD_EPWMSS2
#define BUILDCFG_PRCM_MOD_EPWMSS3
#define BUILDCFG_PRCM_MOD_EPWMSS4
#define BUILDCFG_PRCM_MOD_EPWMSS5
#define BUILDCFG_PRCM_MOD_ERMC
#define BUILDCFG_PRCM_MOD_HDQ1W
#define BUILDCFG_PRCM_MOD_I2C1
#define BUILDCFG_PRCM_MOD_I2C2
#define BUILDCFG_PRCM_MOD_MCASP0
#define BUILDCFG_PRCM_MOD_QSPI
#define BUILDCFG_PRCM_MOD_SPI0
#define BUILDCFG_PRCM_MOD_SPI1
#define BUILDCFG_PRCM_MOD_SPI2
#define BUILDCFG_PRCM_MOD_SPI3
#define BUILDCFG_PRCM_MOD_SPI4
#define BUILDCFG_PRCM_MOD_TIMER10
#define BUILDCFG_PRCM_MOD_TIMER11
#define BUILDCFG_PRCM_MOD_TIMER2
#define BUILDCFG_PRCM_MOD_TIMER3
#define BUILDCFG_PRCM_MOD_TIMER4
#define BUILDCFG_PRCM_MOD_TIMER5
#define BUILDCFG_PRCM_MOD_TIMER6
#define BUILDCFG_PRCM_MOD_TIMER7
#define BUILDCFG_PRCM_MOD_TIMER8
#define BUILDCFG_PRCM_MOD_TIMER9
#define BUILDCFG_PRCM_MOD_UART1
#define BUILDCFG_PRCM_MOD_UART2
#define BUILDCFG_PRCM_MOD_UART3
#define BUILDCFG_PRCM_MOD_UART4
#define BUILDCFG_PRCM_MOD_UART5
#define BUILDCFG_PRCM_MOD_CPGMAC0
#define BUILDCFG_PRCM_MOD_MAILBOX0
#define BUILDCFG_PRCM_MOD_MCASP1
#define BUILDCFG_PRCM_MOD_SPARE0
#define BUILDCFG_PRCM_MOD_SPARE1
#define BUILDCFG_PRCM_MOD_SPINLOCK
#define BUILDCFG_PRCM_MOD_MPU
#define BUILDCFG_PRCM_MOD_OCP_WP_NOC
#define BUILDCFG_PRCM_MOD_RTC
#define BUILDCFG_PRCM_MOD_AES0
#define BUILDCFG_PRCM_MOD_CRYPTODMA
#define BUILDCFG_PRCM_MOD_DES
#define BUILDCFG_PRCM_MOD_PKA
#define BUILDCFG_PRCM_MOD_RNG
#define BUILDCFG_PRCM_MOD_SHA0
#define BUILDCFG_PRCM_MOD_SMARTREFLEX0
#define BUILDCFG_PRCM_MOD_SMARTREFLEX1
#define BUILDCFG_PRCM_MOD_USB_PHY0_ALWAYS_ON
#define BUILDCFG_PRCM_MOD_USB_PHY1_ALWAYS_ON
#define BUILDCFG_PRCM_MOD_WDT0
#define BUILDCFG_PRCM_MOD_WDT1
#define BUILDCFG_PRCM_MOD_TPMSS
#define BUILDCFG_PRCM_MOD_USBPHYOCP2SCP0
#define BUILDCFG_PRCM_MOD_USBPHYOCP2SCP1
#define BUILDCFG_PRCM_MOD_USB_OTG_SS0
#define BUILDCFG_PRCM_MOD_USB_OTG_SS1
#define BUILDCFG_PRCM_MOD_USIM0
#define BUILDCFG_PRCM_MOD_USIM1
#define BUILDCFG_PRCM_MOD_VPFE0
#define BUILDCFG_PRCM_MOD_VPFE1
#define BUILDCFG_PRCM_MOD_ADC_TSC
#define BUILDCFG_PRCM_MOD_CLKDIV32K
#define BUILDCFG_PRCM_MOD_CONTROL
#define BUILDCFG_PRCM_MOD_GPIO0
#define BUILDCFG_PRCM_MOD_I2C0
#define BUILDCFG_PRCM_MOD_L4WKUP
#define BUILDCFG_PRCM_MOD_SYNCTIMER
#define BUILDCFG_PRCM_MOD_TIMER0
#define BUILDCFG_PRCM_MOD_TIMER1
#define BUILDCFG_PRCM_MOD_UART0
#define BUILDCFG_PRCM_MOD_WKUP_M3
#define BUILDCFG_PRCM_MOD_EFUSE


/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* HW_PRCM_MODINC_H */

