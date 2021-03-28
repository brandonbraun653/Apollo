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
;;  int_setup.asm
;;
;;  Description
;;      Contains cache and MMU startup routines for C7x.
;;*****************************************************************************


        .global int_Setup
        .global ss_vector_table
        .global s_vector_table
        .global gs_vector_table
	.global ss_stack_pointer
	.global s_stack_pointer
	.global gs_stack_pointer
	.global CSL_c7x_SaveAllEABIRegs
	.global CSL_c7x_RestoreAllEABIRegs
        .global CSL_c7x_SaveSARegs
        .global CSL_c7x_SaveSERegs
        .global tcsp_evt_ecq
        .global ss_evt_ecq
        .global gs_evt_ecq
        .global s_evt_ecq
        .global ss_evtstack
        .global s_evtstack
        .global gs_evtstack
        .global CSL_c7x_RestoreSARegs
        .global CSL_c7x_RestoreSERegs


int_Setup:
        ; // SS int setup
        MVK64       .L1     ss_evtstack+0x20000  , A0
        MVK64       .L1     ss_stack_pointer     , A1
	STD         .D1     A0,   *A1
        MVK64       .L1     ss_vector_table,A0
        MVC         .S1     A0, ESTP_SS ;write ESTP location
        MVK64       .L1     ss_evt_ecq,A0
        MVC         .S1     A0, ECSP_SS ;write ECSP_SS location
        ; //Init TCSP EVT ECQ
        MVK64       .L1     tcsp_evt_ecq,A0
        MVC         .S1     A0, TCSP ;write TCSP location

        ; //S int setup
        MVK64       .L1     s_evtstack+0x20000  , A0
        MVK64       .L1     s_stack_pointer     , A1
	STD         .D1     A0,   *A1
        MVK64       .L1     s_vector_table,A0
        MVC         .S1     A0, ESTP_S ;write vector location
        MVK64       .L1     s_evt_ecq,A0
        MVC         .S1     A0, ECSP_S ;write ECSP_S location
        ; //GS int setup
        MVK64       .L1     gs_evtstack+0x20000  , A0
        MVK64       .L1     gs_stack_pointer     , A1
	STD         .D1     A0,   *A1
        MVK64       .L1     gs_vector_table,A0
        MVC         .S1     A0, ESTP_GS ;write vector location
        MVK64       .L1     gs_evt_ecq,A0
        MVC         .S1     A0, ECSP_GS ;write ECSP_GS location

        ;; Enable the external events (all of them)
        MVK64       .L1     0xffffffffffffffff, A0
        MVC         .S1     A0, EESET

        ;; Global enable for external events
        REVT        .S1     A0

        MVK64       .L1     0xff,   A0
        SETCOP      .S1     A0


        RET         .B1

;;----------------------------------------------------------------------------------------------
; CSL_c7x_SaveAllEABIRegs
; Arguments -- A4 -- save area pointer -- must point to an area which has 2775 bytes of storage available (or 2712 bytes if the pointer has been aligned to 64 bytes)
;;----------------------------------------------------------------------------------------------
;
; Assumptions
;    Only A0-A7, D15, VB15 and RP have been saved so far.  All other registers must be saved.
;
;;----------------------------------------------------------------------------------------------
; Functionality:
;   Save the rest of the registers that the EABI knows about, starting at the address in A4.
;   Note that the vector stores will be issued as aligned 64B stores, so the first thing we do is make sure we start
;   at an aligned address.
;
;   The ABI designates RP, D15 (SP), A8-A15, B14/VB14, and B15/VB15 as callee-save. That is, a called
;   function is required to preserve them so they have the same value on return from a function as they had
;   at the point of the call.
;   All other registers are caller-save; that is, they are not preserved across a call, so if their value is needed
;   following the call, the caller is responsible for saving and restoring their contents.
;
;   Just for safety, though we'll go ahead and save all there registers anyway
;     1. A8-A15
;     2. VB0-VB14 (512-bit registers)  * NOTE: VB15 already saved outside of this function
;     3. AL0-AL7, AM0-AM7
;     4. VBL0-VBL7, VBM0-VBM7 (512-bit registers)
;     5. D0-D14    * NOTE: D15 is already saved and being used in this function!
;     6. P0-P7   (MVP to move P to scalar, and MV moves from scalar to P.  For saving, there is a STPREDB instruction that will store the register directly)
;     7. CUCR0-CUCR3 (Note these are 512-bit registers)
;     8. FPCR, FSR, GFPGFR, GPLY
;
;     Total storage space :
;       32+4 64-byte registers == 2304 bytes
;       43 8-byte registers == 344 bytes
;       0 to 63 bytes of pad for aligning the vector store pointer to a 64B boundary
;       Total: 2712-2775 bytes of storage space
;
;   Other notes:
;   1. The store operations can access A0-A15, VB0-VB15, P0-P7 (using STPREDB) and D0-D15 as operands, but cannot have local registers as an operand.
;      Those registers will need to be manually moved into a register that can be an operand on the store instructions.
;   2. This function obeys the EABI register usage model, and therefore only uses A0-A7 and VB14/15 as scratch registers
;   3. VST64B VB0, *D0++ is equivalent to VST64B VB0, *D0++(64) -- it will increment by the vector width
;;----------------------------------------------------------------------------------------------
CSL_c7x_SaveAllEABIRegs:
 ; // Register usage:
      ; //   A6 -- pointer to memory area for scalar registers
      ; //   A7 -- pointer to memory area for vector registers

      ; // First, take in the Address pointer and align it to a 64-Byte boundary
      MVK32           .L1 63,    A0
      ADDAB           .D1 A4,    A0, A7          ; // Add 63 bytes to get this number to overflow into the next 64 Byte range if it is not aligned
||    MVK32           .L1 0x3f,  A1              ; // save a cycle by putting this MVK32 in parallel w/ the ADDAB
      ANDND           .L1 A1,    A7, A7          ; // Align the address to 64 bytes -- Vector store pointer ready to use!

      ; // Create the scalar store pointer
      ; The storage space required for the vectors is 2304 bytes.  Store the scalars immediately above that
      MVK32           .L1 2304, A0
      ADDAB           .D1 A7,   A0, A6

      ; --------------------------------------------------------------------------
      ; // Store the Vector RF in parallel with the Dx registers --  NOTE: D15 and VB15 were saved outside of this function.
      ; --------------------------------------------------------------------------
      STD             .D1 D0,    *A6++[1]
||    VST64B          .D2 VB0,   *A7++

      STD             .D1 D1,    *A6++[1]
||    VST64B          .D2 VB1,   *A7++

      STD             .D1 D2,    *A6++[1]
||    VST64B          .D2 VB2,   *A7++

      STD             .D1 D3,    *A6++[1]
||    VST64B          .D2 VB3,   *A7++

      STD             .D1 D4,    *A6++[1]
||    VST64B          .D2 VB4,   *A7++

      STD             .D1 D5,    *A6++[1]
||    VST64B          .D2 VB5,   *A7++

      STD             .D1 D6,    *A6++[1]
||    VST64B          .D2 VB6,   *A7++

      STD             .D1 D7,    *A6++[1]
||    VST64B          .D2 VB7,   *A7++

      STD             .D1 D8,    *A6++[1]
||    VST64B          .D2 VB8,   *A7++

      STD             .D1 D9,    *A6++[1]
||    VST64B          .D2 VB9,   *A7++

      STD             .D1 D10,   *A6++[1]
||    VST64B          .D2 VB10,  *A7++

      STD             .D1 D11,   *A6++[1]
||    VST64B          .D2 VB11,  *A7++

      STD             .D1 D12,   *A6++[1]
||    VST64B          .D2 VB12,  *A7++

      STD             .D1 D13,   *A6++[1]
||    VST64B          .D2 VB13,  *A7++

      STD             .D1 D14,   *A6++[1]         ; Stop at D14


      ; --------------------------------------------------------------------------
      ; //Save the M local register files -- using A0 and VB15  for temp storage
      ; --------------------------------------------------------------------------
      MV              .M1 AM0,    A0          ; Move AM0 into A0
||    VMV             .M2 VBM0,   VB15         ; Move VBM0 into VB15

      STD             .D1 A0,    *A6++[1]     ; A0 contains AM0 --> store it to the save area
||    VST64B          .D2 VB15,   *A7++        ; VB15 contains VBM0 --> store it
||    MV              .M1 AM1,    A0          ; Move AM1 into A0 for the store in the following clock
||    VMV             .M2 VBM1,   VB15        ; Move VBM1 into VB15 for the store in the following clock

      STD             .D1 A0,    *A6++[1]     ; A0 has AM1 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBM1 in it
||    MV              .M1 AM2,    A0
||    VMV             .M2 VBM2,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AM2 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBM2 in it
||    MV              .M1 AM3,    A0
||    VMV             .M2 VBM3,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AM3 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBM3 in it
||    MV              .M1 AM4,    A0
||    VMV             .M2 VBM4,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AM4 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBM4 in it
||    MV              .M1 AM5,    A0
||    VMV             .M2 VBM5,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AM5 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBM5 in it
||    MV              .M1 AM6,    A0
||    VMV             .M2 VBM6,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AM7 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBM7 in it
||    MV              .M1 AM7,    A0          ; Last set of moves for the following stores
||    VMV             .M2 VBM7,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AM7 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBM7 in it

      ; --------------------------------------------------------------------------
      ; //Save the L local register files in similar method to the above
      ; --------------------------------------------------------------------------
      MV              .L1 AL0,    A0          ; Move AL0 into A0
||    VMV             .L2 VBL0,   VB15        ; Move VBL0 into VB15

      STD             .D1 A0,    *A6++[1]     ; A0 contains AL0 --> store it to the save area
||    VST64B          .D2 VB15,   *A7++        ; VB15 contains VBL0 --> store it
||    MV              .L1 AL1,    A0          ; Move AL1 into A0 for the store in the following clock
||    VMV             .L2 VBL1,   VB15        ; Move VBL1 into VB15 for the store in the following clock

      STD             .D1 A0,    *A6++[1]     ; A0 has AL1 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBL1 in it
||    MV              .L1 AL2,    A0
||    VMV             .L2 VBL2,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AL2 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBL2 in it
||    MV              .L1 AL3,    A0
||    VMV             .L2 VBL3,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AL3 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBL3 in it
||    MV              .L1 AL4,    A0
||    VMV             .L2 VBL4,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AL4 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBL4 in it
||    MV              .L1 AL5,    A0
||    VMV             .L2 VBL5,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AL5 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBL5 in it
||    MV              .L1 AL6,    A0
||    VMV             .L2 VBL6,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AL7 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBL7 in it
||    MV              .L1 AL7,    A0          ; Last set of moves for the following stores
||    VMV             .L2 VBL7,   VB15

      STD             .D1 A0,    *A6++[1]     ; A0 has AL7 in it
||    VST64B          .D2 VB15,   *A7++        ; VB15 has VBL7 in it

      ; --------------------------------------------------------------------------
      ; // Save A8-15 in parallel with P0-P7 -- Note: both of these are using the scalar pointer
      ; --------------------------------------------------------------------------
      STD             .D1  A8,    *A6++[2]     ; // Increment by 2 DWORDs because we're storing 2 in parallel
||    STD             .D2X A9,    *A6[1]
||    MVPB            .L2  P0,    B0
||    MVPB            .S2  P1,    B1
      STD             .D1  A10,   *A6++[2]
||    STD             .D2X A11,   *A6[1]
||    MVPB            .L2  P2,    B2
||    MVPB            .S2  P3,    B3
      STD             .D1  A12,   *A6++[2]
||    STD             .D2X A13,   *A6[1]
||    MVPB            .L2  P4,    B4
||    MVPB            .S2  P5,    B5
      STD             .D1  A14,   *A6++[2]
||    STD             .D2X A15,   *A6[1]
||    MVPB            .L2  P6,    B6
||    MVPB            .S2  P7,    B7

      STD             .D1X B0,  *A6++[2]     ; // Increment by 2 DWORDs because we're storing 2 in parallel
||    STD             .D2  B1,  *A6[1]
      STD             .D1X B2,  *A6++[2]     ; // Increment by 2 DWORDs because we're storing 2 in parallel
||    STD             .D2  B3,  *A6[1]
      STD             .D1X B4,  *A6++[2]     ; // Increment by 2 DWORDs because we're storing 2 in parallel
||    STD             .D2  B5,  *A6[1]
      STD             .D1X B6,  *A6++[2]     ; // Increment by 2 DWORDs because we're storing 2 in parallel
||    STD             .D2  B7,  *A6[1]

      ; --------------------------------------------------------------------------
      ; // Finally, save the miscellaneous control registers:
      ; // CUCR0-CUCR3,  FPCR, FSR, GFPGFR, GPLY
      ; --------------------------------------------------------------------------

      ; // NOTE:   CUCR's take 3 cycles to read, other CR reads are 2 cycle instructions -- wait for the MVC's to complete before issuing stores so we avoid RAW hazarding stalls
      ; // We have also saved all the general purpose registers, so we are free to use any of the registers as temporary storage (other than the callee-save registers)

      MVC             .S1 FPCR,    A0
||    MVC             .C2 CUCR0,   VB0
      MVC             .S1 FSR,     A1
||    MVC             .C2 CUCR1,   VB1
      MVC             .S1 GFPGFR,  A2
||    MVC             .C2 CUCR2,   VB2
      MVC             .S1 GPLY,    A3        ; VB0 is available with CUCR0 in it in this cycle
||    MVC             .C2 CUCR3,   VB3
||    STD             .D1 A0,     *A6++[1]   ; Write FPCR
||    VST64B          .D2 VB0,    *A7++      ; Write CUCR0
      STD             .D1 A1,     *A6++[1]   ; Write FSR
||    VST64B          .D2 VB1,    *A7++      ; Write CUCR1
      STD             .D1 A2,     *A6++[1]   ; Write GFPGFR
||    VST64B          .D2 VB2,    *A7++      ; Write CUCR2
      STD             .D1 A3,     *A6++[1]   ; Write GPLY
||    VST64B          .D2 VB3,    *A7++      ; Write CUCR3

      ; --------------------------------------------------------------------------
      ; Done!  Nothing to restore, so we can just return
      ; --------------------------------------------------------------------------
      RET             .B1
;; ----------------------------------------------------------------------------------------------------------------------------------------------------
;; End Function CSL_c7x_SaveAllEABIRegs
;; ----------------------------------------------------------------------------------------------------------------------------------------------------

;;------------------------------------------------------------------------------------------------------------------------------------------------
; CSL_c7x_SaveSARegs
; Arguments -- A4 -- save area pointer -- Create a pointer to the area we want to save the register state too.  There must be 2712 bytes available
; Functionality -- Save all SA registers
;;------------------------------------------------------------------------------------------------------------------------------------------------

CSL_c7x_SaveSARegs:
      ; // First, take in the Address pointer and align it to a 64-Byte boundary
      MVK32           .L1 63,    A0
      ADDAB           .D1 A4,    A0,  A7         ; // Add 63 bytes to get this number to overflow into the next 64 Byte range if it is not aligned
||    MVK32           .L1 0x3f,  A1              ; // save a cycle by putting this MVK32 in parallel w/ the ADDAB
      ANDND           .L1 A1,    A7,  A7         ; // Align the address to 64 bytes -- Vector store pointer ready to use!

      MVC             .C2 STRACNTR0, VB15
      VST64B          .D2      VB15, *A7++
 ||   MVC             .C2 STRACNTR1, VB15
      VST64B          .D2      VB15, *A7++
 ||   MVC             .C2 STRACNTR2, VB15
      VST64B          .D2      VB15, *A7++
 ||   MVC             .C2 STRACNTR3, VB15
      VST64B          .D2      VB15, *A7++
 ||   MVC             .C2   STRACR0, VB15
      VST64B          .D2      VB15, *A7++
 ||   MVC             .C2   STRACR1, VB15
      VST64B          .D2      VB15, *A7++
 ||   MVC             .C2   STRACR2, VB15
      VST64B          .D2      VB15, *A7++
 ||   MVC             .C2   STRACR3, VB15
      VST64B          .D2      VB15, *A7++

      RET             .B1

;; ----------------------------------------------------------------------------------------------------------------------------------------------------
;; End Function CSL_c7x_SaveSARegs
;; ----------------------------------------------------------------------------------------------------------------------------------------------------

;;------------------------------------------------------------------------------------------------------------------------------------------------
; CSL_c7x_SaveSERegs
; Arguments -- A4 -- save area pointer -- Create a pointer to the area we want to save the register state too.  There must be 2712 bytes available
; Functionality -- Save all SE registers
;;------------------------------------------------------------------------------------------------------------------------------------------------

CSL_c7x_SaveSERegs:

      ; // First, take in the Address pointer and align it to a 64-Byte boundary
      MVK32           .L1 63,    A0
      ADDAB           .D1 A4,    A0,  A7         ; // Add 63 bytes to get this number to overflow into the next 64 Byte range if it is not aligned
||    MVK32           .L1 0x3f,  A1              ; // save a cycle by putting this MVK32 in parallel w/ the ADDAB
      ANDND           .L1 A1,    A7,  A7         ; // Align the address to 64 bytes -- Vector store pointer ready to use!

      ; // save 3-0 vector registers in SE1 and SE0
      SESAVE          .L2 3,  1,  VB15
      VST64B          .D2  VB15,   *A7++
  ||  SESAVE          .L2 2,  1,  VB15
      VST64B          .D2  VB15,   *A7++
  ||  SESAVE          .L2 1,  1,  VB15
      VST64B          .D2  VB15,   *A7++
  ||  SESAVE          .L2 0,  1,  VB15
      VST64B          .D2  VB15,   *A7++
  ||  SESAVE          .L2 3,  0,  VB15
      VST64B          .D2  VB15,   *A7++
  ||  SESAVE          .L2 2,  0,  VB15
      VST64B          .D2  VB15,   *A7++
  ||  SESAVE          .L2 1,  0,  VB15
      VST64B          .D2  VB15,   *A7++
  ||  SESAVE          .L2 0,  0,  VB15
      VST64B          .D2  VB15,   *A7++

      RET             .B1
;; ----------------------------------------------------------------------------------------------------------------------------------------------------
;; End Function CSL_c7x_SaveSERegs
;; ----------------------------------------------------------------------------------------------------------------------------------------------------


;; ----------------------------------------------------------------------------------------------------------------------------------------------------
; CSL_c7x_RestoreAllEABIRegs
; Arguments -- A4 -- save area pointer -- must point to an area which has 2775 bytes of storage available (or 2712 if the pointer has been aligned to 64 bytes)
;
;; ----------------------------------------------------------------------------------------------------------------------------------------------------
; Assumptions
;     A0-A7, D15, VB15 and RP were saved by a different mechanism.  All other registers will be restored
;
;; ----------------------------------------------------------------------------------------------------------------------------------------------------
; Functionality:
;   Restore the rest of the registers that the EABI knows about, starting at the address in A4.
;   Note that the vector stores will be issued as aligned 64B stores, so the first thing we do is make sure we start
;   at an aligned address.
;
;   The ABI designates RP, D15 (SP), A8-A15, B14/VB14, and B15/VB15 as callee-save. That is, a called
;   function is required to preserve them so they have the same value on return from a function as they had
;   at the point of the call.
;   All other registers are caller-save; that is, they are not preserved across a call, so if their value is needed
;   following the call, the caller is responsible for saving and restoring their contents.
;
;   We will restore these registers from the save area
;     1. A8-A15
;     2. VB0-VB14 (512-bit registers)  * VB15 will be restored outside of this function
;     3. AL0-AL7, AM0-AM7
;     4. VBL0-VBL7, VBM0-VBM7 (512-bit registers)
;     5. D0-D14    * NOTE: D15 is the stack pointer and will not be restored
;     6. P0-P7   (MVP to move P to scalar, and MV moves from scalar to P.)
;     7. CUCR0-CUCR3 (Note these are 512-bit registers)
;     8. FPCR, FSR, GFPGFR, GPLY
;
;     Total storage space :
;       32+4 64-byte registers == 2304 bytes
;       43 8-byte registers == 344 bytes
;       0 to 63 bytes of pad
;       Total: 2712-2775 bytes of storage space
;
;   Other notes:
;   1. The load operations can access A0-A15, VB0-VB15, P0-P7 (using STPREDB) and D0-D15 as operands, but cannot have local registers as an operand.
;      Those registers will need to be manually moved into a register that can be an operand on the store instructions.
;   2. This function obeys the EABI register usage model, and therefore only uses A0-A7 and VB14/15 as scratch registers
;   3. VST64B VB0, *D0++ is equivalent to VST64B VB0, *D0++(64) -- it will increment by the vector width
;
;; ----------------------------------------------------------------------------------------------------------------------------------------------------
CSL_c7x_RestoreAllEABIRegs:
 ; // Register usage:
      ; //   A6 -- pointer to memory area for scalar registers
      ; //   A7 -- pointer to memory area for vector registers

      MVK32           .L1   63,    A0
      ADDAB           .D1   A4,    A0,  A7       ; // Add 63 bytes to get this number to overflow into the next 64 Byte range if it is not aligned
||    MVK32           .L1   0x3f,  A1            ; // Save a cycle by putting this instruction in parallel with the ADDAB instruction
      ANDND           .L1   A1,    A7, A7        ; // Align the address to 64 bytes -- Vector store pointer ready to use!

      ; // Create the scalar store pointer
      MVK32           .L1   2304, A0
      ADDAB           .D1   A7,   A0, A6

      ; // Set up SE template for reading the scalar side
      ; // Parameters:
      ; // ELTYPE = Dwords
      ; // VECLEN = 1 Element (encoded as zere in the veclen field)
      ;  ICNT0  = 51

      VMVK32          .L2     0,    VB15             ; // Most of the template needs to be zeroed out
      MVK32           .L2    51,    VB15             ; //number of dwords
||    MVK32           .S1     3,    A0               ; //ELtype=dwords
      VPUTD           .C2X   A0,    7, VB15

      SEOPENSC        .D2    A7,    1, 0          ; // Open SE1 starting at base address A7, with a stream of bytes   -- open SE1 first to hide 1 cycle of the RAW hazard on VB15
      SEOPEN          .D2    A6,    0, VB15       ; // Open SE0 starting at base address A6, with a stream of double-words (matters in big-endian mode)

 ; // Restore the Vector RF and Dx registers
      MV              .L2   SE0++,  VB15         ; // Move the saved D0 into B15
      MV              .L2   SE0++,  VB14         ; // Move the saved D1 into B14
||    VMV             .S2   SE1++,  VB0          ; // Move the saved VB0 to VB0
      MV	      .D1X  B15  ,  D0	         ; // Move the saved D0 into D0
||    MV	      .L2   SE0++,  VB15         ; // Move the saved D2 into B15
||    VMV	      .S2   SE1++,  VB1	         ; // Move the saved VB1 to VB1
      MV	      .D1X  B14  ,  D1	         ; // Move the saved D1 into D1
||    MV	      .L2   SE0++,  VB14         ;
||    VMV	      .S2   SE1++,  VB2	         ;
      MV	      .D1X  B15  ,  D2	         ;
||    MV	      .L2   SE0++,  VB15         ;
||    VMV	      .S2   SE1++,  VB3	         ;
      MV	      .D1X  B14  ,  D3	         ;
||    MV	      .L2   SE0++,  VB14         ;
||    VMV	      .S2   SE1++,  VB4	         ;
      MV	      .D1X  B15  ,  D4	         ;
||    MV	      .L2   SE0++,  VB15         ;
||    VMV	      .S2   SE1++,  VB5	         ;
      MV	      .D1X  B14  ,  D5	         ;
||    MV	      .L2   SE0++,  VB14         ;
||    VMV	      .S2   SE1++,  VB6	         ;
      MV	      .D1X  B15  ,  D6	         ;
||    MV	      .L2   SE0++,  VB15         ;
||    VMV	      .S2   SE1++,  VB7	         ;
      MV	      .D1X  B14  ,  D7	         ;
||    MV	      .L2   SE0++,  VB14         ;
||    VMV	      .S2   SE1++,  VB8	         ;
      MV	      .D1X  B15  ,  D8	         ;
||    MV	      .L2   SE0++,  VB15         ;
||    VMV	      .S2   SE1++,  VB9	         ;
      MV	      .D1X  B14  ,  D9	         ;
||    MV	      .L2   SE0++,  VB14         ;
||    VMV	      .S2   SE1++,  VB10         ;
      MV	      .D1X  B15  ,  D10	         ;
||    MV	      .L2   SE0++,  VB15         ;
||    VMV	      .S2   SE1++,  VB11         ;
      MV	      .D1X  B14  ,  D11	         ;
||    MV	      .L2   SE0++,  VB14         ;
||    VMV	      .S2   SE1++,  VB12         ;
      MV	      .D1X  B15  ,  D12	         ;
||    MV	      .L2   SE0++,  VB15         ;
||    VMV	      .S2   SE1++,  VB13         ;
      MV	      .D1X  B14  ,  D13	         ;
      MV	      .D1X  B15  ,  D14	         ;

      ; // Restoring the local register files is easy w/ the SE because each unit can read the XPATH on the scalar side and the SE on the vector side
      ; // Any unit can write every local register file, so can still use any unit for all the writes
      MV              .L2   SE0++, VB15           ; // Move the saved AM0 into B15
      MV              .L2   SE0++, VB14           ; // Move the saved AM1 into B14
||    VMV             .M2   SE1++, VBM0           ; // Move the saved VBM0 to VBM0
      MV              .M1X  B15  , AM0            ; // Move the saved AM0 into AM0
||    MV              .L2   SE0++, VB15           ;
||    VMV             .M2   SE1++, VBM1           ;
      MV              .M1X  B14  , AM1            ;
||    MV              .L2   SE0++, VB14           ;
||    VMV             .M2   SE1++, VBM2           ;
      MV              .M1X  B15  , AM2            ;
||    MV              .L2   SE0++, VB15           ;
||    VMV             .M2   SE1++, VBM3           ;
      MV              .M1X  B14  , AM3            ;
||    MV              .L2   SE0++, VB14           ;
||    VMV             .M2   SE1++, VBM4           ;
      MV              .M1X  B15  , AM4            ;
||    MV              .L2   SE0++, VB15           ;
||    VMV             .M2   SE1++, VBM5           ;
      MV              .M1X  B14  , AM5            ;
||    MV              .L2   SE0++, VB14           ;
||    VMV             .M2   SE1++, VBM6           ;
      MV              .M1X  B15  , AM6            ;
||    VMV             .M2   SE1++, VBM7           ;
      MV              .M1X  B14  , AM7            ;

      MV              .L2   SE0++, VB15           ; // Move the saved AL0 into B15
      MV              .L2   SE0++, VB14           ; // Move the saved AL1 into B14
||    VMV             .M2   SE1++, VBL0           ; // Move the saved VBL0 to VBL0
      MV              .M1X  B15  , AL0            ; // Move the saved AL0 into AL0
||    MV              .L2   SE0++, VB15           ; // Move the saved M1 into B15
||    VMV             .M2   SE1++, VBL1           ; // Move the saved VBL1 to VBL1
      MV              .M1X  B14  , AL1            ; // Move the saved AL1 into AL1
||    MV              .L2   SE0++, VB14           ;
||    VMV             .M2   SE1++, VBL2           ;
      MV              .M1X  B15  , AL2            ;
||    MV              .L2   SE0++, VB15           ;
||    VMV             .M2   SE1++, VBL3           ;
      MV              .M1X  B14  , AL3            ;
||    MV              .L2   SE0++, VB14           ;
||    VMV             .M2   SE1++, VBL4           ;
      MV              .M1X  B15  , AL4            ;
||    MV              .L2   SE0++, VB15           ;
||    VMV             .M2   SE1++, VBL5           ;
      MV              .M1X  B14  , AL5            ;
||    MV              .L2   SE0++, VB14           ;
||    VMV             .M2   SE1++, VBL6           ;
      MV              .M1X  B15  , AL6            ;
||    VMV             .M2   SE1++, VBL7           ;
      MV              .M1X  B14  , AL7            ;


      ; // Restoring the A8-A15 and P0-P7 will have to serially instead of in parallel.
      ; // Order they will come out of SE0 is A8, P0, A9, P1, A10, P2 ....

      MV              .M2   SE0++, VB15           ; // Move A8 restore value to B15
      MV              .M2   SE0++, VB14           ; // Move A9 restore value to B14
      MV              .L1X  B15,    A8            ; // move A8 restore value to A8
||    MV              .M2   SE0++, VB15           ;
      MV              .L1X  B14,    A9            ;
||    MV              .M2   SE0++, VB14           ;
      MV              .L1X  B15,    A10           ;
||    MV              .M2   SE0++, VB15           ;
      MV              .L1X  B14,    A11           ;
||    MV              .M2   SE0++, VB14           ;
      MV              .L1X  B15,    A12           ;
||    MV              .M2   SE0++, VB15           ;
      MV              .L1X  B14,    A13           ;
||    MV              .M2   SE0++, VB14           ;
      MV              .L1X  B15,    A14           ;
||    MV              .M2   SE0++, VB15           ;
      MV              .L1X  B14,    A15           ;
||    MV              .M2   SE0++, VB14           ; // Move P0 restore value to B15
      MV              .L2   B15,    P0            ; // move P0 restore value to P0
||    MV              .M2   SE0++, VB15           ;
      MV              .L2   B14,    P1            ;
||    MV              .M2   SE0++, VB14           ;
      MV              .L2   B15,    P2            ;
||    MV              .M2   SE0++, VB15           ;
      MV              .L2   B14,    P3            ;
||    MV              .M2   SE0++, VB14           ;
      MV              .L2   B15,    P4            ;
||    MV              .M2   SE0++, VB15           ;
      MV              .L2   B14,    P5            ;
||    MV              .M2   SE0++, VB14           ;
      MV              .L2   B15,    P6            ;
||    MV              .S2   B14,    P7            ;


      ; // Finally, restore the miscellaneous control registers:
      ; // CUCR0-CUCR3,  FPCR, FSR, GFPGFR, GPLY
      MV              .L2   SE0++, VB15           ; // Move the saved FPCR into B15
      MV              .L2   SE0++, VB14           ; // Move the saved FSR into B14
||    MVC             .C2   SE1++, CUCR0          ; // Move the saved CUCR0 to CUCR0
      MVC             .S1X  B15  , FPCR           ; // Move the saved FPCR into FPCR
||    MV              .L2   SE0++, VB15           ; // Move the saved GFPGFR into B15
||    MVC             .C2   SE1++, CUCR1          ; // Move the saved CUCR1 to CUCR1
      MVC             .S1X  B14  , FSR            ; // Move the saved FSR into FSR
||    MV              .L2   SE0++, VB14           ; // Move the saved GPLY into B14
||    MVC             .C2   SE1++, CUCR2          ;
      MVC             .S1X  B15  , GFPGFR         ;
||    MVC             .C2   SE1++, CUCR3          ;
      MVC             .S1X  B14  , GPLY           ;

      SECLOSE         .D2   0
      SECLOSE         .D2   1

      RET	      .B1

;; ----------------------------------------------------------------------------------------------------------------------------------------------------
CSL_c7x_RestoreSARegs:
 ; // Register usage:
      ; //   A6 -- pointer to memory area for scalar registers
      ; //   A7 -- pointer to memory area for vector registers

      MVK32           .L1   63,    A0
      ADDAB           .D1   A4,    A0,  A7       ; // Add 63 bytes to get this number to overflow into the next 64 Byte range if it is not aligned
||    MVK32           .L1   0x3f,  A1            ; // Save a cycle by putting this instruction in parallel with the ADDAB instruction
      ANDND           .L1   A1,    A7, A7        ; // Align the address to 64 bytes -- Vector store pointer ready to use!

      SEOPENSC        .D2    A7,    1, 0         ; // Open SE1 starting at base address A7, with a stream of bytes   -- open SE1 first to hide 1 cycle of the RAW hazard on VB15
      VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACNTR0      ;
  ||  VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACNTR1      ;
  ||  VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACNTR2      ;
  ||  VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACNTR3      ;
  ||  VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACR0        ;
  ||  VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACR1        ;
  ||  VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACR2        ;
  ||  VMV             .S2   SE1++,  VB15         ;
      MVC             .C2   VB15, STRACR3        ;

      SECLOSE         .D2   1                    ; // close SE1 stream

      RET             .B1

;; ----------------------------------------------------------------------------------------------------------------------------------------------------
CSL_c7x_RestoreSERegs:
 ; // Register usage:
      ; //   A6 -- pointer to memory area for scalar registers
      ; //   A7 -- pointer to memory area for vector registers

      MVK32           .L1   63,    A0
      ADDAB           .D1   A4,    A0,  A7       ; // Add 63 bytes to get this number to overflow into the next 64 Byte range if it is not aligned
||    MVK32           .L1   0x3f,  A1            ; // Save a cycle by putting this instruction in parallel with the ADDAB instruction
      ANDND           .L1   A1,    A7, A7        ; // Align the address to 64 bytes -- Vector store pointer ready to use!

      VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       3,  1, VB15
  ||  VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       2,  1, VB15
  ||  VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       1,  1, VB15
  ||  VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       0,  1, VB15
  ||  VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       3,  0, VB15
  ||  VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       2,  0, VB15
  ||  VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       1,  0, VB15
  ||  VLD64B          .D1   *A7++[64], VB15
      SERSTR          .D2       0,  0, VB15

      RET             .B1

 .sect ".ss_evtstack"
ss_evtstack:
        .word       0x00000000

 .sect ".s_evtstack"
s_evtstack:
        .word       0x00000000

 .sect ".gs_evtstack"
gs_evtstack:
        .word       0x00000000
