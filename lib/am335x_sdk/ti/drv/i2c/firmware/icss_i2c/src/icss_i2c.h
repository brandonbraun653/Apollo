/*
*  TEXAS INSTRUMENTS TEXT FILE LICENSE
* 
*  Copyright (c) 2017-2018 Texas Instruments Incorporated
* 
*  All rights reserved not granted herein.
*  
*  Limited License.  
* 
*  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive 
*  license under copyrights and patents it now or hereafter owns or controls to 
*  make, have made, use, import, offer to sell and sell ("Utilize") this software 
*  subject to the terms herein.  With respect to the foregoing patent license, 
*  such license is granted  solely to the extent that any such patent is necessary 
*  to Utilize the software alone.  The patent license shall not apply to any 
*  combinations which include this software, other than combinations with devices 
*  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
* 
*  Redistributions must preserve existing copyright notices and reproduce this license 
*  (including the above copyright notice and the disclaimer and (if applicable) source 
*  code license limitations below) in the documentation and/or other materials provided 
*  with the distribution.
*  
*  Redistribution and use in binary form, without modification, are permitted provided 
*  that the following conditions are met:
*  No reverse engineering, decompilation, or disassembly of this software is 
*  permitted with respect to any software provided in binary form.
*  Any redistribution and use are licensed by TI for use only with TI Devices.
*  Nothing shall obligate TI to provide you with source code for the software 
*  licensed and provided to you in object code.
*  
*  If software source code is provided to you, modification and redistribution of the 
*  source code are permitted provided that the following conditions are met:
*  Any redistribution and use of the source code, including any resulting derivative 
*  works, are licensed by TI for use only with TI Devices.
*  Any redistribution and use of any object code compiled from the source code
*  and any resulting derivative works, are licensed by TI for use only with TI Devices.
* 
*  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
*  may be used to endorse or promote products derived from this software without 
*  specific prior written permission.
* 
*  DISCLAIMER.
* 
*  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
*  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
*  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S 
*  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
*  GOODS OR SERVICES* LOSS OF USE, DATA, OR PROFITS* OR BUSINESS INTERRUPTION) HOWEVER 
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* file:   icss_i2c.h
*
* brief: This is a common header file with all memory map configuration.
*
*
*  (C) Copyright 2017-2018, Texas Instruments, Inc
*
*/

#ifndef ICSS_I2C_H
#define ICSS_I2C_H

/* The Memory Size of I2C Instance */
#define ICSS_I2C_INSTANCE_SIZE                     (0x0300)
/* The Memory offset of I2C Tx Buffer */
#define ICSS_I2C_INSTANCE_TX_OFFSET                (0x0100)
/* The Memory offset of I2C Rx Buffer */
#define ICSS_I2C_INSTANCE_RX_OFFSET                (0x0200)

#ifndef AM437X_ICSS0
/* The Memory offset of I2C Config Buffer */
#define ICSS_I2C_CONFIG_MEMORY                     (0x0400)

#else   // AM437X_ICSS0
// Relocate base address to 0x0 of DMEM.
// This is required to fit image in 4 kB of ICSS1 DMEM.
#define ICSS_I2C_CONFIG_MEMORY                     (0x0000)

#endif  // AM437X_ICSS0

/* The Memory region of I2C INSTANCE0 MMap */
#define ICSS_I2C_INSTANCE0_ADDR                    (ICSS_I2C_CONFIG_MEMORY + 0x0100)
/* The Memory region of I2C INSTANCE1 MMap */
#define ICSS_I2C_INSTANCE1_ADDR                    (ICSS_I2C_INSTANCE0_ADDR + ICSS_I2C_INSTANCE_SIZE)
/* The Memory region of I2C INSTANCE2 MMap */
#define ICSS_I2C_INSTANCE2_ADDR                    (ICSS_I2C_INSTANCE1_ADDR + ICSS_I2C_INSTANCE_SIZE)
/* The Memory region of I2C INSTANCE3 MMap */
#define ICSS_I2C_INSTANCE3_ADDR                    (ICSS_I2C_INSTANCE2_ADDR + ICSS_I2C_INSTANCE_SIZE)

/* The Memory region of I2C INSTANCE0 Tx buffer */
#define ICSS_I2C_INSTANCE0_TX_MEM                  (ICSS_I2C_INSTANCE0_ADDR + ICSS_I2C_INSTANCE_TX_OFFSET)
/* The Memory region of I2C INSTANCE1 Tx buffer */
#define ICSS_I2C_INSTANCE1_TX_MEM                  (ICSS_I2C_INSTANCE1_ADDR + ICSS_I2C_INSTANCE_TX_OFFSET)
/* The Memory region of I2C INSTANCE2 Tx buffer */
#define ICSS_I2C_INSTANCE2_TX_MEM                  (ICSS_I2C_INSTANCE2_ADDR + ICSS_I2C_INSTANCE_TX_OFFSET)
/* The Memory region of I2C INSTANCE3 Tx buffer */
#define ICSS_I2C_INSTANCE3_TX_MEM                  (ICSS_I2C_INSTANCE3_ADDR + ICSS_I2C_INSTANCE_TX_OFFSET)

/* The Memory region of I2C INSTANCE0 Rx buffer */
#define ICSS_I2C_INSTANCE0_RX_MEM                  (ICSS_I2C_INSTANCE0_ADDR + ICSS_I2C_INSTANCE_RX_OFFSET)
/* The Memory region of I2C INSTANCE1 Rx buffer */
#define ICSS_I2C_INSTANCE1_RX_MEM                  (ICSS_I2C_INSTANCE1_ADDR + ICSS_I2C_INSTANCE_RX_OFFSET)
/* The Memory region of I2C INSTANCE2 Rx buffer */
#define ICSS_I2C_INSTANCE2_RX_MEM                  (ICSS_I2C_INSTANCE2_ADDR + ICSS_I2C_INSTANCE_RX_OFFSET)
/* The Memory region of I2C INSTANCE3 Rx buffer */
#define ICSS_I2C_INSTANCE3_RX_MEM                  (ICSS_I2C_INSTANCE3_ADDR + ICSS_I2C_INSTANCE_RX_OFFSET)

/* The Memory offset of I2C Revision Register low value */
#define ICSS_I2C_REVNB_LO_OFFSET                   (0x00)
/* The Memory offset of I2C Revision Register high value */
#define ICSS_I2C_REVNB_HI_OFFSET                   (0x04)
/* The Memory offset of I2C command value register */
#define ICSS_I2C_COMMAND_OFFSET                    (0x08)
/* The Memory offset of I2C IRQ status register */
#define ICSS_I2C_IRQSTATUS_OFFSET                  (0x28)
/* The Memory offset of I2C Fifo size register */
#define ICSS_I2C_BUF_OFFSET                        (0x94)
/* The Memory offset of I2C data count register */
#define ICSS_I2C_CNT_OFFSET                        (0x98)
/* The Memory offset of I2C configuration register */
#define ICSS_I2C_CON_OFFSET                        (0xA4)
/* The Memory offset of I2C slave address register */
#define ICSS_I2C_SA_OFFSET                         (0xAC)
/* The Memory offset of I2C input output pin value */
#define ICSS_I2C_PRU_PIN_OFFSET                    (0xD8)
/* The Memory offset of I2C clock value register */
#define ICSS_I2C_PRU_CLK_VAL_OFFSET                (0xDC)
/* The Memory offset of I2C smbus command code register */
#define ICSS_I2C_PRU_CMD_CODE_OFFSET               (0xE0)
/* The Memory offset of I2C instance id register */
#define ICSS_I2C_PRU_INST_ID_OFFSET                (0xE4)

/* The register bit for enabling i2c instance */
#define ICSS_I2C_MODULE_ENABLE_BIT                 (15)
/* The register bit for selecting master or slave */
#define ICSS_I2C_MASTER_SLAVE_MODE_BIT             (10)
/* The register bit for selecting address mode */
#define ICSS_I2C_ADDRESSING_MODE_BIT               (8)
/* The register bit for enabling i2c burst mode */
#define ICSS_I2C_SMBUS_BURST_BIT                   (5)
/* The register bit for deciding NACK recieve */
#define ICSS_I2C_RECIEVE_NACK_BIT                  (4)
/* The register bit for deciding ACK recieve */
#define ICSS_I2C_ACK_RECIEVED_BIT                  (3)
/* The register bit for selecting between read/write */
#define ICSS_I2C_READ_WRITE_BIT                    (2)
/* The register bit for enabling start bit */
#define ICSS_I2C_START_BIT                         (0)
/* The register bit for enabling stop bit */
#define ICSS_I2C_STOP_BIT                          (1)

/* The command value for resetting I2C instance */
#define ICSS_I2C_RESET_CMD                         (0x10U)
/* The command value for setting up I2C instance */
#define ICSS_I2C_SETUP_CMD                         (0x11U)
/* The command value for start Rx for I2C instance */
#define ICSS_I2C_RX_CMD                            (0x12U)
/* The command value for start Tx for I2C instance */
#define ICSS_I2C_TX_CMD                            (0x13U)
/* The command value for start quick cmd for I2C instance */
#define ICSS_SMBUS_QUICK_CMD                       (0x14U)
/* The command value for start send byte cmd for I2C instance */
#define ICSS_SMBUS_SEND_BYTE_CMD                   (0x15U)
/* The command value for start recieve byte cmd for I2C instance */
#define ICSS_SMBUS_RECEIVE_BYTE_CMD                (0x16U)
/* The command value for start write byte cmd for I2C instance */
#define ICSS_SMBUS_WRITE_BYTE_CMD                  (0x17U)
/* The command value for start read byte cmd for I2C instance */
#define ICSS_SMBUS_READ_BYTE_CMD                   (0x18U)
/* The command value for start write word cmd for I2C instance */
#define ICSS_SMBUS_WRITE_WORD_CMD                  (0x19U)
/* The command value for start read word for I2C instance */
#define ICSS_SMBUS_READ_WORD_CMD                   (0x1AU)
/* The command value for start block write for I2C instance */
#define ICSS_SMBUS_BLOCK_WRITE_CMD                 (0x1BU)
/* The command value for start block read for I2C instance */
#define ICSS_SMBUS_BLOCK_READ_CMD                  (0x1CU)
/* The command value for start read scl cmd for I2C instance */
#define ICSS_I2C_READ_SCL_CMD                      (0x1DU)
/* The command value for start reset slave cmd for I2C instance */
#define ICSS_I2C_RESET_SLAVE_CMD                   (0x1EU)
/* The command value for loopback mode */
#define ICSS_I2C_LOOPBACK_CMD                      (0x1FU)

/* The response for command successful */
#define COMMAND_SUCCESS                            (0x0500U)
/* The response for reset command failure */
#define RESET_COMMAND_FAILED                       (0x0501U)
/* The response for setup command failure */
#define SETUP_COMMAND_FAILED                       (0x0502U)
/* The response for tx command failure */
#define TX_COMMAND_FAILED                          (0x0503U)
/* The response for rx command failure */
#define RX_COMMAND_FAILED                          (0x0504U)
/* The response for if SCL value high */
#define SCL_VALUE_HIGH                             (0x0505U)
/* The response for if SCL value low */
#define SCL_VALUE_LOW                              (0x0506U)
/* The response for sucessfull reset command */
#define RESET_SLAVE_DONE                           (0x0507U)
/* The response for NACK for address transmission */
#define ADDRESS_ACKNOWLDEGE_FAILED                 (0x0508U)
/* The response for NACK for data transmission */
#define DATA_ACKNOWLDEGE_FAILED                    (0x0509U)
/* The response for wrong master slave configuration */
#define MASTER_SLAVE_MODE_FAILED                   (0x050AU)
/* The response for wrong addressing mode configuration */
#define ADDRESSING_MODE_FAILED                     (0x050BU)
/* The response for invalid command passed configuration */
#define INVALID_COMMAND                            (0x050CU)
/* The response for incorrect data count configuration */
#define INVALID_DATA_COUNT                         (0x050DU)
/* The time out for the response to come */
#define TIME_OUT_ERROR                             (0x050EU)

#ifdef PRU0                                      
/* The random delay value for PRU0 */
#define DELAY_CYCLE                                (0x7FU)
#endif                                           
#ifdef PRU1                                      
/* The random delay value for PRU1 */
#define DELAY_CYCLE                                (0xFFU)
#endif                                           

/* The iep counter increment value for 400KHz value */
//  1 I2C instance, time-slice 125 (625/5) cycles.
//  => bus clock time is 125*4/200e6 = 2.5 usec.
//  => bus clock speed is 1/2.5e-6 = 400 kHz
#define IEP_CMP_INCREMENT_VAL_400KHZ               (0x00000270U)  // 400 kHz
#define IEP_CMP_INCREMENT_HALF_VAL_400KHZ          (0x00000138U)

/* The iep counter increment value for 100KHz value */
//  4 I2C instances, time-slice 125 (625/5) cycles.
//  => bus clock time is 125*4*4/200e6 = 10 usec.
//  => bus clock speed is 1/10e-6 = 100 kHz
#define IEP_CMP_INCREMENT_VAL_100KHZ               (0x00000270U)  // 100 kHz, 4x instances
#define IEP_CMP_INCREMENT_HALF_VAL_100KHZ          (0x00000138U)

#ifndef AM437X_ICSS0
/* The iep counter increment value for 1MHz value */
//  1 I2C instance, time-slice 50 (250/5) cycles.
//  => bus clock time is 50*4/200e6 = 1 usec.
//  => bus clock speed is 1/1e-6 = 1 MHz
#define IEP_CMP_INCREMENT_VAL_1MHZ                 (0x000000FAU)  // 1 MHz, 1x instance
#define IEP_CMP_INCREMENT_HALF_VAL_1MHZ            (0x0000007DU)

#else   // AM437X_ICSS0
//  1 I2C instance, time-slice 64 (320/5) cycles.
//  => bus clock time is 64*4/200e6 = 1.28 usec.
//  => bus clock speed is 1/1.28e-6 = 781.25 kHz
#define IEP_CMP_INCREMENT_VAL_1MHZ                  (0x00000140U)   // 781.25 kHz, 1x instance
#define IEP_CMP_INCREMENT_HALF_VAL_1MHZ             (0x000000A0U)

#endif  // AM437X_ICSS0

/* The register offset of IRQ status for host to read */
#define IRQ_COMMON_REGISTER_OFFSET                 (0x0008U)
/* The register offset of global frequency set */
#define I2C_BUS_FREQUENCY_OFFSET                   (0x000CU)

/* The frequency configuration for I2C FW */
#define ICSS_I2C_NO_FREQ                           (0x00U)
/* The frequency configuration for I2C FW @ 1MHZ */
#define ICSS_I2C_1MHZ_FREQ                         (0x01U)
/* The frequency configuration for I2C FW @ 400KHZ */
#define ICSS_I2C_400KHZ_FREQ                       (0x02U)
/* The frequency configuration for I2C FW @ 100KHZ */
#define ICSS_I2C_100KHZ_FREQ                       (0x03U)

/* The interrupt line used for host for PRU0*/
#define ICSS_I2C_INTC_PRU0_BIT_VAL                 (0x00100000U)
/* The interrupt line used for host for PRU1*/
#define ICSS_I2C_INTC_PRU1_BIT_VAL                 (0x00200000U)

#endif

