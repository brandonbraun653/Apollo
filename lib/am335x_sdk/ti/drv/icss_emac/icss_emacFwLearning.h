/**
 *   @file  icss_emacFwLearning.h
 *
 *   @brief
 *      Include file for firmware-based Learning/FDB implementation
 *
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



#ifndef ICSS_EMAC_FW_LEARNING__H
#define ICSS_EMAC_FW_LEARNING__H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "ti/drv/icss_emac/icss_emacCommon.h"
#include "ti/drv/icss_emac/icss_emacLearning.h"
#include <ti/drv/icss_emac/firmware/icss_switch/src/icss_stp_switch.h>

#define FDB__TOTAL_NUM_PORTS (2)
#define FDB__INDEX_TBL__MAX_ENTRIES (256)
#define FDB__MAC_TBL__MAX_ENTRIES (256)

#define FDB__ERROR__FDB_FULL      (-2)
#define FDB__ERROR__FDB_EMPTY     (-3)
#define FDB__ERROR__MAC_NOT_FOUND (-4)


/**
 * FdbMacInfo - FDB MAC Info
 * All relevant information related to a particular MAC address.
 */
typedef struct __attribute__((packed))
{ 
  MAC mac;               /* MAC Address */
  uint16_t age;          /* Age of MAC entry in table */  
  uint8_t  portNo;       /* Flag to indicate MAC address is associated with Port 1 (=0) or Port 2 (=1) */
  uint8_t  isStatic : 1; /* Flag to indicate whether address added statically or dynamically */
  uint8_t  active   : 1; /* Flag to indicate whether this entry is currently active in the table */
} FdbMacInfo;

/**
 * FdbMacTable - FDB MAC Table
 * This table contains the actual MAC information managed by the FDB Index Table.
 */
typedef struct FdbMacTable_s {
  FdbMacInfo entries[FDB__MAC_TBL__MAX_ENTRIES]; /* Array of MAC Info entries */
} FdbMacTable;

/**
 * FdbIndexTableEntry - FDB Index Table Entry
 * Each entry points to a bucket of learned MAC addresses in the FDB Table.
 * Upon collision, the buckets will dynamically re-size to accommodate the new address.
 * These entries are fully in charge of bucket geometry, thus bucket size is also tracked here.
 */
typedef struct FdbIndexTableEntry_s {
  uint16_t bucketIndex;      /* Bucket Table index of first Bucket with this MAC address */
  uint16_t numBucketEntries; /* Number of entries in this bucket */
} FdbIndexTableEntry;


/**
 * FdbIndexTable - FDB Index Table
 * Hashable FDB table, contains entries that point to buckets of learned MAC addresses.
 */
typedef struct FdbIndexTable_s {
  FdbIndexTableEntry entries[FDB__INDEX_TBL__MAX_ENTRIES]; /* Array of Index Table entries (256 entries) */  
} FdbIndexTable;

typedef struct FdbArbitration_s {
  uint8_t hostLock;
  volatile uint8_t pruLocks;
} FdbArbitration;

typedef struct FdbFloodCfg_s
{
  uint8_t hostPortFloodEn : 1;
  uint8_t port1FloodEn    : 1;
  uint8_t port2FloodEn    : 1;
} FdbFloodCfg;

typedef struct FdbStpCfg_s {
  uint8_t state; /* per-port STP state (defined in FW header) */
} FdbStpCfg;

/**
 * Fdb - Forwarding Data Base
 * Stores learned MAC addresses in a linearly expandable hash table represented
 * as an Index Table and a MAC Table (see implementations for details) for RSTP.
 * Tracks the RSTP state. All elements are pointers in case they need to be
 * broken up in memory.
 */
typedef struct Fdb_s {
  FdbIndexTable * indexTbl;           /* FDB Index Table */
  FdbMacTable * macTbl;               /* FDB MAC Table */
  FdbStpCfg *port1StpCfg;             /* Port 1 STP configuration */
  FdbStpCfg *port2StpCfg;             /* Port 2 STP configuration */
  FdbFloodCfg *floodEnableFlags;      /* Per-port flood enable flags */
  FdbArbitration *locks;              /* FDB Locking Mechanisms */
  uint16_t  totalNumEntries;          /* Total number of entries in the hash table */
} Fdb;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


int16_t fdbSearch(FdbMacTable *macTbl, FdbIndexTableEntry *bucketInfo, MAC mac);
int32_t fdbInsert(Fdb *fdb, MAC mac, uint8_t portNo, bool staticEntry);
int32_t fdbDelete(Fdb *fdb, MAC mac);
void fdbPurge(Fdb *fdb);
void fdbInit(Fdb *fdb, uint32_t fdb_base_addr);
void fdbUpdateStpState(Fdb *fdb, uint8_t portNo, uint8_t state);
void fdbIncrementAgeingCounter(Fdb *fdb);
void fdbAgeingRoutine(Fdb *fdb);

#endif /* _ICSS_EMAC_FW_LEARNING_H_ */
