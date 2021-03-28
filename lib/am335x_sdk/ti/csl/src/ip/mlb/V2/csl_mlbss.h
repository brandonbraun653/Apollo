/**
 * @file  csl_mlbss.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the Media Local Bus Sub-System (mlbss) CSL.
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2015, Texas Instruments, Inc.
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

#ifndef CSL_MLBSS_H_
#define CSL_MLBSS_H_

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/soc.h>
#include <ti/csl/cslr_mlb.h>

/** ===========================================================================
 *
 * @defgroup CSL_MLBSS_API Media Local Bus Sub-System (MLBSS)
 * @ingroup CSL_MLBSS_API
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 *
 * @subsection References
 *    -# List any references (ie. design specs) here
 * ============================================================================
 */
/**
@defgroup CSL_MLBSS_SYMBOL  MLBSS Symbols Defined
@ingroup CSL_MLBSS_API
*/
/**
@defgroup CSL_MLBSS_DATASTRUCT  MLBSS Data Structures
@ingroup CSL_MLBSS_API
*/
/**
@defgroup CSL_MLBSS_FUNCTION  MLBSS Functions
@ingroup CSL_MLBSS_API
*/
/**
@defgroup CSL_MLBSS_ENUM MLBSS Enumerated Data Types
@ingroup CSL_MLBSS_API
*/

/** @addtogroup CSL_MLBSS_SYMBOL
@{ */

//=============================================================================
//  defines
//=============================================================================
/** @brief Pointers to registers */
#define pMlbSsRegs          ((CSL_mlbssRegs *)(CSL_MLBSS_CFG_REGS + 0x00000000))
#define pMlbDimRegs         ((CSL_mlbdimRegs *)(CSL_MLBSS_CFG_REGS + 0x00000800))
#define pMlbRatRegs         ((CSL_KSBUS_RATRegs *)(CSL_MLBSS_CFG_REGS + 0x00001000))

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_MLBSS_ENUM
    @{
 * ============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the pin modes for the MLB interface
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** 3-pin mode */
    CSL_MLBSS_MLB_PIN_MODE_3 = 0,
    /** 6-pin mode */
    CSL_MLBSS_MLB_PIN_MODE_6
} CSL_MLBSS_MLB_PIN_MODE_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the clock speeds for the MLB interface
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /**  256xFs (for 3-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_256X = 0,
    /**  512xFs (for 3-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_512X,
    /** 1024xFs (for 3-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_1024X,
    /** 2048xFs (for 6-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_2048X,
    /** 3072xFs (for 6-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_3072X,
    /** 4096xFs (for 6-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_4096X,
    /** 6144xFs (for 6-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_6144X,
    /** 8192xFs (for 6-pin mode) */
    CSL_MLBSS_MLB_CLK_SPEED_8192X,
    CSL_MLBSS_MLB_CLK_SPEED_MAX
} CSL_MLBSS_MLB_CLK_SPEED_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the packet modes for the AHB interface
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** A single packet within each ping-pong buffer */
    CSL_MLBSS_AHB_PKT_MODE_SINGLE = 0,
    /** Multiple packets possible within each ping-pong buffer */
    CSL_MLBSS_AHB_PKT_MODE_MULTIPLE
} CSL_MLBSS_AHB_PKT_MODE_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the DMA modes for the AHB interface
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** DMA mode 0 */
    CSL_MLBSS_AHB_DMA_MODE_0 = 0,
    /** DMA mode 1 */
    CSL_MLBSS_AHB_DMA_MODE_1
} CSL_MLBSS_AHB_DMA_MODE_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the channel types
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** Synchronous     */
    CSL_MLBSS_CHN_TYPE_SYNC = 0,
    /** Control         */
    CSL_MLBSS_CHN_TYPE_CTL,
    /** Asynchronous    */
    CSL_MLBSS_CHN_TYPE_ASYNC,
    /** Isochronous     */
    CSL_MLBSS_CHN_TYPE_ISO,
    CSL_MLBSS_CHN_TYPE_MAX
} CSL_MLBSS_CHN_TYPE_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the channel directions (from the system
 *          memory point of view)
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** Receive  */
    CSL_MLBSS_CHN_DIR_RX = 0,
    /** Transmit */
    CSL_MLBSS_CHN_DIR_TX
} CSL_MLBSS_CHN_DIR_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the number of frames per sub-buffer for
 *          synchronous channel types
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /**  1 frame  per sub-buffer */
    CSL_MLBSS_SYNC_FCNT_1 = 0,
    /**  2 frames per sub-buffer */
    CSL_MLBSS_SYNC_FCNT_2,
    /**  4 frames per sub-buffer */
    CSL_MLBSS_SYNC_FCNT_4,
    /**  8 frames per sub-buffer */
    CSL_MLBSS_SYNC_FCNT_8,
    /** 16 frames per sub-buffer */
    CSL_MLBSS_SYNC_FCNT_16,
    /** 32 frames per sub-buffer */
    CSL_MLBSS_SYNC_FCNT_32,
    /** 64 frames per sub-buffer */
    CSL_MLBSS_SYNC_FCNT_64,
    CSL_MLBSS_SYNC_FCNT_MAX
} CSL_MLBSS_SYNC_FCNT_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the buffer pages in the system memory
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** Ping buffer */
    CSL_MLBSS_BUFF_PAGE_PING = 0,
    /** Pong buffer */
    CSL_MLBSS_BUFF_PAGE_PONG
} CSL_MLBSS_BUFF_PAGE_E;

/** ---------------------------------------------------------------------------
 * @brief   This enumerator defines the possible MLB events
 *
 * ----------------------------------------------------------------------------
 */
typedef enum {
    /** Isochronous Rx protocol error   */
    CSL_MLBSS_MLB_INT_ISO_RX_PROTOCOL_ERR = 0,
    /** Isochronous Rx buffer overflow  */
    CSL_MLBSS_MLB_INT_ISO_RX_OVERFLOW,
    /** Synchronous protocol error      */
    CSL_MLBSS_MLB_INT_SYNC_PROTOCOL_ERR = 16,
    /** Asynchronous Rx packet done     */
    CSL_MLBSS_MLB_INT_ASYNC_RX_PKT_DONE,
    /** Asynchronous Rx protocol error  */
    CSL_MLBSS_MLB_INT_ASYNC_RX_PROTOCOL_ERR,
    /** Asynchronous Rx break           */
    CSL_MLBSS_MLB_INT_ASYNC_RX_BREAK,
    /** Asynchronous Tx packet done     */
    CSL_MLBSS_MLB_INT_ASYNC_TX_PKT_DONE,
    /** Asynchronous Tx protocol error  */
    CSL_MLBSS_MLB_INT_ASYNC_TX_PROTOCOL_ERR,
    /** Asynchronous Tx break           */
    CSL_MLBSS_MLB_INT_ASYNC_TX_BREAK,
    /** Control Rx packet done          */
    CSL_MLBSS_MLB_INT_CTL_RX_PKT_DONE = 24,
    /** Control Rx protocol error       */
    CSL_MLBSS_MLB_INT_CTL_RX_PROTOCOL_ERR,
    /** Control Rx break                */
    CSL_MLBSS_MLB_INT_CTL_RX_BREAK,
    /** Control Tx packet done          */
    CSL_MLBSS_MLB_INT_CTL_TX_PKT_DONE,
    /** Control Tx protocol error       */
    CSL_MLBSS_MLB_INT_CTL_TX_PROTOCOL_ERR,
    /** Control Tx break                */
    CSL_MLBSS_MLB_INT_CTL_TX_BREAK,
    CSL_MLBSS_MLB_INT_MAX
} CSL_MLBSS_MLB_INT_E;

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_MLBSS_DATASTRUCT
    @{
 * ============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains configuration information for the mlb
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /** Number of frames per sub-buffer for synchronous channels */
    CSL_MLBSS_SYNC_FCNT_E       SyncFrameCnt;
    /** Interface pin mode (3 or 6 pins) (see <MLBSS_MLB_PIN_MODE_E>) */
    CSL_MLBSS_MLB_PIN_MODE_E    PinMode;
    /** Interface clock speed (multiplier of clock frequency) (see <MLBSS_MLB_CLK_SPEED_E>) */
    CSL_MLBSS_MLB_CLK_SPEED_E   ClkSpeed;
    /** Single or multiple packet mode (see <MLBSS_AHB_PKT_MODE_E>) */
    CSL_MLBSS_AHB_PKT_MODE_E    AhbPktMode;
    /** AHB DMA mode 0 or 1 (see <MLBSS_AHB_DMA_MODE_E>) */
    CSL_MLBSS_AHB_DMA_MODE_E    AhbDmaMode;
    /** AHB interrupt mux enable */
    bool                        bAhbIntMux;
    /** Software clear interrupt enable */
    bool                        bAhbSwClrInt;
    /** Control Tx packet retry. When true, a control packet that is flagged with a Break or ProtocolError by the receiver is retransmitted */
    bool                        bCtlRtry;
    /** Asynchronous Tx packet retry. When true, an asynchronous packet that is flagged with a Break or ProtocolError by the receiver is retransmitted */
    bool                        bAsyRetry;
    /** When true, the MLB responds with a device present, request service system response if a matching channel scan system command is detected. When false, the MLB responds with a device present system response. */
    bool                        bServiceReqEnable;
    /** Clock hysteresis enable (for MediaLB 6-pin interface) */
    bool                        bHysteresisEnable;
    /** Clock receiver bias control (for MediaLB 6-pin interface) */
    unsigned                    ClkRxBiasCtl;
    /** Signal/Data transmitter bias control  (for MediaLB 6-pin interface) */
    unsigned                    SigDataTxBiasCtl;
    /** Signal/Data receiver bias control (for MediaLB 6-pin interface) */
    unsigned                    SigDataRxBiasCtl;
} CSL_MLBSS_MLB_CFG_T;

/** ---------------------------------------------------------------------------
 * @brief   This structure contains configuration information for the mlbss
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /** false=clock stop will wait for internal processes to complete, true=clock stop fast ack enable */
    bool                    bEnableFastClkStop;
    /** VBUSP priority (0-7, 0 is the highest) for DMA transfers */
    unsigned                DmaVbusPriority;
} CSL_MLBSS_CFG_T;

/** @} */

/** @addtogroup CSL_MLBSS_FUNCTION
@{ */

/** @} */

#endif
