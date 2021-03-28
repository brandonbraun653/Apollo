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
#include <stdio.h>
#include <stdint.h>
#include <ti/csl/csl_mlb.h>
#include "csl_mlbss_support.h"

typedef unsigned int    uint;

#define CTR_MAX_ADDR            (0x90)                  // CTR address maximum
#define CTR_CAT_MEDIALB_BASE    (0x80)                  // CTR address of start of CAT MEDIALB area
#define CTR_CAT_HBI_BASE        (0x88)                  // CTR address of start of CAT HBI area
#define CTR_CAT_ADDR(lcn,hbi)   ((hbi)?(CTR_CAT_HBI_BASE+((lcn)>>3)):(CTR_CAT_MEDIALB_BASE+((lcn)>>3))) // Converts a logical channel num and hbi indicator to a CTR address in the CAT
#define CTR_CAT_BITOFFSET(lcn)  (((lcn)%8)<<4)          // Converts a logical channel num to a bit offset within a CAT CTR entry
#define DBR_SIZE_BYTES          (16*1024)               // Size of Data Buffer RAM in bytes

#define _BITMASK_(w,s)          ((uint32_t)(((1UL<<(w))-1)<<(s)))   // Generate a bit mask of width (w) with lsb at bit position (s)
#define _MIN_(a,b)              ((a)<(b)?(a):(b))

static unsigned             _eSyncFrameCnt;             // Global storage for the SyncFrameCnt

//-----------------------------------------------------------------------------
//  Internal variables and macros for tracking active channels
//-----------------------------------------------------------------------------
static uint64_t _mlbss_DefinedChannels = 0;
#define _mlbss_isChnNumValid(lcn)   ((lcn)<MLBSS_MAX_CHNS)
#define _mlbss_isChnDefined(lcn)    (_mlbss_isChnNumValid(lcn) && (_mlbss_DefinedChannels & ((uint64_t)1<<(lcn))))
#define _mlbss_setChnDefined(lcn)   (_mlbss_DefinedChannels |= ((uint64_t)1<<(lcn)))
#define _mlbss_clrChnDefined(lcn)   (_mlbss_DefinedChannels &= ~((uint64_t)1<<(lcn)))
//-----------------------------------------------------------------------------
//  Internal variables and macros for tracking active RAT regions
//-----------------------------------------------------------------------------
static uint64_t _mlbss_DefinedRatRegions = 0;

//=============================================================================
//  Internal functions for allocating space from the Data Buffer Ram
//=============================================================================
static unsigned _mlbss_dbrPoolMaxAddr, _mlbss_dbrPoolCurrAddr;

static void _mlbss_resetDbrMallocPool()
{
    _mlbss_dbrPoolCurrAddr = 0;
    _mlbss_dbrPoolMaxAddr = 16*1024;
}

static unsigned _mlbss_mallocDrbPool( unsigned size )
{
    unsigned CurrAddr;

    if( (_mlbss_dbrPoolCurrAddr + size) > _mlbss_dbrPoolMaxAddr )
        return (unsigned)-1;
    CurrAddr = _mlbss_dbrPoolCurrAddr;
    _mlbss_dbrPoolCurrAddr += size;
    return CurrAddr;
}

//=============================================================================
//  mlbss top-level API functions
//=============================================================================
int mlbss_initCsl( uint64_t BaseAddr )
{
    mlbss_setBaseAddr( BaseAddr );
    _mlbss_resetDbrMallocPool();        // Reset DBR malloc pool
    _mlbss_DefinedChannels = 0;         // No channels are defined
    _mlbss_DefinedRatRegions = 0;       // No RAT regions are defined
    return 0;
}

int mlbss_config( CSL_MLBSS_CFG_T *pMlbssCfg, CSL_MLBSS_MLB_CFG_T *pMlbCoreCfg )
{
    if( (pMlbssCfg == NULL) || (pMlbCoreCfg == NULL) )
        return 1;
    if( CSL_MLBSS_isInitInProgress() )
    {
//        CslOsal_Log( "Waiting for ECC initialization of DIM rams to complete...\n" );
        while( CSL_MLBSS_isInitInProgress() );
    }
    _eSyncFrameCnt = pMlbCoreCfg->SyncFrameCnt;     // Save SyncFrameCnt
    CSL_MLBSS_config( pMlbssCfg, pMlbCoreCfg );
    return 0;
}

//=============================================================================
//  chn (Logical channel API functions)
//=============================================================================

#define _mlbss_chnGetType(lcn)                  ((MLBSS_CHN_TYPE_E)mlbss_getCtrField(CTR_CAT_ADDR(lcn,0),3,CTR_CAT_BITOFFSET(lcn)+8))
#define _mlbss_catSetMute(lcn,hbi,mute)         (mlbss_setCtrField(CTR_CAT_ADDR(lcn,hbi),1,CTR_CAT_BITOFFSET(lcn)+13,(mute)))
#define _mlbss_setChnMute(lcn,mute)             { _mlbss_catSetMute(lcn,0,mute); _mlbss_catSetMute(lcn,1,mute); }

static unsigned _mlbss_getChnDbrBuffSize( MLBSS_CHN_CFG_T *pChn )
{
    unsigned DbrBuffDepth;
    MLBSS_CHN_CFG_ISO_T *pIsoChnCfg;

    switch( pChn->Type )
    {
        case MLBSS_CHN_TYPE_SYNC:
            DbrBuffDepth = 4 * MLBSS_DECODE_SYNC_FCNT_E(_eSyncFrameCnt) * ((MLBSS_CHN_CFG_SYNC_T *)pChn->pChnCfg)->BytesPerFrame;
            if( DbrBuffDepth > (1u<<12) )           // DBR buffer depth field for Sync channel is 12-bits
                return 0;
            break;
        case MLBSS_CHN_TYPE_CTL:
            DbrBuffDepth = ((MLBSS_CHN_CFG_CTL_T *)pChn->pChnCfg)->BuffDepthBytes;
            if( DbrBuffDepth > (1u<<12) )           // DBR buffer depth field for Ctl channel is 12-bits
                return 0;
            break;
        case MLBSS_CHN_TYPE_ASYNC:
            DbrBuffDepth = ((MLBSS_CHN_CFG_ASYNC_T *)pChn->pChnCfg)->BuffDepthBytes;
            if( DbrBuffDepth > (1u<<12) )           // DBR buffer depth field for Async channel is 12-bits
                return 0;
            break;
        case MLBSS_CHN_TYPE_ISO:
            pIsoChnCfg = (MLBSS_CHN_CFG_ISO_T *)pChn->pChnCfg;
            DbrBuffDepth = pIsoChnCfg->DbrNumBlocks * pIsoChnCfg->BlockSizeBytes;
            if( (pIsoChnCfg->DbrNumBlocks < 3) || ( DbrBuffDepth > (1u<<13) ) ) // DBR buffer depth field for Iso channel is 13-bits
                return 0;
            break;
        default:
            return 0;
    }
    return DbrBuffDepth;
}

int mlbss_addChannel( unsigned LogChnNum, MLBSS_CHN_CFG_T *pChn )
{
    unsigned DbrBuffAddr, DbrBuffDepth;
    bool    bFCE, bMFE;

    if( !_mlbss_isChnNumValid(LogChnNum) ) return 1;    // Channel number is invalid
    if( _mlbss_isChnDefined(LogChnNum) ) return 2;      // Channel is already defined
    if( pChn == NULL ) return 3;                        // Channel information not provided
    //-------------------------------------------------------------------------
    //  Initialize DBR and AHB buffer-related values
    //-------------------------------------------------------------------------
    DbrBuffDepth = _mlbss_getChnDbrBuffSize( pChn );
    if( DbrBuffDepth == 0 ) return 4;
    //-------------------------------------------------------------------------
    //  1. Initialize all bits of the CAT to ’0’ (already done in mlbss_config())
    //  2. Select a logical channel: N = 0 - 63 (N = pCfg->Num)
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    // 3. Program the CDT for channel N (mlbss_configCdt( unsigned DbrBuffBaseAddr, unsigned DbrBuffDepth )
    //      a. Set the 14-bit base address (BA) (BA = mlbss_dbrMalloc(buffer_depth)
    //      b. Set the 12-bit or 13-bit buffer depth (BD): BD = buffer depth in bytes -1
    //          i.   For synchronous channels: (BD + 1) = 4 × frames per sub-buffer (m) × bytes-per-frame (bpf)
    //          ii.  For isochronous channels: (BD + 1) mod (BS + 1) = 0
    //          iii. For asynchronous channels: (BD + 1) >= max packet length (1024 for a MOST Data Packet (MDP); 1536 for a MOST Ethernet Packet (MEP))
    //          iv.  For control channels: (BD + 1) >= max packet length (64)
    //      c. For isochronous channels, set the block size (BS): BS = block size in bytes - 1
    //      d. Set all other bits of the CDT to ’0’
    //-------------------------------------------------------------------------
    DbrBuffAddr = _mlbss_mallocDrbPool( DbrBuffDepth );
    if( DbrBuffAddr == (unsigned)-1 ) return 5;
    mlbss_configCdt( LogChnNum, DbrBuffAddr, DbrBuffDepth );
    //-------------------------------------------------------------------------
    //  4. Program the CAT for the inbound DMA into the DBR
    //      a. For Tx channels (to MediaLB) HBI is the inbound DMA
    //      b. For Rx channels (from MediaLB) MediaLB is the inbound DMA
    //      c. Set the channel direction: RNW = 0
    //      d. Set the channel type: CT[2:0] = 010 (asynchronous), 001 (control), 011 (isochronous), or 000 (synchronous)
    //      e. Set the connection label: CL[5:0] = N
    //      f. If CT[2:0] = 000 (synchronous), set the mute bit (MT = 1)
    //      g. Set the channel enable: CE = 1
    //      h. Set all other bits of the CAT to ’0’
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //  5. Program the CAT for the outbound DMA into the DBR
    //      a. For Tx channels (to MediaLB) MediaLB is the outbound DMA
    //      b. For Rx channels (from MediaLB) HBI is the outbound DMA
    //      c. Set the channel direction: RNW = 1
    //      d. Set the channel type: CT[2:0] = 010 (asynchronous), 001 (control), 011 (isochronous), or 000 (synchronous)
    //      e. Set the channel label: CL[5:0] = N
    //      f. If CT[2:0] = 000 (synchronous), set the mute bit (MT = 1)
    //      g. Set the channel enable: CE = 1
    //      h. Set all other bits of the CAT to ’0’
    //-------------------------------------------------------------------------
    bFCE = (pChn->Type == MLBSS_CHN_TYPE_ISO) && (pChn->Dir == MLBSS_CHN_DIR_RX) && ((MLBSS_CHN_CFG_ISO_T *)pChn->pChnCfg)->bFlowCtlEnable;
    bMFE = (pChn->Type == MLBSS_CHN_TYPE_SYNC) && (_eSyncFrameCnt != MLBSS_SYNC_FCNT_1);
    mlbss_configCat( LogChnNum, pChn->Type, pChn->Dir, true, pChn->Type==MLBSS_CHN_TYPE_SYNC, bFCE, bMFE );
    //-------------------------------------------------------------------------
    //  Program the AMBA AHB block ping/pong pages
    //-------------------------------------------------------------------------
    mlbss_configAdt( LogChnNum, pChn );
    //-------------------------------------------------------------------------
    //  Configure the RAT for this logical channel
    //-------------------------------------------------------------------------
    mlbss_addRatRegion( LogChnNum, true, (uint32_t)pChn->pSysBuff->BuffAddr[0], pChn->pSysBuff->BuffDepth[0]*2, pChn->pSysBuff->BuffAddr[0] );
    //-------------------------------------------------------------------------
    //  Configure AHB interrupts
    //-------------------------------------------------------------------------
    if( pChn->bEnableInt )
    {
        CSL_MLBSS_enableAhbInt( LogChnNum );
        CSL_MLBSS_enableHbiInt( LogChnNum );
    }
    else
    {
        CSL_MLBSS_disableAhbInt( LogChnNum );
        CSL_MLBSS_disableHbiInt( LogChnNum );
    }
    //-------------------------------------------------------------------------
    //  Denote channel as defined
    //-------------------------------------------------------------------------
    _mlbss_setChnDefined( LogChnNum );
    return 0;
}

int mlbss_enableChannel( unsigned LogChnNum, bool bEnable )
{
    static uint64_t _ChannelsEnabled = 0;

    if( !_mlbss_isChnDefined(LogChnNum) ) return 1;                     // Channel number is invalid or is not defined
    mlbss_setChnEnable( LogChnNum, bEnable );
    //---------------------------------------------------------------------
    //  Denote channel as enabled or disabled
    //---------------------------------------------------------------------
    if( bEnable )
        _ChannelsEnabled |= (uint64_t)1 << LogChnNum;
    else
        _ChannelsEnabled &= ~((uint64_t)1 << LogChnNum);
    //---------------------------------------------------------------------
    //  If one or more channels are enabled, insure MLB and HCI are
    //  enabled. If all channels are disabled, then disable the MLB and HCI.
    //---------------------------------------------------------------------
	if( _ChannelsEnabled )
	{
		CSL_MLBSS_enableMlb();
		CSL_MLBSS_enableHbi();
	}
	else
	{
		CSL_MLBSS_disableMlb();
		CSL_MLBSS_disableHbi();
	}
    return 0;
}

int mlbss_muteChannel( unsigned LogChnNum, bool bMute )
{
    if( !_mlbss_isChnDefined(LogChnNum) ) return 1;                     // Channel number is invalid or is not defined
    if( _mlbss_chnGetType(LogChnNum) == MLBSS_CHN_TYPE_ISO ) return 2;  // Invalid channel type
    _mlbss_setChnMute( LogChnNum, bMute );                              // Configure MT bit in CAT MediaLB and HBI portions of CTR
    return 0;
}

int mlbss_getChannelBuffStatus( unsigned LogChnNum, MLBSS_BUFF_PAGE_E BuffPage, MLBSS_CHN_BUFF_STATUS_T *pChnBuffStatus )
{
    if( !_mlbss_isChnDefined(LogChnNum) ) return 1;                     // Channel number is invalid or is not defined
    pChnBuffStatus->bBuffRdy     = mlbss_isBuffRdy( LogChnNum, BuffPage );
    pChnBuffStatus->bBuffDone    = mlbss_isBuffDone( LogChnNum, BuffPage );
    pChnBuffStatus->bErr         = mlbss_isBuffErr( LogChnNum, BuffPage );
    pChnBuffStatus->bPktStart    = mlbss_isBuffPktStart( LogChnNum, BuffPage );
    pChnBuffStatus->bMEP         = mlbss_isBuffMEP( LogChnNum, BuffPage );
    return 0;
}

int mlbss_setChannelBuffStatus( unsigned LogChnNum, MLBSS_BUFF_PAGE_E BuffPage, MLBSS_CHN_BUFF_STATUS_T *pChnBuffStatus )
{
    if( !_mlbss_isChnDefined(LogChnNum) ) return 1;                     // Channel number is invalid or is not defined
    mlbss_setBuffPagePtr( LogChnNum, BuffPage );
    mlbss_setBuffRdy( LogChnNum, BuffPage, pChnBuffStatus->bBuffRdy );
    mlbss_clrBuffDone( LogChnNum, BuffPage );
    mlbss_setBuffPktStart( LogChnNum, BuffPage, pChnBuffStatus->bPktStart );
    mlbss_clrBuffErr( LogChnNum, BuffPage );
    mlbss_clrBuffMEP( LogChnNum, BuffPage );
    return 0;
}

//=============================================================================
//  ss (SubSystem)
//=============================================================================
#define MLBSS_DIM_REGS_OFFSET   (0x800)
#define MLBSS_RAT_REGS_OFFSET   (0x1000)

void mlbss_setBaseAddr( uint64_t BaseAddr )
{
}

//=============================================================================
//  rat (Region Address Translation)
//=============================================================================
#define RAT_MAX_REGIONS             (64)
#define RAT_MIN_REGION_SIZE         (1024)
#define RAT_MIN_REGION_SIZE_ENCODED (10)

typedef struct
{
    uint32_t    Control;
    uint32_t    Res[3];
    uint32_t    Base;
    uint32_t    Size;
    uint32_t    Upper;
    uint32_t    Lower;
} MLBSS_RAT_T;

static unsigned _lmo( uint32_t val )
{
    unsigned LmoBitPos=0;
    while(val)
    {
        LmoBitPos++;
        val >>= 1;
    }
    return LmoBitPos-1;
}

int mlbss_addRatRegion( unsigned RegionNum, bool bEnable, uint32_t AhbAddr, unsigned SizeBytes, uint64_t VbusAddr )
{
    uint32_t EncSize;

    if (RegionNum >= RAT_MAX_REGIONS) return 1;                             // RegionNum Invalid
    if (_mlbss_DefinedRatRegions & ((uint64_t)1 << RegionNum)) return 2;    // Region Already Exists
    EncSize = (SizeBytes <= RAT_MIN_REGION_SIZE) ? RAT_MIN_REGION_SIZE_ENCODED : _lmo(SizeBytes-1) + 1;
    CSL_MLBSS_setRatRegion( RegionNum, bEnable, EncSize, AhbAddr, VbusAddr );
    _mlbss_DefinedRatRegions |= ((uint64_t)1 << RegionNum);   // Denote region as existing
    return 0; // Success
}

int mlbss_getRatRegion( unsigned RegionNum, bool *pbEnable, uint32_t *pAhbAddr, unsigned *pSizeBytes, uint64_t *pVbusAddr )
{
    uint32_t EncSize;

    if(RegionNum >= RAT_MAX_REGIONS) return 1;     // RegionNum Invalid
    if(!(_mlbss_DefinedRatRegions & ((uint64_t)1 << RegionNum))) return 2; // Region Does Not Exist
    CSL_MLBSS_getRatRegion( RegionNum, pbEnable, &EncSize, pAhbAddr, pVbusAddr );
    if(pSizeBytes)  *pSizeBytes = 1u << EncSize;
    return 0;
}

int mlbss_delRatRegion( unsigned RegionNum )
{
    if (RegionNum >= RAT_MAX_REGIONS) return 1;                     // RegionNum Invalid
    if (!(_mlbss_DefinedRatRegions & ((uint64_t)1 << RegionNum))) return 2; // Region Does Not Exist
    CSL_MLBSS_disableRatRegion( RegionNum );
    _mlbss_DefinedRatRegions &= ~((uint64_t)1 << RegionNum);                // Denote region as not existing
    return 0;  // Success
}

int mlbss_enableRatRegion( unsigned RegionNum, bool bEnable )
{
    if (RegionNum >= RAT_MAX_REGIONS) return 1;                     // RegionNum Invalid
    if (!(_mlbss_DefinedRatRegions & ((uint64_t)1 << RegionNum))) return 2; // Region Does Not Exist
    CSL_MLBSS_enableRatRegion( RegionNum );
    return 0; // Success
}

uint32_t mlbss_getCtrField( unsigned CtrAddr, unsigned FieldWidth, unsigned FieldStart )
{
    uint32_t v, data[4] = {0,0,0,0};
    unsigned WordIdx, WordLsb;

    if( (CtrAddr >= CTR_MAX_ADDR)           ||
        (FieldWidth == 0)                   ||
        (FieldWidth > 32)                   ||
        ((FieldStart+FieldWidth) > 128) )
        return (uint32_t)-1;
    CSL_MLBSS_getCtrEntry( CtrAddr, data );
    WordIdx = FieldStart >> 5;
    WordLsb = FieldStart & 0x1F;
    v = (data[WordIdx] >> WordLsb) & _BITMASK_(_MIN_(FieldWidth, 32-WordLsb), 0);
    if( WordLsb + FieldWidth > 32 )
    {
        // Field crosses a word boundary
        WordIdx++;
        v |= ((data[WordIdx] & _BITMASK_((WordLsb+FieldWidth-32), 0)) << (32-WordLsb));
    }
    return v;
}

int mlbss_setCtrField( unsigned CtrAddr, unsigned FieldWidth, unsigned FieldStart, uint32_t value )
{
    uint32_t mask[4] = {0,0,0,0};
    uint32_t data[4] = {0,0,0,0};
    unsigned WordIdx, WordLsb;

    if( (CtrAddr >= CTR_MAX_ADDR)           ||
        (FieldWidth == 0)                   ||
        (FieldWidth > 32)                   ||
        ((FieldStart+FieldWidth) > 128) )
        return (int)-1;
    WordIdx = FieldStart >> 5;
    WordLsb = FieldStart & 0x1F;
    mask[WordIdx] = _BITMASK_(_MIN_(FieldWidth,32-WordLsb),WordLsb);
    data[WordIdx] = (value << WordLsb) & mask[WordIdx];
    if( WordLsb + FieldWidth > 32 )
    {
        // Field crosses a word boundary
        WordIdx++;
        mask[WordIdx] = _BITMASK_((WordLsb+FieldWidth-32), 0);
        data[WordIdx] = (value >> (32-WordLsb)) & mask[WordIdx];
    }
    CSL_MLBSS_setCtrEntry( CtrAddr, mask, data );
    return 0;
}

int mlbss_configCdt( unsigned LogChnNum, unsigned DbrBuffAddr, unsigned DbrBuffLen )
{
    uint32_t data[4] = { 0, 0, 0, 0 };

    DbrBuffLen--;                                       // Buffer length - 1 is stored in the register
    if( (!_mlbss_isChnNumValid( LogChnNum ))    ||
        (DbrBuffLen > _BITMASK_(13,0))          ||      // This will catch DbrBuffLen==0 and large values of DbrBuffLen
        ((DbrBuffAddr+DbrBuffLen) >= DBR_SIZE_BYTES) )
        return 1;
    data[3] = (DbrBuffAddr << 16) | DbrBuffLen;
    CSL_MLBSS_setCtrEntry( LogChnNum, NULL, data );
    return 0;
}

#define CAT_RNW_MASK    (1u<<12)

int mlbss_configCat( unsigned LogChnNum, MLBSS_CHN_TYPE_E ChnType, MLBSS_CHN_DIR_E Dir, bool bEnable, bool bMute, bool bFCE, bool bMFE )
{
    uint32_t data;

    if( (!_mlbss_isChnNumValid( LogChnNum ))        ||
        (ChnType >= MLBSS_CHN_TYPE_MAX)             ||
        (Dir > MLBSS_CHN_DIR_TX) )
        return 1;
    data =  ((LogChnNum & 0x3F) << 0)       |
            ((ChnType & 0x7) << 8)          |
            ((bEnable & 0x1) << 11);
    if( ChnType == MLBSS_CHN_TYPE_SYNC )
    {
        data |= ((bMFE & 0x1) << 14) | ((bMute & 0x1) << 13);
    }
    else if( ChnType == MLBSS_CHN_TYPE_ISO )
    {
        if( Dir == MLBSS_CHN_DIR_RX )
            data |= ((bFCE & 0x1) << 14);
    }
    else
    {
        data |= ((bMute & 0x1) << 13);
    }
    //-------------------------------------------------------------------------
    //  Configure the MediaLB CAT entry
    //      bRNW = (Dir==MLBSS_CHN_DIR_TX)
    //-------------------------------------------------------------------------
    if( Dir == MLBSS_CHN_DIR_TX )
        data |= CAT_RNW_MASK;       // MediaLB RNW = 1 for TX
    else
        data &= ~CAT_RNW_MASK;      // MediaLB RNW = 0 for RX
    mlbss_setCtrField( CTR_CAT_ADDR(LogChnNum,false), 16, CTR_CAT_BITOFFSET(LogChnNum), data );
    //-------------------------------------------------------------------------
    //  Configure the HBI CAT entry
    //      bRNW = (Dir==MLBSS_CHN_DIR_RX)
    //-------------------------------------------------------------------------
    if( Dir == MLBSS_CHN_DIR_RX )
        data |= CAT_RNW_MASK;       // HBI RNW = 1 for RX
    else
        data &= ~CAT_RNW_MASK;      // HBI RNW = 0 for TX
    mlbss_setCtrField( CTR_CAT_ADDR(LogChnNum,true), 16, CTR_CAT_BITOFFSET(LogChnNum), data );
    return 0;
}

//-----------------------------------------------------------------------------
//  mlbss_configAdt
//
//  1. Initialize all bits of the ADT to ’0’ (done earlier)
//  2. Select a logical channel: N = 0 - 63 (LogChnNum)
//  3. Program the AMBA AHB block ping page for channel N
//      a. Set the 32-bit base address (BA1)
//      b. Set the 11-bit buffer depth (BD1): BD1 = buffer depth in bytes - 1
//          i. For synchronous channels: (BD1 + 1) = n × frames per sub-buffer (m) × bytes-per-frame (bpf)
//          ii. For isochronous channels: (BD1 + 1) mod (BS + 1) = 0
//          iii. For asynchronous channels: 5 <= (BD1 + 1) <= 4096 (max packet length)
//          iv. For control channels: 5 <= (BD1 + 1) <= 4096 (max packet length)
//      c. For asynchronous and control Tx channels set the packet start bit (PS1) iff the page contains the start of the packet (don't do this here)
//      d. Clear the page done bit (DNE1)
//      e Clear the error bit (ERR1)
//      f. Set the page ready bit (RDY1) (don't do this here)
//  4. Program the AMBA AHB block pong page for channel N
//      a. Set the 32-bit base address (BA2)
//      b. Set the 11-bit buffer depth (BD2): BD2 = buffer depth in bytes - 1
//          i. For synchronous channels: (BD2 +1) = n × frames per sub-buffer (m) × bytes-per-frame (bpf)
//          ii. For isochronous channels: (BD2 + 1) mod (BS + 1) = 0
//          iii. For asynchronous channels: 5 <= (BD2 + 1) <= 4096 (max packet length)
//          iv. For control channels: 5 <= (BD2 + 1) <= 4096 (max packet length)
//      c. For asynchronous and control Tx channels set the packet start bit (PS2) iff the page contains the start of the packet (don't do this here)
//      d. Clear the page done bit (DNE2)
//      e. Clear the error bit (ERR2)
//      f. Set the page ready bit (RDY2) (don't do this here)
//  5. Select Big Endian (LE = 0) or Little Endian (LE = 1)
//  6. Select the active page: PG = 0 (ping), PG = 1 (pong)
//  7. Set the channel enable (CE) bit for all active logical channels
//-----------------------------------------------------------------------------
int mlbss_configAdt( unsigned LogChnNum, MLBSS_CHN_CFG_T *pChn )
{
    MLBSS_CHN_SYS_BUFF_T *pSysBuff;
    uint32_t data[4];

    if( (!_mlbss_isChnNumValid( LogChnNum ))  ||
        (pChn == NULL) )
        return 1;
    pSysBuff = pChn->pSysBuff;
    if( (pSysBuff->BuffDepth[0] == 0)   ||
        (pSysBuff->BuffDepth[1] == 0) )
        return 1;
    data[0] =   (pSysBuff->bLittleEndian & 0x1) << 14;      // Configure LE (CE=0)
    data[1] =   ((pSysBuff->BuffDepth[1]-1) << 16)  |       // BD2
                (pSysBuff->BuffDepth[0]-1);                 // BD1
    data[2] =   pSysBuff->BuffAddr[0] & 0xFFFFFFFFu;        // BA1
    data[3] =   pSysBuff->BuffAddr[1] & 0xFFFFFFFFu;        // BA2
    CSL_MLBSS_setCtrEntry( CTR_ADT_BASE+LogChnNum, NULL, data );
    return 0;
}
