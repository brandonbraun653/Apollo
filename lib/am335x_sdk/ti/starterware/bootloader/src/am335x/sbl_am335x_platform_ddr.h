/**
 *  \file  sbl_am335x_platform_ddr.h
 *
 *  \brief This file contain functions which configure EMIF and DDR.
 *
 *  \copyright Copyright (C) 2013-2017 Texas Instruments Incorporated -
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

#ifndef BL_PLATFORM_DDR_H_
#define BL_PLATFORM_DDR_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* TODO : These are not there in the control module header file */
#define DDR_PHY_CTRL_REGS                  (SOC_CONTROL_REGS + 0x2000)
#define CMD0_SLAVE_RATIO_0                 (DDR_PHY_CTRL_REGS + 0x1C)
#define CMD0_SLAVE_FORCE_0                 (DDR_PHY_CTRL_REGS + 0x20)
#define CMD0_SLAVE_DELAY_0                 (DDR_PHY_CTRL_REGS + 0x24)
#define CMD0_LOCK_DIFF_0                   (DDR_PHY_CTRL_REGS + 0x28)
#define CMD0_INVERT_CLKOUT_0               (DDR_PHY_CTRL_REGS + 0x2C)
#define CMD1_SLAVE_RATIO_0                 (DDR_PHY_CTRL_REGS + 0x50)
#define CMD1_SLAVE_FORCE_0                 (DDR_PHY_CTRL_REGS + 0x54)
#define CMD1_SLAVE_DELAY_0                 (DDR_PHY_CTRL_REGS + 0x58)
#define CMD1_LOCK_DIFF_0                   (DDR_PHY_CTRL_REGS + 0x5C)
#define CMD1_INVERT_CLKOUT_0               (DDR_PHY_CTRL_REGS + 0x60)
#define CMD2_SLAVE_RATIO_0                 (DDR_PHY_CTRL_REGS + 0x84)
#define CMD2_SLAVE_FORCE_0                 (DDR_PHY_CTRL_REGS + 0x88)
#define CMD2_SLAVE_DELAY_0                 (DDR_PHY_CTRL_REGS + 0x8C)
#define CMD2_LOCK_DIFF_0                   (DDR_PHY_CTRL_REGS + 0x90)
#define CMD2_INVERT_CLKOUT_0               (DDR_PHY_CTRL_REGS + 0x94)
#define DATA0_RD_DQS_SLAVE_RATIO_0         (DDR_PHY_CTRL_REGS + 0xC8)
#define DATA0_RD_DQS_SLAVE_RATIO_1         (DDR_PHY_CTRL_REGS + 0xCC)
#define DATA0_WR_DQS_SLAVE_RATIO_0         (DDR_PHY_CTRL_REGS + 0xDC)
#define DATA0_WR_DQS_SLAVE_RATIO_1         (DDR_PHY_CTRL_REGS + 0xE0)
#define DATA0_WRLVL_INIT_RATIO_0           (DDR_PHY_CTRL_REGS + 0xF0)
#define DATA0_WRLVL_INIT_RATIO_1           (DDR_PHY_CTRL_REGS + 0xF4)
#define DATA0_GATELVL_INIT_RATIO_0         (DDR_PHY_CTRL_REGS + 0xFC)
#define DATA0_GATELVL_INIT_RATIO_1         (DDR_PHY_CTRL_REGS + 0x100)
#define DATA0_FIFO_WE_SLAVE_RATIO_0        (DDR_PHY_CTRL_REGS + 0x108)
#define DATA0_FIFO_WE_SLAVE_RATIO_1        (DDR_PHY_CTRL_REGS + 0x10C)
#define DATA0_WR_DATA_SLAVE_RATIO_0        (DDR_PHY_CTRL_REGS + 0x120)
#define DATA0_WR_DATA_SLAVE_RATIO_1        (DDR_PHY_CTRL_REGS + 0x124)
#define DATA0_USE_RANK0_DELAYS_0           (DDR_PHY_CTRL_REGS + 0x134)
#define DATA0_LOCK_DIFF_0                  (DDR_PHY_CTRL_REGS + 0x138)
#define DATA1_RD_DQS_SLAVE_RATIO_0         (DDR_PHY_CTRL_REGS + 0x16c)
#define DATA1_RD_DQS_SLAVE_RATIO_1         (DDR_PHY_CTRL_REGS + 0x170)
#define DATA1_WR_DQS_SLAVE_RATIO_0         (DDR_PHY_CTRL_REGS + 0x180)
#define DATA1_WR_DQS_SLAVE_RATIO_1         (DDR_PHY_CTRL_REGS + 0x184)
#define DATA1_WRLVL_INIT_RATIO_0           (DDR_PHY_CTRL_REGS + 0x194)
#define DATA1_WRLVL_INIT_RATIO_1           (DDR_PHY_CTRL_REGS + 0x198)
#define DATA1_GATELVL_INIT_RATIO_0         (DDR_PHY_CTRL_REGS + 0x1a0)
#define DATA1_GATELVL_INIT_RATIO_1         (DDR_PHY_CTRL_REGS + 0x1a4)
#define DATA1_FIFO_WE_SLAVE_RATIO_0        (DDR_PHY_CTRL_REGS + 0x1ac)
#define DATA1_FIFO_WE_SLAVE_RATIO_1        (DDR_PHY_CTRL_REGS + 0x1b0)
#define DATA1_WR_DATA_SLAVE_RATIO_0        (DDR_PHY_CTRL_REGS + 0x1c4)
#define DATA1_WR_DATA_SLAVE_RATIO_1        (DDR_PHY_CTRL_REGS + 0x1c8)
#define DATA1_USE_RANK0_DELAYS_0           (DDR_PHY_CTRL_REGS + 0x1d8)
#define DATA1_LOCK_DIFF_0                  (DDR_PHY_CTRL_REGS + 0x1dc)


/* DDR3 init values */
#ifdef PLATFORM_EVM_SI

#define DDR3_CMD0_SLAVE_RATIO_0            (0x80)
#define DDR3_CMD0_INVERT_CLKOUT_0          (0x0)
#define DDR3_CMD1_SLAVE_RATIO_0            (0x80)
#define DDR3_CMD1_INVERT_CLKOUT_0          (0x0)
#define DDR3_CMD2_SLAVE_RATIO_0            (0x80)
#define DDR3_CMD2_INVERT_CLKOUT_0          (0x0)

#define DDR3_DATA0_RD_DQS_SLAVE_RATIO_0    (0x3B)
#define DDR3_DATA0_WR_DQS_SLAVE_RATIO_0    (0x3C)
#define DDR3_DATA0_FIFO_WE_SLAVE_RATIO_0   (0xA5)
#define DDR3_DATA0_WR_DATA_SLAVE_RATIO_0   (0x74)

#define DDR3_DATA0_RD_DQS_SLAVE_RATIO_1    (0x3B)
#define DDR3_DATA0_WR_DQS_SLAVE_RATIO_1    (0x3C)
#define DDR3_DATA0_FIFO_WE_SLAVE_RATIO_1   (0xA5)
#define DDR3_DATA0_WR_DATA_SLAVE_RATIO_1   (0x74)

#define DDR3_CONTROL_DDR_CMD_IOCTRL_0      (0x18B)
#define DDR3_CONTROL_DDR_CMD_IOCTRL_1      (0x18B)
#define DDR3_CONTROL_DDR_CMD_IOCTRL_2      (0x18B)

#define DDR3_CONTROL_DDR_DATA_IOCTRL_0      (0x18B)
#define DDR3_CONTROL_DDR_DATA_IOCTRL_1      (0x18B)

#define DDR3_CONTROL_DDR_IO_CTRL           (0xefffffff)

#define DDR3_EMIF_DDR_PHY_CTRL_1           (0x06)
#define DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN         (0x00100000)
#define DDR3_EMIF_DDR_PHY_CTRL_1_SHDW      (0x06)
#define DDR3_EMIF_DDR_PHY_CTRL_1_SHDW_DY_PWRDN    (0x00100000)
#define DDR3_EMIF_DDR_PHY_CTRL_2           (0x06)

#define DDR3_EMIF_SDRAM_TIM_1              (0x0888A39B)
#define DDR3_EMIF_SDRAM_TIM_1_SHDW         (0x0888A39B)

#define DDR3_EMIF_SDRAM_TIM_2              (0x26517FDA)
#define DDR3_EMIF_SDRAM_TIM_2_SHDW         (0x26517FDA)

#define DDR3_EMIF_SDRAM_TIM_3              (0x501F84EF)
#define DDR3_EMIF_SDRAM_TIM_3_SHDM         (0x501F84EF)

#define DDR3_EMIF_SDRAM_REF_CTRL_VAL1      (0x0000093B)
#define DDR3_EMIF_SDRAM_REF_CTRL_SHDW_VAL1 (0x0000093B)

#define DDR3_EMIF_ZQ_CONFIG_VAL            (0x50074BE4)

/*
** termination = 1 (RZQ/4)
** dynamic ODT = 2 (RZQ/2)
** SDRAM drive = 0 (RZQ/6)
** CWL = 0 (CAS write latency = 5)
** CL = 2 (CAS latency = 5)
** ROWSIZE = 7 (16 row bits)
** PAGESIZE = 2 (10 column bits)
*/
#define DDR3_EMIF_SDRAM_CONFIG             (0x61C04BB2)

#else

#define DDR3_CMD0_SLAVE_RATIO_0            (0x40)
#define DDR3_CMD0_INVERT_CLKOUT_0          (0x1)
#define DDR3_CMD1_SLAVE_RATIO_0            (0x40)
#define DDR3_CMD1_INVERT_CLKOUT_0          (0x1)
#define DDR3_CMD2_SLAVE_RATIO_0            (0x40)
#define DDR3_CMD2_INVERT_CLKOUT_0          (0x1)

#define DDR3_DATA0_RD_DQS_SLAVE_RATIO_0    (0x3B)
#define DDR3_DATA0_WR_DQS_SLAVE_RATIO_0    (0x85)
#define DDR3_DATA0_FIFO_WE_SLAVE_RATIO_0   (0x100)
#define DDR3_DATA0_WR_DATA_SLAVE_RATIO_0   (0xC1)

#define DDR3_DATA0_RD_DQS_SLAVE_RATIO_1    (0x3B)
#define DDR3_DATA0_WR_DQS_SLAVE_RATIO_1    (0x85)
#define DDR3_DATA0_FIFO_WE_SLAVE_RATIO_1   (0x100)
#define DDR3_DATA0_WR_DATA_SLAVE_RATIO_1   (0xC1)

#define DDR3_CONTROL_DDR_CMD_IOCTRL_0      (0x18B)
#define DDR3_CONTROL_DDR_CMD_IOCTRL_1      (0x18B)
#define DDR3_CONTROL_DDR_CMD_IOCTRL_2      (0x18B)

#define DDR3_CONTROL_DDR_DATA_IOCTRL_0      (0x18B)
#define DDR3_CONTROL_DDR_DATA_IOCTRL_1      (0x18B)

//#define DDR3_CONTROL_DDR_IO_CTRL           (0x0fffffff)
#define DDR3_CONTROL_DDR_IO_CTRL           (0xefffffff)

#define DDR3_EMIF_DDR_PHY_CTRL_1           (0x06)
#define DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN         (0x00100000)
#define DDR3_EMIF_DDR_PHY_CTRL_1_SHDW      (0x06)
#define DDR3_EMIF_DDR_PHY_CTRL_1_SHDW_DY_PWRDN    (0x00100000)
#define DDR3_EMIF_DDR_PHY_CTRL_2           (0x06)

#define DDR3_EMIF_SDRAM_TIM_1              (0x0888A39B)
#define DDR3_EMIF_SDRAM_TIM_1_SHDW         (0x0888A39B)

#define DDR3_EMIF_SDRAM_TIM_2              (0x26337FDA)
#define DDR3_EMIF_SDRAM_TIM_2_SHDW         (0x26337FDA)

#define DDR3_EMIF_SDRAM_TIM_3              (0x501F830F)
#define DDR3_EMIF_SDRAM_TIM_3_SHDM         (0x501F830F)

#define DDR3_EMIF_SDRAM_REF_CTRL_VAL1      (0x0000093B)
#define DDR3_EMIF_SDRAM_REF_CTRL_SHDW_VAL1 (0x0000093B)

#define DDR3_EMIF_ZQ_CONFIG_VAL            (0x50074BE4)
#define DDR3_EMIF_SDRAM_CONFIG             (0x61C04AB2)//termination = 1 (RZQ/4)
                                                       //dynamic ODT = 2 (RZQ/2)
                                                       //SDRAM drive = 0 (RZQ/6)
                                                       //CWL = 0 (CAS write latency = 5)
                                                       //CL = 2 (CAS latency = 5)
                                                       //ROWSIZE = 5 (14 row bits)
                                                       //PAGESIZE = 2 (10 column bits)

#endif

/* DDR2 init values */

#define DDR2_CMD0_SLAVE_RATIO_0            (0x80)
#define DDR2_CMD0_SLAVE_FORCE_0            (0x0)
#define DDR2_CMD0_SLAVE_DELAY_0            (0x0)
#define DDR2_CMD0_LOCK_DIFF_0              (0x4)
#define DDR2_CMD0_INVERT_CLKOUT_0          (0x0)

#define DDR2_CMD1_SLAVE_RATIO_0            (0x80)
#define DDR2_CMD1_SLAVE_FORCE_0            (0x0)
#define DDR2_CMD1_SLAVE_DELAY_0            (0x0)
#define DDR2_CMD1_LOCK_DIFF_0              (0x4)
#define DDR2_CMD1_INVERT_CLKOUT_0          (0x0)

#define DDR2_CMD2_SLAVE_RATIO_0            (0x80)
#define DDR2_CMD2_SLAVE_FORCE_0            (0x0)
#define DDR2_CMD2_SLAVE_DELAY_0            (0x0)
#define DDR2_CMD2_LOCK_DIFF_0              (0x4)
#define DDR2_CMD2_INVERT_CLKOUT_0          (0x0)

#define DDR2_DATA0_RD_DQS_SLAVE_RATIO_0    (0x12)
#define DDR2_DATA0_WR_DQS_SLAVE_RATIO_0    (0x0)
#define DDR2_DATA0_FIFO_WE_SLAVE_RATIO_0   (0x80)
#define DDR2_DATA0_WR_DATA_SLAVE_RATIO_0   (0x40)

#define DDR2_DATA1_RD_DQS_SLAVE_RATIO_0    (0x12)
#define DDR2_DATA1_WR_DQS_SLAVE_RATIO_0    (0x0)
#define DDR2_DATA1_FIFO_WE_SLAVE_RATIO_0   (0x80)
#define DDR2_DATA1_WR_DATA_SLAVE_RATIO_0   (0x40)

#define DDR2_CONTROL_DDR_CMD_IOCTRL_0      (0x18B)
#define DDR2_CONTROL_DDR_CMD_IOCTRL_1      (0x18B)
#define DDR2_CONTROL_DDR_CMD_IOCTRL_2      (0x18B)
#define DDR2_CONTROL_DDR_DATA_IOCTRL_0     (0x18B)
#define DDR2_CONTROL_DDR_DATA_IOCTRL_1     (0x18B)

#define DDR2_CONTROL_DDR_IO_CTRL           (0x0fffffff)
#define DDR2_EMIF_DDR_PHY_CTRL_1           (0x05)
#define DDR2_EMIF_DDR_PHY_CTRL_1_DY_PWRDN         (0x00100000)
#define DDR2_EMIF_DDR_PHY_CTRL_1_SHDW      (0x05)
#define DDR2_EMIF_DDR_PHY_CTRL_1_SHDW_DY_PWRDN    (0x00100000)
#define DDR2_EMIF_DDR_PHY_CTRL_2           (0x05)

#define DDR2_EMIF_SDRAM_TIM_1          (0x0666B3D6)
#define DDR2_EMIF_SDRAM_TIM_1_SHDW         (0x0666B3D6)
#define DDR2_EMIF_SDRAM_TIM_2              (0x143731DA)
#define DDR2_EMIF_SDRAM_TIM_2_SHDW     (0x143731DA)
#define DDR2_EMIF_SDRAM_TIM_3              (0x00000347)
#define DDR2_EMIF_SDRAM_TIM_3_SHDM         (0x00000347)
#define DDR2_EMIF_SDRAM_CONFIG             (0x41805332)
#define DDR2_EMIF_SDRAM_REF_CTRL_VAL1      (0x00004650)
#define DDR2_EMIF_SDRAM_REF_CTRL_SHDW_VAL1 (0x00004650)

#define DDR2_EMIF_SDRAM_REF_CTRL_VAL2      (0x0000081a)
#define DDR2_EMIF_SDRAM_REF_CTRL_SHDW_VAL2 (0x0000081a)

/**
 * DDR parameters as per the structure requirement
 */

#define DDR_NOTAPPLICABLE_VALUE 			(0x00000000U)
/**
 * DDR2 configurations for BEAGLEBONE and others.
 */

#define DDR2_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE		(0x18BU)
#define DDR2_CONTROL_DDR_DATA_IOCTRL_VALUE		(0x18BU)
#define DDR2_CONTROL_DDR_IOCTRL_VALUE			(0x0fffffffU)


#define DDR2_EMIF_DDR_PHY_CTRL_VALUE			(0x0E084007U)

/**
 * DDR2 configurations for BEAGLEBONE.
 */

/**
 * DDR EMIF physical configuration for command
 */
#define BBW_DDR2_CMD_SLAVE_RATIO				(0x80U)
#define BBW_DDR2_CMD_SLAVE_FORCE            		(0x0U)
#define BBW_DDR2_CMD_SLAVE_DELAY            		(0x0U)
#define BBW_DDR2_CMD_LOCK_DIFF              		(0x4U)
#define BBW_DDR2_CMD_INVERT_CLKOUT          		(0x0U)

/**
 * DDR EMIF physical configuration for data
 */
#define BBW_DDR2_DATA_RD_DQS_SLAVE_RATIO    		(0x12U)
#define BBW_DDR2_DATA_WR_DQS_SLAVE_RATIO    		(0x0U)
#define BBW_DDR2_DATA_FIFO_WE_SLAVE_RATIO   		(0x80U)
#define BBW_DDR2_DATA_WR_DATA_SLAVE_RATIO   		(0x40U)

/**
 *DDR Emif registers.
 */
#define BBW_DDR2_EMIF_DDR_PHY_CTRL_1		(0x05U)
#define BBW_DDR2_EMIF_DDR_PHY_CTRL_1_DY_PWRDN	(0x00100000U)

#define BBW_DDR2_EMIF_SDRAM_TIM_1_VALUE          (0x0666B3D6U)
#define BBW_DDR2_EMIF_SDRAM_TIM_2_VALUE          (0x143731DAU)
#define BBW_DDR2_EMIF_SDRAM_TIM_3_VALUE          (0x00000347U)

#define BBW_DDR2_EMIF_SDRAM_CONFIG_VALUE         (0x41805332U)

#define BBW_DDR2_EMIF_SDRAM_REF_CTRL_VAL1      	(0x00004650U)
#define BBW_DDR2_EMIF_SDRAM_REF_CTRL_VAL2      	(0x0000081aU)



/**
 * DDR3 configurations for BEAGLEBONEBLACK and others.
 */

#define DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE		(0x18BU)
#define DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE		(0x18BU)
#define DDR3_CONTROL_DDR_IOCTRL_VALUE			(0xefffffffU)

#define DDR3_EMIF_DDR_PHY_CTRL_VALUE                    (0x0E084007U)
#define DDR3_ZQ_CONFIG_VALUE                            (0x50074BE4U)

/**
 * DDR3 configurations for BEAGLEBONEBLACK.
 */

/**
 * DDR EMIF physical configuration for command
 */
#define BBB_DDR3_CMD_SLAVE_RATIO            (0x80U)
#define BBB_DDR3_CMD_INVERT_CLKOUT          (0x0U)

/**
 * DDR EMIF physical configuration for data
 */
#define BBB_DDR3_DATA_RD_DQS_SLAVE_RATIO    (0x38U)
#define BBB_DDR3_DATA_WR_DQS_SLAVE_RATIO    (0x44U)
#define BBB_DDR3_DATA_FIFO_WE_SLAVE_RATIO   (0x94U)
#define BBB_DDR3_DATA_WR_DATA_SLAVE_RATIO   (0x7dU)

/**
 *DDR Emif registers.
 */
#define BBB_DDR3_EMIF_DDR_PHY_CTRL_1        	(0x07U)
#define BBB_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN   	(0x00100000U)

#define BBB_DDR3_EMIF_SDRAM_TIM_1_VALUE         	(0x0AAAD4DBU)
#define BBB_DDR3_EMIF_SDRAM_TIM_2_VALUE         	(0x266B7FDAU)
#define BBB_DDR3_EMIF_SDRAM_TIM_3_VALUE         	(0x501F867FU)

#define BBB_DDR3_EMIF_SDRAM_CONFIG_VALUE        	(0x61C05332U)

#define BBB_DDR3_EMIF_SDRAM_REF_CTRL_VAL1      	(0x00000C30U)

/**
 * DDR3 configurations for EVM.
 */

/**
 * DDR EMIF physical configuration for command
 */
#define EVM_DDR3_CMD_SLAVE_RATIO                    (0x80U)
#define EVM_DDR3_CMD_INVERT_CLKOUT                  (0x0U)

/**
 * DDR EMIF physical configuration for data
 */
#define EVM_DDR3_DATA_RD_DQS_SLAVE_RATIO            (0x3BU)
#define EVM_DDR3_DATA_WR_DQS_SLAVE_RATIO            (0x3CU)
#define EVM_DDR3_DATA_FIFO_WE_SLAVE_RATIO           (0xA5U)
#define EVM_DDR3_DATA_WR_DATA_SLAVE_RATIO           (0x74U)

/**
 *DDR Emif registers.
 */
#define EVM_DDR3_EMIF_DDR_PHY_CTRL_1                (0x06U)
#define EVM_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN       (0x00100000U)

#define EVM_DDR3_EMIF_SDRAM_TIM_1_VALUE             (0x0888A39BU)
#define EVM_DDR3_EMIF_SDRAM_TIM_2_VALUE             (0x26517FDAU)
#define EVM_DDR3_EMIF_SDRAM_TIM_3_VALUE             (0x501F84EFU)

#define EVM_DDR3_EMIF_SDRAM_CONFIG_VALUE            (0x61C04BB2U)

#define EVM_DDR3_EMIF_SDRAM_REF_CTRL_VAL1           (0x0000093BU)

/**
 * DDR3 configurations for SK.
 */

/**
 * DDR EMIF physical configuration for command
 */
#define SK_DDR3_CMD_SLAVE_RATIO                   (0x40U)
#define SK_DDR3_CMD_INVERT_CLKOUT                 (0x1U)

/**
 * DDR EMIF physical configuration for data
 */
#define SK_DDR3_DATA_RD_DQS_SLAVE_RATIO           (0x3BU)
#define SK_DDR3_DATA_WR_DQS_SLAVE_RATIO           (0x85U)
#define SK_DDR3_DATA_FIFO_WE_SLAVE_RATIO          (0x100U)
#define SK_DDR3_DATA_WR_DATA_SLAVE_RATIO          (0xC1U)

/**
 *DDR Emif registers.
 */
#define SK_DDR3_EMIF_DDR_PHY_CTRL_1               (0x06U)
#define SK_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN      (0x00100000U)

#define SK_DDR3_EMIF_SDRAM_TIM_1_VALUE            (0x0888A39BU)
#define SK_DDR3_EMIF_SDRAM_TIM_2_VALUE            (0x26337FDAU)
#define SK_DDR3_EMIF_SDRAM_TIM_3_VALUE            (0x501F830FU)

#define SK_DDR3_EMIF_SDRAM_CONFIG_VALUE           (0x61C04AB2U)

#define SK_DDR3_EMIF_SDRAM_REF_CTRL_VAL1          (0x0000093BU)

/**
 * DDR2 configurations for ICE ver1.
 */

/**
 * DDR EMIF physical configuration for command
 */
#define ICEv1_DDR2_CMD_SLAVE_RATIO				    (0x80U)
#define ICEv1_DDR2_CMD_SLAVE_FORCE            		(0x0U)
#define ICEv1_DDR2_CMD_SLAVE_DELAY            		(0x0U)
#define ICEv1_DDR2_CMD_LOCK_DIFF              		(0x4U)
#define ICEv1_DDR2_CMD_INVERT_CLKOUT          		(0x0U)

/**
 * DDR EMIF physical configuration for data
 */
#define ICEv1_DDR2_DATA_RD_DQS_SLAVE_RATIO    		(0x12U)
#define ICEv1_DDR2_DATA_WR_DQS_SLAVE_RATIO    		(0x0U)
#define ICEv1_DDR2_DATA_FIFO_WE_SLAVE_RATIO   		(0x80U)
#define ICEv1_DDR2_DATA_WR_DATA_SLAVE_RATIO   		(0x40U)

/**
 *DDR Emif registers.
 */
#define ICEv1_DDR2_EMIF_DDR_PHY_CTRL_1		        (0x05U)
#define ICEv1_DDR2_EMIF_DDR_PHY_CTRL_1_DY_PWRDN	    (0x00100000U)

#define ICEv1_DDR2_EMIF_SDRAM_TIM_1_VALUE           (0x0666B3C9U)
#define ICEv1_DDR2_EMIF_SDRAM_TIM_2_VALUE           (0x243631CAU)
#define ICEv1_DDR2_EMIF_SDRAM_TIM_3_VALUE           (0x00000337U)

#define ICEv1_DDR2_EMIF_SDRAM_CONFIG_VALUE          (0x41805332U)

#define ICEv1_DDR2_EMIF_SDRAM_REF_CTRL_VAL1      	(0x00004650U)
#define ICEv1_DDR2_EMIF_SDRAM_REF_CTRL_VAL2      	(0x0000081aU)

/**
 * DDR3 configurations for ICEv2.
 */

/**
 * DDR EMIF physical configuration for command
 */
#define ICEv2_DDR3_CMD_SLAVE_RATIO                   (0x80U)
#define ICEv2_DDR3_CMD_INVERT_CLKOUT                 (0x00U)

/**
 * DDR EMIF physical configuration for data
 */
#define AMIC110_DDR3_DATA_WR_DQS_SLAVE_RATIO         (0x39U)
#define AMIC110_DDR3_DATA_WR_DATA_SLAVE_RATIO        (0x71U)

#define ICEv2_DDR3_DATA_RD_DQS_SLAVE_RATIO           (0x3AU)
#define ICEv2_DDR3_DATA_WR_DQS_SLAVE_RATIO           (0x3BU)
#define ICEv2_DDR3_DATA_FIFO_WE_SLAVE_RATIO          (0x96U)
#define ICEv2_DDR3_DATA_WR_DATA_SLAVE_RATIO          (0x76U)

/**
 *DDR Emif registers.
 */
#define ICEv2_DDR3_EMIF_DDR_PHY_CTRL_1               (0x07U)
#define ICEv2_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN      (0x00100000U)

#define AMIC110_DDR3_EMIF_SDRAM_TIM_1_VALUE          (0x0AAAD4DBU)
#define AMIC110_DDR3_EMIF_SDRAM_TIM_2_VALUE          (0x266B7FDAU)
#define AMIC110_DDR3_EMIF_SDRAM_TIM_3_VALUE          (0x501F867FU)
#define AMIC110_DDR3_EMIF_SDRAM_CONFIG_VALUE         (0x61C05332U)

#define ICEv2_DDR3_EMIF_SDRAM_TIM_1_VALUE            (0x0AAAD4DBU)
#define ICEv2_DDR3_EMIF_SDRAM_TIM_2_VALUE            (0x26437FDAU)
#define ICEv2_DDR3_EMIF_SDRAM_TIM_3_VALUE            (0x501F83FFU)
#define ICEv2_DDR3_EMIF_SDRAM_CONFIG_VALUE           (0x61C052B2U)

#define ICEv2_DDR3_EMIF_SDRAM_REF_CTRL_VAL1          (0x00000C30U)
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function initializes the DDR
 *
 * \param dynPwrDown  Is dynamic power down condifuration applicable.
 *                    - FALSE for SoC revisons 1.x.
 *                    - TRUE for SoC revisons 2.x and above.
 */
void SBLPlatformDdrInit(uint32_t dynPwrDown, uint32_t boardId);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef BL_PLATFORM_DDR_H_ */
