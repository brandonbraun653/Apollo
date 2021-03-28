/**
 *  \file   omapl138/cppi41dma.h
 *
 *  \brief  CPPI 4.1 DMA related function prototypes
 *
 *  This file contains the API prototypes for CPPI 4.1 DMA
*/

/*
* Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef __CPPI41DMA_H
#define __CPPI41DMA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "musb.h"
#include"hw_usb.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

#if defined(ccs) ||             \
    defined(codered) ||         \
    defined(gcc) ||             \
    defined(rvmdk) ||           \
    defined(__ARMCC_VERSION) || \
    defined(sourcerygxx)
#define CPPI_DMA_PACKED __attribute__ ((packed))
#elif defined(ewarm) || defined(__IAR_SYSTEMS_ICC__)
#define CPPI_DMA_PACKED
#elif defined(__TMS470__)
#if defined(__TI_TMS470_V7__) || (__TI_COMPILER_VERSION__ >= 5000000)
#define CPPI_DMA_PACKED __attribute__ ((packed))
#else
#warn The packed attribute is not supported by this version of the TI ARM CGT. \
      Please upgrade to version 5.x or use an alternate toolchain instead.
#define CPPI_DMA_PACKED
#endif
#elif defined(_TMS320C6X)
#define CPPI_DMA_PACKED __attribute__ ((packed))
#else
#error Unrecognized COMPILER!
#endif

#define USB_TX_MODE_SHIFT(n)       (((((n) - 1) << 1) * 2))
#define USB_RX_MODE_SHIFT(n)       ((((((n) - 1) << 1) * 2) + 16))

#if defined (am335x_15x15) || defined(am335x)
#define USB_OTGBASE USBSS_BASE

/*Interrupt status macros*/
#define CPDMA_TX_PENDING 0x60000000
#define CPDMA_RX_PENDING 0x00006000
#else
#define USB_OTGBASE USB_0_OTGBASE

/*Interrupt status macros*/
#define CPDMA_TX_PENDING 0x03000000
#define CPDMA_RX_PENDING 0x0C000000
#endif

#define CPDMA_STAR_0_PEND	0x1
#define CPDMA_STAR_1_PEND	0x2

/*Link RAM size*/
#define LINK_RAM_SIZE						1024
#define DESC_REGION_SIZE					(1024 * 20) + 64

/* Maximum packet length for GRNDS mode*/
#define GRNDIS_MAX_PACKET_LENGTH			512

#define  CPDMA_NUMOF_BUFFERS				256

#ifdef USB_MODE_HS_DISABLE
	#define USB_PACKET_LENGTH				64
#else
	#define USB_PACKET_LENGTH				512
#endif /* USB_MODE_HS_DISABLE */

#define QUEUE_MGR_DESCSIZE  				0x100
#define QUEUE_MGR_REGSIZE   				0x3

/* Defines for The tear down Q*/
#define QUEUE_TDDESC_MGR_DESCSIZE            0x0   /* DescSize in # of bytes: 2^(5+0) = 32 Bytes */
#define QUEUE_TDDESC_MGR_REGSIZE             0x0   /* RegionSize in # of desc: 2^(5+1) = 64 Desc */
#define QUEUE_TDDESC_STARTINDEX_SHIFT        16
#define QUEUE_TDDESC_STARTINDEX      	     0
#define MAX_TDD_NUM                          32 	  /* Max TearDown Desc Count: QUEUE_TDDESC_MGR_REGSIZE */

#define CPDMA_DESC_TYPE_TD_SHIFT    		 27
#define CPDMA_DESC_TYPE_TD                	 0x13

#define MAX_BD_NUM							256
#define NUM_OF_RX_BDs						10

#define NUMOF_USB_INSTANCE					1
#define BYTE_ALIGNMENT						64

#define SCHEDULER_ENABLE_SHFT				31
#define CLAER_INTDO_STATUS					0x03

#define SIZE_OF_SINGLE_BD					0X0A
#define SIZE_OF_TEARDOWNDESC             	 0x02 /* 32 bytes */

#define	CPDMA_BUFFER_NOT_USED				0
#define CPDMA_BUFFER_USED					1

#define CPDMA_BD_PACKET_TYPE				16
#define CPDMA_TEARDOWN_DESC_TYPE             0x13

#define SOP									1
#define MOP									2
#define EOP									4

#define DMA_TX_IN_PROGRESS					1
#define DMA_TX_COMPLETED					0

#define CPDMA_TD_FD_QUEUE_CONTROL_REG       0x1004
#define CPDMA_TX_CHANNEL_CONFIG_REG		 	0x1800
#define CPDMA_RX_CHANNEL_CONFIG_REG 		0x1808
#define CPDMA_RX_CHANNEL_REG_A      		0x180C
#define CPDMA_RX_CHANNEL_REG_B      		0x1810
#define CPDMA_SCHED_CONTROL_REG        		0x2000
#define CPDMA_SCHED_TABLE_0            		0x2800
#define CPDMA_SCHED_TABLE_1            		0x2804

#define CPDMA_INTD_0_REGISTER				0x3200
#define CPDMA_CLEAR_INTD_0_STATUS			0x3280
#define	CPDMA_LRAM_0_BASE 					0x4080
#define	CPDMA_LRAM_0_SIZE 					0x4084
#define	CPDMA_LRAM_1_BASE 					0x4088
#define CPDMA_PEND_0_REGISTER				0x4090
#define CPDMA_PEND_1_REGISTER				0x4094
#define CPDMA_PEND_2_REGISTER				0x4098
#define CPDMA_PEND_3_REGISTER				0x409C
#define CPDMA_PEND_4_REGISTER				0x40A0
#define CPDMA_QUEUEMGR_REGION_0           	0x5000
#define CPDMA_QUEUEMGR_REGION_0_CONTROL   	0x5004

#define CPDMA_QUEUE_REGISTER_D			    0x600C
#define CPDMA_QUEUE_STATUS_A                 0x7000
#define CPDMA_QUEUE_STATUS_A_COUNT_MASK   	 0x3FFF


//Bit Fields for Channel Config
#define SCHEDULE_RX_CHANNEL					0x83828180
#define SCHEDULE_TX_CHANNEL					0x03020100
#define NUM_OF_SCHEDULER_ENTRIES			8

#define CPDMA_RX_CHANNEL_ENABLE				0x81004000
#define CPDMA_TX_CHANNEL_ENABLE				0x80000000

/* Tx Channel N Global Configuration Register bits */
#define DMA_CH_TX_ENABLE_SHIFT		31
#define DMA_CH_TX_ENABLE_MASK		(1 << DMA_CH_TX_ENABLE_SHIFT)
#define DMA_CH_TX_TEARDOWN_SHIFT	30
#define DMA_CH_TX_TEARDOWN_MASK		(1 << DMA_CH_TX_TEARDOWN_SHIFT)
#define DMA_CH_TX_DEFAULT_QMGR_SHIFT	12
#define DMA_CH_TX_DEFAULT_QMGR_MASK	(3 << DMA_CH_TX_DEFAULT_QMGR_SHIFT)
#define DMA_CH_TX_DEFAULT_QNUM_SHIFT	0
#define DMA_CH_TX_DEFAULT_QNUM_MASK	(0xfff << DMA_CH_TX_DEFAULT_QNUM_SHIFT)

/* Clear Auto set for TX endpoint */
#define CPDMA_TX_CLR_AUTO_SET				0x7FFF

/* Set DMAReqEnab & DMAReqMode for TX */
#define CPDMA_TX_SET_REQ_ENABLE				0x1400

/* Clear AUTOCLEAR and DMAReqMode */
#define CPDMA_RX_CLR_AUTO_CLEAR				0x77FF

/* Set DMAReqEnab */
#define CPDMA_RX_SET_REQ_ENABLE				0x2000
/* Clear DMAReqEnab & DMAReqMode */
#define CPDMA_RX_CLR_REQ_ENABLE				0xDFFF

/* Clear DMAReqEnab & DMAReqMode */
#define CPDMA_TX_CLR_REQ_ENABLE				0xEBFF

/* Bit fields  for Schduler controll reg */
#define ENABLE_CPPIDMA						0x1
#define DISABLE_CPPIDMA						0x0

/* DMA directions */
#define CPDMA_DIR_RX						0x1
#define CPDMA_DIR_TX 						0x0

/*Bit Fields to set the DMA Mode */
#define CPDMA_MODE_ENABLE_GLOBAL_RNDIS		0x00000010

/* DMA mode */
#define CPDMA_MODE_SET_TRANSPARENT			0x0
#define CPDMA_MODE_SET_RNDIS				0x1
#define CPDMA_MODE_SET_LINUXCDC				0x2
#define CPDMA_MODE_SET_GRNDIS				0x3

#define NUM_TX_SUBMITQ						8
#define NUM_TX_COMPQ						4
#define NUM_RX_COMPQ						4

/* TX submit q */
#define	TX_SUBMITQ1							16
#define TX_SUBMITQ2 						17
#define TX_SUBMITQ3							18
#define TX_SUBMITQ4							19
#define TX_SUBMITQ5 						20
#define TX_SUBMITQ6							21
#define TX_SUBMITQ7 						22
#define TX_SUBMITQ8							23

/* TX Completion queue */
#define TX_COMPQ1							24
#define TX_COMPQ2							25

/* RX Completion queue */
#define RX_COMPQ1							26
#define RX_COMPQ2							27

#define USB0_TEARDOWNQ1             	    15

#define CPPI41_TEARDOWN_TX_RX_SHIFT	16
#define CPPI41_TEARDOWN_TX_RX_MASK	(1 << CPPI41_TEARDOWN_TX_RX_SHIFT)
#define CPPI41_TEARDOWN_DMA_NUM_SHIFT	10
#define CPPI41_TEARDOWN_DMA_NUM_MASK	(0x3f << CPPI41_TEARDOWN_DMA_NUM_SHIFT)
#define CPPI41_TEARDOWN_CHAN_NUM_SHIFT	0
#define CPPI41_TEARDOWN_CHAN_NUM_MASK	(0x3f << CPPI41_TEARDOWN_CHAN_NUM_SHIFT)

#define DMA_MULTIBUFFER_ALLOCATION          (0x1)

/*
 * CPPI 4.1 Teardown Descriptor
 */
typedef struct
{
	uint32_t channelNumber:6;
	uint32_t reserved2:4;
	uint32_t dmaNumber:6; /*DMA number*/
	uint32_t txrx:1; /*Tx=0; Rx=1*/
	uint32_t reserved1:10;
	uint32_t tearDownDescType:5;	/* Teardown information */
}CPPI_DMA_PACKED cppi41TearDownInfo;

typedef struct
{
	uint32_t teardown_info;	/* Teardown information */
	uint32_t reserved[7];	/* 28 byte padding */
}CPPI_DMA_PACKED cppi41TearDownDesc;

/* BD-PD structure */
typedef struct {
	uint32_t pktLength:22;
	uint32_t protSize:5;
	uint32_t hostPktType:5; 	/* This should be 16 */
}hPDWord0;

typedef struct {
	uint32_t dstTag:16; 		/* bits[15:0] always Zero */
	uint32_t srcSubChNum:5;	    /* bits[20:16] always Zero */
	uint32_t srcChNum:6; 		/* bits[26:21] */
	uint32_t srcPrtNum:5; 		/* bits[31:27] */
}hPDWord1;

typedef struct {
	uint32_t pktRetQueue:12; 	/* bits[11:0] */
	uint32_t pktRetQM:2; 		/* bits[13:12] */
	uint32_t onChip:1; 		    /* bit[14] */
	uint32_t retPolicy:1; 		/* bit[15] */
	uint32_t protoSpecific:4;	/* bits[19:16] */
	uint32_t rsv:6; 			/* bits[25:20] */
	uint32_t pktType:5; 		/* bits[30:26] */
	uint32_t pktErr:1; 		    /* bit[31] */
}hPDWord2;

typedef struct hostPacketDesc {
	hPDWord0 hPDword0;
	hPDWord1 hPDword1;
	hPDWord2 hPDword2;
	uint32_t buffLength;
	uint32_t buffAdd;
	struct hostPacketDesc *nextHBDptr;
	uint32_t gBuffLength;
	uint32_t gBuffAdd;

	uint8_t packetId;
	uint16_t endPoint;
	uint16_t channel;
	uint8_t devInst;
	void * reqContext;
	uint8_t reserved[18];

} hostPacketDesc ;

/* End point info structure for the application */
typedef struct
{
	 uint32_t endPoint;
	 uint16_t direction;
	 uint16_t dmaMode;

}endpointInfo;

/* End point inf for internal USB configuration. */
typedef struct
{
	uint32_t submitq;
	uint32_t complettionq;
	uint32_t tearDownq;
	uint16_t channel;
	uint16_t mode;
}configEndPointInfo;

typedef struct
{
uint32_t usbBaseAddress;
uint32_t otgBaseAddress;
configEndPointInfo rxEndPoint[NUM_USB_EP/2];
configEndPointInfo txEndPoint[NUM_USB_EP/2];

}usbInstance;

typedef struct
{
	/* TX submit queues */
	uint32_t txSubmitq[NUM_TX_SUBMITQ/2][2];

	/* TX Completion queues */
	uint32_t txCompletionq[NUM_TX_COMPQ];

	/* RX Completion queues */
	uint32_t rxCompletionq[NUM_RX_COMPQ];

	/* Pointers for BD Management */
	hostPacketDesc *tail_bd ;
	hostPacketDesc *head_bd;
	uint32_t *region0DescriptorAddress;

	/* Array of USB Instances */
	usbInstance usbInst[NUMOF_USB_INSTANCE];
}cppi41DmaInfo;


extern endpointInfo epInfo[];

void Cppi41DmaInit(uint16_t usbDevInst, endpointInfo *epInfo, uint16_t numOfEndPoints);

uint32_t dmaTxCompletion(uint16_t usbDevInst, uint32_t ulEndpoint);
uint32_t dmaRxCompletion(uint16_t usbDevInst, uint32_t ulEndpoint, uint32_t *pkLength );

void doDmaTxTransfer(uint16_t usbDevInst, uint8_t *buff,
								uint32_t length, uint32_t endPoint);

void doDmaRxTransfer(uint16_t usbDevInst, uint32_t length,
								uint8_t *buff, uint32_t endPoint);

void enableCoreTxDMA(uint16_t usbDevInst, uint32_t ulEndpoint);
void enableCoreRxDMA(uint16_t usbDevInst, uint32_t ulEndpoint);
void disableCoreRxDMA(uint16_t usbDevIns, uint32_t ulEndpoint);
void disableCoreTxDMA(uint16_t usbDevIns, uint32_t ulEndpoint);

uint32_t CppiDmaGetPendStatus(uint16_t usbDevInst);
uint32_t CppiDmaGetINTD0Status(uint16_t usbDevInst);

uint32_t * cppiDmaAllocBuffer();
void cppiDmaFreeBuffer(uint32_t *dataBuffer);
uint32_t * cppiDmaAllocnBuffer(uint32_t numOfBlocks);
void cppiDmaFreenBuffer(uint32_t *dataBuffer);
void cppiDmaHandleError(uint32_t usbDevInst);

/* Teardown related function declarations */
void Cppi41DmaInitTddPool(uint16_t usbDevInst );
int Cppi41DmaRxChTeardown(uint16_t usbDevInst, uint32_t ulEndpoint );
int Cppi41DmaTxChTeardown(uint16_t usbDevInst, uint32_t ulEndpoint );

#ifdef __cplusplus
}
#endif
#endif
