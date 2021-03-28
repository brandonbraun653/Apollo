/**  
 * @file cpsw_rateLimit_test.h
 *
 * @brief 
 *  Holds all the constants, data structures and API definitions required by 
 *  the rate limit example application to run.
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
*/
#ifndef _CPSW_RATELIMIT_TEST_H_
#define _CPSW_RATELIMIT_TEST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/emac/cpsw/example/src/cpsw_singlecore.h>      /* Inherent all definitions from CPSW basic example */

/* Define rate limit example specific constants, data structures and API prototypes */
#define RATE_LIMIT_FAST_SCENARIO  // Define this to run scenarios for 1/100th of the configured time

#define CORE_SPEED                  600000000 /* Default system clock in units of Hz */
#define CPSW_SPEED                  600       /* Default CPSW input clock in units of MHz */
                                               /* note: The CPSW internal clock is 1/3*CPSW_SPEED */

/* Ethernet ovehead -- accounts for preamble, gap, and crc */
#define ENET_DATA_PACKET_OVHD       24

/* 
 * Define the number of packet engine and configuration instances
 * There is one instance per priority.
 */
#define MAX_PKT_GEN_INSTANCES        8         

/* Packet engine instance state */
typedef struct
{
    uint8_t*      pkt;          /* pointer to packet data buffer */
    Qmss_QueueHnd outputQ;      /* Queue to place packets */
    uint32_t      deltaTime;    /* Delta time between packets */
    uint64_t      nextTime;     /* Next time this generator should output packet */
    uint64_t      lastRxTime;   /* Timestamp of last received packet */
    uint64_t      bytesTx;      /* Number of bytes transmitted to this stream */
    uint64_t      bytesRx;      /* Number of bytes received from this stream */
    uint32_t      sizeIdx;      /* Index of next size to use */
    uint32_t      packetsRx;    /* Number of packets received from this stream */
    uint32_t      packetsTx;    /* Number of packets transmitted to this stream */
    uint32_t      packetsYanked; /* Number of packets yanked from this stream at EOT */
    uint32_t      packetsDropped; /* Number of packets dropped due to lack of bandwidth */
} pktGenEngState_t;

/* List of ordered packet engines */
typedef struct
{
    uint32_t      numPresent;                 /* Number of active packet engines */
    uint32_t      idx[MAX_PKT_GEN_INSTANCES]; /* Ordered (by nextTime) list of pending engines */
} pktGenEngList_t;

/* Define the packet size determine pattern used by the packet engine */
typedef enum
{
   packet_GEN_SIZE_MODE_ROUND_ROBIN, /* Generate packets with each size in pktSize[] in round robin fashion */
   packet_GEN_SIZE_MODE_RANDOM       /* Generate packets with each size uniform between pktSize[0] and pktSizse[1] */
} packetGenSizeMode;

/* Packet generator instance data structure */ 
typedef struct 
{
   uint32_t          pps;      /* Generate packets per second */
   uint32_t          nSizes;   /* Number of sizes in pktSize */
   uint32_t          pktSize[16];  /* generated packet size (just value of Qm C register) */
   packetGenSizeMode sizeMode;
   uint32_t          bpsExp;   /* Expected result packets per second */
   uint32_t          bpsError; /* Allowed error */
} packetGenInstCfg_t;

/* Packet generator data structure */
typedef struct 
{
   uint32_t      genTime;      /* milliseconds to generate traffic */
   uint32_t      readTime;     /* milliseconds from start of test to check results */
   packetGenInstCfg_t inst[MAX_PKT_GEN_INSTANCES]; /* traffic instances */
} packetGenCfg_t;

/* Prototype of the rate limit test configuration function */
typedef int (*rateLimitTestConfigFcn_t) (packetGenCfg_t *pktGen);

/*  Data structure which defines a rate limit test scenario */
typedef struct
{
    rateLimitTestConfigFcn_t    fcn;
    char                        *desc;
} rateLimitTestScenCfg_t;

extern const rateLimitTestScenCfg_t rateLimitTestScenCfgs[];

#ifdef __LINUX_USER_SPACE
extern void* Cpsw_RateLimitTestApp (void *args);
#else
extern void Cpsw_RateLimitTestApp (void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _CPSW_RATELIMIT_TEST_H_ */
/* Nothing past this point */

