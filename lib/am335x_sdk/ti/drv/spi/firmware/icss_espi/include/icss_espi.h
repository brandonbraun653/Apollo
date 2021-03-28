/*
*  TEXAS INSTRUMENTS TEXT FILE LICENSE
* 
*  Copyright (c) 2018 Texas Instruments Incorporated
* 
*  All rights reserved not granted herein.
*  
*  Limited License.  
* 
*  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive 
*  license under copyrights and patents it now or hereafter owns or controls to 
*  make, have made, use, import, offer to sell and sell ("Utilize") this software 
*  subject to the terms herein.  With respect to the foregoing patent license, 
*  such license is granted  solely to the extent that any such patent is necessary 
*  to Utilize the software alone.  The patent license shall not apply to any 
*  combinations which include this software, other than combinations with devices 
*  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
* 
*  Redistributions must preserve existing copyright notices and reproduce this license 
*  (including the above copyright notice and the disclaimer and (if applicable) source 
*  code license limitations below) in the documentation and/or other materials provided 
*  with the distribution.
*  
*  Redistribution and use in binary form, without modification, are permitted provided 
*  that the following conditions are met:
*  No reverse engineering, decompilation, or disassembly of this software is 
*  permitted with respect to any software provided in binary form.
*  Any redistribution and use are licensed by TI for use only with TI Devices.
*  Nothing shall obligate TI to provide you with source code for the software 
*  licensed and provided to you in object code.
*  
*  If software source code is provided to you, modification and redistribution of the 
*  source code are permitted provided that the following conditions are met:
*  Any redistribution and use of the source code, including any resulting derivative 
*  works, are licensed by TI for use only with TI Devices.
*  Any redistribution and use of any object code compiled from the source code
*  and any resulting derivative works, are licensed by TI for use only with TI Devices.
* 
*  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
*  may be used to endorse or promote products derived from this software without 
*  specific prior written permission.
* 
*  DISCLAIMER.
* 
*  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
*  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
*  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S 
*  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
*  GOODS OR SERVICES* LOSS OF USE, DATA, OR PROFITS* OR BUSINESS INTERRUPTION) HOWEVER 
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* file:   icss_espi.h
*
* brief: This is a common header file with all memory map configuration.
*
*
*  (C) Copyright 2017-2018, Texas Instruments, Inc
*
*/

#ifndef ICSS_ESPI_H
#define ICSS_ESPI_H

#include <stdint.h>

#if defined(SOC_AM335x)
#include <ti/drv/spi/soc/am335x/SPI_icss_hw.h>
#endif

#if defined(SOC_AM437x)
#include <ti/drv/spi/soc/am437x/SPI_icss_hw.h>
#endif

#define	ESPI_PACKET_MAX_SIZE (75U) /* Max size for an ESPI packet, 11 bytes header and 64 bytes data */
#define ESPI_PACKET_MAGIC_NUMBER (0x69U) /* Only one byte so CMD can fit in first word of RX/TX buf */

/********************************/
/** ESPI REGISTER DESCRIPTIONS **/ /* SHOULD BE IN SHARED MEMORY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/********************************/
/* ESPI Slave Registers */
#define ICSS_ESPI_SLAVE_REGISTERS_BASE	(0x0000)
#define ICSS_ESPI_SLAVE_REGISTER_SIZE	(0x0020)
/* Internal Slave Registers */
#define ICSS_ESPI_INTERNAL_SLAVE_REGISTERS_BASE	(0x0020)
#define ICSS_ESPI_INTERNAL_SLAVE_REGISTERS_SIZE	(0x0020)
/* RX Buffers */
#define ICSS_ESPI_RX_BUFFERS_BASE	(0x0040)
#define ICSS_ESPI_RX_BUFFERS_SIZE	(0x17C0)
/* TX Buffers */
#define ICSS_ESPI_TX_BUFFERS_BASE	(0x1800)
#define ICSS_ESPI_TX_BUFFERS_SIZE	(0x1800)


/**************************/
/** ESPI SLAVE REGISTERS **/
/**************************/
/* The Memory offset of ESPI Device Identification Register */
#define DEVICE_ID_REGISTER_BASE	(ICSS_ESPI_SLAVE_REGISTERS_BASE + 0x0000)
/* The Memory offset of ESPI General Capabilites and Configuration Register */
#define GENERAL_CAP_CON_REGISTER_BASE	(ICSS_ESPI_SLAVE_REGISTERS_BASE + 0x0004)
/* The Memory offset of ESPI Channel 0 Capabilites and Configuration Register */
#define CHAN0_CAP_CON_REGISTER_BASE	(ICSS_ESPI_SLAVE_REGISTERS_BASE + 0x0008)
/* The Memory offset of ESPI Channel 1 Capabilites and Configuration Register */
#define CHAN1_CAP_CON_REGISTER_BASE	(ICSS_ESPI_SLAVE_REGISTERS_BASE + 0x000C)
/* The Memory offset of ESPI Channel 2 Capabilites and Configuration Register */
#define CHAN2_CAP_CON_REGISTER_BASE	(ICSS_ESPI_SLAVE_REGISTERS_BASE + 0x0010)
/* The Memory offset of ESPI Channel 3 Capabilites and Configuration Register */
#define CHAN3_CAP_CON_REGISTER_BASE	(ICSS_ESPI_SLAVE_REGISTERS_BASE + 0x0014)
/* The Memory offset of the ESPI Slave Status Register */
#define STATUS_REGISTER_BASE          (ICSS_ESPI_SLAVE_REGISTERS_BASE + 0x0018)

/* ESPI Slave Status Register Bits*/
#define STATUS_PC_FREE_BIT		(0)
#define STATUS_NP_FREE_BIT		(1)
#define STATUS_VWIRE_FREE_BIT		(2)
#define STATUS_OOB_FREE_BIT		(3)
#define STATUS_PC_AVAIL_BIT		(4)
#define STATUS_NP_AVAIL_BIT		(5)
#define STATUS_VWIRE_AVAIL_BIT		(6)
#define STATUS_OOB_AVAIL_BIT		(7)
#define STATUS_FLASH_C_FREE_BIT		(8)
#define STATUS_FLASH_NP_FREE_BIT	(9)
#define STATUS_FLASH_C_AVAIL_BIT	(12)
#define STATUS_FLASH_NP_AVAIL_BIT	(13)

/******************************/
/** INTERNAL SLAVE REGISTERS **/
/******************************/
/* The register offset of ESPI status for host to read */
#define INTERNAL_STATUS_REGISTER_BASE	(ICSS_ESPI_INTERNAL_SLAVE_REGISTERS_BASE + 0x0000)
#define IPC_REGISTER_BASE		(ICSS_ESPI_INTERNAL_SLAVE_REGISTERS_BASE + 0x0004)

/* Internal Status Register */
#define CHAN0_NP_TXQ_FULL_BIT		(0x0)
#define CHAN0_PC_TXQ_FULL_BIT		(0x1)
#define RAISE_ALERT_FLAG_BIT		(0x7)

#define MAX_PACKET_SIZE			(75)


/****************/
/** RX BUFFERS **/
/****************/
/* CH0 NP RX Buffers */
#define CH0_NP_RX_BUFFER_BASE	(ICSS_ESPI_RX_BUFFERS_BASE + 0x0)
#define CH0_NP_RX_BUFFER_SIZE	(0x02F0)

/* CH0 PC RX Buffers */
#define CH0_PC_RX_BUFFER_BASE	(ICSS_ESPI_RX_BUFFERS_BASE + 0x2F0)
#define CH0_PC_RX_BUFFER_SIZE	(0x02F0)


/****************/
/** TX BUFFERS **/
/****************/
/* CH0 NP TX Buffers */
#define CH0_NP_TX_BUFFER_BASE	(ICSS_ESPI_TX_BUFFERS_BASE + 0x0)
#define CH0_NP_TX_BUFFER_SIZE	(0x0300)

/* CH0 PC TX Buffers */
#define CH0_PC_TX_BUFFER_BASE	(ICSS_ESPI_TX_BUFFERS_BASE + 0x300)
#define CH0_PC_TX_BUFFER_SIZE	(0x0300)

/**************************/
/** PRU to Host Messages **/
/**************************/
#define ICSS_ESPI_IPC_MSG_NONE	(0)
#define ICSS_ESPI_IPC_MSG_RESET	(1)
#define ICSS_ESPI_IPC_MSG_ERROR	(2)
#define ICSS_ESPI_IPC_MSG_RX_AVAIL	(3)


/*******************************/
/* Device ID Register Contents */
 /*******************************/
#define DEVICE_ID_VERSION_ID_OFFSET	(0)
#define DEVICE_ID_VERSION_ID_MASK	(0xFF)


typedef struct bitfield_s {
  uint8_t bit_offset;
  uint8_t mask;
} Reg_Bitfield;


/************************************************************/
/* General Capabilities and Configuration Register Contents */
/************************************************************/
/* struct general_cap_con_s { */
/*   uint32_t Base; */
/*   Reg_Bitfield CRC_Checking_Enable; */
/*   Reg_Bitfield Response_Modifier; */
/*   Reg_Bitfield Alert_Mode; */
/*   Reg_Bitfield IO_Mode_Select; */
/*   Reg_Bitfield IO_Mode_Support; */
/*   Reg_Bitfield Open_Drain_Alert_Select; */
/*   Reg_Bitfield Operating_Frequency; */
/*   Reg_Bitfield Open_Drain_Alert_Supported; */
/*   Reg_Bitfield Maximum_Frequency_Supported; */
/*   Reg_Bitfield Maximum_WAIT_STATE_Allowed; */
/*   Reg_Bitfield Channel_Supported; */
/* } ESPI_General_Cap_Con; */

/* CRC_CHECKING_ENABLE */
#define GENERAL_CAP_CON_CRC_CHECKING_ENABLE_OFFSET	(31)
#define GENERAL_CAP_CON_CRC_CHECKING_ENABLE_MASK	(0x1)
#define CRC_CHECKING_DISABLE				(0)
#define CRC_CHECKING_ENABLE				(1)

/* RESPONSE_MODIFIER */
#define GENERAL_CAP_CON_RESPONSE_MODIFIER_ENABLE_OFFSET	(30)
#define GENERAL_CAP_CON_RESPONSE_MODIFIER_ENABLE_MASK	(0x1)
#define RESPONSE_MODIFIER_ENABLE			(0)
#define RESPONSE_MODIFIER_DISABLE			(1)

/* ALERT_MODE */
#define GENERAL_CAP_CON_ALERT_MODE_OFFSET	(28)
#define GENERAL_CAP_CON_ALERT_MODE_MASK		(0x1)

/* IO_MODE_SELECT */
#define GENERAL_CAP_CON_IO_MODE_SELECT_OFFSET	(26)
#define GENERAL_CAP_CON_IO_MODE_SELECT_MASK	(0x3)

/* IO_MODE_SUPPORT */
#define GENERAL_CAP_CON_IO_MODE_SUPPORT_OFFSET	(24)
#define GENERAL_CAP_CON_IO_MODE_SUPPORT_MASK	(0x3)

/* OPEN_DRAIN_ALERT_SELECT */
#define GENERAL_CAP_CON_OPEN_DRAIN_ALERT_SELECT_OFFSET	(23)
#define GENERAL_CAP_CON_OPEN_DRAIN_ALERT_SELECT_MASK	(0x3)

/* OPERATING_FREQUENCY */
#define GENERAL_CAP_CON_OPERATING_FREQUENCY_OFFSET	(20)
#define GENERAL_CAP_CON_OPERATING_FREQUENCY_MASK	(0x7)

/* OPEN_DRAIN_ALERT_SUPPORTED */
#define GENERAL_CAP_CON_OPEN_DRAIN_ALERT_SUPPORTED_OFFSET	(19)
#define GENERAL_CAP_CON_OPEN_DRAIN_ALERT_SUPPORTED_MASK		(0x1)

/* MAXIMUM_FREQUENCY_SUPPORTED */
#define GENERAL_CAP_CON_MAXIMUM_FREQUENCY_SUPPORTED_OFFSET	(16)
#define GENERAL_CAP_CON_MAXIMUM_FREQUENCY_SUPPORTED_MASK	(0x7)

/* MAXIMUM_WAIT_STATE_ALLOWED */
#define GENERAL_CAP_CON_MAXIMUM_WAIT_STATE_ALLOWED_OFFSET	(12)
#define GENERAL_CAP_CON_MAXIMUM_WAIT_STATE_ALLOWED_MASK		(0xF)

/* CHANNEL_SUPPORTED */
#define GENERAL_CAP_CON_CHANNEL_SUPPORTED_OFFSET	(0)
#define GENERAL_CAP_CON_CHANNEL_SUPPORTED_MASK		(0xFF)

/**************************************************************/
/* Channel 0 Capabilities and Configuration Register Contents */
/**************************************************************/
/* struct chan0_cap_con_s { */
/*   uint32_t Base; */
/*   Reg_Bitfield Peripheral_Channel_Maximum_Read_Request; */
/*   Reg_Bitfield Peripheral_Channel_Maximum_Payload_Size_Selected; */
/*   Reg_Bitfield Peripheral_Channel_Maximum_Payload_Size_Supported; */
/*   Reg_Bitfield Bus_Master_Enable; */
/*   Reg_Bitfield Peripheral_Channel_Ready; */
/*   Reg_Bitfield Peripheral_Channel_Enable; */
/* } ESPI_Chan0_Cap_Con = { */
/*   CHAN0_CAP_CON_REGISTER_BASE, */
/*   { 12, 0b111 }, /\* Peripheral_Channel_Maximum_Read_Request *\/ */
/*   { 8, 0b111 }, /\* Peripheral_Channel_Maximum_Payload_Size_Selected *\/ */
/*   { 4, 0b111 }, /\* Peripheral_Channel_Maximum_Payload_Size_Supported *\/ */
/*   { 2, 0b1 }, /\* Bus_Master_Enable *\/ */
/*   { 1, 0b1 }, /\* Peripheral_Channel_Ready *\/ */
/*   { 0, 0b1 } /\* Peripheral_Channel_Enable *\/ */
/* }; */

/* Maximum Read Request Size */
#define PERIPHERAL_CHAN_MAX_READ_REQUEST_OFFSET	(12)
#define PERIPHERAL_CHAN_MAX_READ_REQUEST_MASK	(0x7)

/* Maximum Payload Size Selected */
#define PERIPHERAL_CHAN_MAX_PAYLOAD_SIZE_SELECTED_OFFSET	(8)
#define PERIPHERAL_CHAN_MAX_PAYLOAD_SIZE_SELECTED_MASK		(0x7)

/* Maximum Payload Size Supported */
#define PERIPHERAL_CHAN_MAX_PAYLOAD_SIZE_SUPPORTED_OFFSET	(4)
#define PERIPHERAL_CHAN_MAX_PAYLOAD_SIZE_SUPPORTED_MASK		(0x7)

/* Bus Master Enable */
#define PERIPHERAL_CHAN_BUS_MASTER_ENABLE_OFFSET	(2)
#define PERIPHERAL_CHAN_BUS_MASTER_ENABLE_MASK		(0x1)

/* Peripheral Channel Ready */
#define PERIPHERAL_CHAN_READY_OFFSET	(1)
#define PERIPHERAL_CHAN_READY_MASK	(0x1)
  
/* Peripheral Channel Enable */
#define PERIPHERAL_CHAN_ENABLE_OFFSET	(0)
#define PERIPHERAL_CHAN_ENABLE_MASK	(0x1)


/* Interrupt line*/
#define ICSS_ESPI_INTC_BIT_VAL                 (0x00100000U)

/* PRU flags */
#define	ICSS_ESPI_CS_DEASSERT_GOOD_FLAG_BIT	(0x0)
#define	ICSS_ESPI_CS_DEASSERT_BAD_FLAG_BIT	(0x1)

#endif // ICSS_ESPI_H





