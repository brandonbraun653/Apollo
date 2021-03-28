/**
 *  \file       cpsw.h
 *
 *  \brief      This file contains the function prototypes for the device
 *              abstraction layer for CPSW subsystem. It also contains some
 *              related macro definitions and some files to be included.
 *
 *              TODO: Programming sequence to be added. Need to see how relevant
 *                    is this for CPSW.
 *              Pending: Following APIs
 *                       - Unknown VLAN configuration.
 *                       - save/restore context
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

#ifndef MLB_H_
#define MLB_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_mailbox.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Type of supported Mailbox idle modes. */
typedef enum mlbIdleMode
{
    MLB_IDLE_MODE_FORCE_IDLE   = MLB_SYSCONFIG_SIDLEMODE_FORCEIDLE,
    /**< Force Idle mode. */
    MLB_IDLE_MODE_NO_IDLE      = MLB_SYSCONFIG_SIDLEMODE_NOIDLE,
    /**< No idle mode. */
    MLB_IDLE_MODE_SMART_IDLE  = MLB_SYSCONFIG_SIDLEMODE_SMARTIDLE
    /**< Smart idle mode. */
}mlbIdleMode_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief    This function resets the mailbox
 *
 *  \param    baseAddr   Memory address of the mailbox instance used.
 */
void MLBReset(uint32_t baseAddr);

/**
 *  \brief   This function configures the idle mode of the mailbox
 *
 * \param     baseAddr  Memory address of the mailbox instance used.
 * \param     idleMode  Idle mode of the module to be configured.
 *                      idleMode can take macros from the following enum
 *                      - #mlbIdleMode_t
 */
void MLBSetIdleMode(uint32_t baseAddr, uint32_t idleMode);

/**
 *  \brief   This function gets the first message in the queue
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     queueId   Queue to be read
 *  \param     *msgPtr   Message pointer in which the message will be returned
 *
 *  \retval    S_PASS    Message read successfully.
 *  \retval    E_FAIL    Message read failed.
 */
int32_t MLBGetMessage(uint32_t baseAddr, uint32_t queueId, uint32_t *pMessage);

/**
 *  \brief   This function writes message in the queue
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     queueId   Queue to be written
 *  \param     msg       Message which has to be sent
 *
 *  \retval    S_PASS    Message written successfully.
 *  \retval    E_FAIL    Message queue is full.
 */
uint32_t MLBMessageSend(uint32_t baseAddr, uint32_t queueId, uint32_t message);

/**
 *  \brief   This function enables the new message interrupt for a user for given queue
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     userId    User for whom the new meaasge should be intimated
 *  \param     queueId   Queue to be monitored for new message
 *  \param     enableNewMessageIntr Flag value to control enabling/disabling of new
 *             message interrupt. It can take any of the two macro values.
 *             - TRUE to indicate enabling new message Interrupt
 *             - FALSE to indicate disabling new message Interrupt
 */
void MLBNewMessageIntrEnable(uint32_t baseAddr,
                             uint32_t userId,
                             uint32_t queueId,
                             uint32_t enableNewMessageIntr);

/**
 *  \brief   This function enables the queue not full interrupt for a user for given queue
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     userId    User for whom the event should be intimated
 *  \param     queueId   Queue to be monitored for non-full condition
 *  \param     enableNotFullIntr Flag value to control enabling/disabling of queue
 *             not full interrupt. It can take any of the two macro values.
 *             - TRUE to indicate enabling queue not full interrupt.
 *             - FALSE to indicate disabling queue not full interrupt.
 */
void MLBNotFullIntrEnable(uint32_t baseAddr,
                          uint32_t userId,
                          uint32_t queueId,
                          uint32_t enableNotFullIntr);

/**
 *  \brief   This function gets the new message status
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     userId    User for whom the event should be checked
 *  \param     queueId   Queue for  which the event should be checked
 *
 *  \retval    status    status of new message
 */
uint32_t MLBNewMessageIntrStatus(uint32_t baseAddr,
                                 uint32_t userId,
                                 uint32_t queueId);

/**
 *  \brief     This function gets the queue not-full status.
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     userId    User for whom the event should be checked
 *  \param     queueId   Queue for  which the event should be checked
 *
 *  \retval   status    Queue not full status
 */
uint32_t MLBNotFullIntrStatus(uint32_t baseAddr,
                              uint32_t userId,
                              uint32_t queueId);

/**
 *  \brief     This function clears the queue not-full status
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     userId    User for whom the event should be cleared
 *  \param     queueId   Queue for  which the event should be cleared
 *
 */
void MLBNewMessageIntrClr(uint32_t baseAddr,
                          uint32_t userId,
                          uint32_t queueId);

/**
 *  \brief   This function clears the queue not-full status
 *
 * \param     baseAddr  Memory address of the mailbox instance used.
 * \param     userId    User for whom the event should be cleared
 * \param     queueId   Queue for  which the event should be cleared
 *
 */
void MLBNotFullIntrClr(uint32_t baseAddr,
                       uint32_t userId,
                       uint32_t queueId);

/**
 *  \brief     This function sets the event for new message Interrupt.
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     userId    User for whom the event should be checked
 *  \param     queueId   Queue for  which the event should be checked
 *
 *  \retval    status    status of new message
 */
void MLBSetRawNewMessageIntrStatus(uint32_t baseAddr,
                                   uint32_t userId,
                                   uint32_t queueId);

/**
 *  \brief     This function sets the event for queue not full Interrupt.
 *
 *  \param     baseAddr  Memory address of the mailbox instance used.
 *  \param     userId    User for whom the event should be checked
 *  \param     queueId   Queue for  which the event should be checked
 *
 */
void MLBSetRawNotFullIntrStatus(uint32_t baseAddr,
                                uint32_t userId,
                                uint32_t queueId);

/* ========================================================================== */
/*                        Deprecated Function Declarations                    */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef MLB_H_ */
