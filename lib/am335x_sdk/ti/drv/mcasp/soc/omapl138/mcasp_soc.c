/*
 * mcasp_soc.c
 *
 * This file contains MCASP IP & driver specifications pertaining to a given SOC (OMAPL138)
 *
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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

/* CSL MCASP Register Layer */
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
 *          MCASP Driver Initialization API which needs to be invoked by
 *          the users to initialize the MCASP peripheral. This call is
 *          *mandatory* and should be called before calling any of the
 *          other driver API's.  This can be modified by customers for
 *          their application and configuration.
 *
 * \return  None
 */
#include <mcasp_drv.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <mcasp_osal.h>
#include <include/McaspLocal.h>
#include "string.h"
#define AINTC_EVENTID_AXRINT    (0x00000036)
extern Mcasp_HwInfo Mcasp_deviceInstInfo[MCASP_CNT];
extern Mcasp_Module_State Mcasp_module ;
extern Mcasp_Object Mcasp_Instances[MCASP_CNT];
extern Mcasp_TempBuffer Mcasp_muteBuf[MCASP_CNT];

void McaspDevice_init(void)

    {
        Int i;

        for (i = 0; i < (int32_t)MCASP_CNT; i++)
        {
            /* have to initialize  ally */
            Mcasp_module.inUse[i] = (Bool)0;/* FALSE; */
            memset((void *)&Mcasp_Instances[i], 0x0, sizeof(Mcasp_Object));

            Mcasp_module.isrObject[i].isIsrRegistered[0] = (Bool)0;/* FALSE; */
            Mcasp_module.isrObject[i].isIsrRegistered[1] = (Bool)0;/* FALSE; */
            Mcasp_module.isrObject[i].chanEnabled[0] = (Bool)0;/* FALSE; */
            Mcasp_module.isrObject[i].chanEnabled[1] = (Bool)0;/* FALSE; */
            Mcasp_module.isrObject[i].instHandle = 0;/* NULL; */
            Mcasp_module.isrObject[i].isrSwiTaskHandle = 0;/* NULL; */

            if (i == 0)
            {
                Mcasp_deviceInstInfo[i].ditSupport = (Bool)0;/* FALSE; */
                Mcasp_deviceInstInfo[i].baseAddress =
                    (CSL_McaspRegs *)CSL_MCASP_0_CFG_REGS;
                Mcasp_deviceInstInfo[i].fifoAddress =
                    (CSL_AfifoRegs *)CSL_MCASP_0_FIFO_CFG_REGS;
                Mcasp_deviceInstInfo[i].dataAddress =
                    (CSL_AdataRegs *)CSL_MCASP_0_SLV_REGS;
                Mcasp_deviceInstInfo[i].numSerializers = 16u;
                Mcasp_deviceInstInfo[i].rxDmaEventNumber =
                    (uint32_t)CSL_EDMA3_CHA_MCASP0_RX;
                Mcasp_deviceInstInfo[i].txDmaEventNumber =
                    (uint32_t)CSL_EDMA3_CHA_MCASP0_TX;
    #ifndef BIOS_PWRM_ENABLE
                Mcasp_deviceInstInfo[i].pwrmLpscId =
                (Uint32)7;
    #else
                Mcasp_deviceInstInfo[i].pwrmLpscId =
                    (uint32_t)CSL_LPSC_NUMBER_MCASP_0;
    #endif
                Mcasp_deviceInstInfo[i].pscInstance =
                   1;

            }
            else
            {
                /* do nothing                                                     */
            }
#if defined (_TMS320C6X)
            Mcasp_deviceInstInfo[i].cpuTxEventNumber = CSL_INTC_EVENTID_MCASP0INT;
            Mcasp_deviceInstInfo[i].cpuRxEventNumber = CSL_INTC_EVENTID_MCASP0INT;
            Mcasp_deviceInstInfo[i].txIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
            Mcasp_deviceInstInfo[i].rxIntNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
#else
            Mcasp_deviceInstInfo[i].cpuTxEventNumber = AINTC_EVENTID_AXRINT;
            Mcasp_deviceInstInfo[i].cpuRxEventNumber = AINTC_EVENTID_AXRINT;
            Mcasp_deviceInstInfo[i].txIntNum = AINTC_EVENTID_AXRINT;
            Mcasp_deviceInstInfo[i].rxIntNum = AINTC_EVENTID_AXRINT;
#endif
            /* No mux present */
            Mcasp_deviceInstInfo[i].muxNum=MCASP_INVALID_MUX_NUM;
            Mcasp_deviceInstInfo[i].txMuxInEvent=MCASP_INVALID_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].txMuxOutEvent=MCASP_INVALID_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].rxMuxInEvent=MCASP_INVALID_MUX_EVENTNUM;
            Mcasp_deviceInstInfo[i].rxMuxOutEvent=MCASP_INVALID_MUX_EVENTNUM;
        }

        /* intialise the loop job buffers and the mute buffers for all instances  */
    #ifdef Mcasp_LOOPJOB_ENABLED
        memset((void *)Mcasp_loopDstBuf, 0x0,
               sizeof(Mcasp_TempBuffer) * MCASP_CNT);
        memset((void *)Mcasp_loopSrcBuf, 0x0,
               sizeof(Mcasp_TempBuffer) * MCASP_CNT);
    #endif /* Mcasp_LOOPJOB_ENABLED */
        memset((void *)Mcasp_muteBuf, 0x0,
               sizeof(Mcasp_TempBuffer) * MCASP_CNT);
}

/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
