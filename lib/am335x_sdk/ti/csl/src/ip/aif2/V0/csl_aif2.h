/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008, 2009
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


/** @defgroup CSL_AIF2_API AIF2
 *
 * @section Introduction
 *
 * @subsection xxx Purpose and Scope
 * The purpose of this document is to identify a set of common CSL APIs for
 * the AIF2 module across various devices. The CSL developer is expected to
 * refer to this document while designing APIs for these modules. Some of the
 * listed APIs may not be applicable to a given AIF module. While other cases
 * this list of APIs may not be sufficient to cover all the features of a
 * particular AIF2 Module. The CSL developer should use his discretion designing
 * new APIs or extending the existing ones to cover these.
 *
 * @subsection aaa Terms and Abbreviations
 *   -# CSL:  Chip Support Library
 *   -# API:  Application Programmer Interface
 *
 *
 */

/** @file csl_aif2.h
 *
 *  @path  $(CSLPATH)\inc
 *
 *  @brief Header file for functional layer of AIF2 CSL
 *
 *  Description
 *  - The different symbolic constants, enumerations, structure definitions
 *    and function prototype declarations
 *
 *  @date    03 Jun, 2009
 *  @author  Albert Bae
 *  @version 0.0.1
 */

/**
 * @defgroup CSL_AIF2_DATASTRUCT AIF2 Data Structures
 * @ingroup CSL_AIF2_API
 */
/**
 * @defgroup CSL_AIF2_ENUM  AIF2 Enumerated Data Types
 * @ingroup CSL_AIF2_API
 */
/**
 * @defgroup CSL_AIF2_FUNCTION  AIF2 Functions
 * @ingroup CSL_AIF2_API
 */

#ifndef CSL_AIF2_H
#define CSL_AIF2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>
#include <ti/csl/cslr_aif2.h>
#include <ti/csl/soc.h>


/**************************************************************************\
* AIF2 global macro declarations
\**************************************************************************/

/** @addtogroup CSL_AIF2_ENUM
*
* @{ */

/**
 * @brief Frame model supported
 *
 * Use this symbol to specify frame mode for AIF2
 *  */
typedef enum 
{  /** Selects the Normal frame mode */
   CSL_AIF2_FRAME_MODE_NORMAL = 0,
   /** Selects the Short frame mode */
   CSL_AIF2_FRAME_MODE_SHORT

} CSL_Aif2FrameMode;

/**
 *
 * @brief Link Protocol supported
 *
 * Use this symbol to specify link formats for AIF2
 *  */
typedef enum 
{  /** Selects the CPRI protocol */
   CSL_AIF2_LINK_PROTOCOL_CPRI = 0,
   /** Selects the OBSAI protocol */
   CSL_AIF2_LINK_PROTOCOL_OBSAI

} CSL_Aif2LinkProtocol;

/**
 *
 * @brief  data width format supported
 *
 * Use this symbol to specify DL/UL and Generic data formats for AIF2
 *  */
typedef enum 
{
   /** Selects 7bit data width */ 
   CSL_AIF2_DATA_WIDTH_7_BIT = 0,
   /** Selects 8bit data width */ 
   CSL_AIF2_DATA_WIDTH_8_BIT,
   /** Selects 15bit data width */ 
   CSL_AIF2_DATA_WIDTH_15_BIT,
   /** Selects 16bit data width */ 
   CSL_AIF2_DATA_WIDTH_16_BIT

} CSL_Aif2DataWidth;


/**
 *
 * @brief aif2 link indices supported
 *
 * Use this symbol to specify the aif2 link index
 *  */
typedef enum 
{
   /** Selects link0 */
   CSL_AIF2_LINK_0  = 0,
   /** Selects link1 */
   CSL_AIF2_LINK_1,
   /** Selects link2 */
   CSL_AIF2_LINK_2,
   /** Selects link3 */
   CSL_AIF2_LINK_3,
   /** Selects link4 */
   CSL_AIF2_LINK_4,
   /** Selects link5 */
   CSL_AIF2_LINK_5
   /** Selects no link */
   /*CSL_AIF2_NO_LINK = 0xF*/ /* this is not used by hw, and sw doesn't handle so remove */

} CSL_Aif2LinkIndex;



/**
 *
 * @brief  link rates supported
 *
 * Use this symbol to specify the  link rate
 *  */
typedef enum 
{
   /** Selects 8X link rate */
   CSL_AIF2_LINK_RATE_8x =0,
   /** Selects 4X link rate */
   CSL_AIF2_LINK_RATE_4x,
   /** Selects 2X link rate */
   CSL_AIF2_LINK_RATE_2x,
   /** Selects 5X link rate only for CPRI*/
   CSL_AIF2_LINK_RATE_5x
   
} CSL_Aif2LinkRate;



/**
 *
 * @brief TM states
 *
 * Use this symbol to specify the state of the TM state machine
 * */
typedef enum 
{
   /** Selects the TM state Off */	 
   CSL_AIF2_TM_ST_OFF =  0x1,
   /** Selects the TM state idle */   
   CSL_AIF2_TM_ST_IDLE =  0x2,
   /** Selects the TM state re-sync */
   CSL_AIF2_TM_ST_RE_SYNC =  0x4,
   /** Selects the TM state frame sync */
   CSL_AIF2_TM_ST_FRAME_SYNC =  0x8

} CSL_Aif2TmSyncState;




/**
 *
 * @brief setup Rm fifo threshold word size for reading received data 
 *
 * 
 * */
typedef enum 
{
   /** FIFO starts reading immediately  */	
   CSL_AIF2_RM_FIFO_THOLD_IMMEDIATELY =  0,
   /** FIFO starts reading after 4 dual words received   */
   CSL_AIF2_RM_FIFO_THOLD_4DUAL,
   /** FIFO starts reading after 8 dual words received   */
   CSL_AIF2_RM_FIFO_THOLD_8DUAL,
   /** FIFO starts reading after 16 dual words received   */
   CSL_AIF2_RM_FIFO_THOLD_16DUAL

} CSL_Aif2RmFifoThold;


/**
 *
 * @brief Suppress error reporting when the receiver state machine is not in state ST3 
 *
 * 
 *  */
typedef enum 
{
   /** Allow all RM error reporting when not in ST3  */	
   CSL_AIF2_RM_ERROR_ALLOW =  0,
 
   /** Suppress all RM error reporting when not in ST3  */
   CSL_AIF2_RM_ERROR_SUPPRESS

} CSL_Aif2RmErrorSuppress;



/**
 *
 * @brief RM sync states
 *
 * Use this symbol to specify the state of the RM state machine
 * */
typedef enum 
{
   /** Selects the RM state 0 */	
   CSL_AIF2_RM_ST_0 =  8,
   /** Selects the RM state 1 */
   CSL_AIF2_RM_ST_1 =  4,
   /** Selects the RM state 2 */
   CSL_AIF2_RM_ST_2 =  2,
   /** Selects the RM state 3 */
   CSL_AIF2_RM_ST_3 =  1,
   /** Selects the RM state 4 */
   CSL_AIF2_RM_ST_4 =  16,
   /** Selects the RM state 5 */
   CSL_AIF2_RM_ST_5 =  32

} CSL_Aif2RmSyncState;


/**
 *
 * @brief Link data type supported
 *
 * Use this symbol to specify the type of data on inbound/outbound link
 * */
typedef enum 
{
   /** Selects the link data type as downlink, generic */
   CSL_AIF2_LINK_DATA_TYPE_NORMAL = 0,
   /** Selects the link data type as uplink */
   CSL_AIF2_LINK_DATA_TYPE_RSA

} CSL_Aif2LinkDataType;


/**
 *
 * @brief GSM data type supported
 *
 * Use this symbol to specify the GSM type of data on inbound link
 * */
typedef enum 
{
   /** Not GSM UL  */
   CSL_AIF2_GSM_DATA_OTHER = 0,
   /** GSM UL, has special OBSAI Time Stamp implications. UL time stamp format msb=1 first four msg  */
   CSL_AIF2_GSM_DATA_UL

} CSL_Aif2GSMDataFormat;


/**
 *
 * @brief Retransmitter Mode used
 *
 * Use this symbol to specify the retransmitter mode
 * */

typedef enum
{
   /** RT  takes RM input only  */
   CSL_AIF2_RT_MODE_RETRANSMIT, 
   /** Aggregate or Merge data from PE and CI */ 
   CSL_AIF2_RT_MODE_AGGREGATE, 
    /** RT takes PE input only*/ 
   CSL_AIF2_RT_MODE_TRANSMIT  

} CSL_Aif2RtConfig;



/**
 *
 * @brief Sd module index
 *
 * Use this symbol to specify the Sd Rx invert polarity
 * */
typedef enum
{
    /** Selects the Receive pair normal polarity*/
    CSL_AIF2_SD_RX_NORMAL_POLARITY = 0,
    /** Selects the Receive pair inverted polarity*/
    CSL_AIF2_SD_RX_INVERTED_POLARITY
    
} CSL_Aif2SdRxInvertPolarity;


/**
 *
 * @brief Sd module rx alignment
 *
 * 
 * */
typedef enum
{
    /** No symbol alignment will be performed whilst this setting is selected, or when switching to this selection from another*/
    CSL_AIF2_SD_RX_ALIGNMENT_DISABLE = 0,
    /** Symbol alignment will be performed whenever a misaligned comma symbol is received. */
    CSL_AIF2_SD_RX_COMMA_ALIGNMENT_ENABLE,
    /** The symbol alignment will be adjusted by one bit position when this mode is selected */
    CSL_AIF2_SD_RX_ALIGNMENT_JOG

}CSL_Aif2SdRxAlign;



/**
 *
 * @brief Sd module rx LOS
 *
 * 
 * */
typedef enum
{
    /** Loss of signal detection disabled*/
    CSL_AIF2_SD_RX_LOS_DISABLE = 0,
    /** Loss of signal detection enabled. */
    CSL_AIF2_SD_RX_LOS_ENABLE = 1

}CSL_Aif2SdRxLos;



/**
 *
 * @brief Sd sys clock select from either B8 or B4
 *
 * */
typedef enum 
{
    /* Select TX Byte clock from B8, B4 default */
    CSL_AIF2_SD_BYTECLOCK_FROM_B8_B4_DEFAULT = 0,
    /* Select TX Byte clock from B8 SERDES */
    CSL_AIF2_SD_BYTECLOCK_FROM_B8,
    /* Select TX Byte clock from B4 SERDES */
    CSL_AIF2_SD_BYTECLOCK_FROM_B4,
    /* Select TX Byte clock from both B4 and B8 */
    CSL_AIF2_SD_BYTECLOCK_FROM_B8_B4

}CSL_Aif2SdClockSelect;



/**
 *
 * @brief CRPI Control Word 4B/5B encoding enable
 *
 * 
 * */
typedef enum 
{
   /** User defined data is not extracted from CPRI Control Words   */
   CSL_AIF2_CW_DELIM_NO_CW = 0,
   /** CW user data is delimitted using 4B/5B encoding where SOP & EOP are defined  */
   CSL_AIF2_CW_DELIM_4B5B,
   /** CW user data is delimitted by a user defined Null Delimiter (defined in other MMR field)   */
   CSL_AIF2_CW_DELIM_NULLDELM,
   /** Packet Boundaries are inferred to be on hyper-frame boundaries  */
   CSL_AIF2_CW_DELIM_HYP_FRM

} CSL_Aif2CpriCwPktDelim;



/**
 *
 * @brief dicates the payload is to be used as AxC (normal) or Packet traffic
 *
 * 
 *  */
typedef enum 
{
   /** Use  AxC data  */
   CSL_AIF2_PD_DATA_AXC = 0,
   /** Use  Packet data  */
   CSL_AIF2_PD_DATA_PKT

} CSL_Aif2PdDataMode;

/**
 *
 * @brief select mode between CPPI and DIO
 *
 * 
 * */
typedef enum 
{
   /** Use CPPI mode  */
   CSL_AIF2_CPPI = 0,
   /** Use DIO for AxC data  */
   CSL_AIF2_DIO

} CSL_Aif2CppiDio;


/**
 *
 * @brief Report every missed WDog fail, or report only fails of missing EOP
 *
 * 
 * */
typedef enum 
{
   /** WD Report all  */
   CSL_AIF2_PD_WD_REPORT_ALL = 0,
   /** WD report EOP only  */
   CSL_AIF2_PD_WD_REPORT_EOP

} CSL_Aif2PdWatchDogReport;


/**
 *
 * @brief PD or PE Obsai time stamp mask supported
 *
 * */
typedef enum 
{
   /** All TS bits are genrated, not inserted */
   CSL_AIF2_TSTAMP_MASK_FULL_GEN = 0,
   /** 4 lsb bits of TS are inserted, 2 msb are generated */
   CSL_AIF2_TSTAMP_MASK_4INS_2GEN,
   /** All TS(5:0) bits are inserted */
   CSL_AIF2_TSTAMP_MASK_FULL_INS

} CSL_Aif2ObsaiTsMask;


/**
 *
 * @brief PD or PE time stamp format supported
 *
 * */
typedef enum 
{
   /** Selects the link time stamp format as no time stamp check */
   CSL_AIF2_TSTAMP_FORMAT_NO_TS = 0,
   /** Selects the link time stamp format as normal time stamp */
   CSL_AIF2_TSTAMP_FORMAT_NORM_TS,
   /** Selects the link time stamp format as GSM OBSAI time stamp (UL time stamp for PE)  */
   CSL_AIF2_TSTAMP_FORMAT_GSM,
   /** Selects the link time stamp format for generic packet (SOP = 10, MOP = 00, EOP = 11) */
   CSL_AIF2_TSTAMP_FORMAT_GEN_PKT,
   /** Selects the link time stamp format for ethernet */
   CSL_AIF2_TSTAMP_FORMAT_ETHERNET,
   /** Selects the link time stamp format, which value is checked by PD or PE route  */
   CSL_AIF2_TSTAMP_FORMAT_ROUTE_CHECK,
    /** Selects the link time stamp format as GSM DL OBSAI time stamp (only used for PE)  */
   CSL_AIF2_TSTAMP_FORMAT_GSM_DL

} CSL_Aif2TstampFormat;

/**
 *
 * @brief controls how many OBSAI time stamp bits to use in the reception routing.
 *
 * Use this symbol to specify the masking value for time stamp
 * */
typedef enum 
{
   /** Do not use the TS field for routing  */
   CSL_AIF2_ROUTE_MASK_NONE = 0,
   /** 4 lsb bits: Use TS(3:0)  */
   CSL_AIF2_ROUTE_MASK_4LSB,
   /** all Use TS(5:0)   */
   CSL_AIF2_ROUTE_MASK_ALL,
   /** Reserved */
   CSL_AIF2_ROUTE_MASK_RESERVED

} CSL_Aif2RouteMask;

/**
 *
 * @brief select CPRI AxC data pack type
 *
 *  */
typedef enum 
{
   /** AxC data is 7bit I & 7bit Q (byte packing needed)  */
   CSL_AIF2_CPRI_7BIT_SAMPLE = 0,
   /** AxC data is 8bit I & 8bit Q (byte aligned)  */
   CSL_AIF2_CPRI_8BIT_SAMPLE,
   /** AxC data is 15bit I & 15bit Q (byte packing needed) */
   CSL_AIF2_CPRI_15BIT_SAMPLE,
   /** AxC data is 16bit I & 16bit Q (byte aligned) */
   CSL_AIF2_CPRI_16BIT_SAMPLE

} CSL_Aif2CpriAxCPack;

/**
 *
 * @brief Controls RT to perform appropriate insterion/aggregation into PHY 
 *
 * Use this symbol to specify RT control for PE
 * */
typedef enum 
{
   /** Retransmit mode */
   CSL_AIF2_PE_RT_RETRANS = 0,
   /** PE Insert mode */
   CSL_AIF2_PE_RT_INSERT,
   /** aggregate 16 bit mode */
   CSL_AIF2_PE_RT_ADD16,
   /** aggregate 8 bit mode  */
   CSL_AIF2_PE_RT_ADD8

} CSL_Aif2PeRtContol;

/**
 *
 * @brief CRC: length of CRC 
 *
 * Use this symbol to specify crc length for PE,PD
 * */
typedef enum 
{
   /** CRC 32 bits */
   CSL_AIF2_CRC_32BIT = 0,
   /** CRC 16 bits  */
   CSL_AIF2_CRC_16BIT,
   /** CRC 8 bits   */
   CSL_AIF2_CRC_8BIT

} CSL_Aif2CrcLen;



/**
 *
 * @brief DB FIFO bufffer depth
 *
 * Use this symbol to specify the buffer depth for DB FIFO
 * */
typedef enum
{
   /** Selects  FIFO buffer depth to 8 quad words */
   CSL_AIF2_DB_FIFO_DEPTH_QW8 = 0,
   /** Selects  FIFO buffer depth to 16 quad words */
   CSL_AIF2_DB_FIFO_DEPTH_QW16,
   /** Selects  FIFO buffer depth to 32 quad words */
   CSL_AIF2_DB_FIFO_DEPTH_QW32,
   /** Selects  FIFO buffer depth to 64 quad words */
   CSL_AIF2_DB_FIFO_DEPTH_QW64,
   /** Selects  FIFO buffer depth to 128 quad words */
   CSL_AIF2_DB_FIFO_DEPTH_QW128,
   /** Selects  FIFO buffer depth to 256 quad words */
   CSL_AIF2_DB_FIFO_DEPTH_QW256

} CSL_Aif2DbFifoDepth;

/**
 *
 * @brief DB Big endian swapping control
 *
 * 
 * */
typedef enum 
{
   /** Selects DB no swap */
   CSL_AIF2_DB_NO_SWAP = 0,
   /** Selects DB byte swap */
   CSL_AIF2_DB_BYTE_SWAP,
   /** Selects DB half word swap */
   CSL_AIF2_DB_HALF_WORD_SWAP,
   /** Selects DB word swap */
   CSL_AIF2_DB_WORD_SWAP
   
} CSL_Aif2DbDataSwap;


/**
 *
 * @brief Internally changing IQ data order control 
 *
 * 
 * */
typedef enum 
{
   /** Selects DB IQ data no swap */
   CSL_AIF2_DB_IQ_NO_SWAP = 0,
   /** Selects DB IQ data no swap1 */
   CSL_AIF2_DB_IQ_NO_SWAP1,
   /** Selects DB IQ data byte swap */
   CSL_AIF2_DB_IQ_BYTE_SWAP,
   /** Selects DB IQ data 16 bit swap */
   CSL_AIF2_DB_IQ_16BIT_SWAP
   
} CSL_Aif2DbIqOrder;


/**
 *
 * @brief DB DIO length type 
 *
 * Use this symbol to specify DIO length type for DB
 * */
typedef enum 
{
   /** Selects DB dio buffer length 128 bytes */
   CSL_AIF2_DB_DIO_LEN_128 = 0,
   /** Selects DB dio buffer length 256 bytes */
   CSL_AIF2_DB_DIO_LEN_256

} CSL_Aif2DioLen;


/**
 *
 * @brief DB Packet mode control type 
 *
 * Use this symbol to specify PM control for DB
 * */
typedef enum 
{
   /** Put PM tokens from PE in separate PM Token FIFO */
   CSL_AIF2_DB_PM_TOKEN_FIFO = 0,
   /** Put PM tokens from PE in Axc Token FIFO to improve CPRI packet performance */
   CSL_AIF2_DB_AXC_TOKEN_FIFO

} CSL_Aif2DbPmControl;


/**
 *
 * @brief This field tells how the Ingress Scheduler handles packets marked as failed by the PD. 
 *
 * */
typedef enum 
{
   /** Selects AD error data drop */
   CSL_AIF2_AD_DROP = 0,
   /** Selects AD error data mark */
   CSL_AIF2_AD_MARK

} CSL_Aif2AdFailMode;

/**
 *
 * @brief AD Ingress Scheduler aribitration priority
 *
 * */
typedef enum 
{
   /** Set dio as high priority  */
   CSL_AIF2_AD_DIO_PRI = 0,
   /** Set cppi packet  as high priority */
   CSL_AIF2_AD_PKT_PRI

} CSL_Aif2AdIngrPriority;


/**
 *
 * @brief AD Egress Scheduler aribitration priority
 *
 * */
typedef enum 
{
   /** Set AxC data as high priority  */
   CSL_AIF2_AD_AXC_PRI = 0,
   /** Set non AxC data as high priority */
   CSL_AIF2_AD_NON_AXC_PRI

} CSL_Aif2AdEgrPriority;


/**
 *
 * @brief AD DIO Quad word number for each AxC data
 *
 * */
typedef enum 
{
   /** Set AD dio quad word number to 1 quad */
   CSL_AIF2_AD_1QUAD = 0,
   /** Set AD dio quad word number to 2 quad */
   CSL_AIF2_AD_2QUAD,
   /** Set AD dio quad word number to 4 quad */
   CSL_AIF2_AD_4QUAD

} CSL_Aif2AdNumQWord;

/**
 *
 * @brief AD DIO BCN TABLE SEL  type 
 *
 * Use this symbol to specify DIO bcn table selection  type for AD
 * */
typedef enum 
{
   CSL_AIF2_AD_DIO_BCN_TABLE_0 = 0,
   CSL_AIF2_AD_DIO_BCN_TABLE_1

} CSL_Aif2AdBcnTable;

/**
 *
 * @brief aif2 dio engine index supported
 *
 * Use this symbol to specify the aif2 dio engine index
 *  */
typedef enum 
{
   /** Selects dio engine 0 */
   CSL_AIF2_DIO_ENGINE_0  = 0,
   /** Selects dio engine 1 */
   CSL_AIF2_DIO_ENGINE_1,
   /** Selects dio engine 2 */
   CSL_AIF2_DIO_ENGINE_2

} CSL_Aif2DioEngineIndex;


/**
 *
 * @brief AT Rad event strobe selection type
 *
 * Use this symbol to specify rad event strobe type for AT
 * */
typedef enum 
{
   /** Selects rad timer symbol strobe */
   CSL_AIF2_RADT_SYMBOL = 0,
   /** Selects rad timer frame strobe */
   CSL_AIF2_RADT_FRAME, 
   /** Selects ul rad timer symbol strobe */
   CSL_AIF2_ULRADT_SYMBOL,
   /** Selects ul rad timer frame strobe */
   CSL_AIF2_ULRADT_FRAME,
   /** Selects dl rad timer symbol strobe */
   CSL_AIF2_DLRADT_SYMBOL,
   /** Selects dl rad timer frame strobe */
   CSL_AIF2_DLRADT_FRAME,
   /** Selects phy timer frame strobe */
   CSL_AIF2_PHYT_FRAME

} CSL_Aif2AtEvtStrobe;



/**
 *
 * @brief AT Event selection type
 *
 * Use this symbol to specify event type for AT dynamic event setup
 * */
typedef enum 
{
    /** Selects external event 0 */
   CSL_AIF2_EVENT_0 = 0,
   /** Selects external event 1 */
   CSL_AIF2_EVENT_1,
   /** Selects external event 2 */
   CSL_AIF2_EVENT_2,
   /** Selects external event 3 */
   CSL_AIF2_EVENT_3,
   /** Selects external event 4 */
   CSL_AIF2_EVENT_4,
   /** Selects external event 5 */
   CSL_AIF2_EVENT_5,
   /** Selects external event 6 */
   CSL_AIF2_EVENT_6,
   /** Selects external event 7 */
   CSL_AIF2_EVENT_7,
   /** Selects special event 8 for TAC */
   CSL_AIF2_EVENT_8,
   /** Selects special event 9 for RAC A*/
   CSL_AIF2_EVENT_9,
   /** Selects special event 10 for RAC B*/
   CSL_AIF2_EVENT_10,
   /** Selects special event 11 for RAC C*/
   CSL_AIF2_EVENT_11,
   /** Selects special event 12 for RAC D*/
   CSL_AIF2_EVENT_12,
   /** Selects external event 13 */
   CSL_AIF2_EVENT_13,
   /** Selects external event 14 */
   CSL_AIF2_EVENT_14,
   /** Selects external event 15 */
   CSL_AIF2_EVENT_15,
   /** Selects external event 16 */
   CSL_AIF2_EVENT_16,
   /** Selects external event 17 */
   CSL_AIF2_EVENT_17,
   /** Selects external event 18 */
   CSL_AIF2_EVENT_18,
   /** Selects external event 19 */
   CSL_AIF2_EVENT_19,
   /** Selects external  event 20 */
   CSL_AIF2_EVENT_20,
   /** Selects external event 21 */
   CSL_AIF2_EVENT_21,
   /** Selects external event 22 */
   CSL_AIF2_EVENT_22,
   /** Selects external event 23 */
   CSL_AIF2_EVENT_23,
   /** Selects ingress dio event 0 */
   CSL_AIF2_IN_DIO_EVENT_0,
   /** Selects ingress dio event 1 */
   CSL_AIF2_IN_DIO_EVENT_1,
   /** Selects ingress dio event 2 */
   CSL_AIF2_IN_DIO_EVENT_2,
   /** Selects egress dio event 0 */
   CSL_AIF2_E_DIO_EVENT_0,
    /** Selects egress dio event 1 */
   CSL_AIF2_E_DIO_EVENT_1,
    /** Selects egress dio event 2 */
   CSL_AIF2_E_DIO_EVENT_2
} CSL_Aif2AtEventIndex;


/**
 *
 * @brief Timer sync sources in AT
 *
 * Use this symbol to specify timer sync source for AT
 * */
typedef enum 
{
    /** Selects RP1 sync */
   CSL_AIF2_RP1_SYNC = 0,
   /** Selects chip input sync */
   CSL_AIF2_CHIP_INPUT_SYNC,
   /** Selects sw debug sync */
   CSL_AIF2_SW_SYNC,
   /** Selects rm at  sync */
   CSL_AIF2_RM_AT_SYNC,
   /** Selects phy timer compare sync */
   CSL_AIF2_PHYT_CMP_SYNC

} CSL_Aif2AtSyncSource;


/**
 *
 * @brief Sync mode for AT
 *
 * Use this symbol to specify sync mode for AT
 * */
typedef enum 
{
   /** Selects non rp1 mode */
   CSL_AIF2_NON_RP1_MODE = 0,
   /** Selects rp1 mode */
   CSL_AIF2_RP1_MODE

} CSL_Aif2AtSyncMode;


/**
 *
 * @brief Re-Sync mode for AT
 *
 * Use this symbol to specify re-sync mode for AT
 * 
 * */
typedef enum 
{
   /** Selects at no auto resync mode */
   CSL_AIF2_NO_AUTO_RESYNC_MODE = 0,
   /** Selects at auto resync mode */
   CSL_AIF2_AUTO_RESYNC_MODE

} CSL_Aif2AtReSyncMode;

/**
 *
 * @brief select CRC mode on / off
 * 
 *
 *  */
typedef enum 
{
   /** Don't use at crc  */
   CSL_AIF2_AT_CRC_DONT_USE = 0,
   /** Use at crc  */
   CSL_AIF2_AT_CRC_USE

} CSL_Aif2AtCrcUse;

/**
 *
 * @brief select CRC flip mode between normal and reverse
 * 
 *
 *  */
typedef enum 
{
   /** use at crc normal mode  */
   CSL_AIF2_AT_CRC_NORMAL = 0,
   /** use at crc reverse mode  */
   CSL_AIF2_AT_CRC_REVERSE

} CSL_Aif2AtCrcFlip;

/**
 *
 * @brief select CRC init value
 * 
 *
 * */
typedef enum 
{
   /** use at crc init0  */
   CSL_AIF2_AT_CRC_INIT0 = 0,
   /** use at crc init1  */
   CSL_AIF2_AT_CRC_INIT1

} CSL_Aif2AtCrcInitOnes;

/**
 *
 * @brief select CRC invert mode
 * 
 *
 * */
typedef enum 
{
   /** use at crc non invert mode  */
   CSL_AIF2_AT_CRC_NOINVERT = 0,
   /** use at crc invert mode  */
   CSL_AIF2_AT_CRC_INVERT

} CSL_Aif2AtCrcInvert;


/**
 *
 * @brief CRC usage in RP1 sync mode for AT
 *
 * Use this symbol to specify CRC usage mode when AT is used in RP1 sync mode 
 * */
typedef enum 
{
   /** use at sync burst on crc fail  */
   CSL_AIF2_USE_SYNC_BURST_ON_CRC_FAIL = 0,
   /** discard at sync burst on crc fail  */
   CSL_AIF2_DISCARD_SYNC_BURST_ON_CRC_FAIL

} CSL_Aif2AtRp1CRCUsage;


/**
 *
 * @brief Type field definitions for RP1 sync burst
 *
 * Use this symbol to specify the type field in the RP1 sync burst 
 * */
typedef enum
{
   /** Selects rp1 type not used  */
   CSL_AIF2_RP1_TYPE_NOT_USED               = 0x00,
   /** Selects rp1 type rp3 frame number  */
   CSL_AIF2_RP1_TYPE_RP3_FRAME_NUM          = 0x01, 
   /** Selects rp1 type wcdma fdd frame number  */
   CSL_AIF2_RP1_TYPE_WCDMA_FDD_FRAME_NUM    = 0x02, 
   /** Selects rp1 type gsm edge 1 frame number  */
   CSL_AIF2_RP1_TYPE_GSM_EDGE_1_FRAME_NUM   = 0x03,
   /** Selects rp1 type gsm edge 2 frame number  */
   CSL_AIF2_RP1_TYPE_GSM_EDGE_2_FRAME_NUM   = 0x04,
   /** Selects rp1 type gsm edge3 frame number  */
   CSL_AIF2_RP1_TYPE_GSM_EDGE_3_FRAME_NUM   = 0x05,
   /** Selects rp1 type wcdma tdd frame number  */
   CSL_AIF2_RP1_TYPE_WCDMA_TDD_FRAME_NUM    = 0x06,
   /** Selects rp1 type cdma 2000 frame number  */
   CSL_AIF2_RP1_TYPE_CDMA_2000_FRAME_NUM    = 0x07,
   /** Selects rp1 type tdd  */
   CSL_AIF2_RP1_TYPE_TOD                    = 0x08,
   /** Selects rp1 type reserved first  */
   CSL_AIF2_RP1_TYPE_RESERVED_FIRST         = 0x09,
   /** Selects rp1 type reserved last */
   CSL_AIF2_RP1_TYPE_RESERVED_LAST          = 0x7F,
   /** Selects rp1 type spare first  */
   CSL_AIF2_RP1_TYPE_SPARE_FIRST            = 0x80,
   /** Selects rp1 type spare last  */
   CSL_AIF2_RP1_TYPE_SPARE_LAST             = 0xFF

} CSL_Aif2AtRp1TypeField;


/**
 *
 * @brief select EE module working function
 *
 * Use this symbol to specify one of the function of EE  
 * */
typedef enum
{
   /** Selects ee interrupt raw status  */
   CSL_AIF2_EE_INT_RAW_STATUS = 0, 
   /** Selects ee interrupt set  */
   CSL_AIF2_EE_INT_SET,             
   /** Selects ee interrupt clear  */
   CSL_AIF2_EE_INT_CLR,         
   /** Selects ee interrupt enabled status ev0  */
   CSL_AIF2_EE_INT_EN_STATUS_EV0,
   /** Selects ee interrupt enabled status ev1 */
   CSL_AIF2_EE_INT_EN_STATUS_EV1, 
   /** Selects ee interrupt enable ev0  */
   CSL_AIF2_EE_INT_EN_EV0,      
   /** Selects ee interrupt   enable ev1*/
   CSL_AIF2_EE_INT_EN_EV1,    
   /** Selects ee interrupt enable set ev0  */
   CSL_AIF2_EE_INT_EN_SET_EV0,     
   /** Selects ee interrupt enable set ev1  */
   CSL_AIF2_EE_INT_EN_SET_EV1,
   /** Selects ee interrupt enable clear ev0  */
   CSL_AIF2_EE_INT_EN_CLR_EV0,   
   /** Selects ee interrupt enable clear ev1  */
   CSL_AIF2_EE_INT_EN_CLR_EV1
    
} CSL_Aif2EeArgIndex;


/**
 * This is the set of control commands that are passed to
 * @a CSL_aif2HwControl(), with an optional argument type-casted to @a void*
 *
 * The arguments, if any, to be passed with each command are specified
 * next to that command.
 */
typedef enum 
{
   /** Starts a Rx link. use hAif2->arg_link to select link (argument type: Bool * ) */
   CSL_AIF2_CMD_ENABLE_DISABLE_RX_LINK = 0,
    
   /** Starts a Tx link. use hAif2->arg_link to select link (argument type: Bool * ) */
   CSL_AIF2_CMD_ENABLE_DISABLE_TX_LINK,

   /** Enable SD B8 PLL (argument type: Bool * )*/   
   CSL_AIF2_CMD_ENABLE_DISABLE_SD_B8_PLL,

   /** Enable SD B4 PLL (argument type: Bool * )*/
   CSL_AIF2_CMD_ENABLE_DISABLE_SD_B4_PLL,

   /** Control Aif2 Emulation (argument type:  CSL_Aif2VcEmu*)  */   
   CSL_AIF2_CMD_VC_EMU_CONTROL,

   /** Force RM Sync State (argument type:  CSL_Aif2RmSyncState *, use hAif2->arg_link to select link)  */   
   CSL_AIF2_CMD_RM_FORCE_STATE,

    /** TM L1 Inband Control Signal Set (argument type:  Uint8 *, use hAif2->arg_link to select link)  */   
    CSL_AIF2_CMD_TM_L1_INBAND_SET,

   /** Force TM Flush FIFO (argument type:  Bool *)  */   
   CSL_AIF2_CMD_TM_FLUSH_FIFO,

    /** Force TM Idle state (argument type:  Bool *)  */   
   CSL_AIF2_CMD_TM_IDLE,

    /** Force TM Resync state (argument type:  Bool *)  */   
   CSL_AIF2_CMD_TM_RESYNC,

   /** Dynamic configuration of PD CPRI id lut register (argument type:  CSL_Aif2PdCpriIdLut  *, use hAif2->arg_link to select link)  */   
   CSL_AIF2_CMD_PD_CPRI_ID_LUT_SETUP,

   /** Dynamic configuration of PD CPRI Control Word lut register (argument type:  CSL_Aif2PdCpriCwLut  *, use hAif2->arg_link to select link)  */   
   CSL_AIF2_CMD_PD_CPRI_CW_LUT_SETUP,

   /** Dynamic configuration of PD DBMR  (argument type:  CSL_Aif2DualbitMap  *, use hAif2->arg_link to select link)  */   
   CSL_AIF2_CMD_PD_LINK_DBMR_SETUP,

   /** Dynamic configuration of PD channel config registers (argument type:  CSL_Aif2PdChannelConfig  *)  */   
   CSL_AIF2_CMD_PD_CH_CONFIG_SETUP,

   /** Dynamic configuration of PE CPRI Control Word lut register (argument type:  CSL_Aif2CpriCwLut  *, use hAif2->arg_link to select link)  */   
   CSL_AIF2_CMD_PE_CPRI_CW_LUT_SETUP,

   /** Dynamic configuration of PE OBSAI header register (argument type:  CSL_Aif2PeObsaiHeader  *, use hAif2->arg_link to select link)  */   
   CSL_AIF2_CMD_PE_OBSAI_HEADER_SETUP,

   /** Dynamic configuration of PE DBMR  (argument type:  CSL_Aif2DualbitMap  *)  */   
   CSL_AIF2_CMD_PE_LINK_DBMR_SETUP,

   /** Dynamic configuration of PE Modulo rule  (argument type:  CSL_Aif2DualbitMap  *)  */   
   CSL_AIF2_CMD_PE_MODULO_RULE_SETUP,

   /** Dynamic configuration of PE channel config registers (argument type:  CSL_Aif2PeChannelConfig  *)  */   
   CSL_AIF2_CMD_PE_CH_CONFIG_SETUP,

   /** Dynamic configuration of PE channel rule LUT config registers (argument type:  CSL_Aif2PeChRuleLut  *)  */   
   CSL_AIF2_CMD_PE_CH_RULE_LUT_SETUP,
   
   /** Enables Trace data and framing data capture (use hAif2->arg_link to select link, argument type: Bool *) */ 
   CSL_AIF2_CMD_ENABLE_DISABLE_LINK_DATA_CAPTURE,  /* use arg_link index to determine which link are enabled/disabled */

   /** Data Trace Synchronization with Frame boundary Enable (argument type: Bool *) */
   CSL_AIF2_CMD_ENABLE_DISABLE_DATA_TRACE_SYNC,

    /** Enables Ingress DB Debug mode (argument type: Bool *) */
   CSL_AIF2_CMD_DB_IN_ENABLE_DISABLE_DEBUG_MODE,
   
   /** Debug data written to bits 128:0 of Ingress DB RAM (argument type: Uint32 *) */
   CSL_AIF2_CMD_DB_IN_DEBUG_DATA_SETUP, 

   /** Ingress DB debug side band data setup (argument type: CSL_Aif2DbSideDatal *)  */
   CSL_AIF2_CMD_DB_IN_DEBUG_SIDE_DATA_SETUP, 

   /** Writes the data in the following registers into the Ingress DB and sideband RAMS
   DB_IDB_DEBUG_D0, DB_IDB_DEBUG_D1, DB_IDB_DEBUG_D2, DB_IDB_DEBUG_D3, DB_IDB_DEBUG_SBDN (argument type: Bool *)  */
   CSL_AIF2_CMD_DB_IN_DEBUG_WRITE,

   /** Set Read and Write Address used to access write or read Offset RAM for DB Debug (argument type: Uint8 * arg[0] : write offset addr  arg[1] : read offset addr)  */
   CSL_AIF2_CMD_DB_IN_DEBUG_OFFSET_ADDR,

   /** Enable or Disable Ingress DB channel to add or remove channel dynamically (argument type: Uint32 *)  */
   CSL_AIF2_CMD_DB_IN_ENABLE_DISABLE_CHANNEL,

   /** Setup Ingress DB channel to add or remove channel dynamically (argument type: CSL_Aif2DbChannel *)  */
   CSL_AIF2_CMD_DB_IN_CHANNEL_SETUP,

    /** Enables Egress DB Debug mode (argument type: Bool *) */
   CSL_AIF2_CMD_DB_E_ENABLE_DISABLE_DEBUG_MODE,

   /** Setup Side band data control info like dio and fifo write enable and channel id and dio base address.(argument type: CSL_Aif2DbSideData *) */
   CSL_AIF2_CMD_DB_E_DEBUG_READ_CONTROL,
   
   /** the value loaded into DB_EDB_DEBUG_RD_CNTL.CH_ID being issued to the AxC Token FIFO.(argument type: Bool *) */
   CSL_AIF2_CMD_DB_E_DEBUG_WRITE_TOKEN,

   /** Read the data in the following registers from the Egress DB and sideband RAMS
   DB_EDB_DEBUG_D0, DB_EDB_DEBUG_D1, DB_EDB_DEBUG_D2, DB_EDB_DEBUG_D3, DB_EDB_DEBUG_SBDN (argument type: Bool *)  */
   CSL_AIF2_CMD_DB_E_DEBUG_READ,

   /** Set Read and Write Address used to access write or read Offset RAM for DB Debug (argument type: Uint8 * arg[0] : write offset addr  arg[1] : read offset addr)  */
   CSL_AIF2_CMD_DB_E_DEBUG_OFFSET_ADDR,

   /** Enable or Disable Egress DB channel to add or remove channel dynamically (argument type: Uint32 *)  */
   CSL_AIF2_CMD_DB_E_ENABLE_DISABLE_CHANNEL,

   /** Setup Egress DB channel to add or remove channel dynamically (argument type: CSL_Aif2DbChannel *)  */
   CSL_AIF2_CMD_DB_E_CHANNEL_SETUP,

   /** Enable or Disable IN Global AD module dynamically (argument type: Bool *)  */
   CSL_AIF2_CMD_AD_IN_ENABLE_DISABLE_GLOBAL,

   /** Enable or Disable E Global AD module dynamically (argument type: Bool *)  */
   CSL_AIF2_CMD_AD_E_ENABLE_DISABLE_GLOBAL,
		
   /** Enable or Disable Global Ingress DIO mode dynamically (argument type: Bool *)  */
   CSL_AIF2_CMD_AD_IN_ENABLE_DISABLE_DIO_GLOBAL,
       
   /** Enable or Disable Global Egress DIO mode dynamically (argument type: Bool *)  */
   CSL_AIF2_CMD_AD_E_ENABLE_DISABLE_DIO_GLOBAL,
   
   /** Change Ingress DIO table selection dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
   CSL_AIF2_CMD_AD_IN_DIO_TABLE_SELECT,

   /** Change Ingress DIO num of AxC dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
   CSL_AIF2_CMD_AD_IN_DIO_NUM_AXC_CHANGE,

   /** Change Ingress DIO BCN table dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
   CSL_AIF2_CMD_AD_IN_DIO_BCN_TABLE_CHANGE,

   /** Change Egress DIO table selection dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
   CSL_AIF2_CMD_AD_E_DIO_TABLE_SELECT,

   /** Change Egress DIO num of AxC dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
   CSL_AIF2_CMD_AD_E_DIO_NUM_AXC_CHANGE,

   /** Change Egress DIO BCN table dynamically (use hAif2->arg_dioEngine to select dio engine.  argument type: Uint8 *)  */
   CSL_AIF2_CMD_AD_E_DIO_BCN_TABLE_CHANGE,

   /** Set Enable or disable Data trace DMA for data and framing data (argument type: Bool *)  */
   CSL_AIF2_CMD_AD_TRACE_DATA_DMA_CHANNEL_ON_OFF,

   /** Set Trace data base address  (argument type: Uint32 *)  */
   CSL_AIF2_CMD_AD_TRACE_DATA_BASE_ADDR,

   /** Set trace framing data base address  (argument type: Uint32 *)  */
   CSL_AIF2_CMD_AD_TRACE_FRAMING_DATA_BASE_ADDR,

   /** Sets the number of burst transfers before the destination address wraps back to the base address (argument type: Uint8 *)  */
   CSL_AIF2_CMD_AD_TRACE_CPPI_DMA_BURST_WRAP,

   /** Sets AT External Rad timer event dynamically (argument type: CSL_Aif2AtEvent *)  */
   CSL_AIF2_CMD_AT_EVENT_SETUP,

   /** Sets AT Delta offset  (use hAif2->arg_link to select link   argument type: CSL_Aif2AtEvent *)  */
   CSL_AIF2_CMD_AT_DELTA_SETUP,

   /** Sets AT Halt timer  (argument type:  Bool  *)  */
   CSL_AIF2_CMD_AT_HALT_TIMER,

   /** Sets AT diable all events for debug purpose (argument type:  Bool  *)  */
   CSL_AIF2_CMD_AT_DISABLE_ALL_EVENTS,
   
   /** Sets AT Arm timer  (argument type:  Bool  *)  */
   CSL_AIF2_CMD_AT_ARM_TIMER,

   /** Sets AT SW debug sync  (argument type:  Bool  *)  */
   CSL_AIF2_CMD_AT_DEBUG_SYNC,

   /** Sets AT radt wcdma clock divider terminal count  (argument type:  Uint8  *)  */
   CSL_AIF2_CMD_AT_RAD_WCDMA_DIV,

   /** Sets AT Rad terminal count  (argument type:  CSL_Aif2AtTcObj  *)  */
   CSL_AIF2_CMD_AT_RAD_TC_SETUP,

   /** Sets AT GSM Tcount  (argument type:  CSL_Aif2AtGsmTCount  *)  */
   CSL_AIF2_CMD_AT_GSM_TCOUNT_SETUP,

   /** Enable Eight Rad and Six DIO Events  (argument type:  CSL_Aif2AtEventIndex  *)  */
   CSL_AIF2_CMD_AT_ENABLE_EVENT,

   /** Disable Eight Rad and Six DIO Events  (argument type:  CSL_Aif2AtEventIndex  *)  */
   CSL_AIF2_CMD_AT_DISABLE_EVENT,

   /** Force set  Eight Rad and Six DIO Events  (argument type:  CSL_Aif2AtEventIndex  *)  */
   CSL_AIF2_CMD_AT_FORCE_EVENT,

   /** EE End of interrupt vector value setup  (argument type:  Uint8  *)  */
   CSL_AIF2_CMD_EE_EOI_SETUP,

   /** EE VB error interrupt set or clear (use hAif2->ee_arg to select between set and clear   argument type:  CSL_Aif2EeAif2IntSetup  *)  */
   CSL_AIF2_CMD_EE_AIF2_ERROR_INT,

   /** EE DB interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeDbIntSetup  *)  */
   CSL_AIF2_CMD_EE_DB_INT,
   
   /** EE AD interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeAdIntSetup  *)  */
   CSL_AIF2_CMD_EE_AD_INT,

   /** EE CD(CDMA module) interrupt set, clear, enable set or clear for EV0 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeCdIntSetup  *)  */
   CSL_AIF2_CMD_EE_CD_INT,

   /** EE SD interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeSdIntSetup  *)  */
   CSL_AIF2_CMD_EE_SD_INT,

   /** EE VC interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeVcIntSetup  *)  */
   CSL_AIF2_CMD_EE_VC_INT,

   /** EE Aif2 run control register setup (argument type:  CSL_Aif2EeAif2RunSetup  *)  */
   CSL_AIF2_CMD_EE_AIF2_RUN,
		
   /** EE Link A interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeLinkAIntSetup  *)  */
   CSL_AIF2_CMD_EE_LINKA_INT,

   /** EE Link B  interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeLinkBIntSetup  *)  */
   CSL_AIF2_CMD_EE_LINKB_INT,

   /** EE AT interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EeAtInt  *)  */
   CSL_AIF2_CMD_EE_AT_INT,

   /** EE PD common interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EePdInt  *)  */
   CSL_AIF2_CMD_EE_PD_INT,

   /** EE PE common interrupt set, clear, enable set or clear for EV0 and EV1 (use hAif2->ee_arg to select function   argument type:  CSL_Aif2EePeInt  *)  */
   CSL_AIF2_CMD_EE_PE_INT
   
} CSL_Aif2HwControlCmd;

/**
 * This is the set of query commands to get the status of various
 * operations in AIF2
 *
 * The arguments, if any, to be passed with each command are specified
 * next to that command. */                   
typedef enum 
{

 /** Get  the version of the module accessed  @param  (CSL_Aif2PidStatus *) **/
   CSL_AIF2_QUERY_VERSION =  0,

 /** returns VC Emu status */
   CSL_AIF2_QUERY_VC_STAT,
   
 /** SERDES Rx Status     @param  (CSL_Aif2SdRxStatus *) */
   CSL_AIF2_QUERY_SD_RX_LINK_STATUS,

 /** Return the status of SERDES B8 PLL lock.   @param (Uint8 *)*/
   CSL_AIF2_QUERY_SD_B8_PLL_LOCK,

 /** Return the status of SERDES B4 PLL lock.   @param (Uint8 *)*/
   CSL_AIF2_QUERY_SD_B4_PLL_LOCK,

  /** RM link Status 0. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus0 *)*/
   CSL_AIF2_QUERY_RM_LINK_STATUS_0,

  /** RM link Status 1. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus1 *)*/
   CSL_AIF2_QUERY_RM_LINK_STATUS_1,

  /** RM link Status 2. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus2 *)*/
   CSL_AIF2_QUERY_RM_LINK_STATUS_2,

  /** RM link Status 3. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus3 *)*/
   CSL_AIF2_QUERY_RM_LINK_STATUS_3,

  /** RM link Status 4. use hAif2->arg_link to choose link.  @param (CSL_Aif2RmStatus4 *)*/
   CSL_AIF2_QUERY_RM_LINK_STATUS_4,
	
  /** Return TM link CPRI HFN Status. use hAif2->arg_link to choose link.  @param (Uint8 *)*/
   CSL_AIF2_QUERY_TM_LINK_CPRI_HFN,

  /** TM link Status. use hAif2->arg_link to choose link.  @param (CSL_Aif2TmStatus *)*/
   CSL_AIF2_QUERY_TM_LINK_STATUS,

  /** RT Internal FIFO depth Status. use hAif2->arg_link to choose link.  @param (Uint8 *)*/
   CSL_AIF2_QUERY_RT_FIFO_DEPTH_STATUS,
    
  /** RT Header Error Status. use hAif2->arg_link to choose link.  @param (CSL_Aif2RtHeaderStatus *)*/
   CSL_AIF2_QUERY_RT_HEADER_ERROR_STATUS,

  /** Get  the status of the Retransmitter @param  (CSL_Aif2RtStatus *) **/
   CSL_AIF2_QUERY_RT_LINK_STATUS,
		
  /** PD 128 Channel Status.  @param (Uint32 *)*/
   CSL_AIF2_QUERY_PD_CHANNEL_STATUS,

  /** PD Packet Status for 128 channels if it is in or out of packet.  @param (Uint32 *)*/
   CSL_AIF2_QUERY_PD_PACKET_STATUS,

  /** PE 128 Channel Status.  @param (Uint32 *)*/
   CSL_AIF2_QUERY_PE_CHANNEL_STATUS,

  /** PE Packet Status for 128 channels if it is in or out of packet.  @param (Uint32 *)*/
   CSL_AIF2_QUERY_PE_PACKET_STATUS,

 /** Get Write and Read Offset Value at address in DB_IDB_DEBUG_OFS   @param  (Uint8 *) **/
   CSL_AIF2_QUERY_DB_IN_DEBUG_OFFSET_DATA,  

 /** Get Debug data written to bits 128:0 of Egress DB RAM @param (Uint32 *) **/
   CSL_AIF2_QUERY_DB_E_DEBUG_DATA, 

 /** Get Egress DB debug side band data setup  @param (CSL_Aif2DbSideData *)  **/
   CSL_AIF2_QUERY_DB_E_DEBUG_SIDE_DATA, 

 /** Get Write and Read Offset Value at address in DB_EDB_DEBUG_OFS   @param  (Uint8 *) **/
   CSL_AIF2_QUERY_DB_E_DEBUG_OFFSET_DATA,  

 /** Get Egress EOP count value   @param (Uint32 *) */
   CSL_AIF2_QUERY_DB_E_EOP_COUNT,

 /** Get Ingress EOP count value   @param (Uint32 *) */
   CSL_AIF2_QUERY_AD_I_EOP_COUNT,

 /** Get Aif2 timer link Pi captured value. use hAif2->arg_link to choose link   @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_LINK_PI_CAPTURE,

 /** Get Aif2 timer capture Radt values @param (CSL_Aif2AtCaptRadt  *) */
   CSL_AIF2_QUERY_AT_RADT_CAPTURE,
		
 /** Get Aif2 timer RP1 type capture value @param  (Uint8 *) **/
   CSL_AIF2_QUERY_AT_RP1_TYPE_CAPTURE,

 /** Get Aif2 timer RP1 tod capture lsb value @param  (Uint32 *) **/
   CSL_AIF2_QUERY_AT_RP1_TOD_CAPTURE_LSB,

 /** Get Aif2 timer RP1 tod capture msb value @param  (Uint32 *) **/
   CSL_AIF2_QUERY_AT_RP1_TOD_CAPTURE_MSB,

 /** Get Aif2 timer RP1 RP3 capture lsb value @param  (Uint32 *) **/
   CSL_AIF2_QUERY_AT_RP1_RP3_CAPTURE_LSB,

 /** Get Aif2 timer RP1 RP3 capture msb value @param  (Uint32 *) **/
   CSL_AIF2_QUERY_AT_RP1_RP3_CAPTURE_MSB,

 /** Get Aif2 timer RP1 RAD capture lsb value @param  (Uint32 *) **/
   CSL_AIF2_QUERY_AT_RP1_RAD_CAPTURE_LSB,

 /** Get Aif2 timer RP1 RAD capture msb value @param  (Uint32 *) **/
   CSL_AIF2_QUERY_AT_RP1_RAD_CAPTURE_MSB,

 /** Get Aif2 Phy timer clock count value  @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_PHY_CLOCK_COUNT,

  /** Get Aif2 Phy timer frame count value lsb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_PHY_FRAME_COUNT_LSB,

  /** Get Aif2 Phy timer frame count value msb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_PHY_FRAME_COUNT_MSB,

  /** Get Aif2 Rad timer clock count value  @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_RAD_CLOCK_COUNT,

  /** Get Aif2 Rad timer symbol count value  @param (Uint8 *) */
   CSL_AIF2_QUERY_AT_RAD_SYMBOL_COUNT,

  /** Get Aif2 Rad timer frame count value lsb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_RAD_FRAME_COUNT_LSB,

  /** Get Aif2 Rad timer frame count value msb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_RAD_FRAME_COUNT_MSB,

  /** Get Aif2 Ul Rad timer clock count value  @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_ULRAD_CLOCK_COUNT,

  /** Get Aif2 Ul Rad timer symbol count value  @param (Uint8 *) */
   CSL_AIF2_QUERY_AT_ULRAD_SYMBOL_COUNT,

  /** Get Aif2 Ul Rad timer frame count value lsb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_ULRAD_FRAME_COUNT_LSB,

  /** Get Aif2 Ul Rad timer frame count value msb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_ULRAD_FRAME_COUNT_MSB,

  /** Get Aif2 Dl Rad timer clock count value  @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_DLRAD_CLOCK_COUNT,

  /** Get Aif2 Dl Rad timer symbol count value  @param (Uint8 *) */
   CSL_AIF2_QUERY_AT_DLRAD_SYMBOL_COUNT,

  /** Get Aif2 Dl Rad timer frame count value lsb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_DLRAD_FRAME_COUNT_LSB,

  /** Get Aif2 Dl Rad timer frame count value msb @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_DLRAD_FRAME_COUNT_MSB,

  /** Get Aif2 Rad timer WCDMA chip count value  @param (CSL_Aif2AtWcdmaCount *) */
   CSL_AIF2_QUERY_AT_RAD_WCDMA_VALUE,
 
  /** Get Aif2 Ul Rad timer WCDMA chip count value  @param (CSL_Aif2AtWcdmaCount *) */
   CSL_AIF2_QUERY_AT_ULRAD_WCDMA_VALUE,

  /** Get Aif2 Dl Rad timer WCDMA chip count value  @param (CSL_Aif2AtWcdmaCount *) */
   CSL_AIF2_QUERY_AT_DLRAD_WCDMA_VALUE,

  /** Get Aif2 Rad timer time stamp clock count value  @param (Uint32 *) */
   CSL_AIF2_QUERY_AT_RAD_TSTAMP_CLOCK_COUNT,

  /** Get Aif2 GSM Tcount  value  @param (CSL_Aif2AtGsmTCount *) */
   CSL_AIF2_QUERY_AT_GSM_TCOUNT_VALUE,

  /** Get Aif2 EE DB interrupt  status value  @param (CSL_Aif2EeDbInt *) */
   CSL_AIF2_QUERY_EE_DB_INT_STATUS,

  /** Get Aif2 EE AD interrupt  status value  @param (CSL_Aif2EeAdInt *) */
   CSL_AIF2_QUERY_EE_AD_INT_STATUS,
        
  /** Get Aif2 EE CD(CDMA) interrupt  status value  @param (CSL_Aif2EeCdInt *) */
   CSL_AIF2_QUERY_EE_CD_INT_STATUS,
        
  /** Get Aif2 EE SD interrupt  status value  @param (CSL_Aif2EeSdInt *) */
   CSL_AIF2_QUERY_EE_SD_INT_STATUS,
        
  /** Get Aif2 EE VC interrupt  status value  @param (CSL_Aif2EeVcInt *) */
   CSL_AIF2_QUERY_EE_VC_INT_STATUS,

  /** Get Aif2 EE AIF2 run status value  @param (CSL_Aif2EeAif2Run *)  */
   CSL_AIF2_QUERY_EE_AIF2_RUN_STATUS,
      
  /** Get Aif2 EE error or alarm origination  @param (CSL_Aif2EeAif2Run *)  */
   CSL_AIF2_QUERY_EE_AIF2_ORIGINATION,
       
   /** Get Aif2 EE Link A interrupt  status value  @param (CSL_Aif2EeLinkAInt *) use hAif2->ee_arg to select function and hAif2->arg_link to select link */
   CSL_AIF2_QUERY_EE_LINKA_INT_STATUS,

  /** Get Aif2 EE Link B interrupt  status value  @param (CSL_Aif2EeLinkBInt *) use hAif2->ee_arg to select function and hAif2->arg_link to select link */
   CSL_AIF2_QUERY_EE_LINKB_INT_STATUS,

  /** Get Aif2 EE AT interrupt  status value  @param (CSL_Aif2EeAtInt *) use hAif2->ee_arg to select function */
   CSL_AIF2_QUERY_EE_AT_INT_STATUS,

   /* Get Aif2 EE PD common interrupt  status value  @param (CSL_Aif2EePdInt *) use hAif2->ee_arg to select function */
   CSL_AIF2_QUERY_EE_PD_INT_STATUS,

   /* Get Aif2 EE PE common interrupt  status value  @param (CSL_Aif2EePeInt *) use hAif2->ee_arg to select function */
   CSL_AIF2_QUERY_EE_PE_INT_STATUS
} CSL_Aif2HwStatusQuery;
/**
@} */



/** @addtogroup CSL_AIF2_DATASTRUCT
*
* @{ */

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/

/**
 * @brief pointer to the csl aif2 register global structure
 * */
typedef volatile CSL_Aif2Regs *CSL_Aif2RegsOvly;


/**
 * @brief This is a sub-structure in @a CSL_AifCommonLinkSetup. This structure is used for
 * configuring the parameters for Serdes params specific to a link  */
typedef struct
{

    /** Select Rx Align mode */
   CSL_Aif2SdRxAlign                   rxAlign;
   /** Rx loss of Signal */
   CSL_Aif2SdRxLos                      rxLos;

   /** polairty of Rx differential i/p - normal/inverted */
   CSL_Aif2SdRxInvertPolarity      rxPolarity;


} CSL_Aif2SdLinkSetup;


/**
 * @brief This is a sub-structure in @a CSL_Aif2LinkSetup. This structure is used for
 * configuring the parameters of common link index specifies which all link modules are using
 * */
typedef struct
{
   /** Link protocol  OBSAI/CPRI */
   CSL_Aif2LinkProtocol        linkProtocol;

    /** Link rate */      
   CSL_Aif2LinkRate             linkRate;

   /** Data width to be used on the link 7/8/15/16 bits */
   CSL_Aif2DataWidth          IngrDataWidth;
   
   /** Data width to be used on the link 7/8/15/16 bits */
   CSL_Aif2DataWidth          EgrDataWidth;
  
} CSL_Aif2CommonLinkSetup;


/**
 * @brief  This is a sub-structure in @a CSL_Aif2TmLinkSetup. This structure is used for
 * configuring the parameters of the CPRI params relating to TM  */
typedef struct
{
  
   /** CPRI  Link L1 Inband data 9 bits mask Bit 8: LOS_LOSERR_EN, Bit 7: LOS_LOSRX_EN, 
   Bit 6: LOF_LOFERR_EN, Bit 5: LOF_LOFRX_EN, Bit 4: RAI_LOSERR_EN, Bit 3: RAI_LOSRX_EN, 
   Bit 2: RAI_LOFERR_EN, Bit 1: RAI_LOFRX_EN, Bit 0: RAI_RAIRX_EN*/
   Uint16        L1InbandEn;

   /** RM Link LOS Error source link Selection */
   CSL_Aif2LinkIndex              RmLinkLosError;

  /** RM Link LOF Error source link Selection */
   CSL_Aif2LinkIndex              RmLinkLofError;

   /** RM Link LOS Rx bit source link Selection */
   CSL_Aif2LinkIndex              RmLinkLosRx;

   /** RM Link LOF Rx bit source link Selection */
   CSL_Aif2LinkIndex              RmLinkLofRx;

   /** RM Link RAI Rx bit source link Selection */
   CSL_Aif2LinkIndex              RmLinkRaiRx;

   /** start up info Z.66.0 */
   Uint8             TxStartup;

   /** transmit poniter p */
   Uint8             TxPointerP;

    /** protocol version Z.2.0 */
   Uint8             TxProtocolVer;

} CSL_Aif2CpriTmSetup;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2LinkSetup. This structure is used for
 * configuring the parameters of the TM */

typedef struct
{
    /** Boolean indicating if Tm link is to be enabled  */
   Bool                        bEnableTmLink;
	
   /** Boolean indicating if Loss of Sync on Rm is to be enabled  */
   Bool                        bEnableRmLos;

   /** seed value for Tx scramber initialization  */
   Uint8                        SeedValue;

   /** Boolean indicating if Tm Scrambler is to be enabled  */
   Bool                        bEnableScrambler;
   
   /** pointer to CPRI setup for TM */
   CSL_Aif2CpriTmSetup         pCpriTmSetup;

} CSL_Aif2TmLinkSetup;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2LinkSetup. This structure is used for
 * configuring the parameters of RM link*/

typedef struct
{
   /** Boolean indicating if Rm link is to be enabled  */
   Bool                        bEnableRmLink;
   
   /** setup Rm fifo threshold word size for reading received data */
   CSL_Aif2RmFifoThold      RmFifoThold;

   /** Suppress error reporting when the receiver state machine is not in state ST3 */
   CSL_Aif2RmErrorSuppress  RmErrorSuppress; 

   /** Enables the RM to automatically disable Serdes symbol alignment when the receiver state machine reaches state ST3 */
   Bool                        bEnableSdAutoAlign;
   
   /** Boolean indicating if Rm Scrambler is to be enabled  */
   Bool                        bEnableScrambler;

   /** Enables a state transition from teh ST3 to the ST0 state when lcv_det_thold is met  */
   Bool                        bEnableLcvUnsync;

   /** Writing a 1 to the bit will enable the Line Code Violation counter. THis 16 bit counter will saturate when it reaches a value of 0xffff. 
   Writing a 0 to this bit will clear and disable the counter. The current counter value is available as status, lcv_cntr_value */
   Bool                        bEnableLcvControl;

   /** Enables the clock detect watch dog timer. */
   Bool                        bEnableWatchDog;

    /** Defines the wrap value of the clock detection watchdog circuit. A value of zero disables the clock watchdog timer, Range 0 to 255 */
   Uint8                        WatchDogWrap;

   /** Enables the clock quality circuit. */
   Bool                        bEnableClockQuality;

   /** Defines the wrap value of the clock monitor used to define clock quality. A value of zero disables the clock monitor, Range 0 to 65,535 */
   Uint16                      ClockMonitorWrap;

   /** Sets 8b10b los detect threshold values in number of Line Code Violations received during a master frame, OBSAI, or during a Hyperframe, 
   CPRI. Writing to this location will automatically clear the num_los counter and num_los_det status bit. Range 0 to 65,535*/
   Uint16                      losDetThreshold;

    /** Threshold value for consecutive valid blocks of bytes which result in state ST1. Range 0 to 65,535 */
   Uint16                      SyncThreshold;

    /** Threshold value for consecutive valid message groups which result in state ST3. Range 0 to 65,535*/
   Uint16                      FrameSyncThreshold;

     /** Threshold value for consecutive invalid blocks of bytes which result in state ST0. Range 0 to 65,535 */
   Uint16                      UnsyncThreshold;

    /** Threshold value for consecutive invalid message groups which result in state ST1. Range 0 to 65,535 */
   Uint16                      FrameUnsyncThreshold;
} CSL_Aif2RmLinkSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2LinkSetup. This structure is used for
 * configuring the parameters of Retransmitter */

typedef struct
{
   /** The CI Select bits indicate the selected inbound link for the retransmitted data path */
   CSL_Aif2LinkIndex     CiSelect;

   /** The Empty Message Enable Bit configures the RT block to insert an empty message in the event that a message is discovered 
   to have a code violation in the header. The configuration is valid in OBSAI mode only. */
   Bool                        bEnableEmptyMsg;

   /** The RT Configuration field configures the mode of operation of the RT block */
   CSL_Aif2RtConfig       RtConfig;
  

} CSL_Aif2RtLinkSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2Pd(Pe)LinkSetup. This structure is used for
 * configuring the parameters of Pd and Pe dual bit map */
typedef struct
{
   /** CPRI Dual Bit Map FSM (DBMF) channel count, sets the max number of AxC supported in a given Link. i.e. 
   for CPRI 4x LTE15MHz this must be set to 7b'0000001 indicating 2 AxC */
   Uint8                                         DbmX;
   /** DBMF bubble count where 0:indicates 1 bubble of 1 AxC sample (4bytes).OBSAI DBMF assumes 4 AxC samples as a bubble length. 
   A burst of bubbles is inserted only when dictated to do so by the bit maps. This field gives great flexibility in rate matching  */
   Uint8                                         DbmXBubble;
   /** DBMF repititions of map1. */
   Uint8                                         Dbm1Mult;
   /** DBMF number of bits of bit map1 to use. */
   Uint8                                         Dbm1Size;
   /** DBMF number of bits of bit map2 to use. */
   Uint8                                         Dbm2Size;
   /** bit-by-bit bit map [99:0]. pd_dbm_1map[0].dbm_1map[0] == bit 0 of 100 bits */
   Uint32                                       Dbm1Map[4];
   /** bit-by-bit bit map [67:0]. pd_dbm_2map[0].dbm_2map[0] == bit 0 of 68 bits*/
   Uint32                                       Dbm2Map[3];
   
} CSL_Aif2DualBitMap ;

/**
 * @brief This is a sub-structure in @a CSL_Aif2PdLinkSetup. This structure is used for
 * configuring the parameters of 32 Pd type LUT  */
typedef struct
{
    /** PD OBSAI time stamp format  selection  */
   CSL_Aif2TstampFormat                 ObsaiTsFormat;

   /** PD CRC type selection  */
   CSL_Aif2CrcLen                    PdCrcType;

    /** enable CRC for this link */
   Bool                                    bEnableCrc;

    /** OBSAI mode selection between packet and AxC */
   CSL_Aif2PdDataMode                PdObsaiMode;

    /** enable Ethernet strip for this link */
   Bool                                    bEnableEnetStrip;
	
   /** enable CRC calculation  for OBSAI header */
   Bool                                    bEnableCrcHeader;
   
} CSL_Aif2PdTypeLut ;

/**
 * @brief This is a sub-structure in @a CSL_Aif2LinkSetup. This structure is used for
 * configuring the parameters of protocol decoder */
typedef struct
{
   /** Boolean indicating if Pd link is to be enabled  */
   Bool                        bEnablePdLink;
 
   /** CPRI: bit3-0 enables stripping Ethernet headers for chan3-0 OBSAI: unused  */
   Uint8                        CpriEnetStrip;

    /** CRC: programmable polynomial for CRC8 (other polynomials are fixed) */
   Uint8                        Crc8Poly;

   /** CRC: programmable seed value for CRC8 (other polynomials are fixed) */
   Uint8                        Crc8Seed;

   /** CPRI Control word pre packing bit order control (used for changing endianness) */
   Uint8                        PreEncBitmap;

   /** CPRI Control word post packing bit order control (used for changing endianness) */
   Uint8                        PostEncBitmap;

   CSL_Aif2CpriAxCPack                CpriAxCPack;
   
   /** CRPI Control Word 4B/5B encoding enable for 4 channels */
   CSL_Aif2CpriCwPktDelim           CpriCwPktDelimitor[4];

   /** CPRI Conrol Word Null Delimitor. Used instead of 4B/5B for packet delimitation. Only used when enabled by CpriCwPktDelimitor fields */
   Uint16                                      CpriCwNullDelimitor;

   /** PD CPRI Pack map structure  */
   Uint8                                        PdPackDmaCh[4];

  /** enable pd cpri pack  */
   Bool                                         bEnablePack[4];

   /** PD CRC  setup structure  */
   CSL_Aif2CrcLen                          PdCpriCrcType[4];

   /** enable pd cpri crc  */
   Bool                                         bEnableCpriCrc[4];
   
   /** Dual bit map structure for Pd CPRI dual bit map rule FSM */
   CSL_Aif2DualBitMap                   PdCpriDualBitMap;

   /** 32 Pd Type LUT structure */ 
   CSL_Aif2PdTypeLut                   PdTypeLut[32];

   /** DBMF CPRI Stream LUT: AxC:used to map DBM X count to DMA channel. PKT:2 lsb indicates 0-3 PKT packing circuit (assumed 4B/5B encoding)*/
   Uint8                                        CpriDmaCh[128];
   
   /** DBMF CPRI Stream LUT: enable-disable of channel, for each value of DBM X count.*/
   Bool                                        bEnableCpriX[128];

    /** DBMF CPRI Stream LUT: dicates the cpri payload is to be used as AxC (normal) or Packet traffic */
   Bool                                        bEnableCpriPkt[128];

   /** Fine AxC offset. Used in the front end of PD to align word data into QWords. bit [1:0] are offset into a QWord.
   bit[2] give RSA double QWork alignment. Bit[2] and corresponding axc_offset[0] should always be programmed to be identical*/
   Uint8                                       Cpri8WordOffset[128];
   
   /** All possible CPRI CW per hyperframe are are mapped to one of four(0~3) CPRI CW staging areas*/
   Uint8                                       CpriCwChannel[256];    

   /** All possible CPRI CW per hyperframe. Dicatates whether the control word should be captured at all*/
   Bool                                        bEnableCpriCw[256];

   /** All possible CPRI CW per hyperframe. identifies which control word slot is eop for each stream */
   Bool                                        bHyperFrameEop[256];
   
} CSL_Aif2PdLinkSetup;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2LinkSetup. This structure is used for
 * configuring the link parameters of protocol encoder */
typedef struct
{
   /** Boolean indicating if Pe link is to be enabled  */
   Bool                        bEnablePeLink;
   
   /** For streams that are AxC, use DB as a circular RAM which will feed DIO DMA. (WCDMA use DIO) otherwise, 
   DB is used as a FIFO for AxC traffic and will feed CPPI DMA */
   CSL_Aif2CppiDio            PeCppiDioSel;

   /** AIF2 is tollerant of whole symbols of missing data on AxC-by-AxC basis */
   Bool                         TddAxc;

   /** GSM compress mode turn on or off (only used for GSM) */
   Bool                         bGsmCompress;
   
   /**  enable or disable OBSAI bubble bandwidth **/
   Bool                        bEnObsaiBubbleBW;
   /** delay (in sys_clks) between DB read and PE processing */
   Uint8                        PeDelay;

   /** CRC: programmable polynomial for CRC8 (other polynomials are fixed) */
   Uint8                        Crc8Poly;

   /** CRC: programmable starting seed value (CRC16 & CRC32 seed is fixed)*/
   Uint8                        Crc8Seed;

   /** CPRI Control word pre encoding bit order control (used for changing endianness) */
   Uint8                        PreEncBitmap;

   /** CPRI Control word post encoding bit order control (used for changing endianness) */
   Uint8                        PostEncBitmap;
   
   /** Dual bit map structure for Pe CPRI dual bit map rule FSM */
   CSL_Aif2DualBitMap                   PeCpriDualBitMap;

   /**  CRPI: identifies the bit precision of the IQ data. Used to un-packing packet data passed over CPRI AxC slots */
   CSL_Aif2CpriAxCPack                CpriAxCPack;

   /** CPRI Conrol Word Null Delimitor. Used instead of 4B/5B for packet delimitation. Only used when enabled by CpriCwPktDelimitor fields */
   Uint16                                      CpriCwNullDelimitor;

   /** CRPI Control Word 4B/5B encoding enable for 4 channels */
   CSL_Aif2CpriCwPktDelim           CpriCwPktDelimitor[4];
   
   /** PE CPRI Pack map structure  */
   Uint8                                        PePackDmaCh[4];

   /** enalbe pe cpri pack */
   Bool                                         bEnablePack[4];

   /** All possible CPRI CW per hyperframe are are mapped to one of four(0~3) CPRI CW staging areas*/
   Uint8                                       CpriCwChannel[256];    

   /** All possible CPRI CW per hyperframe. Dicatates whether the control word should be captured at all*/
   Bool                                        bEnableCpriCw[256];

} CSL_Aif2PeLinkSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2LinkSetup. This structure is used for
 * configuring the parameters of aif2 timer module */
typedef struct
{
   /** Maximum pi offset value. max and min pi makes a window for pi offset */
   Uint32                      PiMax;
   
   /** Minimum pi offset value. max and min pi makes a window for pi offset */
   Uint32                      PiMin;

   /** Delta event offset index it is calculated based on byte clock*/
   Uint32                      DeltaOffset;

   /** Control for positive or negative delta for TM delta event. Controls the BFN PHYT frame number passed to the TM when the Delta event occurs*/
   Bool                         IsNegativeDelta;

   /** PE1 event offset index it is calculated based on byte clock*/
   Uint32                      PE1Offset;

   /** PE2 event offset index it is calculated based on byte clock*/
   Uint32                      PE2Offset;
	
} CSL_Aif2AtLinkSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of a SD module, the link index specifies which SD module is used
 * links 0-3 use SD module 0, links 4-5 use SD module 1 */

typedef struct
{
   /** Indicating if B8 PLL is to be enabled */
   Uint8                        bEnablePllB8;
   
   /** Indicating if B4 PLL is to be enabled */
   Uint8                        bEnablePllB4;


   /**  Tx byte clock from either B8 or B4 SEDES link will be selected as sys_clk once the PLL has acquired lock */
   CSL_Aif2SdClockSelect      SysClockSelect;

   /**  Select if link clock is gated off or on  each bool array is matched with each link */
   Bool                                DisableLinkClock[6];
 
} CSL_Aif2SdCommonSetup;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2PdCommonSetup. This structure is used for
 * configuring the routing parameters of protocol decoder  */
typedef struct
{
   /**OBSAI time stamp in header. Used to extend addressing by using the TS field The number of bits of TS to compare is controlled via the ctrl field.*/
   Uint8                              RouteTs;

   /**OBSAI type field in header */
   Uint8                              RouteType;

   /**OBSAI address field in header*/
   Uint16                            RouteAddr;

   /**Link number for which to apply this routing rule*/
   Uint8                            RouteLink;
   
   /** controls how many OBSAI time stamp bits to use in the reception routing. */
   CSL_Aif2RouteMask             RouteMask;

} CSL_Aif2PdRoute;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2PdCommonSetup. This structure is used for
 * configuring Pd 128 Dma channel configuration */
typedef struct
{
   /**Channel On/Off. Schedules a channel to be turned on or off.*/
   Bool                              bChannelEn;

   /**PD data format (Normal or UL RSA)*/
   CSL_Aif2LinkDataType         DataFormat;
   
} CSL_Aif2PdChConfig;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2PdCommonSetup. This structure is used for
 * configuring Pd 128 Dma channel configuration 1 register*/
typedef struct
{
   /**TS: enable OBSAI time stamp watch dog timer (only known use is GSM BB hopping). (Set to 0 for CPRI) */
   Bool                              bTsWatchDogEn;

   /**GSM data format (Other or GSM UL)*/
   CSL_Aif2GSMDataFormat         DataFormat;

    /**OBSAI framing counter: Which of 6 framing counter terminal counts should be used for each dma channel. (codes 3'b110 & 3'b111 are reserved)*/
   Uint8                             FrameCounter;

   /**Offset for DIO DMA mode. Used to align DMA for AxC with different AxC offsets.*/
   Uint8                             DioOffset;

   /**PD TDD, disables DMA of whole symbols (CPPI packets), Program as 0xffff for most applications Bit mapped, bit0 --> sym0 of framing FSM
   (Symbol count above 15 are always enabled) */
   Uint16                            TddEnable;
   
} CSL_Aif2PdChConfig1;

/**
 * @brief This is a sub-structure in @a CSL_Aif2Pd(Pe)CommonSetup. This structure is used for
 * configuring the parameters of PD, PE frame counter */
typedef struct
{
   /** OBSAI AxC framing counter. Index Terminal count. */
   Uint8                              FrameIndexTc;

   /** OBSAI AxC framing counter. Index Start count.*/
   Uint8                              FrameIndexSc;

   /** OBSAI AxC framing counter. Symbol terminal count */
   Uint8                              FrameSymbolTc;
	
} CSL_Aif2FrameCounter;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of protocol decoder which are common to all links */
typedef struct
{

   Bool                                 PdGlobalEnable;
   
   /** For streams that are AxC, use DB as a circular RAM which will feed DIO DMA. (WCDMA use DIO) otherwise, 
   DB is used as a FIFO for AxC traffic and will feed CPPI DMA */
   CSL_Aif2CppiDio            PdCppiDioSel;

   /**Reception timing window width parameter. Indicates the window size for searching the radio frame boundary identified by TS=0*/
   Uint16                            AxCOffsetWin;
   
   /** TS: OBSAI time stamp watch dog timer count duration. Counts n x 64 sys_clks */
   Uint16                                TsWatchDogCount;

   /** Controls circuit to simply report or to report and add an EOP if the wdog fails on an expected EOP */
   Bool                                WatchDogEopAdd;

   /** Report every missed WDog fail, or report only fails of missing EOP */
   CSL_Aif2PdWatchDogReport           WatchDogReport;

   /** Max expected terminal count value for the RadT timer value. Used for creating a exected timing window */ 
   Uint32                                PdRadtTC;

   /** Pd frame and symbol terminal counting value to calculate sop and eop of packet */ 
   CSL_Aif2FrameCounter       PdFrameTC[6];

   /** Pd route */
   CSL_Aif2PdRoute               PdRoute[128];
   
   /** Pd 128 Dma channel configuration */
   CSL_Aif2PdChConfig          PdChConfig[128];

   /*** OBSAI: Antenna Carrier offset programmed in 307.2MHz clocks and relative to the Frame Boundary of the RadT AT timer. 
          CPRI: Antenna Carrier Offset programmed in (non-oversampled) samples, relative to the link (PHY) frame boundary */
   Uint32                               AxCOffset[128];

   /** Pd 128 Dma channel configuration 1 */
   CSL_Aif2PdChConfig1          PdChConfig1[128];

   /** TDD symbol enable/disable from symbol 16 ~ 47  */
   Uint32                               TddEnable1[128];
   /** TDD symbol enable/disable from symbol 48 ~ 79  */
   Uint32                               TddEnable2[128];
   /** TDD symbol enable/disable from symbol 80 ~ 111  */
   Uint32                               TddEnable3[128];
   /** TDD symbol enable/disable from symbol 112 ~ 143  */
   Uint32                               TddEnable4[128];

   /** Pd Frame message terminal counter for  OBSAI and CPRI  */
   Uint16                            PdFrameMsgTc[128];

} CSL_Aif2PdCommonSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2Pd(Pe)CommonSetup. This structure is used for
 * configuring the parameters of Modulo Terminal count */
typedef struct
{
   /** Modulo Terminal count of the rule counter. Dictates the period of the rule. Terminal count is the OBSAI Module minus 1 */
   Uint16                              RuleModulo;

   /** Transmission rule enable */
   Bool                               bEnableRule;

    /** Bit 1: Module Rule oppeations on OBSAI control messages   bit0: AxC messages */
   Bool                               bRuleObsaiCtlMsg;

   /** Index. Transmission Rule. Index indicates at which count the rule will fire */
   Uint16                              RuleIndex;

   /** Indicates which link the rule is allocated to */
   Uint8                              RuleLink;

	
} CSL_Aif2ModuloTc;

/**
 * @brief This is a sub-structure in @a CSL_Aif2PeCommonSetup. This structure is used for
 * PE DMA channel configuration 0 register */
typedef struct
{
   /** CRC: enable CRC check on AxC by AxC basis */
   Bool                              bCrcEn;

   /** OBSAI framing counter: Which of 6 framingcounter terminal counts should be used for each dma channel. (codes 3b110 and 3b111 are reserved) */
   Uint8                              FrameTC;

   /** Controls RT to perform appropriate insterion/aggregation into PHY */
   CSL_Aif2PeRtContol                RtControl;

   /** CRC: length of CRC */
   CSL_Aif2CrcLen                  CrcType;

   /** check if data is ethernet or not */
   Bool                                     isEthernet;

    /** calculate CRC 16 over 3 bytes of OBSAI header */
   Bool                                     CrcObsaiHeader;
	
} CSL_Aif2PeDmaCh0;

/**
 * @brief This is a sub-structure in @a CSL_Aif2PeCommonSetup. This structure is used for
 * PE input fifo control register  */
typedef struct
{
  
   /** Set water mark per channel. Water mark controls fill level for which lower/higher fetch rate is issued */
   Uint8                               MFifoWmark;

   /** Set full level per channel. Full level controls halt of data fetch to prevent overflow*/
   Uint8                               MFifoFullLevel;

    /** Normally set to 0. First non-tdd symbol of frame. Used for startup sync with DMA*/
   Uint8                              SyncSymbol;
	
} CSL_Aif2PeInFifoControl;

/**
 * @brief  This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of protocol encoder which are common to all links */
typedef struct
{
   /**  Gives Phase alignement relative to Channel Radio Frame Boundary for scheduling DMA. 
   OBSAI: only lsb is used CPRI: all three bits give 8th phase alignment. Phase can be used to adjust DMA according to DMA transfer budget.*/
   Uint8                                PeTokenPhase;

   /**  bit order for Ethernet preamble and SOF  */
   Bool                               EnetHeaderSelect;
   
   /**  DirectIO buffer length, set same as value in DB */
   CSL_Aif2DioLen              GlobalDioLen;
 
   /**  PE globla enable setup  */
   Bool                                PeGlobalEnable;
   
   /** PE frame and symbol terminal counting value to calculate sop and eop of packet */ 
   CSL_Aif2FrameCounter       PeFrameTC[6];
   
   /**Enable PE channels one-by-one*/
   Bool                      bEnableCh[128];

   /** PE channel configuration 0 */
   CSL_Aif2PeDmaCh0         PeDmaCh0[128];
   
   /** PE input fifo control */
   CSL_Aif2PeInFifoControl        PeInFifo[128];
   
   /** Antanna carrier offset. Programmed in sys-clocks */
   Uint32                             PeAxcOffset[128];

   /** PE Frame message terminal counter for OBSAI and CPRI    */
   Uint16                            PeFrameMsgTc[128];

   /** Modulo terminal count  structure for Pe OBSAI WCDMA or LTE */
   CSL_Aif2ModuloTc            PeModuloTc[64];

   /** PE 128 DMA channel OBSAI time stamp value which is inserted into the frame */
   Uint8                                       PeChObsaiTS[128];

    /** PE 128 DMA channel OBSAI type value which is inserted into the frame */
   Uint8                                       PeChObsaiType[128];

   /** PE 128 DMA channel OBSAI address value which is inserted into the frame */
   Uint16                                       PeChObsaiAddr[128];

    /** PE 128 DMA channel OBSAI time stamp mask value which is inserted into the frame */
   CSL_Aif2RouteMask                   PeChObsaiTsMask[128];

   /** PE 128 DMA channel OBSAI time stamp generation algorithm  */
   CSL_Aif2TstampFormat             PeChObsaiTsfomat[128];
   
   /* OBSAI channel (not used for CPRI) is a packet channel not AxC channel   */
   Bool                                         PeObsaiPkt[128];

   /* GSM OBSAI Address is taken from CPPI protocol specific bits (SW value passed in data dma) instead of obsai_adr mmr bits */
   Bool                                         PeBbHop[128];
   
   /** Dual bit map structure for Pe OBSAI dual bit map rule FSM */
   CSL_Aif2DualBitMap             PeObsaiDualBitMap[64];

   /** DMA channel rule LUT 0 for first 512 rules */
   Uint8                               ChIndex0[512];
   /** DMA channel rule LUT 0 enable for first 512 rules */
   Bool                                bEnableChIndex0[512];
   Bool                                CpriPktEn0[512];
   
    /** DMA channel rule LUT 1 for second 512 rules  */
   Uint8                               ChIndex1[512];
   /** DMA channel rule LUT 1 enable for first 512 rules */
   Bool                                bEnableChIndex1[512];
   /** DMA channel rule LUT 1 cpri packet enable for first 512 rules */
   Bool                                CpriPktEn1[512];

   /** DMA channel rule LUT 2 for third 512 rules */
   Uint8                               ChIndex2[512];
   /** DMA channel rule LUT 2 enable for first 512 rules */
   Bool                                bEnableChIndex2[512];
   /** DMA channel rule LUT 2 cpri packet enable for first 512 rules */
   Bool                                CpriPktEn2[512];
   
    /** DMA channel rule LUT 3 for fourth 512 rules  */
   Uint8                               ChIndex3[512];
   /** DMA channel rule LUT 3 enable for first 512 rules */
   Bool                                bEnableChIndex3[512];
   /** DMA channel rule LUT 3 cpri packet enable for first 512 rules */
   Bool                                CpriPktEn3[512];

   /** DMA channel rule LUT 4 for fifth 512 rules */
   Uint8                               ChIndex4[512];
   /** DMA channel rule LUT 4 enable for first 512 rules */
   Bool                                bEnableChIndex4[512];
   /** DMA channel rule LUT 4 cpri packet enable for first 512 rules */
   Bool                                CpriPktEn4[512];
   
    /** DMA channel rule LUT 5 for sixth 512 rules  */
   Uint8                               ChIndex5[512];
   /** DMA channel rule LUT 5 enable for first 512 rules */
   Bool                                bEnableChIndex5[512];
   /** DMA channel rule LUT 5 cpri packet enable for first 512 rules */
   Bool                                CpriPktEn5[512];

    /** DMA channel rule LUT 6 for seventh 512 rules */
   Uint8                               ChIndex6[512];
   /** DMA channel rule LUT 6 enable for first 512 rules */
   Bool                                bEnableChIndex6[512];
   
    /** DMA channel rule LUT 7 for eighth 512 rules  */
   Uint8                               ChIndex7[512];
   /** DMA channel rule LUT 7 enable for first 512 rules */
   Bool                                bEnableChIndex7[512];

} CSL_Aif2PeCommonSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of ingress Data Buffer */
typedef struct
{

   /** Channel number to be added or changed */
   Uint8                   ChannelNum;
   
   /** Channel configuration structure for all 128 channels */
   Uint8                               BaseAddress;

   /** Channel configuration structure for all 128 channels */
   CSL_Aif2DbFifoDepth        BufDepth;

   /** Big endian, little endian  swapping control */
   CSL_Aif2DbDataSwap       DataSwap;

   /** Internally changing IQ data order control */
   CSL_Aif2DbIqOrder           IQOrder;

   /** Boolean indicating if the protocol specific data is to be enabled. this is only used for ingress DB */
   Bool                               bEnablePsData;

    /** Programmable packet type that is inserted into pkt_type field in CPPI Info Word 0. this is only used for ingress DB  */
   Uint8                               PacketType;

   /**  Address offset of SOP for DIO channels  */
   Uint8                               EgressDioOffset;
	
} CSL_Aif2DbChannel;

/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of ingress Data Buffer */
typedef struct
{
   /** Boolean indicating if Ingress data buffer is to be enabled */
   Bool                               bEnableIngrDb;

   /** DIO buffer length selection between 128 and 256 bytes */
   CSL_Aif2DioLen              DioBufferLen;

   /** Boolean indicating if the channel is to be enabled */
   Bool                               bEnableChannel[128];

   /** Channel configuration structure for all 128 channels */
   CSL_Aif2DbChannel        IngrDbChannel[128];

} CSL_Aif2IngrDbSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of Egress data buffer */

typedef struct
{
   /** Boolean indicating if Ingress data buffer is to be enabled */
   Bool                               bEnableEgrDb;

   /** DIO buffer length selection between 128 and 256 bytes */
   CSL_Aif2DioLen              DioBufferLen;

   /** Egress Packet mode control  */
   CSL_Aif2DbPmControl     PmControl;

   /** Boolean indicating if the channel is to be enabled */
   Bool                               bEnableChannel[128];
   
   /** Channel configuration structure for all 128 channels */
   CSL_Aif2DbChannel        EgrDbChannel[128];
  
} CSL_Aif2EgrDbSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the common parameters of aif2 Dma module */

typedef struct
{
   /**  global enable Ingress DIO module  */
   Bool                                 IngrGlobalDioEnable;

   /**  global enable Egress DIO module  */
   Bool                                 EgrGlobalDioEnable;
   
   /**  global enable Ingress AD scheduler module  */
   Bool                                 IngrGlobalEnable;

   /**  global enable Egress AD module  */
   Bool                                 EgrGlobalEnable;
   
   /**   Wrapping count of EOPs sent to the CPPI DMA Controller */
   Uint32                              IngrEopCount;
   
   /** This field controls how the Ingress Scheduler handles packets marked as failed by the PD*/
   CSL_Aif2AdFailMode           FailMode;

  /** This field controls the Ingress Scheduler aribitration priority between packet and dio */
  CSL_Aif2AdIngrPriority              IngrPriority;

  /**Queue manager number sent to CDMA Scheduling Interface for all egress transactions 0x3 to 0x0*/
  Uint8                                 Tx_QueManager;

  /**Base egress queue number for AIF2. Channel id of each packet 127-0 added to this base value to generate 
  egress queue number sent to CDMA Scheduling Interface. 0xF80 to 0x000*/
  Uint16                                 Tx_QueNum;

  /** This field controls the Egress Scheduler aribitration priority between packet and dio */
  CSL_Aif2AdEgrPriority              EgrPriority;

} CSL_Aif2AdCommonSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2AdDioSetup. This structure is used for
 * configuring the parameters of aif2 dma engine */
typedef struct
{
  /** Selects which buffer channel number table for the DMA engine to use */
  CSL_Aif2AdBcnTable                 BcnTableSelect;
  
  /** Sets the number of quad words per AxC */
  CSL_Aif2AdNumQWord              NumQuadWord;

   /** Sets the number of quad words per AxC */
  Uint8                                        NumAxC;

   /** Sets the maximum DMA burst length */
  CSL_Aif2AdNumQWord              DmaBurstLen;
   
  /** enable or disable Egress DIO RSA data type format  */
  Bool                                       bEnEgressRsaFormat;

   /** enable or disable Ingress DIO RSA data type format  */
  Bool                                       bEnIngressRsaFormat;

   /** enable or disable DIO DMA channel  */
  Bool                                        bEnDmaChannel;

   /** Set the number of data blocks to transfer before wrapping back to dma_base_addr */
  Uint16                                        DmaNumBlock;

   /** Sets the VBUS destination base address (upper 28 bits of 32 bit data bus). */
  Uint32                                        DmaBaseAddr;

   /** Sets the DMA burst address stride (in multiples of 0x10). After each DMA burst, the DMA address will increment by this amount */
  Uint16                                        DmaBurstAddrStride;

    /** Sets the DMA block address stride (in multiples of 0x10). */
  Uint16                                        DmaBlockAddrStride;

  /** Data Buffer Channel Number for total 64 channels */
  Uint8                                          DBCN[64];
  
} CSL_Aif2AdDioEngine;

/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of aif2 dma module especially for DIO mode */
typedef struct
{
  /** Boolean indicating if each Dio engine is to be enabled or not */
  Bool                              IngrDioEngineEnable[3];

  /** Boolean indicating if each Dio engine is to be enabled or not */
  Bool                              EgrDioEngineEnable[3];
  
  /** setup ingress dio engine */
  CSL_Aif2AdDioEngine     IngrDioEngine[3];

  /** setup egress dio engine */
  CSL_Aif2AdDioEngine     EgrDioEngine[3];

} CSL_Aif2AdDioSetup;

/** 
 * This object is used to query Phy/Rad timer count
 *  and timer init objects
 *
 */
typedef struct 
{
   /** AT event count clock num */
   Uint32       ClockNum;
   /** AT event count symbol num */
   Uint8         SymbolNum;
   /** AT event count lut index num */
   Uint8         LutIndexNum;
   /** AT event count frame lsb num */
   Uint32       FrameLsbNum;
   /** AT event count frame msb num */
   Uint32       FrameMsbNum;
   /** FCB - 1 flag for Ul rad or Dl rad timer */
   Bool          FcbMinusOne;

} CSL_Aif2AtCountObj;

/** 
 * This object is used to intialise Phy and Rad timers 
 * 
 */
typedef struct
{
  /** AT event phy timer init count pointer */
  CSL_Aif2AtCountObj      *pPhyTimerInit;
  /** AT event rad timer init count pointer */
  CSL_Aif2AtCountObj      *pRadTimerInit;
  /** AT event ul rad timer init count pointer */
  CSL_Aif2AtCountObj      *pUlRadTimerInit;
  /** AT event dl rad timer init count pointer */
  CSL_Aif2AtCountObj      *pDlRadTimerInit;

} CSL_Aif2AtInitObj;

/** 
 * This object is used to setup terminal count value for  Phy and Rad timers 
 * 
 */
typedef struct
{
  /** AT event phy timer terminal count pointer */
  CSL_Aif2AtCountObj      *pPhyTimerTc;
  /** AT event rad timer terminal count pointer */
  CSL_Aif2AtCountObj      *pRadTimerTc;
   /** Rad timer Ram structure for symbol and Lut index  */
  Uint32                            RadClockCountTc[128];

} CSL_Aif2AtTcObj;


/** @brief This object contains the aif2 GSM  Tcount  information */
typedef struct 
{
   /** GSM T1 count */
   Uint16                   t1;
   
   /** GSM T2 count   */
   Uint8                   t2;
   
   /** GSM T3 count  */
   Uint8                   t3;

} CSL_Aif2AtGsmTCount;



/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the common parameters of aif2 timer module */
typedef struct
{
   /** Phy sync mode selection */
  CSL_Aif2AtSyncSource          PhySyncSel;
   
  /** Rad sync mode selection */
  CSL_Aif2AtSyncSource          RadSyncSel;

   /** Rp1 mode or not */
  CSL_Aif2AtSyncMode            SyncMode;

  /** Auto resync if new frame boundary is received */
  CSL_Aif2AtReSyncMode         AutoResyncMode;

  /** Crc use or not */
  CSL_Aif2AtCrcUse                CrcMode;

   /** Crc flip normal  or reverse */
  CSL_Aif2AtCrcFlip                 CrcFlip;

   /** Crc init ones is init0  or init1 */
  CSL_Aif2AtCrcInitOnes          CrcInitOnes;

  /** Crc invert is applied  or not */
  CSL_Aif2AtCrcInvert             CrcInvert;

  /** RP1 sync_sampl_window value = size - 1*/
  Uint8                                   SyncSampleWindow;

  /** RP1 RADT Frame Load selection (8bit ~ 40bits) */
  Uint8                                   Rp1RadtFrameLoad;

  /** RP1 PHYT Frame Load selection (8bit ~ 40bits) */
  Uint8                                   Rp1PhytFrameLoad;

  /** Phyt compare value when when radt sync is selected to CSL_AIF2_PHYT_CMP_SYNC */
  Uint32                                  PhytCompValue;

  /** RP1 RAD Type Select */
  CSL_Aif2AtRp1TypeField              Rp1Type;

  /** WCDMA value Divide terminal count to make WCDMA counter working 3.84 MHz sample rate */
  Uint8                                    WcdmaDivTC;
  
  /** timer Init structure for Phy and Rad(Ul,Dl) */
  CSL_Aif2AtInitObj                  AtInit;              

   /** timer terminal count and LUT  structure for Phy and Rad(Ul,Dl) */
  CSL_Aif2AtTcObj                   AtTerminalCount; 

   /** T count  structure for GSM */
  CSL_Aif2AtGsmTCount           AtGsmTcount; 

} CSL_Aif2AtCommonSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2AtEventSetup. This structure is used for
 * configuring the parameters of aif2 at event for external Rad events and Internal events for dio */
typedef struct
{
   /** Select Event */
   CSL_Aif2AtEventIndex      EventSelect;
   
   /** Event offset index */
   Uint32                             EventOffset;

   /** Event strobe selection  */
   CSL_Aif2AtEvtStrobe        EvtStrobeSel;

    /** Event modulo  */
   Uint32                             EventModulo;

   /** Event Mask LSB for external GSM event */
   Uint32                             EventMaskLsb;

    /** Event Mask MSB for external GSM event */
   Uint32                             EventMaskMsb;

   /** frame strobe selection for DIO  */
   CSL_Aif2AtEvtStrobe        DioFrameStrobeSel;

   /** DIO frame Event offset index */
   Uint32                             DioFrameEventOffset;

} CSL_Aif2AtEvent;



/**
 * @brief This is a sub-structure in @a CSL_Aif2CommonSetup. This structure is used for
 * configuring the parameters of aif2 dma module especially for external Rad events and Internal events for dio */
typedef struct
{
   /** Active event flag */
   Bool                                bEnableRadEvent[24];
   
    /** Aif2 Timer 19 external event and 5 special events config*/
   CSL_Aif2AtEvent              AtRadEvent[24];

   /** Active ingress dio event flag */
   Bool                                bEnableIngrDioEvent[3];
   
   /** Aif2 Timer 3 ingress dio event  config */
   CSL_Aif2AtEvent              AtIngrDioEvent[3];

    /** Active egress dio event flag */
   Bool                                bEnableEgrDioEvent[3];

    /** Aif2 Timer 3 egress  event  config */
   CSL_Aif2AtEvent              AtEgrDioEvent[3];

} CSL_Aif2AtEventSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2HwSetup. This structure is used for
 * configuring the parameters global to AIF2 */
typedef struct 
{
   /** Active link flag  */
   Bool                     ActiveLink[6];
   
   /**  frame mode : Normal mode , Short frame mode */
   CSL_Aif2FrameMode      frameMode;


} CSL_Aif2GlobalSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2HwSetup. This structure is used for
 * configuring the parameters of a link */
typedef struct 
{

   /** pointer to Sd common setup */
   CSL_Aif2SdCommonSetup      *pSdCommonSetup;

   /** pointer to Protocol decoder common setup */
   CSL_Aif2PdCommonSetup          *pPdCommonSetup;

   /** pointer to protocol encoder common setup */
   CSL_Aif2PeCommonSetup          *pPeCommonSetup;
   
   /** pointer to data buffer setup */
   CSL_Aif2IngrDbSetup              *pIngrDbSetup;

   /** pointer to data buffer setup */
   CSL_Aif2EgrDbSetup              *pEgrDbSetup;

   /** pointer to Aif2 DMA setup */
   CSL_Aif2AdCommonSetup        *pAdCommonSetup;

   /** pointer to Aif2 DMA DIO Engine setup */
   CSL_Aif2AdDioSetup              *pAdDioSetup;

   /** pointer to Aif2 Timer external and internal event  setup */
   CSL_Aif2AtEventSetup              *pAtEventSetup;

   /** pointer to Aif2 Timer common  setup */
   CSL_Aif2AtCommonSetup          *pAtCommonSetup;

} CSL_Aif2CommonSetup;

/**
 * @brief This is a sub-structure in @a CSL_Aif2HwSetup. This structure is used for
 * configuring the parameters of an outbound link */
typedef struct 
{
   /** Link index 0-5  */
   CSL_Aif2LinkIndex           linkIndex;

   /** pointer to Sd link setup */
   CSL_Aif2SdLinkSetup            *pSdLinkSetup;

   /** pointer to link common setup */
   CSL_Aif2CommonLinkSetup       *pComLinkSetup;

   /* pointer to RM link setup */
   CSL_Aif2RmLinkSetup           *pRmLinkSetup;

   /** pointer to TM setup */
   CSL_Aif2TmLinkSetup           *pTmLinkSetup;

    /** pointer to re-transmitter link setup */
   CSL_Aif2RtLinkSetup              *pRtLinkSetup;

   /** pointer to protocol encoder link setup */
   CSL_Aif2PeLinkSetup              *pPeLinkSetup;

   /** pointer to Protocol decoder link setup */
   CSL_Aif2PdLinkSetup              *pPdLinkSetup;

    /** pointer to Aif2 timer link setup (Pi, Delta, PE signal) */
   CSL_Aif2AtLinkSetup              *pAtLinkSetup;

} CSL_Aif2LinkSetup;


/** @brief This object contains the reference to the instance of AIF2 opened
 *  using the @a CSL_aif2Open().
 *
 *  The pointer to this, is passed to all AIF2 CSL APIs.
 */
typedef struct 
{
   /** This is a pointer to the registers of the AIF2 */
   CSL_Aif2RegsOvly         regs;
   
   /** This is the instance of AIF2 being referred to by this object  */
   CSL_InstNum             perNum;

   /** This is the dedicated link number for HW control and get HW status argument*/
   CSL_Aif2LinkIndex       arg_link;  /* 0 ~ 5 */

   /** This is the dedicated dio engine number for HW control and get HW status argument*/
   CSL_Aif2DioEngineIndex       arg_dioEngine;  /*0 ~ 2 */

   /** This is the dedicated ee function index for HW control and get HW status argument*/
   CSL_Aif2EeArgIndex        ee_arg;

} CSL_Aif2Obj;


/** @brief handle pointer to aif2 object
 **/
typedef CSL_Aif2Obj *CSL_Aif2Handle;


/** @brief This will have the base-address information for the peripheral
 *  instance
 */
typedef struct 
{
   /** This is a pointer to the registers of the AIF2 */
    CSL_Aif2RegsOvly   regs;

} CSL_Aif2BaseAddress;



/** @brief Module specific parameters. 
 */
typedef struct
{
   /** Bit mask to be used for selecting link specific parameters. For this 
    *  module, this is not used as there is only one module specific parameter. 
    *  So user need not worry about this.
    */
   CSL_BitMask8   flags;
    
   /**Global setup structure */
   CSL_Aif2GlobalSetup   gSetup;

} CSL_Aif2Param;



/** @brief This is the Setup structure for configuring AIF2 using @a CSL_aif2HwSetup()
 * function 
 */
typedef struct 
{
   /** Pointer to the global AIF2 setup structure */
   CSL_Aif2GlobalSetup         *globalSetup;
   
   /** Pointer specifying common setup structure */
   CSL_Aif2CommonSetup     *commonSetup;

   /** Pointer to the 6 link setup structure */
   CSL_Aif2LinkSetup            *linkSetup[6];
   
} CSL_Aif2Setup;



/**************************************************************************\
* AIF2 Data structures for HW Control
\**************************************************************************/

/**
 *
 * @brief RM force sync states
 *
 * Use this symbol to specify the state of the RM state machine
 * */
typedef enum 
{
   /** Selects the force RM state 0 */	
   CSL_AIF2_RM_FORCE_ST0 =  4,
   /** Selects the force RM state 1 */
   CSL_AIF2_RM_FORCE_ST1 =  5,
   /** Selects the force RM state 2 */
   CSL_AIF2_RM_FORCE_ST2 =  6,
   /** Selects the force RM state 3 */
   CSL_AIF2_RM_FORCE_ST3 =  7,
   /** Selects the force RM state 4 */
   CSL_AIF2_RM_FORCE_ST4 =  2,
   /** Selects the force RM state 5 */
   CSL_AIF2_RM_FORCE_ST5 =  3

} CSL_Aif2RmForceSyncState;


/** @brief This structure is used for DBMR dynamic configuring parameters of protocol encoder */
typedef struct
{
   /** TRUE for CPRI and FALSE for OBSAI DBMR setup */
   Bool                                       isCpri; 
   
   /** dedicated channel number for CPRI DBMr setup 0 ~ 5 */
   Uint8                                       CpriLinkNum;

   /** dedicated rule number for Obsai DBMR setup 0~ 63 */
   Uint8                                       RuleNum;
   
   /** Dual bit map structure for Pe dual bit map rule FSM */
   CSL_Aif2DualBitMap                  DualBitMap;
   
} CSL_Aif2PeDbmr;


/** @brief This structure is used for dynamic configuring the obsai header parameters of protocol encoder */
typedef struct
{

   /** dedicated channel number for this setup */
   Uint8                                       ChannelNum;
   /** PE DMA channel OBSAI time stamp value which is inserted into the frame */
   Uint8                                       PeChObsaiType;

    /** PE DMA channel OBSAI type value which is inserted into the frame */
   Uint8                                       PeChObsaiTs;

   /** PE DMA channel OBSAI address value which is inserted into the frame */
   Uint16                                       PeChObsaiAddr;

    /** PE DMA channel OBSAI time stamp mask value which is inserted into the frame */
   CSL_Aif2ObsaiTsMask                PeChObsaiTsMask;

   /** PE DMA channel OBSAI time stamp generation algorithm  */
   CSL_Aif2TstampFormat             PeChObsaiTsfomat;
   
} CSL_Aif2PeObsaiHeader;


/** @brief  This structure is used for dynamic configuring the Modulo rule parameters of protocol encoder */
typedef struct
{
    /** dedicated rule number for this setup */
   Uint16                               RuleNum;
	
    /** Modulo terminal count  structure */
   CSL_Aif2ModuloTc            PeModuloTc;

} CSL_Aif2PeModuloRule;


 /** @brief  This structure is used for dynamic configuring the channel parameters of protocol encoder */
typedef struct
{
    /** dedicated channel number for this setup */
   Uint8                                       ChannelNum;
	
   /**Enable axc channels one-by-one*/
   Bool                              bEnableAxC;

   /** PE channel configuration 0 */
   CSL_Aif2PeDmaCh0         PeDmaCh0;
   
   /** PE input fifo configuration  */
   CSL_Aif2PeInFifoControl         PeInFifo;
   
   /** PE AxC offset */
   Uint32                            AxCOffset;

} CSL_Aif2PeChannelConfig;


/** @brief  This structure is used for dynamic configuring the channel parameters of protocol encoder */
typedef struct
{
    /** dedicated rule number from 0 to 511 */
   Uint16                               RuleNum;

    /** dedicated lut number from 0 to 7 */
   Uint8                               LutNum;
	
   /** Primary, DMA channel number, LUT maps rule indexes to DMA channels */
   Uint8                               ChIndex;

   /** enable pe channel rule index */
   Bool                                bEnableChIndex;

   /** enable cpri packet mode for the rule */
   Bool                                bCpriPktEnable;

} CSL_Aif2PeChRuleLut;
  

/** @brief This structure is used for dynamic configuring the cpri Id LUT parameters of protocol decoder */
typedef struct
{
   /** dedicated channel number for this setup */
   Uint8                                       ChannelNum;

   /**DBMF CPRI Stream LUT: AxC:used to map DBM X count to DMA channel. PKT:2 lsb indicates 0-3 PKT packing circuit (assumed 4B/5B encoding)*/
   Uint8                                        CpriDmaCh;
   
   /** DBMF CPRI Stream LUT: enable-disable of channel, for each value of DBM X count.*/
   Bool                                        bEnableCpriX;

    /** DBMF CPRI Stream LUT: dicates the cpri payload is to be used as AxC (normal) or Packet traffic */
   Bool                                       bEnableCpriPkt;

   /** Fine AxC offset. Used in the front end of PD to align word data into QWords. bit [1:0] are offset into a QWord.
   bit[2] give RSA double QWork alignment. Bit[2] and corresponding axc_offset[0] should always be programmed to be identical*/
   Uint8                                       Cpri8WordOffset;
   
} CSL_Aif2PdCpriIdLut;


/** @brief This structure is used for dynamic configuring the cpri 256 control word LUT parameters of protocol decoder */
typedef struct
{
   /** dedicated channel number for this setup */
   Uint8                                       ChannelNum;

    /** All possible CPRI CW per hyperframe are are mapped to one of four(0~3) CPRI CW staging areas*/
   Uint8                                       CpriCwChannel;    

   /** All possible CPRI CW per hyperframe. Dicatates whether the control word should be captured at all*/
   Bool                                        bEnableCpriCw;

} CSL_Aif2CpriCwLut;


 /** @brief  This structure is used for dynamic configuring the channel parameters of protocol decoder */
typedef struct
{
    /** dedicated channel number for this setup */
   Uint8                                       ChannelNum;
	
   /** Pd route */
   CSL_Aif2PdRoute               PdRoute;
   
   /** Pd 128 Dma channel configuration */
   CSL_Aif2PdChConfig          PdChConfig;

   /*** OBSAI: Antenna Carrier offset programmed in 307.2MHz clocks and relative to the Frame Boundary of the RadT AT timer. 
          CPRI: Antenna Carrier Offset programmed in (non-oversampled) samples, relative to the link (PHY) frame boundary */
   Uint32                               AxCOffset;

   /** Pd 128 Dma channel configuration 1 */
   CSL_Aif2PdChConfig1          PdChConfig1;

   /** TDD symbol enable/disable from symbol 16 ~ 47  */
   Uint32                               TddEnable1;
   /** TDD symbol enable/disable from symbol 48 ~ 79  */
   Uint32                               TddEnable2;
   /** TDD symbol enable/disable from symbol 80 ~ 111  */
   Uint32                               TddEnable3;
   /** TDD symbol enable/disable from symbol 112 ~ 143  */
   Uint32                               TddEnable4;

   /** pd frame message terminal count */
   Uint16                              PdFrameMsgTc;

} CSL_Aif2PdChannelConfig;

 

/** @brief This object contains the aif2 DB side data information */
typedef struct 
{
   /** DirectIO Ram Buffer Write Enable */
   Bool                   bEnDioBufferWrite;

   /** DirectIO Ram Buffer Read Enable for Egress*/
   Bool                   bEnDioBufferRead;
   
    /** CPPI FIFO buffer Write Enable */
   Bool                   bEnFifoBufferWrite;
   
   /** Start of packet flag */
   Bool                   bSop;
   
  /** End of packet flag */
   Bool                   bEop;

   /** DMA channel number 127-0 */
   Uint8                   ChannelId;

   /** Address within a DirectIO Circular Buffer. Each address contains a quad-word and 16 locations */
   Uint8                   DioAddress;

   /** Transfer Byte Count: Indicates how many valid bytes are transferred in the current data phase. value should be within 0 ~ 16*/
   Uint8                   xcnt;

   /** AxC symbol number inserted as part of protocol specific data (0x00 - 0xFF) */
   Uint8                   Symbol;

} CSL_Aif2DbSideData;


/** @brief This object contains the aif2 Vc Emu control data information */
typedef struct 
{
   /** Aif2 Emulation Freerun Enable */
   Bool                   Freerun;
   
    /** Aif2 Emulation Soft Enable */
   Bool                   Soft;
   
   /** Aif2 Emulation mode RT selection enable */
   Bool                   RtSel;

} CSL_Aif2VcEmu;


/** @brief This object contains the aif2 EE Aif2 Error Interrupt data information */
typedef struct 
{
   /**  ee error interrupt */
   Bool                   Error_intr;
   /**  ee alarm interrupt */
   Bool                   Alarm_intr;
   /**  ee cppi dma  interrupt */
   Bool                   Cdma_intr;

} CSL_Aif2EeAif2Int;


/** @brief This object contains the aif2 EE DB Interrupt data information */
typedef struct 
{
   /**  ee db interrupt  db_ee_i_trc_ram_ovfl_err */
   Bool      db_ee_i_trc_ram_ovfl_err;
   /**  ee db interrupt  db_ee_i_token_ovfl_err */
   Bool      db_ee_i_token_ovfl_err;
   /**  ee db interrupt  db_ee_i_fifo_ovfl_err */
   Bool      db_ee_i_fifo_ovfl_err;
   /**  ee db interrupt  db_ee_i_pd2db_full_err */
   Bool      db_ee_i_pd2db_full_err;
   /**  ee db interrupt  db_ee_e_ps_axc_err */
   Bool      db_ee_e_ps_axc_err;
   /**  ee db interrupt  db_ee_e_cd_data_err */
   Bool      db_ee_e_cd_data_err;
   /**  ee db interrupt  db_ee_e_cd_data_type_err */
   Bool      db_ee_e_cd_data_type_err;

} CSL_Aif2EeDbInt;


/** @brief This object contains the aif2 EE AD Interrupt data information */
typedef struct 
{
   /** ee ad interrupt ad_ee_i_cd_data_err  */
   Bool      ad_ee_i_cd_data_err;
   /** ee ad interrupt ad_ee_e_cd_sch_err  */
   Bool      ad_ee_e_cd_sch_err;
   /** ee ad interrupt ad_ee_i_dma_0_err  */
   Bool      ad_ee_i_dma_0_err;
   /** ee ad interrupt ad_ee_i_dma_1_err  */
   Bool      ad_ee_i_dma_1_err;
   /** ee ad interrupt ad_ee_i_dma_2_err  */
   Bool      ad_ee_i_dma_2_err;
   /** ee ad interrupt ad_ee_e_dma_0_err  */
   Bool      ad_ee_e_dma_0_err;
   /** ee ad interrupt ad_ee_e_dma_1_err  */
   Bool      ad_ee_e_dma_1_err;
   /** ee ad interrupt ad_ee_e_dma_2_err  */
   Bool      ad_ee_e_dma_2_err;

} CSL_Aif2EeAdInt;


/** @brief This object contains the aif2 EE CD(PKTDMA module) Interrupt data information */
typedef struct 
{
   /** ee cppi dma interrupt  cd_ee_sop_desc_starve_err */
   Bool      cd_ee_sop_desc_starve_err;
   /** ee cppi dma interrupt  cd_ee_mop_desc_starve_err */
   Bool      cd_ee_mop_desc_starve_err;

} CSL_Aif2EeCdInt;


/** @brief This object contains the aif2 EE SD Interrupt data information */
typedef struct 
{
   /** ee serdes interrupt sd_ee_stspll_b4_err */
   Bool      sd_ee_stspll_b4_err;
   /** ee serdes interrupt sd_ee_stspll_b8_err */
   Bool      sd_ee_stspll_b8_err;

} CSL_Aif2EeSdInt;


/** @brief This object contains the aif2 EE VC Interrupt data information */
typedef struct 
{
   /** ee vc interrupt vc_ee_vbus_err */
   Bool      vc_ee_vbus_err;
  
} CSL_Aif2EeVcInt;


/** @brief This object contains the EE aif2 run control data information */
typedef struct 
{
   /** ee aif2 run control aif2_phy_run */
   Bool      aif2_phy_run;
   /** ee aif2 run control aif2_global_run */
   Bool      aif2_global_run;

} CSL_Aif2EeAif2Run;


/** @brief This object contains the aif2 EE Link A Interrupt data information */
typedef struct 
{
   /** ee link a interrupt  rm_ee_sync_status_change_err */
   Bool     rm_ee_sync_status_change_err;
   /** ee link a interrupt  rm_ee_num_los_det_err */
   Bool     rm_ee_num_los_det_err;
   /** ee link a interrupt  rm_ee_lcv_det_err */
   Bool     rm_ee_lcv_det_err;
   /** ee link a interrupt  rm_ee_frame_bndry_det_err */
   Bool     rm_ee_frame_bndry_det_err;
   /** ee link a interrupt  rm_ee_block_bndry_det_err */
   Bool     rm_ee_block_bndry_det_err;
   /** ee link a interrupt  rm_ee_missing_k28p5_err */
   Bool     rm_ee_missing_k28p5_err;
   /** ee link a interrupt  rm_ee_missing_k28p7_err */
   Bool     rm_ee_missing_k28p7_err;
   /** ee link a interrupt  rm_ee_k30p7_det_err */
   Bool     rm_ee_k30p7_det_err;
   /** ee link a interrupt  rm_ee_loc_det_err */
   Bool     rm_ee_loc_det_err;
   /** ee link a interrupt  rm_ee_rx_fifo_ovf_err */
   Bool     rm_ee_rx_fifo_ovf_err;
   /** ee link a interrupt  rm_ee_rcvd_los_err */
   Bool     rm_ee_rcvd_los_err;
   /** ee link a interrupt  rm_ee_rcvd_lof_err */
   Bool     rm_ee_rcvd_lof_err;
   /** ee link a interrupt  rm_ee_rcvd_rai_err */
   Bool     rm_ee_rcvd_rai_err;
   /** ee link a interrupt  rm_ee_rcvd_sdi_err */
   Bool     rm_ee_rcvd_sdi_err;
   /** ee link a interrupt  rm_ee_los_err */
   Bool     rm_ee_los_err;
   /** ee link a interrupt  rm_ee_lof_err */
   Bool     rm_ee_lof_err;
   /** ee link a interrupt  rm_ee_hfnsync_state_err */
   Bool     rm_ee_hfnsync_state_err;
   /** ee link a interrupt  rm_ee_lof_state_err */
   Bool     rm_ee_lof_state_err;
   /** ee link a interrupt  tm_ee_frm_misalign_err */
   Bool     tm_ee_frm_misalign_err;
   /** ee link a interrupt  tm_ee_fifo_starve_err */
   Bool     tm_ee_fifo_starve_err;

} CSL_Aif2EeLinkAInt;


/** @brief This object contains the aif2 EE Link B Interrupt data information */
typedef struct 
{
   /** ee link b interrupt  pd_ee_eop_err */
   Bool     pd_ee_eop_err;
    /** ee link b interrupt  pd_ee_crc_err */
   Bool     pd_ee_crc_err;
   /** ee link b interrupt  pd_ee_cpri_frame_err */
   Bool     pd_ee_cpri_frame_err;
   /** ee link b interrupt  pd_ee_axc_fail_err */
   Bool     pd_ee_axc_fail_err;
   /** ee link b interrupt   pd_ee_sop_err*/
   Bool     pd_ee_sop_err;
   /** ee link b interrupt  pd_ee_obsai_frm_err */
   Bool     pd_ee_obsai_frm_err;
   /** ee link b interrupt  pd_ee_wr2db_err */
   Bool     pd_ee_wr2db_err;
   /** ee link b interrupt   pe_ee_modrule_err*/
   Bool     pe_ee_modrule_err;
    /** ee link b interrupt   pe_ee_sym_err*/
   Bool     pe_ee_sym_err;
    /** ee link b interrupt   pe_ee_mf_fifo_overflow_err*/
   Bool     pe_ee_mf_fifo_overflow_err;
   /** ee link b interrupt   pe_ee_mf_fifo_underflow_err*/
   Bool     pe_ee_mf_fifo_underflow_err;
    /** ee link b interrupt   pe_ee_db_starve_err*/
   Bool     pe_ee_db_starve_err;
   /** ee link b interrupt   pe_ee_rt_if_err*/
   Bool     pe_ee_rt_if_err;
   /** ee link b interrupt   pe_ee_pkt_starve_err*/
   Bool     pe_ee_pkt_starve_err;
   /** ee link b interrupt  rt_ee_frm_err */
   Bool     rt_ee_frm_err;
   /** ee link b interrupt  rt_ee_ovfl_err */
   Bool     rt_ee_ovfl_err;
   /** ee link b interrupt  rt_ee_unfl_err */
   Bool     rt_ee_unfl_err;
   /** ee link b interrupt rt_ee_em_err  */
   Bool     rt_ee_em_err;
   /** ee link b interrupt  rt_ee_hdr_err */
   Bool     rt_ee_hdr_err;

} CSL_Aif2EeLinkBInt;


/** @brief This object contains the aif2 EE AT Interrupt data information */
typedef struct 
{
	/** ee at interrupt  at_ee_rp1_type_sys_rcvd_err */
	Bool      at_ee_rp1_type_sys_rcvd_err;
	/** ee at interrupt   at_ee_rp1_type_rp3_rcvd_err*/
	Bool      at_ee_rp1_type_rp3_rcvd_err;
	/** ee at interrupt   at_ee_rp1_type_tod_rcvd_err*/
	Bool      at_ee_rp1_type_tod_rcvd_err;
	/** ee at interrupt   at_ee_rp1_type_unsel_err*/
	Bool      at_ee_rp1_type_unsel_err;
	/** ee at interrupt   at_ee_rp1_type_spare_err*/
	Bool      at_ee_rp1_type_spare_err;
	/** ee at interrupt   at_ee_rp1_type_rsvd_err*/
	Bool      at_ee_rp1_type_rsvd_err;
	/** ee at interrupt   at_ee_rp1_bit_width_err*/
	Bool      at_ee_rp1_bit_width_err;
	/** ee at interrupt  at_ee_rp1_crc_err */
	Bool      at_ee_rp1_crc_err;
	/** ee at interrupt   at_ee_rp1_rp3_err*/
	Bool      at_ee_rp1_rp3_err;
	/** ee at interrupt   at_ee_rp1_sys_err*/
	Bool      at_ee_rp1_sys_err;
	/** ee at interrupt  at_ee_pi0_err */
	Bool      at_ee_pi0_err;
	/** ee at interrupt  at_ee_pi1_err */
	Bool      at_ee_pi1_err;
	/** ee at interrupt   at_ee_pi2_err*/
	Bool      at_ee_pi2_err;
	/** ee at interrupt   at_ee_pi3_err*/
	Bool      at_ee_pi3_err;
	/** ee at interrupt   at_ee_pi4_err*/
	Bool      at_ee_pi4_err;
	/** ee at interrupt   at_ee_pi5_err*/
	Bool      at_ee_pi5_err;
	/** ee at interrupt   at_ee_phyt_sync_err*/
	Bool      at_ee_phyt_sync_err;
	/** ee at interrupt   at_ee_radt_sync_err*/
	Bool      at_ee_radt_sync_err;

} CSL_Aif2EeAtInt;

/** @brief This object contains the aif2 EE PD Interrupt data information */
typedef struct 
{
	/** ee pd interrupt  pd_ee_ts_wdog_err  */
	Bool      pd_ee_ts_wdog_err;

} CSL_Aif2EePdInt;

/** @brief This object contains the aif2 EE PE Interrupt data information */
typedef struct 
{
	/** ee pe interrupt  pe_ee_rd2db_err  */
	Bool      pe_ee_rd2db_err;
	/** ee pe interrupt  pe_ee_token_req_ovfl_err  */
	Bool      pe_ee_token_req_ovfl_err;
	/** ee pe interrupt  pe_ee_token_wr_err  */
	Bool      pe_ee_token_wr_err;
	/** ee pe interrupt  pe_ee_dat_req_ovfl_err  */
	Bool      pe_ee_dat_req_ovfl_err;

} CSL_Aif2EePeInt;


/**************************************************************************\
* AIF2 Data structures for Get HW status
\**************************************************************************/

/** @brief This object contains the aif2 PID information */
typedef struct 
{
   /** Major revision (X) code */
   Uint8                   major;
   
   /** Custom version code  */
   Uint8                   custom;
   
   /** Minor revision (Y) code */
   Uint8                   minor;

   /** RTL version R code */
   Uint8                   RTL;

   /** function code */
   Uint16                   func;

   /** current scheme */
   Uint8                   scheme;

} CSL_Aif2PidStatus;


/** @brief This object contains the aif2 SERDES Rx  link status information */
typedef struct 
{
   /** If the alignment feature of the Ser-des is used by hardware, the receiver frame synchronizer must have knowledge 
   that each Ser-des port had completed a requested byte alignment so that the byte alignment control logic can operate. */
   Bool                   sdRxSync;
   
   /**The receiver frame synchronizer must have knowledge that each Ser-des port had detected a loss of signal condition 
   so that the receiver can suppress events due to a loss of frame synchronization  */
   Bool                   sdRxLosDetect;
   

   /**/
   Bool                   sdRxAdaptDone;


} CSL_Aif2SdRxStatus;


/** @brief This object contains the aif2 Rm link status0  information */
typedef struct 
{
   /** Indicates that status of the Frame Sync state machine */
   CSL_Aif2RmSyncState                   rmSyncStatus;
   
   /** Active when RX state machine is in ST0, inactive otherwise  */
   Bool                   rmLos;
   
   /** Detects when num_los counter has reached the programable los_det_thold limit  */
   Bool                   rmNumLosDetect;
   
   /** The clock watchdog circuit detected a missing clock */
   Bool                   rmLoc;

   /** Active after an RM FIFO overflow */
   Bool                   rmFifoOverflow;

} CSL_Aif2RmStatus0;


/** @brief This object contains the aif2 Rm link status1  information */
typedef struct 
{
   
   /** Represents the number of los detect */
   Uint16                  rmNumLos;
   
   /** Number of Line Code Violations counted since last cleared and enabled. Range 0 to 65,535 */
   Uint16                  rmLcvCountValue;

} CSL_Aif2RmStatus1;


/** @brief This object contains the aif2 Rm link status2  information */
typedef struct 
{
   
   /** A value that represents the quality, relative frequency, of the received Serdes clock. Range 0 to 65,535 */
   Uint16                  rmClockQuality;
   
   /** Indicates the captured scrambling code, only when configuration bit scr_en = 1. */
   Uint8                  rmScrValue;

} CSL_Aif2RmStatus2;


/** @brief This object contains the aif2 Rm link status3  information */
typedef struct 
{
   /** Received hyperframe number, Z.64.0. Range 0 to 149 basic frames */
   Uint8                   rmHfn;
   
   /** Received Node B Frame number low byte, Z.128.0  */
   Uint8                   rmBfnHigh;
   
   /** Received Node B Frame number high byte, Z.130.0*/
   Uint8                   rmBfnLow;
   
   /** Active high status indicates when the receiber FSM is in the HFSYNC state ST3  */
   Bool                   rmHfsyncState;

   /** Active high status indicates Loss Of Frame when the receiver FSM is in state ST0 or ST1 */
   Bool                   rmLofState;

} CSL_Aif2RmStatus3;


/** @brief This object contains the aif2 Rm link status4  information */
typedef struct 
{
   /** Received protocol version, Z.2.0 */
   Uint8                   rmL1Version;
   
   /** Received start up information, Z.66.0  */
   Uint8                   rmL1Startup;
   
   /** Received reset, Z.130.0, b0  */
   Bool                   rmL1RST;

   /** Received rai, Z.130.0, b1  */
   Bool                   rmL1RAI;

   /** Received sdi, Z.130.0, b2*/
   Bool                   rmL1SDI;

   /** Received los, Z.130.0, b3*/
   Bool                   rmL1LOS;

   /** Received lof, Z.130.0, b4  */
   Bool                   rmL1LOF;

   /** Received Pointer P */
   Bool                   rmL1PointerP;

} CSL_Aif2RmStatus4;


/** @brief This object contains the aif2 Tm link status information */
typedef struct 
{
   /** TM Fail condition  */
   Bool                   tmFail;
   
   /** Tx FIFO underflow  */
   Bool                   tmFifoUnderflow;
   
   /** CO Frame alignment mismatch from transmit FSM */
   Bool                   tmFrameMisalign;

   /** Indicates that status of the Frame Sync state machine */
   CSL_Aif2TmSyncState                   tmFrameStatus;


} CSL_Aif2TmStatus;


/** @brief This object contains the aif2 Rt header error status information */
typedef struct 
{
   /** Indicates a header error has occurred */
   Bool                   HeaderError;
   
   /** Indicates which dma channel shows the header error  */
   Uint8                  DmaChannel;
   
} CSL_Aif2RtHeaderStatus;


/** @brief This object contains the aif2 Rt link status information */
typedef struct 
{
   /** Indicates a header error has occurred */
   Bool                   rtHeaderError;
   
   /** Indicates an empty message was inserted  */
   Bool                   rtEmptyMessage;
   
   /** Indicates an Underflow of the FIFO has occurred*/
   Bool                   rtFifoUnderflow;

   /** Indicates an Overflow of the FIFO has occurred */
   Bool                   rtFifoOverflow;

   /** Indicates a frame error of the FIFO has occurred */
   Bool                   rtFrameError;


} CSL_Aif2RtStatus;


/** @brief This object contains the aif2 radt capture value information */
typedef struct 
{
   /** Capture RADT clock count upon a PHYT frame boundary */
   Uint32                   clock;
   
   /** Capture RADT symbol count upon a PHYT frame boundary   */
   Uint16                   symbol;
   
   /** Capture RADT frame count 5lsbs upon a PHYT frame boundary  */
   Uint8                     frame;

} CSL_Aif2AtCaptRadt;


/** @brief This object contains the aif2 wcdma count value information */
typedef struct 
{
   /** WCDMA chip value */
   Uint16                   chip;
   
   /** WCDMA slot value  */
   Uint8                   slot;
   
   /** WCDMA frame vlaue */
   Uint16                   frame;

} CSL_Aif2AtWcdmaCount;


/** @brief This object contains the aif2 EE error and alarm origination information */
typedef struct 
{
   /** EE origin lk_en_sts_a0 value */
   Bool    lk_en_sts_a0;
   /** EE origin lk_en_sts_b0 value */
   Bool    lk_en_sts_b0;
   /** EE origin lk_en_sts_a1 value */
   Bool    lk_en_sts_a1;
   /** EE origin lk_en_sts_b1 value */
   Bool    lk_en_sts_b1;
   /** EE origin lk_en_sts_a2 value */
   Bool    lk_en_sts_a2;
   /** EE origin lk_en_sts_b2 value */
   Bool    lk_en_sts_b2;
   /** EE origin lk_en_sts_a3 value */
   Bool    lk_en_sts_a3;
   /** EE origin lk_en_sts_b3 value */
   Bool    lk_en_sts_b3;
   /** EE origin lk_en_sts_a4 value */
   Bool    lk_en_sts_a4;
   /** EE origin lk_en_sts_b4 value */
   Bool    lk_en_sts_b4;
   /** EE origin lk_en_sts_a5 value */
   Bool    lk_en_sts_a5;
   /** EE origin lk_en_sts_b5 value */
   Bool    lk_en_sts_b5;
   /** EE origin at_en_sts value */
   Bool    at_en_sts;
   /** EE origin sd_en_sts value */
   Bool    sd_en_sts;
   /** EE origin db_en_sts value */
   Bool    db_en_sts;
   /** EE origin ad_en_sts value */
   Bool    ad_en_sts;
   /** EE origin cd_en_sts value */
   Bool    cd_en_sts;
   /** EE origin vc_en_sts value */
   Bool    vc_en_sts;

} CSL_Aif2EeOrigin;


/** @brief Aif2 context info is a pointer. 
 */
typedef void *CSL_Aif2Context;

/**
@} */

/**************************************************************************\
* AIF2 global function declarations
\**************************************************************************/

/** 
 * @ingroup CSL_AIF2_FUNCTION
 * @brief Peripheral specific initialization function.
 *
 * This is the peripheral specific intialization function. This function is
 * idempotent in that calling it many times is same as calling it once.
 * This function initializes the CSL data structures, and doesn't touches
 * the hardware.
 *
 * <b> Usage Constraints: </b>
 * This function should be called before using any of the CSL APIs in the AIF2
 * module.
 * 
 * @b Example:
 * @verbatim
 * ...
 * CSL_Aif2Context Aif2Context 
 * 
   if (CSL_SOK != CSL_aifInit(&AifContext) {
       return;
   }
   @endverbatim
 *
 *
 * @return returns the status of the operation
 *
 * @{ */

CSL_Status CSL_aif2Init(
   /** AIF2 specific context information
    */
   CSL_Aif2Context *pContext
   );


/** 
 * @ingroup CSL_AIF2_FUNCTION
 * @brief Opens the instance of AIF2 requested.
 *
 *  The open call sets up the data structures for the particular instance of
 *  AIF device. The device can be re-opened anytime after it has been normally
 *  closed if so required. The handle returned by this call is input as an
 *  essential argument for rest of the APIs described for this module.
 *
 *  <b> Usage Constraints: </b>
 *  AIF must be successfully initialized via @a CSL_AIFInit() before calling
 *  this function. Memory for the @a CSL_AifObj must be allocated outside
 *  this call. This object must be retained while usage of this peripheral.
 *
 *  @b Example:
 *  @verbatim

     CSL_AifObj     aifObj;
     CSL_Status     status;
     CSL_AifParam   aifParam;
     aifParam.linkIndex = CSL_AIF2_LINK0 ;
      ...
     hAif = CSL_aifOpen(&aifObj,
                        CSL_AIF,
                        &aifParam,
                        &status);
   @endverbatim
 *
 * @return returns a handle @a CSL_AifHandle to the requested instance of
 * Aif if the call is successful, otherwise, a @a NULL is returned.
 *
 * @{ */
CSL_Aif2Handle CSL_aif2Open (
   /** Pointer to the object that holds reference to the
    *  instance of AIF2 requested after the call
    */
   CSL_Aif2Obj         *paif2Obj,
   /** Instance of AIF2 to which a handle is requested
    */
   CSL_InstNum            aif2Num,
   /** Module specific parameters;
    */
   CSL_Aif2Param           *paif2Param,
   /** This returns the status (success/errors) of the call.
    * Could be 'NULL' if the user does not want status information.
    */
   CSL_Status             *pStatus
   );

/**  
 * @ingroup CSL_AIF2_FUNCTION
 * @brief Reset whole AIF2 module
 *
 *  The open reset whole AIF2 devices and MMRs
 *  The handle returned by this call is input as an
 *  essential argument for rest of the APIs described for this module.
 *
 *  <b> Usage Constraints: </b>
 *  AIF must be successfully initialized via @a CSL_AIF2Init(), CSL_AIF2Open() before calling
 *  this function. Memory for the @a CSL_Aif2Obj must be allocated outside
 *  this call. This object must be retained while usage of this peripheral.
 *
 *  @b Example:
 *  @verbatim

     CSL_Aif2Handle     haif2;
    
      ...
     status = CSL_aif2Reset(haif2);
     
   @endverbatim
 *
 * @return returns a handle @a CSL_Aif2Handle to the requested instance of
 * Aif2 if the call is successful, otherwise, a @a NULL is returned.
 *
 * @{ */
CSL_Status CSL_aif2Reset (
   /** Pointer to the object that holds reference to the
    *  instance of AIF2 requested after the call
    */
   CSL_Aif2Handle        pAif2Handle
   );


/**
 * @ingroup CSL_AIF2_FUNCTION
 *  The Close call releases the resources of the peripheral
 *
 *  <b> Usage Constraints: </b>
 *  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *  in that order before CSL_aif2Close() can be called.
 *
 *  @b Example:
 *  @verbatim

      CSL_Aif2Handle hAif2;
      ...
      CSL_aif2Close(hAif2);
    @endverbatim
 *
 * @return returns the status of the operation (see @a CSL_Status)
 * Status is:
 *    CSL_SOK, if close function succeeds.
 *    CSL_EAIF2_BADHANDLE, if the handle is not valid.
 *
 * @{ */
CSL_Status  CSL_aif2Close(
    /** Pointer to the object that holds reference to the
     *  instance of AIF  link requested after the CSL_aif2Open(...) call
    */
    CSL_Aif2Handle         haif2
);

/**
 * @ingroup CSL_AIF2_FUNCTION
 * This function initializes the device registers with
 * the appropriate values provided through the HwSetup Data structure.
 *
 * <b> Usage Constraints:</b>
 * Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 * in that order before CSL_aif2HwSetup() can be called. The user has to
 * allocate space for & fill in the main setup structure appropriately before
 * calling this function
 *
 * @b Example:
 * @verbatim
     CSL_AifHandle hAif2;
     CSL_Status status;
     CSL_Aif2HwSetup  Aif2Setup;
    CSL_Aif2HwGlobalStup  globalSetup = {?;
    CSL_Aif2HwCommonLinkSetup commonSetup = {?;
    CSL_Aif2HwLinkSetup linkSetup[0~5] = {?;
    
    Aif2Setup.globalSetup   = &globalSetup;
    Aif2Setup.commonSetup   = &commonSetup;
    Aif2Setup.linkSetup  = &linkSetup[0~5] ;
    
     ;
     status = CSL_aif2HwSetup (hAif2, &Aif2Setup);
   @endverbatim
 *
 * @return Returns the status of the setup operation (see @a CSL_Status)
 * Status is:
 * CSL_SOK - successful completion of the setup
 * CSL_EAIF2_INVALID_PARAMS - hwSetup structure is not initialized.
 * @{ */

 CSL_Status  CSL_aif2HwSetup(
    /** Pointer to the object that holds reference to the
     *  instance of AIF2 requested after the call
    */
    CSL_Aif2Handle             hAif2,
    /** Pointer to setup structure which contains the
     *  information to program AIF2 to a useful state
    */
    const CSL_Aif2Setup          *aif2Setup
);

/**
  * @ingroup CSL_AIF2_FUNCTION
  * @brief Controls AIF operation based on the control command
  * @{ */

CSL_Status  CSL_aif2HwControl(
   CSL_Aif2Handle                      hAif2,
   CSL_Aif2HwControlCmd                cmd,
   const void                          *arg
);

/**
@} */

/**
  * @ingroup CSL_AIF2_FUNCTION
  * @brief Get the status of different operations
  * @{ */

CSL_Status  CSL_aif2GetHwStatus(
   CSL_Aif2Handle                      hAif2,
   CSL_Aif2HwStatusQuery               Query,
   void                               *response
);
/**
@} */


#ifdef __cplusplus
}
#endif

#endif /* CSL_AIF2_H */


