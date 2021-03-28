/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   board_devices.h
 *
 * \brief  Top level header file for board devices.
 *
 */

#ifndef _BOARD_DEVICES_H_
#define _BOARD_DEVICES_H_

/**
 *
 *  \ingroup BOARD_LIB_MODULE
 *
 *  \defgroup BOARD_LIB_DEVICES Board Device Library
 *
 *  Board library for various board specific devices on TI EVM.
 *
 *  @{
 *
 */
/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD FPD-Link Device Library
 *
 *  Board library for FPD-Link devices on TI EVM.
 *
 *  @{
 *
 */
/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES
 *
 *  \defgroup BOARD_LIB_DEVICES_SENSOR Sensor Device Library
 *
 *  Board library for sensor devices supported/evaluated on TI EVM.
 *
 *  @{
 *
 */
/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES
 *
 *  \defgroup BOARD_LIB_DEVICES_AUDIO Audio Device Library
 *
 *  Board library for audio devices on TI EVM.
 *
 *  @{
 *
 */
/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES
 *
 *  \defgroup BOARD_LIB_DEVICES_POWER Power Management Device Library
 *
 *  Board library for Power Management devices on TI EVM.
 *
 *  @{
 *
 */
/* @} */

#if defined(j721e_evm)
#include <ti/board/src/devices/common/common.h>

#include <ti/board/src/devices/fpd/ds90ub924.h>
#include <ti/board/src/devices/fpd/ds90ub953.h>
#include <ti/board/src/devices/fpd/ds90ub960.h>
#include <ti/board/src/devices/fpd/ds90ub941.h>
#include <ti/board/src/devices/fpd/ds90ub925.h>
#include <ti/board/src/devices/fpd/ds90ub926.h>
#include <ti/board/src/devices/fpd/ds90ub9702.h>

#include <ti/board/src/devices/sensors/imx390.h>
#include <ti/board/src/devices/sensors/tlc59108.h>

#include <ti/board/src/devices/combos/ds90ub9xx_tlc59108.h>
#include <ti/board/src/devices/combos/ds90ub92x_afe8310.h>

#include <ti/board/src/devices/audio/pcm3168A.h>
#include <ti/board/src/devices/audio/afe8310.h>

#include <ti/board/src/devices/pmic/tps65941.h>
#endif

#if defined(am65xx_evm) || defined(am65xx_idk)
#include <ti/board/src/devices/pmic/tps62363.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOARD_DEVICES_H_ */

/* @} */
