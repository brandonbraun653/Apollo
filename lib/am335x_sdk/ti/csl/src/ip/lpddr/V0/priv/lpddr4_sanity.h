/**********************************************************************
* Copyright (C) 2012-2019 Cadence Design Systems, Inc.
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**********************************************************************
* WARNING: This file is auto-generated using api-generator utility.
*          api-generator: 12.02.13bb8d5
*          Do not edit it manually.
**********************************************************************
* Cadence Core Driver for LPDDR4.
**********************************************************************/

/* parasoft-begin-suppress METRICS-18-3 "Follow the Cyclomatic Complexity limit of 10" */
/* parasoft-begin-suppress METRICS-36-3 "A function should not be called from more than 5 different functions" */
/* parasoft-begin-suppress METRICS-39-3 "The value of VOCF metric for a function should not be higher than 4" */
/* parasoft-begin-suppress METRICS-41-3 "Number of blocks of comments per statement" */

/**
 * This file contains sanity API functions. The purpose of sanity functions
 * is to check input parameters validity. They take the same parameters as
 * original API functions and return 0 on success or CDN_EINVAL on wrong parameter
 * value(s).
 */

#ifndef LPDDR4_SANITY_H
#define LPDDR4_SANITY_H


static inline uint32_t LPDDR4_ConfigSF(const LPDDR4_Config *obj);
static inline uint32_t LPDDR4_PrivateDataSF(const LPDDR4_PrivateData *obj);

static inline uint32_t LPDDR4_SanityFunction1(const LPDDR4_Config* config, const uint16_t* configSize);
static inline uint32_t LPDDR4_SanityFunction2(const LPDDR4_PrivateData* pD, const LPDDR4_Config* cfg);
static inline uint32_t LPDDR4_SanityFunction3(const LPDDR4_PrivateData* pD);
static inline uint32_t LPDDR4_SanityFunction4(const LPDDR4_PrivateData* pD, const LPDDR4_RegBlock cpp, const uint32_t* regValue);
static inline uint32_t LPDDR4_SanityFunction5(const LPDDR4_PrivateData* pD, const LPDDR4_RegBlock cpp);
static inline uint32_t LPDDR4_SanityFunction6(const LPDDR4_PrivateData* pD, const uint64_t* mmrValue, const uint8_t* mmrStatus);
static inline uint32_t LPDDR4_SanityFunction7(const LPDDR4_PrivateData* pD, const uint8_t* mrwStatus);
static inline uint32_t LPDDR4_SanityFunction14(const LPDDR4_PrivateData* pD, const uint64_t* mask);
static inline uint32_t LPDDR4_SanityFunction15(const LPDDR4_PrivateData* pD, const uint64_t* mask);
static inline uint32_t LPDDR4_SanityFunction16(const LPDDR4_PrivateData* pD, const LPDDR4_CtlInterrupt intr, const bool* irqStatus);
static inline uint32_t LPDDR4_SanityFunction17(const LPDDR4_PrivateData* pD, const LPDDR4_CtlInterrupt intr);
static inline uint32_t LPDDR4_SanityFunction18(const LPDDR4_PrivateData* pD, const uint32_t* mask);
static inline uint32_t LPDDR4_SanityFunction20(const LPDDR4_PrivateData* pD, const LPDDR4_PhyIndepInterrupt intr, const bool* irqStatus);
static inline uint32_t LPDDR4_SanityFunction21(const LPDDR4_PrivateData* pD, const LPDDR4_PhyIndepInterrupt intr);
static inline uint32_t LPDDR4_SanityFunction22(const LPDDR4_PrivateData* pD, const LPDDR4_DebugInfo* debugInfo);
static inline uint32_t LPDDR4_SanityFunction23(const LPDDR4_PrivateData* pD, const LPDDR4_LpiWakeUpParam* lpiWakeUpParam, const LPDDR4_CtlFspNum* fspNum, const uint32_t* cycles);
static inline uint32_t LPDDR4_SanityFunction25(const LPDDR4_PrivateData* pD, const LPDDR4_EccEnable* eccParam);
static inline uint32_t LPDDR4_SanityFunction26(const LPDDR4_PrivateData* pD, const LPDDR4_EccEnable* eccParam);
static inline uint32_t LPDDR4_SanityFunction27(const LPDDR4_PrivateData* pD, const LPDDR4_ReducMode* mode);
static inline uint32_t LPDDR4_SanityFunction28(const LPDDR4_PrivateData* pD, const LPDDR4_ReducMode* mode);
static inline uint32_t LPDDR4_SanityFunction29(const LPDDR4_PrivateData* pD, const bool* on_off);
static inline uint32_t LPDDR4_SanityFunction31(const LPDDR4_PrivateData* pD, const LPDDR4_DbiMode* mode);
static inline uint32_t LPDDR4_SanityFunction32(const LPDDR4_PrivateData* pD, const LPDDR4_CtlFspNum* fspNum, const uint32_t* cycles);

#define LPDDR4_ProbeSF LPDDR4_SanityFunction1
#define LPDDR4_InitSF LPDDR4_SanityFunction2
#define LPDDR4_StartSF LPDDR4_SanityFunction3
#define LPDDR4_ReadRegSF LPDDR4_SanityFunction4
#define LPDDR4_WriteRegSF LPDDR4_SanityFunction5
#define LPDDR4_GetMmrRegisterSF LPDDR4_SanityFunction6
#define LPDDR4_SetMmrRegisterSF LPDDR4_SanityFunction7
#define LPDDR4_WriteCtlConfigSF LPDDR4_SanityFunction3
#define LPDDR4_WritePhyConfigSF LPDDR4_SanityFunction3
#define LPDDR4_WritePhyIndepConfigSF LPDDR4_SanityFunction3
#define LPDDR4_ReadCtlConfigSF LPDDR4_SanityFunction3
#define LPDDR4_ReadPhyConfigSF LPDDR4_SanityFunction3
#define LPDDR4_ReadPhyIndepConfigSF LPDDR4_SanityFunction3
#define LPDDR4_GetCtlInterruptMaskSF LPDDR4_SanityFunction14
#define LPDDR4_SetCtlInterruptMaskSF LPDDR4_SanityFunction15
#define LPDDR4_CheckCtlInterruptSF LPDDR4_SanityFunction16
#define LPDDR4_AckCtlInterruptSF LPDDR4_SanityFunction17
#define LPDDR4_GetPhyIndepInterruptMSF LPDDR4_SanityFunction18
#define LPDDR4_SetPhyIndepInterruptMSF LPDDR4_SanityFunction18
#define LPDDR4_CheckPhyIndepInterrupSF LPDDR4_SanityFunction20
#define LPDDR4_AckPhyIndepInterruptSF LPDDR4_SanityFunction21
#define LPDDR4_GetDebugInitInfoSF LPDDR4_SanityFunction22
#define LPDDR4_GetLpiWakeUpTimeSF LPDDR4_SanityFunction23
#define LPDDR4_SetLpiWakeUpTimeSF LPDDR4_SanityFunction23
#define LPDDR4_GetEccEnableSF LPDDR4_SanityFunction25
#define LPDDR4_SetEccEnableSF LPDDR4_SanityFunction26
#define LPDDR4_GetReducModeSF LPDDR4_SanityFunction27
#define LPDDR4_SetReducModeSF LPDDR4_SanityFunction28
#define LPDDR4_GetDbiReadModeSF LPDDR4_SanityFunction29
#define LPDDR4_GetDbiWriteModeSF LPDDR4_SanityFunction29
#define LPDDR4_SetDbiModeSF LPDDR4_SanityFunction31
#define LPDDR4_GetRefreshRateSF LPDDR4_SanityFunction32
#define LPDDR4_SetRefreshRateSF LPDDR4_SanityFunction32
#define LPDDR4_RefreshPerChipSelectSF LPDDR4_SanityFunction3

/**
 * Function to validate struct Config
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
static inline uint32_t LPDDR4_ConfigSF(const LPDDR4_Config *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * Function to validate struct PrivateData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
static inline uint32_t LPDDR4_PrivateDataSF(const LPDDR4_PrivateData *obj)
{
    uint32_t ret = 0;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] config Driver/hardware configuration required.
 * @param[out] configSize Size of memory allocations required.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction1(const LPDDR4_Config* config, const uint16_t* configSize)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (configSize == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_ConfigSF(config) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] cfg Specifies driver/hardware configuration.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction2(const LPDDR4_PrivateData* pD, const LPDDR4_Config* cfg)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_ConfigSF(cfg) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction3(const LPDDR4_PrivateData* pD)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] cpp Indicates whether controller, PHY or PHY Independent Module register
 * @param[out] regValue Register value read
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction4(const LPDDR4_PrivateData* pD, const LPDDR4_RegBlock cpp, const uint32_t* regValue)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (regValue == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (cpp != LPDDR4_CTL_REGS) &&
        (cpp != LPDDR4_PHY_REGS) &&
        (cpp != LPDDR4_PHY_INDEP_REGS)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] cpp Indicates whether controller, PHY or PHY Independent Module register
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction5(const LPDDR4_PrivateData* pD, const LPDDR4_RegBlock cpp)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (cpp != LPDDR4_CTL_REGS) &&
        (cpp != LPDDR4_PHY_REGS) &&
        (cpp != LPDDR4_PHY_INDEP_REGS)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] mmrValue Value which is read from memory mode register(mmr) for all devices.
 * @param[out] mmrStatus Status of mode register read(mrr) instruction.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction6(const LPDDR4_PrivateData* pD, const uint64_t* mmrValue, const uint8_t* mmrStatus)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mmrValue == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (mmrStatus == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] mrwStatus Status of mode register write(mrw) instruction.
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction7(const LPDDR4_PrivateData* pD, const uint8_t* mrwStatus)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mrwStatus == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] mask Value of interrupt mask
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction14(const LPDDR4_PrivateData* pD, const uint64_t* mask)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mask == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] mask Value of interrupt mask to be written
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction15(const LPDDR4_PrivateData* pD, const uint64_t* mask)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mask == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] intr Interrupt to be checked
 * @param[out] irqStatus Status of the interrupt, TRUE if active
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction16(const LPDDR4_PrivateData* pD, const LPDDR4_CtlInterrupt intr, const bool* irqStatus)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (irqStatus == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (intr != LPDDR4_RESET_DONE) &&
        (intr != LPDDR4_BUS_ACCESS_ERROR) &&
        (intr != LPDDR4_MULTIPLE_BUS_ACCESS_ERROR) &&
        (intr != LPDDR4_ECC_MULTIPLE_CORR_ERROR) &&
        (intr != LPDDR4_ECC_MULTIPLE_UNCORR_ERROR) &&
        (intr != LPDDR4_ECC_WRITEBACK_EXEC_ERROR) &&
        (intr != LPDDR4_ECC_SCRUB_DONE) &&
        (intr != LPDDR4_ECC_SCRUB_ERROR) &&
        (intr != LPDDR4_PORT_COMMAND_ERROR) &&
        (intr != LPDDR4_MC_INIT_DONE) &&
        (intr != LPDDR4_LP_DONE) &&
        (intr != LPDDR4_BIST_DONE) &&
        (intr != LPDDR4_WRAP_ERROR) &&
        (intr != LPDDR4_INVALID_BURST_ERROR) &&
        (intr != LPDDR4_RDLVL_ERROR) &&
        (intr != LPDDR4_RDLVL_GATE_ERROR) &&
        (intr != LPDDR4_WRLVL_ERROR) &&
        (intr != LPDDR4_CA_TRAINING_ERROR) &&
        (intr != LPDDR4_DFI_UPDATE_ERROR) &&
        (intr != LPDDR4_MRR_ERROR) &&
        (intr != LPDDR4_PHY_MASTER_ERROR) &&
        (intr != LPDDR4_WRLVL_REQ) &&
        (intr != LPDDR4_RDLVL_REQ) &&
        (intr != LPDDR4_RDLVL_GATE_REQ) &&
        (intr != LPDDR4_CA_TRAINING_REQ) &&
        (intr != LPDDR4_LEVELING_DONE) &&
        (intr != LPDDR4_PHY_ERROR) &&
        (intr != LPDDR4_MR_READ_DONE) &&
        (intr != LPDDR4_TEMP_CHANGE) &&
        (intr != LPDDR4_TEMP_ALERT) &&
        (intr != LPDDR4_SW_DQS_COMPLETE) &&
        (intr != LPDDR4_DQS_OSC_BV_UPDATED) &&
        (intr != LPDDR4_DQS_OSC_OVERFLOW) &&
        (intr != LPDDR4_DQS_OSC_VAR_OUT) &&
        (intr != LPDDR4_MR_WRITE_DONE) &&
        (intr != LPDDR4_INHIBIT_DRAM_DONE) &&
        (intr != LPDDR4_DFI_INIT_STATE) &&
        (intr != LPDDR4_DLL_RESYNC_DONE) &&
        (intr != LPDDR4_TDFI_TO) &&
        (intr != LPDDR4_DFS_DONE) &&
        (intr != LPDDR4_DFS_STATUS) &&
        (intr != LPDDR4_REFRESH_STATUS) &&
        (intr != LPDDR4_ZQ_STATUS) &&
        (intr != LPDDR4_SW_REQ_MODE) &&
        (intr != LPDDR4_LOR_BITS)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] intr Interrupt to be acknowledged
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction17(const LPDDR4_PrivateData* pD, const LPDDR4_CtlInterrupt intr)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (intr != LPDDR4_RESET_DONE) &&
        (intr != LPDDR4_BUS_ACCESS_ERROR) &&
        (intr != LPDDR4_MULTIPLE_BUS_ACCESS_ERROR) &&
        (intr != LPDDR4_ECC_MULTIPLE_CORR_ERROR) &&
        (intr != LPDDR4_ECC_MULTIPLE_UNCORR_ERROR) &&
        (intr != LPDDR4_ECC_WRITEBACK_EXEC_ERROR) &&
        (intr != LPDDR4_ECC_SCRUB_DONE) &&
        (intr != LPDDR4_ECC_SCRUB_ERROR) &&
        (intr != LPDDR4_PORT_COMMAND_ERROR) &&
        (intr != LPDDR4_MC_INIT_DONE) &&
        (intr != LPDDR4_LP_DONE) &&
        (intr != LPDDR4_BIST_DONE) &&
        (intr != LPDDR4_WRAP_ERROR) &&
        (intr != LPDDR4_INVALID_BURST_ERROR) &&
        (intr != LPDDR4_RDLVL_ERROR) &&
        (intr != LPDDR4_RDLVL_GATE_ERROR) &&
        (intr != LPDDR4_WRLVL_ERROR) &&
        (intr != LPDDR4_CA_TRAINING_ERROR) &&
        (intr != LPDDR4_DFI_UPDATE_ERROR) &&
        (intr != LPDDR4_MRR_ERROR) &&
        (intr != LPDDR4_PHY_MASTER_ERROR) &&
        (intr != LPDDR4_WRLVL_REQ) &&
        (intr != LPDDR4_RDLVL_REQ) &&
        (intr != LPDDR4_RDLVL_GATE_REQ) &&
        (intr != LPDDR4_CA_TRAINING_REQ) &&
        (intr != LPDDR4_LEVELING_DONE) &&
        (intr != LPDDR4_PHY_ERROR) &&
        (intr != LPDDR4_MR_READ_DONE) &&
        (intr != LPDDR4_TEMP_CHANGE) &&
        (intr != LPDDR4_TEMP_ALERT) &&
        (intr != LPDDR4_SW_DQS_COMPLETE) &&
        (intr != LPDDR4_DQS_OSC_BV_UPDATED) &&
        (intr != LPDDR4_DQS_OSC_OVERFLOW) &&
        (intr != LPDDR4_DQS_OSC_VAR_OUT) &&
        (intr != LPDDR4_MR_WRITE_DONE) &&
        (intr != LPDDR4_INHIBIT_DRAM_DONE) &&
        (intr != LPDDR4_DFI_INIT_STATE) &&
        (intr != LPDDR4_DLL_RESYNC_DONE) &&
        (intr != LPDDR4_TDFI_TO) &&
        (intr != LPDDR4_DFS_DONE) &&
        (intr != LPDDR4_DFS_STATUS) &&
        (intr != LPDDR4_REFRESH_STATUS) &&
        (intr != LPDDR4_ZQ_STATUS) &&
        (intr != LPDDR4_SW_REQ_MODE) &&
        (intr != LPDDR4_LOR_BITS)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] mask Value of interrupt mask
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction18(const LPDDR4_PrivateData* pD, const uint32_t* mask)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mask == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] intr Interrupt to be checked
 * @param[out] irqStatus Status of the interrupt, TRUE if active
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction20(const LPDDR4_PrivateData* pD, const LPDDR4_PhyIndepInterrupt intr, const bool* irqStatus)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (irqStatus == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (intr != LPDDR4_PHY_INDEP_INIT_DONE_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CONTROL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CA_PARITY_ERR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_GATE_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WRLVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CALVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WDQLVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_UPDATE_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_GATE_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WRLVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CALVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WDQLVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_LVL_DONE_BIT) &&
        (intr != LPDDR4_PHY_INDEP_BIST_DONE_BIT) &&
        (intr != LPDDR4_PHY_INDEP_TDFI_INIT_TIME_OUT_BIT) &&
        (intr != LPDDR4_PHY_INDEP_DLL_LOCK_STATE_CHANGE_BIT)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] intr Interrupt to be acknowledged
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction21(const LPDDR4_PrivateData* pD, const LPDDR4_PhyIndepInterrupt intr)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (intr != LPDDR4_PHY_INDEP_INIT_DONE_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CONTROL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CA_PARITY_ERR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_GATE_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WRLVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CALVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WDQLVL_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_UPDATE_ERROR_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_RDLVL_GATE_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WRLVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_CALVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_WDQLVL_REQ_BIT) &&
        (intr != LPDDR4_PHY_INDEP_LVL_DONE_BIT) &&
        (intr != LPDDR4_PHY_INDEP_BIST_DONE_BIT) &&
        (intr != LPDDR4_PHY_INDEP_TDFI_INIT_TIME_OUT_BIT) &&
        (intr != LPDDR4_PHY_INDEP_DLL_LOCK_STATE_CHANGE_BIT)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] debugInfo status
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction22(const LPDDR4_PrivateData* pD, const LPDDR4_DebugInfo* debugInfo)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (debugInfo == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] lpiWakeUpParam LPI timing parameter
 * @param[in] fspNum Frequency copy
 * @param[out] cycles Timing value(in cycles)
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction23(const LPDDR4_PrivateData* pD, const LPDDR4_LpiWakeUpParam* lpiWakeUpParam, const LPDDR4_CtlFspNum* fspNum, const uint32_t* cycles)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (lpiWakeUpParam == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (fspNum == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (cycles == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (*lpiWakeUpParam != LPDDR4_LPI_PD_WAKEUP_FN) &&
        (*lpiWakeUpParam != LPDDR4_LPI_SR_SHORT_WAKEUP_FN) &&
        (*lpiWakeUpParam != LPDDR4_LPI_SR_LONG_WAKEUP_FN) &&
        (*lpiWakeUpParam != LPDDR4_LPI_SR_LONG_MCCLK_GATE_WAKEUP_FN) &&
        (*lpiWakeUpParam != LPDDR4_LPI_SRPD_SHORT_WAKEUP_FN) &&
        (*lpiWakeUpParam != LPDDR4_LPI_SRPD_LONG_WAKEUP_FN) &&
        (*lpiWakeUpParam != LPDDR4_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_FN)
        )
    {
        ret = CDN_EINVAL;
    }
    else if (
        (*fspNum != LPDDR4_FSP_0) &&
        (*fspNum != LPDDR4_FSP_1) &&
        (*fspNum != LPDDR4_FSP_2)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] eccParam ECC parameter setting
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction25(const LPDDR4_PrivateData* pD, const LPDDR4_EccEnable* eccParam)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (eccParam == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] eccParam ECC control parameter setting
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction26(const LPDDR4_PrivateData* pD, const LPDDR4_EccEnable* eccParam)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (eccParam == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (*eccParam != LPDDR4_ECC_DISABLED) &&
        (*eccParam != LPDDR4_ECC_ENABLED) &&
        (*eccParam != LPDDR4_ECC_ERR_DETECT) &&
        (*eccParam != LPDDR4_ECC_ERR_DETECT_CORRECT)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] mode Half Datapath setting
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction27(const LPDDR4_PrivateData* pD, const LPDDR4_ReducMode* mode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mode == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] mode Half Datapath setting
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction28(const LPDDR4_PrivateData* pD, const LPDDR4_ReducMode* mode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mode == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (*mode != LPDDR4_REDUC_ON) &&
        (*mode != LPDDR4_REDUC_OFF)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[out] on_off DBI read value
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction29(const LPDDR4_PrivateData* pD, const bool* on_off)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (on_off == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] mode status
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction31(const LPDDR4_PrivateData* pD, const LPDDR4_DbiMode* mode)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (mode == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (*mode != LPDDR4_DBI_RD_ON) &&
        (*mode != LPDDR4_DBI_RD_OFF) &&
        (*mode != LPDDR4_DBI_WR_ON) &&
        (*mode != LPDDR4_DBI_WR_OFF)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/**
 * A common function to check the validity of API functions with
 * following parameter types
 * @param[in] pD Driver state info specific to this instance.
 * @param[in] fspNum Frequency set number
 * @param[out] cycles Refresh rate (in cycles)
 * @return 0 success
 * @return CDN_EINVAL invalid parameters
 */
static inline uint32_t LPDDR4_SanityFunction32(const LPDDR4_PrivateData* pD, const LPDDR4_CtlFspNum* fspNum, const uint32_t* cycles)
{
    /* Declaring return variable */
    uint32_t ret = 0;

    if (fspNum == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (cycles == NULL)
    {
        ret = CDN_EINVAL;
    }
    else if (LPDDR4_PrivateDataSF(pD) == CDN_EINVAL)
    {
        ret = CDN_EINVAL;
    }
    else if (
        (*fspNum != LPDDR4_FSP_0) &&
        (*fspNum != LPDDR4_FSP_1) &&
        (*fspNum != LPDDR4_FSP_2)
        )
    {
        ret = CDN_EINVAL;
    }
    else
    {
        /*
         * All 'if ... else if' constructs shall be terminated with an 'else' statement
         * (MISRA2012-RULE-15_7-3)
         */
    }

    return ret;
}

/* parasoft-end-suppress METRICS-41-3 */
/* parasoft-end-suppress METRICS-39-3 */
/* parasoft-end-suppress METRICS-36-3 */
/* parasoft-end-suppress METRICS-18-3 */

#endif  /* LPDDR4_SANITY_H */
