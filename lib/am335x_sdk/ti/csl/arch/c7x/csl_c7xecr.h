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

#ifndef CSL_C7XECR_H
#define CSL_C7XECR_H

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
 * @n@b CSL_c7xSetDBG_CAP
 *
 * @b Description
 * @n  Sets the contents of the DBG_CAP ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_CAP(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_CAP
 *
 * @b Description
 * @n  Gets the contents of the DBG_CAP ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_CAP(void);



/**
 * @n@b CSL_c7xSetDBG_PID
 *
 * @b Description
 * @n  Sets the contents of the DBG_PID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_PID(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_PID
 *
 * @b Description
 * @n  Gets the contents of the DBG_PID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_PID(void);



/**
 * @n@b CSL_c7xSetDBG_CNTL
 *
 * @b Description
 * @n  Sets the contents of the DBG_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_CNTL
 *
 * @b Description
 * @n  Gets the contents of the DBG_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_CNTL(void);



/**
 * @n@b CSL_c7xSetDBG_STAT
 *
 * @b Description
 * @n  Sets the contents of the DBG_STAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_STAT(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_STAT
 *
 * @b Description
 * @n  Gets the contents of the DBG_STAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_STAT(void);



/**
 * @n@b CSL_c7xSetDBG_OWN
 *
 * @b Description
 * @n  Sets the contents of the DBG_OWN ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_OWN(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_OWN
 *
 * @b Description
 * @n  Gets the contents of the DBG_OWN ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_OWN(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_CAP0
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_CAP0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_CAP0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_CAP0
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_CAP0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_CAP0(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_CAP1
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_CAP1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_CAP1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_CAP1
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_CAP1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_CAP1(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_CNTL
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_CNTL
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_CNTL(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_CTXT0
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_CTXT0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_CTXT0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_CTXT0
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_CTXT0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_CTXT0(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_CTXT1
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_CTXT1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_CTXT1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_CTXT1
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_CTXT1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_CTXT1(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_CTXT2
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_CTXT2 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_CTXT2(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_CTXT2
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_CTXT2 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_CTXT2(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_ADDR0
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_ADDR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_ADDR0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_ADDR0
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_ADDR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_ADDR0(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_ADDR1
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_ADDR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_ADDR1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_ADDR1
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_ADDR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_ADDR1(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_DATA0
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_DATA0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_DATA0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_DATA0
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_DATA0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_DATA0(void);



/**
 * @n@b CSL_c7xSetDBG_INDRCT_DATA1
 *
 * @b Description
 * @n  Sets the contents of the DBG_INDRCT_DATA1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_INDRCT_DATA1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_INDRCT_DATA1
 *
 * @b Description
 * @n  Gets the contents of the DBG_INDRCT_DATA1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_INDRCT_DATA1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_CNTL
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_CNTL
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_CNTL(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_CTXT0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_CTXT0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_CTXT0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_CTXT0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_CTXT0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_CTXT0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_CTXT1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_CTXT1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_CTXT1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_CTXT1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_CTXT1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_CTXT1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_CTXT2
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_CTXT2 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_CTXT2(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_CTXT2
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_CTXT2 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_CTXT2(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_ADDR0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_ADDR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_ADDR0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_ADDR0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_ADDR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_ADDR0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_ADDR1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_ADDR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_ADDR1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_ADDR1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_ADDR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_ADDR1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_AMASK0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_AMASK0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_AMASK0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_AMASK0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_AMASK0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_AMASK0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_0_AMASK1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_0_AMASK1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_0_AMASK1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_0_AMASK1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_0_AMASK1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_0_AMASK1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_CNTL
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_CNTL
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_CNTL(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_CTXT0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_CTXT0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_CTXT0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_CTXT0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_CTXT0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_CTXT0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_CTXT1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_CTXT1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_CTXT1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_CTXT1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_CTXT1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_CTXT1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_CTXT2
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_CTXT2 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_CTXT2(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_CTXT2
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_CTXT2 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_CTXT2(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_ADDR0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_ADDR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_ADDR0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_ADDR0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_ADDR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_ADDR0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_ADDR1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_ADDR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_ADDR1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_ADDR1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_ADDR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_ADDR1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_AMASK0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_AMASK0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_AMASK0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_AMASK0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_AMASK0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_AMASK0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_1_AMASK1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_1_AMASK1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_1_AMASK1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_1_AMASK1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_1_AMASK1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_1_AMASK1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_CNTL
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_CNTL
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_CNTL(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_CTXT0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_CTXT0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_CTXT0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_CTXT0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_CTXT0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_CTXT0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_CTXT1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_CTXT1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_CTXT1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_CTXT1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_CTXT1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_CTXT1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_CTXT2
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_CTXT2 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_CTXT2(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_CTXT2
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_CTXT2 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_CTXT2(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_ADDR0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_ADDR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_ADDR0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_ADDR0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_ADDR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_ADDR0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_ADDR1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_ADDR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_ADDR1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_ADDR1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_ADDR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_ADDR1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_AMASK0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_AMASK0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_AMASK0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_AMASK0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_AMASK0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_AMASK0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_2_AMASK1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_2_AMASK1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_2_AMASK1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_2_AMASK1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_2_AMASK1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_2_AMASK1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_CNTL
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_CNTL
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_CNTL(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_CTXT0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_CTXT0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_CTXT0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_CTXT0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_CTXT0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_CTXT0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_CTXT1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_CTXT1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_CTXT1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_CTXT1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_CTXT1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_CTXT1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_CTXT2
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_CTXT2 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_CTXT2(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_CTXT2
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_CTXT2 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_CTXT2(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_ADDR0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_ADDR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_ADDR0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_ADDR0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_ADDR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_ADDR0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_ADDR1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_ADDR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_ADDR1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_ADDR1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_ADDR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_ADDR1(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_AMASK0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_AMASK0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_AMASK0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_AMASK0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_AMASK0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_AMASK0(void);



/**
 * @n@b CSL_c7xSetDBG_HWBP_3_AMASK1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWBP_3_AMASK1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWBP_3_AMASK1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWBP_3_AMASK1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWBP_3_AMASK1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWBP_3_AMASK1(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_CNTL
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_CNTL
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_CNTL(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_CTXT0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_CTXT0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_CTXT0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_CTXT0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_CTXT0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_CTXT0(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_CTXT1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_CTXT1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_CTXT1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_CTXT1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_CTXT1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_CTXT1(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_CTXT2
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_CTXT2 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_CTXT2(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_CTXT2
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_CTXT2 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_CTXT2(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_ADDR0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_ADDR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_ADDR0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_ADDR0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_ADDR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_ADDR0(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_ADDR1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_ADDR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_ADDR1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_ADDR1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_ADDR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_ADDR1(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_MASK0
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_MASK0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_MASK0(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_MASK0
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_MASK0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_MASK0(void);



/**
 * @n@b CSL_c7xSetDBG_HWWP_0_MASK1
 *
 * @b Description
 * @n  Sets the contents of the DBG_HWWP_0_MASK1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetDBG_HWWP_0_MASK1(uint64_t param);

/**
 * @n@b CSL_c7xGetDBG_HWWP_0_MASK1
 *
 * @b Description
 * @n  Gets the contents of the DBG_HWWP_0_MASK1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetDBG_HWWP_0_MASK1(void);



/**
 * @n@b CSL_c7xSetL1DCFG
 *
 * @b Description
 * @n  Sets the contents of the L1DCFG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DCFG(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DCFG
 *
 * @b Description
 * @n  Gets the contents of the L1DCFG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DCFG(void);



/**
 * @n@b CSL_c7xSetL1DWB
 *
 * @b Description
 * @n  Sets the contents of the L1DWB ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DWB(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DWB
 *
 * @b Description
 * @n  Gets the contents of the L1DWB ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DWB(void);



/**
 * @n@b CSL_c7xSetL1DWBINV
 *
 * @b Description
 * @n  Sets the contents of the L1DWBINV ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DWBINV(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DWBINV
 *
 * @b Description
 * @n  Gets the contents of the L1DWBINV ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DWBINV(void);



/**
 * @n@b CSL_c7xSetL1DINV
 *
 * @b Description
 * @n  Sets the contents of the L1DINV ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DINV(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DINV
 *
 * @b Description
 * @n  Gets the contents of the L1DINV ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DINV(void);



/**
 * @n@b CSL_c7xSetL1DCTAG
 *
 * @b Description
 * @n  Sets the contents of the L1DCTAG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DCTAG(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DCTAG
 *
 * @b Description
 * @n  Gets the contents of the L1DCTAG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DCTAG(void);



/**
 * @n@b CSL_c7xSetL1DADDREEA
 *
 * @b Description
 * @n  Sets the contents of the L1DADDREEA ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DADDREEA(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DADDREEA
 *
 * @b Description
 * @n  Gets the contents of the L1DADDREEA ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DADDREEA(void);



/**
 * @n@b CSL_c7xSetL1DADDREES
 *
 * @b Description
 * @n  Sets the contents of the L1DADDREES ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DADDREES(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DADDREES
 *
 * @b Description
 * @n  Gets the contents of the L1DADDREES ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DADDREES(void);



/**
 * @n@b CSL_c7xSetL1DADDREER
 *
 * @b Description
 * @n  Sets the contents of the L1DADDREER ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DADDREER(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DADDREER
 *
 * @b Description
 * @n  Gets the contents of the L1DADDREER ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DADDREER(void);



/**
 * @n@b CSL_c7xSetL1DCMDEEA
 *
 * @b Description
 * @n  Sets the contents of the L1DCMDEEA ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DCMDEEA(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DCMDEEA
 *
 * @b Description
 * @n  Gets the contents of the L1DCMDEEA ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DCMDEEA(void);



/**
 * @n@b CSL_c7xSetL1DCMDEES
 *
 * @b Description
 * @n  Sets the contents of the L1DCMDEES ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DCMDEES(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DCMDEES
 *
 * @b Description
 * @n  Gets the contents of the L1DCMDEES ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DCMDEES(void);



/**
 * @n@b CSL_c7xSetL1DCMDEER
 *
 * @b Description
 * @n  Sets the contents of the L1DCMDEER ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1DCMDEER(uint64_t param);

/**
 * @n@b CSL_c7xGetL1DCMDEER
 *
 * @b Description
 * @n  Gets the contents of the L1DCMDEER ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1DCMDEER(void);



/**
 * @n@b CSL_c7xSetL1PCTAG
 *
 * @b Description
 * @n  Sets the contents of the L1PCTAG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1PCTAG(uint64_t param);

/**
 * @n@b CSL_c7xGetL1PCTAG
 *
 * @b Description
 * @n  Gets the contents of the L1PCTAG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1PCTAG(void);



/**
 * @n@b CSL_c7xSetL2CFG
 *
 * @b Description
 * @n  Sets the contents of the L2CFG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2CFG(uint64_t param);

/**
 * @n@b CSL_c7xGetL2CFG
 *
 * @b Description
 * @n  Gets the contents of the L2CFG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2CFG(void);



/**
 * @n@b CSL_c7xSetL2CC
 *
 * @b Description
 * @n  Sets the contents of the L2CC ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2CC(uint64_t param);

/**
 * @n@b CSL_c7xGetL2CC
 *
 * @b Description
 * @n  Gets the contents of the L2CC ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2CC(void);



/**
 * @n@b CSL_c7xSetL2WB
 *
 * @b Description
 * @n  Sets the contents of the L2WB ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2WB(uint64_t param);

/**
 * @n@b CSL_c7xGetL2WB
 *
 * @b Description
 * @n  Gets the contents of the L2WB ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2WB(void);



/**
 * @n@b CSL_c7xSetL2WBINV
 *
 * @b Description
 * @n  Sets the contents of the L2WBINV ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2WBINV(uint64_t param);

/**
 * @n@b CSL_c7xGetL2WBINV
 *
 * @b Description
 * @n  Gets the contents of the L2WBINV ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2WBINV(void);



/**
 * @n@b CSL_c7xSetL2INV
 *
 * @b Description
 * @n  Sets the contents of the L2INV ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2INV(uint64_t param);

/**
 * @n@b CSL_c7xGetL2INV
 *
 * @b Description
 * @n  Gets the contents of the L2INV ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2INV(void);



/**
 * @n@b CSL_c7xSetL2CTAG
 *
 * @b Description
 * @n  Sets the contents of the L2CTAG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2CTAG(uint64_t param);

/**
 * @n@b CSL_c7xGetL2CTAG
 *
 * @b Description
 * @n  Gets the contents of the L2CTAG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2CTAG(void);



/**
 * @n@b CSL_c7xSetL2EDCFG
 *
 * @b Description
 * @n  Sets the contents of the L2EDCFG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2EDCFG(uint64_t param);

/**
 * @n@b CSL_c7xGetL2EDCFG
 *
 * @b Description
 * @n  Gets the contents of the L2EDCFG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2EDCFG(void);



/**
 * @n@b CSL_c7xSetL2ADDREEA
 *
 * @b Description
 * @n  Sets the contents of the L2ADDREEA ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2ADDREEA(uint64_t param);

/**
 * @n@b CSL_c7xGetL2ADDREEA
 *
 * @b Description
 * @n  Gets the contents of the L2ADDREEA ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2ADDREEA(void);



/**
 * @n@b CSL_c7xSetL2ADDREES
 *
 * @b Description
 * @n  Sets the contents of the L2ADDREES ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2ADDREES(uint64_t param);

/**
 * @n@b CSL_c7xGetL2ADDREES
 *
 * @b Description
 * @n  Gets the contents of the L2ADDREES ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2ADDREES(void);



/**
 * @n@b CSL_c7xSetL2ADDREER
 *
 * @b Description
 * @n  Sets the contents of the L2ADDREER ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2ADDREER(uint64_t param);

/**
 * @n@b CSL_c7xGetL2ADDREER
 *
 * @b Description
 * @n  Gets the contents of the L2ADDREER ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2ADDREER(void);



/**
 * @n@b CSL_c7xSetL2ALLOCEEA
 *
 * @b Description
 * @n  Sets the contents of the L2ALLOCEEA ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2ALLOCEEA(uint64_t param);

/**
 * @n@b CSL_c7xGetL2ALLOCEEA
 *
 * @b Description
 * @n  Gets the contents of the L2ALLOCEEA ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2ALLOCEEA(void);



/**
 * @n@b CSL_c7xSetL2ALLOCEES
 *
 * @b Description
 * @n  Sets the contents of the L2ALLOCEES ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2ALLOCEES(uint64_t param);

/**
 * @n@b CSL_c7xGetL2ALLOCEES
 *
 * @b Description
 * @n  Gets the contents of the L2ALLOCEES ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2ALLOCEES(void);



/**
 * @n@b CSL_c7xSetL2ALLOCEER
 *
 * @b Description
 * @n  Sets the contents of the L2ALLOCEER ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2ALLOCEER(uint64_t param);

/**
 * @n@b CSL_c7xGetL2ALLOCEER
 *
 * @b Description
 * @n  Gets the contents of the L2ALLOCEER ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2ALLOCEER(void);



/**
 * @n@b CSL_c7xSetL2MEMMAP
 *
 * @b Description
 * @n  Sets the contents of the L2MEMMAP ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MEMMAP(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MEMMAP
 *
 * @b Description
 * @n  Gets the contents of the L2MEMMAP ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MEMMAP(void);



/**
 * @n@b CSL_c7xSetL2MSWCTL
 *
 * @b Description
 * @n  Sets the contents of the L2MSWCTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MSWCTL(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MSWCTL
 *
 * @b Description
 * @n  Gets the contents of the L2MSWCTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MSWCTL(void);



/**
 * @n@b CSL_c7xSetL2MEMMAPIBUFA
 *
 * @b Description
 * @n  Sets the contents of the L2MEMMAPIBUFA ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MEMMAPIBUFA(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MEMMAPIBUFA
 *
 * @b Description
 * @n  Gets the contents of the L2MEMMAPIBUFA ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MEMMAPIBUFA(void);



/**
 * @n@b CSL_c7xSetL2MEMMAPIBUFB
 *
 * @b Description
 * @n  Sets the contents of the L2MEMMAPIBUFB ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MEMMAPIBUFB(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MEMMAPIBUFB
 *
 * @b Description
 * @n  Gets the contents of the L2MEMMAPIBUFB ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MEMMAPIBUFB(void);



/**
 * @n@b CSL_c7xSetL2MEMMAPWBUF
 *
 * @b Description
 * @n  Sets the contents of the L2MEMMAPWBUF ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MEMMAPWBUF(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MEMMAPWBUF
 *
 * @b Description
 * @n  Gets the contents of the L2MEMMAPWBUF ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MEMMAPWBUF(void);



/**
 * @n@b CSL_c7xSetL2MSWERRSTAT
 *
 * @b Description
 * @n  Sets the contents of the L2MSWERRSTAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MSWERRSTAT(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MSWERRSTAT
 *
 * @b Description
 * @n  Gets the contents of the L2MSWERRSTAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MSWERRSTAT(void);



/**
 * @n@b CSL_c7xSetL2MSWERRCLR
 *
 * @b Description
 * @n  Sets the contents of the L2MSWERRCLR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MSWERRCLR(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MSWERRCLR
 *
 * @b Description
 * @n  Gets the contents of the L2MSWERRCLR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MSWERRCLR(void);



/**
 * @n@b CSL_c7xSetL2MSWERRADDR
 *
 * @b Description
 * @n  Sets the contents of the L2MSWERRADDR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2MSWERRADDR(uint64_t param);

/**
 * @n@b CSL_c7xGetL2MSWERRADDR
 *
 * @b Description
 * @n  Gets the contents of the L2MSWERRADDR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2MSWERRADDR(void);



/**
 * @n@b CSL_c7xSetL2EDTST
 *
 * @b Description
 * @n  Sets the contents of the L2EDTST ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL2EDTST(uint64_t param);

/**
 * @n@b CSL_c7xGetL2EDTST
 *
 * @b Description
 * @n  Gets the contents of the L2EDTST ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL2EDTST(void);



/**
 * @n@b CSL_c7xSetSE0_PID
 *
 * @b Description
 * @n  Sets the contents of the SE0_PID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_PID(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_PID
 *
 * @b Description
 * @n  Gets the contents of the SE0_PID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_PID(void);



/**
 * @n@b CSL_c7xSetSE0_FAR
 *
 * @b Description
 * @n  Sets the contents of the SE0_FAR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_FAR(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_FAR
 *
 * @b Description
 * @n  Gets the contents of the SE0_FAR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_FAR(void);



/**
 * @n@b CSL_c7xSetSE0_FSR
 *
 * @b Description
 * @n  Sets the contents of the SE0_FSR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_FSR(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_FSR
 *
 * @b Description
 * @n  Gets the contents of the SE0_FSR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_FSR(void);



/**
 * @n@b CSL_c7xSetSE0_TAG
 *
 * @b Description
 * @n  Sets the contents of the SE0_TAG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_TAG(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_TAG
 *
 * @b Description
 * @n  Gets the contents of the SE0_TAG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_TAG(void);



/**
 * @n@b CSL_c7xSetSE0_ICNT
 *
 * @b Description
 * @n  Sets the contents of the SE0_ICNT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_ICNT(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_ICNT
 *
 * @b Description
 * @n  Gets the contents of the SE0_ICNT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_ICNT(void);



/**
 * @n@b CSL_c7xSetSE0_DIM
 *
 * @b Description
 * @n  Sets the contents of the SE0_DIM ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_DIM(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_DIM
 *
 * @b Description
 * @n  Gets the contents of the SE0_DIM ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_DIM(void);



/**
 * @n@b CSL_c7xSetSE0_ADDR
 *
 * @b Description
 * @n  Sets the contents of the SE0_ADDR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_ADDR(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_ADDR
 *
 * @b Description
 * @n  Gets the contents of the SE0_ADDR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_ADDR(void);



/**
 * @n@b CSL_c7xSetSE0_STATUS
 *
 * @b Description
 * @n  Sets the contents of the SE0_STATUS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_STATUS(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_STATUS
 *
 * @b Description
 * @n  Gets the contents of the SE0_STATUS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_STATUS(void);



/**
 * @n@b CSL_c7xSetSE1_PID
 *
 * @b Description
 * @n  Sets the contents of the SE1_PID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_PID(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_PID
 *
 * @b Description
 * @n  Gets the contents of the SE1_PID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_PID(void);



/**
 * @n@b CSL_c7xSetSE1_FAR
 *
 * @b Description
 * @n  Sets the contents of the SE1_FAR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_FAR(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_FAR
 *
 * @b Description
 * @n  Gets the contents of the SE1_FAR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_FAR(void);



/**
 * @n@b CSL_c7xSetSE1_FSR
 *
 * @b Description
 * @n  Sets the contents of the SE1_FSR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_FSR(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_FSR
 *
 * @b Description
 * @n  Gets the contents of the SE1_FSR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_FSR(void);



/**
 * @n@b CSL_c7xSetSE1_TAG
 *
 * @b Description
 * @n  Sets the contents of the SE1_TAG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_TAG(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_TAG
 *
 * @b Description
 * @n  Gets the contents of the SE1_TAG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_TAG(void);



/**
 * @n@b CSL_c7xSetSE1_ICNT
 *
 * @b Description
 * @n  Sets the contents of the SE1_ICNT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_ICNT(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_ICNT
 *
 * @b Description
 * @n  Gets the contents of the SE1_ICNT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_ICNT(void);



/**
 * @n@b CSL_c7xSetSE1_DIM
 *
 * @b Description
 * @n  Sets the contents of the SE1_DIM ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_DIM(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_DIM
 *
 * @b Description
 * @n  Gets the contents of the SE1_DIM ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_DIM(void);



/**
 * @n@b CSL_c7xSetSE1_ADDR
 *
 * @b Description
 * @n  Sets the contents of the SE1_ADDR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_ADDR(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_ADDR
 *
 * @b Description
 * @n  Gets the contents of the SE1_ADDR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_ADDR(void);



/**
 * @n@b CSL_c7xSetSE1_STATUS
 *
 * @b Description
 * @n  Sets the contents of the SE1_STATUS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_STATUS(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_STATUS
 *
 * @b Description
 * @n  Gets the contents of the SE1_STATUS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_STATUS(void);



/**
 * @n@b CSL_c7xSetSE2_PID
 *
 * @b Description
 * @n  Sets the contents of the SE2_PID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE2_PID(uint64_t param);

/**
 * @n@b CSL_c7xGetSE2_PID
 *
 * @b Description
 * @n  Gets the contents of the SE2_PID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE2_PID(void);



/**
 * @n@b CSL_c7xSetSE3_PID
 *
 * @b Description
 * @n  Sets the contents of the SE3_PID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE3_PID(uint64_t param);

/**
 * @n@b CSL_c7xGetSE3_PID
 *
 * @b Description
 * @n  Gets the contents of the SE3_PID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE3_PID(void);



/**
 * @n@b CSL_c7xSetMMU_PID
 *
 * @b Description
 * @n  Sets the contents of the MMU_PID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetMMU_PID(uint64_t param);

/**
 * @n@b CSL_c7xGetMMU_PID
 *
 * @b Description
 * @n  Gets the contents of the MMU_PID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetMMU_PID(void);



/**
 * @n@b CSL_c7xSetMMU_REPL
 *
 * @b Description
 * @n  Sets the contents of the MMU_REPL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetMMU_REPL(uint64_t param);

/**
 * @n@b CSL_c7xGetMMU_REPL
 *
 * @b Description
 * @n  Gets the contents of the MMU_REPL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetMMU_REPL(void);



/**
 * @n@b CSL_c7xSetTDRR
 *
 * @b Description
 * @n  Sets the contents of the TDRR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTDRR(uint64_t param);

/**
 * @n@b CSL_c7xGetTDRR
 *
 * @b Description
 * @n  Gets the contents of the TDRR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTDRR(void);



/**
 * @n@b CSL_c7xSetTDFAR
 *
 * @b Description
 * @n  Sets the contents of the TDFAR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTDFAR(uint64_t param);

/**
 * @n@b CSL_c7xGetTDFAR
 *
 * @b Description
 * @n  Gets the contents of the TDFAR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTDFAR(void);



/**
 * @n@b CSL_c7xSetTLB_INV
 *
 * @b Description
 * @n  Sets the contents of the TLB_INV ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTLB_INV(uint64_t param);

/**
 * @n@b CSL_c7xGetTLB_INV
 *
 * @b Description
 * @n  Gets the contents of the TLB_INV ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTLB_INV(void);



/**
 * @n@b CSL_c7xSetTLB_INVC
 *
 * @b Description
 * @n  Sets the contents of the TLB_INVC ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTLB_INVC(uint64_t param);

/**
 * @n@b CSL_c7xGetTLB_INVC
 *
 * @b Description
 * @n  Gets the contents of the TLB_INVC ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTLB_INVC(void);



/**
 * @n@b CSL_c7xSetTLB_DBG
 *
 * @b Description
 * @n  Sets the contents of the TLB_DBG ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTLB_DBG(uint64_t param);

/**
 * @n@b CSL_c7xGetTLB_DBG
 *
 * @b Description
 * @n  Gets the contents of the TLB_DBG ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTLB_DBG(void);



/**
 * @n@b CSL_c7xSetTLB_DBG_DATA0
 *
 * @b Description
 * @n  Sets the contents of the TLB_DBG_DATA0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTLB_DBG_DATA0(uint64_t param);

/**
 * @n@b CSL_c7xGetTLB_DBG_DATA0
 *
 * @b Description
 * @n  Gets the contents of the TLB_DBG_DATA0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTLB_DBG_DATA0(void);



/**
 * @n@b CSL_c7xSetTLB_DBG_DATA1
 *
 * @b Description
 * @n  Sets the contents of the TLB_DBG_DATA1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTLB_DBG_DATA1(uint64_t param);

/**
 * @n@b CSL_c7xGetTLB_DBG_DATA1
 *
 * @b Description
 * @n  Gets the contents of the TLB_DBG_DATA1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTLB_DBG_DATA1(void);



/**
 * @n@b CSL_c7xSetSCR
 *
 * @b Description
 * @n  Sets the contents of the SCR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSCR(uint64_t param);

/**
 * @n@b CSL_c7xGetSCR
 *
 * @b Description
 * @n  Gets the contents of the SCR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSCR(void);



/**
 * @n@b CSL_c7xSetTCR0
 *
 * @b Description
 * @n  Sets the contents of the TCR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTCR0(uint64_t param);

/**
 * @n@b CSL_c7xGetTCR0
 *
 * @b Description
 * @n  Gets the contents of the TCR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTCR0(void);



/**
 * @n@b CSL_c7xSetTCR1
 *
 * @b Description
 * @n  Sets the contents of the TCR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTCR1(uint64_t param);

/**
 * @n@b CSL_c7xGetTCR1
 *
 * @b Description
 * @n  Gets the contents of the TCR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTCR1(void);



/**
 * @n@b CSL_c7xSetTBR0
 *
 * @b Description
 * @n  Sets the contents of the TBR0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTBR0(uint64_t param);

/**
 * @n@b CSL_c7xGetTBR0
 *
 * @b Description
 * @n  Gets the contents of the TBR0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTBR0(void);



/**
 * @n@b CSL_c7xSetTBR1
 *
 * @b Description
 * @n  Sets the contents of the TBR1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTBR1(uint64_t param);

/**
 * @n@b CSL_c7xGetTBR1
 *
 * @b Description
 * @n  Gets the contents of the TBR1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTBR1(void);



/**
 * @n@b CSL_c7xSetMAR
 *
 * @b Description
 * @n  Sets the contents of the MAR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetMAR(uint64_t param);

/**
 * @n@b CSL_c7xGetMAR
 *
 * @b Description
 * @n  Gets the contents of the MAR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetMAR(void);



/**
 * @n@b CSL_c7xSetTDAR
 *
 * @b Description
 * @n  Sets the contents of the TDAR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTDAR(uint64_t param);

/**
 * @n@b CSL_c7xGetTDAR
 *
 * @b Description
 * @n  Gets the contents of the TDAR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTDAR(void);



/**
 * @n@b CSL_c7xSetSCR_GS
 *
 * @b Description
 * @n  Sets the contents of the SCR_GS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSCR_GS(uint64_t param);

/**
 * @n@b CSL_c7xGetSCR_GS
 *
 * @b Description
 * @n  Gets the contents of the SCR_GS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSCR_GS(void);



/**
 * @n@b CSL_c7xSetTCR0_GS
 *
 * @b Description
 * @n  Sets the contents of the TCR0_GS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTCR0_GS(uint64_t param);

/**
 * @n@b CSL_c7xGetTCR0_GS
 *
 * @b Description
 * @n  Gets the contents of the TCR0_GS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTCR0_GS(void);



/**
 * @n@b CSL_c7xSetTCR1_GS
 *
 * @b Description
 * @n  Sets the contents of the TCR1_GS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTCR1_GS(uint64_t param);

/**
 * @n@b CSL_c7xGetTCR1_GS
 *
 * @b Description
 * @n  Gets the contents of the TCR1_GS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTCR1_GS(void);



/**
 * @n@b CSL_c7xSetTBR0_GS
 *
 * @b Description
 * @n  Sets the contents of the TBR0_GS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTBR0_GS(uint64_t param);

/**
 * @n@b CSL_c7xGetTBR0_GS
 *
 * @b Description
 * @n  Gets the contents of the TBR0_GS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTBR0_GS(void);



/**
 * @n@b CSL_c7xSetTBR1_GS
 *
 * @b Description
 * @n  Sets the contents of the TBR1_GS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTBR1_GS(uint64_t param);

/**
 * @n@b CSL_c7xGetTBR1_GS
 *
 * @b Description
 * @n  Gets the contents of the TBR1_GS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTBR1_GS(void);



/**
 * @n@b CSL_c7xSetMAR_GS
 *
 * @b Description
 * @n  Sets the contents of the MAR_GS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetMAR_GS(uint64_t param);

/**
 * @n@b CSL_c7xGetMAR_GS
 *
 * @b Description
 * @n  Gets the contents of the MAR_GS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetMAR_GS(void);



/**
 * @n@b CSL_c7xSetTDAR_GS
 *
 * @b Description
 * @n  Sets the contents of the TDAR_GS ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTDAR_GS(uint64_t param);

/**
 * @n@b CSL_c7xGetTDAR_GS
 *
 * @b Description
 * @n  Gets the contents of the TDAR_GS ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTDAR_GS(void);



/**
 * @n@b CSL_c7xSetSCR_S
 *
 * @b Description
 * @n  Sets the contents of the SCR_S ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSCR_S(uint64_t param);

/**
 * @n@b CSL_c7xGetSCR_S
 *
 * @b Description
 * @n  Gets the contents of the SCR_S ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSCR_S(void);



/**
 * @n@b CSL_c7xSetTCR0_S
 *
 * @b Description
 * @n  Sets the contents of the TCR0_S ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTCR0_S(uint64_t param);

/**
 * @n@b CSL_c7xGetTCR0_S
 *
 * @b Description
 * @n  Gets the contents of the TCR0_S ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTCR0_S(void);



/**
 * @n@b CSL_c7xSetTCR1_S
 *
 * @b Description
 * @n  Sets the contents of the TCR1_S ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTCR1_S(uint64_t param);

/**
 * @n@b CSL_c7xGetTCR1_S
 *
 * @b Description
 * @n  Gets the contents of the TCR1_S ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTCR1_S(void);



/**
 * @n@b CSL_c7xSetTBR0_S
 *
 * @b Description
 * @n  Sets the contents of the TBR0_S ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTBR0_S(uint64_t param);

/**
 * @n@b CSL_c7xGetTBR0_S
 *
 * @b Description
 * @n  Gets the contents of the TBR0_S ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTBR0_S(void);



/**
 * @n@b CSL_c7xSetTBR1_S
 *
 * @b Description
 * @n  Sets the contents of the TBR1_S ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTBR1_S(uint64_t param);

/**
 * @n@b CSL_c7xGetTBR1_S
 *
 * @b Description
 * @n  Gets the contents of the TBR1_S ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTBR1_S(void);



/**
 * @n@b CSL_c7xSetMAR_S
 *
 * @b Description
 * @n  Sets the contents of the MAR_S ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetMAR_S(uint64_t param);

/**
 * @n@b CSL_c7xGetMAR_S
 *
 * @b Description
 * @n  Gets the contents of the MAR_S ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetMAR_S(void);



/**
 * @n@b CSL_c7xSetTDAR_S
 *
 * @b Description
 * @n  Sets the contents of the TDAR_S ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTDAR_S(uint64_t param);

/**
 * @n@b CSL_c7xGetTDAR_S
 *
 * @b Description
 * @n  Gets the contents of the TDAR_S ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTDAR_S(void);



/**
 * @n@b CSL_c7xSetVCR
 *
 * @b Description
 * @n  Sets the contents of the VCR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetVCR(uint64_t param);

/**
 * @n@b CSL_c7xGetVCR
 *
 * @b Description
 * @n  Gets the contents of the VCR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetVCR(void);



/**
 * @n@b CSL_c7xSetVTCR
 *
 * @b Description
 * @n  Sets the contents of the VTCR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetVTCR(uint64_t param);

/**
 * @n@b CSL_c7xGetVTCR
 *
 * @b Description
 * @n  Gets the contents of the VTCR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetVTCR(void);



/**
 * @n@b CSL_c7xSetVTBR
 *
 * @b Description
 * @n  Sets the contents of the VTBR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetVTBR(uint64_t param);

/**
 * @n@b CSL_c7xGetVTBR
 *
 * @b Description
 * @n  Gets the contents of the VTBR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetVTBR(void);



/**
 * @n@b CSL_c7xSetVTDAR
 *
 * @b Description
 * @n  Sets the contents of the VTDAR ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetVTDAR(uint64_t param);

/**
 * @n@b CSL_c7xGetVTDAR
 *
 * @b Description
 * @n  Gets the contents of the VTDAR ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetVTDAR(void);



/**
 * @n@b CSL_c7xSetL1D_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the L1D_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1D_UTLB_MATCH(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetL1D_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the L1D_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1D_UTLB_MATCH(uint64_t idx);



/**
 * @n@b CSL_c7xSetL1D_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the L1D_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1D_UTLB_ATTR(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetL1D_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the L1D_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1D_UTLB_ATTR(uint64_t idx);



/**
 * @n@b CSL_c7xSetL1D_UTLB_REPL
 *
 * @b Description
 * @n  Sets the contents of the L1D_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1D_UTLB_REPL(uint64_t param);

/**
 * @n@b CSL_c7xGetL1D_UTLB_REPL
 *
 * @b Description
 * @n  Gets the contents of the L1D_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1D_UTLB_REPL(void);



/**
 * @n@b CSL_c7xSetL1P_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the L1P_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1P_UTLB_MATCH(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetL1P_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the L1P_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1P_UTLB_MATCH(uint64_t idx);



/**
 * @n@b CSL_c7xSetL1P_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the L1P_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1P_UTLB_ATTR(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetL1P_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the L1P_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1P_UTLB_ATTR(uint64_t idx);



/**
 * @n@b CSL_c7xSetL1P_UTLB_REPL
 *
 * @b Description
 * @n  Sets the contents of the L1P_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetL1P_UTLB_REPL(uint64_t param);

/**
 * @n@b CSL_c7xGetL1P_UTLB_REPL
 *
 * @b Description
 * @n  Gets the contents of the L1P_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetL1P_UTLB_REPL(void);



/**
 * @n@b CSL_c7xSetSE0_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the SE0_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_UTLB_MATCH(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetSE0_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the SE0_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_UTLB_MATCH(uint64_t idx);



/**
 * @n@b CSL_c7xSetSE0_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the SE0_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_UTLB_ATTR(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetSE0_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the SE0_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_UTLB_ATTR(uint64_t idx);



/**
 * @n@b CSL_c7xSetSE0_UTLB_REPL
 *
 * @b Description
 * @n  Sets the contents of the SE0_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE0_UTLB_REPL(uint64_t param);

/**
 * @n@b CSL_c7xGetSE0_UTLB_REPL
 *
 * @b Description
 * @n  Gets the contents of the SE0_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE0_UTLB_REPL(void);



/**
 * @n@b CSL_c7xSetSE1_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the SE1_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_UTLB_MATCH(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetSE1_UTLB_MATCH
 *
 * @b Description
 * @n  Sets the contents of the SE1_UTLB_MATCH indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_UTLB_MATCH(uint64_t idx);



/**
 * @n@b CSL_c7xSetSE1_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the SE1_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_UTLB_ATTR(uint64_t param, uint64_t idx);

/**
 * @n@b CSL_c7xGetSE1_UTLB_ATTR
 *
 * @b Description
 * @n  Sets the contents of the SE1_UTLB_ATTR indexed ECR
 *
 * @b Arguments
 * @n  uint64_t   idx
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_UTLB_ATTR(uint64_t idx);



/**
 * @n@b CSL_c7xSetSE1_UTLB_REPL
 *
 * @b Description
 * @n  Sets the contents of the SE1_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetSE1_UTLB_REPL(uint64_t param);

/**
 * @n@b CSL_c7xGetSE1_UTLB_REPL
 *
 * @b Description
 * @n  Gets the contents of the SE1_UTLB_REPL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetSE1_UTLB_REPL(void);



/**
 * @n@b CSL_c7xSetTRC_ID
 *
 * @b Description
 * @n  Sets the contents of the TRC_ID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_ID(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_ID
 *
 * @b Description
 * @n  Gets the contents of the TRC_ID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_ID(void);



/**
 * @n@b CSL_c7xSetTRC_OWN
 *
 * @b Description
 * @n  Sets the contents of the TRC_OWN ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_OWN(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_OWN
 *
 * @b Description
 * @n  Gets the contents of the TRC_OWN ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_OWN(void);



/**
 * @n@b CSL_c7xSetTRC_CNTL
 *
 * @b Description
 * @n  Sets the contents of the TRC_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_CNTL
 *
 * @b Description
 * @n  Gets the contents of the TRC_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_CNTL(void);



/**
 * @n@b CSL_c7xSetTRC_PER_CNT
 *
 * @b Description
 * @n  Sets the contents of the TRC_PER_CNT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_PER_CNT(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_PER_CNT
 *
 * @b Description
 * @n  Gets the contents of the TRC_PER_CNT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_PER_CNT(void);



/**
 * @n@b CSL_c7xSetTRC_STAT
 *
 * @b Description
 * @n  Sets the contents of the TRC_STAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_STAT(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_STAT
 *
 * @b Description
 * @n  Gets the contents of the TRC_STAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_STAT(void);



/**
 * @n@b CSL_c7xSetTRC_TRIG0_CNTL_STAT
 *
 * @b Description
 * @n  Sets the contents of the TRC_TRIG0_CNTL_STAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_TRIG0_CNTL_STAT(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_TRIG0_CNTL_STAT
 *
 * @b Description
 * @n  Gets the contents of the TRC_TRIG0_CNTL_STAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_TRIG0_CNTL_STAT(void);



/**
 * @n@b CSL_c7xSetTRC_TRIG1_CNTL_STAT
 *
 * @b Description
 * @n  Sets the contents of the TRC_TRIG1_CNTL_STAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_TRIG1_CNTL_STAT(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_TRIG1_CNTL_STAT
 *
 * @b Description
 * @n  Gets the contents of the TRC_TRIG1_CNTL_STAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_TRIG1_CNTL_STAT(void);



/**
 * @n@b CSL_c7xSetTRC_TIMESTAMP_CNT_REG0
 *
 * @b Description
 * @n  Sets the contents of the TRC_TIMESTAMP_CNT_REG0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_TIMESTAMP_CNT_REG0(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_TIMESTAMP_CNT_REG0
 *
 * @b Description
 * @n  Gets the contents of the TRC_TIMESTAMP_CNT_REG0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_TIMESTAMP_CNT_REG0(void);



/**
 * @n@b CSL_c7xSetTRC_TIMESTAMP_CNT_REG1
 *
 * @b Description
 * @n  Sets the contents of the TRC_TIMESTAMP_CNT_REG1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_TIMESTAMP_CNT_REG1(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_TIMESTAMP_CNT_REG1
 *
 * @b Description
 * @n  Gets the contents of the TRC_TIMESTAMP_CNT_REG1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_TIMESTAMP_CNT_REG1(void);



/**
 * @n@b CSL_c7xSetTRC_EXPT_CNTL
 *
 * @b Description
 * @n  Sets the contents of the TRC_EXPT_CNTL ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_EXPT_CNTL(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_EXPT_CNTL
 *
 * @b Description
 * @n  Gets the contents of the TRC_EXPT_CNTL ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_EXPT_CNTL(void);



/**
 * @n@b CSL_c7xSetTRC_EXPT_STAT
 *
 * @b Description
 * @n  Sets the contents of the TRC_EXPT_STAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_EXPT_STAT(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_EXPT_STAT
 *
 * @b Description
 * @n  Gets the contents of the TRC_EXPT_STAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_EXPT_STAT(void);



/**
 * @n@b CSL_c7xSetTRC_EXPT_ATID
 *
 * @b Description
 * @n  Sets the contents of the TRC_EXPT_ATID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetTRC_EXPT_ATID(uint64_t param);

/**
 * @n@b CSL_c7xGetTRC_EXPT_ATID
 *
 * @b Description
 * @n  Gets the contents of the TRC_EXPT_ATID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetTRC_EXPT_ATID(void);



/**
 * @n@b CSL_c7xSetAET_ID
 *
 * @b Description
 * @n  Sets the contents of the AET_ID ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_ID(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_ID
 *
 * @b Description
 * @n  Gets the contents of the AET_ID ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_ID(void);



/**
 * @n@b CSL_c7xSetAET_OWN
 *
 * @b Description
 * @n  Sets the contents of the AET_OWN ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_OWN(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_OWN
 *
 * @b Description
 * @n  Gets the contents of the AET_OWN ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_OWN(void);



/**
 * @n@b CSL_c7xSetAET_STAT
 *
 * @b Description
 * @n  Sets the contents of the AET_STAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_STAT(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_STAT
 *
 * @b Description
 * @n  Gets the contents of the AET_STAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_STAT(void);



/**
 * @n@b CSL_c7xSetAET_EVT
 *
 * @b Description
 * @n  Sets the contents of the AET_EVT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_EVT(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_EVT
 *
 * @b Description
 * @n  Gets the contents of the AET_EVT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_EVT(void);



/**
 * @n@b CSL_c7xSetAET_PC0
 *
 * @b Description
 * @n  Sets the contents of the AET_PC0 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_PC0(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_PC0
 *
 * @b Description
 * @n  Gets the contents of the AET_PC0 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_PC0(void);



/**
 * @n@b CSL_c7xSetAET_PC1
 *
 * @b Description
 * @n  Sets the contents of the AET_PC1 ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_PC1(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_PC1
 *
 * @b Description
 * @n  Gets the contents of the AET_PC1 ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_PC1(void);



/**
 * @n@b CSL_c7xSetAET_IAR_ADD
 *
 * @b Description
 * @n  Sets the contents of the AET_IAR_ADD ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_IAR_ADD(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_IAR_ADD
 *
 * @b Description
 * @n  Gets the contents of the AET_IAR_ADD ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_IAR_ADD(void);



/**
 * @n@b CSL_c7xSetAET_IAR_DAT
 *
 * @b Description
 * @n  Sets the contents of the AET_IAR_DAT ECR
 *
 * @b Arguments
 * @n  uint64_t   param
 *
 * <b> Return Value </b>
 * @n None
 *
 */
 void     CSL_c7xSetAET_IAR_DAT(uint64_t param);

/**
 * @n@b CSL_c7xGetAET_IAR_DAT
 *
 * @b Description
 * @n  Gets the contents of the AET_IAR_DAT ECR
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t val
 *
 */
 uint64_t CSL_c7xGetAET_IAR_DAT(void);


#ifdef __cplusplus
}
#endif
/** @} */

#endif             /* end of CSL_C7XECR_H definition */
