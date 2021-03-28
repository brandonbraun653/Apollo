/*-------------------------------------------*/
/* Integer type definitions for FatFs module */
/*-------------------------------------------*/

#ifndef _FF_INTEGER
#define _FF_INTEGER

#ifdef _WIN32	/* FatFs development platform */

#include <windows.h>
#include <tchar.h>
typedef uint64_t QWORD;


#else			/* Embedded platform */

#include <ti/csl/tistdtypes.h>
/* These types must be 16-bit, 32-bit or larger integer */
typedef int32_t INT;
typedef uint32_t UINT;

/* These types must be 8-bit integer */
typedef char CHAR;
typedef unsigned char UCHAR;
typedef uint8_t BYTE;

/* These types must be 16-bit integer */
typedef int16_t SHORT;
typedef uint16_t USHORT;
typedef uint16_t WORD;
typedef uint16_t WCHAR;

/* These types must be 32-bit integer */
typedef int32_t LONG;
typedef uint32_t ULONG;
typedef uint32_t DWORD;
/* This type MUST be 64-bit (Remove this for C89 compatibility) */
typedef unsigned long long QWORD;

#endif

#endif
