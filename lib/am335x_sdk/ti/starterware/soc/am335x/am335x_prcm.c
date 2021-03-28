/**
 *  \file  prcm.c
 *
 * \brief  This file contains the implementations for prcm API's. These API's
 *         identify the corresponding SoC clock tree data, and configure the
 *         corresponding module.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "chipdb.h"
#include "error.h"
#include "hw_types.h"
#include "debug.h"
#include "prcm.h"
#include "soc_am335x.h"
#include "hw_cm_per.h"
#include "hw_cm_wkup.h"
#include "hw_cm_rtc.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define PRCM_MODULEMODE_ENABLE           (2U)
#define PRCM_MODULEMODE_MASK             (3U)
#define PRCM_IDLE_ST_MASK                (0x00030000U)
#define PRCM_IDLE_ST_SHIFT               (16U)

#define PRCM_MODULE_IDLEST_FUNC          (0U)
#define PRCM_MODULE_IDLEST_TRANS         (1U)
#define PRCM_MODULE_IDLEST_IDLE          (2U)
#define PRCM_MODULE_IDLEST_DISABLE       (3U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void enableModule(uint32_t domainOffset, uint32_t clkCtrlReg,
                uint32_t clkStCtrlReg, uint32_t clkActMask)
{
    /* Enable the module */
    HW_WR_REG32(domainOffset + clkCtrlReg, PRCM_MODULEMODE_ENABLE);
    /* Check for module enable status */
    while(PRCM_MODULEMODE_ENABLE !=
        (HW_RD_REG32(domainOffset + clkCtrlReg) & PRCM_MODULEMODE_MASK));
    /* Check clock activity - ungated */
    while(clkActMask != (HW_RD_REG32(domainOffset + clkStCtrlReg) & clkActMask));
    /* Check idle status value - should be in functional state */
    while((PRCM_MODULE_IDLEST_FUNC << PRCM_IDLE_ST_SHIFT) !=
        (HW_RD_REG32(domainOffset + clkCtrlReg) & PRCM_IDLE_ST_MASK));
}

int32_t PRCMModuleEnable(chipdbModuleID_t moduleId, uint32_t instNum,
                                                    uint32_t isBlockingCall)
{
    int32_t status = S_PASS;
    switch(moduleId)
    {
#if defined(BUILDCFG_MOD_MMCSD)
        case CHIPDB_MOD_ID_MMCSD:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_PER_REGS, CM_PER_MMC0_CLKCTRL,
                         CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MMC_FCLK);
                    break;
                case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_MMC1_CLKCTRL,
                         CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MMC_FCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_MMCSD) */

#if defined(BUILDCFG_MOD_UART)
        case CHIPDB_MOD_ID_UART:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_WKUP_REGS, CM_WKUP_UART0_CLKCTRL,
                        CM_WKUP_CLKSTCTRL,
                        CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK);
                    break;
               case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_UART1_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK);
                    break;
               case 2:
                    enableModule(SOC_CM_PER_REGS, CM_PER_UART2_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK);
                    break;
               case 3:
                    enableModule(SOC_CM_PER_REGS, CM_PER_UART3_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK);
                    break;
               case 4:
                    enableModule(SOC_CM_PER_REGS, CM_PER_UART4_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK);
                    break;
                case 5:
                    enableModule(SOC_CM_PER_REGS, CM_PER_UART5_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_UART) */

#if defined(BUILDCFG_MOD_GPIO)

        case CHIPDB_MOD_ID_GPIO:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_WKUP_REGS, CM_WKUP_GPIO0_CLKCTRL,
                        CM_WKUP_CLKSTCTRL,
                        CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK);
                    break;

                case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_GPIO1_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK);
                    break;
                case 2:
                    enableModule(SOC_CM_PER_REGS, CM_PER_GPIO2_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK);
                    break;
                case 3:
                    enableModule(SOC_CM_PER_REGS, CM_PER_GPIO3_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK);
                    break;    
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_GPIO) */

#if defined(BUILDCFG_MOD_EDMA3CC)
        case CHIPDB_MOD_ID_EDMA3CC:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TPCC_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_EDMA3CC) */

#if defined(BUILDCFG_MOD_EDMA3TC)
        case CHIPDB_MOD_ID_EDMA3TC:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TPTC0_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;
                case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TPTC1_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;
                case 2:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TPTC2_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;

            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_EDMA3TC) */
#if defined(BUILDCFG_MOD_PWMSS)
        case CHIPDB_MOD_ID_PWMSS:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_PER_REGS, CM_PER_EPWMSS0_CLKCTRL,
                                 CM_PER_L4LS_CLKSTCTRL,
                                 CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK);
                    break;
                case 2:
                    enableModule(SOC_CM_PER_REGS, CM_PER_EPWMSS2_CLKCTRL,
                                 CM_PER_L4LS_CLKSTCTRL,
                                 CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK);
                    break;
            }
        }
        break;
#endif /* #if defined(BUILDCFG_MOD_PWMSS) */

#if defined(BUILDCFG_MOD_I2C)
        case CHIPDB_MOD_ID_I2C:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_WKUP_REGS, CM_WKUP_I2C0_CLKCTRL,
                        CM_WKUP_CLKSTCTRL,
                        CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK);
                    break;
                case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_I2C1_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL,
                        CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK);
                    break;
            }
        }
#endif /* if defined(BUILDCFG_MOD_I2C) */

#if defined(BUILDCFG_MOD_DMTIMER)       
        case CHIPDB_MOD_ID_DMTIMER:
        {       
            switch(instNum)
            {      
                /* Mux line for Timer clock is set to Master osc clock by 
                default*/                
                case 0:
                    enableModule(SOC_CM_WKUP_REGS, CM_WKUP_TIMER0_CLKCTRL, 
                       CM_WKUP_CLKSTCTRL , 
                       CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER0_GCLK);
                case 2:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER2_CLKCTRL, 
                       CM_PER_L4LS_CLKSTCTRL , 
                       CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER2_GCLK);   
                    break;
                case 3:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER3_CLKCTRL, 
                       CM_PER_L4LS_CLKSTCTRL , 
                       CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER3_GCLK);
                    break;
                case 4:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER4_CLKCTRL, 
                       CM_PER_L4LS_CLKSTCTRL , 
                       CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER4_GCLK);
                    break;
                case 5:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER5_CLKCTRL, 
                       CM_PER_L4LS_CLKSTCTRL , 
                       CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER5_GCLK);
                    break;
                case 6:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER6_CLKCTRL, 
                       CM_PER_L4LS_CLKSTCTRL , 
                       CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER6_GCLK);
                    break;
                case 7:
                    enableModule(SOC_CM_PER_REGS, CM_PER_TIMER7_CLKCTRL, 
                       CM_PER_L4LS_CLKSTCTRL , 
                       CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER7_GCLK);
                    break;                     
            }
        }
        break;   
#endif /* if defined(BUILDCFG_MOD_DMTIMER) */

#if defined(BUILDCFG_MOD_MCSPI)
        case CHIPDB_MOD_ID_MCSPI:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_PER_REGS, CM_PER_SPI0_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;
                case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_SPI1_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_MCSPI) */

#if defined(BUILDCFG_MOD_ADC)
        case CHIPDB_MOD_ID_ADC0:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_WKUP_REGS, CM_WKUP_ADC_TSC_CLKCTRL,
                        CM_WKUP_CLKSTCTRL,
                        CM_WKUP_CLKSTCTRL_CLKACTIVITY_ADC_FCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_ADC) */

#if defined(BUILDCFG_MOD_WDT)
        case CHIPDB_MOD_ID_WDT:
        {
            switch(instNum)
            {
                case 1:
                    enableModule(SOC_CM_WKUP_REGS, CM_WKUP_WDT1_CLKCTRL,
                        CM_WKUP_CLKSTCTRL,
                        CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT1_GCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_WDT) */

#if defined(BUILDCFG_MOD_RTC)
        case CHIPDB_MOD_ID_RTCSS:
        {
            enableModule(SOC_CM_RTC_REGS, CM_RTC_RTC_CLKCTRL,
                 CM_RTC_CLKSTCTRL,
                 CM_RTC_CLKSTCTRL_CLKACTIVITY_L4_RTC_GCLK);

            enableModule(SOC_CM_RTC_REGS, CM_RTC_RTC_CLKCTRL,
                 CM_RTC_CLKSTCTRL,
                 CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_32KCLK);
        }
        break;
#endif /* if defined(BUILDCFG_MOD_RTC) */

#if defined(BUILDCFG_MOD_LCDC)
        case CHIPDB_MOD_ID_LCDC:
        {
            enableModule(SOC_CM_PER_REGS, CM_PER_LCDC_CLKCTRL,
                 CM_PER_LCDC_CLKSTCTRL,
                 CM_PER_LCDC_CLKSTCTRL_CLKACTIVITY_LCDC_L3_OCP_GCLK);
        }
        break;
#endif /* if defined(BUILDCFG_MOD_LCDC) */

#if defined(BUILDCFG_MOD_DCAN)
        case CHIPDB_MOD_ID_DCAN:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_PER_REGS, CM_PER_DCAN0_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;
                case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_DCAN1_CLKCTRL,
                        CM_PER_L3_CLKSTCTRL, CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_DCAN) */

        case CHIPDB_MOD_ID_CPSW:
        {
			HW_WR_REG32((SOC_PRCM_REGS + CM_PER_CPGMAC0_CLKCTRL),
							  CM_PER_CPGMAC0_CLKCTRL_MODULEMODE_ENABLE);

			while(0U != (HW_RD_REG32(SOC_PRCM_REGS + CM_PER_CPGMAC0_CLKCTRL)
						& CM_PER_CPGMAC0_CLKCTRL_IDLEST));
        }
        break;
#if defined(BUILDCFG_MOD_GPMC)
        case CHIPDB_MOD_ID_GPMC:
        {
            enableModule(SOC_CM_PER_REGS, CM_PER_GPMC_CLKCTRL,
                        CM_PER_L3S_CLKSTCTRL, CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK);
        }
        break;

        case CHIPDB_MOD_ID_ELM:
        {
            enableModule(SOC_CM_PER_REGS, CM_PER_ELM_CLKCTRL,
                        CM_PER_L4LS_CLKSTCTRL, CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK);
        }
        break;
#endif /* if defined(BUILDCFG_MOD_GPMC) */
#if defined(BUILDCFG_MOD_PRU_ICSS)
        case CHIPDB_MOD_ID_PRU_ICSS:
        {
            /* bring PRU_ICSS module out of reset */
            HWREG( SOC_PRM_PER_REGS) &= 0xFFFFFFFD;

            /* Enable clocks */
            enableModule(SOC_PRCM_REGS, CM_PER_ICSS_CLKCTRL,
                         CM_PER_ICSS_CLKSTCTRL, CM_PER_ICSS_CLKSTCTRL_CLKACTIVITY_ICSS_OCP_GCLK);
        }
        break;
#endif /*if defined(BUILDCFG_MOD_PRU_ICSS) */
#if defined(BUILDCFG_MOD_USB)
        case CHIPDB_MOD_ID_USB:
        {
            enableModule(SOC_CM_PER_REGS, CM_PER_USB0_CLKCTRL,
                CM_PER_L3S_CLKSTCTRL, CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK);
        }
        break;
#endif /*if defined(BUILDCFG_MOD_USB) */
#if defined(BUILDCFG_MOD_MCASP)
        case CHIPDB_MOD_ID_MCASP:
        {
            switch(instNum)
            {
                case 0:
                    enableModule(SOC_CM_PER_REGS, CM_PER_MCASP0_CLKCTRL,
                        CM_PER_L3S_CLKSTCTRL, CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK);
                    break;
                case 1:
                    enableModule(SOC_CM_PER_REGS, CM_PER_MCASP1_CLKCTRL,
                        CM_PER_L3S_CLKSTCTRL, CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK);
                    break;
            }
        }
        break;
#endif /* if defined(BUILDCFG_MOD_MCASP) */
        default:
        {
            status = E_FAIL;
            break;
        }
    }
    return status;
}
