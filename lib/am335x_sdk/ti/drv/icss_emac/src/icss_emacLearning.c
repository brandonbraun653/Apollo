/**
* @file icss_emacLearning.c
*
* @brief Main file for Learning/FDB implementation
*        Contains hash functions and other routines used to implement a Learning/FDB implementation
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/drv/icss_emac/icss_emacLearning.h>

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static uint8_t hashFuncGPMAC(const uint8_t* macId);

static uint8_t checkDuplicateMAC(uint8_t key, const uint8_t* macId, uint8_t portNum, HashTable_t *tablePtr);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static uint8_t hashFuncGPMAC(const uint8_t* macId) {
    uint8_t key;
    /*get the key*/
    key = macId[0] ^ macId[1] ^ macId[2] ^ macId[3] ^ macId[4] ^ macId[5];
    return key;
}

void updateHashTable(uint8_t* macId, uint8_t portNum, HashTable_t *tablePtr,const ICSS_EmacCallBackConfig* exceptionCallBack) {
    uint8_t key = 0;
    uint8_t i, oldestTimestamp, index = 0, macFound;
    HashBucket_t * bucket;
    HashTable_t *table;
    ICSS_EmacCallBack protException;
    void * protExceptionuser = exceptionCallBack->userArg;
    protException = exceptionCallBack->callBack;

    if((tablePtr == NULL) || (macId == NULL)) {
        return;
    }

    if((macId[0] & 0x01U) > 0U) { /* MAC reversed - lowest bit indicates MC  */
        return;
    }

    table = tablePtr + portNum - 1U;

    /* don't do anything for wrong port num  */
    if(portNum > (uint8_t)ICSS_EMAC_LEARNING_PORT_2) {
        return;
    }

    /*Call back for Protocol specific adaption*/
    if(protException != NULL) {
        if(protException(macId, protExceptionuser) == 0U) {
            return;
        }
    }

    /*get the key*/
    key = hashFuncGPMAC(macId);

    if((table->state == locked) || (table->state == notLearning)){
        return; /*not allowed to make any changes in cases table is locked or if learning is disabled  */
    }

    /*go to first hash entry in the table*/
    bucket = &(table->entries[key]);
    macFound = 0; /*set to false*/

    /*If bucket is empty update the first entry else run through the bucket*/
    if (bucket->numEntries == 0) {
        /* make sure the SLT has no entry for this MAC on the other port  */
        checkDuplicateMAC(key, macId, portNum, tablePtr);

        /* add entry  */
        copyMAC((bucket->mac[0].macId), macId);

        bucket->timerCount[0] = 0;
        bucket->numEntries++;
        table->totalNumEntries++;



    } else {
        oldestTimestamp = bucket->timerCount[0];

        for(i = 0; i < bucket->numEntries; i++) {
            /*Update all timer counts, for ageing*/
            if (COMPARE_MAC(macId, bucket->mac[i].macId)) {
                bucket->timerCount[i] = 0;
                macFound = 1u;

                /*early exit  */
                break;
            }

            /*if multiple MAC ID's hash to the same bucket, timer count is used to resolve the conflict*/
            if (oldestTimestamp <=  bucket->timerCount[i]) {
                oldestTimestamp = bucket->timerCount[i];
                index = i;
            }

        }
        if (macFound == 0U) 
        {
            /* make sure the SLT has no entry for this MAC on the other port  */
            checkDuplicateMAC(key, macId, portNum, tablePtr);

            if(bucket->numEntries == MAX_NUM_ENTRIES) 
            {
                /*replace an existing entry(the least hit)*/
                copyMAC(bucket->mac[index].macId, macId);


                bucket->timerCount[index] = 0;
            }
            else
            {
                if (bucket->numEntries < MAX_NUM_ENTRIES)
                {
                    copyMAC(bucket->mac[bucket->numEntries].macId, macId);

                    bucket->timerCount[bucket->numEntries] = 0;
                    bucket->numEntries++;
                    table->totalNumEntries++;
                }
            }

        }
    }



}

void purgeTable(uint8_t portNum, HashTable_t *tablePtr) {
    int32_t i;
    /*don't do anything for wrong port num*/
    if(portNum <= (uint8_t)ICSS_EMAC_LEARNING_PORT_2)
    { 
        HashTable_t *table;
        table = tablePtr;

         /*not allowed to make any changes in cases table is locked  */
        if(table->state != locked) 
        {
            /*make total entries to 0*/
            table->totalNumEntries = 0;
            /*Do a dirty deletion*/
            for(i=0; i<NUMBUCKETS;i++) {
                table->entries[i].numEntries = 0;
            }
        }
    }
    return;
}

void ageingRoutine(uint8_t portNum, HashTable_t *tablePtr) {

    int32_t i, a, j = 0;
    int32_t size, numEntriesRemoved;

    /*structure definitions, see header file*/
    HashTable_t *table;
    HashBucket_t * bucket;
    /*Right now this is hardcoded, modified only at compile time, can be added as an option later*/
    uint8_t ageingTime = AGEING_COUNT;

    /* don't do anything for wrong port num  */
    if(portNum <= (uint8_t)ICSS_EMAC_LEARNING_PORT_2)
    {
        /*get the table for the corresponding port*/
        table  = tablePtr;

        if(table->state != locked) 
        {
            for(i=0; i < NUMBUCKETS; i++) 
            {
            bucket = &(table->entries[i]);
            size = bucket->numEntries;
            numEntriesRemoved = size;
            a = 0;
            while(a < size) {
                if(ageingTime <= bucket->timerCount[a])
                {
                    j = a;
                    /*as we find hits, we decrement the size of the bucket*/
                    size--;
                    while(j < size) {
                        /*copy the data from below once a hole is created in the bucket due to retiring an entry*/
                        bucket->timerCount[j] = bucket->timerCount[j+1];
                        copyMAC(bucket->mac[j].macId, bucket->mac[j+1].macId);
                        j++;
                    }
                } else {
                    a++;
                }
            }
            /*Number of entries left*/
            bucket->numEntries = size;
            numEntriesRemoved -= size;

            /*Update the total number of entries removed  */
            table->totalNumEntries -= numEntriesRemoved;
            }
        }
    }
    return;
}

uint8_t findMAC(const uint8_t * macId, HashTable_t *tablePtr) {

    uint8_t j;
    uint8_t key;
    uint8_t macFound[NUM_PORTS] = {0};
    uint8_t numPorts = 0;
    HashTable_t *table;
    HashBucket_t * bucket;

    uint8_t ret_val = 0U;


    /*get the key to lookup in the hash table*/
    key = hashFuncGPMAC(macId);

    /*Look in all port entries, break if found*/
    for(numPorts = 0; numPorts < NUM_PORTS; numPorts++){
        table = tablePtr + numPorts;
        bucket = &(table->entries[key]);
        for (j = 0; j < bucket->numEntries; j++ ) {
            if (COMPARE_MAC(bucket->mac[j].macId, macId)) {
                /*set the flag and exit*/
                macFound[numPorts] = (uint8_t)1U;
                break;
            }

        }

    }
    /*since a return val of 0 means MAC Id not found 1 is added to distinguish port 0 from mac id not found,
     user to subtract 1 to get port number*/
    /*If MAC ID moves from port 1 to port 2, both ports will return false*/

    for(numPorts = 0; numPorts < NUM_PORTS; numPorts++) 
    {
        if(macFound[numPorts]) 
        {
            ret_val = numPorts + 1U;
            break;
        }
    }

    return ret_val;
}

uint8_t removeMAC(const uint8_t * macId, HashTable_t *tablePtr) {
    uint8_t j = 0;
    uint8_t key = 0;
    uint8_t macFound[NUM_PORTS] = {0};
    uint8_t macIndex[NUM_PORTS] = {0};
    uint8_t numPorts = 0;
    HashTable_t *table;
    HashBucket_t * bucket;
    key = hashFuncGPMAC(macId);

    uint8_t ret_val = 0U;


    /*Look in all port entries, exit if true*/
    for(numPorts = 0; numPorts < NUM_PORTS; numPorts++){
        table = tablePtr + numPorts;
        if(table->state != locked) 
        {
            bucket = &(table->entries[key]);
            for (j = 0; j < bucket->numEntries; j++ ) 
            {
                if (COMPARE_MAC(bucket->mac[j].macId, macId)) 
                {
                    macFound[numPorts] = (uint8_t)1U;
                    macIndex[numPorts] = j;
                    break;
                }
            }
        }
    }

    for(numPorts = 0; numPorts < NUM_PORTS; numPorts++){

        if(macFound[numPorts]) {
                /*Remove for PORT 0*/
                table = tablePtr + numPorts;
                bucket = &(table->entries[key]);

                for(j = macIndex[numPorts]; j < (bucket->numEntries - ((uint8_t)1U)); j++) {
                    bucket->timerCount[j] = bucket->timerCount[j+1U];
                    copyMAC(bucket->mac[j].macId, bucket->mac[j+1U].macId);
                }
                bucket->numEntries--;
                table->totalNumEntries--;
                ret_val = 1U;
                break;
            }
    }

    return ret_val;

}

static uint8_t checkDuplicateMAC(uint8_t key, const uint8_t* macId, uint8_t portNum, HashTable_t *tablePtr) {

    HashBucket_t * bucket;
    HashTable_t *table;
    uint8_t i, j, macFound = 0;
    uint8_t port = 0;

    uint8_t ret_val = 0U;


    /*don't do anything for wrong port num*/
    if(portNum <= (uint8_t)ICSS_EMAC_LEARNING_PORT_2) 
    {
        /*Look in all other port tables for duplicates*/
        for(port = 0; port < NUM_PORTS; port++) 
        {
            /*Skip the current port, look in other ports*/
            if((portNum-1U) != port) 
            {
                table = tablePtr + port;
                bucket = &(table->entries[key]);

                for (j = 0; j < bucket->numEntries; j++ ) 
                {
                    if (COMPARE_MAC(bucket->mac[j].macId, macId)) 
                    {
                        macFound = 1U;
                        for(i = j; i < (bucket->numEntries - ((uint8_t)1U)); i++) 
                        {
                            bucket->timerCount[i] = bucket->timerCount[i+1U];
                            copyMAC(bucket->mac[i].macId, bucket->mac[i+1U].macId);
                        }
                        bucket->numEntries--;
                        table->totalNumEntries--;
                        break;
                    }
            
                }
                /*MAC Found, no need to look in other ports*/
                if(macFound == 1U) {
                    break;
                }
            }
        }
        ret_val = macFound;
    }
    return ret_val;
}

void incrementCounter(HashTable_t *tablePtr) {
    int32_t i,j;
    HashTable_t *table;
    HashBucket_t * bucket;
    uint8_t port;

    /*Do for All ports*/
    for(port = 0; port < NUM_PORTS; port++) {
        table = tablePtr + port;
        if(table->state == locked) {
            break; /*not allowed to make any changes in cases table is locked  */
        }
        for(i=0; i<NUMBUCKETS;i++) {
            bucket = &(table->entries[i]);
            for(j=0; j < bucket->numEntries; j++) {
                if(bucket->timerCount[j] <= AGEING_COUNT) {
                    bucket->timerCount[j]++;
                }
            }
        }

    }
    return;
}

void initLearningTable(HashTable_t *tablePtr) {
    HashTable_t *table;
    uint8_t ports = 0;

    /*Initialize all ports*/
    for(ports = 0; ports < NUM_PORTS; ports++) {
        table = tablePtr + ports;
        purgeTable(ports, table);
        table->state = learning;
    }
}

void changePortState(portState state, HashTable_t *tablePtr) {

    tablePtr->state = state;

}

void copyMAC(uint8_t *dst, const uint8_t *src) {
    uint8_t i;
    for(i = 0; i < 6U; i++) {
        *(dst) = *(src);
        dst++;
        src++;
    }
}
