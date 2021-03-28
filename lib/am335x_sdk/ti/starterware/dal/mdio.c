/**
 *  \file   mdio.c
 *
 *  \brief  This file contains the device abstraction layer API implementation
 *          corresponding to MDIO.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_types.h"
#include "error.h"
#include "hw_mdio.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void MDIOPhyRegRead(uint32_t baseAddr,
                    uint32_t phyAddr,
                    uint32_t regNum,
                    uint16_t *pData)
{
    uint32_t regVal = 0U;

    /* Wait till transaction completion if any */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));

    HW_SET_FIELD(regVal, MDIO_USERACCESS_GO, MDIO_USERACCESS_GO_EN_0x1);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_WRITE, MDIO_USERACCESS_READ);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_REGADR, regNum);
    HW_WR_REG32(baseAddr + MDIO_USERACCESS(0U), regVal);

    /* wait for command completion */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));

    /* Store the data if the read is acknowledged */
    if(MDIO_USERACCESS_ACK_PASS ==
        HW_RD_FIELD32(baseAddr + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_ACK))
    {
        *pData = (uint16_t)(HW_RD_FIELD32(baseAddr + MDIO_USERACCESS(0U),
            MDIO_USERACCESS_DATA));
    }
}

void MDIOPhyRegWrite(uint32_t baseAddr,
                     uint32_t phyAddr,
                     uint32_t regNum,
                     uint16_t wrVal)
{
    uint32_t regVal = 0U;

    /* Wait till transaction completion if any */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));

    HW_SET_FIELD(regVal, MDIO_USERACCESS_GO, MDIO_USERACCESS_GO_EN_0x1);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_WRITE, MDIO_USERACCESS_WRITE);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_REGADR, regNum);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_DATA, wrVal);
    HW_WR_REG32(baseAddr + MDIO_USERACCESS(0U), regVal);

    /* wait for command completion */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));
}

uint32_t MDIOPhyAliveStatus(uint32_t baseAddr, uint32_t phyAddr)
{
    uint32_t retVal = FALSE;

    if(0U != (HW_RD_REG32(baseAddr + MDIO_ALIVE) &
        (1U << phyAddr)))
    {
        retVal =  TRUE;
    }

    return retVal;
}

uint32_t MDIOPhyLinkStatus(uint32_t baseAddr, uint32_t phyAddr)
{
    uint32_t retVal = FALSE;

    if(0U != (HW_RD_REG32(baseAddr + MDIO_LINK) &
        (1U << phyAddr)))
    {
        retVal =  TRUE;
    }

    return retVal;
}

void MDIOInit(uint32_t baseAddr,
              uint32_t mdioInputFreq,
              uint32_t mdioOutputFreq)
{
    uint32_t clkDiv = (mdioInputFreq/mdioOutputFreq) - 1U;
    uint32_t regVal = 0U;

    HW_SET_FIELD(regVal, MDIO_CTRL_EN, MDIO_CTRL_EN_0X1);
    HW_SET_FIELD(regVal,  MDIO_CTRL_PREAMBLE, MDIO_CTRL_PREAMBLE_EN_0X0);
    HW_SET_FIELD(regVal, MDIO_CTRL_FAULTENB, MDIO_CTRL_FAULTENB_EN_0X1);
    HW_SET_FIELD(regVal, MDIO_CTRL_CLKDIV, clkDiv);
    HW_WR_REG32(baseAddr + MDIO_CTRL, regVal);
}

/* ========================================================================== */
/*                          Deprecated Function Definitions                   */
/* ========================================================================== */
