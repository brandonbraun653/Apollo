/**
 *  \file  am335x_control.c
 *
 * \brief  This file contains the implementations for am335x control module
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
#include "soc_am335x.h"
#include "soc_control.h"
#include "hw_control_am335x.h"
#include "hw_cm_per.h"
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
            HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER2_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REGS +
                CM_DPLL_CLKSEL_TIMER2_CLK,
                CM_DPLL_CLKSEL_TIMER2_CLK_CLKSEL,
                CM_DPLL_CLKSEL_TIMER2_CLK_CLKSEL_SHIFT)) != timerClkSrc);
            break;

        case 3U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER3_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER3_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REGS +
                CM_DPLL_CLKSEL_TIMER3_CLK,
                CM_DPLL_CLKSEL_TIMER3_CLK_CLKSEL,
                CM_DPLL_CLKSEL_TIMER3_CLK_CLKSEL_SHIFT)) != timerClkSrc);
            break;

        case 4U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER4_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER4_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REGS +
                CM_DPLL_CLKSEL_TIMER4_CLK,
                CM_DPLL_CLKSEL_TIMER4_CLK_CLKSEL,
                CM_DPLL_CLKSEL_TIMER4_CLK_CLKSEL_SHIFT)) != timerClkSrc);
            break;

        case 5U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER5_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER5_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REGS +
                CM_DPLL_CLKSEL_TIMER5_CLK,
                CM_DPLL_CLKSEL_TIMER5_CLK_CLKSEL,
                CM_DPLL_CLKSEL_TIMER5_CLK_CLKSEL_SHIFT)) != timerClkSrc);
            break;

        case 6U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER6_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER6_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REGS +
                CM_DPLL_CLKSEL_TIMER6_CLK,
                CM_DPLL_CLKSEL_TIMER6_CLK_CLKSEL,
                CM_DPLL_CLKSEL_TIMER6_CLK_CLKSEL_SHIFT)) != timerClkSrc);
            break;

        case 7U:
            /* Write to CLKSEL field of CM_DPLL_CLKSEL_TIMER7_CLK register */
            HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER7_CLK,
               timerClkSrc);

            /* Wait for the CLKSEL field to reflect the written value. */
            while((HW_RD_FIELD32_RAW(SOC_CM_DPLL_REGS +
                CM_DPLL_CLKSEL_TIMER7_CLK,
                CM_DPLL_CLKSEL_TIMER7_CLK_CLKSEL,
                CM_DPLL_CLKSEL_TIMER7_CLK_CLKSEL_SHIFT)) != timerClkSrc);
            break;

        default:
            break;
    }
}

void SOCCtrlPwmssTimebaseClkEnable(uint32_t instance)
{
    uint32_t regVal = HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_PWMSS_CTRL);

    switch(instance)
    {

         case 0U:
            regVal |= CONTROL_PWMSS_CTRL_PWMSS0_TBCLKEN;
            break;

         case 1U:
            regVal |= CONTROL_PWMSS_CTRL_PWMMS1_TBCLKEN;
            break;

         case 2U:
            regVal |= CONTROL_PWMSS_CTRL_PWMSS2_TBCLKEN;
            break;

         default:
         break;
    }

    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_PWMSS_CTRL), regVal);
}

void SOCCtrlLcdcPixelClkSelect(void)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_LCDC_PIXEL_CLK);
    regVal |= CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CLKSEL_SEL3;
    HW_WR_REG32((SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_LCDC_PIXEL_CLK), regVal);
}

void SOCDcanMessageRamInit(uint32_t instance)
{
    uint32_t regVal = HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_DCAN_RAMINIT);
    uint32_t status = 0U;

    switch(instance)
    {
         case 0U:
            regVal |= CONTROL_DCAN_RAMINIT_DCAN0_RAMINIT_START;
            status = CONTROL_DCAN_RAMINIT_DCAN0_RAMINIT_DONE;
            break;

         case 1U:
            regVal |= CONTROL_DCAN_RAMINIT_DCAN1_RAMINIT_START;
            status = CONTROL_DCAN_RAMINIT_DCAN1_RAMINIT_DONE;
            break;

         default:
         break;
    }

    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_DCAN_RAMINIT), regVal);

    while(status !=
         ((status & HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_DCAN_RAMINIT))));
}

void SOCCtrlCpswPortMacModeSelect(uint32_t portNum, uint32_t macMode)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_GMII_SEL);

    switch(macMode)
    {
        case ETHERNET_MAC_TYPE_MII:
        case ETHERNET_MAC_TYPE_GMII:
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_GMII1_SEL, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_GMII2_SEL, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

        case ETHERNET_MAC_TYPE_RMII: /* RMII */
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_GMII1_SEL, 1U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RMII1_IO_CLK_EN, 1U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_GMII2_SEL, 1U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RMII2_IO_CLK_EN, 1U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

        case ETHERNET_MAC_TYPE_RGMII: /* RGMII */
            if(1U == portNum)
            {
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_GMII1_SEL, 2U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RGMII1_IDMODE, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RMII1_IO_CLK_EN, 0U);
            }
            else if(2U == portNum)
            {
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_GMII2_SEL, 2U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RGMII2_IDMODE, 0U);
                HW_SET_FIELD(regVal, CONTROL_GMII_SEL_RMII2_IO_CLK_EN, 0U);
            }
            else
            {
                /* This error does not happen because of check done already */
            }
            break;

         default:
         break;
    }

    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_GMII_SEL), regVal);
}

void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    uint32_t slavePortNum = portNum - 1U;

    pMacAddr[5U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum))
                   >> 8U) & 0xFFU;
    pMacAddr[4U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_LO(slavePortNum)))
                  & 0xFF;
    pMacAddr[3U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                   >> 24U) & 0xFFU;
    pMacAddr[2U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                   >> 16U) & 0xFFU;
    pMacAddr[1U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum))
                   >> 8U) & 0xFFU;
    pMacAddr[0U] =  (HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_MAC_ID_HI(slavePortNum)))
                  & 0xFFU;
}
