/**
 * @file test_common_utils.h
 * @brief Contains function declaration of utility APIs used by icss_emac unit tests. 
 *
 */

/* Copyright (C) {2016} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#ifdef __LINUX_USER_SPACE
#include <stdint.h>
#else
#include <xdc/std.h>
#endif
#include <ti/drv/icss_emac/icss_emacDrv.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Test structures for VLAN filtering tests */
typedef struct testVlanCfg_s
{
    int32_t  vlanFilterEnable;
    int32_t  vlanAddRemoveCfg;
    int32_t  vid;
    int32_t  prioPktCfg;
    int32_t  unTagPktCfg;
    int32_t  expectedRxPktWeight;
}testVlanCfg_t;

/* VLAN filtering test macro defines for weight */
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TAGGED_WEIGHT       10
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_UNTAGGED_WEIGHT     20
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PRIORITY_WEIGHT     40
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_NONE                 0
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TPU                 (ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TAGGED_WEIGHT + ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_UNTAGGED_WEIGHT + ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PRIORITY_WEIGHT)
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TU                  (ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TAGGED_WEIGHT + ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_UNTAGGED_WEIGHT )
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TP                  (ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TAGGED_WEIGHT + ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PRIORITY_WEIGHT )
#define ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PU                  (ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_UNTAGGED_WEIGHT + ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PRIORITY_WEIGHT )

/* VLAN filtering test macro defines for features */
#define ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_DISABLE            (0)
#define ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE             (1)

#define ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_UNTAGGED_HOST_RX     (2)
#define ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_UNTAGGED_HOST_RX (3)

#define ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_PRIO_HOST_RX         (4)
#define ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_PRIO_HOST_RX     (5)

#define ICSS_EMAC_VLAN_FILTER_TEST_VID_NOT_CONFIGURED         ( 6 )
#define ICSS_EMAC_VLAN_FILTER_TEST_VID_ADD_VLAN_ID            ( 7 )
#define ICSS_EMAC_VLAN_FILTER_TEST_VID_REMOVE_VLAN_ID         ( 8 )
#define ICSS_EMAC_VLAN_FILTER_TEST_VID                        ( 1 )

/* Macros Declarations */
#define ICSS_EMAC_TEST_ETHER_TYPE 0x0806U
#define ICSS_EMAC_TEST_VLAN_ETH_TYPE 0x8100U
#define ICSS_EMAC_TEST_ETH_ALEN    0x6U
#define ICSS_EMAC_TEST_BYTESWAP16(x)	((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))
#define ICSS_EMAC_TEST_BOARD_IDKAM571x     1
#define ICSS_EMAC_TEST_BOARD_IDKAM572x     2
#define ICSS_EMAC_TEST_BOARD_IDKAM437x     3
#define ICSS_EMAC_TEST_BOARD_ICEV2AM335x     4
#define ICSS_EMAC_TEST_BOARD_ICEK2G     5
#define ICSS_EMAC_TEST_BOARD_IDKAM574x     6

#define ICSS_EMAC_TEST_PKT_TX_COUNT 10
#define ICSS_EMAC_TEST_PKT_SIZE       42
#define ICSS_EMAC_TEST_QUEUE_OVERFLOW_PASS_CRITERIA_COUNT 14U
#define ICSS_EMAC_TEST_QUEUE_OVERFLOW_COUNT       110U
#define ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT1        60
#define ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT2        60
#define ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT1        1500
#define ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT2        1500

/*    TTS Macros    */
#define ICSS_EMAC_TEST_TTS_PERIOD_MARGIN             50
#define ICSS_EMAC_TEST_TTS_MAX_ACYC_PKT_COUNT        100
#define ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT            10000

#ifdef __LINUX_USER_SPACE
#ifdef icev2AM335x
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1       1200000
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2       1200000
#define ICSS_EMAC_TEST_TTS_CONFIG_TIME               500000
#else
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1        800000
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2        800000
#define ICSS_EMAC_TEST_TTS_CONFIG_TIME               350000
#endif
#else
#if defined(idkAM574x) || defined(idkAM572x)|| defined(idkAM571x) || defined(icev2AM335x) || defined(iceK2G) || defined(am65xx_evm)
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1                350000
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2                350000
#define ICSS_EMAC_TEST_TTS_CONFIG_TIME                       120000
#elif defined(idkAM437x)
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1                425000
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2                425000
#define ICSS_EMAC_TEST_TTS_CONFIG_TIME                       275000
#elif defined(iceAMIC110)
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1                500000
#define ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2                500000
#define ICSS_EMAC_TEST_TTS_CONFIG_TIME                       150000
#endif
#endif

#if defined(icev2AM335x) || defined(iceAMIC110)
#ifndef __LINUX_USER_SPACE
#include <ti/sysbios/timers/dmtimer/Timer.h>
#endif

/* following defines are derived from starterware and should changed to different values
    if different timer are used */
#define CM_PER_TIMER3_CLKCTRL       0x44e00084
#define CM_DPLL_CLKSEL_TIMER3_CLK   0x44e0050c

#define ICSS_EMAC_TEST_DMTIMER3                1
#define ICSS_EMAC_TEST_TIMER_ID                ICSS_EMAC_TEST_DMTIMER3
#define ICSS_EMAC_TEST_TIMER_FREQUENCY      24000000
#define ICSS_EMAC_TEST_TIMER_PERIOD    100
#endif

#if defined (idkAM437x)
#ifndef __LINUX_USER_SPACE
#include <ti/sysbios/timers/dmtimer/Timer.h>
#endif

/* following defines are derived from starterware and should changed to different values
    if different timer are used */
#define CM_PER_TIMER3_CLKCTRL       (0x44DF8800 + 0x538)        // PRCM_CM_PER_TIMER3_CLKCTRL
#define CM_DPLL_CLKSEL_TIMER3_CLK   (0x44DF4200 + 0x8)

#define ICSS_EMAC_TEST_DMTIMER3                3
#define ICSS_EMAC_TEST_TIMER_ID            ICSS_EMAC_TEST_DMTIMER3
#define ICSS_EMAC_TEST_TIMER_FREQUENCY      24000000
#define ICSS_EMAC_TEST_TIMER_PERIOD    100
#endif

#if (defined (idkAM574x) || defined (idkAM572x) || defined (idkAM571x)) || defined(am65xx_evm)
#ifndef __LINUX_USER_SPACE
#include <ti/sysbios/timers/dmtimer/Timer.h>
#endif

#ifndef __JAILHOUSE_INMATE
#define ICSS_EMAC_TEST_GPTIMER2                    1
#define ICSS_EMAC_TEST_TIMER_ID                    ICSS_EMAC_TEST_GPTIMER2
#define ICSS_EMAC_TEST_TIMER_FREQUENCY      19200000
#define ICSS_EMAC_TEST_TIMER_PERIOD    100
#else
#define ICSS_EMAC_TEST_TIMER_ID                    7 /* GPTIMER8 */
#define ICSS_EMAC_TEST_TIMER_FREQUENCY      19200000
#define ICSS_EMAC_TEST_TIMER_PERIOD    100
#endif
#endif


#define ICSS_EMAC_TEST_CONTROL_MAC_ID_LO(n)   (0x630 + (n * 8))
#define ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(n)   (0x634 + (n * 8))

#define ICSS_EMAC_TEST_PRU1ETH0    0
#define ICSS_EMAC_TEST_PRU1ETH1    1
#define ICSS_EMAC_TEST_PRU2ETH0    2
#define ICSS_EMAC_TEST_PRU2ETH1    3

/* MMU defines */
#define ICSS_EMAC_TEST_MMU_BUFFERABLE      1
#define ICSS_EMAC_TEST_MMU_CACHEABLE       2
#define ICSS_EMAC_TEST_MMU_SHAREABLE       4
#define ICSS_EMAC_TEST_MMU_NO_EXECUTE      8



#if defined (iceK2G)
#define ICSS_EMAC_TEST_TIMER64              2
#define ICSS_EMAC_TEST_TIMER_ID                ICSS_EMAC_TEST_TIMER64
#define ICSS_EMAC_TEST_TIMER_FREQUENCY      20480000 
#define ICSS_EMAC_TEST_TIMER_PERIOD    100
#endif


/* MMU Entry stuct definition */
typedef struct icss_emacTestMMUEntry
{
    
    void* address;
    /**< Address to be entered in MMU table. */
    unsigned int attributes;
    /**< Attributes of the memory. */
}ICSS_EmacTestMmuEntry;


/* Function Declarations */
int32_t ICSS_EMAC_testGetPruStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle);
void ICSS_EMAC_testDrvInit(ICSS_EmacHandle handle, uint8_t instance);

/* Call back functions registered with ICSS-EMAC LLD */
int32_t ICSS_EMAC_testLinkIsrCb(void* linkStatus, void* usrArg);

/*Callback functions for packet processing */
int32_t ICSS_EMAC_testCallbackTxComplete(void* ICSS_EmacSubSysHandle, void* queueNum);

int32_t ICSS_EMAC_testCallbackRxPacket(void* queueNum, void* ICSS_EmacSubSysHandle);
int32_t ICSS_EMAC_testCallbackRxPacket1(void* queueNum, void* ICSS_EmacSubSysHandle);
int32_t ICSS_EMAC_testCallbackRxPacket2(void* queueNum, void* ICSS_EmacSubSysHandle);
int32_t ICSS_EMAC_testCallbackRxPacket3(void* queueNum, void* ICSS_EmacSubSysHandle);

bool ICSS_EMAC_testRxPktParser(ICSS_EmacHandle handle, void *pIcssRxPktInfo);
/* TTS functions */
int8_t ICSS_EMAC_testTtsInit(ICSS_EmacHandle icssEmacHandle, uint32_t cyclePeriod);
int8_t    ICSS_EMAC_testTtsSemCreate();
void      ICSS_EMAC_testTtsSemDestroy();


#ifdef __LINUX_USER_SPACE
void *ICSS_EMAC_testPort1TxTask(void *a0);
void *ICSS_EMAC_testPort2TxTask(void *a0);
#else
void ICSS_EMAC_testPort1TxTask(UArg a0, UArg a1);
void ICSS_EMAC_testPort2TxTask(UArg a0, UArg a1);
#endif


void ICSS_EMAC_testTtsCycPort1Callback();
void ICSS_EMAC_testTtsCycPort2Callback();

void ICSS_EMAC_testInterruptInit(ICSS_EmacHandle icssEmacHandle);
void ICSS_EMAC_testInterruptEnd(ICSS_EmacHandle icssEmacHandle);
void ICSS_EMAC_testInterruptEnable(ICSS_EmacHandle icssEmacHandle);
void ICSS_EMAC_testInterruptDisable(ICSS_EmacHandle icssEmacHandle);

int32_t ICSS_EMAC_testTimerSetup(ICSS_EmacHandle icssEmacHandle);
void ICSS_EMAC_testSocCtrlGetPortMacAddr(uint32_t addrIdx, uint8_t *pMacAddr);
void ICSS_EMAC_fwIntrPacingConfig(ICSSEMAC_Handle icssEmacHandle, uint8_t port, uint8_t intrPacStatus, uint32_t timerExpiration);

#ifndef __LINUX_USER_SPACE
void ICSS_EMAC_testPollControlTask(UArg a0, UArg a1);
#endif
#ifdef __LINUX_USER_SPACE
void *ICSS_EMAC_testTaskPruss1(void *a0);
void *ICSS_EMAC_testTaskPruss2(void *a0);
#else
Void ICSS_EMAC_testTaskPruss1(UArg a0, UArg a1);
Void ICSS_EMAC_testTaskPruss2(UArg a0, UArg a1);
Void ICSS_EMAC_testTask_am65xx(UArg a0, UArg a1);

#ifdef __cplusplus
}
#endif

#endif
