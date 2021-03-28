/**
 *   @file  csl_emif4.h
 *
 *   @brief   
 *      This is the main header file for the EMIF4F Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2019, Texas Instruments, Inc.
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

#ifndef CSL_EMIF4F_V1_H
#define CSL_EMIF4F_V1_H

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
@defgroup CSL_EMIF4F_ENUM  EMIF4F ENUM
@ingroup CSL_EMIF4F_API
*/

/**
@addtogroup CSL_EMIF4F_SYMBOL
@{
*/
#ifndef CSL_DDR3_0_SLV_CFG_REGS
/* Handling case of device.h mismatch in defines */
#ifdef CSL_DDR_0_CFG_REGS
#define CSL_DDR3_0_SLV_CFG_REGS CSL_DDR_0_CFG_REGS
#endif
#endif

/** \brief Number of ECC Protected Adrress range in EMIF Module */
#define EMIF_ECC_PROTECTED_NUM_ADDR_RANGE     (0x2)

/** \brief Internal FIFO Buffer with depth of 4 which can store corrected error
 *         address or non correctable error address
 *         This fifo can store only first 4 error address.To store the 5th
 *         error address. Writing 0x1 will pop one element of the FIFO to error
 *         address register ,clearing 0th address in FIFO & then we can store
 *         next new error addresss in FIFO else will miss the error address log
 *         i.e., Overflow occurs when the num ECC Err is more than
 *         EMIF_ECC_FIFO_BUF_SIZE
 */
#define EMIF_ECC_FIFO_BUF_SIZE                (0x4U)

/** \brief Macro to Enable EMIF ECC */
#define EMIF_ECC_ENABLE                 (0x1U)
/** \brief Macro to DISABLE EMIF ECC */
#define EMIF_ECC_DISABLE                (0x0U)
/** \brief Macro to Clear EMIF End of Interrupt */
#define EMIF_EOI_CLEAR                  (0x1U)

/**
 *  Handle to access EMIF4F registers accessible through config bus.
 */
#define hEmif     ((CSL_Emif4fvRegs*)CSL_DDR3_0_SLV_CFG_REGS)

/**
 * \brief  Macro defines mask for all the interrupts to disable for EMIF.
 */
#define EMIF_INTR_STATUS_ALL    (                                 \
        CSL_EMIF4FV_IRQSTATUS_SYS_REG_ERR_SYS_MASK |              \
        CSL_EMIF4FV_IRQSTATUS_SYS_REG_WR_ECC_ERR_SYS_MASK |       \
        CSL_EMIF4FV_IRQSTATUS_SYS_REG_2B_ECC_ERR_SYS_MASK |       \
        CSL_EMIF4FV_IRQSTATUS_SYS_REG_1B_ECC_ERR_SYS_MASK )

/**
 * \brief  Macro defines mask for all the interrupts for EMIF.
 */
#define EMIF_INTR_ALL             (EMIF_INTR_STATUS_ALL)

/**
@}
*/

/**
@addtogroup CSL_EMIF4F_ENUM
@{
*/

/**
 *  \brief    Enumerates the values used to represent ECC EMIF protected address
 *            ranges
 */
typedef enum emifEccAddrRangeNum
{
    EMIF_ECC_ADDR_RANGE_NUM_1 = 1,
    /**< First ECC EMIF protected address range */
    EMIF_ECC_ADDR_RANGE_NUM_2
    /**< Second ECC EMIF protected address range */
} emifEccAddrRangeNum_t;

/**
 *  \brief    Enumerates the values used to represent ECC EMIF ECC protected
 *            address ranges within/outside defined address range
 */
typedef enum emifEccAddrRangeType
{
    EMIF_ECC_ADDR_RANGE_OUTSIDE,
    /**<  ECC protected address range outside defined address range of EMIF*/
    EMIF_ECC_ADDR_RANGE_WITHIN
    /**<  ECC protected address range within defined address range of EMIF*/
} emifEccAddrRangeType_t;

/**
 *  \brief    Enumerates the values used to represent different types of ECC
 *            Errors in EMIF Module
 */
typedef enum emifEccErrType
{
    EMIF_ERR_ECC_ONEBIT = 0x1U,
    /**< EMIF 1 bit ECC Error */
    EMIF_ERR_ECC_TWOBIT = 0x2U,
    /**< EMIF 2 bit ECC Error */
    EMIF_ERR_ECC_NONQUANTA = 0x3U
                             /**< EMIF ECC Error for When a non-quanta
                              *memory/data access */
} emifEccErrType_t;

/**
@}
*/

/** @addtogroup CSL_EMIF4F_DATASTRUCT
 @{ */

/** @brief This is the handle to the MPU Register */
typedef volatile CSL_Emif4fvRegs*   CSL_Emif4fHandle;



/** \brief Structure holding error information of EMIF
 */
typedef struct emifEccErrInfo
{
    uint32_t errBitLoc;
    /**<  Error Bit location of EMIF when 1 Bit Error occurs
     *    Valid only for 1 bit Error
     */
    uint32_t errCnt;
    /**<  As per hardware, it represent Error count for 1 Bit Errors. ErrCnt
     *    could be more than ECC_EMIF_FIFO_BUF_SIZE in case of overflow. And
     *    user can check overflow if this count is greater that numValidErrAddr
     */
    uint32_t numValidErrAddr;
    /**<  Number of Valid ECC Error Address */
    uint32_t errAddr[EMIF_ECC_FIFO_BUF_SIZE];
    /**<  Address offset of EMIF when 1 bit or 2 bit or non-quanta ECC error
     *    Occurs.
     */
} emifEccErrInfo_t;

/** \brief Structure holding ECC Protected Address range configuration
 *          parameters of EMIF
 */
typedef struct emifEccAddrRangeCfgPrm
{
    uint32_t startAddr;
    /**<  Start Adddress for ECC Protected Address which is of 16bit aligned
     *    such as 0x90000000 but not the MSB offset address as EMIF module
     *    expected for ECC protected address such as 0x1000 i.e.,
     *    ((0x90000000 >> 16) - (0x80000000 >> 16)) where 0x80000000 is
     *     EMIF Start address which is done in code
     */
    uint32_t endAddr;
    /**<  End Adddress for ECC Protected Address which is of 16bit aligned
     *    such as 0x9FFFFFFF but not the MSB offset address as EMIF module
     *    expected for ECC protected address such as 0x1FFF i.e.,
     *    ((0x9FFFFFFF >> 16) - (0x80000000 >> 16)) where 0x80000000 is
     *     EMIF Start address which is done in code
     */
    uint32_t addrRangeNum;
    /**<  ECC protected address range number. For valid values refer
     *    enum #emifEccAddrRangeNum_t
     */
    uint32_t addrRangeType;
    /**<  ECC Address range Type . For valid values refer
     *    enum eccEmifAddrRangeType_t
     */
    uint32_t enableAddrRange;
    /**<  Enable/Disable ECC for the defined address range */
} emifEccAddrRangeCfgPrm_t;

/** \brief Structure holding ECC configuration parameters of EMIF
 */
typedef struct emifEccCfgPrm
{
    uint32_t                  emifStartAddr;
    /**<  Start address of EMIF module*/
    emifEccAddrRangeCfgPrm_t *addrRangeCfgPrm;
    /**<  Configuration parameters for ECC Protected Address range
     */
    uint32_t                  thresholdVal;
    /**<  Threshold value to generate 1 bit error*/
    uint32_t                  enableRmw;
    /**<  Enable/Disable RMW for sub quanta access.
     *    Set enableRmw to 1 to enable and 0 to disable.
     *    Applicable only for TDA2Px.
     */
} emifEccCfgPrm_t;

/** @brief EMIF4F SDRAM Configuration
 *
 * This structure is used to define the EMIF4F SDRAM 
 * Configuration
 */
typedef struct EMIF4F_SDRAM_CONFIG_s
{
    Uint8   type;
    Uint8   ddrTerm;
    Uint8   ddrDDQS;
    Uint8   dynODT;
    Uint8   CASWriteLat;
    Uint8   narrowMode;
    Uint8   CASLatency;
    Uint8   iBank;
    Uint8   eBank;
    Uint8   pageSize;

    Uint8   NVMEnable;
    Uint8   eBankPos;
    Uint8   rdbNum;
    Uint8   rdbSize;
}EMIF4F_SDRAM_CONFIG;

/** @brief EMIF4F Timing1 Configuration
 *
 * This structure is used to define the EMIF4F Timing1
 * Configuration
 */
typedef struct EMIF4F_TIMING1_CONFIG_s
{
    Uint8   t_wr;
    Uint8   t_ras;
    Uint8   t_rc;
    Uint8   t_rrd;
    Uint8   t_wtr;
}EMIF4F_TIMING1_CONFIG;

/** @brief Power Management Configuration
 *
 * This structure is used to define the Power Management Configuration
 */
typedef struct EMIF4F_PWR_MGMT_CONFIG_s
{
    Uint8   pdTime;
    Uint8   dpdEnable;
    Uint8   lpMode;
    Uint8   srTime;
    Uint8   csTime;
}EMIF4F_PWR_MGMT_CONFIG;

/** @brief VBUS Configuration Values
 *
 * This structure is used to define the VBUS Configuration Values
 */
typedef struct EMIF4F_VBUS_CONFIG_VALUE_s
{
    Uint8   sysBusWidth;
    Uint8   statFIFODepth;
    Uint8   wrFIFODepth;
    Uint8   cmdFIFODepth;
    Uint8   rregFIFODepth;
    Uint8   rsdFIFODepth;
    Uint8   rcmdFIFODepth;
}EMIF4F_VBUS_CONFIG_VALUE;

/** @brief IODFT Control Values
 *
 * This structure is used to define the IODFT Test Logic Global
 * Control Values.
 */
typedef struct EMIF4F_IODFT_CONTROL_s
{
    Uint16  tlec;
    Uint8   mt;
    Uint8   actCapEn;
    Uint8   opgld;
    Uint8   mms;
    Uint8   mc;
    Uint8   pc;
}EMIF4F_IODFT_CONTROL;

/** @brief Performance Counter Configuration
 *
 * This structure is used to define the performance counter 
 * configuration
 */
typedef struct EMIF4F_PERF_CONFIG_s
{
    Uint8  mstIDEn;
    Uint8  regEn;
    Uint8  cntCfg;
}EMIF4F_PERF_CONFIG;

/** @brief SDRAM Output Impedance Calibration Configuation
 *
 * This structure is used to define the SDRAM Output Impedance 
 * Calibration Configuration.
 */
typedef struct EMIF4F_OUTPUT_IMP_CONFIG_s
{
    Uint8   zqCS1En;
    Uint8   zqCS0En;
    Uint8   zqDualCSEn;
    Uint8   zqSFEXITEn;
    Uint8   zqZQCLMult;
    Uint16  zqRefInterval;
}EMIF4F_OUTPUT_IMP_CONFIG;

/** @brief Priority to COS Mapping
 *
 * This structure is used to define the Priority to COS Mapping.
 */
typedef struct EMIF4_PRI_COS_MAPPING_s
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
}EMIF4_PRI_COS_MAPPING;

/** @brief Master ID to COS Mapping
 *
 * This structure is used to define the Master ID to COS Mapping.
 */
typedef struct EMIF4_MSTID_COS_MAPPING_s
{
    Uint8   enable;
    Uint8   mst1;
    Uint8   mstMask1;
    Uint8   mst2;
    Uint8   mstMask2;
    Uint8   mst3;
    Uint8   mstMask3;
}EMIF4_MSTID_COS_MAPPING;

/** @brief ECC Control 
 *
 * This structure is used to define the ECC Control Configuration.
 */
typedef struct EMIF4_ECC_CONTROL_s
{
    Uint8   enable;
    Uint8   addrRngProt;
    Uint8   rmwEn;
    Uint8   eccVerifyEn;
    Uint8   addrRng2En;
    Uint8   addrRng1En;
}EMIF4_ECC_CONTROL;

/* @} */

/** @addtogroup CSL_EMIF4F_FUNCTION
 @{ */

 /* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function will intialize the ECC Protected Address range
 *          parameters and threshold for 1Bit Error of EMIF Module
 *
 * \param   baseAddr          Base address of EMIF module register
 *
 * \param   pCfgPrm           Pointer which holds ECC configuration parameters
 *                            of EMIF Module
 *
 * \return  STW_SOK on success else STW_EFAIL
 */
int32_t EMIFConfigECCInitECCParams(uint32_t               baseAddr,
                                   const emifEccCfgPrm_t *pCfgPrm);

/**
 * \brief   This function will enable ECC of EMIF Module
 *
 * \param   baseAddr            Base address of EMIF module register
 *
 * \return  None
 */
void EMIFConfigECCEnableEcc(uint32_t baseAddr);

/**
 * \brief   This function will disable ECC of EMIF Module
 *
 * \param   baseAddr            Base address of EMIF module register
 *
 * \return  None
 */
void EMIFConfigECCDisableEcc(uint32_t baseAddr);

/**
 * \brief   This API is used to enable interrupts.
 *
 * \param   baseAddr        Base Address of the EMIF module Registers.
 * \param   intrMask        Interrupts to enable.
 *                          Refer enum #emifIntrSrc_t.
 *
 * \return  None.
 */
void EMIFEnableIntr(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This API is used to disable interrupts.
 *
 * \param   baseAddr        Base Address of the EMIF module Registers.
 * \param   intrMask        Interrupts to disable.
 *                          Refer enum #emifIntrSrc_t.
 *
 * \return  None.
 */
void EMIFDisableIntr(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This API is used to get the pending interrupts.
 *
 * \param   baseAddr        Base Address of the EMIF module Registers.
 *
 * \return  status          Pending interrupt status/occurred.
 */
uint32_t EMIFGetIntrStatus(uint32_t baseAddr);

/**
 * \brief   This API is used to clear the interrupt status.
 *
 * \param   baseAddr        Base Address of the EMIF module Registers.
 * \param   intrMask        Interrupts to clear status.
 *                          Refer enum #emifIntrSrc_t.
 *
 * \return  None.
 */
void EMIFClearIntrStatus(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This API is used to get the raw interrupt status.
 *
 * \param   baseAddr        Base Address of the EMIF module Registers.
 *
 * \return  status          Pending interrupt status/occurred.
 */
uint32_t EMIFGetIntrRawStatus(uint32_t baseAddr);

/**
 * \brief   This API is used to clear the end of interrupt status.
 *
 * \param   baseAddr        Base Address of the EMIF module Registers.
 *
 * \return  None.
 */
void EMIFWriteEOI(uint32_t baseAddr);

/**
 * \brief   This function will return the EMIF ECC error information of the
 *          defined EMIF ECC Error
 *
 * \param   baseAddr      Base address of EMIF module register
 *
 * \param   errType       Value used to represent EMIF ECC Error
 *                        For valid values refer enum #emifEccErrType_t
 *
 * \param   pErrInfo      Pointer which hold Error information of the defined
 *                        EMIF ECC Error
 *                        For valid values refer enum #emifEccErrInfo_t
 *
 * \return  STW_SOK on success else STW_EFAIL
 */
int32_t EMIFConfigECCGetEccErrInfo(uint32_t          baseAddr,
                                   uint32_t          errType,
                                   emifEccErrInfo_t *pErrInfo);

/**
 * \brief   This function will clear all EMIF ECC error information
 *
 * \param   baseAddr       Base address of EMIF module register
 *
 * \return  None
 */
void EMIFConfigECCClrAllEccErrInfo(uint32_t baseAddr);

/* @} */


#ifdef __cplusplus
}
#endif
#endif /* CSL_EMIF4F_V1_H */
