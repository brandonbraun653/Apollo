/**
 *   @file  csl_emif4fAux.h
 *
 *   @brief   
 *      This is the EMIF4F Auxilary Header File which exposes the various
 *      CSL Functional Layer API's to configure the EMIF4FV Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2013, Texas Instruments, Inc.
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

#ifndef CSL_EMIF4FAUX_V0_H_
#define CSL_EMIF4FAUX_V0_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_emif4f.h>

/** @addtogroup CSL_EMIF4F_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetModuleInfo
 *
 *   @b Description
 *   @n This function reads the peripheral ID register which identifies the 
 *      module id, RTL version information etc.
 *
 *   @b Arguments
     @verbatim
          moduleID     Module Id Information populated by this API
          rtlInfo      RTL Version Information populated by this API
          majRev       Major Revision Information populated by this API
          minRev       Minor Revision Information populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_EMIF_MOD_ID_REV_REG_MODULE_ID,EMIF4FV_EMIF_MOD_ID_REV_REG_RTL_VERSION,
 *      EMIF4FV_EMIF_MOD_ID_REV_REG_MAJOR_REVISION,EMIF4FV_EMIF_MOD_ID_REV_REG_MINOR_REVISION
 *
 *   @b Example
 *   @verbatim
        Uint8   moduleID;
        Uint8   rtlInfo;
        Uint8   majRev;
        Uint8   minRev;

        // Get the EMIF4F Module Information.
        CSL_EMIF4F_GetModuleInfo (&moduleID, &rtlInfo, &majRev, &minRev);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetModuleInfo
(
    Uint8*  moduleID,    
    Uint8*  rtlInfo, 
    Uint8*  majRev, 
    Uint8*  minRev
)
{
    Uint32 value = hEmif->EMIF_MOD_ID_REV;

    *moduleID = CSL_FEXT (value, EMIF4FV_EMIF_MOD_ID_REV_REG_MODULE_ID);
    *rtlInfo  = CSL_FEXT (value, EMIF4FV_EMIF_MOD_ID_REV_REG_RTL_VERSION);
    *majRev   = CSL_FEXT (value, EMIF4FV_EMIF_MOD_ID_REV_REG_MAJOR_REVISION);
    *minRev   = CSL_FEXT (value, EMIF4FV_EMIF_MOD_ID_REV_REG_MINOR_REVISION);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_IsBigEndian
 *
 *   @b Description
 *   @n The function gets the endianess mode in which the EMIF4F is operating. 
 *
 *   @b Arguments
     @verbatim
         None 
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE    -   Big Endian Mode
 *   @n FALSE   -   Little Endian Mode.
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_STATUS_REG_BE
 *
 *   @b Example
 *   @verbatim

        // Get the EMIF4F Endianness mode.
        if (CSL_EMIF4F_IsBigEndian () == TRUE)
        {
            // Big Endian Mode.
        }
        else
        {
            // Little Endian Mode.
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_EMIF4F_IsBigEndian()
{
    return (Bool)CSL_FEXT(hEmif->STATUS, EMIF4FV_STATUS_REG_BE);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_IsAsynchronous
 *
 *   @b Description
 *   @n The function gets the dual clock mode on which the EMIF4F is operating.
 *
 *   @b Arguments
     @verbatim
         None 
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE    -   Asynchronous (V_CLK and M_CLK can have any freq ratio)
 *   @n FALSE   -   Synchronous  (V_CLK is the same as M_CLK)
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_STATUS_REG_DUAL_CLK_MODE
 *
 *   @b Example
 *   @verbatim

        // Get the EMIF4F Clock
        if (CSL_EMIF4F_IsAsynchronous () == TRUE)
        {
            // Asynchronous Clock
        }
        else
        {
            // Synchronous Clock
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_EMIF4F_IsAsynchronous()
{
    return (Bool)CSL_FEXT(hEmif->STATUS, EMIF4FV_STATUS_REG_DUAL_CLK_MODE);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_IsDDRPhyRead
 *
 *   @b Description
 *   @n The function gets the status of the DDR PHY
 *
 *   @b Arguments
     @verbatim
         None 
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE    -   DDR PHY is ready
 *   @n FALSE   -   DDR PHY is not ready
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_STATUS_REG_PHY_DLL_READY
 *
 *   @b Example
 *   @verbatim

        // Get the EMIF4F DDR PHY Ready Status
        if (CSL_EMIF4F_IsDDRPhyRead () == TRUE)
        {
            // DDR PHY is ready
        }
        else
        {
            // DDR PHY is not ready
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_EMIF4F_IsDDRPhyRead()
{
    return (Bool)CSL_FEXT(hEmif->STATUS, EMIF4FV_STATUS_REG_PHY_DLL_READY);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetSDRAMConfig
 *
 *   @b Description
 *   @n The function gets the current SDRAM Configuration.
 *
 *   @b Arguments
     @verbatim
         ptrConfig  SDRAM Configuration populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_SDRAM_CONFIG_REG_SDRAM_TYPE,EMIF4FV_SDRAM_CONFIG_REG_DDR_TERM,
 *      EMIF4FV_SDRAM_CONFIG_REG_DDR2_DDQS,EMIF4FV_SDRAM_CONFIG_REG_DYN_ODT,
 *      EMIF4FV_SDRAM_CONFIG_REG_CWL,EMIF4FV_SDRAM_CONFIG_REG_NARROW_MODE,
 *      EMIF4FV_SDRAM_CONFIG_REG_CL,EMIF4FV_SDRAM_CONFIG_REG_IBANK,
 *      EMIF4FV_SDRAM_CONFIG_REG_EBANK,EMIF4FV_SDRAM_CONFIG_REG_PAGESIZE
 *
 *   @b Example
 *   @verbatim
        EMIF4F_SDRAM_CONFIG  sdramConfig;
        ...
        // Get the EMIF4F SDRAM Configuration.
        CSL_EMIF4F_GetSDRAMConfig (&sdramConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetSDRAMConfig(EMIF4F_SDRAM_CONFIG* ptrConfig)
{
    Uint32  sdramConfig = hEmif->SDRAM_CONFIG;

    /* Extract all the fields from the SDRAM Configuration. */
    ptrConfig->type         = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_SDRAM_TYPE);
    ptrConfig->ddrTerm      = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_DDR_TERM);
    ptrConfig->ddrDDQS      = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_DDR2_DDQS);
    ptrConfig->dynODT       = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_DYN_ODT);
    ptrConfig->CASWriteLat  = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_CWL);
    ptrConfig->narrowMode   = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_NARROW_MODE);
    ptrConfig->CASLatency   = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_CL);
    ptrConfig->iBank        = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_IBANK);
    ptrConfig->eBank        = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_EBANK);
    ptrConfig->pageSize     = CSL_FEXT(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_PAGESIZE);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetSDRAMConfig
 *
 *   @b Description
 *   @n The function sets the SDRAM Configuration as specified.
 *
 *   @b Arguments
     @verbatim
         ptrConfig  SDRAM Configuration to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_SDRAM_CONFIG_REG_SDRAM_TYPE,EMIF4FV_SDRAM_CONFIG_REG_DDR_TERM,
 *      EMIF4FV_SDRAM_CONFIG_REG_DDR2_DDQS,EMIF4FV_SDRAM_CONFIG_REG_DYN_ODT,
 *      EMIF4FV_SDRAM_CONFIG_REG_CWL,EMIF4FV_SDRAM_CONFIG_REG_NARROW_MODE,
 *      EMIF4FV_SDRAM_CONFIG_REG_CL,EMIF4FV_SDRAM_CONFIG_REG_IBANK,
 *      EMIF4FV_SDRAM_CONFIG_REG_EBANK,EMIF4FV_SDRAM_CONFIG_REG_PAGESIZE
 *
 *   @b Example
 *   @verbatim
        EMIF4F_SDRAM_CONFIG  sdramConfig;
        ...
        // Get the EMIF4F SDRAM Configuration.
        CSL_EMIF4F_GetSDRAMConfig (&sdramConfig);
        ...
        // Set the SDRAM Data Bus Width to be 32 bits
        sdramConfig.narrowMode = 0;

        // Set the EMIF4F SDRAM Configuration.
        CSL_EMIF4F_SetSDRAMConfig (&sdramConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetSDRAMConfig(EMIF4F_SDRAM_CONFIG* ptrConfig)
{
    Uint32  sdramConfig = 0;

    /* Initialize the SDRAM Configuration. */
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_SDRAM_TYPE, ptrConfig->type);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_DDR_TERM, ptrConfig->ddrTerm);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_DDR2_DDQS, ptrConfig->ddrDDQS);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_DYN_ODT, ptrConfig->dynODT);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_CWL, ptrConfig->CASWriteLat);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_NARROW_MODE, ptrConfig->narrowMode);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_CL, ptrConfig->CASLatency);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_IBANK, ptrConfig->iBank);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_EBANK, ptrConfig->eBank);
    CSL_FINS(sdramConfig, EMIF4FV_SDRAM_CONFIG_REG_PAGESIZE, ptrConfig->pageSize);

    /* Write to the register */
    hEmif->SDRAM_CONFIG = sdramConfig;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_DisableInitRefresh
 *
 *   @b Description
 *   @n The function is used to disable the initialization and refresh.
 *
 *   @b Arguments
     @verbatim
         None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_SDRAM_REF_CTRL_REG_INITREF_DIS=1
 *
 *   @b Example
 *   @verbatim

        // Disable Initialization & Refresh
        CSL_EMIF4F_DisableInitRefresh();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_DisableInitRefresh(void)
{
    CSL_FINS(hEmif->SDRAM_REF_CTRL, EMIF4FV_SDRAM_REF_CTRL_REG_INITREF_DIS, (Uint32)1);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_EnableInitRefresh
 *
 *   @b Description
 *   @n The function is used to enable the initialization and refresh.
 *
 *   @b Arguments
     @verbatim
         None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_SDRAM_REF_CTRL_REG_INITREF_DIS=0
 *
 *   @b Example
 *   @verbatim

        // Enable Initialization & Refresh
        CSL_EMIF4F_EnableInitRefresh();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_EnableInitRefresh(void)
{
    CSL_FINS(hEmif->SDRAM_REF_CTRL, EMIF4FV_SDRAM_REF_CTRL_REG_INITREF_DIS, 0);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetRefreshRate
 *
 *   @b Description
 *   @n The function is used to get the refresh rate
 *
 *   @b Arguments
     @verbatim
         None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Current Refresh Rate configuration
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_SDRAM_REF_CTRL_REG_REFRESH_RATE
 *
 *   @b Example
 *   @verbatim
        Uint8   refreshRate;

        // Get the Refresh Rate 
        refreshRate = CSL_EMIF4F_GetRefreshRate();
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint16 CSL_EMIF4F_GetRefreshRate(void)
{
    return CSL_FEXT(hEmif->SDRAM_REF_CTRL, EMIF4FV_SDRAM_REF_CTRL_REG_REFRESH_RATE);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetRefreshRate
 *
 *   @b Description
 *   @n The function is used to set the refresh rate
 *
 *   @b Arguments
     @verbatim
         refreshRate   Refresh Rate to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_SDRAM_REF_CTRL_REG_REFRESH_RATE
 *
 *   @b Example
 *   @verbatim

        // Enable Initialization & Refresh
        CSL_EMIF4F_EnableInitRefresh();

        // Set the Refresh Rate to be 15.7 us 
        CSL_EMIF4F_SetRefreshRate(0x7AA);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetRefreshRate(Uint16 refreshRate)
{
    CSL_FINS(hEmif->SDRAM_REF_CTRL, EMIF4FV_SDRAM_REF_CTRL_REG_REFRESH_RATE, refreshRate);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetTiming1Config
 *
 *   @b Description
 *   @n The function is used to get the SDRAM Timing1 Configuration
 *
 *   @b Arguments
     @verbatim
         ptrTimingConfig       Timing Configuration populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_SDRAM_TIM_1_REG_T_WR, EMIF4FV_SDRAM_TIM_1_REG_T_RAS,
 *      EMIF4FV_SDRAM_TIM_1_REG_T_RC, EMIF4FV_SDRAM_TIM_1_REG_T_RRD,
 *      EMIF4FV_SDRAM_TIM_1_REG_T_WTR
 *
 *   @b Example
 *   @verbatim
        EMIF4F_TIMING1_CONFIG timingConfig;

        // Get the current timing configuration.
        CSL_EMIF4F_GetTiming1Config(&timingConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetTiming1Config(EMIF4F_TIMING1_CONFIG* ptrTimingConfig)
{   
    Uint32 timingConfig = hEmif->SDRAM_TIM_1;

    /* Extract all the fields from the Timing Register */
    ptrTimingConfig->t_wr  = CSL_FEXT(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_WR);
    ptrTimingConfig->t_ras = CSL_FEXT(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_RAS);
    ptrTimingConfig->t_rc  = CSL_FEXT(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_RC);
    ptrTimingConfig->t_rrd = CSL_FEXT(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_RRD);
    ptrTimingConfig->t_wtr = CSL_FEXT(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_WTR);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetTiming1Config
 *
 *   @b Description
 *   @n The function is used to set the SDRAM Timing1 Configuration
 *
 *   @b Arguments
     @verbatim
         ptrTimingConfig       Timing Configuration to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_SDRAM_TIM_1_REG_T_WR, EMIF4FV_SDRAM_TIM_1_REG_T_RAS,
 *      EMIF4FV_SDRAM_TIM_1_REG_T_RC, EMIF4FV_SDRAM_TIM_1_REG_T_RRD,
 *      EMIF4FV_SDRAM_TIM_1_REG_T_WTR
 *
 *   @b Example
 *   @verbatim
        EMIF4F_TIMING1_CONFIG timingConfig;

        // Get the current timing configuration.
        CSL_EMIF4F_GetTiming1Config(&timingConfig);

        // Set the min number of m_clk cycles from precharge to activate
        timingConfig.t_rp = 1;

        // Set the timing configuration.
        CSL_EMIF4F_SetTiming1Config (&timingConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetTiming1Config(EMIF4F_TIMING1_CONFIG* ptrTimingConfig)
{   
    Uint32 timingConfig = 0;

    /* Insert all the fields from the Timing Register */
    CSL_FINS(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_WR,  ptrTimingConfig->t_wr);
    CSL_FINS(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_RAS, ptrTimingConfig->t_ras);
    CSL_FINS(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_RC,  ptrTimingConfig->t_rc);
    CSL_FINS(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_RRD, ptrTimingConfig->t_rrd);
    CSL_FINS(timingConfig, EMIF4FV_SDRAM_TIM_1_REG_T_WTR, ptrTimingConfig->t_wtr);

    /* Initialize the timing configuration register. */
    hEmif->SDRAM_TIM_1 = timingConfig;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetPowerMgmtConfig
 *
 *   @b Description
 *   @n The function is used to get the Power Management Configuration.
 *
 *   @b Arguments
     @verbatim
         ptrPwrMgmtConfig       Power Management Configuration populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_PWR_MGMT_CTRL_REG_PD_TIM,  EMIF4FV_PWR_MGMT_CTRL_REG_DPD_EN,
 *      EMIF4FV_PWR_MGMT_CTRL_REG_LP_MODE, EMIF4FV_PWR_MGMT_CTRL_REG_SR_TIM,
 *      EMIF4FV_PWR_MGMT_CTRL_REG_CS_TIM
 *
 *   @b Example
 *   @verbatim
        EMIF4F_PWR_MGMT_CONFIG pwrConfig;

        // Get the power management configuration.
        CSL_EMIF4F_GetPowerMgmtConfig(&pwrConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetPowerMgmtConfig(EMIF4F_PWR_MGMT_CONFIG* ptrPwrMgmtConfig)
{
    Uint32 powerMgmtConfig = hEmif->PWR_MGMT_CTRL;

    /* Extract all the fields from the Power Management Register */
    ptrPwrMgmtConfig->pdTime     = CSL_FEXT(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_PD_TIM);
    ptrPwrMgmtConfig->dpdEnable  = CSL_FEXT(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_DPD_EN);
    ptrPwrMgmtConfig->lpMode     = CSL_FEXT(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_LP_MODE);
    ptrPwrMgmtConfig->srTime     = CSL_FEXT(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_SR_TIM);
    ptrPwrMgmtConfig->csTime     = CSL_FEXT(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_CS_TIM);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetPowerMgmtConfig
 *
 *   @b Description
 *   @n The function is used to set the Power Management Configuration.
 *
 *   @b Arguments
     @verbatim
         ptrPwrMgmtConfig       Power Management Configuration to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_PWR_MGMT_CTRL_REG_PD_TIM,  EMIF4FV_PWR_MGMT_CTRL_REG_DPD_EN,
 *      EMIF4FV_PWR_MGMT_CTRL_REG_LP_MODE, EMIF4FV_PWR_MGMT_CTRL_REG_SR_TIM,
 *      EMIF4FV_PWR_MGMT_CTRL_REG_CS_TIM
 *
 *   @b Example
 *   @verbatim
        EMIF4F_PWR_MGMT_CONFIG pwrConfig;

        // Get the power management configuration.
        CSL_EMIF4F_GetPowerMgmtConfig(&pwrConfig);

        // Enable Deep Power Down Mode
        pwrConfig.dpdEnable = 1;

        // Set the power management configuration
        CSL_EMIF4F_SetPowerMgmtConfig(&pwrConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetPowerMgmtConfig(EMIF4F_PWR_MGMT_CONFIG* ptrPwrMgmtConfig)
{
    Uint32 powerMgmtConfig = 0;

    /* Initialzie all the fields for the Power Management Register */
    CSL_FINS(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_PD_TIM,  ptrPwrMgmtConfig->pdTime);
    CSL_FINS(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_DPD_EN,  ptrPwrMgmtConfig->dpdEnable);
    CSL_FINS(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_LP_MODE, ptrPwrMgmtConfig->lpMode);
    CSL_FINS(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_SR_TIM,  ptrPwrMgmtConfig->srTime);
    CSL_FINS(powerMgmtConfig, EMIF4FV_PWR_MGMT_CTRL_REG_CS_TIM,  ptrPwrMgmtConfig->csTime);

    /* Initialize the register */
    hEmif->PWR_MGMT_CTRL = powerMgmtConfig;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetVBUSConfig
 *
 *   @b Description
 *   @n The function is used to get the VBUSM Configuration
 *
 *   @b Arguments
     @verbatim
        cosCount1   Priority Raise Counter for Class of Service 1
        cosCount2   Priority Raise Counter for Class of Service 2
        prOldCount  Priority Raise Old Counter
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Priority Raise New Counter
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_1, EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_2,
 *   @n EMIF4FV_VBUSM_CONFIG_REG_PR_OLD_COUNT
 *
 *   @b Example
 *   @verbatim
        Uint8 cosCount1;
        Uint8 cosCount2;
        Uint8 prOldCount;

        // Get the VBUS Configuration
        CSL_EMIF4F_GetVBUSConfig(&cosCount1, &cosCount2, &prOldCount);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetVBUSConfig(Uint8* cosCount1, Uint8* cosCount2, Uint8* prOldCount)
{
    *cosCount1  = CSL_FEXT(hEmif->VBUSM_CONFIG, EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_1);
    *cosCount2  = CSL_FEXT(hEmif->VBUSM_CONFIG, EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_2);
    *prOldCount = CSL_FEXT(hEmif->VBUSM_CONFIG, EMIF4FV_VBUSM_CONFIG_REG_PR_OLD_COUNT);
    return;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetVBUSConfig
 *
 *   @b Description
 *   @n The function is used to set the VBUSM Configuration
 *
 *   @b Arguments
     @verbatim
        cosCount1   Priority Raise Counter for Class of Service 1
        cosCount2   Priority Raise Counter for Class of Service 2
        prOldCount  Priority Raise Old Counter
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None 
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_1, EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_2,
 *   @n EMIF4FV_VBUSM_CONFIG_REG_PR_OLD_COUNT
 *
 *   @b Example
 *   @verbatim
        Uint8 cosCount1;
        Uint8 cosCount2;
        Uint8 prOldCount;

        // Get the VBUS Configuration
        CSL_EMIF4F_GetVBUSConfig(&cosCount1, &cosCount2, &prOldCount);

        // Set the VBUS Configuration
        CSL_EMIF4F_SetVBUSConfig(cosCount1, cosCount2, 0x1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetVBUSConfig(Uint8 cosCount1, Uint8 cosCount2, Uint8 prOldCount)
{
    hEmif->VBUSM_CONFIG = CSL_FMK (EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_1, cosCount1) |
                          CSL_FMK (EMIF4FV_VBUSM_CONFIG_REG_COS_COUNT_2, cosCount2) |
                          CSL_FMK (EMIF4FV_VBUSM_CONFIG_REG_PR_OLD_COUNT, prOldCount);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetVBUSConfigValues
 *
 *   @b Description
 *   @n The function is used to get the VBUSM Configuration values
 *
 *   @b Arguments
     @verbatim
        ptrVBUSConfigValue      VBUS Configuration populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_VBUSM_CFG_VAL_1_REG_SYS_BUS_WIDTH, EMIF4FV_VBUSM_CFG_VAL_1_REG_STAT_FIFO_DEPTH,
 *      EMIF4FV_VBUSM_CFG_VAL_1_REG_WR_FIFO_DEPTH, EMIF4FV_VBUSM_CFG_VAL_1_REG_CMD_FIFO_DEPTH,
 *   @n EMIF4FV_VBUSM_CFG_VAL_2_REG_RREG_FIFO_DEPTH, EMIF4FV_VBUSM_CFG_VAL_2_REG_RSD_FIFO_DEPTH,
 *      EMIF4FV_VBUSM_CFG_VAL_2_REG_RCMD_FIFO_DEPTH
 *
 *   @b Example
 *   @verbatim
        EMIF4F_VBUS_CONFIG_VALUE     VBUSconfigValue;

        // Get the VBUS Configuration values
        CSL_EMIF4F_GetVBUSConfigValues(&VBUSconfigValue);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetVBUSConfigValues(EMIF4F_VBUS_CONFIG_VALUE* ptrVBUSConfigValue)
{
    Uint32  vbusConfigValue = hEmif->VBUSM_CFG_VAL_1;

    /* Extract all the VBUS Configuration Values */
    ptrVBUSConfigValue->sysBusWidth  = CSL_FEXT(vbusConfigValue, EMIF4FV_VBUSM_CFG_VAL_1_REG_SYS_BUS_WIDTH);
    ptrVBUSConfigValue->statFIFODepth= CSL_FEXT(vbusConfigValue, EMIF4FV_VBUSM_CFG_VAL_1_REG_STAT_FIFO_DEPTH);
    ptrVBUSConfigValue->wrFIFODepth  = CSL_FEXT(vbusConfigValue, EMIF4FV_VBUSM_CFG_VAL_1_REG_WR_FIFO_DEPTH);
    ptrVBUSConfigValue->cmdFIFODepth = CSL_FEXT(vbusConfigValue, EMIF4FV_VBUSM_CFG_VAL_1_REG_CMD_FIFO_DEPTH);

    /* Get the configuration from the second register */
    vbusConfigValue = hEmif->VBUSM_CFG_VAL_2;

    /* Extract all the VBUS Configuration Values */
    ptrVBUSConfigValue->rregFIFODepth = CSL_FEXT(vbusConfigValue, EMIF4FV_VBUSM_CFG_VAL_2_REG_RREG_FIFO_DEPTH);
    ptrVBUSConfigValue->rsdFIFODepth  = CSL_FEXT(vbusConfigValue, EMIF4FV_VBUSM_CFG_VAL_2_REG_RSD_FIFO_DEPTH);
    ptrVBUSConfigValue->rcmdFIFODepth = CSL_FEXT(vbusConfigValue, EMIF4FV_VBUSM_CFG_VAL_2_REG_RCMD_FIFO_DEPTH);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetIODFTControl
 *
 *   @b Description
 *   @n The function is used to get the IODFT Control configuration
 *
 *   @b Arguments
     @verbatim
        ptrIODFTControl      IODFT Control Configuration populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_IODFT_TLGC_REG_TLEC,      EMIF4FV_IODFT_TLGC_REG_MT,
 *      EMIF4FV_IODFT_TLGC_REG_ACT_CAP_EN,EMIF4FV_IODFT_TLGC_REG_OPG_LD,
 *      EMIF4FV_IODFT_TLGC_REG_MMS,       EMIF4FV_IODFT_TLGC_REG_MC,        
 *      EMIF4FV_IODFT_TLGC_REG_PC
 *
 *   @b Example
 *   @verbatim
        EMIF4F_IODFT_CONTROL     IODFTcontrol;

        // Get the IODFT Configuration values
        CSL_EMIF4F_GetIODFTControl(&IODFTcontrol);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetIODFTControl(EMIF4F_IODFT_CONTROL* ptrIODFTControl)
{
    Uint32  iodftControl = hEmif->IODFT_TLGC;

    /* Extract all the IODFT Control Values */
    ptrIODFTControl->tlec    = CSL_FEXT(iodftControl, EMIF4FV_IODFT_TLGC_REG_TLEC);
    ptrIODFTControl->mt      = CSL_FEXT(iodftControl, EMIF4FV_IODFT_TLGC_REG_MT);
    ptrIODFTControl->actCapEn= CSL_FEXT(iodftControl, EMIF4FV_IODFT_TLGC_REG_ACT_CAP_EN);
    ptrIODFTControl->opgld   = CSL_FEXT(iodftControl, EMIF4FV_IODFT_TLGC_REG_OPG_LD);
    ptrIODFTControl->mms     = CSL_FEXT(iodftControl, EMIF4FV_IODFT_TLGC_REG_MMS);
    ptrIODFTControl->mc      = CSL_FEXT(iodftControl, EMIF4FV_IODFT_TLGC_REG_MC);
    ptrIODFTControl->pc      = CSL_FEXT(iodftControl, EMIF4FV_IODFT_TLGC_REG_PC);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetIODFTControl
 *
 *   @b Description
 *   @n The function is used to set the IODFT Control configuration
 *
 *   @b Arguments
     @verbatim
        ptrIODFTControl      IODFT Control Configuration to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_IODFT_TLGC_REG_TLEC,      EMIF4FV_IODFT_TLGC_REG_MT,
 *      EMIF4FV_IODFT_TLGC_REG_ACT_CAP_EN,EMIF4FV_IODFT_TLGC_REG_OPG_LD,
 *      EMIF4FV_IODFT_TLGC_REG_MMS,       EMIF4FV_IODFT_TLGC_REG_MC,        
 *      EMIF4FV_IODFT_TLGC_REG_PC
 *
 *   @b Example
 *   @verbatim
        EMIF4F_IODFT_CONTROL     IODFTcontrol;

        // Get the IODFT Configuration values
        CSL_EMIF4F_GetIODFTControl(&IODFTcontrol);

        // Set the new IODFT configuration 
        CSL_EMIF4F_SetIODFTControl (&IODFTcontrol);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetIODFTControl(EMIF4F_IODFT_CONTROL* ptrIODFTControl)
{
    Uint32  iodftControl = 0;

    /* Initialize all the IODFT Control Values */
    CSL_FINS(iodftControl, EMIF4FV_IODFT_TLGC_REG_TLEC,      ptrIODFTControl->tlec);
    CSL_FINS(iodftControl, EMIF4FV_IODFT_TLGC_REG_MT,        ptrIODFTControl->mt);
    CSL_FINS(iodftControl, EMIF4FV_IODFT_TLGC_REG_ACT_CAP_EN,ptrIODFTControl->actCapEn);
    CSL_FINS(iodftControl, EMIF4FV_IODFT_TLGC_REG_OPG_LD,    ptrIODFTControl->opgld);
    CSL_FINS(iodftControl, EMIF4FV_IODFT_TLGC_REG_MMS,       ptrIODFTControl->mms);
    CSL_FINS(iodftControl, EMIF4FV_IODFT_TLGC_REG_MC,        ptrIODFTControl->mc);
    CSL_FINS(iodftControl, EMIF4FV_IODFT_TLGC_REG_PC,        ptrIODFTControl->pc);

    /* Initialize the register */
    hEmif->IODFT_TLGC = iodftControl;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetIODFTControlResults
 *
 *   @b Description
 *   @n The function is used to get the IODFT Control results.
 *
 *   @b Arguments
     @verbatim
        dqmTLMRResults      DQM TLMR Results populated by this API
        ctlTLMRResults      CTL TLMR Results populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_IODFT_CTRL_MISR_RSLT_REG_DQM_TLMR, EMIF4FV_IODFT_CTRL_MISR_RSLT_REG_CTL_TLMR
 *
 *   @b Example
 *   @verbatim
        Uint16     dqmTLMRResults;
        Uint16     ctlTLMRResults;

        // Get the IODFT Control Results
        CSL_EMIF4F_GetIODFTControlResults(&dqmTLMRResults, &ctlTLMRResults);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetIODFTControlResults(Uint16* dqmTLMRResults, Uint16* ctlTLMRResults)
{
    *dqmTLMRResults = CSL_FEXT (hEmif->IODFT_CTRL_MISR_RSLT, EMIF4FV_IODFT_CTRL_MISR_RSLT_REG_DQM_TLMR);
    *ctlTLMRResults = CSL_FEXT (hEmif->IODFT_CTRL_MISR_RSLT, EMIF4FV_IODFT_CTRL_MISR_RSLT_REG_CTL_TLMR);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetIODFTAddrResults
 *
 *   @b Description
 *   @n The function is used to get the IODFT Address results.
 *
 *   @b Arguments
     @verbatim
        addrTLMRResults      Addr TLMR Results populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_IODFT_ADDR_MISR_RSLT_REG_ADDR_TLMR
 *
 *   @b Example
 *   @verbatim
        Uint32     addrTLMRResults;

        // Get the IODFT Address results
        CSL_EMIF4F_GetIODFTAddrResults(&addrTLMRResults);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetIODFTAddrResults(Uint32* addrTLMRResults)
{
    *addrTLMRResults = CSL_FEXT (hEmif->IODFT_ADDR_MISR_RSLT, EMIF4FV_IODFT_ADDR_MISR_RSLT_REG_ADDR_TLMR);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetIODFTDataResults
 *
 *   @b Description
 *   @n The function is used to get the IODFT Data results.
 *
 *   @b Arguments
     @verbatim
        dataTLMRResults1      Data TLMR1 Results populated by this API
        dataTLMRResults2      Data TLMR2 Results populated by this API
        dataTLMRResults3      Data TLMR3 Results populated by this API
        dataTLMRResults4      Data TLMR4 Results populated by this API
        dataTLMRResults5      Data TLMR5 Results populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_IODFT_DATA_MISR_RSLT_1,EMIF4FV_IODFT_DATA_MISR_RSLT_2,
 *      EMIF4FV_IODFT_DATA_MISR_RSLT_3,EMIF4FV_IODFT_DATA_MISR_RSLT_4,
 *      EMIF4FV_IODFT_DATA_MISR_RSLT_5
 *
 *   @b Example
 *   @verbatim
        Uint32     dataTLMRResults1;
        Uint32     dataTLMRResults2;
        Uint32     dataTLMRResults3;
        Uint32     dataTLMRResults4;
        Uint32     dataTLMRResults5;

        // Get the IODFT Data results
        CSL_EMIF4F_GetIODFTDataResults(&dataTLMRResults1, &dataTLMRResults2, 
                                      &dataTLMRResults3, &dataTLMRResults4, 
                                      &dataTLMRResults5);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetIODFTDataResults
(
    Uint32* dataTLMRResults1,
    Uint32* dataTLMRResults2,
    Uint32* dataTLMRResults3,
    Uint32* dataTLMRResults4,
    Uint32* dataTLMRResults5
)
{
    *dataTLMRResults1 = hEmif->IODFT_DATA_MISR_RSLT_1;
    *dataTLMRResults2 = hEmif->IODFT_DATA_MISR_RSLT_2;
    *dataTLMRResults3 = hEmif->IODFT_DATA_MISR_RSLT_3;
    *dataTLMRResults4 = hEmif->IODFT_DATA_MISR_RSLT_4;
    *dataTLMRResults5 = hEmif->IODFT_DATA_MISR_RSLT_5;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetPerfCounters
 *
 *   @b Description
 *   @n The function is used to get the performance counters
 *
 *   @b Arguments
     @verbatim
        perfCounter1        Performance Counter1 populated by this API
        perfCounter2        Performance Counter2 populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_PERF_CNT_1,EMIF4FV_PERF_CNT_2
 *
 *   @b Example
 *   @verbatim
        Uint32     perfCounter1;
        Uint32     perfCounter2;

        // Get the EMIF4F Performance counters
        CSL_EMIF4F_GetPerfCounters(&perfCounter1, &perfCounter2);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetPerfCounters
(
    Uint32* perfCounter1,
    Uint32* perfCounter2
)
{
    *perfCounter1 = hEmif->PERF_CNT_1;
    *perfCounter2 = hEmif->PERF_CNT_2;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetPerfCounterConfig
 *
 *   @b Description
 *   @n The function is used to get the configuration for performance counters
 *
 *   @b Arguments
     @verbatim
        counter                 Perf Counter for which configuration is required (1 or 2)
        ptrPerfCounterConfig    Performance Counter Configuration populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_PERF_CNT_CFG_REG_CNTR2_MSTID_EN, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_REGION_EN,
 *      EMIF4FV_PERF_CNT_CFG_REG_CNTR2_CFG;
 *      EMIF4FV_PERF_CNT_CFG_REG_CNTR1_MSTID_EN,
 *      EMIF4FV_PERF_CNT_CFG_REG_CNTR1_REGION_EN, EMIF4FV_PERF_CNT_CFG_REG_CNTR1_CFG
 *
 *   @b Example
 *   @verbatim
        EMIF4F_PERF_CONFIG     perfCounterConfig;

        // Get the EMIF4F Performance Counter Configuration for counter 1
        CSL_EMIF4F_GetPerfCounterConfig(1, &perfCounterConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetPerfCounterConfig
(
    Uint8              counter,
    EMIF4F_PERF_CONFIG* ptrPerfCounterConfig
)
{
    Uint32  perfConfig = hEmif->PERF_CNT_CFG;

    if (counter == 2)
    {
        ptrPerfCounterConfig->mstIDEn = CSL_FEXT(perfConfig, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_MSTID_EN);
        ptrPerfCounterConfig->regEn   = CSL_FEXT(perfConfig, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_REGION_EN);
        ptrPerfCounterConfig->cntCfg  = CSL_FEXT(perfConfig, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_CFG);
    } 
    else if (counter == 1)
    {
        ptrPerfCounterConfig->mstIDEn = CSL_FEXT(perfConfig, EMIF4FV_PERF_CNT_CFG_REG_CNTR1_MSTID_EN);
        ptrPerfCounterConfig->regEn   = CSL_FEXT(perfConfig, EMIF4FV_PERF_CNT_CFG_REG_CNTR1_REGION_EN);
        ptrPerfCounterConfig->cntCfg  = CSL_FEXT(perfConfig, EMIF4FV_PERF_CNT_CFG_REG_CNTR1_CFG);
    }
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetPerfCounterConfig
 *
 *   @b Description
 *   @n The function is used to set the configuration for performance counters
 *
 *   @b Arguments
     @verbatim
        counter                 Perf Counter for which configuration is to be set (1 or 2)
        ptrPerfCounterConfig    Performance Counter Configuration to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_PERF_CNT_CFG_REG_CNTR2_MCONNID_EN, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_REGION_EN,
 *      EMIF4FV_PERF_CNT_CFG_REG_CNTR2_CFG;
 *      EMIF4FV_PERF_CNT_CFG_REG_CNTR1_MCONNID_EN,
 *      EMIF4FV_PERF_CNT_CFG_REG_CNTR1_REGION_EN,  EMIF4FV_PERF_CNT_CFG_REG_CNTR1_CFG
 *
 *   @b Example
 *   @verbatim
        EMIF4F_PERF_CONFIG     perfCounterConfig;

        // Get the EMIF4F Performance Counter Configuration for counter 2
        CSL_EMIF4F_GetPerfCounterConfig(2, &perfCounterConfig);

        // Enable Master ID Filter Enable 
        perfCounterConfig.mstIDEn = 1;
        
        // Set the EMIF4F Performance Counter Configuration.
        CSL_EMIF4F_SetPerfCounterConfig(2, &perfCounterConfig);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetPerfCounterConfig
(
    Uint8               counter, 
    EMIF4F_PERF_CONFIG*  ptrPerfCounterConfig
)
{
    /* Configure the performance counter configuration.*/
    if (counter == 1)
    {
        CSL_FINS(hEmif->PERF_CNT_CFG, EMIF4FV_PERF_CNT_CFG_REG_CNTR1_MSTID_EN,  ptrPerfCounterConfig->mstIDEn);
        CSL_FINS(hEmif->PERF_CNT_CFG, EMIF4FV_PERF_CNT_CFG_REG_CNTR1_REGION_EN, ptrPerfCounterConfig->regEn);
        CSL_FINS(hEmif->PERF_CNT_CFG, EMIF4FV_PERF_CNT_CFG_REG_CNTR1_CFG,       ptrPerfCounterConfig->cntCfg);
    }
    else if (counter == 2)
    {
        CSL_FINS(hEmif->PERF_CNT_CFG, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_MSTID_EN,  ptrPerfCounterConfig->mstIDEn);
        CSL_FINS(hEmif->PERF_CNT_CFG, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_REGION_EN, ptrPerfCounterConfig->regEn);
        CSL_FINS(hEmif->PERF_CNT_CFG, EMIF4FV_PERF_CNT_CFG_REG_CNTR2_CFG,       ptrPerfCounterConfig->cntCfg);
    }
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetPerfCounterMasterRegion
 *
 *   @b Description
 *   @n The function is used to get the master region selection for the specific
 *      performance counters
 *
 *   @b Arguments
     @verbatim
        counter          Perf Counter for which master region selection is configured
        mstID            Master ID selection for the specified performance counter
        regionSel        Region Selection for the specified performance counter
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_PERF_CNT_SEL_REG_MCONNID1, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL1;
 *      EMIF4FV_PERF_CNT_SEL_REG_MCONNID2, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL2
 *
 *   @b Example
 *   @verbatim
        Uint8   mstID;
        Uint8   regionSel;

        // Get the Master Region Selection for Counter 1
        CSL_EMIF4F_GetPerfCounterMasterRegion (1, &mstID, &regionSel);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetPerfCounterMasterRegion
(
    Uint8   counter,
    Uint8*  mstID,
    Uint8*  regionSel
)
{
    if (counter == 1)
    {
        *mstID     = CSL_FEXT (hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_MSTID1);
        *regionSel = CSL_FEXT (hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL1);
    }
    else if (counter == 2)
    {
        *mstID     = CSL_FEXT (hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_MSTID2);
        *regionSel = CSL_FEXT (hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL2);
    }
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetPerfCounterMasterRegion
 *
 *   @b Description
 *   @n The function is used to set the master region selection for the specific
 *      performance counters
 *
 *   @b Arguments
     @verbatim
        counter          Perf Counter for which master region selection is configured
        mstID            Master ID selection for the specified performance counter
        regionSel        Region Selection for the specified performance counter
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n EMIF4FV_PERF_CNT_SEL_REG_MCONNID1, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL1;
 *      EMIF4FV_PERF_CNT_SEL_REG_MCONNID2, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL2
 *
 *   @b Example
 *   @verbatim
        Uint8   mstID;
        Uint8   regionSel;

        // Get the Master Region Selection for Counter 1
        CSL_EMIF4F_GetPerfCounterMasterRegion (1, &mstID, &regionSel);

        // Change Master ID to be 5
        CSL_EMIF4F_SetPerfCounterMasterRegion(1, 5, regionSel);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetPerfCounterMasterRegion
(
    Uint8   counter,
    Uint8   mstID,
    Uint8   regionSel
)
{
    if (counter == 1)
    {
        CSL_FINS(hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_MSTID1,      mstID);
        CSL_FINS(hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL1, regionSel);
    }
    else if (counter == 2)
    {
        CSL_FINS(hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_MSTID2,      mstID);
        CSL_FINS(hEmif->PERF_CNT_SEL, EMIF4FV_PERF_CNT_SEL_REG_REGION_SEL2, regionSel);
    }
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetPerfCounterTime
 *
 *   @b Description
 *   @n The function is used to get the performance counter timer register
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Performance counter Time Register
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_PERF_CNT_TIM
 *
 *   @b Example
 *   @verbatim
        Uint32  perfCount;

        // Get the Performance Counter Time Register
        perfCount = CSL_EMIF4F_GetPerfCounterTime ();
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_EMIF4F_GetPerfCounterTime(void)
{
    return hEmif->PERF_CNT_TIM;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetInterruptRawStatus
 *
 *   @b Description
 *   @n The function is used to get the interrupt RAW status 
 *
 *   @b Arguments
     @verbatim
        rawStatus       Raw Interrupt Status populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *     EMIF4FV_IRQSTATUS_RAW_SYS
 *
 *   @b Example
 *   @verbatim
        Uint8   rawStatus;

        // Get the Interrupt RAW Status
        CSL_EMIF4F_GetInterruptRawStatus (&rawStatus);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetInterruptRawStatus(Uint8* rawStatus)
{
    *rawStatus = hEmif->IRQSTATUS_RAW_SYS;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetInterruptRawStatus
 *
 *   @b Description
 *   @n The function is used to set the interrupt RAW status 
 *
 *   @b Arguments
     @verbatim
        rawStatus       Raw Interrupt Status to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *     EMIF4FV_IRQSTATUS_RAW_SYS
 *
 *   @b Example
 *   @verbatim
        
        // Set the Interrupt RAW Status for LPDDR2 NVM data not valid
        CSL_EMIF4F_SetInterruptRawStatus (0x4);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetInterruptRawStatus(Uint8 rawStatus)
{
    hEmif->IRQSTATUS_RAW_SYS = rawStatus;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetInterruptStatus
 *
 *   @b Description
 *   @n The function is used to get the interrupt status 
 *
 *   @b Arguments
     @verbatim
        intrStatus       Interrupt Status populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *     EMIF4FV_IRQSTATUS_SYS
 *
 *   @b Example
 *   @verbatim
        Uint8   intrStatus;

        // Get the Interrupt Status
        CSL_EMIF4F_GetInterruptStatus (&intrStatus);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetInterruptStatus(Uint8* intrStatus)
{
    *intrStatus = hEmif->IRQSTATUS_SYS;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_ClearInterruptStatus
 *
 *   @b Description
 *   @n The function is used to clear the interrupt status 
 *
 *   @b Arguments
     @verbatim
        intrStatus       Interrupt Status populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *     EMIF4FV_IRQSTATUS_SYS
 *
 *   @b Example
 *   @verbatim
        Uint8   intrStatus;

        // Get the Interrupt Status
        CSL_EMIF4F_GetInterruptRawStatus (&intrStatus);
        ...
        // Process the interrupts
        ...
        // Clear the Interrupts
        CSL_EMIF4F_ClearInterruptStatus (intrStatus);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_ClearInterruptStatus(Uint8 intrStatus)
{
    hEmif->IRQSTATUS_SYS = intrStatus;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_EnableInterrupts
 *
 *   @b Description
 *   @n The function is used to enable interrupts
 *
 *   @b Arguments
     @verbatim
        intrFlag       Interrupt flag for interrupts to be enabled
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *     EMIF4FV_IRQENABLE_SET_SYS
 *
 *   @b Example
 *   @verbatim

        // Enable address error interrupt 
        CSL_EMIF4F_EnableInterrupts (0x1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_EnableInterrupts(Uint8 intrStatus)
{
    hEmif->IRQENABLE_SET_SYS = intrStatus;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_DisableInterrupts
 *
 *   @b Description
 *   @n The function is used to disable interrupts
 *
 *   @b Arguments
     @verbatim
        intrFlag       Interrupt flag for interrupts to be disabled
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *     EMIF4FV_IRQENABLE_CLR_SYS
 *
 *   @b Example
 *   @verbatim

        // Disable address error interrupt 
        CSL_EMIF4F_DisableInterrupts (0x1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_DisableInterrupts(Uint8 intrStatus)
{
    hEmif->IRQENABLE_CLR_SYS = intrStatus;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetOutputImpedanceConfig
 *
 *   @b Description
 *   @n The function is used to get the Output Impedance Calibrartion configuration
 *
 *   @b Arguments
     @verbatim
        ptrOutputImpedanceConfig    Output Impedance Calibrartion configuration 
                                    populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *     EMIF4FV_ZQ_CONFIG_REG_ZQ_CS1EN,      EMIF4FV_ZQ_CONFIG_REG_ZQ_CS0EN, 
 *     EMIF4FV_ZQ_CONFIG_REG_ZQ_DUALCALEN,  EMIF4FV_ZQ_CONFIG_REG_ZQ_SFEXITEN,
 *     EMIF4FV_ZQ_CONFIG_REG_ZQ_ZQCL_MULT,  EMIF4FV_ZQ_CONFIG_REG_ZQ_REFINTERVAL
 *
 *   @b Example
 *   @verbatim
        EMIF4F_OUTPUT_IMP_CONFIG outputImpConfig; 

        // Get the output impedance configuration
        CSL_EMIF4F_GetOutputImpedanceConfig (&outputImpConfig);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetOutputImpedanceConfig(EMIF4F_OUTPUT_IMP_CONFIG* ptrOutputImpedanceConfig)
{
    Uint32 zqConfig = hEmif->ZQ_CONFIG;

    /* Extract all the fields and populate the structure */
    ptrOutputImpedanceConfig->zqCS1En       = CSL_FEXT (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_CS1EN);
    ptrOutputImpedanceConfig->zqCS0En       = CSL_FEXT (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_CS0EN);
    ptrOutputImpedanceConfig->zqDualCSEn    = CSL_FEXT (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_DUALCALEN);
    ptrOutputImpedanceConfig->zqSFEXITEn    = CSL_FEXT (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_SFEXITEN);
    ptrOutputImpedanceConfig->zqZQCLMult    = CSL_FEXT (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_ZQCL_MULT);
    ptrOutputImpedanceConfig->zqRefInterval = CSL_FEXT (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_REFINTERVAL);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetOutputImpedanceConfig
 *
 *   @b Description
 *   @n The function is used to set the Output Impedance Calibrartion configuration
 *
 *   @b Arguments
     @verbatim
        ptrOutputImpedanceConfig    Output Impedance Calibrartion configuration to be
                                    configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *     EMIF4FV_ZQ_CONFIG_REG_ZQ_CS1EN,      EMIF4FV_ZQ_CONFIG_REG_ZQ_CS0EN, 
 *     EMIF4FV_ZQ_CONFIG_REG_ZQ_DUALCALEN,  EMIF4FV_ZQ_CONFIG_REG_ZQ_SFEXITEN,
 *     EMIF4FV_ZQ_CONFIG_REG_ZQ_ZQCL_MULT,  EMIF4FV_ZQ_CONFIG_REG_ZQ_REFINTERVAL
 *
 *   @b Example
 *   @verbatim
        EMIF4F_OUTPUT_IMP_CONFIG outputImpConfig; 

        // Get the output impedance configuration
        CSL_EMIF4F_GetOutputImpedanceConfig (&outputImpConfig);

        // Enable ZQ Calibration for CS1
        outputImpConfig.zqCS1En = 1;

        // Set the new output impedance configuration.
        CSL_EMIF4F_SetOutputImpedanceConfig(&outputImpConfig);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetOutputImpedanceConfig(EMIF4F_OUTPUT_IMP_CONFIG* ptrOutputImpedanceConfig)
{
    Uint32 zqConfig = 0;

    /* Initialize the fields */
    CSL_FINS (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_CS1EN, ptrOutputImpedanceConfig->zqCS1En);
    CSL_FINS (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_CS0EN, ptrOutputImpedanceConfig->zqCS0En);
    CSL_FINS (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_DUALCALEN, ptrOutputImpedanceConfig->zqDualCSEn);
    CSL_FINS (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_SFEXITEN, ptrOutputImpedanceConfig->zqSFEXITEn);
    CSL_FINS (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_ZQCL_MULT, ptrOutputImpedanceConfig->zqZQCLMult);
    CSL_FINS (zqConfig, EMIF4FV_ZQ_CONFIG_REG_ZQ_REFINTERVAL, ptrOutputImpedanceConfig->zqRefInterval);

    /* Initialize the register */
    hEmif->ZQ_CONFIG = zqConfig;
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetErrorLog
 *
 *   @b Description
 *   @n The function is used to get the error log
 *
 *   @b Arguments
     @verbatim
        errCRSel    CRSel for the first errored transaction populated by this API
        errAddMode  Addressing Mode populated by this API
        errCmdType  Command Type of the first errored transaction populated by this API
        errMstID    Master ID of the first errored transaction populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *     EMIF4FV_VBUSM_ERR_LOG_REG_CRSEL,EMIF4FV_VBUSM_ERR_LOG_REG_CAMODE, 
 *     EMIF4FV_VBUSM_ERR_LOG_REG_CDIR, EMIF4FV_VBUSM_ERR_LOG_REG_CMSTID
 *
 *   @b Example
 *   @verbatim
        Uint8  errCRSel;
        Uint8  errAddMode;
        Uint8  errCmdType;
        Uint8  errMstID;

        // Get the Error Log 
        CSL_EMIF4F_GetErrorLog (&errCRSel, &errAddMode, &errCmdType, &errMstID);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetErrorLog
(
    Uint8*  errCRSel,
    Uint8*  errAddMode,
    Uint8*  errCmdType,
    Uint8*  errMstID
)
{
    Uint32 errLog = hEmif->VBUSM_ERR_LOG;

    /* Extract all the fields from the error log register */
    *errCRSel   = CSL_FEXT (errLog, EMIF4FV_VBUSM_ERR_LOG_REG_CRSEL);
    *errAddMode = CSL_FEXT (errLog, EMIF4FV_VBUSM_ERR_LOG_REG_CAMODE);
    *errCmdType = CSL_FEXT (errLog, EMIF4FV_VBUSM_ERR_LOG_REG_CDIR);
    *errMstID   = CSL_FEXT (errLog, EMIF4FV_VBUSM_ERR_LOG_REG_CMSTID);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetPriorityToCOSMapping
 *
 *   @b Description
 *   @n The function is used to get the priority to class of service mapping.
 *
 *   @b Arguments
     @verbatim
        ptrPriCosMapper       Priority to COS Mapping configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_COS_MAP_EN, EMIF4FV_PRI_COS_MAP_REG_PRI_7_COS,
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_5_COS, EMIF4FV_PRI_COS_MAP_REG_PRI_4_COS,
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_3_COS, EMIF4FV_PRI_COS_MAP_REG_PRI_2_COS,
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_1_COS, EMIF4FV_PRI_COS_MAP_REG_PRI_0_COS     
 *
 *   @b Example
 *   @verbatim
        EMIF4_PRI_COS_MAPPING priCosMapper;

        // Get the Priority to COS Mapper information
        CSL_EMIF4F_GetPriorityToCOSMapping (&priCosMapper);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetPriorityToCOSMapping(EMIF4_PRI_COS_MAPPING* ptrPriCosMapper)
{
    Uint32 value = hEmif->PRI_COS_MAP;

    ptrPriCosMapper->enable  = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_COS_MAP_EN);
    ptrPriCosMapper->pri7cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_7_COS);
    ptrPriCosMapper->pri6cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_6_COS);
    ptrPriCosMapper->pri5cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_5_COS);
    ptrPriCosMapper->pri4cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_4_COS);
    ptrPriCosMapper->pri3cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_3_COS);
    ptrPriCosMapper->pri2cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_2_COS);
    ptrPriCosMapper->pri1cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_1_COS);
    ptrPriCosMapper->pri0cos = CSL_FEXT (value, EMIF4FV_PRI_COS_MAP_REG_PRI_0_COS);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetPriorityToCOSMapping
 *
 *   @b Description
 *   @n The function is used to set the priority to class of service mapping.
 *
 *   @b Arguments
     @verbatim
        ptrPriCosMapper       Priority to COS Mapping configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_COS_MAP_EN, EMIF4FV_PRI_COS_MAP_REG_PRI_7_COS,
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_5_COS, EMIF4FV_PRI_COS_MAP_REG_PRI_4_COS,
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_3_COS, EMIF4FV_PRI_COS_MAP_REG_PRI_2_COS,
 *      EMIF4FV_PRI_COS_MAP_REG_PRI_1_COS, EMIF4FV_PRI_COS_MAP_REG_PRI_0_COS     
 *
 *   @b Example
 *   @verbatim
        EMIF4_PRI_COS_MAPPING priCosMapper;

        // Get the Priority to COS Mapper information
        CSL_EMIF4F_GetPriorityToCOSMapping (&priCosMapper);
        ...
        // Configure the mapper to allow priority to COS mapping 
        priCosMapper.enable = 1;
        CSL_EMIF4F_SetPriorityToCOSMapping (&priCosMapper);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetPriorityToCOSMapping(EMIF4_PRI_COS_MAPPING* ptrPriCosMapper)
{
    hEmif->PRI_COS_MAP = 
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_COS_MAP_EN, ptrPriCosMapper->enable)  |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_7_COS, ptrPriCosMapper->pri7cos)      |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_6_COS, ptrPriCosMapper->pri6cos)      |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_5_COS, ptrPriCosMapper->pri5cos)      |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_4_COS, ptrPriCosMapper->pri4cos)      |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_3_COS, ptrPriCosMapper->pri3cos)      |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_2_COS, ptrPriCosMapper->pri2cos)      |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_1_COS, ptrPriCosMapper->pri1cos)      |
        CSL_FMK (EMIF4FV_PRI_COS_MAP_REG_PRI_0_COS, ptrPriCosMapper->pri0cos);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetMstIDToCos1Mapping
 *
 *   @b Description
 *   @n The function is used to get the master id to Class of Service 1 mapping
 *
 *   @b Arguments
     @verbatim
        ptrMstIDCosMapper       Master ID to COS Mapping configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_COS_1_MAP_EN, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_1_COS_1,
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSK_1_COS_1, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_2_COS_1,
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSK_2_COS_1, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_3_COS_1,
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSK_3_COS_1
 *
 *   @b Example
 *   @verbatim
        EMIF4_MSTID_COS_MAPPING mstIDCosMapper;

        // Get the Master ID to COS1 Mapper information
        CSL_EMIF4F_GetMstIDToCos1Mapping (&mstIDCosMapper);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetMstIDToCos1Mapping(EMIF4_MSTID_COS_MAPPING* ptrMstIDCosMapper)
{
    Uint32 value = hEmif->MSTID_COS_1_MAP;

    ptrMstIDCosMapper->enable   = CSL_FEXT (value, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_COS_1_MAP_EN);
    ptrMstIDCosMapper->mst1     = CSL_FEXT (value, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_1_COS_1);
    ptrMstIDCosMapper->mstMask1 = CSL_FEXT (value, EMIF4FV_MSTID_COS_1_MAP_REG_MSK_1_COS_1);
    ptrMstIDCosMapper->mst2     = CSL_FEXT (value, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_2_COS_1);
    ptrMstIDCosMapper->mstMask2 = CSL_FEXT (value, EMIF4FV_MSTID_COS_1_MAP_REG_MSK_2_COS_1);
    ptrMstIDCosMapper->mst3     = CSL_FEXT (value, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_3_COS_1);
    ptrMstIDCosMapper->mstMask3 = CSL_FEXT (value, EMIF4FV_MSTID_COS_1_MAP_REG_MSK_3_COS_1);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetMstIDToCos1Mapping
 *
 *   @b Description
 *   @n The function is used to set the master id to Class of Service 1 mapping
 *
 *   @b Arguments
     @verbatim
        ptrMstIDCosMapper       Master ID to COS Mapping configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_COS_1_MAP_EN, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_1_COS_1,
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSK_1_COS_1, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_2_COS_1,
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSK_2_COS_1, EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_3_COS_1,
 *      EMIF4FV_MSTID_COS_1_MAP_REG_MSK_3_COS_1
 *
 *   @b Example
 *   @verbatim
        EMIF4_MSTID_COS_MAPPING mstIDCosMapper;

        // Get the Master ID to COS1 Mapper information
        CSL_EMIF4F_GetMstIDToCos1Mapping (&mstIDCosMapper);
        ...
        // Enable the Master ID to COS1 Mapping
        mstIDCosMapper.enable = 1;
        CSL_EMIF4F_SetMstIDToCos1Mapping (&mstIDCosMapper);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetMstIDToCos1Mapping(EMIF4_MSTID_COS_MAPPING* ptrMstIDCosMapper)
{
    hEmif->MSTID_COS_1_MAP = 
            CSL_FMK (EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_COS_1_MAP_EN, ptrMstIDCosMapper->enable)  |
            CSL_FMK (EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_1_COS_1,      ptrMstIDCosMapper->mst1)    |
            CSL_FMK (EMIF4FV_MSTID_COS_1_MAP_REG_MSK_1_COS_1,        ptrMstIDCosMapper->mstMask1)|
            CSL_FMK (EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_2_COS_1,      ptrMstIDCosMapper->mst2)    |
            CSL_FMK (EMIF4FV_MSTID_COS_1_MAP_REG_MSK_2_COS_1,        ptrMstIDCosMapper->mstMask2)|
            CSL_FMK (EMIF4FV_MSTID_COS_1_MAP_REG_MSTID_3_COS_1,      ptrMstIDCosMapper->mst3)    |
            CSL_FMK (EMIF4FV_MSTID_COS_1_MAP_REG_MSK_3_COS_1,        ptrMstIDCosMapper->mstMask3);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetMstIDToCos2Mapping
 *
 *   @b Description
 *   @n The function is used to get the master id to Class of Service 2 mapping
 *
 *   @b Arguments
     @verbatim
        ptrMstIDCosMapper       Master ID to COS Mapping configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_COS_2_MAP_EN, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_1_COS_2,
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSK_1_COS_2, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_2_COS_2,
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSK_2_COS_2, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_3_COS_2,
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSK_3_COS_2
 *
 *   @b Example
 *   @verbatim
        EMIF4_MSTID_COS_MAPPING mstIDCosMapper;

        // Get the Master ID to COS2 Mapper information
        CSL_EMIF4F_GetMstIDToCos2Mapping (&mstIDCosMapper);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetMstIDToCos2Mapping(EMIF4_MSTID_COS_MAPPING* ptrMstIDCosMapper)
{
    Uint32 value = hEmif->MSTID_COS_2_MAP;

    ptrMstIDCosMapper->enable   = CSL_FEXT (value, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_COS_2_MAP_EN);
    ptrMstIDCosMapper->mst1     = CSL_FEXT (value, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_1_COS_2);
    ptrMstIDCosMapper->mstMask1 = CSL_FEXT (value, EMIF4FV_MSTID_COS_2_MAP_REG_MSK_1_COS_2);
    ptrMstIDCosMapper->mst2     = CSL_FEXT (value, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_2_COS_2);
    ptrMstIDCosMapper->mstMask2 = CSL_FEXT (value, EMIF4FV_MSTID_COS_2_MAP_REG_MSK_2_COS_2);
    ptrMstIDCosMapper->mst3     = CSL_FEXT (value, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_3_COS_2);
    ptrMstIDCosMapper->mstMask3 = CSL_FEXT (value, EMIF4FV_MSTID_COS_2_MAP_REG_MSK_3_COS_2);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetMstIDToCos2Mapping
 *
 *   @b Description
 *   @n The function is used to set the master id to Class of Service 2 mapping
 *
 *   @b Arguments
     @verbatim
        ptrMstIDCosMapper       Master ID to COS Mapping configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_COS_2_MAP_EN, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_1_COS_2,
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSK_1_COS_2, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_2_COS_2,
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSK_2_COS_2, EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_3_COS_2,
 *      EMIF4FV_MSTID_COS_2_MAP_REG_MSK_3_COS_2
 *
 *   @b Example
 *   @verbatim
        EMIF4_MSTID_COS_MAPPING mstIDCosMapper;

        // Get the Master ID to COS2 Mapper information
        CSL_EMIF4F_GetMstIDToCos2Mapping (&mstIDCosMapper);
        ...
        // Enable the Master ID to COS2 Mapping
        mstIDCosMapper.enable = 1;
        CSL_EMIF4F_SetMstIDToCos2Mapping (&mstIDCosMapper);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetMstIDToCos2Mapping(EMIF4_MSTID_COS_MAPPING* ptrMstIDCosMapper)
{
    hEmif->MSTID_COS_2_MAP = 
            CSL_FMK (EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_COS_2_MAP_EN, ptrMstIDCosMapper->enable)  |
            CSL_FMK (EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_1_COS_2,      ptrMstIDCosMapper->mst1)    |
            CSL_FMK (EMIF4FV_MSTID_COS_2_MAP_REG_MSK_1_COS_2,        ptrMstIDCosMapper->mstMask1)|
            CSL_FMK (EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_2_COS_2,      ptrMstIDCosMapper->mst2)    |
            CSL_FMK (EMIF4FV_MSTID_COS_2_MAP_REG_MSK_2_COS_2,        ptrMstIDCosMapper->mstMask2)|
            CSL_FMK (EMIF4FV_MSTID_COS_2_MAP_REG_MSTID_3_COS_2,      ptrMstIDCosMapper->mst3)    |
            CSL_FMK (EMIF4FV_MSTID_COS_2_MAP_REG_MSK_3_COS_2,        ptrMstIDCosMapper->mstMask3);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetECCControl
 *
 *   @b Description
 *   @n The function is used to get the ECC Control Information
 *
 *   @b Arguments
     @verbatim
        ptrECCControl       ECC Control Configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *      EMIF4FV_ECC_CTRL_REG_ECC_EN, EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_PROT,
 *      EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_2_EN, EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_1_EN
 *
 *   @b Example
 *   @verbatim
        EMIF4_ECC_CONTROL eccControl;

        // Get the ECC Control Configuration
        CSL_EMIF4F_GetECCControl (&eccControl);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetECCControl(EMIF4_ECC_CONTROL* ptrECCControl)
{
    Uint32 value = hEmif->ECC_CTRL;

    ptrECCControl->enable       = CSL_FEXT (value, EMIF4FV_ECC_CTRL_REG_ECC_EN);
    ptrECCControl->addrRngProt  = CSL_FEXT (value, EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_PROT);
    ptrECCControl->addrRng2En   = CSL_FEXT (value, EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_2_EN);
    ptrECCControl->addrRng1En   = CSL_FEXT (value, EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_1_EN);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetECCControl
 *
 *   @b Description
 *   @n The function is used to set the ECC Control Information
 *
 *   @b Arguments
     @verbatim
        ptrECCControl       ECC Control Configuration
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *      EMIF4FV_ECC_CTRL_REG_ECC_EN, EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_PROT,
 *      EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_2_EN, EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_1_EN
 *
 *   @b Example
 *   @verbatim
        EMIF4_ECC_CONTROL eccControl;

        // Get the ECC Control Configuration
        CSL_EMIF4F_GetECCControl (&eccControl);
        ..
        // Enable ECC 
        eccControl.enable = 1;
        CSL_EMIF4F_SetECCControl (&eccControl);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetECCControl(EMIF4_ECC_CONTROL* ptrECCControl)
{
    hEmif->ECC_CTRL = 
        CSL_FMK (EMIF4FV_ECC_CTRL_REG_ECC_EN,            ptrECCControl->enable)      |
        CSL_FMK (EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_PROT, ptrECCControl->addrRngProt) |
        CSL_FMK (EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_2_EN, ptrECCControl->addrRng2En)  |
        CSL_FMK (EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_1_EN, ptrECCControl->addrRng1En);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetECCAddressRange
 *
 *   @b Description
 *   @n The function is used to get the ECC Address Range
 *
 *   @b Arguments
     @verbatim
        range           Address Range for which start and end address are required
        endAddr         End Address
        startAddr       Start Address
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *      EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_END_ADDR_1, EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_STRT_ADDR_1;
 *      EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_END_ADDR_2, EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_STRT_ADDR_2
 *
 *   @b Example
 *   @verbatim
        Uint16  endAddr;
        Uint16  startAddr;

        // Get the ECC Address Range1
        CSL_EMIF4F_GetECCAddressRange (1, &endAddr, &startAddr);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetECCAddressRange(Uint8 range, Uint16* endAddr, Uint16* startAddr)
{
    Uint32 value;

    if (range == 1)
    {
        value = hEmif->ECC_ADDR_RNG_1;
        *endAddr    = CSL_FEXT(value, EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_END_ADDR_1);
        *startAddr  = CSL_FEXT(value, EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_STRT_ADDR_1);
    }
    else if (range == 2)
    {
        value = hEmif->ECC_ADDR_RNG_2;
        *endAddr    = CSL_FEXT(value, EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_END_ADDR_2);
        *startAddr  = CSL_FEXT(value, EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_STRT_ADDR_2);
    }
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetECCAddressRange
 *
 *   @b Description
 *   @n The function is used to set the ECC Address Range
 *
 *   @b Arguments
     @verbatim
        range           Address Range for which start and end address are required
        endAddr         End Address
        startAddr       Start Address
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *      EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_END_ADDR_1, EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_STRT_ADDR_1;
 *      EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_END_ADDR_2, EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_STRT_ADDR_2
 *
 *   @b Example
 *   @verbatim
        Uint16  endAddr;
        Uint16  startAddr;

        // Set the ECC Address Range1
        CSL_EMIF4F_SetECCAddressRange (1, 0x100, 0x0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetECCAddressRange(Uint8 range, Uint16 endAddr, Uint16 startAddr)
{
    if (range == 1)
    {
        hEmif->ECC_ADDR_RNG_1 = 
            CSL_FMK (EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_END_ADDR_1,  endAddr) |
            CSL_FMK (EMIF4FV_ECC_ADDR_RNG_1_REG_ECC_STRT_ADDR_1, startAddr);
    }
    else if (range == 2)
    {
        hEmif->ECC_ADDR_RNG_2 = 
            CSL_FMK (EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_END_ADDR_2,  endAddr) |
            CSL_FMK (EMIF4FV_ECC_ADDR_RNG_2_REG_ECC_STRT_ADDR_2, startAddr);
    }
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_GetReadWriteThreshold
 *
 *   @b Description
 *   @n The function is used to get the Read, Write Execution Thresholds
 *
 *   @b Arguments
     @verbatim
        wrThreshold       Write Threshold
        rdThreshold       Read  Threshold
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *      EMIF4FV_RD_WR_EXEC_THRSH_REG_WR_THRSH, EMIF4FV_RD_WR_EXEC_THRSH_REG_RD_THRSH
 *
 *   @b Example
 *   @verbatim
        Uint8   wrThreshold;
        Uint8   rdThreshold;

        // Get the Read, Write Execution Thresholds.
        CSL_EMIF4F_GetReadWriteThreshold (&wrThreshold, &rdThreshold);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_GetReadWriteThreshold(Uint8* wrThreshold, Uint8* rdThreshold)
{
    Uint32 value = hEmif->RD_WR_EXEC_THRSH;

    *wrThreshold = CSL_FEXT (value, EMIF4FV_RD_WR_EXEC_THRSH_REG_WR_THRSH);
    *rdThreshold = CSL_FEXT (value, EMIF4FV_RD_WR_EXEC_THRSH_REG_RD_THRSH);
}

/** ============================================================================
 *   @n@b CSL_EMIF4F_SetReadWriteThreshold
 *
 *   @b Description
 *   @n The function is used to set the Read, Write Execution Thresholds
 *
 *   @b Arguments
     @verbatim
        wrThreshold       Write Threshold
        rdThreshold       Read  Threshold
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *      EMIF4FV_RD_WR_EXEC_THRSH_REG_WR_THRSH, EMIF4FV_RD_WR_EXEC_THRSH_REG_RD_THRSH
 *
 *   @b Example
 *   @verbatim

        // Get the Read, Write Execution Thresholds.
        CSL_EMIF4F_SetReadWriteThreshold (1, 2);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_EMIF4F_SetReadWriteThreshold(Uint8 wrThreshold, Uint8 rdThreshold)
{
    hEmif->RD_WR_EXEC_THRSH = 
        CSL_FMK (EMIF4FV_RD_WR_EXEC_THRSH_REG_WR_THRSH, wrThreshold) |
        CSL_FMK (EMIF4FV_RD_WR_EXEC_THRSH_REG_RD_THRSH, rdThreshold);
}




/* @} */

#ifdef __cplusplus
}
#endif

#endif /* CSL_EMIF4FAUX_V0_H_ */
