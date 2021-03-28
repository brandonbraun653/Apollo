; 
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; 
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
; 
;        * Redistributions of source code must retain the above copyright
;          notice, this list of conditions and the following disclaimer.
; 
;        * Redistributions in binary form must reproduce the above copyright
;          notice, this list of conditions and the following disclaimer in the
;          documentation and/or other materials provided with the
;          distribution.
; 
;        * Neither the name of Texas Instruments Incorporated nor the names of
;          its contributors may be used to endorse or promote products derived
;          from this software without specific prior written permission.
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

; file:   PRU_SW_UART.asm
;
; brief:  PRU UART Firmware
;

; Resource table needed for remoteproc Linux driver
    .global ||pru_remoteproc_ResourceTable||
    .sect   ".resource_table:retain", RW
    .retain
    .align  1
    .elfsym ||pru_remoteproc_ResourceTable||,SYM_SIZE(20)
||pru_remoteproc_ResourceTable||:
    .bits   1,32            ; pru_remoteproc_ResourceTable.base.ver @ 0
    .bits   0,32            ; pru_remoteproc_ResourceTable.base.num @ 32
    .bits   0,32            ; pru_remoteproc_ResourceTable.base.reserved[0] @ 64
    .bits   0,32            ; pru_remoteproc_ResourceTable.base.reserved[1] @ 96
    .bits   0,32            ; pru_remoteproc_ResourceTable.offset[0] @ 128

    .include "firmware_version.h"
    .include "icss_defines.h"
    .include "icss_ctrl_regs.h"
    
    .cdecls C,NOLIST
%{
#include "icss_uart.h"
%}


;DEBUG_NO_HOST               .set    1   ; include code for initializing parameters normally initialized by Host

                            .if $defined("DEBUG_NO_HOST")
                            .if $defined("PRU0")
;  Host driver sets PRU ID FW register as part of Open function.
;
PRU_N                       .set    0   ; PRU number
    
;  Host driver sets FW PIN configuration registers as part of Open function.
;
; Pins used to mimic the UART interfaces
UART0_TX_PIN                .set    0   ;P9.31
UART0_RX_PIN                .set    1   ;P9.29
UART0_CTS_PIN               .set    19  ;unused
UART0_RTS_PIN               .set    19  ;unused

UART1_TX_PIN                .set    2   ;P9.30
UART1_RX_PIN                .set    3   ;P9.28
UART1_CTS_PIN               .set    19  ;unused
UART1_RTS_PIN               .set    19  ;unused

UART2_TX_PIN                .set    5   ;P9.27
UART2_RX_PIN                .set    7   ;P9.25
UART2_CTS_PIN               .set    19  ;unused
UART2_RTS_PIN               .set    19  ;unused

;  Host driver sets INT configuration registers as part of Open function.
;
; PRU System Events to use for character transmit buffer empty
TX_EVENT_0                  .set    21  ; generates pr1_pru_mst_intr[5]_intr_req
TX_EVENT_1                  .set    22  ; generates pr1_pru_mst_intr[6]_intr_req
TX_EVENT_2                  .set    23  ; generates pr1_pru_mst_intr[7]_intr_req
; PRU System Events to use for character received
RX_EVENT_0                  .set    18  ; generates pr1_pru_mst_intr[2]_intr_req
RX_EVENT_1                  .set    19  ; generates pr1_pru_mst_intr[3]_intr_req
RX_EVENT_2                  .set    20  ; generates pr1_pru_mst_intr[4]_intr_req

                            .else ; $defined("PRU0")
;  Host driver sets PRU ID FW register as part of Open function.
;
PRU_N                       .set    1   ; PRU number
    
;  Host driver sets FW PIN configuration registers as part of Open function.
;
; Pins used to mimic the UART interfaces
UART0_TX_PIN                .set    0   ;P8.45, LCD_DATA0,      R1, 0x8A0
UART0_RX_PIN                .set    1   ;P8.46, LCD_DATA1,      R2, 0x8A4
UART0_CTS_PIN               .set    2   ;P8.43, LCD_DATA2,      R3, 0x8A8
UART0_RTS_PIN               .set    3   ;P8.44, LCD_DATA3,      R4, 0x8AC
        
UART1_TX_PIN                .set    4   ;P8.41, LCD_DATA4,      T1, 0x8B0
UART1_RX_PIN                .set    5   ;P8.42, LCD_DATA5,      T2, 0x8B4
UART1_CTS_PIN               .set    6   ;P8.39, LCD_DATA6,      T3, 0x8B8
UART1_RTS_PIN               .set    7   ;P8.40, LCD_DATA7,      T4, 0x8BC
        
UART2_TX_PIN                .set    8   ;P8.27, LCD_VSYNC,      U5, 0x8E0
UART2_RX_PIN                .set    9   ;P8.29, LCD_HSYNC,      R5, 0x8E4
UART2_CTS_PIN               .set    10  ;P8.28, LCD_PCLK,       V5, 0x8E8
UART2_RTS_PIN               .set    11  ;P8.30, LCD_AC_BIAS_EN, R6, 0x8EC

;  Host driver sets INT configuration registers as part of Open function.
;
; PRU System Events to use for character transmit buffer empty
TX_EVENT_0                  .set    27  ; generates pr1_pru_mst_intr[11]_intr_req
TX_EVENT_1                  .set    28  ; generates pr1_pru_mst_intr[12]_intr_req
TX_EVENT_2                  .set    29  ; generates pr1_pru_mst_intr[13]_intr_req
; PRU System Events to use for character received
RX_EVENT_0                  .set    24  ; generates pr1_pru_mst_intr[8]_intr_req
RX_EVENT_1                  .set    25  ; generates pr1_pru_mst_intr[9]_intr_req
RX_EVENT_2                  .set    26  ; generates pr1_pru_mst_intr[10]_intr_req

                            .endif ; $defined("PRU0")

;  Host driver sets INT control registers as part of Open function.
;
; Tx interrupt to Host enable flags
UART0_TX_INT_CTRL           .set    0   ; LS bit is TxIntToHostEn flag, set flag to FALSE
UART1_TX_INT_CTRL           .set    0   ; LS bit is TxIntToHostEn flag, set flag to FALSE
UART2_TX_INT_CTRL           .set    0   ; LS bit is TxIntToHostEn flag, set flag to FALSE
; Rx interrupt to Host enable flags
UART0_RX_INT_CTRL           .set    0   ; LS bit is RxIntToHostEn flag, set flag to FALSE
UART1_RX_INT_CTRL           .set    0   ; LS bit is RxIntToHostEn flag, set flag to FALSE
UART2_RX_INT_CTRL           .set    0   ; LS bit is RxIntToHostEn flag, set flag to FALSE

                            .endif ; $defined("DEBUG_NO_HOST")

; Program constants
;;; PRU cycles per system tick and number of system tick for different baud rates for 14x oversampling
;;CYCLES_PER_TICK             .set    124     ; number of PRU cycles per tick
;;BAUD_300_TICKS              .set    5376    ; number of ticks for 300 baud
;;BAUD_600_TICKS              .set    2688    ; number of ticks for 600 baud
;;BAUD_1200_TICKS             .set    1344    ; number of ticks for 1200 baud
;;BAUD_2400_TICKS             .set    672     ; number of ticks for 2400 baud
;;BAUD_4800_TICKS             .set    336     ; number of ticks for 4800 baud
;;BAUD_9600_TICKS             .set    168     ; number of ticks for 9600 baud
;;BAUD_14400_TICKS            .set    112     ; number of ticks for 14400 baud
;;BAUD_19200_TICKS            .set    84      ; number of ticks for 19200 baud
;;BAUD_28800_TICKS            .set    56      ; number of ticks for 28800 baud
;;BAUD_38400_TICKS            .set    42      ; number of ticks for 38400 baud
;;BAUD_57600_TICKS            .set    28      ; number of ticks for 57600 baud
;;BAUD_115200_TICKS           .set    14      ; number of ticks for 115200 baud

; PRU cycles per system tick and number of system tick for different baud rates for 8x oversampling
CYCLES_PER_TICK             .set    217     ; number of PRU cycles per tick
BAUD_300_TICKS              .set    3072    ; number of ticks for 300 baud
BAUD_600_TICKS              .set    1536    ; number of ticks for 600 baud
BAUD_1200_TICKS             .set    768     ; number of ticks for 1200 baud
BAUD_2400_TICKS             .set    384     ; number of ticks for 2400 baud
BAUD_4800_TICKS             .set    192     ; number of ticks for 4800 baud
BAUD_9600_TICKS             .set    96      ; number of ticks for 9600 baud
BAUD_14400_TICKS            .set    64      ; number of ticks for 14400 baud
BAUD_19200_TICKS            .set    48      ; number of ticks for 19200 baud
BAUD_28800_TICKS            .set    32      ; number of ticks for 28800 baud
BAUD_38400_TICKS            .set    24      ; number of ticks for 38400 baud
BAUD_57600_TICKS            .set    16      ; number of ticks for 57600 baud
BAUD_115200_TICKS           .set    8       ; number of ticks for 115200 baud

; Config register bits
CONFIG_BAUD_BIT0            .set    0
CONFIG_BAUD_BIT1            .set    1
CONFIG_BAUD_BIT2            .set    2
CONFIG_BAUD_BIT3            .set    3
CONFIG_CHAR_SZ_BIT0         .set    4
CONFIG_CHAR_SZ_BIT1         .set    5
CONFIG_CHAR_SZ_BIT2         .set    6
CONFIG_STOP_SZ_BIT0         .set    7
CONFIG_STOP_SZ_BIT1         .set    8
CONFIG_PAR_BIT              .set    9
CONFIG_PAR_TYPE_BIT         .set    10
CONFIG_RSVD_11_BIT          .set    11
CONFIG_FC_BIT               .set    12
CONFIG_FC_TYPE_BIT          .set    13
CONFIG_RSVD_14_BIT          .set    14
CONFIG_RSVD_15_BIT          .set    15

; State bits for easier reading
STATE_BIT0                  .set    0
STATE_BIT1                  .set    1
STATE_BIT2                  .set    2
STATE_BIT3                  .set    3

UART_TX_START_STATE         .set    7   ; Tx starting state (RESET)
UART_RX_START_STATE         .set    15  ; Rx starting state (RESET)
UART_START_TICK             .set    100 ; starting tick
WAIT_TICK_SUB_CYCS          .set    7   ; wait_tick cycles between getting the count and checking it

; PRU control register base address
PRU_CTRL_REG_BASE_OFFSET    .set    ICSS_UART_GCFG_SZ
PRU_CTRL_REG_BASE_SZ        .set    4 ; bytes
PRU_CTRL_REG_BASE           .set    ICSS_UART_GCFG_ADDR + PRU_CTRL_REG_BASE_OFFSET

; Tx Interrupt Control register bits
CTRL_TX_INT_TO_HOST_EN      .set    TX_INT_EN_SHIFT ; flag indicates whether Tx Buffer empty interrupt to Host enabled
; Rx Interrupt Control register bits
CTRL_RX_INT_TO_HOST_EN      .set    RX_INT_EN_SHIFT ; flag indicates whether Rx character interrupt to Host enabled

; Tx Status register bits
STAT_TX_INT_TO_HOST_SENT    .set    0   ; flag indicates whether Tx Buffer empty interrupt to Host has been sent

; UART register offsets
RX_BUFF_RD_PTR_OFFSET       .set    UART_RD_WR_PTRS_OFFSET + RX_BUFF_WR_IDX_BYTEN    ; Rx read buffer pointer offset

; UART register sizes (bytes)
RD_WR_PTR_SZ                .set    1               ; Tx/Rx read/write buffer pointer size
RD_WR_PTRS_SZ               .set    2*RD_WR_PTR_SZ  ; Tx/Rx read/write buffer pointers size
TX_RX_INT_SZ                .set    1               ; Tx/Rx int (system event) size
; UART Tx/Rx configuration sizes (bytes)
UART_TX_CFG_SIZE            .set    2               ; Tx configuration size
UART_RX_CFG_SIZE            .set    3               ; Rx configuration size

; R31 Event Interface Mapping
R31_VEC_VALID               .set    5   ; valid strobe for vector output

; Structure for transmit register set
tx_reg_params_s .struct
CONFIG .ushort
RSVD .ubyte
STAT  .ubyte        ; Tx internal status register, LS bit is TxIntToHostSent flag.
STATE_REG .ubyte
CURR_BIT .ubyte
NUM_BITS .ubyte
PARITY .ubyte
CHAR_REG .ushort
NEXT_TICK .ushort
TICK_SIZE .ushort
    .endstruct

; Structure for receive register set
rx_reg_params_s .struct
CONFIG .ushort
FC_THRESH .ubyte
RSVD .ubyte
STATE_REG .ubyte
CURR_BIT .ubyte
NUM_BITS .ubyte
PARITY .ubyte
CHAR_REG .ushort
NEXT_TICK .ushort
TICK_SIZE .ushort
LAST_TICK .ushort
    .endstruct

; Structures being assigned to registers
UART0_TX_REGS .sassign r3.b0, tx_reg_params_s ;r3.b0-r6.b1
UART1_TX_REGS .sassign r7.b0, tx_reg_params_s ;r7.b0-r10.b1
UART2_TX_REGS .sassign r11.b0, tx_reg_params_s ;r11.b0-r14.b1
UART0_RX_REGS .sassign r15.b0, rx_reg_params_s ;r15.b0-r18.b3
UART1_RX_REGS .sassign r19.b0, rx_reg_params_s ;r19.b0-r22.b3
UART2_RX_REGS .sassign r23.b0, rx_reg_params_s ;r23.b0-r26.b3

; Temporary register to be used in a local context
    .asg    "r0", TEMP_REG
; Register to contain 32 bits of zero at all times
    .asg    "r2", ZERO_REG
; Register to contain the number of cycles per tick
    .asg    "r6.w2", CYCLE_COUNT_REG
; Word to contain the worst case tick delay (detects wrap around after subtraction)
    .asg    "r10.w2", WORST_DELAY_REG
; Word to contain the current tick count
    .asg    "r14.w2", TICK_COUNT_REG
; Temporary register to be used in a local context
    .asg    "r1", TEMP2_REG
; Temporary register for pin/interrupt configuration
    .asg    "r29", TEMP_PIN_INT_CFG
    .asg    "r29.b0", UART_TX_INT
    .asg    "r29.b1", UART_TX_INT_CTRL  ; UART Tx interrupt control, LS bit is TxIntToHostEn flag.
    .asg    "r29.b2", UART_TX_PIN
    .asg    "r29.b3", UART_CTS_PIN
    .asg    "r29.b0", UART_RX_INT
    .asg    "r29.b1", UART_RX_INT_CTRL  ; UART Rx interrupt control, LS bit is RxIntToHostEn flag.
    .asg    "r29.b2", UART_RX_PIN
    .asg    "r29.b3", UART_RTS_PIN

; Registers for temporary R30 and R31
TEMP_R30    .set    r27
TEMP_R31    .set    r28


; Macro to poke the bit into the TEMP_R30 position needed
config_bit  .macro in_reg, bit, pin, out_reg
    qbbs label1?, in_reg, bit
    jmp label2?
label1?:    
    set out_reg, out_reg, pin
label2?:
        .endm
; Macro to pick the bit out of the TEMP_R31 position needed
read_bit    .macro in_reg, bit, pin, out_reg
    qbbs label3?, in_reg, pin
    jmp label4?
label3?:    
    set out_reg, out_reg, bit
label4?:
        .endm

wait_tick   .macro bit 
    ; Get current cycle count
    LDI32   TEMP2_REG, PRU_CTRL_REG_BASE
    LBBO    &TEMP2_REG, TEMP2_REG, 0, PRU_CTRL_REG_BASE_SZ
    LBBO    &TEMP_REG, TEMP2_REG, ICSS_PRU_CTRL_CYCLE, 4
    ; Subtract current elapsed cycles from cycles between samples
    SUB CYCLE_COUNT_REG, CYCLE_COUNT_REG, TEMP_REG
    ; Subtract cycles between getting the count and checking it
    SUB CYCLE_COUNT_REG, CYCLE_COUNT_REG, WAIT_TICK_SUB_CYCS
    ; Check if the remaining count is even or odd
    QBBC    even, CYCLE_COUNT_REG, 0
    ; Subtract 2 more cycles if the remainging count is odd
    SUB CYCLE_COUNT_REG, CYCLE_COUNT_REG, 2
even:
    ; Skip the wait if the counter has rolled over, otherwise we would wait
    ; for more than 20 seconds for the counter to expire
    QBLT    reached, CYCLE_COUNT_REG, WORST_DELAY_REG
    ; Wait until cycle count is reached
not_reached:
    SUB CYCLE_COUNT_REG, CYCLE_COUNT_REG, 2
    QBLT    not_reached, CYCLE_COUNT_REG, 2
reached:
    ; Reset_cycle_counter
    SBBO    &ZERO_REG, TEMP2_REG, ICSS_PRU_CTRL_CYCLE, 4
        .endm

parse_baud_rate .macro config, tick_size
    ; binary parse for deterministic macro cycles (6 cycles)
    QBBS    _xxx1?, config, CONFIG_BAUD_BIT0
    QBBS    _xx10?, config, CONFIG_BAUD_BIT1
    QBBS    _x100?, config, CONFIG_BAUD_BIT2
    QBBS    _1000?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_300_TICKS   ;0000
    JMP baud_parse_done?
_xxx1?:
    QBBS    _xx11?, config, CONFIG_BAUD_BIT1
    QBBS    _x101?, config, CONFIG_BAUD_BIT2
    QBBS    _1001?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_600_TICKS   ;0001
    JMP baud_parse_done?
_xx10?:
    QBBS    _x110?, config, CONFIG_BAUD_BIT2
    QBBS    _1010?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_1200_TICKS  ;0010
    JMP baud_parse_done?
_xx11?:
    QBBS    _x111?, config, CONFIG_BAUD_BIT2
    QBBS    _1011?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_2400_TICKS  ;0011
    JMP baud_parse_done?
_x100?:
    QBBS    _default?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_4800_TICKS  ;0100
    JMP baud_parse_done?
_x101?:
    QBBS    _default?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_9600_TICKS  ;0101
    JMP baud_parse_done?
_x110?:
    QBBS    _default?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_14400_TICKS ;0110
    JMP baud_parse_done?
_x111?:
    QBBS    _default?, config, CONFIG_BAUD_BIT3
    LDI tick_size, BAUD_19200_TICKS ;0111
    JMP baud_parse_done?
_1000?:
    LDI tick_size, BAUD_28800_TICKS ;1000
    JMP baud_parse_done?
_1001?:
    LDI tick_size, BAUD_38400_TICKS ;1001
    JMP baud_parse_done?
_1010?:
    LDI tick_size, BAUD_57600_TICKS ;1010
    JMP baud_parse_done?
_1011?:
_default?:
    LDI tick_size, BAUD_115200_TICKS    ;1011
    JMP baud_parse_done?
baud_parse_done?:
        .endm

parse_num_bits  .macro config, num_bits
    ; binary parse for deterministic macro cycles (5 cycles)
    QBBS    _xx1?, config, CONFIG_CHAR_SZ_BIT0
    QBBS    _x10?, config, CONFIG_CHAR_SZ_BIT1
    QBBS    _100?, config, CONFIG_CHAR_SZ_BIT2
    LDI num_bits, 5     ;0000
    JMP num_bits_parse_done?
_xx1?:
    QBBS    _x11?, config, CONFIG_CHAR_SZ_BIT1
    QBBS    _default?, config, CONFIG_CHAR_SZ_BIT2
    LDI num_bits, 6     ;0001
    JMP num_bits_parse_done?
_x10?:
    QBBS    _default?, config, CONFIG_CHAR_SZ_BIT2
    LDI num_bits, 7     ;0010
    JMP num_bits_parse_done?
_x11?:
    QBBS    _default?, config, CONFIG_CHAR_SZ_BIT2
_default?:
    LDI num_bits, 8     ;0011
    JMP num_bits_parse_done?
_100?:
    LDI num_bits, 9     ;0100
    JMP num_bits_parse_done?
num_bits_parse_done?:
        .endm

tx_macro    .macro tx_regs, pin, cts_pin, cfg_offset, tx_buf_addr, int_ctrl, int_pulse
    QBNE    continue?, TICK_COUNT_REG, tx_regs.NEXT_TICK
    ; binary state selection to bound worst case cycle count
    QBBS    _xx1?, tx_regs.STATE_REG, STATE_BIT0
    QBBS    _x10?, tx_regs.STATE_REG, STATE_BIT1
    QBBS    _100?, tx_regs.STATE_REG, STATE_BIT2
    
    ; TX STATE0
    ; Check whether UART instance disabled
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_CTRL_OFFSET, UART_CTRL_SZ
    QBBS    txUartEnabledS0?, TEMP_REG, UART_CTRL__EN_SHIFT
    
    ; UART instance disabled
    ; set the next state
    LDI tx_regs.STATE_REG, UART_TX_START_STATE  ; set state to RESET
    ; set the next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    ; exit state machine
    JMP continue?
    
txUartEnabledS0?
    ; UART instance enabled

    ; pull and parse configs
    ; using knowledge of the config location to save 2 LDI32 cycles here
    LBBO    &tx_regs.CONFIG, ZERO_REG, cfg_offset+UART_CFG_OFFSET, UART_TX_CFG_SIZE
    parse_baud_rate tx_regs.CONFIG, tx_regs.TICK_SIZE
    ; clear the parity
    LDI tx_regs.PARITY, 0
    ; set the next state
    LDI tx_regs.STATE_REG, 1
    ; set the next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    ; exit state machine
    JMP continue?
    
_xx1?:
    QBBS    _x11?, tx_regs.STATE_REG, STATE_BIT1
    QBBS    _101?, tx_regs.STATE_REG, STATE_BIT2
    ; TX STATE1
    ; check if there is a byte to send
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_RD_WR_PTRS_OFFSET, UART_RD_WR_PTRS_SZ
    QBNE    byte_avail?, TEMP_REG.b0, TEMP_REG.b1
    
    ; check if Tx interrupt enabled for Tx Buffer empty
    QBBC    _default?, int_ctrl, CTRL_TX_INT_TO_HOST_EN
    ; if not already sent, send Tx interrupt to Host for Tx Buffer empty
    QBBS    _default?, tx_regs.STAT, STAT_TX_INT_TO_HOST_SENT
    ; send Tx Buffer empty interrupt to Host
    MOV     R31, int_pulse
    ; set Tx interrupt to Host flag
    SET     tx_regs.STAT, tx_regs.STAT, STAT_TX_INT_TO_HOST_SENT
    
_default?:
    LDI tx_regs.STATE_REG, 0
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    JMP continue?
    
byte_avail?:
    ; get the byte to send
    LDI32   TEMP2_REG, tx_buf_addr
    LBBO    &tx_regs.CHAR_REG, TEMP2_REG, TEMP_REG.b0, 2
    
    ; reset Tx interrupt to Host flag
    CLR     tx_regs.STAT, tx_regs.STAT, STAT_TX_INT_TO_HOST_SENT
    
    ; set the next state
    LDI tx_regs.STATE_REG, 2
    ; set the next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    ; exit state machine
    JMP continue?
    
_x10?:
    QBBS    _110?, tx_regs.STATE_REG, STATE_BIT2
    ; TX STATE2
    ; check flow control
    QBBC    no_fc?, tx_regs.CONFIG, CONFIG_FC_BIT
    ; flow control requested, check whether SW or HW
    QBBS    sw_fc?, tx_regs.CONFIG, CONFIG_FC_TYPE_BIT
    ; HW flow control, check CTS pin (active low)
    QBBC    no_fc?, R31, cts_pin
    LDI tx_regs.STATE_REG, 0
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    JMP continue?
sw_fc?:
    ; SW flow control not currently supported
no_fc?:
    ; parse the number of bits per character
    parse_num_bits tx_regs.CONFIG, tx_regs.NUM_BITS
    ; reset current bit counter
    LDI tx_regs.CURR_BIT, 0
    ; send the start bit
    CLR TEMP_R30, TEMP_R30, pin
    ; set the next state
    LDI tx_regs.STATE_REG, 3
    ; set the next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, tx_regs.TICK_SIZE
    ; exit state machine
    JMP continue?
    
_x11?:
    ;QBBS    _default?, tx_regs.STATE_REG, STATE_BIT2; _111 (should never happen)
    QBBS    _111?, tx_regs.STATE_REG, STATE_BIT2
    ; TX STATE3
    ; send the current bit
    CLR TEMP_R30, TEMP_R30, pin
    config_bit  tx_regs.CHAR_REG, tx_regs.CURR_BIT, pin, TEMP_R30
    ADD tx_regs.CURR_BIT, tx_regs.CURR_BIT, 1
    ; add parity if bit is 1
    QBBC    no_inc?, TEMP_R30, pin  
    ADD tx_regs.PARITY, tx_regs.PARITY, 1
no_inc?:
    ; set the next state to parity or stop bit if character is done
    QBNE    cont?, tx_regs.CURR_BIT, tx_regs.NUM_BITS
    ; finished sending, check to see if parity is requested
    QBBC    no_parity?, tx_regs.CONFIG, CONFIG_PAR_BIT
    LDI tx_regs.STATE_REG, 4
    JMP cont?
no_parity?:
    LDI tx_regs.STATE_REG, 5
cont?:
    ; set the next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, tx_regs.TICK_SIZE
    ; exit state machine
    JMP continue?
    
_100?:
    ;TX STATE4
    ; send the parity bit
    CLR TEMP_R30, TEMP_R30, pin
    ; set the parity bit if bit 0 of the count is 1
    config_bit  tx_regs.PARITY, 0, pin, TEMP_R30
    QBBC    even?, tx_regs.CONFIG, CONFIG_PAR_TYPE_BIT
    ; invert the parity because it's odd
    ZERO    &TEMP_REG, 4
    SET TEMP_REG, TEMP_REG, pin
    XOR TEMP_R30, TEMP_R30, TEMP_REG
even?:
    LDI tx_regs.STATE_REG, 5
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, tx_regs.TICK_SIZE
    JMP continue?
    
_101?:
    ;TX STATE5
    ; send the stop bit
    SET TEMP_R30, TEMP_R30, pin
    ; increment the read pointer
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_RD_WR_PTRS_OFFSET, UART_RD_WR_PTRS_SZ
    ADD TEMP_REG.b0, TEMP_REG.b0, 2
    ; reset the read pointer if it rolled over
    QBGE    update?, TEMP_REG.b0, BUFF_SIZE-2
    LDI TEMP_REG.b0, 0
update?:
    SBBO    &TEMP_REG.b0, ZERO_REG, cfg_offset+UART_RD_WR_PTRS_OFFSET, RD_WR_PTR_SZ
    ; set the next state
    LDI tx_regs.STATE_REG, 6
    ; set the next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    JMP continue?
    
_110?:
    ; TX STATE6
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, tx_regs.TICK_SIZE
    LSR TEMP_REG.w0, tx_regs.TICK_SIZE, 1
    QBBS    _2_0?, tx_regs.CONFIG, CONFIG_STOP_SZ_BIT1
    QBBS    _1_5?, tx_regs.CONFIG, CONFIG_STOP_SZ_BIT0
    JMP neither?
_2_0?:
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, TEMP_REG.w0
_1_5?:
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, TEMP_REG.w0
neither?:
    LDI tx_regs.STATE_REG, 0
    SUB tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 3
    JMP continue?
    
_111?:
    ; TX STATE7 (RESET)
    ; Check whether UART instance enabled
    
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_CTRL_OFFSET, UART_CTRL_SZ      ; load entire UART CTRL register
    QBBS    txUartEnabledS7?, TEMP_REG, UART_CTRL__EN_SHIFT                     ; check if EN bit is set in Byte 0
    
    ; UART instance disabled
    ; clear Tx enable-ack
    CLR     TEMP_REG, TEMP_REG, UART_CTRL__TX_EN_ACK_SHIFT                      ; update ACK bit in Byte 1
    SBBO    &TEMP_REG.b1, ZERO_REG, cfg_offset+UART_CTRL_OFFSET+1, 1            ; Only store Byte 0 containing updated TX ACK bit.
                                                                                ; This avoids overwrite of update by Host to Byte 0.
                                                                                
    ; set next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    JMP continue?
txUartEnabledS7?:
    ; UART instance enabled
    LDI32   TEMP2_REG, cfg_offset
    ; clear UART instance Tx rd/wr pointers
    SBBO    &ZERO_REG, TEMP2_REG, UART_RD_WR_PTRS_OFFSET, RD_WR_PTRS_SZ
    ; subtract 16 from interrupt (system event) number
    ; add valid strobe bit to Tx interrupt (system event) number
    CLR     int_pulse, int_pulse, 4
    SET     int_pulse, int_pulse, R31_VEC_VALID
    SBBO    &int_pulse, TEMP2_REG, UART_TX_PIN_INT_OFFSET, TX_RX_INT_SZ
    
    ; set Tx enable-ack
    SET     TEMP_REG, TEMP_REG, UART_CTRL__TX_EN_ACK_SHIFT                      ; update ACK bit in Byte 1
    SBBO    &TEMP_REG.b1, ZERO_REG, cfg_offset+UART_CTRL_OFFSET+1, 1            ; Only store Byte 0 containing updated TX ACK bit.
                                                                                ; This avoids overwrite of update by Host to Byte 0.
                                                                                
    ; set the next state
    LDI tx_regs.STATE_REG, 0
    ; set next tick
    ADD tx_regs.NEXT_TICK, tx_regs.NEXT_TICK, 1
    JMP continue?    
continue?:
        .endm

rx_macro    .macro rx_regs, pin, rts_pin, cfg_offset, rx_buf_addr, int_ctrl, int_pulse
    QBNE    continue?, TICK_COUNT_REG, rx_regs.NEXT_TICK
    ; binary state selection to bound worst case cycle count
    QBBS    _xxx1?, rx_regs.STATE_REG, STATE_BIT0
    QBBS    _xx10?, rx_regs.STATE_REG, STATE_BIT1
    QBBS    _x100?, rx_regs.STATE_REG, STATE_BIT2
    QBBS    _1000?, rx_regs.STATE_REG, STATE_BIT3
    
    ; RX STATE0
    ; Check whether UART instance disabled
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_CTRL_OFFSET, UART_CTRL_SZ
    QBBS    rxUartEnabledS0?, TEMP_REG, UART_CTRL__EN_SHIFT
    ; UART instance disabled
    ; set the next state
    LDI rx_regs.STATE_REG, UART_RX_START_STATE  ; set state to RESET
    ; set the next tick
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    ; exit state machine
    JMP continue?
rxUartEnabledS0?:
    ; UART instance enabled
    ; wait for the RX pin to go high (to check for a transition)
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    QBBC    continue?, TEMP_R31, pin 
    LDI rx_regs.STATE_REG, 1
    JMP continue?

_xxx1?:
    QBBS    _xx11?, rx_regs.STATE_REG, STATE_BIT1
    QBBS    _x101?, rx_regs.STATE_REG, STATE_BIT2
    QBBS    _default?, rx_regs.STATE_REG, STATE_BIT3 ;_1001
    
    ; RX STATE1
    ; Check whether UART instance disabled
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_CTRL_OFFSET, UART_CTRL_SZ
    QBBS    rxUartEnabledS1?, TEMP_REG, UART_CTRL__EN_SHIFT

    ; UART instance disabled
    ; set the next state
    LDI rx_regs.STATE_REG, UART_RX_START_STATE  ; set state to RESET
    ; set the next tick
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    ; exit state machine
    JMP continue?
    
rxUartEnabledS1?:
    ; UART instance enabled
    
    ; check for start bit
    QBBC    start?, TEMP_R31, pin
    ; no start bit, check the buffer threshold, stay in state 1, and check again next tick
    ; assume there is space in the buffer 
    CLR     TEMP_R30, TEMP_R30, rts_pin
    ; pull the current read and write pointers
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_RD_WR_PTRS_OFFSET, UART_RD_WR_PTRS_SZ
    ; get the current fill level (WR pointer - RD pointer)
    SUB TEMP_REG.b0, TEMP_REG.b3, TEMP_REG.b2
    ; check buffer fill level against threshold for flow control
    QBGT    no_rts?, TEMP_REG.b0, rx_regs.FC_THRESH
    ; flow control is not requested
    QBBC    no_rts?, rx_regs.CONFIG, CONFIG_FC_BIT
    SET     TEMP_R30, TEMP_R30, rts_pin
no_rts?:
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    ; exit state machine
    JMP continue?
start?:
    ; start bit found, pull configurations
    ; using knowledge of the config location to save 2 LDI32 cycles here
    LBBO    &rx_regs.CONFIG, ZERO_REG, cfg_offset+UART_CFG_OFFSET, UART_RX_CFG_SIZE
    parse_baud_rate rx_regs.CONFIG, rx_regs.TICK_SIZE
    ; set the next state
    LDI rx_regs.STATE_REG, 2
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    ; exit state machine
    JMP continue?
    
_xx10?:
    QBBS    _x110?, rx_regs.STATE_REG, STATE_BIT2
    QBBS    _default?, rx_regs.STATE_REG, STATE_BIT3 ;_1010
    ; RX STATE2
    ; pull the current read and write pointers
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_RD_WR_PTRS_OFFSET, UART_RD_WR_PTRS_SZ
    ; increment the write pointer locally to check buffer fill level
    ADD TEMP_REG.b3, TEMP_REG.b3, 2
    QBGE    no_roll?, TEMP_REG.b3, BUFF_SIZE-2
    LDI TEMP_REG.b3, 0
no_roll?:
    QBNE    not_full?, TEMP_REG.b3, TEMP_REG.b2
    ; buffer is completely full, return to state 1
_default?:
    LDI rx_regs.STATE_REG, 1
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?
not_full?:  
    LDI rx_regs.STATE_REG, 3
    ; set the next tick to half a tick to check for spurious start bit
    LSR TEMP_REG.w0, rx_regs.TICK_SIZE, 1
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, TEMP_REG.w0
    SUB rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?  
    
_xx11?:
    QBBS    _x111?, rx_regs.STATE_REG, STATE_BIT2
    QBBS    _default?, rx_regs.STATE_REG, STATE_BIT3 ;_1011
    ; RX STATE3
    ; check for spurious start bit
    QBBC    real_start?, TEMP_R31, pin
    ; spurious start bit
    LDI rx_regs.STATE_REG, 1
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?
real_start?:
    ; clear the parity bit
    LDI rx_regs.PARITY, 0
    ; reset the current bit counter
    LDI rx_regs.CURR_BIT, 0
    ; clear the char receive register
    ZERO    &rx_regs.CHAR_REG, 2
    ; parse the number of bits per character
    parse_num_bits rx_regs.CONFIG, rx_regs.NUM_BITS
    LDI rx_regs.STATE_REG, 4
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, rx_regs.TICK_SIZE
    JMP continue?
    
_x100?:
    QBBS    _default?, rx_regs.STATE_REG, STATE_BIT3 ;_1100
    ; RX STATE4
    read_bit TEMP_R31, rx_regs.CURR_BIT, pin, rx_regs.CHAR_REG
    ADD rx_regs.CURR_BIT, rx_regs.CURR_BIT, 1
    ; check parity if bit is 1
    QBBC    no_inc?, TEMP_R31, pin  
    ADD rx_regs.PARITY, rx_regs.PARITY, 1
no_inc?:
    ; set the next state to parity or stop bit if character is done
    QBNE    cont?, rx_regs.CURR_BIT, rx_regs.NUM_BITS
    ; finished receiving, check to see if parity is requested
    QBBC    no_parity?, rx_regs.CONFIG, CONFIG_PAR_BIT
    LDI rx_regs.STATE_REG, 5
    JMP cont?
no_parity?:
    LDI rx_regs.STATE_REG, 6
cont?:
    ; set the next tick
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, rx_regs.TICK_SIZE
    ; exit state machine
    JMP continue?
    
_x101?:
    QBBS    _default?, rx_regs.STATE_REG, STATE_BIT3 ;_1101
    ; RX STATE5 
    ; read the parity bit into bit 0 of the TEMP_REG
    ZERO    &TEMP2_REG, 4
    read_bit    TEMP_R31, 0, pin, TEMP2_REG
    ; mask the parity counter to get bit 0 (even parity value)
    AND rx_regs.PARITY, rx_regs.PARITY, 0x1
    QBBC    even?, rx_regs.CONFIG, CONFIG_PAR_TYPE_BIT
    ; odd parity, values should be not equal for correct
    QBNE    no_error?, TEMP2_REG.b0, rx_regs.PARITY 
    JMP error?
even?:
    QBEQ    no_error?, TEMP2_REG.b0, rx_regs.PARITY
error?:
    ; parity bit error, set bit 15
    SET rx_regs.CHAR_REG, rx_regs.CHAR_REG, RX_CHAR_PARITY_ERR_SHIFT
no_error?:
    LDI rx_regs.STATE_REG, 6
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, rx_regs.TICK_SIZE
    JMP continue?
    
_x110?:
    QBBS    _default?, rx_regs.STATE_REG, STATE_BIT3 ;_1110
    ; RX STATE6
    ADD rx_regs.LAST_TICK, rx_regs.NEXT_TICK, 0
    LSR TEMP_REG.w0, rx_regs.TICK_SIZE, 1
    QBBS    _2_0?, rx_regs.CONFIG, CONFIG_STOP_SZ_BIT1
    QBBS    _1_5?, rx_regs.CONFIG, CONFIG_STOP_SZ_BIT0
    JMP neither?
_2_0?:
    ADD rx_regs.LAST_TICK, rx_regs.LAST_TICK, TEMP_REG.w0
_1_5?:
    ADD rx_regs.LAST_TICK, rx_regs.LAST_TICK, TEMP_REG.w0
neither?:
    LSR TEMP_REG.w0, rx_regs.TICK_SIZE, 2
    ADD rx_regs.LAST_TICK, rx_regs.LAST_TICK, TEMP_REG.w0
    LDI rx_regs.STATE_REG, 7
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?
    
_x111?:
    ;QBBS    _default?, rx_regs.STATE_REG, STATE_BIT3 ;_1111
    QBBS    _1111?, rx_regs.STATE_REG, STATE_BIT3
    ; RX STATE7
    QBBC    framing_error?, TEMP_R31, pin 
    QBEQ    no_framing_error?, TICK_COUNT_REG, rx_regs.LAST_TICK
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?
framing_error?:
    ; framing error, set bit 14
    SET rx_regs.CHAR_REG, rx_regs.CHAR_REG, RX_CHAR_FRAMING_ERR_SHIFT
no_framing_error?:
    LDI rx_regs.STATE_REG, 8
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?
    
_1111?:
    ; RX STATE15 (RESET)
    ; Check whether UART instance enabled
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_CTRL_OFFSET, UART_CTRL_SZ      ; load entire UART CTRL register
    QBBS    rxUartEnabledS15?, TEMP_REG, UART_CTRL__EN_SHIFT                    ; check if EN bit is set in Byte 0
    
    ; UART instance disabled
    ; clear Rx enable-ack
    CLR     TEMP_REG, TEMP_REG, UART_CTRL__RX_EN_ACK_SHIFT                      ; update ACK bit in Byte 1
    SBBO    &TEMP_REG.b1, ZERO_REG, cfg_offset+UART_CTRL_OFFSET+1, 1            ; Only store Byte 0 containing updated TX ACK bit.
                                                                                ; This avoids overwrite of update by Host to Byte 0.
    
    ; set next tick
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?
rxUartEnabledS15?:
    ; UART instance enabled
    LDI32   TEMP2_REG, cfg_offset
    ; clear UART instance Rx rd/wr pointers
    SBBO    &ZERO_REG, TEMP2_REG, UART_RD_WR_PTRS_OFFSET+RX_BUFF_RD_IDX_BYTEN, RD_WR_PTRS_SZ
    ; subtract 16 from interrupt (system event) number
    ; add valid strobe bit to Rx interrupt (system event) number
    CLR     int_pulse, int_pulse, 4
    SET     int_pulse, int_pulse, R31_VEC_VALID
    SBBO    &int_pulse, TEMP2_REG, UART_RX_PIN_INT_OFFSET, TX_RX_INT_SZ
    ; set RTS low
    CLR     TEMP_R30, TEMP_R30, rts_pin
    
    ; set Rx enable-ack
    SET     TEMP_REG, TEMP_REG, UART_CTRL__RX_EN_ACK_SHIFT                      ; update ACK bit in Byte 1
    SBBO    &TEMP_REG.b1, ZERO_REG, cfg_offset+UART_CTRL_OFFSET+1, 1            ; Only store Byte 0 containing updated TX ACK bit.
                                                                                ; This avoids overwrite of update by Host to Byte 0.
    
    ; set the next state
    LDI rx_regs.STATE_REG, 0
    ; set next tick
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    JMP continue?    

_1000?:
    ; RX STATE8
    ; get the address to store the character
    LBBO    &TEMP_REG, ZERO_REG, cfg_offset+UART_RD_WR_PTRS_OFFSET, UART_RD_WR_PTRS_SZ
    ; write the character before updating the pointer
    LDI32   TEMP2_REG, rx_buf_addr
    SBBO    &rx_regs.CHAR_REG, TEMP2_REG, TEMP_REG.b3, 2
    ; increment and then update the write pointer
    ADD TEMP_REG.b3, TEMP_REG.b3, 2
    QBGE    update?, TEMP_REG.b3, BUFF_SIZE-2
    LDI TEMP_REG.b3, 0
update?:
    SBBO    &TEMP_REG.b3, ZERO_REG, cfg_offset+RX_BUFF_RD_PTR_OFFSET, RD_WR_PTR_SZ
    LDI rx_regs.STATE_REG, 1
    ADD rx_regs.NEXT_TICK, rx_regs.NEXT_TICK, 1
    ; check if Rx interrupt enabled for Rx character
    QBBC    continue?, int_ctrl, CTRL_RX_INT_TO_HOST_EN
    ; send interrupt to Host for this character
    MOV     R31, int_pulse
continue?
        .endm

    .sect ".data"
    .retain
    ; need static data in DMEM properly loaded using hexpru image
    .word 0 ; unused
    
    .sect  ".firmware_version"
    .retain
    .byte   0x55,0x41,0x52,0x54 ; magic number, "UART"
    .word   UART_FIRMWARE_TYPE
    .word   UART_FIRMWARE_VERSION
    .word   UART_FIRMWARE_FEATURE
    .word   UART_FIRMWARE_EXTENDED_FEATURE_PTR    
    
    .sect ".text"
    .retain
    .retainrefs

    .global UART_entry

UART_entry:
    .if $defined("DEBUG_NO_HOST")
    ;  Host driver sets PRU ID FW register as part of Open function (FW download & init).
    ;
    ; Set PRU ID
    LDI32   TEMP2_REG, ICSS_UART_GCFG_ADDR
    LDI     TEMP_REG, PRU_N
    LSL     TEMP_REG, TEMP_REG, ICSS_UART_GCFG__PRU_ID_SHIFT
    SBBO    &TEMP_REG, TEMP2_REG, 0, 1
    
    ;  Host driver sets UART configuration FW registers as part of Open function.
    ;
    ; Set configuration registers to defaults
    ; Config UART0 to 0x35 (9600 baud, 8 bits per character)
    LDI32   TEMP2_REG, UART0_CFG
    LDI32   TEMP_REG, 0x35
    SBBO    &TEMP_REG, TEMP2_REG, 0, UART_CFG_SZ
    ; Config UART1 to 0x35 (9600 baud, 8 bits per character)
    LDI32   TEMP2_REG, UART1_CFG
    LDI32   TEMP_REG, 0x35
    SBBO    &TEMP_REG, TEMP2_REG, 0, UART_CFG_SZ
    ; Config UART2 to 0x35 (9600 baud, 8 bits per character)
    LDI32   TEMP2_REG, UART2_CFG
    LDI32   TEMP_REG, 0x35
    SBBO    &TEMP_REG, TEMP2_REG, 0, UART_CFG_SZ

    ;  Host driver sets FW PIN configuration registers as part of Open function.
    ;
    ; Set pin configuration registers to defaults
    ; Set UART0 Tx pins
    LDI32   TEMP2_REG, UART0_TX_PIN_INT_CFG
    LDI     UART_TX_INT, TX_EVENT_0
    LDI     UART_TX_INT_CTRL, UART0_TX_INT_CTRL
    LDI     UART_TX_PIN, UART0_TX_PIN
    LDI     UART_CTS_PIN, UART0_CTS_PIN
    SBBO    &TEMP_PIN_INT_CFG, TEMP2_REG, 0, UART_TX_PIN_INT_SZ
    ; Set UART0 Rx pins
    LDI32   TEMP2_REG, UART0_RX_PIN_INT_CFG
    LDI     UART_RX_INT, RX_EVENT_0
    LDI     UART_RX_INT_CTRL, UART0_RX_INT_CTRL
    LDI     UART_RX_PIN, UART0_RX_PIN
    LDI     UART_RTS_PIN, UART0_RTS_PIN
    SBBO    &TEMP_PIN_INT_CFG, TEMP2_REG, 0, UART_RX_PIN_INT_SZ
    ; Set UART1 Tx pins
    LDI32   TEMP2_REG, UART1_TX_PIN_INT_CFG
    LDI     UART_TX_INT, TX_EVENT_1
    LDI     UART_TX_INT_CTRL, UART1_TX_INT_CTRL
    LDI     UART_TX_PIN, UART1_TX_PIN
    LDI     UART_CTS_PIN, UART1_CTS_PIN
    SBBO    &TEMP_PIN_INT_CFG, TEMP2_REG, 0, UART_TX_PIN_INT_SZ
    ; Set UART1 Rx pins
    LDI32   TEMP2_REG, UART1_RX_PIN_INT_CFG
    LDI     UART_RX_INT, RX_EVENT_1
    LDI     UART_RX_INT_CTRL, UART1_RX_INT_CTRL
    LDI     UART_RX_PIN, UART1_RX_PIN
    LDI     UART_RTS_PIN, UART1_RTS_PIN
    SBBO    &TEMP_PIN_INT_CFG, TEMP2_REG, 0, UART_RX_PIN_INT_SZ
    ; Set UART2 Tx pins
    LDI32   TEMP2_REG, UART2_TX_PIN_INT_CFG
    LDI     UART_TX_INT, TX_EVENT_2
    LDI     UART_TX_INT_CTRL, UART2_TX_INT_CTRL
    LDI     UART_TX_PIN, UART2_TX_PIN
    LDI     UART_CTS_PIN, UART2_CTS_PIN
    SBBO    &TEMP_PIN_INT_CFG, TEMP2_REG, 0, UART_TX_PIN_INT_SZ
    ; Set UART2 Rx pins
    LDI32   TEMP2_REG, UART2_RX_PIN_INT_CFG
    LDI     UART_RX_INT, RX_EVENT_2
    LDI     UART_RX_INT_CTRL, UART2_RX_INT_CTRL
    LDI     UART_RX_PIN, UART2_RX_PIN
    LDI     UART_RTS_PIN, UART2_RTS_PIN
    SBBO    &TEMP_PIN_INT_CFG, TEMP2_REG, 0, UART_RX_PIN_INT_SZ
    .endif ; defined("DEBUG_NO_HOST")

   ; Load with the worst case delay to check for overflow
    LDI WORST_DELAY_REG, 0x0FFF

    ; Load PRU_CTRL_REG_BASE with PRU_CTRL registers base address.
    ; Load address based on PRU ID (0 or 1).
    LDI32   TEMP2_REG, ICSS_UART_GCFG_ADDR
    LBBO    &TEMP_REG, TEMP2_REG, 0, ICSS_UART_GCFG_SZ
    QBBS    cfg_ctrl_reg_base_pru1, TEMP_REG, ICSS_UART_GCFG__PRU_ID_SHIFT
    LDI32   TEMP_REG, ICSS_PRU0_CTRL_LOCAL ; load PRU0 Control
    SBBO    &TEMP_REG, TEMP2_REG, PRU_CTRL_REG_BASE_OFFSET, PRU_CTRL_REG_BASE_SZ
    QBA     cfg_ctrl_reg_base_done
cfg_ctrl_reg_base_pru1:
    LDI32   TEMP_REG, ICSS_PRU1_CTRL_LOCAL ; load PRU1 Control
    SBBO    &TEMP_REG, TEMP2_REG, PRU_CTRL_REG_BASE_OFFSET, PRU_CTRL_REG_BASE_SZ
cfg_ctrl_reg_base_done:
    
    ; Load ZERO_REG with 32 bits of 0
    ZERO    &ZERO_REG, 4

    ; Initialize the tick counter
    LDI TICK_COUNT_REG, 1

    ; Initialize UART0 TX registers
    LDI UART0_TX_REGS.STATE_REG, UART_TX_START_STATE
    LDI UART0_TX_REGS.NEXT_TICK, UART_START_TICK
    LDI UART0_TX_REGS.CHAR_REG, 0
    LDI UART0_TX_REGS.CURR_BIT, 0
    LDI UART0_TX_REGS.STAT, 0   ; reset Tx status
    ; Initialize UART1 TX registers
    LDI UART1_TX_REGS.STATE_REG, UART_TX_START_STATE
    LDI UART1_TX_REGS.NEXT_TICK, UART_START_TICK
    LDI UART1_TX_REGS.CHAR_REG, 0
    LDI UART1_TX_REGS.CURR_BIT, 0
    LDI UART1_TX_REGS.STAT, 0   ; reset Tx status
    ; Initialize UART2 TX registers
    LDI UART2_TX_REGS.STATE_REG, UART_TX_START_STATE
    LDI UART2_TX_REGS.NEXT_TICK, UART_START_TICK
    LDI UART2_TX_REGS.CHAR_REG, 0
    LDI UART2_TX_REGS.CURR_BIT, 0
    LDI UART2_TX_REGS.STAT, 0   ; reset Tx status
    ; Initialize UART0 RX registers
    LDI UART0_RX_REGS.STATE_REG, UART_RX_START_STATE
    LDI UART0_RX_REGS.NEXT_TICK, UART_START_TICK
    LDI UART0_RX_REGS.CHAR_REG, 0
    LDI UART0_RX_REGS.CURR_BIT, 0
    ; Initialize UART1 RX registers
    LDI UART1_RX_REGS.STATE_REG, UART_RX_START_STATE
    LDI UART1_RX_REGS.NEXT_TICK, UART_START_TICK
    LDI UART1_RX_REGS.CHAR_REG, 0
    LDI UART1_RX_REGS.CURR_BIT, 0
    ; Initialize UART2 RX registers
    LDI UART2_RX_REGS.STATE_REG, UART_RX_START_STATE
    LDI UART2_RX_REGS.NEXT_TICK, UART_START_TICK
    LDI UART2_RX_REGS.CHAR_REG, 0
    LDI UART2_RX_REGS.CURR_BIT, 0
    
    ; Set all output pins to initial state (TX high/RTS low)
    LDI32   TEMP_R30, 0xFFFFFFFF
    MOV     r30, TEMP_R30

    ; Configure PRU cycle counter
    ; Clear the CTR_EN bit (RMW operation)
    LDI32   TEMP2_REG, PRU_CTRL_REG_BASE
    LBBO    &TEMP2_REG, TEMP2_REG, 0, PRU_CTRL_REG_BASE_SZ
    LBBO    &TEMP_REG, TEMP2_REG, ICSS_PRU_CTRL_CONTROL, 4
    CLR     TEMP_REG, TEMP_REG, 3   ; clear CTR_EN
    SBBO    &TEMP_REG, TEMP2_REG, ICSS_PRU_CTRL_CONTROL, 4
    ; Reset the COUNTER register to 0
    SBBO    &ZERO_REG, TEMP2_REG, ICSS_PRU_CTRL_CYCLE, 4
    ; Set the CTR_EN bit to kick off the cycle counter (RMW operation)
    LBBO    &TEMP_REG, TEMP2_REG, ICSS_PRU_CTRL_CONTROL, 4
    SET     TEMP_REG, TEMP_REG, 3   ; set CTR_EN
    SBBO    &TEMP_REG, TEMP2_REG, ICSS_PRU_CTRL_CONTROL, 4

    LDI CYCLE_COUNT_REG, CYCLES_PER_TICK
    
    ; Disable all UART instances
    LDI32   TEMP2_REG, UART0_CTRL
    SBBO    &ZERO_REG, TEMP2_REG, 0, UART_CTRL_SZ   ; clear enable,txEnableAck,rxEnableAck
    LDI32   TEMP2_REG, UART1_CTRL
    SBBO    &ZERO_REG, TEMP2_REG, 0, UART_CTRL_SZ   ; clear enable,txEnableAck,rxEnableAck
    LDI32   TEMP2_REG, UART2_CTRL
    SBBO    &ZERO_REG, TEMP2_REG, 0, UART_CTRL_SZ   ; clear enable,txEnableAck,rxEnableAck    
    
    ; Notify Host FW init complete
    LDI32   TEMP2_REG, ICSS_UART_GCFG_ADDR
    LBBO    &TEMP_REG, TEMP2_REG, 0, ICSS_UART_GCFG_SZ
    SET     TEMP_REG, TEMP_REG, ICSS_UART_GCFG__FW_INIT_SHIFT   ; set FW init flag
    SBBO    &TEMP_REG, TEMP2_REG, 0, ICSS_UART_GCFG_SZ

    ; reset PRU cycle counter
    LDI32   TEMP2_REG, PRU_CTRL_REG_BASE
    LBBO    &TEMP2_REG, TEMP2_REG, 0, PRU_CTRL_REG_BASE_SZ
    SBBO    &ZERO_REG, TEMP2_REG, ICSS_PRU_CTRL_CYCLE, 4
    nop
    nop
    nop
    nop
    nop

main_loop:    
        .newblock
    ; Wait for a tick to occur and then push the latest R30 and pull the latest R31
    wait_tick
    
    ; Push the latest output pins
    MOV r30, TEMP_R30
    
    ; Capture the latest input pins
    MOV TEMP_R31, r31
    
    ; Call RX Macros
    LBBO &TEMP_PIN_INT_CFG, ZERO_REG, UART0_RX_PIN_INT_CFG, UART_RX_PIN_INT_SZ ; load pin/int configuration
    rx_macro    UART0_RX_REGS, UART_RX_PIN, UART_RTS_PIN, UART0_CTRL, UART0_RX_BUFFER, UART_RX_INT_CTRL, UART_RX_INT
    LBBO &TEMP_PIN_INT_CFG, ZERO_REG, UART1_RX_PIN_INT_CFG, UART_RX_PIN_INT_SZ ; load pin/int configuration
    rx_macro    UART1_RX_REGS, UART_RX_PIN, UART_RTS_PIN, UART1_CTRL, UART1_RX_BUFFER, UART_RX_INT_CTRL, UART_RX_INT
    LBBO &TEMP_PIN_INT_CFG, ZERO_REG, UART2_RX_PIN_INT_CFG, UART_RX_PIN_INT_SZ ; load pin/int configuration
    rx_macro    UART2_RX_REGS, UART_RX_PIN, UART_RTS_PIN, UART2_CTRL, UART2_RX_BUFFER, UART_RX_INT_CTRL, UART_RX_INT
    
    ; Call TX Macros
    LBBO &TEMP_PIN_INT_CFG, ZERO_REG, UART0_TX_PIN_INT_CFG, UART_TX_PIN_INT_SZ ; load pin/int configuration
    tx_macro    UART0_TX_REGS, UART_TX_PIN, UART_CTS_PIN, UART0_CTRL, UART0_TX_BUFFER, UART_TX_INT_CTRL, UART_TX_INT
    LBBO &TEMP_PIN_INT_CFG, ZERO_REG, UART1_TX_PIN_INT_CFG, UART_TX_PIN_INT_SZ ; load pin/int configuration
    tx_macro    UART1_TX_REGS, UART_TX_PIN, UART_CTS_PIN, UART1_CTRL, UART1_TX_BUFFER, UART_TX_INT_CTRL, UART_TX_INT
    LBBO &TEMP_PIN_INT_CFG, ZERO_REG, UART2_TX_PIN_INT_CFG, UART_TX_PIN_INT_SZ ; load pin/int configuration
    tx_macro    UART2_TX_REGS, UART_TX_PIN, UART_CTS_PIN, UART2_CTRL, UART2_TX_BUFFER, UART_TX_INT_CTRL, UART_TX_INT
    
    ADD TICK_COUNT_REG, TICK_COUNT_REG, 1   ; increment system tick count
    LDI CYCLE_COUNT_REG, CYCLES_PER_TICK    ; reload cycle count register for next iteration

    ; Jump to the top of the loop
    JMP       main_loop
