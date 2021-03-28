#ifndef MCASP_OSAL_H
#define MCASP_OSAL_H


#include <ti/osal/osal.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
typedef void *McaspOsal_IntrHandle;
typedef void (*McaspOsal_IntrFuncPtr)(uint32_t arg0);
#define assert(expr)         OSAL_Assert(!(expr))

#endif

#ifdef __cplusplus
}
#endif
