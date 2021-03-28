;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
; 
;   Copyright (c) 2018 Texas Instruments Incorporated
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
;  manufactured by or for TI ("TI Devices").  No hardware patent is licensed hereunder.
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
;  THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S 
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   emac_ptp.asm
;
; brief:  ICSS EMAC precision time protocol

    .if !$defined(____pn_gPtp_asm)
____pn_gPtp_asm    .set    1
    .if $defined("ICSS_DUAL_EMAC_BUILD")
    .include "icss_emacSwitch.h"
    .endif
    .if $defined("ICSS_SWITCH_BUILD")	
        .include "icss_switch.h"
    .endif

    .include "icss_defines.h"
    .include "emac_MII_Xmt.h"
    .include "emac_MII_Rcv.h"
    .include "icss_ptp.h"
    .include "micro_scheduler.h"
    .include "icss_iep_regs.h"
    .include "icss_miirt_regs.h"
    .include "icss_ptp_macro.h"
    .cdecls C,NOLIST
%{
#include "icss_timeSync_memory_map.h"
%}

    .global  FN_PTP_BACKGROUND_TASK
    .global  FN_TIMESTAMP_GPTP_PACKET
    .global  FN_PTP_TX_ADD_DELAY
    .global  FN_TIMESTAMP_GPTP_PACKET_UDP
    .global  FN_PTP_TX_ADD_DELAY_UDP
    .global  FN_COMPARE_DELAY_RESP_ID

    .if $defined (ICSS_REV1)

;****************************************************************************
;
;     NAME             : FN_TIMESTAMP_GPTP_PACKET
;     DESCRIPTION      : Store timestamp for PTP frames.
;                        It is called during Rx
;     Cycles           : 34
;     Register Usage   : R22 (flags), R20, R21, R10, R11, R13
;     Pseudocode       :
;if PTP frame:
;   if not link local
;       if sync frame:
;           if PTP not enabled:
;               discard frame
;           else:
;               if not from master:
;                   do not forward to host
;               else:
;                   if first sync:
;                       update the master port
;                   take timestamp()
;       elif follow up
;           if PTP not enabled:
;               discard frame
;           else:
;               if not from master:
;                   do not forward to host
;               else:
;                   clear fwd_flag
;                   exit without timestamp
;
;   else:
;       check if hsr tag is there and load appropriate offset
;       if pdelay req frame or pdelay response frame:
;           take timestamp()
;def take_timestamp()
;   load SFD timestamp
;   exit
;else:
;   exit
;
;***************************************************************************

FN_TIMESTAMP_GPTP_PACKET:

    MOV     R11.w2, R13.w2
    QBBC    FN_TIMESTAMP_GPTP_PACKET_EXIT, R22, RX_IS_PTP_BIT
    CLR     R22, R22, RX_IS_PTP_BIT

    ;domain number check disabled for now. Will be enabled later
    ;LBCO    &R21, ICSS_SHARED_CONST, GPTP_DOMAIN_NUMBER_LIST, GPTP_NUM_DOMAINS
    ;QBEQ    GPTP_OFFSET_LOAD, Ethernet.ProtWord3, R21.b0                ; Check gPTP domain number
    ;QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT, Ethernet.ProtWord3, R21.b1                 ; Check gPTP domain number

GPTP_OFFSET_LOAD:
    LDI     R1.b0, &R5.b2
    QBNE    NO_VLAN_RX, R5.w0, VLAN_EtherType
    ADD     R1.b0, R1.b0, 4
NO_VLAN_RX:
    MVIB    R20.b0, *R1.b0
    ;check for link local vs non link local frame
    ;non link local frames have the lower 4 bytes as 0
    QBNE    PTP_LINK_LOCAL_FRAME, R3.w0, 0
    ;check for sync frame
    QBNE    CHECK_FOLLOW_UP, R20.b0, PTP_SYNC_MSG_ID
    ;-------------------process sync frames------------------;
    ;Below is a combined load to save cycles.
    ;R20.b0 tells if DUT is master. R20.b1 tells which port is connected to master
    ;and R20.w2 and R21 tell the MAC ID of the master selected by BMCA
    LBCO    &R20.w0, ICSS_SHARED_CONST, DUT_IS_MASTER_OFFSET, 8
    QBNE    DUT_IS_SLAVE_SYNC, R20.b0, 1    ; exit if DUT is configured as master, also discard frame
    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift    ; Don't forward to host
    SET     R22, R22, PTP_RELEASE_HOST_QUEUE_BIT
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

DUT_IS_SLAVE_SYNC:

    ;Master MAC ID is now in R20.w2 and R21
    ;Check against Master MAC address. R3.w2 and R4 contain source MAC address
    QBNE    FRAME_NOT_FROM_MASTER, R20.w2, R3.w2
    QBNE    FRAME_NOT_FROM_MASTER, R21, R4

    ;check for dual master on two ports.
    ;The logic works like this....initially the memory location is empty
    ;whenever the first sync arrives, the corresponding port number is written into
    ;memory location. Subsequent sync frames check against this value and they are discarded
    ;if the value in memory does not match the port number.
    QBEQ    FIRST_SYNC_FRAME, R20.b1, 0
    QBA     PTP_CHECK_FORCED_2_STEP

FIRST_SYNC_FRAME:               ;whichever port receives the sync first is assigned as master port

    .if $defined (PRU0)
    LDI     R20.b1, 1
    .else
    LDI     R20.b1, 2
    .endif
    SBCO    &R20.b1, ICSS_SHARED_CONST, MASTER_PORT_NUM_OFFSET, 1
PTP_CHECK_FORCED_2_STEP:
    ;check if this is a 1-step, if it's set and if the force 2-step bit is also set then we 
    ;don't forward the frame. Instead we send it to host which flips the two-step flag bit
    QBEQ    VLAN_TAGGED_RX, R5.w0, VLAN_EtherType
    QBBS    LOAD_TS_OFFSET_ADDR_SYNC, two_step_reg, GPTP_802_3_two_step_bit
    QBA     DONE_VLAN_CHECK_RX
VLAN_TAGGED_RX:
    QBBS    LOAD_TS_OFFSET_ADDR_SYNC, two_step_reg_vlan, GPTP_802_3_two_step_bit
DONE_VLAN_CHECK_RX:
    ;check if the forced 2-step bit is set. It's bit 1 of the value written at the location GPTP_CTRL_VAR_OFFSET
    LBCO    &R20.b0, ICSS_SHARED_CONST, TIMESYNC_CTRL_VAR_OFFSET, 1
    QBBC    LOAD_TS_OFFSET_ADDR_SYNC, R20, 1
    ;set the 2-step bit which forces setting the 2-step flag on forward path
    ;SET     R22, R22, PTP_FORCED_2_STEP_BIT
LOAD_TS_OFFSET_ADDR_SYNC:

    .if $defined (PRU0)
    LDI     R11.w0, RX_SYNC_TIMESTAMP_OFFSET_P1    ; load sync timestamp offset
    .else
    LDI     R11.w0, RX_SYNC_TIMESTAMP_OFFSET_P2
    .endif
    QBA     GPTP_STORE_TIMESTAMP    ; with the offset loaded, store the Rx timestamp

DISCARD_PTP_FRAME_RX:

    ;set error flag
    SET     MII_RCV.rx_flags, MII_RCV.rx_flags, 4

FRAME_NOT_FROM_MASTER:                                  ;if frame is not from master, it's not processed

    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift    ; Don't forward to host
    SET     R22, R22, PTP_RELEASE_HOST_QUEUE_BIT
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

CHECK_FOLLOW_UP:

    QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT, R20.b0, PTP_FOLLOW_UP_MSG_ID
    ;load the value indicating whether PTP is in uninitialized state
    LBCO    &R20.b0, ICSS_SHARED_CONST, TIMESYNC_CTRL_VAR_OFFSET, 1 
    QBEQ    DISCARD_PTP_FRAME_RX, R20.b0, 0
    ;Below is a combined load to save cycles.
    ;R20.b0 tells if DUT is master. R20.b1 tells which port is connected to master
    ;and R20.w2 and R21 tell the MAC ID of the master selected by BMCA
    LBCO    &R20.w0, ICSS_SHARED_CONST, DUT_IS_MASTER_OFFSET, 8
    QBNE    DUT_IS_SLAVE_FLW_UP, R20.b0, 1    ; exit if DUT is configured as master
    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift    ; Don't forward to host
    SET     R22, R22, PTP_RELEASE_HOST_QUEUE_BIT
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

DUT_IS_SLAVE_FLW_UP:

    ;forwarding only applies to HSR
    .if $defined (HSR)
    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, fwd_flag_shift    ; Don't forward to other port
    SET     R22, R22, PTP_RELEASE_PORT_QUEUE_BIT
    .endif ;HSR
    ;Master MAC ID is now in R20.w2 and R21
    ;Check against Master MAC address. R3.w2 and R4 contain source MAC address
    QBNE    FRAME_NOT_FROM_MASTER, R20.w2, R3.w2
    QBNE    FRAME_NOT_FROM_MASTER, R21, R4
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

PTP_LINK_LOCAL_FRAME:
PTP_LL_LOAD_PACKET_TYPE:
CHECK_PDELAY_REQ:

    QBNE    CHECK_PDELAY_RESP, R20.b0, PTP_PDLY_REQ_MSG_ID    ; Check gPTP messageType: Pdelay_Req
    .if $defined (PRU0)
    LDI     R11.w0, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P1
    .else
    LDI     R11.w0, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P2
    .endif
    QBA     GPTP_STORE_TIMESTAMP

CHECK_PDELAY_RESP:

    QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT, R20.b0, PTP_PDLY_RSP_MSG_ID    ; Check gPTP messageType: Pdelay_Resp
    .if $defined (PRU0)
    LDI     R11.w0, RX_PDELAY_RESP_TIMESTAMP_OFFSET_P1
    .else
    LDI     R11.w0, RX_PDELAY_RESP_TIMESTAMP_OFFSET_P2
    .endif

GPTP_STORE_TIMESTAMP:

    ;This also loads 2 bytes in RCV_TEMP_REG_2.w0
    LBCO    &RCV_TEMP_REG_1, ICSS_SHARED_CONST, TIMESYNC_SECONDS_COUNT_OFFSET, 6
    .if $defined (PRU0)
    LBCO    &R13, IEP_CONST, CAP_RISE_RX_SFD_PORT1_OFFSET, 4
    .else
    LBCO    &R13, IEP_CONST, CAP_RISE_RX_SFD_PORT2_OFFSET, 4
    .endif
    ;current IEP counter value
    LBCO    &R12, IEP_CONST, IEP_COUNTER_OFFSET, 4
    ;check if counter has been incremented
    LBCO    &R10.b0, IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1
    ;check if there has been a wrap around
    QBGT    NO_WRAPAROUND_SINCE_RX, R13, R12
    ;make sure counter has not incremented
    QBBS    COMPENSATION_DONE_RX, R10, 0
    LBCO    &R10, ICSS_SHARED_CONST, TIMESYNC_IEP_VAL_CYCLE_COUNTER, 4
    QBGT    COMPENSATION_DONE_RX, R12, R10
    SUB     RCV_TEMP_REG_1, RCV_TEMP_REG_1, 1
    SUC     RCV_TEMP_REG_2.w0, RCV_TEMP_REG_2.w0, 0
    QBA     COMPENSATION_DONE_RX

NO_WRAPAROUND_SINCE_RX:

    ;make sure that counter has incremented
    QBBC    COMPENSATION_DONE_RX, R10, 0
    LBCO    &R10, ICSS_SHARED_CONST, TIMESYNC_IEP_VAL_CYCLE_COUNTER, 4
    QBGT    COMPENSATION_DONE_RX, R10, R12
    ADD     RCV_TEMP_REG_1, RCV_TEMP_REG_1, 1
    ADC     RCV_TEMP_REG_2.w0, RCV_TEMP_REG_2.w0, 0

COMPENSATION_DONE_RX:

    ;Do PHY compensation
    LBCO    &R12.w0, ICSS_SHARED_CONST, MII_RX_CORRECTION_OFFSET, 2
    QBLE    NO_WRAPAROUND_RX, R13, R12.w0
    ;The seconds timestamp should be decremented by 1
    SUB     RCV_TEMP_REG_1, RCV_TEMP_REG_1, 1
    SUC     RCV_TEMP_REG_2.w0, RCV_TEMP_REG_2.w0, 0
    LDI32     R10, IEP_WRAP_AROUND_VAL
    ADD     R13, R13, R10

NO_WRAPAROUND_RX:

    SUB     R13, R13, R12.w0

PHY_COMPENSATION_DONE:

    ;store nanoseconds TS
    SBCO    &R13, ICSS_SHARED_CONST, R11.w0, 4
    ADD     R11.w0, R11.w0, 4
    ;store seconds TS
    SBCO    &RCV_TEMP_REG_1, ICSS_SHARED_CONST, R11.w0, 6

FN_TIMESTAMP_GPTP_PACKET_EXIT:

    JMP     R11.w2

;***************************************************************************
;
;     NAME             : FN_GET_TX_TIMESTAMP
;     DESCRIPTION      : calculates the Tx timestamp in seconds and nanoseconds format
;                        It is called during Tx
;     Assumption       : This uses registers R2-R6 as temp registers, They also contain Tx
;                      : data which has been pushed to FIFO. Calling function must not use
;                        the data.
;     Cycles           :
;     Return           : Returns nanoseconds in R4, Seconds in R2 and R3.w0. Return address in R0.w2
;     Register Usage   :
;     Pseudocode       :
;
;
;***************************************************************************

FN_GET_TX_TIMESTAMP:

    ;we need to make sure that the timestamp here is actual value
    ;this we do by comparing with Tx SOF of previous frame
    .if $defined("ICSS_SWITCH_BUILD")
        .if $defined (PRU0)
        LDI    R5.w0, PTP_PREV_TX_TIMESTAMP_P2
        LBCO    &R5.w0, ICSS_SHARED_CONST, R5.w0, 4
        .else
        ; LDI    R5.w0, PTP_PREV_TX_TIMESTAMP_P1
        LBCO    &R5.w0, ICSS_SHARED_CONST, PTP_PREV_TX_TIMESTAMP_P1, 4
        .endif
        ;LBCO    &R5, ICSS_SHARED_CONST, R5.w0, 4
        ; get the timestamp  
    .else
        .if $defined (PRU0)
        LDI    R5.w0, PTP_PREV_TX_TIMESTAMP_P1
        LBCO    &R5.w0, ICSS_SHARED_CONST, R5.w0, 4
        .else
        LDI    R5.w0, PTP_PREV_TX_TIMESTAMP_P2
        LBCO    &R5.w0, ICSS_SHARED_CONST, R5.w0, 4
        .endif
        ;LBCO    &R5, ICSS_SHARED_CONST, R5.w0, 4
        ; get the timestamp
    .endif ; switch build

LOAD_TX_SOF_TS:

    .if $defined("ICSS_SWITCH_BUILD")
    .if $defined (PRU0)
    LBCO    &R4, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 4
    .else
    LBCO    &R4, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 4
    .endif
    .else
    .if $defined (PRU0)
    LBCO    &R4, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 4
    .else
    LBCO    &R4, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 4
    .endif
    .endif

    QBEQ    LOAD_TX_SOF_TS, R4, R5

    ;This also loads 2 bytes in R3.w0
    LBCO    &R2, ICSS_SHARED_CONST, TIMESYNC_SECONDS_COUNT_OFFSET, 6

    ;current IEP counter value
    LBCO    &R5, IEP_CONST, IEP_COUNTER_OFFSET, 4
    ;check if counter has been incremented
    LBCO    &R11.b0, IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1
    ;check if there has been a wrap around
    QBGT    NO_WRAPAROUND_SINCE_TX, R4, R5
    ;make sure counter has not incremented
    QBBS    COMPENSATION_DONE_TX, R11, 0
    LBCO    &R10, ICSS_SHARED_CONST, TIMESYNC_IEP_VAL_CYCLE_COUNTER, 4
    QBGT    COMPENSATION_DONE_TX, R5, R10
    SUB     R2, R2, 1
    SUC     R3.w0, R3.w0, 0
    QBA     COMPENSATION_DONE_TX

NO_WRAPAROUND_SINCE_TX:

    ;make sure that counter has incremented
    QBBC    COMPENSATION_DONE_TX, R11, 0
    LBCO    &R10, ICSS_SHARED_CONST, TIMESYNC_IEP_VAL_CYCLE_COUNTER, 4
    QBGT    COMPENSATION_DONE_TX, R10, R5
    ADD     R2, R2, 1
    ADC     R3.w0, R3.w0, 0

COMPENSATION_DONE_TX:

    LDI32     R10, IEP_WRAP_AROUND_VAL
    ;Do PHY compensation
    LBCO    &R5.w0, ICSS_SHARED_CONST, MII_TX_CORRECTION_OFFSET, 2
    ADD     R4, R4, R5.w0
    QBGT    NO_WRAPAROUND_TX, R4, R10
    ;Add 1 to seconds timestamp
    ADD     R2, R2, 1
    ADC     R3.w0, R3.w0, 0
    SUB     R4, R10, R4

NO_WRAPAROUND_TX:

    ;nanoseconds in R4 and seconds in R2 and R3.w0

    JMP     R0.w2

;***************************************************************************
;
;     NAME             : FN_PTP_TX_ADD_DELAY
;     DESCRIPTION      : 1. Function for measuring bridge delay
;                        2. In Sync frames
;                        3. For Pdelay Response frames
;                        4. For storing Tx timestamp for Sync and Pdelay Req frames
;     Cycles           : 75 PRU cycles (worst case)
;     Register Usage   : R22 (flags), R0, R13, R25, R26, R28, R29
;     Pseudocode       :
;22 bytes have been put in Tx FIFO
;if ptp frame:
;   load tx SOF timestamp
;   do phy delay correction on tx SOF
;   if link local frame:
;       if Pdelay Request frame:
;           store tx SOF TS
;           indicate that this is a Pdelay request frame (by writing into shared memory)
;           set flag for Tx callback interrupt
;       elif Pdelay response frame:
;           store tx SOF TS
;           indicate that this is a Pdelay response frame (by writing into shared memory)
;           set flag for Tx callback interrupt
;    else: Not a link local frame
;       if sync frame:
;           if not two-step:
;               store tx SOF TS
;               indicate that this is a sync frame (by writing into shared memory)
;               set flag for Tx callback interrupt
;
;           else: single step
;               if DUT is master:
;                   if frame is from some other device:
;                       exit
;                   else:
;                       add origin timestamp (see logic below)
;               else:
;                   Do Bridge delay computation
;                   calculate BD from Tx SOF and Rx timestamp
;                   Multiply by RCF
;                   Add peer delay and store back
;
;else:
;   exit

;--------------Logic for adding 1-step origin Timestamp----------
;
;   The logic here works like this
;   Assume three timestamps Y, Y' and Z
;   Y--------------Y'----------------Z
;    Z is the start of the seconds cycle i.e. nanoseconds value of 0
;    Y denotes current time inside this function which is invoked
;    just before transmitting the sync frame. Y' is the actual Tx SOF timestamp
;    and is guaranteed to be within few microsends/miliseconds ahead of Y.
;    Now three possible cases exist
;    Y-----Z-----Y' in which case Y' lies in the next cycle
;    Y-----Y'----Z  in which case Y' is in current cycle
;    corner cases in which Y == Z and Y' == Z also fall under the above 2
;
;    In firmware the timestamp Y' is compared against Z and it is determined
;    whether it falls in next or previous cycle. The corresponding seconds value
;    of Z is then used to get the seconds value. Nanoseconds value is obtained by
;    subtraction and long division and reminder operation is avoided.
;
;    Compare the timestamps and determine the cycle
;    if current cycle:
;       subtract 1 from stored value to get seconds
;       get nanoseconds value by subtracting from stored value and then from 1x10^9
;    else:
;       stored value is the seconds value
;       subtract from stored value to get nanoseconds value
;    store second and nanoseconds values
;
;
;
;***************************************************************************

FN_PTP_TX_ADD_DELAY:

    QBBC    EXIT_PTP_TX_ADD_DELAY, R22, TX_IS_PTP_BIT
    CLR     R22, R22, TX_IS_PTP_BIT

    ;check if frame carries VLAN tag
    LDI     R1.b0, &R5.b2
    QBNE    NO_VLAN_TX, R5.w0, VLAN_EtherType
    ADD     R1.b0, R1.b0, 4
NO_VLAN_TX:
    MVIB    R25.b0, *R1.b0
    ;check if non link local
    QBEQ    PTP_NOT_LINK_LOCAL, R3.w0, 0

NO_HSR_TAG_TX:

    MVIB    R25.b0, *R1.b0

    QBNE    NOT_PDELAY_REQ_TX, R25.b0, PTP_PDLY_REQ_MSG_ID
    ;***************************PDELAY REQ PACKET PROCESSING***************************
    ;Take timestamp T1 here
    JAL     R0.w2, FN_GET_TX_TIMESTAMP

    .if $defined("ICSS_SWITCH_BUILD")
    .if $defined (PRU0)
    LDI     R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P2
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P2
    .else
    LDI     R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P1
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P1
    .endif
    .else
    .if $defined (PRU0)
    LDI     R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P1
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P1
    .else
    LDI     R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P2
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P2
    .endif
    .endif
    ;Store the Tx TS, set flag for
    QBA     STORE_TX_TS_SET_FLAG_EXIT

NOT_PDELAY_REQ_TX:

    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.b0, PTP_PDLY_RSP_MSG_ID

    ;***************************PDELAY RES PACKET PROCESSING***************************
    ;Load the Delay Request Timestamp to compute T3 - T2
    ;Load T2, we are echoing back here so load same port timestamps
    ;Store the Tx timestamp
    JAL     R0.w2, FN_GET_TX_TIMESTAMP

    .if $defined("ICSS_SWITCH_BUILD")
    .if $defined (PRU0)
    LDI     R10.w0, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P2
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P2
    .else
    LDI     R10.w0, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P1
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P1
    .endif
    .else
    .if $defined (PRU0)
    LDI     R10.w0, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P1
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P1
    .else
    LDI     R10.w0, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P2
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P2
    .endif
    .endif

    ;Store the Tx TS, set flag for
    QBA     STORE_TX_TS_SET_FLAG_EXIT

PTP_NOT_LINK_LOCAL:

    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.b0, PTP_SYNC_MSG_ID
    ;***************************SYNC PACKET PROCESSING***************************
    ;check for two-step
    QBEQ    VLAN_TAGGED_TX, R5.w0, VLAN_EtherType
    QBBC    DUT_IS_SINGLE_STEP, two_step_reg, GPTP_802_3_two_step_bit
    QBA     DONE_VLAN_CHECK_TX
VLAN_TAGGED_TX:
    QBBC    DUT_IS_SINGLE_STEP, two_step_reg_vlan, GPTP_802_3_two_step_bit
DONE_VLAN_CHECK_TX:

    ;processing two-step sync frame
    ;Irrespective of slave/master status we just store timestamp and
    ;set flag to give a callback interrupt

    JAL     R0.w2, FN_GET_TX_TIMESTAMP

    .if $defined("ICSS_SWITCH_BUILD")
    .if $defined (PRU0)
    LDI     R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P2
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P2
    .else
    LDI     R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P1
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P1
    .endif
    .else
    .if $defined (PRU0)
    LDI     R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P1
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P1
    .else
    LDI     R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P2
    LDI     R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P2
    .endif
    .endif

    ;Store the Tx TS, set flag for
    QBA     STORE_TX_TS_SET_FLAG_EXIT

DUT_IS_SINGLE_STEP:

    ;check if we are in master mode, if yes then set flag and exit
    QBBC    SYNC_SLAVE_PROCESSING, R22, DUT_IS_MASTER_BIT
    ;check if the frame is from host, else we exit. TODO : Do it using Buffer desc
    LDI     R25.w0, PORT_MAC_ADDR
    LBCO    &R25.w2, PRU_CROSS_DMEM, R25.w0, 6
    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.w2, R3.w2
    QBNE    EXIT_PTP_TX_ADD_DELAY, R26, R4

STORE_TS_IN_FRAME:

    ;Since we are in the first 32 bytes of the frame, we need
    ;to write the outoing origin TS in L3 memory since it lies
    ;in the 32-64 byte offset of the frame
    ;get the timestamp
    JAL     R0.w2, FN_GET_TX_TIMESTAMP

    ;load the offset for the correction field in L3
    MOV     R0.w2, BUFFER_INDEX
    ADD     R0.w2, R0.w2, 32

    QBNE    NO_QUEUE_WRAP_XMT_PTP_1, BUFFER_DESC_OFFSET, TOP_MOST_BUFFER_DESC_OFFSET
    QBBS    NO_QUEUE_WRAP_XMT_PTP_1, R13, 2    ; PACKET_FROM_COLL_QUEUE
    MOV     R0.w2, BUFFER_OFFSET

NO_QUEUE_WRAP_XMT_PTP_1:

    ;Add offset to reach the start of origin timestamp
    ;from the start of 32 byte block. This offset differs
    ;for HSR and PRP due to presence of HSR tag

    .if $defined (HSR)
    ADD     R0.w2, R0.w2, 22
    .endif ;HSR

    .if $defined (PRP)
    ADD     R0.w2, R0.w2, 16
    .endif ;PRP

    ;We need to convert to big endian to write back

    ;Registers R5.w2, R6 and R10 are free

    ;convert seconds to big endian first
    MOV     R6.b3, R2.b0
    MOV     R6.b2, R2.b1
    MOV     R6.b1, R2.b2
    MOV     R6.b0, R2.b3
    MOV     R5.b3, R3.b0
    MOV     R5.b2, R3.b1

    ;store nanoseconds to big endian next
    MOV     R10.b3, R4.b0
    MOV     R10.b2, R4.b1
    MOV     R10.b1, R4.b2
    MOV     R10.b0, R4.b3

    ;First write the seconds part
    SBCO    &R5.b2, L3_OCMC_RAM_CONST, R0.w2, 6
    ADD     R0.w2, R0.w2, 6
    ;write nanoseconds
    SBCO    &R10, L3_OCMC_RAM_CONST, R0.w2, 4

    QBA     EXIT_PTP_TX_ADD_DELAY

SYNC_SLAVE_PROCESSING:

    ;In PRP there is no forwarding and hence no bridge delay to calculate
    .if $defined (PRP)
    QBA     EXIT_PTP_TX_ADD_DELAY
    .endif ;PRP

    ;check against master MAC ID, if no match then exit
    ;else we do bridge delay correction here
    LBCO    &R25.w2, ICSS_SHARED_CONST, SYNC_MASTER_MAC_OFFSET, 6
    ;master MAC is in R25.w2 and R26
    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.w2, R3.w2
    QBNE    EXIT_PTP_TX_ADD_DELAY, R26, R4

    ;get the timestamp
    JAL     R0.w2, FN_GET_TX_TIMESTAMP

    .if $defined (PRU0)
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P1, 4
    .else
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P2, 4
    .endif

CALC_BD_PTP_TX_PRE_PROC:

    ;calculate bridge delay, taking care of wraparound
    ;bridge delay is in R10 after this
    QBGE    TX_TS_NO_WRAPAROUND, R25, R4
    ; Fill with saturation value for wraparound calc
    LDI32     R26, IEP_WRAP_AROUND_VAL
    ADD     R4, R26, R4

TX_TS_NO_WRAPAROUND:

    SUB     R10, R4, R25

MULTIPLY_WITH_RCF:

    ;multiply with syntonization factor
    ;RCF is stored in the form of RCF * 1024 in
    ;TIMESYNC_TC_RCF_OFFSET. A division by 1024 is done at the end
    ;to get the result as BD * RCF.
    ;Use the MAC unit of PRU to do the multiplication
    ADD     R28, R10, 0
    LDI     R29.w0, TIMESYNC_TC_RCF_OFFSET
    LBCO    &R29, ICSS_SHARED_CONST, R29.w0, 4
    LDI     R25, 0
    XOUT    0, &R25, 1
    XIN     0, &R26, 8
    LSR     R10, R26, 10

SYNC_ADD_PEER_DELAY:

    ;load the peer delay for the other port and add to the bridge delay in R10
    ;R10 has BD + Peer delay after this
    .if $defined (PRU0)
    LBCO    &R25, ICSS_SHARED_CONST, P1_SMA_LINE_DELAY_OFFSET, 4
    .else
    LBCO    &R25, ICSS_SHARED_CONST, P2_SMA_LINE_DELAY_OFFSET, 4
    .endif
    ADD     R10, R10, R25

ADD_CORR_FIELD_PTP_TX_PRE_PROC:

    ;add BD to the correction field of sync frame
    ;copy the correction in R10 in little endian format, add and then put it back in big endian format
    ;Since for HSR the correction field lies across the 32 byte boundary we load
    ;the correction field from L3 memory, modify the upper 4 bytes which are within the
    ;first 32 bytes and the remaining 2 bytes are modified and stored back in L3 memory

    ;load the correction field from memory
    MOV     R25.w2, BUFFER_INDEX
    ADD     R25.w2, R25.w2, 32

    QBNE    NO_QUEUE_WRAP_XMT_PTP, BUFFER_DESC_OFFSET, TOP_MOST_BUFFER_DESC_OFFSET
    QBBS    NO_QUEUE_WRAP_XMT_PTP, R13, 2    ; PACKET_FROM_COLL_QUEUE
    MOV     R25.w2, BUFFER_OFFSET

NO_QUEUE_WRAP_XMT_PTP:

    ;load 2 bytes of correction field which lie in 32-64 byte segment
    LBCO    &R0.w2, L3_OCMC_RAM_CONST, R25.w2, 2

    ;reorder (big to little endian) correction field and add the bridge delay
    MOV     R21.b3, R9.b2
    MOV     R21.b2, R9.b3
    MOV     R21.b1, R0.b2
    MOV     R21.b0, R0.b3

    MOV     R20.b1, R9.b0
    MOV     R20.b0, R9.b1

    ;add and get the value
    LDI     R13.w0, 0
    ADD     R10, R10, R21
    ADC     R0.w2, R20.w0, R13.w0

    ;store the 4 partial values which lie in 0-32 byte segment
    MOV     R9.b3, R10.b2
    MOV     R9.b2, R10.b3
    MOV     R9.b1, R0.b2
    MOV     R9.b0, R0.b3

    ;store back the 2-bytes in 32-64 byte segment
    ;the firmware will pick it up later and put it on the wire
    MOV     R25.b0, R10.b1
    MOV     R25.b1, R10.b0
    SBCO    &R25.w0, L3_OCMC_RAM_CONST, R25.w2, 2
    QBA     EXIT_PTP_TX_ADD_DELAY

STORE_TX_TS_SET_FLAG_EXIT:

    ;nanoseconds in R4, Seconds in R2 and R3.w0
    ;TS offset is in R10.w0 and notification offset in R10.w2
    SBCO    &R4, ICSS_SHARED_CONST, R10.w0, 4
    ADD     R10.w0, R10.w0, 4
    SBCO    &R2, ICSS_SHARED_CONST, R10.w0, 6

    ;store notification
    LDI     R25.b2, 1
    SBCO    &R25.b2, ICSS_SHARED_CONST, R10.w2, 1
    ;set indicator for callback interrupt
    SET     R22, R22, TX_CALLBACK_INTERRUPT_BIT

EXIT_PTP_TX_ADD_DELAY:

    JMP     R0.w0

    .if $defined (PRU0)

;***************************************************************************
;
;     NAME             : FN_PTP_BACKGROUND_TASK
;     DESCRIPTION      : Background task which reprograms CMP1 and disables/enables
;                        Sync0 for 1PPS output
;     Cycles           : 30 PRU cycles (worst case)
;     Register Usage   : R22 (flags), R0, R2, R3, R12, R13, R20, R21
;     Pseudocode       :
;
;
;***************************************************************************

FN_PTP_BACKGROUND_TASK:

    ;check if compare0 has been asserted and increment counter
    LBCO    &TEMP_REG_3.b0, IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1
    ;load IEP Counter for later usage
    LBCO    &RCV_TEMP_REG_1, IEP_CONST, IEP_COUNTER_OFFSET, 4
    QBBC    CHECK_CMP1, TEMP_REG_3, 0
    LDI     TEMP_REG_3.b2, 1
    ;clear the status
    SBCO    &TEMP_REG_3.b2, IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1
    ;increment the counter
    LBCO    &TEMP_REG_4, ICSS_SHARED_CONST, TIMESYNC_SECONDS_COUNT_OFFSET, 6
    ADD     TEMP_REG_4, TEMP_REG_4, 1
    ADC     TEMP_REG_2.w0, TEMP_REG_2.w0, 0
    SBCO    &TEMP_REG_4, ICSS_SHARED_CONST, TIMESYNC_SECONDS_COUNT_OFFSET, 6

    ;save the current IEP value for comparison later
    SBCO    &RCV_TEMP_REG_1, ICSS_SHARED_CONST, TIMESYNC_IEP_VAL_CYCLE_COUNTER, 4

CHECK_CMP1:
    ;check PTP enable bit and exit if not enabled
    LBCO    &TEMP_REG_3.b2, ICSS_SHARED_CONST, TIMESYNC_CTRL_VAR_OFFSET, 1
    QBBC    EXIT_PTP_BACKGROUND_TASK, TEMP_REG_3.b2, GPTP_ENABLE_BG_TASK_BIT

    QBBC    CHECK_SYNC0_SIGNAL, TEMP_REG_3, 1
    SET     R22, R22, CHECK_SYNC0_BIT
    LBCO    &RCV_TEMP_REG_4, IEP_CONST, ICSS_IEP_CMP1_REG, 4
    ;read cmp1 register and reprogram the value
    LBCO    &RCV_TEMP_REG_2, ICSS_SHARED_CONST, TIMESYNC_CMP1_PERIOD_OFFSET, 4
    LBCO    &TEMP_REG_1, ICSS_SHARED_CONST, TIMESYNC_SYNC0_WIDTH_OFFSET, 4
    ADD     RCV_TEMP_REG_3, RCV_TEMP_REG_4, TEMP_REG_1
    ADD     RCV_TEMP_REG_4, RCV_TEMP_REG_4, RCV_TEMP_REG_2
    LDI32     R25, IEP_WRAP_AROUND_VAL
    QBLE    CMP1_IS_LESS_THAN_WRAPAROUND, R25, RCV_TEMP_REG_4
    MOV     RCV_TEMP_REG_4, RCV_TEMP_REG_2
    MOV     RCV_TEMP_REG_3, TEMP_REG_1

CMP1_IS_LESS_THAN_WRAPAROUND:

    SBCO    &RCV_TEMP_REG_4, IEP_CONST, ICSS_IEP_CMP1_REG, 4
    SBCO    &RCV_TEMP_REG_3, ICSS_SHARED_CONST, TIMESYNC_SYNC0_CMP_VALUE, 4
    LDI     TEMP_REG_3.b2, 2
    SBCO    &TEMP_REG_3.b2, IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1
    QBA     EXIT_PTP_BACKGROUND_TASK

CHECK_SYNC0_SIGNAL:

    QBBC    EXIT_PTP_BACKGROUND_TASK, R22, CHECK_SYNC0_BIT
    LBCO    &RCV_TEMP_REG_4, ICSS_SHARED_CONST, TIMESYNC_SYNC0_CMP_VALUE, 4
    QBLE    SYNC0_STILL_HIGH, RCV_TEMP_REG_4, RCV_TEMP_REG_1
    CLR     R22, R22, CHECK_SYNC0_BIT
    ;disable and enable the sync0
    LDI     TEMP_REG_4.b0, 0
    LDI     TEMP_REG_4.w2, IEP_SYNC_CTRL_REG    ; clear sync enable
    SBCO    &TEMP_REG_4.b0, IEP_CONST, TEMP_REG_4.w2, 1
    LDI     TEMP_REG_4.b0, 0x3    ; set sync enable
    SBCO    &TEMP_REG_4.b0, IEP_CONST, TEMP_REG_4.w2, 1

SYNC0_STILL_HIGH:

EXIT_PTP_BACKGROUND_TASK:

    JMP     CALL_REG     
    .endif ;PRU0

    .else

;****************************************************************************
;
;     NAME             : FN_TIMESTAMP_GPTP_PACKET
;     DESCRIPTION      : Store timestamp for PTP frames.
;                        It is called during Rx
;     Cycles           : 34
;     Register Usage   : R22 (flags), R20, R21, R10, R11, R13
;     Pseudocode       :
;if PTP frame:
;   if not link local
;       if sync frame:
;           if PTP not enabled:
;               discard frame
;           else:
;               if not from master:
;                   do not forward to host
;               else:
;                   if first sync:
;                       update the master port
;                   take timestamp()
;       elif follow up
;           if PTP not enabled:
;               discard frame
;           else:
;               if not from master:
;                   do not forward to host
;               else:
;                   clear fwd_flag
;                   exit without timestamp
;
;   else:
;       check if hsr tag is there and load appropriate offset
;       if pdelay req frame or pdelay response frame:
;           take timestamp()
;def take_timestamp()
;   load SFD timestamp
;   exit
;else:
;   exit
;
;****************************************************************************

FN_TIMESTAMP_GPTP_PACKET:
    QBBC    FN_TIMESTAMP_GPTP_PACKET_EXIT, R22, RX_IS_PTP_BIT
    CLR     R22, R22, RX_IS_PTP_BIT

    ;domain number check disabled for now. Will be enabled later
    ;LBCO    &R21, ICSS_SHARED_CONST, GPTP_DOMAIN_NUMBER_LIST, GPTP_NUM_DOMAINS
    ;QBEQ    GPTP_OFFSET_LOAD, Ethernet.ProtWord3, R21.b0                ; Check gPTP domain number
    ;QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT, Ethernet.ProtWord3, R21.b1                 ; Check gPTP domain number

GPTP_OFFSET_LOAD:
    

    LDI     R1.b0, &R5.b2
    QBNE    NO_VLAN_RX, R5.w0, VLAN_EtherType
    ADD     R1.b0, R1.b0, 4
NO_VLAN_RX:
    MVIB    R20.b0, *R1.b0
    ;check for link local vs non link local frame
    ;non link local frames have the lower 4 bytes as 0
    QBNE    PTP_LINK_LOCAL_FRAME, R3.w0, 0
    ;check for sync frame
    QBNE    CHECK_FOLLOW_UP, R20.b0, PTP_SYNC_MSG_ID
    ;--------------------process sync frames------------------;
    ;Below is a combined load to save cycles.
    ;R20.b0 tells if DUT is master. R20.b1 tells which port is connected to master
    ;and R20.w2 and R21 tell the MAC ID of the master selected by BMCA
    LBCO    &R20.w0, ICSS_SHARED_CONST, DUT_IS_MASTER_OFFSET, 8
    QBNE    DUT_IS_SLAVE_SYNC, R20.b0, 1    ; exit if DUT is configured as master, also discard frame
    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift    ; Don't forward to host
    SET     R22, R22, PTP_RELEASE_HOST_QUEUE_BIT
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

DUT_IS_SLAVE_SYNC:

    ;Master MAC ID is now in R20.w2 and R21
    ;Check against Master MAC address. R3.w2 and R4 contain source MAC address
    QBNE    FRAME_NOT_FROM_MASTER, R20.w2, R3.w2
    QBNE    FRAME_NOT_FROM_MASTER, R21, R4

    ;check for dual master on two ports.
    ;The logic works like this....initially the memory location is empty
    ;whenever the first sync arrives, the corresponding port number is written into
    ;memory location. Subsequent sync frames check against this value and they are discarded
    ;if the value in memory does not match the port number.
    QBEQ    FIRST_SYNC_FRAME, R20.b1, 0
    QBA     PTP_CHECK_FORCED_2_STEP

FIRST_SYNC_FRAME:               ;whichever port receives the sync first is assigned as master port

    .if $isdefed("PRU0")
    LDI     R20.b1, 1
    .else
    LDI     R20.b1, 2
    .endif 
    SBCO    &R20.b1, ICSS_SHARED_CONST, MASTER_PORT_NUM_OFFSET, 1
    
PTP_CHECK_FORCED_2_STEP:
    ;check if this is a 1-step, if it's set and if the force 2-step bit is also set then we 
    ;don't forward the frame. Instead we send it to host which flips the two-step flag bit
    QBEQ    VLAN_TAGGED_RX, R5.w0, VLAN_EtherType
    QBBS    LOAD_TS_OFFSET_ADDR_SYNC, two_step_reg, GPTP_802_3_two_step_bit
    QBA     DONE_VLAN_CHECK_RX
VLAN_TAGGED_RX:
    QBBS    LOAD_TS_OFFSET_ADDR_SYNC, two_step_reg_vlan, GPTP_802_3_two_step_bit
DONE_VLAN_CHECK_RX:
    ;check if the forced 2-step bit is set. It's bit 1 of the value written at the location GPTP_CTRL_VAR_OFFSET
    LBCO    &R20.b0, ICSS_SHARED_CONST, TIMESYNC_CTRL_VAR_OFFSET, 1
    QBBC    LOAD_TS_OFFSET_ADDR_SYNC, R20, 1
    ;set the 2-step bit which forces setting the 2-step flag on forward path
    ;SET     R22, R22, PTP_FORCED_2_STEP_BIT

LOAD_TS_OFFSET_ADDR_SYNC:

    .if $isdefed("PRU0")
    LDI     R13.w0, RX_SYNC_TIMESTAMP_OFFSET_P1    ; load sync timestamp offset
    .else
    LDI     R13.w0, RX_SYNC_TIMESTAMP_OFFSET_P2
    .endif        
    QBA     GPTP_STORE_TIMESTAMP    ; with the offset loaded, store the Rx timestamp

DISCARD_PTP_FRAME_RX:

    ;set error flag
    SET     MII_RCV.rx_flags, MII_RCV.rx_flags, rx_frame_error_shift

FRAME_NOT_FROM_MASTER:                                  ;if frame is not from master, it's not processed

    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift    ; Don't forward to host
    SET     R22, R22, PTP_RELEASE_HOST_QUEUE_BIT
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

CHECK_FOLLOW_UP:

    QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT, R20.b0, PTP_FOLLOW_UP_MSG_ID
    ;load the value indicating whether PTP is in uninitialized state
    LBCO    &R20.b0, ICSS_SHARED_CONST, TIMESYNC_CTRL_VAR_OFFSET, 1 
    QBEQ    DISCARD_PTP_FRAME_RX, R20.b0, 0
    ;Below is a combined load to save cycles.
    ;R20.b0 tells if DUT is master. R20.b1 tells which port is connected to master
    ;and R20.w2 and R21 tell the MAC ID of the master selected by BMCA
    LBCO    &R20.w0, ICSS_SHARED_CONST, DUT_IS_MASTER_OFFSET, 8
    QBNE    DUT_IS_SLAVE_FLW_UP, R20.b0, 1    ; exit if DUT is configured as master
    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift    ; Don't forward to host
    SET     R22, R22, PTP_RELEASE_HOST_QUEUE_BIT
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

DUT_IS_SLAVE_FLW_UP:

    ;forwarding only applies to HSR
    .if $defined(HSR)
    CLR     MII_RCV.rx_flags, MII_RCV.rx_flags, fwd_flag_shift    ; Don't forward to other port
    SET     R22, R22, PTP_RELEASE_PORT_QUEUE_BIT
    .endif ;HSR
    ;Master MAC ID is now in R20.w2 and R21
    ;Check against Master MAC address. R3.w2 and R4 contain source MAC address
    QBNE    FRAME_NOT_FROM_MASTER, R20.w2, R3.w2
    QBNE    FRAME_NOT_FROM_MASTER, R21, R4
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT

PTP_LINK_LOCAL_FRAME:
PTP_LL_LOAD_PACKET_TYPE:
CHECK_PDELAY_REQ:

    QBNE    CHECK_PDELAY_RESP, R20.b0, PTP_PDLY_REQ_MSG_ID    ; Check gPTP messageType: Pdelay_Req
    .if $isdefed("PRU0")
    LDI     R13.w0, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P1
    .else
    LDI     R13.w0, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P2
    .endif
    QBA     GPTP_STORE_TIMESTAMP

CHECK_PDELAY_RESP:

    QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT, R20.b0, PTP_PDLY_RSP_MSG_ID    ; Check gPTP messageType: Pdelay_Resp
    .if $isdefed("PRU0")
    LDI     R13.w0, RX_PDELAY_RESP_TIMESTAMP_OFFSET_P1
    .else
    LDI     R13.w0, RX_PDELAY_RESP_TIMESTAMP_OFFSET_P2
    .endif

GPTP_STORE_TIMESTAMP:

    .if $isdefed("PRU0")
    LBCO    &R20, IEP_CONST, CAP_RISE_RX_SFD_PORT1_OFFSET, 8    ; Load RX SFD
    .else
    LBCO    &R20, IEP_CONST, CAP_RISE_RX_SFD_PORT2_OFFSET, 8    ; Load RX SFD
    .endif
    ;subtract rx correction and store the timestamp
    LDI     R11.w2, MII_RX_CORRECTION_OFFSET
    LBCO    &R11.w0, ICSS_SHARED_CONST, R11.w2, 2
    SUB     R20, R20, R11.w0
    SUC     R21, R21, 0

    SBCO    &R20, ICSS_SHARED_CONST, R13.w0, 8

FN_TIMESTAMP_GPTP_PACKET_EXIT:

    JMP     RCV_TEMP_REG_3.w2

;****************************************************************************
;
;     NAME             : FN_PTP_TX_ADD_DELAY
;     DESCRIPTION      : 1. Function for measuring bridge delay
;                        2. In Sync frames
;                        3. For Pdelay Response frames
;                        4. For storing Tx timestamp for Sync and Pdelay Req frames
;     Cycles           : 75 PRU cycles (worst case)
;     Register Usage   : R22 (flags), R0, R13, R25, R26, R28, R29
;     Pseudocode       :
;22 bytes have been put in Tx FIFO
;if ptp frame:
;   load tx SOF timestamp
;   do phy delay correction on tx SOF
;   if link local frame:
;       if Pdelay Request frame:
;           store tx SOF TS
;           indicate that this is a Pdelay request frame (by writing into shared memory)
;           set flag for Tx callback interrupt
;       elif Pdelay response frame:
;           store tx SOF TS
;           indicate that this is a Pdelay response frame (by writing into shared memory)
;           set flag for Tx callback interrupt
;    else: Not a link local frame
;       if sync frame:
;           if not two-step:
;               store tx SOF TS
;               indicate that this is a sync frame (by writing into shared memory)
;               set flag for Tx callback interrupt
;
;           else: single step
;               if DUT is master:
;                   if frame is from some other device:
;                       exit
;                   else:
;                       add origin timestamp (see logic below)
;               else:
;                   Do Bridge delay computation
;                   calculate BD from Tx SOF and Rx timestamp
;                   Multiply by RCF
;                   Add peer delay and store back
;
;else:
;   exit

;---------------Logic for adding 1-step origin Timestamp----------
;
;   The logic here works like this
;   Assume three timestamps Y, Y' and Z
;   Y--------------Y'----------------Z
;    Z is the start of the seconds cycle i.e. nanoseconds value of 0
;    Y denotes current time inside this function which is invoked
;    just before transmitting the sync frame. Y' is the actual Tx SOF timestamp
;    and is guaranteed to be within few microsends/miliseconds ahead of Y.
;    Now three possible cases exist
;    Y-----Z-----Y' in which case Y' lies in the next cycle
;    Y-----Y'----Z  in which case Y' is in current cycle
;    corner cases in which Y == Z and Y' == Z also fall under the above 2
;
;    In firmware the timestamp Y' is compared against Z and it is determined
;    whether it falls in next or previous cycle. The corresponding seconds value
;    of Z is then used to get the seconds value. Nanoseconds value is obtained by
;    subtraction and long division and reminder operation is avoided.
;
;    Compare the timestamps and determine the cycle
;    if current cycle:
;       subtract 1 from stored value to get seconds
;       get nanoseconds value by subtracting from stored value and then from 1x10^9
;    else:
;       stored value is the seconds value
;       subtract from stored value to get nanoseconds value
;    store second and nanoseconds values
;
;
;
;****************************************************************************

FN_PTP_TX_ADD_DELAY:
    QBBC    EXIT_PTP_TX_ADD_DELAY, R22, TX_IS_PTP_BIT
    CLR     R22, R22, TX_IS_PTP_BIT

    ;we need to make sure that the timestamp here is actual value
    ;this we do by comparing with Tx SOF of previous frame
    .if    $isdefed("PRU0")
    LDI     R20.w0, PTP_PREV_TX_TIMESTAMP_P1
    .else
    LDI     R20.w0, PTP_PREV_TX_TIMESTAMP_P2
    .endif
    LBCO    &R20, ICSS_SHARED_CONST, R20.w0, 8
    ;get the timestamp

LOAD_TX_SOF_TS:
    
    .if  $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8
    .else
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8
    .endif
    .else
    .if    $isdefed("PRU0")
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8
    .else
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8
    .endif
    .endif

    QBNE    TX_SOF_OK, R10, R20
    QBEQ    LOAD_TX_SOF_TS, R11, R21

TX_SOF_OK:

    ;Do phy delay correction here
    LDI     R0.w2, MII_TX_CORRECTION_OFFSET
    LBCO    &R25.w0, ICSS_SHARED_CONST, R0.w2, 2
    ADD     R10, R10, R25.w0
    ADC     R11, R11, 0
    ;check if frame carries VLAN tag
    LDI     R1.b0, &R5.b2
    QBNE    NO_VLAN_TX, R5.w0, VLAN_EtherType
    ADD     R1.b0, R1.b0, 4
NO_VLAN_TX:
    MVIB    R25.b0, *R1.b0
    ;check if non link local
    QBEQ    PTP_NOT_LINK_LOCAL, R3.w0, 0

NO_HSR_TAG_TX:

    MVIB    R25.b0, *R1.b0

    QBNE    NOT_PDELAY_REQ_TX, R25.b0, PTP_PDLY_REQ_MSG_ID
    ;****************************PDELAY REQ PACKET PROCESSING***************************
    ;Take timestamp T1 here
    .if    $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")    
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P2, 8
    .else
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P1, 8
    .endif    
    .else
    .if    $isdefed("PRU0")    
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P1, 8
    .else
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P2, 8
    .endif    
    .endif

    ;store the value and set and interrupt
    LDI     R25.b2, 1

    .if    $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")    
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P2, 1    ; store the notification
    .else
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P1, 1    ; store the notification
    .endif
    .else
    .if    $isdefed("PRU0")    
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P1, 1    ; store the notification
    .else
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P2, 1    ; store the notification
    .endif
    .endif
    ;set tx callback interrupt. Just set the flag, interrupt is set upon successful transmission
    SET     R22, R22, TX_CALLBACK_INTERRUPT_BIT

    QBA     EXIT_PTP_TX_ADD_DELAY

NOT_PDELAY_REQ_TX:

    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.b0, PTP_PDLY_RSP_MSG_ID

    ;****************************PDELAY RES PACKET PROCESSING***************************
    ;Load the Delay Request Timestamp to compute T3 - T2
    ;Load T2, we are echoing back here so load same port timestamps
    ;Store the Tx timestamp

    .if    $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P2, 8
    .else
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P1, 8
    .endif
    .else
    .if    $isdefed("PRU0")
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P1, 8
    .else
    SBCO    &R10, ICSS_SHARED_CONST, TX_PDELAY_RESP_TIMESTAMP_OFFSET_P2, 8
    .endif
    .endif
    ;store the indicator and set and interrupt
    LDI     R25.b2, 1

    .if    $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")    
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P2, 1    ; store the notification
    .else
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P1, 1    ; store the notification
    .endif
    .else
    .if    $isdefed("PRU0")    
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P1, 1    ; store the notification
    .else
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_PDEL_RES_P2, 1    ; store the notification
    .endif
    .endif
    ;set tx callback interrupt. The interrupt is set upon successful transmission
    SET     R22, R22, TX_CALLBACK_INTERRUPT_BIT
    QBA     EXIT_PTP_TX_ADD_DELAY

PTP_NOT_LINK_LOCAL:

    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.b0, PTP_SYNC_MSG_ID
    ;****************************SYNC PACKET PROCESSING***************************
    ;check for two-step
    QBEQ    VLAN_TAGGED_TX, R5.w0, VLAN_EtherType
    QBBC    DUT_IS_SINGLE_STEP, two_step_reg, GPTP_802_3_two_step_bit
    QBA     DONE_VLAN_CHECK_TX
VLAN_TAGGED_TX:
    QBBC    DUT_IS_SINGLE_STEP, two_step_reg_vlan, GPTP_802_3_two_step_bit
DONE_VLAN_CHECK_TX:

    ;processing two-step sync frame
    ;Irrespective of slave/master status we just store timestamp and
    ;set flag to give a callback interrupt

    .if    $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")
    SBCO    &R10, ICSS_SHARED_CONST, TX_SYNC_TIMESTAMP_OFFSET_P2, 8
    .else
    SBCO    &R10, ICSS_SHARED_CONST, TX_SYNC_TIMESTAMP_OFFSET_P1, 8
    .endif
    .else
    .if    $isdefed("PRU0")
    SBCO    &R10, ICSS_SHARED_CONST, TX_SYNC_TIMESTAMP_OFFSET_P1, 8
    .else
    SBCO    &R10, ICSS_SHARED_CONST, TX_SYNC_TIMESTAMP_OFFSET_P2, 8
    .endif
    .endif
    ;store the indicator and set and interrupt
    LDI     R25.b2, 1

    .if    $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")    
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_SYNC_P2, 1    ; store the notification
    .else
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_SYNC_P1, 1    ; store the notification
    .endif
    .else
    .if    $isdefed("PRU0")    
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_SYNC_P1, 1    ; store the notification
    .else
    SBCO    &R25.b2, ICSS_SHARED_CONST, TX_TS_NOTIFICATION_OFFSET_SYNC_P2, 1    ; store the notification
    .endif
    .endif
    ;set tx callback interrupt. The interrupt is set upon successful transmission
    SET     R22, R22, TX_CALLBACK_INTERRUPT_BIT
    QBA     EXIT_PTP_TX_ADD_DELAY

DUT_IS_SINGLE_STEP:

    ;check if we are in master mode, if yes then set flag and exit
    QBBC    SYNC_SLAVE_PROCESSING, R22, DUT_IS_MASTER_BIT
    ;check if the frame is from host, else we exit. TODO : Do it using Buffer desc
    LDI     R25.w0, PORT_MAC_ADDR
    LBCO    &R25.w2, PRU_CROSS_DMEM, R25.w0, 6
    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.w2, R3.w2
    QBNE    EXIT_PTP_TX_ADD_DELAY, R26, R4

    .if    $defined("ICSS_SWITCH_BUILD")
    ;Do single step processing here
    .if    $isdefed("PRU0")
    LDI     R0.w2, SINGLE_STEP_IEP_OFFSET_P2
    .else
    LDI     R0.w2, SINGLE_STEP_IEP_OFFSET_P1
    .endif 
    .else
    .if    $isdefed("PRU0")
    LDI     R0.w2, SINGLE_STEP_IEP_OFFSET_P1
    .else
    LDI     R0.w2, SINGLE_STEP_IEP_OFFSET_P2
    .endif
    .endif 
    ;R25 contains the lower 4 bytes of stored IEP
    ;and R26 contains the upper 4 bytes
    LBCO    &R25, ICSS_SHARED_CONST, R0.w2, 8
    ADD     R0.w2, R0.w2, 8
    ;Compare R25 and R26 with R10 and R11 values to find out
    ;whether it's in the current cycle or the next
    QBGT    TX_TS_IN_NEXT_CYCLE, R26, R11
    QBNE    TX_TS_IN_CURRENT_CYCLE, R26, R11
    QBGE    TX_TS_IN_NEXT_CYCLE, R25, R10

TX_TS_IN_CURRENT_CYCLE:

    ;Means that timestamp is lower than stored IEP value
    ;Difference is less than 1s so we only subtract lower 4 bytes
    SUB     R25, R25, R10
    LDI32   R11, SEC_TO_NS
    SUB     R25, R11, R25
    LBCO    &R10, ICSS_SHARED_CONST, R0.w2, 8
    SUB     R10, R10, 1
    SUC     R11, R11, 0
    QBA     STORE_TS_IN_FRAME

TX_TS_IN_NEXT_CYCLE:

    ;Means that timestamp is higher than stored IEP value
    ;Difference is less than 1s so we only subtract lower 4 bytes
    SUB     R25, R10, R25
    LBCO    &R10, ICSS_SHARED_CONST, R0.w2, 8

STORE_TS_IN_FRAME:

    ;Since we are in the first 32 bytes of the frame, we need
    ;to write the outoing origin TS in L3 memory since it lies
    ;in the 32-64 byte offset of the frame

    ;load the offset for the correction field in L3
    MOV     R0.w2, BUFFER_INDEX
    ADD     R0.w2, R0.w2, 32

    QBNE    NO_QUEUE_WRAP_XMT_PTP_1, BUFFER_DESC_OFFSET, TOP_MOST_BUFFER_DESC_OFFSET
    QBBS    NO_QUEUE_WRAP_XMT_PTP_1, R13, 2    ; PACKET_FROM_COLL_QUEUE
    MOV     R0.w2, BUFFER_OFFSET

NO_QUEUE_WRAP_XMT_PTP_1:

    ;Add offset to reach the start of origin timestamp
    ;from the start of 32 byte block. This offset differs
    ;for HSR and PRP due to presence of HSR tag

    .if $defined(HSR)
    ADD     R0.w2, R0.w2, 22
    .endif ;HSR

    .if $defined(PRP)
    ADD     R0.w2, R0.w2, 16
    .endif ;PRP

    ;We need to convert to big endian to write back

    ;Since we have already pushed 22 bytes into the FIFO
    ;registers R2-R5 are free

    ;convert seconds to big endian first
    MOV     R3.b3, R10.b0
    MOV     R3.b2, R10.b1
    MOV     R3.b1, R10.b2
    MOV     R3.b0, R10.b3
    MOV     R2.b3, R11.b0
    MOV     R2.b2, R11.b1

    ;store nanoseconds to big endian next
    MOV     R4.b3, R25.b0
    MOV     R4.b2, R25.b1
    MOV     R4.b1, R25.b2
    MOV     R4.b0, R25.b3

    ;write 10 bytes (seconds + nanoseconds) at one go into memory
    SBCO    &R2.b2, L3_OCMC_RAM_CONST, R0.w2, 10

    QBA     EXIT_PTP_TX_ADD_DELAY

SYNC_SLAVE_PROCESSING:

    ;In PRP there is no forwarding and hence no bridge delay to calculate
    .if $defined(PRP)
    QBA     EXIT_PTP_TX_ADD_DELAY
    .endif ;PRP
    ;check against master MAC ID, if no match then exit
    ;else we do bridge delay correction here
    LBCO    &R25.w2, ICSS_SHARED_CONST, SYNC_MASTER_MAC_OFFSET, 6
    ;master MAC is in R25.w2 and R26
    QBNE    EXIT_PTP_TX_ADD_DELAY, R25.w2, R3.w2
    QBNE    EXIT_PTP_TX_ADD_DELAY, R26, R4

    .if    $isdefed("PRU0")
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P1, 8
    .else
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P2, 8
    .endif

CALC_BD_PTP_TX_PRE_PROC:

    ;this subtraction code takes care of lower word overflow situation
    ;bridge delay is in R10 after this
    QBNE    TX_TS_OVERFLOW, R26, R11
    SUB     R10, R10, R25
    QBA     MULTIPLY_WITH_RCF

TX_TS_OVERFLOW:

    ; Fill with saturation value for overflow calc
    FILL    &R26, 4
    SUB     R25, R26, R25
    ADD     R10, R25, R10   
    
MULTIPLY_WITH_RCF:    
;multiply with syntonization factor
;RCF is stored in the form of RCF * 1024 in 
;TIMESYNC_TC_RCF_OFFSET. A division by 1024 is done at the end
;to get the result as BD * RCF. 
;Use the MAC unit of PRU to do the multiplication
    ADD      R28, R10, 0
    LDI      R29.w0, TIMESYNC_TC_RCF_OFFSET
    LBCO     &R29, ICSS_SHARED_CONST, R29.w0, 4
    LDI      R25, 0
    XOUT     0, &R25, 1
    XIN      0, &R26, 8
    LSR      R10, R26, 10
    
SYNC_ADD_PEER_DELAY:

    ;load the peer delay for the other port and add to the bridge delay in R10
    ;R10 has BD + Peer delay after this
    .if    $isdefed("PRU0")
    LBCO    &R25, ICSS_SHARED_CONST, P1_SMA_LINE_DELAY_OFFSET, 4
    .else
    LBCO    &R25, ICSS_SHARED_CONST, P2_SMA_LINE_DELAY_OFFSET, 4
    .endif    
    ADD     R10, R10, R25

ADD_CORR_FIELD_PTP_TX_PRE_PROC:

    ;add BD to the correction field of sync frame
    ;copy the correction in R10 in little endian format, add and then put it back in big endian format
    ;Since for HSR the correction field lies across the 32 byte boundary we load
    ;the correction field from L3 memory, modify the upper 4 bytes which are within the
    ;first 32 bytes and the remaining 2 bytes are modified and stored back in L3 memory

    ;load the correction field from memory
    MOV     R25.w2, BUFFER_INDEX
    ADD     R25.w2, R25.w2, 32

    QBNE    NO_QUEUE_WRAP_XMT_PTP, BUFFER_DESC_OFFSET, TOP_MOST_BUFFER_DESC_OFFSET
    QBBS    NO_QUEUE_WRAP_XMT_PTP, R13, 2    ; PACKET_FROM_COLL_QUEUE
    MOV     R25.w2, BUFFER_OFFSET

NO_QUEUE_WRAP_XMT_PTP:

    ;load 2 bytes of correction field which lie in 32-64 byte segment
    LBCO    &R0.w2, L3_OCMC_RAM_CONST, R25.w2, 2

    ;reorder (big to little endian) correction field and add the bridge delay
    MOV     R21.b3, R9.b2
    MOV     R21.b2, R9.b3
    MOV     R21.b1, R0.b2
    MOV     R21.b0, R0.b3

    MOV     R20.b1, R9.b0
    MOV     R20.b0, R9.b1

    ;add and get the value
    LDI     R13.w0, 0
    ADD     R10, R10, R21
    ADC     R0.w2, R20.w0, R13.w0

    ;store the 4 partial values which lie in 0-32 byte segment
    MOV     R9.b3, R10.b2
    MOV     R9.b2, R10.b3
    MOV     R9.b1, R0.b2
    MOV     R9.b0, R0.b3

    ;store back the 2-bytes in 32-64 byte segment
    ;the firmware will pick it up later and put it on the wire
    MOV     R25.b0, R10.b1
    MOV     R25.b1, R10.b0
    SBCO    &R25.w0, L3_OCMC_RAM_CONST, R25.w2, 2

EXIT_PTP_TX_ADD_DELAY:

    JMP     R0.w0

;****************************************************************************
;
;     NAME             : FN_PTP_BACKGROUND_TASK
;     DESCRIPTION      : Background task which reprograms CMP1 and disables/enables
;                        Sync0 for 1PPS output
;     Cycles           : 30 PRU cycles (worst case)
;     Register Usage   : R22 (flags), R0, R2, R3, R12, R13, R20, R21
;     Pseudocode       :
;
;
;****************************************************************************

FN_PTP_BACKGROUND_TASK:

    ;check PTP enable bit and exit if not enabled
    LBCO    &TEMP_REG_3.b0, ICSS_SHARED_CONST, TIMESYNC_CTRL_VAR_OFFSET, 1
    QBBC    EXIT_PTP_BACKGROUND_TASK, TEMP_REG_3, GPTP_ENABLE_BG_TASK_BIT
    
    ;check if compare1 has been asserted and increment counter
    LBCO    &TEMP_REG_3.b0, IEP_CONST, IEP_CMP_STATUS_REG, 1

CHECK_CMP1:

    QBBC    CHECK_SYNC0_SIGNAL, TEMP_REG_3, 1
    SET     R22, R22, CHECK_SYNC0_BIT

    ;a load from IEP is 15 cycles but shared memory load is 3 cycles
    ;so instead of loading from IEP to reprogram we use a shared location offset i.e. GPTP_CMP1_CMP_OFFSET
    ;a similar location i.e. GPTP_SYNC0_CMP_OFFSET is used to store dynamic value of CMP1 value plus sync width
    LBCO  &RCV_TEMP_REG_4, ICSS_SHARED_CONST, TIMESYNC_CMP1_CMP_OFFSET, 8    ;loads into RCV_TEMP_REG_4 & RCV_TEMP_REG_3
    
    LBCO    &TEMP_REG_3, ICSS_SHARED_CONST, TIMESYNC_CMP1_PERIOD_OFFSET, 8    ;loads TIMESYNC_CMP1_PERIOD_OFFSET to TEMP_REG_3 and TIMESYNC_SYNC0_WIDTH_OFFSET to TEMP_REG_4
    ADD     RCV_TEMP_REG_1, RCV_TEMP_REG_4, TEMP_REG_3
    ADC     RCV_TEMP_REG_2, RCV_TEMP_REG_3, 0

    ADD     RCV_TEMP_REG_4, RCV_TEMP_REG_4, TEMP_REG_4
    ADC     RCV_TEMP_REG_3, RCV_TEMP_REG_3, 0
    
    SBCO    &RCV_TEMP_REG_1, IEP_CONST, IEP_CMP1_REG, 8            ;program new cmp1 value
    SBCO    &RCV_TEMP_REG_1, ICSS_SHARED_CONST, TIMESYNC_CMP1_CMP_OFFSET, 8            ;also store new cmp1 value into memory, this saves cycles as explained above
    SBCO    &RCV_TEMP_REG_4, ICSS_SHARED_CONST, TIMESYNC_SYNC0_CMP_OFFSET, 8            ;store into memory, used for comparison later
    LDI     TEMP_REG_3.b2, 2
    SBCO    &TEMP_REG_3.b2, IEP_CONST, IEP_CMP_STATUS_REG, 1

    QBA     EXIT_PTP_BACKGROUND_TASK

CHECK_SYNC0_SIGNAL:

    ;check if cmp1 has been hit already. Check the R22 bit set earlier
    QBBC    EXIT_PTP_BACKGROUND_TASK, R22, CHECK_SYNC0_BIT
    LBCO    &RCV_TEMP_REG_4, IEP_CONST, IEP_COUNTER_OFFSET, 8                ;load current IEP into RCV_TEMP_REG_4 & RCV_TEMP_REG_3
    LBCO    &RCV_TEMP_REG_1, ICSS_SHARED_CONST, TIMESYNC_SYNC0_CMP_OFFSET, 8  ;load the time when sync0 signal will go down. Into RCV_TEMP_REG_1 & RCV_TEMP_REG_2
    
    ;compare current IEP with loaded value
    QBLT    EXIT_PTP_BACKGROUND_TASK, RCV_TEMP_REG_2, RCV_TEMP_REG_3
    QBNE    RESET_SYNC0, RCV_TEMP_REG_2, RCV_TEMP_REG_3
    QBLT    EXIT_PTP_BACKGROUND_TASK, RCV_TEMP_REG_1, RCV_TEMP_REG_4

RESET_SYNC0:

    CLR     R22, R22, CHECK_SYNC0_BIT
    ;disable and enable the sync0
    LDI     TEMP_REG_4.b0, 0
    LDI     TEMP_REG_4.w2, IEP_SYNC_CTRL_REG    ; clear sync enable
    SBCO    &TEMP_REG_4.b0, IEP_CONST, TEMP_REG_4.w2, 1
    LDI     TEMP_REG_4.b0, 3    ; set sync enable
    SBCO    &TEMP_REG_4.b0, IEP_CONST, TEMP_REG_4.w2, 1

EXIT_PTP_BACKGROUND_TASK:

    JMP     CALL_REG

    .endif

;****************************************************************************
;
;     NAME             : FN_TIMESTAMP_GPTP_PACKET_UDP
;     DESCRIPTION      : Store timestamp for PTP frames.
;                        It is called during Rx
;     Cycles           : 
;     Register Usage   : R22 (flags), R20, R21, R10, R11, R13
;     Pseudocode       :  
;if PTP frame:
;   if not link local
;       if sync frame:
;           if PTP not enabled:
;               discard frame
;           else:
;               if not from master:
;                   do not forward to host
;               else:
;                   if first sync:
;                       update the master port 
;                   take timestamp()
;       elif follow up 
;           if PTP not enabled:
;               discard frame
;           else:
;               if not from master:
;                   do not forward to host
;               else:
;                   clear fwd_flag
;                   exit without timestamp
;           
;   else:
;       if pdelay req frame or pdelay response frame:
;           take timestamp()
;def take_timestamp()
;   load SFD timestamp
;   exit       
;else:
;   exit                     
;
;****************************************************************************
FN_TIMESTAMP_GPTP_PACKET_UDP:
    QBBC    FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP, R22, RX_IS_UDP_PTP_BIT 
    CLR    R22, R22, RX_IS_UDP_PTP_BIT

CHECK_UDP_PORT:
    QBBS    CHECK_UDP_PORT_VLAN, R22, RX_IS_VLAN_BIT
    LDI     R20.w0, UDP_PTP_PORT_319
    QBEQ    GPTP_OFFSET_LOAD_UDP, UDP_SRC_PORT_REG, R20.w0
    LDI     R20.w0, UDP_PTP_PORT_320
    QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP, UDP_SRC_PORT_REG, R20.w0
    QBA     GPTP_OFFSET_LOAD_UDP
CHECK_UDP_PORT_VLAN:
    CLR     R22, R22, RX_IS_VLAN_BIT
    LDI     R20.w0, UDP_PTP_PORT_319
    QBEQ    GPTP_OFFSET_LOAD_UDP, UDP_SRC_PORT_VLAN_REG, R20.w0
    LDI     R20.w0, UDP_PTP_PORT_320
    QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP, UDP_SRC_PORT_VLAN_REG, R20.w0

    ;domain number check disabled for now. Will be enabled later
    ;LBCO    R21, ICSS_SHARED_CONST, GPTP_DOMAIN_NUMBER_LIST, GPTP_NUM_DOMAINS
    ;QBEQ    GPTP_OFFSET_LOAD, Ethernet.ProtWord3, R21.b0                // Check gPTP domain number
    ;QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT, Ethernet.ProtWord3, R21.b1                 // Check gPTP domain number
GPTP_OFFSET_LOAD_UDP:
    ;load the value indicating whether PTP is in uninitialized state
    LBCO    &R20.b0, ICSS_SHARED_CONST, TIMESYNC_CTRL_VAR_OFFSET, 1    
    ;check for sync frame
    QBNE    CHECK_FOLLOW_UP_UDP, PTP_MSG_ID_REG_UDP, PTP_SYNC_MSG_ID   

    ;--------------------process sync frames------------------//
    ;discard frame if in initial state
    QBEQ    DISCARD_PTP_FRAME_RX_UDP, R20.b0, 0    
    ;Below is a combined load to save cycles.
    ;R20.b0 tells if DUT is master. R20.b1 tells which port is connected to master
    ;and R20.w2 and R21 tell the MAC ID of the master selected by BMCA
    LBCO    &R20.w0, ICSS_SHARED_CONST, DUT_IS_MASTER_OFFSET, 8    
    QBNE    DUT_IS_SLAVE_SYNC_UDP, R20.b0, 1    ;exit if DUT is configured as master, also discard frame
    CLR    MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift ; Don't forward to host
    SET    R22, R22, PTP_RELEASE_HOST_QUEUE_BIT 
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP
DUT_IS_SLAVE_SYNC_UDP:
    ;Check against Master MAC address. R3.w2 and R4 contain source MAC address
    ; QBBC    FRAME_NOT_FROM_MASTER, R22, PTP_PKT_FROM_MASTER_RX 
    ; CLR     R22, R22, PTP_PKT_FROM_MASTER_RX
    
    ;check for dual master on two ports.
    ;The logic works like this....initially the memory location is empty
    ;whenever the first sync arrives, the corresponding port number is written into
    ;memory location. Subsequent sync frames check against this value and they are discarded
    ;if the value in memory does not match the port number.
    QBEQ    FIRST_SYNC_FRAME_UDP, R20.b1, 0    
    QBA      LOAD_TS_OFFSET_ADDR_SYNC_UDP
    
FIRST_SYNC_FRAME_UDP:               ;whichever port receives the sync first is assigned as master port
    .if $isdefed("PRU0")    
    LDI    R20.b1, 1    
    .else    ; "PRU0"
    LDI    R20.b1, 2    
    .endif    ; "PRU0"
    SBCO    &R20.b1, ICSS_SHARED_CONST, MASTER_PORT_NUM_OFFSET, 1    
    
LOAD_TS_OFFSET_ADDR_SYNC_UDP:
    .if $isdefed("PRU0")    
    LDI    R11.w0, RX_SYNC_TIMESTAMP_OFFSET_P1    ;load sync timestamp offset    
    .else    ; "PRU0"
    LDI    R11.w0, RX_SYNC_TIMESTAMP_OFFSET_P2    
    .endif    ; "PRU0"
    QBA     GPTP_STORE_TIMESTAMP_UDP                     ;with the offset loaded, store the Rx timestamp
DISCARD_PTP_FRAME_RX_UDP:
    ;set error flag
    SET    MII_RCV.rx_flags, MII_RCV.rx_flags, rx_frame_error_shift
FRAME_NOT_FROM_MASTER_UDP:                                  ;if frame is not from master, it's not processed
    CLR    MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift ; Don't forward to host
    SET    R22, R22, PTP_RELEASE_HOST_QUEUE_BIT 
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP
    
CHECK_FOLLOW_UP_UDP:
    QBNE    CHECK_DELAY_RESP_UDP, PTP_MSG_ID_REG_UDP, PTP_FOLLOW_UP_MSG_ID    
    QBEQ    DISCARD_PTP_FRAME_RX_UDP, R20.b0, 0    
    ;Below is a combined load to save cycles.
    ;R20.b0 tells if DUT is master. R20.b1 tells which port is connected to master
    ;and R20.w2 and R21 tell the MAC ID of the master selected by BMCA
    LBCO    &R20.w0, ICSS_SHARED_CONST, DUT_IS_MASTER_OFFSET, 8    
    QBNE    DUT_IS_SLAVE_FLW_UP_UDP, R20.b0, 1    ;exit if DUT is configured as master
    CLR    MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift ; Don't forward to host
    SET    R22, R22, PTP_RELEASE_HOST_QUEUE_BIT 
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP
DUT_IS_SLAVE_FLW_UP_UDP:
    CLR    MII_RCV.rx_flags, MII_RCV.rx_flags, fwd_flag_shift ; Don't forward to other port
    SET    R22, R22, PTP_RELEASE_PORT_QUEUE_BIT 
    ;Check against Master MAC address. R3.w2 and R4 contain source MAC address
    QBBC    FRAME_NOT_FROM_MASTER, R22, PTP_PKT_FROM_MASTER_RX 
    CLR     R22, R22, PTP_PKT_FROM_MASTER_RX 
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT
    
CHECK_DELAY_RESP_UDP:
    QBNE    CHECK_DELAY_REQ_UDP, PTP_MSG_ID_REG_UDP, PTP_DLY_RESP_MSG_ID    
    ;set a flag so we can compare the delay response against the
    ;source port identity and make sure this is for us. The source port
    ;identity comes after 64 bytes.
    ;This is required because there may be hundreds of devices in the network
    ;and it's no point sending all the delay responses (meant for others) up to the host
    SET    R22, R22, PTP_CHECK_PDELAY_RESP 
    QBA     FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP
    
CHECK_DELAY_REQ_UDP:
    QBNE    FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP, PTP_MSG_ID_REG_UDP, PTP_DLY_REQ_MSG_ID    
    QBEQ    DISCARD_PTP_FRAME_RX_UDP, R20.b0, 0    
    ;clear the host receive flag, only master processes delay request frames
    ;and PTP master capability is not enabled for EIP
    CLR    MII_RCV.rx_flags, MII_RCV.rx_flags, host_rcv_flag_shift ; Don't forward to host
    SET    R22, R22, PTP_RELEASE_HOST_QUEUE_BIT 
    .if $isdefed("PRU0")    
    LDI    R11.w0, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P1    
    .else    ; "PRU0"
    LDI    R11.w0, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P2    
    .endif    ; "PRU0"
    
GPTP_STORE_TIMESTAMP_UDP:
    .if $isdefed("ICSS_V_1_0")    
    
    ;This also loads 2 bytes in RCV_TEMP_REG_2.w0
    LBCO    &RCV_TEMP_REG_1, ICSS_SHARED_CONST, TIMESYNC_SECONDS_COUNT_OFFSET, 6    
    .if $isdefed("PRU0")    
    LBCO    &R13, IEP_CONST, CAP_RISE_RX_SFD_PORT1_OFFSET, 4    
    .else    ; "PRU0"
    LBCO    &R13, IEP_CONST, CAP_RISE_RX_SFD_PORT2_OFFSET, 4    
    .endif    ; "PRU0"
    ;current IEP counter value
    LBCO    &R12, IEP_CONST, IEP_COUNTER_OFFSET, 4    
    ;check if counter has been incremented
    LBCO    &R10.b0, IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 1    
    ;check if there has been a wrap around
    QBGT    NO_WRAPAROUND_SINCE_RX_UDP, R13, R12    
    ;make sure counter has not incremented
    QBBS    COMPENSATION_DONE_RX_UDP, R10, 0     ;replaced: QBBS   COMPENSATION_DONE_RX, R10.t0 
    LBCO    &R10, ICSS_SHARED_CONST, TIMESYNC_IEP_VAL_CYCLE_COUNTER, 4    
    QBGT    COMPENSATION_DONE_RX_UDP, R12, R10    
    SUB    RCV_TEMP_REG_1, RCV_TEMP_REG_1, 1    
    SUC    RCV_TEMP_REG_2.w0, RCV_TEMP_REG_2.w0, 0    
    QBA    COMPENSATION_DONE_RX_UDP
    
NO_WRAPAROUND_SINCE_RX_UDP:
    ;make sure that counter has incremented
    QBBC    COMPENSATION_DONE_RX_UDP, R10, 0     ;replaced: QBBC   COMPENSATION_DONE_RX, R10.t0 
    LBCO    &R10, ICSS_SHARED_CONST, TIMESYNC_IEP_VAL_CYCLE_COUNTER, 4    
    QBGT    COMPENSATION_DONE_RX_UDP, R10, R12    
    ADD    RCV_TEMP_REG_1, RCV_TEMP_REG_1, 1    
    ADC    RCV_TEMP_REG_2.w0, RCV_TEMP_REG_2.w0, 0    
    
COMPENSATION_DONE_RX_UDP:
    ;Do PHY compensation
    LBCO    &R12.w0, ICSS_SHARED_CONST, MII_RX_CORRECTION_OFFSET, 2    
    QBLE    NO_WRAPAROUND_RX_UDP, R13, R12.w0    
    ;The seconds timestamp should be decremented by 1
    SUB    RCV_TEMP_REG_1, RCV_TEMP_REG_1, 1    
    SUC    RCV_TEMP_REG_2.w0, RCV_TEMP_REG_2.w0, 0    
    LDI    R10.w0, IEP_WRAP_AROUND_VAL & 0xFFFF
    LDI    R10.w2, IEP_WRAP_AROUND_VAL >> 16
    ADD    R13, R13, R10    
    
NO_WRAPAROUND_RX_UDP:
    SUB    R13, R13, R12.w0    
PHY_COMPENSATION_DONE_UDP:
    
    ;store nanoseconds TS
    SBCO    &R13, ICSS_SHARED_CONST, R11.w0, 4    
    ADD    R11.w0, R11.w0, 4    
    ;store seconds TS
    SBCO    &RCV_TEMP_REG_1, ICSS_SHARED_CONST, R11.w0, 6    
    
    .else    ; "ICSS_V_1_0"
    ;R12 contains the lower 4 bytes and R13 contains the upper 4 bytes of IEP
    .if $isdefed("PRU0")    
    LBCO    &R12, IEP_CONST, CAP_RISE_RX_SFD_PORT1_OFFSET, 8    
    .else    ; "PRU0"
    LBCO    &R12, IEP_CONST, CAP_RISE_RX_SFD_PORT2_OFFSET, 8    
    .endif    ; "PRU0"
    
    ;Do PHY compensation. Rx PHY delay is in R20.w0
    LBCO    &R20.w0, ICSS_SHARED_CONST, MII_RX_CORRECTION_OFFSET, 2    
    
    ;Subtract PHY delay from timestamp to get the actual delay
    SUB    R12, R12, R20.w0    
    SUC    R13, R13, 0    
    
    ;store TS in memory
    SBCO    &R12, ICSS_SHARED_CONST, R11.w0, 8    
    .endif    ; "ICSS_V_1_0"
FN_TIMESTAMP_GPTP_PACKET_EXIT_UDP:
    JMP   R11.w2

;****************************************************************************
;
;     NAME             : FN_PTP_TX_ADD_DELAY_UDP
;     DESCRIPTION      : 1. Function for measuring bridge delay 
;                        2. In Sync frames
;                        3. For Pdelay Response frames
;                        4. For storing Tx timestamp for Sync and Pdelay Req frames
;     Cycles           : 75 PRU cycles (worst case)
;     Register Usage   : R22 (flags), R0, R13, R25, R26, R28, R29
;     Pseudocode       :  
;22 bytes have been put in Tx FIFO
;if ptp frame:
;   load tx SOF timestamp 
;   do phy delay correction on tx SOF
;   if link local frame:
;       if Pdelay Request frame:
;           store tx SOF TS
;           indicate that this is a Pdelay request frame (by writing into shared memory)
;           set flag for Tx callback interrupt
;       elif Pdelay response frame:
;           store tx SOF TS
;           indicate that this is a Pdelay response frame (by writing into shared memory)
;           set flag for Tx callback interrupt
;    else: #Not a link local frame
;       if sync frame:
;           if not two-step:
;               store tx SOF TS
;               indicate that this is a sync frame (by writing into shared memory)
;               set flag for Tx callback interrupt
;
;           else: #single step
;               if DUT is master:
;                   if frame is from some other device:
;                       exit
;                   else:
;                       add origin timestamp (see logic below)
;               else:
;                   #Do Bridge delay computation   
;                   calculate BD from Tx SOF and Rx timestamp
;                   Multiply by RCF
;                   Add peer delay and store back
;    
;else:
;   exit                     
    
;---------------Logic for adding 1-step origin Timestamp----------
;
;   The logic here works like this
;   Assume three timestamps Y, Y' and Z
;   Y--------------Y'----------------Z
;    Z is the start of the seconds cycle i.e. nanoseconds value of 0
;    Y denotes current time inside this function which is invoked
;    just before transmitting the sync frame. Y' is the actual Tx SOF timestamp
;    and is guaranteed to be within few microsends/miliseconds ahead of Y.
;    Now three possible cases exist
;    Y-----Z-----Y' in which case Y' lies in the next cycle
;    Y-----Y'----Z  in which case Y' is in current cycle
;    corner cases in which Y == Z and Y' == Z also fall under the above 2
;    
;    In firmware the timestamp Y' is compared against Z and it is determined
;    whether it falls in next or previous cycle. The corresponding seconds value
;    of Z is then used to get the seconds value. Nanoseconds value is obtained by
;    subtraction and long division and reminder operation is avoided.
;
;    Compare the timestamps and determine the cycle
;    if current cycle:
;       subtract 1 from stored value to get seconds
;       get nanoseconds value by subtracting from stored value and then from 1x10^9
;    else:
;       stored value is the seconds value
;       subtract from stored value to get nanoseconds value
;    store second and nanoseconds values
;
;
;
;****************************************************************************
FN_PTP_TX_ADD_DELAY_UDP:
    QBBC    EXIT_PTP_TX_ADD_DELAY_UDP, R22, TX_IS_UDP_PTP_BIT 
    CLR    R22, R22, TX_IS_UDP_PTP_BIT


CHECK_UDP_PORT_TX:
    QBBS    CHECK_UDP_PORT_TX_VLAN, R22, TX_IS_VLAN_BIT
    LDI     R20.w0, UDP_PTP_PORT_319
    QBEQ    DONE_UDP_CHECK, UDP_SRC_PORT_REG, R20.w0
    LDI     R20.w0, UDP_PTP_PORT_320
    QBNE    EXIT_PTP_TX_ADD_DELAY_UDP, UDP_SRC_PORT_REG, R20.w0
    QBA     DONE_UDP_CHECK

CHECK_UDP_PORT_TX_VLAN:
    CLR     R22, R22, TX_IS_VLAN_BIT
    LDI     R20.w0, UDP_PTP_PORT_319
    QBEQ    DONE_UDP_CHECK, UDP_SRC_PORT_VLAN_REG, R20.w0
    LDI     R20.w0, UDP_PTP_PORT_320
    QBNE    EXIT_PTP_TX_ADD_DELAY_UDP, UDP_SRC_PORT_VLAN_REG, R20.w0
DONE_UDP_CHECK:

    ;we need to make sure that the timestamp here is actual value
    ;this we do by comparing with Tx SOF of previous frame
    .if    $isdefed("PRU0")
    LDI     R20.w0, PTP_PREV_TX_TIMESTAMP_P1
    .else
    LDI     R20.w0, PTP_PREV_TX_TIMESTAMP_P2
    .endif
    LBCO    &R20, ICSS_SHARED_CONST, R20.w0, 8
    ;get the timestamp

LOAD_TX_SOF_TS_UDP:
    
    .if  $defined("ICSS_SWITCH_BUILD")
    .if    $isdefed("PRU0")
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8
    .else
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8
    .endif
    .else
    .if    $isdefed("PRU0")
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8
    .else
    LBCO    &R10, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8
    .endif
    .endif

    QBNE    TX_SOF_OK_UDP, R10, R20
    QBEQ    LOAD_TX_SOF_TS_UDP, R11, R21

TX_SOF_OK_UDP:
    
    QBNE    NOT_DELAY_REQ_TX_UDP, PTP_MSG_ID_REG_UDP, PTP_DLY_REQ_MSG_ID    
    ;****************************DELAY REQ PACKET PROCESSING***************************
    ;If packet is from host then we just store the exit timestamp
    ;else we do bridge delay correction
    ;Take timestamp T1 here
    ;JAL       R0.w2, FN_GET_TX_TIMESTAMP
    
    .if $isdefed("ICSS_V_1_0")    
    
    JAL    R0.w2, FN_GET_TX_TIMESTAMP
    
    .else    ; "ICSS_V_1_0"

    ;check if the frame is from self
    .if $isdefed("ICSS_SWITCH_BUILD")
    LDI    R10.w0, PORT_MAC_ADDR
    LBCO    &R20.w2, PRU_DMEM_ADDR, R10.w0, 6    ;6 bytes of Interface MAC Addr in R20.w2 and R21
    QBNE    DELAY_REQ_NOT_FROM_DUT_UDP, R20.w2, R3.w2    
    QBNE    DELAY_REQ_NOT_FROM_DUT_UDP, R21, R4
    .endif 

    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8    
    .else    ; "PRU0"
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8    
    .else    ; "PRU0"
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8    
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    .endif    ; "ICSS_V_1_0"

    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LDI    R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P2    
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P2    
    .else    ; "PRU0"
    LDI    R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P1    
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P1    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LDI    R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P1  
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P1
    .else    ; "PRU0"
    LDI    R10.w0, TX_PDELAY_REQ_TIMESTAMP_OFFSET_P2
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_PDEL_REQ_P2
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    
    ;Store the Tx TS, set flag for
    QBA       STORE_TX_TS_SET_FLAG_EXIT_UDP
    
DELAY_REQ_NOT_FROM_DUT_UDP:
    ;load the Rx timestamp and calculate BD
    .if $isdefed("ICSS_V_1_0")  
    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P1, 4    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P2, 4    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P2, 4    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P1, 4    
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    .else    ; "ICSS_V_1_0"
    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P1, 8    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P2, 8    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P2, 8    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_PDELAY_REQ_TIMESTAMP_OFFSET_P1, 8    
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    .endif    ; "ICSS_V_1_0"
    ;branch and calculate BD and add it to outoing frame
    ;This part of code is common to both sync and delay request frames
    QBA     CALC_BD_PTP_TX_PRE_PROC_UDP
    
NOT_DELAY_REQ_TX_UDP:
    QBNE    NOT_DELAY_RESP_UDP, PTP_MSG_ID_REG_UDP, PTP_DLY_RESP_MSG_ID    
    
    ;****************************DELAY RES PACKET PROCESSING***************************
    ;Nothing to be done here. Add code here when master is implemented
    
    ;Store the Tx TS, set flag for
    QBA       EXIT_PTP_TX_ADD_DELAY_UDP
    
NOT_DELAY_RESP_UDP:
    QBNE    EXIT_PTP_TX_ADD_DELAY_UDP, PTP_MSG_ID_REG_UDP, PTP_SYNC_MSG_ID    
    ;****************************SYNC PACKET PROCESSING***************************
    
    ;check against master MAC ID, if no match then exit
    ;else we do bridge delay correction here
    ; LBCO    &R25.w2, ICSS_SHARED_CONST, SYNC_MASTER_MAC_OFFSET, 6
    ; ;master MAC is in R25.w2 and R26
    ; QBNE    EXIT_PTP_TX_ADD_DELAY, R25.w2, R3.w2
    ; QBNE    EXIT_PTP_TX_ADD_DELAY, R26, R4

    ;check for two-step
    QBBC    DUT_IS_SINGLE_STEP_UDP, R6, 1     ;replaced: QBBC    DUT_IS_SINGLE_STEP, IF_TWO_STEP_CLK_UDP 
    
    ;processing two-step sync frame
    ;Irrespective of slave/master status we just store timestamp and
    ;set flag to give a callback interrupt
    
    ;JAL   R0.w2, FN_GET_TX_TIMESTAMP
    .if $isdefed("ICSS_V_1_0")    
    JAL    R0.w2, FN_GET_TX_TIMESTAMP
    .else    ; "ICSS_V_1_0"
    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8    
    .else    ; "PRU0"
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8    
    .else    ; "PRU0"
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8    
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    .endif    ; "ICSS_V_1_0"
    
    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LDI    R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P2    
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P2    
    .else    ; "PRU0"
    LDI    R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P1    
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P1    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LDI    R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P1
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P1
    .else    ; "PRU0"
    LDI    R10.w0, TX_SYNC_TIMESTAMP_OFFSET_P2
    LDI    R10.w2, TX_TS_NOTIFICATION_OFFSET_SYNC_P2
    .endif    ; "PRU0"
    .endif
    
    ;Store the Tx TS, set flag for
    QBA       STORE_TX_TS_SET_FLAG_EXIT_UDP
    
DUT_IS_SINGLE_STEP_UDP:
    
SYNC_SLAVE_PROCESSING_UDP:
    
    .if $isdefed("ICSS_V_1_0")    
    ;get the timestamp
    JAL    R0.w2, FN_GET_TX_TIMESTAMP 
    
    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P1, 4    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P2, 4    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P2, 4    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P1, 4    
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    
CALC_BD_PTP_TX_PRE_PROC_UDP:
    ;calculate bridge delay, taking care of wraparound
    ;bridge delay is in R10 after this
    QBGE    TX_TS_NO_WRAPAROUND_UDP, R25, R4    
    ; Fill with saturation value for wraparound calc
    LDI    R26.w0, IEP_WRAP_AROUND_VAL & 0xFFFF
    LDI    R26.w2, IEP_WRAP_AROUND_VAL >> 16
    ADD    R4, R26, R4    
TX_TS_NO_WRAPAROUND_UDP:
    SUB    R10, R4, R25    
    .else    ; "ICSS_V_1_0"
    ;get the timestamp
    ;JAL     R0.w2, FN_GET_TX_TIMESTAMP
    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8    
    .else    ; "PRU0"
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT1_OFFSET, 8    
    .else    ; "PRU0"
    LBCO    &R20, IEP_CONST, CAP_RISE_TX_SOF_PORT2_OFFSET, 8    
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    
    .if    $defined("ICSS_SWITCH_BUILD")
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P1, 8    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P2, 8    
    .endif    ; "PRU0"
    .else
    .if $isdefed("PRU0")    
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P2, 8    
    .else    ; "PRU0"
    LBCO    &R25, ICSS_SHARED_CONST, RX_SYNC_TIMESTAMP_OFFSET_P1, 8    
    .endif    ; "PRU0"
    .endif    ; "ICSS_SWITCH_BUILD"
    
CALC_BD_PTP_TX_PRE_PROC_UDP:
    ;this subtraction code takes care of lower word overflow situation
    ;bridge delay is in R10 after this
    QBNE    TX_TS_OVERFLOW_UDP, R26, R21    
    SUB    R10, R20, R25    
    QBA     MULTIPLY_WITH_RCF_UDP
TX_TS_OVERFLOW_UDP:
    ; Fill with saturation value for overflow calc
    FILL    &R26, 4
    SUB    R25, R26, R25    
    ADD    R10, R25, R20    
    .endif    ; "ICSS_V_1_0"
    
MULTIPLY_WITH_RCF_UDP:
;multiply with syntonization factor
;RCF is stored in the form of RCF * 1024 in 
;TIMESYNC_TC_RCF_OFFSET. A division by 1024 is done at the end
;to get the result as BD * RCF. 
;Use the MAC unit of PRU to do the multiplication
    ADD    R28, R10, 0    
    LDI    R29.w0, TIMESYNC_TC_RCF_OFFSET    
    LBCO    &R29, ICSS_SHARED_CONST, R29.w0, 4    
    LDI    R25, 0    
    XOUT    0, &R25, 1    
    XIN    0, &R26, 8    
    LSR    R10, R26, 10    
    
ADD_CORR_FIELD_PTP_TX_PRE_PROC_UDP:
    ;add BD to the correction field of sync or delay request frame
    ;copy the correction in R10 in little endian format, add and then put it back in big endian format
    ;The correction field is in registers (correction field 6 bytes: [R6.w2:R7])
    
NO_QUEUE_WRAP_XMT_PTP_UDP:
    ; convert big-endian mode (correction field 6 bytes: [R6.w2:R7]) to little endian mode(R11)
    AND R20.b0, R7.b3, R7.b3
    AND R20.b1, R7.b2, R7.b2
    AND R20.b2, R7.b1, R7.b1
    AND R20.b3, R7.b0, R7.b0
    
    AND R21.b0, R6.b3, R6.b3
    AND R21.b1, R6.b2, R6.b2
    
    ; add BD to it (BD is in R10)
    ADD    R20, R20, R10    
    ADC    R21.w0, R21.w0, 0    
    
    ;reorder and store back
    AND R7.b3, R20.b0, R20.b0
    AND R7.b2, R20.b1, R20.b1
    AND R7.b1, R20.b2, R20.b2
    AND R7.b0, R20.b3, R20.b3
    
    AND R6.b3, R21.b0, R21.b0
    AND R6.b2, R21.b1, R21.b1
    
    AND R11.w0, BUFFER_INDEX, BUFFER_INDEX
    ADD    R11.w0, R11.w0, 18    
    SBCO    &R6.w2, L3_OCMC_RAM_CONST, R11.w0, 6    
    ;Make UDP checksum 0
    LDI    R12, 0x0000
    AND R11.w0, BUFFER_INDEX, BUFFER_INDEX
    ADD    R11.w0, R11.w0, 8    
    SBCO    &R12, L3_OCMC_RAM_CONST, R11.w0, 2    
    LDI    R4.w0, 0x00
    
    .if $isdefed("ICSS_V_1_0")    
    ;restore R2-R5 bytes. The timestamps have been consumed
    LDI    R10.w0, PTP_SCRATCH_MEM    
    LBCO    &R2, ICSS_SHARED_CONST, R10.w0, 16    
    
    QBA     EXIT_PTP_TX_ADD_DELAY_UDP
    
STORE_TX_TS_SET_FLAG_EXIT_UDP:
    ;nanoseconds in R4, Seconds in R2 and R3.w0
    ;TS offset is in R10.w0 and notification offset in R10.w2
    SBCO    &R4, ICSS_SHARED_CONST, R10.w0, 4    
    ADD    R10.w0, R10.w0, 4    
    SBCO    &R2, ICSS_SHARED_CONST, R10.w0, 6    
    
    ;store notification
    LDI    R25.b2, 1    
    SBCO    &R25.b2, ICSS_SHARED_CONST, R10.w2, 1    
    ;set indicator for callback interrupt
    SET    R22, R22, TX_CALLBACK_INTERRUPT_BIT 
    
    ;restore R2-R5 bytes. The timestamps in R2, R3 and R4 have been consumed
    LDI    R10.w0, PTP_SCRATCH_MEM    
    LBCO    &R2, ICSS_SHARED_CONST, R10.w0, 16    
    .else    ; "ICSS_V_1_0"
    QBA     EXIT_PTP_TX_ADD_DELAY_UDP
    
STORE_TX_TS_SET_FLAG_EXIT_UDP:
    ;Timestamp is in R20 + R21 (8 bytes of IEP)
    ;add Tx PHY delay
    LBCO    &R25.w0, ICSS_SHARED_CONST, MII_TX_CORRECTION_OFFSET, 2    
    ADD    R20, R20, R25.w0    
    ADC    R21, R21, 0    
    
    SBCO    &R20, ICSS_SHARED_CONST, R10.w0, 8    
    
    ;store notification
    LDI    R25.b2, 1    
    SBCO    &R25.b2, ICSS_SHARED_CONST, R10.w2, 1    
    ;set indicator for callback interrupt
    SET    R22, R22, TX_CALLBACK_INTERRUPT_BIT 
    .endif    ; "ICSS_V_1_0"
    
EXIT_PTP_TX_ADD_DELAY_UDP:
    JMP    R0.w0    

    .endif    ;____pn_gPtp_asm
