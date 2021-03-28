/**
 *  \file   emac_soc.c
 *
 *  \brief  SOC specific EMAC hardware attributes.
 *
 *   This file contains the EMAC hardware attributes like base address and
 *   interrupt ids.
 */

/*
 * Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
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


#include <stdint.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_psilcfg.h>
#include <ti/csl/cslr_mdio.h>
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>




#define EMAC_NOT_CONFIGURED 0xFFFFFFFF
#define EMAC_DEFFAULT_ELEMENT_COUNT ((uint32_t)128U)


/* Offset in ICSSG shared data ram to write FW config for slice 1 */
#define EMAC_SLICE1_HANDSHAKE_OFFSET ((uint32_t)(0x8000U))


#define EMAC_TX_CHANNEL_UNCONFIGURED  {NULL,NULL,NULL,NULL,NULL,0,0 }


#define EMAC_TX_CHANNEL_CONFIG(threadId) \
{NULL,NULL,NULL,NULL,NULL,EMAC_DEFFAULT_ELEMENT_COUNT,(threadId)}\




#define EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG \
{\
1,\
{NULL},\
{NULL}, \
NULL, \
NULL,\
{NULL},\
NULL,\
{EMAC_DEFFAULT_ELEMENT_COUNT,EMAC_DEFFAULT_ELEMENT_COUNT,EMAC_DEFFAULT_ELEMENT_COUNT,EMAC_DEFFAULT_ELEMENT_COUNT},\
EMAC_DEFFAULT_ELEMENT_COUNT\
}\


EMAC_HwAttrs_V5 EMACInitCfg[1] =
{
    {
        {
            { /* EMAC_PER_PORT_CFG ICSSG-0 PORT 0 */
                0, /* phy address */
                4,/* number of TX channels */
                EMAC_NOT_CONFIGURED,
                CSL_PRU_ICSSG0_PR1_MDIO_V1P7_MDIO_BASE,
                CSL_PRU_ICSSG0_RAM_SLV_RAM_BASE,
                CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_BASE,
                CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE,
                CSL_PRU_ICSSG0_DRAM1_SLV_RAM_BASE,
                { /*  PER_CHANNEL_CFG_TX upto 4 */
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 0),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 1u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 2u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 3u)
                },
                {
                /*  EMAC_PER_CHANNEL_CFG_RX for rxChannel */
                    NULL,
                    NULL,
                    9U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILS_THREAD_OFFSET + 0u
                },
                {/*  EMAC_PER_CHANNEL_CFG_RX for rxMgmtChannel */
                    NULL,
                    NULL,
                    3U,
                        {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                        },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILS_THREAD_OFFSET + 2u
                },
                {/*  EMAC_PER_CHANNEL_CFG_RX for rxMgmtChannel2 */
                        NULL,
                        NULL,
                        1U,
                        {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                        },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILS_THREAD_OFFSET +1 // need to fix this
                },
                NULL
            },
            {
                3,
                4,
                EMAC_NOT_CONFIGURED,
                CSL_PRU_ICSSG0_PR1_MDIO_V1P7_MDIO_BASE,
                CSL_PRU_ICSSG0_RAM_SLV_RAM_BASE + EMAC_SLICE1_HANDSHAKE_OFFSET,
                CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_BASE,
                CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE,
                CSL_PRU_ICSSG0_DRAM1_SLV_RAM_BASE,
                {
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 4u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 5u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 6u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILD_THREAD_OFFSET + 7u)
                },
                {
                    NULL,
                    NULL,
                    9U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILS_THREAD_OFFSET + 1u,
                },
                {
                    NULL,
                    NULL,
                    3U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILS_THREAD_OFFSET + 3u,
                },                
                {
                    NULL,
                    NULL,
                    1U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G0_PSILS_THREAD_OFFSET + 1u // need to fix this
                },
                NULL
            },
            {
                0,
                4,
                EMAC_NOT_CONFIGURED,
                 CSL_PRU_ICSSG1_PR1_MDIO_V1P7_MDIO_BASE,
                 CSL_PRU_ICSSG1_RAM_SLV_RAM_BASE,
                 CSL_PRU_ICSSG1_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_BASE,
                 CSL_PRU_ICSSG1_DRAM0_SLV_RAM_BASE,
                 CSL_PRU_ICSSG1_DRAM1_SLV_RAM_BASE,
                {
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 0),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 1u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 2u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 3u)
                },
                {
                    NULL,
                    NULL,
                    9U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILS_THREAD_OFFSET + 0u
                },
                {
                    NULL,
                    NULL,
                    3U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILS_THREAD_OFFSET + 2u,
                },
                {
                    NULL,
                    NULL,
                    1U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILS_THREAD_OFFSET + 1u
                },
                NULL
            },
            {
                3,
                4,
                EMAC_NOT_CONFIGURED,
                CSL_PRU_ICSSG1_PR1_MDIO_V1P7_MDIO_BASE,
                CSL_PRU_ICSSG1_RAM_SLV_RAM_BASE + EMAC_SLICE1_HANDSHAKE_OFFSET,
                CSL_PRU_ICSSG1_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_BASE,
                CSL_PRU_ICSSG1_DRAM0_SLV_RAM_BASE,
                CSL_PRU_ICSSG1_DRAM1_SLV_RAM_BASE,
                {
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 4u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 5u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 6u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILD_THREAD_OFFSET + 7u)

                },
                {
                    NULL,
                    NULL,
                    9U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILS_THREAD_OFFSET + 1u,
                },
                {
                    NULL,
                    NULL,
                    3U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILS_THREAD_OFFSET + 3u,
                },                
                {
                    NULL,
                    NULL,
                    1U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G1_PSILS_THREAD_OFFSET + 1u // need to fix this
                },
                NULL
            },
            {
                0,
                4,
                EMAC_NOT_CONFIGURED,
                CSL_PRU_ICSSG2_PR1_MDIO_V1P7_MDIO_BASE,
                CSL_PRU_ICSSG2_RAM_SLV_RAM_BASE,
                CSL_PRU_ICSSG2_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_BASE,
                CSL_PRU_ICSSG2_DRAM0_SLV_RAM_BASE,
                CSL_PRU_ICSSG2_DRAM1_SLV_RAM_BASE,
                {
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 0),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 1u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 2u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 3u)
                },
                {
                    NULL,
                    NULL,
                    9U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILS_THREAD_OFFSET + 0u
                },
                {
                    NULL,
                    NULL,
                    3U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILS_THREAD_OFFSET + 2u,
                },
                {
                    NULL,
                    NULL,
                    0U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILS_THREAD_OFFSET + 1u
                },
                NULL
            },
            {
                3,
                4,
                EMAC_NOT_CONFIGURED,
                CSL_PRU_ICSSG2_PR1_MDIO_V1P7_MDIO_BASE,
                CSL_PRU_ICSSG2_RAM_SLV_RAM_BASE + EMAC_SLICE1_HANDSHAKE_OFFSET,
                CSL_PRU_ICSSG2_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_BASE,
                CSL_PRU_ICSSG2_DRAM0_SLV_RAM_BASE,
                CSL_PRU_ICSSG2_DRAM1_SLV_RAM_BASE,
                {
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 4u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 5u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 6u),
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILD_THREAD_OFFSET + 7u)
                },
                {
                    NULL,
                    NULL,
                    9U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILS_THREAD_OFFSET + 1u,
                },
                {
                    NULL,
                    NULL,
                    3U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILS_THREAD_OFFSET + 3u,
                },
                {
                    NULL,
                    NULL,
                    0U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                        CSL_PSILCFG_NAVSS_MAIN_ICSS_G2_PSILS_THREAD_OFFSET + 1u
                },
                NULL
            },
            {   /* CPSW port */
                0,
                1,
                CSL_MCU_CPSW0_NUSS_BASE,
                CSL_MCU_CPSW0_NUSS_BASE + CPSW_MDIO_OFFSET,
                EMAC_NOT_CONFIGURED,
                EMAC_NOT_CONFIGURED,
                EMAC_NOT_CONFIGURED,
                EMAC_NOT_CONFIGURED,
                {
                    EMAC_TX_CHANNEL_CONFIG(CSL_PSILCFG_NAVSS_MCU_CPSW0_PSILD_THREAD_OFFSET),
                    EMAC_TX_CHANNEL_UNCONFIGURED,
                    EMAC_TX_CHANNEL_UNCONFIGURED,
                    EMAC_TX_CHANNEL_UNCONFIGURED
                },
                {
                    NULL,
                    NULL,
                    1U,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    CSL_PSILCFG_NAVSS_MCU_CPSW0_PSILS_THREAD_OFFSET,
                },
                {
                    NULL,
                    NULL,
                    0,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    EMAC_NOT_CONFIGURED,
                },
                {
                    NULL,
                    NULL,
                    0,
                    {
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG,
                        EMAC_RX_SUB_CHANNEL_DEFAULT_CONFIG
                    },
                    EMAC_NOT_CONFIGURED,
                },
                NULL
            }
            
        }
    }
};

/* EMAC configuration structure */
EMAC_config_list EMAC_config =
{
    {
        &EMAC_FxnTable_v5,
        NULL,
        &EMACInitCfg[0]
    },
    {
        NULL,
        NULL,
        NULL
    }
};


/**
 * \brief  This API gets the SoC level of EMAC intial configuration
 *
 * \param  port_num     EMAC port number.
 * \param  cfg       Pointer to EAMC SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t EMAC_socGetInitCfg(uint32_t port_num, EMAC_HwAttrs_V5 *cfg)
{
    int32_t ret = 0;

    if (port_num  < EMAC_MAX_PORTS)
    {
        *cfg = EMACInitCfg[0];
    }
    else
    {
        ret = -1;
    }
    return ret;
}

/**
 * \brief  This API sets the SoC level of EMAC intial configuration
 *
 * \param  index     EMAC port number.
 * \param  cfg       Pointer to EMAC SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t EMAC_socSetInitCfg(uint32_t port_num, EMAC_HwAttrs_V5 *cfg)
{
    int32_t ret = 0;
    if (port_num  < EMAC_MAX_PORTS)
    {
        EMACInitCfg[0] = *cfg;
    }
    else
    {
        ret = -1;
    }
    return ret;
}
