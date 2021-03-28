/**
 * @file test_common_utils.c
 * @brief Contains utility APIs used by icss_emac unit tests. 
 *
 */

/* Copyright (C) {2016-2020} Texas Instruments Incorporated - http://www.ti.com/
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
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdlib.h>
#include <assert.h>

#ifdef __LINUX_USER_SPACE
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <semaphore.h>
#include "mmap_helper.h"
#else
#include <ti/sysbios/knl/Task.h>

#ifdef _TMS320C6X
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/EventCombiner.h>
#endif

#include <xdc/std.h>
#endif

#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_iep.h>

#ifndef __LINUX_USER_SPACE
#include <ti/drv/uart/UART_stdio.h>
#endif

#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/test/src/test_common_utils.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>

#ifdef SWITCH_EMAC
#include <ti/drv/icss_emac/test/src/tiswitch_pruss_intc_mapping.h>
#include <ti/drv/icss_emac/firmware/icss_switch/config/icss_emacFwVersion.h>
#else
#include <ti/drv/icss_emac/test/src/tiemac_pruss_intc_mapping.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/config/icss_emacFwVersion.h>
#endif

#include <ti/drv/icss_emac/firmware/icss_dualemac/config/icss_emacFwConfig.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/src/icss_rx_int_pacing_mmap.h>

#if defined(icev2AM335x) || defined(iceAMIC110)
#include <ti/starterware/include/hw/soc_am335x.h>
#include <ti/csl/src/ip/icss/V0/cslr_icssm_iep.h>
uint32_t ICSS_EMAC_testIepCounterOffset = CSL_ICSSM_IEP_COUNT;
#elif defined(idkAM437x)
#include <ti/starterware/include/hw/hw_control_am43xx.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/csl/src/ip/icss/V0/cslr_icssm_iep.h>
uint32_t ICSS_EMAC_testIepCounterOffset = CSL_ICSSM_IEP_COUNT;
#elif defined(idkAM572x)|| defined(idkAM571x) || defined(iceK2G) || defined(idkAM574x) || defined(am65xx_evm)
#include <ti/csl/src/ip/icss/V1/cslr_icss_iep.h>
uint32_t ICSS_EMAC_testIepCounterOffset = CSL_ICSSIEP_COUNT_REG0;
#endif

#ifdef __JAILHOUSE_INMATE
#if defined(SOC_AM572x)
#include <ti/csl/soc/am572x/src/csl_device_xbar.h>
#elif defined (SOC_AM574x)
#include <ti/csl/soc/am574x/src/csl_device_xbar.h>
#endif
#endif
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>

#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>

#if defined(am65xx_evm)
#include <ti\drv\icss_emac\firmware\icss_dualemac\bin\am65xx\a53_0\REV2\PRU0_bin.h>
#include <ti\drv\icss_emac\firmware\icss_dualemac\bin\am65xx\a53_0\REV2\PRU1_bin.h>
#endif

#ifdef UNITY_INCLUDE_CONFIG_H
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif


/* PG version of EVM */
uint32_t ICSS_EMAC_testPgVersion = 0;

/* Flag to enable queue overflow check */
uint32_t enableQOverFlowCheck = 0;
#if defined(icev2AM335x) || defined(iceAMIC110)
static uint32_t ICSS_EMAC_testPruInstance2Done = 1;
#else
static uint32_t ICSS_EMAC_testPruInstance2Done = 0;
#endif

extern uint8_t ICSS_EMAC_testEvmType;

#ifdef UNITY_INCLUDE_CONFIG_H
/*
 *  ======== Unity set up and tear down ========
 */
void setUp(void)
{
    /* Do nothing */
}

void tearDown(void)
{
    /* Do nothing */
}
#endif

#ifndef __LINUX_USER_SPACE
#ifdef SWITCH_EMAC
void ICSS_EMAC_testStormPrevention(void);
#endif
#endif

#ifdef __LINUX_USER_SPACE
static inline void linux_sleep_ms(int ms) {
    struct timespec ts;
    ts.tv_sec = (ms)/1000; \
    ts.tv_nsec = (ms*1000000)%1000000000; \
    nanosleep(&ts, NULL);
}
#define SLEEP(t) linux_sleep_ms(t)
#define PRINT printf

#else
#define SLEEP Task_sleep
#define PRINT UART_printf
#endif

/* total number of packets received on all interfaces being tested, cummulative account */
uint32_t ICSS_EMAC_testTotalPktRcvd = 0;

#ifdef __LINUX_USER_SPACE
#include <ti/drv/pruss/soc/pruicss_v1.h>
tprussdrv *pruss_drv_handle;
tprussdrv *pruss_drv_handle2;
PRUICSS_HwAttrs linux_prussHwAttrs[PRUICCSS_INSTANCE_MAX-1];
PRUICSS_V1_Object linux_prussObjects[PRUICCSS_INSTANCE_MAX-1];
PRUICSS_Config linux_pruss_config[PRUICCSS_INSTANCE_MAX] = {
        {
            &(linux_prussObjects[0]),
            &(linux_prussHwAttrs[0])
        },
        {
            &(linux_prussObjects[1]),
            &(linux_prussHwAttrs[1])
        },
        {NULL, NULL}
    };
#endif

/* number of links which actually came up to test the interface */
static uint32_t  ICSS_EMAC_testLinkUpCount = 0;

/* Handle's to pru-icss instances */
extern PRUICSS_Handle ICSS_EMAC_testPruIcssHandle1;
extern PRUICSS_Handle ICSS_EMAC_testPruIcssHandle2;

/* Handle's to icss-emac  instances */
ICSS_EmacHandle ICSS_EMAC_testHandle = NULL; 
ICSS_EmacHandle ICSS_EMAC_testHandle1 = NULL;
ICSS_EmacHandle ICSS_EMAC_testHandle2 = NULL;
ICSS_EmacHandle ICSS_EMAC_testHandle3 = NULL;


/*    TTS Global Variables    */
uint8_t    ICSS_EMAC_testTtsModePort1 = 0;
uint8_t    ICSS_EMAC_testTtsModePort2 = 0;
uint8_t    ICSS_EMAC_testTtsStartPort1 = 0;
uint8_t    ICSS_EMAC_testTtsStartPort2 = 0;

uint8_t ICSS_EMAC_testTtsRecvPktPort1[ICSS_EMAC_MAXMTU] = {0};
uint8_t ICSS_EMAC_testTtsRecvPktPort2[ICSS_EMAC_MAXMTU] = {0};


uint32_t ICSS_EMAC_testRecv_Q1PktCntPort1 = 0;
uint32_t ICSS_EMAC_testRecv_Q2PktCntPort1 = 0;
uint32_t ICSS_EMAC_testRecv_Q1PktCntPort2 = 0;
uint32_t ICSS_EMAC_testRecv_Q2PktCntPort2 = 0;


uint32_t ICSS_EMAC_testPacketRcvdPort0 = 0;
uint32_t ICSS_EMAC_testPacketRcvdPort1 = 0;
uint32_t ICSS_EMAC_testPacketRcvdPort2 = 0;
uint32_t ICSS_EMAC_testPacketRcvdPort3 = 0;


uint32_t ICSS_EMAC_testLinkIsrPru1Eth0 = 0;
uint32_t ICSS_EMAC_testLinkIsrPru1Eth1 = 0;
uint32_t ICSS_EMAC_testLinkIsrPru2Eth0 = 0;
uint32_t ICSS_EMAC_testLinkIsrPru2Eth1 = 0;


SemaphoreP_Handle    ICSS_EMAC_testTtsP1TxSem = NULL;
SemaphoreP_Handle    ICSS_EMAC_testTtsP2TxSem = NULL;
SemaphoreP_Handle    ICSS_EMAC_testTtsP1TimeSem = NULL;
SemaphoreP_Handle    ICSS_EMAC_testTtsP2TimeSem = NULL;
SemaphoreP_Handle    ICSS_EMAC_testTtsP1ResultSem = NULL;
SemaphoreP_Handle    ICSS_EMAC_testTtsP2ResultSem = NULL;

uint8_t ICSS_EMAC_testLclMac[6] = {0x01, 0xb2, 0xc1, 0xd4, 0xe4, 0xff};
uint8_t ICSS_EMAC_testLclMac1[6]= {0x02, 0xb3, 0xc2, 0xd4, 0xe4, 0xff};;
uint8_t ICSS_EMAC_testLclMac2[6] = {0x02, 0xb4, 0xc3, 0xdd, 0xee, 0xff};
uint8_t ICSS_EMAC_testLclMac3[6] = {0x02, 0xb5, 0xc4, 0xd4, 0xe4, 0xff};

uint8_t ICSS_EMAC_testPacketArrayInstance1[256] = {0};
uint8_t ICSS_EMAC_testPacketArrayInstance1_1[256] = {0};
uint8_t ICSS_EMAC_testPacketArrayInstance2[256] = {0};
uint8_t ICSS_EMAC_testPacketArrayInstance2_1[256] = {0};

uint32_t ICSS_EMAC_testPacketTxCompletePort0 = 0;
uint32_t ICSS_EMAC_testPacketTxCompletePort1 = 0;
uint32_t ICSS_EMAC_testPacketTxCompletePort2 = 0;
uint32_t ICSS_EMAC_testPacketTxCompletePort3 = 0;

uint32_t promisEnableFlag;

/* DO NOT CHANGE ICSS_EMAC_testPkt UNLESS ICSS_EMAC_ICSS_EMAC_TEST_PKT_SIZE IS UPDATED */
uint8_t ICSS_EMAC_testPkt[] = {
    0x02, 0xb2, 0xc1, 0xd4, 0xe4, 0xff, /* broadcast mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};
uint8_t ICSS_EMAC_testPkt1[] = {
    0x02, 0xb3, 0xc2, 0xd4, 0xe4, 0xff, /* broadcast mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};
uint8_t ICSS_EMAC_testPkt2[] = {
    0x02, 0xb4, 0xc3, 0xdd, 0xee, 0xff, /* broadcast mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};
uint8_t ICSS_EMAC_testPkt3[] = {
    0x02, 0xb5, 0xc4, 0xd4, 0xe4, 0xff, /* broadcast mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};
uint8_t ICSS_EMAC_testPktPromicuous[] = {
    0x02, 0xb0, 0xc3, 0xdd, 0xee, 0xff, /* broadcast mac */    
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};
/* DO NOT CHANGE ICSS_EMAC_testArpPktPort1 size UNLESS ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT1 IS UPDATED */
uint8_t ICSS_EMAC_testArpPktPort1[ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT1] = {
    0xc4, 0xbe, 0x84, 0xcc, 0xff, 0x1f,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0x81, 0x00, 0xe0, 0x00,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00, 0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* DO NOT CHANGE ICSS_EMAC_testArpPktPort2 size UNLESS ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT2 IS UPDATED */
uint8_t ICSS_EMAC_testArpPktPort2[ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT2] = {
    0xc4, 0xbe, 0x84, 0xcc, 0xff, 0x1f,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0x81, 0x00, 0xe0, 0x00,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00, 0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
/* DO NOT CHANGE ICSS_EMAC_testUdpPktPort1 size UNLESS ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT1 IS UPDATED */
uint8_t ICSS_EMAC_testUdpPktPort1[ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT1] = {
    0xc4, 0xbe, 0x84, 0xcc, 0xff, 0x1f,
    0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0x81, 0x00, 0x20, 0x00,
    0x08, 0x00, 0x45, 0x00,
    0x00, 0x2E, 0x00, 0x00, 0x40, 0x00,
    0x40, 0x11, 0xB7, 0x56, 0xC0, 0xA8,
    0x01, 0x16, 0xC0, 0xA8,
    0x01, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

/* DO NOT CHANGE ICSS_EMAC_testUdpPktPort2 size UNLESS ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT2 IS UPDATED */
uint8_t ICSS_EMAC_testUdpPktPort2[ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT2] = {
    0xc4, 0xbe, 0x84, 0xcc, 0xff, 0x1f,
    0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0x81, 0x00, 0x20, 0x00,
    0x08, 0x00, 0x45, 0x00,
    0x00, 0x2E, 0x00, 0x00, 0x40, 0x00,
    0x40, 0x11, 0xB7, 0x56, 0xC0, 0xA8,
    0x01, 0x16, 0xC0, 0xA8,
    0x01, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

uint8_t ICSS_EMAC_testPkt1Multicast[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, /* multicast destination mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};

uint8_t ICSS_EMAC_testPkt2Multicast[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x07, /* multicast destination mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};

/* Canned untagged packet for VLAN filtering test */
uint8_t ICSS_EMAC_testPkt1VlanUntagged[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xd4, 0xbe, 0xd9, 0x3d, 0xb6, 0xc1,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0xd4, 0xbe,
    0xd9, 0x3d, 0xb6, 0xc1, 0xc0, 0xa8, 0x03, 0x01,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xa8,
    0x03, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* Canned tagged packet for VLAN filtering test with VID = 1 */
uint8_t ICSS_EMAC_testPkt1VlanTagged[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xd4, 0xbe, 0xd9, 0x3d, 0xb6, 0xc1,
    0x81, 0x00, 0xa0, 0x01,
    0x08, 0x06, 0x00, 0x01, 0x08, 0x00, 0x06, 0x04,
    0x00, 0x01, 0xd4, 0xbe, 0xd9, 0x3d, 0xb6, 0xc1,
    0xc0, 0xa8, 0x03, 0x01, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0xa8, 0x03, 0x0a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

/* Canned priority packet for VLAN filtering test with VID = 0 */
uint8_t ICSS_EMAC_testPkt1VlanPriority[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xd4, 0xbe, 0xd9, 0x3d, 0xb6, 0xc1,
    0x81, 0x00, 0xa0, 0x00,
    0x08, 0x06, 0x00, 0x01, 0x08, 0x00, 0x06, 0x04,
    0x00, 0x01, 0xd4, 0xbe, 0xd9, 0x3d, 0xb6, 0xc1,
    0xc0, 0xa8, 0x03, 0x01, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0xa8, 0x03, 0x0a, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */



/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
bool ICSS_EMAC_testRxPktParser(ICSS_EmacHandle handle, void *pIcssRxPktInfo)
{
    char *pTemp = (char*) pIcssRxPktInfo;

    uint16_t ethType;
    ethType = *(uint16_t *)(pTemp  +  2 * ICSS_EMAC_TEST_ETH_ALEN);
    ethType = ICSS_EMAC_TEST_BYTESWAP16(ethType);

    /* to support VLAN filtering */
    if (ethType == ICSS_EMAC_TEST_VLAN_ETH_TYPE)
    {
        /* read the actual ethtype at an offset of 4 */
        ethType = *(uint16_t *)(pTemp  +  (2 * ICSS_EMAC_TEST_ETH_ALEN) + 4);
        ethType = ICSS_EMAC_TEST_BYTESWAP16(ethType);
    }

    if (ethType == ICSS_EMAC_TEST_ETHER_TYPE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

int32_t ICSS_EMAC_testGetPruStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle)
{
    if (icssEmacHandle == ICSS_EMAC_testHandle)
    {
        PRINT("\nPRU-ICSS STATS for PRU1ETH0, port: %d\n", portNum);
    }
    else if (icssEmacHandle == ICSS_EMAC_testHandle1)
    {
        PRINT("\nPRU-ICSS STATS for PRU1ETH1, port: %d\n", portNum);
    }
    else if (icssEmacHandle == ICSS_EMAC_testHandle2)
    {
        PRINT("\nPRU-ICSS STATS for PRU2ETH0, port: %d\n", portNum);
    }
    else if (icssEmacHandle == ICSS_EMAC_testHandle3)
    {
        PRINT("\nPRU-ICSS STATS for PRU2ETH1, port: %d\n", portNum);
    }
    else
    {
        PRINT("ICSS_EMAC_testGetPruStats: Invalid ICSS_EmacHandle, returning without stats\n");
        return -1;
    }
        
    ICSS_EmacReadStats(portNum, icssEmacHandle);
    ICSS_EmacPruStatistics_t* pruStatsPtr = (ICSS_EmacPruStatistics_t *)(((ICSS_EmacObject *)icssEmacHandle->object)->pruStat);

    PRINT("txBcast:0x%x\n", pruStatsPtr->txBcast);
    PRINT("txMcast:0x%x\n", pruStatsPtr->txMcast);
    PRINT("txUcast:0x%x\n", pruStatsPtr->txUcast);
    PRINT("txOctets:0x%x\n", pruStatsPtr->txOctets);
    
    PRINT("rxBcast:0x%x\n", pruStatsPtr->rxBcast);
    PRINT("rxMcast:0x%x\n", pruStatsPtr->rxMcast);
    PRINT("rxUcast:0x%x\n", pruStatsPtr->rxUcast);
    PRINT("rxOctets:0x%x\n", pruStatsPtr->rxOctets);

    PRINT("tx64byte:0x%x\n", pruStatsPtr->tx64byte);
    PRINT("tx65_127byte:0x%x\n", pruStatsPtr->tx65_127byte);
    PRINT("tx128_255byte:0x%x\n", pruStatsPtr->tx128_255byte);
    PRINT("tx512_1023byte:0x%x\n", pruStatsPtr->tx512_1023byte);
    PRINT("tx1024byte:0x%x\n", pruStatsPtr->tx1024byte);

    PRINT("rx64byte:0x%x\n", pruStatsPtr->rx64byte);
    PRINT("rx65_127byte:0x%x\n", pruStatsPtr->rx65_127byte);
    PRINT("rx128_255byte:0x%x\n", pruStatsPtr->rx128_255byte);
    PRINT("rx512_1023byte:0x%x\n", pruStatsPtr->rx512_1023byte);
    PRINT("rx1024byte:0x%x\n", pruStatsPtr->rx1024byte);

    PRINT("lateColl:0x%x\n", pruStatsPtr->lateColl);
    PRINT("singleColl:0x%x\n", pruStatsPtr->singleColl);
    PRINT("multiColl:0x%x\n", pruStatsPtr->excessColl);
    PRINT("excessColl:0x%x\n", pruStatsPtr->excessColl);

    PRINT("rxMisAlignmentFrames:0x%x\n", pruStatsPtr->rxMisAlignmentFrames);
    PRINT("stormPrevCounter:0x%x\n", pruStatsPtr->stormPrevCounter);
    PRINT("macRxError:0x%x\n", pruStatsPtr->macRxError);
    PRINT("SFDError:0x%x\n", pruStatsPtr->SFDError);
    PRINT("defTx:0x%x\n", pruStatsPtr->defTx);
    PRINT("macTxError:0x%x\n", pruStatsPtr->macTxError);
    PRINT("rxOverSizedFrames:0x%x\n", pruStatsPtr->rxOverSizedFrames);
    PRINT("rxUnderSizedFrames:0x%x\n", pruStatsPtr->rxUnderSizedFrames);
    PRINT("rxCRCFrames:0x%x\n", pruStatsPtr->rxCRCFrames);
    PRINT("droppedPackets:0x%x\n", pruStatsPtr->droppedPackets);

/* Debug variables, these are not part of standard MIB. Useful for debugging
    Reserved for future Use 
 */
    PRINT("txOverFlow:0x%x\n", pruStatsPtr->txOverFlow);
    PRINT("txUnderFlow:0x%x\n", pruStatsPtr->txUnderFlow);
    PRINT("sqeTestError:0x%x\n", pruStatsPtr->sqeTestError);
    PRINT("TXqueueLevel:0x%x\n", pruStatsPtr->TXqueueLevel);
    PRINT("CSError:0x%x\n\n", pruStatsPtr->CSError);

    return 0;
    
}

void ICSS_EMAC_testDrvInit(ICSS_EmacHandle handle, uint8_t instance) 
{

    /* LLD attributes mallocs */
    handle->object = (ICSS_EmacObject*)malloc(sizeof(ICSS_EmacObject));
    memset((void*)handle->object, 0, sizeof(ICSS_EmacObject));
    handle->hwAttrs= (ICSS_EmacHwAttrs*)malloc(sizeof(ICSS_EmacHwAttrs));
    memset(handle->object, 0, sizeof(ICSS_EmacObject));
    memset((void*)handle->hwAttrs, 0, sizeof(ICSS_EmacHwAttrs));

    /* Callback mallocs */
    ICSS_EmacCallBackObject* callBackObj = (ICSS_EmacCallBackObject*)malloc(sizeof(ICSS_EmacCallBackObject));

    callBackObj->learningExCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxRTCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->txCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    ((ICSS_EmacObject*)handle->object)->callBackHandle = callBackObj;

    /*Allocate memory for learning*/
    ((ICSS_EmacObject*)handle->object)->macTablePtr = (HashTable_t*)malloc(NUM_PORTS * sizeof(HashTable_t));

    /*Allocate memory for firmware-based learning*/
    ((ICSS_EmacObject*)handle->object)->fdb = (Fdb*)malloc(NUM_PORTS * sizeof(Fdb));

    /*Allocate memory for PRU Statistics*/
    ((ICSS_EmacObject*)handle->object)->pruStat = (ICSS_EmacPruStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacPruStatistics_t));

    /*Allocate memory for Host Statistics*/
    ((ICSS_EmacObject*)handle->object)->hostStat = (ICSS_EmacHostStatistics_t*)malloc(NUM_PORTS * sizeof(ICSS_EmacHostStatistics_t));

    /*Allocate memory for Storm Prevention*/
    ((ICSS_EmacObject*)handle->object)->stormPrevPtr = (stormPrevention_t*)malloc(NUM_PORTS * sizeof(stormPrevention_t));

    /* Base address initialization */
    if(NULL == ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg) {
        ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg =
                        (ICSS_EmacBaseAddressHandle_T)malloc(sizeof(ICSS_EmacBaseAddrCfgParams));
    }
    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg;

    ICSS_EmacSocGetInitCfg((instance-1), emacBaseAddr );

#ifdef __LINUX_USER_SPACE
    tprussdrv *pruss_handle = (instance==1 ? pruss_drv_handle:pruss_drv_handle2);
    ((ICSS_EmacObject*)handle->object)->pruss_drv_handle = pruss_handle;

    emacBaseAddr->dataRam0BaseAddr          = (uint32_t) pruss_handle->pru0_dataram_base;
    emacBaseAddr->dataRam1BaseAddr          = (uint32_t) pruss_handle->pru1_dataram_base;
    emacBaseAddr->l3OcmcBaseAddr            = (uint32_t) pruss_handle->l3Ocmc_base;
    emacBaseAddr->ecapBaseAddr              = (uint32_t) pruss_handle->pruss_ecap_base;
    emacBaseAddr->prussCfgRegs              = (uint32_t) pruss_handle->pruss_cfg_base;
    emacBaseAddr->prussIepRegs              = (uint32_t) pruss_handle->pruss_iep_base;
    emacBaseAddr->prussIntcRegs             = (uint32_t) pruss_handle->intc_base;
    emacBaseAddr->prussMiiMdioRegs          = (uint32_t) pruss_handle->pruss_mdio_base;
    emacBaseAddr->prussMiiRtCfgRegsBaseAddr = (uint32_t) pruss_handle->pruss_miirt_base;
    emacBaseAddr->prussPru0CtrlRegs         = (uint32_t) pruss_handle->pru0_control_base;
    emacBaseAddr->prussPru1CtrlRegs         = (uint32_t) pruss_handle->pru1_control_base;
    emacBaseAddr->sharedDataRamBaseAddr     = (uint32_t) pruss_handle->pruss_sharedram_base;
#ifdef iceK2G
    emacBaseAddr->l3OcmcBaseAddr_phys       = (uint32_t) pruss_handle->l3Ocmc_phy_base;
#else
    emacBaseAddr->l3OcmcBaseAddr_phys       = (uint32_t) ((pruss_handle->l3Ocmc_phy_base)&0xFFFF00|0x40000000);
#endif

    emacBaseAddr->sharedDataRamBaseAddr_phys = (uint32_t) emacBaseAddr->sharedDataRamBaseAddr;
    ICSS_EmacSocSetInitCfg((instance-1), emacBaseAddr );
#else
    /*    Restricting l3OcmcBaseAddr to 0x40xxxx00.
     *  This is done because L3 OCMC Base Address must be 256 byte aligned and to support OCMC memory usage for Linux Power Management.
     */
#ifndef iceK2G
    emacBaseAddr->l3OcmcBaseAddr =  (((emacBaseAddr->l3OcmcBaseAddr)&0xFFFF00)|0x40000000);
#endif
#if defined(am65xx_evm)
    emacBaseAddr->l3OcmcBaseAddr =0x70100000; //mapping OCMC to MSMC_H
#endif
    ICSS_EmacSocSetInitCfg((instance-1), emacBaseAddr );
#endif

    ICSS_EmacSocGetInitCfg((instance-1), emacBaseAddr );
    PRINT("ICSS_EMAC_testDrvInit: instance: %d, data0RamSize: 0x%x, data1RamSize: 0x%x, sharedDataRamSize: 0x%x, l3OcmcSize: 0x%x\n",
                instance, emacBaseAddr->dataRam0Size, emacBaseAddr->dataRam1Size, emacBaseAddr->sharedDataRamSize, emacBaseAddr->l3OcmcSize);

}

int32_t ICSS_EMAC_testCallbackTxComplete(void* ICSS_EmacSubSysHandle, void* queueNum)
{
    if(!(ICSS_EMAC_testTtsModePort1 | ICSS_EMAC_testTtsModePort2))
    {
        if((ICSS_EmacHandle)ICSS_EmacSubSysHandle ==  ICSS_EMAC_testHandle)
        {
            ICSS_EMAC_testPacketTxCompletePort0++;
        }
        else if((ICSS_EmacHandle)ICSS_EmacSubSysHandle == ICSS_EMAC_testHandle1)
        {
            ICSS_EMAC_testPacketTxCompletePort1++;
        }
        else if((ICSS_EmacHandle)ICSS_EmacSubSysHandle == ICSS_EMAC_testHandle2)
        {
            ICSS_EMAC_testPacketTxCompletePort2++;
        }
        else if((ICSS_EmacHandle)ICSS_EmacSubSysHandle == ICSS_EMAC_testHandle3)
        {
            ICSS_EMAC_testPacketTxCompletePort3++;
        }
        else
        {
            /* Error print */
            PRINT("packet transmission not complete for packet(ICSS_EMAC_TEST_PRU1ETH0): invalid Emac Sub System Handle passed  \n");
        }
    }
    return 0;
}
int32_t ICSS_EMAC_testCallbackRxPacket(void* queueNum, void* ICSS_EmacSubSysHandle)
{
    uint8_t         j;
    uint32_t        tmp;
    int32_t         packetLength;
    bool        etherType;
    ICSS_EmacRxArgument rxArgs;
    ICSS_EmacPktInfo rxPktInfo;
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle) ICSS_EmacSubSysHandle;
    rxArgs.icssEmacHandle = ICSS_EMAC_testHandle;
    rxArgs.queueNumber = *((uint32_t *)(queueNum));
    rxArgs.more = 0;
    rxArgs.port = 0;

    if(ICSS_EMAC_testTtsModePort1)
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testTtsRecvPktPort1[0]);
        memset(ICSS_EMAC_testTtsRecvPktPort1, 0, ICSS_EMAC_MAXMTU);
        if(icssEmacHandle == ICSS_EMAC_testHandle)
        {
                packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
                assert((packetLength != -1) && (packetLength != 0));
                /*    Extract packet number    */
                tmp = 0;
                for(j=0;j<4;j++)
                {
                    tmp = (tmp | (uint32_t)(ICSS_EMAC_testTtsRecvPktPort1[packetLength - j -1] << ((3-j)*8)));
                }

                if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE1)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q1PktCntPort1) != 1)
                    {
                         PRINT("\nTTS Port 1: Error in received cyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q1PktCntPort1, tmp);
                    }
                    ICSS_EMAC_testRecv_Q1PktCntPort1 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort1[0], &ICSS_EMAC_testArpPktPort1[0],ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT1)))
                    {
                         PRINT("\nTTS Port 1: Error in received cyclic pkt content. Packet mismatch.");
                    }
                    /*    If interrupt is for cyclic packet completion, post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP1TimeSem);
                }
                else if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE2)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q2PktCntPort1) != 1)
                    {
                         PRINT("\nTTS Port 1: Error in received acyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q2PktCntPort1, tmp);
                    }
                    ICSS_EMAC_testRecv_Q2PktCntPort1 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort1[0], &ICSS_EMAC_testUdpPktPort1[0],ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT1)))
                    {
                         PRINT("\nTTS Port 1: Error in received acyclic pkt content. Packet mismatch.");
                    }
                }

                /*    Check if mac cyclic and acyclic packet count is reached    */
                /*    This means test is over and we can print results    */
                if((ICSS_EMAC_testRecv_Q1PktCntPort1 == ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT) && (ICSS_EMAC_testRecv_Q2PktCntPort1 == ICSS_EMAC_TEST_TTS_MAX_ACYC_PKT_COUNT))
                {
                    /*    Post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP1ResultSem);
                }
        }
    }
    else
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testPacketArrayInstance1[0]);
        if(icssEmacHandle == ICSS_EMAC_testHandle)
        {
            for (tmp = 1; tmp; )
            {
                memset(&rxPktInfo,0, sizeof(ICSS_EmacPktInfo));
                ICSS_EmacRxPktInfo2(icssEmacHandle, &rxPktInfo);
                etherType = ICSS_EMAC_testRxPktParser(icssEmacHandle, (void*)rxPktInfo.rdBufferL3Addr);
                if (etherType != TRUE)
                {
                    PRINT("parser returned incorect values: rdBufferL3Addr 0x%x, port: 0x%x, queue: 0x%x\n",rxPktInfo.rdBufferL3Addr, rxPktInfo.portNumber, rxPktInfo.queueNumber);
                    return 0;
                }
                packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
            
            if(packetLength)
            {
                if (!(memcmp(&ICSS_EMAC_testPacketArrayInstance1[0], &ICSS_EMAC_testPkt[0],ICSS_EMAC_TEST_PKT_SIZE)))
                {
                    PRINT("ICSS_EMAC_testTaskPruss1(PRU1 ETH0): received pkt: %d\n", ICSS_EMAC_testTotalPktRcvd);
                    ICSS_EMAC_testTotalPktRcvd++;
                    ICSS_EMAC_testPacketRcvdPort0++; /* PRU1 ETH 0 */
                }
                else
                {
                    if(1U == promisEnableFlag)
                    {
                        ICSS_EMAC_testPacketRcvdPort0++;
                        /* PRINT("Unit Test Passed, Promiscuous mode packet mismatch occured\n"); */
                    }
                    else
                    {
                        PRINT("Unit Test Failure, packet mismatch occured\n");
                    }
                }
            }
            if(rxArgs.more== 0)
                    tmp = 0;    // exit if there are no more packets
            }
        }
    }
    return 0;
}



int32_t ICSS_EMAC_testCallbackRxPacket1(void* queueNum, void* ICSS_EmacSubSysHandle)
{
    uint8_t         j;
    uint32_t        tmp;
    int32_t         packetLength;
    ICSS_EmacRxArgument rxArgs;
    ICSS_EmacPktInfo rxPktInfo;
    bool etherType;
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle) ICSS_EmacSubSysHandle;
    rxArgs.icssEmacHandle = ICSS_EMAC_testHandle1;
    rxArgs.queueNumber = *((uint32_t *)(queueNum));
    rxArgs.more = 0;
    rxArgs.port = 0;
    
    if(ICSS_EMAC_testTtsModePort2)
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testTtsRecvPktPort2[0]);
        memset(ICSS_EMAC_testTtsRecvPktPort2, 0, ICSS_EMAC_MAXMTU);
        if(icssEmacHandle == ICSS_EMAC_testHandle1)
        {
                packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
                assert((packetLength != -1) && (packetLength != 0));
                /*    Extract packet number    */
                tmp = 0;
                for(j=0;j<4;j++)
                {
                    tmp = (tmp | (uint32_t)(ICSS_EMAC_testTtsRecvPktPort2[packetLength - j -1] << ((3-j)*8)));
                }

                if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE3)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q1PktCntPort2) != 1)
                    {
                         PRINT("\nTTS Port 2: Error in received cyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q1PktCntPort2, tmp);
                    }
                    ICSS_EMAC_testRecv_Q1PktCntPort2 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort2[0], &ICSS_EMAC_testArpPktPort2[0],ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT2)))
                    {
                         PRINT("\nTTS Port 2: Error in received cyclic pkt content. Packet mismatch.");
                    }
                    /*    If interrupt is for cyclic packet completion, post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP2TimeSem);
                }
                else if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE4)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q2PktCntPort2) != 1)
                    {
                         PRINT("\nTTS Port 2: Error in received acyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q2PktCntPort2, tmp);
                    }
                    ICSS_EMAC_testRecv_Q2PktCntPort2 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort2[0], &ICSS_EMAC_testUdpPktPort2[0],ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT2)))
                    {
                         PRINT("\nTTS Port 2: Error in received acyclic pkt content. Packet mismatch.");
                    }
                }

                /*    Check if mac cyclic and acyclic packet count is reached    */
                /*    This means test is over and we can print results    */
                if((ICSS_EMAC_testRecv_Q1PktCntPort2 == ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT) && (ICSS_EMAC_testRecv_Q2PktCntPort2 == ICSS_EMAC_TEST_TTS_MAX_ACYC_PKT_COUNT))
                {
                    /*    Post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP2ResultSem);
                }
        }
    }
    else
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testPacketArrayInstance1_1[0]);
        if(icssEmacHandle == ICSS_EMAC_testHandle1)
        {
            for (tmp = 1; tmp; )
            {
                memset(&rxPktInfo,0, sizeof(ICSS_EmacPktInfo));
                ICSS_EmacRxPktInfo2(icssEmacHandle, &rxPktInfo);
                etherType = ICSS_EMAC_testRxPktParser(icssEmacHandle, (void*)rxPktInfo.rdBufferL3Addr);
                if (etherType != TRUE)
                {
                    PRINT("parser returned incorect values: rdBufferL3Addr 0x%x, port: 0x%x, queue: 0x%x\n",rxPktInfo.rdBufferL3Addr, rxPktInfo.portNumber, rxPktInfo.queueNumber);
                    return 0;
                }
                packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
            if(packetLength)
            {
                if (!(memcmp(&ICSS_EMAC_testPacketArrayInstance1_1[0], &ICSS_EMAC_testPkt1[0],ICSS_EMAC_TEST_PKT_SIZE)))
                {
                    PRINT("ICSS_EMAC_testTaskPruss1(PRU1 ETH1): received pkt: %d\n", ICSS_EMAC_testTotalPktRcvd);
                    ICSS_EMAC_testTotalPktRcvd++;
                    ICSS_EMAC_testPacketRcvdPort1++; /* PRU1 ETH 0 */
                }
                else
                {
                    if(1U == promisEnableFlag)
                    {
                        ICSS_EMAC_testPacketRcvdPort1++;
                        /* PRINT("Unit Test Passed, Promiscuous mode packet mismatch occured\n"); */
                    }
                    else
                    {
                        PRINT("Unit Test Failure, packet mismatch occured\n");
                    }
                }
            }
            if(rxArgs.more== 0)
                tmp = 0;    // exit if there are no more packets
            }
        }
    }
    return 0;
}

int32_t ICSS_EMAC_testCallbackRxPacket2(void* queueNum, void* ICSS_EmacSubSysHandle)
{
    uint8_t         j;
    uint32_t        tmp;
    int32_t         packetLength;
    ICSS_EmacRxArgument rxArgs;
    ICSS_EmacPktInfo rxPktInfo;
    bool validEtherType;
     ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle) ICSS_EmacSubSysHandle;
    rxArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
    rxArgs.queueNumber = *((uint32_t *)(queueNum));
    rxArgs.more = 0;
    rxArgs.port = 0;

    if(ICSS_EMAC_testTtsModePort1)
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testTtsRecvPktPort1[0]);
        memset(ICSS_EMAC_testTtsRecvPktPort1, 0, ICSS_EMAC_MAXMTU);
        if(icssEmacHandle == ICSS_EMAC_testHandle2)
        {
                packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
                assert((packetLength != -1) && (packetLength != 0));
                /*    Extract packet number    */
                tmp = 0;
                for(j=0;j<4;j++)
                {
                    tmp = (tmp | (uint32_t)(ICSS_EMAC_testTtsRecvPktPort1[packetLength - j -1] << ((3-j)*8)));
                }

                if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE1)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q1PktCntPort1) != 1)
                    {
                         PRINT("\nTTS Port 1: Error in received cyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q1PktCntPort1, tmp);
                    }
                    ICSS_EMAC_testRecv_Q1PktCntPort1 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort1[0], &ICSS_EMAC_testArpPktPort1[0],ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT1)))
                    {
                         PRINT("\nTTS Port 1: Error in received cyclic pkt content. Packet mismatch.");
                    }
                    /*    If interrupt is for cyclic packet completion, post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP1TimeSem);
                }
                else if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE2)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q2PktCntPort1) != 1)
                    {
                         PRINT("\nTTS Port 1: Error in received acyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q2PktCntPort1, tmp);
                    }
                    ICSS_EMAC_testRecv_Q2PktCntPort1 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort1[0], &ICSS_EMAC_testUdpPktPort1[0],ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT1)))
                    {
                         PRINT("\nTTS Port 1: Error in received acyclic pkt content. Packet mismatch.");
                    }
                }

                /*    Check if mac cyclic and acyclic packet count is reached    */
                /*    This means test is over and we can print results    */
                if((ICSS_EMAC_testRecv_Q1PktCntPort1 == ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT) && (ICSS_EMAC_testRecv_Q2PktCntPort1 == ICSS_EMAC_TEST_TTS_MAX_ACYC_PKT_COUNT))
                {
                    /*    Post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP1ResultSem);
                }
        }
    }
    else
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testPacketArrayInstance2[0]);

        if(icssEmacHandle == ICSS_EMAC_testHandle2)
        {
            for (tmp = 1; tmp; )
            {
                memset(&rxPktInfo,0, sizeof(ICSS_EmacPktInfo));
                ICSS_EmacRxPktInfo2(icssEmacHandle, &rxPktInfo);
                validEtherType = ICSS_EMAC_testRxPktParser(icssEmacHandle, (void*)rxPktInfo.rdBufferL3Addr);
                if(enableQOverFlowCheck != 1)
                {
                    if (validEtherType != TRUE)
                    {
#if !defined (STP_SWITCH)
                        PRINT("parser returned incorect values: rdBufferL3Addr 0x%x, port: 0x%x, queue: 0x%x\n",rxPktInfo.rdBufferL3Addr, rxPktInfo.portNumber, rxPktInfo.queueNumber);
                        return 0;
#endif /* STP_SWITCH */
                    }
                    packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
                    
                }
                else
                {
                    ICSS_EMAC_testPacketRcvdPort2++; /* PRU2 ETH 0 */
                    packetLength = 0;
                    tmp = 0;
                }
                if(packetLength)
                {
#if defined (STP_SWITCH)		  		  
		  stp_switch_test(icssEmacHandle, rxPktInfo);
#else
                    if(!(memcmp(&ICSS_EMAC_testPacketArrayInstance2[0], &ICSS_EMAC_testPkt2[0],ICSS_EMAC_TEST_PKT_SIZE)))
                    {
                        PRINT("ICSS_EMAC_testTaskPruss2(PRU2 ETH0): received pkt: %d\n", ICSS_EMAC_testTotalPktRcvd);
                        ICSS_EMAC_testTotalPktRcvd++;
                        ICSS_EMAC_testPacketRcvdPort2++; /* PRU2 ETH 0 */
                    }
                    else
                    {
                        if(1U == promisEnableFlag)
                        {
                            ICSS_EMAC_testPacketRcvdPort2++;
                            /* PRINT("Unit Test Passed, Promiscuous mode packet mismatch occured\n"); */
                        }
                        else
                        {
                            PRINT("Unit Test Failure, packet mismatch occured\n");
                        }
                    }
#endif /* STP_SWITCH */
                }
                if(rxArgs.more== 0)
                    tmp = 0;    // exit if there are no more packets
            }
        }
    }
    return 0;
}


int32_t ICSS_EMAC_testCallbackRxPacket3(void* queueNum, void* ICSS_EmacSubSysHandle)
{
    uint8_t         j;
    uint32_t        tmp;
    int32_t         packetLength;
    ICSS_EmacRxArgument rxArgs;
    ICSS_EmacPktInfo rxPktInfo;
    bool etherType;
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle) ICSS_EmacSubSysHandle;

    rxArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
    rxArgs.queueNumber = *((uint32_t *)(queueNum));
    rxArgs.more = 0;
    rxArgs.port = 0;

    if(ICSS_EMAC_testTtsModePort2)
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testTtsRecvPktPort2[0]);
        memset(ICSS_EMAC_testTtsRecvPktPort2, 0, ICSS_EMAC_MAXMTU);
        if(icssEmacHandle == ICSS_EMAC_testHandle3)
        {
                packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
                assert((packetLength != -1) && (packetLength != 0));
                /*    Extract packet number    */
                tmp = 0;
                for(j=0;j<4;j++)
                {
                    tmp = (tmp | (uint32_t)(ICSS_EMAC_testTtsRecvPktPort2[packetLength - j -1] << ((3-j)*8)));
                }

                if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE3)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q1PktCntPort2) != 1)
                    {
                         PRINT("\nTTS Port 2: Error in received cyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q1PktCntPort2, tmp);
                    }
                    ICSS_EMAC_testRecv_Q1PktCntPort2 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort2[0], &ICSS_EMAC_testArpPktPort2[0],ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT2)))
                    {
                         PRINT("\nTTS Port 2: Error in received cyclic pkt content. Packet mismatch.");
                    }
                    /*    If interrupt is for cyclic packet completion, post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP2TimeSem);
                }
                else if((*((uint32_t *)(queueNum))) == ICSS_EMAC_QUEUE4)
                {
                    if((tmp - ICSS_EMAC_testRecv_Q2PktCntPort2) != 1)
                    {
                         PRINT("\nTTS Port 2: Error in received acyclic pkt sequence.\nPrevious seq no.: %u\nNew seq no.:%u", ICSS_EMAC_testRecv_Q2PktCntPort2, tmp);
                    }
                    ICSS_EMAC_testRecv_Q2PktCntPort2 = tmp;
                    if (0 != (memcmp(&ICSS_EMAC_testTtsRecvPktPort2[0], &ICSS_EMAC_testUdpPktPort2[0],ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT2)))
                    {
                         PRINT("\nTTS Port 2: Error in received acyclic pkt content. Packet mismatch.");
                    }
                }

                /*    Check if mac cyclic and acyclic packet count is reached    */
                /*    This means test is over and we can print results    */
                if((ICSS_EMAC_testRecv_Q1PktCntPort2 == ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT) && (ICSS_EMAC_testRecv_Q2PktCntPort2 == ICSS_EMAC_TEST_TTS_MAX_ACYC_PKT_COUNT))
                {
                    /*    Post semaphore    */
                    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP2ResultSem);
                }
        }
    }
    else
    {
        rxArgs.destAddress =  (uint32_t)(&ICSS_EMAC_testPacketArrayInstance2_1[0]);

        if(icssEmacHandle == ICSS_EMAC_testHandle3)
        {
            for (tmp = 1; tmp; )
            {
                memset(&rxPktInfo,0, sizeof(ICSS_EmacPktInfo));
                ICSS_EmacRxPktInfo2(icssEmacHandle, &rxPktInfo);
                etherType = ICSS_EMAC_testRxPktParser(icssEmacHandle, (void*)rxPktInfo.rdBufferL3Addr);
                if (etherType != TRUE)
                {
                    PRINT("parser returned incorect values: rdBufferL3Addr 0x%x, port: 0x%x, queue: 0x%x\n",rxPktInfo.rdBufferL3Addr, rxPktInfo.portNumber, rxPktInfo.queueNumber);
                    return 0;
                }
                packetLength = ICSS_EmacRxPktGet(&rxArgs, NULL);
            
            if(packetLength)
            {
               if (!(memcmp(&ICSS_EMAC_testPacketArrayInstance2_1[0], &ICSS_EMAC_testPkt3[0],ICSS_EMAC_TEST_PKT_SIZE)))
                {
                    PRINT("ICSS_EMAC_testTaskPruss2(PRU2 ETH1): received pkt: %d\n", ICSS_EMAC_testTotalPktRcvd);
                    ICSS_EMAC_testTotalPktRcvd++;
                    ICSS_EMAC_testPacketRcvdPort3++; /* PRU2 ETH 0 */
                }
                else
                {
                    if(1U == promisEnableFlag)
                    {
                        ICSS_EMAC_testPacketRcvdPort3++;
                        /* PRINT("Unit Test Passed, Promiscuous mode packet mismatch occured\n"); */
                    }
                    else
                    {
                        PRINT("Unit Test Failure, packet mismatch occured\n");
                    }
                }
            }
            if(rxArgs.more== 0)
                    tmp = 0;    // exit if there are no more packets
            }
        }
    }
    return 0;
}

/*
 * ---ICSS_EMAC Link Interrupt Service routine callback ---
 */
int32_t ICSS_EMAC_testLinkIsrCb(void* linkStatus, void* usrArg)
{
    uint32_t status = (uint32_t) linkStatus;
    uint32_t pruNum = (uint32_t)usrArg;


    if (pruNum > ICSS_EMAC_TEST_PRU2ETH1)
    {
         return -1;
    }
    if ((status  == 1) && (pruNum == ICSS_EMAC_TEST_PRU1ETH0))
    {
        ICSS_EMAC_testLinkIsrPru1Eth0++;
    }
    else if ((status  == 1) && (pruNum == ICSS_EMAC_TEST_PRU1ETH1))
    {
        ICSS_EMAC_testLinkIsrPru1Eth1++;
    }
    else if ((status  == 1) && (pruNum == ICSS_EMAC_TEST_PRU2ETH0))
    {
        ICSS_EMAC_testLinkIsrPru2Eth0++;
    }
    else if ((status  == 1) && (pruNum == ICSS_EMAC_TEST_PRU2ETH1))
    {
        ICSS_EMAC_testLinkIsrPru2Eth1++;
    }
    else
    {
        return -1;
    }
    return 0;
}


/*
 * ---TTS Cyclic Packet Insertion Interrupt Callback Port 1---
 */
void ICSS_EMAC_testTtsCycPort1Callback()
{
    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP1TxSem);
}

/*
 * ---TTS Cyclic Packet Insertion Interrupt Callback Port 2---
 */
void ICSS_EMAC_testTtsCycPort2Callback()
{
    ICSS_EMAC_osalPostLock(ICSS_EMAC_testTtsP2TxSem);
}

#ifndef am65xx_evm
#if defined (__ARM_ARCH_7A__) || defined (__TI_ARM_V7M4__)
/**
* @internal
* @brief Registering Interrupts and Enabling global interrupts
*
* @param icssEmacHandle  icssEmacHandle handle to ICSS_EMAC Instance.
*
* @retval none
*/
void ICSS_EMAC_testInterruptInit(ICSS_EmacHandle icssEmacHandle)
{
    HwiP_Handle rxHwiHandle;
    HwiP_Handle linkHwiHandle;
    HwiP_Handle txHwiHandle;

    static uint32_t cookie = 0;
    uint32_t linkIntrN = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum;

    uint32_t rxIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum;

    uint32_t txIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum;

    cookie = ICSS_EMAC_osalHardwareIntDisable();

    HwiP_Params hwiParams;

    ICSS_EMAC_osalHwiParamsInit(&hwiParams);

    hwiParams.arg = (uintptr_t)icssEmacHandle;
    hwiParams.evtId = 0;
    hwiParams.priority = 20;


#ifdef iceK2G
            hwiParams.triggerSensitivity =2; /* use trigger type edge */
#endif
    rxHwiHandle = ICSS_EMAC_osalRegisterInterrupt(rxIntrN, (HwiP_Fxn)ICSS_EmacRxInterruptHandler, &hwiParams);
    if (rxHwiHandle == NULL ){
        return;
    }


    hwiParams.arg = (uintptr_t)icssEmacHandle;
    hwiParams.evtId = 0;
    hwiParams.priority = 20;
    linkHwiHandle = ICSS_EMAC_osalRegisterInterrupt(linkIntrN, (HwiP_Fxn)ICSS_EmacLinkISR, &hwiParams);

    if (linkHwiHandle == NULL) {
        return;
    }

    hwiParams.arg = (uintptr_t)icssEmacHandle;
    hwiParams.evtId = 0;
    hwiParams.priority = 20;
    txHwiHandle = ICSS_EMAC_osalRegisterInterrupt(txIntrN, (HwiP_Fxn)ICSS_EmacTxInterruptHandler, &hwiParams);


    if (txHwiHandle == NULL) {
        return;
    }
    ((ICSS_EmacObject*)icssEmacHandle->object)->txintHandle = txHwiHandle;

    ((ICSS_EmacObject*)icssEmacHandle->object)->rxintHandle = rxHwiHandle;
    ((ICSS_EmacObject*)icssEmacHandle->object)->linkintHandle = linkHwiHandle;

    ICSS_EMAC_osalHardwareIntRestore(cookie);
}
/**
* @internal
* @brief De-registering the interrupts and disabling global interrupts
*
* @param icssEmacHandle  icssEmacHandle handle to ICSS_EMAC Instance.
*
* @retval none
*/
void ICSS_EMAC_testInterruptEnd(ICSS_EmacHandle icssEmacHandle)
{
    if (icssEmacHandle != NULL)
    {
        ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->rxintHandle));
        ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->linkintHandle));
        ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->txintHandle));
    }
}
/**
* @internal
* @brief This function enables the EMAC interrupts
*
* @param icssEmacHandle  icssEmacHandle handle to ICSS_EMAC Instance.
*
* @retval none
*/
void ICSS_EMAC_testInterruptEnable(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t key = 0;
    if (icssEmacHandle != NULL)
    {
        key = ICSS_EMAC_osalHardwareIntDisable();
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum);
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum);
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum);
        ICSS_EMAC_osalHardwareIntRestore(key);
    }
}
/**
* @brief This function disables the EMAC interrupts
* @internal
* @param icssEmacHandle  icssEmacHandle handle to ICSS_EMAC Instance.
*
* @retval none
*/
void ICSS_EMAC_testInterruptDisable(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t key;
    if (icssEmacHandle != NULL)
    {
        key = ICSS_EMAC_osalHardwareIntDisable();

        ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum);
        ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum);
        ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum);

        ICSS_EMAC_osalHardwareIntRestore(key);
    }
}
#else

/**
* @internal
* @brief Registering Interrupts and Enabling global interrupts
*
* @param icssEmacHandle  icssEmacHandle handle to ICSS_EMAC Instance.
*
* @retval none
*/
void ICSS_EMAC_testInterruptInit(ICSS_EmacHandle icssEmacHandle)
{

#ifdef iceK2G
    static uint32_t cookie = 0;
    MuxIntcP_inParams       muxInParams;
    MuxIntcP_outParams      muxOutParams;
    HwiP_Handle hwiHandle;
    cookie = ICSS_EMAC_osalHardwareIntDisable();

    muxInParams.arg         = (uintptr_t)icssEmacHandle;
    muxInParams.muxNum      = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.intcMuxNum;
    muxInParams.muxInEvent  = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.intcMuxInEvent;
    muxInParams.muxOutEvent = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.intcMuxOutEvent;
    muxInParams.muxIntcFxn  = (MuxIntcFxn)(&ICSS_EmacLinkISR);

     ICSS_EMAC_osalMuxIntcSetup(&muxInParams, &muxOutParams);

    EventCombiner_dispatchPlug ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.eventId,
                                                (EventCombiner_FuncPtr)muxOutParams.muxIntcFxn, (UArg)muxOutParams.arg, TRUE);
    EventCombiner_enableEvent( (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.eventId);

    muxInParams.arg         = (uintptr_t)icssEmacHandle;
    muxInParams.muxNum      = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.intcMuxNum;
    muxInParams.muxInEvent  = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.intcMuxInEvent;
    muxInParams.muxOutEvent = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.intcMuxOutEvent;
    muxInParams.muxIntcFxn  = (MuxIntcFxn)(&ICSS_EmacRxInterruptHandler);

     ICSS_EMAC_osalMuxIntcSetup(&muxInParams, &muxOutParams);

    EventCombiner_dispatchPlug ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.eventId,
                                                (EventCombiner_FuncPtr)muxOutParams.muxIntcFxn, (UArg)muxOutParams.arg, TRUE);
    EventCombiner_enableEvent( (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.eventId);

    muxInParams.arg         = (uintptr_t)icssEmacHandle;
    muxInParams.muxNum      = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.intcMuxNum;
    muxInParams.muxInEvent  = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.intcMuxInEvent;
    muxInParams.muxOutEvent = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.intcMuxOutEvent;
    muxInParams.muxIntcFxn  = (MuxIntcFxn)(&ICSS_EmacTxInterruptHandler);


     ICSS_EMAC_osalMuxIntcSetup(&muxInParams, &muxOutParams);

    EventCombiner_dispatchPlug ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.eventId,
                                                (EventCombiner_FuncPtr)muxOutParams.muxIntcFxn, (UArg)muxOutParams.arg, TRUE);
    EventCombiner_enableEvent( (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.eventId);

#else

    static uint32_t cookie = 0;
    uint8_t linkIntrN = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum;

    uint8_t rxIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum;

    uint8_t txIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum;

    cookie = ICSS_EMAC_osalHardwareIntDisable();

    EventCombiner_dispatchPlug (linkIntrN, (EventCombiner_FuncPtr)ICSS_EmacLinkISR, (UArg)icssEmacHandle, TRUE);
    EventCombiner_enableEvent(linkIntrN);


    EventCombiner_dispatchPlug (rxIntrN, (EventCombiner_FuncPtr)ICSS_EmacRxInterruptHandler, (UArg)icssEmacHandle, TRUE);
    EventCombiner_enableEvent(rxIntrN);

    EventCombiner_dispatchPlug (txIntrN, (EventCombiner_FuncPtr)ICSS_EmacTxInterruptHandler, (UArg)icssEmacHandle, TRUE);

    EventCombiner_enableEvent(txIntrN);
    ICSS_EMAC_osalHardwareIntRestore(cookie);

#endif

ICSS_EMAC_osalHardwareIntRestore(cookie);

}

/**
* @internal
* @brief This function enables the EMAC interrupts
*
* @param icssEmacHandle  icssEmacHandle handle to ICSS_EMAC Instance.
*
* @retval none
*/
void ICSS_EMAC_testInterruptEnable(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t key = 0;
    if (icssEmacHandle != NULL)
    {
        key = ICSS_EMAC_osalHardwareIntDisable();
    
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum);
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum);
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum);
    
        ICSS_EMAC_osalHardwareIntRestore(key);
    }
}
/**
* @brief This function disables the EMAC interrupts
* @internal
* @param icssEmacHandle  icssEmacHandle handle to ICSS_EMAC Instance.
*
* @retval none
*/
void ICSS_EMAC_testInterruptDisable(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t key = 0;
    if (icssEmacHandle != NULL)
    {
        uint8_t linkIntrN = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum;
        uint8_t rxIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum;

      
        uint8_t txIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum;

        key = ICSS_EMAC_osalHardwareIntDisable();

        EventCombiner_disableEvent(linkIntrN);
        EventCombiner_disableEvent(rxIntrN);
        EventCombiner_disableEvent(txIntrN);

        ICSS_EMAC_osalHardwareIntRestore(key);
    }
}
#endif

#endif
/*
 *     ---function to create TTS Semaphores---
 */
int8_t    ICSS_EMAC_testTtsSemCreate()
{
    SemaphoreP_Params semParams;

    /*    Creating semaphores for TTS Task Port 1    */

    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    semParams.name = "ttsPort1TxSemaphore";
    ICSS_EMAC_testTtsP1TxSem =  ICSS_EMAC_osalCreateBlockingLock(0, &semParams);
    if(ICSS_EMAC_testTtsP1TxSem == NULL)
    {
            return -1;
    }

    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    semParams.name = "ttsPort1TimestampSemaphore";
    ICSS_EMAC_testTtsP1TimeSem =  ICSS_EMAC_osalCreateBlockingLock(0, &semParams);
    if(ICSS_EMAC_testTtsP1TimeSem == NULL)
    {
            return -1;
    }

    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    semParams.name = "ttsPort1ResultSemaphore";
    ICSS_EMAC_testTtsP1ResultSem =  ICSS_EMAC_osalCreateBlockingLock(0, &semParams);
    if(ICSS_EMAC_testTtsP1ResultSem == NULL)
    {
            return -1;
    }

    /*    Creating semaphores for TTS Task Port 2    */

    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    semParams.name = "ttsPort2TxSemaphore";
    ICSS_EMAC_testTtsP2TxSem =  ICSS_EMAC_osalCreateBlockingLock(0, &semParams);
    if(ICSS_EMAC_testTtsP2TxSem == NULL)
    {
            return -1;
    }

    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    semParams.name = "ttsPort2TimestampSemaphore";
    ICSS_EMAC_testTtsP2TimeSem =  ICSS_EMAC_osalCreateBlockingLock(0, &semParams);
    if(ICSS_EMAC_testTtsP2TimeSem == NULL)
    {
            return -1;
    }

    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_COUNTING;
    semParams.name = "ttsPort2ResultSemaphore";
    ICSS_EMAC_testTtsP2ResultSem =  ICSS_EMAC_osalCreateBlockingLock(0, &semParams);
    if(ICSS_EMAC_testTtsP2ResultSem == NULL)
    {
            return -1;
    }

    return 0;
}

#ifndef __LINUX_USER_SPACE
/* Entry point for PollControlTask */
void ICSS_EMAC_testPollControlTask(UArg a0, UArg a1)
{
     while (1)
    {
        if (ICSS_EMAC_testHandle)
        {
            ICSS_EmacPollControl(ICSS_EMAC_testHandle, ICSS_EMAC_POLL_MODE_LINK | ICSS_EMAC_POLL_MODE_TX_COMPLETE | ICSS_EMAC_POLL_MODE_RX_PKT);
        }
        if (ICSS_EMAC_testHandle1)
        {
            ICSS_EmacPollControl(ICSS_EMAC_testHandle1, ICSS_EMAC_POLL_MODE_LINK | ICSS_EMAC_POLL_MODE_TX_COMPLETE | ICSS_EMAC_POLL_MODE_RX_PKT);
        }
        if (ICSS_EMAC_testHandle2)
        {
            ICSS_EmacPollControl(ICSS_EMAC_testHandle2, ICSS_EMAC_POLL_MODE_LINK | ICSS_EMAC_POLL_MODE_TX_COMPLETE | ICSS_EMAC_POLL_MODE_RX_PKT);
        }
        if (ICSS_EMAC_testHandle3)
        {
            ICSS_EmacPollControl(ICSS_EMAC_testHandle3, ICSS_EMAC_POLL_MODE_LINK | ICSS_EMAC_POLL_MODE_TX_COMPLETE | ICSS_EMAC_POLL_MODE_RX_PKT);
        }
        Task_yield();
    }
}
#endif
/*
 *     ---function to destryoy TTS Semaphores---
 */
void    ICSS_EMAC_testTtsSemDestroy()
{
    /*    Destroying semaphores for TTS Task Port 1    */
    ICSS_EMAC_osalDeleteBlockingLock(ICSS_EMAC_testTtsP1TxSem);
    ICSS_EMAC_osalDeleteBlockingLock(ICSS_EMAC_testTtsP1TimeSem);
    ICSS_EMAC_osalDeleteBlockingLock(ICSS_EMAC_testTtsP1ResultSem);
    /*    Destroying semaphores for TTS Task Port 2    */
    ICSS_EMAC_osalDeleteBlockingLock(ICSS_EMAC_testTtsP2TxSem);
    ICSS_EMAC_osalDeleteBlockingLock(ICSS_EMAC_testTtsP2TimeSem);
    ICSS_EMAC_osalDeleteBlockingLock(ICSS_EMAC_testTtsP2ResultSem);
}

#ifdef __LINUX_USER_SPACE
static void clear_TTS_int_if_set(ICSS_EmacHandle icssEmacHandle) {
    fd_set rfds;
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycInt_fd, &rfds);

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    retval = select(((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycInt_fd + 1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        PRINT("In TTSInit(): Error calling select()\n");
    } else if (retval) {
        //PRINT("In TTSInit(): TTS int already set\n");
        wait_interrupt(((ICSS_EmacObject*)icssEmacHandle->object)->pruss_drv_handle,
                                             (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum,
                       ((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycInt_fd);
    } else {
        //PRINT("In TTSInit(): TTS int not already set\n");
    }
}
#endif

//#define DEBUG_TIMING_PRUSS
#ifdef DEBUG_TIMING_PRUSS
uint32_t int_arr_drv_port1[10005];
uint32_t int_arr_drv_port2[10005];
uint32_t index_port1, index_port2;
#endif
/*
 *    --- TTS Unit Test Task Port 1---
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMAC_testPort1TxTask(void *a0)
#else
void ICSS_EMAC_testPort1TxTask(UArg a0, UArg a1)
#endif
{
    uint32_t j = 0;
    uint32_t k = 0;
    //uint8_t ret = 0;
    int32_t ret = 0;

    uint8_t portNumber;
    uint32_t *addr = 0;
    uint32_t cyclePeriod;
    uint8_t tts_error = 0;
    uint32_t timestamp = 0;
    uint32_t max_jitter = 0;
    uint32_t q1_pkt_cnt = 0;
    uint32_t q2_pkt_cnt = 0;
    uint32_t t_delta_quo = 0;
    uint32_t t_delta_rem = 0;
    ICSS_EmacTTSQuery ttsQuery;
    ICSS_EmacTxArgument txArgs;
    uint32_t pkt_period_avg = 0;
    uint64_t pkt_period_sum = 0;
    uint32_t timestamp_prev = 0;
    uint32_t timestamp_delta = 0;
    ICSS_EmacTTSConfig ttsConfig;
    ICSSEMAC_IoctlCmd ioctlParams;
    ICSSEMAC_IoctlCmd ioctlParams2;
    ICSS_EmacHandle icssEmacHandle;
    uint32_t missed_cycle_count = 0;
    uint32_t pkt_missed_cycle_cnt = 0;

#ifdef DEBUG_TIMING_PRUSS
    uint32_t int_timestamp_pend[10000];
    uint32_t int_timestamp_arr[10000];
    uint32_t queue_timestamp_arr[10000];
    uint32_t acyclic_queue_timestamp_arr[10000];
    uint32_t send_timestamp_arr[10000];
    uint32_t rx_timestamp_arr[10000];

    uint32_t max_int = 0;
    uint32_t max_queue_cyclic = 0;
    uint32_t max_int_and_queue_cyclic = 0;
    uint32_t max_queue_acyclic = 0;
    uint32_t max_int_and_queue = 0;
    uint32_t max_pkt_rx = 0;
    uint32_t max_post_rx = 0;

    uint32_t min_int = 0xFFFFFFFF;
    uint32_t min_queue_cyclic = 0xFFFFFFFF;
    uint32_t min_queue_acyclic = 0xFFFFFFFF;
    uint32_t min_int_and_queue_cyclic = 0xFFFFFFFF;
    uint32_t min_int_and_queue = 0xFFFFFFFF;
    uint32_t min_pkt_rx = 0xFFFFFFFF;
    uint32_t min_post_rx = 0xFFFFFFFF;

    char timestamp_filename[50];
    char benchmark_filename[50];

    extern uint32_t cycle_period_port1;
    extern uint32_t config_time;
    extern uint32_t num_iteration;
    sprintf(timestamp_filename, "timestamps_port1_iter%d_cycle%d_cfg%d", num_iteration, cycle_period_port1, config_time);
    sprintf(benchmark_filename, "benchmark_port1_iter%d_cycle%d_cfg%d", num_iteration, cycle_period_port1, config_time);

    FILE *timestamp_file = fopen(timestamp_filename, "w+");
    FILE *benchmark_file = fopen(benchmark_filename, "w+");

    fprintf(benchmark_file, "index min_int_latency_drv max_int_latency_drv min_int max_int min_int_latency_diff max_int_latency_diff min_queue_cyclic max_queue_cyclic min_pkt_rx max_pkt_rx min_post_rx max_post_rx \n");

    index_port1 = 0;
#endif

#if defined(idkAM572x)
#ifdef __LINUX_USER_SPACE
    ICSS_EMAC_testPgVersion = 2;
#else
    ICSS_EMAC_testPgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;
#endif
#elif defined(idkAM574x)
    ICSS_EMAC_testPgVersion = 2;
#endif
    
    /*    Wait for TTS Test to be started    */
    while(!ICSS_EMAC_testTtsModePort1)
    {
        SLEEP(1);
    }

    /*    Initialize TTS Parameters    */
    if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM571x)
    {
        icssEmacHandle = ICSS_EMAC_testHandle;
    }
     else if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_ICEV2AM335x)
    {
        icssEmacHandle = ICSS_EMAC_testHandle;
    }
    else
    {
        icssEmacHandle = ICSS_EMAC_testHandle2;
    }

    portNumber = ICSS_EMAC_PORT_1;

#ifdef __LINUX_USER_SPACE
    extern uint32_t cycle_period_port1;
    cyclePeriod = cycle_period_port1;
#else
    cyclePeriod = ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1;
#endif

    assert((icssEmacHandle == ICSS_EMAC_testHandle) || (icssEmacHandle == ICSS_EMAC_testHandle2));

    ttsQuery.icssEmacHandle = icssEmacHandle;
    ttsQuery.portNumber = portNumber;
    ttsQuery.statusTTS = 0;
    ttsQuery.insertCycFrameNotification = 0;
    ttsQuery.cycTxSOFStatus = 0;
    ttsQuery.missedCycleCounter = 0;
    ttsQuery.cycTxSOF = 0;
    ioctlParams.command = 0;
    ioctlParams.ioctlVal = (void *)(&ttsQuery);

    txArgs.icssEmacHandle = icssEmacHandle;
    txArgs.portNumber = portNumber;

    /*    Test for multiple period values    */
#ifdef __LINUX_USER_SPACE
    extern uint32_t num_iteration;
    while(k < num_iteration)
#else
    while(k < 10)
#endif
    {
#ifdef __LINUX_USER_SPACE
        sem_init((sem_t*)ICSS_EMAC_testTtsP1TxSem, 0, 0);
#endif

        /*    Initialize time triggered send on PRU    */
        ICSS_EMAC_testTtsInit(icssEmacHandle, cyclePeriod);
        ICSS_EMAC_testTtsStartPort1 = 1;

        /*    Queueing packets    */
        while(j < ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT)
        {
            j++;

#ifdef DEBUG_TIMING_PRUSS
            int_timestamp_pend[q1_pkt_cnt] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif
            /*    Wait for cyclic packet insertion interrupt from PRU    */
            ICSS_EMAC_osalPendLock(ICSS_EMAC_testTtsP1TxSem, SemaphoreP_WAIT_FOREVER);

#ifdef DEBUG_TIMING_PRUSS
            int_timestamp_arr[q1_pkt_cnt] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Inserting cyclic packet count in pkt and transmitting    */
            addr = (uint32_t *)&(ICSS_EMAC_testArpPktPort1[ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT1 - 4]);
            *addr = (q1_pkt_cnt+1);
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT1;
            txArgs.queuePriority = ICSS_EMAC_QUEUE1;
            txArgs.srcAddress = &ICSS_EMAC_testArpPktPort1[0];
            ret = ICSS_EmacTxPacket(&txArgs, NULL);
            assert(ret != -1);
            q1_pkt_cnt++;

#ifdef DEBUG_TIMING_PRUSS
            queue_timestamp_arr[q1_pkt_cnt-1] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Inserting acyclic packet count in pkt and transmitting    */
            /*    Acyclic packet is sent after every few cycles    */
            if(q1_pkt_cnt%(ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT/ICSS_EMAC_TEST_TTS_MAX_ACYC_PKT_COUNT) == 0)
            {
                addr = (uint32_t *)&(ICSS_EMAC_testUdpPktPort1[ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT1 - 4]);
                *addr = (q2_pkt_cnt+1);
                txArgs.lengthOfPacket = ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT1;
                txArgs.queuePriority = ICSS_EMAC_QUEUE2;
                txArgs.srcAddress = &ICSS_EMAC_testUdpPktPort1[0];
                ret = ICSS_EmacTxPacket(&txArgs, NULL);
                if(ret != -1)
                    q2_pkt_cnt++;
            }

#ifdef DEBUG_TIMING_PRUSS
            acyclic_queue_timestamp_arr[q1_pkt_cnt-1] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Wait for RX interrupt from PRU    */
            ICSS_EMAC_osalPendLock(ICSS_EMAC_testTtsP1TimeSem, SemaphoreP_WAIT_FOREVER);

#ifdef DEBUG_TIMING_PRUSS
            rx_timestamp_arr[q1_pkt_cnt-1] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Query TTS status and timestamp from PRU    */
            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_STATUS_CTRL, portNumber, &ioctlParams);
            assert(ret == 0);
            timestamp = ttsQuery.cycTxSOF;
            assert(timestamp_prev != timestamp);
#ifdef DEBUG_TIMING_PRUSS
            send_timestamp_arr[q1_pkt_cnt-1] = timestamp;
#endif


            if(1 != q1_pkt_cnt)
            {
                /*    Process cyclic packet timestamp    */
                /*    For second cyclic pkt onwards, start processing    */
#if defined(idkAM572x) || defined(idkAM574x)
                if(ICSS_EMAC_testPgVersion >= 2)    /* 64-bit IEP    */
                {
                    timestamp_delta = timestamp - timestamp_prev;
                }
                else
                {
                    if(timestamp < timestamp_prev)    /* 32-bit IEP    */
                    {
                        timestamp_delta = (ICSS_EMAC_TTS_IEP_MAX_VAL - timestamp_prev) + timestamp;
                    }
                    else
                    {
                        timestamp_delta = timestamp - timestamp_prev;
                    }
                }
#elif defined(idkAM571x)
                timestamp_delta = timestamp - timestamp_prev;
#elif defined(idkAM437x) || defined(icev2AM335x) || defined(iceAMIC110)
                 /*Process cyclic packet timestamp */
                /*      For second cyclic pkt onwards, start processing */
                if(timestamp < timestamp_prev)  /* 32-bit IEP   */
                {
                    timestamp_delta = (ICSS_EMAC_TTS_IEP_MAX_VAL - timestamp_prev) + timestamp;
                }
                else
                {
                    timestamp_delta = timestamp - timestamp_prev;
                 }
#endif

                /*    Check if delta is acceptable    */
                if(abs(timestamp_delta - cyclePeriod) <= ICSS_EMAC_TEST_TTS_PERIOD_MARGIN)
                {
                    pkt_period_sum += timestamp_delta;
                    pkt_period_avg = (uint32_t)(pkt_period_sum/(q1_pkt_cnt - 1));
                    if(abs(timestamp_delta - cyclePeriod) > max_jitter)
                        max_jitter = abs(timestamp_delta - cyclePeriod);
                }
                else
                {
                    t_delta_rem = timestamp_delta % cyclePeriod;
                    t_delta_quo = timestamp_delta / cyclePeriod;
                    if((t_delta_rem <= ICSS_EMAC_TEST_TTS_PERIOD_MARGIN) || (t_delta_rem >= (cyclePeriod - ICSS_EMAC_TEST_TTS_PERIOD_MARGIN)))
                    {
                        pkt_missed_cycle_cnt += t_delta_quo;
                        pkt_period_sum += cyclePeriod;
                        pkt_period_avg = (uint32_t)(pkt_period_sum/q1_pkt_cnt);
                    }
                    else
                    {
                        PRINT("\n============================================================");
                        PRINT("\nTTS Port 1: Packet cyclic timestamp error.");
                        PRINT("\nProgrammed Cycle Period: %u ns", cyclePeriod);
                        PRINT("\nTimestamp_prev: %u ns\nTimestamp: %u ns\nDelta: %u ns", timestamp_prev, timestamp, timestamp_delta);
                        PRINT("\nCyclic Packet Number: %u", q1_pkt_cnt);
                        tts_error = 1;
                        break;
                    }
                }
            }
            timestamp_prev = timestamp;
        }

        if(!tts_error)
        {
            /*    Wait for any queued packets to be received    */
            ICSS_EMAC_osalPendLock(ICSS_EMAC_testTtsP1ResultSem, SemaphoreP_WAIT_FOREVER);

            /*    Setting tts status to disable (Port 1)    */
            ttsConfig.icssEmacHandle = icssEmacHandle;
            ttsConfig.statusTTS = ICSS_EMAC_TTS_DISABLE;
            ttsConfig.cyclePeriod = 0;
            ttsConfig.configTime = 0;
            ttsConfig.cycleStartTime = 0;
            ttsConfig.cycTxSOFStatus = ICSS_EMAC_TTS_CYC_TXSOF_DISABLE;
            ttsConfig.portNumber = portNumber;
            ioctlParams2.command = 0;
            ioctlParams2.ioctlVal = (void *)(&ttsConfig);

            /*    Disabling time triggered send on PORT 1 (PRU0).    */
            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_CTRL, portNumber, &ioctlParams2);
            assert(ret == 0);

            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_STATUS_CTRL, portNumber, &ioctlParams);
            assert(ret == 0);

            missed_cycle_count = ttsQuery.missedCycleCounter;

            /*    Wait for any packets to be received and for test to be finished on other PRU    */
            while((!((q1_pkt_cnt == ICSS_EMAC_testRecv_Q1PktCntPort1) && (q2_pkt_cnt == ICSS_EMAC_testRecv_Q2PktCntPort1) && ((missed_cycle_count - pkt_missed_cycle_cnt) <= 20))) || ICSS_EMAC_testTtsStartPort2)
            {
                SLEEP(1);
            }

            /*    Printing results now.    */
            if((q1_pkt_cnt == ICSS_EMAC_testRecv_Q1PktCntPort1) && (q2_pkt_cnt == ICSS_EMAC_testRecv_Q2PktCntPort1) && ((missed_cycle_count - pkt_missed_cycle_cnt) <= 20))
            {
                PRINT("\n============================================================");
                PRINT("\nTTS Port 1: Test Passed!!");
                PRINT("\nProgrammed Cycle Period: %u ns", cyclePeriod);
                PRINT("\nAverage Cycle Period: %u ns", pkt_period_avg);
                PRINT("\nMaximum Jitter: %u ns", max_jitter);
            }
            else
            {
                PRINT("\n============================================================");
                PRINT("\nTTS Port 1: Test Failed!!");
                PRINT("\nProgrammed Cycle Period: %u ns", cyclePeriod);
                PRINT("\nDisplaying results:");
                PRINT("\nNote: Missed cycles is permitted to be within a range of +/- 20.");

                PRINT("\n\nTransmit Information:");
                PRINT("\nCyclic Packets: %u", q1_pkt_cnt);
                PRINT("\nAcyclic Packets: %u", q2_pkt_cnt);
                PRINT("\nMissed Cycles: %u", pkt_missed_cycle_cnt);

                PRINT("\n\nReceive Information:");
                PRINT("\nCyclic Packets: %u", ICSS_EMAC_testRecv_Q1PktCntPort1);
                PRINT("\nAcyclic Packets: %u", ICSS_EMAC_testRecv_Q2PktCntPort1);
                PRINT("\nMissed Cycles: %u", missed_cycle_count);
            }
        }
        else
        {
            /*    Setting tts status to disable (Port 1)    */
            ttsConfig.icssEmacHandle = icssEmacHandle;
            ttsConfig.statusTTS = ICSS_EMAC_TTS_DISABLE;
            ttsConfig.cyclePeriod = 0;
            ttsConfig.configTime = 0;
            ttsConfig.cycleStartTime = 0;
            ttsConfig.cycTxSOFStatus = ICSS_EMAC_TTS_CYC_TXSOF_DISABLE;
            ttsConfig.portNumber = portNumber;
            ioctlParams2.command = 0;
            ioctlParams2.ioctlVal = (void *)(&ttsConfig);

            /*    Disabling time triggered send on PORT 1 (PRU0).    */
            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_CTRL, portNumber, &ioctlParams2);
            assert(ret == 0);

            /* Wait for test to be finished on other PRU */
            while(ICSS_EMAC_testTtsStartPort2)
            {
                SLEEP(1);
            }
        }

#ifdef DEBUG_TIMING_PRUSS
    {
                int wcnt;
                fprintf(benchmark_file, "%d ", k);
                uint32_t int_from_fw, int_latency, cyclic_queue, acyclic_queue, int_and_queue, int_and_queue_cyclic;
                uint32_t pkt_rx;
                uint32_t post_rx;
                uint32_t tx_complete, min_tx_complete=0xFFFFFFFF, max_tx_complete=0;
                uint32_t int_latency_drv, min_int_latency_drv=0xFFFFFFFF, max_int_latency_drv=0;
                uint32_t int_latency_diff, min_int_latency_diff=0xFFFFFFFF, max_int_latency_diff=0;

                max_int = 0;
                max_queue_cyclic = 0;
                max_queue_acyclic = 0;
                max_int_and_queue_cyclic = 0;
                max_int_and_queue = 0;
                max_pkt_rx = 0;
                max_post_rx = 0;

                min_int = 0xFFFFFFFF;
                min_queue_cyclic = 0xFFFFFFFF;
                min_queue_acyclic = 0xFFFFFFFF;
                min_int_and_queue_cyclic = 0xFFFFFFFF;
                min_int_and_queue = 0xFFFFFFFF;
                min_pkt_rx = 0xFFFFFFFF;
                min_post_rx = 0xFFFFFFFF;

                if(k<10) fprintf(timestamp_file, "int_timestamp_pend int_from_fw int_arr_drv_port1 int_timestamp_arr queue_timestamp_arr send_timestamp_arr rx_timestamp_arr int_latency_drv int_latency int_latency_diff cyclic_queue pkt_rx post_rx\n");
                for (wcnt = 1; wcnt < 10000; wcnt++) {

                    int_from_fw = send_timestamp_arr[wcnt] - config_time;
                    int_latency = int_timestamp_arr[wcnt] - int_from_fw;
                    cyclic_queue = queue_timestamp_arr[wcnt] - int_timestamp_arr[wcnt];
                    acyclic_queue = acyclic_queue_timestamp_arr[wcnt] - queue_timestamp_arr[wcnt];
                    int_and_queue_cyclic = int_latency + cyclic_queue;

                    if(int_latency > max_int) max_int = int_latency;
                    if(cyclic_queue > max_queue_cyclic) max_queue_cyclic = cyclic_queue;
                    if(acyclic_queue > max_queue_acyclic) max_queue_acyclic = acyclic_queue;
                    if(int_and_queue_cyclic > max_int_and_queue_cyclic) max_int_and_queue_cyclic = int_and_queue_cyclic;

                    if(int_latency < min_int) min_int = int_latency;
                    if(cyclic_queue < min_queue_cyclic) min_queue_cyclic = cyclic_queue;
                    if(acyclic_queue < min_queue_acyclic) min_queue_acyclic = acyclic_queue;
                    if(int_and_queue_cyclic < min_int_and_queue_cyclic) min_int_and_queue_cyclic = int_and_queue_cyclic;

                    int_latency_drv = int_arr_drv_port1[wcnt] - int_from_fw;
                    if (int_latency_drv < min_int_latency_drv) min_int_latency_drv = int_latency_drv;
                    if (int_latency_drv > max_int_latency_drv) max_int_latency_drv = int_latency_drv;

                    int_latency_diff = int_timestamp_arr[wcnt] -  int_arr_drv_port1[wcnt];
                    if (int_latency_diff < min_int_latency_diff) min_int_latency_diff = int_latency_diff;
                    if (int_latency_diff > max_int_latency_diff) max_int_latency_diff = int_latency_diff;

                    pkt_rx = rx_timestamp_arr[wcnt] - send_timestamp_arr[wcnt];
                    if(pkt_rx > max_pkt_rx)  max_pkt_rx = pkt_rx;
                    if(pkt_rx < min_pkt_rx) min_pkt_rx = pkt_rx;

                    if (wcnt>0)
                    {
                       post_rx = int_timestamp_pend[wcnt] - rx_timestamp_arr[wcnt-1];
                       if (post_rx > max_post_rx) max_post_rx = post_rx;
                       if (post_rx < min_post_rx) min_post_rx = post_rx;
                    }
                    if(k<10) fprintf(timestamp_file, "%u %u %u %u %u %u %u %u %u %u %u %u %u\n", int_timestamp_pend[wcnt], int_from_fw, int_arr_drv_port1[wcnt], int_timestamp_arr[wcnt], queue_timestamp_arr[wcnt], send_timestamp_arr[wcnt], rx_timestamp_arr[wcnt], int_latency_drv, int_latency, int_latency_diff, cyclic_queue, pkt_rx, post_rx);
                }

                if(!tts_error) {
                    fprintf(benchmark_file, "%u %u %u %u %u %u %u %u %u %u %u %u\n", min_int_latency_drv, max_int_latency_drv, min_int, max_int, min_int_latency_diff, max_int_latency_diff, min_queue_cyclic, max_queue_cyclic, min_pkt_rx, max_pkt_rx, min_post_rx, max_post_rx);
                } else {
                    fprintf(benchmark_file, "Test Failed!!!\n");
                }
       index_port1 = 0;
    }
#endif

        /*    Init next round of testing    */
        k++;
#ifndef __LINUX_USER_SPACE
        cyclePeriod +=    ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT1;
#endif
        q1_pkt_cnt = 0;
        q2_pkt_cnt = 0;
        j = 0;
        pkt_period_avg = 0;
        pkt_period_sum = 0;
        timestamp_delta = 0;
        t_delta_quo = 0;
        t_delta_rem = 0;
        max_jitter = 0;
        pkt_missed_cycle_cnt = 0;
        timestamp = 0;
        timestamp_prev = 0;
        missed_cycle_count = 0;
        ret = 0;
        tts_error = 0;

        /*    Signal PRU1 to print the results    */
        ICSS_EMAC_testTtsStartPort1 = 0;

        /*    Wait for results to be printed for the PRU1    */
        SLEEP(1);
    }
    ICSS_EMAC_testTtsModePort1 = 0;
}


/*
 *    --- TTS Unit Test Task Port 2---
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMAC_testPort2TxTask(void *a0)
#else
void ICSS_EMAC_testPort2TxTask(UArg a0, UArg a1)
#endif
{
    uint32_t j = 0;
    uint32_t k = 0;
    int32_t ret = 0;
    uint8_t portNumber;
    uint32_t *addr = 0;
    uint32_t cyclePeriod;
    uint8_t tts_error = 0;
    uint32_t timestamp = 0;
    uint32_t max_jitter = 0;
    uint32_t q1_pkt_cnt = 0;
    uint32_t q2_pkt_cnt = 0;
    uint32_t t_delta_quo = 0;
    uint32_t t_delta_rem = 0;
    ICSS_EmacTTSQuery ttsQuery;
    ICSS_EmacTxArgument txArgs;
    uint32_t pkt_period_avg = 0;
    uint64_t pkt_period_sum = 0;
    uint32_t timestamp_prev = 0;
    uint32_t timestamp_delta = 0;
    ICSS_EmacTTSConfig ttsConfig;
    ICSSEMAC_IoctlCmd ioctlParams;
    ICSSEMAC_IoctlCmd ioctlParams2;
    ICSS_EmacHandle icssEmacHandle;
    uint32_t missed_cycle_count = 0;
    uint32_t pkt_missed_cycle_cnt = 0;


#ifdef DEBUG_TIMING_PRUSS
    uint32_t int_timestamp_pend[10000];
    uint32_t int_timestamp_arr[10000];
    uint32_t queue_timestamp_arr[10000];
    uint32_t acyclic_queue_timestamp_arr[10000];
    uint32_t send_timestamp_arr[10000];
    uint32_t rx_timestamp_arr[10000];

    uint32_t max_int = 0;
    uint32_t max_queue_cyclic = 0;
    uint32_t max_int_and_queue_cyclic = 0;
    uint32_t max_queue_acyclic = 0;
    uint32_t max_int_and_queue = 0;
    uint32_t max_pkt_rx = 0;
    uint32_t max_post_rx = 0;

    uint32_t min_int = 0xFFFFFFFF;
    uint32_t min_queue_cyclic = 0xFFFFFFFF;
    uint32_t min_queue_acyclic = 0xFFFFFFFF;
    uint32_t min_int_and_queue_cyclic = 0xFFFFFFFF;
    uint32_t min_int_and_queue = 0xFFFFFFFF;
    uint32_t min_pkt_rx = 0xFFFFFFFF;
    uint32_t min_post_rx = 0xFFFFFFFF;

    char timestamp_filename[50];
    char benchmark_filename[50];

    extern uint32_t cycle_period_port2;
    extern uint32_t config_time;
    extern uint32_t num_iteration;

    sprintf(timestamp_filename, "timestamps_port2_iter%d_cycle%d_cfg%d", num_iteration, cycle_period_port2, config_time);
    sprintf(benchmark_filename, "benchmark_port2_iter%d_cycle%d_cfg%d", num_iteration, cycle_period_port2, config_time);

    FILE *timestamp_file = fopen(timestamp_filename, "w+");
    FILE *benchmark_file = fopen(benchmark_filename, "w+");

    fprintf(benchmark_file, "index min_int_latency_drv max_int_latency_drv min_int max_int min_int_latency_diff max_int_latency_diff min_queue_cyclic max_queue_cyclic min_pkt_rx max_pkt_rx min_post_rx max_post_rx \n");

    index_port2 = 0;
#endif
#if defined(idkAM572x)
#ifdef __LINUX_USER_SPACE
    ICSS_EMAC_testPgVersion = 2;
#else
    ICSS_EMAC_testPgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;
#endif
#elif defined(idkAM574x)
    ICSS_EMAC_testPgVersion = 2;
#endif

    /*    Wait for TTS Test to be started    */
    while(!ICSS_EMAC_testTtsModePort2)
    {
        SLEEP(1);
    }

    /*    Initialize TTS Parameters    */
    if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM571x)
    {
        icssEmacHandle = ICSS_EMAC_testHandle1;
    }
     else if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_ICEV2AM335x)
    {
        icssEmacHandle = ICSS_EMAC_testHandle1;
    }
    else
    {
        icssEmacHandle = ICSS_EMAC_testHandle3;
    }
    portNumber = ICSS_EMAC_PORT_2;

#ifdef __LINUX_USER_SPACE
    extern uint32_t cycle_period_port2;
    cyclePeriod = cycle_period_port2;
#else
    cyclePeriod = ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2;
#endif
    assert((icssEmacHandle == ICSS_EMAC_testHandle1) || (icssEmacHandle == ICSS_EMAC_testHandle3));

    ttsQuery.icssEmacHandle = icssEmacHandle;
    ttsQuery.portNumber = portNumber;
    ttsQuery.statusTTS = 0;
    ttsQuery.insertCycFrameNotification = 0;
    ttsQuery.cycTxSOFStatus = 0;
    ttsQuery.missedCycleCounter = 0;
    ttsQuery.cycTxSOF = 0;
    ioctlParams.command = 0;
    ioctlParams.ioctlVal = (void *)(&ttsQuery);

    txArgs.icssEmacHandle = icssEmacHandle;
    txArgs.portNumber = portNumber;

    /*    Test for multiple period values    */
#ifdef __LINUX_USER_SPACE
    extern uint32_t num_iteration;
    while(k < num_iteration)
#else
    while(k < 10)
#endif
    {
        /*    Wait for Port 1 TTS Init    */
        while(ICSS_EMAC_testTtsStartPort1 == 0)
        {
            SLEEP(1);
        }

#ifdef __LINUX_USER_SPACE
        sem_init((sem_t*)ICSS_EMAC_testTtsP2TxSem, 0, 0);
#endif

        /*    Initialize time triggered send on PRU    */
        ICSS_EMAC_testTtsInit(icssEmacHandle, cyclePeriod);
        ICSS_EMAC_testTtsStartPort2 = 1;

        /*    Queueing packets    */
        while(j < ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT)
        {
            j++;

#ifdef DEBUG_TIMING_PRUSS
            int_timestamp_pend[q1_pkt_cnt] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif
            /*    Wait for cyclic packet insertion interrupt from PRU    */
            ICSS_EMAC_osalPendLock(ICSS_EMAC_testTtsP2TxSem, SemaphoreP_WAIT_FOREVER);

#ifdef DEBUG_TIMING_PRUSS
            int_timestamp_arr[q1_pkt_cnt] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Inserting cyclic packet count in pkt and transmitting    */
            addr = (uint32_t *)&(ICSS_EMAC_testArpPktPort2[ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT2 - 4]);
            *addr = (q1_pkt_cnt+1);
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_ARP_PKT_SIZE_PORT2;
            txArgs.queuePriority = ICSS_EMAC_QUEUE1;
            txArgs.srcAddress = &ICSS_EMAC_testArpPktPort2[0];
            ret = ICSS_EmacTxPacket(&txArgs, NULL);
            assert(ret != -1);
            q1_pkt_cnt++;

#ifdef DEBUG_TIMING_PRUSS
            queue_timestamp_arr[q1_pkt_cnt-1] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Inserting acyclic packet count in pkt and transmitting    */
            /*    Acyclic packet is sent after every few cycles    */
            if(q1_pkt_cnt%(ICSS_EMAC_TEST_TTS_MAX_CYC_PKT_COUNT/ICSS_EMAC_TEST_TTS_MAX_ACYC_PKT_COUNT) == 0)
            {
                addr = (uint32_t *)&(ICSS_EMAC_testUdpPktPort2[ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT2 - 4]);
                *addr = (q2_pkt_cnt+1);
                txArgs.lengthOfPacket = ICSS_EMAC_TEST_UDP_PKT_SIZE_PORT2;
                txArgs.queuePriority = ICSS_EMAC_QUEUE2;
                txArgs.srcAddress = &ICSS_EMAC_testUdpPktPort2[0];
                ret = ICSS_EmacTxPacket(&txArgs, NULL);
                if(ret != -1)
                    q2_pkt_cnt++;
            }

#ifdef DEBUG_TIMING_PRUSS
            acyclic_queue_timestamp_arr[q1_pkt_cnt-1] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Wait for RX interrupt from PRU    */
            ICSS_EMAC_osalPendLock(ICSS_EMAC_testTtsP2TimeSem, SemaphoreP_WAIT_FOREVER);

#ifdef DEBUG_TIMING_PRUSS
            rx_timestamp_arr[q1_pkt_cnt-1] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + ICSS_EMAC_testIepCounterOffset);
#endif

            /*    Query TTS status and timestamp from PRU    */
            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_STATUS_CTRL, portNumber, &ioctlParams);
            assert(ret == 0);
            timestamp = ttsQuery.cycTxSOF;
            assert(timestamp_prev != timestamp);

#ifdef DEBUG_TIMING_PRUSS
            send_timestamp_arr[q1_pkt_cnt-1] = timestamp;
#endif

            if(1 != q1_pkt_cnt)
            {
                /*    Process cyclic packet timestamp    */
                /*    For second cyclic pkt onwards, start processing    */
#if defined(idkAM572x) || defined(idkAM574x)
                if(ICSS_EMAC_testPgVersion >= 2)    /* 64-bit IEP    */
                {
                    timestamp_delta = timestamp - timestamp_prev;
                }
                else
                {
                    if(timestamp < timestamp_prev)    /* 32-bit IEP    */
                    {
                        timestamp_delta = (ICSS_EMAC_TTS_IEP_MAX_VAL - timestamp_prev) + timestamp;
                    }
                    else
                    {
                        timestamp_delta = timestamp - timestamp_prev;
                    }
                }
#elif defined(idkAM571x)
                timestamp_delta = timestamp - timestamp_prev;
#endif

#if defined(idkAM437x) || defined(icev2AM335x) || defined(iceAMIC110)
 /*      Process cyclic packet timestamp */
                                /*      For second cyclic pkt onwards, start processing */
                                if(timestamp < timestamp_prev)  /* 32-bit IEP   */
                                {
                                        timestamp_delta = (ICSS_EMAC_TTS_IEP_MAX_VAL - timestamp_prev) + timestamp;
                                }
                                else
                                {
                                        timestamp_delta = timestamp - timestamp_prev;
                                }

#endif
                /*    Check if delta is acceptable    */
                if(abs(timestamp_delta - cyclePeriod) <= ICSS_EMAC_TEST_TTS_PERIOD_MARGIN)
                {
                    pkt_period_sum += timestamp_delta;
                    pkt_period_avg = (uint32_t)(pkt_period_sum/(q1_pkt_cnt - 1));
                    if(abs(timestamp_delta - cyclePeriod) > max_jitter)
                        max_jitter = abs(timestamp_delta - cyclePeriod);
                }
                else
                {
                    t_delta_rem = timestamp_delta % cyclePeriod;
                    t_delta_quo = timestamp_delta / cyclePeriod;
                    if((t_delta_rem <= ICSS_EMAC_TEST_TTS_PERIOD_MARGIN) || (t_delta_rem >= (cyclePeriod - ICSS_EMAC_TEST_TTS_PERIOD_MARGIN)))
                    {
                        pkt_missed_cycle_cnt += t_delta_quo;
                        pkt_period_sum += cyclePeriod;
                        pkt_period_avg = (uint32_t)(pkt_period_sum/q1_pkt_cnt);
                    }
                    else
                    {
                        PRINT("\n============================================================");
                        PRINT("\nTTS Port 2: Packet cyclic timestamp error.");
                        PRINT("\nProgrammed Cycle Period: %u ns", cyclePeriod);
                        PRINT("\nTimestamp_prev: %u ns\nTimestamp: %u ns\nDelta: %u ns", timestamp_prev, timestamp, timestamp_delta);
                        PRINT("\nCyclic Packet Number: %u", q1_pkt_cnt);
                        tts_error = 1;
                        break;
                    }
                }
            }
            timestamp_prev = timestamp;
        }

        if(!tts_error)
        {
            /*    Wait for any queued packets to be received    */
            ICSS_EMAC_osalPendLock(ICSS_EMAC_testTtsP2ResultSem, SemaphoreP_WAIT_FOREVER);

            /*    Setting tts status to disable (Port 2)    */
            ttsConfig.icssEmacHandle = icssEmacHandle;
            ttsConfig.statusTTS = ICSS_EMAC_TTS_DISABLE;
            ttsConfig.cyclePeriod = 0;
            ttsConfig.configTime = 0;
            ttsConfig.cycleStartTime = 0;
            ttsConfig.cycTxSOFStatus = ICSS_EMAC_TTS_CYC_TXSOF_DISABLE;
            ttsConfig.portNumber = portNumber;
            ioctlParams2.command = 0;
            ioctlParams2.ioctlVal = (void *)(&ttsConfig);

            /*    Disabling time triggered send on PORT 2 (PRU1).    */
            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_CTRL, portNumber, &ioctlParams2);
            assert(ret == 0);

            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_STATUS_CTRL, portNumber, &ioctlParams);
            assert(ret == 0);

            missed_cycle_count = ttsQuery.missedCycleCounter;

            /*    Signal PRU0 to print the results    */
            ICSS_EMAC_testTtsStartPort2 = 0;

            /*    Wait for PRU0 results to be printed    */
            /*    This is also sufficient time for any remaining packets to be recieved    */
            while(ICSS_EMAC_testTtsStartPort1)
            {
                SLEEP(1);
            }

            /*    Printing results now.    */
            if((q1_pkt_cnt == ICSS_EMAC_testRecv_Q1PktCntPort2) && (q2_pkt_cnt == ICSS_EMAC_testRecv_Q2PktCntPort2) && ((missed_cycle_count - pkt_missed_cycle_cnt) <= 20))
            {
                PRINT("\n============================================================");
                PRINT("\nTTS Port 2: Test Passed!!");
                PRINT("\nProgrammed Cycle Period: %u ns", cyclePeriod);
                PRINT("\nAverage Cycle Period: %u ns", pkt_period_avg);
                PRINT("\nMaximum Jitter: %u ns", max_jitter);
            }
            else
            {
                PRINT("\n============================================================");
                PRINT("\nTTS Port 2: Test Failed!!");
                PRINT("\nProgrammed Cycle Period: %u ns", cyclePeriod);
                PRINT("\nDisplaying results:");
                PRINT("\nNote: Missed cycles is permitted to be within a range of +/- 20.");

                PRINT("\n\nTransmit Information:");
                PRINT("\nCyclic Packets: %u", q1_pkt_cnt);
                PRINT("\nAcyclic Packets: %u", q2_pkt_cnt);
                PRINT("\nMissed Cycles: %u", pkt_missed_cycle_cnt);

                PRINT("\n\nReceive Information:");
                PRINT("\nCyclic Packets: %u", ICSS_EMAC_testRecv_Q1PktCntPort2);
                PRINT("\nAcyclic Packets: %u", ICSS_EMAC_testRecv_Q2PktCntPort2);
                PRINT("\nMissed Cycles: %u", missed_cycle_count);
            }
        }
        else
        {
            /*    Setting tts status to disable (Port 2)    */
            ttsConfig.icssEmacHandle = icssEmacHandle;
            ttsConfig.statusTTS = ICSS_EMAC_TTS_DISABLE;
            ttsConfig.cyclePeriod = 0;
            ttsConfig.configTime = 0;
            ttsConfig.cycleStartTime = 0;
            ttsConfig.cycTxSOFStatus = ICSS_EMAC_TTS_CYC_TXSOF_DISABLE;
            ttsConfig.portNumber = portNumber;
            ioctlParams2.command = 0;
            ioctlParams2.ioctlVal = (void *)(&ttsConfig);

            /*    Disabling time triggered send on PORT 2 (PRU1).    */
            ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_CTRL, portNumber, &ioctlParams2);
            assert(ret == 0);

            /* Signal PRU0 to print the results */
            ICSS_EMAC_testTtsStartPort2 = 0;
            /* Wait for PRU0 results to be printed    */
            while(ICSS_EMAC_testTtsStartPort1)
            {
                SLEEP(1);
            }
        }

#ifdef DEBUG_TIMING_PRUSS
    {
                int wcnt;
                fprintf(benchmark_file, "%d ", k);
                uint32_t int_from_fw, int_latency, cyclic_queue, acyclic_queue, int_and_queue, int_and_queue_cyclic;
                uint32_t pkt_rx;
                uint32_t post_rx;
                uint32_t int_latency_drv, min_int_latency_drv=0xFFFFFFFF, max_int_latency_drv=0;
                uint32_t int_latency_diff, min_int_latency_diff=0xFFFFFFFF, max_int_latency_diff=0;

                max_int = 0;
                max_queue_cyclic = 0;
                max_queue_acyclic = 0;
                max_int_and_queue_cyclic = 0;
                max_int_and_queue = 0;
                max_pkt_rx = 0;
                max_post_rx = 0;

                min_int = 0xFFFFFFFF;
                min_queue_cyclic = 0xFFFFFFFF;
                min_queue_acyclic = 0xFFFFFFFF;
                min_int_and_queue_cyclic = 0xFFFFFFFF;
                min_int_and_queue = 0xFFFFFFFF;
                min_pkt_rx = 0xFFFFFFFF;
                min_post_rx = 0xFFFFFFFF;

                if(k<10) fprintf(timestamp_file, "int_timestamp_pend int_from_fw int_arr_drv_port2 int_timestamp_arr queue_timestamp_arr send_timestamp_arr rx_timestamp_arr int_latency_drv int_latency int_latency_diff cyclic_queue pkt_rx post_rx\n");
                for (wcnt = 1; wcnt < 10000; wcnt++) {

                    int_from_fw = send_timestamp_arr[wcnt] - config_time;
                    int_latency = int_timestamp_arr[wcnt] - int_from_fw;
                    cyclic_queue = queue_timestamp_arr[wcnt] - int_timestamp_arr[wcnt];
                    acyclic_queue = acyclic_queue_timestamp_arr[wcnt] - queue_timestamp_arr[wcnt];
                    int_and_queue_cyclic = int_latency + cyclic_queue;

                    if(int_latency > max_int) max_int = int_latency;
                    if(cyclic_queue > max_queue_cyclic) max_queue_cyclic = cyclic_queue;
                    if(acyclic_queue > max_queue_acyclic) max_queue_acyclic = acyclic_queue;
                    if(int_and_queue_cyclic > max_int_and_queue_cyclic) max_int_and_queue_cyclic = int_and_queue_cyclic;

                    if(int_latency < min_int) min_int = int_latency;
                    if(cyclic_queue < min_queue_cyclic) min_queue_cyclic = cyclic_queue;
                    if(acyclic_queue < min_queue_acyclic) min_queue_acyclic = acyclic_queue;
                    if(int_and_queue_cyclic < min_int_and_queue_cyclic) min_int_and_queue_cyclic = int_and_queue_cyclic;

                    int_latency_drv = int_arr_drv_port2[wcnt] - int_from_fw;
                    if (int_latency_drv < min_int_latency_drv) min_int_latency_drv = int_latency_drv;
                    if (int_latency_drv > max_int_latency_drv) max_int_latency_drv = int_latency_drv;

                    int_latency_diff = int_timestamp_arr[wcnt] -  int_arr_drv_port2[wcnt];
                    if (int_latency_diff < min_int_latency_diff) min_int_latency_diff = int_latency_diff;
                    if (int_latency_diff > max_int_latency_diff) max_int_latency_diff = int_latency_diff;

                    pkt_rx = rx_timestamp_arr[wcnt] - send_timestamp_arr[wcnt];
                    if(pkt_rx > max_pkt_rx)  max_pkt_rx = pkt_rx;
                    if(pkt_rx < min_pkt_rx) min_pkt_rx = pkt_rx;

                    if (wcnt>0)
                    {
                       post_rx = int_timestamp_pend[wcnt] - rx_timestamp_arr[wcnt-1];
                       if (post_rx > max_post_rx) max_post_rx = post_rx;
                       if (post_rx < min_post_rx) min_post_rx = post_rx;
                    }
                    if(k<10) fprintf(timestamp_file, "%u %u %u %u %u %u %u %u %u %u %u %u %u\n", int_timestamp_pend[wcnt], int_from_fw, int_arr_drv_port2[wcnt], int_timestamp_arr[wcnt], queue_timestamp_arr[wcnt], send_timestamp_arr[wcnt], rx_timestamp_arr[wcnt], int_latency_drv, int_latency, int_latency_diff, cyclic_queue, pkt_rx, post_rx);
                }

                if(!tts_error) {
                    fprintf(benchmark_file, "%u %u %u %u %u %u %u %u %u %u %u %u\n", min_int_latency_drv, max_int_latency_drv, min_int, max_int,  min_int_latency_diff, max_int_latency_diff, min_queue_cyclic, max_queue_cyclic, min_pkt_rx, max_pkt_rx, min_post_rx, max_post_rx);
                } else {
                    fprintf(benchmark_file, "Test Failed!!!\n");
                }
        index_port2 = 0;
    }
#endif


        /*    Init next round of testing    */
        k++;
#ifndef __LINUX_USER_SPACE
        cyclePeriod +=    ICSS_EMAC_TEST_TTS_CYCLE_PERIOD_PORT2;
#endif
        q1_pkt_cnt = 0;
        q2_pkt_cnt = 0;
        j = 0;
        pkt_period_avg = 0;
        pkt_period_sum = 0;
        timestamp_delta = 0;
        t_delta_quo = 0;
        t_delta_rem = 0;
        max_jitter = 0;
        pkt_missed_cycle_cnt = 0;
        timestamp = 0;
        timestamp_prev = 0;
        missed_cycle_count = 0;
        ret = 0;

        /*    Wait for PRU0 TTS Init    */
        SLEEP(1);
    }
    ICSS_EMAC_testTtsModePort2 = 0;
}



/*
 *    ---function to initialize time triggered send---
 */
int8_t ICSS_EMAC_testTtsInit(ICSS_EmacHandle icssEmacHandle, uint32_t cyclePeriod)
{
    uint8_t j;
    int8_t ret;
    uint8_t portNumber;
    uint32_t iepRegsBase;
    uint64_t iepCounterVal;
    ICSSEMAC_IoctlCmd ioctlParams;
    ICSS_EmacTTSConfig ttsConfig;

    /*    Update Destination MAC address in sample frames    */
    if(icssEmacHandle == ICSS_EMAC_testHandle)
    {
        portNumber = ICSS_EMAC_PORT_1;

        /*    Re-init received pkt count for each TTS test    */
        ICSS_EMAC_testRecv_Q1PktCntPort1 = 0;
        ICSS_EMAC_testRecv_Q2PktCntPort1 = 0;

        for(j=0; j<6; j++)
        {
            ICSS_EMAC_testArpPktPort1[j] = ICSS_EMAC_testLclMac[j];
            ICSS_EMAC_testUdpPktPort1[j] = ICSS_EMAC_testLclMac[j];
        }
    }
    else if(icssEmacHandle == ICSS_EMAC_testHandle1)
    {
        portNumber = ICSS_EMAC_PORT_2;

        /*    Re-init received pkt count for each TTS test    */
        ICSS_EMAC_testRecv_Q1PktCntPort2 = 0;
        ICSS_EMAC_testRecv_Q2PktCntPort2 = 0;

        for(j=0; j<6; j++)
        {
            ICSS_EMAC_testArpPktPort2[j] = ICSS_EMAC_testLclMac1[j];
            ICSS_EMAC_testUdpPktPort2[j] = ICSS_EMAC_testLclMac1[j];
        }
    }
    else if(icssEmacHandle == ICSS_EMAC_testHandle2)
    {
        portNumber = ICSS_EMAC_PORT_1;

        /*    Re-init received pkt count for each TTS test    */
        ICSS_EMAC_testRecv_Q1PktCntPort1 = 0;
        ICSS_EMAC_testRecv_Q2PktCntPort1 = 0;

        for(j=0; j<6; j++)
        {
            ICSS_EMAC_testArpPktPort1[j] = ICSS_EMAC_testLclMac2[j];
            ICSS_EMAC_testUdpPktPort1[j] = ICSS_EMAC_testLclMac2[j];
        }
    }
    else if(icssEmacHandle == ICSS_EMAC_testHandle3)
    {
        portNumber = ICSS_EMAC_PORT_2;

        /*    Re-init received pkt count for each TTS test    */
        ICSS_EMAC_testRecv_Q1PktCntPort2 = 0;
        ICSS_EMAC_testRecv_Q2PktCntPort2 = 0;

        for(j=0; j<6; j++)
        {
            ICSS_EMAC_testArpPktPort2[j] = ICSS_EMAC_testLclMac3[j];
            ICSS_EMAC_testUdpPktPort2[j] = ICSS_EMAC_testLclMac3[j];
        }
    }
    else
    {
        return -1;
    }

    /*    Init TTS Parameters    */
    ioctlParams.command = 0;
    iepRegsBase = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs;

    memset(&ttsConfig, 0, sizeof(ICSS_EmacTTSConfig));
    ioctlParams.ioctlVal = (void *)(&ttsConfig);

    ttsConfig.icssEmacHandle = icssEmacHandle;
    ttsConfig.cycTxSOFStatus = ICSS_EMAC_TTS_CYC_TXSOF_ENABLE;
    ttsConfig.portNumber = portNumber;
#ifdef __LINUX_USER_SPACE
    extern uint32_t config_time;
    ttsConfig.configTime = config_time;
#else
    ttsConfig.configTime = ICSS_EMAC_TEST_TTS_CONFIG_TIME;
#endif
    ttsConfig.cyclePeriod = cyclePeriod;
    ttsConfig.statusTTS = ICSS_EMAC_TTS_ENABLE;

    /*    Reading IEP Counter Value   */
    iepCounterVal = (*((uint64_t*)(iepRegsBase + ICSS_EMAC_testIepCounterOffset)));

#if defined(icev2AM335x) || defined(iceAMIC110) || defined (idkAM437x)
    /* Clear out uppper 32 bits of IEP Counter Value for SOCs with 32 bit IEP counter */
    iepCounterVal = iepCounterVal & 0x00000000FFFFFFFFU;
#endif
    /*    Calculating cycle start value by adding 100us to counter value.    */
#ifdef __LINUX_USER_SPACE
    /* Linux seems to need more time before starting or may miss first cycle trigger */
    ttsConfig.cycleStartTime = (uint64_t)(iepCounterVal + 500000);
    clear_TTS_int_if_set(icssEmacHandle);
#else
    ttsConfig.cycleStartTime = (uint64_t)(iepCounterVal + 100000);
#endif

    /*    Enabling time triggered send.    */
    ret = ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_TTS_CTRL, portNumber, &ioctlParams);
    assert(ret == 0);

    return 0;
}

/*
 *    ---function to setup Timer for Receive Packet pacing---
 */

int32_t ICSS_EMAC_testTimerSetup(ICSS_EmacHandle icssEmacHandle)
{
    void * timerHandle = NULL;
    TimerP_Params timerParams;

#if defined(icev2AM335x) || defined(iceAMIC110) || defined (idkAM437x)
    *(unsigned int*)CM_DPLL_CLKSEL_TIMER3_CLK = 0x1; /* high frequency input clock */

    // enable the TIMER
    *(unsigned int*)CM_PER_TIMER3_CLKCTRL = 0x2; /* Module is explicitly enabled */
#endif


    memset(&timerParams, 0, sizeof(TimerP_Params));
    ICSS_EMAC_osalTimerParamsInit(&timerParams);

    timerParams.runMode = TimerP_RunMode_CONTINUOUS;
    timerParams.startMode = TimerP_StartMode_USER;
    timerParams.periodType = TimerP_PeriodType_MICROSECS;
    timerParams.period = ICSS_EMAC_TEST_TIMER_PERIOD;

    timerParams.arg = (void*)icssEmacHandle;

    /*Create Interrupt Pacing Timer*/
    timerHandle = ICSS_EMAC_osalTimerCreate(ICSS_EMAC_TEST_TIMER_ID, (TimerP_Fxn)ICSS_EmacInterruptPacingISR, &timerParams);

    if ( timerHandle == NULL)
    {
       return -1;
    }
    else
    {
        ((ICSS_EmacObject*)icssEmacHandle->object)->rxPacingTimerHandle = timerHandle;
        return 0;
    }
}

#if defined(idkAM574x) || defined (idkAM572x) || defined  (idkAM571x)
void ICSS_EMAC_testSocCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    if(portNum == 0)
    {
        pMacAddr[5U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_0
                       >> 16U) & 0xFFU;
        pMacAddr[4U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_0
                       >> 8U) & 0xFFU;
        pMacAddr[3U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_0)
                      & 0xFFU;
        pMacAddr[2U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_1
                       >> 16U) & 0xFFU;
        pMacAddr[1U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_1
                       >> 8U) & 0xFFU;
        pMacAddr[0U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_1)
                      & 0xFF;

    }
    else
    {
        pMacAddr[5U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_2
                       >> 16U) & 0xFFU;
        pMacAddr[4U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_2
                       >> 8U) & 0xFFU;
        pMacAddr[3U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_2)
                      & 0xFFU;
        pMacAddr[2U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_3
                       >> 16U) & 0xFFU;
        pMacAddr[1U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_3
                       >> 8U) & 0xFFU;
        pMacAddr[0U] =  (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->MAC_ID_SW_3)
                      & 0xFF;
    }
}
#endif

#if defined(icev2AM335x) || defined(iceAMIC110)
void ICSS_EMAC_testSocCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    uint32_t slavePortNum = portNum - 1U;

    pMacAddr[5U] =  (HW_RD_REG32(SOC_CONTROL_REGS + ICSS_EMAC_TEST_CONTROL_MAC_ID_LO(slavePortNum))
                   >> 8U) & 0xFFU;
    pMacAddr[4U] =  (HW_RD_REG32(SOC_CONTROL_REGS + ICSS_EMAC_TEST_CONTROL_MAC_ID_LO(slavePortNum)))
                  & 0xFF;
    pMacAddr[3U] =  (HW_RD_REG32(SOC_CONTROL_REGS + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(slavePortNum))
                   >> 24U) & 0xFFU;
    pMacAddr[2U] =  (HW_RD_REG32(SOC_CONTROL_REGS + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(slavePortNum))
                   >> 16U) & 0xFFU;
    pMacAddr[1U] =  (HW_RD_REG32(SOC_CONTROL_REGS + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(slavePortNum))
                   >> 8U) & 0xFFU;
    pMacAddr[0U] =  (HW_RD_REG32(SOC_CONTROL_REGS + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(slavePortNum)))
                  & 0xFFU;
}
#endif


#ifdef idkAM437x
void ICSS_EMAC_testSocCtrlGetPortMacAddr(uint32_t portNum, uint8_t *pMacAddr)
{
    switch(portNum)
    {
        case 1U:
            pMacAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_LO(0),
                CTRL_MAC_ID0_LO_MACADDR_7_0);
            pMacAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_LO(0),
                CTRL_MAC_ID0_LO_MACADDR_15_8);
            pMacAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(0),
                CTRL_MAC_ID0_HI_MACADDR_23_16);
            pMacAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(0),
                CTRL_MAC_ID0_HI_MACADDR_31_24);
            pMacAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(0),
                CTRL_MAC_ID0_HI_MACADDR_39_32);
            pMacAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(0),
                CTRL_MAC_ID0_HI_MACADDR_47_40);
            break;

        case 2U:
            pMacAddr[5U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_LO(1),
                CTRL_MAC_ID0_LO_MACADDR_7_0);
            pMacAddr[4U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + ICSS_EMAC_TEST_CONTROL_MAC_ID_LO(1),
                CTRL_MAC_ID0_LO_MACADDR_15_8);
            pMacAddr[3U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG +  ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(1),
                CTRL_MAC_ID1_HI_MACADDR_23_16);
            pMacAddr[2U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG +  ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(1),
                CTRL_MAC_ID1_HI_MACADDR_31_24);
            pMacAddr[1U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG +  ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(1),
                CTRL_MAC_ID1_HI_MACADDR_39_32);
            pMacAddr[0U] = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG +  ICSS_EMAC_TEST_CONTROL_MAC_ID_HI(1),
                CTRL_MAC_ID1_HI_MACADDR_47_40);
            break;

        default:
            break;
    }
}
#endif

Bool ICSS_EMAC_testIMemInit(PRUICSS_Handle ICSS_EMAC_testPruIcssHandle )
{
    Bool retVal = FALSE;


#if defined(idkAM572x)
    if (ICSS_EMAC_testPgVersion >= 2)
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                              (uint32_t *) &pru_imem0_rev2_start,
                          &pru_imem0_rev2_end - &pru_imem0_rev2_start))
        {
            if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                                  (uint32_t *) &pru_imem1_rev2_start,
                              &pru_imem1_rev2_end - &pru_imem1_rev2_start))
            {
                retVal = TRUE;
            }
        }
    }
    else
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                              (uint32_t *) &pru_imem0_rev1_start,
                          &pru_imem0_rev1_end - &pru_imem0_rev1_start))
        {
            if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                                  (uint32_t *) &pru_imem1_rev1_start,
                              &pru_imem1_rev1_end - &pru_imem1_rev1_start))
            {
                retVal = TRUE;
            }
        }
    }
#endif
#if defined(idkAM571x) || defined(iceK2G) || defined(idkAM574x)
     if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                              (uint32_t *) &pru_imem0_rev2_start,
                          &pru_imem0_rev2_end - &pru_imem0_rev2_start))
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                              (uint32_t *) &pru_imem1_rev2_start,
                              &pru_imem1_rev2_end - &pru_imem1_rev2_start))
        {
            retVal = TRUE;
        }
    }
#endif

#if defined(icev2AM335x) || defined(idkAM437x) || defined(iceAMIC110)
    if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                          (uint32_t *) &pru_imem0_rev1_start,
                          &pru_imem0_rev1_end - &pru_imem0_rev1_start))
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                              (uint32_t *) &pru_imem1_rev1_start,
                              &pru_imem1_rev1_end - &pru_imem1_rev1_start))
        {
            retVal = TRUE;
        }
    }
#endif

    return retVal;

}

Bool ICSS_EMAC_testFwVerValidate(ICSS_EmacHandle icssEmacHandle)
{
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

    if (HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr +pStaticMMap->versionOffset) != ICSS_FIRMWARE_RELEASE_1)
    {
        PRINT("ICSS_EMAC_testFwVerValidate: Firmware validate failure\n");
        return FALSE;
    }
    else
    {
        if (HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr +pStaticMMap->version2Offset) != ICSS_FIRMWARE_RELEASE_2)
        {
            PRINT("ICSS_EMAC_testFwVerValidate: Firmware validate failure\n");
            return FALSE;
        }
    }
    if (HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr +pStaticMMap->versionOffset) != ICSS_FIRMWARE_RELEASE_1)
    {
        PRINT("ICSS_EMAC_testFwVerValidate: Firmware validate failure\n");
        return FALSE;
    }
    else
    {
        if (HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr +pStaticMMap->version2Offset) != ICSS_FIRMWARE_RELEASE_2)
        {
            PRINT("ICSS_EMAC_testFwVerValidate: Firmware validate failure\n");
            return FALSE;
        }
    }
    PRINT("Validate Firmware: Release1: 0x%x, Release2: 0x%x\n", ICSS_FIRMWARE_RELEASE_1, ICSS_FIRMWARE_RELEASE_2);
    return TRUE;
}

Bool ICSS_EMAC_testDMemInit(PRUICSS_Handle ICSS_EMAC_testPruIcssHandle )
{

    Bool retVal = FALSE;

#ifndef am65xx_evm
    uint32_t size = 16U;
#endif

#if defined(idkAM572x)
    if (ICSS_EMAC_testPgVersion >= 2)
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(0) ,0,
                              (uint32_t *) &pru_dmem0_rev2_start,
                              size))
        {
            if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(1) ,0,
                                  (uint32_t *) &pru_dmem1_rev2_start,
                              size))
            {
                retVal = TRUE;
            }
        }
    }
    else
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(0) ,0,
                              (uint32_t *) &pru_dmem0_rev1_start,
                              size))
        {
            if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(1) ,0,
                                  (uint32_t *) &pru_dmem1_rev1_start,
                              size))
            {
                retVal = TRUE;
            }
        }
    }
#endif

#if defined(idkAM571x) || defined(iceK2G) || defined(idkAM574x)
     if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(0) ,0,
                              (uint32_t *) &pru_dmem0_rev2_start,
                              size))
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(1) ,0,
                              (uint32_t *) &pru_dmem1_rev2_start,
                              size))
        {
            retVal = TRUE;
        }
    }
#endif

#if defined(icev2AM335x) || defined(idkAM437x) || defined(iceAMIC110)
    if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(0) ,0,
                          (uint32_t *) &pru_dmem0_rev1_start,
                          size))
    {
        if(PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle,PRU_ICSS_DATARAM(1) ,0,
                              (uint32_t *) &pru_dmem1_rev1_start,
                              size))
        {
            retVal = TRUE;
        }
    }
#endif

    return retVal;

}

#ifdef __LINUX_USER_SPACE
void *ICSS_EMAC_testTaskPruss1(void *a0)
#else
Void ICSS_EMAC_testTaskPruss1(UArg a0, UArg a1)
#endif
{
    Bool retVal = FALSE;
    uint32_t count = 0;
    ICSS_EmacTxArgument txArgs;
#ifndef SWITCH_EMAC
    uint8_t ret = 0;
    uint32_t fail_count= 0;
    ICSSEMAC_IoctlCmd ioctlParams;
#endif

#if defined(idkAM572x)
#ifdef __LINUX_USER_SPACE
    ICSS_EMAC_testPgVersion = 2;
#else
    ICSS_EMAC_testPgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;
#endif
#elif defined(idkAM574x)
    ICSS_EMAC_testPgVersion = 2;
#endif
    memset(&txArgs, 0, sizeof(ICSS_EmacTxArgument));

    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);


    retVal = ICSS_EMAC_testDMemInit(ICSS_EMAC_testPruIcssHandle1);
    if (!retVal)
    {
        return;
    }
    retVal = ICSS_EMAC_testFwVerValidate(ICSS_EMAC_testHandle1);
    if (!retVal)
    {
        return;
    }
    retVal = ICSS_EMAC_testIMemInit(ICSS_EMAC_testPruIcssHandle1);

    if( retVal)
    {
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);

        while (!ICSS_EMAC_testPruInstance2Done)
        {
            /*    Do not print during time sensitive TTS testing    */
            if(!(ICSS_EMAC_testTtsModePort1 || ICSS_EMAC_testTtsModePort2))
            {
                SLEEP(100);
            }
        }
    
#ifndef SWITCH_EMAC
#if defined(icev2AM335x) || defined(iceAMIC110)
        while (!ICSS_EMAC_testLinkIsrPru1Eth0)
        {
            PRINT("ICSS_EMAC_testTaskPruss1: LINK IS DOWN,skipping PRU1 ETH0\n");
        }
#else 
        if (!ICSS_EMAC_testLinkIsrPru1Eth0)
        {
            PRINT("ICSS_EMAC_testTaskPruss1: LINK IS DOWN,skipping PRU1 ETH0\n");
        }
        else
#endif
        {
            PRINT("ICSS_EMAC_testTaskPruss1: PRU1 ETH0: LINK IS UP, eth0 state: %d\n", ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkStatus[0]);

            /* Creating Unicast packets in Non-Promiscuous Mode.*/
            for (count=0;count < 6;count++)
            {
                ICSS_EMAC_testPkt[count] = ICSS_EMAC_testLclMac[count];
            }

	    /* Sending Unicast packets in Non-Promiscuous Mode. The eth should be able to recieve packets as destination address == eth own address */
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss1: Testing NonPromiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address == eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort0 = 1;
    
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 1;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPkt[0];
        
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkStatus[0] )
                {
                    if(ICSS_EMAC_testPacketRcvdPort0 )
                    {
                        ICSS_EMAC_testPacketRcvdPort0 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        while(!ICSS_EMAC_testPacketRcvdPort0)
                        {
                            SLEEP(100);
                        }
                    }
                }
            }
            /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss1: Testing NonPromiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address != eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort0 = 1;
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 1;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
            
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkStatus[0] )
                {
                    if(ICSS_EMAC_testPacketRcvdPort0 )
                    {
                        ICSS_EMAC_testPacketRcvdPort0 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        fail_count = 0;
                        while(!ICSS_EMAC_testPacketRcvdPort0)
                        {
                            SLEEP(100);
                            fail_count++;
                            if(fail_count == 5)
                            {
                                PRINT("ICSS_EMAC_testTaskPruss1: Received no packet for PRU1 ETH0\n");
                                ICSS_EMAC_testPacketRcvdPort0 = 1;
                                break;
                            }
                        }                    
                    }
                }
            }
            
            /* Enabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            
            promisEnableFlag = 1;           /* enabling promiscuous mode */
            ioctlParams.command = 0;
            ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
            
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            
            /* Sending Unicast packets in Promiscuous Mode. The eth should be able to recieve packets as destination address != eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss1: Testing Promiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address != eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort0 = 1;
    
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 1;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
            
            ((ICSS_EmacObject*)ICSS_EMAC_testHandle->object)->linkStatus[0] = 1;
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                {
                    if(ICSS_EMAC_testPacketRcvdPort0 )
                    {
                        ICSS_EMAC_testPacketRcvdPort0 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        fail_count = 0;
                        while(!ICSS_EMAC_testPacketRcvdPort0)
                        {
                            SLEEP(100);
                            fail_count++;
                        }                    
                    }
                }
            }

            /* Disabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            
            promisEnableFlag = 0;           /* disabling promiscuous mode */
            ioctlParams.command = 0;
            ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
            
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            /* update link up count */
            ICSS_EMAC_testLinkUpCount++;
            /* Verification on ETH1 for instance 1 only */
        }
#endif

#ifdef SWITCH_EMAC
        while(!ICSS_EMAC_testLinkIsrPru1Eth1)
        {
            PRINT("ICSS_EMAC_testTaskPruss1: LINK IS DOWN,skipping PRU1 ETH1\n");
        }
#else
        if (!ICSS_EMAC_testLinkIsrPru1Eth1)
        {
            PRINT("ICSS_EMAC_testTaskPruss1: LINK IS DOWN,skipping PRU1 ETH1\n");
        }
        else
#endif
        {
            PRINT("ICSS_EMAC_testTaskPruss1: PRU1 ETH1: LINK IS UP, eth0 state: %d\n", ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkStatus[0]);

            /* Creating Unicast packets in Non-Promiscuous Mode.*/
            for (count=0;count < 6;count++)
            {
                ICSS_EMAC_testPkt1[count] = ICSS_EMAC_testLclMac1[count];
            }

#ifdef SWITCH_EMAC
	    /* Sending Unicast packets in Switch Firmware. */
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss1: Testing Switch Firmware ");
            PRINT("\n sending Unicast packets as destination address == eth own address");
            PRINT("\n============================================================\n\n");
#else
            /* Sending Unicast packets in Non-Promiscuous Mode. The eth should be able to recieve packets as destination address == eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss1: Testing NonPromiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address == eth own address");
            PRINT("\n============================================================\n\n");
#endif
            ICSS_EMAC_testPacketRcvdPort1 = 1;
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle1;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
#ifdef SWITCH_EMAC
            txArgs.portNumber = 0;
#else
            txArgs.portNumber = 2;
#endif
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPkt1[0];
        
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
#ifdef SWITCH_EMAC
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkStatus[1])
#else
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkStatus[0] )
#endif
                {
                    if(ICSS_EMAC_testPacketRcvdPort1 )
                    {
                        ICSS_EMAC_testPacketRcvdPort1 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        while(!ICSS_EMAC_testPacketRcvdPort1)
                        {
                            SLEEP(100);
                        }
                    }
                }
            }
#ifndef SWITCH_EMAC
            /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss1: Testing NonPromiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address != eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort1 = 1;
    
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle1;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 2;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
            
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkStatus[0] )
                {
                    if(ICSS_EMAC_testPacketRcvdPort1 )
                    {
                        ICSS_EMAC_testPacketRcvdPort1 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        fail_count = 0;
                        while(!ICSS_EMAC_testPacketRcvdPort1)
                        {
                            SLEEP(100);
                            fail_count++;
                            if(fail_count == 5)
                            {
                                PRINT("ICSS_EMAC_testTaskPruss1: Received no packet for PRU1 ETH1\n");
                                ICSS_EMAC_testPacketRcvdPort1 = 1;
                                break;
                            }
                        }                    
                    }
                }
            }
            
            /* Enabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            
            promisEnableFlag = 1;           /* enabling promiscuous mode */
            ioctlParams.command = 0;
            ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
            
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            
            /* Sending Unicast packets in Promiscuous Mode. The eth should be able to recieve packets as destination address != eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss1: Testing Promiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address != eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort1 = 1;
    
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle1;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 2;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
            
            ((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->linkStatus[0] = 1;
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                {
                    if(ICSS_EMAC_testPacketRcvdPort1 )
                    {
                        ICSS_EMAC_testPacketRcvdPort1 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        fail_count = 0;
                        while(!ICSS_EMAC_testPacketRcvdPort1)
                        {
                            SLEEP(100);
                            fail_count++;
                        }                    
                    }
                }
            }

            /* Disabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
            
            promisEnableFlag = 0;           /* disabling promiscuous mode */
            ioctlParams.command = 0;
            ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
            
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle1, ICSS_EMAC_PORT_2-1);
#endif
            ICSS_EMAC_testLinkUpCount++;
        }
#ifndef SWITCH_EMAC
        if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM572x)
        {
            PRINT("ICSS_EMAC_testTaskPruss1: Skipping TTS Tests for PRUICSS Instance 1 for AM572x\n");
        }
        else
        {
#ifndef __TI_ARM_V7M4__
#ifndef iceK2G
            while(!ICSS_EMAC_testLinkIsrPru1Eth0 && !ICSS_EMAC_testLinkIsrPru1Eth1)
            {
                PRINT("\nICSS_EMAC_testTaskPruss1: LINK IS DOWN, pluggin loopback cable for PRU1 ETH0 and PRU1 ETH1.\n");
            }
    
            PRINT("\n============================================================");
            PRINT("\nInitiating TTS tests on ICSS_EMAC_TEST_PRU1ETH0 and ICSS_EMAC_TEST_PRU1ETH1");
    
            /*    Create TTS related semaphores    */
            ret = ICSS_EMAC_testTtsSemCreate();
            assert(ret == 0);
    
            ICSS_EMAC_testTtsModePort1 = 1;
            ICSS_EMAC_testTtsModePort2 = 1;
    
            /*    Wait for TTS test to complete    */
            while(ICSS_EMAC_testTtsModePort1 || ICSS_EMAC_testTtsModePort2)
            {
                SLEEP(10);
            }
            ICSS_EMAC_testTtsSemDestroy();
    
            PRINT("\n============================================================");
            PRINT("\nTTS tests finished on ICSS_EMAC_TEST_PRU1ETH0 and ICSS_EMAC_TEST_PRU1ETH1");
            PRINT("\n============================================================");
#endif
#endif
        }
#endif

/*storm prevention unit tests start*/        
#ifndef __LINUX_USER_SPACE
#ifdef SWITCH_EMAC
        ICSS_EMAC_testStormPrevention();
#endif
#endif
/*storm prevention unit tests end*/  

#ifdef SWITCH_EMAC
        if (ICSS_EMAC_testTotalPktRcvd == (2*ICSS_EMAC_TEST_PKT_TX_COUNT * ICSS_EMAC_testLinkUpCount))
        {
            PRINT("\nAll tests have passed\n");
        }
#else
        if (ICSS_EMAC_testTotalPktRcvd == (ICSS_EMAC_TEST_PKT_TX_COUNT * ICSS_EMAC_testLinkUpCount))
        {
            PRINT("\nAll tests have passed\n");
        }
        else
            PRINT("ICSS_EMAC_testTaskPruss1: total Pkts received: %d\n", ICSS_EMAC_testTotalPktRcvd);
#endif
		
#ifndef SWITCH_EMAC    
#ifndef am65xx_evm
        ICSS_EMAC_testInterruptDisable(ICSS_EMAC_testHandle);
        ICSS_EMAC_testInterruptDisable(ICSS_EMAC_testHandle1);
#endif

        ICSS_EmacDeInit(ICSS_EMAC_testHandle, ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);
        ICSS_EmacDeInit(ICSS_EMAC_testHandle1, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
#else
	ICSS_EMAC_testInterruptDisable(ICSS_EMAC_testHandle1);
        ICSS_EmacDeInit(ICSS_EMAC_testHandle1, ICSS_EMAC_MODE_SWITCH);
#endif
    }
    else
    {
        PRINT("ICSS_EMAC_testTaskPruss2: firmware load failure\n");
    }

#ifdef __LINUX_USER_SPACE
#ifdef iceK2G
    exit(EXIT_SUCCESS);
#endif
#endif
}

#ifndef SWITCH_EMAC
static Bool ICSS_EMAC_firmware_feature_ctrl(ICSS_EmacHandle *eHandle, PRUICSS_Handle *hdl, uint32_t ioctlCmd, uint8_t portNum, ICSSEMAC_IoctlCmd *ioctlParams);
static Bool ICSS_EMAC_firmware_feature_ctrl(ICSS_EmacHandle *eHandle, PRUICSS_Handle *hdl, uint32_t ioctlCmd, uint8_t portNum, ICSSEMAC_IoctlCmd *ioctlParams)
{
    Bool   retVal;
    PRUICSS_Handle handle = *hdl;
    ICSS_EmacHandle icssEmacHandle = *eHandle;
#ifdef SWITCH_EMAC
    retVal = FALSE;
#else
    int8_t ret_Val = 0;

    PRUICSS_pruDisable(handle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(handle, ICSS_EMAC_PORT_2-1);

    PRUICSS_pruReset(handle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruReset(handle, ICSS_EMAC_PORT_2-1);

    ret_Val = ICSS_EmacIoctl(icssEmacHandle, ioctlCmd, portNum, ioctlParams);
    if (ret_Val != 0)
    {
        retVal = FALSE;
    }
    else
    {
        retVal = TRUE;
    }

    PRUICSS_pruEnable(handle, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruEnable(handle, ICSS_EMAC_PORT_2-1);
#endif
    return (retVal);
}

/* Multicast filtering Test details :
 *-------------+------------------------------------------------------+--------------
 * MCF         |  Destination address                                 |   Response
 *-------------+------------------------------------------------------+--------------
 * DISABLED	   |   XX	                                              |   RECEIVE
 *-------------+------------------------------------------------------+--------------
 * DISABLED	   |   with above config : 01:02:03:04:05:07              |   RECEIVE
 *             |   with above config : 01:02:03:04:05:06              |   RECEIVE
 *-------------+----------------------------------------------------- +--------------
 * ENABLED     |  MCT adds MC MAC ID (Lets say 01:02:03:04:05:06)     |   RECEIVE
 *             |  overlaps for 01:02:03:05:04:06 as well              |   RECEIVE
 *-------------+------------------------------------------------------+--------------
 * ENABLED	   |  DST MAC ID (Lets say 01:02:03:04:05:07)	          |   NOT RECEIVE
 *-------------+------------------------------------------------------+--------------
 * ENABLED	   |  Remove 01:02:03:04:05:06 & ping                     |   NOT RECEIVE
               |  Ping with 01:02:03:04:05:07                         |   NOT RECEIVE
 *-------------+------------------------------------------------------+---------------
 */
Bool ICSS_EMAC_testMulticastFiltering_EmacPort2(ICSS_EmacHandle icss_emacHandle)
{
    Bool retVal = FALSE;
    uint32_t count = 0;
    int32_t    portNum = ICSS_EMAC_PORT_2;
    uint32_t   fail_count, gFail_count;
    ICSSEMAC_IoctlCmd ioctlParams;
    uint8_t    mc_macId[6] = { 01, 02, 03, 04, 05, 06};
    uint8_t    mask[6] = {255, 255, 255, 255, 255, 255};
    ICSS_EmacTxArgument txArgs;
    memset(&txArgs, 0, sizeof(ICSS_EmacTxArgument));

    /* Enable the promiscuous mode for the ports to get multicast packets*/
    {
        promisEnableFlag = 1;    /* enable promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            return(FALSE);
        }
    }

    /* Now enable MCF with MC MAC ID (Lets say 01:02:03:04:05:06) */
    ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ENABLE;
    retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
    if (retVal == FALSE)
    {
        return(FALSE);
    }

    ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ADD_MACID;
    ioctlParams.ioctlVal = (void *) &mc_macId[0] ;
    retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
    if (retVal == FALSE)
    {
        return(FALSE);
    }

    ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_OVERRIDE_HASHMASK;
    ioctlParams.ioctlVal = (void *) &mask[0] ;
    retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
    if (retVal == FALSE)
    {
        return(FALSE);
    }

    /*
     * MCT with 01:02:03:04:05:06 shoud be received
     */

    ICSS_EMAC_testPacketRcvdPort3 = 1;
    txArgs.icssEmacHandle = icss_emacHandle;
    txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt1Multicast);
    txArgs.portNumber = portNum;
    txArgs.queuePriority = 3;
    txArgs.srcAddress = &ICSS_EMAC_testPkt1Multicast[0];
    
    for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
    {
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
        {
            if(ICSS_EMAC_testPacketRcvdPort3 )
            {
                ICSS_EMAC_testPacketRcvdPort3 = 0;
                ICSS_EmacTxPacket(&txArgs, NULL);
                while(!ICSS_EMAC_testPacketRcvdPort3)
                {
                    SLEEP(100);
                }
            }
        }
    }

    /* Keep the multicast filter enabled 
     * send with above config : 01:02:03:04:05:07 (should not be received)
     */

    ICSS_EMAC_testPacketRcvdPort3 = 1;
    txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
    txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt2Multicast);
    txArgs.portNumber = portNum;
    txArgs.queuePriority = 3;
    txArgs.srcAddress = &ICSS_EMAC_testPkt2Multicast[0];

    gFail_count = 0;
    for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
    {
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
        {
            if(ICSS_EMAC_testPacketRcvdPort3 )
            {
                ICSS_EMAC_testPacketRcvdPort3 = 0;
                fail_count = 0;
                ICSS_EmacTxPacket(&txArgs, NULL);
                while(!ICSS_EMAC_testPacketRcvdPort3)
                {
                    SLEEP(100);
                    fail_count++;
                    if (fail_count > 5)
                    {
                        gFail_count ++;
                        ICSS_EMAC_testPacketRcvdPort3 = 1;
                        break;
                    }
                }
            }
        }
    }

    if (gFail_count == ICSS_EMAC_TEST_PKT_TX_COUNT)
    {
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_REMOVE_MACID;
        ioctlParams.ioctlVal = (void *) &mc_macId[0] ;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        /* Now disable MCF with MC MAC ID (Lets say 01:02:03:04:05:06) */
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_DISABLE;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        retVal = TRUE;
    }
    else
    {
        /* Disable MCF feature */
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_REMOVE_MACID;
        ioctlParams.ioctlVal = (void *) &mc_macId[0] ;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        /* Now disable MCF with MC MAC ID (Lets say 01:02:03:04:05:06) */
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_DISABLE;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        retVal = FALSE;
    }

testComplete:

    if (retVal == TRUE)
    {
        /* Now run the MC mac-ID checks and both should make the host packet get the packets */
        /* Keep the multicast filter (disabled) 
         * send with above config : 01:02:03:04:05:06
         */
        ICSS_EMAC_testPacketRcvdPort3 = 1;
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
        txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt1Multicast);
        txArgs.portNumber = portNum;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPkt1Multicast[0];
        
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort3 )
                {
                    ICSS_EMAC_testPacketRcvdPort3 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    while(!ICSS_EMAC_testPacketRcvdPort3)
                    {
                        SLEEP(100);
                    }
                }
            }
        }
    
        /* Keep the multicast filter default (disabled) 
         * send with above config : 01:02:03:04:05:07
         */
    
        ICSS_EMAC_testPacketRcvdPort3 = 1;
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
        txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt2Multicast);
        txArgs.portNumber = portNum;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPkt2Multicast[0];
        
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort3 )
                {
                    ICSS_EMAC_testPacketRcvdPort3 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    while(!ICSS_EMAC_testPacketRcvdPort3)
                    {
                        SLEEP(100);
                    }
                }
            }
        }
    }

    /* Disable the promiscuous mode for all ports to after multicast tests*/
    {
        promisEnableFlag = 0;            /* enable promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle3, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            return(FALSE);
        }
    }

    return (retVal);
}



/* Multicast filtering Test details :
 *-------------+------------------------------------------------------+--------------
 * MCF         |  Destination address                                 |   Response
 *-------------+------------------------------------------------------+--------------
 * DISABLED    |   XX                                                 |   RECEIVE
 *-------------+------------------------------------------------------+--------------
 * DISABLED    |   with above config : 01:02:03:04:05:07              |   RECEIVE
 *             |   with above config : 01:02:03:04:05:06              |   RECEIVE
 *-------------+----------------------------------------------------- +--------------
 * ENABLED     |  MCT adds MC MAC ID (Lets say 01:02:03:04:05:06)     |   RECEIVE
 *             |  overlaps for 01:02:03:05:04:06 as well              |   RECEIVE
 *-------------+------------------------------------------------------+--------------
 * ENABLED     |  DST MAC ID (Lets say 01:02:03:04:05:07)             |   NOT RECEIVE
 *-------------+------------------------------------------------------+--------------
 * ENABLED     |  Remove 01:02:03:04:05:06 & ping                     |   NOT RECEIVE
               |  Ping with 01:02:03:04:05:07                         |   NOT RECEIVE
 *-------------+------------------------------------------------------+---------------
 */
Bool ICSS_EMAC_testMulticastFiltering_EmacPort1(ICSS_EmacHandle icss_emacHandle)
{
    Bool retVal = FALSE;
    uint32_t count = 0;
    int32_t    portNum = ICSS_EMAC_PORT_1;
    uint32_t   fail_count, gFail_count;
    ICSSEMAC_IoctlCmd ioctlParams;
    uint8_t    mc_macId[6] = { 01, 02, 03, 04, 05, 06};
    uint8_t    mask[6] = {255, 255, 255, 255, 255, 255};

    ICSS_EmacTxArgument txArgs;
    memset(&txArgs, 0, sizeof(ICSS_EmacTxArgument));

    /* Enable the promiscuous mode for the ports to get multicast packets*/
    {
        promisEnableFlag = 1;            /* enable promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            return(FALSE);
        }
    }

    /* Now enable MCF with MC MAC ID (Lets say 01:02:03:04:05:06) */
    ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ENABLE;
    retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
    if (retVal == FALSE)
    {
        return(FALSE);
    }

    ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ADD_MACID;
    ioctlParams.ioctlVal = (void *) &mc_macId[0] ;
    retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
    if (retVal == FALSE)
    {
        return(FALSE);
    }

    ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_OVERRIDE_HASHMASK;
    ioctlParams.ioctlVal = (void *) &mask[0] ;
    retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
    if (retVal == FALSE)
    {
        return(FALSE);
    }

    /*
     * MCT with 01:02:03:04:05:06 shoud be received
     */

    ICSS_EMAC_testPacketRcvdPort2 = 1;
    txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
    txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt1Multicast);
    txArgs.portNumber = portNum;
    txArgs.queuePriority = 3;
    txArgs.srcAddress = &ICSS_EMAC_testPkt1Multicast[0];
    
    for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
    {
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
        {
            if(ICSS_EMAC_testPacketRcvdPort2 )
            {
                ICSS_EMAC_testPacketRcvdPort2 = 0;
                ICSS_EmacTxPacket(&txArgs, NULL);
                while(!ICSS_EMAC_testPacketRcvdPort2)
                {
                    SLEEP(100);
                }
            }
        }
    }

    /* Keep the multicast filter enabled 
     * send with above config : 01:02:03:04:05:07 (should not be received)
     */

    ICSS_EMAC_testPacketRcvdPort2 = 1;
    txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
    txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt2Multicast);
    txArgs.portNumber = portNum;
    txArgs.queuePriority = 3;
    txArgs.srcAddress = &ICSS_EMAC_testPkt2Multicast[0];

    gFail_count = 0;
    for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
    {
        if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
        {
            if(ICSS_EMAC_testPacketRcvdPort2 )
            {
                ICSS_EMAC_testPacketRcvdPort2 = 0;
                fail_count = 0;
                ICSS_EmacTxPacket(&txArgs, NULL);
                while(!ICSS_EMAC_testPacketRcvdPort2)
                {
                    SLEEP(100);
                    fail_count++;
                    if (fail_count > 5)
                    {
                        gFail_count ++;
                        ICSS_EMAC_testPacketRcvdPort2 = 1;
                        break;
                    }
                }
            }
        }
    }

    if (gFail_count == ICSS_EMAC_TEST_PKT_TX_COUNT)
    {
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_REMOVE_MACID;
        ioctlParams.ioctlVal = (void *) &mc_macId[0] ;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        /* Now disable MCF with MC MAC ID (Lets say 01:02:03:04:05:06) */
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_DISABLE;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        retVal = TRUE;
    }
    else
    {
        /* Disable MCF feature */
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_REMOVE_MACID;
        ioctlParams.ioctlVal = (void *) &mc_macId[0] ;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        /* Now disable MCF with MC MAC ID (Lets say 01:02:03:04:05:06) */
        ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_DISABLE;
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            goto testComplete;
        }

        retVal = FALSE;
    }

testComplete:

    if (retVal == TRUE)
    {
        /* Now run the MC mac-ID checks and both should make the host packet get the packets */
        /* Keep the multicast filter (disabled) 
         * send with above config : 01:02:03:04:05:06
         */
        ICSS_EMAC_testPacketRcvdPort2 = 1;
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt1Multicast);
        txArgs.portNumber = portNum;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPkt1Multicast[0];
        
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                    }
                }
            }
        }

        /* Keep the multicast filter default (disabled) 
         * send with above config : 01:02:03:04:05:07
         */

        ICSS_EMAC_testPacketRcvdPort2 = 1;
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = sizeof(ICSS_EMAC_testPkt2Multicast);
        txArgs.portNumber = portNum;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPkt2Multicast[0];
        
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                    }
                }
            }
        }
    }

    /* Disable the promiscuous mode for all ports to after multicast tests*/
    {
        promisEnableFlag = 0;            /* enable promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EMAC_firmware_feature_ctrl(&ICSS_EMAC_testHandle2, &ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, portNum, &ioctlParams);
        if (retVal == FALSE)
        {
            return(FALSE);
        }
    }

    return (retVal);
}

/*
Vlan filter Testing:
T : tagged frames
P : priority frames (VID=0)
U : untagged frames
Table:

==============================+===========+=================================+================================+=================+
ICSS_EMAC_FW_VLAN_FILTER_CTRL |           |  ICSS_EMAC_FW_VLAN_FILTER_      |  ICSS_EMAC_FW_VLAN_FILTER_     |     Result      |
_ENABLE_BIT                   |  VIDs (T) | PRIOTAG_HOST_RCV_ALLOW_CTRL_BIT |  UNTAG_HOST_RCV_ALLOW_CTRL_BIT |                 |
==============================+===========+=================================+================================+=================+
DISABLE                       | dont care |   dont care                     |     dont care                  | TPU             |
                              |           |                                 |                                | (All Rx by Host)|
==============================+===========+=================================+================================+=================+
ENABLE                        | NOT       |  VLAN_FLTR_PRIOTAG_HOST_RCV_NAL |   VLAN_FLTR_UNTAG_HOST_RCV_NAL | T'P'U'          |
                              | CONFIGURED|                                 |                                | (None Rx)       |
==============================+===========+=================================+================================+=================+
ENABLE                        | NOT       |  VLAN_FLTR_PRIOTAG_HOST_RCV_NAL |   VLAN_FLTR_UNTAG_HOST_RCV_ALL | T'P'U           |
                              | CONFIGURED|                                 |                                | (Only U Rx)     |
==============================+===========+=================================+================================+=================+
ENABLE                        |NOT        |  VLAN_FLTR_PRIOTAG_HOST_RCV_ALL |   VLAN_FLTR_UNTAG_HOST_RCV_NAL | T'U'P           |
                              |CONFIGURED |                                 |                                | (Only P Rx)     |
==============================+===========+=================================+================================+=================+
ENABLE                        | NOT       |  VLAN_FLTR_PRIOTAG_HOST_RCV_ALL |   VLAN_FLTR_UNTAG_HOST_RCV_ALL | T'PU            |
                              | CONFIGURED|                                 |                                | (Only P,U Rx)   |
==============================+===========+=================================+================================+=================+
ENABLE                        | CONFIGURED|  VLAN_FLTR_PRIOTAG_HOST_RCV_NAL |   VLAN_FLTR_UNTAG_HOST_RCV_NAL | P'U'T           |
                              |           |                                 |                                | (Only T Rx)     |
==============================+===========+=================================+================================+=================+
ENABLE                        | CONFIGURED|  VLAN_FLTR_PRIOTAG_HOST_RCV_NAL |   VLAN_FLTR_UNTAG_HOST_RCV_ALL | P'TU            |
                              |           |                                 |                                | (OnlyT, U Rx)   |
==============================+===========+=================================+================================+=================+
ENABLE                        |CONFIGURED |  VLAN_FLTR_PRIOTAG_HOST_RCV_ALL |   VLAN_FLTR_UNTAG_HOST_RCV_NAL | U'TP            |
                              |           |                                 |                                | (Only T, P Rx)  |
==============================+===========+=================================+================================+=================+
ENABLE                        |CONFIGURED |  VLAN_FLTR_PRIOTAG_HOST_RCV_ALL |  VLAN_FLTR_UNTAG_HOST_RCV_ALL  |  TPU            |
..............................|           |                                 |                                | (All Rx by Host)|
==============================+===========+=================================+================================+=================+
(DEFAULT)                     |NOT        |  VLAN_FLTR_PRIOTAG_HOST_RCV_ALL |   VLAN_FLTR_UNTAG_HOST_RCV_ALL |   TPU           |
DISABLE                       |CONFIGURED |                                 |                                | (All Rx by host)|
==============================+===========+=================================+================================+=================+
*/

static testVlanCfg_t testVlanFilterCfg[] =
{

    /* Test case configuration 1 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_DISABLE,                /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_NOT_CONFIGURED,             /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                             /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_PRIO_HOST_RX,         /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_UNTAGGED_HOST_RX,     /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TPU                      /* Expected result */
    },

    /* Test case configuration 2 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_NOT_CONFIGURED,             /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_PRIO_HOST_RX,         /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_UNTAGGED_HOST_RX,     /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_NONE                     /* Expected result */
    },

    /* Test case configuration 3 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_NOT_CONFIGURED,             /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_PRIO_HOST_RX,         /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_UNTAGGED_HOST_RX,         /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_UNTAGGED_WEIGHT          /* Expected result */
    },

    /* Test case configuration 4 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_NOT_CONFIGURED,             /* VID Config cmd*/
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_PRIO_HOST_RX,             /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_UNTAGGED_HOST_RX,     /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PRIORITY_WEIGHT          /* Expected result */
    },

    /* Test case configuration 5 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_NOT_CONFIGURED,             /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_PRIO_HOST_RX,             /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_UNTAGGED_HOST_RX,         /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PU                       /* Expected result */
    },

    /* Test case configuration 6 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_ADD_VLAN_ID,                 /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_PRIO_HOST_RX,         /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_UNTAGGED_HOST_RX,     /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TAGGED_WEIGHT            /* Expected result */
    },

    /* Test case configuration 7 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_ADD_VLAN_ID,                 /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_PRIO_HOST_RX,         /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_UNTAGGED_HOST_RX,         /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TU                       /* Expected result */
    },

    /* Test case configuration 8 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_ADD_VLAN_ID,                 /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_PRIO_HOST_RX,             /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_UNTAGGED_HOST_RX,     /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TP                       /* Expected result */
    },

    /* Test case configuration 9 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_ADD_VLAN_ID,                 /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_PRIO_HOST_RX,             /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_UNTAGGED_HOST_RX,         /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TPU                      /* Expected result */
    },
    /* Test case configuration 10 */
    {
      ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE,                 /* Vlan filter feature */
      ICSS_EMAC_VLAN_FILTER_TEST_VID_REMOVE_VLAN_ID,             /* VID Config cmd */
      ICSS_EMAC_VLAN_FILTER_TEST_VID,                            /* Test VID */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_PRIO_HOST_RX,             /* Priority tag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_UNTAGGED_HOST_RX,         /* Untag host rx control */
      ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PU                       /* Expected result */
     }

};

/* Number of VLAN test configurations */
#define ICSS_EMAC_TEST_MAX_NUM_VLAN_TEST_CFGS               (sizeof (testVlanFilterCfg)/sizeof (testVlanCfg_t))
#define ICSS_EMAC_TEST_MAX_VLAN_CMDS                        ( 4 )

static Bool ICSS_EMAC_vlan_filter_feature_config(ICSS_EmacHandle *icssEmacHandlePtr, PRUICSS_Handle *pruHandlePtr, uint8_t portNum, testVlanCfg_t *vlanCfg);
static Bool ICSS_EMAC_vlan_filter_feature_config(ICSS_EmacHandle *icssEmacHandlePtr, PRUICSS_Handle *pruHandlePtr, uint8_t portNum, testVlanCfg_t *vlanCfg)
{
    uint32_t          i;
    int32_t           vlanFilterCmd[ICSS_EMAC_TEST_MAX_VLAN_CMDS];
    ICSSEMAC_IoctlCmd ioctlParams;
    Bool              retVal = TRUE;


    /* Get the commands */
    vlanFilterCmd[0] = vlanCfg->vlanFilterEnable;
    vlanFilterCmd[1] = vlanCfg->vlanAddRemoveCfg;
    vlanFilterCmd[2] = vlanCfg->unTagPktCfg;
    vlanFilterCmd[3] = vlanCfg->prioPktCfg;
    for (i = 0; i < ICSS_EMAC_TEST_MAX_VLAN_CMDS; i++)
    {
        switch(vlanFilterCmd[i])
        {
            case ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_ENABLE:
                ioctlParams.command = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_ENABLE_CMD;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_FEATURE_DISABLE:
                ioctlParams.command = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_DISABLE_CMD;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_PRIO_HOST_RX:
                ioctlParams.command = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_PRIOTAG_HOST_RCV_ALL_CMD;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_PRIO_HOST_RX:
                ioctlParams.command = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_PRIOTAG_HOST_RCV_NAL_CMD;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_ALLOW_UNTAGGED_HOST_RX:
                ioctlParams.command = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_UNTAG_HOST_RCV_ALL_CMD;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_NOT_ALLOW_UNTAGGED_HOST_RX:
                ioctlParams.command = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_UNTAG_HOST_RCV_NAL_CMD;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_VID_ADD_VLAN_ID:
                ioctlParams.command  = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_ADD_VID_CMD;
                ioctlParams.ioctlVal = (void *) &vlanCfg->vid;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_VID_REMOVE_VLAN_ID:
                ioctlParams.command = ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_REMOVE_VID_CMD;
                ioctlParams.ioctlVal = (void *) &vlanCfg->vid;
                retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruHandlePtr, ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL, portNum, &ioctlParams);
                break;

            case ICSS_EMAC_VLAN_FILTER_TEST_VID_NOT_CONFIGURED:
                /* No action */
            default:
                break;
        }
    }

    return(retVal);

}

static Bool ICSS_EMAC_SendPktChkRx(ICSS_EmacHandle *icssEmacHandlePtr, PRUICSS_Handle *pruHandlePtr, uint32_t portNum, uint8_t *testVlanpkt, uint32_t pktSize);
Bool ICSS_EMAC_SendPktChkRx(ICSS_EmacHandle *icssEmacHandlePtr, PRUICSS_Handle *pruHandlePtr, uint32_t portNum, uint8_t *testVlanpkt, uint32_t pktSize)
{
    ICSS_EmacTxArgument  txArgs;
    uint32_t             count, fail_count, gFail_count = 0;
    uint32_t             *rxPktCnt;
    ICSS_EmacObject      *emacObj;
    Bool                 retVal = TRUE;
    ICSS_EmacHandle      icssEmacHandle = *icssEmacHandlePtr;

    /* Clear the arguments */
    memset(&txArgs, 0, sizeof(ICSS_EmacTxArgument));

    if (portNum == ICSS_EMAC_PORT_1)
    {
        rxPktCnt = &ICSS_EMAC_testPacketRcvdPort2;
    }
    else
    {
        rxPktCnt = &ICSS_EMAC_testPacketRcvdPort3;
    }

    emacObj = (ICSS_EmacObject *) (icssEmacHandle->object);

    *rxPktCnt = 1;
    txArgs.icssEmacHandle = icssEmacHandle;
    txArgs.lengthOfPacket = pktSize;
    txArgs.portNumber = portNum;
    txArgs.queuePriority = 3;
    txArgs.srcAddress = testVlanpkt;

    for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
    {
        if(emacObj->linkStatus[0])
        {
            if(*rxPktCnt )
            {
                *rxPktCnt = 0;
                ICSS_EmacTxPacket(&txArgs, NULL);
                fail_count = 0;
                while(*rxPktCnt == 0U)
                {
                    SLEEP(100U);
                    fail_count ++;
                    if (fail_count > 2)
                    {
                        gFail_count ++;
                        *rxPktCnt = 1;
                        break;
                    }
                }
            }
        }
    }

    if (gFail_count == ICSS_EMAC_TEST_PKT_TX_COUNT)
    {
        retVal = FALSE;
    }
    else
    {
        retVal = TRUE;
    }

    return (retVal);

}


Bool ICSS_EMAC_testVlanFiltering_On_EmacPort(PRUICSS_Handle *pruIcssHandlePtr, uint8_t portNum)
{
    Bool                 retVal = FALSE;
    uint32_t             weight;
    uint32_t             testCfgIndex;
    ICSS_EmacHandle     *icssEmacHandlePtr = NULL;
    ICSSEMAC_IoctlCmd    ioctlParams;

    /* Test VLAN for given ports */
    if (*pruIcssHandlePtr ==  ICSS_EMAC_testPruIcssHandle2)
    {
        if (portNum == ICSS_EMAC_PORT_1)
        {
            icssEmacHandlePtr = &ICSS_EMAC_testHandle2;
        }
        else
        {
            icssEmacHandlePtr = &ICSS_EMAC_testHandle3;
        }
    }

    if (*pruIcssHandlePtr ==  ICSS_EMAC_testPruIcssHandle1)
    {
        if (portNum == ICSS_EMAC_PORT_1)
        {
            icssEmacHandlePtr = &ICSS_EMAC_testHandle;
        }
        else
        {
            icssEmacHandlePtr = &ICSS_EMAC_testHandle1;
        }
    }

    if(icssEmacHandlePtr != NULL)
    {
        /* Enable the promiscuous mode for the ports to get VLAN packets*/
        promisEnableFlag = 1;    /* enable promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruIcssHandlePtr, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, portNum, &ioctlParams);

        /* Test the configurations */
        for (testCfgIndex = 0, weight = 0; ((testCfgIndex < ICSS_EMAC_TEST_MAX_NUM_VLAN_TEST_CFGS) && (retVal == TRUE)); testCfgIndex++)
        {
            /* Configure the VLAN filter test parameters */
            retVal = ICSS_EMAC_vlan_filter_feature_config(icssEmacHandlePtr, pruIcssHandlePtr, portNum, &testVlanFilterCfg[testCfgIndex]);
            if (retVal == FALSE)
            {
                break;
            }

            /* Get the weight of the received packet after sending and receive the packet */
            weight = ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_NONE;

            retVal = ICSS_EMAC_SendPktChkRx(icssEmacHandlePtr, pruIcssHandlePtr, portNum, &ICSS_EMAC_testPkt1VlanUntagged[0], sizeof(ICSS_EMAC_testPkt1VlanUntagged));
            if (retVal == TRUE)
            {
                weight += ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_UNTAGGED_WEIGHT;
            }

            retVal = ICSS_EMAC_SendPktChkRx(icssEmacHandlePtr, pruIcssHandlePtr, portNum, &ICSS_EMAC_testPkt1VlanTagged[0], sizeof(ICSS_EMAC_testPkt1VlanTagged));
            if (retVal == TRUE)
            {
                weight += ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_TAGGED_WEIGHT;
            }

            retVal = ICSS_EMAC_SendPktChkRx(icssEmacHandlePtr, pruIcssHandlePtr, portNum, &ICSS_EMAC_testPkt1VlanPriority[0], sizeof(ICSS_EMAC_testPkt1VlanPriority));
            if (retVal == TRUE)
            {
                weight += ICSS_EMAC_VLAN_FILTER_TEST_RX_PKT_PRIORITY_WEIGHT;
            }

            if (weight != testVlanFilterCfg[testCfgIndex].expectedRxPktWeight)
            {
                retVal = FALSE;
                PRINT ("    VLAN filtering test Failed for Configuration %d (weight mismatch - expected %d, obtained %d) \n", testCfgIndex, testVlanFilterCfg[testCfgIndex].expectedRxPktWeight, weight );
                break;
            }
            else
            {
               /* Test passed with expected results, continue for next test configuration */
               retVal = TRUE;
               PRINT ("    VLAN filtering test Passed for Configuration %d \n", testCfgIndex);
            }
        }

        /* Disable the promiscuous mode for the ports to get back to original state */
        if (retVal == TRUE)
        {
            promisEnableFlag = 0;    /* enable promiscuous mode */
            ioctlParams.command = 0;
            ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
            retVal = ICSS_EMAC_firmware_feature_ctrl(icssEmacHandlePtr, pruIcssHandlePtr, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, portNum, &ioctlParams);
        }
    }

    /* Return overall test result */
    return (retVal);
}

#endif   /* DUAL_EMAC TESTS ONLY */

Bool ICSS_EMAC_testQueueOverflow(ICSS_EmacHandle icss_emacHandle)
{
	uint32_t count;
	int32_t overflowCount;
	ICSS_EmacTxArgument txArgs;
	enableQOverFlowCheck = 1;
	ICSS_EMAC_testPacketRcvdPort2 = 1;
	memset(&txArgs, 0, sizeof(ICSS_EmacTxArgument));
        txArgs.icssEmacHandle = icss_emacHandle;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
#ifdef SWITCH_EMAC
        txArgs.portNumber = 0;
#else
        txArgs.portNumber = 1;
#endif
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPkt2[0];
        
        for (count = 0; count < ICSS_EMAC_TEST_QUEUE_OVERFLOW_COUNT;count++)
        {
            if(((ICSS_EmacObject*)icss_emacHandle->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
					ICSS_EmacTxPacket(&txArgs, NULL);
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
						ICSS_EMAC_testPacketRcvdPort2 = 1;
						break;
                    }
                }
            }
        }
		overflowCount = ICSS_EmacGetQueueOverflowCount(ICSS_EMAC_testHandle2,ICSS_EMAC_PORT_0,ICSS_EMAC_QUEUE2);
		if (ICSS_EMAC_TEST_QUEUE_OVERFLOW_PASS_CRITERIA_COUNT == overflowCount)
		{
			PRINT("ICSS_EMAC_testQueueOverflow(pass): expected: %d, observed: %d\n",
				ICSS_EMAC_TEST_QUEUE_OVERFLOW_PASS_CRITERIA_COUNT, overflowCount);
			return true;
		}
		else
		{
			PRINT("ICSS_EMAC_testQueueOverflow(fail): expected: %d, observed: %d\n",
				ICSS_EMAC_TEST_QUEUE_OVERFLOW_PASS_CRITERIA_COUNT, overflowCount);
			return false;
		}
	
}

void ICSS_EMAC_fwIntrPacingConfig(ICSSEMAC_Handle icssEmacHandle, uint8_t port, uint8_t intrPacStatus, uint32_t timerExpiration)
{
    uint8_t *intrPacing;

    uint32_t *timeOutValuePru0 = (uint32_t *)(((((ICSS_EmacHwAttrs *)
                                 icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                                 INTR_PAC_TMR_EXP_OFFSET_PRU0);
    uint32_t *timeOutValuePru1 = (uint32_t *)(((((ICSS_EmacHwAttrs *)
                                 icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                                 INTR_PAC_TMR_EXP_OFFSET_PRU1);
    if (port == 0) {
        intrPacing = (uint8_t *)(((((ICSS_EmacHwAttrs *)
                                         icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                                      INTR_PAC_STATUS_OFFSET_PRU0);
    } else {
        intrPacing = (uint8_t *)(((((ICSS_EmacHwAttrs *)
                                         icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                                      INTR_PAC_STATUS_OFFSET_PRU1);
    }

    *intrPacing = intrPacStatus;

    if(intrPacStatus == INTR_PAC_ENA_ADP_LGC_DIS)
    {
        *timeOutValuePru0 = timerExpiration;
        *timeOutValuePru1 = timerExpiration;
    }
    
}

#ifndef __LINUX_USER_SPACE
#ifdef SWITCH_EMAC
void ICSS_EMAC_testStormPrevention(void)
{
    uint8_t testPassed = 1;
    uint32_t value = 0;
    uint8_t index = 0;
    ICSSEMAC_IoctlCmd ioctlParams;
    int8_t ioctlRetVal;
    uint32_t* stormPreventionOffsetPtrBC[2]= {NULL, NULL};
    uint32_t* stormPreventionOffsetPtrMC[2]= {NULL, NULL};
    uint32_t* stormPreventionOffsetPtrUC[2]= {NULL, NULL};
    stormPrevention_t* stormPrevPtr;
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->fwStaticMMap);
    stormPreventionOffsetPtrBC[0] = (uint32_t*)(((((ICSS_EmacHwAttrs*)ICSS_EMAC_testHandle1->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->stormPreventionOffsetBC));
    stormPreventionOffsetPtrBC[1] = (uint32_t*)(((((ICSS_EmacHwAttrs*)ICSS_EMAC_testHandle1->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->stormPreventionOffsetBC));
    stormPreventionOffsetPtrMC[0] = (uint32_t*)(((((ICSS_EmacHwAttrs*)ICSS_EMAC_testHandle1->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->stormPreventionOffsetMC));
    stormPreventionOffsetPtrMC[1] = (uint32_t*)(((((ICSS_EmacHwAttrs*)ICSS_EMAC_testHandle1->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->stormPreventionOffsetMC));
    stormPreventionOffsetPtrUC[0] = (uint32_t*)(((((ICSS_EmacHwAttrs*)ICSS_EMAC_testHandle1->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->stormPreventionOffsetUC));
    stormPreventionOffsetPtrUC[1] = (uint32_t*)(((((ICSS_EmacHwAttrs*)ICSS_EMAC_testHandle1->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->stormPreventionOffsetUC));
    uint8_t port[] = {ICSS_EMAC_PORT_0, ICSS_EMAC_PORT_1, ICSS_EMAC_PORT_2};

    uint16_t credit = 2000;
    uint32_t spResetVal = 512001;
    ioctlParams.ioctlVal = (void*)(&credit);
    for(index = 1 ; index < 3 ; index++)
    {
        stormPrevPtr = (stormPrevention_t*)(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->stormPrevPtr);
        stormPrevPtr += (port[index] - 1u);

        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_ENABLE_BC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_ENABLE_BC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledBC != 1)
        {
            PRINT("stormPrevPtr->suppressionEnabledBC != 1 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrBC[port[index] -1]), 4);
        if(value != 1)
        {
            PRINT("*(stormPreventionOffsetPtrBC[port[index] -1]) != 1 test for SWITCH failed\n");
            testPassed = 0;
        }

        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_DISABLE_BC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_DISABLE_BC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledBC != 0)
        {
            PRINT("stormPrevPtr->suppressionEnabledBC != 0 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrBC[port[index] -1]), 4);
        if(value != 0)
        {
            PRINT("*(stormPreventionOffsetPtrBC[port[index] - 1]) != 0 test for SWITCH failed\n");
            testPassed = 0;
        }
        stormPrevPtr->creditsBC = credit;
        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_ENABLE_BC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_BC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_RESET_BC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledBC != 1)
        {
            PRINT("stormPrevPtr->suppressionEnabledBC != 1 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrBC[port[index] -1]), 4);
        if(value != spResetVal)
        {
            PRINT("*(stormPreventionOffsetPtrBC[port[index] - 1]) != 1 test for SWITCH failed, actal value = %d\n", *(stormPreventionOffsetPtrBC[port[index] - 1]));
            testPassed = 0;
        }
    }

    for(index = 1 ; index < 3 ; index++)
    {
        stormPrevention_t* stormPrevPtr = (stormPrevention_t*)(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->stormPrevPtr);
        stormPrevPtr += (port[index] - 1u);

        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_ENABLE_MC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_ENABLE_MC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledMC != 1)
        {
            PRINT("stormPrevPtr->suppressionEnabledMC != 1 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrMC[port[index] -1]), 4);
        if(value != 1)
        {
            PRINT("*(stormPreventionOffsetPtrMC[port[index] -1]) test for SWITCH failed\n");
            testPassed = 0;
        }

        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_DISABLE_MC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_DISABLE_MC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledMC != 0)
        {
            PRINT("stormPrevPtr->suppressionEnabledMC != 0 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrMC[port[index] -1]), 4);
        if(value != 0)
        {
            PRINT("*(stormPreventionOffsetPtrMC[port[index] - 1]) != 0 test for SWITCH failed\n");
            testPassed = 0;
        }
        stormPrevPtr->creditsMC = credit;
        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_ENABLE_MC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_MC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_RESET_MC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledMC != 1)
        {
            PRINT("stormPrevPtr->suppressionEnabledMC != 1 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrMC[port[index] -1]), 4);
        if(value != spResetVal)
        {
            PRINT("*(stormPreventionOffsetPtrMC[port[index] - 1]) != 1 test for SWITCH failed\n");
            testPassed = 0;
        }
    }
    for(index = 1 ; index < 3 ; index++)
    {
        stormPrevention_t* stormPrevPtr = (stormPrevention_t*)(((ICSS_EmacObject*)ICSS_EMAC_testHandle1->object)->stormPrevPtr);
        stormPrevPtr += (port[index] - 1u);

        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_ENABLE_UC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_ENABLE_UC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledUC != 1)
        {
            PRINT("stormPrevPtr->suppressionEnabledUC != 1 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrUC[port[index] -1]), 4);
        if(value != 1)
        {
            PRINT("*(stormPreventionOffsetPtrUC[port[index] -1]) != 1 test for SWITCH failed\n");
            testPassed = 0;
        }

        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_DISABLE_UC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_DISABLE_UC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledUC != 0)
        {
            PRINT("stormPrevPtr->suppressionEnabledUC != 0 test for SWITCH failed\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrUC[port[index] -1]), 4);
        if(value != 0)
        {
            PRINT("*(stormPreventionOffsetPtrUC[port[index] - 1]) != 0 test for SWITCH failed\n");
            testPassed = 0;
        }
        stormPrevPtr->creditsUC = credit;
        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_ENABLE_UC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_UC;
        ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle1, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, port[index], (void*)&ioctlParams);
        if(ioctlRetVal != 0)
        {
            PRINT("IOCTL(ICSS_EMAC_STORM_PREV_CTRL_RESET_UC) test for SWITCH failed\n");
            testPassed = 0;
        }
        if(stormPrevPtr->suppressionEnabledUC != 1)
        {
            PRINT("stormPrevPtr->suppressionEnabledUC != 1\n");
            testPassed = 0;
        }
        byteCopy((void*)(&value), (void*)(stormPreventionOffsetPtrUC[port[index] -1]), 4);
        if(value != spResetVal)
        {
            PRINT("*(stormPreventionOffsetPtrUC[port[index] - 1]) != 1\n");
            testPassed = 0;
        }
    }

    if (testPassed == 0)
    {
        while(1)
        {
            PRINT("IOCTL test for SWITCH failed\n");
            Task_sleep(100);
        }
    }
    else
    {
        PRINT("IOCTL test for SWITCH passed\n");
    }
}
#endif
#endif

#ifdef am65xx_evm
Void test_ICSS_EMAC_verify(void)
{
    Bool retVal = FALSE;
    uint32_t count = 0;
    uint32_t gFail_count = 0;
    uint32_t fail_count= 0;
    ICSSEMAC_IoctlCmd ioctlParams;
    ICSS_EmacTxArgument txArgs;
    ICSS_EmacPktInfo rxPktInfo;
    memset(&txArgs, 0, sizeof(ICSS_EmacTxArgument));

    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);

    uint32_t result_flag = 0;
    result_flag = (PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle2, PRU_ICSS_IRAM(0) , 0,
                              (uint32_t *) PRU0_b00,
                              sizeof(PRU0_b00)));
    if(result_flag)
    {
        UART_printf("load to PRU0 passed\n");
        retVal = TRUE;
    }
    else
    {
        UART_printf("load to PRU0 failed\n");
    }
    result_flag = (PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle2, PRU_ICSS_IRAM(1) , 0,
                                  (uint32_t *) PRU1_b00,
                                  sizeof(PRU1_b00)));
    if(result_flag)
    {
        UART_printf("load to PRU1 passed\n");
        retVal = TRUE;
    }
    else
    {
        UART_printf("load to PRU0 failed\n");
    }

    if( retVal)
    {
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);


        while (!ICSS_EMAC_testLinkIsrPru2Eth0)
        {
            PRINT("ICSS_EMAC_testTaskPruss2: LINK IS DOWN, pluggin loopback cable for PRU2 ETH0\n");
            SLEEP(100);
        }
        ICSS_EMAC_testLinkUpCount++;
        PRINT("ICSS_EMAC_testTaskPruss2: PRU2 ETH0: LINK IS UP, eth0 state: %d, link up count: %d\n",
              ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0], ICSS_EMAC_testLinkUpCount);

        /* Creating Unicast packets in Non-Promiscuous Mode.*/
        for (count=0;count < 6;count++)
        {
            ICSS_EMAC_testPkt2[count] = ICSS_EMAC_testLclMac2[count];
        }

        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should be able to recieve packets as destination address == eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address == eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort2 = 1;
        
        memset(&rxPktInfo,0, sizeof(ICSS_EmacPktInfo));

        if (ICSS_EmacRxPktInfo2(ICSS_EMAC_testHandle2, &rxPktInfo) == 0)
        {
            PRINT("ICSS_EmacRxPktInfo2: no packet found, expected Result \n");
        }
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 1;
        txArgs.srcAddress = &ICSS_EMAC_testPkt2[0];

        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    /* test with invalid queue number */
                    txArgs.queuePriority = 4;
                    if (ICSS_EmacTxPacket(&txArgs, NULL) != 0)
                    {
                        PRINT("ICSS_EmacTxPacket: returned error with invalid queue number, expected Result \n");
                        /* test with valid queue number */
                        txArgs.queuePriority = 3;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                    }
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                    }
                }
            }
        }

        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address != eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort2 = 1;
    
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 1;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
        
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    fail_count = 0;
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                        fail_count++;
                        if(fail_count == 5)
                        {
                            PRINT("ICSS_EMAC_testTaskPruss2: Received no packet for PRU2 ETH0\n");
                            ICSS_EMAC_testPacketRcvdPort2 = 1;
                            break;
                        }
                    }                    
                }
            }
        }
        
        /* Enabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        
        promisEnableFlag = 1;           /* enabling promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
        
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        
        /* Sending Unicast packets in Promiscuous Mode. The eth should be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Promiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address != eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort2 = 1;
    
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 1;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
        
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] = 1;
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    fail_count = 0;
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                        fail_count++;
                    }                    
                }
            }
        }

        /* Testing the multicast filtering logic introduced under firmware and driver */
        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Multicast filtering ");
        PRINT("\n sending Multicast packets as destination address for MCF tests on EMAC Port 1");
        PRINT("\n============================================================\n\n");

        PRINT ("\nTesting multicast filtering logic begin\n");
        if(!ICSS_EMAC_testMulticastFiltering_EmacPort1(ICSS_EMAC_testHandle2))
        {
            PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing failed\n");
            gFail_count++;
        }
        else
        {
            PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing passed\n");
        }
        PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering logic end\n");

        /* Testing the vlan filtering logic introduced under firmware and driver */
        /* Sending VLAN packets in Promiscuous Mode. The Pkt is received as per the VLAN filtering rule */
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing VLAN filtering ");
        PRINT("\n sending VLAN test packets as destination address for Vlan filtering tests on Port 1");
        PRINT("\n============================================================\n\n");
        
        PRINT ("\nTesting vlan filtering logic begin\n");
        if(!ICSS_EMAC_testVlanFiltering_On_EmacPort(&ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1))
        {
            PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing failed on Port 1\n");
            gFail_count++;
        }
        else
        {
            PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing passed on Port 1\n");
        }
        PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering logic end\n");

        /* Disabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        
        promisEnableFlag = 0;           /* disabling promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
        
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        while (!ICSS_EMAC_testLinkIsrPru2Eth1)
        {
            PRINT("ICSS_EMAC_testTaskPruss2: LINK IS DOWN,skipping PRU2 ETH1\n");
        }
        ICSS_EMAC_testLinkUpCount++;
        PRINT("ICSS_EMAC_testTaskPruss2: PRU2 ETH1: LINK IS UP, eth0 state: %d, link up count: %d\n",
              ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0], ICSS_EMAC_testLinkUpCount);

        /* Creating Unicast packets in Non-Promiscuous Mode.*/
        for (count=0;count < 6;count++)
        {
            ICSS_EMAC_testPkt3[count] = ICSS_EMAC_testLclMac3[count];
        }

        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should be able to recieve packets as destination address == eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address == eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort3 = 1;
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 2;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPkt3[0];
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort3 )
                {
                    ICSS_EMAC_testPacketRcvdPort3 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    while(!ICSS_EMAC_testPacketRcvdPort3)
                    {
                        SLEEP(100);
                    }
                }
            }
        }
        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address != eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort3 = 1;
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 2;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort3 )
                {
                    ICSS_EMAC_testPacketRcvdPort3 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    fail_count = 0;
                    while(!ICSS_EMAC_testPacketRcvdPort3)
                    {
                        SLEEP(100);
                        fail_count++;
                        if(fail_count == 5)
                        {
                            PRINT("ICSS_EMAC_testTaskPruss2: Received no packet for PRU2 ETH1\n");
                            ICSS_EMAC_testPacketRcvdPort3 = 1;
                            break;
                        }
                    }
                }
            }
        }      

        /* Enabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);

        promisEnableFlag = 1;           /* enabling promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);

        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);

        /* Sending Unicast packets in Promiscuous Mode. The eth should be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Promiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address != eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort3 = 1;
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 2;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort3 )
                {
                    ICSS_EMAC_testPacketRcvdPort3 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    fail_count = 0;
                    while(!ICSS_EMAC_testPacketRcvdPort3)
                    {
                        SLEEP(100);
                        fail_count++;
                    }
                }
            }
        }

        /* Testing the multicast filtering logic introduced under firmware and driver */
        /* Sending Multicast packets in Promiscuous Mode, the packet is received as per the configurations */
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Multicast filtering ");
        PRINT("\n sending Multicast packets as destination address for MCF tests on EMAC Port 2");
        PRINT("\n============================================================\n\n");
        PRINT ("\nTesting multicast filtering logic begin\n");
        if(!ICSS_EMAC_testMulticastFiltering_EmacPort2(ICSS_EMAC_testHandle3))
        {
            PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing failed on Port 2\n");
                gFail_count++;
        }
        else
        {
            PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing passed on Port 2\n");
        }
        PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering logic end\n");

        /* Testing the vlan filtering logic introduced under firmware and driver */
        /* Sending VLAN packets in Promiscuous Mode. The Pkt is received as per the VLAN filtering rule */
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing VLAN filtering ");
        PRINT("\n sending VLAN test packets as destination address for Vlan filtering tests on Port 2");
        PRINT("\n============================================================\n\n");
        PRINT ("\nTesting vlan filtering logic begin\n");
        if(!ICSS_EMAC_testVlanFiltering_On_EmacPort(&ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2))
        {
            PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing failed on Port 2\n");
            gFail_count++;
        }
        else
        {
            PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing passed on Port 2\n");
        }
        PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering logic end\n");

        /* Disabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);

        promisEnableFlag = 0;           /* disabling promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);

        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);

        while(!ICSS_EMAC_testLinkIsrPru2Eth0 && !ICSS_EMAC_testLinkIsrPru2Eth1)
        {
            PRINT("\nICSS_EMAC_testTaskPruss2: LINK IS DOWN, pluggin loopback cable for PRU2 ETH0 and PRU2 ETH1.\n");
        }



        PRINT("\nDone with PRU-ICSS Instance 2 Testing\n");

        ICSS_EMAC_testGetPruStats(1, ICSS_EMAC_testHandle2);
        ICSS_EMAC_testPruInstance2Done = 1;

        ICSS_EmacDeInit(ICSS_EMAC_testHandle2, ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);

        if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM572x)
        {
            ICSS_EMAC_testGetPruStats(2, ICSS_EMAC_testHandle3);
            ICSS_EmacDeInit(ICSS_EMAC_testHandle3, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
        }

        if ((gFail_count == 0) &&
            (ICSS_EMAC_testTotalPktRcvd == (ICSS_EMAC_TEST_PKT_TX_COUNT*ICSS_EMAC_testLinkUpCount)))
        {
            PRINT("All tests have passed\n");
#ifdef UNITY_INCLUDE_CONFIG_H
            TEST_PASS();
#endif
        }
        else
        {
            PRINT("Few/All tests have failed\n");
#ifdef UNITY_INCLUDE_CONFIG_H
            TEST_FAIL();
#endif
        }
    }
    else
    {
        PRINT("ICSS_EMAC_testTaskPruss2: firmware load failure\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
    }
}



void test_Icss_Emac_TestApp_runner(void)
{
    /* @description:Test runner for ICSS-EMAC tests

       @requirements: PRSDK-4441

       @cores: mpu1_0*/

    UNITY_BEGIN();
    RUN_TEST(test_ICSS_EMAC_verify);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
}



Void ICSS_EMAC_testTask_am65xx(UArg a0, UArg a1)
{
    test_Icss_Emac_TestApp_runner();
}

#else
#ifdef __LINUX_USER_SPACE
void *ICSS_EMAC_testTaskPruss2(void *a0)
#else
Void ICSS_EMAC_testTaskPruss2(UArg a0, UArg a1)
#endif
{
    Bool retVal = FALSE;
    uint32_t count = 0;
    uint32_t gFail_count = 0;
#ifndef SWITCH_EMAC
    int8_t ret = 0;
    uint32_t fail_count= 0;
    ICSSEMAC_IoctlCmd ioctlParams;
#endif
    ICSS_EmacTxArgument txArgs;
    ICSS_EmacPktInfo rxPktInfo;
    memset(&txArgs, 0, sizeof(ICSS_EmacTxArgument));

#if defined(idkAM572x)
#ifdef __LINUX_USER_SPACE
    ICSS_EMAC_testPgVersion = 2;
#else
    ICSS_EMAC_testPgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;
#endif
#elif defined(idkAM574x)
    ICSS_EMAC_testPgVersion = 2;
#endif

    PRINT("ICSS_EMAC_testTaskPruss2: ICSS_EMAC_testPgVersion: 0x%x\n", ICSS_EMAC_testPgVersion);
    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
    PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);

#ifndef am65xx_evm
    retVal = ICSS_EMAC_testDMemInit(ICSS_EMAC_testPruIcssHandle2);
    if (!retVal)
    {
        return;
    }
    retVal = ICSS_EMAC_testFwVerValidate(ICSS_EMAC_testHandle2);
    if (!retVal)
    {
        return;
    }
    retVal = ICSS_EMAC_testIMemInit(ICSS_EMAC_testPruIcssHandle2);

#else
    uint32_t result_flag = 0;
    result_flag = (PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle2, PRU_ICSS_IRAM(0) , 0,
                              (uint32_t *) PRU0_b00,
                              sizeof(PRU0_b00)));
    if(result_flag)
    {
        UART_printf("load to PRU0 passed\n");
        retVal = TRUE;
    }
    else
    {
        UART_printf("load to PRU0 failed\n");
    }
    result_flag = (PRUICSS_pruWriteMemory(ICSS_EMAC_testPruIcssHandle2, PRU_ICSS_IRAM(1) , 0,
                                  (uint32_t *) PRU1_b00,
                                  sizeof(PRU1_b00)));
    if(result_flag)
    {
        UART_printf("load to PRU1 passed\n");
        retVal = TRUE;
    }
    else
    {
        UART_printf("load to PRU0 failed\n");
    }
#endif

    if( retVal)
    {
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);


        while (!ICSS_EMAC_testLinkIsrPru2Eth0)
        {
            PRINT("ICSS_EMAC_testTaskPruss2: LINK IS DOWN, pluggin loopback cable for PRU2 ETH0\n");
            SLEEP(100);
        }
        ICSS_EMAC_testLinkUpCount++;
        PRINT("ICSS_EMAC_testTaskPruss2: PRU2 ETH0: LINK IS UP, eth0 state: %d, link up count: %d\n",
              ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0], ICSS_EMAC_testLinkUpCount);

        /* Creating Unicast packets in Non-Promiscuous Mode.*/
        for (count=0;count < 6;count++)
        {
            ICSS_EMAC_testPkt2[count] = ICSS_EMAC_testLclMac2[count];
        }
    
#ifdef SWITCH_EMAC
    /* Verify IOCTL functionality for switch use case which validates fw versiononing check for both ports */
    ICSSEMAC_IoctlCmd ioctlParams;
    ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET;
    int8_t ioctlRetVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, ICSS_EMAC_PORT_0, (void*)&ioctlParams);
    if (ioctlRetVal != 0)
    {
        while(1)
        {
            PRINT("IOCTL test for SWITCH failed\n");
            Task_sleep(100);
        }
    }
    else
    {
            PRINT("IOCTL test for SWITCH passed\n");
    }
#if defined (STP_SWITCH)
    stp_switch_init();
#endif /* STP_SWITCH */
#endif

#ifdef SWITCH_EMAC
		/* Sending Unicast packets in Switch Firmware. */
		PRINT("\n\n\n============================================================");
		PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Switch Firmware ");
		PRINT("\n sending Unicast packets as destination address == eth own address");
		PRINT("\n============================================================\n\n");
#else

        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should be able to recieve packets as destination address == eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address == eth own address");
        PRINT("\n============================================================\n\n");
#endif
        ICSS_EMAC_testPacketRcvdPort2 = 1;
    
        memset(&rxPktInfo,0, sizeof(ICSS_EmacPktInfo));

        if (ICSS_EmacRxPktInfo2(ICSS_EMAC_testHandle2, &rxPktInfo) == 0)
        {
            PRINT("ICSS_EmacRxPktInfo2: no packet found, expected Result \n");
        }
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
#ifdef SWITCH_EMAC
        txArgs.portNumber = 0;
#else
        txArgs.portNumber = 1;
#endif
        
        txArgs.srcAddress = &ICSS_EMAC_testPkt2[0];
	
#if defined (STP_SWITCH)
	/* Firmware Switch main testing loop. Should NOT return. */
	stp_switch_main_loop(txArgs);
#endif /* STP_SWITCH */
        
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    /* test with invalid queue number */
                    txArgs.queuePriority = 4;
                    if (ICSS_EmacTxPacket(&txArgs, NULL) != 0)
                    {
                        PRINT("ICSS_EmacTxPacket: returned error with invalid queue number, expected Result \n");
                        /* test with valid queue number */
                        txArgs.queuePriority = 3;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                    }
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                    }
                }
            }
        }

#ifndef SWITCH_EMAC
        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address != eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort2 = 1;
    
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 1;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
        
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            if(((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] )
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    fail_count = 0;
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                        fail_count++;
                        if(fail_count == 5)
                        {
                            PRINT("ICSS_EMAC_testTaskPruss2: Received no packet for PRU2 ETH0\n");
                            ICSS_EMAC_testPacketRcvdPort2 = 1;
                            break;
                        }
                    }                    
                }
            }
        }
        
        /* Enabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        
        promisEnableFlag = 1;           /* enabling promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
        
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        
        /* Sending Unicast packets in Promiscuous Mode. The eth should be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Promiscuous Mode ");
        PRINT("\n sending Unicast packets as destination address != eth own address");
        PRINT("\n============================================================\n\n");
        ICSS_EMAC_testPacketRcvdPort2 = 1;
    
        txArgs.icssEmacHandle = ICSS_EMAC_testHandle2;
        txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
        txArgs.portNumber = 1;
        txArgs.queuePriority = 3;
        txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
        
        ((ICSS_EmacObject*)ICSS_EMAC_testHandle2->object)->linkStatus[0] = 1;
        for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
        {
            {
                if(ICSS_EMAC_testPacketRcvdPort2 )
                {
                    ICSS_EMAC_testPacketRcvdPort2 = 0;
                    ICSS_EmacTxPacket(&txArgs, NULL);
                    fail_count = 0;
                    while(!ICSS_EMAC_testPacketRcvdPort2)
                    {
                        SLEEP(100);
                        fail_count++;
                    }                    
                }
            }
        }

#ifndef SWITCH_EMAC
        /* Testing the multicast filtering logic introduced under firmware and driver */
        /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Multicast filtering ");
        PRINT("\n sending Multicast packets as destination address for MCF tests on EMAC Port 1");
        PRINT("\n============================================================\n\n");

        PRINT ("\nTesting multicast filtering logic begin\n");
        if(!ICSS_EMAC_testMulticastFiltering_EmacPort1(ICSS_EMAC_testHandle2))
        {
            PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing failed\n");
            gFail_count++;
        }
        else
        {
            PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing passed\n");
        }
        PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering logic end\n");

        /* Testing the vlan filtering logic introduced under firmware and driver */
        /* Sending VLAN packets in Promiscuous Mode. The Pkt is received as per the VLAN filtering rule */
        PRINT("\n\n\n============================================================");
        PRINT("\n ICSS_EMAC_testTaskPruss2: Testing VLAN filtering ");
        PRINT("\n sending VLAN test packets as destination address for Vlan filtering tests on Port 1");
        PRINT("\n============================================================\n\n");
        
        PRINT ("\nTesting vlan filtering logic begin\n");
        if(!ICSS_EMAC_testVlanFiltering_On_EmacPort(&ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1))
        {
            PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing failed on Port 1\n");
            gFail_count++;
        }
        else
        {
            PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing passed on Port 1\n");
        }
        PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering logic end\n");
#endif

        /* Disabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        
        promisEnableFlag = 0;           /* disabling promiscuous mode */
        ioctlParams.command = 0;
        ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
        retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle2, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
        
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM571x)
        {
            PRINT("ICSS_EMAC_testTaskPruss2: Skipping ICSS_EMAC_TEST_PRU2ETH1 for AM571x\n");
            PRINT("ICSS_EMAC_testTaskPruss2: Skipping TTS Tests for PRUICSS Instance 2 for AM571x\n");
        }
        else
        {
            while (!ICSS_EMAC_testLinkIsrPru2Eth1)
            {
                PRINT("ICSS_EMAC_testTaskPruss2: LINK IS DOWN,skipping PRU2 ETH1\n");
            }
            ICSS_EMAC_testLinkUpCount++;
            PRINT("ICSS_EMAC_testTaskPruss2: PRU2 ETH1: LINK IS UP, eth0 state: %d, link up count: %d\n",
                  ((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0], ICSS_EMAC_testLinkUpCount);

            /* Creating Unicast packets in Non-Promiscuous Mode.*/
            for (count=0;count < 6;count++)
            {
                ICSS_EMAC_testPkt3[count] = ICSS_EMAC_testLclMac3[count];
            }
    
            /* Sending Unicast packets in Non-Promiscuous Mode. The eth should be able to recieve packets as destination address == eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address == eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort3 = 1;
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 2;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPkt3[0];
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
                {
                    if(ICSS_EMAC_testPacketRcvdPort3 )
                    {
                        ICSS_EMAC_testPacketRcvdPort3 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        while(!ICSS_EMAC_testPacketRcvdPort3)
                        {
                            SLEEP(100);
                        }
                    }
                }
             }
            /* Sending Unicast packets in Non-Promiscuous Mode. The eth should not be able to recieve packets as destination address != eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss2: Testing NonPromiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address != eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort3 = 1;
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 2;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
                {
                    if(ICSS_EMAC_testPacketRcvdPort3 )
                    {
                        ICSS_EMAC_testPacketRcvdPort3 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        fail_count = 0;
                        while(!ICSS_EMAC_testPacketRcvdPort3)
                        {
                            SLEEP(100);
                            fail_count++;
                            if(fail_count == 5)
                            {
                                PRINT("ICSS_EMAC_testTaskPruss2: Received no packet for PRU2 ETH1\n");
                                ICSS_EMAC_testPacketRcvdPort3 = 1;
                                break;
                            }
                        }
                    }
                }
            }      

            /* Enabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
            
            promisEnableFlag = 1;           /* enabling promiscuous mode */
            ioctlParams.command = 0;
            ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
            
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
        
            /* Sending Unicast packets in Promiscuous Mode. The eth should be able to recieve packets as destination address != eth own address*/
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Promiscuous Mode ");
            PRINT("\n sending Unicast packets as destination address != eth own address");
            PRINT("\n============================================================\n\n");
            ICSS_EMAC_testPacketRcvdPort3 = 1;
            txArgs.icssEmacHandle = ICSS_EMAC_testHandle3;
            txArgs.lengthOfPacket = ICSS_EMAC_TEST_PKT_SIZE;
            txArgs.portNumber = 2;
            txArgs.queuePriority = 3;
            txArgs.srcAddress = &ICSS_EMAC_testPktPromicuous[0];
            for (count=0;count < ICSS_EMAC_TEST_PKT_TX_COUNT;count++)
            {
                if(((ICSS_EmacObject*)ICSS_EMAC_testHandle3->object)->linkStatus[0] )
                {
                    if(ICSS_EMAC_testPacketRcvdPort3 )
                    {
                        ICSS_EMAC_testPacketRcvdPort3 = 0;
                        ICSS_EmacTxPacket(&txArgs, NULL);
                        fail_count = 0;
                        while(!ICSS_EMAC_testPacketRcvdPort3)
                        {
                            SLEEP(100);
                            fail_count++;
                        }
                    }
                }
            }
#ifndef SWITCH_EMAC

            /* Testing the multicast filtering logic introduced under firmware and driver */
            /* Sending Multicast packets in Promiscuous Mode, the packet is received as per the configurations */
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss2: Testing Multicast filtering ");
            PRINT("\n sending Multicast packets as destination address for MCF tests on EMAC Port 2");
            PRINT("\n============================================================\n\n");

            PRINT ("\nTesting multicast filtering logic begin\n");
            if(!ICSS_EMAC_testMulticastFiltering_EmacPort2(ICSS_EMAC_testHandle3))
            {
                PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing failed on Port 2\n");
                gFail_count++;
            }
            else
            {
                PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering testing passed on Port 2\n");
            }
            PRINT("ICSS_MEAC_testTaskPruss2:multicast filtering logic end\n");


            /* Testing the vlan filtering logic introduced under firmware and driver */
            /* Sending VLAN packets in Promiscuous Mode. The Pkt is received as per the VLAN filtering rule */
            PRINT("\n\n\n============================================================");
            PRINT("\n ICSS_EMAC_testTaskPruss2: Testing VLAN filtering ");
            PRINT("\n sending VLAN test packets as destination address for Vlan filtering tests on Port 2");
            PRINT("\n============================================================\n\n");

            PRINT ("\nTesting vlan filtering logic begin\n");
            if(!ICSS_EMAC_testVlanFiltering_On_EmacPort(&ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2))
            {
                PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing failed on Port 2\n");
                gFail_count++;
            }
            else
            {
                PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering testing passed on Port 2\n");
            }
            PRINT("ICSS_MEAC_testTaskPruss2:vlan filtering logic end\n");
#endif
            /* Disabling Promiscuous Mode. Hence, disable -> reset -> change mmap -> enable */
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruDisable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruReset(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);
            
            promisEnableFlag = 0;           /* disabling promiscuous mode */
            ioctlParams.command = 0;
            ioctlParams.ioctlVal = (void *)(&promisEnableFlag);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_1, &ioctlParams);
            retVal = ICSS_EmacIoctl(ICSS_EMAC_testHandle3, ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL, ICSS_EMAC_PORT_2, &ioctlParams);
            
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruEnable(ICSS_EMAC_testPruIcssHandle2, ICSS_EMAC_PORT_2-1);


#ifndef __TI_ARM_V7M4__
#ifndef iceK2G
            while(!ICSS_EMAC_testLinkIsrPru2Eth0 && !ICSS_EMAC_testLinkIsrPru2Eth1)
            {
                PRINT("\nICSS_EMAC_testTaskPruss2: LINK IS DOWN, pluggin loopback cable for PRU2 ETH0 and PRU2 ETH1.\n");
            }

            PRINT("\n============================================================");
            PRINT("\nInitiating TTS tests on ICSS_EMAC_TEST_PRU2ETH0 and ICSS_EMAC_TEST_PRU2ETH1");
    
            /*    Create TTS related semaphores    */
            ret = ICSS_EMAC_testTtsSemCreate();
            assert(ret == 0);
    
            ICSS_EMAC_testTtsModePort1 = 1;
            ICSS_EMAC_testTtsModePort2 = 1;
    
            /*    Wait for TTS test to complete    */
            while(ICSS_EMAC_testTtsModePort1 || ICSS_EMAC_testTtsModePort2)
            {
                SLEEP(10);
            }
            ICSS_EMAC_testTtsSemDestroy();

            PRINT("\n============================================================");
            PRINT("\nTTS tests finished on ICSS_EMAC_TEST_PRU2ETH0 and ICSS_EMAC_TEST_PRU2ETH1");
            PRINT("\n============================================================");
#endif
#endif
        }
#endif

#ifndef __LINUX_USER_SPACE
#if defined(idkAM572x) || defined(idkAM574x)
#ifndef SWITCH_EMAC
        PRINT("\nTesting queue-overflow logic begin\n");
        if (!ICSS_EMAC_testQueueOverflow(ICSS_EMAC_testHandle2))
        {
            PRINT("ICSS_EMAC_testTaskPruss2:queue overflow count testing faiured\n");
            return;
        }
        PRINT("ICSS_EMAC_testTaskPruss2:queue overflow count testing passed\n");
        PRINT("\nTesting queue-overflow logic end\n");	
#endif
#endif
#endif
        PRINT("\nDone with PRU-ICSS Instance 2 Testing\n");
    
        ICSS_EMAC_testGetPruStats(1, ICSS_EMAC_testHandle2);
        ICSS_EMAC_testPruInstance2Done = 1;

#ifndef SWITCH_EMAC 
#ifndef am65xx_evm
        ICSS_EMAC_testInterruptDisable(ICSS_EMAC_testHandle2);
#endif
        ICSS_EmacDeInit(ICSS_EMAC_testHandle2, ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC);

        if(ICSS_EMAC_testEvmType == ICSS_EMAC_TEST_BOARD_IDKAM572x)
        {
            ICSS_EMAC_testGetPruStats(2, ICSS_EMAC_testHandle3);
#ifndef am65xx_evm
            ICSS_EMAC_testInterruptDisable(ICSS_EMAC_testHandle3);
#endif
            ICSS_EmacDeInit(ICSS_EMAC_testHandle3, ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC);
        }
#else
	ICSS_EMAC_testInterruptDisable(ICSS_EMAC_testHandle2);
        ICSS_EmacDeInit(ICSS_EMAC_testHandle2, ICSS_EMAC_MODE_SWITCH);
#endif

        /* for AM571x, this will be printed after PRU-ICSS instance 1 testing */
#if defined(idkAM574x) || defined(idkAM437x) || defined(idkAM572x) || (defined(SWITCH_EMAC) && defined(idkAM571x))

#ifdef SWITCH_EMAC
if ((gFail_count == 0) &&
    (ICSS_EMAC_testTotalPktRcvd == (2*ICSS_EMAC_TEST_PKT_TX_COUNT*ICSS_EMAC_testLinkUpCount)))
{
    PRINT("All tests have passed\n");
}
else
{
    PRINT("Few/All tests have failed\n");
}

#else
        if ((gFail_count == 0) &&
            (ICSS_EMAC_testTotalPktRcvd == (ICSS_EMAC_TEST_PKT_TX_COUNT*ICSS_EMAC_testLinkUpCount)))
        {
            PRINT("All tests have passed\n");
        }
        else
        {
            PRINT("Few/All tests have failed\n");
        }
#endif
#endif
    }
    else
    {
        PRINT("ICSS_EMAC_testTaskPruss2: firmware load failure\n");
    }
}
#endif
