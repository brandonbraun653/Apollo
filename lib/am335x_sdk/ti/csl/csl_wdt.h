/**
 *   @file  csl_wdt.h
 *
 *   @brief
 *      This is the main header file for the WDT Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002-2011, Texas Instruments, Inc.
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

/** @defgroup CSL_WDT_API WDT
 *
 */

#ifndef CSL_WDTMR_H_
#define CSL_WDTMR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_wdt.h>

/**
@defgroup CSL_WDT_SYMBOL  WDT Symbols Defined
@ingroup CSL_WDT_API
*/
/**
@defgroup CSL_WDT_DATASTRUCT  WDT Data Structures
@ingroup CSL_WDT_API
*/
/**
@defgroup CSL_WDT_FUNCTION  WDT Functions
@ingroup CSL_WDT_API
*/
/**
@defgroup CSL_WDT_ENUM WDT Enumerated Data Types
@ingroup CSL_WDT_API
*/

/**
@addtogroup CSL_WDT_ENUM
@{
*/

/**
 * General purpose global type def declarations
 */

/**
 *  @brief    Enumerates the different prescaler values available for WDT
 *            module.
 */
typedef enum
{
    /**
     * @brief   Minimum value of the enum
     */
    CSL_WDT_PRESCALER_CLK_DIV_MIN,

    /**
     * @brief   WDT functional clock divide by 1
     */
    CSL_WDT_PRESCALER_CLK_DIV_1 = CSL_WDT_PRESCALER_CLK_DIV_MIN,

    /**
     * @brief   WDT functional clock divide by 2
     */
    CSL_WDT_PRESCALER_CLK_DIV_2 = 0x1U,

    /**
     * @brief   WDT functional clock divide by 4
     */
    CSL_WDT_PRESCALER_CLK_DIV_4 = 0x2U,

    /**
     * @brief   WDT functional clock divide by 8
     */
    CSL_WDT_PRESCALER_CLK_DIV_8 = 0x3U,

    /**
     * @brief   WDT functional clock divide by 16
     */
    CSL_WDT_PRESCALER_CLK_DIV_16 = 0x4U,

    /**
     * @brief   WDT functional clock divide by 32
     */
    CSL_WDT_PRESCALER_CLK_DIV_32 = 0x5U,

    /**
     * @brief   WDT functional clock divide by 64
     */
    CSL_WDT_PRESCALER_CLK_DIV_64 = 0x6U,

    /**
     * @brief   WDT functional clock divide by 128
     */
    CSL_WDT_PRESCALER_CLK_DIV_128 = 0x7U,

    /**
     * @brief   Maximum value of the enum
     */
    CSL_WDT_PRESCALER_CLK_DIV_MAX = CSL_WDT_PRESCALER_CLK_DIV_128
} CSL_wdtPrescalerClkDiv;

/**
 *  @brief    Enumerates the values used to represent the WDT interrupts.
 */
typedef enum
{
    /**
     * @brief   WDT overflow interrupt
     */
    CSL_WDT_INTR_MASK_OVERFLOW = CSL_WDT_WIRQENSET_ENABLE_OVF_MASK,

    /**
     * @brief   WDT delay interrupt
     */
    CSL_WDT_INTR_MASK_DELAY = CSL_WDT_WIRQENSET_ENABLE_DLY_MASK
} CSL_wdtIntrMask;

/**
 *  @brief    Enumerates the supported WDT idle modes.
 */
typedef enum
{
    /**
     * @brief   Force Idle mode
     */
    CSL_WDT_IDLE_MODE_FORCE_IDLE = CSL_WDT_WDSC_IDLEMODE_FORCEIDLE,

    /**
     * @brief   No idle mode
     */
    CSL_WDT_IDLE_MODE_NO_IDLE = CSL_WDT_WDSC_IDLEMODE_NOIDLE,

    /**
     * @brief   Smart idle mode
     */
    CSL_WDT_IDLE_MODE_SMART_IDLE = CSL_WDT_WDSC_IDLEMODE_SMARTIDLE,

    /**
     * @brief   Smart idle with wake up mode
     */
    CSL_WDT_IDLE_MODE_SMART_IDLE_WAKEUP =
                                  CSL_WDT_WDSC_IDLEMODE_SMARTIDLEWAKEUP
} CSL_wdtIdleMode;

/**
 *  @brief    Enumerates the values used to represent the WDT write
 *            posted status.
 */
typedef enum
{
    /**
     * @brief   Write pending for register WCLR
     */
    CSL_WDT_WRITE_POST_WCLR = CSL_WDT_WWPS_W_PEND_WCLR_MASK,

    /**
     * @brief   Write pending for register WCRR
     */
    CSL_WDT_WRITE_POST_WCRR = CSL_WDT_WWPS_W_PEND_WCRR_MASK,

    /**
     * @brief   Write pending for register WLDR
     */
    CSL_WDT_WRITE_POST_WLDR = CSL_WDT_WWPS_W_PEND_WLDR_MASK,

    /**
     * @brief   Write pending for register WTGR
     */
    CSL_WDT_WRITE_POST_WTGR = CSL_WDT_WWPS_W_PEND_WTGR_MASK,

    /**
     * @brief   Write pending for register WSPR
     */
    CSL_WDT_WRITE_POST_WSPR = CSL_WDT_WWPS_W_PEND_WSPR_MASK,

    /**
     * @brief   Write pending for register WDLY
     */
    CSL_WDT_WRITE_POST_WDLY = CSL_WDT_WWPS_W_PEND_WDLY_MASK
} CSL_wdtWritePost;

/**
@}
*/

/** @addtogroup CSL_WDT_DATASTRUCT
 @{ */

/**
 * @brief This data type is the handle to the CSL of the RTC
 */
typedef volatile CSL_WdtRegs             *CSL_wdtHandle;

/**
@}
*/

/**
@addtogroup CSL_WDT_SYMBOL
@{
*/

/**
 * @brief     This macro will check for write POSTED status of WDT registers
 *
 * \param     regField         Write posted status register field whose status
 *                             needs to be checked.
 *            regField will take values from the following enum
 *            #CSL_wdtWritePost_t
 */
#define CSL_WDT_WAIT_FOR_WRITE(regField) \
        while(0U != ((hWdt->WWPS) & regField))

#define CSL_WDT_DISABLE_SEQ1           (0x0000AAAAu)
#define CSL_WDT_DISABLE_SEQ2           (0x00005555u)
#define CSL_WDT_ENABLE_SEQ1            (0x0000BBBBu)
#define CSL_WDT_ENABLE_SEQ2            (0x00004444u)

/**
@}
*/

/** @addtogroup CSL_WDT_FUNCTION
 @{ */

/*******************************************************************************
 * Timer global function declarations
 ******************************************************************************/

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif  /* CSL_WDT_H_ */
