/*
 * nimu_internal.h
 *
 * Copyright (C) 2011 - 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/**
 *   @file  nimu_internal.h
 *
 *   @brief
 *      Network Interface Module Ethernet driver adaptation layer. These are internal
 *      definitions for the driver.
 *
 */
#ifndef _NIMU_INTERNAL_H_
#define _NIMU_INTERNAL_H_

#include <ti/ndk/inc/stkmain.h>

/* CSL EMAC include */
#include <ti/csl/csl_cpgmac_slAux.h>
#include <ti/csl/csl_cptsAux.h>
#include <ti/csl/csl_cpsgmii.h>
#include <ti/csl/csl_cpsgmiiAux.h>

/* BootCfg module include */
#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_bootcfgAux.h>

/* CSL CHIP, SEM Functional layer includes */
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_semAux.h>


/* CPPI LLD include */
#include <ti/drv/cppi/cppi_drv.h>
#include <ti/drv/cppi/cppi_desc.h>

/* NetCP includes */
#include <ti/drv/qmss/qmss_drv.h>


/* Standard C-native includes  */
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Shut off: remark #880-D: parameter "descType" was never referenced
*
* This is better than removing the argument since removal would break
* backwards compatibility
*/
#ifdef _TMS320C6X
#elif defined(__GNUC__)
/* Same for GCC:
* warning: unused parameter descType [-Wunused-parameter]
*/
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"
#pragma GCC diagnostic ignored "-Wunused-function"
#endif



/* Number of cores on K2G */
#define     NUM_CORES           2

#define NIMU_MAX_EMAC_PORT_NUM 1

/*
 * Pre-Pad Packet Data Offset
 *
 *   The TCP/IP stack library requires that every packet device
 *   include enough L2 header room for all supported headers. In
 *   order to support PPPoE, this requires a 22 byte L2 header.
 *   Thus, since standard Ethernet is only 14 bytes, we must add
 *   on an additional 8 byte offset, or PPPoE can not function
 *   with our driver.
*/
#define     PKT_PREPAD                      8

/* Indicates whether RAM based multicast lists are suported for this
 * EMAC peripheral.
 */
#define     RAM_MCAST                       0

/* Indicates whether HASH based multicasting is suported for this
 * EMAC peripheral.
 */
#define     HASH_MCAST                      0

/* Multicast Address List Size */
#define     PKT_MAX_MCAST                   31

/** Number of ports in the ethernet subsystem */
#define         NUM_PORTS                   3u

/** Number of MAC/GMII ports in the ethernet switch */
#define         NUM_MAC_PORTS               2u


/** Host descriptor size.
 *
 *  Big enough to hold the mandatory fields of the
 *  host descriptor and PA Control Data
 *
 *  = 32 bytes for Host desc + PA Control data + 16 bytes padding
 */
#define         SIZE_HOST_DESC              128

/* High Priority QM Rx Interrupt Threshold */
#define     RX_INT_THRESHOLD            4u


/* Accumulator channel to use */
#define     PA_ACC_CHANNEL_NUM          0u

/* Max Number of Rx packets in the Queue before passing to NDK */
#define     MAX_NUM_RAW_PKTS_INQ                    4


/* Rx queue (one for all PKT devices) */
#ifndef _INCLUDE_NIMU_CODE
extern PBMQ    PBMQ_rx;
#endif

/**
 * @brief   External memory start address
 */

#define     EMAC_EXTMEM                          0x80000000
#define     EMAC_LL2SRAM                         0x00800000
#define     EMAC_MSMCSRAM                        0x0c000000

/* tmannan: new updates */
#if 1
/* PA definitions */
#define     MAX_NUM_L2_HANDLES          10
#define     MAX_NUM_L3_HANDLES          20
#define     MAX_NUM_L4_HANDLES          40

#define NIMU_ETH_EVENTID            48              /**< Ethernet Switch event - Used by NIMU library */
#define NIMU_ETH_INTERRUPT          7               /**< Ethernet Switch Interrupt - Used by NIMU library */
#define CACHE_LINESZ (128)

/**
 *  @brief      Queue handler type for FDQ.
 */
typedef enum {
    QHANDLER_QPOP_FDQ_NO_ATTACHEDBUF,
    QHANDLER_QPOP_FDQ_ATTACHEDBUF
} NIMU_QHANDLER_TYPE;

typedef enum {
    CPPI_CFG_PASS   = 0,
    CPPI_CFG_SRIO
} NIMU_CPPI_CFG_TYPE;


#define NIMU_NUM_TX_DESC                16u /**< Maximum number of TX descriptors used by NIMU */
#define NIMU_NUM_RX_DESC                110u /**< Maximum number of RX descriptors used by NIMU */
#define NIMU_MAX_NUM_TX_CMD_DESC        2u  /**< Maximum number of TX Command descriptors used by NIMU */

#define MAX_NUM_NIMU_DESC   (NIMU_NUM_TX_DESC + NIMU_NUM_RX_DESC + NIMU_MAX_NUM_TX_CMD_DESC) /**< Maximum number of descriptors used by NIMU */
#define MAX_NUM_DESC        (MAX_NUM_NIMU_DESC)   /**< Maximum number of descriptors used by all the modules */
#define MAX_DESC_SIZE       128 /**< Maximum size of descriptor in bytes */

#define NIMU_roundUp(n,w) (((n) + (w) - 1) & ~((w) - 1))

typedef struct {
    uint32_t                        port_num;
    /**<Port number of the EMAC port */
    uint32_t         mode;
    /**<Mode of the EMAC port */
    uint8_t                         mac_address[6];
    /**<MAC address of the EMAC port */
} NIMU_EMAC_EXT_info;

#endif

/**
 * @brief
 *  Packet device information
 *
 * @details
 *  This structure caches the device info.
 */
typedef struct _pdinfo
{
    /**
     * @brief       Physical index of this device (0 to n-1).
     */
    uint32_t            PhysIdx;
    /*
     * @brief       Handle to logical driver.
     */
    void*          hEther;
    /*
     * @brief       Semaphore handle used by NDK stack and driver
     *              to communicate any pending Rx events that need
     *              to be serviced by NDK ethernet stack.
     */
    STKEVENT_Handle hEvent;
    /*
     * @brief       MAC Address
     */
    uint8_t           bMacAddr[6];
    /*
     * @brief       Current RX filter
     */
    uint32_t            Filter;
    /*
     * @brief       Current MCast Address Countr
     */
    uint32_t            MCastCnt;
    /*
     * @brief       Multicast list configured by the Application.
     */
    uint8_t           bMCast[6*PKT_MAX_MCAST];
    /*
     * @brief       Transmitter "free" flag
     */
    uint32_t            TxFree;
    /*
     * @brief       Tx queue (one for each PKT device)
     */
    PBMQ            PBMQ_tx;

    /*
     * @brief       Raw Pkt Tx queue (one for each PKT device)
     */
    PBMQ            PBMQ_rawtx;

    /*
     * @brief       Rx queue (one for each PKT device)
     */
    PBMQ            PBMQ_rx;

    /*
     * @brief       Raw Pkt Rx queue (one for each PKT device)
     */
    PBMQ            PBMQ_rawrx;
} PDINFO;

/**
 *  @brief  Nimu_CppiDescCfg
 *
 *          Structure to specify the CPPI descriptor configuration
 *          for a NIMU free queue used to hold pre-allocated
 *          buffers.
 */
typedef struct  _Nimu_CppiDescCfg
{
    /** CPPI Memory region to be used for this set of free descriptors. */
    uint32_t                    descMemRegion;

    /** Number of CPPI free descriptors to allocate */
    uint32_t                    numDesc;

    /** Size of CPPI free descriptors to allocate */
    uint32_t                    descSize;

    /** CPPI Descriptor Type.
     *
     *  Valid values are:
     *      Cppi_DescType_HOST,
     *      Cppi_DescType_MONOLITHIC
     */
    Cppi_DescType               descType;
} Nimu_CppiDescCfg;

/**
 * @brief
 *  NIMU LLD configuration information
 *
 * @details
 *  This structure holds the configurations for the PA, QMSS, CPPI LLDs.
 */
typedef struct _nimu_config
{
    /**
     * @brief       To configure internal or external link ram (0 or 1).
     */
    Bool                    ExtLinkRam;

    /* RX Threshold */

    /** Even ID for the Rx ISR */
    uint32_t                eventID;

    /** Vector ID for the Rx ISR */
    uint32_t                vectorID;

} NIMUConfigParams;

/* The EMAC Initialization Function. */
static int EmacInit (STKEVENT_Handle hEvent);
static int EMACInit_Core (STKEVENT_Handle hEvent);

extern      int32_t       NIMU_initQmss(void);
extern      int32_t       Init_PASS(void);
extern      int32_t       Init_Cpsw(uint32_t mtu, uint8_t * srcmacaddress);
extern      int32_t       NIMU_initCppi(void);
extern      int32_t       Verify_Init (void);
extern      void        Init_MDIO(void);
extern      void        Init_SGMII (uint32_t macPortNum);
extern      void        emac_init_mac(uint32_t, uint8_t *, uint32_t);
extern      int32_t       Setup_Tx(void);
extern      int32_t       Setup_Rx(NETIF_DEVICE*     ptr_net_device);
extern      int32_t       Setup_PASS(void);
extern      uint32_t      NIMU_convertCoreLocal2GlobalAddr (uint32_t  addr);
extern      void        CycleDelay (int32_t count);
extern      void        EmacRxPktISR (NETIF_DEVICE*     ptr_net_device );
extern      int32_t       Cpsw_SwitchOpen (void);
extern      int32_t       Mdio_Open (void);
extern      int32_t       Sgmii_Open (void);
extern      int32_t       Download_PAFirmware (void);


/**
 * @brief
 *   EMAC_DATA
 *
 * @details
 *  The structure is used to store the private data for the
 *  EMAC controller.
 */
typedef struct EMAC_DATA
{
/**
  * @brief   Private Information
  */
    PDINFO      pdi;
}EMAC_DATA;

static void
EmacRxPkt
(
    uint32_t              port_num,
    Cppi_Desc*          pCppiDesc
);


NIMUConfigParams nimuGlobalConfigParams;

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/



#if  0
/* Various stats  */
#ifdef _TMS320C6X
#pragma DATA_SECTION(gTxCounter, ".nimu_eth_ll2");
#pragma DATA_SECTION(gRxCounter, ".nimu_eth_ll2");
#pragma DATA_SECTION(gTxDropCounter, ".nimu_eth_ll2");
#pragma DATA_SECTION(gRxDropCounter, ".nimu_eth_ll2");
#endif
uint32_t gTxCounter=0, gRxCounter=0, gTxDropCounter = 0, gRxDropCounter=0;
#endif
/* TX port number */
#ifdef _TMS320C6X
#ifdef __cplusplus
#pragma DATA_SECTION(".nimu_eth_ll2");
#else
#pragma DATA_SECTION(gTxPort, ".nimu_eth_ll2");
#endif
#endif
uint32_t gTxPort;

#ifdef __cplusplus
}
#endif

#endif /* _NIMU_ETH_H_ */
