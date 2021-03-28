/*
 * Copyright (c) 2011-2017, Texas Instruments Incorporated
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
 *  @file   platform_internal.h
 *
 *  @brief  Private definitions for the Platform Library.
 *
 *  ============================================================================
 */

#ifndef _PLATFORM_INTERNAL_H_
#define _PLATFORM_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************
 * 					BUILD OPTIONS FOR THE LIBRARY											*
 *******************************************************************************************/

/***
 * @brief  The following flags are used for controlling the build of Platform Library
 */

/*  brief Platform Library version number */
#define PLATFORM_LIB_VERSION "3.02.00.00"

/* Turn on and off debug statements (may not be safe in certain contexts) */
#define	PLATFORM_DEBUG	0

#define	PLATFORM_VERSTRING_IN		  0
#define	PLATFORM_INIT_IN			  1
#define	PLATFORM_GETINFO_IN			  0
#define PLATFORM_GETCOREID_IN		  0
#define PLATFORM_GETSWITCHSTATE_IN	  0
#define PLATFORM_GETMACADDR_IN		  0
#define PLATFORM_GETPHYADDR_IN		  0
#define PLATFORM_PHYLINKSTATUS_IN	  0
#define PLATFORM_DELAY_IN			  1
#define PLATFORM_LED_IN				  0
#define PLATFORM_WRITE_IN			  1
#define PLATFORM_READ_IN              0
#define	PLATFORM_EXTMEMTEST_IN		  0
#define	PLATFORM_I2C_EEPROM_WRITE_IN  1
#define	PLATFORM_I2C_EEPROM_IN		  1
#define	PLATFORM_UART_IN			  0
#define	PLATFORM_NOR_IN				  1
#define	PLATFORM_NOR_READ_IN		  1
#define	PLATFORM_NOR_WRITE_IN		  1
#define PLATFORM_NAND_IN			  1
#define PLATFORM_NAND_READ_IN		  1
#define PLATFORM_NAND_WRITE_IN		  1
#define PLATFORM_NAND_ECC_IN          1
#define PLATFORM_SEMLOCK_IN			  0
#define PLATFORM_CACHE_IN			  0
#define PLATFORM_GPIO_IN 			  1
#define PLATFORM_I2C_IN 			  1
#define PLATFORM_I2C_IO_EXP_IN 		  0
#define PLATFORM_AUDIO                0
#define PLATFORM_AUDIO_ADC            0
#define PLATFORM_AUDIO_DAC            0
#define PLATFORM_AUDIO_DIR            0
#define PLATFORM_MMCHS_IN             0
#define PLATFORM_DSS_IN               0
#define PLATFORM_DCAN_IN              0
#define PLATFORM_QSPI_FLASH_IN        1
#define PLATFORM_QSPI_FLASH_READ_IN   1
#define PLATFORM_QSPI_FLASH_WRITE_IN  1

#if 0
/* These flags compile in and out functionality offered by the library allowing you to control
 * the size of the code that is included.
 */
#ifdef _PLATFORM_LITE_
	/*
	 * Build a version of Platform Library suitable for use in an EEPROM or other small application.
	 * (likely needs tailoring to the specific application if size matters)
	 */
	#define	PLATFORM_VERSTRING_IN		  1
	#define	PLATFORM_INIT_IN			  1
	#define	PLATFORM_GETINFO_IN			  1
	#define PLATFORM_GETCOREID_IN		  1
	#define PLATFORM_GETSWITCHSTATE_IN	  0
	#define PLATFORM_GETMACADDR_IN		  1
	#define PLATFORM_GETPHYADDR_IN		  0
	#define PLATFORM_PHYLINKSTATUS_IN	  0
	#define PLATFORM_DELAY_IN			  1
	#define PLATFORM_LED_IN				  1
	#define PLATFORM_WRITE_IN			  0
	#define PLATFORM_READ_IN              0
	#define	PLATFORM_EXTMEMTEST_IN		  1
	#define	PLATFORM_I2C_EEPROM_IN	      1
	#define	PLATFORM_I2C_EEPROM_WRITE_IN  1
	#define	PLATFORM_UART_IN			  1
	#define	PLATFORM_NOR_IN				  1
	#define	PLATFORM_NOR_READ_IN		  1
	#define	PLATFORM_NOR_WRITE_IN		  0
	#define PLATFORM_NAND_IN			  1
	#define PLATFORM_NAND_READ_IN		  1
	#define PLATFORM_NAND_WRITE_IN		  0
    #define PLATFORM_NAND_ECC_IN          0
	#define PLATFORM_SEMLOCK_IN			  0
	#define PLATFORM_CACHE_IN			  0
	#define PLATFORM_GPIO_IN 			  1
	#define PLATFORM_I2C_IN 			  1
	#define PLATFORM_I2C_IO_EXP_IN 		  1
	#define PLATFORM_AUDIO                1
	#define PLATFORM_AUDIO_ADC            1
	#define PLATFORM_AUDIO_DAC            1
	#define PLATFORM_AUDIO_DIR            1
    #define PLATFORM_MMCHS_IN             1
    #define PLATFORM_DSS_IN               0
	#define PLATFORM_DCAN_IN              0
    #define PLATFORM_QSPI_FLASH_IN        1
    #define PLATFORM_QSPI_FLASH_READ_IN   1
    #define PLATFORM_QSPI_FLASH_WRITE_IN  1
#else
	/*
	 * Build the FULL version of Platform Library
	 */
	#define	PLATFORM_VERSTRING_IN		  1
	#define	PLATFORM_INIT_IN			  1
	#define	PLATFORM_GETINFO_IN			  1
	#define PLATFORM_GETCOREID_IN		  1
	#define PLATFORM_GETSWITCHSTATE_IN	  1
	#define PLATFORM_GETMACADDR_IN		  1
	#define PLATFORM_GETPHYADDR_IN		  1
	#define PLATFORM_PHYLINKSTATUS_IN	  1
	#define PLATFORM_DELAY_IN			  1
	#define PLATFORM_LED_IN				  1
	#define PLATFORM_WRITE_IN			  1
	#define PLATFORM_READ_IN              1
	#define	PLATFORM_EXTMEMTEST_IN		  1
	#define	PLATFORM_I2C_EEPROM_WRITE_IN  1
	#define	PLATFORM_I2C_EEPROM_IN		  1
	#define	PLATFORM_UART_IN			  1
	#define	PLATFORM_NOR_IN				  1
	#define	PLATFORM_NOR_READ_IN		  1
	#define	PLATFORM_NOR_WRITE_IN		  1
	#define PLATFORM_NAND_IN			  1
	#define PLATFORM_NAND_READ_IN		  1
	#define PLATFORM_NAND_WRITE_IN		  1
    #define PLATFORM_NAND_ECC_IN          0
	#define PLATFORM_SEMLOCK_IN			  1
	#define PLATFORM_CACHE_IN			  1
	#define PLATFORM_GPIO_IN 			  1
	#define PLATFORM_I2C_IN 			  1
	#define PLATFORM_I2C_IO_EXP_IN 		  1
	#define PLATFORM_AUDIO                1
	#define PLATFORM_AUDIO_ADC            1
	#define PLATFORM_AUDIO_DAC            1
	#define PLATFORM_AUDIO_DIR            1
    #define PLATFORM_MMCHS_IN             1
    #define PLATFORM_DSS_IN               1
	#define PLATFORM_DCAN_IN              1
    #define PLATFORM_QSPI_FLASH_IN        1
    #define PLATFORM_QSPI_FLASH_READ_IN   1
    #define PLATFORM_QSPI_FLASH_WRITE_IN  1
#endif
#endif

#if (PLATFORM_DEBUG && !PLATFORM_WRITE_IN)
#error	You must enable PLATFORM_WRITE to turn on DEBUG
#endif

#if (PLATFORM_DEBUG)
#define IFPRINT(x)   (x)
#else
#define IFPRINT(x)
#endif

/* This flag implements a workaround to re-initialize PLL and DDR
   if DDR test after DDR initialization */
#undef PLATFORM_PLL_REINIT
#define PLL_REINIT_DDR3_TEST_START_ADDR (0x80000000)
#define PLL_REINIT_DDR3_TEST_END_ADDR   (PLL_REINIT_DDR3_TEST_START_ADDR + (128 *1024))

/********************************************************************************************
 * 					Includes for the Library Routines										*
 *******************************************************************************************/

#include "types.h"
#include "csl_types.h"
#include "soc.h"

#include "platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "csl_chip.h"
#include "csl_chipAux.h"
#include "csl_semAux.h"
#include "cslr_device.h"
#include "cslr_psc.h"
#include "csl_psc.h"
#include "cslr_gpmc.h"
#include "cslr_elm.h"
#include "cslr_i2c.h"
#include "csl_cpsw.h"
#include "csl_cpsgmii.h"
#include "csl_cpsgmiiAux.h"
#include "csl_mdio.h"
#include "csl_mdioAux.h"
#include "cslr_uart.h"
#include "csl_gpioAux.h"
#include "csl_pscAux.h"
#include "csl_bootcfg.h"
#include "csl_bootcfgAux.h"
#include "cslr_spi.h"
#include "csl_xmcAux.h"
#include "csl_serdes_ethernet.h"
#include "cslr_mmchs.h"
#include "cslr_dss.h"
#include "cslr_qspi.h"
#include "cslr_ecap.h"
#include "cslr_pwmss.h"
#include "cslr_mlb.h"

#include "evmc66x_gpio.h"
#include "evmc66x_i2c.h"
#include "evmc66x_i2c_eeprom.h"
#include "evmc66x_elm.h"
#include "evmc66x_spi.h"
#include "evmc66x_pllc.h"
#include "evmc66x_gpmc.h"
#include "evmc66x_nand_gpmc.h"
#include "evmc66x_nand.h"
#include "evmc66x_nor.h"
#include "evmc66x_qspi.h"
#include "evmc66x_pinmux.h"
#include "evmc66x_qspi_norflash.h"
#if 0
#include "evmc66x_uart.h"
#include "evmc66x_gpio.h"
#include "evmc66x_bmc.h"
#include "evmc66x_gpmc.h"
#include "evmc66x_elm.h"
#include "evmc66x_spi.h"
#include "evmc66x_pllc.h"
#include "evmc66x_i2c_eeprom.h"
#include "evmc66x_i2c_ioexpander.h"
#include "evmc66x_nand_gpmc.h"
#include "evmc66x_nand.h"
#include "evmc66x_nor.h"
#include "evmc66x_audio_dc_dac.h"
#include "evmc66x_audio_dc_adc.h"
#include "evmc66x_mmchs.h"
#include "evmc66x_mmchs_card.h"
#include "evmc66x_dcan.h"
#include "evmc66x_dss.h"
#include "evmc66x_dss_panel.h"
#include "evmc66x_hdmi_panel.h"
#include "evmc66x_qspi.h"
#include "evmc66x_hdmi.h"
#include "evmc66x_touch.h"
#include "evmc66x_pinmux.h"
#include "platform_audio.h"
#include "evmc66x_qspi_norflash.h"
#include "evmc66x_pwm.h"
#endif

/********************************************************************************************
 * 					Platform Specific Declarations											*
 *******************************************************************************************/

#define PLATFORM_INFO_CPU_NAME 		"TCI66AK2G02"
#define PLATFORM_INFO_BOARD_NAME 	"TMDXEVM66AK2G02"

#define MEGM_REV_ID_REGISTER   (0x01812000)
#define MEGM_REV_ID_MAJ_MASK   (0xFFFF0000)
#define MEGM_REV_ID_MAJ_SHIFT  (16)
#define MEGM_REV_ID_MIN_MASK   (0x0000FFFF)
#define MEGM_REV_ID_MIN_SHIFT  (0)

/* Default UART baudrate value */
#define  PLATFORM_UART_BAUDRATE_val (19200)

/* LED Definitions */
#define PLATFORM_BMC_LED_COUNT   (4)
#define PLATFORM_SOC_LED_COUNT   (5)
#define PLATFORM_I2C_LED_COUNT   (0)
#define PLATFORM_TOTAL_LED_COUNT (PLATFORM_BMC_LED_COUNT + \
                                  PLATFORM_I2C_LED_COUNT + \
                                  PLATFORM_SOC_LED_COUNT)

#define PLATFORM_SOC_LED0        (0)
#define PLATFORM_SOC_LED1        (1)
#define PLATFORM_SOC_LED2        (2)
#define PLATFORM_SOC_LED3        (3)
#define PLATFORM_SOC_LED4        (4)

#define SOC_LED0_GPIO            (GPIO_PIN_108)
#define SOC_LED1_GPIO            (GPIO_PIN_11)
#define SOC_LED0_PADCONFIG       (139)
#define SOC_LED1_PADCONFIG       (186)

/* Number of cores on the platform */
#define PLATFORM_CORE_COUNT      (1)

/* Memory Sections */
#define PLATFORM_L1P_BASE_ADDRESS (CSL_C66X_COREPAC_0_L1P_SRAM_REGS)
#define PLATFORM_L1P_SIZE         (CSL_C66X_COREPAC_0_L1P_SRAM_REGS_SIZE)    /* 32K bytes */
#define PLATFORM_L1D_BASE_ADDRESS (CSL_GEM_INTERNAL_DSP0_L1D_SRAM_RAM_REGS)
#define PLATFORM_L1D_SIZE         (CSL_GEM_INTERNAL_DSP0_L1D_SRAM_RAM_REGS_SIZE)    /* 32K bytes */
#define PLATFORM_DDR3_SDRAM_START 0x80000000
#define PLATFORM_DDR3_SDRAM_END   0x9FFFFFFF /* DDR3A 1024 MB*/

/* AT24CM01 EEPROM */
#define PLATFORM_I2C_EEPROM_MANUFACTURER_ID (0x01)
#define PLATFORM_I2C_EEPROM_DEVICE_ID_1     (0x50)
#define PLATFORM_I2C_EEPROM_DEVICE_ID_2     (0x51)

/* UART port number for sending debug messages */
/* Set to UART_PORT_0 for DB9 connector and UART_PORT_2 for console header */
#define PLATFORM_UART_DBG_PORT    (UART_PORT_0)

/********************************************************************************************
 * 					General Declarations													*
 *******************************************************************************************/

/* Macro to calclate the size of default register Array */
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

/* Size of a string we can output with platform_write */
#define	MAX_WRITE_LEN	200

/* Device Tables */
#if (PLATFORM_NAND_IN)
extern PLATFORM_DEVICE_info gDeviceNand;
#endif

#if (PLATFORM_NOR_IN)
extern  PLATFORM_DEVICE_info gDeviceNor;
#endif

#if (PLATFORM_I2C_EEPROM_IN)
extern PLATFORM_DEVICE_info gDeviceEeprom0;
extern PLATFORM_DEVICE_info gDeviceEeprom1;
#endif

#define PLATFORM_READ_DELAY   (30000000)

/**
 *  Handle to access PSC registers.
 */
#define hPscCfg     ((CSL_PscRegs*)CSL_PSC_REGS)

/* Boot Cfg Registers */
#define   DEVSTAT_REG           (*((volatile uint32_t *) 0x02620020))

#define MAX_SN_SIZE             (10)      /* Maximum number of the chars of Serial Number for the EVM */
#define MAX_SN_STORE_SIZE       (128)     /* Maximum size in bytes to store the serial number info */

/* Size of MAC address in EEPROM at slave address 0x51 */
#define MACADDRESS_SIZE			(12)
/* Offset of MAC address in EEPROM at slave address 0x51 */
#define MAC_OFFSET				(0xF400)

/* Registers to enable or disable memory ECC for L1, L2 and MSMC memories */
#define L1PEDSTAT	(0x01846404)
#define L1PEDCMD	(0x01846408)
#define L1PEDADDR	(0x0184640C)
#define L2EDSTAT	(0x01846004)
#define L2EDCMD		(0x01846008)
#define L2EDADDR	(0x0184600C)
#define L2EDCPEC	(0x01846018)
#define L2EDCNEC	(0x0184601C)
#define L2EDCEN		(0x01846030)
#define SMCERRAR	(0x0BC00008)
#define	SMCERRXR	(0x0BC0000C)
#define SMEDCC		(0x0BC00010)
#define SMCEA		(0x0BC00014)
#define SMSECC		(0x0BC00018)

#define DDR_CFG_DELAY    (200)

/* DDR3A definitions */
#define DDR3A_EMIF_CTRL_BASE		(0x21010000)
#define DDR3A_EMIF_DATA_BASE		(0x80000000)
#define DDR3A_DDRPHYC				(0x02329000)


#define DDRPHY_PIR_OFFSET			(0x04)
#define DDRPHY_PGCR0_OFFSET			(0x08)
#define DDRPHY_PGCR1_OFFSET			(0x0C)
#define DDRPHY_PGSR0_OFFSET			(0x10)
#define DDRPHY_PGSR1_OFFSET			(0x14)
#define DDRPHY_PLLCR_OFFSET			(0x18)
#define DDRPHY_PTR0_OFFSET			(0x1C)
#define DDRPHY_PTR1_OFFSET			(0x20)
#define DDRPHY_PTR2_OFFSET			(0x24)
#define DDRPHY_PTR3_OFFSET			(0x28)
#define DDRPHY_PTR4_OFFSET			(0x2C)
#define DDRPHY_DCR_OFFSET			(0x44)

#define DDRPHY_DTPR0_OFFSET			(0x48)
#define DDRPHY_DTPR1_OFFSET			(0x4C)
#define DDRPHY_DTPR2_OFFSET			(0x50)

#define DDRPHY_MR0_OFFSET			(0x54)
#define DDRPHY_MR1_OFFSET			(0x58)
#define DDRPHY_MR2_OFFSET			(0x5C)
#define DDRPHY_DTCR_OFFSET			(0x68)
#define DDRPHY_PGCR2_OFFSET			(0x8C)

#define DDRPHY_ZQ0CR1_OFFSET		(0x184)
#define DDRPHY_ZQ1CR1_OFFSET  		(0x194)
#define DDRPHY_ZQ2CR1_OFFSET		(0x1A4)
#define DDRPHY_ZQ3CR1_OFFSET		(0x1B4)

#define DDRPHY_DATX8_4_OFFSET 		(0x2C0)
#define DDRPHY_DATX8_5_OFFSET 		(0x300)
#define DDRPHY_DATX8_6_OFFSET 		(0x340)
#define DDRPHY_DATX8_7_OFFSET 		(0x380)
#define DDRPHY_DATX8_8_OFFSET 		(0x3C0)

#define DDR3_MIDR_OFFSET		(0x00)
#define DDR3_STATUS_OFFSET		(0x04)
#define DDR3_SDCFG_OFFSET		(0x08)
#define DDR3_SDRFC_OFFSET		(0x10)
#define DDR3_SDTIM1_OFFSET		(0x18)
#define DDR3_SDTIM2_OFFSET		(0x1C)
#define DDR3_SDTIM3_OFFSET		(0x20)
#define DDR3_SDTIM4_OFFSET		(0x28)
#define DDR3_PMCTL_OFFSET		(0x38)
#define DDR3_ZQCFG_OFFSET		(0xC8)
#define DDR3_TMPALRT_OFFSET     (0xCC)
#define DDR3_DDRPHYC_OFFSET     (0xE4)
#define DDR3_ECC_CTRL_OFFSET    (0x110)


#define IODDRM_MASK            (0x00000180)
#define ZCKSEL_MASK            (0x01800000)
#define CL_MASK				   (0x00000072)
#define WR_MASK				   (0x00000E00)
#define BL_MASK				   (0x00000003)
#define RRMODE_MASK            (0x00040000)
#define UDIMM_MASK             (0x20000000)
#define BYTEMASK_MASK          (0x0000FC00)
#define MPRDQ_MASK             (0x00000080)
#define PDQ_MASK               (0x00000070)
#define NOSRA_MASK             (0x08000000)
#define ECC_MASK               (0x00000001)

typedef struct ddr3_phy_config {
	uint32_t pllcr;
	uint32_t pgcr1_mask;
	uint32_t pgcr1_val;
	uint32_t ptr0;
	uint32_t ptr1;
	uint32_t ptr2;
	uint32_t ptr3;
	uint32_t ptr4;
	uint32_t dcr_mask;
	uint32_t dcr_val;
	uint32_t dtpr0;
	uint32_t dtpr1;
	uint32_t dtpr2;
	uint32_t mr0;
	uint32_t mr1;
	uint32_t mr2;
	uint32_t dtcr;
	uint32_t pgcr2;
	uint32_t zq0cr1;
	uint32_t zq1cr1;
	uint32_t zq2cr1;
	uint32_t pir_v1;
	uint32_t pir_v2;
	uint32_t ecc_ctl;
} ddr3_phy_config;

typedef struct ddr3_emif_config {
	uint32_t sdcfg;
	uint32_t sdtim1;
	uint32_t sdtim2;
	uint32_t sdtim3;
	uint32_t sdtim4;
	uint32_t zqcfg;
	uint32_t sdrfc;
} ddr3_emif_config;

#define read_reg(a)          (*(volatile uint32_t *)(a))
#define write_reg(v,a)       (*(volatile uint32_t *)(a) = (v))


/********************************************************************************************
 * 					Function Prototypes														*
 *******************************************************************************************/
#if (PLATFORM_SEMLOCK_IN)
#define PLIBSPILOCK() Osal_platformSpiCsEnter();
#define PLIBSPIRELEASE() Osal_platformSpiCsExit ();
#else
#define PLIBSPILOCK()
#define PLIBSPIRELEASE()
#endif

/* Function prototypes that don't live anywhere else */
extern void configSerdes();
extern void Init_SGMII(uint32_t macport);
extern void PowerUpDomains (void);
extern void xmc_setup();

CSL_Status  DDR3Init(void);
int32_t readSPD(uint8_t uchEepromI2cAddress,uint8_t buf[],uint8_t i2cportnumber);
int32_t init_ddr3param(uint8_t*);

#ifdef __cplusplus
}
#endif

#endif /* _PLATFORM_INTERNAL_H_ */
