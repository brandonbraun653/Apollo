/*
 *  Copyright (C) 2020 Texas Instruments Incorporated
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

#ifndef CSLR_SOC_DEFINES_H_
#define CSLR_SOC_DEFINES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define CSL_MAX(x,y) ((x) > (y) ? (x) : (y))

/** \brief number of instances of CAL available */
#define CSL_CAL_PER_CNT                     (1U)
/** \brief Defines the total number of PPI available per CAL */
#define CSL_CAL_PPI_CNT                     (2U)
/** \brief Defines the total number of complex IO available per CAL */
#define CSL_CAL_CMPLXIO_CNT                 (1U)
/** \brief Defines the total number of pixel processing context
 *          available per CAL */
#define CSL_CAL_PIX_PROC_CTX_CNT            (4U)

/** @brief interrupt number for CAL. */
#define CSL_CAL_IRQ_NUM                     (71U)

/** @brief Number of UART instances */
#define CSL_UART_PER_CNT                    (3U)

/** @brief Number of McSPI instances */
#define CSL_MCSPI_PER_CNT                   (5U)

/** @brief Number of OSPI instances */
#define CSL_OSPI_PER_CNT                    (2U)

#ifndef CSL_MODIFICATION
#define SOC_DSP_L1P_BASE               (CSL_DSP_L1P_U_BASE)
#define SOC_DSP_L1D_BASE               (CSL_DSP_L1D_U_BASE)
#define SOC_DSP_L2_BASE                (CSL_DSP_L2_U_BASE)
#define SOC_DSP_ICFG_BASE              (CSL_DSP_ICFG_U_BASE - 0x800000U)
#endif

/* ESM number of groups */
#define ESM_NUM_GROUP_MAX                    (3U)
#define ESM_NUM_INTR_PER_GROUP               (128U)

/** @brief DSP TPCC A EVENT MAP */
#define EDMA_DSS_TPCC_A_EVT_RTIA_DMA_REQ0    0
#define EDMA_DSS_TPCC_A_EVT_RTIA_DMA_REQ1    1
#define EDMA_DSS_TPCC_A_EVT_RTIA_DMA_REQ2    2
#define EDMA_DSS_TPCC_A_EVT_RTIA_DMA_REQ3    3
#define EDMA_DSS_TPCC_A_EVT_RTIB_DMA_REQ0    4
#define EDMA_DSS_TPCC_A_EVT_RTIB_DMA_REQ1    5
#define EDMA_DSS_TPCC_A_EVT_RTIB_DMA_REQ2    6
#define EDMA_DSS_TPCC_A_EVT_RTIB_DMA_REQ3    7
#define EDMA_DSS_TPCC_A_EVT_WDT_DMA_REQ0     8
#define EDMA_DSS_TPCC_A_EVT_WDT_DMA_REQ1     9
#define EDMA_DSS_TPCC_A_EVT_WDT_DMA_REQ2     10
#define EDMA_DSS_TPCC_A_EVT_WDT_DMA_REQ3     11
#define EDMA_DSS_TPCC_A_EVT_MCRC_DMA_REQ0    12
#define EDMA_DSS_TPCC_A_EVT_MCRC_DMA_REQ1    13
#define EDMA_DSS_TPCC_A_EVT_SCIA_RX_DMA_REQ  14
#define EDMA_DSS_TPCC_A_EVT_SCIA_TX_DMA_REQ  15
#define EDMA_DSS_TPCC_A_EVT_SCIB_RX_DMA_REQ  16
#define EDMA_DSS_TPCC_A_EVT_SCIB_TX_DMA_REQ  17
#define EDMA_DSS_TPCC_A_EVT_CBUFF_DMA_REQ0   18
#define EDMA_DSS_TPCC_A_EVT_CBUFF_DMA_REQ1   19
#define EDMA_DSS_TPCC_A_EVT_CBUFF_DMA_REQ2   20
#define EDMA_DSS_TPCC_A_EVT_CBUFF_DMA_REQ3   21
#define EDMA_DSS_TPCC_A_EVT_CBUFF_DMA_REQ4   22
#define EDMA_DSS_TPCC_A_EVT_CBUFF_DMA_REQ5   23
#define EDMA_DSS_TPCC_A_EVT_CBUFF_DMA_REQ6   24
#define EDMA_DSS_TPCC_A_EVT_FREE_0           25
#define EDMA_DSS_TPCC_A_EVT_FREE_1           26
#define EDMA_DSS_TPCC_A_EVT_FREE_2           27
#define EDMA_DSS_TPCC_A_EVT_FREE_3           28
#define EDMA_DSS_TPCC_A_EVT_FREE_4           29
#define EDMA_DSS_TPCC_A_EVT_FREE_5           30
#define EDMA_DSS_TPCC_A_EVT_FREE_6           31
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ0     32
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ1     33
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ2     34
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ3     35
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ4     36
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ5     37
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ6     38
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ7     39
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ8     40
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ9     41
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ10    42
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ11    43
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ12    44
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ13    45
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ14    46
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ15    47
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ16    48
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ17    49
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ18    50
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ19    51
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ20    52
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ21    53
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ22    54
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ23    55
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ24    56
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ25    57
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ26    58
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ27    59
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ28    60
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ29    61
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ30    62
#define EDMA_DSS_TPCC_A_EVT_HWA_DMA_REQ31    63

/** @brief DSP TPCC B EVENT MAP */
#define EDMA_DSS_TPCC_B_EVT_RTIA_DMA_REQ0    0
#define EDMA_DSS_TPCC_B_EVT_RTIA_DMA_REQ1    1
#define EDMA_DSS_TPCC_B_EVT_RTIA_DMA_REQ2    2
#define EDMA_DSS_TPCC_B_EVT_RTIA_DMA_REQ3    3
#define EDMA_DSS_TPCC_B_EVT_RTIB_DMA_REQ0    4
#define EDMA_DSS_TPCC_B_EVT_RTIB_DMA_REQ1    5
#define EDMA_DSS_TPCC_B_EVT_RTIB_DMA_REQ2    6
#define EDMA_DSS_TPCC_B_EVT_RTIB_DMA_REQ3    7
#define EDMA_DSS_TPCC_B_EVT_WDT_DMA_REQ0     8
#define EDMA_DSS_TPCC_B_EVT_WDT_DMA_REQ1     9
#define EDMA_DSS_TPCC_B_EVT_WDT_DMA_REQ2     10
#define EDMA_DSS_TPCC_B_EVT_WDT_DMA_REQ3     11
#define EDMA_DSS_TPCC_B_EVT_MCRC_DMA_REQ0    12
#define EDMA_DSS_TPCC_B_EVT_MCRC_DMA_REQ1    13
#define EDMA_DSS_TPCC_B_EVT_SCIA_RX_DMA_REQ  14
#define EDMA_DSS_TPCC_B_EVT_SCIA_TX_DMA_REQ  15
#define EDMA_DSS_TPCC_B_EVT_SCIB_RX_DMA_REQ  16
#define EDMA_DSS_TPCC_B_EVT_SCIB_TX_DMA_REQ  17
#define EDMA_DSS_TPCC_B_EVT_CBUFF_DMA_REQ0   18
#define EDMA_DSS_TPCC_B_EVT_CBUFF_DMA_REQ1   19
#define EDMA_DSS_TPCC_B_EVT_CBUFF_DMA_REQ2   20
#define EDMA_DSS_TPCC_B_EVT_CBUFF_DMA_REQ3   21
#define EDMA_DSS_TPCC_B_EVT_CBUFF_DMA_REQ4   22
#define EDMA_DSS_TPCC_B_EVT_CBUFF_DMA_REQ5   23
#define EDMA_DSS_TPCC_B_EVT_CBUFF_DMA_REQ6   24
#define EDMA_DSS_TPCC_B_EVT_FREE_0           25
#define EDMA_DSS_TPCC_B_EVT_FREE_1           26
#define EDMA_DSS_TPCC_B_EVT_FREE_2           27
#define EDMA_DSS_TPCC_B_EVT_FREE_3           28
#define EDMA_DSS_TPCC_B_EVT_FREE_4           29
#define EDMA_DSS_TPCC_B_EVT_FREE_5           30
#define EDMA_DSS_TPCC_B_EVT_FREE_6           31
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ0     32
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ1     33
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ2     34
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ3     35
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ4     36
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ5     37
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ6     38
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ7     39
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ8     40
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ9     41
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ10    42
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ11    43
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ12    44
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ13    45
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ14    46
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ15    47
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ16    48
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ17    49
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ18    50
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ19    51
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ20    52
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ21    53
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ22    54
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ23    55
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ24    56
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ25    57
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ26    58
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ27    59
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ28    60
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ29    61
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ30    62
#define EDMA_DSS_TPCC_B_EVT_HWA_DMA_REQ31    63

/** @brief DSP TPCC C EVENT MAP */
#define EDMA_DSS_TPCC_C_EVT_RTIA_DMA_REQ0    0
#define EDMA_DSS_TPCC_C_EVT_RTIA_DMA_REQ1    1
#define EDMA_DSS_TPCC_C_EVT_RTIA_DMA_REQ2    2
#define EDMA_DSS_TPCC_C_EVT_RTIA_DMA_REQ3    3
#define EDMA_DSS_TPCC_C_EVT_RTIB_DMA_REQ0    4
#define EDMA_DSS_TPCC_C_EVT_RTIB_DMA_REQ1    5
#define EDMA_DSS_TPCC_C_EVT_RTIB_DMA_REQ2    6
#define EDMA_DSS_TPCC_C_EVT_RTIB_DMA_REQ3    7
#define EDMA_DSS_TPCC_C_EVT_WDT_DMA_REQ0     8
#define EDMA_DSS_TPCC_C_EVT_WDT_DMA_REQ1     9
#define EDMA_DSS_TPCC_C_EVT_WDT_DMA_REQ2     10
#define EDMA_DSS_TPCC_C_EVT_WDT_DMA_REQ3     11
#define EDMA_DSS_TPCC_C_EVT_MCRC_DMA_REQ0    12
#define EDMA_DSS_TPCC_C_EVT_MCRC_DMA_REQ1    13
#define EDMA_DSS_TPCC_C_EVT_SCIA_RX_DMA_REQ  14
#define EDMA_DSS_TPCC_C_EVT_SCIA_TX_DMA_REQ  15
#define EDMA_DSS_TPCC_C_EVT_SCIB_RX_DMA_REQ  16
#define EDMA_DSS_TPCC_C_EVT_SCIB_TX_DMA_REQ  17
#define EDMA_DSS_TPCC_C_EVT_CBUFF_DMA_REQ0   18
#define EDMA_DSS_TPCC_C_EVT_CBUFF_DMA_REQ1   19
#define EDMA_DSS_TPCC_C_EVT_CBUFF_DMA_REQ2   20
#define EDMA_DSS_TPCC_C_EVT_CBUFF_DMA_REQ3   21
#define EDMA_DSS_TPCC_C_EVT_CBUFF_DMA_REQ4   22
#define EDMA_DSS_TPCC_C_EVT_CBUFF_DMA_REQ5   23
#define EDMA_DSS_TPCC_C_EVT_CBUFF_DMA_REQ6   24
#define EDMA_DSS_TPCC_C_EVT_FREE_0           25
#define EDMA_DSS_TPCC_C_EVT_FREE_1           26
#define EDMA_DSS_TPCC_C_EVT_FREE_2           27
#define EDMA_DSS_TPCC_C_EVT_FREE_3           28
#define EDMA_DSS_TPCC_C_EVT_FREE_4           29
#define EDMA_DSS_TPCC_C_EVT_FREE_5           30
#define EDMA_DSS_TPCC_C_EVT_FREE_6           31
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ0     32
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ1     33
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ2     34
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ3     35
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ4     36
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ5     37
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ6     38
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ7     39
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ8     40
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ9     41
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ10    42
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ11    43
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ12    44
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ13    45
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ14    46
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ15    47
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ16    48
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ17    49
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ18    50
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ19    51
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ20    52
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ21    53
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ22    54
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ23    55
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ24    56
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ25    57
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ26    58
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ27    59
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ28    60
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ29    61
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ30    62
#define EDMA_DSS_TPCC_C_EVT_HWA_DMA_REQ31    63


/** @brief MSS TPCC A EVENT MAP */
#define EDMA_MSS_TPCC_A_EVT_SPIA_DMA_REQ0    0
#define EDMA_MSS_TPCC_A_EVT_SPIA_DMA_REQ1    1
#define EDMA_MSS_TPCC_A_EVT_SPIA_DMA_REQ2    2
#define EDMA_MSS_TPCC_A_EVT_SPIA_DMA_REQ3    3
#define EDMA_MSS_TPCC_A_EVT_SPIA_DMA_REQ4    4
#define EDMA_MSS_TPCC_A_EVT_SPIA_DMA_REQ5    5
#define EDMA_MSS_TPCC_A_EVT_SPIB_DMA_REQ0    6
#define EDMA_MSS_TPCC_A_EVT_SPIB_DMA_REQ1    7
#define EDMA_MSS_TPCC_A_EVT_SPIB_DMA_REQ2    8
#define EDMA_MSS_TPCC_A_EVT_SPIB_DMA_REQ3    9
#define EDMA_MSS_TPCC_A_EVT_SPIB_DMA_REQ4    10
#define EDMA_MSS_TPCC_A_EVT_SPIB_DMA_REQ5    11
#define EDMA_MSS_TPCC_A_EVT_QSPI_DMA_REQ0    12
#define EDMA_MSS_TPCC_A_EVT_MCRC_DMA_REQ0    13
#define EDMA_MSS_TPCC_A_EVT_MCRC_DMA_REQ1    14
#define EDMA_MSS_TPCC_A_EVT_RTIA_DMA_REQ0    15
#define EDMA_MSS_TPCC_A_EVT_RTIA_DMA_REQ1    16
#define EDMA_MSS_TPCC_A_EVT_RTIA_DMA_REQ2    17
#define EDMA_MSS_TPCC_A_EVT_RTIA_DMA_REQ3    18
#define EDMA_MSS_TPCC_A_EVT_RTIB_DMA_REQ0    19
#define EDMA_MSS_TPCC_A_EVT_RTIB_DMA_REQ1    20
#define EDMA_MSS_TPCC_A_EVT_RTIC_DMA_REQ0    21
#define EDMA_MSS_TPCC_A_EVT_RTIC_DMA_REQ1    22
#define EDMA_MSS_TPCC_A_EVT_WDT_DMA_REQ0     23
#define EDMA_MSS_TPCC_A_EVT_WDT_DMA_REQ1     24
#define EDMA_MSS_TPCC_A_EVT_WDT_DMA_REQ2     25
#define EDMA_MSS_TPCC_A_EVT_WDT_DMA_REQ3     26
#define EDMA_MSS_TPCC_A_EVT_ETPWMA_DMA_REQ0  27
#define EDMA_MSS_TPCC_A_EVT_ETPWMA_DMA_REQ1  28
#define EDMA_MSS_TPCC_A_EVT_ETPWMB_DMA_REQ0  29
#define EDMA_MSS_TPCC_A_EVT_ETPWMB_DMA_REQ1  30
#define EDMA_MSS_TPCC_A_EVT_ETPWMC_DMA_REQ0  31
#define EDMA_MSS_TPCC_A_EVT_ETPWMC_DMA_REQ1  32
#define EDMA_MSS_TPCC_A_EVT_MCANA_DMA_REQ0   33
#define EDMA_MSS_TPCC_A_EVT_MCANA_DMA_REQ1   34
#define EDMA_MSS_TPCC_A_EVT_MCANA_FE_INT1    35
#define EDMA_MSS_TPCC_A_EVT_MCANA_FE_INT2    36
#define EDMA_MSS_TPCC_A_EVT_MCANA_FE_INT4    37
#define EDMA_MSS_TPCC_A_EVT_MCANB_DMA_REQ0   38
#define EDMA_MSS_TPCC_A_EVT_MCANB_DMA_REQ1   39
#define EDMA_MSS_TPCC_A_EVT_MCANB_FE_INT1    40
#define EDMA_MSS_TPCC_A_EVT_MCANB_FE_INT2    41
#define EDMA_MSS_TPCC_A_EVT_MCANB_FE_INT4    42
#define EDMA_MSS_TPCC_A_EVT_RTIB_DMA_REQ2    43
#define EDMA_MSS_TPCC_A_EVT_RTIB_DMA_REQ3    44
#define EDMA_MSS_TPCC_A_EVT_RTIC_DMA_REQ2    45
#define EDMA_MSS_TPCC_A_EVT_RTIC_DMA_REQ3    46
#define EDMA_MSS_TPCC_A_EVT_GIO_PAD_INT0     49
#define EDMA_MSS_TPCC_A_EVT_GIO_PAD_INT1     50
#define EDMA_MSS_TPCC_A_EVT_GIO_PAD_INT2     51
#define EDMA_MSS_TPCC_A_EVT_GIO_PAD_INT3     52
#define EDMA_MSS_TPCC_A_EVT_GIO_PAD_INT4     53
#define EDMA_MSS_TPCC_A_EVT_I2C_DMA_REQ0     55
#define EDMA_MSS_TPCC_A_EVT_I2C_DMA_REQ1     56
#define EDMA_MSS_TPCC_A_EVT_SCIA_RX_DMA_REQ  57
#define EDMA_MSS_TPCC_A_EVT_SCIA_TX_DMA_REQ  58
#define EDMA_MSS_TPCC_A_EVT_SCIB_RX_DMA_REQ  59
#define EDMA_MSS_TPCC_A_EVT_SCIB_TX_DMA_REQ  60
#define EDMA_MSS_TPCC_A_EVT_CBUFF_DMA_REQ    63

/** @brief MSS TPCC B EVENT MAP */
#define EDMA_MSS_TPCC_B_EVT_MCRC_DMA_REQ0    0
#define EDMA_MSS_TPCC_B_EVT_MCRC_DMA_REQ1    1
#define EDMA_MSS_TPCC_B_EVT_ETPWMA_DMA_REQ0  2
#define EDMA_MSS_TPCC_B_EVT_ETPWMA_DMA_REQ1  3
#define EDMA_MSS_TPCC_B_EVT_ETPWMB_DMA_REQ0  4
#define EDMA_MSS_TPCC_B_EVT_ETPWMB_DMA_REQ1  5
#define EDMA_MSS_TPCC_B_EVT_ETPWMC_DMA_REQ0  6
#define EDMA_MSS_TPCC_B_EVT_ETPWMC_DMA_REQ1  7
#define EDMA_MSS_TPCC_B_EVT_MCANA_DMA_REQ0   8
#define EDMA_MSS_TPCC_B_EVT_MCANA_DMA_REQ1   9
#define EDMA_MSS_TPCC_B_EVT_MCANB_DMA_REQ0   10
#define EDMA_MSS_TPCC_B_EVT_MCANB_DMA_REQ1   11
#define EDMA_MSS_TPCC_B_EVT_GIO_PAD_INT0     16
#define EDMA_MSS_TPCC_B_EVT_GIO_PAD_INT1     17
#define EDMA_MSS_TPCC_B_EVT_GIO_PAD_INT2     18
#define EDMA_MSS_TPCC_B_EVT_GIO_PAD_INT3     19
#define EDMA_MSS_TPCC_B_EVT_GIO_PAD_INT4     20
#define EDMA_MSS_TPCC_B_EVT_MCANA_FE_INT1    43
#define EDMA_MSS_TPCC_B_EVT_MCANA_FE_INT2    44
#define EDMA_MSS_TPCC_B_EVT_MCANA_FE_INT3    45
#define EDMA_MSS_TPCC_B_EVT_MCANA_FE_INT4    46
#define EDMA_MSS_TPCC_B_EVT_MCANA_FE_INT5    47
#define EDMA_MSS_TPCC_B_EVT_MCANA_FE_INT6    48
#define EDMA_MSS_TPCC_B_EVT_MCANA_FE_INT7    49
#define EDMA_MSS_TPCC_B_EVT_MCANB_FE_INT1    50
#define EDMA_MSS_TPCC_B_EVT_MCANB_FE_INT2    51
#define EDMA_MSS_TPCC_B_EVT_MCANB_FE_INT3    52
#define EDMA_MSS_TPCC_B_EVT_MCANB_FE_INT4    53
#define EDMA_MSS_TPCC_B_EVT_MCANB_FE_INT5    54
#define EDMA_MSS_TPCC_B_EVT_MCANB_FE_INT6    55
#define EDMA_MSS_TPCC_B_EVT_MCANB_FE_INT7    56

/** @brief RCSS TPCC A EVENT MAP */
#define EDMA_RCSS_TPCC_A_EVT_SPIA_DMA_REQ0          0
#define EDMA_RCSS_TPCC_A_EVT_SPIA_DMA_REQ1          1
#define EDMA_RCSS_TPCC_A_EVT_SPIA_DMA_REQ2          2
#define EDMA_RCSS_TPCC_A_EVT_SPIA_DMA_REQ3          3
#define EDMA_RCSS_TPCC_A_EVT_SPIA_DMA_REQ4          4
#define EDMA_RCSS_TPCC_A_EVT_SPIA_DMA_REQ5          5
#define EDMA_RCSS_TPCC_A_EVT_SPIB_DMA_REQ0          6
#define EDMA_RCSS_TPCC_A_EVT_SPIB_DMA_REQ1          7
#define EDMA_RCSS_TPCC_A_EVT_SPIB_DMA_REQ2          8
#define EDMA_RCSS_TPCC_A_EVT_SPIB_DMA_REQ3          9
#define EDMA_RCSS_TPCC_A_EVT_SPIB_DMA_REQ4          10
#define EDMA_RCSS_TPCC_A_EVT_SPIB_DMA_REQ5          11
#define EDMA_RCSS_TPCC_A_EVT_ECAP_DMA_REQ           12
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOF_INT          16
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_INT          17
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX0_INT    18
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX1_INT    19
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX2_INT    20
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX3_INT    21
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX4_INT    22
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX5_INT    23
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX6_INT    24
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_EOL_CNTX7_INT    25
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_SOF_TRIG0_INT    26
#define EDMA_RCSS_TPCC_A_EVT_CSI2A_SOF_TRIG1_INT    27
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOF_INT          32
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_INT          33
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX0_INT    34
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX1_INT    35
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX2_INT    36
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX3_INT    37
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX4_INT    38
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX5_INT    39
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX6_INT    40
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_EOL_CNTX7_INT    41
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_SOF_TRIG0_INT    42
#define EDMA_RCSS_TPCC_A_EVT_CSI2B_SOF_TRIG1_INT    43
#define EDMA_RCSS_TPCC_A_EVT_SCIA_TX_SINGLE_REQ     44
#define EDMA_RCSS_TPCC_A_EVT_SCIA_TX_BURST_REQ      45
#define EDMA_RCSS_TPCC_A_EVT_MCASPA_TX_REQ          48
#define EDMA_RCSS_TPCC_A_EVT_MCASPB_TX_REQ          49
#define EDMA_RCSS_TPCC_A_EVT_MCASPC_TX_REQ          50
#define EDMA_RCSS_TPCC_A_EVT_MCASPA_RX_REQ          51
#define EDMA_RCSS_TPCC_A_EVT_MCASPB_RX_REQ          52
#define EDMA_RCSS_TPCC_A_EVT_MCASPC_RX_REQ          53
#define EDMA_RCSS_TPCC_A_EVT_I2CA_TX_DMA_REQ        54
#define EDMA_RCSS_TPCC_A_EVT_I2CA_RX_DMA_REQ        55
#define EDMA_RCSS_TPCC_A_EVT_I2CB_TX_DMA_REQ        56
#define EDMA_RCSS_TPCC_A_EVT_I2CB_RX_DMA_REQ        57
#define EDMA_RCSS_TPCC_A_EVT_SCIA_RX_SINGLE_REQ     58
#define EDMA_RCSS_TPCC_A_EVT_SCIA_RX_BURST_REQ      59


#define EDMA_DSS_TPCC_A_NUM_PARAM_SETS  (128U)
#define EDMA_DSS_TPCC_A_NUM_TC          (2U)

#define EDMA_DSS_TPCC_B_NUM_PARAM_SETS  (128U)
#define EDMA_DSS_TPCC_B_NUM_TC          (2U)

#define EDMA_DSS_TPCC_C_NUM_PARAM_SETS  (256U)

/*! Note even though EDMA's CCCFG register indicates 6 TCs for CC2, only first 2
 *  are verified for radar processing flows, hence we limit to 2 TCs. */
#define EDMA_DSS_TPCC_C_NUM_TC          (2U)

#define EDMA_RCSS_TPCC_A_NUM_PARAM_SETS  (128U)
#define EDMA_RCSS_TPCC_A_NUM_TC          (2U)

#define EDMA_MSS_TPCC_A_NUM_PARAM_SETS  (128U)
#define EDMA_MSS_TPCC_A_NUM_TC          (2U)

#define EDMA_MSS_TPCC_B_NUM_PARAM_SETS  (128U)
#define EDMA_MSS_TPCC_B_NUM_TC          (1U)

#define EDMA_HSM_TPCC_A_NUM_PARAM_SETS  (128U)
#define EDMA_HSM_TPCC_A_NUM_TC          (2U)

#define EDMA_TPCC_ERRAGG_TPCC_EERINT__POS   (0U)
#define EDMA_TPCC_INTAGG_TPCC_INTG__POS     (0U)
#define EDMA_TPCC_ERRAGG_TPTC_MIN_ERR__POS  (2U) /* position of the lowest TC Id, others are higher */


/* DSS definitions of EDMA instance IDs for application usage */
//TODO_TPR12: When RCSS is enabled on QT, change order to make RCSS instance first.
#define EDMA_DSS_INSTANCE_ID_DSS_TPCC_A    (0U)
#define EDMA_DSS_INSTANCE_ID_DSS_TPCC_B    (1U)
#define EDMA_DSS_INSTANCE_ID_DSS_TPCC_C    (2U)
#define EDMA_DSS_INSTANCE_ID_RCSS_TPCC_A   (3U)

#define EDMA_DSS_NUM_CC        4

#define EDMA_DSS_MAX_NUM_TC     CSL_MAX(EDMA_DSS_TPCC_A_NUM_TC, \
                                CSL_MAX(EDMA_DSS_TPCC_B_NUM_TC, \
                                CSL_MAX(EDMA_DSS_TPCC_C_NUM_TC, \
                                EDMA_RCSS_TPCC_A_NUM_TC)))

#define EDMA_DSS_NUM_TC_IN_CC0  EDMA_DSS_TPCC_A_NUM_TC
#define EDMA_DSS_NUM_TC_IN_CC1  EDMA_DSS_TPCC_B_NUM_TC
#define EDMA_DSS_NUM_TC_IN_CC2  EDMA_DSS_TPCC_C_NUM_TC
#define EDMA_DSS_NUM_TC_IN_CC3  EDMA_RCSS_TPCC_A_NUM_TC

#define EDMA_DSS_NUM_PARAM_SETS_CC0   EDMA_DSS_TPCC_A_NUM_PARAM_SETS
#define EDMA_DSS_NUM_PARAM_SETS_CC1   EDMA_DSS_TPCC_B_NUM_PARAM_SETS
#define EDMA_DSS_NUM_PARAM_SETS_CC2   EDMA_DSS_TPCC_C_NUM_PARAM_SETS
#define EDMA_DSS_NUM_PARAM_SETS_CC3   EDMA_RCSS_TPCC_A_NUM_PARAM_SETS


/* MSS definitions of EDMA instance IDs for application usage */
//TODO_TPR12: When RCSS is enabled on QT, change order to make RCSS instance first.
#define EDMA_MSS_INSTANCE_ID_MSS_TPCC_A    (0U)
#define EDMA_MSS_INSTANCE_ID_MSS_TPCC_B    (1U)
#define EDMA_MSS_INSTANCE_ID_DSS_TPCC_A    (2U)
#define EDMA_MSS_INSTANCE_ID_DSS_TPCC_B    (3U)
#define EDMA_MSS_INSTANCE_ID_DSS_TPCC_C    (4U)
#define EDMA_MSS_INSTANCE_ID_RCSS_TPCC_A   (5U)

#define EDMA_MSS_NUM_CC        6

#define EDMA_MSS_MAX_NUM_TC     CSL_MAX(EDMA_MSS_TPCC_A_NUM_TC, \
                                CSL_MAX(EDMA_MSS_TPCC_B_NUM_TC, \
                                CSL_MAX(EDMA_DSS_TPCC_A_NUM_TC, \
                                CSL_MAX(EDMA_DSS_TPCC_B_NUM_TC, \
                                CSL_MAX(EDMA_DSS_TPCC_C_NUM_TC, \
                                EDMA_RCSS_TPCC_A_NUM_TC)))))

#define EDMA_MSS_NUM_TC_IN_CC0  EDMA_MSS_TPCC_A_NUM_TC
#define EDMA_MSS_NUM_TC_IN_CC1  EDMA_MSS_TPCC_B_NUM_TC
#define EDMA_MSS_NUM_TC_IN_CC2  EDMA_DSS_TPCC_A_NUM_TC
#define EDMA_MSS_NUM_TC_IN_CC3  EDMA_DSS_TPCC_B_NUM_TC
#define EDMA_MSS_NUM_TC_IN_CC4  EDMA_DSS_TPCC_C_NUM_TC
#define EDMA_MSS_NUM_TC_IN_CC5  EDMA_RCSS_TPCC_A_NUM_TC

#define EDMA_MSS_NUM_PARAM_SETS_CC0   EDMA_MSS_TPCC_A_NUM_PARAM_SETS
#define EDMA_MSS_NUM_PARAM_SETS_CC1   EDMA_MSS_TPCC_B_NUM_PARAM_SETS
#define EDMA_MSS_NUM_PARAM_SETS_CC2   EDMA_DSS_TPCC_A_NUM_PARAM_SETS
#define EDMA_MSS_NUM_PARAM_SETS_CC3   EDMA_DSS_TPCC_B_NUM_PARAM_SETS
#define EDMA_MSS_NUM_PARAM_SETS_CC4   EDMA_DSS_TPCC_C_NUM_PARAM_SETS
#define EDMA_MSS_NUM_PARAM_SETS_CC5   EDMA_RCSS_TPCC_A_NUM_PARAM_SETS

/***********************************************************************
 * Peripheral number of instance definition
 ***********************************************************************/
#define HWA_NUM_INSTANCES            (1U)

/***********************************************************************
 * MSS - CLOCK settings
 ***********************************************************************/
 /* Sys_vclk : 200MHz */
#define MSS_SYS_VCLK                  200000000U
#define R5F_CLOCK_MHZ                 400U

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/*! @brief R5F to Hardware Accelerator address translation macro. */
//#define ADDR_TRANSLATE_CPU_TO_HWA(x)  (uint16_t)(((uint32_t)(x) - SOC_XWR18XX_MSS_HWA_MEM0_BASE_ADDRESS) & 0x0000FFFFU)


/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif  /* CSLR_SOC_DEFINES_H_ */
