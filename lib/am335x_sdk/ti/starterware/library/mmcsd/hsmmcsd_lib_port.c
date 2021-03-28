/**
 *  \file  hsmmcsd_lib_port.c
 *
 * \brief  This file contains the prototypes for porting of HSMMCSD IP for
 *         MMCSD library.
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

#include <stdint.h>
#include <console_utils.h>
#include "types.h"
#include "hs_mmcsd.h"
#include "mmcsd_lib.h"
#include "hsmmcsd_lib_port.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t HSMMCSDLibPortIsCardPresent(mmcsdLibCtrlInfo_t *pCtrl)
{
    return HSMMCSDIsCardInserted(pCtrl->baseAddr);
}

void HSMMCSDLibPortIntrEnable(mmcsdLibCtrlInfo_t *pCtrl)
{
    HSMMCSDIntrEnable(pCtrl->baseAddr, pCtrl->intrMask);
}

uint32_t HSMMCSDLibPortCtrlInit(mmcsdLibCtrlInfo_t *pCtrl)
{
    uint32_t retStat = FALSE;
    int32_t status = E_FAIL;
    hsMmcsdSysCfg_t sysCfg = {HS_MMCSD_CLK_ACT_ICLK_FCLK_OFF,
                              HS_MMCSD_STANDBY_MODE_FORCE,
                              HS_MMC_SD_IDLE_MODE_FORCE,
                              FALSE,
                              TRUE};

    if(NULL != pCtrl)
    {
        /*
         * Refer to the MMC Host and Bus configuration steps in TRM
         * controller Reset
         */
        status = HSMMCSDSoftReset(pCtrl->baseAddr);

        if (S_PASS != status)
        {
            CONSOLEUtilsPrintf("HS MMC/SD Reset failed\n\r");
        }
        else
        {
            retStat = TRUE;
        }
    }

    if (TRUE == retStat)
    {
        /* Lines Reset */
        HSMMCSDLinesReset(pCtrl->baseAddr, HS_MMCSD_RESET_LINE_MASK_ALL);

        /* Set supported voltage list */
        HSMMCSDSetSupportedVoltage(pCtrl->baseAddr,
            (HS_MMCSD_SUPP_VOLT_1P8 | HS_MMCSD_SUPP_VOLT_3P0));

        HSMMCSDSystemConfig(pCtrl->baseAddr, &sysCfg);

        /* Set the bus width */
        HSMMCSDSetBusWidth(pCtrl->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);

        /* Set the bus voltage */
        HSMMCSDSetBusVolt(pCtrl->baseAddr, HS_MMCSD_BUS_VOLT_3P0);

        /* Bus power on */
        status = HSMMCSDBusPowerOnCtrl(pCtrl->baseAddr, HS_MMCSD_PWR_CTRL_ON);

        if (TRUE != status)
        {
            CONSOLEUtilsPrintf("HS MMC/SD Power on failed\n\r");
            retStat = FALSE;
        }

        if (TRUE == retStat)
        {
            /* Set the initialization frequency */
            status = HSMMCSDBusFreqSet(pCtrl->baseAddr, pCtrl->ipClk,
                pCtrl->opClk, FALSE);

            if (S_PASS != status)
            {
                CONSOLEUtilsPrintf("HS MMC/SD Bus Frequency set failed\n\r");
                retStat = FALSE;
            }

            if (TRUE == retStat)
            {
                HSMMCSDInitStreamSend(pCtrl->baseAddr);
            }
        }
    }

    return retStat;
}

uint32_t HSMMCSDLibPortCmdSend(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCmd_t *pCmd)
{
    uint32_t status = FALSE;
    hsMmcsdCmdObj_t cmdObj = {{0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U};

    if(NULL != pCtrl)
    {
        if(NULL != pCmd)
        {
            status = TRUE;
        }
    }

    if(TRUE == status)
    {
        if (pCmd->flags & MMCSD_LIB_CMDRSP_STOP)
        {
            cmdObj.cmd.cmdType = HS_MMCSD_CMD_TYPE_BUS_SUSPEND;
        }
        else if (pCmd->flags & MMCSD_LIB_CMDRSP_FS)
        {
            cmdObj.cmd.cmdType = HS_MMCSD_CMD_TYPE_FUNC_SEL;
        }
        else if (pCmd->flags & MMCSD_LIB_CMDRSP_ABORT)
        {
            cmdObj.cmd.cmdType = HS_MMCSD_CMD_TYPE_IO_ABORT;
        }

        cmdObj.cmd.xferType = (pCmd->flags & MMCSD_LIB_CMDRSP_READ) ? \
            HS_MMCSD_XFER_TYPE_RX : HS_MMCSD_XFER_TYPE_TX;
        cmdObj.enableData = (pCmd->flags & MMCSD_LIB_CMDRSP_DATA) ? TRUE : FALSE;
        cmdObj.numBlks = (TRUE == cmdObj.enableData) ? pCmd->nBlks : 0U;

        if (pCmd->flags & MMCSD_LIB_CMDRSP_NONE)
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_NONE;
        }
        else if (pCmd->flags & MMCSD_LIB_CMDRSP_136BITS)
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_LEN_136;
        }
        else if (pCmd->flags & MMCSD_LIB_CMDRSP_BUSY)
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_LEN_48_BUSY;
        }
        else
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_LEN_48;
        }

        if (FALSE == cmdObj.enableData)
        {
            HSMMCSDIntrClear(pCtrl->baseAddr, HS_MMCSD_INTR_MASK_TRNFCOMP);
            HSMMCSDDataTimeoutSet(pCtrl->baseAddr, 27U);
        }

        cmdObj.cmd.cmdId = pCmd->idx;
        cmdObj.cmdArg = pCmd->arg;
        cmdObj.enableDma = pCtrl->dmaEnable;
        HSMMCSDCommandSend(pCtrl->baseAddr, &cmdObj);

        if (NULL != pCtrl->pfnCmdStatusGet)
        {
            status = pCtrl->pfnCmdStatusGet(pCtrl);
        }
        else
        {
            status = FALSE;
        }

        if (TRUE == status)
        {
            HSMMCSDResponseGet(pCtrl->baseAddr, pCmd->rsp);
        }
    }
    return status;
}

uint32_t HSMMCSDLibPortBusWidthConfig(mmcsdLibCtrlInfo_t *pCtrl, uint32_t busWidth)
{
    uint32_t status = FALSE;

    if(NULL != pCtrl)
    {
        status = TRUE;
    }

    if(TRUE == status)
    {
        if (busWidth == MMCSD_LIB_BUS_WIDTH_1BIT)
        {
            HSMMCSDSetBusWidth(pCtrl->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);
        }
        else
        {
            HSMMCSDSetBusWidth(pCtrl->baseAddr, HS_MMCSD_BUS_WIDTH_4BIT);
        }
    }

    return status;
}

int32_t HSMMCSDLibPortBusFreqConfig(mmcsdLibCtrlInfo_t *pCtrl, uint32_t busFreq)
{
    int32_t status = FALSE;

    if(NULL != pCtrl)
    {
        if(S_PASS == HSMMCSDBusFreqSet(pCtrl->baseAddr, pCtrl->ipClk, busFreq, 0U))
        {
            status = TRUE;
        }
    }

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
