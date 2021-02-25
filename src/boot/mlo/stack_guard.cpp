/********************************************************************************
 *  File Name:
 *    stack_protector.c
 *
 *  Description:
 *    Required declarations to support the "-fstack-protector-strong" compiler
 *    argument.
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstdint>

/* Chimera Includes */
#include <Chimera/assert>

#ifdef __cplusplus
extern "C"
{
#endif

  /*-------------------------------------------------
  Canary value used to check for stack overruns
  -------------------------------------------------*/
  extern const uintptr_t __stack_chk_guard = 0xdeadbeef;

  /*-------------------------------------------------
  Called if the stack check fails
  -------------------------------------------------*/
  [[noreturn]] void __stack_chk_fail()
  {
    RT_HARD_ASSERT( false );
    while ( true )
    {
      __asm volatile ( "nop" );
    }
  }

#ifdef __cplusplus
} /* extern "C" */
#endif
