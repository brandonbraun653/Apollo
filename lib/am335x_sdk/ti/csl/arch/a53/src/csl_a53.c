 /**
    *  @file csl_a53.c
    *
    *  @brief
    *     Generic Data Barrier Operations
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

#include "csl_a53.h"
#if defined (SOC_AM65XX)
#include "soc/am65xx/dmsc/csl_soc_firewalls.h"
#endif

#ifdef CSL_A53_AARCH64
#include "csl_a53v8cache.h"
#include "csl_a53v8misc.h"
#include "csl_a53v8func.h"
#endif
#ifdef CSL_A53_AARCH32
#include "csl_a53v7cache.h"
#endif



/*/////////////////////////////////////////////////////////////////////////// */
/*  Data Cache Enable and Disable Operations */
/*////////////////////////////////////////////////////////////////////////// */



void CSL_a53DisableDcacheEl3()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DisableDcacheEl3();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_disableDcacheH();
#endif
     CSL_a53Isb();
}


void CSL_a53DisableDcacheEl2()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8DisableDcacheEl2();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_disableDcache();
#endif
     CSL_a53Isb();
}

void CSL_a53DisableDcacheEl1()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8DisableDcacheEl1();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_disableDcache();
#endif
     CSL_a53Isb();
}



void CSL_a53DisableDcacheAllLev()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8DisableDcacheEl3();
     CSL_a53v8DisableDcacheEl2();
     CSL_a53v8DisableDcacheEl1();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_disableDcacheH();
     CSL_ARMCACHE32_disableDcache();
#endif
     CSL_a53Isb();
}



void CSL_a53EnableDcacheEl3()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8EnableDcacheEl3();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_enableDcacheH();
#endif
     CSL_a53Isb();
     return;
}


void CSL_a53EnableDcacheEl2()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8EnableDcacheEl2();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_enableDcache();
#endif
     CSL_a53Isb();
}


void CSL_a53EnableDcacheEl1()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8EnableDcacheEl1();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_enableDcache();
#endif
     CSL_a53Isb();
}

void CSL_a53EnableDcacheAllLev()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8EnableDcacheEl3();
     CSL_a53v8EnableDcacheEl2();
     CSL_a53v8EnableDcacheEl1();
#endif
#ifdef CSL_A53_AARCH32
     CSL_ARMCACHE32_enableDcacheH();
     CSL_ARMCACHE32_enableDcache();
#endif
    CSL_a53Isb();
}


/*/////////////////////////////////////////////////////////////////////////// */
/*/  Instruction Cache Enable and Disable Operations */
/*////////////////////////////////////////////////////////////////////////// */





 void CSL_a53EnableIcacheEl3()
 {
#ifdef CSL_A53_AARCH64
    CSL_a53v8EnableInstEl3();
#endif
#ifdef CSL_A53_AARCH32
    CSL_ARMCACHE32_enableIcacheH();
#endif

    CSL_a53Isb();
}


 void CSL_a53EnableIcacheEl2()
 {
#ifdef CSL_A53_AARCH64
    CSL_a53v8EnableInstEl2();
#endif
#ifdef CSL_A53_AARCH32
    CSL_ARMCACHE32_enableIcache();
#endif

    CSL_a53Isb();
}


 void CSL_a53EnableIcacheEl1()
 {
#ifdef CSL_A53_AARCH64
    CSL_a53v8EnableInstEl1();
#endif
#ifdef CSL_A53_AARCH32
    CSL_ARMCACHE32_enableIcache();
#endif

    CSL_a53Isb();
}


 void CSL_a53EnableIcacheAllLev()
 {
#ifdef CSL_A53_AARCH64
    CSL_a53v8EnableInstEl3();
    CSL_a53v8EnableInstEl2();
    CSL_a53v8EnableInstEl1();
#endif
#ifdef CSL_A53_AARCH32
    CSL_ARMCACHE32_enableIcacheH();
    CSL_ARMCACHE32_enableIcache();
#endif

    CSL_a53Isb();
}

 void CSL_a53DisableDataCoherency()
 {
#ifdef CSL_A53_AARCH64
    CSL_a53v8DisableDataCoherency();
#endif

    CSL_a53Isb();
}


/*////////////////////////////////////////////////////////////////////////// */
/* Data Cache Clean and Invalidate Operations */
/*////////////////////////////////////////////////////////////////////////// */


void CSL_a53CleanInvalidateL1DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;
    LevelInD = 0x00000000U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    /*    CSL_a53v8CleaninvalidateDcacheSetWay(setway); */
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL1DcacheSetWay(); */
#endif

    CSL_a53Isb();

}

void CSL_a53CleanInvalidateL2DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;
    LevelInD = 0x00000002U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    /*    CSL_a53v8CleaninvalidateDcacheSetWay(setway); */
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL2DcacheSetWay(); */
#endif

    CSL_a53Isb();

}

void CSL_a53CleanInvalidateL1L2DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;

    /*set current cache to L1 */
    LevelInD = 0x00000000U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    /*    CSL_a53v8CleaninvalidateDcacheSetWay(setway); */
    CSL_a53Isb();
    /*set current cache to L2 */
    LevelInD = 0x00000002U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    /*    CSL_a53v8CleaninvalidateDcacheSetWay(setway); */
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL1L2DcacheSetWay(); */
#endif

    CSL_a53Isb();

}


void CSL_a53CleanL1DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;
    LevelInD = 0x00000000U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    CSL_a53v8CleanDcacheSetWay(setway);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleanL1DcacheSetWay(); */
#endif

    CSL_a53Isb();

}

void CSL_a53CleanL2DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;
    LevelInD = 0x00000002U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    CSL_a53v8CleanDcacheSetWay(setway);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleanL2DcacheSetWay(); */
#endif

    CSL_a53Isb();

}

void CSL_a53CleanL1L2DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;

    /*set current cache to L1 */
    LevelInD = 0x00000000U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    /*    CSL_a53v8CleaninvalidateDcacheSetWay(setway); */
    CSL_a53Isb();
    /*set current cache to L2 */
    LevelInD = 0x00000002U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    /*    CSL_a53v8CleaninvalidateDcacheSetWay(setway); */
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL1L2DcacheSetWay(); */
#endif

    CSL_a53Isb();

}





void CSL_a53InvalidateL1DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;
    LevelInD = 0x00000000U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    CSL_a53v8InvalidateDcacheSetWay(setway);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL1DcacheSetWay(); */
#endif

    CSL_a53Isb();

}

void CSL_a53InvalidateL2DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;
    LevelInD = 0x00000002U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    CSL_a53v8InvalidateDcacheSetWay(setway);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL2DcacheSetWay(); */
#endif

    CSL_a53Isb();

}

void CSL_a53InvalidateL1L2DcacheSetWay(uint64_t setway)
{
#ifdef CSL_A53_AARCH64
    uint32_t    LevelInD;

    /*set current cache to L1 */
    LevelInD = 0x00000000U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    CSL_a53v8InvalidateDcacheSetWay(setway);
    CSL_a53Isb();
    /*set current cache to L2 */
    LevelInD = 0x00000002U;        /*3:1 = Level 0 = InD */
    CSL_a53v8SetCacheLevelInD(LevelInD);
    CSL_a53Isb();
    CSL_a53v8InvalidateDcacheSetWay(setway);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL1L2DcacheSetWay(); */
#endif

    CSL_a53Isb();

}



void CSL_a53CleanInvalidateDcacheMvaPoC(uint64_t mva)
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8CleanInvalidateDcacheMvaPoC(mva);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL1L2DcacheMva(mva); */
#endif
    CSL_a53Isb();
}



void CSL_a53InvalidateDcacheMvaPoC(uint64_t mva)
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8InvalidateDcacheMvaPoC(mva);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleaninvalidateL1L2DcacheMva(mva); */
#endif
    CSL_a53Isb();
}



void CSL_a53CleanDcacheMvaPoC(uint64_t mva)
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8CleanDcacheMvaPoC(mva);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleanL1DcacheMva(mva); */
#endif
    CSL_a53Isb();
}



void CSL_a53CleanDcacheMvaPoU(uint64_t mva)
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8CleanDcacheMvaPoU(mva);
#endif
#ifdef CSL_A53_AARCH32
    /*    CSL_ARMCACHE32_cleanL1DcacheMva(mva); */
#endif
    CSL_a53Isb();
}


void CSL_a53InvalidateL2Cache()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8InvalidateDcache(0x2);
#endif
    CSL_a53Isb();
}

void CSL_a53InvalidateL1DCache()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8InvalidateDcache(0x1);
#endif
  CSL_a53Isb();
}



/*////////////////////////////////////////////////////////////////////////////////////*/
/*                          BARRIERS                                                  */
/*////////////////////////////////////////////////////////////////////////////////////*/

void CSL_a53Isb()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8Isb();
#endif
#ifdef CSL_A53_AARCH32
    //    CSL_ARM32MISC_Isb();
#endif

}

void CSL_a53DmIshLdS()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DmbIsHld();
#endif
#ifdef CSL_A53_AARCH32
    //    CSL_ARM32MISC_DmbIsH();
#endif

}


void CSL_a53DmOshLdS()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DmbOsHld();
#endif
#ifdef CSL_A53_AARCH32
    //    CSL_ARM32MISC_DsbOsH();
#endif

}

void CSL_a53DmNshLdS()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DmbNsHld();
#endif

}


void CSL_a53DmLd()
{
#ifdef CSL_A53_AARCH64
     CSL_a53v8DmbLd();
#endif
#ifdef CSL_A53_AARCH32
     //     CSL_ARM32MISC_DmbSy();
#endif
}

void CSL_a53DsIshLd()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DsbIsHld();
#endif
#ifdef CSL_A53_AARCH32
    //    CSL_ARM32MISC_DsbIsH();
#endif
}

void CSL_a53DsOshLd()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DsbOsHld();
#endif

}

void CSL_a53DsNshLd()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DsbNdsHld();
#endif
#ifdef CSL_A53_AARCH32
    //    CSL_ARM32MISC_DsbOsH();
#endif
}

void CSL_a53DsShSyLd()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DsbLd();
#endif
#ifdef CSL_A53_AARCH32
    //    CSL_ARM32MISC_DsbSy();
#endif
}

void CSL_a53DsYLd()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8DsbSy();
#endif
#ifdef CSL_A53_AARCH32
    //    CSL_ARM32MISC_DsbSy();
#endif
}


void CSL_a53WaitFi()
{
#ifdef CSL_A53_AARCH64
    CSL_a53v8WFI();
#endif
}


uint64_t CSL_a53GetCpuId()
{

    uint64_t cpuid;
#ifdef CSL_A53_AARCH64
    cpuid = CSL_a53v8GetCpuId();
#else
    cpuid = 0;   /*temporary until others are available.*/
#endif
    return(cpuid);
}


/*
 *  ======== CSL_cacheDisable ========
 *  This function enables the instructions and data cache
 *  when application enables the cache.
 *
 */
void CSL_cacheDisable(void)
{
    /* Reset CPUECTLR.SMPEN bit to disable data coherency */
    CSL_a53v8DisableDataCoherency();
    CSL_a53v8DisableDcacheEl1();
    CSL_a53v8DisableInstEl1();
}

/*
 *  ======== CSL_cacheEnable ========
 *  This function enables the instructions and data cache
 *  when application enables the cache.
 *
 */
void CSL_cacheEnable(void)
{
    /* Set CPUECTLR.SMPEN bit to enable data coherency */
    CSL_a53v8EnableDataCoherency();
    CSL_a53v8EnableDcacheEl1();
    CSL_a53v8EnableInstEl1();
}

__attribute__((aligned(4096))) uint64_t gCSLa53Mmulevel1Table[CSL_a53Mmu_NUM_LEVEL1_ENTRIES];
__attribute__((aligned(4096))) uint64_t gCSLa53Mmulevel2Table[CSL_a53Mmu_NUM_LEVEL1_ENTRIES];

void CSL_mmuStartup(void)
{
  uint32_t idx;
  uint64_t addr, desc;
  CSL_a53MmuDescAttrs attrs;

  /* Device memory attributes for 0x0 - 0x3FFFFFFF address space */
  attrs.type = CSL_a53Mmu_DescType_BLOCK;
  attrs.nsTable        = FALSE;
  attrs.apTable        = 0u;
  attrs.xnTable        = FALSE;
  attrs.pxnTable       = FALSE;
  attrs.noExecute      = TRUE;
  attrs.privNoExecute  = FALSE;
  attrs.contiguous     = FALSE;
  attrs.notGlobal      = FALSE;
  attrs.accessFlag     = TRUE;
  attrs.shareable      = 0x2; /* Outer shareable */
  attrs.accPerm        = 0x10; /* RW at EL1 only */
  attrs.nonSecure      = TRUE;
  attrs.attrIndx       = 0;
  attrs.reserved       = 0u;

  desc = CSL_mmuInitLevel1Desc(0x0, &attrs);
  gCSLa53Mmulevel1Table[0] = desc;


  /* Table pointer for 0x40000000 - 0x7FFFFFFF address space */
  attrs.type = CSL_a53Mmu_DescType_TABLE;
  attrs.nsTable = FALSE;
  attrs.apTable = 0;
  attrs.xnTable = FALSE;
  attrs.pxnTable = FALSE;

  desc = CSL_mmuInitLevel1Desc((uint64_t)&gCSLa53Mmulevel2Table[0], &attrs);
  gCSLa53Mmulevel1Table[1] = desc;

  /* Normal memory attributes for 0x80000000 - 0xFFFFFFFF address space */
  attrs.type = CSL_a53Mmu_DescType_BLOCK;
  attrs.noExecute = TRUE;
  attrs.privNoExecute = FALSE;
  attrs.contiguous = FALSE;
  attrs.notGlobal = FALSE;
  attrs.accessFlag = TRUE;
  attrs.shareable = 0x2; /* Outer shareable */
  attrs.accPerm = 0x10; /* RW at EL1 only */
  attrs.nonSecure = TRUE;
  attrs.attrIndx = 1;

  desc = CSL_mmuInitLevel1Desc(0x80000000, &attrs);
  gCSLa53Mmulevel1Table[2] = desc;
  desc = CSL_mmuInitLevel1Desc(0xC0000000, &attrs);
  gCSLa53Mmulevel1Table[3] = desc;

  /* Device memory attributes for 0x40000000 - 0x6FFFFFFF address space */
  attrs.type = CSL_a53Mmu_DescType_BLOCK;
  attrs.noExecute = TRUE;
  attrs.privNoExecute = FALSE;
  attrs.contiguous = FALSE;
  attrs.notGlobal = FALSE;
  attrs.accessFlag = TRUE;
  attrs.shareable = 0x2; /* Outer shareable */
  attrs.accPerm = 0x10; /* RW at EL1 only */
  attrs.nonSecure = TRUE;
  attrs.attrIndx = 0;

  /* 1GB for FSS0 OSPI0 */
  desc = CSL_mmuInitLevel1Desc(0x400000000, &attrs);
  gCSLa53Mmulevel1Table[16] = desc;
  /* 1GB for FSS0 OSPI1 */
  desc = CSL_mmuInitLevel1Desc(0x600000000, &attrs);
  gCSLa53Mmulevel1Table[24] = desc;

  /* Map for main ECC Aggr Instance as device memory */
  desc = CSL_mmuInitLevel1Desc(0x4D00000000, &attrs);
  gCSLa53Mmulevel1Table[308] = desc;

  for (idx = 0, addr = 0x40000000; addr < 0x70000000; idx++, addr+=0x200000) {
      desc = CSL_mmuInitLevel2Desc(addr, &attrs);
      gCSLa53Mmulevel2Table[idx] = desc;
  }

  /* Normal memory attributes for 0x70000000 - 0x7FFFFFFF address space */
  attrs.type = CSL_a53Mmu_DescType_BLOCK;
  attrs.noExecute = TRUE;
  attrs.privNoExecute = FALSE;
  attrs.contiguous = FALSE;
  attrs.notGlobal = FALSE;
  attrs.accessFlag = TRUE;
  attrs.shareable = 0x2; /* Outer shareable */
  attrs.accPerm = 0x10; /* RW at EL1 only */
  attrs.nonSecure = TRUE;
  attrs.attrIndx = 1;

  for (; addr < 0x80000000; idx++, addr+=0x200000) {
      desc = CSL_mmuInitLevel2Desc(addr, &attrs);
      gCSLa53Mmulevel2Table[idx] = desc;
  }

  CSL_mmuSetMAIR(0, 0x00);
  CSL_mmuSetMAIR(1, 0xFF);

  CSL_mmuInit((uintptr_t)&gCSLa53Mmulevel1Table[0]);
  CSL_a53v8WriteTCREL1(0x500000019);

  CSL_a53v8InitIDCacheMmuEl1();
}


uint64_t CSL_mmuInitLevel1Desc(uint64_t phyAddr, CSL_a53MmuDescAttrs *attrs)
{
    uint64_t desc;

    if (attrs->type == CSL_a53Mmu_DescType_BLOCK) {
        desc = ((UInt64)attrs->type & 0x3) |
               ((UInt64)(attrs->attrIndx & 0x7) << 2) |
               ((UInt64)(attrs->nonSecure & 0x1) << 5) |
               ((UInt64)(attrs->accPerm & 0x3) << 6) |
               ((UInt64)(attrs->shareable & 0x3) << 8) |
               ((UInt64)(attrs->accessFlag & 0x1) << 10) |
               ((UInt64)(attrs->notGlobal & 0x1) << 11) |
               ((UInt64)phyAddr & 0xFFFFFFFFC0000000) |
               ((UInt64)(attrs->contiguous & 0x1) << 52) |
               ((UInt64)(attrs->privNoExecute & 0x1) << 53) |
               ((UInt64)(attrs->noExecute & 0x1) << 54) |
               ((UInt64)(attrs->reserved & 0xF) << 55);
    }
    else {
        desc = ((UInt64)attrs->type & 0x3) |
               ((UInt64)phyAddr & 0xFFFFFFFFFFFFF000) |
               ((UInt64)(attrs->pxnTable & 0x1) << 59) |
               ((UInt64)(attrs->xnTable & 0x1) << 60) |
               ((UInt64)(attrs->apTable & 0x3) << 61) |
               ((UInt64)(attrs->nsTable & 0x1) << 63);
    }

    return (desc);
}

uint64_t CSL_mmuInitLevel2Desc(uint64_t phyAddr, CSL_a53MmuDescAttrs *attrs)
{
    UInt64 desc;

    if (attrs->type == CSL_a53Mmu_DescType_BLOCK) {
        desc = ((UInt64)attrs->type & 0x3) |
               ((UInt64)(attrs->attrIndx & 0x7) << 2) |
               ((UInt64)(attrs->nonSecure & 0x1) << 5) |
               ((UInt64)(attrs->accPerm & 0x3) << 6) |
               ((UInt64)(attrs->shareable & 0x3) << 8) |
               ((UInt64)(attrs->accessFlag & 0x1) << 10) |
               ((UInt64)(attrs->notGlobal & 0x1) << 11) |
               ((UInt64)phyAddr & 0xFFFFFFFFFFE00000) |
               ((UInt64)(attrs->contiguous & 0x1) << 52) |
               ((UInt64)(attrs->privNoExecute & 0x1) << 53) |
               ((UInt64)(attrs->noExecute & 0x1) << 54) |
               ((UInt64)(attrs->reserved & 0xF) << 55);
    }
    else {
        desc = ((UInt64)attrs->type & 0x3) |
               ((UInt64)phyAddr & 0xFFFFFFFFFFFFF000) |
               ((UInt64)(attrs->pxnTable & 0x1) << 59) |
               ((UInt64)(attrs->xnTable & 0x1) << 60) |
               ((UInt64)(attrs->apTable & 0x3) << 61) |
               ((UInt64)(attrs->nsTable & 0x1) << 63);
    }

    return (desc);
}

void CSL_mmuSetMAIR(uint8_t idx, uint16_t attr)
{
    CSL_a53v8SetMAIR(idx, attr);
    CSL_a53v8InvTLB();
    return;
}

void CSL_mmuInit(uintptr_t tableAddr)
{
    CSL_a53v8WriteTtbr0El1(tableAddr);
    return;
}

void CSL_mmuSetTCR(uint64_t tcr)
{
    CSL_a53v8WriteTCREL1(tcr);
    return;
}

void CSL_enablePmu(void)
{
    __asm   volatile (
        "   mrs     x0, PMCR_EL0        ;"
        "   orr     w0, w0, #1          ;"
        "   msr     PMCR_EL0, x0        ;"      /* enable PMU counters */
        "   isb                         ;"
        );
}

void CSL_initPmu(void)
{
    CSL_enablePmu();
    __asm   volatile (
            "   mrs     x0, PMCR_EL0        ;"
            "   orr     w0, w0, #(1 << 6)   ;"
            "   msr     PMCR_EL0, x0        ;"  /* select long cycle counter */
            "   isb                         ;"
    );
    CSL_resetPmuCycleCounter();
}

void CSL_disablePmu(void)
{
     /* clear E bit */
    __asm   volatile (
            "   mrs        x0, PMCR_EL0        ;"
            "   bfi        w0, wzr, #0, #1     ;"
            "   msr        PMCR_EL0, x0        ;"      /* disable PMU counters */
            "   isb                            ;"
    );
}

void  CSL_startPmuCycleCounter(void)    {

     /*      set C bit */
    __asm    volatile (
            "   mov     w1, #(1 << 31)      ;"
            "   msr     PMCNTENSET_EL0, x1  ;"      /* enable CCNT */
            "   isb                         ;"
    );
}

void    CSL_stopPmuCycleCounter(void)    {

    /*      clear C bit */
    __asm    volatile (
            "   mov     w1, #(1 << 31)      ;"
            "   msr     PMCNTENCLR_EL0, x1  ;"      /* disable CCNT */
            "   isb                         ;"
    );
}

uint64_t   CSL_getPmuCycleCount(void)    {

    register uint64_t i asm ("x0");
    __asm   volatile (
            "   mrs    x0, PMCCNTR_EL0      ;"
            "   isb                         ;"
    );
    return i;
}

/* This functions calculates how long it takes just to start the cycle
 * counter, execute one instruction and then disables it
 */
uint64_t   CSL_getPmuCycleCountOverhead(void)
{
    volatile uint64_t val;
    val = CSL_getPmuCycleCount();
    CSL_startPmuCycleCounter();
    CSL_stopPmuCycleCounter();
    val = CSL_getPmuCycleCount() - val;
    return val;
}

void    CSL_clearPmuCycleCounter(void)
{
    CSL_stopPmuCycleCounter();
    __asm   volatile (
            "   msr     PMCCNTR_EL0, xzr     ;"
    );
}

/*    Input: value to initialize Cycle Counter with
 *    Note: this function disables the cycle counter first
 */
void    CSL_setPmuCycleCounter (uint64_t initVal)
{
    CSL_stopPmuCycleCounter();
    __asm    volatile (
            "    msr        PMCCNTR_EL0, %0     "
               :
               : "r" (initVal)              );
    __asm  volatile ("   isb               ");
}

void    CSL_resetPmuCycleCounter(void)
{
    /*      Set C-bit */
    CSL_stopPmuCycleCounter();
    __asm    volatile (
            "   mrs     x0, PMCR_EL0        ;"
            "   orr     w0, w0, #(1 << 2)   ;"
            "   msr     PMCR_EL0, x0        ;"  /* reset PMCCNTR_EL0 to 0 */
            "   msr     PMCCNTR_EL0, xzr    ;"  /* clear it */
            "   isb                         ;"
    );
}


void    CSL_stopAllPmuCounters(void)
{
    __asm volatile (
            "   mvn     x0, xzr             ;"
            "   msr     PMCNTENCLR_EL0, x0  ;"
            "   isb                         ;"
            );
}

/*     ***** PMU Event Counter APIs *****
 *      Set P-bit
 */
void    CSL_resetPmuEventCounter(void)
{
    CSL_stopAllPmuCounters();
    __asm   volatile (
            "   mrs     x0, PMCR_EL0        ;"
            "   orr     w0, w0, #(1 << 1)   ;"
            "   msr     PMCR_EL0, x0        ;"  /* reset ALL event counters */
            "   isb                         ;"
    );
}

/*        This function uses the ARMv8 Generic Timer Comparator (GTC)
 *        Important: the GTC clock is different than PMU clock.
 *                Function assumes clock set by GEL or DMSC.
 *                Make sure to check freq. used for SoC! (K3M4=200MHz default)
 *  Note:
 *        For K3M4 this register requires a SECURE WRITE so it only works
 *        if A53 is in EL3
 */
void    CSL_initGTC(void)
{
#if defined (SOC_AM65XX)
    volatile uint32_t *gtcRegister = (uint32_t *) CSL_FW_IGTC_R10_MAIN_0_VBUSP_GTC_CFG1_START;
    /*  Enable GTC */
    *gtcRegister = *gtcRegister | CSL_A53_GTC_ENABLE | CSL_A53_GTC_DEBUG_HALT;
#endif
}


/*    Read MPU Timer */
uint64_t   CSL_getGTCcount(void)
{
    register uint64_t val asm ("x0");
    __asm    (
            "    mrs        x0, CNTPCT_EL0            ;"
            );
    return  val;
}

/* Nothing past this point */
