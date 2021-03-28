/********************************************************************
 * Copyright (C) 2018 Texas Instruments Incorporated.
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
 *  Name        : cslr_nsf4v.h
*/
#ifndef CSLR_NSF4V_H_
#define CSLR_NSF4V_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : VPAC VISS Noise Supression Filter for Human Vision 4 Memory Mapped Register
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t TN0;                       /* T_n Part0  */
    volatile uint32_t TN1;                       /* T_n Part1  */
} CSL_nsf4vRegs_color_TnSeg;


typedef struct {
    CSL_nsf4vRegs_color_TnSeg TNSEG[12];
} CSL_nsf4vRegs_color;


typedef struct {
    volatile uint32_t LSCCCURVE0;                /* LSCC Curve Part0  */
    volatile uint32_t LSCCCURVE1;                /* LSCC Curve Part1  */
} CSL_nsf4vRegs_set_LSCCseg;


typedef struct {
    CSL_nsf4vRegs_set_LSCCseg LSCCSEG[16];
} CSL_nsf4vRegs_set;


typedef struct {
    volatile uint8_t  Resv_4[4];
    volatile uint32_t DBG;                       /* Diagnostic Register */
    volatile uint32_t CTRL;                      /* control register */
    volatile uint32_t DIM;                       /* Input Output Frame dimension */
    volatile uint32_t LSCC;                      /* Lens Shading Correction Compensation */
    volatile uint32_t LSCC_CENT;                 /* Lens Shading Correction Compensation Center */
    volatile uint8_t  Resv_28[4];
    volatile uint32_t TN_SCALE;                  /* Tn Scaling Factor  */
    volatile uint32_t U_KNEE;                    /* U suppression curve knee  */
    volatile uint32_t WHITEBAL0;                 /* White Balance Gain (Part0)  */
    volatile uint32_t WHITEBAL1;                 /* White Balance Gain (Part0)  */
    volatile uint8_t  Resv_96[52];
    CSL_nsf4vRegs_color COLOR[4];
    volatile uint8_t  Resv_512[32];
    CSL_nsf4vRegs_set SET[2];
} CSL_nsf4vRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_NSF4V_DBG                                                          (0x00000004U)
#define CSL_NSF4V_CTRL                                                         (0x00000008U)
#define CSL_NSF4V_DIM                                                          (0x0000000CU)
#define CSL_NSF4V_LSCC                                                         (0x00000010U)
#define CSL_NSF4V_LSCC_CENT                                                    (0x00000014U)
#define CSL_NSF4V_TN_SCALE                                                     (0x0000001CU)
#define CSL_NSF4V_U_KNEE                                                       (0x00000020U)
#define CSL_NSF4V_WHITEBAL0                                                    (0x00000024U)
#define CSL_NSF4V_WHITEBAL1                                                    (0x00000028U)
#define CSL_NSF4V_COLOR_TNSEG_TN0(COLOR, TNSEG)                                (0x00000060U+((COLOR)*0x60U)+((TNSEG)*0x8U))
#define CSL_NSF4V_COLOR_TNSEG_TN1(COLOR, TNSEG)                                (0x00000064U+((COLOR)*0x60U)+((TNSEG)*0x8U))
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE0(SET, LSCCSEG)                         (0x00000200U+((SET)*0x80U)+((LSCCSEG)*0x8U))
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE1(SET, LSCCSEG)                         (0x00000204U+((SET)*0x80U)+((LSCCSEG)*0x8U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* TN0 */

#define CSL_NSF4V_COLOR_TNSEG_TN0_Y_CFG_MASK                                   (0x7FFF0000U)
#define CSL_NSF4V_COLOR_TNSEG_TN0_Y_CFG_SHIFT                                  (0x00000010U)
#define CSL_NSF4V_COLOR_TNSEG_TN0_Y_CFG_MAX                                    (0x00007FFFU)

#define CSL_NSF4V_COLOR_TNSEG_TN0_X_CFG_MASK                                   (0x0000FFFFU)
#define CSL_NSF4V_COLOR_TNSEG_TN0_X_CFG_SHIFT                                  (0x00000000U)
#define CSL_NSF4V_COLOR_TNSEG_TN0_X_CFG_MAX                                    (0x0000FFFFU)

/* TN1 */

#define CSL_NSF4V_COLOR_TNSEG_TN1_S_CFG_MASK                                   (0x0000FFFFU)
#define CSL_NSF4V_COLOR_TNSEG_TN1_S_CFG_SHIFT                                  (0x00000000U)
#define CSL_NSF4V_COLOR_TNSEG_TN1_S_CFG_MAX                                    (0x0000FFFFU)

/* LSCCCURVE0 */

#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE0_Y_CFG_MASK                            (0x01FF0000U)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE0_Y_CFG_SHIFT                           (0x00000010U)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE0_Y_CFG_MAX                             (0x000001FFU)

#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE0_X_CFG_MASK                            (0x0000FFFFU)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE0_X_CFG_SHIFT                           (0x00000000U)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE0_X_CFG_MAX                             (0x0000FFFFU)

/* LSCCCURVE1 */

#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE1_RSVD_MASK                             (0xFFFF0000U)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE1_RSVD_SHIFT                            (0x00000010U)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE1_RSVD_MAX                              (0x0000FFFFU)

#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE1_S_CFG_MASK                            (0x0000FFFFU)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE1_S_CFG_SHIFT                           (0x00000000U)
#define CSL_NSF4V_SET_LSCCSEG_LSCCCURVE1_S_CFG_MAX                             (0x0000FFFFU)

/* DBG */

#define CSL_NSF4V_DBG_RAM_MUX_CFG_MASK                                         (0x0000003FU)
#define CSL_NSF4V_DBG_RAM_MUX_CFG_SHIFT                                        (0x00000000U)
#define CSL_NSF4V_DBG_RAM_MUX_CFG_MAX                                          (0x0000003FU)

/* CTRL */

#define CSL_NSF4V_CTRL_LSCC_EN_CFG_MASK                                        (0x00001000U)
#define CSL_NSF4V_CTRL_LSCC_EN_CFG_SHIFT                                       (0x0000000CU)
#define CSL_NSF4V_CTRL_LSCC_EN_CFG_MAX                                         (0x00000001U)

#define CSL_NSF4V_CTRL_LSCC_SETSEL_CFG_MASK                                    (0x00000F00U)
#define CSL_NSF4V_CTRL_LSCC_SETSEL_CFG_SHIFT                                   (0x00000008U)
#define CSL_NSF4V_CTRL_LSCC_SETSEL_CFG_MAX                                     (0x0000000FU)

#define CSL_NSF4V_CTRL_TN_MODE_CFG_MASK                                        (0x00000010U)
#define CSL_NSF4V_CTRL_TN_MODE_CFG_SHIFT                                       (0x00000004U)
#define CSL_NSF4V_CTRL_TN_MODE_CFG_MAX                                         (0x00000001U)

#define CSL_NSF4V_CTRL_U_MODE_CFG_MASK                                         (0x0000000FU)
#define CSL_NSF4V_CTRL_U_MODE_CFG_SHIFT                                        (0x00000000U)
#define CSL_NSF4V_CTRL_U_MODE_CFG_MAX                                          (0x0000000FU)

/* DIM */

#define CSL_NSF4V_DIM_IH_CFG_MASK                                              (0x1FFF0000U)
#define CSL_NSF4V_DIM_IH_CFG_SHIFT                                             (0x00000010U)
#define CSL_NSF4V_DIM_IH_CFG_MAX                                               (0x00001FFFU)

#define CSL_NSF4V_DIM_IW_CFG_MASK                                              (0x00001FFFU)
#define CSL_NSF4V_DIM_IW_CFG_SHIFT                                             (0x00000000U)
#define CSL_NSF4V_DIM_IW_CFG_MAX                                               (0x00001FFFU)

/* LSCC */

#define CSL_NSF4V_LSCC_GMAX_CFG_MASK                                           (0x1FF00000U)
#define CSL_NSF4V_LSCC_GMAX_CFG_SHIFT                                          (0x00000014U)
#define CSL_NSF4V_LSCC_GMAX_CFG_MAX                                            (0x000001FFU)

#define CSL_NSF4V_LSCC_T_CFG_MASK                                              (0x000F0000U)
#define CSL_NSF4V_LSCC_T_CFG_SHIFT                                             (0x00000010U)
#define CSL_NSF4V_LSCC_T_CFG_MAX                                               (0x0000000FU)

#define CSL_NSF4V_LSCC_KV_CFG_MASK                                             (0x0000FF00U)
#define CSL_NSF4V_LSCC_KV_CFG_SHIFT                                            (0x00000008U)
#define CSL_NSF4V_LSCC_KV_CFG_MAX                                              (0x000000FFU)

#define CSL_NSF4V_LSCC_KH_CFG_MASK                                             (0x000000FFU)
#define CSL_NSF4V_LSCC_KH_CFG_SHIFT                                            (0x00000000U)
#define CSL_NSF4V_LSCC_KH_CFG_MAX                                              (0x000000FFU)

/* LSCC_CENT */

#define CSL_NSF4V_LSCC_CENT_Y_CFG_MASK                                         (0x3FFF0000U)
#define CSL_NSF4V_LSCC_CENT_Y_CFG_SHIFT                                        (0x00000010U)
#define CSL_NSF4V_LSCC_CENT_Y_CFG_MAX                                          (0x00003FFFU)

#define CSL_NSF4V_LSCC_CENT_X_CFG_MASK                                         (0x00003FFFU)
#define CSL_NSF4V_LSCC_CENT_X_CFG_SHIFT                                        (0x00000000U)
#define CSL_NSF4V_LSCC_CENT_X_CFG_MAX                                          (0x00003FFFU)

/* TN_SCALE */

#define CSL_NSF4V_TN_SCALE_TN3_CFG_MASK                                        (0x00FF0000U)
#define CSL_NSF4V_TN_SCALE_TN3_CFG_SHIFT                                       (0x00000010U)
#define CSL_NSF4V_TN_SCALE_TN3_CFG_MAX                                         (0x000000FFU)

#define CSL_NSF4V_TN_SCALE_TN2_CFG_MASK                                        (0x0000FF00U)
#define CSL_NSF4V_TN_SCALE_TN2_CFG_SHIFT                                       (0x00000008U)
#define CSL_NSF4V_TN_SCALE_TN2_CFG_MAX                                         (0x000000FFU)

#define CSL_NSF4V_TN_SCALE_TN1_CFG_MASK                                        (0x000000FFU)
#define CSL_NSF4V_TN_SCALE_TN1_CFG_SHIFT                                       (0x00000000U)
#define CSL_NSF4V_TN_SCALE_TN1_CFG_MAX                                         (0x000000FFU)

/* U_KNEE */

#define CSL_NSF4V_U_KNEE_U_KNEE_CFG_MASK                                       (0x0000003FU)
#define CSL_NSF4V_U_KNEE_U_KNEE_CFG_SHIFT                                      (0x00000000U)
#define CSL_NSF4V_U_KNEE_U_KNEE_CFG_MAX                                        (0x0000003FU)

/* WHITEBAL0 */

#define CSL_NSF4V_WHITEBAL0_GAIN1_CFG_MASK                                     (0x1FFF0000U)
#define CSL_NSF4V_WHITEBAL0_GAIN1_CFG_SHIFT                                    (0x00000010U)
#define CSL_NSF4V_WHITEBAL0_GAIN1_CFG_MAX                                      (0x00001FFFU)

#define CSL_NSF4V_WHITEBAL0_GAIN0_CFG_MASK                                     (0x00001FFFU)
#define CSL_NSF4V_WHITEBAL0_GAIN0_CFG_SHIFT                                    (0x00000000U)
#define CSL_NSF4V_WHITEBAL0_GAIN0_CFG_MAX                                      (0x00001FFFU)

/* WHITEBAL1 */

#define CSL_NSF4V_WHITEBAL1_GAIN3_CFG_MASK                                     (0x1FFF0000U)
#define CSL_NSF4V_WHITEBAL1_GAIN3_CFG_SHIFT                                    (0x00000010U)
#define CSL_NSF4V_WHITEBAL1_GAIN3_CFG_MAX                                      (0x00001FFFU)

#define CSL_NSF4V_WHITEBAL1_GAIN2_CFG_MASK                                     (0x00001FFFU)
#define CSL_NSF4V_WHITEBAL1_GAIN2_CFG_SHIFT                                    (0x00000000U)
#define CSL_NSF4V_WHITEBAL1_GAIN2_CFG_MAX                                      (0x00001FFFU)

/**************************************************************************
* Hardware Region  : MMR MEM Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t DBG_MEM[4096];             /* diag_mem_ram */
} CSL_nsf4v_memRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_NSF4V_MEM_DBG_MEM(DBG_MEM)                                         (0x00000000U+((DBG_MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DBG_MEM */

#define CSL_NSF4V_MEM_DBG_MEM_DATA_MASK                                        (0xFFFFFFFFU)
#define CSL_NSF4V_MEM_DBG_MEM_DATA_SHIFT                                       (0x00000000U)
#define CSL_NSF4V_MEM_DBG_MEM_DATA_MAX                                         (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif
