/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2008
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

#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/soc/am571x/src/cslr_soc.h>

void CSL_xbarMpuIrqConfigure(Uint32 irqNumIdx, CSL_XbarIrq xbarIrq)
{
    CSL_control_intr_dmaRegs *ctrlCoreIntrDmaReg =
        (CSL_control_intr_dmaRegs *) CSL_MPU_IRQ_DMARQ_CROSSBAR_REGISTERS_REGS;
    uint8_t unlockStatus;
    Uint32 regIdx = (irqNumIdx - 1U) / 2U;
    Uint32 regLsb = (((irqNumIdx - 1U) % 2U) * 16U);
    Uint32 regMsb = regLsb + 16U;

    if((CSL_XBAR_IRQ_MIN < xbarIrq) && (CSL_XBAR_IRQ_MAX > xbarIrq))
    {
        if ((0U < irqNumIdx) && (CSL_MPU_IRQ_XBAR_COUNT >= irqNumIdx))
        {
            unlockStatus = CSL_unlockMmrLock2();
            CSL_FINSR(ctrlCoreIntrDmaReg->MPU_IRQ[regIdx],
                regMsb, regLsb, xbarIrq);
            CSL_lockMmrLock2(unlockStatus);
        }
    }
}

void CSL_xbarIpuIrqConfigure(Uint32 ipuInst, Uint32 irqNumIdx, CSL_XbarIrq xbarIrq)
{
    CSL_control_intr_dmaRegs *ctrlCoreIntrDmaReg =
        (CSL_control_intr_dmaRegs *) CSL_MPU_IRQ_DMARQ_CROSSBAR_REGISTERS_REGS;
    uint8_t unlockStatus;
    Uint32 regIdx = (irqNumIdx - 1U) / 2U;
    Uint32 regLsb = (((irqNumIdx - 1U) % 2U) * 16U);
    Uint32 regMsb = regLsb + 16U;

    if((CSL_XBAR_IRQ_MIN < xbarIrq) && (CSL_XBAR_IRQ_MAX > xbarIrq))
    {
        if ((0U < irqNumIdx) && (CSL_IPU_IRQ_XBAR_COUNT >= irqNumIdx))
        {
            if(1U == ipuInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->IPU1_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
            if(2U == ipuInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->IPU2_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
        }
    }
}

void CSL_xbarDspIrqConfigure(Uint32 dspInst, Uint32 irqNumIdx, CSL_XbarIrq xbarIrq)
{
    CSL_control_intr_dmaRegs *ctrlCoreIntrDmaReg =
        (CSL_control_intr_dmaRegs *) CSL_MPU_IRQ_DMARQ_CROSSBAR_REGISTERS_REGS;
    uint8_t unlockStatus;
    Uint32 regIdx = (irqNumIdx - 1U) / 2U;
    Uint32 regLsb = (((irqNumIdx - 1U) % 2U) * 16U);
    Uint32 regMsb = regLsb + 16U;

    if((CSL_XBAR_IRQ_MIN < xbarIrq) && (CSL_XBAR_IRQ_MAX > xbarIrq))
    {
       if ((0U < irqNumIdx) && (CSL_DSP_IRQ_XBAR_COUNT >= irqNumIdx))
        {
            if(1U == dspInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->DSP1_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
            if(2U == dspInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->DSP2_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
        }
    }
}

void CSL_xbarEveIrqConfigure(Uint32 eveInst, Uint32 irqNumIdx, CSL_XbarIrq xbarIrq)
{
    CSL_control_intr_dmaRegs *ctrlCoreIntrDmaReg =
        (CSL_control_intr_dmaRegs *) CSL_MPU_IRQ_DMARQ_CROSSBAR_REGISTERS_REGS;
    uint8_t unlockStatus;
    Uint32 regIdx = (irqNumIdx - 1U) / 2U;
    Uint32 regLsb = (((irqNumIdx - 1U) % 2U) * 16U);
    Uint32 regMsb = regLsb + 16U;

    if((CSL_XBAR_IRQ_MIN < xbarIrq) && (CSL_XBAR_IRQ_MAX > xbarIrq))
    {
        if ((0U < irqNumIdx) && (CSL_EVE_IRQ_XBAR_COUNT >= irqNumIdx))
        {
            if(1U == eveInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->EVE1_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
            if(2U == eveInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->EVE2_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
            if(3U == eveInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->EVE3_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
            if(4U == eveInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->EVE4_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
        }
    }
}

void CSL_xbarPrussIrqConfigure(Uint32 prussInst, Uint32 irqNumIdx, CSL_XbarIrq xbarIrq)
{
    CSL_control_intr_dmaRegs *ctrlCoreIntrDmaReg =
        (CSL_control_intr_dmaRegs *) CSL_MPU_IRQ_DMARQ_CROSSBAR_REGISTERS_REGS;
    uint8_t unlockStatus;
    Uint32 regIdx = (irqNumIdx - 1U) / 2U;
    Uint32 regLsb = (((irqNumIdx - 1U) % 2U) * 16U);
    Uint32 regMsb = regLsb + 16U;

    if((CSL_XBAR_IRQ_MIN < xbarIrq) && (CSL_XBAR_IRQ_MAX > xbarIrq))
    {
        if ((0U < irqNumIdx) && (CSL_PRUSS_IRQ_XBAR_COUNT >= irqNumIdx))
        {
            if(1U == prussInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->PRUSS1_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
            if(2U == prussInst)
            {
                unlockStatus = CSL_unlockMmrLock2();
                CSL_FINSR(ctrlCoreIntrDmaReg->PRUSS2_IRQ[regIdx],
                    regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
            }
        }
    }
}

void CSL_xbarIrqConfigure(CSL_XbarIrqCpuId cpuId, Uint32 irqNumIdx, CSL_XbarIrq xbarIrq)
{
    CSL_control_intr_dmaRegs *ctrlCoreIntrDmaReg =
        (CSL_control_intr_dmaRegs *) CSL_MPU_IRQ_DMARQ_CROSSBAR_REGISTERS_REGS;
    uint8_t unlockStatus;
    Uint32 regIdx = (irqNumIdx - 1U) / 2U;
    Uint32 regLsb = (((irqNumIdx - 1U) % 2U) * 16U);
    Uint32 regMsb = regLsb + 16U;

    if((CSL_XBAR_IRQ_MIN < xbarIrq) && (CSL_XBAR_IRQ_MAX > xbarIrq))
    {
        switch(cpuId)
        {
            case CSL_XBAR_IRQ_CPU_ID_MPU:
                if ((0U < irqNumIdx) && (CSL_MPU_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->MPU_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_IPU1:
                if ((0U < irqNumIdx) && (CSL_IPU_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->IPU1_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_IPU2:
                if ((0U < irqNumIdx) && (CSL_IPU_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->IPU2_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_DSP1:
                if ((0U < irqNumIdx) && (CSL_DSP_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->DSP1_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_DSP2:
                if ((0U < irqNumIdx) && (CSL_DSP_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->DSP2_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_EVE1:
                if ((0U < irqNumIdx) && (CSL_EVE_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->EVE1_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_EVE2:
                if ((0U < irqNumIdx) && (CSL_EVE_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->EVE2_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_EVE3:
                if ((0U < irqNumIdx) && (CSL_EVE_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->EVE3_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_EVE4:
                if ((0U < irqNumIdx) && (CSL_EVE_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->EVE4_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_PRUSS1:
                if ((0U < irqNumIdx) && (CSL_PRUSS_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->PRUSS1_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            case CSL_XBAR_IRQ_CPU_ID_PRUSS2:
                if ((0U < irqNumIdx) && (CSL_PRUSS_IRQ_XBAR_COUNT >= irqNumIdx))
                {
                    unlockStatus = CSL_unlockMmrLock2();
                    CSL_FINSR(ctrlCoreIntrDmaReg->PRUSS2_IRQ[regIdx],
                        regMsb, regLsb, xbarIrq);
                    CSL_lockMmrLock2(unlockStatus);
                }
                break;

            default:
                break;
        }
    }
}

void CSL_xbarDmaConfigure(CSL_XbarDmaCpuId dmaRegType, Uint32 dmaCrossbarInputNo, Uint32 dmaDreqToMapTo)
{
    CSL_control_intr_dmaRegs *ctrlCoreIntrDmaReg =
        (CSL_control_intr_dmaRegs *) CSL_MPU_IRQ_DMARQ_CROSSBAR_REGISTERS_REGS;
    uint8_t unlockStatus;
    Uint32 regIdx = (dmaDreqToMapTo-1U) / 2U;
    Uint32 regLsb = (((dmaDreqToMapTo-1U)  % 2U) * 16U);
    Uint32 regMsb = regLsb + 16U;

    if((CSL_XBAR_DMA_CROSSBAR_IN_MIN < dmaCrossbarInputNo) && (CSL_XBAR_DMA_CROSSBAR_IN_MAX > dmaCrossbarInputNo))
    {
            if(CSL_XBAR_DMA_CPU_ID_SYSTEM_DMA == dmaRegType)
            {
                
             if((dmaDreqToMapTo >= CSL_XBAR_INST_DMA_SYSTEM_DREQ_0) && (dmaDreqToMapTo <= CSL_XBAR_INST_DMA_SYSTEM_DREQ_126))
               {
                 unlockStatus = CSL_unlockMmrLock2();
                 CSL_FINSR(ctrlCoreIntrDmaReg->DMA_SYSTEM_DREQ[regIdx],regMsb, regLsb, dmaCrossbarInputNo);
                 CSL_lockMmrLock2(unlockStatus);
			   }	
            }

           if(CSL_XBAR_DMA_CPU_ID_EDMA == dmaRegType)
            {
                
             if((dmaDreqToMapTo >= CSL_XBAR_INST_DMA_EDMA_DREQ_0) && (dmaDreqToMapTo <= CSL_XBAR_INST_DMA_EDMA_DREQ_63))
               {
                 unlockStatus = CSL_unlockMmrLock2();
                 CSL_FINSR(ctrlCoreIntrDmaReg->DMA_EDMA_DREQ[regIdx],regMsb, regLsb, dmaCrossbarInputNo);
                 CSL_lockMmrLock2(unlockStatus);
			   }	
            }
			

			if(CSL_XBAR_DMA_CPU_ID_DSP1_DMA == dmaRegType)
            {
                
             if((dmaDreqToMapTo >= CSL_XBAR_INST_DMA_DSP1_DREQ_0) && (dmaDreqToMapTo <= CSL_XBAR_INST_DMA_DSP1_DREQ_19))
               {
                 unlockStatus = CSL_unlockMmrLock2();
                 CSL_FINSR(ctrlCoreIntrDmaReg->DMA_DSP1_DREQ[regIdx],regMsb, regLsb, dmaCrossbarInputNo);
                 CSL_lockMmrLock2(unlockStatus);
			   }	
            }

           if(CSL_XBAR_DMA_CPU_ID_DSP2_DMA == dmaRegType)
            {
                
             if((dmaDreqToMapTo >= CSL_XBAR_INST_DMA_DSP2_DREQ_0) && (dmaDreqToMapTo <= CSL_XBAR_INST_DMA_DSP2_DREQ_19))
               {
                 unlockStatus = CSL_unlockMmrLock2();
                 CSL_FINSR(ctrlCoreIntrDmaReg->DMA_DSP2_DREQ[regIdx],regMsb, regLsb, dmaCrossbarInputNo);
                 CSL_lockMmrLock2(unlockStatus);
			   }	
            }
			
        }
}

