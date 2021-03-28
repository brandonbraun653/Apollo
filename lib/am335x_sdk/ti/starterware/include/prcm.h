/**
 *  \file  prcm.h
 *
 *  \brief This file contains the PRCM APIs prototype.
 *
 *  These APIs rely on the PRCM database which encompasses the relation between 
 *  clock, module and different domains (Clock domain, power domain and voltage 
 *  domain). Following are the typical operations performed StarterWare,
 *    1. Clock- enable, disable & check state
 *    2. Module- enable, disable & check state
 *    3. Parent clock- select of from the multiple possible parent clocks
 *    4. Divider - configure the clock dividers
 *    5. Clock rate - get the input functional clock rate of a module. This can be
 *       used by the device driver API's to get the input clock and configure the
 *       internal multipliers/dividers accordingly. Clock manipulations inside the
 *       module are not modelled here, and left to the individual module drivers to
 *       handle this.
 *    6. PLL configuration- Multiplier, dividers and bypass configuration.
 *    7. DVFS- Not integrated. It is expected that the DVFS will be a separate 
 *           framework which can use Clock API's for configuring the clock.
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef PRCM_H_
#define PRCM_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "chipdb.h"
#if defined(AM43XX_FAMILY_BUILD)
    #include "hw_prcm.h"
    #include "hw_prcm_data.h"
#endif /* AM43XX_FAMILY_BUILD */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief Resource information which uniquely defines a resource based on 
 *        module id and instance number.
 */
typedef struct 
{
    chipdbModuleID_t moduleId;
    /**< Module id which identifies the peripheral. Refer #chipdbModuleID_t */
    uint32_t instNum;
    /**< Instance number of the module */
}prcmModuleInfo_t;

/* ========================================================================== */
/*                      Global Variables Declarations                         */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/**
 * \brief This API enables the module. It also ensures the corresponding 
 *        power domain, clock domain are enabled before enabling the module. 
 *        This API shall be called before accessing any memory mapped register
 *        (MMR) of a module. The interface and functional clocks will be enabled 
 *        and the optional clocks will not be enabled by this API. A separate 
 *        call to the API PRCMOptClockEnable() has to be made to enable the 
 *        optional clock as per the use case requirement.
 *
 * Note1: This API enables only one module. At system level multiple modules 
 *        may need to be enabled. Since the order of enabling is specific to 
 *        application,synchronizing enabling of multiple modules shall be 
 *        handled by the application.
 * Note2: Also the multiplexer and divider in the clock path will not be 
 *        configured by this API. Separate API's have to be called to configure 
 *        them.
 *
 * \param moduleId       Unique ID of the module to be enabled
 *                           #chipdbModuleID_t
 * \param instNum        Instance number of the module
 * \param isBlockingCall Flag indicating whether this call should wait till the 
 *                       module is enabled (TRUE) or return simply after 
 *                       configuring the control register (FALSE). In case of 
 *                       non-blocking the caller should ensure the module is 
 *                       enabled before accessing the MMR's (by calling the API 
 *                       PRCMIsModuleEnabled())
 *
 * \retval S_PASS          indicates the operation is success
 * \retval E_FAIL          indicates the module is not enabled (time-out)
 * \retval E_INVALID_PARAM invalid module id
 **/
int32_t PRCMModuleEnable(chipdbModuleID_t moduleId, 
                         uint32_t instNum, 
                         uint32_t isBlockingCall);

/**
 * \brief This API enables list of modules passed - calls PRCMModuleEnable() 
 *        to enable all the modules (indicated in parameter).
 *
 * Note: The order of enabling is specific to the application so synchronizing
 *       enabling of multiple modules and the order shall be handled by the 
 *       application. Any incompatibility between modules are not checked and 
 *       the later configuration will be effective.
 *
 * \param moduleEnableList List of modules (specific instance) to be enabled.
 * \param numModules Number of modules.
 *
 * \retval S_PASS          indicates the operation is success
 * \retval E_FAIL          indicates the module is not enabled (time-out)
 * \retval E_INVALID_PARAM invalid module id
 **/                                                    
int32_t PRCMMultiModuleEnable(prcmModuleInfo_t *moduleEnableList, 
                              uint32_t numModules);
 
/**
 * \brief This API disables the module. It also disables the corresponding 
 *        optional clocks.
 *
 * \param moduleId       Unique ID of the module to be disabled
 *                           #chipdbModuleID_t 
 * \param instNum        Instance number of the module 
 * \param isBlockingCall Flag indicating whether this call should wait till the 
 *                       module is disabled (TRUE) or return simply after  
 *                       configuring the control register (FLASE). In case of 
 *                       non-blocking call the caller should ensure the module
 *                       is disabled before entering low power modes.
 *
 * Note1: This API disables only one module. At system level multiple modules 
 *       may need to be disabled. Since the order of disabling is specific to 
 *       application, synchronizing disabling of multiple modules shall be 
 *       handled by the application.
 *
 * Note2: This is a blocking call and will wait till all the modules are 
 *        enabled.
 *
 * \retval S_PASS          indicates the operation is success
 * \retval E_FAIL          indicates the module is not disabled (time-out)
 * \retval E_INVALID_PARAM invalid module id
 *
 **/
int32_t PRCMModuleDisable(chipdbModuleID_t moduleId, 
                          uint32_t instNum, 
                          uint32_t isBlockingCall);

/**
 * \brief This API disables list of modules passed - it calls 
 *        PRCMModuleDisable() to disable all the modules (specified in 
 *        parameter).
 *
 * Note1: The order of disabling is specific to the application so synchronizing
 *       disabling of multiple modules and the order shall be handled by the 
 *       application.
 *
 * Note2: This is a blocking call and will wait till all the modules are 
 *        disabled.
 *
 * \param moduleDisableList List of modules (specific instance) to be disabled.
 * \param numModules Number of modules.
 *
 * \retval S_PASS          indicates the operation is success
 * \retval E_FAIL          indicates the module is not disabled (time-out)
 * \retval E_INVALID_PARAM invalid module id
 **/
int32_t PRCMMultiModuleDisable(prcmModuleInfo_t *moduleDisableList, 
                               uint32_t numModules);

/**
 * \brief This API checks if the module is currently in enabled/disabled state.
 *
 * \param moduleId   Unique ID of the module for which the status to be 
 *                   checked.
 *                       #chipdbModuleID_t 
 * \param instNum    Instance number of the module
 *
 * \retval TRUE  Module is enabled
 * \retval FALSE Module is disabled 
 **/
uint32_t PRCMIsModuleEnabled(chipdbModuleID_t moduleId, uint32_t instNum);

#if defined(AM43XX_FAMILY_BUILD)
/**
 * \brief This API enables the optional clock. The functional and interface 
 *        clocks will get enabled once the module is enabled in PRCM. 
 *
 * \param clockId        Unique ID of the clock to be enabled
 *                           #prcmClockId_t
 * \param isBlockingCall Flag indicating whether this call should wait till the 
 *                       clock is enabled (TRUE) or return simply after  
 *                       configuring the control register (FALSE). In case of 
 *                       non-blocking call the caller should ensure the clock 
 *                       is enabled by calling the API PRCMIsClockEnabled())
 *
 * \retval S_PASS          indicates the operation is success
 * \retval E_FAIL          indicates the clock is not enabled (time-out)
 * \retval E_INVALID_PARAM invalid clock (optional clock) id
 *
 **/
int32_t PRCMOptClockEnable(prcmClockId_t clockId, uint32_t isBlockingCall);

/**
 * \brief This API disables the optional clock. It can be called when a 
 *        sub-module not need to be operational. When a module is disabled the
 *        API PRCMModuleDisable() ensures that the optional clock is also 
 *        disabled.
  *
 * \param clockId        Unique ID of the clock to be disabled
 *                           #prcmClockId_t
 * \param isBlockingCall Flag indicating whether this call should wait till the 
 *                       clock is disabled (TRUE) or return simply after  
 *                       configuring the control register (FALSE). In case of 
 *                       non-blocking call the caller should ensure the clock 
 *                       is disabled by calling the API PRCMIsClockEnabled())
 *
 * \retval S_PASS          indicates the operation is success
 * \retval E_FAIL          indicates the clock is not disabled (time-out)
 * \retval E_INVALID_PARAM invalid clock (optional clock) id
 *
 **/
int32_t PRCMOptClockDisable(prcmClockId_t clockId, uint32_t isBlockingCall);

/**
 * \brief This API checks if the optional clock is currently in 
 *        enabled/disabled state.
 *
 * \param clockId   Unique ID of the clock for which the status to be checked.
 *                           #prcmClockId_t 
 *
 * \retval TRUE  Clock is enabled
 * \retval FALSE Clock is disabled
 **/
uint32_t PRCMIsOptClockEnabled(prcmClockId_t clockId);

/**
 * \brief This API gets the input functional clock rate of a module. This can
 *        be used by the device driver API's to get the input clock and configure
 *        the internal multipliers/dividers accordingly. Clock manipulations
 *        inside the module are not modelled here, and left to the individual
 *        module drivers to handle.
 *
 * \param moduleId       Unique ID of the module
 *                           #chipdbModuleID_t
 * \param instNum        Instance number of the module
 * \param clockId        Clock ID of the clock edge to be traversed. For 
 *                       modules like CPSW, DSS etc, where more than one clock 
 *                       feeds the module, one of the clock need to be selected.
 *                           #prcmClockId_t
 * \param *pClockRate    Pointer to get the clock rate in KHz 
 *
 * \retval S_PASS              Clock rate returned in 'clockRate' is valid
 * \retval E_INVALID_PARAM     Invalid module id
 * \retval E_INVALID_OPERATION API called when the module is disabled
 **/
int32_t PRCMGetClockRate(chipdbModuleID_t moduleId, 
                         uint32_t instNum,
                         prcmClockId_t clockId, 
                         uint32_t *pClockRate);
                            
/**
 * \brief This API selects the parent of a node (multiplexer) in
 *        the clock tree. At reset the parent node will be set to the reset 
 *        selection. If the application need to select different parent clock 
 *        this API shall be called. 
 *
 * Note:  This change in parent node may affect the modules which take clock 
 *        from this source. The application is expected to ensure other modules 
 *        are handled to accommodate this change.
 *
 * \param muxId         Unique ID of the node.
 *                          #prcmNodeId_t
 * \param parentNodeId  Parent node to be selected.
 *                          #prcmNodeId_t
 *
 * \retval S_PASS          Parent node selection is updated with new parent
 * \retval E_INVALID_PARAM Invalid node id or parent node id
 **/
int32_t PRCMSetMuxParent(prcmNodeId_t muxId, prcmNodeId_t parentNodeId);

/**
 * \brief This API gets the parent clock id of a clock node (multiplexer) in
 *        the clock tree. At reset the parent clock will be set to the reset 
 *        selection. 
 *
 * \param muxId          Unique ID of the node.
 *                          #prcmNodeId_t
 * \param *pParentNodeId Pointer to get the parent node id.
 *                          #prcmNodeId_t
 *
 * \retval S_PASS          Id returned via 'parentNodeId' is valid
 * \retval E_INVALID_PARAM Invalid node id
 **/
int32_t PRCMGetMuxParent(prcmNodeId_t muxId, prcmNodeId_t *pParentNodeId);

/**
 * \brief This API sets the divide value of a divider node in the clock tree. 
 *        At reset the divider value will be set to the reset value. If the 
 *        application need to set a different divider this API shall be called.
 *
 * Note:  This change in the clock divider may affect the modules which take 
 *        clock from this divider. The application is expected to ensure other 
 *        modules are handled to accommodate this change.
 *
 * \param dividerId     Unique ID of the node.
 *                          #prcmNodeId_t
 * \param divider       Division factor(/2, /4, /8 etc.)
 *
 * \retval S_PASS          The new divider value is updated
 * \retval E_INVALID_PARAM Invalid node id or divider
 **/
int32_t PRCMSetDivider(prcmNodeId_t dividerId, uint32_t divider);

/**
 * \brief This API gets the divide value of a divider node in the clock tree. 
 *        At reset the divider value will be set to the reset value.
 *
 *
 * \param dividerId     Unique ID of the node.
 *                          #prcmNodeId_t
 * \param *pDivider     Pointer to get the divider value
 *
 * \retval S_PASS          The value in "divider" pointer is valid
 * \retval E_INVALID_PARAM Invalid node id
 **/
int32_t PRCMGetDivider(prcmNodeId_t dividerId, uint32_t *pDivider);

/**
 * \brief This API configures different parameters of PLL - multiplier, 
 *        divider, post divider and low power mode as indicated by the 
 *        input. It also makes sure the PLL is locked with new values. This API
 *        can be used to configure the PLL with initial values and also to 
 *        change the frequency during OPP change (DVFS).
 *
 * Note: The PLL configuration will affect the clock supplied to the down 
 *       stream nodes. The caller is expected to handle the down stream nodes
 *       affected by this change.
 *
 * \param dpllId       Unique ID of the PLL.
 *                         #prcmNodeId_t
 * \param *pDpllData   PRCM Configuration values.
 *
 * Note: This API shall not be called with DCC (Duty Cycle Correction) enabled.
 *       If the DCC is enabled, then this API will return failure (E_FAIL).
 *
 * \retval S_PASS          The PLL is updated with values passed
 * \retval E_FAIL          The PLL couldn't be configured with new values (time-out).
 * \retval E_INVALID_PARAM Invalid PLL ptr or invalid value.
 **/
int32_t PRCMDpllLock(prcmNodeId_t dpllId, prcmDpllConfig_t *pDpllData);

/**
 * \brief This API configures the PLL in bypass mode. This API will be used 
 *        while entering low power mode.
 *
 * Note: PLL bypass configuration will affect the clock supplied to the down
 *       stream nodes. The caller is expected to handle the down stream nodes
 *       affected by this change.
 *
 * \param dpllId         Unique ID of the PLL
 *                           #prcmNodeId_t
 * \param bypassInputSel Bypass clock source
 *                           #prcmDpllBypassClkSel_t
 * \param clkInputLowSel  Mux input select - CORE_CLKOUTM6 or PER_CLKOUTM2
 *                           #prcmDpllClkInputLowSel_t
 * \param bypassType     Type of bypass MN-bypass or LP-bypass
 *                           #prcmDpllBypassClkSel_t
 *
 * \retval S_PASS          The PLL is configured in bypass mode
 * \retval E_FAIL          The PLL doesn't switch to bypass mode (time-out)
 * \retval E_INVALID_PARAM Invalid PLL ptr or invalid bypass clock source/type
 **/
int32_t PRCMDpllBypass(prcmNodeId_t dpllId, 
                       prcmDpllBypassClkSel_t bypassInputSel,
                       prcmDpllClkInputLowSel_t clkInputLowSel, 
                       prcmDpllBypassMode_t bypassType);

/**
 * \brief This API configures the output frequency ramping parameters of the 
 *        PLL.
 *
 * \param dpllId         Unique ID of the PLL
 *                           #prcmNodeId_t
 * \param rampLevel      Ramp level (Algo to be used)
 *                           #prcmDpllRampLevel_t
 * \param rampRate       Ramp rate (time spent in each ramp step)
 *                           #prcmDpllRampRate_t
 * \param isRelockRampEnable Flag indicating whether ramping should be enabled 
 *                           during relock also (TRUE) or only during initial 
 *                           locking (FALSE).
 *
 * \retval S_PASS          The ramp configuration is done successfully
 * \retval E_INVALID_PARAM Invalid PLL id or ramp values
 **/
int32_t PRCMDpllRampConfig(prcmNodeId_t dpllId, 
                           prcmDpllRampLevel_t rampLevel, 
                           prcmDpllRampRate_t rampRate, 
                           uint32_t isRelockRampEnable);
                        
/**
 * \brief This API can enable or disable duty cycle correction. This must be 
 *        enabled only for frequency > 1GHz. 
 *
 * \param dpllId          Unique ID of the PLL
 *                            #prcmNodeId_t
 * \param enableDccCorr   Flag indicating whether DCC correction to be 
 *                        enabled or disabled
 * \param dccRampDuration The value "NbCycles" set in this field determines the
 *        duration of the clock ramp step during which output frequency is 
 *        Fdpll/(2*M2). The duration is computed as 32 x NbCycles of WKUP-L4 
 *        clock period (WKUP-L4 clock in AM43xx is SYSCLK, which is the master 
 *        oscillator clock). For Example: If the WKUP-L4 clock is 26Mhz, the 
 *        duration is computed as  (32 x NbCycles)/26Mhz. Duration should be 
 *        > 1.5us to allow enough time for DCC to lock. This bit-field is only 
 *        relevant when DCC is enabled.
 *
 * Note: It is not allowed to transition from a locked mode with DCC_EN = 1 to 
 *       a manual bypass mode directly (because DPLL M3 output does not support
 *       bypass mode). An intermediate state with DCC_EN=0 and DPLL locked must
 *       be programmed in-between.
 *
 * \retval S_PASS          DCC is enabled
 * \retval E_INVALID_PARAM Invalid PLL id or DCC config value
 **/
int32_t PRCMDpllDutyCycleCorrEnable(prcmNodeId_t dpllId, 
                                    uint32_t enableDccCorr, 
                                    uint32_t dccRampDuration);
               
/**
 * \brief This API provides interface to enable or disable CLKDCOLDO output of 
 *        PLL. 
 *
 * \param dpllId    Unique ID of the PLL
 *                      #prcmNodeId_t
 * \param enableClkDcoLdo Flag indicating whether CLKDCOLDO to be enabled or 
 *                        disabled
 *
 * \retval S_PASS CLKDCOLDO is enabled
 * \retval E_INVALID_PARAM Invalid PLL id
 **/
int32_t PRCMDpllClkDcoLdoEnable(prcmNodeId_t dpllId, uint32_t enableClkDcoLdo);

/**
 * \brief This API provides interface to enable or disable auto-recalibration 
 *        of PLL.
 *
 * \param dpllId    Unique ID of the PLL
 *                      #prcmNodeId_t
 * \param enableDpllRecalib Flag indicating whether auto-recalibration to be  
 *                          enabled or disabled
 *
 * \retval S_PASS Auto-recalibration is enabled
 * \retval E_INVALID_PARAM Invalid PLL id
 **/
int32_t PRCMDpllRecalibEnable(prcmNodeId_t dpllId, uint32_t enableDpllRecalib);
                                                    
/**
 * \brief This API configures the rate of the Root clock.
 *
 * \param rootClockId   Unique ID of the root clock node
 *                          #prcmNodeId_t
 * \param clockRateKhz  Frequency to be set for the root clock in Khz.
 *
 * \retval S_PASS         The Root clock is configured with the given value
 * \retval E_FAIL         The root clock is not configured with the given value
 * \retval E_INVALID_PARAM Invalid root clock id or rate
 **/
int32_t PRCMSetRootClockRate(prcmNodeId_t rootClockId, uint32_t clockRateKhz);

/**
 * \brief This API gets the rate of the Root clock.
 *
 * \param rootClockId     Unique ID of the root clock node
 *                            #prcmNodeId_t 
 * \param *pClockRateKhz  Pointer to get root clock rate in Khz.
 *                        (It holds 0 on return if the clock rate was not set)
 *
 * \retval S_PASS      The Root clock rate returned in pClockRateKhz is valid.
 * \retval E_INVALID_PARAM Invalid root clock id.
 *
 **/
int32_t PRCMGetRootClockRate(prcmNodeId_t rootClockId, uint32_t* pClockRatekHz);

#endif /* AM43XX_FAMILY_BUILD */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef PRCM_DRIVER_H_ */
