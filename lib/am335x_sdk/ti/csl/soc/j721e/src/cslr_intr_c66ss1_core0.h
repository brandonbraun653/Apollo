/********************************************************************
*
* C66SS1_CORE0 INTERRUPT MAP. header file
*
* Copyright (C) 2015-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_C66SS1_CORE0_INTERRUPT_MAP_H_
#define CSLR_C66SS1_CORE0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: C66SS1_CORE0
*/

#define CSLR_C66SS1_CORE0_C66_EVENT_NMI_SYNC_GLUELOGIC_EXT_INTN_GLUE_EXT_INT_LVL_0                 (0U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_0                               (4U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_1                               (5U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_2                               (6U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_3                               (7U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_4                               (8U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_5                               (15U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_6                               (16U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_7                               (17U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_8                               (18U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_9                               (19U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_10                              (20U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_11                              (21U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_12                              (22U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_13                              (23U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_14                              (24U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_15                              (25U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_16                              (26U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_17                              (27U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_18                              (28U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_19                              (29U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_20                              (30U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_21                              (31U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_22                              (32U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_23                              (33U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_24                              (34U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_25                              (35U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_26                              (36U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_27                              (37U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_28                              (38U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_29                              (39U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_30                              (40U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_31                              (41U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_32                              (42U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_33                              (43U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_34                              (44U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_35                              (45U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_36                              (46U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_37                              (47U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_38                              (48U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_39                              (49U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_40                              (50U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_41                              (51U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_42                              (52U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_43                              (53U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_44                              (54U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_45                              (55U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_46                              (56U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_47                              (57U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_48                              (58U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_49                              (59U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_50                              (60U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_51                              (61U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_52                              (62U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_53                              (63U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_54                              (64U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_55                              (65U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_56                              (66U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_57                              (67U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_58                              (68U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_59                              (69U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_60                              (70U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_61                              (71U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_62                              (72U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_63                              (73U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_64                              (74U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_65                              (75U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_66                              (76U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_67                              (77U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_68                              (78U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_69                              (79U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_70                              (80U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_71                              (81U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_72                              (82U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_73                              (83U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_74                              (84U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_75                              (85U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_76                              (86U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_77                              (87U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_78                              (88U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_79                              (89U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_80                              (90U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_81                              (91U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_82                              (92U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_83                              (93U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_84                              (94U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_85                              (95U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_86                              (99U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_87                              (102U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_88                              (103U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_89                              (104U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_90                              (105U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_91                              (106U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_92                              (107U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_93                              (108U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_94                              (109U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_95                              (114U)
#define CSLR_C66SS1_CORE0_C66_EVENT_IN_SYNC_C66SS1_INTROUTER0_OUTL_96                              (115U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_C66SS1_CORE0_INTERRUPT_MAP_H_ */

