/**
 *  \file     dmtimer.h
 *
 *  \brief    DMTIMER API prototypes and macros.
 *            This file contains the dal API prototypes and macro definitions 
 *            which interact directly with the dmtimer hardware registers.This 
 *            file provides APIs to initialise configure and use dmtimer . The 
 *            user is required to enable the clock to the dmtimer module through 
 *            the Control Module before attempting to use APIS listed here.
 *
 *  \details  Programming sequence of dmtimer module is as follows:
 *            -# Enable dmtimer module in PRCM module by using PRCM APIs
 *            -# Select the parent of a node (multiplexer) in the clock tree
 *               using PRCM APIs, else default reset value of CLK_M_OSC is 
 *               chosen as input frequency. 
 *            -# Configure dmtimer interrupts - register dmtimer Interrupt Service
 *               routine with the interrupt controller.
 *            -# Reset dmtimer module through the API
 *               #DMTIMERReset.
 *            -# Load the initial Count and reload values in timer registers using
 *               #DMTIMERSetCounterVal and #DMTIMERLoadReloadCount APIs  
 *            -# Configure the mode of the timer through the API
 *               #DMTIMERSetMode   
 *            -# Enable and configure Prescaler if required using the API
 *               #DMTIMERPrescalerClkEnable
 *            -# Enable dmtimer module interrupts through the API 
 *               #DMTIMERIntrEnable 
 *            -# Enable or run the timer through the API
 *               #DMTIMEREnable
 *            To configure and use interrupts use the following APIs
 *            -# To enable interrupts use #DMTIMERIntrEnable  
 *            -# To disable interrupts use  #DMTIMERIntrDisable                
 *            -# To clear interrupt registers use  #DMTIMERIntrClear 
 *            -# To Get current pending interrupts use  #DMTIMERIntrStatus  
 *  
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 */
/*
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistribution of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistribution in binary form must reproduce the above copyright
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

 #ifndef DMTIMER_H_
 #define DMTIMER_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "hw_dmtimer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define DMTimerModeConfigure          DMTIMERSetMode
#define DMTimerPreScalerClkEnable     DMTIMERPrescalerClkEnable
#define DMTimerPreScalerClkDisable    DMTIMERPrescalerClkDisable
#define DMTimerCounterSet             DMTIMERSetCounterVal
#define DMTimerCounterGet             DMTIMERGetCounterVal
#define DMTimerReloadSet              DMTIMERLoadReloadCount
#define DMTimerReloadGet              DMTIMERGetReloadCount
#define DMTimerGPOConfigure           DMTIMERGpoConfig
#define DMTimerCompareSet             DMTIMERSetCompareVal
#define DMTimerCompareGet             DMTIMERGetCompareVal
#define DMTimerIntRawStatusSet        DMTIMERIntrTrigger
#define DMTimerIntRawStatusGet        DMTIMERIntrRawStatus
#define DMTimerIntStatusGet           DMTIMERIntrStatus
#define DMTimerIntStatusClear         DMTIMERIntrClear
#define DMTimerIntEnable              DMTIMERIntrEnable
#define DMTimerIntDisable             DMTIMERIntrDisable
#define DMTimerTriggerSet             DMTIMERTriggerTcrrWrite
#define DMTimerIntEnableGet           DMTIMERGetIntrEnableStatus
#define DMTimerResetConfigure         DMTIMERResetEnable
#define DMTimerReset                  DMTIMERReset
#define DMTimerContextSave            DMTIMERContextSave
#define DMTimerContextRestore         DMTIMERContextRestore
#define DMTimerPostedModeConfig       DMTIMERPostedModeEnable
#define DMTimerWritePostedStatusGet   DMTIMERGetWritePostedStatus
/* ========================================================================== */
/*                           Macros                                           */
/* ========================================================================== */
/*None*/
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
** \brief Enumarates the supported interrupt status flags supported by dmtimer.
*
*         Any combination is also followed.
*         Example- (DMTIMER_INTR_MASK_TCAR |
*                   DMTIMER_INTR_MASK_OVF)
*/
typedef enum dmtimerIntrMask
{
    DMTIMER_INTR_MASK_TCAR   = (DMTIMER_IRQSTS_RAW_TCAR_IT_FLAG_MASK),
    /**< Value used for capture event interrupt mask of DMTIMER. */
    DMTIMER_INTR_MASK_OVF    = (DMTIMER_IRQSTS_RAW_OVF_IT_FLAG_MASK),
    /**< Value used for overflow event interrupt mask of DMTIMER. */
    DMTIMER_INTR_MASK_MAT    = (DMTIMER_IRQSTS_RAW_MAT_IT_FLAG_MASK)
    /**< Value used for Match event of interrupt mask DMTIMER. */
}dmtimerIntrMask_t;

/**
 *  \brief Enumerates the prescaler clock divider ratios
 *
 */
typedef enum dmtimerPrescalerClkDivRatio
{
    DMTIMER_PRESCALER_CLK_DIV_RATIO_MIN       = 0U,
    /**< Min value of divider ratio .Used for input validation. */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_2         =
        DMTIMER_PRESCALER_CLK_DIV_RATIO_MIN,
    /**< Value used to divide timer clock by 2. */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_4         = 1U,
    /**< Value used to divide timer clock by 4.  */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_8         = 2U,
    /**<Value used to divide timer clock by 8.   */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_16        = 3U,
    /**< Value used to divide timer clock by 16. */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_32        = 4U,
    /**< Value used to divide timer clock by 32. */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_64        = 5U,
    /**< Value used to divide timer clock by 64. */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_128       = 6U,
    /**< Value used to divide timer clock by 128. */
    DMTIMER_PRESCALER_CLK_DIV_RATIO_256       = 7U,
    DMTIMER_PRESCALER_CLK_DIV_RATIO_MAX       =
        DMTIMER_PRESCALER_CLK_DIV_RATIO_256
    /**< Max value of divider ratio .Used for input validation. */
}dmtimerPrescalerClkDivRatio_t;

/**
 *  \brief Enumerates dmtimer operational modes
 *
 */
typedef enum dmtimerModeCfg
{
    DMTIMER_MODE_CFG_ONESHOT_CMP_ENABLE        = 1U,
    /**< Value used to enable the timer in one-shot and compare enabled mode */
    DMTIMER_MODE_CFG_ONESHOT_CMP_DISABLE       = 2U,
    /**< Value used to enable the timer only in one-shot mode. */
    DMTIMER_MODE_CFG_AUTORLD_CMP_ENABLE        = 3U,
    /**< Value used to enable the timer in auto-reload and compare mode. */
    DMTIMER_MODE_CFG_AUTORLD_CMP_DISABLE       = 4U
    /**< Value used to enable the timer only in auto-reload mode. */

}dmtimerMode_t;

/**
 *  \brief Enumerates GPO configuration values.
 *
 */
typedef enum dmtimerGpoCfg
{
    DMTIMER_GPO_CFG_DRIVE0        = (DMTIMER_TCLR_GPO_CFG_DRIVE0),
    /**< Value used to drive 0 on PORGPOCFG pin.*/
    DMTIMER_GPO_CFG_DRIVE1        = (DMTIMER_TCLR_GPO_CFG_DRIVE1)
    /**<Value used to drive 1 on PORGPOCFG pin. */
}dmtimerGpoCfg_t;

/**
* \brief Structure to store the DM timer context
*/
typedef struct dmtimerContext
{
    uint32_t tldr;
    /**< saved value of load register .*/
    uint32_t tmar;
    /**< saved value of Match register .*/
    uint32_t irqenableset;
    /**< saved value of irqenableset register .*/
    uint32_t tcrr;
    /**< saved value of Counter register .*/
    uint32_t tclr;
    /**< saved value of control register .*/
}dmtimerContext_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API will start/stop the timer.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   enableDmtimer   Value controlling the enabling/ disabling of dmtimer
 *                          module. This can take following values:
 *          - TRUE  - dmtimer module is started.
 *          - FALSE -  dmtimer module is stopped.
 * \note    The timer must be configured before it is started/enabled.
 */
 void DMTIMEREnable(uint32_t baseAddr, uint32_t enableDmtimer);

/**
 * \brief   This API will configure the timer in combinations of
 *          'One Shot timer' and 'Compare' Mode or 'Auto-reload timer'
 *          and 'Compare' Mode.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   modeCfg         Mode for enabling the timer.
 *
 *          'modeCfg' can take the following values
 *          - #dmtimerMode_t
 */
 void DMTIMERSetMode(uint32_t baseAddr, dmtimerMode_t modeCfg);

 /**
 * \brief   This API will configure and enable the pre-scaler clock.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   dividerRatio    Pre-scale clock Timer value.
 *
 *          'dividerRatio' can take the following values
 *          - #dmtimerPrescalerClkDivRatio_t
 */
 void DMTIMERPrescalerClkEnable(uint32_t baseAddr, uint32_t dividerRatio);

 /**
 * \brief   This API will disable the pre-scaler clock.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 */
 void DMTIMERPrescalerClkDisable(uint32_t baseAddr);

 /**
 * \brief   Set/Write the Counter register with the counter value.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   counter         Count value for the timer.
 *
 * \note    Value can be loaded into the counter register when the counter is
 *          stopped or when it is running.
 */
 void DMTIMERSetCounterVal(uint32_t baseAddr, uint32_t counter);

 /**
 * \brief   Get/Read the counter value from the counter register.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 *
 * \retval  DMTIMER_TCRR_value This API returns the count value present
 *          in the DMTIMER Counter register.
 *
 * \note    Value can be read from the counter register when the counter is
 *          stopped or when it is running.
 */
 uint32_t DMTIMERGetCounterVal(uint32_t baseAddr);

 /**
 * \brief   Set the reload count value in the timer load register.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   reload          The reload count value of the timer.
 *
 * \note    It is recommended to not use reload value as 0xFFFFFFFF as it can
 *          lead to undesired results.
 */
 void DMTIMERLoadReloadCount(uint32_t baseAddr, uint32_t reload);

 /**
 * \brief   Get the reload count value from the timer load register.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 *
 * \retval  DMTIMER_TLDR_value This API returns the value present in
 *          DMTIMER Load Register.
 */
 uint32_t DMTIMERGetReloadCount(uint32_t baseAddr);

 /**
 * \brief   Configure general purpose output pin.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   gpoCfg          General purpose output.
 *
 *          'gpoCfg' can take the following values
 *          - #dmtimerGpoCfg_t
 */
 void DMTIMERGpoConfig(uint32_t baseAddr, uint32_t gpoCfg);

 /**
 * \brief   Set the match register with the compare value.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   compareVal      Compare value.
 */
 void DMTIMERSetCompareVal(uint32_t baseAddr, uint32_t compareVal);

 /**
 * \brief   Get the match register contents.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 *
 * \retval  DMTIMER_TMAR_value This API returns the match register contents.
 */
 uint32_t DMTIMERGetCompareVal(uint32_t baseAddr);

 /**
 * \brief   Trigger IRQ event in Software by setting the IRQ raw status registers.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   intrMask        Variable used to trigger the events.
 *
 *          'intrMask' can take the following values
 *          -#dmtimerIntrMask_t
 */
 void DMTIMERIntrTrigger(uint32_t baseAddr, uint32_t intrMask);

 /**
 * \brief   Return the status of IRQSTATUS_RAW register.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 *
 * \retval  DMTIMER_IRQSTS_RAW_value This API returns the contents of
 *          IRQSTATUS_RAW register.
 */
 uint32_t DMTIMERIntrRawStatus(uint32_t baseAddr);

 /**
 * \brief   Return the status of IRQ_STATUS register.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 *
 * \retval  DMTIMER_IRQSTS_value This API returns the status of IRQSTATUS
 *          register.
 */
 uint32_t DMTIMERIntrStatus(uint32_t baseAddr);

 /**
 * \brief   Clear the status of interrupt events.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   intrMask        Variable used to clear the events.
 *
 *          'intrMask' can take the following values
 *          -#dmtimerIntrMask_t
 */
 void DMTIMERIntrClear(uint32_t baseAddr, uint32_t intrMask);

 /**
 * \brief   Enable the DMTIMER interrupts.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   intrMask        Variable used to enable the interrupts.
 *
 *          'intrMask' can take the following values
 *          -#dmtimerIntrMask_t
 */
 void DMTIMERIntrEnable(uint32_t baseAddr, uint32_t intrMask);

 /**
 * \brief   Disable the DMTIMER interrupts.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   intrMask        Variable used to disable the interrupts.
 *
 *          'intrMask' can take the following values
 *          -#dmtimerIntrMask_t
 */
 void DMTIMERIntrDisable(uint32_t baseAddr, uint32_t intrMask);

 /**
 * \brief   Set/enable the trigger write access.
 *
 * \param   baseAddr       Base Address of the DMTIMER Module Register.
 *
 *
 * \note    When we have enabled the timer in Auto-reload mode, the value from
 *          TLDR is reloaded into TCRR when a overflow condition occurs. But if
 *          we want to load the contents from TLDR to TCRR before overflow
 *          occurs then call this API.
 */
 void DMTIMERTriggerTcrrWrite(uint32_t baseAddr);

 /**
 * \brief   Read the status of IRQENABLE_SET register.
 *
 * \param   baseAddr       Base Address of the DMTIMER Module Register.
 *
 * \retval  DMTIMER_IRQEN_SET_value This API returns the status of
 *          IRQENABLE_SET register.
 */
 uint32_t DMTIMERGetIntrEnableStatus(uint32_t baseAddr);

 /**
 * \brief   Enable/Disable software reset for DMTIMER module.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   enableReset       Enable/Disable reset option for DMTIMER.
 *
 *          'enableReset' can take the following values
 *          - #dmtimerResetConfig_t
 */
 void DMTIMERResetEnable(uint32_t baseAddr, uint32_t enableReset);

 /**
 * \brief   Reset the DMTIMER module.
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 */
 void DMTIMERReset(uint32_t baseAddr);

 /**
 * \brief   This API stores the context of the DMTIMER
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   pContextPtr     Pointer to the structure where the DM timer context
 *                          need to be saved.
 */
 void DMTIMERContextSave(uint32_t baseAddr, dmtimerContext_t *pContextPtr );

 /**
 * \brief   This API restores the context of the DMTIMER
 *
 * \param   baseAddr        Base Address of the DMTIMER Module Register.
 * \param   pContextPtr     Pointer to the structure where the DM timer context
 *                          need to be restored from.
 */
 void DMTIMERContextRestore(uint32_t baseAddr, dmtimerContext_t *pContextPtr );

 /**
 * \brief   Configure the posted mode of DMTIMER.
 *
 * \param   baseAddr         Base Address of the DMTIMER Module Register.
 * \param   enablePostedMode TRUE  - posted mode active
 *                           FALSE - posted mode is inactive 
 *       
 */
 void DMTIMERPostedModeEnable(uint32_t baseAddr, uint32_t enablePostedMode);

 /**
 * \brief   Read the status of Write Posted Status register.
 *
 * \param   baseAddr    Base Address of the DMTIMER Module Register.
 *
 * \retval  DMTIMER_TWPS_value  This API returns the status of TWPS register.
 */
 uint32_t DMTIMERGetWritePostedStatus(uint32_t baseAddr);

/* @} */

#ifdef __cplusplus
}
#endif

#endif/* inclusion guard ends here*/
