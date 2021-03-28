//*****************************************************************************
//  Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//      Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//      Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the
//      distribution.
//
//      Neither the name of Texas Instruments Incorporated nor the names of
//      its contributors may be used to endorse or promote products derived
//      from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*****************************************************************************

//*****************************************************************************
//  File: csl_test_mlbss.h
//      This is the include file for the CSL test layer for the Media Local Bus
//      SubSystemm (mlbss) module.
//
//  Designer: Bill Egr, begr@ti.com, 214-567-5819
//
//  Revision History:
//      21Jul15 0.0.1 - Initial version written
//*****************************************************************************
#ifndef _CSL_TEST_MLBSS_H_
#define _CSL_TEST_MLBSS_H_

#include <ti/csl/csl_mlb.h>          // Required for CSL_MLBSS_CFG_T and CSL_MLBSS_MLB_CFG_T structure typedefs

#ifdef __cplusplus
extern "C" {
#endif

//=============================================================================
//  defines
//=============================================================================
#define MLBSS_MAX_CHNS          (64)                    // Maximum number of channels supported
#define CTR_CDT_BASE            (0x0)                   // CTR address of start of CDT area
#define CTR_ADT_BASE            (0x40)                  // CTR address of start of ADT area
#define CTR_CDT_ADDR(lcn)       (CTR_CDT_BASE+(lcn))    // Convert Logical Channel Number to CTR CDT entry number
#define CTR_ADT_ADDR(lcn)       (CTR_ADT_BASE+(lcn))    // Convert Logical Channel Number to CTR ADT entry number
#define CSL_MLBSS_DECODE_SYNC_FCNT_E(v) (1u<<(v))       // Decodes a MLBSS_SYNC_FCNT_E enumerated value into an integer value


//=============================================================================
//  typedefs
//=============================================================================

//-----------------------------------------------------------------------------
//  Enum: MLBSS_CHN_TYPE_E
//
//  This enumerator defines the channel types:
//
//  MLBSS_CHN_TYPE_SYNC     - (0) Synchronous
//  MLBSS_CHN_TYPE_CTL      - (1) Control
//  MLBSS_CHN_TYPE_ASYNC    - (2) Asynchronous
//  MLBSS_CHN_TYPE_ISO      - (3) Isochronous
//-----------------------------------------------------------------------------
typedef enum {
    MLBSS_CHN_TYPE_SYNC,
    MLBSS_CHN_TYPE_CTL,
    MLBSS_CHN_TYPE_ASYNC,
    MLBSS_CHN_TYPE_ISO,
    MLBSS_CHN_TYPE_MAX
} MLBSS_CHN_TYPE_E;

//-----------------------------------------------------------------------------
//  Enum: MLBSS_CHN_DIR_E
//
//  This enumerator defines the channel directions (from the system memory
//  point of view):
//
//  MLBSS_CHN_DIR_RX        - (0) Receive
//  MLBSS_CHN_DIR_TX        - (1) Transmit
//-----------------------------------------------------------------------------
typedef enum {
    MLBSS_CHN_DIR_RX,
    MLBSS_CHN_DIR_TX
} MLBSS_CHN_DIR_E;

//-----------------------------------------------------------------------------
//  Enum: MLBSS_SYNC_FCNT_E
//
//  This enumerator defines the number of frames per sub-buffer for synchronous
//  channel types:
//
//  MLBSS_SYNC_FCNT_1       - (0)  1 frame  per sub-buffer
//  MLBSS_SYNC_FCNT_2       - (1)  2 frames per sub-buffer
//  MLBSS_SYNC_FCNT_4       - (2)  4 frames per sub-buffer
//  MLBSS_SYNC_FCNT_8       - (3)  8 frames per sub-buffer
//  MLBSS_SYNC_FCNT_16      - (4) 16 frames per sub-buffer
//  MLBSS_SYNC_FCNT_32      - (5) 32 frames per sub-buffer
//  MLBSS_SYNC_FCNT_64      - (6) 64 frames per sub-buffer
//-----------------------------------------------------------------------------
typedef enum {
    MLBSS_SYNC_FCNT_1,
    MLBSS_SYNC_FCNT_2,
    MLBSS_SYNC_FCNT_4,
    MLBSS_SYNC_FCNT_8,
    MLBSS_SYNC_FCNT_16,
    MLBSS_SYNC_FCNT_32,
    MLBSS_SYNC_FCNT_64,
    MLBSS_SYNC_FCNT_MAX
} MLBSS_SYNC_FCNT_E;

#define MLBSS_DECODE_SYNC_FCNT_E(v) (1u<<(v))       // Decodes a MLBSS_SYNC_FCNT_E enumerated value into an integer value

//-----------------------------------------------------------------------------
//  Enum: MLBSS_BUFF_PAGE_E
//
//  This enumerator defines the buffer pages in the system memory:
//
//  MLBSS_BUFF_PAGE_PING    - (0) Ping buffer
//  MLBSS_BUFF_PAGE_PONG    - (1) Pong buffer
//-----------------------------------------------------------------------------
typedef enum {
    MLBSS_BUFF_PAGE_PING,
    MLBSS_BUFF_PAGE_PONG
} MLBSS_BUFF_PAGE_E;

//-----------------------------------------------------------------------------
//  Enum: MLBSS_MLB_EVENT_E
//
//  This enumerator defines the possible MLB events
//
//  MLBSS_MLB_EVENT_ISO_RX_PROTOCOL_ERR         - ( 0) Isochronous Rx protocol error
//  MLBSS_MLB_EVENT_ISO_RX_OVERFLOW             - ( 1) Isochronous Rx buffer overflow
//  MLBSS_MLB_EVENT_SYNC_PROTOCOL_ERR           - (16) Synchronous protocol error
//  MLBSS_MLB_EVENT_ASYNC_RX_PKT_DONE           - (17) Asynchronous Rx packet done
//  MLBSS_MLB_EVENT_ASYNC_RX_PROTOCOL_ERR       - (18) Asynchronous Rx protocol error
//  MLBSS_MLB_EVENT_ASYNC_RX_BREAK              - (19) Asynchronous Rx break
//  MLBSS_MLB_EVENT_ASYNC_TX_PKT_DONE           - (20) Asynchronous Tx packet done
//  MLBSS_MLB_EVENT_ASYNC_TX_PROTOCOL_ERR       - (21) Asynchronous Tx protocol error
//  MLBSS_MLB_EVENT_ASYNC_TX_BREAK              - (22) Asynchronous Tx break
//  MLBSS_MLB_EVENT_CTL_RX_PKT_DONE             - (24) Control Rx packet done
//  MLBSS_MLB_EVENT_CTL_RX_PROTOCOL_ERR         - (25) Control Rx protocol error
//  MLBSS_MLB_EVENT_CTL_RX_BREAK                - (26) Control Rx break
//  MLBSS_MLB_EVENT_CTL_TX_PKT_DONE             - (27) Control Tx packet done
//  MLBSS_MLB_EVENT_CTL_TX_PROTOCOL_ERR         - (28) Control Tx protocol error
//  MLBSS_MLB_EVENT_CTL_TX_BREAK                - (29) Control Tx break
//-----------------------------------------------------------------------------
typedef enum {
    MLBSS_MLB_EVENT_ISO_RX_PROTOCOL_ERR,
    MLBSS_MLB_EVENT_ISO_RX_OVERFLOW,
    MLBSS_MLB_EVENT_SYNC_PROTOCOL_ERR = 16,
    MLBSS_MLB_EVENT_ASYNC_RX_PKT_DONE,
    MLBSS_MLB_EVENT_ASYNC_RX_PROTOCOL_ERR,
    MLBSS_MLB_EVENT_ASYNC_RX_BREAK,
    MLBSS_MLB_EVENT_ASYNC_TX_PKT_DONE,
    MLBSS_MLB_EVENT_ASYNC_TX_PROTOCOL_ERR,
    MLBSS_MLB_EVENT_ASYNC_TX_BREAK,
    MLBSS_MLB_EVENT_CTL_RX_PKT_DONE = 24,
    MLBSS_MLB_EVENT_CTL_RX_PROTOCOL_ERR,
    MLBSS_MLB_EVENT_CTL_RX_BREAK,
    MLBSS_MLB_EVENT_CTL_TX_PKT_DONE,
    MLBSS_MLB_EVENT_CTL_TX_PROTOCOL_ERR,
    MLBSS_MLB_EVENT_CTL_TX_BREAK,
    MLBSS_MLB_EVENT_MAX
} MLBSS_MLB_EVENT_E;

//-----------------------------------------------------------------------------
//  Struct: MLBSS_CHN_SYS_BUFF_T
//
//  This structure contains information about the ping/pong channel buffers
//  located in SoC system memory.
//
//  uint64_t BuffAddr[2];       - A 2-element array (ping/pong) containing the system base address of the buffer
//  unsigned BuffDepth[2];      - A 2-element array (ping/pong) containing the buffer size in bytes
//  bool     bLittleEndian;     - AHB data ordering within the buffer: false=big-endian, true=little-endian
//-----------------------------------------------------------------------------
typedef struct
{
    uint64_t                BuffAddr[2];
    unsigned                BuffDepth[2];
    bool                    bLittleEndian;
} MLBSS_CHN_SYS_BUFF_T;

//-----------------------------------------------------------------------------
//  Struct: MLBSS_CHN_CFG_SYNC_T
//
//  This structure contains configuration information for a synchronous channel.
//
//  unsigned SysNumSubBuffs;    - Number of sub-buffers in system memory. Note that NumSubBuffs
//                                in the DBR is hardcoded to 4.
//  unsigned BytesPerFrame;     - The number of bytes per frame
//-----------------------------------------------------------------------------
typedef struct
{
    unsigned                SysNumSubBuffs;
    unsigned                BytesPerFrame;
} MLBSS_CHN_CFG_SYNC_T;

//-----------------------------------------------------------------------------
//  Struct: MLBSS_CHN_CFG_ISO_T
//
//  This structure contains configuration information for an isochronous channel.
//
//  unsigned BlockSizeBytes;      - Block size in bytes
//  unsigned DbrNumBlocks;        - Number of blocks in the DBR buffer; must be >=3
//  unsigned SysNumBlocks;        - Number of blocks in the system memory buffer
//  bool     bFlowCtlEnable;      - Flow control enable
//-----------------------------------------------------------------------------
typedef struct
{
    unsigned                BlockSizeBytes;
    unsigned                DbrNumBlocks;
    unsigned                SysNumBlocks;
    bool                    bFlowCtlEnable;
} MLBSS_CHN_CFG_ISO_T;

//-----------------------------------------------------------------------------
//  Struct: MLBSS_CHN_CFG_ASYNC_T
//
//  This structure contains configuration information for an asynchronous channel.
//
//  unsigned BuffDepthBytes;      - Buffer depth in bytes; must be >= max packet size
//-----------------------------------------------------------------------------
typedef struct
{
    unsigned                BuffDepthBytes;
} MLBSS_CHN_CFG_ASYNC_T;

//-----------------------------------------------------------------------------
//  Struct: MLBSS_CHN_CFG_CTL_T
//
//  This structure contains configuration information for a control channel.
//
//  unsigned BuffDepthBytes;      - Buffer depth in bytes; must be >= max packet size
//-----------------------------------------------------------------------------
typedef struct
{
    unsigned                BuffDepthBytes;
} MLBSS_CHN_CFG_CTL_T;

//-----------------------------------------------------------------------------
//  Struct: MLBSS_CHN_CFG_T
//
//  This structure contains configuration information for a logical channel.
//
//  MLBSS_CHN_TYPE_E     Type;       - Channel type (see <MLBSS_CHN_TYPE_E>)
//  MLBSS_CHN_DIR_E      Dir;        - Channel direction (see <MLBSS_CHN_DIR_E>)
//  bool                 bEnableInt; - Enable AHB interrupt for this channel?
//  void                 *pChnCfg;   - Void pointer to a channel-specific
//      configuation information structure (<MLBSS_CHN_CFG_SYNC_T>,
//      <MLBSS_CHN_CFG_ISO_T>, <MLBSS_CHN_CFG_ASYNC_T>, or <MLBSS_CHN_CFG_CTL_T>)
//  MLBSS_CHN_SYS_BUFF_T *pSysBuff;  - Pointer to a <MLBSS_CHN_SYS_BUFF_T>
//      structure containing ping-pong system buffer information
//-----------------------------------------------------------------------------
typedef struct
{
    MLBSS_CHN_TYPE_E        Type;
    MLBSS_CHN_DIR_E         Dir;
    bool                    bEnableInt;
    void                    *pChnCfg;
    MLBSS_CHN_SYS_BUFF_T    *pSysBuff;
} MLBSS_CHN_CFG_T;

//-----------------------------------------------------------------------------
//  Struct: MLBSS_CHN_BUFF_STATUS_T
//
//  This structure contains buffer status information for a logical channel.
//
//  bool bBuffRdy;        - Status indicating that buffer is ready for transmit
//  bool bBuffDone;       - Status indicating an AHB error response detected in this buffer
//  bool bErr;            - Status (ping/pong) indicating that buffer is done for receive
//  bool bPktStart;       - Status indicating a packet start (valid only for ctl and async channels)
//  bool bMEP;            - Status indicating a MOST Ethernet Packet (MEP) (valid only for the first page of a segmented buffer; valid only for async channels)
//-----------------------------------------------------------------------------
typedef struct
{
    bool                    bBuffRdy;
    bool                    bBuffDone;
    bool                    bErr;
    bool                    bPktStart;
    bool                    bMEP;
} MLBSS_CHN_BUFF_STATUS_T;

//=============================================================================
//  mlbss top-level API functions
//=============================================================================

//-----------------------------------------------------------------------------
//  Function: mlbss_initCsl
//      This function initializes the mlbss CSL-F. It must be called prior to calling
//      any other mlbss CSL-F function and must be called after a software reset is
//      issued. The following operations are performed...
//
//      1. Sets the base address of the module's register set (see <mlbss_setBaseAddr>)
//
//      2. All internal tracking mechanisms are cleared to their default values
//
//  Parameters:
//      BaseAddr    - VBUSP base address of mlbss IP
//
//  Returns:
//      0       - Success
//      1       - An unexpected error was encountered
//
//  See Also:
//      <CSL_MLBSS_CFG_T>, <CSL_MLBSS_MLB_CFG_T>
//-----------------------------------------------------------------------------
extern int mlbss_initCsl( uint64_t BaseAddr );

//-----------------------------------------------------------------------------
//  Function: mlbss_config
//      This function configures the mlbss. It must be called prior to calling
//      any other mlbss CSL-F function. The following operations are performed...
//
//      1. Wait for ECC initialization of the DIM rams to complete (see <mlbss_ssIsInitInProgress>)
//
//      2. The CTR RAM is cleared (see <mlbss_mifClrCtr>)
//
//      3. The module subsystem is initialized (see <mlbss_ssCfg>)
//
//      4. The MLB (Media Local Bus) is initialized (see <mlbss_mlbCfg>)
//
//      5. The AHB (AMBA AHB bus support) is initialized (see <mlbss_ahbCfg>)
//
//  Parameters:
//      pMlbSsCfg   - A pointer to a <CSL_MLBSS_CFG_T> structure that contains mlbss
//                    configuration information
//      pMlbCoreCfg - A pointer to a <CSL_MLBSS_MLB_CFG_T> structure that contains mlb
//                    core configuration information
//
//  Returns:
//      0       - Success
//      1       - An error was detected in one or more elements in the
//                passed structures
//
//  See Also:
//      <CSL_MLBSS_CFG_T>, <CSL_MLBSS_MLB_CFG_T>
//-----------------------------------------------------------------------------
extern int mlbss_config( CSL_MLBSS_CFG_T *pMlbSsCfg, CSL_MLBSS_MLB_CFG_T *pMlbCoreCfg );

//-----------------------------------------------------------------------------
//  Function: mlbss_addChannel
//      This function is used to add a logical channel into the mlbss. The following operations are performed...
//
//      1. Program the Channel Descriptor Table (CDT) (see <mlbss_configCdt>)
//
//      2. Program the Channel Allocation Table (CAT) for the inbound DMA into the DBR (see <mlbss_configCat>)
//
//      3. Program the Channel Allocation Table (CAT) for the outbound DMA into the DBR (see <mlbss_configCat>)
//
//      4. Program the AMBA AHB block ping/pong pages (see <mlbss_configAdt>)
//
//      5. Configure the Region Address Translation (RAT) (see <mlbss_addRatRegion>)
//
//      6. Configure interrupts (see <mlbss_ahbIntEnable> and mlbss_hbiIntEnable)
//
//  Parameters:
//      LogChnNum   - The logical channel number (0..63)
//      pChn        - A pointer to a <MLBSS_CHN_CFG_T> structure that contains channel configuration information
//
//  Returns:
//      0       - Success
//      1       - LogChnNum is out of range
//      2       - Channel associated with LogChnNum had already been added
//      3       - pChn is NULL
//      4       - Error in DBR buffer parameters for this channel type
//      5       - Insufficient buffer space available in the DBR for this channel's buffer requirements
//
//  See Also:
//      <MLBSS_CHN_CFG_T>
//-----------------------------------------------------------------------------
extern int mlbss_addChannel( unsigned LogChnNum, MLBSS_CHN_CFG_T *pChn );

//-----------------------------------------------------------------------------
//  Function: mlbss_enableChannel
//      This function is used to enable or disable a channel that has been previously
//      added. This function also insures that if one or more channels are enabled, then
//      the mlb and hbi are enabled as well. Similarly, if there are no channels enabled,
//      then this function will disable to mlb and hbi interfaces.
//
//  Parameters:
//      LogChnNum   - The logical channel number (0..63)
//      bEnable     - If true, the channel is enabled. If false, it is disabled.
//
//  Returns:
//      0       - Success
//      1       - LogChnNum is out of range or channel associated with LogChnNum had not been added
//
//  See Also:
//      <MLBSS_CHN_CFG_T>
//-----------------------------------------------------------------------------
extern int mlbss_enableChannel( unsigned LogChnNum, bool bEnable );

//-----------------------------------------------------------------------------
//  Function: mlbss_muteChannel
//      This function is used to mute or unmute a channel that has been previously
//      added.
//
//  Parameters:
//      LogChnNum   - The logical channel number (0..63)
//      bMute       - If true, the channel is muted. If false, it is unmuted.
//
//  Returns:
//      0       - Success
//      1       - LogChnNum is out of range or channel associated with LogChnNum had not been added
//      2       - Channel type associated with LogChnNum is invalid (must be synchronous, asynchronous, or control)
//
//  See Also:
//      None
//-----------------------------------------------------------------------------
extern int mlbss_muteChannel( unsigned LogChnNum, bool bMute );

//-----------------------------------------------------------------------------
//  Function: mlbss_getChannelBuffStatus
//      This function is used to get the system buffer status for a channel
//      that has been previously added.
//
//  Parameters:
//      LogChnNum      - The logical channel number (0..63)
//      BuffPage       - The buffer page (ping or pong) to get the status of (see <MLBSS_BUFF_PAGE_E>)
//      pChnBuffStatus - A pointer to a <MLBSS_CHN_BUFF_STATUS_T> structure where the system buffer status is written
//
//  Returns:
//      0       - Success
//      1       - LogChnNum is out of range or channel associated with LogChnNum had not been added
//
//  See Also:
//      <mlbss_setChannelBuffStatus>
//-----------------------------------------------------------------------------
extern int mlbss_getChannelBuffStatus( unsigned LogChnNum, MLBSS_BUFF_PAGE_E BuffPage, MLBSS_CHN_BUFF_STATUS_T *pChnBuffStatus );

//-----------------------------------------------------------------------------
//  Function: mlbss_setChannelBuffStatus
//      This function is used to set the system buffer status for a channel
//      that has been previously added.
//
//  Parameters:
//      LogChnNum      - The logical channel number (0..63)
//      BuffPage       - The buffer page (ping or pong) to get the status of (see <MLBSS_BUFF_PAGE_E>)
//      pChnBuffStatus - A pointer to a <MLBSS_CHN_BUFF_STATUS_T> structure containing the system buffer status information
//
//  Returns:
//      0       - Success
//      1       - LogChnNum is out of range or channel associated with LogChnNum had not been added
//
//  See Also:
//      <mlbss_getChannelBuffStatus>
//-----------------------------------------------------------------------------
extern int mlbss_setChannelBuffStatus( unsigned LogChnNum, MLBSS_BUFF_PAGE_E BuffPage, MLBSS_CHN_BUFF_STATUS_T *pChnBuffStatus );

//-----------------------------------------------------------------------------
//  Function: mlbss_setBaseAddr
//      This function is used to specify the base address of the module's
//      register set in the SoC MMR memory map.
//
//      This function is called by the <mlbss_config> function, so the user
//      normally does not need to call it directly.
//
//  Parameters:
//      BaseAddr   - Base address of the module's register set in the SoC MMR memory map
//
//  Returns:
//      None
//
//  See Also:
//      <mlbss_config>
//-----------------------------------------------------------------------------
extern void mlbss_setBaseAddr( uint64_t BaseAddr );

//-----------------------------------------------------------------------------
//  Function: mlbss_ratCfgRegion
//      This function is used to add a region into the Region Address
//      Translation. If the region already exists, or the region overlaps with
//      one or more existing regions, an error is returned.
//
//  Parameters:
//      RegionNum   - The region number (0-63)
//      bEnable     - If true, the region is enabled. If false, it is disabled.
//      AhbAddr     - 32-bit AHB address
//      SizeBytes   - Size of the region in bytes (size will be rounded-up to the next power-of-2, minimum of 1024 bytes)
//      VbusAddr    - 48-bit VBUS address (specified in a 64-bit variable)
//
//  Returns:
//      0           - Success
//      1           - Argument error (RegionNum is invalid)
//      2           - Region already exists. Call <mlbss_delRatRegion> first.
//      3           - Region overlaps with previously added regions
//
//  See Also:
//      <mlbss_delRatRegion>
//      <mlbss_enableRatRegion>
//-----------------------------------------------------------------------------
extern int mlbss_addRatRegion( unsigned RegionNum, bool bEnable, uint32_t AhbAddr, unsigned SizeBytes, uint64_t VbusAddr );

//-----------------------------------------------------------------------------
//  Function: mlbss_delRatRegion
//      This function is used to delete a previously added region from the
//      Region Address Translation.
//
//  Parameters:
//      RegionNum   - The region number (0-63)
//
//  Returns:
//      0           - Success
//      1           - Argument error (RegionNum is invalid)
//      2           - Region does not exist. Call <mlbss_addRatRegion> first.
//      3           - Region overlaps with previously added regions
//
//  See Also:
//      <mlbss_addRatRegion>
//-----------------------------------------------------------------------------
extern int mlbss_delRatRegion( unsigned RegionNum );

//-----------------------------------------------------------------------------
//  Function: mlbss_enableRatRegion
//      This function is used to enable or disable a previously added region in
//      the Region Address Translation.
//
//  Parameters:
//      RegionNum   - The region number (0-63)
//      bEnable     - If true, the region is enabled. If false, it is disabled.
//
//  Returns:
//      0           - Success
//      1           - Parameter error (RegionNum is invalid)
//      2           - Region does not exist. Call <mlbss_addRatRegion> first.
//
//  See Also:
//      <mlbss_addRatRegion>
//-----------------------------------------------------------------------------
extern int mlbss_enableRatRegion( unsigned RegionNum, bool bEnable );

//-----------------------------------------------------------------------------
//  Function: mlbss_getRatRegion
//      This function is used to add a region into the Region Address
//      Translation. If the region already exists, or the region overlaps with
//      one or more existing regions, an error is returned.
//
//  Parameters:
//      RegionNum   - The region number (0-63)
//      pbEnable    - A pointer to a bool indicating if the region is enabled
//      pAhbAddr    - A pointer to a 32-bit AHB address
//      pSizeBytes  - A pointer to the size of the region in bytes
//      pVbusAddr   - A pointer to a 48-bit VBUS address (specified in a 64-bit variable)
//
//  Returns:
//      0           - Success
//      1           - Argument error (RegionNum is invalid)
//
//  See Also:
//      <mlbss_addRatRegion>
//-----------------------------------------------------------------------------
extern int mlbss_getRatRegion( unsigned RegionNum, bool *pbEnable, uint32_t *pAhbAddr, unsigned *pSizeBytes, uint64_t *pVbusAddr );

//-----------------------------------------------------------------------------
//  Function: mlbss_getCtrField
//      This function is used to read a field (from 1 to 32 bits in length)
//      starting from any bit position (0 to 127 bits) from a 128-bit CTR entry.
//
//  Parameters:
//      CtrAddr     - The address (index) of the CTR entry to be written (0..0x8F)
//      FieldWidth  - The width of the field in bits (1..32)
//      FieldStart  - The starting bit position of the field in the CTR entry (0..127)
//
//  Returns:
//      (uint32_t)-1    - Parameter error (CtrAddr is out of range, FieldWidth > 32, or (FieldStart+FieldWidth) > 128)
//      The specified field is returned
//
//  See Also:
//      <mlbss_setCtrField>
//-----------------------------------------------------------------------------
extern uint32_t mlbss_getCtrField( unsigned CtrAddr, unsigned FieldWidth, unsigned FieldStart );

//-----------------------------------------------------------------------------
//  Function: mlbss_setCtrField
//      This function is used to write a field (from 1 to 32 bits in length)
//      starting from any bit position (0 to 127 bits) to a 128-bit CTR entry.
//
//  Parameters:
//      CtrAddr     - The address (index) of the CTR entry to be written (0..0x8F)
//      FieldWidth  - The width of the field in bits (1..32)
//      FieldStart  - The starting bit position of the field in the CTR entry (0..127)
//      value       - The value to be written into the field
//
//  Returns:
//      0           - Success
//      (int)-1     - Parameter error (CtrAddr is out of range, FieldWidth > 32, or (FieldStart+FieldWidth) > 128)
//
//  See Also:
//      <mlbss_getCtrField>
//-----------------------------------------------------------------------------
extern int mlbss_setCtrField( unsigned CtrAddr, unsigned FieldWidth, unsigned FieldStart, uint32_t value );

//-----------------------------------------------------------------------------
//  Function: mlbss_configCdt
//      This function is used to configure a Channel Descriptor Table (cdt)
//      entry for the specified logical channel number. Note that only the
//      Data Buffer RAM address and length fields are configured. The rest of the
//      cdt fields are written as 0.
//
//  Parameters:
//      LogChnNum       - Logical channel number (0-63)
//      DbrBuffAddr     - Address of the data buffer for this channel in the
//                        Data Buffer RAM. The address must be in the range
//                        of 0-0x3FFF.
//      DbrBuffLen      - The length in bytes of the buffer for this channel
//                        in the Data Buffer RAM. DbrBuffLen must be > 0 and
//                        DbrBuffAddr+DbrBuffLen must be <= 0x4000.
//
//  Returns:
//      0               - Success
//      1               - Parameter error (out of range)
//
//  See Also:
//      None
//-----------------------------------------------------------------------------
extern int mlbss_configCdt( unsigned LogChnNum, unsigned DbrBuffAddr, unsigned DbrBuffLen );

//-----------------------------------------------------------------------------
//  Function: mlbss_configCat
//      This function is used to configure the HBI and MediaLB Channel
//      Allocation Table (cat) entries for the specified logical channel number.
//
//  Parameters:
//      LogChnNum       - Logical channel number (0-63)
//      ChnType         - Type of channel (see <MLBSS_CHN_TYPE_E>)
//      Dir             - Direction of channel (see <MLBSS_CHN_DIR_E>)
//      bEnable         - true to enable channel now, false to disable channel
//      bMute           - Mute Enable (not valid for Isochronous channels)
//      bFCE            - Flow Control Enable (valid only for Isochronous Rx channels)
//      bMFE            - Multi-Frame per sub-buffer Enable (valid only for Synchronous channels)
//
//  Returns:
//      0               - Success
//      1               - Parameter error (out of range)
//
//  See Also:
//      None
//-----------------------------------------------------------------------------
extern int mlbss_configCat( unsigned LogChnNum, MLBSS_CHN_TYPE_E ChnType, MLBSS_CHN_DIR_E Dir, bool bEnable, bool bMute, bool bFCE, bool bMFE );

extern int mlbss_configAdt( unsigned LogChnNum, MLBSS_CHN_CFG_T *pChn );

#define mlbss_getBuffPagePtr(lcn)            mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,13)
#define mlbss_setBuffPagePtr(lcn,v)          mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,13,v)
#define mlbss_isBuffRdy(lcn,page)            mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,(32+15)+(16*(page)))
#define mlbss_setBuffRdy(lcn,page,v)         mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,(32+15)+(16*(page)),v)
#define mlbss_isBuffDone(lcn,page)           mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,(32+14)+(16*(page)))
#define mlbss_clrBuffDone(lcn,page)          mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,(32+14)+(16*(page)),0)
#define mlbss_isBuffPktStart(lcn,page)       mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,(32+12)+(16*(page)))
#define mlbss_setBuffPktStart(lcn,page,v)    mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,(32+12)+(16*(page)),v)
#define mlbss_isBuffErr(lcn,page)            mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,(32+13)+(16*(page)))
#define mlbss_clrBuffErr(lcn,page)           mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,(32+13)+(16*(page)),0)
#define mlbss_isBuffMEP(lcn,page)            mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,(32+11)+(16*(page)))
#define mlbss_clrBuffMEP(lcn,page)           mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,(32+11)+(16*(page)),0)
#define mlbss_isChnEnabled(lcn)              mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,15)
#define mlbss_setChnEnable(lcn,v)            mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,15,v)
#define mlbss_getChnEndian(lcn)              mlbss_getCtrField(CTR_ADT_ADDR(lcn),1,14)
#define mlbss_setChnEndian(lcn,v)            mlbss_setCtrField(CTR_ADT_ADDR(lcn),1,14,v)
#define mlbss_getBuffDepth(lcn,page,w)       mlbss_getCtrField(CTR_ADT_ADDR(lcn),(w),32+(16*(page)))
#define mlbss_setBuffDepth(lcn,page,v,w)     mlbss_setCtrField(CTR_ADT_ADDR(lcn),(w),32+(16*(page)),v)
#define mlbss_getBuffAddr(lcn,page)          mlbss_getCtrField(CTR_ADT_ADDR(lcn),32,64+(32*(page)))
#define mlbss_setBuffAddr(lcn,page,v)        mlbss_setCtrField(CTR_ADT_ADDR(lcn),32,64+(32*(page)),v)

#ifdef __cplusplus
}
#endif  // extern "C"

#endif  // end of _CSLF_MLBSS_H_ definition
