	/*
******************************************************************************
*  Copyright (C) 2015 Texas Instruments Incorporated - http:*www.ti.com/
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*      Redistributions of source code must retain the above copyright
*      notice, this list of conditions and the following disclaimer.
*
*      Redistributions in binary form must reproduce the above copyright
*      notice, this list of conditions and the following disclaimer in the
*      documentation and/or other materials provided with the
*      distribution.
*
*      Neither the name of Texas Instruments Incorporated nor the names of
*      its contributors may be used to endorse or promote products derived
*      from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************

******************************************************************************
*  misc_inst.s
*
*  Description
*      This is the CSL-F implementation for ARM memory sychronization operations
*
******************************************************************************
*
*  Code derived from ARM LTD examples and documentation found in the
*  following documents.
*
*  ARM® Cortex® -A53 MPCore Processor
*  Revision: r0p4
*  Technical Reference Manual
*
*  ARM® Architecture Reference Manual
*  ARMv8, for ARMv8-A architecture profile
*  Beta
*/
    .section arm64misc, "ax", %progbits

/*
 *
 *  void CSL_a53Exit(void)
 *  This is a baremetal exit code
 *  After the baremetal application is complete, the control comes
 *  here and waits until a system reset/power cycle
 */
    .global CSL_a53Exit
    .type CSL_a53Exit  , %function
CSL_a53Exit:
     B CSL_a53Exit

    .global CSL_a53v8DmbIsHld
    .type CSL_a53v8DmbIsHld  , %function
CSL_a53v8DmbIsHld:
    DMB ISHLD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DmbIsHst
    .type CSL_a53v8DmbIsHst  , %function
CSL_a53v8DmbIsHst:
    DMB ISHST    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DmbOsHld
    .type CSL_a53v8DmbOsHld  , %function
CSL_a53v8DmbOsHld:
    DMB OSHLD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DmbNsHld
    .type CSL_a53v8DmbNsHld  , %function
CSL_a53v8DmbNsHld:
    DMB NSHLD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DmbLd
    .type CSL_a53v8DmbLd  , %function
CSL_a53v8DmbLd:
    DMB LD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DsbIsHld
    .type CSL_a53v8DsbIsHld  , %function
CSL_a53v8DsbIsHld:
    DSB ISHLD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DsbOsHld
    .type CSL_a53v8DsbOsHld  , %function
CSL_a53v8DsbOsHld:
    DSB OSHLD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DsbNdsHld
    .type CSL_a53v8DsbNdsHld  , %function
CSL_a53v8DsbNdsHld:
    DSB NSHLD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DsbLd
    .type CSL_a53v8DsbLd  , %function
CSL_a53v8DsbLd:
    DSB LD    ; /* Non-shareable load/store */
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8DsbSy
    .type CSL_a53v8DsbSy  , %function
CSL_a53v8DsbSy:
    DSB SY    ; /* Full System DSB Operation */
    BR  X30       ; /*Return to caller */



    .global CSL_a53v8Isb
    .type CSL_a53v8Isb, %function
CSL_a53v8Isb:
    ISB
    BR  X30



    .global CSL_a53v8WFI
    .type CSL_a53v8WFI, %function
CSL_a53v8WFI:
    WFI
    BR  X30




        /*====================================================================== */
        /* ARM_Get_CpuId */
        /* */
        /* This function reads the affinity register, Legacy K2 naming */
        /*====================================================================== */

        .global CSL_a53v8GetCpuId
        .type   CSL_a53v8GetCpuId, %function
CSL_a53v8GetCpuId:
        mrs     x0, mpidr_el1        /*returns are in x0(r0) */
        ret                          /*return to caller */


        /*====================================================================== */
        /* ARM_WriteTTBR0 */
        /* */
        /* Legacy K2 function for writing the EL3 TTBR0 register */
        /*====================================================================== */
        .global CSL_a53v8WriteTtbr0El3
        .type   CSL_a53v8WriteTtbr0El3, %function
CSL_a53v8WriteTtbr0El3:
        msr     ttbr0_el3,x0
        ret


        /*====================================================================== */
        /* ARM_WriteTTBR0_el2 */
        /* */
        /* Fucntion for writing the EL2 TTBR0 */
        /*====================================================================== */
        .global CSL_a53v8WriteTtbr0El2
        .type  CSL_a53v8WriteTtbr0El2 , %function
CSL_a53v8WriteTtbr0El2:
        msr     ttbr0_el2,x0
        ret

        /*====================================================================== */
        /* ARM_WriteTTBR0_el1 */
        /* */
        /* Function for writing the EL1 TTBR0 */
        /*====================================================================== */
        .global CSL_a53v8WriteTtbr0El1
        .type   CSL_a53v8WriteTtbr0El1, %function
CSL_a53v8WriteTtbr0El1:
        msr     ttbr0_el1,x0
        ret


    /************************************* */
    /*** Exception Level Transition Functions */



        .global CSL_a53v8SwitchLevelEl3toEl2
        .type   CSL_a53v8SwitchLevelEl3toEl2, %function
CSL_a53v8SwitchLevelEl3toEl2:
        msr     SCTLR_EL2, xzr          /*Initialize SCTRL_EL2 to safe values */

        mov     x1, #0x401              /* EL2 is AArch64 */
        msr     SCR_EL3, x1             /* SCR_EL3.RW = .NS = 0b1 */

        mov     x1, #0b01001            /* Setup SPRS_EL3 to be "AArch64 with SP_EL2h" */
        msr     SPSR_EL3, x1

        msr     ELR_EL3, x0             /* x0 is the entry point and argument to the function */

        eret



        .global CSL_a53v8SwitchLevelEl3toNsEl1
        .type   CSL_a53v8SwitchLevelEl3toNsEl1, %function
CSL_a53v8SwitchLevelEl3toNsEl1:
        msr     SCTLR_EL1, xzr          /*Initialize SCTRL_EL2 to safe values */

        mov     x1, #0x501              /* EL2 is AArch64, enable HVC[8] */
        msr     SCR_EL3, x1             /* SCR_EL3.RW = .NS = 0b1 */

        mov     x1, #0x80000000              /* EL2 is AArch64 */
        msr     HCR_EL2, x1             /* SCR_EL3.RW = .NS = 0b1 */

        mov     x1, #0b00101            /* Setup SPRS_EL3 to be "AArch64 with SP_EL1h" */
        msr     SPSR_EL3, x1

        msr     ELR_EL3, x0             /* x0 is the entry point and argument to the function */

        eret




        .global CSL_a53v8SwitchLevelEl3toSEl1
        .type   CSL_a53v8SwitchLevelEl3toSEl1, %function
CSL_a53v8SwitchLevelEl3toSEl1:
        msr     SCTLR_EL1, xzr          /*Initialize SCTRL_EL2 to safe values */

        mov     x1, #0x500              /* EL2 is AArch64, enable HVC[8] */
        msr     SCR_EL3, x1             /* SCR_EL3.RW = .NS = 0b1 */

        mov     x1, #0b00101            /* Setup SPRS_EL3 to be "AArch64 with SP_EL1h" */
        msr     SPSR_EL3, x1

        msr     ELR_EL3, x0             /* x0 is the entry point and argument to the function */

        eret

        /*========================================================================= */
        /* change_el3_to_nsel0 */
        /* */
        /*Transition from EL3 to Non-Secure EL0 */
        /* */
        /*========================================================================= */

      .global CSL_a53v8SwitchLevelEl3toNsEl0
        .type   CSL_a53v8SwitchLevelEl3toNsEl0, %function
CSL_a53v8SwitchLevelEl3toNsEl0:
        msr     SCTLR_EL1, xzr          /*Initialize SCTRL_EL2 to safe values */

        mov     x1, #0x401              /* EL2 is AArch64 */
        msr     SCR_EL3, x1             /* SCR_EL3.RW = .NS = 0b1 */

        mov     x1, #0x80000000              /* EL1 is AArch64 */
        msr     HCR_EL2, x1             /* HCR_EL3.RW = 0b1 */

        mov     x1, #0b0000             /* Setup SPRS_EL3 to be "AArch64 with SP_EL0t" */
        msr     SPSR_EL3, x1

        msr     ELR_EL3, x0             /* x0 is the entry point and argument to the function */

        eret


        .global CSL_a53v8SwitchLevelEl3toSEl0
        .type   CSL_a53v8SwitchLevelEl3toSEl0, %function
CSL_a53v8SwitchLevelEl3toSEl0:
        msr     SCTLR_EL1, xzr          /*Initialize SCTRL_EL2 to safe values */

        mov     x1, #0x400              /* EL2 is AArch64 */
        msr     SCR_EL3, x1             /* SCR_EL3.RW = .NS = 0b1 */

        mov     x1, #0x80000000              /* EL1 is AArch64 */
        msr     HCR_EL2, x1             /* HCR_EL3.RW = 0b1 */

        mov     x1, #0b0000             /* Setup SPRS_EL3 to be "AArch64 with SP_EL0t" */
        msr     SPSR_EL3, x1

        msr     ELR_EL3, x0             /* x0 is the entry point and argument to the function */

        eret




        .global CSL_a53v8SwitchLeveltoEl3
        .type   CSL_a53v8SwitchLeveltoEl3, %function
CSL_a53v8SwitchLeveltoEl3:

        smc     #0                      /* Secure Monitor Call causes exception at EL3 */
        ret

        .global CSL_a53v8SwitchLevelEl0toEl3
        .type   CSL_a53v8SwitchLevelEl0toEl3, %function
CSL_a53v8SwitchLevelEl0toEl3:

        svc     #0                      /* Supervisor Call causes exception at EL1 */
        smc     #0                      /* Secure Monitor Call causes exception at EL3 */
        ret



        .global CSL_a53v8SwitchLeveltoEl2
        .type  CSL_a53v8SwitchLeveltoEl2 , %function
CSL_a53v8SwitchLeveltoEl2:

        hvc     #0
        ret




        .global CSL_a53v8GetCurrentEl
        .type   CSL_a53v8GetCurrentEl, %function
CSL_a53v8GetCurrentEl:

        mrs x0, CurrentEL
        ret

        .global CSL_a53v8ArmGicv3Init
        .type CSL_a53v8ArmGicv3Init, %function
CSL_a53v8ArmGicv3Init:
        msr     vbar_el1, x0         /* Set vector table base address */
        ret

        .global CSL_a53v8ArmGicv3HwiDisable
        .type   CSL_a53v8ArmGicv3HwiDisable, %function
CSL_a53v8ArmGicv3HwiDisable:
         mrs x0, daif
         msr daifset, #2
         ret

        .global CSL_a53v8ArmGicv3HwiEnable
        .type   CSL_a53v8ArmGicv3HwiEnable, %function
CSL_a53v8ArmGicv3HwiEnable:
         mrs x0, daif
         msr daifclr, #2
         ret

        .global CSL_a53v8ArmGicv3HwiRestore
        .type   CSL_a53v8ArmGicv3HwiRestore, %function
CSL_a53v8ArmGicv3HwiRestore:
         and x2, x0, #128
         mrs x1, daif
         bic x1, x1, #128
         orr x1, x1, x2
         msr daif, x1
         ret

        .global CSL_a53SetPriorityMask
        .type   CSL_a53SetPriorityMask, %function
CSL_a53SetPriorityMask:
        MSR   S3_0_c4_c6_0, x0
	    ret
.end
