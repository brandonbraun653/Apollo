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
#ifndef CSLR_MSGMGRGLOBAL_H_
#define CSLR_MSGMGRGLOBAL_H_

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
    volatile Uint32 REVISION_REG;
    volatile Uint8  RSVD0[12];
    volatile Uint32 INTR_RAW_STATUS_SET_REG;
    volatile Uint32 INTR_ENABLED_STATUS_SET_REG;
    volatile Uint32 INTR_ENABLE_REG;
    volatile Uint32 INTR_CLEAR_REG;
    volatile Uint32 EOI_REG;
} CSL_MsgmgrGlobalRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* The Revision register provides revision details of the module. */
#define CSL_MSGMGRGLOBAL_REVISION_REG                           (0x0U)

/* The Interrupt Raw Status/Set register shows the raw interrupt status before
 * enabling and allows for setting of the interrupt status. Bit 0 indicates
 * that there is no free index available. This should only happen if more than
 * max_messages (configured for the design) are queued. */
#define CSL_MSGMGRGLOBAL_INTR_RAW_STATUS_SET_REG                (0x10U)

/* The Interrupt Enabled Status/Set register shows the interrupt enabled
 * status and allows clearing the interrupt status. Bit 0 indicates that there
 * is no free index available. This should only happen if more than
 * max_messages (configured for the design) are queued. */
#define CSL_MSGMGRGLOBAL_INTR_ENABLED_STATUS_SET_REG            (0x14U)

/* The Interrupt Enable register allows setting the interrupt enable. Bit 0
 * corresponds to the free index error interrupt. */
#define CSL_MSGMGRGLOBAL_INTR_ENABLE_REG                        (0x18U)

/* The Interrupt Clear register allows clearing the interrupt enable. Bit 0
 * corresponds to the free index error interrupt. */
#define CSL_MSGMGRGLOBAL_INTR_CLEAR_REG                         (0x1CU)

/* The EOI register is used by software to write a vector associated with each
 * interrupt to indicate that the interrupt has been serviced. */
#define CSL_MSGMGRGLOBAL_EOI_REG                                (0x20U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION_REG */

#define CSL_MSGMGRGLOBAL_REVISION_REG_SCHEME_MASK               (0xC0000000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_SCHEME_SHIFT              (30U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_SCHEME_RESETVAL           (0x00000000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_SCHEME_MAX                (0x00000003U)

#define CSL_MSGMGRGLOBAL_REVISION_REG_FUNCTION_MASK             (0x0FFF0000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_FUNCTION_SHIFT            (16U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_FUNCTION_RESETVAL         (0x00000000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_FUNCTION_MAX              (0x00000fffU)

#define CSL_MSGMGRGLOBAL_REVISION_REG_REVRTL_MASK               (0x0000F800U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVRTL_SHIFT              (11U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVRTL_RESETVAL           (0x00000000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVRTL_MAX                (0x0000001fU)

#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMAJ_MASK               (0x00000700U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMAJ_SHIFT              (8U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMAJ_RESETVAL           (0x00000000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMAJ_MAX                (0x00000007U)

#define CSL_MSGMGRGLOBAL_REVISION_REG_REVCUSTOM_MASK            (0x000000C0U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVCUSTOM_SHIFT           (6U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVCUSTOM_RESETVAL        (0x00000000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVCUSTOM_MAX             (0x00000003U)

#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMIN_MASK               (0x0000003FU)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMIN_SHIFT              (0U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMIN_RESETVAL           (0x00000000U)
#define CSL_MSGMGRGLOBAL_REVISION_REG_REVMIN_MAX                (0x0000003fU)

#define CSL_MSGMGRGLOBAL_REVISION_REG_RESETVAL                  (0x00000000U)

/* INTR_RAW_STATUS_SET_REG */

#define CSL_MSGMGRGLOBAL_INTR_RAW_STATUS_SET_REG_FREE_INDEX_ERROR_MASK  (0x00000001U)
#define CSL_MSGMGRGLOBAL_INTR_RAW_STATUS_SET_REG_FREE_INDEX_ERROR_SHIFT  (0U)
#define CSL_MSGMGRGLOBAL_INTR_RAW_STATUS_SET_REG_FREE_INDEX_ERROR_RESETVAL  (0x00000000U)
#define CSL_MSGMGRGLOBAL_INTR_RAW_STATUS_SET_REG_FREE_INDEX_ERROR_MAX  (0x00000001U)

#define CSL_MSGMGRGLOBAL_INTR_RAW_STATUS_SET_REG_RESETVAL       (0x00000000U)

/* INTR_ENABLED_STATUS_SET_REG */

#define CSL_MSGMGRGLOBAL_INTR_ENABLED_STATUS_SET_REG_FREE_INDEX_ERROR_MASK  (0x00000001U)
#define CSL_MSGMGRGLOBAL_INTR_ENABLED_STATUS_SET_REG_FREE_INDEX_ERROR_SHIFT  (0U)
#define CSL_MSGMGRGLOBAL_INTR_ENABLED_STATUS_SET_REG_FREE_INDEX_ERROR_RESETVAL  (0x00000000U)
#define CSL_MSGMGRGLOBAL_INTR_ENABLED_STATUS_SET_REG_FREE_INDEX_ERROR_MAX  (0x00000001U)

#define CSL_MSGMGRGLOBAL_INTR_ENABLED_STATUS_SET_REG_RESETVAL   (0x00000000U)

/* INTR_ENABLE_REG */

#define CSL_MSGMGRGLOBAL_INTR_ENABLE_REG_FREE_INDEX_ERROR_MASK  (0x00000001U)
#define CSL_MSGMGRGLOBAL_INTR_ENABLE_REG_FREE_INDEX_ERROR_SHIFT  (0U)
#define CSL_MSGMGRGLOBAL_INTR_ENABLE_REG_FREE_INDEX_ERROR_RESETVAL  (0x00000000U)
#define CSL_MSGMGRGLOBAL_INTR_ENABLE_REG_FREE_INDEX_ERROR_MAX   (0x00000001U)

#define CSL_MSGMGRGLOBAL_INTR_ENABLE_REG_RESETVAL               (0x00000000U)

/* INTR_CLEAR_REG */

#define CSL_MSGMGRGLOBAL_INTR_CLEAR_REG_FREE_INDEX_ERROR_MASK   (0x00000001U)
#define CSL_MSGMGRGLOBAL_INTR_CLEAR_REG_FREE_INDEX_ERROR_SHIFT  (0U)
#define CSL_MSGMGRGLOBAL_INTR_CLEAR_REG_FREE_INDEX_ERROR_RESETVAL  (0x00000000U)
#define CSL_MSGMGRGLOBAL_INTR_CLEAR_REG_FREE_INDEX_ERROR_MAX    (0x00000001U)

#define CSL_MSGMGRGLOBAL_INTR_CLEAR_REG_RESETVAL                (0x00000000U)

/* EOI_REG */

#define CSL_MSGMGRGLOBAL_EOI_REG_VECTOR_MASK                    (0x000000FFU)
#define CSL_MSGMGRGLOBAL_EOI_REG_VECTOR_SHIFT                   (0U)
#define CSL_MSGMGRGLOBAL_EOI_REG_VECTOR_RESETVAL                (0x00000000U)
#define CSL_MSGMGRGLOBAL_EOI_REG_VECTOR_MAX                     (0x000000ffU)

#define CSL_MSGMGRGLOBAL_EOI_REG_RESETVAL                       (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
