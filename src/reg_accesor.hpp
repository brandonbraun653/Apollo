/********************************************************************************
 *  File Name:
 *    reg_accesor.hpp
 *
 *  Description:
 *    Register accessor helper tools
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_ACCESSOR_HPP
#define APOLLO_REG_ACCESSOR_HPP

#include <cstdint>
#include <cstddef>
#include <limits>

#define __IO volatile

namespace Apollo::Register
{
  template<typename T, const size_t addr, const size_t mask = std::numeric_limits<T>::max(),
           const size_t reset = 0, const size_t offset = 0>
  class RegDecl
  {
  public:
    static constexpr __IO T *_accessor = static_cast<__IO T *>( addr );
    static constexpr T _address        = addr;
    static constexpr T _bitOffset      = offset; /**< Starting bit position for this field */
    static constexpr T _bitMask        = mask;   /**< Bit mask for this field */
    static constexpr T _resetValue     = reset;  /**< Value of the field upon reset */
  };

  template<typename T, const size_t addr, const size_t mask = std::numeric_limits<T>::max(),
           const size_t reset = 0, const size_t offset = 0>
  struct RegAccess : public RegDecl<T, addr, mask, reset, offset>
  {
    static_assert( addr != 0 );

    /*-------------------------------------------------------------------------------
    Public Functions
    -------------------------------------------------------------------------------*/
    inline T read() const
    {
      return ( *_accessor ) & _bitMask;
    }

    inline void write( const T val )
    {
      *_accessor = val & _bitMask;
    }

    inline void shiftedWrite( const T val )
    {
      *_accessor = ( val << _bitOffset ) & _bitMask;
    }

    inline void update( const T val )
    {

    }
  };


  template<typename Base, const size_t mask = std::numeric_limits<decltype( Base::address )>::max(), const size_t reset = 0,
           const size_t offset = 0>
  struct FieldAccess : public RegAccess<decltype( Base::address ), Base::address, mask, reset, offset>
  {
  };


  RegAccess<uint32_t, 0x40056000> hwm_wakeup;

  using HWM_WKUP = RegAccess<uint32_t, 0x6000E000>;

  using Field = FieldAccess<HWM_WKUP, 0x0000FFFF, 0x0000AAAA, 8>;

  static constexpr size_t some_address = HWM_WKUP::_bitMask;

  static constexpr size_t some_field = Field::_accessor;

}    // namespace Apollo::Register

#endif /* !APOLLO_REG_ACCESSOR_HPP */
