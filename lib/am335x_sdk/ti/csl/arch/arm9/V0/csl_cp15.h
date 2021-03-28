/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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

#ifndef __CP15_H
#define __CP15_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************
**                           FUNCTION PROTOTYPES
*****************************************************************************/
extern void CSL_CP15ICacheDisable(void);
extern void CSL_CP15DCacheDisable(void);
extern void CSL_CP15ICacheEnable(void);
extern void CSL_CP15DCacheEnable(void);
extern void CSL_CP15DCacheFlush(void);
extern void CSL_CP15DCacheClean(void);
extern void CSL_CP15DCacheCleanFlush(void);
extern void CSL_CP15ICacheFlush(void);
extern void CSL_CP15TtbSet(unsigned int ttb);
extern void CSL_CP15MMUDisable(void);
extern void CSL_CP15MMUEnable(void);
extern void CSL_CP15ICacheFlushBuff(unsigned int ptr, unsigned int size);
extern void CSL_CP15DCacheCleanBuff(unsigned int bufPtr, unsigned int size);

#ifdef __cplusplus
}
#endif
#endif /* __CP15_H__ */
