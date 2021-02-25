/********************************************************************************
 *  File Name:
 *    boot_entry.c
 *
 *  Description:
 *    Entry point for the MLO software
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

#include <Apollo/src/boot/mlo/boot_linker_refs.hpp>

/**
 *  System entry after the assembly Reset_Handler executes.
 */
void __attribute__( ( used ) ) _mlo_startup_entry( void )
{
  while ( 1 )
  {
    __asm volatile( "nop" );
  }
}

// void main(void)
// {
//   _mlo_startup_entry();
// }

#ifdef __cplusplus
} /* extern "C" */
#endif
