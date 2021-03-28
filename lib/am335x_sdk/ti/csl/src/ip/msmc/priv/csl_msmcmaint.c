/**
 *  @file csl_msmcmaint.c
 *
 *  @brief
 *     MSMC Maintainence Functions
 *  \par
 *   ================================================================================
 *
 *   @n   (C)  Copyright 2017 Texas Instruments Incorporated
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



#include <stdint.h>
#include <csl_msmcmaint.h>
#include <cslr_msmc.h>


//PID
uint64_t CSL_msmcGetPid( CSL_msmc_cfgs0Regs *ptr)
{
    return(ptr->PID);
}


//COHCTRL
void CSL_msmcSetCohCtrl( CSL_msmc_cfgs0Regs *ptr, uint8_t val)
{
    ptr->COHCTRL =  (CSL_MSMC_CFGS0_COHCTRL_BCM_MASK & val) << CSL_MSMC_CFGS0_COHCTRL_BCM_SHIFT;
}

uint64_t CSL_msmcGetCohCtrl( CSL_msmc_cfgs0Regs *ptr)
{
    return (ptr->COHCTRL);
}



//SMEDCC
void CSL_msmcEnableScrub( CSL_msmc_cfgs0Regs *ptr, uint8_t cnt)
{
    ptr->SMEDCC = (CSL_MSMC_CFGS0_SMEDCC_SEN_MASK | (( CSL_MSMC_CFGS0_SMEDCC_REFDEL_MASK & cnt)
                                                     << CSL_MSMC_CFGS0_SMEDCC_REFDEL_SHIFT));
}

uint64_t CSL_GetScrub(CSL_msmc_cfgs0Regs *ptr)
{
    return(ptr->SMEDCC);
}

void CSL_msmcDisableScrub(CSL_msmc_cfgs0Regs *ptr)
{
    ptr->SMEDCC = 0x0000000000000000U;
}



//CAHCE_CTRL
void CSL_msmcSetCacheSize( CSL_msmc_cfgs0Regs *ptr, uint64_t size)
{
    uint64_t   cachectrlval;
    cachectrlval = CSL_MSMC_CFGS0_CACHE_CTRL_CACHE_SIZE_MASK & size;
    ptr->CACHE_CTRL = cachectrlval;
}

uint64_t CSL_GetCacheSize(CSL_msmc_cfgs0Regs *ptr)
{
    return(ptr->CACHE_CTRL);
}



//RT_WAY_SELECT
void CSL_msmcSetRelTimWaySel(CSL_msmc_cfgs0Regs *ptr, uint8_t andmask, uint8_t ormask)
{
    ptr->RT_WAY_SELECT = (
                          ((andmask << CSL_MSMC_CFGS0_RT_WAY_SELECT_AND_MASK_SHIFT) &
                           CSL_MSMC_CFGS0_RT_WAY_SELECT_AND_MASK_MASK)
                          |
                          ((ormask << CSL_MSMC_CFGS0_RT_WAY_SELECT_OR_MASK_SHIFT) &
                           CSL_MSMC_CFGS0_RT_WAY_SELECT_OR_MASK_MASK)
                          );
}


uint64_t CSL_msmcGetRelTimWaySel(CSL_msmc_cfgs0Regs *ptr)
{
    return(ptr->RT_WAY_SELECT);
}


//NRT_WAY_SELECT
void CSL_msmcSetNRelTimWaySel(CSL_msmc_cfgs0Regs *ptr, uint8_t andmask, uint8_t ormask)
{
    ptr->NRT_WAY_SELECT = (
                          ((andmask << CSL_MSMC_CFGS0_NRT_WAY_SELECT_AND_MASK_SHIFT) &
                           CSL_MSMC_CFGS0_NRT_WAY_SELECT_AND_MASK_MASK)
                          |
                          ((ormask << CSL_MSMC_CFGS0_NRT_WAY_SELECT_OR_MASK_SHIFT) &
                           CSL_MSMC_CFGS0_NRT_WAY_SELECT_OR_MASK_MASK)
                          );
}


uint64_t CSL_msmcGetNRelTimWaySel(CSL_msmc_cfgs0Regs *ptr)
{
    return(ptr->NRT_WAY_SELECT);
}


//SMESTAT
uint64_t CSL_msmcGetSmeStat(CSL_msmc_cfgs0Regs *ptr)
{
    return(ptr->SMESTAT);
}



//SMIRSTAT
uint64_t CSL_msmcGetSmIrStat(CSL_msmc_cfgs0Regs *ptr)
{
    //    return(ptr->SMIRSTAT);
}



//SMIRWS
void CSL_msmcSetSmIrWs(CSL_msmc_cfgs0Regs *ptr, uint8_t val)
{
    ptr->u0.SMIRWS = (val << CSL_MSMC_CFGS0_SMIRWS_NULL_SLV_SHIFT)
        & CSL_MSMC_CFGS0_SMIRWS_NULL_SLV_MASK;
}



//SMIRC
void CSL_msmcClearInt(CSL_msmc_cfgs0Regs *ptr)
{
    ptr->SMIRC = CSL_MSMC_CFGS0_SMIRC_NULL_SLV_MASK;
}


//SMIESTAT
uint64_t CSL_msmcGetSmIeStat(CSL_msmc_cfgs0Regs *ptr)
{
    return(ptr->u1.SMIESTAT);
}


//SMIEWS
void CSL_msmcSetSmIeWs(CSL_msmc_cfgs0Regs *ptr, uint8_t val)
{
    ptr->u1.SMIEWS = (val << CSL_MSMC_CFGS0_SMIEWS_NULL_SLV_SHIFT)
        & CSL_MSMC_CFGS0_SMIEWS_NULL_SLV_MASK;
}


//SMIEC

void CSL_msmcClearIent(CSL_msmc_cfgs0Regs *ptr)
{
    ptr->SMIEC =  CSL_MSMC_CFGS0_SMIEC_NULL_SLV_MASK;
}


//SBNDCOH0
void CSL_msmcSetStvBndCohPt0(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH0 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH0_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH0_SBNDE_RT_MASK);
}


//SBNDCOH1
void CSL_msmcSetStvBndCohPt1(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH1 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH1_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH1_SBNDE_RT_MASK);
}


//SBNDCOH2
void CSL_msmcSetStvBndCohPt2(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH2 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH2_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH2_SBNDE_RT_MASK);
}


//SBNDCOH3
void CSL_msmcSetStvBndCohPt3(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH3 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH3_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH3_SBNDE_RT_MASK);
}


//SBNDCOH4
void CSL_msmcSetStvBndCohPt4(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH4 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH4_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH4_SBNDE_RT_MASK);
}


//SBNDCOH5
void CSL_msmcSetStvBndCohPt5(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH5 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_MASK);
}


//SBNDCOH6
void CSL_msmcSetStvBndCohPt6(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH6 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH6_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH6_SBNDE_RT_MASK);
}


//SBNDCOH7
void CSL_msmcSetStvBndCohPt7(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH7 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH5_SBNDE_RT_MASK);
}


//SBNDCOH8
void CSL_msmcSetStvBndCohPt8(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH8 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH8_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH8_SBNDE_RT_MASK);
}


//SBNDCOH9
void CSL_msmcSetStvBndCohPt9(
                             CSL_msmc_cfgs0Regs *ptr,
                             csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH9 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH9_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH9_SBNDE_RT_MASK);
}


//SBNDCOH10
void CSL_msmcSetStvBndCohPt10(
                              CSL_msmc_cfgs0Regs *ptr,
                              csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH10 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH10_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH10_SBNDE_RT_MASK);
}


//SBNDCOH11
void CSL_msmcSetStvBndCohPt11(
                              CSL_msmc_cfgs0Regs *ptr,
                              csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH11 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH11_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH11_SBNDE_RT_MASK);
}


//SBNDCOH12
void CSL_msmcSetStvBndCohPt12(
                              CSL_msmc_cfgs0Regs *ptr,
                              csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDCOH12 =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH12_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDCOH12_SBNDE_RT_MASK);
}


//SBNDDRU
void CSL_msmcSetStvBndDRU(
                          CSL_msmc_cfgs0Regs *ptr,
                          csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDDRU =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_MASK);
}

//SBNDRESP
void CSL_msmcSetStvBndResp(
                           CSL_msmc_cfgs0Regs *ptr,
                           csl_msmcmaint_stv_t *bnd_descriptor
                          )
{
    ptr->SBNDRESP =
        ((bnd_descriptor->sbndmnrt << CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDM_NRT_MASK)
        |
        ((bnd_descriptor->sbndenrt << CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDE_NRT_MASK)
        |
        ((bnd_descriptor->sbndmrt << CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDM_RT_MASK)
        |
        ((bnd_descriptor->sbndert << CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_SHIFT)
         & CSL_MSMC_CFGS0_SBNDDRU_SBNDE_RT_MASK);
}
