/******************************************************************************
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   tpr12_evm.c
 *
 *  \brief  TPR12 EVM Board library main file
 *
 *  Board library provides basic functions to initialize the interfaces
 *  on a given HW platform. It takes care of configuring and enabling different
 *  modules like PLL, clocks inside SoC and HW components on the board which are
 *  required to make sure board is ready for running the application software.
 *
 *  A common standard API Board_init() is exposed to the applications to invoke
 *  different board initialization routines. This function is common across the
 *  platforms maitaining the portability and can receive different input
 *  configuration flags based on the board capabilities allowing extendibility.
 *
 *  Board library shall eliminate the use of any additional configurations like
 *  GEL files to initialize the board except the cases like DDR initialization
 *  for loading the code into DDR before calling the Board init function.
 *  Give this limitation, applications invoking board library functions to
 *  initialize PLL, DDR and pinmux are supposed to run from SoC internal memory.
 *
 */

#include "board_internal.h"

Board_gblObj Board_obj = {NULL};

/**
 * \brief  Board library initialization function
 *
 *  Different board initialization routines are invoked by using configuration
 *  flags as described below
 *  BOARD_INIT_UNLOCK_MMR -
 *      Unlocks the MMR registers of the SoC. MMR registers should be
 *      enabled before any write access to MMR register address space.
 *
 *  BOARD_INIT_PLL -
 *      Configures different PLL controller modules. This enables all the PLL
 *      controllers on the SoC with default configurations. Any custom values
 *      required for PLL output needs to be done separately
 *
 *  BOARD_INIT_DDR -
 *      Initializes the DDR timing parameters. Sets the DDR timing parameters
 *      based in the DDR PLL controller configuration done by the board library.
 *      Any changes to DDR PLL requires change to DDR timing.
 *
 *  BOARD_INIT_PINMUX_CONFIG -
 *      Enables pinmux for the board interfaces. Pin mux is done based on the
 *      default/primary functionality of the board. Any pins shared by multiple
 *      interfaces need to be reconfigured to access the secondary functionality.
 *
 *  BOARD_INIT_UART_STDIO -
 *      Configures the UART module to use for serial console messages.
 *
 *  BOARD_INIT_MODULE_CLOCK -
 *      Enables different power domains and peripheral clocks of the SoC.
 *      Some of the power domains and peripherals will be off by default.
 *      Enabling the power domains is mandatory before accessing using
 *      board interfaces connected to those peripherals.
 *
 * \param   cfg [IN]    Board configuration flags
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS ret = BOARD_SOK;

    if (cfg & BOARD_INIT_UNLOCK_MMR)
        ret = Board_unlockMMR();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_MODULE_CLOCK)
        ret = Board_moduleClockInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_PINMUX_CONFIG)
        ret = Board_pinmuxConfig();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_PLL)
        ret = Board_PLLInitAll();
    if (ret != BOARD_SOK)
        return ret;

    return ret;
}

/**
 * \brief  Board library deinitialization function
 *
 *  BOARD_DEINIT_UART_STDIO -
 *      Deinitializes the UART module.
 *
 * \param   cfg [IN]    Board configuration flags
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_deinit(Board_initCfg cfg)
{
    Board_STATUS ret = BOARD_SOK;

    return ret;
}

