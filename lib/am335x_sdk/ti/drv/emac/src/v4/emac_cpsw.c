/**
 * @file emac_cpsw.c
 * @brief Contains the CPSW implementon functions for EMAC
 *
 */

/* Copyright (C) {2016 - 2019} Texas Instruments Incorporated - http://www.ti.com/
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

#include <string.h>

#include <ti/csl/cslr_cpgmac_sl.h>
#include <ti/csl/src/ip/cpgmac/V2/cslr_cpgmac_sl.h>
#include <ti/csl/csl_cpgmac_sl.h>
#include <ti/csl/src/ip/emac/V2/csl_cpgmac_sl.h>
#include <ti/csl/csl_cpgmac_slAux.h>
#include <ti/csl/src/ip/emac/V2/csl_cpgmac_slAux.h>
#include <ti/csl/cslr_cpsw.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_cpsw_3g.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_wr.h>
#include <ti/csl/src/ip/cpdma/V0/cslr_cpdma.h>
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_cpswAux.h>
#include <ti/csl/src/ip/cpsw/V3/csl_cpswAux.h>
#include <ti/csl/hw_types.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_cpsw.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>
#include <ti/drv/emac/src/emac_osal.h>
#include <ti/drv/emac/src/emac_drv_log.h>

#define CPSW3G_ECTL_HOSTERR_INTMASK  	(((uint32_t)0x1U) << ((uint32_t)4U))
#define CPSW3G_ECTL_STATPEND_INTMASK    (((uint32_t)0x1U) << ((uint32_t)5U))

/*----INT_PACE_EN Tokens----*/
#define CSL_ECTL_INT_CONTROL_INT_PACE_EN_C0_RX (0x00000001U)
#define CSL_ECTL_INT_CONTROL_INT_PACE_EN_C0_TX (0x00000002U)
#define CSL_ECTL_INT_CONTROL_INT_PACE_EN_C1_RX (0x00000004U)
#define CSL_ECTL_INT_CONTROL_INT_PACE_EN_C1_TX (0x00000008U)
#define CSL_ECTL_INT_CONTROL_INT_PACE_EN_C2_RX (0x00000010U)
#define CSL_ECTL_INT_CONTROL_INT_PACE_EN_C2_TX (0x00000020U)

extern EMAC_Cpsw3gDevice      localDev;


/* Implementations are in the board library for each SOC/DEVICE */
extern int32_t  ENETPHY_Init(ENETPHY_Handle hPhyDev, uint32_t miibase, uint32_t inst, uint32_t PhyMask,
                        uint32_t MLinkMask, uint32_t MdixMask, uint32_t PhyAddr, uint32_t ResetBit, uint32_t MdioBusFreq,
                        uint32_t MdioClockFreq,int32_t verbose);

/*Called every 100 milli Seconds, returns TRUE if there has been a mode change */
extern int32_t ENETPHY_Tic(ENETPHY_Handle hPhyDev, uint32_t* mdioStatus);

/*Called to set Phy mode   */
extern void ENETPHY_SetPhyMode(ENETPHY_Handle hPhyDev,uint32_t PhyMode);

/*Called to Get Phy mode   */
extern uint32_t ENETPHY_GetPhyMode(ENETPHY_Handle hPhyDev);

/*Calls to retreive info after a mode change! */
extern int32_t  ENETPHY_GetDuplex(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetSpeed(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetPhyNum(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetLinked(ENETPHY_Handle hPhyDev);
extern void ENETPHY_LinkChange(ENETPHY_Handle hPhyDev);
extern int32_t  ENETPHY_GetLoopback(ENETPHY_Handle hPhyDev);

/*  Shut Down  */
extern void ENETPHY_Close(ENETPHY_Handle hPhyDev, int32_t Full);




/**< Flag to indicate if the EMAC is already opened.                        */
static uint32_t           openFlag = 0;


extern EMAC_McbV4      emac_mcb;

/* Number of EMAC BDs allocated so far. Shared global variable between the
 * Tx and Rx InitChannel routines.                                          */
uint32_t                  cpswNumBdsAllocated = 0;



/* Defines the num of ports, set using boardType */


/* Queue Helper Functions                                                   */
static EMAC_PKT_DESC_T *EMAC_pqPop( EMAC_PKT_QUEUE_T *pq );
static void EMAC_pqPush( EMAC_PKT_QUEUE_T *pq, EMAC_PKT_DESC_T *pPktHdr );
static void EMAC_pqPushChain( EMAC_PKT_QUEUE_T *pq, EMAC_PKT_DESC_T *pPktHdrFirst, EMAC_PKT_DESC_T *pPktHdrLast, uint32_t Count );
/**********************************************************************
 ********************** BD Management Functions ***********************
 **********************************************************************/
static void EMAC_enqueueTx(EMAC_DescCh *pdc);
static void EMAC_dequeueTx(EMAC_DescCh *pdc, EMAC_Desc *pDescAck);


uint32_t EMAC_cpswStatsRead(uint32_t baseAddr, uint32_t reg);
static void EMAC_cpdmaTxTeardown(uint32_t baseAddr, uint32_t channel);
static void EMAC_cpdmaRxTeardown(uint32_t baseAddr, uint32_t channel);
static void EMAC_cpdmaDMAIntEnable(uint32_t baseAddr, uint32_t value);
static void EMAC_cpdmaDMAIntDisable(uint32_t baseAddr, uint32_t value);
static void EMAC_cpswWrCoreMiscIntEnable(uint32_t baseAddr, uint32_t core,
                         uint32_t value);
static void EMAC_cpswWrCoreMiscIntDisable(uint32_t baseAddr, uint32_t core,
                         uint32_t value);
static void EMAC_cpswWrSetRxIntPerMSec(uint32_t baseAddr, uint32_t core,
                         uint32_t value);
static void EMAC_cpswWrSetIntPacingEnable(uint32_t baseAddr,
                         uint32_t value);
static void EMAC_cpswWrSetIntPrescaler(uint32_t baseAddr,
                         uint32_t value);


/** ============================================================================
 *  @n@b EMAC_pqPop()
 *
 *  @b Description
 *  @n Pop a desc buffer off a queue
 *
 *  @b Arguments
 *  @verbatim
        pq      pointer to packet queue
    @endverbatim
 *
 *  <b> Return Value </b>  Pointer to EMAC packet
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Descriptor buffer from the Queue is removed
 *
 *  @b Example
 *  @verbatim
        EMAC_PKT_QUEUE_T *pq;
        EMAC_pqPop( pq );
    @endverbatim
 * ============================================================================
 */
static EMAC_PKT_DESC_T *EMAC_pqPop(EMAC_PKT_QUEUE_T*pq)
{
    EMAC_PKT_DESC_T *pPktHdr = NULL;

    pPktHdr = pq->pHead;

    if (pPktHdr)
    {
        pq->pHead = pPktHdr->pNext;
        pq->Count--;
        pPktHdr->pPrev = pPktHdr->pNext = 0;
    }

    return (pPktHdr);
}

/** ============================================================================
 *  @n@b EMAC_pqPush()
 *
 *  @b Description
 *  @n Push a desc buffer onto a queue
 *
 *  @b Arguments
 *  @verbatim
        pq      pointer to packet queue
        pPktHdr pointer to the EMAC packet
    @endverbatim
 *
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Descriptor buffer from the Queue is added
 *
 *  @b Example
 *  @verbatim
        EMAC_PKT_QUEUE_T *pq;
        EMAC_PKT_DESC_T *pPktHdr

        EMAC_pqPush( pq, pPktHdr );
    @endverbatim
 * ============================================================================
 */
static void EMAC_pqPush(EMAC_PKT_QUEUE_T *pq, EMAC_PKT_DESC_T *pPktHdr)
{
    pPktHdr->pNext = 0;

    if (pq->pHead == NULL)
    {
        /* Queue is empty - Initialize it with this one packet */
        pq->pHead = pPktHdr;
        pq->pTail = pPktHdr;
    }
    else
    {
        /* Queue is not empty - Push onto END */
        pq->pTail->pNext = pPktHdr;
        pq->pTail        = pPktHdr;
    }
    pq->Count++;
}

/** ============================================================================
 *  @n@b EMAC_pqPushChain()
 *
 *  @b Description
 *  @n Push a desc buffer chain onto a queue
 *
 *  @b Arguments
 *  @verbatim
        pq              pointer to packet queue
        pPktHdrFirst    pointer to the first element of the EMAC Packet.
        pPktHdrLast     pointer to the last element of the EMAC Packet.
        Count           count of elements to push
    @endverbatim
 *
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  A chain of descriptor buffers are added to the Queue
 *
 *  @b Example
 *  @verbatim
        EMAC_PKT_QUEUE_T *pq;
        EMAC_PKT_DESC_T *pPktHdrFirst, *pPktHdrLast;
        uint32_t Count;

        EMAC_pqPushChain( pq, pPktHdrFirst, pPktHdrLast, Count );
    @endverbatim
 * ============================================================================
 */
static void EMAC_pqPushChain(EMAC_PKT_QUEUE_T *pq, EMAC_PKT_DESC_T *pPktHdrFirst,
        EMAC_PKT_DESC_T *pPktHdrLast, uint32_t Count)
{
    pPktHdrLast->pNext = 0;

    if (pq->pHead == NULL)
    {
        /* Queue is empty - Initialize it with this packet chain */
        pq->pHead = pPktHdrFirst;
        pq->pTail = pPktHdrLast;
    }
    else
    {
        /* Queue is not empty - Push onto END */
        pq->pTail->pNext = pPktHdrFirst;
        pq->pTail        = pPktHdrLast;
    }
    pq->Count += Count;
}

/** ============================================================================
 *  @n@b EMAC_enqueueTx()
 *
 *  @b Description
 *  @n Enqueue a TX packet and restart transmitter as needed
 *
 *  @b Arguments
 *  @verbatim
        pq  pointer to Channel descriptor
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Enqueue a TX packet and restart transmitter as needed
 *
 *  @b Example
 *  @verbatim
        EMAC_DescCh *pdc;

        EMAC_enqueueTx ( pdc );
    @endverbatim
 * ============================================================================
 */
static void EMAC_enqueueTx( EMAC_DescCh *pdc)
{
    EMAC_Desc       *pDescThis = NULL;
    EMAC_PKT_DESC_T        *pPkt = NULL;
    uint32_t          PktFrags;
    volatile EMAC_Desc       *pStartPtr = NULL;
    volatile EMAC_Desc       *pDescPrev = NULL;
    uint32_t port;

    if (pdc->dmaInProgress == 0U)
    {
        /* pDescWrite is in initialized to 0xffffffff to indicate 1st time tx enqueue, starting point */
        if (pdc->pDescWrite == (EMAC_Desc*)0xffffffffU)
        {
            pdc->pDescWrite = pdc->pDescFirst;
        }
        pStartPtr = pdc->pDescWrite;
        /* Try to post any waiting packets */
        while (pdc->WaitQueue.Count)
        {
            /* See if we have enough room for a new packet */
            pPkt = pdc->WaitQueue.pHead;
            if (pPkt != NULL)
            {
                PktFrags = pPkt->PktFrags;
                /* If we don't have room, break out */
                if ((PktFrags+pdc->DescCount) > pdc->DescMax)
                {
                    break;
                }
                /* The next packet will fit, post it. */
                while (PktFrags)
                {
                    /* Pop the next frag off the wait queue */
                    pPkt = EMAC_pqPop(&pdc->WaitQueue);
                    /* Assign the pointer to "this" desc */
                    pDescThis = pdc->pDescWrite;
                    /* Move the write pointer and bump count */
                    if (pdc->pDescWrite == pdc->pDescLast)
                    {
                        pdc->pDescWrite = pdc->pDescFirst;
                    }
                    else
                    {
                        pdc->pDescWrite++;
                    }
                    /*
                     * If this is the last descriptor, the forward pointer is (void *)0
                     * Otherwise; this desc points to the next desc in the wait queue
                     */
                    if (pdc->WaitQueue.Count == 0)
                    {
                        pDescThis->pNext = NULL;
                    }
                    else
                    {
                        pDescThis->pNext = pdc->pDescWrite;
                    }
                    if (pDescPrev)
                    {
                        pDescPrev->pNext = pDescThis;
                    }
                    pDescThis->pBuffer   = pPkt->pDataBuffer + pPkt->DataOffset;
                    pDescThis->BufOffLen = pPkt->ValidLen;
                    /* clear all the flags prior to setting them */
                    pDescThis->pktFlgLen = 0;
                    if (pPkt->Flags & EMAC_PKT_FLAG_SOP)
                    {
                        pDescThis->pktFlgLen = ((pPkt->Flags&
                                               (EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP))
                                               |pPkt->PktLength | EMAC_BUF_DESC_OWNER);
                    }
                    else
                    {
                        pDescThis->pktFlgLen = (pPkt->Flags & EMAC_PKT_FLAG_EOP)
                                               | EMAC_BUF_DESC_OWNER;
                    }

                    /* For directed packet case, port is specified, need to update TO_PORT_ENABLE and TO_PORT field in the desciptor */
                    port = (pPkt->Flags & EMAC_PKT_FLAG_TO_PORT_MASK) >> EMAC_PKT_FLAG_TO_PORT_SHIFT;
                    if(port != 0)
                    {
                        pDescThis->pktFlgLen |= ((uint32_t)1) << EMAC_PKT_FLAG_TO_PORT_ENABLE_SHIFT;
                        pDescThis->pktFlgLen |= ((uint32_t)port) << EMAC_PKT_FLAG_TO_PORT_SHIFT;
                    }
                    pDescPrev = pDescThis;
                    EMAC_osalCacheWbInv((void*)pPkt->pDataBuffer, pPkt->BufferLen);
                    EMAC_pqPush(&pdc->DescQueue, pPkt);
                    pdc->DescCount++;
                    PktFrags--;
                    }
                }
        }
        
        if (pPkt != NULL)
        {
            /* last descriptor in the chain should have pointer to next descriptor as NULL */
            if (pDescThis)
            {
                pDescThis->pNext = NULL;
            }
            pdc->dmaInProgress = 1;
            HW_SYNC_BARRIER();
            CSL_CPSW_setCpdmaTxHdrDescPtr((CSL_cpdmaHandle) pdc->pd->Config.baseConfig.cpdma_base, ((uint32_t)pStartPtr), pdc->chInfo->chNum);
        }
    }
}

/** ============================================================================
 *  @n@b EMAC_dequeueTx()
 *
 *  @b Description
 *  @n Dequeue all completed TX packets and return buffers to application
 *
 *  @b Arguments
 *  @verbatim
        pdc         pointer to channel descriptor
        pDescAck    pointer to Descriptor object
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Dequeue all completed TX packets and return buffers to application
 *
 *  @b Example
 *  @verbatim
        EMAC_DescCh *pdc;
        EMAC_Desc *pDescAck;

        EMAC_dequeueTx ( pdc, pDescAck );
    @endverbatim
 * ============================================================================
 */
static void EMAC_dequeueTx(EMAC_DescCh *pdc, EMAC_Desc *pDescAck)
{
    EMAC_PKT_DESC_T        *pPkt = NULL;
    int32_t tmp = 1;
    volatile EMAC_Desc * pIterator = NULL;
    volatile EMAC_Desc * pTxCompleteLastDesc = NULL;

    /* Start with Desciptor Ack pointer */
    pIterator = pDescAck;

    while (tmp == 1)
    {
        if ((pIterator->pktFlgLen) & EMAC_BUF_DESC_OWNER)
        {
            tmp = 0;
        }
        else
        {
            /* we now own the packet meaning its been transferred to the port */
            pPkt = EMAC_pqPop(&pdc->DescQueue);
            if (pPkt)
            {
                (pdc->pd->Config.pfcbFreePacket)(pdc->pd->hApplication[0],pPkt, CPSW_NET_CH_DIR_TX);
                pdc->DescCount--;
            }
            pTxCompleteLastDesc = pIterator;
            /* we have EOQ but need to see if any packets chained to this one which will require re-start of transmitter */
            if( pIterator->pktFlgLen & EMAC_PKT_FLAG_EOQ)
            {
                /* whether packets are chained or not, we are finished processing for this interrupt cycle */
                tmp = 0;
                pdc->dmaInProgress = 0;
            }
            /* EOQ is not set, check to see if we chained any descriptors, if we did, continue with loop */
            else
            {
                if(pIterator->pNext)
                {
                    pIterator = pIterator->pNext;
                }
                else
                {
                    tmp = 0;
                }
            }
        }
     }

    /* Ack Tx completion interrupt */
    if (pTxCompleteLastDesc != NULL)
    {
        CSL_CPSW_setCpdmaTxCp((CSL_cpdmaHandle) pdc->pd->Config.baseConfig.cpdma_base, 0U, (uint32_t)pTxCompleteLastDesc);
    }
    /* Try to post any waiting TX packets */
    if ((pdc->WaitQueue.Count != 0U) && (pdc->dmaInProgress == 0U))
    {
        EMAC_enqueueTx( pdc);
    }

}

/** ============================================================================
 *  @n@b EMAC_enqueueRx()
 *
 *  @b Description
 *  @n Fill any empty RX descriptors with new buffers from the application
 *
 *  @b Arguments
 *  @verbatim
        pdc         pointer to Descriptor object
        fRestart    re-fill packet
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Fill any empty RX descriptors with new buffers from the application.
 *
 *  @b Example
 *  @verbatim
        EMAC_DescCh  *pdc;
        uint32_t         fRestart;

        EMAC_enqueueRx( pdc, fRestart );
    @endverbatim
 * ============================================================================
 */
void EMAC_enqueueRx(EMAC_DescCh *pdc, uint32_t fRestart)
{
    EMAC_PKT_DESC_T        *pPkt;
    EMAC_Desc       *pDesc;
    uint32_t            CountOrg;

    /* Keep the old count around */
    CountOrg = pdc->DescCount;

    /* Fill RX Packets Until Full */
    while (pdc->DescCount < pdc->DescMax)
    {
        /* Get a buffer from the application */
        pPkt = (*EMAC_LOCAL_DEVICE->Config.pfcbGetPacket)(pdc->pd->hApplication[0]);

        /* If no more buffers are available, break out of loop */
        if (pPkt == NULL)
        {
            break;
        }
        /* Fill in the descriptor for this buffer */
        pDesc = pdc->pDescWrite;

        /* Move the write pointer and bump count */
        if (pdc->pDescWrite == pdc->pDescLast)
        {
            pdc->pDescWrite = pdc->pDescFirst;
        }
        else
        {
            pdc->pDescWrite++;
        }
        pdc->DescCount++;

        /* Supply buffer pointer with application supplied offset */
        pDesc->pNext     = 0;
        pDesc->pBuffer   = pPkt->pDataBuffer + pPkt->DataOffset;
        pDesc->BufOffLen = 1518;
        pDesc->pktFlgLen = EMAC_BUF_DESC_OWNER;

        /* Make the previous buffer point to us */
        if (pDesc == pdc->pDescFirst)
        {
             pdc->pDescLast->pNext = pDesc;
        }
        else
        {
            (pDesc-1U)->pNext = pDesc;
        }
        /* Push the packet buffer on the local descriptor queue */
        EMAC_osalCacheInv((void*)pPkt->pDataBuffer, pPkt->BufferLen);
        EMAC_pqPush(&pdc->DescQueue, pPkt);
    }

    /* Restart RX if we had ran out of descriptors and got some here */
    if ((fRestart == 1U) && (CountOrg == 0U) && (pdc->DescCount != 0U))
    {
        CSL_CPSW_setCpdmaRxHdrDescPtr((CSL_cpdmaHandle)pdc->pd->Config.baseConfig.cpdma_base, ((uint32_t)pdc->pDescRead), pdc->chInfo->chNum);
    }
}

/** ============================================================================
 *  @n@b EMAC_dequeueRx()
 *
 *  @b Description
 *  @n Dequeue all completed RX packets and give buffers to application
 *
 *  @b Arguments
 *  @verbatim
        pdc         pointer to descriptor channel object
        pDescAck    pointer to the acknowledge
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Dequeue all completed RX packets and give buffers to application
 *
 *  @b Example
 *  @verbatim
        EMAC_DescCh *pdc;
        EMAC_Desc   *pDescAck;

        EMAC_dequeueRx( pdc, pDescAck );
    @endverbatim
 * ============================================================================
 */
void EMAC_dequeueRx(EMAC_DescCh *pdc, const EMAC_Desc *pDescAck)
{
    EMAC_PKT_DESC_T    *pPkt = NULL;
    EMAC_PKT_DESC_T    *pPktNew = NULL;
    EMAC_Desc   *pDescNewRxFirst;
    EMAC_Desc   *pDescNewRxLast=0;
    EMAC_Desc   *pTemp;
    int32_t      tmp;
    uint32_t      pktFlgLen;
    uint32_t tempVar;

    /* Remember the first new descriptor slot */
    pDescNewRxFirst = pdc->pDescWrite;

    /*
     * Pop & Free Buffers 'till the last Descriptor
     * One thing we know for sure is that all the decriptors from
     * the read pointer to pDescAsk are linked to each other via
     * their pNext field.
    */
    tmp = 1;
    while (tmp == 1)
    {
        /* Get the status of this descriptor */
        pktFlgLen = pdc->pDescRead->pktFlgLen;

        /* Bit 16,17 and 18 indicate the port number(ingress)
         * Passcrc bit is always set in the received packets.Clear it before putting the \
         * packet in receive queue */
        pktFlgLen = pktFlgLen & 0xFBFFFFFFU;

        /* Check the ownership of the packet */
        tempVar = pktFlgLen & EMAC_BUF_DESC_OWNER;
        if (tempVar == 0U)
        {
            /* Recover the buffer and free it */
            pPkt = EMAC_pqPop(&pdc->DescQueue);
            if (pPkt != NULL)
            {
                EMAC_osalCacheInv((void*)pPkt->pDataBuffer, pPkt->BufferLen);
                /* Fill in the necessary packet header fields */
                pPkt->Flags = pktFlgLen & 0xFFFF0000U;
                pPkt->ValidLen = pPkt->PktLength = pktFlgLen & 0xFFFFU;
                pPkt->PktChannel = pdc->chInfo->chNum;
                pPkt->PktFrags = 1U;

                /* Pass the packet to the application */
                pPktNew = (*EMAC_LOCAL_DEVICE->Config.pfcbRxPacket)
                                               (pdc->pd->hApplication[0],pPkt);
            }
            /* See if this was the last buffer */
            if (pdc->pDescRead == pDescAck)
            {
                tmp = 0;
            }
            /* Move the read pointer and decrement count */
            if (pdc->pDescRead == pdc->pDescLast)
            {
                pdc->pDescRead = pdc->pDescFirst;
            }
            else
            {
                pdc->pDescRead++;
            }
            pdc->DescCount--;

            /* See if we got a replacement packet */
            if(pPktNew)
            {
                /* We know we can immediately queue this packet */

                /* Fill in the descriptor for this buffer */
                pDescNewRxLast = pdc->pDescWrite;

                /* Move the write pointer and bump count */
                if( pdc->pDescWrite == pdc->pDescLast )
                {
                    pdc->pDescWrite = pdc->pDescFirst;
                }
                else
                {
                    pdc->pDescWrite++;
                }
                pdc->DescCount++;

                /* Supply buffer pointer with application supplied offset */
                pDescNewRxLast->pBuffer   = pPktNew->pDataBuffer + pPktNew->DataOffset;
                pDescNewRxLast->BufOffLen = EMAC_LOCAL_DEVICE->PktMTU;
                pDescNewRxLast->pktFlgLen = EMAC_BUF_DESC_OWNER;

                /* Push the packet buffer on the local descriptor queue */
                EMAC_osalCacheInv((void*)pPktNew->pDataBuffer, pPktNew->BufferLen);
                EMAC_pqPush(&pdc->DescQueue, pPktNew);
            }
        }
        else
        {
            tmp = 0;
        }
    }

    /*
     * If we added descriptors, make the pNext of the last (void *)0, and
     * make the previous descriptor point to the new list we added.
     */
    if (pDescNewRxLast)
    {
        pDescNewRxLast->pNext = 0;

        /* Make the previous buffer point to us */
        if (pDescNewRxFirst == pdc->pDescFirst)
        {
            pTemp = pdc->pDescLast;
        }
        else
        {
            pTemp = pDescNewRxFirst-1;
        }
        /*
         * If these pointers wrapped, the RX engine is stopped
         * Otherwise; tack the new list to the old
         */
        if (pTemp != pDescNewRxLast)
        {
            pTemp->pNext = pDescNewRxFirst;
        }
    }

    /* If the receiver stopped and we have more descriptors, then restart */
    tempVar = pktFlgLen & EMAC_PKT_FLAG_EOQ;
    if ((tempVar != 0U) && (pdc->DescCount != 0U))
    {
       CSL_CPSW_setCpdmaRxHdrDescPtr((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base, (uint32_t)((uint32_t)pdc->pDescRead), pdc->chInfo->chNum);
    }
}

void EMAC_delay(uint32_t delay); /* for misra warning */
void EMAC_delay(uint32_t delay)
{
    volatile uint32_t delay1 = delay;
    while (delay1)
    {
            delay1--;
    }
}
void EMAC_AlePortDisableLoopback(uint32_t base); /* for misra warning */
void EMAC_AlePortDisableLoopback(uint32_t base)
{
    CSL_CPSW_ALE_PORTCONTROL pPortControlInfo;
    CSL_CPSW_disableAle((CSL_cpswHandle) base);
    CSL_CPSW_clearAleTable((CSL_cpswHandle) base);
    /* port into forwarding mode */
    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 0U, &pPortControlInfo);
    pPortControlInfo.portState = ALE_PORTSTATE_DISABLED;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 0U, &pPortControlInfo);
    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 1U, &pPortControlInfo);
    pPortControlInfo.portState = ALE_PORTSTATE_DISABLED;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 1U, &pPortControlInfo);
    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 2U, &pPortControlInfo);
    pPortControlInfo.portState = ALE_PORTSTATE_DISABLED;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 2U, &pPortControlInfo);
}

void EMAC_AleInitLoopback(uint32_t base); /* for misra warning */
void EMAC_AleInitLoopback(uint32_t base)
{
     CSL_CPSW_ALE_PORTCONTROL pPortControlInfo;
     CSL_CPSW_clearAleTable((CSL_cpswHandle) base);
   
     /* enable learning */
     CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 0U, &pPortControlInfo);
     pPortControlInfo.noLearnModeEnable = 0x1U;
     CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 0U, &pPortControlInfo);
     CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 1U, &pPortControlInfo);
     pPortControlInfo.noLearnModeEnable = 0x1U;
     CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 1U, &pPortControlInfo);
     CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 2U, &pPortControlInfo);
     pPortControlInfo.noLearnModeEnable = 0x1U;
     CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 2U, &pPortControlInfo);
     /*add ale entries for port 0,1,2 */
     CSL_CPSW_setAleTableEntry((CSL_cpswHandle) base, 0U, 0xffffffffU, 0xffffffffU, 0x0U);
     CSL_CPSW_setAleTableEntry((CSL_cpswHandle) base, 1U, 0xffffffffU, 0xffffffffU, 0x4U);
     CSL_CPSW_setAleTableEntry((CSL_cpswHandle) base, 2U, 0xffffffffU, 0xffffffffU, 0x8U);
   
     CSL_CPSW_enableAle((CSL_cpswHandle) base);
     /* port into forwarding mode */
     CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 0U, &pPortControlInfo);
     pPortControlInfo.portState = ALE_PORTSTATE_FORWARD;
     CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 0U, &pPortControlInfo);



}

/*link setup for loopback */
uint32_t EMAC_loopbackSetup(const EMAC_Cpsw3GPort *hPort); /* for misra warning */
uint32_t EMAC_loopbackSetup(const EMAC_Cpsw3GPort *hPort)
{
    uint32_t phy_addr=0U, slBase=0U;
    uint32_t val16 = 0U;
    uint32_t debug_data;
    CSL_CPSW_ALE_PORTCONTROL pPortControlInfo;
    ENETPHY_DEVICE phyDev;
    EMAC_HwAttrs_V4 emac_cfg;
    uint32_t port = hPort->portNum;
    uint32_t retVal = CPSW3G_SUCCESS;

    EMAC_socGetInitCfg(0U, &emac_cfg);
    phyDev.miibase = emac_cfg.mdio_base;
    if(port==1U)
    {
        phy_addr = emac_cfg.port[0U].phy_addr;
        slBase = emac_cfg.port[0U].sliver_base;
    }
    else if(port==2U)
    {
        phy_addr = emac_cfg.port[1U].phy_addr;
        slBase = emac_cfg.port[1U].sliver_base;
    }
    else
    {
        retVal = CPSW3G_INVALID_PARAM;
    }

    if (retVal == CPSW3G_SUCCESS)
        {
        /* put port into a disabled state in ale and mac_sl */
        CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) emac_cfg.ss_base, port, &pPortControlInfo);
        pPortControlInfo.portState = ALE_PORTSTATE_DISABLED;
        CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) emac_cfg.ss_base, port, &pPortControlInfo);
    
        CSL_CPGMAC_SL_disableGMII((CSL_cpgmacSlHandle) slBase);
    
        /* set the mac to non-gig mode to start with incase we error out later */
        CSL_CPGMAC_SL_enableGigabit((CSL_cpgmacSlHandle) slBase);
        CSL_CPGMAC_SL_enableFullDuplex((CSL_cpgmacSlHandle) slBase);
        CSL_CPGMAC_SL_disableExtControl((CSL_cpgmacSlHandle) slBase);
    
        EMAC_delay(1000U);


        /* reset phy */
        ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, 0x8000U);
        do
        {
            ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val16);
        } while(val16>>15U);


        /* force phy into desired mode */
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val16);
        val16 &= ~(((uint32_t)1U)<< ((uint32_t)12U));        /*disable auto-negotiate */
        val16 &= ~(((uint32_t)1U)<< ((uint32_t)14U));       /*disable loopback */
    
    
        val16 &= ~(((uint32_t)1U) << ((uint32_t)13U));    /* clear speed LSB */
        val16 |= (((uint32_t)1U)<<((uint32_t)6u));      /*set speed MSB */
        val16 |= (((uint32_t)1U) << ((uint32_t)8U));      /*set duplex bit */
        val16 |= (((uint32_t)1U) << ((uint32_t)14U));     /*set loopback */

        ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, val16);
    
        /*special phy setup for external loopback */
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_1000BT_CONTROL, phy_addr, &debug_data);
        debug_data |= (((uint32_t)1U) << ((uint32_t)12U));     /* Enable master-slave manual configuration */
        debug_data &= ~(((uint32_t)1U) << ((uint32_t)11U));     /*select slave configuration(required for loopback mode) */
        ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_1000BT_CONTROL, phy_addr, debug_data);
    
        EMAC_delay(1000U);

        /* if we made it this far successfully, we can enable mac and ale port now */
        CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) emac_cfg.ss_base, port, &pPortControlInfo);
        pPortControlInfo.portState = ALE_PORTSTATE_FORWARD;
        CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) emac_cfg.ss_base, port, &pPortControlInfo);
        CSL_CPGMAC_SL_enableGMII((CSL_cpgmacSlHandle) slBase);
    }    
    return (retVal);
}
/**********************************************************************
 ***************** Switch Configuration Functions *********************
 **********************************************************************/



/** ============================================================================
 *  @n@b EMAC_cpsw3gSetMacCfg()
 *
 *  @b Description
 *  @n Configures the MAC port settings.
 *
 *  @b Arguments
 *  @verbatim
        hPort       pointer to port object
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Configures the MAC_CONTROL register for the specific port
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpsw3gSetMacCfg(const EMAC_Cpsw3GPort* hPort); /* for misra warning */
static void EMAC_cpsw3gSetMacCfg(const EMAC_Cpsw3GPort* hPort)
{
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    uint32_t portNo = 0U,macNo = 0U;
    EMAC_CPGMacConfig*    lpMacConfign = NULL;

    portNo = hPort->portNum;
    if (portNo > 0U)
    {
        macNo =  portNo - 1U;
    }
    if(portNo > 2U) /* only GMAC port 0 and port 1 are valid */
    {
        /* error condition */
        EMAC_drv_log("Error in SetMacCfg\n");
        /* return without doing anything, you
         * cant dereference past instances 0 & 1
         * of CPGMAC_SL config structures */
    }
    else
    {
        uint32_t macInitCfg = 0U;
        macInitCfg = cpsw3gCfg->macInitCfg[macNo].macModeFlags;
    
        lpMacConfign = &cpsw3gCfg->macInitCfg[macNo];

        EMAC_LOCAL_DEVICE->PktMTU = (cpsw3gCfg->PktMTU);

        if (macInitCfg & EMAC_CPSW_CONFIG_MODEFLG_GIGABIT)
        {
            CSL_CPGMAC_SL_enableGigabit((CSL_cpgmacSlHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.port[macNo].sliver_base);
        }

        if (macInitCfg & EMAC_CPSW_CONFIG_MODEFLG_IFCTLA)
        {
            CSL_CPGMAC_SL_enableIFCTLA((CSL_cpgmacSlHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.port[macNo].sliver_base);
        }
        if (macInitCfg & EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX)
        {
            CSL_CPGMAC_SL_enableFullDuplex((CSL_cpgmacSlHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.port[macNo].sliver_base);
        }
        /* Configure the MDIO params, i.e. speed, duplex */

        if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_NOPHY)
        {
            lpMacConfign->phyMode = NWAY_NOPHY;
        }
        else if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_AUTONEG)
        {
            /* If this MAC port is marked for internal PHY loopback,
             * configure the MDIO parameters appropriately.
             */
            if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_LOOPBACK)
            {
                lpMacConfign->phyMode = NWAY_FD100|NWAY_FD10|NWAY_HD100|NWAY_HD10|NWAY_AUTO;
            }
            else
            {
                 lpMacConfign->phyMode = NWAY_AUTO|NWAY_FD1000|NWAY_FD100|NWAY_FD10|NWAY_HD100|NWAY_HD10;
            }
        }
        else
        {
            if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_HD10)
            {
                lpMacConfign->phyMode = NWAY_HD10;
            }
            if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_FD10)
            {
                lpMacConfign->phyMode |= NWAY_FD10;
            }
            if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_HD100)
            {
                lpMacConfign->phyMode |= NWAY_HD100;
            }
            if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_FD100)
            {
                lpMacConfign->phyMode |= NWAY_FD100;
            }
            if(lpMacConfign->mdioModeFlags & CPSW_MDIO_MODEFLG_FD1000)
            {
                lpMacConfign->phyMode |= NWAY_FD1000;
            }
        }

    }

    return;
}


/** ============================================================================
 *  @n@b EMAC_cpswSetCfg()
 *
 *  @b Description
 *  @n Configures the switch settings based on user configuration.
 *
 *  @b Arguments
 *  @verbatim
 *      None
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Configures the CPSW_STAT_PORT_EN registers
 *      for the DMA port.
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswSetCfg(void); /* for misra warning */
static void EMAC_cpswSetCfg(void)
{
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    /* Local Pointer to Switch Configuration */
    EMAC_Cpsw3GConfig*       lpCpswCfg = &cpsw3gCfg->cpswCfg;
    CSL_CPSW_PORTSTAT       portStatsCfg;

    portStatsCfg.p0StatEnable   =   1U;
    portStatsCfg.p1StatEnable   =   1U;
    portStatsCfg.p2StatEnable   =   1U;

    if (lpCpswCfg->cpswStatModeFlags & CPSW_CONFIG_STAT_ENABLE)
    {
        CSL_CPSW_setPortStatsEnableReg((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base, &portStatsCfg);
    }
}

/** ============================================================================
 *  @n@b EMAC_cpswSetALECfg()
 *
 *  @b Description
 *  @n Configures Address lookup engine (ALE) of EMAC.
 *
 *  @b Arguments
 *  @verbatim
 *      None
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Configures the ALE_CONTROL, ALE_PRESCALE, ALE_UNKNOWN_VLAN registers
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswSetALECfg(void); /* for misra warning */
static void EMAC_cpswSetALECfg(void)
{
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    /* Local Pointer to Ale Configuration */
    EMAC_AleConfig*          lpAleConfig = &cpsw3gCfg->aleCfg;

    CSL_CPSW_clearAleTable((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base);
    CSL_CPSW_enableAle((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base);

    /* Clear out toggle bits */
    lpAleConfig->aleModeFlags &= ~(CPSW_CONFIG_ALE_CLRTABLE
                                 | CPSW_CONFIG_ALE_AGEOUTNOW);

    /* Configure ALE Prescale register */
    CSL_CPSW_setAlePrescaleReg((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base, lpAleConfig->alePrescale);
}

/** ============================================================================
 *  @n@b EMAC_cpswSetALEPortCfg()
 *
 *  @b Description
 *  @n Configures Address lookup engine (ALE) settings for the specific MAC port.
 *
 *  @b Arguments
 *  @verbatim
 *      None
    @endverbatim
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Configures the ALE_PORTCTL register
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswSetALEPortCfg(const EMAC_Cpsw3GPort* hPort); /*for misra waring */
static void EMAC_cpswSetALEPortCfg(const EMAC_Cpsw3GPort* hPort)
{
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    uint32_t portNo = 0;
    /* Local Pointer to AlePort Configuration */
    EMAC_AlePortConfig *lpAlePortConfign = 0;
    CSL_CPSW_ALE_PORTCONTROL portControlInfo;

    portNo = hPort->portNum;
    lpAlePortConfign = &cpsw3gCfg->alePortCfg[portNo];

    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base, portNo, &portControlInfo);
    portControlInfo.portState = (CSL_CPSW_ALE_PORTSTATE) lpAlePortConfign->portState;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base, portNo, &portControlInfo);
}

/** ============================================================================
 *  @n@b EMAC_cpswUpdatePhyStatus()
 *
 *  @b Description
 *  @n This function configures the MACCONTROL register according to the user
 *  defined PHY speed, duplex link settings.
 *
 *  @b Arguments
 *  @verbatim
 *      gmacObject          GMAC Object whose PHY needs to be updated
 *      instanceNum         MAC port identifier
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  Always returns CPSW3G_SUCCESS
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Configures the GMAC_MACCONTROL register
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswUpdatePhyStatus(EMAC_CPGMacObj* gmacObject , uint32_t instanceNum)
{
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    uint32_t              setPhyMode, macControl;
    ENETPHY_Handle      hPhyDev =  &gmacObject->PhyDev;

    setPhyMode = cpsw3gCfg->macInitCfg[instanceNum].phyMode;

    macControl = CSL_CPGMAC_SL_getMacControlReg((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instanceNum].sliver_base);
    /* No Phy Condition */
    if(0U != (setPhyMode & NWAY_NOPHY))
    {
        /* No Phy condition, always linked */
    gmacObject->PhyLinked = 1U;
    gmacObject->PhySpeed = 1U;
    gmacObject->PhyDuplex = 1U;
    gmacObject->PhyNum = 0xFFFFFFFFU;  /* No Phy */

    CSL_CPGMAC_SL_setMacControlReg((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instanceNum].sliver_base, macControl);
    }
    else
    {
        /* If loopback set in hardware, set link to ON */
        if(0u != CSL_CPGMAC_SL_isLoopbackModeEnabled((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instanceNum].sliver_base))
    {
        gmacObject->PhyLinked = 1;
    }
        else
        {
            if(0U != (setPhyMode & NWAY_LPBK))
        {
                gmacObject->PhyLinked = ENETPHY_GetLoopback(hPhyDev);
            }
            else
        {
                gmacObject->PhyLinked = ENETPHY_GetLinked(hPhyDev);
        }

            if (0u != (gmacObject->PhyLinked) )
        {
            /*  Retreive Duplex and Speed and the Phy Number  */
                if (0u != (setPhyMode & NWAY_LPBK))
                {
                    gmacObject->PhyDuplex = EMAC_PHY_FULL_DUPLEX_MODE;
                }
            else
                {
                    gmacObject->PhyDuplex = ENETPHY_GetDuplex(hPhyDev);
            }

                if(gmacObject->PhyDuplex == EMAC_PHY_FULL_DUPLEX_MODE)
                {
                    /* enable full duplex  in mac control*/
                    macControl |= (((uint32_t)1U) << CSL_CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX_SHIFT);
                }
                else
                {
                    /* disable full duplex in mac control */
                    macControl &= ~(((uint32_t)1U) << CSL_CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX_SHIFT);
                }
                gmacObject->PhySpeed  = ENETPHY_GetSpeed(hPhyDev);

                if (gmacObject->PhySpeed != EMAC_PHY_GIGABIT_MODE)
                {
                    gmacObject->PhySpeed = (gmacObject->PhySpeed >> 10U);
                    /* not in gigabit mode, disable it in mac control*/
                    macControl &= ~(((uint32_t)1U) << CSL_CPGMAC_SL_MACCONTROL_REG_GIG_SHIFT);
                }
                else
                {
                    /* in gigabit mode, enable it in mac control*/
                     macControl |= (((uint32_t)1U) << CSL_CPGMAC_SL_MACCONTROL_REG_GIG_SHIFT);
                }

                gmacObject->PhyNum =  ENETPHY_GetPhyNum(hPhyDev);

                if(0U == gmacObject->PhySpeed)
                {
                    macControl |= ((uint32_t)1U) << CSL_CPGMAC_SL_MACCONTROL_REG_CTL_EN_SHIFT;
                }
                else
                {
                    macControl &= ~(((uint32_t)1U) << CSL_CPGMAC_SL_MACCONTROL_REG_CTL_EN_SHIFT);
                }
            }

            /* Write mac control register from stored value */
            CSL_CPGMAC_SL_setMacControlReg((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instanceNum].sliver_base, macControl);
            }
    }

    return (CPSW3G_SUCCESS);
}

/** ============================================================================
 *  @n@b EMAC_cpswControlCb()
 *
 *  @b Description
 *  @n This function is called to update the local copy of device configuration
 *  with the updated Phy status and parameters.
 *
 *  @b Arguments
 *  @verbatim
 *      devPtr              CPSW3G device pointer to be updated
 *      cmd                 Type of update being received. Currently, only one
 *                          supported, i.e. CPSW3G_PHY_STATUS_UPDATE
 *      cmdArg              Command argument, pointer to the updated link parameters
 *      param               Pointer to MAC port object to update.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  Always returns CPSW3G_SUCCESS
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
void EMAC_cpswControlCb(EMAC_Cpsw3gDevice* devPtr,uint32_t cmd,Ptr cmdArg, Ptr param); /* for misra warning */
void EMAC_cpswControlCb(EMAC_Cpsw3gDevice* devPtr,uint32_t cmd,Ptr cmdArg, Ptr param)
{
    static uint32_t linkspeed[2]= {0};
    EMAC_Cpsw3GPort *hPort = (EMAC_Cpsw3GPort*)param;
    EMAC_CPGMacStatus *macStat;

    switch (cmd)
    {
        case CPSW3G_PHY_STATUS_UPDATE:
        {
            macStat = (EMAC_CPGMacStatus*)cmdArg;

            devPtr->Config.linkStatus[hPort->portNum] = macStat->PhyLinked;
            if(0u != (macStat->PhyLinked) )
            {
                devPtr->Config.linkSpeed[hPort->portNum] =
                                                (macStat->PhySpeed == 2) ? 1000000000U :((macStat->PhySpeed)?100000000U : 10000000U);
                devPtr->Config.linkMode[hPort->portNum]  = ((macStat->PhyDuplex) ? 2 : 1);

                if(linkspeed[hPort->portNum]!= devPtr->Config.linkSpeed[hPort->portNum])
                {
                    if(devPtr->Config.linkSpeed[hPort->portNum]== 1000000000U)
                    {
                        devPtr->Config.macInitCfg[hPort->portNum].macModeFlags |= EMAC_CPSW_CONFIG_MODEFLG_GIGABIT;
                    }
                    else
                    {
                        devPtr->Config.macInitCfg[hPort->portNum].macModeFlags &= ~EMAC_CPSW_CONFIG_MODEFLG_GIGABIT;
                    }

                    if(macStat->PhyDuplex == 1U)
                    {
                        devPtr->Config.macInitCfg[hPort->portNum].macModeFlags |= EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX;
                    }
                    else
                    {
                        devPtr->Config.macInitCfg[hPort->portNum].macModeFlags &= ~EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX;
                    }
                }

                linkspeed[hPort->portNum]= devPtr->Config.linkSpeed[hPort->portNum];
            }
            else
            {
                if(  (0U == devPtr->Config.linkStatus[0U] ) && ( 0U == devPtr->Config.linkStatus[1U]) )
                {
                    devPtr->Config.linkSpeed[hPort->portNum] = 100000000U;
                    devPtr->Config.linkMode[hPort->portNum]  = 1U;
                }
            }

            break;
        }
        default:
        {
            break;
        }
    }
}

/** ============================================================================
 *  @n@b EMAC_cpswSetPhyMode()
 *
 *  @b Description
 *  @n This function configures the appropriate registers with updated PHY
 *  settings and notifies a callback function to update the same in our local
 *  configuration copy.
 *
 *  @b Arguments
 *  @verbatim
 *      gmacObject          GMAC Object whose PHY needs to be updated
 *      instanceNum         MAC port identifier
    @endverbatim
 *
 *  <b> Return Value </b>   None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Configures the GMAC_MACCONTROL register and updates the local
 *  config copy to reflect the same.
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswSetPhyMode(EMAC_CPGMacObj* gmacObject,uint32_t instanceNum); /* for misra warning */
static void EMAC_cpswSetPhyMode(EMAC_CPGMacObj* gmacObject,uint32_t instanceNum)
{
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    uint32_t setPhyMode,PhyMode, tempPhyMode;
    EMAC_CPGMacConfig * macInitCfg =  &cpsw3gCfg->macInitCfg[instanceNum];
    ENETPHY_Handle      hPhyDev =  &gmacObject->PhyDev;
    EMAC_CPGMacStatus macStat;

    setPhyMode = macInitCfg->phyMode;
    PhyMode = 0;

    tempPhyMode = NWAY_AUTO | NWAY_FD10 | NWAY_FD100 | NWAY_FD1000
                    | NWAY_HD10 | NWAY_HD100 | NWAY_HD1000 | NWAY_LPBK | NWAY_AUTOMDIX;

    if(0u != (setPhyMode & tempPhyMode))
    {
        PhyMode |= (setPhyMode & tempPhyMode);
    }

    ENETPHY_SetPhyMode(hPhyDev, PhyMode);

    EMAC_cpswUpdatePhyStatus(gmacObject,instanceNum);

    /**CHECK: notify status change thru callback here */
    macStat.PhyDuplex = gmacObject->PhyDuplex;
    macStat.PhyLinked =  gmacObject->PhyLinked;
    macStat.PhyNum = gmacObject->PhyNum;
    macStat.PhySpeed = gmacObject->PhySpeed;


    EMAC_cpswControlCb(EMAC_LOCAL_DEVICE, CPSW3G_PHY_STATUS_UPDATE, &macStat, &EMAC_LOCAL_DEVICE->cpsw3gPort[instanceNum]);
}

/** ============================================================================
 *  @n@b EMAC_cpswEnableChannel()
 *
 *  @b Description
 *  @n This function configures the appropriate registers to initialize a
 *  DMA channel.
 *
 *  @b Arguments
 *  @verbatim
 *      channel             Channel number
 *      direction           Channel Direction, i.e., CPSW_NET_CH_DIR_TX/CPSW_NET_CH_DIR_RX
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Initializes the Tx/Rx HDP and enables interrupts on the specific channel.
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswEnableChannel(uint32_t channel, uint32_t direction); /* for misra warning */
static void EMAC_cpswEnableChannel(uint32_t channel, uint32_t direction)
{
    EMAC_CpdmaObj *dmaObj = &EMAC_LOCAL_DEVICE->cpdma;
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    if(direction == CPSW_NET_CH_DIR_TX)
    {
        /* enable a TX Dma channel for transfers here */

        CSL_CPSW_setCpdmaTxHdrDescPtr((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base, 0, channel);
        CSL_CPSW_enableCpdmaTxInt((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base, channel);
        CSL_CPSW_enableWrTxInt((CSL_wrHandle) cpsw3gCfg->baseConfig.wrpr_base, 0, channel);

       /* mark the channel as open */
        dmaObj->chIsOpen[CPSW_NET_CH_DIR_TX][channel] = TRUE;
    }
    else
    {
        /* enable RX Dma channel for transfer here */
        EMAC_DescCh  *rxChan;
        rxChan = &EMAC_LOCAL_DEVICE->cpdma.rxCppi[channel];
        CSL_CPSW_enableCpdmaRxInt((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base, channel);
        CSL_CPSW_enableWrRxInt((CSL_wrHandle) cpsw3gCfg->baseConfig.wrpr_base, 0, channel);
        /* mark the channel as open */
        dmaObj->chIsOpen[CPSW_NET_CH_DIR_RX][channel] = TRUE;
        /* Init Head Pointer, created the chain in InitRxChannel */

        CSL_CPSW_setCpdmaRxHdrDescPtr((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base, (uint32_t)(rxChan->pDescRead), channel);
    }

}

/** ============================================================================
 *  @n@b EMAC_cpswDisableChannel()
 *
 *  @b Description
 *  @n This function configures the appropriate registers to de-initialize a
 *  DMA channel.
 *
 *  @b Arguments
 *  @verbatim
 *      channel             Channel number
 *      direction           Channel Direction, i.e., CPSW_NET_CH_DIR_TX/CPSW_NET_CH_DIR_RX
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  Always returns CPSW3G_SUCCESS
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  De-Initializes the channel by resetting Tx/Rx HDP and disabling interrupts on
 *  the specific channel.
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static uint32_t EMAC_cpswDisableChannel(uint32_t channel, uint32_t direction); /* for misra warning */
static uint32_t EMAC_cpswDisableChannel(uint32_t channel, uint32_t direction)
{
    EMAC_CpdmaObj    *dmaObj = &EMAC_LOCAL_DEVICE->cpdma;
    uint32_t          Desc = 0;

    dmaObj->tdPending[direction][channel] = TRUE;

    if(direction == CPSW_NET_CH_DIR_TX)
    {
        /* disable the requested Tx DMA channel here */

        /* command teardown  */
        EMAC_cpdmaTxTeardown(EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base, channel);

        /* wait for ack ,examine CP for EMAC_TEARDOWN_DESC (0xfffffffc) */
        do
        {
            CSL_CPSW_getCpdmaTxCp((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base, channel, &Desc);
        } while(Desc != EMAC_TEARDOWN_DESC);


        /*disable Tx Interrupt on this channel */
        CSL_CPSW_disableCpdmaTxInt((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base, channel);

        /* also disable in the wrapper */
        CSL_CPSW_disableWrTxInt((CSL_wrHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.wrpr_base, 0, channel);
    }
    else
    {
        /* disable the requested Rx Dma channel here */

        /* command teardown  */
        EMAC_cpdmaRxTeardown(EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base, channel);

        /* wait for ack ,examine CP for 0xfffffffc */
        do
        {
            CSL_CPSW_getCpdmaRxCp((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base, channel, &Desc);
        } while(Desc != EMAC_TEARDOWN_DESC);

        /*disable Rx Interrupt on this channel */
        CSL_CPSW_disableCpdmaRxInt((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base, channel);

        /* also disable in the wrapper */
        CSL_CPSW_disableWrRxInt((CSL_wrHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.wrpr_base, 0, channel);
    }

    dmaObj->tdPending[direction][channel] = FALSE;
    dmaObj->chIsOpen[direction][channel] = FALSE;

    return (CPSW3G_SUCCESS);
}

/** ============================================================================
 *  @n@b EMAC_cpswInitTxChannel()
 *
 *  @b Description
 *  @n This function sets up the Transmit Buffer descriptors.
 *
 *  @b Arguments
 *  @verbatim
 *      chInfo              Channel object
    @endverbatim
 *
 *  <b> Return Value </b>
 *  CPSW3G_INVALID_PARAM  -   Returned on BD allocation error
 *  CPSW3G_SUCCESS      -   On Success
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Sets up the Tx Buffer descriptors. Tx channel ready for send.
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static uint32_t EMAC_cpswInitTxChannel(EMAC_CpswChInfo *chInfo); /* for misra warning */
static uint32_t EMAC_cpswInitTxChannel(EMAC_CpswChInfo *chInfo)
{
    uint32_t retVal =0U;
    EMAC_CpdmaObj*       dmaObj = &EMAC_LOCAL_DEVICE->cpdma;
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    EMAC_DescCh* txChan = &dmaObj->txCppi[chInfo->chNum];
    EMAC_Desc       *pDesc;

    /* zero init the book keeping structure */
    memset(txChan, 0, sizeof(EMAC_DescCh));

    /* store pointer to channel info structure */
    txChan->chInfo = chInfo;

    /*
     * We give the first descriptors to RX. The rest of the descriptors
     * will be divided evenly among the TX channels. Odds are this
     * will leave TX with a very large number of TX descriptors, but
     * we'll only use what we need (driven from the application send
     * requests). The RX descriptors are always kept fully populated.
     */
    /* Pointer to first descriptor to use on RX */
    pDesc = (EMAC_Desc *)(cpsw3gCfg->baseConfig.cppi_ram_base);
    pDesc += cpswNumBdsAllocated; /* advance to next free BD */

    if((cpswNumBdsAllocated + chInfo->numBD) > EMAC_NUM_TXRX_PKTS(0))
    {
        /* not enough room for the requested number of BDs, fail request */
        EMAC_drv_log3("InitTx Channel : Unable to allocate %d BDs for channel %d.%d BDs already in use\n",
                                chInfo->numBD,chInfo->chNum,cpswNumBdsAllocated);
        retVal = 1U;
    }
    else
    {
        /* Setup Transmit Buffers */
        txChan->pd         = &localDev;
        txChan->DescMax    = chInfo->numBD;
        /*Pointer for first TX desc = pointer to RX + num of RX desc.*/
        txChan->pDescFirst = pDesc;
        txChan->pDescLast  = pDesc + (chInfo->numBD - 1);
        txChan->pDescRead  = pDesc;
        txChan->pDescWrite = (EMAC_Desc*)0xffffffffU;
        txChan->dmaInProgress = 0;

        /* clear the teardown pending flag */
        dmaObj->tdPending[CPSW_NET_CH_DIR_TX][chInfo->chNum] = FALSE;
        /* update the Bd allocation count */
        cpswNumBdsAllocated += chInfo->numBD;
        dmaObj->chIsInit[CPSW_NET_CH_DIR_TX][chInfo->chNum] = TRUE;
    }
    return (retVal);
}

/** ============================================================================
 *  @n@b EMAC_cpswInitRxChannel()
 *
 *  @b Description
 *  @n This function sets up the Receive Buffer descriptors.
 *
 *  @b Arguments
 *  @verbatim
 *      chInfo              Channel object
    @endverbatim
 *
 *  <b> Return Value </b>
 *  CPSW3G_INVALID_PARAM  -   Returned on BD allocation error
 *  CPSW3G_SUCCESS      -   On Success
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Sets up the Rx Buffer descriptors. Rx channel ready for receive.
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static uint32_t EMAC_cpswInitRxChannel(EMAC_CpswChInfo *chInfo); /* for misra warning */
static uint32_t EMAC_cpswInitRxChannel(EMAC_CpswChInfo *chInfo)
{
    uint32_t retVal = CPSW3G_SUCCESS;
    EMAC_CpdmaObj*       dmaObj = &EMAC_LOCAL_DEVICE->cpdma;
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    EMAC_DescCh* rxChan = &dmaObj->rxCppi[chInfo->chNum];
    EMAC_Desc       *pDesc;
    EMAC_PKT_DESC_T*        pPkt;

    /* zero init the book keeping structure */
    memset(rxChan, 0, sizeof(EMAC_DescCh));

    /* store pointer to channel info structure */
    rxChan->chInfo = chInfo;

    /*
     * Setup Receive Buffers
     */
    /*
     * We give the first descriptors to RX. The rest of the descriptors
     * will be divided evenly among the TX channels. Odds are this
     * will leave TX with a very large number of TX descriptors, but
     * we'll only use what we need (driven from the application send
     * requests). The RX descriptors are always kept fully populated.
     */

    /* Pointer to first descriptor to use on RX */
    pDesc = (EMAC_Desc *)(cpsw3gCfg->baseConfig.cppi_ram_base);
    if (retVal == CPSW3G_SUCCESS)
    {
        pDesc += cpswNumBdsAllocated; /* advance to next free BD */
    
        if( (cpswNumBdsAllocated + chInfo->numBD) >  EMAC_NUM_TXRX_PKTS(0))
        {
            /* not enough room for the requested number of BDs, fail request */
            EMAC_drv_log3("InitRx Channel : Unable to allocate %d BDs for channel %d.%d BDs already in use\n",
                    chInfo->numBD,chInfo->chNum,cpswNumBdsAllocated);
            retVal =  CPSW3G_INVALID_PARAM;
        }
        else
        {
            /* Init the Rx channel */
            rxChan->pd         = &localDev;
            rxChan->DescMax    = chInfo->numBD;
            rxChan->pDescFirst = pDesc;
            rxChan->pDescLast  = pDesc + (chInfo->numBD - 1);
            rxChan->pDescRead  = pDesc;
            rxChan->pDescWrite = pDesc;
            rxChan->dmaInProgress = 0;
            /* Fill the descriptor table */
            EMAC_enqueueRx(rxChan, 0);
    
            if (rxChan->DescCount < (chInfo->numBD))
            {
                /* Free all RX descriptors */
                pPkt = EMAC_pqPop( &rxChan->DescQueue);
                while (pPkt)
                {
                    (*EMAC_LOCAL_DEVICE->Config.pfcbFreePacket)(EMAC_LOCAL_DEVICE->hApplication[0], pPkt, CPSW_NET_CH_DIR_RX);
                    pPkt = EMAC_pqPop( &rxChan->DescQueue);
                    /* Return the error condition */
                }
                retVal = CPSW3G_INVALID_PARAM;
            }
            else
            {
                /* clear the teardown pending flag */
                dmaObj->tdPending[CPSW_NET_CH_DIR_RX][chInfo->chNum] = FALSE;
                cpswNumBdsAllocated += chInfo->numBD;
                dmaObj->chIsInit[CPSW_NET_CH_DIR_RX][chInfo->chNum] = TRUE;
            }
        }
    }
    return (retVal);
}

/** ============================================================================
 *  @n@b EMAC_cpswUnInitTxChannel()
 *
 *  @b Description
 *  @n This function frees up the enqueued Transmit Buffer descriptors and the
 *  packets held in any of its queues.
 *
 *  @b Arguments
 *  @verbatim
 *      chInfo              Channel object
    @endverbatim
 *
 *  <b> Return Value </b>
 *  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswUnInitTxChannel(const EMAC_CpswChInfo *chInfo); /* for misra warning */
static void EMAC_cpswUnInitTxChannel(const EMAC_CpswChInfo *chInfo)
{
    EMAC_CpdmaObj*       dmaObj = &EMAC_LOCAL_DEVICE->cpdma;
    EMAC_DescCh* txChan = &dmaObj->txCppi[chInfo->chNum];
    EMAC_PKT_DESC_T*       pPkt;

    pPkt = EMAC_pqPop(&txChan->DescQueue);
    while(pPkt)
    {
        (EMAC_LOCAL_DEVICE->Config.pfcbFreePacket)(EMAC_LOCAL_DEVICE->hApplication[0], pPkt, CPSW_NET_CH_DIR_TX);
         pPkt = EMAC_pqPop( &txChan->DescQueue);
    }

    pPkt = EMAC_pqPop(&txChan->WaitQueue);
    while (pPkt)
    {
        (EMAC_LOCAL_DEVICE->Config.pfcbFreePacket)(EMAC_LOCAL_DEVICE->hApplication[0], pPkt, CPSW_NET_CH_DIR_TX);
        pPkt = EMAC_pqPop(&txChan->WaitQueue);
    }

    dmaObj->chIsInit[CPSW_NET_CH_DIR_TX][chInfo->chNum] = FALSE;

}

/** ============================================================================
 *  @n@b EMAC_cpswUnInitRxChannel()
 *
 *  @b Description
 *  @n This function frees up the enqueued Receive Buffer descriptors and any
 *  packets held in the Rx queue.
 *
 *  @b Arguments
 *  @verbatim
 *      chInfo              Channel object
    @endverbatim
 *
 *  <b> Return Value </b>
 *  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswUnInitRxChannel(const EMAC_CpswChInfo *chInfo); /* for misra warning */
static void EMAC_cpswUnInitRxChannel(const EMAC_CpswChInfo *chInfo)
{
    EMAC_CpdmaObj*       dmaObj = &EMAC_LOCAL_DEVICE->cpdma;
    EMAC_DescCh* rxChan = &dmaObj->rxCppi[chInfo->chNum];
    EMAC_PKT_DESC_T*       pPkt;

    pPkt = EMAC_pqPop(&rxChan->DescQueue);
    while (pPkt)
    {
        (EMAC_LOCAL_DEVICE->Config.pfcbFreePacket)(EMAC_LOCAL_DEVICE->hApplication[0], pPkt, CPSW_NET_CH_DIR_RX);
        pPkt = EMAC_pqPop(&rxChan->DescQueue);
    }
    
    dmaObj->chIsInit[CPSW_NET_CH_DIR_RX][chInfo->chNum] = FALSE;
}

/** ============================================================================
 *  @n@b EMAC_cpswNetChOpen()
 *
 *  @b Description
 *  @n This function opens a data channel on the CPPI DMA engine.
 *
 *  @b Arguments
 *  @verbatim
 *      chInfo              Channel object to setup.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  CPSW3G_SUCCESS          - Channel setup successful
 *  CPSW3G_ERR_CH_ALREADY_INIT  - Channel already initialized
 *  Other error values if Channel init failed.
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static uint32_t  EMAC_cpswNetChOpen(EMAC_CpswChInfo *chInfo); /* for misra warning */
static uint32_t  EMAC_cpswNetChOpen(EMAC_CpswChInfo *chInfo)
{
    uint32_t retVal = CPSW3G_SUCCESS;
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    

    /* Perform sanity checks on input params */
    if( chInfo->chNum >= cpsw3gCfg->dmaInitCfg.numChannels[chInfo->chDir])
    {
        EMAC_drv_log("NetChOpen: Channel number invalid \n");
        retVal = CPSW3G_ERR_CH_INVALID;
    }
    else
    {
        if(EMAC_LOCAL_DEVICE->cpdma.chIsInit[chInfo->chDir][chInfo->chNum] == TRUE)
        {
            EMAC_drv_log2("NetChOpen: %s Channel %d already initialized\n",
                                   ((chInfo->chDir == CPSW_NET_CH_DIR_TX) ? "TX" : "RX"), chInfo->chNum);
            retVal = CPSW3G_ERR_CH_ALREADY_INIT;
        }
        else
        {
            /* Perform book keeping for indv channel */
            if (chInfo->chDir == CPSW_NET_CH_DIR_TX)
            {
                retVal = EMAC_cpswInitTxChannel(chInfo);
            }
            else
            {
                retVal = EMAC_cpswInitRxChannel( chInfo);
            }
            if (retVal != CPSW3G_SUCCESS)
            {
                EMAC_drv_log2("NetChOpen: Error in initializing %s channel %d",
                                       ((chInfo->chDir == CPSW_NET_CH_DIR_TX) ? "TX" : "RX"), chInfo->chNum);
            }
            else
            {
                /* Enable this channel for use */
                EMAC_cpswEnableChannel(chInfo->chNum, chInfo->chDir);
            }
        }
    }
    return (retVal);
}

/** ============================================================================
 *  @n@b EMAC_cpswNetChClose()
 *
 *  @b Description
 *  @n This function closes a previously open data channel on the CPPI DMA engine
 *  and frees up any memory held associated with it.
 *
 *  @b Arguments
 *  @verbatim
 *      chInfo              Channel object to clean up.
    @endverbatim
 *
 *  <b> Return Value </b>
 *          None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpswNetChClose(const EMAC_CpswChInfo *chInfo); /* for misra warning */
static void EMAC_cpswNetChClose(const EMAC_CpswChInfo *chInfo)
{
    EMAC_CpdmaObj *dmaObj = &EMAC_LOCAL_DEVICE->cpdma;

    if(dmaObj->chIsOpen[chInfo->chDir][chInfo->chNum]  == TRUE)
    {
        EMAC_cpswDisableChannel(chInfo->chNum, chInfo->chDir);
    }
    if(dmaObj->chIsInit[chInfo->chDir][chInfo->chNum] == TRUE)
    {
        if(chInfo->chDir == CPSW_NET_CH_DIR_TX)
        {
            EMAC_cpswUnInitTxChannel(chInfo);
        }
        else
        {
            EMAC_cpswUnInitRxChannel(chInfo);
        }
    }
}

/** ============================================================================
 *  @n@b EMAC_cpgmacMacOpen()
 *
 *  @b Description
 *  @n This function opens and sets up a MAC port for communication.
 *
 *  @b Arguments
 *  @verbatim
 *      hPort               Handle to the Port object to setup
    @endverbatim
 *
 *  <b> Return Value </b>   None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpgmacMacOpen(const EMAC_Cpsw3GPort *hPort); /* for misra warning */
static void EMAC_cpgmacMacOpen(const EMAC_Cpsw3GPort *hPort)
{
    EMAC_Cpsw3gInitConfig*    cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    uint32_t                 instId = hPort->portNum -1U ;
    EMAC_CPGMacConfig*    macInitCfg = &cpsw3gCfg->macInitCfg[instId];
    EMAC_CPGMacObj*            gmacObject = &EMAC_LOCAL_DEVICE->cpgmacMac[instId];
    ENETPHY_Handle      hPhyDev =  &gmacObject->PhyDev;
    EMAC_CpswAddrConfig*    tmp;
    uint32_t status;
    uint8_t idx;
    /* Check for valid phy address prior to module reset and phy init */
    if (cpsw3gCfg->baseConfig.port[instId].phy_addr != EMAC_CPSW_NO_PHY_ADDR)
    {
        /* Do a soft reset of the module */
        CSL_CPGMAC_SL_resetMac((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instId].sliver_base);
        status = CSL_CPGMAC_SL_isMACResetDone((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instId].sliver_base);
        while (status == FALSE)
        {
            status = CSL_CPGMAC_SL_isMACResetDone((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instId].sliver_base);
        }
        /* Set MacControl Register */
        EMAC_cpsw3gSetMacCfg(hPort);

        /* Configure Mac Address */
        for (idx = 0; idx < EMAC_LOCAL_DEVICE->Config.totalNumMacAddrs; idx++)
        {
            tmp = &(cpsw3gCfg->MacAddr[idx]);
    
            /* set MAC hardware address */
            CSL_CPSW_setPortMACAddress((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base, instId + 1U, tmp->Addr);
        }
        /**
         * For Dual Mac mode, configure port0 and port1 for one VLAN ID;
         * port0 and port2 for a different VLAN ID. Here we choose the
         * port number as VLAN ID.
         */
        CSL_CPSW_setPortVlanReg((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base, instId + 1U, instId + 1U, 0U, 0U);
    
        /* write rx maxlen register */
        CSL_CPGMAC_SL_setRxMaxLen((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instId].sliver_base, EMAC_LOCAL_DEVICE->PktMTU);
    
    
    
        /*Kick Start MDIO , auto-negn */
        memset(hPhyDev, 0, sizeof(ENETPHY_DEVICE));

        ENETPHY_Init(hPhyDev, cpsw3gCfg->baseConfig.mdio_base, instId, macInitCfg->PhyMask,
                  macInitCfg->MLinkMask, 0,cpsw3gCfg->baseConfig.port[instId].phy_addr, 0,
                  MDIO_FREQ_INPUT, MDIO_FREQ_OUTPUT, 0);
    
        /* set the Phy to given mode based on Config Params */
        EMAC_cpswSetPhyMode(gmacObject,instId);
    
        /* Finally Set the Mac Control register. Enable MII */
        CSL_CPGMAC_SL_enableGMII((CSL_cpgmacSlHandle) cpsw3gCfg->baseConfig.port[instId].sliver_base);
    }
}

/** ============================================================================
 *  @n@b EMAC_cpgmacMacClose()
 *
 *  @b Description
 *  @n This function closes and de-initializes the MAC port.
 *
 *  @b Arguments
 *  @verbatim
 *      hPort               Handle to the Port object to setup
    @endverbatim
 *
 *  <b> Return Value </b>   None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpgmacMacClose(const EMAC_Cpsw3GPort *hPort); /* for misra warning */
static void EMAC_cpgmacMacClose(const EMAC_Cpsw3GPort *hPort)
{
    uint32_t status;
    uint32_t instId = hPort->portNum - 1U;
    if (EMAC_LOCAL_DEVICE->Config.baseConfig.port[instId].phy_addr != EMAC_CPSW_NO_PHY_ADDR)
    {
        /* soft reset */
        CSL_CPGMAC_SL_resetMac((CSL_cpgmacSlHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.port[instId].sliver_base);
        status = CSL_CPGMAC_SL_isMACResetDone((CSL_cpgmacSlHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.port[instId].sliver_base);
        while (status == ((uint32_t)FALSE))
        {
            status = CSL_CPGMAC_SL_isMACResetDone((CSL_cpgmacSlHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.port[instId].sliver_base);
        }
    }
}

/** ============================================================================
 *  @n@b EMAC_cpdmaOpen()
 *
 *  @b Description
 *  @n This function opens and sets up the DMA port and channel for communication.
 *
 *  @b Arguments
 *  @verbatim
 *      hPort               Handle to the Port object to setup
    @endverbatim
 *
 *  <b> Return Value </b>
 *      None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpdmaOpen(EMAC_Cpsw3GPort *hPort); /* for misra warning */
static void EMAC_cpdmaOpen(EMAC_Cpsw3GPort *hPort)
{
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    EMAC_CpdmaConfig*        dmaInitCfg = &cpsw3gCfg->dmaInitCfg;
    EMAC_CpdmaObj*           dmaObj = &EMAC_LOCAL_DEVICE->cpdma;
    uint32_t              channel, dir, status;
    EMAC_HwAttrs_V4 emac_cfg;

    EMAC_socGetInitCfg(0U, &emac_cfg);
    CSL_CPSW_resetCpdma((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base);
    status = CSL_CPSW_isCpdmaResetDone((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base);
    while (status == ((uint32_t)FALSE))
    {
        status = CSL_CPSW_isCpdmaResetDone((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base);
    }
    /* Enable Opened TX Channels */
    for (dir = CPSW_NET_CH_DIR_TX; dir <= CPSW_NET_CH_DIR_RX; dir ++)
    {
        for (channel = 0; channel < EMAC_CPDMA_MAX_CHANNELS; channel++)
        {
            /**CHECK: Normal scenario channel wont be init at this stage */
            if (dmaObj->chIsInit[dir][channel] == TRUE)
            {
                EMAC_cpswEnableChannel(channel, dir);
            }
        }/* end of for channel loop */
    }/* end of for loop over dir */


    CSL_CPSW_setCpdmaRxBufOffset((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base, dmaInitCfg->rxBufferOffset);

    CSL_CPSW_disableCpdmaTxInt((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base, 0);
    CSL_CPSW_disableCpdmaRxInt((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base, 0);

    /* Acknowledge receive and transmit interrupts for proper interrupt pulsing*/
    CSL_CPSW_setCpdmaTxEndOfIntVector((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base);
    CSL_CPSW_setCpdmaRxEndOfIntVector((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base);

    CSL_CPSW_enableCpdmaTx((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base);
    CSL_CPSW_enableCpdmaRx((CSL_cpdmaHandle) cpsw3gCfg->baseConfig.cpdma_base);

    /* Enable Adapter check interrupts - enable stats interupt */
    EMAC_cpdmaDMAIntEnable(cpsw3gCfg->baseConfig.cpdma_base,
        CSL_CPDMA_DMA_INTMASK_SET_HOST_ERR_INT_MASK_MASK |CSL_CPDMA_DMA_INTMASK_SET_STAT_INT_MASK_MASK);

    /* enable host,stats interrupt in cpsw_3gss_s wrapper */
    EMAC_cpswWrCoreMiscIntEnable(cpsw3gCfg->baseConfig.wrpr_base, 0,
        CPSW3G_ECTL_HOSTERR_INTMASK | CPSW3G_ECTL_STATPEND_INTMASK);

    if (emac_cfg.rxInterruptPerMSec)
    {
        /* enable Interrupt Pacing Logic in the Wrapper */
        EMAC_cpswWrSetRxIntPerMSec(cpsw3gCfg->baseConfig.wrpr_base, 0U, emac_cfg.rxInterruptPerMSec);
        EMAC_cpswWrSetIntPacingEnable(cpsw3gCfg->baseConfig.wrpr_base,  CSL_ECTL_INT_CONTROL_INT_PACE_EN_C0_RX);
        EMAC_cpswWrSetIntPrescaler(cpsw3gCfg->baseConfig.wrpr_base, 0x370U);
    }
}

/** ============================================================================
 *  @n@b EMAC_cpdmaClose()
 *
 *  @b Description
 *  @n This function closes and de-initializes up the DMA port and channels.
 *
 *  @b Arguments
 *  @verbatim
 *      none
    @endverbatim
 *
 *  <b> Return Value </b>
 *      None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static void EMAC_cpdmaClose(void); /* for misra warning */
static void EMAC_cpdmaClose(void)
{
    uint32_t channel;
    uint32_t status;



    /* Close TX Channels */
    for (channel = 0; channel < EMAC_CPDMA_MAX_CHANNELS; channel++)
    {
        EMAC_cpswNetChClose(&EMAC_LOCAL_DEVICE->Config.chInfo[CPSW_NET_CH_DIR_TX][channel]);
    }

    /* Close RX Channels */
    for (channel = 0; channel < EMAC_CPDMA_MAX_CHANNELS; channel++)
    {
        EMAC_cpswNetChClose(&EMAC_LOCAL_DEVICE->Config.chInfo[CPSW_NET_CH_DIR_RX][channel]);
    }

    /* Disable Adapter check interrupts - Disable stats interupt */
    EMAC_cpdmaDMAIntDisable(EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base,
        CSL_CPDMA_DMA_INTMASK_SET_HOST_ERR_INT_MASK_MASK |
                    CSL_CPDMA_DMA_INTMASK_SET_STAT_INT_MASK_MASK);

    /* Disable host,stats interrupt in cpsw_3gss_s wrapper */
    EMAC_cpswWrCoreMiscIntDisable(EMAC_LOCAL_DEVICE->Config.baseConfig.wrpr_base, 0,
        ~( CPSW3G_ECTL_HOSTERR_INTMASK |
                                CPSW3G_ECTL_STATPEND_INTMASK));

    /* soft reset */
    CSL_CPSW_resetCpdma((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base);
    status = CSL_CPSW_isCpdmaResetDone((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base);
    while (status == ((uint32_t)FALSE))
    {
        status = CSL_CPSW_isCpdmaResetDone((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base);
    }
}

/** ============================================================================
 *  @n@b EMAC_cpswPortClose()
 *
 *  @b Description
 *  @n This function calls the appropriate functions for closing the port and
 *  cleaning up the associated channels.
 *
 *  @b Arguments
 *  @verbatim
 *      hPort               Handle to the Port object to setup
    @endverbatim
 *
 *  <b> Return Value </b>
 *      CPSWG3_SUCCESS      port open successful
 *      error value         port open failed
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static int32_t EMAC_cpswPortClose(const EMAC_Cpsw3GPort* hPort); /* for misra warning */
static int32_t EMAC_cpswPortClose(const EMAC_Cpsw3GPort* hPort)
{
    if(hPort->portNum == 0)
    {
        /* handle DMA port cleanup here */
        EMAC_cpdmaClose();
    }
    else
    {
        EMAC_cpgmacMacClose(hPort);
    }

    return (0);
}


/** ============================================================================
 *  @n@b EMAC_cpswPortOpen()
 *
 *  @b Description
 *  @n This function opens and sets up the port and channel for communication.
 *
 *  @b Arguments
 *  @verbatim
 *      hPort               Handle to the Port object to setup
    @endverbatim
 *
 *  <b> Return Value </b>
 *      CPSWG3_SUCCESS      port open successful
 *      error value         port open failed
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b> None
 *
 *  @b Example
    @endverbatim
 * ============================================================================
 */
static uint32_t EMAC_cpswPortOpen(EMAC_Cpsw3GPort *hPort); /* for misra warning */
static uint32_t EMAC_cpswPortOpen(EMAC_Cpsw3GPort *hPort)
{
    uint32_t dir,ch,retVal = CPSW3G_SUCCESS;
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;

    if(hPort->portNum > 0)
    {
        /* Ports 1 & 2 are CPGMAC_SL */
        EMAC_cpgmacMacOpen(hPort);
    }
    else
    {
        EMAC_cpdmaOpen(hPort);
    }

    /**CHECK  sequence here */

    /*Program the CPSW_Control register */
    EMAC_cpswSetCfg();

    /* Program the ALE Control register */
    EMAC_cpswSetALECfg();

    /* Configure ALE Port Control Register */
    EMAC_cpswSetALEPortCfg(hPort);

    /**CHECK: kick start any timers here */

    /**Port num 0: Program DMA channels here */
    if (hPort->portNum == 0)
    {
        for (dir = CPSW_NET_CH_DIR_TX; dir <= CPSW_NET_CH_DIR_RX; dir ++)
        {
            for (ch = 0U; ch < cpsw3gCfg->dmaInitCfg.numChannels[dir]; ch++)
            {
                /*Create a channel */
                retVal = EMAC_cpswNetChOpen( &EMAC_LOCAL_DEVICE->Config.chInfo[dir][ch]);
            }
        }
    }
    return (retVal);
}

/** ============================================================================
 *  @n@b  EMAC_cpswOpen()
 *
 *  @b Description
 *  @n Opens the EMAC peripheral at the given physical index and initializes
 *     it to an embryonic state.
 *
 *     The calling application must supply a operating configuration that
 *     includes a callback function table. Data from this config structure is
 *     copied into the device's internal instance structure so the structure
 *     may be discarded after EMAC_cpswOpen() returns. In order to change an item
 *     in the configuration, the EMAC device must be closed and then
 *     re-opened with the new configuration.
 *
 *     The application layer may pass in an hApplication callback handle,
 *     that will be supplied by the EMAC device when making calls to the
 *     application callback functions.
 *
 *     An EMAC device handle is written to phEMAC. This handle must be saved
 *     by the caller and then passed to other EMAC device functions.
 *
 *     The default receive filter prevents normal packets from being received
 *     until the receive filter is specified by calling EMAC_receiveFilter().
 *
 *     A device reset is achieved by calling EMAC_cpswClose() followed by EMAC_cpswOpen().
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error codes include:
 *       CPSW3G_ERR_DEV_ALREADY_OPEN   - The device is already open
 *       CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        physicalIndex   physical index
        hApplication    application handle
        pEMACConfig     EMAC's configuration structure
        phEMAC          handle to the EMAC device
    @endverbatim
 *
 *
 *  <b> Return Value </b>  Success (0)
 *  @n     CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *  @n     CPSW3G_ERR_DEV_ALREADY_OPEN   - The device is already open
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Opens the EMAC peripheral at the given physical index and initializes it.
 *
 *  @b Example
 *  @verbatim
    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswOpen(int32_t physicalIndex, Handle hApplication,
                  EMAC_Cpsw3gInitConfig *pEMACConfig, Handle *phEMAC)
{
    uint32_t retVal = CPSW3G_SUCCESS;
    uint32_t              i;
    EMAC_CpswAddrConfig  *tmp;
    EMAC_HwAttrs_V4 emac_cfg;
    uint32_t status;
    uint8_t idx;

    EMAC_socGetInitCfg(0, &emac_cfg);

    /* Error checks: We only handle a single instance, should not be already opened, valid config,
        error code is internal to LLD, just return CPSW3G_INVALID_PARAM*/
    if ((physicalIndex != 1) ||
        (openFlag == 1U)          || 
        ((pEMACConfig == NULL) || (phEMAC == NULL)))
    {
       retVal = CPSW3G_INVALID_PARAM;
    }
    else
    {
        /* MAC address must be supplied and not a multicast address */
        for (idx=0U; idx < pEMACConfig->totalNumMacAddrs; idx++)
        {
            tmp = &(pEMACConfig->MacAddr[idx]);
            if(tmp->Addr[0U] & 1U )
            {
                retVal = CPSW3G_INVALID_PARAM;
            }
            else
            {
                /* basic check for ZERO mac address */
                for (i = 0U; i < EMAC_MAC_ADDR_LENTH; i++)
                {
                     if (tmp->Addr[i] != 0U)
                     {
                        break;
                     }
                }
                if (i == EMAC_MAC_ADDR_LENTH)
                {
                     retVal =  CPSW3G_INVALID_PARAM;
                }
            }
        }
        if (retVal == CPSW3G_SUCCESS)
        {
            /*
             * Init the instance structure
             */
            /* Set the hApplication and RxFilter */
            EMAC_LOCAL_DEVICE->hApplication[0] = hApplication;
    
            /* there are soft resets in indv. modules, and one from LPSC */
            /* order of reset CPDMA->SL0->SL1->3G->SG0->SG1->3Gss */
    
            /* Reset the different modules */
            EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;


            CSL_CPSW_resetWr((CSL_wrHandle) cpsw3gCfg->baseConfig.wrpr_base);

            status = CSL_CPSW_isWrResetDone((CSL_wrHandle) cpsw3gCfg->baseConfig.wrpr_base);
             while (status == ((uint32_t)FALSE))
            {
                status = CSL_CPSW_isWrResetDone((CSL_wrHandle) cpsw3gCfg->baseConfig.wrpr_base);
            }

            CSL_CPSW_reset((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base);

            status = CSL_CPSW_isResetDone((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base);
            while (status == ((uint32_t)FALSE))
            {
                status = CSL_CPSW_isResetDone((CSL_cpswHandle) cpsw3gCfg->baseConfig.ss_base);
            }

            /* Open all ports */
            for(i=0U; i < cpsw3gCfg->baseConfig.numPorts + 1U; i++)
            {
                EMAC_LOCAL_DEVICE->cpsw3gPort[i].portNum = i;
                EMAC_LOCAL_DEVICE->cpsw3gPort[i].chNum = i;
                EMAC_cpswPortOpen(&(EMAC_LOCAL_DEVICE->cpsw3gPort[i]));
            }/* end of for loop over PORTS */
        
        
            /* Activate the ALE ageout timer here */
            EMAC_LOCAL_DEVICE->Config.aleTimerActive = 1;
        
            /* Validate the device handle */
            EMAC_LOCAL_DEVICE->DevMagic = CPSW_DEVMAGIC;
        
            /* Set the open flag */
            openFlag = 1U;

            /* Give a handle back to the caller */
            *phEMAC = EMAC_LOCAL_DEVICE;
        
            if (EMAC_CFG_LOOPBACK(0U))
            {
                EMAC_AlePortDisableLoopback(emac_cfg.ss_base);
                EMAC_AleInitLoopback(emac_cfg.ss_base);
                EMAC_delay(100000U);
                for(i=1U; i < cpsw3gCfg->baseConfig.numPorts + 1U; i++)
                {
                    EMAC_loopbackSetup(&(EMAC_LOCAL_DEVICE->cpsw3gPort[i]));
                }
            }
        }
    }

    return( retVal );
}


/** ============================================================================
 *  @n@b  EMAC_cpswClose()
 *
 *  @b Description
 *  @n Closed the EMAC peripheral indicated by the supplied instance handle.
 *     When called, the EMAC device will shutdown both send and receive
 *     operations, and free all pending transmit and receive packets.
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC   handle to opened the EMAC device
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC_cpswOpen function must be called before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  The EMAC device will shutdown both send and receive
 *      operations, and free all pending transmit and receive packets.
 *
 *  @b Example
 *  @verbatim
        EMAC_Cpsw3gInitConfig  ecfg;
        Handle       hEMAC = 0;
        //Open the EMAC peripheral
        EMAC_cpswOpen(1, (Handle)ICSS_HANDLE_VALUE, &ecfg, &hEMAC);

        //Close the EMAC peripheral
        EMAC_cpswClose( hEMAC );
    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswClose(Handle hEMAC)
{
    uint32_t retVal = CPSW3G_SUCCESS;
    EMAC_Cpsw3gDevice    *pd = (EMAC_Cpsw3gDevice *)hEMAC;
    EMAC_Cpsw3gInitConfig*   cpsw3gCfg = &EMAC_LOCAL_DEVICE->Config;
    uint32_t idx;

    /* Validate our handle */
    if ((pd == NULL) || (pd->DevMagic != CPSW_DEVMAGIC))
    {
        retVal = CPSW3G_INVALID_PARAM;
    }
    else
    {
        /* Close all ports */
         for(idx=0U;idx< cpsw3gCfg->baseConfig.numPorts + 1U; idx++)
        {
            EMAC_cpswPortClose(&pd->cpsw3gPort[idx]);
        }
        /* De-Activate the ALE ageout timer here */
        pd->Config.aleTimerActive = 0U;
        /* Invalidate the EMAC handle */
        pd->DevMagic = 0U;
        /* Clear the open flag */
        openFlag = 0U;
    }
    return (retVal);
}


/** ============================================================================
 *  @n@b  EMAC_sendPacket()
 *
 *  @b Description
 *  @n Sends a Ethernet data packet out the EMAC device. On a non-error return,
 *     the EMAC device takes ownership of the packet. The packet is returned
 *     to the application's free pool once it has been transmitted.
 *
 *     The function returns zero on success, or an error code on failure.
 *     When an error code is returned, the EMAC device has not taken ownership
 *     of the packet.
 *
 *     Possible error codes include:
 *       CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *       CPSW3G_ERR_BADPACKET - The packet structure is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
        pPkt        EMAC packet structure
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n      CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *  @n      CPSW3G_ERR_BADPACKET - The packet structure is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened and get a packet
 *      buffer from private queue
 *
 *  <b> Post Condition </b>
 *  @n  Sends a ethernet data packet out the EMAC device and is returned to the
 *      application,s free pool once it has been transmitted.
 *
 *  @b Example
 *  @verbatim
        #define EMAC_RXFILTER_DIRECT       1
        #define EMAC_PKT_FLAGS_SOP         0x80000000u
        #define EMAC_PKT_FLAGS_EOP         0x40000000u

        EMAC_Cpsw3gInitConfig ecfg;
        EMAC_Pkt    *pPkt;
        Handle      hEMAC = 0;
        uint32_t      size, TxCount = 0;

        //open the EMAC device
        EMAC_cpswOpen( 1, (Handle)ICSS_HANDLE_VALUE, &ecfg, &hEMAC );

        //set the receive filter
        CPSW_setReceiveFilter( hEMAC, EMAC_RXFILTER_DIRECT );

        //Fill the packet options fields
        size = TxCount + 60;
        pPkt->Flags      = EMAC_PKT_FLAGS_SOP | EMAC_PKT_FLAGS_EOP;
        pPkt->ValidLen   = size;
        pPkt->DataOffset = 0;
        pPkt->PktChannel = 0;
        pPkt->PktLength  = size;
        pPkt->PktFrags   = 1;

        EMAC_sendPacket( hEMAC, pPkt );

    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_sendPacket(Handle hEMAC, EMAC_PKT_DESC_T *pPkt)
{
    EMAC_Cpsw3gDevice    *pd = (EMAC_Cpsw3gDevice *)hEMAC;
    uint32_t          fragcnt,pktlen;
    EMAC_PKT_DESC_T        *pPktLast;
    EMAC_DescCh     *pdc;
    EMAC_CpdmaObj*       dmaObj;
    EMAC_CpswChInfo*   txChan;
    uint32_t retVal = CPSW3G_SUCCESS;
    uint32_t tempVar;
    uint32_t key;

    /* ok to deference pPkt, pointer check done in emac_send_v4() */
    tempVar = pPkt->Flags & EMAC_PKT_FLAG_SOP;
    /* Validate our handle and do packet validation */
    if ((pd == NULL) || (pd->DevMagic != CPSW_DEVMAGIC ))
    {
        retVal = CPSW3G_INVALID_PARAM;
    }
    else if ((tempVar == 0U) ||
                  (pPkt->PktLength < 14U) || 
                  (pPkt->PktLength > pd->PktMTU))
    {
        retVal = CPSW3G_INVALID_PARAM;
    }
    else
    {
        dmaObj = &pd->cpdma;
        txChan = &pd->Config.chInfo[CPSW_NET_CH_DIR_TX][pPkt->PktChannel];

        /* Count the number of frags in this packet */
        fragcnt = 1U;
        pktlen  = pPkt->PktLength;
    
        pPktLast = pPkt;
        tempVar = pPktLast->Flags & EMAC_PKT_FLAG_EOP;
        
        while (tempVar == 0U)
        {
            if (pPktLast->pNext == NULL)
            {
                retVal = CPSW3G_INVALID_PARAM; /* previously returning */
                tempVar = 1U;
            }
            else
            {
                pktlen -= pPktLast->ValidLen;
                pPktLast = pPktLast->pNext;
                fragcnt++;
                /* At this point we can't have another SOP */
                if (pPktLast->Flags & EMAC_PKT_FLAG_SOP)
                {
                    retVal = CPSW3G_INVALID_PARAM;
                    tempVar = 1U;
                }
                tempVar = pPktLast->Flags & EMAC_PKT_FLAG_EOP;
            }
        }
        if (retVal == CPSW3G_SUCCESS)
        {
            /* Perform the followinc checks */
            /* 1. Make sure PktLength and ValidLen agree */
            /* 2. The final packet frag must be the last in the list */
            /* 3. The frag count must be correct */
            if ((pktlen != pPktLast->ValidLen) ||
                (pPktLast->pNext != NULL) ||
                (fragcnt != pPkt->PktFrags))
            {
                retVal = CPSW3G_ERR_BADPACKET;
            }
            else
            {
                /* Now pad for 60 byte min size. We only pad the last fragment */
                if (pPkt->PktLength < 60U)
                {
                    pktlen = 60U - pPkt->PktLength;
                    pPkt->PktLength = 60U;
                    pPktLast->ValidLen += pktlen;
                }
            
                /* Get a local pointer to the descriptor channel */
                pdc = &(dmaObj->txCppi[pPkt->PktChannel]);
                pdc->chInfo = txChan;
        
                /* Make sure this packet does not have too many frags to fit */
                if (fragcnt > pdc->DescMax)
                {
                    retVal =  CPSW3G_ERR_BADPACKET;
                }
                else
                {
                    /*Queue and packet and service transmitter */
                    key = EMAC_osalHardwareIntDisable();
                    EMAC_pqPushChain(&pdc->WaitQueue, pPkt, pPktLast, fragcnt);
                    EMAC_enqueueTx(pdc);
                    EMAC_osalHardwareIntRestore(key);
                }
            }
        }
    }
    return (retVal);
}


/** ============================================================================
 *  @n@b  EMAC_cpswTxServiceCheck()
 *
 *  @b Description
 *  @n This function should be called every time there is an EMAC device Tx
 *     interrupt. It maintains the status the EMAC.
 *
 *     Note that the application has the responsibility for mapping the
 *     physical device index to the correct EMAC_serviceCheck() function. If
 *     more than one EMAC device is on the same interrupt, the function must be
 *     called for each device.
 *
 *     Possible error codes include:
 *       CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *       CPSW3G_ERR_MACFATAL  - Fatal error in the MAC - Call EMAC_cpswClose()
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n     CPSW3G_INVALID_PARAM   - A calling parameter is invalid
 *  @n     CPSW3G_SUCCESS  - Sucess
 *
 *  <b> Pre Condition </b>
 *  @n EMAC_cpswOpen function must be called before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  None
 *
 *  @b Example
 *  @verbatim
        static CSL_IntcContext context;
        static CSL_IntcEventHandlerRecord Record[13];
        static CSL_IntcObj intcEMACTx;
        static CSL_IntcHandle hIntcEMACTx;

        //CSL_IntcParam vectId1;
        CSL_IntcParam vectId2;

        CSL_IntcGlobalEnableState state;

        // Setup the global Interrupt
        context.numEvtEntries = 13;
        context.eventhandlerRecord = Record;

        // VectorID for the Event
        vectId2 = CSL_INTC_VECTID_6;

        CSL_intcInit(&context);
        // Enable NMIs
        CSL_intcGlobalNmiEnable();
        // Enable Global Interrupts
        CSL_intcGlobalEnable(&state);

        // Opening a handle for EMAC Tx interrupt
        hIntcEMACTx=CSL_intcOpen(&intcEMACTx,CSL_INTC_EVENTID_MACTXINT,&vectId2,NULL);

        //Hook the ISRs
        CSL_intcHookIsr(vectId2,&HwTxInt);

        CSL_intcHwControl(hIntcEMACTx, CSL_INTC_CMD_EVTENABLE, NULL);

        // This function is called when Rx interrupt occurs
        Void HwTxInt (void)
        {
            // Note : get the Emac Handle(hEMAC) by calling EMAC_cpswOpen function
            EMAC_cpswTxServiceCheck(hEMAC);
        }

    @endverbatim
 * ============================================================================
 */
uint32_t EMAC_cpswTxServiceCheck(Handle hEMAC)
{
    EMAC_Cpsw3gDevice    *pd = (EMAC_Cpsw3gDevice *)hEMAC;
    uint32_t          Desc;
    uint32_t          i;
    uint32_t retVal = CPSW3G_SUCCESS;
    /* Validate our handle */
    if ((pd == NULL) || (pd->DevMagic != CPSW_DEVMAGIC))
    {
        retVal = CPSW3G_INVALID_PARAM;
    }
    else
    {
        i = 0;
        /* find out if interrupt happend */
        EMAC_DescCh *txChan;
        CSL_CPSW_getCpdmaTxCp((CSL_cpdmaHandle) pd->Config.baseConfig.cpdma_base, i, &Desc);
        /* this should only happen is teardown in process */
        if(Desc == 0xFFFFFFFCU)
        {
            /* need to ack with acknowledge value */
            CSL_CPSW_setCpdmaTxCp((CSL_cpdmaHandle)pd->Config.baseConfig.cpdma_base, 0U, (uint32_t)EMAC_TEARDOWN_DESC);
        }
        else
        {
            txChan = &(pd->cpdma.txCppi[i]);
             EMAC_dequeueTx(txChan, (EMAC_Desc *)Desc);
        }
    }
    return (retVal);
}

void EMAC_cpswRxEoiWrite (void)
{
    CSL_CPSW_setCpdmaRxEndOfIntVector((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base);
}

void EMAC_cpswTxEoiWrite(void)
{
    CSL_CPSW_setCpdmaTxEndOfIntVector((CSL_cpdmaHandle) EMAC_LOCAL_DEVICE->Config.baseConfig.cpdma_base);
}


/**
 * \brief   API to Read Statistics Register and clear it
 *
 * \param   baseAddr      Base Address of the CPSW_STATS
 * \param   reg              The Stats register to be read
  *
 * \return  Count          The value of the register
 *
 **/
uint32_t EMAC_cpswStatsRead(uint32_t baseAddr, uint32_t reg)
{
    uint32_t value = 0U;
    uint32_t address = baseAddr + (reg*4U);
    value = HWREG(address);
    HWREG(address) = value;
    return value;
}



/**
 * \brief   Teardown TX channel
 *
 * \param   baseAddr      Base address of the CPDMA Module registers.
 * \param   channel       Channel number is torn down
 *
 * \return  None
 *
 **/
static void EMAC_cpdmaTxTeardown(uint32_t baseAddr, uint32_t channel)
{
    uint32_t address = baseAddr + CSL_CPDMA_TX_TEARDOWN;
    HWREG(address) = channel;

}

/**
 * \brief   Teardown RX channel
 *
 * \param   baseAddr      Base address of the CPDMA Module registers.
 * \param   channel       Channel number is torn down
 *
 * \return  None
 *
 **/
static void EMAC_cpdmaRxTeardown(uint32_t baseAddr, uint32_t channel)
{
    uint32_t address = baseAddr + CSL_CPDMA_RX_TEARDOWN;
    HWREG(address) = channel;

}

/**
 * \brief   Enables the TXPULSE Interrupt Generation.
 *
 * \param   baseAddr      Base address of the CPDMA Module registers.
 * \param   value         Takes
 *                 CSL_CPDMA_DMA_INTMASK_SET_HOST_ERR_INT_MASK_MASK |
 *                 CSL_CPDMA_DMA_INTMASK_SET_STAT_INT_MASK_MASK
 *
 * \return  None
 *
 **/
static void EMAC_cpdmaDMAIntEnable(uint32_t baseAddr, uint32_t value)
{
    uint32_t address = baseAddr + CSL_CPDMA_TX_INTMASK_SET;
    HWREG(address) = value;
}

/**
 * \brief   Enables the TXPULSE Interrupt Generation.
 *
 * \param   baseAddr      Base address of the CPDMA Module registers.
 * \param   value       TAkes CSL_CPDMA_DMA_INTMASK_SET_HOST_ERR_INT_MASK_MASK |
                    CSL_CPDMA_DMA_INTMASK_SET_STAT_INT_MASK_MASK
 *
 * \return  None
 *
 **/
static void EMAC_cpdmaDMAIntDisable(uint32_t baseAddr, uint32_t value)
{
    uint32_t address = baseAddr + CSL_CPDMA_DMA_INTMASK_CLEAR;
    HWREG(address) |= (((uint32_t)1U) << value);
}

/**
 * \brief   Enables a Misc interrupt for the specified core.
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   core        Core number
 * \param   value     Type of interrupt
 *                 CPSW3G_ECTL_HOSTERR_INTMASK
 *                 CPSW3G_ECTL_STATPEND_INTMASK
 *
 * \return  None
 **/
static void EMAC_cpswWrCoreMiscIntEnable(uint32_t baseAddr, uint32_t core,
                         uint32_t value)
{
    uint32_t address = baseAddr + CSL_WR_MISC_EN(core);
    HWREG(address) |= value;
}

/**
 * \brief   Disables a Misc interrupt for the specified core.
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   core        Core number
 * \param   value     Type of interrupt
 *                 CPSW3G_ECTL_HOSTERR_INTMASK
 *                 CPSW3G_ECTL_STATPEND_INTMASK
 *
 * \return  None
 **/
static void EMAC_cpswWrCoreMiscIntDisable(uint32_t baseAddr, uint32_t core,
                         uint32_t value)
{
    uint32_t address = baseAddr + CSL_WR_MISC_EN(core);
    HWREG(address) &= value;
}

/**
 * \brief   Sets the Rx per second(Interrupt Pacing)
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   core        Core number
 * \param   value       Number of interrupts per millisecond
 *
 * \return  None
 **/
static void EMAC_cpswWrSetRxIntPerMSec(uint32_t baseAddr, uint32_t core,
                         uint32_t value)
{
    uint32_t address = baseAddr + CSL_WR_RX_IMAX(core);
    HWREG(address) &= ~(CSL_WR_RX_IMAX_RX_IMAX_MASK);
    HWREG(address) = (value << CSL_WR_RX_IMAX_RX_IMAX_SHIFT);
}

/**
 * \brief   Enable Interrupt pacing
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   value       The pulse to which Pacing is enabled
 *
 * \return  None
 **/
static void EMAC_cpswWrSetIntPacingEnable(uint32_t baseAddr,
                         uint32_t value)
{
    if (value <= CSL_WR_INT_CONTROL_INT_PACE_EN_MAX)
    {
        uint32_t address =baseAddr + CSL_WR_INT_CONTROL;
        uint32_t tempVal = HW_RD_REG32(address);
        tempVal  &= ~(CSL_WR_INT_CONTROL_INT_PACE_EN_MASK);
        tempVal |= (value << CSL_WR_INT_CONTROL_INT_PACE_EN_SHIFT);
        HW_WR_REG32(address, tempVal);
    }
}

/**
 * \brief   Set Interrupt counter prescaler
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   value
 *
 * \return  None
 **/
static void EMAC_cpswWrSetIntPrescaler(uint32_t baseAddr,
                         uint32_t value)
{
    if (value <= CSL_WR_INT_CONTROL_INT_PRESCALE_MAX)
    {
        uint32_t address =baseAddr + CSL_WR_INT_CONTROL;
        uint32_t tempVal = HW_RD_REG32(address);
        tempVal  &= ~(CSL_WR_INT_CONTROL_INT_PRESCALE_MASK);
        tempVal |= (value << CSL_WR_INT_CONTROL_INT_PRESCALE_SHIFT);
        HW_WR_REG32(address, tempVal);
    }
}

