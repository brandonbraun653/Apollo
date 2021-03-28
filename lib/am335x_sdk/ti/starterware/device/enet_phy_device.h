/**
 *  \file  enet_phy_device.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the Ethernet PHY.
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

#ifndef ENET_PHY_DEVICE_H_
#define ENET_PHY_DEVICE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding the LCD panel configuration parameters. */
typedef struct enetPhyDeviceData
{
    uint32_t devId;
    /**< Ethernet PHY device ID. */
    uint32_t macType;
    /**< Ethernet PHY MAC type takes values #ethernetMacType_t. */
    uint32_t isGigCapab;
    /**< Ethernet PHY Gigabit capability. */
}enetPhyDeviceData_t;

/** \brief Structure holding the I2C register context .*/
typedef struct enetPhyDevConfig
{
    uint32_t devId;
    /**< Phy device ID. */
    uint32_t devInst;
    /**< Phy device instance. */
    uint32_t phyAddr;
    /**< Phy Address. */
    uint32_t macType;
    /**< Phy interface type. */
    uint32_t isGigCapab;
    /**< Phy gigabit capability. */
    uint32_t enableAutoNeg;
    /**< Phy gigabit capability. */
    uint32_t advertiseCapab;
    /**< Phy advertisement capability. */
    uint32_t linkPartCapab;
    /**< Link partner capability. */
    uint32_t speed;
    /**< Phy operating speed. */
    uint32_t duplexMode;
    /**< Phy operating duplexMode. */
}enetPhyDevConfig_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API returns the Ethernet PHY related data according to the PHY
 *        that is connected to the board.
 *
 * \param devId The device id of the Ethernet PHY device.
 *
 * \retval enet_phy_device_data Pointer to the Ethernet PHY device data.
 */
enetPhyDeviceData_t *ENETPhyGetDeviceData(uint32_t devId);

/**
 * \brief This API returns the list of Ethernet PHY devices available.
 *
 * \retval enet_phy_device_id_list Pointer to the Ethernet PHY devices list
 */
uint32_t * ENETPhyGetDeviceIdList(void);

/**
 * \brief AutoNegotiates with phy for link.
 *
 * \param  pPhyConfig The interface structure for PHY configuration.
 *
 * \retval S_PASS     Link set up is successful.
 * \retval E_FAIL     Link set up is not successful.
 */
int32_t ENETPhyDevAutoNegotiate(enetPhyDevConfig_t *pPhyConfig);

/**
 * \brief  Manually configure phy.
 *
 * \param  pPhyConfig The interface structure for PHY configuration.
 *
 * \retval S_PASS     Link set up is successful.
 * \retval E_FAIL     Link set up is not successful.
 */
int32_t ENETPhyDevForce(enetPhyDevConfig_t *pPhyConfig);

/**
 * \brief   Reads the PHY ID.
 *
 * \param   devId       PHY device ID.
 * \param   devInst     PHY device instance.
 *
 * \retval  32 bit PHY ID (ID1:ID2)
 */
uint32_t ENETPhyDevGetId(uint32_t devId,
                         uint32_t devInst);

/**
 * \brief   Enables Loop Back mode
 *
 * \param   devId          PHY device ID.
 * \param   devInst        PHY device instance.
 * \param   enableLoopBack Configure PHY loop back.
 *                         -# TRUE  - Enable PHY loop back.
 *                         -# FALSE - Disable PHY loop back.
 *
 * \retval S_PASS          Loop back configuration successful.
 * \retval E_FAIL          Loop back configuration failed.
 */
int32_t ENETPhyDevLoopBackEnable(uint32_t devId,
                                  uint32_t devInst,
                                  uint32_t enableLoopBack);

/**
 * \brief   Resets the PHY
 *
 * \param   devId       PHY device ID.
 * \param   devInst     PHY device instance.
 *
 * \retval S_PASS       Reset successful.
 * \retval E_FAIL       Reset failed.
 */
int32_t ENETPhyDevReset(uint32_t devId,
                         uint32_t devInst);

/**
 * \brief   Reads the link status of the PHY.
 *
 * \param   devId       PHY device ID.
 * \param   devInst     PHY device instance.
 * \param   retries  The number of retries before indicating link status.
 *
 * \retval  TRUE     Link is up.
 * \retval  FALSE    Link is down.
 *
 * \note    This reads both the basic status register of the PHY and the
 *          link register of MDIO for double check
 */
uint32_t ENETPhyDevLinkStatus(uint32_t devId,
                              uint32_t devInst,
                              uint32_t retries);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ENET_PHY_DEVICE_H_ */
