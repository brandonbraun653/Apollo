/**
 * @file   fw_mem_section.h
 *
 * @brief  This file tests the ICSS-EMAC driver APIs for ICE_K2G
 */
/*
 * Copyright (c) 2015-2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef FW_MEM_SECTION_H
#define FW_MEM_SECTION_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SOC_AM335x
extern uint8_t pru_imem0_rev1_start;         /*start address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem0_rev1_end;           /*end address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_start;         /*start address for PRU1 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_end;           /*end address for PRU1 binary array for Revision 1*/

extern uint8_t pru_dmem0_rev1_start;         /*start address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem0_rev1_end;           /*end address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_start;         /*start address for DMEM PRU1 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_end;           /*end address for DMEM PRU1 binary array for Revision 1*/
#endif

#ifdef SOC_AM437x
extern uint8_t pru_imem0_rev1_start;         /*start address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem0_rev1_end;           /*end address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_start;         /*start address for PRU1 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_end;           /*end address for PRU1 binary array for Revision 1*/

extern uint8_t pru_dmem0_rev1_start;         /*start address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem0_rev1_end;           /*end address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_start;         /*start address for DMEM PRU1 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_end;           /*end address for DMEM PRU1 binary array for Revision 1*/
#endif

#if defined(__TI_ARM_V7M4__) || defined(__ARM_ARCH_7A__)
#ifdef SOC_AM571x
extern uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/
extern uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/
#endif

#ifdef SOC_AM574x
extern uint8_t pru_imem0_rev1_start;         /*start address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem0_rev1_end;           /*end address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_start;         /*start address for PRU1 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_end;           /*end address for PRU1 binary array for Revision 1*/
extern uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/

extern uint8_t pru_dmem0_rev1_start;         /*start address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem0_rev1_end;           /*end address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_start;         /*start address for DMEM PRU1 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_end;           /*end address for DMEM PRU1 binary array for Revision 1*/
extern uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/

#endif

#ifdef SOC_AM572x
extern uint8_t pru_imem0_rev1_start;         /*start address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem0_rev1_end;           /*end address for PRU0 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_start;         /*start address for PRU1 binary array for Revision 1*/
extern uint8_t pru_imem1_rev1_end;           /*end address for PRU1 binary array for Revision 1*/
extern uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/

extern uint8_t pru_dmem0_rev1_start;         /*start address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem0_rev1_end;           /*end address for DMEM PRU0 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_start;         /*start address for DMEM PRU1 binary array for Revision 1*/
extern uint8_t pru_dmem1_rev1_end;           /*end address for DMEM PRU1 binary array for Revision 1*/
extern uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/

#endif

#ifdef SOC_K2G
extern uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/

extern uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/
#endif

#else
#ifdef SOC_AM571x
extern far uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/
extern far uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/
#endif

#ifdef SOC_AM574x
extern far uint8_t pru_imem0_rev1_start;         /*start address for PRU0 binary array for Revision 1*/
extern far uint8_t pru_imem0_rev1_end;           /*end address for PRU0 binary array for Revision 1*/
extern far uint8_t pru_imem1_rev1_start;         /*start address for PRU1 binary array for Revision 1*/
extern far uint8_t pru_imem1_rev1_end;           /*end address for PRU1 binary array for Revision 1*/
extern far uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/

extern far uint8_t pru_dmem0_rev1_start;         /*start address for DMEM PRU0 binary array for Revision 1*/
extern far uint8_t pru_dmem0_rev1_end;           /*end address for DMEM PRU0 binary array for Revision 1*/
extern far uint8_t pru_dmem1_rev1_start;         /*start address for DMEM PRU1 binary array for Revision 1*/
extern far uint8_t pru_dmem1_rev1_end;           /*end address for DMEM PRU1 binary array for Revision 1*/
extern far uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/

#endif

#ifdef SOC_AM572x
extern far uint8_t pru_imem0_rev1_start;         /*start address for PRU0 binary array for Revision 1*/
extern far uint8_t pru_imem0_rev1_end;           /*end address for PRU0 binary array for Revision 1*/
extern far uint8_t pru_imem1_rev1_start;         /*start address for PRU1 binary array for Revision 1*/
extern far uint8_t pru_imem1_rev1_end;           /*end address for PRU1 binary array for Revision 1*/
extern far uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/

extern far uint8_t pru_dmem0_rev1_start;         /*start address for DMEM PRU0 binary array for Revision 1*/
extern far uint8_t pru_dmem0_rev1_end;           /*end address for DMEM PRU0 binary array for Revision 1*/
extern far uint8_t pru_dmem1_rev1_start;         /*start address for DMEM PRU1 binary array for Revision 1*/
extern far uint8_t pru_dmem1_rev1_end;           /*end address for DMEM PRU1 binary array for Revision 1*/
extern far uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/

#endif

#ifdef SOC_K2G
extern far uint8_t pru_imem0_rev2_start;         /*start address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem0_rev2_end;           /*end address for PRU0 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_start;         /*start address for PRU1 binary array for Revision 2*/
extern far uint8_t pru_imem1_rev2_end;           /*end address for PRU1 binary array for Revision 2*/

extern far uint8_t pru_dmem0_rev2_start;         /*start address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem0_rev2_end;           /*end address for DMEM PRU0 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_start;         /*start address for DMEM PRU1 binary array for Revision 2*/
extern far uint8_t pru_dmem1_rev2_end;           /*end address for DMEM PRU1 binary array for Revision 2*/
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* FW_MEM_SECTION_H */
