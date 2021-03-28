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
#ifndef CSLR_ECC_AGGR_H_
#define CSLR_ECC_AGGR_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[4];
    volatile Uint32 VECTOR;
    volatile Uint32 MISC_STATUS;
    volatile Uint32 WRAPPER_REVISION;
    volatile Uint32 CONTROL;
    volatile Uint32 ERROR_CONTROL1;
    volatile Uint32 ERROR_CONTROL2;
    volatile Uint32 ERROR_STATUS1;
    volatile Uint32 ERROR_STATUS2;
    volatile Uint8  RSVD1[20];
    volatile Uint32 EOI;
    volatile Uint32 INT_STATUS[16];
    volatile Uint32 INT_ENABLE[16];
    volatile Uint32 INT_CLEAR[16];
} CSL_Ecc_aggrRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* The Revision Register contains the ID and revision information. */
#define CSL_ECC_AGGR_REVISION                                   (0x0U)

/* ECC RAM ID to select the ECC RAM to control or read status. */
#define CSL_ECC_AGGR_VECTOR                                     (0x8U)

/* Miscellaneous status register. */
#define CSL_ECC_AGGR_MISC_STATUS                                (0xCU)

/* The Revision Register contains the ID and revision information for the ECC
 * wrapper. */
#define CSL_ECC_AGGR_WRAPPER_REVISION                           (0x10U)

/* The Control Register controls the ECC control bits for the selected ECC
 * RAM. */
#define CSL_ECC_AGGR_CONTROL                                    (0x14U)

/* This register contains ECC error control bits for the selected ECC RAM. */
#define CSL_ECC_AGGR_ERROR_CONTROL1                             (0x18U)

/* This register contains ECC error control bits for the selected ECC RAM. */
#define CSL_ECC_AGGR_ERROR_CONTROL2                             (0x1CU)

/* This register contains ECC status bits for the selected ECC RAM. */
#define CSL_ECC_AGGR_ERROR_STATUS1                              (0x20U)

/* This register contains ECC status bits for the selected ECC RAM. */
#define CSL_ECC_AGGR_ERROR_STATUS2                              (0x24U)

/* This is the EOI register for the interrupt to the host. */
#define CSL_ECC_AGGR_EOI                                        (0x3CU)

/* These are the raw level interrupt status bits where each bit corresponds to
 * the pending status from an ECC RAM. */
#define CSL_ECC_AGGR_INT_STATUS(i)                              (0x40U + ((i) * (0x4U)))

/* These are interrupt enables associated with the interrupt from each of the
 * ECC RAMs. Writing a 1 to a bit position in the register enables the
 * interrupt from the associated ECC RAM. */
#define CSL_ECC_AGGR_INT_ENABLE(i)                              (0x80U + ((i) * (0x4U)))

/* These are interrupt enable clear bits associated with the interrupt from
 * each of the ECC RAMs. Writing a 1 to a bit position in the register
 * disables the interrupt from the associated ECC RAM. */
#define CSL_ECC_AGGR_INT_CLEAR(i)                               (0xC0U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_ECC_AGGR_REVISION_SCHEME_MASK                       (0xC0000000U)
#define CSL_ECC_AGGR_REVISION_SCHEME_SHIFT                      (30U)
#define CSL_ECC_AGGR_REVISION_SCHEME_RESETVAL                   (0x00000000U)
#define CSL_ECC_AGGR_REVISION_SCHEME_MAX                        (0x00000003U)

#define CSL_ECC_AGGR_REVISION_MODID_MASK                        (0x0FFF0000U)
#define CSL_ECC_AGGR_REVISION_MODID_SHIFT                       (16U)
#define CSL_ECC_AGGR_REVISION_MODID_RESETVAL                    (0x00000000U)
#define CSL_ECC_AGGR_REVISION_MODID_MAX                         (0x00000fffU)

#define CSL_ECC_AGGR_REVISION_REVRTL_MASK                       (0x0000F800U)
#define CSL_ECC_AGGR_REVISION_REVRTL_SHIFT                      (11U)
#define CSL_ECC_AGGR_REVISION_REVRTL_RESETVAL                   (0x00000000U)
#define CSL_ECC_AGGR_REVISION_REVRTL_MAX                        (0x0000001fU)

#define CSL_ECC_AGGR_REVISION_REVMAJ_MASK                       (0x00000700U)
#define CSL_ECC_AGGR_REVISION_REVMAJ_SHIFT                      (8U)
#define CSL_ECC_AGGR_REVISION_REVMAJ_RESETVAL                   (0x00000000U)
#define CSL_ECC_AGGR_REVISION_REVMAJ_MAX                        (0x00000007U)

#define CSL_ECC_AGGR_REVISION_REVCUSTOM_MASK                    (0x000000C0U)
#define CSL_ECC_AGGR_REVISION_REVCUSTOM_SHIFT                   (6U)
#define CSL_ECC_AGGR_REVISION_REVCUSTOM_RESETVAL                (0x00000000U)
#define CSL_ECC_AGGR_REVISION_REVCUSTOM_MAX                     (0x00000003U)

#define CSL_ECC_AGGR_REVISION_REVMIN_MASK                       (0x0000003FU)
#define CSL_ECC_AGGR_REVISION_REVMIN_SHIFT                      (0U)
#define CSL_ECC_AGGR_REVISION_REVMIN_RESETVAL                   (0x00000000U)
#define CSL_ECC_AGGR_REVISION_REVMIN_MAX                        (0x0000003fU)

#define CSL_ECC_AGGR_REVISION_RESETVAL                          (0x00000000U)

/* VECTOR */

#define CSL_ECC_AGGR_VECTOR_READ_DONE_MASK                      (0x01000000U)
#define CSL_ECC_AGGR_VECTOR_READ_DONE_SHIFT                     (24U)
#define CSL_ECC_AGGR_VECTOR_READ_DONE_RESETVAL                  (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_READ_DONE_MAX                       (0x00000001U)

#define CSL_ECC_AGGR_VECTOR_READ_ADDRESS_MASK                   (0x00FF0000U)
#define CSL_ECC_AGGR_VECTOR_READ_ADDRESS_SHIFT                  (16U)
#define CSL_ECC_AGGR_VECTOR_READ_ADDRESS_RESETVAL               (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_READ_ADDRESS_MAX                    (0x000000ffU)

#define CSL_ECC_AGGR_VECTOR_TRIGGER_READ_MASK                   (0x00008000U)
#define CSL_ECC_AGGR_VECTOR_TRIGGER_READ_SHIFT                  (15U)
#define CSL_ECC_AGGR_VECTOR_TRIGGER_READ_RESETVAL               (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_TRIGGER_READ_MAX                    (0x00000001U)

#define CSL_ECC_AGGR_VECTOR_RAM_ID_MASK                         (0x000007FFU)
#define CSL_ECC_AGGR_VECTOR_RAM_ID_SHIFT                        (0U)
#define CSL_ECC_AGGR_VECTOR_RAM_ID_RESETVAL                     (0x00000000U)
#define CSL_ECC_AGGR_VECTOR_RAM_ID_MAX                          (0x000007ffU)

#define CSL_ECC_AGGR_VECTOR_RESETVAL                            (0x00000000U)

/* MISC_STATUS */

#define CSL_ECC_AGGR_MISC_STATUS_NUM_RAMS_MASK                  (0x000007FFU)
#define CSL_ECC_AGGR_MISC_STATUS_NUM_RAMS_SHIFT                 (0U)
#define CSL_ECC_AGGR_MISC_STATUS_NUM_RAMS_RESETVAL              (0x00000000U)
#define CSL_ECC_AGGR_MISC_STATUS_NUM_RAMS_MAX                   (0x000007ffU)

#define CSL_ECC_AGGR_MISC_STATUS_RESETVAL                       (0x00000000U)

/* WRAPPER_REVISION */

#define CSL_ECC_AGGR_WRAPPER_REVISION_SCHEME_MASK               (0xC0000000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_SCHEME_SHIFT              (30U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_SCHEME_RESETVAL           (0x00000000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_SCHEME_MAX                (0x00000003U)

#define CSL_ECC_AGGR_WRAPPER_REVISION_MODID_MASK                (0x0FFF0000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_MODID_SHIFT               (16U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_MODID_RESETVAL            (0x00000000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_MODID_MAX                 (0x00000fffU)

#define CSL_ECC_AGGR_WRAPPER_REVISION_REVRTL_MASK               (0x0000F800U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVRTL_SHIFT              (11U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVRTL_RESETVAL           (0x00000000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVRTL_MAX                (0x0000001fU)

#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMAJ_MASK               (0x00000700U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMAJ_SHIFT              (8U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMAJ_RESETVAL           (0x00000000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMAJ_MAX                (0x00000007U)

#define CSL_ECC_AGGR_WRAPPER_REVISION_REVCUSTOM_MASK            (0x000000C0U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVCUSTOM_SHIFT           (6U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVCUSTOM_RESETVAL        (0x00000000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVCUSTOM_MAX             (0x00000003U)

#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMIN_MASK               (0x0000003FU)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMIN_SHIFT              (0U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMIN_RESETVAL           (0x00000000U)
#define CSL_ECC_AGGR_WRAPPER_REVISION_REVMIN_MAX                (0x0000003fU)

#define CSL_ECC_AGGR_WRAPPER_REVISION_RESETVAL                  (0x00000000U)

/* CONTROL */

#define CSL_ECC_AGGR_CONTROL_ERROR_ONCE_MASK                    (0x00000040U)
#define CSL_ECC_AGGR_CONTROL_ERROR_ONCE_SHIFT                   (6U)
#define CSL_ECC_AGGR_CONTROL_ERROR_ONCE_RESETVAL                (0x00000000U)
#define CSL_ECC_AGGR_CONTROL_ERROR_ONCE_MAX                     (0x00000001U)

#define CSL_ECC_AGGR_CONTROL_FORCE_N_ROW_MASK                   (0x00000020U)
#define CSL_ECC_AGGR_CONTROL_FORCE_N_ROW_SHIFT                  (5U)
#define CSL_ECC_AGGR_CONTROL_FORCE_N_ROW_RESETVAL               (0x00000000U)
#define CSL_ECC_AGGR_CONTROL_FORCE_N_ROW_MAX                    (0x00000001U)

#define CSL_ECC_AGGR_CONTROL_FORCE_DED_MASK                     (0x00000010U)
#define CSL_ECC_AGGR_CONTROL_FORCE_DED_SHIFT                    (4U)
#define CSL_ECC_AGGR_CONTROL_FORCE_DED_RESETVAL                 (0x00000000U)
#define CSL_ECC_AGGR_CONTROL_FORCE_DED_MAX                      (0x00000001U)

#define CSL_ECC_AGGR_CONTROL_FORCE_SEC_MASK                     (0x00000008U)
#define CSL_ECC_AGGR_CONTROL_FORCE_SEC_SHIFT                    (3U)
#define CSL_ECC_AGGR_CONTROL_FORCE_SEC_RESETVAL                 (0x00000000U)
#define CSL_ECC_AGGR_CONTROL_FORCE_SEC_MAX                      (0x00000001U)

#define CSL_ECC_AGGR_CONTROL_ENABLE_RMW_MASK                    (0x00000004U)
#define CSL_ECC_AGGR_CONTROL_ENABLE_RMW_SHIFT                   (2U)
#define CSL_ECC_AGGR_CONTROL_ENABLE_RMW_RESETVAL                (0x00000000U)
#define CSL_ECC_AGGR_CONTROL_ENABLE_RMW_MAX                     (0x00000001U)

#define CSL_ECC_AGGR_CONTROL_ECC_CHECK_MASK                     (0x00000002U)
#define CSL_ECC_AGGR_CONTROL_ECC_CHECK_SHIFT                    (1U)
#define CSL_ECC_AGGR_CONTROL_ECC_CHECK_RESETVAL                 (0x00000000U)
#define CSL_ECC_AGGR_CONTROL_ECC_CHECK_MAX                      (0x00000001U)

#define CSL_ECC_AGGR_CONTROL_ECC_ENABLE_MASK                    (0x00000001U)
#define CSL_ECC_AGGR_CONTROL_ECC_ENABLE_SHIFT                   (0U)
#define CSL_ECC_AGGR_CONTROL_ECC_ENABLE_RESETVAL                (0x00000000U)
#define CSL_ECC_AGGR_CONTROL_ECC_ENABLE_MAX                     (0x00000001U)

#define CSL_ECC_AGGR_CONTROL_RESETVAL                           (0x00000000U)

/* ERROR_CONTROL1 */

#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_BIT1_MASK               (0xFFFF0000U)
#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_BIT1_SHIFT              (16U)
#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_BIT1_RESETVAL           (0x00000000U)
#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_BIT1_MAX                (0x0000ffffU)

#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_ROW_MASK                (0x0000FFFFU)
#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_ROW_SHIFT               (0U)
#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_ROW_RESETVAL            (0x00000000U)
#define CSL_ECC_AGGR_ERROR_CONTROL1_ECC_ROW_MAX                 (0x0000ffffU)

#define CSL_ECC_AGGR_ERROR_CONTROL1_RESETVAL                    (0x00000000U)

/* ERROR_CONTROL2 */

#define CSL_ECC_AGGR_ERROR_CONTROL2_ECC_BIT2_MASK               (0x0000FFFFU)
#define CSL_ECC_AGGR_ERROR_CONTROL2_ECC_BIT2_SHIFT              (0U)
#define CSL_ECC_AGGR_ERROR_CONTROL2_ECC_BIT2_RESETVAL           (0x00000000U)
#define CSL_ECC_AGGR_ERROR_CONTROL2_ECC_BIT2_MAX                (0x0000ffffU)

#define CSL_ECC_AGGR_ERROR_CONTROL2_RESETVAL                    (0x00000000U)

/* ERROR_STATUS1 */

#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_ROW_MASK                 (0xFFFF0000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_ROW_SHIFT                (16U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_ROW_RESETVAL             (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_ROW_MAX                  (0x0000ffffU)

#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_OTHER_MASK           (0x00000400U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_OTHER_SHIFT          (10U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_OTHER_RESETVAL       (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_OTHER_MAX            (0x00000001U)

#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_DED_MASK             (0x00000200U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_DED_SHIFT            (9U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_DED_RESETVAL         (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_DED_MAX              (0x00000001U)

#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_SEC_MASK             (0x00000100U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_SEC_SHIFT            (8U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_SEC_RESETVAL         (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_CLR_ECC_SEC_MAX              (0x00000001U)

#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_OTHER_MASK               (0x00000004U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_OTHER_SHIFT              (2U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_OTHER_RESETVAL           (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_OTHER_MAX                (0x00000001U)

#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_DED_MASK                 (0x00000002U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_DED_SHIFT                (1U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_DED_RESETVAL             (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_DED_MAX                  (0x00000001U)

#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_SEC_MASK                 (0x00000001U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_SEC_SHIFT                (0U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_SEC_RESETVAL             (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS1_ECC_SEC_MAX                  (0x00000001U)

#define CSL_ECC_AGGR_ERROR_STATUS1_RESETVAL                     (0x00000000U)

/* ERROR_STATUS2 */

#define CSL_ECC_AGGR_ERROR_STATUS2_ECC_BIT1_MASK                (0x0000FFFFU)
#define CSL_ECC_AGGR_ERROR_STATUS2_ECC_BIT1_SHIFT               (0U)
#define CSL_ECC_AGGR_ERROR_STATUS2_ECC_BIT1_RESETVAL            (0x00000000U)
#define CSL_ECC_AGGR_ERROR_STATUS2_ECC_BIT1_MAX                 (0x0000ffffU)

#define CSL_ECC_AGGR_ERROR_STATUS2_RESETVAL                     (0x00000000U)

/* EOI */

#define CSL_ECC_AGGR_EOI_EOI_WR_MASK                            (0x00000001U)
#define CSL_ECC_AGGR_EOI_EOI_WR_SHIFT                           (0U)
#define CSL_ECC_AGGR_EOI_EOI_WR_RESETVAL                        (0x00000000U)
#define CSL_ECC_AGGR_EOI_EOI_WR_MAX                             (0x00000001U)

#define CSL_ECC_AGGR_EOI_RESETVAL                               (0x00000000U)

/* INT_STATUS */

#define CSL_ECC_AGGR_INT_STATUS_BITMASK_MASK                    (0xFFFFFFFFU)
#define CSL_ECC_AGGR_INT_STATUS_BITMASK_SHIFT                   (0U)
#define CSL_ECC_AGGR_INT_STATUS_BITMASK_RESETVAL                (0x00000000U)
#define CSL_ECC_AGGR_INT_STATUS_BITMASK_MAX                     (0xffffffffU)

#define CSL_ECC_AGGR_INT_STATUS_RESETVAL                        (0x00000000U)

/* INT_ENABLE */

#define CSL_ECC_AGGR_INT_ENABLE_BITMASK_MASK                    (0xFFFFFFFFU)
#define CSL_ECC_AGGR_INT_ENABLE_BITMASK_SHIFT                   (0U)
#define CSL_ECC_AGGR_INT_ENABLE_BITMASK_RESETVAL                (0x00000000U)
#define CSL_ECC_AGGR_INT_ENABLE_BITMASK_MAX                     (0xffffffffU)

#define CSL_ECC_AGGR_INT_ENABLE_RESETVAL                        (0x00000000U)

/* INT_CLEAR */

#define CSL_ECC_AGGR_INT_CLEAR_BITMASK_MASK                     (0xFFFFFFFFU)
#define CSL_ECC_AGGR_INT_CLEAR_BITMASK_SHIFT                    (0U)
#define CSL_ECC_AGGR_INT_CLEAR_BITMASK_RESETVAL                 (0x00000000U)
#define CSL_ECC_AGGR_INT_CLEAR_BITMASK_MAX                      (0xffffffffU)

#define CSL_ECC_AGGR_INT_CLEAR_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
