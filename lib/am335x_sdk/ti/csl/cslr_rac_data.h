/*  ===========================================================================
 *  Copyright (c) Texas Instruments Incorporated 2002-2011
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

/** 
 *   @file  cslr_rac_data.h
 *
 *   @brief  
 *      This file contains the Register Desciptions for RAC_DATA
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2006, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found 
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par 
 */
#ifndef CSLR_RAC_DATA_H
#define CSLR_RAC_DATA_H

#include <ti/csl/cslr.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/tistdtypes.h>


/* Minimum unit = 4 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile CSL_Uint64 FE_ANT[1024];
    volatile Uint32 FE_TIME;
} CSL_Rac2_dataRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* FE_ANT */

#define CSL_RAC2_DATA_FE_ANT_C3_Q_MASK   (0xFF00000000000000u)
#define CSL_RAC2_DATA_FE_ANT_C3_Q_SHIFT  (0x0000000000000038u)
#define CSL_RAC2_DATA_FE_ANT_C3_Q_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_C3_I_MASK   (0x00FF000000000000u)
#define CSL_RAC2_DATA_FE_ANT_C3_I_SHIFT  (0x0000000000000030u)
#define CSL_RAC2_DATA_FE_ANT_C3_I_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_C2_Q_MASK   (0x0000FF0000000000u)
#define CSL_RAC2_DATA_FE_ANT_C2_Q_SHIFT  (0x0000000000000028u)
#define CSL_RAC2_DATA_FE_ANT_C2_Q_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_C2_I_MASK   (0x000000FF00000000u)
#define CSL_RAC2_DATA_FE_ANT_C2_I_SHIFT  (0x0000000000000020u)
#define CSL_RAC2_DATA_FE_ANT_C2_I_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_C1_Q_MASK   (0x00000000FF000000u)
#define CSL_RAC2_DATA_FE_ANT_C1_Q_SHIFT  (0x0000000000000018u)
#define CSL_RAC2_DATA_FE_ANT_C1_Q_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_C1_I_MASK   (0x0000000000FF0000u)
#define CSL_RAC2_DATA_FE_ANT_C1_I_SHIFT  (0x0000000000000010u)
#define CSL_RAC2_DATA_FE_ANT_C1_I_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_C0_Q_MASK   (0x000000000000FF00u)
#define CSL_RAC2_DATA_FE_ANT_C0_Q_SHIFT  (0x0000000000000008u)
#define CSL_RAC2_DATA_FE_ANT_C0_Q_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_C0_I_MASK   (0x00000000000000FFu)
#define CSL_RAC2_DATA_FE_ANT_C0_I_SHIFT  (0x0000000000000000u)
#define CSL_RAC2_DATA_FE_ANT_C0_I_RESETVAL (0x0000000000000000u)

#define CSL_RAC2_DATA_FE_ANT_RESETVAL    (0x0000000000000000u)

/* FE_TIME */


#define CSL_RAC2_DATA_FE_TIME_FRAME_MASK (0x0FFF0000u)
#define CSL_RAC2_DATA_FE_TIME_FRAME_SHIFT (0x00000010u)
#define CSL_RAC2_DATA_FE_TIME_FRAME_RESETVAL (0x00000000u)

#define CSL_RAC2_DATA_FE_TIME_SLOT_MASK  (0x0000F000u)
#define CSL_RAC2_DATA_FE_TIME_SLOT_SHIFT (0x0000000Cu)
#define CSL_RAC2_DATA_FE_TIME_SLOT_RESETVAL (0x00000000u)

#define CSL_RAC2_DATA_FE_TIME_CHIP_MASK  (0x00000FFFu)
#define CSL_RAC2_DATA_FE_TIME_CHIP_SHIFT (0x00000000u)
#define CSL_RAC2_DATA_FE_TIME_CHIP_RESETVAL (0x00000000u)

#define CSL_RAC2_DATA_FE_TIME_RESETVAL   (0x00000000u)

#endif
