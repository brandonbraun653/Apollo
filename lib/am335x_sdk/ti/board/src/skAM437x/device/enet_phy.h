/**
 * enet_phy.h
 *
 *
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef _ENETPHY_H
#define _ENETPHY_H

//#include "cpsw_nimu_eth.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************
**
**         M D I O  R E G I S T E R  A C C E S S  M A C R O S
**
***************************************************************************/

#define         MDIO_USERACCESS_DATA   (0xFFFF)
#define         MDIO_USERPHYSEL_LINKSEL         (1 << 7)

/****************************************************************************/
/*                                                                          */
/*         P H Y   R E G I S T E R  D E F I N I T I O N S                   */
/*                                                                          */
/****************************************************************************/

/* PHY register offset definitions */
#define ENETPHY_BCR                           (0u)
#define ENETPHY_BSR                           (1u)
#define ENETPHY_ID1                           (2u)
#define ENETPHY_ID2                           (3u)
#define ENETPHY_AUTONEG_ADV                   (4u)
#define ENETPHY_LINK_PARTNER_ABLTY            (5u)
#define ENETPHY_1000BT_CONTROL                (9u)
#define ENETPHY_1000BT_STATUS                 (0x0A)

/* PHY status definitions */
#define ENETPHY_ID_SHIFT                      (16u)
#define ENETPHY_SOFTRESET                     (0x8000)
#define ENETPHY_AUTONEG_ENABLE                (0x1000u)
#define ENETPHY_AUTONEG_RESTART               (0x0200u)
#define ENETPHY_AUTONEG_COMPLETE              (0x0020u)
#define ENETPHY_AUTONEG_INCOMPLETE            (0x0000u)
#define ENETPHY_AUTONEG_STATUS                (0x0020u)
#define ENETPHY_AUTONEG_ABLE                  (0x0008u)
#define ENETPHY_LPBK_ENABLE                   (0x4000u)
#define ENETPHY_LINK_STATUS                   (0x0004u)

/* PHY ID. The LSB nibble will vary between different phy revisions */
#define ENETPHY_ID_REV_MASK                   (0x0000000Fu)

/* Pause operations */
#define ENETPHY_PAUSE_NIL                     (0x0000u)
#define ENETPHY_PAUSE_SYM                     (0x0400u)
#define ENETPHY_PAUSE_ASYM                    (0x0800u)
#define ENETPHY_PAUSE_BOTH_SYM_ASYM           (0x0C00u)

/* 1000 Base-T capabilities */
#define ENETPHY_NO_1000BT                     (0x0000u)
#define ENETPHY_1000BT_HD                     (0x0100u)
#define ENETPHY_1000BT_FD                     (0x0200u)

/* 100 Base TX Full Duplex capablity */
#define ENETPHY_100BTX_HD                     (0x0000u)
#define ENETPHY_100BTX_FD                     (0x0100u)

/* 100 Base TX capability */
#define ENETPHY_NO_100BTX                     (0x0000u)
#define ENETPHY_100BTX                        (0x0080u)

/* 10 BaseT duplex capabilities */
#define ENETPHY_10BT_HD                       (0x0000u)
#define ENETPHY_10BT_FD                       (0x0040u)

/* 10 BaseT ability*/
#define ENETPHY_NO_10BT                       (0x0000u)
#define ENETPHY_10BT                          (0x0020u)

#define ENETPHY_LINK_PARTNER_1000BT_FD        (0x0800u)
#define ENETPHY_LINK_PARTNER_1000BT_HD        (0x0400u)

/* Speed settings for BCR register */
#define ENETPHY_SPEED_MASK                    (0xDFBF)
#define ENETPHY_SPEED_10MBPS                  (0x0000u)
#define ENETPHY_SPEED_100MBPS                 (0x2000u)
#define ENETPHY_SPEED_1000MBPS                (0x0040)

/* Duplex settings for BCR register */
#define ENETPHY_FULL_DUPLEX                   (0x0100)

#define ENETPHY_CONTROL_REG       0
  #define MII_ENETPHY_RESET           (1<<15)
  #define MII_ENETPHY_LOOP            (1<<14)
  #define MII_ENETPHY_100             (1<<13)
  #define MII_AUTO_NEGOTIATE_EN   (1<<12)
  #define MII_ENETPHY_PDOWN           (1<<11)
  #define MII_ENETPHY_ISOLATE         (1<<10)
  #define MII_RENEGOTIATE         (1<<9)
  #define MII_ENETPHY_FD              (1<<8)
  #define MII_ENETPHY_1000            (1<<6)

#define ENETPHY_STATUS_REG        1
  #define MII_NWAY_COMPLETE       (1<<5)
  #define MII_NWAY_CAPABLE        (1<<3)
  #define MII_ENETPHY_LINKED          (1<<2)

#define ENETPHY_IDENT_REG         2
#define NWAY_ADVERTIZE_REG    4
#define NWAY_REMADVERTISE_REG 5
  #define MII_NWAY_FD100          (1<<8)
  #define MII_NWAY_HD100          (1<<7)
  #define MII_NWAY_FD10           (1<<6)
  #define MII_NWAY_HD10           (1<<5)
  #define MII_NWAY_SEL            (1<<0)

#define NWAY_1000BT_ADVERTISE_REG    9
  #define MII_NWAY_MY_FD1000         (1<<9)
  #define MII_NWAY_MY_HD1000         (1<<8)
#define NWAY_1000BT_REMADVERTISE_REG 10
  #define MII_NWAY_REM_FD1000         (1<<11)
  #define MII_NWAY_REM_HD1000         (1<<10)

#define ENETPHY_CNTRL_REG        0x0019

#define ENETPHY_CONFIG_REG	22
  #define SYSTEM_CLOCK_ENABLE_125MHZ	(1<<4)
  #define TRANSMIT_CLOCK_ENABLE_1000BASET	(1<<5)
  #define GMII_CLOCKED_BY_GTX_CLK	(1<<1)

#define ENETPHY_LED_CONTROL_REG	28

/* Phy Mode Values  */
#define NWAY_AUTOMDIX       (1u << 16u)
#define NWAY_FD1000         (1u<<13u)
#define NWAY_HD1000         (1u<<12u)
#define NWAY_NOPHY          (1u<<10u)
#define NWAY_LPBK           (1u<<9u)
#define NWAY_FD100          (1u<<8u)
#define NWAY_HD100          (1u<<7u)
#define NWAY_FD10           (1u<<6u)
#define NWAY_HD10           (1u<<5u)
#define NWAY_AUTO           (1u<<0u)

#define NWAY_AUTOMDIX_ENABLE (1u<<15)

/* Tic() return values */
#define _MIIMDIO_MDIXFLIP (1u<<28u)
#define _AUTOMDIX_DELAY_MIN  80u  /* milli-seconds*/
#define _AUTOMDIX_DELAY_MAX 200u  /* milli-seconds*/

/*-----------------------------------------------------------------------
 * MDIO Events
 *
 * These events are returned as result param by ENETPHY_Tic() to allow the application
 * (or EMAC) to track MDIO status.
 *-----------------------------------------------------------------------*/
#define MDIO_EVENT_NOCHANGE      0u   /* No change from previous status */
#define MDIO_EVENT_LINKDOWN      1u   /* Link down event                */
#define MDIO_EVENT_LINKUP         2u   /* Link (or re-link) event        */
#define MDIO_EVENT_PHYERROR      3u   /* No PHY connected                */

/*-----------------------------------------------------------------------
 * MDIO Link Status Values
 *
 * These values indicate current PHY link status.
 * Codes are constructed as follows
 * Bit0: 0  for HD, 1 for FullDuplex
 * Bit[2:1]: 10Mbps- 1, 100Mbps - 2, 1000Mbps - 3
 *
 *-----------------------------------------------------------------------*/
#define MDIO_LINKSTATUS_NOLINK     0u
#define MDIO_LINKSTATUS_HD10     2u
#define MDIO_LINKSTATUS_FD10     3u
#define MDIO_LINKSTATUS_HD100     4u
#define MDIO_LINKSTATUS_FD100     5u
#define MDIO_LINKSTATUS_FD1000  7u

typedef void            *ENETPHY_Handle;

typedef struct ENETPHY_DEVICE_s
{
   uint32_t miibase;
   uint32_t inst;
   uint32_t PhyState;
   uint32_t MdixMask;
   uint32_t PhyMask;
   uint32_t MLinkMask;
   uint32_t PhyMode;
   uint32_t SPEED_1000; /* set to 1 for gig capable phys */
} ENETPHY_DEVICE;

/*Version Information */
void ENETPHY_GetVer(uint32_t miiBase, uint32_t *ModID,  uint32_t *RevMaj,  uint32_t *RevMin);

/*Called once at the begining of time */
int32_t  ENETPHY_GetPhyDevSize(void);  /*Called first to get size of storage needed!*/

int32_t  ENETPHY_Init(ENETPHY_Handle hPhyDev, uint32_t miibase, uint32_t inst, uint32_t PhyMask,
                        uint32_t MLinkMask, uint32_t MdixMask, uint32_t PhyAddr, uint32_t ResetBit, uint32_t MdioBusFreq,
                        uint32_t MdioClockFreq,int32_t verbose);

/*Called every 100 milli Seconds, returns TRUE if there has been a mode change */
int32_t ENETPHY_Tic(ENETPHY_Handle hPhyDev, uint32_t* mdioStatus);

/*Called to set Phy mode   */
void ENETPHY_SetPhyMode(ENETPHY_Handle hPhyDev,uint32_t PhyMode);

/*Called to Get Phy mode   */
uint32_t ENETPHY_GetPhyMode(ENETPHY_Handle hPhyDev);

/*Calls to retreive info after a mode change! */
int32_t  ENETPHY_GetDuplex(ENETPHY_Handle hPhyDev);
int32_t  ENETPHY_GetSpeed(ENETPHY_Handle hPhyDev);
int32_t  ENETPHY_GetPhyNum(ENETPHY_Handle hPhyDev);
int32_t  ENETPHY_GetLinked(ENETPHY_Handle hPhyDev);
void ENETPHY_LinkChange(ENETPHY_Handle hPhyDev);
int32_t  ENETPHY_GetLoopback(ENETPHY_Handle hPhyDev);

/*  Shut Down  */
void ENETPHY_Close(ENETPHY_Handle hPhyDev, int32_t Full);

/* Expert Use Functions (exported) */
uint32_t ENETPHY_UserAccessRead (ENETPHY_Handle hPhyDev, uint32_t regadr, uint32_t phyadr, uint32_t *data);
void   ENETPHY_UserAccessWrite(ENETPHY_Handle hPhyDev, uint32_t regadr, uint32_t phyadr, uint32_t data);

#ifdef __cplusplus
}
#endif

#endif /*_CPSW_MIIMDIO_H*/
