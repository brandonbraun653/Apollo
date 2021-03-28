    /**
    *  @file csl_armcache32.s
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
    */


.section testcode, "ax", %progbits

/*======================================================================================*/
/* SCTLR*/
/*======================================================================================*/

.global CSL_a53v7EnableIcache
.type   CSL_a53v7EnableIcache    , %function
CSL_a53v7EnableIcache:
    MRC p15, 0, r0, c1, c0, 0
    ORR r0, r0, #(0x1<<12)
    MCR p15, 0, r0, c1, c0, 0

.global CSL_a53v7DisableIcache
.type   CSL_a53v7DisableIcache    , %function
CSL_a53v7DisableIcache:
    MRC p15, 0, r0, c1, c0, 0
    BIC r0, r0, #(0x1<<12)
    MCR p15, 0, r0, c1, c0, 0

.global CSL_a53v7EnableDcache
.type   CSL_a53v7EnableDcache     , %function
CSL_a53v7EnableDcache:
    MRC p15, 0, r0, c1, c0, 0
    ORR r0, r0, #(0x1<<2)
    MCR p15, 0, r0, c1, c0, 0

.global CSL_a53v7DisableDcache
.type   CSL_a53v7DisableDcache, %function
CSL_a53v7DisableDcache:
    MRC p15, 0, r0, c1, c0, 0
    BIC r0, r0, #(0x1<<2)
    MCR p15, 0, r0, c1, c0, 0

.global CSL_a53v7EnableMmu
.type   CSL_a53v7EnableMmu, %function
CSL_a53v7Enable_Mmu:
    MRC p15, 0, r0, c1, c0, 0
    ORR r0, r0, #(0x1<<0)
    MCR p15, 0, r0, c1, c0, 0

.global CSL_a53v7DisableMmu
.type   CSL_a53v7DisableMmu, %function
CSL_a53v7DisableMmu:
    MRC p15, 0, r0, c1, c0, 0
    BIC r0, r0, #(0x1<<0)
    MCR p15, 0, r0, c1, c0, 0

/*======================================================================================*/
/* HSCTLR*/
/*======================================================================================*/
.global CSL_a53v7EnableIcacheH
.type   CSL_a53v7EnableIcahceH, %function
CSL_a53v7EnableIcacheH:
    MRC p15, 4, r0, c1, c0, 0
    ORR r0, r0, #(0x1<<12)
    MCR p15, 4, r0, c1, c0, 0

.global CSL_a53v7DisableIcacheH
.type   CSL_a53v7DisableIcacheH, %function
CSL_a53v7DisableIcacheH:
    MRC p15, 4, r0, c1, c0, 0
    BIC r0, r0, #(0x1<<12)
    MCR p15, 4, r0, c1, c0, 0

.global CSL_a53v7EnableDcacheH
.type   CSL_a53v7EnableDcacheH, %function
CSL_a53v7EnableDcacheH:
    MRC p15, 4, r0, c1, c0, 0
    ORR r0, r0, #(0x1<<2)
    MCR p15, 4, r0, c1, c0, 0

.global CSL_a53v7DisableDcacheH
.type   CSL_a53v7DisableDcacheH, %function
CSL_a53v7DisableDcacheH:
    MRC p15, 4, r0, c1, c0, 0
    BIC r0, r0, #(0x1<<2)
    MCR p15, 4, r0, c1, c0, 0

.global CSL_a53v7EnableMmuH
.type   CSL_a53v7EnableMmuH, %function
CSL_a53v7EnableMmuH:
    MRC p15, 4, r0, c1, c0, 0
    ORR r0, r0, #(0x1<<0)
    MCR p15, 4, r0, c1, c0, 0

.global CSL_a53v7DisableMmuH
.type   CSL_a53v7DisableMmuH, %function
CSL_a53v7DisableMmuH:
    MRC p15, 4, r0, c1, c0, 0
    BIC r0, r0, #(0x1<<0)
    MCR p15, 4, r0, c1, c0, 0

/*======================================================================================*/
/* Clean L1 data cache line by MVA*/
/*======================================================================================*/
.global CSL_a53v7CleanL1DcacheMva
.type   CSL_a53v7CleanL1DcacheMva, %function
CSL_a53v7CleanL1DcacheMva:
    MCR     p15, 0, r0, c7, c11, 1
    ISB
    BX      lr

/*======================================================================================*/
/* Clean L1 Data cache line by way and set*/
/*======================================================================================*/
.global CSL_a53v7CleanL1DcacheSetWay
.type   CSL_a53v7CleanL1DcacheSetWay, %function
CSL_a53v7CleanL1DcacheSetWay:
    BIC     r0,r0,#0xF
    MCR     p15, 0, r0, c7, c10, 2
    ISB
    BX      lr

    /*See V7 Arch Ref Manual Figure B3-31*/
/*======================================================================================*/
/* Clean Invalidate L1 data cache line by MVA*/
/*======================================================================================*/
.global CSL_a53v7CleanInvalidateL1DcacheMva
.type   CSL_a53v7CleanInvalidateL1DcacheMva, %function
CSL_a53v7CleanInvalidateL1DcacheMva:
    MCR     p15, 0, r0, c7, c14, 1
       ISB
    BX LR

/*======================================================================================*/
/* Clean Invalidate L1 data cahces by set and way*/
/*======================================================================================*/
.global CSL_a53v7CleanInvalidateL1DcacheSetWay
.type   CSL_a53v7CleanInvalidateL1DcacheSetWay, %function
CSL_a53v7CleanInvalidateL1DcacheSetWay:
    BIC     r0,r0,#0xF
    MCR     p15, 0, r0, c7, c14, 2
    ISB
    BX      lr

/*======================================================================================*/
/* Clean L1 and L2 data caches line by mva*/
/*======================================================================================*/
.global CSL_a53v7CleanL1L2DcacheMva
.type   CSL_a53v7CleanL1L2DcacheMva, %function
CSL_a53v7CleanL1L2DcacheMva:
    MCR    p15, 0, r0, c7, c10, 1
    ISB
    BX     lr

/*======================================================================================*/
/* Clean L1 and L2 data caches line by set and way*/
/*======================================================================================*/
.global CSL_a53v7CleanL1L2DcacheSetWay
.type   CSL_a53v7CleanL1L2DcacheSetWay, %function
CSL_a53v7CleanL1L2DcacheSetWay:
    BIC     r0,r0,#0xF
    MCR     p15, 0, r0, c7, c10, 2
    ORR     r0,r0,#0x2
    MCR     p15, 0, r0, c7, c10, 2
    ISB
    BX      lr


/*======================================================================================*/
/* Clean Invalidate L1 and L2 data cache line by mva*/
/*======================================================================================*/
.global CSL_a53v7CleaninvalidateL1L2DcacheMva
.type   CSL_a53v7CleaninvalidateL1L2DcacheMva, %function
CSL_a53v7CleaninvalidateL1L2DcacheMva:
    MCR     p15, 0, r0, c7, c14, 1
    ISB
    BX      lr

/*======================================================================================*/
/* Clean Invalidate L1 and L2 data cache line by set and way*/
/*======================================================================================*/
.global CSL_a53v7CleaninvalidateL1L2DcacheSetWay
.type   CSL_a53v7CleaninvalidateL1L2DcacheSetWay, %function
CSL_a53v7CleaninvalidateL1L2DcacheSetWay:
    BIC     r0,r0,#0xF
    MCR     p15, 0, r0, c7, c14, 2
    ORR     r0,r0,#0x2
    MCR     p15, 0, r0, c7, c14, 2
    ISB
    BX      lr

/*======================================================================================*/
/* Clean Invalidate L2 data caches line by set and way*/
/*======================================================================================*/
.global CSL_a53v7CleaninvalidateL2DcacheSetWay
.type   CSL_a53v7CleaninvalidateL2DcacheSetWay, %function
CSL_a53v7CleaninvalidateL2DcacheLineSetWay:
    ORR     r0,r0,#0x2
    MCR     p15, 0, r0, c7, c14, 2
    ISB
    BX      lr

/*======================================================================================*/
/* Invalidate I-Cache by MVA*/
/*======================================================================================*/
.global CSL_a53v7IvalidateIcacheMva
.type   CSL_a53v7IvalidateIcacheMva, %function
CSL_a53v7IvalidateIcacheMva:
    MCR     p15, 0, r0, c7, c5, 1
    ISB
    BX      lr

/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
