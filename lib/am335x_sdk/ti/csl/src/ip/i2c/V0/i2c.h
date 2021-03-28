/**
 *  \file      i2c.h
 *
 *  \brief     File provides functional level API prototypes for I2C interface.
 *             It also contains some related macro definitions and some files to
 *             be included.
 */


/*
 * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef I2C_V0_H_
#define I2C_V0_H_

#include <ti/csl/src/ip/i2c/V0/V0_0/cslr_i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/*
** Values that can be passed to  I2CMasterControl API as cmd to configure mode
** of operation of I2C
*/

#define I2C_CFG_MASK_TX             (CSL_I2C_ICMDR_TRX_MASK)
#define I2C_CFG_MASK_RX             (CSL_I2C_ICMDR_TRX_MASK)
#define I2C_CFG_MASK_STOP           (CSL_I2C_ICMDR_STP_MASK)
#define I2C_CFG_MASK_START          (CSL_I2C_ICMDR_STT_MASK)
#define I2C_CFG_MASK_RUN_FREE       (CSL_I2C_ICMDR_FREE_MASK)
#define I2C_CFG_MASK_REPEAT_MODE    (CSL_I2C_ICMDR_RM_MASK)
#define I2C_CFG_MASK_LOOP_BACK      (CSL_I2C_ICMDR_DLB_MASK)
#define I2C_CFG_MASK_XA             (CSL_I2C_ICMDR_XA_MASK)


#define I2C_CFG_CMD_TX              (CSL_I2C_ICMDR_TRX_MASK)
#define I2C_CFG_CMD_RX              (0U)
#define I2C_CFG_CMD_STOP            (CSL_I2C_ICMDR_STP_MASK)
#define I2C_CFG_CMD_START           (CSL_I2C_ICMDR_STT_MASK)
#define I2C_CFG_CMD_RUN_FREE_ON     (CSL_I2C_ICMDR_FREE_MASK)
#define I2C_CFG_CMD_RUN_FREE_OFF    (0U)
#define I2C_CFG_CMD_REPEAT_MODE_ON  (CSL_I2C_ICMDR_RM_MASK)
#define I2C_CFG_CMD_REPEAT_MODE_OFF (0U)
#define I2C_CFG_CMD_LOOP_BACK_ON    (CSL_I2C_ICMDR_DLB_MASK)
#define I2C_CFG_CMD_LOOP_BACK_OFF   (0U)
#define I2C_CFG_CMD_10BIT_ADDRESS   (I2C_CFG_MASK_XA)
#define I2C_CFG_CMD_7BIT_ADDRESS    (0U)

/****************************************************************************/
/*
** Values that can be passed to I2CMasterIntStatusEx and I2CMasterIntClearEx
** APIs as int status flag to check and clear interrupt status
*/
#define I2C_INT_ARBITRATION_LOST     (CSL_I2C_ICSTR_AL_MASK)
#define I2C_INT_NO_ACK               (CSL_I2C_ICSTR_NACK_MASK)
#define I2C_INT_ADRR_READY_ACESS     (CSL_I2C_ICSTR_ARDY_MASK)
#define I2C_INT_RECV_READY           (CSL_I2C_ICSTR_ICRRDY_MASK)
#define I2C_INT_TRANSMIT_READY       (CSL_I2C_ICSTR_ICXRDY_MASK)
#define I2C_INT_STOP_CONDITION       (CSL_I2C_ICSTR_SCD_MASK)
#define I2C_INT_ADRR_ZERO            (CSL_I2C_ICSTR_AD0_MASK)
#define I2C_INT_ADRR_SLAVE           (CSL_I2C_ICSTR_AAS_MASK)
#define I2C_INT_TRANSMIT_UNDER_FLOW  (CSL_I2C_ICSTR_XSMT_MASK)
#define I2C_INT_RECV_OVER_RUN        (CSL_I2C_ICSTR_RSFULL_MASK)
#define I2C_INT_BUS_BUSY             (CSL_I2C_ICSTR_BB_MASK)
#define I2C_INT_NO_ACK_SENT          (CSL_I2C_ICSTR_NACKSNT_MASK)
#define I2C_INT_SLAVE_DIRECTION      (CSL_I2C_ICSTR_SDIR_MASK)

#define I2C_ALL_INTS                (I2C_INT_ARBITRATION_LOST     | \
                                     I2C_INT_NO_ACK               | \
                                     I2C_INT_ADRR_READY_ACESS     | \
                                     I2C_INT_RECV_READY           | \
                                     I2C_INT_TRANSMIT_READY       | \
                                     I2C_INT_STOP_CONDITION       | \
                                     I2C_INT_ADRR_ZERO            | \
                                     I2C_INT_ADRR_SLAVE           | \
                                     I2C_INT_TRANSMIT_UNDER_FLOW  | \
                                     I2C_INT_RECV_OVER_RUN        | \
                                     I2C_INT_BUS_BUSY             | \
                                     I2C_INT_NO_ACK_SENT          | \
                                     I2C_INT_SLAVE_DIRECTION)


/****************************************************************************/
/*
** Values that can be passed to I2CMasterIntEnableEx and I2CMasterIntDisableEx
** APIs as intFlag to enable or disable interrupts.
*/
#define I2C_INT_MASK_ARBITRATION_LOST     (CSL_I2C_ICIMR_AL_MASK)
#define I2C_INT_MASK_NO_ACK               (CSL_I2C_ICIMR_NACK_MASK)
#define I2C_INT_MASK_ADRR_READY_ACESS     (CSL_I2C_ICIMR_ARDY_MASK)
#define I2C_INT_MASK_RECV_READY           (CSL_I2C_ICIMR_ICRRDY_MASK)
#define I2C_INT_MASK_TRANSMIT_READY       (CSL_I2C_ICIMR_ICXRDY_MASK)
#define I2C_INT_MASK_STOP_CONDITION       (CSL_I2C_ICIMR_SCD_MASK)
#define I2C_INT_MASK_ADRR_SLAVE           (CSL_I2C_ICIMR_AAS_MASK)

#define I2C_ALL_INTS_MASK           (I2C_INT_MASK_ARBITRATION_LOST     | \
                                     I2C_INT_MASK_NO_ACK               | \
                                     I2C_INT_MASK_ADRR_READY_ACESS     | \
                                     I2C_INT_MASK_RECV_READY           | \
                                     I2C_INT_MASK_TRANSMIT_READY       | \
                                     I2C_INT_MASK_STOP_CONDITION       | \
                                     I2C_INT_MASK_ADRR_SLAVE)

/****************************************************************************/
/*
** I2C own slave address which distinguishes it from other slaves
** connected to the I2C-bus.
*/
#define I2C_OWN_ADDR                 0x10

/****************************************************************************/
/*
** I2C interrupt vector Code.
*/
#define I2C_IVR_INTCODE_MASK             (CSL_I2C_ICIVR_INTCODE_MASK)
#define I2C_IVR_INTCODE_AL               (CSL_I2C_ICIVR_INTCODE_AL)
#define I2C_IVR_INTCODE_NACK             (CSL_I2C_ICIVR_INTCODE_NACK)
#define I2C_IVR_INTCODE_ARDY             (CSL_I2C_ICIVR_INTCODE_RAR)
#define I2C_IVR_INTCODE_RRDY             (CSL_I2C_ICIVR_INTCODE_RDR)
#define I2C_IVR_INTCODE_XRDY             (CSL_I2C_ICIVR_INTCODE_TDR)
#define I2C_IVR_INTCODE_SCD              (CSL_I2C_ICIVR_INTCODE_SCD)
#define I2C_IVR_INTCODE_AAS              (CSL_I2C_ICIVR_INTCODE_AAS)

/****************************************************************************/

/*****************************************************************************/

/* I2C AM57x hardware register read/write functions */
extern  void I2CMasterStop(uint32_t baseAdd);
extern  void I2CMasterStart(uint32_t baseAdd);
extern  void I2CMasterEnable(uint32_t baseAdd);
extern  void I2CSlaveEnable(uint32_t baseAdd);
extern  void I2CMasterDisable(uint32_t baseAdd);
extern  uint32_t I2CMasterErr(uint32_t baseAdd);
extern  uint32_t I2CDataCountGet(uint32_t baseAdd);
extern  uint8_t I2CMasterDataGet(uint32_t baseAdd);
extern  bool I2CMasterBusBusy(uint32_t baseAdd);
extern  void I2CMasterControl(uint32_t baseAdd, uint32_t ctrlMask, uint32_t ctrlCmds);
extern  void I2CModeControl(uint32_t baseAdd, uint32_t ctrlMask, uint32_t ctrlCmds);
extern  void I2CSetDataCount(uint32_t baseAdd, uint32_t count);
extern  void I2CMasterDataPut(uint32_t baseAdd, uint8_t data);
extern  void I2CMasterInitExpClk(uint32_t baseAdd, uint32_t sysClk,
                                 uint32_t internalClk, uint32_t outputClk);
extern  void I2CMasterIntClearEx(uint32_t baseAdd, uint32_t intFlag);
extern  void I2CMasterIntEnableEx(uint32_t baseAdd, uint32_t intFlag);
extern  void I2CMasterIntDisableEx(uint32_t baseAdd, uint32_t intFlag);

extern  void I2CMasterSlaveAddrSet(uint32_t baseAdd, uint32_t slaveAdd);
extern  uint32_t I2CMasterIntStatusEx(uint32_t baseAdd, uint32_t intFlag);
extern  void I2COwnAddressSet(uint32_t baseAddr, uint32_t ownAddr);
extern  uint32_t I2CIntVectGet(uint32_t baseAdd);
#ifdef __cplusplus
}
#endif

#endif
