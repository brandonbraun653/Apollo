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
#ifndef CSLR_ILF3_H_
#define CSLR_ILF3_H_

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
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 IRQ_EOI;
    volatile Uint32 IRQSTS_RAW_0;
    volatile Uint32 IRQSTS_0;
    volatile Uint32 IRQEN_SET_0;
    volatile Uint32 IRQEN_CLR_0;
    volatile Uint8  RSVD2[4];
    volatile Uint32 CONFIG;
    volatile Uint32 STS;
    volatile Uint32 MBCONFIG_SLICEINFO01;
    volatile Uint32 MBCONFIG_SLICEINFO2;
    volatile Uint32 MBCONFIG_MBINFO[3];
    volatile Uint32 MBCONFIG_MB[16];
    volatile Uint32 MBCONFIG_COEFFICIENTS0123;
    volatile Uint32 MBCONFIG_COEFFICIENTS4567;
    volatile Uint32 MBCONFIG_GDPCONFIG[4];
    volatile Uint8  RSVD3[12];
    volatile Uint32 MBCONFIG_AUTOINC;
    volatile Uint32 MBCONFIG_NEXTMBCONFIG;
    volatile Uint32 MBSTS;
    volatile Uint32 SLICESTS[3];
    volatile Uint8  RSVD4[24];
    volatile Uint32 QP[18];
    volatile Uint32 QP_IDX[40];
    volatile Uint32 BS[149];
    volatile Uint32 IPB[704];
    volatile Uint8  RSVD5[224];
    volatile Uint32 COMMAND;
} CSL_Ilf3Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier (X.Y.R) Used by software to track features, bugs,
 * and compatibility */
#define CSL_ILF3_REVISION                                       (0x0U)

/* Clock management configuration */
#define CSL_ILF3_SYSCONFIG                                      (0x10U)

/* End Of Interrupt number specification */
#define CSL_ILF3_IRQ_EOI                                        (0x18U)

/* Per-event raw interrupt status vector, line #0. Raw status is set even if
 * event is not enabled. Write 1 to set the (raw) status, mostly for debug. */
#define CSL_ILF3_IRQSTS_RAW_0                                   (0x1CU)

/* Per-event "enabled" interrupt status vector, line #0. Enabled status isn't
 * set unless event is enabled. Write 1 to clear the status after interrupt
 * has been serviced (raw status gets cleared, i.e. even if not enabled). */
#define CSL_ILF3_IRQSTS_0                                       (0x20U)

/* Per-event interrupt enable bit vector, line #0. Write 1 to set (enable
 * interrupt). Readout equal to corresponding _CLR register. */
#define CSL_ILF3_IRQEN_SET_0                                    (0x24U)

/* Per-event interrupt enable bit vector, line #0. Write 1 to clear (disable
 * interrupt). Readout equal to corresponding _SET register. */
#define CSL_ILF3_IRQEN_CLR_0                                    (0x28U)

/* Configuration register. */
#define CSL_ILF3_CONFIG                                         (0x30U)

/* Provides information on the progress of the iLF3 execution. */
#define CSL_ILF3_STS                                            (0x34U)

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_SLICEINFO01                           (0x38U)

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_SLICEINFO2                            (0x3CU)

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_MBINFO(i)                             (0x40U + ((i) * (0x4U)))

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_MB(i)                                 (0x4CU + ((i) * (0x4U)))

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123                      (0x8CU)

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567                      (0x90U)

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_GDPCONFIG(i)                          (0x94U + ((i) * (0x4U)))

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_AUTOINC                               (0xB0U)

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_MBCONFIG_NEXTMBCONFIG                          (0xB4U)

/* Provides MB properties. */
#define CSL_ILF3_MBSTS                                          (0xB8U)

/* MBConfig table contains pointers used by program to control the iLF units. */
#define CSL_ILF3_SLICESTS(i)                                    (0xBCU + ((i) * (0x4U)))

/* Quantization parameter. */
#define CSL_ILF3_QP(i)                                          (0xE0U + ((i) * (0x4U)))

/* Quantization parameter index. */
#define CSL_ILF3_QP_IDX(i)                                      (0x128U + ((i) * (0x4U)))

/* Boundary strength. */
#define CSL_ILF3_BS(i)                                          (0x1C8U + ((i) * (0x4U)))

/* Input buffer bank. */
#define CSL_ILF3_IPB(i)                                         (0x41CU + ((i) * (0x4U)))

/* iLF3 command register: a write to this register decodes a command.
 * DATA/COMMAND 0x1 -> Start() 0x2 -> Stop() 0x3 -> DbgEn() 0x4 -> DbgDis()
 * 0x5 -> DbgStep() */
#define CSL_ILF3_COMMAND                                        (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_ILF3_REVISION_Y_MINOR_MASK                          (0x0000003FU)
#define CSL_ILF3_REVISION_Y_MINOR_SHIFT                         (0U)
#define CSL_ILF3_REVISION_Y_MINOR_RESETVAL                      (0x00000000U)
#define CSL_ILF3_REVISION_Y_MINOR_MAX                           (0x0000003fU)

#define CSL_ILF3_REVISION_CUSTOM_MASK                           (0x000000C0U)
#define CSL_ILF3_REVISION_CUSTOM_SHIFT                          (6U)
#define CSL_ILF3_REVISION_CUSTOM_RESETVAL                       (0x00000000U)
#define CSL_ILF3_REVISION_CUSTOM_STANDARD                       (0x00000000U)

#define CSL_ILF3_REVISION_X_MAJOR_MASK                          (0x00000700U)
#define CSL_ILF3_REVISION_X_MAJOR_SHIFT                         (8U)
#define CSL_ILF3_REVISION_X_MAJOR_RESETVAL                      (0x00000001U)
#define CSL_ILF3_REVISION_X_MAJOR_MAX                           (0x00000007U)

#define CSL_ILF3_REVISION_R_RTL_MASK                            (0x0000F800U)
#define CSL_ILF3_REVISION_R_RTL_SHIFT                           (11U)
#define CSL_ILF3_REVISION_R_RTL_RESETVAL                        (0x00000000U)
#define CSL_ILF3_REVISION_R_RTL_MAX                             (0x0000001fU)

#define CSL_ILF3_REVISION_FUNC_MASK                             (0x0FFF0000U)
#define CSL_ILF3_REVISION_FUNC_SHIFT                            (16U)
#define CSL_ILF3_REVISION_FUNC_RESETVAL                         (0x00000000U)
#define CSL_ILF3_REVISION_FUNC_MAX                              (0x00000fffU)

#define CSL_ILF3_REVISION_SCHEME_MASK                           (0xC0000000U)
#define CSL_ILF3_REVISION_SCHEME_SHIFT                          (30U)
#define CSL_ILF3_REVISION_SCHEME_RESETVAL                       (0x00000000U)
#define CSL_ILF3_REVISION_SCHEME_H08                            (0x00000001U)
#define CSL_ILF3_REVISION_SCHEME_LEGACY                         (0x00000000U)

#define CSL_ILF3_REVISION_RESETVAL                              (0x00000100U)

/* SYSCONFIG */

#define CSL_ILF3_SYSCONFIG_SOFTRESET_MASK                       (0x00000001U)
#define CSL_ILF3_SYSCONFIG_SOFTRESET_SHIFT                      (0U)
#define CSL_ILF3_SYSCONFIG_SOFTRESET_RESETVAL                   (0x00000000U)
#define CSL_ILF3_SYSCONFIG_SOFTRESET_DONE                       (0x00000000U)
#define CSL_ILF3_SYSCONFIG_SOFTRESET_PENDING                    (0x00000001U)
#define CSL_ILF3_SYSCONFIG_SOFTRESET_NOACTION                   (0x00000000U)
#define CSL_ILF3_SYSCONFIG_SOFTRESET_RESET                      (0x00000001U)

#define CSL_ILF3_SYSCONFIG_IDLEMODE_MASK                        (0x0000000CU)
#define CSL_ILF3_SYSCONFIG_IDLEMODE_SHIFT                       (2U)
#define CSL_ILF3_SYSCONFIG_IDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_ILF3_SYSCONFIG_IDLEMODE_FORCE                       (0x00000000U)
#define CSL_ILF3_SYSCONFIG_IDLEMODE_NO                          (0x00000001U)
#define CSL_ILF3_SYSCONFIG_IDLEMODE_SMART                       (0x00000002U)
#define CSL_ILF3_SYSCONFIG_IDLEMODE_SMARTWAKEUP                 (0x00000003U)

#define CSL_ILF3_SYSCONFIG_RESETVAL                             (0x00000008U)

/* IRQ_EOI */

#define CSL_ILF3_IRQ_EOI_LINE_NUMBER_MASK                       (0x00000001U)
#define CSL_ILF3_IRQ_EOI_LINE_NUMBER_SHIFT                      (0U)
#define CSL_ILF3_IRQ_EOI_LINE_NUMBER_RESETVAL                   (0x00000000U)
#define CSL_ILF3_IRQ_EOI_LINE_NUMBER_READ0                      (0x00000000U)
#define CSL_ILF3_IRQ_EOI_LINE_NUMBER_EOI0                       (0x00000000U)
#define CSL_ILF3_IRQ_EOI_LINE_NUMBER_EOI1                       (0x00000001U)

#define CSL_ILF3_IRQ_EOI_RESETVAL                               (0x00000000U)

/* IRQSTS_RAW_0 */

#define CSL_ILF3_IRQSTS_RAW_0_EVT0_MASK                         (0x00000001U)
#define CSL_ILF3_IRQSTS_RAW_0_EVT0_SHIFT                        (0U)
#define CSL_ILF3_IRQSTS_RAW_0_EVT0_RESETVAL                     (0x00000000U)
#define CSL_ILF3_IRQSTS_RAW_0_EVT0_NOACTION                     (0x00000000U)
#define CSL_ILF3_IRQSTS_RAW_0_EVT0_SET                          (0x00000001U)
#define CSL_ILF3_IRQSTS_RAW_0_EVT0_NOEVENT                      (0x00000000U)
#define CSL_ILF3_IRQSTS_RAW_0_EVT0_PENDING                      (0x00000001U)

#define CSL_ILF3_IRQSTS_RAW_0_RESETVAL                          (0x00000000U)

/* IRQSTS_0 */

#define CSL_ILF3_IRQSTS_0_EVT0_MASK                             (0x00000001U)
#define CSL_ILF3_IRQSTS_0_EVT0_SHIFT                            (0U)
#define CSL_ILF3_IRQSTS_0_EVT0_RESETVAL                         (0x00000000U)
#define CSL_ILF3_IRQSTS_0_EVT0_NOACTION                         (0x00000000U)
#define CSL_ILF3_IRQSTS_0_EVT0_CLEAR                            (0x00000001U)
#define CSL_ILF3_IRQSTS_0_EVT0_NOEVENT                          (0x00000000U)
#define CSL_ILF3_IRQSTS_0_EVT0_PENDING                          (0x00000001U)

#define CSL_ILF3_IRQSTS_0_RESETVAL                              (0x00000000U)

/* IRQEN_SET_0 */

#define CSL_ILF3_IRQEN_SET_0_EN0_MASK                           (0x00000001U)
#define CSL_ILF3_IRQEN_SET_0_EN0_SHIFT                          (0U)
#define CSL_ILF3_IRQEN_SET_0_EN0_RESETVAL                       (0x00000000U)
#define CSL_ILF3_IRQEN_SET_0_EN0_NOACTION                       (0x00000000U)
#define CSL_ILF3_IRQEN_SET_0_EN0_ENABLE                         (0x00000001U)
#define CSL_ILF3_IRQEN_SET_0_EN0_DISABLED                       (0x00000000U)
#define CSL_ILF3_IRQEN_SET_0_EN0_ENABLED                        (0x00000001U)

#define CSL_ILF3_IRQEN_SET_0_RESETVAL                           (0x00000000U)

/* IRQEN_CLR_0 */

#define CSL_ILF3_IRQEN_CLR_0_EN0_MASK                           (0x00000001U)
#define CSL_ILF3_IRQEN_CLR_0_EN0_SHIFT                          (0U)
#define CSL_ILF3_IRQEN_CLR_0_EN0_RESETVAL                       (0x00000000U)
#define CSL_ILF3_IRQEN_CLR_0_EN0_NOACTION                       (0x00000000U)
#define CSL_ILF3_IRQEN_CLR_0_EN0_DISABLE                        (0x00000001U)
#define CSL_ILF3_IRQEN_CLR_0_EN0_DISABLED                       (0x00000000U)
#define CSL_ILF3_IRQEN_CLR_0_EN0_ENABLED                        (0x00000001U)

#define CSL_ILF3_IRQEN_CLR_0_RESETVAL                           (0x00000000U)

/* CONFIG */

#define CSL_ILF3_CONFIG_MBINFO_SIZE_MASK                        (0x00060000U)
#define CSL_ILF3_CONFIG_MBINFO_SIZE_SHIFT                       (17U)
#define CSL_ILF3_CONFIG_MBINFO_SIZE_RESETVAL                    (0x00000000U)
#define CSL_ILF3_CONFIG_MBINFO_SIZE_E1                          (0x00000000U)
#define CSL_ILF3_CONFIG_MBINFO_SIZE_E2                          (0x00000001U)
#define CSL_ILF3_CONFIG_MBINFO_SIZE_E3                          (0x00000002U)
#define CSL_ILF3_CONFIG_MBINFO_SIZE_E4                          (0x00000003U)

#define CSL_ILF3_CONFIG_PPA_TASK_MASK                           (0x0000001FU)
#define CSL_ILF3_CONFIG_PPA_TASK_SHIFT                          (0U)
#define CSL_ILF3_CONFIG_PPA_TASK_RESETVAL                       (0x0000001fU)
#define CSL_ILF3_CONFIG_PPA_TASK_MAX                            (0x0000001fU)

#define CSL_ILF3_CONFIG_CODEC_MASK                              (0x0000FF00U)
#define CSL_ILF3_CONFIG_CODEC_SHIFT                             (8U)
#define CSL_ILF3_CONFIG_CODEC_RESETVAL                          (0x00000000U)
#define CSL_ILF3_CONFIG_CODEC_MAX                               (0x000000ffU)

#define CSL_ILF3_CONFIG_AUTOINCCTR_MASK                         (0xFF000000U)
#define CSL_ILF3_CONFIG_AUTOINCCTR_SHIFT                        (24U)
#define CSL_ILF3_CONFIG_AUTOINCCTR_RESETVAL                     (0x00000000U)
#define CSL_ILF3_CONFIG_AUTOINCCTR_MAX                          (0x000000ffU)

#define CSL_ILF3_CONFIG_IRQAUTOCLR_EN_MASK                      (0x00010000U)
#define CSL_ILF3_CONFIG_IRQAUTOCLR_EN_SHIFT                     (16U)
#define CSL_ILF3_CONFIG_IRQAUTOCLR_EN_RESETVAL                  (0x00000000U)
#define CSL_ILF3_CONFIG_IRQAUTOCLR_EN_MAX                       (0x00000001U)

#define CSL_ILF3_CONFIG_RESETVAL                                (0x0000001fU)

/* STS */

#define CSL_ILF3_STS_EXECSTATE_MASK                             (0x03000000U)
#define CSL_ILF3_STS_EXECSTATE_SHIFT                            (24U)
#define CSL_ILF3_STS_EXECSTATE_RESETVAL                         (0x00000000U)
#define CSL_ILF3_STS_EXECSTATE_E1                               (0x00000000U)
#define CSL_ILF3_STS_EXECSTATE_E2                               (0x00000001U)
#define CSL_ILF3_STS_EXECSTATE_E3                               (0x00000002U)
#define CSL_ILF3_STS_EXECSTATE_E4                               (0x00000003U)

#define CSL_ILF3_STS_WRITEREGERROR_MASK                         (0x08000000U)
#define CSL_ILF3_STS_WRITEREGERROR_SHIFT                        (27U)
#define CSL_ILF3_STS_WRITEREGERROR_RESETVAL                     (0x00000000U)
#define CSL_ILF3_STS_WRITEREGERROR_E1                           (0x00000000U)
#define CSL_ILF3_STS_WRITEREGERROR_E2                           (0x00000001U)

#define CSL_ILF3_STS_CYCLECOUNT_MASK                            (0x0000FFFFU)
#define CSL_ILF3_STS_CYCLECOUNT_SHIFT                           (0U)
#define CSL_ILF3_STS_CYCLECOUNT_RESETVAL                        (0x00000000U)
#define CSL_ILF3_STS_CYCLECOUNT_MAX                             (0x0000ffffU)

#define CSL_ILF3_STS_DBGSTATE_MASK                              (0x04000000U)
#define CSL_ILF3_STS_DBGSTATE_SHIFT                             (26U)
#define CSL_ILF3_STS_DBGSTATE_RESETVAL                          (0x00000000U)
#define CSL_ILF3_STS_DBGSTATE_E1                                (0x00000000U)
#define CSL_ILF3_STS_DBGSTATE_E2                                (0x00000001U)

#define CSL_ILF3_STS_RESETVAL                                   (0x00000000U)

/* MBCONFIG_SLICEINFO01 */

#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO0_MASK           (0x0000FFFFU)
#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO0_SHIFT          (0U)
#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO0_RESETVAL       (0x00000000U)
#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO0_MAX            (0x0000ffffU)

#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO1_MASK           (0xFFFF0000U)
#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO1_SHIFT          (16U)
#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO1_RESETVAL       (0x00000000U)
#define CSL_ILF3_MBCONFIG_SLICEINFO01_SLICEINFO1_MAX            (0x0000ffffU)

#define CSL_ILF3_MBCONFIG_SLICEINFO01_RESETVAL                  (0x00000000U)

/* MBCONFIG_SLICEINFO2 */

#define CSL_ILF3_MBCONFIG_SLICEINFO2_MBCONFIG_ADDR_SLICEINFO2_MASK  (0x0000FFFFU)
#define CSL_ILF3_MBCONFIG_SLICEINFO2_MBCONFIG_ADDR_SLICEINFO2_SHIFT  (0U)
#define CSL_ILF3_MBCONFIG_SLICEINFO2_MBCONFIG_ADDR_SLICEINFO2_RESETVAL  (0x00000000U)
#define CSL_ILF3_MBCONFIG_SLICEINFO2_MBCONFIG_ADDR_SLICEINFO2_MAX  (0x0000ffffU)

#define CSL_ILF3_MBCONFIG_SLICEINFO2_RESETVAL                   (0x00000000U)

/* MBCONFIG_MBINFO */

#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_LOW_MASK         (0x0000FFFFU)
#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_LOW_SHIFT        (0U)
#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_LOW_RESETVAL     (0x00000000U)
#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_LOW_MAX          (0x0000ffffU)

#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_HIGH_MASK        (0xFFFF0000U)
#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_HIGH_SHIFT       (16U)
#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_HIGH_RESETVAL    (0x00000000U)
#define CSL_ILF3_MBCONFIG_MBINFO_MBCONFIG_ADDR_HIGH_MAX         (0x0000ffffU)

#define CSL_ILF3_MBCONFIG_MBINFO_RESETVAL                       (0x00000000U)

/* MBCONFIG_MB */

#define CSL_ILF3_MBCONFIG_MB_LUMA_CHROMA_ADDR_MASK              (0x0000FFFFU)
#define CSL_ILF3_MBCONFIG_MB_LUMA_CHROMA_ADDR_SHIFT             (0U)
#define CSL_ILF3_MBCONFIG_MB_LUMA_CHROMA_ADDR_RESETVAL          (0x00000000U)
#define CSL_ILF3_MBCONFIG_MB_LUMA_CHROMA_ADDR_MAX               (0x0000ffffU)

#define CSL_ILF3_MBCONFIG_MB_STRIDE_MASK                        (0x007F0000U)
#define CSL_ILF3_MBCONFIG_MB_STRIDE_SHIFT                       (16U)
#define CSL_ILF3_MBCONFIG_MB_STRIDE_RESETVAL                    (0x00000000U)
#define CSL_ILF3_MBCONFIG_MB_STRIDE_MAX                         (0x0000007fU)

#define CSL_ILF3_MBCONFIG_MB_SHIFT_OR_WE_MASK                   (0x07800000U)
#define CSL_ILF3_MBCONFIG_MB_SHIFT_OR_WE_SHIFT                  (23U)
#define CSL_ILF3_MBCONFIG_MB_SHIFT_OR_WE_RESETVAL               (0x00000000U)
#define CSL_ILF3_MBCONFIG_MB_SHIFT_OR_WE_MAX                    (0x0000000fU)

#define CSL_ILF3_MBCONFIG_MB_RESETVAL                           (0x00000000U)

/* MBCONFIG_COEFFICIENTS0123 */

#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF0_MASK          (0x000000FFU)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF0_SHIFT         (0U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF0_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF0_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF1_MASK          (0x0000FF00U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF1_SHIFT         (8U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF1_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF1_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF2_MASK          (0x00FF0000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF2_SHIFT         (16U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF2_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF2_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF3_MASK          (0xFF000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF3_SHIFT         (24U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF3_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_COEFF3_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS0123_RESETVAL             (0x00000000U)

/* MBCONFIG_COEFFICIENTS4567 */

#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF4_MASK          (0x000000FFU)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF4_SHIFT         (0U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF4_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF4_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF5_MASK          (0x0000FF00U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF5_SHIFT         (8U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF5_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF5_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF6_MASK          (0x00FF0000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF6_SHIFT         (16U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF6_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF6_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF7_MASK          (0xFF000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF7_SHIFT         (24U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF7_RESETVAL      (0x00000000U)
#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_COEFF7_MAX           (0x000000ffU)

#define CSL_ILF3_MBCONFIG_COEFFICIENTS4567_RESETVAL             (0x00000000U)

/* MBCONFIG_GDPCONFIG */

#define CSL_ILF3_MBCONFIG_GDPCONFIG_COEFFCONFIG_MASK            (0x00FFFFFFU)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_COEFFCONFIG_SHIFT           (0U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_COEFFCONFIG_RESETVAL        (0x00000000U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_COEFFCONFIG_MAX             (0x00ffffffU)

#define CSL_ILF3_MBCONFIG_GDPCONFIG_RIGHT_SHIFT_MASK            (0x07000000U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_RIGHT_SHIFT_SHIFT           (24U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_RIGHT_SHIFT_RESETVAL        (0x00000000U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_RIGHT_SHIFT_MAX             (0x00000007U)

#define CSL_ILF3_MBCONFIG_GDPCONFIG_RND_MASK                    (0x78000000U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_RND_SHIFT                   (27U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_RND_RESETVAL                (0x00000000U)
#define CSL_ILF3_MBCONFIG_GDPCONFIG_RND_MAX                     (0x0000000fU)

#define CSL_ILF3_MBCONFIG_GDPCONFIG_RESETVAL                    (0x00000000U)

/* MBCONFIG_AUTOINC */

#define CSL_ILF3_MBCONFIG_AUTOINC_MAX_COUNT_MASK                (0x000000FFU)
#define CSL_ILF3_MBCONFIG_AUTOINC_MAX_COUNT_SHIFT               (0U)
#define CSL_ILF3_MBCONFIG_AUTOINC_MAX_COUNT_RESETVAL            (0x00000000U)
#define CSL_ILF3_MBCONFIG_AUTOINC_MAX_COUNT_MAX                 (0x000000ffU)

#define CSL_ILF3_MBCONFIG_AUTOINC_PIXEL_FMT_MASK                (0x00000700U)
#define CSL_ILF3_MBCONFIG_AUTOINC_PIXEL_FMT_SHIFT               (8U)
#define CSL_ILF3_MBCONFIG_AUTOINC_PIXEL_FMT_RESETVAL            (0x00000000U)
#define CSL_ILF3_MBCONFIG_AUTOINC_PIXEL_FMT_MAX                 (0x00000007U)

#define CSL_ILF3_MBCONFIG_AUTOINC_AUTOINC_MASK                  (0x00000800U)
#define CSL_ILF3_MBCONFIG_AUTOINC_AUTOINC_SHIFT                 (11U)
#define CSL_ILF3_MBCONFIG_AUTOINC_AUTOINC_RESETVAL              (0x00000000U)
#define CSL_ILF3_MBCONFIG_AUTOINC_AUTOINC_MAX                   (0x00000001U)

#define CSL_ILF3_MBCONFIG_AUTOINC_RESETVAL                      (0x00000000U)

/* MBCONFIG_NEXTMBCONFIG */

#define CSL_ILF3_MBCONFIG_NEXTMBCONFIG_NEXTMBCONFIGADDR_MASK    (0x0000FFFFU)
#define CSL_ILF3_MBCONFIG_NEXTMBCONFIG_NEXTMBCONFIGADDR_SHIFT   (0U)
#define CSL_ILF3_MBCONFIG_NEXTMBCONFIG_NEXTMBCONFIGADDR_RESETVAL  (0x00000000U)
#define CSL_ILF3_MBCONFIG_NEXTMBCONFIG_NEXTMBCONFIGADDR_MAX     (0x0000ffffU)

#define CSL_ILF3_MBCONFIG_NEXTMBCONFIG_RESETVAL                 (0x00000000U)

/* MBSTS */

#define CSL_ILF3_MBSTS_LEFT_FIELD_MASK                          (0x00100000U)
#define CSL_ILF3_MBSTS_LEFT_FIELD_SHIFT                         (20U)
#define CSL_ILF3_MBSTS_LEFT_FIELD_RESETVAL                      (0x00000000U)
#define CSL_ILF3_MBSTS_LEFT_FIELD_E1                            (0x00000000U)
#define CSL_ILF3_MBSTS_LEFT_FIELD_E2                            (0x00000001U)

#define CSL_ILF3_MBSTS_LOAD_SLICEINFO_MASK                      (0x00000100U)
#define CSL_ILF3_MBSTS_LOAD_SLICEINFO_SHIFT                     (8U)
#define CSL_ILF3_MBSTS_LOAD_SLICEINFO_RESETVAL                  (0x00000001U)
#define CSL_ILF3_MBSTS_LOAD_SLICEINFO_E1                        (0x00000000U)
#define CSL_ILF3_MBSTS_LOAD_SLICEINFO_E2                        (0x00000001U)

#define CSL_ILF3_MBSTS_PPA_TASK_STS_MASK                        (0x0000001FU)
#define CSL_ILF3_MBSTS_PPA_TASK_STS_SHIFT                       (0U)
#define CSL_ILF3_MBSTS_PPA_TASK_STS_RESETVAL                    (0x00000000U)
#define CSL_ILF3_MBSTS_PPA_TASK_STS_MAX                         (0x0000001fU)

#define CSL_ILF3_MBSTS_TOP_FIELD_MASK                           (0x00200000U)
#define CSL_ILF3_MBSTS_TOP_FIELD_SHIFT                          (21U)
#define CSL_ILF3_MBSTS_TOP_FIELD_RESETVAL                       (0x00000000U)
#define CSL_ILF3_MBSTS_TOP_FIELD_E1                             (0x00000000U)
#define CSL_ILF3_MBSTS_TOP_FIELD_E2                             (0x00000001U)

#define CSL_ILF3_MBSTS_ALT_H_MASK                               (0x00010000U)
#define CSL_ILF3_MBSTS_ALT_H_SHIFT                              (16U)
#define CSL_ILF3_MBSTS_ALT_H_RESETVAL                           (0x00000000U)
#define CSL_ILF3_MBSTS_ALT_H_E1                                 (0x00000000U)
#define CSL_ILF3_MBSTS_ALT_H_E2                                 (0x00000001U)

#define CSL_ILF3_MBSTS_ALT_V_MASK                               (0x00060000U)
#define CSL_ILF3_MBSTS_ALT_V_SHIFT                              (17U)
#define CSL_ILF3_MBSTS_ALT_V_RESETVAL                           (0x00000000U)
#define CSL_ILF3_MBSTS_ALT_V_E1                                 (0x00000000U)
#define CSL_ILF3_MBSTS_ALT_V_E2                                 (0x00000001U)
#define CSL_ILF3_MBSTS_ALT_V_E3                                 (0x00000002U)
#define CSL_ILF3_MBSTS_ALT_V_E4                                 (0x00000003U)

#define CSL_ILF3_MBSTS_TOP_LEFT_FIELD_MASK                      (0x00400000U)
#define CSL_ILF3_MBSTS_TOP_LEFT_FIELD_SHIFT                     (22U)
#define CSL_ILF3_MBSTS_TOP_LEFT_FIELD_RESETVAL                  (0x00000000U)
#define CSL_ILF3_MBSTS_TOP_LEFT_FIELD_E1                        (0x00000000U)
#define CSL_ILF3_MBSTS_TOP_LEFT_FIELD_E2                        (0x00000001U)

#define CSL_ILF3_MBSTS_CUR_FIELD_MASK                           (0x00080000U)
#define CSL_ILF3_MBSTS_CUR_FIELD_SHIFT                          (19U)
#define CSL_ILF3_MBSTS_CUR_FIELD_RESETVAL                       (0x00000000U)
#define CSL_ILF3_MBSTS_CUR_FIELD_E1                             (0x00000000U)
#define CSL_ILF3_MBSTS_CUR_FIELD_E2                             (0x00000001U)

#define CSL_ILF3_MBSTS_COMPONENT_MASK                           (0x01800000U)
#define CSL_ILF3_MBSTS_COMPONENT_SHIFT                          (23U)
#define CSL_ILF3_MBSTS_COMPONENT_RESETVAL                       (0x00000000U)
#define CSL_ILF3_MBSTS_COMPONENT_MAX                            (0x00000003U)

#define CSL_ILF3_MBSTS_ISFIRSTMB_MASK                           (0x02000000U)
#define CSL_ILF3_MBSTS_ISFIRSTMB_SHIFT                          (25U)
#define CSL_ILF3_MBSTS_ISFIRSTMB_RESETVAL                       (0x00000001U)
#define CSL_ILF3_MBSTS_ISFIRSTMB_E1                             (0x00000000U)
#define CSL_ILF3_MBSTS_ISFIRSTMB_E2                             (0x00000001U)

#define CSL_ILF3_MBSTS_RESETVAL                                 (0x02000100U)

/* SLICESTS */

#define CSL_ILF3_SLICESTS_SLICEINFO_MASK                        (0xFFFFFFFFU)
#define CSL_ILF3_SLICESTS_SLICEINFO_SHIFT                       (0U)
#define CSL_ILF3_SLICESTS_SLICEINFO_RESETVAL                    (0x00000000U)
#define CSL_ILF3_SLICESTS_SLICEINFO_MAX                         (0xffffffffU)

#define CSL_ILF3_SLICESTS_RESETVAL                              (0x00000000U)

/* QP */

#define CSL_ILF3_QP_QP_MASK                                     (0x0000003FU)
#define CSL_ILF3_QP_QP_SHIFT                                    (0U)
#define CSL_ILF3_QP_QP_RESETVAL                                 (0x00000000U)
#define CSL_ILF3_QP_QP_MAX                                      (0x0000003fU)

#define CSL_ILF3_QP_RESETVAL                                    (0x00000000U)

/* QP_IDX */

#define CSL_ILF3_QP_IDX_QP_IDX_MASK                             (0x00000007U)
#define CSL_ILF3_QP_IDX_QP_IDX_SHIFT                            (0U)
#define CSL_ILF3_QP_IDX_QP_IDX_RESETVAL                         (0x00000000U)
#define CSL_ILF3_QP_IDX_QP_IDX_MAX                              (0x00000007U)

#define CSL_ILF3_QP_IDX_RESETVAL                                (0x00000000U)

/* BS */

#define CSL_ILF3_BS_BS_MASK                                     (0x0000000FU)
#define CSL_ILF3_BS_BS_SHIFT                                    (0U)
#define CSL_ILF3_BS_BS_RESETVAL                                 (0x00000000U)
#define CSL_ILF3_BS_BS_MAX                                      (0x0000000fU)

#define CSL_ILF3_BS_RESETVAL                                    (0x00000000U)

/* IPB */

#define CSL_ILF3_IPB_IPB_BYTE_MASK                              (0x000000FFU)
#define CSL_ILF3_IPB_IPB_BYTE_SHIFT                             (0U)
#define CSL_ILF3_IPB_IPB_BYTE_RESETVAL                          (0x00000000U)
#define CSL_ILF3_IPB_IPB_BYTE_MAX                               (0x000000ffU)

#define CSL_ILF3_IPB_IPB_BYTE_EXT_MASK                          (0x00000700U)
#define CSL_ILF3_IPB_IPB_BYTE_EXT_SHIFT                         (8U)
#define CSL_ILF3_IPB_IPB_BYTE_EXT_RESETVAL                      (0x00000000U)
#define CSL_ILF3_IPB_IPB_BYTE_EXT_MAX                           (0x00000007U)

#define CSL_ILF3_IPB_RESETVAL                                   (0x00000000U)

/* COMMAND */

#define CSL_ILF3_COMMAND_CMD_MASK                               (0x00000007U)
#define CSL_ILF3_COMMAND_CMD_SHIFT                              (0U)
#define CSL_ILF3_COMMAND_CMD_RESETVAL                           (0x00000000U)
#define CSL_ILF3_COMMAND_CMD_MAX                                (0x00000007U)

#define CSL_ILF3_COMMAND_RESETVAL                               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
