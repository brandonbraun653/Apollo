/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_atl.h
*/
#ifndef CSLR_ATL_H_
#define CSLR_ATL_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_ATL_MMR_REGS_BASE                                                  (0x00000000U)


/**************************************************************************
* Hardware Region  : ATL Control Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t REVISION;                  /* Peripheral Revision Register */
    volatile uint8_t  Resv_512[508];
    volatile uint32_t ATL0_PPMR;                 /* ATL0 Parts Per Million Register */
    volatile uint32_t ATL0_BBSR;                 /* ATL0 Baseband Sampler Register */
    volatile uint32_t ATL0_ATLCR;                /* ATL0 Configuration Register */
    volatile uint8_t  Resv_528[4];
    volatile uint32_t ATL0_SWEN;                 /* ATL0 Software Enable */
    volatile uint32_t ATL0_BWSMUX;               /* ATL0 BWS Mux Select */
    volatile uint32_t ATL0_AWSMUX;               /* ATL0 AWS Mux Select */
    volatile uint32_t ATL0_PCLKMUX;              /* ATL PCLK Mux Select */
    volatile uint8_t  Resv_640[96];
    volatile uint32_t ATL1_PPMR;                 /* ATL1 Parts Per Million Register */
    volatile uint32_t ATL1_BBSR;                 /* ATL1 Baseband Sampler Register */
    volatile uint32_t ATL1_ATLCR;                /* ATL1 Configuration Register */
    volatile uint8_t  Resv_656[4];
    volatile uint32_t ATL1_SWEN;                 /* ATL1 Software Enable */
    volatile uint32_t ATL1_BWSMUX;               /* ATL1 BWS Mux Select */
    volatile uint32_t ATL1_AWSMUX;               /* ATL1 AWS Mux Select */
    volatile uint32_t ATL1_PCLKMUX;              /* ATL1 PCLK Mux Select */
    volatile uint8_t  Resv_768[96];
    volatile uint32_t ATL2_PPMR;                 /* ATL2 Parts Per Million Register */
    volatile uint32_t ATL2_BBSR;                 /* ATL2 Baseband Sampler Register */
    volatile uint32_t ATL2_ATLCR;                /* ATL2 Configuration Register */
    volatile uint8_t  Resv_784[4];
    volatile uint32_t ATL2_SWEN;                 /* ATL2 Software Enable */
    volatile uint32_t ATL2_BWSMUX;               /* ATL2 BWS Mux Select */
    volatile uint32_t ATL2_AWSMUX;               /* ATL2 AWS Mux Select */
    volatile uint32_t ATL2_PCLKMUX;              /* ATL2 PCLK Mux Select */
    volatile uint8_t  Resv_896[96];
    volatile uint32_t ATL3_PPMR;                 /* ATL3 Parts Per Million Register */
    volatile uint32_t ATL3_BBSR;                 /* ATL3 Baseband Sampler Register */
    volatile uint32_t ATL3_ATLCR;                /* ATL3 Configuration Register */
    volatile uint8_t  Resv_912[4];
    volatile uint32_t ATL3_SWEN;                 /* ATL3 Software Enable */
    volatile uint32_t ATL3_BWSMUX;               /* ATL3 BWS Mux Select */
    volatile uint32_t ATL3_AWSMUX;               /* ATL3 AWS Mux Select */
    volatile uint32_t ATL3_PCLKMUX;              /* ATL3 PCLK Mux Select */
} CSL_atl_mmrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_ATL_MMR_REVISION                                                   (0x00000000U)
#define CSL_ATL_MMR_ATL0_PPMR                                                  (0x00000200U)
#define CSL_ATL_MMR_ATL0_BBSR                                                  (0x00000204U)
#define CSL_ATL_MMR_ATL0_ATLCR                                                 (0x00000208U)
#define CSL_ATL_MMR_ATL0_SWEN                                                  (0x00000210U)
#define CSL_ATL_MMR_ATL0_BWSMUX                                                (0x00000214U)
#define CSL_ATL_MMR_ATL0_AWSMUX                                                (0x00000218U)
#define CSL_ATL_MMR_ATL0_PCLKMUX                                               (0x0000021CU)
#define CSL_ATL_MMR_ATL1_PPMR                                                  (0x00000280U)
#define CSL_ATL_MMR_ATL1_BBSR                                                  (0x00000284U)
#define CSL_ATL_MMR_ATL1_ATLCR                                                 (0x00000288U)
#define CSL_ATL_MMR_ATL1_SWEN                                                  (0x00000290U)
#define CSL_ATL_MMR_ATL1_BWSMUX                                                (0x00000294U)
#define CSL_ATL_MMR_ATL1_AWSMUX                                                (0x00000298U)
#define CSL_ATL_MMR_ATL1_PCLKMUX                                               (0x0000029CU)
#define CSL_ATL_MMR_ATL2_PPMR                                                  (0x00000300U)
#define CSL_ATL_MMR_ATL2_BBSR                                                  (0x00000304U)
#define CSL_ATL_MMR_ATL2_ATLCR                                                 (0x00000308U)
#define CSL_ATL_MMR_ATL2_SWEN                                                  (0x00000310U)
#define CSL_ATL_MMR_ATL2_BWSMUX                                                (0x00000314U)
#define CSL_ATL_MMR_ATL2_AWSMUX                                                (0x00000318U)
#define CSL_ATL_MMR_ATL2_PCLKMUX                                               (0x0000031CU)
#define CSL_ATL_MMR_ATL3_PPMR                                                  (0x00000380U)
#define CSL_ATL_MMR_ATL3_BBSR                                                  (0x00000384U)
#define CSL_ATL_MMR_ATL3_ATLCR                                                 (0x00000388U)
#define CSL_ATL_MMR_ATL3_SWEN                                                  (0x00000390U)
#define CSL_ATL_MMR_ATL3_BWSMUX                                                (0x00000394U)
#define CSL_ATL_MMR_ATL3_AWSMUX                                                (0x00000398U)
#define CSL_ATL_MMR_ATL3_PCLKMUX                                               (0x0000039CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REVISION */

#define CSL_ATL_MMR_REVISION_MINOR_MASK                                        (0x0000003FU)
#define CSL_ATL_MMR_REVISION_MINOR_SHIFT                                       (0x00000000U)
#define CSL_ATL_MMR_REVISION_MINOR_MAX                                         (0x0000003FU)

#define CSL_ATL_MMR_REVISION_CUSTOM_MASK                                       (0x000000C0U)
#define CSL_ATL_MMR_REVISION_CUSTOM_SHIFT                                      (0x00000006U)
#define CSL_ATL_MMR_REVISION_CUSTOM_MAX                                        (0x00000003U)

#define CSL_ATL_MMR_REVISION_MAJOR_MASK                                        (0x00000700U)
#define CSL_ATL_MMR_REVISION_MAJOR_SHIFT                                       (0x00000008U)
#define CSL_ATL_MMR_REVISION_MAJOR_MAX                                         (0x00000007U)

#define CSL_ATL_MMR_REVISION_RTL_MASK                                          (0x0000F800U)
#define CSL_ATL_MMR_REVISION_RTL_SHIFT                                         (0x0000000BU)
#define CSL_ATL_MMR_REVISION_RTL_MAX                                           (0x0000001FU)

#define CSL_ATL_MMR_REVISION_FUNCTION_MASK                                     (0x0FFF0000U)
#define CSL_ATL_MMR_REVISION_FUNCTION_SHIFT                                    (0x00000010U)
#define CSL_ATL_MMR_REVISION_FUNCTION_MAX                                      (0x00000FFFU)

#define CSL_ATL_MMR_REVISION_RESERVED_MASK                                     (0x30000000U)
#define CSL_ATL_MMR_REVISION_RESERVED_SHIFT                                    (0x0000001CU)
#define CSL_ATL_MMR_REVISION_RESERVED_MAX                                      (0x00000003U)

#define CSL_ATL_MMR_REVISION_SCHEME_MASK                                       (0xC0000000U)
#define CSL_ATL_MMR_REVISION_SCHEME_SHIFT                                      (0x0000001EU)
#define CSL_ATL_MMR_REVISION_SCHEME_MAX                                        (0x00000003U)

/* ATL0_PPMR */

#define CSL_ATL_MMR_ATL0_PPMR_PPM_SET_MASK                                     (0x000001FFU)
#define CSL_ATL_MMR_ATL0_PPMR_PPM_SET_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL0_PPMR_PPM_SET_MAX                                      (0x000001FFU)

#define CSL_ATL_MMR_ATL0_PPMR_PPM_SD_MASK                                      (0x00008000U)
#define CSL_ATL_MMR_ATL0_PPMR_PPM_SD_SHIFT                                     (0x0000000FU)
#define CSL_ATL_MMR_ATL0_PPMR_PPM_SD_MAX                                       (0x00000001U)

/* ATL0_BBSR */

#define CSL_ATL_MMR_ATL0_BBSR_SMP_CNT_MASK                                     (0x0000FFFFU)
#define CSL_ATL_MMR_ATL0_BBSR_SMP_CNT_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL0_BBSR_SMP_CNT_MAX                                      (0x0000FFFFU)

/* ATL0_ATLCR */

#define CSL_ATL_MMR_ATL0_ATLCR_INT_DIV_MASK                                    (0x0000001FU)
#define CSL_ATL_MMR_ATL0_ATLCR_INT_DIV_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL0_ATLCR_INT_DIV_MAX                                     (0x0000001FU)

#define CSL_ATL_MMR_ATL0_ATLCR_CLK_DIV_SEL_MASK                                (0x00000020U)
#define CSL_ATL_MMR_ATL0_ATLCR_CLK_DIV_SEL_SHIFT                               (0x00000005U)
#define CSL_ATL_MMR_ATL0_ATLCR_CLK_DIV_SEL_MAX                                 (0x00000001U)

/* ATL0_SWEN */

#define CSL_ATL_MMR_ATL0_SWEN_ENABLE_MASK                                      (0x00000001U)
#define CSL_ATL_MMR_ATL0_SWEN_ENABLE_SHIFT                                     (0x00000000U)
#define CSL_ATL_MMR_ATL0_SWEN_ENABLE_MAX                                       (0x00000001U)

/* ATL0_BWSMUX */

#define CSL_ATL_MMR_ATL0_BWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL0_BWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL0_BWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL0_AWSMUX */

#define CSL_ATL_MMR_ATL0_AWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL0_AWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL0_AWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL0_PCLKMUX */

#define CSL_ATL_MMR_ATL0_PCLKMUX_SELECT_MASK                                   (0x00000001U)
#define CSL_ATL_MMR_ATL0_PCLKMUX_SELECT_SHIFT                                  (0x00000000U)
#define CSL_ATL_MMR_ATL0_PCLKMUX_SELECT_MAX                                    (0x00000001U)

/* ATL1_PPMR */

#define CSL_ATL_MMR_ATL1_PPMR_PPM_SET_MASK                                     (0x000001FFU)
#define CSL_ATL_MMR_ATL1_PPMR_PPM_SET_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL1_PPMR_PPM_SET_MAX                                      (0x000001FFU)

#define CSL_ATL_MMR_ATL1_PPMR_PPM_SD_MASK                                      (0x00008000U)
#define CSL_ATL_MMR_ATL1_PPMR_PPM_SD_SHIFT                                     (0x0000000FU)
#define CSL_ATL_MMR_ATL1_PPMR_PPM_SD_MAX                                       (0x00000001U)

/* ATL1_BBSR */

#define CSL_ATL_MMR_ATL1_BBSR_SMP_CNT_MASK                                     (0x0000FFFFU)
#define CSL_ATL_MMR_ATL1_BBSR_SMP_CNT_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL1_BBSR_SMP_CNT_MAX                                      (0x0000FFFFU)

/* ATL1_ATLCR */

#define CSL_ATL_MMR_ATL1_ATLCR_INT_DIV_MASK                                    (0x0000001FU)
#define CSL_ATL_MMR_ATL1_ATLCR_INT_DIV_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL1_ATLCR_INT_DIV_MAX                                     (0x0000001FU)

#define CSL_ATL_MMR_ATL1_ATLCR_CLK_DIV_SEL_MASK                                (0x00000020U)
#define CSL_ATL_MMR_ATL1_ATLCR_CLK_DIV_SEL_SHIFT                               (0x00000005U)
#define CSL_ATL_MMR_ATL1_ATLCR_CLK_DIV_SEL_MAX                                 (0x00000001U)

/* ATL1_SWEN */

#define CSL_ATL_MMR_ATL1_SWEN_ENABLE_MASK                                      (0x00000001U)
#define CSL_ATL_MMR_ATL1_SWEN_ENABLE_SHIFT                                     (0x00000000U)
#define CSL_ATL_MMR_ATL1_SWEN_ENABLE_MAX                                       (0x00000001U)

/* ATL1_BWSMUX */

#define CSL_ATL_MMR_ATL1_BWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL1_BWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL1_BWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL1_AWSMUX */

#define CSL_ATL_MMR_ATL1_AWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL1_AWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL1_AWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL1_PCLKMUX */

#define CSL_ATL_MMR_ATL1_PCLKMUX_SELECT_MASK                                   (0x00000001U)
#define CSL_ATL_MMR_ATL1_PCLKMUX_SELECT_SHIFT                                  (0x00000000U)
#define CSL_ATL_MMR_ATL1_PCLKMUX_SELECT_MAX                                    (0x00000001U)

/* ATL2_PPMR */

#define CSL_ATL_MMR_ATL2_PPMR_PPM_SET_MASK                                     (0x000001FFU)
#define CSL_ATL_MMR_ATL2_PPMR_PPM_SET_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL2_PPMR_PPM_SET_MAX                                      (0x000001FFU)

#define CSL_ATL_MMR_ATL2_PPMR_PPM_SD_MASK                                      (0x00008000U)
#define CSL_ATL_MMR_ATL2_PPMR_PPM_SD_SHIFT                                     (0x0000000FU)
#define CSL_ATL_MMR_ATL2_PPMR_PPM_SD_MAX                                       (0x00000001U)

/* ATL2_BBSR */

#define CSL_ATL_MMR_ATL2_BBSR_SMP_CNT_MASK                                     (0x0000FFFFU)
#define CSL_ATL_MMR_ATL2_BBSR_SMP_CNT_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL2_BBSR_SMP_CNT_MAX                                      (0x0000FFFFU)

/* ATL2_ATLCR */

#define CSL_ATL_MMR_ATL2_ATLCR_INT_DIV_MASK                                    (0x0000001FU)
#define CSL_ATL_MMR_ATL2_ATLCR_INT_DIV_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL2_ATLCR_INT_DIV_MAX                                     (0x0000001FU)

#define CSL_ATL_MMR_ATL2_ATLCR_CLK_DIV_SEL_MASK                                (0x00000020U)
#define CSL_ATL_MMR_ATL2_ATLCR_CLK_DIV_SEL_SHIFT                               (0x00000005U)
#define CSL_ATL_MMR_ATL2_ATLCR_CLK_DIV_SEL_MAX                                 (0x00000001U)

/* ATL2_SWEN */

#define CSL_ATL_MMR_ATL2_SWEN_ENABLE_MASK                                      (0x00000001U)
#define CSL_ATL_MMR_ATL2_SWEN_ENABLE_SHIFT                                     (0x00000000U)
#define CSL_ATL_MMR_ATL2_SWEN_ENABLE_MAX                                       (0x00000001U)

/* ATL2_BWSMUX */

#define CSL_ATL_MMR_ATL2_BWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL2_BWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL2_BWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL2_AWSMUX */

#define CSL_ATL_MMR_ATL2_AWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL2_AWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL2_AWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL2_PCLKMUX */

#define CSL_ATL_MMR_ATL2_PCLKMUX_SELECT_MASK                                   (0x00000001U)
#define CSL_ATL_MMR_ATL2_PCLKMUX_SELECT_SHIFT                                  (0x00000000U)
#define CSL_ATL_MMR_ATL2_PCLKMUX_SELECT_MAX                                    (0x00000001U)

/* ATL3_PPMR */

#define CSL_ATL_MMR_ATL3_PPMR_PPM_SET_MASK                                     (0x000001FFU)
#define CSL_ATL_MMR_ATL3_PPMR_PPM_SET_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL3_PPMR_PPM_SET_MAX                                      (0x000001FFU)

#define CSL_ATL_MMR_ATL3_PPMR_PPM_SD_MASK                                      (0x00008000U)
#define CSL_ATL_MMR_ATL3_PPMR_PPM_SD_SHIFT                                     (0x0000000FU)
#define CSL_ATL_MMR_ATL3_PPMR_PPM_SD_MAX                                       (0x00000001U)

/* ATL3_BBSR */

#define CSL_ATL_MMR_ATL3_BBSR_SMP_CNT_MASK                                     (0x0000FFFFU)
#define CSL_ATL_MMR_ATL3_BBSR_SMP_CNT_SHIFT                                    (0x00000000U)
#define CSL_ATL_MMR_ATL3_BBSR_SMP_CNT_MAX                                      (0x0000FFFFU)

/* ATL3_ATLCR */

#define CSL_ATL_MMR_ATL3_ATLCR_INT_DIV_MASK                                    (0x0000001FU)
#define CSL_ATL_MMR_ATL3_ATLCR_INT_DIV_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL3_ATLCR_INT_DIV_MAX                                     (0x0000001FU)

#define CSL_ATL_MMR_ATL3_ATLCR_CLK_DIV_SEL_MASK                                (0x00000020U)
#define CSL_ATL_MMR_ATL3_ATLCR_CLK_DIV_SEL_SHIFT                               (0x00000005U)
#define CSL_ATL_MMR_ATL3_ATLCR_CLK_DIV_SEL_MAX                                 (0x00000001U)

/* ATL3_SWEN */

#define CSL_ATL_MMR_ATL3_SWEN_ENABLE_MASK                                      (0x00000001U)
#define CSL_ATL_MMR_ATL3_SWEN_ENABLE_SHIFT                                     (0x00000000U)
#define CSL_ATL_MMR_ATL3_SWEN_ENABLE_MAX                                       (0x00000001U)

/* ATL3_BWSMUX */

#define CSL_ATL_MMR_ATL3_BWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL3_BWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL3_BWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL3_AWSMUX */

#define CSL_ATL_MMR_ATL3_AWSMUX_SELECT_MASK                                    (0x0000000FU)
#define CSL_ATL_MMR_ATL3_AWSMUX_SELECT_SHIFT                                   (0x00000000U)
#define CSL_ATL_MMR_ATL3_AWSMUX_SELECT_MAX                                     (0x0000000FU)

/* ATL3_PCLKMUX */

#define CSL_ATL_MMR_ATL3_PCLKMUX_SELECT_MASK                                   (0x00000001U)
#define CSL_ATL_MMR_ATL3_PCLKMUX_SELECT_SHIFT                                  (0x00000000U)
#define CSL_ATL_MMR_ATL3_PCLKMUX_SELECT_MAX                                    (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif
