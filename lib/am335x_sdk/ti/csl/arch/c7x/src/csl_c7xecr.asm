;;*****************************************************************************
;;  Copyright (C) 2019 Texas Instruments Incorporated - http:;;www.ti.com/
;;
;;  Redistribution and use in source and binary forms, with or without
;;  modification, are permitted provided that the following conditions
;;  are met:
;;
;;      Redistributions of source code must retain the above copyright
;;      notice, this list of conditions and the following disclaimer.
;;
;;      Redistributions in binary form must reproduce the above copyright
;;      notice, this list of conditions and the following disclaimer in the
;;      documentation and/or other materials provided with the
;;      distribution.
;;
;;      Neither the name of Texas Instruments Incorporated nor the names of
;;      its contributors may be used to endorse or promote products derived
;;      from this software without specific prior written permission.
;;
;;  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;;  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;;  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;;  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;;  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;;  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;;  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
;;  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;;  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;;  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;*****************************************************************************
	.global CSL_c7xSetL1DCFG
CSL_c7xSetL1DCFG:
	MVC	.S1	A4,		ECR256		;; L1D Cache Configuration Register
	RET	.B1



	.global CSL_c7xGetL1DCFG
CSL_c7xGetL1DCFG:
	MVC	.S1	ECR256,	A4	;; L1D Cache Configuration Register
	RET	.B1

	.global CSL_c7xSetL2CFG
CSL_c7xSetL2CFG:
	MVC	.S1	A4,		ECR384		;; L2 Cache Configuration Register
	RET	.B1



	.global CSL_c7xGetL2CFG
CSL_c7xGetL2CFG:
	MVC	.S1	ECR384,	A4	;; L2 Cache Configuration Register
	RET	.B1

	.global CSL_c7xSetL1DINV
CSL_c7xSetL1DINV:
	MVC	.S1	A4,		ECR260		;; L1D Invalidate Register
	RET	.B1



	.global CSL_c7xGetL1DINV
CSL_c7xGetL1DINV:
	MVC	.S1	ECR260,	A4	;; L1D Invalidate Register
	RET	.B1



	.global CSL_c7xSetL2INV
CSL_c7xSetL2INV:
	MVC	.S1	A4,		ECR388		;; L2 Invalidate Register
	RET	.B1



	.global CSL_c7xGetL2INV
CSL_c7xGetL2INV:
	MVC	.S1	ECR388,	A4	;; L2 Invalidate Register
	RET	.B1


	.global CSL_c7xSetL1DWBINV
CSL_c7xSetL1DWBINV:
	MVC	.S1	A4,		ECR259		;; L1D Global Writeback Invalidate Register
	RET	.B1



	.global CSL_c7xGetL1DWBINV
CSL_c7xGetL1DWBINV:
	MVC	.S1	ECR259,	A4	;; L1D Global Writeback Invalidate Register
	RET	.B1


	.global CSL_c7xSetMAR
CSL_c7xSetMAR:
	MVC	.S1	A4,		ECR789		;; Memory Attribute Register
	RET	.B1

	.global CSL_c7xSetL2WBINV
CSL_c7xSetL2WBINV:
	MVC	.S1	A4,		ECR387		;; L2 Global Writeback Invalidate Register
	RET	.B1



	.global CSL_c7xGetL2WBINV
CSL_c7xGetL2WBINV:
	MVC	.S1	ECR387,	A4	;; L2 Global Writeback Invalidate Register
	RET	.B1

	.global CSL_c7xSetTCR0_GS
CSL_c7xSetTCR0_GS:
	MVC	.S1	A4,		ECR801		;; Table Control Register 0 - Non-Secure Guest Supervisor
	RET	.B1



	.global CSL_c7xGetTCR0_GS
CSL_c7xGetTCR0_GS:
	MVC	.S1	ECR801,	A4	;; Table Control Register 0 - Non-Secure Guest Supervisor
	RET	.B1

	.global CSL_c7xSetTBR0_GS
CSL_c7xSetTBR0_GS:
	MVC	.S1	A4,		ECR803		;; Table Base Register 0 - Non-Secure Guest Supervisor
	RET	.B1



	.global CSL_c7xGetTBR0_GS
CSL_c7xGetTBR0_GS:
	MVC	.S1	ECR803,	A4	;; Table Base Register 0 - Non-Secure Guest Supervisor
	RET	.B1


	.global CSL_c7xSetSCR
CSL_c7xSetSCR:
	MVC	.S1	A4,		ECR784		;; System Control Register
	RET	.B1
