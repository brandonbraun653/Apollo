/**
 *
 * \file   hw_chipdb_interrupt.h
 *
 * \brief  This file enables the interrupt number APIs in ChipDB. These APIs
 *         are used to get the mapping of input interrupt signals to the
 *         interrupt number
 *
 * \version 0.0 (Sep 2013) : [AE] First version
 *
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 */
/*
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


#ifndef HW_INTERRUPT_H_
#define HW_INTERRUPT_H_

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/**
 *
 * \brief An array of interrupt table pointers. Each resource, if it can
 *        generate an interrupt has a table that maps the interrupt signal
 *        to the interrupt number. This array has pointer to these tables.
 *        If a resource doesn't originate interrupt signals that connect to
 *        the INTC in question, then there won't be a table and the
 *        corresponding entry will be NULL.
 *
 */
extern const uint16_t * gChipDBInterruptTables[CHIPDB_RESOURCE_COUNT];


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#ifdef  __cplusplus
}
#endif /* ifdef  __cplusplus */

#endif /* ifndef HW_INTERRUPT_H_ */
