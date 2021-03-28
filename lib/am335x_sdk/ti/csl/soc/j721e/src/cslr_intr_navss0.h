/********************************************************************
*
* NAVSS0 INTERRUPT MAP. header file
*
* Copyright (C) 2015-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_NAVSS0_INTERRUPT_MAP_H_
#define CSLR_NAVSS0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: NAVSS0
*/

#define CSLR_NAVSS0_CPTS0_HW1_PUSH_TIMESYNC_INTRTR0_OUTL_0                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW1_PUSH_0                                         (0U)
#define CSLR_NAVSS0_CPTS0_HW2_PUSH_TIMESYNC_INTRTR0_OUTL_1                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW2_PUSH_0                                         (1U)
#define CSLR_NAVSS0_CPTS0_HW3_PUSH_TIMESYNC_INTRTR0_OUTL_2                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW3_PUSH_0                                         (2U)
#define CSLR_NAVSS0_CPTS0_HW4_PUSH_TIMESYNC_INTRTR0_OUTL_3                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW4_PUSH_0                                         (3U)
#define CSLR_NAVSS0_CPTS0_HW5_PUSH_TIMESYNC_INTRTR0_OUTL_4                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW5_PUSH_0                                         (4U)
#define CSLR_NAVSS0_CPTS0_HW6_PUSH_TIMESYNC_INTRTR0_OUTL_5                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW6_PUSH_0                                         (5U)
#define CSLR_NAVSS0_CPTS0_HW7_PUSH_TIMESYNC_INTRTR0_OUTL_6                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW7_PUSH_0                                         (6U)
#define CSLR_NAVSS0_CPTS0_HW8_PUSH_TIMESYNC_INTRTR0_OUTL_7                                         (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_NAVSS0_CPTS0_HW8_PUSH_0                                         (7U)
/*
* Include SubSystem Intr Sources for:NAVSS0
*/

#include <ti/csl/soc/j721e/src/cslr_intr_navss0_intr_router_0.h>
#include <ti/csl/soc/j721e/src/cslr_intr_navss0_udmass_intaggr_0.h>

#ifdef __cplusplus
}
#endif
#endif /* CSLR_NAVSS0_INTERRUPT_MAP_H_ */

