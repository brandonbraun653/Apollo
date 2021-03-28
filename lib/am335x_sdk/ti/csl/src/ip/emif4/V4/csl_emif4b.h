/**
 *   @file  csl_emif4b.h
 *
 *   @brief
 *      This is the main header file for the EMIF4F Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
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

/** @defgroup CSL_EMIF4F_API EMIF4F
 *
 * @section Introduction
 *  The External Memory Interface (EMIF) is a TI developed re-usable IP component
 *  targeted for SOC designs. The EMIF is a VBUSM slave peripheral providing an
 *  interface to a wide variety of DDR SDRAM. This memory controller is a soft
 *  macro and must be used with the DDR PHY hard macros to interface to the
 *  DDR SDRAM.
 *
 * @subsection References
 *   -# EMIF4F Functional Specification
 */

#ifndef CSL_EMIF4B_H_
#define CSL_EMIF4B_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_emif4f.h>

/**
@defgroup CSL_EMIF4F_SYMBOL  EMIF4F Symbols Defined
@ingroup CSL_EMIF4F_API
*/
/**
@defgroup CSL_EMIF4F_DATASTRUCT  EMIF4F Data Structures
@ingroup CSL_EMIF4F_API
*/
/**
@defgroup CSL_EMIF4F_FUNCTION  EMIF4F Functions
@ingroup CSL_EMIF4F_API
*/

/**
@addtogroup CSL_EMIF4F_SYMBOL
@{
*/

/**
 *  Handle to access EMIF4F registers accessible through config bus.
 */
#define hEmifb     ((CSL_EmifbRegs*)CSL_EMIFB_0_REGS)

/**
@}
*/

/** @addtogroup CSL_EMIF4F_DATASTRUCT
 @{ */

/** @brief This is the handle to the MPU Register */
typedef volatile CSL_EmifbRegs*   CSL_EmifbHandle;

/** @brief EMIF4F SDRAM Configuration
 *
 * This structure is used to define the EMIF4F SDRAM
 * Configuration
 */
typedef struct EMIFB_SDRAM_CONFIG
{
    Uint8   iBankPos;
    Uint8   mSdrmEnable;
    Uint8   bootUnlock;
    Uint8   sdRen;
    Uint8   timUnlock;
    Uint8   nm;
    Uint8   cl;
    Uint8   iBank;
    Uint8   eBank;
    Uint8   pageSize;

    Uint8   NVMEnable;
    Uint8   eBankPos;
    Uint8   rdbNum;
    Uint8   rdbSize;
}EMIFB_SDRAM_CONFIG;

/** @brief EMIF4F SDRAM Refresh Control Register Configuration
 *
 * This structure is used to define the EMIF4F SDRAM Refresh Control Register
 * Configuration
 */
typedef struct EMIFB_SDRFC_CONFIG
{
    Uint8   lpMode;
    Uint8   mclkStop_en;
    Uint8   sr_pd;
    Uint16   refresh_rate;
}EMIFB_SDRFC_CONFIG;

/** @brief EMIF4F Timing1 Configuration
 *
 * This structure is used to define the EMIF4F Timing1
 * Configuration
 */
typedef struct EMIFB_TIMING1_CONFIG
{
    Uint8   t_rfc;
    Uint8   t_rp;
    Uint8   t_rcd;
    Uint8   t_wr;
    Uint8   t_ras;
    Uint8   t_rc;
    Uint8   t_rrd;
}EMIFB_TIMING1_CONFIG;

/** @brief EMIF4F Timing2 Configuration
 *
 * This structure is used to define the EMIF4F Timing2
 * Configuration
 */
typedef struct EMIFB_TIMING2_CONFIG
{
	Uint8	t_ras_max;
	Uint8	t_xsr;
	Uint8	t_cke;
}EMIFB_TIMING2_CONFIG;

/** @brief EMIF4F SDRAM configuration 2 register
 *
 * This structure is used to define the EMIF4F SDRAM configuration 2 register
 * Configuration
 */
typedef struct EMIFB_SDCFG2_REG
{
    Uint8   pasr;
    Uint8   rowSize;
}EMIFB_SDCFG2_REG;

/** @brief Peripheral Bus Burst Priority Register
 *
 * This structure is used to define the Peripheral Bus Burst Priority Register
 */
typedef struct EMIFB_BPRIO_REG
{
    Uint8   prio_raise;
}EMIFB_BPRIO_REG;

/** @brief Performance Counter Configuration Register
 *
 * This structure is used to define the Performance Counter Configuration Register
 */
typedef struct EMIFB_PCC_CONFIG
{
    Uint8   cntr2_mstid_en;
    Uint8   cntr2_region_en;
    Uint8   cntr2_cfg;
    Uint8   cntr1_mstid_en;
    Uint8   cntr1_region_en;
    Uint8   cntr1_cfg;
}EMIFB_PCC_CONFIG;

/** @brief Performance Counter Master Region Select Register
 *
 * This structure is used to define the Performance Counter Master Region Select Register
 */
typedef struct EMIFB_PCMRS_REG
{
    Uint8   mst_id2;
    Uint8   region_sel2;
    Uint8   mst_id1;
    Uint8   region_sel1;
}EMIFB_PCMRS_REG;

/** @brief IODFT Control Values
 *
 * This structure is used to define the IODFT Test Logic Global
 * Control Values.
 */
typedef struct EMIFB_IODFT_CONTROL
{
    Uint16  tlec;
    Uint8   mt;
    Uint8   actCapEn;
    Uint8   opgld;
    Uint8   mms;
    Uint8   mc;
    Uint8   pc;
    Uint8   tm;
}EMIFB_IODFT_CONTROL;

/** @brief Performance Counter Configuration
 *
 * This structure is used to define the performance counter
 * configuration
 */
typedef struct EMIFB_PERF_CONFIG
{
    Uint8  mstIDEn;
    Uint8  regEn;
    Uint8  cntCfg;
}EMIFB_PERF_CONFIG;

/** @brief SDRAM Output Impedance Calibration Configuation
 *
 * This structure is used to define the SDRAM Output Impedance
 * Calibration Configuration.
 */
typedef struct EMIFB_OUTPUT_IMP_CONFIG
{
    Uint8   zqCS1En;
    Uint8   zqCS0En;
    Uint8   zqDualCSEn;
    Uint8   zqSFEXITEn;
    Uint8   zqZQCLInterval;
    Uint8   zqZQCLMult;
    Uint16  zqRefInterval;
}EMIFB_OUTPUT_IMP_CONFIG;

/** @brief Temperature Alert Configuration
 *
 * This structure is used to define the Temperature Alert Configuration.
 */
typedef struct EMIFB_TEMP_ALERT_CONFIG
{
    Uint8   taCS1En;
    Uint8   taCS0En;
    Uint8   taSFEXITEn;
    Uint8   taDevWdth;
    Uint8   taDevCnt;
    Uint32  taRefInterval;
}EMIFB_TEMP_ALERT_CONFIG;

/** @brief Priority to COS Mapping
 *
 * This structure is used to define the Priority to COS Mapping.
 */
typedef struct EMIFB_PRI_COS_MAPPING
{
    Uint8   enable;
    Uint8   pri7cos;
    Uint8   pri6cos;
    Uint8   pri5cos;
    Uint8   pri4cos;
    Uint8   pri3cos;
    Uint8   pri2cos;
    Uint8   pri1cos;
    Uint8   pri0cos;
}EMIFB_PRI_COS_MAPPING;

/** @brief Master ID to COS Mapping
 *
 * This structure is used to define the Master ID to COS Mapping.
 */
typedef struct EMIFB_MSTID_COS_MAPPING
{
    Uint8   enable;
    Uint8   mst1;
    Uint8   mstMask1;
    Uint8   mst2;
    Uint8   mstMask2;
    Uint8   mst3;
    Uint8   mstMask3;
}EMIFB_MSTID_COS_MAPPING;

/** @brief ECC Control
 *
 * This structure is used to define the ECC Control Configuration.
 */
typedef struct EMIFB_ECC_CONTROL
{
    Uint8   enable;
    Uint8   addrRngProt;
    Uint8   addrRng2En;
    Uint8   addrRng1En;
}EMIFB_ECC_CONTROL;

/* @} */

/** @addtogroup CSL_EMIF4F_FUNCTION
 @{ */

/* @} */


#ifdef __cplusplus
}
#endif
#endif /* CSL_EMIF4F_H_ */
