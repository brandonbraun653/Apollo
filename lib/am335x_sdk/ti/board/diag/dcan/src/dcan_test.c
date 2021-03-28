/*
 * Copyright (c) 2012-2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *  \file   dcan_test.c
 *
 *  \brief This file contains DCAN test functions.
 *
 */

#include "dcan_test.h"
#include "platform_internal.h"

#include "board.h"
#include "board_cfg.h"

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

uint32_t fDcan0 = FALSE;
uint32_t fDcan1 = FALSE;
uint32_t fLoopback  = FALSE;
uint32_t fPort2Port = FALSE;
uint32_t fInternalLoopback = FALSE;

#ifdef ECHO
uint32_t fEcho = TRUE;
#else
uint32_t fEcho = FALSE;
#endif

/**
 * \brief Function to configure DCAN module
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return None
 */
static void configureDCAN(uint32_t instance)
{
	uint32_t baseAddr = 0;
	uint32_t index;

	/* Set base address */
	if(instance == 0)
	{
		baseAddr = DCAN0_BASE;
	}

  	if(instance == 1)
  	{
   		baseAddr = DCAN1_BASE;
	}

	/* Reset the DCAN module */
	DCANReset(baseAddr);

	/* Enter the Initialization mode of CAN controller */
	DCANInitModeSet(baseAddr);

	/* Enable the write access to the DCAN configuration registers */
	DCANConfigRegWriteAccessControl(baseAddr, DCAN_CONF_REG_WR_ACCESS_ENABLE);

	/* Configure the bit timing values for CAN communication */
	CANSetBitTiming(baseAddr, DCAN_IN_CLK, DCAN_BIT_RATE);

	/* Enable internal loopback (test mode loopback and silent set) */
	if(fInternalLoopback)
	{
		HWREG(baseAddr + DCAN_CTL)  |= (DCAN_CTL_TEST);
		HWREG(baseAddr + DCAN_TEST) |= (1<<4);   //Loopback
		HWREG(baseAddr + DCAN_TEST) |= (1<<3);   //Silent
  	}

	/* Disable the write access to the DCAN configuration registers */
	DCANConfigRegWriteAccessControl(baseAddr, DCAN_CONF_REG_WR_ACCESS_DISABLE);

	/* Invalidate all message objects in the message RAM */
	for(index = 1; index <= CAN_NUM_OF_MSG_OBJS; index++)
    {
		CANInValidateMsgObject(baseAddr, index, DCAN_IF2_REG);
	}
}

/**
 * \brief Function to build Rx Packets
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return None
 */
void buildRxPackets(uint32_t instance)
{
	uint32_t baseAddr = 0;
	uint32_t count;
	can_frame entry;
	uint32_t id_offset;

	// Set base address
	if(instance == 0)
	{
	    baseAddr = DCAN0_BASE;
	}

	if(instance == 1)
	{
	    baseAddr=DCAN1_BASE;
	}

	// Set starting id
	if(((instance == 0) && fLoopback) |
	   ((instance == 1) && fPort2Port))
	{
    	id_offset = 0;
	}

	if(((instance == 1) && fLoopback) |
	   ((instance == 0) && fPort2Port))
	{
    	id_offset = 32;
	}

	// Build packets
	for(count = 1; count <= CAN_NUM_OF_MSG_OBJS/2; count++)
	{
		entry.id = count + id_offset;
		entry.flag = (CAN_DATA_FRAME | CAN_MSG_DIR_RX);

		if(!fEcho)
		{
      		entry.msk = 0x7ff;
		}
	    else
		{
      		entry.msk = 0x1f;
		}

		CANRxObjectConfig(baseAddr, &entry);
		//msg=CANRxObjectConfig(baseAddr, &entry);
		//UART_printf("id: %d, flag: 0x%08x, msk: 0x%x, msgIndex: %d\n", entry.id, entry.flag, entry.msk, msg);
	}
}

/**
 * \brief Function to build Tx Packets
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return None
 */
void buildTxPackets(uint32_t instance)
{
	uint32_t baseAddr = 0;
	uint32_t count;
	uint32_t index;
	can_frame entry;
	uint32_t size, id_offset;
	uint32_t data[2];
	unsigned char *pData;
	unsigned char data_val;

	// Set base address
	if(instance == 0)
	{
		baseAddr = DCAN0_BASE;
	}

	if(instance == 1)
	{
    	baseAddr = DCAN1_BASE;
	}

	// Set starting id and data and size
	if(instance == 0)
	{
		id_offset = 0;
		data_val  = 0x01;
	}
	else
	{
		id_offset = 32;
		data_val  = 0xff;
	}

  	size = 0;

	// Build packets
	for(count = 1; count <= CAN_NUM_OF_MSG_OBJS/2; count++)
	{
		// Reset data
		data[0] = 0x0;
		data[1] = 0x0;

		// Set id
		entry.id = count + id_offset;

		// Set dlc
		size++;

		if(size > 8)
		{
			size = 1;
		}

	    entry.dlc = size;

		// Build data
		pData = (unsigned char *)&data;

		for(index = 0; index < size; index++)
		{
			*pData++ = data_val;

			if(instance == 0)
			{
				data_val++;
			}
			else
			{
				data_val--;
			}
    	}

    	entry.data = (unsigned int *)data;

		// Set flags
		entry.flag = (CAN_DATA_FRAME | CAN_MSG_DIR_TX);

		CANTxObjectConfig(baseAddr, &entry);
		while(DCANIFBusyStatusGet(baseAddr, DCAN_IF1_REG));
	}
}

/**
 * \brief Function to start DCAN transfer
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return None
 */
void startDCANTransfer(uint32_t instance)
{
	uint32_t baseAddr;

	if(instance == 0)
	{
		baseAddr = DCAN0_BASE;
	}

  	if(instance == 1)
  	{
    	baseAddr = DCAN1_BASE;
	}

	/* Start the CAN transfer */
	DCANNormalModeSet(baseAddr);
}

/**
 * \brief Function to print stats header
 *
 * \return None
 */
void statsHeader(void)
{
	UART_printf("TxRqst        TxRqst        NewData       NewData       IntPend       IntPend       MsgVal        MsgVal    \n");
	UART_printf("1-32          33-64         1-32          33-64         1-32          33-64         1-32          33-64     \n");
	UART_printf("----------    ----------    ----------    ----------    ----------    ----------    ----------    ----------\n");
}

/**
 * \brief Function to dump stats
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return None
 */
void dumpStats(uint32_t instance)
{
  uint32_t baseAddr;
  uint32_t txrq0, txrq1;
  uint32_t newdata0, newdata1;
  uint32_t pend0, pend1;
  uint32_t msgval0, msgval1;

	if(instance == 0)
	{
		baseAddr = DCAN0_BASE;
	}

	if(instance == 1)
	{
	    baseAddr = DCAN1_BASE;
	}

	txrq0 = HWREG(baseAddr + DCAN_TXRQ(0));
	txrq1 = HWREG(baseAddr + DCAN_TXRQ(1));
	newdata0 = HWREG(baseAddr + DCAN_NWDAT(0));
	newdata1 = HWREG(baseAddr + DCAN_NWDAT(1));
	pend0 = HWREG(baseAddr + DCAN_INTPND(0));
	pend1 = HWREG(baseAddr + DCAN_INTPND(1));
	msgval0 = HWREG(baseAddr + DCAN_MSGVAL(0));
	msgval1 = HWREG(baseAddr + DCAN_MSGVAL(1));

	UART_printf("0x%08x    0x%08x    0x%08x    0x%08x    0x%08x    0x%08x    0x%08x    0x%08x\n",
			       txrq0, txrq1, newdata0, newdata1, pend0, pend1, msgval0, msgval1);
}

/**
 * \brief Function to check Tx packet status and errors
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return 0 for success or error code
 */
uint32_t checkTx(uint32_t instance)
{
	uint32_t baseAddr;
	uint32_t ret_val=0;
	uint32_t error;
	uint32_t timeout = 1000;

	if(instance == 0)
	{
    	baseAddr = DCAN0_BASE;
	}

	if(instance == 1)
	{
    	baseAddr = DCAN1_BASE;
	}

	// Check to make sure all packets have transmitted
	do
	{
		timeout--;
		if(!timeout)
		{
			break;
		}

		platform_delay(1000);

	} while(HWREG(baseAddr + DCAN_TXRQ(0)));

	if(HWREG(baseAddr + DCAN_TXRQ(0)))
	{
		ret_val = 1;
	}

	// Check for errors
	error = DCANErrAndStatusRegInfoGet(baseAddr);
	if((error & DCAN_PARITY_ERR_DETECTED))
	{
  		ret_val = 2;
	}

	if((error & DCAN_MOD_IN_BUS_OFF_STATE))
	{
		ret_val = 3;
	}

	switch(error & DCAN_ES_LEC)
	{
		case 0:
		case 7:
			break;
		case 1:
			ret_val = 4;
			break;
		case 2:
			ret_val = 5;
			break;
		case 3:
			ret_val = 6;
			break;
		case 4:
			ret_val = 7;
			break;
		case 5:
			ret_val = 8;
			break;
		case 6:
			ret_val = 9;
			break;
  	}

	// Printf error if found
	switch(ret_val)
	{
		case 0:
		default:
      		break;
		case 1:
			UART_printf("FAIL      Transmit failed: Timeout\n");
			break;
		case 2:
			UART_printf("FAIL      Transmit failed: Parity error\n");
			break;
		case 3:
			UART_printf("FAIL      Transmit failed: Bus in off state\n");
			break;
		case 4:
			UART_printf("FAIL      Transmit failed: Stuff error\n");
			break;
		case 5:
			UART_printf("FAIL      Transmit failed: Form error\n");
			break;
		case 6:
			UART_printf("FAIL      Transmit failed: Ack error\n");
			break;
		case 7:
			UART_printf("FAIL      Transmit failed: Bit1 error\n");
			break;
		case 8:
			UART_printf("FAIL      Transmit failed: Bit0 error\n");
			break;
		case 9:
			UART_printf("FAIL      Transmit failed: CRC error\n");
			break;
  	}

  	return (ret_val);
}

/**
 * \brief Function to check Rx packet status and errors
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return 0 for success or error code
 */
uint32_t checkRx(uint32_t instance)
{
	uint32_t baseAddr;
	uint32_t count, index;
	uint32_t ret_val = 0;
	uint32_t msgNum, val, id_offset;
	uint32_t data[2], dlc, id, newData;
	uint32_t exp_dlc, exp_id;
	unsigned char *pData;
	unsigned char expData_val;
	uint32_t timeout = 1000;

	if(instance == 0)
	{
		baseAddr = DCAN0_BASE;
	}

	if(instance == 1)
	{
    	baseAddr = DCAN1_BASE;
	}

	do
	{
	    newData = HWREG(baseAddr + DCAN_NWDAT(1));

		timeout--;
		if(!timeout)
		{
	  		break;
	    }

	    platform_delay(1000);

	} while( newData != 0xffffffff);

	newData = HWREG(baseAddr + DCAN_NWDAT(1));
	if( newData != 0xffffffff)
	{
	    ret_val = 1;
	}

	// Set expected id and data and size
	if(((instance == 0) && fLoopback) |
	   ((instance == 1) && fPort2Port))
	{
		id_offset   = 0;
		expData_val = 0x1;
	}
	else
	{
		id_offset   = 32;
		expData_val = 0xff;
	}

  	exp_dlc = 0;

	for(count = 1; count <= CAN_NUM_OF_MSG_OBJS/2; count++)
	{
		msgNum = (count + 32);
		CANReadMsgObjData(baseAddr, msgNum, (unsigned int*)data, DCAN_IF2_REG);
		val = DCANIFMsgCtlStatusGet(baseAddr, DCAN_IF2_REG);
		dlc = (val >> 0) & 0xf;

		val = DCANIFArbStatusGet(baseAddr, DCAN_IF2_REG);
		id  = (val >> 18) & 0x7ff;

		// Check expected id
		exp_id = count + id_offset;
		if(exp_id != id)
		{
			ret_val = 2;
		}

		// Check expected dlc
		exp_dlc++;
		if(exp_dlc > 8)
		{
			exp_dlc = 1;
		}

		if(exp_dlc != dlc)
		{
			ret_val = 2;
		}

		// Check expected data
		pData = (unsigned char *)&data;
		for(index = 0; index < exp_dlc; index++)
		{
			if(*pData++ != expData_val)
			{
				ret_val = 2;
			}

			if(((instance == 0) && fLoopback) |
			   ((instance == 1) && fPort2Port))
			{
				expData_val++;
			}
			else
			{
				expData_val--;
			}
		}
	}

	// Printf error if found
	switch(ret_val)
	{
		case 0:
		default:
			break;
		case 1:
			UART_printf("FAIL      Receive failed: Timeout\n");
    		break;
		case 2:
			UART_printf("FAIL      Receive failed: Data mismatch\n");
			break;
	}

	return (ret_val);
}

/**
 * \brief Function to echo DCAN packets
 *
 * \param	instance  [IN]  - DCAN instance number
 *
 * \return None
 */
void echoPackets(uint32_t instance)
{
	uint32_t baseAddr;
	uint32_t count , fQuit = FALSE;
	uint32_t msgNum, val, cnt = 0;
	uint32_t data[2], dlc, id, newData;
	can_frame entry;

	if(instance == 0)
	{
		baseAddr = DCAN0_BASE;
	}

	if(instance == 1)
	{
		baseAddr = DCAN1_BASE;
	}

	UART_printf("Performing packet echo...press any key to exit\n");
	while(!fQuit)
	{
		newData = HWREG(baseAddr + DCAN_NWDAT(1));
		for(count = 0; count < CAN_NUM_OF_MSG_OBJS/2; count++)
		{
			if((newData >> count) & 0x1)
			{
				data[0] = 0;
				data[1] = 0;

				msgNum = count + 1 + CAN_NUM_OF_MSG_OBJS/2;
				CANReadMsgObjData(baseAddr, msgNum, (unsigned int*) data, DCAN_IF2_REG);
				val = DCANIFMsgCtlStatusGet(baseAddr, DCAN_IF2_REG);
				dlc = (val >> 0) & 0xf;
				val = DCANIFArbStatusGet(baseAddr, DCAN_IF2_REG);
				id  = (val >> 18) & 0x7ff;

				// Build and echo packet
				entry.id   = id;
				entry.dlc  = dlc;
				entry.data = (unsigned int *)data;
				entry.flag = (CAN_DATA_FRAME | CAN_MSG_DIR_TX);
				msgNum = CANTxObjectConfig(baseAddr, &entry);
				while(DCANIFBusyStatusGet(baseAddr, DCAN_IF1_REG));
				cnt++;
			}
		}

		//if(IsTimeout())
		{
			UART_printf("\rPackets echoed: %d", cnt);
		}
	}
}

/**
 *  \brief    Executes CAN bus tests
 *
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_dcan_test(void *testArgs)
{
	TEST_STATUS ret_val = TEST_PASS;
	uint32_t BoardType = 0;

	/* Initialize DCAN instances to be tested and test mode */
	fDcan0     = TRUE;
	fDcan1     = TRUE;
	fLoopback  = FALSE;
	fPort2Port = TRUE;

	// Basic pin mux, ram init, and clock setup
	if(fDcan0)
	{
		DCANModuleClkConfig(0);
		DCANPinMuxSetUp(0, BoardType);
		DCANMsgRAMInit(0);
		platform_delay(100);
		configureDCAN(0);
		buildRxPackets(0);
	}

	if(fDcan1)
	{
		DCANModuleClkConfig(1);
		DCANPinMuxSetUp(1, BoardType);
		DCANMsgRAMInit(1);
		platform_delay(100);
		configureDCAN(1);
		buildRxPackets(1);
	}

	// Test
	if(fLoopback && !fEcho)
	{
		UART_printf("Test        Port    Status    Error\n");
		UART_printf("\n");
		UART_printf("--------    ----    ------    ---------------------------\n");

		if(fDcan0)
		{
			UART_printf("Loopback    0       ");
			buildTxPackets(0);
			startDCANTransfer(0);
			platform_delay(100);

			if(!checkTx(0))
			{
				if(!checkRx(0))
				{
					UART_printf("PASS\n");
				}
				else
				{
					ret_val = TEST_FAIL;
				}
			}
			else
			{
				ret_val = TEST_FAIL;
			}
		}

		if(fDcan1)
		{
			UART_printf("Loopback    1       ");
			startDCANTransfer(1);
			platform_delay(100);

			if(!checkTx(1))
			{
				if(!checkRx(1))
				{
					UART_printf("PASS\n");
				}
				else
				{
					ret_val = TEST_FAIL;
				}
			}
			else
			{
     		   ret_val = TEST_FAIL;
			}
		}
	}

	if(fPort2Port && !fEcho)
	{
		UART_printf("Port    Direction    Status    Error\n");
		UART_printf("\n");
		UART_printf("----    ---------    ------    ---------------------------\n");

		// Transmit on port 0
		UART_printf("0       Transmit     ");
		startDCANTransfer(1);
		buildTxPackets(0);
		startDCANTransfer(0);
		platform_delay(100);

		if(!checkTx(0))
		{
			UART_printf("PASS\n");
		}
    	else
    	{
    		ret_val = TEST_FAIL;
		}

		// Receive on port 1
		UART_printf("1       Receive      ");

		if(!checkRx(1))
		{
			UART_printf("PASS\n");
		}
		else
		{
			ret_val = TEST_FAIL;
		}

		// Transmit on port 1
		UART_printf("1       Transmit     ");
		buildTxPackets(1);
		platform_delay(100);

		if(!checkTx(1))
		{
			UART_printf("PASS\n");
		}
		else
		{
			ret_val = TEST_FAIL;
		}

		// Receive on port 0
		UART_printf("0       Receive      ");

		if(!checkRx(0))
		{
			UART_printf("PASS\n");
		}
		else
		{
			ret_val = TEST_FAIL;
		}
	}

	if(fEcho)
	{
		if(fDcan0)
		{
			//buildTxPackets(0);
			startDCANTransfer(0);
			echoPackets(0);
			return (0);
		}

		if(fDcan1)
		{
			startDCANTransfer(1);
			echoPackets(1);
			return (0);
		}
	}

	return (ret_val);
}

/**
 * \brief This function performs dcan test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS dcanTest(void *testArgs)
{
    TEST_STATUS testStatus;
 	dcanTestArgs_t *args = (dcanTestArgs_t *)testArgs;

	UART_printf("\n**************************\n");
	UART_printf(  "       CAN Bus Test       \n");
	UART_printf(  "**************************\n");

 	testStatus = run_dcan_test(args);
 	if(testStatus != TEST_PASS)
 	{
 		UART_printf("\nCAN Bus Test Failed!\n");
 	}
 	else
 	{
 		UART_printf("\nCAN Bus Test Passed!\n");
 	}

	UART_printf("\nCAN Bus Tests Completed!!\n");
	UART_printf("\n-----------------X-----------------\n\n\n");

    return(testStatus);

}  // dcanTest

/**
 * \brief Invokes dcan test functions
 *
 */
int main(void)
{
    TEST_STATUS     testStatus;
    dcanTestArgs_t  testArgs;
    Board_initCfg   boardCfg;

    testArgs.autoRun = 1;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

    /* Invoke DCAN Test */
    testStatus = dcanTest(&testArgs);
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}

/* Nothing past this point */
