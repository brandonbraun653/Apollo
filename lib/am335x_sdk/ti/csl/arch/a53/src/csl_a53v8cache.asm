    /**
    *  @file csl_armcache64.s
    *
    *  @brief
    *     ARM Cache Maintainence Operations
    *  \par
    *   ================================================================================
    *
    *   @n   (C)  Copyright 2015 Texas Instruments Incorporated
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



    .section armcache64, "a", %progbits
    /*Non-Shared or Non-Cached */
    .equ Device_nGnRnE,               0x00
    .equ OuterWTnWA__InnerWTnWA,      0x22
    .equ OuterNC__InnerNC,            0x44

    /*Shared and Cached */
    .equ OuterWBWA__InnerWBWA,        0x55
    .equ OuterWBnWA__InnerWBnWA,      0x66
    .equ OuterWBRWA__InnerWBRWA,      0x77

    .equ OuterWBWAnT__InnerWBWAnT,    0xdd

    .equ OuterWBnWAnT__InnerWBnWAnT,    0xee

    .equ AttrIndx64_0, Device_nGnRnE
    .equ AttrIndx64_1, OuterWTnWA__InnerWTnWA
    .equ AttrIndx64_2, OuterNC__InnerNC
    .equ AttrIndx64_3, OuterWBWA__InnerWBWA
    .equ AttrIndx64_4, OuterWBnWA__InnerWBnWA
    .equ AttrIndx64_5, OuterWBRWA__InnerWBRWA
    .equ AttrIndx64_6, OuterWBWAnT__InnerWBWAnT
    .equ AttrIndx64_7, OuterWBnWAnT__InnerWBnWAnT


    /* */
    /* Instruction Enable/Disable SCTLR */
    /* */
    .global CSL_a53v8EnableInstEl1
    .type   CSL_a53v8EnableInstEl1, %function
CSL_a53v8EnableInstEl1:
    MRS x0, SCTLR_EL1 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<12)
    MSR SCTLR_EL1, x0
    RET

    .global CSL_a53v8EnableInstEl2
    .type    CSL_a53v8EnableInstEl2, %function
CSL_a53v8EnableInstEl2:
    MRS x0, SCTLR_EL2 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<12)
    MSR SCTLR_EL2, x0
    RET

    .global CSL_a53v8EnableInstEl3
    .type    CSL_a53v8EnableInstEl3, %function
CSL_a53v8EnableInstEl3:
    MRS x0, SCTLR_EL3 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<12)
    MSR SCTLR_EL3, x0
    RET

    .global CSL_a53v8DisableInstEl1
    .type    CSL_a53v8DisableInstEl1, %function
CSL_a53v8DisableInstEl1:
    MRS x0, SCTLR_EL1 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<12)
    MSR SCTLR_EL1, x0
    RET

    .global CSL_a53v8DisableInstEl2
    .type    CSL_a53v8DisableInstEl2, %function
CSL_a53v8DisableInstEl2:
    MRS x0, SCTLR_EL2 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<12)
    MSR SCTLR_EL2, x0
    RET

    .global CSL_a53v8DisableInstEl3
    .type    CSL_a53v8DisableInstEl3, %function
CSL_a53v8DisableInstEl3:
    MRS x0, SCTLR_EL3 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<12)
    MSR SCTLR_EL3, x0
    RET


    /* */
    /* Cache Enable/Disable SCTLR */
    /* */
    .global CSL_a53v8EnableDcacheEl1
    .type   CSL_a53v8EnableDcacheEl1, %function
CSL_a53v8EnableDcacheEl1:
    MRS x0, SCTLR_EL1 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<2)
    MSR SCTLR_EL1, x0
    RET

    .global CSL_a53v8EnableDcacheEl2
    .type   CSL_a53v8EnableDcacheEl2, %function
CSL_a53v8EnableDcacheEl2:
    MRS x0, SCTLR_EL2 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<2)
    MSR SCTLR_EL2, x0
    RET

    .global CSL_a53v8EnableDcacheEl3
    .type   CSL_a53v8EnableDcacheEl3, %function
CSL_a53v8EnableDcacheEl3:
    MRS x0, SCTLR_EL3 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<2)
    MSR SCTLR_EL3, x0
    RET

    .global CSL_a53v8DisableDcacheEl1
    .type   CSL_a53v8DisableDcacheEl1, %function
CSL_a53v8DisableDcacheEl1:
    MRS x0, SCTLR_EL1 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<2)
    MSR SCTLR_EL1, x0
    RET

    .global CSL_a53v8DisableDcacheEl2
    .type   CSL_a53v8DisableDcacheEl2, %function
CSL_a53v8DisableDcacheEl2:
    MRS x0, SCTLR_EL2 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<2)
    MSR SCTLR_EL2, x0
    RET

    .global CSL_a53v8DisableDcacheEl3
    .type   CSL_a53v8DisableDcacheEl3, %function
CSL_a53v8DisableDcacheEl3:
    MRS x0, SCTLR_EL3 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<2)
    MSR SCTLR_EL3, x0
    RET

    /* */
    /* MMU Enable/Disable SCTLR */
    /* */
    .global CSL_a53v8EnableMmuEl1
    .type   CSL_a53v8EnableMmuEl1, %function
CSL_a53v8EnableMmuEl1:
    MRS x0, SCTLR_EL1 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<0)
    MSR SCTLR_EL1, x0
    RET

    .global CSL_a53v8EnableMmuEl2
    .type   CSL_a53v8EnableMmuEl2, %function
CSL_a53v8EnableMmuEl2:
    MRS x0, SCTLR_EL2 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<0)
    MSR SCTLR_EL2, x0
    RET

    .global CSL_a53v8EnableMmuEl3
    .type   CSL_a53v8EnableMmuEl3, %function
CSL_a53v8EnableMmuEl3:
    MRS x0, SCTLR_EL3 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1<<0)
    MSR SCTLR_EL3, x0
    RET

    .global CSL_a53v8DisableMmuEl1
    .type   CSL_a53v8DisableMmuEl1, %function
CSL_a53v8DisableMmuEl1:
    MRS x0, SCTLR_EL1 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<0)
    MSR SCTLR_EL1, x0
    RET

    .global CSL_a53v8DisableMmuEl2
    .type   CSL_a53v8DisableMmuEl2, %function
CSL_a53v8DisableMmuEl2:
    MRS x0, SCTLR_EL2 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<0)
    MSR SCTLR_EL2, x0
    RET

    .global CSL_a53v8DisableMmuEl3
    .type   CSL_a53v8DisableMmuEl3, %function
CSL_a53v8DisableMmuEl3:
    MRS x0, SCTLR_EL3 /* Read SCTLR into x0 */
    BIC x0, x0, #(0x1<<0)
    MSR SCTLR_EL3, x0
    RET

    .global CSL_a53v8DisableDataCoherency
    .type   CSL_a53v8DisableDataCoherency, %function
CSL_a53v8DisableDataCoherency:
    MRS x0, S3_1_c15_c2_1; /* CPUECTLR_EL1 */
    BIC x0, x0, #(0x1<<7)
    MSR S3_1_c15_c2_1, x0 /* CPUECTLR_EL1 */
    RET


    .global CSL_a53v8EnableDataCoherency
    .type   CSL_a53v8EnableDataCoherency, %function
CSL_a53v8EnableDataCoherency:
    MRS x0, S3_1_c15_c2_1; /* CPUECTLR_EL1 */
    ORR x0, x0, #(0x1<<6)
    MSR S3_1_c15_c2_1, x0 /* CPUECTLR_EL1 */
    RET


    .global CSL_a53v8CleanInvalidateDcacheSetWay
    .type   CSL_a53v8CleanInvalidateDcacheSetWay, %function
CSL_a53v8CleanInvalidateDcacheSetWay:
    DC      CISW, X0
    ISB
    RET


    .global CSL_a53v8CleanInvalidateDcacheMvaPoC
    .type   CSL_a53v8CleanInvalidateDcacheMvaPoC, %function
CSL_a53v8CleanInvalidateDcacheMvaPoC:
    DC      CIVAC, X0
    ISB
    RET


    .global CSL_a53v8CleanDcacheSetWay
    .type   CSL_a53v8CleanDcacheSetWay, %function
CSL_a53v8CleanDcacheSetWay:
    DC      CSW, X0
    ISB
    RET


    .global CSL_a53v8CleanDcacheMvaPoC
    .type   CSL_a53v8CleanDcacheMvaPoC, %function
CSL_a53v8CleanDcacheMvaPoC:
    DC      CVAC, X0
    ISB
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8CleanDcacheMvaPoU
    .type   CSL_a53v8CleanDcacheMvaPoU, %function
CSL_a53v8CleanDcacheMvaPoU:
    DC      CVAU, X0
    ISB
    BR  X30       ; /*Return to caller */

    .global CSL_a53v8InvalidateDcacheSetWay
    .type   CSL_a53v8InvalidateDcacheSetWay, %function
CSL_a53v8InvalidateDcacheSetWay:
    DC      ISW, X0
    ISB
    RET


    .global CSL_a53v8InvalidateDcacheMvaPoC
    .type   CSL_a53v8InvalidateDcacheMvaPoC, %function
CSL_a53v8InvalidateDcacheMvaPoC:
    DC      IVAC, X0
    ISB
    RET


    .global CSL_a53v8zeroDcaheMva
    .type   CSL_a53v8zeroDcaheMva, %function
CSL_a53v8ZeroDcaheMva:
    DC      ZVA, X0
    ISB
    RET


    .global CSL_a53v8InvalidateIcacheAllPoU
    .type   CSL_a53v8InvalidateIcacheAllPoU, %function
CSL_a53v8InvalidateIcacheAllPoU:
    IC      IALLU
    ISB
    RET


    .global CSL_a53v8InvalidateIcacheAllPoUIs
    .type   CSL_a53v8InvalidateIcacheAllPoUIs, %function
CSL_a53v8InvalidateIcacheAllPoUIs:
    IC      IALLUIS
    ISB
    RET


    .global CSL_a53v8InvalidateIcacheMvaPoU
    .type   CSL_a53v8InvalidateIcacheMvaPoU, %function
CSL_a53v8InvalidateIcacheMvaPoU:
    IC      IVAU, X0
    ISB
    RET


    .global CSL_a53v8InvalidateDcache
    .type   CSL_a53v8InvalidateDcache, %function
CSL_a53v8InvalidateDcache:
       MRS X3, CLIDR_EL1
       MOV W10, W0              /* W10 = 2 x cache level */
       MOV W8, #1               /* W8 = constant 0b1 */
       ADD W2, W10, W10, LSR #1 /* Calculate 3 x cache level */
       LSR W1, W3, W2           /* extract 3-bit cache type for this level */
       AND W1, W1, #0x7
       CMP W1, #2
       B.LT Finished                /* No data or unified cache at this level */
       MSR CSSELR_EL1, X10      /* Select this cache level */
       ISB                      /* Synchronize change of CSSELR */
       MRS X1, CCSIDR_EL1       /* Read CCSIDR */
       AND W2, W1, #7           /* W2 = log2(linelen)-4 */
       ADD W2, W2, #4           /* W2 = log2(linelen) */
       UBFX W4, W1, #3, #10     /* W4 = max way number, right aligned */
       CLZ W5, W4               /* W5 = 32-log2(ways), bit position of way in DC                                                           operand */
       LSL W9, W4, W5           /* W9 = max way number, aligned to position in DC
                                   operand */
       LSL W16, W8, W5          /* W16 = amount to decrement way number per iteration */
Loop2: UBFX W7, W1, #13, #15    /* W7 = max set number, right aligned */
       LSL W7, W7, W2           /* W7 = max set number, aligned to position in DC
                                   operand */
       LSL W17, W8, W2          /* W17 = amount to decrement set number per iteration */
Loop3: ORR W11, W10, W9         /* W11 = combine way number and cache number... */
       ORR W11, W11, W7         /* ... and set number for DC operand */
       DC CSW, X11              /* Do data cache clean by set and way */
       SUBS W7, W7, W17         /* Decrement set number */
       B.GE Loop3
       SUBS X9, X9, X16         /* Decrement way number */
       B.GE Loop2
       DSB SY                      /* Ensure completion of cache maintenance operation */
Finished:
       BR  X30       ; /*Return to caller */



    .global CSL_a53v8InitIDCacheMmuEl1          /* enable the instr&data cache and mmu for EL1 */
    .type   CSL_a53v8InitIDCacheMmuEl1, %function
CSL_a53v8InitIDCacheMmuEl1:
       ldr w20, =0xCAFEBA22
       mrs x0, sctlr_el1 /* Read SCTLR into x0 */
       orr x0, x0, #(0x1<<2)
       orr x0, x0, #(0x1<<12)
       orr x0, x0, #0x1
       msr sctlr_el1, x0
       DSB SY
       ISB SY

       ldr w20, =0xCAFEBA33
       ret
    .balign 16




    .global CSL_a53v8InitIDCacheMmuEl2          /* enable the instr&data cache and mmu for EL2 */
    .type   CSL_a53v8InitIDCacheMmuEl2, %function
CSL_a53v8InitIDCacheMmuEl2:
    ldr w20, =0xCAFEBA22
    mrs x0, sctlr_el2 /* Read SCTLR into x0 */
    orr x0, x0, #(0x1<<2)
    orr x0, x0, #(0x1<<12)
    orr x0, x0, #0x1
    msr sctlr_el2, x0
    DSB SY
    ISB SY

    ldr w20, =0xCAFEBA33
    ret
    .balign 16




    .global CSL_a53v8InitIDCacheMmuEl3          /* enable the instr&data cache and mmu for EL3 */
    .type   CSL_a53v8InitIDCacheMmuEl3, %function
CSL_a53v8InitIDCacheMmuEl3:
    ldr w20, =0xCAFEBA22
    mrs x0, sctlr_el3 /* Read SCTLR into x0 */
    orr x0, x0, #(0x1<<2)
    orr x0, x0, #(0x1<<12)
    orr x0, x0, #0x1
    msr sctlr_el3, x0
    DSB SY
    ISB SY

    ldr w20, =0xCAFEBA33
    ret
    .balign 16


    .global CSL_a53v8EnableMairEl3
    .type   CSL_a53v8EnableMairEl3, %function
    .extern TTBR3_BASE_ADDR

CSL_a53v8EnableMairEl3:
    ldr w20, =0xCAFEBA11
    mrs x0, ttbr0_el3
    ldr x0, =TTBR3_BASE_ADDR
    msr     ttbr0_el3, x0;
    mrs x0, mair_el3 /* Read MAIR_EL3 into x0 */
    ldr x0, =(AttrIndx64_7<<56 | AttrIndx64_6<<48 | AttrIndx64_5<<40 | AttrIndx64_4<<32 | AttrIndx64_3<<24 | AttrIndx64_2<<16 | AttrIndx64_1<<8 | AttrIndx64_0<<0)
    msr mair_el3, x0
    ldr     w1, =0x80823518  /* 40 bit address space. T0SZ=0x18 */
    msr     TCR_EL3, x1
    ret
    .balign 16

    .global CSL_a53v8EnableMairEl2
    .type   CSL_a53v8EnableMairEl2, %function
    .extern TTBR2_BASE_ADDR


CSL_a53v8EnableMairEl2:
    ldr w20, =0xCAFEBA11
    mrs x0, ttbr0_el2
    ldr x0, =TTBR2_BASE_ADDR
    msr     ttbr0_el2, x0;
    mrs x0, mair_el2 /* Read MAIR_EL2 into x0 */
    ldr x0, =(AttrIndx64_7<<56 | AttrIndx64_6<<48 | AttrIndx64_5<<40 | AttrIndx64_4<<32 | AttrIndx64_3<<24 | AttrIndx64_2<<16 | AttrIndx64_1<<8 | AttrIndx64_0<<0)
    msr mair_el2, x0
    ldr     w1, =0x80823518  /* 40 bit address space. T0SZ=0x18 */
    msr     TCR_EL2, x1
    ret
    .balign 16


    .global CSL_a53v8EnableMairEl1
    .type   CSL_a53v8EnableMairEl1, %function
    .extern TTBR1_BASE_ADDR


CSL_a53v8EnableMairEl1:
    ldr w20, =0xCAFEBA11
    mrs x0, ttbr0_el1
    ldr x0, =TTBR1_BASE_ADDR
    msr     ttbr0_el1, x0;
    mrs x0, mair_el1 /* Read MAIR_EL1 into x0 */
    ldr x0, =(AttrIndx64_7<<56 | AttrIndx64_6<<48 | AttrIndx64_5<<40 | AttrIndx64_4<<32 | AttrIndx64_3<<24 | AttrIndx64_2<<16 | AttrIndx64_1<<8 | AttrIndx64_0<<0)
    msr mair_el1, x0
    ldr     w1, =0x80823518  /* 40 bit address space. T0SZ=0x18 */
    msr     TCR_EL1, x1
    ret
    .balign 16



    .global CSL_a53v8EnableCpuEctrlEl1
    .type CSL_a53v8EnableCpuEctrlEl1, %function

CSL_a53v8EnableCpuEctrlEl1:
    ldr w20, =0xCAFEBA77
    mrs x0, S3_1_C15_C2_1 /* Read CPUECTLR into x0 */
    orr x0, x0, #(0x1<<6)
    msr S3_1_C15_C2_1, x0
    DSB SY
    ISB SY

    ldr w20, =0xCAFEBA88
    ret
    .balign 16



    /*Functions for Cache controlling cache levels and modes */

    .global CSL_a53v8GetCacheLevelId
    .type CSL_a53v8GetCacheLevelId, %function
CSL_a53v8GetCacheLevelId:
    mrs x0, CLIDR_EL1           /*read CLIDR_EL1 into x0 */
    and x0, x0, #0x00000000ffffffff
    ret
    .balign 16


    .global  CSL_a53v8SetCacheLevelInD
    .type  CSL_a53v8SetCacheLevelInD, %function
CSL_a53v8SetCacheLevelInD:
    msr CSSELR_EL1, x0
    ret
    .balign 16

    .global CSL_a53v8GetCacheLevelInD
    .type CSL_a53v8GetCacheLevelInD, %function
CSL_a53v8GetCacheLevelInD:
    mrs x0, CSSELR_EL1
    ret
    .balign 16


    .global CSL_a53v8GetCurrentCacheSize
    .type CSL_a53v8GetCurrentCacheSize, %function
CSL_a53v8GetCurrentCacheSize:
    mrs x0, CCSIDR_EL1
    ret
    .balign 16


    .global CSL_a53v8findNumLeadZeros
    .type CSL_a53v8findNumLeadZeros, %function
CSL_a53v8FindNumLeadZeros:
    CLZ x0,x0
    ret
    .balign 16



    /* */
    /* set TCR */
    /* */
    .global CSL_a53v8WriteTCREL1
    .type CSL_a53v8WriteTCREL1, %function
CSL_a53v8WriteTCREL1:
    MSR TCR_EL1, x0
    RET
    .balign 16

	.global CSL_a53v8WriteTCREL3
    .type CSL_a53v8WriteTCREL3, %function
CSL_a53v8WriteTCREL3:
    MSR TCR_EL3, x0
    RET
    .balign 16

    /* */
    /* MMU Enable SCTLR */
    /* */
    .global CSL_a53v8EnableMMUEl1
    .type CSL_a53v8EnableMMUEl1, %function
CSL_a53v8EnableMMUEl1:
    MRS x0, SCTLR_EL1 /* Read SCTLR into x0 */
    ORR x0, x0, #(0x1)
    MSR SCTLR_EL1, x0
    RET
    .balign 16

    .global CSL_a53v8SetMAIR
    .type CSL_a53v8SetMAIR, %function
CSL_a53v8SetMAIR:
    lsl x0, x0, #3
    lslv x1, x1, x0
    movz x2, 0xFF
    lsl  x2, x2, x0
    mrs x0, MAIR_EL1
    bic x0, x0, x2
    orr x0, x0, x1
    msr MAIR_EL1, x0
    ret
    .balign 16

    .global CSL_a53v8InvTLB
    .type CSL_a53v8InvTLB, %function
CSL_a53v8InvTLB:
    tlbi   vmalle1
    dsb    sy
    isb
    ret
    .balign 16

    .global CSL_a53v8SetMAIREL3
    .type CSL_a53v8SetMAIREL3, %function
CSL_a53v8SetMAIREL3:
    lsl x0, x0, #3
    lslv x1, x1, x0
    movz x2, 0xFF
    lsl  x2, x2, x0
    mrs x0, MAIR_EL3
    bic x0, x0, x2
    orr x0, x0, x1
    msr MAIR_EL3, x0
    ret
    .balign 16
    .end
