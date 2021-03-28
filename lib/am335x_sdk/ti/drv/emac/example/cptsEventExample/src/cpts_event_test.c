/**  
 * @file cpts_event_test.c
 *
 *   @n This function performs IEEE1588 Event tests. It formats and sends IEEE1588
 *      event packets to the CPSW and then receive the same packets since the CPSW
 *      is in loopback mode. It also verifies the receive packets and displat both
 *      Tx and Rx CPTS events.
 *
 *
 * @brief 
 *  Example to illustrate the usage of EMAC CPSW switch to send and receive IEEE1588 
 *  event packets  and process CPTS events using CPPI, QMSS low level drivers and 
 *  CSL.
 *
 * 	This example application does the following:
 * 	    (1) Initializes:
 * 	            (a) Queue Manager (QM) Subsystem 
 * 	            (b) Packet Accelerator (PA) CPPI DMA 
 * 	            (c) Ethernet Subsystem (Ethernet switch + CPTS + SGMII/RGMII + MDIO) 
 *                  - (Note: Applicable only for NO_BOOT mode)
 *
 * 	    (2) Sets up the CPPI descriptors and Queues required for sending and
 * 	        receiving data using Ethernet.
 * 	            (a) Uses Host descriptors
 *
 * 	    (3) Sends IEEE1588 event packets onto wire 
 *          The packets sent by the application are sent onto wire and 
 *          then be delivered to the same EMAC port through internal or 
 *          external loopback.
 *      
 *      (4) Application receives the IEEE1588 event packet, pop and display 
 *          the CPTS events.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015, Texas Instruments, Inc.
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
#include <ti/drv/emac/example/cptsEventExample/src/cpts_event_test.h>
#include <stdio.h>

/**************************************************************
************************** DEFINITIONS ************************
***************************************************************/
/*
 * Default test configuration for the silicon
 *
 * To run test at the CCS simulator
 *    cpswSimTest = 1
 *    cpswLpbkMode = CPSW_LOOPBACK_INTERNAL
 */
#ifdef  SIMULATOR_SUPPORT
int cpswSimTest = 1;
int cpswLpbkMode = CPSW_LOOPBACK_INTERNAL;
#else
int cpswSimTest = 0;
int cpswLpbkMode = CPSW_LOOPBACK_INTERNAL;
#endif

#ifdef __LINUX_USER_SPACE
uint32_t no_bootMode = FALSE;
/* Linux Specific global variables per process */
sock_h                 rmClientSocket;
sem_t                  mutex;
#else
uint32_t no_bootMode = TRUE;
#endif

/* IEEE1588F packet 1
 * Sync Message: Message Type = 0
 * mac dest = 01:0b:19:00:00:00
 */                         
//#pragma DATA_ALIGN(pkt1588F_1, 16);
uint8_t pkt1588F_1[] = {
        0x01, 0x1b, 0x19, 0x00, 0x00, 0x00,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x88, 0xf7,                                       /* Ethertype = IEEE1588 */
        0x00,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x2c,                                       /* Length */
        0x0F,                                             /* domain number */
        0x00,                                             /* reserved */
        0x02, 0x00,                                       /* flags 0x02: twoStep operation */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x01,                                       /* sequenceId */
        0x00,                                             /* controlField */
        0x00,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* originTimestamp */
        0x00, 0x00, 
        0x00, 0x00                                        /* padding */ 
        };    
        
        
/* IEEE1588F packet 2
 * Path Delay Request Message: Message Type = 2
 * mac dest = 01:80:C2:00:00:0E
 */                         
uint8_t pkt1588F_2[] = {
        0x01, 0x80, 0xC2, 0x00, 0x00, 0x0E,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00, 0x08, 0x88,                           /* VLAN: 0x0888 */
        0x88, 0xf7,                                       /* Ethertype = IEEE1588 */
        0x02,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x36,                                       /* Length */
        0x0F,                                             /* domain number */
        0x00,                                             /* reserved */
        0x02, 0x00,                                       /* flags 0x02: twoStep operation */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x02,                                       /* sequenceId */
        0x05,                                             /* controlField */
        0x0f,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* requestReceiptTimestamp */
        0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* requestingPortIdentity */
        0x00, 0x00, 
        };  
        
/* IEEE1588F packet 3
 * Announce Message: Message Type = 11 (0x0b)
 * mac dest = 01:0b:19:00:00:00
 */                         
uint8_t pkt1588F_3[] = {
        0x01, 0x1b, 0x19, 0x00, 0x00, 0x00,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x88, 0xa8, 0x07, 0x77,                           /* STag: 0x0777 */
        0x81, 0x00, 0x08, 0x88,                           /* VLAN: 0x0888 */
        0x88, 0xf7,                                       /* Ethertype = IEEE1588 */
        0x0b,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x40,                                       /* Length */
        0x0F,                                             /* domain number */
        0x00,                                             /* reserved */
        0x00, 0x0c,                                       /* flags: ptpTimescale and currentUtcOffsetValid */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x03,                                       /* sequenceId */
        0x05,                                             /* controlField */
        0x01,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* originTimestamp */
        0x00, 0x00,                                       
        0x00, 0x00,                                       /* currentUtcOffset */
        0x00,                                             /* reserved */
        0x60,                                             /* grandmasterPriority1 */
        0x00, 0x00, 0x00, 0x80,                           /* grandmasterClockQuality */
        0x63,                                             /* grandmasterPriority2 */
        0xff, 0xff, 0x00, 0x09, 0xba, 0xf8, 0x21, 0x00,   /* grandmasterIdentity */
        0x00, 0x80,                                       /* stepsRemoved */
        0x80,                                             /* timeSource */
        };                        
        
        
/* IEEE1588E packet 1
 * Sync Message: Message Type = 0
 * mac dest = 01:00:5e:00:01:81
 * ip dest = FF0E:0:0:0:0:0:0:181
 */                         
uint8_t pkt1588E_1[] = {
        0x01, 0x00, 0x5e, 0x00, 0x01, 0x81,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x86, 0xdd,                                       /* Ethertype = IPv6 */
	    0x60, 0x01, 0x01, 0x01,                           /* Iv6 header */
	    0x00, 0x34, 0x11, 0x01, 
	    0x20, 0x02,	0x9e, 0xda, 
	    0x6d, 0x30,	0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x04, 
	    0xFF, 0x0E, 0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00,	0x01, 0x81, 
        0x01, 0x3f, 0x01, 0x3f, 0x00, 0x34, 0x00, 0x00,   /* UDP header */
        0x10,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x2c,                                       /* Length */
        0x0E,                                             /* domain number */
        0x00,                                             /* reserved */
        0x02, 0x00,                                       /* flags 0x02: twoStep operation */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x04,                                       /* sequenceId */
        0x00,                                             /* controlField */
        0x00,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* originTimestamp */
        0x00, 0x00, 
        0x00, 0x00                                        /* padding */ 
        };    
                                
                                                      
/* IEEE1588D packet 2
 * Path Delay Request Message: Message Type = 2
 * mac dest = 01:00:5e:00:00:6b
 * ip dest = FF02:0:0:0:0:0:0:6B
 */                         
uint8_t pkt1588E_2[] = {
        0x01, 0x00, 0x5e, 0x00, 0x00, 0x6b,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x86, 0xdd,                                       /* Ethertype = IPv6 */
	    0x60, 0x01, 0x01, 0x01,                           /* Iv6 header */
	    0x00, 0x3e, 0x11, 0x01, 
	    0x20, 0x02,	0x9e, 0xda, 
	    0x6d, 0x30,	0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x04, 
	    0xFF, 0x02, 0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x6B, 
        0x01, 0x3f, 0x01, 0x3f, 0x00, 0x3e, 0x00, 0x00,   /* UDP header */
        0x12,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x36,                                       /* Length */
        0x0E,                                             /* domain number */
        0x00,                                             /* reserved */
        0x02, 0x00,                                       /* flags 0x02: twoStep operation */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x05,                                       /* sequenceId */
        0x05,                                             /* controlField */
        0x0f,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* requestReceiptTimestamp */
        0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* requestingPortIdentity */
        0x00, 0x00, 
        };  
        
/* IEEE1588D packet 3
 * Announce Message: Message Type = 11 (0x0b)
 * mac dest = 01:00:5e:00:01:81
 * ip dest = FF0X:0:0:0:0:0:0:181
 */                         
uint8_t pkt1588E_3[] = {
        0x01, 0x00, 0x5e, 0x00, 0x01, 0x81,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x86, 0xdd,                                       /* Ethertype = IPv6 */
	    0x60, 0x01, 0x01, 0x01,                           /* Iv6 header */
	    0x00, 0x48, 0x11, 0x01, 
	    0x20, 0x02,	0x9e, 0xda, 
	    0x6d, 0x30,	0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00, 0x00, 0x04, 
	    0xFF, 0x0E, 0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00,	0x00, 0x00, 
	    0x00, 0x00,	0x01, 0x81, 
        0x01, 0x40, 0x01, 0x40, 0x00, 0x48, 0x00, 0x00,   /* UDP header */
        0x1b,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x40,                                       /* Length */
        0x0E,                                             /* domain number */
        0x00,                                             /* reserved */
        0x00, 0x0c,                                       /* flags: ptpTimescale and currentUtcOffsetValid */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x06,                                       /* sequenceId */
        0x05,                                             /* controlField */
        0x01,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* originTimestamp */
        0x00, 0x00,                                       
        0x00, 0x00,                                       /* currentUtcOffset */
        0x00,                                             /* reserved */
        0x60,                                             /* grandmasterPriority1 */
        0x00, 0x00, 0x00, 0x80,                           /* grandmasterClockQuality */
        0x63,                                             /* grandmasterPriority2 */
        0xff, 0xff, 0x00, 0x09, 0xba, 0xf8, 0x21, 0x00,   /* grandmasterIdentity */
        0x00, 0x80,                                       /* stepsRemoved */
        0x80,                                             /* timeSource */
        };   
        
/* IEEE1588D packet 1
 * Sync Message: Message Type = 0
 * mac dest = 01:00:5e:00:01:81
 * ip dest = 224.0.1.129
 */                         
uint8_t pkt1588D_1[] = {
        0x01, 0x00, 0x5e, 0x00, 0x01, 0x81,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x08, 0x00,                                       /* Ethertype = IPv4 */
        0x45, 0x00, 0x00, 0x48, 0x45, 0xa9, 0x00, 0x00,   /* IPv4 header */
        0x01, 0x11, 0x00, 0x00, 0xc0, 0xa8, 0x02, 0x06,
        0xe0, 0x00, 0x01, 0x81,
        0x01, 0x3f, 0x01, 0x3f, 0x00, 0x34, 0x00, 0x00,   /* UDP header */
        0x10,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x2c,                                       /* Length */
        0x0D,                                             /* domain number */
        0x00,                                             /* reserved */
        0x02, 0x00,                                       /* flags 0x02: twoStep operation */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x07,                                       /* sequenceId */
        0x00,                                             /* controlField */
        0x00,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* originTimestamp */
        0x00, 0x00, 
        0x00, 0x00                                        /* padding */ 
        };    
                                
                                                      
/* IEEE1588D packet 2
 * Path Delay Request Message: Message Type = 2
 * mac dest = 01:00:5e:00:00:6b
 * ip dest = 224.0.0.107
 */                         
uint8_t pkt1588D_2[] = {
        0x01, 0x00, 0x5e, 0x00, 0x00, 0x6b,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x08, 0x00,                                       /* Ethertype = IPv4 */
        0x45, 0x00, 0x00, 0x52, 0x45, 0xaa, 0x00, 0x00,   /* IPv4 header */
        0x01, 0x11, 0x00, 0x00, 0xc0, 0xa8, 0x02, 0x06,
        0xe0, 0x00, 0x00, 0x6b,
        0x01, 0x3f, 0x01, 0x3f, 0x00, 0x3e, 0x00, 0x00,   /* UDP header */
        0x12,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x36,                                       /* Length */
        0x0D,                                             /* domain number */
        0x00,                                             /* reserved */
        0x02, 0x00,                                       /* flags 0x02: twoStep operation */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x08,                                       /* sequenceId */
        0x05,                                             /* controlField */
        0x0f,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* requestReceiptTimestamp */
        0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* requestingPortIdentity */
        0x00, 0x00, 
        };  
        
/* IEEE1588D packet 3
 * Announce Message: Message Type = 11 (0x0b)
 * mac dest = 01:00:5e:00:01:81
 * ip dest = 224.0.1.129
 */                         
uint8_t pkt1588D_3[] = {
        0x01, 0x00, 0x5e, 0x00, 0x01, 0x81,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x08, 0x00,                                       /* Ethertype = IPv4 */
        0x45, 0x00, 0x00, 0x5c, 0x45, 0xac, 0x00, 0x00,   /* IPv4 header */
        0x01, 0x11, 0x00, 0x00, 0xc0, 0xa8, 0x02, 0x06,
        0xe0, 0x00, 0x01, 0x81,
        0x01, 0x40, 0x01, 0x40, 0x00, 0x48, 0x00, 0x00,   /* UDP header */
        0x1b,                                             /* transport specific | message type */
        0x02,                                             /* reserved | PTP version */
        0x00, 0x40,                                       /* Length */
        0x0D,                                             /* domain number */
        0x00,                                             /* reserved */
        0x00, 0x0c,                                       /* flags: ptpTimescale and currentUtcOffsetValid */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* correction Fields */
        0x00, 0x00, 0x00, 0x00,                           /* reserved */
        0x00, 0xe0, 0xa6, 0xff, 0xfe, 0x66, 0x57, 0x04,   /* sourcePortIdentity */
        0x00, 0x00,                                       /* soure port ID */
        0x00, 0x09,                                       /* sequenceId */
        0x05,                                             /* controlField */
        0x01,                                             /* logMessageInterval */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* originTimestamp */
        0x00, 0x00,                                       
        0x00, 0x00,                                       /* currentUtcOffset */
        0x00,                                             /* reserved */
        0x60,                                             /* grandmasterPriority1 */
        0x00, 0x00, 0x00, 0x80,                           /* grandmasterClockQuality */
        0x63,                                             /* grandmasterPriority2 */
        0xff, 0xff, 0x00, 0x09, 0xba, 0xf8, 0x21, 0x00,   /* grandmasterIdentity */
        0x00, 0x80,                                       /* stepsRemoved */
        0x80,                                             /* timeSource */
        };                        
        
        
/* Goose packet 1
 * Ltype = 0x88b8
 * mac dest = 01:a0:f4:08:2f:77
 */                         
char pktGoose_1[] = {                                     
        0x01, 0xa0, 0xf4, 0x08, 0x2f, 0x77,               /* Dest MAC */
        0x00, 0xa0, 0xf4, 0x08, 0x2f, 0x77,               /* Src MAC  */
        0x88, 0xb8,                                       /* Ethertype = Goose */
        0x00, 0x01, 0x00, 0x91, 0x11, 0x00, 0x00, 0x00, 
        0x61, 0x81, 0x86, 0x80, 0x1a, 0x47, 0x45, 0x44, 
        0x65, 0x76, 0x69, 0x63, 0x65, 0x46, 0x36, 0x35, 
        0x30, 0x2f, 0x4c, 0x4c, 0x4e, 0x30, 0x00, 0x0A, 
        0x4f, 0x24, 0x67, 0x63, 0x62, 0x30, 0x31, 0x81, 
        0x03, 0x00, 0x9c, 0x40, 0x82, 0x18, 0x47, 0x45, 
        0x44, 0x65, 0x76, 0x69, 0x63, 0x65, 0x46, 0x36, 
        0x35, 0x30, 0x2f, 0x4c, 0x4c, 0x4e, 0x30, 0x24, 
        0x47, 0x4f, 0x4f, 0x53, 0x45, 0x31, 0x83, 0x0b, 
        0x46, 0x36, 0x35, 0x30, 0x5f, 0x47, 0x4f, 0x4f, 
        0x53, 0x45, 0x31, 0x84, 0x08, 0x38, 0x6e, 0xbb, 
        0xf3, 0x42, 0x17, 0x28, 0x0a, 0x85, 0x01, 0x01, 
        0x86, 0x01, 0x0a, 0x87, 0x01, 0x00, 0x88, 0x01, 
        0x01, 0x89, 0x01, 0x00, 0x8a, 0x01, 0x08, 0xab, 
        0x20, 0x83, 0x01, 0x00, 0x84, 0x03, 0x03, 0x00, 
        0x00, 0x83, 0x01, 0x00, 0x84, 0x03, 0x03, 0x00, 
        0x00, 0x83, 0x01, 0x00, 0x84, 0x03, 0x03, 0x00, 
        0x00, 0x83, 0x01, 0x00, 0x84, 0x03, 0x03, 0x00, 
        0x00 
        };
        
typedef struct cptsEvtPkts_s {
    char *name;
	uint8_t *data;
	int size;
} cptsEvtPkts_t;

cptsEvtPkts_t cptsEvtPkts[] = {

    /* IEEE1588 Annex F Packet 1 */
    {
        "IEEE1588 Annex F Sync Message",
        pkt1588F_1,
        sizeof(pkt1588F_1)
    },
    
    /* IEEE1588 Annex F Packet 2 */
    {
        "IEEE1588 Annex F Path Delay Request Message",
        pkt1588F_2,
        sizeof(pkt1588F_2)
    },
    
    /* IEEE1588 Annex F Packet 3 */
    {
        "IEEE1588 Annex F Announce Message",
        pkt1588F_3,
        sizeof(pkt1588F_3)
    },
    
    /* IEEE1588 Annex E Packet 1 */
    {
        "IEEE1588 Annex E Sync Message",
        pkt1588E_1,
        sizeof(pkt1588E_1)
    },
    
    /* IEEE1588 Annex E Packet 2 */
    {
        "IEEE1588 Annex E Path Delay Request Message",
        pkt1588E_2,
        sizeof(pkt1588E_2)
    },
    
    /* IEEE1588 Annex E Packet 3 */
    {
        "IEEE1588 Annex E Announce Message",
        pkt1588E_3,
        sizeof(pkt1588E_3)
    },
    
    /* IEEE1588 Annex D Packet 1 */
    {
        "IEEE1588 Annex D Sync Message",
        pkt1588D_1,
        sizeof(pkt1588D_1)
    },
    
    /* IEEE1588 Annex D Packet 2 */
    {
        "IEEE1588 Annex D Path Delay Request Message",
        pkt1588D_2,
        sizeof(pkt1588D_2)
    },
    
    /* IEEE1588 Annex D Packet 3 */
    {
        "IEEE1588 Annex D Announce Message",
        pkt1588D_3,
        sizeof(pkt1588D_3)
    },
    
    /* Goose Packet 1 */
    {
        "Goose",
        pktGoose_1,
        sizeof(pktGoose_1)
    },
    
};

/** ============================================================================
 *   @n@b Send1588Packet
 *
 *   @b Description
 *   @n This API is called to actually send out an IEEE1588 test packet data onto 
 *      wire using ethernet.
 *
 *   @param[in]
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
static int32_t Send1588Packet (cptsEvtPkts_t *pPkt)
{
    Cppi_Desc*      pCppiDesc;
    uint32_t        dataBufferSize;
    char            psFlags = EMAC_PORT_0;
    Cppi_DescTag    tag;
    
    /* Get a free descriptor from the global free queue we setup
     * during initialization.
     */
    if ((pCppiDesc = Qmss_queuePop (gTxFreeQHnd)) == NULL)
    {
        System_printf ("No Tx free descriptor. Cant run send/rcv test \n");
        return -1;
    }

    /* The descriptor address returned from the hardware has the
     * descriptor size appended to the address in the last 4 bits.
     *
     * To get the true descriptor size, always mask off the last
     * 4 bits of the address.
     */
    pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);

    dataBufferSize  = pPkt->size;
    Cppi_setData (  Cppi_DescType_HOST,
                    (Cppi_Desc *) pCppiDesc,
                    (uint8_t *) Convert_CoreLocal2GlobalAddr((uint32_t)pPkt->data),
                    dataBufferSize
                 );
    Cppi_setPacketLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, dataBufferSize);
        
    tag.srcTagHi  = 0;
    tag.srcTagLo  = 0;
    tag.destTagHi = 0;
    tag.destTagLo = psFlags;
    Cppi_setTag(Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, (Cppi_DescTag *)&tag); 
    
    /* Clear PS Data */
    Cppi_setPSLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, 0);
    
	/* Send the packet out the mac. */
    Qmss_queuePush (gPaTxQHnd[NSS_CPSW_QUEUE_ETH_INDEX_LITE], pCppiDesc, dataBufferSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
    
    /* Give some time for the CPSW to process the packet */
    CycleDelay (1000);

    return 0;
}

/** ============================================================================
 *   @n@b Verify1588Packet
 *
 *   @b Description
 *   @n This function verifies a 1588 packet received against the expected data and 
 *      returns 0 to inidcate success and -1 to indicate a mismatch.
 *
 *   @param[in]  
 *   @n pCppiDesc           Packet descriptor received.
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
static int32_t Verify1588Packet (cptsEvtPkts_t *pPkt, Cppi_Desc* pCppiDesc)
{
	Cppi_HostDesc               *pHostDesc;
	uint8_t                     *pDataBuffer;
    uint8_t                     *pMsg;
	int32_t                      i;
    CSL_CPTS_EVENTINFO           cptsEventInfo;
	
    pHostDesc = (Cppi_HostDesc *)pCppiDesc;
    
    System_printf ("%s packet received: \n", pPkt->name);
    
    /* Verify the packet matches what we had sent */
    pDataBuffer = (uint8_t *) pHostDesc->buffPtr;
    pMsg = (uint8_t *) pPkt->data;
    for (i = 0; i < pPkt->size; i++)  
    {
        if (pMsg[i] != pDataBuffer[i])  
        {
            System_printf ("Verify1588Packet: Byte %d expected 0x%02x, found 0x%02x\n", i, pMsg[i], pDataBuffer[i]);
            System_flush();

            /* Free the packet back to the Rx FDQ */
            pHostDesc->buffLen = pHostDesc->origBufferLen;
            Qmss_queuePush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
            return -1;
        }
    }
    
    /* Extract Tx Timestamp from CPTS event */
    CSL_CPTS_getEventInfo(&cptsEventInfo);
    CSL_CPTS_popEvent(); 
    System_printf ("CPTS Tx event (0x%x): Message Type 0x%x, Domain 0x%02x, SeqId 0x%04x, Tx timestamp 0x%08x%08x\n", 
                   cptsEventInfo.eventType, cptsEventInfo.msgType, cptsEventInfo.domain, cptsEventInfo.seqId, 
                   cptsEventInfo.timeStampHi, cptsEventInfo.timeStamp);
    CSL_CPTS_getEventInfo(&cptsEventInfo);
    CSL_CPTS_popEvent(); 
    System_printf ("CPTS Rx event (0x%x): Message Type 0x%x, Domain 0x%02x, SeqId 0x%04x, Rx timestamp 0x%08x%08x\n", 
                   cptsEventInfo.eventType, cptsEventInfo.msgType, cptsEventInfo.domain, cptsEventInfo.seqId, 
                   cptsEventInfo.timeStampHi, cptsEventInfo.timeStamp);
        
    /* Reset the buffer lenght and put the descriptor back on the free queue */    
    pHostDesc->buffLen = pHostDesc->origBufferLen;
    Qmss_queuePush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);

    /* Verify packet done. Return success. */
	return 0;
}

/**************************************************************
**************** EXAMPLE APP FUNCTIONS ************************
***************************************************************/


/** ============================================================================
 *   @n@b Cpts_EventTestApp
 *
 *   @b Description
 *   @n Example application that sets up the application, sends, receives
 *      data.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return
 *   @n None
 *
 * =============================================================================
 */
extern Qmss_QueueHnd gRxQHnd;
static CSL_CPSW_STATS  stats [CSL_CPSW_NUMSTATBLOCKS];

#ifdef __LINUX_USER_SPACE
void* Cpts_EventTestApp (void *args)
#else
void Cpts_EventTestApp (void)
#endif
{
	extern void view_ale_table(void);
	int32_t			i, numPkts;
    int             fPass = 1;

    System_printf ("**************************************************\n");
    System_printf ("************* CPTS Event Test Starts *************\n");
    System_printf ("**************************************************\n");
    System_flush();

#if RM
    if (setupRm ())
    {
      System_printf ("Function setupRm failed\n");
      System_flush();
      return;
    }
#endif
    /* Initialize the components required to run the example:
     *  (1) QMSS
     *  (2) CPPI
     *  (3) Ethernet switch subsystem + MDIO + SGMII
     */
    
    /* Initialize QMSS */
    if (Init_Qmss () != 0)
    {
        System_printf ("QMSS init failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("QMSS successfully initialized \n");
        System_flush();
    }

    /* Initialize CPPI */
    if (Init_Cppi () != 0)
    {
        System_printf ("CPPI init failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("CPPI successfully initialized \n");
        System_flush();
    }
 
#ifndef __LINUX_USER_SPACE
    if (no_bootMode == TRUE)
    {
        /* Initialize the CPSW switch */
        if (Init_Cpsw () != 0)
        {
            System_printf ("Ethernet subsystem init failed \n");
            System_flush();
            APP_exit (-1);
        }
        else
        {
            System_printf ("Ethernet subsystem successfully initialized \n");
            System_flush();
        }
    }
#endif

    /* Setup Tx */
    if (Setup_Tx () != 0)
    {
        System_printf ("Tx setup failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("Tx setup successfully done \n");
        System_flush();
    }

    /* Setup Rx */
    if (Setup_Rx () != 0)
    {
        System_printf ("Rx setup failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("Rx setup successfully done \n");
        System_flush();
    }

#if 0
#ifndef __LINUX_USER_SPACE
    System_printf ("CSL_CPSW_getStats before Packet Transmission ...\n");
    memset(stats, 0, sizeof(stats));
    cpsw_getStats(stats, 0);
    System_flush();
#endif
#endif
    
    /* Run all types of CPTS event packets through */
    numPkts = sizeof(cptsEvtPkts)/sizeof(cptsEvtPkts_t);
    
    for ( i = 0; i < numPkts; i++)
    {
        int j;
	    Cppi_Desc           *hd;
        
        if (Send1588Packet(&cptsEvtPkts[i]))
        {
            System_printf ("%s pkt: send error!\n", cptsEvtPkts[i].name);
            break;
        }
        
	    /* Wait for a data packet from PA */
        for (j = 0; j < 100; j++)  
        {
            CycleDelay (1000);
            if (Qmss_getQueueEntryCount (gRxQHnd) > 0)   
            {
                hd = (Cppi_Desc *)(((uint32_t)Qmss_queuePop (gRxQHnd)) & ~0xf);
                break;
            }
        } 
        
        if (j == 100)
        {
            System_printf ("%s pkt: receive timeout !\n", cptsEvtPkts[i].name);
            break;
        }
        
        if (Verify1588Packet(&cptsEvtPkts[i], hd) != 0)
        {
            System_printf ("%s pkt: receive error!\n", cptsEvtPkts[i].name);
            break;
        }
    }
    
    if (i < numPkts)
    {
	    System_printf("IEEE1588 event test failed!\n");
        fPass = 0;
    }

#if 0
#ifndef __LINUX_USER_SPACE
    System_printf ("CSL_CPSW_getStats after Packet Transmission ...\n");
    cpsw_getStats(stats, 1);
#endif
#endif
    if(fPass)
        System_printf("All tests have passed!\n");
    System_printf ("**************************************************\n");
    System_printf ("************** CPTS Event Test Ends **************\n");
    System_printf ("**************************************************\n");
    System_flush();

    /* Clear framework */
	if (clearFramework() < 0) 
	{
        System_printf ("Failed to Clean the example application \n");
        System_flush();
	}

#if (RM) && !defined(__LINUX_USER_SPACE)
    {
        int32_t rmResult;

        if ((rmResult = Rm_resourceStatus(rmHandle, FALSE)) != 0)
        {
            System_printf ("Error : Number of unfreed resources : %d\n", rmResult);
            System_flush();
        }
        else
        {
            System_printf ("All resources freed successfully\n");
            System_flush();
        }
    }
#endif
    /* Example application done. Return success */
    APP_exit (0);
    
}

/* Nothing past this point */

