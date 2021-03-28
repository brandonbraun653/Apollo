/*
 *
 * Copyright (C) 2012-2013 Texas Instruments Incorporated - http://www.ti.com/
 *
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
*/

/********************************************************************
* file: cslr_iqn2.h
*
* Brief: This file contains the Register Description for IQN2
*
*********************************************************************/
#ifndef CSLR_IQN2_H_
#define CSLR_IQN2_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#include <ti/csl/src/ip/iqn2/V0/cslr_iqn2_top.h>
#include <ti/csl/src/ip/iqn2/V0/cslr_iqn_at2.h>
#include <ti/csl/src/ip/iqn2/V0/cslr_iqn_iqs2.h>
#include <ti/csl/src/ip/iqn2/V0/cslr_iqn_aid2.h>
#include <ti/csl/src/ip/iqn2/V0/cslr_iqn_dio2.h>
#include <ti/csl/src/ip/iqn2/V0/cslr_iqn2_cdmahp.h>
#include <ti/csl/src/ip/iqn2/V0/cslr_iqn_ail.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for IQN2
\**************************************************************************/
typedef struct  {
    CSL_Iqn2_topRegs      Top;    /* offset 0x00_0000 to 0x00_FFFF  sub modules VC, EE and PSR */
    CSL_Iqn_at2Regs       At2;    /* offset 0x01_0000 to 0x01_FFFF  sub_module AT */
    CSL_Iqn_iqs2Regs      Iqs2;   /* offset 0x02_0000 to 0x03_FFFF  sub_module IQS */
    CSL_Iqn_aid2Regs      Aid2;   /* offset 0x04_0000 to 0x05_FFFF  sub_module AID */
    CSL_Iqn_dio2Regs      Dio2;   /* offset 0x06_0000 to 0x0F_FFFF  sub_module DIO */
    CSL_Iqn2_cdmahpRegs   CdmaHp; /* offset 0x10_0000 to 0x1F_FFFF  sub_module CDMAHP */
    CSL_Iqn_ailRegs       Ail[2]; /* offset 0x20_0000 to 0x23_FFFF (AIL0), offset 24_0000 to 27_FFFF (AIL1) */
} CSL_Iqn2Regs;

#endif
