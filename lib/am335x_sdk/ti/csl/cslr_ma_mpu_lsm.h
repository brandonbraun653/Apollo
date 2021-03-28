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
#ifndef CSLR_MAMPULSM_H_
#define CSLR_MAMPULSM_H_

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
    volatile Uint32 CONFIG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 LOCK;
    volatile Uint8  RSVD1[32];
    volatile Uint32 MAP_0;
    volatile Uint32 MAP_1;
    volatile Uint32 MAP_2;
    volatile Uint32 MAP_3;
} CSL_MampuLsmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* MPUMA LSM memory mapping lock */
#define CSL_MAMPULSM_CONFIG                                     (0x0U)

/* MPUMA LSM memory mapping lock */
#define CSL_MAMPULSM_LOCK                                       (0xCU)

/* MPUMA LSM memory mapping n = 0 for the first memory mapping register, n = 1 
 * for the second memory mapping register... */
#define CSL_MAMPULSM_MAP_0                                      (0x30U)

/* MPUMA LSM memory mapping n = 0 for the first memory mapping register, n = 1 
 * for the second memory mapping register... */
#define CSL_MAMPULSM_MAP_1                                      (0x34U)

/* MPUMA LSM memory mapping n = 0 for the first memory mapping register, n = 1 
 * for the second memory mapping register... */
#define CSL_MAMPULSM_MAP_2                                      (0x38U)

/* MPUMA LSM memory mapping n = 0 for the first memory mapping register, n = 1 
 * for the second memory mapping register... */
#define CSL_MAMPULSM_MAP_3                                      (0x3CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CONFIG */

#define CSL_MAMPULSM_CONFIG_IDLE_MODE_MASK                      (0x0000000CU)
#define CSL_MAMPULSM_CONFIG_IDLE_MODE_SHIFT                     (2U)
#define CSL_MAMPULSM_CONFIG_IDLE_MODE_RESETVAL                  (0x00000002U)
#define CSL_MAMPULSM_CONFIG_IDLE_MODE_MAX                       (0x00000003U)

#define CSL_MAMPULSM_CONFIG_RESETVAL                            (0x00000008U)

/* LOCK */

#define CSL_MAMPULSM_LOCK_LOCK_MASK                             (0x00000001U)
#define CSL_MAMPULSM_LOCK_LOCK_SHIFT                            (0U)
#define CSL_MAMPULSM_LOCK_LOCK_RESETVAL                         (0x00000000U)
#define CSL_MAMPULSM_LOCK_LOCK__UNLOCKED                        (0x00000000U)
#define CSL_MAMPULSM_LOCK_LOCK__LOCKED                          (0x00000001U)
#define CSL_MAMPULSM_LOCK_LOCK__LOCKING                         (0x00000001U)
#define CSL_MAMPULSM_LOCK_LOCK__KEEP                            (0x00000000U)

#define CSL_MAMPULSM_LOCK_RESETVAL                              (0x00000000U)

/* MAP_0 */

#define CSL_MAMPULSM_MAP_0_SDRC_ADDR_MASK                       (0x000000FFU)
#define CSL_MAMPULSM_MAP_0_SDRC_ADDR_SHIFT                      (0U)
#define CSL_MAMPULSM_MAP_0_SDRC_ADDR_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_0_SDRC_ADDR_MAX                        (0x000000ffU)

#define CSL_MAMPULSM_MAP_0_SDRC_ADDRSPC_MASK                    (0x00030000U)
#define CSL_MAMPULSM_MAP_0_SDRC_ADDRSPC_SHIFT                   (16U)
#define CSL_MAMPULSM_MAP_0_SDRC_ADDRSPC_RESETVAL                (0x00000001U)
#define CSL_MAMPULSM_MAP_0_SDRC_ADDRSPC_MAX                     (0x00000003U)

#define CSL_MAMPULSM_MAP_0_SDRC_MAP_MASK                        (0x00000300U)
#define CSL_MAMPULSM_MAP_0_SDRC_MAP_SHIFT                       (8U)
#define CSL_MAMPULSM_MAP_0_SDRC_MAP_RESETVAL                    (0x00000001U)
#define CSL_MAMPULSM_MAP_0_SDRC_MAP_MAX                         (0x00000003U)

#define CSL_MAMPULSM_MAP_0_SDRC_INTL_MASK                       (0x000C0000U)
#define CSL_MAMPULSM_MAP_0_SDRC_INTL_SHIFT                      (18U)
#define CSL_MAMPULSM_MAP_0_SDRC_INTL_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_0_SDRC_INTL__NONE                      (0x00000000U)
#define CSL_MAMPULSM_MAP_0_SDRC_INTL__128B                      (0x00000001U)
#define CSL_MAMPULSM_MAP_0_SDRC_INTL__256B                      (0x00000002U)
#define CSL_MAMPULSM_MAP_0_SDRC_INTL__512B                      (0x00000003U)

#define CSL_MAMPULSM_MAP_0_SYS_SIZE_MASK                        (0x00700000U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE_SHIFT                       (20U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE_RESETVAL                    (0x00000001U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__16MB                       (0x00000000U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__32MB                       (0x00000001U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__64MB                       (0x00000002U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__128MB                      (0x00000003U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__256MB                      (0x00000004U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__512MB                      (0x00000005U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__1GB                        (0x00000006U)
#define CSL_MAMPULSM_MAP_0_SYS_SIZE__2GB                        (0x00000007U)

#define CSL_MAMPULSM_MAP_0_SYS_ADDR_MASK                        (0xFF000000U)
#define CSL_MAMPULSM_MAP_0_SYS_ADDR_SHIFT                       (24U)
#define CSL_MAMPULSM_MAP_0_SYS_ADDR_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_0_SYS_ADDR_MAX                         (0x000000ffU)

#define CSL_MAMPULSM_MAP_0_RESETVAL                             (0x00110100U)

/* MAP_1 */

#define CSL_MAMPULSM_MAP_1_SDRC_ADDR_MASK                       (0x000000FFU)
#define CSL_MAMPULSM_MAP_1_SDRC_ADDR_SHIFT                      (0U)
#define CSL_MAMPULSM_MAP_1_SDRC_ADDR_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SDRC_ADDR_MAX                        (0x000000ffU)

#define CSL_MAMPULSM_MAP_1_SDRC_ADDRSPC_MASK                    (0x00030000U)
#define CSL_MAMPULSM_MAP_1_SDRC_ADDRSPC_SHIFT                   (16U)
#define CSL_MAMPULSM_MAP_1_SDRC_ADDRSPC_RESETVAL                (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SDRC_ADDRSPC_MAX                     (0x00000003U)

#define CSL_MAMPULSM_MAP_1_SDRC_MAP_MASK                        (0x00000300U)
#define CSL_MAMPULSM_MAP_1_SDRC_MAP_SHIFT                       (8U)
#define CSL_MAMPULSM_MAP_1_SDRC_MAP_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SDRC_MAP_MAX                         (0x00000003U)

#define CSL_MAMPULSM_MAP_1_SDRC_INTL_MASK                       (0x000C0000U)
#define CSL_MAMPULSM_MAP_1_SDRC_INTL_SHIFT                      (18U)
#define CSL_MAMPULSM_MAP_1_SDRC_INTL_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SDRC_INTL__NONE                      (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SDRC_INTL__128B                      (0x00000001U)
#define CSL_MAMPULSM_MAP_1_SDRC_INTL__256B                      (0x00000002U)
#define CSL_MAMPULSM_MAP_1_SDRC_INTL__512B                      (0x00000003U)

#define CSL_MAMPULSM_MAP_1_SYS_SIZE_MASK                        (0x00700000U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE_SHIFT                       (20U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__16MB                       (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__32MB                       (0x00000001U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__64MB                       (0x00000002U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__128MB                      (0x00000003U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__256MB                      (0x00000004U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__512MB                      (0x00000005U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__1GB                        (0x00000006U)
#define CSL_MAMPULSM_MAP_1_SYS_SIZE__2GB                        (0x00000007U)

#define CSL_MAMPULSM_MAP_1_SYS_ADDR_MASK                        (0xFF000000U)
#define CSL_MAMPULSM_MAP_1_SYS_ADDR_SHIFT                       (24U)
#define CSL_MAMPULSM_MAP_1_SYS_ADDR_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_1_SYS_ADDR_MAX                         (0x000000ffU)

#define CSL_MAMPULSM_MAP_1_RESETVAL                             (0x00000000U)

/* MAP_2 */

#define CSL_MAMPULSM_MAP_2_SDRC_ADDR_MASK                       (0x000000FFU)
#define CSL_MAMPULSM_MAP_2_SDRC_ADDR_SHIFT                      (0U)
#define CSL_MAMPULSM_MAP_2_SDRC_ADDR_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SDRC_ADDR_MAX                        (0x000000ffU)

#define CSL_MAMPULSM_MAP_2_SDRC_ADDRSPC_MASK                    (0x00030000U)
#define CSL_MAMPULSM_MAP_2_SDRC_ADDRSPC_SHIFT                   (16U)
#define CSL_MAMPULSM_MAP_2_SDRC_ADDRSPC_RESETVAL                (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SDRC_ADDRSPC_MAX                     (0x00000003U)

#define CSL_MAMPULSM_MAP_2_SDRC_MAP_MASK                        (0x00000300U)
#define CSL_MAMPULSM_MAP_2_SDRC_MAP_SHIFT                       (8U)
#define CSL_MAMPULSM_MAP_2_SDRC_MAP_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SDRC_MAP_MAX                         (0x00000003U)

#define CSL_MAMPULSM_MAP_2_SDRC_INTL_MASK                       (0x000C0000U)
#define CSL_MAMPULSM_MAP_2_SDRC_INTL_SHIFT                      (18U)
#define CSL_MAMPULSM_MAP_2_SDRC_INTL_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SDRC_INTL__NONE                      (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SDRC_INTL__128B                      (0x00000001U)
#define CSL_MAMPULSM_MAP_2_SDRC_INTL__256B                      (0x00000002U)
#define CSL_MAMPULSM_MAP_2_SDRC_INTL__512B                      (0x00000003U)

#define CSL_MAMPULSM_MAP_2_SYS_SIZE_MASK                        (0x00700000U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE_SHIFT                       (20U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__16MB                       (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__32MB                       (0x00000001U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__64MB                       (0x00000002U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__128MB                      (0x00000003U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__256MB                      (0x00000004U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__512MB                      (0x00000005U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__1GB                        (0x00000006U)
#define CSL_MAMPULSM_MAP_2_SYS_SIZE__2GB                        (0x00000007U)

#define CSL_MAMPULSM_MAP_2_SYS_ADDR_MASK                        (0xFF000000U)
#define CSL_MAMPULSM_MAP_2_SYS_ADDR_SHIFT                       (24U)
#define CSL_MAMPULSM_MAP_2_SYS_ADDR_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_2_SYS_ADDR_MAX                         (0x000000ffU)

#define CSL_MAMPULSM_MAP_2_RESETVAL                             (0x00000000U)

/* MAP_3 */

#define CSL_MAMPULSM_MAP_3_SDRC_ADDR_MASK                       (0x000000FFU)
#define CSL_MAMPULSM_MAP_3_SDRC_ADDR_SHIFT                      (0U)
#define CSL_MAMPULSM_MAP_3_SDRC_ADDR_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SDRC_ADDR_MAX                        (0x000000ffU)

#define CSL_MAMPULSM_MAP_3_SDRC_ADDRSPC_MASK                    (0x00030000U)
#define CSL_MAMPULSM_MAP_3_SDRC_ADDRSPC_SHIFT                   (16U)
#define CSL_MAMPULSM_MAP_3_SDRC_ADDRSPC_RESETVAL                (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SDRC_ADDRSPC_MAX                     (0x00000003U)

#define CSL_MAMPULSM_MAP_3_SDRC_MAP_MASK                        (0x00000300U)
#define CSL_MAMPULSM_MAP_3_SDRC_MAP_SHIFT                       (8U)
#define CSL_MAMPULSM_MAP_3_SDRC_MAP_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SDRC_MAP_MAX                         (0x00000003U)

#define CSL_MAMPULSM_MAP_3_SDRC_INTL_MASK                       (0x000C0000U)
#define CSL_MAMPULSM_MAP_3_SDRC_INTL_SHIFT                      (18U)
#define CSL_MAMPULSM_MAP_3_SDRC_INTL_RESETVAL                   (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SDRC_INTL__NONE                      (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SDRC_INTL__128B                      (0x00000001U)
#define CSL_MAMPULSM_MAP_3_SDRC_INTL__256B                      (0x00000002U)
#define CSL_MAMPULSM_MAP_3_SDRC_INTL__512B                      (0x00000003U)

#define CSL_MAMPULSM_MAP_3_SYS_SIZE_MASK                        (0x00700000U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE_SHIFT                       (20U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__16MB                       (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__32MB                       (0x00000001U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__64MB                       (0x00000002U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__128MB                      (0x00000003U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__256MB                      (0x00000004U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__512MB                      (0x00000005U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__1GB                        (0x00000006U)
#define CSL_MAMPULSM_MAP_3_SYS_SIZE__2GB                        (0x00000007U)

#define CSL_MAMPULSM_MAP_3_SYS_ADDR_MASK                        (0xFF000000U)
#define CSL_MAMPULSM_MAP_3_SYS_ADDR_SHIFT                       (24U)
#define CSL_MAMPULSM_MAP_3_SYS_ADDR_RESETVAL                    (0x00000000U)
#define CSL_MAMPULSM_MAP_3_SYS_ADDR_MAX                         (0x000000ffU)

#define CSL_MAMPULSM_MAP_3_RESETVAL                             (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
