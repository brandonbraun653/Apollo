;******************************************************************************
;  @file  startup.asm
;
;  @brief
;   Implementation file for the ARM R5 startup assembly code.
;
;   \par
;   ============================================================================
;   @n   (C) Copyright 2017-2019, Texas Instruments, Inc.
;
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions
;   are met:
;
;     Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;
;     Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the
;     distribution.
;
;     Neither the name of Texas Instruments Incorporated nor the names of
;     its contributors may be used to endorse or promote products derived
;     from this software without specific prior written permission.
;
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE,
;   DATA, OR PROFITS;  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;******************************************************************************
    .text

    .sect   ".startupCode"
;==============================================================================
;   void CSL_armR5StartupCacheEnableAllCache( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupCacheEnableAllCache
CSL_armR5StartupCacheEnableAllCache:
    PUSH    {lr}
    BL      CSL_armR5StartupCacheEnableICache
    BL      CSL_armR5StartupCacheEnableDCache
    POP     {lr}
    BX      lr

;==============================================================================
;   void CSL_armR5StartupCacheEnableForceWrThru( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupCacheEnableForceWrThru
CSL_armR5StartupCacheEnableForceWrThru:
    MRC     p15, #0, r1, c1, c0, #1         ; Read Auxiliary Control Register
    CMP     r0, #0
    BEQ     armR5CacheEnableForceWrThru_disable
    ORR     r1, r1, #(1<<9)                 ; Set (enable) force Write-thru bit for write-back (WB) regions
    B       armR5CacheEnableForceWrThru_00
armR5CacheEnableForceWrThru_disable:
    BIC     r1, r1, #(1<<9)                 ; Clear (disable) force Write-thru bit for write-back (WB) regions
armR5CacheEnableForceWrThru_00:
    MCR     p15, #0, r1, c1, c0, #1         ; Write modified Auxiliary Control Register
    BX      lr


;==============================================================================
;   void CSL_armR5StartupCacheEnableICache( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupCacheEnableICache
CSL_armR5StartupCacheEnableICache:
    MRC     p15, #0, r1, c1, c0, #0         ; Read SCTLR
    CMP     r0, #0
    BEQ     armR5CacheEnableICaches_disable
    ORR     r1, r1, #(1<<12)                ; Set I bit (enable L1 instruction caches)
    MOV     r2, #0
    MCR     p15, #0, r2, c7, c5, #0         ; Invalidate entire instruction cache
    B       armR5CacheEnableICaches_00
armR5CacheEnableICaches_disable:
    BIC     r1, r1, #(1<<12)                ; Clear I bit (disable L1 instruction caches)
armR5CacheEnableICaches_00:
    DSB
    MCR     p15, #0, r1, c1, c0, #0         ; Write modified SCTLR
    ISB
    BX      lr

;==============================================================================
;   void CSL_armR5StartupCacheEnableDCache( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupCacheEnableDCache
CSL_armR5StartupCacheEnableDCache:
    MRC     p15, #0, r1, c1, c0, #0         ; Read SCTLR
    CMP     r0, #0
    BEQ     armR5CacheEnableDCaches_disable
    ORR     r1, r1, #(1<<2)                 ; Set C bit (enable L1 data caches)
    DSB
    MOV     r2, #0
    MCR     p15, #0, r2, c15, c5, #0        ; Invalidate entire data cache
    B       armR5CacheEnableDCaches_00
armR5CacheEnableDCaches_disable:
    BIC     r1, r1, #(1<<2)                 ; Clear C bit (disable L1 data caches)
armR5CacheEnableDCaches_00:
    DSB
    MCR     p15, #0, r1, c1, c0, #0         ; Write modified SCTLR
    BX      lr

;==============================================================================
;   void CSL_armR5StartupCacheInvalidateAllIcache( void )
;==============================================================================
    .global CSL_armR5StartupCacheInvalidateAllIcache
CSL_armR5StartupCacheInvalidateAllIcache:
    DMB     ; Ensure all previous memory accesses are completed
    MOV     r0, #0
    MCR     p15, #0, r0, c7, c5, #0         ; Invalidate I caches
    DSB
    ISB
    BX      lr

;==============================================================================
;   void CSL_armR5StartupCacheInvalidateAllDcache( void )
;==============================================================================
    .global CSL_armR5StartupCacheInvalidateAllDcache
CSL_armR5StartupCacheInvalidateAllDcache:
    DMB     ; Ensure all previous memory accesses are completed
    MOV     r0, #0
    MCR     p15, #0, r0, c15, c5, #0        ; Invalidate D caches
    DSB
    ISB
    BX      lr

;==============================================================================
;   void CSL_armR5StartupCacheInvalidateAllCache( void )
;==============================================================================
    .global CSL_armR5StartupCacheInvalidateAllCache
CSL_armR5StartupCacheInvalidateAllCache:
    PUSH    {lr}
    BL      CSL_armR5StartupCacheInvalidateAllIcache
    BL      CSL_armR5StartupCacheInvalidateAllDcache
    POP     {lr}
    BX      lr

;==============================================================================
;   void CSL_armR5StartupMpuEnable( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupMpuEnable
CSL_armR5StartupMpuEnable:
    MRC     p15, #0, r1, c1, c0, #0         ; Read SCTLR (System Control Register)
    CMP     r0, #0
    BEQ     armR5MpuEnable_disable
    ORR     r1, r1, #0x1                    ; Set M bit to enable MPU
    B       armR5MpuEnable_00
armR5MpuEnable_disable:
    BIC     r1, r1, #0x1                    ; Clr M bit to disable MPU
armR5MpuEnable_00:
    DSB
    MCR     p15, #0, r1, c1, c0, #0         ; Write modified SCTLR
    ISB
    BX      lr

;==============================================================================
;   void CSL_armR5StartupMpuCfgRegion( uint32_t regionNum, uint32_t baseAddrRegVal, uint32_t sizeRegVal, uint32_t accessCtrlRegVal )
;==============================================================================
    .global CSL_armR5StartupMpuCfgRegion
CSL_armR5StartupMpuCfgRegion:
    AND     r0, r0, #0xF
    MCR     p15, #0, r0, c6, c2, #0         ; Write RGNR (MPU Region Number Register)
    BIC     r1, r1, #0x1F                   ; Base address must be 16-bit aligned
    MCR     p15, #0, r1, c6, c1, #0         ; Write MPU Region Base Address Register
    MCR     p15, #0, r2, c6, c1, #2         ; Write Data MPU Region Size and Enable Register
    MCR     p15, #0, r3, c6, c1, #4         ; Write MPU Region Access Control Register
    BX      lr

;==============================================================================
;   uint32_t CSL_armR5StartupReadMpidrReg(void )
;==============================================================================
    .global CSL_armR5StartupReadMpidrReg
CSL_armR5StartupReadMpidrReg:
    DMB
    MRC p15, #0, r0, c0, c0, #5 ; Read MPIDR
    BX        lr

;==============================================================================
;   void CSL_armR5StartupFpuEnable( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupFpuEnable
CSL_armR5StartupFpuEnable:
    MRC     p15, #0, r1, c1, c0, #2         ; Read CPACR into r1
    CMP     r0, #0
    BEQ     armR5FpuEnable_disable
    ORR     r1, r1, #(0xf << 20)            ; Enable full access for p10 & p11
    B       armR5FpuEnable_00
armR5FpuEnable_disable:
    BIC     r1, r1, #(0xf << 20)
armR5FpuEnable_00:
    MCR     p15, #0, r1, c1, c0, #2         ; Write back into CPACR
    ISB
    MOV     r0, #0x40000000
;    VMSR    FPEXC, r0                      ; Currently causing a build error
    BX      lr

;==============================================================================
;   void CSL_armR5StartupIntrEnableVic( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupIntrEnableVic
CSL_armR5StartupIntrEnableVic:
    MRC     p15, #0, r1, c1, c0, #0         ; Read SCTLR
    CMP     r0, #0
    BEQ     armR5IntrEnableVic_disable
    ORR     r1, r1, #(1<<24)                ; Set VE mask (VIC controller provides handler address for IRQ)
    B       armR5IntrEnableVic_00
armR5IntrEnableVic_disable:
    BIC     r1, r1, #(1<<24)                ; Clear VE mask (exception vector address for IRQ is 0x00000018 or 0xFFFF0018)
armR5IntrEnableVic_00:
    DSB
    MCR     p15, #0, r1, c1, c0, #0         ; Write modified SCTLR
    BX      lr

;==============================================================================
;   void CSL_armR5StartupIntrEnableFiq( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupIntrEnableFiq
CSL_armR5StartupIntrEnableFiq:
    MRS     r1, CPSR                        ; Read CPSR
    CMP     r0, #0
    BEQ     armR5IntrEnableFiq_disable
    BIC     r1, r1, #(1<<6)                 ; Clear FIQ mask (exception is not masked (is enabled))
    B       armR5IntrEnableFiq_00
armR5IntrEnableFiq_disable:
    ORR     r1, r1, #(1<<6)                 ; Set FIQ mask (exception is masked (is disabled))
armR5IntrEnableFiq_00:
    MSR     CPSR_c, r1                      ; Write CPSR (bits 7:0 only)
    BX      lr

;==============================================================================
;   void CSL_armR5StartupIntrEnableIrq( uint32_t enable )
;==============================================================================
    .global CSL_armR5StartupIntrEnableIrq
CSL_armR5StartupIntrEnableIrq:
    MRS     r1, CPSR                        ; Read CPSR
    CMP     r0, #0
    BEQ     armR5IntrEnableIrq_disable
    BIC     r1, r1, #(1<<7)                 ; Clear IRQ mask (exception is not masked (is enabled))
    B       armR5IntrEnableIrq_00
armR5IntrEnableIrq_disable:
    ORR     r1, r1, #(1<<7)                 ; Set IRQ mask (exception is masked (is disabled))
armR5IntrEnableIrq_00:
    MSR     CPSR_c, r1                      ; Write CPSR (bits 7:0 only)
    BX      lr

;==============================================================================
;   void CSL_armR5SetDLFOBit( void )
;==============================================================================
    .global CSL_armR5SetDLFOBit
CSL_armR5SetDLFOBit:
    PUSH    {r8}                ; Save r8 register contents
    MRC p15, #0, r8, c1, c0, #1 ; Read ACTRL register into r8
    ORR r8, r8, #(1<<13)        ; Set DLFO bit in ACTRL register
    MCR p15, #0, r8, c1, c0, #1 ; Write back ACTRL register
    POP     {r8}                ; Restore r8 register contents
    BX      lr

    .end
