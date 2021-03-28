/********************************************************************
 * Copyright (C) 2018-2019 Texas Instruments Incorporated.
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
/** ============================================================================
 *   @file  emac_mdio.h
 *
 *   @brief  This file contains the Constants, Objects and interfaces for MDIO IP sub-system for EMAD LLD
 *  ============================================================================
 */

#ifndef EMAC_MDIO_H
#define EMAC_MDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/cslr.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_error.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_cpswitch.h>

/* void pointer type defined for MDIO */
typedef void * emacMdioHandle;

void EMAC_mdioGetStatus( emacMdioHandle hMDIO, uint32_t *pPhy, uint32_t *pLinkStatus );
void EMAC_mdioOpen(uint32_t portNum, int instNum, uint32_t phyAddr, emacMdioHandle hMDIO);
uint32_t EMAC_mdioTimerTick( emacMdioHandle hMDIO );

/*
 *  These flags determine how the MDIO module behaves
 */
#define EMAC_MDIO_MODEFLG_AUTONEG        0x0001
/* Use Autonegotiate                                                      */

/* The following bits are used for manual and fallback configuration        */
#define EMAC_MDIO_MODEFLG_HD10           0x0002
/* Use 10Mb/s Half Duplex                                                 */
#define EMAC_MDIO_MODEFLG_FD10           0x0004
/* Use 10Mb/s Full Duplex                                                 */
#define EMAC_MDIO_MODEFLG_HD100          0x0008
/* Use 100Mb/s Half Duplex                                                */
#define EMAC_MDIO_MODEFLG_FD100          0x0010
/* Use 100Mb/s Full Duplex                                                */
#define EMAC_MDIO_MODEFLG_FD1000         0x0020
/* Use 1000Mb/s Full Duplex                                               */
#define EMAC_MDIO_MODEFLG_LOOPBACK       0x0040
/* Use PHY Loopback                                                       */

/* The following bits are reserved for use by the MDIO module               */
#define EMAC_MDIO_MODEFLG_NWAYACTIVE     0x0080
/* NWAY currently active                                                  */
#define EMAC_MDIO_MODEFLG_EXTLOOPBACK    0x0100
/* Use external PHY Loopback, with plug                                   */
#define EMAC_MDIO_MODEFLG_SPECPHYADDR    0x0200
/* Monitor PHY address which is specified by user                         */

/*
 *  These values indicate current PHY link status
 */
#define EMAC_MDIO_LINKSTATUS_NOLINK      0
/* Link Status: No Link                                                   */
#define EMAC_MDIO_LINKSTATUS_HD10        1
/* Link Status: HD10                                                      */
#define EMAC_MDIO_LINKSTATUS_FD10        2
/* Link Status: FD10                                                      */
#define EMAC_MDIO_LINKSTATUS_HD100       3
/* Link Status: HD100                                                     */
#define EMAC_MDIO_LINKSTATUS_FD100       4
/* Link Status: FD100                                                     */
#define EMAC_MDIO_LINKSTATUS_FD1000      5
/* Link Status: FD1000                                                    */

/*  These events are returned by MDIO_timerTick() to allow the application
 *  (or EMAC) to track MDIO status.
 */
#define EMAC_MDIO_EVENT_NOCHANGE         0
/* No change from previous status                                         */
#define EMAC_MDIO_EVENT_LINKDOWN         1
/* Link down event                                                        */
#define EMAC_MDIO_EVENT_LINKUP           2
/* Link (or re-link) event                                                */
#define EMAC_MDIO_EVENT_PHYERROR         3
/* No PHY connected                                                       */

/**
 *
 *  Used by MDIO to configure a MII compliant PHY
 */

/**
 *
 *  Used by MDIO to configure a MII compliant PHY
 */
#define EMAC_PHYREG_CONTROL              0           /* Control register       */
#define EMAC_PHYREG_CONTROL_RESET        (1<<15)     /* Set Reset bit          */
#define EMAC_PHYREG_CONTROL_LOOPBACK     (1<<14)     /* Set Loop back bit      */
#define EMAC_PHYREG_CONTROL_SPEEDLSB     (1<<13)     /* Set Speed LSB bit      */
#define EMAC_PHYREG_CONTROL_AUTONEGEN    (1<<12)     /* Auto Negate Enable bit */
#define EMAC_PHYREG_CONTROL_POWERDOWN    (1<<11)     /* Set Power Down bit     */
#define EMAC_PHYREG_CONTROL_ISOLATE      (1<<10)     /* Set Isolate bit        */
#define EMAC_PHYREG_CONTROL_AUTORESTART  (1<<9)      /* Set Auto restart bit   */
#define EMAC_PHYREG_CONTROL_DUPLEXFULL   (1<<8)      /* Set Full Duplex bit    */
#define EMAC_PHYREG_CONTROL_SPEEDMSB     (1<<6)      /* Set Speed MSB bit      */

/**
 *
 *  Used by MDIO to configure a MII compliant PHY
 */
#define EMAC_PHYREG_STATUS               1           /* Status register        */
#define EMAC_PHYREG_STATUS_FD100         (1<<14)     /* Set FD100 bit          */
#define EMAC_PHYREG_STATUS_HD100         (1<<13)     /* Set HD100 bit          */
#define EMAC_PHYREG_STATUS_FD10          (1<<12)     /* Set FD10 bit           */
#define EMAC_PHYREG_STATUS_HD10          (1<<11)     /* Set HD10bit            */
#define EMAC_PHYREG_STATUS_EXTSTATUS     (1<<8)      /* Set External Status bit*/
#define EMAC_PHYREG_STATUS_NOPREAMBLE    (1<<6)      /* Set No preamble bit    */
#define EMAC_PHYREG_STATUS_AUTOCOMPLETE  (1<<5)      /* Set Auto complete bit  */
#define EMAC_PHYREG_STATUS_REMOTEFAULT   (1<<4)      /* Set Reomte default bit */
#define EMAC_PHYREG_STATUS_AUTOCAPABLE   (1<<3)      /* Set Auto Capable bit   */
#define EMAC_PHYREG_STATUS_LINKSTATUS    (1<<2)      /* Set Link status bit    */
#define EMAC_PHYREG_STATUS_JABBER        (1<<1)      /* Set Jabber bit         */
#define EMAC_PHYREG_STATUS_EXTENDED      (1<<0)      /* Set Extended bit       */

/**
 *
 *  Used by MDIO to configure a MII compliant PHY
 */
#define EMAC_PHYREG_ADVERTISE            4           /* Physical Advertise reg */
#define EMAC_PHYREG_ADVERTISE_NEXTPAGE   (1<<15)     /* Set next page bit      */
#define EMAC_PHYREG_ADVERTISE_FAULT      (1<<13)     /* Set Fault bit          */
#define EMAC_PHYREG_ADVERTISE_PAUSE      (1<<10)     /* Set Pause bit          */
#define EMAC_PHYREG_ADVERTISE_FD100      (1<<8)      /* Set FD100 bit          */
#define EMAC_PHYREG_ADVERTISE_HD100      (1<<7)      /* Set HD100 bit          */
#define EMAC_PHYREG_ADVERTISE_FD10       (1<<6)      /* Set FD10 bit           */
#define EMAC_PHYREG_ADVERTISE_HD10       (1<<5)      /* Set HD10 bit           */
#define EMAC_PHYREG_ADVERTISE_MSGMASK    (0x1F)      /* Set Message mask bit   */
#define EMAC_PHYREG_ADVERTISE_MSG        (1)         /* Set Message bit        */

/**
 *
 *  Used by MDIO to configure a MII compliant PHY
 */
#define EMAC_PHYREG_PARTNER              5           /* Physical Partner reg   */
#define EMAC_PHYREG_PARTNER_NEXTPAGE     (1<<15)     /* Set next page bit      */
#define EMAC_PHYREG_PARTNER_ACK          (1<<14)     /* Set Acknowledge bit    */
#define EMAC_PHYREG_PARTNER_FAULT        (1<<13)     /* Set Fault bit          */
#define EMAC_PHYREG_PARTNER_PAUSE        (1<<10)     /* Set Pause bit          */
#define EMAC_PHYREG_PARTNER_FD100        (1<<8)      /* Set FD100 bit          */
#define EMAC_PHYREG_PARTNER_HD100        (1<<7)      /* Set HD100 bit          */
#define EMAC_PHYREG_PARTNER_FD10         (1<<6)      /* Set FD10 bit           */
#define EMAC_PHYREG_PARTNER_HD10         (1<<5)      /* Set HD10 bit           */
#define EMAC_PHYREG_PARTNER_MSGMASK      (0x1F)      /* Set Message mask bit   */

#define EMAC_PHYREG_1000CONTROL          9           /* Physical 1000 Ctrl reg */
#define EMAC_PHYREG_ADVERTISE_FD1000     (1<<9)      /* Advertise FD1000 bit   */

#define EMAC_PHYREG_1000STATUS           0xA         /* Phy 1000 Status reg    */
#define EMAC_PHYREG_PARTNER_FD1000       (1<<11)     /* Partner FD1000 bit     */

#define EMAC_PHYREG_EXTSTATUS            0x0F        /* Physical Ext status reg*/
#define EMAC_PHYREG_EXTSTATUS_FD1000     (1<<13)     /* Ext Status FD1000 bit  */

#define EMAC_PHYREG_PHYSTS               0x11       /* PHYSTS reg              */
#define EMAC_PHYREG_PHYSTS_FD1000       (5<<13)     /* 1000Mb/s FD             */
#define EMAC_PHYREG_PHYSTS_FD100        (3<<13)     /* 100Mb/s FD              */
#define EMAC_PHYREG_PHYSTS_HD100        (2<<13)     /* 100Mb/s HD              */
#define EMAC_PHYREG_PHYSTS_FD10         (1<<13)     /* 10Mb/s FD               */
#define EMAC_PHYREG_PHYSTS_HD10         (0<<13)     /* 10Mb/s HD               */

/**
 *
 *  When using auto-negotiation, the software must keep the MAC in
 *  sync with the PHY (for duplex). This module will also attempt to
 *  "auto-select" the PHY from a potential list of 32 based on which is
 *  first to get a link.
 *
 *  On detection of a good link, the link speed and duplex settings will be
 *  used to update the EMAC configuration (done external to this module).
 *
 *  States in the PHY State Machine:
 */
#define EMAC_PHYSTATE_MDIOINIT           ((uint32_t)0U)   /* MDIO Initialization state      */
#define EMAC_PHYSTATE_RESET              ((uint32_t)1U)   /* MDIO Reset State               */
#define EMAC_PHYSTATE_NWAYSTART          ((uint32_t)2U)   /* MDIO N Way start               */
#define EMAC_PHYSTATE_NWAYWAIT           ((uint32_t)3U)   /* MDIO N Way wait                */
#define EMAC_PHYSTATE_LINKWAIT           ((uint32_t)4U)   /* MDIO Wait for link             */
#define EMAC_PHYSTATE_LINKED             ((uint32_t)5U)   /* MDIO Linked                    */


/**
 *  \brief EMAC_MDIO_DEVICE_T
 *  This is the MDIO object that contains the MDIO device object
 *  characteristics
 *
 */
typedef struct _EMAC_MDIO_DEVICE_S {
    uint32_t            modeFlags;
    /* User specified configuration flags                                 */
    uint32_t            phyAddr;
    /* PHY address                                  */
    uint32_t            phyState;
    /* PHY State                                                          */
    uint32_t            linkStatus;
    /* Link State EMAC_PHYREG_STATUS_LINKSTATUS                                */
    uint32_t            regId;
    /* The set of MDIO User Access and PHY Select Registers used to
         monitor the PHY:
         0 - USERACCESS0 and USERPHYSEL0; 1 - USERACCESS1 and USERPHYSEL1   */
    uintptr_t mdioBaseAddr;
    /* Base address of MDIO IP registers */
} EMAC_MDIO_DEVICE_T;


#ifdef __cplusplus
}
#endif

/**
@}
*/
#endif /* EMAC_MDIO_H */
