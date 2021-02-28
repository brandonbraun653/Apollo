/********************************************************************************
 *  File Name:
 *    reg_cm_rtc.hpp
 *
 *  Description:
 *    RTC clock module register definitions
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_CM_CEFUSE_HPP
#define APOLLO_REG_DEF_CM_CEFUSE_HPP

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
  RTC Registers
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_CEFUSE.StartAddress + 0x00, 0xFFFFFFFF, 0x00000000, 0>
      CM_CEFUSE_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_CEFUSE.StartAddress + 0x20, 0xFFFFFFFF, 0x00000000, 0>
      CM_CEFUSE_CEFUSE_CLKCTRL;
}    // namespace Apollo::REG

#endif /* !APOLLO_REG_DEF_CM_CEFUSE_HPP */
