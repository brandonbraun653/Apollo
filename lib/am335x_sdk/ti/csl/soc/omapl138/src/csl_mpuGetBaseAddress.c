/**
 *   @file  csl_mpuGetBaseAddress.c
 *
 *   @brief
 *      The file contains routines which are MPU Device specific
 *      and need to be modified for each new device which has the
 *      MPU IP Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par
 */

#include <ti/csl/soc.h>
#include <ti/csl/csl_mpu.h>

/** ============================================================================
 *   @n@b CSL_MPU_Open
 *
 *   @b Description
 *   @n This API opens the MPU instance. This should always be the first call
 *      to the CSL MPU Functional layer. The handle  which is returned from
 *      this call should be passed in all subsequent CSL API's.
 *
 *   <b> Return Value </b>
 *   @n  CSL_MpuHandle  - Handle to the MPU Module
 *   @n  0               - Error.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Affects
 *   @n  None.
 *
 *   @b  Example
 *   @verbatim
        CSL_MpuHandle   hMpu;
        ...
        hMpu = CSL_MPU_Open (0);    // Opens MPU Instance 0
        ...
     @endverbatim
 * ===========================================================================
 */
CSL_MpuHandle CSL_MPU_Open (Int32 instNum)
{
    CSL_MpuHandle ret_val = (CSL_MpuHandle)0;
    switch (instNum)
    {
#ifdef CSL_MPU_0
        case (Int32)CSL_MPU_0:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_0_REGS;
            break;
        }
#endif /* CSL_MPU_0 */
#ifdef CSL_MPU_1
        case (Int32)CSL_MPU_1:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_1_REGS;
            break;
        }
#endif /* CSL_MPU_1 */

    }
    return(ret_val);
}
