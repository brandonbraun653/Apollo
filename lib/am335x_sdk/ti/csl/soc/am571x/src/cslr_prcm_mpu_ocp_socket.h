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
#ifndef CSLR_PRCM_MPU_OCP_SOCKET_H
#define CSLR_PRCM_MPU_OCP_SOCKET_H

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
    volatile Uint32 REVISION_PRCM_MPU_REG;
} CSL_prcm_mpu_ocp_socketRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register controls the CPU domain power state to reach upon a domain
 * sleep transition */
#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG           (0x0U)
/* Below define for backward compatibility */
#define MPU_REVISION  (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION_PRCM_MPU_REG */

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_X_MAJOR_MASK  (0x00000700U)
/* Below define for backward compatibility */
#define MPU_REVISION_X_MAJOR_MASK                (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_X_MAJOR_MASK)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_X_MAJOR_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_X_MAJOR_SHIFT  (8U)
/* Below define for backward compatibility */
#define MPU_REVISION_X_MAJOR_SHIFT               (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_X_MAJOR_SHIFT)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_X_MAJOR_READ0X0  (0x00000000U)
/* Below define for backward compatibility */
#define MPU_REVISION_X_MAJOR_Read0x0             (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_X_MAJOR_READ0X0)


#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define MPU_REVISION_Y_MINOR_MASK                (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_MASK)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_SHIFT  (0U)
/* Below define for backward compatibility */
#define MPU_REVISION_Y_MINOR_SHIFT               (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_SHIFT)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_READ0X0  (0x00000000U)
/* Below define for backward compatibility */
#define MPU_REVISION_Y_MINOR_Read0x0             (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_READ0X0)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_READ0X1  (0x00000001U)
/* Below define for backward compatibility */
#define MPU_REVISION_Y_MINOR_Read0x1             (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_Y_MINOR_READ0X1)


#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_CUSTOM_MASK  (0x000000C0U)
/* Below define for backward compatibility */
#define MPU_REVISION_CUSTOM_MASK                 (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_CUSTOM_MASK)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_CUSTOM_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_CUSTOM_SHIFT  (6U)
/* Below define for backward compatibility */
#define MPU_REVISION_CUSTOM_SHIFT                (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_CUSTOM_SHIFT)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_CUSTOM_MAX  (0x00000003U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_R_RTL_MASK  (0x0000F800U)
/* Below define for backward compatibility */
#define MPU_REVISION_R_RTL_MASK                  (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_R_RTL_MASK)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_R_RTL_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_R_RTL_SHIFT  (11U)
/* Below define for backward compatibility */
#define MPU_REVISION_R_RTL_SHIFT                 (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_R_RTL_SHIFT)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_R_RTL_MAX  (0x0000001fU)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_FUNC_MASK  (0x0FFF0000U)
/* Below define for backward compatibility */
#define MPU_REVISION_FUNC_MASK                   (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_FUNC_MASK)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_FUNC_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_FUNC_SHIFT  (16U)
/* Below define for backward compatibility */
#define MPU_REVISION_FUNC_SHIFT                  (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_FUNC_SHIFT)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_FUNC_MAX  (0x00000fffU)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_SCHEME_MASK  (0xC0000000U)
/* Below define for backward compatibility */
#define MPU_REVISION_SCHEME_MASK                 (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_SCHEME_MASK)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_SCHEME_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_SCHEME_SHIFT  (30U)
/* Below define for backward compatibility */
#define MPU_REVISION_SCHEME_SHIFT                (CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_SCHEME_SHIFT)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_SCHEME_MAX  (0x00000003U)

#define CSL_PRCM_MPU_OCP_SOCKET_REVISION_PRCM_MPU_REG_RESETVAL  (0x40000001U)

#ifdef __cplusplus
}
#endif
#endif
