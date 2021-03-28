/**
 * \file     elm.h
 *
 * \brief    This file contains the prototypes of device abstraction layer APIs
 *           corresponding to the ELM. This also contains necessary structure,
 *           enum and macro definitions.
 *
 * \details  The GPMC probes data read from an external NAND flash and uses this
 *           to compute checksum-like information, called syndrome polynomials,
 *           on a per-block basis. Each syndrome polynomial gives a status of
 *           the read operations for a full block, including 512 bytes of data,
 *           parity bits, and an optional spare-area data field, with a maximum
 *           block size of 1023 bytes. Computation is based on BCH algorithm.
 *           The error-location module (ELM) extracts error addresses from these
 *           syndrome polynomials.
 *
 *           Programming sequence of ELM is as follows:
 *           -# Enable Module Clocks for ELM through PRCMModuleEnable API
 *           -# Configure the Pinmux for the ELM required through
 *              PINMUXModuleConfig API
 *           -# Perform a module reset of the ELM through the API
 *              #ELMModuleReset
 *           -# Configure the Idle mode for the module through the API
 *              #ELMSetIdleMode
 *           -# Define the Error Correction level to be used through the API
 *              #ELMSetBchEccLevel
 *           -# Define the maximum buffer length through the API
 *              #ELMSetEccBufSize
 *           -# Set the ELM in continuous or Page mode as required through the
 *              following APIs #ELMSetContinuousMode and #ELMSetPageMode
 *           -# In continuous mode
 *              -# Enable interrupts for the particular syndrome polynomial
 *                 through the API #ELMIntrEnable
 *              -# Set the input polynomial to be processed
 *                 through the API #ELMSetSyndromeFragment
 *              -# Initiate the Error location processing through the API
 *                 #ELMErrLocProcessingStart
 *           -# In Page mode
 *              -# Disable all interrupts syndrome polynomial through
 *                 #ELMIntrDisable and enable the Page Mask interrupt through
 *                 the API #ELMIntrEnable
 *              -# Set the input polynomial to be processed
 *                 through the API #ELMSetSyndromeFragment
 *              -# Initiate the Error location processing through the API
 *                 #ELMErrLocProcessingStart
 *           -# Reading the Results
 *              -# Wait until the process is complete for the syndrome
 *                 polynomial either through interrupt or polling the status
 *                 register through the API #ELMIntrStatus
 *              -# Read the number of errors through #ELMGetNumErrors API
 *              -# Read the error location bit addresses for syndrome polynomial
 *                 through the API #ELMGetErrAddress
 *              -# Take suitable corrective action based on the number of errors
 *                 reported, which is based on the ECC algorithm used.
 */

 /**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#ifndef ELM_H_
#define ELM_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "misc.h"
#include "hw_elm.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define ELMRevisionGet                  ELMGetRevision
#define ELMModuleResetStatusGet         ELMModuleIsResetDone
#define ELMErrCorrectionLevelSet        ELMSetBchEccLevel
#define ELMECCSizeSet                   ELMSetEccBufSize
#define ELMSyndromeFrgmtSet             ELMSetSyndromeFragment
#define ELMErrLocProcessingStatusGet    ELMErrLocProcessStatus
#define ELMNumOfErrsGet                 ELMGetNumErrors
#define ELMErrLocBitAddrGet             ELMGetErrAddress
#define ELMIntStatusGet                 ELMIntrStatus
#define ELMIntStatusClear               ELMIntrClear
#define ELMCAutoGatingConfig            ELMAutoGatingEnable
#define ELMCIdleModeSelect              ELMSetIdleMode
#define ELMOCPClkActivityConfig         ELMSetIdleModeOcpClkActivity

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the different ECC levels for the BCH algorithm. */
typedef enum elmBchEccLevel
{
    ELM_BCH_ECC_LEVEL_4_BITS = ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_FOUR_BITS,
    /**< Error correction through BCH algorithm for 4 bits. */
    ELM_BCH_ECC_LEVEL_8_BITS = ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_EIGHT_BITS,
    /**< Error correction through BCH algorithm for 8 bits. */
    ELM_BCH_ECC_LEVEL_16_BITS = ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_SIXTEEN_BITS,
    /**< Error correction through BCH algorithm for 16 bits. */
}elmBchEccLevel_t;

/** \brief Enumerates the different sector number mask values to assign a
           syndrome polynomial as part of the particular page. */
typedef enum elmSectorMaskNum
{
    ELM_SECTOR_MASK_NUM_0 = ELM_PAGE_CTRL_SECTOR_0_MASK,
    /**< Mask value for setting Syndrome polynomial 0 as part of the Page. */
    ELM_SECTOR_MASK_NUM_1 = ELM_PAGE_CTRL_SECTOR_1_MASK,
    /**< Mask value for setting Syndrome polynomial 1 as part of the Page. */
    ELM_SECTOR_MASK_NUM_2 = ELM_PAGE_CTRL_SECTOR_2_MASK,
    /**< Mask value for setting Syndrome polynomial 2 as part of the Page. */
    ELM_SECTOR_MASK_NUM_3 = ELM_PAGE_CTRL_SECTOR_3_MASK,
    /**< Mask value for setting Syndrome polynomial 3 as part of the Page. */
    ELM_SECTOR_MASK_NUM_4 = ELM_PAGE_CTRL_SECTOR_4_MASK,
    /**< Mask value for setting Syndrome polynomial 4 as part of the Page. */
    ELM_SECTOR_MASK_NUM_5 = ELM_PAGE_CTRL_SECTOR_5_MASK,
    /**< Mask value for setting Syndrome polynomial 5 as part of the Page. */
    ELM_SECTOR_MASK_NUM_6 = ELM_PAGE_CTRL_SECTOR_6_MASK,
    /**< Mask value for setting Syndrome polynomial 6 as part of the Page. */
    ELM_SECTOR_MASK_NUM_7 = ELM_PAGE_CTRL_SECTOR_7_MASK,
    /**< Mask value for setting Syndrome polynomial 7 as part of the Page. */
    ELM_SECTOR_MASK_NUM_ALL = (ELM_PAGE_CTRL_SECTOR_0_MASK |
                               ELM_PAGE_CTRL_SECTOR_1_MASK |
                               ELM_PAGE_CTRL_SECTOR_2_MASK |
                               ELM_PAGE_CTRL_SECTOR_3_MASK |
                               ELM_PAGE_CTRL_SECTOR_4_MASK |
                               ELM_PAGE_CTRL_SECTOR_5_MASK |
                               ELM_PAGE_CTRL_SECTOR_6_MASK |
                               ELM_PAGE_CTRL_SECTOR_7_MASK)
    /**< Mask value to set all the syndrome polynomial as part of the page. */
}elmSectorMaskNum_t;

/** \brief     Enumerates the Error location process exit status.
 *
 *  \details   The same macros will be used to determine the status of all
 *             syndrome polynomials.
 */
typedef enum elmErrLocProcessSts
{
    ELM_ERR_LOC_PROCESS_STS_PASS = ELM_LOCATION_STS_ECC_CORRECTABL_SUCCESS,
    /**< Value indicating all errors were successfully located. Number of
         errors and error locations are valid. */
    ELM_ERR_LOC_PROCESS_STS_FAIL = ELM_LOCATION_STS_ECC_CORRECTABL_FAIL
    /**< Value indicating the Error location process failed. Number of
         errors and error locations are invalid. */
}elmErrLocProcessSts_t;

/** \brief Enumerates the different ELM interrupts. */
typedef enum elmIntrMask
{
    ELM_INTR_MASK_SYNDR_POLY_0 = ELM_IRQEN_LOCATION_MASK_0_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 0. */
    ELM_INTR_MASK_SYNDR_POLY_1 = ELM_IRQEN_LOCATION_MASK_1_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 1. */
    ELM_INTR_MASK_SYNDR_POLY_2 = ELM_IRQEN_LOCATION_MASK_2_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 2. */
    ELM_INTR_MASK_SYNDR_POLY_3 = ELM_IRQEN_LOCATION_MASK_3_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 3. */
    ELM_INTR_MASK_SYNDR_POLY_4= ELM_IRQEN_LOCATION_MASK_4_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 4. */
    ELM_INTR_MASK_SYNDR_POLY_5= ELM_IRQEN_LOCATION_MASK_5_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 5. */
    ELM_INTR_MASK_SYNDR_POLY_6 = ELM_IRQEN_LOCATION_MASK_6_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 6. */
    ELM_INTR_MASK_SYNDR_POLY_7 = ELM_IRQEN_LOCATION_MASK_7_MASK,
    /**< Error location interrupt mask for Syndrome Polynomial 7. */
    ELM_INTR_MASK_PAGE = ELM_IRQEN_PAGE_MASK_MASK,
    /** Error location interrupt mask for a full page. */
    ELM_INTR_MASK_ALL = (ELM_IRQEN_LOCATION_MASK_0_MASK |
                         ELM_IRQEN_LOCATION_MASK_1_MASK |
                         ELM_IRQEN_LOCATION_MASK_2_MASK |
                         ELM_IRQEN_LOCATION_MASK_3_MASK |
                         ELM_IRQEN_LOCATION_MASK_4_MASK |
                         ELM_IRQEN_LOCATION_MASK_5_MASK |
                         ELM_IRQEN_LOCATION_MASK_6_MASK |
                         ELM_IRQEN_LOCATION_MASK_7_MASK |
                         ELM_IRQEN_PAGE_MASK_MASK)
    /**< Interrupt mask to enable/disable all the ELM interrupts. */
}elmIntrMask_t;

/** \brief Enumerates the different Idle modes of ELM. */
typedef enum elmIdleMode
{
    ELM_IDLE_MODE_FORCE_IDLE = ELM_SYSCONFIG_SIDLEMODE_FORCE_IDLE,
    /**< Force Idle Mode. */
    ELM_IDLE_MODE_NO_IDLE = ELM_SYSCONFIG_SIDLEMODE_NO_IDLE,
    /**< No Idle Mode. */
    ELM_IDLE_MODE_SMART_IDLE = ELM_SYSCONFIG_SIDLEMODE_SMART_IDLE,
    /**< Smart Idle Mode. */
}elmIdleMode_t;

/** \brief Enumerates the OCP Clock Activity behaviour in IDLE mode of ELM. */
typedef enum elmOcpClkActivity
{
    ELM_OCP_CLK_ACTIVITY_OFF = ELM_SYSCONFIG_CLOCKACTIVITYOCPZ_OCP_OFF,
    /**< OCP Clock Activity can be switched off in Idle mode. */
    ELM_OCP_CLK_ACTIVITY_ON = ELM_SYSCONFIG_CLOCKACTIVITYOCPZ_OCP_ON
    /**< OCP Clock Activity is maintained during wake up period. */
}elmOcpClkActivity_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief    This API returns the Revision Number of the ELM.
 *
 *  \param    baseAddr   Memory address of the ELM.
 *
 *  \retval   revision   The value holding the IP Revision Number of the module.
 */
uint32_t ELMGetRevision(uint32_t baseAddr);

/**
 *  \brief    This API performs a module reset of the ELM. It also
 *            waits until the reset process is complete.
 *
 *  \param    baseAddr    Memory address of the ELM.
 */
void ELMModuleReset(uint32_t baseAddr);

/**
 * \brief    This function returns the software resets status of ELM.
 *
 * \param    baseAddr    Memory address of the ELM.
 *
 * \retval   TRUE If the Reset is complete.
 * \retval   FALSE If the Reset is not done.
 */
uint32_t ELMModuleIsResetDone(uint32_t baseAddr);

/**
 *  \brief    This API sets the Error Correction level to be used for the
 *            BCH algorithm.
 *
 *  \param    baseAddr    Memory address of the ELM.
 *  \param    eccLevel    The ECC level to be set.
 *            'eccLevel' can take any of the values from the following enum
 *            - #elmBchEccLevel_t
 */
void ELMSetBchEccLevel(uint32_t baseAddr, uint32_t eccLevel);

/**
 *  \brief    This API sets the maximum size of the buffer for which the
 *            Error location engine is used.
 *
 *  \param    baseAddr      Memory address of the ELM.
 *  \param    eccBufSize    The buffer size for the Error location engine.
 *            'eccBufSize' can take any of the values in the range 0 to 0x7FF
 *
 *  \note     The eccBufSize value is to be entered in number of nibbles
 *            (4-bit entities). For instance for a maximum buffer length of
 *            528 bytes the value to be entered is 0x420 i.e
 *            (528 * 2 = 1056 nibbles)
 */
void ELMSetEccBufSize(uint32_t baseAddr, uint32_t eccBufSize);

/**
 *  \brief    This API sets the Error location engine to continuous mode.
 *            In continuous mode each syndrome polynomial is processed
 *            independently.
 *
 *  \param    baseAddr     Memory address of the ELM.
 */
void ELMSetContinuousMode(uint32_t baseAddr);

/**
 *  \brief    This API sets the Error location engine to Page mode. It also
 *            sets a particular syndrome polynomial as part of the page to
 *            to be processed.
 *
 *  \details  In page mode syndrome polynomial are grouped into atomic entities
 *            and only one page is processed at any given time.
 *
 *  \param    baseAddr     Memory address of the ELM.
 *  \param    sectorNum    The mask value to identify if a syndrome polynomial
 *                         is part of the NAND Page.
 *            'sectorNum' can take any of the values from the following enum
 *            - #elmSectorMaskNum_t
 */
void ELMSetPageMode(uint32_t baseAddr, uint32_t sectorNum);

/**
 *  \brief    This API sets the fragment of the input syndrome polynomial
 *            for error location processing.
 *
 *  \param    baseAddr          Memory address of the ELM.
 *  \param    syndromeFragment  The fragment of the syndrome polynomial
 *                              generated by GPMC for which the error location
 *                              processing is to be done.
 *            'syndromeFragment' takes values in the range 0 to 0xFFFFFFFF
 *  \param    syndromePolyNum   The polynomial number from which the fragment is
 *                              derived.
 *            'syndromePolyNum' can take any value in the range 0 to 7.
 *  \param    fragmentId       The syndrome fragment number
 *            'fragmentId' can take any of the values in the range 0 to 6.
 */
void ELMSetSyndromeFragment(uint32_t baseAddr,
                            uint32_t syndromeFragment,
                            uint32_t syndromePolyNum,
                            uint32_t fragmentId);

/**
 *  \brief    This API controls the Enabling/Diabling of the computation process
 *            for Error location for the polynomial set in the syndrome fragment
 *            registers.
 *
 *  \param    baseAddr          Memory address of the ELM.
 *  \param    syndromePolyNum   The polynomial number which should be processed
 *                              for error location.
 *            'syndromePolyNum' can take any value in the range 0 to 7.
 */
void ELMErrLocProcessingStart(uint32_t baseAddr, uint32_t syndromePolyNum);

/**
 *  \brief    This API returns the status of error location processing for a
 *            given syndrome polynomial.
 *
 *  \param    baseAddr          Memory address of the ELM.
 *  \param    syndromePolyNum   The syndrome for which the error location status
 *                              is to be known.
 *            'syndromePolyNum' can take any value in the range 0 to 7.
 *
 *  \retval   status      The status of the error location process.
 *            'status' can be any of the values from the following  enum
 *            - #elmErrLocProcessSts_t
 */
uint32_t ELMErrLocProcessStatus(uint32_t baseAddr, uint32_t syndromePolyNum);

/**
 *  \brief    This API returns the number of errors detected and located.
 *
 *  \param    baseAddr          Memory address of the ELM.
 *  \param    syndromePolyNum   The syndrome polynomial for which the number of
 *                              errors is to be known.
 *            'syndromePolyNum' can take any value in the range 0 to 7.
 *
 *  \retval   errNum      The number of errors detected and processed.
 *            'errNum' can be any of the values in the range 0 to 0x1F
 */
uint32_t ELMGetNumErrors(uint32_t baseAddr, uint32_t syndromePolyNum);

/**
 *  \brief    This API returns the bit address of error location for the
 *            syndrome polynomial.
 *
 *  \param    baseAddr          Memory address of the ELM.
 *  \param    syndromePolyNum   The syndrome polynomial for which the error bit
 *                              address is to be retrieved.
 *            'syndromePolyNum' can take any value in the range 0 to 7.
 *  \param    errRegNum         The error location register number where the
 *                              address is stored.
 *            'errRegNum' can take any value in the range 0 to 15.
 *
 *  \retval   errAddr     The bit address for the error number.
 *            'errAddr' can be any of the values in the range 0 to 0x1FFF
 */
uint32_t ELMGetErrAddress(uint32_t baseAddr,
                          uint32_t syndromePolyNum,
                          uint32_t errRegNum);

/**
 *  \brief    This API enables the specified interrupts for ELM.
 *
 *  \param    baseAddr    Memory address of the ELM.
 *  \param    intrMask    Mask value specifying the ELM interrupts to be
 *                        enabled.
 *            'intrMask' can take any of the values from the following enum
 *            - #elmIntrMask_t
 */
void ELMIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 *  \brief    This API disables the specified interrupts for ELM.
 *
 *  \param    baseAddr    Memory address of the ELM.
 *  \param    intrMask    Mask value specifying the ELM interrupts to be
 *                        disabled.
 *            'intrMask' can take any of the values from the following enum
 *            - #elmIntrMask_t
 */
void ELMIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 *  \brief    This API returns the status of ELM interrupts.
 *
 *  \param    baseAddr    Memory address of the ELM.
 *
 *  \retval   status     The status of ELM interrupts. This can be any of the
 *                       values from the following enum #elmIntrMask_t
 *
 *  \note    To Check the status of a specific interrupt AND the return value
 *           of the API with specific macro from the following enum
 *           - #elmIntrMask_t
 */
uint32_t ELMIntrStatus(uint32_t baseAddr);

/**
 *  \brief    This API clears the status of ELM interrupts.
 *
 *  \param    baseAddr    Memory address of the ELM.
 *  \param    intrMask     Mask specifying which interrupts have to be cleared.
 *            'intrMask' can take any of the values from the following enum
 *            - #elmIntrMask_t
 */
void ELMIntrClear(uint32_t baseAddr, uint32_t intrMask);

/**
 *  \brief    This API controls Enabling/Disabling of the Auto-Gating feature.
 *            It controls the Internal OCP Clock gating strategy for saving
 *            power.
 *
 *  \param    baseAddr         Memory address of the ELM.
 *  \param    enableAutoGating It is the value which controls enabling/disabling
 *                             clock gating feature.
 *           'enableAutoGating' can take any of the 2 values
 *           - TRUE to enable the Auto-Gating feature.
 *           - FALSE to disable the Auto-Gating feature.
 */
void ELMAutoGatingEnable(uint32_t baseAddr, uint32_t enableAutoGating);

/**
 *  \brief    This API sets ELM to one of the Slave Idle modes.
 *
 *  \param    baseAddr    Memory address of the ELM.
 *  \param    idleMode    It is the value which determines the type of idle
 *                        mode operation.
 *           'idleMode' can take any of the values from the following enum
 *           - #elmIdleMode_t
 */
void ELMSetIdleMode(uint32_t baseAddr, uint32_t idleMode);

/**
 *  \brief    This API sets the OCP Clock Activity when module is in Idle mode.
 *
 *  \param    baseAddr      Memory address of the ELM.
 *  \param    clkActivity   It holds the value to control the OCP clock
 *                          behaviour in idle modes.
 *            'clkActivity' can take any of the following values from the
 *            following enum - #elmOcpClkActivity_t
 */
void ELMSetIdleModeOcpClkActivity(uint32_t baseAddr, uint32_t clkActivity);

/* ========================================================================== */
/*                     Deprecated Function Declarations                       */
/* ========================================================================== */

#ifdef __cplusplus
}
#endif

#endif