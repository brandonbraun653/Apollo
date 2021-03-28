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
#ifndef CSLR_IVAHD_H_
#define CSLR_IVAHD_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile uint64_t COMPONENT;
    volatile uint8_t  RSVD0[8];
    volatile uint64_t NETWORK;
    volatile uint8_t  RSVD1[88];
    volatile uint64_t INITID_READBACK;
} CSL_IvaHdRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Component identification */
#define CSL_IVAHD_COMPONENT                                     (0x0U)

/* Interconnect identification */
#define CSL_IVAHD_NETWORK                                       (0x10U)

/* Initiator ID read-back */
#define CSL_IVAHD_INITID_READBACK                               (0x70U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* COMPONENT */

#define CSL_IVAHD_COMPONENT_REV_MASK                            (0x0000FFFFU)
#define CSL_IVAHD_COMPONENT_REV_SHIFT                           (0U)
#define CSL_IVAHD_COMPONENT_REV_RESETVAL                        (0x00006333U)
#define CSL_IVAHD_COMPONENT_REV_MAX                             (0x0000ffffU)

#define CSL_IVAHD_COMPONENT_CODE_MASK                           (0xFFFF0000U)
#define CSL_IVAHD_COMPONENT_CODE_SHIFT                          (16U)
#define CSL_IVAHD_COMPONENT_CODE_RESETVAL                       (0x00002000U)
#define CSL_IVAHD_COMPONENT_CODE_MAX                            (0x0000ffffU)

#define CSL_IVAHD_COMPONENT_RESETVAL                            (0x20006333U)

/* NETWORK */

#define CSL_IVAHD_NETWORK_REV_MASK                              (0xFFFF00000000U)
#define CSL_IVAHD_NETWORK_REV_SHIFT                             (32U)
#define CSL_IVAHD_NETWORK_REV_RESETVAL                          (0x00000000U)
#define CSL_IVAHD_NETWORK_REV_MAX                               (0x0000ffffU)

#define CSL_IVAHD_NETWORK_ID_MASK                               (0xFFFF000000000000U)
#define CSL_IVAHD_NETWORK_ID_SHIFT                              (48U)
#define CSL_IVAHD_NETWORK_ID_RESETVAL                           (0x00000000U)
#define CSL_IVAHD_NETWORK_ID_MAX                                (0x0000ffffU)

#define CSL_IVAHD_NETWORK_RESETVAL                              (0x00000000U)

/* INITID_READBACK */

#define CSL_IVAHD_INITID_READBACK_INITID_MASK                   (0x000000FFU)
#define CSL_IVAHD_INITID_READBACK_INITID_SHIFT                  (0U)
#define CSL_IVAHD_INITID_READBACK_INITID_RESETVAL               (0x00000000U)
#define CSL_IVAHD_INITID_READBACK_INITID_MAX                    (0x000000ffU)

#define CSL_IVAHD_INITID_READBACK_RESETVAL                      (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
