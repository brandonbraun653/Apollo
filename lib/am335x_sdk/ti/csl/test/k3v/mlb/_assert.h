#ifndef _ASSERT_H_
#define _ASSERT_H_
#include <csl_osal.h>

//=============================================================================
//  assertion support
//=============================================================================
#ifdef NDEBUG
#define _assert(ignore) ((void)0)
#else
void __assert_func( const char *func, const char *file, int line, const char *failedexpr )
{
    Osal_Log("assertion \"%s\" failed: file \"%s\", line %d%s%s\n", failedexpr, file, line, func ? ", function: " : "", func ? func : "");
#ifdef ASSERT_ABORT_ON_FAIL
    Osal_Shutdown(0);
#endif
}

#define __assert(e) ((e) ? (void)0 : __assert_func(__func__, __FILE__, __LINE__, #e))
#define _assert(e) __assert(e)
#endif

#endif
