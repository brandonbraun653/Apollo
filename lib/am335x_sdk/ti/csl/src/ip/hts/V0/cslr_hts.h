/********************************************************************
 * Copyright (C) 2018 Texas Instruments Incorporated.
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
 *  Name        : cslr_hts.h
*/
#ifndef CSLR_HTS_H_
#define CSLR_HTS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : MMR Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PIPELINE_CONTROL[7];       /* HTS pipeline control */
    volatile uint8_t  Resv_80[52];
    volatile uint32_t HWA0_SCHEDULER_CONTROL;    /* HWA0 control */
    volatile uint32_t HWA0_HOP;                  /* HWA0 HOP control */
    volatile uint32_t HWA0_WDTIMER;              /* HWA0 WD timer control */
    volatile uint32_t HWA0_BW_LIMITER;           /* HWA0 BW control */
    volatile uint32_t HWA0_CONS0_CONTROL;        /* HWA0 cons socket 0 control */
    volatile uint32_t HWA0_CONS1_CONTROL;        /* HWA0 cons socket 1 control */
    volatile uint32_t HWA0_CONS2_CONTROL;        /* HWA0 cons socket 2 control */
    volatile uint32_t HWA0_CONS3_CONTROL;        /* HWA0 cons socket 3 control */
    volatile uint32_t HWA0_CONS4_CONTROL;        /* HWA0 cons socket 4 control */
    volatile uint32_t HWA0_CONS5_CONTROL;        /* HWA0 cons socket 5 control */
    volatile uint32_t HWA0_PROD0_CONTROL;        /* HWA0 prod0 control */
    volatile uint32_t HWA0_PROD0_BUF_CONTROL;    /* HWA0 prod0 buf control */
    volatile uint32_t HWA0_PROD0_COUNT;          /* HWA0 prod0 count  */
    volatile uint32_t HWA0_PA0_CONTROL;          /* HWA0 prod0 pattern adapter control  */
    volatile uint32_t HWA0_PA0_PRODCOUNT;        /* HWA0 prod0 pattern adapter count  */
    volatile uint32_t HWA0_PROD1_CONTROL;        /* HWA0 prod1 control */
    volatile uint32_t HWA0_PROD1_BUF_CONTROL;    /* HWA0 prod1 buf control */
    volatile uint32_t HWA0_PROD1_COUNT;          /* HWA0 prod1 count  */
    volatile uint32_t HWA0_PA1_CONTROL;          /* HWA0 prod1 pattern adapter control  */
    volatile uint32_t HWA0_PA1_PRODCOUNT;        /* HWA0 prod1 pattern adapter count  */
    volatile uint32_t HWA0_PROD2_CONTROL;        /* HWA0 prod2 control */
    volatile uint32_t HWA0_PROD2_BUF_CONTROL;    /* HWA0 prod2 buf control */
    volatile uint32_t HWA0_PROD2_COUNT;          /* HWA0 prod2 count  */
    volatile uint8_t  Resv_180[8];
    volatile uint32_t HWA0_PROD3_CONTROL;        /* HWA0 prod3 control */
    volatile uint32_t HWA0_PROD3_BUF_CONTROL;    /* HWA0 prod3 buf control */
    volatile uint32_t HWA0_PROD3_COUNT;          /* HWA0 prod3 count  */
    volatile uint8_t  Resv_200[8];
    volatile uint32_t HWA0_PROD4_CONTROL;        /* HWA0 prod4 control */
    volatile uint32_t HWA0_PROD4_BUF_CONTROL;    /* HWA0 prod4 buf control */
    volatile uint32_t HWA0_PROD4_COUNT;          /* HWA0 prod4 count  */
    volatile uint8_t  Resv_220[8];
    volatile uint32_t HWA0_PROD5_CONTROL;        /* HWA0 prod5 control */
    volatile uint32_t HWA0_PROD5_BUF_CONTROL;    /* HWA0 prod5 buf control */
    volatile uint32_t HWA0_PROD5_COUNT;          /* HWA0 prod5 count  */
    volatile uint8_t  Resv_240[8];
    volatile uint32_t HWA0_PROD6_CONTROL;        /* HWA0 prod6 control */
    volatile uint32_t HWA0_PROD6_BUF_CONTROL;    /* HWA0 prod6 buf control */
    volatile uint32_t HWA0_PROD6_COUNT;          /* HWA0 prod6 count  */
    volatile uint8_t  Resv_260[8];
    volatile uint32_t HWA1_SCHEDULER_CONTROL;    /* HWA1 control */
    volatile uint32_t HWA1_HOP;                  /* HWA1 HOP control */
    volatile uint32_t HWA1_WDTIMER;              /* HWA1 WD timer control */
    volatile uint32_t HWA1_BW_LIMITER;           /* HWA1 BW control */
    volatile uint32_t HWA1_CONS0_CONTROL;        /* HWA1 cons socket 0 control */
    volatile uint32_t HWA1_CONS1_CONTROL;        /* HWA1 cons socket 1 control */
    volatile uint32_t HWA1_CONS2_CONTROL;        /* HWA1 cons socket 2 control */
    volatile uint32_t HWA1_CONS3_CONTROL;        /* HWA1 cons socket 3 control */
    volatile uint32_t HWA1_CONS4_CONTROL;        /* HWA1 cons socket 4 control */
    volatile uint32_t HWA1_CONS5_CONTROL;        /* HWA1 cons socket 5 control */
    volatile uint32_t HWA1_PROD0_CONTROL;        /* HWA1 prod0 control */
    volatile uint32_t HWA1_PROD0_BUF_CONTROL;    /* HWA1 prod0 buf control */
    volatile uint32_t HWA1_PROD0_COUNT;          /* HWA1 prod0 count  */
    volatile uint32_t HWA1_PA0_CONTROL;          /* HWA1 prod0 pattern adapter control  */
    volatile uint32_t HWA1_PA0_PRODCOUNT;        /* HWA1 prod0 pattern adapter count  */
    volatile uint32_t HWA1_PROD1_CONTROL;        /* HWA1 prod1 control */
    volatile uint32_t HWA1_PROD1_BUF_CONTROL;    /* HWA1 prod1 buf control */
    volatile uint32_t HWA1_PROD1_COUNT;          /* HWA1 prod1 count  */
    volatile uint32_t HWA1_PA1_CONTROL;          /* HWA1 prod1 pattern adapter control  */
    volatile uint32_t HWA1_PA1_PRODCOUNT;        /* HWA1 prod1 pattern adapter count  */
    volatile uint32_t HWA1_PROD2_CONTROL;        /* HWA1 prod2 control */
    volatile uint32_t HWA1_PROD2_BUF_CONTROL;    /* HWA1 prod2 buf control */
    volatile uint32_t HWA1_PROD2_COUNT;          /* HWA1 prod2 count  */
    volatile uint8_t  Resv_360[8];
    volatile uint32_t HWA1_PROD3_CONTROL;        /* HWA1 prod3 control */
    volatile uint32_t HWA1_PROD3_BUF_CONTROL;    /* HWA1 prod3 buf control */
    volatile uint32_t HWA1_PROD3_COUNT;          /* HWA1 prod3 count  */
    volatile uint8_t  Resv_380[8];
    volatile uint32_t HWA1_PROD4_CONTROL;        /* HWA1 prod4 control */
    volatile uint32_t HWA1_PROD4_BUF_CONTROL;    /* HWA1 prod4 buf control */
    volatile uint32_t HWA1_PROD4_COUNT;          /* HWA1 prod4 count  */
    volatile uint8_t  Resv_400[8];
    volatile uint32_t HWA1_PROD5_CONTROL;        /* HWA1 prod5 control */
    volatile uint32_t HWA1_PROD5_BUF_CONTROL;    /* HWA1 prod5 buf control */
    volatile uint32_t HWA1_PROD5_COUNT;          /* HWA1 prod5 count  */
    volatile uint8_t  Resv_420[8];
    volatile uint32_t HWA1_PROD6_CONTROL;        /* HWA1 prod6 control */
    volatile uint32_t HWA1_PROD6_BUF_CONTROL;    /* HWA1 prod6 buf control */
    volatile uint32_t HWA1_PROD6_COUNT;          /* HWA1 prod6 count  */
    volatile uint8_t  Resv_440[8];
    volatile uint32_t HWA2_SCHEDULER_CONTROL;    /* HWA2 control */
    volatile uint32_t HWA2_HOP;                  /* HWA2 HOP control */
    volatile uint32_t HWA2_WDTIMER;              /* HWA2 WD timer control */
    volatile uint32_t HWA2_BW_LIMITER;           /* HWA2 BW control */
    volatile uint32_t HWA2_CONS0_CONTROL;        /* HWA2 cons socket 0 control */
    volatile uint32_t HWA2_CONS1_CONTROL;        /* HWA2 cons socket 1 control */
    volatile uint32_t HWA2_CONS2_CONTROL;        /* HWA2 cons socket 2 control */
    volatile uint32_t HWA2_PROD0_CONTROL;        /* HWA2 prod0 control */
    volatile uint32_t HWA2_PROD0_BUF_CONTROL;    /* HWA2 prod0 buf control */
    volatile uint32_t HWA2_PROD0_COUNT;          /* HWA2 prod0 count  */
    volatile uint32_t HWA2_PA0_CONTROL;          /* HWA2 prod0 pattern adapter control  */
    volatile uint32_t HWA2_PA0_PRODCOUNT;        /* HWA2 prod0 pattern adapter count  */
    volatile uint32_t HWA2_PROD1_CONTROL;        /* HWA2 prod1 control */
    volatile uint32_t HWA2_PROD1_BUF_CONTROL;    /* HWA2 prod1 buf control */
    volatile uint32_t HWA2_PROD1_COUNT;          /* HWA2 prod1 count  */
    volatile uint32_t HWA2_PA1_CONTROL;          /* HWA2 prod1 pattern adapter control  */
    volatile uint32_t HWA2_PA1_PRODCOUNT;        /* HWA2 prod1 pattern adapter count  */
    volatile uint32_t HWA2_PROD2_CONTROL;        /* HWA2 prod2 control */
    volatile uint32_t HWA2_PROD2_BUF_CONTROL;    /* HWA2 prod2 buf control */
    volatile uint32_t HWA2_PROD2_COUNT;          /* HWA2 prod2 count  */
    volatile uint32_t HWA2_PA2_CONTROL;          /* HWA2 prod2 pattern adapter control  */
    volatile uint32_t HWA2_PA2_PRODCOUNT;        /* HWA2 prod2 pattern adapter count  */
    volatile uint32_t HWA2_PROD3_CONTROL;        /* HWA2 prod3 control */
    volatile uint32_t HWA2_PROD3_BUF_CONTROL;    /* HWA2 prod3 buf control */
    volatile uint32_t HWA2_PROD3_COUNT;          /* HWA2 prod3 count  */
    volatile uint32_t HWA2_PA3_CONTROL;          /* HWA2 prod3 pattern adapter control  */
    volatile uint32_t HWA2_PA3_PRODCOUNT;        /* HWA2 prod3 pattern adapter count  */
    volatile uint32_t HWA2_PROD4_CONTROL;        /* HWA2 prod4 control */
    volatile uint32_t HWA2_PROD4_BUF_CONTROL;    /* HWA2 prod4 buf control */
    volatile uint32_t HWA2_PROD4_COUNT;          /* HWA2 prod4 count  */
    volatile uint32_t HWA2_PA4_CONTROL;          /* HWA2 prod4 pattern adapter control  */
    volatile uint32_t HWA2_PA4_PRODCOUNT;        /* HWA2 prod4 pattern adapter count  */
    volatile uint32_t HWA2_PROD5_CONTROL;        /* HWA2 prod5 control */
    volatile uint32_t HWA2_PROD5_BUF_CONTROL;    /* HWA2 prod5 buf control */
    volatile uint32_t HWA2_PROD5_COUNT;          /* HWA2 prod5 count  */
    volatile uint32_t HWA2_PA5_CONTROL;          /* HWA2 prod5 pattern adapter control  */
    volatile uint32_t HWA2_PA5_PRODCOUNT;        /* HWA2 prod5 pattern adapter count  */
    volatile uint32_t HWA2_PROD6_CONTROL;        /* HWA2 prod6 control */
    volatile uint32_t HWA2_PROD6_BUF_CONTROL;    /* HWA2 prod6 buf control */
    volatile uint32_t HWA2_PROD6_COUNT;          /* HWA2 prod6 count  */
    volatile uint32_t HWA2_PA6_CONTROL;          /* HWA2 prod6 pattern adapter control  */
    volatile uint32_t HWA2_PA6_PRODCOUNT;        /* HWA2 prod6 pattern adapter count  */
    volatile uint32_t HWA2_PROD7_CONTROL;        /* HWA2 prod7 control */
    volatile uint32_t HWA2_PROD7_BUF_CONTROL;    /* HWA2 prod7 buf control */
    volatile uint32_t HWA2_PROD7_COUNT;          /* HWA2 prod7 count  */
    volatile uint8_t  Resv_628[8];
    volatile uint32_t HWA3_SCHEDULER_CONTROL;    /* HWA3 control */
    volatile uint32_t HWA3_HOP;                  /* HWA3 HOP control */
    volatile uint32_t HWA3_WDTIMER;              /* HWA3 WD timer control */
    volatile uint32_t HWA3_BW_LIMITER;           /* HWA3 BW control */
    volatile uint32_t HWA3_CONS0_CONTROL;        /* HWA3 cons socket 0 control */
    volatile uint32_t HWA3_CONS1_CONTROL;        /* HWA3 cons socket 1 control */
    volatile uint32_t HWA3_CONS2_CONTROL;        /* HWA3 cons socket 2 control */
    volatile uint32_t HWA3_PROD0_CONTROL;        /* HWA3 prod0 control */
    volatile uint32_t HWA3_PROD0_BUF_CONTROL;    /* HWA3 prod0 buf control */
    volatile uint32_t HWA3_PROD0_COUNT;          /* HWA3 prod0 count  */
    volatile uint32_t HWA3_PA0_CONTROL;          /* HWA3 prod0 pattern adapter control  */
    volatile uint32_t HWA3_PA0_PRODCOUNT;        /* HWA3 prod0 pattern adapter count  */
    volatile uint32_t HWA3_PROD1_CONTROL;        /* HWA3 prod1 control */
    volatile uint32_t HWA3_PROD1_BUF_CONTROL;    /* HWA3 prod1 buf control */
    volatile uint32_t HWA3_PROD1_COUNT;          /* HWA3 prod1 count  */
    volatile uint32_t HWA3_PA1_CONTROL;          /* HWA3 prod1 pattern adapter control  */
    volatile uint32_t HWA3_PA1_PRODCOUNT;        /* HWA3 prod1 pattern adapter count  */
    volatile uint32_t HWA3_PROD2_CONTROL;        /* HWA3 prod2 control */
    volatile uint32_t HWA3_PROD2_BUF_CONTROL;    /* HWA3 prod2 buf control */
    volatile uint32_t HWA3_PROD2_COUNT;          /* HWA3 prod2 count  */
    volatile uint32_t HWA3_PA2_CONTROL;          /* HWA3 prod2 pattern adapter control  */
    volatile uint32_t HWA3_PA2_PRODCOUNT;        /* HWA3 prod2 pattern adapter count  */
    volatile uint32_t HWA3_PROD3_CONTROL;        /* HWA3 prod3 control */
    volatile uint32_t HWA3_PROD3_BUF_CONTROL;    /* HWA3 prod3 buf control */
    volatile uint32_t HWA3_PROD3_COUNT;          /* HWA3 prod3 count  */
    volatile uint32_t HWA3_PA3_CONTROL;          /* HWA3 prod3 pattern adapter control  */
    volatile uint32_t HWA3_PA3_PRODCOUNT;        /* HWA3 prod3 pattern adapter count  */
    volatile uint32_t HWA3_PROD4_CONTROL;        /* HWA3 prod4 control */
    volatile uint32_t HWA3_PROD4_BUF_CONTROL;    /* HWA3 prod4 buf control */
    volatile uint32_t HWA3_PROD4_COUNT;          /* HWA3 prod4 count  */
    volatile uint32_t HWA3_PA4_CONTROL;          /* HWA3 prod4 pattern adapter control  */
    volatile uint32_t HWA3_PA4_PRODCOUNT;        /* HWA3 prod4 pattern adapter count  */
    volatile uint32_t HWA3_PROD5_CONTROL;        /* HWA3 prod5 control */
    volatile uint32_t HWA3_PROD5_BUF_CONTROL;    /* HWA3 prod5 buf control */
    volatile uint32_t HWA3_PROD5_COUNT;          /* HWA3 prod5 count  */
    volatile uint32_t HWA3_PA5_CONTROL;          /* HWA3 prod5 pattern adapter control  */
    volatile uint32_t HWA3_PA5_PRODCOUNT;        /* HWA3 prod5 pattern adapter count  */
    volatile uint32_t HWA3_PROD6_CONTROL;        /* HWA3 prod6 control */
    volatile uint32_t HWA3_PROD6_BUF_CONTROL;    /* HWA3 prod6 buf control */
    volatile uint32_t HWA3_PROD6_COUNT;          /* HWA3 prod6 count  */
    volatile uint32_t HWA3_PA6_CONTROL;          /* HWA3 prod6 pattern adapter control  */
    volatile uint32_t HWA3_PA6_PRODCOUNT;        /* HWA3 prod6 pattern adapter count  */
    volatile uint32_t HWA3_PROD7_CONTROL;        /* HWA3 prod7 control */
    volatile uint32_t HWA3_PROD7_BUF_CONTROL;    /* HWA3 prod7 buf control */
    volatile uint32_t HWA3_PROD7_COUNT;          /* HWA3 prod7 count  */
    volatile uint8_t  Resv_816[8];
    volatile uint32_t HWA4_SCHEDULER_CONTROL;    /* HWA4 control */
    volatile uint32_t HWA4_HOP;                  /* HWA4 HOP control */
    volatile uint32_t HWA4_WDTIMER;              /* HWA4 WD timer control */
    volatile uint32_t HWA4_BW_LIMITER;           /* HWA4 BW control */
    volatile uint32_t HWA4_CONS0_CONTROL;        /* HWA4 cons socket 0 control */
    volatile uint32_t HWA4_CONS1_CONTROL;        /* HWA4 cons socket 1 control */
    volatile uint32_t HWA4_PROD0_CONTROL;        /* HWA4 prod0 control */
    volatile uint32_t HWA4_PROD0_BUF_CONTROL;    /* HWA4 prod0 buf control */
    volatile uint32_t HWA4_PROD0_COUNT;          /* HWA4 prod0 count  */
    volatile uint8_t  Resv_860[8];
    volatile uint32_t HWA4_PROD1_CONTROL;        /* HWA4 prod1 control */
    volatile uint32_t HWA4_PROD1_BUF_CONTROL;    /* HWA4 prod1 buf control */
    volatile uint32_t HWA4_PROD1_COUNT;          /* HWA4 prod1 count  */
    volatile uint8_t  Resv_880[8];
    volatile uint32_t HWA4_PROD2_CONTROL;        /* HWA4 prod2 control */
    volatile uint32_t HWA4_PROD2_BUF_CONTROL;    /* HWA4 prod2 buf control */
    volatile uint32_t HWA4_PROD2_COUNT;          /* HWA4 prod2 count  */
    volatile uint8_t  Resv_900[8];
    volatile uint32_t HWA4_PROD3_CONTROL;        /* HWA4 prod3 control */
    volatile uint32_t HWA4_PROD3_BUF_CONTROL;    /* HWA4 prod3 buf control */
    volatile uint32_t HWA4_PROD3_COUNT;          /* HWA4 prod3 count  */
    volatile uint8_t  Resv_920[8];
    volatile uint32_t HWA4_PROD4_CONTROL;        /* HWA4 prod4 control */
    volatile uint32_t HWA4_PROD4_BUF_CONTROL;    /* HWA4 prod4 buf control */
    volatile uint32_t HWA4_PROD4_COUNT;          /* HWA4 prod4 count  */
    volatile uint8_t  Resv_940[8];
    volatile uint32_t HWA4_PROD5_CONTROL;        /* HWA4 prod5 control */
    volatile uint32_t HWA4_PROD5_BUF_CONTROL;    /* HWA4 prod5 buf control */
    volatile uint32_t HWA4_PROD5_COUNT;          /* HWA4 prod5 count  */
    volatile uint8_t  Resv_960[8];
    volatile uint32_t HWA4_PROD6_CONTROL;        /* HWA4 prod6 control */
    volatile uint32_t HWA4_PROD6_BUF_CONTROL;    /* HWA4 prod6 buf control */
    volatile uint32_t HWA4_PROD6_COUNT;          /* HWA4 prod6 count  */
    volatile uint8_t  Resv_980[8];
    volatile uint32_t HWA4_PROD7_CONTROL;        /* HWA4 prod7 control */
    volatile uint32_t HWA4_PROD7_BUF_CONTROL;    /* HWA4 prod7 buf control */
    volatile uint32_t HWA4_PROD7_COUNT;          /* HWA4 prod7 count  */
    volatile uint8_t  Resv_1000[8];
    volatile uint32_t HWA4_PROD8_CONTROL;        /* HWA4 prod8 control */
    volatile uint32_t HWA4_PROD8_BUF_CONTROL;    /* HWA4 prod8 buf control */
    volatile uint32_t HWA4_PROD8_COUNT;          /* HWA4 prod8 count  */
    volatile uint8_t  Resv_1020[8];
    volatile uint32_t HWA4_PROD9_CONTROL;        /* HWA4 prod9 control */
    volatile uint32_t HWA4_PROD9_BUF_CONTROL;    /* HWA4 prod9 buf control */
    volatile uint32_t HWA4_PROD9_COUNT;          /* HWA4 prod9 count  */
    volatile uint8_t  Resv_1040[8];
    volatile uint32_t HWA4_PROD10_CONTROL;       /* HWA4 prod10 control */
    volatile uint32_t HWA4_PROD10_BUF_CONTROL;   /* HWA4 prod10 buf control */
    volatile uint32_t HWA4_PROD10_COUNT;         /* HWA4 prod10 count  */
    volatile uint8_t  Resv_1060[8];
    volatile uint32_t HWA5_SCHEDULER_CONTROL;    /* HWA5 control */
    volatile uint32_t HWA5_HOP;                  /* HWA5 HOP control */
    volatile uint32_t HWA5_WDTIMER;              /* HWA5 WD timer control */
    volatile uint32_t HWA5_BW_LIMITER;           /* HWA5 BW control */
    volatile uint32_t HWA5_CONS0_CONTROL;        /* HWA5 cons socket 0 control */
    volatile uint32_t HWA5_CONS1_CONTROL;        /* HWA5 cons socket 1 control */
    volatile uint32_t HWA5_PROD0_CONTROL;        /* HWA5 prod0 control */
    volatile uint32_t HWA5_PROD0_BUF_CONTROL;    /* HWA5 prod0 buf control */
    volatile uint32_t HWA5_PROD0_COUNT;          /* HWA5 prod0 count  */
    volatile uint8_t  Resv_1104[8];
    volatile uint32_t HWA5_PROD1_CONTROL;        /* HWA5 prod1 control */
    volatile uint32_t HWA5_PROD1_BUF_CONTROL;    /* HWA5 prod1 buf control */
    volatile uint32_t HWA5_PROD1_COUNT;          /* HWA5 prod1 count  */
    volatile uint8_t  Resv_1124[8];
    volatile uint32_t HWA5_PROD2_CONTROL;        /* HWA5 prod2 control */
    volatile uint32_t HWA5_PROD2_BUF_CONTROL;    /* HWA5 prod2 buf control */
    volatile uint32_t HWA5_PROD2_COUNT;          /* HWA5 prod2 count  */
    volatile uint8_t  Resv_1144[8];
    volatile uint32_t HWA5_PROD3_CONTROL;        /* HWA5 prod3 control */
    volatile uint32_t HWA5_PROD3_BUF_CONTROL;    /* HWA5 prod3 buf control */
    volatile uint32_t HWA5_PROD3_COUNT;          /* HWA5 prod3 count  */
    volatile uint8_t  Resv_1164[8];
    volatile uint32_t HWA5_PROD4_CONTROL;        /* HWA5 prod4 control */
    volatile uint32_t HWA5_PROD4_BUF_CONTROL;    /* HWA5 prod4 buf control */
    volatile uint32_t HWA5_PROD4_COUNT;          /* HWA5 prod4 count  */
    volatile uint8_t  Resv_1184[8];
    volatile uint32_t HWA5_PROD5_CONTROL;        /* HWA5 prod5 control */
    volatile uint32_t HWA5_PROD5_BUF_CONTROL;    /* HWA5 prod5 buf control */
    volatile uint32_t HWA5_PROD5_COUNT;          /* HWA5 prod5 count  */
    volatile uint8_t  Resv_1204[8];
    volatile uint32_t HWA5_PROD6_CONTROL;        /* HWA5 prod6 control */
    volatile uint32_t HWA5_PROD6_BUF_CONTROL;    /* HWA5 prod6 buf control */
    volatile uint32_t HWA5_PROD6_COUNT;          /* HWA5 prod6 count  */
    volatile uint8_t  Resv_1224[8];
    volatile uint32_t HWA5_PROD7_CONTROL;        /* HWA5 prod7 control */
    volatile uint32_t HWA5_PROD7_BUF_CONTROL;    /* HWA5 prod7 buf control */
    volatile uint32_t HWA5_PROD7_COUNT;          /* HWA5 prod7 count  */
    volatile uint8_t  Resv_1244[8];
    volatile uint32_t HWA5_PROD8_CONTROL;        /* HWA5 prod8 control */
    volatile uint32_t HWA5_PROD8_BUF_CONTROL;    /* HWA5 prod8 buf control */
    volatile uint32_t HWA5_PROD8_COUNT;          /* HWA5 prod8 count  */
    volatile uint8_t  Resv_1264[8];
    volatile uint32_t HWA5_PROD9_CONTROL;        /* HWA5 prod9 control */
    volatile uint32_t HWA5_PROD9_BUF_CONTROL;    /* HWA5 prod9 buf control */
    volatile uint32_t HWA5_PROD9_COUNT;          /* HWA5 prod9 count  */
    volatile uint8_t  Resv_1284[8];
    volatile uint32_t HWA5_PROD10_CONTROL;       /* HWA5 prod10 control */
    volatile uint32_t HWA5_PROD10_BUF_CONTROL;   /* HWA5 prod10 buf control */
    volatile uint32_t HWA5_PROD10_COUNT;         /* HWA5 prod10 count  */
    volatile uint8_t  Resv_1304[8];
    volatile uint32_t HWA6_SCHEDULER_CONTROL;    /* HWA6 control */
    volatile uint32_t HWA6_HOP;                  /* HWA6 HOP control */
    volatile uint32_t HWA6_WDTIMER;              /* HWA6 WD timer control */
    volatile uint32_t HWA6_BW_LIMITER;           /* HWA6 BW control */
    volatile uint32_t HWA6_CONS0_CONTROL;        /* HWA6 cons socket 0 control */
    volatile uint32_t HWA6_CONS1_CONTROL;        /* HWA6 cons socket 1 control */
    volatile uint32_t HWA6_PROD0_CONTROL;        /* HWA6 prod0 control */
    volatile uint32_t HWA6_PROD0_BUF_CONTROL;    /* HWA6 prod0 buf control */
    volatile uint32_t HWA6_PROD0_COUNT;          /* HWA6 prod0 count  */
    volatile uint8_t  Resv_1348[8];
    volatile uint32_t HWA6_PROD1_CONTROL;        /* HWA6 prod1 control */
    volatile uint32_t HWA6_PROD1_BUF_CONTROL;    /* HWA6 prod1 buf control */
    volatile uint32_t HWA6_PROD1_COUNT;          /* HWA6 prod1 count  */
    volatile uint8_t  Resv_1368[8];
    volatile uint32_t HWA7_SCHEDULER_CONTROL;    /* HWA7 control */
    volatile uint32_t HWA7_HOP;                  /* HWA7 HOP control */
    volatile uint32_t HWA7_WDTIMER;              /* HWA7 WD timer control */
    volatile uint32_t HWA7_BW_LIMITER;           /* HWA7 BW control */
    volatile uint32_t HWA7_CONS0_CONTROL;        /* HWA7 cons socket 0 control */
    volatile uint32_t HWA7_CONS1_CONTROL;        /* HWA7 cons socket 1 control */
    volatile uint32_t HWA7_CONS2_CONTROL;        /* HWA7 cons socket 2 control */
    volatile uint32_t HWA7_CONS3_CONTROL;        /* HWA7 cons socket 3 control */
    volatile uint32_t HWA7_CONS4_CONTROL;        /* HWA7 cons socket 4 control */
    volatile uint32_t HWA7_PROD0_CONTROL;        /* HWA7 prod0 control */
    volatile uint32_t HWA7_PROD0_BUF_CONTROL;    /* HWA7 prod0 buf control */
    volatile uint32_t HWA7_PROD0_COUNT;          /* HWA7 prod0 count  */
    volatile uint32_t HWA7_PA0_CONTROL;          /* HWA7 prod0 pattern adapter control  */
    volatile uint32_t HWA7_PA0_PRODCOUNT;        /* HWA7 prod0 pattern adapter count  */
    volatile uint32_t HWA7_PROD1_CONTROL;        /* HWA7 prod1 control */
    volatile uint32_t HWA7_PROD1_BUF_CONTROL;    /* HWA7 prod1 buf control */
    volatile uint32_t HWA7_PROD1_COUNT;          /* HWA7 prod1 count  */
    volatile uint32_t HWA7_PA1_CONTROL;          /* HWA7 prod1 pattern adapter control  */
    volatile uint32_t HWA7_PA1_PRODCOUNT;        /* HWA7 prod1 pattern adapter count  */
    volatile uint32_t HWA7_PROD2_CONTROL;        /* HWA7 prod2 control */
    volatile uint32_t HWA7_PROD2_BUF_CONTROL;    /* HWA7 prod2 buf control */
    volatile uint32_t HWA7_PROD2_COUNT;          /* HWA7 prod2 count  */
    volatile uint32_t HWA7_PA2_CONTROL;          /* HWA7 prod2 pattern adapter control  */
    volatile uint32_t HWA7_PA2_PRODCOUNT;        /* HWA7 prod2 pattern adapter count  */
    volatile uint32_t HWA7_PROD3_CONTROL;        /* HWA7 prod3 control */
    volatile uint32_t HWA7_PROD3_BUF_CONTROL;    /* HWA7 prod3 buf control */
    volatile uint32_t HWA7_PROD3_COUNT;          /* HWA7 prod3 count  */
    volatile uint32_t HWA7_PA3_CONTROL;          /* HWA7 prod3 pattern adapter control  */
    volatile uint32_t HWA7_PA3_PRODCOUNT;        /* HWA7 prod3 pattern adapter count  */
    volatile uint32_t HWA7_PROD4_CONTROL;        /* HWA7 prod4 control */
    volatile uint32_t HWA7_PROD4_BUF_CONTROL;    /* HWA7 prod4 buf control */
    volatile uint32_t HWA7_PROD4_COUNT;          /* HWA7 prod4 count  */
    volatile uint8_t  Resv_1504[8];
    volatile uint32_t HWA8_SCHEDULER_CONTROL;    /* HWA8 control */
    volatile uint32_t HWA8_HOP;                  /* HWA8 HOP control */
    volatile uint32_t HWA8_WDTIMER;              /* HWA8 WD timer control */
    volatile uint32_t HWA8_BW_LIMITER;           /* HWA8 BW control */
    volatile uint32_t HWA8_CONS0_CONTROL;        /* HWA8 cons socket 0 control */
    volatile uint32_t HWA8_CONS1_CONTROL;        /* HWA8 cons socket 1 control */
    volatile uint32_t HWA8_CONS2_CONTROL;        /* HWA8 cons socket 2 control */
    volatile uint32_t HWA8_CONS3_CONTROL;        /* HWA8 cons socket 3 control */
    volatile uint32_t HWA8_CONS4_CONTROL;        /* HWA8 cons socket 4 control */
    volatile uint32_t HWA8_PROD0_CONTROL;        /* HWA8 prod0 control */
    volatile uint32_t HWA8_PROD0_BUF_CONTROL;    /* HWA8 prod0 buf control */
    volatile uint32_t HWA8_PROD0_COUNT;          /* HWA8 prod0 count  */
    volatile uint32_t HWA8_PA0_CONTROL;          /* HWA8 prod0 pattern adapter control  */
    volatile uint32_t HWA8_PA0_PRODCOUNT;        /* HWA8 prod0 pattern adapter count  */
    volatile uint32_t HWA8_PROD1_CONTROL;        /* HWA8 prod1 control */
    volatile uint32_t HWA8_PROD1_BUF_CONTROL;    /* HWA8 prod1 buf control */
    volatile uint32_t HWA8_PROD1_COUNT;          /* HWA8 prod1 count  */
    volatile uint32_t HWA8_PA1_CONTROL;          /* HWA8 prod1 pattern adapter control  */
    volatile uint32_t HWA8_PA1_PRODCOUNT;        /* HWA8 prod1 pattern adapter count  */
    volatile uint32_t HWA8_PROD2_CONTROL;        /* HWA8 prod2 control */
    volatile uint32_t HWA8_PROD2_BUF_CONTROL;    /* HWA8 prod2 buf control */
    volatile uint32_t HWA8_PROD2_COUNT;          /* HWA8 prod2 count  */
    volatile uint32_t HWA8_PA2_CONTROL;          /* HWA8 prod2 pattern adapter control  */
    volatile uint32_t HWA8_PA2_PRODCOUNT;        /* HWA8 prod2 pattern adapter count  */
    volatile uint32_t HWA8_PROD3_CONTROL;        /* HWA8 prod3 control */
    volatile uint32_t HWA8_PROD3_BUF_CONTROL;    /* HWA8 prod3 buf control */
    volatile uint32_t HWA8_PROD3_COUNT;          /* HWA8 prod3 count  */
    volatile uint32_t HWA8_PA3_CONTROL;          /* HWA8 prod3 pattern adapter control  */
    volatile uint32_t HWA8_PA3_PRODCOUNT;        /* HWA8 prod3 pattern adapter count  */
    volatile uint32_t HWA8_PROD4_CONTROL;        /* HWA8 prod4 control */
    volatile uint32_t HWA8_PROD4_BUF_CONTROL;    /* HWA8 prod4 buf control */
    volatile uint32_t HWA8_PROD4_COUNT;          /* HWA8 prod4 count  */
    volatile uint8_t  Resv_1640[8];
    volatile uint32_t HWA12_SCHEDULER_CONTROL;   /* HWA12 control */
    volatile uint32_t HWA12_HOP;                 /* HWA12 HOP control */
    volatile uint8_t  Resv_1656[8];
    volatile uint32_t HWA12_CONS0_CONTROL;       /* HWA12 cons socket 0 control */
    volatile uint32_t HWA12_CONS1_CONTROL;       /* HWA12 cons socket 1 control */
    volatile uint32_t HWA12_PROD0_CONTROL;       /* HWA12 prod0 control */
    volatile uint32_t HWA12_PROD0_BUF_CONTROL;   /* HWA12 prod0 buf control */
    volatile uint32_t HWA12_PROD0_COUNT;         /* HWA12 prod0 count  */
    volatile uint32_t HWA12_PA0_CONTROL;         /* HWA12 prod0 pattern adapter control  */
    volatile uint32_t HWA12_PA0_PRODCOUNT;       /* HWA12 prod0 pattern adapter count  */
    volatile uint32_t HWA12_PROD1_CONTROL;       /* HWA12 prod1 control */
    volatile uint32_t HWA12_PROD1_BUF_CONTROL;   /* HWA12 prod1 buf control */
    volatile uint32_t HWA12_PROD1_COUNT;         /* HWA12 prod1 count  */
    volatile uint32_t HWA12_PA1_CONTROL;         /* HWA12 prod1 pattern adapter control  */
    volatile uint32_t HWA12_PA1_PRODCOUNT;       /* HWA12 prod1 pattern adapter count  */
    volatile uint32_t HWA12_PROD2_CONTROL;       /* HWA12 prod2 control */
    volatile uint32_t HWA12_PROD2_BUF_CONTROL;   /* HWA12 prod2 buf control */
    volatile uint32_t HWA12_PROD2_COUNT;         /* HWA12 prod2 count  */
    volatile uint32_t HWA12_PA2_CONTROL;         /* HWA12 prod2 pattern adapter control  */
    volatile uint32_t HWA12_PA2_PRODCOUNT;       /* HWA12 prod2 pattern adapter count  */
    volatile uint32_t HWA12_PROD3_CONTROL;       /* HWA12 prod3 control */
    volatile uint32_t HWA12_PROD3_BUF_CONTROL;   /* HWA12 prod3 buf control */
    volatile uint32_t HWA12_PROD3_COUNT;         /* HWA12 prod3 count  */
    volatile uint8_t  Resv_1744[8];
    volatile uint32_t HWA13_SCHEDULER_CONTROL;   /* HWA13 control */
    volatile uint32_t HWA13_HOP;                 /* HWA13 HOP control */
    volatile uint8_t  Resv_1760[8];
    volatile uint32_t HWA13_CONS0_CONTROL;       /* HWA13 cons socket 0 control */
    volatile uint32_t HWA13_CONS1_CONTROL;       /* HWA13 cons socket 1 control */
    volatile uint32_t HWA13_PROD0_CONTROL;       /* HWA13 prod0 control */
    volatile uint32_t HWA13_PROD0_BUF_CONTROL;   /* HWA13 prod0 buf control */
    volatile uint32_t HWA13_PROD0_COUNT;         /* HWA13 prod0 count  */
    volatile uint32_t HWA13_PA0_CONTROL;         /* HWA13 prod0 pattern adapter control  */
    volatile uint32_t HWA13_PA0_PRODCOUNT;       /* HWA13 prod0 pattern adapter count  */
    volatile uint32_t HWA13_PROD1_CONTROL;       /* HWA13 prod1 control */
    volatile uint32_t HWA13_PROD1_BUF_CONTROL;   /* HWA13 prod1 buf control */
    volatile uint32_t HWA13_PROD1_COUNT;         /* HWA13 prod1 count  */
    volatile uint32_t HWA13_PA1_CONTROL;         /* HWA13 prod1 pattern adapter control  */
    volatile uint32_t HWA13_PA1_PRODCOUNT;       /* HWA13 prod1 pattern adapter count  */
    volatile uint32_t HWA13_PROD2_CONTROL;       /* HWA13 prod2 control */
    volatile uint32_t HWA13_PROD2_BUF_CONTROL;   /* HWA13 prod2 buf control */
    volatile uint32_t HWA13_PROD2_COUNT;         /* HWA13 prod2 count  */
    volatile uint32_t HWA13_PA2_CONTROL;         /* HWA13 prod2 pattern adapter control  */
    volatile uint32_t HWA13_PA2_PRODCOUNT;       /* HWA13 prod2 pattern adapter count  */
    volatile uint32_t HWA13_PROD3_CONTROL;       /* HWA13 prod3 control */
    volatile uint32_t HWA13_PROD3_BUF_CONTROL;   /* HWA13 prod3 buf control */
    volatile uint32_t HWA13_PROD3_COUNT;         /* HWA13 prod3 count  */
    volatile uint8_t  Resv_1848[8];
    volatile uint32_t HWA14_SCHEDULER_CONTROL;   /* HWA14 control */
    volatile uint32_t HWA14_HOP;                 /* HWA14 HOP control */
    volatile uint8_t  Resv_1864[8];
    volatile uint32_t HWA14_CONS0_CONTROL;       /* HWA14 cons socket 0 control */
    volatile uint32_t HWA14_CONS1_CONTROL;       /* HWA14 cons socket 1 control */
    volatile uint32_t HWA14_PROD0_CONTROL;       /* HWA14 prod0 control */
    volatile uint32_t HWA14_PROD0_BUF_CONTROL;   /* HWA14 prod0 buf control */
    volatile uint32_t HWA14_PROD0_COUNT;         /* HWA14 prod0 count  */
    volatile uint32_t HWA14_PA0_CONTROL;         /* HWA14 prod0 pattern adapter control  */
    volatile uint32_t HWA14_PA0_PRODCOUNT;       /* HWA14 prod0 pattern adapter count  */
    volatile uint32_t HWA14_PROD1_CONTROL;       /* HWA14 prod1 control */
    volatile uint32_t HWA14_PROD1_BUF_CONTROL;   /* HWA14 prod1 buf control */
    volatile uint32_t HWA14_PROD1_COUNT;         /* HWA14 prod1 count  */
    volatile uint32_t HWA14_PA1_CONTROL;         /* HWA14 prod1 pattern adapter control  */
    volatile uint32_t HWA14_PA1_PRODCOUNT;       /* HWA14 prod1 pattern adapter count  */
    volatile uint32_t HWA14_PROD2_CONTROL;       /* HWA14 prod2 control */
    volatile uint32_t HWA14_PROD2_BUF_CONTROL;   /* HWA14 prod2 buf control */
    volatile uint32_t HWA14_PROD2_COUNT;         /* HWA14 prod2 count  */
    volatile uint32_t HWA14_PA2_CONTROL;         /* HWA14 prod2 pattern adapter control  */
    volatile uint32_t HWA14_PA2_PRODCOUNT;       /* HWA14 prod2 pattern adapter count  */
    volatile uint32_t HWA14_PROD3_CONTROL;       /* HWA14 prod3 control */
    volatile uint32_t HWA14_PROD3_BUF_CONTROL;   /* HWA14 prod3 buf control */
    volatile uint32_t HWA14_PROD3_COUNT;         /* HWA14 prod3 count  */
    volatile uint8_t  Resv_1952[8];
    volatile uint32_t HWA15_SCHEDULER_CONTROL;   /* HWA15 control */
    volatile uint32_t HWA15_HOP;                 /* HWA15 HOP control */
    volatile uint8_t  Resv_1968[8];
    volatile uint32_t HWA15_CONS0_CONTROL;       /* HWA15 cons socket 0 control */
    volatile uint32_t HWA15_CONS1_CONTROL;       /* HWA15 cons socket 1 control */
    volatile uint32_t HWA15_PROD0_CONTROL;       /* HWA15 prod0 control */
    volatile uint32_t HWA15_PROD0_BUF_CONTROL;   /* HWA15 prod0 buf control */
    volatile uint32_t HWA15_PROD0_COUNT;         /* HWA15 prod0 count  */
    volatile uint32_t HWA15_PA0_CONTROL;         /* HWA15 prod0 pattern adapter control  */
    volatile uint32_t HWA15_PA0_PRODCOUNT;       /* HWA15 prod0 pattern adapter count  */
    volatile uint32_t HWA15_PROD1_CONTROL;       /* HWA15 prod1 control */
    volatile uint32_t HWA15_PROD1_BUF_CONTROL;   /* HWA15 prod1 buf control */
    volatile uint32_t HWA15_PROD1_COUNT;         /* HWA15 prod1 count  */
    volatile uint32_t HWA15_PA1_CONTROL;         /* HWA15 prod1 pattern adapter control  */
    volatile uint32_t HWA15_PA1_PRODCOUNT;       /* HWA15 prod1 pattern adapter count  */
    volatile uint32_t HWA15_PROD2_CONTROL;       /* HWA15 prod2 control */
    volatile uint32_t HWA15_PROD2_BUF_CONTROL;   /* HWA15 prod2 buf control */
    volatile uint32_t HWA15_PROD2_COUNT;         /* HWA15 prod2 count  */
    volatile uint32_t HWA15_PA2_CONTROL;         /* HWA15 prod2 pattern adapter control  */
    volatile uint32_t HWA15_PA2_PRODCOUNT;       /* HWA15 prod2 pattern adapter count  */
    volatile uint32_t HWA15_PROD3_CONTROL;       /* HWA15 prod3 control */
    volatile uint32_t HWA15_PROD3_BUF_CONTROL;   /* HWA15 prod3 buf control */
    volatile uint32_t HWA15_PROD3_COUNT;         /* HWA15 prod3 count  */
    volatile uint8_t  Resv_2056[8];
    volatile uint32_t HWA16_SCHEDULER_CONTROL;   /* HWA16 control */
    volatile uint32_t HWA16_HOP;                 /* HWA16 HOP control */
    volatile uint8_t  Resv_2072[8];
    volatile uint32_t HWA16_CONS0_CONTROL;       /* HWA16 cons socket 0 control */
    volatile uint32_t HWA16_CONS1_CONTROL;       /* HWA16 cons socket 1 control */
    volatile uint32_t HWA16_PROD0_CONTROL;       /* HWA16 prod0 control */
    volatile uint32_t HWA16_PROD0_BUF_CONTROL;   /* HWA16 prod0 buf control */
    volatile uint32_t HWA16_PROD0_COUNT;         /* HWA16 prod0 count  */
    volatile uint32_t HWA16_PA0_CONTROL;         /* HWA16 prod0 pattern adapter control  */
    volatile uint32_t HWA16_PA0_PRODCOUNT;       /* HWA16 prod0 pattern adapter count  */
    volatile uint32_t HWA16_PROD1_CONTROL;       /* HWA16 prod1 control */
    volatile uint32_t HWA16_PROD1_BUF_CONTROL;   /* HWA16 prod1 buf control */
    volatile uint32_t HWA16_PROD1_COUNT;         /* HWA16 prod1 count  */
    volatile uint32_t HWA16_PA1_CONTROL;         /* HWA16 prod1 pattern adapter control  */
    volatile uint32_t HWA16_PA1_PRODCOUNT;       /* HWA16 prod1 pattern adapter count  */
    volatile uint32_t HWA16_PROD2_CONTROL;       /* HWA16 prod2 control */
    volatile uint32_t HWA16_PROD2_BUF_CONTROL;   /* HWA16 prod2 buf control */
    volatile uint32_t HWA16_PROD2_COUNT;         /* HWA16 prod2 count  */
    volatile uint32_t HWA16_PA2_CONTROL;         /* HWA16 prod2 pattern adapter control  */
    volatile uint32_t HWA16_PA2_PRODCOUNT;       /* HWA16 prod2 pattern adapter count  */
    volatile uint32_t HWA16_PROD3_CONTROL;       /* HWA16 prod3 control */
    volatile uint32_t HWA16_PROD3_BUF_CONTROL;   /* HWA16 prod3 buf control */
    volatile uint32_t HWA16_PROD3_COUNT;         /* HWA16 prod3 count  */
    volatile uint8_t  Resv_2160[8];
    volatile uint32_t HWA17_SCHEDULER_CONTROL;   /* HWA17 control */
    volatile uint32_t HWA17_HOP;                 /* HWA17 HOP control */
    volatile uint8_t  Resv_2176[8];
    volatile uint32_t HWA17_CONS0_CONTROL;       /* HWA17 cons socket 0 control */
    volatile uint32_t HWA17_CONS1_CONTROL;       /* HWA17 cons socket 1 control */
    volatile uint32_t HWA17_PROD0_CONTROL;       /* HWA17 prod0 control */
    volatile uint32_t HWA17_PROD0_BUF_CONTROL;   /* HWA17 prod0 buf control */
    volatile uint32_t HWA17_PROD0_COUNT;         /* HWA17 prod0 count  */
    volatile uint32_t HWA17_PA0_CONTROL;         /* HWA17 prod0 pattern adapter control  */
    volatile uint32_t HWA17_PA0_PRODCOUNT;       /* HWA17 prod0 pattern adapter count  */
    volatile uint32_t HWA17_PROD1_CONTROL;       /* HWA17 prod1 control */
    volatile uint32_t HWA17_PROD1_BUF_CONTROL;   /* HWA17 prod1 buf control */
    volatile uint32_t HWA17_PROD1_COUNT;         /* HWA17 prod1 count  */
    volatile uint32_t HWA17_PA1_CONTROL;         /* HWA17 prod1 pattern adapter control  */
    volatile uint32_t HWA17_PA1_PRODCOUNT;       /* HWA17 prod1 pattern adapter count  */
    volatile uint32_t HWA17_PROD2_CONTROL;       /* HWA17 prod2 control */
    volatile uint32_t HWA17_PROD2_BUF_CONTROL;   /* HWA17 prod2 buf control */
    volatile uint32_t HWA17_PROD2_COUNT;         /* HWA17 prod2 count  */
    volatile uint32_t HWA17_PA2_CONTROL;         /* HWA17 prod2 pattern adapter control  */
    volatile uint32_t HWA17_PA2_PRODCOUNT;       /* HWA17 prod2 pattern adapter count  */
    volatile uint32_t HWA17_PROD3_CONTROL;       /* HWA17 prod3 control */
    volatile uint32_t HWA17_PROD3_BUF_CONTROL;   /* HWA17 prod3 buf control */
    volatile uint32_t HWA17_PROD3_COUNT;         /* HWA17 prod3 count  */
    volatile uint8_t  Resv_2264[8];
    volatile uint32_t HWA18_SCHEDULER_CONTROL;   /* HWA18 control */
    volatile uint32_t HWA18_HOP;                 /* HWA18 HOP control */
    volatile uint8_t  Resv_2280[8];
    volatile uint32_t HWA18_CONS0_CONTROL;       /* HWA18 cons socket 0 control */
    volatile uint32_t HWA18_CONS1_CONTROL;       /* HWA18 cons socket 1 control */
    volatile uint32_t HWA18_PROD0_CONTROL;       /* HWA18 prod0 control */
    volatile uint32_t HWA18_PROD0_BUF_CONTROL;   /* HWA18 prod0 buf control */
    volatile uint32_t HWA18_PROD0_COUNT;         /* HWA18 prod0 count  */
    volatile uint32_t HWA18_PA0_CONTROL;         /* HWA18 prod0 pattern adapter control  */
    volatile uint32_t HWA18_PA0_PRODCOUNT;       /* HWA18 prod0 pattern adapter count  */
    volatile uint32_t HWA18_PROD1_CONTROL;       /* HWA18 prod1 control */
    volatile uint32_t HWA18_PROD1_BUF_CONTROL;   /* HWA18 prod1 buf control */
    volatile uint32_t HWA18_PROD1_COUNT;         /* HWA18 prod1 count  */
    volatile uint32_t HWA18_PA1_CONTROL;         /* HWA18 prod1 pattern adapter control  */
    volatile uint32_t HWA18_PA1_PRODCOUNT;       /* HWA18 prod1 pattern adapter count  */
    volatile uint32_t HWA18_PROD2_CONTROL;       /* HWA18 prod2 control */
    volatile uint32_t HWA18_PROD2_BUF_CONTROL;   /* HWA18 prod2 buf control */
    volatile uint32_t HWA18_PROD2_COUNT;         /* HWA18 prod2 count  */
    volatile uint32_t HWA18_PA2_CONTROL;         /* HWA18 prod2 pattern adapter control  */
    volatile uint32_t HWA18_PA2_PRODCOUNT;       /* HWA18 prod2 pattern adapter count  */
    volatile uint32_t HWA18_PROD3_CONTROL;       /* HWA18 prod3 control */
    volatile uint32_t HWA18_PROD3_BUF_CONTROL;   /* HWA18 prod3 buf control */
    volatile uint32_t HWA18_PROD3_COUNT;         /* HWA18 prod3 count  */
    volatile uint8_t  Resv_2368[8];
    volatile uint32_t HWA19_SCHEDULER_CONTROL;   /* HWA19 control */
    volatile uint32_t HWA19_HOP;                 /* HWA19 HOP control */
    volatile uint8_t  Resv_2384[8];
    volatile uint32_t HWA19_CONS0_CONTROL;       /* HWA19 cons socket 0 control */
    volatile uint32_t HWA19_CONS1_CONTROL;       /* HWA19 cons socket 1 control */
    volatile uint32_t HWA19_PROD0_CONTROL;       /* HWA19 prod0 control */
    volatile uint32_t HWA19_PROD0_BUF_CONTROL;   /* HWA19 prod0 buf control */
    volatile uint32_t HWA19_PROD0_COUNT;         /* HWA19 prod0 count  */
    volatile uint32_t HWA19_PA0_CONTROL;         /* HWA19 prod0 pattern adapter control  */
    volatile uint32_t HWA19_PA0_PRODCOUNT;       /* HWA19 prod0 pattern adapter count  */
    volatile uint32_t HWA19_PROD1_CONTROL;       /* HWA19 prod1 control */
    volatile uint32_t HWA19_PROD1_BUF_CONTROL;   /* HWA19 prod1 buf control */
    volatile uint32_t HWA19_PROD1_COUNT;         /* HWA19 prod1 count  */
    volatile uint32_t HWA19_PA1_CONTROL;         /* HWA19 prod1 pattern adapter control  */
    volatile uint32_t HWA19_PA1_PRODCOUNT;       /* HWA19 prod1 pattern adapter count  */
    volatile uint32_t HWA19_PROD2_CONTROL;       /* HWA19 prod2 control */
    volatile uint32_t HWA19_PROD2_BUF_CONTROL;   /* HWA19 prod2 buf control */
    volatile uint32_t HWA19_PROD2_COUNT;         /* HWA19 prod2 count  */
    volatile uint32_t HWA19_PA2_CONTROL;         /* HWA19 prod2 pattern adapter control  */
    volatile uint32_t HWA19_PA2_PRODCOUNT;       /* HWA19 prod2 pattern adapter count  */
    volatile uint32_t HWA19_PROD3_CONTROL;       /* HWA19 prod3 control */
    volatile uint32_t HWA19_PROD3_BUF_CONTROL;   /* HWA19 prod3 buf control */
    volatile uint32_t HWA19_PROD3_COUNT;         /* HWA19 prod3 count  */
    volatile uint8_t  Resv_2472[8];
    volatile uint32_t DMA0_SCHEDULER_CONTROL;    /* DMA0 control */
    volatile uint32_t DMA0_HOP;                  /* DMA0 HOP control */
    volatile uint8_t  Resv_2488[8];
    volatile uint32_t DMA0_PROD0_CONTROL;        /* DMA0 prod control */
    volatile uint32_t DMA0_PROD0_BUF_CONTROL;    /* DMA0 prod buf control */
    volatile uint32_t DMA0_PROD0_COUNT;          /* DMA0 prod count  */
    volatile uint32_t DMA1_SCHEDULER_CONTROL;    /* DMA1 control */
    volatile uint32_t DMA1_HOP;                  /* DMA1 HOP control */
    volatile uint8_t  Resv_2516[8];
    volatile uint32_t DMA1_PROD0_CONTROL;        /* DMA1 prod control */
    volatile uint32_t DMA1_PROD0_BUF_CONTROL;    /* DMA1 prod buf control */
    volatile uint32_t DMA1_PROD0_COUNT;          /* DMA1 prod count  */
    volatile uint32_t DMA2_SCHEDULER_CONTROL;    /* DMA2 control */
    volatile uint32_t DMA2_HOP;                  /* DMA2 HOP control */
    volatile uint8_t  Resv_2544[8];
    volatile uint32_t DMA2_PROD0_CONTROL;        /* DMA2 prod control */
    volatile uint32_t DMA2_PROD0_BUF_CONTROL;    /* DMA2 prod buf control */
    volatile uint32_t DMA2_PROD0_COUNT;          /* DMA2 prod count  */
    volatile uint32_t DMA3_SCHEDULER_CONTROL;    /* DMA3 control */
    volatile uint32_t DMA3_HOP;                  /* DMA3 HOP control */
    volatile uint8_t  Resv_2572[8];
    volatile uint32_t DMA3_PROD0_CONTROL;        /* DMA3 prod control */
    volatile uint32_t DMA3_PROD0_BUF_CONTROL;    /* DMA3 prod buf control */
    volatile uint32_t DMA3_PROD0_COUNT;          /* DMA3 prod count  */
    volatile uint32_t DMA4_SCHEDULER_CONTROL;    /* DMA4 control */
    volatile uint32_t DMA4_HOP;                  /* DMA4 HOP control */
    volatile uint8_t  Resv_2600[8];
    volatile uint32_t DMA4_PROD0_CONTROL;        /* DMA4 prod control */
    volatile uint32_t DMA4_PROD0_BUF_CONTROL;    /* DMA4 prod buf control */
    volatile uint32_t DMA4_PROD0_COUNT;          /* DMA4 prod count  */
    volatile uint8_t  Resv_2696[84];
    volatile uint32_t DMA8_SCHEDULER_CONTROL;    /* DMA8 control */
    volatile uint32_t DMA8_HOP;                  /* DMA8 HOP control */
    volatile uint8_t  Resv_2712[8];
    volatile uint32_t DMA8_PROD0_CONTROL;        /* DMA8 prod control */
    volatile uint32_t DMA8_PROD0_BUF_CONTROL;    /* DMA8 prod buf control */
    volatile uint32_t DMA8_PROD0_COUNT;          /* DMA8 prod count  */
    volatile uint32_t DMA8_PA0_CONTROL;          /* DMA8 prod0 pattern adapter control  */
    volatile uint32_t DMA8_PA0_PRODCOUNT;        /* DMA8 prod0 pattern adapter count  */
    volatile uint32_t DMA9_SCHEDULER_CONTROL;    /* DMA9 control */
    volatile uint32_t DMA9_HOP;                  /* DMA9 HOP control */
    volatile uint8_t  Resv_2748[8];
    volatile uint32_t DMA9_PROD0_CONTROL;        /* DMA9 prod control */
    volatile uint32_t DMA9_PROD0_BUF_CONTROL;    /* DMA9 prod buf control */
    volatile uint32_t DMA9_PROD0_COUNT;          /* DMA9 prod count  */
    volatile uint32_t DMA9_PA0_CONTROL;          /* DMA9 prod0 pattern adapter control  */
    volatile uint32_t DMA9_PA0_PRODCOUNT;        /* DMA9 prod0 pattern adapter count  */
    volatile uint32_t DMA10_SCHEDULER_CONTROL;   /* DMA10 control */
    volatile uint32_t DMA10_HOP;                 /* DMA10 HOP control */
    volatile uint8_t  Resv_2784[8];
    volatile uint32_t DMA10_PROD0_CONTROL;       /* DMA10 prod control */
    volatile uint32_t DMA10_PROD0_BUF_CONTROL;   /* DMA10 prod buf control */
    volatile uint32_t DMA10_PROD0_COUNT;         /* DMA10 prod count  */
    volatile uint32_t DMA10_PA0_CONTROL;         /* DMA10 prod0 pattern adapter control  */
    volatile uint32_t DMA10_PA0_PRODCOUNT;       /* DMA10 prod0 pattern adapter count  */
    volatile uint8_t  Resv_3392[588];
    volatile uint32_t DMA32_SCHEDULER_CONTROL;   /* DMA32 control */
    volatile uint32_t DMA32_HOP;                 /* DMA32 HOP control */
    volatile uint8_t  Resv_3408[8];
    volatile uint32_t DMA32_PROD0_CONTROL;       /* DMA32 prod control */
    volatile uint32_t DMA32_PROD0_BUF_CONTROL;   /* DMA32 prod buf control */
    volatile uint32_t DMA32_PROD0_COUNT;         /* DMA32 prod count  */
    volatile uint8_t  Resv_3616[196];
    volatile uint32_t DMA40_SCHEDULER_CONTROL;   /* DMA40 control */
    volatile uint32_t DMA40_HOP;                 /* DMA40 HOP control */
    volatile uint8_t  Resv_3632[8];
    volatile uint32_t DMA40_PROD0_CONTROL;       /* DMA40 prod control */
    volatile uint32_t DMA40_PROD0_BUF_CONTROL;   /* DMA40 prod buf control */
    volatile uint32_t DMA40_PROD0_COUNT;         /* DMA40 prod count  */
    volatile uint8_t  Resv_3840[196];
    volatile uint32_t DMA48_SCHEDULER_CONTROL;   /* DMA48 control */
    volatile uint32_t DMA48_HOP;                 /* DMA48 HOP control */
    volatile uint8_t  Resv_3856[8];
    volatile uint32_t DMA48_PROD0_CONTROL;       /* DMA48 prod control */
    volatile uint32_t DMA48_PROD0_BUF_CONTROL;   /* DMA48 prod buf control */
    volatile uint32_t DMA48_PROD0_COUNT;         /* DMA48 prod count  */
    volatile uint8_t  Resv_4064[196];
    volatile uint32_t DMA56_SCHEDULER_CONTROL;   /* DMA56 control */
    volatile uint32_t DMA56_HOP;                 /* DMA56 HOP control */
    volatile uint8_t  Resv_4080[8];
    volatile uint32_t DMA56_PROD0_CONTROL;       /* DMA56 prod control */
    volatile uint32_t DMA56_PROD0_BUF_CONTROL;   /* DMA56 prod buf control */
    volatile uint32_t DMA56_PROD0_COUNT;         /* DMA56 prod count  */
    volatile uint32_t DMA57_SCHEDULER_CONTROL;   /* DMA57 control */
    volatile uint32_t DMA57_HOP;                 /* DMA57 HOP control */
    volatile uint8_t  Resv_4108[8];
    volatile uint32_t DMA57_PROD0_CONTROL;       /* DMA57 prod control */
    volatile uint32_t DMA57_PROD0_BUF_CONTROL;   /* DMA57 prod buf control */
    volatile uint32_t DMA57_PROD0_COUNT;         /* DMA57 prod count  */
    volatile uint32_t DMA58_SCHEDULER_CONTROL;   /* DMA58 control */
    volatile uint32_t DMA58_HOP;                 /* DMA58 HOP control */
    volatile uint8_t  Resv_4136[8];
    volatile uint32_t DMA58_PROD0_CONTROL;       /* DMA58 prod control */
    volatile uint32_t DMA58_PROD0_BUF_CONTROL;   /* DMA58 prod buf control */
    volatile uint32_t DMA58_PROD0_COUNT;         /* DMA58 prod count  */
    volatile uint32_t DMA59_SCHEDULER_CONTROL;   /* DMA59 control */
    volatile uint32_t DMA59_HOP;                 /* DMA59 HOP control */
    volatile uint8_t  Resv_4164[8];
    volatile uint32_t DMA59_PROD0_CONTROL;       /* DMA59 prod control */
    volatile uint32_t DMA59_PROD0_BUF_CONTROL;   /* DMA59 prod buf control */
    volatile uint32_t DMA59_PROD0_COUNT;         /* DMA59 prod count  */
    volatile uint8_t  Resv_4288[112];
    volatile uint32_t DMA64_SCHEDULER_CONTROL;   /* DMA64 control */
    volatile uint32_t DMA64_HOP;                 /* DMA64 HOP control */
    volatile uint8_t  Resv_4304[8];
    volatile uint32_t DMA64_PROD0_CONTROL;       /* DMA64 prod control */
    volatile uint32_t DMA64_PROD0_BUF_CONTROL;   /* DMA64 prod buf control */
    volatile uint32_t DMA64_PROD0_COUNT;         /* DMA64 prod count  */
    volatile uint32_t DMA65_SCHEDULER_CONTROL;   /* DMA65 control */
    volatile uint32_t DMA65_HOP;                 /* DMA65 HOP control */
    volatile uint8_t  Resv_4332[8];
    volatile uint32_t DMA65_PROD0_CONTROL;       /* DMA65 prod control */
    volatile uint32_t DMA65_PROD0_BUF_CONTROL;   /* DMA65 prod buf control */
    volatile uint32_t DMA65_PROD0_COUNT;         /* DMA65 prod count  */
    volatile uint32_t DMA66_SCHEDULER_CONTROL;   /* DMA66 control */
    volatile uint32_t DMA66_HOP;                 /* DMA66 HOP control */
    volatile uint8_t  Resv_4360[8];
    volatile uint32_t DMA66_PROD0_CONTROL;       /* DMA66 prod control */
    volatile uint32_t DMA66_PROD0_BUF_CONTROL;   /* DMA66 prod buf control */
    volatile uint32_t DMA66_PROD0_COUNT;         /* DMA66 prod count  */
    volatile uint32_t DMA67_SCHEDULER_CONTROL;   /* DMA67 control */
    volatile uint32_t DMA67_HOP;                 /* DMA67 HOP control */
    volatile uint8_t  Resv_4388[8];
    volatile uint32_t DMA67_PROD0_CONTROL;       /* DMA67 prod control */
    volatile uint32_t DMA67_PROD0_BUF_CONTROL;   /* DMA67 prod buf control */
    volatile uint32_t DMA67_PROD0_COUNT;         /* DMA67 prod count  */
    volatile uint8_t  Resv_8628[4228];
    volatile uint32_t DMA240_SCHEDULER_CONTROL;   /* DMA240 control */
    volatile uint8_t  Resv_8644[12];
    volatile uint32_t DMA240_CONS0_CONTROL;      /* DMA240 cons socket 0 control */
    volatile uint32_t DMA241_SCHEDULER_CONTROL;   /* DMA241 control */
    volatile uint8_t  Resv_8664[12];
    volatile uint32_t DMA241_CONS0_CONTROL;      /* DMA241 cons socket 0 control */
    volatile uint32_t DMA242_SCHEDULER_CONTROL;   /* DMA242 control */
    volatile uint8_t  Resv_8684[12];
    volatile uint32_t DMA242_CONS0_CONTROL;      /* DMA242 cons socket 0 control */
    volatile uint32_t DMA243_SCHEDULER_CONTROL;   /* DMA243 control */
    volatile uint8_t  Resv_8704[12];
    volatile uint32_t DMA243_CONS0_CONTROL;      /* DMA243 cons socket 0 control */
    volatile uint32_t DMA244_SCHEDULER_CONTROL;   /* DMA244 control */
    volatile uint8_t  Resv_8724[12];
    volatile uint32_t DMA244_CONS0_CONTROL;      /* DMA244 cons socket 0 control */
    volatile uint32_t DMA245_SCHEDULER_CONTROL;   /* DMA245 control */
    volatile uint8_t  Resv_8744[12];
    volatile uint32_t DMA245_CONS0_CONTROL;      /* DMA245 cons socket 0 control */
    volatile uint32_t DMA256_SCHEDULER_CONTROL;   /* DMA256 control */
    volatile uint8_t  Resv_8764[12];
    volatile uint32_t DMA256_CONS0_CONTROL;      /* DMA256 cons socket 0 control */
    volatile uint32_t DMA257_SCHEDULER_CONTROL;   /* DMA257 control */
    volatile uint8_t  Resv_8784[12];
    volatile uint32_t DMA257_CONS0_CONTROL;      /* DMA257 cons socket 0 control */
    volatile uint32_t DMA258_SCHEDULER_CONTROL;   /* DMA258 control */
    volatile uint8_t  Resv_8804[12];
    volatile uint32_t DMA258_CONS0_CONTROL;      /* DMA258 cons socket 0 control */
    volatile uint32_t DMA259_SCHEDULER_CONTROL;   /* DMA259 control */
    volatile uint8_t  Resv_8824[12];
    volatile uint32_t DMA259_CONS0_CONTROL;      /* DMA259 cons socket 0 control */
    volatile uint32_t DMA260_SCHEDULER_CONTROL;   /* DMA260 control */
    volatile uint8_t  Resv_8844[12];
    volatile uint32_t DMA260_CONS0_CONTROL;      /* DMA260 cons socket 0 control */
    volatile uint32_t DMA261_SCHEDULER_CONTROL;   /* DMA261 control */
    volatile uint8_t  Resv_8864[12];
    volatile uint32_t DMA261_CONS0_CONTROL;      /* DMA261 cons socket 0 control */
    volatile uint32_t DMA272_SCHEDULER_CONTROL;   /* DMA272 control */
    volatile uint8_t  Resv_8884[12];
    volatile uint32_t DMA272_CONS0_CONTROL;      /* DMA272 cons socket 0 control */
    volatile uint32_t DMA273_SCHEDULER_CONTROL;   /* DMA273 control */
    volatile uint8_t  Resv_8904[12];
    volatile uint32_t DMA273_CONS0_CONTROL;      /* DMA273 cons socket 0 control */
    volatile uint32_t DMA274_SCHEDULER_CONTROL;   /* DMA274 control */
    volatile uint8_t  Resv_8924[12];
    volatile uint32_t DMA274_CONS0_CONTROL;      /* DMA274 cons socket 0 control */
    volatile uint32_t DMA275_SCHEDULER_CONTROL;   /* DMA275 control */
    volatile uint8_t  Resv_8944[12];
    volatile uint32_t DMA275_CONS0_CONTROL;      /* DMA275 cons socket 0 control */
    volatile uint32_t DMA288_SCHEDULER_CONTROL;   /* DMA288 control */
    volatile uint8_t  Resv_8964[12];
    volatile uint32_t DMA288_CONS0_CONTROL;      /* DMA288 cons socket 0 control */
    volatile uint32_t DMA289_SCHEDULER_CONTROL;   /* DMA289 control */
    volatile uint8_t  Resv_8984[12];
    volatile uint32_t DMA289_CONS0_CONTROL;      /* DMA289 cons socket 0 control */
    volatile uint32_t DMA290_SCHEDULER_CONTROL;   /* DMA290 control */
    volatile uint8_t  Resv_9004[12];
    volatile uint32_t DMA290_CONS0_CONTROL;      /* DMA290 cons socket 0 control */
    volatile uint32_t DMA291_SCHEDULER_CONTROL;   /* DMA291 control */
    volatile uint8_t  Resv_9024[12];
    volatile uint32_t DMA291_CONS0_CONTROL;      /* DMA291 cons socket 0 control */
    volatile uint32_t DMA304_SCHEDULER_CONTROL;   /* DMA304 control */
    volatile uint8_t  Resv_9044[12];
    volatile uint32_t DMA304_CONS0_CONTROL;      /* DMA304 cons socket 0 control */
    volatile uint32_t DMA305_SCHEDULER_CONTROL;   /* DMA305 control */
    volatile uint8_t  Resv_9064[12];
    volatile uint32_t DMA305_CONS0_CONTROL;      /* DMA305 cons socket 0 control */
    volatile uint32_t DMA306_SCHEDULER_CONTROL;   /* DMA306 control */
    volatile uint8_t  Resv_9084[12];
    volatile uint32_t DMA306_CONS0_CONTROL;      /* DMA306 cons socket 0 control */
    volatile uint32_t DMA307_SCHEDULER_CONTROL;   /* DMA307 control */
    volatile uint8_t  Resv_9104[12];
    volatile uint32_t DMA307_CONS0_CONTROL;      /* DMA307 cons socket 0 control */
    volatile uint32_t DMA308_SCHEDULER_CONTROL;   /* DMA308 control */
    volatile uint8_t  Resv_9124[12];
    volatile uint32_t DMA308_CONS0_CONTROL;      /* DMA308 cons socket 0 control */
    volatile uint32_t DMA309_SCHEDULER_CONTROL;   /* DMA309 control */
    volatile uint8_t  Resv_9144[12];
    volatile uint32_t DMA309_CONS0_CONTROL;      /* DMA309 cons socket 0 control */
    volatile uint32_t DMA310_SCHEDULER_CONTROL;   /* DMA310 control */
    volatile uint8_t  Resv_9164[12];
    volatile uint32_t DMA310_CONS0_CONTROL;      /* DMA310 cons socket 0 control */
    volatile uint32_t DMA311_SCHEDULER_CONTROL;   /* DMA311 control */
    volatile uint8_t  Resv_9184[12];
    volatile uint32_t DMA311_CONS0_CONTROL;      /* DMA311 cons socket 0 control */
    volatile uint32_t DMA312_SCHEDULER_CONTROL;   /* DMA312 control */
    volatile uint8_t  Resv_9204[12];
    volatile uint32_t DMA312_CONS0_CONTROL;      /* DMA312 cons socket 0 control */
    volatile uint32_t DMA313_SCHEDULER_CONTROL;   /* DMA313 control */
    volatile uint8_t  Resv_9224[12];
    volatile uint32_t DMA313_CONS0_CONTROL;      /* DMA313 cons socket 0 control */
    volatile uint32_t DMA336_SCHEDULER_CONTROL;   /* DMA336 control */
    volatile uint8_t  Resv_9244[12];
    volatile uint32_t DMA336_CONS0_CONTROL;      /* DMA336 cons socket 0 control */
    volatile uint32_t DMA352_SCHEDULER_CONTROL;   /* DMA352 control */
    volatile uint8_t  Resv_9264[12];
    volatile uint32_t DMA352_CONS0_CONTROL;      /* DMA352 cons socket 0 control */
    volatile uint32_t DMA353_SCHEDULER_CONTROL;   /* DMA353 control */
    volatile uint8_t  Resv_9284[12];
    volatile uint32_t DMA353_CONS0_CONTROL;      /* DMA353 cons socket 0 control */
    volatile uint32_t DMA354_SCHEDULER_CONTROL;   /* DMA354 control */
    volatile uint8_t  Resv_9304[12];
    volatile uint32_t DMA354_CONS0_CONTROL;      /* DMA354 cons socket 0 control */
    volatile uint32_t DMA355_SCHEDULER_CONTROL;   /* DMA355 control */
    volatile uint8_t  Resv_9324[12];
    volatile uint32_t DMA355_CONS0_CONTROL;      /* DMA355 cons socket 0 control */
    volatile uint32_t DMA368_SCHEDULER_CONTROL;   /* DMA368 control */
    volatile uint8_t  Resv_9344[12];
    volatile uint32_t DMA368_CONS0_CONTROL;      /* DMA368 cons socket 0 control */
    volatile uint32_t DMA369_SCHEDULER_CONTROL;   /* DMA369 control */
    volatile uint8_t  Resv_9364[12];
    volatile uint32_t DMA369_CONS0_CONTROL;      /* DMA369 cons socket 0 control */
    volatile uint32_t DMA370_SCHEDULER_CONTROL;   /* DMA370 control */
    volatile uint8_t  Resv_9384[12];
    volatile uint32_t DMA370_CONS0_CONTROL;      /* DMA370 cons socket 0 control */
    volatile uint32_t DMA371_SCHEDULER_CONTROL;   /* DMA371 control */
    volatile uint8_t  Resv_9404[12];
    volatile uint32_t DMA371_CONS0_CONTROL;      /* DMA371 cons socket 0 control */
    volatile uint8_t  Resv_9808[400];
    volatile uint32_t PIPE_DBG_CNTL;             /* pipeline Debug control */
    volatile uint32_t DBG_CAP;                   /* Debug capability */
    volatile uint32_t DBG_CNTL;                  /* Debug control */
} CSL_htsRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_HTS_PIPELINE_CONTROL(N)                                            (0x00000000U+((N)*0x4U))
#define CSL_HTS_HWA0_SCHEDULER_CONTROL                                         (0x00000050U)
#define CSL_HTS_HWA0_HOP                                                       (0x00000054U)
#define CSL_HTS_HWA0_WDTIMER                                                   (0x00000058U)
#define CSL_HTS_HWA0_BW_LIMITER                                                (0x0000005CU)
#define CSL_HTS_HWA0_CONS0_CONTROL                                             (0x00000060U)
#define CSL_HTS_HWA0_CONS1_CONTROL                                             (0x00000064U)
#define CSL_HTS_HWA0_CONS2_CONTROL                                             (0x00000068U)
#define CSL_HTS_HWA0_CONS3_CONTROL                                             (0x0000006CU)
#define CSL_HTS_HWA0_CONS4_CONTROL                                             (0x00000070U)
#define CSL_HTS_HWA0_CONS5_CONTROL                                             (0x00000074U)
#define CSL_HTS_HWA0_PROD0_CONTROL                                             (0x00000078U)
#define CSL_HTS_HWA0_PROD0_BUF_CONTROL                                         (0x0000007CU)
#define CSL_HTS_HWA0_PROD0_COUNT                                               (0x00000080U)
#define CSL_HTS_HWA0_PA0_CONTROL                                               (0x00000084U)
#define CSL_HTS_HWA0_PA0_PRODCOUNT                                             (0x00000088U)
#define CSL_HTS_HWA0_PROD1_CONTROL                                             (0x0000008CU)
#define CSL_HTS_HWA0_PROD1_BUF_CONTROL                                         (0x00000090U)
#define CSL_HTS_HWA0_PROD1_COUNT                                               (0x00000094U)
#define CSL_HTS_HWA0_PA1_CONTROL                                               (0x00000098U)
#define CSL_HTS_HWA0_PA1_PRODCOUNT                                             (0x0000009CU)
#define CSL_HTS_HWA0_PROD2_CONTROL                                             (0x000000A0U)
#define CSL_HTS_HWA0_PROD2_BUF_CONTROL                                         (0x000000A4U)
#define CSL_HTS_HWA0_PROD2_COUNT                                               (0x000000A8U)
#define CSL_HTS_HWA0_PROD3_CONTROL                                             (0x000000B4U)
#define CSL_HTS_HWA0_PROD3_BUF_CONTROL                                         (0x000000B8U)
#define CSL_HTS_HWA0_PROD3_COUNT                                               (0x000000BCU)
#define CSL_HTS_HWA0_PROD4_CONTROL                                             (0x000000C8U)
#define CSL_HTS_HWA0_PROD4_BUF_CONTROL                                         (0x000000CCU)
#define CSL_HTS_HWA0_PROD4_COUNT                                               (0x000000D0U)
#define CSL_HTS_HWA0_PROD5_CONTROL                                             (0x000000DCU)
#define CSL_HTS_HWA0_PROD5_BUF_CONTROL                                         (0x000000E0U)
#define CSL_HTS_HWA0_PROD5_COUNT                                               (0x000000E4U)
#define CSL_HTS_HWA0_PROD6_CONTROL                                             (0x000000F0U)
#define CSL_HTS_HWA0_PROD6_BUF_CONTROL                                         (0x000000F4U)
#define CSL_HTS_HWA0_PROD6_COUNT                                               (0x000000F8U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL                                         (0x00000104U)
#define CSL_HTS_HWA1_HOP                                                       (0x00000108U)
#define CSL_HTS_HWA1_WDTIMER                                                   (0x0000010CU)
#define CSL_HTS_HWA1_BW_LIMITER                                                (0x00000110U)
#define CSL_HTS_HWA1_CONS0_CONTROL                                             (0x00000114U)
#define CSL_HTS_HWA1_CONS1_CONTROL                                             (0x00000118U)
#define CSL_HTS_HWA1_CONS2_CONTROL                                             (0x0000011CU)
#define CSL_HTS_HWA1_CONS3_CONTROL                                             (0x00000120U)
#define CSL_HTS_HWA1_CONS4_CONTROL                                             (0x00000124U)
#define CSL_HTS_HWA1_CONS5_CONTROL                                             (0x00000128U)
#define CSL_HTS_HWA1_PROD0_CONTROL                                             (0x0000012CU)
#define CSL_HTS_HWA1_PROD0_BUF_CONTROL                                         (0x00000130U)
#define CSL_HTS_HWA1_PROD0_COUNT                                               (0x00000134U)
#define CSL_HTS_HWA1_PA0_CONTROL                                               (0x00000138U)
#define CSL_HTS_HWA1_PA0_PRODCOUNT                                             (0x0000013CU)
#define CSL_HTS_HWA1_PROD1_CONTROL                                             (0x00000140U)
#define CSL_HTS_HWA1_PROD1_BUF_CONTROL                                         (0x00000144U)
#define CSL_HTS_HWA1_PROD1_COUNT                                               (0x00000148U)
#define CSL_HTS_HWA1_PA1_CONTROL                                               (0x0000014CU)
#define CSL_HTS_HWA1_PA1_PRODCOUNT                                             (0x00000150U)
#define CSL_HTS_HWA1_PROD2_CONTROL                                             (0x00000154U)
#define CSL_HTS_HWA1_PROD2_BUF_CONTROL                                         (0x00000158U)
#define CSL_HTS_HWA1_PROD2_COUNT                                               (0x0000015CU)
#define CSL_HTS_HWA1_PROD3_CONTROL                                             (0x00000168U)
#define CSL_HTS_HWA1_PROD3_BUF_CONTROL                                         (0x0000016CU)
#define CSL_HTS_HWA1_PROD3_COUNT                                               (0x00000170U)
#define CSL_HTS_HWA1_PROD4_CONTROL                                             (0x0000017CU)
#define CSL_HTS_HWA1_PROD4_BUF_CONTROL                                         (0x00000180U)
#define CSL_HTS_HWA1_PROD4_COUNT                                               (0x00000184U)
#define CSL_HTS_HWA1_PROD5_CONTROL                                             (0x00000190U)
#define CSL_HTS_HWA1_PROD5_BUF_CONTROL                                         (0x00000194U)
#define CSL_HTS_HWA1_PROD5_COUNT                                               (0x00000198U)
#define CSL_HTS_HWA1_PROD6_CONTROL                                             (0x000001A4U)
#define CSL_HTS_HWA1_PROD6_BUF_CONTROL                                         (0x000001A8U)
#define CSL_HTS_HWA1_PROD6_COUNT                                               (0x000001ACU)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL                                         (0x000001B8U)
#define CSL_HTS_HWA2_HOP                                                       (0x000001BCU)
#define CSL_HTS_HWA2_WDTIMER                                                   (0x000001C0U)
#define CSL_HTS_HWA2_BW_LIMITER                                                (0x000001C4U)
#define CSL_HTS_HWA2_CONS0_CONTROL                                             (0x000001C8U)
#define CSL_HTS_HWA2_CONS1_CONTROL                                             (0x000001CCU)
#define CSL_HTS_HWA2_CONS2_CONTROL                                             (0x000001D0U)
#define CSL_HTS_HWA2_PROD0_CONTROL                                             (0x000001D4U)
#define CSL_HTS_HWA2_PROD0_BUF_CONTROL                                         (0x000001D8U)
#define CSL_HTS_HWA2_PROD0_COUNT                                               (0x000001DCU)
#define CSL_HTS_HWA2_PA0_CONTROL                                               (0x000001E0U)
#define CSL_HTS_HWA2_PA0_PRODCOUNT                                             (0x000001E4U)
#define CSL_HTS_HWA2_PROD1_CONTROL                                             (0x000001E8U)
#define CSL_HTS_HWA2_PROD1_BUF_CONTROL                                         (0x000001ECU)
#define CSL_HTS_HWA2_PROD1_COUNT                                               (0x000001F0U)
#define CSL_HTS_HWA2_PA1_CONTROL                                               (0x000001F4U)
#define CSL_HTS_HWA2_PA1_PRODCOUNT                                             (0x000001F8U)
#define CSL_HTS_HWA2_PROD2_CONTROL                                             (0x000001FCU)
#define CSL_HTS_HWA2_PROD2_BUF_CONTROL                                         (0x00000200U)
#define CSL_HTS_HWA2_PROD2_COUNT                                               (0x00000204U)
#define CSL_HTS_HWA2_PA2_CONTROL                                               (0x00000208U)
#define CSL_HTS_HWA2_PA2_PRODCOUNT                                             (0x0000020CU)
#define CSL_HTS_HWA2_PROD3_CONTROL                                             (0x00000210U)
#define CSL_HTS_HWA2_PROD3_BUF_CONTROL                                         (0x00000214U)
#define CSL_HTS_HWA2_PROD3_COUNT                                               (0x00000218U)
#define CSL_HTS_HWA2_PA3_CONTROL                                               (0x0000021CU)
#define CSL_HTS_HWA2_PA3_PRODCOUNT                                             (0x00000220U)
#define CSL_HTS_HWA2_PROD4_CONTROL                                             (0x00000224U)
#define CSL_HTS_HWA2_PROD4_BUF_CONTROL                                         (0x00000228U)
#define CSL_HTS_HWA2_PROD4_COUNT                                               (0x0000022CU)
#define CSL_HTS_HWA2_PA4_CONTROL                                               (0x00000230U)
#define CSL_HTS_HWA2_PA4_PRODCOUNT                                             (0x00000234U)
#define CSL_HTS_HWA2_PROD5_CONTROL                                             (0x00000238U)
#define CSL_HTS_HWA2_PROD5_BUF_CONTROL                                         (0x0000023CU)
#define CSL_HTS_HWA2_PROD5_COUNT                                               (0x00000240U)
#define CSL_HTS_HWA2_PA5_CONTROL                                               (0x00000244U)
#define CSL_HTS_HWA2_PA5_PRODCOUNT                                             (0x00000248U)
#define CSL_HTS_HWA2_PROD6_CONTROL                                             (0x0000024CU)
#define CSL_HTS_HWA2_PROD6_BUF_CONTROL                                         (0x00000250U)
#define CSL_HTS_HWA2_PROD6_COUNT                                               (0x00000254U)
#define CSL_HTS_HWA2_PA6_CONTROL                                               (0x00000258U)
#define CSL_HTS_HWA2_PA6_PRODCOUNT                                             (0x0000025CU)
#define CSL_HTS_HWA2_PROD7_CONTROL                                             (0x00000260U)
#define CSL_HTS_HWA2_PROD7_BUF_CONTROL                                         (0x00000264U)
#define CSL_HTS_HWA2_PROD7_COUNT                                               (0x00000268U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL                                         (0x00000274U)
#define CSL_HTS_HWA3_HOP                                                       (0x00000278U)
#define CSL_HTS_HWA3_WDTIMER                                                   (0x0000027CU)
#define CSL_HTS_HWA3_BW_LIMITER                                                (0x00000280U)
#define CSL_HTS_HWA3_CONS0_CONTROL                                             (0x00000284U)
#define CSL_HTS_HWA3_CONS1_CONTROL                                             (0x00000288U)
#define CSL_HTS_HWA3_CONS2_CONTROL                                             (0x0000028CU)
#define CSL_HTS_HWA3_PROD0_CONTROL                                             (0x00000290U)
#define CSL_HTS_HWA3_PROD0_BUF_CONTROL                                         (0x00000294U)
#define CSL_HTS_HWA3_PROD0_COUNT                                               (0x00000298U)
#define CSL_HTS_HWA3_PA0_CONTROL                                               (0x0000029CU)
#define CSL_HTS_HWA3_PA0_PRODCOUNT                                             (0x000002A0U)
#define CSL_HTS_HWA3_PROD1_CONTROL                                             (0x000002A4U)
#define CSL_HTS_HWA3_PROD1_BUF_CONTROL                                         (0x000002A8U)
#define CSL_HTS_HWA3_PROD1_COUNT                                               (0x000002ACU)
#define CSL_HTS_HWA3_PA1_CONTROL                                               (0x000002B0U)
#define CSL_HTS_HWA3_PA1_PRODCOUNT                                             (0x000002B4U)
#define CSL_HTS_HWA3_PROD2_CONTROL                                             (0x000002B8U)
#define CSL_HTS_HWA3_PROD2_BUF_CONTROL                                         (0x000002BCU)
#define CSL_HTS_HWA3_PROD2_COUNT                                               (0x000002C0U)
#define CSL_HTS_HWA3_PA2_CONTROL                                               (0x000002C4U)
#define CSL_HTS_HWA3_PA2_PRODCOUNT                                             (0x000002C8U)
#define CSL_HTS_HWA3_PROD3_CONTROL                                             (0x000002CCU)
#define CSL_HTS_HWA3_PROD3_BUF_CONTROL                                         (0x000002D0U)
#define CSL_HTS_HWA3_PROD3_COUNT                                               (0x000002D4U)
#define CSL_HTS_HWA3_PA3_CONTROL                                               (0x000002D8U)
#define CSL_HTS_HWA3_PA3_PRODCOUNT                                             (0x000002DCU)
#define CSL_HTS_HWA3_PROD4_CONTROL                                             (0x000002E0U)
#define CSL_HTS_HWA3_PROD4_BUF_CONTROL                                         (0x000002E4U)
#define CSL_HTS_HWA3_PROD4_COUNT                                               (0x000002E8U)
#define CSL_HTS_HWA3_PA4_CONTROL                                               (0x000002ECU)
#define CSL_HTS_HWA3_PA4_PRODCOUNT                                             (0x000002F0U)
#define CSL_HTS_HWA3_PROD5_CONTROL                                             (0x000002F4U)
#define CSL_HTS_HWA3_PROD5_BUF_CONTROL                                         (0x000002F8U)
#define CSL_HTS_HWA3_PROD5_COUNT                                               (0x000002FCU)
#define CSL_HTS_HWA3_PA5_CONTROL                                               (0x00000300U)
#define CSL_HTS_HWA3_PA5_PRODCOUNT                                             (0x00000304U)
#define CSL_HTS_HWA3_PROD6_CONTROL                                             (0x00000308U)
#define CSL_HTS_HWA3_PROD6_BUF_CONTROL                                         (0x0000030CU)
#define CSL_HTS_HWA3_PROD6_COUNT                                               (0x00000310U)
#define CSL_HTS_HWA3_PA6_CONTROL                                               (0x00000314U)
#define CSL_HTS_HWA3_PA6_PRODCOUNT                                             (0x00000318U)
#define CSL_HTS_HWA3_PROD7_CONTROL                                             (0x0000031CU)
#define CSL_HTS_HWA3_PROD7_BUF_CONTROL                                         (0x00000320U)
#define CSL_HTS_HWA3_PROD7_COUNT                                               (0x00000324U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL                                         (0x00000330U)
#define CSL_HTS_HWA4_HOP                                                       (0x00000334U)
#define CSL_HTS_HWA4_WDTIMER                                                   (0x00000338U)
#define CSL_HTS_HWA4_BW_LIMITER                                                (0x0000033CU)
#define CSL_HTS_HWA4_CONS0_CONTROL                                             (0x00000340U)
#define CSL_HTS_HWA4_CONS1_CONTROL                                             (0x00000344U)
#define CSL_HTS_HWA4_PROD0_CONTROL                                             (0x00000348U)
#define CSL_HTS_HWA4_PROD0_BUF_CONTROL                                         (0x0000034CU)
#define CSL_HTS_HWA4_PROD0_COUNT                                               (0x00000350U)
#define CSL_HTS_HWA4_PROD1_CONTROL                                             (0x0000035CU)
#define CSL_HTS_HWA4_PROD1_BUF_CONTROL                                         (0x00000360U)
#define CSL_HTS_HWA4_PROD1_COUNT                                               (0x00000364U)
#define CSL_HTS_HWA4_PROD2_CONTROL                                             (0x00000370U)
#define CSL_HTS_HWA4_PROD2_BUF_CONTROL                                         (0x00000374U)
#define CSL_HTS_HWA4_PROD2_COUNT                                               (0x00000378U)
#define CSL_HTS_HWA4_PROD3_CONTROL                                             (0x00000384U)
#define CSL_HTS_HWA4_PROD3_BUF_CONTROL                                         (0x00000388U)
#define CSL_HTS_HWA4_PROD3_COUNT                                               (0x0000038CU)
#define CSL_HTS_HWA4_PROD4_CONTROL                                             (0x00000398U)
#define CSL_HTS_HWA4_PROD4_BUF_CONTROL                                         (0x0000039CU)
#define CSL_HTS_HWA4_PROD4_COUNT                                               (0x000003A0U)
#define CSL_HTS_HWA4_PROD5_CONTROL                                             (0x000003ACU)
#define CSL_HTS_HWA4_PROD5_BUF_CONTROL                                         (0x000003B0U)
#define CSL_HTS_HWA4_PROD5_COUNT                                               (0x000003B4U)
#define CSL_HTS_HWA4_PROD6_CONTROL                                             (0x000003C0U)
#define CSL_HTS_HWA4_PROD6_BUF_CONTROL                                         (0x000003C4U)
#define CSL_HTS_HWA4_PROD6_COUNT                                               (0x000003C8U)
#define CSL_HTS_HWA4_PROD7_CONTROL                                             (0x000003D4U)
#define CSL_HTS_HWA4_PROD7_BUF_CONTROL                                         (0x000003D8U)
#define CSL_HTS_HWA4_PROD7_COUNT                                               (0x000003DCU)
#define CSL_HTS_HWA4_PROD8_CONTROL                                             (0x000003E8U)
#define CSL_HTS_HWA4_PROD8_BUF_CONTROL                                         (0x000003ECU)
#define CSL_HTS_HWA4_PROD8_COUNT                                               (0x000003F0U)
#define CSL_HTS_HWA4_PROD9_CONTROL                                             (0x000003FCU)
#define CSL_HTS_HWA4_PROD9_BUF_CONTROL                                         (0x00000400U)
#define CSL_HTS_HWA4_PROD9_COUNT                                               (0x00000404U)
#define CSL_HTS_HWA4_PROD10_CONTROL                                            (0x00000410U)
#define CSL_HTS_HWA4_PROD10_BUF_CONTROL                                        (0x00000414U)
#define CSL_HTS_HWA4_PROD10_COUNT                                              (0x00000418U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL                                         (0x00000424U)
#define CSL_HTS_HWA5_HOP                                                       (0x00000428U)
#define CSL_HTS_HWA5_WDTIMER                                                   (0x0000042CU)
#define CSL_HTS_HWA5_BW_LIMITER                                                (0x00000430U)
#define CSL_HTS_HWA5_CONS0_CONTROL                                             (0x00000434U)
#define CSL_HTS_HWA5_CONS1_CONTROL                                             (0x00000438U)
#define CSL_HTS_HWA5_PROD0_CONTROL                                             (0x0000043CU)
#define CSL_HTS_HWA5_PROD0_BUF_CONTROL                                         (0x00000440U)
#define CSL_HTS_HWA5_PROD0_COUNT                                               (0x00000444U)
#define CSL_HTS_HWA5_PROD1_CONTROL                                             (0x00000450U)
#define CSL_HTS_HWA5_PROD1_BUF_CONTROL                                         (0x00000454U)
#define CSL_HTS_HWA5_PROD1_COUNT                                               (0x00000458U)
#define CSL_HTS_HWA5_PROD2_CONTROL                                             (0x00000464U)
#define CSL_HTS_HWA5_PROD2_BUF_CONTROL                                         (0x00000468U)
#define CSL_HTS_HWA5_PROD2_COUNT                                               (0x0000046CU)
#define CSL_HTS_HWA5_PROD3_CONTROL                                             (0x00000478U)
#define CSL_HTS_HWA5_PROD3_BUF_CONTROL                                         (0x0000047CU)
#define CSL_HTS_HWA5_PROD3_COUNT                                               (0x00000480U)
#define CSL_HTS_HWA5_PROD4_CONTROL                                             (0x0000048CU)
#define CSL_HTS_HWA5_PROD4_BUF_CONTROL                                         (0x00000490U)
#define CSL_HTS_HWA5_PROD4_COUNT                                               (0x00000494U)
#define CSL_HTS_HWA5_PROD5_CONTROL                                             (0x000004A0U)
#define CSL_HTS_HWA5_PROD5_BUF_CONTROL                                         (0x000004A4U)
#define CSL_HTS_HWA5_PROD5_COUNT                                               (0x000004A8U)
#define CSL_HTS_HWA5_PROD6_CONTROL                                             (0x000004B4U)
#define CSL_HTS_HWA5_PROD6_BUF_CONTROL                                         (0x000004B8U)
#define CSL_HTS_HWA5_PROD6_COUNT                                               (0x000004BCU)
#define CSL_HTS_HWA5_PROD7_CONTROL                                             (0x000004C8U)
#define CSL_HTS_HWA5_PROD7_BUF_CONTROL                                         (0x000004CCU)
#define CSL_HTS_HWA5_PROD7_COUNT                                               (0x000004D0U)
#define CSL_HTS_HWA5_PROD8_CONTROL                                             (0x000004DCU)
#define CSL_HTS_HWA5_PROD8_BUF_CONTROL                                         (0x000004E0U)
#define CSL_HTS_HWA5_PROD8_COUNT                                               (0x000004E4U)
#define CSL_HTS_HWA5_PROD9_CONTROL                                             (0x000004F0U)
#define CSL_HTS_HWA5_PROD9_BUF_CONTROL                                         (0x000004F4U)
#define CSL_HTS_HWA5_PROD9_COUNT                                               (0x000004F8U)
#define CSL_HTS_HWA5_PROD10_CONTROL                                            (0x00000504U)
#define CSL_HTS_HWA5_PROD10_BUF_CONTROL                                        (0x00000508U)
#define CSL_HTS_HWA5_PROD10_COUNT                                              (0x0000050CU)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL                                         (0x00000518U)
#define CSL_HTS_HWA6_HOP                                                       (0x0000051CU)
#define CSL_HTS_HWA6_WDTIMER                                                   (0x00000520U)
#define CSL_HTS_HWA6_BW_LIMITER                                                (0x00000524U)
#define CSL_HTS_HWA6_CONS0_CONTROL                                             (0x00000528U)
#define CSL_HTS_HWA6_CONS1_CONTROL                                             (0x0000052CU)
#define CSL_HTS_HWA6_PROD0_CONTROL                                             (0x00000530U)
#define CSL_HTS_HWA6_PROD0_BUF_CONTROL                                         (0x00000534U)
#define CSL_HTS_HWA6_PROD0_COUNT                                               (0x00000538U)
#define CSL_HTS_HWA6_PROD1_CONTROL                                             (0x00000544U)
#define CSL_HTS_HWA6_PROD1_BUF_CONTROL                                         (0x00000548U)
#define CSL_HTS_HWA6_PROD1_COUNT                                               (0x0000054CU)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL                                         (0x00000558U)
#define CSL_HTS_HWA7_HOP                                                       (0x0000055CU)
#define CSL_HTS_HWA7_WDTIMER                                                   (0x00000560U)
#define CSL_HTS_HWA7_BW_LIMITER                                                (0x00000564U)
#define CSL_HTS_HWA7_CONS0_CONTROL                                             (0x00000568U)
#define CSL_HTS_HWA7_CONS1_CONTROL                                             (0x0000056CU)
#define CSL_HTS_HWA7_CONS2_CONTROL                                             (0x00000570U)
#define CSL_HTS_HWA7_CONS3_CONTROL                                             (0x00000574U)
#define CSL_HTS_HWA7_CONS4_CONTROL                                             (0x00000578U)
#define CSL_HTS_HWA7_PROD0_CONTROL                                             (0x0000057CU)
#define CSL_HTS_HWA7_PROD0_BUF_CONTROL                                         (0x00000580U)
#define CSL_HTS_HWA7_PROD0_COUNT                                               (0x00000584U)
#define CSL_HTS_HWA7_PA0_CONTROL                                               (0x00000588U)
#define CSL_HTS_HWA7_PA0_PRODCOUNT                                             (0x0000058CU)
#define CSL_HTS_HWA7_PROD1_CONTROL                                             (0x00000590U)
#define CSL_HTS_HWA7_PROD1_BUF_CONTROL                                         (0x00000594U)
#define CSL_HTS_HWA7_PROD1_COUNT                                               (0x00000598U)
#define CSL_HTS_HWA7_PA1_CONTROL                                               (0x0000059CU)
#define CSL_HTS_HWA7_PA1_PRODCOUNT                                             (0x000005A0U)
#define CSL_HTS_HWA7_PROD2_CONTROL                                             (0x000005A4U)
#define CSL_HTS_HWA7_PROD2_BUF_CONTROL                                         (0x000005A8U)
#define CSL_HTS_HWA7_PROD2_COUNT                                               (0x000005ACU)
#define CSL_HTS_HWA7_PA2_CONTROL                                               (0x000005B0U)
#define CSL_HTS_HWA7_PA2_PRODCOUNT                                             (0x000005B4U)
#define CSL_HTS_HWA7_PROD3_CONTROL                                             (0x000005B8U)
#define CSL_HTS_HWA7_PROD3_BUF_CONTROL                                         (0x000005BCU)
#define CSL_HTS_HWA7_PROD3_COUNT                                               (0x000005C0U)
#define CSL_HTS_HWA7_PA3_CONTROL                                               (0x000005C4U)
#define CSL_HTS_HWA7_PA3_PRODCOUNT                                             (0x000005C8U)
#define CSL_HTS_HWA7_PROD4_CONTROL                                             (0x000005CCU)
#define CSL_HTS_HWA7_PROD4_BUF_CONTROL                                         (0x000005D0U)
#define CSL_HTS_HWA7_PROD4_COUNT                                               (0x000005D4U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL                                         (0x000005E0U)
#define CSL_HTS_HWA8_HOP                                                       (0x000005E4U)
#define CSL_HTS_HWA8_WDTIMER                                                   (0x000005E8U)
#define CSL_HTS_HWA8_BW_LIMITER                                                (0x000005ECU)
#define CSL_HTS_HWA8_CONS0_CONTROL                                             (0x000005F0U)
#define CSL_HTS_HWA8_CONS1_CONTROL                                             (0x000005F4U)
#define CSL_HTS_HWA8_CONS2_CONTROL                                             (0x000005F8U)
#define CSL_HTS_HWA8_CONS3_CONTROL                                             (0x000005FCU)
#define CSL_HTS_HWA8_CONS4_CONTROL                                             (0x00000600U)
#define CSL_HTS_HWA8_PROD0_CONTROL                                             (0x00000604U)
#define CSL_HTS_HWA8_PROD0_BUF_CONTROL                                         (0x00000608U)
#define CSL_HTS_HWA8_PROD0_COUNT                                               (0x0000060CU)
#define CSL_HTS_HWA8_PA0_CONTROL                                               (0x00000610U)
#define CSL_HTS_HWA8_PA0_PRODCOUNT                                             (0x00000614U)
#define CSL_HTS_HWA8_PROD1_CONTROL                                             (0x00000618U)
#define CSL_HTS_HWA8_PROD1_BUF_CONTROL                                         (0x0000061CU)
#define CSL_HTS_HWA8_PROD1_COUNT                                               (0x00000620U)
#define CSL_HTS_HWA8_PA1_CONTROL                                               (0x00000624U)
#define CSL_HTS_HWA8_PA1_PRODCOUNT                                             (0x00000628U)
#define CSL_HTS_HWA8_PROD2_CONTROL                                             (0x0000062CU)
#define CSL_HTS_HWA8_PROD2_BUF_CONTROL                                         (0x00000630U)
#define CSL_HTS_HWA8_PROD2_COUNT                                               (0x00000634U)
#define CSL_HTS_HWA8_PA2_CONTROL                                               (0x00000638U)
#define CSL_HTS_HWA8_PA2_PRODCOUNT                                             (0x0000063CU)
#define CSL_HTS_HWA8_PROD3_CONTROL                                             (0x00000640U)
#define CSL_HTS_HWA8_PROD3_BUF_CONTROL                                         (0x00000644U)
#define CSL_HTS_HWA8_PROD3_COUNT                                               (0x00000648U)
#define CSL_HTS_HWA8_PA3_CONTROL                                               (0x0000064CU)
#define CSL_HTS_HWA8_PA3_PRODCOUNT                                             (0x00000650U)
#define CSL_HTS_HWA8_PROD4_CONTROL                                             (0x00000654U)
#define CSL_HTS_HWA8_PROD4_BUF_CONTROL                                         (0x00000658U)
#define CSL_HTS_HWA8_PROD4_COUNT                                               (0x0000065CU)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL                                        (0x00000668U)
#define CSL_HTS_HWA12_HOP                                                      (0x0000066CU)
#define CSL_HTS_HWA12_CONS0_CONTROL                                            (0x00000678U)
#define CSL_HTS_HWA12_CONS1_CONTROL                                            (0x0000067CU)
#define CSL_HTS_HWA12_PROD0_CONTROL                                            (0x00000680U)
#define CSL_HTS_HWA12_PROD0_BUF_CONTROL                                        (0x00000684U)
#define CSL_HTS_HWA12_PROD0_COUNT                                              (0x00000688U)
#define CSL_HTS_HWA12_PA0_CONTROL                                              (0x0000068CU)
#define CSL_HTS_HWA12_PA0_PRODCOUNT                                            (0x00000690U)
#define CSL_HTS_HWA12_PROD1_CONTROL                                            (0x00000694U)
#define CSL_HTS_HWA12_PROD1_BUF_CONTROL                                        (0x00000698U)
#define CSL_HTS_HWA12_PROD1_COUNT                                              (0x0000069CU)
#define CSL_HTS_HWA12_PA1_CONTROL                                              (0x000006A0U)
#define CSL_HTS_HWA12_PA1_PRODCOUNT                                            (0x000006A4U)
#define CSL_HTS_HWA12_PROD2_CONTROL                                            (0x000006A8U)
#define CSL_HTS_HWA12_PROD2_BUF_CONTROL                                        (0x000006ACU)
#define CSL_HTS_HWA12_PROD2_COUNT                                              (0x000006B0U)
#define CSL_HTS_HWA12_PA2_CONTROL                                              (0x000006B4U)
#define CSL_HTS_HWA12_PA2_PRODCOUNT                                            (0x000006B8U)
#define CSL_HTS_HWA12_PROD3_CONTROL                                            (0x000006BCU)
#define CSL_HTS_HWA12_PROD3_BUF_CONTROL                                        (0x000006C0U)
#define CSL_HTS_HWA12_PROD3_COUNT                                              (0x000006C4U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL                                        (0x000006D0U)
#define CSL_HTS_HWA13_HOP                                                      (0x000006D4U)
#define CSL_HTS_HWA13_CONS0_CONTROL                                            (0x000006E0U)
#define CSL_HTS_HWA13_CONS1_CONTROL                                            (0x000006E4U)
#define CSL_HTS_HWA13_PROD0_CONTROL                                            (0x000006E8U)
#define CSL_HTS_HWA13_PROD0_BUF_CONTROL                                        (0x000006ECU)
#define CSL_HTS_HWA13_PROD0_COUNT                                              (0x000006F0U)
#define CSL_HTS_HWA13_PA0_CONTROL                                              (0x000006F4U)
#define CSL_HTS_HWA13_PA0_PRODCOUNT                                            (0x000006F8U)
#define CSL_HTS_HWA13_PROD1_CONTROL                                            (0x000006FCU)
#define CSL_HTS_HWA13_PROD1_BUF_CONTROL                                        (0x00000700U)
#define CSL_HTS_HWA13_PROD1_COUNT                                              (0x00000704U)
#define CSL_HTS_HWA13_PA1_CONTROL                                              (0x00000708U)
#define CSL_HTS_HWA13_PA1_PRODCOUNT                                            (0x0000070CU)
#define CSL_HTS_HWA13_PROD2_CONTROL                                            (0x00000710U)
#define CSL_HTS_HWA13_PROD2_BUF_CONTROL                                        (0x00000714U)
#define CSL_HTS_HWA13_PROD2_COUNT                                              (0x00000718U)
#define CSL_HTS_HWA13_PA2_CONTROL                                              (0x0000071CU)
#define CSL_HTS_HWA13_PA2_PRODCOUNT                                            (0x00000720U)
#define CSL_HTS_HWA13_PROD3_CONTROL                                            (0x00000724U)
#define CSL_HTS_HWA13_PROD3_BUF_CONTROL                                        (0x00000728U)
#define CSL_HTS_HWA13_PROD3_COUNT                                              (0x0000072CU)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL                                        (0x00000738U)
#define CSL_HTS_HWA14_HOP                                                      (0x0000073CU)
#define CSL_HTS_HWA14_CONS0_CONTROL                                            (0x00000748U)
#define CSL_HTS_HWA14_CONS1_CONTROL                                            (0x0000074CU)
#define CSL_HTS_HWA14_PROD0_CONTROL                                            (0x00000750U)
#define CSL_HTS_HWA14_PROD0_BUF_CONTROL                                        (0x00000754U)
#define CSL_HTS_HWA14_PROD0_COUNT                                              (0x00000758U)
#define CSL_HTS_HWA14_PA0_CONTROL                                              (0x0000075CU)
#define CSL_HTS_HWA14_PA0_PRODCOUNT                                            (0x00000760U)
#define CSL_HTS_HWA14_PROD1_CONTROL                                            (0x00000764U)
#define CSL_HTS_HWA14_PROD1_BUF_CONTROL                                        (0x00000768U)
#define CSL_HTS_HWA14_PROD1_COUNT                                              (0x0000076CU)
#define CSL_HTS_HWA14_PA1_CONTROL                                              (0x00000770U)
#define CSL_HTS_HWA14_PA1_PRODCOUNT                                            (0x00000774U)
#define CSL_HTS_HWA14_PROD2_CONTROL                                            (0x00000778U)
#define CSL_HTS_HWA14_PROD2_BUF_CONTROL                                        (0x0000077CU)
#define CSL_HTS_HWA14_PROD2_COUNT                                              (0x00000780U)
#define CSL_HTS_HWA14_PA2_CONTROL                                              (0x00000784U)
#define CSL_HTS_HWA14_PA2_PRODCOUNT                                            (0x00000788U)
#define CSL_HTS_HWA14_PROD3_CONTROL                                            (0x0000078CU)
#define CSL_HTS_HWA14_PROD3_BUF_CONTROL                                        (0x00000790U)
#define CSL_HTS_HWA14_PROD3_COUNT                                              (0x00000794U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL                                        (0x000007A0U)
#define CSL_HTS_HWA15_HOP                                                      (0x000007A4U)
#define CSL_HTS_HWA15_CONS0_CONTROL                                            (0x000007B0U)
#define CSL_HTS_HWA15_CONS1_CONTROL                                            (0x000007B4U)
#define CSL_HTS_HWA15_PROD0_CONTROL                                            (0x000007B8U)
#define CSL_HTS_HWA15_PROD0_BUF_CONTROL                                        (0x000007BCU)
#define CSL_HTS_HWA15_PROD0_COUNT                                              (0x000007C0U)
#define CSL_HTS_HWA15_PA0_CONTROL                                              (0x000007C4U)
#define CSL_HTS_HWA15_PA0_PRODCOUNT                                            (0x000007C8U)
#define CSL_HTS_HWA15_PROD1_CONTROL                                            (0x000007CCU)
#define CSL_HTS_HWA15_PROD1_BUF_CONTROL                                        (0x000007D0U)
#define CSL_HTS_HWA15_PROD1_COUNT                                              (0x000007D4U)
#define CSL_HTS_HWA15_PA1_CONTROL                                              (0x000007D8U)
#define CSL_HTS_HWA15_PA1_PRODCOUNT                                            (0x000007DCU)
#define CSL_HTS_HWA15_PROD2_CONTROL                                            (0x000007E0U)
#define CSL_HTS_HWA15_PROD2_BUF_CONTROL                                        (0x000007E4U)
#define CSL_HTS_HWA15_PROD2_COUNT                                              (0x000007E8U)
#define CSL_HTS_HWA15_PA2_CONTROL                                              (0x000007ECU)
#define CSL_HTS_HWA15_PA2_PRODCOUNT                                            (0x000007F0U)
#define CSL_HTS_HWA15_PROD3_CONTROL                                            (0x000007F4U)
#define CSL_HTS_HWA15_PROD3_BUF_CONTROL                                        (0x000007F8U)
#define CSL_HTS_HWA15_PROD3_COUNT                                              (0x000007FCU)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL                                        (0x00000808U)
#define CSL_HTS_HWA16_HOP                                                      (0x0000080CU)
#define CSL_HTS_HWA16_CONS0_CONTROL                                            (0x00000818U)
#define CSL_HTS_HWA16_CONS1_CONTROL                                            (0x0000081CU)
#define CSL_HTS_HWA16_PROD0_CONTROL                                            (0x00000820U)
#define CSL_HTS_HWA16_PROD0_BUF_CONTROL                                        (0x00000824U)
#define CSL_HTS_HWA16_PROD0_COUNT                                              (0x00000828U)
#define CSL_HTS_HWA16_PA0_CONTROL                                              (0x0000082CU)
#define CSL_HTS_HWA16_PA0_PRODCOUNT                                            (0x00000830U)
#define CSL_HTS_HWA16_PROD1_CONTROL                                            (0x00000834U)
#define CSL_HTS_HWA16_PROD1_BUF_CONTROL                                        (0x00000838U)
#define CSL_HTS_HWA16_PROD1_COUNT                                              (0x0000083CU)
#define CSL_HTS_HWA16_PA1_CONTROL                                              (0x00000840U)
#define CSL_HTS_HWA16_PA1_PRODCOUNT                                            (0x00000844U)
#define CSL_HTS_HWA16_PROD2_CONTROL                                            (0x00000848U)
#define CSL_HTS_HWA16_PROD2_BUF_CONTROL                                        (0x0000084CU)
#define CSL_HTS_HWA16_PROD2_COUNT                                              (0x00000850U)
#define CSL_HTS_HWA16_PA2_CONTROL                                              (0x00000854U)
#define CSL_HTS_HWA16_PA2_PRODCOUNT                                            (0x00000858U)
#define CSL_HTS_HWA16_PROD3_CONTROL                                            (0x0000085CU)
#define CSL_HTS_HWA16_PROD3_BUF_CONTROL                                        (0x00000860U)
#define CSL_HTS_HWA16_PROD3_COUNT                                              (0x00000864U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL                                        (0x00000870U)
#define CSL_HTS_HWA17_HOP                                                      (0x00000874U)
#define CSL_HTS_HWA17_CONS0_CONTROL                                            (0x00000880U)
#define CSL_HTS_HWA17_CONS1_CONTROL                                            (0x00000884U)
#define CSL_HTS_HWA17_PROD0_CONTROL                                            (0x00000888U)
#define CSL_HTS_HWA17_PROD0_BUF_CONTROL                                        (0x0000088CU)
#define CSL_HTS_HWA17_PROD0_COUNT                                              (0x00000890U)
#define CSL_HTS_HWA17_PA0_CONTROL                                              (0x00000894U)
#define CSL_HTS_HWA17_PA0_PRODCOUNT                                            (0x00000898U)
#define CSL_HTS_HWA17_PROD1_CONTROL                                            (0x0000089CU)
#define CSL_HTS_HWA17_PROD1_BUF_CONTROL                                        (0x000008A0U)
#define CSL_HTS_HWA17_PROD1_COUNT                                              (0x000008A4U)
#define CSL_HTS_HWA17_PA1_CONTROL                                              (0x000008A8U)
#define CSL_HTS_HWA17_PA1_PRODCOUNT                                            (0x000008ACU)
#define CSL_HTS_HWA17_PROD2_CONTROL                                            (0x000008B0U)
#define CSL_HTS_HWA17_PROD2_BUF_CONTROL                                        (0x000008B4U)
#define CSL_HTS_HWA17_PROD2_COUNT                                              (0x000008B8U)
#define CSL_HTS_HWA17_PA2_CONTROL                                              (0x000008BCU)
#define CSL_HTS_HWA17_PA2_PRODCOUNT                                            (0x000008C0U)
#define CSL_HTS_HWA17_PROD3_CONTROL                                            (0x000008C4U)
#define CSL_HTS_HWA17_PROD3_BUF_CONTROL                                        (0x000008C8U)
#define CSL_HTS_HWA17_PROD3_COUNT                                              (0x000008CCU)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL                                        (0x000008D8U)
#define CSL_HTS_HWA18_HOP                                                      (0x000008DCU)
#define CSL_HTS_HWA18_CONS0_CONTROL                                            (0x000008E8U)
#define CSL_HTS_HWA18_CONS1_CONTROL                                            (0x000008ECU)
#define CSL_HTS_HWA18_PROD0_CONTROL                                            (0x000008F0U)
#define CSL_HTS_HWA18_PROD0_BUF_CONTROL                                        (0x000008F4U)
#define CSL_HTS_HWA18_PROD0_COUNT                                              (0x000008F8U)
#define CSL_HTS_HWA18_PA0_CONTROL                                              (0x000008FCU)
#define CSL_HTS_HWA18_PA0_PRODCOUNT                                            (0x00000900U)
#define CSL_HTS_HWA18_PROD1_CONTROL                                            (0x00000904U)
#define CSL_HTS_HWA18_PROD1_BUF_CONTROL                                        (0x00000908U)
#define CSL_HTS_HWA18_PROD1_COUNT                                              (0x0000090CU)
#define CSL_HTS_HWA18_PA1_CONTROL                                              (0x00000910U)
#define CSL_HTS_HWA18_PA1_PRODCOUNT                                            (0x00000914U)
#define CSL_HTS_HWA18_PROD2_CONTROL                                            (0x00000918U)
#define CSL_HTS_HWA18_PROD2_BUF_CONTROL                                        (0x0000091CU)
#define CSL_HTS_HWA18_PROD2_COUNT                                              (0x00000920U)
#define CSL_HTS_HWA18_PA2_CONTROL                                              (0x00000924U)
#define CSL_HTS_HWA18_PA2_PRODCOUNT                                            (0x00000928U)
#define CSL_HTS_HWA18_PROD3_CONTROL                                            (0x0000092CU)
#define CSL_HTS_HWA18_PROD3_BUF_CONTROL                                        (0x00000930U)
#define CSL_HTS_HWA18_PROD3_COUNT                                              (0x00000934U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL                                        (0x00000940U)
#define CSL_HTS_HWA19_HOP                                                      (0x00000944U)
#define CSL_HTS_HWA19_CONS0_CONTROL                                            (0x00000950U)
#define CSL_HTS_HWA19_CONS1_CONTROL                                            (0x00000954U)
#define CSL_HTS_HWA19_PROD0_CONTROL                                            (0x00000958U)
#define CSL_HTS_HWA19_PROD0_BUF_CONTROL                                        (0x0000095CU)
#define CSL_HTS_HWA19_PROD0_COUNT                                              (0x00000960U)
#define CSL_HTS_HWA19_PA0_CONTROL                                              (0x00000964U)
#define CSL_HTS_HWA19_PA0_PRODCOUNT                                            (0x00000968U)
#define CSL_HTS_HWA19_PROD1_CONTROL                                            (0x0000096CU)
#define CSL_HTS_HWA19_PROD1_BUF_CONTROL                                        (0x00000970U)
#define CSL_HTS_HWA19_PROD1_COUNT                                              (0x00000974U)
#define CSL_HTS_HWA19_PA1_CONTROL                                              (0x00000978U)
#define CSL_HTS_HWA19_PA1_PRODCOUNT                                            (0x0000097CU)
#define CSL_HTS_HWA19_PROD2_CONTROL                                            (0x00000980U)
#define CSL_HTS_HWA19_PROD2_BUF_CONTROL                                        (0x00000984U)
#define CSL_HTS_HWA19_PROD2_COUNT                                              (0x00000988U)
#define CSL_HTS_HWA19_PA2_CONTROL                                              (0x0000098CU)
#define CSL_HTS_HWA19_PA2_PRODCOUNT                                            (0x00000990U)
#define CSL_HTS_HWA19_PROD3_CONTROL                                            (0x00000994U)
#define CSL_HTS_HWA19_PROD3_BUF_CONTROL                                        (0x00000998U)
#define CSL_HTS_HWA19_PROD3_COUNT                                              (0x0000099CU)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL                                         (0x000009A8U)
#define CSL_HTS_DMA0_HOP                                                       (0x000009ACU)
#define CSL_HTS_DMA0_PROD0_CONTROL                                             (0x000009B8U)
#define CSL_HTS_DMA0_PROD0_BUF_CONTROL                                         (0x000009BCU)
#define CSL_HTS_DMA0_PROD0_COUNT                                               (0x000009C0U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL                                         (0x000009C4U)
#define CSL_HTS_DMA1_HOP                                                       (0x000009C8U)
#define CSL_HTS_DMA1_PROD0_CONTROL                                             (0x000009D4U)
#define CSL_HTS_DMA1_PROD0_BUF_CONTROL                                         (0x000009D8U)
#define CSL_HTS_DMA1_PROD0_COUNT                                               (0x000009DCU)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL                                         (0x000009E0U)
#define CSL_HTS_DMA2_HOP                                                       (0x000009E4U)
#define CSL_HTS_DMA2_PROD0_CONTROL                                             (0x000009F0U)
#define CSL_HTS_DMA2_PROD0_BUF_CONTROL                                         (0x000009F4U)
#define CSL_HTS_DMA2_PROD0_COUNT                                               (0x000009F8U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL                                         (0x000009FCU)
#define CSL_HTS_DMA3_HOP                                                       (0x00000A00U)
#define CSL_HTS_DMA3_PROD0_CONTROL                                             (0x00000A0CU)
#define CSL_HTS_DMA3_PROD0_BUF_CONTROL                                         (0x00000A10U)
#define CSL_HTS_DMA3_PROD0_COUNT                                               (0x00000A14U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL                                         (0x00000A18U)
#define CSL_HTS_DMA4_HOP                                                       (0x00000A1CU)
#define CSL_HTS_DMA4_PROD0_CONTROL                                             (0x00000A28U)
#define CSL_HTS_DMA4_PROD0_BUF_CONTROL                                         (0x00000A2CU)
#define CSL_HTS_DMA4_PROD0_COUNT                                               (0x00000A30U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL                                         (0x00000A88U)
#define CSL_HTS_DMA8_HOP                                                       (0x00000A8CU)
#define CSL_HTS_DMA8_PROD0_CONTROL                                             (0x00000A98U)
#define CSL_HTS_DMA8_PROD0_BUF_CONTROL                                         (0x00000A9CU)
#define CSL_HTS_DMA8_PROD0_COUNT                                               (0x00000AA0U)
#define CSL_HTS_DMA8_PA0_CONTROL                                               (0x00000AA4U)
#define CSL_HTS_DMA8_PA0_PRODCOUNT                                             (0x00000AA8U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL                                         (0x00000AACU)
#define CSL_HTS_DMA9_HOP                                                       (0x00000AB0U)
#define CSL_HTS_DMA9_PROD0_CONTROL                                             (0x00000ABCU)
#define CSL_HTS_DMA9_PROD0_BUF_CONTROL                                         (0x00000AC0U)
#define CSL_HTS_DMA9_PROD0_COUNT                                               (0x00000AC4U)
#define CSL_HTS_DMA9_PA0_CONTROL                                               (0x00000AC8U)
#define CSL_HTS_DMA9_PA0_PRODCOUNT                                             (0x00000ACCU)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL                                        (0x00000AD0U)
#define CSL_HTS_DMA10_HOP                                                      (0x00000AD4U)
#define CSL_HTS_DMA10_PROD0_CONTROL                                            (0x00000AE0U)
#define CSL_HTS_DMA10_PROD0_BUF_CONTROL                                        (0x00000AE4U)
#define CSL_HTS_DMA10_PROD0_COUNT                                              (0x00000AE8U)
#define CSL_HTS_DMA10_PA0_CONTROL                                              (0x00000AECU)
#define CSL_HTS_DMA10_PA0_PRODCOUNT                                            (0x00000AF0U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL                                        (0x00000D40U)
#define CSL_HTS_DMA32_HOP                                                      (0x00000D44U)
#define CSL_HTS_DMA32_PROD0_CONTROL                                            (0x00000D50U)
#define CSL_HTS_DMA32_PROD0_BUF_CONTROL                                        (0x00000D54U)
#define CSL_HTS_DMA32_PROD0_COUNT                                              (0x00000D58U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL                                        (0x00000E20U)
#define CSL_HTS_DMA40_HOP                                                      (0x00000E24U)
#define CSL_HTS_DMA40_PROD0_CONTROL                                            (0x00000E30U)
#define CSL_HTS_DMA40_PROD0_BUF_CONTROL                                        (0x00000E34U)
#define CSL_HTS_DMA40_PROD0_COUNT                                              (0x00000E38U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL                                        (0x00000F00U)
#define CSL_HTS_DMA48_HOP                                                      (0x00000F04U)
#define CSL_HTS_DMA48_PROD0_CONTROL                                            (0x00000F10U)
#define CSL_HTS_DMA48_PROD0_BUF_CONTROL                                        (0x00000F14U)
#define CSL_HTS_DMA48_PROD0_COUNT                                              (0x00000F18U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL                                        (0x00000FE0U)
#define CSL_HTS_DMA56_HOP                                                      (0x00000FE4U)
#define CSL_HTS_DMA56_PROD0_CONTROL                                            (0x00000FF0U)
#define CSL_HTS_DMA56_PROD0_BUF_CONTROL                                        (0x00000FF4U)
#define CSL_HTS_DMA56_PROD0_COUNT                                              (0x00000FF8U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL                                        (0x00000FFCU)
#define CSL_HTS_DMA57_HOP                                                      (0x00001000U)
#define CSL_HTS_DMA57_PROD0_CONTROL                                            (0x0000100CU)
#define CSL_HTS_DMA57_PROD0_BUF_CONTROL                                        (0x00001010U)
#define CSL_HTS_DMA57_PROD0_COUNT                                              (0x00001014U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL                                        (0x00001018U)
#define CSL_HTS_DMA58_HOP                                                      (0x0000101CU)
#define CSL_HTS_DMA58_PROD0_CONTROL                                            (0x00001028U)
#define CSL_HTS_DMA58_PROD0_BUF_CONTROL                                        (0x0000102CU)
#define CSL_HTS_DMA58_PROD0_COUNT                                              (0x00001030U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL                                        (0x00001034U)
#define CSL_HTS_DMA59_HOP                                                      (0x00001038U)
#define CSL_HTS_DMA59_PROD0_CONTROL                                            (0x00001044U)
#define CSL_HTS_DMA59_PROD0_BUF_CONTROL                                        (0x00001048U)
#define CSL_HTS_DMA59_PROD0_COUNT                                              (0x0000104CU)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL                                        (0x000010C0U)
#define CSL_HTS_DMA64_HOP                                                      (0x000010C4U)
#define CSL_HTS_DMA64_PROD0_CONTROL                                            (0x000010D0U)
#define CSL_HTS_DMA64_PROD0_BUF_CONTROL                                        (0x000010D4U)
#define CSL_HTS_DMA64_PROD0_COUNT                                              (0x000010D8U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL                                        (0x000010DCU)
#define CSL_HTS_DMA65_HOP                                                      (0x000010E0U)
#define CSL_HTS_DMA65_PROD0_CONTROL                                            (0x000010ECU)
#define CSL_HTS_DMA65_PROD0_BUF_CONTROL                                        (0x000010F0U)
#define CSL_HTS_DMA65_PROD0_COUNT                                              (0x000010F4U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL                                        (0x000010F8U)
#define CSL_HTS_DMA66_HOP                                                      (0x000010FCU)
#define CSL_HTS_DMA66_PROD0_CONTROL                                            (0x00001108U)
#define CSL_HTS_DMA66_PROD0_BUF_CONTROL                                        (0x0000110CU)
#define CSL_HTS_DMA66_PROD0_COUNT                                              (0x00001110U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL                                        (0x00001114U)
#define CSL_HTS_DMA67_HOP                                                      (0x00001118U)
#define CSL_HTS_DMA67_PROD0_CONTROL                                            (0x00001124U)
#define CSL_HTS_DMA67_PROD0_BUF_CONTROL                                        (0x00001128U)
#define CSL_HTS_DMA67_PROD0_COUNT                                              (0x0000112CU)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL                                       (0x000021B4U)
#define CSL_HTS_DMA240_CONS0_CONTROL                                           (0x000021C4U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL                                       (0x000021C8U)
#define CSL_HTS_DMA241_CONS0_CONTROL                                           (0x000021D8U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL                                       (0x000021DCU)
#define CSL_HTS_DMA242_CONS0_CONTROL                                           (0x000021ECU)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL                                       (0x000021F0U)
#define CSL_HTS_DMA243_CONS0_CONTROL                                           (0x00002200U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL                                       (0x00002204U)
#define CSL_HTS_DMA244_CONS0_CONTROL                                           (0x00002214U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL                                       (0x00002218U)
#define CSL_HTS_DMA245_CONS0_CONTROL                                           (0x00002228U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL                                       (0x0000222CU)
#define CSL_HTS_DMA256_CONS0_CONTROL                                           (0x0000223CU)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL                                       (0x00002240U)
#define CSL_HTS_DMA257_CONS0_CONTROL                                           (0x00002250U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL                                       (0x00002254U)
#define CSL_HTS_DMA258_CONS0_CONTROL                                           (0x00002264U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL                                       (0x00002268U)
#define CSL_HTS_DMA259_CONS0_CONTROL                                           (0x00002278U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL                                       (0x0000227CU)
#define CSL_HTS_DMA260_CONS0_CONTROL                                           (0x0000228CU)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL                                       (0x00002290U)
#define CSL_HTS_DMA261_CONS0_CONTROL                                           (0x000022A0U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL                                       (0x000022A4U)
#define CSL_HTS_DMA272_CONS0_CONTROL                                           (0x000022B4U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL                                       (0x000022B8U)
#define CSL_HTS_DMA273_CONS0_CONTROL                                           (0x000022C8U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL                                       (0x000022CCU)
#define CSL_HTS_DMA274_CONS0_CONTROL                                           (0x000022DCU)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL                                       (0x000022E0U)
#define CSL_HTS_DMA275_CONS0_CONTROL                                           (0x000022F0U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL                                       (0x000022F4U)
#define CSL_HTS_DMA288_CONS0_CONTROL                                           (0x00002304U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL                                       (0x00002308U)
#define CSL_HTS_DMA289_CONS0_CONTROL                                           (0x00002318U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL                                       (0x0000231CU)
#define CSL_HTS_DMA290_CONS0_CONTROL                                           (0x0000232CU)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL                                       (0x00002330U)
#define CSL_HTS_DMA291_CONS0_CONTROL                                           (0x00002340U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL                                       (0x00002344U)
#define CSL_HTS_DMA304_CONS0_CONTROL                                           (0x00002354U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL                                       (0x00002358U)
#define CSL_HTS_DMA305_CONS0_CONTROL                                           (0x00002368U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL                                       (0x0000236CU)
#define CSL_HTS_DMA306_CONS0_CONTROL                                           (0x0000237CU)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL                                       (0x00002380U)
#define CSL_HTS_DMA307_CONS0_CONTROL                                           (0x00002390U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL                                       (0x00002394U)
#define CSL_HTS_DMA308_CONS0_CONTROL                                           (0x000023A4U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL                                       (0x000023A8U)
#define CSL_HTS_DMA309_CONS0_CONTROL                                           (0x000023B8U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL                                       (0x000023BCU)
#define CSL_HTS_DMA310_CONS0_CONTROL                                           (0x000023CCU)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL                                       (0x000023D0U)
#define CSL_HTS_DMA311_CONS0_CONTROL                                           (0x000023E0U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL                                       (0x000023E4U)
#define CSL_HTS_DMA312_CONS0_CONTROL                                           (0x000023F4U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL                                       (0x000023F8U)
#define CSL_HTS_DMA313_CONS0_CONTROL                                           (0x00002408U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL                                       (0x0000240CU)
#define CSL_HTS_DMA336_CONS0_CONTROL                                           (0x0000241CU)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL                                       (0x00002420U)
#define CSL_HTS_DMA352_CONS0_CONTROL                                           (0x00002430U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL                                       (0x00002434U)
#define CSL_HTS_DMA353_CONS0_CONTROL                                           (0x00002444U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL                                       (0x00002448U)
#define CSL_HTS_DMA354_CONS0_CONTROL                                           (0x00002458U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL                                       (0x0000245CU)
#define CSL_HTS_DMA355_CONS0_CONTROL                                           (0x0000246CU)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL                                       (0x00002470U)
#define CSL_HTS_DMA368_CONS0_CONTROL                                           (0x00002480U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL                                       (0x00002484U)
#define CSL_HTS_DMA369_CONS0_CONTROL                                           (0x00002494U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL                                       (0x00002498U)
#define CSL_HTS_DMA370_CONS0_CONTROL                                           (0x000024A8U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL                                       (0x000024ACU)
#define CSL_HTS_DMA371_CONS0_CONTROL                                           (0x000024BCU)
#define CSL_HTS_PIPE_DBG_CNTL                                                  (0x00002650U)
#define CSL_HTS_DBG_CAP                                                        (0x00002654U)
#define CSL_HTS_DBG_CNTL                                                       (0x00002658U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PIPELINE_CONTROL */

#define CSL_HTS_PIPELINE_CONTROL_PIPE_EN_MASK                                (0x00000001U)
#define CSL_HTS_PIPELINE_CONTROL_PIPE_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_PIPELINE_CONTROL_PIPE_EN_MAX                                 (0x00000001U)

/* HWA0_SCHEDULER_CONTROL */

#define CSL_HTS_HWA0_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA0_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA0_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA0_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA0_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA0_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA0_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA0_HOP */

#define CSL_HTS_HWA0_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA0_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA0_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA0_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA0_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA0_HOP_HOP_MAX                                               (0x00000001U)

/* HWA0_WDTIMER */

#define CSL_HTS_HWA0_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA0_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA0_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA0_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA0_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA0_BW_LIMITER */

#define CSL_HTS_HWA0_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA0_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA0_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA0_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA0_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA0_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA0_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA0_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA0_CONS0_CONTROL */

#define CSL_HTS_HWA0_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA0_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA0_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA0_CONS1_CONTROL */

#define CSL_HTS_HWA0_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA0_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA0_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA0_CONS2_CONTROL */

#define CSL_HTS_HWA0_CONS2_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA0_CONS2_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_CONS2_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA0_CONS2_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_CONS2_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_CONS2_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA0_CONS3_CONTROL */

#define CSL_HTS_HWA0_CONS3_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA0_CONS3_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_CONS3_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA0_CONS3_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_CONS3_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_CONS3_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA0_CONS4_CONTROL */

#define CSL_HTS_HWA0_CONS4_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA0_CONS4_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_CONS4_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA0_CONS4_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_CONS4_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_CONS4_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA0_CONS5_CONTROL */

#define CSL_HTS_HWA0_CONS5_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA0_CONS5_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_CONS5_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA0_CONS5_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_CONS5_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_CONS5_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA0_PROD0_CONTROL */

#define CSL_HTS_HWA0_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA0_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA0_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA0_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA0_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA0_PROD0_COUNT */

#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA0_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA0_PA0_CONTROL */

#define CSL_HTS_HWA0_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA0_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA0_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA0_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA0_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA0_PA0_PRODCOUNT */

#define CSL_HTS_HWA0_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA0_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA0_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA0_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA0_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA0_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA0_PROD1_CONTROL */

#define CSL_HTS_HWA0_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA0_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA0_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA0_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA0_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA0_PROD1_COUNT */

#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA0_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA0_PA1_CONTROL */

#define CSL_HTS_HWA0_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA0_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA0_PA1_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA0_PA1_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA0_PA1_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PA1_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA0_PA1_PRODCOUNT */

#define CSL_HTS_HWA0_PA1_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA0_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA0_PA1_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA0_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA0_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA0_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA0_PROD2_CONTROL */

#define CSL_HTS_HWA0_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA0_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA0_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA0_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA0_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA0_PROD2_COUNT */

#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA0_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA0_PROD3_CONTROL */

#define CSL_HTS_HWA0_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA0_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA0_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA0_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA0_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA0_PROD3_COUNT */

#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA0_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA0_PROD4_CONTROL */

#define CSL_HTS_HWA0_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA0_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA0_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA0_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA0_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA0_PROD4_COUNT */

#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA0_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA0_PROD5_CONTROL */

#define CSL_HTS_HWA0_PROD5_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA0_PROD5_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_PROD5_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA0_PROD5_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PROD5_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PROD5_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA0_PROD5_BUF_CONTROL */

#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA0_PROD5_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA0_PROD5_COUNT */

#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA0_PROD5_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA0_PROD6_CONTROL */

#define CSL_HTS_HWA0_PROD6_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA0_PROD6_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA0_PROD6_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA0_PROD6_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA0_PROD6_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA0_PROD6_CONTROL_PROD_EN_MAX                                 (0x00000001U)

#define CSL_HTS_HWA0_PROD6_CONTROL_MASK_SELECT_MASK                            (0x07000000U)
#define CSL_HTS_HWA0_PROD6_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA0_PROD6_CONTROL_MASK_SELECT_MAX                             (0x00000007U)

/* HWA0_PROD6_BUF_CONTROL */

#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA0_PROD6_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA0_PROD6_COUNT */

#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA0_PROD6_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA1_SCHEDULER_CONTROL */

#define CSL_HTS_HWA1_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA1_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA1_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA1_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA1_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA1_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA1_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA1_HOP */

#define CSL_HTS_HWA1_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA1_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA1_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA1_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA1_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA1_HOP_HOP_MAX                                               (0x00000001U)

/* HWA1_WDTIMER */

#define CSL_HTS_HWA1_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA1_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA1_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA1_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA1_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA1_BW_LIMITER */

#define CSL_HTS_HWA1_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA1_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA1_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA1_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA1_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA1_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA1_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA1_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA1_CONS0_CONTROL */

#define CSL_HTS_HWA1_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA1_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA1_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA1_CONS1_CONTROL */

#define CSL_HTS_HWA1_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA1_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA1_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA1_CONS2_CONTROL */

#define CSL_HTS_HWA1_CONS2_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA1_CONS2_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_CONS2_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA1_CONS2_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_CONS2_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_CONS2_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA1_CONS3_CONTROL */

#define CSL_HTS_HWA1_CONS3_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA1_CONS3_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_CONS3_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA1_CONS3_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_CONS3_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_CONS3_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA1_CONS4_CONTROL */

#define CSL_HTS_HWA1_CONS4_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA1_CONS4_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_CONS4_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA1_CONS4_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_CONS4_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_CONS4_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA1_CONS5_CONTROL */

#define CSL_HTS_HWA1_CONS5_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA1_CONS5_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_CONS5_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA1_CONS5_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_CONS5_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_CONS5_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA1_PROD0_CONTROL */

#define CSL_HTS_HWA1_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA1_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA1_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA1_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA1_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA1_PROD0_COUNT */

#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA1_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA1_PA0_CONTROL */

#define CSL_HTS_HWA1_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA1_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA1_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA1_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA1_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA1_PA0_PRODCOUNT */

#define CSL_HTS_HWA1_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA1_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA1_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA1_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA1_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA1_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA1_PROD1_CONTROL */

#define CSL_HTS_HWA1_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA1_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA1_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA1_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA1_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA1_PROD1_COUNT */

#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA1_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA1_PA1_CONTROL */

#define CSL_HTS_HWA1_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA1_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA1_PA1_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA1_PA1_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA1_PA1_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PA1_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA1_PA1_PRODCOUNT */

#define CSL_HTS_HWA1_PA1_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA1_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA1_PA1_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA1_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA1_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA1_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA1_PROD2_CONTROL */

#define CSL_HTS_HWA1_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA1_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA1_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA1_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA1_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA1_PROD2_COUNT */

#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA1_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA1_PROD3_CONTROL */

#define CSL_HTS_HWA1_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA1_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA1_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA1_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA1_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA1_PROD3_COUNT */

#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA1_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA1_PROD4_CONTROL */

#define CSL_HTS_HWA1_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA1_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA1_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA1_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA1_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA1_PROD4_COUNT */

#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA1_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA1_PROD5_CONTROL */

#define CSL_HTS_HWA1_PROD5_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA1_PROD5_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_PROD5_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA1_PROD5_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PROD5_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PROD5_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA1_PROD5_BUF_CONTROL */

#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA1_PROD5_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA1_PROD5_COUNT */

#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA1_PROD5_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA1_PROD6_CONTROL */

#define CSL_HTS_HWA1_PROD6_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA1_PROD6_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA1_PROD6_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA1_PROD6_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA1_PROD6_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA1_PROD6_CONTROL_PROD_EN_MAX                                 (0x00000001U)

#define CSL_HTS_HWA1_PROD6_CONTROL_MASK_SELECT_MASK                            (0x07000000U)
#define CSL_HTS_HWA1_PROD6_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA1_PROD6_CONTROL_MASK_SELECT_MAX                             (0x00000007U)

/* HWA1_PROD6_BUF_CONTROL */

#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA1_PROD6_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA1_PROD6_COUNT */

#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA1_PROD6_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_SCHEDULER_CONTROL */

#define CSL_HTS_HWA2_SCHEDULER_CONTROL_EOR_EN_MASK                             (0x00400000U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_EOR_EN_SHIFT                            (0x00000016U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_EOR_EN_MAX                              (0x00000001U)

#define CSL_HTS_HWA2_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA2_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA2_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA2_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA2_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA2_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA2_HOP */

#define CSL_HTS_HWA2_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA2_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA2_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA2_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA2_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA2_HOP_HOP_MAX                                               (0x00000001U)

/* HWA2_WDTIMER */

#define CSL_HTS_HWA2_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA2_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA2_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA2_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA2_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA2_BW_LIMITER */

#define CSL_HTS_HWA2_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA2_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA2_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA2_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA2_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA2_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA2_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA2_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA2_CONS0_CONTROL */

#define CSL_HTS_HWA2_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA2_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA2_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA2_CONS1_CONTROL */

#define CSL_HTS_HWA2_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA2_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA2_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA2_CONS2_CONTROL */

#define CSL_HTS_HWA2_CONS2_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA2_CONS2_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_CONS2_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA2_CONS2_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_CONS2_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_CONS2_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA2_PROD0_CONTROL */

#define CSL_HTS_HWA2_PROD0_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA2_PROD0_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA2_PROD0_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA2_PROD0_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA2_PROD0_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA2_PROD0_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA2_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD0_COUNT */

#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_PA0_CONTROL */

#define CSL_HTS_HWA2_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA2_PA0_PRODCOUNT */

#define CSL_HTS_HWA2_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA2_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA2_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA2_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA2_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA2_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA2_PROD1_CONTROL */

#define CSL_HTS_HWA2_PROD1_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA2_PROD1_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA2_PROD1_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA2_PROD1_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA2_PROD1_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA2_PROD1_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA2_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD1_COUNT */

#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_PA1_CONTROL */

#define CSL_HTS_HWA2_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA1_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA1_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA1_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PA1_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA2_PA1_PRODCOUNT */

#define CSL_HTS_HWA2_PA1_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA2_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA2_PA1_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA2_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA2_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA2_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA2_PROD2_CONTROL */

#define CSL_HTS_HWA2_PROD2_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA2_PROD2_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA2_PROD2_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA2_PROD2_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA2_PROD2_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA2_PROD2_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA2_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD2_COUNT */

#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_PA2_CONTROL */

#define CSL_HTS_HWA2_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA2_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA2_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA2_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PA2_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA2_PA2_PRODCOUNT */

#define CSL_HTS_HWA2_PA2_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA2_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA2_PA2_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA2_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA2_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA2_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA2_PROD3_CONTROL */

#define CSL_HTS_HWA2_PROD3_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA2_PROD3_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA2_PROD3_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA2_PROD3_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA2_PROD3_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA2_PROD3_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA2_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD3_COUNT */

#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_PA3_CONTROL */

#define CSL_HTS_HWA2_PA3_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA3_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA3_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA3_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA3_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PA3_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA2_PA3_PRODCOUNT */

#define CSL_HTS_HWA2_PA3_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA2_PA3_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA2_PA3_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA2_PA3_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA2_PA3_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA2_PA3_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA2_PROD4_CONTROL */

#define CSL_HTS_HWA2_PROD4_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA2_PROD4_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA2_PROD4_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA2_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD4_COUNT */

#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_PA4_CONTROL */

#define CSL_HTS_HWA2_PA4_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA4_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA4_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA4_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA4_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PA4_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA2_PA4_PRODCOUNT */

#define CSL_HTS_HWA2_PA4_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA2_PA4_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA2_PA4_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA2_PA4_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA2_PA4_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA2_PA4_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA2_PROD5_CONTROL */

#define CSL_HTS_HWA2_PROD5_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA2_PROD5_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA2_PROD5_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA2_PROD5_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD5_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD5_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD5_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD5_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD5_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD5_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD5_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD5_COUNT */

#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD5_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_PA5_CONTROL */

#define CSL_HTS_HWA2_PA5_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA5_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA5_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA5_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA5_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PA5_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA2_PA5_PRODCOUNT */

#define CSL_HTS_HWA2_PA5_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA2_PA5_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA2_PA5_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA2_PA5_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA2_PA5_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA2_PA5_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA2_PROD6_CONTROL */

#define CSL_HTS_HWA2_PROD6_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA2_PROD6_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA2_PROD6_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA2_PROD6_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD6_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD6_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD6_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD6_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD6_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD6_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD6_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD6_COUNT */

#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD6_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA2_PA6_CONTROL */

#define CSL_HTS_HWA2_PA6_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA6_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA2_PA6_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA6_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA2_PA6_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PA6_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA2_PA6_PRODCOUNT */

#define CSL_HTS_HWA2_PA6_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA2_PA6_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA2_PA6_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA2_PA6_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA2_PA6_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA2_PA6_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA2_PROD7_CONTROL */

#define CSL_HTS_HWA2_PROD7_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA2_PROD7_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA2_PROD7_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA2_PROD7_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA2_PROD7_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA2_PROD7_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA2_PROD7_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA2_PROD7_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA2_PROD7_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA2_PROD7_BUF_CONTROL */

#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA2_PROD7_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA2_PROD7_COUNT */

#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA2_PROD7_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_SCHEDULER_CONTROL */

#define CSL_HTS_HWA3_SCHEDULER_CONTROL_EOR_EN_MASK                             (0x00400000U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_EOR_EN_SHIFT                            (0x00000016U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_EOR_EN_MAX                              (0x00000001U)

#define CSL_HTS_HWA3_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA3_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA3_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA3_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA3_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA3_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA3_HOP */

#define CSL_HTS_HWA3_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA3_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA3_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA3_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA3_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA3_HOP_HOP_MAX                                               (0x00000001U)

/* HWA3_WDTIMER */

#define CSL_HTS_HWA3_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA3_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA3_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA3_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA3_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA3_BW_LIMITER */

#define CSL_HTS_HWA3_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA3_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA3_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA3_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA3_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA3_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA3_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA3_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA3_CONS0_CONTROL */

#define CSL_HTS_HWA3_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA3_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA3_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA3_CONS1_CONTROL */

#define CSL_HTS_HWA3_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA3_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA3_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA3_CONS2_CONTROL */

#define CSL_HTS_HWA3_CONS2_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA3_CONS2_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_CONS2_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA3_CONS2_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_CONS2_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_CONS2_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA3_PROD0_CONTROL */

#define CSL_HTS_HWA3_PROD0_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA3_PROD0_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA3_PROD0_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA3_PROD0_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA3_PROD0_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA3_PROD0_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA3_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD0_COUNT */

#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_PA0_CONTROL */

#define CSL_HTS_HWA3_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA3_PA0_PRODCOUNT */

#define CSL_HTS_HWA3_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA3_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA3_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA3_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA3_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA3_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA3_PROD1_CONTROL */

#define CSL_HTS_HWA3_PROD1_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA3_PROD1_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA3_PROD1_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA3_PROD1_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA3_PROD1_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA3_PROD1_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA3_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD1_COUNT */

#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_PA1_CONTROL */

#define CSL_HTS_HWA3_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA1_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA1_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA1_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PA1_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA3_PA1_PRODCOUNT */

#define CSL_HTS_HWA3_PA1_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA3_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA3_PA1_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA3_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA3_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA3_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA3_PROD2_CONTROL */

#define CSL_HTS_HWA3_PROD2_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA3_PROD2_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA3_PROD2_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA3_PROD2_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA3_PROD2_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA3_PROD2_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA3_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD2_COUNT */

#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_PA2_CONTROL */

#define CSL_HTS_HWA3_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA2_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA2_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA2_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PA2_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA3_PA2_PRODCOUNT */

#define CSL_HTS_HWA3_PA2_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA3_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA3_PA2_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA3_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA3_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA3_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA3_PROD3_CONTROL */

#define CSL_HTS_HWA3_PROD3_CONTROL_PARTIAL_BPR_COUNT_MASK                      (0x003C0000U)
#define CSL_HTS_HWA3_PROD3_CONTROL_PARTIAL_BPR_COUNT_SHIFT                     (0x00000012U)
#define CSL_HTS_HWA3_PROD3_CONTROL_PARTIAL_BPR_COUNT_MAX                       (0x0000000FU)

#define CSL_HTS_HWA3_PROD3_CONTROL_PARTIAL_BPR_TRIGMODE_MASK                   (0x00C00000U)
#define CSL_HTS_HWA3_PROD3_CONTROL_PARTIAL_BPR_TRIGMODE_SHIFT                  (0x00000016U)
#define CSL_HTS_HWA3_PROD3_CONTROL_PARTIAL_BPR_TRIGMODE_MAX                    (0x00000003U)

#define CSL_HTS_HWA3_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD3_COUNT */

#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_PA3_CONTROL */

#define CSL_HTS_HWA3_PA3_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA3_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA3_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA3_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA3_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PA3_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA3_PA3_PRODCOUNT */

#define CSL_HTS_HWA3_PA3_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA3_PA3_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA3_PA3_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA3_PA3_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA3_PA3_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA3_PA3_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA3_PROD4_CONTROL */

#define CSL_HTS_HWA3_PROD4_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA3_PROD4_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA3_PROD4_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA3_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD4_COUNT */

#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_PA4_CONTROL */

#define CSL_HTS_HWA3_PA4_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA4_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA4_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA4_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA4_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PA4_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA3_PA4_PRODCOUNT */

#define CSL_HTS_HWA3_PA4_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA3_PA4_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA3_PA4_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA3_PA4_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA3_PA4_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA3_PA4_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA3_PROD5_CONTROL */

#define CSL_HTS_HWA3_PROD5_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA3_PROD5_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA3_PROD5_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA3_PROD5_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD5_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD5_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD5_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD5_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD5_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD5_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD5_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD5_COUNT */

#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD5_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_PA5_CONTROL */

#define CSL_HTS_HWA3_PA5_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA5_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA5_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA5_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA5_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PA5_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA3_PA5_PRODCOUNT */

#define CSL_HTS_HWA3_PA5_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA3_PA5_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA3_PA5_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA3_PA5_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA3_PA5_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA3_PA5_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA3_PROD6_CONTROL */

#define CSL_HTS_HWA3_PROD6_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA3_PROD6_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA3_PROD6_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA3_PROD6_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD6_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD6_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD6_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD6_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD6_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD6_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD6_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD6_COUNT */

#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD6_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA3_PA6_CONTROL */

#define CSL_HTS_HWA3_PA6_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA6_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA3_PA6_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA6_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA3_PA6_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PA6_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA3_PA6_PRODCOUNT */

#define CSL_HTS_HWA3_PA6_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA3_PA6_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA3_PA6_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA3_PA6_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA3_PA6_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA3_PA6_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA3_PROD7_CONTROL */

#define CSL_HTS_HWA3_PROD7_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA3_PROD7_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA3_PROD7_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

#define CSL_HTS_HWA3_PROD7_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA3_PROD7_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA3_PROD7_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA3_PROD7_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA3_PROD7_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA3_PROD7_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA3_PROD7_BUF_CONTROL */

#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA3_PROD7_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA3_PROD7_COUNT */

#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA3_PROD7_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_SCHEDULER_CONTROL */

#define CSL_HTS_HWA4_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA4_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA4_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA4_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA4_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA4_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA4_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA4_HOP */

#define CSL_HTS_HWA4_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA4_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA4_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA4_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA4_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA4_HOP_HOP_MAX                                               (0x00000001U)

/* HWA4_WDTIMER */

#define CSL_HTS_HWA4_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA4_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA4_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA4_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA4_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA4_BW_LIMITER */

#define CSL_HTS_HWA4_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA4_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA4_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA4_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA4_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA4_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA4_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA4_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA4_CONS0_CONTROL */

#define CSL_HTS_HWA4_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA4_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA4_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA4_CONS1_CONTROL */

#define CSL_HTS_HWA4_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA4_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA4_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA4_PROD0_CONTROL */

#define CSL_HTS_HWA4_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD0_COUNT */

#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD1_CONTROL */

#define CSL_HTS_HWA4_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD1_COUNT */

#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD2_CONTROL */

#define CSL_HTS_HWA4_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD2_COUNT */

#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD3_CONTROL */

#define CSL_HTS_HWA4_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD3_COUNT */

#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD4_CONTROL */

#define CSL_HTS_HWA4_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD4_COUNT */

#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD5_CONTROL */

#define CSL_HTS_HWA4_PROD5_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD5_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD5_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD5_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD5_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD5_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD5_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD5_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD5_COUNT */

#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD5_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD6_CONTROL */

#define CSL_HTS_HWA4_PROD6_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD6_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD6_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD6_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD6_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD6_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD6_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD6_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD6_COUNT */

#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD6_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD7_CONTROL */

#define CSL_HTS_HWA4_PROD7_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD7_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD7_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD7_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD7_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD7_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD7_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD7_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD7_COUNT */

#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD7_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD8_CONTROL */

#define CSL_HTS_HWA4_PROD8_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD8_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD8_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD8_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD8_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD8_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD8_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD8_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD8_COUNT */

#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD8_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD9_CONTROL */

#define CSL_HTS_HWA4_PROD9_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA4_PROD9_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA4_PROD9_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA4_PROD9_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA4_PROD9_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA4_PROD9_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA4_PROD9_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA4_PROD9_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA4_PROD9_COUNT */

#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA4_PROD9_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA4_PROD10_CONTROL */

#define CSL_HTS_HWA4_PROD10_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA4_PROD10_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA4_PROD10_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA4_PROD10_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA4_PROD10_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA4_PROD10_CONTROL_PROD_EN_MAX                                (0x00000001U)

#define CSL_HTS_HWA4_PROD10_CONTROL_MASK_SELECT_MASK                           (0x0F000000U)
#define CSL_HTS_HWA4_PROD10_CONTROL_MASK_SELECT_SHIFT                          (0x00000018U)
#define CSL_HTS_HWA4_PROD10_CONTROL_MASK_SELECT_MAX                            (0x0000000FU)

/* HWA4_PROD10_BUF_CONTROL */

#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA4_PROD10_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA4_PROD10_COUNT */

#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA4_PROD10_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA5_SCHEDULER_CONTROL */

#define CSL_HTS_HWA5_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA5_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA5_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA5_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA5_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA5_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA5_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA5_HOP */

#define CSL_HTS_HWA5_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA5_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA5_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA5_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA5_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA5_HOP_HOP_MAX                                               (0x00000001U)

/* HWA5_WDTIMER */

#define CSL_HTS_HWA5_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA5_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA5_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA5_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA5_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA5_BW_LIMITER */

#define CSL_HTS_HWA5_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA5_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA5_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA5_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA5_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA5_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA5_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA5_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA5_CONS0_CONTROL */

#define CSL_HTS_HWA5_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA5_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA5_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA5_CONS1_CONTROL */

#define CSL_HTS_HWA5_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA5_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA5_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA5_PROD0_CONTROL */

#define CSL_HTS_HWA5_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD0_COUNT */

#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD1_CONTROL */

#define CSL_HTS_HWA5_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD1_COUNT */

#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD2_CONTROL */

#define CSL_HTS_HWA5_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD2_COUNT */

#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD3_CONTROL */

#define CSL_HTS_HWA5_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD3_COUNT */

#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD4_CONTROL */

#define CSL_HTS_HWA5_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD4_COUNT */

#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD5_CONTROL */

#define CSL_HTS_HWA5_PROD5_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD5_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD5_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD5_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD5_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD5_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD5_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD5_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD5_COUNT */

#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD5_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD6_CONTROL */

#define CSL_HTS_HWA5_PROD6_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD6_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD6_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD6_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD6_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD6_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD6_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD6_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD6_COUNT */

#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD6_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD7_CONTROL */

#define CSL_HTS_HWA5_PROD7_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD7_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD7_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD7_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD7_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD7_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD7_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD7_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD7_COUNT */

#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD7_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD8_CONTROL */

#define CSL_HTS_HWA5_PROD8_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD8_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD8_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD8_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD8_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD8_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD8_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD8_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD8_COUNT */

#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD8_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD9_CONTROL */

#define CSL_HTS_HWA5_PROD9_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA5_PROD9_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA5_PROD9_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA5_PROD9_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA5_PROD9_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA5_PROD9_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA5_PROD9_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA5_PROD9_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA5_PROD9_COUNT */

#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA5_PROD9_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA5_PROD10_CONTROL */

#define CSL_HTS_HWA5_PROD10_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA5_PROD10_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA5_PROD10_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA5_PROD10_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA5_PROD10_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA5_PROD10_CONTROL_PROD_EN_MAX                                (0x00000001U)

#define CSL_HTS_HWA5_PROD10_CONTROL_MASK_SELECT_MASK                           (0x0F000000U)
#define CSL_HTS_HWA5_PROD10_CONTROL_MASK_SELECT_SHIFT                          (0x00000018U)
#define CSL_HTS_HWA5_PROD10_CONTROL_MASK_SELECT_MAX                            (0x0000000FU)

/* HWA5_PROD10_BUF_CONTROL */

#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA5_PROD10_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA5_PROD10_COUNT */

#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA5_PROD10_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA6_SCHEDULER_CONTROL */

#define CSL_HTS_HWA6_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA6_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA6_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA6_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA6_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA6_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA6_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA6_HOP */

#define CSL_HTS_HWA6_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA6_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA6_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA6_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA6_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA6_HOP_HOP_MAX                                               (0x00000001U)

/* HWA6_WDTIMER */

#define CSL_HTS_HWA6_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA6_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA6_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA6_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA6_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA6_BW_LIMITER */

#define CSL_HTS_HWA6_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA6_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA6_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA6_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA6_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA6_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA6_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA6_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA6_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA6_CONS0_CONTROL */

#define CSL_HTS_HWA6_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA6_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA6_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA6_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA6_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA6_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA6_CONS1_CONTROL */

#define CSL_HTS_HWA6_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA6_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA6_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA6_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA6_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA6_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA6_PROD0_CONTROL */

#define CSL_HTS_HWA6_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA6_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA6_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA6_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA6_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA6_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA6_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA6_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA6_PROD0_COUNT */

#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA6_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA6_PROD1_CONTROL */

#define CSL_HTS_HWA6_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA6_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA6_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA6_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA6_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA6_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA6_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA6_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA6_PROD1_COUNT */

#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA6_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA7_SCHEDULER_CONTROL */

#define CSL_HTS_HWA7_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA7_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA7_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA7_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA7_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA7_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA7_HOP */

#define CSL_HTS_HWA7_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA7_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA7_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA7_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA7_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA7_HOP_HOP_MAX                                               (0x00000001U)

/* HWA7_WDTIMER */

#define CSL_HTS_HWA7_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA7_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA7_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA7_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA7_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA7_BW_LIMITER */

#define CSL_HTS_HWA7_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA7_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA7_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA7_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA7_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA7_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA7_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA7_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA7_CONS0_CONTROL */

#define CSL_HTS_HWA7_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA7_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA7_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA7_CONS1_CONTROL */

#define CSL_HTS_HWA7_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA7_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA7_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA7_CONS2_CONTROL */

#define CSL_HTS_HWA7_CONS2_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA7_CONS2_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_CONS2_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA7_CONS2_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_CONS2_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_CONS2_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA7_CONS3_CONTROL */

#define CSL_HTS_HWA7_CONS3_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA7_CONS3_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_CONS3_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA7_CONS3_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_CONS3_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_CONS3_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA7_CONS4_CONTROL */

#define CSL_HTS_HWA7_CONS4_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA7_CONS4_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_CONS4_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA7_CONS4_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_CONS4_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_CONS4_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA7_PROD0_CONTROL */

#define CSL_HTS_HWA7_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA7_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA7_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA7_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA7_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA7_PROD0_COUNT */

#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA7_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA7_PA0_CONTROL */

#define CSL_HTS_HWA7_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA7_PA0_PRODCOUNT */

#define CSL_HTS_HWA7_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA7_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA7_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA7_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA7_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA7_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA7_PROD1_CONTROL */

#define CSL_HTS_HWA7_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA7_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA7_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA7_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA7_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA7_PROD1_COUNT */

#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA7_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA7_PA1_CONTROL */

#define CSL_HTS_HWA7_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA1_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA1_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA1_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PA1_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA7_PA1_PRODCOUNT */

#define CSL_HTS_HWA7_PA1_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA7_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA7_PA1_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA7_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA7_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA7_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA7_PROD2_CONTROL */

#define CSL_HTS_HWA7_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA7_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA7_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA7_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA7_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA7_PROD2_COUNT */

#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA7_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA7_PA2_CONTROL */

#define CSL_HTS_HWA7_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA2_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA2_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA2_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PA2_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA7_PA2_PRODCOUNT */

#define CSL_HTS_HWA7_PA2_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA7_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA7_PA2_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA7_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA7_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA7_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA7_PROD3_CONTROL */

#define CSL_HTS_HWA7_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA7_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA7_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA7_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA7_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA7_PROD3_COUNT */

#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA7_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA7_PA3_CONTROL */

#define CSL_HTS_HWA7_PA3_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA3_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA7_PA3_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA3_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA7_PA3_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PA3_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA7_PA3_PRODCOUNT */

#define CSL_HTS_HWA7_PA3_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA7_PA3_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA7_PA3_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA7_PA3_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA7_PA3_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA7_PA3_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA7_PROD4_CONTROL */

#define CSL_HTS_HWA7_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA7_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA7_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA7_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA7_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA7_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

#define CSL_HTS_HWA7_PROD4_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA7_PROD4_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA7_PROD4_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

/* HWA7_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA7_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA7_PROD4_COUNT */

#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA7_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA8_SCHEDULER_CONTROL */

#define CSL_HTS_HWA8_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_HWA8_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_HWA8_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_HWA8_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_HWA8_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA8_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* HWA8_HOP */

#define CSL_HTS_HWA8_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_HWA8_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_HWA8_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_HWA8_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_HWA8_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_HWA8_HOP_HOP_MAX                                               (0x00000001U)

/* HWA8_WDTIMER */

#define CSL_HTS_HWA8_WDTIMER_WDTIMER_COUNT_MASK                                (0x01FFFF00U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_COUNT_SHIFT                               (0x00000008U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_COUNT_MAX                                 (0x0001FFFFU)

#define CSL_HTS_HWA8_WDTIMER_WDTIMER_MODE_MASK                                 (0x00000004U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_MODE_SHIFT                                (0x00000002U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_MODE_MAX                                  (0x00000001U)

#define CSL_HTS_HWA8_WDTIMER_WDTIMER_STATUS_MASK                               (0x00000002U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_STATUS_SHIFT                              (0x00000001U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_STATUS_MAX                                (0x00000001U)

#define CSL_HTS_HWA8_WDTIMER_WDTIMER_EN_MASK                                   (0x00000001U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_EN_SHIFT                                  (0x00000000U)
#define CSL_HTS_HWA8_WDTIMER_WDTIMER_EN_MAX                                    (0x00000001U)

/* HWA8_BW_LIMITER */

#define CSL_HTS_HWA8_BW_LIMITER_BW_CYCLE_COUNT_MASK                            (0x007FFF00U)
#define CSL_HTS_HWA8_BW_LIMITER_BW_CYCLE_COUNT_SHIFT                           (0x00000008U)
#define CSL_HTS_HWA8_BW_LIMITER_BW_CYCLE_COUNT_MAX                             (0x00007FFFU)

#define CSL_HTS_HWA8_BW_LIMITER_BW_TOKEN_COUNT_MASK                            (0x0000001EU)
#define CSL_HTS_HWA8_BW_LIMITER_BW_TOKEN_COUNT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_BW_LIMITER_BW_TOKEN_COUNT_MAX                             (0x0000000FU)

#define CSL_HTS_HWA8_BW_LIMITER_BW_LIMITER_EN_MASK                             (0x00000001U)
#define CSL_HTS_HWA8_BW_LIMITER_BW_LIMITER_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA8_BW_LIMITER_BW_LIMITER_EN_MAX                              (0x00000001U)

/* HWA8_CONS0_CONTROL */

#define CSL_HTS_HWA8_CONS0_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA8_CONS0_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_CONS0_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA8_CONS0_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_CONS0_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_CONS0_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA8_CONS1_CONTROL */

#define CSL_HTS_HWA8_CONS1_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA8_CONS1_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_CONS1_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA8_CONS1_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_CONS1_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_CONS1_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA8_CONS2_CONTROL */

#define CSL_HTS_HWA8_CONS2_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA8_CONS2_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_CONS2_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA8_CONS2_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_CONS2_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_CONS2_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA8_CONS3_CONTROL */

#define CSL_HTS_HWA8_CONS3_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA8_CONS3_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_CONS3_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA8_CONS3_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_CONS3_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_CONS3_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA8_CONS4_CONTROL */

#define CSL_HTS_HWA8_CONS4_CONTROL_PROD_SELECT_MASK                            (0x000003FEU)
#define CSL_HTS_HWA8_CONS4_CONTROL_PROD_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_CONS4_CONTROL_PROD_SELECT_MAX                             (0x000001FFU)

#define CSL_HTS_HWA8_CONS4_CONTROL_CONS_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_CONS4_CONTROL_CONS_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_CONS4_CONTROL_CONS_EN_MAX                                 (0x00000001U)

/* HWA8_PROD0_CONTROL */

#define CSL_HTS_HWA8_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA8_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA8_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA8_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA8_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA8_PROD0_COUNT */

#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA8_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA8_PA0_CONTROL */

#define CSL_HTS_HWA8_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA8_PA0_PRODCOUNT */

#define CSL_HTS_HWA8_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA8_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA8_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA8_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA8_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA8_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA8_PROD1_CONTROL */

#define CSL_HTS_HWA8_PROD1_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA8_PROD1_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_PROD1_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA8_PROD1_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PROD1_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PROD1_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA8_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA8_PROD1_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA8_PROD1_COUNT */

#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA8_PROD1_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA8_PA1_CONTROL */

#define CSL_HTS_HWA8_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA1_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA1_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA1_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PA1_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA8_PA1_PRODCOUNT */

#define CSL_HTS_HWA8_PA1_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA8_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA8_PA1_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA8_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA8_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA8_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA8_PROD2_CONTROL */

#define CSL_HTS_HWA8_PROD2_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA8_PROD2_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_PROD2_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA8_PROD2_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PROD2_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PROD2_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA8_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA8_PROD2_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA8_PROD2_COUNT */

#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA8_PROD2_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA8_PA2_CONTROL */

#define CSL_HTS_HWA8_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA2_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA2_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA2_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PA2_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA8_PA2_PRODCOUNT */

#define CSL_HTS_HWA8_PA2_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA8_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA8_PA2_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA8_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA8_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA8_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA8_PROD3_CONTROL */

#define CSL_HTS_HWA8_PROD3_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA8_PROD3_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_PROD3_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA8_PROD3_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PROD3_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PROD3_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* HWA8_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA8_PROD3_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA8_PROD3_COUNT */

#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA8_PROD3_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA8_PA3_CONTROL */

#define CSL_HTS_HWA8_PA3_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA3_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_HWA8_PA3_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA3_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_HWA8_PA3_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PA3_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* HWA8_PA3_PRODCOUNT */

#define CSL_HTS_HWA8_PA3_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_HWA8_PA3_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA8_PA3_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_HWA8_PA3_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_HWA8_PA3_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA8_PA3_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* HWA8_PROD4_CONTROL */

#define CSL_HTS_HWA8_PROD4_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_HWA8_PROD4_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_HWA8_PROD4_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_HWA8_PROD4_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_HWA8_PROD4_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_HWA8_PROD4_CONTROL_PROD_EN_MAX                                 (0x00000001U)

#define CSL_HTS_HWA8_PROD4_CONTROL_MASK_SELECT_MASK                            (0x03000000U)
#define CSL_HTS_HWA8_PROD4_CONTROL_MASK_SELECT_SHIFT                           (0x00000018U)
#define CSL_HTS_HWA8_PROD4_CONTROL_MASK_SELECT_MAX                             (0x00000003U)

/* HWA8_PROD4_BUF_CONTROL */

#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_HWA8_PROD4_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* HWA8_PROD4_COUNT */

#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA8_PROD4_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* HWA12_SCHEDULER_CONTROL */

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA12_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA12_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA12_HOP */

#define CSL_HTS_HWA12_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA12_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA12_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA12_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA12_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA12_HOP_HOP_MAX                                              (0x00000001U)

/* HWA12_CONS0_CONTROL */

#define CSL_HTS_HWA12_CONS0_CONTROL_EHWA_PROD_MASK                             (0x80000000U)
#define CSL_HTS_HWA12_CONS0_CONTROL_EHWA_PROD_SHIFT                            (0x0000001FU)
#define CSL_HTS_HWA12_CONS0_CONTROL_EHWA_PROD_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_CONS0_CONTROL_SET_PEND_MASK                              (0x40000000U)
#define CSL_HTS_HWA12_CONS0_CONTROL_SET_PEND_SHIFT                             (0x0000001EU)
#define CSL_HTS_HWA12_CONS0_CONTROL_SET_PEND_MAX                               (0x00000001U)

#define CSL_HTS_HWA12_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA12_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA12_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA12_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA12_CONS1_CONTROL */

#define CSL_HTS_HWA12_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA12_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA12_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA12_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA12_PROD0_CONTROL */

#define CSL_HTS_HWA12_PROD0_CONTROL_EHWA_CONS_MASK                             (0x80000000U)
#define CSL_HTS_HWA12_PROD0_CONTROL_EHWA_CONS_SHIFT                            (0x0000001FU)
#define CSL_HTS_HWA12_PROD0_CONTROL_EHWA_CONS_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_PROD0_CONTROL_PROD_DEC_MASK                              (0x40000000U)
#define CSL_HTS_HWA12_PROD0_CONTROL_PROD_DEC_SHIFT                             (0x0000001EU)
#define CSL_HTS_HWA12_PROD0_CONTROL_PROD_DEC_MAX                               (0x00000001U)

#define CSL_HTS_HWA12_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA12_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA12_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA12_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA12_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA12_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA12_PROD0_COUNT */

#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA12_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA12_PA0_CONTROL */

#define CSL_HTS_HWA12_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA12_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA12_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA12_PA0_PRODCOUNT */

#define CSL_HTS_HWA12_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA12_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA12_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA12_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA12_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA12_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA12_PROD1_CONTROL */

#define CSL_HTS_HWA12_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA12_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA12_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA12_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA12_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA12_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA12_PROD1_COUNT */

#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA12_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA12_PA1_CONTROL */

#define CSL_HTS_HWA12_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA12_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA12_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA12_PA1_PRODCOUNT */

#define CSL_HTS_HWA12_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA12_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA12_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA12_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA12_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA12_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA12_PROD2_CONTROL */

#define CSL_HTS_HWA12_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA12_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA12_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA12_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA12_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA12_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA12_PROD2_COUNT */

#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA12_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA12_PA2_CONTROL */

#define CSL_HTS_HWA12_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA12_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA12_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA12_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA12_PA2_PRODCOUNT */

#define CSL_HTS_HWA12_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA12_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA12_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA12_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA12_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA12_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA12_PROD3_CONTROL */

#define CSL_HTS_HWA12_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA12_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA12_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA12_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA12_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA12_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA12_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA12_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA12_PROD3_COUNT */

#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA12_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA13_SCHEDULER_CONTROL */

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA13_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA13_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA13_HOP */

#define CSL_HTS_HWA13_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA13_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA13_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA13_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA13_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA13_HOP_HOP_MAX                                              (0x00000001U)

/* HWA13_CONS0_CONTROL */

#define CSL_HTS_HWA13_CONS0_CONTROL_EHWA_PROD_MASK                             (0x80000000U)
#define CSL_HTS_HWA13_CONS0_CONTROL_EHWA_PROD_SHIFT                            (0x0000001FU)
#define CSL_HTS_HWA13_CONS0_CONTROL_EHWA_PROD_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_CONS0_CONTROL_SET_PEND_MASK                              (0x40000000U)
#define CSL_HTS_HWA13_CONS0_CONTROL_SET_PEND_SHIFT                             (0x0000001EU)
#define CSL_HTS_HWA13_CONS0_CONTROL_SET_PEND_MAX                               (0x00000001U)

#define CSL_HTS_HWA13_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA13_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA13_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA13_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA13_CONS1_CONTROL */

#define CSL_HTS_HWA13_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA13_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA13_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA13_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA13_PROD0_CONTROL */

#define CSL_HTS_HWA13_PROD0_CONTROL_EHWA_CONS_MASK                             (0x80000000U)
#define CSL_HTS_HWA13_PROD0_CONTROL_EHWA_CONS_SHIFT                            (0x0000001FU)
#define CSL_HTS_HWA13_PROD0_CONTROL_EHWA_CONS_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_PROD0_CONTROL_PROD_DEC_MASK                              (0x40000000U)
#define CSL_HTS_HWA13_PROD0_CONTROL_PROD_DEC_SHIFT                             (0x0000001EU)
#define CSL_HTS_HWA13_PROD0_CONTROL_PROD_DEC_MAX                               (0x00000001U)

#define CSL_HTS_HWA13_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA13_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA13_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA13_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA13_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA13_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA13_PROD0_COUNT */

#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA13_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA13_PA0_CONTROL */

#define CSL_HTS_HWA13_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA13_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA13_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA13_PA0_PRODCOUNT */

#define CSL_HTS_HWA13_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA13_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA13_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA13_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA13_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA13_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA13_PROD1_CONTROL */

#define CSL_HTS_HWA13_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA13_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA13_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA13_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA13_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA13_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA13_PROD1_COUNT */

#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA13_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA13_PA1_CONTROL */

#define CSL_HTS_HWA13_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA13_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA13_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA13_PA1_PRODCOUNT */

#define CSL_HTS_HWA13_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA13_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA13_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA13_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA13_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA13_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA13_PROD2_CONTROL */

#define CSL_HTS_HWA13_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA13_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA13_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA13_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA13_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA13_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA13_PROD2_COUNT */

#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA13_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA13_PA2_CONTROL */

#define CSL_HTS_HWA13_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA13_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA13_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA13_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA13_PA2_PRODCOUNT */

#define CSL_HTS_HWA13_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA13_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA13_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA13_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA13_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA13_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA13_PROD3_CONTROL */

#define CSL_HTS_HWA13_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA13_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA13_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA13_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA13_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA13_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA13_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA13_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA13_PROD3_COUNT */

#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA13_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA14_SCHEDULER_CONTROL */

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA14_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA14_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA14_HOP */

#define CSL_HTS_HWA14_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA14_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA14_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA14_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA14_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA14_HOP_HOP_MAX                                              (0x00000001U)

/* HWA14_CONS0_CONTROL */

#define CSL_HTS_HWA14_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA14_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA14_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA14_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA14_CONS1_CONTROL */

#define CSL_HTS_HWA14_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA14_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA14_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA14_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA14_PROD0_CONTROL */

#define CSL_HTS_HWA14_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA14_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA14_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA14_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA14_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA14_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA14_PROD0_COUNT */

#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA14_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA14_PA0_CONTROL */

#define CSL_HTS_HWA14_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA14_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA14_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA14_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA14_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA14_PA0_PRODCOUNT */

#define CSL_HTS_HWA14_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA14_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA14_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA14_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA14_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA14_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA14_PROD1_CONTROL */

#define CSL_HTS_HWA14_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA14_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA14_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA14_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA14_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA14_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA14_PROD1_COUNT */

#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA14_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA14_PA1_CONTROL */

#define CSL_HTS_HWA14_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA14_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA14_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA14_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA14_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA14_PA1_PRODCOUNT */

#define CSL_HTS_HWA14_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA14_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA14_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA14_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA14_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA14_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA14_PROD2_CONTROL */

#define CSL_HTS_HWA14_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA14_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA14_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA14_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA14_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA14_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA14_PROD2_COUNT */

#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA14_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA14_PA2_CONTROL */

#define CSL_HTS_HWA14_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA14_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA14_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA14_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA14_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA14_PA2_PRODCOUNT */

#define CSL_HTS_HWA14_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA14_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA14_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA14_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA14_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA14_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA14_PROD3_CONTROL */

#define CSL_HTS_HWA14_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA14_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA14_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA14_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA14_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA14_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA14_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA14_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA14_PROD3_COUNT */

#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA14_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA15_SCHEDULER_CONTROL */

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA15_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA15_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA15_HOP */

#define CSL_HTS_HWA15_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA15_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA15_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA15_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA15_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA15_HOP_HOP_MAX                                              (0x00000001U)

/* HWA15_CONS0_CONTROL */

#define CSL_HTS_HWA15_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA15_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA15_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA15_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA15_CONS1_CONTROL */

#define CSL_HTS_HWA15_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA15_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA15_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA15_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA15_PROD0_CONTROL */

#define CSL_HTS_HWA15_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA15_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA15_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA15_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA15_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA15_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA15_PROD0_COUNT */

#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA15_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA15_PA0_CONTROL */

#define CSL_HTS_HWA15_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA15_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA15_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA15_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA15_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA15_PA0_PRODCOUNT */

#define CSL_HTS_HWA15_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA15_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA15_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA15_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA15_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA15_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA15_PROD1_CONTROL */

#define CSL_HTS_HWA15_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA15_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA15_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA15_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA15_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA15_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA15_PROD1_COUNT */

#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA15_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA15_PA1_CONTROL */

#define CSL_HTS_HWA15_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA15_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA15_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA15_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA15_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA15_PA1_PRODCOUNT */

#define CSL_HTS_HWA15_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA15_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA15_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA15_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA15_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA15_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA15_PROD2_CONTROL */

#define CSL_HTS_HWA15_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA15_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA15_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA15_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA15_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA15_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA15_PROD2_COUNT */

#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA15_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA15_PA2_CONTROL */

#define CSL_HTS_HWA15_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA15_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA15_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA15_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA15_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA15_PA2_PRODCOUNT */

#define CSL_HTS_HWA15_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA15_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA15_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA15_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA15_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA15_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA15_PROD3_CONTROL */

#define CSL_HTS_HWA15_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA15_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA15_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA15_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA15_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA15_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA15_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA15_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA15_PROD3_COUNT */

#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA15_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA16_SCHEDULER_CONTROL */

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA16_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA16_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA16_HOP */

#define CSL_HTS_HWA16_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA16_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA16_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA16_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA16_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA16_HOP_HOP_MAX                                              (0x00000001U)

/* HWA16_CONS0_CONTROL */

#define CSL_HTS_HWA16_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA16_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA16_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA16_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA16_CONS1_CONTROL */

#define CSL_HTS_HWA16_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA16_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA16_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA16_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA16_PROD0_CONTROL */

#define CSL_HTS_HWA16_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA16_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA16_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA16_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA16_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA16_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA16_PROD0_COUNT */

#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA16_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA16_PA0_CONTROL */

#define CSL_HTS_HWA16_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA16_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA16_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA16_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA16_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA16_PA0_PRODCOUNT */

#define CSL_HTS_HWA16_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA16_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA16_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA16_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA16_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA16_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA16_PROD1_CONTROL */

#define CSL_HTS_HWA16_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA16_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA16_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA16_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA16_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA16_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA16_PROD1_COUNT */

#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA16_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA16_PA1_CONTROL */

#define CSL_HTS_HWA16_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA16_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA16_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA16_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA16_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA16_PA1_PRODCOUNT */

#define CSL_HTS_HWA16_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA16_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA16_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA16_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA16_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA16_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA16_PROD2_CONTROL */

#define CSL_HTS_HWA16_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA16_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA16_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA16_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA16_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA16_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA16_PROD2_COUNT */

#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA16_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA16_PA2_CONTROL */

#define CSL_HTS_HWA16_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA16_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA16_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA16_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA16_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA16_PA2_PRODCOUNT */

#define CSL_HTS_HWA16_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA16_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA16_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA16_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA16_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA16_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA16_PROD3_CONTROL */

#define CSL_HTS_HWA16_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA16_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA16_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA16_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA16_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA16_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA16_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA16_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA16_PROD3_COUNT */

#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA16_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA17_SCHEDULER_CONTROL */

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA17_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA17_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA17_HOP */

#define CSL_HTS_HWA17_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA17_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA17_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA17_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA17_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA17_HOP_HOP_MAX                                              (0x00000001U)

/* HWA17_CONS0_CONTROL */

#define CSL_HTS_HWA17_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA17_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA17_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA17_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA17_CONS1_CONTROL */

#define CSL_HTS_HWA17_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA17_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA17_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA17_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA17_PROD0_CONTROL */

#define CSL_HTS_HWA17_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA17_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA17_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA17_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA17_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA17_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA17_PROD0_COUNT */

#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA17_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA17_PA0_CONTROL */

#define CSL_HTS_HWA17_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA17_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA17_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA17_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA17_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA17_PA0_PRODCOUNT */

#define CSL_HTS_HWA17_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA17_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA17_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA17_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA17_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA17_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA17_PROD1_CONTROL */

#define CSL_HTS_HWA17_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA17_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA17_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA17_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA17_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA17_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA17_PROD1_COUNT */

#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA17_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA17_PA1_CONTROL */

#define CSL_HTS_HWA17_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA17_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA17_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA17_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA17_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA17_PA1_PRODCOUNT */

#define CSL_HTS_HWA17_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA17_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA17_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA17_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA17_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA17_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA17_PROD2_CONTROL */

#define CSL_HTS_HWA17_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA17_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA17_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA17_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA17_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA17_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA17_PROD2_COUNT */

#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA17_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA17_PA2_CONTROL */

#define CSL_HTS_HWA17_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA17_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA17_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA17_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA17_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA17_PA2_PRODCOUNT */

#define CSL_HTS_HWA17_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA17_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA17_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA17_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA17_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA17_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA17_PROD3_CONTROL */

#define CSL_HTS_HWA17_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA17_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA17_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA17_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA17_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA17_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA17_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA17_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA17_PROD3_COUNT */

#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA17_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA18_SCHEDULER_CONTROL */

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA18_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA18_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA18_HOP */

#define CSL_HTS_HWA18_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA18_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA18_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA18_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA18_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA18_HOP_HOP_MAX                                              (0x00000001U)

/* HWA18_CONS0_CONTROL */

#define CSL_HTS_HWA18_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA18_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA18_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA18_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA18_CONS1_CONTROL */

#define CSL_HTS_HWA18_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA18_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA18_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA18_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA18_PROD0_CONTROL */

#define CSL_HTS_HWA18_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA18_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA18_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA18_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA18_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA18_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA18_PROD0_COUNT */

#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA18_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA18_PA0_CONTROL */

#define CSL_HTS_HWA18_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA18_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA18_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA18_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA18_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA18_PA0_PRODCOUNT */

#define CSL_HTS_HWA18_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA18_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA18_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA18_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA18_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA18_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA18_PROD1_CONTROL */

#define CSL_HTS_HWA18_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA18_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA18_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA18_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA18_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA18_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA18_PROD1_COUNT */

#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA18_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA18_PA1_CONTROL */

#define CSL_HTS_HWA18_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA18_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA18_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA18_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA18_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA18_PA1_PRODCOUNT */

#define CSL_HTS_HWA18_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA18_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA18_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA18_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA18_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA18_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA18_PROD2_CONTROL */

#define CSL_HTS_HWA18_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA18_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA18_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA18_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA18_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA18_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA18_PROD2_COUNT */

#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA18_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA18_PA2_CONTROL */

#define CSL_HTS_HWA18_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA18_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA18_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA18_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA18_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA18_PA2_PRODCOUNT */

#define CSL_HTS_HWA18_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA18_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA18_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA18_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA18_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA18_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA18_PROD3_CONTROL */

#define CSL_HTS_HWA18_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA18_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA18_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA18_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA18_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA18_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA18_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA18_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA18_PROD3_COUNT */

#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA18_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA19_SCHEDULER_CONTROL */

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_START_LOOP_BACK_MASK                   (0x00800000U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_START_LOOP_BACK_SHIFT                  (0x00000017U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_START_LOOP_BACK_MAX                    (0x00000001U)

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_HWA19_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_HWA19_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* HWA19_HOP */

#define CSL_HTS_HWA19_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_HWA19_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_HWA19_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_HWA19_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_HWA19_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_HWA19_HOP_HOP_MAX                                              (0x00000001U)

/* HWA19_CONS0_CONTROL */

#define CSL_HTS_HWA19_CONS0_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA19_CONS0_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA19_CONS0_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA19_CONS0_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_CONS0_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_CONS0_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA19_CONS1_CONTROL */

#define CSL_HTS_HWA19_CONS1_CONTROL_PROD_SELECT_MASK                           (0x000003FEU)
#define CSL_HTS_HWA19_CONS1_CONTROL_PROD_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA19_CONS1_CONTROL_PROD_SELECT_MAX                            (0x000001FFU)

#define CSL_HTS_HWA19_CONS1_CONTROL_CONS_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_CONS1_CONTROL_CONS_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_CONS1_CONTROL_CONS_EN_MAX                                (0x00000001U)

/* HWA19_PROD0_CONTROL */

#define CSL_HTS_HWA19_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA19_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA19_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA19_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA19_PROD0_BUF_CONTROL */

#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA19_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA19_PROD0_COUNT */

#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA19_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA19_PA0_CONTROL */

#define CSL_HTS_HWA19_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA19_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA19_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA19_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA19_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA19_PA0_PRODCOUNT */

#define CSL_HTS_HWA19_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA19_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA19_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA19_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA19_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA19_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA19_PROD1_CONTROL */

#define CSL_HTS_HWA19_PROD1_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA19_PROD1_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA19_PROD1_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA19_PROD1_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_PROD1_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_PROD1_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA19_PROD1_BUF_CONTROL */

#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA19_PROD1_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA19_PROD1_COUNT */

#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA19_PROD1_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA19_PA1_CONTROL */

#define CSL_HTS_HWA19_PA1_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA19_PA1_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA19_PA1_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA19_PA1_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA19_PA1_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_PA1_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA19_PA1_PRODCOUNT */

#define CSL_HTS_HWA19_PA1_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA19_PA1_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA19_PA1_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA19_PA1_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA19_PA1_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA19_PA1_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA19_PROD2_CONTROL */

#define CSL_HTS_HWA19_PROD2_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA19_PROD2_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA19_PROD2_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA19_PROD2_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_PROD2_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_PROD2_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA19_PROD2_BUF_CONTROL */

#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA19_PROD2_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA19_PROD2_COUNT */

#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA19_PROD2_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* HWA19_PA2_CONTROL */

#define CSL_HTS_HWA19_PA2_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA19_PA2_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_HWA19_PA2_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA19_PA2_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_HWA19_PA2_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_PA2_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* HWA19_PA2_PRODCOUNT */

#define CSL_HTS_HWA19_PA2_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_HWA19_PA2_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_HWA19_PA2_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_HWA19_PA2_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_HWA19_PA2_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_HWA19_PA2_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* HWA19_PROD3_CONTROL */

#define CSL_HTS_HWA19_PROD3_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_HWA19_PROD3_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_HWA19_PROD3_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_HWA19_PROD3_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_HWA19_PROD3_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_HWA19_PROD3_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* HWA19_PROD3_BUF_CONTROL */

#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_HWA19_PROD3_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* HWA19_PROD3_COUNT */

#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_HWA19_PROD3_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA0_SCHEDULER_CONTROL */

#define CSL_HTS_DMA0_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                     (0x001FE000U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                    (0x0000000DU)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                      (0x000000FFU)

#define CSL_HTS_DMA0_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_DMA0_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_DMA0_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_DMA0_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_DMA0_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_DMA0_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA0_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* DMA0_HOP */

#define CSL_HTS_DMA0_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_DMA0_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_DMA0_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_DMA0_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_DMA0_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_DMA0_HOP_HOP_MAX                                               (0x00000001U)

/* DMA0_PROD0_CONTROL */

#define CSL_HTS_DMA0_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_DMA0_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_DMA0_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_DMA0_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_DMA0_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA0_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* DMA0_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA0_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* DMA0_PROD0_COUNT */

#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA0_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* DMA1_SCHEDULER_CONTROL */

#define CSL_HTS_DMA1_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                     (0x001FE000U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                    (0x0000000DU)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                      (0x000000FFU)

#define CSL_HTS_DMA1_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_DMA1_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_DMA1_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_DMA1_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_DMA1_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_DMA1_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA1_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* DMA1_HOP */

#define CSL_HTS_DMA1_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_DMA1_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_DMA1_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_DMA1_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_DMA1_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_DMA1_HOP_HOP_MAX                                               (0x00000001U)

/* DMA1_PROD0_CONTROL */

#define CSL_HTS_DMA1_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_DMA1_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_DMA1_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_DMA1_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_DMA1_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA1_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* DMA1_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA1_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* DMA1_PROD0_COUNT */

#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA1_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* DMA2_SCHEDULER_CONTROL */

#define CSL_HTS_DMA2_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                     (0x001FE000U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                    (0x0000000DU)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                      (0x000000FFU)

#define CSL_HTS_DMA2_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_DMA2_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_DMA2_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_DMA2_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_DMA2_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_DMA2_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA2_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* DMA2_HOP */

#define CSL_HTS_DMA2_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_DMA2_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_DMA2_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_DMA2_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_DMA2_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_DMA2_HOP_HOP_MAX                                               (0x00000001U)

/* DMA2_PROD0_CONTROL */

#define CSL_HTS_DMA2_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_DMA2_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_DMA2_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_DMA2_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_DMA2_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA2_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* DMA2_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA2_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* DMA2_PROD0_COUNT */

#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA2_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* DMA3_SCHEDULER_CONTROL */

#define CSL_HTS_DMA3_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                     (0x001FE000U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                    (0x0000000DU)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                      (0x000000FFU)

#define CSL_HTS_DMA3_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_DMA3_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_DMA3_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_DMA3_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_DMA3_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_DMA3_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA3_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* DMA3_HOP */

#define CSL_HTS_DMA3_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_DMA3_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_DMA3_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_DMA3_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_DMA3_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_DMA3_HOP_HOP_MAX                                               (0x00000001U)

/* DMA3_PROD0_CONTROL */

#define CSL_HTS_DMA3_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_DMA3_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_DMA3_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_DMA3_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_DMA3_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA3_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* DMA3_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA3_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* DMA3_PROD0_COUNT */

#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA3_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* DMA4_SCHEDULER_CONTROL */

#define CSL_HTS_DMA4_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                     (0x001FE000U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                    (0x0000000DU)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                      (0x000000FFU)

#define CSL_HTS_DMA4_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_DMA4_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_DMA4_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_DMA4_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_DMA4_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_DMA4_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA4_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* DMA4_HOP */

#define CSL_HTS_DMA4_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_DMA4_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_DMA4_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_DMA4_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_DMA4_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_DMA4_HOP_HOP_MAX                                               (0x00000001U)

/* DMA4_PROD0_CONTROL */

#define CSL_HTS_DMA4_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_DMA4_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_DMA4_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_DMA4_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_DMA4_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA4_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* DMA4_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA4_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* DMA4_PROD0_COUNT */

#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA4_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* DMA8_SCHEDULER_CONTROL */

#define CSL_HTS_DMA8_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                     (0x001FE000U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                    (0x0000000DU)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                      (0x000000FFU)

#define CSL_HTS_DMA8_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_DMA8_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_DMA8_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_DMA8_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_DMA8_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_DMA8_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA8_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* DMA8_HOP */

#define CSL_HTS_DMA8_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_DMA8_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_DMA8_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_DMA8_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_DMA8_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_DMA8_HOP_HOP_MAX                                               (0x00000001U)

/* DMA8_PROD0_CONTROL */

#define CSL_HTS_DMA8_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_DMA8_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_DMA8_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_DMA8_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_DMA8_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA8_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* DMA8_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA8_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* DMA8_PROD0_COUNT */

#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA8_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* DMA8_PA0_CONTROL */

#define CSL_HTS_DMA8_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_DMA8_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_DMA8_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_DMA8_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_DMA8_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA8_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* DMA8_PA0_PRODCOUNT */

#define CSL_HTS_DMA8_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_DMA8_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA8_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_DMA8_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_DMA8_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA8_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* DMA9_SCHEDULER_CONTROL */

#define CSL_HTS_DMA9_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                     (0x001FE000U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                    (0x0000000DU)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                      (0x000000FFU)

#define CSL_HTS_DMA9_SCHEDULER_CONTROL_DEBUG_RDY_MASK                          (0x00001000U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                         (0x0000000CU)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_DEBUG_RDY_MAX                           (0x00000001U)

#define CSL_HTS_DMA9_SCHEDULER_CONTROL_STATE_MASK                              (0x00000780U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_STATE_SHIFT                             (0x00000007U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_STATE_MAX                               (0x0000000FU)

#define CSL_HTS_DMA9_SCHEDULER_CONTROL_PAUSE_MASK                              (0x00000040U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_PAUSE_SHIFT                             (0x00000006U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_PAUSE_MAX                               (0x00000001U)

#define CSL_HTS_DMA9_SCHEDULER_CONTROL_STRM_EN_MASK                            (0x00000020U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_STRM_EN_SHIFT                           (0x00000005U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_STRM_EN_MAX                             (0x00000001U)

#define CSL_HTS_DMA9_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                       (0x0000000EU)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                      (0x00000001U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                        (0x00000007U)

#define CSL_HTS_DMA9_SCHEDULER_CONTROL_SCH_EN_MASK                             (0x00000001U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_SCH_EN_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA9_SCHEDULER_CONTROL_SCH_EN_MAX                              (0x00000001U)

/* DMA9_HOP */

#define CSL_HTS_DMA9_HOP_HOP_THREAD_COUNT_MASK                                 (0x00003FFEU)
#define CSL_HTS_DMA9_HOP_HOP_THREAD_COUNT_SHIFT                                (0x00000001U)
#define CSL_HTS_DMA9_HOP_HOP_THREAD_COUNT_MAX                                  (0x00001FFFU)

#define CSL_HTS_DMA9_HOP_HOP_MASK                                              (0x00000001U)
#define CSL_HTS_DMA9_HOP_HOP_SHIFT                                             (0x00000000U)
#define CSL_HTS_DMA9_HOP_HOP_MAX                                               (0x00000001U)

/* DMA9_PROD0_CONTROL */

#define CSL_HTS_DMA9_PROD0_CONTROL_CONS_SELECT_MASK                            (0x000001FEU)
#define CSL_HTS_DMA9_PROD0_CONTROL_CONS_SELECT_SHIFT                           (0x00000001U)
#define CSL_HTS_DMA9_PROD0_CONTROL_CONS_SELECT_MAX                             (0x000000FFU)

#define CSL_HTS_DMA9_PROD0_CONTROL_PROD_EN_MASK                                (0x00000001U)
#define CSL_HTS_DMA9_PROD0_CONTROL_PROD_EN_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA9_PROD0_CONTROL_PROD_EN_MAX                                 (0x00000001U)

/* DMA9_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_COUNT_DEC_MASK                          (0x07E00000U)
#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                         (0x00000015U)
#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_COUNT_DEC_MAX                           (0x0000003FU)

#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_THRESHOLD_MASK                          (0x001FE000U)
#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_THRESHOLD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_DEPTH_MASK                              (0x00001FFFU)
#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_DEPTH_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA9_PROD0_BUF_CONTROL_DEPTH_MAX                               (0x00001FFFU)

/* DMA9_PROD0_COUNT */

#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_MASK                                    (0x1FFF0000U)
#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_SHIFT                                   (0x00000010U)
#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_MAX                                     (0x00001FFFU)

#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_POSTLOAD_MASK                           (0x0000FF00U)
#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                          (0x00000008U)
#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_POSTLOAD_MAX                            (0x000000FFU)

#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_PRELOAD_MASK                            (0x000000FFU)
#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_PRELOAD_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA9_PROD0_COUNT_COUNT_PRELOAD_MAX                             (0x000000FFU)

/* DMA9_PA0_CONTROL */

#define CSL_HTS_DMA9_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                           (0x007FE000U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                          (0x0000000DU)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_DMA9_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                           (0x00001FF8U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                          (0x00000003U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                            (0x000003FFU)

#define CSL_HTS_DMA9_PA0_CONTROL_PA_BUF_CNTL_MASK                              (0x00000004U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_BUF_CNTL_SHIFT                             (0x00000002U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_BUF_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_DMA9_PA0_CONTROL_PA_DEC_CNTL_MASK                              (0x00000002U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_DEC_CNTL_SHIFT                             (0x00000001U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_DEC_CNTL_MAX                               (0x00000001U)

#define CSL_HTS_DMA9_PA0_CONTROL_PA_ENABLE_MASK                                (0x00000001U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_ENABLE_SHIFT                               (0x00000000U)
#define CSL_HTS_DMA9_PA0_CONTROL_PA_ENABLE_MAX                                 (0x00000001U)

/* DMA9_PA0_PRODCOUNT */

#define CSL_HTS_DMA9_PA0_PRODCOUNT_PA_PSCOUNT_MASK                             (0x0000FFC0U)
#define CSL_HTS_DMA9_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA9_PA0_PRODCOUNT_PA_PSCOUNT_MAX                              (0x000003FFU)

#define CSL_HTS_DMA9_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                           (0x0000003FU)
#define CSL_HTS_DMA9_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA9_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                            (0x0000003FU)

/* DMA10_SCHEDULER_CONTROL */

#define CSL_HTS_DMA10_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA10_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA10_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA10_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA10_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA10_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA10_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA10_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA10_HOP */

#define CSL_HTS_DMA10_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA10_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA10_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA10_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA10_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA10_HOP_HOP_MAX                                              (0x00000001U)

/* DMA10_PROD0_CONTROL */

#define CSL_HTS_DMA10_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA10_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA10_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA10_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA10_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA10_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA10_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA10_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA10_PROD0_COUNT */

#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA10_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA10_PA0_CONTROL */

#define CSL_HTS_DMA10_PA0_CONTROL_PA_PS_MAXCOUNT_MASK                          (0x007FE000U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_PS_MAXCOUNT_SHIFT                         (0x0000000DU)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_PS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_DMA10_PA0_CONTROL_PA_CS_MAXCOUNT_MASK                          (0x00001FF8U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_CS_MAXCOUNT_SHIFT                         (0x00000003U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_CS_MAXCOUNT_MAX                           (0x000003FFU)

#define CSL_HTS_DMA10_PA0_CONTROL_PA_BUF_CNTL_MASK                             (0x00000004U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_BUF_CNTL_SHIFT                            (0x00000002U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_BUF_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_DMA10_PA0_CONTROL_PA_DEC_CNTL_MASK                             (0x00000002U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_DEC_CNTL_SHIFT                            (0x00000001U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_DEC_CNTL_MAX                              (0x00000001U)

#define CSL_HTS_DMA10_PA0_CONTROL_PA_ENABLE_MASK                               (0x00000001U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_ENABLE_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA10_PA0_CONTROL_PA_ENABLE_MAX                                (0x00000001U)

/* DMA10_PA0_PRODCOUNT */

#define CSL_HTS_DMA10_PA0_PRODCOUNT_PA_PSCOUNT_MASK                            (0x0000FFC0U)
#define CSL_HTS_DMA10_PA0_PRODCOUNT_PA_PSCOUNT_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA10_PA0_PRODCOUNT_PA_PSCOUNT_MAX                             (0x000003FFU)

#define CSL_HTS_DMA10_PA0_PRODCOUNT_PA_COUNT_DEC_MASK                          (0x0000003FU)
#define CSL_HTS_DMA10_PA0_PRODCOUNT_PA_COUNT_DEC_SHIFT                         (0x00000000U)
#define CSL_HTS_DMA10_PA0_PRODCOUNT_PA_COUNT_DEC_MAX                           (0x0000003FU)

/* DMA32_SCHEDULER_CONTROL */

#define CSL_HTS_DMA32_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA32_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA32_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA32_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA32_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA32_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA32_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA32_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA32_HOP */

#define CSL_HTS_DMA32_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA32_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA32_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA32_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA32_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA32_HOP_HOP_MAX                                              (0x00000001U)

/* DMA32_PROD0_CONTROL */

#define CSL_HTS_DMA32_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA32_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA32_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA32_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA32_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA32_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA32_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA32_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA32_PROD0_COUNT */

#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA32_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA40_SCHEDULER_CONTROL */

#define CSL_HTS_DMA40_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA40_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA40_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA40_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA40_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA40_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA40_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA40_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA40_HOP */

#define CSL_HTS_DMA40_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA40_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA40_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA40_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA40_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA40_HOP_HOP_MAX                                              (0x00000001U)

/* DMA40_PROD0_CONTROL */

#define CSL_HTS_DMA40_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA40_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA40_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA40_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA40_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA40_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA40_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA40_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA40_PROD0_COUNT */

#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA40_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA48_SCHEDULER_CONTROL */

#define CSL_HTS_DMA48_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA48_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA48_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA48_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA48_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA48_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA48_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA48_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA48_HOP */

#define CSL_HTS_DMA48_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA48_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA48_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA48_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA48_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA48_HOP_HOP_MAX                                              (0x00000001U)

/* DMA48_PROD0_CONTROL */

#define CSL_HTS_DMA48_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA48_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA48_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA48_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA48_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA48_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA48_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA48_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA48_PROD0_COUNT */

#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA48_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA56_SCHEDULER_CONTROL */

#define CSL_HTS_DMA56_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA56_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA56_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA56_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA56_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA56_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA56_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA56_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA56_HOP */

#define CSL_HTS_DMA56_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA56_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA56_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA56_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA56_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA56_HOP_HOP_MAX                                              (0x00000001U)

/* DMA56_PROD0_CONTROL */

#define CSL_HTS_DMA56_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA56_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA56_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA56_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA56_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA56_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA56_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA56_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA56_PROD0_COUNT */

#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA56_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA57_SCHEDULER_CONTROL */

#define CSL_HTS_DMA57_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA57_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA57_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA57_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA57_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA57_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA57_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA57_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA57_HOP */

#define CSL_HTS_DMA57_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA57_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA57_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA57_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA57_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA57_HOP_HOP_MAX                                              (0x00000001U)

/* DMA57_PROD0_CONTROL */

#define CSL_HTS_DMA57_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA57_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA57_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA57_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA57_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA57_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA57_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA57_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA57_PROD0_COUNT */

#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA57_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA58_SCHEDULER_CONTROL */

#define CSL_HTS_DMA58_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA58_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA58_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA58_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA58_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA58_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA58_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA58_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA58_HOP */

#define CSL_HTS_DMA58_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA58_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA58_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA58_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA58_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA58_HOP_HOP_MAX                                              (0x00000001U)

/* DMA58_PROD0_CONTROL */

#define CSL_HTS_DMA58_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA58_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA58_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA58_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA58_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA58_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA58_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA58_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA58_PROD0_COUNT */

#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA58_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA59_SCHEDULER_CONTROL */

#define CSL_HTS_DMA59_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA59_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA59_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA59_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA59_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA59_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA59_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA59_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA59_HOP */

#define CSL_HTS_DMA59_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA59_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA59_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA59_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA59_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA59_HOP_HOP_MAX                                              (0x00000001U)

/* DMA59_PROD0_CONTROL */

#define CSL_HTS_DMA59_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA59_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA59_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA59_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA59_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA59_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA59_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA59_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA59_PROD0_COUNT */

#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA59_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA64_SCHEDULER_CONTROL */

#define CSL_HTS_DMA64_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA64_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA64_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA64_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA64_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA64_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA64_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA64_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA64_HOP */

#define CSL_HTS_DMA64_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA64_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA64_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA64_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA64_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA64_HOP_HOP_MAX                                              (0x00000001U)

/* DMA64_PROD0_CONTROL */

#define CSL_HTS_DMA64_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA64_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA64_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA64_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA64_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA64_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA64_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA64_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA64_PROD0_COUNT */

#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA64_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA65_SCHEDULER_CONTROL */

#define CSL_HTS_DMA65_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA65_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA65_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA65_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA65_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA65_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA65_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA65_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA65_HOP */

#define CSL_HTS_DMA65_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA65_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA65_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA65_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA65_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA65_HOP_HOP_MAX                                              (0x00000001U)

/* DMA65_PROD0_CONTROL */

#define CSL_HTS_DMA65_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA65_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA65_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA65_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA65_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA65_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA65_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA65_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA65_PROD0_COUNT */

#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA65_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA66_SCHEDULER_CONTROL */

#define CSL_HTS_DMA66_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA66_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA66_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA66_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA66_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA66_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA66_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA66_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA66_HOP */

#define CSL_HTS_DMA66_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA66_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA66_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA66_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA66_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA66_HOP_HOP_MAX                                              (0x00000001U)

/* DMA66_PROD0_CONTROL */

#define CSL_HTS_DMA66_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA66_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA66_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA66_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA66_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA66_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA66_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA66_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA66_PROD0_COUNT */

#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA66_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA67_SCHEDULER_CONTROL */

#define CSL_HTS_DMA67_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                    (0x001FE000U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                   (0x0000000DU)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                     (0x000000FFU)

#define CSL_HTS_DMA67_SCHEDULER_CONTROL_DEBUG_RDY_MASK                         (0x00001000U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                        (0x0000000CU)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_DEBUG_RDY_MAX                          (0x00000001U)

#define CSL_HTS_DMA67_SCHEDULER_CONTROL_STATE_MASK                             (0x00000780U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_STATE_SHIFT                            (0x00000007U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_STATE_MAX                              (0x0000000FU)

#define CSL_HTS_DMA67_SCHEDULER_CONTROL_PAUSE_MASK                             (0x00000040U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_PAUSE_SHIFT                            (0x00000006U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_PAUSE_MAX                              (0x00000001U)

#define CSL_HTS_DMA67_SCHEDULER_CONTROL_STRM_EN_MASK                           (0x00000020U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_STRM_EN_SHIFT                          (0x00000005U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_STRM_EN_MAX                            (0x00000001U)

#define CSL_HTS_DMA67_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                      (0x0000000EU)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                     (0x00000001U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                       (0x00000007U)

#define CSL_HTS_DMA67_SCHEDULER_CONTROL_SCH_EN_MASK                            (0x00000001U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_SCH_EN_SHIFT                           (0x00000000U)
#define CSL_HTS_DMA67_SCHEDULER_CONTROL_SCH_EN_MAX                             (0x00000001U)

/* DMA67_HOP */

#define CSL_HTS_DMA67_HOP_HOP_THREAD_COUNT_MASK                                (0x00003FFEU)
#define CSL_HTS_DMA67_HOP_HOP_THREAD_COUNT_SHIFT                               (0x00000001U)
#define CSL_HTS_DMA67_HOP_HOP_THREAD_COUNT_MAX                                 (0x00001FFFU)

#define CSL_HTS_DMA67_HOP_HOP_MASK                                             (0x00000001U)
#define CSL_HTS_DMA67_HOP_HOP_SHIFT                                            (0x00000000U)
#define CSL_HTS_DMA67_HOP_HOP_MAX                                              (0x00000001U)

/* DMA67_PROD0_CONTROL */

#define CSL_HTS_DMA67_PROD0_CONTROL_CONS_SELECT_MASK                           (0x000001FEU)
#define CSL_HTS_DMA67_PROD0_CONTROL_CONS_SELECT_SHIFT                          (0x00000001U)
#define CSL_HTS_DMA67_PROD0_CONTROL_CONS_SELECT_MAX                            (0x000000FFU)

#define CSL_HTS_DMA67_PROD0_CONTROL_PROD_EN_MASK                               (0x00000001U)
#define CSL_HTS_DMA67_PROD0_CONTROL_PROD_EN_SHIFT                              (0x00000000U)
#define CSL_HTS_DMA67_PROD0_CONTROL_PROD_EN_MAX                                (0x00000001U)

/* DMA67_PROD0_BUF_CONTROL */

#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_COUNT_DEC_MASK                         (0x07E00000U)
#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_COUNT_DEC_SHIFT                        (0x00000015U)
#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_COUNT_DEC_MAX                          (0x0000003FU)

#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_THRESHOLD_MASK                         (0x001FE000U)
#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_THRESHOLD_SHIFT                        (0x0000000DU)
#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_THRESHOLD_MAX                          (0x000000FFU)

#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_DEPTH_MASK                             (0x00001FFFU)
#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_DEPTH_SHIFT                            (0x00000000U)
#define CSL_HTS_DMA67_PROD0_BUF_CONTROL_DEPTH_MAX                              (0x00001FFFU)

/* DMA67_PROD0_COUNT */

#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_MASK                                   (0x1FFF0000U)
#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_SHIFT                                  (0x00000010U)
#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_MAX                                    (0x00001FFFU)

#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_POSTLOAD_MASK                          (0x0000FF00U)
#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_POSTLOAD_SHIFT                         (0x00000008U)
#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_POSTLOAD_MAX                           (0x000000FFU)

#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_PRELOAD_MASK                           (0x000000FFU)
#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_PRELOAD_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA67_PROD0_COUNT_COUNT_PRELOAD_MAX                            (0x000000FFU)

/* DMA240_SCHEDULER_CONTROL */

#define CSL_HTS_DMA240_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA240_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA240_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA240_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA240_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA240_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA240_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA240_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA240_CONS0_CONTROL */

#define CSL_HTS_DMA240_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA240_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA240_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA240_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA240_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA240_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA241_SCHEDULER_CONTROL */

#define CSL_HTS_DMA241_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA241_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA241_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA241_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA241_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA241_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA241_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA241_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA241_CONS0_CONTROL */

#define CSL_HTS_DMA241_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA241_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA241_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA241_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA241_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA241_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA242_SCHEDULER_CONTROL */

#define CSL_HTS_DMA242_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA242_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA242_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA242_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA242_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA242_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA242_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA242_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA242_CONS0_CONTROL */

#define CSL_HTS_DMA242_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA242_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA242_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA242_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA242_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA242_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA243_SCHEDULER_CONTROL */

#define CSL_HTS_DMA243_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA243_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA243_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA243_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA243_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA243_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA243_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA243_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA243_CONS0_CONTROL */

#define CSL_HTS_DMA243_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA243_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA243_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA243_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA243_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA243_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA244_SCHEDULER_CONTROL */

#define CSL_HTS_DMA244_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA244_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA244_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA244_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA244_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA244_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA244_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA244_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA244_CONS0_CONTROL */

#define CSL_HTS_DMA244_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA244_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA244_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA244_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA244_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA244_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA245_SCHEDULER_CONTROL */

#define CSL_HTS_DMA245_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA245_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA245_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA245_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA245_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA245_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA245_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA245_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA245_CONS0_CONTROL */

#define CSL_HTS_DMA245_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA245_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA245_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA245_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA245_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA245_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA256_SCHEDULER_CONTROL */

#define CSL_HTS_DMA256_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA256_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA256_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA256_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA256_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA256_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA256_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA256_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA256_CONS0_CONTROL */

#define CSL_HTS_DMA256_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA256_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA256_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA256_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA256_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA256_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA257_SCHEDULER_CONTROL */

#define CSL_HTS_DMA257_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA257_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA257_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA257_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA257_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA257_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA257_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA257_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA257_CONS0_CONTROL */

#define CSL_HTS_DMA257_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA257_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA257_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA257_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA257_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA257_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA258_SCHEDULER_CONTROL */

#define CSL_HTS_DMA258_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA258_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA258_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA258_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA258_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA258_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA258_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA258_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA258_CONS0_CONTROL */

#define CSL_HTS_DMA258_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA258_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA258_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA258_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA258_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA258_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA259_SCHEDULER_CONTROL */

#define CSL_HTS_DMA259_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA259_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA259_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA259_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA259_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA259_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA259_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA259_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA259_CONS0_CONTROL */

#define CSL_HTS_DMA259_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA259_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA259_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA259_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA259_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA259_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA260_SCHEDULER_CONTROL */

#define CSL_HTS_DMA260_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA260_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA260_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA260_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA260_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA260_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA260_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA260_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA260_CONS0_CONTROL */

#define CSL_HTS_DMA260_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA260_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA260_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA260_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA260_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA260_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA261_SCHEDULER_CONTROL */

#define CSL_HTS_DMA261_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA261_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA261_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA261_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA261_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA261_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA261_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA261_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA261_CONS0_CONTROL */

#define CSL_HTS_DMA261_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA261_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA261_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA261_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA261_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA261_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA272_SCHEDULER_CONTROL */

#define CSL_HTS_DMA272_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA272_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA272_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA272_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA272_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA272_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA272_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA272_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA272_CONS0_CONTROL */

#define CSL_HTS_DMA272_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA272_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA272_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA272_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA272_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA272_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA273_SCHEDULER_CONTROL */

#define CSL_HTS_DMA273_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA273_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA273_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA273_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA273_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA273_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA273_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA273_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA273_CONS0_CONTROL */

#define CSL_HTS_DMA273_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA273_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA273_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA273_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA273_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA273_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA274_SCHEDULER_CONTROL */

#define CSL_HTS_DMA274_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA274_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA274_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA274_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA274_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA274_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA274_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA274_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA274_CONS0_CONTROL */

#define CSL_HTS_DMA274_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA274_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA274_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA274_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA274_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA274_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA275_SCHEDULER_CONTROL */

#define CSL_HTS_DMA275_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA275_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA275_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA275_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA275_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA275_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA275_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA275_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA275_CONS0_CONTROL */

#define CSL_HTS_DMA275_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA275_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA275_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA275_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA275_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA275_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA288_SCHEDULER_CONTROL */

#define CSL_HTS_DMA288_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA288_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA288_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA288_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA288_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA288_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA288_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA288_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA288_CONS0_CONTROL */

#define CSL_HTS_DMA288_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA288_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA288_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA288_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA288_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA288_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA289_SCHEDULER_CONTROL */

#define CSL_HTS_DMA289_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA289_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA289_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA289_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA289_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA289_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA289_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA289_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA289_CONS0_CONTROL */

#define CSL_HTS_DMA289_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA289_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA289_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA289_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA289_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA289_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA290_SCHEDULER_CONTROL */

#define CSL_HTS_DMA290_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA290_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA290_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA290_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA290_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA290_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA290_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA290_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA290_CONS0_CONTROL */

#define CSL_HTS_DMA290_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA290_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA290_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA290_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA290_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA290_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA291_SCHEDULER_CONTROL */

#define CSL_HTS_DMA291_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA291_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA291_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA291_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA291_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA291_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA291_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA291_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA291_CONS0_CONTROL */

#define CSL_HTS_DMA291_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA291_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA291_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA291_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA291_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA291_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA304_SCHEDULER_CONTROL */

#define CSL_HTS_DMA304_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA304_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA304_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA304_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA304_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA304_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA304_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA304_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA304_CONS0_CONTROL */

#define CSL_HTS_DMA304_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA304_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA304_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA304_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA304_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA304_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA305_SCHEDULER_CONTROL */

#define CSL_HTS_DMA305_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA305_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA305_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA305_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA305_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA305_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA305_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA305_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA305_CONS0_CONTROL */

#define CSL_HTS_DMA305_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA305_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA305_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA305_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA305_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA305_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA306_SCHEDULER_CONTROL */

#define CSL_HTS_DMA306_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA306_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA306_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA306_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA306_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA306_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA306_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA306_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA306_CONS0_CONTROL */

#define CSL_HTS_DMA306_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA306_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA306_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA306_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA306_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA306_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA307_SCHEDULER_CONTROL */

#define CSL_HTS_DMA307_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA307_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA307_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA307_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA307_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA307_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA307_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA307_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA307_CONS0_CONTROL */

#define CSL_HTS_DMA307_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA307_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA307_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA307_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA307_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA307_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA308_SCHEDULER_CONTROL */

#define CSL_HTS_DMA308_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA308_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA308_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA308_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA308_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA308_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA308_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA308_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA308_CONS0_CONTROL */

#define CSL_HTS_DMA308_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA308_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA308_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA308_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA308_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA308_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA309_SCHEDULER_CONTROL */

#define CSL_HTS_DMA309_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA309_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA309_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA309_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA309_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA309_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA309_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA309_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA309_CONS0_CONTROL */

#define CSL_HTS_DMA309_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA309_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA309_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA309_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA309_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA309_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA310_SCHEDULER_CONTROL */

#define CSL_HTS_DMA310_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA310_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA310_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA310_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA310_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA310_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA310_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA310_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA310_CONS0_CONTROL */

#define CSL_HTS_DMA310_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA310_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA310_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA310_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA310_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA310_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA311_SCHEDULER_CONTROL */

#define CSL_HTS_DMA311_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA311_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA311_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA311_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA311_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA311_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA311_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA311_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA311_CONS0_CONTROL */

#define CSL_HTS_DMA311_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA311_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA311_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA311_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA311_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA311_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA312_SCHEDULER_CONTROL */

#define CSL_HTS_DMA312_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA312_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA312_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA312_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA312_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA312_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA312_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA312_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA312_CONS0_CONTROL */

#define CSL_HTS_DMA312_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA312_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA312_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA312_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA312_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA312_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA313_SCHEDULER_CONTROL */

#define CSL_HTS_DMA313_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA313_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA313_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA313_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA313_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA313_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA313_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA313_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA313_CONS0_CONTROL */

#define CSL_HTS_DMA313_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA313_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA313_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA313_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA313_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA313_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA336_SCHEDULER_CONTROL */

#define CSL_HTS_DMA336_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA336_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA336_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA336_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA336_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA336_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA336_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA336_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA336_CONS0_CONTROL */

#define CSL_HTS_DMA336_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA336_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA336_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA336_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA336_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA336_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA352_SCHEDULER_CONTROL */

#define CSL_HTS_DMA352_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA352_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA352_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA352_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA352_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA352_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA352_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA352_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA352_CONS0_CONTROL */

#define CSL_HTS_DMA352_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA352_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA352_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA352_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA352_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA352_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA353_SCHEDULER_CONTROL */

#define CSL_HTS_DMA353_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA353_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA353_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA353_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA353_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA353_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA353_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA353_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA353_CONS0_CONTROL */

#define CSL_HTS_DMA353_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA353_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA353_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA353_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA353_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA353_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA354_SCHEDULER_CONTROL */

#define CSL_HTS_DMA354_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA354_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA354_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA354_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA354_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA354_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA354_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA354_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA354_CONS0_CONTROL */

#define CSL_HTS_DMA354_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA354_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA354_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA354_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA354_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA354_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA355_SCHEDULER_CONTROL */

#define CSL_HTS_DMA355_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA355_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA355_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA355_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA355_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA355_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA355_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA355_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA355_CONS0_CONTROL */

#define CSL_HTS_DMA355_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA355_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA355_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA355_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA355_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA355_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA368_SCHEDULER_CONTROL */

#define CSL_HTS_DMA368_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA368_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA368_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA368_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA368_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA368_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA368_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA368_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA368_CONS0_CONTROL */

#define CSL_HTS_DMA368_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA368_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA368_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA368_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA368_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA368_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA369_SCHEDULER_CONTROL */

#define CSL_HTS_DMA369_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA369_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA369_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA369_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA369_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA369_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA369_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA369_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA369_CONS0_CONTROL */

#define CSL_HTS_DMA369_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA369_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA369_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA369_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA369_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA369_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA370_SCHEDULER_CONTROL */

#define CSL_HTS_DMA370_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA370_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA370_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA370_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA370_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA370_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA370_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA370_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA370_CONS0_CONTROL */

#define CSL_HTS_DMA370_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA370_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA370_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA370_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA370_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA370_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* DMA371_SCHEDULER_CONTROL */

#define CSL_HTS_DMA371_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MASK                   (0x001FE000U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_DMA_CHANNEL_NO_SHIFT                  (0x0000000DU)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_DMA_CHANNEL_NO_MAX                    (0x000000FFU)

#define CSL_HTS_DMA371_SCHEDULER_CONTROL_DEBUG_RDY_MASK                        (0x00001000U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_DEBUG_RDY_SHIFT                       (0x0000000CU)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_DEBUG_RDY_MAX                         (0x00000001U)

#define CSL_HTS_DMA371_SCHEDULER_CONTROL_STATE_MASK                            (0x00000780U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_STATE_SHIFT                           (0x00000007U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_STATE_MAX                             (0x0000000FU)

#define CSL_HTS_DMA371_SCHEDULER_CONTROL_PAUSE_MASK                            (0x00000040U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_PAUSE_SHIFT                           (0x00000006U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_PAUSE_MAX                             (0x00000001U)

#define CSL_HTS_DMA371_SCHEDULER_CONTROL_STRM_EN_MASK                          (0x00000020U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_STRM_EN_SHIFT                         (0x00000005U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_STRM_EN_MAX                           (0x00000001U)

#define CSL_HTS_DMA371_SCHEDULER_CONTROL_PIPELINE_NUM_MASK                     (0x0000000EU)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_PIPELINE_NUM_SHIFT                    (0x00000001U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_PIPELINE_NUM_MAX                      (0x00000007U)

#define CSL_HTS_DMA371_SCHEDULER_CONTROL_SCH_EN_MASK                           (0x00000001U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_SCH_EN_SHIFT                          (0x00000000U)
#define CSL_HTS_DMA371_SCHEDULER_CONTROL_SCH_EN_MAX                            (0x00000001U)

/* DMA371_CONS0_CONTROL */

#define CSL_HTS_DMA371_CONS0_CONTROL_PROD_SELECT_MASK                          (0x000003FEU)
#define CSL_HTS_DMA371_CONS0_CONTROL_PROD_SELECT_SHIFT                         (0x00000001U)
#define CSL_HTS_DMA371_CONS0_CONTROL_PROD_SELECT_MAX                           (0x000001FFU)

#define CSL_HTS_DMA371_CONS0_CONTROL_CONS_EN_MASK                              (0x00000001U)
#define CSL_HTS_DMA371_CONS0_CONTROL_CONS_EN_SHIFT                             (0x00000000U)
#define CSL_HTS_DMA371_CONS0_CONTROL_CONS_EN_MAX                               (0x00000001U)

/* PIPE_DBG_CNTL */

#define CSL_HTS_PIPE_DBG_CNTL_DEBUG_STATE_MASK                                 (0x000E0000U)
#define CSL_HTS_PIPE_DBG_CNTL_DEBUG_STATE_SHIFT                                (0x00000011U)
#define CSL_HTS_PIPE_DBG_CNTL_DEBUG_STATE_MAX                                  (0x00000007U)

#define CSL_HTS_PIPE_DBG_CNTL_ABORT_DEBUG_MASK                                 (0x00010000U)
#define CSL_HTS_PIPE_DBG_CNTL_ABORT_DEBUG_SHIFT                                (0x00000010U)
#define CSL_HTS_PIPE_DBG_CNTL_ABORT_DEBUG_MAX                                  (0x00000001U)

#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_6_MASK                              (0x00000040U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_6_SHIFT                             (0x00000006U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_6_MAX                               (0x00000001U)

#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_5_MASK                              (0x00000020U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_5_SHIFT                             (0x00000005U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_5_MAX                               (0x00000001U)

#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_4_MASK                              (0x00000010U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_4_SHIFT                             (0x00000004U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_4_MAX                               (0x00000001U)

#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_3_MASK                              (0x00000008U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_3_SHIFT                             (0x00000003U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_3_MAX                               (0x00000001U)

#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_2_MASK                              (0x00000004U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_2_SHIFT                             (0x00000002U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_2_MAX                               (0x00000001U)

#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_1_MASK                              (0x00000002U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_1_SHIFT                             (0x00000001U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_1_MAX                               (0x00000001U)

#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_0_MASK                              (0x00000001U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_0_SHIFT                             (0x00000000U)
#define CSL_HTS_PIPE_DBG_CNTL_PIPE_DBG_DIS_0_MAX                               (0x00000001U)

/* DBG_CAP */

#define CSL_HTS_DBG_CAP_DBG_INT_STEP_SUP_MASK                                  (0x40000000U)
#define CSL_HTS_DBG_CAP_DBG_INT_STEP_SUP_SHIFT                                 (0x0000001EU)
#define CSL_HTS_DBG_CAP_DBG_INT_STEP_SUP_MAX                                   (0x00000001U)

#define CSL_HTS_DBG_CAP_DBG_WP_DATA_SUP_MASK                                   (0x20000000U)
#define CSL_HTS_DBG_CAP_DBG_WP_DATA_SUP_SHIFT                                  (0x0000001DU)
#define CSL_HTS_DBG_CAP_DBG_WP_DATA_SUP_MAX                                    (0x00000001U)

#define CSL_HTS_DBG_CAP_DBG_OWN_SUP_MASK                                       (0x10000000U)
#define CSL_HTS_DBG_CAP_DBG_OWN_SUP_SHIFT                                      (0x0000001CU)
#define CSL_HTS_DBG_CAP_DBG_OWN_SUP_MAX                                        (0x00000001U)

#define CSL_HTS_DBG_CAP_DBG_INDIRECT_SUP_MASK                                  (0x08000000U)
#define CSL_HTS_DBG_CAP_DBG_INDIRECT_SUP_SHIFT                                 (0x0000001BU)
#define CSL_HTS_DBG_CAP_DBG_INDIRECT_SUP_MAX                                   (0x00000001U)

#define CSL_HTS_DBG_CAP_DBG_SWBP_SUP_MASK                                      (0x04000000U)
#define CSL_HTS_DBG_CAP_DBG_SWBP_SUP_SHIFT                                     (0x0000001AU)
#define CSL_HTS_DBG_CAP_DBG_SWBP_SUP_MAX                                       (0x00000001U)

#define CSL_HTS_DBG_CAP_DBQ_RESET_SUP_MASK                                     (0x02000000U)
#define CSL_HTS_DBG_CAP_DBQ_RESET_SUP_SHIFT                                    (0x00000019U)
#define CSL_HTS_DBG_CAP_DBQ_RESET_SUP_MAX                                      (0x00000001U)

#define CSL_HTS_DBG_CAP_SYS_EXE_REQ_MASK                                       (0x01000000U)
#define CSL_HTS_DBG_CAP_SYS_EXE_REQ_SHIFT                                      (0x00000018U)
#define CSL_HTS_DBG_CAP_SYS_EXE_REQ_MAX                                        (0x00000001U)

#define CSL_HTS_DBG_CAP_TRIG_OUTPUT_MASK                                       (0x00800000U)
#define CSL_HTS_DBG_CAP_TRIG_OUTPUT_SHIFT                                      (0x00000017U)
#define CSL_HTS_DBG_CAP_TRIG_OUTPUT_MAX                                        (0x00000001U)

#define CSL_HTS_DBG_CAP_TRIG_INPUT_MASK                                        (0x00400000U)
#define CSL_HTS_DBG_CAP_TRIG_INPUT_SHIFT                                       (0x00000016U)
#define CSL_HTS_DBG_CAP_TRIG_INPUT_MAX                                         (0x00000001U)

#define CSL_HTS_DBG_CAP_TRIG_CHNS_MASK                                         (0x00300000U)
#define CSL_HTS_DBG_CAP_TRIG_CHNS_SHIFT                                        (0x00000014U)
#define CSL_HTS_DBG_CAP_TRIG_CHNS_MAX                                          (0x00000003U)

#define CSL_HTS_DBG_CAP_NUM_CNTRS_MASK                                         (0x000F0000U)
#define CSL_HTS_DBG_CAP_NUM_CNTRS_SHIFT                                        (0x00000010U)
#define CSL_HTS_DBG_CAP_NUM_CNTRS_MAX                                          (0x0000000FU)

#define CSL_HTS_DBG_CAP_NUM_WPS_MASK                                           (0x0000F000U)
#define CSL_HTS_DBG_CAP_NUM_WPS_SHIFT                                          (0x0000000CU)
#define CSL_HTS_DBG_CAP_NUM_WPS_MAX                                            (0x0000000FU)

#define CSL_HTS_DBG_CAP_NUM_BPS_MASK                                           (0x00000F00U)
#define CSL_HTS_DBG_CAP_NUM_BPS_SHIFT                                          (0x00000008U)
#define CSL_HTS_DBG_CAP_NUM_BPS_MAX                                            (0x0000000FU)

#define CSL_HTS_DBG_CAP_REV_MAJ_MASK                                           (0x000000F0U)
#define CSL_HTS_DBG_CAP_REV_MAJ_SHIFT                                          (0x00000004U)
#define CSL_HTS_DBG_CAP_REV_MAJ_MAX                                            (0x0000000FU)

#define CSL_HTS_DBG_CAP_REV_MIN_MASK                                           (0x0000000FU)
#define CSL_HTS_DBG_CAP_REV_MIN_SHIFT                                          (0x00000000U)
#define CSL_HTS_DBG_CAP_REV_MIN_MAX                                            (0x0000000FU)

/* DBG_CNTL */

#define CSL_HTS_DBG_CNTL_DBG_RESET_OCC_MASK                                    (0x04000000U)
#define CSL_HTS_DBG_CNTL_DBG_RESET_OCC_SHIFT                                   (0x0000001AU)
#define CSL_HTS_DBG_CNTL_DBG_RESET_OCC_MAX                                     (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_EMU0_CNTL_MASK                                    (0x000F0000U)
#define CSL_HTS_DBG_CNTL_DBG_EMU0_CNTL_SHIFT                                   (0x00000010U)
#define CSL_HTS_DBG_CNTL_DBG_EMU0_CNTL_MAX                                     (0x0000000FU)

#define CSL_HTS_DBG_CNTL_DBG_HALT_EMU0_MASK                                    (0x00001000U)
#define CSL_HTS_DBG_CNTL_DBG_HALT_EMU0_SHIFT                                   (0x0000000CU)
#define CSL_HTS_DBG_CNTL_DBG_HALT_EMU0_MAX                                     (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_HALT_USER_MASK                                    (0x00000800U)
#define CSL_HTS_DBG_CNTL_DBG_HALT_USER_SHIFT                                   (0x0000000BU)
#define CSL_HTS_DBG_CNTL_DBG_HALT_USER_MAX                                     (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_HALT_STEP_MASK                                    (0x00000400U)
#define CSL_HTS_DBG_CNTL_DBG_HALT_STEP_SHIFT                                   (0x0000000AU)
#define CSL_HTS_DBG_CNTL_DBG_HALT_STEP_MAX                                     (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_EXE_STAT_MASK                                     (0x00000080U)
#define CSL_HTS_DBG_CNTL_DBG_EXE_STAT_SHIFT                                    (0x00000007U)
#define CSL_HTS_DBG_CNTL_DBG_EXE_STAT_MAX                                      (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_EMU0_EN_MASK                                      (0x00000020U)
#define CSL_HTS_DBG_CNTL_DBG_EMU0_EN_SHIFT                                     (0x00000005U)
#define CSL_HTS_DBG_CNTL_DBG_EMU0_EN_MAX                                       (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_SINGLE_STEP_EN_MASK                               (0x00000004U)
#define CSL_HTS_DBG_CNTL_DBG_SINGLE_STEP_EN_SHIFT                              (0x00000002U)
#define CSL_HTS_DBG_CNTL_DBG_SINGLE_STEP_EN_MAX                                (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_RESTART_MASK                                      (0x00000002U)
#define CSL_HTS_DBG_CNTL_DBG_RESTART_SHIFT                                     (0x00000001U)
#define CSL_HTS_DBG_CNTL_DBG_RESTART_MAX                                       (0x00000001U)

#define CSL_HTS_DBG_CNTL_DBG_HALT_MASK                                         (0x00000001U)
#define CSL_HTS_DBG_CNTL_DBG_HALT_SHIFT                                        (0x00000000U)
#define CSL_HTS_DBG_CNTL_DBG_HALT_MAX                                          (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif
