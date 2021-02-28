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

/* STL Includes */
#include <cstdint>

/* Chimera Includes */
#include <Chimera/utility>

namespace Apollo::MEM
{
  /*-------------------------------------------------------------------------------
  L3 Memory Map
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x00000000, 0x1FFFFFFF> L3_GPMC_RANGE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x40000000, 0x4001FFFF> L3_BOOT_ROM;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x402F0400, 0x402FFFFF> L3_SRAM_INTERNAL;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x40300000, 0x4030FFFF> L3_OCMC0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44000000, 0x443FFFFF> L3_FCFG;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44800000, 0x44BFFFFF> L3_SCFG;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x46000000, 0x463FFFFF> L3_MCASP0_DATA;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x46400000, 0x467FFFFF> L3_MCASP1_DATA;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47400000, 0x47400FFF> L3_USBSS;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47401000, 0x474012FF> L3_USB0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47401300, 0x474013FF> L3_USB0_PHY;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47401400, 0x474017FF> L3_USB0_CORE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47401800, 0x47401AFF> L3_USB1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47401B00, 0x47401BFF> L3_USB1_PHY;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47401C00, 0x47401FFF> L3_USB1_CORE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47402000, 0x47402FFF> L3_USB_CPPI_DMA_CONTROLLER;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47403000, 0x47403FFF> L3_USB_CPPI_DMA_SCHEDULER;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47404000, 0x47407FFF> L3_USB_QUEUE_MANAGER;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x47810000, 0x4781FFFF> L3_MMCHS2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x49000000, 0x490FFFFF> L3_TPCC;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x49800000, 0x498FFFFF> L3_TPTC0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x49900000, 0x499FFFFF> L3_TPTC1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x49A00000, 0x49AFFFFF> L3_TPTC2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4B140000, 0x4B140FFF> L3_DEBUG_SS_ETM;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4B141000, 0x4B141FFF> L3_DEBUG_SS_DBG;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4B142000, 0x4B142FFF> L3_DEBUG_SS_CTI;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4B143000, 0x4B143FFF> L3_DEBUG_SS_ICE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4B160000, 0x4B160FFF> L3_DEBUG_SS_DRM;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4B162000, 0x4B162FFF> L3_DEBUG_SS_ETB;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4C000000, 0x4CFFFFFF> L3_EMIF0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x50000000, 0x50FFFFFF> L3_GPMC_CFG;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x54C00000, 0x54FFFFFF> L3_ADC_TSC_DMA;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x56000000, 0x56FFFFFF> L3_SGX530;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x80000000, 0xBFFFFFFF> L3_EMIF0_RANGE;

  /*-------------------------------------------------------------------------------
  L4 Wakeup Region
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44C00000, 0x44C007FF> L4_WKUP_RGN_AP;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44C00800, 0x44C00FFF> L4_WKUP_RGN_LA;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44C01000, 0x44C013FF> L4_WKUP_RGN_IP0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44C01400, 0x44C017FF> L4_WKUP_RGN_IP1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00000, 0x44E003FF> L4_CM_PER;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00400, 0x44E004FF> L4_CM_WKUP;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00500, 0x44E005FF> L4_CM_DPLL;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00600, 0x44E006FF> L4_CM_MPU;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00700, 0x44E007FF> L4_CM_DEVICE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00800, 0x44E008FF> L4_CM_RTC;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00900, 0x44E009FF> L4_CM_GFX;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00A00, 0x44E00AFF> L4_CM_CEFUSE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00B00, 0x44E00BFF> L4_PRM_IRQ;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00C00, 0x44E00CFF> L4_PRM_PER;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00D00, 0x44E00DFF> L4_PRM_WKUP;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00E00, 0x44E00EFF> L4_PRM_MPU;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E00F00, 0x44E00FFF> L4_PRM_DEV;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E01000, 0x44E010FF> L4_PRM_RTC;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E01100, 0x44E011FF> L4_PRM_GFX;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E01200, 0x44E012FF> L4_PRM_CEFUSE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E05000, 0x44E05FFF> L4_DMTIMER0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E07000, 0x44E07FFF> L4_GPIO0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E09000, 0x44E09FFF> L4_UART0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E0B000, 0x44E0BFFF> L4_I2C0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E0D000, 0x44E0EFFF> L4_ADC_TSC;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E10000, 0x44E11FFF> L4_CONTROL_MODULE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E12000, 0x44E123FF> L4_DDR_PHY;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E31000, 0x44E31FFF> L4_DMTIMER1_1MS;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E35000, 0x44E35FFF> L4_WDT1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E37000, 0x44E37FFF> L4_SMART_REFLEX0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E39000, 0x44E39FFF> L4_SMART_REFLEX1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E3E000, 0x44E3EFFF> L4_RTCSS;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x44E40000, 0x44E7FFFF> L4_DEBUG_SS;

  /*-------------------------------------------------------------------------------
  L4 Peripheral Memory
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48022000, 0x48022FFF> L4_UART1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48024000, 0x48024FFF> L4_UART2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4802A000, 0x4802AFFF> L4_I2C1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48030000, 0x48030FFF> L4_MCSPI0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48038000, 0x48039FFF> L4_MCASP0_CFG;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4803C000, 0x4803DFFF> L4_MCASP1_CFG;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48040000, 0x48040FFF> L4_DMTIMER2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48042000, 0x48042FFF> L4_DMTIMER3;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48044000, 0x48044FFF> L4_DMTIMER4;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48046000, 0x48046FFF> L4_DMTIMER5;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48048000, 0x48048FFF> L4_DMTIMER6;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4804A000, 0x4804AFFF> L4_DMTIMER7;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4804C000, 0x4804CFFF> L4_GPIO1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48060000, 0x48060FFF> L4_MMCHS0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48080000, 0x4808FFFF> L4_ELM;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x480C8000, 0x480C8FFF> L4_MAILBOX_0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x480CA000, 0x480CAFFF> L4_SPINLOCK;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4818C000, 0x4818CFFF> L4_OCP_WATCHPOINT;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4819C000, 0x4819CFFF> L4_I2C2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481A0000, 0x481A0FFF> L4_MCSPI1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481A6000, 0x481A6FFF> L4_UART3;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481A8000, 0x481A8FFF> L4_UART4;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481AA000, 0x481AAFFF> L4_UART5;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481AC000, 0x481ACFFF> L4_GPIO2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481AE000, 0x481AEFFF> L4_GPIO3;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481CC000, 0x481CDFFF> L4_DCAN0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481D0000, 0x481D1FFF> L4_DCAN1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x481D8000, 0x481D8FFF> L4_MMC1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48200000, 0x48200FFF> L4_INTC;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48240000, 0x48240FFF> L4_MPUSS_CFG;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48300000, 0x483000FF> L4_PWM_SS0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48300100, 0x4830017F> L4_ECAP0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48300180, 0x483001FF> L4_EQEP0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48300200, 0x4830025F> L4_EPWM0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48302000, 0x483020FF> L4_PWM_SS1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48302100, 0x4830217F> L4_ECAP1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48302180, 0x483021FF> L4_EQEP1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48302200, 0x4830225F> L4_EPWM1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48304000, 0x483040FF> L4_PWM_SS2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48304100, 0x4830417F> L4_ECAP2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48304180, 0x483041FF> L4_EQEP2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x48304200, 0x4830425F> L4_EPWM2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4830E000, 0x4830EFFF> L4_LCD_CONTROLLER;

  /*-------------------------------------------------------------------------------
  L4 Fast Peripheral Memory
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A000000, 0x4A0007FF> L4_FAST_CFG_AP;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A000800, 0x4A000FFF> L4_FAST_CFG_LA;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A001000, 0x4A0013FF> L4_FAST_CFG_IP0;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A001800, 0x4A001FFF> L4_FAST_CFG_IP2_3;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100000, 0x4A107FFF> L4_CPSW_SS;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100100, 0x4A1007FF> L4_CPSW_PORT;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100800, 0x4A1008FF> L4_CPSW_CPDMA;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100900, 0x4A1009FF> L4_CPSW_STATS;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100A00, 0x4A100BFF> L4_CPSW_STATERAM;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100C00, 0x4A100CFF> L4_CPSW_CPTS;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100D00, 0x4A100D7F> L4_CPSW_ALE;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100D80, 0x4A100DBF> L4_CPSW_SL1;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A100DC0, 0x4A100DFF> L4_CPSW_SL2;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A101000, 0x4A1010FF> L4_MDIO;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A101200, 0x4A101FFF> L4_CPSW_WR;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A102000, 0x4A103FFF> L4_CPPI_RAM;
  static constexpr Chimera::Gen::MemRegion<uint32_t, 0x4A300000, 0x4A37FFFF> L4_PRU_ICSS;

}    // namespace Apollo::MEM

#endif /* !APOLLO_MEMORY_MAP_PERIPHERALS_HPP */
