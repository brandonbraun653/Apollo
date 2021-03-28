/**
 *  \file     cpsw.h
 *
 *  \brief    This file contains the function prototypes for the device
 *            abstraction layer for CPSW subsystem. It also contains some
 *            related macro definitions and some files to be included.
 *
 *  \details  Please find the below detailed description of cpsw dal.
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

#ifndef CPSW_H_
#define CPSW_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_cpsw_wr.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define CPSWSSReset             CPSWSsReset
#define CPSWSlReset             CPSWSlReset
#define CPSWWrReset             CPSWWrReset
#define CPSWCPDMANumFreeBufSet  CPSWSetCpdmaNumFreeBuf
#define CPSWCPDMARxBufOffsetSet CPSWSetCpdmaRxBufOffset

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief Maximum length of ethernet packet. */
#define CPSW_MAX_PACKET_LEN     (16383U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates interrupt configurations for channel. */
typedef enum cpswChIntr
{
    CPSW_CH_INTR_NONE     = 0x00U,
    /**< Receive threshold interrupt. */
    CPSW_CH_INTR_RX_THR   = (0x1U << 0x0U),
    /**< Receive threshold interrupt. */
    CPSW_CH_INTR_RX       = (0x1U << 0x1U),
    /**< Receive interrupt. */
    CPSW_CH_INTR_TX       = (0x1U << 0x2U)
    /**< Transmit interrupt. */
}cpswChIntr_t;

/** \brief Enumerates channel bus configuration for rate limit configuration. */
typedef enum cpswCpdmaTxRateLimitChBus
{
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_NONE     = 0x00U,
    /**< No channel configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7        = 0x80U,
    /**< Channel7 configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7_TO_6   = 0xC0U,
    /**< Channels 7 to 6 configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7_TO_5   = 0xE0U,
    /**< Channels 7 to 5 configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7_TO_4   = 0xF0U,
    /**< Channels 7 to 4 configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7_TO_3   = 0xF8U,
    /**< Channels 7 to 3 configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7_TO_2   = 0xFCU,
    /**< Channels 7 to 2 configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7_TO_1   = 0xFEU,
    /**< Channels 7 to 1 configured for rate limit. */
    CPSW_CPDMA_TX_RATE_LIMIT_CH_BUS_7_TO_0   = 0xFFU,
    /**< All Channels configured for rate limit. */
}cpswCpdmaTxRateLimitChBus_t;

/** \brief Enumerates interrupt configurations for channel. */
typedef enum cpswWrIntrLine
{
    CPSW_WR_INTR_LINE_NONE     = 0x0U,
    /**< None. */
    CPSW_WR_INTR_LINE_RX_THR   = 0x1U,
    /**< Receive threshold interrupt. */
    CPSW_WR_INTR_LINE_RX       = 0x2U,
    /**< Receive interrupt. */
    CPSW_WR_INTR_LINE_TX       = 0x3U,
    /**< Transmit interrupt. */
    CPSW_WR_INTR_LINE_MISC     = 0x4U
    /**< Miscellaneous interrupt. */
}cpswWrIntrLine_t;

/** \brief Enumerates interrupt configurations for channel. */
typedef enum cpswWrMiscIntr
{
    CPSW_WR_MISC_INTR_NONE     = 0x00U,
    /**< None. */
    CPSW_WR_MISC_INTR_EVT_PEND = CPSW_WR_C_MISC_EN_EVT_PEND,
    /**< Receive threshold interrupt. */
    CPSW_WR_MISC_STS_PEND      = CPSW_WR_C_MISC_EN_STS_PEND,
    /**< Receive interrupt. */
    CPSW_WR_MISC_HOST_PEND     = CPSW_WR_C_MISC_EN_HOST_PEND,
    /**< Transmit interrupt. */
    CPSW_WR_MISC_MDIO_LINK     = CPSW_WR_C_MISC_EN_MDIO_LINK,
    /**< Transmit interrupt. */
    CPSW_WR_MISC_MDIO_USER     = CPSW_WR_C_MISC_EN_MDIO_USER
    /**< Transmit interrupt. */
}cpswWrMiscIntr_t;

/** \brief Enumerates error codes to indicate error generated by CPDMA host. */
typedef enum cpswCpdmaErrCode
{
    CPSW_CPDMA_ERR_CODE_NONE         = 0x0U,
    /**< No error. */
    CPSW_CPDMA_ERR_CODE_SOP          = 0x1U,
    /**< SOP error. */
    CPSW_CPDMA_ERR_CODE_OWN_SOP      = 0x2U,
    /**< Ownership bit not set in SOP buffer. */
    CPSW_CPDMA_ERR_CODE_ZERO_BD      = 0x3U,
    /**< Zero Next Buffer Descriptor Pointer Without EOP. */
    CPSW_CPDMA_ERR_CODE_ZERO_BUF_PTR = 0x4U,
    /**< Zero Buffer Pointer. */
    CPSW_CPDMA_ERR_CODE_ZERO_BUF_LEN = 0x5U,
    /**< Zero Buffer Length. */
    CPSW_CPDMA_ERR_CODE_PCKT_LEN     = 0x6U
    /**< Packet Length Error (sum of buffers is less than packet length). */
}cpswCpdmaErrCode_t;

/** \brief Enumerates port transmit FIFO input queue operating modes. */
typedef enum cpswPortTxInputSel
{
    CPSW_PORT_TX_INPUT_SEL_NORMAL     = 0x0U,
    /**< Port transmit FIFO input queue in normal priority mode. */
    CPSW_PORT_TX_INPUT_SEL_DUAL_MAC   = 0x1U,
    /**< Port transmit FIFO input queue in DUAL MAC mode. */
    CPSW_PORT_TX_INPUT_SEL_RATE_LIMIT = 0x2U
    /**< Port transmit FIFO input queue in rate limit mode. */
}cpswPortTxInputSel_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API resets the CPSW.
 *
 * \param   baseAddr    Base address of the CPSW.
 * \param   noOfPort    Number of slave ports.
 */
void CPSWReset(uint32_t baseAddr, uint32_t noOfPort);

/**
 * \brief   This API resets the CPSW Subsystem module.
 *
 * \param   baseAddr Base address of the CPSW.
 */
void CPSWSsReset(uint32_t baseAddr);

/**
 * \brief   This API resets the CPSW Sliver Logic.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 */
void CPSWSlReset(uint32_t baseAddr, uint32_t slavePortNum);

/**
 * \brief   This API resets the CPSW Wrapper module.
 *
 * \param   baseAddr Base address of the CPSW.
 */
void CPSWWrReset(uint32_t baseAddr);

/**
 * \brief   This API resets the CPDMA module.
 *
 * \param   baseAddr Base address of the CPDMA.
 */
void CPSWCpdmaReset(uint32_t baseAddr);

/**
 * \brief   This API configures the CPGMAC of sliver if the input gmii_mt_clk
 *          has been stopped by the PHY.
 *
 * \param   baseAddr     Base address of the CPSW Sliver Module registers.
 * \param   slavePortNum Slave port number.
 * \param   forceGigMode Configure CPGMAC of sliver if the input gmii_mt_clk has
 *                       been stopped by the PHY.
 *                       -# TRUE   Force into gigabit mode.
 *                       -# FALSE  Do not force into gigabit mode.
 */
void CPSWSlForceExtGigbitMode(uint32_t baseAddr,
                              uint32_t slavePortNum,
                              uint32_t forceGigMode);

/**
 * \brief   This API configures the operating mode of the sliver.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 * \param   enableInband Configure the mode of operation of sliver.
 *                        -# TRUE  Enables the fullduplex and gigabit mode to be
 *                                 selected from the FULLDUPLEX_IN and GIG_IN
 *                                 input signals and not from the fullduplex
 *                                 and gig bits in this register.
 *                        -# FALSE The fullduplex and gigabit mode is selected
 *                                 from the fullduplex (FULLDUPLEX) and
 *                                 gigabits (GIG) in this register.
 */
void CPSWSlCtrlInbandEnable(uint32_t baseAddr,
                            uint32_t slavePortNum,
                            uint32_t enableInband);

/**
 * \brief   This API configures the transfer speed of the sliver to gigabit or
 *          non-gigabit mode.
 *
 * \param   baseAddr      Base address of the CPSW.
 * \param   slavePortNum  Slave port number.
 * \param   enableGigMode Configure transfer speed mode of sliver.
 *                        -# TRUE  Gigabit speed mode.
 *                        -# FALSE 10/100 speed mode.
 */
void CPSWSlGigModeEnable(uint32_t baseAddr,
                         uint32_t slavePortNum,
                         uint32_t enableGigMode);

/**
 * \brief   This API sets the transfer duplex mode of the sliver.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 * \param   duplexMode   The transfer duplex mode of sliver takes values from
 *                       #ethernetDuplexMode_t.
 */
void CPSWSlSetDuplexMode(uint32_t baseAddr,
                         uint32_t slavePortNum,
                         uint32_t duplexMode);

/**
 * \brief   This API configures the sliver to enable GMII for gigabit mode.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 * \param   enableGmii   Configure GMII RX and TX.
 *                       -# TRUE  - GMII RX and TX held reset.
 *                       -# FALSE - GMII RX and TX released from reset.
 *
 * \note    To configure the sliver in gigabit mode, GMII has to be enabled.
 */
void CPSWSlGmiiEnable(uint32_t baseAddr,
                      uint32_t slavePortNum,
                      uint32_t enableGmii);

/**
 * \brief   This API configures the RMII input speed of slover to either 10Mbps
 *          or 100Mbps operation.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 * \param   rmiiSpeed    Configure the RMII speed input for.
 *                       -# #ETHERNET_SPEED_10  - 10 Mbps operation.
 *                       -# #ETHERNET_SPEED_100 - 100 Mbps operation.
 */
void CPSWSetSlRmiiSpeed(uint32_t baseAddr,
                        uint32_t slavePortNum,
                        uint32_t rmiiSpeed);

/**
 * \brief   This API checks the external speed status of sliver is gigabit or
 *          non-gigabyte (10/100 Mbps) for in-band mode of operation.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 *
 * \retval  TRUE         External input speed is gigabit.
 * \retval  FALSE        External input speed is non gigabit.
 *
 * \note    The status is valid only for in-band mode of operation.
 */
uint32_t CPSWSlIsExtSpeedGigabit(uint32_t baseAddr, uint32_t slavePortNum);

/**
 * \brief   This API check the external duplex status is Half/Full for in-band
 *          mode of operation.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 *
 * \retval  TRUE         External input is full duplex.
 * \retval  FALSE        External input is half duplex.
 *
 * \note    The status is valid only for in-band mode of operation.
 */
uint32_t CPSWSlIsExtFullDuplex(uint32_t baseAddr, uint32_t slavePortNum);

/**
 * \brief   This API checks if the sliver is in idle state.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 *
 * \retval  TRUE         Sliver is in the idle mode.
 * \retval  FALSE        Sliver is not in the idle mode.
 */
uint32_t CPSWSlIsMacIdle(uint32_t baseAddr, uint32_t slavePortNum);

/**
 * \brief   This API sets the maximum length for received frame in sliver.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 * \param   rxMaxLen     Maximum length for a received frame. The default value
 *                       for 'rxMaxLen' is 1518. The maximum value which can be
 *                       set is 16383.
 */
void CPSWSetSlRxMaxLen(uint32_t baseAddr,
                       uint32_t slavePortNum,
                       uint32_t rxMaxLen);

/**
 * \brief   This API enables RX, TX or RX threshold interrupts of a channel. It
 *          configures given interrupt core interfaced to processor.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   intrCore     Interrupt core number interfaced with the processor.
 * \param   chNum        Channel number to be enabled.
 * \param   chIntrMask   Interrupts to be enabled on the given channel of core.
 *                       It takes mask of values #cpswChIntr_t.
 */
void CPSWWrChIntrEnable(uint32_t baseAddr,
                        uint32_t intrCore,
                        uint32_t chNum,
                        uint32_t chIntrMask);

/**
 * \brief   This API enables miscellaneous interrupts. It configures given
 *          interrupt core in wrapper module interfaced to processor.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   intrCore     Interrupt core number interfaced with the processor.
 * \param   miscIntrMask Interrupts to be enabled on the given core. It takes
 *                       mask of values #cpswWrMiscIntr_t.
 */
void CPSWWrMiscIntrEnable(uint32_t baseAddr,
                          uint32_t intrCore,
                          uint32_t miscIntrMask);

/**
 * \brief   This API disables RX, TX or RX threshold interrupts of a channel. It
 *          configures given interrupt core in wrapper module interfaced to
 *          processor.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   intrCore     Interrupt core number interfaced with the processor.
 * \param   chNum        Channel number to be disabled.
 * \param   chIntrMask   Interrupts to be disabled on the given channel of core.
 *                       It takes mask of values #cpswChIntr_t.
 */
void CPSWWrChIntrDisable(uint32_t baseAddr,
                         uint32_t intrCore,
                         uint32_t chNum,
                         uint32_t chIntrMask);

/**
 * \brief   This API disables miscellaneous interrupts. It configures given
 *          interrupt core in wrapper module interfaced to processor.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   intrCore     Interrupt core number interfaced with the processor.
 * \param   miscIntrMask Interrupts to be disabled on the given core. It takes
 *                       mask of values #cpswWrMiscIntr_t.
 */
void CPSWWrMiscIntrDisable(uint32_t baseAddr,
                           uint32_t intrCore,
                           uint32_t miscIntrMask);

/**
 * \brief   This API gives status given channel interrupt of all channels for
 *          given interrupt core in wrapper module interfaced to processor.
 *
 * \param   baseAddr       Base address of the CPSW.
 * \param   intrCore       Interrupt core number interfaced with the processor.
 * \param   chIntr         Channel interrupt line takes values #cpswChIntr_t.
 *
 * \retval  status         Given interrupt status of all channels.
 */
uint32_t CPSWWrchIntrStatus(uint32_t baseAddr,
                            uint32_t intrCore,
                            uint32_t chIntr);

/**
 * \brief   This API gives status for miscellaneous interrupts of given
 *          interrupt core in wrapper module interfaced to processor.
 *
 * \param   baseAddr       Base address of the CPSW.
 * \param   intrCore       Interrupt core number interfaced with the processor.
 *
 * \retval  miscIntrStatus Status of all miscellaneous interrupts.
 *
 * \note    To get status of specific miscellaneous use the values from
 *          #cpswWrMiscIntr_t.
 */
uint32_t CPSWWrMiscIntrStatus(uint32_t baseAddr, uint32_t intrCore);

/**
 * \brief   This API gives speed of CPRGMII in in-band mode for given slave port.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 *
 * \retval  speed        Speed of CPRGMII in in-band mode return possible values
 *                       from #ethernetSpeed_t.
 */
uint32_t CPSWGetWrRgmiiInbandSpeed(uint32_t baseAddr, uint32_t slavePortNum);

/**
 * \brief   This API gives duplex mode of CPRGMII in in-band mode for given
 *          slave port.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 *
 * \retval  duplex       Duplex mode of CPRGMII in in-band mode return possible
 *                       values from #ethernetDuplexMode_t.
 */
uint32_t CPSWGetWrRgmiiInbandDuplexMode(uint32_t baseAddr,
                                        uint32_t slavePortNum);

/**
 * \brief   This API gives link status of CPRGMII in in-band mode for given
 *          slave port.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   slavePortNum Slave port number.
 *
 * \retval  TRUE         Link is UP.
 * \retval  FALSE        Link is Down.
 */
uint32_t CPSWWrRgmiiInbandLinkStatus(uint32_t baseAddr, uint32_t slavePortNum);

/**
 * \brief   This API enables/disables the receive flow control for a given port
 *          in CPSW system.
 *
 * \param   baseAddr         Base Address of the CPSW.
 * \param   portNum          Port number.
 * \param   enableRxFlowCtrl Flow control configuration for a port takes
 *                           -# TRUE  - Enable flow control.
 *                           -# FALSE - Disable flow control.
 */
void CPSWSsRxFlowCtrlEnable(uint32_t baseAddr,
                            uint32_t portNum,
                            uint32_t enableRxFlowCtrl);

/**
 * \brief   This API enables/disables the software idle mode, causing the switch
 *          fabric to stop forward packets at the next start of packet.
 *
 * \param   baseAddr     Base Address of the CPSW.
 * \param   enableSwIdle Software idle configuration takes
 *                       -# TRUE  - Enable idle mode.
 *                       -# FALSE - Disable idle mode.
 */
void CPSWSsSwIdleEnable(uint32_t baseAddr, uint32_t enableSwIdle);

/**
 * \brief   This API enables/disables the CPSW statistics for the given port
 *
 * \param   baseAddr    Base Address of the CPSW.
 * \param   portNum     The port number.
 * \param   enableStats Statistics configuration for a port takes
 *                      -# TRUE  - Enable statistics on the given port.
 *                      -# FALSE - Disable statistics on the given port.
 */
void CPSWSsStatsEnable(uint32_t baseAddr,
                       uint32_t portNum,
                       uint32_t enableStats);

/**
 * \brief   This API enables/disables the VLAN aware mode for CPSW.
 *
 * \param   baseAddr        Base Address of the CPSW.
 * \param   enableVlanAware VLAN Aware configuration takes following
 *                          -# TRUE  - CPSW is in the VLAN aware mode.
 *                          -# FALSE - CPSW is in the VLAN unaware mode.
 */
void CPSWSsVlanAwareEnable(uint32_t baseAddr, uint32_t enableVlanAware);

/**
 * \brief   This API configures the MAC address of the slave port.
 *
 * \param   baseAddr     Base address of the CPSW Port Module registers
 * \param   slavePortNum Slave port number.
 * \param   pMacAddr     The 6 byte MAC address.
 */
void CPSWSetPortSrcAddr(uint32_t baseAddr,
                        uint32_t slavePortNum,
                        uint8_t *pMacAddr);

/**
 * \brief   This API configures the host port for Dual MAC mode.
 *
 * \param   baseAddr          Base Address of the CPSW.
 * \param   enableDualMacMode DUAL MAC mode configuration takes
 *                            -# TRUE  - CPSW as DUAL MAC mode.
 *                            -# FALSE - CPSW as non DUAL MAC mode.
 */
void CPSWHostPortDualMacModeEnable(uint32_t baseAddr,
                                   uint32_t enableDualMacMode);

/**
 * \brief   This API configures Port VLAN.
 *
 * \param   baseAddr Base address of the CPSW.
 * \param   portNum  Port number.
 * \param   vlanId   VLAN ID of port.
 * \param   cfiBit   CFI bit of port.
 * \param   vlanPri  VLAN priority of port.
 */
void CPSWPortVlanConfig(uint32_t baseAddr,
                        uint32_t portNum,
                        uint32_t vlanId,
                        uint32_t cfiBit,
                        uint32_t vlanPri);

/**
 * \brief   This API enables the transfer interrupt for given channel.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   chNum        Channel number for which interrupt to be enabled.
 * \param   chIntrMask   Interrupt configuration mask of channel takes values
 *                       #cpswChIntr_t.
 */
void CPSWCpdmaChIntrEnable(uint32_t baseAddr,
                           uint32_t chNum,
                           uint32_t chIntrMask);

/**
 * \brief   This API disables the transfer interrupt for given channel.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   chNum        Channel number for which interrupt to be disabled
 * \param   chIntrMask   Interrupt configuration mask of channel takes values
 *                       #cpswChIntr_t.
 */
void CPSWCpdmaChIntrDisable(uint32_t baseAddr,
                            uint32_t chNum,
                            uint32_t chIntrMask);

/**
 * \brief   This API enables the transfer. Any write to hardware descriptor of
 *          a channel will start transfer.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   xferMode Transfer mode takes values #ethernetXferMode_t.
 */
void CPSWCpdmaXferEnable(uint32_t baseAddr, uint32_t xferMode);

/**
 * \brief   This API disables the transfer.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   xferMode Transfer mode mask takes values #ethernetXferMode_t.
 */
void CPSWCpdmaXferDisable(uint32_t baseAddr, uint32_t xferMode);

/**
 * \brief   This API writes the transfer HDP register. If transfer is enabled,
 *          write to the transfer HDP will immediately start transfer.
 *          The data will be taken from the buffer pointer of the transfer buffer
 *          descriptor written to the transfer HDP.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   xferMode Transfer type.
 * \param   descHdr  Address of the transfer buffer descriptor.
 * \param   chNum    Channel Number.
 */
void CPSWCpdmaXferHdrDescPtrWrite(uint32_t baseAddr,
                                  uint32_t xferMode,
                                  uint32_t descHdr,
                                  uint32_t chNum);

/**
 * \brief   This API writes the the transfer Completion Pointer for a specific
 *          channel.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   xferMode Transfer type.
 * \param   chNum    Channel Number.
 * \param   comPtr   Completion Pointer Value to be written.
 */
void CPSWCpdmaXferCpWrite(uint32_t baseAddr,
                          uint32_t xferMode,
                          uint32_t chNum,
                          uint32_t comPtr);

/**
 * \brief   This API writes the interrupt line number to End Of Interrupt Vector.
 *
 * \param   baseAddr      Base Address of the CPDMA module registers.
 * \param   intrLine      Type of interrupt to acknowledge to the CPDMA from
 *                        interrupt lines #cpswWrIntrLine_t.
 */
void CPSWCpdmaWriteEoiVector(uint32_t baseAddr, uint32_t intrLine);

/**
 * \brief   This API sets the free buffers for a specific channel.
 *
 * \param   baseAddr   Base Address of the CPSW.
 * \param   chNum      Channel Number.
 * \param   numFreeBuf Number of free buffers.
 */
void CPSWSetCpdmaNumFreeBuf(uint32_t baseAddr,
                            uint32_t chNum,
                            uint32_t numFreeBuf);

/**
 * \brief   This API checks if the CPDMA is in idle state.
 *
 * \param   baseAddr   Base Address of the CPSW.
 *
 * \retval  TRUE       CPDMA is in idle state.
 * \retval  FALSE      CPDMA is not in idle state.
 */
uint32_t CPSWIsCpdmaIdle(uint32_t baseAddr);

/**
 * \brief   Returns the CPDMA Status.
 *
 * \param   baseAddr    Base Address of the CPSW.
 * \param   xferMode    Transfer mode takes values #ethernetXferMode_t.
 *
 * \retval  errCodeMask CPDMA transfer error status code returns values
 *                      #cpswCpdmaErrCode.
 */
uint32_t CPSWGetCpdmaHostErrorCode(uint32_t baseAddr, uint32_t xferMode);

/**
 * \brief   This API returns the channel number on which error occurred.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   xferMode Transfer mode takes values #ethernetXferMode_t.
 *
 * \retval  chNum    Channel number on which error occurred.
 */
uint32_t CPSWGetCpdmaHostErrorCh(uint32_t baseAddr, uint32_t xferMode);

/**
 * \brief   This API configures the transmit rate limit channel bus of CPDMA
 *          module.
 *
 * \param   baseAddr       Base Address of the CPSW.
 * \param   rateLimitChBus CPDMA channel bus for rate limit takes values
 *                         #cpswCpdmaTxRateLimitChBus_t.
 **/
void CPSWCpdmaTxRateLimitChBusConfig(uint32_t baseAddr, uint32_t rateLimitChBus);

/**
 * \brief   This API enable/disable the idle mode for CPDMA. When enabled idle,
 *          the CPSW stops all the reception and transmission. However,
 *          if receiving the current frame will be received completely before
 *          going to the idle state. Also, while transmitting, the contents in
 *          the fifo will be sent fully.
 *
 * \param   baseAddr        Base Address of the CPSW.
 * \param   enableCpdmaIdle Take values
 *                          -# TRUE  - Enable CPDMA Idle.
 *                          -# FALSE - Disable CPDMA Idle.
 */
void CPSWCpdmaIdleEnable(uint32_t baseAddr, uint32_t enableCpdmaIdle);

/**
 * \brief   This API sets the RX buffer offset value. The RX buffer offset will
 *          be written by the port into each frame SOP buffer descriptor
 *          buffer_offset field. The frame data will begin after the
 *          rx_buffer_offset value of bytes. This value will be used for
 *          all the channels .
 *
 * \param   baseAddr      Base Address of the CPSW.
 * \param   bufOffset     Buffer offset value.
 */
void CPSWSetCpdmaRxBufOffset(uint32_t baseAddr, uint32_t bufOffset);

/**
 * \brief   This API returns the status of given interrupt for all channels.
 *
 * \param   baseAddr Base address of the CPSW.
 * \param   chIntr   Channel interrupt configuration takes values #cpswChIntr_t.
 *
 * \retval  intrStatus Interrupt status for all channels.
 */
uint32_t CPSWCpdmaChIntrStatus(uint32_t baseAddr, uint32_t chIntr);

/**
 * \brief   This API returns the raw status of given interrupt for all channels.
 *
 * \param   baseAddr Base address of the CPSW.
 * \param   chIntr   Channel interrupt configuration takes values #cpswChIntr_t.
 *
 * \retval  intrStatus Raw interrupt status for all channels.
 */
void CPSWCpdmaChIntrRawStatus(uint32_t baseAddr, uint32_t chIntr);

/**
 * \brief   This API reads a PHY register using MDIO.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   phyAddr  PHY Address.
 * \param   regNum   Register Number to be read.
 * \param   pData    Pointer where the read value shall be written.
 *
 * \retval  TRUE     Read is successful.
 * \retval  FALSE    Read is not acknowledged properly.
 */
void CPSWMdioPhyRegRead(uint32_t baseAddr,
                        uint32_t phyAddr,
                        uint32_t regNum,
                        uint16_t *pData);

/**
 * \brief   This API writes a PHY register using MDIO.
 *
 * \param   baseAddr      Base Address of the CPSW.
 * \param   phyAddr       PHY Address.
 * \param   regNum        Register Number to be written.
 * \param   wrVal         Value to be written.
 */
void CPSWMdioPhyRegWrite(uint32_t baseAddr,
                         uint32_t phyAddr,
                         uint32_t regNum,
                         uint16_t wrVal);

/**
 * \brief   This API reads the alive status of all PHY connected to this MDIO.
 *          The bit corresponding to the PHY address will be set if the PHY
 *          is alive.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   phyAddr       PHY Address.
 *
 * \retval  TRUE   PHY is present.
 * \retval  FALSE  PHY is not present.
 */
uint32_t CPSWMdioPhyAliveStatus(uint32_t baseAddr, uint32_t phyAddr);

/**
 * \brief   This API reads the link status of all PHY connected to this MDIO.
 *          The bit corresponding to the PHY address will be set if the PHY
 *          link is active.
 *
 * \param   baseAddr Base Address of the CPSW.
 * \param   phyAddr  PHY Address.
 *
 * \retval  TRUE   PHY link is active.
 * \retval  FALSE  PHY link is inactive.
 */
uint32_t CPSWMdioPhyLinkStatus(uint32_t baseAddr, uint32_t phyAddr);

/**
 * \brief   This API initializes the MDIO peripheral. This enables the MDIO state
 *          machine, uses standard pre-amble and set the clock divider value.
 *
 * \param   baseAddr       Base Address of the CPSW.
 * \param   mdioInputFreq  The clock input to the MDIO module.
 * \param   mdioOutputFreq The clock output required on the MDIO bus.
 */
void CPSWMdioInit(uint32_t baseAddr,
                  uint32_t mdioInputFreq,
                  uint32_t mdioOutputFreq);

/* ========================================================================== */
/*                        Deprecated Function Declarations                    */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef CPSW_H_ */
