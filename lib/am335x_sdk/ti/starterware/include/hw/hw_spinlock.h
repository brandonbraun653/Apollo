/*
* hw_spinlock.h
*
* Register-level header file for SPINLOCK
*
* Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
*
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef HW_SPINLOCK_H_
#define HW_SPINLOCK_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define SPINLOCK_SYSCONFIG                                           (0x10U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

/* SYSCONFIG */
#define SPINLOCK_SYSCONFIG_CLOCKACTIVITY_SHIFT   (0x00000008U)
#define SPINLOCK_SYSCONFIG_CLOCKACTIVITY_MASK    (0x00000100U)
#define SPINLOCK_SYSCONFIG_CLOCKACTIVITY_OCP_OFF (0x00000000U)
#define SPINLOCK_SYSCONFIG_CLOCKACTIVITY_OCP_ON  (0x00000001U)

#define SPINLOCK_SYSCONFIG_IDLEMODE_MASK         (0x0000000Cu)
#define SPINLOCK_SYSCONFIG_IDLEMODE_SHIFT        (0x00000002u)
#define SPINLOCK_SYSCONFIG_IDLEMODE_FORCE        (0x00000000u)
#define SPINLOCK_SYSCONFIG_IDLEMODE_NOIDLE       (0x00000001u)
#define SPINLOCK_SYSCONFIG_IDLEMODE_SMART        (0x00000002u)
#define SPINLOCK_SYSCONFIG_IDLEMODE_RESERVED     (0x00000003u)

#ifdef __cplusplus
}
#endif
#endif  /* HW_SPINLOCK_H_ */
