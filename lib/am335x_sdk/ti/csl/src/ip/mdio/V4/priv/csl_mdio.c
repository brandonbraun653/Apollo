/**
 * @file  csl_mdio.c
 *
 * @brief
 *  Functional layer implementation of CSL MDIO IP version 4
 *
 *  Contains the different control command and status query functions definitions
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2018, Texas Instruments, Inc.
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

#include <string.h>
#include <stdbool.h>
#include <ti/csl/cslr.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_mdio.h>

void CSL_MDIO_getVersionInfo(
    CSL_mdioHandle          hMdioRegs,
    CSL_MDIO_VERSION*       mdioVersionInfo
)
{
    mdioVersionInfo->revMin     =   CSL_FEXT (hMdioRegs->VERSION_REG, MDIO_VERSION_REG_REVMINOR);
    mdioVersionInfo->revMaj     =   CSL_FEXT (hMdioRegs->VERSION_REG, MDIO_VERSION_REG_REVMAJ);
    mdioVersionInfo->modId      =   CSL_FEXT (hMdioRegs->VERSION_REG, MDIO_VERSION_REG_MODID);

    return;
}

uint16_t CSL_MDIO_getClkDivVal(
    CSL_mdioHandle          hMdioRegs
)
{
    return (uint16_t)CSL_FEXT (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_CLKDIV);
}

void CSL_MDIO_setClkDivVal(
    CSL_mdioHandle          hMdioRegs,
    uint16_t                 clkDivVal
)
{
    CSL_FINS (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_CLKDIV, (uint32_t)clkDivVal);

    return;
}

uint32_t CSL_MDIO_isStateMachineEnabled(
    CSL_mdioHandle          hMdioRegs
)
{
    return CSL_FEXT (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_ENABLE);
}

void CSL_MDIO_enableStateMachine(
    CSL_mdioHandle          hMdioRegs
)
{
    CSL_FINS (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_ENABLE, 1U);

    return;
}

void CSL_MDIO_disableStateMachine(
    CSL_mdioHandle          hMdioRegs
)
{
    CSL_FINS (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_ENABLE, 0U);

    return;
}

uint32_t CSL_MDIO_isPhyAlive(
    CSL_mdioHandle          hMdioRegs,
    uint32_t                  phyAddr
)
{
    return CSL_FEXTR (hMdioRegs->ALIVE_REG, phyAddr, phyAddr);
}


uint32_t CSL_MDIO_isPhyLinked(
    CSL_mdioHandle          hMdioRegs,
    uint32_t                  phyAddr
)
{
    return CSL_FEXTR (hMdioRegs->LINK_REG, phyAddr, phyAddr);
}

uint32_t CSL_MDIO_isUnmaskedLinkStatusChangeIntSet(
    CSL_mdioHandle          hMdioRegs,
    uint32_t                  index
)
{
    return CSL_FEXTR (hMdioRegs->LINK_INT_RAW_REG, index, index);
}

void CSL_MDIO_clearUnmaskedLinkStatusChangeInt(
    CSL_mdioHandle          hMdioRegs,
    uint32_t                  index
)
{
    CSL_FINSR (hMdioRegs->LINK_INT_RAW_REG, index, index, 1U);
}

uint32_t  CSL_MDIO_phyRegRead(uint32_t baseAddr,
                    uint32_t phyAddr,
                    uint32_t regNum,
                    uint16_t *pData)
{
    uint32_t regVal = 0U;
    uint32_t ret_val = 0U;

    /* Wait till transaction completion if any */
    while(CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
        CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO))
    {}
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO_EN_0x1);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_READ);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_REGADR, regNum);
    HW_WR_REG32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U), regVal);

    /* wait for command completion */
    while(CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
        CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO))
    {}

    /* Store the data if the read is acknowledged */
    if(CSL_MDIO_USER_GROUP_USER_ACCESS_REG_ACK_PASS ==
        HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
        CSL_MDIO_USER_GROUP_USER_ACCESS_REG_ACK))
    {
        *pData = (uint16_t)(HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
            CSL_MDIO_USER_GROUP_USER_ACCESS_REG_DATA));
        ret_val = (uint32_t)TRUE;
    }
    else
    {
        ret_val = (uint32_t)FALSE;
    }

    return(ret_val);
}

void CSL_MDIO_phyRegWrite(uint32_t baseAddr, uint32_t phyAddr, uint32_t regNum, uint16_t wrVal)
{
    uint32_t regVal = 0U;

    /* Wait till transaction completion if any */
    while(CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
        CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO))
    {}

    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO_EN_0x1);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_REGADR, regNum);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_DATA, wrVal);
    HW_WR_REG32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U), regVal);

    /* wait for command completion */
    while(CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
        CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO))
    {}
}

uint32_t CSL_MDIO_phyLinkStatus(uint32_t baseAddr, uint32_t phyAddr)
{
    uint32_t retVal = FALSE;

    if(0U != ((HW_RD_REG32(baseAddr + CSL_MDIO_LINK_REG)) & ((1U) << phyAddr)))
    {
        retVal =  (uint32_t)TRUE;
    }

    return retVal;
}

void CSL_MDIO_enableLinkStatusChangeInterrupt (
    CSL_mdioHandle          hMdioRegs,
    Uint32                  index,
    Uint32                  phyAddr
)
{
    hMdioRegs->USER_GROUP [index].USER_PHY_SEL_REG  =   CSL_FMK (MDIO_USER_GROUP_USER_PHY_SEL_REG_PHYADR_MON, phyAddr) |
                                                        CSL_FMK (MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKINT_ENABLE, 1U);
    return;
}

void CSL_MDIO_disableLinkStatusChangeInterrupt (
    CSL_mdioHandle          hMdioRegs,
    Uint32                  index,
    Uint32                  phyAddr
)
{
    hMdioRegs->USER_GROUP [index].USER_PHY_SEL_REG  =   CSL_FMK (MDIO_USER_GROUP_USER_PHY_SEL_REG_PHYADR_MON, phyAddr) |
                                                        CSL_FMK (MDIO_USER_GROUP_USER_PHY_SEL_REG_LINKINT_ENABLE, 0U);

    return;
}

void CSL_MDIO_enableFaultDetect (
    CSL_mdioHandle          hMdioRegs
)
{
    CSL_FINS (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_FAULT_DETECT_ENABLE, 1U);

    return;
}

void CSL_MDIO_disableFaultDetect (
    CSL_mdioHandle          hMdioRegs
)
{
    CSL_FINS (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_FAULT_DETECT_ENABLE, 0U);

    return;
}

void CSL_MDIO_enablePreamble (
    CSL_mdioHandle          hMdioRegs
)
{
    CSL_FINS (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_PREAMBLE, 0U);

    return;
}

void CSL_MDIO_disablePreamble (
    CSL_mdioHandle          hMdioRegs
)
{
    CSL_FINS (hMdioRegs->CONTROL_REG, MDIO_CONTROL_REG_PREAMBLE, 1U);

    return;
}
