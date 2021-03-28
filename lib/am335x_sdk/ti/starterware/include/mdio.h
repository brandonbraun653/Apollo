/**
 *  \file     mdio.h
 *
 *  \brief    This file contains the dal API prototypes and macro definitions
 *            which interact with the MDIO hardware registers. This file
 *            provides APIs to initialise configure and use MDIO.
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 */
/*
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistribution of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistribution in binary form must reproduce the above copyright
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

 #ifndef MDIO_H_
 #define MDIO_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "hw_mdio.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros                                           */
/* ========================================================================== */
/*None*/
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/*None*/

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API reads a PHY register using MDIO.
 *
 * \param   baseAddr Base Address of the MDIO module.
 * \param   phyAddr  PHY Address.
 * \param   regNum   Register Number to be read.
 * \param   pData    Pointer where the read value shall be written.
 *
 * \retval  TRUE     Read is successful.
 * \retval  FALSE    Read is not acknowledged properly.
 */
void MDIOPhyRegRead(uint32_t baseAddr,
                    uint32_t phyAddr,
                    uint32_t regNum,
                    uint16_t *pData);

/**
 * \brief   This API writes a PHY register using MDIO.
 *
 * \param   baseAddr      Base Address of the MDIO module.
 * \param   phyAddr       PHY Address.
 * \param   regNum        Register Number to be written.
 * \param   wrVal         Value to be written.
 */
void MDIOPhyRegWrite(uint32_t baseAddr,
                     uint32_t phyAddr,
                     uint32_t regNum,
                     uint16_t wrVal);

/**
 * \brief   This API reads the alive status of all PHY connected to this MDIO.
 *          The bit corresponding to the PHY address will be set if the PHY
 *          is alive.
 *
 * \param   baseAddr Base Address of the MDIO module.
 * \param   phyAddr       PHY Address.
 *
 * \retval  TRUE   PHY is present.
 * \retval  FALSE  PHY is not present.
 */
uint32_t MDIOPhyAliveStatus(uint32_t baseAddr, uint32_t phyAddr);

/**
 * \brief   This API reads the link status of all PHY connected to this MDIO.
 *          The bit corresponding to the PHY address will be set if the PHY
 *          link is active.
 *
 * \param   baseAddr Base Address of the MDIO module.
 * \param   phyAddr  PHY Address.
 *
 * \retval  TRUE   PHY link is active.
 * \retval  FALSE  PHY link is inactive.
 */
uint32_t MDIOPhyLinkStatus(uint32_t baseAddr, uint32_t phyAddr);

/**
 * \brief   This API initializes the MDIO peripheral. This enables the MDIO state
 *          machine, uses standard pre-amble and set the clock divider value.
 *
 * \param   baseAddr       Base Address of the MDIO module.
 * \param   mdioInputFreq  The clock input to the MDIO module.
 * \param   mdioOutputFreq The clock output required on the MDIO bus.
 */
void MDIOInit(uint32_t baseAddr,
              uint32_t mdioInputFreq,
              uint32_t mdioOutputFreq);

/* ========================================================================== */
/*                        Deprecated Function Declarations                    */
/* ========================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MDIO_H_ */
