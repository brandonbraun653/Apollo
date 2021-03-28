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
;     file:   firm_main.asm
;
;     brief:  SORTE master protocol: contains the initialization routine and SORTE state machine.
;                                   
;
;    Version        Description                                Author
;     0.1         Created                                      Thomas Leyrer

;include section
    .include "../include/macros/macros.inc"
    .include "../include/macros/utils.inc"
    .include "../include/macros/sorte_macros.inc"
    .include "../include/macros/MACdef.inc"
    .include "../include/icss/icss_defines.inc"
    .include "../include/icss/icss_regs.inc"
    .include "../include/icss/icss_miirt_macros.inc"
    .include "../include/protocol/sorte_pru_master_register.inc"
    .include "../include/protocol/sorte_master_cfg.inc"
    .include "../include/protocol/sorte_packet_definition.inc"
	.include "../include/protocol/sorte_host_interface.inc"
    .include "firmware_version.inc"

; defines, set and asg section
; use PRU0 as SORTE master serving Port 0 receive and transmit. PRU1 is not used


; in order to ONLY send a 4 byte preamable, comment out the following line
; otherwise 8 byte preamble will be sent with every frame.
FULL_PREAMBLE     .set     1

; trace settings
trace_cmp0_left        .set 1

; Enable LED pattern generation
application_io          .set 1

;CCS/makefile specific settings
    .retain     ; Required for building .out with assembly file
    .retainrefs ; Required for building .out with assembly file

    .global    firm_main
    .global FN_STATE_MACHINE
    .global FN_EVENT_HANDLER
    .global FN_DISC_RCV
    .global IDLE_WAIT_FOR_LINK_ACTIVE
    .sect    ".text:firm_main"

;********
;* FIRM MAIN *
;********
firm_main:
; PRU init
; clear R0 to R30

    zero    &R0, 124

; configure defaults in SORTE configuration register
; options list: enable(bit 0); offline engineering;no trace; retrain on single crc error and timing error;
; no extra diag packet; no error test
;   ldi        TEMP_REG_1, 0x51
    ldi   TEMP_REG_1, 0x01
    sbco  &TEMP_REG_1, PRU0_DMEM_CONST, CTRL_REG_OFFSET , 1

; init status register to 0
    zero    &TEMP_REG_1,4
    sbco    &TEMP_REG_1, PRU0_DMEM_CONST, CTRL_REG_OFFSET+4 , 4

; init control parmaeter: set error counts for retrain to 3, no extra diags packet
      ldi32    TEMP_REG_1, 0x00000303
        sbco    &TEMP_REG_1, PRU0_DMEM_CONST, CTRL_REG_OFFSET+8 , 4

; set MII_RT mode for R30/R31 interface
;bit 1-0 PRU0_GPI_MODE R/W 0h PRU GPI (R31) modes:
;0h = Direct input mode. (default)
;1h = 16bit parallel capture mode.
;2h = 28bit shift in mode.
;3h = MII_RT mode

        ldi    TEMP_REG_1, 0x03
    .if $defined(PRU0)
    sbco    &TEMP_REG_1,ICSS_CFG_CONST,ICSS_CFG_GPCFG0,1
    .else
    sbco    &TEMP_REG_1,ICSS_CFG_CONST,ICSS_CFG_GPCFG1,1
    .endif

; set min frame count to 6 bytes (2 PREAMBLE(PE) + 4 payload bytes) in RXFRMS0 register
; memcpy(MII_RT_CFG_CONST+ 0x40, &TEMP_REG_1, 1);
    ldi    TEMP_REG_1, 0x06
    sbco     &TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_RXFRMS0, 1
    
; disable Port 1
    ldi    TEMP_REG_1, 0
    sbco     &TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 1

; set MII_RT into host send (HS) and host receive (HR) on same PRU; e.g. EMAC mode
; macro is PRU specific, i.e. each PRU can use this macro indepenently
    M_SET_MIIRT_HR
    M_SET_MIIRT_HS

; init the IEP timer, disable CMP0 wrap-around
    zero    &TEMP_REG_1, 4
    sbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
    lbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4
    sbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4

; starting with idle state
; test if there is an active link on the port using mdio interface
IDLE_WAIT_FOR_LINK_ACTIVE:
    lbco    &TEMP_REG_2.b0, ICSS_SHARED_RAM_CONST, MDIO_PHY_CONFIG_OFFSET, 1
    lbco    &TEMP_REG_1, ICSS_MDIO_CONST, ICSS_MDIO_LINK, 4
    qbbc    IDLE_WAIT_FOR_LINK_ACTIVE, TEMP_REG_1, TEMP_REG_2.b0

; check if enabled, enabling done at startup of pru firmware.
       lbco    &TEMP_REG_1.b0, PRU0_DMEM_CONST, CTRL_REG_OFFSET , 1
        qbbc    IDLE_WAIT_FOR_LINK_ACTIVE,TEMP_REG_1.b0, 0

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
STATE_DISCOVERY:

; set state register
; init status register to DISCOVERY state
       M_SET_STATE S_DISCOV, TEMP_REG_1.b1

; Reset mode back to host send mode
; could occur if jumping back to DISCOVERY state from another state
    M_SET_MIIRT_HS

; reset rx and tx fifos
    M_RESET_RXFIFO
    M_RESET_TXFIFO

; R30.w2 is the mask register
; set R30 mask to take data from R30.w0 (TX path - PRU)
; all FFFF in mask takes the data from PRU, all 0000 take the data from RX_L1 fifo
    ldi    R30.w2, 0xFFFF

; set const to control PRU cycle counter
        ldi32     r27, ICSS_PRU0_CNTL_BASE

; set iteration count for DISCOVERY state
    ldi     TEMP_REG_4.b0, 0

; Entry point where master starts sending out DISCOVERY frame every 1 ms
STATE_DISCOVERY_ITERATION:

; reset RX- and TX-FIFO and clear TX errors via the command interface
    ldi    R31.w2, (D_RESET_RXFIFO | D_RX_ERROR_CLEAR | D_RESET_TXFIFO)

; start 1 ms timer using PRU cycle counter
; disable cycle counter to clear it
; bit 3 is cycle counter enable, need to keep PRU enable
        ldi    TEMP_REG_1.w0, 0x0b03
        sbbo    &TEMP_REG_1.b0, r27, 0, 1
        zero    &TEMP_REG_2, 4

; clear PRU cycle counter
        sbbo    &TEMP_REG_2, r27, 0x0c,4

; enable PRU cycle counter
        sbbo    &TEMP_REG_1.b1, r27, 0, 1

; clear previous PRU cycle counter
    zero    &TEMP_REG_3, 4
; clear bytes received register
    zero    &TEMP_REG_6, 2
    zero    &TEMP_REG_6.b3, 1

; send DISCOVERY packet header

; send 8 byte PA for wireshark capture
; in order to not send 8 byte PA, please comment out line which defines FULL_PREAMBLE at top of file
    .if $defined(FULL_PREAMBLE)
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    .endif

; send 4 byte pre-amble
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    ldi        TX_DATA_WORD, 0xd555
    NOP
    M_PUSH_WORD

; 4 bytes header
    ldi32     TEMP_REG_1,DISC_HEADER
    ;ldi32    TX_DATA_WORD, DISC_HEADER
    ;M_PUSH_WORD
    mov        TX_DATA_BYTE, TEMP_REG_1.b0
    NOP
    M_PUSH_BYTE
    mov        TX_DATA_BYTE, TEMP_REG_1.b1
    NOP
    M_PUSH_BYTE
    ; jump to STATE_DISCOV_NOT_LAST is the discovery frame count is not 9;
    ; if it is 9, then set bit 3 of status register prior to sending
    ; out the next discovery frame which will transition the slave device
    ; to the next state. 
    qbne    STATE_DISCOV_NOT_LAST, TEMP_REG_4.b0, 9
    
    ldi    TEMP_REG_1.b3, 0x08
STATE_DISCOV_NOT_LAST:
    mov        TX_DATA_WORD, TEMP_REG_1.w2
    NOP
    M_PUSH_WORD
; start sending the payload
; initialize  2 byte count to zero, this will get incremented by each slave upon 
; receiving discovery frame; in general need 2 cycles between pushed to TX_FIFO.
; 
; 2 bytes: cnt (16 bit)
    ldi        TX_DATA_WORD, 0
    NOP
    M_PUSH_WORD

; need to check is slave is expecting to update READ_BYTE_OFFSET
; 2 bytes: READ_BYTE_OFFSET
;  ldi        TX_DATA_WORD, 0
;  NOP
;  M_PUSH_WORD

; 2 bytes: INPUT_BYTES_COUNT
    ldi        TX_DATA_WORD, 0
    NOP
    M_PUSH_WORD

; 2 bytes: OUTPUT_BYTES_COUNT
    ldi        TX_DATA_WORD, 0
    NOP
    M_PUSH_WORD

;   set number bytes inserted to TX_FIFO (8 PA + 4 H + 4 DISC H = 16 bytes)
    .if $defined(FULL_PREAMBLE)
    ldi        TEMP_REG_4.w2, 16
    .else
    ldi        TEMP_REG_4.w2, 14
    .endif

; set counter for DISCOVERY payload blocks (254 slaves * 4 bytes = 1016 bytes = 31 *32 bytes + 24 bytes
    ldi     TEMP_REG_4.b1, 31

; send 254 * 4 bytes = 1016 bytes = 31 *32 bytes + 24 bytes
; for i =0; i<254*4; i+=32 // send to TX fifo in blocks of 32 bytes

DISC_BLOCK_REPEAT:

; check TX_FIFO_LEVEL; start of frame time ~0
; TX_FIFO_LEVEL = bytes inserted - bytes sent on wire (delta t in 5 ns cycles / 16)
; if TX_FIFO_LEVEL <32  (32 bytes = 2.56 us = 512 PRU cycles
    lbbo     &PRU_CC_REG, r27, 0x0c , 4
    sub        TEMP_REG_1, PRU_CC_REG, TEMP_REG_3
; convert time difference which is in 5 ns into # of bytes 5ns * 16 = 80 ns
    lsr     TEMP_REG_1.w0, TEMP_REG_1, 4
; subtract sent bytes - time elapsed
    sub     TEMP_REG_1.w0, TEMP_REG_4.w2, TEMP_REG_1.w0
; if more than 32 bytes are available send next 32 bytes
    qblt     DISC_SKIP_SEND, TEMP_REG_1.w0, 32

    loop     DISC_PL_REPEAT, 16

;    ldi        TX_DATA_WORD, 0x0000
    mov        TX_DATA_WORD, TEMP_REG_4.w2
    NOP
    M_PUSH_WORD
DISC_PL_REPEAT:

    add        TEMP_REG_4.w2, TEMP_REG_4.w2, 32
    sub        TEMP_REG_4.b1, TEMP_REG_4.b1, 1

DISC_SKIP_SEND:

    CALL     FN_DISC_RCV

; check if more than 32 byte blocks need to be transfered.
    qblt    DISC_BLOCK_REPEAT, TEMP_REG_4.b1, 0

; insert last  24 bytes

; check TX_FIFO_LEVEL; start of frame time ~0
; TX_FIFO_LEVEL = bytes inserted - bytes sent on wire (delta t in 5 ns cycles / 16)
; if TX_FIFO_LEVEL <32  (32 bytes = 2.56 us = 512 PRU cycles

DISC_WAIT_LAST_BLOCK:
    lbbo     &PRU_CC_REG, r27, 0x0c , 4
    sub        TEMP_REG_1, PRU_CC_REG, TEMP_REG_3
    lsr     TEMP_REG_1.w0, TEMP_REG_1, 4
    sub     TEMP_REG_1.w0, TEMP_REG_4.w2, TEMP_REG_1.w0
    qblt     DISC_WAIT_LAST_BLOCK, TEMP_REG_1.w0, 24

    loop     DISC_LAST_REPEAT, 12
    ldi        TX_DATA_WORD, 0xbeef
    NOP
    M_PUSH_WORD
DISC_LAST_REPEAT:

    NOP
    NOP
; end packet with crc generated by PRU
    M_CMD16 D_PUSH_CRC_MSWORD_CMD | D_PUSH_CRC_LSWORD_CMD | D_TX_EOF
    nop


; check on receive
; on receive store packet in ICCS memory

; was this last interation? If not send another DISC after 1 ms (0x30d40) / 10ms (0x4E20)
DISC_WAIT_ITERATION:
    qbgt    DISC_WAIT_SKIP_RX, TEMP_REG_4.b0, TEMP_REG_6.b2
    CALL    FN_DISC_RCV
DISC_WAIT_SKIP_RX:
    ldi32    TEMP_REG_1, 0x0030d40
    lbbo     &PRU_CC_REG, r27, 0x0c , 4
    qblt    DISC_WAIT_ITERATION, TEMP_REG_1, PRU_CC_REG
    ; increment discovery frame send count by 1
    add    TEMP_REG_4.b0, TEMP_REG_4.b0, 1
    ; check to see if 10 discovery frames sent, if not, then
    ; continue to send  discovery frame. otherwise transition to PARAM state
    qbne    STATE_DISCOVERY_ITERATION, TEMP_REG_4.b0, 10

; ------------------------------------------------------------------------------
; state: PARAM
; Regsiter defines:
; n = TEMP_REG_4.b0 (iterations)
; m = TEMP_REG_4.b1 (counter for 32 bytes blocks in payload field)
; previous cycle counter = TEMP_REG_3
; ------------------------------------------------------------------------------

STATE_PARAM:

; stay in same host send mode as DISCOVERY state
;    M_SET_MIIRT_HS
;    M_SET_MIIRT_HR

; set protocol state
       M_SET_STATE S_PARAM, TEMP_REG_1.b1

; set number of iterations
    ldi     TEMP_REG_4.b0, 10

STATE_PARAM_ITERATION:
; setup PARAM packet using struct
    ldi       PARAM_P.da, 0xff
    ldi        PARAM_P.sa, 0
    ldi        PARAM_P.type, 0x02
    ldi        PARAM_P.status, 0x10
    qbne    STATE_PARAM_CONT,TEMP_REG_4.b0, 1
    ldi        PARAM_P.status, 0x18
STATE_PARAM_CONT:
    ldi32    PARAM_P.cycle_time,     CYCLE_TIME_10us
    ldi32    PARAM_P.sync_cycle,     SYNC_CYCLE_NONE
    ldi        PARAM_P.delay_period,     DELAY_PERIOD_1s
    ldi     PARAM_P.delay_burst,     DELAY_BURST_CNT_16
    ldi     PARAM_P.delay_gap,         DELAY_GAP_TIME_1ms
    ldi        PARAM_P.delay_fwd_time,    DELAY_FWD_TIME_320ns
    ldi        PARAM_P.ipg,            IPG_260ns
    ldi        PARAM_P.t_in,            T_IN_0
    ldi        PARAM_P.t_out,            T_OUT_0
    ldi        PARAM_P.topology,        TOPOLOGY_NORMAL
    ldi        PARAM_P.diagnostics,    DIAGS_MODE_PAYLOAD
    ldi        PARAM_P.alarm,            ALARM_MODE_NO
    ldi        PARAM_P.crc_mode,        CRC8 | (CRC8<<4)

; reset RX- and TX-FIFO and clear TX errors
    ldi        R31.w2, (D_RESET_RXFIFO | D_RX_ERROR_CLEAR | D_RESET_TXFIFO)

; start 1 ms timer using PRU cycle counter
; disable cycle counter to clear it
; bit 3 is cycle counter enable, need to keep PRU enable
    ldi        TEMP_REG_1.w0, 0x0b03
    sbbo    &TEMP_REG_1.b0, r27, 0, 1
    zero    &TEMP_REG_2, 4

; clear cycle counter
    sbbo    &TEMP_REG_2, r27, 0x0c,4

; enable cycle counter
    sbbo    &TEMP_REG_1.b1, r27, 0, 1

; clear previous cycle counter
    zero    &TEMP_REG_3, 4

; send PARAM packet

; pre-amble
; send 8 byte PA
    .if FULL_PREAMBLE
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    .endif

; send 4 byte pre-amble
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    ldi        TX_DATA_WORD, 0xd555
    NOP
    M_PUSH_WORD

; set parameter for send loop
; R1.b0 points to start of structure
; R1.b1 used as loop counter
    ldi        R1.b1, $sizeof(PARAM_P)
    ldi        R1.b0, &R2.b0

;send PARAM packet
    loop    STATE_PARAM_SEND, R1.b1
    mvib    TX_DATA_BYTE, *R1.b0++
    M_PUSH_BYTE
    nop
STATE_PARAM_SEND:

; end packet with crc generated by PRU
    M_CMD16 D_PUSH_CRC_MSWORD_CMD | D_PUSH_CRC_LSWORD_CMD | D_TX_EOF

    ldi        R2.w0, 0
    ldi        R2.w2, 1000
; receive packet and check if all accepted
STATE_PARAM_WAIT_BANK0:
    add        R2.w0, R2.w0, 1
    xin        RXL2_BANK0, &R18, 1
    qbeq    STATE_PARAM_WAIT, R2.w0, R2.w2
    qbgt    STATE_PARAM_WAIT_BANK0, r18.b0, 32

   

    xin        RXL2_BANK0, &r2, 32+16

; received packet has PA?
; find start offset
    ldi        R1.b0, &R2.b0
STATE_PARAM_PA_SEARCH:
; check on error: r1.b0 >8 (R2 offset) + 8 (max PA size)
    qblt    STATE_PARAM_PA_CONT, r1.b0, 16
    mvib    TEMP_REG_1.b1, *R1.b0++
    qbne    STATE_PARAM_PA_SEARCH, TEMP_REG_1.b1, 0xD5
STATE_PARAM_PA_CONT:

; check on status byte ok
; add 3 bytes offset to get to status field
    add        R1.b0, R1.b0, 3
    mvib    TEMP_REG_1.b1, *R1.b0
    qbbs    STATE_PARAM_RCV_OK, TEMP_REG_1.b1, 0

;   not all slave accepted
;    qba        STATE_DISCOVERY
STATE_PARAM_RCV_OK:

    sub        TEMP_REG_4.b0,TEMP_REG_4.b0,1
;  todo: read and verify rest of packet
;  wait for end of 1 ms period
STATE_PARAM_WAIT:
    ldi32    TEMP_REG_1, 0x0030d40 - 18
    lbbo     &PRU_CC_REG, r27, 0x0c , 4
    qblt    STATE_PARAM_WAIT, TEMP_REG_1, PRU_CC_REG

    qbne    STATE_PARAM_ITERATION,TEMP_REG_4.b0, 0


; ------------------------------------------------------------------------------
; state: DELAY_MASTER
; Regsiter defines:
; n = TEMP_REG_4.w0 (iterations)
;
; min delay = TEMP_REG_6.w0
; max delay = TEMP_REG_6.w2
; avg delay = TEMP_REG_5.w2
;
; ------------------------------------------------------------------------------

; set protocol state
       M_SET_STATE S_LINED, TEMP_REG_1.b1

; reset iep timer
    ldi     TEMP_REG_1.b0, CNT_DISABLE
    sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 1

    ldi32   TEMP_REG_1, 0
    sbco      &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
    .if $isdefed("ICSS_REV2")
        sbco      &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG + 4, 4
    .endif

    ldi     TEMP_REG_1.b0, 0x51
    sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 1

; init min, max and avg delay values
    ldi32    TEMP_REG_6,0x00007fff
    ldi        TEMP_REG_5.w2, 0
    ldi        TEMP_REG_4.w0, DELAY_BURST_CNT_16

STATE_DELAYM:

; reset RX- and TX-FIFO and clear RX errors
    ldi        R31.w2, (D_RESET_RXFIFO | D_RX_ERROR_CLEAR | D_RESET_TXFIFO)

; reset cycle counter
; start 1 ms timer using PRU cycle counter
; disable cycle counter to clear it
; bit 3 is cycle counter enable, need to keep PRU enable
    ldi     TEMP_REG_1.w0, 0x0b03
    sbbo    &TEMP_REG_1.b0, r27, 0, 1
    zero    &TEMP_REG_2, 4

; clear cycle counter
    sbbo    &TEMP_REG_2, r27, 0x0c,4

; enable cycle counter
    sbbo    &TEMP_REG_1.b1, r27, 0, 1

; clear previous cycle counter
    zero    &TEMP_REG_3, 4

; send DELAY_REQ packet
; start with delay master mode
    M_SET_DELAY_M_P0

; pre-amble
; send 8 byte PA
    .if FULL_PREAMBLE
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    .endif

; send 4 byte pre-amble
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    ldi        TX_DATA_WORD, 0xd555
    NOP
    M_PUSH_WORD

; 4 bytes header
    ldi32     TEMP_REG_1,DELAY_REQ_P
    mov        TX_DATA_BYTE, TEMP_REG_1.b0
    NOP
    M_PUSH_BYTE
    mov        TX_DATA_BYTE, TEMP_REG_1.b1
    NOP
    M_PUSH_BYTE
    ;qbne    STATE_DELAY_LAST, TEMP_REG_4.b0, (DELAY_BURST_CNT_16-1)
    qbne    STATE_DELAY_LAST, TEMP_REG_4.b0, 1    ; the frame counter runs down to 0
    ldi        TEMP_REG_1.b3, 0x08
STATE_DELAY_LAST:
    mov        TX_DATA_WORD, TEMP_REG_1.w2
    NOP
    M_PUSH_WORD

; send packet with crc generated by PRU
    M_CMD16 D_PUSH_CRC_MSWORD_CMD | D_PUSH_CRC_LSWORD_CMD | D_TX_EOF

; receive DELAY_RESP packet
STATE_DELAY_WAIT_BANK0:
    xin        RXL2_BANK0, &R18, 1
    qbgt    STATE_DELAY_WAIT_BANK0, r18.b0, 4

; read rx and tx time stamp - sof based
; read all time stamp register in one step r2 maps to cap0 (RX_SOF), r6 maps to cap
    lbco    &r2,ICSS_IEP_CONST, ICSS_IEP_CAPR0_REG, 6*4
    sub        TEMP_REG_1,r2,r6
    qbgt    STATE_DELAY_SKIP_MIN, TEMP_REG_6.w0, TEMP_REG_1.w0
    mov        TEMP_REG_6.w0, TEMP_REG_1.w0

STATE_DELAY_SKIP_MIN:
    qblt    STATE_DELAY_SKIP_MAX,TEMP_REG_6.w2,TEMP_REG_1.w0
    mov        TEMP_REG_6.w2, TEMP_REG_1.w0

STATE_DELAY_SKIP_MAX:
; calculate average, divide by count at the end
    add        TEMP_REG_5.w2, TEMP_REG_5.w2, TEMP_REG_1.w0

; wait gap (1ms)

STATE_DELAY_WAIT:
    ldi32    TEMP_REG_1, 0x0030d40
    lbbo     &PRU_CC_REG, r27, 0x0c , 4
    qblt    STATE_DELAY_WAIT, TEMP_REG_1, PRU_CC_REG

; repeat burst (16 times)

    sub        TEMP_REG_4.w0,TEMP_REG_4.w0, 1
    qbne    STATE_DELAYM,TEMP_REG_4.w0, 0

; shift right by 4 works for DELAY_BURST_CNT_16
    lsr        TEMP_REG_5.w2, TEMP_REG_5.w2, 4
; subtract bridge delay = 320 ns
    ldi        TEMP_REG_1.w0, DELAY_FWD_TIME_320ns
    sub     TEMP_REG_5.w2, TEMP_REG_5.w2, TEMP_REG_1.w0
; shift right by one to divide by 2 for line delay measurement
    lsr        TEMP_REG_5.w2, TEMP_REG_5.w2, 1

; ------------------------------------------------------------------------------
; state: SYNC
;
; Regsiter defines:
; n = TEMP_REG_4.w0 (iterations)
; period = TEMP_REG_3 (continous sync compare value used in cmp3)
; previous cycle counter = TEMP_REG_3
; ------------------------------------------------------------------------------

; send 1024 sync packets every 10 us using iep timer and cmp3 time of 500 ns for first packet
; sub-sequent packets have 10.0 us period

; set protocol state
       M_SET_STATE S_SYNC, TEMP_REG_1.b1


; set time triggered send mode where PRU0 uses cmp3 register
    M_SET_MIIRT_TTS

; disable IEP counter, keep cnt increment to 5
    ldi       TEMP_REG_1, 0x50
    sbco      &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 1

; clear global status
    ldi       TEMP_REG_1, 0x1
    sbco      &TEMP_REG_1, ICSS_IEP_CONST,ICSS_IEP_GLOBAL_STATUS_REG, 1

; reset IEP timer
    ldi32   TEMP_REG_1, 0
    sbco      &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
    
    .if $isdefed("ICSS_REV2")
        sbco      &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG+4, 4
    .endif

; set iteration to 1024 sync packets
    ldi        TEMP_REG_4.w0, 1024

; set 500 ns offset for first sync packet
    ldi32    TEMP_REG_3, 500
    sbco    &TEMP_REG_3, ICSS_IEP_CONST, ICSS_IEP_CMP3_REG, 4

; load the IEP CMP CFG register and enable the cmp3
    lbco   &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
    set    TEMP_REG_1, TEMP_REG_1, 4
    sbco   &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4

; clear cmp3 register
    ldi        TEMP_REG_1.b0, 0x08
    sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1


; enable IEP counter, keep cnt increment to 5
    ldi       TEMP_REG_1, 0x51
    sbco      &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 1

STATE_SYNC_ITERATION:
; need to enable tx fifo for every packet in TX_EN_MODE
    M_SET_MIIRT_TTS

; reset RX- and TX-FIFO and clear RX errors
    ldi        R31.w2, (D_RESET_RXFIFO | D_RX_ERROR_CLEAR | D_RESET_TXFIFO)


; send 4 byte pre-amble
    ldi        TX_DATA_WORD, 0x5555
    NOP
    M_PUSH_WORD
    ldi        TX_DATA_WORD, 0xd555
    NOP
    M_PUSH_WORD

; 4 bytes header
    ldi32     TEMP_REG_1, SYNC_P
    mov        TX_DATA_BYTE, TEMP_REG_1.b0
    NOP
    M_PUSH_BYTE
    mov        TX_DATA_BYTE, TEMP_REG_1.b1
    NOP
    M_PUSH_BYTE
    ldi        TEMP_REG_2.w0, 1023
    ;qbne    STATE_SYNC_LAST, TEMP_REG_4.w0, TEMP_REG_2.w0
    qbne    STATE_SYNC_LAST, TEMP_REG_4.w0, 1    ; frame counter counts down to zero
    ldi        TEMP_REG_1.b3, 0x08

STATE_SYNC_LAST:
    mov        TX_DATA_WORD, TEMP_REG_1.w2
    NOP
    M_PUSH_WORD

; insert time stamp of outgoing packet which is cmp3+ld+3.5 bytes of PA (280ns)
    lbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP3_REG, 4
    add        TEMP_REG_1, TEMP_REG_1, TEMP_REG_5.w2
    add        TEMP_REG_1, TEMP_REG_1, 100
    add        TEMP_REG_1, TEMP_REG_1, 180

    mov        TX_DATA_WORD, TEMP_REG_1.w0
    NOP
    M_PUSH_WORD

    mov        TX_DATA_WORD, TEMP_REG_1.w2
    NOP
    M_PUSH_WORD

    mov        TX_DATA_WORD, TEMP_REG_5.w2
    NOP
    M_PUSH_WORD

; end packet with crc generated by PRU
    M_CMD16 D_PUSH_CRC_MSWORD_CMD | D_PUSH_CRC_LSWORD_CMD | D_TX_EOF

; wait ~5 us after packet was sent
    ldi        TEMP_REG_2, 5000
    add        TEMP_REG_1, TEMP_REG_1, TEMP_REG_2
STATE_SYNC_WAIT:
    lbco      &TEMP_REG_2, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
    qblt    STATE_SYNC_WAIT, TEMP_REG_1,TEMP_REG_2

; add 10 us to cmp3
    ldi        TEMP_REG_1, 10000
    add        TEMP_REG_3, TEMP_REG_3, TEMP_REG_1
    sbco    &TEMP_REG_3, ICSS_IEP_CONST, ICSS_IEP_CMP3_REG, 4
    sbco    &TEMP_REG_3, ICSS_IEP_CONST, ICSS_IEP_CMP0_REG, 4

; clear cmp3 register
    ldi        TEMP_REG_1.b0, 0x08
    sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1

    sub        TEMP_REG_4.w0,TEMP_REG_4.w0, 1
    qbne    STATE_SYNC_ITERATION,TEMP_REG_4.w0, 0
; ------------------------------------------------------------------------------
; state: IO Exchange
; Regsiter defines:
; n = TEMP_REG_4.b0 (iterations)
; m = TEMP_REG_4.b1 (counter for 32 bytes blocks in payload field)
; previous cycle counter = TEMP_REG_3
; IO_CYCLE_CNT = cycle counter which start from 0, overlapps with PRU_CC
; ------------------------------------------------------------------------------
STATE_IOEXHANGE:
; start IO cycle count to 0
; IO cycle count is used for sample application
; 32 ms = 4 us * 8192 (2^13)
; 64 ms = 4 us * 16384 (2^14)
; 128 ms = 4us * 32768 (2^15)
; 256 ms = 4us * 65536 (2^16)
    ldi   IO_CYCLE_CNT, 0

; set protocol state
    M_SET_STATE S_IOEXCHANGE, TEMP_REG_1.b1

; set SYNC0 pulse width to 2 us
    ldi     TEMP_REG_1.w0, 400
    ldi     TEMP_REG_1.w2, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_PWIDTH_REG
    sbco    &TEMP_REG_1.w0, ICSS_IEP_CONST, TEMP_REG_1.w2, 2
    ldi32   TEMP_REG_1, 2000           ; SYNC0 should output
    sbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP1_REG, 4
    lbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
    set     TEMP_REG_1, TEMP_REG_1, 1<<(1+1) ; CMP[1]
    sbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4

; set CMP0 wrap around mode
; load the IEP CMP CFG register and enable the cmp0 with wrap around mode
    lbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 1
    or      TEMP_REG_1.b0, TEMP_REG_1.b0, 0x07
    sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 1

; wait for CMP0 hit and loop back to new cycle
STATE_IO_WAIT0:
    lbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1
    qbbc    STATE_IO_WAIT0,TEMP_REG_1.b0,0

;    clear cmp0, cmp1 and cmp3 events
    ldi     TEMP_REG_1.b0, 0x0b
    sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1

; set IEP CMP0 wrap around to 4 us
; enhancement: Should read from configuration register instead of hard-coded value
    ldi32   TEMP_REG_1, 4000-5
    sbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP0_REG, 4

; set 500 ns offset for the out packet
    ldi32   TEMP_REG_3, 500
    sbco    &TEMP_REG_3, ICSS_IEP_CONST, ICSS_IEP_CMP3_REG, 4

; debug pointer
    ldi     TEMP_REG_6.w0, 0

; send master out packet after 500 ns
; infininte loop for packet transmition with slave devices
; will exit loop on error condition ie link status down
STATE_IOEX_LOOP:
    M_SET_MIIRT_TTS
; reset RX- and TX-FIFO and clear TX errors
    ldi     R31.w2, (D_RESET_RXFIFO | D_RX_ERROR_CLEAR | D_RESET_TXFIFO)

; load 16 byte payload from PRU data memory, 4 bytes for each slave
    ldi     TEMP_REG_1.w0, OUT_DATA_OFFSET
    lbco    &r2.b2, PRU0_DMEM_CONST, TEMP_REG_1.w0, 16
    ldi     r2.w0, 0x3000

; send 1 byte pre-amble
    ;ldi        TX_DATA_BYTE, 0x5d
    ldi        TX_DATA_WORD, 0xd555
    NOP
    M_PUSH_WORD

; 2 bytes header SA = 0 and Sataus = IO Exchange master state
; use r2 for header to support crc calculation
    ldi     r2.w0, 0x3000
    mov        TX_DATA_BYTE, r2.b0
    NOP
    M_PUSH_BYTE
    mov        TX_DATA_BYTE, r2.b1
    NOP
    M_PUSH_BYTE

; send data field
    ldi        R1.b1, 16
    ldi        R1.b0, &R2.b2

;send out data
    loop    STATE_IO_SEND, R1.b1
    mvib    TX_DATA_BYTE, *R1.b0++
    M_PUSH_BYTE
STATE_IO_SEND:

; timing critical code:
;    packet went out at 500ns of new cycle
;   19 bytes are already in TX Fifo which takes 19 x 80 ns = 1520 ns
;   crc calculation over 18 bytes takes 650 ns. It is save to put the code here.

; calculate crc8 over 2 byte header and 16 data bytes - takes 35 ns per byte!
    ldi        TEMP_REG_3.b0, 0
    CRC8_CALC  TEMP_REG_3.b0, r2.b0, 18, TEMP_REG_4

; send crc8
    mov        TX_DATA_BYTE, TEMP_REG_3.b0
    NOP
    M_PUSH_BYTE

;  add actual tx time stamp to packet
    lbco    &TX_DATA_WORD,ICSS_IEP_CONST, ICSS_IEP_CAPR4_REG, 2
    M_PUSH_WORD

; send packet with crc8 inserted by PRU
   M_CMD16 D_TX_EOF


   .if $defined("application_io")
; now is time to generate new output data
; running LEDs for slave 1..4 with 2^n rate difference
; takes 31 cycles = 155 ns

; slave 1 = 32 ms runnig LED
    lsr     TEMP_REG_1, IO_CYCLE_CNT, 13
    and     TEMP_REG_1.b0,TEMP_REG_1, 0x07
    ldi     TEMP_REG_1.b1, 1
    lsl     TEMP_REG_1.b0, TEMP_REG_1.b1, TEMP_REG_1.b0
    ldi     TEMP_REG_2.w0, OUT_DATA_OFFSET
    sbco    &TEMP_REG_1.b0, PRU0_DMEM_CONST, TEMP_REG_2.w0, 1

; slave 2 = 64 ms runnig LED
    lsr     TEMP_REG_1, IO_CYCLE_CNT, 14
    and     TEMP_REG_1.b0,TEMP_REG_1, 0x07
    ldi     TEMP_REG_1.b1, 1
    lsl     TEMP_REG_1.b0, TEMP_REG_1.b1, TEMP_REG_1.b0
    ldi     TEMP_REG_2.w0, OUT_DATA_OFFSET
    add     TEMP_REG_2.w0, TEMP_REG_2.w0, 4
    sbco    &TEMP_REG_1.b0, PRU0_DMEM_CONST, TEMP_REG_2.w0, 1

; slave 3 = 128 ms runnig LED
    lsr     TEMP_REG_1, IO_CYCLE_CNT, 15
    and     TEMP_REG_1.b0,TEMP_REG_1, 0x07
    ldi     TEMP_REG_1.b1, 1
    lsl     TEMP_REG_1.b0, TEMP_REG_1.b1, TEMP_REG_1.b0
    ldi     TEMP_REG_2.w0, OUT_DATA_OFFSET
    add     TEMP_REG_2.w0, TEMP_REG_2.w0, 8
    sbco    &TEMP_REG_1.b0, PRU0_DMEM_CONST, TEMP_REG_2.w0, 1
; slave 4 = 256 ms runnig LED
    lsr     TEMP_REG_1, IO_CYCLE_CNT, 16
    and     TEMP_REG_1.b0,TEMP_REG_1, 0x07
    ldi     TEMP_REG_1.b1, 1
    lsl     TEMP_REG_1.b0, TEMP_REG_1.b1, TEMP_REG_1.b0
    ldi     TEMP_REG_2.w0, OUT_DATA_OFFSET
    add     TEMP_REG_2.w0, TEMP_REG_2.w0, 12
    sbco    &TEMP_REG_1.b0, PRU0_DMEM_CONST, TEMP_REG_2.w0, 1

    .endif

; increment cycle count and store to interface register
    add     IO_CYCLE_CNT, IO_CYCLE_CNT, 1
    sbco    &IO_CYCLE_CNT, PRU0_DMEM_CONST, CYCLE_CNT_P0_OFFSET, 4
    sbco    &R22,PRU0_DMEM_CONST, 0x60, 32
    lbco    &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4

; debug (write pulse settings)
    .if $defined("trace_cmp0_left")
    ldi     TEMP_REG_2.w0, OUT_DATA_OFFSET
    sbco    &TEMP_REG_1, PRU1_DMEM_CONST, TEMP_REG_6.w0, 4
    add     TEMP_REG_6.w0,TEMP_REG_6.w0, 4
    ldi     r2, 2048
    QBGT    STATE_IO_WAIT, TEMP_REG_6.w0, r2
    ldi     TEMP_REG_6.w0, 0
    .endif

; wait for CMP0 hit and loop back to new cycle
STATE_IO_WAIT:
    lbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1
    qbbc    STATE_IO_WAIT,TEMP_REG_1.b0,0

; clear cmp0, cmp1 and cmp3 events
    ldi        TEMP_REG_1.b0, 0x0b
    sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1

; re-enable SYNC0
; clear and set sync_en bit in IEP timer to re-enable trigger
    ldi    TEMP_REG_1, 0x06    ; clear sync_en (sync0_en, sync1_en)
    ldi    TEMP_REG_2.w0, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_CTRL_REG
    sbco   &TEMP_REG_1, ICSS_IEP_CONST, TEMP_REG_2.w0, 4
    ldi    TEMP_REG_1, 0x07    ;  set sync_en (sync0_en, sync1_en)
    sbco   &TEMP_REG_1, ICSS_IEP_CONST, TEMP_REG_2.w0, 4


; read and store input from slaves
    xin    RXL2_BANK0, &R18.b0, 1

; check on missing packet, bit 6 and 7 define retrain mode if packet is not received
    lbco    &r2, PRU0_DMEM_CONST, CTRL_REG_OFFSET , 1
    and     r2.b0, r2.b0, 0xc0
    qbeq    STATE_IOEX_SKIP_RETRAIN,r2.b0,0

; restart protocol
    qbne    STATE_IOEX_SKIP_RETRAIN, r18.b0, 0
    jmp     IDLE_WAIT_FOR_LINK_ACTIVE

STATE_IOEX_SKIP_RETRAIN:
    xin     RXL2_BANK0, &r2, 32
    ldi     TEMP_REG_2.w0, IN_DATA_OFFSET
    sbco    &r2.b0, PRU0_DMEM_CONST, TEMP_REG_2.w0, 32

    qba        STATE_IOEX_LOOP

firmware_version:
    .if $defined(PRU0)
    .word 0x00        ; PRU0
    .else
    .word 0x01        ; PRU1
    .endif

    .word   ICSS_FIRMWARE_RELEASE_1
    .word   ICSS_FIRMWARE_RELEASE_2
