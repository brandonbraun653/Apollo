/**
 *   @file  icss_emacStatistics.h
 *
 *   @brief
 *      Include file for Statistics implementation, contains Statistics getter funnction declarations
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
 
#ifndef ICSS_EMAC_STATISTICS__H
#define ICSS_EMAC_STATISTICS__H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdlib.h>
#include <string.h>

#include "ti/drv/icss_emac/icss_emacLearning.h"
#include "ti/drv/icss_emac/icss_emacFwInit.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
* @brief Statistics structure for capturing statistics on PRU
*
*/
typedef struct {
/* The fields here are aligned here so that it's consistent 
  with the memory layout in PRU DRAM, this is to facilitate easy
  memcpy or DMA transfer. Don't change the order of fields without
  modifying the order of fields in PRU DRAM. For details refer to guide 
*/

    volatile uint32_t txBcast;                  /**Number of broadcast packets sent*/
    volatile uint32_t txMcast;                  /**Number of multicast packets sent*/
    volatile uint32_t txUcast;                  /**Number of unicast packets sent*/
    volatile uint32_t txOctets;                 /**Number of Tx packets*/

    volatile uint32_t rxBcast;                  /**Number of broadcast packets rcvd*/
    volatile uint32_t rxMcast;                  /**Number of multicast packets rcvd*/
    volatile uint32_t rxUcast;                  /**Number of unicast packets rcvd*/
    volatile uint32_t rxOctets;                 /**Number of Rx packets*/

    volatile uint32_t tx64byte;                 /**Number of 64 byte packets sent*/
    volatile uint32_t tx65_127byte;             /**Number of 65-127 byte packets sent*/
    volatile uint32_t tx128_255byte;            /**Number of 128-255 byte packets sent*/
    volatile uint32_t tx256_511byte;            /**Number of 256-511 byte packets sent*/
    volatile uint32_t tx512_1023byte;           /**Number of 512-1023 byte packets sent*/
    volatile uint32_t tx1024byte;               /**Number of 1024 and larger size packets sent*/


    volatile uint32_t rx64byte;                 /**Number of 64 byte packets rcvd*/
    volatile uint32_t rx65_127byte;             /**Number of 65-127 byte packets rcvd*/
    volatile uint32_t rx128_255byte;            /**Number of 128-255 byte packets rcvd*/
    volatile uint32_t rx256_511byte;            /**Number of 256-511 byte packets rcvd*/
    volatile uint32_t rx512_1023byte;           /**Number of 512-1023 byte packets rcvd*/
    volatile uint32_t rx1024byte;               /**Number of 1024 and larger size packets rcvd*/


    volatile uint32_t lateColl;                 /**Number of late collisions(Half Duplex)*/
    volatile uint32_t singleColl;               /**Number of single collisions (Half Duplex)*/
    volatile uint32_t multiColl;                /**Number of multiple collisions (Half Duplex)*/
    volatile uint32_t excessColl;               /**Number of excess collisions(Half Duplex)*//**Number of excess collisions(Half Duplex)*/

    volatile uint32_t rxMisAlignmentFrames;     /**Number of non multiple of 8 byte frames rcvd*/
    volatile uint32_t stormPrevCounter;         /**Number of packets dropped because of Storm Prevention (broadcast)*/
    volatile uint32_t stormPrevCounterMC;         /**Number of packets dropped because of Storm Prevention (multicast)*/
    volatile uint32_t stormPrevCounterUC;         /**Number of packets dropped because of Storm Prevention (unicast)*/
    volatile uint32_t macRxError;               /**Number of MAC receive errors*/

    volatile uint32_t SFDError;                  /**Number of invalid SFD*/
    volatile uint32_t defTx;                    /**Number of transmissions deferred*/
    volatile uint32_t macTxError;               /**Number of MAC transmit errors*/
    volatile uint32_t rxOverSizedFrames;        /**Number of oversized frames rcvd*/
    volatile uint32_t rxUnderSizedFrames;       /**Number of undersized frames rcvd*/
    volatile uint32_t rxCRCFrames;              /**Number of CRC error frames rcvd*/

    volatile uint32_t droppedPackets;           /**Number of packets dropped due to a link down on opposite port*/


/* Debug variables, these are not part of standard MIB. Useful for debugging */
/* Reserved for future Use */
    volatile uint32_t txOverFlow;               /**Tx FIFO overflow count*/
    volatile uint32_t txUnderFlow;              /**Tx FIFO underflow count*/
    volatile uint32_t sqeTestError;             /**Number of MAC receive errors*/
    volatile uint32_t TXqueueLevel;             /**Current Tx queue level*/
    volatile uint32_t CSError;                  /**Number of carrier sense errors*/
}ICSS_EmacPruStatistics_t;

#define pruStatistics_t ICSS_EmacPruStatistics_t

/**
* @brief Stats structure for statistics on Host (ARM)
*
*/
typedef struct {
    volatile uint32_t txUcast;          /**Number of unicast packets sent*/
    volatile uint32_t txBcast;          /**Number of broadcast packets sent*/
    volatile uint32_t txMcast;          /**Number of multicast packets sent*/
    volatile uint32_t txOctets;         /**Number of bytes sent*/
    volatile uint32_t rxUcast;          /**Number of unicast packets rcvd*/
    volatile uint32_t rxBcast;          /**Number of broadcast packets rcvd*/
    volatile uint32_t rxMcast;          /**Number of multicast packets rcvd*/
    volatile uint32_t rxOctets;         /**Number of Rx packets*/
    volatile uint32_t rxUnknownProtocol;    /**Number of packets with unknown protocol*/
	volatile uint32_t txDroppedPackets;	/**Number of packets with unknown protocol*/
    /*
    * Debug variables, these are not part of standard MIB. Useful for debugging
    */
    volatile uint32_t linkBreak;            /**Number of link breaks*/

}ICSS_EmacHostStatistics_t;


/* For backward compatibility */
#define hostStatistics_t ICSS_EmacHostStatistics_t



/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
* @brief   Read statistics from PRU DRAM Memory into structure
* @param portNum Port Number. 1/2
* @param icssEmacHandle EMAC Handle. Provides PRUSS memory map
*
* @retval none
*/
void ICSS_EmacReadStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle);

/**
* @brief   clear switch statistics
* @param portNum Port Number. 1/2
* @param icssEmacHandle EMAC Handle. Provides PRUSS memory map
*
* @retval none
*/
void PurgeStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle);


/**
* @brief   Do the stats initialization, call at the beginning of the frame
* @param portNum Port Number. 1/2
* @param icssEmacHandle EMAC Handle. Provides PRUSS memory map
*
* @retval none
*/
void InitStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle);

/**
* @brief   Call every time a packet is received, updates Rx related statistics
*
* @param macAddr pointer to mac address, stored in 8 bit locations
* @param packet_len packet length in bytes
* @param protIdent Protocol Type
* @param hostStatsPtr Pointer to Host statistics for the relevant port
*
* @retval none
*/
void ICSS_EmacUpdateRxStats(const uint8_t* macAddr,uint32_t packet_len,uint16_t protIdent, ICSS_EmacHostStatistics_t * hostStatsPtr);
/**
* @brief   Call every time a packet is transmitted, updates Tx related statistics
*
* @param macAddr pointer to mac address, stored in 8 bit locations
* @param packet_len packet length in bytes
* @param hostStatsPtr Pointer to Host statistics for the relevant port
*
* @retval none
*/
void ICSS_EmacUpdateTxStats(const uint8_t *macAddr,uint32_t packet_len, ICSS_EmacHostStatistics_t * hostStatsPtr);


#ifdef __cplusplus
}
#endif

#endif /*_ICSS_EMAC_STATISTICS_H_*/
