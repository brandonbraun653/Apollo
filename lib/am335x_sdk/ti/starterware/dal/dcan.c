/**
 * \file       dcan.c
 *
 * \brief      This file contains the function definitions for the device
 *             abstraction layer for DCAN.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "dcan.h"
#include "error.h"
#include "hw_types.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * \name    Macros used by the DAL APIs.
 */

/** @{ */
/** \brief Check for the busy status of DCAN IF register set.
 *
 */
#define DCAN_IFREG_BUSY_STATUS(baseAddr, regNum) \
       ((HW_RD_REG32(baseAddr + DCAN_IFCMD(regNum)) & DCAN_IFCMD_BUSY_MASK))

/** \brief  DCAN standard ID shift value.
 */
#define DCAN_STD_ID_SHIFT      (18U)
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void DCANReset(uint32_t baseAddr)
{
    /* Reset the DCAN module. */
    HW_WR_FIELD32((baseAddr + DCAN_CTL), DCAN_CTL_SWR, DCAN_CTL_SWR_RESET);

    /* Wait until the reset is done */
    while(DCAN_CTL_SWR_MASK == (HW_RD_REG32(baseAddr + DCAN_CTL) &
          DCAN_CTL_SWR_MASK));
}

void DCANSetMode(uint32_t baseAddr, uint32_t mode)
{
    /* Configure the DCAN mode of operation. */
    HW_WR_FIELD32((baseAddr + DCAN_CTL), DCAN_CTL_INIT, mode);
}

void DCANBitTimeConfig(uint32_t baseAddr, uint32_t bitTimeVal)
{
    /* Enable the configuration change enable bit. */
    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                   DCAN_CTL_CCE,
                   DCAN_CTL_CCE_ACCESS);

    /* Program the DCAN bit time value. */
    HW_WR_REG32((baseAddr + DCAN_BTR), bitTimeVal);

    /* Disable the configuration change enable bit. */
    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                   DCAN_CTL_CCE,
                   DCAN_CTL_CCE_NOACCESS);
}

void DCANIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + DCAN_CTL);

    regVal |= intrMask;

    /* Enable the DCAN interrupts. */
    HW_WR_REG32((baseAddr + DCAN_CTL), regVal);
}

void DCANIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

	regVal = HW_RD_REG32(baseAddr + DCAN_CTL);
	regVal &= ~intrMask;

    /* Disable the DCAN interrupts. */
    HW_WR_REG32((baseAddr + DCAN_CTL), regVal);
}

void DCANAutoReTransmissionEnable(uint32_t baseAddr, uint32_t enableAutoReTxn)
{
    if (TRUE == enableAutoReTxn)
	{
        /* Enable Auto retransmission. */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                       DCAN_CTL_DAR,
                       DCAN_CTL_DAR_ENABLED);
	}
	else
	{
        /* Disable Auto retransmission. */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                       DCAN_CTL_DAR,
                       DCAN_CTL_DAR_DISABLED);
	}
}

void DCANParityEnable(uint32_t baseAddr, uint32_t enableParity)
{
    if (TRUE == enableParity)
	{
        /* Enable DCAN parity. */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                       DCAN_CTL_PMD,
                       DCAN_CTL_PMD_ENABLED);
	}
	else
	{
        /* Disable DCAN parity. */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                       DCAN_CTL_PMD,
                       DCAN_CTL_PMD_DISABLED);
	}
}

void DCANIntrLineEnable(uint32_t baseAddr,
                        uint32_t intrLineNum,
                        uint32_t enableIntrLine)
{
    if (TRUE == enableIntrLine)
	{
        if (DCAN_INTR_LINE_NUM_0 == intrLineNum)
		{
            HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_IE0,
                           DCAN_CTL_IE0_ENABLED);
		}
		else
		{
		    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_IE1,
                           DCAN_CTL_IE1_ENABLED);
	    }
	}
	else
	{
        if (DCAN_INTR_LINE_NUM_0 == intrLineNum)
		{
            HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_IE0,
                           DCAN_CTL_IE0_DISABLED);
		}
		else
		{
		    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_IE1,
                           DCAN_CTL_IE1_DISABLED);
	    }
	}
}

void DCANDmaRequestLineEnable(uint32_t baseAddr,
                              uint32_t ifRegNum,
                              uint32_t enableDmaReq)
{
    if (TRUE == enableDmaReq)
	{
        if (DCAN_IF_REG_NUM_1 == ifRegNum)
		{
            HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_DE1,
                           DCAN_CTL_DE1_ENABLED);
		}
		else if (DCAN_IF_REG_NUM_2 == ifRegNum)
		{
		    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_DE2,
                           DCAN_CTL_DE2_ENABLED);
	    }
		else
		{
		    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_DE3,
                           DCAN_CTL_DE3_ENABLED);
		}
	}
	else
	{
        if (DCAN_IF_REG_NUM_1 == ifRegNum)
		{
            HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_DE1,
                           DCAN_CTL_DE1_DISABLED);
		}
		else if (DCAN_IF_REG_NUM_2 == ifRegNum)
		{
		    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_DE2,
                           DCAN_CTL_DE2_DISABLED);
	    }
		else
		{
		    HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_DE3,
                           DCAN_CTL_DE3_DISABLED);
		}
	}
}

uint32_t DCANIntrStatus(uint32_t baseAddr, uint32_t intrLineNum)
{
    uint32_t retVal = 0U;

	retVal = HW_RD_REG32(baseAddr + DCAN_INT);

    if (DCAN_INTR_LINE_NUM_0 == intrLineNum)
	{
	    /* Fetch the Interrupt line 0 status. */
        retVal = (retVal & DCAN_INT_INT0ID_MASK);
	}
	else
	{
	    /* Fetch the Interrupt line 1 status. */
	    retVal = ((retVal & DCAN_INT_INT1ID_MASK) >> DCAN_INT_INT1ID_SHIFT);
	}

	return(retVal);
}

uint32_t DCANGetErrorStatus(uint32_t baseAddr)
{
    /* Return the DCAN error and status register value. */
    return(HW_RD_REG32(baseAddr + DCAN_ES));
}

uint32_t DCANErrorCounterStatus(uint32_t baseAddr)
{
    /* Return the DCAN error counter value. */
    return(HW_RD_REG32(baseAddr + DCAN_ERRC));
}

void DCANTestModeEnable(uint32_t baseAddr,
                        uint32_t testMode,
                        uint32_t enableTestMode)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + DCAN_TEST);

    if (TRUE == enableTestMode)
    {
        /* Enable the DCAN test modes. */
        if(HW_RD_FIELD32(baseAddr + DCAN_CTL, DCAN_CTL_TEST) == DCAN_CTL_TEST_NORMALMODE)
            HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_TEST,
                           DCAN_CTL_TEST_TESTMODE);
        regVal = regVal | testMode;
        HW_WR_REG32((baseAddr + DCAN_TEST), regVal);
    }
    else
    {
        /* Disable the DCAN test modes. */
        regVal = (regVal & (~testMode));
        if(HW_RD_FIELD32(baseAddr + DCAN_CTL, DCAN_CTL_TEST) == DCAN_CTL_TEST_TESTMODE)
        {
            HW_WR_REG32((baseAddr + DCAN_TEST), regVal);
            HW_WR_FIELD32((baseAddr + DCAN_CTL),
                           DCAN_CTL_TEST,
                           DCAN_CTL_TEST_NORMALMODE);
        }
    }
}

uint32_t DCANParityErrorStatus(uint32_t baseAddr)
{
    /* Return the DCAN parity error value. */
    return(HW_RD_REG32(baseAddr + DCAN_PERR));
}

void DCANAutoBusOnEnable(uint32_t baseAddr, uint32_t enableAutoBusOn)
{
    if (TRUE == enableAutoBusOn)
	{
        /* Enable Auto bus on. */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                       DCAN_CTL_ABO,
                       DCAN_CTL_ABO_ENABLED);
	}
	else
	{
        /* Disable auto bus on. */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                       DCAN_CTL_ABO,
                       DCAN_CTL_ABO_DISABLED);
	}
}

void DCANSetAutoBusOnTimeVal(uint32_t baseAddr, uint32_t autoBusOnTimeVal)
{
    /* Configure the auto bus on time value. */
    HW_WR_REG32((baseAddr + DCAN_ABOTR), autoBusOnTimeVal);
}

uint32_t DCANGetAutoBusOnTimeVal(uint32_t baseAddr)
{
    /* Return the auto bus on time value. */
    return(HW_RD_REG32(baseAddr + DCAN_ABOTR));
}

uint32_t DCANTxRequestXStatus(uint32_t baseAddr)
{
    /* Return the transmit request X status. */
    return(HW_RD_REG32(baseAddr + DCAN_TXRQ_X));
}

uint32_t DCANTxRequestStatus(uint32_t baseAddr, uint32_t msgObjNum)
{
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;
    uint32_t regVal = 0U;

    regNum = (msgObjNum - 1U) / 32U;
    regOffSet = (msgObjNum - 1U) % 32U;

    /* Return the status from DCAN_TXRQ register */
    regVal = (HW_RD_REG32(baseAddr + DCAN_TXRQ(regNum)) & (1 << regOffSet));

    return(regVal >> regOffSet);
}

uint32_t DCANTxRqstLeastMsgObjStatus(uint32_t baseAddr)
{
    uint32_t index = 1U;
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;

    while(index < 128U)
    {
        regNum = (index - 1U) / 32U;
        regOffSet = (index - 1U) % 32U;

        if(!(HW_RD_REG32(baseAddr + DCAN_TXRQ(regNum)) & (1 << regOffSet)))
        {
            break;
        }
        index++;
    }

    return(index);
}

uint32_t DCANNewDataXRegStatus(uint32_t baseAddr)
{
    /* Return the status from DCAN_NWDAT_X register. */
    return(HW_RD_REG32(baseAddr + DCAN_NWDAT_X));
}

uint32_t DCANNewDataRegStatus(uint32_t baseAddr, uint32_t msgObjNum)
{
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;
	uint32_t regVal = 0U;

    regNum = (msgObjNum - 1U) / 32U;
    regOffSet = (msgObjNum - 1U) % 32U;

    /* Return the status from DCAN_NWDAT register. */
    regVal = (HW_RD_REG32(baseAddr + DCAN_NWDAT(regNum)) & (1 << regOffSet));

	return(regVal >> regOffSet);
}

uint32_t DCANNewDataLeastMsgObjStatus(uint32_t baseAddr)
{
    uint32_t index = 1U;
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;

    while(index < 128U)
    {
        regNum = (index - 1U) / 32U;
        regOffSet = (index - 1U) % 32U;

        if(!(HW_RD_REG32(baseAddr + DCAN_NWDAT(regNum)) & (1 << regOffSet)))
        {
            break;
        }
        index++;
    }

    return(index);
}

uint32_t DCANIntrPendingXRegStatus(uint32_t baseAddr)
{
    /* Return the status from DCAN_INTPND_X register. */
    return(HW_RD_REG32(baseAddr + DCAN_INTPND_X));
}

uint32_t DCANIntrPendingStatus(uint32_t baseAddr, uint32_t msgObjNum)
{
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;
	uint32_t regVal = 0U;

    regNum = (msgObjNum - 1U) / 32U;
    regOffSet = (msgObjNum - 1U) % 32U;

    /* Return the status from DCAN_INTPND register */
    regVal = (HW_RD_REG32(baseAddr + DCAN_INTPND(regNum)) & (1 << regOffSet));

	return(regVal >> regOffSet);
}

uint32_t DCANMsgValidXRegStatus(uint32_t baseAddr)
{
    /* Return the status from DCAN_MSGVAL_X register. */
    return(HW_RD_REG32(baseAddr + DCAN_MSGVAL_X));
}

uint32_t DCANMsgValidStatus(uint32_t baseAddr, uint32_t msgObjNum)
{
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;
	uint32_t regVal = 0U;

    regNum = (msgObjNum - 1U) / 32U;
    regOffSet = (msgObjNum - 1U) % 32U;

    /* Return the status from DCAN_MSGVAL register */
    regVal = (HW_RD_REG32(baseAddr + DCAN_MSGVAL(regNum)) & (1 << regOffSet));

	return(regVal >> regOffSet);
}

void DCANIntrMuxConfig(uint32_t baseAddr,
                      uint32_t intrLine,
                      uint32_t msgObjNum,
					  uint32_t maxMsgObjects)
{
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;
	uint32_t regVal = 0U;

    if(msgObjNum == maxMsgObjects)
    {
        regNum = 0;
        regOffSet = 0;
    }
    else
    {
        regNum = msgObjNum / 32;
        regOffSet = msgObjNum % 32;
    }

    regVal = HW_RD_REG32(baseAddr + DCAN_INTMUX(regNum));

	if (DCAN_INTR_LINE_NUM_0 == intrLine)
	{
        /* Clear the IntMux field of DCAN_INTMUX register. */
		regVal &= ~(1 << regOffSet);
	}
	else
	{
	    /* Set the IntMux field of DCAN_INTMUX register. */
	    regVal |= (1 << regOffSet);
	}

    /* Set the DCAN_INTMUX field corresponding to msgNum. */
    HW_WR_REG32((baseAddr + DCAN_INTMUX(regNum)), regVal);
}

void DCANValidateMsgObj(uint32_t baseAddr, uint32_t ifRegNum)
{
    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    /* Validate the DCAN message object. */
    HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                   DCAN_IFARB_MSGVAL,
                   DCAN_IFARB_MSGVAL_USED);
}

void DCANInvalidateMsgObj(uint32_t baseAddr, uint32_t ifRegNum)
{
    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

	/* Invalidate the DCAN message object. */
    HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                   DCAN_IFARB_MSGVAL,
                   DCAN_IFARB_MSGVAL_IGNORED);
}

void DCANSetCommand(uint32_t baseAddr,
                    uint32_t command,
                    uint32_t msgObjNum,
					uint32_t ifRegNum)
{
    uint32_t regVal = 0U;

	regVal = HW_RD_REG32(baseAddr + DCAN_IFCMD(ifRegNum));

    regVal &= ~(DCAN_IFCMD_DMAACTIVE_MASK |
                DCAN_IFCMD_DATAA_MASK |
                DCAN_IFCMD_DATAB_MASK |
                DCAN_IFCMD_TXRQST_NEWDAT_MASK |
                DCAN_IFCMD_CLRINTPND_MASK |
                DCAN_IFCMD_CONTROL_MASK |
                DCAN_IFCMD_ARB_MASK |
                DCAN_IFCMD_MASK_MASK |
                DCAN_IFCMD_MESSAGENUMBER_MASK |
                DCAN_IFCMD_WR_RD_MASK);

    regVal |= (command | (msgObjNum & DCAN_IFCMD_MESSAGENUMBER_MASK));

    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    HW_WR_REG32(baseAddr + DCAN_IFCMD(ifRegNum), regVal);
}

void DCANSetMsgId(uint32_t baseAddr,
                  uint32_t msgId,
                  uint32_t idLength,
                  uint32_t ifRegNum)
{
    if(idLength == DCAN_ID_LENGTH_11_BIT)
    {
        msgId <<= DCAN_STD_ID_SHIFT;
    }

    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    /* Set the msg id. */
	HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                   DCAN_IFARB_MSGID,
                   msgId);

    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

	/* Set the msg id. */
	HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                   DCAN_IFARB_XTD,
                   idLength);
}

void DCANSetMsgDirection(uint32_t baseAddr,
                         uint32_t msgDir,
                         uint32_t ifRegNum)
{
    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    /* Configure the direction. */
	HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                   DCAN_IFARB_DIR,
                   msgDir);
}

void DCANWriteData(uint32_t baseAddr,
                   uint32_t* pDataVal,
                   uint32_t ifRegNum)
{
    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    /* Write the lower 4 data bytes to IFDATA register */
	HW_WR_FIELD32((baseAddr + DCAN_IFDATA(ifRegNum)),
                   DCAN_IFDATA_DCAN_IFDATA,
                   *pDataVal++);

    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    /* Write the higher 4 data bytes to IFDATB register */
	HW_WR_FIELD32((baseAddr + DCAN_IFDATB(ifRegNum)),
                   DCAN_IFDATB_DCAN_IFDATB,
                   *pDataVal);
}

void DCANReadData(uint32_t baseAddr,
                  uint32_t* pDataVal,
                  uint32_t ifRegNum)
{
    /* Read the data bytes from the DCAN_IFDATA register */
    *pDataVal++ = HW_RD_REG32(baseAddr + DCAN_IFDATA(ifRegNum));

    /* Read the data bytes from the DCAN_IFDATB register */
    *pDataVal = HW_RD_REG32(baseAddr + DCAN_IFDATB(ifRegNum));
}

void DCANSetDataLengthCode(uint32_t baseAddr,
                           uint32_t dataLengthCode,
                           uint32_t ifRegNum)
{
    /* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    /* Configure the Data length code. */
	HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                   DCAN_IFMCTL_DATALENGTHCODE,
                   dataLengthCode);
}

void DCANMsgObjIntrEnable(uint32_t baseAddr,
                          uint32_t msgObjIntrMask,
                          uint32_t ifRegNum)
{
    uint32_t regVal = 0U;

	/* Read the DCAN message control register value. */
	regVal = HW_RD_REG32(baseAddr + DCAN_IFMCTL(ifRegNum));

	regVal |= msgObjIntrMask;

	/* Write the DCAN message control register value. */
	HW_WR_REG32(baseAddr + DCAN_IFMCTL(ifRegNum), regVal);
}

void DCANMsgObjIntrDisable(uint32_t baseAddr,
                           uint32_t msgObjIntrMask,
                           uint32_t ifRegNum)
{
    uint32_t regVal = 0U;

	/* Read the DCAN message control register value. */
	regVal = HW_RD_REG32(baseAddr + DCAN_IFMCTL(ifRegNum));

	regVal &= ~msgObjIntrMask;

	/* Write the DCAN message control register value. */
	HW_WR_REG32(baseAddr + DCAN_IFMCTL(ifRegNum), regVal);
}

void DCANFifoEndOfBlockEnable(uint32_t baseAddr,
                              uint32_t fifoEndOfBlockEnable,
                              uint32_t ifRegNum)
{
	/* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    if (TRUE == fifoEndOfBlockEnable)
	{
        /* Configure the Data length code. */
	    HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                       DCAN_IFMCTL_EOB,
                       DCAN_IFMCTL_EOB_SAME);
	}
	else
	{
        /* Configure the Data length code. */
	    HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                       DCAN_IFMCTL_EOB,
                       DCAN_IFMCTL_EOB_BYTE8);
	}
}

void DCANMsgObjectMaskConfig(uint32_t baseAddr,
                             uint32_t msgIdMask,
                             uint32_t msgDirMask,
                             uint32_t extIdMask,
                             uint32_t ifRegNum)
{
    uint32_t regVal = 0U;

	/* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

    regVal = (msgIdMask | msgDirMask | extIdMask);

	/* Write the DCAN mask register value. */
    HW_WR_REG32(baseAddr + DCAN_IFMSK(ifRegNum), regVal);
}

void DCANSetIf3RegUpdateEnable(uint32_t baseAddr, uint32_t msgNum)
{
    uint32_t regNum = 0U;
    uint32_t regOffSet = 0U;
	uint32_t regVal = 0U;

    regNum = (msgNum - 1) / 32;
    regOffSet = (msgNum - 1) % 32;

    /* Configure the DCAN IF3 update enable register. */
    regVal = HW_RD_REG32(baseAddr + DCAN_IF3UPD(regNum));
	regVal |= (1U << regOffSet);
	HW_WR_REG32(baseAddr + DCAN_IF3UPD(regNum), regVal);
}

void DCANSetIf3Observation(uint32_t baseAddr, uint32_t obsMask)
{
    uint16_t regVal = 0U;

    /* Set the appropriate flags in the DCAN_IF3OBS register. */
	regVal = HW_RD_REG16(baseAddr + DCAN_IF3OBS);
	regVal |= obsMask;
	HW_WR_REG16((baseAddr + DCAN_IF3OBS), regVal);
}

void DCANClearIf3Observation(uint32_t baseAddr, uint32_t obsMask)
{
    uint16_t regVal = 0U;

    /* Set the appropriate flags in the DCAN_IF3OBS register. */
	regVal = HW_RD_REG16(baseAddr + DCAN_IF3OBS);
	regVal &= ~obsMask;
	HW_WR_REG16((baseAddr + DCAN_IF3OBS), regVal);
}

uint32_t DCANIf3ObservationStatus(uint32_t baseAddr)
{
    /* Return the observation status from the DCAN_IF3OBS register. */
    return(HW_RD_REG16(baseAddr + DCAN_IF3OBS));
}

uint32_t DCANIfMaskStatus(uint32_t baseAddr, uint32_t ifRegNum)
{
    /* Return the status of DCAN_IF_MSK register. */
    return(HW_RD_REG16(baseAddr + DCAN_IFMSK(ifRegNum)));
}

uint32_t DCANIfArbitrationStatus(uint32_t baseAddr, uint32_t ifRegNum)
{
    /* Return the status of DCAN_IF_ARB register. */
    return(HW_RD_REG32(baseAddr + DCAN_IFARB(ifRegNum)));
}

uint32_t DCANIfMsgCtlStatus(uint32_t baseAddr, uint32_t ifRegNum)
{
    /* Return the status of DCAN_IFMCTl register. */
    return(HW_RD_REG32(baseAddr + DCAN_IFMCTL(ifRegNum)));
}

void DCANIntrClear(uint32_t baseAddr, uint32_t ifRegNum)
{
	/* Wait in loop until busy bit is cleared. */
    while(DCAN_IFCMD_BUSY_MASK == DCAN_IFREG_BUSY_STATUS(baseAddr, ifRegNum));

	HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                   DCAN_IFMCTL_INTPND,
                   DCAN_IFMCTL_INTPND_NOINTERRUPT);
}

void DCANNewDataConfig(uint32_t baseAddr, uint32_t newData, uint32_t ifRegNum)
{
    /* Configure the DCAN new data. */
    HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                   DCAN_IFMCTL_NEWDAT,
                   newData);
}

void DCANAcceptanceMaskEnable(uint32_t baseAddr,
                              uint32_t enableMask,
                              uint32_t ifRegNum)
{
    if (TRUE == enableMask)
	{
	    /* Acceptance mask is being used. */
	    HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                       DCAN_IFMCTL_UMASK,
                       DCAN_IFMCTL_UMASK_MASKED);
	}
	else
	{
	    /* Acceptance mask is not used. */
	    HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                       DCAN_IFMCTL_UMASK,
                       DCAN_IFMCTL_UMASK_IGNORED);
	}
}

void DCANTransmitRequestEnable(uint32_t baseAddr,
                               uint32_t enableTxRqst,
                               uint32_t ifRegNum)
{
    if (TRUE == enableTxRqst)
	{
	    /* Acceptance mask is being used. */
	    HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                       DCAN_IFMCTL_TXRQST,
                       DCAN_IFMCTL_TXRQST_REQUESTED);

	}
	else
	{
	    /* Acceptance mask is being used. */
	    HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                       DCAN_IFMCTL_TXRQST,
                       DCAN_IFMCTL_TXRQST_NOREQUESTED);
	}
}
