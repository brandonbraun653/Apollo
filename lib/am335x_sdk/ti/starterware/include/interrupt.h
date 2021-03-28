/**
 *  \file   interrupt.h
 *
 *  \brief  Generic interrupt API's prototype are declared in this file.
 *
 *   These API's abstract the actual interrupt controller functions to handle 
 *   variations between different interrupt controllers. API's are provided for
 *   the following functionalities.
 *       - Initialize Interrupt controller
 *       - Enable interrupt: (register isr, set priority, trigger type
 *             set secure/NS mode, set target CPU core, enable interrupt).
 *             Note: Enables the interrupt in Interrupt controller and CPU. 
 *             The interrupt at peripheral level will not be enabled by this 
 *             API and should be enabled by the corresponding device driver.
 *       - Disable interrupt: Disables the interrupt in Interrupt controller 
 *             and not in the CPU core.
 *       - CPU core interrupt enable/disable (shall be used to enable critical 
 *             section)
 *       - Clear interrupt: For some interrupt controllers the interrupt has 
 *             to be explicitly cleared. For others this will be dummy call. 
 *             This API will not clear the interrupt in peripheral.
 *       - Save and Restore Interrupt controller context
 *       - Software Trigger interrupt (sets interrupt in pending register).
 *             Clearing of these interrupts is similar to other interrupts.
 *       - Get interrupt pending status (if the interrupt is disabled or 
 *             blocked by high priority interrupt)
 *       - IPC interrupt - Trigger IPC (interprocessor communication) interrupt
 *             to another core.
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

#ifndef INTERRUPT_H
#define INTERRUPT_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Macro to set Interrupts for SECURE mode */
#define INTC_SECURE_MODE                    (1U)

/** \brief Macro to set Interrupts for Non-Secure mode */
#define INTC_NON_SECURE_MODE                (0U)

/** Note: The below macro group is applicable for ARM only. For other 
    architectures corresponding macros shall be defined as needed. 
    Using wrong macro for in an arch will result in an error. */

/**
 * @defgroup INTR_ARM_CPU  Interrupt macros for ARM architecture.
 *
 * @{
 */
    /** \brief Macro to mask for IRQ interrupt */
    #define INTC_ARM_IRQ_MASK                     (0x80U)
    
    /** \brief Macro to mask for FIQ interrupt */
    #define INTC_ARM_FIQ_MASK                     (0x40U)
    
    /** \brief Macro to mask for both IRQ and FIQ interrupts */
    #define INTC_ARM_IRQ_FIQ_MASK                 (0xC0U)
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/**
 *  \brief Enumerates the types different trigger types.
 */
typedef enum intcTrigType
{
    INTC_TRIG_HIGH_LEVEL,     /**< High Level */
    INTC_TRIG_LOW_LEVEL,      /**< Low Level */
    INTC_TRIG_RISING_EDGE,    /**< Rising edge */ 
    INTC_TRIG_FALLING_EDGE,   /**< Falling edge */
    INTC_TRIG_BOTH_EDGE       /**< Both edge */
} intcTrigType_t;


/**
 *  \brief Structure defining parameters to configure an interrupt.
 */
typedef struct
{
    intcTrigType_t triggerType;    /**< Trigger type */
    uint32_t   priority;       
    /**< Priority of the interrupt. In some processors not all values of 
         priorities are supproted. If invalid priority value is passed an error 
         status ("E_INVALID_PARAM") will be returned.
	 For Eg: In AM43xx for, 
		    Non-secure mode the valid values are 0,16,32,....240 and
                    Secure mode the valid values are 0,8,16,32,....248.
    */
    void (*pFnIntrHandler)(uint32_t intrId, uint32_t cpuId, void* pUserParam);
                               /**< Interrupt handler */
    void *pUserParam;  /**< Parameter to be passed to the handler function */
    uint32_t isIntrSecure;   /**< Is this a secure interrupt (not CPU secure 
	                              state). */
#if SMP_ENABLED
    uint32_t targetCpu;  /**< Which CPU to interrupt- in a multi proc system */
#endif
}intcIntrParams_t;


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Initialize the interrupt controller. This API identifies the SOC 
 *          and the corresponding interrupt controller and accordingly calls 
 *          the corresponding driver API's.
 *
 *  Note:   This API abstracts some of the configuration parameters from the user
 *          and initializes with default configuration. This will help novice user
 *          to get started quickly. Advanced users can modify these default
 *          configuration as per their need.
 *
 * \param   isCpuSecure   Flag to indicate if the CPU is in secure state. The 
 *                        validity of this parameter will not be checked, so 
 *                        user need to pass right value, otherwise unexpected 
 *                        behaviour may occur.
 *
 * \retval  status   Any of the following values, 
 *          - S_PASS - Controller is initialized successfully
 *          - E_FAIL - Initialization failed
 *          - E_INVALID_PARAM - Parameter passed is invalid
 **/
int32_t INTCInit(uint32_t isCpuSecure);


/**
 * \brief   This function initializes the following properties and enables an 
 *          interrupt.
 *            - Configures trigger type
 *            - Set the priority of the interrupt
 *            - Register the interrupt handler
 *            - Sets target processor in multi proc systems 
 *
 * \param   intrNum       Interrupt number which identifies as specific event 
 *                        as specified by the processor.
 *
 * \param   pIntrParams   Parameters to configure interrupt
 *                          #intcIntrParams_t
 *
 * \param   isCpuSecure   Flag to indicate if the CPU is in secure state. The 
 *                        validity of this parameter will not be checked, so 
 *                        user need to pass right value, otherwise unexpected 
 *                        behaviour may occur.
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Configured and enabled successfully
 *          - E_FAIL - Configuration failed
 *          - E_INTR_NOT_SUPP - Interrupt number passed is not supported
 *          - E_INVALID_PARAM - Parameter passed is invalid
 **/
int32_t INTCConfigIntr(uint32_t intrNum, intcIntrParams_t *pIntrParams, 
                                                         uint32_t isCpuSecure);

                                                        
/**
 * \brief   This API enables an interrupt. It will not do any other 
 *          configuration of an interupt.
 *
 * \param   intrNum      - Iterrupt number
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Intr enabled successfully
 *          - E_INTR_NOT_SUPP - Interrupt number passed is not supported
 **/
int32_t INTCEnableIntr(uint32_t intrNum);


/**
 * \brief   This function disables the interrupt in interrupt controller and 
 *          un-register the handler. It will not disable the CPU core interrupt
 *          as other interrupts might still be enabled.
 *
 * \param   intrNum  - Interrupt to be disabled
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Interrupt is disabled
 *          - E_INTR_NOT_SUPP - Interrupt number passed is not supported
 **/
int32_t INTCDisableIntr(uint32_t intrNum);


/**
 * \brief   This function enables the CPU core interrupt. This is a global 
 *          mask for all the interrupts. Only after enabling this all the 
 *          interrupts from intr controller will be recognized.
 *
 * \param   intrType - interrupt type. Valid value specific to the architecture 
 *                     need to be provided. If incorrect value is passed it 
 *                     will result in error.
 *
 *           eg: in ARM IRQ/FIQ, any of the below values can be passed
 *	                INTC_ARM_IRQ_MASK - enable IRQ
 *			INTC_ARM_FIQ_MASK - enable FIQ
 *			INTC_ARM_IRQ_FIQ_MASK - enable both IRQ & FIQ
 *
 * \retval  status   Any of the following values, 
 *           - S_PASS - Interrupt is enabled
 *           - E_INVALID_PARAM - Parameter passed is invalid
 **/
int32_t INTCEnableCpuIntr(uint32_t intrType);


/**
 * \brief   This function disables the CPU core interrupt. After disabling the 
 *          core interrupt the interrupt from intr controller will not be 
 *          recognized.
 *
 * \retval   pPrevintrConf - previous interrupt config.
 *           eg: Possible values in ARM are,
 *	                INTC_ARM_IRQ_MASK
 *			INTC_ARM_FIQ_MASK
 *			INTC_ARM_IRQ_FIQ_MASK
 **/
uint32_t INTCDisableCpuIntr(void);


/**
 * \brief   This function clears the interrupt in intr controller. Some 
 *          interrupt controllers clear the interrupt once they are recognized 
 *          by the CPU, in those cases this will be a dummy call. This API 
 *          will not clear the interrupt in peripheral and has to cleared by 
 *          the corresponding driver.
 *
 * \param   intrNum  - Interrupt to be cleared
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Interrupt is cleared
 *          - E_FAIL - Interrupt cannot be cleared
 *          - E_INTR_NOT_SUPP - Interrupt number passed is not supported
 **/
int32_t INTCClearIntr(uint32_t intrNum);

/**
 * \brief   This function triggers the interrupt by writing to pending 
 *          register. Clearing of these interrupts is similar to other 
 *          interrupts. This can be used to simulate peripheral interrupt.
 *
 * \param   intrNum  - Interrupt to be triggered via software
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Interrupt is triggered
 *          - E_FAIL - Interrupt cannot be triggerd
 *          - E_INTR_NOT_SUPP - Interrupt number passed is not supported
 **/
int32_t INTCTriggerSWIntr(uint32_t intrNum);


/**
 * \brief   This function triggers the IPC interrupt via Software. Clearing 
 *          of these interrupts is similar to other interrupts. This can be 
 *          used for interprocessor synchronization.
 *
 * \param   intrNum  - Interrupt to be triggered
 * \param   cpuId    - CPU to which the interrupt to be triggered
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Interrupt is triggered
 *          - E_FAIL - Interrupt cannot be triggerd
 *          - E_INTR_NOT_SUPP - Interrupt number passed is not supported
 *          - E_INVALID_PARAM - CPU id is invalid
 **/
int32_t INTCTriggerIPCIntr(uint32_t intrNum, uint32_t cpuId);

/**
 * \brief   This function saves the intr controller context before entering 
 *          low power state.
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Context is saved
 *          - E_FAIL - Context is not saved
 **/
int32_t INTCSaveContext(void);


/**
 * \brief   This function restores the intr controller context while waking up
 *          from low power state.
 *
 * \retval   status   Any of the following values, 
 *          - S_PASS - Context is restored
 *          - E_FAIL - Context is not restored
 **/
int32_t INTCRestoreContext(void);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef INTERRUPT_H */
