/**
 * \file hw_chipdb_interrupt.c
 *
 * \brief   Chip DB Interrupt number API Implementation
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <types.h>
#include <hw_types.h>
#include <chipdb.h>
#include <chipdb_defs.h>
#include "hw_am335x_chipdb.h"
#include "hw_am335x_chipdb_interrupt.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/*
 *
 * \brief USB Interrupt Mapping Table. This table maps the USB interrupt
 *        signals to the INTC line number to which this signal is connected.
 *
 *        There is a version of this table in each <proc>_interrupt.c file.
 *        It is the user responsibility to include the right file when building
 *        for a specific processor.
 *
 *        This table is auto-generated. The MaxProcResID is also auto
 *        generated as an inline constant value.
 *
 *        The gChipDBInterruptTables[] array entry corresponding to the
 *        USB resources are initialized with these pointers.
 *
 */

static const uint16_t gChipDBUSB0InterruptMap[CHIPDB_INTSIG_USB_COUNT] =
{
    /* USB Instance 0 */
    18U, 19U, 17U, 34U 
};

static const uint16_t gChipDBUSB1InterruptMap[CHIPDB_INTSIG_USB_COUNT] =
{
    /* USB Instance 1 */
    18U, 19U, 17U, 34U
};

static const uint16_t gChipDBDMTIMER0InterruptMap[1] =
{
    /* Interrupt line number of DMTIMER 0*/
    66U
};
static const uint16_t gChipDBDMTIMER2InterruptMap[1] =
{
    /* Interrupt line number of DMTIMER 2*/
    68U
};
static const uint16_t gChipDBDMTIMER3InterruptMap[1] =
{
    /* Interrupt line number of DMTIMER 3*/
    69U
};
static const uint16_t gChipDBDMTIMER4InterruptMap[1] =
{
    /* Interrupt line number of DMTIMER 4*/
    92U
};
static const uint16_t gChipDBDMTIMER5InterruptMap[1] =
{
    /* Interrupt line number of DMTIMER 5*/
    93U
};
static const uint16_t gChipDBDMTIMER6InterruptMap[1] =
{
    /* Interrupt line number of DMTIMER 6*/
    94U
};

static const uint16_t gChipDBDMTIMER7InterruptMap[1] =
{
    /* Interrupt line number of DMTIMER 7*/
    95U
};

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
const uint16_t * gChipDBInterruptTables[CHIPDB_RESOURCE_COUNT] =
{
    /*
    Res0_Interrupt_Table_pointer,
    Res1_Interrupt_Table_pointer,
    ...
    ResN_Interrupt_Table_pointer,
    */
    /* ... */
    gChipDBUSB0InterruptMap,
    gChipDBUSB1InterruptMap,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL, /* resource ID 10 */
    NULL,
    NULL, /* resource ID 12 */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL, 
    NULL,
    NULL, /* resource ID 22 */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL, 
    NULL,
    NULL, /* resource ID 32 */   
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL, 
    NULL,
    NULL, /* resource ID 42 */
    NULL,
    NULL,
    NULL,
    gChipDBDMTIMER0InterruptMap,
    NULL,
    gChipDBDMTIMER2InterruptMap,
    gChipDBDMTIMER3InterruptMap,
    gChipDBDMTIMER4InterruptMap, 
    gChipDBDMTIMER5InterruptMap,
    gChipDBDMTIMER6InterruptMap, /* resource ID 52 */      
    gChipDBDMTIMER7InterruptMap
    /* ... */
};

