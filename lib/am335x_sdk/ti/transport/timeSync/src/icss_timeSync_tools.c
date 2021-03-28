/******************************************************************************
 * FILE NAME:   icss_timeSync_tools.c
 *
 * DESCRIPTION: Tools for debugging, generic API's and Profiling
 *
 * Contains functions for logging the state of events, API's for profiling.
 *
 * (C) Copyright 2018 Texas Instruments, Inc.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/transport/timeSync/include/icss_timeSync_tools.h>
#include <ti/drv/icss_emac/icss_emac_ver.h>
#include "string.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*TODO: USE NIMU DRV version instead of EMAC LLD*/
uint32_t calcChecksum(uint8_t *packet, uint16_t len)
{
    uint32_t sum = 0;  /* assume 32 bit long, 16 bit short */
    uint16_t shortVal;
    uint8_t byte1, byte2;

    while(len > 1)
    {
        byte1 = *(packet++);
        byte2 = *(packet++);

        shortVal = byte1;
        shortVal = (shortVal << 8 | byte2);

        sum += shortVal;

        if(sum & 0xffff0000)   /* if high order bit set, fold */
        {
            sum = (sum & 0xFFFF) + (sum >> 16);
        }

        len -= 2;
    }

    if(len)         /* take care of left over byte */
    {
        sum += (uint16_t) * (uint8_t *)packet;
    }

    while(sum >> 16)
    {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return ~sum;

}

void calcIPChecksum(uint8_t *packet)
{
    uint8_t *src;
    uint32_t checksum;

    /*Reset the checksum to zero to recalculate*/
    src = packet + START_OF_IP_CHECKSUM;
    *(src++) = 0;
    *(src) = 0;

    src = packet + START_OF_IP_HEADER;

    checksum = calcChecksum(src, DEFAULT_IP_HEADER_SIZE);

    src = packet + START_OF_IP_CHECKSUM;
    *(src++) = (checksum >> 8) & 0xff;
    *(src) = checksum & 0xff;

}

void calcUDPChecksum(uint8_t *packet)
{

    /*needed for udp checksum calculation*/
    uint8_t pseudoIPHeader[20];

    uint32_t checksum;
    uint8_t *src;

    src = packet + START_OF_UDP_CHECKSUM;
    *(src++) = 0;
    *(src++) = 0;

    src = packet + START_OF_IP_ADDRESS;
    memcpy(pseudoIPHeader, src, 8);

    src = packet + START_OF_IP_PROTOCOL;
    pseudoIPHeader[8] = 0;
    pseudoIPHeader[9] = *(src);

    src = packet + START_OF_UDP_LENGTH;
    pseudoIPHeader[10] = *(src++);
    pseudoIPHeader[11] = *(src++);


    src = packet + START_OF_UDP_HEADER;
    memcpy(&(pseudoIPHeader[12]), src, DEFAULT_UDP_HEADER_SIZE);

    checksum = calcChecksum(pseudoIPHeader, 18);

    src = packet + START_OF_UDP_CHECKSUM;
    *(src++) = (checksum >> 8) & 0xff;
    *(src++) = checksum & 0xff;

}

void addMACID(uint8_t *src, uint8_t *macID)
{
    *(src) = *(macID);
    *(src + 1) = *(macID + 1);
    *(src + 2) = *(macID + 2);
    *(src + 3) = *(macID + 3);
    *(src + 4) = *(macID + 4);
    *(src + 5) = *(macID + 5);
}

void addWord(uint8_t *src, uint32_t word)
{
    *(src) = (word >> 24) & 0xff;
    *(src + 1) = (word >> 16) & 0xff;
    *(src + 2) = (word >> 8) & 0xff;
    *(src + 3) = word & 0xff;
}

void addHalfWord(volatile uint8_t *src, uint16_t halfWord)
{
    *(src) = (halfWord >> 8) & 0xff;
    *(src + 1) = (halfWord) & 0xff;
}

void convEndianess(volatile void *src, volatile void *dst, uint8_t numBytes)
{
    uint8_t i;
    uint8_t *srcPtr = (uint8_t *)src;
    uint8_t *dstPtr = (uint8_t *)dst;

    /*If multiple of 2*/
    if((numBytes & 0x1) == 0)
    {
        dstPtr = dstPtr + numBytes - 1;

        for(i = 0; i < numBytes; i++)
        {
            *(dstPtr--) = *(srcPtr++);
        }
    }

}

void convEnd6to8(volatile void *src, void *dst)
{

    uint8_t *srcPtr = (uint8_t *)src;
    uint8_t *dstPtr = (uint8_t *)dst;

    dstPtr[0] = srcPtr[5];
    dstPtr[1] = srcPtr[4];
    dstPtr[2] = srcPtr[3];
    dstPtr[3] = srcPtr[2];
    dstPtr[4] = srcPtr[1];
    dstPtr[5] = srcPtr[0];

}

void getMACId(uint8_t *packet, uint8_t *macId)
{
    uint8_t *src;
    uint8_t i;
    src = packet;

    //conversion from big endian byte order to little endian byte order
    for(i = 0; i < 6; i++)
    {
        *(macId + i) = *(src++);
    }
}

uint32_t convBigEndianToLittleEndianWord(uint8_t *byte)
{
    uint8_t *src;
    uint32_t word = 0;
    src = byte;

    /*conversion from big endian byte order to little endian byte order*/
    word |= *(src++);
    word <<= 8;
    word |= *(src++);
    word <<= 8;
    word |= *(src++);
    word <<= 8;
    word |= *(src++);

    return word;
}

uint16_t convBigEndianToLittleEndianHalfWord(uint8_t *byte)
{
    uint8_t *src;
    uint32_t halfWord = 0;
    src = byte;

    //conversion from big endian byte order to little endian byte order
    halfWord |= *(src++);
    halfWord <<= 8;
    halfWord |= *(src++);

    return halfWord;
}
/* Nothing past this point */
