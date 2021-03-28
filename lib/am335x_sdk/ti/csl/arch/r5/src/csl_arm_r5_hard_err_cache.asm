;******************************************************************************
;  @file  csl_arm_r5_hard_err_cache.asm
;
;  @brief
;   Implementation file for the ARM R5 hard error cache module CSL-FL.
;
;   Contains the different control command and status query functions definitions
;
;   \par
;   ============================================================================
;   @n   (C) Copyright 2019, Texas Instruments, Inc.
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
;   uint32_t CSL_armR5ReadATCMRegionRegister(void)
;
;   Requirement: REQ_TAG(PRSDK-1673)
;   Design Id: (did_csl_core_hard_err_cache_access)
;==============================================================================
    .global CSL_armR5ReadATCMRegionRegister
CSL_armR5ReadATCMRegionRegister:
    MRC     p15, #0, r0, c9, c1, #1        ; Read ATCM Register Register
    BX      lr

;==============================================================================
;   uint32_t CSL_armR5ReadBTCMRegionRegister(void)
;
;   Requirement: REQ_TAG(PRSDK-1673)
;   Design Id: (did_csl_core_hard_err_cache_access)
;==============================================================================
    .global CSL_armR5ReadBTCMRegionRegister
CSL_armR5ReadBTCMRegionRegister:
    MRC     p15, #0, r0, c9, c1, #0        ; Read BTCM Register Register
    BX      lr

;==============================================================================
;   void_t CSL_armR5WriteATCMRegionRegister(uint32_t value)
;
;   Requirement: REQ_TAG(PRSDK-1673)
;   Design Id: (did_csl_core_hard_err_cache_access)
;==============================================================================
    .global CSL_armR5WriteATCMRegionRegister
CSL_armR5WriteATCMRegionRegister:
    MCR     p15, #0, r0, c9, c1, #1        ; Write ATCM Register Register
    BX      lr

;==============================================================================
;   void  CSL_armR5WriteBTCMRegionRegister(uint32_t value)
;
;   Requirement: REQ_TAG(PRSDK-1673)
;   Design Id: (did_csl_core_hard_err_cache_access)
;==============================================================================
    .global CSL_armR5WriteBTCMRegionRegister
CSL_armR5WriteBTCMRegionRegister:
    MCR     p15, #0, r0, c9, c1, #0        ; Write BTCM Register Register
    BX      lr

;==============================================================================
;   void CSL_armR5CacheEnableHardErrCache (uint32_t enable)
;
;   Requirement: REQ_TAG(PRSDK-1673)
;   Design Id: (did_csl_core_hard_err_cache_access)
;==============================================================================
    .global CSL_armR5CacheEnableHardErrCache
CSL_armR5CacheEnableHardErrCache:
    MRC     p15, #0, r1, c15, c0, #0       ; Read Secondary Auxiliary Control Register
    CMP     r0, #0
    BEQ     armR5HardErrCache_disable
    BIC     r1, r1, #(1<<22)               ; Enabled. The cache logic recovers from some hard errors.
    B       armR5HardErrCache_set
armR5HardErrCache_disable:
    ORR     r1, r1, #(1<<22)               ; Disabled. Most hard errors in the caches are fatal.
armR5HardErrCache_set:
    DSB
    MCR     p15, #0, r1, c15, c0, #0       ; Write Secondary Auxiliary Control Register
    BX      lr


    .end
