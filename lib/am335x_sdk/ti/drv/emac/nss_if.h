#ifndef _NSS_IF_H
#define _NSS_IF_H
/**
 *   @file  nss_if.h
 *
 *   @brief   
 *      This file defines Network Sub-System (NSS) transport layer related constants, and macros where
 *      NSS consists of CPSW, PASS and SASS. The definitions here are not used by PA LLD itself. Instead,
 *      they are used by the application module which invokes NSS including all PA unit tests and examples.
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2014 Texas Instruments, Inc.
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

#ifdef __cplusplus
extern "C" {
#endif


/** @defgroup nss_if_module NSS Interface
 *  @{
 */
/** @} */


/** @defgroup nss_if_constants NSS Constants (enum's and define's)
 *  @ingroup nss_if_module
 */

/**
 *  @defgroup nssPktDmaGen1 NSS PKTDMA definitions for First Generation NSS
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS PKTDMA definitions for First Generation NSS
 *
 *  Define NSS PKTDMA related constants for first generation NSS
 */
/*@{*/

#define NSS_NUM_RX_PKTDMA_CHANNELS_GEN1       24    /**< Number of PKTDMA Receive channels at first generation NSS */ 
#define NSS_NUM_TX_PKTDMA_CHANNELS_GEN1        9    /**< Number of PKTDMA Transmit channels at first generation NSS */

/*@}*/ /* nssPktDmaGen1 */
/** @}*/ /* NSS PKTDMA definitions for First Generation NSS */


/**
 *  @defgroup nssPktDmaGen2 NSS PKTDMA definitions for Second Generation NSS
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS PKTDMA definitions for Second Generation NSS
 *
 *  Define NSS PKTDMA related constants for second generation NSS
 */
/*@{*/

#define NSS_NUM_RX_PKTDMA_CHANNELS_GEN2       91    /**< Number of PKTDMA Receive channels at second generation NSS */ 
#define NSS_NUM_TX_PKTDMA_CHANNELS_GEN2       21    /**< Number of PKTDMA Transmit channels at second generation NSS */

/*@}*/ /* nssPktDmaGen2 */
/** @}*/ /* NSS PKTDMA definitions for Second Generation NSS */

/**
 *  @defgroup nssPktDmaLite NSS PKTDMA definitions for NSS Lite
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS PKTDMA definitions for NSS Lite
 *
 *  Define NSS PKTDMA related constants for NSS Lite
 */
/*@{*/

#define NSS_NUM_RX_PKTDMA_CHANNELS_LITE       32    /**< Number of PKTDMA Receive channels at NSS Lite */ 
#define NSS_NUM_TX_PKTDMA_CHANNELS_LITE       21    /**< Number of PKTDMA Transmit channels at NSS Lite*/

/*@}*/ /* nssPktDmaLite */
/** @}*/ /* NSS PKTDMA definitions for NSS Lite */


/** NSS maximum number of PKTDMA channels in all devices */
#define NSS_MAX_RX_PKTDMA_CHANNELS            91
#if (NSS_MAX_RX_PKTDMA_CHANNELS < NSS_NUM_RX_PKTDMA_CHANNELS_GEN1) || \
    (NSS_MAX_RX_PKTDMA_CHANNELS < NSS_NUM_RX_PKTDMA_CHANNELS_GEN2) || \
    (NSS_MAX_RX_PKTDMA_CHANNELS < NSS_NUM_RX_PKTDMA_CHANNELS_LITE)
#error check NSS_MAX_RX_PKTDMA_CHANNELS
#endif

#define NSS_MAX_TX_PKTDMA_CHANNELS            21
#if (NSS_MAX_TX_PKTDMA_CHANNELS < NSS_NUM_TX_PKTDMA_CHANNELS_GEN1) || \
    (NSS_MAX_TX_PKTDMA_CHANNELS < NSS_NUM_TX_PKTDMA_CHANNELS_GEN2) || \
    (NSS_MAX_TX_PKTDMA_CHANNELS < NSS_NUM_TX_PKTDMA_CHANNELS_LITE)
#error check NSS_MAX_TX_PKTDMA_CHANNELS
#endif

/**
 *  @defgroup nssPktDma NSS PKTDMA definitions 
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS PKTDMA definitions 
 *
 *  Define NSS PKTDMA related constants 
 *  @note: These definitions are also available at CPPI device files 
 */
/*@{*/

#define NSS_NUM_RX_PKTDMA_CHANNELS            NSS_NUM_RX_PKTDMA_CHANNELS_LITE    /**< Number of PKTDMA Receive channels at NSS */
#define NSS_NUM_TX_PKTDMA_CHANNELS            NSS_NUM_TX_PKTDMA_CHANNELS_LITE    /**< Number of PKTDMA Transmit channels at NSS */

/*@}*/ /* nssPktDma */
/** @}*/ /* NSS PKTDMA definitions */


/* NSS PDSP related definitions */

/**
 *  @defgroup nssPdspGen1 NSS PDSP related definitions for Dirst Generation NSS
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS PDSP related definitions for First Generation NSS
 *
 *  Define NSS PDSP related constants for first generation NSS
 */
/*@{*/

#define NSS_PA_NUM_PDSPS_GEN1                6                                 /**< Number of PASS PDSPs at first generation NSS */
#define NSS_SA_NUM_PDSPS_GEN1                2                                 /**< Number of SASS PDSPs at first generation NSS */

/*@}*/ /* nssPdspGen1 */
/** @}*/ /* PDSP related definitions for First Generation NSS */


/**
 *  @defgroup nssPdspGen2 NSS PDSP related definitions for Second Generation NSS
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS PDSP related definitions for Second Generation NSS
 *
 *  Define NSS PDSP related constants for second generation NSS
 */
/*@{*/

#define NSS_PA_NUM_PDSPS_GEN2                15                                /**< Number of PASS PDSPs at second generation NSS */
#define NSS_SA_NUM_PDSPS_GEN2                3                                 /**< Number of SASS PDSPs at second generation NSS */

/*@}*/ /* nssPdspGen2 */
/** @}*/ /* PDSP related definitions for Second Generation NSS */

/** NSS maximum number of PDSPs in PA/SA respectively in all devices */
#define NSS_PA_MAX_PDSPS                     15   
#if (NSS_PA_MAX_PDSPS < NSS_PA_NUM_PDSPS_GEN1) || \
    (NSS_PA_MAX_PDSPS < NSS_PA_NUM_PDSPS_GEN2)
#error check  NSS_PA_MAX_PDSPS
#endif

#define NSS_SA_MAX_PDSPS                     3   
#if (NSS_SA_MAX_PDSPS < NSS_SA_NUM_PDSPS_GEN1) || \
    (NSS_SA_MAX_PDSPS < NSS_SA_NUM_PDSPS_GEN2)
#error check  NSS_SA_MAX_PDSPS
#endif

/**
 *  @defgroup nssPdsp NSS PDSP related definitions
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS PDSP related definitions
 *
 *  Define NSS PDSP related constants 
 */
/*@{*/

#define NSS_PA_NUM_PDSPS                     0                            /**< Number of PASS PDSPs at NSS */
#define NSS_SA_NUM_PDSPS                     0                            /**< Number of SASS PDSPs at NSS */

/*@}*/ /* nssPdsp */
/** @}*/ /* PDSP related definitions */

/**
 *  @defgroup nssTxQueueGen1 NSS Transmit Queue related definitions for First Generation NSS
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS Transmit Queue related definitions for First Generation NSS
 *
 *  Define NSS Transmit Queue related constants for first generation NSS
 */
/*@{*/

#define NSS_NUM_TX_QUEUES_GEN1              9 
                                                                       /**< Number of Transmit Queues at first Generation NSS */
#define NSS_PA_QUEUE_INPUT_INDEX_GEN1       pa_CMD_TX_DEST_0_GEN1      /**< Offset to the system input queue at first Generation NSS */
#define NSS_PA_QUEUE_MAC_INDEX_GEN1         pa_CMD_TX_DEST_0_GEN1      /**< Offset to the MAC input queue at first Generation NSS */
#define NSS_PA_QUEUE_OUTER_IP_INDEX_GEN1    pa_CMD_TX_DEST_1_GEN1      /**< Offset to the (Outer) IP input queue at first Generation NSS */
#define NSS_PA_QUEUE_INNER_IP_INDEX_GEN1    pa_CMD_TX_DEST_2_GEN1      /**< Offset to the Inner IP input queue at first Generation NSS */
#define NSS_PA_QUEUE_LUT2_INDEX_GEN1        pa_CMD_TX_DEST_3_GEN1      /**< Offset to the LUT2 (UDP/TCP) input queue at first Generation NSS */
#define NSS_PA_QUEUE_IPSEC_INDEX_GEN1       pa_CMD_TX_DEST_1_GEN1      /**< Offset to the first layer IPSEC input queue at first Generation NSS */
#define NSS_PA_QUEUE_IPSEC2_INDEX_GEN1      pa_CMD_TX_DEST_1_GEN1      /**< Offset to the second layer IPSEC input queue at first Generation NSS */
#define NSS_PA_QUEUE_POST_INDEX_GEN1        pa_CMD_TX_DEST_4_GEN1      /**< Offset to the post-classification input queue at first Generation NSS */
#define NSS_PA_QUEUE_TXCMD_INDEX_GEN1       pa_CMD_TX_DEST_5_GEN1      /**< Offset to the Tx command input queue at first Generation NSS */

#define NSS_SA_QUEUE_SASS_INDEX_GEN1        6                          /**< Offset to the first SASS input queue at first Generation NSS */
#define NSS_SA_QUEUE_SASS2_INDEX_GEN1       7                          /**< Offset to the second SASS input queue at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_INDEX_GEN1       8                          /**< Offset to the CPSW input queue at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI0_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 0  packets at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI1_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 1  packets at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI2_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 2  packets at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI3_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 3  packets at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI4_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 4  packets at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI5_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 5  packets at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI6_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 6  packets at first Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI7_INDEX_GEN1  8                          /**< Offset to the CPSW input queue for priority 7  packets at first Generation NSS */

/*@}*/ /* nssTxQueueGen1 */
/** @}*/ /* SS Transmit Queue related definitions for First Generation NSS */

/**
 *  @defgroup nssTxQueueGen2 NSS Transmit Queue related definitions for Second Generation NSS
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS Transmit Queue related definitions for Second Generation NSS
 *
 *  Define NSS Transmit Queue related constants for second generation NSS
 */
/*@{*/


#define NSS_NUM_TX_QUEUES_GEN2              21                         /**< Number of Transmit Queues at second Generation NSS */
                                                                       
#define NSS_PA_QUEUE_INPUT_INDEX_GEN2       pa_CMD_TX_DEST_0_GEN2      /**< Offset to the system input queue at second Generation NSS */
#define NSS_PA_QUEUE_MAC_INDEX_GEN2         pa_CMD_TX_DEST_0_GEN2      /**< Offset to the MAC input queue at second Generation NSS */
#define NSS_PA_QUEUE_OUTER_IP_INDEX_GEN2    pa_CMD_TX_DEST_1_GEN2      /**< Offset to the (Outer) IP input queue at second Generation NSS */
#define NSS_PA_QUEUE_INNER_IP_INDEX_GEN2    pa_CMD_TX_DEST_4_GEN2      /**< Offset to the Inner IP input queue at second Generation NSS */
#define NSS_PA_QUEUE_LUT2_INDEX_GEN2        pa_CMD_TX_DEST_4_GEN2      /**< Offset to the LUT2 (UDP/TCP) input queue at second Generation NSS */
#define NSS_PA_QUEUE_IPSEC_INDEX_GEN2       pa_CMD_TX_DEST_1_GEN2      /**< Offset to the first layer IPSEC input queue at second Generation NSS */
#define NSS_PA_QUEUE_IPSEC2_INDEX_GEN2      pa_CMD_TX_DEST_2_GEN2      /**< Offset to the second layer IPSEC input queue at second Generation NSS */
#define NSS_PA_QUEUE_POST_INDEX_GEN2        pa_CMD_TX_DEST_5_GEN2      /**< Offset to the post-classification input queue at second Generation NSS */
#define NSS_PA_QUEUE_TXCMD_INDEX_GEN2       pa_CMD_TX_DEST_6_GEN2      /**< Offset to the Tx command input queue at second Generation NSS */
#define NSS_PA_QUEUE_FIREWALL_INDEX_GEN2    pa_CMD_TX_DEST_0_GEN2      /**< Offset to the first Firewall (ACL) input queue at second Generation NSS */
#define NSS_PA_QUEUE_FIREWALL2_INDEX_GEN2   pa_CMD_TX_DEST_3_GEN2      /**< Offset to the second Firewall (ACL) input queue at second Generation NSS */
#define NSS_PA_QUEUE_EGRESS0_INDEX_GEN2     pa_CMD_TX_DEST_6_GEN2      /**< Offset to the input queue of the first egress stage at second Generation NSS */
#define NSS_PA_QUEUE_EGRESS1_INDEX_GEN2     pa_CMD_TX_DEST_7_GEN2      /**< Offset to the input queue of the second egress stage at second Generation NSS */
#define NSS_PA_QUEUE_EGRESS2_INDEX_GEN2     pa_CMD_TX_DEST_8_GEN2      /**< Offset to the input queue of the third egress stage at second Generation NSS */
                                                                       
#define NSS_SA_QUEUE_SASS_INDEX_GEN2         18                        /**< Offset to the first SASS input queue at second Generation NSS */
#define NSS_SA_QUEUE_SASS2_INDEX_GEN2        19                        /**< Offset to the second SASS input queue at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_INDEX_GEN2        0                         /**< Offset to the CPSW input queue at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI0_INDEX_GEN2   0                         /**< Offset to the CPSW input queue for priority 0  packets at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI1_INDEX_GEN2   1                         /**< Offset to the CPSW input queue for priority 1  packets at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI2_INDEX_GEN2   2                         /**< Offset to the CPSW input queue for priority 2  packets at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI3_INDEX_GEN2   3                         /**< Offset to the CPSW input queue for priority 3  packets at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI4_INDEX_GEN2   4                         /**< Offset to the CPSW input queue for priority 4  packets at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI5_INDEX_GEN2   5                         /**< Offset to the CPSW input queue for priority 5  packets at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI6_INDEX_GEN2   6                         /**< Offset to the CPSW input queue for priority 6  packets at second Generation NSS */
#define NSS_CPSW_QUEUE_ETH_PRI7_INDEX_GEN2   7                         /**< Offset to the CPSW input queue for priority 7  packets at second Generation NSS */

/*@}*/ /* nssTxQueueGen2 */
/** @}*/ /* NSS Transmit Queue related definitions for Second Generation NSS */

/**
 *  @defgroup nssTxQueueLite NSS Transmit Queue related definitions for NSS Lite
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS Transmit Queue related definitions for NSS Lite
 *
 *  Define NSS Transmit Queue related constants for NSS Lite
 */
/*@{*/


#define NSS_NUM_TX_QUEUES_LITE               9                        /**< Number of Transmit Queues at NSS Lite */
                                                                       
                                                                       
#define NSS_SA_QUEUE_SASS_INDEX_LITE         0                        /**< Offset to the first SASS input queue at NSS Lite */
#define NSS_SA_QUEUE_SASS2_INDEX_LITE        0                        /**< Offset to the second SASS input queue at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_INDEX_LITE        1                        /**< Offset to the CPSW input queue at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI0_INDEX_LITE   1                        /**< Offset to the CPSW input queue for priority 0  packets at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI1_INDEX_LITE   2                        /**< Offset to the CPSW input queue for priority 1  packets at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI2_INDEX_LITE   3                        /**< Offset to the CPSW input queue for priority 2  packets at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI3_INDEX_LITE   4                        /**< Offset to the CPSW input queue for priority 3  packets at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI4_INDEX_LITE   5                        /**< Offset to the CPSW input queue for priority 4  packets at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI5_INDEX_LITE   6                        /**< Offset to the CPSW input queue for priority 5  packets at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI6_INDEX_LITE   7                        /**< Offset to the CPSW input queue for priority 6  packets at NSS Lite */
#define NSS_CPSW_QUEUE_ETH_PRI7_INDEX_LITE   8                        /**< Offset to the CPSW input queue for priority 7  packets at NSS Lite */

/*@}*/ /* nssTxQueueLite */
/** @}*/ /* NSS Transmit Queue related definitions for NSS Lite */

/** NSS maximum number of Tx queues in all devices */
#define NSS_MAX_TX_QUEUES                    21   
#if (NSS_MAX_TX_QUEUES < NSS_NUM_TX_QUEUES_GEN1) || \
    (NSS_MAX_TX_QUEUES < NSS_NUM_TX_QUEUES_GEN2) || \
    (NSS_MAX_TX_QUEUES < NSS_NUM_TX_QUEUES_LITE)    
#error check  NSS_MAX_TX_QUEUES
#endif

/**
 *  @defgroup nssTxQueue NSS Transmit Queue related definitions
 *  @ingroup nss_if_constants
 *  @{
 *
 *  @name NSS Transmit Queue related definitions
 *
 *  Define NSS Transmit Queue related constants
 */
/*@{*/

#define NSS_NUM_TX_QUEUES                    NSS_NUM_TX_QUEUES_LITE                /**< Number of Transmit Queues at NSS */

#define NSS_PA_QUEUE_INPUT_INDEX             -1                                    /**< Offset to the system input queue at NSS */
#define NSS_PA_QUEUE_MAC_INDEX               -1                                    /**< Offset to the MAC input queue at NSS */
#define NSS_PA_QUEUE_OUTER_IP_INDEX          -1                                    /**< Offset to the (Outer) IP input queue at NSS */
#define NSS_PA_QUEUE_INNER_IP_INDEX          -1                                    /**< Offset to the Inner IP input queue at NSS */
#define NSS_PA_QUEUE_LUT2_INDEX              -1                                    /**< Offset to the LUT2 (UDP/TCP) input queue at NSS */
#define NSS_PA_QUEUE_IPSEC_INDEX             -1                                    /**< Offset to the first layer IPSEC input queue at NSS */
#define NSS_PA_QUEUE_IPSEC2_INDEX            -1                                    /**< Offset to the second layer IPSEC input queue at NSS */
#define NSS_PA_QUEUE_POST_INDEX              -1                                    /**< Offset to the post-classification input queue at NSS */
#define NSS_PA_QUEUE_TXCMD_INDEX             -1                                    /**< Offset to the Tx command input queue at NSS */
#define NSS_PA_QUEUE_FIREWALL_INDEX          -1                                    /**< Offset to the first Firewall (ACL) input queue at NSS */
#define NSS_PA_QUEUE_FIREWALL2_INDEX         -1                                    /**< Offset to the second Firewall (ACL) input queue at NSS */
#define NSS_PA_QUEUE_EGRESS0_INDEX           -1                                    /**< Offset to the input queue of the first egress stage at NSS */
#define NSS_PA_QUEUE_EGRESS1_INDEX           -1                                    /**< Offset to the input queue of the second egress stage at NSS */
#define NSS_PA_QUEUE_EGRESS2_INDEX           -1                                    /**< Offset to the input queue of the third egress stage at NSS */
#define NSS_SA_QUEUE_SASS_INDEX              NSS_SA_QUEUE_SASS_INDEX_LITE          /**< Offset to the first SASS input queue at NSS */
#define NSS_SA_QUEUE_SASS2_INDEX             NSS_SA_QUEUE_SASS2_INDEX_LITE         /**< Offset to the second SASS input queue at NSS */
#define NSS_CPSW_QUEUE_ETH_INDEX             NSS_CPSW_QUEUE_ETH_INDEX_LITE         /**< Offset to the CPSW input queue at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI0_INDEX        NSS_CPSW_QUEUE_ETH_PRI0_INDEX_LITE    /**< Offset to the CPSW input queue for priority 0  packets at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI1_INDEX        NSS_CPSW_QUEUE_ETH_PRI1_INDEX_LITE    /**< Offset to the CPSW input queue for priority 1  packets at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI2_INDEX        NSS_CPSW_QUEUE_ETH_PRI2_INDEX_LITE    /**< Offset to the CPSW input queue for priority 2  packets at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI3_INDEX        NSS_CPSW_QUEUE_ETH_PRI3_INDEX_LITE    /**< Offset to the CPSW input queue for priority 3  packets at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI4_INDEX        NSS_CPSW_QUEUE_ETH_PRI4_INDEX_LITE    /**< Offset to the CPSW input queue for priority 4  packets at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI5_INDEX        NSS_CPSW_QUEUE_ETH_PRI5_INDEX_LITE    /**< Offset to the CPSW input queue for priority 5  packets at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI6_INDEX        NSS_CPSW_QUEUE_ETH_PRI6_INDEX_LITE    /**< Offset to the CPSW input queue for priority 6  packets at NSS */
#define NSS_CPSW_QUEUE_ETH_PRI7_INDEX        NSS_CPSW_QUEUE_ETH_PRI7_INDEX_LITE    /**< Offset to the CPSW input queue for priority 7  packets at NSS */


/*@}*/ /* nssTxQueue */
/** @}*/ /* NSS Transmit Queue related definitions */


#ifdef __cplusplus
}
#endif

#endif  /* _NSS_IF_H */




