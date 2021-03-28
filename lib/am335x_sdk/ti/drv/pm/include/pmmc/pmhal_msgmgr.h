/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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
 *  \file  pmhal_msgmgr.h
 *
 *  \brief This file contains the MSGMGR interface declarations.
 */

#ifndef PMHAL_MSGMGR_H_
#define PMHAL_MSGMGR_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief MSGMGR Global Config revision register address */
#define MSGMGR_GBL_CFG_REV_REG   (CSL_MESSAGEMANAGER_0_CFG4_REGS + \
                                  CSL_MSGMGRGLOBAL_REVISION_REG)
/** \brief MSGMGR Global Config revision register expected value */
#define MSGMGR_GBL_CFG_REV       (0x4E641900U)

/** \brief MSGMGR Maximum transferable data bytes */
#define MSGMGR_MESSAGE_MAX_BYTES (64U)
/** \brief MSGMGR Maximum transferable 32-bit data words */
#define MSGMGR_MESSAGE_MAX_WORDS (MSGMGR_MESSAGE_MAX_BYTES/sizeof(uint32_t))

#if defined (__ARM_ARCH_7A__)
/********* ARM MSGMGR Proxy and Queue Definitions *********/

/** \brief ARM MSGMGR Proxy */
#define MSGMGR_PROXY             (2U)

/** \brief ARM MSGMGR TX Queue to PMMC */
#define MSGMGR_TX_PMMC_QUEUE     (0U)
/** \brief ARM MSGMGR RX Queue */
#define MSGMGR_RX_PMMC_QUEUE     (5U)

#elif defined (_TMS320C6X)
/********* DSP MSGMGR Proxy and Queue Definitions *********/

/** \brief DSP MSGMGR Proxy */
#define MSGMGR_PROXY             (1U)

/** \brief DSP MSGMGR TX Queue to PMMC */
#define MSGMGR_TX_PMMC_QUEUE     (0U)
/** \brief DSP MSGMGR RX Queue */
#define MSGMGR_RX_PMMC_QUEUE     (4U)

#else
#error "MSGMGR not valid for processor"
#endif

/** \brief MSGMGR first data register offset */
#define MSGMGR_DATA_REGS_START   (16)
/** \brief MSGMGR last data register offset.  Also, used for MSGMGR push/pop
 *         operation */
#define MSGMGR_DATA_REGS_END     (31)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                      Global Variables Declarations                         */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Function to initialize the MSGMGR interface
 *
 * \param   None.
 *
 * \return  status  PM_SUCCESS If init completes successfully
 *                  PM_FAIL If init fails
 */
pmErrCode_t PMHALMsgmgrInit(void);

/**
 * \brief   Function to write message to Message Manager proxy
 *
 * \param   proxy   Proxy to write
 *
 * \param   queue   Queue within proxy to write
 *
 * \param   data    Pointer to data
 *
 * \param   size    Size of data in bytes
 *
 * \return  status  PM_SUCCESS If write completes successfuly
 *                  PM_MSGMGR_INVALID_MSG_FORMAT If write fails
 */
pmErrCode_t PMHALMsgmgrWrite(uint32_t proxy, uint32_t queue, uint32_t *data,
                             uint32_t size);

/**
 * \brief   Function to poll a Message Manager proxy for a pending message
 *
 * \param   proxy   Proxy to poll for message
 *
 * \param   queue   Queue within proxy to poll for message
 *
 * \param   timeout Polling timeout
 *
 * \return  status  PM_SUCCESS If message detected in proxy queue
 *                  PM_FAIL    If polling timed out
 */
pmErrCode_t PMHALMsgmgrPoll(uint32_t proxy, uint32_t queue, uint32_t timeout);

/**
 * \brief   Function to read message from Message Manager proxy
 *
 * \param   proxy   Proxy to read
 *
 * \param   queue   Queue within proxy to read
 *
 * \param   data    Pointer to data array where read data will be stored
 *
 * \param   size    Size of data array in bytes
 *
 * \return  status  PM_SUCCESS If read completes successfuly
 *                  PM_MSGMGR_INVALID_MSG_FORMAT If read fails
 */
pmErrCode_t PMHALMsgmgrRead(uint32_t proxy, uint32_t queue, uint32_t *data,
                            uint32_t size);

#ifdef __cplusplus
}
#endif

#endif

