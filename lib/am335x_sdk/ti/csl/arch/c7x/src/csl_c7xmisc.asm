;;*****************************************************************************
;;  Copyright (C) 2018 Texas Instruments Incorporated - http:;;www.ti.com/
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
	.global CSL_c7xL1PCacheInvalidateAll
CSL_c7xL1PCacheInvalidateAll:
	IINVAL 0x3				;; CPU instruction to invalidate all L1P content
	RET	.B1


    ;; uint64_t CSL_c7xSecSupv2NonSecSupv(void);
    .global CSL_c7xSecSupv2NonSecSupv
CSL_c7xSecSupv2NonSecSupv:
        ;; Allow all events to be handled as interrupts in non-secure mode
        MVK64   .L1    0h,  A2
        MVC     .S1    A2,  ECLMR
        MVK64   .L1    0h, A2
        MVC     .S1    A2,  EASGR

        ;; now switch to non-secure supervisor mode
        MVC     .S1    TSR, A1
        MVK64   .L1    0fffffffffffffff8h, A2       ;; save all bits except [2:0]
        ANDD    .L1    A1, A2, A3

        ORD     .L1    A3, 03h, A3

        MVC            .S1 RP, A2
        MVK64   .L1     1, A4
        RETE    .S1    A2, A3

