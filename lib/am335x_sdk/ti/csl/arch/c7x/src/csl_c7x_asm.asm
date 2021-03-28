;   ============================================================================
;   @n   (C) Copyright 2018, Texas Instruments, Inc.
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

        .global CSL_c7xGetCpuMode
CSL_c7xGetCpuMode:
        MVC    .S1      TSR,            A4
        MVK64  .S1      0x7,            A2
	ANDD   .L1      A4,     A2,     A4
	RET    .B1

	.global CSL_c7xMmuTlbInvByASID
CSL_c7xMmuTlbInvByASID:
      MVK64   .L1     0xff, AL0                 ;; AL0 has ASID mask
      ANDD    .L1     A4, AL0, A4               ;; A4 has ASID to begin with. zero out except ASID[7:0]
      SHLD    .L1     A4, 48, A4                ;; A4 has ASID in bits [55:48]
      MVK64   .L1     0x0000008000000000, AL0   ;; AL0 has TLB_INV_TYPE_BY_ASID
      ORD     .L1     AL0, A4, A4               ;; A4 has ASID, OR it with TLB_INV_TYPE_BY_ASID and write it to TLB_INV reg
      MVC     .S1     A4, TLB_INV               ;; final A4 value is moved to TLB_INV register
      RET     .B1


	.global CSL_c7xMmuTlbInvLL
CSL_c7xMmuTlbInvLL:
        MVK64   .L1     0x0000002000000000, A4   ;; AL0 has TLB_INV_TYPE_LL
	MVC     .S1     A4, TLB_INV              ;; final A4 value is moved to TLB_INV register
	RET	.B1

	.global CSL_c7xMmuTlbInvByVA
CSL_c7xMmuTlbInvByVA:
      MVK64   .L1     0x1ffffffffffff, AL0      ;; AL0 has VA[48:0] mask
      ANDD    .L1     A4, AL0, A4               ;; A4 has VA to begin with. zero out VA[63:49]
      SHRD    .L1     A4, 12, A4                ;; A4 has VA[48:12]
      MVK64   .L1     0x0000004000000000, AL0   ;; AL0 has TLB_INV_TYPE_BY_VA
      ORD     .L1     AL0, A4, A4               ;; A4 has VA, OR it with TLB_INV_TYPE_BY_VA and write it to TLB_INV reg
      MVC     .S1     A4, TLB_INV               ;; final A4 value is moved to TLB_INV register
      RET     .B1


	.global CSL_c7xMmuTlbInvAll
CSL_c7xMmuTlbInvAll:                               ;; writing 0's to TLB_INV invalidates entire TLB
        ANDD    .L1     A4, 0x0, A4
	MVC     .S1     A4, TLB_INV
	RET	.B1

	.global CSL_c7xMmuGetErrInfo
CSL_c7xMmuGetErrInfo:
	MVC	.S1	A4,		ECR772      ;; Get response status
	RET	.B1

	.global CSL_c7xMmuHwModeEnable
CSL_c7xMmuHwModeEnable:                          ;; enables MMU HW mode by writing 1 to bit SCR[63]
        MVK64   .L1     0x8000000000000000, AL0
	MVC	.S1	ECR784,	 A4
	ORD     .L1     AL0, A4, A4
	MVC     .S1     A4, ECR784
	RET	.B1

	.global CSL_c7xMmuHwModeEnableGS
CSL_c7xMmuHwModeEnableGS:                        ;; enables MMU HW mode by writing 1 to bit SCR_GS[63]
        MVK64   .L1     0x8000000000000000, AL0
	MVC	.S1	ECR800,	 A4
	ORD     .L1     AL0, A4, A4
	MVC     .S1     A4, ECR800
	RET	.B1

	.global CSL_c7xMmuHwModeEnableS
CSL_c7xMmuHwModeEnableS:                         ;; enables MMU HW mode by writing 1 to bit SCR_S[63]
        MVK64   .L1     0x8000000000000000, AL0
	MVC	.S1	ECR816,	 A4
	ORD     .L1     AL0, A4, A4
	MVC     .S1     A4, ECR816
	RET	.B1

	.global CSL_c7xMmuIsHwModeEnabled
CSL_c7xMmuIsHwModeEnabled:                       ;; reads SCR[63] to determine if HW mode is enabled
        MVK64   .L1     0x8000000000000000, AL0
	MVC	.S1	ECR784,	 A4
	ANDD    .L1     AL0, A4, A4
	CMPEQW  .L1     A4, AL0, A4
	RET	.B1

	.global CSL_c7xMmuIsHwModeEnabledGS
CSL_c7xMmuIsHwModeEnabledGS:                     ;; reads SCR_GS[63] to determine if HW mode is enabled
        MVK64   .L1     0x8000000000000000, AL0
	MVC	.S1	ECR816,	 A4
	ANDD    .L1     AL0, A4, A4
	CMPEQW  .L1     A4, AL0, A4
	RET	.B1

	.global CSL_c7xMmuIsHwModeEnabledS
CSL_c7xMmuIsHwModeEnabledS:                     ;; reads SCR_GS[63] to determine if HW mode is enabled
        MVK64   .L1     0x8000000000000000, AL0
	MVC	.S1	ECR816,	 A4
	ANDD    .L1     AL0, A4, A4
	CMPEQW  .L1     A4, AL0, A4
	RET	.B1

    .global CSL_c7xFenceAll
CSL_c7xFenceAll:
    MFENCE   0x1F ;
    RET     .B1
