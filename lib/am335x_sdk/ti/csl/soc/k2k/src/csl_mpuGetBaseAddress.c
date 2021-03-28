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
 *  @n   (C) Copyright 2012, Texas Instruments, Inc.
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
        case CSL_MPU_0:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_0_REGS;
            break;
        }
#endif /* CSL_MPU_0 */
#ifdef CSL_MPU_1
        case CSL_MPU_1:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_1_REGS;
            break;
        }
#endif /* CSL_MPU_1 */
#ifdef CSL_MPU_2
        case CSL_MPU_2:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_2_REGS;
            break;
        }
#endif /* CSL_MPU_2 */
#ifdef CSL_MPU_3
        case CSL_MPU_3:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_3_REGS;
            break;
        }
#endif /* CSL_MPU_3 */
#ifdef CSL_MPU_4
        case CSL_MPU_4:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_4_REGS;
            break;
        }
#endif /* CSL_MPU_4 */
#ifdef CSL_MPU_5
        case CSL_MPU_5:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_5_REGS;
            break;
        }
#endif /* CSL_MPU_5 */
#ifdef CSL_MPU_6
        case CSL_MPU_6:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_6_REGS;
            break;
        }
#endif /* CSL_MPU_6 */
#ifdef CSL_MPU_7
        case CSL_MPU_7:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_7_REGS;
            break;
        }
#endif /* CSL_MPU_7 */
#ifdef CSL_MPU_8
        case CSL_MPU_8:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_8_REGS;
            break;
        }
#endif /* CSL_MPU_8 */
#ifdef CSL_MPU_9
        case CSL_MPU_9:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_9_REGS;
            break;
        }
#endif /* CSL_MPU_9 */
#ifdef CSL_MPU_10
        case CSL_MPU_10:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_10_REGS;
            break;
        }
#endif /* CSL_MPU_10 */
#ifdef CSL_MPU_11
        case CSL_MPU_11:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_11_REGS;
            break;
        }
#endif /* CSL_MPU_11 */
#ifdef CSL_MPU_12
        case CSL_MPU_12:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_12_REGS;
            break;
        }
#endif /* CSL_MPU_12*/
#ifdef CSL_MPU_13
        case CSL_MPU_13:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_13_REGS;
            break;
        }
#endif /* CSL_MPU_13 */
#ifdef CSL_MPU_14
        case CSL_MPU_14:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_14_REGS;
            break;
        }
#endif /* CSL_MPU_14 */
#ifdef CSL_MPU_15
        case CSL_MPU_15:
        {
            ret_val = (CSL_MpuHandle)CSL_MPU_15_REGS;
            break;
        }
#endif /* CSL_MPU_15 */
        default:
        {
            ret_val = (CSL_MpuHandle)0;
            break;
        }
    }
    return(ret_val);
}

