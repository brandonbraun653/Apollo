/**
 * @file   emac_soc.h
 *
 * @brief  EMAC SoC level driver
 */
/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EMAC_SOC_V4__H
#define EMAC_SOC_V4__H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/csl/csl_utils.h>
#include <ti/osal/osal.h>


#define EMAC_NUM_MAX_MAC_PORTS 2U


/**
 *  \defgroup   macModeFlags Configuration Mode Flags
 *
 */
#define EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX      ((uint32_t)0x00001U)
/**< Set full duplex mode                                                   */
#define EMAC_CPSW_CONFIG_MODEFLG_GIGABIT         ((uint32_t)0x00002U)
/**< Set gigabit                                                            */
#define EMAC_CPSW_CONFIG_MODEFLG_IFCTLA          ((uint32_t)0x00004U)
/**< Enable IFCTL_A                                                         */

/**< Default setting for max number of of receive packet interrupts per millisecond*/
#define EMAC_RX_ISR_PER_MSEC_DEFAULT 2U

/*!
 *  @brief  EMAC Hardware attributes for AM57x
 */

typedef struct EMAC_CpswPorts_s{
    uint32_t port_base;
    uint32_t sliver_base;
    uint32_t phy_addr;

}EMAC_CpswPorts;


/**<
 *  @brief  EMAC Hardware attributes for AM57x
 *  The status structure contains information about the Base addresses
 *  for different registers and additional config parameters
 */

typedef struct EMAC_HwAttrs_V4_s {
    /**< GMAC SW  sub-system(ss) register base address */
    uint32_t ss_base;
    /**< GMAC SW MDIO register base address */
    uint32_t mdio_base;
    /**< GMAC SW wrapper register base address */
    uint32_t wrpr_base;
    /**< GMAC SW ale register base address */
    uint32_t ale_base;
    /**< GMAC SW cpdma register base address */
    uint32_t cpdma_base;
    /**< GMAC CPPI ram base address which is used for allocation of hardware cppi descriptors used by LLD
            NOTE: that this can be changed by application to use un-cached DDR memory */
    uint32_t cppi_ram_base;
    /**< GMAC SW port register base address */
    uint32_t host_port_base;
    /**< GMAC SW statistics register base address */
    uint32_t stat_base;
    /**< GMAC SW receive packet interrupt number*/
    uint32_t rxIntrNum;
    /**< GMAC SW receive packet  event ID*/
    uint32_t rxEventId;
    /**< GMAC SW transmit packet interrupt number*/
    uint32_t txIntrNum;
    /**< GMAC SW transmit packet  event ID*/
    uint32_t txEventId;
    /**< Bitmap of MAC configuration mode flags */
    uint32_t macModeFlags;
    /**< Number of emac ports */
    uint32_t numPorts;
    /**< Number of rx Interrupts per millisecond */
    uint32_t rxInterruptPerMSec;
    /**< Slave port information */
    EMAC_CpswPorts port[EMAC_NUM_MAX_MAC_PORTS];
}EMAC_HwAttrs_V4;




int32_t EMAC_socGetInitCfg(uint32_t port_num, EMAC_HwAttrs_V4 *cfg);

int32_t EMAC_socSetInitCfg(uint32_t port_num, const EMAC_HwAttrs_V4 *cfg);

#ifdef __cplusplus
}
#endif

#endif /* EMAC_SOC_V1__H */

