;;*****************************************************************************
;;  Copyright (C) 2015 Texas Instruments Incorporated - http:;;www.ti.com/
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

;;*****************************************************************************
;;  c7vectors.asm
;;
;;  Description
;;      SS Event vectors for C7x Processor
;;
;;; Revision History:
;;;     01Oct15 - Initial coding
;;*****************************************************************************

    ;;.include    "int_list.h"
    .sect       ".ss_vectors"

    .global     ss_stack_pointer
    .global     ss_evtstack
    .global     s_stack_pointer
    .global     s_evtstack
    .global     s_evt_ecq
    .global     gs_stack_pointer
    .global     gs_evtstack
    .global     gs_evt_ecq

    .global     ss_vector_table
    .global     s_vector_table
    .global     gs_vector_table
    .global     test_end

    .weak       curr_soft_reset_vector
    .weak       curr_int_exp_vector
    .weak       curr_page_fault_vector
    .weak       curr_nme_vector
    .global     CSL_c7x_SaveAllEABIRegs
    .global     CSL_c7x_RestoreAllEABIRegs
    .global     CSL_c7x_SaveSARegs
    .global     CSL_c7x_SaveSERegs
    .global     CSL_c7x_RestoreSARegs
    .global     CSL_c7x_RestoreSERegs


ss_vector_table:

soft_reset:
        ; // SS int setup
        MVK64       .L1     ss_evtstack+0x20000  , A0
        MVK64       .L1     ss_stack_pointer     , A1
        STD         .D1     A0,   *A1
     || MVK64       .L1     ss_vector_table,A0
        MVC         .S1     A0, ESTP_SS ;write ESTP location
     || MVK64       .L1     ss_evt_ecq,A0
        MVC         .S1     A0, ECSP_SS ;write ECSP_SS location
        ; //Init TCSP EVT ECQ
     || MVK64       .L1     tcsp_evt_ecq,A0
        MVC         .S1     A0, TCSP ;write TCSP location

        ; //S int setup
     || MVK64       .L1     s_evtstack+0x20000  , A0
        MVK64       .L1     s_stack_pointer     , A1
        STD         .D1     A0,   *A1
     || MVK64       .L1     s_vector_table,A0
        MVC         .S1     A0, ESTP_S ;write vector location
     || MVK64       .L1     s_evt_ecq,A0
        MVC         .S1     A0, ECSP_S ;write ECSP_S location
        ; //GS int setup
     || MVK64       .L1     gs_evtstack+0x20000  , A0
        MVK64       .L1     gs_stack_pointer     , A1
        STD         .D1     A0,   *A1
     || MVK64       .L1     gs_vector_table,A0
        MVC         .S1     A0, ESTP_GS ;write vector location
     || MVK64       .L1     gs_evt_ecq,A0
        MVC         .S1     A0, ECSP_GS ;write ECSP_GS location

        ;; Enable the external events (all of them)
     || MVK64       .L1     0xffffffffffffffff, A0
        MVC         .S1     A0, EESET

        ;; Prep a filter for setting us into S privilege and zero out the HDL bit
        MVK64       .L1     0xFFFFFFFFFFFFFFF0, A2
     || MVC         .S1     TSR,                A3

        ;; Global enable for external events
        REVT        .S1     A0

     || MVK64       .L1     0xff,   A0
        SETCOP      .S1     A0

     || MVK64       .L1         curr_soft_reset_vector, A0
  [!A0] MVK64       .L1         0x0000C0000, A0 ;load default boot address if not supplied
        ;; Create new TSR value with
     || ANDD        .S1     A2,    A3,    A1
        ORD         .L1     A1,    0x3,   A1
        RETE        .S1     A0,    A1

        .align     0x200

int_excp:
  ; // Make sure curr_int_excp_vector is linked. Call curr_int_excp_vector, which has user handler code
	; //if curr_int_excp_vector is not defined while(1)
        MVK64          .L1   curr_int_exp_vector   , A0
 [!A0]  B              .B1   loop_die
        CALLA          .S1   A0                        ; // Call curr_int_exp_vector

	.align 0x200

page_fault:
  ; // Make sure curr_page_fault_vector is linked. Call curr_page_fault_vector, which has user handler code
	; //if curr_page_fault_vector is not defined while(1)
        MVK64          .L1   curr_page_fault_vector   , A0
 [!A0]  B              .B1   loop_die
        CALLA          .S1   A0                          ; // Call the page fault handler

        .align     0x200
nme:
  ; // Make sure curr_nme_vector is linked. Call curr_nme_vector, which has user handler code
	; //if curr_nme_vector is not defined while(1)
        MVK64       .L1         curr_nme_vector,    A0
 [!A0]  B           .B1         loop_die
        CALLA       .S1         A0                   ; // Call the NME handler

        .align     0x200

; //comments describing the event handler
evt:
        ; // Save A0-A7
        MARK                 0
        STD            .D1   A0       , *ECSP[0x300]      ;
  ||    STD            .D2X  A1       , *ECSP[0x301]      ;
        STD            .D1   A2       , *ECSP[0x302]      ;
  ||    STD            .D2X  A3       , *ECSP[0x303]      ;
        STD            .D1   A4       , *ECSP[0x304]      ;
  ||    STD            .D2X  A5       , *ECSP[0x305]      ;
        STD            .D1   A6       , *ECSP[0x306]      ;
  ||    STD            .D2X  A7       , *ECSP[0x307]      ;

        ; //Save the current stack pointer (could be the Task's SP or could be the Handlers SP, either way,
        ; //we need to restore it before we return
        ; //Also, we're going to need VB15 in the save/restore handlers, so save it too
        STD            .D1   D15      , *ECSP[0x318]   ; // Store D15 at a location AFTER where we store VB14, VB15.  VB14, VB15 takes up 16 DWORDS in memory, so increment by 16
||      VST8D          .D2   VB14     , *ECSP[0x308]  ; // 0x308 is aligned to a 8 double word offset, so put VB14 at the aligned location
        VST8D          .D2   VB15     , *ECSP[0x310]  ; // 0x310 is aligned to a 8 double word offset, so put VB15 at the aligned location

        ; // Save RP
        MVC            .S1   RP       , A3                ;
        STD            .D1   A3       , *ECSP[0x340]      ;

        ; // Test the TSR.HDL bit of the task we pre-empted to see if D15 is already loaded with the supervisor stack pointer
        LDD             .D1   *ECSP[1], A0                ; // Grab the previous TSR
        SHRD            .L1   A0, 3, A0                   ; // HDL bit is bit 3 of TSR/ITSR
        ANDD            .L1   A0, 1, A0                   ; // Isolate the HDL bit
 [A0]   B               .B1   skip_ss_sp_load             ; // HDL is set: skip loading of the SP

        ; // Load the supervisor stack pointer, and allocate 8KB of space
        MVK64           .S1   ss_stack_pointer, A0        ; // Get the stack pointer's address
        LDD             .D1   *A0, D15                    ; // Load the stack into

skip_ss_sp_load:

       ; // Allocate 8KB on the stack for the local variables
        MVK32           .L1   0x2000, A0                  ;
        SUBAB           .D1   D15, A0, D15                ;

       ; // Save all EABI registers
        MVK32          .L1   16, A0                      ; // EABI reserves first 16B of every stack frame for functions that are called by this function
        ADDAB          .D1   D15, A0, A4                 ; // A4 is the first argument
        MVK64          .L1   CSL_c7x_SaveAllEABIRegs, A0 ;
        CALLA          .S1   A0

       ; // Save the SA registers
       ; // Create a pointer to the area we want to save the SA register state too.  There must be 512 bytes available
        MVK32          .L1   3200, A3
        ADDAB          .D1   D15, A3, A4                      ; // Point to the area in the stack frame reserved for these registers (512 bytes starting at offset 32 from the SP)
        MVK64          .L1   CSL_c7x_SaveSARegs, A0
        CALLA          .S1   A0

       ; // Save the SE registers
       ; // Create a pointer to the area we want to save the SE state too.  There must be 512 bytes available
        MVK32          .L1   3712, A3
        ADDAB          .D1   D15, A3, A4                      ; // Point to the area in the stack frame reserved for these registers (512 bytes starting at offset 32 from the SP)
        MVK64          .L1   CSL_c7x_SaveSERegs, A0
        CALLA          .S1   A0

        ; // Loop up the event in the registered event table and call it if it exists
	      MVC            .S1   AHPEE              , D0
     || MVK64          .L1   ss_evt_vector_table, A0
        LDD            .D1   *A0[D0]            , A0
   [A0] CALLA          .S1   A0

       ; // Restore all EABI registers
        MVK32          .L1   16, A0                         ; // EABI reserves first 16B of every stack frame for functions that are called by this function
        ADDAB          .D1   D15, A0, A4                    ; // A4 is the first argument
        MVK64          .L1   CSL_c7x_RestoreAllEABIRegs, A0
        CALLA          .S1   A0

        ; // Restore the SA registers
        ; // Create a pointer to the area we want to save the SA register state too.  There must be 512 bytes available
        MVK32          .L1   3200, A3
        ADDAB          .D1   D15, A3, A4                      ; Point to the area in the stack frame reserved for these registers (512 bytes starting at offset 32 from the SP)

        MVK64          .L1   CSL_c7x_RestoreSARegs, A0
        CALLA          .S1   A0

        ; // Restore the SE registers
        ; // Create a pointer to the area we want to save the SE state too.  There must be 512 bytes available
        MVK32          .L1   3712, A3
        ADDAB          .D1   D15, A3, A4                      ; Point to the area in the stack frame reserved for these registers (512 bytes starting at offset 32 from the SP)

        MVK64          .L1   CSL_c7x_RestoreSERegs, A0
        CALLA          .S1   A0

        ; //Restore the stack pointer (could be the Task's SP or could be the Handlers SP, either way,
        ; //we need to restore it what it was before we return
        LDD            .D2  *ECSP[0x318]      , D15      ;
||      VLD8D          .D1  *ECSP[0x310]      , VB15     ;

         ; // Retrieve RP
        LDD            .D2  *ECSP[0x340]      , A0       ;
||      VLD8D          .D1  *ECSP[0x308]      , VB14     ;
        MVC            .S1  A0                , RP       ;

	; //Restore A2-A7
        LDD            .D1  *ECSP[0x302]      , A2       ;
  ||    LDD            .D2  *ECSP[0x303]      , A3       ;
        LDD            .D1  *ECSP[0x304]      , A4       ;
  ||    LDD            .D2  *ECSP[0x305]      , A5       ;
        LDD            .D1  *ECSP[0x306]      , A6       ;
  ||    LDD            .D2  *ECSP[0x307]      , A7       ;

        ; // Retrieve ITSR, IRP from ECSP save area
        LDD            .D1  *ECSP[0x0]        , A0       ;
  ||    LDD            .D2  *ECSP[0x1]        , A1       ;

        ; // Retrieve A0-A1 and return
        LDD            .D1  *ECSP[0x300]      , A0       ;
  ||    LDD            .D2  *ECSP[0x301]      , A1       ;
  ||    RETE           .S1   A0               , A1       ;

	.align 0x200

loop_die:
        idle
        b           .B1         loop_die

  .align 0x200

ss_evt_vector_table:
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000
        .word 0x00000000


    .global         ss_evt_ecq
    .sect           .ss_evtecq

ss_evt_ecq:
     .word         0x00000000

    .global         tcsp_evt_ecq
    .sect           .tcsp_evtecq

tcsp_evt_ecq:

  .align 0x800
