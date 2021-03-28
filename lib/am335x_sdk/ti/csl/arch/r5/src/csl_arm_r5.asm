;******************************************************************************
;  @file  csl_arm_r5.asm
;
;  @brief
;   Implementation file for the ARM R5 module CSL-FL.
;
;   Contains the different control command and status query functions definitions
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

;==============================================================================
;   void CSL_armR5Dsb( void )
;==============================================================================
    .global CSL_armR5Dsb
CSL_armR5Dsb:
    DSB
    BX      lr

;==============================================================================
;   void CSL_armR5FpuEnable( uint32_t enable )
;==============================================================================
    .global CSL_armR5FpuEnable
CSL_armR5FpuEnable:
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
;   void CSL_armR5IntrEnableFiq( uint32_t enable )
;==============================================================================
    .global CSL_armR5IntrEnableFiq
CSL_armR5IntrEnableFiq:
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
;   void CSL_armR5IntrEnableIrq( uint32_t enable )
;==============================================================================
    .global CSL_armR5IntrEnableIrq
CSL_armR5IntrEnableIrq:
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
;   void CSL_armR5IntrEnableVic( uint32_t enable )
;==============================================================================
    .global CSL_armR5IntrEnableVic
CSL_armR5IntrEnableVic:
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
;   void CSL_armR5CacheEnableICache( uint32_t enable )
;==============================================================================
    .global CSL_armR5CacheEnableICache
CSL_armR5CacheEnableICache:
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
;   void CSL_armR5CacheEnableDCache( uint32_t enable )
;==============================================================================
    .global CSL_armR5CacheEnableDCache
CSL_armR5CacheEnableDCache:
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
;   uint32_t CSL_armR5CacheGetIcacheLineSize(void )
;==============================================================================
    .global CSL_armR5CacheGetIcacheLineSize
CSL_armR5CacheGetIcacheLineSize:
    DMB
    MRC       p15, #0, r0, c0, c0, #1   ; Read Cache Type Register
    UBFX      r0, r0, #0, #4           ; Extract the iMinLine
    MOV       r1, #1
    LSL       r0, r1, r0                ; Calculate the line size
    BX        lr

;==============================================================================
;   uint32_t CSL_armR5CacheGetDcacheLineSize(void )
;==============================================================================
    .global CSL_armR5CacheGetDcacheLineSize
CSL_armR5CacheGetDcacheLineSize:
    DMB
    MRC       p15, #0, r0, c0, c0, #1   ; Read Cache Type Register
    UBFX      r0, r0, #16, #4           ; Extract the DMinLine
    MOV       r1, #1
    LSL       r0, r1, r0                ; Calculate the line size
    BX        lr

;==============================================================================
;   void CSL_armR5CacheEnableAllCache( uint32_t enable )
;==============================================================================
    .global CSL_armR5CacheEnableAllCache
CSL_armR5CacheEnableAllCache:
    PUSH    {lr}
    BL      CSL_armR5CacheEnableICache
    BL      CSL_armR5CacheEnableDCache
    POP     {lr}
    BX      lr

;==============================================================================
;   void CSL_armR5CacheInvalidateAllIcache( void )
;==============================================================================
    .global CSL_armR5CacheInvalidateAllIcache
CSL_armR5CacheInvalidateAllIcache:
    DMB     ; Ensure all previous memory accesses are completed
    MOV     r0, #0
    MCR     p15, #0, r0, c7, c5, #0         ; Invalidate I caches
    DSB
    ISB
    BX      lr

;==============================================================================
;   void CSL_armR5CacheInvalidateAllDcache( void )
;==============================================================================
    .global CSL_armR5CacheInvalidateAllDcache
CSL_armR5CacheInvalidateAllDcache:
    DMB     ; Ensure all previous memory accesses are completed
    MOV     r0, #0
    MCR     p15, #0, r0, c15, c5, #0        ; Invalidate D caches
    DSB
    ISB
    BX      lr

;==============================================================================
;   void CSL_armR5CacheInvalidateAllCache( void )
;==============================================================================
    .global CSL_armR5CacheInvalidateAllCache
CSL_armR5CacheInvalidateAllCache:
    PUSH    {lr}
    BL      CSL_armR5CacheInvalidateAllIcache
    BL      CSL_armR5CacheInvalidateAllDcache
    POP     {lr}
    BX      lr

;==============================================================================
;   void CSL_armR5CacheInvalidateIcacheMva( uint32_t address )
;==============================================================================
    .global CSL_armR5CacheInvalidateIcacheMva
CSL_armR5CacheInvalidateIcacheMva:
    DMB     ; Ensure all previous memory accesses are completed
    MCR     p15, #0, r0, c7, c5, #1
    DSB
    BX      lr

;==============================================================================
;   void CSL_armR5CacheInvalidateDcacheMva( uint32_t address )
;==============================================================================
    .global CSL_armR5CacheInvalidateDcacheMva
CSL_armR5CacheInvalidateDcacheMva:
    DMB     ; Ensure all previous memory accesses are completed
    MCR     p15, #0, r0, c7, c6, #1
    DSB
    BX      lr

;==============================================================================
;   void CSL_armR5CacheInvalidateDcacheSetWay( uint32_t set, uint32_t way )
;==============================================================================
    .global CSL_armR5CacheInvalidateDcacheSetWay
CSL_armR5CacheInvalidateDcacheSetWay:
    DMB     ; Ensure all previous memory accesses are completed
    AND     r1, r1, #0x3
    LSL     r0, #(32-9)
    LSR     r0, #(32-9)                     ; set &= 0x1FF
    LSL     r1, r1, #30
    ORR     r0, r1, r0, LSL #5
    MCR     p15, #0, r0, c7, c6, #2
    DSB
    BX      lr

;==============================================================================
;   void CSL_armR5CacheCleanDcacheMva( uint32_t address )
;==============================================================================
    .global CSL_armR5CacheCleanDcacheMva
CSL_armR5CacheCleanDcacheMva:
    DMB     ; Ensure all previous memory accesses are completed
    MCR     p15, #0, r0, c7, c10, #1
    DSB

    BX      lr

;==============================================================================
;   void CSL_armR5CacheCleanDcacheSetWay( uint32_t set, uint32_t way )
;==============================================================================
    .global CSL_armR5CacheCleanDcacheSetWay
CSL_armR5CacheCleanDcacheSetWay:
    DMB     ; Ensure all previous memory accesses are completed
    AND     r1, r1, #0x3
    LSL     r0, #(32-9)
    LSR     r0, #(32-9)                     ; set &= 0x1FF
    LSL     r1, r1, #30
    ORR     r0, r1, r0, LSL #5
    MCR     p15, #0, r0, c7, c10, #2
    DSB
    BX      lr

;==============================================================================
;   void CSL_armR5CacheCleanInvalidateDcacheMva( uint32_t address )
;==============================================================================
    .global CSL_armR5CacheCleanInvalidateDcacheMva
CSL_armR5CacheCleanInvalidateDcacheMva:
    MCR     p15, #0, r0, c7, c14, #1
    BX      lr

;==============================================================================
;   void CSL_armR5CacheCleanInvalidateDcacheSetWay( uint32_t set, uint32_t way )
;==============================================================================
    .global CSL_armR5CacheCleanInvalidateDcacheSetWay
CSL_armR5CacheCleanInvalidateDcacheSetWay:
    DMB     ; Ensure all previous memory accesses are completed
    AND     r1, r1, #0x3
    LSL     r0, #(32-9)
    LSR     r0, #(32-9)                     ; set &= 0x1FF
    LSL     r1, r1, #30
    ORR     r0, r1, r0, LSL #5
    MCR     p15, #0, r0, c7, c14, #2
    DSB
    BX      lr

;==============================================================================
;   void CSL_armR5CacheEnableForceWrThru( uint32_t enable )
;==============================================================================
    .global CSL_armR5CacheEnableForceWrThru
CSL_armR5CacheEnableForceWrThru:
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
;   void CSL_armR5CacheDisableEcc( void )
;==============================================================================
    .global CSL_armR5CacheDisableEcc
CSL_armR5CacheDisableEcc:
    PUSH    {lr}
    MOV     r0, #0
    BL      CSL_armR5CacheEnableAllCache    ; Disable instruction and data caches

    MRC     p15, #0, r0, c1, c0, #1         ; Read Auxiliary Control register
    BIC     r0, r0, #(0x7<<3)               ; Clear CEC field
    ORR     r0, r0, #(1<<5)                 ; Set CEC field to 3'b100 (disable parity checking)
    ORR     r0, r0, #(1<<9)                 ; Enable Write Through Cache RAMS
    MCR     p15, #0, r0, c1, c0, #1         ; Write Auxiliary Control register

    BL      CSL_armR5CacheInvalidateAllCache
    MOV     r0, #1
    BL      CSL_armR5CacheEnableAllCache    ; Enable instruction and data caches
    POP     {lr}
    BX      lr

;==============================================================================
;   void CSL_armR5CacheEnableAxiAccess( void )
;==============================================================================
    .global CSL_armR5CacheEnableAxiAccess
CSL_armR5CacheEnableAxiAccess:
    MRC     p15, #0, r0, c1, c0, #1         ; Read Auxiliary Control register
    ORR     r0, r0, #(1<<24)                ; Set AXISCEN bit (enable AXI slave cache RAM access)
    MCR     p15, #0, r0, c1, c0, #1         ; Write Auxiliary Control register
    BX      lr

;==============================================================================
;   uint32_t CSL_armR5ReadMpidrReg(void )
;==============================================================================
    .global CSL_armR5ReadMpidrReg
CSL_armR5ReadMpidrReg:
    DMB
    MRC p15, #0, r0, c0, c0, #5 ; Read MPIDR
    BX        lr

;==============================================================================
;   uintptr_t CSL_armR5GetCpsrRegVal( void );
;==============================================================================
    .global CSL_armR5GetCpsrRegVal
CSL_armR5GetCpsrRegVal:
    MRS     r0, CPSR                        ; Read CPSR
    BX      lr

irq_fiq_set_mask		 .word 0xFFFFFF3F
irq_fiq_clear_mask		 .word 0x000000C0
;==============================================================================
;   void CSL_armR5DisableIrqFiq( void );
;==============================================================================
    .global CSL_armR5DisableIrqFiq
CSL_armR5DisableIrqFiq:
    LDR     r0, irq_fiq_clear_mask       ; Mask for clearing IRQ and FIQ bits
    MRS     r1, CPSR                     ; Read CPSR
    ORR     r1, r1, r0                   ; Clear IRQ and FIQ bits only
    MSR     CPSR_c, r1                   ; Write CPSR (bits 7:6 only)
    BX      lr

;==============================================================================
;   void CSL_armR5EnableIrqFiq( uintptr_t cookie );
;==============================================================================
    .global CSL_armR5EnableIrqFiq
CSL_armR5EnableIrqFiq:
    LDR     r2, irq_fiq_set_mask         ; Mask out other bits than IRQ and FIQ
    MRS     r1, CPSR                     ; Read CPSR
    AND     r1, r1, r2
    LDR     r2, irq_fiq_clear_mask       ; Mask out other bits than IRQ and FIQ
    AND     r0, r0, r2                   ; set/clear IRQ and FIQ bits
    ORR     r1, r1, r0
    MSR     CPSR_c, r1                   ; Write CPSR (bits 7:6 only)
    BX      lr

    .end
