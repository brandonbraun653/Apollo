/********************************************************************************
 *  File Name:
 *    reg_cm_wkup.hpp
 *
 *  Description:
 *    Wakeup region register definitions
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_CM_WKUP_HPP
#define APOLLO_REG_DEF_CM_WKUP_HPP

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
  Clock Module Wakeup Registers
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x00, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x04, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_CONTROL_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x08, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_GPIO0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x0C, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_L4WKUP_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x10, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_TIMER0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x14, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_DEBUGSS_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x18, 0xFFFFFFFF, 0x00000000, 0>
      CM_L3_AON_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x1C, 0xFFFFFFFF, 0x00000000, 0>
      CM_AUTOIDLE_DPLL_MPU;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x20, 0xFFFFFFFF, 0x00000000, 0>
      CM_IDLEST_DPLL_MPU;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x24, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_DELTAMSTEP_DPLL_MPU;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x28, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_MODFREQDIV_DPLL_MPU;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x2C, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKSEL_DPLL_MPU;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x30, 0xFFFFFFFF, 0x00000000, 0>
      CM_AUTOIDLE_DPLL_DDR;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x34, 0xFFFFFFFF, 0x00000000, 0>
      CM_IDLEST_DPLL_DDR;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x38, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_DELTAMSTEP_DPLL_DDR;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x3C, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_MODFREQDIV_DPLL_DDR;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x40, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKSEL_DPLL_DDR;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x44, 0xFFFFFFFF, 0x00000000, 0>
      CM_AUTOIDLE_DPLL_DISP;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x48, 0xFFFFFFFF, 0x00000000, 0>
      CM_IDLEST_DPLL_DISP;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x4C, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_DELTAMSTEP_DPLL_DISP;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x50, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_MODFREQDIV_DPLL_DISP;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x54, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKSEL_DPLL_DISP;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x58, 0xFFFFFFFF, 0x00000000, 0>
      CM_AUTOIDLE_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x5C, 0xFFFFFFFF, 0x00000000, 0>
      CM_IDLEST_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x60, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_DELTAMSTEP_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x64, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_MODFREQDIV_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x68, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKSEL_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x6C, 0xFFFFFFFF, 0x00000000, 0>
      CM_AUTOIDLE_DPLL_PER;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x70, 0xFFFFFFFF, 0x00000000, 0>
      CM_IDLEST_DPLL_PER;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x74, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_DELTAMSTEP_DPLL_PER;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x78, 0xFFFFFFFF, 0x00000000, 0>
      CM_SSC_MODFREQDIV_DPLL_PER;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x7C, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKDCOLDO_DPLL_PER;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x80, 0xFFFFFFFF, 0x00000000, 0>
      CM_DIV_M4_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x84, 0xFFFFFFFF, 0x00000000, 0>
      CM_DIV_M5_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x88, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKMODE_DPLL_MPU;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x8C, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKMODE_DPLL_PER;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x90, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKMODE_DPLL_CORE;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x94, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKMODE_DPLL_DDR;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x98, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKMODE_DPLL_DISP;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0x9C, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKSEL_DPLL_PERIPH;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xA0, 0xFFFFFFFF, 0x00000000, 0>
      CM_DIV_M2_DPLL_DDR;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xA4, 0xFFFFFFFF, 0x00000000, 0>
      CM_DIV_M2_DPLL_DISP;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xA8, 0xFFFFFFFF, 0x00000000, 0>
      CM_DIV_M2_DPLL_MPU;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xAC, 0xFFFFFFFF, 0x00000000, 0>
      CM_DIV_M2_DPLL_PER;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xB0, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_WKUP_M3_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xB4, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_UART0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xB8, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_I2C0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xBC, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_ADC_TSC_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xC0, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_SMARTREFLEX0_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xC4, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_TIMER1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xC8, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_SMARTREFLEX1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xCC, 0xFFFFFFFF, 0x00000000, 0>
      CM_L4_WKUP_AON_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xD4, 0xFFFFFFFF, 0x00000000, 0>
      CM_WKUP_WDT1_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_WKUP.StartAddress + 0xD8, 0xFFFFFFFF, 0x00000000, 0>
      CM_DIV_M6_DPLL_CORE;

}    // namespace Apollo::REG

#endif /* !APOLLO_REG_DEF_CM_WKUP_HPP */
