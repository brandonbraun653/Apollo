/**
 *  \file  prcm.c
 *
 *  \brief This file contains the PRCM APIs implementation.
 *
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

/* ========================================================================= */
/*                             Include Files                                 */
/* ========================================================================= */

#include "types.h"
#include "hw_types.h"
#include "prcm.h"
#include "chipdb_defs.h"
#include "hw_prcm_data.h"
#include "hw_prcm_data_names.h"
#include "hw_control_am43xx.h"
#include "hw_am43xx_chipdb.h"
#include "misc.h"
#include "error.h"

/* ========================================================================= */
/*                           Macros & Typedefs                               */
/* ========================================================================= */

/* ========================================================================= */
/*                         Structures and Enums                              */
/* ========================================================================= */

/* ========================================================================= */
/*                       Global Variables Declarations                       */
/* ========================================================================= */
extern const prcmModule_t prcmModuleElems[];
extern const prcmClkDomain_t prcmClockDomainElems[];
extern const prcmPowerDomain_t prcmPowerDomainElems[];
extern const ag_node prcmNodes[];

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

/**
 * \brief This API returns the frequency conversion factor of the PLL. It 
 *        includes multiplier, divider and post divider influences on the input
 *        clock frequency to the PLL.
 *
 * \param pDpllPtr Pointer to the DPLL instance
 *
 * \retval Conversion factor Frequency conversion factor.
 **/
static float PrcmDpllGetConvVal(prcmDpll_t* pDpllPtr);

/**
 * \brief This API returns the frequency of the root clock.
 *
 * \param pRootClkPtr Pointer to the root clock instance
 *
 * \retval Frequency Root clock frequency
 **/
static float PrcmGetRootClkRate(prcmRootClk_t* pRootClkPtr);

/**
 * \brief This API updates the post dividers on the PLL.
 *
 * \param pDpllPtr       Pointer to the DPLL instance
 * \param postDivValList List of post dividers and the values to be configured.
 * \param maxDividers    Number of post dividers in the list
 *
 * \retval S_PASS The divider is updated successfully
 * \retval E_FAIL The divider update has failed
 **/
static int32_t PrcmPostDivUpdate(prcmDpll_t* pDpllPtr, 
                    pllPostDivValue_t* postDivValList, uint32_t maxDividers);

/**
 * \brief This API returns the division factor of the divider.
 *
 * \param pDivPtr Pointer to the divider instance
 *
 * \retval division factor of the divider
 **/
static uint32_t PrcmGetDivVal(prcmClockDivider_t* pDivPtr);

/* TODO: The implementation is completely blocking. Once the Timer API's 
         are available, support for non-blocking will be added.*/

/* ========================================================================= */
/*                          Function Definitions                             */
/* ========================================================================= */
int32_t PRCMModuleIdxEnable(prcmModuleId_t prcmModId, uint32_t isBlockingCall)
{
    int32_t status = S_PASS;
    uint32_t configValue = 0;
    uint8_t moduleMode;
    
    prcmCdId_t prcmCdId = PRCM_CD_UNDEF;
    prcmPdId_t prcmPdId = PRCM_PD_UNDEF;
    
    const prcmModule_t* pModuleHandle = NULL;
    const prcmClkDomain_t* pCdHandle = NULL;
    const prcmPowerDomain_t* pPdHandle = NULL;
    
    /* Get handles for module, clock domain and power domain. */
    if(PRCM_MOD_UNDEF != prcmModId)
    {
        pModuleHandle = &prcmModuleElems[prcmModId - PRCM_MOD_MIN];
        prcmCdId = pModuleHandle->clockDomainId;
        moduleMode = pModuleHandle->moduleMode;
        
        /* Proceed further only if the clock control reg address is valid and 
           the module supports auto or enabled modes */
        if((PRCM_INVALID_REGADDR != pModuleHandle->clkCtrlRegAddr) && 
           (PRCM_CD_UNDEF != prcmCdId) &&
           ((PRCM_MODULE_MODE_AUTO == (moduleMode & PRCM_MODULE_MODE_AUTO)) ||
           (PRCM_MODULE_MODE_ENABLED == (moduleMode & PRCM_MODULE_MODE_ENABLED))))
        {
            pCdHandle = &prcmClockDomainElems[prcmCdId];
            prcmPdId = pCdHandle->powerDomainId;
            if((PRCM_INVALID_REGADDR != pCdHandle->clkStCtrlAddr) && 
               (PRCM_PD_UNDEF != prcmPdId))
            {
                pPdHandle = &prcmPowerDomainElems[prcmPdId];
            }
            else
            {
                status = E_FAIL;
            }
        }
        else
        {
            status = E_FAIL;
        }
    }
    else
    {
        status = E_INVALID_MODULE_ID;
    }

    /* Check if power domain id enabled */
    /* Note: Programming "PWRSTCTRL" can be skipped in during sleep and wake 
       sequences. Whenever  "_CLKSTCTRL.CLKTRCTRL = SW_SLEEP is programmed, it 
       will automatically go to OFF state. Whenever  "_CLKSTCTRL.CLKTRCTRL = 
       SW_WKUP is programmed, it will automatically go to ON state. 
       PWRSTCTRL.POWERSTATE = ON should be programmed only if there is any 
       requirement of not to switch off the power but gate all the clocks. So
       here only the status of Power domain is checked (and not configured).
    */
    if(S_PASS == status)
    {
        /* Check if domain is NOT an always-on domain (valid power state-status 
           register). If it is always-on domain no need to have this check. */
        if(PRCM_INVALID_REGADDR != pPdHandle->pwrStateStatusRegAddr)
        {
            while(PRCM_PD_STATUS_ON != HW_RD_FIELD32(
                pPdHandle->pwrStateStatusRegAddr, PRCM_PWRSTST_POWERSTATEST));
        }
    }
	
	/* TODO: Clock domain enable */
        
    /* Enable Module (module mode) */
    if(S_PASS == status)
    {
        if(PRCM_MODULE_MODE_AUTO == pModuleHandle->moduleMode)
        {
            configValue = PRCM_MODULE_MODE_AUTO;
        }
        else if (PRCM_MODULE_MODE_ENABLED == pModuleHandle->moduleMode)
        {
            configValue = PRCM_MODULE_MODE_ENABLED;
        }
        else
        {}
        HW_WR_FIELD32_RAW(pModuleHandle->clkCtrlRegAddr, PRCM_MODULE_MODE_MASK,
                            PRCM_MODULE_MODE_SHIFT, configValue);
            
        /* Wait till idle status is functional */
        while(PRCM_MODULE_IDLEST_FUNC != HW_RD_FIELD32(
            pModuleHandle->clkCtrlRegAddr, PRCM_CLKCTRL_IDLEST));
        
        /* Wait till standby status is functional */
        /*
         * TODO: Standby mode support should be checked only in low power mode.
         * For normal functionality it is not needed to check the mode. Hence
         * this checking is commented.
         */
        /*
        if(TRUE == pModuleHandle->isStandbySuported)
        {
            while(PRCM_CLKCTRL_STBYST_FUNC != HW_RD_FIELD32(
                pModuleHandle->clkCtrlRegAddr, PRCM_CLKCTRL_STBYST));            
        }
        */
    }
    return status;
}

int32_t PRCMModuleEnable(chipdbModuleID_t moduleId, uint32_t instNum,
                                                    uint32_t isBlockingCall)
{
    int32_t status = S_PASS;
    prcmModuleId_t prcmModId = PRCM_MOD_UNDEF;

    /* Translate "chipdb module Id" to "prcm module Id" */
    prcmModId = PRCMGetModuleId(CHIPDB_GET_RESOURCEID(moduleId, instNum));

    /* Get handles for module, clock domain and power domain. */
    if(PRCM_MOD_UNDEF != prcmModId)
    {
        status = PRCMModuleIdxEnable(prcmModId, isBlockingCall);
    }
    else
    {
        status = E_INVALID_MODULE_ID;
    }
    return status;
}

int32_t PRCMMultiModuleEnable(prcmModuleInfo_t *moduleEnableList, 
                                                        uint32_t numModules)
{
    int32_t status = S_PASS;
    uint32_t index = 0;
    while((index < numModules) && (S_PASS == status))
    {
        status = PRCMModuleEnable(moduleEnableList[index].moduleId, 
                                    moduleEnableList[index].instNum, TRUE);
        index++;
    }
    return status;
}

int32_t PRCMModuleIdxDisable(prcmModuleId_t prcmModId, uint32_t isBlockingCall)
{
    int32_t status = S_PASS;
    prcmCdId_t prcmCdId = PRCM_CD_UNDEF;
    
    const prcmModule_t* pModuleHandle = NULL;
    const prcmClkDomain_t* pCdHandle = NULL;
    
    /* Get handles for module and clock domain. */
    if(PRCM_MOD_UNDEF != prcmModId)
    {
        pModuleHandle = &prcmModuleElems[prcmModId - PRCM_MOD_MIN];
        prcmCdId = pModuleHandle->clockDomainId;
        
        /* Proceed further only if the clock control reg address is valid and 
           the module supports auto or enabled modes */
        if((PRCM_INVALID_REGADDR != pModuleHandle->clkCtrlRegAddr) && 
           (PRCM_CD_UNDEF != prcmCdId))
        {
            pCdHandle = &prcmClockDomainElems[prcmCdId];
        }
        else
        {
            status = E_FAIL;
        }
    }
    else
    {
        status = E_INVALID_MODULE_ID;
    }

    /* Disable optional clock */
    /* Commenting this out for now needs to be implemented. */
    /*
    index = 0;
    while(pModuleHandle->maxOptionalClock > index)
    {
        // TODO: Clock list not yet defined in auto-generation
        //pOptClock = (prcmClock_t*)(clockList[optClkId[index]]);
        HW_WR_FIELD32_RAW(pOptClock->pClkCtrlBitField.regAddr, 
                          pOptClock->pClkCtrlBitField.mask, 
                          pOptClock->pClkCtrlBitField.shift,
                          !PRCM_OPT_CLOCK_ENABLE);
        
        while(PRCM_OPT_CLOCK_ENABLE == 
            HW_RD_FIELD32_RAW(pOptClock->clkActivityBitField.regAddr,
                              pOptClock->clkActivityBitField.mask,
                              pOptClock->clkActivityBitField.shift))
        
        index++;
    }
    */

    /* Disable Module (module mode) */
    if(S_PASS == status)
    {
        HW_WR_FIELD32_RAW(pModuleHandle->clkCtrlRegAddr, PRCM_MODULE_MODE_MASK,
                            PRCM_MODULE_MODE_SHIFT, PRCM_MODULE_MODE_DISABLED);
            
        /* Wait till idle status is "disabled" */
        while(PRCM_MODULE_IDLEST_DISABLE != HW_RD_FIELD32(
            pModuleHandle->clkCtrlRegAddr, PRCM_CLKCTRL_IDLEST));
        
        /* Wait till standby status is "standby" */        
        if(TRUE == pModuleHandle->isStandbySuported)
        {
            while(PRCM_CLKCTRL_STBYST_STANDBY != HW_RD_FIELD32(
                pModuleHandle->clkCtrlRegAddr, PRCM_CLKCTRL_STBYST));            
        }
    }

    /* Update clock domain */
    if(S_PASS == status)
    {
        if(0 == (HW_RD_REG32(pCdHandle->clkStCtrlAddr) & 
                                            ~PRCM_CLKSTCTRL_CLKTRCTRL_MASK))
        {
            HW_WR_FIELD32_RAW(pCdHandle->clkStCtrlAddr, 
                                PRCM_CLKSTCTRL_CLKTRCTRL_MASK, 
                                PRCM_CLKSTCTRL_CLKTRCTRL_SHIFT, 
                                PRCM_CD_CLK_TRANS_SW_SLEEP);        
        }
    }

    /* Disable PD - Not Needed for AM43xx. For SoC's needing PD disable, all 
       CD's need to be checked if they are disabled before disabling the PD. */
    return status;
}

int32_t PRCMModuleDisable(chipdbModuleID_t moduleId, uint32_t instNum,
                                                    uint32_t isBlockingCall)
{
    int32_t status = S_PASS;
    prcmModuleId_t prcmModId = PRCM_MOD_UNDEF;

    /* Translate "chipdb module Id" to "prcm module Id" */
    prcmModId = PRCMGetModuleId(CHIPDB_GET_RESOURCEID(moduleId, instNum));

    /* Get handles for module and clock domain. */
    if(PRCM_MOD_UNDEF != prcmModId)
    {
        status = PRCMModuleIdxDisable(prcmModId, isBlockingCall);
    }
    else
    {
        status = E_INVALID_MODULE_ID;
    }
    return status;
}

int32_t PRCMMultiModuleDisable(prcmModuleInfo_t *moduleDisableList, 
                                                        uint32_t numModules)
{
    int32_t status = S_PASS;
    uint32_t index = 0;
    while((index < numModules) && (S_PASS == status))
    {
        status = PRCMModuleDisable(moduleDisableList[index].moduleId, 
                                    moduleDisableList[index].instNum, TRUE);
        index++;
    }
    return status;
}

uint32_t PRCMIsModuleEnabled(chipdbModuleID_t moduleId, uint32_t instNum)
{
    uint32_t isEnabled = FALSE;
    prcmModuleId_t prcmModId = PRCM_MOD_UNDEF;
    const prcmModule_t* pModuleHandle = NULL;
    uint32_t moduleMode = 0;

    /* Translate "chipdb module Id" to "prcm module Id" */
    prcmModId = PRCMGetModuleId(CHIPDB_GET_RESOURCEID(moduleId, instNum));
    
    /* Get handles for module, clock domain and power domain. */
    if(PRCM_MOD_UNDEF != prcmModId)
    {
        pModuleHandle = &prcmModuleElems[prcmModId - PRCM_MOD_MIN];
        
        /* Proceed further only if the clock control reg address is valid. */
        if(PRCM_INVALID_REGADDR != pModuleHandle->clkCtrlRegAddr)
        {
            moduleMode = HW_RD_FIELD32
                (pModuleHandle->clkCtrlRegAddr, PRCM_MODULE_MODE);
            if((PRCM_MODULE_MODE_AUTO == moduleMode) || 
               (PRCM_MODULE_MODE_ENABLED == moduleMode))
            {
                isEnabled = TRUE;
            }
        }
    }
    return isEnabled;
}

/* TODO: Define struct only for opt clock - prcmClock_t */
int32_t PRCMOptClockEnable(prcmClockId_t clockId, uint32_t isBlockingCall)
{
    int32_t status = S_PASS;
    prcmClock_t *pOptClock = NULL;
    
    if((clockId >= PRCM_CLK_MIN) && (clockId < PRCM_CLK_MAX))
    {
        /* TODO: Clock list not yet defined ??? */
        //pOptClock = (prcmClock_t*)(clockList[clockId]);
        HW_WR_FIELD32_RAW(pOptClock->pClkCtrlBitField.regAddr, 
                              pOptClock->pClkCtrlBitField.mask, 
                              pOptClock->pClkCtrlBitField.shift,
                              PRCM_OPT_CLOCK_ENABLE);
                              
        while(PRCM_OPT_CLOCK_ENABLE == 
            HW_RD_FIELD32_RAW(pOptClock->clkActivityBitField.regAddr,
                              pOptClock->clkActivityBitField.mask,
                              pOptClock->clkActivityBitField.shift));
    }
    else
    {
        status = E_INVALID_PARAM;
    }
    return status;
}

int32_t PRCMOptClockDisable(prcmClockId_t clockId, uint32_t isBlockingCall)
{
    int32_t status = S_PASS;
    prcmClock_t *pOptClock = NULL;
    
    if((clockId >= PRCM_CLK_MIN) && (clockId < PRCM_CLK_MAX))
    {    
        // TODO:
        //pOptClock = (prcmClock_t*)(clockList[clockId]);
        HW_WR_FIELD32_RAW(pOptClock->pClkCtrlBitField.regAddr, 
                                pOptClock->pClkCtrlBitField.mask, 
                                pOptClock->pClkCtrlBitField.shift,
                                !PRCM_OPT_CLOCK_ENABLE);
                          
        while(PRCM_OPT_CLOCK_ENABLE == 
            HW_RD_FIELD32_RAW(pOptClock->clkActivityBitField.regAddr,
                                pOptClock->clkActivityBitField.mask,
                                pOptClock->clkActivityBitField.shift));
    }
    else
    {
        status = E_INVALID_PARAM;
    }
    return status;
}

uint32_t PRCMIsOptClockEnabled(prcmClockId_t clockId)
{
    int32_t status = E_FAIL;
    prcmClock_t *pOptClock = NULL;
    
    if((clockId >= PRCM_CLK_MIN) && (clockId < PRCM_CLK_MAX))
    {    
        // TODO:
        //pOptClock = (prcmClock_t*)(clockList[clockId]);
        if(PRCM_OPT_CLOCK_ENABLE == 
            HW_RD_FIELD32_RAW(pOptClock->clkActivityBitField.regAddr,
                                pOptClock->clkActivityBitField.mask,
                                pOptClock->clkActivityBitField.shift));
        {
            status = S_PASS;
        }
    }
    return status;
}

int32_t PRCMGetClockRate(chipdbModuleID_t moduleId, uint32_t instNum,
                            prcmClockId_t clockId, uint32_t *pClockRate)
{
    prcmModuleId_t prcmModId = PRCM_MOD_UNDEF;
    int32_t status = E_INVALID_PARAM;
    prcmModuleMode_t moduleMode;
    
    const prcmModule_t* pModuleHandle = NULL;
    prcmClockDivider_t* pDivPtr  = NULL;
    prcmMultiplexer_t* pMuxPtr  = NULL;
    prcmDpll_t* pDpllPtr        = NULL;
    prcmRootClk_t* pRootClkPtr  = NULL;

    uint32_t fieldVal = 0;
    prcmNodeId_t parent_node_id = 0;
    float divisionFactor = 1.0;
    float rootClkRate = 0.0;
    
    /* Translate "chipdb module Id" to "prcm module Id" */
    prcmModId = PRCMGetModuleId(CHIPDB_GET_RESOURCEID(moduleId, instNum));
    
    /* If clock Id is invalid, so get the first functional clock from Module's
       clock list. */
    if((clockId < PRCM_CLK_MIN) && (clockId >= PRCM_CLK_MAX))
    {
        /* Get handles for module, clock domain and power domain. */
        if(PRCM_MOD_UNDEF != prcmModId)
        {
            pModuleHandle = &prcmModuleElems[prcmModId - PRCM_MOD_MIN];
        
            /* Proceed further only if the clock control reg address is valid. */
            if(PRCM_INVALID_REGADDR != pModuleHandle->clkCtrlRegAddr)
            {
                moduleMode = HW_RD_FIELD32(
                    pModuleHandle->clkCtrlRegAddr, PRCM_MODULE_MODE);
                if((PRCM_MODULE_MODE_AUTO == moduleMode) || 
                   (PRCM_MODULE_MODE_ENABLED == moduleMode))
                {
                    // TODO:
                    //clockId = clockList[pModuleHandle->funcClkId[0]];
                }
                else
                {
                    status = E_INVALID_OPERATION;
                }
            }
        }
    }
    
    /* Calculate clock rate */
    if((clockId >= PRCM_CLK_MIN) && (clockId < PRCM_CLK_MAX))
    {
        /* TODO: Index '0' to be decided based on clockId. */
        /* TODO: Spec need to be updated to move func clk list to edge property */
        parent_node_id = prcmNodes[prcmModId].edge_in[0];
        
        /* Traverse till root clock and get the division factor */
        while(PRCM_NODE_UNDEF != parent_node_id)
        {
            /* Validate Node */
            //if(TRUE == ag_valid_node(prcmNodes, parent_node_id)) // TODO
            {
                status = E_FAIL;
                break;
            }
        
            switch(ag_get_prop_type(prcmNodes, parent_node_id))
            {
                case PRCM_DIV:
                    pDivPtr = (prcmClockDivider_t*)ag_get_prop_ptr(prcmNodes, 
                                                           parent_node_id);
                    divisionFactor *= PrcmGetDivVal(pDivPtr);
                    /* For Divider only one input is present */
                    parent_node_id = prcmNodes[parent_node_id].edge_in[0];
                    break;
                    
                case PRCM_MUX:
                    /* TODO: Index to be used as bit-field config value - 
                             "PRCM_MUX_TIMER3_CLK_inNodes". They are not in 
                             order currently, need to order them. */
                    pMuxPtr = (prcmMultiplexer_t*)ag_get_prop_ptr(prcmNodes, 
                                                           parent_node_id);
                    fieldVal= HW_RD_FIELD32_RAW(pMuxPtr->muxSelBitField.regAddr,
                                                pMuxPtr->muxSelBitField.mask,
                                                pMuxPtr->muxSelBitField.shift);
                    parent_node_id = prcmNodes[parent_node_id].edge_in[fieldVal];
                    break;

                case PRCM_DPLL:
                    /* Read mult, div, post div values */
                    pDpllPtr = (prcmDpll_t*)ag_get_prop_ptr(prcmNodes, 
                                                           parent_node_id);
                    /* Update divisionFactor */
                    divisionFactor = divisionFactor/PrcmDpllGetConvVal(pDpllPtr);
                    //parent_node_id = ??? /* TODO: Edge property - active edge ??? */
                    break;
                    
                case PRCM_ROOT_CLK:
                    /* TODO: Root clock array list not complete */
                    pRootClkPtr = (prcmRootClk_t*)ag_get_prop_ptr(prcmNodes, 
                                                           parent_node_id);
                    rootClkRate = PrcmGetRootClkRate(pRootClkPtr);
                    if(0.0 != rootClkRate)
                    {
                        *pClockRate = rootClkRate/divisionFactor;
                        status = S_PASS;
                    }
                    parent_node_id = PRCM_NODE_UNDEF;
                    break;
                    
                default:
                    status = E_FAIL;
            }
        }
    }
    return status;
}

int32_t PRCMSetMuxParent(prcmNodeId_t muxId, prcmNodeId_t parentNodeId)
{
    uint32_t index = 0;
    ag_node_id parent_node_id = 0;
    int32_t status = E_INVALID_PARAM;
    prcmMultiplexer_t* pMuxPtr;
    
    while(index < prcmNodes[muxId].edge_in_max)
    {
        if(parent_node_id == prcmNodes[muxId].edge_in[index])
        {
            pMuxPtr = (prcmMultiplexer_t*)ag_get_prop_ptr(prcmNodes, muxId);
                    
            HW_WR_FIELD32_RAW(pMuxPtr->muxSelBitField.regAddr,
                                        pMuxPtr->muxSelBitField.mask,
                                        pMuxPtr->muxSelBitField.shift,
                                        index);
            status = S_PASS;
            break;
        }
        index++;
    }
    return status;
}

int32_t PRCMGetMuxParent(prcmNodeId_t muxId, prcmNodeId_t *pParentNodeId)
{
    uint32_t fieldVal = 0;
    int32_t status = E_INVALID_PARAM;
    prcmMultiplexer_t* pMuxPtr;
    
    if(IS_PRCM_MUX(muxId))
    {
        pMuxPtr = (prcmMultiplexer_t*)ag_get_prop_ptr(prcmNodes, muxId);
        fieldVal= HW_RD_FIELD32_RAW(pMuxPtr->muxSelBitField.regAddr,
                                pMuxPtr->muxSelBitField.mask,
                                pMuxPtr->muxSelBitField.shift);
                
        *pParentNodeId = prcmNodes[muxId].edge_in[fieldVal];
        status = S_PASS;
    }
    return status;
}

int32_t PRCMSetDivider(prcmNodeId_t dividerId, uint32_t divider)
{
    uint32_t index = 0;
    int32_t status = E_INVALID_PARAM;
    prcmClockDivider_t* pDivPtr;
    
    if(IS_PRCM_DIV(dividerId))
    {
        pDivPtr = (prcmClockDivider_t*)ag_get_prop_ptr(prcmNodes, dividerId);
        while(0 != pDivPtr->pSupportedDivision[index])
        {
            if(pDivPtr->pSupportedDivision[index] == divider)
            {
                HW_WR_FIELD32_RAW(pDivPtr->pDivCtrlBitField.regAddr,
                                    pDivPtr->pDivCtrlBitField.mask,
                                    pDivPtr->pDivCtrlBitField.shift,
                                    pDivPtr->pDividerBitValue[index]);
                status = S_PASS;
                break;
            }
            index++;
        }
    }
    return status;
}

int32_t PRCMGetDivider(prcmNodeId_t dividerId, uint32_t *pDivider)
{
    int32_t status = E_INVALID_PARAM;
    prcmClockDivider_t* pDivPtr;
    
    if(IS_PRCM_DIV(dividerId))
    {
        pDivPtr = (prcmClockDivider_t*)ag_get_prop_ptr(prcmNodes, dividerId);
        *pDivider = PrcmGetDivVal(pDivPtr);
        status = S_PASS;
    }
    return status;
}

int32_t PRCMDpllLock(prcmNodeId_t dpllId, prcmDpllConfig_t *pDpllData)
{
    int32_t status = S_PASS;
    uint32_t multMask;
    uint32_t multShift;
    uint32_t divMask;
    uint32_t divShift;
    float dpllIpClockKhz = 0.0;    
    prcmDpll_t* pDpllPtr = NULL;
    uint32_t clkSelRegAddr = 0;
    uint32_t clkModeRegAddr = 0;
    uint32_t idleStsRegAddr = 0;
    uint16_t multiplier = pDpllData->multiplier;
    uint16_t divider = pDpllData->divider;
    
    /* Validate dpll ID */
    if(!IS_PRCM_DPLL(dpllId))
    {
        status = E_INVALID_PARAM;
    }

    if(S_PASS == status)
    {
        /* Configure PLL in bypass mode */
        status = PRCMDpllBypass(dpllId, PRCM_DPLL_BYP_CLKINP,
                                PRCM_DPLL_CLKINPULOW_CORE_CLKOUTM6, 
                                PRCM_DPLL_BYP_MODE_FR_BYP_MODE);
    }    
    
    if(S_PASS == status)
    {
        pDpllPtr = (prcmDpll_t*)ag_get_prop_ptr(prcmNodes, dpllId);
        clkSelRegAddr = pDpllPtr->pllClkSelRegAddr;
        clkModeRegAddr = pDpllPtr->pllClkModeRegAddr;
        idleStsRegAddr = pDpllPtr->pllIdleStatusRegAddr;
        
        /* Low power mode enable */
        /* TODO: Get PLL input clock */
        /* Optimize power consumption of the module in the combination of low 
           input frequency and low output frequency (from TRM) */
        if((dpllIpClockKhz/(divider+1) <= (1*FREQ_MHZ)) && 
                    ((dpllIpClockKhz * multiplier)/(divider+1) <= (100*FREQ_MHZ)))
        {
            HW_WR_FIELD32_RAW(clkModeRegAddr, PRCM_CLKMODE_DPLL_LPMODE_EN_MASK, 
                                              PRCM_CLKMODE_DPLL_LPMODE_EN_SHIFT, 
                                              TRUE);
        }
        
        /* Update divider */
        divMask = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                    PRCM_ADPLLS_CLKSEL_DIV_MASK : PRCM_ADPLLLJ_CLKSEL_DIV_MASK);
        divShift = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                    PRCM_ADPLLS_CLKSEL_DIV_SHIFT : PRCM_ADPLLLJ_CLKSEL_DIV_SHIFT);
        HW_WR_FIELD32_RAW(clkSelRegAddr, divMask, divShift, pDpllData->divider);

        /* Update multiplier */
        multMask = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                    PRCM_ADPLLS_CLKSEL_MULT_MASK : PRCM_ADPLLLJ_CLKSEL_MULT_MASK);
        multShift = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                    PRCM_ADPLLS_CLKSEL_MULT_SHIFT : PRCM_ADPLLLJ_CLKSEL_MULT_SHIFT);
        HW_WR_FIELD32_RAW(clkSelRegAddr, multMask, multShift, pDpllData->multiplier);
    
        /* Update post dividers */
        status = PrcmPostDivUpdate(pDpllPtr, pDpllData->postDivConfList, 
                                            pDpllData->postDivConfigValueMax);

        /* Configure PLL in lock mode */
        HW_WR_FIELD32_RAW(clkModeRegAddr, PRCM_CLKMODE_DPLL_EN_MASK, 
                       PRCM_CLKMODE_DPLL_EN_SHIFT, PRCM_DPLL_BYP_MODE_LOCK_MODE);
        /* Wait till lock */
        while(PRCM_DPLL_IDLEST_ST_CLK_LOCKED != HW_RD_FIELD32_RAW(idleStsRegAddr,
                     PRCM_IDLEST_DPLL_ST_CLK_MASK, PRCM_IDLEST_DPLL_ST_CLK_SHIFT));
    }
    return status;
}

int32_t PRCMDpllBypass(prcmNodeId_t dpllId,
                        prcmDpllBypassClkSel_t bypassInputSel,
                        prcmDpllClkInputLowSel_t clkInpuLowSel,
                        prcmDpllBypassMode_t bypassType)
{
    int32_t status = S_PASS;
    prcmDpll_t* pDpllPtr = NULL;        
    
    /* Validate dpll ID */
    if( ((PRCM_DPLL_MPU != dpllId) && (PRCM_DPLL_DDR != dpllId) && 
         (PRCM_DPLL_DISP != dpllId))|| 
        (!IS_PRCM_DPLL(dpllId)))
    {
        status = E_INVALID_PARAM;
    }
    
    if(S_PASS == status)
    {
        pDpllPtr = (prcmDpll_t*)ag_get_prop_ptr(prcmNodes, dpllId);
        //if(TRUE == pDpllPtr->isDccSupported)// TODO
        {
            if(TRUE == HW_RD_FIELD32_RAW(pDpllPtr->pllClkSelRegAddr,
                                PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_MASK,
                                PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_SHIFT))
            {
                /* Bypass config with DCC enabled is not supported */
                status = E_FAIL;
            }
        }
    }
    
    if(S_PASS == status)
    {
        /* TODO: The below configuration is actually mux config- clkInpuLowSel.
               Use clock tree for config. This mux is not captured currently */
        /* Select CLKINPULOW */
        if(PRCM_DPLL_BYP_CLKINPULOW == bypassInputSel)
        {
            if(PRCM_DPLL_MPU == dpllId)
            {
                HW_WR_FIELD32_RAW(CTRL_PLL_CLKINPULOW, 
                    CTRL_PLL_CLKINPULOW_MPU_DPLL_SEL_MASK, 
                    CTRL_PLL_CLKINPULOW_MPU_DPLL_SEL_SHIFT, clkInpuLowSel);
            }
            else if (PRCM_DPLL_DISP == dpllId)
            {
                HW_WR_FIELD32_RAW(CTRL_PLL_CLKINPULOW, 
                    CTRL_PLL_CLKINPULOW_DISP_SEL_MASK, 
                    CTRL_PLL_CLKINPULOW_DISP_SEL_SHIFT, clkInpuLowSel);
            }
            else if (PRCM_DPLL_DDR == dpllId)
            {
                HW_WR_FIELD32_RAW(CTRL_PLL_CLKINPULOW, 
                    CTRL_PLL_CLKINPULOW_DDR_SEL_MASK, 
                    CTRL_PLL_CLKINPULOW_DDR_SEL_SHIFT, clkInpuLowSel);
            }
            else 
            {
                status = E_INVALID_PARAM;
            }
        }
        
        /* Select bypass clock */
        HW_WR_FIELD32_RAW(pDpllPtr->pllClkSelRegAddr, PRCM_DPLL_BYP_MASK, 
                    PRCM_DPLL_BYP_SHIFT, bypassInputSel);
        
        /* Configure PLL in bypass mode */
        HW_WR_FIELD32_RAW(pDpllPtr->pllClkModeRegAddr, PRCM_CLKMODE_DPLL_EN_MASK, 
                    PRCM_CLKMODE_DPLL_EN_SHIFT, bypassType);
        /* Wait till unlock */
        while(PRCM_DPLL_IDLEST_ST_CLK_UNLOCKED != 
                    HW_RD_FIELD32_RAW(pDpllPtr->pllIdleStatusRegAddr,
                    PRCM_IDLEST_DPLL_ST_CLK_MASK, PRCM_IDLEST_DPLL_ST_CLK_SHIFT));
    }
    return status;
}

int32_t PRCMDpllRampConfig(prcmNodeId_t dpllId, prcmDpllRampLevel_t rampLevel, 
                    prcmDpllRampRate_t rampRate, uint32_t isRelockRampEnable)
{
    int32_t status = S_PASS;
    prcmDpll_t* pDpllPtr = NULL;        
    
    /* Validate dpll ID */
    if(!IS_PRCM_DPLL(dpllId))
    {
        status = E_INVALID_PARAM;
    }
    
    if(S_PASS == status)
    {
        pDpllPtr = (prcmDpll_t*)ag_get_prop_ptr(prcmNodes, dpllId);
        
        if(PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType)
        {
            HW_WR_FIELD32_RAW(pDpllPtr->pllClkModeRegAddr,
                            PRCM_DPLL_RAMP_LEVEL_MASK,
                            PRCM_DPLL_RAMP_LEVEL_SHIFT, 
                            rampLevel);        

            HW_WR_FIELD32_RAW(pDpllPtr->pllClkModeRegAddr,
                            PRCM_DPLL_RAMP_RATE_MASK,
                            PRCM_DPLL_RAMP_RATE_SHIFT, 
                            rampRate);                      
                            
            HW_WR_FIELD32_RAW(pDpllPtr->pllClkModeRegAddr,
                            PRCM_DPLL_RELOCK_RAMP_EN_MASK,
                            PRCM_DPLL_RELOCK_RAMP_EN_SHIFT, 
                            isRelockRampEnable);
        }
        else
        {
            status = E_INVALID_PARAM;
        }
    }
    return status;
}

int32_t PRCMDpllDutyCycleCorrEnable(prcmNodeId_t dpllId, uint32_t isEnable, 
                                                    uint32_t dccRampDuration)
{
    int32_t status = S_PASS;
    prcmDpll_t* pDpllPtr = NULL;        
    
    /* Validate dpll ID */
    if(!IS_PRCM_DPLL(dpllId))
    {
        status = E_INVALID_PARAM;
    }
    
    if(S_PASS == status)
    {
        pDpllPtr = (prcmDpll_t*)ag_get_prop_ptr(prcmNodes, dpllId);
        
        //if(TRUE == pDpllPtr->isDccSupported) // TODO
        if(1) // TODO
        {
            if(TRUE == isEnable)
            {
                /* DCC Ramp duration */
                HW_WR_FIELD32_RAW(pDpllPtr->pllClkSelRegAddr,
                                PRCM_CM_CLKSEL_DPLL_MPU_DCC_COUNT_MAX_MASK,
                                PRCM_CM_CLKSEL_DPLL_MPU_DCC_COUNT_MAX_SHIFT,
                                dccRampDuration);        
            }
            HW_WR_FIELD32_RAW(pDpllPtr->pllClkSelRegAddr,
                            PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_MASK,
                            PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_SHIFT, 
                            isEnable);
        }
        else
        {
            status = E_INVALID_PARAM;
        }
    }
    return status;
}
                                                        
int32_t PRCMDpllClkDcoLdoEnable(prcmNodeId_t dpllId, uint32_t isEnable)
{
    int32_t status = S_PASS;
    prcmDpll_t* pDpllPtr = NULL;        
    
    /* Validate dpll ID */
    if((PRCM_DPLL_PER != dpllId) || (!IS_PRCM_DPLL(dpllId)))
    {
        status = E_INVALID_PARAM;
    }
    
    if(S_PASS == status)
    {
        pDpllPtr = (prcmDpll_t*)ag_get_prop_ptr(prcmNodes, dpllId);
        
        /* Power up/down control */
        HW_WR_FIELD32_RAW(pDpllPtr->pllClkDcoLdoRegAddr, 
                                PRCM_CM_CLKDCOLDO_DPLL_PER_PWDN_MASK, 
                                PRCM_CM_CLKDCOLDO_DPLL_PER_PWDN_SHIFT, 
                                !isEnable);
        /* Clock gate control */
        HW_WR_FIELD32_RAW(pDpllPtr->pllClkDcoLdoRegAddr,
                                PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL_MASK,
                                PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL_SHIFT, 
                                isEnable);
        /* Wait for clock gate status update */
        while(isEnable != HW_RD_FIELD32_RAW(pDpllPtr->pllClkDcoLdoRegAddr,
                                PRCM_CM_CLKDCOLDO_DPLL_PER_ST_MASK,
                                PRCM_CM_CLKDCOLDO_DPLL_PER_ST_SHIFT));
    }
    return status;
}

int32_t PRCMDpllRecalibEnable(prcmNodeId_t dpllId, uint32_t isEnable)
{
    int32_t status = S_PASS;
    prcmDpll_t* pDpllPtr = NULL;        
    
    /* Validate dpll ID */
    if(!IS_PRCM_DPLL(dpllId))
    {
        status = E_INVALID_PARAM;
    }
    
    if(S_PASS == status)
    {
        pDpllPtr = (prcmDpll_t*)ag_get_prop_ptr(prcmNodes, dpllId);
        
        if(PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType)
        {
            /* Drift Guard Enable */
            HW_WR_FIELD32_RAW(pDpllPtr->pllClkModeRegAddr,
                                    PRCM_DPLL_DRIFTGUARD_EN_MASK,
                                    PRCM_DPLL_DRIFTGUARD_EN_SHIFT, 
                                    isEnable);
        }
        else
        {
            status = E_INVALID_PARAM;
        }
    }
    return status;
}                     
                                                        
int32_t PRCMSetRootClockRate(prcmNodeId_t rootClockId, uint32_t clockRatekHz)
{
    uint32_t index = 0;
    int32_t status = E_INVALID_PARAM;
    prcmRootClk_t* pRootClkPtr = NULL;
    
    pRootClkPtr = (prcmRootClk_t*)ag_get_prop_ptr(prcmNodes, rootClockId);
    if(PRCM_ROOT_CLK_FREQ_FIXED != pRootClkPtr->rootClkType)
    {
        //while(index != pRootClkPtr->maxPossibleRates) //TODO
        while(1) //TODO
        {
            if(clockRatekHz == 
                        pRootClkPtr->pClockRateConfig[index].supportedClockRate)
            {
                // HW_WR_FIELD32_RAW(pRootClkPtr->pClkCtrlBitField->regAddr,
                            // pRootClkPtr->pClkCtrlBitField->mask,
                            // pRootClkPtr->pClkCtrlBitField->shift,
                            // pRootClkPtr->pClockRateConfig[index].configValue);
                break;
            }
            index++;
        }
    }
    return status;
}

int32_t PRCMGetRootClockRate(prcmNodeId_t rootClockId,uint32_t* pClockRatekHz)
{
    int32_t status = E_INVALID_PARAM;
    prcmRootClk_t* pRootClkPtr = NULL;
    
    if(IS_PRCM_ROOT_CLK(rootClockId))
    {
        pRootClkPtr = (prcmRootClk_t*)ag_get_prop_ptr(prcmNodes, rootClockId);
        *pClockRatekHz = PrcmGetRootClkRate(pRootClkPtr);
        status = S_PASS;
    }
    return status;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */


static uint32_t PrcmGetDivVal(prcmClockDivider_t* pDivPtr)
{
    uint32_t fieldVal;
    uint32_t divVal = 1;
    uint32_t index = 0;
    
    /* TODO: fixed divider to be accounted */
    
    fieldVal= HW_RD_FIELD32_RAW(pDivPtr->pDivCtrlBitField.regAddr,
                                pDivPtr->pDivCtrlBitField.mask,
                                pDivPtr->pDivCtrlBitField.shift);
    while(0 != pDivPtr->pSupportedDivision[index])
    {
        if(pDivPtr->pDividerBitValue[index] == fieldVal)
        {
            divVal = pDivPtr->pSupportedDivision[index];
            break;
        }
        index++;
    }
    return divVal;
}

static float PrcmDpllGetConvVal(prcmDpll_t* pDpllPtr)
{
    float dpllMultFactor = 1;
    uint32_t mult = 1;
    uint32_t divider = 1;
    uint32_t multMask;
    uint32_t multShift;
    uint32_t divMask;
    uint32_t divShift;

    divMask = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                PRCM_ADPLLS_CLKSEL_DIV_MASK : PRCM_ADPLLLJ_CLKSEL_DIV_MASK);
    divShift = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                PRCM_ADPLLS_CLKSEL_DIV_SHIFT : PRCM_ADPLLLJ_CLKSEL_DIV_SHIFT);

    /* Update multiplier */
    multMask = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                PRCM_ADPLLS_CLKSEL_MULT_MASK : PRCM_ADPLLLJ_CLKSEL_MULT_MASK);
    multShift = ((PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType) ? 
                PRCM_ADPLLS_CLKSEL_MULT_SHIFT : PRCM_ADPLLLJ_CLKSEL_MULT_SHIFT);
                    
    mult = HW_RD_FIELD32_RAW(pDpllPtr->pllClkSelRegAddr, multMask, multShift);
    divider = HW_RD_FIELD32_RAW(pDpllPtr->pllClkSelRegAddr, divMask, divShift);
    
    /* Calculate conversion factor - formulae */
    if(PRCM_DPLL_TYPE_ADPLLS == pDpllPtr->dpllType)
    {
        dpllMultFactor = (2*mult)/(divider+1);
    }
    else /* PRCM_DPLL_TYPE_ADPLLLJ */ /* TODO: Update auto-generation */
    {
        dpllMultFactor = (mult)/(divider+1);
    }
    
    /* post divider */
    /* TODO: Get selection from edge prop - M2, M4, M5, M6 etc... */
    
    return dpllMultFactor;
}

static float PrcmGetRootClkRate(prcmRootClk_t* pRootClkPtr)
{
    float clkRate = 0.0;
    uint32_t regFieldVal = 0;
    uint32_t index = 0;
    
    if((PRCM_ROOT_CLK_FREQ_FIXED == pRootClkPtr->rootClkType))
                //&& (pRootClkPtr->maxPossibleRates == 1)) // TODO
    {
        clkRate = pRootClkPtr->pClockRateConfig[0].supportedClockRate;
    }
    else
    {
        // regFieldVal = HW_RD_FIELD32_RAW(pRootClkPtr->pClkCtrlBitField->regAddr, 
                                        // pRootClkPtr->pClkCtrlBitField->mask, 
                                        // pRootClkPtr->pClkCtrlBitField->shift);

        /* TODO: Root clock list no of config values */
        while(1)
        //while(index != pRootClkPtr->maxPossibleRates) // TODO
        {
            if(regFieldVal == pRootClkPtr->pClockRateConfig[index].configValue)
            {
                clkRate= pRootClkPtr->pClockRateConfig[index].supportedClockRate;
                break;
            }
            index++;
        }
    }
    return clkRate;
}

static int32_t PrcmPostDivUpdate(prcmDpll_t* pDpllPtr, 
                    pllPostDivValue_t* postDivValList, uint32_t maxDividers)
{
    uint32_t indexVal = 0;
    uint32_t indexDiv = 0;
    int32_t status = E_FAIL;
    prcmDpllPostDivId_t postDividerId;
    regBitField_t regBitField;
    
    while(indexVal <= maxDividers)
    {
        postDividerId = postDivValList[indexVal].postDivId;
        while(indexDiv <= pDpllPtr->postDividersMax)
        {
            if(postDividerId == pDpllPtr->postDividers[indexDiv].postDivId)
            {
                regBitField = pDpllPtr->postDividers[indexDiv].postDivBitField;
                HW_RD_FIELD32_RAW(regBitField.regAddr, regBitField.mask, 
                                                            regBitField.shift);
                /* TODO: check for updated status */
                break;
            }
            indexDiv++;
        }
        indexVal++;
    }
    if(indexVal > maxDividers)
    {
        status = S_PASS;
    }
    return status;
}
