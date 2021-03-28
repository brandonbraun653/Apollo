/*
 * Copyright (C) 2010-2016 Texas Instruments Incorporated - http://www.ti.com/
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

/*******************************************************************************
* FILE PURPOSE: Test Application Header Local Definitions
*
********************************************************************************
* FILE NAME:    test_loc.h
*
* DESCRIPTION:  This file contains all Local definitions for EMAC test application.
*******************************************************************************/
#ifndef __TEST_UTILS_H__
#define __TEST_UTILS_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <xdc/std.h>
#include "ti/drv/emac/emac_drv.h"
#include "ti/drv/emac/test/EmacLoopbackTest/test_loc.h"

#ifdef __cplusplus
extern "C" {
#endif


EMAC_PKT_DESC_T* app_queue_pop(uint32_t            port_num,    APP_PKT_QUEUE_T*    pq);
void app_queue_push(uint32_t              port_num, APP_PKT_QUEUE_T*    pq,EMAC_PKT_DESC_T*    pPktHdr);

EMAC_PKT_DESC_T* app_alloc_pkt(uint32_t port_num, uint32_t pkt_size);
void app_free_pkt(uint32_t port_num, EMAC_PKT_DESC_T*    p_pkt_desc);

void app_init(void);

void app_test_rx_pkt_cb(uint32_t port_num, EMAC_PKT_DESC_T* p_desc);
void app_test_task_poll_pkt (UArg arg0, UArg arg1);
void app_test_task_poll_cfg (UArg arg0, UArg arg1);
void app_test_task_poll_pktEth1 (UArg arg0, UArg arg1);
void app_test_task_send_pkts(UArg arg0, UArg arg1);
void app_test_task_init_emac(UArg arg0, UArg arg1);
void app_test_task_poll_ctrl (UArg arg0, UArg arg1);

void app_delay(uint32_t delay);
void app_output_log(Char* str, UInt numChar);


#ifdef __cplusplus
}
#endif

#endif  /* __TEST_UTILS_H__ */


