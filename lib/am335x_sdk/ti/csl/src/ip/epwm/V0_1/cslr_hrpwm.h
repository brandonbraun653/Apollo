/********************************************************************
 * Copyright (C) 2019 Texas Instruments Incorporated.
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
 *  Name        : cslr_hrpwm.h
*/
#ifndef CSLR_HRPWM_H_
#define CSLR_HRPWM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint8_t  Resv_64[64];
    volatile uint16_t HRCTL;
} CSL_hrpwmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_HRPWM_HRCTL                                                        (0x00000040U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* HRCTL */

#define CSL_HRPWM_HRCTL_DELMODE_MASK                                           (0x0003U)
#define CSL_HRPWM_HRCTL_DELMODE_SHIFT                                          (0x0000U)
#define CSL_HRPWM_HRCTL_DELMODE_RESETVAL                                       (0x0000U)
#define CSL_HRPWM_HRCTL_DELMODE_MAX                                            (0x0003U)

#define CSL_HRPWM_HRCTL_DELBUSSEL_MASK                                         (0x0004U)
#define CSL_HRPWM_HRCTL_DELBUSSEL_SHIFT                                        (0x0002U)
#define CSL_HRPWM_HRCTL_DELBUSSEL_RESETVAL                                     (0x0000U)
#define CSL_HRPWM_HRCTL_DELBUSSEL_MAX                                          (0x0001U)

#define CSL_HRPWM_HRCTL_PULSESEL_MASK                                          (0x0008U)
#define CSL_HRPWM_HRCTL_PULSESEL_SHIFT                                         (0x0003U)
#define CSL_HRPWM_HRCTL_PULSESEL_RESETVAL                                      (0x0000U)
#define CSL_HRPWM_HRCTL_PULSESEL_MAX                                           (0x0001U)

#define CSL_HRPWM_HRCTL_RESERVED1_MASK                                         (0xFFF0U)
#define CSL_HRPWM_HRCTL_RESERVED1_SHIFT                                        (0x0004U)
#define CSL_HRPWM_HRCTL_RESERVED1_RESETVAL                                     (0x0000U)
#define CSL_HRPWM_HRCTL_RESERVED1_MAX                                          (0x0FFFU)

#define CSL_HRPWM_HRCTL_RESETVAL                                               (0x0000U)

#ifdef __cplusplus
}
#endif
#endif
