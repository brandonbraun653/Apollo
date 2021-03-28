/*
 * mcasp_cfg.c
 *
 * This file contains the test / demo code to demonstrate the Audio component
 * driver functionality on SYS/BIOS 6.
 *
 * Copyright (C) 2009-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/** \file     mcasp_cfg.c
 *
 *  \brief    sample application for demostration of audio playing
 *
 *  This file contains the implementation of the sample appliation for the
 *  demonstration of audio playing through the audio interface layer.
 *
 *             (C) Copyright 2009, Texas Instruments, Inc
 */

/* ========================================================================== */
/*                            INCLUDE FILES                                   */
/* ========================================================================== */

#include <xdc/std.h>
#include <ti/sysbios/io/IOM.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <mcasp_drv.h>
#include <mcasp_cfg.h>
#include <mcasp_tune.h>
#include <ti/csl/csl_chip.h>
#include "ICodec.h"
#include "stdio.h"
#include "string.h"

void GblErrXmt(Mcasp_errCbStatus errCbStat);
void GblErrRcv(Mcasp_errCbStatus errCbStat);

/* ========================================================================== */
/*                          IMPORTED VARIABLES                                */
/* ========================================================================== */


extern HeapMem_Handle myHeap;

/* ========================================================================== */
/*                          McASP Init config                                 */
/* ========================================================================== */

#if defined(AUDIO_DC_DIGITAL_TEST)
Mcasp_HwSetupData mcasp0RcvSetup = {
    /* .rmask    = */
    0xFFFFFFFF,                   /* All the data bits are to be used     */
    /* .rfmt     = */ 0x000180F2, /* 0/1 bit delay from framsync
                                   * MSB first
                                   * No extra bit padding
                                   * Padding bit (ignore)
                                   * slot Size is 32
                                   * Reads from DMA port
                                   * NO rotation
                                   */


    /* .afsrctl  = */ 0x00000111, /* I2S mode,
                                   * Frame sync is one word
                                   * Internally generated frame sync
                                   * Falling edge is start of frame
                                   */




    /* .rtdm     = */ 0x00000003, /* 2 slots are active (I2S)           */
    /* .rintctl  = */ 0x00000003, /* sync error and overrun error       */
    /* .rstat    = */ 0x000001FF, /* reset any existing status bits     */
    /* .revtctl  = */ 0x00000000, /* DMA request is enabled or disabled */
    {
        /* .aclkrctl  = */ 0x00000080, /* Div (8), Internal Source, rising edge */
        /* .ahclkrctl = */ 0x00000400, /* Div (20), Internal AUX_CLK Source     */
        /* .rclkchk   = */ 0x00000000
    }
};

Mcasp_HwSetupData mcasp0XmtSetup = {
    /* .xmask    = */
    0xFFFFFFFF,                   /* All the data bits are to be used     */
    /* .xfmt     = */ 0x000100F0, /* 0/1 bit delay from framsync
                                   * MSB first
                                   * No extra bit padding
                                   * Padding bit (ignore)
                                   * slot Size is 32
                                   * Reads from DMA port
                                   * 0-bit rotation
                                   */

    /* .afsxctl  = */ 0x0000C002, /* I2S mode,
                                   * Frame sync is one word
                                   * internally generated frame sync
                                   * Falling edge is start of frame
                                   */

    /* .xtdm     = */ 0xFFFFFFFF, /* 2 slots are active (I2S) */
    /* .xintctl  = */ 0x00000003, /* sync error,overrun error,clK error   */
    /* .xstat    = */ 0x000001FF, /* reset any existing status bits       */
    /* .xevtctl  = */ 0x00000000, /* DMA request is enabled or disabled   */
    {
        /* .aclkxctl  = */ 0x000000E3, /* Div (8), Internal Source, SYNC, Falling edge */
        /* .ahclkxctl = */ 0x00004000, /* Div (20), Internal AUX_CLK Source */
        /* .xclkchk   = */ 0x00000000
    },
};
#else
Mcasp_HwSetupData mcasp0RcvSetup = {
    /* .rmask    = */
    0xFFFFFFFF,                   /* All the data bits are to be used     */
    /* .rfmt     = */ 0x000180F0, /* 0/1 bit delay from framsync
                                   * MSB first
                                   * No extra bit padding
                                   * Padding bit (ignore)
                                   * slot Size is 32
                                   * Reads from DMA port
                                   * NO rotation
                                   */


    /* .afsrctl  = */ 0x00000113, /* I2S mode,
                                   * Frame sync is one word
                                   * Internally generated frame sync
                                   * Falling edge is start of frame
                                   */




    /* .rtdm     = */ 0x00000003, /* 2 slots are active (I2S)           */
    /* .rintctl  = */ 0x00000003, /* sync error and overrun error       */
    /* .rstat    = */ 0x000001FF, /* reset any existing status bits     */
    /* .revtctl  = */ 0x00000000, /* DMA request is enabled or disabled */
    {
        /* .aclkrctl  = */ 0x000000A3, /* Div (8), Internal Source, rising edge */
        /* .ahclkrctl = */ 0x00008010, /* Div (20), Internal AUX_CLK Source     */
        /* .rclkchk   = */ 0x00000000
    }
};

Mcasp_HwSetupData mcasp0XmtSetup = {
    /* .xmask    = */
    0xFFFFFFFF,                   /* All the data bits are to be used     */
    /* .xfmt     = */ 0x000180F0, /* 0/1 bit delay from framsync
                                   * MSB first
                                   * No extra bit padding
                                   * Padding bit (ignore)
                                   * slot Size is 32
                                   * Reads from DMA port
                                   * 0-bit rotation
                                   */

    /* .afsxctl  = */ 0x00000113, /* I2S mode,
                                   * Frame sync is one word
                                   * internally generated frame sync
                                   * Falling edge is start of frame
                                   */

    /* .xtdm     = */ 0x00000003, /* 2 slots are active (I2S) */
    /* .xintctl  = */ 0x00000003, /* sync error,overrun error,clK error   */
    /* .xstat    = */ 0x000001FF, /* reset any existing status bits       */
    /* .xevtctl  = */ 0x00000000, /* DMA request is enabled or disabled   */
    {
        /* .aclkxctl  = */ 0x000000A3, /* Div (8), Internal Source, SYNC, Falling edge */
        /* .ahclkxctl = */ 0x00008010, /* Div (20), Internal AUX_CLK Source */
        /* .xclkchk   = */ 0x00000000
    },
};
#endif

/* McAsp channel parameters                                  */
Mcasp_ChanParams mcasp_chanparam[2] = {
    {
        RX_NUM_SERIALIZER,                    /* number of serialisers      */
#if defined (DEVICE_LOOPBACK)
        {Mcasp_SerializerNum_1, Mcasp_SerializerNum_3, Mcasp_SerializerNum_5}, /* serialiser index */
#elif defined(AUDIO_DC_ANALOG_TEST)
        {Mcasp_SerializerNum_0, Mcasp_SerializerNum_1, Mcasp_SerializerNum_2, Mcasp_SerializerNum_7, Mcasp_SerializerNum_8, Mcasp_SerializerNum_9}, /* serialiser index           */
#elif defined(AUDIO_DC_DIGITAL_TEST)
        {Mcasp_SerializerNum_0}, /* serialiser index           */
#else
        {Mcasp_SerializerNum_4, Mcasp_SerializerNum_5, Mcasp_SerializerNum_6}, /* serialiser index */
#endif
        &mcasp0RcvSetup,
        TRUE,
        Mcasp_OpMode_TDM,          /* Mode (TDM/DIT)             */
        Mcasp_WordLength_32,
        NULL,
        0,
        NULL,
        (Mcasp_GblCallback)&GblErrRcv,
#if defined(AUDIO_DC_DIGITAL_TEST)
        1, /* number of TDM channels      */
        Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED,
#else
        2, /* number of TDM channels      */
        Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1,
#endif
        TRUE,
        RX_FIFO_EVENT_DMA_RATIO,
        TRUE,
        Mcasp_WordBitsSelect_LSB
    },
    {
        TX_NUM_SERIALIZER,                   /* number of serialisers       */
#if defined (DEVICE_LOOPBACK)
        {Mcasp_SerializerNum_0, Mcasp_SerializerNum_2, Mcasp_SerializerNum_4}, /* serialiser index */
#elif defined(AUDIO_DC_ANALOG_TEST)
	    {Mcasp_SerializerNum_3, Mcasp_SerializerNum_4, Mcasp_SerializerNum_5, Mcasp_SerializerNum_10, Mcasp_SerializerNum_11, Mcasp_SerializerNum_12},
#elif defined(AUDIO_DC_DIGITAL_TEST)
        {Mcasp_SerializerNum_0}, /* serialiser index           */
#else
        {Mcasp_SerializerNum_0, Mcasp_SerializerNum_1, Mcasp_SerializerNum_2}, /* serialiser index */
#endif
        &mcasp0XmtSetup,
        TRUE,
        Mcasp_OpMode_TDM,
        Mcasp_WordLength_32,      /* word width                  */
        NULL,
        0,
        NULL,
        (Mcasp_GblCallback)&GblErrXmt,
#if defined(AUDIO_DC_DIGITAL_TEST)
        1, /* number of TDM channels      */
        Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED,
#else
        2, /* number of TDM channels      */
        Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1,
#endif
        TRUE,
        TX_FIFO_EVENT_DMA_RATIO,
        TRUE,
        Mcasp_WordBitsSelect_LSB
    }
};
