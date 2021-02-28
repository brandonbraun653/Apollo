/********************************************************************************
 *  File Name:
 *    reg_cm_dpll.hpp
 *
 *  Description:
 *    DEVICE clock module register definitions
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_CM_DEVICE_HPP
#define APOLLO_REG_DEF_CM_DEVICE_HPP

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
  DEVICE Registers
  -------------------------------------------------------------------------------*/
  static constexpr Chimera::Gen::RegAccess<uint32_t, MEM::L4_CM_DEVICE.StartAddress + 0x00, 0xFFFFFFFF, 0x00000000, 0>
      CM_CLKOUT_CTRL;
}    // namespace Apollo::REG

#endif /* !APOLLO_REG_DEF_CM_DEVICE_HPP */
