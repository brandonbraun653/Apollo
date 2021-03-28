//***********************************************************************************
//**+-----------------------------------------------------------------------------+**
//**|                              ******                                         |**
//**|                              ******     o                                   |**
//**|                              *******__////__****                            |**
//**|                              ***** /_ //___/ ***                            |**
//**|                           ********* ////__ ******                           |**
//**|                             *******(_____/ ******                           |**
//**|                                 **********                                  |**
//**|                                   ******                                    |**
//**|                                      ***                                    |**
//**|                                                                             |**
//**|            Copyright (c) 2019 Texas Instruments Incorporated                |**
//**|                           ALL RIGHTS RESERVED                               |**
//**|                                                                             |**
//**|    Permission is hereby granted to licensees of Texas Instruments           |**
//**|    Incorporated (TI) products to use this computer program for the sole     |**
//**|    purpose of implementing a licensee product based on TI products.         |**
//**|    No other rights to reproduce, use, or disseminate this computer          |**
//**|    program, whether in part or in whole, are granted.                       |**
//**|                                                                             |**
//**|    TI makes no representation or warranties with respect to the             |**
//**|    performance of this computer program, and specifically disclaims         |**
//**|    any responsibility for any damages, special or consequential,            |**
//**|    connected with the use of this program.                                  |**
//**|                                                                             |**
//**+-----------------------------------------------------------------------------+**
//***********************************************************************************
// file:     switch_mem_map.h
//
// brief:    Contains memory map for Ethernet Switch.
//           This file is shared by firmware and driver.

#ifndef ____switch_mem_map_h
#define ____switch_mem_map_h 1

#include "switch_mmap_defines.h"

//************************************************************************************
//
// Memory Usage of : SHARED_MEMORY
//
//************************************************************************************

#define SHARED_MEMORY_START_OFFSET                         0x0000
#define PRE_EMPTION_CONTEXT_OFFSET                         0x0000    //Backup of active Tx and Q context. The offset is not used
#define PRE_EMPTION_CONTEXT_OFFSET_SIZE                    0x8
#define FW_HOST_HANDSHAKE_MAGIC_VAL_OFFSET                 0x0008    //Firmware host handshake
#define FW_HOST_HANDSHAKE_MAGIC_VAL_OFFSET_SIZE            0x4
#define PSI_L_REGULAR_FLOW_ID_BASE_OFFSET                  0x000C    //Base Flow ID for sending packets to Host
#define PSI_L_REGULAR_FLOW_ID_BASE_OFFSET_SIZE             0x2
#define EMAC_ICSSG_SWITCH_PSI_L_REGULAR_FLOW_ID_BASE_OFFSET PSI_L_REGULAR_FLOW_ID_BASE_OFFSET    //Same as PSI_L_REGULAR_FLOW_ID_BASE_OFFSET
#define PSI_L_MGMT_FLOW_ID_OFFSET                          0x000E    //Base Flow ID for sending mgmt and Tx TS to Host
#define PSI_L_MGMT_FLOW_ID_OFFSET_SIZE                     0x2
#define EMAC_ICSSG_SWITCH_PSI_L_MGMT_FLOW_ID_BASE_OFFSET   PSI_L_MGMT_FLOW_ID_OFFSET    //Same as PSI_L_MGMT_FLOW_ID_OFFSET
#define SPL_PKT_DEFAULT_PRIORITY                           0x0010    //Queue number for Special packets written here. Only 1B is used
#define SPL_PKT_DEFAULT_PRIORITY_SIZE                      0x4
#define FDB_SA_MAC_ADDRESS                                 0x0014    //Used internally by FW for learning
#define FDB_SA_MAC_ADDRESS_SIZE                            0x8
#define FDB_FID_FIDC2_OFFSET                               0x001C    //Used internally by FW for learning
#define FDB_FID_FIDC2_OFFSET_SIZE                          0x4
#define FDB_BUCKET_OFFSET                                  0x0020    //Used internally by FW for learning
#define FDB_BUCKET_OFFSET_SIZE                             0x4
#define FDB_AGEING_LAST_USED_OFFSET                        0x0024    //Used internally by FW for learning
#define FDB_AGEING_LAST_USED_OFFSET_SIZE                   0x4
#define TX_SOF_TS_OFFSET                                   0x0028    //Used internally by FW to store Tx timestamp
#define TX_SOF_TS_OFFSET_SIZE                              0x8
#define TX_TS_COOKIE_OFFSET                                0x0030    //Used internally by FW to stash cookie
#define TX_TS_COOKIE_OFFSET_SIZE                           0x4
#define HOST_PORT_DF_VLAN_OFFSET                           0x0034    //default VLAN tag for Host Port
#define HOST_PORT_DF_VLAN_OFFSET_SIZE                      0x4
#define EMAC_ICSSG_SWITCH_PORT0_DEFAULT_VLAN_OFFSET        HOST_PORT_DF_VLAN_OFFSET    //Same as HOST_PORT_DF_VLAN_OFFSET
#define P1_PORT_DF_VLAN_OFFSET                             0x0038    //default VLAN tag for P1 Port
#define P1_PORT_DF_VLAN_OFFSET_SIZE                        0x4
#define EMAC_ICSSG_SWITCH_PORT1_DEFAULT_VLAN_OFFSET        P1_PORT_DF_VLAN_OFFSET    //Same as P1_PORT_DF_VLAN_OFFSET
#define P2_PORT_DF_VLAN_OFFSET                             0x003C    //default VLAN tag for P2 Port
#define P2_PORT_DF_VLAN_OFFSET_SIZE                        0x4
#define EMAC_ICSSG_SWITCH_PORT2_DEFAULT_VLAN_OFFSET        P2_PORT_DF_VLAN_OFFSET    //Same as P2_PORT_DF_VLAN_OFFSET
#define RX_TS_STASHED                                      0x0040    //Used internally by FW for stashed Rx timestamp
#define RX_TS_STASHED_SIZE                                 0x8
#define MGR_CMD_OFFSET                                     0x0048    //Management command from Host to RTU0
#define MGR_CMD_OFFSET_SIZE                                0x20
#define MGR_CMD_RET                                        0x0068    //Management reply to Host from RTU0
#define MGR_CMD_RET_SIZE                                   0xc
#define MGR_CMD_STATE                                      0x0074    //0 - idle; 1 - todo; 2 - executing
#define MGR_CMD_STATE_SIZE                                 0x1
//Padding of 3 bytes
#define MGR_CMD_PRU0_STATUS                                0x0078    //Used internally by FW to communicate from RTU0 to PRU0
#define MGR_CMD_PRU0_STATUS_SIZE                           0x2
#define MGR_CMD_PRU1_STATUS                                0x007A    //Used internally by FW to communicate from RTU0 to PRU1
#define MGR_CMD_PRU1_STATUS_SIZE                           0x2
#define MGR_CMD_RTU0_STATUS                                0x007C    //Used internally by FW to communicate from RTU0 to RTU0
#define MGR_CMD_RTU0_STATUS_SIZE                           0x2
#define MGR_CMD_RTU1_STATUS                                0x007E    //Used internally by FW to for management state machine
#define MGR_CMD_RTU1_STATUS_SIZE                           0x42
#define MGR_CMD_END_OFFSET                                 0x00C0    //End of Management command region
#define P1_QUEUE_NUM_UNTAGGED                              0x00C0    //Port1 Default Queue number for untagged packets
#define P1_QUEUE_NUM_UNTAGGED_SIZE                         0x1
#define P2_QUEUE_NUM_UNTAGGED                              0x00C1    //Port2 Default Queue number for untagged packets
#define P2_QUEUE_NUM_UNTAGGED_SIZE                         0x1
#define PORT_Q0_RD_PTR_OFFSET                              0x0100    //Port Tx Q0 MSMC Read pointer stored here
#define PORT_Q0_RD_PTR_OFFSET_SIZE                         0x4
#define EMAC_ICSSG_SWITCH_PORT_QUEUE_READ_PTR_OFFSET       PORT_Q0_RD_PTR_OFFSET    //Same as PORT_Q0_RD_PTR_OFFSET
#define PORT_Q1_RD_PTR_OFFSET                              0x0104    //Port Tx Q1 MSMC Read pointer stored here
#define PORT_Q1_RD_PTR_OFFSET_SIZE                         0x4
#define PORT_Q2_RD_PTR_OFFSET                              0x0108    //Port Tx Q2 MSMC Read pointer stored here
#define PORT_Q2_RD_PTR_OFFSET_SIZE                         0x4
#define PORT_Q3_RD_PTR_OFFSET                              0x010C    //Port Tx Q3 MSMC Read pointer stored here
#define PORT_Q3_RD_PTR_OFFSET_SIZE                         0x4
#define PORT_Q4_RD_PTR_OFFSET                              0x0110    //Port Tx Q4 MSMC Read pointer stored here
#define PORT_Q4_RD_PTR_OFFSET_SIZE                         0x4
#define PORT_Q5_RD_PTR_OFFSET                              0x0114    //Port Tx Q5 MSMC Read pointer stored here
#define PORT_Q5_RD_PTR_OFFSET_SIZE                         0x4
#define PORT_Q6_RD_PTR_OFFSET                              0x0118    //Port Tx Q6 MSMC Read pointer stored here
#define PORT_Q6_RD_PTR_OFFSET_SIZE                         0x4
#define PORT_Q7_RD_PTR_OFFSET                              0x011C    //Port Tx Q1 MSMC Read pointer stored here
#define PORT_Q7_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q0_RD_PTR_OFFSET                              0x0120    //Host Tx Q0 MSMC Read pointer stored here
#define HOST_Q0_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q1_RD_PTR_OFFSET                              0x0124    //Host Tx Q1 MSMC Read pointer stored here
#define HOST_Q1_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q2_RD_PTR_OFFSET                              0x0128    //Host Tx Q2 MSMC Read pointer stored here
#define HOST_Q2_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q3_RD_PTR_OFFSET                              0x012C    //Host Tx Q3 MSMC Read pointer stored here
#define HOST_Q3_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q4_RD_PTR_OFFSET                              0x0130    //Host Tx Q4 MSMC Read pointer stored here
#define HOST_Q4_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q5_RD_PTR_OFFSET                              0x0134    //Host Tx Q5 MSMC Read pointer stored here
#define HOST_Q5_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q6_RD_PTR_OFFSET                              0x0138    //Host Tx Q6 MSMC Read pointer stored here
#define HOST_Q6_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_Q7_RD_PTR_OFFSET                              0x013C    //Host Tx Q7 MSMC Read pointer stored here
#define HOST_Q7_RD_PTR_OFFSET_SIZE                         0x4
#define HOST_RX_PRE_RD_PTR_OFFSET                          0x0140    //Host Egress Q MSMC Read pointer (for Pre-emptive queue) stored here
#define HOST_RX_PRE_RD_PTR_OFFSET_SIZE                     0x4
#define EMAC_ICSSG_SWITCH_HOST_QUEUE_READ_PTR_OFFSET       HOST_RX_PRE_RD_PTR_OFFSET    //Same as HOST_RX_PRE_RD_PTR_OFFSET
#define HOST_RX_PRE_WR_PTR_OFFSET                          0x0144    //Host Egress Q MSMC Write pointer (for Pre-emptive queue) stored here
#define HOST_RX_PRE_WR_PTR_OFFSET_SIZE                     0x4
#define HOST_RX_EXP_RD_PTR_OFFSET                          0x0148    //Reserved for Future Use
#define HOST_RX_EXP_RD_PTR_OFFSET_SIZE                     0x4
#define HOST_RX_EXP_WR_PTR_OFFSET                          0x014C    //Reserved for Future Use
#define HOST_RX_EXP_WR_PTR_OFFSET_SIZE                     0x4
#define PORT_Q0_DESC_RD_PTR_OFFSET                         0x0150    //Port Tx Q0 Desc Read pointer stored here
#define PORT_Q0_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q0_DESC_WR_PTR_OFFSET                         0x0152    //Port Tx Q0 Desc Write pointer stored here
#define PORT_Q0_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define PORT_Q1_DESC_RD_PTR_OFFSET                         0x0154    //Port Tx Q1 Desc Read pointer stored here
#define PORT_Q1_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q1_DESC_WR_PTR_OFFSET                         0x0156    //Port Tx Q1 Desc Write pointer stored here
#define PORT_Q1_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define PORT_Q2_DESC_RD_PTR_OFFSET                         0x0158    //Port Tx Q2 Desc Read pointer stored here
#define PORT_Q2_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q2_DESC_WR_PTR_OFFSET                         0x015A    //Port Tx Q2 Desc Write pointer stored here
#define PORT_Q2_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define PORT_Q3_DESC_RD_PTR_OFFSET                         0x015C    //Port Tx Q3 Desc Read pointer stored here
#define PORT_Q3_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q3_DESC_WR_PTR_OFFSET                         0x015E    //Port Tx Q3 Desc Write pointer stored here
#define PORT_Q3_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define PORT_Q4_DESC_RD_PTR_OFFSET                         0x0160    //Port Tx Q4 Desc Read pointer stored here
#define PORT_Q4_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q4_DESC_WR_PTR_OFFSET                         0x0162    //Port Tx Q4 Desc Write pointer stored here
#define PORT_Q4_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define PORT_Q5_DESC_RD_PTR_OFFSET                         0x0164    //Port Tx Q5 Desc Read pointer stored here
#define PORT_Q5_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q5_DESC_WR_PTR_OFFSET                         0x0166    //Port Tx Q5 Desc Write pointer stored here
#define PORT_Q5_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define PORT_Q6_DESC_RD_PTR_OFFSET                         0x0168    //Port Tx Q3 Desc Read pointer stored here
#define PORT_Q6_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q6_DESC_WR_PTR_OFFSET                         0x016A    //Port Tx Q6 Desc Write pointer stored here
#define PORT_Q6_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define PORT_Q7_DESC_RD_PTR_OFFSET                         0x016C    //Port Tx Q7 Desc Read pointer stored here
#define PORT_Q7_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define PORT_Q7_DESC_WR_PTR_OFFSET                         0x016E    //Port Tx Q7 Desc Write pointer stored here
#define PORT_Q7_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q0_DESC_RD_PTR_OFFSET                         0x0170    //Host Tx Q0 Desc Read pointer stored here
#define HOST_Q0_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q0_DESC_WR_PTR_OFFSET                         0x0172    //Host Tx Q0 Desc Write pointer stored here
#define HOST_Q0_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q1_DESC_RD_PTR_OFFSET                         0x0174    //Host Tx Q1 Desc Read pointer stored here
#define HOST_Q1_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q1_DESC_WR_PTR_OFFSET                         0x0176    //Host Tx Q1 Desc Write pointer stored here
#define HOST_Q1_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q2_DESC_RD_PTR_OFFSET                         0x0178    //Host Tx Q2 Desc Read pointer stored here
#define HOST_Q2_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q2_DESC_WR_PTR_OFFSET                         0x017A    //Host Tx Q2 Desc Write pointer stored here
#define HOST_Q2_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q3_DESC_RD_PTR_OFFSET                         0x017C    //Host Tx Q3 Desc Read pointer stored here
#define HOST_Q3_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q3_DESC_WR_PTR_OFFSET                         0x017E    //Host Tx Q3 Desc Write pointer stored here
#define HOST_Q3_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q4_DESC_RD_PTR_OFFSET                         0x0180    //Host Tx Q4 Desc Read pointer stored here
#define HOST_Q4_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q4_DESC_WR_PTR_OFFSET                         0x0182    //Host Tx Q4 Desc Write pointer stored here
#define HOST_Q4_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q5_DESC_RD_PTR_OFFSET                         0x0184    //Host Tx Q5 Desc Read pointer stored here
#define HOST_Q5_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q5_DESC_WR_PTR_OFFSET                         0x0186    //Host Tx Q5 Desc Write pointer stored here
#define HOST_Q5_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q6_DESC_RD_PTR_OFFSET                         0x0188    //Host Tx Q6 Desc Read pointer stored here
#define HOST_Q6_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q6_DESC_WR_PTR_OFFSET                         0x018A    //Host Tx Q6 Desc Write pointer stored here
#define HOST_Q6_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define HOST_Q7_DESC_RD_PTR_OFFSET                         0x018C    //Host Tx Q7 Desc Read pointer stored here
#define HOST_Q7_DESC_RD_PTR_OFFSET_SIZE                    0x2
#define HOST_Q7_DESC_WR_PTR_OFFSET                         0x018E    //Host Tx Q7 Desc Write pointer stored here
#define HOST_Q7_DESC_WR_PTR_OFFSET_SIZE                    0x2
#define VLAN_STATIC_REG_TABLE_OFFSET                       0x0190    //VLAN-FID Table offset. 4096 VIDs. 2B per VID = 8KB = 0x2000
#define VLAN_STATIC_REG_TABLE_OFFSET_SIZE                  0x2000
#define EMAC_ICSSG_SWITCH_DEFAULT_VLAN_TABLE_OFFSET        VLAN_STATIC_REG_TABLE_OFFSET    //VLAN-FID Table offset for EMAC
#define SMEM_VLAN_END_OF_MEM                               0x2190    //End of VLAN-FID table marker
#define SMEM_VLAN_END_OF_MEM_SIZE                          0x4
#define PORT_Q0_CONTEXT_OFFSET                             0x2194    //16B for Port Tx MSMC Q context
#define PORT_Q0_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define EMAC_ICSSG_SWITCH_PORT_QUEUE_CONTEXT_OFFSET        PORT_Q0_CONTEXT_OFFSET    //Same as PORT_Q0_CONTEXT_OFFSET
#define PORT_Q1_CONTEXT_OFFSET                             0x21A4    //16B for Port Tx MSMC Q context
#define PORT_Q1_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q2_CONTEXT_OFFSET                             0x21B4    //16B for Port Tx MSMC Q context
#define PORT_Q2_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q3_CONTEXT_OFFSET                             0x21C4    //16B for Port Tx MSMC Q context
#define PORT_Q3_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q4_CONTEXT_OFFSET                             0x21D4    //16B for Port Tx MSMC Q context
#define PORT_Q4_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q5_CONTEXT_OFFSET                             0x21E4    //16B for Port Tx MSMC Q context
#define PORT_Q5_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q6_CONTEXT_OFFSET                             0x21F4    //16B for Port Tx MSMC Q context
#define PORT_Q6_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q7_CONTEXT_OFFSET                             0x2204    //16B for Port Tx MSMC Q context
#define PORT_Q7_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q0_CONTEXT_OFFSET                             0x2214    //16B for Host Tx MSMC Q context
#define HOST_Q0_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q1_CONTEXT_OFFSET                             0x2224    //16B for Host Tx MSMC Q context
#define HOST_Q1_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q2_CONTEXT_OFFSET                             0x2234    //16B for Host Tx MSMC Q context
#define HOST_Q2_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q3_CONTEXT_OFFSET                             0x2244    //16B for Host Tx MSMC Q context
#define HOST_Q3_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q4_CONTEXT_OFFSET                             0x2254    //16B for Host Tx MSMC Q context
#define HOST_Q4_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q5_CONTEXT_OFFSET                             0x2264    //16B for Host Tx MSMC Q context
#define HOST_Q5_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q6_CONTEXT_OFFSET                             0x2274    //16B for Host Tx MSMC Q context
#define HOST_Q6_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q7_CONTEXT_OFFSET                             0x2284    //16B for Host Tx MSMC Q context
#define HOST_Q7_CONTEXT_OFFSET_SIZE                        (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_RX_Q_PRE_CONTEXT_OFFSET                       0x2294    //16B for Host Egress MSMC Q (Pre-emptible) context
#define HOST_RX_Q_PRE_CONTEXT_OFFSET_SIZE                  (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_RX_Q_EXP_CONTEXT_OFFSET                       0x22A4    //16B for Host Egress MSMC Q (Express) context
#define HOST_RX_Q_EXP_CONTEXT_OFFSET_SIZE                  (NRT_QUEUE_CONTEXT_SIZE) //0x10
#define DEFAULT_MSMC_Q_OFFSET                              (HOST_RX_Q_EXP_CONTEXT_OFFSET + 12)    //End of NRT MSMC region.
#define PORT_Q0_DESC_CONTEXT_OFFSET                        0x22B4    //16B for Port Tx Q Desc context
#define PORT_Q0_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define EMAC_ICSSG_SWITCH_PORT_DESC_QUEUE_CONTEXT_OFFSET   PORT_Q0_DESC_CONTEXT_OFFSET    //Start of Queue Descriptors for EMAC
#define PORT_Q1_DESC_CONTEXT_OFFSET                        0x22C4    //16B for Port Tx Q Desc context
#define PORT_Q1_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q2_DESC_CONTEXT_OFFSET                        0x22D4    //16B for Port Tx Q Desc context
#define PORT_Q2_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q3_DESC_CONTEXT_OFFSET                        0x22E4    //16B for Port Tx Q Desc context
#define PORT_Q3_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q4_DESC_CONTEXT_OFFSET                        0x22F4    //16B for Port Tx Q Desc context
#define PORT_Q4_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q5_DESC_CONTEXT_OFFSET                        0x2304    //16B for Port Tx Q Desc context
#define PORT_Q5_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q6_DESC_CONTEXT_OFFSET                        0x2314    //16B for Port Tx Q Desc context
#define PORT_Q6_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_Q7_DESC_CONTEXT_OFFSET                        0x2324    //16B for Port Tx Q Desc context
#define PORT_Q7_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q0_DESC_CONTEXT_OFFSET                        0x2334    //16B for Port Tx Q Desc context
#define HOST_Q0_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q1_DESC_CONTEXT_OFFSET                        0x2344    //16B for Host Tx Q Desc context
#define HOST_Q1_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q2_DESC_CONTEXT_OFFSET                        0x2354    //16B for Host Tx Q Desc context
#define HOST_Q2_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q3_DESC_CONTEXT_OFFSET                        0x2364    //16B for Host Tx Q Desc context
#define HOST_Q3_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q4_DESC_CONTEXT_OFFSET                        0x2374    //16B for Host Tx Q Desc context
#define HOST_Q4_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q5_DESC_CONTEXT_OFFSET                        0x2384    //16B for Host Tx Q Desc context
#define HOST_Q5_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q6_DESC_CONTEXT_OFFSET                        0x2394    //16B for Host Tx Q Desc context
#define HOST_Q6_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_Q7_DESC_CONTEXT_OFFSET                        0x23A4    //16B for Host Tx Q Desc context
#define HOST_Q7_DESC_CONTEXT_OFFSET_SIZE                   (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_RX_Q_PRE_DESC_CONTEXT_OFFSET                  0x23B4    //16B for Host Egress Q (pre-emptible) Desc context
#define HOST_RX_Q_PRE_DESC_CONTEXT_OFFSET_SIZE             (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define HOST_RX_Q_EXP_DESC_CONTEXT_OFFSET                  0x23C4    //16B for Host Egress Q (Express) Desc context. redundant
#define HOST_RX_Q_EXP_DESC_CONTEXT_OFFSET_SIZE             (NRT_DESC_QUEUE_CONTEXT_SIZE) //0x10
#define PORT_DESC_Q0_OFFSET                                0x23D4    //packet descriptor Q reserved memory
#define PORT_DESC_Q0_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define PORT_DESC_Q1_OFFSET                                0x2B08    //packet descriptor Q reserved memory for Port Tx queues
#define PORT_DESC_Q1_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define PORT_DESC_Q2_OFFSET                                0x323C    //packet descriptor Q reserved memory for Port Tx queues
#define PORT_DESC_Q2_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define PORT_DESC_Q3_OFFSET                                0x3970    //packet descriptor Q reserved memory for Port Tx queues
#define PORT_DESC_Q3_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define PORT_DESC_Q4_OFFSET                                0x40A4    //packet descriptor Q reserved memory for Port Tx queues
#define PORT_DESC_Q4_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define PORT_DESC_Q5_OFFSET                                0x47D8    //packet descriptor Q reserved memory for Port Tx queues
#define PORT_DESC_Q5_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define PORT_DESC_Q6_OFFSET                                0x4F0C    //packet descriptor Q reserved memory for Port Tx queues
#define PORT_DESC_Q6_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define PORT_DESC_Q7_OFFSET                                0x5640    //packet descriptor Q reserved memory for Port Tx queues
#define PORT_DESC_Q7_OFFSET_SIZE                           (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define HOST_DESC_Q0_OFFSET                                0x5D74    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q0_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_DESC_Q1_OFFSET                                0x5FA8    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q1_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_DESC_Q2_OFFSET                                0x61DC    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q2_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_DESC_Q3_OFFSET                                0x6410    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q3_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_DESC_Q4_OFFSET                                0x6644    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q4_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_DESC_Q5_OFFSET                                0x6878    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q5_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_DESC_Q6_OFFSET                                0x6AAC    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q6_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_DESC_Q7_OFFSET                                0x6CE0    //packet descriptor Q reserved memory for Host Tx queues
#define HOST_DESC_Q7_OFFSET_SIZE                           (NRT_HOST_DESC_QUEUE_SIZE) //0x234
#define HOST_RX_DESC_Q_PRE_OFFSET                          0x6F14    //packet descriptor Q reserved memory for Host Egress (Pre-emptible) queues
#define HOST_RX_DESC_Q_PRE_OFFSET_SIZE                     (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define HOST_RX_DESC_Q_EXP_OFFSET                          0x7648    //packet descriptor Q reserved memory for Host Egress (Pre-emptible) queues. redundant
#define HOST_RX_DESC_Q_EXP_OFFSET_SIZE                     (NRT_PORT_DESC_QUEUE_SIZE) //0x734
#define SHARED_MEMORY_END_OFFSET                           0x7D7C

// total SHARED_MEMORY memory usage : 31.37109375 KB from total of 64.0KB 

//************************************************************************************
//
// Memory Usage of : MSMC
//
//************************************************************************************

#define MSMC_START_OFFSET                                  0x0000
#define MSMC_END_OFFSET                                    0x0000

// total MSMC memory usage : 0.0 KB from total of 2048.0KB 

//************************************************************************************
//
// Memory Usage of : DMEM0
//
//************************************************************************************

#define DMEM0_START_OFFSET                                 0x0000
#define PORT_Q_PRIORITY_REGEN_OFFSET                       0x0000    //Stores the table used for priority regeneration. 4B per PCP/Queue. Only 1B is used
#define PORT_Q_PRIORITY_REGEN_OFFSET_SIZE                  0x20
#define EXPRESS_PRE_EMPTIVE_Q_MAP                          0x0020    //For marking packet as priority/express (this feature is disabled) or cut-through/S&F. One per slice
#define EXPRESS_PRE_EMPTIVE_Q_MAP_SIZE                     0x20
#define TAS_CONFIG_CHANGE_TIME                             0x0040    //New list is copied at this time
#define TAS_CONFIG_CHANGE_TIME_SIZE                        0x8
#define TAS_CONFIG_CHANGE_ERROR_COUNTER                    0x0048    //config change error counter
#define TAS_CONFIG_CHANGE_ERROR_COUNTER_SIZE               0x4
#define TAS_CONFIG_PENDING                                 0x004C    //TAS List update pending flag
#define TAS_CONFIG_PENDING_SIZE                            0x1
#define TAS_CONFIG_CHANGE                                  0x004D    //TAS list update trigger flag
#define TAS_CONFIG_CHANGE_SIZE                             0x1
//Padding of 2 bytes
#define TAS_ADMIN_CYCLE_TIME                               0x0050    //Cycle time for the new TAS schedule
#define TAS_ADMIN_CYCLE_TIME_SIZE                          0x4
#define TAS_CONFIG_CHANGE_CYCLE_COUNT                      0x0054    //Cycle counts remaining till the TAS list update
#define TAS_CONFIG_CHANGE_CYCLE_COUNT_SIZE                 0x4
#define PORT_Q_PRIORITY_MAPPING_OFFSET                     0x0058    //Stores the table used for priority mapping. 1B per PCP/Queue
#define PORT_Q_PRIORITY_MAPPING_OFFSET_SIZE                0x8
#define TAS_SHADOW_EXPIRY_LIST_GATE0                       0x0100    //TAS gate expiry list for gate0
#define TAS_SHADOW_EXPIRY_LIST_GATE0_SIZE                  0x20
#define TAS_SHADOW_EXPIRY_LIST_GATE1                       0x0120    //TAS gate expiry list for gate1
#define TAS_SHADOW_EXPIRY_LIST_GATE1_SIZE                  0x20
#define TAS_SHADOW_EXPIRY_LIST_GATE2                       0x0140    //TAS gate expiry list for gate2
#define TAS_SHADOW_EXPIRY_LIST_GATE2_SIZE                  0x20
#define TAS_SHADOW_EXPIRY_LIST_GATE3                       0x0160    //TAS gate expiry list for gate3
#define TAS_SHADOW_EXPIRY_LIST_GATE3_SIZE                  0x20
#define TAS_SHADOW_EXPIRY_LIST_GATE4                       0x0180    //TAS gate expiry list for gate4
#define TAS_SHADOW_EXPIRY_LIST_GATE4_SIZE                  0x20
#define TAS_SHADOW_EXPIRY_LIST_GATE5                       0x01A0    //TAS gate expiry list for gate5
#define TAS_SHADOW_EXPIRY_LIST_GATE5_SIZE                  0x20
#define TAS_SHADOW_EXPIRY_LIST_GATE6                       0x01C0    //TAS gate expiry list for gate6
#define TAS_SHADOW_EXPIRY_LIST_GATE6_SIZE                  0x20
#define TAS_SHADOW_EXPIRY_LIST_GATE7                       0x01E0    //TAS gate expiry list for gate7
#define TAS_SHADOW_EXPIRY_LIST_GATE7_SIZE                  0x20
#define PRE_EMPTION_ENABLE_TX                              0x0200    //Memory to Enable/Disable Preemption on TX side
#define PRE_EMPTION_ENABLE_TX_SIZE                         0x1
#define PRE_EMPTION_ACTIVE_TX                              0x0201    //Active State of Preemption on TX side
#define PRE_EMPTION_ACTIVE_TX_SIZE                         0x1
#define PRE_EMPTION_ENABLE_VERIFY                          0x0202    //Memory to Enable/Disable Verify State Machine Preemption
#define PRE_EMPTION_ENABLE_VERIFY_SIZE                     0x1
#define PRE_EMPTION_VERIFY_STATUS                          0x0203    //Verify Status of State Machine
#define PRE_EMPTION_VERIFY_STATUS_SIZE                     0x1
#define PRE_EMPTION_ADD_FRAG_SIZE_REMOTE                   0x0204    //Non Final Fragment Size supported by Link Partner
#define PRE_EMPTION_ADD_FRAG_SIZE_REMOTE_SIZE              0x2
#define PRE_EMPTION_ADD_FRAG_SIZE_LOCAL                    0x0206    //Non Final Fragment Size supported by Firmware
#define PRE_EMPTION_ADD_FRAG_SIZE_LOCAL_SIZE               0x1
//Padding of 1 bytes
#define PRE_EMPTION_VERIFY_TIME                            0x0208    //Time in ms the State machine waits for respond packet
#define PRE_EMPTION_VERIFY_TIME_SIZE                       0x2
#define DMEM0_END_OFFSET                                   0x020A

// total DMEM0 memory usage : 0.509765625 KB from total of 8.0KB 

//************************************************************************************
//
// Memory Usage of : DMEM1
//
//************************************************************************************

#define DMEM1_START_OFFSET                                 0x0000
#define ICSS_FIRMWARE_VERSION_OFFSET                       0x0000    //ICSSG Firmware version details
#define ICSS_FIRMWARE_VERSION_OFFSET_SIZE                  0xc
#define NRT_FRAME_PREEMPTION_ENABLE_OFFSET                 0x000C    //Memory used for Global enable and disable Frame Preemption
#define NRT_FRAME_PREEMPTION_ENABLE_OFFSET_SIZE            0x4
#define NRT_STASHED_Q_NUM_OFFSET                           0x0010    //Memory used for Stashing queue number during Host Egress in BG Task
#define NRT_STASHED_Q_NUM_OFFSET_SIZE                      0x4
#define PSI_TX_PKT_DATA_OFFSET                             0x0014    //Used Internally by FW. 
#define PSI_TX_PKT_DATA_OFFSET_SIZE                        0x24
#define LEARNING_WR_RD_COUNT_OFFSET                        0x0038    //Used Internally by FW to synchronize FDB Learning between RTU0 and PRU0 
#define LEARNING_WR_RD_COUNT_OFFSET_SIZE                   0x4
#define FDB_G0_M_G1_SLV_OFFSET                             0x003C    //Used Internally by FW to synchronize FDB Learning between two ICSSG's 
#define FDB_G0_M_G1_SLV_OFFSET_SIZE                        0x4
#define FDB_G1_M_G0_SLV_OFFSET                             0x0040    //Used Internally by FW to synchronize FDB Learning between two ICSSG's 
#define FDB_G1_M_G0_SLV_OFFSET_SIZE                        0x4
#define FDB_SYNC_ENTRY                                     0x0044    //Used to store the FDB entry one ICSSG learnt and one that needs to be communicated to other ICSSG 
#define FDB_SYNC_ENTRY_SIZE                                0x10
#define DEBUG_FDB_COMPARISON_MAC_VLAN                      0x0054    //Used for debugging FDB lookups, write the MAC and VLAN combination that is suspect. Currently disabled
#define DEBUG_FDB_COMPARISON_MAC_VLAN_SIZE                 0x8
#define DEBUG_FDB_RESULTS                                  0x005C    //The results of FBD lookup for Local injection are dumped here
#define DEBUG_FDB_RESULTS_SIZE                             0xc
#define FDB_AGEING_TIMEOUT_OFFSET                          0x0068    //Time after which FDB entries are checked for aged out values. Value in nanoseconds
#define FDB_AGEING_TIMEOUT_OFFSET_SIZE                     0x8
#define L2_2_L1_BYTES_SENT_COUNT_OFFSET                    0x0070    //Number of bytes sent by Tx L2 FIFO to L1 FIFO. Only 2 out of 4 bytes used.
#define L2_2_L1_BYTES_SENT_COUNT_OFFSET_SIZE               0x4
#define DMEM1_END_OFFSET                                   0x0100

// total DMEM1 memory usage : 0.25 KB from total of 8.0KB 

//************************************************************************************
//
// Memory Usage of : PRU0_BSRAM
//
//************************************************************************************

#define PRU0_BSRAM_START_OFFSET                            0x0000
#define PSI_TX_INFO_SLOT_PRU0                              0x0000    //Store PSI template for INFO chunk
#define PSI_TX_INFO_SLOT_PRU0_SIZE                         0x1
#define HOST_RX_PACKET_DESC_SLOT_PRU0                      0x0001    //Stores the PSI descriptor for packet being sent to Host
#define HOST_RX_PACKET_DESC_SLOT_PRU0_SIZE                 0x1
#define HOST_RX_PRE_CONTEXT_RD_SLOT_PRU0                   0x0002    //Contains context info for Host Egress Queue (pre-emptible). Used by read task
#define HOST_RX_PRE_CONTEXT_RD_SLOT_PRU0_SIZE              0x1
#define HOST_RX_PRE_CONTEXT_WR_SLOT_PRU0                   0x0003    //Contains context info for Host Egress Queue (pre-emptible). Used by write task
#define HOST_RX_PRE_CONTEXT_WR_SLOT_PRU0_SIZE              0x1
#define HOST_RX_EXP_CONTEXT_RD_SLOT_PRU0                   0x0004    //Contains context info for Host Egress Queue (express). redundant
#define HOST_RX_EXP_CONTEXT_RD_SLOT_PRU0_SIZE              0x1
#define HOST_RX_EXP_CONTEXT_WR_SLOT_PRU0                   0x0005    //Contains context info for Host Egress Queue (express). redundant
#define HOST_RX_EXP_CONTEXT_WR_SLOT_PRU0_SIZE              0x1
#define P0_FIRST_32B_PACKET_DATA                           0x0006    //Used to store 32B at the start of SOF
#define P0_FIRST_32B_PACKET_DATA_SIZE                      0x1
#define PRU0_BSRAM_END_OFFSET                              0x0007

// total PRU0_BSRAM memory usage : 0.21875 KB from total of 4.0KB 

//************************************************************************************
//
// Memory Usage of : PRU1_BSRAM
//
//************************************************************************************

#define PRU1_BSRAM_START_OFFSET                            0x0000
#define P1_FIRST_32B_PACKET_DATA                           0x0000    //redundant
#define P1_FIRST_32B_PACKET_DATA_SIZE                      0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE0                       0x0001    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE0_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE1                       0x0002    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE1_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE2                       0x0003    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE2_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE3                       0x0004    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE3_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE4                       0x0005    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE4_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE5                       0x0006    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE5_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE6                       0x0007    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE6_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST0_GATE7                       0x0008    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST0_GATE7_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE0                       0x0009    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE0_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE1                       0x000A    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE1_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE2                       0x000B    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE2_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE3                       0x000C    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE3_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE4                       0x000D    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE4_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE5                       0x000E    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE5_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE6                       0x000F    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE6_SIZE                  0x1
#define TAS_BSRAM_EXPIRY_LIST1_GATE7                       0x0010    //32B total for one gate.
#define TAS_BSRAM_EXPIRY_LIST1_GATE7_SIZE                  0x1
#define PORT_Q0_CONTEXT_SLOT_PRU1                          0x0011    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q0_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PORT_Q1_CONTEXT_SLOT_PRU1                          0x0012    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q1_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PORT_Q2_CONTEXT_SLOT_PRU1                          0x0013    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q2_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PORT_Q3_CONTEXT_SLOT_PRU1                          0x0014    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q3_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PORT_Q4_CONTEXT_SLOT_PRU1                          0x0015    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q4_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PORT_Q5_CONTEXT_SLOT_PRU1                          0x0016    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q5_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PORT_Q6_CONTEXT_SLOT_PRU1                          0x0017    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q6_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PORT_Q7_CONTEXT_SLOT_PRU1                          0x0018    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q7_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q0_CONTEXT_SLOT_PRU1                          0x0019    //Combined context (MSMC + Desc) for Port Tx queue
#define HOST_Q0_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q1_CONTEXT_SLOT_PRU1                          0x001A    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q1_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q2_CONTEXT_SLOT_PRU1                          0x001B    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q2_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q3_CONTEXT_SLOT_PRU1                          0x001C    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q3_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q4_CONTEXT_SLOT_PRU1                          0x001D    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q4_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q5_CONTEXT_SLOT_PRU1                          0x001E    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q5_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q6_CONTEXT_SLOT_PRU1                          0x001F    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q6_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define HOST_Q7_CONTEXT_SLOT_PRU1                          0x0020    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q7_CONTEXT_SLOT_PRU1_SIZE                     0x1
#define PSI_TXTS_INFO_SLOT_PRU1                            0x0021    //Store Info chunk for Tx TS PSI transaction
#define PSI_TXTS_INFO_SLOT_PRU1_SIZE                       0x1
#define PRU1_BS_OFFSETS_END                                0x0022    //_Small_Description_
#define PRU1_BSRAM_END_OFFSET                              0x0022

// total PRU1_BSRAM memory usage : 1.0625 KB from total of 4.0KB 

//************************************************************************************
//
// Memory Usage of : RTU0_BSRAM
//
//************************************************************************************

#define RTU0_BSRAM_START_OFFSET                            0x0000
#define PSI_MGR_INFO_SLOT_RTU0                             0x0000    //Stores Management Frame PSI Info chunk
#define PSI_MGR_INFO_SLOT_RTU0_SIZE                        0x1
#define PORT_Q0_CONTEXT_SLOT_RTU0                          0x0001    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q0_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define PORT_Q1_CONTEXT_SLOT_RTU0                          0x0002    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q1_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define PORT_Q2_CONTEXT_SLOT_RTU0                          0x0003    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q2_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define PORT_Q3_CONTEXT_SLOT_RTU0                          0x0004    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q3_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define PORT_Q4_CONTEXT_SLOT_RTU0                          0x0005    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q4_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define PORT_Q5_CONTEXT_SLOT_RTU0                          0x0006    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q5_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define PORT_Q6_CONTEXT_SLOT_RTU0                          0x0007    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q6_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define PORT_Q7_CONTEXT_SLOT_RTU0                          0x0008    //Combined context (MSMC + Desc) for Port Tx queue
#define PORT_Q7_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q0_CONTEXT_SLOT_RTU0                          0x0009    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q0_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q1_CONTEXT_SLOT_RTU0                          0x000A    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q1_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q2_CONTEXT_SLOT_RTU0                          0x000B    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q2_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q3_CONTEXT_SLOT_RTU0                          0x000C    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q3_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q4_CONTEXT_SLOT_RTU0                          0x000D    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q4_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q5_CONTEXT_SLOT_RTU0                          0x000E    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q5_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q6_CONTEXT_SLOT_RTU0                          0x000F    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q6_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define HOST_Q7_CONTEXT_SLOT_RTU0                          0x0010    //Combined context (MSMC + Desc) for Host Tx queue
#define HOST_Q7_CONTEXT_SLOT_RTU0_SIZE                     0x1
#define RTU0_BSRAM_END_OFFSET                              0x0011

// total RTU0_BSRAM memory usage : 0.53125 KB from total of 16.0KB 

//************************************************************************************
//
// Memory Usage of : RTU1_BSRAM
//
//************************************************************************************

#define RTU1_BSRAM_START_OFFSET                            0x0000
#define RTU1_BS_OFFSETS_END                                0x0000    //_Small_Description_
#define RTU1_BSRAM_END_OFFSET                              0x0000

// total RTU1_BSRAM memory usage : 0.0 KB from total of 16.0KB 

//************************************************************************************
//
// Memory Usage of : PA_STAT
//
//************************************************************************************

#define PA_STAT_START_OFFSET                               0x0000
#define PA_STAT_64b_START_OFFSET                           0x0000    //Start of 64 bits PA_STAT counters
#define NRT_HOST_RX_BYTE_COUNT_PASTATID                    0x0000    //Number of valid bytes sent by Rx PRU to Host on PSI. Currently disabled
#define NRT_HOST_RX_BYTE_COUNT_PASTATID_SIZE               0x2
#define NRT_HOST_TX_BYTE_COUNT_PASTATID                    0x0002    //Number of valid bytes copied by RTU0 to Tx queues. Currently disabled
#define NRT_HOST_TX_BYTE_COUNT_PASTATID_SIZE               0x2
#define PA_STAT_32b_START_OFFSET                           0x0080    //Start of 32 bits PA_STAT counters
#define NRT_HOST_RX_PKT_COUNT_PASTATID                     0x0080    //Number of valid packets sent by Rx PRU to Host on PSI
#define NRT_HOST_RX_PKT_COUNT_PASTATID_SIZE                0x4
#define NRT_HOST_TX_PKT_COUNT_PASTATID                     0x0084    //Number of valid packets copied by RTU0 to Tx queues
#define NRT_HOST_TX_PKT_COUNT_PASTATID_SIZE                0x4
#define NRT_RTU0_PACKET_DROPPED_PASTATID                   0x0088    //PRU diagnostic error counter which increments when RTU0 drops a locally injected packet due to port disabled or rule violation
#define NRT_RTU0_PACKET_DROPPED_PASTATID_SIZE              0x4
#define NRT_PORT_Q0_OVERFLOW_PASTATID                      0x008C    //Port Tx Q Overflow Counters
#define NRT_PORT_Q0_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_PORT_Q1_OVERFLOW_PASTATID                      0x0090    //Port Tx Q Overflow Counters
#define NRT_PORT_Q1_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_PORT_Q2_OVERFLOW_PASTATID                      0x0094    //Port Tx Q Overflow Counters
#define NRT_PORT_Q2_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_PORT_Q3_OVERFLOW_PASTATID                      0x0098    //Port Tx Q Overflow Counters
#define NRT_PORT_Q3_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_PORT_Q4_OVERFLOW_PASTATID                      0x009C    //Port Tx Q Overflow Counters
#define NRT_PORT_Q4_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_PORT_Q5_OVERFLOW_PASTATID                      0x00A0    //Port Tx Q Overflow Counters
#define NRT_PORT_Q5_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_PORT_Q6_OVERFLOW_PASTATID                      0x00A4    //Port Tx Q Overflow Counters
#define NRT_PORT_Q6_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_PORT_Q7_OVERFLOW_PASTATID                      0x00A8    //Port Tx Q Overflow Counters
#define NRT_PORT_Q7_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q0_OVERFLOW_PASTATID                      0x00AC    //Host Tx Q Overflow Counters
#define NRT_HOST_Q0_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q1_OVERFLOW_PASTATID                      0x00B0    //Host Tx Q Overflow Counters
#define NRT_HOST_Q1_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q2_OVERFLOW_PASTATID                      0x00B4    //Host Tx Q Overflow Counters
#define NRT_HOST_Q2_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q3_OVERFLOW_PASTATID                      0x00B8    //Host Tx Q Overflow Counters
#define NRT_HOST_Q3_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q4_OVERFLOW_PASTATID                      0x00BC    //Host Tx Q Overflow Counters
#define NRT_HOST_Q4_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q5_OVERFLOW_PASTATID                      0x00C0    //Host Tx Q Overflow Counters
#define NRT_HOST_Q5_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q6_OVERFLOW_PASTATID                      0x00C4    //Host Tx Q Overflow Counters
#define NRT_HOST_Q6_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_Q7_OVERFLOW_PASTATID                      0x00C8    //Host Tx Q Overflow Counters
#define NRT_HOST_Q7_OVERFLOW_PASTATID_SIZE                 0x4
#define NRT_HOST_EGRESS_Q_PRE_OVERFLOW_PASTATID            0x00CC    //Host Egress Q (Pre-emptible) Overflow Counter
#define NRT_HOST_EGRESS_Q_PRE_OVERFLOW_PASTATID_SIZE       0x4
#define NRT_HOST_EGRESS_Q_EXP_OVERFLOW_PASTATID            0x00D0    //Host Egress Q (Express) Overflow Counter. redundant
#define NRT_HOST_EGRESS_Q_EXP_OVERFLOW_PASTATID_SIZE       0x4
#define NRT_PSI_ABORT_CNT_PASTATID                         0x00D4    //_Small_Description_
#define NRT_PSI_ABORT_CNT_PASTATID_SIZE                    0x4
#define NRT_WRONG_Q_STATUS_PASTATID                        0x00D8    //Not Used, will be removed
#define NRT_WRONG_Q_STATUS_PASTATID_SIZE                   0x4
#define NRT_DROPPED_PKT_PASTATID                           0x00DC    //Incremented if a packet is dropped because of a rule violation
#define NRT_DROPPED_PKT_PASTATID_SIZE                      0x4
#define NRT_RX_ERROR_PASTATID                              0x00E0    //Incremented if there was a CRC error or Min/Max frame error
#define NRT_RX_ERROR_PASTATID_SIZE                         0x4
#define RX_EOF_RTU_DS_INVALID_PASTATID                     0x00E4    //RTU diagnostic counter increments when RTU detects Data Status invalid condition
#define RX_EOF_RTU_DS_INVALID_PASTATID_SIZE                0x4
#define RX_B1_NRT_ENTRY_PASTATID                           0x00E8    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] PRU diagnostic counter which increments when NRT path of RX_B1 handling is invoked
#define RX_B1_NRT_ENTRY_PASTATID_SIZE                      0x4
#define RX_Bn_NRT_ENTRY_PASTATID                           0x00EC    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] PRU diagnostic counter which increments when NRT path of RX_Bn handling is invoked
#define RX_Bn_NRT_ENTRY_PASTATID_SIZE                      0x4
#define RX_EOF_NRT_ENTRY_PASTATID                          0x00F0    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] PRU diagnostic counter which increments when NRT path of RX_EOF handling is invoked
#define RX_EOF_NRT_ENTRY_PASTATID_SIZE                     0x4
#define NRT_TX_DROPPED_PACKET_PASTATID                     0x00F4    //Counter for packets dropped via NRT TX path
#define NRT_TX_DROPPED_PACKET_PASTATID_SIZE                0x4
#define NRT_TX_TS_DROPPED_PACKET_PASTATID                  0x00F8    //Counter for packets with TS flag dropped via NRT TX path
#define NRT_TX_TS_DROPPED_PACKET_PASTATID_SIZE             0x4
#define NRT_INF_PORT_DISABLED_PASTATID                     0x00FC    //PRU diagnostic error counter which increments when RX frame is dropped due to port is disabled
#define NRT_INF_PORT_DISABLED_PASTATID_SIZE                0x4
#define NRT_INF_SAV_PASTATID                               0x0100    //PRU diagnostic error counter which increments when RX frame is dropped due to SA violation
#define NRT_INF_SAV_PASTATID_SIZE                          0x4
#define NRT_INF_SA_BL_PASTATID                             0x0104    //PRU diagnostic error counter which increments when RX frame is dropped due to SA black listed
#define NRT_INF_SA_BL_PASTATID_SIZE                        0x4
#define NRT_INF_PORT_BLOCKED_PASTATID                      0x0108    //PRU diagnostic error counter which increments when RX frame is dropped due to port blocked and not a special frame
#define NRT_INF_PORT_BLOCKED_PASTATID_SIZE                 0x4
#define NRT_INF_AFT_DROP_TAGGED_PASTATID                   0x010C    //PRU diagnostic error counter which increments when RX frame is dropped due to tagged
#define NRT_INF_AFT_DROP_TAGGED_PASTATID_SIZE              0x4
#define NRT_INF_AFT_DROP_PRIOTAGGED_PASTATID               0x0110    //PRU diagnostic error counter which increments when RX frame is dropped due to priority tagged
#define NRT_INF_AFT_DROP_PRIOTAGGED_PASTATID_SIZE          0x4
#define NRT_INF_AFT_DROP_NOTAG_PASTATID                    0x0114    //PRU diagnostic error counter which increments when RX frame is dropped due to untagged
#define NRT_INF_AFT_DROP_NOTAG_PASTATID_SIZE               0x4
#define NRT_INF_AFT_DROP_NOTMEMBER_PASTATID                0x0118    //PRU diagnostic error counter which increments when RX frame is dropped due to port not member of VLAN
#define NRT_INF_AFT_DROP_NOTMEMBER_PASTATID_SIZE           0x4
#define NRT_FDB_NO_SPACE_TO_LEARN                          0x011C    //PRU diagnostic error counter which increments when an entry couldn't be learned
#define NRT_FDB_NO_SPACE_TO_LEARN_SIZE                     0x4
#define NRT_FDB_LAST_ENTRY_OVERWRITTEN_FOR_LEARNING        0x0120    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] PRU diagnostic error counter which increments when the fourth entry is overwritten to accomodate leart MAC
#define NRT_FDB_LAST_ENTRY_OVERWRITTEN_FOR_LEARNING_SIZE   0x4
#define NRT_PREEMPT_BAD_FRAG_PASTATID                      0x0124    //Bad fragment Error Counter
#define NRT_PREEMPT_BAD_FRAG_PASTATID_SIZE                 0x4
#define NRT_PREEMPT_ASSEMBLY_ERROR_PASTATID                0x0128    //Fragment assembly Error Counter
#define NRT_PREEMPT_ASSEMBLY_ERROR_PASTATID_SIZE           0x4
#define NRT_PREEMPT_FRAG_COUNT_TX_PASTATID                 0x012C    //Fragment count in TX
#define NRT_PREEMPT_FRAG_COUNT_TX_PASTATID_SIZE            0x4
#define NRT_PREEMPT_ASSEMBLY_OK_PASTATID                   0x0130    //Assembly Completed
#define NRT_PREEMPT_ASSEMBLY_OK_PASTATID_SIZE              0x4
#define NRT_PREEMPT_FRAG_COUNT_RX_PASTATID                 0x0134    //Fragments received
#define NRT_PREEMPT_FRAG_COUNT_RX_PASTATID_SIZE            0x4
#define NRT_PREEMPT_DEBUG_GLOBAL_ERROR                     0x0138    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] Global Debug Error Counter
#define NRT_PREEMPT_DEBUG_GLOBAL_ERROR_SIZE                0x4
#define NRT_PREEMPT_DEBUG_SMDCx_PASTATID                   0x013C    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] Debug counter SMDCx
#define NRT_PREEMPT_DEBUG_SMDCx_PASTATID_SIZE              0x4
#define NRT_PREEMPT_DEBUG_SMDSx_PASTATID                   0x0140    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] Debug counter SMDSx
#define NRT_PREEMPT_DEBUG_SMDSx_PASTATID_SIZE              0x4
#define NRT_PREEMPT_DEBUG_EOF_MPKT_FRAG0_ERROR_PASTATID    0x0144    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] Debug counter - Error in SMDSx
#define NRT_PREEMPT_DEBUG_EOF_MPKT_FRAG0_ERROR_PASTATID_SIZE 0x4
#define NRT_PREEMPT_DEBUG_EOF_MPKT_FRAGX_ERROR_PASTATID    0x0148    //[DEBUG_L2_DIAGNOSTICS |  not in release binary] Debug counter - Error in SMDCx
#define NRT_PREEMPT_DEBUG_EOF_MPKT_FRAGX_ERROR_PASTATID_SIZE 0x4
#define PA_STAT_END_OFFSET                                 0x014C

// total PA_STAT memory usage : 0.32421875 KB from total of 2.0KB 


#endif // ____switch_mem_map_h
