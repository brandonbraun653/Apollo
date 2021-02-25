/********************************************************************************
 *  File Name:
 *    boot_linker_refs.hpp
 *
 *  Description:
 *    Declare critical functions so the linker can't throw them away
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_MLO_LINKER_REFERENCES_HPP
#define APOLLO_MLO_LINKER_REFERENCES_HPP

#ifdef __cplusplus
extern "C"
{
#endif

extern void _mlo_startup_entry( void );
#define _LINKER_REF ( _mlo_startup_entry )

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif  /* !APOLLO_MLO_LINKER_REFERENCES_HPP */
