/**
 *  \file   EMAC_drv.c
 *
 *  \brief  EMAC Driver high level APIs implementation.
 *
 *   This file contains the driver APIs for EMAC peripheral. 
 */

/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/emac_osal.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* Externs */
extern const EMAC_config_list EMAC_config;


/*
 *  ======== emac_open ========
 */
EMAC_DRV_ERR_E emac_open(uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    /* Input parameter validation */
    OSAL_Assert((p_config) == NULL);

    if (EMAC_config[port_num].fxnTablePtr && EMAC_config[port_num].fxnTablePtr->openFxn)
        return (EMAC_config[port_num].fxnTablePtr->openFxn(port_num, p_config));
    else
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
}


/*
 *  ======== emac_config ========
 */
EMAC_DRV_ERR_E emac_config(uint32_t port_num, EMAC_CONFIG_INFO_T *p_config)
{
    /* Input parameter validation */
    OSAL_Assert((p_config) == NULL);

    if (EMAC_config[port_num].fxnTablePtr && EMAC_config[port_num].fxnTablePtr->configFxn)
        return (EMAC_config[port_num].fxnTablePtr->configFxn(port_num, p_config));
    else
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
}

/*
 *  ======== emac_close ========
 */
EMAC_DRV_ERR_E emac_close(uint32_t port_num)
{
    if (EMAC_config[port_num].fxnTablePtr && EMAC_config[port_num].fxnTablePtr->closeFxn)
        return (EMAC_config[port_num].fxnTablePtr->closeFxn(port_num));
    else
        return EMAC_DRV_RESULT_CLOSE_PORT_ERR;
}

/*
 *  ======== emac_send ========
 */
EMAC_DRV_ERR_E emac_send(uint32_t port_num, EMAC_PKT_DESC_T* p_desc)
{
    /* Input parameter validation */
    OSAL_Assert((p_desc) == NULL);

    if (EMAC_config[port_num].fxnTablePtr && EMAC_config[port_num].fxnTablePtr->sendFxn)
        return (EMAC_config[port_num].fxnTablePtr->sendFxn(port_num, p_desc));
    else
        return EMAC_DRV_RESULT_SEND_ERR;
}

/*
 *  ======== emac_poll ========
 */
EMAC_DRV_ERR_E emac_poll(uint32_t port_num, EMAC_LINK_INFO_T* p_info)
{
    /* Input parameter validation */
    OSAL_Assert((p_info) == NULL);

    if (EMAC_config[port_num].fxnTablePtr && EMAC_config[port_num].fxnTablePtr->pollFxn)
        return (EMAC_config[port_num].fxnTablePtr->pollFxn(port_num, p_info));
    else
        return EMAC_DRV_RESULT_POLL_ERR;
}

/*
 *  ======== emac_get_statistics ========
 */
EMAC_DRV_ERR_E emac_get_statistics(uint32_t port_num, EMAC_STATISTICS_T*      p_stats)
{
    /* Input parameter validation */
    OSAL_Assert((p_stats) == NULL);

    if (EMAC_config[port_num].fxnTablePtr && EMAC_config[port_num].fxnTablePtr->getStatsFxn)
        return (EMAC_config[port_num].fxnTablePtr->getStatsFxn(port_num, p_stats));
    else
        return EMAC_DRV_RESULT_POLL_ERR;
}

/*
 *  ======== emac_poll_pkt ========
 */
EMAC_DRV_ERR_E emac_poll_pkt(uint32_t port_num)
{
    if (EMAC_config[port_num].fxnTablePtr && EMAC_config[port_num].fxnTablePtr->pollPktFxn)
        return (EMAC_config[port_num].fxnTablePtr->pollPktFxn(port_num));
    else
        return EMAC_DRV_RESULT_POLL_ERR;
}







