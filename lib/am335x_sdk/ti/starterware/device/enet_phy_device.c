/**
 * \file   enet_phy_device.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         Ethernet PHY.
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
#include "device.h"
#include "ethernet.h"
#include "cpsw.h"
#include "chipdb_defs.h"
#include "chipdb.h"
#include "board.h"
#include "enet_phy_device_types.h"
#include "enet_phy_device.h"
#include "console_utils.h"
#include "delay_utils.h"
#include "mdio.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Reads a register from the the PHY
 *
 * \param   devId       PHY device ID.
 * \param   devInst     PHY device instance.
 * \param   regAddr     Address of the register to be read.
 * \param   regVal      Value of the register will be read.
 *
 * \retval S_PASS       PHY register read successful.
 * \retval E_FAIL       PHY register read failed.
 */
int32_t ENETPhyDevReadReg(uint32_t devId,
                           uint32_t devInst,
                           uint32_t regAddr,
                           uint16_t *regVal);

/**
 * \brief   Writes a register with the input
 *
 * \param   devId    PHY device ID.
 * \param   devInst  PHY device instance.
 * \param   regAddr  Address of the register to be written.
 * \param   regVal   Value to be written.
 *
 * \retval S_PASS    PHY register write successful.
 * \retval E_FAIL    PHY register write failed.
 */
int32_t ENETPhyDevWriteReg(uint32_t devId,
                            uint32_t devInst,
                            uint32_t regAddr,
                            uint16_t regVal);

/**
 * \brief   Returns the status of Auto Negotiation completion.
 *
 * \param   devId       PHY device ID.
 * \param   devInst     PHY device instance.
 *
 * \retval  TRUE        Auto negotiation is completed
 * \retval  FALSE       Auto negotiation is not completed
 */
uint32_t ENETPhyDevAutoNegStatus(uint32_t devId,
                                 uint32_t devInst);

/**
 * \brief   Reads the Link Partner Ability register of the PHY.
 *
 * \param   devId       PHY device ID.
 * \param   devInst     PHY device instance.
 * \param   pPartnerAblty Autonegotiation partner ability.
 * \param   isGigCapab  Gigabit capability of the PHY.
 *                      -# TRUE - PHY is gigabit capable.
 *                      -# TRUE - PHY is non-gigabit capable.
 *
 * \retval  S_PASS      Link Partner Ability status read successful.
 * \retval  E_FAIL      Link Partner Ability status read failed.
 */
int32_t ENETPhyDevPartnerAbility(uint32_t devId,
                                  uint32_t devInst,
                                  uint32_t *pPartnerAblty,
                                  uint32_t isGigCapab);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Structure holding the supported Ethernet PHY device ids. */
uint32_t gEnetPhyDeviceIdList[] =
{
    DEVICE_ID_ENET_PHY_RGMII,
    /**< RGMII Ethernet PHY device. */
    DEVICE_ID_ENET_PHY_RMII,
    /**< RMII Ethernet PHY device. */
    DEVICE_ID_ENET_PHY_MII,
    /**< MII Ethernet PHY device. */
    DEVICE_ID_INVALID
    /**< Invalid device ID. */
};

/** \brief Structure holding the panel parameters of different Ethernet PHYs. */
enetPhyDeviceData_t gEnetPhyDeviceData[] =
{
    {
        /* RGMII Ethernet PHY device */
        DEVICE_ID_ENET_PHY_RGMII,            /* devId */
        ETHERNET_MAC_TYPE_RGMII,             /* macType */
        TRUE                                 /* isGigCapab */
    },
    {
        /* RMII Ethernet PHY device. */
        DEVICE_ID_ENET_PHY_RMII,             /* devId */
        ETHERNET_MAC_TYPE_RMII,               /* macType */
        FALSE                                /* isGigCapab */
    },
    {
        /* MII Ethernet PHY device. */
        DEVICE_ID_ENET_PHY_MII,             /* devId */
        ETHERNET_MAC_TYPE_MII,               /* macType */
        FALSE                                /* isGigCapab */
    }
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

enetPhyDeviceData_t *ENETPhyGetDeviceData(uint32_t devId)
{
    uint32_t numDev = sizeof(gEnetPhyDeviceData) / sizeof(enetPhyDeviceData_t);
    uint32_t devIndex = 0U;
    enetPhyDeviceData_t *enetPhyDeviceData = NULL;

    for (devIndex = 0U; devIndex < numDev; devIndex++)
    {
        if (devId == gEnetPhyDeviceData[devIndex].devId)
        {
            /* Device Found */
            enetPhyDeviceData = &gEnetPhyDeviceData[devIndex];
            break;
        }
    }
    return enetPhyDeviceData;
}

uint32_t * ENETPhyGetDeviceIdList(void)
{
    return gEnetPhyDeviceIdList;
}

int32_t ENETPhyDevAutoNegotiate(enetPhyDevConfig_t *pPhyConfig)
{
    uint32_t autoNegRetries = 200U;
    int32_t retVal = E_FAIL;
    uint16_t data = 0U;
    uint16_t dataBcr = 0U;

    if(NULL != pPhyConfig)
    {
        CONSOLEUtilsPrintf("\n\rPerforming Auto-Negotiation...");

        retVal = ENETPhyDevReadReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_BMC, &dataBcr);

        if(S_PASS == retVal)
        {
            HW_SET_FIELD(dataBcr, ENET_PHY_DEV_BMC_AUTONEG_ENABLE,
                ENET_PHY_DEV_BMC_AUTONEG_ENABLE);

            /* Set the configurations */
            retVal = ENETPhyDevWriteReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_BMC, dataBcr);
        }

        if(S_PASS == retVal)
        {
            if(S_PASS == ENETPhyDevReadReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_AUTO_NEG_ADV, &data))
            {
                retVal = S_PASS;

                if(0U != (pPhyConfig->advertiseCapab & ETHERNET_ADV_CAPAB_10_HALF))
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF,
                        ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF_CAPABLE);
                }
                else
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF,
                        ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF_NOT_CAPABLE);
                }

                if(0U != (pPhyConfig->advertiseCapab & ETHERNET_ADV_CAPAB_10_FULL))
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL,
                        ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL_CAPABLE);
                }
                else
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL,
                        ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL_NOT_CAPABLE);
                }

                if(0U != (pPhyConfig->advertiseCapab & ETHERNET_ADV_CAPAB_100_HALF))
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF,
                        ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF_CAPABLE);
                }
                else
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF,
                        ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF_NOT_CAPABLE);
                }

                if(0U != (pPhyConfig->advertiseCapab & ETHERNET_ADV_CAPAB_100_FULL))
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL,
                        ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL_CAPABLE);
                }
                else
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL,
                        ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL_NOT_CAPABLE);
                }

                /* Set the configurations */
                retVal = ENETPhyDevWriteReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_AUTO_NEG_ADV, data);
            }
        }

        if(S_PASS == retVal)
        {
            if(TRUE == pPhyConfig->isGigCapab)
            {
                if(S_PASS == ENETPhyDevReadReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_GIG_CTRL, &data))
                {
                    retVal = S_PASS;

                    if(0U != (pPhyConfig->advertiseCapab & ETHERNET_ADV_CAPAB_1000_HALF))
                    {
                        HW_SET_FIELD(data, ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF,
                            ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF_CAPABLE);
                    }
                    else
                    {
                        HW_SET_FIELD(data, ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF,
                            ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF_NOT_CAPABLE);
                    }

                    if(0U != (pPhyConfig->advertiseCapab & ETHERNET_ADV_CAPAB_1000_FULL))
                    {
                        HW_SET_FIELD(data, ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL,
                            ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL_CAPABLE);
                    }
                    else
                    {
                        HW_SET_FIELD(data, ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL,
                            ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL_NOT_CAPABLE);
                    }

                    /* Set the configurations */
                    retVal = ENETPhyDevWriteReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_GIG_CTRL, data);
                }
            }
        }

        if(S_PASS == retVal)
        {
            if(S_PASS == ENETPhyDevReadReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_BMC, &data))
            {
                HW_SET_FIELD(data, ENET_PHY_DEV_BMC_RESTART_AUTONEG,
                    ENET_PHY_DEV_BMC_RESTART_AUTONEG_ENABLE);

                /* Set the configurations */
                retVal = ENETPhyDevWriteReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_BMC, data);
            }
        }
    }

    if(S_PASS == retVal)
    {
        while (0U != autoNegRetries)
        {
            delay(50U);

            if (TRUE == ENETPhyDevAutoNegStatus(pPhyConfig->devId, pPhyConfig->devInst))
            {
                break;
            }
            autoNegRetries--;
        }

        if (0U != autoNegRetries)
        {
            CONSOLEUtilsPrintf("\n\rAuto-Negotiation Successful.");

            retVal = ENETPhyDevPartnerAbility(pPhyConfig->devId, pPhyConfig->devInst,
                &(pPhyConfig->linkPartCapab), pPhyConfig->isGigCapab);

            if(S_PASS == retVal)
            {
                if(0U != (pPhyConfig->advertiseCapab & pPhyConfig->linkPartCapab & ETHERNET_ADV_CAPAB_1000_FULL))
                {
                    CONSOLEUtilsPrintf("\n\rTransfer Mode : 1000 Mbps Full Duplex.");
                    pPhyConfig->speed = ETHERNET_SPEED_1000;
                    pPhyConfig->duplexMode = ETHERNET_DUPLEX_MODE_FULL;
                }
                else if(0U != (pPhyConfig->advertiseCapab & pPhyConfig->linkPartCapab & ETHERNET_ADV_CAPAB_1000_HALF))
                {
                    CONSOLEUtilsPrintf("\n\rTransfer Mode : 1000 Mbps HALF Duplex.");
                    pPhyConfig->speed = ETHERNET_SPEED_1000;
                    pPhyConfig->duplexMode = ETHERNET_DUPLEX_MODE_HALF;
                }
                else if(0U != (pPhyConfig->advertiseCapab & pPhyConfig->linkPartCapab & ETHERNET_ADV_CAPAB_100_FULL))
                {
                    CONSOLEUtilsPrintf("\n\rTransfer Mode : 100 Mbps Full Duplex.");
                    pPhyConfig->speed = ETHERNET_SPEED_100;
                    pPhyConfig->duplexMode = ETHERNET_DUPLEX_MODE_FULL;
                }
                else if(0U != (pPhyConfig->advertiseCapab & pPhyConfig->linkPartCapab & ETHERNET_ADV_CAPAB_100_HALF))
                {
                    CONSOLEUtilsPrintf("\n\rTransfer Mode : 100 Mbps Half Duplex.");
                    pPhyConfig->speed = ETHERNET_SPEED_100;
                    pPhyConfig->duplexMode = ETHERNET_DUPLEX_MODE_HALF;
                }
                else if(0U != (pPhyConfig->advertiseCapab & pPhyConfig->linkPartCapab & ETHERNET_ADV_CAPAB_10_FULL))
                {
                    CONSOLEUtilsPrintf("\n\rTransfer Mode : 10 Mbps Full Duplex.");
                    pPhyConfig->speed = ETHERNET_SPEED_10;
                    pPhyConfig->duplexMode = ETHERNET_DUPLEX_MODE_FULL;
                }
                else if(0U != (pPhyConfig->advertiseCapab & pPhyConfig->linkPartCapab & ETHERNET_ADV_CAPAB_10_HALF))
                {
                    CONSOLEUtilsPrintf("\n\rTransfer Mode : 10 Mbps Half Duplex.");
                    pPhyConfig->speed = ETHERNET_SPEED_10;
                    pPhyConfig->duplexMode = ETHERNET_DUPLEX_MODE_HALF;
                }
                else
                {
                }
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\n\rAuto-Negotiation Not Successful.");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\nAuto-Negotiation configuration failed.");
    }

    return retVal;
}

int32_t ENETPhyDevForce(enetPhyDevConfig_t *pPhyConfig)
{
    uint32_t forceRetries = 200U;
    volatile uint32_t forceStatus = FALSE;
    uint16_t data = 0U;
    int32_t retVal = E_FAIL;

    if(NULL != pPhyConfig)
    {
        retVal = ENETPhyDevReset(pPhyConfig->devId, pPhyConfig->devInst);

        if (S_PASS == retVal)
        {
            while (0U != forceRetries)
            {
                delay(50U);

                /* Check if PHY link is there or not */
                if (FALSE == ENETPhyDevLinkStatus(pPhyConfig->devId, pPhyConfig->devInst, 1000U))
                {
                    CONSOLEUtilsPrintf("\n\rPHY Link is Down.");
                    break;
                }

                forceRetries--;
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\n\rPHY Reset Failed...");
        }

        if(S_PASS == retVal)
        {
            forceRetries = 200U;
            forceStatus = FALSE;
            CONSOLEUtilsPrintf("\n\rPerforming Manual Configuration...");

            retVal = ENETPhyDevReadReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_BMC, &data);

            if(S_PASS == retVal)
            {
                if(ETHERNET_DUPLEX_MODE_FULL == pPhyConfig->duplexMode)
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_BMC_DUPLEX_MODE,
                        ENET_PHY_DEV_BMC_DUPLEX_MODE_FULL);
                }
                else if(ETHERNET_DUPLEX_MODE_HALF == pPhyConfig->duplexMode)
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_BMC_DUPLEX_MODE,
                        ENET_PHY_DEV_BMC_DUPLEX_MODE_HALF);
                }

                if(ETHERNET_SPEED_10 == pPhyConfig->speed)
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_BMC_SPEED, ENET_PHY_DEV_BMC_SPEED_10);
                }
                else if(ETHERNET_SPEED_100 == pPhyConfig->speed)
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_BMC_SPEED, ENET_PHY_DEV_BMC_SPEED_100);
                }
                else if(ETHERNET_SPEED_1000 == pPhyConfig->speed)
                {
                    HW_SET_FIELD(data, ENET_PHY_DEV_BMC_SPEED, ENET_PHY_DEV_BMC_SPEED_1000);
                }
                else
                {
                }

                /* Set the configurations */
                retVal = ENETPhyDevWriteReg(pPhyConfig->devId, pPhyConfig->devInst, ENET_PHY_DEV_BMC, data);
            }

            if (S_PASS == retVal)
            {
                while (0U != forceRetries)
                {
                    delay(50U);

                    /* Check if PHY link is there or not */
                    forceStatus = ENETPhyDevLinkStatus(pPhyConfig->devId, pPhyConfig->devInst, 1000U);
                    if (TRUE == forceStatus)
                    {
                        break;
                    }

                    forceRetries--;
                }

                if (0U != forceRetries)
                {
                    retVal = S_PASS;
                    CONSOLEUtilsPrintf("\n\rPhy Configuration Successful.");
                    CONSOLEUtilsPrintf("\n\rPHY link verified for Port %d.",
                        pPhyConfig->phyAddr);

                    if (ETHERNET_SPEED_1000 == pPhyConfig->speed)
                    {
                        CONSOLEUtilsPrintf("\n\rTransfer Mode : 1000 Mbps.");
                    }
                    else
                    {
                        if (ETHERNET_SPEED_10 == pPhyConfig->speed)
                        {
                            CONSOLEUtilsPrintf("\n\rTransfer Mode : 10 Mbps ");
                        }
                        else
                        {
                            CONSOLEUtilsPrintf("\n\rTransfer Mode : 100 Mbps ");
                        }

                        if (ETHERNET_DUPLEX_MODE_FULL == pPhyConfig->duplexMode)
                        {
                            CONSOLEUtilsPrintf("Full Duplex.");
                        }
                        else
                        {
                            CONSOLEUtilsPrintf("Half Duplex.");
                        }
                    }
                }
                else
                {
                    CONSOLEUtilsPrintf("\nPhy Configuration not Successful.");
                    CONSOLEUtilsPrintf("\nPHY link connectivity failed for Port %d.",
                        pPhyConfig->phyAddr);
                    retVal = E_FAIL;
                }
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\nPhy Configuration Not Successful.");
            CONSOLEUtilsPrintf("\nPHY link connectivity failed for Port %d.", pPhyConfig->phyAddr);
        }
    }

  return retVal;
}

uint32_t ENETPhyDevGetId(uint32_t devId,
                         uint32_t devInst)
{
    uint32_t id = 0U;
    uint16_t data;

    /* read the ID1 register */
    ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_ID1, &data);

    /* update the ID1 value */
    id = data << 16U;

    /* read the ID2 register */
    ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_ID2, &data);

    /* update the ID2 value */
    id |= data;

    /* return the ID in ID1:ID2 format */
    return id;
}

int32_t ENETPhyDevLoopBackEnable(uint32_t devId,
                                  uint32_t devInst,
                                  uint32_t enableLoopBack)
{
    uint16_t data = 0U;
    int32_t retVal = E_FAIL;

    if(S_PASS == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_BMC, &data))
    {
        retVal = S_PASS;

        if(TRUE == enableLoopBack)
        {
            HW_SET_FIELD(data, ENET_PHY_DEV_BMC_LOOPBACK, ENET_PHY_DEV_BMC_LOOPBACK_ENABLE);
        }
        else
        {
            HW_SET_FIELD(data, ENET_PHY_DEV_BMC_LOOPBACK, ENET_PHY_DEV_BMC_LOOPBACK_DISABLE);
        }

        retVal = ENETPhyDevWriteReg(devId, devInst, ENET_PHY_DEV_BMC, data);
    }

    return retVal;
}

int32_t ENETPhyDevReset(uint32_t devId,
                         uint32_t devInst)
{
    uint16_t data = 0U;
    int32_t retVal = E_FAIL;

    if(S_PASS == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_BMC, &data))
    {
        retVal = S_PASS;

        HW_SET_FIELD(data, ENET_PHY_DEV_BMC_RESET, ENET_PHY_DEV_BMC_RESET_ENABLE);

        /* Reset the PHY. */
        retVal = ENETPhyDevWriteReg(devId, devInst, ENET_PHY_DEV_BMC, data);
    }

    if(S_PASS == retVal &&
		(S_PASS == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_BMC, &data)))
    {
        /* wait till the reset bit is auto cleared. */
        while(ENET_PHY_DEV_BMC_RESET_ENABLE == HW_GET_FIELD(data, ENET_PHY_DEV_BMC_RESET))
        {
            if(E_FAIL == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_BMC, &data))
            {
                retVal = E_FAIL;
                break;
            }
        }
    }

    return retVal;
}

uint32_t ENETPhyDevLinkStatus(uint32_t devId,
                              uint32_t devInst,
                              uint32_t retries)
{
    uint16_t data = 0U;
    volatile uint32_t cnt = retries;
    uint32_t retVal = FALSE;

    while (0U != cnt)
    {
        /* First read the BSR of the PHY */
        if(S_PASS == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_BMS, &data))
        {
            if(ENET_PHY_DEV_BMS_LINKS_STS_UP ==
                HW_GET_FIELD(data, ENET_PHY_DEV_BMS_LINKS_STS))
            {
                retVal = TRUE;
                break;
            }
        }

        cnt--;
    }

    return retVal;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

int32_t ENETPhyDevReadReg(uint32_t devId,
                           uint32_t devInst,
                           uint32_t regAddr,
                           uint16_t *regVal)
{
    int32_t retVal = E_FAIL;
    uint32_t instNum = 0U;
    uint32_t modId = 0U;
    uint32_t phyAddr = 0U;
    uint32_t baseAddr = 0U;

    if(NULL != regVal)
    {
        modId = BOARDGetDeviceCtrlModId(devId, devInst);
    }

    if(CHIPDB_MOD_ID_INVALID != modId)
    {
        switch(modId)
        {
            case CHIPDB_MOD_ID_CPSW:
            {
                instNum = BOARDGetDeviceCtrlModInstNum(devId, devInst);
                phyAddr = BOARDGetDeviceDataModId(devId, devInst);

                if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_CPSW, instNum))
                {
                    baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_CPSW, instNum);
                }

                retVal = S_PASS;
                CPSWMdioPhyRegRead(baseAddr, phyAddr, regAddr, regVal);
            }
            break;
	    case CHIPDB_MOD_ID_ICSS_MDIO:
            {
                instNum = BOARDGetDeviceCtrlModInstNum(devId, devInst);
                phyAddr = BOARDGetDeviceDataModId(devId, devInst);

                if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_ICSS_MDIO, instNum))
                {
                    baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_ICSS_MDIO, instNum);
                }

                retVal = S_PASS;
                MDIOPhyRegRead(baseAddr, phyAddr, regAddr, regVal);
            }
            break;
            default:
            break;
        }
    }

    return retVal;
}

int32_t ENETPhyDevWriteReg(uint32_t devId,
                            uint32_t devInst,
                            uint32_t regAddr,
                            uint16_t regVal)
{
    int32_t retVal = E_FAIL;
    uint32_t instNum = 0U;
    uint32_t modId = 0U;
    uint32_t phyAddr = 0U;
    uint32_t baseAddr = 0U;

    modId = BOARDGetDeviceCtrlModId(devId, devInst);

    if(CHIPDB_MOD_ID_INVALID != modId)
    {
        switch(modId)
        {
            case CHIPDB_MOD_ID_CPSW:
            {
                instNum = BOARDGetDeviceCtrlModInstNum(devId, devInst);
                phyAddr = BOARDGetDeviceDataModId(devId, devInst);

                if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_CPSW, instNum))
                {
                    baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_CPSW, instNum);
                }

                retVal = S_PASS;
                CPSWMdioPhyRegWrite(baseAddr, phyAddr, regAddr, regVal);
            }
            break;
	   case CHIPDB_MOD_ID_ICSS_MDIO:
           {
               instNum = BOARDGetDeviceCtrlModInstNum(devId, devInst);
               phyAddr = BOARDGetDeviceDataModId(devId, devInst);

               if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_ICSS_MDIO, instNum))
               {
                   baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_ICSS_MDIO, instNum);
               }

               retVal = S_PASS;
               MDIOPhyRegWrite(baseAddr, phyAddr, regAddr, regVal);
           }
           break;

            default:
            break;
        }
    }

    return retVal;
}

uint32_t ENETPhyDevAutoNegStatus(uint32_t devId,
                                 uint32_t devInst)
{
    uint16_t data = 0U;
    uint32_t retVal = FALSE;

    if(S_PASS == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_BMS, &data))
    {
        /* Auto negotiation completion status */
        if(ENET_PHY_DEV_BMS_AUTONEG_PROCESS_COMPLETE ==
            HW_GET_FIELD(data, ENET_PHY_DEV_BMS_AUTONEG_PROCESS))
        {
            retVal = TRUE;
        }
    }

    return retVal;
}

int32_t ENETPhyDevPartnerAbility(uint32_t devId,
                                  uint32_t devInst,
                                  uint32_t *pPartnerAblty,
                                  uint32_t isGigCapab)
{
    uint16_t data = 0U;
    int32_t retVal = E_FAIL;

    *pPartnerAblty = 0U;

    if(S_PASS == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY, &data))
    {
        retVal = S_PASS;

        if(ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_HALF_CAPABLE ==
            HW_GET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_HALF))
        {
            *pPartnerAblty |= ETHERNET_ADV_CAPAB_10_HALF;
        }

        if(ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_FULL_CAPABLE ==
            HW_GET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_FULL))
        {
            *pPartnerAblty |= ETHERNET_ADV_CAPAB_10_FULL;
        }

        if(ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_HALF_CAPABLE ==
            HW_GET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_HALF))
        {
            *pPartnerAblty |= ETHERNET_ADV_CAPAB_100_HALF;
        }

        if(ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_FULL_CAPABLE ==
            HW_GET_FIELD(data, ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_FULL))
        {
            *pPartnerAblty |= ETHERNET_ADV_CAPAB_100_FULL;
        }
    }

    if((S_PASS == retVal) && (TRUE == isGigCapab))
    {
        if(S_PASS == ENETPhyDevReadReg(devId, devInst, ENET_PHY_DEV_GIG_STS, &data))
        {
            retVal = S_PASS;

            if(ENET_PHY_DEV_GIG_STS_LINK_1000_HALF_CAPABLE ==
                HW_GET_FIELD(data, ENET_PHY_DEV_GIG_STS_LINK_1000_HALF))
            {
                *pPartnerAblty |= ETHERNET_ADV_CAPAB_1000_HALF;
            }

            if(ENET_PHY_DEV_GIG_STS_LINK_1000_FULL_CAPABLE ==
                HW_GET_FIELD(data, ENET_PHY_DEV_GIG_STS_LINK_1000_FULL))
            {
                *pPartnerAblty |= ETHERNET_ADV_CAPAB_1000_FULL;
            }
        }
    }

    return retVal;
}
