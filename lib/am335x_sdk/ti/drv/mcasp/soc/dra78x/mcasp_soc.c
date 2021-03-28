/*
 * mcasp_soc.c
 *
 * This file contains MCASP IP & driver specifications pertaining to a given SOC (AM572x)
 *
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/* MCASP Driver Includes. */

/* CSL McASP Register Layer */
#include <ti/csl/cslr_mcasp.h>

#include <ti/csl/cslr_device.h>

/*============================================================================*/
/*                           IMPORTED VARIABLES                               */
/*============================================================================*/

/* ========================================================================== */
/*                           MODULE FUNCTIONS                                 */
/* ========================================================================== */
/**
 * \brief   Initializes McASP driver's data structures
 *
 *          This function initializes the McASP driver's data structures
 *          including instance objects and channel objects. This is the
 *          McASP Driver Initialization API which needs to be invoked by
 *          the users to initialize the McASP peripheral. This call is
 *          *mandatory* and should be called before calling any of the
 *          other driver API's.  This can be modified by customers for
 *          their application and configuration.
 *
 * \return  None
 */
#include <mcasp_drv.h>
#include <mcasp_osal.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <include/McaspLocal.h>
#include "string.h"
extern Mcasp_HwInfo       Mcasp_deviceInstInfo[MCASP_CNT];
extern Mcasp_Module_State Mcasp_module;
extern Mcasp_Object       Mcasp_Instances[MCASP_CNT];
extern Mcasp_TempBuffer   Mcasp_muteBuf[MCASP_CNT];

void McaspDevice_init(void)
{
    Int i;

    for (i = 0; i < (int32_t)MCASP_CNT; i++)
    {
        /* have to initialize  ally */
        Mcasp_module.inUse[i] = (Bool)0;    /* FALSE; */
        memset((void *)&Mcasp_Instances[i], 0x0, sizeof(Mcasp_Object));

        Mcasp_module.isrObject[i].isIsrRegistered[0] = (Bool)0;    /* FALSE; */
        Mcasp_module.isrObject[i].isIsrRegistered[1] = (Bool)0;    /* FALSE; */
        Mcasp_module.isrObject[i].chanEnabled[0]     = (Bool)0;/* FALSE; */
        Mcasp_module.isrObject[i].chanEnabled[1]     = (Bool)0;/* FALSE; */
        Mcasp_module.isrObject[i].instHandle         = 0;/* NULL; */
        Mcasp_module.isrObject[i].isrSwiTaskHandle   = 0;  /* NULL; */

        if (i == 0)
        {
            Mcasp_deviceInstInfo[i].ditSupport  = (Bool)1;   /* TRUE; */
            Mcasp_deviceInstInfo[i].baseAddress =
                (CSL_McaspRegs *)SOC_MCASP1_CFG_BASE;
            Mcasp_deviceInstInfo[i].fifoAddress =
                (CSL_AfifoRegs *)(SOC_MCASP1_CFG_BASE + 0x1000U);
            Mcasp_deviceInstInfo[i].dataAddress =
                (CSL_AdataRegs *)SOC_MCASP1_BASE;

            Mcasp_deviceInstInfo[i].numSerializers   = CSL_MCASP_0_NUMSERIALIZERS;
            Mcasp_deviceInstInfo[i].txMuxInEvent=CSL_XBAR_McASP1_IRQ_AXEVT;
            Mcasp_deviceInstInfo[i].rxMuxInEvent=CSL_XBAR_McASP1_IRQ_AREVT;
            Mcasp_deviceInstInfo[i].txMuxOutEvent=MCASP_UNASSIGNED_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].rxMuxOutEvent=MCASP_UNASSIGNED_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].muxNum=MCASP_INVALID_MUX_NUM;
            
#ifdef _TMS320C6X
            Mcasp_deviceInstInfo[i].cpuRxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].cpuTxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].txIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
            Mcasp_deviceInstInfo[i].rxIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
#else
            Mcasp_deviceInstInfo[i].txIntNum = MCASP_UNASSIGNED_INTNUM;
            Mcasp_deviceInstInfo[i].rxIntNum = MCASP_UNASSIGNED_INTNUM;
            Mcasp_deviceInstInfo[i].cpuTxEventNumber =  MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].cpuRxEventNumber =  MCASP_UNASSIGNED_EVENTNUM;
#endif                  
            Mcasp_deviceInstInfo[i].rxDmaEventNumber =
                (uint32_t)CSL_EDMA3_CHA_MCASP0_RX;
            Mcasp_deviceInstInfo[i].txDmaEventNumber =
                (uint32_t)CSL_EDMA3_CHA_MCASP0_TX;
        }
        else if (i == 1)
        {
            Mcasp_deviceInstInfo[i].ditSupport  = (Bool)1;   /* TRUE; */
            Mcasp_deviceInstInfo[i].baseAddress =
                (CSL_McaspRegs *)SOC_MCASP2_CFG_BASE;
            Mcasp_deviceInstInfo[i].fifoAddress =
                (CSL_AfifoRegs *)(SOC_MCASP2_CFG_BASE + 0x1000U);
            Mcasp_deviceInstInfo[i].dataAddress =
                (CSL_AdataRegs *)SOC_MCASP2_BASE;

            Mcasp_deviceInstInfo[i].numSerializers   = CSL_MCASP_1_NUMSERIALIZERS;
            Mcasp_deviceInstInfo[i].txMuxInEvent=CSL_XBAR_McASP2_IRQ_AXEVT;
            Mcasp_deviceInstInfo[i].rxMuxInEvent=CSL_XBAR_McASP2_IRQ_AREVT;
            Mcasp_deviceInstInfo[i].txMuxOutEvent=MCASP_UNASSIGNED_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].rxMuxOutEvent=MCASP_UNASSIGNED_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].muxNum=MCASP_INVALID_MUX_NUM;
            
#ifdef _TMS320C6X
            Mcasp_deviceInstInfo[i].cpuTxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].cpuRxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].txIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
            Mcasp_deviceInstInfo[i].rxIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
#else
            Mcasp_deviceInstInfo[i].txIntNum = MCASP_UNASSIGNED_INTNUM;
            Mcasp_deviceInstInfo[i].rxIntNum = MCASP_UNASSIGNED_INTNUM;
            Mcasp_deviceInstInfo[i].cpuTxEventNumber =  MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].cpuRxEventNumber =  MCASP_UNASSIGNED_EVENTNUM;
#endif                  
            Mcasp_deviceInstInfo[i].rxDmaEventNumber =
                (uint32_t)CSL_EDMA3_CHA_MCASP1_RX;
            Mcasp_deviceInstInfo[i].txDmaEventNumber =
                (uint32_t)CSL_EDMA3_CHA_MCASP1_TX;
        }
        else if (i == 2)
        {
            Mcasp_deviceInstInfo[i].ditSupport  = (Bool)1;   /* TRUE; */
            Mcasp_deviceInstInfo[i].baseAddress =
                (CSL_McaspRegs *)SOC_MCASP3_CFG_BASE;
            Mcasp_deviceInstInfo[i].fifoAddress =
                (CSL_AfifoRegs *)(SOC_MCASP3_CFG_BASE + 0x1000U);
            Mcasp_deviceInstInfo[i].dataAddress =
                (CSL_AdataRegs *)SOC_MCASP3_BASE;

            Mcasp_deviceInstInfo[i].numSerializers   = CSL_MCASP_2_NUMSERIALIZERS;
            Mcasp_deviceInstInfo[i].txMuxInEvent=CSL_XBAR_McASP3_IRQ_AXEVT;
            Mcasp_deviceInstInfo[i].rxMuxInEvent=CSL_XBAR_McASP3_IRQ_AREVT;
            Mcasp_deviceInstInfo[i].txMuxOutEvent=MCASP_UNASSIGNED_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].rxMuxOutEvent=MCASP_UNASSIGNED_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].muxNum=MCASP_INVALID_MUX_NUM;
#ifdef _TMS320C6X
            Mcasp_deviceInstInfo[i].cpuTxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].cpuRxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].txIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
            Mcasp_deviceInstInfo[i].rxIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
#else
            Mcasp_deviceInstInfo[i].txIntNum = MCASP_UNASSIGNED_INTNUM;
            Mcasp_deviceInstInfo[i].rxIntNum = MCASP_UNASSIGNED_INTNUM;
            Mcasp_deviceInstInfo[i].cpuTxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
            Mcasp_deviceInstInfo[i].cpuRxEventNumber = MCASP_UNASSIGNED_EVENTNUM;
#endif                  
            Mcasp_deviceInstInfo[i].rxDmaEventNumber =
                (uint32_t)CSL_EDMA3_CHA_MCASP2_RX;
            Mcasp_deviceInstInfo[i].txDmaEventNumber =
                (uint32_t)CSL_EDMA3_CHA_MCASP2_TX;
        }
    }

    /* intialise the loop job buffers and the mute buffers for all instances  */
#ifdef Mcasp_LOOPJOB_ENABLED
    memset((void *)Mcasp_loopDstBuf, 0x0,
           sizeof(Mcasp_TempBuffer) * MCASP_CNT);
    memset((void *)Mcasp_loopSrcBuf, 0x0,
           sizeof(Mcasp_TempBuffer) * MCASP_CNT);
#else     /* Mcasp_LOOPJOB_ENABLED */
    memset((void *)Mcasp_muteBuf, 0x0,
           sizeof(Mcasp_TempBuffer) * MCASP_CNT);
#endif
}

/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
