/*
 * test_pruss_intc_mapping.h
 *
 * PRUICSS INTC mapping for UIO sample application
 *
 * Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/
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

/*
 * ============================================================================
 * Copyright (c) Texas Instruments Inc 2015
 *
 * Use of this software is controlled by the terms and conditions found in the
 * license agreement under which this software has been supplied or provided.
 * ============================================================================
*/
//SYS_EVT_16-31 can be used for generating interrupts for IPC with hosts/prus etc


#define ARM_PRU0_EVENT       16
#define PRU0_ARM_EVENT       17
#define ARM_PRU1_EVENT       18
#define PRU1_ARM_EVENT       19
/*#else
#define ARM_PRU0_EVENT       32
#define PRU0_ARM_EVENT       33
#define ARM_PRU1_EVENT       34
#define PRU1_ARM_EVENT       35
#endif
*/
#define CHANNEL0                0
#define CHANNEL1                1
#define CHANNEL2                2
#define CHANNEL3                3
#define CHANNEL4                4
#define CHANNEL5                5
#define CHANNEL6                6
#define CHANNEL7                7
#define CHANNEL8                8
#define CHANNEL9                9

#define PRU0                    0
#define PRU1                    1
#define PRU_EVTOUT0             2
#define PRU_EVTOUT1             3
#define PRU_EVTOUT2             4
#define PRU_EVTOUT3             5
#define PRU_EVTOUT4             6
#define PRU_EVTOUT5             7
#define PRU_EVTOUT6             8
#define PRU_EVTOUT7             9

#define PRU0_HOSTEN_MASK            0x0001
#define PRU1_HOSTEN_MASK            0x0002
#define PRU_EVTOUT0_HOSTEN_MASK     0x0004
#define PRU_EVTOUT1_HOSTEN_MASK     0x0008
#define PRU_EVTOUT2_HOSTEN_MASK     0x0010
#define PRU_EVTOUT3_HOSTEN_MASK     0x0020
#define PRU_EVTOUT4_HOSTEN_MASK     0x0040
#define PRU_EVTOUT5_HOSTEN_MASK     0x0080
#define PRU_EVTOUT6_HOSTEN_MASK     0x0100
#define PRU_EVTOUT7_HOSTEN_MASK     0x0200
#define SYS_EVT_POLARITY_LOW        0
#define SYS_EVT_POLARITY_HIGH       1

#define SYS_EVT_TYPE_PULSE          0
#define SYS_EVT_TYPE_EDGE           1

#define PRUICSS_INTC_INITDATA {   \
{ ARM_PRU0_EVENT, PRU0_ARM_EVENT, ARM_PRU1_EVENT, PRU1_ARM_EVENT,0xFF  },  \
{ {ARM_PRU0_EVENT,CHANNEL0, SYS_EVT_POLARITY_HIGH ,SYS_EVT_TYPE_PULSE}, {PRU0_ARM_EVENT, CHANNEL2,SYS_EVT_POLARITY_HIGH ,SYS_EVT_TYPE_PULSE}, {ARM_PRU1_EVENT,CHANNEL1,SYS_EVT_POLARITY_HIGH ,SYS_EVT_TYPE_PULSE}, {PRU1_ARM_EVENT, CHANNEL3,SYS_EVT_POLARITY_HIGH ,SYS_EVT_TYPE_PULSE}, {0xFF,0xFF,0xFF,0xFF}},  \
 {  {CHANNEL0,PRU0}, {CHANNEL1, PRU1}, {CHANNEL2, PRU_EVTOUT0}, {CHANNEL3, PRU_EVTOUT1}, {CHANNEL4, PRU_EVTOUT2}, {0xFF,0xFF} },  \
 (PRU0_HOSTEN_MASK | PRU1_HOSTEN_MASK | PRU_EVTOUT0_HOSTEN_MASK | PRU_EVTOUT1_HOSTEN_MASK) /*Enable PRU0/1, PRU_EVTOUT0/1*/ \
}
