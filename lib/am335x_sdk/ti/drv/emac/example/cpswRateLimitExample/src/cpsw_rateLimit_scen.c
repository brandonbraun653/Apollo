/**
 *   @file  cpsw_rateLimit_scen.c
 *
 *   @brief   
 *      This file contains system scenarios for testing the CPSW Rate Limit operations.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015, Texas Instruments, Inc.
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
 *  \par
*/

#include <ti/drv/emac/example/cpswRateLimitExample/src/cpsw_rateLimit_test.h>
#include <stdio.h>

/* Rate limit configuration data structure */
typedef struct
{
   int           numChans;      /* number of rate limiting channels */
   uint32_t      bandwidth[8];  /* desired bandwidth in Mbps per priority */
} rateLimitCfg_t;

/************************ GLOBAL VARIABLES ********************/
uint32_t cpsw_speed  = CPSW_SPEED;        /* Initialize CPSW input clock to be the default value */
                                          /* cpsw_speed should be set to the actual CPSW input clock
                                             before the test starts if it is not the default value */

/************************ EXTERN VARIABLES ********************/
extern uint32_t errorCount;

/** ============================================================================
 *   @n@b rate_limit_config
 *
 *   @b Description
 *   @n Utility function to configure CPSW Receive Rate Limit
 *
 *   @param[in] cfg     The rate limit configuration information 
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              >=0     -   Success
 * =============================================================================
 */
int rate_limit_config(rateLimitCfg_t *cfg)
{
    CSL_CPSW_RX_RATE_LIMIT_CONFIG rxRateLimtCfg;
    int i;
   
    memset(&rxRateLimtCfg, 0, sizeof(rxRateLimtCfg));
    /* read BOOTCFG_EFUSE_BOOTROM to determine cpsw ss clock speed for EVM_K2G*/
#ifndef ICE_K2G
   cpsw_speed = Board_getDEVSPEED();
#endif 
    rxRateLimtCfg.numRLimChans = cfg->numChans;
   
    for ( i = 0; i < rxRateLimtCfg.numRLimChans; i++)
    {
        uint32_t idleStep;
        for (idleStep = 1; idleStep < cfg->bandwidth[7 - i]; idleStep++)
        {
            if(((idleStep * cpsw_speed * 128) % (cfg->bandwidth[7 - i])) == 0)
                break;
        }
        
        rxRateLimtCfg.idleStep[7 - i] = idleStep*3;
        rxRateLimtCfg.sendStep[7 - i] = idleStep*cpsw_speed*128/(cfg->bandwidth[7 - i]) - rxRateLimtCfg.idleStep[7 - i];
    }
   
    CSL_CPSW_setRxRLimConfig(&rxRateLimtCfg);
    
    return (0);
}

/*****************************************************************************
 * Configuration and expected results for scenario 1
 *****************************************************************************/
int scenario_config_01 (packetGenCfg_t *pktGen)
{
    rateLimitCfg_t rateLimitCfg;
    
    /*************************************************************************
     * Configure the CPSW Rate Limit as follows
     * Top 2 proirities with reserved bandwith as the followings
     * priority 7: 200 Mbps
     * Priority 6: 300 Mbps
     ************************************************************************/
     memset (&rateLimitCfg, 0, sizeof(rateLimitCfg_t));
     rateLimitCfg.numChans = 2;
     rateLimitCfg.bandwidth[7] = 200;
     rateLimitCfg.bandwidth[6] = 300;
     
    if (rate_limit_config (&rateLimitCfg))
    {
        return 1;
    }
    
    /*************************************************************************
     * Configure the packet generator as follows
     * Total (3) Output streams
     * Stream No.(1), priority 7 with (300M)bps and (500 )bytes/packet
     * Stream No.(2), priority 6 with (400M)bps and (500 )bytes/packet
     * Stream No.(3), priority 0 with (100M)bps and (500 )bytes/packet
     * 
     * Configure the expected results
     * Total bps present to each output port.  
     *    Stream No.(1) output with 200 Mbps
     *    Stream No.(2) output with 300 Mbps
     *    Stream No.(3) output with 100 Mbps
     * Tolerances for above each number that is checked. (5%)
     *************************************************************************/

    /* Make sure enough memory is in pktGen */
    pktGen->genTime  = 30000;
    pktGen->readTime = 30000;
    memset (pktGen->inst, 0,  MAX_PKT_GEN_INSTANCES * sizeof(pktGen->inst[0]));
    
    pktGen->inst[7].nSizes = 1;
    pktGen->inst[7].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[7].pktSize[0] = 500;
    pktGen->inst[7].pps = 300000000 / ((pktGen->inst[7].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[7].bpsExp = 200000000;
    pktGen->inst[7].bpsError = pktGen->inst[7].bpsExp / (100/5);  /* 5% */
    
    
    pktGen->inst[6].nSizes = 1;
    pktGen->inst[6].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[6].pktSize[0] = 500;
    pktGen->inst[6].pps = 400000000 / ((pktGen->inst[6].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[6].bpsExp = 300000000;
    pktGen->inst[6].bpsError = pktGen->inst[6].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[0].nSizes = 1;
    pktGen->inst[0].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[0].pktSize[0] = 1000;
    pktGen->inst[0].pps = 100000000 / ((pktGen->inst[0].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[0].bpsExp = 100000000;
    pktGen->inst[0].bpsError = pktGen->inst[0].bpsExp / (100/5);  /* 5% */

    return 0;
}

/*****************************************************************************
 * Configuration and expected results for scenario 2
 *****************************************************************************/
int scenario_config_02 (packetGenCfg_t *pktGen)
{
    rateLimitCfg_t rateLimitCfg;
    
    /*************************************************************************
     * Configure the CPSW Rate Limit as follows
     * Top 2 proirities with reserved bandwith as the followings
     * priority 7: 20 Mbps
     * Priority 6: 30 Mbps
     * Priority 5: 150 Mbps
     * Priority 4: 200 Mbps
     * Priority 3: 300 Mbps
     * Priority 2: 100 Mbps
     * Priority 1: 100 Mbps
     ************************************************************************/
     memset (&rateLimitCfg, 0, sizeof(rateLimitCfg_t));
     rateLimitCfg.numChans = 7;
     rateLimitCfg.bandwidth[7] = 20;
     rateLimitCfg.bandwidth[6] = 30;
     rateLimitCfg.bandwidth[5] = 150;
     rateLimitCfg.bandwidth[4] = 200;
     rateLimitCfg.bandwidth[3] = 300;
     rateLimitCfg.bandwidth[2] = 100;
     rateLimitCfg.bandwidth[1] = 100;
     
    if (rate_limit_config (&rateLimitCfg))
    {
        return 1;
    }
    
    /*************************************************************************
     * Configure the packet generator as follows
     * Total (3) Output streams
     * Stream No.(1), priority 7 with (30M)bps and (60 )bytes/packet
     * Stream No.(2), priority 6 with (45M)bps and (80 )bytes/packet
     * Stream No.(2), priority 5 with (180M)bps and (126 )bytes/packet
     * Stream No.(2), priority 4 with (250M)bps and (500 )bytes/packet
     * Stream No.(2), priority 3 with (350M)bps and (1000 )bytes/packet
     * Stream No.(2), priority 2 with (150M)bps and (200 )bytes/packet
     * Stream No.(2), priority 1 with (150M)bps and (100 )bytes/packet
     * Stream No.(3), priority 0 with (100M)bps and (500 )bytes/packet
     * 
     * Configure the expected results
     * Total bps present to each output port.  
     *    Stream No.(1) output with  20 Mbps
     *    Stream No.(2) output with  30 Mbps
     *    Stream No.(3) output with 150 Mbps
     *    Stream No.(4) output with 200 Mbps
     *    Stream No.(5) output with 300 Mbps
     *    Stream No.(6) output with 100 Mbps
     *    Stream No.(7) output with 100 Mbps
     *    Stream No.(8) output with 100 Mbps
     * Tolerances for above each number that is checked. (5%)
     *************************************************************************/

    /* Make sure enough memory is in pktGen */
    pktGen->genTime  = 30000;
    pktGen->readTime = 30000;
    memset (pktGen->inst, 0,  MAX_PKT_GEN_INSTANCES * sizeof(pktGen->inst[0]));
    
    pktGen->inst[7].nSizes = 1;
    pktGen->inst[7].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[7].pktSize[0] = 60;
    pktGen->inst[7].pps = 25000000 / ((pktGen->inst[7].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[7].bpsExp = 20000000;
    pktGen->inst[7].bpsError = pktGen->inst[7].bpsExp / (100/5);  /* 5% */
    
    
    pktGen->inst[6].nSizes = 1;
    pktGen->inst[6].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[6].pktSize[0] = 80;
    pktGen->inst[6].pps = 35000000 / ((pktGen->inst[6].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[6].bpsExp = 30000000;
    pktGen->inst[6].bpsError = pktGen->inst[6].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[5].nSizes = 1;
    pktGen->inst[5].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[5].pktSize[0] = 126;
    pktGen->inst[5].pps = 160000000 / ((pktGen->inst[5].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[5].bpsExp = 150000000;
    pktGen->inst[5].bpsError = pktGen->inst[5].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[4].nSizes = 1;
    pktGen->inst[4].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[4].pktSize[0] = 500;
    pktGen->inst[4].pps = 220000000 / ((pktGen->inst[4].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[4].bpsExp = 200000000;
    pktGen->inst[4].bpsError = pktGen->inst[4].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[3].nSizes = 1;
    pktGen->inst[3].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[3].pktSize[0] = 1000;
    pktGen->inst[3].pps = 320000000 / ((pktGen->inst[3].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[3].bpsExp = 300000000;
    pktGen->inst[3].bpsError = pktGen->inst[3].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[2].nSizes = 1;
    pktGen->inst[2].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[2].pktSize[0] = 200;
    pktGen->inst[2].pps = 120000000 / ((pktGen->inst[2].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[2].bpsExp = 100000000;
    pktGen->inst[2].bpsError = pktGen->inst[2].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[1].nSizes = 1;
    pktGen->inst[1].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[1].pktSize[0] = 100;
    pktGen->inst[1].pps = 120000000 / ((pktGen->inst[1].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[1].bpsExp = 100000000;
    pktGen->inst[1].bpsError = pktGen->inst[1].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[0].nSizes = 1;
    pktGen->inst[0].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[0].pktSize[0] = 500;
    pktGen->inst[0].pps = 100000000 / ((pktGen->inst[0].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[0].bpsExp = 100000000;
    pktGen->inst[0].bpsError = pktGen->inst[0].bpsExp / (100/5);  /* 5% */

    return 0;
}

/*****************************************************************************
 * Configuration and expected results for scenario 3
 *****************************************************************************/
int scenario_config_03 (packetGenCfg_t *pktGen)
{
    rateLimitCfg_t rateLimitCfg;
    
    /*************************************************************************
     * Configure the CPSW Rate Limit as follows
     * Top 2 proirities with reserved bandwith as the followings
     * priority 7: 20 Mbps
     * Priority 6: 30 Mbps
     * Priority 1: 100 Mbps
     ************************************************************************/
     memset (&rateLimitCfg, 0, sizeof(rateLimitCfg_t));
     rateLimitCfg.numChans = 6;
     rateLimitCfg.bandwidth[7] = 100;
     rateLimitCfg.bandwidth[6] = 100;
     rateLimitCfg.bandwidth[5] = 100;
     rateLimitCfg.bandwidth[4] = 100;
     rateLimitCfg.bandwidth[3] = 100;
     rateLimitCfg.bandwidth[2] = 100;
     
    if (rate_limit_config (&rateLimitCfg))
    {
        return 1;
    }
    
    /*************************************************************************
     * Configure the packet generator as follows
     * Total (3) Output streams
     * Stream No.(1), priority 7 with (150M)bps and (60 )bytes/packet
     * Stream No.(2), priority 6 with (150M)bps and (100 )bytes/packet
     * Stream No.(3), priority 5 with (150M)bps and (200 )bytes/packet
     * Stream No.(4), priority 4 with (150M)bps and (400 )bytes/packet
     * Stream No.(5), priority 3 with (150M)bps and (800 )bytes/packet
     * Stream No.(6), priority 2 with (150M)bps and (1500 )bytes/packet
     * Stream No.(7), priority 0 with (100M)bps and (500 )bytes/packet
     * 
     * Configure the expected results
     * Total bps present to each output port.  
     *    Stream No.(1) output with 100 Mbps
     *    Stream No.(2) output with 100 Mbps
     *    Stream No.(3) output with 100 Mbps
     *    Stream No.(4) output with 100 Mbps
     *    Stream No.(5) output with 100 Mbps
     *    Stream No.(6) output with 100 Mbps
     *    Stream No.(7) output with 100 Mbps
     * Tolerances for above each number that is checked. (5%)
     *************************************************************************/

    /* Make sure enough memory is in pktGen */
    pktGen->genTime  = 30000;
    pktGen->readTime = 30000;
    memset (pktGen->inst, 0,  MAX_PKT_GEN_INSTANCES * sizeof(pktGen->inst[0]));
    
    pktGen->inst[7].nSizes = 1;
    pktGen->inst[7].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[7].pktSize[0] = 60;
    pktGen->inst[7].pps = 150000000 / ((pktGen->inst[7].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[7].bpsExp = 100000000;
    pktGen->inst[7].bpsError = pktGen->inst[7].bpsExp / (100/5);  /* 5% */
    
    
    pktGen->inst[6].nSizes = 1;
    pktGen->inst[6].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[6].pktSize[0] = 100;
    pktGen->inst[6].pps = 150000000 / ((pktGen->inst[6].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[6].bpsExp = 100000000;
    pktGen->inst[6].bpsError = pktGen->inst[6].bpsExp / (100/5);  /* 5% */
                                   
                                   
    pktGen->inst[5].nSizes = 1;
    pktGen->inst[5].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[5].pktSize[0] = 200;
    pktGen->inst[5].pps = 150000000 / ((pktGen->inst[5].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[5].bpsExp = 100000000;
    pktGen->inst[5].bpsError = pktGen->inst[5].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[4].nSizes = 1;
    pktGen->inst[4].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[4].pktSize[0] = 400;
    pktGen->inst[4].pps = 150000000 / ((pktGen->inst[4].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[4].bpsExp = 100000000;
    pktGen->inst[4].bpsError = pktGen->inst[4].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[3].nSizes = 1;
    pktGen->inst[3].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[3].pktSize[0] = 800;
    pktGen->inst[3].pps = 150000000 / ((pktGen->inst[3].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[3].bpsExp = 100000000;
    pktGen->inst[3].bpsError = pktGen->inst[3].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[2].nSizes = 1;
    pktGen->inst[2].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[2].pktSize[0] = 1500;
    pktGen->inst[2].pps = 150000000 / ((pktGen->inst[2].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[2].bpsExp = 100000000;
    pktGen->inst[2].bpsError = pktGen->inst[2].bpsExp / (100/5);  /* 5% */
                                   
    pktGen->inst[0].nSizes = 1;
    pktGen->inst[0].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[0].pktSize[0] = 500;
    pktGen->inst[0].pps = 100000000 / ((pktGen->inst[0].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[0].bpsExp = 100000000;
    pktGen->inst[0].bpsError = pktGen->inst[0].bpsExp / (100/5);  /* 5% */

    return 0;
}

/*****************************************************************************
 * Configuration and expected results for scenario 4
 *****************************************************************************/
int scenario_config_04 (packetGenCfg_t *pktGen)
{
    rateLimitCfg_t rateLimitCfg;
    
    /*************************************************************************
     * Configure the CPSW Rate Limit as follows
     * Top 2 proirities with reserved bandwith as the followings
     * priority 7: 20 Mbps
     * Priority 6: 30 Mbps
     * Priority 1: 100 Mbps
     ************************************************************************/
     memset (&rateLimitCfg, 0, sizeof(rateLimitCfg_t));
     rateLimitCfg.numChans = 6;
     rateLimitCfg.bandwidth[7] = 100;
     rateLimitCfg.bandwidth[6] =  80;
     rateLimitCfg.bandwidth[5] =  60;
     rateLimitCfg.bandwidth[4] =  40;
     rateLimitCfg.bandwidth[3] =  20;
     rateLimitCfg.bandwidth[2] =  10;
     
    if (rate_limit_config (&rateLimitCfg))
    {
        return 1;
    }
    
    /*************************************************************************
     * Configure the packet generator as follows
     * Total (3) Output streams
     * Stream No.(1), priority 7 with (120M)bps and (60 )bytes/packet
     * Stream No.(2), priority 6 with (100M)bps and (60 )bytes/packet
     * Stream No.(3), priority 5 with (80M)bps and (60 )bytes/packet
     * Stream No.(4), priority 4 with (60M)bps and (60 )bytes/packet
     * Stream No.(5), priority 3 with (30M)bps and (60 )bytes/packet
     * Stream No.(6), priority 2 with (15M)bps and (60 )bytes/packet
     * Stream No.(7), priority 0 with (100M)bps and (500 )bytes/packet
     * 
     * Configure the expected results
     * Total bps present to each output port.  
     *    Stream No.(1) output with 100 Mbps
     *    Stream No.(2) output with  80 Mbps
     *    Stream No.(3) output with  60 Mbps
     *    Stream No.(4) output with  40 Mbps
     *    Stream No.(5) output with  20 Mbps
     *    Stream No.(6) output with  10 Mbps
     *    Stream No.(7) output with 100 Mbps
     * Tolerances for above each number that is checked. (5%)
     *************************************************************************/

    /* Make sure enough memory is in pktGen */
    pktGen->genTime  = 30000;
    pktGen->readTime = 30000;
    memset (pktGen->inst, 0,  MAX_PKT_GEN_INSTANCES * sizeof(pktGen->inst[0]));
    
    pktGen->inst[7].nSizes = 1;
    pktGen->inst[7].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[7].pktSize[0] = 60;
    pktGen->inst[7].pps = 120000000 / ((pktGen->inst[7].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[7].bpsExp = 100000000;
    pktGen->inst[7].bpsError = pktGen->inst[7].bpsExp / (100/5);  /* 5% */

    pktGen->inst[6].nSizes = 1;
    pktGen->inst[6].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[6].pktSize[0] = 60;
    pktGen->inst[6].pps = 100000000 / ((pktGen->inst[6].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[6].bpsExp = 80000000;
    pktGen->inst[6].bpsError = pktGen->inst[6].bpsExp / (100/5);  /* 5% */
                                   
    pktGen->inst[5].nSizes = 1;
    pktGen->inst[5].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[5].pktSize[0] = 60;
    pktGen->inst[5].pps = 80000000 / ((pktGen->inst[5].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[5].bpsExp = 60000000;
    pktGen->inst[5].bpsError = pktGen->inst[5].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[4].nSizes = 1;
    pktGen->inst[4].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[4].pktSize[0] = 60;
    pktGen->inst[4].pps = 60000000 / ((pktGen->inst[4].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[4].bpsExp = 40000000;
    pktGen->inst[4].bpsError = pktGen->inst[4].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[3].nSizes = 1;
    pktGen->inst[3].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[3].pktSize[0] = 60;
    pktGen->inst[3].pps = 30000000 / ((pktGen->inst[3].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[3].bpsExp = 20000000;
    pktGen->inst[3].bpsError = pktGen->inst[3].bpsExp / (100/5);  /* 5% */
    
    pktGen->inst[2].nSizes = 1;
    pktGen->inst[2].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[2].pktSize[0] = 60;
    pktGen->inst[2].pps = 15000000 / ((pktGen->inst[2].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[2].bpsExp = 10000000;
    pktGen->inst[2].bpsError = pktGen->inst[2].bpsExp / (100/5);  /* 5% */
     
    pktGen->inst[0].nSizes = 1;
    pktGen->inst[0].sizeMode = packet_GEN_SIZE_MODE_ROUND_ROBIN;
    pktGen->inst[0].pktSize[0] = 500;
    pktGen->inst[0].pps = 100000000 / ((pktGen->inst[0].pktSize[0] + ENET_DATA_PACKET_OVHD) * 8);
    
    pktGen->inst[0].bpsExp = 100000000;
    pktGen->inst[0].bpsError = pktGen->inst[0].bpsExp / (100/5);  /* 5% */

    return 0;
}


const rateLimitTestScenCfg_t rateLimitTestScenCfgs[] =
{
    scenario_config_01, "RateLimit Test1 (0: 100/100, 6: 300/400, 7: 200/300)",
    scenario_config_02, "RateLimit Test2 (0: 100/100, 1: 100/150, 2: 100/150, 3: 300/350, 4: 200/250, 5: 150/180, 6: 30/45, 7: 20/30)",
    scenario_config_03, "RateLimit Test3 (0: 100/100, 2: 100/150, 3: 100/150,  4: 100/150, 5: 100/150, 6: 100/150, 7: 100/150)",
    scenario_config_04, "RateLimit Test4 (0: 100/100, 2: 10/15, 3: 20/30,  4: 40/60, 5: 60/80, 6: 80/100, 7: 100/120)",
    NULL, NULL
};


