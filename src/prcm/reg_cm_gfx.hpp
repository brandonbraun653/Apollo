/********************************************************************************
 *  File Name:
 *    reg_cm_gfx.hpp
 *
 *  Description:
 *    GFX clock module register definitions
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_CM_GFX_HPP
#define APOLLO_REG_DEF_CM_GFX_HPP

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
  GFX Registers
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_GFX.StartAddress + 0x00, 0xFFFFFFFF, 0x00000000, 0>
      CM_GFX_L3_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_GFX.StartAddress + 0x04, 0xFFFFFFFF, 0x00000000, 0>
      CM_GFX_GFX_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_GFX.StartAddress + 0x0C, 0xFFFFFFFF, 0x00000000, 0>
      CM_GFX_L4LS_GFX_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_GFX.StartAddress + 0x10, 0xFFFFFFFF, 0x00000000, 0>
      CM_GFX_MMUCFG_CLKCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_GFX.StartAddress + 0x14, 0xFFFFFFFF, 0x00000000, 0>
      CM_GFX_MMUDATA_CLKCTRL;
}    // namespace Apollo::REG

#endif /* !APOLLO_REG_DEF_CM_GFX_HPP */
