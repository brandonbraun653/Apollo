/*
 *   Copyright (c) Texas Instruments Incorporated 2017-2019
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
 *  \file     esm.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of ESM.
 *            This also contains some related macros.
 */

#ifndef CSL_ESM_H
#define CSL_ESM_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdbool.h>

#include <ti/csl/soc.h>
#include <ti/csl/cslr_esm.h>


#ifdef __cplusplus
extern "C" {
#endif

/** 
 *
 * @defgroup CSL_ESM_API ESM (ESM)
 *
 * The Error Signaling Module (ESM) aggregates safety-related events and/or errors from throughout the
 * device into one location. It can signal both low and high priority interrupts to a processor to deal with a
 * safety event and/or manipulate an I/O error pin to signal an external hardware that an error has occurred.
 * Therefore an external controller is able to reset the device or keep the system in a safe, known state.
 *
 * The CSL APIs provide APIs to do the following functionalities.
 *
 * -# API to read back ESM registers
 * -# API to set the ESM error forcing mode
 * -# APIs for ESM initialization sequence/configurations
 * -# APIs for ESM Raw error status
 *
 */
/**
@defgroup CSL_ESM_DATASTRUCT ESM Data Structures
@ingroup CSL_ESM_API
*/
/**
@defgroup CSL_ESM_FUNCTION  ESM Functions
@ingroup CSL_ESM_API
*/
/**
@defgroup CSL_ESM_ENUM ESM Enumerated Data Types
@ingroup CSL_ESM_API
*/

/**
 *  @addtogroup CSL_ESM_ENUM
    @{
 * 
 */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * \brief  ESM Operation Mode type.
 */

#define ESM_NUMBER_OF_GROUP_REGS          (32u)
/**
 * \brief  ESM Operation Mode type.
 */
typedef uint32_t esmOperationMode_t;

/**
 * \brief  defines to select the ESM Operation Mode.
 */
#define ESM_OPERATION_MODE_NORMAL 0x0U
    /**< Configure ESM operation mode to normal mode */
#define ESM_OPERATION_MODE_ERROR_FORCE 0xAu
    /**< Configure ESM operation mode to error force mode */

/**
 * \brief  ESM Interrupt Type to select level for interrupt.
 */
typedef uint32_t esmIntrType_t;

/**
 * \brief  defines for ESM Hardware Requests for interrupt type.
 */

#define ESM_INTR_TYPE_CONFIG_ERROR   (0x0u)
    /**< Configure interrupt to high level interrupt */
#define ESM_INTR_TYPE_LOW_PRIO_ERROR (0x1u)
    /**< Configure interrupt to high level interrupt */
#define ESM_INTR_TYPE_HIGH_PRIO_ERROR (0x2u)
                                   /**< Configure interrupt to low level
                                    * interrupt */
/**
 * \brief  ESM Interrupt Priority Levels.
 */
typedef uint32_t esmIntrPriorityLvl_t;

/**
 * \brief  defines to select level for interrupt.
 */

#define ESM_INTR_PRIORITY_LEVEL_LOW  (0x0u)
    /**< Configure interrupt to low level interrupt */
#define ESM_INTR_PRIORITY_LEVEL_HIGH (0x1u)
    /**< Configure interrupt to highlevel
      * interrupt */

/** @} */

/** 
 *  @addtogroup CSL_ESM_DATASTRUCT
    @{
 *
 */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief  Structure for accessing Revision ID of ESM module.
 */
typedef struct esmRevisionId
{
    uint32_t scheme;
    /**< Scheme */
    uint32_t func;
    /**< Functional number */
    uint32_t rtlRev;
    /**< RTL revision */
    uint32_t major;
    /**< Major revision */
    uint32_t custom;
    /**< Custom revision */
    uint32_t minor;
    /**< Minor revision */
}esmRevisionId_t;

/**
 * \brief  Structure for accessing information register of ESM module.
 */
typedef struct esmInfo
{
    uint32_t lastRstType;
    /**< Last reset type
     *   0 – Last reset was a Power On Reset
     *   1 – Last reset was a Warm Reset
     */
    uint32_t plsGrpNum;
    /**< Number of event groups that are pulse */
    uint32_t lvlGrpNum;
    /**< Number of event groups that are level */
}esmInfo_t;

/**
 * \brief  Structure to access the status of interrupts belonging to a High or
 *         Low priority interrupt.
 */
typedef struct esmGroupIntrStatus
{
    uint32_t highestPendPlsIntNum;
    /**< Indicates what is the highest priority High Priority interrupt
     *  caused by a pulse number.
     */
    uint32_t highestPendLvlIntNum;
    /**< Indicates what is the highest priority High Priority interrupt
     *  caused by a level number.
     */
    uint32_t grpIntrStatus;
    /**< Indicates which Event Groups have one or more interrupts
     *   pending. This register is bit oriented where bit 0 is for
     *   Event Group 0, bit 1 is for Event Group 1, etc…
     *   (bit N is for Event Group N).
     */
}esmGroupIntrStatus_t;

/**
 * \brief  ESM Error Group static registers list.
 */
typedef struct {
    volatile uint32_t RAW;                       /* Config Error Raw Status/Set Register */
    volatile uint32_t INTR_EN_SET;               /* Level Error Interrutp Enable Set Register */
    volatile uint32_t INTR_EN_CLR;               /* Level Error Interrupt Enabled Clear Register */
    volatile uint32_t INT_PRIO;                  /* Level Error Interrupt Enabled Clear Register */
    volatile uint32_t PIN_EN_SET;                /* Level Error Interrupt Enabled Clear Register */
    volatile uint32_t PIN_EN_CLR;                /* Level Error Interrupt Enabled Clear Register */
} CSL_esmRegs_ERR_GRP_STATIC;

/**
 * \brief  ESM static registers list.
 */
typedef struct {
    CSL_esmRegs_ERR_GRP_STATIC ERR_GRP[ESM_NUMBER_OF_GROUP_REGS];
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t INFO;                      /* Info Register */
    volatile uint32_t EN;                        /* Global Enable Register */
    volatile uint32_t ERR_EN_SET;                /* Config Error Interrutp Enable Set Register */
    volatile uint32_t ERR_EN_CLR;                /* Config Error Interrupt Enabled Clear Register */
    volatile uint32_t LOW_PRI;                   /* Low Priority Prioritized Register */
    volatile uint32_t HI_PRI;                    /* High Priority Prioritized Register */
    volatile uint32_t LOW;                       /* Low Priority Interrupt Status Register */
    volatile uint32_t HI;                        /* High Priority Interrupt Status Register */
    volatile uint32_t PIN_CTRL;                  /* Error Pin Control Register */
    volatile uint32_t PIN_CNTR;                  /* Error Counter Value Register */
    volatile uint32_t PIN_CNTR_PRE;              /* Error Counter Value Pre-Load Register */
} CSL_esmStaticRegs;

/** @} */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* None */

/** ===========================================================================
 *  @addtogroup CSL_ESM_FUNCTION
    @{
 * 
 */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API is used to configure operation mode of ESM module.
 * 
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   mode            Channel number for which reset is to be done.
 *                          Refer enum #esmOperationMode_t.
 *
 * \return                  CSL_PASS - API success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       esmOperationMode_t  mode     = ESM_OPERATION_MODE_ERROR_FORCE;
       int32_t             cslRet;
 
       cslRet = ESMSetMode (baseAddr, mode);

   @endverbatim
 *
 */
int32_t ESMSetMode(uint32_t baseAddr, esmOperationMode_t mode);

/**
 * \brief   This API is used to read operation mode of ESM module.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pMode           pointer to variable to hold ESM operation Mode.
 *                          Refer enum #esmOperationMode_t.
 *
 * \return                  CSL_PASS - API success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       esmOperationMode_t  mode;
       uint32_t            cslRet;

       cslRet = ESMGetMode (baseAddr, &mode);

   @endverbatim
 *
 */
int32_t ESMGetMode(uint32_t baseAddr, esmOperationMode_t *pMode);

/**
 * \brief   This API is used to set the influence of interrupt on nERROR pin.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt source which will influence nERROR pin.
 *
 * \param   enable          true: Enables influence on nERROR pin if it is TRUE.
 *                          false:Disables influence on nERROR pin if it is FALSE.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       int32_t             cslRet;
       cslRet =  ESMSetInfluenceOnErrPin (baseAddr, intrSrc, TRUE);

   @endverbatim
 *
 */
int32_t ESMSetInfluenceOnErrPin(uint32_t baseAddr, uint32_t intrSrc,
                             bool enable);

/**
 * \brief   This API is used to get the influence of interrupt on nERROR pin.
 * 
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt source which will influence nERROR pin.
 *
 * \param   pInfluence      pointer to read the influence value
 *                          1: enabled
 *                          0: disabled
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       uint32_t            influence;
       int32_t             cslRet;
       cslRet =  ESMGetInfluenceOnErrPin (baseAddr, intrSrc, &influence);

   @endverbatim
 *
 */
int32_t ESMGetInfluenceOnErrPin(uint32_t baseAddr, uint32_t intrSrc,
                                uint32_t *pInfluence);
/**
 * \brief   This API is used to configure the low time counter pre-load value.
 * 
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   lowTime         Time to be configured as LTCP.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * This is the value that will be pre-loaded in to the counter field of the
 * ESM_PIN_CNTR register whenever the ESM enters the
 * ESM_ERROR state from ESM_IDLE. The default value is
 * determined based on the ESM clock frequency, so that there is a
 * minimum low time of 100 micro seconds.
 * This field is only reset by a Power-On-Reset (not warm reset). A
 * global soft reset will set this field to 0h.
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            pinCntrPre  = 100;
       int32_t             cslRet;
       cslRet = ESMSetErrPinLowTimePreload (baseAddr, pinCntrPre);

   @endverbatim
 *
 */
int32_t ESMSetErrPinLowTimePreload(uint32_t baseAddr, uint32_t lowTime);

/**
 * \brief   This API is used to read the low time counter pre-load value.
 * 
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pLowTime        pointer to Time to be read as LTCP.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * This is the value that will be pre-loaded in to the counter field of the
 * ESM_PIN_CNTR register whenever the ESM enters the
 * ESM_ERROR state from ESM_IDLE. The default value is
 * determined based on the ESM clock frequency, so that there is a
 * minimum low time of 100 micro seconds.
 * This field is only reset by a Power-On-Reset (not warm reset). A
 * global soft reset will set this field to 0h.
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            inCntrPre;
       int32_t             cslRet;
       cslRet = ESMGetErrPinLowTimePreload (baseAddr, &inCntrPre);

   @endverbatim
 *
 */
int32_t ESMGetErrPinLowTimePreload(uint32_t baseAddr, uint32_t *pLowTime);


/**
 * \brief   This API is used to get the current value of low time counter.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pPinCntrPre     pointer to Counter value Current low time count.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            pinCntrPre;
       int32_t             cslRet;
       cslRet  = ESMGetCurrErrPinLowTimeCnt (baseAddr, &pinCntrPre);

   @endverbatim
 *
 */
int32_t ESMGetCurrErrPinLowTimeCnt(uint32_t baseAddr, uint32_t *pPinCntrPre);

/**
 * \brief   This API is used to get the current status of nERROR pin.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pStatus         pointer to Current nERROR pin status.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            status;
       uint32_t            cslRet;
       cslRet = ESMGetErrPinStatus (baseAddr, &status);

   @endverbatim
 *
 */
int32_t ESMGetErrPinStatus(uint32_t baseAddr, uint32_t *pStatus);

/**
 * \brief   This API is used to reset the nERROR pin.
 * 
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \note    This will set the nERROR pin to high.
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       int32_t             cslRet;
       cslRet = ESMResetErrPin (baseAddr);

   @endverbatim
 *
 */
int32_t ESMResetErrPin(uint32_t baseAddr);

/**
 * \brief   This API is used check if interrupt is enabled/disabled.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt to enable.
 *
 * \param   pEnStatus       Pointer to status of interrupt enable variable
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            status, intrNum  = 0u;
       int32_t             cslRet;
       cslRet = ESMIsEnableIntr (baseAddr, intrNum, &status);

   @endverbatim
 *
 */
int32_t ESMIsEnableIntr(uint32_t baseAddr, uint32_t intrSrc, uint32_t *pEnStatus);


/**
 * \brief   This API is used to enable interrupt.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrNum         Interrupt to enable.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrNum  = 0u;
       int32_t             status;
       status = ESMEnableIntr (baseAddr, intrNum);

   @endverbatim
 *
 */
int32_t ESMEnableIntr(uint32_t baseAddr, uint32_t intrNum);

/**
 * \brief   This API is used to disable interrupt.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrNum         Interrupt to disable.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 *
 * \pre
 *   @n  None
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrNum  = 0u;
       int32_t             cslRet;
       cslRet = ESMSetInfluenceOnErrPin (baseAddr, intrNum);

   @endverbatim
 *
 */
int32_t ESMDisableIntr(uint32_t baseAddr, uint32_t intrNum);

/**
 * \brief   This API is used to set interrupt level.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt to set the level.
 *
 * \param   intrPriorityLvl Interrupt level to set.
 *                          Refer enum #esmIntrPriorityLvl_t.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       esmIntrPriorityLvl_t pri     = ESM_INTR_PRIORITY_LEVEL_HIGH;
       int32_t             cslRet;
       cslRet = ESMSetIntrPriorityLvl (baseAddr, intrSrc, pri);

   @endverbatim
 *
 */
int32_t ESMSetIntrPriorityLvl(uint32_t baseAddr, uint32_t intrSrc,
                           esmIntrPriorityLvl_t intrPriorityLvl);

/**
 * \brief   This API is used to get interrupt level.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt to set the level.
 *
 * \param   pIntrPriorityLvl Pointer to Interrupt level to get.
 *                          Refer enum #esmIntrPriorityLvl_t.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       esmIntrPriorityLvl_t            pri;
       int32_t             cslRet;
       cslRet = ESMGetIntrPriorityLvl (baseAddr, intrSrc, &pri);

   @endverbatim
 *
 */
int32_t ESMGetIntrPriorityLvl(uint32_t baseAddr, uint32_t intrSrc,
                              esmIntrPriorityLvl_t *pIntrPriorityLvl);

/**
 * \brief   This API is used to get the interrupt status.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt for which status to return.
 *
 * \param   pStaus          pointer to interrupt status
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            status, intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       int32_t             cslRet;
       cslRet = ESMGetIntrStatus (baseAddr, intrSrc, &status);

   @endverbatim
 *
 */
int32_t ESMGetIntrStatus(uint32_t baseAddr, uint32_t intrSrc, uint32_t *pStaus);

/**
 * \brief   This API is used to set the interrupt RAW status.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt for which status to return.
 *
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       int32_t             cslRet;
       cslRet = ESMSetIntrStatusRAW (baseAddr, intrSrc);

   @endverbatim
 *
 */
int32_t ESMSetIntrStatusRAW(uint32_t baseAddr, uint32_t intrSrc);

/**
 * \brief   This API is used to get the interrupt RAW status.
 * 
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt for which status to return.
 *
 * \param   pStatus         pointer to Interrupt status.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       uitn32_t            status;
       int32_t             cslRet;
       cslRet = ESMGetIntrStatusRAW (baseAddr, intrSrc, &status);

   @endverbatim
 *
 */
int32_t ESMGetIntrStatusRAW(uint32_t baseAddr, uint32_t intrSrc, uint32_t *pStatus);

/**
 * \brief   This API is used to get the interrupt/error status for a group.
 *          This will also return highest pending interrupt for pulse as well
 *          as for level interrupts.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrPrioType    Group for which status to return.
 *                          Refer enum #esmIntrPriorityLvl_t.
 *
 * \param   pIntrstatus     pointer to Interrupt status.
 *                          Refer struct #esmGroupIntrStatus_t.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       esmIntrPriorityLvl  priType  = ESM_INTR_PRIORITY_LEVEL_HIGH;
       esmGroupIntrStatus_t groupIntrStatus;
       int32_t             cslRet;

       cslRet = ESMGetGroupIntrStatus (baseAddr, priType, &groupIntrStatus);

   @endverbatim
 *
 */
int32_t ESMGetGroupIntrStatus(uint32_t baseAddr, esmIntrPriorityLvl_t intrPrioType,
                           esmGroupIntrStatus_t *pIntrstatus);


/**
 * \brief   This API is used to clear the interrupt status.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrSrc         Interrupt to clear status.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 *
 * Note: the intrSrc check is only at the IP level max and not done at instance 
 *       level, so it is expected to be done at higher layer.
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            intrSrc  = CSL_ESM1_INTR_MCU0_CPU0_ECC_CORRECTED_LEVEL;
       int32_t             cslRet;
       cslRet = ESMClearIntrStatus (baseAddr, intrSrc);

   @endverbatim
 *
 */
int32_t ESMClearIntrStatus(uint32_t baseAddr, uint32_t intrSrc);

/**
 * \brief   This API is used to write EOI.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   intrType        Type of interrupt for which to write EOI.
 *                          Refer enum #esmIntrType_t.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       esmIntrType_t       intrType  = ESM_INTR_TYPE_HIGH_PRIO_ERROR;
       int32_t             cslRet;
       cslRet = ESMWriteEOI (baseAddr, intrType);

   @endverbatim
 *
 */
int32_t ESMWriteEOI(uint32_t baseAddr, esmIntrType_t intrType);

/**
 * \brief   This API is used get the ESM revision ID.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pRevId          Pointer to Revision ID of ESM module..
 *                          Refer struct #esmRevisionId_t.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       esmRevisionId_t     revId;
       int32_t             cslRet;
       cslRet = ESMGetRevisionId (baseAddr, &revId);

   @endverbatim
 *
 */
int32_t ESMGetRevisionId(uint32_t baseAddr, esmRevisionId_t *pRevId);

/**
 * \brief   This API is used read the ESM information register.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pInfo           pointer to variable that
 *                          Contains information register contents of ESM module..
 *                          Refer struct #esmInfo_t.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  None
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       esmInfo_t           esmInfo;
       int32_t             cslRet;
       cslRet = ESMGetInfo (baseAddr, &esmInfo);

   @endverbatim
 *
 */
int32_t ESMGetInfo(uint32_t baseAddr, esmInfo_t *pInfo);


/**
 * \brief   This API is used read the ESM information register.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pStatus         pointer to is global Interrupt enabled status
 *                          0h: all interrupts are enabled
 *                          Fh: all interrupts are disabled
 *                         -others: interrupts are in invalid state.Software should never write
 *                          these values. If these values are ever read, they indicate that an
 *                          error has occurred. In this state, all interrupts are enabled (biased to
 *                          false enable).
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  None
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            enStatus;
       int32_t             cslRet;
       cslRet = ESMGetGlobalIntrEnabledStatus (baseAddr, &enStatus);

   @endverbatim
 *
 */
int32_t ESMGetGlobalIntrEnabledStatus(uint32_t baseAddr, uint32_t *pStatus);


/**
 * \brief   This API is used to enable Global control of interrupt.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       int32_t             cslRet;
       cslRet = ESMEnableGlobalIntr (baseAddr);

   @endverbatim
 *
 */
int32_t ESMEnableGlobalIntr(uint32_t baseAddr);

/**
 * \brief   This API is used to disable Global control of interrupt.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  ESM module is reset and initialized for desired operation
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            cslRet;
       cslRet = ESMDisableGlobalIntr (baseAddr);

   @endverbatim
 *
 */
int32_t ESMDisableGlobalIntr(uint32_t baseAddr);

/**
 * \brief   This API is used to reset ESM module.
 *          Reset is used to reset all enables and raw status bits.
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  None
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = CSL_MCU_ESM0_CFG_BASE;
       uint32_t            cslRet;
       cslRet = ESMReset (baseAddr);

   @endverbatim
 *
 */
int32_t ESMReset(uint32_t baseAddr);


/**
 * \brief   This API is used to read static registers of ESM module.
 *          This API needs to be called after the initial configuration is done and
 *          hence mutliple read between static registers do not change the values
 *
 * \param   baseAddr        Base Address of the ESM Registers.
 *
 * \param   pStaticRegs     pointer to static registers to be read
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 * \pre
 *   @n  None
 *
 * \post
 *   @n  None
 *
 * @b Example
   @verbatim

       uint32_t            baseAddr = (uint32_t)CSL_MCU_ESM0_CFG_BASE;
       CSL_esmStaticRegs   staticRegs;
       uint32_t            cslRet;
       cslRet = ESMReadStaticRegs (baseAddr, &staticRegs);

   @endverbatim
 *
 */
int32_t ESMReadStaticRegs (uint32_t baseAddr, CSL_esmStaticRegs *pStaticRegs);

/** @} */

#ifdef __cplusplus
}

#endif /*extern "C" */

#endif
