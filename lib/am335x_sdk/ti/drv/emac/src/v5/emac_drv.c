/**
 *  \file   EMAC_drv.c
 *
 *  \brief  EMAC Driver high level APIs implementation.
 *
 *   This file contains the driver APIs for EMAC peripheral. 
 */

/*
 * Copyright (C) 2014-2018 Texas Instruments Incorporated - http://www.ti.com/
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
//#include <ti/drv/emac/src/emac_osal.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* Externs */
extern EMAC_config_list EMAC_config;


/*
 *  ======== emac_open ========
 */
EMAC_DRV_ERR_E emac_open(uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_DRV_ERR_E retVal;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->openFxn)
        {
            retVal =  (cfg->fxnTablePtr->openFxn(port_num, p_config));
        }
        else
        {
            retVal = EMAC_DRV_RESULT_OPEN_PORT_ERR;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }
    return retVal;
}


/*
 *  ======== emac_config ========
 */
EMAC_DRV_ERR_E emac_config(uint32_t port_num, EMAC_CONFIG_INFO_T *p_config)
{
    EMAC_DRV_ERR_E retVal;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->configFxn)
        {
            retVal =  (cfg->fxnTablePtr->configFxn(port_num, p_config));
        }
        else
        {
            retVal = EMAC_DRV_RESULT_CONFIG_PORT_ERR;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_CONFIG_PORT_ERR;
    }
    return retVal;
}

/*
 *  ======== emac_close ========
 */
EMAC_DRV_ERR_E emac_close(uint32_t port_num)
{
    EMAC_DRV_ERR_E retVal;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->closeFxn)
        {
            retVal =  (cfg->fxnTablePtr->closeFxn(port_num));
        }
        else
        {
            retVal = EMAC_DRV_RESULT_CLOSE_PORT_ERR;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_CLOSE_PORT_ERR;
    }
    return retVal;
}

/*
 *  ======== emac_send ========
 */
EMAC_DRV_ERR_E emac_send(uint32_t port_num, EMAC_PKT_DESC_T* p_desc)
{
    EMAC_DRV_ERR_E retVal;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->sendFxn)
        {
            retVal =  (cfg->fxnTablePtr->sendFxn(port_num, p_desc));
        }
        else
        {
            retVal = EMAC_DRV_RESULT_SEND_ERR;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_SEND_ERR;
    }
    return retVal;
}

/*
 *  ======== emac_poll ========
 */
EMAC_DRV_ERR_E emac_poll(uint32_t port_num, EMAC_LINK_INFO_T* p_info)
{
    EMAC_DRV_ERR_E retVal;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->pollFxn)
        {
            retVal =  (cfg->fxnTablePtr->pollFxn(port_num, p_info));
        }
        else
        {
            retVal = EMAC_DRV_RESULT_POLL_ERR;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_POLL_ERR;
    }
    return retVal;
}

/*
 *  ======== emac_get_statistics ========
 */
EMAC_DRV_ERR_E emac_get_statistics(uint32_t port_num, EMAC_STATISTICS_T*      p_stats)
{
    EMAC_DRV_ERR_E retVal;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->getStatsFxn)
        {
            retVal =  (cfg->fxnTablePtr->getStatsFxn(port_num, p_stats));
        }
        else
        {
            retVal = EMAC_DRV_RESULT_GET_STATS_ERR;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_GET_STATS_ERR;
    }
    return retVal;
}

/*
 *  ======== emac_poll_pkt ========
 */
EMAC_DRV_ERR_E emac_poll_pkt(uint32_t port_num)
{
    EMAC_Cfg *cfg = &EMAC_config[0];
    EMAC_DRV_ERR_E ret;
    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->pollPktFxn)
        {
            ret = (cfg->fxnTablePtr->pollPktFxn(port_num));
        }
        else
        {
            ret = EMAC_DRV_RESULT_POLL_ERR;
        }

    }
    else
    {
        ret = EMAC_DRV_RESULT_POLL_ERR;
    }
    return ret;
}


/*
 *  ======== emac_get_statistics_icss ========
 */
EMAC_DRV_ERR_E emac_get_statistics_icssg(uint32_t port_num, EMAC_STATISTICS_ICSSG_T *p_stats, bool clear)
{
    EMAC_DRV_ERR_E retVal;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->getStatsIcssgFxn)
        {
            retVal =  (cfg->fxnTablePtr->getStatsIcssgFxn(port_num, p_stats, clear));
        }
        else
        {
            retVal = EMAC_DRV_RESULT_GET_STATS_ERR;
        }
    }
    else
    {
        retVal = EMAC_DRV_RESULT_GET_STATS_ERR;
    }
    return retVal;
}

/*
 *  ======== emac_ioctl ========
 */
EMAC_DRV_ERR_E emac_ioctl(uint32_t port_num, EMAC_IOCTL_CMD emacIoctlCmd, EMAC_IOCTL_PARAMS *emacIoctlParams)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_GET_STATS_ERR;
    EMAC_Cfg *cfg = &EMAC_config[0];

    if (cfg->fxnTablePtr)
        if (cfg->fxnTablePtr->ioctlFxn)
            retVal =  (cfg->fxnTablePtr->ioctlFxn(port_num, emacIoctlCmd, emacIoctlParams));
    return retVal;
}


/*
 *  ======== emac_poll_ctrl ========
 */
EMAC_DRV_ERR_E emac_poll_ctrl(uint32_t port_num,     uint32_t rxPktRings, uint32_t rxMgmtRings, uint32_t txRings)
{
    EMAC_Cfg *cfg = &EMAC_config[0];
    EMAC_DRV_ERR_E ret;
    if (cfg->fxnTablePtr)
    {
        if (cfg->fxnTablePtr->pollCtrl)
        {
            ret = (cfg->fxnTablePtr->pollCtrl(port_num, rxPktRings, rxMgmtRings, txRings));
        }
        else
        {
            ret = EMAC_DRV_RESULT_POLL_ERR;
        }

    }
    else
    {
        ret = EMAC_DRV_RESULT_POLL_ERR;
    }
    return ret;
}

