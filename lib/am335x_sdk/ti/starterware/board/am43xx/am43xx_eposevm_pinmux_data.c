/**
 *  \file  am43xx_eposevm_pinmux_data.c
 *
 * \brief  This file contains the pin mux configurations for the boards.
 *         These are prepared based on how the peripherals are extended on
 *         the boards.
 *
 * Note: Currently the entries in this file are hand-coded, but later this
 *       will be replaced with auto-generated file from pinmux tool.
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

#include <types.h>
#include "pinmux.h"
#include "am43xx_pinmux.h"

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** Peripheral Pin Configurations */

/* ########################################################################## */
/* ########################################################################## */
/* ########################################################################## */
/* BELOW DATA IS JUST REPRESENTATIVE - THEY MAY NOT MATCH WITH EVM CONFIG -   */
/*   UPDATE AS REQUIRED.                                                      */
/* ########################################################################## */
/* ########################################################################## */
/* ########################################################################## */

/* -------------------------------------------------------------------------- */
/*                           HSMMCSD                                          */
/* -------------------------------------------------------------------------- */
/* Peripheral Pin Configurations */
#if defined(BUILDCFG_MOD_MMCSD)
static pinmuxPerCfg_t gMmcsd0PinCfg[] =
{
   // /* Perform pin mux for MMC0 DATA3 pin. */
   // {
      // PIN_MMC0_DAT3, (PIN_MODE(0) | (PIN_PULL_UP_EN | PIN_RX_ACTIVE))
   // },
   // /* Perform pin mux for MMC0 DATA2 pin. */
   // {
      // PIN_MMC0_DAT2, (PIN_MODE(0) | (PIN_PULL_UP_EN | PIN_RX_ACTIVE))
   // },
   // /* Perform pin mux for MMC0 DATA1 pin. */
   // {
      // PIN_MMC0_DAT1, (PIN_MODE(0) | (PIN_PULL_UP_EN | PIN_RX_ACTIVE))
   // },
   // /* Perform pin mux for MMC0 DATA0 pin. */
   // {
      // PIN_MMC0_DAT0, (PIN_MODE(0) | (PIN_PULL_UP_EN | PIN_RX_ACTIVE))
   // },
   // /* Perform pin mux for MMC0 CLK pin. */
   // {
      // PIN_MMC0_CLK, (PIN_MODE(0) | (PIN_PULL_UP_EN | PIN_RX_ACTIVE))
   // },
   // /* Perform pin mux for MMC0 CMD pin. */
   // {
      // PIN_MMC0_CMD, (PIN_MODE(0) | (PIN_PULL_UP_EN | PIN_RX_ACTIVE))
   // },
   // /* Perform pin mux for MMC0 CD pin. */
   // {
      // PIN_SPI0_CS1, (PIN_MODE(5) | (PIN_PULL_UP_EN | PIN_RX_ACTIVE))
   // },
   {PINMUX_INVALID_PIN}
};

/* Module/IP Pin configurations */
static pinmuxModuleCfg_t gMmcsdPinCfg[] =
{
    {0, TRUE, gMmcsd0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};
#endif

/* -------------------------------------------------------------------------- */
/*                            Board pin config                                */
/* -------------------------------------------------------------------------- */
/** EVM pin configurations for EVM */
pinmuxBoardCfg_t gEposevmPinmuxData[] =
{
#if defined(BUILDCFG_MOD_MMCSD)
    {CHIPDB_MOD_ID_MMCSD, gMmcsdPinCfg},
#endif
    {CHIPDB_MOD_ID_INVALID}
};
