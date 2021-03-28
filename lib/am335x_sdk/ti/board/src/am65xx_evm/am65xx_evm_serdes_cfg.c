/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   am65xx_evm_serdes_cfg.c
 *
 *  \brief  EVM serdes configuration file
 *
 *  Configures the serdes module for one lane pcie and USB3.0 Interfaces.
 *
 */

#include "board_serdes_cfg.h"

/**
 *  \brief PCIe and USB3.0 serdes configurations  
 *
 *  The function configures the serdes module for one lane pcie and USB3.0
 *  interface
 *
 * \return   BOARD_SOK in case of success or appropriate error code
 *
 */
static Board_STATUS Board_OnelanePCIeUSBSerdesCfg(void)
{
    uint32_t index;
    CSL_SerdesResult result;
    CSL_SerdesLaneEnableStatus status = CSL_SERDES_LANE_ENABLE_NO_ERR;
    CSL_SerdesLaneEnableParams serdesLane0EnableParams  = {0},
                               serdesLane1EnableParams  = {0};

    /* Selects the SERDES0 lane function to configure USB3.0 */
    CSL_FINSR(*(volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES0_CTRL), 1, 0, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES0_CTRL), 7, 4, 0x4);
    CSL_FINSR(*(volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES0_REFCLK_SEL), 1, 0, 0x3);

    /* Selects the SERDES1 lane function to configure PCIe1 Lane0 */
    CSL_FINSR(*(volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES1_CTRL), 1, 0, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES1_CTRL), 7, 4, 0x0);
    CSL_FINSR(*(volatile uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_SERDES1_REFCLK_SEL), 1, 0, 0x3);


    /* Configuring USB3.0 */
    serdesLane0EnableParams.baseAddr           = CSL_SERDES0_BASE;
    serdesLane0EnableParams.numLanes           = 1;
    serdesLane0EnableParams.laneMask           = 0x01;
    serdesLane0EnableParams.peripheralBaseAddr = 0;
    serdesLane0EnableParams.refClock           = CSL_SERDES_REF_CLOCK_100M;
    serdesLane0EnableParams.linkRate           = CSL_SERDES_LINK_RATE_5G ;
    serdesLane0EnableParams.phyType            = CSL_SERDES_PHY_TYPE_USB ;
    serdesLane0EnableParams.operatingMode      = CSL_SERDES_FUNCTIONAL_MODE;
    serdesLane0EnableParams.iterationMode      = CSL_SERDES_LANE_ENABLE_COMMON_INIT;

    for(index = 0; index < serdesLane0EnableParams.numLanes; index++)
    {
        serdesLane0EnableParams.loopbackMode[index]   = CSL_SERDES_LOOPBACK_DISABLED;
        serdesLane0EnableParams.laneCtrlRate[index]   = CSL_SERDES_LANE_FULL_RATE; 
    }

    /* Configuring PCIe1 Lane0 */ 
    serdesLane1EnableParams.baseAddr           = CSL_SERDES1_BASE;
    serdesLane1EnableParams.numLanes           = 1;
    serdesLane1EnableParams.laneMask           = 0x01;
    serdesLane1EnableParams.peripheralBaseAddr = 0;
    serdesLane1EnableParams.refClock           = CSL_SERDES_REF_CLOCK_100M;
    serdesLane1EnableParams.linkRate           = CSL_SERDES_LINK_RATE_8G ;
    serdesLane1EnableParams.phyType            = CSL_SERDES_PHY_TYPE_PCIe ;
    serdesLane1EnableParams.operatingMode      = CSL_SERDES_FUNCTIONAL_MODE;
    serdesLane1EnableParams.iterationMode      = CSL_SERDES_LANE_ENABLE_COMMON_INIT;

    for(index = 0; index < serdesLane1EnableParams.numLanes; index++)
    {
        serdesLane1EnableParams.loopbackMode[index]   = CSL_SERDES_LOOPBACK_DISABLED;
        serdesLane1EnableParams.laneCtrlRate[index]   = CSL_SERDES_LANE_FULL_RATE; 
    }

    /* PUT SERDES PHY OUT OF RESET */
    CSL_serdesPorReset(serdesLane0EnableParams.baseAddr);

    CSL_serdesPorReset(serdesLane1EnableParams.baseAddr);

    /* USB3.0 initializations */
    result = CSL_serdesUSBInit(serdesLane0EnableParams.baseAddr,
                               serdesLane0EnableParams.numLanes,
                               serdesLane0EnableParams.refClock,
                               serdesLane0EnableParams.linkRate);
    if (result != CSL_SERDES_NO_ERR)
    {
        return BOARD_FAIL;
    }

    status = CSL_serdesLaneEnable(&serdesLane0EnableParams);
    if(status != CSL_SERDES_LANE_ENABLE_NO_ERR)
    {
        return BOARD_FAIL;
    }
    

    /* PCIe initialization */
    result = CSL_serdesPCIeInit(serdesLane1EnableParams.baseAddr,
                                serdesLane1EnableParams.numLanes,
                                serdesLane1EnableParams.refClock,
                                serdesLane1EnableParams.linkRate);
    if (result != CSL_SERDES_NO_ERR)
    {
        return BOARD_FAIL;
    }

    status = CSL_serdesLaneEnable(&serdesLane1EnableParams);
    if(status != CSL_SERDES_LANE_ENABLE_NO_ERR)
    {
        return BOARD_FAIL;
    }

    return BOARD_SOK;
}

/**
 *  \brief serdes configurations
 *
 *  This function detects the personality boards connected and configures the
 *  respective module.
 *
 *  \return BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_serdesCfg(void)
{    
    Board_STATUS ret;

/* Enable this code after programming EEPROM IDs for the personality cards */
#ifdef ENABLE_BOARD_DETECT
    Board_IDInfo boardInfo;
    uint8_t isBoardDetected = 0;

    /* Detecting the serdes board */
    if(Board_detectBoard(SERDES_BRD_DETECT))
    {
        /* Get the serdes board information to configure */
        ret = Board_getIDInfo(&boardInfo);
        if(ret == BOARD_SOK)
        {
            if(strcmp(boardInfo.boardName, SERDES_USB_PCIE) == 0)
            {
                ret = Board_OnelanePCIeUSBSerdesCfg();
            }
            else
            {
                ret = BOARD_FAIL;
            }
        }
    }
#else
    ret = Board_OnelanePCIeUSBSerdesCfg();
#endif

    return ret;
}
