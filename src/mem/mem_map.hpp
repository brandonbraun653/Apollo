/********************************************************************************
 *  File Name:
 *    mem_map.hpp
 *
 *  Description:
 *    System level memory map of all peripherals
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_MEMORY_MAP_PERIPHERALS_HPP
#define APOLLO_MEMORY_MAP_PERIPHERALS_HPP

/* Chimera Includes */
#include <Chimera/utility>

namespace Apollo::MEM
{
  /*-------------------------------------------------------------------------------
  L3 Memory Map
  -------------------------------------------------------------------------------*/
  Chimera::Gen::MemRegion<0x00000000, 0x1FFFFFFF> L3_GPMC_RANGE;
  Chimera::Gen::MemRegion<0x40000000, 0x4001FFFF> L3_BOOT_ROM;
  Chimera::Gen::MemRegion<0x402F0400, 0x402FFFFF> L3_SRAM_INTERNAL;
  Chimera::Gen::MemRegion<0x40300000, 0x4030FFFF> L3_OCMC0;
  Chimera::Gen::MemRegion<0x44000000, 0x443FFFFF> L3_FCFG;
  Chimera::Gen::MemRegion<0x44800000, 0x44BFFFFF> L3_SCFG;
  Chimera::Gen::MemRegion<0x46000000, 0x463FFFFF> L3_MCASP0_DATA;
  Chimera::Gen::MemRegion<0x46400000, 0x467FFFFF> L3_MCASP1_DATA;
  Chimera::Gen::MemRegion<0x47400000, 0x47400FFF> L3_USBSS;
  Chimera::Gen::MemRegion<0x47401000, 0x474012FF> L3_USB0;
  Chimera::Gen::MemRegion<0x47401300, 0x474013FF> L3_USB0_PHY;
  Chimera::Gen::MemRegion<0x47401400, 0x474017FF> L3_USB0_CORE;
  Chimera::Gen::MemRegion<0x47401800, 0x47401AFF> L3_USB1;
  Chimera::Gen::MemRegion<0x47401B00, 0x47401BFF> L3_USB1_PHY;
  Chimera::Gen::MemRegion<0x47401C00, 0x47401FFF> L3_USB1_CORE;
  Chimera::Gen::MemRegion<0x47402000, 0x47402FFF> L3_USB_CPPI_DMA_CONTROLLER;
  Chimera::Gen::MemRegion<0x47403000, 0x47403FFF> L3_USB_CPPI_DMA_SCHEDULER;
  Chimera::Gen::MemRegion<0x47404000, 0x47407FFF> L3_USB_QUEUE_MANAGER;
  Chimera::Gen::MemRegion<0x47810000, 0x4781FFFF> L3_MMCHS2;
  Chimera::Gen::MemRegion<0x49000000, 0x490FFFFF> L3_TPCC;
  Chimera::Gen::MemRegion<0x49800000, 0x498FFFFF> L3_TPTC0;
  Chimera::Gen::MemRegion<0x49900000, 0x499FFFFF> L3_TPTC1;
  Chimera::Gen::MemRegion<0x49A00000, 0x49AFFFFF> L3_TPTC2;
  Chimera::Gen::MemRegion<0x4B140000, 0x4B140FFF> L3_DEBUG_SS_ETM;
  Chimera::Gen::MemRegion<0x4B141000, 0x4B141FFF> L3_DEBUG_SS_DBG;
  Chimera::Gen::MemRegion<0x4B142000, 0x4B142FFF> L3_DEBUG_SS_CTI;
  Chimera::Gen::MemRegion<0x4B143000, 0x4B143FFF> L3_DEBUG_SS_ICE;
  Chimera::Gen::MemRegion<0x4B160000, 0x4B160FFF> L3_DEBUG_SS_DRM;
  Chimera::Gen::MemRegion<0x4B162000, 0x4B162FFF> L3_DEBUG_SS_ETB;
  Chimera::Gen::MemRegion<0x4C000000, 0x4CFFFFFF> L3_EMIF0;
  Chimera::Gen::MemRegion<0x50000000, 0x50FFFFFF> L3_GPMC_CFG;
  Chimera::Gen::MemRegion<0x54C00000, 0x54FFFFFF> L3_ADC_TSC_DMA;
  Chimera::Gen::MemRegion<0x56000000, 0x56FFFFFF> L3_SGX530;
  Chimera::Gen::MemRegion<0x80000000, 0xBFFFFFFF> L3_EMIF0_RANGE;


  /*-------------------------------------------------------------------------------
  L4 Wakeup Region
  -------------------------------------------------------------------------------*/
  Chimera::Gen::MemRegion<0x44C00000, 0x44C007FF> L4_WKUP_RGN_AP;
  Chimera::Gen::MemRegion<0x44C00800, 0x44C00FFF> L4_WKUP_RGN_LA;
  Chimera::Gen::MemRegion<0x44C01000, 0x44C013FF> L4_WKUP_RGN_IP0;
  Chimera::Gen::MemRegion<0x44C01400, 0x44C017FF> L4_WKUP_RGN_IP1;
  Chimera::Gen::MemRegion<0x44E00000, 0x44E003FF> L4_CM_PER;
  Chimera::Gen::MemRegion<0x44E00400, 0x44E004FF> L4_CM_WKUP;
  Chimera::Gen::MemRegion<0x44E00500, 0x44E005FF> L4_CM_DPLL;
  Chimera::Gen::MemRegion<0x44E00600, 0x44E006FF> L4_CM_MPU;
  Chimera::Gen::MemRegion<0x44E00700, 0x44E007FF> L4_CM_DEVICE;
  Chimera::Gen::MemRegion<0x44E00800, 0x44E008FF> L4_CM_RTC;
  Chimera::Gen::MemRegion<0x44E00900, 0x44E009FF> L4_CM_GFX;
  Chimera::Gen::MemRegion<0x44E00A00, 0x44E00AFF> L4_CM_CEFUSE;
  Chimera::Gen::MemRegion<0x44E00B00, 0x44E00BFF> L4_PRM_IRQ;
  Chimera::Gen::MemRegion<0x44E00C00, 0x44E00CFF> L4_PRM_PER;
  Chimera::Gen::MemRegion<0x44E00D00, 0x44E00DFF> L4_PRM_WKUP;
  Chimera::Gen::MemRegion<0x44E00E00, 0x44E00EFF> L4_PRM_MPU;
  Chimera::Gen::MemRegion<0x44E00F00, 0x44E00FFF> L4_PRM_DEV;
  Chimera::Gen::MemRegion<0x44E01000, 0x44E010FF> L4_PRM_RTC;
  Chimera::Gen::MemRegion<0x44E01100, 0x44E011FF> L4_PRM_GFX;
  Chimera::Gen::MemRegion<0x44E01200, 0x44E012FF> L4_PRM_CEFUSE;
  Chimera::Gen::MemRegion<0x44E05000, 0x44E05FFF> L4_DMTIMER0;
  Chimera::Gen::MemRegion<0x44E07000, 0x44E07FFF> L4_GPIO0;
  Chimera::Gen::MemRegion<0x44E09000, 0x44E09FFF> L4_UART0;
  Chimera::Gen::MemRegion<0x44E0B000, 0x44E0BFFF> L4_I2C0;
  Chimera::Gen::MemRegion<0x44E0D000, 0x44E0EFFF> L4_ADC_TSC;
  Chimera::Gen::MemRegion<0x44E10000, 0x44E11FFF> L4_CONTROL_MODULE;
  Chimera::Gen::MemRegion<0x44E12000, 0x44E123FF> L4_DDR_PHY;
  Chimera::Gen::MemRegion<0x44E31000, 0x44E31FFF> L4_DMTIMER1_1MS;
  Chimera::Gen::MemRegion<0x44E35000, 0x44E35FFF> L4_WDT1;
  Chimera::Gen::MemRegion<0x44E37000, 0x44E37FFF> L4_SMART_REFLEX0;
  Chimera::Gen::MemRegion<0x44E39000, 0x44E39FFF> L4_SMART_REFLEX1;
  Chimera::Gen::MemRegion<0x44E3E000, 0x44E3EFFF> L4_RTCSS;
  Chimera::Gen::MemRegion<0x44E40000, 0x44E7FFFF> L4_DEBUG_SS;

  /*-------------------------------------------------------------------------------
  L4 Peripheral Memory
  -------------------------------------------------------------------------------*/
  Chimera::Gen::MemRegion<0x48022000, 0x48022FFF> L4_UART1;
  Chimera::Gen::MemRegion<0x48024000, 0x48024FFF> L4_UART2;
  Chimera::Gen::MemRegion<0x4802A000, 0x4802AFFF> L4_I2C1;
  Chimera::Gen::MemRegion<0x48030000, 0x48030FFF> L4_MCSPI0;
  Chimera::Gen::MemRegion<0x48038000, 0x48039FFF> L4_MCASP0_CFG;
  Chimera::Gen::MemRegion<0x4803C000, 0x4803DFFF> L4_MCASP1_CFG;
  Chimera::Gen::MemRegion<0x48040000, 0x48040FFF> L4_DMTIMER2;
  Chimera::Gen::MemRegion<0x48042000, 0x48042FFF> L4_DMTIMER3;
  Chimera::Gen::MemRegion<0x48044000, 0x48044FFF> L4_DMTIMER4;
  Chimera::Gen::MemRegion<0x48046000, 0x48046FFF> L4_DMTIMER5;
  Chimera::Gen::MemRegion<0x48048000, 0x48048FFF> L4_DMTIMER6;
  Chimera::Gen::MemRegion<0x4804A000, 0x4804AFFF> L4_DMTIMER7;
  Chimera::Gen::MemRegion<0x4804C000, 0x4804CFFF> L4_GPIO1;
  Chimera::Gen::MemRegion<0x48060000, 0x48060FFF> L4_MMCHS0;
  Chimera::Gen::MemRegion<0x48080000, 0x4808FFFF> L4_ELM;
  Chimera::Gen::MemRegion<0x480C8000, 0x480C8FFF> L4_MAILBOX_0;
  Chimera::Gen::MemRegion<0x480CA000, 0x480CAFFF> L4_SPINLOCK;
  Chimera::Gen::MemRegion<0x4818C000, 0x4818CFFF> L4_OCP_WATCHPOINT;
  Chimera::Gen::MemRegion<0x4819C000, 0x4819CFFF> L4_I2C2;
  Chimera::Gen::MemRegion<0x481A0000, 0x481A0FFF> L4_MCSPI1;
  Chimera::Gen::MemRegion<0x481A6000, 0x481A6FFF> L4_UART3;
  Chimera::Gen::MemRegion<0x481A8000, 0x481A8FFF> L4_UART4;
  Chimera::Gen::MemRegion<0x481AA000, 0x481AAFFF> L4_UART5;
  Chimera::Gen::MemRegion<0x481AC000, 0x481ACFFF> L4_GPIO2;
  Chimera::Gen::MemRegion<0x481AE000, 0x481AEFFF> L4_GPIO3;
  Chimera::Gen::MemRegion<0x481CC000, 0x481CDFFF> L4_DCAN0;
  Chimera::Gen::MemRegion<0x481D0000, 0x481D1FFF> L4_DCAN1;
  Chimera::Gen::MemRegion<0x481D8000, 0x481D8FFF> L4_MMC1;
  Chimera::Gen::MemRegion<0x48200000, 0x48200FFF> L4_INTC;
  Chimera::Gen::MemRegion<0x48240000, 0x48240FFF> L4_MPUSS_CFG;
  Chimera::Gen::MemRegion<0x48300000, 0x483000FF> L4_PWM_SS0;
  Chimera::Gen::MemRegion<0x48300100, 0x4830017F> L4_ECAP0;
  Chimera::Gen::MemRegion<0x48300180, 0x483001FF> L4_EQEP0;
  Chimera::Gen::MemRegion<0x48300200, 0x4830025F> L4_EPWM0;
  Chimera::Gen::MemRegion<0x48302000, 0x483020FF> L4_PWM_SS1;
  Chimera::Gen::MemRegion<0x48302100, 0x4830217F> L4_ECAP1;
  Chimera::Gen::MemRegion<0x48302180, 0x483021FF> L4_EQEP1;
  Chimera::Gen::MemRegion<0x48302200, 0x4830225F> L4_EPWM1;
  Chimera::Gen::MemRegion<0x48304000, 0x483040FF> L4_PWM_SS2;
  Chimera::Gen::MemRegion<0x48304100, 0x4830417F> L4_ECAP2;
  Chimera::Gen::MemRegion<0x48304180, 0x483041FF> L4_EQEP2;
  Chimera::Gen::MemRegion<0x48304200, 0x4830425F> L4_EPWM2;
  Chimera::Gen::MemRegion<0x4830E000, 0x4830EFFF> L4_LCD_CONTROLLER;

  /*-------------------------------------------------------------------------------
  L4 Fast Peripheral Memory
  -------------------------------------------------------------------------------*/
  Chimera::Gen::MemRegion<0x4A000000, 0x4A0007FF> L4_FAST_CFG_AP;
  Chimera::Gen::MemRegion<0x4A000800, 0x4A000FFF> L4_FAST_CFG_LA;
  Chimera::Gen::MemRegion<0x4A001000, 0x4A0013FF> L4_FAST_CFG_IP0;
  Chimera::Gen::MemRegion<0x4A001800, 0x4A001FFF> L4_FAST_CFG_IP2_3;
  Chimera::Gen::MemRegion<0x4A100000, 0x4A107FFF> L4_CPSW_SS;
  Chimera::Gen::MemRegion<0x4A100100, 0x4A1007FF> L4_CPSW_PORT;
  Chimera::Gen::MemRegion<0x4A100800, 0x4A1008FF> L4_CPSW_CPDMA;
  Chimera::Gen::MemRegion<0x4A100900, 0x4A1009FF> L4_CPSW_STATS;
  Chimera::Gen::MemRegion<0x4A100A00, 0x4A100BFF> L4_CPSW_STATERAM;
  Chimera::Gen::MemRegion<0x4A100C00, 0x4A100CFF> L4_CPSW_CPTS;
  Chimera::Gen::MemRegion<0x4A100D00, 0x4A100D7F> L4_CPSW_ALE;
  Chimera::Gen::MemRegion<0x4A100D80, 0x4A100DBF> L4_CPSW_SL1;
  Chimera::Gen::MemRegion<0x4A100DC0, 0x4A100DFF> L4_CPSW_SL2;
  Chimera::Gen::MemRegion<0x4A101000, 0x4A1010FF> L4_MDIO;
  Chimera::Gen::MemRegion<0x4A101200, 0x4A101FFF> L4_CPSW_WR;
  Chimera::Gen::MemRegion<0x4A102000, 0x4A103FFF> L4_CPPI_RAM;
  Chimera::Gen::MemRegion<0x4A300000, 0x4A37FFFF> L4_PRU_ICSS;

}    // namespace Apollo::MEM

#endif /* !APOLLO_MEMORY_MAP_PERIPHERALS_HPP */
