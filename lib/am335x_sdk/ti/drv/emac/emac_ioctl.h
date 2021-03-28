/********************************************************************
 * Copyright (C) 2018-2020 Texas Instruments Incorporated.
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
 *  @file       emac_ioctl.h
 *
 *  @brief      EMAC driver IOCTL API inteface specification
 *  @note       IOCTL API is only supported for am65xx SOC
 *
 *  This API header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/emac/emac_ioctl.h>
 *  @endcode
 *
 */

#ifndef EMAC_IOCTL_H
#define EMAC_IOCTL_H

#include <ti/drv/emac/emac_drv.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @cond NODOC
 *  Internally used by the driver, used for classifier config
 */
#define EMAC_NUM_CLASSIFIERS    ((uint32_t)16U)
#define EMAC_CLASS_CFG1_OFF     (CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0-CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_AND_EN_PRU0) 
#define EMAC_CLASS_CFG2_OFF     ((uint32_t)4U) /* from EMAC_CLASS_CFG1_OFF */
#define EMAC_CLASS_GATE_OFF     ((uint32_t)8U) /* from EMAC_CLASS_CFG1_OFF */

#define EMAC_CLASS_AND_EN_OFF                     ((uint32_t)0U)
#define EMAC_CLASS_OR_EN_OFF                      ((uint32_t)4U)
#define EMAC_IOCTL_PRIO_MAX                       ((uint32_t)8U)
#define EMAC_FW_MGMT_CMD_HEADER                   ((uint32_t)0x81U)
#define EMAC_FW_MGMT_FDB_CMD_TYPE                 ((uint32_t)0x03U)
#define EMAC_FW_MGMT_SPEED_DUPLEXITY_CMD_TYPE     ((uint32_t)0x02U)

#define EMAC_FW_MGMT_CMD_TYPE           ((uint32_t)0x04U)
#define EMAC_FW_MGMT_PKT                ((uint32_t)0x80000000u)
/*! @endcond */

/*!
 *  @cond NODOC
 *  Internally used by the driver for filter 3 configuration
 */
typedef struct EMAC_FILTER3_CONFIG_S
{
    uint32_t ft3Start;
    uint32_t ft3StartAuto;
    uint32_t ft3StartOffset;
    uint32_t ft3JmpOffset;
    uint32_t ft3Len;
    uint32_t ft3Config;
    uint32_t ft3Type;
    uint32_t ft3TypeMask;
    uint32_t ft3PatternLow;
    uint32_t ft3PatternHigh;
    uint32_t ft3PatternMaskLow;
    uint32_t ft3PatternMaskHigh;
} EMAC_FILTER3_CONFIG;
/*! @endcond */

/*!
 *  @cond NODOC
 *  Internally used by the driver, used to send CMD to ICSSG FW
 */

/* local to the driver, used to send CMD to ICSSG FW*/
typedef struct EMAC_IOCTL_CMD_S {
    /* Optional parameter for TX to FW, ERROR code for RX from FW */
    uint8_t              commandParam;
    uint8_t              seqNumber;
    /* Command Type */
    uint8_t               commandType;
    /* Command Header */
    uint8_t commandHeader;
    uint32_t              spare[3];
} __attribute__((packed)) EMAC_IOCTL_CMD_T;
/*! @endcond */

/**
 * @brief Max number of entries in VLAN TABLE
 */
#define EMAC_VLAN_TBL_MAX_ENTRIES ((uint32_t)4096U)

/**
 *  @defgroup  EMAC_IOCTL_VLAN_CTRL Vlan Control sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_VLAN_CTRL sub-commands
 *  @details The following macros are sub-commands that to be used when issueing
 *  emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_VLAN_CTRL
 *
 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_VLAN_SET_DEFAULT_TBL
 *        Populate VLAN table with default vlan entry configuration
 */
#define EMAC_IOCTL_VLAN_SET_DEFAULT_TBL                 ((uint32_t)1U)

/**
 *  @def  EMAC_IOCTL_VLAN_SET_ENTRY
 *        Update a VLAN TABLE entry
 */
#define EMAC_IOCTL_VLAN_SET_ENTRY                       ((uint32_t)2U)

/**
 *  @def  EMAC_IOCTL_VLAN_SET_DEFAULT_VLAN_ID
 *        Sets the default VLAN id for specified switch/host port
 */
#define EMAC_IOCTL_VLAN_SET_DEFAULT_VLAN_ID             ((uint32_t)3U)

/**
 *  @def  EMAC_IOCTL_VLAN_GET_ENTRY
 *        Get vlan entry from vlan table for requested vlan id
 */
#define EMAC_IOCTL_VLAN_GET_ENTRY                        ((uint32_t)4U)

/*@}*/
/** @} */


/**
 * @brief VLAN FID entry parameters definition for EMAC_IOCTL_VLAN_SET_DEFAULT_TBL sub-command
 */
typedef struct EMAC_IOCTL_VLAN_FID_PARAMS_S {
    uint8_t fid;
    /**< filtering identifier field, this 8 bit field is included in SA and DA hashes as part of FDB function */
    uint8_t hostMember;
    /**< if set, forward to the host port */
    uint8_t p1Member;
    /**< if set, forware to physical port 1 of the switch */
    uint8_t p2Member;
    /**< if set, forware to physical port 2 of the switch */
    uint8_t hostTagged;
    /**< if set, VLAN tag should be added to host port packet being transmitted, if not set, then strip VLAN tag*/
    uint8_t p1Tagged;
    /**< if set, VLAN tag should be added to phsyical port 1 packet being transmitted, if not set, then strip VLAN tag*/
    uint8_t p2Tagged;
    /**< if set, VLAN tag should be added to physical port 2 packet being transmitted, if not set, then strip VLAN tag*/
    uint8_t streamVid;
    /**< if set, VLAN is part of stream FDB, Bypass UC/MC FDB */
    uint8_t floodToHost;
    /**< if set, send un-registered MC packet to host port*/
}EMAC_IOCTL_VLAN_FID_PARAMS;

/**
 * @brief VLAN FID table entry definition for EMAC_IOCTL_VLAN_SET_ENTRY sub-command
 */
typedef struct EMAC_IOCTL_VLAN_FID_ENTRY_S {
        uint16_t vlanId;
        /**< Index into VLAN fid table, range from 0 to 4095 entries */
        EMAC_IOCTL_VLAN_FID_PARAMS vlanFidPrams;
        /**<VLAN fid configuration srtructuure, @ref EMAC_IOCTL_VLAN_FID_PARAMS*/
} EMAC_IOCTL_VLAN_FID_ENTRY;

/**
 * @brief Default VLAN entry definition for @ref EMAC_IOCTL_VLAN_SET_DEFAULT_VLAN_ID sub-command
 * @details Used to configure default vlan entry for 
 * EMAC_SWITCH_PORT0 and EMAC_SWITCH_PORT1 and EMAC_SWITCH_PORT0
 */
typedef struct EMAC_IOCTL_VLAN_DEFAULT_ENTRY_S {
    uint16_t vlanId;
    /**< default VLAN ID, range from 0 to 4095 entries */
    uint8_t pcp;
    /**< priority point code for default VLAN ID entry, range from 0 to 7 */
} EMAC_IOCTL_VLAN_DEFAULT_ENTRY;

/**
 * @brief Port Priority configuration structure
 * @details This arrary is used to map differnt PCP values (0-7)
 * to 1 of 8 host/port queues.
 */
typedef struct EMAC_IOCTL_PORT_PRIO_MAP_S {
    uint8_t portPrioMap[EMAC_IOCTL_PRIO_MAX];
    /**< Specifies mapping of 8 different PCP to 8 port queues/flow, eg portPrioMap[2] = 5 
         implies that any packet received with pcp value of 2 will be placed in port queue/flow 5.*/
}EMAC_IOCTL_PORT_PRIO_MAP;

/**
 * @brief Priority regen configuration structure
 * @details This 8 byte array is used to configure the priority regeneration table
 * for boundary ports.
 */
typedef struct EMAC_IOCTL_PRIO_REGEN_MAP_S {
    uint8_t prioRegenMap[EMAC_IOCTL_PRIO_MAX];
} EMAC_IOCTL_PRIO_REGEN_MAP;

/**
 * @brief pcp to prempt or cut through configuration structure
 * @details These arrary is used to map differnt PCP values (0-7)
 * to premption or cut through.
 */
typedef struct EMAC_IOCTL_PREMPT_OR_CUT_THROUGH_MAP_S {
    uint8_t pcpPreemptMap[EMAC_IOCTL_PRIO_MAX];
    /**< Specifies mapping of 8 different PCP to preemption mapping.
         Bit 7 determines if it will be cut-through. Set 1 for cut-through*/
    uint8_t pcpCutThroughMap[EMAC_IOCTL_PRIO_MAX];
    /**< Specifies mapping of 8 different PCP to cut through mapping
         bit 4 of the byte determines if packet will be pre-emptive on transmit.Set 1 for pre-emptive*/
}EMAC_IOCTL_PREMPT_OR_CUT_THROUGH_MAP;

/**
 * @brief proirity for special frames configuration structure
 * @details priority values possible(0-7)
 */
typedef struct EMAC_IOCTL_SPECIAL_FRAME_DEFAULT_PRIO_S {
    uint8_t specialFramePrio;
    /**< Specifies mapping of special frames to a priority
         priority values possible(0-7)*/
}EMAC_IOCTL_SPECIAL_FRAME_DEFAULT_PRIO;

/**
 * @brief FDB Ageing interval
 * @details Value is in nanoseconds
 */
typedef struct EMAC_IOCTL_FDB_AGEING_INTERVAL_S {
    uint64_t fdbAgeingInterval;
    /**< Specifies FDB ageing interval in nanoseconds*/
}EMAC_IOCTL_FDB_AGEING_INTERVAL;

typedef enum Preempt_Verify_States_E{
    STATE_UNKNOWN = 0,
    STATE_INITIAL,
    STATE_VERIFYING,
    STATE_SUCCEEDED,
    STATE_FAILED,
    STATE_DISABLED
} Preempt_Verify_States;

/**
 * @brief proirity for frame premption configuration structure
 * @details it will be input param for premtion ioctl.
 */
typedef struct EMAC_IOCTL_PREEMPTION_ENTRY_S {
    uint8_t premt_tx_enabled_status;
    /**< Specifies weather tx is enabled or disabled on tx side
         values possible(0 or 1)*/
    uint8_t premt_tx_active_status;
    /**< Specifie sweather tx is active or deactive on tx side
         values possible(0 or 1)*/
    Preempt_Verify_States premt_verify_state;
    /**< Specifies the state of varify state machine
         values possible*/
    uint8_t premt_min_fragment_size;
    /**< Specifies minimum fragment size supported by firmware
         values possible(0-max_frame_size)*/
    uint16_t add_min_fragment_size;
    /**< Specifies fragment size to be configured.
         values possible(0-max_frame_size)*/
}EMAC_IOCTL_PREEMPTION_ENTRY;

/**
 *  @defgroup  EMAC_IOCTL_PORT_STATE_CTRL Port State control sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_PORT_STATE_CTRL sub-commands
  * @details The following macros are sub-commands that to be used when issueing
 *   emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_PORT_STATE_CTRL
 *
 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_PORT_STATE_DISABLE
 *        Place PORT is disabled state
 */
#define EMAC_IOCTL_PORT_STATE_DISABLE                   ((uint32_t)2U)

/**
 *  @def  EMAC_IOCTL_PORT_STATE_BLOCKING
 *        Place PORT is blocking state
 */
#define EMAC_IOCTL_PORT_STATE_BLOCKING                  ((uint32_t)3U)

/**
 *  @def  EMAC_IOCTL_PORT_STATE_FORWARD
 *        Place PORT is forwarding state
 */
#define EMAC_IOCTL_PORT_STATE_FORWARD                   ((uint32_t)4U)

/**
 *  @def  EMAC_IOCTL_PORT_STATE_FORWARD_WO_LEARNING
 *        Place PORT is forwarding  without learning state
 */
#define EMAC_IOCTL_PORT_STATE_FORWARD_WO_LEARNING       ((uint32_t)5U)

/**
 *  @def  EMAC_IOCTL_PORT_STATE_TAS_TRIGGER
 *        Place PORT is TAS trigger state
 */
#define EMAC_IOCTL_PORT_STATE_TAS_TRIGGER               ((uint32_t)6U)

/**
 *  @def  EMAC_IOCTL_PORT_STATE_TAS_ENABLE
 *        Place PORT is TAS enable state
 */
#define EMAC_IOCTL_PORT_STATE_TAS_ENABLE                ((uint32_t)7U)

/**
 *  @def  EMAC_IOCTL_PORT_STATE_TAS_RESET
 *        Place PORT is TAS reset state
 */
#define EMAC_IOCTL_PORT_STATE_TAS_RESET                 ((uint32_t)8U)

/**
 *  @def  EMAC_IOCTL_PORT_STATE_TAS_DISABLE
 *        Place PORT is TAS disable state
 */
#define EMAC_IOCTL_PORT_STATE_TAS_DISABLE              ((uint32_t)9U)

/*@}*/
/** @} */


/**
 *  @defgroup  EMAC_IOCTL_FDB_ENTRY_CTRL FDB entry control sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_FDB_ENTRY_CTRL sub-commands
 *  @details The following macros are sub-commands that to be used when issueing
 *   emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_FDB_ENTRY_CTRL
 *
 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_FDB_ENTRY_ADD
 *        Add FDB entry
 */
#define EMAC_IOCTL_FDB_ENTRY_ADD                   ((uint32_t)1U)

/**
 *  @def  EMAC_IOCTL_FDB_ENTRY_DELETE
 *        Delete FDB entry
 */
#define EMAC_IOCTL_FDB_ENTRY_DELETE                  ((uint32_t)2U)

/**
 *  @def  EMAC_IOCTL_FDB_ENTRY_DELETE_ALL
 *        Delete all FDB entries
 */
#define EMAC_IOCTL_FDB_ENTRY_DELETE_ALL                   ((uint32_t)3U)

/**
 *  @def  EMAC_IOCTL_FDB_ENTRY_DELETE_ALL_AGEABLE
 *        Delete all ageable FDB entries
 */
#define EMAC_IOCTL_FDB_ENTRY_DELETE_ALL_AGEABLE       ((uint32_t)4U)

/*@}*/
/** @} */

/*!
 *  @brief    Define for  un-tagged vlan Id
 */
#define EMAC_VLAN_UNTAGGED               ((int16_t)-1)

/**
 * @brief FDB entry configuration structure
 */
typedef struct EMAC_IOCTL_FDB_ENTRY_S {
    uint8_t mac[6];
    /**< mac address */
    int16_t vlanId;
    /**< vlan id */
    uint8_t fdbEntry[2];
    /**< FDB entry with the following bit fields starting with bit 0: fdb_host, fdb_port1, fdb_port2, fdb_ageable, fdb_block, fdb_secure, fdb_touched, fdb_valid. Two entries for two ports */
}EMAC_IOCTL_FDB_ENTRY;

/**
 *  @defgroup  EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL Acceptable frame check control IOCTL sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL sub-commands
 *  @details The following macros are sub-commands that to be used when issueing
 *   emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL

 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_VLAN_TAGGED
 *        Admit only VLAN-tagged frames
 */
#define EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_VLAN_TAGGED              ((uint32_t)1U)

/**
 *  @def  EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_UN_TAGGED_PRIO_TAGGED
 *        Admit Only Untagged and Priority-tagged frames
 */
#define EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_UN_TAGGED_PRIO_TAGGED    ((uint32_t)2U)

/**
 *  @def  EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ALL_FRAMES
 *        Admit all frames (default setting)
 */
#define EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ALL_FRAMES                    ((uint32_t)3U)

/*@}*/
/** @} */

/**
 *  @defgroup  EMAC_IOCTL_PORT_UC_FLOODING_CTRL Control sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_PORT_UC_FLOODING_CTRL sub-commands
 *  @details The following macros are sub-commands that to be used when issueing
 *  emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_PORT_UC_FLOODING_CTRL
 *
 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_PORT_UC_FLOODING_ENABLE
 *        Enable UC flooding
 */
#define EMAC_IOCTL_PORT_UC_FLOODING_ENABLE                 ((uint32_t)1U)

/**
 *  @def  EMAC_IOCTL_PORT_UC_FLOODING_DISABLE
 *        Disable UC flooding
 */
#define EMAC_IOCTL_PORT_UC_FLOODING_DISABLE                ((uint32_t)2U)

/*@}*/
/** @} */

/**
 *  @defgroup  EMAC_IOCTL_INTERFACE_MAC_CTRL Control sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_INTERFACE_MAC_CTRL sub-commands
 *  @details The following macros are sub-commands that to be used when issueing
 *  emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_INTERFACE_MAC_CTRL
 *
 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_INTERFACE_MAC_ADD
 *        Enable UC flooding
 */
#define EMAC_IOCTL_INTERFACE_MAC_ADD                       ((uint32_t)1U)

/*@}*/
/** @} */

/**
 *  @defgroup  EMAC_IOCTL_FRAME_PREEMPTION_CTRL Control sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_FRAME_PREEMPTION_CTRL sub-commands
 *  @details The following macros are sub-commands that to be used when issueing
 *  emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_FRAME_PREEMPTION_CTRL
 *
 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_PREEMPT_TX_ENABLE
 *        Enable premeption on TX
 */
#define EMAC_IOCTL_PREEMPT_TX_ENABLE                        ((uint32_t)1U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_TX_DISABLE
 *        Disable  premeption on TX
 */
#define EMAC_IOCTL_PREEMPT_TX_DISABLE                       ((uint32_t)2U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_GET_TX_ENABLE_STATUS
 *        Get status of premeption on TX
 */
#define EMAC_IOCTL_PREEMPT_GET_TX_ENABLE_STATUS             ((uint32_t)3U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_GET_TX_ACTIVE_STATUS
 *       Get status of weather premeption is active
 */
#define EMAC_IOCTL_PREEMPT_GET_TX_ACTIVE_STATUS             ((uint32_t)4U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_VERIFY_ENABLE
 *        Enable verify state machine
 */
#define EMAC_IOCTL_PREEMPT_VERIFY_ENABLE                    ((uint32_t)5U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_VERIFY_DISABLE
 *        Disable verify state machine
 */
#define EMAC_IOCTL_PREEMPT_VERIFY_DISABLE                    ((uint32_t)6U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_GET_VERIFY_STATE
 *        get the verify state machine current state
 */
#define EMAC_IOCTL_PREEMPT_GET_VERIFY_STATE                 ((uint32_t)7U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_GET_MIN_FRAG_SIZE_LOCAL
 *        Get minimum fragment size supported by firmware
 */
#define EMAC_IOCTL_PREEMPT_GET_MIN_FRAG_SIZE_LOCAL          ((uint32_t)8U)

/**
 *  @def  EMAC_IOCTL_PREEMPT_SET_MIN_FRAG_SIZE_REMOTE
 *        Add minimum fragment size
 */
#define EMAC_IOCTL_PREEMPT_SET_MIN_FRAG_SIZE_REMOTE         ((uint32_t)9U)

/*@}*/
/** @} */

/*@}*/
/** @} */
/**
 *  @defgroup  EMAC_IOCTL_SPEED_DUPLEXITY_CTRL Control sub-commands
 *  @ingroup emaclld_api_ioctl_macros
 *  @{
 *
 *  @name EMAC_IOCTL_SPEED_DUPLEXITY_CTRL sub-commands
 *  @details The following macros are sub-commands that to be used when issueing
 *  emac_ioctl with EMAC_IOCTL_CMD set to EMAC_IOCTL_SPEED_DUPLEXITY_CTRL
 *
 */
/*@{*/
/**
 *  @def  EMAC_IOCTL_PREEMPT_TX_ENABLE
 *        Enable premeption on TX
 */
#define EMAC_IOCTL_SPEED_DUPLEXITY_10HD             ((uint32_t)0x0)

/**
 *  @def  EMAC_IOCTL_PREEMPT_TX_DISABLE
 *        Disable  premeption on TX
 */
#define EMAC_IOCTL_SPEED_DUPLEXITY_10FD             ((uint32_t)0x8)

/**
 *  @def  EMAC_IOCTL_PREEMPT_GET_TX_ENABLE_STATUS
 *        Get status of premeption on TX
 */
#define EMAC_IOCTL_SPEED_DUPLEXITY_100HD            ((uint32_t)0x2)

/**
 *  @def  EMAC_IOCTL_PREEMPT_GET_TX_ACTIVE_STATUS
 *       Get status of weather premeption is active
 */
#define EMAC_IOCTL_SPEED_DUPLEXITY_100FD             ((uint32_t)0xA)

/**
 *  @def  EMAC_IOCTL_PREEMPT_VERIFY_ENABLE
 *        Enable verify state machine
 */
#define EMAC_IOCTL_SPEED_DUPLEXITY_GIGABIT          ((uint32_t)0xC)

/**
 *  @def  EMAC_IOCTL_PREEMPT_VERIFY_DISABLE
 *        Disable verify state machine
 */
#define EMAC_IOCTL_SPEED_DUPLEXITY_DISABLE          ((uint32_t)0xF)

/*@}*/
/** @} */

/*!
 *  @cond NODOC
 *  Internally used by the driver, IOCTL helper functions
 */
extern void emac_classifier_disable(uint32_t port_num);
extern void emac_ioctl_icss_add_mac (uint32_t port_num, uint8_t*  macAddr);
extern void emac_ioctl_icss_promiscous_ctrl(uint32_t port_num, void*  ctrl);
extern void emac_ioctl_icss_debug_fw_mgmt_psi(uint32_t port_num, void*  ctrl);
extern void emac_ioctl_test_multi_flow(uint32_t port_num, void*  ctrl);
extern void emac_ioctl_vlan_ctrl_set_default_tbl(uint32_t port_num, void*  ctrl);
extern EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_set_default_vlan_id(uint32_t port_num, void* ctrl);
extern EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_set_default_vlan_id_host_port(uint32_t port_num, void* ctrl);
extern EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_set_entry(uint32_t port_num, void*  ctrl);
extern EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_get_entry(uint32_t port_num, void*  ctrl);
extern void emac_switch_vlan_init(uint32_t port_num, EMAC_OPEN_CONFIG_INFO_T* p_config);
extern void emac_ioctl_port_prio_mapping_ctrl(uint32_t port_num, void*  ctrl);
extern EMAC_DRV_ERR_E emac_ioctl_port_state_ctrl(uint32_t port_num, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_fdb_entry_ctrl(uint32_t port_num, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_fdb_del_all(uint32_t port_num, void* p_params);
EMAC_DRV_ERR_E emac_ioctl_accept_frame_check_ctrl(uint32_t port_num, void* p_params);
extern void emac_switch_config_ft3_priority_tag(uint32_t port_num);
extern EMAC_DRV_ERR_E emac_ioctl_prio_regen_mapping_ctrl(uint32_t port_num, void*  ctrl);
extern EMAC_DRV_ERR_E emac_ioctl_uc_flooding_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_configure_interface_mac_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_configure_cut_through_or_prempt_select_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_configure_special_frame_prio_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_frame_premption_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_configure_fdb_ageing_interval(uint32_t port_num, uint32_t switch_port, void* p_params);
extern EMAC_DRV_ERR_E emac_ioctl_speed_duplexity_cfg(uint32_t port_num, void* p_params);

/*! @endcond */

/*!
 *  @cond NODOC
 *  Internally used by the driver, IOCTL helper functions
 */
typedef enum EMAC_IOctlR30Cmd_E{
    EMAC_PORT_DISABLE = 0,
    EMAC_PORT_BLOCK,
    EMAC_PORT_FORWARD,
    EMAC_PORT_FORWARD_WO_LEARNING,
    EMAC_PORT_ACCEPT_ALL,
    EMAC_PORT_ACCEPT_TAGGED,
    EMAC_PORT_ACCEPT_UNTAGGED_N_PRIO,
    EMAC_PORT_TAS_TRIGGER,
    EMAC_PORT_TAS_ENABLE,
    EMAC_PORT_TAS_RESET,
    EMAC_PORT_TAS_DISABLE,
    EMAC_PORT_UC_FLOODING_ENABLE,
    EMAC_PORT_UC_FLOODING_DISABLE,
    EMAC_PORT_PREMPT_TX_ENABLE,
    EMAC_PORT_PREMPT_TX_DISABLE,
    EMAC_PORT_MAX_COMMANDS
} EMAC_IOctlR30Cmd;

typedef enum EMAC_IcssgInstance_E{
    EMAC_ICSSG_0 = 0,
    EMAC_ICSSG_1
} EMAC_IcssgInstance;

#define EMAC_NONE           ((uint32_t)0xffff0000)
#define EMAC_PRU0_P_DI      ((uint32_t)0xffff0004)
#define EMAC_PRU1_P_DI      ((uint32_t)0xffff0040)
#define EMAC_TX_P_DI        ((uint32_t)0xffff0100)

#define EMAC_PRU0_P_EN      ((uint32_t)0xfffb0000)
#define EMAC_PRU1_P_EN      ((uint32_t)0xffbf0000)
#define EMAC_TX_P_EN        ((uint32_t)0xfeff0000)

#define EMAC_P_BLOCK        ((uint32_t)0xffff0040)
#define EMAC_TX_P_BLOCK     ((uint32_t)0xffff0200)
#define EMAC_P_UNBLOCK      ((uint32_t)0xffbf0000)
#define EMAC_TX_P_UNBLOCK   ((uint32_t)0xfdff0000)
#define EMAC_LEAN_EN        ((uint32_t)0xfff70000)
#define EMAC_LEAN_DI        ((uint32_t)0xffff0008)

#define EMAC_ACCEPT_ALL     ((uint32_t)0xffff0001)
#define EMAC_ACCEPT_TAG     ((uint32_t)0xfffe0002)
#define EMAC_ACCEPT_PRIOR   ((uint32_t)0xfffc0000)

/*! @endcond */

#ifdef __cplusplus
}
#endif

/**
@}
*/
#endif /* EMAC_IOCTL_H */
