/*
 *  Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   mmcsd.h
 *
 *  \brief  HS MMC/SD APIs and macros.
 *
 *   This file contains the driver API prototypes and macro definitions.
 */

#ifndef HS_MMCSD_H_
#define HS_MMCSD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/cslr_mmc.h>

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/*----WIDTH1_WIDTH0 Tokens----*/
#define MMCSD_MMCCTL_WIDTH1_WIDTH0_1BIT		(0x0000u)
#define MMCSD_MMCCTL_WIDTH1_WIDTH0_4BIT 	(0x0004u)
#define MMCSD_MMCCTL_WIDTH1_WIDTH0_8BIT 	(0x0100u)

/*----DATEG Tokens----*/
#define MMCSD_MMCCTL_DATEG_RESET			(0x00000000u)
#define MMCSD_MMCCTL_DATEG_R_EDGE    		(0x00000001u)
#define MMCSD_MMCCTL_DATEG_F_EDGE    		(0x00000002u)
#define MMCSD_MMCCTL_DATEG_RF_EDGE   		(0x00000003u)

/*----WIDTH0 Tokens----*/
#define MMCSD_MMCCTL_WIDTH0_1BIT_8BIT  		(0x00000000u)
#define MMCSD_MMCCTL_WIDTH0_4BIT       		(0x00000004u)

/*----DIV4 Tokens----*/
#define MMCSD_MMCCLK_DIV4_DISABLE    		(0x00000000u)
#define MMCSD_MMCCLK_DIV4_ENABLE     		(0x00000001u)

/*----DMATRIG Tokens----*/
#define MMCSD_MMCCMD_DMATRIG_NO             (0x00000000u)
#define MMCSD_MMCCMD_DMATRIG_YES            (0x00000001u)

/*----DCLR Tokens----*/
#define MMCSD_MMCCMD_DCLR_NO                (0x00000000u)
#define MMCSD_MMCCMD_DCLR_CLEAR             (0x00000001u)

/*----INITCK Tokens----*/
#define MMCSD_MMCCMD_INITCK_NO              (0x00000000u)
#define MMCSD_MMCCMD_INITCK_INIT            (0x00000001u)

/*----WDATX Tokens----*/
#define MMCSD_MMCCMD_WDATX_NO               (0x00000000u)
#define MMCSD_MMCCMD_WDATX_DATA             (0x00000001u)

/*----STRMTP Tokens----*/
#define MMCSD_MMCCMD_STRMTP_BLOCK           (0x00000000u)
#define MMCSD_MMCCMD_STRMTP_STREAM          (0x00000001u)
#define MMCSD_MMCCMD_STRMTP_NO              (0x00000000u)

/*----DTRW Tokens----*/
#define MMCSD_MMCCMD_DTRW_READ              (0x00000000u)
#define MMCSD_MMCCMD_DTRW_WRITE             (0x00000001u)
#define MMCSD_MMCCMD_DTRW_NO                (0x00000000u)

/*----CLKEN Tokens----*/
#define MMCSD_MMCCLK_CLKEN_DISABLE   		(0x00000000u)
#define MMCSD_MMCCLK_CLKEN_ENABLE    		(0x00000001u)

/*----RSPFMT Tokens----*/
#define MMCSD_MMCCMD_RSPFMT_NORSP    		(0x00000000u)
#define MMCSD_MMCCMD_RSPFMT_R1       		(0x00000001u)
#define MMCSD_MMCCMD_RSPFMT_R2       		(0x00000002u)
#define MMCSD_MMCCMD_RSPFMT_R3       		(0x00000003u)
#define MMCSD_MMCCMD_RSPFMT_R4       		(0x00000004u)
#define MMCSD_MMCCMD_RSPFMT_R5       		(0x00000005u)
#define MMCSD_MMCCMD_RSPFMT_R6       		(0x00000006u)

/*----BSYEXP Tokens----*/
#define MMCSD_MMCCMD_BSYEXP_NO              (0x00000000u)
#define MMCSD_MMCCMD_BSYEXP_BUSY            (0x00000001u)

/*----PPLEN Tokens----*/
#define MMCSD_MMCCMD_PPLEN_OD               (0x00000000u)
#define MMCSD_MMCCMD_PPLEN_PP               (0x00000001u)

/*----ACCWD Tokens----*/
#define MMCSD_MMCFIFOCTL_ACCWD_4BYTES 		(0x00000000u)
#define MMCSD_MMCFIFOCTL_ACCWD_3BYTES 		(0x00000001u)
#define MMCSD_MMCFIFOCTL_ACCWD_2BYTES 		(0x00000002u)
#define MMCSD_MMCFIFOCTL_ACCWD_1BYTE 		(0x00000003u)

/*----FIFOLEV Tokens----*/
#define MMCSD_MMCFIFOCTL_FIFOLEV_256BIT     (0x00000000u)
#define MMCSD_MMCFIFOCTL_FIFOLEV_512BIT     (0x00000001u)

/*----FIFODIR Tokens----*/
#define MMCSD_MMCFIFOCTL_FIFODIR_READ 		(0x00000000u)
#define MMCSD_MMCFIFOCTL_FIFODIR_WRITE 		(0x00000001u)

/*----FIFORST Tokens----*/
#define MMCSD_MMCFIFOCTL_FIFORST_RESETVAL   (0x00000000u)
#define MMCSD_MMCFIFOCTL_FIFORST_RESET 		(0x00000001u)
#define MMCSD_MMCFIFOCTL_RESETVAL    		(0x00000000u)

#define MMCSD_FIFO_SIZE_32_BYTES			(32)
#define MMCSD_FIFO_SIZE_64_BYTES			(64)

#define MMCSD_EDGE_DETECT_DISABLE			(0x00000000)
#define MMCSD_EDGE_DETECT_RISEEDGE_ENABLE	(0x00000040)
#define MMCSD_EDGE_DETECT_FALLEDGE_ENABLE	(0x00000080)
#define MMCSD_EDGE_DETECT_RISEFALL_ENABLE	(0x000000C0)


#define MMCSD_BUSWIDTH_8BIT				(0x00000100)
#define MMCSD_BUSWIDTH_4BIT				(0x00000004)
#define MMCSD_BUSWIDTH_1BIT				(0x00000000)


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Soft reset the MMC/SD controller lines
 *
 * \param   baseAddr      Base Address of the MMC/SD controller Registers.
 * \param   resetMask     reset Mask indicating the lines to be reset.
 *
 * resetMask can take the following values \n
 * MMCSD_MMCCTL_CMDRST_MASK \n
 * MMCSD_MMCCTL_DATRST_MASK \n
 *
 * \example
 * For resetting the controller both flags can be combined as follows
 * MMCSDLineReset(baseAddr, (MMCSD_MMCCTL_CMDRST_MASK | MMCSD_MMCCTL_DATRST_MASK));
 *
 * \return  None
 *
 **/
void MMCSDLineReset(uint32_t baseAddr, uint32_t resetMask);

/**
 * \brief Function to configure read endian mode
 *
 * \param   baseAddr      Base Address of the MMC/SD controller Registers.
 * \param   flag          Flags indicating the endian mode.
 *
 * \return None
 *
 *
 **/
void MMCSDReadEndianSet(uint32_t baseAddr, uint32_t flag);

/**
 * \brief Function to configure write endian mode
 *
 * \param   baseAddr      Base Address of the MMC/SD controller Registers.
 * \param   flag          Flags indicating the endian mode.
 *
 * \return None
 *
 *
 **/
void MMCSDWriteEndianSet(uint32_t baseAddr, uint32_t flag);

/**
 * \brief Function to set command response timeout
 *
 * \param   baseAddr      Base Address of the MMC/SD controller Registers.
 * \param   timeout       Timeout value
 *
 * \return None
 *
 *
 **/
void MMCSDResponseTimeoutSet(uint32_t baseAddr, uint32_t timeout);

/**
 * \brief Function to set read timeout
 *
 * \param   baseAddr      Base Address of the MMC/SD controller Registers.
 * \param   timeout       Timeout value.
 *
 * \return  None
 *
 *
 **/
void MMCSDSetReadTimeout(uint32_t baseAddr, uint32_t timeout);

/**
 * \brief Function to set data timeout
 *
 * \param   baseAddr      Base Address of the MMC/SD controller Registers.
 * \param   timeout       Timeout value.
 *
 * \return  None
 *
 *
 **/
void MMCSDSetDataTimeout(uint32_t baseAddr, uint32_t timeout);

/**
 * \brief Function to configure edge detection
 *
 * \param   baseAddr      Base Address of the MMC/SD controller Registers.
 * \param   edgeVal       Edge value.
 *
 * \return  None
 *
 *
 **/
void MMCSDEdgeDetection(uint32_t baseAddr, uint32_t edgeVal);

/**
 * \brief Function to set bus width
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   width       Value of bus width
 *
 * \return  None
 *
 *
 **/
void MMCSDSetBusWidth(uint32_t baseAddr, uint32_t width);

/**
 * \brief Function to set block length
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   blockLen    Block length value
 *
 * \return  None
 *
 *
 **/
void MMCSDSetBlkLength(uint32_t baseAddr, uint32_t blockLen);

/**
 * \brief Function to set number of blocks
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   numBlocks   Number of blocks to transfer
 *
 * \return  None
 *
 *
 **/
void MMCSDSetNumBlocks(uint32_t baseAddr, uint32_t numBlocks);

/**
 * \brief Function to enable sending init sequence to the card
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 *
 * \return  None
 *
 *
 **/
void MMCSDSendInitSeq(uint32_t baseAddr);

/**
 * \brief Function to send a command to the card
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   cmd         Command ID
 * \param   arg         Command arguments
 *
 * \return  None
 *
 *
 **/
void MMCSDCommandSend(uint32_t baseAddr, uint32_t cmd, uint32_t arg);

/**
 * \brief Function to configure MMCSD controller frequency.
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   freq        Frequency value
 * \param   isDivBy4Reqd Flag to indicate if divide by four is needed
 *                       for the clock
 *
 * \return  None
 *
 *
 **/
void MMCSDFreqSet(uint32_t baseAddr, uint32_t freq, Bool isDivBy4Reqd);

/**
 * \brief Function to configure MMCSD FIFO
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   fifoSize    Size of the FIFO
 * \param   readFlag    FIFO direction. 1 - read, 0- write
 *
 * \return
 *
 *
 **/
void MMCSDConfigureFIFO(uint32_t baseAddr, uint16_t fifoSize, Bool readFlag);

/**
 * \brief Function to enable MMCSD interrupts
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   intrMask    Interrupt mask
 *
 * \return
 *
 *
 **/
void MMCSDIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief Function to disable MMCSD interrupts
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   intrMask    Interrupt mask
 *
 * \return
 *
 *
 **/
void MMCSDIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief Function to get interrupt status
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 *
 * \return Interrupt status
 *
 *
 **/
uint32_t MMCSDGetIntrStatus(uint32_t baseAddr);

/**
 * \brief Function to get interrupt configuration
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 *
 * \return Interrupt configuration
 *
 *
 **/
uint32_t MMCSDIntrGet(uint32_t baseAddr);

/**
 * \brief Function to get interrupt status
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   respType    Type of the response
 * \param   rsp         Response read from the card.
 *
 * \return None
 *
 *
 **/
void MMCSDGetResponse(uint32_t baseAddr, uint32_t respType, uint32_t *rsp);

/**
 * \brief Function to read data from MMCSD FIFO
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   data        Data read from the card
 * \param   len         Length of data in bytes.
 *
 * \return None
 *
 *
 **/
void MMCSDGetData(uint32_t baseAddr, uint8_t *data, uint32_t len);

/**
 * \brief Function to write data to MMCSD FIFO
 *
 * \param   baseAddr    Base Address of the MMC/SD controller Registers.
 * \param   pData       Data to be written to the card
 * \param   len         Length of data in bytes.
 *
 * \return None
 *
 *
 **/
void MMCSDSetData(uint32_t baseAddr, const uint8_t *pData, uint32_t len);

#ifdef __cplusplus
}
#endif
#endif
/********************************* End of file ******************************/
