/********************************************************************************
 *  File Name:
 *    reg_cm_dpll.hpp
 *
 *  Description:
 *    MPU register definitions
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_CM_MPU_HPP
#define APOLLO_REG_DEF_CM_MPU_HPP

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
  MPU Registers
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_MPU.StartAddress + 0x00, 0xFFFFFFFF, 0x00000000, 0>
      CM_MPU_CLKSTCTRL;
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_MPU.StartAddress + 0x04, 0xFFFFFFFF, 0x00000000, 0>
      CM_MPU_MPU_CLKCTRL;
}    // namespace Apollo::REG

#endif /* !APOLLO_REG_DEF_CM_MPU_HPP */
