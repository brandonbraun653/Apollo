/*
* Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/ 
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
*/


/**
 * \file  codecif.h
 *
 * \brief Codec Interface APIs
 *
 */

#ifndef _CODECIF_H_
#define _CODECIF_H_

#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#if defined(SOC_K2G)
#include <ti/csl/soc/k2g/src/cslr_interrupt.h>
#include <ti/csl/arch/a15/interrupt.h>
#include <ti/csl/src/ip/arm_gic/V0/csl_armGicAux.h>
#include <ti/csl/src/ip/i2c/V0/i2c.h>
#define BOARD_I2C_INTR_NUM    ((CSL_ARM_GIC_I2C_1_INT+32))

#elif defined (SOC_AM65XX)
#if defined (__aarch64__)
#include <ti/csl/arch/a53/interrupt.h>
#else
#include <ti/csl/arch/r5/interrupt.h>
#endif
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_i2c.h>
#else

#include <ti/csl/src/ip/i2c/V0/i2c.h>
#ifdef BUILD_DSP
#include <ti/csl/arch/c67x/interrupt.h>

#define BOARD_I2C_INTR_NUM    (CSL_INTC_EVENTID_I2CINT0)

#else
#include <ti/csl/arch/arm9/interrupt.h>
#define BOARD_I2C_INTR_NUM    (SYS_INT_I2CINT0)

#endif  /* #ifdef SOC_K2G */
#endif  /* #ifdef BUILD_DSP */



/**************************************************************************
**                       Macro Definitions
**************************************************************************/
/*
** Macros for configuring the interface Type
*/
#define CODEC_INTERFACE_I2C  /* Codec interface is I2C */

/**************************************************************************
**                      API function Prototypes
**************************************************************************/
extern void BoardDiag_I2CCodecIfInit(unsigned int baseAddr, unsigned int intCh,
                                     unsigned int slaveAddr);
/*
** Function to be used by codecs
*/
extern void BoardDiag_CodecRegWrite(unsigned int baseAddr, unsigned char regAddr,
                                    unsigned char regData);
extern void BoardDiag_CodecRegBitSet(unsigned int baseAddr, unsigned char regAddr,
                                     unsigned char bitMask);
extern void BoardDiag_CodecRegBitClr(unsigned int baseAddr, unsigned char regAddr,
                                     unsigned char bitMask);
extern unsigned char BoardDiag_CodecRegRead(unsigned int baseAddr,
                                            unsigned char regAddr);

#endif /* #ifndef _CODECIF_H_*/
