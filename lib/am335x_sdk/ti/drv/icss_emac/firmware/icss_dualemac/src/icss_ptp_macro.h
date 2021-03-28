;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
; 
;   Copyright (c) 2017-2018 Texas Instruments Incorporated
; 
;  All rights reserved not granted herein.
;  
;  Limited License.  
; 
;  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive 
;  license under copyrights and patents it now or hereafter owns or controls to 
;  make, have made, use, import, offer to sell and sell ("Utilize") this software 
;  subject to the terms herein.  With respect to the foregoing patent license, 
;  such license is granted  solely to the extent that any such patent is necessary 
;  to Utilize the software alone.  The patent license shall not apply to any 
;  combinations which include this software, other than combinations with devices 
;  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
; 
;  Redistributions must preserve existing copyright notices and reproduce this license 
;  (including the above copyright notice and the disclaimer and (if applicable) source 
;  code license limitations below) in the documentation and/or other materials provided 
;  with the distribution.
;  
;  Redistribution and use in binary form, without modification, are permitted provided 
;  that the following conditions are met:
; 	No reverse engineering, decompilation, or disassembly of this software is 
;   permitted with respect to any software provided in binary form.
; 	Any redistribution and use are licensed by TI for use only with TI Devices.
; 	Nothing shall obligate TI to provide you with source code for the software 
;   licensed and provided to you in object code.
;  
;  If software source code is provided to you, modification and redistribution of the 
;  source code are permitted provided that the following conditions are met:
; 	Any redistribution and use of the source code, including any resulting derivative 
;   works, are licensed by TI for use only with TI Devices.
; 	Any redistribution and use of any object code compiled from the source code
;   and any resulting derivative works, are licensed by TI for use only with TI Devices.
; 
;  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
;  may be used to endorse or promote products derived from this software without 
;  specific prior written permission.
; 
;  DISCLAIMER.
; 
;  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S 
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   icss_ptp_macro.h
;
; brief:  Implements common macros & defines.
;
;

;---------------------------------------------------------------------------------------------------------
; Macro Name: M_SET_TX_TS_AVAILABLE_PKT_P1
; Description: Let the host know there is a Timestamp available. For Port 1
; Input Parameters: R31
; Output Parameters: none
;---------------------------------------------------------------------------------------------------------
M_SET_TX_TS_AVAILABLE_PKT_P1    .macro
    ;set an interrupt
    LDI        R31, 0x2a       ; Maps to system event 26
    .endm
    
;---------------------------------------------------------------------------------------------------------
; Macro Name: M_SET_TX_TS_AVAILABLE_PKT_P2
; Description: Let the host know there is a Timestamp available. For Port 1
; Input Parameters: R31
; Output Parameters: none
;---------------------------------------------------------------------------------------------------------
M_SET_TX_TS_AVAILABLE_PKT_P2    .macro
    ;set an interrupt
    LDI        R31, 0x2b       ; Maps to system event 27
    .endm   
    
;---------------------------------------------------------------------------------------------------------
; Macro Name: M_GPTP_ASSIGN_QOS
; Description: Assign PTP frame to highest priority queue
; Input Parameters: R31
; Output Parameters: none
;---------------------------------------------------------------------------------------------------------
M_GPTP_ASSIGN_QOS    .macro
    QBBC    NOT_A_PTP_FRAME_2, R22, RX_IS_PTP_BIT
    ;Choose highest priority queue for PTP

    .if $defined(PRU0)
        ; for host context
        LDI     RCV_TEMP_REG_1.b0, 1-1
        LDI     MII_RCV.qos_queue, 1-1   ;Choose highest priority queue for PTP
    .else   ; PRU1
        ; for host context
        LDI     RCV_TEMP_REG_1.b0, 3-1
        LDI     MII_RCV.qos_queue, 3-1   ;Choose highest priority queue for PTP
    .endif ; PRU0

    QBA     FB_QOS_LOADED
NOT_A_PTP_FRAME_2:
    .endm 
    
;---------------------------------------------------------------------------------------------------------
; Macro Name: M_GPTP_CHECK_AND_SET_FLAGS
; Description: Checks for PTP mac ID and sets host and fwd flags including the PTP R22 flag
; Peak cycles : 12
; Input Parameters: R31
; Output Parameters: none
;---------------------------------------------------------------------------------------------------------
M_GPTP_CHECK_AND_SET_FLAGS    .macro
    ;PTP_HSR_NON_LL_MAC_ID_L is 0
    QBNE    CHECK_PTP_LINK_LOCAL_RX, R3.w0, 0
    LDI32   RCV_TEMP_REG_2, PTP_HSR_PRP_NON_LL_MAC_ID_H
    QBNE    CHECK_PTP_LINK_LOCAL_RX, R2, RCV_TEMP_REG_2
    QBA     SET_PTP_TAG_RX
    
CHECK_PTP_LINK_LOCAL_RX:
    LDI     RCV_TEMP_REG_2.w0, PTP_HSR_PRP_LL_MAC_ID_L
    QBNE    CHECK_UDP_PTP, R3.w0, RCV_TEMP_REG_2.w0
    LDI32   RCV_TEMP_REG_2, PTP_HSR_PRP_LL_MAC_ID_H
    QBNE    CHECK_UDP_PTP, R2, RCV_TEMP_REG_2
    ;check for LLD frame since it has the same MAC ID
    LDI     RCV_TEMP_REG_2.w0, LLDP_EtherType
    QBEQ    CHECK_UDP_PTP, R5.w0, RCV_TEMP_REG_2.w0
SET_PTP_TAG_RX:
    SET     R22, R22, RX_IS_PTP_BIT
    SET     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift     ; set flag that host queue will receive data
    QBA     CHECK_IF_FROM_MASTER
CHECK_UDP_PTP:
    LDI     RCV_TEMP_REG_2.w0, PTP_E2E_UDP_MAC_ID_H & 0xFFFF
    LDI     RCV_TEMP_REG_2.w2, PTP_E2E_UDP_MAC_ID_H >> 16
    QBNE    GPTP_CHECK_EXIT, R2, RCV_TEMP_REG_2    
    LDI     RCV_TEMP_REG_2.w0, PTP_E2E_UDP_MAC_ID_L    
    QBNE    GPTP_CHECK_EXIT, R3.w0, RCV_TEMP_REG_2.w0
    SET     R22, R22, RX_IS_UDP_PTP_BIT
    SET     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift
   
CHECK_IF_FROM_MASTER:
    ;check if frame is from master and set flag
    ;this is used later in a segment of packet where MAC ID is not present
    ;load 6 bytes into RCV_TEMP_REG_1 and RCV_TEMP_REG_2
    LBCO    &RCV_TEMP_REG_1.w2, ICSS_SHARED_CONST, SYNC_MASTER_MAC_OFFSET, 6    
    QBNE    GPTP_CHECK_EXIT, RCV_TEMP_REG_1.w2, R3.w2    
    QBNE    GPTP_CHECK_EXIT, RCV_TEMP_REG_2, R4    
    SET     R22, R22, PTP_PKT_FROM_MASTER_RX

    ; skip any filtering + cut-through
    .if $defined(ICSS_DUAL_EMAC_BUILD)
        QBA     FB_LT_VT_2
    .endif
    ; skip filting but not cut-through
    .if $defined(ICSS_SWITCH_BUILD)
        QBA     FB_LT_VT
    .endif

GPTP_CHECK_EXIT:
    .endm     

;---------------------------------------------------------------------------------------------------------
; Macro Name: M_GPTP_CHECK_AND_SET_FLAGS_L4
; Description: Checks for PTP UDP flag and if not set checks if frame is IPv4/UDP
; Peak cycles : 5
; Input Parameters: R22
; Output Parameters: none
;---------------------------------------------------------------------------------------------------------
M_GPTP_CHECK_AND_SET_FLAGS_L4    .macro
    ; If UDP PTP bit already set then frame is PTP msg bc of MC PTP MAC
    QBBS    GPTP_CHECK_EXIT_L4?, R22, RX_IS_UDP_PTP_BIT
    CLR     R22, R22, RX_IS_VLAN_BIT
    LDI     RCV_TEMP_REG_2.w0, IPV4_EtherType
    QBNE    NO_VLAN_RX_CHECK?, R5.w0, VLAN_EtherType
    SET     R22, R22, RX_IS_VLAN_BIT
    ; Check if protocol is IPv4/UDP (PTP message may be unicast)
    QBNE    GPTP_CHECK_EXIT_L4?, R6.w0, RCV_TEMP_REG_2.w0
    QBNE    GPTP_CHECK_EXIT_L4?, IP_PROT_VLAN_REG, UDP_PROTOCOL_TYPE
    QBA     SET_RX_UDP_PTP_BIT?
NO_VLAN_RX_CHECK?:
    QBNE    GPTP_CHECK_EXIT_L4?, R5.w0, RCV_TEMP_REG_2.w0
    QBNE    GPTP_CHECK_EXIT_L4?, IP_PROT_REG, UDP_PROTOCOL_TYPE
SET_RX_UDP_PTP_BIT?:
    ; set UDP PTP bit here, but not guaranteed PTP message yet. UDP Port
    ; will be checked in second block if this bit is set, and bit cleared if not
    ; PTP message UDP port (319/320)
    SET     R22, R22, RX_IS_UDP_PTP_BIT

GPTP_CHECK_EXIT_L4?:
    .endm   
    
;---------------------------------------------------------------------------------------------------------
; Macro Name: M_GPTP_SET_CALLBACK_INTERRUPT
; Description: Give the callback interrupt to host
; Input Parameters: R22 (flag is checked)
; Output Parameters: none
;---------------------------------------------------------------------------------------------------------
M_GPTP_SET_CALLBACK_INTERRUPT    .macro
    QBBC    NOT_A_PTP_FRAME_3, R22, TX_CALLBACK_INTERRUPT_BIT
    CLR R22 , R22 , TX_CALLBACK_INTERRUPT_BIT

    .if $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")
        M_SET_TX_TS_AVAILABLE_PKT_P2
    .else
        M_SET_TX_TS_AVAILABLE_PKT_P1
    .endif ;PRU0
    .else
    .if $isdefed("PRU0")
        M_SET_TX_TS_AVAILABLE_PKT_P1
    .else
        M_SET_TX_TS_AVAILABLE_PKT_P2
    .endif ;PRU0
    .endif
NOT_A_PTP_FRAME_3:
    .endm         
    
;****************************************************************************
;
;     NAME             : M_GPTP_TX_PRE_PROC
;     DESCRIPTION      : Detect and set flag to indicate PTP frame.
;                        called during Tx
;     Cycles           : 14
;     Register Usage   : R22 (flags), R0, R10
;     Pseudocode       :
;;if ptp_enabled:
;    if ethertype not 0x88f7:
;        exit
;     else:
;        mark frame as PTP
;        if DUT is currently a master:
;            set flag indicating so
;else:
;    exit  
;                     
;
;****************************************************************************
M_GPTP_TX_PRE_PROC  .macro

    QBNE    CHECK_PTP_LINK_LOCAL_TX, R3.w0, 0
    LDI32   R10, PTP_HSR_PRP_NON_LL_MAC_ID_H
    QBNE    CHECK_PTP_LINK_LOCAL_TX, R2, R10
    QBA     SET_PTP_TAG_TX
        
CHECK_PTP_LINK_LOCAL_TX:
    LDI     R10.w0, PTP_HSR_PRP_LL_MAC_ID_L
    QBNE    CHECK_UDP_PTP_TX, R3.w0, R10.w0
    LDI32   R10, PTP_HSR_PRP_LL_MAC_ID_H
    QBNE    CHECK_UDP_PTP_TX, R2, R10 
    ;make sure we don't tag LLDP frames
    LDI     R10.w0, LLDP_EtherType
    QBEQ    CHECK_UDP_PTP_TX, R5.w0, R10.w0
SET_PTP_TAG_TX:
    SET     R22, R22, TX_IS_PTP_BIT
    QBA     CONTINUE_PRE_PROC
    
CHECK_UDP_PTP_TX:
    ; Check for UDP PTP multicast MAC
    LDI     R10.w0, PTP_E2E_UDP_MAC_ID_L
    QBNE    CHECK_UDP_TX, R3.w0, R10.w0
    LDI32   R10, PTP_E2E_UDP_MAC_ID_H
    QBNE    CHECK_UDP_TX, R2, R10 

    SET     R22, R22, TX_IS_UDP_PTP_BIT
    QBA     CONTINUE_PRE_PROC

CHECK_UDP_TX:
    CLR     R22, R22, TX_IS_VLAN_BIT
    ; Check if protocol is IPv4/UDP (PTP message may be unicast)
    LDI     R10.w0, IPV4_EtherType
    QBNE    NO_VLAN_TX_CHECK, R5.w0, VLAN_EtherType
    SET     R22, R22, TX_IS_VLAN_BIT
    QBNE    EXIT_PTP_TX_PRE_PROC, R6.w0, R10.w0
    QBNE    EXIT_PTP_TX_PRE_PROC, IP_PROT_VLAN_REG, UDP_PROTOCOL_TYPE
    QBA     SET_TX_UDP_PTP_BIT
NO_VLAN_TX_CHECK:
    QBNE    EXIT_PTP_TX_PRE_PROC, R5.w0, R10.w0
    QBNE    EXIT_PTP_TX_PRE_PROC, IP_PROT_REG, UDP_PROTOCOL_TYPE
SET_TX_UDP_PTP_BIT:
    ; set UDP PTP bit here, but not guaranteed PTP message yet. UDP Port
    ; will be checked in second block if this bit is set, and bit cleared if not
    ; PTP message UDP port (319/320)
    SET     R22, R22, TX_IS_UDP_PTP_BIT

CONTINUE_PRE_PROC:
    .if !$defined(ICSS_REV1)
    ;Just before pushing to FIFO store the current Tx SOF TS
    ;This is used for comparison later to make sure SOF has actually
    ;updated.

    .if $defined("ICSS_SWITCH_BUILD")
    .if $defined(PRU0)
        LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8
        LDI     RCV_TEMP_REG_1.w0, PTP_PREV_TX_TIMESTAMP_P2
        SBCO    &R10, ICSS_SHARED_CONST, RCV_TEMP_REG_1.w0, 8
    .else
        LBCO    &R10, ICSS_IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8
        LDI     RCV_TEMP_REG_1.w0, PTP_PREV_TX_TIMESTAMP_P1
        SBCO    &R10, ICSS_SHARED_CONST, RCV_TEMP_REG_1.w0, 8
    .endif ; PRU0
    .else
    .if $defined(PRU0)
        LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8
        LDI     RCV_TEMP_REG_1.w0, PTP_PREV_TX_TIMESTAMP_P1
        SBCO    &R10, ICSS_SHARED_CONST, RCV_TEMP_REG_1.w0, 8
    .else
        LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8
        LDI     RCV_TEMP_REG_1.w0, PTP_PREV_TX_TIMESTAMP_P2
        SBCO    &R10, ICSS_SHARED_CONST, RCV_TEMP_REG_1.w0, 8
    .endif ; PRU0
    .endif ; ICSS_SWITCH_BUILD
    .endif ; ICSS_REV1
    
    LDI     R0.w2, DUT_IS_MASTER_OFFSET
    LBCO    &R0.b0, ICSS_SHARED_CONST, R0.w2, 1
    QBNE    EXIT_PTP_TX_PRE_PROC, R0.b0, 1
    SET     R22, R22, DUT_IS_MASTER_BIT

EXIT_PTP_TX_PRE_PROC:
    .endm 
    
    
