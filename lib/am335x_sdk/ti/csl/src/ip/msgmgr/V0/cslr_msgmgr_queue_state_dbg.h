/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_MSGMGRQUEUESTATEDBG_H_
#define CSLR_MSGMGRQUEUESTATEDBG_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 INDEX_REG[64];
} CSL_MsgmgrQueueStateDbgRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* This register holds the head index and count of queue R. */
#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG(i)                    (0x0U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* INDEX_REG */

#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_ENTRY_COUNT_MASK      (0x00FFF000U)
#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_ENTRY_COUNT_SHIFT     (12U)
#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_ENTRY_COUNT_RESETVAL  (0x00000000U)
#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_ENTRY_COUNT_MAX       (0x00000fffU)

#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_HEAD_INDEX_MASK       (0x00000FFFU)
#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_HEAD_INDEX_SHIFT      (0U)
#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_HEAD_INDEX_RESETVAL   (0x00000000U)
#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_HEAD_INDEX_MAX        (0x00000fffU)

#define CSL_MSGMGRQUEUESTATEDBG_INDEX_REG_RESETVAL              (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
