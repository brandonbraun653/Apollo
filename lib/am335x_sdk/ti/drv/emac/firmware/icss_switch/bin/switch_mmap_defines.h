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
// file:     switch_mmap_defines.h
//
// brief:    Contains common defines used in the memory map for Ethernet Switch.
//           This file is shared by firmware and driver. Also includes common defines.

#ifndef ____switch_mmap_defines_h
#define ____switch_mmap_defines_h 1

//**************************** Ethernet Switch Constants *****************************
//all sizes in bytes except otherwise mentioned
#define NRT_TX_Q_HIGH_OFFSET                    0x0000

#define NRT_QUEUE_CONTEXT_SIZE                  (16)          
#define NRT_DESC_QUEUE_CONTEXT_SIZE             (16)          
#define NRT_PUSH_SIZE                           (32)
#define PACKET_DESC_SIZE                        (4)
#define BD_CUT_THROUGH_MAGIC_VALUE              (0xBB8)     //used to indicate cut-through. This is an illegal packet size and does not overlap
#define NRT_PRE_EMPTION_SIZE_THRESHOLD          (64)

#define R31_ERROR_BITS_MASK                     0x0188  //Mask for extracting CRC, Min/Max errors from R31 bits. Refer MII RT Spec

#define RX_B0_QNUM_SPECIAL_VALUE                0xFF    //special pattern used to wait for IPC SPAD values from RTU0

//queue numbers
#define QUEUE_0                                 (0)
#define QUEUE_1                                 (1)
#define QUEUE_2                                 (2)
#define QUEUE_3                                 (3)
#define QUEUE_4                                 (4)
#define QUEUE_5                                 (5)
#define QUEUE_6                                 (6)
#define QUEUE_7                                 (7)

#define PORT_1_ID                               (1)
#define PORT_2_ID                               (2)
#define UNDIRECTED_PKT_ID                       (0)

//if bucket size is changed in firmware then this too should be changed
//because it directly impacts FDB ageing calculation
#define NUMBER_OF_FDB_BUCKET_ENTRIES            (4)
#define SIZE_OF_FDB                             (2048)  //This is fixed in ICSSG
//ageing interval in nanoseconds. 30s
#define DEFAULT_FDB_AGEING_INTERVAL             (0x6FC23AC00)

//MSMC queue sizes
#define NRT_NUM_PORT_QUEUES                     (16)                //Number of Port Tx queues for both ports. 8 each
#define NRT_NUM_HOST_QUEUES                     (16)                //Number of Host Tx queues for both ports. 8 each
#define NRT_NUM_HOST_EGRESS_QUEUES              (4)                 //Number of Host Egress queues for both ports. 2 each
#define NRT_PORT_QUEUE_SIZE                     (25 * 1024)         //25kB per port queue
#define NRT_HOST_QUEUE_SIZE                     (6400)              //~6.5kB per host queue
#define NRT_RESERVED_MEM                        (2048)

//Descriptor Q sizes
// See design doc. It's calculated as ((queue size) / 64) * 4 plus some additional descriptors for margin of safety
#define NRT_PORT_DESC_QUEUE_SIZE                (((NRT_PORT_QUEUE_SIZE + NRT_RESERVED_MEM)/64) + 29) * 4     // for 25kB queue size
#define NRT_HOST_DESC_QUEUE_SIZE                (((NRT_HOST_QUEUE_SIZE + NRT_RESERVED_MEM)/64) + 9) * 4   // for ~6kB queue size


//TAS sizes
#define TAS_LIST_EXPIRY_SIZE                    (8 * 8 * 4)        //8 queues * 8 expiry values (each queue has 8 expiry values) * 4 (size of expiry in bytes) = 256B

#define MTU_SIZE                                (2048)

#define MII_INTC_RX_ERROR_MASK                  (0x13)      //Mask to extract CRC and Rx error from INCT bits 32-63
//Bit 32 : PRU0_RX_ERR, 33 : PRU0_RX_ERR32, 36 : PRU0_RX_CRC

//default priority for packets without VLAN tag and special packet type
#define DEFAULT_P1_PRIORITY                     (0)         //default priority for P1
#define DEFAULT_P2_PRIORITY                     (0)         //default priority for P2
#define DEFAULT_HOST_PRIORITY                   (0)         //default priority for Host port

//---------------------PSI packet types----------------------
//They come in handy to match against R1, instead of comparing each bit field we do a single shot compare
#define INFO_PKT_META_DATA                      (0x0f000011) //Info packet type meta data which comes in R1. It has bit 0 (sop), bit 4(lastw) set indicating it's the first and last packet of it's type

#define INFO_PKT_TYPE                           (0x00)       //Info packet type in R1 metadata. R1.b2
                                                             //it is first and last chunk of it's type. packet type is 0 and size is f or 15
//Info packet has the following meta data inside
//R2.t23 indicates if Host has inserted CRC in packet. Not used by switch
//R4.b2 tells if it's a directed packet. R4.b2 = 0(undirected), R4.b2 = 1(directed. P1), R4.b2 = 2(directed. P2)
                                                             
#define CTRL_PKT_META_DATA                      (0x0f100011) //Control packet type meta data which comes in R1. It has bit 0 (sop), bit 4(lastw) set indicating it's the first and last packet of it's type

#define CTRL_PKT_TYPE                           (0x10)       //Ctrl packet type in R1 metadata. R1.b2

                                                             //it is first and last chunk of it's type. packet type is 0x10 and size is 15
                                                             
#define STATUS_PKT_META_DATA                    (0x0f180012) //Status packet type meta data which comes in R1. It has bit 0 (sop), bit 4(lastw) set indicating

#define STATUS_PKT_TYPE                         (0x18)       //Status packet type in R1 metadata. R1.b2
                                                             //it is first and last chunk of it's type. packet type is 0x18 and size is 15
                                                             
#define DATA_FIRST_PKT_META_DATA                (0x10140000) //Data packet type meta data which comes in R1. This is for the all chunks (except last) and 
                                                             //doesn't have lastw set. packet type is 0x14 and size is 15
                                                             
#define DATA_LAST_PKT_META_DATA                 (0x00140010) //Data packet type meta data which comes in R1. This is for the last chunk and has
                                                             //lastw set. packet type is 0x14 and size is 0 because size determined by xout by widget
                                                             
#define DATA_LAST_PKT_META_DATA_EOP             (0x00140012) //Same as above but has eop also set
                                                             
#define DATA_PKT_TYPE                           (0x14)       //Data packet type in R1 metadata. R1.b2

//FIXME : Temporary. Need to align with EMAC
#define NRT_PACKET_DROP_TS_ERROR_CODE               (0xBAADF00D)

#endif //____switch_mmap_defines_h

