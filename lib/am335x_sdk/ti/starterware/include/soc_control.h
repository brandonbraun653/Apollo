/**
 * \file   soc_control.h
 *
 * \brief  This file contains prototype declarations of functions which
 *         performs SoC specific configurations.
 */

/*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef SOC_CONTROL_H_
#define SOC_CONTROL_H_

/* ========================================================================== */
/*                           include files                                    */
/* ========================================================================== */

#include "types.h"
#include "misc.h"
#include "error.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief L2 SRAM memory size */
#define L2_SRAM_MEM_SIZE              (256U * MEM_SIZE_KB)
/** \brief Configure L2 as cache */
#define L2_CONFIG_AS_CACHE            (0U)
/** \brief Configure L2 as SRAM */
#define L2_CONFIG_AS_SRAM             (1U)

/** \brief enum holding Type of Clock Source */
typedef enum socCtrlDmtimerClkSrc
{
    SOC_CTRL_DMTIMER_CLK_SRC_TCLKIN =  0x0U,
    /**< Timer Clock Input from External Pin  */
    SOC_CTRL_DMTIMER_CLK_SRC_M_OSC_24M = 0x1U,
    /**< 24MHz Master Oscillator */
    SOC_CTRL_DMTIMER_CLK_SRC_32K = 0x2U,
    /**< 32KHz Clock Source */
    SOC_CTRL_DMTIMER_CLK_SRC_RESERVED = 0x3U,
    /**< Reserved */
    SOC_CTRL_DMTIMER_CLK_SRC_MAX = SOC_CTRL_DMTIMER_CLK_SRC_RESERVED,
    /**< Max Operational clock input */
}socCtrlDmtimerClkSrc_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API enables the selection of clock source for all the instances
 *          of DMTimer.
 *
 * \param   instance     DMTimer instance for which clock source to be provided.
 * \param   timerClkSrc  Clock Source Type to the DMTimer instance
 **/
void SOCCtrlTimerClkSrcSelect(uint32_t instance, uint32_t timerClkSrc);

/**
 * \brief   This API configures L2 as cache or SRAM memory (which is memory
 *          mapped).Also this API has to be called only during initialization
 *          and runtime change is not allowed. By default when the device resets
 *          it will be set as cache. The size of L2 SRAM in am43xx is 256KB.
 *
 * \param   l2SramFlag  Flag indicating whether L2 is configured as SRAM or 
 *                      cache. Possible values are,
 *                          #L2_CONFIG_AS_CACHE
 *                          #L2_CONFIG_AS_SRAM
 *
 * \retval  S_PASS           Configures as indicated by l2SramFlag.
 * \retval  E_INVALID_PARAM  Parameter passed is invalid.
 **/
int32_t SOCL2SramConfig(uint32_t l2SramFlag);

/**
 * \brief   This API enables the Time base clock of the ePWM sub-module which
 *          is present inside the PWM sub system.
 *
 * \param   instance  PWM sub system instance for which time base clock has to
 *                    be enabled.
 */
void SOCCtrlPwmssTimebaseClkEnable(uint32_t instance);

/**
 * \brief   This API selects the source of clock from which lcdc pixel clock
 *          will be derived. This selects the PER PLL CLKOUTM2 as source.
 */
void SOCCtrlLcdcPixelClkSelect(void);
 
/**
 * \brief   This API enables the DCAN message RAM.
 *
 * \param   instance  DCAN instance number for which the message RAM
 *                    has to be enabled.
 */
void SOCDcanMessageRamInit(uint32_t instance);

/**
 * \brief   This API configures the MAC mode of Ethernet port.
 *
 * \param   portNum  Port number.
 * \param   macMode  Mac mode to be configured takes #ethernetMacType_t.
 */
void SOCCtrlCpswPortMacModeSelect(uint32_t portNum, uint32_t macMode);

/**
 * \brief   This API reads the Ethernet MAC address.
 *
 * \param   portNum  Port number.
 * \param   pMacAddr Ethernet Address
 */
void SOCCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr);

#ifdef  __cplusplus
}
#endif /* ifdef  __cplusplus */
#endif /* ifndef SOC_CONTROL_H_ */
