/**
 *  \file  asciiutils.c
 *
 * \brief  This file contain functions which compute ASCII for standard
 *         operations.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <string.h>
#include "types.h"
#include "edma.h"
#include "console_utils.h"
#include "mmcsd_lib.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Width of the data response buffer. */
#define DATA_RESPONSE_WIDTH       (SOC_CACHELINE_SIZE)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/* Cache size aligned data buffer (minimum of 64 bytes) for command response */
#ifdef __TMS470__
#pragma DATA_ALIGN(dataBuffer, SOC_CACHELINE_SIZE);
static uint8_t dataBuffer[DATA_RESPONSE_WIDTH];

#elif defined(__IAR_SYSTEMS_ICC__)
#pragma data_alignment = SOC_CACHELINE_SIZE
static uint8_t dataBuffer[DATA_RESPONSE_WIDTH];

#elif defined(gcc)
static uint8_t dataBuffer[DATA_RESPONSE_WIDTH]
                               __attribute__((aligned(SOC_CACHELINE_SIZE)));

#else
#error "Unsupported compiler\n\r"
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t MMCSDLibCmdSend(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCmd_t *pCmd)
{
    return pCtrl->pfnCmdSend(pCtrl, pCmd);
}

uint32_t MMCSDLibAppCmdSend(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCmd_t *pCmd)
{
    uint32_t status = FALSE;
    mmcsdLibCmd_t cmdApp;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        /* APP cmd should be preceeded by a CMD55 */
        cmdApp.idx = MMCSD_LIB_CMD(55U);
        cmdApp.flags = 0U;
        cmdApp.arg = pCtrl->pCard->rca << 16U;
        status = MMCSDLibCmdSend(pCtrl, &cmdApp);
    }

    /* return safely, since we cannot continue if CMD55 fails */
    if (FALSE != status)
    {
        status = MMCSDLibCmdSend(pCtrl, pCmd);
    }

    return status;
}

uint32_t MMCSDLibBusWidthSet(mmcsdLibCtrlInfo_t *pCtrl)
{
    mmcsdLibCardInfo_t *pCard = pCtrl->pCard;
    uint32_t status = FALSE;
    mmcsdLibCmd_t cmdApp;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        cmdApp.idx = MMCSD_LIB_CMD(6U);
        cmdApp.arg = MMCSD_LIB_BUS_WIDTH_1BIT;
        cmdApp.flags = 0U;

        if (pCtrl->busWidth & MMCSD_LIB_BUS_WIDTH_4BIT)
        {
            if (pCard->busWidth & MMCSD_LIB_BUS_WIDTH_4BIT)
            {
                cmdApp.arg = MMCSD_LIB_BUS_WIDTH_4BIT;
            }
        }

        cmdApp.arg = cmdApp.arg >> 1U;
        status = MMCSDLibAppCmdSend(pCtrl, &cmdApp);
    }

    if (TRUE == status)
    {
        if (0U == cmdApp.arg)
        {
            pCtrl->pfnBusWidthConfig(pCtrl, MMCSD_LIB_BUS_WIDTH_1BIT);
        }
        else
        {
            pCtrl->pfnBusWidthConfig(pCtrl, MMCSD_LIB_BUS_WIDTH_4BIT);
        }
    }

    return status;
}

uint32_t MMCSDLibTranSpeedSet(mmcsdLibCtrlInfo_t *pCtrl)
{
    mmcsdLibCardInfo_t *pCard = pCtrl->pCard;
    uint32_t speed;
    uint32_t status = FALSE;
    mmcsdLibCmd_t cmd;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        pCtrl->pfnXferSetup(pCtrl, 1U, dataBuffer, 64U, 1U);

        cmd.idx = MMCSD_LIB_CMD(6U);
        cmd.arg = ((MMCSD_LIB_SWITCH_MODE & MMCSD_LIB_CMD6_GRP1_SEL) |
            (MMCSD_LIB_CMD6_GRP1_HS));
        cmd.flags = MMCSD_LIB_CMDRSP_READ | MMCSD_LIB_CMDRSP_DATA;
        cmd.nBlks = 1U;
        cmd.pData = (signed char*)dataBuffer;
        status = MMCSDLibCmdSend(pCtrl, &cmd);
    }

    if (FALSE != status)
    {
        status = pCtrl->pfnXferStatusGet(pCtrl);
    }

    if (FALSE != status)
    {
        /* Invalidate the data cache. */
#if 0
        CacheDataInvalidateBuff((uint32_t) dataBuffer, DATA_RESPONSE_WIDTH);
#endif

        speed = pCard->tranSpeed;

        if ((dataBuffer[16U] & 0xFU) == MMCSD_LIB_CMD6_GRP1_HS)
        {
            pCard->tranSpeed = MMCSD_LIB_TRANSPEED_50MBPS;
        }
        else
        {
            pCard->tranSpeed = MMCSD_LIB_TRANSPEED_25MBPS;
        }

        if (MMCSD_LIB_TRANSPEED_50MBPS == speed)
        {
            status = pCtrl->pfnBusFreqConfig(pCtrl, 50000000U);
            pCtrl->opClk = 50000000U;
        }
        else
        {
            status = pCtrl->pfnBusFreqConfig(pCtrl, 25000000U);
            pCtrl->opClk = 25000000U;
        }

        if(FALSE != status)
        {
            status = FALSE;
        }
    }

    return status;
}

uint32_t MMCSDLibCardReset(mmcsdLibCtrlInfo_t *pCtrl)
{
    uint32_t status = FALSE;
    mmcsdLibCmd_t cmd;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        cmd.idx = MMCSD_LIB_CMD(0U);
        cmd.flags = MMCSD_LIB_CMDRSP_NONE;
        cmd.arg = 0U;
        status = MMCSDLibCmdSend(pCtrl, &cmd);
    }

    return status;
}

uint32_t MMCSDLibStopCmdSend(mmcsdLibCtrlInfo_t *pCtrl)
{
    uint32_t status = FALSE;
    mmcsdLibCmd_t cmd;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        cmd.idx  = MMCSD_LIB_CMD(12U);
        cmd.flags = MMCSD_LIB_CMDRSP_BUSY;
        cmd.arg = 0U;
        MMCSDLibCmdSend(pCtrl, &cmd);

        /* Get transfer status */
        status = pCtrl->pfnXferStatusGet(pCtrl);
    }

    return status;
}

uint32_t MMCSDLibCardTypeCheck(mmcsdLibCtrlInfo_t *pCtrl)
{
    uint32_t status = FALSE;
    mmcsdLibCmd_t cmd;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        /*
         * Card type can be found by sending CMD55. If the pCard responds,
         * it is a SD pCard. Else, we assume it is a MMC Card
         */
        cmd.idx = MMCSD_LIB_CMD(55U);
        cmd.flags = 0U;
        cmd.arg = 0U;
        status = MMCSDLibAppCmdSend(pCtrl, &cmd);
    }

    return status;
}

uint32_t MMCSDLibCtrlInit(mmcsdLibCtrlInfo_t *pCtrl)
{
    return pCtrl->pfnCtrlInit(pCtrl);
}

uint32_t MMCSDLibCardPresent(mmcsdLibCtrlInfo_t *pCtrl)
{
    return pCtrl->pfnCardPresent(pCtrl);
}

void MMCSDLibIntrEnable(mmcsdLibCtrlInfo_t *pCtrl)
{
    pCtrl->pfnIntrEnable(pCtrl);
}

uint32_t MMCSDLibCardInit(mmcsdLibCtrlInfo_t *pCtrl)
{
    mmcsdLibCardInfo_t *pCard = pCtrl->pCard;
    uint32_t retry = 0xFFFFU;
    uint32_t status = FALSE;
    mmcsdLibCmd_t cmd;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        memset(pCtrl->pCard, 0U, sizeof(mmcsdLibCardInfo_t));

        pCard->pCtrl = pCtrl;

        /* CMD0 - reset pCard */
        status = MMCSDLibCardReset(pCtrl);
    }

    if(FALSE != status)
    {
        /* Returns TRUE for a SD pCard, FALSE for a non-SD pCard */
        status = MMCSDLibCardTypeCheck(pCtrl);
    }

    /* SD Card */
    if(TRUE == status)
    {
        pCtrl->pCard->cardType = MMCSD_LIB_CARD_SD;

        /* CMD0 - reset pCard */
        status = MMCSDLibCardReset(pCtrl);

        if(FALSE != status)
        {
            /* CMD8 - send oper voltage */
            cmd.idx = MMCSD_LIB_CMD(8U);
            cmd.flags = 0U;
            cmd.arg = (MMCSD_LIB_CHECK_PATTERN | MMCSD_LIB_VOLT_2P7_3P6);
            status = MMCSDLibCmdSend(pCtrl, &cmd);
        }

        if (FALSE == status)
        {
            /*
             * If the cmd fails, it can be due to version < 2.0, since
             * we are currently supporting high voltage pCards only
             */
        }

        if(FALSE != status)
        {
            /* Go ahead and send ACMD41, with host capabilities */
            cmd.idx = MMCSD_LIB_CMD(41U);
            cmd.flags = 0U;
            cmd.arg = MMCSD_LIB_OCR_HIGH_CAPACITY | MMCSD_LIB_OCR_VDD_WILDCARD;
            status = MMCSDLibAppCmdSend(pCtrl,&cmd);
        }

        if(FALSE != status)
        {
            /* Poll until we get the pCard status (BIT31 of OCR) is powered up */
            do
            {
                cmd.idx = MMCSD_LIB_CMD(41U);
                cmd.flags = 0U;
                cmd.arg = MMCSD_LIB_OCR_HIGH_CAPACITY | MMCSD_LIB_OCR_VDD_WILDCARD;
                MMCSDLibAppCmdSend(pCtrl,&cmd);
            } while (!(cmd.rsp[0U] & ((uint32_t)BIT(31U))) && retry--);

            if (0U == retry)
            {
                /* No point in continuing */
                status = FALSE;
            }
        }

        if(FALSE != status)
        {
            pCard->ocr = cmd.rsp[0U];

            pCard->highCap = (pCard->ocr & MMCSD_LIB_OCR_HIGH_CAPACITY) ? 1U : 0U;

            /* Send CMD2, to get the pCard identification register */
            cmd.idx = MMCSD_LIB_CMD(2U);
            cmd.flags = MMCSD_LIB_CMDRSP_136BITS;
            cmd.arg = 0U;

            status = MMCSDLibCmdSend(pCtrl,&cmd);

            memcpy(pCard->raw_cid, cmd.rsp, 16U);
        }

        if(FALSE != status)
        {
            /* Send CMD3, to get the pCard relative address */
            cmd.idx = MMCSD_LIB_CMD(3U);
            cmd.flags = 0U;
            cmd.arg = 0U;

            status = MMCSDLibCmdSend(pCtrl,&cmd);

            pCard->rca = MMCSD_LIB_RCA_ADDR(cmd.rsp[0U]);
        }

        if(FALSE != status)
        {
            /* Send CMD9, to get the pCard specific data */
            cmd.idx = MMCSD_LIB_CMD(9U);
            cmd.flags = MMCSD_LIB_CMDRSP_136BITS;
            cmd.arg = pCard->rca << 16U;

            status = MMCSDLibCmdSend(pCtrl,&cmd);

            memcpy(pCard->raw_csd, cmd.rsp, 16U);
        }

        if(FALSE != status)
        {
            if (MMCSD_LIB_CARD_CSD_VERSION(pCard))
            {
                pCard->tranSpeed = MMCSD_LIB_CARD1_TRANSPEED(pCard);
                pCard->blkLen = 1U << (MMCSD_LIB_CARD1_RDBLKLEN(pCard));
                pCard->size = MMCSD_LIB_CARD1_SIZE(pCard);
                pCard->nBlks = pCard->size / pCard->blkLen;
            }
            else
            {
                pCard->tranSpeed = MMCSD_LIB_CARD0_TRANSPEED(pCard);
                pCard->blkLen = 1U << (MMCSD_LIB_CARD0_RDBLKLEN(pCard));
                pCard->nBlks = MMCSD_LIB_CARD0_NUMBLK(pCard);
                pCard->size = MMCSD_LIB_CARD0_SIZE(pCard);

            }

            /* Set data block length to 512 (for byte addressing pCards) */
            if( !(pCard->highCap) )
            {
                cmd.idx = MMCSD_LIB_CMD(16U);
                cmd.flags = MMCSD_LIB_CMDRSP_NONE;
                cmd.arg = 512U;
                status = MMCSDLibCmdSend(pCtrl,&cmd);

                if(FALSE != status)
                {
                    pCard->blkLen = 512U;
                }
            }
        }

        if(FALSE != status)
        {
            /* Select the pCard */
            cmd.idx = MMCSD_LIB_CMD(7U);
            cmd.flags = MMCSD_LIB_CMDRSP_BUSY;
            cmd.arg = pCard->rca << 16U;

            status = MMCSDLibCmdSend(pCtrl,&cmd);
        }

        if(FALSE != status)
        {
            /*
             * Send ACMD51, to get the SD Configuration register details.
             * Note, this needs data transfer (on data lines).
             */
            cmd.idx = MMCSD_LIB_CMD(55U);
            cmd.flags = 0U;
            cmd.arg = pCard->rca << 16U;

            status = MMCSDLibCmdSend(pCtrl,&cmd);
        }

        if(FALSE != status)
        {
            pCtrl->pfnXferSetup(pCtrl, 1U, dataBuffer, 8U, 1U);

            cmd.idx = MMCSD_LIB_CMD(51U);
            cmd.flags = MMCSD_LIB_CMDRSP_READ | MMCSD_LIB_CMDRSP_DATA;
            cmd.arg = pCard->rca << 16U;
            cmd.nBlks = 1U;
            cmd.pData = (signed char*)dataBuffer;

            status = MMCSDLibCmdSend(pCtrl,&cmd);
        }

        if(FALSE != status)
        {
            status = pCtrl->pfnXferStatusGet(pCtrl);
        }

        if(FALSE != status)
        {
            /* Invalidate the data cache. */
#if 0
            CacheDataInvalidateBuff((uint32_t)dataBuffer, DATA_RESPONSE_WIDTH);
#endif

            pCard->raw_scr[0U] = (dataBuffer[3U] << 24U) | (dataBuffer[2U] << 16U) | \
                               (dataBuffer[1U] << 8U) | (dataBuffer[0U]);
            pCard->raw_scr[1U] = (dataBuffer[7U] << 24U) | (dataBuffer[6U] << 16U) | \
                                       (dataBuffer[5U] << 8U) | (dataBuffer[4U]);

            pCard->sdVer = MMCSD_LIB_CARD_VERSION(pCard);
            pCard->busWidth = MMCSD_LIB_CARD_BUSWIDTH(pCard);
        }
    }

    return status;
}

uint32_t MMCSDLibWriteCmdSend(mmcsdLibCtrlInfo_t *pCtrl, void *pBuff, uint32_t block,
                               uint32_t nBlks)
{
    mmcsdLibCardInfo_t *pCard = pCtrl->pCard;
    uint32_t status = FALSE;
    uint32_t address;
    mmcsdLibCmd_t cmd;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        /*
         * Address is in blks for high cap pCards and in actual bytes
         * for standard capacity pCards
         */
        if (FALSE != pCard->highCap)
        {
            address = block;
        }
        else
        {
            address = block * pCard->blkLen;
        }

        /* Clean the data cache. */
#if 0
        CacheDataCleanBuff((uint32_t) pBuff, (512U * nBlks));
#endif
        pCtrl->pfnXferSetup(pCtrl, 0U, pBuff, 512U, nBlks);

        cmd.flags = MMCSD_LIB_CMDRSP_WRITE | MMCSD_LIB_CMDRSP_DATA;
        cmd.arg = address;
        cmd.nBlks = nBlks;

        if (nBlks > 1U)
        {
            cmd.idx = MMCSD_LIB_CMD(25U);
            cmd.flags |= MMCSD_LIB_CMDRSP_ABORT;
        }
        else
        {
            cmd.idx = MMCSD_LIB_CMD(24U);
        }

        status = MMCSDLibCmdSend(pCtrl, &cmd);
    }

    if(FALSE != status)
    {
        status = pCtrl->pfnXferStatusGet(pCtrl);
    }

    if(FALSE != status)
    {
        /* Send a STOP */
        if (cmd.nBlks > 1U)
        {
            status = MMCSDLibStopCmdSend(pCtrl);
        }
    }

    return status;
}

uint32_t MMCSDLibReadCmdSend(mmcsdLibCtrlInfo_t *pCtrl, void *pBuff, uint32_t block,
                              uint32_t nBlks)
{
    mmcsdLibCardInfo_t *pCard = pCtrl->pCard;
    uint32_t status = FALSE;
    uint32_t address;
    mmcsdLibCmd_t cmd;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        /*
         * Address is in blks for high cap pCards and in actual bytes
         * for standard capacity pCards
         */
        if (FALSE != pCard->highCap)
        {
            address = block;
        }
        else
        {
            address = block * pCard->blkLen;
        }

        pCtrl->pfnXferSetup(pCtrl, 1U, pBuff, 512U, nBlks);

        cmd.flags = MMCSD_LIB_CMDRSP_READ | MMCSD_LIB_CMDRSP_DATA;
        cmd.arg = address;
        cmd.nBlks = nBlks;

        if (nBlks > 1U)
        {
            cmd.flags |= MMCSD_LIB_CMDRSP_ABORT;
            cmd.idx = MMCSD_LIB_CMD(18U);
        }
        else
        {
            cmd.idx = MMCSD_LIB_CMD(17U);
        }

        status = MMCSDLibCmdSend(pCtrl, &cmd);
    }

    if(FALSE != status)
    {
        status = pCtrl->pfnXferStatusGet(pCtrl);
    }

    if(FALSE != status)
    {
        /* Send a STOP */
        if (cmd.nBlks > 1U)
        {
            status = MMCSDLibStopCmdSend(pCtrl);
        }
    }

    if(FALSE != status)
    {
        /* Invalidate the data cache. */
#if 0
        CacheDataInvalidateBuff((uint32_t) pBuff, (512U * nBlks));
#endif
    }

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
