/*
 * Copyright (c) 2016-2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file  nor_spi.h
 *
 * \brief This file contains structure, typedefs, functions and
 *        prototypes used for SPI interface for NOR flash.
 *
 *****************************************************************************/
#ifndef NOR_SPI_H_
#define NOR_SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

#include <ti/board/src/flash/nor/nor.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>

#if defined (evmK2H) || defined (evmK2K) || defined (evmK2L) || defined (evmK2E) || defined (evmK2G) || defined (iceK2G) || defined (evmC6657) || defined (evmC6678) || defined (evmOMAPL137) || defined (am65xx_evm) || defined (am65xx_idk)  || defined(j721e_sim) || defined(j721e_evm) || defined(j7200_evm)
#if defined (evmK2G) || defined (iceK2G) || defined (am65xx_evm) || defined (am65xx_idk)  || defined(j721e_sim) || defined(j721e_evm) || defined(j7200_evm)
#include <ti/board/src/flash/nor/device/n25q128a13esf40f.h>
#elif defined (evmOMAPL137)
#include <ti/board/src/flash/nor/device/w25x32vsfig.h>
#else
#include <ti/board/src/flash/nor/device/n25q128.h>
#endif
#endif

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* NOR_SPI_H_ */

/* Nothing past this point */
