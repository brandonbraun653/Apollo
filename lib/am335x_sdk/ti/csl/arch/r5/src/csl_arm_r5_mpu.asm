;******************************************************************************
;  @file  csl_arm_r5_mpu.asm
;
;  @brief
;   Implementation file for the ARM R5 MPU module CSL-FL.
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
;   void CSL_armR5MpuEnable( uint32_t enable )
;
;   Requirement: REQ_TAG(PRSDK-1663)
;   Design: did_csl_core_mpu_configure
;==============================================================================
    .global CSL_armR5MpuEnable
CSL_armR5MpuEnable:
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
;   uint32_t CSL_armR5MpuGetNumRegions( void )
;
;   Requirement: REQ_TAG(PRSDK-1663)
;   Design: did_csl_core_mpu_read
;==============================================================================
    .global CSL_armR5MpuGetNumRegions
CSL_armR5MpuGetNumRegions:
    MRC     p15, #0, r0, c0, c0, #4         ; Read MPUIR (MPU Type Register)
    LSR     r0, r0, #8                      ; Shift and
    AND     r0, r0, #0xFF                   ;   mask to get DRegion
    BX      lr

;==============================================================================
;   void CSL_armR5MpuCfgRegion( uint32_t regionNum, uint32_t baseAddrRegVal, uint32_t sizeRegVal, uint32_t accessCtrlRegVal )
;
;   Requirement: REQ_TAG(PRSDK-1663)
;   Design: did_csl_core_mpu_configure
;==============================================================================
    .global CSL_armR5MpuCfgRegion
CSL_armR5MpuCfgRegion:
    AND     r0, r0, #0xF
    MCR     p15, #0, r0, c6, c2, #0         ; Write RGNR (MPU Region Number Register)
    BIC     r1, r1, #0x1F                   ; Base address must be 16-bit aligned
    MCR     p15, #0, r1, c6, c1, #0         ; Write MPU Region Base Address Register
    MCR     p15, #0, r2, c6, c1, #2         ; Write Data MPU Region Size and Enable Register
    MCR     p15, #0, r3, c6, c1, #4         ; Write MPU Region Access Control Register
    BX      lr

;==============================================================================
;   int32_t CSL_armR5MpuVerifyCfgRegion( uint32_t regionNum, uint32_t baseAddrRegVal, uint32_t sizeRegVal, uint32_t accessCtrlRegVal )
;
;   Requirement: REQ_TAG(PRSDK-1663)
;   Design: did_csl_core_mpu_check
;==============================================================================
    .global CSL_armR5MpuVerifyCfgRegion
CSL_armR5MpuVerifyCfgRegion:
    PUSH    {r4}
    MRC     p15, #0, r4, c6, c2, #0         ; Read RGNR (MPU Region Number Register)
    AND     r4, r4, #0xF
    SUBS    r0, r4, r0
    BEQ     armR5MpuVerifyCfgRegion_pass1
    MVN     r0, #0x0                        ; -1 in return value
    B       armR5MpuVerifyCfgRegion_done

armR5MpuVerifyCfgRegion_pass1:
    MRC     p15, #0, r4, c6, c1, #0         ; Read MPU Region Base Address Register
    BIC     r4, r4, #0x1F                   ; Base address must be 16-bit aligned
    CMP     r1, r4
    BEQ     armR5MpuVerifyCfgRegion_pass2
    MVN     r0, #0x0                        ; -1 in return value
    B       armR5MpuVerifyCfgRegion_done

armR5MpuVerifyCfgRegion_pass2:
    MRC     p15, #0, r4, c6, c1, #2         ; Read Data MPU Region Size and Enable Register
    BFC     r4,  #16, #16
    BFC     r4,  #6,  #2
    CMP     r2, r4
    BEQ     armR5MpuVerifyCfgRegion_pass3
    MVN     r0, #0x0                        ; -1 in return value
    B       armR5MpuVerifyCfgRegion_done

armR5MpuVerifyCfgRegion_pass3:
    MRC     p15, #0, r4, c6, c1, #4         ; Read MPU Region Access Control Register
    BFC     r4,  #13, #18
    BFC     r4,  #11, #1
    BFC     r4,  #6, #2
    CMP     r3, r4
    BEQ     armR5MpuVerifyCfgRegion_done
    MVN     r0, #0x0                        ; -1 in return value

armR5MpuVerifyCfgRegion_done:
    ISB
    POP     {r4}
    BX      lr
;==============================================================================
;   void CSL_armR5MpuEnableRegion( uint32_t regionNum, uint32_t enable );
;
;   Requirement: REQ_TAG(PRSDK-1663)
;   Design: did_csl_core_mpu_configure
;==============================================================================
    .global CSL_armR5MpuEnableRegion
CSL_armR5MpuEnableRegion:
    AND     r0, r0, #0xF
    MCR     p15, #0, r0, c6, c2, #0         ; Write RGNR (MPU Region Number Register)
    MRC     p15, #0, r2, c6, c1, #2         ; Read Data MPU Region Size and Enable Register
    CMP     r1, #0
    BEQ     armR5MpuEnableRegion_disable
    ORR     r2, r2, #0x1                    ; Set Enable bit to enable MPU region
    B       armR5MpuEnableRegion_00
armR5MpuEnableRegion_disable:
    BIC     r2, r2, #0x1                    ; Clr Enable bit to disable MPU region
armR5MpuEnableRegion_00:
    DSB
    MCR     p15, #0, r2, c6, c1, #2         ; Write modified Data MPU Region Size and Enable Register
    ISB
    BX      lr

;==============================================================================
;   int32_t CSL_armR5MpuVerifyEnableRegion( uint32_t regionNum, uint32_t enable );
;
;   Requirement: REQ_TAG(PRSDK-1663)
;   Design: did_csl_core_mpu_check
;==============================================================================
    .global CSL_armR5MpuVerifyEnableRegion
CSL_armR5MpuVerifyEnableRegion:
    MRC     p15, #0, r2, c6, c2, #0         ; Read RGNR (MPU Region Number Register)
    AND     r2, r2, #0xF                    ; get the Region number

    SUBS    r0, r0, r2
    BEQ     armR5MpuVerifyRegion_pass
    MVN     r0, #0x0                        ; -1 in return value
    B       armR5MpuVerifyRegion_done
armR5MpuVerifyRegion_pass:

    MRC     p15, #0, r2, c6, c1, #2         ; Read Data MPU Region Size and Enable Register
    AND     r2, r2, #0x1                    ; Get the enable bit

    SUBS    r0, r1, r2
    BEQ     armR5MpuVerifyRegion_done
    MVN     r0, #0x0                        ; -1 in return value
armR5MpuVerifyRegion_done:
    ISB
    BX      lr

   .end
