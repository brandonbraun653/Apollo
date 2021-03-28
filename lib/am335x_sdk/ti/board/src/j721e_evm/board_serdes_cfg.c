/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/
/**
 *  \file   board_cfg.c
 *
 *  \brief  EVM serdes configuration file
 *
 *  Configures the serdes module.
 *
 */

#include "board_serdes_cfg.h"

static Board_STATUS Board_CfgSgmii(void)
{
    CSL_SerdesResult result;
    CSL_SerdesLaneEnableStatus laneRetVal = CSL_SERDES_LANE_ENABLE_NO_ERR;
    CSL_SerdesLaneEnableParams serdesLane0EnableParams  = {0};

    memset(&serdesLane0EnableParams, 0, sizeof(serdesLane0EnableParams));

    /* SGMII Config */
    serdesLane0EnableParams.serdesInstance    = (CSL_SerdesInstance)SGMII_SERDES_INSTANCE;
    serdesLane0EnableParams.baseAddr          = CSL_SERDES_16G0_BASE;
    serdesLane0EnableParams.refClock          = CSL_SERDES_REF_CLOCK_100M;
    serdesLane0EnableParams.refClkSrc         = CSL_SERDES_REF_CLOCK_INT;
    serdesLane0EnableParams.linkRate          = CSL_SERDES_LINK_RATE_1p25G;
    serdesLane0EnableParams.numLanes          = 0x2;
    serdesLane0EnableParams.laneMask          = 0x3;
    serdesLane0EnableParams.SSC_mode          = CSL_SERDES_NO_SSC;
    serdesLane0EnableParams.phyType           = CSL_SERDES_PHY_TYPE_SGMII;
    serdesLane0EnableParams.operatingMode     = CSL_SERDES_FUNCTIONAL_MODE;
    serdesLane0EnableParams.phyInstanceNum    = SERDES_LANE_SELECT_CPSW;
    serdesLane0EnableParams.pcieGenType        = CSL_SERDES_PCIE_GEN3;

    serdesLane0EnableParams.laneCtrlRate[0]   = CSL_SERDES_LANE_FULL_RATE;
    serdesLane0EnableParams.loopbackMode[0]   = CSL_SERDES_LOOPBACK_DISABLED;

    serdesLane0EnableParams.laneCtrlRate[1]   = CSL_SERDES_LANE_FULL_RATE;
    serdesLane0EnableParams.loopbackMode[1]   = CSL_SERDES_LOOPBACK_DISABLED;

    CSL_serdesPorReset(serdesLane0EnableParams.baseAddr);

    /* Select the IP type, IP instance num, Serdes Lane Number */
    CSL_serdesIPSelect(CSL_CTRL_MMR0_CFG0_BASE,
                       serdesLane0EnableParams.phyType,
                       serdesLane0EnableParams.phyInstanceNum,
                       serdesLane0EnableParams.serdesInstance,
                       SGMII_LANE_NUM);


    result = CSL_serdesRefclkSel(CSL_CTRL_MMR0_CFG0_BASE,
                                 serdesLane0EnableParams.baseAddr,
                                 serdesLane0EnableParams.refClock,
                                 serdesLane0EnableParams.refClkSrc,
                                 serdesLane0EnableParams.serdesInstance,
                                 serdesLane0EnableParams.phyType);

    if (result != CSL_SERDES_NO_ERR)
    {
        return BOARD_FAIL;
    }
    /* Assert PHY reset and disable all lanes */
    CSL_serdesDisablePllAndLanes(serdesLane0EnableParams.baseAddr, serdesLane0EnableParams.numLanes, serdesLane0EnableParams.laneMask);

    /* Load the Serdes Config File */
    result = CSL_serdesEthernetInit(&serdesLane0EnableParams);
    /* Return error if input params are invalid */
    if (result != CSL_SERDES_NO_ERR)
    {
        return BOARD_FAIL;
    }

    /* Common Lane Enable API for lane enable, pll enable etc */
    laneRetVal = CSL_serdesLaneEnable(&serdesLane0EnableParams);
    if (laneRetVal != 0)
    {
        return BOARD_FAIL;
    }

    return BOARD_SOK;
}

static Board_STATUS Board_CfgQsgmii(void)
{
    CSL_SerdesResult result;
    CSL_SerdesLaneEnableStatus laneRetVal = CSL_SERDES_LANE_ENABLE_NO_ERR;
    CSL_SerdesLaneEnableParams serdesLane0EnableParams  = {0};

    memset(&serdesLane0EnableParams, 0, sizeof(serdesLane0EnableParams));

    /* QSGMII Config */
    serdesLane0EnableParams.serdesInstance    = (CSL_SerdesInstance)SGMII_SERDES_INSTANCE;
    serdesLane0EnableParams.baseAddr          = CSL_SERDES_16G0_BASE;
    serdesLane0EnableParams.refClock          = CSL_SERDES_REF_CLOCK_100M;
    serdesLane0EnableParams.refClkSrc         = CSL_SERDES_REF_CLOCK_INT;
    serdesLane0EnableParams.linkRate          = CSL_SERDES_LINK_RATE_5G;
    serdesLane0EnableParams.numLanes          = 0x2;
    serdesLane0EnableParams.laneMask          = 0x3;
    serdesLane0EnableParams.SSC_mode          = CSL_SERDES_NO_SSC;
    serdesLane0EnableParams.phyType           = CSL_SERDES_PHY_TYPE_QSGMII;
    serdesLane0EnableParams.operatingMode     = CSL_SERDES_FUNCTIONAL_MODE;
    serdesLane0EnableParams.phyInstanceNum    = SERDES_LANE_SELECT_CPSW;
    serdesLane0EnableParams.pcieGenType        = CSL_SERDES_PCIE_GEN4;

    serdesLane0EnableParams.laneCtrlRate[0]   = CSL_SERDES_LANE_FULL_RATE;
    serdesLane0EnableParams.loopbackMode[0]   = CSL_SERDES_LOOPBACK_DISABLED;

    serdesLane0EnableParams.laneCtrlRate[1]   = CSL_SERDES_LANE_FULL_RATE;
    serdesLane0EnableParams.loopbackMode[1]   = CSL_SERDES_LOOPBACK_DISABLED;

    CSL_serdesPorReset(serdesLane0EnableParams.baseAddr);

    /* Select the IP type, IP instance num, Serdes Lane Number */
    CSL_serdesIPSelect(CSL_CTRL_MMR0_CFG0_BASE,
                       serdesLane0EnableParams.phyType,
                       serdesLane0EnableParams.phyInstanceNum,
                       serdesLane0EnableParams.serdesInstance,
                       SGMII_LANE_NUM);


    result = CSL_serdesRefclkSel(CSL_CTRL_MMR0_CFG0_BASE,
                                 serdesLane0EnableParams.baseAddr,
                                 serdesLane0EnableParams.refClock,
                                 serdesLane0EnableParams.refClkSrc,
                                 serdesLane0EnableParams.serdesInstance,
                                 serdesLane0EnableParams.phyType);

    if (result != CSL_SERDES_NO_ERR)
    {
        return BOARD_FAIL;
    }
    /* Assert PHY reset and disable all lanes */
    CSL_serdesDisablePllAndLanes(serdesLane0EnableParams.baseAddr, serdesLane0EnableParams.numLanes, serdesLane0EnableParams.laneMask);

    /* Load the Serdes Config File */
    result = CSL_serdesEthernetInit(&serdesLane0EnableParams);
    /* Return error if input params are invalid */
    if (result != CSL_SERDES_NO_ERR)
    {
        return BOARD_FAIL;
    }

    /* Common Lane Enable API for lane enable, pll enable etc */
    laneRetVal = CSL_serdesLaneEnable(&serdesLane0EnableParams);
    if (laneRetVal != 0)
    {
        return BOARD_FAIL;
    }

    return BOARD_SOK;
}

/**
 *  \brief serdes configurations
 *
 *  The function configures the serdes1 module for one lane pcie interface
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_serdesCfgSgmii(void)
{
    Board_STATUS ret;

    /* SERDES0 Initializations */
    ret = Board_CfgSgmii();
    if(ret != BOARD_SOK)
    {
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief serdes configurations
 *
 *  The function configures the serdes1 module for one lane pcie interface
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_serdesCfgQsgmii(void)
{
    Board_STATUS ret;

    /* SERDES0 Initializations */
    ret = Board_CfgQsgmii();
    if(ret != BOARD_SOK)
    {
        return ret;
    }

    return BOARD_SOK;
}
