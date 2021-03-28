/**
 *  \file  am43xx_control.c
 *
 * \brief  This file contains the implementations for am43xx control module
 *         API's.
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
#include "hw_types.h"
#include "ethernet.h"
#include "am437x.h"
#include "soc_control.h"
#include "hw_control_am43xx.h"
#include "hw_cm_per.h"
#include "pl310.h"
#include "hw_cm_dpll.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void SOCCtrlTimerClkSrcSelect(uint32_t instance, uint32_t timerClkSrc)
{
    switch(instance)
    {
        case 2U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER2_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER2_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER2_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_SHIFT)) != timerClkSrc);
            break;

        case 3U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER3_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER3_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER3_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_SHIFT)) != timerClkSrc);
            break;

        case 4U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER4_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER4_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER4_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_SHIFT)) != timerClkSrc);
            break;

        case 5U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER5_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER5_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER5_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_SHIFT)) != timerClkSrc);
            break;

        case 6U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER6_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER6_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER6_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_SHIFT)) != timerClkSrc);
            break;

        case 7U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER7_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER7_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER7_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_SHIFT)) != timerClkSrc);
            break;

        case 8U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER8_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER8_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER8_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_SHIFT)) != timerClkSrc);
            break;

        case 9U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER9_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER9_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER9_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_SHIFT)) != timerClkSrc);
            break;

        case 10U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER10_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER10_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER10_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_SHIFT)) != timerClkSrc);
            break;

        case 11U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER11_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER11_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REG +
                PRCM_CM_DPLL_CLKSEL_TIMER11_CLK,
                PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_MASK,
                PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_SHIFT)) != timerClkSrc);
            break;

        default:
            break;
    }
}

int32_t SOCL2SramConfig(uint32_t l2SramFlag)
{
    uint32_t ctrlRegVal = 0;
    int32_t status = S_PASS;

    /* TODO: Check of correct clock input to L2SRAM - CONTROL_MPUSS_CTRL. */

    if(L2_CONFIG_AS_SRAM ==l2SramFlag)
    {
        PL310Disable();
    }

    if((L2_CONFIG_AS_CACHE == l2SramFlag) || (L2_CONFIG_AS_SRAM ==l2SramFlag))
    {
        /* PRCM_CM_PER_SPARE0_CLKCTRL   0x4e8U
           SOC_CM_PER_REG            0x44df8800U
           L4LS_GCLK
           PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_MASK */
        /* TODO: Use PRCM module enable */
        HW_WR_REG32((SOC_CM_PER_REG + PRCM_CM_PER_SPARE0_CLKCTRL),
            PRCM_CM_PER_SPARE0_CLKCTRL_MODULEMODE_ENABLE);

        while((HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_SPARE0_CLKCTRL) &
                PRCM_CM_PER_SPARE1_CLKCTRL_IDLEST_MASK) !=
                        PRCM_CM_PER_SPARE1_CLKCTRL_IDLEST_FUNC);

        ctrlRegVal = HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_SEC_SPARE0);
        ctrlRegVal = ((ctrlRegVal & ~CTRL_SEC_SPARE0_PIUSEL2SRAM_MASK) |
                         ((l2SramFlag << CTRL_SEC_SPARE0_PIUSEL2SRAM_SHIFT) &
                         CTRL_SEC_SPARE0_PIUSEL2SRAM_MASK));

        HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_SEC_SPARE0, ctrlRegVal);
    }
    else
    {
        status = E_INVALID_PARAM;
    }
    return status;
}


void SOCCtrlPwmssTimebaseClkEnable(uint32_t instance)
{
    uint32_t regVal = HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_PWMSS);

    switch(instance)
    {

         case 0U:
            regVal |= CTRL_PWMSS_PWMSS0_TBCLKEN_MASK;
            break;

         case 1U:
            regVal |= CTRL_PWMSS_PWMMS1_TBCLKEN_MASK;
            break;

         case 2U:
            regVal |= CTRL_PWMSS_PWMSS2_TBCLKEN_MASK;
            break;

         case 3U:
            regVal |= CTRL_PWMSS_PWMSS3_TBCLKEN_MASK;
            break;

         case 4U:
            regVal |= CTRL_PWMSS_PWMMS4_TBCLKEN_MASK;
            break;

         case 5U:
            regVal |= CTRL_PWMSS_PWMSS5_TBCLKEN_MASK;
            break;

         default:
         break;
    }

    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_PWMSS), regVal);
}

void SOCDcanMessageRamInit(uint32_t instance)
{
    uint32_t regVal = HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_DCAN_RAMINIT);
    uint32_t status = 0U;

    switch(instance)
    {
         case 0U:
            regVal |= CTRL_DCAN_RAMINIT_DCAN0_START_MASK;
            status = CTRL_DCAN_RAMINIT_DCAN0_DONE_MASK;
            break;

         case 1U:
            regVal |= CTRL_DCAN_RAMINIT_DCAN1_START_MASK;
            status = CTRL_DCAN_RAMINIT_DCAN1_DONE_MASK;
            break;

         default:
         break;
    }

    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DCAN_RAMINIT), regVal);

    while(status !=
         ((status & HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_DCAN_RAMINIT))));
}

void SOCCtrlCpswPortMacModeSelect(uint32_t portNum, uint32_t macMode)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_GMII_SEL);

    switch(macMode)
    {
        case ETHERNET_MAC_TYPE_MII:
        case ETHERNET_MAC_TYPE_GMII:
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII1, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII2, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

        case ETHERNET_MAC_TYPE_RMII: /* RMII */
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII1, 1U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII2, 1U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

        case ETHERNET_MAC_TYPE_RGMII: /* RGMII */
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII1, 2U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_GMII2, 2U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CTRL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

         default:
         break;
    }

    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_GMII_SEL), regVal);
}

void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    switch(portNum)
    {
        case 1U:
            pMacAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_LO,
                CTRL_MAC_ID0_LO_MACADDR_7_0);
            pMacAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_LO,
                CTRL_MAC_ID0_LO_MACADDR_15_8);
            pMacAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_23_16);
            pMacAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_31_24);
            pMacAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_39_32);
            pMacAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID0_HI,
                CTRL_MAC_ID0_HI_MACADDR_47_40);
            break;

        case 2U:
            pMacAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_LO,
                CTRL_MAC_ID0_LO_MACADDR_7_0);
            pMacAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_LO,
                CTRL_MAC_ID0_LO_MACADDR_15_8);
            pMacAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_23_16);
            pMacAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_31_24);
            pMacAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_39_32);
            pMacAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_MAC_ID1_HI,
                CTRL_MAC_ID1_HI_MACADDR_47_40);
            break;

        default:
            break;
    }
}
