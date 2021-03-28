/**
 *   @file  csl_tsip.h
 *
 *   @brief   
 *      This is the main header file for the TSIP Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2008-2015, Texas Instruments, Inc.
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

/** @defgroup CSL_TSIP_API TSIP
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This page describes the Functions, Data Structures, Enumerations and Macros
 * within TSIP module.
 *
 * The TSIP is a serial interface peripheral with timeslot data management and
 * an integrated DMA capability. The primary purpose of this peripheral is to
 * provide a glueless interface to common telecom serial data streams and
 * efficient internal routing of the data to designated memories in a multi-CPU
 * device.
 *
 * The TSIP provides 8 serial transmit pins and 8 serial receive pins that
 * connect directly to TEMUX devices. Internally the TSIP offers multiple
 * channels of timeslot data management and multichannel DMA capability that
 * allow individual timeslots to be selectively processed.
 *
 * The 3 TSIPs are controlled by 3 different LPSCs. TSIP0 is controlled by
 * LPSC10. TSIP1 is controlled by LPSC11. TSIP2 is controlled by LPSC12. This
 * is done so that TSIPs can be independently clock gated.
 *
 *
 * @subsection References
 *    -# CSL-001-DES, CSL 3.x Design Specification DocumentVersion 1.02
 *
 */
#ifndef CSL_TSIP_H
#define CSL_TSIP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_error.h>
#include <ti/csl/cslr_tsip.h>


/**
@defgroup CSL_TSIP_SYMBOL  TSIP Symbols Defined
@ingroup CSL_TSIP_API
*/
/**
@defgroup CSL_TSIP_DATASTRUCT  TSIP Data Structures
@ingroup CSL_TSIP_API
*/
/**
@defgroup CSL_TSIP_FUNCTION  TSIP Functions
@ingroup CSL_TSIP_API
*/
/**
@defgroup CSL_TSIP_ENUM  TSIP Enumerated Data Types
@ingroup CSL_TSIP_API
*/


/** @defgroup CSL_TSIP_BITMAP_SIZE Bitmap Size
 * @ingroup CSL_TSIP_SYMBOL
 *
 * @{ */
#define CSL_TSIP_BITMAP_SIZE                        64
/**
@} */


/**************************************************************************\
* TSIP global typedef declarations
\**************************************************************************/

/**
 * @defgroup CSL_TSIP_TESTMODE_ENUM Test Mode Selection
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Test mode selection on TSIP
 *
 * Use this symbol for selecting test mode
 * @{ */
typedef enum {
    /** Data loopback mode */
    CSL_TSIP_TESTMODE_DATA_LOOPBACK        = 0,
    /** Link loopback mode */
    CSL_TSIP_TESTMODE_LINK_LOOPBACK        = 1
} CSL_TsipTestModeSelect;
/**
@} */


/**
 * @defgroup CSL_TSIP_DATARATE_ENUM Data Rate
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Data Rate supported on TSIP
 *
 * Use this symbol for setting Data rate
 * @{ */
typedef enum {
    /** Data rate is 8 Mbps */
    CSL_TSIP_DATARATE_8M         = 0,
    /** Data rate is 16 Mbps */
    CSL_TSIP_DATARATE_16M        = 1,
    /** Data rate is 32 Mbps */
    CSL_TSIP_DATARATE_32M        = 2
} CSL_TsipDataRate;
/**
@} */

/**
 * @defgroup CSL_TSIP_PRI_ENUM Priority 0 to 7
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Priority 0 to 7
 *
 * Use this symbol for repereseting DMA priority
 * @{ */
typedef enum {
    /** Priority 0 */
    CSL_TSIP_PRI_0         = 0,
    /** Priority 1 */
    CSL_TSIP_PRI_1         = 1,
    /** Priority 2 */
    CSL_TSIP_PRI_2         = 2,
    /** Priority 3 */
    CSL_TSIP_PRI_3         = 3,
    /** Priority 4 */
    CSL_TSIP_PRI_4         = 4,
    /** Priority 5 */
    CSL_TSIP_PRI_5         = 5,
    /** Priority 6 */
    CSL_TSIP_PRI_6         = 6,
    /** Priority 7 */
    CSL_TSIP_PRI_7         = 7
} CSL_TsipPri;
/**
@} */


/**
 * @defgroup CSL_TSIP_CLKM_ENUM Clock mode options
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief TSIP clock mode options
 *
 * Use this symbol to set clock mode
 * @{ */
typedef enum {
    /** Double rate clock */
    CSL_TSIP_CLKM_DBL = 0,
    /** Single rate clock */
    CSL_TSIP_CLKM_SGL = 1
} CSL_TsipClkm;
/**
@} */


/**
 * @defgroup CSL_TSIP_FRAMECOUNT_ENUM Frame Count options
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief TSIP frame count options
 *
 * Use this symbol to represent frame count
 * @{ */
typedef enum {
    /** Frame Count is 0 */
    CSL_TSIP_FRAMECOUNT_1   = 0,
    /** Frame Count is 255 */
    CSL_TSIP_FRAMECOUNT_256 = 255
} CSL_TsipFramecount;
/**
@} */

/**
 * @defgroup CSL_TSIP_FRAMESIZE_ENUM Frame Size options
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief TSIP frame size options
 *
 * Use this symbol to represent frame size
 * @{ */
typedef enum {
    /** Frame size is 0 */
    CSL_TSIP_FRAMESIZE_1   = 0,
    /** Frame size is 128 */
    CSL_TSIP_FRAMESIZE_128 = 127
} CSL_TsipFramesize;
/**
@} */

/**
 * @defgroup CSL_TSIP_TIMESLOT_ENUM Timeslot Configuration options
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief TSIP timeslot configuration options
 *
 * Use this symbol to represent timeslot configuration
 * @{ */
typedef enum {
    /** Timeslot Disabled */
    CSL_TSIP_TIMESLOT_DISABLED   = 0,
    /** Linear */
    CSL_TSIP_TIMESLOT_LINEAR     = 1,
    /** u-law */
    CSL_TSIP_TIMESLOT_ULAW       = 2,
    /** a-law */
    CSL_TSIP_TIMESLOT_ALAW       = 3
} CSL_TsipTimeslot;
/**
@} */

/**
 * @defgroup CSL_TSIP_CLKSRC_ENUM Frame and Clock Source
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Clock Source.... A/B
 *
 * Use this symbol to select the clock source
 * @{ */
typedef enum {
    /** Clock and Frame sync Source A  */
    CSL_TSIP_CLKSRC_A      = 0,
    /** Clock and Frame sync Source B  */
    CSL_TSIP_CLKSRC_B      = 1
} CSL_TsipClkSrc;
/**
@} */

/**
 * @defgroup CSL_TSIP_CLKP_ENUM Data Clock Polarity
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Clock Polarity.... rising/falling
 *
 * Use this symbol to represent data/fsync clock polarity
 * @{ */
typedef enum {
    /** Rising Polarity  */
    CSL_TSIP_CLKP_RISING     = 0,
    /** Falling Polarity */
    CSL_TSIP_CLKP_FALLING    = 1
} CSL_TsipClkp;
/**
@} */

/**
 * @defgroup CSL_TSIP_ENDIAN_ENUM Endian Selection
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Endian Selection.... Little/Big
 *
 * Use this symbol to represent the endianness
 * @{ */
typedef enum {
    /** Little Endian */
    CSL_TSIP_ENDIAN_LITTLE    = 0,
    /** Big Endian */
    CSL_TSIP_ENDIAN_BIG       = 1
} CSL_TsipEndian;
/**
@} */

/**
 * @defgroup CSL_TSIP_FSYNCP_ENUM Frame Sync Polarity
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief TSIP Frame Sync Polarity
 *
 * Use this symbol to represent Frame Sync Polarity
 * This symbol is used on both RCV and XMT
 * @{ */
typedef enum {
    /** Active Low */
    CSL_TSIP_FSYNCP_ALOW     = 0,
    /** Active High */
    CSL_TSIP_FSYNCP_AHIGH    = 1
} CSL_TsipFsyncp;
/**
@} */


/**
 * @defgroup CSL_TSIP_DLY_ENUM Output Enanble Delay
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief TSIP Output Enanble Delay
 *
 * Use this symbol to represent Output Enanble Delay
 * This symbol is used on both RCV and XMT
 * @{ */
typedef enum {
    /** No Added Delay */
    CSL_TSIP_DLY_CTRL_DISABLE   = 0,
    /** Active High */
    CSL_TSIP_DLY_CTRL_ENABLE    = 1
} CSL_TsipDlyCtrl;
/**
@} */



/**
 * @defgroup CSL_TSIP_INT_ENUM Interrupt selection
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief TSIP Interrupt selection
 *
 * Use this symbol to set the interrupt selection time
 * This symbol could be used for both RCV and XMT
 * @{ */
typedef enum {
    /** Interrupt on Acknowledgement */
    CSL_TSIP_INT_ACK        = 0,
    /** Interrupt on Delay */
    CSL_TSIP_INT_DLY        = 1,
    /** Interrupt on either Acknowledgement or Delay */
    CSL_TSIP_INT_ACKORDLY   = 2,
    /** Interrupt on both Acknowledgement and Delay */
    CSL_TSIP_INT_ACKNDLY    = 3
} CSL_TsipInt;
/**
@} */

/**
 * @defgroup CSL_TSIP_XMTDIS_ENUM Transmit Output Disable
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Transmit Output Disable State
 *
 * Use this symbol to represent the transmit output disable state
 * @{ */
typedef enum {
    /** High Impedence */
    CSL_TSIP_XMTDIS_HIGHIMP    = 0,
    /** Driven Low */
    CSL_TSIP_XMTDIS_LOW        = 2,
    /** Driven HIGH */
    CSL_TSIP_XMTDIS_HIGH       = 3
} CSL_TsipXmtDis;
/**
@} */

/**
 * @defgroup CSL_TSIP_CLKD_ENUM Clock Mode
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Clock Redundancy selection source
 *
 * Use this symbol to set the CLKD for redundancy clock selection
 * @{ */
typedef enum {
    /** Redundant Clock Mode */
    CSL_TSIP_CLKD_REDUN    = 0,
    /** Dual Clock Mode */
    CSL_TSIP_CLKD_DUAL     = 1
} CSL_TsipClkd;
/**
@} */


/**
 * @defgroup CSL_TSIP_CHST_ENUM Channel Active Status
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Channel Status: inactive or a config or b config
 *
 * Use this symbol to represent the Channel Status
 * @{ */
typedef enum {
    /** Channel is Inactive */
    CSL_TSIP_CHST_INACTIVE        = 0,
    /** A Config/Bitmap is used */
    CSL_TSIP_CHST_AACTIVE         = 1,
    /** B Config/Bitmap is used */
    CSL_TSIP_CHST_BACTIVE         = 2
} CSL_TsipChst;
/**
@} */


/**
 * @defgroup CSL_TSIP_EMU_ENUM Emulation mode setting
 * @ingroup CSL_TSIP_ENUM
 *
 * @brief Emulation mode setting
 *
 * Use this symbol to set the Emulation Mode
 * @{ */
typedef enum {
    /** Emulation mode stop */
    CSL_TSIP_EMU_STOP             = 0,
    /** Emulation mode TX stop */
    CSL_TSIP_EMU_TX_STOP          = 1,
    /** Emulation free run mode */
    CSL_TSIP_EMU_FREERUN          = 2
} CSL_TsipEmu;
/**
@} */



/** @addtogroup CSL_TSIP_DATASTRUCT
 @{ */
 
/** @brief This is the handle to the TSIP instance */
typedef volatile CSL_TsipRegs*  CSL_TsipHandle;

/**
@}
*/

/* Device specific API which opens the TSIP instance and returns a handle used in all subsequent calls */
extern CSL_TsipHandle CSL_tsipOpen (Int32 instNum);

#ifdef __cplusplus
}
#endif

#endif

