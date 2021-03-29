/********************************************************************
 * Copyright (C) 2019 Texas Instruments Incorporated.
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
 *  Name        : cslr_vmap.h
*/
#ifndef CSLR_VMAP_H_
#define CSLR_VMAP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t REQID;
    volatile uint32_t VIRTID;
} CSL_vmapRegs_trans;


typedef struct {
    volatile uint32_t DESC;
} CSL_vmapRegs_ext;


typedef struct {
    CSL_vmapRegs_trans TRANS[32];
    volatile uint8_t  Resv_512[128];
    volatile uint32_t DEFMAP;
    volatile uint8_t  Resv_768[252];
    CSL_vmapRegs_ext EXT[32];
    volatile uint8_t  Resv_1024[128];
    volatile uint32_t OB_VIRTID_MATCH;
} CSL_vmapRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_VMAP_TRANS_CTRL(TRANS)                                             (0x00000000U+((TRANS)*0xCU))
#define CSL_VMAP_TRANS_REQID(TRANS)                                            (0x00000004U+((TRANS)*0xCU))
#define CSL_VMAP_TRANS_VIRTID(TRANS)                                           (0x00000008U+((TRANS)*0xCU))
#define CSL_VMAP_DEFMAP                                                        (0x00000200U)
#define CSL_VMAP_EXT_DESC(EXT)                                                 (0x00000300U+((EXT)*0x4U))
#define CSL_VMAP_OB_VIRTID_MATCH                                               (0x00000400U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CTRL */

#define CSL_VMAP_TRANS_CTRL_EN_MASK                                            (0x00000001U)
#define CSL_VMAP_TRANS_CTRL_EN_SHIFT                                           (0x00000000U)
#define CSL_VMAP_TRANS_CTRL_EN_MAX                                             (0x00000001U)

/* REQID */

#define CSL_VMAP_TRANS_REQID_MASK_MASK                                         (0xFFFF0000U)
#define CSL_VMAP_TRANS_REQID_MASK_SHIFT                                        (0x00000010U)
#define CSL_VMAP_TRANS_REQID_MASK_MAX                                          (0x0000FFFFU)

#define CSL_VMAP_TRANS_REQID_RID_MASK                                          (0x0000FFFFU)
#define CSL_VMAP_TRANS_REQID_RID_SHIFT                                         (0x00000000U)
#define CSL_VMAP_TRANS_REQID_RID_MAX                                           (0x0000FFFFU)

/* VIRTID */

#define CSL_VMAP_TRANS_VIRTID_ATYPE_MASK                                       (0x00030000U)
#define CSL_VMAP_TRANS_VIRTID_ATYPE_SHIFT                                      (0x00000010U)
#define CSL_VMAP_TRANS_VIRTID_ATYPE_MAX                                        (0x00000003U)

#define CSL_VMAP_TRANS_VIRTID_VID_MASK                                         (0x00000FFFU)
#define CSL_VMAP_TRANS_VIRTID_VID_SHIFT                                        (0x00000000U)
#define CSL_VMAP_TRANS_VIRTID_VID_MAX                                          (0x00000FFFU)

/* DESC */

#define CSL_VMAP_EXT_DESC_DEV_FUNC_NUM_MASK                                    (0x000000FFU)
#define CSL_VMAP_EXT_DESC_DEV_FUNC_NUM_SHIFT                                   (0x00000000U)
#define CSL_VMAP_EXT_DESC_DEV_FUNC_NUM_MAX                                     (0x000000FFU)

#define CSL_VMAP_EXT_DESC_BUS_NUM_MASK                                         (0x0000FF00U)
#define CSL_VMAP_EXT_DESC_BUS_NUM_SHIFT                                        (0x00000008U)
#define CSL_VMAP_EXT_DESC_BUS_NUM_MAX                                          (0x000000FFU)

#define CSL_VMAP_EXT_DESC_BD_EN_MASK                                           (0x00010000U)
#define CSL_VMAP_EXT_DESC_BD_EN_SHIFT                                          (0x00000010U)
#define CSL_VMAP_EXT_DESC_BD_EN_MAX                                            (0x00000001U)

#define CSL_VMAP_EXT_DESC_TRAFFIC_CLASS_MASK                                   (0xE0000000U)
#define CSL_VMAP_EXT_DESC_TRAFFIC_CLASS_SHIFT                                  (0x0000001DU)
#define CSL_VMAP_EXT_DESC_TRAFFIC_CLASS_MAX                                    (0x00000007U)

/* DEFMAP */

#define CSL_VMAP_DEFMAP_ATS_DIS_MASK                                           (0x00100000U)
#define CSL_VMAP_DEFMAP_ATS_DIS_SHIFT                                          (0x00000014U)
#define CSL_VMAP_DEFMAP_ATS_DIS_MAX                                            (0x00000001U)

#define CSL_VMAP_DEFMAP_BDF_MODE_MASK                                          (0x00080000U)
#define CSL_VMAP_DEFMAP_BDF_MODE_SHIFT                                         (0x00000013U)
#define CSL_VMAP_DEFMAP_BDF_MODE_MAX                                           (0x00000001U)

#define CSL_VMAP_DEFMAP_DEF_ATYPE_MASK                                         (0x00030000U)
#define CSL_VMAP_DEFMAP_DEF_ATYPE_SHIFT                                        (0x00000010U)
#define CSL_VMAP_DEFMAP_DEF_ATYPE_MAX                                          (0x00000003U)

#define CSL_VMAP_DEFMAP_DEF_VID_MASK                                           (0x00000FFFU)
#define CSL_VMAP_DEFMAP_DEF_VID_SHIFT                                          (0x00000000U)
#define CSL_VMAP_DEFMAP_DEF_VID_MAX                                            (0x00000FFFU)

/* OB_VIRTID_MATCH */

#define CSL_VMAP_OB_VIRTID_MATCH_VAL_MASK                                      (0x00000FE0U)
#define CSL_VMAP_OB_VIRTID_MATCH_VAL_SHIFT                                     (0x00000005U)
#define CSL_VMAP_OB_VIRTID_MATCH_VAL_MAX                                       (0x0000007FU)

#ifdef __cplusplus
}
#endif
#endif