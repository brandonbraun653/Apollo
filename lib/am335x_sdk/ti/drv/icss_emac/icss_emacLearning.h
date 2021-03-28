/**
 *   @file  icss_emacLearning.h
 *
 *   @brief
 *      Include file for Learning/FDB implementation
 *
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



#ifndef ICSS_EMAC_LEARNING__H
#define ICSS_EMAC_LEARNING__H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdlib.h>

#include <stdint.h>
#include <string.h>
#include "ti/drv/icss_emac/icss_emacCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  @def  ICSS_EMAC_LEARNING_PORT_1
 *        Used to specify physical port 1 MII 0 (tx)
 */
#define ICSS_EMAC_LEARNING_PORT_1 1

/**
 *  @def  ICSS_EMAC_LEARNING_PORT_2
 *        Used to specify physical port 2 MII 1 (tx)
 */
#define ICSS_EMAC_LEARNING_PORT_2 2

/**
* @def NUMBUCKETS
*      Number of Buckets in the learning table(per port)
*/
#define NUMBUCKETS 256
/**
* @def MAX_NUM_ENTRIES
*      Number of entries per Bucket
*/
#define MAX_NUM_ENTRIES 4

/**
* @def AGEING_COUNT
*      used for ageing, higher value means entries age out slower, max value is 255
*/
#define AGEING_COUNT        (100U)
/**Compare MAC ID's. Uses memcmp internally */
#define COMPARE_MAC(x, y)   (memcmp((x), (y), 6U) == 0)
/**Copy MAC ID. Uses memcpy internally */
#define COPY_MAC(dst, src)  (memcpy((dst), (src), 6U))

/** Number of buckets in each port's learning table*/
#define tableSize 256

/**
* @brief Enum for different port states
*
*/
typedef enum {
    learning = 0,
    notLearning,
    locked

} portState;

/**
* @brief MAC ID
*
*/
typedef struct {
    /**MAC ID*/
    uint8_t macId[6];
} MAC;

/**
* @brief Structure for Individual bucket. A hash table is made up of several such buckets
*
*/
typedef struct {

    /**Four MAC Id per bucket*/
    MAC mac[MAX_NUM_ENTRIES];
    /**Timer count used for ageing and conflict resolution*/
    uint8_t timerCount[MAX_NUM_ENTRIES];
    /**Number of MAC entries in the bucket, 4 means it is full*/
    uint8_t numEntries;
} HashBucket_t;

/**Number of ports in an ICSS*/
#define NUM_PORTS        (2U)
/**
* @brief Structure for the Hash Table. To be declared as an array of two. One for each port
*
*/
typedef struct HashTable_s{

    uint32_t totalNumEntries;           /**Total number of entries in the hash table*/
    portState state;                    /**State of the hash table, see enum portState above*/
    HashBucket_t  entries[NUMBUCKETS];  /**Number of bucket entries*/
} HashTable_t;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
* @brief Update the learning table used to map MAC Id's and ports
*
* @param  macId MACID which is to be learned
* @param  portNum port number of incoming packet
* @param  tablePtr Hash Table pointer for the port for which table must be updated
* @param  exceptionCallBack Call back for protocol specific task
*
* @retval none
*/
void updateHashTable(uint8_t* macId, uint8_t portNum, HashTable_t *tablePtr,const ICSS_EmacCallBackConfig* exceptionCallBack);
/**
* @brief Clear the Learning table associated with a given port
*
* @param portNum Port number whose learning table is to be flushed
* @param  tablePtr Hash Table pointer for the port for which table is to be flushed
*
* @retval none
*/
void purgeTable(uint8_t portNum, HashTable_t *tablePtr);
/**
* @brief Remove old MAC entries from the table
*
* @param  portNum Portnumber whose learning table is to be flushed
* @param  tablePtr pointer to the hash table for corresponding portNum
*
* @retval none
*/
void ageingRoutine(uint8_t portNum, HashTable_t *tablePtr);

/**
* @brief This takes in a hash key and the port number and removes the MAC ID if found in the other port
*
* @retval none
*/
void incrementCounter(HashTable_t *tablePtr);

/**
* @brief Find given a MAC ID which port it exists
*
* @param  macId MAC ID which is to be found
*
* @retval tablePtr where the MAC ID exists, 0 means not found 1 means port 0 and 2 means port 1
*/
uint8_t findMAC(const uint8_t * macId, HashTable_t *tablePtr);
/**
* @brief Find given a MAC ID and remove it from the table
*
* @param  macId  MAC which is to be found
* @param  tablePtr Hash Table pointer for the port for which MAC ID (provided) to be removed
*
* @retval pass/fail. 0 means operation failed (mac not found)
*/
uint8_t removeMAC(const uint8_t * macId, HashTable_t *tablePtr);

/**
 * Name : hashFuncGPMAC_asm
 * The above function written in assembly
 */
uint8_t hashFuncGPMAC_asm(uint8_t* macId);

/**
* @brief This takes in a hash key and the port number and removes the MAC ID if found in the other port
*
* @retval none
*/
void initLearningTable(HashTable_t *tablePtr);

/*******************************************Port State Change Functions******************************/
/****************************************************************************************************/

/*Port State Change Functions*/

/**
* @brief Change the Port state. Supported values are Learning/Not Learning/Locked
*
* @param  state Port state which is an Enum type. See corresponding in include file
* @param  tablePtr Hash Table pointer for the port for which state must be changed
*
* @retval none
*/
void changePortState(portState state, HashTable_t *tablePtr);

/**
* @brief API to copy Macaddress
*
* @param dst destination address
 * @param src source address
*
* @retval none
*/
void copyMAC(uint8_t *dst, const uint8_t *src);


#ifdef __cplusplus
}
#endif

#endif /* _ICSS_EMAC_LEARNING_H_ */
