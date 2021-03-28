/**
 *  \file       ethernet.h
 *
 *  \brief      This file contains the generic ethernet definitions.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */


/*
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

#ifndef ETHERNET_H_
#define ETHERNET_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief MAC address length in bytes. */
#define ETHERNET_MAC_ADDR_LEN                              (6U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates mode of transfer operation. */
typedef enum ethernetXferMode
{
    ETHERNET_XFER_MODE_TX   = 0x00U,
    /**< Transfer mode is transmitter. */
    ETHERNET_XFER_MODE_RX    = 0x01U
    /**< Transfer mode is receiver. */
}ethernetXferMode_t;

/** \brief Enumerates type of MAC address. */
typedef enum ethernetAddrType
{
    ETHERNET_ADDR_TYPE_UNICAST   = 0x00U,
    /**< Unicast address. */
    ETHERNET_ADDR_TYPE_MULTICAST = 0x01U,
    /**< Multicast address. */
    ETHERNET_ADDR_TYPE_BROADCAST = 0x02U
    /**< Broadcast address. */
}ethernetAddrType_t;

/** \brief Enumerates duplicity configuration modes. */
typedef enum ethernetDuplexMode
{
    ETHERNET_DUPLEX_MODE_HALF   = 0x00U,
    /**< Half duplex mode. */
    ETHERNET_DUPLEX_MODE_FULL    = 0x01U
    /**< Full duplex mode. */
}ethernetDuplexMode_t;

/** \brief Enumerates speed configurations. */
typedef enum ethernetSpeed
{
    ETHERNET_SPEED_10    = 0x00U,
    /**< 10 Mbps operation. */
    ETHERNET_SPEED_100   = 0x01U,
    /**< 100 Mbps operation. */
    ETHERNET_SPEED_1000  = 0x02U
    /**< 1000 Mbps operation. */
}ethernetSpeed_t;

/** \brief Enumerates Advertisement configurations. */
typedef enum ethernetAdvCapab
{
    ETHERNET_ADV_CAPAB_10_HALF    = (0x1U << 0x0U),
    /**< 10 Mbps half operation. */
    ETHERNET_ADV_CAPAB_10_FULL    = (0x1U << 0x1U),
    /**< 10 Mbps full operation. */
    ETHERNET_ADV_CAPAB_100_HALF   = (0x1U << 0x2U),
    /**< 100 Mbps half operation. */
    ETHERNET_ADV_CAPAB_100_FULL   = (0x1U << 0x3U),
    /**< 100 Mbps full operation. */
    ETHERNET_ADV_CAPAB_1000_HALF  = (0x1U << 0x4U),
    /**< 1000 Mbps half operation. */
    ETHERNET_ADV_CAPAB_1000_FULL  = (0x1U << 0x5U)
    /**< 1000 Mbps full operation. */
}ethernetAdvCapab_t;

/** \brief Enumerates MAC interface type. */
typedef enum ethernetMacType
{
    ETHERNET_MAC_TYPE_MII    = 0x00U,
    /**< MII interface. */
    ETHERNET_MAC_TYPE_RMII   = 0x01U,
    /**< RMII interface. */
    ETHERNET_MAC_TYPE_GMII  = 0x02U,
    /**< GMII interface. */
    ETHERNET_MAC_TYPE_RGMII  = 0x03U
    /**< RGMII interface. */
}ethernetMacType_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                        Deprecated Function Declarations                    */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef ETHERNET_H_ */
