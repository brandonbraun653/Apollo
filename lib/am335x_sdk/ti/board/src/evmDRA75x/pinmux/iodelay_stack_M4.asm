;/******************************************************************************
; * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
; *
; *  Redistribution and use in source and binary forms, with or without
; *  modification, are permitted provided that the following conditions
; *  are met:
; *
; *    Redistributions of source code must retain the above copyright
; *    notice, this list of conditions and the following disclaimer.
; *
; *    Redistributions in binary form must reproduce the above copyright
; *    notice, this list of conditions and the following disclaimer in the
; *    documentation and/or other materials provided with the
; *    distribution.
; *
; *    Neither the name of Texas Instruments Incorporated nor the names of
; *    its contributors may be used to endorse or promote products derived
; *    from this software without specific prior written permission.
; *
; *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
; *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
; *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
; *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; *
; *****************************************************************************/

; **********************************************************************************************
; * iodelay_stack_M4.asm:    Swap out stack with dedicated SRAM IO stack                       *
; **********************************************************************************************
;
; **********************************************************************************************
; * Calling format:                                                                            *
; * void Board_ioStack(void *sp,                                                               *
; *                    void(fn)(const boardPadDelayCfg_t *pPadCfgData, uint32_t padArraySize), *
; *                    const boardPadDelayCfg_t *pPadCfgData,                                  *
; *                    uint32_t padArraySize);                                                 *
; *                                                                                            *
; * r0:   pointer to new stack base                                                            *
; * r1:   pointer to pad delay config function                                                 *
; * r2:   pointer to pad delay config data                                                     *
; * r3:   size of pad delay config                                                             *
; **********************************************************************************************

    .global Board_ioStack

Board_ioStack:    .sect "BOARD_IO_DELAY_CODE"
    push    {r4, lr}            ; Preserve R4 and LR on stack
    mov     r4, r0              ; Preserve stack base in temporary register
    str     r13, [r4, #-4]      ; Push application stack pointer into SRAM stack
    sub     r13, r4, #8         ; Change stack pointer to SRAM stack
    mov     r0, r2              ; Cycle arguments for next function call: first arg is pad config data
    mov     r2, r1              ; Store BoardCtrlPadIoDelayConfig address for branch statement below
    mov     r1, r3              ; Second arg is the number of entries in the pad config data
    blx     r2                  ; Branch to BoardCtrlPadIoDelayConfig, update link
    ldr     r13, [r4, #-4]      ; Pop application stack pointer
    pop     {r4, lr}            ; Restore R4 and LR
    bx      lr                  ; Return to original calling context
