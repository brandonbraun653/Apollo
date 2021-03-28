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
#ifndef CSLR_DES_H_
#define CSLR_DES_H_

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
    volatile Uint32 S_KEY3_L;
    volatile Uint32 S_KEY3_H;
    volatile Uint32 S_KEY2_L;
    volatile Uint32 S_KEY2_H;
    volatile Uint32 S_KEY1_L;
    volatile Uint32 S_KEY1_H;
    volatile Uint32 S_IV_L;
    volatile Uint32 S_IV_H;
    volatile Uint32 S_CTRL;
    volatile Uint32 S_LENGTH;
    volatile Uint32 S_DATA_L;
    volatile Uint32 S_DATA_H;
    volatile Uint32 S_REVISION;
    volatile Uint32 S_SYSCONFIG;
    volatile Uint32 S_SYSSTS;
    volatile Uint32 S_IRQSTS;
    volatile Uint32 S_IRQEN;
    volatile Uint32 S_DIRTYBITS;
    volatile Uint32 S_LOCKDOWN;
    volatile Uint8  RSVD0[4020];
    volatile Uint32 P_KEY3_L;
    volatile Uint32 P_KEY3_H;
    volatile Uint32 P_KEY2_L;
    volatile Uint32 P_KEY2_H;
    volatile Uint32 P_KEY1_L;
    volatile Uint32 P_KEY1_H;
    volatile Uint32 P_IV_L;
    volatile Uint32 P_IV_H;
    volatile Uint32 P_CTRL;
    volatile Uint32 P_LENGTH;
    volatile Uint32 P_DATA_L;
    volatile Uint32 P_DATA_H;
    volatile Uint32 P_REVISION;
    volatile Uint32 P_SYSCONFIG;
    volatile Uint32 P_SYSSTS;
    volatile Uint32 P_IRQSTS;
    volatile Uint32 P_IRQEN;
} CSL_DesRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* KEY3 (LSW) for 192-bit key */
#define CSL_DES_S_KEY3_L                                        (0x0U)

/* KEY3 (MSW) for 192-bit key */
#define CSL_DES_S_KEY3_H                                        (0x4U)

/* KEY2 (LSW) for 192-bit key */
#define CSL_DES_S_KEY2_L                                        (0x8U)

/* KEY2 (MSW) for 192-bit key */
#define CSL_DES_S_KEY2_H                                        (0xCU)

/* KEY1 (LSW) for 128-bit key/192-bit key */
#define CSL_DES_S_KEY1_L                                        (0x10U)

/* KEY1 (MSW) for 128-bit key/192-bit key */
#define CSL_DES_S_KEY1_H                                        (0x14U)

/* Initialization vector LSW */
#define CSL_DES_S_IV_L                                          (0x18U)

/* Initialization vector MSW */
#define CSL_DES_S_IV_H                                          (0x1CU)

/* S_CTRL */
#define CSL_DES_S_CTRL                                          (0x20U)

/* Indicates the cryptographic data length in bytes for all modes. Once
 * processing is started with this context, this length decrements to zero.
 * Data lengths up to (2^32 – 1) bytes are allowed. A write to this register
 * triggers the engine to start using this context. For a Host read operation,
 * these registers return all-zeroes. */
#define CSL_DES_S_LENGTH                                        (0x24U)

/* Data register(LSW) to read/write encrypted/decrypted data. */
#define CSL_DES_S_DATA_L                                        (0x28U)

/* Data register(MSW) to read/write encrypted/decrypted data. */
#define CSL_DES_S_DATA_H                                        (0x2CU)

/* Revision number of the module */
#define CSL_DES_S_REVISION                                      (0x30U)

/* S_SYSCONFIG */
#define CSL_DES_S_SYSCONFIG                                     (0x34U)

/* S_SYSSTS */
#define CSL_DES_S_SYSSTS                                        (0x38U)

/* This register indicates the interrupt status. If one of the interrupt bits
 * is set the interrupt output will be asserted */
#define CSL_DES_S_IRQSTS                                        (0x3CU)

/* This register contains an enable bit for each unique interrupt generated by
 * the module. It matches the layout of DES_IRQSTATUS register. An interrupt
 * is enabled when the bit in this register is set to 1 */
#define CSL_DES_S_IRQEN                                         (0x40U)

/* S_DIRTYBITS */
#define CSL_DES_S_DIRTYBITS                                     (0x44U)

/* S_LOCKDOWN */
#define CSL_DES_S_LOCKDOWN                                      (0x48U)

/* KEY3 (LSW) for 192-bit key */
#define CSL_DES_P_KEY3_L                                        (0x1000U)

/* KEY3 (MSW) for 192-bit key */
#define CSL_DES_P_KEY3_H                                        (0x1004U)

/* KEY2 (LSW) for 192-bit key */
#define CSL_DES_P_KEY2_L                                        (0x1008U)

/* KEY2 (MSW) for 192-bit key */
#define CSL_DES_P_KEY2_H                                        (0x100CU)

/* KEY1 (LSW) for 128-bit key/192-bit key */
#define CSL_DES_P_KEY1_L                                        (0x1010U)

/* KEY1 (LSW) for 128-bit key/192-bit key */
#define CSL_DES_P_KEY1_H                                        (0x1014U)

/* Initialization vector LSW */
#define CSL_DES_P_IV_L                                          (0x1018U)

/* Initialization vector MSW */
#define CSL_DES_P_IV_H                                          (0x101CU)

/* P_CTRL */
#define CSL_DES_P_CTRL                                          (0x1020U)

/* Indicates the cryptographic data length in bytes for all modes. Once
 * processing is started with this context, this length decrements to zero.
 * Data lengths up to (2^32 – 1) bytes are allowed. A write to this register
 * triggers the engine to start using this context. For a Host read operation,
 * these registers return all-zeroes. */
#define CSL_DES_P_LENGTH                                        (0x1024U)

/* Data register(LSW) to read/write encrypted/decrypted data. */
#define CSL_DES_P_DATA_L                                        (0x1028U)

/* Data register(MSW) to read/write encrypted/decrypted data. */
#define CSL_DES_P_DATA_H                                        (0x102CU)

/* P_REVISION */
#define CSL_DES_P_REVISION                                      (0x1030U)

/* P_SYSCONFIG */
#define CSL_DES_P_SYSCONFIG                                     (0x1034U)

/* P_SYSSTS */
#define CSL_DES_P_SYSSTS                                        (0x1038U)

/* This register indicates the interrupt status. If one of the interrupt bits
 * is set the interrupt output will be asserted */
#define CSL_DES_P_IRQSTS                                        (0x103CU)

/* This register contains an enable bit for each unique interrupt generated by
 * the module. It matches the layout of DES_IRQSTATUS register. An interrupt
 * is enabled when the bit in this register is set to 1 */
#define CSL_DES_P_IRQEN                                         (0x1040U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* S_KEY3_L */

#define CSL_DES_S_KEY3_L_KEY3_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_KEY3_L_KEY3_L_SHIFT                           (0U)
#define CSL_DES_S_KEY3_L_KEY3_L_RESETVAL                        (0x00000000U)
#define CSL_DES_S_KEY3_L_KEY3_L_MAX                             (0xffffffffU)

#define CSL_DES_S_KEY3_L_RESETVAL                               (0x00000000U)

/* S_KEY3_H */

#define CSL_DES_S_KEY3_H_KEY3_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_KEY3_H_KEY3_H_SHIFT                           (0U)
#define CSL_DES_S_KEY3_H_KEY3_H_RESETVAL                        (0x00000000U)
#define CSL_DES_S_KEY3_H_KEY3_H_MAX                             (0xffffffffU)

#define CSL_DES_S_KEY3_H_RESETVAL                               (0x00000000U)

/* S_KEY2_L */

#define CSL_DES_S_KEY2_L_KEY2_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_KEY2_L_KEY2_L_SHIFT                           (0U)
#define CSL_DES_S_KEY2_L_KEY2_L_RESETVAL                        (0x00000000U)
#define CSL_DES_S_KEY2_L_KEY2_L_MAX                             (0xffffffffU)

#define CSL_DES_S_KEY2_L_RESETVAL                               (0x00000000U)

/* S_KEY2_H */

#define CSL_DES_S_KEY2_H_KEY2_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_KEY2_H_KEY2_H_SHIFT                           (0U)
#define CSL_DES_S_KEY2_H_KEY2_H_RESETVAL                        (0x00000000U)
#define CSL_DES_S_KEY2_H_KEY2_H_MAX                             (0xffffffffU)

#define CSL_DES_S_KEY2_H_RESETVAL                               (0x00000000U)

/* S_KEY1_L */

#define CSL_DES_S_KEY1_L_KEY1_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_KEY1_L_KEY1_L_SHIFT                           (0U)
#define CSL_DES_S_KEY1_L_KEY1_L_RESETVAL                        (0x00000000U)
#define CSL_DES_S_KEY1_L_KEY1_L_MAX                             (0xffffffffU)

#define CSL_DES_S_KEY1_L_RESETVAL                               (0x00000000U)

/* S_KEY1_H */

#define CSL_DES_S_KEY1_H_KEY1_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_KEY1_H_KEY1_H_SHIFT                           (0U)
#define CSL_DES_S_KEY1_H_KEY1_H_RESETVAL                        (0x00000000U)
#define CSL_DES_S_KEY1_H_KEY1_H_MAX                             (0xffffffffU)

#define CSL_DES_S_KEY1_H_RESETVAL                               (0x00000000U)

/* S_IV_L */

#define CSL_DES_S_IV_L_IV_L_MASK                                (0xFFFFFFFFU)
#define CSL_DES_S_IV_L_IV_L_SHIFT                               (0U)
#define CSL_DES_S_IV_L_IV_L_RESETVAL                            (0x00000000U)
#define CSL_DES_S_IV_L_IV_L_MAX                                 (0xffffffffU)

#define CSL_DES_S_IV_L_RESETVAL                                 (0x00000000U)

/* S_IV_H */

#define CSL_DES_S_IV_H_IV_H_MASK                                (0xFFFFFFFFU)
#define CSL_DES_S_IV_H_IV_H_SHIFT                               (0U)
#define CSL_DES_S_IV_H_IV_H_RESETVAL                            (0x00000000U)
#define CSL_DES_S_IV_H_IV_H_MAX                                 (0xffffffffU)

#define CSL_DES_S_IV_H_RESETVAL                                 (0x00000000U)

/* S_CTRL */

#define CSL_DES_S_CTRL_OUTPUT_READY_MASK                        (0x00000001U)
#define CSL_DES_S_CTRL_OUTPUT_READY_SHIFT                       (0U)
#define CSL_DES_S_CTRL_OUTPUT_READY_RESETVAL                    (0x00000000U)
#define CSL_DES_S_CTRL_OUTPUT_READY_MAX                         (0x00000001U)

#define CSL_DES_S_CTRL_INPUT_READY_MASK                         (0x00000002U)
#define CSL_DES_S_CTRL_INPUT_READY_SHIFT                        (1U)
#define CSL_DES_S_CTRL_INPUT_READY_RESETVAL                     (0x00000000U)
#define CSL_DES_S_CTRL_INPUT_READY_MAX                          (0x00000001U)

#define CSL_DES_S_CTRL_DIRECTION_MASK                           (0x00000004U)
#define CSL_DES_S_CTRL_DIRECTION_SHIFT                          (2U)
#define CSL_DES_S_CTRL_DIRECTION_RESETVAL                       (0x00000000U)
#define CSL_DES_S_CTRL_DIRECTION_ENCRYPT                        (0x00000001U)
#define CSL_DES_S_CTRL_DIRECTION_DECRYPT                        (0x00000000U)

#define CSL_DES_S_CTRL_TDES_MASK                                (0x00000008U)
#define CSL_DES_S_CTRL_TDES_SHIFT                               (3U)
#define CSL_DES_S_CTRL_TDES_RESETVAL                            (0x00000000U)
#define CSL_DES_S_CTRL_TDES_DES                                 (0x00000000U)
#define CSL_DES_S_CTRL_TDES_TDES                                (0x00000001U)

#define CSL_DES_S_CTRL_MODE_MASK                                (0x00000030U)
#define CSL_DES_S_CTRL_MODE_SHIFT                               (4U)
#define CSL_DES_S_CTRL_MODE_RESETVAL                            (0x00000000U)
#define CSL_DES_S_CTRL_MODE_ECB                                 (0x00000000U)
#define CSL_DES_S_CTRL_MODE_CBC                                 (0x00000001U)
#define CSL_DES_S_CTRL_MODE_CFB                                 (0x00000002U)
#define CSL_DES_S_CTRL_MODE_RESERVED                            (0x00000003U)

#define CSL_DES_S_CTRL_CONTEXT_MASK                             (0x80000000U)
#define CSL_DES_S_CTRL_CONTEXT_SHIFT                            (31U)
#define CSL_DES_S_CTRL_CONTEXT_RESETVAL                         (0x00000001U)
#define CSL_DES_S_CTRL_CONTEXT_MAX                              (0x00000001U)

#define CSL_DES_S_CTRL_RESETVAL                                 (0x80000000U)

/* S_LENGTH */

#define CSL_DES_S_LENGTH_LENGTH_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_LENGTH_LENGTH_SHIFT                           (0U)
#define CSL_DES_S_LENGTH_LENGTH_RESETVAL                        (0x00000000U)
#define CSL_DES_S_LENGTH_LENGTH_MAX                             (0xffffffffU)

#define CSL_DES_S_LENGTH_RESETVAL                               (0x00000000U)

/* S_DATA_L */

#define CSL_DES_S_DATA_L_DATA_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_DATA_L_DATA_L_SHIFT                           (0U)
#define CSL_DES_S_DATA_L_DATA_L_RESETVAL                        (0x00000000U)
#define CSL_DES_S_DATA_L_DATA_L_MAX                             (0xffffffffU)

#define CSL_DES_S_DATA_L_RESETVAL                               (0x00000000U)

/* S_DATA_H */

#define CSL_DES_S_DATA_H_DATA_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_S_DATA_H_DATA_H_SHIFT                           (0U)
#define CSL_DES_S_DATA_H_DATA_H_RESETVAL                        (0x00000000U)
#define CSL_DES_S_DATA_H_DATA_H_MAX                             (0xffffffffU)

#define CSL_DES_S_DATA_H_RESETVAL                               (0x00000000U)

/* S_REVISION */

#define CSL_DES_S_REVISION_Y_MINOR_MASK                         (0x0000003FU)
#define CSL_DES_S_REVISION_Y_MINOR_SHIFT                        (0U)
#define CSL_DES_S_REVISION_Y_MINOR_RESETVAL                     (0x00000000U)
#define CSL_DES_S_REVISION_Y_MINOR_MAX                          (0x0000003fU)

#define CSL_DES_S_REVISION_CUSTOM_MASK                          (0x000000C0U)
#define CSL_DES_S_REVISION_CUSTOM_SHIFT                         (6U)
#define CSL_DES_S_REVISION_CUSTOM_RESETVAL                      (0x00000000U)
#define CSL_DES_S_REVISION_CUSTOM_STANDARD                      (0x00000000U)

#define CSL_DES_S_REVISION_X_MAJOR_MASK                         (0x00000700U)
#define CSL_DES_S_REVISION_X_MAJOR_SHIFT                        (8U)
#define CSL_DES_S_REVISION_X_MAJOR_RESETVAL                     (0x00000000U)
#define CSL_DES_S_REVISION_X_MAJOR_MAX                          (0x00000007U)

#define CSL_DES_S_REVISION_R_RTL_MASK                           (0x0000F800U)
#define CSL_DES_S_REVISION_R_RTL_SHIFT                          (11U)
#define CSL_DES_S_REVISION_R_RTL_RESETVAL                       (0x00000000U)
#define CSL_DES_S_REVISION_R_RTL_MAX                            (0x0000001fU)

#define CSL_DES_S_REVISION_FUNC_MASK                            (0x0FFF0000U)
#define CSL_DES_S_REVISION_FUNC_SHIFT                           (16U)
#define CSL_DES_S_REVISION_FUNC_RESETVAL                        (0x00000000U)
#define CSL_DES_S_REVISION_FUNC_MAX                             (0x00000fffU)

#define CSL_DES_S_REVISION_SCHEME_MASK                          (0xC0000000U)
#define CSL_DES_S_REVISION_SCHEME_SHIFT                         (30U)
#define CSL_DES_S_REVISION_SCHEME_RESETVAL                      (0x00000000U)
#define CSL_DES_S_REVISION_SCHEME_H08                           (0x00000001U)
#define CSL_DES_S_REVISION_SCHEME_LEGACY                        (0x00000000U)

#define CSL_DES_S_REVISION_RESETVAL                             (0x00000000U)

/* S_SYSCONFIG */

#define CSL_DES_S_SYSCONFIG_AUTOIDLE_MASK                       (0x00000001U)
#define CSL_DES_S_SYSCONFIG_AUTOIDLE_SHIFT                      (0U)
#define CSL_DES_S_SYSCONFIG_AUTOIDLE_RESETVAL                   (0x00000001U)
#define CSL_DES_S_SYSCONFIG_AUTOIDLE_CLOCKS_ON                  (0x00000000U)
#define CSL_DES_S_SYSCONFIG_AUTOIDLE_CLOCKS_OFF                 (0x00000001U)

#define CSL_DES_S_SYSCONFIG_SOFTRESET_MASK                      (0x00000002U)
#define CSL_DES_S_SYSCONFIG_SOFTRESET_SHIFT                     (1U)
#define CSL_DES_S_SYSCONFIG_SOFTRESET_RESETVAL                  (0x00000000U)
#define CSL_DES_S_SYSCONFIG_SOFTRESET_NOOP                      (0x00000000U)
#define CSL_DES_S_SYSCONFIG_SOFTRESET_SOFRESET                  (0x00000001U)

#define CSL_DES_S_SYSCONFIG_SIDLE_MASK                          (0x0000000CU)
#define CSL_DES_S_SYSCONFIG_SIDLE_SHIFT                         (2U)
#define CSL_DES_S_SYSCONFIG_SIDLE_RESETVAL                      (0x00000000U)
#define CSL_DES_S_SYSCONFIG_SIDLE_FORCEIDLE                     (0x00000000U)
#define CSL_DES_S_SYSCONFIG_SIDLE_NOIDLE                        (0x00000001U)
#define CSL_DES_S_SYSCONFIG_SIDLE_SMARTIDLE                     (0x00000002U)
#define CSL_DES_S_SYSCONFIG_SIDLE_RESERVED                      (0x00000003U)

#define CSL_DES_S_SYSCONFIG_DIRECTBUSEN_MASK                    (0x00000010U)
#define CSL_DES_S_SYSCONFIG_DIRECTBUSEN_SHIFT                   (4U)
#define CSL_DES_S_SYSCONFIG_DIRECTBUSEN_RESETVAL                (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DIRECTBUSEN_KEY                     (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DIRECTBUSEN_DIRECT                  (0x00000001U)

#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_IN_EN_MASK             (0x00000020U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_IN_EN_SHIFT            (5U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_IN_EN_RESETVAL         (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_IN_EN_DMA_DIS          (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_IN_EN_DMA_EN           (0x00000001U)

#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_OUT_EN_MASK            (0x00000040U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_OUT_EN_SHIFT           (6U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_OUT_EN_RESETVAL        (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_OUT_EN_DMA_DIS         (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_DATA_OUT_EN_DMA_EN          (0x00000001U)

#define CSL_DES_S_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_MASK          (0x00000080U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_SHIFT         (7U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_RESETVAL      (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_DMA_DIS       (0x00000000U)
#define CSL_DES_S_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_DMA_EN        (0x00000001U)

#define CSL_DES_S_SYSCONFIG_RESETVAL                            (0x00000001U)

/* S_SYSSTS */

#define CSL_DES_S_SYSSTS_RESETDONE_MASK                         (0x00000001U)
#define CSL_DES_S_SYSSTS_RESETDONE_SHIFT                        (0U)
#define CSL_DES_S_SYSSTS_RESETDONE_RESETVAL                     (0x00000000U)
#define CSL_DES_S_SYSSTS_RESETDONE_MAX                          (0x00000001U)

#define CSL_DES_S_SYSSTS_RESETVAL                               (0x00000000U)

/* S_IRQSTS */

#define CSL_DES_S_IRQSTS_CONTEX_IN_MASK                         (0x00000001U)
#define CSL_DES_S_IRQSTS_CONTEX_IN_SHIFT                        (0U)
#define CSL_DES_S_IRQSTS_CONTEX_IN_RESETVAL                     (0x00000000U)
#define CSL_DES_S_IRQSTS_CONTEX_IN_MAX                          (0x00000001U)

#define CSL_DES_S_IRQSTS_DATA_IN_MASK                           (0x00000002U)
#define CSL_DES_S_IRQSTS_DATA_IN_SHIFT                          (1U)
#define CSL_DES_S_IRQSTS_DATA_IN_RESETVAL                       (0x00000000U)
#define CSL_DES_S_IRQSTS_DATA_IN_MAX                            (0x00000001U)

#define CSL_DES_S_IRQSTS_DATA_OUT_MASK                          (0x00000004U)
#define CSL_DES_S_IRQSTS_DATA_OUT_SHIFT                         (2U)
#define CSL_DES_S_IRQSTS_DATA_OUT_RESETVAL                      (0x00000000U)
#define CSL_DES_S_IRQSTS_DATA_OUT_MAX                           (0x00000001U)

#define CSL_DES_S_IRQSTS_RESETVAL                               (0x00000000U)

/* S_IRQEN */

#define CSL_DES_S_IRQEN_M_CONTEX_IN_MASK                        (0x00000001U)
#define CSL_DES_S_IRQEN_M_CONTEX_IN_SHIFT                       (0U)
#define CSL_DES_S_IRQEN_M_CONTEX_IN_RESETVAL                    (0x00000000U)
#define CSL_DES_S_IRQEN_M_CONTEX_IN_MAX                         (0x00000001U)

#define CSL_DES_S_IRQEN_M_DATA_IN_MASK                          (0x00000002U)
#define CSL_DES_S_IRQEN_M_DATA_IN_SHIFT                         (1U)
#define CSL_DES_S_IRQEN_M_DATA_IN_RESETVAL                      (0x00000000U)
#define CSL_DES_S_IRQEN_M_DATA_IN_MAX                           (0x00000001U)

#define CSL_DES_S_IRQEN_M_DATA_OUT_MASK                         (0x00000004U)
#define CSL_DES_S_IRQEN_M_DATA_OUT_SHIFT                        (2U)
#define CSL_DES_S_IRQEN_M_DATA_OUT_RESETVAL                     (0x00000000U)
#define CSL_DES_S_IRQEN_M_DATA_OUT_MAX                          (0x00000001U)

#define CSL_DES_S_IRQEN_RESETVAL                                (0x00000000U)

/* S_DIRTYBITS */

#define CSL_DES_S_DIRTYBITS_S_ACCESS_MASK                       (0x00000001U)
#define CSL_DES_S_DIRTYBITS_S_ACCESS_SHIFT                      (0U)
#define CSL_DES_S_DIRTYBITS_S_ACCESS_RESETVAL                   (0x00000000U)
#define CSL_DES_S_DIRTYBITS_S_ACCESS_MAX                        (0x00000001U)

#define CSL_DES_S_DIRTYBITS_S_DIRTY_MASK                        (0x00000002U)
#define CSL_DES_S_DIRTYBITS_S_DIRTY_SHIFT                       (1U)
#define CSL_DES_S_DIRTYBITS_S_DIRTY_RESETVAL                    (0x00000000U)
#define CSL_DES_S_DIRTYBITS_S_DIRTY_MAX                         (0x00000001U)

#define CSL_DES_S_DIRTYBITS_P_ACCESS_MASK                       (0x00000004U)
#define CSL_DES_S_DIRTYBITS_P_ACCESS_SHIFT                      (2U)
#define CSL_DES_S_DIRTYBITS_P_ACCESS_RESETVAL                   (0x00000000U)
#define CSL_DES_S_DIRTYBITS_P_ACCESS_MAX                        (0x00000001U)

#define CSL_DES_S_DIRTYBITS_P_DIRTY_MASK                        (0x00000008U)
#define CSL_DES_S_DIRTYBITS_P_DIRTY_SHIFT                       (3U)
#define CSL_DES_S_DIRTYBITS_P_DIRTY_RESETVAL                    (0x00000000U)
#define CSL_DES_S_DIRTYBITS_P_DIRTY_MAX                         (0x00000001U)

#define CSL_DES_S_DIRTYBITS_RESETVAL                            (0x00000000U)

/* S_LOCKDOWN */

#define CSL_DES_S_LOCKDOWN_KEY_LOCK_MASK                        (0x00000001U)
#define CSL_DES_S_LOCKDOWN_KEY_LOCK_SHIFT                       (0U)
#define CSL_DES_S_LOCKDOWN_KEY_LOCK_RESETVAL                    (0x00000000U)
#define CSL_DES_S_LOCKDOWN_KEY_LOCK_MAX                         (0x00000001U)

#define CSL_DES_S_LOCKDOWN_IV_LOCK_MASK                         (0x00000002U)
#define CSL_DES_S_LOCKDOWN_IV_LOCK_SHIFT                        (1U)
#define CSL_DES_S_LOCKDOWN_IV_LOCK_RESETVAL                     (0x00000000U)
#define CSL_DES_S_LOCKDOWN_IV_LOCK_MAX                          (0x00000001U)

#define CSL_DES_S_LOCKDOWN_CTRL_LOCK_MASK                       (0x00000004U)
#define CSL_DES_S_LOCKDOWN_CTRL_LOCK_SHIFT                      (2U)
#define CSL_DES_S_LOCKDOWN_CTRL_LOCK_RESETVAL                   (0x00000000U)
#define CSL_DES_S_LOCKDOWN_CTRL_LOCK_MAX                        (0x00000001U)

#define CSL_DES_S_LOCKDOWN_LENGTH_LOCK_MASK                     (0x00000008U)
#define CSL_DES_S_LOCKDOWN_LENGTH_LOCK_SHIFT                    (3U)
#define CSL_DES_S_LOCKDOWN_LENGTH_LOCK_RESETVAL                 (0x00000000U)
#define CSL_DES_S_LOCKDOWN_LENGTH_LOCK_MAX                      (0x00000001U)

#define CSL_DES_S_LOCKDOWN_RESETVAL                             (0x00000000U)

/* P_KEY3_L */

#define CSL_DES_P_KEY3_L_KEY3_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_KEY3_L_KEY3_L_SHIFT                           (0U)
#define CSL_DES_P_KEY3_L_KEY3_L_RESETVAL                        (0x00000000U)
#define CSL_DES_P_KEY3_L_KEY3_L_MAX                             (0xffffffffU)

#define CSL_DES_P_KEY3_L_RESETVAL                               (0x00000000U)

/* P_KEY3_H */

#define CSL_DES_P_KEY3_H_KEY3_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_KEY3_H_KEY3_H_SHIFT                           (0U)
#define CSL_DES_P_KEY3_H_KEY3_H_RESETVAL                        (0x00000000U)
#define CSL_DES_P_KEY3_H_KEY3_H_MAX                             (0xffffffffU)

#define CSL_DES_P_KEY3_H_RESETVAL                               (0x00000000U)

/* P_KEY2_L */

#define CSL_DES_P_KEY2_L_KEY2_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_KEY2_L_KEY2_L_SHIFT                           (0U)
#define CSL_DES_P_KEY2_L_KEY2_L_RESETVAL                        (0x00000000U)
#define CSL_DES_P_KEY2_L_KEY2_L_MAX                             (0xffffffffU)

#define CSL_DES_P_KEY2_L_RESETVAL                               (0x00000000U)

/* P_KEY2_H */

#define CSL_DES_P_KEY2_H_KEY2_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_KEY2_H_KEY2_H_SHIFT                           (0U)
#define CSL_DES_P_KEY2_H_KEY2_H_RESETVAL                        (0x00000000U)
#define CSL_DES_P_KEY2_H_KEY2_H_MAX                             (0xffffffffU)

#define CSL_DES_P_KEY2_H_RESETVAL                               (0x00000000U)

/* P_KEY1_L */

#define CSL_DES_P_KEY1_L_KEY1_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_KEY1_L_KEY1_L_SHIFT                           (0U)
#define CSL_DES_P_KEY1_L_KEY1_L_RESETVAL                        (0x00000000U)
#define CSL_DES_P_KEY1_L_KEY1_L_MAX                             (0xffffffffU)

#define CSL_DES_P_KEY1_L_RESETVAL                               (0x00000000U)

/* P_KEY1_H */

#define CSL_DES_P_KEY1_H_KEY1_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_KEY1_H_KEY1_H_SHIFT                           (0U)
#define CSL_DES_P_KEY1_H_KEY1_H_RESETVAL                        (0x00000000U)
#define CSL_DES_P_KEY1_H_KEY1_H_MAX                             (0xffffffffU)

#define CSL_DES_P_KEY1_H_RESETVAL                               (0x00000000U)

/* P_IV_L */

#define CSL_DES_P_IV_L_IV_L_MASK                                (0xFFFFFFFFU)
#define CSL_DES_P_IV_L_IV_L_SHIFT                               (0U)
#define CSL_DES_P_IV_L_IV_L_RESETVAL                            (0x00000000U)
#define CSL_DES_P_IV_L_IV_L_MAX                                 (0xffffffffU)

#define CSL_DES_P_IV_L_RESETVAL                                 (0x00000000U)

/* P_IV_H */

#define CSL_DES_P_IV_H_IV_H_MASK                                (0xFFFFFFFFU)
#define CSL_DES_P_IV_H_IV_H_SHIFT                               (0U)
#define CSL_DES_P_IV_H_IV_H_RESETVAL                            (0x00000000U)
#define CSL_DES_P_IV_H_IV_H_MAX                                 (0xffffffffU)

#define CSL_DES_P_IV_H_RESETVAL                                 (0x00000000U)

/* P_CTRL */

#define CSL_DES_P_CTRL_OUTPUT_READY_MASK                        (0x00000001U)
#define CSL_DES_P_CTRL_OUTPUT_READY_SHIFT                       (0U)
#define CSL_DES_P_CTRL_OUTPUT_READY_RESETVAL                    (0x00000000U)
#define CSL_DES_P_CTRL_OUTPUT_READY_MAX                         (0x00000001U)

#define CSL_DES_P_CTRL_INPUT_READY_MASK                         (0x00000002U)
#define CSL_DES_P_CTRL_INPUT_READY_SHIFT                        (1U)
#define CSL_DES_P_CTRL_INPUT_READY_RESETVAL                     (0x00000000U)
#define CSL_DES_P_CTRL_INPUT_READY_MAX                          (0x00000001U)

#define CSL_DES_P_CTRL_DIRECTION_MASK                           (0x00000004U)
#define CSL_DES_P_CTRL_DIRECTION_SHIFT                          (2U)
#define CSL_DES_P_CTRL_DIRECTION_RESETVAL                       (0x00000000U)
#define CSL_DES_P_CTRL_DIRECTION_ENCRYPT                        (0x00000001U)
#define CSL_DES_P_CTRL_DIRECTION_DECRYPT                        (0x00000000U)

#define CSL_DES_P_CTRL_TDES_MASK                                (0x00000008U)
#define CSL_DES_P_CTRL_TDES_SHIFT                               (3U)
#define CSL_DES_P_CTRL_TDES_RESETVAL                            (0x00000000U)
#define CSL_DES_P_CTRL_TDES_DES                                 (0x00000000U)
#define CSL_DES_P_CTRL_TDES_TDES                                (0x00000001U)

#define CSL_DES_P_CTRL_MODE_MASK                                (0x00000030U)
#define CSL_DES_P_CTRL_MODE_SHIFT                               (4U)
#define CSL_DES_P_CTRL_MODE_RESETVAL                            (0x00000000U)
#define CSL_DES_P_CTRL_MODE_ECB                                 (0x00000000U)
#define CSL_DES_P_CTRL_MODE_CBC                                 (0x00000001U)
#define CSL_DES_P_CTRL_MODE_CFB                                 (0x00000002U)
#define CSL_DES_P_CTRL_MODE_RESERVED                            (0x00000003U)

#define CSL_DES_P_CTRL_CONTEXT_MASK                             (0x80000000U)
#define CSL_DES_P_CTRL_CONTEXT_SHIFT                            (31U)
#define CSL_DES_P_CTRL_CONTEXT_RESETVAL                         (0x00000001U)
#define CSL_DES_P_CTRL_CONTEXT_MAX                              (0x00000001U)

#define CSL_DES_P_CTRL_RESETVAL                                 (0x80000000U)

/* P_LENGTH */

#define CSL_DES_P_LENGTH_LENGTH_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_LENGTH_LENGTH_SHIFT                           (0U)
#define CSL_DES_P_LENGTH_LENGTH_RESETVAL                        (0x00000000U)
#define CSL_DES_P_LENGTH_LENGTH_MAX                             (0xffffffffU)

#define CSL_DES_P_LENGTH_RESETVAL                               (0x00000000U)

/* P_DATA_L */

#define CSL_DES_P_DATA_L_DATA_L_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_DATA_L_DATA_L_SHIFT                           (0U)
#define CSL_DES_P_DATA_L_DATA_L_RESETVAL                        (0x00000000U)
#define CSL_DES_P_DATA_L_DATA_L_MAX                             (0xffffffffU)

#define CSL_DES_P_DATA_L_RESETVAL                               (0x00000000U)

/* P_DATA_H */

#define CSL_DES_P_DATA_H_DATA_H_MASK                            (0xFFFFFFFFU)
#define CSL_DES_P_DATA_H_DATA_H_SHIFT                           (0U)
#define CSL_DES_P_DATA_H_DATA_H_RESETVAL                        (0x00000000U)
#define CSL_DES_P_DATA_H_DATA_H_MAX                             (0xffffffffU)

#define CSL_DES_P_DATA_H_RESETVAL                               (0x00000000U)

/* P_REVISION */

#define CSL_DES_P_REVISION_Y_MINOR_MASK                         (0x0000003FU)
#define CSL_DES_P_REVISION_Y_MINOR_SHIFT                        (0U)
#define CSL_DES_P_REVISION_Y_MINOR_RESETVAL                     (0x00000000U)
#define CSL_DES_P_REVISION_Y_MINOR_MAX                          (0x0000003fU)

#define CSL_DES_P_REVISION_CUSTOM_MASK                          (0x000000C0U)
#define CSL_DES_P_REVISION_CUSTOM_SHIFT                         (6U)
#define CSL_DES_P_REVISION_CUSTOM_RESETVAL                      (0x00000000U)
#define CSL_DES_P_REVISION_CUSTOM_STANDARD                      (0x00000000U)

#define CSL_DES_P_REVISION_X_MAJOR_MASK                         (0x00000700U)
#define CSL_DES_P_REVISION_X_MAJOR_SHIFT                        (8U)
#define CSL_DES_P_REVISION_X_MAJOR_RESETVAL                     (0x00000000U)
#define CSL_DES_P_REVISION_X_MAJOR_MAX                          (0x00000007U)

#define CSL_DES_P_REVISION_R_RTL_MASK                           (0x0000F800U)
#define CSL_DES_P_REVISION_R_RTL_SHIFT                          (11U)
#define CSL_DES_P_REVISION_R_RTL_RESETVAL                       (0x00000000U)
#define CSL_DES_P_REVISION_R_RTL_MAX                            (0x0000001fU)

#define CSL_DES_P_REVISION_FUNC_MASK                            (0x0FFF0000U)
#define CSL_DES_P_REVISION_FUNC_SHIFT                           (16U)
#define CSL_DES_P_REVISION_FUNC_RESETVAL                        (0x00000000U)
#define CSL_DES_P_REVISION_FUNC_MAX                             (0x00000fffU)

#define CSL_DES_P_REVISION_SCHEME_MASK                          (0xC0000000U)
#define CSL_DES_P_REVISION_SCHEME_SHIFT                         (30U)
#define CSL_DES_P_REVISION_SCHEME_RESETVAL                      (0x00000000U)
#define CSL_DES_P_REVISION_SCHEME_H08                           (0x00000001U)
#define CSL_DES_P_REVISION_SCHEME_LEGACY                        (0x00000000U)

#define CSL_DES_P_REVISION_RESETVAL                             (0x00000000U)

/* P_SYSCONFIG */

#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_IN_EN_MASK             (0x00000020U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_IN_EN_SHIFT            (5U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_IN_EN_RESETVAL         (0x00000000U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_IN_EN_DMA_DIS          (0x00000000U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_IN_EN_DMA_EN           (0x00000001U)

#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_OUT_EN_MASK            (0x00000040U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_OUT_EN_SHIFT           (6U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_OUT_EN_RESETVAL        (0x00000000U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_OUT_EN_DMA_DIS         (0x00000000U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_DATA_OUT_EN_DMA_EN          (0x00000001U)

#define CSL_DES_P_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_MASK          (0x00000080U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_SHIFT         (7U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_RESETVAL      (0x00000000U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_DMA_DIS       (0x00000000U)
#define CSL_DES_P_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_DMA_EN        (0x00000001U)

#define CSL_DES_P_SYSCONFIG_RESETVAL                            (0x00000000U)

/* P_SYSSTS */

#define CSL_DES_P_SYSSTS_RESETDONE_MASK                         (0x00000001U)
#define CSL_DES_P_SYSSTS_RESETDONE_SHIFT                        (0U)
#define CSL_DES_P_SYSSTS_RESETDONE_RESETVAL                     (0x00000000U)
#define CSL_DES_P_SYSSTS_RESETDONE_MAX                          (0x00000001U)

#define CSL_DES_P_SYSSTS_RESETVAL                               (0x00000000U)

/* P_IRQSTS */

#define CSL_DES_P_IRQSTS_CONTEX_IN_MASK                         (0x00000001U)
#define CSL_DES_P_IRQSTS_CONTEX_IN_SHIFT                        (0U)
#define CSL_DES_P_IRQSTS_CONTEX_IN_RESETVAL                     (0x00000000U)
#define CSL_DES_P_IRQSTS_CONTEX_IN_MAX                          (0x00000001U)

#define CSL_DES_P_IRQSTS_DATA_IN_MASK                           (0x00000002U)
#define CSL_DES_P_IRQSTS_DATA_IN_SHIFT                          (1U)
#define CSL_DES_P_IRQSTS_DATA_IN_RESETVAL                       (0x00000000U)
#define CSL_DES_P_IRQSTS_DATA_IN_MAX                            (0x00000001U)

#define CSL_DES_P_IRQSTS_DATA_OUT_MASK                          (0x00000004U)
#define CSL_DES_P_IRQSTS_DATA_OUT_SHIFT                         (2U)
#define CSL_DES_P_IRQSTS_DATA_OUT_RESETVAL                      (0x00000000U)
#define CSL_DES_P_IRQSTS_DATA_OUT_MAX                           (0x00000001U)

#define CSL_DES_P_IRQSTS_RESETVAL                               (0x00000000U)

/* P_IRQEN */

#define CSL_DES_P_IRQEN_M_CONTEX_IN_MASK                        (0x00000001U)
#define CSL_DES_P_IRQEN_M_CONTEX_IN_SHIFT                       (0U)
#define CSL_DES_P_IRQEN_M_CONTEX_IN_RESETVAL                    (0x00000000U)
#define CSL_DES_P_IRQEN_M_CONTEX_IN_MAX                         (0x00000001U)

#define CSL_DES_P_IRQEN_M_DATA_IN_MASK                          (0x00000002U)
#define CSL_DES_P_IRQEN_M_DATA_IN_SHIFT                         (1U)
#define CSL_DES_P_IRQEN_M_DATA_IN_RESETVAL                      (0x00000000U)
#define CSL_DES_P_IRQEN_M_DATA_IN_MAX                           (0x00000001U)

#define CSL_DES_P_IRQEN_M_DATA_OUT_MASK                         (0x00000004U)
#define CSL_DES_P_IRQEN_M_DATA_OUT_SHIFT                        (2U)
#define CSL_DES_P_IRQEN_M_DATA_OUT_RESETVAL                     (0x00000000U)
#define CSL_DES_P_IRQEN_M_DATA_OUT_MAX                          (0x00000001U)

#define CSL_DES_P_IRQEN_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
