/**
 *  \file   board_phy.c
 *
 *  \brief  AM437x IDK Board specific phy parameters.
 *
 *   This file contains the phy hardware parameters specific to board.
 */

/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <xdc/std.h>
#include <examples/board/include/board_phy.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/csl/soc.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_cfg.h>
#include <ti/csl/csl_gpio.h>

#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <examples/board/include/board_misc.h>

#define AM437X_ICSS1_PORT1_PHY_ADDR 0
#define AM437X_ICSS1_PORT2_PHY_ADDR 1

int8_t Board_getPhyAddress(uint8_t instance, uint8_t portNumber)
{
    if(PRUICSS2_PHY_ADDRESS == instance)
    {
        if(1u == portNumber)
        {
            return AM437X_ICSS1_PORT1_PHY_ADDR;
        }

        else if(2u == portNumber)
        {
            return AM437X_ICSS1_PORT2_PHY_ADDR;
        }
    }

    return -1;
}


typedef struct GPIO_INFO
{
    uint32_t pin;
    uint32_t baseAddr;

} GPIO_INFO;

GPIO_INFO PhyResetInfo[2];


void Board_phyManualReset(uint8_t numPorts)
{

    GPIOModuleEnable(PhyResetInfo[0].baseAddr);
    GPIODirModeSet(PhyResetInfo[0].baseAddr, PhyResetInfo[0].pin, GPIO_DIR_OUTPUT);

    GPIOPinWrite(PhyResetInfo[0].baseAddr, PhyResetInfo[0].pin, GPIO_PIN_LOW);
    Board_delay(1000);

    GPIOPinWrite(PhyResetInfo[0].baseAddr, PhyResetInfo[0].pin, GPIO_PIN_HIGH);
    Board_delay(100000);

}


/* ========================================================================== */
/*                          Function Definitions                             */
/* ========================================================================== */

int32_t Board_phyGPIOsetup(uint8_t numPorts)
{
    if((numPorts != 4) && (numPorts != 2))
    {
        return -1;
    }

    /*PRUETH0_RESETn */
    PhyResetInfo[0].pin = 20;
    PhyResetInfo[0].baseAddr = SOC_GPIO4_REG;

    return (0);
}

int32_t Board_phyReset(uint8_t numPorts)
{
    int32_t retval = 0;
    /*Configure the GPIO pins */
    retval = Board_phyGPIOsetup(numPorts);
    /*Reset the phys */
    Board_phyManualReset(numPorts);
    return retval;
}
