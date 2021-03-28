/*
 * mcasp_dma.c
 *
 * This file contains local functions for McASP driver which contain implemen-
 * tation for UDMA operation specifc calls like starting an UDMA transfer for
 * for McASP peripheral, UDMA completion and/or error callbacks etc
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   V1/mcasp_dma.c
 *
 *  \brief  This files contains the edma functions required for the Mcasp driver
 *          to function in the UDMA mode.
 *
 *   (C) Copyright 2019, Texas Instruments, Inc
 *
 */

/* ========================================================================== */
/*                             INCLUDE FILES                                  */
/* ========================================================================== */

#include <ti/csl/cslr_device.h>
#include <ti/csl/cslr_device.h>
#include <ti/drv/mcasp/mcasp_drv.h>
#include <ti/drv/mcasp/mcasp_osal.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <include/McaspLocal.h>
#include <ti/csl/csl_psilcfg.h>
#include <ti/drv/udma/udma.h>
#include <ti/osal/osal.h>

/* Enable the below to enable emuwait trap while debugging */
#ifdef MCASP_ENABLE_DEBUG_ERR_TRAP
volatile uint32_t mcasp_drv_emuwait=1;
#define MCASP_DEBUG_ERR_TRAP   while(mcasp_drv_emuwait);
#else
#define MCASP_DEBUG_ERR_TRAP 
#endif


typedef uintptr_t physptr_t;

#define VirtToPhys(x) ((physptr_t)(uint64_t)(x))
#define PhysToVirt(x) ((void *)(physptr_t)(x))

extern Mcasp_TempBuffer Mcasp_muteBuf[MCASP_CNT];


int32_t Mcasp_enableUDMA_PDMA_Channel(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object       *instHandle;
    int32_t retVal=UDMA_SOK;
    Mcasp_dmaInfo_t     *pDmaInfo;
    Udma_ChPdmaPrms     pdmaPrms;
    Udma_ChHandle    udmaChHandle;
    
    instHandle = (Mcasp_Object *)chanHandle->devHandle;
    pDmaInfo = &(instHandle->hwInfo.dmaInfo);
    
    if (MCASP_OUTPUT == chanHandle->mode) 
    {
       udmaChHandle = pDmaInfo->txChHandle;
    } 
    else
    {
       udmaChHandle = pDmaInfo->rxChHandle;
    }

    UdmaChPdmaPrms_init(&pdmaPrms);
    pdmaPrms.elemSize = chanHandle->roundedWordWidth -1; /* 8-bit/16/24/32 */
    /* Number of elements to transfer per event */
    pdmaPrms.elemCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
    pdmaPrms.fifoCnt    = 0U;
   
    retVal = Udma_chConfigPdma(udmaChHandle, &pdmaPrms);

    if(UDMA_SOK == retVal)
    {
        retVal = Mcasp_enableDMA(chanHandle);
    }

	return retVal;
}

static void Mcasp_udmaTrpdInit(Mcasp_ChannelHandle handle,
                               Udma_ChHandle  chHandle,
                               uint8_t       *pTrpdMem,
                               const void    *bufPtr,
                               uint32_t       length)
{
    Mcasp_ChannelObj   *chanHandle;
    NAVSS_TR_Params    *trParams;
    CSL_UdmapCppi5TRPD *pTrpd = (CSL_UdmapCppi5TRPD *) pTrpdMem;
    uint32_t cqRingNum = Udma_chGetCqRingNum(chHandle);
    uint32_t descType = CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR;

    uint32_t trType=NAVSS_TRTYPE_TR15; /* TR15 by default */
    uint64_t hostAddr;
    uint32_t trpdLength = 16;
    uint32_t aCnt=0;
    uint32_t bCnt=0;
    uint32_t cCnt=0;
    
    int32_t bIndex=0;
    int32_t cIndex=0;
    
    chanHandle = (Mcasp_ChannelObj *)handle;
    trParams = (NAVSS_TR_Params *)&(chanHandle->trParams);
    
    
    aCnt=trParams->hostMemTransferParams.aCnt;
    bCnt=trParams->hostMemTransferParams.bCnt;
    cCnt=trParams->hostMemTransferParams.cCnt;
       
    bIndex=trParams->hostMemTransferParams.bIndex;
    cIndex=trParams->hostMemTransferParams.cIndex;

    hostAddr = (uint64_t)trParams->hostMemTransferParams.hostAddr;
       
    trType=trParams->type;
    /* Setup descriptor */
    CSL_udmapCppi5SetDescType(pTrpd, descType);
    CSL_udmapCppi5TrSetReload(pTrpd, 0U, 0U);
    CSL_udmapCppi5SetPktLen(pTrpd, descType, 1U);       /* Only one TR in TRPD */
    CSL_udmapCppi5SetIds(pTrpd, descType, 0x321,0x3FFFU); /* Flow ID and Packet ID */
    CSL_udmapCppi5SetSrcTag(pTrpd, 0x0025);     /* Not used */
    CSL_udmapCppi5SetDstTag(pTrpd, 0x1234);     /* Not used */
    CSL_udmapCppi5SetReturnPolicy(
        pTrpd,
        descType,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT,   /* Don't care for TR */
        CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_VAL_NO,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL,
        cqRingNum);


    switch(trType) 
    {
     
       case NAVSS_TRTYPE_TR0:
          { 
             CSL_UdmapTR0 *pTr = (CSL_UdmapTR0 *)(pTrpdMem + 16);
             CSL_UdmapTR0 *pTrResp = (CSL_UdmapTR0 *)(pTrpdMem + 2*16);
             
             /* Setup TR */
             pTr->flags    = CSL_FMK(UDMAP_TR_FLAGS_TYPE, trType)                                        |
                             CSL_FMK(UDMAP_TR_FLAGS_STATIC, 0U)                                          |
                             CSL_FMK(UDMAP_TR_FLAGS_EOL, 0U)                                             |   /* NA */
                             CSL_FMK(UDMAP_TR_FLAGS_EVENT_SIZE, CSL_UDMAP_TR_FLAGS_EVENT_SIZE_COMPLETION)|
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                             CSL_FMK(UDMAP_TR_FLAGS_CMD_ID, 0x25U)                                       |   /* This will come back in TR response */
                             CSL_FMK(UDMAP_TR_FLAGS_SA_INDIRECT, 0U)                                     |
                             CSL_FMK(UDMAP_TR_FLAGS_DA_INDIRECT, 0U)                                     |
                             CSL_FMK(UDMAP_TR_FLAGS_EOP, 1U);
                         
              pTr->icnt0 = aCnt;
              pTr->addr  = hostAddr;

                /* Size of TR Packet descriptor */
                trpdLength = 16;
              CSL_udmapCppi5TrSetEntryStride(pTrpd, CSL_UDMAP_CPPI5_TRPD_PKTINFO_RECSIZE_VAL_16B);  /* Setting default to be overwritten later */

              *((uint32_t *)pTrResp) = 0xFFFFFFFFU;

	      }
	      break;

       case NAVSS_TRTYPE_TR1:
          { 
             CSL_UdmapTR1 *pTr = (CSL_UdmapTR1 *)(pTrpdMem + 32);
             CSL_UdmapTR1 *pTrResp = (CSL_UdmapTR1 *)(pTrpdMem + 2*32);
             
                  /* Setup TR */
             pTr->flags    = CSL_FMK(UDMAP_TR_FLAGS_TYPE, trType)                                            |
                             CSL_FMK(UDMAP_TR_FLAGS_STATIC, 0U)                                          |
                             CSL_FMK(UDMAP_TR_FLAGS_EOL, 0U)                                             |   /* NA */
                             CSL_FMK(UDMAP_TR_FLAGS_EVENT_SIZE, CSL_UDMAP_TR_FLAGS_EVENT_SIZE_COMPLETION)|
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                             CSL_FMK(UDMAP_TR_FLAGS_CMD_ID, 0x25U)                                       |   /* This will come back in TR response */
                             CSL_FMK(UDMAP_TR_FLAGS_SA_INDIRECT, 0U)                                     |
                             CSL_FMK(UDMAP_TR_FLAGS_DA_INDIRECT, 0U)                                     |
                             CSL_FMK(UDMAP_TR_FLAGS_EOP, 1U);
                         
              pTr->addr  = hostAddr;
     		  pTr->icnt0 = aCnt;
		      pTr->icnt1 = bCnt;    
		      pTr->dim1  = bIndex;  		
     	  
                /* Size of TR Packet descriptor */
                trpdLength = 32;
              CSL_udmapCppi5TrSetEntryStride(pTrpd, CSL_UDMAP_CPPI5_TRPD_PKTINFO_RECSIZE_VAL_32B);  /* Setting default to be overwritten later */

              *((uint32_t *)pTrResp) = 0xFFFFFFFFU;

	      }
	      break;
	      

       case NAVSS_TRTYPE_TR2:
          { 
             CSL_UdmapTR2 *pTr = (CSL_UdmapTR2 *)(pTrpdMem + 32);
             CSL_UdmapTR2 *pTrResp = (CSL_UdmapTR2 *)(pTrpdMem + 2*32);
             
                  /* Setup TR */
             pTr->flags    = CSL_FMK(UDMAP_TR_FLAGS_TYPE, trType)                                            |
                             CSL_FMK(UDMAP_TR_FLAGS_STATIC, 0U)                                          |
                             CSL_FMK(UDMAP_TR_FLAGS_EOL, 0U)                                             |   /* NA */
                             CSL_FMK(UDMAP_TR_FLAGS_EVENT_SIZE, CSL_UDMAP_TR_FLAGS_EVENT_SIZE_COMPLETION)|
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                             CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                             CSL_FMK(UDMAP_TR_FLAGS_CMD_ID, 0x25U)                                       |   /* This will come back in TR response */
                             CSL_FMK(UDMAP_TR_FLAGS_SA_INDIRECT, 0U)                                     |
                             CSL_FMK(UDMAP_TR_FLAGS_DA_INDIRECT, 0U)                                     |
                             CSL_FMK(UDMAP_TR_FLAGS_EOP, 1U);
                         
              pTr->addr  = hostAddr;
     		  
     		  pTr->icnt0 = aCnt;
		      pTr->icnt1 = bCnt;
		      pTr->icnt2 = cCnt;
		      
		      pTr->dim1  = bIndex;  		
              pTr->dim2  = cIndex;
              
                /* Size of TR Packet descriptor */
                trpdLength = 32;
              CSL_udmapCppi5TrSetEntryStride(pTrpd, CSL_UDMAP_CPPI5_TRPD_PKTINFO_RECSIZE_VAL_32B);  /* Setting default to be overwritten later */
              
              *((uint32_t *)pTrResp) = 0xFFFFFFFFU;

	      }
	      break;
	      
       case NAVSS_TRTYPE_TR15:
          { 
             CSL_UdmapTR15 *pTr = (CSL_UdmapTR15 *)(pTrpdMem + sizeof(CSL_UdmapTR15));
             uint32_t *pTrResp = (uint32_t *) (pTrpdMem + (sizeof(CSL_UdmapTR15) * 2U)); 

             /* Setup TR */
             pTr->flags    = CSL_FMK(UDMAP_TR_FLAGS_TYPE, trType)                                            |
                         CSL_FMK(UDMAP_TR_FLAGS_STATIC, 0U)                                          |
                         CSL_FMK(UDMAP_TR_FLAGS_EOL, 0U)                                             |   /* NA */
                         CSL_FMK(UDMAP_TR_FLAGS_EVENT_SIZE, CSL_UDMAP_TR_FLAGS_EVENT_SIZE_COMPLETION)|
                         CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                         CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                         CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                         CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                         CSL_FMK(UDMAP_TR_FLAGS_CMD_ID, 0x25U)                                       |   /* This will come back in TR response */
                         CSL_FMK(UDMAP_TR_FLAGS_SA_INDIRECT, 0U)                                     |
                         CSL_FMK(UDMAP_TR_FLAGS_DA_INDIRECT, 0U)                                     |
                         CSL_FMK(UDMAP_TR_FLAGS_EOP, 1U);
       
             pTr->icnt0    = length;
             pTr->icnt1    = aCnt;
             pTr->icnt2    = bCnt;
             pTr->icnt3    = cCnt;
             pTr->dim1     = pTr->icnt0;
             pTr->dim2     = (pTr->icnt0 * pTr->icnt1);
             pTr->dim3     = (pTr->icnt0 * pTr->icnt1 * pTr->icnt2);
             pTr->addr     = (uint64_t) hostAddr;
             pTr->fmtflags = 0x00000000U;        /* Linear addressing, 1 byte per elem.
                                             Replace with CSL-FL API */
             pTr->dicnt0   = length;
             pTr->dicnt1   = aCnt;
             pTr->dicnt2   = bCnt;
             pTr->dicnt3   = cCnt;
             pTr->ddim1    = pTr->dicnt0;
             pTr->ddim2    = (pTr->dicnt0 * pTr->dicnt1);
             pTr->ddim3    = (pTr->dicnt0 * pTr->dicnt1 * pTr->dicnt2);
             pTr->daddr    = (uint64_t) hostAddr;
         
                /* Size of TR Packet descriptor */
                trpdLength = 64;

             /* Clear TR response memory */
             *pTrResp = 0xFFFFFFFFU;
         }
        break;
        
       default:
          break;
    }    
       
// #if !defined (__aarch64__)
    CacheP_wbInv((void *)pTrpd, 2 * trpdLength);
// #endif
    return;
}

static void Mcasp_udmaHpdInit(Udma_ChHandle  chHandle,
                             uint8_t       *pHpdMem,
                             const void    *bufPtr,
                             uint32_t       length)
{
    CSL_UdmapCppi5HMPD *pHpd = (CSL_UdmapCppi5HMPD *) pHpdMem;
    uint32_t descType = (uint32_t)CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST;
    uint32_t cqRingNum = Udma_chGetCqRingNum(chHandle);

    /* Setup descriptor */
    CSL_udmapCppi5SetDescType(pHpd, descType);
    CSL_udmapCppi5SetEpiDataPresent(pHpd, FALSE);
    CSL_udmapCppi5SetPsDataLoc(pHpd, 1U);
    CSL_udmapCppi5SetPsDataLen(pHpd, 0U);
    CSL_udmapCppi5SetPktLen(pHpd, descType, length);
    CSL_udmapCppi5SetPsFlags(pHpd, 0U);
    CSL_udmapCppi5SetIds(pHpd, descType, 0x321, 0x3FFFU);
    CSL_udmapCppi5SetSrcTag(pHpd, 0x0025);     /* Not used */
    CSL_udmapCppi5SetDstTag(pHpd, 0x1234);     /* Not used */
    CSL_udmapCppi5SetReturnPolicy(
        pHpd,
        descType,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_VAL_NO,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL,
        cqRingNum);
    CSL_udmapCppi5LinkDesc(pHpd, 0U);
    CSL_udmapCppi5SetBufferAddr(pHpd, (uint64_t) bufPtr);
    CSL_udmapCppi5SetBufferLen(pHpd, length);
    CSL_udmapCppi5SetOrgBufferAddr(pHpd, (uint64_t) bufPtr);
    CSL_udmapCppi5SetOrgBufferLen(pHpd, length);

// #if !defined (__aarch64__)
    CacheP_wbInv((const void *)pHpd, sizeof(CSL_UdmapCppi5HMPD));
// #endif
    return;
}

int32_t Mcasp_submitUdmaPkt(Mcasp_ChannelHandle chanHandle)
{
    int32_t            retVal=UDMA_SOK;
    Udma_ChHandle       udmaChanHandle;
    Mcasp_Object       *instHandle;
    MCASP_Packet       *ioPacket;
    Mcasp_dmaInfo_t      *pDmaInfo;
    uint8_t            *pHpdMem;
    void *buffer;
    size_t size;
    
    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    ioPacket = chanHandle->dataPacket;
    buffer = ioPacket->addr;
    size = ioPacket->size;

    pDmaInfo = &(instHandle->hwInfo.dmaInfo);

    if (chanHandle->mode == MCASP_INPUT)
    {
        udmaChanHandle = pDmaInfo->rxChHandle;
    }
    else /* MCASP_OUTPUT */
    {
        udmaChanHandle = pDmaInfo->txChHandle;
    }

    if(UDMA_SOK == retVal)
    {
       /* Update host packet descriptor */
       Mcasp_descQueueEntry_t *descQueueEntry=NULL;
       descQueueEntry = (Mcasp_descQueueEntry_t *)Osal_Queue_get((&(chanHandle->queueFreeDesc)));
       pHpdMem = (uint8_t *) descQueueEntry->descMem;
       Osal_Queue_put((Osal_Queue_handle(&(chanHandle->queueTransitDesc))),(Osal_Queue_Elem *)descQueueEntry);

        if(pHpdMem!=NULL) {
			
			if(pDmaInfo->descType == CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR) {
				Mcasp_udmaTrpdInit(chanHandle, udmaChanHandle, pHpdMem, buffer, size);
		     } else {
                Mcasp_udmaHpdInit(udmaChanHandle, pHpdMem, buffer, size);
			 }
        } else {
		   MCASP_DEBUG_ERR_TRAP
	    }
       /* Submit TRPD to channel */
       retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(udmaChanHandle), (uint64_t)pHpdMem);
    } else {
		MCASP_DEBUG_ERR_TRAP
	}

    return (retVal);
}

/* ========================================================================== */
/*                         LOCAL FUNCTION PROTOTYPES                          */
/* ========================================================================== */
int32_t Mcasp_freeDmaChannel(Mcasp_ChannelHandle chan_handle)
{
    Mcasp_Object         *instHandle;
    Mcasp_ChannelObj     *chanHandle;
    Udma_ChHandle         udmaChHandle;
    Udma_EventHandle      eventHandle;
    Udma_EventHandle      TdeventHandle;
    int32_t retVal;
    
    chanHandle = (Mcasp_ChannelObj *)chan_handle;
    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    if (MCASP_OUTPUT == chanHandle->mode)
    {
        udmaChHandle = instHandle->hwInfo.dmaInfo.txChHandle;
        eventHandle =  instHandle->hwInfo.dmaInfo.txEventHandle;
        TdeventHandle =  instHandle->hwInfo.dmaInfo.tdTxEventHandle;
    }
    else
    {
        udmaChHandle = instHandle->hwInfo.dmaInfo.rxChHandle;
        eventHandle =  instHandle->hwInfo.dmaInfo.rxEventHandle;
        TdeventHandle =  instHandle->hwInfo.dmaInfo.tdRxEventHandle;
    }

   /* Close the TX channel */
    retVal = Udma_eventUnRegister(eventHandle);
    if (UDMA_SOK == retVal)
    {
        retVal = Udma_eventUnRegister(TdeventHandle);
    }
    if (UDMA_SOK == retVal)
    {
        retVal = Udma_chClose(udmaChHandle);
    }

    return retVal;
}	


/* ========================================================================== */
/*                         Initializes all the descriptors in the queue       */
/* ========================================================================== */
uint32_t Mcasp_getSizeOfTransfer(uint64_t pDesc,uint32_t descType)
{
	uint32_t size=0;
	uint32_t dType;
	
	if( descType ==  CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR)
	{
  	   uint8_t * ptrTRDesc;
  	   uint32_t trStride=0;
  	   uint32_t trType;
  	   
 	   CSL_UdmapCppi5TRPD *cppi5Desc = (CSL_UdmapCppi5TRPD *)((uintptr_t )pDesc);
 	   CSL_UdmapTR15 *genTrDesc;
       
	   dType = CSL_udmapCppi5GetDescType((const void *)cppi5Desc);
	   /* Get the TR type */
	   if(dType !=CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR) 
	   {
		  MCASP_DEBUG_ERR_TRAP 
       }
	   /* Get the beginning of the TR descriptor */
	   trStride = CSL_udmapCppi5TrGetEntryStride(cppi5Desc);
	   if( trStride == CSL_UDMAP_CPPI5_TRPD_PKTINFO_RECSIZE_VAL_16B) {
   	      ptrTRDesc = (uint8_t *)(uintptr_t )pDesc + 16;
	   } else if (trStride == CSL_UDMAP_CPPI5_TRPD_PKTINFO_RECSIZE_VAL_32B) {
  	      ptrTRDesc = (uint8_t *)(uintptr_t )pDesc + 32;
       }  else if (trStride == CSL_UDMAP_CPPI5_TRPD_PKTINFO_RECSIZE_VAL_64B) {
          ptrTRDesc = (uint8_t *)(uintptr_t )pDesc + 64;
	   } else {
  	      ptrTRDesc = (uint8_t *)(uintptr_t )pDesc + 32;		   
	   }
       
       /* Now that we have the beginning of the descriptor, read the flags and find the length */
       /* First find the TR type , 0,1,2 etc by reading the 'flags'*/
		genTrDesc = (CSL_UdmapTR15 *)ptrTRDesc;
		trType = (genTrDesc->flags & CSL_UDMAP_TR_FLAGS_TYPE_MASK) >> CSL_UDMAP_TR_FLAGS_TYPE_SHIFT;
		switch (trType)
		{
			case NAVSS_TRTYPE_TR0:
			 size = genTrDesc->icnt0;
			 break;
			case NAVSS_TRTYPE_TR1:
			 size = genTrDesc->icnt0 * genTrDesc->icnt1;
			 break;
			case NAVSS_TRTYPE_TR2:
			 size = genTrDesc->icnt0 * genTrDesc->icnt1 * genTrDesc->icnt2;
			 break;
			case NAVSS_TRTYPE_TR15:
			 size = genTrDesc->icnt0 * genTrDesc->icnt1 * genTrDesc->icnt2 * genTrDesc->icnt3 ;
			 break;
			 default:
			   size =0;
			   break;
		}
		
	} else if(descType == CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST)
	{
       CSL_UdmapCppi5HMPD *pHmpd;
       pHmpd = (CSL_UdmapCppi5HMPD *)(uintptr_t)pDesc;

       dType = CSL_udmapCppi5GetDescType((const void *)pHmpd);
	   /* Get the TR type */
	   if(dType ==CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST)
       {
          size = (pHmpd->descInfo & CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_MASK) >> CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_SHIFT;
       }   
	}
	
   return(size);
}

static void Mcasp_udmaIsrHandler(Udma_EventHandle eventHandle,
                                 uint32_t         eventType,
                                 void            *appData)
{
   Mcasp_ChannelHandle   chanHandle = (Mcasp_ChannelHandle)appData;
   Mcasp_Object         *instHandle = (Mcasp_Object *)chanHandle->devHandle;
   uint64_t            pDesc = 0;
   CSL_UdmapTdResponse tdResp;
   uint32_t            num_descs=0;
   int32_t status;

    Udma_ChHandle udmaChanHandle;
#if !defined (__aarch64__)
    const void *cqRingMem;
    const void *tdCqRingMem;
#endif

    if (chanHandle->mode == MCASP_INPUT)
    {
        udmaChanHandle = instHandle->hwInfo.dmaInfo.rxChHandle;
#if !defined (__aarch64__)
        cqRingMem      = instHandle->hwInfo.dmaInfo.cqRxRingMem;
        tdCqRingMem    = instHandle->hwInfo.dmaInfo.tdCqRxRingMem;
#endif
    }
    else /* chanHandle->mode == MCASP_OUTPUT) */
    {
        udmaChanHandle = instHandle->hwInfo.dmaInfo.txChHandle;
#if !defined (__aarch64__)
        cqRingMem      = instHandle->hwInfo.dmaInfo.cqTxRingMem;
        tdCqRingMem    = instHandle->hwInfo.dmaInfo.tdCqTxRingMem;
#endif
    }

   do
   {
	   
    if (eventType == UDMA_EVENT_TYPE_TEARDOWN_PACKET)
    {
    #if !defined (__aarch64__)
       CacheP_Inv(tdCqRingMem, sizeof(uint64_t) * instHandle->hwInfo.dmaInfo.ringCnt);
    #endif
        /*
         * Dequeue the descriptor from the RX tear down queue
         * to be re-used for the next transfer
         */
        status = Udma_chDequeueTdResponse(udmaChanHandle, &tdResp);
    }
    else
    {
   #if !defined (__aarch64__)
        CacheP_Inv(cqRingMem, sizeof(uint64_t) * instHandle->hwInfo.dmaInfo.ringCnt);
   #endif
       /*
        * Dequeue the descriptor from the RX completion queue
        * to be re-used for the next transfer
        */
       status = Udma_ringDequeueRaw(Udma_chGetCqRingHandle(udmaChanHandle), &pDesc);
     }
     
     if ((UDMA_SOK == status) && (pDesc != 0))
     {
       Mcasp_descQueueEntry_t *descQueueEntry=NULL;
       
       /* Get a queue entry from the transit descriptor */
       descQueueEntry = (Mcasp_descQueueEntry_t *)Osal_Queue_get((&(chanHandle->queueTransitDesc)));
       descQueueEntry->descMem = (void *)(uintptr_t )pDesc;
       Osal_Queue_put((Osal_Queue_handle(&(chanHandle->queueFreeDesc))),(Osal_Queue_Elem *)descQueueEntry);

     }

     if ((UDMA_SOK == status) && (eventType == UDMA_EVENT_TYPE_DMA_COMPLETION))
     {
         num_descs++;
         Mcasp_commonDmaCallback(chanHandle, status);
     }
   } while(status==UDMA_SOK);  
}

/* ========================================================================== */
/*                          FUNCTION DEFINITIONS                              */
/* ========================================================================== */
/**
 *  \brief  This function is called during channel creation (during open)
 *          This function does the following
 *          1) Request the Xfer (in/out depends on mode) channel to EDMA
 *             driver for this peripheral;
 *          2) Requests the link channels for linking (exclusive for each
 *             direction (tx/rx)
 *
 *  \param  chan_handle  [IN]  pointer to the channel object
 *  \param  hwInfo      [IN]  pointer to Mcasp_HwObj structure
 *
 *  \return  status     MCASP_COMPLETED if is sucess
 *                      error id in case of failure
 *
 */
int32_t Mcasp_setupDmaDuringOpen(Mcasp_ChannelHandle chan_handle, Mcasp_HwObj *hwInfo)
{

    Mcasp_Object         *instHandle;
    Mcasp_ChannelObj     *chanHandle;
    int32_t            retVal=UDMA_EFAIL;
    int32_t            status=MCASP_EBADIO;
    Mcasp_dmaInfo_t    *pDmaInfo;
    Udma_DrvHandle     drvHandle;
    uint32_t           chType;
    Udma_ChPrms        chPrms;
    Udma_ChTxPrms      txPrms;
    Udma_ChRxPrms      rxPrms;
    Udma_EventHandle   eventHandle;
    Udma_EventPrms     eventPrms;

    chanHandle = (Mcasp_ChannelObj *)chan_handle;
    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    /* First packet to be submitted */
    chanHandle->firstPacket  = TRUE;

    if (MCASP_OUTPUT == chanHandle->mode) 
    {

       pDmaInfo  = &(instHandle->hwInfo.dmaInfo);
       drvHandle = (Udma_DrvHandle)(instHandle->hwInfo.dmaHandle);

       /* Init TX channel parameters */
       chType = UDMA_CH_TYPE_PDMA_TX;
       
       UdmaChPrms_init(&chPrms, chType);
       chPrms.peerChNum            = instHandle->hwInfo.dmaTxEventNum;
       chPrms.fqRingPrms.ringMem     = pDmaInfo->txRingMem;
       chPrms.cqRingPrms.ringMem   = pDmaInfo->cqTxRingMem;
       chPrms.tdCqRingPrms.ringMem = pDmaInfo->tdCqTxRingMem;
       chPrms.fqRingPrms.elemCnt     = pDmaInfo->ringCnt;
       chPrms.cqRingPrms.elemCnt     = pDmaInfo->ringCnt;
       chPrms.tdCqRingPrms.elemCnt     = pDmaInfo->ringCnt;

       /* Open TX channel for transmit */
        retVal = Udma_chOpen(drvHandle, pDmaInfo->txChHandle, chType, &chPrms);

       if(UDMA_SOK == retVal)
       {
          UdmaChTxPrms_init(&txPrms, chType);
       	  if(instHandle->hwInfo.dmaInfo.descType == CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR) {
         	txPrms.chanType    = CSL_UDMAP_CHAN_TYPE_REF_TR_RING;
            txPrms.filterEinfo     = TRUE;
            txPrms.filterPsWords   = TRUE;			  
	      }	  
          retVal = Udma_chConfigTx(pDmaInfo->txChHandle, &txPrms);
       }
      /* Register TX ring event callback */
      if(UDMA_SOK == retVal)
      {
         /* Register ring completion callback */
        eventHandle = pDmaInfo->txEventHandle;
        UdmaEventPrms_init(&eventPrms);
        eventPrms.eventType         = UDMA_EVENT_TYPE_DMA_COMPLETION;
        eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
        eventPrms.chHandle          = pDmaInfo->txChHandle;
        eventPrms.masterEventHandle = Udma_eventGetGlobalHandle(drvHandle);
        eventPrms.eventCb           = &Mcasp_udmaIsrHandler;
        eventPrms.appData           = (void *)chanHandle;
        retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
      }
      /* Register TX tear down ring event callback */
      if(UDMA_SOK == retVal)
      {
         /* Register ring completion callback */
         eventHandle = pDmaInfo->tdTxEventHandle;
         UdmaEventPrms_init(&eventPrms);
         eventPrms.eventType         = UDMA_EVENT_TYPE_TEARDOWN_PACKET;
         eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
         eventPrms.chHandle          = pDmaInfo->txChHandle;
         eventPrms.masterEventHandle = Udma_eventGetGlobalHandle(drvHandle);
         eventPrms.eventCb           = &Mcasp_udmaIsrHandler;
         eventPrms.appData           = (void *)chanHandle;
         retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
      }
    } /* if TX */
    
    if (MCASP_INPUT == chanHandle->mode) 
    {
        pDmaInfo  = &(instHandle->hwInfo.dmaInfo);
        drvHandle = (Udma_DrvHandle)(instHandle->hwInfo.dmaHandle);

        /* Init RX channel parameters */
        chType = UDMA_CH_TYPE_PDMA_RX;
        UdmaChPrms_init(&chPrms, chType);
        chPrms.peerChNum            = instHandle->hwInfo.dmaRxEventNum;

        chPrms.fqRingPrms.ringMem     = pDmaInfo->rxRingMem;
        chPrms.cqRingPrms.ringMem   = pDmaInfo->cqRxRingMem;
        chPrms.tdCqRingPrms.ringMem = pDmaInfo->tdCqRxRingMem;
        chPrms.fqRingPrms.elemCnt     = pDmaInfo->ringCnt;
        chPrms.cqRingPrms.elemCnt     = pDmaInfo->ringCnt;
        chPrms.tdCqRingPrms.elemCnt     = pDmaInfo->ringCnt;


        /* Open RX channel for transmit */
        retVal = Udma_chOpen(drvHandle, pDmaInfo->rxChHandle, chType, &chPrms);

        if(UDMA_SOK == retVal)
        {
          UdmaChRxPrms_init(&rxPrms, chType);
          if(instHandle->hwInfo.dmaInfo.descType == CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR) {
         	rxPrms.chanType    = CSL_UDMAP_CHAN_TYPE_REF_TR_RING;
	      }	  
          
          rxPrms.ignoreLongPkts = TRUE;
          retVal = Udma_chConfigRx(pDmaInfo->rxChHandle, &rxPrms);
         }

       /* Register RX ring event callback */
       if(UDMA_SOK == retVal)
       {
          /* Register ring completion callback */
          eventHandle = pDmaInfo->rxEventHandle;
          UdmaEventPrms_init(&eventPrms);
          eventPrms.eventType         = UDMA_EVENT_TYPE_DMA_COMPLETION;
          eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
          eventPrms.chHandle          = pDmaInfo->rxChHandle;
          eventPrms.masterEventHandle = Udma_eventGetGlobalHandle(drvHandle);
          eventPrms.eventCb           = &Mcasp_udmaIsrHandler;
          eventPrms.appData           = (void *)chanHandle;
          retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
       }
       /* Register RX tear down ring event callback */
       if(UDMA_SOK == retVal)
       {
          /* Register ring completion callback */
          eventHandle = pDmaInfo->tdRxEventHandle;
          UdmaEventPrms_init(&eventPrms);
          eventPrms.eventType         = UDMA_EVENT_TYPE_TEARDOWN_PACKET;
          eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
          eventPrms.chHandle          = pDmaInfo->rxChHandle;
          eventPrms.masterEventHandle = Udma_eventGetGlobalHandle(drvHandle);
          eventPrms.eventCb           = &Mcasp_udmaIsrHandler;
          eventPrms.appData           = (void *)chanHandle;
          retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
       }
    } /* if RX */

    if (UDMA_SOK == retVal)
    {
       /* Enable UDMA after configuring PDMA */      
       retVal = Mcasp_enableUDMA_PDMA_Channel(chanHandle);
    }
    
    if (UDMA_SOK == retVal)
    {
        status = MCASP_COMPLETED;
    }
    else
    {
        status = MCASP_EBADIO;
    }
    return(status);
 }

/**
 *  \brief  This function does the following
 *          1) set up the param set of main xfer channel (for loopjob transfers)
 *          2) set up the param sets of all link channel (for loopjob transfers)
 *          3) link the last link channel to itself (this channel will be linked
 *             to  main xfer channel later and to supply the loopjob xfer
 *            information infinely this is done so; other link channels are
 *            setup here just for completion sake
 *
 *  \param  chanHandle [IN]  Handle to the mcasp channel
 *
 *  \return MCASP_COMPLETED if is success
 *          Error id if failed
 *
 */
int32_t Mcasp_setupDmaChan(Mcasp_ChannelHandle chanHandle)
{
    int32_t                status      = MCASP_COMPLETED;

    if(!((NULL != chanHandle) && (NULL != chanHandle->devHandle)))
    {
		status = MCASP_EBADARGS;
    }
    return status;
}

/*!
 *  \brief  This function updates the TR descriptor with data or
 *          loopjobbuffer. This uses properly maintained index to idendtify to
 *          what TR the info has to be updated.
 *
 *  \param  chanHandle  [IN]  Handle to the mcasp channel
 *  \param  ioPacket    [IN]  Pointer to I/O packet
 *
 *  \return MCASP_COMPLETED in case of sucess
 *          else Error code in case of failure
 *
 */
int32_t Mcasp_submitPktToDma(Mcasp_ChannelHandle       chanHandle,
                                    MCASP_Packet *const         ioPacket)
{
    Mcasp_Object         *instHandle  = NULL;
    Bool                  falsewhile  = TRUE;
    Mcasp_PktAddrPayload *payLoad     = NULL;
    int32_t                 status      = MCASP_COMPLETED;
    NAVSS_TR_Params *trParams;
    uint16_t aCnt=0, bCnt=0, cCnt=0;
    uint32_t trType=0;
    int16_t  bIndex=0, cIndex=0;
    uintptr_t host_addr=(uintptr_t)NULL; /* HOst memory address */
    if ( (NULL == ioPacket) || (NULL == chanHandle) || (NULL == chanHandle->devHandle) )
    {
        status = MCASP_EBADARGS;
    }
    else
    {
        do
        {
            falsewhile = FALSE;

            instHandle = (Mcasp_Object *)chanHandle->devHandle;


            /* if at all this is the first packet we will update the main params  *
             * else we will update the link params                                */

        if ((NULL != ioPacket) && (MCASP_COMPLETED == status))
        {
            /* 1) when control comes to this function from submitreq control  *
             *    will surely comeinto the block                              *
             * 2) When control comes to this function from EDMA callback,     *
             *    control will some only if there is fuirther more packets to *
             *     handle                                                     */
            chanHandle->userDataBufferSize = ioPacket->size;
            if (MCASP_INPUT == chanHandle->mode)
            {

                if (TRUE == instHandle->isDataBufferPayloadStructure)
                {
                    payLoad = (Mcasp_PktAddrPayload *)ioPacket->addr;
                    if(NULL != payLoad) {
                      host_addr = (uintptr_t)payLoad->addr;
				    }
                }
                else
                {
                    host_addr = (uintptr_t)ioPacket->addr;
                }

                Mcasp_localGetIndicesSyncType(
                    chanHandle,
                    &bIndex,
                    &cIndex,
                    &aCnt,
                    &bCnt,
                    &cCnt,
                    &trType,
                    FALSE);
            }
            else
            {

#ifndef Mcasp_LOOPJOB_ENABLED
                

#endif
                if (TRUE == chanHandle->bMuteON)
                {
                    /* data buffer is changed to local mutebuffer             */
                    host_addr  =
                        (uintptr_t)&Mcasp_muteBuf[(instHandle->instNum)].scratchBuffer;

                    /* calculation is similar to the loop job buffer          */
                    Mcasp_localGetIndicesSyncType(
                        chanHandle,
                    &bIndex,
                    &cIndex,
                    &aCnt,
                    &bCnt,
                    &cCnt,
                    &trType,
                    TRUE);
                }
                else
                {
                    if (TRUE == instHandle->isDataBufferPayloadStructure)
                    {
                        payLoad = (Mcasp_PktAddrPayload *)ioPacket->addr;
                        if(payLoad != NULL) 
                        {
                          host_addr = (uintptr_t)payLoad->addr;
                        }  
                    }
                    else
                    {
                        host_addr = (uintptr_t)ioPacket->addr;
                    }

                    Mcasp_localGetIndicesSyncType(
                        chanHandle,
                    &bIndex,
                    &cIndex,
                    &aCnt,
                    &bCnt,
                    &cCnt,
                    &trType,
                    FALSE);
                }/*for mute on/off*/
            }


        }

        /* Populate the DMA transfer parameters */
        trParams = (NAVSS_TR_Params *)&(chanHandle->trParams);
        
        trParams->hostMemTransferParams.aCnt = aCnt;
        trParams->hostMemTransferParams.bCnt = bCnt;
        trParams->hostMemTransferParams.cCnt = cCnt;
        
        trParams->hostMemTransferParams.bIndex = bIndex;
        trParams->hostMemTransferParams.cIndex = cIndex;
        
        trParams->hostMemTransferParams.length = ioPacket->size;
        trParams->hostMemTransferParams.hostAddr = (void *)host_addr;
         
       trParams->type = (NAVSS_TR_Type_e)trType;
      
   } while(falsewhile);

   chanHandle->dataPacket = ioPacket;
   Mcasp_submitUdmaPkt(chanHandle);
  } 
    return status;
}

/**
 *  \brief  Mcasp_localGetIndicesSyncType
 *
 *  This function computes the parameters requied to configure EDMA 3 based
 *  on the buffer format seleted while creating the driver.
 *
 *  Entry Criteria : This function expects channel variables such as no of slots
 *                     serializers, length of buffers is updated.
 *
 *  \param    chanHandle       [IN]    Pointer to channel handle
 *  \param    bIndex           [IN]    Pointer to stores computed bIndex
 *  \param    cIndex           [IN]    Pointer to stores computed cIndex
 *  \param    aCnt             [IN]    Pointer to stores computed aCnt
 *  \param    bCnt             [IN]    Pointer to stores computed bCnt
 *  \param    cCnt             [IN]    Pointer to stores computed cCnt
 *  \param    trType           [IN]    Pointer to store the TR Type found
 *  \param    forLoopJobBuf    [IN]    To calucalate above for loopJob or data
 *
 * CAUTION : This function could be called with pointer pointing to EDMA 3
 *           paramset pointer (avoiding couple of variables). Care should be
 *           take to ensure that data types used in EDMA 3 paramset is
 *           consistent with EDMA 3 defined data types.
 *
 *  \return  MCASP_EBADARGS on invalid buffer format, else MCASP_COMPLETED
 */
int32_t Mcasp_localGetIndicesSyncType(Mcasp_ChannelHandle chanHandle,
                                    volatile int16_t     *bIndex,
                                    volatile int16_t     *cIndex,
                                    volatile uint16_t    *aCnt,
                                    volatile uint16_t    *bCnt,
                                    volatile uint16_t    *cCnt,
                                    uint32_t             *trType,
                                    Bool                forLoopJobBuf)
{
    uint32_t  tempSize  = 0x0;
    int32_t   status    = MCASP_COMPLETED;
    Uint16    temp_var  = 0x0U;
    Uint16    aCntByBCnt = 0x0U;

    if(((NULL != chanHandle) && (NULL != bIndex) && (NULL != cIndex)
                    && (NULL != aCnt) && (NULL != bCnt) && (NULL != cCnt)
                    ))
    { 

#ifdef Mcasp_LOOPJOB_ENABLED
    /* Get the size of the buffer to be used. In case of mute command and     *
     * normal IOP we will use the actual size of the buffer. For the loop job *
     * case 1. if internal loop job then the minimum loop job length will be  *
     *         used.                                                          *
     * case 2. user supplied loop job buffer then the user loop job length    *
     *         will be used.                                                  */
    if (((Bool) TRUE == forLoopJobBuf) && ((Bool) FALSE == chanHandle->bMuteON))
    {
        if ((Bool) TRUE == chanHandle->userLoopJob)
        {
            /* use the user supplied buffer length for the EDMA params        */
            tempSize = chanHandle->userLoopJobLength;
        }
        else
        {
            tempSize = chanHandle->loopJobLength;
        }
    }
    else
    {
    tempSize = chanHandle->userDataBufferSize;

    }
#else
    tempSize = chanHandle->userDataBufferSize;
#endif

    /* Get the indices                                                        */
    switch (chanHandle->dataFormat)
    {
        case Mcasp_BufferFormat_1SER_1SLOT:
        case Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            *cCnt = (uint16_t)(tempSize/((*aCnt)*(*bCnt)));
            *bIndex = (int16_t)*aCnt;
            *cIndex = (int16_t)(*aCnt)*(*bCnt);
//            *syncType = EDMA3_DRV_SYNC_AB;
             *trType = NAVSS_TRTYPE_TR2;
            break;
        case Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the acnt hence the division  *
             * result will always be an integer                               */
            aCntByBCnt = ((*aCnt)*(*bCnt));
            *cCnt = (Uint16)(tempSize/ (uint32_t)aCntByBCnt);
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the reuslt will be always an integer*/
            temp_var = (((uint16_t)(tempSize))/(*bCnt));
            *bIndex = (int16_t)(temp_var);
            *cIndex = (int16_t)(*aCnt);
 //           *syncType = EDMA3_DRV_SYNC_AB;
             *trType = NAVSS_TRTYPE_TR2;
            break;
        case Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSlots*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the acnt hence the division  *
             * result will always be an integer                               */
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt = (Uint16)(tempSize / (uint32_t)aCntByBCnt);
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple slots hence the result will be always an integer      */
            temp_var = (((uint16_t)(tempSize))/(*bCnt));
            *bIndex = (int16_t)(temp_var);
            temp_var = ((*aCnt) - (((*bCnt)- ((uint16_t)1u)) * (((uint16_t)(tempSize))/(*bCnt))));
            *cIndex = (int16_t)(temp_var);
  //          *syncType = EDMA3_DRV_SYNC_A;
            *trType = NAVSS_TRTYPE_TR2;

            break;
        case Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED:
            *aCnt = (chanHandle->roundedWordWidth);
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the result will be always an integer*/
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt = (Uint16)(tempSize / (uint32_t)aCntByBCnt);
            temp_var = ((*aCnt) * (*bCnt));
            *cIndex = (int16_t)(temp_var);
   //         *syncType = EDMA3_DRV_SYNC_AB;
               *trType = NAVSS_TRTYPE_TR2;
            break;
        case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1:
            *aCnt =  chanHandle->roundedWordWidth;
            *bCnt =  chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the result will be always an integer*/
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt =  (Uint16)(tempSize/ (uint32_t)aCntByBCnt);
            *bIndex   = (int16_t)(*aCnt);
            temp_var = ((*aCnt) * (*bCnt));
            *cIndex = (int16_t)(temp_var);
    //        *syncType = EDMA3_DRV_SYNC_AB;
            *trType = NAVSS_TRTYPE_TR2;
            break;
        case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the acnt hence the division  *
             * result will always be an integer                               */
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt  = (Uint16)(tempSize/ (uint32_t)aCntByBCnt);
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the result will be always an integer*/
            temp_var = (((uint16_t)(tempSize))/(*bCnt));
            *bIndex = (int16_t)(temp_var);
            *cIndex = (int16_t)(*aCnt);
     //       *syncType = EDMA3_DRV_SYNC_AB;
            *trType = NAVSS_TRTYPE_TR2;
            break;
#if 0
        /* we are unable to support this buffer format because the MCASP gives *
         * tx underrun error.
         * When 2 serializers are configured in 2 slot mode each. The MCASP   *
         * even though it receives two 16 bit samples it considers it as only *
         * one 32 bit sample because of which it will always give an underrun *
         * error. Hence this buffer format cannot be supported                */
        case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_3:
            *aCnt = ((chanHandle->roundedWordWidth) * chanHandle->noOfSerAllocated);
            *bCnt = chanHandle->noOfSlots;
            *cCnt = (tempSize / ((*aCnt) *(*bCnt)));
            *bIndex = (tempSize/(*bCnt));
            *cIndex = ((*aCnt) - (((*bCnt) - 1) * (tempSize/(*bCnt))));
  //        *syncType = EDMA3_DRV_SYNC_A;
            *trType = NAVSS_TRTYPE_TR0;

            break;
#endif
        default:
            status = MCASP_EBADARGS;
               break;
    }

    /* if the loop job buffer being used is the driver internal loop job      *
     * buffer, dont increment the index for it.Same is the case if mute is ON */
    if (TRUE == forLoopJobBuf)
    {
        if ((TRUE == chanHandle->bMuteON) ||
            (FALSE == chanHandle->userLoopJob))
        {
            *bIndex = 0;
            *cIndex = 0;
        }
    }
   }
   else
   {
	   status = MCASP_EBADARGS;
   }
    
   return status;
}

void Mcasp_initChanDmaObj(Mcasp_ChannelHandle chanHandle)
{
    int           i;
    Mcasp_Object *instHandle = (Mcasp_Object *) chanHandle->devHandle;
    void **trpdMem;

    Osal_Queue_construct(&(chanHandle->queueFreeDesc), (void *)NULL);
    Osal_Queue_construct(&(chanHandle->queueTransitDesc), (void *)NULL);

    if (chanHandle->mode == MCASP_INPUT)
    {
        trpdMem = instHandle->hwInfo.dmaInfo.rxHpdMem;
    }
    else /* MCASP_OUTPUT */
    {
        trpdMem = instHandle->hwInfo.dmaInfo.txHpdMem;
    }
    for(i = 0; i < MCASP_NUM_FREE_DESCS; i++)
    {
        chanHandle->freeDescMem[i].descMem = trpdMem[i];
        Osal_Queue_put((Osal_Queue_handle(&(chanHandle->queueFreeDesc))),
                       (Osal_Queue_Elem *)(&chanHandle->freeDescMem[i]));
    }

    /* Number of pending transfers controlled by application and matches the
     * number of rings allocated.
     */
    chanHandle->maxActiveSubmit = instHandle->hwInfo.dmaInfo.ringCnt;
    chanHandle->dmaCallback = NULL;
    chanHandle->udmaEnabled = FALSE;
}

int32_t Mcasp_enableDMA(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object         *instHandle;
    Udma_ChHandle         udmaChHandle;
    instHandle = (Mcasp_Object *)chanHandle->devHandle;
    int32_t retVal = MCASP_COMPLETED;

    if (MCASP_OUTPUT == chanHandle->mode)
    {
        udmaChHandle = instHandle->hwInfo.dmaInfo.txChHandle;
    }
    else
    {
        udmaChHandle = instHandle->hwInfo.dmaInfo.rxChHandle;
    }

    /* We don't want to enable if already enabled */
    if (chanHandle->udmaEnabled != TRUE)
    {
        retVal = Udma_chEnable(udmaChHandle);
        chanHandle->udmaEnabled = TRUE;
    }

    return retVal;
}

int32_t Mcasp_disableDMA(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object         *instHandle;
    Udma_ChHandle         udmaChHandle;
    instHandle = (Mcasp_Object *)chanHandle->devHandle;
    int32_t retVal;

    if (MCASP_OUTPUT == chanHandle->mode)
    {
        udmaChHandle = instHandle->hwInfo.dmaInfo.txChHandle;
    }
    else
    {
        udmaChHandle = instHandle->hwInfo.dmaInfo.rxChHandle;
    }

    retVal = Udma_chDisable(udmaChHandle, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);

    chanHandle->udmaEnabled = FALSE;

    return retVal;
}

void Mcasp_getDmaPosition(Mcasp_ChannelHandle chanHandle, uint32_t *dmaPosition)
{
    uint32_t localbCnt = 0;
    uint32_t localcCnt = 0;

    /* Todo: get UDMA/PDMA parameters */

    *dmaPosition = localcCnt * chanHandle->roundedWordWidth * localbCnt;
}

void Mcasp_clearDmaErrors(Mcasp_ChannelHandle chanHandle)
{
    /* Todo: implement for UDMA */
}

void Mcasp_initiateDummyDMAXfer(Mcasp_ChannelHandle chanHandle)
{
    /* Todo: implement for UDMA */
}

void Mcasp_triggerDMA(Mcasp_ChannelHandle chanHandle)
{
    /* Todo: implement for UDMA */
}
/* ========================================================================== */
/*                             END OF FILE                                    */
/* ========================================================================== */
