/********************************************************************************
 *  File Name:
 *    reg_cm_per.hpp
 *
 *  Description:
 *    Register definitions for CM_PER_XXXX
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_CM_PER_HPP
#define APOLLO_REG_DEF_CM_PER_HPP

/* STL Includes */
#include <cstdint>

/* Apollo Includes */
#include <Apollo/src/mem/mem_map.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/utility>

namespace Apollo::REG
{
  /*-------------------------------------------------------------------------------
  Clock Module Peripheral Registers
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x000, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L4LS_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x004, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L3S_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x00C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L3_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x014, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_CPGMAC0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x018, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_LCDC_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x01C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_USB0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x024, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TPTC0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x028, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_EMIF_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x02C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_OCMCRAM_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x030, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_GPMC_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x034, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_MCASP0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x038, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_UART5_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x03C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_MMC0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x040, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_ELM_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x044, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_I2C2_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x048, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_I2C1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x04C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_SPI0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x050, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_SPI1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x060, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L4LS_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x068, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_MCASP1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x06C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_UART1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x070, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_UART2_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x074, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_UART3_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x078, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_UART4_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x07C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TIMER7_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x080, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TIMER2_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x084, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TIMER3_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x088, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TIMER4_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0AC, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_GPIO1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0B0, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_GPIO2_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0B4, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_GPIO3_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0BC, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TPCC_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0C0, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_DCAN0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0C4, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_DCAN1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0CC, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_EPWMSS1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0D4, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_EPWMSS0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0D8, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_EPWMSS2_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0DC, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L3_INSTR_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0E0, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L3_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0E4, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_IEEE5000_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0E8, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_PRU_ICSS_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0EC, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TIMER5_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0F0, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TIMER6_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0F4, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_MMC1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0F8, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_MMC2_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x0FC, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TPTC1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x100, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_TPTC2_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x10C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_SPINLOCK_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x110, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_MAILBOX0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x11C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L4HS_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x120, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_L4HS_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x12C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_OCPWP_L3_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x130, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_OCPWP_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x140, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_PRU_ICSS_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x144, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_CPSW_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x148, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_LCDC_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x14C, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_CLKDIV32K_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_PER.StartAddress + 0x150, 0xFFFFFFFF, 0x00000000, 0>
      CM_PER_CLK_24MHZ_CLKSTCTRL;
}    // namespace Apollo::REG

#endif /* !APOLLO_REG_DEF_CM_PER_HPP */
