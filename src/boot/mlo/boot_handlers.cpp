/********************************************************************************
 *  File Name:
 *    boot_handlers.cpp
 *
 *  Description:
 *    Exception handlers for the various system IRQ events
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#include <Apollo/src/boot/mlo/boot_linker_refs.hpp>

#ifdef __cplusplus
extern "C"
{
#endif


  // void Reset_Handler()
  // {
  //   _mlo_startup_entry();
  // }

  void Undefined_Handler()
  {
    while ( true )
    {
      __asm volatile( "nop" );
    }
  }


  void SVC_Handler()
  {
    while ( true )
    {
      __asm volatile( "nop" );
    }
  }


  void Prefetch_Handler()
  {
    while ( true )
    {
      __asm volatile( "nop" );
    }
  }


  void Abort_Handler()
  {
    while ( true )
    {
      __asm volatile( "nop" );
    }
  }


  void IRQ_Handler()
  {
    while ( true )
    {
      __asm volatile( "nop" );
    }
  }


  void FIQ_Handler()
  {
    while ( true )
    {
      __asm volatile( "nop" );
    }
  }

#ifdef __cplusplus
} /* extern "C" */
#endif
