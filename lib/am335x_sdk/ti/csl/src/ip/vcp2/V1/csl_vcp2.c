/* ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008-2012
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
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
*/

/** ===========================================================================
 *   @file  csl_vcp2.c
 *
 *   @brief  
 *      VCP2 API implementation
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2008-2012, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found 
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par  
 */

#include <ti/csl/csl_vcp2.h>
#include <ti/csl/csl_vcp2Aux.h>
#include <ti/csl/csl_utils.h>

/* Polynomials for different constraint lengths and
   code rates
   - All these are octal numbers
   - Default values
*/
#define VCP2_POLY0_FOR_CONST9_RATE_1_2 (0561U)
#define VCP2_POLY1_FOR_CONST9_RATE_1_2 (0753U)

#define VCP2_POLY0_FOR_CONST8_RATE_1_2 (0712U)
#define VCP2_POLY1_FOR_CONST8_RATE_1_2 (0476U)

#define VCP2_POLY0_FOR_CONST7_RATE_1_2 (0554U)
#define VCP2_POLY1_FOR_CONST7_RATE_1_2 (0744U)

#define VCP2_POLY0_FOR_CONST6_RATE_1_2 (0650U)
#define VCP2_POLY1_FOR_CONST6_RATE_1_2 (0570U)

#define VCP2_POLY0_FOR_CONST5_RATE_1_2 (0460U)
#define VCP2_POLY1_FOR_CONST5_RATE_1_2 (0720U)


#define VCP2_POLY0_FOR_CONST9_RATE_1_3_1_4 (0557U)
#define VCP2_POLY1_FOR_CONST9_RATE_1_3_1_4 (0663U)
#define VCP2_POLY2_FOR_CONST9_RATE_1_3_1_4 (0711U)
#define VCP2_POLY3_FOR_CONST9_RATE_1_3_1_4 (0557U)

#define VCP2_POLY0_FOR_CONST8_RATE_1_3_1_4 (0452U)
#define VCP2_POLY1_FOR_CONST8_RATE_1_3_1_4 (0662U)
#define VCP2_POLY2_FOR_CONST8_RATE_1_3_1_4 (0756U)
#define VCP2_POLY3_FOR_CONST8_RATE_1_3_1_4 (0452U)

#define VCP2_POLY0_FOR_CONST7_RATE_1_3_1_4 (0544U)
#define VCP2_POLY1_FOR_CONST7_RATE_1_3_1_4 (0624U)
#define VCP2_POLY2_FOR_CONST7_RATE_1_3_1_4 (0764U)
#define VCP2_POLY3_FOR_CONST7_RATE_1_3_1_4 (0544U)

#define VCP2_POLY0_FOR_CONST6_RATE_1_3_1_4 (0470U)
#define VCP2_POLY1_FOR_CONST6_RATE_1_3_1_4 (0530U)
#define VCP2_POLY2_FOR_CONST6_RATE_1_3_1_4 (0750U)
#define VCP2_POLY3_FOR_CONST6_RATE_1_3_1_4 (0470U)

#define VCP2_POLY0_FOR_CONST5_RATE_1_3_1_4 (0520U)
#define VCP2_POLY1_FOR_CONST5_RATE_1_3_1_4 (0660U)
#define VCP2_POLY2_FOR_CONST5_RATE_1_3_1_4 (0760U)
#define VCP2_POLY3_FOR_CONST5_RATE_1_3_1_4 (0520U)

/* Maxmimum frame sizes, maximum (reliability length +
   convergence distance) and the number of trellis stages
   processed in 2 passes for different constraint
   lengths of soft and hard decisions
*/

/* For Hard Decisions */
#define VCP2_MAX_FRAME_SIZE_FOR_HD_CONST9          (120U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST9    (124U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST9  (4U)

#define VCP2_MAX_FRAME_SIZE_FOR_HD_CONST8          (217U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST8    (217U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST8  (7U)

#define VCP2_MAX_FRAME_SIZE_FOR_HD_CONST7          (378U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST7    (378U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST7  (6U)

#define VCP2_MAX_FRAME_SIZE_FOR_HD_CONST6          (635U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST6    (635U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST6  (5U)

#define VCP2_MAX_FRAME_SIZE_FOR_HD_CONST5          (2044U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST5    (2044U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST5  (4U)

/* For Soft Decisions */
#define VCP2_MAX_FRAME_SIZE_FOR_SD_CONST9          (56U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST9    (60U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST9  (4U)

#define VCP2_MAX_FRAME_SIZE_FOR_SD_CONST8          (105U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST8    (105U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST8  (7U)

#define VCP2_MAX_FRAME_SIZE_FOR_SD_CONST7          (186U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST7    (186U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST7  (6U)

#define VCP2_MAX_FRAME_SIZE_FOR_SD_CONST6          (315U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST6    (315U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST6  (5U)

#define VCP2_MAX_FRAME_SIZE_FOR_SD_CONST5          (1020U)
#define VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST5    (1020U)
#define VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST5  (4U)

/* Limit on sliding window length in case more than 1 sliding
   window is required. (see section 2.4.5.4) */
#define VCP2_REL_LEN_LIMIT_FOR_A_SILDING_WINDOW (248U)

/* Branch metrics buffer length and branch metrics per
   trellis state for different code rates */
#define VCP2_BM_PER_TRL_FOR_RATE_1_4                (8U)
#define VCP2_SYMX_FOR_128_BYTE_PER_RXEVENT_RATE_1_4 (3U)

#define VCP2_BM_PER_TRL_FOR_RATE_1_3                (4U)
#define VCP2_SYMX_FOR_128_BYTE_PER_RXEVENT_RATE_1_3 (7U)

#define VCP2_BM_PER_TRL_FOR_RATE_1_2                (2U)
#define VCP2_SYMX_FOR_128_BYTE_PER_RXEVENT_RATE_1_2 (15U)

/* Number of bytes transfered to the VCP2 per receive event */
#define VCP2_BYTE_COUNT_PER_RXEVENT  (128U)

/* Maximum hard decisions in out FIFO */
#define VCP2_MAX_HD_IN_OUTFIFO       (2048U)

/* Number of hard decisions per FIFO word */
#define VCP2_HD_PER_OUTFIFO_WORD     (64U)

/* Maximum soft decisions in out FIFO */
#define VCP2_MAX_SD_IN_OUTFIFO       (256U)

/* Number of hard decisions per FIFO word */
#define VCP2_SD_PER_OUTFIFO_WORD     (8U)

/* Number of words in out FIFO */
#define VCP2_OUTFIFO_WORDS           (32U)

/** ============================================================================
 *  @n@b VCP2GetBaseAddress
 *
 *  @b Description
 *  @n  Function to get the base address of the peripheral instance.
 *      This function is used for getting the base address of the peripheral
 *      instance. This function will be called inside the VCP2_init()
 *      function call. This function is open for re-implementing if the user
 *      wants to modify the base address of the peripheral object to point to
 *      a different location and there by allow CSL initiated write/reads into
 *      peripheral. MMR's go to an alternate location.
 *
 *  @b Arguments
    @verbatim
        vcp2Num         Specifies the instance of the VCP2 to be opened.
        pBaseAddress    Pointer to baseaddress structure containing base
                        address details.
    @endverbatim
 *
 *  <b> Return Value </b>  CSL_Status
 *  @li                    CSL_OK               Successful on getting the base
 *                                              address of vcp2
 *  @li                    CSL_ESYS_FAIL        The instance number is invalid.
 *  @li                    CSL_ESYS_INVPARAMS   Invalid parameter
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Base Address structure is populated and appropriate status is returned.
 *
 *  @b  Writes
 *  @n  None
 *  
 *  @b Example
    @verbatim
        int          status;
        VCP2BaseAddress  baseAddress;

        ...
        status = VCP2GetBaseAddress(CSL_VCP2_0, &baseAddress);
    @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
Uint32  VCP2GetBaseAddress (
        Int32                 vcp2Num,
        VCP2BaseAddress    *pBaseAddress
);
Uint32  VCP2GetBaseAddress (
        Int32                 vcp2Num,
        VCP2BaseAddress    *pBaseAddress
)
{
    Uint32 status = (Uint32)CSL_SOK;

    if (pBaseAddress == NULL)
    {
        status = (Uint32)CSL_ESYS_INVPARAMS;
    }
    else
    {
        switch (vcp2Num) 
        {
#ifdef CSL_VCP2_A
            case CSL_VCP2_A:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_A_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_A_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_A */
#ifdef CSL_VCP2_B
            case CSL_VCP2_B:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_B_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_B_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_B */
#ifdef CSL_VCP2_C
            case CSL_VCP2_C:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_C_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_C_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_C */
#ifdef CSL_VCP2_D
            case CSL_VCP2_D:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_D_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_D_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_D */
#ifdef CSL_VCP2_E
            case CSL_VCP2_E:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_E_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_E_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_E */
#ifdef CSL_VCP2_F
            case CSL_VCP2_F:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_F_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_F_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_F */
#ifdef CSL_VCP2_G
            case CSL_VCP2_G:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_G_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_G_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_G */
#ifdef CSL_VCP2_H
            case CSL_VCP2_H:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)CSL_VCP2_H_DATA_REGS;
                pBaseAddress->cfgregs   =   (CSL_Vcp2CfgRegsOvly)CSL_VCP2_H_CFG_REGS;
                break;
            }
#endif /* CSL_VCP2_H */
            default:
            {
                pBaseAddress->regs      =   (CSL_Vcp2RegsOvly)NULL;
                status                  =   (Uint32)CSL_ESYS_FAIL;
                break;
            }
        }
    }
    return (status);
}

/** ============================================================================
 *  @n@b VCP2_init
 *
 *  @b  Description
 *  @n  Reserves the specified VCP2 for use. The device can be re-opened
 *      anytime after it has been normally closed, if so required.
 *      The VCP2 handle returned by this call is input as an essential argument
 *      for the rest of the APIs in VCP2 module.
 *
 *  @b Arguments
    @verbatim
        vcp2Obj        Vcp2 Module Object pointer
        instNum        VCP2 instance number.
        status         Status of the function call
    @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n VCP2Handle      Valid Vcp2 handle will be returned if status value
 *                      is equal to CSL_SOK.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  1. The status is returned in the status variable. If status
 *          returned is
 *   @li            CSL_SOK             Valid VCP2 handle is returned
 *   @li            CSL_ESYS_FAIL       The VCP2 instance is invalid
 *   @li            CSL_ESYS_INVPARAMS  The Parameter passed is invalid
 *
 *       2. Vcp2 object structure is populated
 *
 *  @b Writes
 *  @n None
 *
 *  @b Example
    @verbatim
            VCP2Handle     hVcp2;
            VCP2Obj        vcp2Obj;
            int            status;
            ...
            hVcp2 = VCP2_init(&vcp2Obj, CSL_VCP2_0, &status);
     @endverbatim
 * ===========================================================================
 */
VCP2Handle VCP2_init(VCP2Obj *pVcp2Obj,Int32 instNum, Int32 *pStatus)
{
    Uint32                 status;
    VCP2Handle         hVcp2 = NULL;
    VCP2BaseAddress    baseAddress;

    if (pStatus == NULL)
    {
        /* do nothing */
    }
    else if (pVcp2Obj == NULL)
    {
        *pStatus = CSL_ESYS_INVPARAMS;
    }
    else
    {
        status = VCP2GetBaseAddress(instNum, &baseAddress);

        if (status == (Uint32)CSL_SOK) 
        {
            pVcp2Obj->regs = baseAddress.regs;
            pVcp2Obj->cfgregs = baseAddress.cfgregs;
            pVcp2Obj->perNum = (CSL_InstNum)instNum;
            hVcp2 = (VCP2Handle)pVcp2Obj;
        }
        else 
        {
            pVcp2Obj->regs = (CSL_Vcp2RegsOvly)NULL;
            pVcp2Obj->cfgregs = (CSL_Vcp2CfgRegsOvly)NULL;
            pVcp2Obj->perNum = (CSL_InstNum)-1;
            hVcp2 = (VCP2Handle)NULL;
        }

        *pStatus = status;
    }

    return hVcp2;
}

/** ============================================================================
 *   @n@b VCP2_Close
 *
 *   @b Description
 *   @n Unreserves the VCP2 identified by the handle passed.
 *
 *   @b Arguments
 *   @verbatim
        hVcp2           VCP2 handle returned by successful VCP2_init
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - close successful
 *   @li                    CSL_ESYS_BADHANDLE - The handle passed is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  VCP2_init must be called successfully before VCP2_Close can be called.
 *
 *   <b> Post Condition </b>
 *   @n  The VCP2 CSL APIs can not be called until the VCP2 CSL is reopened
 *       again using VCP2_init
 *
 *   @b Writes
 *   @n None
 *
 *   @b Example
 *   @verbatim
            VCP2Handle     hVcp2;
            ...
            VCP2_Close(hVcp2);
    @endverbatim
 * =============================================================================
 */
CSL_Status  VCP2_Close (VCP2Handle hVcp2)
{
    CSL_Status  status;

    if (hVcp2 != NULL) 
    {
        hVcp2->regs    = (CSL_Vcp2RegsOvly) NULL;
        hVcp2->cfgregs = (CSL_Vcp2CfgRegsOvly) NULL;
        hVcp2->perNum  = (CSL_InstNum) - 1;
        status         = CSL_SOK;
    }
    else
    {
        status = CSL_ESYS_BADHANDLE;
    }

    return status;
}

/*
 * ============================================================================
 *  @n@b VCP2_genParams
 *
 *  @b Description
 *  @n  This function calculates the VCP parameters based on the input
 *      VCP2_BaseParams object values and set the values to the output
 *      VCP2_Params parameters structure.
 *
 *  @b Arguments    
    @verbatim
        pConfigBase     Pointer to VCP base parameters structure.
        pConfigParams   Pointer to output VCP channel parameters structure.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n  @bVCP2_init must be called to initialize the VCP2 peripheral
 *      before doing any operations on it.
 *
 *  <b> Post Condition </b>
 *  @n  The output Params structure, pConfigParams is populated accordingly.   
 * 
 *   @b Writes
 *   @n None
 *
 *   @b Reads
 *   @n None
 *
 *  @eg
 *   @verbatim 
            VCP2_Params      vcpParam;
            VCP2_BaseParams  vcpBaseParam;
            ...
            vcpBaseParam.rate           =   VCP2_RATE_1_4;
            vcpBaseParam.constLen       =   5;
            vcpBaseParam.frameLen       =   2042;
            vcpBaseParam.yamTh          =   50;
            vcpBaseParam.stateNum       =   2048;
            vcpBaseParam.tbConvrgMode   =   FALSE;
            vcpBaseParam.decision       =   VCP2_DECISION_HARD;
            vcpBaseParam.readFlag       =   VCP2_OUTF_YES;
            vcpBaseParam.tailBitEnable  =   FALSE;
            vcpBaseParam.traceBackIndex =   0x0;
            vcpBaseParam.outOrder       =   VCP2_OUTORDER_0_31;
            vcpBaseParam.perf           =   VCP2_SPEED_CRITICAL;
            ...
            VCP2_genParams (&vcpBaseParam, &vcpParam);
     @endverbatim
 * ============================================================================
 */
CSL_SET_CSECT  (VCP2_genParams, ".text:csl_section:vcp2")
void    VCP2_genParams (
    const VCP2_BaseParams * restrict pConfigBase,
    VCP2_Params * restrict pConfigParams
)
{
    VCP2_Rate rate = pConfigBase->rate;
    Bool tbConvrgMode = pConfigBase->tbConvrgMode;
    Bool tailBitEnable = pConfigBase->tailBitEnable;
    Uint8 constLen = pConfigBase->constLen;
    Uint8 decision = pConfigBase->decision;
    Uint8 readFlag = pConfigBase->readFlag;
    Uint8 stateNum = pConfigBase->stateNum;
    Uint8 outOrder = pConfigBase->outOrder;
    Uint8 perf = pConfigBase->perf;
    Uint16 frameLen = pConfigBase->frameLen;
    Uint16 yamTh = pConfigBase->yamTh;
    Uint16 traceBackIndex = pConfigBase->traceBackIndex;

    Uint16 poly0 = 0;
    Uint16 poly1 = 0;
    Uint16 poly2 = 0;
    Uint16 poly3 = 0;
    Uint16 relLen = 0;
    Uint16 convDist = 0;
    Int16 minSm = 0;
    Int16 maxSm = 0x400; /* Select a maximum value for initial state metric */
    Uint8 bmBuffLen;
    Uint8 decBuffLen;
    Uint16 numBmFrames;
    Uint16 numDecFrames;
    Uint8 traceBack;

    Uint8 i;
    Uint8 convMultiplier;
    Uint16 polynomes[4];
    Uint16 fMax;
    Uint16 rcMax;
    Uint16 multiple;
    Uint16 nsw;
    Uint16 mask;
    Uint16 bmNum;
    Uint32 bmCnt;

    Uint16 temp_var = 0;
    Uint32 temp_var1 = 0;

    /* VCPIC0 parameters */
    if (rate == (VCP2_Rate)VCP2_RATE_1_2) {
        if (constLen == 9U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST9_RATE_1_2;
            polynomes[1] = VCP2_POLY1_FOR_CONST9_RATE_1_2;
        }                       /* end if constLen == 9 */
        else if (constLen == 8U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST8_RATE_1_2;
            polynomes[1] = VCP2_POLY1_FOR_CONST8_RATE_1_2;
        }                       /* end if constLen == 8 */
        else if (constLen == 7U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST7_RATE_1_2;
            polynomes[1] = VCP2_POLY1_FOR_CONST7_RATE_1_2;
        }                       /* end if constLen == 7 */
        else if (constLen == 6U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST6_RATE_1_2;
            polynomes[1] = VCP2_POLY1_FOR_CONST6_RATE_1_2;
        }                       /* end if constLen == 6 */
        else {                  /* (constLen == 5) */
            polynomes[0] = VCP2_POLY0_FOR_CONST5_RATE_1_2;
            polynomes[1] = VCP2_POLY1_FOR_CONST5_RATE_1_2;
        }                       /* end if constLen == 5 */
    }                           /* end if rate 1/2 */
    else {                      /* if rate 1/3 or 1/4 */
        if (constLen == 9U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST9_RATE_1_3_1_4;
            polynomes[1] = VCP2_POLY1_FOR_CONST9_RATE_1_3_1_4;
            polynomes[2] = VCP2_POLY2_FOR_CONST9_RATE_1_3_1_4;
            polynomes[3] = VCP2_POLY3_FOR_CONST9_RATE_1_3_1_4;
        }                       /* end if constLen == 9 */
        else if (constLen == 8U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST8_RATE_1_3_1_4;
            polynomes[1] = VCP2_POLY1_FOR_CONST8_RATE_1_3_1_4;
            polynomes[2] = VCP2_POLY2_FOR_CONST8_RATE_1_3_1_4;
            polynomes[3] = VCP2_POLY3_FOR_CONST8_RATE_1_3_1_4;
        }                       /* end if constLen == 8 */
        else if (constLen == 7U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST7_RATE_1_3_1_4;
            polynomes[1] = VCP2_POLY1_FOR_CONST7_RATE_1_3_1_4;
            polynomes[2] = VCP2_POLY2_FOR_CONST7_RATE_1_3_1_4;
            polynomes[3] = VCP2_POLY3_FOR_CONST7_RATE_1_3_1_4;
        }                       /* end if constLen == 7 */
        else if (constLen == 6U) {
            polynomes[0] = VCP2_POLY0_FOR_CONST6_RATE_1_3_1_4;
            polynomes[1] = VCP2_POLY1_FOR_CONST6_RATE_1_3_1_4;
            polynomes[2] = VCP2_POLY2_FOR_CONST6_RATE_1_3_1_4;
            polynomes[3] = VCP2_POLY3_FOR_CONST6_RATE_1_3_1_4;
        }                       /* end if constLen == 6 */
        else {                  /* (constLen == 5) */
            polynomes[0] = VCP2_POLY0_FOR_CONST5_RATE_1_3_1_4;
            polynomes[1] = VCP2_POLY1_FOR_CONST5_RATE_1_3_1_4;
            polynomes[2] = VCP2_POLY2_FOR_CONST5_RATE_1_3_1_4;
            polynomes[3] = VCP2_POLY3_FOR_CONST5_RATE_1_3_1_4;
        }                       /* end if constLen == 5 */
    }                           /* end if rate 1/3 or 1/4 */

    /* zero out any unneeded polynomials, based on the data rate */
    for (i = VCP2_RATE_1_4; i > rate; i--) {
        polynomes[i - 1U] = 0;
    }
    /* the polynome sent to the coprocessor has always the most
       significant bit masked */
    mask = 0x00FFU;

    /* Polynomes coefficients */
    poly0 = polynomes[0] & mask;
    poly1 = polynomes[1] & mask;
    poly2 = polynomes[2] & mask;
    poly3 = polynomes[3] & mask;


    /* Calculation of reliability length */
    /* Identify Fmax for a given constraint length and decision type */
    if (decision == VCP2_DECISION_HARD) {
        if (constLen == 9U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_HD_CONST9;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST9;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST9;
        }                       /* end if constLen == 9 */
        if (constLen == 8U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_HD_CONST8;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST8;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST8;
        }                       /* end if constLen == 8 */
        if (constLen == 7U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_HD_CONST7;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST7;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST7;
        }                       /* end if constLen == 7 */
        if (constLen == 6U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_HD_CONST6;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST6;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST6;
        }                       /* end if constLen == 6 */
        if (constLen == 5U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_HD_CONST5;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_HD_CONST5;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_HD_CONST5;
        }                       /* end if constLen == 5 */
    }                           /* end if hard decision */
    else {                      /* if soft decision */
        if (constLen == 9U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_SD_CONST9;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST9;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST9;
        }                       /* end if constLen == 9 */
        if (constLen == 8U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_SD_CONST8;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST8;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST8;
        }                       /* end if constLen == 8 */
        if (constLen == 7U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_SD_CONST7;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST7;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST7;
        }                       /* end if constLen == 7 */
        if (constLen == 6U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_SD_CONST6;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST6;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST6;
        }                       /* end if constLen == 6 */
        if (constLen == 5U) {
            fMax = VCP2_MAX_FRAME_SIZE_FOR_SD_CONST5;
            rcMax = VCP2_MAX_RELLEN_CONV_DIST_FOR_SD_CONST5;
            multiple = VCP2_TRL_STAGES_IN_2_PASSES_FOR_SD_CONST5;
        }                       /* end if constLen == 5 */
    }                           /* end if soft decision */

    /* If mixed or convergent traceback mode */
    if ((tbConvrgMode == TRUE) || (frameLen > fMax)) {
        if (perf == VCP2_SPEED_MOST_CRITICAL) {  /* Speed most critical */
            convMultiplier = 3U;                 /* convMultiplier
                                                   values  - as
                                                   specified in the
                                                   'TPC2_VCP2_API_
                                                   Requirements_v1.4'
                                                   spread sheet */
        }
        else if (perf == VCP2_PERF_CRITICAL) {   /* Performance critical */
            if (constLen == 9U) {
                convMultiplier = 6U;
            }
            else {
                convMultiplier = 9U;
            }

        }
        else if (perf == VCP2_PERF_MOST_CRITICAL) {
                  /* Performance most critical */
            if (constLen == 9U) {
                convMultiplier = 6U;
            }
            else if (constLen == 8U) {
                convMultiplier = 12U;
            }
            else {
                convMultiplier = 18U;
            }
        }
        else {                  /* for speed critical and default case */

            if (constLen == 9U) {
                convMultiplier = 3U;
            }
            else {
                convMultiplier = 6U;
            }
        }
        /* Calculation of Reliability length and Convergence distance */
        temp_var = ((Uint16)constLen) - ((Uint16)1U);
        convDist = (Uint16)(convMultiplier * temp_var);
        nsw = (Uint16)(VCP2_normalCeil ((Uint32)frameLen, (((Uint32)rcMax) - ((Uint32)convDist))));
        relLen = multiple * ((Uint16)(VCP2_normalCeil (frameLen, nsw * multiple)));

        if ((decision == VCP2_DECISION_SOFT) && (constLen < 7U)) {
            while (relLen > VCP2_REL_LEN_LIMIT_FOR_A_SILDING_WINDOW) {
                nsw++;
                relLen = multiple * ((Uint16)(VCP2_normalCeil (frameLen, nsw * multiple)));
            }
        }
    }                          /* end if mixed or convergent traceback modes */


    /* Trace back mode */
    if (tbConvrgMode == TRUE) {
        traceBack = VCP2_TRACEBACK_CONVERGENT;
    }
    else {
        if (frameLen > fMax)
        {
            traceBack = VCP2_TRACEBACK_MIXED;   
        }
        else
        {
            traceBack = VCP2_TRACEBACK_TAILED;
        }
    }


    /* Calculation of branch metric buffer length */
    /* Number of branch metrics per trellis stage */
    if (rate == VCP2_RATE_1_4) {
        bmNum = VCP2_BM_PER_TRL_FOR_RATE_1_4;
        bmBuffLen = VCP2_SYMX_FOR_128_BYTE_PER_RXEVENT_RATE_1_4;
    }
    else if (rate == VCP2_RATE_1_3) {
        bmNum = VCP2_BM_PER_TRL_FOR_RATE_1_3;
        bmBuffLen = VCP2_SYMX_FOR_128_BYTE_PER_RXEVENT_RATE_1_3;
    }
    else if (rate == VCP2_RATE_1_2) {
        bmNum = VCP2_BM_PER_TRL_FOR_RATE_1_2;
        bmBuffLen = VCP2_SYMX_FOR_128_BYTE_PER_RXEVENT_RATE_1_2;
    }

    /* Maximum number of branch metrics */
    if (traceBack == VCP2_TRACEBACK_CONVERGENT)
    {
        temp_var1 = ((Uint32)frameLen) + convDist;
        bmCnt = (Uint32)(bmNum * temp_var1);
    }
    else 
    {
        temp_var1 = ((Uint32)frameLen) + constLen - 1U;
        bmCnt = (Uint32)(bmNum * temp_var1);
    }
    /* Number of frame transfers */
    numBmFrames = (Uint16)(VCP2_normalCeil (bmCnt, VCP2_BYTE_COUNT_PER_RXEVENT));


    /* Calculation of Decision buffer length */
    if (decision == VCP2_DECISION_HARD) {
        if (frameLen > VCP2_MAX_HD_IN_OUTFIFO)
        {
            decBuffLen = (VCP2_OUTFIFO_WORDS) - 1U;
        }
        else {
            decBuffLen = (Uint8)(VCP2_normalCeil (frameLen, VCP2_HD_PER_OUTFIFO_WORD)) - 1U;
            numDecFrames = 1U;  /* Not being used here */
        }
    }
    else {
        if (frameLen > VCP2_MAX_SD_IN_OUTFIFO)
        {
            decBuffLen = (VCP2_OUTFIFO_WORDS) - 1U;
        }
        else {
            decBuffLen = (Uint8)(VCP2_normalCeil (frameLen, VCP2_SD_PER_OUTFIFO_WORD)) - 1U;
            numDecFrames = 1U;  /* Not being used here */
        }
    }

    pConfigParams->rate = rate;
    pConfigParams->constLen = constLen;
    pConfigParams->poly0 = poly0;
    pConfigParams->poly1 = poly1;
    pConfigParams->poly2 = poly2;
    pConfigParams->poly3 = poly3;
    pConfigParams->yamTh = yamTh;
    pConfigParams->frameLen = frameLen;
    pConfigParams->relLen = relLen;
    pConfigParams->convDist = convDist;
    pConfigParams->traceBackEn = tailBitEnable;
    pConfigParams->traceBackIndex = traceBackIndex;
    pConfigParams->outOrder = outOrder;
    pConfigParams->maxSm = maxSm;
    pConfigParams->minSm = minSm;
    pConfigParams->stateNum = stateNum;
    pConfigParams->bmBuffLen = bmBuffLen;
    pConfigParams->decBuffLen = decBuffLen;
    pConfigParams->traceBack = traceBack;
    pConfigParams->readFlag = readFlag;
    pConfigParams->decision = decision;
    pConfigParams->numBmFrames = numBmFrames;
    pConfigParams->numDecFrames = numDecFrames;
}

/*
 * ============================================================================
 *  @n@b VCP2_genIc
 *
 *  @b  Description
 *      This function generates the required input configuration registers'
 *      values needed to program the VCP based on the parameters provided by
 *      VCP2_Params object values.
 *
 *  @b Arguments    
    @verbatim
        pConfigParams   Pointer to channel parameters structure.
        pConfigIc       Pointer to input configuration structure.       
    @endverbatim
 * 
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n  @bVCP2_init must be called to initialize the VCP2 peripheral
 *      before doing any operations on it.
 *
 *  <b> Post Condition </b>
 *  @n  Based on the input configuration passed, the appropriate VCP2 registers
 *      are programmed and the input configuration structure pConfigIc is 
 *      populated.
 * 
 *   @b Writes
 *   @n VCP2_VCPIC1_YAMEN=1, 
 *      VCP2_VCPIC1_YAMT
 *
 *  @eg
    @verbatim 
            VCP2_Params      vcpParam;
            VCP2_ConfigIc    vcpConfig;
            VCP2_BaseParams  vcpBaseParam;
            ...
            vcpBaseParam.rate           =   VCP2_RATE_1_4;
            vcpBaseParam.constLen       =   5;
            vcpBaseParam.frameLen       =   2042;
            vcpBaseParam.yamTh          =   50;
            vcpBaseParam.stateNum       =   2048;
            vcpBaseParam.tbConvrgMode   =   FALSE;
            vcpBaseParam.decision       =   VCP2_DECISION_HARD;
            vcpBaseParam.readFlag       =   VCP2_OUTF_YES;
            vcpBaseParam.tailBitEnable  =   FALSE;
            vcpBaseParam.traceBackIndex =   0x0;
            vcpBaseParam.outOrder       =   VCP2_OUTORDER_0_31;
            vcpBaseParam.perf           =   VCP2_SPEED_CRITICAL;
            ...
            VCP2_genParams (&vcpBaseParam, &vcpParam);
            
            VCP2_genIc (&vcpParam, &vcpConfig);
     @endverbatim
 * ============================================================================
 */
CSL_SET_CSECT  (VCP2_genIc, ".text:csl_section:vcp2")
void    VCP2_genIc (
    const VCP2_Params * restrict pConfigParams,
    VCP2_ConfigIc     * restrict pConfigIc
)
{
    Uint8 poly0 = pConfigParams->poly0;
    Uint8 poly1 = pConfigParams->poly1;
    Uint8 poly2 = pConfigParams->poly2;
    Uint8 poly3 = pConfigParams->poly3;
    Uint16 yamTh = pConfigParams->yamTh;
    Uint16 frameLen = pConfigParams->frameLen;
    Uint16 relLen = pConfigParams->relLen;
    Uint16 convDist = pConfigParams->convDist;
    Uint16 traceBackIndex = pConfigParams->traceBackIndex;
    Bool traceBackEn = pConfigParams->traceBackEn;
    Uint8 outOrder = pConfigParams->outOrder;
    Int16 minSm = pConfigParams->minSm;
    Int16 maxSm = pConfigParams->maxSm;
    Uint8 stateNum = pConfigParams->stateNum;
    Uint8 bmBuffLen = pConfigParams->bmBuffLen;
    Uint8 decBuffLen = pConfigParams->decBuffLen;
    Uint8 traceBack = pConfigParams->traceBack;
    Uint8 readFlag = pConfigParams->readFlag;
    Uint8 decision = pConfigParams->decision;
    Uint32 ic0 = 0;
    Uint32 ic1 = 0;
    Uint32 ic2 = 0;
    Uint32 ic3 = 0;
    Uint32 ic4 = 0;
    Uint32 ic5 = 0;

    /* VCPIC0 parameters */
    ic0 = CSL_FMK (VCP2_VCPIC0_POLY0, (Uint32)poly0) |
        CSL_FMK (VCP2_VCPIC0_POLY1, (Uint32)poly1) |
        CSL_FMK (VCP2_VCPIC0_POLY2, (Uint32)poly2) |
        CSL_FMK (VCP2_VCPIC0_POLY3, (Uint32)poly3);

    /* VCPIC1 parameters */
    if (yamTh) {
        CSL_FINST (ic1, VCP2_VCPIC1_YAMEN, ENABLE);
        CSL_FINS (ic1, VCP2_VCPIC1_YAMT, (Uint32)yamTh);
    }

    /* VCPIC2 parameters */
    ic2 = CSL_FMK (VCP2_VCPIC2_FL, (Uint32)frameLen) |
        CSL_FMK (VCP2_VCPIC2_R, (Uint32)relLen);

    /* VCPIC3 parameters */
    ic3 = CSL_FMK (VCP2_VCPIC3_C, (Uint32)convDist) |
        CSL_FMK (VCP2_VCPIC3_ITBI, (Uint32)traceBackIndex) |
        CSL_FMK (VCP2_VCPIC3_ITBEN, (Uint32)traceBackEn) |
        CSL_FMK (VCP2_VCPIC3_OUT_ORDER, (Uint32)outOrder);

    /* VCPIC4 parameters */
    ic4 = CSL_FMK (VCP2_VCPIC4_IMAXS, (Uint32)maxSm) |
        CSL_FMK (VCP2_VCPIC4_IMINS, (Uint32)minSm);

    /* VCPIC5 parameters */
    ic5 = CSL_FMK (VCP2_VCPIC5_IMAXI, (Uint32)stateNum) |
        CSL_FMK (VCP2_VCPIC5_SYMX, (Uint32)bmBuffLen) |
        CSL_FMK (VCP2_VCPIC5_SYMR, (Uint32)decBuffLen) |
        CSL_FMK (VCP2_VCPIC5_TB, (Uint32)traceBack) |
        CSL_FMK (VCP2_VCPIC5_OUTF, (Uint32)readFlag) |
        CSL_FMK (VCP2_VCPIC5_SDHD, (Uint32)decision);

    pConfigIc->ic0 = ic0;
    pConfigIc->ic1 = ic1;
    pConfigIc->ic2 = ic2;
    pConfigIc->ic3 = ic3;
    pConfigIc->ic4 = ic4;
    pConfigIc->ic5 = ic5;

}

