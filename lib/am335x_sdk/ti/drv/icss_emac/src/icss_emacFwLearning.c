/**
* @file icss_emacFwLearning.c
*
* @brief Main file for firmware-based Learning/FDB implementation
*        Contains hash functions and other routines used to implement a Learning/FDB implementation
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/drv/icss_emac/icss_emacCommon.h>
#include <ti/drv/icss_emac/icss_emacFwLearning.h>
#include <ti/osal/osal.h>

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                      Local Function Declarations                           */
/* ========================================================================== */
static uint8_t fdbHash(MAC mac);
static void fdb_memcpy(uint8_t *dst, uint8_t *src, uint32_t sz);
static int8_t macCmp(uint8_t *macIdA, uint8_t *macIdB);
static void fdbUpdateIndexTbl(Fdb *fdb, uint16_t left, uint16_t right);
static void fdbMoveRangeRight(Fdb *fdb, uint16_t left, uint16_t right);
static void fdbMoveRangeLeft(Fdb *fdb, uint16_t left, uint16_t right);
static uint16_t fdbFindOpenSlot(FdbMacTable *macTbl);
static int16_t fdbFindBucketInsertionPoint(FdbMacTable *macTbl, FdbIndexTableEntry *bucketInfo, MAC mac);
static int16_t fdbCheckEmptySlotLeftwards(FdbMacTable *macTbl, uint8_t macTblIdx);
static int16_t fdbCheckEmptySlotRightwards(FdbMacTable *macTbl, uint8_t macTblIdx);
static void fdbSpinLock(Fdb *fdb);
static void fdbSpinUnlock(Fdb *fdb);

/* ========================================================================== */
/*                       Global Function Definitions                          */
/* ========================================================================== */

int16_t fdbSearch(FdbMacTable *macTbl, FdbIndexTableEntry *bucketInfo, MAC mac) {
  int32_t i;
  uint8_t macTblIdx;
  bool found = false;
  int16_t retVal = 0;

  macTblIdx = bucketInfo->bucketIndex;
  
  for (i = 0; i < bucketInfo->numBucketEntries; i++, macTblIdx++) {
    /* Search until MAC address found in bucket */
    if(macCmp(mac.macId, macTbl->entries[macTblIdx].mac.macId) == 0) {
      found = true;
      break;
    }    
  }

  if (found == false) {
    retVal = -1;
  } else {
    retVal = macTblIdx;
  }
  
  return retVal;
}

int32_t fdbInsert(Fdb *fdb, MAC mac, uint8_t portNo, bool staticEntry) {
  FdbIndexTableEntry *bucketInfo;
  FdbMacInfo *macInfo;
  uint8_t hashVal, macTblIdx;  
  int16_t emptySlotIdx = 0, left = 0, right = 0;
  int32_t retVal = 0;  
  bool updateIndexes = false;

  /**
   * If the FDB is full, don't insert
   */
  if (fdb->totalNumEntries == FDB__MAC_TBL__MAX_ENTRIES) {
    retVal = FDB__ERROR__FDB_FULL;
    goto END;
  }
  
  /**
   * Find proper bucket
   */
  hashVal = fdbHash(mac);    
  bucketInfo = &fdb->indexTbl->entries[hashVal];

  /**
   * Set up bucket if empty
   */
  if(bucketInfo->numBucketEntries == 0)  {
    macTblIdx = fdbFindOpenSlot(fdb->macTbl);
    bucketInfo->bucketIndex = macTblIdx;
  }

  /**
   * Find the proper MAC table insertion point
   */
  retVal = fdbFindBucketInsertionPoint(fdb->macTbl,bucketInfo, mac);
  if (retVal < 0) {
    /* MAC already in table */
    retVal = 0;
    goto END;
  }
  macTblIdx = retVal;

  /* Lock FDB */
  fdbSpinLock(fdb);

  /**
   * Shift MAC table entries if needed
   */
  if (0 == fdb->macTbl->entries[macTblIdx].active) {
    /* Current slot is empty, thus it is valid to enter new MAC */
    macInfo = &fdb->macTbl->entries[macTblIdx];
  } 
  else {
    /**
     * There current slot is not empty. Check if there is an empty slot to the left
     * of the insertion point.
     */
    emptySlotIdx = fdbCheckEmptySlotLeftwards(fdb->macTbl, macTblIdx);
    
    if (emptySlotIdx == -1) {
      /* Table isn't full so there must be space to the right, shift MAC table entries right. */
      emptySlotIdx = fdbCheckEmptySlotRightwards(fdb->macTbl, macTblIdx); /* Should never return -1 */
      
      /* Shift right */
      left = macTblIdx;
      right = emptySlotIdx;
      fdbMoveRangeRight(fdb, macTblIdx, emptySlotIdx);      

      /* There is a chance we moved something in a different bucket, update index table */
      updateIndexes = true;
      
      /* Update current MAC Table entry */
      macInfo = &fdb->macTbl->entries[macTblIdx];            
    }
    else if (emptySlotIdx == (macTblIdx - 1)) {
      /* There is space immediately left of the open slot, which means the inserted MAC address */
      /* must be the lowest-valued MAC address in bucket. Update bucket pointer accordingly */
      bucketInfo->bucketIndex = emptySlotIdx;
      
      /* Update current MAC Table entry */
      macInfo = &fdb->macTbl->entries[emptySlotIdx];
    }    
    else {
      /* There is empty space to the left, shift MAC table entries left */
      left = emptySlotIdx;
      right = macTblIdx - 1;
      fdbMoveRangeLeft(fdb, left, right);      

      /* There is a chance we moved something in a different bucket, update index table */
      updateIndexes = true;
      
      /* Update current MAC Table entry */
      macInfo = &fdb->macTbl->entries[right];      
    } 
  }


  /**
   * Insert the MAC into the MAC table
   */
  copyMAC((macInfo->mac.macId), mac.macId);
  macInfo->active = 1;
  macInfo->age = 0;
  macInfo->portNo = portNo - 1; /* The FDB only supports 2 ports at the moment, associate ports 1/2 with 0/1 */
  macInfo->isStatic = staticEntry;
  
  /**
   * Update Index Table to reflect any changes. Should be done after insertion
   */
  if(updateIndexes) {
    fdbUpdateIndexTbl(fdb, left, right);
  }

  /**
   * Finish up book-keeping
   */
  bucketInfo->numBucketEntries++;
  fdb->totalNumEntries++;

  /* Unlock FDB */
  fdbSpinUnlock(fdb);

END:
  return retVal;  
}

int32_t fdbDelete(Fdb *fdb, MAC mac) {
  FdbIndexTableEntry *bucketInfo;
  FdbMacInfo *macInfo;
  uint8_t hashVal, macTblIdx;  
  int16_t left = 0, right = 0;
  int32_t retVal = 0;  
  
  /**
   * If the FDB is empty, don't delete
   */
  if (fdb->totalNumEntries == 0) {
    retVal = FDB__ERROR__FDB_EMPTY;
    goto END;
  }
  
  /**
   * Find proper bucket
   */
  hashVal = fdbHash(mac);    
  bucketInfo = &fdb->indexTbl->entries[hashVal];

  /**
   * Find MAC location in FDB
   */
  retVal = fdbSearch(fdb->macTbl, bucketInfo, mac);
  if (retVal < 0) {
    retVal = FDB__ERROR__MAC_NOT_FOUND;
    goto END;
  }
  macTblIdx = retVal;
  macInfo = &fdb->macTbl->entries[macTblIdx];

  /* Lock FDB */
  fdbSpinLock(fdb);

  /**
   * Shift all elements in bucket to the left
   */
  left = macTblIdx;
  right = bucketInfo->bucketIndex + bucketInfo->numBucketEntries - 1;
  fdbMoveRangeLeft(fdb, left, right); /* no need to update index table */
                                      /* .. only shifting within bucket */

  /**
   * Remove end of bucket from table
   */  
  macInfo = &fdb->macTbl->entries[right];
  macInfo->active = 0;
  bucketInfo->numBucketEntries--;
  fdb->totalNumEntries--;

  /* Unlock FDB */
  fdbSpinUnlock(fdb);

END:
  return retVal; 
}

void fdbPurge(Fdb *fdb) {
  /* FDB "empty" when all buckets are size zero and all MAC entries are marked as inactive */
  uint16_t i;

  /* LOCK */
  fdbSpinLock(fdb);

  for (i = 0; i < FDB__INDEX_TBL__MAX_ENTRIES; i++) {
    fdb->indexTbl->entries[i].numBucketEntries = 0;
  }

  for (i = 0; i < FDB__MAC_TBL__MAX_ENTRIES; i++) {
    fdb->macTbl->entries[i].active = 0;
  }

  fdb->totalNumEntries = 0;

  /* UNLOCK */
  fdbSpinUnlock(fdb);
}

void fdbInit(Fdb *fdb, uint32_t fdb_base_addr) {  
  fdb->indexTbl = (FdbIndexTable*) fdb_base_addr;
  fdb->macTbl = (FdbMacTable*) (fdb_base_addr + sizeof(FdbIndexTable));
  fdb->port1StpCfg = (FdbStpCfg*) (fdb_base_addr + sizeof(FdbIndexTable) + sizeof(FdbMacTable));
  fdb->port2StpCfg = (FdbStpCfg*) (fdb_base_addr + sizeof(FdbIndexTable) + sizeof(FdbMacTable)
				   + sizeof(FdbStpCfg));
  fdb->floodEnableFlags = (FdbFloodCfg*) (fdb_base_addr + sizeof(FdbIndexTable) + sizeof(FdbMacTable)
					  + 2*sizeof(FdbStpCfg));  
  fdb->locks = (FdbArbitration*) (fdb_base_addr + sizeof(FdbIndexTable) + sizeof(FdbMacTable)
				  + 2*sizeof(FdbStpCfg) + sizeof(FdbFloodCfg));
  fdb->totalNumEntries = 0;  

  fdb->locks->hostLock = 0x0;

  fdb->floodEnableFlags->hostPortFloodEn = 1U;
  fdb->floodEnableFlags->port1FloodEn = 1U;
  fdb->floodEnableFlags->port2FloodEn = 1U;
}

void fdbUpdateStpState(Fdb *fdb, uint8_t portNo, uint8_t state) {
  /* The firmware supports STP, but the intended application use case is with RSTP */
  /* .. which overloads existing STP states */

  if (portNo == 1) {
    fdb->port1StpCfg->state = state;
  }
  else if (portNo == 2) {
    fdb->port2StpCfg->state = state;
  }
  else {
    /* Invalid state, do nothing */
  }
}

void fdbIncrementAgeingCounter(Fdb *fdb) {
  uint16_t i;
  FdbMacInfo *entry;

  for (i = 0; i < FDB__MAC_TBL__MAX_ENTRIES; i++) {
    entry = &fdb->macTbl->entries[i];
    if (entry->active) {
      fdbSpinLock(fdb);
      entry->age++;
      fdbSpinUnlock(fdb);
    }
  }
}

void fdbAgeingRoutine(Fdb *fdb) {
  /* NOT CURRENTLY IMPLEMENTED */
}

/* ========================================================================== */
/*                       Local Function Definitions                           */
/* ========================================================================== */

static uint8_t fdbHash(MAC mac) {
  return mac.macId[0] ^ mac.macId[1] ^ mac.macId[2] ^ mac.macId[3] ^ mac.macId[4] ^ mac.macId[5];
}

static void fdb_memcpy(uint8_t *dst, uint8_t *src, uint32_t sz) {
  uint16_t j;
  
  for(j = 0; j < sz; j++) {
        *(dst) = *(src);
        dst++;
        src++;
    }
}

/* -1  MAC_A < MAC_B
    0  MAC_A == MAC_B
    1  MAC_A > MAC_B
 */
static int8_t macCmp(uint8_t *macIdA, uint8_t *macIdB) {
  int8_t retVal = 0;
  uint32_t i = 0;

  for (i = 0; i < 6; i++) {
    /* Current byte is equal, skip to the next*/
    if (macIdA[i] == macIdB[i]) {
      continue;
    }
    
    /* macA is decidedly different than macB */
    retVal = macIdA[i] < macIdB[i] ? -1 : 1;
    break;
  }

  return retVal;
}

static void fdbUpdateIndexTbl(Fdb *fdb, uint16_t left, uint16_t right) {
  uint16_t i;
  uint8_t hash, hash_prev;
  
  /* To ensure we don't improperly update the bucket index */
  hash_prev = 0xff; /* Initialize with an invalid hash in case we are in leftmost slot */
  if (left > 0) {
    hash_prev = fdbHash(fdb->macTbl->entries[left - 1].mac);
  }

  /* For each moved element, update the bucket index */
  for (i = left; i <= right; i++) {
    hash = fdbHash(fdb->macTbl->entries[i].mac);
    
    /* Only need to update buckets once */
    if (hash != hash_prev) {
      fdb->indexTbl->entries[hash].bucketIndex = i;
    }
        
    hash_prev = hash;
  }
}

/* Because up/down can be ambiguous, using left/right as if reading a number-line  */
static void fdbMoveRangeRight(Fdb *fdb, uint16_t left, uint16_t right) {
  uint16_t i;
  uint8_t *src, *dst;
  uint32_t sz = 0;

  /**
   * 
   */
  for(i = right; i > left; i--) {
    dst = (uint8_t *)&fdb->macTbl->entries[i];
    src = (uint8_t *)&fdb->macTbl->entries[i - 1];
    sz = sizeof(FdbMacInfo);
    fdb_memcpy(dst, src, sz);
  }
}

/* Because up/down can be ambiguous, using left/right as if reading a number-line  */
static void fdbMoveRangeLeft(Fdb *fdb, uint16_t left, uint16_t right) {
  uint16_t i;
  uint8_t *src, *dst;
  uint32_t sz = 0;
  
  /**
   * 
   */
  for(i = left; i < right; i++) {
    dst = (uint8_t *)&fdb->macTbl->entries[i];
    src = (uint8_t *)&fdb->macTbl->entries[i + 1];
    sz = sizeof(FdbMacInfo);
    fdb_memcpy(dst, src, sz);
  }
}

static uint16_t fdbFindOpenSlot(FdbMacTable *macTbl) {
  uint16_t macTblIdx;

  for (macTblIdx = 0; macTblIdx < FDB__MAC_TBL__MAX_ENTRIES; macTblIdx++) {
    if (0 == macTbl->entries[macTblIdx].active) {
      break;
    }
  }

  return macTblIdx;
}

static int16_t fdbFindBucketInsertionPoint(FdbMacTable *macTbl,
					   FdbIndexTableEntry *bucketInfo,
					   MAC mac) {
  int32_t i;
  uint8_t macTblIdx;
  int16_t retVal = 0;
  int8_t cmp;

  macTblIdx = bucketInfo->bucketIndex;
  
  for (i = 0; i < bucketInfo->numBucketEntries; i++, macTblIdx++) {
    /* Search until find a MAC address larger than that being added */    
    cmp = macCmp(mac.macId, macTbl->entries[macTblIdx].mac.macId);    
    if(cmp < 0) {
      break;
    } else if (cmp == 0) {
      retVal = -1;
      goto ERROR;
    }
  }

  retVal = macTblIdx;

ERROR:
  return retVal;
}

static int16_t fdbCheckEmptySlotLeftwards(FdbMacTable *macTbl, uint8_t macTblIdx) {
  int16_t i;

  /**
   * Check all entries to the left of selected index and return index of open slot.
   * Return -1 if no open slot found.
   */  
  for (i = macTblIdx - 1; i > -1; i--) {
    if(macTbl->entries[i].active == 0) {
      break;
    }
  }
  
  return i;
}

static int16_t fdbCheckEmptySlotRightwards(FdbMacTable *macTbl, uint8_t macTblIdx) {
  int16_t i;

  /**
   * Check all entries to the right of selected index and return index of open slot.
   * Return -1 if not found.
   */
  for (i = macTblIdx; i < FDB__MAC_TBL__MAX_ENTRIES; i++) {
    if(macTbl->entries[i].active == 0) {
      break;
    }
  }

  /* If there are no slots to the right, return -1 */
  if (i == FDB__MAC_TBL__MAX_ENTRIES) {
    i = -1;
  }
      
  return i;
}

static void fdbSpinLock(Fdb *fdb) {
  
  /* Take the lock */
  fdb->locks->hostLock = 1;
  
  /* Wait for the PRUs to release their locks */
  while (0 != fdb->locks->pruLocks) {
#ifdef __LINUX_USER_SPACE
    linux_sleep_ns(10000);
#else
    Osal_delay(10);
#endif
  }
}

static void fdbSpinUnlock(Fdb *fdb) {
  /* Release the lock */
  fdb->locks->hostLock = 0;
}
