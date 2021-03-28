/*
 * Copyright (C) 2002-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/** ============================================================================
 *   @file  emac.c
 *
 *   PATH:  \$(PDK_INSTALL_PATH)\ti\drv\emac\src\v0
 *
 *   @brief  EMAC Implementation on DSP side
 *
 *  \par
 *  NOTE:
 *  When used in an multitasking environment, no EMAC function may be
 *  called while another EMAC function is operating on the same device
 *  handle in another thread. It is the responsibility of the application
 *  to assure adherence to this restriction.
 *
 *  \par
 *  Although the EMAC API is defined to support multiple device instances,
 *  this version supports a single device instance
 */

/* =============================================================================
 *  Revision History
 *  ================
 *  19-Mar-2008 Added EMAC fixes for polling, frag count, multiple MAC support,
 *	Rx/Tx EOI, multiple Rx channels.
 *  02-Nov-07 PSK   Ported to new soc
 * =============================================================================
 */

#include <ti/csl/cslr_ectl.h>
#include <ti/csl/csl_emac.h>
#include <ti/csl/csl_chip.h>
/* Hardware Platform Configuration Header. */
#include <ti/drv/emac/emac_hwcfg.h>
/* EMAC Driver API Header. */
#include <ti/drv/emac/emac_drv.h>
#include "inc/emac_loc.h"
#include <ti/drv/emac/soc/emac_soc_v0.h>

extern void   *memset(void *_mem, int _ch, Uint32 _n);
/**< Default Memset API                                                     */

/* Queue Helper Functions                                                   */
static EMAC_Pkt *pqPop(PKTQ *pq);
static void pqPush(PKTQ *pq, EMAC_Pkt *pPktHdr);
static void pqPushChain(PKTQ *pq, EMAC_Pkt *pPktHdrFirst,
                         EMAC_Pkt *pPktHdrLast, Uint32 Count);

/*
 * Local Helper Functions
 */
static void emacUpdateStats(EMAC_Device *pd);
static void emacEnqueueTx(EMAC_DescCh *pdc);
static void emacDequeueTx(EMAC_Device* pd, EMAC_DescCh *pdc, EMAC_Desc *pDescLast);
static void emacEnqueueRx(EMAC_Device* pd, EMAC_DescCh *pdc, Uint32 fRestart);
static void emacDequeueRx(EMAC_Device* pd, EMAC_DescCh *pdc, EMAC_Desc *pDescAck);

void  emacLinkUpProcessing(Handle hEMAC );

/** ============================================================================
 *  @n@b pqPop()
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
        PKTQ *pq;
        pqPop( pq );
    @endverbatim
 * ============================================================================
 */
static EMAC_Pkt *pqPop(PKTQ *pq)
{
    EMAC_Pkt *pPktHdr;

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
 *  @n@b pqPush()
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
        PKTQ *pq;
        EMAC_Pkt *pPktHdr

        pqPush( pq, pPktHdr );
    @endverbatim
 * ============================================================================
 */
static void pqPush(PKTQ *pq, EMAC_Pkt *pPktHdr)
{
    pPktHdr->pNext = 0;

    if (!pq->pHead)
    {
        // Queue is empty - Initialize it with this one packet
        pq->pHead = pPktHdr;
        pq->pTail = pPktHdr;
    }
    else
    {
        // Queue is not empty - Push onto END
        pq->pTail->pNext = pPktHdr;
        pq->pTail        = pPktHdr;
    }
    pq->Count++;
}
/** ============================================================================
 *  @n@b pqPushChain()
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
        PKTQ *pq;
        EMAC_Pkt *pPktHdrFirst, *pPktHdrLast;
        Uint32 Count;

        pqPushChain( pq, pPktHdrFirst, pPktHdrLast, Count );
    @endverbatim
 * ============================================================================
 */
static void pqPushChain(PKTQ *pq, EMAC_Pkt *pPktHdrFirst,
                         EMAC_Pkt *pPktHdrLast, Uint32 Count)
{
    pPktHdrLast->pNext = 0;

    if (!pq->pHead)
    {
        // Queue is empty - Initialize it with this packet chain
        pq->pHead = pPktHdrFirst;
        pq->pTail = pPktHdrLast;
    }
    else
    {
        // Queue is not empty - Push onto END
        pq->pTail->pNext = pPktHdrFirst;
        pq->pTail        = pPktHdrLast;
    }
    pq->Count += Count;
}

/** ============================================================================
 *  @n@b emacUpdateStats()
 *
 *  @b Description
 *  @n Update our local copy of the statistics
 *
 *  @b Arguments
 *  @verbatim
        pd  pointer to EMAC object
    @endverbatim
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened
 *
 *  <b> Post Condition </b>
 *  @n  Update local copy of the statistics to the EMAC registers
 *
 *  @b Example
 *  @verbatim
        EMAC_Device *pd;

        emacUpdateStats( pd );
    @endverbatim
 * ============================================================================
 */
static void emacUpdateStats( EMAC_Device *pd )
{
    int             i;
    volatile Uint32 *pRegAddr;
    Uint32          *pStatAddr;
    Uint32          statval;

    pRegAddr = &EMAC_REGS->RXGOODFRAMES;
    pStatAddr = (Uint32 *)(&pd->Stats);

    /*
     * There are "EMAC_NUMSTATS" statistics registers
     * Note that when GMIIEN is set in MACCONTROL, these registers
     * are "write to decrement".
     */
    for (i = 0; i < EMAC_NUMSTATS; i++)
    {
        statval = *pRegAddr;
        *pRegAddr++ = statval;
        statval += *pStatAddr;
        *pStatAddr++ = statval;
    }
}
/** ============================================================================
 *  @n@b emacEnqueueTx()
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

        emacEnqueueTx ( pdc );
    @endverbatim
 * ============================================================================
 */
static void emacEnqueueTx(EMAC_DescCh *pdc)
{
    EMAC_Desc       *pDescOrg;
    EMAC_Desc       *pDescThis;
    EMAC_Pkt        *pPkt;
    Uint32          PktFrags;
    Uint32          CountOrg;
    volatile Uint32 *pRegAddr;

    /*
     * We need to be careful that we don't post half a packet to
     * the list. Otherwise; we just fill in as much packet descriptor
     * stuff as we can.
     */
    pDescOrg = pdc->pDescWrite;
    CountOrg = pdc->DescCount;

    /* Try to post any waiting packets */
    while (pdc->WaitQueue.Count)
    {
        /* See if we have enough room for a new packet */
        pPkt = pdc->WaitQueue.pHead;
        PktFrags = pPkt->PktFrags;

        /* If we don't have room, break out */
        if ((PktFrags+pdc->DescCount) > pdc->DescMax)
            break;

        /* The next packet will fit, post it. */
        while (PktFrags)
        {
            /* Pop the next frag off the wait queue */
            pPkt = pqPop(&pdc->WaitQueue);

            /* Assign the pointer to "this" desc */
            pDescThis = pdc->pDescWrite;

            /* Move the write pointer and bump count */
            if (pdc->pDescWrite == pdc->pDescLast)
                pdc->pDescWrite = pdc->pDescFirst;
            else
                pdc->pDescWrite++;
            pdc->DescCount++;

            /*
             * If this is the last frag, the forward pointer is NULL
             * Otherwise; this desc points to the next frag's desc
             */
            if (PktFrags == 1)
                pDescThis->pNext = 0;
            else
                pDescThis->pNext = pdc->pDescWrite;

            pDescThis->pBuffer   = pPkt->pDataBuffer + pPkt->DataOffset;
            pDescThis->BufOffLen = pPkt->ValidLen;

            if (pPkt->Flags & EMAC_PKT_FLAGS_SOP)
                pDescThis->PktFlgLen = ((pPkt->Flags&
                                       (EMAC_PKT_FLAGS_SOP|EMAC_PKT_FLAGS_EOP))
                                       |pPkt->PktLength|EMAC_DSC_FLAG_OWNER);
            else
                pDescThis->PktFlgLen = (pPkt->Flags&EMAC_PKT_FLAGS_EOP)
                                       |EMAC_DSC_FLAG_OWNER;

            /* Enqueue this frag onto the desc queue */
            pqPush(&pdc->DescQueue, pPkt);
            PktFrags--;
        }
    }

    /* If we posted anything, chain on the list or start the transmitter */
    if (CountOrg != pdc->DescCount)
    {
        if (CountOrg)
        {
            /*
             * Transmitter is already running. Just tack this packet on
             * to the end of the list (we need to "back up" one descriptor)
             */
            if (pDescOrg == pdc->pDescFirst)
                pDescThis = pdc->pDescLast;
            else
                pDescThis = pDescOrg - 1;
            pDescThis->pNext = pDescOrg;
        }
        else
        {
            /* Transmitter is not running, start it up */
            pRegAddr = &EMAC_REGS->TX0HDP;
            *(pRegAddr + pdc->ChannelIndex) = (Uint32)pDescOrg;
        }
    }
}
/** ============================================================================
 *  @n@b emacDequeueTx()
 *
 *  @b Description
 *  @n Dequeue all completed TX packets and return buffers to application
 *
 *  @b Arguments
 *  @verbatim
        pd          pointer to EMAC object
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
        EMAC_Device *pd;

        emacDequeueTx ( pd, pdc, pDescAck );
    @endverbatim
 * ============================================================================
 */
static void emacDequeueTx(EMAC_Device* pd, EMAC_DescCh *pdc, EMAC_Desc *pDescAck)
{
    EMAC_Pkt        *pPkt;
    Uint32          PktFlgLen;
    register Uint32   i;
    register Uint32   j = (Uint32)pdc->pDescRead;
    volatile Uint32 *pRegAddr;
    Uint32              corenum = 0;  


    /* Get the status of the ACK descriptor */
    PktFlgLen = pDescAck->PktFlgLen;

    /* Calc the new "Read" descriptor */
    if (pDescAck == pdc->pDescLast)
        pdc->pDescRead = pdc->pDescFirst;
    else
        pdc->pDescRead = pDescAck+1;

    i = (Uint32)pdc->pDescRead;

    /* Turn i into a descriptor count */
    if( j < i )
        i = (i-j)/sizeof(EMAC_Desc);
    else
        i = pdc->DescMax - ((j-i)/sizeof(EMAC_Desc));

    if (pdc->DescCount == 0)
		i=0;
    else
		pdc->DescCount-=i;

    /* Pop & Free Buffers 'till the last Descriptor */
    while (i--)
    {
        /* Recover the buffer and free it */
        pPkt = pqPop(&pdc->DescQueue);
        if (pPkt)
            (*pd->CoreConfig[corenum].pfcbFreePacket)(pdc->pd->pEMACCore[corenum]->hApplication,pPkt);
    }

    /* If the transmitter stopped and we have more descriptors, then restart */
    if ((PktFlgLen & EMAC_DSC_FLAG_EOQ) && pdc->DescCount)
    {
        pRegAddr = &EMAC_REGS->TX0HDP;
        *(pRegAddr + pdc->ChannelIndex) = (Uint32)pdc->pDescRead;
    }

    /* Try to post any waiting TX packets */
    if (pdc->WaitQueue.Count)
        emacEnqueueTx(pdc);
}

/** ============================================================================
 *  @n@b emacEnqueueRx()
 *
 *  @b Description
 *  @n Fill any empty RX descriptors with new buffers from the application
 *
 *  @b Arguments
 *  @verbatim
        pd          pointer to EMAC object
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
        Uint32         fRestart;
        EMAC_Device*    pd;

        emacEnqueueRx( pd, pdc, fRestart );
    @endverbatim
 * ============================================================================
 */
static void emacEnqueueRx(EMAC_Device* pd, EMAC_DescCh *pdc, Uint32 fRestart)
{
    EMAC_Pkt        *pPkt;
    EMAC_Desc       *pDesc;
    Uint32            CountOrg;
    volatile Uint32  *pRegAddr;
    Uint32              corenum = 0;  

    /* Keep the old count around */
    CountOrg = pdc->DescCount;

    /* Fill RX Packets Until Full */
    while (pdc->DescCount < pdc->DescMax)
    {
        /* Get a buffer from the application */
        pPkt = (*pd->CoreConfig[corenum].pfcbGetPacket)(pdc->pd->pEMACCore[corenum]->hApplication);

        /* If no more buffers are available, break out of loop */
        if (!pPkt)
            break;

        /* Fill in the descriptor for this buffer */
        pDesc = pdc->pDescWrite;

        /* Move the write pointer and bump count */
        if (pdc->pDescWrite == pdc->pDescLast)
            pdc->pDescWrite = pdc->pDescFirst;
        else
            pdc->pDescWrite++;
        pdc->DescCount++;

        /* Supply buffer pointer with application supplied offset */
        pDesc->pNext     = 0;
        pDesc->pBuffer   = pPkt->pDataBuffer + pPkt->DataOffset;
        pDesc->BufOffLen = pd->PktMTU;
        pDesc->PktFlgLen = EMAC_DSC_FLAG_OWNER;

        /* Make the previous buffer point to us */
        if (pDesc == pdc->pDescFirst)
             pdc->pDescLast->pNext = pDesc;
        else
            (pDesc-1)->pNext = pDesc;

        /* Push the packet buffer on the local descriptor queue */
        pqPush(&pdc->DescQueue, pPkt);
    }

    /* Restart RX if we had ran out of descriptors and got some here */
    if (fRestart && !CountOrg && pdc->DescCount)
    {
        pRegAddr = &EMAC_REGS->RX0HDP;
        *(pRegAddr + pdc->ChannelIndex)= (Uint32)pdc->pDescRead;
    }
}

/** ============================================================================
 *  @n@b emacDequeueRx()
 *
 *  @b Description
 *  @n Dequeue all completed RX packets and give buffers to application
 *
 *  @b Arguments
 *  @verbatim
        pd          pointer to EMAC object
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
        EMAC_Device *pd;

        emacDequeueRx( pd, pdc, pDescAck );
    @endverbatim
 * ============================================================================
 */
static void emacDequeueRx(EMAC_Device* pd, EMAC_DescCh *pdc, EMAC_Desc *pDescAck)
{
    EMAC_Pkt    *pPkt;
    EMAC_Pkt    *pPktNew;
    EMAC_Desc   *pDescNewRxFirst;
    EMAC_Desc   *pDescNewRxLast=0;
    EMAC_Desc   *pTemp;
    Uint32      tmp;
    Uint32          PktFlgLen = 0;
    volatile Uint32 *pRegAddr;
    Uint32          corenum = 0;  

    /* Remember the first new descriptor slot */
    pDescNewRxFirst = pdc->pDescWrite;

    /*
     * Pop & Free Buffers 'till the last Descriptor
     * One thing we know for sure is that all the decriptors from
     * the read pointer to pDescAsk are linked to each other via
     * their pNext field.
    */
    for (tmp = 1; tmp; )
    {
        /* Get the status of this descriptor */
        PktFlgLen = pdc->pDescRead->PktFlgLen;
	  if (!(PktFlgLen & EMAC_DSC_FLAG_OWNER) )
      {
        /* Recover the buffer and free it */
        pPkt = pqPop(&pdc->DescQueue);
        if (pPkt)
        {
            /* Fill in the necessary packet header fields */
            pPkt->Flags = PktFlgLen & 0xFFFF0000;
            pPkt->ValidLen = pPkt->PktLength = PktFlgLen & 0xFFFF;
            pPkt->PktChannel = pdc->ChannelIndex;
            pPkt->PktFrags = 1;

            /* Pass the packet to the application */
            pPktNew = (*pd->CoreConfig[corenum].pfcbRxPacket)
                                           (pdc->pd->pEMACCore[corenum]->hApplication,pPkt);
        }

        /* See if this was the last buffer */
        if (pdc->pDescRead == pDescAck)
            tmp = 0;

        /* Move the read pointer and decrement count */
        if (pdc->pDescRead == pdc->pDescLast)
            pdc->pDescRead = pdc->pDescFirst;
        else
            pdc->pDescRead++;
        pdc->DescCount--;

        /* See if we got a replacement packet */
        if(pPktNew)
        {
            /* We know we can immediately queue this packet */

            /* Fill in the descriptor for this buffer */
            pDescNewRxLast = pdc->pDescWrite;

            /* Move the write pointer and bump count */
            if( pdc->pDescWrite == pdc->pDescLast )
                pdc->pDescWrite = pdc->pDescFirst;
            else
                pdc->pDescWrite++;
            pdc->DescCount++;

            /* Supply buffer pointer with application supplied offset */
            pDescNewRxLast->pBuffer   = pPktNew->pDataBuffer + pPktNew->DataOffset;
            pDescNewRxLast->BufOffLen = pd->PktMTU;
            pDescNewRxLast->PktFlgLen = EMAC_DSC_FLAG_OWNER;

            /* Push the packet buffer on the local descriptor queue */
            pqPush(&pdc->DescQueue, pPktNew);
        }

	  }
	  else
        tmp =0;
    }

    /*
     * If we added descriptors, make the pNext of the last NULL, and
     * make the previous descriptor point to the new list we added.
     */
    if (pDescNewRxLast)
    {
        pDescNewRxLast->pNext = 0;

        /* Make the previous buffer point to us */
        if (pDescNewRxFirst == pdc->pDescFirst)
            pTemp = pdc->pDescLast;
        else
            pTemp = pDescNewRxFirst-1;

        /*
         * If these pointers wrapped, the RX engine is stopped
         * Otherwise; tack the new list to the old
         */
        if (pTemp != pDescNewRxLast)
            pTemp->pNext = pDescNewRxFirst;
    }

    /* If the receiver stopped and we have more descriptors, then restart */
    if ((PktFlgLen & EMAC_DSC_FLAG_EOQ) && pdc->DescCount)
    {
        pRegAddr = &EMAC_REGS->RX0HDP;
        *(pRegAddr + pdc->ChannelIndex) = (Uint32)pdc->pDescRead;
    }
}


/*-----------------------------------------------------------------------*\
 * STANDARD API FUNCTIONS
 *
 * Note on Exclusion (Serialization):
 *   The application is charged with verifying that only one of the
 * following API calls may only be executing at a given time across
 * all threads and all interrupt functions.
 *
 *-----------------------------------------------------------------------*/




/** ============================================================================
 *  @n@b  EMAC_commonInit()
 *
 *  @b Description
 *  @n Open the EMAC peripheral at the given physical index and perform
 *     initialization common to all the cores, including resetting the EMAC control
 *     module and stats, initializing DMA, configuring common registers such as
 *     the MACCONTROL register, initializing MDIO, and etc. This function has to 
 *     be called only once by the master core.
 *
 *     The calling application must supply an operating configuration. Data from 
 *     this config structure is copied into the device's internal instance structure
 *     so the structure may be discarded after EMAC_commonInit() returns. In order
 *     to change an item in the configuration, the EMAC device must be de-initialized
 *     by EMAC_commonDeInit() and then re-initialized by calling EMAC_commonInit()
 *     with the new configuration.
 *
 *     A valid EMAC device handle should be passed to this API to which the
 *     configuration and operating state of the EMAC device common to all the cores
 *     will be written. The EMAC device structure for the handle needs to be 
 *     initialized before calling EMAC_commonInit().
 *
 *     The default receive filter prevents normal packets from being received
 *     until the receive filter is specified by calling EMAC_receiveFilter().
 *
 *     A device reset is achieved by calling EMAC_commonDeInit() followed by 
 *     EMAC_commonInit().
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        instNum           EMAC Peripheral ID to identify the EMAC controller to be
                          initialized.
        pEMACCommonConfig EMAC's configuration common to all cores.
        hEMAC             Handle to the EMAC device which needs to be initialized.
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Open the EMAC peripheral at the given physical index and perform 
 *      initialization common to all the cores.
 *
 *  @b Example
 *  @verbatim
        EMAC_Device            EMACObj; // In multi-core scenario, this must be placed in shared memory,
                                           and initialized by application. Refer to "emac_core_restart"
                                           example project for more details.

        EMAC_Common_Config     commonCfg;

        // Initialize our EMAC Dev structure.
        memset(&EMACObj, 0, sizeof(EMAC_Device));

        // Not using the MDIO configuration
        commonCfg.UseMdio = 0;
        // core 0 is master core performing common initialization of the EMAC
        commonCfg.CoreNum = 0; 
        //packet size
        commonCfg.PktMTU = 1600;

        // Setup the EMAC local loopback
        commonCfg.ModeFlags      = EMAC_CONFIG_MODEFLG_MACLOOPBACK | EMAC_CONFIG_MODEFLG_GMIIEN
                                 | EMAC_CONFIG_MODEFLG_FULLDUPLEX;
        commonCfg.MdioModeFlags  = MDIO_MODEFLG_FD1000;

        //Common initialization of the EMAC peripheral
        EMAC_commonInit(0, &commonCfg, &EMACObj);
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_commonInit( int instNum, EMAC_Common_Config *pEMACCommonConfig, Handle hEMAC, Uint32 macsel)
{
    int                 i;
    volatile Uint32*    pRegAddr;
    EMAC_Device*        pEmacDev;
    CSL_EmacRegs*       emacRegs;
    Uint32              corenum = 0;
    Uint32              tmpval;

    /*
     *  Validate the supplied configuration structure
     */
    if (!pEMACCommonConfig || !hEMAC)
        return (EMAC_ERROR_INVALID);

    if(corenum != pEMACCommonConfig->CoreNum)
        return (EMAC_ERROR_INVALID);

    pEmacDev = (EMAC_Device *)hEMAC;
    if (pEmacDev->InitOnce)
        return (0);

    if (instNum == CSL_EMAC) {
        pEmacDev->emacRegs = (CSL_EmacRegs *)CSL_EMAC_0_REGS;
        pEmacDev->ectlRegs = (CSL_EctlRegs *)CSL_ECTL_0_REGS;
    }
    else {
        return( EMAC_ERROR_INVALID );
    }

    /* Update our local copy of register handles too */
    emacRegs =  pEmacDev->emacRegs;

    if (pEMACCommonConfig->UseMdio)
    {
        /* MDIO settings must be valid - at least one bit must be set */
        if (!(pEMACCommonConfig->MdioModeFlags & (MDIO_MODEFLG_AUTONEG |
            MDIO_MODEFLG_HD10  | MDIO_MODEFLG_FD10 |
            MDIO_MODEFLG_HD100 | MDIO_MODEFLG_FD100 |
            MDIO_MODEFLG_FD1000)))
            return (EMAC_ERROR_INVALID);
    }

    /*
     * Init the device instance structure
     */
    /* Set the RxFilter */
    pEmacDev->RxFilter     = EMAC_RXFILTER_NOTHING;

    /* Setup the new configuration */
    pEmacDev->Config = *pEMACCommonConfig;

    /*
     *  Initialize the EMAC and MDIO devices
     */

	/* Disable wrapper interrupt pacing */
	ECTL_REGS->INT_CONTROL = 0x00;
	/*Give soft reset to Wrapper*/
	ECTL_REGS->SOFT_RESET = 0x01;
	while (ECTL_REGS->SOFT_RESET != 0x00000000);  /* Wait until reset has occured */

	/* Give soft reset to EMAC */
	EMAC_REGS->SOFTRESET = 0x00000001;
	while (EMAC_REGS->SOFTRESET != 0x00000000); /* Wait until reset has occured */

    if (pEMACCommonConfig->UseMdio)
        /* Start the MII Configuration */
        MDIO_open(instNum, pEMACCommonConfig->MdioModeFlags, pEMACCommonConfig->MdioPhyAddr, &pEmacDev->MdioDev, macsel);

    /*
     *  Setup the EMAC
     */

    /* Reset MAC Control */
    emacRegs->MACCONTROL = 0 ;


    /* Must manually init HDPs to NULL */
    pRegAddr = &emacRegs->TX0HDP;
    for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++)
        *pRegAddr++ = 0;
    pRegAddr = &emacRegs->RX0HDP;
    for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++)
        *pRegAddr++ = 0;

    /*
     * While GMIIEN is clear in MACCONTROL, we can write directly to
     * the statistics registers (there are "CSL_EMAC_NUMSTATS" of them).
     */
    pRegAddr = &emacRegs->RXGOODFRAMES;
    for (i=0; i<EMAC_NUMSTATS; i++)
        *pRegAddr++ = 0;

    /* Initialize the RAM locations */
    for (i = 0; i < CSL_EMAC_NUMMACADDRS; i++)
    {
        emacRegs->MACINDEX = i;
        emacRegs->MACADDRHI = 0;
        emacRegs->MACADDRLO = 0;
        pEmacDev->MacIndexUsed[i] = 0xFF;
    }

    for (i = 0; i < CSL_EMAC_NUMCORES; i++) {
        pEmacDev->CoreConfig[i].ChannelInfo.TxChanEnable = 0;
        pEmacDev->CoreConfig[i].ChannelInfo.RxChanEnable = 0;
    }

    /*
     * Setup Special Receive Conditions (loopback, error frames, etc)
     */

    /* For us buffer offset will always be zero */
    emacRegs->RXBUFFEROFFSET = 0;

    /* Reset RX (M)ulticast (B)roadcast (P)romiscuous Enable register */
    emacRegs->RXMBPENABLE = 0;
    emacRegs->MACHASH1 = 0;
    emacRegs->MACHASH2 = 0;

    /* Clear Unicast RX on channel 0-7 */
    emacRegs->RXUNICASTCLEAR = 0xFF;

    /* Set the pass RX CRC mode and adjust max buffer accordingly */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_RXCRC)
    {
        CSL_FINST(emacRegs->RXMBPENABLE, EMAC_RXMBPENABLE_RXPASSCRC, INCLUDE);
        pEmacDev->PktMTU = (pEMACCommonConfig->PktMTU) + 4;
    }
    else
        pEmacDev->PktMTU = (pEMACCommonConfig->PktMTU);


    emacRegs->RXMAXLEN = pEmacDev->PktMTU;
    /* If PASSERROR is set, enable both ERROR and short frames */
    tmpval = emacRegs->RXMBPENABLE;
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_PASSERROR){
        CSL_FINST(tmpval, EMAC_RXMBPENABLE_RXCEFEN, ENABLE);
        CSL_FINST(tmpval, EMAC_RXMBPENABLE_RXCSFEN, ENABLE);
    }
    /* If PASSCONTROL is set, enable control frames */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_PASSCONTROL)
        CSL_FINST(tmpval, EMAC_RXMBPENABLE_RXCMFEN, ENABLE);
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_PASSALL)
        CSL_FINST(tmpval, EMAC_RXMBPENABLE_RXCAFEN, ENABLE);
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_RXQOS)
        CSL_FINST(tmpval, EMAC_RXMBPENABLE_RXQOSEN, ENABLE);
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_RXNOCHAIN)
        CSL_FINST(tmpval, EMAC_RXMBPENABLE_RXNOCHAIN, ENABLE);
    emacRegs->RXMBPENABLE = tmpval;

    tmpval = emacRegs->MACCONTROL;
    /* Set the channel configuration to priority if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_CHPRIORITY)
        CSL_FINST(tmpval, EMAC_MACCONTROL_TX_PTYPE, CHANNELPRI);
    /* Set MAC loopback if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_MACLOOPBACK)
        CSL_FINST(tmpval, EMAC_MACCONTROL_LOOPBACK, ENABLE);
    /* Set full duplex mode if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_FULLDUPLEX)
        CSL_FINST(tmpval, EMAC_MACCONTROL_FULLDUPLEX, ENABLE);
    /* Enable gigabit transfer if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_GIGABIT)
        CSL_FINST(tmpval, EMAC_MACCONTROL_GIG, ENABLE);
    /* Enable rx offset/length blocing if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_RXOFFLENBLOCK)
        CSL_FINST(tmpval, EMAC_MACCONTROL_RX_OFFLEN_BLOCK, BLOCK);
    /* Use rx owership one if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_RXOWNERSHIP)
        CSL_FINST(tmpval, EMAC_MACCONTROL_RX_OWNERSHIP, ONE);
    /* Enable rx fifo flow control if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_RXFIFOFLOWCNTL)
        CSL_FINST(tmpval, EMAC_MACCONTROL_RX_FIFO_FLOW_EN, ENABLE);
    /* Enable IDLE command bit if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_CMDIDLE)
        CSL_FINST(tmpval, EMAC_MACCONTROL_CMD_IDLE, ENABLE);
	/* Enable tx short gap if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_TXSHORTGAPEN)
        CSL_FINST(tmpval, EMAC_MACCONTROL_TX_SHORT_GAP_EN, ENABLE);
    /* Enable tx pace if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_TXPACE)
        CSL_FINST(tmpval, EMAC_MACCONTROL_TX_PACE, ENABLE);
    /* Enable tx flow control */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_TXFLOWCNTL)
        CSL_FINST(tmpval, EMAC_MACCONTROL_TX_FLOW_EN, ENABLE);
    /* Enable rx  buffer flow control if requested */
    if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_RXBUFFERFLOWCNTL)
        CSL_FINST(tmpval, EMAC_MACCONTROL_RX_BUFFER_FLOW_EN, ENABLE);
   if (pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_EXTEN)
	      CSL_FINST(tmpval, EMAC_MACCONTROL_EXT_EN, ENABLE);
    /* GMII enable */
    if(pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLG_GMIIEN)
       CSL_FINST(tmpval, EMAC_MACCONTROL_GMII_EN, ENABLE);
    /* giga force enable */
    if(pEMACCommonConfig->ModeFlags & EMAC_CONFIG_MODEFLAG_GIGFORCE)
       CSL_FINST(tmpval, EMAC_MACCONTROL_GIG_FORCE, ENABLE);
    /* RMII speed select */
    tmpval = EMAC_RMIISpeedSelect(tmpval);

    emacRegs->MACCONTROL = tmpval;

    /*
     * Reset TX and RX channel interrupts
     * Enable Host interrupts
     */
    emacRegs->RXINTMASKCLEAR = 0xFF;
    emacRegs->TXINTMASKCLEAR = 0xFF;

    emacRegs->MACINTMASKSET = CSL_FMK(EMAC_MACINTMASKSET_HOSTMASK, 1) |
                               CSL_FMK(EMAC_MACINTMASKSET_STATMASK, 1);

    /*
     * Enable RX and TX control
     */
    CSL_FINST(emacRegs->TXCONTROL, EMAC_TXCONTROL_TXEN, ENABLE);
    CSL_FINST(emacRegs->RXCONTROL, EMAC_RXCONTROL_RXEN, ENABLE);

    /* Initialize the device magic number and peripheral instance ID */
    pEmacDev->DevMagic = EMAC_DEVMAGIC;
    pEmacDev->perNum =  instNum;
    pEmacDev->InitOnce = 1;

    /* Return Success */
    return( 0 );
}

/* DISABLE AND RE-ENABLE GMII_EN FIELD to allow for link establishement when link comes up */
void emacLinkUpProcessing(Handle hEMAC )
{
    EMAC_Device*        pEmacDev;
    CSL_EmacRegs*       emacRegs;
    Uint32              tmpval;


    pEmacDev = (EMAC_Device *)hEMAC;
    pEmacDev->emacRegs = (CSL_EmacRegs *)CSL_EMAC_0_REGS;


    /* Update our local copy of register handles too */
    emacRegs =  pEmacDev->emacRegs;


    tmpval = emacRegs->MACCONTROL;

    /* GMII_EN disable */
    CSL_FINST(tmpval, EMAC_MACCONTROL_GMII_EN, DISABLE);

    emacRegs->MACCONTROL = tmpval;

   
    while(CSL_FEXT(emacRegs->MACCONTROL, EMAC_MACCONTROL_GMII_EN) != 0);

    tmpval = emacRegs->MACCONTROL;

    /* GMII_EN enable */
    CSL_FINST(tmpval, EMAC_MACCONTROL_GMII_EN, ENABLE);
    emacRegs->MACCONTROL = tmpval;
    while(CSL_FEXT(emacRegs->MACCONTROL, EMAC_MACCONTROL_GMII_EN)  != 1);


}
/** ============================================================================
 *  @n@b  EMAC_coreInit()
 *
 *  @b Description
 *  @n Core specific initialization to use the EMAC peripheral at the given 
 *     physical index when every core starts/restarts. The per core configuration 
 *     includes setting up Tx/Rx channels, allocating MAC addresses, enabling 
 *     interrupts in the EMAC control module for the channels that this core uses,
 *     and etc.
 *
 *     The calling application must supply an operating configuration. Data from 
 *     this config structure is copied into the device's internal instance structure
 *     so the structure may be discarded after EMAC_coreInit() returns. In order
 *     to change an item in the configuration, the core must be de-initialized from
 *     the EMAC device by calling EMAC_coreDeInit() and then re-initialized by 
 *     calling EMAC_coreInit() with the new configuration.
 *
 *     A valid EMAC core instance handle should be passed to this API to which the
 *     operating state of the EMAC device specific to individual cores will be written.
 *     The EMAC core instance structure for the handle needs to be initialized
 *     before calling EMAC_coreInit().
 *
 *     The application layer may pass in an hApplication callback handle, that 
 *     will be supplied by the EMAC device for the core when making calls to the
 *     core's application callback functions.
 *
 *     A valid EMAC device handle should be passed to this API to which the per 
 *     core configuration and operating state of the EMAC device will be written.
 *
 *     A core reset for EMAC operation is achieved by calling EMAC_coreDeInit() 
 *     followed by EMAC_coreInit().
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC           Handle to the EMAC device which needs to be initialized.
        hApplication    Application handle
        pEMACCoreConfig EMAC's configuration specific to the core
        hCore           Handle to the EMAC core instance which needs to be initialized.
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  Before calling this API, EMAC_commonInit function must be called on the master
 *      core and then EMAC_coreDeInit must be called for this particular core.
 *
 *  <b> Post Condition </b>
 *  @n  Core specific initialization to use the EMAC peripheral at the given 
 *      physical index.
 *
 *  @b Example
 *  @verbatim
        #define MASTER_CORE 0           // Which core is responsible for EMAC common initialization

        Uint32                 coreNum;
        Uint32                 i = 0, j = 0;
        EMAC_Common_Config     commonCfg;
        EMAC_Core_Config       coreCfg;
        EMAC_Device            EMACObj;
        EMAC_Core              EMACCore;
        EMAC_AddrConfig*       addrCfg;

        ...

        if (coreNum == MASTER_CORE)
		{
            // Initialize our EMAC Dev structure.
            memset(&EMACObj, 0, sizeof(EMAC_Device));
            // Common initialization of the EMAC peripheral
            EMAC_commonInit(0, &commonCfg, &EMACObj);
		}
        // Initialize EMAC core instance structure.
        memset(&EMACCore, 0, sizeof(EMAC_Core));

        //Total 3 MAC addresses allocated for the receive channel 
        coreCfg.NumOfMacAddrs = 3;
        // selects CPPI RAM for Descriptor memory 
        coreCfg.DescBase = EMAC_DESC_BASE_CPPI;

        coreCfg.RxMaxPktPool              = 8;
        coreCfg.pfcbGetPacket             = &GetPacket;
        coreCfg.pfcbFreePacket            = &FreePacket;
        coreCfg.pfcbRxPacket              = &RxPacket;
        coreCfg.pfcbStatus                = &StatusUpdate;
        coreCfg.pfcbStatistics            = &StatisticsUpdate;

        switch(coreNum) {
            default:
            case 0:                   // core 0 use channel 0 
                coreCfg.ChannelInfo.TxChanEnable = 1;
                coreCfg.ChannelInfo.RxChanEnable = 1;
                break;
            case 1:                   // core 1 use channel 1 
                coreCfg.ChannelInfo.TxChanEnable = 2;
                coreCfg.ChannelInfo.RxChanEnable = 2;
                break;
            case 2:                   // core 2 use channel 2 
                coreCfg.ChannelInfo.TxChanEnable = 4;
                coreCfg.ChannelInfo.RxChanEnable = 4;
                break;
        }

        //Configure the number of MAC addresses per channel
        //Hardware gives support for 32 MAC addresses for 8 receive channels
        //Here total 9 MAC addresses are assigned to 3 receive channels
        //3 MAC addresses per channel
        //MAC addresses and channels allocated are like mentioned below
        //  core no	   channel assigned       MAC address
        //   core0         channel 0        00.01.02.03.04.05
        //						            10.11.12.13.14.15
        //								    20.21.22.23.24.25(address used for loopback test)
        //
        //   core1         channel 1		30.31.32.33.34.35
        //									40.41.42.43.44.45
        //									50.51.52.53.54.55(address used for loopback test)
        //
        //	 core2         channel 2		60.61.62.63.64.65
        //									70.71.72.73.74.75
        //									80.81.82.83.84.85(address used for loopback test)

        coreCfg.MacAddr = (EMAC_AddrConfig **)
                          malloc(coreCfg.NumOfMacAddrs * sizeof(EMAC_AddrConfig *));

        for (j=0; j<coreCfg.NumOfMacAddrs; j++){
            coreCfg.MacAddr[j] = (EMAC_AddrConfig *)malloc(sizeof(EMAC_AddrConfig));
        }

        for(j=0; (Uint8)j<(coreCfg.NumOfMacAddrs); j++){
            addrCfg = coreCfg.MacAddr[j];
            addrCfg->ChannelNum = coreNum;
            for (i=0; i<6; i++)
            {
                addrCfg->Addr[i] = j * 0x10 + i + coreNum * 0x30;
            }
        }

        EMAC_coreDeInit(&EMACObj);
        EMAC_coreInit(&EMACObj, (Handle)0x12345678, &coreCfg, &EMACCore);
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_coreInit(Handle hEMAC, Handle hApplication, EMAC_Core_Config *pEMACCoreConfig, Handle hCore)
{
    int                 i, index, j;
    EMAC_AddrConfig*    tmp;
    Uint32              utemp1;
    Uint32              tmpval;
    CSL_EmacRegs*       emacRegs;
    EMAC_Device*        pEmacDev;
    Uint32              corenum = 0;
    EMAC_Pkt*           pPkt;
    EMAC_Desc*          pDesc;
    volatile Uint32*    pRegAddr;

    /*
     *  Validate the supplied configuration structure
     */
    if (!pEMACCoreConfig || !hEMAC || !hCore)
        return (EMAC_ERROR_INVALID);

    pEmacDev = (EMAC_Device *)hEMAC;
    if(!pEmacDev->InitOnce)
        return (EMAC_ERROR_INVALID);

    pEmacDev->pEMACCore[corenum] = (EMAC_Core*)hCore;

    /* Update our local copy of register handles too */
    emacRegs =  pEmacDev->emacRegs;

    /* Rx pool must be at least 8 to 60 */
    /* Max num of descriptors is 512 --> 64 for a channel*/
    if (pEMACCoreConfig->RxMaxPktPool < 8 || pEMACCoreConfig->RxMaxPktPool > 60)
        return( EMAC_ERROR_INVALID );

    /* MAC address must be supplied and not a multicast address */
    for (index=0; (Uint8)index<(pEMACCoreConfig->NumOfMacAddrs); index++){
        tmp = pEMACCoreConfig->MacAddr[index];
        if(tmp->Addr[0] & 1 )
            return( EMAC_ERROR_INVALID );
        for (i = 0; (i < 6) && (!(tmp->Addr[i])); i++);
        if (i == 6)
            return (EMAC_ERROR_INVALID);
    }

    /* test TxChanEnable and RxChanEnable*/
    if (pEMACCoreConfig->ChannelInfo.TxChanEnable > 255)
        return (EMAC_ERROR_INVALID);

    /* Rx Channels must be 1-8 */
    if (pEMACCoreConfig->ChannelInfo.RxChanEnable > 255)
        return (EMAC_ERROR_INVALID);

    for (i = 0; i < CSL_EMAC_NUMCORES; i++) {
        if(pEMACCoreConfig->ChannelInfo.TxChanEnable & pEmacDev->CoreConfig[i].ChannelInfo.TxChanEnable)
            return (EMAC_ERROR_INVALID); /* if not mutually exclusive */
    }

    for (i = 0; i < CSL_EMAC_NUMCORES; i++) {
        if(pEMACCoreConfig->ChannelInfo.RxChanEnable & pEmacDev->CoreConfig[i].ChannelInfo.RxChanEnable)
            return (EMAC_ERROR_INVALID); /* if not mutually exclusive */
    }

    /* Callback functions must be supplied */
    if (!pEMACCoreConfig->pfcbGetPacket || !pEMACCoreConfig->pfcbFreePacket ||
        !pEMACCoreConfig->pfcbRxPacket || !pEMACCoreConfig->pfcbStatus ||
        !pEMACCoreConfig->pfcbStatistics)
        return (EMAC_ERROR_INVALID);

    /* Set the hApplication */
    pEmacDev->pEMACCore[corenum]->hApplication = hApplication;

    /* Setup the new core specific configuration */
    pEmacDev->CoreConfig[corenum] = *pEMACCoreConfig;

    /* Setup device MAC addresses */
    for (index = 0; (Uint8)index < (pEMACCoreConfig->NumOfMacAddrs); index++) {
        for (i = 0; i < CSL_EMAC_NUMMACADDRS; i++) {
            if(pEmacDev->MacIndexUsed[i] == 0xFF) {
                tmp = pEMACCoreConfig->MacAddr[index];
                emacRegs->MACINDEX = i;

                tmpval = 0;
                for (j = 3; j >= 0; j--)
                    tmpval = (tmpval << 8) | tmp->Addr[j];

                emacRegs->MACADDRHI = tmpval;

                tmpval = tmp->Addr[5];
                emacRegs->MACADDRLO = CSL_FMKT(EMAC_MACADDRLO_VALID, VALID) |
                                      CSL_FMKT(EMAC_MACADDRLO_MATCHFILT, MATCH) |
                                      CSL_FMK(EMAC_MACADDRLO_CHANNEL, tmp->ChannelNum) |
                                      (tmpval << 8) |
                                      tmp->Addr[4];
                pEmacDev->MacIndexUsed[i] = corenum;
                break;
            }
        }
        if(i >= CSL_EMAC_NUMMACADDRS) return (EMAC_ERROR_INVALID);
    }


    /*
     * Enable TX and RX channel interrupts (set mask bits)
     */
    /*emacRegs->RXINTMASKSET |= pEMACCoreConfig->ChannelInfo.RxChanEnable << 16;
    emacRegs->TXINTMASKSET |= pEMACCoreConfig->ChannelInfo.TxChanEnable << 16;*/
    emacRegs->RXINTMASKSET = pEMACCoreConfig->ChannelInfo.RxChanEnable;
    emacRegs->TXINTMASKSET = pEMACCoreConfig->ChannelInfo.TxChanEnable;

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

    if (pEMACCoreConfig->DescBase == EMAC_DESC_BASE_CPPI) {
        if (pEmacDev->perNum == CSL_EMAC)
            pDesc = (EMAC_Desc *)CSL_EMAC_DSC_BASE_ADDR;
        else
            return (EMAC_ERROR_INVALID);
    }
    else {
        return (EMAC_ERROR_INVALID);
    }


    /* Number of descriptors for RX channel 64 per channel */
    utemp1 = 64 - (pEMACCoreConfig->RxMaxPktPool);

    /* Init all Rx channels in use */
    for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++) {
        if((1 << i) & (pEMACCoreConfig->ChannelInfo.RxChanEnable)) {
            pEmacDev->pEMACCore[corenum]->RxCh[i].pd = pEmacDev;
            pEmacDev->pEMACCore[corenum]->RxCh[i].ChannelIndex = i;
            pEmacDev->pEMACCore[corenum]->RxCh[i].DescMax    = (pEMACCoreConfig->RxMaxPktPool);
            pEmacDev->pEMACCore[corenum]->RxCh[i].pDescFirst = pDesc;
            pEmacDev->pEMACCore[corenum]->RxCh[i].pDescLast  = pDesc + ((pEMACCoreConfig->RxMaxPktPool)- 1);
            pEmacDev->pEMACCore[corenum]->RxCh[i].pDescRead  = pDesc;
            pEmacDev->pEMACCore[corenum]->RxCh[i].pDescWrite = pDesc;

            /* Fill the descriptor table */
            emacEnqueueRx(pEmacDev, &pEmacDev->pEMACCore[corenum]->RxCh[i], 0);
        }
        pDesc += 64;
    }

    /*
     * If we didn't get the number of descriptor buffers that the
     * application said we should, then the app lied to us. This is
     * bad because we'll be constantly calling to the app to fill
     * up our buffers. So we'll close now to make the problem
     * obvious.
     */
    for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++) {
        if((1<<i) & (pEMACCoreConfig->ChannelInfo.RxChanEnable)) {
            if (pEmacDev->pEMACCore[corenum]->RxCh[i].DescCount < (pEMACCoreConfig->RxMaxPktPool)) {
                /* Free all RX descriptors */
                while (pPkt = pqPop( &pEmacDev->pEMACCore[corenum]->RxCh[i].DescQueue)) {
                    (*pEMACCoreConfig->pfcbFreePacket)(pEmacDev->pEMACCore[corenum]->hApplication, pPkt);
                    pEmacDev->pEMACCore[corenum]->RxCh[i].DescCount--;
                }
                /* Return the error condition */
                return (EMAC_ERROR_INVALID);
            }
        }
    }
    /*
     * Setup Transmit Buffers
     */

    /* Pointer to first descriptor to use on TX Increase of pointer should not be done,
       because RX descriptor loop already increases pointer */
    /* pDesc += utemp1; */

    /* Number of descriptors (max) per channel */
    //utemp1 = (CSL_EMAC_DSC_ENTRY_COUNT-utemp1)/TotalTxChannels;

    /* Init TX channels in use */
    for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++){
        if((1<<i) & (pEMACCoreConfig->ChannelInfo.TxChanEnable)){
            pEmacDev->pEMACCore[corenum]->TxCh[i].pd         = pEmacDev;
            pEmacDev->pEMACCore[corenum]->TxCh[i].ChannelIndex = i;
            pEmacDev->pEMACCore[corenum]->TxCh[i].DescMax    = utemp1;
            /*Pointer for first TX desc = pointer to RX + num of RX desc.*/
            pDesc = (pEmacDev->pEMACCore[corenum]->RxCh[i].pDescFirst + (pEMACCoreConfig->RxMaxPktPool));
            pEmacDev->pEMACCore[corenum]->TxCh[i].pDescFirst = pDesc;
            pEmacDev->pEMACCore[corenum]->TxCh[i].pDescLast  = pDesc + (utemp1 - 1);
            pEmacDev->pEMACCore[corenum]->TxCh[i].pDescRead  = pDesc;
            pEmacDev->pEMACCore[corenum]->TxCh[i].pDescWrite = pDesc;
        }
    }

     /* Startup RX */
     for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++){
         if((1<<i) & (pEMACCoreConfig->ChannelInfo.RxChanEnable)) {
             pRegAddr = &emacRegs->RX0HDP;
             *(pRegAddr + i) = (Uint32)pEmacDev->pEMACCore[corenum]->RxCh[i].pDescRead;
         }
     }

	/* Enable interrupts in ECTL module */
	ECTL_REGS->C0_RX_EN = pEMACCoreConfig->ChannelInfo.RxChanEnable;
	ECTL_REGS->C0_TX_EN = pEMACCoreConfig->ChannelInfo.TxChanEnable;

    /* Return Success */
    return( 0 );
}

/** ============================================================================
 *  @n@b  EMAC_commonDeInit()
 *
 *  @b Description
 *  @n Shut down EMAC peripheral indicated by the supplied EMAC device handle: 
 *     tear down both send and receive operations, resets common configuration,
 *     and bring down the MDIO link. Called by the master core only. 
 *   . 
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to opened the EMAC device
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC_open (on the master core) or EMAC_commonInit function must be called
 *      before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  The EMAC device will shutdown both send and receive operations, resets common
 *      configuration, and bring down the MDIO link.
 *
 *  @b Example
 *  @verbatim
        EMAC_Config     ecfg;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;
        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        //Shut down EMAC operation for a core
        EMAC_coreDeInit( &EMACObj );

        ...

        //Shut down the EMAC peripheral
        EMAC_commonDeInit( &EMACObj );
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_commonDeInit(Handle hEMAC)
{
    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
    CSL_EmacRegs    *emacRegs;
    Uint32          corenum = 0;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC || !pd->InitOnce)
        return (EMAC_ERROR_INVALID);

    emacRegs = pd->emacRegs;

    if(corenum != pd->Config.CoreNum)
        return (EMAC_ERROR_INVALID);

    /* Disable EMAC/MDIO interrupts pacing in wrapper */
	ECTL_REGS->INT_CONTROL = 0x00000000; /*Disable Wrapper interrupts pacing */
    ECTL_REGS->C0_RX_EN = 0x00;/*Disable all Rx channels */
	ECTL_REGS->C0_TX_EN = 0x00;/*Disable all Tx channels */

    /* Disable RX, TX, and Clear MACCONTROL */
    CSL_FINST(emacRegs->TXCONTROL, EMAC_TXCONTROL_TXEN, DISABLE);
    CSL_FINST(emacRegs->RXCONTROL, EMAC_RXCONTROL_RXEN, DISABLE);
    emacRegs->MACCONTROL = 0;

    if (pd->Config.UseMdio)
       /* Close the MDIO Module */
        MDIO_close( &pd->MdioDev );

    /* Invalidate the EMAC handle */
    pd->DevMagic = 0;

    pd->emacRegs     = NULL;
    pd->ectlRegs     = NULL;
    pd->perNum       = (CSL_InstNum) -1;
    pd->InitOnce     = 0;

    /* Exit with interrupts still disabled in the wrapper */
    return (0);
}

/** ============================================================================
 *  @n@b  EMAC_coreDeInit()
 *
 *  @b Description
 *  @n Shut down EMAC operation for a core. When called, free all pending transmit
 *     and receive packets for the core, and release Tx/Rx channels used and 
 *     MAC addresses assigned
 *   . 
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to opened the EMAC device
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC_open (on the master core) or EMAC_commonInit function must be called
 *      before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  The EMAC device will free all pending transmit and receive packets for the 
 *      core, and also release Tx/Rx channels used and MAC addresses assigned.
 *
 *  @b Example
 *  @verbatim
        EMAC_Config     ecfg;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;
        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        //Shut down EMAC operation for a core
        EMAC_coreDeInit( &EMACObj );
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_coreDeInit(Handle hEMAC)
{
    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
    Uint32          tmp, index;
    volatile Uint32 *pRegAddr;
    CSL_EmacRegs    *emacRegs;
    Uint32          corenum = 0;
    int             i;
    EMAC_Pkt        *pPkt;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC)
        return (EMAC_ERROR_INVALID);

    emacRegs = pd->emacRegs;

    /*
     * The close process consists of tearing down all the active channels 
     * (RX and TX) used by the core and then waiting for the teardown complete 
     * indication from the MAC. Then, all queued packets will be returned.
     */

    /* Teardown RX */
    for (index = 0; index < CSL_EMAC_NUMCHANNELS; index++){
        if((1<<index) & (pd->CoreConfig[corenum].ChannelInfo.RxChanEnable)) {
          emacRegs->RXTEARDOWN = index ;
        }
    }

    /* Teardown TX */
    for (index = 0; index < CSL_EMAC_NUMCHANNELS; index++){
        if((1<<index) & (pd->CoreConfig[corenum].ChannelInfo.TxChanEnable)) {
          emacRegs->TXTEARDOWN = index ;
        }
    }

    /* Only check teardown status if there was no fatal error         */
    /* Otherwise; the EMAC is halted and can’t be shutdown gracefully */
    if (!pd->FatalError)
    {
        /* Wait for the teardown to complete */
        pRegAddr = &emacRegs->RX0CP;
        for (index = 0; index < CSL_EMAC_NUMCHANNELS; index++)
        {
          if((1<<index) & (pd->CoreConfig[corenum].ChannelInfo.RxChanEnable)) {
            for (tmp = 0; tmp != 0xFFFFFFFC; tmp = *(pRegAddr + index));
          }
          *(pRegAddr + index) = tmp;
        }

        pRegAddr = &emacRegs->TX0CP;
        for (index=0; index< CSL_EMAC_NUMCHANNELS; index++)
        {
          if((1<<index) & (pd->CoreConfig[corenum].ChannelInfo.TxChanEnable)) {
            for (tmp = 0; tmp != 0xFFFFFFFC; tmp = *(pRegAddr + index));
          }
          *(pRegAddr + index) = tmp;
        }
    }

    /* Disable EMAC/MDIO interrupts pacing in wrapper */
	ECTL_REGS->INT_CONTROL = 0x00000000; /*Disable Wrapper interrupts pacing */
    ECTL_REGS->C0_RX_EN = 0x00;/*Disable all Rx channels */
	ECTL_REGS->C0_TX_EN = 0x00;/*Disable all Tx channels */

    /* Free all RX buffers used by the core */
    for (index = 0; index < CSL_EMAC_NUMCHANNELS; index++){
        if((1<<index) & (pd->CoreConfig[corenum].ChannelInfo.RxChanEnable)) {
            while (pPkt = pqPop( &pd->pEMACCore[corenum]->RxCh[index].DescQueue))  {
                (*pd->CoreConfig[corenum].pfcbFreePacket)(pd->pEMACCore[corenum]->hApplication, pPkt);
                pd->pEMACCore[corenum]->RxCh[index].DescCount--;
            }
        }
    }

    /* Free all TX buffers used by the core */
    for (index = 0; index < CSL_EMAC_NUMCHANNELS; index++){
        if((1<<index) & (pd->CoreConfig[corenum].ChannelInfo.TxChanEnable)) {
            while (pPkt = pqPop( &pd->pEMACCore[corenum]->TxCh[index].DescQueue)) {
                (*pd->CoreConfig[corenum].pfcbFreePacket)(pd->pEMACCore[corenum]->hApplication, pPkt);
                pd->pEMACCore[corenum]->TxCh[index].DescCount--;
            }
            while (pPkt = pqPop(&pd->pEMACCore[corenum]->TxCh[index].WaitQueue)) {
                (*pd->CoreConfig[corenum].pfcbFreePacket)(pd->pEMACCore[corenum]->hApplication, pPkt);
                pd->pEMACCore[corenum]->TxCh[index].WaitQueue.Count--;
            }
        }
    }

    /* Reset MacIndexUsed */
    for (i = 0; i < CSL_EMAC_NUMMACADDRS; i++){
        if(pd->MacIndexUsed[i] == corenum)
            pd->MacIndexUsed[i] = 0xFF;
    }

    /* Reset Tx and Rx ChannelInfo */
    pd->CoreConfig[corenum].ChannelInfo.RxChanEnable = 0;
    pd->CoreConfig[corenum].ChannelInfo.TxChanEnable = 0;

    return (0);
}

/** ============================================================================
 *  @n@b  EMAC_close()
 *
 *  @b Description
 *  @n When called by a core, free all pending transmit and receive packets, and 
 *     release Tx/Rx channels used and MAC addresses assigned via.calling 
 *     EMAC_coreDeInit(). When called by the master core, furhter close the EMAC
 *     peripheral indicated by the supplied EMAC device handle, shutdown both send
 *     and receive operations, and bring down the MDIO link via calling 
 *     EMAC_commonDeInit().
 *   . 
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to opened the EMAC device
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC_open, or EMAC_commonInit/EMAC_coreInit function must be called before
 *      calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  For any core, the EMAC device will free all pending transmit and receive 
 *      packets, release Tx/Rx channels used and MAC addresses assigned. For master
 *      core, the EMAC device will further shutdown both send and receive operations
 *      and bring down the MDIO link.
 *
 *  @b Example
 *  @verbatim
        EMAC_Config     ecfg;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;

        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        //Close the EMAC peripheral
        EMAC_close( &EMACObj );
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_close(Handle hEMAC)
{
    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
    Uint32          corenum = 0;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC)
        return (EMAC_ERROR_INVALID);

    if (EMAC_coreDeInit(hEMAC))
        return (EMAC_ERROR_INVALID);

    if (corenum == pd->Config.CoreNum)  {
        if (EMAC_commonDeInit(hEMAC))
            return (EMAC_ERROR_INVALID);
    }
    /* Return Success */
    return( 0 );
}



/** ============================================================================
 *  @n@b  EMAC_setReceiveFilter()
 *
 *  @b Description
 *  @n Called to set the packet filter for received packets. The filtering
 *     level is inclusive, so BROADCAST would include both BROADCAST and
 *     DIRECTED (UNICAST) packets.
 *
 *     Available filtering modes include the following:
 *         - EMAC_RXFILTER_NOTHING      - Receive nothing
 *         - EMAC_RXFILTER_DIRECT       - Receive only Unicast to local MAC addr
 *         - EMAC_RXFILTER_BROADCAST    - Receive direct and Broadcast
 *         - EMAC_RXFILTER_MULTICAST    - Receive above plus multicast in mcast list
 *         - EMAC_RXFILTER_ALLMULTICAST - Receive above plus all multicast
 *         - EMAC_RXFILTER_ALL          - Receive all packets
 *
 *     Note that if error frames and control frames are desired, reception of
 *     these must be specified in the device configuration.
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *         EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
         hEMAC           handle to the opened EMAC device
         ReceiveFilter   Filtering modes
         masterChannel   master core channel which receives broadcast frames
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened before calling this API
 *
 *  <b> Post Condition </b>
 *  @n  Sets the packet filter for received packets
 *
 *  @b Example
 *  @verbatim
        #define EMAC_RXFILTER_DIRECT       1
        EMAC_Config  ecfg;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;

        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        EMAC_setReceiveFilter(&EMACObj, EMAC_RXFILTER_DIRECT, 0);

    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_setReceiveFilter(Handle hEMAC, Uint32 ReceiveFilter, Uint8 masterChannel)
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;
    Uint32              EnabledRxChannel;
	Uint32			corenum = 0;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC || ReceiveFilter > EMAC_RXFILTER_ALL) 
        return (EMAC_ERROR_INVALID);
  
		EnabledRxChannel = pd->CoreConfig[corenum].ChannelInfo.RxChanEnable;
    /*
     * The following code relies on the numeric relation of the filter
     * value such that the higher filter values receive more types of
     * packets.
     */

    /* Disable Section */
    if (ReceiveFilter < EMAC_RXFILTER_ALL)
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXCAFEN, DISABLE);
    if (ReceiveFilter < EMAC_RXFILTER_ALLMULTICAST) {
        EMAC_REGS->MACHASH1 = pd->MacHash1;
        EMAC_REGS->MACHASH2 = pd->MacHash2;
    }
    if (ReceiveFilter < EMAC_RXFILTER_MULTICAST)
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXMULTEN, DISABLE);
    if (ReceiveFilter < EMAC_RXFILTER_BROADCAST)
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXBROADEN, DISABLE);
    if (ReceiveFilter < EMAC_RXFILTER_DIRECT) {
        EMAC_REGS->RXUNICASTCLEAR = EnabledRxChannel;
    }

    /* Enable Section */
    if (ReceiveFilter >= EMAC_RXFILTER_DIRECT) {
        EMAC_REGS->RXUNICASTSET = EnabledRxChannel;
    }

    if (ReceiveFilter >= EMAC_RXFILTER_BROADCAST) {
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXBROADEN, ENABLE);
		CSL_FINS(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXBROADCH, masterChannel);
	}
    if (ReceiveFilter >= EMAC_RXFILTER_MULTICAST) {
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXMULTEN, ENABLE);
		CSL_FINS(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXMULTCH, masterChannel);
	}
    if (ReceiveFilter >= EMAC_RXFILTER_ALLMULTICAST) {
        EMAC_REGS->MACHASH1 = 0xffffffff;
        EMAC_REGS->MACHASH2 = 0xffffffff;
    }
    if (ReceiveFilter == EMAC_RXFILTER_ALL) {
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXCAFEN, ENABLE);
		CSL_FINS(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXPROMCH, masterChannel);
	}

    pd->RxFilter = ReceiveFilter;
    return (0);
}


/** ============================================================================
 *  @n@b  EMAC_getReceiveFilter()
 *
 *  @b Description
 *  @n Called to get the current packet filter setting for received packets.
 *     The filter values are the same as those used in EMAC_setReceiveFilter().
 *
 *     The current filter value is written to the pointer supplied in
 *     pReceiveFilter.
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *       EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC           handle to the opened EMAC device
        pReceiveFilter  Current receive packet filter
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened before calling this API and
 *      must be set the packet filter value.
 *
 *  <b> Post Condition </b>
 *  @n  The current filter value is written to the pointer supplied
 *
 *  @b Example
 *  @verbatim
        #define EMAC_RXFILTER_DIRECT       1
        EMAC_Config     ecfg;
        Uint32          pReceiveFilter;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;

        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        EMAC_setReceiveFilter(&EMACObj, EMAC_RXFILTER_DIRECT, 0);

        EMAC_getReceiveFilter(&EMACObj, &pReceiveFilter );
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_getReceiveFilter(Handle hEMAC, Uint32 *pReceiveFilter)
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC || !pReceiveFilter)
        return (EMAC_ERROR_INVALID);

    *pReceiveFilter = pd->RxFilter;
    return (0);
}


/** ============================================================================
 *  @n@b  EMAC_getStatistics()
 *
 *  @b Description
 *  @n Called to get the current device statistics. The statistics structure
 *     contains a collection of event counts for various packet sent and
 *     receive properties. Reading the statistics also clears the current
 *     statistic counters, so the values read represent a delta from the last
 *     call.
 *
 *     The statistics information is copied into the structure pointed to
 *     by the pStatistics argument.
 *
 *     The function returns zero on success, or an error code on failure.
 *
 *     Possible error code include:
 *      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
        pStatistics Get the device statistics
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened before calling this API
 *
 *  <b> Post Condition </b>
 *      -# Statistics are read for various packects sent and received.
        -# Reading the statistics also clears the current
           statistic counters, so the values read represent a delta from the
           last call.
 *
 *  @b Example
 *  @verbatim
        EMAC_Config     ecfg;
        EMAC_Statistics pStatistics;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;

        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        EMAC_getStatistics(&EMACObj, &pStatistics );
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_getStatistics(Handle hEMAC, EMAC_Statistics *pStatistics)
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC || !pStatistics)
        return (EMAC_ERROR_INVALID);

    /* Update the stats */
    emacUpdateStats(pd);

    /* Copy the updated stats to the application */
    *pStatistics = pd->Stats;

    /* Clear our copy */
    memset(&pd->Stats, 0, sizeof(EMAC_Statistics));

    return (0);
}


/** ============================================================================
 *  @n@b  EMAC_setMulticast()
 *
 *  @b Description
 *  @n This function is called to install a list of multicast addresses for
 *     use in multicast address filtering. Each time this function is called,
 *     any current multicast configuration is discarded in favor of the new
 *     list. Thus a set with a list size of zero will remove all multicast
 *     addresses from the device.
 *
 *     Note that the multicast list configuration is stateless in that the
 *     list of multicast addresses used to build the configuration is not
 *     retained. Thus it is impossible to examine a list of currently installed
 *     addresses.
 *
 *     The addresses to install are pointed to by pMCastList. The length of
 *     this list in bytes is 6 times the value of AddrCnt. When AddrCnt is
 *     zero, the pMCastList parameter can be NULL.
 *
 *     The function returns zero on success, or an error code on failure.
 *     The multicast list settings are not altered in the event of a failure
 *     code.
 *
 *     Possible error code include:
 *       EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
        AddrCount   number of addresses to multicast
        pMCastList  pointer to the multi cast list
    @endverbatim
 *
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened and set multicast filter.
 *
 *  <b> Post Condition </b>
        -# Install a list of multicast addresses for use in multicast
           address filtering.
        -# A set with a list size of zero will remove all multicast addresses
           from the device.
 *
 *  @b Example
 *  @verbatim
        #define EMAC_RXFILTER_ALLMULTICAST 4

        Uint32          AddrCnt;
        Uint8           pMCastList;
        EMAC_Config     ecfg;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;

        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        EMAC_setReceiveFilter( &EMACObj, EMAC_RXFILTER_ALLMULTICAST, 0);

        EMAC_setMulticast( &EMACObj, AddrCnt, &pMCastList );
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_setMulticast(Handle hEMAC, Uint32 AddrCnt, Uint8 *pMCastList)
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;
    Uint32        tmp1,tmp2;
    Uint8       HashVal,tmpval;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC || (AddrCnt && !pMCastList))
        return (EMAC_ERROR_INVALID);

    /* Clear the hash bits */
    pd->MacHash1 = 0;
    pd->MacHash2 = 0;

    /* For each address in the list, hash and set the bit */
    for (tmp1=0; tmp1<AddrCnt; tmp1++) {
        HashVal=0;

        for (tmp2=0; tmp2 < 2; tmp2++) {
            tmpval = *pMCastList++;
            HashVal ^= (tmpval >> 2) ^ (tmpval << 4);
            tmpval = *pMCastList++;
            HashVal ^= (tmpval >> 4) ^ (tmpval << 2);
            tmpval = *pMCastList++;
            HashVal ^= (tmpval >> 6) ^ (tmpval);
        }

        if (HashVal & 0x20)
            pd->MacHash2 |= (1 << (HashVal & 0x1f));
        else
            pd->MacHash1 |= (1 << (HashVal & 0x1f));
    }

    /* We only write the hash table if the filter setting allows */
    if (pd->RxFilter < EMAC_RXFILTER_ALLMULTICAST) {
        EMAC_REGS->MACHASH1 = pd->MacHash1;
        EMAC_REGS->MACHASH2 = pd->MacHash2;
    }

    return (0);
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
 *       EMAC_ERROR_INVALID   - A calling parameter is invalid
 *       EMAC_ERROR_BADPACKET - The packet structure is invalid
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
        pPkt        EMAC packet structure
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *  @n      EMAC_ERROR_BADPACKET - The packet structure is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened and get a packet
 *      buffer from private queue
 *
 *  <b> Post Condition </b>
 *  @n  Sends a ethernet data packet out the EMAC device and is returned to the
 *      application's free pool once it has been transmitted.
 *
 *  @b Example
 *  @verbatim
        #define EMAC_RXFILTER_DIRECT       1
        #define EMAC_PKT_FLAGS_SOP         0x80000000u
        #define EMAC_PKT_FLAGS_EOP         0x40000000u

        EMAC_Config     ecfg;
        EMAC_Pkt        *pPkt;
        Uint32          size, TxCount = 0;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;

        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...

        //set the receive filter
        EMAC_setReceiveFilter( &EMACObj, EMAC_RXFILTER_DIRECT, 0);

        //Fill the packet options fields
        size = TxCount + 60;
        pPkt->Flags      = EMAC_PKT_FLAGS_SOP | EMAC_PKT_FLAGS_EOP;
        pPkt->ValidLen   = size;
        pPkt->DataOffset = 0;
        pPkt->PktChannel = 0;
        pPkt->PktLength  = size;
        pPkt->PktFrags   = 1;

        EMAC_sendPacket( &EMACObj, pPkt );

    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_sendPacket(Handle hEMAC, EMAC_Pkt *pPkt)
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;
    Uint32        fragcnt,pktlen,i;
    EMAC_Pkt     *pPktLast;
    EMAC_DescCh  *pdc;
	Uint32		corenum = 0;	

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC || !pPkt)
        return (EMAC_ERROR_INVALID);

    /* Do some packet validation */
    if (!(pPkt->Flags & EMAC_PKT_FLAGS_SOP))
        return (EMAC_ERROR_BADPACKET);

	/* Verify to channel to use is the channel enabled */
	for(i=0; i<CSL_EMAC_NUMCHANNELS; i++) {
		if((1<<i) & (pd->CoreConfig[corenum].ChannelInfo.TxChanEnable)) {
			if(pPkt->PktChannel == i) break;
		}
	}
	if(i == CSL_EMAC_NUMCHANNELS)
        return (EMAC_ERROR_BADPACKET);

    if (pPkt->PktLength < 14 || pPkt->PktLength > pd->PktMTU)
        return (EMAC_ERROR_BADPACKET);

    /* Count the number of frags in this packet */
    fragcnt = 1;
    pktlen  = pPkt->PktLength;

    pPktLast = pPkt;
    while (!(pPktLast->Flags & EMAC_PKT_FLAGS_EOP)) {
        if (!pPktLast->pNext)
            return (EMAC_ERROR_INVALID);
        pktlen -= pPktLast->ValidLen;
        pPktLast = pPktLast->pNext;
        fragcnt++;

        /* At this point we can't have another SOP */
        if (pPktLast->Flags & EMAC_PKT_FLAGS_SOP)
            return (EMAC_ERROR_INVALID);
    }

    /* Make sure PktLength and ValidLen agree */
    if (pktlen != pPktLast->ValidLen)
        return (EMAC_ERROR_BADPACKET);

    /* The final packet frag must be the last in the list */
    if (pPktLast->pNext)
        return (EMAC_ERROR_BADPACKET);

    /* The frag count must be correct */
    if (fragcnt != pPkt->PktFrags)
        return (EMAC_ERROR_BADPACKET);

    /* Now pad for 60 byte min size. We only pad the last fragment */
    if (pPkt->PktLength < 60) {
        pktlen = 60 - pPkt->PktLength;
        pPkt->PktLength = 60;
        pPktLast->ValidLen += pktlen;
    }

    /* Get a local pointer to the descriptor channel */
    pdc = &(pd->pEMACCore[corenum]->TxCh[pPkt->PktChannel]);

    /* Make sure this packet does not have too many frags to fit */
    if (fragcnt > pdc->DescMax)
        return (EMAC_ERROR_BADPACKET);

    /*
     * Queue and packet and service transmitter
     */
    pqPushChain(&pdc->WaitQueue, pPkt, pPktLast, fragcnt);
    emacEnqueueTx(pdc);

    return (0);
}


/** ============================================================================
 *  @n@b  EMAC_RxServiceCheck()
 *
 *  @b Description
 *  @n This function should be called every time there is an EMAC device Rx
 *     interrupt. It maintains the status the EMAC.
 *
 *     Note that the application has the responsibility for mapping the
 *     physical device index to the correct EMAC_serviceCheck() function. If
 *     more than one EMAC device is on the same interrupt, the function must be
 *     called for each device.
 *
 *     Possible error codes include:
 *       EMAC_ERROR_INVALID   - A calling parameter is invalid
 *       EMAC_ERROR_MACFATAL  - Fatal error in the MAC - Call EMAC_close()
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n     EMAC_ERROR_INVALID   - A calling parameter is invalid
 *  @n     EMAC_ERROR_MACFATAL  - Fatal error in the MAC - Call EMAC_close()
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC_open function must be called before calling this API.
 *
 *  <b> Post Condition </b>
 *  @n  None
 *
 *  @b Example
 *  @verbatim
        static CSL_IntcContext context;
        static CSL_IntcEventHandlerRecord Record[13];
        static CSL_IntcObj intcEMACRx;
        static CSL_IntcHandle hIntcEMACRx;

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

        // Opening a handle for EMAC Rx interrupt
        hIntcEMACRx=CSL_intcOpen(&intcEMACRx,CSL_INTC_EVENTID_6,&vectId2,NULL);

        //Hook the ISRs
        CSL_intcHookIsr(vectId2,&HwRxInt);

        CSL_intcHwControl(hIntcEMACRx, CSL_INTC_CMD_EVTENABLE, NULL);

        // This function is called when Rx interrupt occurs
        Void HwRxInt (void)
        {
            EMAC_Device     EMACObj;
            EMAC_Core       EMACCore;

            ...

            //Open the EMAC peripheral
            EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

            ...
	        
            EMAC_RxServiceCheck(&EMACObj);
        }

    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_RxServiceCheck(Handle hEMAC)
{
    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
	Uint32          intflags,Desc; //,mask;
    volatile Uint32 *pRegAddr;
    int             i;
    Uint32          corenum = 0;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC)
        return (EMAC_ERROR_INVALID);

    /* Read the interrupt cause */
    intflags = EMAC_REGS->MACINVECTOR;

    /* Look for fatal errors first */
    if (intflags & CSL_FMK(EMAC_MACINVECTOR_HOSTPEND, 1)) {
        /* Read the error status - we'll decode it by hand */
        pd->FatalError = EMAC_REGS->MACSTATUS;

        /* Tell the application */
        (*pd->CoreConfig[corenum].pfcbStatus)(pd->pEMACCore[corenum]->hApplication);

        /* return with interrupt disabled in the wrapper */
        return (EMAC_ERROR_MACFATAL);
    }

    /* Look for statistics interrupt */
    if (intflags & CSL_FMK(EMAC_MACINVECTOR_STATPEND, 1)) {
        /* Read the stats and reset to zero         */
        /* This is necessary to clear the interrupt */
        emacUpdateStats(pd);

        /* Tell the application */
        (*pd->CoreConfig[corenum].pfcbStatistics)(pd->pEMACCore[corenum]->hApplication);
    }

    pRegAddr = &EMAC_REGS->RX0CP;

    /* Look for RX interrupt (channel 0) */
    for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++){
        if((1<<i) & (pd->CoreConfig[corenum].ChannelInfo.RxChanEnable)){
            if((1<<i) & (EMAC_REGS->RXINTSTATRAW))              /* Check if the interrupt happened on the channel 'i' */
			 {  
        	    /*
         	     * For multichannel operation, we need to apply the
         	     * same errata workaround as TX. However this driver
             	 * example only supports one RX channel.
         	     */
        	    Desc = *(pRegAddr + i);
        	    *(pRegAddr + i) = Desc;

        	    emacDequeueRx(pd, &pd->pEMACCore[corenum]->RxCh[i], (EMAC_Desc *)Desc);
        	    /* Re-fill Rx buffer queue if needed */
        	    if (pd->pEMACCore[corenum]->RxCh[i].DescCount != pd->pEMACCore[corenum]->RxCh[i].DescMax)
            	    emacEnqueueRx(pd, &pd->pEMACCore[corenum]->RxCh[i], 1);
            }
        }
    }

    EMAC_REGS->MACEOIVECTOR = 0x01;     // core 0, C0_RX_PULSE = 0x01

    return(0);
}


/** ============================================================================
 *  @n@b  EMAC_TxServiceCheck()
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
 *       EMAC_ERROR_INVALID   - A calling parameter is invalid
 *       EMAC_ERROR_MACFATAL  - Fatal error in the MAC - Call EMAC_close()
 *
 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
    @endverbatim
 *  <b> Return Value </b>  Success (0)
 *  @n     EMAC_ERROR_INVALID   - A calling parameter is invalid
 *  @n     EMAC_ERROR_MACFATAL  - Fatal error in the MAC - Call EMAC_close()
 *
 *  <b> Pre Condition </b>
 *  @n EMAC_open function must be called before calling this API.
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
        hIntcEMACTx=CSL_intcOpen(&intcEMACTx,CSL_INTC_EVENTID_6,&vectId2,NULL);

        //Hook the ISRs
        CSL_intcHookIsr(vectId2,&HwTxInt);

        CSL_intcHwControl(hIntcEMACTx, CSL_INTC_CMD_EVTENABLE, NULL);

        // This function is called when Rx interrupt occurs
        Void HwTxInt (void)
        {
            EMAC_Device     EMACObj;
            EMAC_Core       EMACCore;

            ...

            //Open the EMAC peripheral
            EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

            ...

            EMAC_TxServiceCheck(&EMACObj);
        }

    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_TxServiceCheck(Handle hEMAC)
{
    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
    Uint32          intflags,Desc; //,mask;
	Uint32          i;
    volatile Uint32 *pRegAddr;
    Uint32          corenum = 0;

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC)
        return (EMAC_ERROR_INVALID);

    /* Read the interrupt cause */
    intflags = EMAC_REGS->MACINVECTOR;

    /* Look for fatal errors first */
    if (intflags & CSL_FMK(EMAC_MACINVECTOR_HOSTPEND, 1)) {
        /* Read the error status - we'll decode it by hand */
        pd->FatalError = EMAC_REGS->MACSTATUS;

        /* Tell the application */
        (*pd->CoreConfig[corenum].pfcbStatus)(pd->pEMACCore[corenum]->hApplication);

        /* return with interrupt disabled in the wrapper */
        return (EMAC_ERROR_MACFATAL);
    }

    /* Look for statistics interrupt */
    if (intflags & CSL_FMK(EMAC_MACINVECTOR_STATPEND, 1)) {
        /* Read the stats and reset to zero         */
        /* This is necessary to clear the interrupt */
        emacUpdateStats(pd);

        /* Tell the application */
        (*pd->CoreConfig[corenum].pfcbStatistics)(pd->pEMACCore[corenum]->hApplication);
    }

    pRegAddr = &EMAC_REGS->TX0CP;

    /* Look for TX interrupt (channel 0-max) */
    for (i = 0; i < CSL_EMAC_NUMCHANNELS; i++){
		if((1<<i) & (pd->CoreConfig[corenum].ChannelInfo.TxChanEnable)) {   /* find out which channel is enabled */
			 if((1<<i) & (EMAC_REGS->TXINTSTATRAW)) {        /* find out if the interrupt happend */
        	    Desc = *(pRegAddr + i);
        	    *(pRegAddr + i) = Desc;

        	    emacDequeueTx(pd, &pd->pEMACCore[corenum]->TxCh[i], (EMAC_Desc *)Desc);
            }
		}
    }

	EMAC_REGS->MACEOIVECTOR = 0x02;     // core 0, C0_TX_PULSE = 0x02

    return (0);
}



/** ============================================================================
 *  @n@b  EMAC_timerTick()
 *
 *  @b Description
 *  @n This function should be called for each device in the system on a
 *     periodic basis of 100mS (10 times a second). It is used to check the
 *     status of the EMAC and MDIO device, and to potentially recover from
 *     low Rx buffer conditions.
 *
 *     Strict timing is not required, but the application should make a
 *     reasonable attempt to adhere to the 100mS mark. A missed call should
 *     not be "made up" by making multiple sequential calls.
 *
 *     A "polling" driver (one that calls EMAC_serviceCheck() in a tight loop),
 *     must also adhere to the 100mS timing on this function.
 *
 *     Possible error codes include:
 *       EMAC_ERROR_INVALID   - A calling parameter is invalid

 *  @b Arguments
 *  @verbatim
        hEMAC       handle to the opened EMAC device
    @endverbatim
 *
 *  <b> Return Value </b>  Success (0)
 *  @n      EMAC_ERROR_INVALID   - A calling parameter is invalid
 *
 *  <b> Pre Condition </b>
 *  @n  EMAC peripheral instance must be opened
 *
 *  <b> Post Condition </b>
 *  @n  Re-fill Rx buffer queue if needed and modifies  EMAC CONTROL register.
 *
 *  @b Example
 *  @verbatim
        EMAC_Config ecfg;
        EMAC_Device     EMACObj;
        EMAC_Core       EMACCore;

        ...

        //Open the EMAC peripheral
        EMAC_open(0, (Handle)0x12345678, &ecfg, &EMACObj, &EMACCore);

        ...


        EMAC_timerTick( &EMACObj );
    @endverbatim
 * ============================================================================
 */
Uint32 EMAC_timerTick(Handle hEMAC)
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;
    Uint32       mdioStatus,linkStatus;
	Uint32       i;
    Uint32          corenum = 0;  

    /* Validate our handle */
    if (!pd || pd->DevMagic != EMAC_DEVMAGIC)
        return( EMAC_ERROR_INVALID );

    if (pd->Config.UseMdio) {
        /* Signal the MDIO */
        mdioStatus = MDIO_timerTick( &pd->MdioDev );

	    /* On a new link, set the EMAC duplex */
        if (mdioStatus == MDIO_EVENT_LINKUP)
        {
            MDIO_getStatus(&pd->MdioDev, 0, &linkStatus);

            if (linkStatus == MDIO_LINKSTATUS_FD10  ||
                linkStatus == MDIO_LINKSTATUS_FD100 ||
                linkStatus == MDIO_LINKSTATUS_FD1000 ) {
                CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_FULLDUPLEX, ENABLE );
		    }
            else {
                CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_FULLDUPLEX, DISABLE );
            }

		    if (linkStatus == MDIO_LINKSTATUS_FD1000)
			    CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_GIG, ENABLE );
	    }

	    if (mdioStatus != MDIO_EVENT_NOCHANGE)
	        (*pd->CoreConfig[corenum].pfcbStatus)(pd->pEMACCore[corenum]->hApplication);
    }

    /* Re-fill Rx buffer queue if needed */
	for(i=0; i<CSL_EMAC_NUMCHANNELS; i++) {
		if((1<<i) & (pd->CoreConfig[corenum].ChannelInfo.RxChanEnable)) {
		    if (pd->pEMACCore[corenum]->RxCh[i].DescCount != pd->pEMACCore[corenum]->RxCh[i].DescMax)
			   emacEnqueueRx(pd, &pd->pEMACCore[corenum]->RxCh[i], 1);
		}
    }

    return (0);
}

