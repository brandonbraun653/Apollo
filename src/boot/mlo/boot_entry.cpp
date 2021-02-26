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

  /*-------------------------------------------------
  Library Functions
  -------------------------------------------------*/
  extern void __libc_init_array();

  /**
   *  System entry after the assembly Reset_Handler executes.
   */
  void _mlo_startup_entry( void )
  {

    /*------------------------------------------------
    Copy the data segment from flash into RAM
    ------------------------------------------------*/
    void **pSource, **pDest;
    // for ( pSource = &_sidata, pDest = &_sdata; pDest != &_edata; pSource++, pDest++ )
    // {
    //   *pDest = *pSource;
    // }

    /*------------------------------------------------
    Zero initialize the bss segment
    ------------------------------------------------*/
    for ( pDest = &__bss_start__; pDest != &__bss_end__; pDest++ )
    {
      *pDest = 0;
    }

    /*------------------------------------------------
    Takes care of array/ctor/dtor data
    ------------------------------------------------*/
    //__libc_init_array();
  }

  // void main(void)
  // {
  //   _mlo_startup_entry();
  // }

#ifdef __cplusplus
} /* extern "C" */
#endif
