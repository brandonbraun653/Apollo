/**
 * @file stp_switch_test_utils.c
 * @brief Contains utility APIs used by icss_stp_switch unit tests. 
 *
 */

/* Copyright (C) {2019} Texas Instruments Incorporated - http://www.ti.com/ 
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

#include "stp_switch_test_utils.h"

#include <ti/drv/icss_emac/icss_emacFwLearning.h>
#include <ti/drv/icss_emac/firmware/icss_switch/src/icss_stp_switch.h>
#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/icss_emacFwInit.h>

#ifndef __LINUX_USER_SPACE
#include <ti/sysbios/knl/Task.h>
#include <ti/drv/uart/UART_stdio.h>
#define SLEEP Task_sleep
#define PRINT UART_printf
#endif

/* ========================================================================== */
/*                           Externed Variables                               */
/* ========================================================================== */
extern ICSS_EmacHandle ICSS_EMAC_testHandle2;
extern uint32_t ICSS_EMAC_testTotalPktRcvd;
extern uint8_t ICSS_EMAC_testPacketArrayInstance2[256];
extern uint8_t ICSS_EMAC_testLclMac[6];
extern uint8_t ICSS_EMAC_testLclMac1[6];
extern uint8_t ICSS_EMAC_testLclMac2[6];
extern uint8_t ICSS_EMAC_testLclMac3[6];

/* ========================================================================== */
/*                            Module Variables                                */
/* ========================================================================== */
static uint8_t ICSS_EMAC_broadcastMac[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
static uint8_t ICSS_EMAC_fwSwitchTestMac[6] = {0x02, 0xDE, 0xAD, 0xBE, 0xEF, 0x69};
static uint8_t ICSS_EMAC_fwSwitchTestMac1[6] = {0x02, 0x01, 0x01, 0x01, 0x01, 0x69};
static uint8_t ICSS_EMAC_fwSwitchTestMac2[6] = {0x02, 0x02, 0x02, 0x02, 0x02, 0x69};
static uint8_t ICSS_EMAC_mcBpduMac[6] = {0x01, 0x80, 0xC2, 0x00, 0x00, 0x00};
static uint8_t ICSS_EMAC_vlanBpduMac[6] = {0x01, 0x00, 0x0C, 0xCC, 0xCC, 0xCD};

/* ========================================================================== */
/*                      Local Function Declarations                           */
/* ========================================================================== */
static void print_transaction(uint8_t *srcMac, uint8_t *dstMac, ICSS_EmacPktInfo rxPktInfo);
static void print_fdb(Fdb *fdb);
static int32_t validate_flood_bit(ICSS_EmacPktInfo rxPktInfo);
static void print_bpdu_info();
static void ioctl_stp_state(uint8_t stpState, uint8_t portNo);
static void ioctl_fdb_insert_static(MAC mac, uint8_t portNo);
static void ioctl_fdb_delete(MAC mac);
static void ioctl_purge_fdb();
static void ioctl_enable_multicast_filter();
static void ioctl_allow_mc_addr(uint8_t *macId);
static void run_test_command(ICSS_EmacHandle icssEmacHandle, ICSS_EmacPktInfo rxPktInfo);

/* ========================================================================== */
/*                       Global Function Definitions                          */
/* ========================================================================== */
void stp_switch_init() {
  uint8_t stpState;
  ICSSEMAC_IoctlCmd ioctlParams;
  uint8_t i;
  uint8_t macId1[6] = {0x01, 0x77, 0x77, 0x77, 0x77, 0x77};
  uint8_t macId2[6] = {0x01, 0x69, 0x69, 0x69, 0x69, 0x69};
  uint8_t bpdu_macId[6] = {0x01, 0x80, 0xC2, 0x00, 0x00, 0x00};

  /**
   * Initialize FDB
   */
  ioctlParams.command = ICSS_EMAC_FW_LEARN_CTRL_INIT_TABLE;
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_FW_LEARNING_CTRL,
		 ICSS_EMAC_PORT_0, /* portNo doesn't matter for init */
		 (void*)&ioctlParams);

  /**
   * Set starting FDB STP per-port state
   */
  stpState = RSTP_STATE_FORWARDING;
  ioctlParams.command = ICSS_EMAC_FW_LEARN_CTRL_SET_PORTSTATE;
  ioctlParams.ioctlVal = (void *)&stpState;

  /* Port 1 */
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_FW_LEARNING_CTRL,
		 ICSS_EMAC_PORT_1,
		 (void*)&ioctlParams);

  /* Port 2 */
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_FW_LEARNING_CTRL,
		 ICSS_EMAC_PORT_2,
		 (void*)&ioctlParams);

  /**
   * Allow selected Multicast traffic
   */
  ioctl_enable_multicast_filter();
  
  /* CFG MAC addresses */
  ioctl_allow_mc_addr(macId1);
  ioctl_allow_mc_addr(macId2);  

  /* Reserved BPDU MAC addresses */
  for(i = 0; i < 0x10; i++) {
    bpdu_macId[5] = i;
    ioctl_allow_mc_addr(bpdu_macId);
  }
  
  /* Test BPDU MAC addresses */
  for(i = 0x10; i < 0x14; i++) {
    bpdu_macId[5] = i;
    ioctl_allow_mc_addr(bpdu_macId);
  }
}

void stp_switch_main_loop(ICSS_EmacTxArgument txArgs) {
  while(1) { 
    /* Spin while the RX task runs, have no need for TX in the switch test */
  }
}

void stp_switch_test(ICSS_EmacHandle icssEmacHandle, ICSS_EmacPktInfo rxPktInfo) {      
  Fdb *fdb = ((ICSS_EmacObject*)(icssEmacHandle->object))->fdb;
  static uint32_t testPktsRcvd = 0;

  /* Track packet statistics for all packets */
  ICSS_EMAC_testTotalPktRcvd++;  

  /* It is possible that we have received some extraneous traffic... */
  /* ... only analyze packets recieved from/to test MAC addresses */
  if( (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[0], /* Test MAC 0 */
		   &ICSS_EMAC_fwSwitchTestMac[0], 6))
       || (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[6],
		       &ICSS_EMAC_fwSwitchTestMac[0], 6))
       
       || (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[0], /* Test MAC 1 */
		       &ICSS_EMAC_fwSwitchTestMac1[0], 6))
       || (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[6],
		       &ICSS_EMAC_fwSwitchTestMac1[0], 6))
       
       || (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[0], /* Test MAC 2 */
		       &ICSS_EMAC_fwSwitchTestMac2[0], 6))
       || (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[6],
		       &ICSS_EMAC_fwSwitchTestMac2[0], 6)) ) {
	
    /* For this test, only increase the RcvdPort2 stats when receive packet from test address */
    testPktsRcvd++; /* PRU2 ETH 0 */
    
    /* Print transaction information */
    PRINT("vvvvvvvvvvvvvvvvvvv\n");
    /* PRINT("%d: ", testPktsRcvd); */
    print_transaction(&ICSS_EMAC_testPacketArrayInstance2[6], &ICSS_EMAC_testPacketArrayInstance2[0],
		      rxPktInfo);

    /* Print the FDB */
    print_fdb(fdb);
    
    /* Print BPDU information (if applicable) */
    /* print_bpdu_info(); */

    run_test_command(icssEmacHandle, rxPktInfo);
    
    PRINT("^^^^^^^^^^^^^^^^^^^\n");    
  }
}

/* ========================================================================== */
/*                       Local Function Definitions                           */
/* ========================================================================== */
static void print_transaction(uint8_t *srcMac, uint8_t *dstMac, ICSS_EmacPktInfo rxPktInfo) {
  PRINT("[%02x:%02x:%02x:%02x:%02x:%02x]->[%02x:%02x:%02x:%02x:%02x:%02x] port:%d flood:%d insert:%d\n",
	srcMac[0], srcMac[1], srcMac[2], srcMac[3], srcMac[4], srcMac[5],
	dstMac[0], dstMac[1], dstMac[2], dstMac[3], dstMac[4], dstMac[5],
	rxPktInfo.portNumber, rxPktInfo.flooded, !rxPktInfo.fdbLookupSuccess);
}

static void print_fdb(Fdb *fdb) {
  uint16_t i, j, start, len;
  for(i = 0; i < FDB__INDEX_TBL__MAX_ENTRIES; i++) {
    if (fdb->indexTbl->entries[i].numBucketEntries > 0) {
      start = fdb->indexTbl->entries[i].bucketIndex;
      len = fdb->indexTbl->entries[i].numBucketEntries;
      PRINT("[0x%02x]: len:%d\n", i, len, start);
      
      PRINT("{");
      for(j = start; j < start + len; j++) {
	PRINT("[%02x:%02x:%02x:%02x:%02x:%02x](%d)",
	      fdb->macTbl->entries[j].mac.macId[0],
	      fdb->macTbl->entries[j].mac.macId[1],
	      fdb->macTbl->entries[j].mac.macId[2],
	      fdb->macTbl->entries[j].mac.macId[3],
	      fdb->macTbl->entries[j].mac.macId[4],
	      fdb->macTbl->entries[j].mac.macId[5],
	      fdb->macTbl->entries[j].portNo + 1);
      }
      PRINT("}\n");
    }
    
  }
}

static int32_t validate_flood_bit(ICSS_EmacPktInfo rxPktInfo) {
  int32_t retVal = 0;

  /**
   * Packet flooded
   */
  if (0 == rxPktInfo.flooded) {
    /* Check erroneous FLOOD clear */
    if ((0 != memcmp(&ICSS_EMAC_testPacketArrayInstance2[6], &ICSS_EMAC_testLclMac[0], 6)) ||
	(0 != memcmp(&ICSS_EMAC_testPacketArrayInstance2[6], &ICSS_EMAC_testLclMac2[0], 6))) {
      PRINT("FLOOD BIT ERROR: bit clear, but packet is not destined for host\n");
      retVal = -1;
    }

    /* Flood bit properly cleared */
    else {
      PRINT("Flood bit properly cleared, destined for host. Ignore packet.\n");
    }
  }
  
  /**
   * Packet not flooded
   */
  else {
    /* Check erroneous FLOOD set */
    if ((0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[6], &ICSS_EMAC_testLclMac[0], 6)) ||
	(0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[6], &ICSS_EMAC_testLclMac2[0], 6))) {
      PRINT("FLOOD BIT ERROR: bit set, but packet is actually destined for host\n");
      retVal = -1;
    }
    
    /* Flood bit properly set */
    else {
      PRINT("Flood bit properly set. Continue processing packet.\n");
    }
  }

  return retVal;
}

static void print_bpdu_info() {
  if (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[0],
		  &ICSS_EMAC_mcBpduMac[0], 6)) {
    PRINT("Got Multicast BPDU!\n");
  }
  
  else if (0 == memcmp(&ICSS_EMAC_testPacketArrayInstance2[0],
		       &ICSS_EMAC_vlanBpduMac[0], 6)) {
    PRINT("Got VLAN BPDU!\n");
  }   
}

static void ioctl_stp_state(uint8_t stpState, uint8_t portNo) {
  ICSSEMAC_IoctlCmd ioctlParams;

  ioctlParams.command = ICSS_EMAC_FW_LEARN_CTRL_SET_PORTSTATE;
  ioctlParams.ioctlVal = (void *)&stpState;
  
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_FW_LEARNING_CTRL,
		 portNo,
		 (void*)&ioctlParams);
}

static void ioctl_fdb_insert_static(MAC mac, uint8_t portNo) {
  ICSSEMAC_IoctlCmd ioctlParams;
  
  ioctlParams.command = ICSS_EMAC_FW_LEARN_CTRL_INSERT_STATIC_MAC;
  ioctlParams.ioctlVal = (void *)&mac;
  
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_FW_LEARNING_CTRL,
		 portNo,
		 (void*)&ioctlParams);
}

static void ioctl_fdb_delete(MAC mac) {
  ICSSEMAC_IoctlCmd ioctlParams;
  
  ioctlParams.command = ICSS_EMAC_FW_LEARN_CTRL_REMOVE_MAC;
  ioctlParams.ioctlVal = (void *)&mac;
  
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_FW_LEARNING_CTRL,
		 0, /* portNo doesn't matter for delete */
		 (void*)&ioctlParams);
}

static void ioctl_purge_fdb() {
  ICSSEMAC_IoctlCmd ioctlParams;
  
  ioctlParams.command = ICSS_EMAC_FW_LEARN_CTRL_CLR_TABLE;
  
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_FW_LEARNING_CTRL,
		 0, /* portNo doesn't matter for purge */
		 (void*)&ioctlParams);
}

static void ioctl_enable_multicast_filter() {
  ICSSEMAC_IoctlCmd ioctlParams;
  
  /**
   * Enable Multicast Filtering
   */
  ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ENABLE;
  ioctlParams.ioctlVal = NULL;

  /* Port 1 */  
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL,
		 ICSS_EMAC_PORT_1,
		 (void*)&ioctlParams);
  /* Port 2 */
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL,
		 ICSS_EMAC_PORT_2,
		 (void*)&ioctlParams);
}

static void ioctl_allow_mc_addr(uint8_t *macId) {
  ICSSEMAC_IoctlCmd ioctlParams;
 
  /**
   * Allow Multicast Address through filter
   */
  ioctlParams.command = ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ADD_MACID;
  ioctlParams.ioctlVal = (void *) &macId[0];

  /* Port 1 */
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL,
		 ICSS_EMAC_PORT_1,
		 (void*)&ioctlParams);

  /* Port 2 */
  ICSS_EmacIoctl(ICSS_EMAC_testHandle2,
		 ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL,
		 ICSS_EMAC_PORT_2,
		 (void*)&ioctlParams);
}

static void run_test_command(ICSS_EmacHandle icssEmacHandle, ICSS_EmacPktInfo rxPktInfo) {
  uint8_t stpState;  
  Fdb *fdb = ((ICSS_EmacObject*)(icssEmacHandle->object))->fdb;
  /**
   * Parse final byte in "Target Protocol Address" field in ARP packet to determing test command:
   * - 1: Purge FDB
   * - 2: Set RSTP state to RSTP_STATE_DISCARDING
   * - 3: Set RSTP state to RSTP_STATE_LEARNING
   * - 4: Set RSTP state to RSTP_STATE_FORWARDING
   * - 5: Set STP state to STP_STATE_DISABLED
   * - 6: Set STP state to STP_STATE_LISTENING
   * - 7: Set STP state to STP_STATE_LEARNING
   * - 8: Set STP state to STP_STATE_FORWARDING
   * - 9: Set STP state to STP_STATE_BLOCKING
   */

  switch(*((uint32_t*)&ICSS_EMAC_testPacketArrayInstance2[38])) {
    case 0x01010101:
      PRINT("### Purge table ###\n");
      ioctl_purge_fdb();
      print_fdb(fdb);
      break;  
    case 0x02020202:
      PRINT("### Set RSTP state DISCARDING ###\n");
      ioctl_stp_state(RSTP_STATE_DISCARDING, rxPktInfo.portNumber);
      break;
    case 0x03030303:
      PRINT("### Set RSTP state LEARNING ###\n");
      ioctl_stp_state(RSTP_STATE_LEARNING, rxPktInfo.portNumber);
      break;
    case 0x04040404:
      PRINT("### Set RSTP state FORWARDING ###\n");
      ioctl_stp_state(RSTP_STATE_FORWARDING, rxPktInfo.portNumber);
      break;
    case 0x05050505:
      PRINT("### Set STP state DISABLED ###\n");
      ioctl_stp_state(STP_STATE_DISABLED, rxPktInfo.portNumber);
      break;
    case 0x06060606:
      PRINT("### Set STP state LISTENING ###\n");
      ioctl_stp_state(STP_STATE_LISTENING, rxPktInfo.portNumber);
      break;
    case 0x07070707:
      PRINT("### Set STP state LEARNING ###\n");
      ioctl_stp_state(STP_STATE_LEARNING, rxPktInfo.portNumber);
      break;
    case 0x08080808:
      PRINT("### Set STP state FORWARDING ###\n");
      ioctl_stp_state(STP_STATE_FORWARDING, rxPktInfo.portNumber);
      break;
    case 0x09090909:
      PRINT("### Set STP state BLOCKING ###\n");
      ioctl_stp_state(STP_STATE_BLOCKING, rxPktInfo.portNumber);
      break;
    default:
      /*PRINT("--- Invalid Test Command: %d ---\n", ICSS_EMAC_testPacketArrayInstance2[0x29]);*/
      break;
  }
}
