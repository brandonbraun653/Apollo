/*
 *  Copyright (C) 2013-2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   mmcsd.c
 *
 *  \brief  Device abstraction layer for HS MMC/SD
 *
 *   This file contains the device abstraction layer APIs for HS MMC/SD.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdio.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_mmcsd.h>

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void MMCSDLineReset(uint32_t baseAddr, uint32_t resetMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + MMCSD_MMCCTL);
    regVal |= resetMask;
    HW_WR_REG32(baseAddr + MMCSD_MMCCTL, regVal);

    regVal = HW_RD_REG32(baseAddr + MMCSD_MMCCTL);
    regVal &= ~(resetMask);
    HW_WR_REG32(baseAddr + MMCSD_MMCCTL, regVal);
}

void MMCSDReadEndianSet(uint32_t baseAddr, uint32_t flag)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_PERMDR,
                  flag);
}

void MMCSDWriteEndianSet(uint32_t baseAddr, uint32_t flag)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_PERMDX,
                  flag);
}

void MMCSDResponseTimeoutSet(uint32_t baseAddr, uint32_t timeout)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCTOR, MMCSD_MMCTOR_TOR,
                  timeout);
}

void MMCSDSetReadTimeout(uint32_t baseAddr, uint32_t timeout)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCTOR, MMCSD_MMCTOR_TOD_25_16,
                  timeout);
}

void MMCSDSetDataTimeout(uint32_t baseAddr, uint32_t timeout)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCTOD, MMCSD_MMCTOD_TOD_15_0,
                  timeout);
}

void MMCSDEdgeDetection(uint32_t baseAddr, uint32_t edgeVal)
{
	switch (edgeVal)
    {
		case MMCSD_EDGE_DETECT_DISABLE:
			HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_DATEG,
                          MMCSD_MMCCTL_DATEG_RESET);
			break;
		case MMCSD_EDGE_DETECT_RISEEDGE_ENABLE:
			HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_DATEG,
                          MMCSD_MMCCTL_DATEG_R_EDGE);
			break;
		case MMCSD_EDGE_DETECT_FALLEDGE_ENABLE:
			HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_DATEG,
                          MMCSD_MMCCTL_DATEG_F_EDGE);
			break;
		case MMCSD_EDGE_DETECT_RISEFALL_ENABLE:
			HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_DATEG,
                          MMCSD_MMCCTL_DATEG_RF_EDGE);
			break;
		default:
			break;

	}
}

void MMCSDSetBusWidth(uint32_t baseAddr, uint32_t width)
{
    switch (width)
    {
        case MMCSD_BUSWIDTH_8BIT:
            HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_WIDTH1, 1);
            HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_WIDTH0, 0);
            break;
        case MMCSD_BUSWIDTH_4BIT:
            HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_WIDTH1, 0);
            HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_WIDTH0, 1);
            break;
        case MMCSD_BUSWIDTH_1BIT:
            HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_WIDTH1, 0);
            HW_WR_FIELD32(baseAddr + MMCSD_MMCCTL, MMCSD_MMCCTL_WIDTH0, 0);
            break;
        default:
            break;
    }
}
void MMCSDSetBlkLength(uint32_t baseAddr, uint32_t blockLen)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCBLEN, MMCSD_MMCBLEN_BLEN,
                          blockLen);
}

void MMCSDSetNumBlocks(uint32_t baseAddr, uint32_t numBlocks)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCNBLK, MMCSD_MMCNBLK_NBLK,
                          numBlocks);
}

void MMCSDSendInitSeq(uint32_t baseAddr)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_DMATRIG,
                          MMCSD_MMCCMD_DMATRIG_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_DCLR,
                          MMCSD_MMCCMD_DCLR_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_STRMTP,
                          MMCSD_MMCCMD_STRMTP_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_WDATX,
                          MMCSD_MMCCMD_WDATX_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_DTRW,
                          MMCSD_MMCCMD_DTRW_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_BSYEXP,
                          MMCSD_MMCCMD_BSYEXP_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_RSPFMT,
                          MMCSD_MMCCMD_RSPFMT_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_INITCK,
                          MMCSD_MMCCMD_INITCK_INIT);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_PPLEN,
                          MMCSD_MMCCMD_PPLEN_RESETVAL);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCMD, MMCSD_MMCCMD_CMD,
                          MMCSD_MMCCMD_CMD_RESETVAL);
}

void MMCSDCommandSend(uint32_t baseAddr, uint32_t cmd, uint32_t arg)
{
	HW_WR_REG32(baseAddr + MMCSD_MMCARGHL, arg);
	HW_WR_REG32(baseAddr + MMCSD_MMCCMD, cmd);
}

void MMCSDFreqSet(uint32_t baseAddr, uint32_t freq, Bool isDivBy4Reqd)
{
	/*Disable the clock*/
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCLK, MMCSD_MMCCLK_CLKEN,
                          MMCSD_MMCCLK_CLKEN_DISABLE);

	if(TRUE == isDivBy4Reqd)
	{
		/*Enable the clock to be divided by 4*/
		HW_WR_FIELD32(baseAddr + MMCSD_MMCCLK, MMCSD_MMCCLK_DIV4,
                          MMCSD_MMCCLK_DIV4_ENABLE);
	}
	else
	{
		/*Enable the clock to be divided by 2*/
		HW_WR_FIELD32(baseAddr + MMCSD_MMCCLK, MMCSD_MMCCLK_DIV4,
                          MMCSD_MMCCLK_DIV4_DISABLE);
	}

	HW_WR_FIELD32(baseAddr + MMCSD_MMCCLK, MMCSD_MMCCLK_CLKRT,
                          freq);
	/*Enable the clock*/
	HW_WR_FIELD32(baseAddr + MMCSD_MMCCLK, MMCSD_MMCCLK_CLKEN,
                          MMCSD_MMCCLK_CLKEN_ENABLE);
}

void MMCSDConfigureFIFO(uint32_t baseAddr, uint16_t fifoSize, Bool readFlag)
{
	HW_WR_FIELD32(baseAddr + MMCSD_MMCFIFOCTL, MMCSD_MMCFIFOCTL_FIFORST,
                          MMCSD_MMCFIFOCTL_FIFORST_RESET);
	HW_WR_FIELD32(baseAddr + MMCSD_MMCFIFOCTL, MMCSD_MMCFIFOCTL_FIFORST,
                          MMCSD_MMCFIFOCTL_FIFORST_RESETVAL);
	if(readFlag)
	{
		HW_WR_FIELD32(baseAddr + MMCSD_MMCFIFOCTL, MMCSD_MMCFIFOCTL_FIFODIR,
                          MMCSD_MMCFIFOCTL_FIFODIR_READ);
	}
	else
	{
		HW_WR_FIELD32(baseAddr + MMCSD_MMCFIFOCTL, MMCSD_MMCFIFOCTL_FIFODIR,
                          MMCSD_MMCFIFOCTL_FIFODIR_WRITE);
	}

	HW_WR_FIELD32(baseAddr + MMCSD_MMCFIFOCTL, MMCSD_MMCFIFOCTL_ACCWD,
                          MMCSD_MMCFIFOCTL_ACCWD_4BYTES);

	switch (fifoSize)
	{
		case MMCSD_FIFO_SIZE_32_BYTES:
			HW_WR_FIELD32(baseAddr + MMCSD_MMCFIFOCTL, MMCSD_MMCFIFOCTL_FIFOLEV,
                          MMCSD_MMCFIFOCTL_FIFOLEV_256BIT);
			break;

		case MMCSD_FIFO_SIZE_64_BYTES:
			HW_WR_FIELD32(baseAddr + MMCSD_MMCFIFOCTL, MMCSD_MMCFIFOCTL_FIFOLEV,
                          MMCSD_MMCFIFOCTL_FIFOLEV_512BIT);
			break;

		default:
			break;
	}
}

void MMCSDIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + MMCSD_MMCIM);
    regVal |= intrMask;
    HW_WR_REG32((baseAddr + MMCSD_MMCIM), regVal);
}

void MMCSDIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + MMCSD_MMCIM);
    regVal &= ~intrMask;
    HW_WR_REG32((baseAddr + MMCSD_MMCIM), regVal);
}

uint32_t MMCSDIntrGet(uint32_t baseAddr)
{
    return HW_RD_REG32(baseAddr + MMCSD_MMCIM);
}

uint32_t MMCSDGetIntrStatus(uint32_t baseAddr)
{
	return HW_RD_REG32(baseAddr + MMCSD_MMCST0);
}

void MMCSDGetResponse(uint32_t baseAddr, uint32_t respType, uint32_t *rsp)
{
	rsp[0] = HW_RD_REG32(baseAddr + MMCSD_MMCRSP01);
    rsp[1] = HW_RD_REG32(baseAddr + MMCSD_MMCRSP23);
    rsp[2] = HW_RD_REG32(baseAddr + MMCSD_MMCRSP45);
    rsp[3] = HW_RD_REG32(baseAddr + MMCSD_MMCRSP67);
}

void MMCSDGetData(uint32_t baseAddr, uint8_t *data, uint32_t len)
{
    int32_t i;

    for (i = 0; i < (len / 4U); i++)
    {
        ((uint32_t *) data)[i] = HW_RD_REG32(baseAddr + MMCSD_MMCDRR);
    }
}

void MMCSDSetData(uint32_t baseAddr, const uint8_t *pData, uint32_t len)
{
    uint32_t i;

    for (i = 0U; i < (len / 4U); i++)
    {
        HW_WR_REG32((baseAddr + MMCSD_MMCDXR), ((uint32_t*)pData)[i]);
    }
}

/********************************* End of file ******************************/

