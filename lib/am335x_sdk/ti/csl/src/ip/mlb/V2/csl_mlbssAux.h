/**
 * @file  csl_mlbssAux.h
 *
 * @brief
 *  API Auxiliary header file for the Media Local Bus Sub-System (mlbss) CSL.
 *  This file contains control and status query functions.
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

#ifndef CSL_MLBSS_AUX_H_
#define CSL_MLBSS_AUX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_mlb.h>
#include <ti/csl/cslr_mlb.h>

#ifndef CSL_IDEF_INLINE
#define CSL_IDEF_INLINE static inline
#endif

#define CTR_MAX_ADDR            (0x90)          // CTR address maximum
#define CTR_CAT_MEDIALB_BASE    (0x80)          // CTR address of start of CAT MEDIALB area

#define CSL_MLBSS_clearCtrEntry(CtrAddr) CSL_MLBSS_setCtrEntry( CtrAddr, NULL, NULL )

/** @addtogroup CSL_MLBSS_FUNCTION
@{ */

/********************************************************************************
******************* Media Local Bus Sub-System (MLBSS) Submodule ****************
********************************************************************************/


/** ============================================================================
 *   @n@b CSL_MLBSS_configSubSystem
 *
 *   @b Description
 *   @n This function is used to configure the mlbss sub-system. It is called by
 *      the higher-level CSL_MLBSS_config function, but may be called separately.
 *
 *   @b Arguments
 *   @verbatim
        bool     bEnableFastClkStop   - If true, fast Clock Stop mode is enabled. If false, it is disabled.
        unsigned DmaVbusPriority      - A value (0..7) specifying the priority of the mlbss DMA (with 0 being the highest priority, 7 the lowest)
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBSS_CTRL_CLKFACK, MLBSS_DMA_CTRL_PRIORITY
 *
 *   @b Example
 *   @verbatim
        bool        bEnableFastClkStop = true;
        unsigned    DmaVbusPriority = 0;

        CSL_MLBSS_configSubSystem( bEnableFastClkStop, DmaVbusPriority );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_configSubSystem( bool bEnableFastClkStop, unsigned DmaVbusPriority )
{
    CSL_REG_WRITE( pMlbSsRegs->CTRL, CSL_FMK( MLBSS_CTRL_CLKFACK, bEnableFastClkStop ) );
    CSL_REG_WRITE( pMlbSsRegs->DMA_CTRL, CSL_FMK( MLBSS_DMA_CTRL_PRIORITY, DmaVbusPriority ) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_getPid
 *
 *   @b Description
 *   @n This function is used to get the mlbss PID value.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  The 32-bit PID value of the mlbss is returned
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n PID
 *
 *   @b Example
 *   @verbatim
        uint32_t    pid;

        pid = CSL_MLBSS_getPid();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE uint32_t CSL_MLBSS_getPid()
{
    return CSL_REG_READ( pMlbSsRegs->PID );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_isInitInProgress
 *
 *   @b Description
 *   @n This function returns the initialization status of the mlbss sub-system.
 *      When the mlbss is reset, internal CTR and DBR memories within the mlbss are
 *      initialized. This is not an instantaneous operation, so this function is
 *      provided to determine when this operation is complete. No functions
 *      which require the use of the CTR or DBR should be called until this
 *      initialization is complete.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  TRUE is returned if the internal memory initialization is in progress,
 *       otherwise FALSE is returned.
 *
 *   <b> Pre Condition </b>
 *   @n  No functions which require the use of the CTR or DBR should be called until this
 *       initialization is complete.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MLBSS_STAT_INIT
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_resetSubSystem();                 // Initiate reset
        while( CSL_MLBSS_isInitInProgress() );      // Wait for memory initialization to complete
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE bool CSL_MLBSS_isInitInProgress()
{
//  return CSL_FEXT( pMlbSsRegs->STAT, MLBSS_STAT_INIT ) == 1;
    return (CSL_FEXT( pMlbSsRegs->STAT, MLBSS_STAT_INIT ) == 0);      // WORKAROUND: There is an rtl polarity bug with this status indication
}

/** ============================================================================
 *   @n@b CSL_MLBSS_isResetInProgress
 *
 *   @b Description
 *   @n This function returns the reset status of the mlbss sub-system.
 *      When the mlbss is reset, registers are reset to their default values and
 *      internal CTR and DBR memories within the mlbss are initialized. This is
 *      not an instantaneous operation, so this function is provided to determine
 *      when this operation is complete. No other mlbss functions should be
 *      called until reset is complete.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  TRUE is returned if a Sub-System reset is in progress, otherwise FALSE is
 *       returned.
 *
 *   <b> Pre Condition </b>
 *   @n  This function is normally used after calling CSL_MLBSS_resetSubSystem()
 *       to determine when the subsystem reset is completed.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MLBSS_STAT_RESET
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_resetSubSystem();                 // Initiate reset
        while( CSL_MLBSS_isResetInProgress() );     // Wait for reset to complete
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE bool CSL_MLBSS_isResetInProgress()
{
    return ( CSL_MLBSS_isInitInProgress()               ||
             (CSL_FEXT( pMlbSsRegs->STAT, MLBSS_STAT_RESET ) == 1) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_resetSubSystem
 *
 *   @b Description
 *   @n This function initiates a reset of the mlbss sub-system, including
 *      initialization of internal CTR and DBR memories.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Reset may take some time to complete. CSL_MLBSS_isResetInProgress() can
 *       be called to
 *
 *   @b Reads
 *   @n MLBSS_STAT_INIT
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_resetSubSystem();                 // Initiate reset
        while( CSL_MLBSS_isInitInProgress() );      // Wait for memory initialization to complete
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_resetSubSystem()
{
    CSL_FINS( pMlbSsRegs->CTRL, MLBSS_CTRL_RESET, 1 );
}

//=============================================================================
//  rat (Region Address Translation)
//=============================================================================
typedef struct
{
    uint32_t    Control;
    uint32_t    Res[3];
    uint32_t    Base;
    uint32_t    Size;
    uint32_t    Upper;
    uint32_t    Lower;
} _CSL_MLBSS_RAT_T;

CSL_IDEF_INLINE void _CSL_MLBSS_toggleRatRegion( unsigned RegionNum, bool bEnable )
{
    _CSL_MLBSS_RAT_T *pRatRegs = ((_CSL_MLBSS_RAT_T *)pMlbRatRegs) + RegionNum;

    CSL_FINS(pRatRegs->Control, KSBUS_RAT_CTRL0_BASE, bEnable);
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableRatRegion
 *
 *   @b Description
 *   @n This function disables translation for the specified RAT region.
 *
 *   @b Arguments
 *   @verbatim
        unsigned RegionNum  - The number of the region (0..63)
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_setRatRegion
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n KSBUS_RAT_CTRL0_BASE
 *
 *   @b Example
 *   @verbatim
        unsigned RegionNum = 3;
        CSL_MLBSS_disableRatRegion( RegionNum );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableRatRegion( unsigned RegionNum )
{
   _CSL_MLBSS_toggleRatRegion( RegionNum, 0 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableRatRegion
 *
 *   @b Description
 *   @n This function enables translation for the specified RAT region.
 *
 *   @b Arguments
 *   @verbatim
        unsigned RegionNum  - The number of the region (0..63)
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_setRatRegion
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n KSBUS_RAT_CTRL0_BASE
 *
 *   @b Example
 *   @verbatim
        unsigned RegionNum = 3;
        CSL_MLBSS_enableRatRegion( RegionNum );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableRatRegion( unsigned RegionNum )
{
     _CSL_MLBSS_toggleRatRegion( RegionNum, 1 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_setRatRegion
 *
 *   @b Description
 *   @n This function is used to set a RAT region.
 *
 *   @b Arguments
 *   @verbatim
        RegionNum   - The number of the region (0..63)
        bEnable     - If true, region is enabled, otherwise region is disabled
        EncodedSize - Encoded size of the region (SizeInBytes = 2^EncSize)
        AhbAddr     - The 32-bit AHB base address for this region
        VbusAddr    - The 48-bit VBUS base address for this region (stored in a 64-bit variable)
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n KSBUS_RAT_SIZE0_SIZE, KSBUS_RAT_BASE0_BASE, KSBUS_RAT_UPPER0_UPPER, KSBUS_RAT_LOWER0_UPPER, KSBUS_RAT_CTRL0_BASE
 *
 *   @b Example
 *   @verbatim
        unsigned    RegionNum = 3;
        bool        bEnable        = true;         // Enable the region
        unsigned    EncodedSize    = 12;           // Region size is 4K bytes (encoded as 12)
        uint32_t    AhbAddr        = 0x00001000;   // The 32-bit AHB base address for this region
        uint64_t    VbusAddr       = 0x80000000UL; // The 48-bit VBUS base address for this region
        CSL_MLBSS_setRatRegion( RegionNum, bEnable, EncodedSize, AhbAddr, VbusAddr );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_setRatRegion( unsigned RegionNum, bool bEnable, unsigned EncodedSize, uint32_t AhbAddr, uint64_t VbusAddr )
{
    _CSL_MLBSS_RAT_T *pRatRegs = ((_CSL_MLBSS_RAT_T *)pMlbRatRegs) + RegionNum;

    CSL_FINS(pRatRegs->Size, KSBUS_RAT_SIZE0_SIZE, EncodedSize);
    CSL_FINS(pRatRegs->Base, KSBUS_RAT_BASE0_BASE, AhbAddr);
    CSL_FINS(pRatRegs->Upper, KSBUS_RAT_UPPER0_UPPER, (VbusAddr >> 32));
    CSL_FINS(pRatRegs->Lower, KSBUS_RAT_LOWER0_UPPER, VbusAddr);
    _CSL_MLBSS_toggleRatRegion( RegionNum, bEnable );
}

/** ============================================================================
 *   @n@b mlbss_getRatRegion
 *
 *   @b Description
 *   @n This function is used to get information about a RAT region. Note that
 *      if any of the argument pointers described in the Arguments below are
 *      NULL, then that particular value is not returned.
 *
 *   @b Arguments
 *   @verbatim
        RegionNum       - The number of the region (0..63)
        pbEnable        - Pointer to a bool indicating if the region is enabled (true) or disabled (false)
        pEncodedSize    - Pointer to unsigned indicating the encoded size of the region (SizeInBytes = 2^EncSize)
        pAhbAddr        - Pointer to a uint32_t indicating the 32-bit AHB base address for this region
        pVbusAddr       - Pointer to a uint64_t indicating the 48-bit VBUS base address for this region (stored in a 64-bit variable)
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n KSBUS_RAT_SIZE0_SIZE, KSBUS_RAT_BASE0_BASE, KSBUS_RAT_UPPER0_UPPER, KSBUS_RAT_LOWER0_UPPER, KSBUS_RAT_CTRL0_BASE
 *
 *   @b Example
 *   @verbatim
        bool        bEnable;
        unsigned    EncodedSize;
        uint32_t    AhbAddr;
        uint64_t    VbusAddr;
        mlbss_getRatRegion( 3, &bEnable, &EncodedSize, &AhbAddr, &VbusAddr );   // Return all Rat information for region 3
        mlbss_getRatRegion( 6, NULL, &EncodedSize, NULL, NULL );                // Return only the encoded size for Rat region 6
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_getRatRegion( unsigned RegionNum, bool *pbEnable, unsigned *pEncodedSize, uint32_t *pAhbAddr, uint64_t *pVbusAddr )
{
    _CSL_MLBSS_RAT_T *pRatRegs = ((_CSL_MLBSS_RAT_T *)pMlbRatRegs) + RegionNum;

    if(pbEnable)        *pbEnable       = (bool)CSL_FEXT( pRatRegs->Control, KSBUS_RAT_CTRL0_BASE );
    if(pEncodedSize)    *pEncodedSize   = (unsigned)CSL_REG_READ( pRatRegs->Size );
    if(pAhbAddr)        *pAhbAddr       = CSL_REG_READ( pRatRegs->Base );
    if(pVbusAddr)       *pVbusAddr      = (((uint64_t)CSL_REG_READ( pRatRegs->Upper )) << 32) | (uint64_t)CSL_REG_READ( pRatRegs->Lower );
}

//=============================================================================
//  mif (Memory I/F)
//=============================================================================
CSL_IDEF_INLINE void _CSL_MLBSS_doMifAccess( uint32_t MadrRegVal )
{
    CSL_REG_WRITE( pMlbDimRegs->MADR, MadrRegVal );
    while( !CSL_REG_READ( pMlbDimRegs->MCTL ) );        // The MIF block sets MCTL.XCMP = 1 to inform the HC when the read is complete.
    CSL_REG_WRITE( pMlbDimRegs->MCTL, 0 );              // Write-0 to clear MCTL.XCMP
}

/** ============================================================================
 *   @n@b CSL_MLBSS_writeDbr8
 *
 *   @b Description
 *   @n This function is used to write a byte to the Data Buffer Ram (DBR).
 *
 *   @b Arguments
 *   @verbatim
        ByteAddr    - The byte address within the DBR to write to (0..0x3FFF)
        data        - The byte value to write
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the DBR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MADR, MCTL
 *
 *   @b Reads
 *   @n MCTL
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_writeDbr8( 0x1000, 0xFF );        // Write 0xFF to DBR address 0x1000
     @endverbatim
 * =============================================================================
 */
 CSL_IDEF_INLINE void CSL_MLBSS_writeDbr8(unsigned ByteAddr, uint8_t data)
{
    unsigned dbr_address = ByteAddr & 0x3FFF;
    uint32_t madr_reg;

    CSL_REG_WRITE(pMlbDimRegs->MDAT0, data);                    // MDAT0 = data;
    madr_reg = (0x1 << 31) | (0x1 << 30) | (dbr_address);       // WNR, TB, and Addr
    _CSL_MLBSS_doMifAccess( madr_reg );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_readDbr8
 *
 *   @b Description
 *   @n This function is used to read a byte from the Data Buffer Ram (DBR).
 *
 *   @b Arguments
 *   @verbatim
        ByteAddr    - The byte address within the DBR to read from (0..0x3FFF)
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  The byte value read
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the DBR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MADR, MCTL
 *
 *   @b Reads
 *   @n MCTL
 *
 *   @b Example
 *   @verbatim
        uint8_t data;

        data = CSL_MLBSS_readDbr8( 0x1000 );        // Read the byte from DBR address 0x1000
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE uint8_t CSL_MLBSS_readDbr8(unsigned ByteAddr)
{
    unsigned dbr_address = ByteAddr & 0x3FFF;
    uint32_t madr_reg;

    madr_reg = (0x0 << 31) | (0x1 << 30) | (dbr_address);       // WNR, TB, and Addr
    _CSL_MLBSS_doMifAccess( madr_reg );
    return (uint8_t)CSL_REG_READ(pMlbDimRegs->MDAT0);
}

/** ============================================================================
 *   @n@b CSL_MLBSS_clearCtrEntry
 *
 *   @b Description
 *   @n This function is used to clear an entry in the Channel Table Ram (CTR)
 *
 *   @b Arguments
 *   @verbatim
        CtrAddr     - The address (0..0x8F) of the CTR entry to clear
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the DBR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MDAT0, MDAT1, MDAT2, MDAT3, MDWE0, MDWE1, MDWE2, MDWE3, MADR, MCTL
 *
 *   @b Reads
 *   @n MCTL
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_clearCtrEntry( 0x10 );  // Clear CTR entry 0x10
     @endverbatim
 * =============================================================================
 */
#define CSL_MLBSS_clearCtrEntry(CtrAddr) CSL_MLBSS_setCtrEntry( CtrAddr, NULL, NULL )

/** ============================================================================
 *   @n@b CSL_MLBSS_setCtrEntry
 *
 *   @b Description
 *   @n This function is used to set an entry in the Channel Table Ram (CTR)
 *
 *   @b Arguments
 *   @verbatim
        CtrAddr     - The address (0..0x8F) of the CTR entry to set
        mask        - Pointer to a 4 element uint32_t array (128-bits) where each bit corresponds
                      to a write enable for the corresponding bit in the entry. If mask is NULL,
                      then all mask bits are assumed to be 1.
        data        - Pointer to a 4 element uint32_t array (128-bits) where each bit corresponds
                      to the bit to be written in the entry (if the corresponding mask bit is also set).
                      If data is NULL, then all data bits are assumed to be 0.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the DBR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MDAT0, MDAT1, MDAT2, MDAT3, MDWE0, MDWE1, MDWE2, MDWE3, MADR, MCTL
 *
 *   @b Reads
 *   @n MCTL
 *
 *   @b Example
 *   @verbatim
        uint32_t mask[4] = { 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF };

        CSL_MLBSS_setCtrEntry( 0x10, mask, NULL );  // Write 0's to every other byte in CTR entry 0x10
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_setCtrEntry( unsigned CtrAddr, uint32_t *mask, uint32_t *data )
{
    if( CtrAddr < CTR_MAX_ADDR )
    {
        uint32_t madr_reg;

        // Assign Data and Mask
        CSL_REG_WRITE(pMlbDimRegs->MDAT0, data ? data[0] : 0); // MDAT0 = wrdata[0];
        CSL_REG_WRITE(pMlbDimRegs->MDAT1, data ? data[1] : 0); // MDAT1 = wrdata[1];
        CSL_REG_WRITE(pMlbDimRegs->MDAT2, data ? data[2] : 0); // MDAT2 = wrdata[2];
        CSL_REG_WRITE(pMlbDimRegs->MDAT3, data ? data[3] : 0); // MDAT3 = wrdata[3];

        CSL_REG_WRITE(pMlbDimRegs->MDWE0, mask ? mask[0] : 0xFFFFFFFF); // MDWE0  = mask[0];
        CSL_REG_WRITE(pMlbDimRegs->MDWE1, mask ? mask[1] : 0xFFFFFFFF); // MDWE1  = mask[1];
        CSL_REG_WRITE(pMlbDimRegs->MDWE2, mask ? mask[2] : 0xFFFFFFFF); // MDWE2  = mask[2];
        CSL_REG_WRITE(pMlbDimRegs->MDWE3, mask ? mask[3] : 0xFFFFFFFF); // MDWE3  = mask[3];

        // Write Cycle
        madr_reg = (0x1 << 31) | (0x0 << 30) | (CtrAddr & 0xFF);    // WNR, TB, and Addr
        _CSL_MLBSS_doMifAccess( madr_reg );
    }
}

/** ============================================================================
 *   @n@b CSL_MLBSS_getCtrEntry
 *
 *   @b Description
 *   @n This function is used to get an entry from the Channel Table Ram (CTR)
 *
 *   @b Arguments
 *   @verbatim
        CtrAddr     - The address (0..0x8F) of the CTR entry to get
        data        - Pointer to a 4 element uint32_t array (128-bits) where the contents
                      of the CTR entry is stored
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the DBR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MADR, MCTL
 *
 *   @b Reads
 *   @n MDAT0, MDAT1, MDAT2, MDAT3, MCTL
 *
 *   @b Example
 *   @verbatim
        uint32_t data[4];

        CSL_MLBSS_getCtrEntry( 0x10, data );        // Read contents of CTR entry 0x10
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_getCtrEntry( unsigned CtrAddr, uint32_t *data )
{
    if( CtrAddr < CTR_MAX_ADDR )
    {
        uint32_t madr_reg;

        // Read Cycle
        madr_reg = (0x0 << 31) | (0x0 << 30) | (CtrAddr & 0xFF);    // WNR, TB, and Addr
        _CSL_MLBSS_doMifAccess( madr_reg );

        *data++ = CSL_REG_READ(pMlbDimRegs->MDAT0);
        *data++ = CSL_REG_READ(pMlbDimRegs->MDAT1);
        *data++ = CSL_REG_READ(pMlbDimRegs->MDAT2);
        *data++ = CSL_REG_READ(pMlbDimRegs->MDAT3);
    }
}

/** ============================================================================
 *   @n@b CSL_MLBSS_clearCtr
 *
 *   @b Description
 *   @n This function is used to clear each entry in the Channel Table Ram (CTR).
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the DBR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MDAT0, MDAT1, MDAT2, MDAT3, MDWE0, MDWE1, MDWE2, MDWE3, MADR, MCTL
 *
 *   @b Reads
 *   @n MCTL
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_clearCtr();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_clearCtr( void )
{
    unsigned CtrAddr;
    for( CtrAddr = 0; CtrAddr < CTR_MAX_ADDR; CtrAddr++ )
        CSL_MLBSS_setCtrEntry( CtrAddr, NULL, NULL );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_clearCat
 *
 *   @b Description
 *   @n This function is used to clear each entry in the Channel Address Table (CAT)
 *      portion of the Channel Table Ram (CTR).
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the DBR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MDAT0, MDAT1, MDAT2, MDAT3, MDWE0, MDWE1, MDWE2, MDWE3, MADR, MCTL
 *
 *   @b Reads
 *   @n MCTL
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_clearCat();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_clearCat()
{
    unsigned CtrAddr;

    for( CtrAddr = CTR_CAT_MEDIALB_BASE; CtrAddr < CTR_MAX_ADDR; CtrAddr++ )
        CSL_MLBSS_setCtrEntry( CtrAddr, NULL, NULL );
}

//=============================================================================
//  mlb (Media Local Bus)
//=============================================================================
/** ============================================================================
 *   @n@b CSL_MLBSS_configMlb
 *
 *   @b Description
 *   @n This function is used to configure the Media Local Bus (MLB) functionality
 *      within the mlbss.
 *
 *   @b Arguments
 *   @verbatim
        pMlbCoreCfg - A pointer to a CSL_MLBSS_MLB_CFG_T structure containing
                      MLB configuration information
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBC0, MLBPC0, MSS, MLBPC1
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_MLB_CFG_T MlbCfg;

        MlbCoreCfg.SyncFrameCnt         = CSL_MLBSS_SYNC_FCNT_1;
        MlbCoreCfg.PinMode              = CSL_MLBSS_MLB_PIN_MODE_3;
        MlbCoreCfg.ClkSpeed             = CSL_MLBSS_MLB_CLK_SPEED_512X;
        MlbCoreCfg.AhbPktMode           = CSL_MLBSS_AHB_PKT_MODE_SINGLE;
        MlbCoreCfg.AhbDmaMode           = CSL_MLBSS_AHB_DMA_MODE_0;
        MlbCoreCfg.bAhbIntMux           = true;
        MlbCoreCfg.bAhbSwClrInt         = true;
        MlbCoreCfg.bCtlRtry             = false;
        MlbCoreCfg.bAsyRetry            = false;
        MlbCoreCfg.bServiceReqEnable    = false;
        MlbCoreCfg.bHysteresisEnable    = false;
        MlbCoreCfg.ClkRxBiasCtl         = 0;
        MlbCoreCfg.SigDataTxBiasCtl     = 0;
        MlbCoreCfg.SigDataRxBiasCtl     = 0;

        CSL_MLBSS_configMlb( &MlbCfg );
     @endverbatim
 * =============================================================================
 */CSL_IDEF_INLINE void CSL_MLBSS_configMlb( CSL_MLBSS_MLB_CFG_T *pMlbCoreCfg )
{
    //-------------------------------------------------------------------------
    //  Configure MediaLB CONTROL 0 (MLBC0) REGISTER
    //-------------------------------------------------------------------------
    CSL_REG_WRITE( pMlbDimRegs->MLBC0,
        CSL_FMK( MLBDIM_MLBC0_FCNT, pMlbCoreCfg->SyncFrameCnt )     |
        CSL_FMK( MLBDIM_MLBC0_MLBPEN, pMlbCoreCfg->PinMode )        |
        CSL_FMK( MLBDIM_MLBC0_MLBCLK, pMlbCoreCfg->ClkSpeed )       |
        CSL_FMK( MLBDIM_MLBC0_CTLRETRY, pMlbCoreCfg->bCtlRtry )     |
        CSL_FMK( MLBDIM_MLBC0_ASYRETRY, pMlbCoreCfg->bAsyRetry )
    );
    //-------------------------------------------------------------------------
    //  Configure MediaLB 6-PIN CONTROL 0 (MLBPC0) REGISTER
    //-------------------------------------------------------------------------
    CSL_REG_WRITE( pMlbDimRegs->MLBPC0, CSL_FMK( MLBDIM_MLBPC0_MCLKHYS, pMlbCoreCfg->bHysteresisEnable ) );
    //-------------------------------------------------------------------------
    //  Configure MediaLB SYSTEM STATUS (MSS) REGISTER
    //-------------------------------------------------------------------------
    CSL_REG_WRITE( pMlbDimRegs->MSS, CSL_FMK( MLBDIM_MSS_SERVREQ, pMlbCoreCfg->bServiceReqEnable ) );
    //-------------------------------------------------------------------------
    //  Configure MediaLB 6-PIN CONTROL 1 (MLBPC1) REGISTER
    //-------------------------------------------------------------------------
    CSL_REG_WRITE( pMlbDimRegs->MLBPC1,
        CSL_FMK( MLBDIM_MLBPC1_SDRCVBIAS, pMlbCoreCfg->SigDataRxBiasCtl )   |
        CSL_FMK( MLBDIM_MLBPC1_SDXMTBIAS, pMlbCoreCfg->SigDataTxBiasCtl )   |
        CSL_FMK( MLBDIM_MLBPC1_CKRCVBIAS, pMlbCoreCfg->ClkRxBiasCtl )
    );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableMlb
 *
 *   @b Description
 *   @n This function is used to disable the MLB interface.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBDIM_MLBC0_MLBEN
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_disableMlb();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableMlb()
{
    CSL_FINS( pMlbDimRegs->MLBC0, MLBDIM_MLBC0_MLBEN, 0 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableMlb
 *
 *   @b Description
 *   @n This function is used to enable the MLB interface.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBDIM_MLBC0_MLBEN
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_enableMlb();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableMlb()
{
    CSL_FINS( pMlbDimRegs->MLBC0, MLBDIM_MLBC0_MLBEN, 1 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_isMlbClockLocked
 *
 *   @b Description
 *   @n This function is used to determine if the mlbss is locked to the MLB clock.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  true if the mlbss is locked to the MLB clock, false otherwise
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_enableMlb
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MLBDIM_MLBC0_MLBLK
 *
 *   @b Example
 *   @verbatim
        bool IsLocked;

        IsLocked = CSL_MLBSS_isMlbClockLocked();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE bool CSL_MLBSS_isMlbClockLocked()
{
    return (CSL_FEXT( pMlbDimRegs->MLBC0, MLBDIM_MLBC0_MLBLK ) == 1);
}

/** ============================================================================
 *   @n@b CSL_MLBSS_isMlbClockMissing
 *
 *   @b Description
 *   @n This function is used to determine if the mlbss is unable to detect an
 *      MLB clock.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  true if the mlbss is is unable to detect an MLB clock, false otherwise
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_enableMlb
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBDIM_MLBC1_CLKM
 *
 *   @b Reads
 *   @n MLBDIM_MLBC1_CLKM
 *
 *   @b Example
 *   @verbatim
        bool IsClockMissing;

        IsClockMissing = CSL_MLBSS_isMlbClockMissing();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE bool CSL_MLBSS_isMlbClockMissing()
{
    CSL_FINS( pMlbDimRegs->MLBC1, MLBDIM_MLBC1_CLKM, 0 );           // Clear latched clock missing status
    return (CSL_FEXT( pMlbDimRegs->MLBC1, MLBDIM_MLBC1_CLKM ) == 1);
}

CSL_IDEF_INLINE uint32_t CSL_MLBSS_getMlbSysStatus( void ) { return 0; }
CSL_IDEF_INLINE uint32_t CSL_MLBSS_getMlbSysData( void ) { return 0; }

/** ============================================================================
 *   @n@b CSL_MLBSS_getMlbIntsPending
 *
 *   @b Description
 *   @n This function is used to determine which channels have pending MLB
 *      interrupts. The desired MLB interrupts must first be enabled via the
 *      CSL_MLBSS_enableMlbInts or CSL_MLBSS_enableMlbInt functions before they
 *      can potentially cause a pending interrupt for a channel. A pending interrupt
 *      must be acknowledged via the CSL_MLBSS_ackMlbInts or CSL_MLBSS_ackMlbInt
 *      functions once detection or servicing of the interrupt is complete.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  A 64-bit mask is returned (mask bit 0 corresponds to channel 0, ...,
 *       mask bit 63 corresponds to channel 63) where each bit denotes if an MLB interrupt is
 *       pending (bit value is 1) or not pending (bit value is 0).
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_enableMlbInts, CSL_MLBSS_enableMlbInt
 *
 *   <b> Post Condition </b>
 *   @n  CSL_MLBSS_ackMlbInts, CSL_MLBSS_ackMlbInt
 *
 *   @b Reads
 *   @n MS0, MS1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChannelsWithPendingMlbInts;

        ChannelsWithPendingMlbInts = CSL_MLBSS_getMlbIntsPending();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE uint64_t CSL_MLBSS_getMlbIntsPending()
{
    return ((uint64_t)CSL_REG_READ(pMlbDimRegs->MS1) << 32UL) | (uint64_t)CSL_REG_READ( pMlbDimRegs->MS0 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_isMlbIntPending
 *
 *   @b Description
 *   @n This function is used to determine if a specific channel has a pending MLB
 *      interrupt. The desired MLB interrupts must first be enabled via the
 *      CSL_MLBSS_enableMlbInts or CSL_MLBSS_enableMlbInt functions before they
 *      can potentially cause a pending interrupt for a channel. A pending interrupt
 *      must be acknowledged via the CSL_MLBSS_ackMlbInts or CSL_MLBSS_ackMlbInt
 *      functions once detection or servicing of the interrupt is complete.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  true if an MLB interrupt is pending, false otherwise
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_enableMlbInts, CSL_MLBSS_enableMlbInt
 *
 *   <b> Post Condition </b>
 *   @n  CSL_MLBSS_ackMlbInts, CSL_MLBSS_ackMlbInt
 *
 *   @b Reads
 *   @n MS0, MS1
 *
 *   @b Example
 *   @verbatim
        unsigned    ChnNum = 17;
        bool        bMlbIntPending;

        bMlbIntPending = CSL_MLBSS_isMlbIntPending( ChnNum );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE bool CSL_MLBSS_isMlbIntPending( unsigned ChnNum )
{
    return ((CSL_MLBSS_getMlbIntsPending() & (1UL << ChnNum)) != 0);
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableMlbInts
 *
 *   @b Description
 *   @n This function is used to disable one or more MLB interrupt types.
 *
 *   @b Arguments
 *   @verbatim
        MlbIntTypeMask - A 32-bit wide mask where each bit corresponds to a specific MLB interrupt type.
                       If a mask bit is 1, the corresponding MLB interrupt type is disabled. If 0, it is unaffected.
                       See the CSL_MLBSS_MLB_INT_E enumerator for a list of valid MLB interrupt types.
                       Mask bit 0 corresponds to "Isochronous Rx protocol error", mask bit 24 corresponds
                       to "Control Rx packet done", etc.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MIEN
 *
 *   @b Reads
 *   @n MIEN
 *
 *   @b Example
 *   @verbatim
        uint32_t MlbIntTypeMask;

        MlbIntTypeMask = (1 << CSL_MLBSS_MLB_INT_ISO_RX_PROTOCOL_ERR) |
                         (1 << CSL_MLBSS_MLB_INT_CTL_RX_PKT_DONE);
        CSL_MLBSS_disableMlbInts( MlbIntTypeMask );           // Disable "Isochronous Rx protocol error" and "Control Rx packet done" MLB interrupt types
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableMlbInts( uint32_t MlbIntTypeMask )
{
    CSL_REG_WRITE( pMlbDimRegs->MIEN, (CSL_REG_READ( pMlbDimRegs->MIEN ) & ~MlbIntTypeMask) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableMlbInts
 *
 *   @b Description
 *   @n This function is used to enable one or more MLB interrupt types.
 *
 *   @b Arguments
 *   @verbatim
        MlbIntTypeMask - A 32-bit wide mask where each bit corresponds to a specific MLB interrupt type.
                       If a mask bit is 1, the corresponding MLB interrupt type is enable. If 0, it is unaffected.
                       See the CSL_MLBSS_MLB_INT_E enumerator for a list of valid MLB interrupt types.
                       Mask bit 0 corresponds to "Isochronous Rx protocol error", mask bit 24 corresponds
                       to "Control Rx packet done", etc.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MIEN
 *
 *   @b Reads
 *   @n MIEN
 *
 *   @b Example
 *   @verbatim
        uint32_t MlbIntTypeMask;

        MlbIntTypeMask = (1 << CSL_MLBSS_MLB_INT_ISO_RX_PROTOCOL_ERR) |
                         (1 << CSL_MLBSS_MLB_INT_CTL_RX_PKT_DONE);
        CSL_MLBSS_enableMlbInts( MlbIntTypeMask );           // Enable "Isochronous Rx protocol error" and "Control Rx packet done" MLB interrupt types
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableMlbInts( uint32_t MlbIntTypeMask )
{
    CSL_REG_WRITE( pMlbDimRegs->MIEN, (CSL_REG_READ( pMlbDimRegs->MIEN ) | MlbIntTypeMask) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableMlbInt
 *
 *   @b Description
 *   @n This function is used to disable an MLB interrupt type.
 *
 *   @b Arguments
 *   @verbatim
        MlbIntType - The MLB interrupt type to disable. See the CSL_MLBSS_MLB_INT_E
                     enumerator for a list of valid MLB interrupt types.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MIEN
 *
 *   @b Reads
 *   @n MIEN
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_disableMlbInt( CSL_MLBSS_MLB_INT_CTL_RX_PKT_DONE );    // Disable "Control Rx packet done" MLB interrupt type
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableMlbInt( CSL_MLBSS_MLB_INT_E MlbIntType )
{
    CSL_MLBSS_disableMlbInts( 1u << MlbIntType );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableMlbInt
 *
 *   @b Description
 *   @n This function is used to enable an MLB interrupt type.
 *
 *   @b Arguments
 *   @verbatim
        MlbIntType - The MLB interrupt type to enable. See the CSL_MLBSS_MLB_INT_E
                     enumerator for a list of valid MLB interrupt types.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MIEN
 *
 *   @b Reads
 *   @n MIEN
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_enableMlbInt( CSL_MLBSS_MLB_INT_CTL_RX_PKT_DONE );    // Enable "Control Rx packet done" MLB interrupt type
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableMlbInt( CSL_MLBSS_MLB_INT_E MlbIntType )
{
    CSL_MLBSS_enableMlbInts( 1u << MlbIntType );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_ackMlbInts
 *
 *   @b Description
 *   @n This function is used to acknowledge pending MLB interrupts on one or
 *      more channels.
 *
 *   @b Arguments
 *   @verbatim
        ChnNumMask - A 64-bit wide mask (mask bit 0 corresponds to channel 0, ...,
                     mask bit 63 corresponds to channel 63) where each bit denotes
                     if an MLB interrupt is to be acknowledged (bit value is 1) or
                     not (bit value is 0) for that channel.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MS0, MS1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChannelsWithPendingMlbInts;

        ChannelsWithPendingMlbInts = CSL_MLBSS_getMlbIntsPending();     // Determine channels with pending MLB interrupts
        CSL_MLBSS_ackMlbInts( ChannelsWithPendingMlbInts );             // Ack all pending interrupts
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_ackMlbInts( uint64_t ChnNumMask )
{
    if( (uint32_t)ChnNumMask )
        CSL_REG_WRITE( pMlbDimRegs->MS0, (uint32_t)~ChnNumMask );
    if( (uint32_t)(ChnNumMask >> 32UL) )
        CSL_REG_WRITE( pMlbDimRegs->MS1, (uint32_t)~(ChnNumMask >> 32UL) );

}

/** ============================================================================
 *   @n@b CSL_MLBSS_ackMlbInt
 *
 *   @b Description
 *   @n This function is used to acknowledge a pending MLB interrupt on a channel.
 *
 *   @b Arguments
 *   @verbatim
        ChnNum - Channel number (0..63) on which there is a pending MLB interrupt to
                 be acknowledged
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MS0, MS1
 *
 *   @b Example
 *   @verbatim
        unsigned ChnNum = 17;

        if( CSL_MLBSS_isMlbIntPending( ChnNum )     // If an interrupt is pending for this channel,
            CSL_MLBSS_ackMlbInt( ChnNum );          //   then acknowledge it
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_ackMlbInt( unsigned ChnNum )
{
    CSL_MLBSS_ackMlbInts( (uint64_t)1 << ChnNum );
}

//=============================================================================
//  ahb (AMBA AHB support)
//=============================================================================
/** ============================================================================
 *   @n@b CSL_MLBSS_configAhb
 *
 *   @b Description
 *   @n This function is used to configure the AHB functionality in the mlbss.
 *
 *   @b Arguments
 *   @verbatim
        PacketMode - Specifies the AHB packet buffering mode. See the MLBSS_AHB_PKT_MODE_E enumeration for valid modes.
        DmaMode    - Specified the AHB DMA mode. See the MLBSS_AHB_DMA_MODE_E enumeration for valid modes.
        bIntMux    - If true, ACSR0 and ACSR1 generate an interrupt on ahb_int[0] only. If false, ACSR0 generates an interrupt on ahb_int[0] and ACSR1 generates an interrupt on ahb_int[1].
        bSwClrInt  - If true, software is responsible for clearing AHB interrupts. If false, hardware clears interrupt after a ACSRn register read.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBDIM_ACTL_SCE, MLBDIM_ACTL_SMX, MLBDIM_ACTL_DMAMODE, MLBDIM_ACTL_MPB
 *
 *   @b Example
 *   @verbatim
        MLBSS_AHB_PKT_MODE_E PacketMode = CSL_MLBSS_AHB_PKT_MODE_SINGLE;
        MLBSS_AHB_DMA_MODE_E DmaMode    = CSL_MLBSS_AHB_DMA_MODE_0;
        bool bIntMux                    = true;
        bool bSwClrInt                  = true;

        CSL_MLBSS_configAhb( PacketMode, DmaMode, bIntMux, bSwClrInt );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_configAhb( CSL_MLBSS_AHB_PKT_MODE_E PacketMode, CSL_MLBSS_AHB_DMA_MODE_E DmaMode, bool bIntMux, bool bSwClrInt )
{
    CSL_REG_WRITE( pMlbDimRegs->ACTL,
        CSL_FMK( MLBDIM_ACTL_SCE, bSwClrInt )   |
        CSL_FMK( MLBDIM_ACTL_SMX, bIntMux )     |
        CSL_FMK( MLBDIM_ACTL_DMAMODE, DmaMode ) |
        CSL_FMK( MLBDIM_ACTL_MPB, PacketMode )
    );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_getAhbIntsPending
 *
 *   @b Description
 *   @n This function is used to determine which channels have pending AHB
 *      interrupts. The interrupts must first be enabled via the CSL_MLBSS_enableAhbInts
 *      or CSL_MLBSS_enableAhbInt functions before they can potentially cause a pending
 *      interrupt for a channel. A pending interrupt must be acknowledged via the
 *      CSL_MLBSS_ackAhbInts or CSL_MLBSS_ackAhbInt functions once detection or
 *      servicing of the interrupt is complete.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  A 64-bit mask is returned (mask bit 0 corresponds to channel 0, ...,
 *       mask bit 63 corresponds to channel 63) where each bit denotes if an AHB interrupt is
 *       pending (bit value is 1) or not pending (bit value is 0).
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_enableAhbInts, CSL_MLBSS_enableAhbInt
 *
 *   <b> Post Condition </b>
 *   @n  CSL_MLBSS_ackAhbInts, CSL_MLBSS_ackAhbInt
 *
 *   @b Reads
 *   @n ACSR0, ACSR1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChannelsWithPendingAhbInts;

        ChannelsWithPendingAhbInts = CSL_MLBSS_getAhbIntsPending();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE uint64_t CSL_MLBSS_getAhbIntsPending()
{
    return ((uint64_t)CSL_REG_READ(pMlbDimRegs->ACSR1) << 32UL) | (uint64_t)CSL_REG_READ( pMlbDimRegs->ACSR0 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_isAhbIntPending
 *
 *   @b Description
 *   @n This function is used to determine if a specific channel has a pending AHB
 *      interrupt. The interrupts must first be enabled via the CSL_MLBSS_enableAhbInts
 *      or CSL_MLBSS_enableAhbInt functions before they can potentially cause a pending
 *      interrupt for a channel. A pending interrupt must be acknowledged via the
 *      CSL_MLBSS_ackAhbInts or CSL_MLBSS_ackAhbInt functions once detection or
 *      servicing of the interrupt is complete.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  true if an AHB interrupt is pending, false otherwise
 *
 *   <b> Pre Condition </b>
 *   @n  CSL_MLBSS_enableAhbInts, CSL_MLBSS_enableAhbInt
 *
 *   <b> Post Condition </b>
 *   @n  CSL_MLBSS_ackAhbInts, CSL_MLBSS_ackAhbInt
 *
 *   @b Reads
 *   @n ACSR0, ACSR1
 *
 *   @b Example
 *   @verbatim
        unsigned    ChnNum = 17;
        bool        bAhbIntPending;

        bAhbIntPending = CSL_MLBSS_isAhbIntPending( ChnNum );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE bool CSL_MLBSS_isAhbIntPending( unsigned ChnNum )
{
    return ((CSL_MLBSS_getAhbIntsPending() & (1UL << ChnNum)) != 0);
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableAhbInts
 *
 *   @b Description
 *   @n This function is used to disable AHB interrupts on one or more channels.
 *
 *   @b Arguments
 *   @verbatim
        ChnNumMask - A 64-bit wide mask (mask bit 0 corresponds to channel 0, ...,
                     mask bit 63 corresponds to channel 63) where each bit denotes
                     if an AHB interrupt is to be disabled (bit value is 1) or
                     ignored (bit value is 0) for that channel.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACMR0, ACMR1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChnNumMask = (1UL << 48) | (1UL << 17);

        CSL_MLBSS_disableAhbInts( ChnNumMask ); // Disable AHB interrupts for channels 17 and 48
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableAhbInts( uint64_t ChnNumMask )
{
    if( (uint32_t)ChnNumMask )
        CSL_REG_WRITE( pMlbDimRegs->ACMR0, (CSL_REG_READ( pMlbDimRegs->ACMR0 ) & ~(uint32_t)ChnNumMask) );
    if( (uint32_t)(ChnNumMask >> 32UL) )
        CSL_REG_WRITE( pMlbDimRegs->ACMR1, (CSL_REG_READ( pMlbDimRegs->ACMR1) & ~(uint32_t)(ChnNumMask >> 32UL)) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableAhbInts
 *
 *   @b Description
 *   @n This function is used to enable AHB interrupts on one or more channels.
 *
 *   @b Arguments
 *   @verbatim
        ChnNumMask - A 64-bit wide mask (mask bit 0 corresponds to channel 0, ...,
                     mask bit 63 corresponds to channel 63) where each bit denotes
                     if an AHB interrupt is to be enabled (bit value is 1) or
                     ignored (bit value is 0) for that channel.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACMR0, ACMR1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChnNumMask = (1UL << 48) | (1UL << 17);

        CSL_MLBSS_enableAhbInts( ChnNumMask );  // Enable AHB interrupts for channels 17 and 48
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableAhbInts( uint64_t ChnNumMask )
{
    if( (uint32_t)ChnNumMask )
        CSL_REG_WRITE( pMlbDimRegs->ACMR0, (CSL_REG_READ( pMlbDimRegs->ACMR0 ) | (uint32_t)ChnNumMask) );
    if( (uint32_t)(ChnNumMask >> 32UL) )
        CSL_REG_WRITE( pMlbDimRegs->ACMR1, (CSL_REG_READ( pMlbDimRegs->ACMR1) | (uint32_t)(ChnNumMask >> 32UL)) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableAhbInt
 *
 *   @b Description
 *   @n This function is used to disable AHB interrupts on a channel.
 *
 *   @b Arguments
 *   @verbatim
        ChnNum - The channel number (0..63) on which to disable AHB interrupts
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACMR0, ACMR1
 *
 *   @b Example
 *   @verbatim
        unsigned ChnNum = 17;

        CSL_MLBSS_disableAhbInt( ChnNum );  // Disable AHB interrupts for channel 17
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableAhbInt( unsigned ChnNum )
{
    CSL_MLBSS_disableAhbInts( (uint64_t)1 << ChnNum );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableAhbInt
 *
 *   @b Description
 *   @n This function is used to enable AHB interrupts on a channel.
 *
 *   @b Arguments
 *   @verbatim
        ChnNum - The channel number (0..63) on which to enable AHB interrupts
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACMR0, ACMR1
 *
 *   @b Example
 *   @verbatim
        unsigned ChnNum = 17;

        CSL_MLBSS_enableAhbInt( ChnNum );   // Enable AHB interrupts for channel 17
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableAhbInt( unsigned ChnNum )
{
    CSL_MLBSS_enableAhbInts( (uint64_t)1 << ChnNum );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_ackAhbInts
 *
 *   @b Description
 *   @n This function is used to acknowledge AHB interrupts on one or more channels.
 *
 *   @b Arguments
 *   @verbatim
        ChnNumMask - A 64-bit wide mask (mask bit 0 corresponds to channel 0, ...,
                     mask bit 63 corresponds to channel 63) where each bit denotes
                     if an AHB interrupt is to be acknowledged (bit value is 1) or
                     ignored (bit value is 0) for that channel.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACSR0, ACSR1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChannelsWithPendingAhbInts;

        ChannelsWithPendingAhbInts = CSL_MLBSS_getAhbIntsPending(); // Determine channels with pending AHB interrupts
        CSL_MLBSS_ackAhbInts( ChannelsWithPendingAhbInts );         // Ack all pending interrupts
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_ackAhbInts( uint64_t ChnNumMask )
{
    if( (uint32_t)ChnNumMask )
        CSL_REG_WRITE( pMlbDimRegs->ACSR0, (uint32_t)ChnNumMask );
    if( (uint32_t)(ChnNumMask >> 32UL) )
        CSL_REG_WRITE( pMlbDimRegs->ACSR1, (uint32_t)(ChnNumMask >> 32UL) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_ackAhbInt
 *
 *   @b Description
 *   @n This function is used to acknowledge a pending AHB interrupt on a channel.
 *
 *   @b Arguments
 *   @verbatim
        ChnNum - Channel number (0..63) on which there is a pending AHB interrupt to
                 be acknowledged
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACSR0, ACSR1
 *
 *   @b Example
 *   @verbatim
        unsigned ChnNum = 17;

        if( CSL_MLBSS_isAhbIntPending( ChnNum )     // If an interrupt is pending for this channel,
            CSL_MLBSS_ackAhbInt( ChnNum );          //   then acknowledge it
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_ackAhbInt( unsigned ChnNum )
{
    CSL_MLBSS_ackAhbInts( (uint64_t)1 << ChnNum );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableHbi
 *
 *   @b Description
 *   @n This function is used to disable the HBI interface.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBDIM_HCTL_EN
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_disableHbi();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableHbi()
{
    CSL_FINS( pMlbDimRegs->HCTL, MLBDIM_HCTL_EN, 0 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableHbi
 *
 *   @b Description
 *   @n This function is used to enable the HBI interface.
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MLBDIM_HCTL_EN
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_enableHbi();
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableHbi()
{
    CSL_FINS( pMlbDimRegs->HCTL, MLBDIM_HCTL_EN, 1 );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableHbiInts
 *
 *   @b Description
 *   @n This function is used to disable HBI interrupts on one or more channels.
 *
 *   @b Arguments
 *   @verbatim
        ChnNumMask - A 64-bit wide mask (mask bit 0 corresponds to channel 0, ...,
                     mask bit 63 corresponds to channel 63) where each bit denotes
                     if an HBI interrupt is to be disabled (bit value is 1) or
                     ignored (bit value is 0) for that channel.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n HCMR0, HCMR1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChnNumMask = (1UL << 48) | (1UL << 17);

        CSL_MLBSS_disableHbiInts( ChnNumMask ); // Disable HBI interrupts for channels 17 and 48
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableHbiInts( uint64_t ChnNumMask )
{
    if( (uint32_t)ChnNumMask )
        CSL_REG_WRITE( pMlbDimRegs->HCMR0, (CSL_REG_READ( pMlbDimRegs->HCMR0 ) & ~(uint32_t)ChnNumMask) );
    if( (uint32_t)(ChnNumMask >> 32UL) )
        CSL_REG_WRITE( pMlbDimRegs->HCMR1, (CSL_REG_READ( pMlbDimRegs->HCMR1) & ~(uint32_t)(ChnNumMask >> 32UL)) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableHbiInts
 *
 *   @b Description
 *   @n This function is used to enable HBI interrupts on one or more channels.
 *
 *   @b Arguments
 *   @verbatim
        ChnNumMask - A 64-bit wide mask (mask bit 0 corresponds to channel 0, ...,
                     mask bit 63 corresponds to channel 63) where each bit denotes
                     if an HBI interrupt is to be enabled (bit value is 1) or
                     ignored (bit value is 0) for that channel.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n HCMR0, HCMR1
 *
 *   @b Example
 *   @verbatim
        uint64_t ChnNumMask = (1UL << 48) | (1UL << 17);

        CSL_MLBSS_enableHbiInts( ChnNumMask ); // Enable HBI interrupts for channels 17 and 48
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableHbiInts( uint64_t ChnNumMask )
{
    if( (uint32_t)ChnNumMask )
        CSL_REG_WRITE( pMlbDimRegs->HCMR0, (CSL_REG_READ( pMlbDimRegs->HCMR0 ) | (uint32_t)ChnNumMask) );
    if( (uint32_t)(ChnNumMask >> 32UL) )
        CSL_REG_WRITE( pMlbDimRegs->HCMR1, (CSL_REG_READ( pMlbDimRegs->HCMR1) | (uint32_t)(ChnNumMask >> 32UL)) );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_disableHbiInt
 *
 *   @b Description
 *   @n This function is used to disable HBI interrupts on a channel.
 *
 *   @b Arguments
 *   @verbatim
        ChnNum - The channel number (0..63) on which to disable HBI interrupts
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACMR0, ACMR1
 *
 *   @b Example
 *   @verbatim
        unsigned ChnNum = 17;

        CSL_MLBSS_disableHbiInt( ChnNum );  // Disable HBI interrupts for channel 17
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_disableHbiInt( unsigned ChnNum )
{
    CSL_MLBSS_disableHbiInts( (uint64_t)1 << ChnNum );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_enableHbiInt
 *
 *   @b Description
 *   @n This function is used to enable HBI interrupts on a channel.
 *
 *   @b Arguments
 *   @verbatim
        ChnNum - The channel number (0..63) on which to enable HBI interrupts
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n ACMR0, ACMR1
 *
 *   @b Example
 *   @verbatim
        unsigned ChnNum = 17;

        CSL_MLBSS_enableHbiInt( ChnNum );  // Enable HBI interrupts for channel 17
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_enableHbiInt( unsigned ChnNum )
{
    CSL_MLBSS_enableHbiInts( (uint64_t)1 << ChnNum );
}

/** ============================================================================
 *   @n@b CSL_MLBSS_config
 *
 *   @b Description
 *   @n This function is used to configure the entire mlbss in one call. The
 *      following configuration functions are called by this function:
 *      CSL_MLBSS_clearCtr          - Clear the Channel Table Ram
 *      CSL_MLBSS_configSubSystem   - Configure the mlbss sub-system
 *      CSL_MLBSS_configMlb         - Configure the MLB functionality
 *      CSL_MLBSS_configAhb         - Configure the AHB functionality
 *
 *   @b Arguments
 *   @verbatim
        pMlbSubSysCfg - A pointer to a CSL_MLBSS_CFG_T structure containing sub-system configuration information
        pMlbCoreCfg   - A pointer to a CSL_MLBSS_MLB_CFG_T structure containing MLB configuration information
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  Call CSL_MLBSS_isInitInProgress or CSL_MLBSS_isResetInProgress to insure
 *       the CTR has been initialized
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n MDAT0, MDAT1, MDAT2, MDAT3, MDWE0, MDWE1, MDWE2, MDWE3, MADR, MCTL,
 *      CTRL, DMA_CTRL, MLBC0, MLBPC0, MSS, MLBPC1, ACTL
 *
 *   @b Example
 *   @verbatim
        CSL_MLBSS_CFG_T         MlbSubSysCfg;
        CSL_MLBSS_MLB_CFG_T MlbCfg;

        MlbSubSysCfg.bEnableFastClkStop = false;
        MlbSubSysCfg.DmaVbusPriority    = 0;

        MlbCoreCfg.SyncFrameCnt         = CSL_MLBSS_SYNC_FCNT_1;
        MlbCoreCfg.PinMode              = CSL_MLBSS_MLB_PIN_MODE_3;
        MlbCoreCfg.ClkSpeed             = CSL_MLBSS_MLB_CLK_SPEED_512X;
        MlbCoreCfg.AhbPktMode           = CSL_MLBSS_AHB_PKT_MODE_SINGLE;
        MlbCoreCfg.AhbDmaMode           = CSL_MLBSS_AHB_DMA_MODE_0;
        MlbCoreCfg.bAhbIntMux           = true;
        MlbCoreCfg.bAhbSwClrInt         = true;
        MlbCoreCfg.bCtlRtry             = false;
        MlbCoreCfg.bAsyRetry            = false;
        MlbCoreCfg.bServiceReqEnable    = false;
        MlbCoreCfg.bHysteresisEnable    = false;
        MlbCoreCfg.ClkRxBiasCtl         = 0;
        MlbCoreCfg.SigDataTxBiasCtl     = 0;
        MlbCoreCfg.SigDataRxBiasCtl     = 0;

        CSL_MLBSS_config( &MlbSubSysCfg, &MlbCfg );
     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE void CSL_MLBSS_config( CSL_MLBSS_CFG_T *pMlbSubSysCfg, CSL_MLBSS_MLB_CFG_T *pMlbCoreCfg )
{
    CSL_MLBSS_clearCtr();
    CSL_MLBSS_configSubSystem( pMlbSubSysCfg->bEnableFastClkStop, pMlbSubSysCfg->DmaVbusPriority );
    CSL_MLBSS_configMlb( pMlbCoreCfg );
    CSL_MLBSS_configAhb( pMlbCoreCfg->AhbPktMode, pMlbCoreCfg->AhbDmaMode, pMlbCoreCfg->bAhbIntMux, pMlbCoreCfg->bAhbSwClrInt );
}

/** @} */

#ifdef __cplusplus
}
#endif

#endif
