/*
 *  Copyright (C) 2019 Texas Instruments Incorporated.
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

#ifndef CSL_C7X_MISC_H
#define CSL_C7X_MISC_H
/**
 *  @{
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * @**@b CSL_c7xL1PCacheInvalidateAll
 *
 * @b Description
 * @**  Invalidates the L1P Cache Contents
 *
 *
 *
 * @b Arguments
 * @**  None
 *
 * <b> Return Value </b>
 * @** None
 *
 * <b> Pre Condition </b>
 * @** None
 *
 * <b> Post Condition </b>
 * @** None
 *
 * @b Reads
 * @** None
 *
 * @b Example
 * @verbatim
 *
 * CSL_c7xL1PCacheInvalidateAll();
 * @endverbatim
 */
void CSL_c7xL1PCacheInvalidateAll();
/**
 * @n@b CSL_DSPUTILSC7X_fenceAll
 *
 * @b Description
 * @n  Stalls the CPU until all pending load and store operations are completed.
 *
 * @b Arguments
 * @n None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *  CSL_DSPUTILSC7X_fenceAll();
 * @endverbatim
 */
void CSL_DSPUTILSC7X_fenceAll();

/**
 *  \brief Switch C7x from secure supervisor to non-secure supervisor
 *
 *   NOTE, this API must be called after MMU and Cache init
 *
 *  \return Ignore
 */
uint64_t CSL_c7xSecSupv2NonSecSupv(void);

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* CSL_C7X_H */
