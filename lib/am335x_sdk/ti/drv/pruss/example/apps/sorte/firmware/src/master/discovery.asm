; Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
;
; Redistributions of source code must retain the above copyright
; notice, this list of conditions and the following disclaimer.
;
; Redistributions in binary form must reproduce the above copyright
; notice, this list of conditions and the following disclaimer in the
; documentation and/or other materials provided with the
; distribution.
;
; Neither the name of Texas Instruments Incorporated nor the names of
; its contributors may be used to endorse or promote products derived
; from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
; OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
; LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
; DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;     file:   discovery.asm
;
;     brief: contains the DISCOVERY state implementation
;
;    Version        Description                                Author
;     0.1         Created                                      Thomas Mauer,Thomas Leyrer
;include section
    .include "../include/macros/macros.inc"
    .include "../include/icss/icss_regs.inc"
    .include "../include/protocol/sorte_pru_master_register.inc"
    .include "../include/protocol/sorte_master_cfg.inc"

    .global FN_DISC_RCV
    .global IDLE_WAIT_FOR_LINK_ACTIVE

; ------------------------------------------------------------------------------
; state: DISCOVERY
; Regsiter defines:
; n = TEMP_REG_4.b0 (iterations)
; m = TEMP_REG_4.b1 (counter for 32 bytes blocks in payload field)
; previous cycle counter = TEMP_REG_3
; tx_fifo_bytes_inserted = TEMP_REG_4.w2
; rx_bytes_received = TEMP_REG_6.w0
; rx_packet_cnt = TEMP_REG_6.b2
; rx_blocks_rcvd = TEMP_REG_6.b3
; ------------------------------------------------------------------------------

; ------------------------------------------------------------------------------
; FUNCTION: FN_DISC_RCV
; ARGS:
; Description: receive DISCOVERY packet from MII port to ICSS shared RAM
;              This function is called from various locations/timings of
;               transmitting DICOVERY packet.
;               rx_packet_cnt is used to indicate start of frame
; ------------------------------------------------------------------------------

FN_DISC_RCV:

; check status of receive
; FB = fisrt block, NB = next block, LB = last block
; DISCOVERY packet size is 4/8 bytes pre-amble + 1022 bytes frame + 4 bytes FCS

    xin        RXL2_BANK0, &R18, 1

; check if 32 blocks are received to jump to last block processing
    qbeq    DISC_RX_LB, TEMP_REG_6.b3, 32

; first block and next block processing
; check RX_FIFO_LEVEL, start receiving packet when more than 32 bytes are received
    qbbs    DISC_CHECK_BANK1,TEMP_REG_6,5
; check BANK0
    qbgt    DISC_RX_BLOCK_SKIP, r18.b0, 34
    xin     RXL2_BANK0, &R2, 32+16
    ldi     TEMP_REG_1.w0, DISCOV_RX_OFFSET
    add     TEMP_REG_1.w0, TEMP_REG_1.w0, TEMP_REG_6.w0
    sbco    &R2,PRU0_DMEM_CONST, TEMP_REG_1.w0, 32
    add     TEMP_REG_6.w0, TEMP_REG_6.w0, 32
    qba     DISC_RX_BLOCK_DONE

DISC_CHECK_BANK1:
;check BANK 1
    qblt    DISC_RX_BLOCK_SKIP, r18.b0, 32
    xin     RXL2_BANK1, &R2, 32+16
    ldi     TEMP_REG_1.w0, DISCOV_RX_OFFSET
    add     TEMP_REG_1.w0, TEMP_REG_1.w0, TEMP_REG_6.w0
    sbco    &R2,PRU0_DMEM_CONST, TEMP_REG_1.w0, 32
    add     TEMP_REG_6.w0, TEMP_REG_6.w0, 32

DISC_RX_BLOCK_DONE:
    add     TEMP_REG_6.b3,TEMP_REG_6.b3, 1
; save last rx fifo level
DISC_RX_BLOCK_SKIP:
    mov     r18.b1, r18.b0
    RET

DISC_RX_LB:

; check on RX_EOF
    xin     RXL2_BANK0, &R18, 1
    qbeq    DISC_RX_EOF, r18.b0, r18.b1
    mov     r18.b1, r18.b0

; check on length error
    qblt    DISC_RX_ERROR, r18.b0, 32
    RET

DISC_RX_EOF:
    xin     RXL2_BANK0, &R2, 32+16
    ldi     TEMP_REG_1.w0, DISCOV_RX_OFFSET
    add     TEMP_REG_1.w0, TEMP_REG_1.w0, TEMP_REG_6.w0
    sbco    &R2,PRU0_DMEM_CONST, TEMP_REG_1.w0, 32+16
    add     TEMP_REG_6.b2, TEMP_REG_6.b2, 1

; check on RX_CRC erorr
; status register r11.b1 needs to be 0x0A, i.e. EOF w/o errors
;
    qbne    DISC_RX_ERROR, R11.b2, 0x0A

    RET

DISC_RX_ERROR:

; error handling and statistic
; RX L2 status bits
; bit 7: ERROR_CRC - valid with RX_EOF only
; bit 6: ERROR_NIBBLE - valid with RX_EOF only
; bit 5: RX_SOF
; bit 4: SX_SFD
; bit 3: RX_EOF
; bit 2: RX_ERROR - frame size, preamble size, RX_ERR signal
; bit 1: STATUS_RDY -
; bit 0: RX_ERR - signal during frame

    qbne    DISC_SKIP_CRC_ERROR, R11.b2, 0x8A
    lbco    &R2,PRU0_DMEM_CONST, CRC_ERROR_P0_OFFSET, 4
    add     r2,r2,1
    sbco    &R2,PRU0_DMEM_CONST, CRC_ERROR_P0_OFFSET, 4

DISC_SKIP_CRC_ERROR:

    qbne    DISC_SKIP_SIZE_ERROR, R11.b2, 0x0E
    lbco    &R2,PRU0_DMEM_CONST, FORMAT_ERR_P0_OFFSET, 4
    add     r2,r2,1
    sbco    &R2,PRU0_DMEM_CONST, FORMAT_ERR_P0_OFFSET, 4

DISC_SKIP_SIZE_ERROR:

;  add more error handling if needed

; retrain on errors during start-up phase
   JMP      IDLE_WAIT_FOR_LINK_ACTIVE


