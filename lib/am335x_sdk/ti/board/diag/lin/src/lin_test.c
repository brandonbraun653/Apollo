/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 * \file   lin_test.c
 *
 * In the LIN test example two EVMs are used to test the LIN diagnostic example.
 * As described in the following figure, EVM1 is configured as a Master 
 * and EVM2 is configured as slave.
 *
 *         EVM1                                           EVM2  
 *   ------------------                             -------------------
 *   |                |              LIN data       |                 |
 *   |   MASTER       | <-------------------------->|    SLAVE        |
 *   |                |                             |                 |
 *   ------------------                             -------------------
 *
 * Once the LIN transceiver is enabled, the following sequence of actions will
 * happen:
 *  - Master sends data to slave EVM.
 *  - Slave waits to receive all the data
 *  - Slave sends the data back to master
 *  - Master receives all the data
 *  - Master verifies if the received data matches the expected data and declares
 *    test pass or fail.
 *
 */

#include "lin_test.h"

/**
 * \brief  LIN send function
 *
 * This function writes the data to the UART buffers
 *
 * \param  handle    -  UART handler
 * \param  writeBuf   -  Data buffer
 * \param  byteCount -  Number of bytes to write the data
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
static int8_t BoardDiag_linSend(UART_Handle handle, uint8_t *writeBuf,
                                uint32_t byteCount)
{
    int8_t  ret = 0;

    ret = UART_write(handle, (uint8_t *)&writeBuf[0], byteCount);
    if(!ret)
    {
        UART_close(handle);
        return -1;
    }

    return 0;
}

/**
 * \brief  LIN receive function
 *
 * This function is used to read the LIN data
 *
 * \param  handle    -  UART handler
 * \param  readBuf   -  buffer to store the lin data
 * \param  byteCount -  Number of bytes to read
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
static int8_t BoardDiag_linReceive(UART_Handle handle, uint8_t *readBuf,
                                   uint8_t byteCount)
{
    int8_t  ret = 0;

    ret = UART_read(handle, (uint8_t *)&readBuf[0], byteCount);
    if(!ret)
    {
        UART_close(handle);
        return -1;
    }

    return 0;
}

/**
 * \brief  LIN Enable function
 *
 * This function Enables the LIN transceiver
 *
 */
static void BoardDiag_linEnable(void)
{
    GPIO_init();
    GPIO_write(0, 1);
}

/**
 * \brief  LIN config function
 *
 * This function configures the UART with specified instance
 *
 * \param  instance    -  UART instance
 * \param  baseAddress -  UART base Address
 *
 * \return UART_Handle - UART handler for the specified instance
 *
 */
static UART_Handle BoardDiag_linConfig(uint32_t instance, uint32_t baseAddress)
{
    UART_Handle       uartHandle = NULL;
    UART_Params       uartParams;
    UART_HwAttrs      uartCfg;

    UART_init();
    UART_Params_init(&uartParams);

    /* Change the UART default baudrate. LIN can operate upto 20k */
    uartParams.baudRate = BOARD_DIAG_LIN_BAUDRATE;

    UART_socGetInitCfg(instance, &uartCfg);
    uartCfg.baseAddr        = baseAddress;
    uartCfg.enableInterrupt = FALSE;
    uartCfg.frequency       = 48000000;
    UART_socSetInitCfg(instance, &uartCfg);

    uartHandle = UART_open(instance, &uartParams);

    return uartHandle;
}

/**
 * \brief  LIN test function
 *
 * This function executes the LIN diagnostic test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
int8_t BoardDiag_linTest(void)
{
    linData_t      linMasterData;
    linData_t      linSlaveData;
    UART_Handle    handle        = NULL;
    uint32_t       timeout       = 0;
    uint32_t       index         = 0;
    uint32_t       failIndex     = 0;
    uint8_t        txBuf[BOARD_DIAG_LIN_DATA_BYTES] = {0x00};
    uint8_t        modeResponse  = 0;
    uint8_t        linMode       = 0;
    int8_t         status        = 0;
    bool           compareStatus = 1;

    UART_printf  ("***********************************************\n");
    UART_printf  ("*                LIN Test                     *\n");
    UART_printf  ("***********************************************\n");

    BoardDiag_genPattern((uint8_t *)(&linMasterData),
                         sizeof(linData_t),
                         BOARD_DIAG_TEST_PATTERN_FF);

    BoardDiag_genPattern((uint8_t *)(&linSlaveData),
                         sizeof(linData_t),
                         BOARD_DIAG_TEST_PATTERN_FF);
    
    UART_printf  ("Enter: M for Master mode or S for Slave mode\n");
    UART_scanFmt  ("%c", &modeResponse);
    if ((modeResponse == 'M') || (modeResponse == 'm'))
    {
        linMode = BOARD_DIAG_LIN_MASTER_MODE;
        UART_printf ("\n* Master mode *\n");
    }
    else if ((modeResponse == 'S') || (modeResponse == 's'))
    {
        linMode = BOARD_DIAG_LIN_SLAVE_MODE;
        UART_printf ("\n* Slave mode *\n");
    }
    else
    {
        UART_printf ("\nWrong Mode Entered!!. Please Enter M or S \n");
        return -1;
    }
    
    /* Enable the LIN transceiver */
    BoardDiag_linEnable();

    handle = BoardDiag_linConfig(BOARD_LIN_UART_INSTANCE, BOARD_LIN_UART_BASE);
    if(handle == NULL)
    {
        UART_printf("\nFailed to get the UART handle\n");
        return -1;
    }

    if(linMode == BOARD_DIAG_LIN_MASTER_MODE)
    {
        linMasterData.breakfield1   = BOARD_DIAG_LIN_BREAKFIELD1;
        linMasterData.breakfield2   = BOARD_DIAG_LIN_BREAKFIELD2;
        linMasterData.sync          = BOARD_DIAG_LIN_SYNCFIELD;
        linMasterData.pid           = BOARD_DIAG_LIN_SLAVE_ID;
        linMasterData.slaveResponse = 0x00;

        BoardDiag_genPattern((uint8_t *)(&linMasterData.data),
                             BOARD_DIAG_LIN_DATA_BYTES,
                             BOARD_DIAG_TEST_PATTERN_INC);

        for(index = 0; index < BOARD_DIAG_LIN_DATA_BYTES; index++)
        {
            txBuf[index] = linMasterData.data[index];
        }

        UART_printf("\nTransmitting Data to Slave \n");

        status = BoardDiag_linSend(handle, (uint8_t *)(&linMasterData),
                                   sizeof(linMasterData));
        if(status != 0)
        {
            UART_printf("\nFailed to Send the LIN Packet\n");
            UART_close(handle);
            return -1;
        }

        UART_printf("\nWaiting for Response from the Slave \n");

        while((linMasterData.slaveResponse) != BOARD_DIAG_LIN_SLAVE_RSP)
        {
            status = BoardDiag_linReceive(handle, (uint8_t *) (&linMasterData),
                                          sizeof(linMasterData));
            if(status != 0)
            {
                UART_printf("\nFailed to Read the Slave Response\n");
            }

            BOARD_delay(1000);

            timeout++;
            if(timeout >= BOARD_DIAG_LIN_TEST_TIMEOUT)
            {
                UART_printf("\nSlave Response Timeout!\n");
                status = -1;
                break;
            }
        }

        if(((linMasterData.slaveResponse) == BOARD_DIAG_LIN_SLAVE_RSP) &&
           (status == 0))
        {
            UART_printf("\nReceived Response from the Slave\n");

            for(index = 0; index < BOARD_DIAG_LIN_DATA_BYTES; index++)
            {
                txBuf[index] = ~(txBuf[index]);
            }

            /* Data Comparison */
            compareStatus = BoardDiag_memCompare(&txBuf[0],
                                                 (uint8_t *)(&linMasterData.data),
                                                 BOARD_DIAG_LIN_DATA_BYTES,
                                                 &failIndex);
            if(!(compareStatus))
            {
                UART_printf("\nData Mismatch at offset %d \n",failIndex);
                return -1;
            }
            else
            {
                UART_printf("\nData Comparison Successful\n");
                UART_printf("\nLIN Test Completed\n");
                return 0;
            }
        }
    }
    else
    {
        /* waiting to receive the data from master */
        UART_printf("\nWaiting to receive the data from Master \n");

        while((linSlaveData.pid) != BOARD_DIAG_LIN_SLAVE_ID)
        {
            status = BoardDiag_linReceive(handle, (uint8_t *)(&linSlaveData),
                                          sizeof(linSlaveData));
            if(status != 0)
            {
                UART_printf("\nFailed to receive the LIN data\n");
            }

            BOARD_delay(1000);

            timeout++;
            if(timeout >= BOARD_DIAG_LIN_TEST_TIMEOUT)
            {
                UART_printf("\nReceive Timeout!\n");
                status = -1;
                break;
            }
        }

        if(((linSlaveData.pid) == BOARD_DIAG_LIN_SLAVE_ID) && ( status == 0))
        {
            UART_printf("\nData Received from the Master\n");

            /* Complementing the data and sending it back to master */
            for(index = 0; index < BOARD_DIAG_LIN_DATA_BYTES; index++)
            {
                linSlaveData.data[index] = ~(linSlaveData.data[index]);
            }

            UART_printf("\nSending Data to Master \n");

            linSlaveData.slaveResponse = BOARD_DIAG_LIN_SLAVE_RSP;
            status = BoardDiag_linSend(handle, (uint8_t *) (&linSlaveData),
                                       sizeof(linSlaveData));
            if(status != 0)
            {
                UART_printf("\nFailed to Send the LIN Packet\n");
                UART_close(handle);
                return -1;
            }
        }
        else
        {
            UART_printf("\nSlave ID is not Matching\n");
            status = -1;
        }
    }

    UART_close(handle);

    return status;
}


/**
 * \brief  main function
 *
 *  This function performs board initializations and calls LIN test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */

int main(void)
{
    int8_t ret = 0;

    Board_initCfg boardCfg;
    Board_PinmuxConfig_t pinmuxCfg;
   
    boardCfg = BOARD_INIT_UART_STDIO |
               BOARD_INIT_PINMUX_CONFIG;

    /* Enable the pinmux for GESI board */
    Board_pinmuxGetCfg(&pinmuxCfg);
    pinmuxCfg.gesiExp = BOARD_PINMUX_GESI_ICSSG;
    Board_pinmuxSetCfg(&pinmuxCfg);

    Board_init(boardCfg);

    ret = BoardDiag_linTest();
    if(ret == 0)
    {
        UART_printf("\nLIN Test Passed!\n");
    }
    else
    {
        UART_printf("\nLIN Test Failed!!\n");
    }

    return ret;
}
