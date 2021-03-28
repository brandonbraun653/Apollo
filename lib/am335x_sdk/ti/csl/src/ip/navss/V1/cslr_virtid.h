/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_virtid.h
*/
#ifndef CSLR_VIRTID_H_
#define CSLR_VIRTID_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : VirtID Translation Config
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint8_t  Resv_16[12];
    volatile uint32_t WINDOW[16];                /* VirtID Mapping Registers */
} CSL_virtidRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_VIRTID_PID                                                         (0x00000000U)
#define CSL_VIRTID_WINDOW(WINDOW)                                              (0x00000010U+((WINDOW)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_VIRTID_PID_MINOR_MASK                                              (0x0000003FU)
#define CSL_VIRTID_PID_MINOR_SHIFT                                             (0x00000000U)
#define CSL_VIRTID_PID_MINOR_MAX                                               (0x0000003FU)

#define CSL_VIRTID_PID_CUSTOM_MASK                                             (0x000000C0U)
#define CSL_VIRTID_PID_CUSTOM_SHIFT                                            (0x00000006U)
#define CSL_VIRTID_PID_CUSTOM_MAX                                              (0x00000003U)

#define CSL_VIRTID_PID_MAJOR_MASK                                              (0x00000700U)
#define CSL_VIRTID_PID_MAJOR_SHIFT                                             (0x00000008U)
#define CSL_VIRTID_PID_MAJOR_MAX                                               (0x00000007U)

#define CSL_VIRTID_PID_RTL_MASK                                                (0x0000F800U)
#define CSL_VIRTID_PID_RTL_SHIFT                                               (0x0000000BU)
#define CSL_VIRTID_PID_RTL_MAX                                                 (0x0000001FU)

#define CSL_VIRTID_PID_FUNC_MASK                                               (0x0FFF0000U)
#define CSL_VIRTID_PID_FUNC_SHIFT                                              (0x00000010U)
#define CSL_VIRTID_PID_FUNC_MAX                                                (0x00000FFFU)

#define CSL_VIRTID_PID_BU_MASK                                                 (0x30000000U)
#define CSL_VIRTID_PID_BU_SHIFT                                                (0x0000001CU)
#define CSL_VIRTID_PID_BU_MAX                                                  (0x00000003U)

#define CSL_VIRTID_PID_SCHEME_MASK                                             (0xC0000000U)
#define CSL_VIRTID_PID_SCHEME_SHIFT                                            (0x0000001EU)
#define CSL_VIRTID_PID_SCHEME_MAX                                              (0x00000003U)

/* WINDOW */

#define CSL_VIRTID_WINDOW_VIRTID_MASK                                          (0x00000FFFU)
#define CSL_VIRTID_WINDOW_VIRTID_SHIFT                                         (0x00000000U)
#define CSL_VIRTID_WINDOW_VIRTID_MAX                                           (0x00000FFFU)

#ifdef __cplusplus
}
#endif
#endif
