/********************************************************************************
 *  File Name:
 *    reg_cm_dpll.hpp
 *
 *  Description:
 *    PLL register definitions
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_CM_DPLL_HPP
#define APOLLO_REG_DEF_CM_DPLL_HPP

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
  DPLL Registers
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x04, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_TIMER7_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x08, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_TIMER2_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x0C, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_TIMER3_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x10, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_TIMER4_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x14, 0xFFFFFFFF, 0x00000000, 0>
      CM_MAC_CLKSEL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x18, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_TIMER5_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x1C, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_TIMER6_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x20, 0xFFFFFFFF, 0x00000000, 0>
      CM_CPTS_RFT_CLKSEL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x28, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_TIMER1MS_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x2C, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_GFX_FCLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x30, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_PRU_ICSS_OCP_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x34, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_LCDC_PIXEL_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x38, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_WDT1_CLK;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DPLL.StartAddress + 0x3C, 0xFFFFFFFF, 0x00000000, 0>
      CLKSEL_GPIO0_DBCLK;
}    // namespace Apollo::REG

#endif /* !APOLLO_REG_DEF_CM_DPLL_HPP */
