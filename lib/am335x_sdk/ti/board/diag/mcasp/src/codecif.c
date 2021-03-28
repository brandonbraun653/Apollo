/*
* Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/ 
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
*/

/**
 * \file  codecif.c
 *
 * \brief Functions to configure the codec trough i2c or other interfaces.
 *
 * Currently only one interface type is allowed. If another interface to be
 * used, this need enhancement.
 *
 */

#include <stdbool.h>
#include <ti/csl/soc.h>
#include "codecif.h"

#ifdef SOC_K2G
extern CSL_ArmGicDistIntrf distrIntrf;
extern CSL_ArmGicCpuIntrf gCpuIntrf;
CSL_ArmGicIntrParams_t gI2CIntrParams;
#endif

/******************************************************************************
**                      INTERNAL FUNCTION PROTOTYPES
*******************************************************************************/
#if !defined(SOC_AM65XX)
static void BoardDiag_I2CCodecIsr(void);
static void BoardDiag_I2CCodecIntSetup(unsigned int sysIntNum, unsigned int channel);
#endif
static void BoardDiag_I2CCodecSendBlocking(unsigned int baseAddr, unsigned int dataCnt);
static void BoardDiag_I2CCodecRcvBlocking(unsigned int baseAddr, unsigned int dataCnt);
static void BoardDiag_I2CDelay(void);

/******************************************************************************
**                      INTERNAL VARIABLE DEFINITIONS
*******************************************************************************/
volatile unsigned int dataIdx = 0;
volatile unsigned int txCompFlag = 1;
volatile unsigned int slaveData[3];
unsigned int savedBase;

/******************************************************************************
**                          FUNCTION DEFINITIONS
*******************************************************************************/
#if !defined(SOC_AM65XX)
/*
** Sets up the I2C interrupt in the AINTC
*/
static void BoardDiag_I2CCodecIntSetup(unsigned int sysIntNum, unsigned int channel)
{
#ifdef SOC_K2G
    /* Register the ISR in the Interrupt Vector Table.*/
    gI2CIntrParams.triggerType    = CSL_ARM_GIC_TRIG_TYPE_BOTH_EDGE;
    gI2CIntrParams.priority       = 0x20U;
    gI2CIntrParams.pFnIntrHandler = (void *)&BoardDiag_I2CCodecIsr;
    gI2CIntrParams.pUserParam     = NULL;
    CSL_armGicConfigIntr(&gCpuIntrf, sysIntNum, &gI2CIntrParams);
#else
#ifdef BUILD_DSP
	Intc_IntRegister(C674X_MASK_INT4, BoardDiag_I2CCodecIsr);
	IntEventMap(C674X_MASK_INT4, sysIntNum);
	Intc_IntEnable(C674X_MASK_INT4);
#else
	Intc_IntRegister(sysIntNum, BoardDiag_I2CCodecIsr);
	IntChannelSet(sysIntNum, channel);
	Intc_SystemEnable(sysIntNum);
#endif
#endif
}

/* Clears the I2C interrupts */
static void BoardDiag_I2CCodecIntrClear(unsigned int sysIntNum)
{
#ifdef SOC_K2G
    CSL_armGicClearIntr(&gCpuIntrf,sysIntNum);
#else
#ifdef BUILD_DSP
    IntEventClear(sysIntNum);
#else
    IntSystemStatusClear(sysIntNum);
#endif
#endif
}
#endif
/**
 * \brief   Initializes the I2C interface for a codec
 *
 * \param   baseAddr      Base Address of the I2C Module Registers which
 *                        is used for the codec
 *          intCh         Channel Number where the I2C ISR to be registered
 *          slaveAddr     Slave Address of the codec
 *
 * Note: This API enables the system interrupt for the given I2C module only.
 *       It does not do any pin multiplexing or global interrupt enabling. 
 *       This shall be called only after AINTC initialization.
 *
 * \return  None.
 *
 **/
void BoardDiag_I2CCodecIfInit(unsigned int baseAddr, unsigned int intCh,
                              unsigned int slaveAddr)
{
    /* Put i2c in reset/disabled state */
    I2CMasterDisable(baseAddr);

#if defined(SOC_AM65XX)
    /* Configure i2c bus speed to 100khz */
    I2CMasterInitExpClk(baseAddr, 96000000, 4000000, 100000);

    /*Set Rx and Tx FIFO threshold value and reset the fifo*/
    I2CFIFOThresholdConfig(baseAddr, 0, I2C_TX_MODE);

    I2CFIFOThresholdConfig(baseAddr, 0, I2C_RX_MODE);
#else
    /* Configure i2c bus speed to 100khz */
    I2CMasterInitExpClk(baseAddr, 24000000, 8000000, 100000);
#endif

    /* Set i2c slave address */
    I2CMasterSlaveAddrSet(baseAddr, slaveAddr);

    I2CMasterEnable(baseAddr);

#if !defined(SOC_AM65XX)
    BoardDiag_I2CCodecIntSetup(BOARD_I2C_INTR_NUM, intCh);
#endif
}

static void BoardDiag_I2CDelay(void)
{
	volatile int i;
	for(i=0; i<5000; i++);
}

/*
** Function to send data through i2c
*/
static void BoardDiag_I2CCodecSendBlocking(unsigned int baseAddr, unsigned int dataCnt)
{
    txCompFlag = 1;
    dataIdx = 0;    
    savedBase = baseAddr;

#if defined(SOC_AM65XX)
    I2CFIFOClear(baseAddr, I2C_TX_MODE);
    I2CFIFOClear(baseAddr, I2C_RX_MODE);
#endif

    I2CSetDataCount(baseAddr, dataCnt);
#if defined(SOC_AM65XX)
    I2CMasterControl(baseAddr, I2C_CFG_MST_TX);
#else
    I2CMasterControl(baseAddr, I2C_CFG_MASK_TX | I2C_CFG_MASK_REPEAT_MODE,
            I2C_CFG_CMD_TX | I2C_CFG_CMD_REPEAT_MODE_OFF);
    I2CMasterIntEnableEx(baseAddr, I2C_INT_TRANSMIT_READY | I2C_INT_STOP_CONDITION);
#endif
    I2CMasterStart(baseAddr);
#if defined(SOC_AM65XX)
    while(dataIdx < dataCnt)
    {
        if(HW_RD_FIELD32(CSL_I2C0_CFG_BASE+CSL_I2C_STAT, CSL_I2C_STAT_XRDY) == 1)
        {
            I2CMasterDataPut(savedBase, slaveData[dataIdx]);
            dataIdx++;
        }
    }
#endif

    /* Wait till the data is sent */ 
    BoardDiag_I2CDelay();
}

/*
** Function to receive data from the Codec through I2C bus
*/
static void BoardDiag_I2CCodecRcvBlocking(unsigned int baseAddr, unsigned int dataCnt)
{
    txCompFlag = 1;
    dataIdx = 0;
    savedBase = baseAddr;
    
    I2CSetDataCount(baseAddr, dataCnt);

#if defined(SOC_AM65XX)
    I2CMasterControl(baseAddr, I2C_CFG_MST_RX);
#else
    I2CMasterControl(baseAddr, I2C_CFG_MASK_RX | I2C_CFG_MASK_REPEAT_MODE,
            I2C_CFG_CMD_RX | I2C_CFG_CMD_REPEAT_MODE_OFF);
    I2CMasterIntEnableEx(baseAddr, I2C_INT_RECV_READY | I2C_INT_STOP_CONDITION);
#endif
    I2CMasterStart(baseAddr);
#if defined(SOC_AM65XX)
    while(dataIdx < dataCnt)
    {
        if((HW_RD_FIELD32(CSL_I2C0_CFG_BASE+CSL_I2C_STAT, CSL_I2C_STAT_RRDY)) == 1)
        {
            slaveData[dataIdx] = I2CMasterDataGet(savedBase);
            dataIdx++;
        }
    }
#endif

    /* Wait till data is received fully */
    BoardDiag_I2CDelay();
}

#if !defined(SOC_AM65XX)
/*
** ISR to handler i2c interrupts
*/
void BoardDiag_I2CCodecIsr(void)
{
    unsigned int intCode = 0;
    unsigned int sysIntNum = 0;

    /* Get interrupt vector code */
    intCode = I2CIntVectGet(savedBase);
    sysIntNum = BOARD_I2C_INTR_NUM;

    while(intCode!=0)
    {
        /* Clear status of interrupt */
        BoardDiag_I2CCodecIntrClear(sysIntNum);

         if (intCode == I2C_IVR_INTCODE_XRDY)
         {
              I2CMasterDataPut(savedBase, slaveData[dataIdx]);
              dataIdx++;
         }

         if(intCode == I2C_IVR_INTCODE_RRDY)
         {
              slaveData[dataIdx] = I2CMasterDataGet(savedBase);
              dataIdx++;
         }

         if (intCode == I2C_IVR_INTCODE_SCD)
         {
              /* Disable transmit data ready and receive data read interupt */
              I2CMasterIntDisableEx(savedBase, I2C_INT_TRANSMIT_READY
                                               | I2C_INT_RECV_READY);
              txCompFlag = 0;
         }

         intCode = I2CIntVectGet(savedBase);
    }
}
#endif
/*
** Writes a codec register with the given data value
*/
void BoardDiag_CodecRegWrite(unsigned int baseAddr, unsigned char regAddr,
                             unsigned char regData)
{
    /* Send the register address and data */
    slaveData[0] = regAddr;
    slaveData[1] = regData;

    BoardDiag_I2CCodecSendBlocking(baseAddr, 2);
}

/*
** Reads a codec register contents
*/
unsigned char BoardDiag_CodecRegRead(unsigned int baseAddr, unsigned char regAddr)
{
    /* Send the register address */
    slaveData[0] = regAddr;
    BoardDiag_I2CCodecSendBlocking(baseAddr, 1);

    /* Receive the register contents in slaveData */
    BoardDiag_I2CCodecRcvBlocking(baseAddr, 1);

    return (slaveData[0]);
}

/*
** Sets codec register bit specified in the bit mask
*/
void BoardDiag_CodecRegBitSet(unsigned int baseAddr, unsigned char regAddr,
                              unsigned char bitMask)
{
    /* Send the register address */
    slaveData[0] = regAddr;
    BoardDiag_I2CCodecSendBlocking(baseAddr, 1);
  
    /* Receive the register contents in slaveData */
    BoardDiag_I2CCodecRcvBlocking(baseAddr, 1);

    slaveData[1] =  slaveData[0] | bitMask;
    slaveData[0] = regAddr;

    BoardDiag_I2CCodecSendBlocking(baseAddr, 2);

}

/*
** Clears codec register bits specified in the bit mask
*/
void BoardDiag_CodecRegBitClr(unsigned int baseAddr, unsigned char regAddr,
                              unsigned char bitMask)
{
    /* Send the register address */
    slaveData[0] = regAddr;
    BoardDiag_I2CCodecSendBlocking(baseAddr, 1);

    /* Receive the register contents in slaveData */
    BoardDiag_I2CCodecRcvBlocking(baseAddr, 1);

    slaveData[1] =  slaveData[0] & ~bitMask;
    slaveData[0] = regAddr;
   
    BoardDiag_I2CCodecSendBlocking(baseAddr, 2);

}

/***************************** End Of File ***********************************/
