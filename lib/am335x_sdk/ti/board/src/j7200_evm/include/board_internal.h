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

#ifndef BOARD_INTERNAL_H_
#define BOARD_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Include Files                                                             *
 *****************************************************************************/
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_device.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>

#include <ti/board/board.h>
#include <ti/csl/tistdtypes.h>
#include <stdio.h>
#include <stdbool.h>

#define BOARD_I2C_PORT_CNT               (9U)

#undef ENABLE_LOGS

#if !defined(BOARD_DEBUG_LOG)
#if defined(ENABLE_LOGS)
#define BOARD_DEBUG_LOG     UART_printf
#else
#define BOARD_DEBUG_LOG(x, ...)
#endif
#endif  /* #if !defined(BOARD_DEBUG_LOG) */

/*****************************************************************************
 * Internal Objects                                                          *
 *****************************************************************************/
extern I2C_config_list I2C_config;

typedef struct
{
    I2C_Handle    i2cHandle;
    uint8_t       i2cDomain;
    uint32_t      instNum;
    uint32_t      i2cBaseAddr;
} Board_gblObj;

extern Board_gblObj Board_obj[BOARD_I2C_PORT_CNT];

/****************************************************************************/

#define BOARD_KICK0_UNLOCK_VAL               (0x68EF3490U)
#define BOARD_KICK1_UNLOCK_VAL               (0xD172BC5AU)

#define BOARD_KICK0_LOCK_VAL                 (0)
#define BOARD_KICK1_LOCK_VAL                 (0)

/* The below macro are for temporary use only, Once the CSL macros are 
 *  added these can be removed */ 

#define MAIN_PSC_ADDR_OFFSET                 (0x80000000U)  //J7ES_TODO: Need to update
#define WAKEUP_PSC_ADDR_OFFSET               (0x20000000U)  //J7ES_TODO: Need to update
/***************************** File name: J7_PSC.gel ***********************************/
//PD indexes
#define PD_GP_CORE_CTL_WKUP		0
#define PD_MCU_PULSAR			1

//LPSC indexes
#define LPSC_WKUP_ALWAYSON 	0
#define LPSC_DMSC			1	//For M3 reset control only.
#define LPSC_DEBUG2DMSC		2
#define LPSC_WKUP_GPIO		3	//For clock gating purposes only. Always on.
#define LPSC_WKUPMCU2MAIN	4
#define LPSC_MAIN2WKUPMCU	5
#define LPSC_MCU_TEST		6
#define LPSC_MCU_DEBUG		7
#define LPSC_MCU_MCAN_0		8
#define LPSC_MCU_MCAN_1		9
#define LPSC_MCU_OSPI_0		10
#define LPSC_MCU_OSPI_1		11
#define LPSC_MCU_HYPERBUS	12
#define LPSC_MCU_I3C_0		13
#define LPSC_MCU_I3C_1		14
#define LPSC_MCU_ADC_0		15
#define LPSC_MCU_ADC_1		16
#define LPSC_WKUP_SPARE_0	17
#define LPSC_WKUP_SPARE_1	18
#define LPSC_MCU_R5_0		19 	//PD_MCU_PULSAR
#define LPSC_MCU_R5_1		20	//PD_MCU_PULSAR
#define LPSC_MCU_PULSAR_PBIST_0	21	//PD_MCU_PULSAR
//WKUP CTRL MMRs --> controls WKUP analog stuff
//MCU CTRL MMRs --> controls MCU PSRAM
//MCU PLL MMRs --> controls MCU PLL programming interfaces
//WKUP PLL Controller --> runs to wkup efuse chain storage

/*
 * macro definitions for the MAIN_PSC
*/

//PD indexes
#define PD_GP_CORE_CTRL	0
#define PD_MCANSS		1
#define PD_DSS			2
#define PD_ICSS			3
#define PD_9GSS			4
#define PD_SERDES_0		5
#define PD_SERDES_1		6
#define PD_SERDES_2		7
#define PD_SERDES_3		8
#define PD_SERDES_4		9
#define PD_SERDES_5		10
#define PD_TIMER		11
#define PD_C71X_0		12
#define PD_C71X_1		13
#define PD_A72_CLUSTER_0	14
#define PD_A72_0 		15
#define PD_A72_1		16
#define PD_A72_CLUSTER_1 17
#define PD_A72_2		18
#define PD_A72_3		19
#define PD_GPUCOM		20
#define PD_GPUCORE		21
#define PD_C66X_0		22
#define PD_C66X_1		23
#define PD_PULSAR_0		24
#define PD_PULSAR_1		25
#define PD_DECODE		26
#define PD_ENCODE		27
#define PD_DMPAC		28
#define PD_VPAC			29

//LPSC indexes
#define LPSC_MAIN_ALWAYSON	0
#define LPSC_MAIN_TEST		1
#define LPSC_MAIN_PBIST		2
#define LPSC_PER_AUDIO		3
#define LPSC_PER_ATL		4
#define LPSC_PER_MLB		5
#define LPSC_PER_MOTOR		6
#define LPSC_PER_MISCIO			7
#define LPSC_PER_GPMC			8
#define LPSC_PER_VPFE			9
#define LPSC_PER_VPE 			10
#define LPSC_PER_SPARE_0	11
#define LPSC_PER_SPARE_1	12
#define LPSC_MAIN_DEBUG		13
#define LPSC_EMIF_DATA_0	14
#define LPSC_EMIF_CFG_0		15
#define LPSC_EMIF_DATA_1	16
#define LPSC_EMIF_CFG_1		17
#define LPSC_PER_SPARE_2	18
#define LPSC_CC_TOP_PBIST	19
#define LPSC_USB_0 			20
#define LPSC_USB_1			21
#define LPSC_USB_2			22
#define LPSC_MMC4B_0		23
#define LPSC_MMC4B_1		24
#define LPSC_MMC8B_0		25
#define LPSC_UFS_0			26
#define LPSC_UFS_1			27
#define LPSC_PCIE_0			28
#define LPSC_PCIE_1			29
#define LPSC_PCIE_2			30
#define LPSC_PCIE_3			31
#define LPSC_SAUL			32
#define LPSC_PER_I3C		33
#define LPSC_MAIN_MCANSS_0	34
#define LPSC_MAIN_MCANSS_1	35
#define LPSC_MAIN_MCANSS_2	36
#define LPSC_MAIN_MCANSS_3	37
#define LPSC_MAIN_MCANSS_4	38
#define LPSC_MAIN_MCANSS_5	39
#define LPSC_MAIN_MCANSS_6	40
#define LPSC_MAIN_MCANSS_7	41
#define LPSC_MAIN_MCANSS_8	42
#define LPSC_MAIN_MCANSS_9	43
#define LPSC_MAIN_MCANSS_10	44
#define LPSC_MAIN_MCANSS_11	45
#define LPSC_MAIN_MCANSS_12	46
#define LPSC_MAIN_MCANSS_13	47
#define LPSC_DSS			48
#define LPSC_DSS_PBIST		49
#define LPSC_DSI 			50
#define LPSC_EDP_0			51
#define LPSC_EDP_1			52
#define LPSC_CSIRX_0		53
#define LPSC_CSIRX_1		54
#define LPSC_CSIRX_2		55
#define LPSC_CSITX_0		56
#define LPSC_TX_DPHY_0		57
#define LPSC_CSIRX_PHY_0	58
#define LPSC_CSIRX_PHY_1	59
#define LPSC_CSIRX_PHY_2	60
#define LPSC_ICSSG_0		61
#define LPSC_ICSSG_1		62
#define LPSC_9GSS			63
#define LPSC_SERDES_0		64
#define LPSC_SERDES_1		65
#define LPSC_SERDES_2		66
#define LPSC_SERDES_3		67
#define LPSC_SERDES_4		68
#define LPSC_SERDES_5		69
#define LPSC_DMTIMER_0		70
#define LPSC_DMTIMER_1		71
#define LPSC_DMTIMER_2		72
#define LPSC_DMTIMER_3		73
#define LPSC_C71X_0			74
#define LPSC_C71X_0_PBIST	75
#define LPSC_C71X_1			76
#define LPSC_C71X_1_PBIST	77
#define LPSC_A72_CLUSTER_0	78
#define LPSC_A72_CLUSTER_0_PBIST	79
#define LPSC_A72_0 			80
#define LPSC_A72_1 			81
#define LPSC_A72_CLUSTER_1	82
#define LPSC_A72_CLUSTER_1_PBIST	83
#define LPSC_A72_2			84
#define LPSC_A72_3			85
#define LPSC_GPUCOM			86
#define LPSC_GPUPBIST		87
#define LPSC_GPUCORE		88
#define LPSC_C66X_0			89
#define LPSC_C66X_PBIST_0	90
#define LPSC_C66X_1			91
#define LPSC_C66X_PBIST_1	92
#define LPSC_PULSAR_0_R5_0	93
#define LPSC_PULSAR_0_R5_1	94
#define LPSC_PULSAR_0_PBIST	95
#define LPSC_PULSAR_1_R5_0	96
#define LPSC_PULSAR_1_R5_1	97
#define LPSC_PULSAR_1_PBIST	98
#define LPSC_DECODE_0		99
#define LPSC_DECODE_PBIST	100
#define LPSC_ENCODE_0		101
#define LPSC_ENCODE_PBIST	102
#define LPSC_DMPAC			103
#define LPSC_SDE 			104
#define LPSC_DMPAC_PBIST	105
#define LPSC_VPAC			106
#define LPSC_VPAC_PBIST		107
//Main CTRL MMRs --> not controlled by Main PSC
//Main PLL CTRL --> not controlled by Main PSC
//Main PLL MMRs --> not controlled by Main PSC

//common base addresses
#define WAKEUP_PSC_BASE 	(0x42000000)
#define MAIN_PSC_BASE		(0x00400000)
#define PSC_PID 			(0x44827A00)
#define M3_SOC_OFFSET 		(0x60000000)
#define M3_RAT_CTRL			(0x44200020) //Base address + CTRL register offset.

//Defines for WKUP and MAIN PSC indices
#define MAIN_PSC_INDEX				0
#define WAKEUP_PSC_INDEX			1

//PSC MMR interface
#define PSC_MDCTL00           		(0xA00)
#define PSC_MDSTAT00          		(0x800)
#define PSC_PDCTL00           		(0x300)
#define PSC_PDSTAT00          		(0x200)
#define PSC_PTCMD 					(0x120)
#define PSC_PTSTAT 					(0x128)

//PSC Parameter definitions
#define PSC_PD_OFF					(0x0)
#define PSC_PD_ON					(0x1)

#define PSC_SYNCRESETDISABLE		(0x0)
#define PSC_SYNCRESET 				(0x1)
#define PSC_DISABLE   				(0x2)
#define PSC_ENABLE    				(0x3)

#define PSC_TIMEOUT					(100)

//PSC Register pre-calculations
#define WAKEUP_PSC_MDCTL_BASE       WAKEUP_PSC_BASE + PSC_MDCTL00
#define WAKEUP_PSC_MDSTAT_BASE      WAKEUP_PSC_BASE + PSC_MDSTAT00
#define WAKEUP_PSC_PDCTL_BASE       WAKEUP_PSC_BASE + PSC_PDCTL00
#define WAKEUP_PSC_PDSTAT_BASE      WAKEUP_PSC_BASE + PSC_PDSTAT00
#define WAKEUP_PSC_PTCMD_BASE		WAKEUP_PSC_BASE + PSC_PTCMD
#define WAKEUP_PSC_PTSTAT_BASE		WAKEUP_PSC_BASE + PSC_PTSTAT
#define WAKEUP_PSC_PTCMD            WAKEUP_PSC_PTCMD_BASE
#define WAKEUP_PSC_PTSTAT           WAKEUP_PSC_PTSTAT_BASE

#define MAIN_PSC_MDCTL_BASE    		MAIN_PSC_BASE + PSC_MDCTL00
#define MAIN_PSC_MDSTAT_BASE      	MAIN_PSC_BASE + PSC_MDSTAT00
#define MAIN_PSC_PDCTL_BASE       	MAIN_PSC_BASE + PSC_PDCTL00
#define MAIN_PSC_PDSTAT_BASE      	MAIN_PSC_BASE + PSC_PDSTAT00
#define MAIN_PSC_PTCMD_BASE			MAIN_PSC_BASE + PSC_PTCMD
#define MAIN_PSC_PTSTAT_BASE		MAIN_PSC_BASE + PSC_PTSTAT
#define MAIN_PSC_PTCMD             	MAIN_PSC_PTCMD_BASE
#define MAIN_PSC_PTSTAT 			MAIN_PSC_PTSTAT_BASE

#define BOARD_MAC_COUNT_SHIFT                 (3U)
#define BOARD_MAC_COUNT_MASK                  (0x00F8U)

/* Ethenet board library MACROs */
#define BOARD_ETHPHY_REGCR_REG_ADDR             (0xDU)
#define BOARD_ETHPHY_REGCR_ADDR_EN              (0x1FU)
#define BOARD_ETHPHY_REGCR_DATA_EN              (0x401FU)
#define BOARD_ETHPHY_ADDAR_REG_ADDR             (0xEU)

#define BOARD_ETHPHY_LEDCR1_REG_ADDR            (0x18U)

#define BOARD_ETHPHY_FLD_THRESH_REG_ADDR        (0x2EU)

#define BOARD_ETHPHY_RGMIICTL_REG_ADDR          (0x32U)
#define BOARD_ETHPHY_RGMIICTL_CLKDELAY_MASK     (0x3U)
#define BOARD_ETHPHY_RGMIICTL_TXDELAY_EN        (0x2U)
#define BOARD_ETHPHY_RGMIICTL_RXDELAY_EN        (0x1U)

#define BOARD_ETHPHY_STRAP_STS1_REG_ADDR        (0x6EU)
#define BOARD_ETHPHY_STRAP_STS2_REG_ADDR        (0x6FU)

#define BOARD_ETHPHY_RGMIIDCTL_REG_ADDR         (0x86U)

#define BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_ADDR    (0x172U)

#define BOARD_ETHPHY_GPIO_MUX_CFG_REG_ADDR      (0x170U)

#define BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_MASK    (0xFU)
#define BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_CFG     (0x6U)

#define BOARD_ETHPHY_LEDCR1_REG_MASK            (0xF000U)
#define BOARD_ETHPHY_LEDCR1_REG_CFG             (0x8000U)

#define BOARD_ETHPHY_ICSSG_DELAY                (0xA9U)
#define BOARD_ETHPHY_CPSW9G_DELAY               (0xA9U)
#define BOARD_ETHPHY_CPSW2G_DELAY               (0x77U)
#define BOARD_ETHPHY_DELAY_CTRL                 (0xD3U)
#define BOARD_ETHPHY_IO_IMPEDANCE               (0x0C1FU)
#define BOARD_CPSW_MDIO_REG_OFFSET              (0xF00U)

#define BOARD_MDIO_CTRL_REG_OFFSET              (0x4U)
#define BOARD_MDIO_CLK_DIV_CFG                  (0xFFU)
#define BOARD_EMAC_DELAY_CFG                    (0x01000000U)

#define BOARD_ETHPHY_STRAP_FLD_MASK             (0x0400U)
#define BOARD_ETHPHY_STRAP_FLD_THS_CHECK_FLAG   (0x222U)

/*********************XXXXXXXXXXXXXXXXXXXXX**********************/

/*****************************************************************************
 * Function Prototypes                                                       *
 *****************************************************************************/


/**
 *  \brief   This function is to get the i2c handle of the requested
 *           instance of the specifed domain
 *
 *  \param   domainType [IN] Domain of I2C controller
 *                             BOARD_SOC_DOMAIN_MAIN - Main Domain
 *                             BOARD_SOC_DOMAIN_WKUP - Wakeup domain
 *                             BOARD_SOC_DOMAIN_MCU - MCU domain
 * 
 *  \param   i2cInst    [IN]        I2C instance
 *
 *  \return  Board_STATUS in case of success or appropriate error code.
 *
 */
I2C_Handle Board_getI2CHandle(uint8_t domainType,
                              uint32_t i2cInst);

/**
 *
 * \brief  Board pinmuxing enable function
 *
 * Enables pinmux for the Maxwell idk board interfaces. Pin mux is done based on the
 * default/primary functionality of the board. Any pins shared by multiple
 * interfaces need to be reconfigured to access the secondary functionality.
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxConfig(void);

/**
 *
 * \brief  Board PLL initialization function
 *
 *  Configures different PLL controller modules. This enables all the PLL
 *  controllers on the SoC with default configurations.
 *
 * \return BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_PLLInit(uint32_t modId, uint32_t clkId, uint64_t clkRate);

/**
 *
 * \brief DDR4 Initialization function
 *
 * Initializes the DDR timing parameters. Sets the DDR timing parameters
 * based in the DDR PLL controller configuration done by the board library.
 * Any changes to DDR PLL requires change to DDR timing. Also supports
 * enabling ECC
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_DDRInit(Bool eccEnable);

/**
 * \brief clock Initialization function for MCU domain
 *
 * Enables different power domains and peripheral clocks of the MCU.
 * Some of the power domains and peripherals will be OFF by default.
 * Enabling the power domains is mandatory before accessing using
 * board interfaces connected to those peripherals.
 *
 * \return  BOARD_SOK              - Clock initialization successful.
 *          BOARD_INIT_CLOCK_FAIL  - Clock initialization failed.
 *
 */
Board_STATUS Board_moduleClockInitMcu(void);

/**
 * \brief clock Initialization function for MAIN domain
 *
 * Enables different power domains and peripheral clocks of the SoC.
 * Some of the power domains and peripherals will be OFF by default.
 * Enabling the power domains is mandatory before accessing using
 * board interfaces connected to those peripherals.
 *
 * \return  BOARD_SOK              - Clock initialization successful.
 *          BOARD_INIT_CLOCK_FAIL  - Clock initialization failed.
 *
 */
Board_STATUS Board_moduleClockInitMain(void);

/**
 * \brief clock de-initialization function for MCU domain
 *
 * Disables different power domains and peripheral clocks of the MCU.
 *
 * \return  BOARD_SOK              - Clock de-initialization successful.
 *          BOARD_INIT_CLOCK_FAIL  - Clock de-initialization failed.
 *
 */
Board_STATUS Board_moduleClockDeinitMcu(void);

/**
 * \brief clock de-initialization function for MAIN domain
 *
 * Disables different power domains and peripheral clocks of the SoC.
 *
 * \return  BOARD_SOK              - Clock de-initialization successful.
 *          BOARD_INIT_CLOCK_FAIL  - Clock de-initialization failed.
 *
 */
Board_STATUS Board_moduleClockDeinitMain(void);

/**
 * \brief  Board specific configurations for CPSW2G Ethernet PHY
 *
 * This function takes care of configuring the internal delays for MCU gigabit
 * Ethernet PHY
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_cpsw2gEthPhyConfig(void);

/**
 * \brief  Board specific configurations for ICSS EMAC Ethernet PHYs
 *
 * This function takes care of configuring the internal delays for ICSS
 * Ethernet PHY
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_icssEthPhyConfig(void);

/**
 * \brief   This function initializes the default UART instance for use for
 *          console operations.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_uartStdioInit(void);

/**
 * \brief  Locks MMR registers
 *
 * \return  Board_STATUS
 */
Board_STATUS Board_lockMMR(void);

/**
 * \brief  Unlocks MMR registers
 *
 * \return  Board_STATUS
 */
Board_STATUS Board_unlockMMR(void);

/**
 *  \brief Serdes configurations
 *
 *  The function detects the personality boards connected and configures the
 *  respective module.
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_serdesCfg(void);

/**
 *
 * \brief  Board PLL initialization function for MCU domain
 *
 *  Configures different PLL controller modules.  This enables all the PLL
 *  controllers in the MCU domain with default configurations.
 *
 * \return BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_PLLInitMcu(void);

/**
 *
 * \brief  Board PLL initialization function for MAIN domain
 *
 *  Configures different PLL controller modules.  This enables all the PLL
 *  controllers in the MAIN domain with default configurations.
 *
 * \return BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_PLLInitMain(void);

/**
 * \brief   Print out PLL configurations- all multiplier and divider values.
 *
 * \param   none
 *
 * \return  none
 */
Board_STATUS Board_getAllPLLConfigurations();

/**
 * \brief Board detect function
 *
 *  Checks if the board with given 'boardID' is connected to the
 *  base board.
 *
 *  \n Note: Board ID EEPROM should be programmed for this function
 *           to work properly.
 *
 * \param   boardID  [IN]  ID of the board to be detected
 * \n                      BOARD_ID_SOM(0x0) - Dual PMIC SoM Board
 * \n                      BOARD_ID_GESI(0x1) - GESI Board
 * \n                      BOARD_ID_INFOTAINMENT(0x2) - Infotainment board
 * \n                      BOARD_ID_FUSION2(0x3) - Fusion 2 Board
 * \n                      BOARD_ID_MV(0x4) - MV expansion
 * \n                      BOARD_ID_LI(0x5) - LI expansion
 * \n                      BOARD_ID_ENET(0x6) - Quad ENET expansion
 * \n                      BOARD_ID_DISPLAY(0x7) - Display adapter board 
 *
 * \return   TRUE if the given board is detected else 0.
 *           SoM board will be always connected to the base board.
 *           For SoM boardID return value TRUE indicates dual PMIC
 *           SoM and FALSE indicates alternate PMIC SoM
 *
 */
bool Board_detectBoard(uint32_t boardID);

/**
  *  \brief   This function initializes the i2c instance connected to
  *           different control modules on the board
  *
  *  This function disables the interrupt mode as the Board i2c instance 
  *  doesn't require interrupt mode and restores back original at the end.
  *
  *  \return  Board_STATUS in case of success or appropriate error code.
  *
  */
Board_STATUS Board_i2cInit(void);

/**
 *  \brief   This function is used to close all the initialized board I2C handles.
 *
 *  \return  Board_STATUS in case of success or appropriate error code.
 */
Board_STATUS Board_i2cDeInit(void);

/**
 *  \brief    Function to programs VDD_CORE to 0.9V.
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pmVDDCoreVoltageCfg(void);

/**
 *  \brief    Function to configure SD card voltage.
 *
 *  \param vsel [IN] SD voltage selection. 0 for 3.3v, 1 for 1.8v
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pmSdVoltageCtrl(uint8_t vsel);

/**
 *  \brief   This function is used to de-initialize board UART handles.
 */
Board_STATUS Board_uartDeInit(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BOARD_INTERNAL_H_ */
