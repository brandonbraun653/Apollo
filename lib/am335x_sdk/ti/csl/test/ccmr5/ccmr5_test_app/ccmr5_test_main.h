/*
 *   Copyright (c) Texas Instruments Incorporated 2018
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
 *  \file     ccmr5_test_main.h
 *
 *  \brief    This file contains CCM main test defines for R5 core.
 *
 *  \details  CCM register read/write and configuration tests
 **/
#ifndef CCMR5_TEST_MAIN_H
#define CCMR5_TEST_MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <string.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define  CSL_CCMR5_REG_CFG_READ_TEST_ID          (0U)
#define  CSL_CCMR5_REG_CFG_RD_OP_KEY_TEST_ID     (1U)
#define  CSL_CCMR5_REG_CLR_RD_CMP_ERR_TEST_ID    (2U)
#define  CSL_CCMR5_TOTAL_NUM_TESTS               (3U)
#define  CSL_CCMR5_TOTAL_NUM_MODULE_ID           (3U)
#define  CSL_CCMR5_TEST_PASS                     (CSL_PASS)
#define  CSL_CCMR5_TEST_FAIL                     (CSL_EFAIL)

/* ========================================================================== */
/*                 External Function Declarations                             */
/* ========================================================================== */
extern void CSL_CCMR5AppPrint(const uint8_t * str);
extern void CSL_CCMR5AppPrint_arg(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* CCMR5_TEST_MAIN_H */

/* Nothing past this point */
