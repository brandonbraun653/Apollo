/*
 *  Copyright (C) 2019 Texas Instruments Incorporated.
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

/**
 *  \file     csl_hyperbus.h
 *
 *  \brief    This is the include file for the HyperBus CSL-FL.
 */

/** \ingroup CSL_IP_MODULE
 *  \defgroup CSL_HYPERBUS HYPERBUS CSL-FL
 *
 *  @{
 */

#ifndef CSL_HYPERBUS_H_
#define CSL_HYPERBUS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_hyperbus.h>
#include <ti/csl/csl_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \defgroup CSL_HYPERBUS_ENUM HYPREBUS Enumerated Data Types
 *  \ingroup CSL_HYPERBUS
 */
/**
 *  \addtogroup CSL_HYPERBUS_ENUM
 *  @{
 */

/**
 * \anchor CSL_ChipSelects
 * \name HYPERBUS Chip Selects
 *
 * HYPERBUS Number of Chip Selects.
 *
 * @{
 */
#define CSL_HYPERBUS_NUM_CHIP_SELECTS				(2U)
/* @} */

/**
 * \anchor CSL_ReadActive
 * \name HYPERBUS Read Active
 *
 * HYPERBUS Read Active.
 *
 * @{
 */
#define CSL_HYPERBUS_READ_INPROGRESS				(1U) 
#define CSL_HYPERBUS_READ_IDLE					(0U) 
/* @} */

/**
 * \anchor CSL_ReadDecodeError
 * \name HYPERBUS Read Decode Error
 *
 * HYPERBUS Read Decode Error.
 *
 * @{
 */
#define CSL_HYPERBUS_READADDR_DECODEERR				(1U) 
#define CSL_HYPERBUS_READADDR_NORMAL				(0U) 
/* @} */

/**
 * \anchor CSL_ReadTransactionError
 * \name HYPERBUS Read Transaction Error
 *
 * HYPERBUS Read Transaction Error.
 *
 * @{
 */
#define CSL_HYPERBUS_READTRANS_ERROR				(1U) 
#define CSL_HYPERBUS_READTRANS_NORMAL				(0U) 
/* @} */

/**
 * \anchor CSL_ReadRSTOError
 * \name HYPERBUS Read RSTO Error
 *
 * HYPERBUS Read RSTO Error.
 *
 * @{
 */
#define CSL_HYPERBUS_READDURINGRESET_ERROR			(1U) 
#define CSL_HYPERBUS_READDURINGRESET_NORMAL			(0U) 
/* @} */

/**
 * \anchor CSL_RDSStall
 * \name HYPERBUS RDS Stall
 *
 * HYPERBUS RDS Stall.
 *
 * @{
 */
#define CSL_HYPERBUS_READDATA_STALLED				(1U) 
#define CSL_HYPERBUS_READDATA_NOTSTALLED			(0U) 
/* @} */

/**
 * \anchor CSL_WriteActive
 * \name HYPERBUS Write Active
 *
 * HYPERBUS Write Active.
 *
 * @{
 */
#define CSL_HYPERBUS_WRITE_INPROGRESS				(1U)
#define CSL_HYPERBUS_WRITE_IDLE					(0U)
/* @} */

/**
 * \anchor CSL_WriteDecodeError
 * \name HYPERBUS Write Decode Error
 *
 * HYPERBUS Write Decode Error.
 *
 * @{
 */
#define CSL_HYPERBUS_WRITEADDR_DECODEERR			(1U)
#define CSL_HYPERBUS_WRITEADDR_NORMAL				(0U)
/* @} */

/**
 * \anchor CSL_WriteTransactionError
 * \name HYPERBUS Write Transaction Error
 *
 * HYPERBUS Write Transaction Error.
 *
 * @{
 */
#define CSL_HYPERBUS_WRITETRANS_ERROR				(1U)
#define CSL_HYPERBUS_WRITETRANS_NORMAL				(0U)
/* @} */

/**
 * \anchor CSL_WriteRSTOError
 * \name HYPERBUS Write RSTO Error
 *
 * HYPERBUS Write RSTO Error.
 *
 * @{
 */
#define CSL_HYPERBUS_WRITEDURINGRESET_ERROR			(1U)
#define CSL_HYPERBUS_WRITEDURINGRESET_NORMAL			(0U)
/* @} */

/**
 * \anchor CSL_IntrStatus
 * \name HYPERBUS Interrupt Status
 *
 * HYPERBUS Interrupt Status.
 *
 * @{
 */
#define CSL_HYPERBUS_INT_ENABLE					(1U)
#define CSL_HYPERBUS_INT_DISABLE				(0U)
/* @} */

/**
 * \anchor CSL_WrapSize
 * \name HYPERBUS Wrap Size
 *
 * HYPERBUS Wrap Size.
 *
 * @{
 */
#define CSL_HYPERBUS_CSWRAPSIZE_64B				(1U)
#define CSL_HYPERBUS_CSWRAPSIZE_16B				(2U)
#define CSL_HYPERBUS_CSWRAPSIZE_32B				(3U)
/* @} */

/**
 * \anchor CSL_DeviceType
 * \name HYPERBUS Device Type
 *
 * HYPERBUS Device Type.
 *
 * @{
 */
#define CSL_HYPERBUS_CSDEVTYPE_HYPERFLASH			(0U)
#define CSL_HYPERBUS_CSDEVTYPE_HYPERRAM				(1U)
/* @} */

/**
 * \anchor CSL_ConfigRegisterTarget
 * \name HYPERBUS Configuration Register Target
 *
 * HYPERBUS Configuration Register Targer.
 *
 * @{
 */
#define CSL_HYPERBUS_CSTARGET_MEM				(0U)
#define CSL_HYPERBUS_CSTARGET_CR				(1U)
/* @} */

/**
 * \anchor CSL_AsymCacheSupport
 * \name HYPERBUS Asymmetry Cache Support
 *
 * HYPERBUS Asymmetry Cache Support.
 *
 * @{
 */
#define CSL_HYPERBUS_CSASYMCACHE_DISABLE			(0U)
#define CSL_HYPERBUS_CSASYMCACHE_ENABLE				(1U)
/* @} */

/**
 * \anchor CSL_ContdMerge
 * \name HYPERBUS True Continuous Merge Option
 *
 * HYPERBUS True Continuous Merge Option.
 *
 * @{
 */
#define CSL_HYPERBUS_CSTCM_MERGE				(0U)
#define CSL_HYPERBUS_CSTCM_DONOTMERGE				(1U)
/* @} */

/**
 * \anchor CSL_Latency
 * \name HYPERBUS Latency
 *
 * HYPERBUS Latency.
 *
 * @{
 */
#define CSL_HYPERBUS_CSLATENCY_5CYCLES				(0U)
#define CSL_HYPERBUS_CSLATENCY_6CYCLES				(1U)
#define CSL_HYPERBUS_CSLATENCY_3CYCLES				(14U)
#define CSL_HYPERBUS_CSLATENCY_4CYCLES				(15U)
/* @} */

/**
 * \anchor CSL_WriteProtectionControl
 * \name HYPERBUS Write Protection Control
 *
 * HYPERBUS Write Protection Control.
 *
 * @{
 */
#define CSL_HYPERBUS_WRITEPROTECT_DISABLE			(0U)
#define CSL_HYPERBUS_WRITEPROTECT_ENABLE			(1U)
/* @} */

/**
 * \anchor CSL_LoopbackMode
 * \name HYPERBUS Set Loopback Mode
 *
 * HYPERBUS Set Loopback Mode.
 *
 * @{
 */
#define CSL_HYPERBUS_LOOPBACKMODE_DISABLE			(0U)
#define CSL_HYPERBUS_LOOPBACKMODE_ENABLE			(1U)
/* @} */
/* @} */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \defgroup CSL_HYPERBUS_DATASTRUCT  HYPERBUS Data Structures
 *  \ingroup CSL_HYPERBUS
 */
/**
 *  \addtogroup CSL_HYPERBUS_DATASTRUCT
 *  @{
 */

/*
 * \brief Structure for DLL Status
 */
typedef struct {
    /**< MDLL Code */
    uint32_t mdllCode;
    /**< MDLL Code Valid */
    uint32_t mdllCodeValid;
} CSL_HyperbusDllStatus;

/* 
 * \brief This structure sets the Maximum length for read/write transaction 
 *  and its Enable 
 */
typedef struct {
    /**< Maximum read/write transaction length to memory 
      *  0   means 2    Bytes, 1   Hyperbus CK
      *  1   means 4    Bytes, 2   Hyperbus CK
      *  2   means 6    Bytes, 3   Hyperbus CK
      *  511 means 1024 Bytes, 511 Hyperbus CK*/
    uint32_t maxLength;
    /**< Maximum length enable 
      *  0 means Disable
      *  1 means Enable */
    uint32_t maxLengthEnable;
} CSL_HyperbusCSMaxLength;

/*
 * \brief Register structure for the Memory Timing Register
 */
typedef struct
{
    /**< Initial latency for read/write access, only applicable for HyperRAM
      *  Refer \ref CSL_Latency */
    uint32_t latency;
    /**< CS# hold time for write to CS# deassertion 
      *  Range 0 to 15
      *  0  means 1  Cycle
      *  15 means 16 Cycles */
    uint32_t writeCSHold;
    /**< CS# hold time for read to CS# deassertion 
      *  Range 0 to 15
      *  0  means 1  Cycle
      *  15 means 16 Cycles */
    uint32_t readCSHold;
    /**< CS# setup time for write from CS# assertion 
      *  Range 0 to 15
      *  0  means 1  Cycle
      *  15 means 16 Cycles */
    uint32_t writeCSSetup;
    /**< CS# setup time for read from CS# assertion
      *  Range 0 to 15
      *  0  means 1  Cycle
      *  15 means 16 Cycles */
    uint32_t readCSSetup;
    /**< CS# high time for write between operations 
      *  Range 0 to 15
      *  0  means 15  Cycle
      *  15 means 165 Cycles*/
    uint32_t writeCSHigh;
    /**< CS# high time for read between operations 
      *  Range 0 to 15
      *  0  means 15  Cycle
      *  15 means 165 Cycles*/
    uint32_t readCSHigh;
}CSL_HyperbusMemTimingReg;

/*
 * \brief Register structure for the Memory Configuration Register
 */
typedef struct
{
    /**< Wrap burst length of HyperBus memory 
      *  Refer \ref CSL_WrapSize */
    uint32_t wrapSize;
    /**< Device connected to HyperBus - 0 for HyperFlash, 1 for HyperRAM 
      *  Refer \ref CSL_DeviceType */
    uint32_t deviceType;
    /**< Whether read or write operation accesses the memory or CR space 
      *  Refer \ref CSL_ConfigRegisterTarget */
    uint32_t configRegTarget;
    /**< Refer \ref CSL_AsymCacheSupport */
    uint32_t asymCacheSupport;
    /**< True continuous merge option
      *  Refer \ref CSL_ContdMerge */
    uint32_t contdMerge;
}CSL_HyperbusMemConfigReg;

/*
 * \brief Register structure for the Control Status Register
 */
typedef struct
{
    /**< Read transaction in progress or not
      *  Refer \ref CSL_ReadActive */
    uint32_t readActive;
    /**< Access address in acceptable or not in latest read transaction 
      *  Refer \ref CSL_ReadDecodeError */
    uint32_t readDecodeError;
    /**< AXI protocol is acceptable by HBMC IP or not in latest read transaction
      *  Refer \ref CSL_ReadTransactionError */
    uint32_t readTransactionError;
    /**< HyperBus memory under reset or not in latest read transaction 
      *  Refer \ref CSL_ReadRSTOError*/
    uint32_t readRSTOError;
    /**< Read data transfer from HyperBus memory is stalled or not
      *  Refer \ref CSL_RDSStall */
    uint32_t rdsStall;
    /**< Write transaction in progress or not
      *  Refer \ref CSL_WriteActive */
    uint32_t writeActive;
    /**< Access address acceptable or not in latest write transaction
      *  Refer \ref CSL_WriteDecodeError */
    uint32_t writeDecodeError;
    /**< AXI protocol is acceptable by HBMC IP or not in latest write transaction
      *  Refer \ref CSL_WriteTransactionError */
    uint32_t writeTransactionError;
    /**< HyperBus memory under reset or not in latest write transaction
      *  Refer \ref CSL_WriteRSTOError */
    uint32_t writeRSTOError;
}CSL_HyperbusCtrlStatusReg;

/* @} */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \defgroup CSL_HYPERBUS_FUNCTION  HYPERBUS Functions
 *  \ingroup CSL_HYPERBUS
 */
/**
 *  \addtogroup CSL_HYPERBUS_FUNCTION
 *  @{
 */

/*
 * \brief HyperBus Read Revision
 *
 * \param pSyscfgRegs 		[IN]  Pointer to IP Register Overlay 
 *
 * \return value of REVISION_REG register if arguments are valid, else return -1.
 */
uint32_t CSL_hyperbusGetRevision( const CSL_hyperbus_syscfgRegs *pSyscfgRegs );

/*
 * \brief Get the DLL status
 * \param pSyscfgRegs		[IN] Pointer to IP Register Overlay
 * \param pDllStatus		[OUT] Pointer to user suppied structure for 
 *                                    CSL_HyperbusDllStatus
 *
 * \return CSL_PASS if successful
 */
int32_t CSL_hyperbusGetDllCode( const CSL_hyperbus_syscfgRegs *pSyscfgRegs,
                                CSL_HyperbusDllStatus *pDllStatus );

/*
 * \brief Get the Control Status Register
 *
 * \param pCoreRegs 		[IN] Pointer to IP Register Overlay
 * \param pCtrlStatusReg 	[OUT] Pointer to the structure for
                                      \ref CSL_HyperbusCtrlStatusReg
 *
 * \return CSL_PASS if successful 
 */
int32_t CSL_hyperbusGetCtrlStatusReg( const CSL_hyperbus_coreRegs *pCoreRegs,
                                CSL_HyperbusCtrlStatusReg *pCtrlStatusReg );

/*
 * \brief API to enable the Interrupt
 *
 * \param pCoreRegs 		[IN] Pointer to IP Register Overlay
 *
 * \return CSL_PASS if successful 
 */
int32_t CSL_hyperbusEnableIntr( CSL_hyperbus_coreRegs *pCoreRegs );

/*
 * \brief API to disable the Interrupt
 *
 * \param pCoreRegs 		[IN] Pointer to IP Register Overlay
 *
 * \return CSL_PASS if successful 
 */
int32_t CSL_hyperbusDisableIntr( CSL_hyperbus_coreRegs *pCoreRegs );

/*
 * \brief API to check if interrupt is pending
 *
 * \param pCoreRegs 		[IN] Pointer to IP Register Overlay
 *
 * \return TRUE if interrupt pending else return FALSE
 */
uint32_t CSL_hyperbusIsIntrPending( const CSL_hyperbus_coreRegs *pCoreRegs );

/**
 * \brief Set the MSB 8bits of the base address of addressable region
 * to the HyperBus memory 
 *
 * \param pCoreRegs 		[IN] Pointer to IP Register Overlay 
 * \param mbarIndex 		[IN] MBAR index
 * \param hyperbusCSBaseAddr 	[IN] Base address to be set
 *
 * \return CSL_PASS if successful and CSL_EFAIL otherwise
 */
int32_t CSL_hyperbusSetCSBaseAddr( CSL_hyperbus_coreRegs *pCoreRegs,
                                   uint32_t mbarIndex,
                                   uint32_t hyperbusCSBaseAddr );

/*
 * \brief Set the Memory Configuration Register for device type and wrap size based 
 *  on the user defined structure
 *
 * \param pCoreRegs 		[IN] Pointer to the IP Register Overlay
 * \param mcrIndex 		[IN] Memory Configuration Register Index
 * \param pMemConfigReg 	[IN] Pointer to \ref CSL_HyperbusMemConfigReg
 *
 * \return CSL_PASS if successful and CSL_EFAIL otherwise
 */
int32_t CSL_hyperbusSetMemConfig( CSL_hyperbus_coreRegs *pCoreRegs,
                                  uint32_t mcrIndex,
                                  const CSL_HyperbusMemConfigReg *pMemConfigReg );

/*
 * \brief Set the devide type - HyperFlash (0) or HyperRAM (1)
 *
 * \param pCoreRegs 		[IN] Pointer to the IP Register Overlay
 * \param mcrIndex 		[IN] Memory Configuration Register Index
 * \param deviceType 		[IN] \ref CSL_DeviceType
 *
 * \return CSL_PASS if successful and CSL_EFAIL otherwise
 */
int32_t CSL_hyperbusSetDeviceType( CSL_hyperbus_coreRegs *pCoreRegs,
                                   uint32_t mcrIndex,
                                   uint32_t deviceType );

/*
 * \brief Set the maximum read/write transaction length to memory.
 *
 * \param pCoreRegs 		[IN] Pointer to the IP Register Overlay
 * \param mcrIndex 		[IN] Memory Configuration Register Index
 * \param pMaxLen		[IN] Pointer to structure for CSL_HyperbusCSMaxLength
 *                                   mmaxLengthEnable should be 1 for this to
 *                                   take effect
 *
 * \return CSL_PASS if successful and CSL_EFAIL otherwise
 */
int32_t CSL_hyperbusSetMaxLen( CSL_hyperbus_coreRegs *pCoreRegs,
                               uint32_t mcrIndex,
                               const CSL_HyperbusCSMaxLength *pMaxLen );

/*
 * \brief Get the Memory Configuration Register
 *
 * \param pCoreRegs 		[IN] Pointer to the IP Register Overlay
 * \param mcrIndex 		[IN] Memory Configuration Register Index
 * \param pMemConfigReg 	[OUT] Pointer to \ref CSL_HyperbusMemConfigReg
 *
 * \return CSL_PASS if successful and CSL_EFAIL otherwise
 */
int32_t CSL_hyperbusGetMemConfig( const CSL_hyperbus_coreRegs *pCoreRegs,
                                  uint32_t mcrIndex,
                                  CSL_HyperbusMemConfigReg *pMemConfigReg );

/*
 * \brief Set the Memory Timings
 *
 * \param pCoreRegs 		[IN] Pointer to the IP Register Overlay
 * \param mtrIndex 		[IN] Memory Timing Register Index
 * \param pMemTimingReg 	[IN] Pointer to \ref CSL_HyperbusMemConfigReg 
 *
 * \return CSL_PASS if successful and CSL_EFAIL otherwise
 */
int32_t CSL_hyperbusSetMemTiming( CSL_hyperbus_coreRegs *pCoreRegs,
                          uint32_t mtrIndex,
                          const CSL_HyperbusMemTimingReg *pMemTimingReg );

/*
 * \brief Get the Memory Timings
 *
 * \param pCoreRegs 		[IN] Pointer to the IP Register Overlay
 * \param mtrIndex 		[IN] Memory Timing Register Index
 * \param pMemTimingReg 	[OUT] Pointer to \ref CSL_HyperbusMemTimingReg
 *
 * \return CSL_PASS if successful and CSL_EFAIL otherwise
 */
int32_t CSL_hyperbusGetMemTiming( const CSL_hyperbus_coreRegs *pCoreRegs,
                                  uint32_t mtrIndex,
                                  CSL_HyperbusMemTimingReg *pMemTimingReg );

/**
 * \brief Set the value of WriteProtect
 *
 * This function set the value of the WP field of the WPR register
 *
 * \param pCoreRegs 		[IN] Pointer to IP Register Overlay
 * \param writeProtect 		[IN] Value of the write protection field to be
 *                                   written, Refer \ref CSL_WriteProtectionControl
 *
\return CSL_PASS if successful, CSL_EFAIL otherwise.
 */
int32_t CSL_hyperbusSetWriteProtection( CSL_hyperbus_coreRegs *pCoreRegs,
                                        uint32_t writeProtect );

/*
 * \brief Set the value of LoopBackMode
 *
 * This function set the value of the LOOPBACK field of the LBR registe
 *
 * \param pCoreRegs 		[IN] Pointer to IP Register Overlay
 * \param loopBackMode 		[IN] Value to set for the loop back mode
 *                                   Refer \ref CSL_LoopbackMode
 *
 * \return CSL_PASS if successful, CSL_EFAIL otherwise.
 */
int32_t CSL_hyperbusSetLoopBackMode( CSL_hyperbus_coreRegs *pCoreRegs,
                                     uint32_t loopBackMode );
/** @}*/


#ifdef __cplusplus
}
#endif

#endif  /* CSL_HYPERBUS_H_ */
/** @}*/
