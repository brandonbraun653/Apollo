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
#ifndef CSLR_PMMCECCAGGR_H_
#define CSLR_PMMCECCAGGR_H_

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
    volatile Uint32 REV;
    volatile Uint8  RSVD0[4];
    volatile Uint32 VECTOR;
    volatile Uint32 STATUS;
    volatile Uint32 ECCWRAP_REV;
    volatile Uint32 CONTROL;
    volatile Uint32 CONTROL1;
    volatile Uint32 CONTROL2;
    volatile Uint32 STATUS1;
    volatile Uint32 STATUS2;
    volatile Uint8  RSVD1[984];
} CSL_pmmcEccaggrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* The Revision Register contains the major and minor revisions for the
 * module. It does not support byte accesses */
#define CSL_PMMCECCAGGR_REV                                     (0x0U)

/* The Global control register controls ECC control bits for the selected ECC
 * RAM */
#define CSL_PMMCECCAGGR_VECTOR                                  (0x8U)

/* Contains misc status such as number of ECC RAMs serviced by the ECC
 * aggregator */
#define CSL_PMMCECCAGGR_STATUS                                  (0xCU)

/* The Revision Register contains the major and minor revisions for the ECC
 * Wrapper modules. It does not support byte accesses Reads are triggered
 * using VECTOR register. */
#define CSL_PMMCECCAGGR_ECCWRAP_REV                             (0x10U)

/* The Global control register controls ECC control bits for the selected ECC
 * RAM Reads are triggered using VECTOR register. */
#define CSL_PMMCECCAGGR_CONTROL                                 (0x14U)

/* This register contains ECC error control bits for the selected ECC RAM
 * Reads are triggered using VECTOR register. */
#define CSL_PMMCECCAGGR_CONTROL1                                (0x18U)

/* This register contains ECC error control bits for the selected ECC RAM
 * Reads are triggered using VECTOR register. */
#define CSL_PMMCECCAGGR_CONTROL2                                (0x1CU)

/* This register contains ECC status bits for the selected ECC RAM Reads are
 * triggered using VECTOR register. */
#define CSL_PMMCECCAGGR_STATUS1                                 (0x20U)

/* This register contains ECC status bits for the selected ECC RAM Reads are
 * triggered using VECTOR register. */
#define CSL_PMMCECCAGGR_STATUS2                                 (0x24U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REV */

#define CSL_PMMCECCAGGR_REV_SCHEME_MASK                         (0xC0000000U)
#define CSL_PMMCECCAGGR_REV_SCHEME_SHIFT                        (30U)
#define CSL_PMMCECCAGGR_REV_SCHEME_RESETVAL                     (0x00000001U)
#define CSL_PMMCECCAGGR_REV_SCHEME_MAX                          (0x00000003U)

#define CSL_PMMCECCAGGR_REV_MODULEID_MASK                       (0x0FFF0000U)
#define CSL_PMMCECCAGGR_REV_MODULEID_SHIFT                      (16U)
#define CSL_PMMCECCAGGR_REV_MODULEID_RESETVAL                   (0x00000e10U)
#define CSL_PMMCECCAGGR_REV_MODULEID_MAX                        (0x00000fffU)

#define CSL_PMMCECCAGGR_REV_REV_RTL_MASK                        (0x0000F800U)
#define CSL_PMMCECCAGGR_REV_REV_RTL_SHIFT                       (11U)
#define CSL_PMMCECCAGGR_REV_REV_RTL_RESETVAL                    (0x00000000U)
#define CSL_PMMCECCAGGR_REV_REV_RTL_MAX                         (0x0000001fU)

#define CSL_PMMCECCAGGR_REV_REV_MAJOR_MASK                      (0x00000700U)
#define CSL_PMMCECCAGGR_REV_REV_MAJOR_SHIFT                     (8U)
#define CSL_PMMCECCAGGR_REV_REV_MAJOR_RESETVAL                  (0x00000000U)
#define CSL_PMMCECCAGGR_REV_REV_MAJOR_MAX                       (0x00000007U)

#define CSL_PMMCECCAGGR_REV_REV_MINOR_MASK                      (0x0000003FU)
#define CSL_PMMCECCAGGR_REV_REV_MINOR_SHIFT                     (0U)
#define CSL_PMMCECCAGGR_REV_REV_MINOR_RESETVAL                  (0x00000001U)
#define CSL_PMMCECCAGGR_REV_REV_MINOR_MAX                       (0x0000003fU)

#define CSL_PMMCECCAGGR_REV_REV_CUSTOM_MASK                     (0x000000C0U)
#define CSL_PMMCECCAGGR_REV_REV_CUSTOM_SHIFT                    (6U)
#define CSL_PMMCECCAGGR_REV_REV_CUSTOM_RESETVAL                 (0x00000000U)
#define CSL_PMMCECCAGGR_REV_REV_CUSTOM_MAX                      (0x00000003U)

#define CSL_PMMCECCAGGR_REV_RESETVAL                            (0x4e100001U)

/* VECTOR */

#define CSL_PMMCECCAGGR_VECTOR_ECC_VECTOR_MASK                  (0x000007FFU)
#define CSL_PMMCECCAGGR_VECTOR_ECC_VECTOR_SHIFT                 (0U)
#define CSL_PMMCECCAGGR_VECTOR_ECC_VECTOR_RESETVAL              (0x00000000U)
#define CSL_PMMCECCAGGR_VECTOR_ECC_VECTOR_MAX                   (0x000007ffU)

#define CSL_PMMCECCAGGR_VECTOR_TRIGGER_READ_MASK                (0x00008000U)
#define CSL_PMMCECCAGGR_VECTOR_TRIGGER_READ_SHIFT               (15U)
#define CSL_PMMCECCAGGR_VECTOR_TRIGGER_READ_RESETVAL            (0x00000000U)
#define CSL_PMMCECCAGGR_VECTOR_TRIGGER_READ_TRIGGER             (0x00000001U)
#define CSL_PMMCECCAGGR_VECTOR_TRIGGER_READ_NOACT               (0x00000000U)

#define CSL_PMMCECCAGGR_VECTOR_READ_ADDRESS_MASK                (0x00FF0000U)
#define CSL_PMMCECCAGGR_VECTOR_READ_ADDRESS_SHIFT               (16U)
#define CSL_PMMCECCAGGR_VECTOR_READ_ADDRESS_RESETVAL            (0x00000000U)
#define CSL_PMMCECCAGGR_VECTOR_READ_ADDRESS_MAX                 (0x000000ffU)

#define CSL_PMMCECCAGGR_VECTOR_READ_DONE_MASK                   (0x01000000U)
#define CSL_PMMCECCAGGR_VECTOR_READ_DONE_SHIFT                  (24U)
#define CSL_PMMCECCAGGR_VECTOR_READ_DONE_RESETVAL               (0x00000000U)
#define CSL_PMMCECCAGGR_VECTOR_READ_DONE_MAX                    (0x00000001U)

#define CSL_PMMCECCAGGR_VECTOR_RESETVAL                         (0x00000000U)

/* STATUS */

#define CSL_PMMCECCAGGR_STATUS_NUM_RAMS_MASK                    (0x000007FFU)
#define CSL_PMMCECCAGGR_STATUS_NUM_RAMS_SHIFT                   (0U)
#define CSL_PMMCECCAGGR_STATUS_NUM_RAMS_RESETVAL                (0x00000002U)
#define CSL_PMMCECCAGGR_STATUS_NUM_RAMS_MAX                     (0x000007ffU)

#define CSL_PMMCECCAGGR_STATUS_RESETVAL                         (0x00000002U)

/* ECCWRAP_REV */

#define CSL_PMMCECCAGGR_ECCWRAP_REV_SCHEME_MASK                 (0xC0000000U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_SCHEME_SHIFT                (30U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_SCHEME_RESETVAL             (0x00000001U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_SCHEME_MAX                  (0x00000003U)

#define CSL_PMMCECCAGGR_ECCWRAP_REV_MODULEID_MASK               (0x0FFF0000U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_MODULEID_SHIFT              (16U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_MODULEID_RESETVAL           (0x00000e11U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_MODULEID_MAX                (0x00000fffU)

#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_RTL_MASK                (0x0000F800U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_RTL_SHIFT               (11U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_RTL_RESETVAL            (0x00000000U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_RTL_MAX                 (0x0000001fU)

#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MAJOR_MASK              (0x00000700U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MAJOR_SHIFT             (8U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MAJOR_RESETVAL          (0x00000000U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MAJOR_MAX               (0x00000007U)

#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MINOR_MASK              (0x0000003FU)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MINOR_SHIFT             (0U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MINOR_RESETVAL          (0x00000001U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_MINOR_MAX               (0x0000003fU)

#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_CUSTOM_MASK             (0x000000C0U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_CUSTOM_SHIFT            (6U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_CUSTOM_RESETVAL         (0x00000000U)
#define CSL_PMMCECCAGGR_ECCWRAP_REV_REV_CUSTOM_MAX              (0x00000003U)

#define CSL_PMMCECCAGGR_ECCWRAP_REV_RESETVAL                    (0x4e110001U)

/* CONTROL */

#define CSL_PMMCECCAGGR_CONTROL_ECC_ENABLE_MASK                 (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_ENABLE_SHIFT                (0U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_ENABLE_RESETVAL             (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_ENABLE_EN                   (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_ENABLE_DIS                  (0x00000000U)

#define CSL_PMMCECCAGGR_CONTROL_ECC_CHECK_MASK                  (0x00000002U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_CHECK_SHIFT                 (1U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_CHECK_RESETVAL              (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_CHECK_EN                    (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ECC_CHECK_DIS                   (0x00000000U)

#define CSL_PMMCECCAGGR_CONTROL_ENABLE_RMW_MASK                 (0x00000004U)
#define CSL_PMMCECCAGGR_CONTROL_ENABLE_RMW_SHIFT                (2U)
#define CSL_PMMCECCAGGR_CONTROL_ENABLE_RMW_RESETVAL             (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ENABLE_RMW_EN                   (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ENABLE_RMW_DIS                  (0x00000000U)

#define CSL_PMMCECCAGGR_CONTROL_FORCE_SEC_MASK                  (0x00000008U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_SEC_SHIFT                 (3U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_SEC_RESETVAL              (0x00000000U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_SEC_EN                    (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_SEC_DIS                   (0x00000000U)

#define CSL_PMMCECCAGGR_CONTROL_FORCE_DED_MASK                  (0x00000010U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_DED_SHIFT                 (4U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_DED_RESETVAL              (0x00000000U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_DED_EN                    (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_DED_DIS                   (0x00000000U)

#define CSL_PMMCECCAGGR_CONTROL_FORCE_N_ROW_MASK                (0x00000020U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_N_ROW_SHIFT               (5U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_N_ROW_RESETVAL            (0x00000000U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_N_ROW_EN                  (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_FORCE_N_ROW_DIS                 (0x00000000U)

#define CSL_PMMCECCAGGR_CONTROL_ERROR_ONCE_MASK                 (0x00000040U)
#define CSL_PMMCECCAGGR_CONTROL_ERROR_ONCE_SHIFT                (6U)
#define CSL_PMMCECCAGGR_CONTROL_ERROR_ONCE_RESETVAL             (0x00000000U)
#define CSL_PMMCECCAGGR_CONTROL_ERROR_ONCE_EN                   (0x00000001U)
#define CSL_PMMCECCAGGR_CONTROL_ERROR_ONCE_DIS                  (0x00000000U)

#define CSL_PMMCECCAGGR_CONTROL_RESETVAL                        (0x00000007U)

/* CONTROL1 */

#define CSL_PMMCECCAGGR_CONTROL1_ECC_ROW_MASK                   (0x0000FFFFU)
#define CSL_PMMCECCAGGR_CONTROL1_ECC_ROW_SHIFT                  (0U)
#define CSL_PMMCECCAGGR_CONTROL1_ECC_ROW_RESETVAL               (0x00000000U)
#define CSL_PMMCECCAGGR_CONTROL1_ECC_ROW_MAX                    (0x0000ffffU)

#define CSL_PMMCECCAGGR_CONTROL1_ECC_BIT1_MASK                  (0xFFFF0000U)
#define CSL_PMMCECCAGGR_CONTROL1_ECC_BIT1_SHIFT                 (16U)
#define CSL_PMMCECCAGGR_CONTROL1_ECC_BIT1_RESETVAL              (0x00000000U)
#define CSL_PMMCECCAGGR_CONTROL1_ECC_BIT1_MAX                   (0x0000ffffU)

#define CSL_PMMCECCAGGR_CONTROL1_RESETVAL                       (0x00000000U)

/* CONTROL2 */

#define CSL_PMMCECCAGGR_CONTROL2_ECC_BIT2_MASK                  (0x0000FFFFU)
#define CSL_PMMCECCAGGR_CONTROL2_ECC_BIT2_SHIFT                 (0U)
#define CSL_PMMCECCAGGR_CONTROL2_ECC_BIT2_RESETVAL              (0x00000000U)
#define CSL_PMMCECCAGGR_CONTROL2_ECC_BIT2_MAX                   (0x0000ffffU)

#define CSL_PMMCECCAGGR_CONTROL2_RESETVAL                       (0x00000000U)

/* STATUS1 */

#define CSL_PMMCECCAGGR_STATUS1_ECC_SEC_MASK                    (0x00000001U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_SEC_SHIFT                   (0U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_SEC_RESETVAL                (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_SEC_SET                     (0x00000001U)

#define CSL_PMMCECCAGGR_STATUS1_ECC_DED_MASK                    (0x00000002U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_DED_SHIFT                   (1U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_DED_RESETVAL                (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_DED_SET                     (0x00000001U)

#define CSL_PMMCECCAGGR_STATUS1_ECC_OTHER_MASK                  (0x00000004U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_OTHER_SHIFT                 (2U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_OTHER_RESETVAL              (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_OTHER_SET                   (0x00000001U)

#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_SEC_MASK                (0x00000100U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_SEC_SHIFT               (8U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_SEC_RESETVAL            (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_SEC_CLEAR               (0x00000001U)

#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_DED_MASK                (0x00000200U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_DED_SHIFT               (9U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_DED_RESETVAL            (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_DED_CLEAR               (0x00000001U)

#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_OTHER_MASK              (0x00000400U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_OTHER_SHIFT             (10U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_OTHER_RESETVAL          (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS1_CLR_ECC_OTHER_CLEAR             (0x00000001U)

#define CSL_PMMCECCAGGR_STATUS1_ECC_ROW_MASK                    (0xFFFF0000U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_ROW_SHIFT                   (16U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_ROW_RESETVAL                (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS1_ECC_ROW_MAX                     (0x0000ffffU)

#define CSL_PMMCECCAGGR_STATUS1_RESETVAL                        (0x00000000U)

/* STATUS2 */

#define CSL_PMMCECCAGGR_STATUS2_ECC_BIT1_MASK                   (0x0000FFFFU)
#define CSL_PMMCECCAGGR_STATUS2_ECC_BIT1_SHIFT                  (0U)
#define CSL_PMMCECCAGGR_STATUS2_ECC_BIT1_RESETVAL               (0x00000000U)
#define CSL_PMMCECCAGGR_STATUS2_ECC_BIT1_MAX                    (0x0000ffffU)

#define CSL_PMMCECCAGGR_STATUS2_RESETVAL                        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
