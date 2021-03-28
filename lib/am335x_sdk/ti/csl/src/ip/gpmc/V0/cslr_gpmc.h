/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_GPMC_H
#define CSLR_GPMC_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for ALL
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint32 SYSSTS;
    volatile Uint32 IRQSTS;
    volatile Uint32 IRQEN;
    volatile Uint8  RSVD1[32];
    volatile Uint32 TIMEOUT_CTRL;
    volatile Uint32 ERR_ADDR;
    volatile Uint32 ERR_TYPE;
    volatile Uint8  RSVD2[4];
    volatile Uint32 CONFIG;
    volatile Uint32 STS;
    volatile Uint8  RSVD3[8];
    volatile Uint32 CONFIG1_0;
    volatile Uint32 CONFIG2_0;
    volatile Uint32 CONFIG3_0;
    volatile Uint32 CONFIG4_0;
    volatile Uint32 CONFIG5_0;
    volatile Uint32 CONFIG6_0;
    volatile Uint32 CONFIG7_0;
    volatile Uint32 NAND_COMMAND_0;
    volatile Uint32 NAND_ADDR_0;
    volatile Uint32 NAND_DATA_0;
    volatile Uint8  RSVD4[8];
    volatile Uint32 CONFIG1_1;
    volatile Uint32 CONFIG2_1;
    volatile Uint32 CONFIG3_1;
    volatile Uint32 CONFIG4_1;
    volatile Uint32 CONFIG5_1;
    volatile Uint32 CONFIG6_1;
    volatile Uint32 CONFIG7_1;
    volatile Uint32 NAND_COMMAND_1;
    volatile Uint32 NAND_ADDR_1;
    volatile Uint32 NAND_DATA_1;
    volatile Uint8  RSVD5[8];
    volatile Uint32 CONFIG1_2;
    volatile Uint32 CONFIG2_2;
    volatile Uint32 CONFIG3_2;
    volatile Uint32 CONFIG4_2;
    volatile Uint32 CONFIG5_2;
    volatile Uint32 CONFIG6_2;
    volatile Uint32 CONFIG7_2;
    volatile Uint32 NAND_COMMAND_2;
    volatile Uint32 NAND_ADDR_2;
    volatile Uint32 NAND_DATA_2;
    volatile Uint8  RSVD6[8];
    volatile Uint32 CONFIG1_3;
    volatile Uint32 CONFIG2_3;
    volatile Uint32 CONFIG3_3;
    volatile Uint32 CONFIG4_3;
    volatile Uint32 CONFIG5_3;
    volatile Uint32 CONFIG6_3;
    volatile Uint32 CONFIG7_3;
    volatile Uint32 NAND_COMMAND_3;
    volatile Uint32 NAND_ADDR_3;
    volatile Uint32 NAND_DATA_3;
    volatile Uint8  RSVD7[8];
    volatile Uint32 CONFIG1_4;
    volatile Uint32 CONFIG2_4;
    volatile Uint32 CONFIG3_4;
    volatile Uint32 CONFIG4_4;
    volatile Uint32 CONFIG5_4;
    volatile Uint32 CONFIG6_4;
    volatile Uint32 CONFIG7_4;
    volatile Uint32 NAND_COMMAND_4;
    volatile Uint32 NAND_ADDR_4;
    volatile Uint32 NAND_DATA_4;
    volatile Uint8  RSVD8[8];
    volatile Uint32 CONFIG1_5;
    volatile Uint32 CONFIG2_5;
    volatile Uint32 CONFIG3_5;
    volatile Uint32 CONFIG4_5;
    volatile Uint32 CONFIG5_5;
    volatile Uint32 CONFIG6_5;
    volatile Uint32 CONFIG7_5;
    volatile Uint32 NAND_COMMAND_5;
    volatile Uint32 NAND_ADDR_5;
    volatile Uint32 NAND_DATA_5;
    volatile Uint8  RSVD9[8];
    volatile Uint32 CONFIG1_6;
    volatile Uint32 CONFIG2_6;
    volatile Uint32 CONFIG3_6;
    volatile Uint32 CONFIG4_6;
    volatile Uint32 CONFIG5_6;
    volatile Uint32 CONFIG6_6;
    volatile Uint32 CONFIG7_6;
    volatile Uint32 NAND_COMMAND_6;
    volatile Uint32 NAND_ADDR_6;
    volatile Uint32 NAND_DATA_6;
    volatile Uint8  RSVD10[56];
    volatile Uint32 PREFETCH_CONFIG1;
    volatile Uint32 PREFETCH_CONFIG2;
    volatile Uint8  RSVD11[4];
    volatile Uint32 PREFETCH_CTRL;
    volatile Uint32 PREFETCH_STS;
    volatile Uint32 ECC_CONFIG;
    volatile Uint32 ECC_CTRL;
    volatile Uint32 ECC_SIZE_CONFIG;
    volatile Uint32 ECC1_RESULT;
    volatile Uint32 ECC2_RESULT;
    volatile Uint32 ECC3_RESULT;
    volatile Uint32 ECC4_RESULT;
    volatile Uint32 ECC5_RESULT;
    volatile Uint32 ECC6_RESULT;
    volatile Uint32 ECC7_RESULT;
    volatile Uint32 ECC8_RESULT;
    volatile Uint32 ECC9_RESULT;
    volatile Uint8  RSVD12[28];
    volatile Uint32 BCH_RESULT0_0;
    volatile Uint32 BCH_RESULT1_0;
    volatile Uint32 BCH_RESULT2_0;
    volatile Uint32 BCH_RESULT3_0;
    volatile Uint32 BCH_RESULT0_1;
    volatile Uint32 BCH_RESULT1_1;
    volatile Uint32 BCH_RESULT2_1;
    volatile Uint32 BCH_RESULT3_1;
    volatile Uint32 BCH_RESULT0_2;
    volatile Uint32 BCH_RESULT1_2;
    volatile Uint32 BCH_RESULT2_2;
    volatile Uint32 BCH_RESULT3_2;
    volatile Uint32 BCH_RESULT0_3;
    volatile Uint32 BCH_RESULT1_3;
    volatile Uint32 BCH_RESULT2_3;
    volatile Uint32 BCH_RESULT3_3;
    volatile Uint32 BCH_RESULT0_4;
    volatile Uint32 BCH_RESULT1_4;
    volatile Uint32 BCH_RESULT2_4;
    volatile Uint32 BCH_RESULT3_4;
    volatile Uint32 BCH_RESULT0_5;
    volatile Uint32 BCH_RESULT1_5;
    volatile Uint32 BCH_RESULT2_5;
    volatile Uint32 BCH_RESULT3_5;
    volatile Uint32 BCH_RESULT0_6;
    volatile Uint32 BCH_RESULT1_6;
    volatile Uint32 BCH_RESULT2_6;
    volatile Uint32 BCH_RESULT3_6;
    volatile Uint8  RSVD13[32];
    volatile Uint32 BCH_SWDATA;
    volatile Uint8  RSVD14[44];
    volatile Uint32 BCH_RESULT4_0;
    volatile Uint32 BCH_RESULT5_0;
    volatile Uint32 BCH_RESULT6_0;
    volatile Uint8  RSVD15[4];
    volatile Uint32 BCH_RESULT4_1;
    volatile Uint32 BCH_RESULT5_1;
    volatile Uint32 BCH_RESULT6_1;
    volatile Uint8  RSVD16[4];
    volatile Uint32 BCH_RESULT4_2;
    volatile Uint32 BCH_RESULT5_2;
    volatile Uint32 BCH_RESULT6_2;
    volatile Uint8  RSVD17[4];
    volatile Uint32 BCH_RESULT4_3;
    volatile Uint32 BCH_RESULT5_3;
    volatile Uint32 BCH_RESULT6_3;
    volatile Uint8  RSVD18[4];
    volatile Uint32 BCH_RESULT4_4;
    volatile Uint32 BCH_RESULT5_4;
    volatile Uint32 BCH_RESULT6_4;
    volatile Uint8  RSVD19[4];
    volatile Uint32 BCH_RESULT4_5;
    volatile Uint32 BCH_RESULT5_5;
    volatile Uint32 BCH_RESULT6_5;
    volatile Uint8  RSVD20[4];
    volatile Uint32 BCH_RESULT4_6;
    volatile Uint32 BCH_RESULT5_6;
    volatile Uint32 BCH_RESULT6_6;
    volatile Uint8  RSVD21[2612];
} CSL_GpmcRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* BCH_RESULT4_6 */
#define CSL_GPMC_BCH_RESULT4_6                                  (0x360U)

/* BCH_RESULT1_0 */
#define CSL_GPMC_BCH_RESULT1_0                                  (0x244U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_ADDR_2                                    (0xE0U)

/* Chip-select address mapping configuration. */
#define CSL_GPMC_CONFIG7_4                                      (0x138U)

/* Chip-select address mapping configuration. */
#define CSL_GPMC_CONFIG7_5                                      (0x168U)

/* BCH_RESULT4_4 */
#define CSL_GPMC_BCH_RESULT4_4                                  (0x340U)

/* BCH_RESULT6_0 */
#define CSL_GPMC_BCH_RESULT6_0                                  (0x308U)

/* ADV# signal timing parameter configuration. */
#define CSL_GPMC_CONFIG3_3                                      (0xF8U)

/* The GPMC_IRQENABLE interrupt enable register allows to mask/unmask the 
 * module internal sources of interrupt, on a event-by-event basis. */
#define CSL_GPMC_IRQEN                                          (0x1CU)

/* BCH_RESULT0_1 */
#define CSL_GPMC_BCH_RESULT0_1                                  (0x250U)

/* ECC7_RESULT */
#define CSL_GPMC_ECC7_RESULT                                    (0x218U)

/* ECC_SIZE_CONFIG */
#define CSL_GPMC_ECC_SIZE_CONFIG                                (0x1FCU)

/* BCH_RESULT4_0 */
#define CSL_GPMC_BCH_RESULT4_0                                  (0x300U)

/* The GPMC_ERR_TYPE register stores the type of error when an error occurs. */
#define CSL_GPMC_ERR_TYPE                                       (0x48U)

/* BCH_RESULT2_2 */
#define CSL_GPMC_BCH_RESULT2_2                                  (0x268U)

/* WE# and OE# signals timing parameter configuration. */
#define CSL_GPMC_CONFIG4_5                                      (0x15CU)

/* WE# and OE# signals timing parameter configuration. */
#define CSL_GPMC_CONFIG4_3                                      (0xFCU)

/* BCH_RESULT5_3 */
#define CSL_GPMC_BCH_RESULT5_3                                  (0x334U)

/* This register is used to directly pass data to the BCH ECC calculator 
 * without accessing the actual NAND flash interface. */
#define CSL_GPMC_BCH_SWDATA                                     (0x2D0U)

/* The configuration 1 register sets signal control parameters per chip 
 * select. */
#define CSL_GPMC_CONFIG1_6                                      (0x180U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_DATA_2                                    (0xE4U)

/* BCH_RESULT0_3 */
#define CSL_GPMC_BCH_RESULT0_3                                  (0x270U)

/* WE# and OE# signals timing parameter configuration. */
#define CSL_GPMC_CONFIG4_1                                      (0x9CU)

/* BCH_RESULT0_0 */
#define CSL_GPMC_BCH_RESULT0_0                                  (0x240U)

/* BCH_RESULT5_6 */
#define CSL_GPMC_BCH_RESULT5_6                                  (0x364U)

/* The GPMC_IRQSTATUS interrupt status register regroups all the status of the 
 * module internal events that can generate an interrupt. */
#define CSL_GPMC_IRQSTS                                         (0x18U)

/* PREFETCH_CONFIG2 */
#define CSL_GPMC_PREFETCH_CONFIG2                               (0x1E4U)

/* The configuration 1 register sets signal control parameters per chip 
 * select. */
#define CSL_GPMC_CONFIG1_4                                      (0x120U)

/* ECC8_RESULT */
#define CSL_GPMC_ECC8_RESULT                                    (0x21CU)

/* BCH_RESULT0_5 */
#define CSL_GPMC_BCH_RESULT0_5                                  (0x290U)

/* The configuration 1 register sets signal control parameters per chip 
 * select. */
#define CSL_GPMC_CONFIG1_3                                      (0xF0U)

/* ECC9_RESULT */
#define CSL_GPMC_ECC9_RESULT                                    (0x220U)

/* RdAccessTime and CycleTime timing parameters configuration. */
#define CSL_GPMC_CONFIG5_4                                      (0x130U)

/* WE# and OE# signals timing parameter configuration. */
#define CSL_GPMC_CONFIG4_0                                      (0x6CU)

/* BCH_RESULT4_2 */
#define CSL_GPMC_BCH_RESULT4_2                                  (0x320U)

/* ADV# signal timing parameter configuration. */
#define CSL_GPMC_CONFIG3_0                                      (0x68U)

/* BCH_RESULT3_1 */
#define CSL_GPMC_BCH_RESULT3_1                                  (0x25CU)

/* BCH_RESULT5_0 */
#define CSL_GPMC_BCH_RESULT5_0                                  (0x304U)

/* The GPMC_SYSSTATUS register provides status information about the module, 
 * excluding the interrupt status information. */
#define CSL_GPMC_SYSSTS                                         (0x14U)

/* PREFETCH_STS */
#define CSL_GPMC_PREFETCH_STS                                   (0x1F0U)

/* WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle, and BusTurnAround parameters 
 * configuration */
#define CSL_GPMC_CONFIG6_3                                      (0x104U)

/* The status register provides global status bits of the GPMC. */
#define CSL_GPMC_STS                                            (0x54U)

/* Chip-select signal timing parameter configuration. */
#define CSL_GPMC_CONFIG2_6                                      (0x184U)

/* BCH_RESULT6_5 */
#define CSL_GPMC_BCH_RESULT6_5                                  (0x358U)

/* ECC_CTRL */
#define CSL_GPMC_ECC_CTRL                                       (0x1F8U)

/* ADV# signal timing parameter configuration. */
#define CSL_GPMC_CONFIG3_6                                      (0x188U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_ADDR_5                                    (0x170U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_COMMAND_0                                 (0x7CU)

/* ADV# signal timing parameter configuration. */
#define CSL_GPMC_CONFIG3_1                                      (0x98U)

/* WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle, and BusTurnAround parameters 
 * configuration */
#define CSL_GPMC_CONFIG6_5                                      (0x164U)

/* RdAccessTime and CycleTime timing parameters configuration. */
#define CSL_GPMC_CONFIG5_3                                      (0x100U)

/* BCH_RESULT3_5 */
#define CSL_GPMC_BCH_RESULT3_5                                  (0x29CU)

/* ECC1_RESULT */
#define CSL_GPMC_ECC1_RESULT                                    (0x200U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_ADDR_0                                    (0x80U)

/* ECC3_RESULT */
#define CSL_GPMC_ECC3_RESULT                                    (0x208U)

/* BCH_RESULT0_6 */
#define CSL_GPMC_BCH_RESULT0_6                                  (0x2A0U)

/* RdAccessTime and CycleTime timing parameters configuration. */
#define CSL_GPMC_CONFIG5_6                                      (0x190U)

/* The configuration 1 register sets signal control parameters per chip 
 * select. */
#define CSL_GPMC_CONFIG1_2                                      (0xC0U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_DATA_4                                    (0x144U)

/* Chip-select signal timing parameter configuration. */
#define CSL_GPMC_CONFIG2_0                                      (0x64U)

/* RdAccessTime and CycleTime timing parameters configuration. */
#define CSL_GPMC_CONFIG5_0                                      (0x70U)

/* BCH_RESULT6_6 */
#define CSL_GPMC_BCH_RESULT6_6                                  (0x368U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_ADDR_4                                    (0x140U)

/* ECC6_RESULT */
#define CSL_GPMC_ECC6_RESULT                                    (0x214U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_DATA_6                                    (0x1A4U)

/* The GPMC_REVISION register contains the IP revision code. */
#define CSL_GPMC_REVISION                                       (0x0U)

/* WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle, and BusTurnAround parameters 
 * configuration */
#define CSL_GPMC_CONFIG6_1                                      (0xA4U)

/* BCH_RESULT1_2 */
#define CSL_GPMC_BCH_RESULT1_2                                  (0x264U)

/* Chip-select signal timing parameter configuration. */
#define CSL_GPMC_CONFIG2_3                                      (0xF4U)

/* The GPMC_SYSCONFIG register controls the various parameters of the OCP 
 * interface. */
#define CSL_GPMC_SYSCONFIG                                      (0x10U)

/* BCH_RESULT2_1 */
#define CSL_GPMC_BCH_RESULT2_1                                  (0x258U)

/* BCH_RESULT5_4 */
#define CSL_GPMC_BCH_RESULT5_4                                  (0x344U)

/* The configuration 1 register sets signal control parameters per chip 
 * select. */
#define CSL_GPMC_CONFIG1_0                                      (0x60U)

/* BCH_RESULT1_5 */
#define CSL_GPMC_BCH_RESULT1_5                                  (0x294U)

/* Chip-select address mapping configuration. */
#define CSL_GPMC_CONFIG7_2                                      (0xD8U)

/* BCH_RESULT3_3 */
#define CSL_GPMC_BCH_RESULT3_3                                  (0x27CU)

/* BCH_RESULT2_5 */
#define CSL_GPMC_BCH_RESULT2_5                                  (0x298U)

/* Chip-select address mapping configuration. */
#define CSL_GPMC_CONFIG7_3                                      (0x108U)

/* Chip-select signal timing parameter configuration. */
#define CSL_GPMC_CONFIG2_1                                      (0x94U)

/* Chip-select address mapping configuration. */
#define CSL_GPMC_CONFIG7_6                                      (0x198U)

/* The configuration 1 register sets signal control parameters per chip 
 * select. */
#define CSL_GPMC_CONFIG1_1                                      (0x90U)

/* The configuration register allows global configuration of the GPMC. */
#define CSL_GPMC_CONFIG                                         (0x50U)

/* ECC_CONFIG */
#define CSL_GPMC_ECC_CONFIG                                     (0x1F4U)

/* BCH_RESULT4_5 */
#define CSL_GPMC_BCH_RESULT4_5                                  (0x350U)

/* BCH_RESULT6_3 */
#define CSL_GPMC_BCH_RESULT6_3                                  (0x338U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_ADDR_3                                    (0x110U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_ADDR_1                                    (0xB0U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_DATA_1                                    (0xB4U)

/* Chip-select address mapping configuration. */
#define CSL_GPMC_CONFIG7_0                                      (0x78U)

/* WE# and OE# signals timing parameter configuration. */
#define CSL_GPMC_CONFIG4_6                                      (0x18CU)

/* BCH_RESULT5_2 */
#define CSL_GPMC_BCH_RESULT5_2                                  (0x324U)

/* ADV# signal timing parameter configuration. */
#define CSL_GPMC_CONFIG3_5                                      (0x158U)

/* RdAccessTime and CycleTime timing parameters configuration. */
#define CSL_GPMC_CONFIG5_1                                      (0xA0U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_COMMAND_4                                 (0x13CU)

/* BCH_RESULT3_6 */
#define CSL_GPMC_BCH_RESULT3_6                                  (0x2ACU)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_DATA_0                                    (0x84U)

/* BCH_RESULT4_1 */
#define CSL_GPMC_BCH_RESULT4_1                                  (0x310U)

/* BCH_RESULT6_1 */
#define CSL_GPMC_BCH_RESULT6_1                                  (0x318U)

/* PREFETCH_CTRL */
#define CSL_GPMC_PREFETCH_CTRL                                  (0x1ECU)

/* ECC2_RESULT */
#define CSL_GPMC_ECC2_RESULT                                    (0x204U)

/* BCH_RESULT6_4 */
#define CSL_GPMC_BCH_RESULT6_4                                  (0x348U)

/* RdAccessTime and CycleTime timing parameters configuration. */
#define CSL_GPMC_CONFIG5_5                                      (0x160U)

/* BCH_RESULT0_4 */
#define CSL_GPMC_BCH_RESULT0_4                                  (0x280U)

/* ADV# signal timing parameter configuration. */
#define CSL_GPMC_CONFIG3_4                                      (0x128U)

/* ADV# signal timing parameter configuration. */
#define CSL_GPMC_CONFIG3_2                                      (0xC8U)

/* BCH_RESULT1_6 */
#define CSL_GPMC_BCH_RESULT1_6                                  (0x2A4U)

/* BCH_RESULT3_0 */
#define CSL_GPMC_BCH_RESULT3_0                                  (0x24CU)

/* BCH_RESULT0_2 */
#define CSL_GPMC_BCH_RESULT0_2                                  (0x260U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_COMMAND_2                                 (0xDCU)

/* PREFETCH_CONFIG1 */
#define CSL_GPMC_PREFETCH_CONFIG1                               (0x1E0U)

/* ECC5_RESULT */
#define CSL_GPMC_ECC5_RESULT                                    (0x210U)

/* BCH_RESULT3_2 */
#define CSL_GPMC_BCH_RESULT3_2                                  (0x26CU)

/* BCH_RESULT4_3 */
#define CSL_GPMC_BCH_RESULT4_3                                  (0x330U)

/* BCH_RESULT1_4 */
#define CSL_GPMC_BCH_RESULT1_4                                  (0x284U)

/* BCH_RESULT2_4 */
#define CSL_GPMC_BCH_RESULT2_4                                  (0x288U)

/* BCH_RESULT3_4 */
#define CSL_GPMC_BCH_RESULT3_4                                  (0x28CU)

/* WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle, and BusTurnAround parameters 
 * configuration */
#define CSL_GPMC_CONFIG6_2                                      (0xD4U)

/* BCH_RESULT2_3 */
#define CSL_GPMC_BCH_RESULT2_3                                  (0x278U)

/* ECC4_RESULT */
#define CSL_GPMC_ECC4_RESULT                                    (0x20CU)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_COMMAND_5                                 (0x16CU)

/* BCH_RESULT2_6 */
#define CSL_GPMC_BCH_RESULT2_6                                  (0x2A8U)

/* WE# and OE# signals timing parameter configuration. */
#define CSL_GPMC_CONFIG4_4                                      (0x12CU)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_ADDR_6                                    (0x1A0U)

/* RdAccessTime and CycleTime timing parameters configuration. */
#define CSL_GPMC_CONFIG5_2                                      (0xD0U)

/* WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle, and BusTurnAround parameters 
 * configuration */
#define CSL_GPMC_CONFIG6_6                                      (0x194U)

/* BCH_RESULT5_1 */
#define CSL_GPMC_BCH_RESULT5_1                                  (0x314U)

/* The GPMC_ERR_ADDRESS register stores the address of the illegal access when 
 * an error occurs. */
#define CSL_GPMC_ERR_ADDR                                       (0x44U)

/* The configuration 1 register sets signal control parameters per chip 
 * select. */
#define CSL_GPMC_CONFIG1_5                                      (0x150U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_COMMAND_3                                 (0x10CU)

/* BCH_RESULT1_3 */
#define CSL_GPMC_BCH_RESULT1_3                                  (0x274U)

/* WE# and OE# signals timing parameter configuration. */
#define CSL_GPMC_CONFIG4_2                                      (0xCCU)

/* BCH_RESULT1_1 */
#define CSL_GPMC_BCH_RESULT1_1                                  (0x254U)

/* WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle, and BusTurnAround parameters 
 * configuration */
#define CSL_GPMC_CONFIG6_4                                      (0x134U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_COMMAND_6                                 (0x19CU)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_DATA_3                                    (0x114U)

/* Chip-select address mapping configuration. */
#define CSL_GPMC_CONFIG7_1                                      (0xA8U)

/* The GPMC_TIMEOUT_CONTROL register allows the user to set the start value of 
 * the timeout counter */
#define CSL_GPMC_TIMEOUT_CTRL                                   (0x40U)

/* Chip-select signal timing parameter configuration. */
#define CSL_GPMC_CONFIG2_4                                      (0x124U)

/* Chip-select signal timing parameter configuration. */
#define CSL_GPMC_CONFIG2_2                                      (0xC4U)

/* BCH_RESULT5_5 */
#define CSL_GPMC_BCH_RESULT5_5                                  (0x354U)

/* WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle, and BusTurnAround parameters 
 * configuration */
#define CSL_GPMC_CONFIG6_0                                      (0x74U)

/* Chip-select signal timing parameter configuration. */
#define CSL_GPMC_CONFIG2_5                                      (0x154U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_DATA_5                                    (0x174U)

/* This register is not a true register, just an address location. */
#define CSL_GPMC_NAND_COMMAND_1                                 (0xACU)

/* BCH_RESULT2_0 */
#define CSL_GPMC_BCH_RESULT2_0                                  (0x248U)

/* BCH_RESULT6_2 */
#define CSL_GPMC_BCH_RESULT6_2                                  (0x328U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* BCH_RESULT4_6 */

#define CSL_GPMC_BCH_RESULT4_6_BCH_RESULT4_6_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT4_6_BCH_RESULT4_6_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT4_6_BCH_RESULT4_6_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT4_6_BCH_RESULT4_6_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT4_6_RESETVAL                         (0x00000000U)

/* BCH_RESULT1_0 */

#define CSL_GPMC_BCH_RESULT1_0_BCH_RESULT1_0_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT1_0_BCH_RESULT1_0_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT1_0_BCH_RESULT1_0_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT1_0_BCH_RESULT1_0_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT1_0_RESETVAL                         (0x00000000U)

/* NAND_ADDR_2 */

#define CSL_GPMC_NAND_ADDR_2_GPMC_NAND_ADDR_2_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_ADDR_2_GPMC_NAND_ADDR_2_SHIFT             (0U)
#define CSL_GPMC_NAND_ADDR_2_GPMC_NAND_ADDR_2_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_ADDR_2_GPMC_NAND_ADDR_2_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_ADDR_2_RESETVAL                           (0x00000000U)

/* CONFIG7_4 */

#define CSL_GPMC_CONFIG7_4_BASEADDR_MASK                        (0x0000003FU)
#define CSL_GPMC_CONFIG7_4_BASEADDR_SHIFT                       (0U)
#define CSL_GPMC_CONFIG7_4_BASEADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_4_BASEADDR_MAX                         (0x0000003fU)

#define CSL_GPMC_CONFIG7_4_CSVALID_MASK                         (0x00000040U)
#define CSL_GPMC_CONFIG7_4_CSVALID_SHIFT                        (6U)
#define CSL_GPMC_CONFIG7_4_CSVALID_RESETVAL                     (0x00000000U)
#define CSL_GPMC_CONFIG7_4_CSVALID_EN_0X0                       (0x00000000U)
#define CSL_GPMC_CONFIG7_4_CSVALID_EN_0X1                       (0x00000001U)

#define CSL_GPMC_CONFIG7_4_MASKADDR_MASK                        (0x00000F00U)
#define CSL_GPMC_CONFIG7_4_MASKADDR_SHIFT                       (8U)
#define CSL_GPMC_CONFIG7_4_MASKADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_4_MASKADDR_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG7_4_RESETVAL                             (0x00000000U)

/* CONFIG7_5 */

#define CSL_GPMC_CONFIG7_5_BASEADDR_MASK                        (0x0000003FU)
#define CSL_GPMC_CONFIG7_5_BASEADDR_SHIFT                       (0U)
#define CSL_GPMC_CONFIG7_5_BASEADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_5_BASEADDR_MAX                         (0x0000003fU)

#define CSL_GPMC_CONFIG7_5_CSVALID_MASK                         (0x00000040U)
#define CSL_GPMC_CONFIG7_5_CSVALID_SHIFT                        (6U)
#define CSL_GPMC_CONFIG7_5_CSVALID_RESETVAL                     (0x00000000U)
#define CSL_GPMC_CONFIG7_5_CSVALID_EN_0X0                       (0x00000000U)
#define CSL_GPMC_CONFIG7_5_CSVALID_EN_0X1                       (0x00000001U)

#define CSL_GPMC_CONFIG7_5_MASKADDR_MASK                        (0x00000F00U)
#define CSL_GPMC_CONFIG7_5_MASKADDR_SHIFT                       (8U)
#define CSL_GPMC_CONFIG7_5_MASKADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_5_MASKADDR_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG7_5_RESETVAL                             (0x00000000U)

/* BCH_RESULT4_4 */

#define CSL_GPMC_BCH_RESULT4_4_BCH_RESULT4_4_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT4_4_BCH_RESULT4_4_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT4_4_BCH_RESULT4_4_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT4_4_BCH_RESULT4_4_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT4_4_RESETVAL                         (0x00000000U)

/* BCH_RESULT6_0 */

#define CSL_GPMC_BCH_RESULT6_0_BCH_RESULT6_0_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT6_0_BCH_RESULT6_0_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT6_0_BCH_RESULT6_0_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT6_0_BCH_RESULT6_0_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT6_0_RESETVAL                         (0x00000000U)

/* CONFIG3_3 */

#define CSL_GPMC_CONFIG3_3_ADVONTIME_MASK                       (0x0000000FU)
#define CSL_GPMC_CONFIG3_3_ADVONTIME_SHIFT                      (0U)
#define CSL_GPMC_CONFIG3_3_ADVONTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVONTIME_MAX                        (0x0000000fU)

#define CSL_GPMC_CONFIG3_3_ADVAADMUXONTIME_MASK                 (0x00000070U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXONTIME_SHIFT                (4U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXONTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXONTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXONTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXONTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG3_3_ADVEXTRADELAY_MASK                   (0x00000080U)
#define CSL_GPMC_CONFIG3_3_ADVEXTRADELAY_SHIFT                  (7U)
#define CSL_GPMC_CONFIG3_3_ADVEXTRADELAY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVEXTRADELAY_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG3_3_ADVEXTRADELAY_EN_0X0                 (0x00000000U)

#define CSL_GPMC_CONFIG3_3_ADVRDOFFTIME_MASK                    (0x00001F00U)
#define CSL_GPMC_CONFIG3_3_ADVRDOFFTIME_SHIFT                   (8U)
#define CSL_GPMC_CONFIG3_3_ADVRDOFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVRDOFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_3_ADVWROFFTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG3_3_ADVWROFFTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG3_3_ADVWROFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVWROFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_3_ADVAADMUXRDOFFTIME_MASK              (0x07000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXRDOFFTIME_SHIFT             (24U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXRDOFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXRDOFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXRDOFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXRDOFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_3_ADVAADMUXWROFFTIME_MASK              (0x70000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXWROFFTIME_SHIFT             (28U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXWROFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXWROFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXWROFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_3_ADVAADMUXWROFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_3_RESETVAL                             (0x00000000U)

/* IRQEN */

#define CSL_GPMC_IRQEN_FIFOEVTEN_MASK                           (0x00000001U)
#define CSL_GPMC_IRQEN_FIFOEVTEN_SHIFT                          (0U)
#define CSL_GPMC_IRQEN_FIFOEVTEN_RESETVAL                       (0x00000000U)
#define CSL_GPMC_IRQEN_FIFOEVTEN_EN_0X1                         (0x00000001U)
#define CSL_GPMC_IRQEN_FIFOEVTEN_EN_0X0                         (0x00000000U)

#define CSL_GPMC_IRQEN_TERMINALCOUNTEVTEN_MASK                  (0x00000002U)
#define CSL_GPMC_IRQEN_TERMINALCOUNTEVTEN_SHIFT                 (1U)
#define CSL_GPMC_IRQEN_TERMINALCOUNTEVTEN_RESETVAL              (0x00000000U)
#define CSL_GPMC_IRQEN_TERMINALCOUNTEVTEN_EN_0X0                (0x00000000U)
#define CSL_GPMC_IRQEN_TERMINALCOUNTEVTEN_EN_0X1                (0x00000001U)

#define CSL_GPMC_IRQEN_WAIT0EDGEDETECTIONEN_MASK                (0x00000100U)
#define CSL_GPMC_IRQEN_WAIT0EDGEDETECTIONEN_SHIFT               (8U)
#define CSL_GPMC_IRQEN_WAIT0EDGEDETECTIONEN_RESETVAL            (0x00000000U)
#define CSL_GPMC_IRQEN_WAIT0EDGEDETECTIONEN_EN_0X1              (0x00000001U)
#define CSL_GPMC_IRQEN_WAIT0EDGEDETECTIONEN_EN_0X0              (0x00000000U)

#define CSL_GPMC_IRQEN_WAIT1EDGEDETECTIONEN_MASK                (0x00000200U)
#define CSL_GPMC_IRQEN_WAIT1EDGEDETECTIONEN_SHIFT               (9U)
#define CSL_GPMC_IRQEN_WAIT1EDGEDETECTIONEN_RESETVAL            (0x00000000U)
#define CSL_GPMC_IRQEN_WAIT1EDGEDETECTIONEN_EN_0X1              (0x00000001U)
#define CSL_GPMC_IRQEN_WAIT1EDGEDETECTIONEN_EN_0X0              (0x00000000U)

#define CSL_GPMC_IRQEN_RESETVAL                                 (0x00000000U)

/* BCH_RESULT0_1 */

#define CSL_GPMC_BCH_RESULT0_1_BCH_RESULT0_1_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT0_1_BCH_RESULT0_1_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT0_1_BCH_RESULT0_1_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT0_1_BCH_RESULT0_1_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT0_1_RESETVAL                         (0x00000000U)

/* ECC7_RESULT */

#define CSL_GPMC_ECC7_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC7_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC7_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC7_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC7_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC7_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC7_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC7_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC7_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC7_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC7_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC7_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC7_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC7_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC7_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC7_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC7_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC7_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC7_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC7_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC7_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC7_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC7_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC7_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC7_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC7_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC7_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC7_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC7_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC7_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC7_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC7_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC7_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC7_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC7_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC7_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC7_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC7_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC7_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC7_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC7_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC7_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC7_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC7_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC7_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC7_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC7_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC7_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC7_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC7_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC7_RESULT_RESETVAL                           (0x00000000U)

/* ECC_SIZE_CONFIG */

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_MASK            (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_SHIFT           (0U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_MASK            (0x00000002U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_SHIFT           (1U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_MASK            (0x00000004U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_SHIFT           (2U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_MASK            (0x00000008U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_SHIFT           (3U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_MASK            (0x00000010U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_SHIFT           (4U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_MASK            (0x00000020U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_SHIFT           (5U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_MASK            (0x00000040U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_SHIFT           (6U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_MASK            (0x00000080U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_SHIFT           (7U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_MASK            (0x00000100U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_SHIFT           (8U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_RESETVAL        (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_EN_0X1          (0x00000001U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_EN_0X0          (0x00000000U)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE0_MASK                  (0x000FF000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE0_SHIFT                 (12U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE0_RESETVAL              (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE0_MAX                   (0x000000ffU)

#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE1_MASK                  (0x3FC00000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE1_SHIFT                 (22U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE1_RESETVAL              (0x00000000U)
#define CSL_GPMC_ECC_SIZE_CONFIG_ECCSIZE1_MAX                   (0x000000ffU)

#define CSL_GPMC_ECC_SIZE_CONFIG_RESETVAL                       (0x00000000U)

/* BCH_RESULT4_0 */

#define CSL_GPMC_BCH_RESULT4_0_BCH_RESULT4_0_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT4_0_BCH_RESULT4_0_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT4_0_BCH_RESULT4_0_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT4_0_BCH_RESULT4_0_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT4_0_RESETVAL                         (0x00000000U)

/* ERR_TYPE */

#define CSL_GPMC_ERR_TYPE_ERRORVALID_MASK                       (0x00000001U)
#define CSL_GPMC_ERR_TYPE_ERRORVALID_SHIFT                      (0U)
#define CSL_GPMC_ERR_TYPE_ERRORVALID_RESETVAL                   (0x00000000U)
#define CSL_GPMC_ERR_TYPE_ERRORVALID_EN_0X1                     (0x00000001U)
#define CSL_GPMC_ERR_TYPE_ERRORVALID_EN_0X0                     (0x00000000U)

#define CSL_GPMC_ERR_TYPE_ERRORTIMEOUT_MASK                     (0x00000004U)
#define CSL_GPMC_ERR_TYPE_ERRORTIMEOUT_SHIFT                    (2U)
#define CSL_GPMC_ERR_TYPE_ERRORTIMEOUT_RESETVAL                 (0x00000000U)
#define CSL_GPMC_ERR_TYPE_ERRORTIMEOUT_EN_0X1                   (0x00000001U)
#define CSL_GPMC_ERR_TYPE_ERRORTIMEOUT_EN_0X0                   (0x00000000U)

#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_MASK                 (0x00000008U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_SHIFT                (3U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_RESETVAL             (0x00000000U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_EN_0X1               (0x00000001U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_EN_0X0               (0x00000000U)

#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPADD_MASK                  (0x00000010U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPADD_SHIFT                 (4U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPADD_RESETVAL              (0x00000000U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPADD_EN_0X0                (0x00000000U)
#define CSL_GPMC_ERR_TYPE_ERRORNOTSUPPADD_EN_0X1                (0x00000001U)

#define CSL_GPMC_ERR_TYPE_ILLEGALMCMD_MASK                      (0x00000700U)
#define CSL_GPMC_ERR_TYPE_ILLEGALMCMD_SHIFT                     (8U)
#define CSL_GPMC_ERR_TYPE_ILLEGALMCMD_RESETVAL                  (0x00000000U)
#define CSL_GPMC_ERR_TYPE_ILLEGALMCMD_MAX                       (0x00000007U)

#define CSL_GPMC_ERR_TYPE_RESETVAL                              (0x00000000U)

/* BCH_RESULT2_2 */

#define CSL_GPMC_BCH_RESULT2_2_BCH_RESULT2_2_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT2_2_BCH_RESULT2_2_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT2_2_BCH_RESULT2_2_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT2_2_BCH_RESULT2_2_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT2_2_RESETVAL                         (0x00000000U)

/* CONFIG4_5 */

#define CSL_GPMC_CONFIG4_5_OEONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG4_5_OEONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG4_5_OEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_5_OEAADMUXONTIME_MASK                  (0x00000070U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXONTIME_SHIFT                 (4U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXONTIME_RESETVAL              (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXONTIME_EN_0X0                (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXONTIME_EN_0X1                (0x00000001U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXONTIME_EN_0X7                (0x00000007U)

#define CSL_GPMC_CONFIG4_5_OEEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG4_5_OEEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG4_5_OEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG4_5_OEOFFTIME_MASK                       (0x00001F00U)
#define CSL_GPMC_CONFIG4_5_OEOFFTIME_SHIFT                      (8U)
#define CSL_GPMC_CONFIG4_5_OEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_5_OEAADMUXOFFTIME_MASK                 (0x0000E000U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXOFFTIME_SHIFT                (13U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXOFFTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXOFFTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXOFFTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG4_5_OEAADMUXOFFTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG4_5_WEONTIME_MASK                        (0x000F0000U)
#define CSL_GPMC_CONFIG4_5_WEONTIME_SHIFT                       (16U)
#define CSL_GPMC_CONFIG4_5_WEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_5_WEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_5_WEEXTRADELAY_MASK                    (0x00800000U)
#define CSL_GPMC_CONFIG4_5_WEEXTRADELAY_SHIFT                   (23U)
#define CSL_GPMC_CONFIG4_5_WEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_5_WEEXTRADELAY_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG4_5_WEEXTRADELAY_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG4_5_WEOFFTIME_MASK                       (0x1F000000U)
#define CSL_GPMC_CONFIG4_5_WEOFFTIME_SHIFT                      (24U)
#define CSL_GPMC_CONFIG4_5_WEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_5_WEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_5_RESETVAL                             (0x00000000U)

/* CONFIG4_3 */

#define CSL_GPMC_CONFIG4_3_OEONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG4_3_OEONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG4_3_OEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_3_OEAADMUXONTIME_MASK                  (0x00000070U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXONTIME_SHIFT                 (4U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXONTIME_RESETVAL              (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXONTIME_EN_0X0                (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXONTIME_EN_0X1                (0x00000001U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXONTIME_EN_0X7                (0x00000007U)

#define CSL_GPMC_CONFIG4_3_OEEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG4_3_OEEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG4_3_OEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG4_3_OEOFFTIME_MASK                       (0x00001F00U)
#define CSL_GPMC_CONFIG4_3_OEOFFTIME_SHIFT                      (8U)
#define CSL_GPMC_CONFIG4_3_OEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_3_OEAADMUXOFFTIME_MASK                 (0x0000E000U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXOFFTIME_SHIFT                (13U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXOFFTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXOFFTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXOFFTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG4_3_OEAADMUXOFFTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG4_3_WEONTIME_MASK                        (0x000F0000U)
#define CSL_GPMC_CONFIG4_3_WEONTIME_SHIFT                       (16U)
#define CSL_GPMC_CONFIG4_3_WEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_3_WEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_3_WEEXTRADELAY_MASK                    (0x00800000U)
#define CSL_GPMC_CONFIG4_3_WEEXTRADELAY_SHIFT                   (23U)
#define CSL_GPMC_CONFIG4_3_WEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_3_WEEXTRADELAY_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG4_3_WEEXTRADELAY_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG4_3_WEOFFTIME_MASK                       (0x1F000000U)
#define CSL_GPMC_CONFIG4_3_WEOFFTIME_SHIFT                      (24U)
#define CSL_GPMC_CONFIG4_3_WEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_3_WEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_3_RESETVAL                             (0x00000000U)

/* BCH_RESULT5_3 */

#define CSL_GPMC_BCH_RESULT5_3_BCH_RESULT5_3_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT5_3_BCH_RESULT5_3_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT5_3_BCH_RESULT5_3_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT5_3_BCH_RESULT5_3_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT5_3_RESETVAL                         (0x00000000U)

/* BCH_SWDATA */

#define CSL_GPMC_BCH_SWDATA_BCH_DATA_MASK                       (0x0000FFFFU)
#define CSL_GPMC_BCH_SWDATA_BCH_DATA_SHIFT                      (0U)
#define CSL_GPMC_BCH_SWDATA_BCH_DATA_RESETVAL                   (0x00000000U)
#define CSL_GPMC_BCH_SWDATA_BCH_DATA_MAX                        (0x0000ffffU)

#define CSL_GPMC_BCH_SWDATA_RESETVAL                            (0x00000000U)

/* CONFIG1_6 */

#define CSL_GPMC_CONFIG1_6_GPMCFCLKDIVIDER_MASK                 (0x00000003U)
#define CSL_GPMC_CONFIG1_6_GPMCFCLKDIVIDER_SHIFT                (0U)
#define CSL_GPMC_CONFIG1_6_GPMCFCLKDIVIDER_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG1_6_GPMCFCLKDIVIDER_EN_0X3               (0x00000003U)
#define CSL_GPMC_CONFIG1_6_GPMCFCLKDIVIDER_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG1_6_GPMCFCLKDIVIDER_EN_0X2               (0x00000002U)
#define CSL_GPMC_CONFIG1_6_GPMCFCLKDIVIDER_EN_0X0               (0x00000000U)

#define CSL_GPMC_CONFIG1_6_TIMEPARAGRANULARITY_MASK             (0x00000010U)
#define CSL_GPMC_CONFIG1_6_TIMEPARAGRANULARITY_SHIFT            (4U)
#define CSL_GPMC_CONFIG1_6_TIMEPARAGRANULARITY_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_6_TIMEPARAGRANULARITY_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG1_6_TIMEPARAGRANULARITY_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG1_6_MUXADDDATA_MASK                      (0x00000300U)
#define CSL_GPMC_CONFIG1_6_MUXADDDATA_SHIFT                     (8U)
#define CSL_GPMC_CONFIG1_6_MUXADDDATA_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_6_MUXADDDATA_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_6_MUXADDDATA_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_6_MUXADDDATA_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_6_MUXADDDATA_EN_0X0                    (0x00000000U)

#define CSL_GPMC_CONFIG1_6_DEVICETYPE_MASK                      (0x00000C00U)
#define CSL_GPMC_CONFIG1_6_DEVICETYPE_SHIFT                     (10U)
#define CSL_GPMC_CONFIG1_6_DEVICETYPE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_6_DEVICETYPE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_6_DEVICETYPE_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_6_DEVICETYPE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_6_DEVICETYPE_EN_0X2                    (0x00000002U)

#define CSL_GPMC_CONFIG1_6_DEVICESIZE_MASK                      (0x00003000U)
#define CSL_GPMC_CONFIG1_6_DEVICESIZE_SHIFT                     (12U)
#define CSL_GPMC_CONFIG1_6_DEVICESIZE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_6_DEVICESIZE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_6_DEVICESIZE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_6_DEVICESIZE_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_6_DEVICESIZE_EN_0X3                    (0x00000003U)

#define CSL_GPMC_CONFIG1_6_WAITPINSELECT_MASK                   (0x00030000U)
#define CSL_GPMC_CONFIG1_6_WAITPINSELECT_SHIFT                  (16U)
#define CSL_GPMC_CONFIG1_6_WAITPINSELECT_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WAITPINSELECT_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WAITPINSELECT_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG1_6_WAITPINSELECT_EN_0X2                 (0x00000002U)
#define CSL_GPMC_CONFIG1_6_WAITPINSELECT_EN_0X3                 (0x00000003U)

#define CSL_GPMC_CONFIG1_6_WAITMONITORINGTIME_MASK              (0x000C0000U)
#define CSL_GPMC_CONFIG1_6_WAITMONITORINGTIME_SHIFT             (18U)
#define CSL_GPMC_CONFIG1_6_WAITMONITORINGTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WAITMONITORINGTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG1_6_WAITMONITORINGTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WAITMONITORINGTIME_EN_0X3            (0x00000003U)
#define CSL_GPMC_CONFIG1_6_WAITMONITORINGTIME_EN_0X2            (0x00000002U)

#define CSL_GPMC_CONFIG1_6_WAITWRITEMONITORING_MASK             (0x00200000U)
#define CSL_GPMC_CONFIG1_6_WAITWRITEMONITORING_SHIFT            (21U)
#define CSL_GPMC_CONFIG1_6_WAITWRITEMONITORING_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WAITWRITEMONITORING_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG1_6_WAITWRITEMONITORING_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG1_6_WAITREADMONITORING_MASK              (0x00400000U)
#define CSL_GPMC_CONFIG1_6_WAITREADMONITORING_SHIFT             (22U)
#define CSL_GPMC_CONFIG1_6_WAITREADMONITORING_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WAITREADMONITORING_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WAITREADMONITORING_EN_0X1            (0x00000001U)

#define CSL_GPMC_CONFIG1_6_ATTACHEDDEVICEPAGELENGTH_MASK        (0x01800000U)
#define CSL_GPMC_CONFIG1_6_ATTACHEDDEVICEPAGELENGTH_SHIFT       (23U)
#define CSL_GPMC_CONFIG1_6_ATTACHEDDEVICEPAGELENGTH_RESETVAL    (0x00000000U)
#define CSL_GPMC_CONFIG1_6_ATTACHEDDEVICEPAGELENGTH_EN_0X1      (0x00000001U)
#define CSL_GPMC_CONFIG1_6_ATTACHEDDEVICEPAGELENGTH_EN_0X2      (0x00000002U)
#define CSL_GPMC_CONFIG1_6_ATTACHEDDEVICEPAGELENGTH_EN_0X3      (0x00000003U)
#define CSL_GPMC_CONFIG1_6_ATTACHEDDEVICEPAGELENGTH_EN_0X0      (0x00000000U)

#define CSL_GPMC_CONFIG1_6_CLKACTIVATIONTIME_MASK               (0x06000000U)
#define CSL_GPMC_CONFIG1_6_CLKACTIVATIONTIME_SHIFT              (25U)
#define CSL_GPMC_CONFIG1_6_CLKACTIVATIONTIME_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG1_6_CLKACTIVATIONTIME_EN_0X0             (0x00000000U)
#define CSL_GPMC_CONFIG1_6_CLKACTIVATIONTIME_EN_0X2             (0x00000002U)
#define CSL_GPMC_CONFIG1_6_CLKACTIVATIONTIME_EN_0X3             (0x00000003U)
#define CSL_GPMC_CONFIG1_6_CLKACTIVATIONTIME_EN_0X1             (0x00000001U)

#define CSL_GPMC_CONFIG1_6_WRITETYPE_MASK                       (0x08000000U)
#define CSL_GPMC_CONFIG1_6_WRITETYPE_SHIFT                      (27U)
#define CSL_GPMC_CONFIG1_6_WRITETYPE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WRITETYPE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WRITETYPE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_6_WRITEMULTIPLE_MASK                   (0x10000000U)
#define CSL_GPMC_CONFIG1_6_WRITEMULTIPLE_SHIFT                  (28U)
#define CSL_GPMC_CONFIG1_6_WRITEMULTIPLE_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WRITEMULTIPLE_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WRITEMULTIPLE_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG1_6_READTYPE_MASK                        (0x20000000U)
#define CSL_GPMC_CONFIG1_6_READTYPE_SHIFT                       (29U)
#define CSL_GPMC_CONFIG1_6_READTYPE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG1_6_READTYPE_EN_0X1                      (0x00000001U)
#define CSL_GPMC_CONFIG1_6_READTYPE_EN_0X0                      (0x00000000U)

#define CSL_GPMC_CONFIG1_6_READMULTIPLE_MASK                    (0x40000000U)
#define CSL_GPMC_CONFIG1_6_READMULTIPLE_SHIFT                   (30U)
#define CSL_GPMC_CONFIG1_6_READMULTIPLE_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG1_6_READMULTIPLE_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG1_6_READMULTIPLE_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG1_6_WRAPBURST_MASK                       (0x80000000U)
#define CSL_GPMC_CONFIG1_6_WRAPBURST_SHIFT                      (31U)
#define CSL_GPMC_CONFIG1_6_WRAPBURST_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WRAPBURST_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_6_WRAPBURST_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_6_RESETVAL                             (0x00000000U)

/* NAND_DATA_2 */

#define CSL_GPMC_NAND_DATA_2_GPMC_NAND_DATA_2_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_DATA_2_GPMC_NAND_DATA_2_SHIFT             (0U)
#define CSL_GPMC_NAND_DATA_2_GPMC_NAND_DATA_2_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_DATA_2_GPMC_NAND_DATA_2_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_DATA_2_RESETVAL                           (0x00000000U)

/* BCH_RESULT0_3 */

#define CSL_GPMC_BCH_RESULT0_3_BCH_RESULT0_3_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT0_3_BCH_RESULT0_3_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT0_3_BCH_RESULT0_3_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT0_3_BCH_RESULT0_3_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT0_3_RESETVAL                         (0x00000000U)

/* CONFIG4_1 */

#define CSL_GPMC_CONFIG4_1_OEONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG4_1_OEONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG4_1_OEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_1_OEAADMUXONTIME_MASK                  (0x00000070U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXONTIME_SHIFT                 (4U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXONTIME_RESETVAL              (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXONTIME_EN_0X0                (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXONTIME_EN_0X1                (0x00000001U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXONTIME_EN_0X7                (0x00000007U)

#define CSL_GPMC_CONFIG4_1_OEEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG4_1_OEEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG4_1_OEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG4_1_OEOFFTIME_MASK                       (0x00001F00U)
#define CSL_GPMC_CONFIG4_1_OEOFFTIME_SHIFT                      (8U)
#define CSL_GPMC_CONFIG4_1_OEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_1_OEAADMUXOFFTIME_MASK                 (0x0000E000U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXOFFTIME_SHIFT                (13U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXOFFTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXOFFTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXOFFTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG4_1_OEAADMUXOFFTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG4_1_WEONTIME_MASK                        (0x000F0000U)
#define CSL_GPMC_CONFIG4_1_WEONTIME_SHIFT                       (16U)
#define CSL_GPMC_CONFIG4_1_WEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_1_WEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_1_WEEXTRADELAY_MASK                    (0x00800000U)
#define CSL_GPMC_CONFIG4_1_WEEXTRADELAY_SHIFT                   (23U)
#define CSL_GPMC_CONFIG4_1_WEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_1_WEEXTRADELAY_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG4_1_WEEXTRADELAY_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG4_1_WEOFFTIME_MASK                       (0x1F000000U)
#define CSL_GPMC_CONFIG4_1_WEOFFTIME_SHIFT                      (24U)
#define CSL_GPMC_CONFIG4_1_WEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_1_WEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_1_RESETVAL                             (0x00000000U)

/* BCH_RESULT0_0 */

#define CSL_GPMC_BCH_RESULT0_0_BCH_RESULT0_0_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT0_0_BCH_RESULT0_0_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT0_0_BCH_RESULT0_0_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT0_0_BCH_RESULT0_0_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT0_0_RESETVAL                         (0x00000000U)

/* BCH_RESULT5_6 */

#define CSL_GPMC_BCH_RESULT5_6_BCH_RESULT5_6_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT5_6_BCH_RESULT5_6_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT5_6_BCH_RESULT5_6_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT5_6_BCH_RESULT5_6_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT5_6_RESETVAL                         (0x00000000U)

/* IRQSTS */

#define CSL_GPMC_IRQSTS_FIFOEVTSTS_MASK                         (0x00000001U)
#define CSL_GPMC_IRQSTS_FIFOEVTSTS_SHIFT                        (0U)
#define CSL_GPMC_IRQSTS_FIFOEVTSTS_RESETVAL                     (0x00000000U)
#define CSL_GPMC_IRQSTS_FIFOEVTSTS_EN_0X0W                      (0x00000000U)
#define CSL_GPMC_IRQSTS_FIFOEVTSTS_EN_0X1R                      (0x00000001U)
#define CSL_GPMC_IRQSTS_FIFOEVTSTS_EN_0X0R                      (0x00000000U)
#define CSL_GPMC_IRQSTS_FIFOEVTSTS_EN_0X1W                      (0x00000001U)

#define CSL_GPMC_IRQSTS_TERMINALCOUNTSTS_MASK                   (0x00000002U)
#define CSL_GPMC_IRQSTS_TERMINALCOUNTSTS_SHIFT                  (1U)
#define CSL_GPMC_IRQSTS_TERMINALCOUNTSTS_RESETVAL               (0x00000000U)
#define CSL_GPMC_IRQSTS_TERMINALCOUNTSTS_EN_0X1W                (0x00000001U)
#define CSL_GPMC_IRQSTS_TERMINALCOUNTSTS_EN_0X0R                (0x00000000U)
#define CSL_GPMC_IRQSTS_TERMINALCOUNTSTS_EN_0X0W                (0x00000000U)
#define CSL_GPMC_IRQSTS_TERMINALCOUNTSTS_EN_0X1R                (0x00000001U)

#define CSL_GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS_MASK              (0x00000100U)
#define CSL_GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS_SHIFT             (8U)
#define CSL_GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS_RESETVAL          (0x00000000U)
#define CSL_GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS_EN_0X0R           (0x00000000U)
#define CSL_GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS_EN_0X0W           (0x00000000U)
#define CSL_GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS_EN_0X1W           (0x00000001U)
#define CSL_GPMC_IRQSTS_WAIT0EDGEDETECTIONSTS_EN_0X1R           (0x00000001U)

#define CSL_GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS_MASK              (0x00000200U)
#define CSL_GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS_SHIFT             (9U)
#define CSL_GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS_RESETVAL          (0x00000000U)
#define CSL_GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS_EN_0X1W           (0x00000001U)
#define CSL_GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS_EN_0X1R           (0x00000001U)
#define CSL_GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS_EN_0X0R           (0x00000000U)
#define CSL_GPMC_IRQSTS_WAIT1EDGEDETECTIONSTS_EN_0X0W           (0x00000000U)

#define CSL_GPMC_IRQSTS_RESETVAL                                (0x00000000U)

/* PREFETCH_CONFIG2 */

#define CSL_GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_MASK            (0x00003FFFU)
#define CSL_GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_SHIFT           (0U)
#define CSL_GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_RESETVAL        (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_MAX             (0x00003fffU)

#define CSL_GPMC_PREFETCH_CONFIG2_RESETVAL                      (0x00000000U)

/* CONFIG1_4 */

#define CSL_GPMC_CONFIG1_4_GPMCFCLKDIVIDER_MASK                 (0x00000003U)
#define CSL_GPMC_CONFIG1_4_GPMCFCLKDIVIDER_SHIFT                (0U)
#define CSL_GPMC_CONFIG1_4_GPMCFCLKDIVIDER_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG1_4_GPMCFCLKDIVIDER_EN_0X3               (0x00000003U)
#define CSL_GPMC_CONFIG1_4_GPMCFCLKDIVIDER_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG1_4_GPMCFCLKDIVIDER_EN_0X2               (0x00000002U)
#define CSL_GPMC_CONFIG1_4_GPMCFCLKDIVIDER_EN_0X0               (0x00000000U)

#define CSL_GPMC_CONFIG1_4_TIMEPARAGRANULARITY_MASK             (0x00000010U)
#define CSL_GPMC_CONFIG1_4_TIMEPARAGRANULARITY_SHIFT            (4U)
#define CSL_GPMC_CONFIG1_4_TIMEPARAGRANULARITY_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_4_TIMEPARAGRANULARITY_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG1_4_TIMEPARAGRANULARITY_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG1_4_MUXADDDATA_MASK                      (0x00000300U)
#define CSL_GPMC_CONFIG1_4_MUXADDDATA_SHIFT                     (8U)
#define CSL_GPMC_CONFIG1_4_MUXADDDATA_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_4_MUXADDDATA_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_4_MUXADDDATA_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_4_MUXADDDATA_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_4_MUXADDDATA_EN_0X0                    (0x00000000U)

#define CSL_GPMC_CONFIG1_4_DEVICETYPE_MASK                      (0x00000C00U)
#define CSL_GPMC_CONFIG1_4_DEVICETYPE_SHIFT                     (10U)
#define CSL_GPMC_CONFIG1_4_DEVICETYPE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_4_DEVICETYPE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_4_DEVICETYPE_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_4_DEVICETYPE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_4_DEVICETYPE_EN_0X2                    (0x00000002U)

#define CSL_GPMC_CONFIG1_4_DEVICESIZE_MASK                      (0x00003000U)
#define CSL_GPMC_CONFIG1_4_DEVICESIZE_SHIFT                     (12U)
#define CSL_GPMC_CONFIG1_4_DEVICESIZE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_4_DEVICESIZE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_4_DEVICESIZE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_4_DEVICESIZE_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_4_DEVICESIZE_EN_0X3                    (0x00000003U)

#define CSL_GPMC_CONFIG1_4_WAITPINSELECT_MASK                   (0x00030000U)
#define CSL_GPMC_CONFIG1_4_WAITPINSELECT_SHIFT                  (16U)
#define CSL_GPMC_CONFIG1_4_WAITPINSELECT_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WAITPINSELECT_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WAITPINSELECT_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG1_4_WAITPINSELECT_EN_0X2                 (0x00000002U)
#define CSL_GPMC_CONFIG1_4_WAITPINSELECT_EN_0X3                 (0x00000003U)

#define CSL_GPMC_CONFIG1_4_WAITMONITORINGTIME_MASK              (0x000C0000U)
#define CSL_GPMC_CONFIG1_4_WAITMONITORINGTIME_SHIFT             (18U)
#define CSL_GPMC_CONFIG1_4_WAITMONITORINGTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WAITMONITORINGTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG1_4_WAITMONITORINGTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WAITMONITORINGTIME_EN_0X3            (0x00000003U)
#define CSL_GPMC_CONFIG1_4_WAITMONITORINGTIME_EN_0X2            (0x00000002U)

#define CSL_GPMC_CONFIG1_4_WAITWRITEMONITORING_MASK             (0x00200000U)
#define CSL_GPMC_CONFIG1_4_WAITWRITEMONITORING_SHIFT            (21U)
#define CSL_GPMC_CONFIG1_4_WAITWRITEMONITORING_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WAITWRITEMONITORING_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG1_4_WAITWRITEMONITORING_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG1_4_WAITREADMONITORING_MASK              (0x00400000U)
#define CSL_GPMC_CONFIG1_4_WAITREADMONITORING_SHIFT             (22U)
#define CSL_GPMC_CONFIG1_4_WAITREADMONITORING_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WAITREADMONITORING_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WAITREADMONITORING_EN_0X1            (0x00000001U)

#define CSL_GPMC_CONFIG1_4_ATTACHEDDEVICEPAGELENGTH_MASK        (0x01800000U)
#define CSL_GPMC_CONFIG1_4_ATTACHEDDEVICEPAGELENGTH_SHIFT       (23U)
#define CSL_GPMC_CONFIG1_4_ATTACHEDDEVICEPAGELENGTH_RESETVAL    (0x00000000U)
#define CSL_GPMC_CONFIG1_4_ATTACHEDDEVICEPAGELENGTH_EN_0X1      (0x00000001U)
#define CSL_GPMC_CONFIG1_4_ATTACHEDDEVICEPAGELENGTH_EN_0X2      (0x00000002U)
#define CSL_GPMC_CONFIG1_4_ATTACHEDDEVICEPAGELENGTH_EN_0X3      (0x00000003U)
#define CSL_GPMC_CONFIG1_4_ATTACHEDDEVICEPAGELENGTH_EN_0X0      (0x00000000U)

#define CSL_GPMC_CONFIG1_4_CLKACTIVATIONTIME_MASK               (0x06000000U)
#define CSL_GPMC_CONFIG1_4_CLKACTIVATIONTIME_SHIFT              (25U)
#define CSL_GPMC_CONFIG1_4_CLKACTIVATIONTIME_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG1_4_CLKACTIVATIONTIME_EN_0X0             (0x00000000U)
#define CSL_GPMC_CONFIG1_4_CLKACTIVATIONTIME_EN_0X2             (0x00000002U)
#define CSL_GPMC_CONFIG1_4_CLKACTIVATIONTIME_EN_0X3             (0x00000003U)
#define CSL_GPMC_CONFIG1_4_CLKACTIVATIONTIME_EN_0X1             (0x00000001U)

#define CSL_GPMC_CONFIG1_4_WRITETYPE_MASK                       (0x08000000U)
#define CSL_GPMC_CONFIG1_4_WRITETYPE_SHIFT                      (27U)
#define CSL_GPMC_CONFIG1_4_WRITETYPE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WRITETYPE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WRITETYPE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_4_WRITEMULTIPLE_MASK                   (0x10000000U)
#define CSL_GPMC_CONFIG1_4_WRITEMULTIPLE_SHIFT                  (28U)
#define CSL_GPMC_CONFIG1_4_WRITEMULTIPLE_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WRITEMULTIPLE_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WRITEMULTIPLE_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG1_4_READTYPE_MASK                        (0x20000000U)
#define CSL_GPMC_CONFIG1_4_READTYPE_SHIFT                       (29U)
#define CSL_GPMC_CONFIG1_4_READTYPE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG1_4_READTYPE_EN_0X1                      (0x00000001U)
#define CSL_GPMC_CONFIG1_4_READTYPE_EN_0X0                      (0x00000000U)

#define CSL_GPMC_CONFIG1_4_READMULTIPLE_MASK                    (0x40000000U)
#define CSL_GPMC_CONFIG1_4_READMULTIPLE_SHIFT                   (30U)
#define CSL_GPMC_CONFIG1_4_READMULTIPLE_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG1_4_READMULTIPLE_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG1_4_READMULTIPLE_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG1_4_WRAPBURST_MASK                       (0x80000000U)
#define CSL_GPMC_CONFIG1_4_WRAPBURST_SHIFT                      (31U)
#define CSL_GPMC_CONFIG1_4_WRAPBURST_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WRAPBURST_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_4_WRAPBURST_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_4_RESETVAL                             (0x00000000U)

/* ECC8_RESULT */

#define CSL_GPMC_ECC8_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC8_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC8_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC8_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC8_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC8_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC8_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC8_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC8_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC8_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC8_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC8_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC8_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC8_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC8_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC8_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC8_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC8_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC8_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC8_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC8_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC8_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC8_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC8_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC8_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC8_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC8_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC8_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC8_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC8_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC8_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC8_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC8_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC8_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC8_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC8_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC8_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC8_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC8_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC8_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC8_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC8_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC8_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC8_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC8_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC8_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC8_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC8_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC8_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC8_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC8_RESULT_RESETVAL                           (0x00000000U)

/* BCH_RESULT0_5 */

#define CSL_GPMC_BCH_RESULT0_5_BCH_RESULT0_5_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT0_5_BCH_RESULT0_5_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT0_5_BCH_RESULT0_5_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT0_5_BCH_RESULT0_5_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT0_5_RESETVAL                         (0x00000000U)

/* CONFIG1_3 */

#define CSL_GPMC_CONFIG1_3_GPMCFCLKDIVIDER_MASK                 (0x00000003U)
#define CSL_GPMC_CONFIG1_3_GPMCFCLKDIVIDER_SHIFT                (0U)
#define CSL_GPMC_CONFIG1_3_GPMCFCLKDIVIDER_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG1_3_GPMCFCLKDIVIDER_EN_0X3               (0x00000003U)
#define CSL_GPMC_CONFIG1_3_GPMCFCLKDIVIDER_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG1_3_GPMCFCLKDIVIDER_EN_0X2               (0x00000002U)
#define CSL_GPMC_CONFIG1_3_GPMCFCLKDIVIDER_EN_0X0               (0x00000000U)

#define CSL_GPMC_CONFIG1_3_TIMEPARAGRANULARITY_MASK             (0x00000010U)
#define CSL_GPMC_CONFIG1_3_TIMEPARAGRANULARITY_SHIFT            (4U)
#define CSL_GPMC_CONFIG1_3_TIMEPARAGRANULARITY_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_3_TIMEPARAGRANULARITY_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG1_3_TIMEPARAGRANULARITY_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG1_3_MUXADDDATA_MASK                      (0x00000300U)
#define CSL_GPMC_CONFIG1_3_MUXADDDATA_SHIFT                     (8U)
#define CSL_GPMC_CONFIG1_3_MUXADDDATA_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_3_MUXADDDATA_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_3_MUXADDDATA_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_3_MUXADDDATA_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_3_MUXADDDATA_EN_0X0                    (0x00000000U)

#define CSL_GPMC_CONFIG1_3_DEVICETYPE_MASK                      (0x00000C00U)
#define CSL_GPMC_CONFIG1_3_DEVICETYPE_SHIFT                     (10U)
#define CSL_GPMC_CONFIG1_3_DEVICETYPE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_3_DEVICETYPE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_3_DEVICETYPE_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_3_DEVICETYPE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_3_DEVICETYPE_EN_0X2                    (0x00000002U)

#define CSL_GPMC_CONFIG1_3_DEVICESIZE_MASK                      (0x00003000U)
#define CSL_GPMC_CONFIG1_3_DEVICESIZE_SHIFT                     (12U)
#define CSL_GPMC_CONFIG1_3_DEVICESIZE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_3_DEVICESIZE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_3_DEVICESIZE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_3_DEVICESIZE_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_3_DEVICESIZE_EN_0X3                    (0x00000003U)

#define CSL_GPMC_CONFIG1_3_WAITPINSELECT_MASK                   (0x00030000U)
#define CSL_GPMC_CONFIG1_3_WAITPINSELECT_SHIFT                  (16U)
#define CSL_GPMC_CONFIG1_3_WAITPINSELECT_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WAITPINSELECT_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WAITPINSELECT_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG1_3_WAITPINSELECT_EN_0X2                 (0x00000002U)
#define CSL_GPMC_CONFIG1_3_WAITPINSELECT_EN_0X3                 (0x00000003U)

#define CSL_GPMC_CONFIG1_3_WAITMONITORINGTIME_MASK              (0x000C0000U)
#define CSL_GPMC_CONFIG1_3_WAITMONITORINGTIME_SHIFT             (18U)
#define CSL_GPMC_CONFIG1_3_WAITMONITORINGTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WAITMONITORINGTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG1_3_WAITMONITORINGTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WAITMONITORINGTIME_EN_0X3            (0x00000003U)
#define CSL_GPMC_CONFIG1_3_WAITMONITORINGTIME_EN_0X2            (0x00000002U)

#define CSL_GPMC_CONFIG1_3_WAITWRITEMONITORING_MASK             (0x00200000U)
#define CSL_GPMC_CONFIG1_3_WAITWRITEMONITORING_SHIFT            (21U)
#define CSL_GPMC_CONFIG1_3_WAITWRITEMONITORING_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WAITWRITEMONITORING_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG1_3_WAITWRITEMONITORING_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG1_3_WAITREADMONITORING_MASK              (0x00400000U)
#define CSL_GPMC_CONFIG1_3_WAITREADMONITORING_SHIFT             (22U)
#define CSL_GPMC_CONFIG1_3_WAITREADMONITORING_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WAITREADMONITORING_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WAITREADMONITORING_EN_0X1            (0x00000001U)

#define CSL_GPMC_CONFIG1_3_ATTACHEDDEVICEPAGELENGTH_MASK        (0x01800000U)
#define CSL_GPMC_CONFIG1_3_ATTACHEDDEVICEPAGELENGTH_SHIFT       (23U)
#define CSL_GPMC_CONFIG1_3_ATTACHEDDEVICEPAGELENGTH_RESETVAL    (0x00000000U)
#define CSL_GPMC_CONFIG1_3_ATTACHEDDEVICEPAGELENGTH_EN_0X1      (0x00000001U)
#define CSL_GPMC_CONFIG1_3_ATTACHEDDEVICEPAGELENGTH_EN_0X2      (0x00000002U)
#define CSL_GPMC_CONFIG1_3_ATTACHEDDEVICEPAGELENGTH_EN_0X3      (0x00000003U)
#define CSL_GPMC_CONFIG1_3_ATTACHEDDEVICEPAGELENGTH_EN_0X0      (0x00000000U)

#define CSL_GPMC_CONFIG1_3_CLKACTIVATIONTIME_MASK               (0x06000000U)
#define CSL_GPMC_CONFIG1_3_CLKACTIVATIONTIME_SHIFT              (25U)
#define CSL_GPMC_CONFIG1_3_CLKACTIVATIONTIME_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG1_3_CLKACTIVATIONTIME_EN_0X0             (0x00000000U)
#define CSL_GPMC_CONFIG1_3_CLKACTIVATIONTIME_EN_0X2             (0x00000002U)
#define CSL_GPMC_CONFIG1_3_CLKACTIVATIONTIME_EN_0X3             (0x00000003U)
#define CSL_GPMC_CONFIG1_3_CLKACTIVATIONTIME_EN_0X1             (0x00000001U)

#define CSL_GPMC_CONFIG1_3_WRITETYPE_MASK                       (0x08000000U)
#define CSL_GPMC_CONFIG1_3_WRITETYPE_SHIFT                      (27U)
#define CSL_GPMC_CONFIG1_3_WRITETYPE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WRITETYPE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WRITETYPE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_3_WRITEMULTIPLE_MASK                   (0x10000000U)
#define CSL_GPMC_CONFIG1_3_WRITEMULTIPLE_SHIFT                  (28U)
#define CSL_GPMC_CONFIG1_3_WRITEMULTIPLE_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WRITEMULTIPLE_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WRITEMULTIPLE_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG1_3_READTYPE_MASK                        (0x20000000U)
#define CSL_GPMC_CONFIG1_3_READTYPE_SHIFT                       (29U)
#define CSL_GPMC_CONFIG1_3_READTYPE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG1_3_READTYPE_EN_0X1                      (0x00000001U)
#define CSL_GPMC_CONFIG1_3_READTYPE_EN_0X0                      (0x00000000U)

#define CSL_GPMC_CONFIG1_3_READMULTIPLE_MASK                    (0x40000000U)
#define CSL_GPMC_CONFIG1_3_READMULTIPLE_SHIFT                   (30U)
#define CSL_GPMC_CONFIG1_3_READMULTIPLE_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG1_3_READMULTIPLE_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG1_3_READMULTIPLE_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG1_3_WRAPBURST_MASK                       (0x80000000U)
#define CSL_GPMC_CONFIG1_3_WRAPBURST_SHIFT                      (31U)
#define CSL_GPMC_CONFIG1_3_WRAPBURST_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WRAPBURST_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_3_WRAPBURST_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_3_RESETVAL                             (0x00000000U)

/* ECC9_RESULT */

#define CSL_GPMC_ECC9_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC9_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC9_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC9_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC9_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC9_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC9_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC9_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC9_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC9_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC9_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC9_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC9_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC9_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC9_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC9_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC9_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC9_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC9_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC9_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC9_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC9_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC9_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC9_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC9_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC9_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC9_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC9_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC9_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC9_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC9_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC9_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC9_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC9_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC9_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC9_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC9_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC9_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC9_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC9_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC9_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC9_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC9_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC9_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC9_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC9_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC9_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC9_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC9_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC9_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC9_RESULT_RESETVAL                           (0x00000000U)

/* CONFIG5_4 */

#define CSL_GPMC_CONFIG5_4_RDCYCLETIME_MASK                     (0x0000001FU)
#define CSL_GPMC_CONFIG5_4_RDCYCLETIME_SHIFT                    (0U)
#define CSL_GPMC_CONFIG5_4_RDCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_4_RDCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_4_WRCYCLETIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG5_4_WRCYCLETIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG5_4_WRCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_4_WRCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_4_RDACCESSTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG5_4_RDACCESSTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG5_4_RDACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG5_4_RDACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG5_4_PAGEBURSTACCESSTIME_MASK             (0x0F000000U)
#define CSL_GPMC_CONFIG5_4_PAGEBURSTACCESSTIME_SHIFT            (24U)
#define CSL_GPMC_CONFIG5_4_PAGEBURSTACCESSTIME_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG5_4_PAGEBURSTACCESSTIME_MAX              (0x0000000fU)

#define CSL_GPMC_CONFIG5_4_RESETVAL                             (0x00000000U)

/* CONFIG4_0 */

#define CSL_GPMC_CONFIG4_0_OEONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG4_0_OEONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG4_0_OEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_0_OEAADMUXONTIME_MASK                  (0x00000070U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXONTIME_SHIFT                 (4U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXONTIME_RESETVAL              (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXONTIME_EN_0X0                (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXONTIME_EN_0X1                (0x00000001U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXONTIME_EN_0X7                (0x00000007U)

#define CSL_GPMC_CONFIG4_0_OEEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG4_0_OEEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG4_0_OEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG4_0_OEOFFTIME_MASK                       (0x00001F00U)
#define CSL_GPMC_CONFIG4_0_OEOFFTIME_SHIFT                      (8U)
#define CSL_GPMC_CONFIG4_0_OEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_0_OEAADMUXOFFTIME_MASK                 (0x0000E000U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXOFFTIME_SHIFT                (13U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXOFFTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXOFFTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXOFFTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG4_0_OEAADMUXOFFTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG4_0_WEONTIME_MASK                        (0x000F0000U)
#define CSL_GPMC_CONFIG4_0_WEONTIME_SHIFT                       (16U)
#define CSL_GPMC_CONFIG4_0_WEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_0_WEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_0_WEEXTRADELAY_MASK                    (0x00800000U)
#define CSL_GPMC_CONFIG4_0_WEEXTRADELAY_SHIFT                   (23U)
#define CSL_GPMC_CONFIG4_0_WEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_0_WEEXTRADELAY_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG4_0_WEEXTRADELAY_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG4_0_WEOFFTIME_MASK                       (0x1F000000U)
#define CSL_GPMC_CONFIG4_0_WEOFFTIME_SHIFT                      (24U)
#define CSL_GPMC_CONFIG4_0_WEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_0_WEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_0_RESETVAL                             (0x00000000U)

/* BCH_RESULT4_2 */

#define CSL_GPMC_BCH_RESULT4_2_BCH_RESULT4_2_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT4_2_BCH_RESULT4_2_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT4_2_BCH_RESULT4_2_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT4_2_BCH_RESULT4_2_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT4_2_RESETVAL                         (0x00000000U)

/* CONFIG3_0 */

#define CSL_GPMC_CONFIG3_0_ADVONTIME_MASK                       (0x0000000FU)
#define CSL_GPMC_CONFIG3_0_ADVONTIME_SHIFT                      (0U)
#define CSL_GPMC_CONFIG3_0_ADVONTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVONTIME_MAX                        (0x0000000fU)

#define CSL_GPMC_CONFIG3_0_ADVAADMUXONTIME_MASK                 (0x00000070U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXONTIME_SHIFT                (4U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXONTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXONTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXONTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXONTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG3_0_ADVEXTRADELAY_MASK                   (0x00000080U)
#define CSL_GPMC_CONFIG3_0_ADVEXTRADELAY_SHIFT                  (7U)
#define CSL_GPMC_CONFIG3_0_ADVEXTRADELAY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVEXTRADELAY_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG3_0_ADVEXTRADELAY_EN_0X0                 (0x00000000U)

#define CSL_GPMC_CONFIG3_0_ADVRDOFFTIME_MASK                    (0x00001F00U)
#define CSL_GPMC_CONFIG3_0_ADVRDOFFTIME_SHIFT                   (8U)
#define CSL_GPMC_CONFIG3_0_ADVRDOFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVRDOFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_0_ADVWROFFTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG3_0_ADVWROFFTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG3_0_ADVWROFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVWROFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_0_ADVAADMUXRDOFFTIME_MASK              (0x07000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXRDOFFTIME_SHIFT             (24U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXRDOFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXRDOFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXRDOFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXRDOFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_0_ADVAADMUXWROFFTIME_MASK              (0x70000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXWROFFTIME_SHIFT             (28U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXWROFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXWROFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXWROFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_0_ADVAADMUXWROFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_0_RESETVAL                             (0x00000000U)

/* BCH_RESULT3_1 */

#define CSL_GPMC_BCH_RESULT3_1_BCH_RESULT3_1_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT3_1_BCH_RESULT3_1_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT3_1_BCH_RESULT3_1_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT3_1_BCH_RESULT3_1_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT3_1_RESETVAL                         (0x00000000U)

/* BCH_RESULT5_0 */

#define CSL_GPMC_BCH_RESULT5_0_BCH_RESULT5_0_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT5_0_BCH_RESULT5_0_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT5_0_BCH_RESULT5_0_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT5_0_BCH_RESULT5_0_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT5_0_RESETVAL                         (0x00000000U)

/* SYSSTS */

#define CSL_GPMC_SYSSTS_RESETDONE_MASK                          (0x00000001U)
#define CSL_GPMC_SYSSTS_RESETDONE_SHIFT                         (0U)
#define CSL_GPMC_SYSSTS_RESETDONE_RESETVAL                      (0x00000000U)
#define CSL_GPMC_SYSSTS_RESETDONE_EN_0X0                        (0x00000000U)
#define CSL_GPMC_SYSSTS_RESETDONE_EN_0X1                        (0x00000001U)

#define CSL_GPMC_SYSSTS_RESETVAL                                (0x00000000U)

/* PREFETCH_STS */

#define CSL_GPMC_PREFETCH_STS_COUNTVALUE_MASK                   (0x00003FFFU)
#define CSL_GPMC_PREFETCH_STS_COUNTVALUE_SHIFT                  (0U)
#define CSL_GPMC_PREFETCH_STS_COUNTVALUE_RESETVAL               (0x00000000U)
#define CSL_GPMC_PREFETCH_STS_COUNTVALUE_MAX                    (0x00003fffU)

#define CSL_GPMC_PREFETCH_STS_FIFOTHRSTS_MASK                   (0x00010000U)
#define CSL_GPMC_PREFETCH_STS_FIFOTHRSTS_SHIFT                  (16U)
#define CSL_GPMC_PREFETCH_STS_FIFOTHRSTS_RESETVAL               (0x00000000U)
#define CSL_GPMC_PREFETCH_STS_FIFOTHRSTS_EN_0X0                 (0x00000000U)
#define CSL_GPMC_PREFETCH_STS_FIFOTHRSTS_EN_0X1                 (0x00000001U)

#define CSL_GPMC_PREFETCH_STS_FIFOPOINTER_MASK                  (0x7F000000U)
#define CSL_GPMC_PREFETCH_STS_FIFOPOINTER_SHIFT                 (24U)
#define CSL_GPMC_PREFETCH_STS_FIFOPOINTER_RESETVAL              (0x00000000U)
#define CSL_GPMC_PREFETCH_STS_FIFOPOINTER_MAX                   (0x0000007fU)

#define CSL_GPMC_PREFETCH_STS_RESETVAL                          (0x00000000U)

/* CONFIG6_3 */

#define CSL_GPMC_CONFIG6_3_BUSTURNAROUND_MASK                   (0x0000000FU)
#define CSL_GPMC_CONFIG6_3_BUSTURNAROUND_SHIFT                  (0U)
#define CSL_GPMC_CONFIG6_3_BUSTURNAROUND_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG6_3_BUSTURNAROUND_MAX                    (0x0000000fU)

#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDIFFCSEN_MASK             (0x00000040U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDIFFCSEN_SHIFT            (6U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDIFFCSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDIFFCSEN_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDIFFCSEN_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLESAMECSEN_MASK             (0x00000080U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLESAMECSEN_SHIFT            (7U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLESAMECSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLESAMECSEN_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLESAMECSEN_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDELAY_MASK                (0x00000F00U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDELAY_SHIFT               (8U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDELAY_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_3_CYCLE2CYCLEDELAY_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_3_WRDATAONADMUXBUS_MASK                (0x000F0000U)
#define CSL_GPMC_CONFIG6_3_WRDATAONADMUXBUS_SHIFT               (16U)
#define CSL_GPMC_CONFIG6_3_WRDATAONADMUXBUS_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_3_WRDATAONADMUXBUS_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_3_WRACCESSTIME_MASK                    (0x1F000000U)
#define CSL_GPMC_CONFIG6_3_WRACCESSTIME_SHIFT                   (24U)
#define CSL_GPMC_CONFIG6_3_WRACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG6_3_WRACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG6_3_RESETVAL                             (0x00000000U)

/* STS */

#define CSL_GPMC_STS_EMPTYWRITEBUFFERSTS_MASK                   (0x00000001U)
#define CSL_GPMC_STS_EMPTYWRITEBUFFERSTS_SHIFT                  (0U)
#define CSL_GPMC_STS_EMPTYWRITEBUFFERSTS_RESETVAL               (0x00000000U)
#define CSL_GPMC_STS_EMPTYWRITEBUFFERSTS_EN_0X1                 (0x00000001U)
#define CSL_GPMC_STS_EMPTYWRITEBUFFERSTS_EN_0X0                 (0x00000000U)

#define CSL_GPMC_STS_WAIT0STS_MASK                              (0x00000100U)
#define CSL_GPMC_STS_WAIT0STS_SHIFT                             (8U)
#define CSL_GPMC_STS_WAIT0STS_RESETVAL                          (0x00000000U)
#define CSL_GPMC_STS_WAIT0STS_EN_0X0                            (0x00000000U)
#define CSL_GPMC_STS_WAIT0STS_EN_0X1                            (0x00000001U)

#define CSL_GPMC_STS_WAIT1STS_MASK                              (0x00000200U)
#define CSL_GPMC_STS_WAIT1STS_SHIFT                             (9U)
#define CSL_GPMC_STS_WAIT1STS_RESETVAL                          (0x00000000U)
#define CSL_GPMC_STS_WAIT1STS_EN_0X1                            (0x00000001U)
#define CSL_GPMC_STS_WAIT1STS_EN_0X0                            (0x00000000U)

#define CSL_GPMC_STS_RESETVAL                                   (0x00000000U)

/* CONFIG2_6 */

#define CSL_GPMC_CONFIG2_6_CSONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG2_6_CSONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG2_6_CSONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG2_6_CSONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG2_6_CSEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG2_6_CSEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG2_6_CSEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG2_6_CSEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG2_6_CSEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG2_6_CSRDOFFTIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG2_6_CSRDOFFTIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG2_6_CSRDOFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_6_CSRDOFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_6_CSWROFFTIME_MASK                     (0x001F0000U)
#define CSL_GPMC_CONFIG2_6_CSWROFFTIME_SHIFT                    (16U)
#define CSL_GPMC_CONFIG2_6_CSWROFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_6_CSWROFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_6_RESETVAL                             (0x00000000U)

/* BCH_RESULT6_5 */

#define CSL_GPMC_BCH_RESULT6_5_BCH_RESULT6_5_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT6_5_BCH_RESULT6_5_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT6_5_BCH_RESULT6_5_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT6_5_BCH_RESULT6_5_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT6_5_RESETVAL                         (0x00000000U)

/* ECC_CTRL */

#define CSL_GPMC_ECC_CTRL_ECCPOINTER_MASK                       (0x0000000FU)
#define CSL_GPMC_ECC_CTRL_ECCPOINTER_SHIFT                      (0U)
#define CSL_GPMC_ECC_CTRL_ECCPOINTER_RESETVAL                   (0x00000000U)
#define CSL_GPMC_ECC_CTRL_ECCPOINTER_MAX                        (0x0000000fU)

#define CSL_GPMC_ECC_CTRL_ECCCLR_MASK                           (0x00000100U)
#define CSL_GPMC_ECC_CTRL_ECCCLR_SHIFT                          (8U)
#define CSL_GPMC_ECC_CTRL_ECCCLR_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC_CTRL_ECCCLR_EN_0X0R                        (0x00000000U)
#define CSL_GPMC_ECC_CTRL_ECCCLR_EN_0X1W                        (0x00000001U)
#define CSL_GPMC_ECC_CTRL_ECCCLR_EN_0X0W                        (0x00000000U)

#define CSL_GPMC_ECC_CTRL_RESETVAL                              (0x00000000U)

/* CONFIG3_6 */

#define CSL_GPMC_CONFIG3_6_ADVONTIME_MASK                       (0x0000000FU)
#define CSL_GPMC_CONFIG3_6_ADVONTIME_SHIFT                      (0U)
#define CSL_GPMC_CONFIG3_6_ADVONTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVONTIME_MAX                        (0x0000000fU)

#define CSL_GPMC_CONFIG3_6_ADVAADMUXONTIME_MASK                 (0x00000070U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXONTIME_SHIFT                (4U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXONTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXONTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXONTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXONTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG3_6_ADVEXTRADELAY_MASK                   (0x00000080U)
#define CSL_GPMC_CONFIG3_6_ADVEXTRADELAY_SHIFT                  (7U)
#define CSL_GPMC_CONFIG3_6_ADVEXTRADELAY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVEXTRADELAY_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG3_6_ADVEXTRADELAY_EN_0X0                 (0x00000000U)

#define CSL_GPMC_CONFIG3_6_ADVRDOFFTIME_MASK                    (0x00001F00U)
#define CSL_GPMC_CONFIG3_6_ADVRDOFFTIME_SHIFT                   (8U)
#define CSL_GPMC_CONFIG3_6_ADVRDOFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVRDOFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_6_ADVWROFFTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG3_6_ADVWROFFTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG3_6_ADVWROFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVWROFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_6_ADVAADMUXRDOFFTIME_MASK              (0x07000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXRDOFFTIME_SHIFT             (24U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXRDOFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXRDOFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXRDOFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXRDOFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_6_ADVAADMUXWROFFTIME_MASK              (0x70000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXWROFFTIME_SHIFT             (28U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXWROFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXWROFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXWROFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_6_ADVAADMUXWROFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_6_RESETVAL                             (0x00000000U)

/* NAND_ADDR_5 */

#define CSL_GPMC_NAND_ADDR_5_GPMC_NAND_ADDR_5_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_ADDR_5_GPMC_NAND_ADDR_5_SHIFT             (0U)
#define CSL_GPMC_NAND_ADDR_5_GPMC_NAND_ADDR_5_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_ADDR_5_GPMC_NAND_ADDR_5_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_ADDR_5_RESETVAL                           (0x00000000U)

/* NAND_COMMAND_0 */

#define CSL_GPMC_NAND_COMMAND_0_GPMC_NAND_COMMAND_0_MASK        (0xFFFFFFFFU)
#define CSL_GPMC_NAND_COMMAND_0_GPMC_NAND_COMMAND_0_SHIFT       (0U)
#define CSL_GPMC_NAND_COMMAND_0_GPMC_NAND_COMMAND_0_RESETVAL    (0x00000000U)
#define CSL_GPMC_NAND_COMMAND_0_GPMC_NAND_COMMAND_0_MAX         (0xffffffffU)

#define CSL_GPMC_NAND_COMMAND_0_RESETVAL                        (0x00000000U)

/* CONFIG3_1 */

#define CSL_GPMC_CONFIG3_1_ADVONTIME_MASK                       (0x0000000FU)
#define CSL_GPMC_CONFIG3_1_ADVONTIME_SHIFT                      (0U)
#define CSL_GPMC_CONFIG3_1_ADVONTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVONTIME_MAX                        (0x0000000fU)

#define CSL_GPMC_CONFIG3_1_ADVAADMUXONTIME_MASK                 (0x00000070U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXONTIME_SHIFT                (4U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXONTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXONTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXONTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXONTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG3_1_ADVEXTRADELAY_MASK                   (0x00000080U)
#define CSL_GPMC_CONFIG3_1_ADVEXTRADELAY_SHIFT                  (7U)
#define CSL_GPMC_CONFIG3_1_ADVEXTRADELAY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVEXTRADELAY_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG3_1_ADVEXTRADELAY_EN_0X0                 (0x00000000U)

#define CSL_GPMC_CONFIG3_1_ADVRDOFFTIME_MASK                    (0x00001F00U)
#define CSL_GPMC_CONFIG3_1_ADVRDOFFTIME_SHIFT                   (8U)
#define CSL_GPMC_CONFIG3_1_ADVRDOFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVRDOFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_1_ADVWROFFTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG3_1_ADVWROFFTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG3_1_ADVWROFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVWROFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_1_ADVAADMUXRDOFFTIME_MASK              (0x07000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXRDOFFTIME_SHIFT             (24U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXRDOFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXRDOFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXRDOFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXRDOFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_1_ADVAADMUXWROFFTIME_MASK              (0x70000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXWROFFTIME_SHIFT             (28U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXWROFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXWROFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXWROFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_1_ADVAADMUXWROFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_1_RESETVAL                             (0x00000000U)

/* CONFIG6_5 */

#define CSL_GPMC_CONFIG6_5_BUSTURNAROUND_MASK                   (0x0000000FU)
#define CSL_GPMC_CONFIG6_5_BUSTURNAROUND_SHIFT                  (0U)
#define CSL_GPMC_CONFIG6_5_BUSTURNAROUND_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG6_5_BUSTURNAROUND_MAX                    (0x0000000fU)

#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDIFFCSEN_MASK             (0x00000040U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDIFFCSEN_SHIFT            (6U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDIFFCSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDIFFCSEN_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDIFFCSEN_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLESAMECSEN_MASK             (0x00000080U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLESAMECSEN_SHIFT            (7U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLESAMECSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLESAMECSEN_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLESAMECSEN_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDELAY_MASK                (0x00000F00U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDELAY_SHIFT               (8U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDELAY_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_5_CYCLE2CYCLEDELAY_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_5_WRDATAONADMUXBUS_MASK                (0x000F0000U)
#define CSL_GPMC_CONFIG6_5_WRDATAONADMUXBUS_SHIFT               (16U)
#define CSL_GPMC_CONFIG6_5_WRDATAONADMUXBUS_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_5_WRDATAONADMUXBUS_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_5_WRACCESSTIME_MASK                    (0x1F000000U)
#define CSL_GPMC_CONFIG6_5_WRACCESSTIME_SHIFT                   (24U)
#define CSL_GPMC_CONFIG6_5_WRACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG6_5_WRACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG6_5_RESETVAL                             (0x00000000U)

/* CONFIG5_3 */

#define CSL_GPMC_CONFIG5_3_RDCYCLETIME_MASK                     (0x0000001FU)
#define CSL_GPMC_CONFIG5_3_RDCYCLETIME_SHIFT                    (0U)
#define CSL_GPMC_CONFIG5_3_RDCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_3_RDCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_3_WRCYCLETIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG5_3_WRCYCLETIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG5_3_WRCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_3_WRCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_3_RDACCESSTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG5_3_RDACCESSTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG5_3_RDACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG5_3_RDACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG5_3_PAGEBURSTACCESSTIME_MASK             (0x0F000000U)
#define CSL_GPMC_CONFIG5_3_PAGEBURSTACCESSTIME_SHIFT            (24U)
#define CSL_GPMC_CONFIG5_3_PAGEBURSTACCESSTIME_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG5_3_PAGEBURSTACCESSTIME_MAX              (0x0000000fU)

#define CSL_GPMC_CONFIG5_3_RESETVAL                             (0x00000000U)

/* BCH_RESULT3_5 */

#define CSL_GPMC_BCH_RESULT3_5_BCH_RESULT3_5_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT3_5_BCH_RESULT3_5_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT3_5_BCH_RESULT3_5_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT3_5_BCH_RESULT3_5_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT3_5_RESETVAL                         (0x00000000U)

/* ECC1_RESULT */

#define CSL_GPMC_ECC1_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC1_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC1_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC1_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC1_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC1_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC1_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC1_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC1_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC1_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC1_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC1_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC1_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC1_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC1_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC1_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC1_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC1_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC1_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC1_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC1_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC1_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC1_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC1_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC1_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC1_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC1_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC1_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC1_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC1_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC1_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC1_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC1_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC1_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC1_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC1_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC1_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC1_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC1_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC1_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC1_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC1_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC1_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC1_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC1_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC1_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC1_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC1_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC1_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC1_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC1_RESULT_RESETVAL                           (0x00000000U)

/* NAND_ADDR_0 */

#define CSL_GPMC_NAND_ADDR_0_GPMC_NAND_ADDR_0_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_ADDR_0_GPMC_NAND_ADDR_0_SHIFT             (0U)
#define CSL_GPMC_NAND_ADDR_0_GPMC_NAND_ADDR_0_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_ADDR_0_GPMC_NAND_ADDR_0_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_ADDR_0_RESETVAL                           (0x00000000U)

/* ECC3_RESULT */

#define CSL_GPMC_ECC3_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC3_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC3_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC3_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC3_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC3_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC3_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC3_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC3_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC3_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC3_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC3_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC3_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC3_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC3_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC3_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC3_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC3_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC3_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC3_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC3_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC3_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC3_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC3_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC3_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC3_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC3_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC3_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC3_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC3_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC3_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC3_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC3_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC3_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC3_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC3_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC3_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC3_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC3_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC3_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC3_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC3_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC3_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC3_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC3_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC3_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC3_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC3_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC3_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC3_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC3_RESULT_RESETVAL                           (0x00000000U)

/* BCH_RESULT0_6 */

#define CSL_GPMC_BCH_RESULT0_6_BCH_RESULT0_6_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT0_6_BCH_RESULT0_6_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT0_6_BCH_RESULT0_6_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT0_6_BCH_RESULT0_6_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT0_6_RESETVAL                         (0x00000000U)

/* CONFIG5_6 */

#define CSL_GPMC_CONFIG5_6_RDCYCLETIME_MASK                     (0x0000001FU)
#define CSL_GPMC_CONFIG5_6_RDCYCLETIME_SHIFT                    (0U)
#define CSL_GPMC_CONFIG5_6_RDCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_6_RDCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_6_WRCYCLETIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG5_6_WRCYCLETIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG5_6_WRCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_6_WRCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_6_RDACCESSTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG5_6_RDACCESSTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG5_6_RDACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG5_6_RDACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG5_6_PAGEBURSTACCESSTIME_MASK             (0x0F000000U)
#define CSL_GPMC_CONFIG5_6_PAGEBURSTACCESSTIME_SHIFT            (24U)
#define CSL_GPMC_CONFIG5_6_PAGEBURSTACCESSTIME_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG5_6_PAGEBURSTACCESSTIME_MAX              (0x0000000fU)

#define CSL_GPMC_CONFIG5_6_RESETVAL                             (0x00000000U)

/* CONFIG1_2 */

#define CSL_GPMC_CONFIG1_2_GPMCFCLKDIVIDER_MASK                 (0x00000003U)
#define CSL_GPMC_CONFIG1_2_GPMCFCLKDIVIDER_SHIFT                (0U)
#define CSL_GPMC_CONFIG1_2_GPMCFCLKDIVIDER_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG1_2_GPMCFCLKDIVIDER_EN_0X3               (0x00000003U)
#define CSL_GPMC_CONFIG1_2_GPMCFCLKDIVIDER_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG1_2_GPMCFCLKDIVIDER_EN_0X2               (0x00000002U)
#define CSL_GPMC_CONFIG1_2_GPMCFCLKDIVIDER_EN_0X0               (0x00000000U)

#define CSL_GPMC_CONFIG1_2_TIMEPARAGRANULARITY_MASK             (0x00000010U)
#define CSL_GPMC_CONFIG1_2_TIMEPARAGRANULARITY_SHIFT            (4U)
#define CSL_GPMC_CONFIG1_2_TIMEPARAGRANULARITY_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_2_TIMEPARAGRANULARITY_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG1_2_TIMEPARAGRANULARITY_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG1_2_MUXADDDATA_MASK                      (0x00000300U)
#define CSL_GPMC_CONFIG1_2_MUXADDDATA_SHIFT                     (8U)
#define CSL_GPMC_CONFIG1_2_MUXADDDATA_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_2_MUXADDDATA_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_2_MUXADDDATA_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_2_MUXADDDATA_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_2_MUXADDDATA_EN_0X0                    (0x00000000U)

#define CSL_GPMC_CONFIG1_2_DEVICETYPE_MASK                      (0x00000C00U)
#define CSL_GPMC_CONFIG1_2_DEVICETYPE_SHIFT                     (10U)
#define CSL_GPMC_CONFIG1_2_DEVICETYPE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_2_DEVICETYPE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_2_DEVICETYPE_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_2_DEVICETYPE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_2_DEVICETYPE_EN_0X2                    (0x00000002U)

#define CSL_GPMC_CONFIG1_2_DEVICESIZE_MASK                      (0x00003000U)
#define CSL_GPMC_CONFIG1_2_DEVICESIZE_SHIFT                     (12U)
#define CSL_GPMC_CONFIG1_2_DEVICESIZE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_2_DEVICESIZE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_2_DEVICESIZE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_2_DEVICESIZE_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_2_DEVICESIZE_EN_0X3                    (0x00000003U)

#define CSL_GPMC_CONFIG1_2_WAITPINSELECT_MASK                   (0x00030000U)
#define CSL_GPMC_CONFIG1_2_WAITPINSELECT_SHIFT                  (16U)
#define CSL_GPMC_CONFIG1_2_WAITPINSELECT_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WAITPINSELECT_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WAITPINSELECT_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG1_2_WAITPINSELECT_EN_0X2                 (0x00000002U)
#define CSL_GPMC_CONFIG1_2_WAITPINSELECT_EN_0X3                 (0x00000003U)

#define CSL_GPMC_CONFIG1_2_WAITMONITORINGTIME_MASK              (0x000C0000U)
#define CSL_GPMC_CONFIG1_2_WAITMONITORINGTIME_SHIFT             (18U)
#define CSL_GPMC_CONFIG1_2_WAITMONITORINGTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WAITMONITORINGTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG1_2_WAITMONITORINGTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WAITMONITORINGTIME_EN_0X3            (0x00000003U)
#define CSL_GPMC_CONFIG1_2_WAITMONITORINGTIME_EN_0X2            (0x00000002U)

#define CSL_GPMC_CONFIG1_2_WAITWRITEMONITORING_MASK             (0x00200000U)
#define CSL_GPMC_CONFIG1_2_WAITWRITEMONITORING_SHIFT            (21U)
#define CSL_GPMC_CONFIG1_2_WAITWRITEMONITORING_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WAITWRITEMONITORING_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG1_2_WAITWRITEMONITORING_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG1_2_WAITREADMONITORING_MASK              (0x00400000U)
#define CSL_GPMC_CONFIG1_2_WAITREADMONITORING_SHIFT             (22U)
#define CSL_GPMC_CONFIG1_2_WAITREADMONITORING_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WAITREADMONITORING_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WAITREADMONITORING_EN_0X1            (0x00000001U)

#define CSL_GPMC_CONFIG1_2_ATTACHEDDEVICEPAGELENGTH_MASK        (0x01800000U)
#define CSL_GPMC_CONFIG1_2_ATTACHEDDEVICEPAGELENGTH_SHIFT       (23U)
#define CSL_GPMC_CONFIG1_2_ATTACHEDDEVICEPAGELENGTH_RESETVAL    (0x00000000U)
#define CSL_GPMC_CONFIG1_2_ATTACHEDDEVICEPAGELENGTH_EN_0X1      (0x00000001U)
#define CSL_GPMC_CONFIG1_2_ATTACHEDDEVICEPAGELENGTH_EN_0X2      (0x00000002U)
#define CSL_GPMC_CONFIG1_2_ATTACHEDDEVICEPAGELENGTH_EN_0X3      (0x00000003U)
#define CSL_GPMC_CONFIG1_2_ATTACHEDDEVICEPAGELENGTH_EN_0X0      (0x00000000U)

#define CSL_GPMC_CONFIG1_2_CLKACTIVATIONTIME_MASK               (0x06000000U)
#define CSL_GPMC_CONFIG1_2_CLKACTIVATIONTIME_SHIFT              (25U)
#define CSL_GPMC_CONFIG1_2_CLKACTIVATIONTIME_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG1_2_CLKACTIVATIONTIME_EN_0X0             (0x00000000U)
#define CSL_GPMC_CONFIG1_2_CLKACTIVATIONTIME_EN_0X2             (0x00000002U)
#define CSL_GPMC_CONFIG1_2_CLKACTIVATIONTIME_EN_0X3             (0x00000003U)
#define CSL_GPMC_CONFIG1_2_CLKACTIVATIONTIME_EN_0X1             (0x00000001U)

#define CSL_GPMC_CONFIG1_2_WRITETYPE_MASK                       (0x08000000U)
#define CSL_GPMC_CONFIG1_2_WRITETYPE_SHIFT                      (27U)
#define CSL_GPMC_CONFIG1_2_WRITETYPE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WRITETYPE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WRITETYPE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_2_WRITEMULTIPLE_MASK                   (0x10000000U)
#define CSL_GPMC_CONFIG1_2_WRITEMULTIPLE_SHIFT                  (28U)
#define CSL_GPMC_CONFIG1_2_WRITEMULTIPLE_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WRITEMULTIPLE_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WRITEMULTIPLE_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG1_2_READTYPE_MASK                        (0x20000000U)
#define CSL_GPMC_CONFIG1_2_READTYPE_SHIFT                       (29U)
#define CSL_GPMC_CONFIG1_2_READTYPE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG1_2_READTYPE_EN_0X1                      (0x00000001U)
#define CSL_GPMC_CONFIG1_2_READTYPE_EN_0X0                      (0x00000000U)

#define CSL_GPMC_CONFIG1_2_READMULTIPLE_MASK                    (0x40000000U)
#define CSL_GPMC_CONFIG1_2_READMULTIPLE_SHIFT                   (30U)
#define CSL_GPMC_CONFIG1_2_READMULTIPLE_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG1_2_READMULTIPLE_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG1_2_READMULTIPLE_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG1_2_WRAPBURST_MASK                       (0x80000000U)
#define CSL_GPMC_CONFIG1_2_WRAPBURST_SHIFT                      (31U)
#define CSL_GPMC_CONFIG1_2_WRAPBURST_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WRAPBURST_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_2_WRAPBURST_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_2_RESETVAL                             (0x00000000U)

/* NAND_DATA_4 */

#define CSL_GPMC_NAND_DATA_4_GPMC_NAND_DATA_4_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_DATA_4_GPMC_NAND_DATA_4_SHIFT             (0U)
#define CSL_GPMC_NAND_DATA_4_GPMC_NAND_DATA_4_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_DATA_4_GPMC_NAND_DATA_4_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_DATA_4_RESETVAL                           (0x00000000U)

/* CONFIG2_0 */

#define CSL_GPMC_CONFIG2_0_CSONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG2_0_CSONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG2_0_CSONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG2_0_CSONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG2_0_CSEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG2_0_CSEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG2_0_CSEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG2_0_CSEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG2_0_CSEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG2_0_CSRDOFFTIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG2_0_CSRDOFFTIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG2_0_CSRDOFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_0_CSRDOFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_0_CSWROFFTIME_MASK                     (0x001F0000U)
#define CSL_GPMC_CONFIG2_0_CSWROFFTIME_SHIFT                    (16U)
#define CSL_GPMC_CONFIG2_0_CSWROFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_0_CSWROFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_0_RESETVAL                             (0x00000000U)

/* CONFIG5_0 */

#define CSL_GPMC_CONFIG5_0_RDCYCLETIME_MASK                     (0x0000001FU)
#define CSL_GPMC_CONFIG5_0_RDCYCLETIME_SHIFT                    (0U)
#define CSL_GPMC_CONFIG5_0_RDCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_0_RDCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_0_WRCYCLETIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG5_0_WRCYCLETIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG5_0_WRCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_0_WRCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_0_RDACCESSTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG5_0_RDACCESSTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG5_0_RDACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG5_0_RDACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG5_0_PAGEBURSTACCESSTIME_MASK             (0x0F000000U)
#define CSL_GPMC_CONFIG5_0_PAGEBURSTACCESSTIME_SHIFT            (24U)
#define CSL_GPMC_CONFIG5_0_PAGEBURSTACCESSTIME_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG5_0_PAGEBURSTACCESSTIME_MAX              (0x0000000fU)

#define CSL_GPMC_CONFIG5_0_RESETVAL                             (0x00000000U)

/* BCH_RESULT6_6 */

#define CSL_GPMC_BCH_RESULT6_6_BCH_RESULT6_6_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT6_6_BCH_RESULT6_6_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT6_6_BCH_RESULT6_6_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT6_6_BCH_RESULT6_6_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT6_6_RESETVAL                         (0x00000000U)

/* NAND_ADDR_4 */

#define CSL_GPMC_NAND_ADDR_4_GPMC_NAND_ADDR_4_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_ADDR_4_GPMC_NAND_ADDR_4_SHIFT             (0U)
#define CSL_GPMC_NAND_ADDR_4_GPMC_NAND_ADDR_4_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_ADDR_4_GPMC_NAND_ADDR_4_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_ADDR_4_RESETVAL                           (0x00000000U)

/* ECC6_RESULT */

#define CSL_GPMC_ECC6_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC6_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC6_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC6_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC6_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC6_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC6_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC6_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC6_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC6_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC6_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC6_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC6_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC6_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC6_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC6_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC6_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC6_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC6_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC6_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC6_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC6_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC6_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC6_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC6_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC6_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC6_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC6_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC6_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC6_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC6_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC6_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC6_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC6_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC6_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC6_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC6_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC6_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC6_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC6_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC6_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC6_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC6_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC6_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC6_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC6_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC6_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC6_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC6_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC6_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC6_RESULT_RESETVAL                           (0x00000000U)

/* NAND_DATA_6 */

#define CSL_GPMC_NAND_DATA_6_GPMC_NAND_DATA_6_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_DATA_6_GPMC_NAND_DATA_6_SHIFT             (0U)
#define CSL_GPMC_NAND_DATA_6_GPMC_NAND_DATA_6_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_DATA_6_GPMC_NAND_DATA_6_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_DATA_6_RESETVAL                           (0x00000000U)

/* REVISION */

#define CSL_GPMC_REVISION_REV_MASK                              (0x000000FFU)
#define CSL_GPMC_REVISION_REV_SHIFT                             (0U)
#define CSL_GPMC_REVISION_REV_RESETVAL                          (0x00000000U)
#define CSL_GPMC_REVISION_REV_MAX                               (0x000000ffU)

#define CSL_GPMC_REVISION_RESETVAL                              (0x00000000U)

/* CONFIG6_1 */

#define CSL_GPMC_CONFIG6_1_BUSTURNAROUND_MASK                   (0x0000000FU)
#define CSL_GPMC_CONFIG6_1_BUSTURNAROUND_SHIFT                  (0U)
#define CSL_GPMC_CONFIG6_1_BUSTURNAROUND_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG6_1_BUSTURNAROUND_MAX                    (0x0000000fU)

#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDIFFCSEN_MASK             (0x00000040U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDIFFCSEN_SHIFT            (6U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDIFFCSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDIFFCSEN_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDIFFCSEN_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLESAMECSEN_MASK             (0x00000080U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLESAMECSEN_SHIFT            (7U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLESAMECSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLESAMECSEN_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLESAMECSEN_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDELAY_MASK                (0x00000F00U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDELAY_SHIFT               (8U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDELAY_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_1_CYCLE2CYCLEDELAY_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_1_WRDATAONADMUXBUS_MASK                (0x000F0000U)
#define CSL_GPMC_CONFIG6_1_WRDATAONADMUXBUS_SHIFT               (16U)
#define CSL_GPMC_CONFIG6_1_WRDATAONADMUXBUS_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_1_WRDATAONADMUXBUS_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_1_WRACCESSTIME_MASK                    (0x1F000000U)
#define CSL_GPMC_CONFIG6_1_WRACCESSTIME_SHIFT                   (24U)
#define CSL_GPMC_CONFIG6_1_WRACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG6_1_WRACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG6_1_RESETVAL                             (0x00000000U)

/* BCH_RESULT1_2 */

#define CSL_GPMC_BCH_RESULT1_2_BCH_RESULT1_2_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT1_2_BCH_RESULT1_2_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT1_2_BCH_RESULT1_2_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT1_2_BCH_RESULT1_2_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT1_2_RESETVAL                         (0x00000000U)

/* CONFIG2_3 */

#define CSL_GPMC_CONFIG2_3_CSONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG2_3_CSONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG2_3_CSONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG2_3_CSONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG2_3_CSEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG2_3_CSEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG2_3_CSEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG2_3_CSEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG2_3_CSEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG2_3_CSRDOFFTIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG2_3_CSRDOFFTIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG2_3_CSRDOFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_3_CSRDOFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_3_CSWROFFTIME_MASK                     (0x001F0000U)
#define CSL_GPMC_CONFIG2_3_CSWROFFTIME_SHIFT                    (16U)
#define CSL_GPMC_CONFIG2_3_CSWROFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_3_CSWROFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_3_RESETVAL                             (0x00000000U)

/* SYSCONFIG */

#define CSL_GPMC_SYSCONFIG_AUTOIDLE_MASK                        (0x00000001U)
#define CSL_GPMC_SYSCONFIG_AUTOIDLE_SHIFT                       (0U)
#define CSL_GPMC_SYSCONFIG_AUTOIDLE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_SYSCONFIG_AUTOIDLE_EN_0X0                      (0x00000000U)
#define CSL_GPMC_SYSCONFIG_AUTOIDLE_EN_0X1                      (0x00000001U)

#define CSL_GPMC_SYSCONFIG_SOFTRESET_MASK                       (0x00000002U)
#define CSL_GPMC_SYSCONFIG_SOFTRESET_SHIFT                      (1U)
#define CSL_GPMC_SYSCONFIG_SOFTRESET_RESETVAL                   (0x00000000U)
#define CSL_GPMC_SYSCONFIG_SOFTRESET_EN_0X0                     (0x00000000U)
#define CSL_GPMC_SYSCONFIG_SOFTRESET_EN_0X1                     (0x00000001U)

#define CSL_GPMC_SYSCONFIG_SIDLEMODE_MASK                       (0x00000018U)
#define CSL_GPMC_SYSCONFIG_SIDLEMODE_SHIFT                      (3U)
#define CSL_GPMC_SYSCONFIG_SIDLEMODE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_SYSCONFIG_SIDLEMODE_EN_0X3                     (0x00000003U)
#define CSL_GPMC_SYSCONFIG_SIDLEMODE_EN_0X2                     (0x00000002U)
#define CSL_GPMC_SYSCONFIG_SIDLEMODE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_SYSCONFIG_SIDLEMODE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_SYSCONFIG_RESETVAL                             (0x00000000U)

/* BCH_RESULT2_1 */

#define CSL_GPMC_BCH_RESULT2_1_BCH_RESULT2_1_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT2_1_BCH_RESULT2_1_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT2_1_BCH_RESULT2_1_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT2_1_BCH_RESULT2_1_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT2_1_RESETVAL                         (0x00000000U)

/* BCH_RESULT5_4 */

#define CSL_GPMC_BCH_RESULT5_4_BCH_RESULT5_4_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT5_4_BCH_RESULT5_4_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT5_4_BCH_RESULT5_4_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT5_4_BCH_RESULT5_4_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT5_4_RESETVAL                         (0x00000000U)

/* CONFIG1_0 */

#define CSL_GPMC_CONFIG1_0_GPMCFCLKDIVIDER_MASK                 (0x00000003U)
#define CSL_GPMC_CONFIG1_0_GPMCFCLKDIVIDER_SHIFT                (0U)
#define CSL_GPMC_CONFIG1_0_GPMCFCLKDIVIDER_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG1_0_GPMCFCLKDIVIDER_EN_0X3               (0x00000003U)
#define CSL_GPMC_CONFIG1_0_GPMCFCLKDIVIDER_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG1_0_GPMCFCLKDIVIDER_EN_0X2               (0x00000002U)
#define CSL_GPMC_CONFIG1_0_GPMCFCLKDIVIDER_EN_0X0               (0x00000000U)

#define CSL_GPMC_CONFIG1_0_TIMEPARAGRANULARITY_MASK             (0x00000010U)
#define CSL_GPMC_CONFIG1_0_TIMEPARAGRANULARITY_SHIFT            (4U)
#define CSL_GPMC_CONFIG1_0_TIMEPARAGRANULARITY_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_0_TIMEPARAGRANULARITY_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG1_0_TIMEPARAGRANULARITY_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG1_0_MUXADDDATA_MASK                      (0x00000300U)
#define CSL_GPMC_CONFIG1_0_MUXADDDATA_SHIFT                     (8U)
#define CSL_GPMC_CONFIG1_0_MUXADDDATA_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_0_MUXADDDATA_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_0_MUXADDDATA_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_0_MUXADDDATA_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_0_MUXADDDATA_EN_0X0                    (0x00000000U)

#define CSL_GPMC_CONFIG1_0_DEVICETYPE_MASK                      (0x00000C00U)
#define CSL_GPMC_CONFIG1_0_DEVICETYPE_SHIFT                     (10U)
#define CSL_GPMC_CONFIG1_0_DEVICETYPE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_0_DEVICETYPE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_0_DEVICETYPE_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_0_DEVICETYPE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_0_DEVICETYPE_EN_0X2                    (0x00000002U)

#define CSL_GPMC_CONFIG1_0_DEVICESIZE_MASK                      (0x00003000U)
#define CSL_GPMC_CONFIG1_0_DEVICESIZE_SHIFT                     (12U)
#define CSL_GPMC_CONFIG1_0_DEVICESIZE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_0_DEVICESIZE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_0_DEVICESIZE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_0_DEVICESIZE_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_0_DEVICESIZE_EN_0X3                    (0x00000003U)

#define CSL_GPMC_CONFIG1_0_WAITPINSELECT_MASK                   (0x00030000U)
#define CSL_GPMC_CONFIG1_0_WAITPINSELECT_SHIFT                  (16U)
#define CSL_GPMC_CONFIG1_0_WAITPINSELECT_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WAITPINSELECT_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WAITPINSELECT_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG1_0_WAITPINSELECT_EN_0X2                 (0x00000002U)
#define CSL_GPMC_CONFIG1_0_WAITPINSELECT_EN_0X3                 (0x00000003U)

#define CSL_GPMC_CONFIG1_0_WAITMONITORINGTIME_MASK              (0x000C0000U)
#define CSL_GPMC_CONFIG1_0_WAITMONITORINGTIME_SHIFT             (18U)
#define CSL_GPMC_CONFIG1_0_WAITMONITORINGTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WAITMONITORINGTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG1_0_WAITMONITORINGTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WAITMONITORINGTIME_EN_0X3            (0x00000003U)
#define CSL_GPMC_CONFIG1_0_WAITMONITORINGTIME_EN_0X2            (0x00000002U)

#define CSL_GPMC_CONFIG1_0_WAITWRITEMONITORING_MASK             (0x00200000U)
#define CSL_GPMC_CONFIG1_0_WAITWRITEMONITORING_SHIFT            (21U)
#define CSL_GPMC_CONFIG1_0_WAITWRITEMONITORING_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WAITWRITEMONITORING_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG1_0_WAITWRITEMONITORING_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG1_0_WAITREADMONITORING_MASK              (0x00400000U)
#define CSL_GPMC_CONFIG1_0_WAITREADMONITORING_SHIFT             (22U)
#define CSL_GPMC_CONFIG1_0_WAITREADMONITORING_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WAITREADMONITORING_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WAITREADMONITORING_EN_0X1            (0x00000001U)

#define CSL_GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_MASK        (0x01800000U)
#define CSL_GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_SHIFT       (23U)
#define CSL_GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_RESETVAL    (0x00000000U)
#define CSL_GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_EN_0X1      (0x00000001U)
#define CSL_GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_EN_0X2      (0x00000002U)
#define CSL_GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_EN_0X3      (0x00000003U)
#define CSL_GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_EN_0X0      (0x00000000U)

#define CSL_GPMC_CONFIG1_0_CLKACTIVATIONTIME_MASK               (0x06000000U)
#define CSL_GPMC_CONFIG1_0_CLKACTIVATIONTIME_SHIFT              (25U)
#define CSL_GPMC_CONFIG1_0_CLKACTIVATIONTIME_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG1_0_CLKACTIVATIONTIME_EN_0X0             (0x00000000U)
#define CSL_GPMC_CONFIG1_0_CLKACTIVATIONTIME_EN_0X2             (0x00000002U)
#define CSL_GPMC_CONFIG1_0_CLKACTIVATIONTIME_EN_0X3             (0x00000003U)
#define CSL_GPMC_CONFIG1_0_CLKACTIVATIONTIME_EN_0X1             (0x00000001U)

#define CSL_GPMC_CONFIG1_0_WRITETYPE_MASK                       (0x08000000U)
#define CSL_GPMC_CONFIG1_0_WRITETYPE_SHIFT                      (27U)
#define CSL_GPMC_CONFIG1_0_WRITETYPE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WRITETYPE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WRITETYPE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_0_WRITEMULTIPLE_MASK                   (0x10000000U)
#define CSL_GPMC_CONFIG1_0_WRITEMULTIPLE_SHIFT                  (28U)
#define CSL_GPMC_CONFIG1_0_WRITEMULTIPLE_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WRITEMULTIPLE_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WRITEMULTIPLE_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG1_0_READTYPE_MASK                        (0x20000000U)
#define CSL_GPMC_CONFIG1_0_READTYPE_SHIFT                       (29U)
#define CSL_GPMC_CONFIG1_0_READTYPE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG1_0_READTYPE_EN_0X1                      (0x00000001U)
#define CSL_GPMC_CONFIG1_0_READTYPE_EN_0X0                      (0x00000000U)

#define CSL_GPMC_CONFIG1_0_READMULTIPLE_MASK                    (0x40000000U)
#define CSL_GPMC_CONFIG1_0_READMULTIPLE_SHIFT                   (30U)
#define CSL_GPMC_CONFIG1_0_READMULTIPLE_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG1_0_READMULTIPLE_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG1_0_READMULTIPLE_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG1_0_WRAPBURST_MASK                       (0x80000000U)
#define CSL_GPMC_CONFIG1_0_WRAPBURST_SHIFT                      (31U)
#define CSL_GPMC_CONFIG1_0_WRAPBURST_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WRAPBURST_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_0_WRAPBURST_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_0_RESETVAL                             (0x00000000U)

/* BCH_RESULT1_5 */

#define CSL_GPMC_BCH_RESULT1_5_BCH_RESULT1_5_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT1_5_BCH_RESULT1_5_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT1_5_BCH_RESULT1_5_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT1_5_BCH_RESULT1_5_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT1_5_RESETVAL                         (0x00000000U)

/* CONFIG7_2 */

#define CSL_GPMC_CONFIG7_2_BASEADDR_MASK                        (0x0000003FU)
#define CSL_GPMC_CONFIG7_2_BASEADDR_SHIFT                       (0U)
#define CSL_GPMC_CONFIG7_2_BASEADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_2_BASEADDR_MAX                         (0x0000003fU)

#define CSL_GPMC_CONFIG7_2_CSVALID_MASK                         (0x00000040U)
#define CSL_GPMC_CONFIG7_2_CSVALID_SHIFT                        (6U)
#define CSL_GPMC_CONFIG7_2_CSVALID_RESETVAL                     (0x00000000U)
#define CSL_GPMC_CONFIG7_2_CSVALID_EN_0X0                       (0x00000000U)
#define CSL_GPMC_CONFIG7_2_CSVALID_EN_0X1                       (0x00000001U)

#define CSL_GPMC_CONFIG7_2_MASKADDR_MASK                        (0x00000F00U)
#define CSL_GPMC_CONFIG7_2_MASKADDR_SHIFT                       (8U)
#define CSL_GPMC_CONFIG7_2_MASKADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_2_MASKADDR_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG7_2_RESETVAL                             (0x00000000U)

/* BCH_RESULT3_3 */

#define CSL_GPMC_BCH_RESULT3_3_BCH_RESULT3_3_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT3_3_BCH_RESULT3_3_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT3_3_BCH_RESULT3_3_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT3_3_BCH_RESULT3_3_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT3_3_RESETVAL                         (0x00000000U)

/* BCH_RESULT2_5 */

#define CSL_GPMC_BCH_RESULT2_5_BCH_RESULT2_5_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT2_5_BCH_RESULT2_5_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT2_5_BCH_RESULT2_5_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT2_5_BCH_RESULT2_5_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT2_5_RESETVAL                         (0x00000000U)

/* CONFIG7_3 */

#define CSL_GPMC_CONFIG7_3_BASEADDR_MASK                        (0x0000003FU)
#define CSL_GPMC_CONFIG7_3_BASEADDR_SHIFT                       (0U)
#define CSL_GPMC_CONFIG7_3_BASEADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_3_BASEADDR_MAX                         (0x0000003fU)

#define CSL_GPMC_CONFIG7_3_CSVALID_MASK                         (0x00000040U)
#define CSL_GPMC_CONFIG7_3_CSVALID_SHIFT                        (6U)
#define CSL_GPMC_CONFIG7_3_CSVALID_RESETVAL                     (0x00000000U)
#define CSL_GPMC_CONFIG7_3_CSVALID_EN_0X0                       (0x00000000U)
#define CSL_GPMC_CONFIG7_3_CSVALID_EN_0X1                       (0x00000001U)

#define CSL_GPMC_CONFIG7_3_MASKADDR_MASK                        (0x00000F00U)
#define CSL_GPMC_CONFIG7_3_MASKADDR_SHIFT                       (8U)
#define CSL_GPMC_CONFIG7_3_MASKADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_3_MASKADDR_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG7_3_RESETVAL                             (0x00000000U)

/* CONFIG2_1 */

#define CSL_GPMC_CONFIG2_1_CSONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG2_1_CSONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG2_1_CSONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG2_1_CSONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG2_1_CSEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG2_1_CSEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG2_1_CSEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG2_1_CSEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG2_1_CSEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG2_1_CSRDOFFTIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG2_1_CSRDOFFTIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG2_1_CSRDOFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_1_CSRDOFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_1_CSWROFFTIME_MASK                     (0x001F0000U)
#define CSL_GPMC_CONFIG2_1_CSWROFFTIME_SHIFT                    (16U)
#define CSL_GPMC_CONFIG2_1_CSWROFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_1_CSWROFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_1_RESETVAL                             (0x00000000U)

/* CONFIG7_6 */

#define CSL_GPMC_CONFIG7_6_BASEADDR_MASK                        (0x0000003FU)
#define CSL_GPMC_CONFIG7_6_BASEADDR_SHIFT                       (0U)
#define CSL_GPMC_CONFIG7_6_BASEADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_6_BASEADDR_MAX                         (0x0000003fU)

#define CSL_GPMC_CONFIG7_6_CSVALID_MASK                         (0x00000040U)
#define CSL_GPMC_CONFIG7_6_CSVALID_SHIFT                        (6U)
#define CSL_GPMC_CONFIG7_6_CSVALID_RESETVAL                     (0x00000000U)
#define CSL_GPMC_CONFIG7_6_CSVALID_EN_0X0                       (0x00000000U)
#define CSL_GPMC_CONFIG7_6_CSVALID_EN_0X1                       (0x00000001U)

#define CSL_GPMC_CONFIG7_6_MASKADDR_MASK                        (0x00000F00U)
#define CSL_GPMC_CONFIG7_6_MASKADDR_SHIFT                       (8U)
#define CSL_GPMC_CONFIG7_6_MASKADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_6_MASKADDR_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG7_6_RESETVAL                             (0x00000000U)

/* CONFIG1_1 */

#define CSL_GPMC_CONFIG1_1_GPMCFCLKDIVIDER_MASK                 (0x00000003U)
#define CSL_GPMC_CONFIG1_1_GPMCFCLKDIVIDER_SHIFT                (0U)
#define CSL_GPMC_CONFIG1_1_GPMCFCLKDIVIDER_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG1_1_GPMCFCLKDIVIDER_EN_0X3               (0x00000003U)
#define CSL_GPMC_CONFIG1_1_GPMCFCLKDIVIDER_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG1_1_GPMCFCLKDIVIDER_EN_0X2               (0x00000002U)
#define CSL_GPMC_CONFIG1_1_GPMCFCLKDIVIDER_EN_0X0               (0x00000000U)

#define CSL_GPMC_CONFIG1_1_TIMEPARAGRANULARITY_MASK             (0x00000010U)
#define CSL_GPMC_CONFIG1_1_TIMEPARAGRANULARITY_SHIFT            (4U)
#define CSL_GPMC_CONFIG1_1_TIMEPARAGRANULARITY_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_1_TIMEPARAGRANULARITY_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG1_1_TIMEPARAGRANULARITY_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG1_1_MUXADDDATA_MASK                      (0x00000300U)
#define CSL_GPMC_CONFIG1_1_MUXADDDATA_SHIFT                     (8U)
#define CSL_GPMC_CONFIG1_1_MUXADDDATA_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_1_MUXADDDATA_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_1_MUXADDDATA_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_1_MUXADDDATA_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_1_MUXADDDATA_EN_0X0                    (0x00000000U)

#define CSL_GPMC_CONFIG1_1_DEVICETYPE_MASK                      (0x00000C00U)
#define CSL_GPMC_CONFIG1_1_DEVICETYPE_SHIFT                     (10U)
#define CSL_GPMC_CONFIG1_1_DEVICETYPE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_1_DEVICETYPE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_1_DEVICETYPE_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_1_DEVICETYPE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_1_DEVICETYPE_EN_0X2                    (0x00000002U)

#define CSL_GPMC_CONFIG1_1_DEVICESIZE_MASK                      (0x00003000U)
#define CSL_GPMC_CONFIG1_1_DEVICESIZE_SHIFT                     (12U)
#define CSL_GPMC_CONFIG1_1_DEVICESIZE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_1_DEVICESIZE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_1_DEVICESIZE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_1_DEVICESIZE_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_1_DEVICESIZE_EN_0X3                    (0x00000003U)

#define CSL_GPMC_CONFIG1_1_WAITPINSELECT_MASK                   (0x00030000U)
#define CSL_GPMC_CONFIG1_1_WAITPINSELECT_SHIFT                  (16U)
#define CSL_GPMC_CONFIG1_1_WAITPINSELECT_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WAITPINSELECT_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WAITPINSELECT_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG1_1_WAITPINSELECT_EN_0X2                 (0x00000002U)
#define CSL_GPMC_CONFIG1_1_WAITPINSELECT_EN_0X3                 (0x00000003U)

#define CSL_GPMC_CONFIG1_1_WAITMONITORINGTIME_MASK              (0x000C0000U)
#define CSL_GPMC_CONFIG1_1_WAITMONITORINGTIME_SHIFT             (18U)
#define CSL_GPMC_CONFIG1_1_WAITMONITORINGTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WAITMONITORINGTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG1_1_WAITMONITORINGTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WAITMONITORINGTIME_EN_0X3            (0x00000003U)
#define CSL_GPMC_CONFIG1_1_WAITMONITORINGTIME_EN_0X2            (0x00000002U)

#define CSL_GPMC_CONFIG1_1_WAITWRITEMONITORING_MASK             (0x00200000U)
#define CSL_GPMC_CONFIG1_1_WAITWRITEMONITORING_SHIFT            (21U)
#define CSL_GPMC_CONFIG1_1_WAITWRITEMONITORING_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WAITWRITEMONITORING_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG1_1_WAITWRITEMONITORING_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG1_1_WAITREADMONITORING_MASK              (0x00400000U)
#define CSL_GPMC_CONFIG1_1_WAITREADMONITORING_SHIFT             (22U)
#define CSL_GPMC_CONFIG1_1_WAITREADMONITORING_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WAITREADMONITORING_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WAITREADMONITORING_EN_0X1            (0x00000001U)

#define CSL_GPMC_CONFIG1_1_ATTACHEDDEVICEPAGELENGTH_MASK        (0x01800000U)
#define CSL_GPMC_CONFIG1_1_ATTACHEDDEVICEPAGELENGTH_SHIFT       (23U)
#define CSL_GPMC_CONFIG1_1_ATTACHEDDEVICEPAGELENGTH_RESETVAL    (0x00000000U)
#define CSL_GPMC_CONFIG1_1_ATTACHEDDEVICEPAGELENGTH_EN_0X1      (0x00000001U)
#define CSL_GPMC_CONFIG1_1_ATTACHEDDEVICEPAGELENGTH_EN_0X2      (0x00000002U)
#define CSL_GPMC_CONFIG1_1_ATTACHEDDEVICEPAGELENGTH_EN_0X3      (0x00000003U)
#define CSL_GPMC_CONFIG1_1_ATTACHEDDEVICEPAGELENGTH_EN_0X0      (0x00000000U)

#define CSL_GPMC_CONFIG1_1_CLKACTIVATIONTIME_MASK               (0x06000000U)
#define CSL_GPMC_CONFIG1_1_CLKACTIVATIONTIME_SHIFT              (25U)
#define CSL_GPMC_CONFIG1_1_CLKACTIVATIONTIME_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG1_1_CLKACTIVATIONTIME_EN_0X0             (0x00000000U)
#define CSL_GPMC_CONFIG1_1_CLKACTIVATIONTIME_EN_0X2             (0x00000002U)
#define CSL_GPMC_CONFIG1_1_CLKACTIVATIONTIME_EN_0X3             (0x00000003U)
#define CSL_GPMC_CONFIG1_1_CLKACTIVATIONTIME_EN_0X1             (0x00000001U)

#define CSL_GPMC_CONFIG1_1_WRITETYPE_MASK                       (0x08000000U)
#define CSL_GPMC_CONFIG1_1_WRITETYPE_SHIFT                      (27U)
#define CSL_GPMC_CONFIG1_1_WRITETYPE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WRITETYPE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WRITETYPE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_1_WRITEMULTIPLE_MASK                   (0x10000000U)
#define CSL_GPMC_CONFIG1_1_WRITEMULTIPLE_SHIFT                  (28U)
#define CSL_GPMC_CONFIG1_1_WRITEMULTIPLE_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WRITEMULTIPLE_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WRITEMULTIPLE_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG1_1_READTYPE_MASK                        (0x20000000U)
#define CSL_GPMC_CONFIG1_1_READTYPE_SHIFT                       (29U)
#define CSL_GPMC_CONFIG1_1_READTYPE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG1_1_READTYPE_EN_0X1                      (0x00000001U)
#define CSL_GPMC_CONFIG1_1_READTYPE_EN_0X0                      (0x00000000U)

#define CSL_GPMC_CONFIG1_1_READMULTIPLE_MASK                    (0x40000000U)
#define CSL_GPMC_CONFIG1_1_READMULTIPLE_SHIFT                   (30U)
#define CSL_GPMC_CONFIG1_1_READMULTIPLE_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG1_1_READMULTIPLE_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG1_1_READMULTIPLE_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG1_1_WRAPBURST_MASK                       (0x80000000U)
#define CSL_GPMC_CONFIG1_1_WRAPBURST_SHIFT                      (31U)
#define CSL_GPMC_CONFIG1_1_WRAPBURST_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WRAPBURST_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_1_WRAPBURST_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_1_RESETVAL                             (0x00000000U)

/* CONFIG */

#define CSL_GPMC_CONFIG_NANDFORCEPOSTEDWRITE_MASK               (0x00000001U)
#define CSL_GPMC_CONFIG_NANDFORCEPOSTEDWRITE_SHIFT              (0U)
#define CSL_GPMC_CONFIG_NANDFORCEPOSTEDWRITE_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG_NANDFORCEPOSTEDWRITE_EN_0X1             (0x00000001U)
#define CSL_GPMC_CONFIG_NANDFORCEPOSTEDWRITE_EN_0X0             (0x00000000U)

#define CSL_GPMC_CONFIG_LIMITEDADDR_MASK                        (0x00000002U)
#define CSL_GPMC_CONFIG_LIMITEDADDR_SHIFT                       (1U)
#define CSL_GPMC_CONFIG_LIMITEDADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG_LIMITEDADDR_EN_0X0                      (0x00000000U)
#define CSL_GPMC_CONFIG_LIMITEDADDR_EN_0X1                      (0x00000001U)

#define CSL_GPMC_CONFIG_WRITEPROTECT_MASK                       (0x00000010U)
#define CSL_GPMC_CONFIG_WRITEPROTECT_SHIFT                      (4U)
#define CSL_GPMC_CONFIG_WRITEPROTECT_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG_WRITEPROTECT_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG_WRITEPROTECT_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG_WAIT0PINPOLARITY_MASK                   (0x00000100U)
#define CSL_GPMC_CONFIG_WAIT0PINPOLARITY_SHIFT                  (8U)
#define CSL_GPMC_CONFIG_WAIT0PINPOLARITY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG_WAIT0PINPOLARITY_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG_WAIT0PINPOLARITY_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG_WAIT1PINPOLARITY_MASK                   (0x00000200U)
#define CSL_GPMC_CONFIG_WAIT1PINPOLARITY_SHIFT                  (9U)
#define CSL_GPMC_CONFIG_WAIT1PINPOLARITY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG_WAIT1PINPOLARITY_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG_WAIT1PINPOLARITY_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG_RESETVAL                                (0x00000000U)

/* ECC_CONFIG */

#define CSL_GPMC_ECC_CONFIG_ECCEN_MASK                          (0x00000001U)
#define CSL_GPMC_ECC_CONFIG_ECCEN_SHIFT                         (0U)
#define CSL_GPMC_ECC_CONFIG_ECCEN_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCEN_EN_0X0                        (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCEN_EN_0X1                        (0x00000001U)

#define CSL_GPMC_ECC_CONFIG_ECCCS_MASK                          (0x0000000EU)
#define CSL_GPMC_ECC_CONFIG_ECCCS_SHIFT                         (1U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X5                        (0x00000005U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X1                        (0x00000001U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X0                        (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X6                        (0x00000006U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X7                        (0x00000007U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X2                        (0x00000002U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X4                        (0x00000004U)
#define CSL_GPMC_ECC_CONFIG_ECCCS_EN_0X3                        (0x00000003U)

#define CSL_GPMC_ECC_CONFIG_ECCTOPSECTOR_MASK                   (0x00000070U)
#define CSL_GPMC_ECC_CONFIG_ECCTOPSECTOR_SHIFT                  (4U)
#define CSL_GPMC_ECC_CONFIG_ECCTOPSECTOR_RESETVAL               (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCTOPSECTOR_EN_0X7                 (0x00000007U)
#define CSL_GPMC_ECC_CONFIG_ECCTOPSECTOR_EN_0X0                 (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCTOPSECTOR_EN_0X3                 (0x00000003U)
#define CSL_GPMC_ECC_CONFIG_ECCTOPSECTOR_EN_0X1                 (0x00000001U)

#define CSL_GPMC_ECC_CONFIG_ECC16B_MASK                         (0x00000080U)
#define CSL_GPMC_ECC_CONFIG_ECC16B_SHIFT                        (7U)
#define CSL_GPMC_ECC_CONFIG_ECC16B_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECC16B_EN_0X1                       (0x00000001U)
#define CSL_GPMC_ECC_CONFIG_ECC16B_EN_0X0                       (0x00000000U)

#define CSL_GPMC_ECC_CONFIG_ECCWRAPMODE_MASK                    (0x00000F00U)
#define CSL_GPMC_ECC_CONFIG_ECCWRAPMODE_SHIFT                   (8U)
#define CSL_GPMC_ECC_CONFIG_ECCWRAPMODE_RESETVAL                (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCWRAPMODE_MAX                     (0x0000000fU)

#define CSL_GPMC_ECC_CONFIG_ECCBCHTSEL_MASK                     (0x00003000U)
#define CSL_GPMC_ECC_CONFIG_ECCBCHTSEL_SHIFT                    (12U)
#define CSL_GPMC_ECC_CONFIG_ECCBCHTSEL_RESETVAL                 (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCBCHTSEL_EN_0X0                   (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCBCHTSEL_EN_0X1                   (0x00000001U)
#define CSL_GPMC_ECC_CONFIG_ECCBCHTSEL_EN_0X3                   (0x00000003U)
#define CSL_GPMC_ECC_CONFIG_ECCBCHTSEL_EN_0X2                   (0x00000002U)

#define CSL_GPMC_ECC_CONFIG_ECCALGORITHM_MASK                   (0x00010000U)
#define CSL_GPMC_ECC_CONFIG_ECCALGORITHM_SHIFT                  (16U)
#define CSL_GPMC_ECC_CONFIG_ECCALGORITHM_RESETVAL               (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCALGORITHM_EN_0X0                 (0x00000000U)
#define CSL_GPMC_ECC_CONFIG_ECCALGORITHM_EN_0X1                 (0x00000001U)

#define CSL_GPMC_ECC_CONFIG_RESETVAL                            (0x00000000U)

/* BCH_RESULT4_5 */

#define CSL_GPMC_BCH_RESULT4_5_BCH_RESULT4_5_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT4_5_BCH_RESULT4_5_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT4_5_BCH_RESULT4_5_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT4_5_BCH_RESULT4_5_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT4_5_RESETVAL                         (0x00000000U)

/* BCH_RESULT6_3 */

#define CSL_GPMC_BCH_RESULT6_3_BCH_RESULT6_3_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT6_3_BCH_RESULT6_3_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT6_3_BCH_RESULT6_3_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT6_3_BCH_RESULT6_3_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT6_3_RESETVAL                         (0x00000000U)

/* NAND_ADDR_3 */

#define CSL_GPMC_NAND_ADDR_3_GPMC_NAND_ADDR_3_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_ADDR_3_GPMC_NAND_ADDR_3_SHIFT             (0U)
#define CSL_GPMC_NAND_ADDR_3_GPMC_NAND_ADDR_3_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_ADDR_3_GPMC_NAND_ADDR_3_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_ADDR_3_RESETVAL                           (0x00000000U)

/* NAND_ADDR_1 */

#define CSL_GPMC_NAND_ADDR_1_GPMC_NAND_ADDR_1_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_ADDR_1_GPMC_NAND_ADDR_1_SHIFT             (0U)
#define CSL_GPMC_NAND_ADDR_1_GPMC_NAND_ADDR_1_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_ADDR_1_GPMC_NAND_ADDR_1_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_ADDR_1_RESETVAL                           (0x00000000U)

/* NAND_DATA_1 */

#define CSL_GPMC_NAND_DATA_1_GPMC_NAND_DATA_1_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_DATA_1_GPMC_NAND_DATA_1_SHIFT             (0U)
#define CSL_GPMC_NAND_DATA_1_GPMC_NAND_DATA_1_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_DATA_1_GPMC_NAND_DATA_1_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_DATA_1_RESETVAL                           (0x00000000U)

/* CONFIG7_0 */

#define CSL_GPMC_CONFIG7_0_BASEADDR_MASK                        (0x0000003FU)
#define CSL_GPMC_CONFIG7_0_BASEADDR_SHIFT                       (0U)
#define CSL_GPMC_CONFIG7_0_BASEADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_0_BASEADDR_MAX                         (0x0000003fU)

#define CSL_GPMC_CONFIG7_0_CSVALID_MASK                         (0x00000040U)
#define CSL_GPMC_CONFIG7_0_CSVALID_SHIFT                        (6U)
#define CSL_GPMC_CONFIG7_0_CSVALID_RESETVAL                     (0x00000000U)
#define CSL_GPMC_CONFIG7_0_CSVALID_EN_0X0                       (0x00000000U)
#define CSL_GPMC_CONFIG7_0_CSVALID_EN_0X1                       (0x00000001U)

#define CSL_GPMC_CONFIG7_0_MASKADDR_MASK                        (0x00000F00U)
#define CSL_GPMC_CONFIG7_0_MASKADDR_SHIFT                       (8U)
#define CSL_GPMC_CONFIG7_0_MASKADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_0_MASKADDR_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG7_0_RESETVAL                             (0x00000000U)

/* CONFIG4_6 */

#define CSL_GPMC_CONFIG4_6_OEONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG4_6_OEONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG4_6_OEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_6_OEAADMUXONTIME_MASK                  (0x00000070U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXONTIME_SHIFT                 (4U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXONTIME_RESETVAL              (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXONTIME_EN_0X0                (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXONTIME_EN_0X1                (0x00000001U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXONTIME_EN_0X7                (0x00000007U)

#define CSL_GPMC_CONFIG4_6_OEEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG4_6_OEEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG4_6_OEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG4_6_OEOFFTIME_MASK                       (0x00001F00U)
#define CSL_GPMC_CONFIG4_6_OEOFFTIME_SHIFT                      (8U)
#define CSL_GPMC_CONFIG4_6_OEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_6_OEAADMUXOFFTIME_MASK                 (0x0000E000U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXOFFTIME_SHIFT                (13U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXOFFTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXOFFTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXOFFTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG4_6_OEAADMUXOFFTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG4_6_WEONTIME_MASK                        (0x000F0000U)
#define CSL_GPMC_CONFIG4_6_WEONTIME_SHIFT                       (16U)
#define CSL_GPMC_CONFIG4_6_WEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_6_WEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_6_WEEXTRADELAY_MASK                    (0x00800000U)
#define CSL_GPMC_CONFIG4_6_WEEXTRADELAY_SHIFT                   (23U)
#define CSL_GPMC_CONFIG4_6_WEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_6_WEEXTRADELAY_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG4_6_WEEXTRADELAY_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG4_6_WEOFFTIME_MASK                       (0x1F000000U)
#define CSL_GPMC_CONFIG4_6_WEOFFTIME_SHIFT                      (24U)
#define CSL_GPMC_CONFIG4_6_WEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_6_WEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_6_RESETVAL                             (0x00000000U)

/* BCH_RESULT5_2 */

#define CSL_GPMC_BCH_RESULT5_2_BCH_RESULT5_2_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT5_2_BCH_RESULT5_2_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT5_2_BCH_RESULT5_2_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT5_2_BCH_RESULT5_2_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT5_2_RESETVAL                         (0x00000000U)

/* CONFIG3_5 */

#define CSL_GPMC_CONFIG3_5_ADVONTIME_MASK                       (0x0000000FU)
#define CSL_GPMC_CONFIG3_5_ADVONTIME_SHIFT                      (0U)
#define CSL_GPMC_CONFIG3_5_ADVONTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVONTIME_MAX                        (0x0000000fU)

#define CSL_GPMC_CONFIG3_5_ADVAADMUXONTIME_MASK                 (0x00000070U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXONTIME_SHIFT                (4U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXONTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXONTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXONTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXONTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG3_5_ADVEXTRADELAY_MASK                   (0x00000080U)
#define CSL_GPMC_CONFIG3_5_ADVEXTRADELAY_SHIFT                  (7U)
#define CSL_GPMC_CONFIG3_5_ADVEXTRADELAY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVEXTRADELAY_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG3_5_ADVEXTRADELAY_EN_0X0                 (0x00000000U)

#define CSL_GPMC_CONFIG3_5_ADVRDOFFTIME_MASK                    (0x00001F00U)
#define CSL_GPMC_CONFIG3_5_ADVRDOFFTIME_SHIFT                   (8U)
#define CSL_GPMC_CONFIG3_5_ADVRDOFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVRDOFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_5_ADVWROFFTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG3_5_ADVWROFFTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG3_5_ADVWROFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVWROFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_5_ADVAADMUXRDOFFTIME_MASK              (0x07000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXRDOFFTIME_SHIFT             (24U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXRDOFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXRDOFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXRDOFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXRDOFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_5_ADVAADMUXWROFFTIME_MASK              (0x70000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXWROFFTIME_SHIFT             (28U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXWROFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXWROFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXWROFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_5_ADVAADMUXWROFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_5_RESETVAL                             (0x00000000U)

/* CONFIG5_1 */

#define CSL_GPMC_CONFIG5_1_RDCYCLETIME_MASK                     (0x0000001FU)
#define CSL_GPMC_CONFIG5_1_RDCYCLETIME_SHIFT                    (0U)
#define CSL_GPMC_CONFIG5_1_RDCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_1_RDCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_1_WRCYCLETIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG5_1_WRCYCLETIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG5_1_WRCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_1_WRCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_1_RDACCESSTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG5_1_RDACCESSTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG5_1_RDACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG5_1_RDACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG5_1_PAGEBURSTACCESSTIME_MASK             (0x0F000000U)
#define CSL_GPMC_CONFIG5_1_PAGEBURSTACCESSTIME_SHIFT            (24U)
#define CSL_GPMC_CONFIG5_1_PAGEBURSTACCESSTIME_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG5_1_PAGEBURSTACCESSTIME_MAX              (0x0000000fU)

#define CSL_GPMC_CONFIG5_1_RESETVAL                             (0x00000000U)

/* NAND_COMMAND_4 */

#define CSL_GPMC_NAND_COMMAND_4_GPMC_NAND_COMMAND_4_MASK        (0xFFFFFFFFU)
#define CSL_GPMC_NAND_COMMAND_4_GPMC_NAND_COMMAND_4_SHIFT       (0U)
#define CSL_GPMC_NAND_COMMAND_4_GPMC_NAND_COMMAND_4_RESETVAL    (0x00000000U)
#define CSL_GPMC_NAND_COMMAND_4_GPMC_NAND_COMMAND_4_MAX         (0xffffffffU)

#define CSL_GPMC_NAND_COMMAND_4_RESETVAL                        (0x00000000U)

/* BCH_RESULT3_6 */

#define CSL_GPMC_BCH_RESULT3_6_BCH_RESULT3_6_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT3_6_BCH_RESULT3_6_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT3_6_BCH_RESULT3_6_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT3_6_BCH_RESULT3_6_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT3_6_RESETVAL                         (0x00000000U)

/* NAND_DATA_0 */

#define CSL_GPMC_NAND_DATA_0_GPMC_NAND_DATA_0_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_DATA_0_GPMC_NAND_DATA_0_SHIFT             (0U)
#define CSL_GPMC_NAND_DATA_0_GPMC_NAND_DATA_0_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_DATA_0_GPMC_NAND_DATA_0_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_DATA_0_RESETVAL                           (0x00000000U)

/* BCH_RESULT4_1 */

#define CSL_GPMC_BCH_RESULT4_1_BCH_RESULT4_1_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT4_1_BCH_RESULT4_1_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT4_1_BCH_RESULT4_1_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT4_1_BCH_RESULT4_1_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT4_1_RESETVAL                         (0x00000000U)

/* BCH_RESULT6_1 */

#define CSL_GPMC_BCH_RESULT6_1_BCH_RESULT6_1_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT6_1_BCH_RESULT6_1_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT6_1_BCH_RESULT6_1_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT6_1_BCH_RESULT6_1_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT6_1_RESETVAL                         (0x00000000U)

/* PREFETCH_CTRL */

#define CSL_GPMC_PREFETCH_CTRL_STARTENGINE_MASK                 (0x00000001U)
#define CSL_GPMC_PREFETCH_CTRL_STARTENGINE_SHIFT                (0U)
#define CSL_GPMC_PREFETCH_CTRL_STARTENGINE_RESETVAL             (0x00000000U)
#define CSL_GPMC_PREFETCH_CTRL_STARTENGINE_EN_0X0W              (0x00000000U)
#define CSL_GPMC_PREFETCH_CTRL_STARTENGINE_EN_0X0R              (0x00000000U)
#define CSL_GPMC_PREFETCH_CTRL_STARTENGINE_EN_0X1R              (0x00000001U)
#define CSL_GPMC_PREFETCH_CTRL_STARTENGINE_EN_0X1W              (0x00000001U)

#define CSL_GPMC_PREFETCH_CTRL_RESETVAL                         (0x00000000U)

/* ECC2_RESULT */

#define CSL_GPMC_ECC2_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC2_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC2_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC2_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC2_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC2_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC2_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC2_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC2_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC2_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC2_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC2_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC2_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC2_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC2_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC2_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC2_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC2_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC2_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC2_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC2_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC2_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC2_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC2_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC2_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC2_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC2_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC2_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC2_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC2_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC2_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC2_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC2_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC2_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC2_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC2_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC2_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC2_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC2_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC2_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC2_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC2_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC2_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC2_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC2_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC2_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC2_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC2_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC2_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC2_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC2_RESULT_RESETVAL                           (0x00000000U)

/* BCH_RESULT6_4 */

#define CSL_GPMC_BCH_RESULT6_4_BCH_RESULT6_4_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT6_4_BCH_RESULT6_4_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT6_4_BCH_RESULT6_4_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT6_4_BCH_RESULT6_4_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT6_4_RESETVAL                         (0x00000000U)

/* CONFIG5_5 */

#define CSL_GPMC_CONFIG5_5_RDCYCLETIME_MASK                     (0x0000001FU)
#define CSL_GPMC_CONFIG5_5_RDCYCLETIME_SHIFT                    (0U)
#define CSL_GPMC_CONFIG5_5_RDCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_5_RDCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_5_WRCYCLETIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG5_5_WRCYCLETIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG5_5_WRCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_5_WRCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_5_RDACCESSTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG5_5_RDACCESSTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG5_5_RDACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG5_5_RDACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG5_5_PAGEBURSTACCESSTIME_MASK             (0x0F000000U)
#define CSL_GPMC_CONFIG5_5_PAGEBURSTACCESSTIME_SHIFT            (24U)
#define CSL_GPMC_CONFIG5_5_PAGEBURSTACCESSTIME_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG5_5_PAGEBURSTACCESSTIME_MAX              (0x0000000fU)

#define CSL_GPMC_CONFIG5_5_RESETVAL                             (0x00000000U)

/* BCH_RESULT0_4 */

#define CSL_GPMC_BCH_RESULT0_4_BCH_RESULT0_4_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT0_4_BCH_RESULT0_4_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT0_4_BCH_RESULT0_4_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT0_4_BCH_RESULT0_4_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT0_4_RESETVAL                         (0x00000000U)

/* CONFIG3_4 */

#define CSL_GPMC_CONFIG3_4_ADVONTIME_MASK                       (0x0000000FU)
#define CSL_GPMC_CONFIG3_4_ADVONTIME_SHIFT                      (0U)
#define CSL_GPMC_CONFIG3_4_ADVONTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVONTIME_MAX                        (0x0000000fU)

#define CSL_GPMC_CONFIG3_4_ADVAADMUXONTIME_MASK                 (0x00000070U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXONTIME_SHIFT                (4U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXONTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXONTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXONTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXONTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG3_4_ADVEXTRADELAY_MASK                   (0x00000080U)
#define CSL_GPMC_CONFIG3_4_ADVEXTRADELAY_SHIFT                  (7U)
#define CSL_GPMC_CONFIG3_4_ADVEXTRADELAY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVEXTRADELAY_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG3_4_ADVEXTRADELAY_EN_0X0                 (0x00000000U)

#define CSL_GPMC_CONFIG3_4_ADVRDOFFTIME_MASK                    (0x00001F00U)
#define CSL_GPMC_CONFIG3_4_ADVRDOFFTIME_SHIFT                   (8U)
#define CSL_GPMC_CONFIG3_4_ADVRDOFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVRDOFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_4_ADVWROFFTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG3_4_ADVWROFFTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG3_4_ADVWROFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVWROFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_4_ADVAADMUXRDOFFTIME_MASK              (0x07000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXRDOFFTIME_SHIFT             (24U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXRDOFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXRDOFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXRDOFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXRDOFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_4_ADVAADMUXWROFFTIME_MASK              (0x70000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXWROFFTIME_SHIFT             (28U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXWROFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXWROFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXWROFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_4_ADVAADMUXWROFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_4_RESETVAL                             (0x00000000U)

/* CONFIG3_2 */

#define CSL_GPMC_CONFIG3_2_ADVONTIME_MASK                       (0x0000000FU)
#define CSL_GPMC_CONFIG3_2_ADVONTIME_SHIFT                      (0U)
#define CSL_GPMC_CONFIG3_2_ADVONTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVONTIME_MAX                        (0x0000000fU)

#define CSL_GPMC_CONFIG3_2_ADVAADMUXONTIME_MASK                 (0x00000070U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXONTIME_SHIFT                (4U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXONTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXONTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXONTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXONTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG3_2_ADVEXTRADELAY_MASK                   (0x00000080U)
#define CSL_GPMC_CONFIG3_2_ADVEXTRADELAY_SHIFT                  (7U)
#define CSL_GPMC_CONFIG3_2_ADVEXTRADELAY_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVEXTRADELAY_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG3_2_ADVEXTRADELAY_EN_0X0                 (0x00000000U)

#define CSL_GPMC_CONFIG3_2_ADVRDOFFTIME_MASK                    (0x00001F00U)
#define CSL_GPMC_CONFIG3_2_ADVRDOFFTIME_SHIFT                   (8U)
#define CSL_GPMC_CONFIG3_2_ADVRDOFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVRDOFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_2_ADVWROFFTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG3_2_ADVWROFFTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG3_2_ADVWROFFTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVWROFFTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG3_2_ADVAADMUXRDOFFTIME_MASK              (0x07000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXRDOFFTIME_SHIFT             (24U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXRDOFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXRDOFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXRDOFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXRDOFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_2_ADVAADMUXWROFFTIME_MASK              (0x70000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXWROFFTIME_SHIFT             (28U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXWROFFTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXWROFFTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXWROFFTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG3_2_ADVAADMUXWROFFTIME_EN_0X7            (0x00000007U)

#define CSL_GPMC_CONFIG3_2_RESETVAL                             (0x00000000U)

/* BCH_RESULT1_6 */

#define CSL_GPMC_BCH_RESULT1_6_BCH_RESULT1_6_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT1_6_BCH_RESULT1_6_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT1_6_BCH_RESULT1_6_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT1_6_BCH_RESULT1_6_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT1_6_RESETVAL                         (0x00000000U)

/* BCH_RESULT3_0 */

#define CSL_GPMC_BCH_RESULT3_0_BCH_RESULT3_0_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT3_0_BCH_RESULT3_0_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT3_0_BCH_RESULT3_0_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT3_0_BCH_RESULT3_0_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT3_0_RESETVAL                         (0x00000000U)

/* BCH_RESULT0_2 */

#define CSL_GPMC_BCH_RESULT0_2_BCH_RESULT0_2_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT0_2_BCH_RESULT0_2_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT0_2_BCH_RESULT0_2_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT0_2_BCH_RESULT0_2_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT0_2_RESETVAL                         (0x00000000U)

/* NAND_COMMAND_2 */

#define CSL_GPMC_NAND_COMMAND_2_GPMC_NAND_COMMAND_2_MASK        (0xFFFFFFFFU)
#define CSL_GPMC_NAND_COMMAND_2_GPMC_NAND_COMMAND_2_SHIFT       (0U)
#define CSL_GPMC_NAND_COMMAND_2_GPMC_NAND_COMMAND_2_RESETVAL    (0x00000000U)
#define CSL_GPMC_NAND_COMMAND_2_GPMC_NAND_COMMAND_2_MAX         (0xffffffffU)

#define CSL_GPMC_NAND_COMMAND_2_RESETVAL                        (0x00000000U)

/* PREFETCH_CONFIG1 */

#define CSL_GPMC_PREFETCH_CONFIG1_ACCESSMODE_MASK               (0x00000001U)
#define CSL_GPMC_PREFETCH_CONFIG1_ACCESSMODE_SHIFT              (0U)
#define CSL_GPMC_PREFETCH_CONFIG1_ACCESSMODE_RESETVAL           (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ACCESSMODE_EN_0X0             (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ACCESSMODE_EN_0X1             (0x00000001U)

#define CSL_GPMC_PREFETCH_CONFIG1_DMAMODE_MASK                  (0x00000004U)
#define CSL_GPMC_PREFETCH_CONFIG1_DMAMODE_SHIFT                 (2U)
#define CSL_GPMC_PREFETCH_CONFIG1_DMAMODE_RESETVAL              (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_DMAMODE_EN_0X1                (0x00000001U)
#define CSL_GPMC_PREFETCH_CONFIG1_DMAMODE_EN_0X0                (0x00000000U)

#define CSL_GPMC_PREFETCH_CONFIG1_SYNCHROMODE_MASK              (0x00000008U)
#define CSL_GPMC_PREFETCH_CONFIG1_SYNCHROMODE_SHIFT             (3U)
#define CSL_GPMC_PREFETCH_CONFIG1_SYNCHROMODE_RESETVAL          (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_SYNCHROMODE_EN_0X0            (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_SYNCHROMODE_EN_0X1            (0x00000001U)

#define CSL_GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_MASK          (0x00000030U)
#define CSL_GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_SHIFT         (4U)
#define CSL_GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_RESETVAL      (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_EN_0X1        (0x00000001U)
#define CSL_GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_EN_0X2        (0x00000002U)
#define CSL_GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_EN_0X3        (0x00000003U)
#define CSL_GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_EN_0X0        (0x00000000U)

#define CSL_GPMC_PREFETCH_CONFIG1_ENENGINE_MASK                 (0x00000080U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENENGINE_SHIFT                (7U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENENGINE_RESETVAL             (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENENGINE_EN_0X0               (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENENGINE_EN_0X1               (0x00000001U)

#define CSL_GPMC_PREFETCH_CONFIG1_FIFOTHR_MASK                  (0x00007F00U)
#define CSL_GPMC_PREFETCH_CONFIG1_FIFOTHR_SHIFT                 (8U)
#define CSL_GPMC_PREFETCH_CONFIG1_FIFOTHR_RESETVAL              (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_FIFOTHR_MAX                   (0x0000007fU)

#define CSL_GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_MASK         (0x000F0000U)
#define CSL_GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_SHIFT        (16U)
#define CSL_GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_RESETVAL     (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_MAX          (0x0000000fU)

#define CSL_GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_MASK         (0x00800000U)
#define CSL_GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_SHIFT        (23U)
#define CSL_GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_RESETVAL     (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_EN_0X1       (0x00000001U)
#define CSL_GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_EN_0X0       (0x00000000U)

#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_MASK         (0x07000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_SHIFT        (24U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_RESETVAL     (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X6       (0x00000006U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X5       (0x00000005U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X1       (0x00000001U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X4       (0x00000004U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X3       (0x00000003U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X0       (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X2       (0x00000002U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_EN_0X7       (0x00000007U)

#define CSL_GPMC_PREFETCH_CONFIG1_ENOPTIMIZEDACCESS_MASK        (0x08000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENOPTIMIZEDACCESS_SHIFT       (27U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENOPTIMIZEDACCESS_RESETVAL    (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENOPTIMIZEDACCESS_EN_0X1      (0x00000001U)
#define CSL_GPMC_PREFETCH_CONFIG1_ENOPTIMIZEDACCESS_EN_0X0      (0x00000000U)

#define CSL_GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_MASK        (0x70000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_SHIFT       (28U)
#define CSL_GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_RESETVAL    (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_EN_0X0      (0x00000000U)
#define CSL_GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_EN_0X1      (0x00000001U)
#define CSL_GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_EN_0X7      (0x00000007U)

#define CSL_GPMC_PREFETCH_CONFIG1_RESETVAL                      (0x00000000U)

/* ECC5_RESULT */

#define CSL_GPMC_ECC5_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC5_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC5_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC5_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC5_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC5_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC5_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC5_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC5_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC5_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC5_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC5_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC5_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC5_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC5_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC5_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC5_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC5_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC5_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC5_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC5_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC5_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC5_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC5_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC5_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC5_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC5_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC5_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC5_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC5_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC5_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC5_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC5_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC5_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC5_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC5_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC5_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC5_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC5_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC5_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC5_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC5_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC5_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC5_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC5_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC5_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC5_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC5_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC5_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC5_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC5_RESULT_RESETVAL                           (0x00000000U)

/* BCH_RESULT3_2 */

#define CSL_GPMC_BCH_RESULT3_2_BCH_RESULT3_2_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT3_2_BCH_RESULT3_2_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT3_2_BCH_RESULT3_2_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT3_2_BCH_RESULT3_2_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT3_2_RESETVAL                         (0x00000000U)

/* BCH_RESULT4_3 */

#define CSL_GPMC_BCH_RESULT4_3_BCH_RESULT4_3_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT4_3_BCH_RESULT4_3_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT4_3_BCH_RESULT4_3_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT4_3_BCH_RESULT4_3_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT4_3_RESETVAL                         (0x00000000U)

/* BCH_RESULT1_4 */

#define CSL_GPMC_BCH_RESULT1_4_BCH_RESULT1_4_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT1_4_BCH_RESULT1_4_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT1_4_BCH_RESULT1_4_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT1_4_BCH_RESULT1_4_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT1_4_RESETVAL                         (0x00000000U)

/* BCH_RESULT2_4 */

#define CSL_GPMC_BCH_RESULT2_4_BCH_RESULT2_4_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT2_4_BCH_RESULT2_4_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT2_4_BCH_RESULT2_4_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT2_4_BCH_RESULT2_4_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT2_4_RESETVAL                         (0x00000000U)

/* BCH_RESULT3_4 */

#define CSL_GPMC_BCH_RESULT3_4_BCH_RESULT3_4_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT3_4_BCH_RESULT3_4_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT3_4_BCH_RESULT3_4_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT3_4_BCH_RESULT3_4_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT3_4_RESETVAL                         (0x00000000U)

/* CONFIG6_2 */

#define CSL_GPMC_CONFIG6_2_BUSTURNAROUND_MASK                   (0x0000000FU)
#define CSL_GPMC_CONFIG6_2_BUSTURNAROUND_SHIFT                  (0U)
#define CSL_GPMC_CONFIG6_2_BUSTURNAROUND_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG6_2_BUSTURNAROUND_MAX                    (0x0000000fU)

#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDIFFCSEN_MASK             (0x00000040U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDIFFCSEN_SHIFT            (6U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDIFFCSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDIFFCSEN_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDIFFCSEN_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLESAMECSEN_MASK             (0x00000080U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLESAMECSEN_SHIFT            (7U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLESAMECSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLESAMECSEN_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLESAMECSEN_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDELAY_MASK                (0x00000F00U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDELAY_SHIFT               (8U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDELAY_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_2_CYCLE2CYCLEDELAY_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_2_WRDATAONADMUXBUS_MASK                (0x000F0000U)
#define CSL_GPMC_CONFIG6_2_WRDATAONADMUXBUS_SHIFT               (16U)
#define CSL_GPMC_CONFIG6_2_WRDATAONADMUXBUS_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_2_WRDATAONADMUXBUS_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_2_WRACCESSTIME_MASK                    (0x1F000000U)
#define CSL_GPMC_CONFIG6_2_WRACCESSTIME_SHIFT                   (24U)
#define CSL_GPMC_CONFIG6_2_WRACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG6_2_WRACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG6_2_RESETVAL                             (0x00000000U)

/* BCH_RESULT2_3 */

#define CSL_GPMC_BCH_RESULT2_3_BCH_RESULT2_3_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT2_3_BCH_RESULT2_3_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT2_3_BCH_RESULT2_3_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT2_3_BCH_RESULT2_3_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT2_3_RESETVAL                         (0x00000000U)

/* ECC4_RESULT */

#define CSL_GPMC_ECC4_RESULT_P1E_MASK                           (0x00000001U)
#define CSL_GPMC_ECC4_RESULT_P1E_SHIFT                          (0U)
#define CSL_GPMC_ECC4_RESULT_P1E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P1E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P2E_MASK                           (0x00000002U)
#define CSL_GPMC_ECC4_RESULT_P2E_SHIFT                          (1U)
#define CSL_GPMC_ECC4_RESULT_P2E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P2E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P4E_MASK                           (0x00000004U)
#define CSL_GPMC_ECC4_RESULT_P4E_SHIFT                          (2U)
#define CSL_GPMC_ECC4_RESULT_P4E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P4E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P8E_MASK                           (0x00000008U)
#define CSL_GPMC_ECC4_RESULT_P8E_SHIFT                          (3U)
#define CSL_GPMC_ECC4_RESULT_P8E_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P8E_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P16E_MASK                          (0x00000010U)
#define CSL_GPMC_ECC4_RESULT_P16E_SHIFT                         (4U)
#define CSL_GPMC_ECC4_RESULT_P16E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P16E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P32E_MASK                          (0x00000020U)
#define CSL_GPMC_ECC4_RESULT_P32E_SHIFT                         (5U)
#define CSL_GPMC_ECC4_RESULT_P32E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P32E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P64E_MASK                          (0x00000040U)
#define CSL_GPMC_ECC4_RESULT_P64E_SHIFT                         (6U)
#define CSL_GPMC_ECC4_RESULT_P64E_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P64E_MAX                           (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P128E_MASK                         (0x00000080U)
#define CSL_GPMC_ECC4_RESULT_P128E_SHIFT                        (7U)
#define CSL_GPMC_ECC4_RESULT_P128E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P128E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P256E_MASK                         (0x00000100U)
#define CSL_GPMC_ECC4_RESULT_P256E_SHIFT                        (8U)
#define CSL_GPMC_ECC4_RESULT_P256E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P256E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P512E_MASK                         (0x00000200U)
#define CSL_GPMC_ECC4_RESULT_P512E_SHIFT                        (9U)
#define CSL_GPMC_ECC4_RESULT_P512E_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P512E_MAX                          (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P1024E_MASK                        (0x00000400U)
#define CSL_GPMC_ECC4_RESULT_P1024E_SHIFT                       (10U)
#define CSL_GPMC_ECC4_RESULT_P1024E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P1024E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P2048E_MASK                        (0x00000800U)
#define CSL_GPMC_ECC4_RESULT_P2048E_SHIFT                       (11U)
#define CSL_GPMC_ECC4_RESULT_P2048E_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P2048E_MAX                         (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P1O_MASK                           (0x00010000U)
#define CSL_GPMC_ECC4_RESULT_P1O_SHIFT                          (16U)
#define CSL_GPMC_ECC4_RESULT_P1O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P1O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P2O_MASK                           (0x00020000U)
#define CSL_GPMC_ECC4_RESULT_P2O_SHIFT                          (17U)
#define CSL_GPMC_ECC4_RESULT_P2O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P2O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P4O_MASK                           (0x00040000U)
#define CSL_GPMC_ECC4_RESULT_P4O_SHIFT                          (18U)
#define CSL_GPMC_ECC4_RESULT_P4O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P4O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P8O_MASK                           (0x00080000U)
#define CSL_GPMC_ECC4_RESULT_P8O_SHIFT                          (19U)
#define CSL_GPMC_ECC4_RESULT_P8O_RESETVAL                       (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P8O_MAX                            (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P16O_MASK                          (0x00100000U)
#define CSL_GPMC_ECC4_RESULT_P16O_SHIFT                         (20U)
#define CSL_GPMC_ECC4_RESULT_P16O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P16O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P32O_MASK                          (0x00200000U)
#define CSL_GPMC_ECC4_RESULT_P32O_SHIFT                         (21U)
#define CSL_GPMC_ECC4_RESULT_P32O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P32O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P64O_MASK                          (0x00400000U)
#define CSL_GPMC_ECC4_RESULT_P64O_SHIFT                         (22U)
#define CSL_GPMC_ECC4_RESULT_P64O_RESETVAL                      (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P64O_MAX                           (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P128O_MASK                         (0x00800000U)
#define CSL_GPMC_ECC4_RESULT_P128O_SHIFT                        (23U)
#define CSL_GPMC_ECC4_RESULT_P128O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P128O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P256O_MASK                         (0x01000000U)
#define CSL_GPMC_ECC4_RESULT_P256O_SHIFT                        (24U)
#define CSL_GPMC_ECC4_RESULT_P256O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P256O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P512O_MASK                         (0x02000000U)
#define CSL_GPMC_ECC4_RESULT_P512O_SHIFT                        (25U)
#define CSL_GPMC_ECC4_RESULT_P512O_RESETVAL                     (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P512O_MAX                          (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P1024O_MASK                        (0x04000000U)
#define CSL_GPMC_ECC4_RESULT_P1024O_SHIFT                       (26U)
#define CSL_GPMC_ECC4_RESULT_P1024O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P1024O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_P2048O_MASK                        (0x08000000U)
#define CSL_GPMC_ECC4_RESULT_P2048O_SHIFT                       (27U)
#define CSL_GPMC_ECC4_RESULT_P2048O_RESETVAL                    (0x00000000U)
#define CSL_GPMC_ECC4_RESULT_P2048O_MAX                         (0x00000001U)

#define CSL_GPMC_ECC4_RESULT_RESETVAL                           (0x00000000U)

/* NAND_COMMAND_5 */

#define CSL_GPMC_NAND_COMMAND_5_GPMC_NAND_COMMAND_5_MASK        (0xFFFFFFFFU)
#define CSL_GPMC_NAND_COMMAND_5_GPMC_NAND_COMMAND_5_SHIFT       (0U)
#define CSL_GPMC_NAND_COMMAND_5_GPMC_NAND_COMMAND_5_RESETVAL    (0x00000000U)
#define CSL_GPMC_NAND_COMMAND_5_GPMC_NAND_COMMAND_5_MAX         (0xffffffffU)

#define CSL_GPMC_NAND_COMMAND_5_RESETVAL                        (0x00000000U)

/* BCH_RESULT2_6 */

#define CSL_GPMC_BCH_RESULT2_6_BCH_RESULT2_6_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT2_6_BCH_RESULT2_6_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT2_6_BCH_RESULT2_6_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT2_6_BCH_RESULT2_6_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT2_6_RESETVAL                         (0x00000000U)

/* CONFIG4_4 */

#define CSL_GPMC_CONFIG4_4_OEONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG4_4_OEONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG4_4_OEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_4_OEAADMUXONTIME_MASK                  (0x00000070U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXONTIME_SHIFT                 (4U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXONTIME_RESETVAL              (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXONTIME_EN_0X0                (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXONTIME_EN_0X1                (0x00000001U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXONTIME_EN_0X7                (0x00000007U)

#define CSL_GPMC_CONFIG4_4_OEEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG4_4_OEEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG4_4_OEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG4_4_OEOFFTIME_MASK                       (0x00001F00U)
#define CSL_GPMC_CONFIG4_4_OEOFFTIME_SHIFT                      (8U)
#define CSL_GPMC_CONFIG4_4_OEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_4_OEAADMUXOFFTIME_MASK                 (0x0000E000U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXOFFTIME_SHIFT                (13U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXOFFTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXOFFTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXOFFTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG4_4_OEAADMUXOFFTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG4_4_WEONTIME_MASK                        (0x000F0000U)
#define CSL_GPMC_CONFIG4_4_WEONTIME_SHIFT                       (16U)
#define CSL_GPMC_CONFIG4_4_WEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_4_WEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_4_WEEXTRADELAY_MASK                    (0x00800000U)
#define CSL_GPMC_CONFIG4_4_WEEXTRADELAY_SHIFT                   (23U)
#define CSL_GPMC_CONFIG4_4_WEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_4_WEEXTRADELAY_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG4_4_WEEXTRADELAY_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG4_4_WEOFFTIME_MASK                       (0x1F000000U)
#define CSL_GPMC_CONFIG4_4_WEOFFTIME_SHIFT                      (24U)
#define CSL_GPMC_CONFIG4_4_WEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_4_WEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_4_RESETVAL                             (0x00000000U)

/* NAND_ADDR_6 */

#define CSL_GPMC_NAND_ADDR_6_GPMC_NAND_ADDR_6_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_ADDR_6_GPMC_NAND_ADDR_6_SHIFT             (0U)
#define CSL_GPMC_NAND_ADDR_6_GPMC_NAND_ADDR_6_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_ADDR_6_GPMC_NAND_ADDR_6_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_ADDR_6_RESETVAL                           (0x00000000U)

/* CONFIG5_2 */

#define CSL_GPMC_CONFIG5_2_RDCYCLETIME_MASK                     (0x0000001FU)
#define CSL_GPMC_CONFIG5_2_RDCYCLETIME_SHIFT                    (0U)
#define CSL_GPMC_CONFIG5_2_RDCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_2_RDCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_2_WRCYCLETIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG5_2_WRCYCLETIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG5_2_WRCYCLETIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG5_2_WRCYCLETIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG5_2_RDACCESSTIME_MASK                    (0x001F0000U)
#define CSL_GPMC_CONFIG5_2_RDACCESSTIME_SHIFT                   (16U)
#define CSL_GPMC_CONFIG5_2_RDACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG5_2_RDACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG5_2_PAGEBURSTACCESSTIME_MASK             (0x0F000000U)
#define CSL_GPMC_CONFIG5_2_PAGEBURSTACCESSTIME_SHIFT            (24U)
#define CSL_GPMC_CONFIG5_2_PAGEBURSTACCESSTIME_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG5_2_PAGEBURSTACCESSTIME_MAX              (0x0000000fU)

#define CSL_GPMC_CONFIG5_2_RESETVAL                             (0x00000000U)

/* CONFIG6_6 */

#define CSL_GPMC_CONFIG6_6_BUSTURNAROUND_MASK                   (0x0000000FU)
#define CSL_GPMC_CONFIG6_6_BUSTURNAROUND_SHIFT                  (0U)
#define CSL_GPMC_CONFIG6_6_BUSTURNAROUND_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG6_6_BUSTURNAROUND_MAX                    (0x0000000fU)

#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDIFFCSEN_MASK             (0x00000040U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDIFFCSEN_SHIFT            (6U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDIFFCSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDIFFCSEN_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDIFFCSEN_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLESAMECSEN_MASK             (0x00000080U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLESAMECSEN_SHIFT            (7U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLESAMECSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLESAMECSEN_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLESAMECSEN_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDELAY_MASK                (0x00000F00U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDELAY_SHIFT               (8U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDELAY_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_6_CYCLE2CYCLEDELAY_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_6_WRDATAONADMUXBUS_MASK                (0x000F0000U)
#define CSL_GPMC_CONFIG6_6_WRDATAONADMUXBUS_SHIFT               (16U)
#define CSL_GPMC_CONFIG6_6_WRDATAONADMUXBUS_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_6_WRDATAONADMUXBUS_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_6_WRACCESSTIME_MASK                    (0x1F000000U)
#define CSL_GPMC_CONFIG6_6_WRACCESSTIME_SHIFT                   (24U)
#define CSL_GPMC_CONFIG6_6_WRACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG6_6_WRACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG6_6_RESETVAL                             (0x00000000U)

/* BCH_RESULT5_1 */

#define CSL_GPMC_BCH_RESULT5_1_BCH_RESULT5_1_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT5_1_BCH_RESULT5_1_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT5_1_BCH_RESULT5_1_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT5_1_BCH_RESULT5_1_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT5_1_RESETVAL                         (0x00000000U)

/* ERR_ADDR */

#define CSL_GPMC_ERR_ADDR_ILLEGALADD_MASK                       (0x7FFFFFFFU)
#define CSL_GPMC_ERR_ADDR_ILLEGALADD_SHIFT                      (0U)
#define CSL_GPMC_ERR_ADDR_ILLEGALADD_RESETVAL                   (0x00000000U)
#define CSL_GPMC_ERR_ADDR_ILLEGALADD_MAX                        (0x7fffffffU)

#define CSL_GPMC_ERR_ADDR_RESETVAL                              (0x00000000U)

/* CONFIG1_5 */

#define CSL_GPMC_CONFIG1_5_GPMCFCLKDIVIDER_MASK                 (0x00000003U)
#define CSL_GPMC_CONFIG1_5_GPMCFCLKDIVIDER_SHIFT                (0U)
#define CSL_GPMC_CONFIG1_5_GPMCFCLKDIVIDER_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG1_5_GPMCFCLKDIVIDER_EN_0X3               (0x00000003U)
#define CSL_GPMC_CONFIG1_5_GPMCFCLKDIVIDER_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG1_5_GPMCFCLKDIVIDER_EN_0X2               (0x00000002U)
#define CSL_GPMC_CONFIG1_5_GPMCFCLKDIVIDER_EN_0X0               (0x00000000U)

#define CSL_GPMC_CONFIG1_5_TIMEPARAGRANULARITY_MASK             (0x00000010U)
#define CSL_GPMC_CONFIG1_5_TIMEPARAGRANULARITY_SHIFT            (4U)
#define CSL_GPMC_CONFIG1_5_TIMEPARAGRANULARITY_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_5_TIMEPARAGRANULARITY_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG1_5_TIMEPARAGRANULARITY_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG1_5_MUXADDDATA_MASK                      (0x00000300U)
#define CSL_GPMC_CONFIG1_5_MUXADDDATA_SHIFT                     (8U)
#define CSL_GPMC_CONFIG1_5_MUXADDDATA_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_5_MUXADDDATA_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_5_MUXADDDATA_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_5_MUXADDDATA_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_5_MUXADDDATA_EN_0X0                    (0x00000000U)

#define CSL_GPMC_CONFIG1_5_DEVICETYPE_MASK                      (0x00000C00U)
#define CSL_GPMC_CONFIG1_5_DEVICETYPE_SHIFT                     (10U)
#define CSL_GPMC_CONFIG1_5_DEVICETYPE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_5_DEVICETYPE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_5_DEVICETYPE_EN_0X3                    (0x00000003U)
#define CSL_GPMC_CONFIG1_5_DEVICETYPE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_5_DEVICETYPE_EN_0X2                    (0x00000002U)

#define CSL_GPMC_CONFIG1_5_DEVICESIZE_MASK                      (0x00003000U)
#define CSL_GPMC_CONFIG1_5_DEVICESIZE_SHIFT                     (12U)
#define CSL_GPMC_CONFIG1_5_DEVICESIZE_RESETVAL                  (0x00000000U)
#define CSL_GPMC_CONFIG1_5_DEVICESIZE_EN_0X0                    (0x00000000U)
#define CSL_GPMC_CONFIG1_5_DEVICESIZE_EN_0X1                    (0x00000001U)
#define CSL_GPMC_CONFIG1_5_DEVICESIZE_EN_0X2                    (0x00000002U)
#define CSL_GPMC_CONFIG1_5_DEVICESIZE_EN_0X3                    (0x00000003U)

#define CSL_GPMC_CONFIG1_5_WAITPINSELECT_MASK                   (0x00030000U)
#define CSL_GPMC_CONFIG1_5_WAITPINSELECT_SHIFT                  (16U)
#define CSL_GPMC_CONFIG1_5_WAITPINSELECT_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WAITPINSELECT_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WAITPINSELECT_EN_0X1                 (0x00000001U)
#define CSL_GPMC_CONFIG1_5_WAITPINSELECT_EN_0X2                 (0x00000002U)
#define CSL_GPMC_CONFIG1_5_WAITPINSELECT_EN_0X3                 (0x00000003U)

#define CSL_GPMC_CONFIG1_5_WAITMONITORINGTIME_MASK              (0x000C0000U)
#define CSL_GPMC_CONFIG1_5_WAITMONITORINGTIME_SHIFT             (18U)
#define CSL_GPMC_CONFIG1_5_WAITMONITORINGTIME_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WAITMONITORINGTIME_EN_0X1            (0x00000001U)
#define CSL_GPMC_CONFIG1_5_WAITMONITORINGTIME_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WAITMONITORINGTIME_EN_0X3            (0x00000003U)
#define CSL_GPMC_CONFIG1_5_WAITMONITORINGTIME_EN_0X2            (0x00000002U)

#define CSL_GPMC_CONFIG1_5_WAITWRITEMONITORING_MASK             (0x00200000U)
#define CSL_GPMC_CONFIG1_5_WAITWRITEMONITORING_SHIFT            (21U)
#define CSL_GPMC_CONFIG1_5_WAITWRITEMONITORING_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WAITWRITEMONITORING_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG1_5_WAITWRITEMONITORING_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG1_5_WAITREADMONITORING_MASK              (0x00400000U)
#define CSL_GPMC_CONFIG1_5_WAITREADMONITORING_SHIFT             (22U)
#define CSL_GPMC_CONFIG1_5_WAITREADMONITORING_RESETVAL          (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WAITREADMONITORING_EN_0X0            (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WAITREADMONITORING_EN_0X1            (0x00000001U)

#define CSL_GPMC_CONFIG1_5_ATTACHEDDEVICEPAGELENGTH_MASK        (0x01800000U)
#define CSL_GPMC_CONFIG1_5_ATTACHEDDEVICEPAGELENGTH_SHIFT       (23U)
#define CSL_GPMC_CONFIG1_5_ATTACHEDDEVICEPAGELENGTH_RESETVAL    (0x00000000U)
#define CSL_GPMC_CONFIG1_5_ATTACHEDDEVICEPAGELENGTH_EN_0X1      (0x00000001U)
#define CSL_GPMC_CONFIG1_5_ATTACHEDDEVICEPAGELENGTH_EN_0X2      (0x00000002U)
#define CSL_GPMC_CONFIG1_5_ATTACHEDDEVICEPAGELENGTH_EN_0X3      (0x00000003U)
#define CSL_GPMC_CONFIG1_5_ATTACHEDDEVICEPAGELENGTH_EN_0X0      (0x00000000U)

#define CSL_GPMC_CONFIG1_5_CLKACTIVATIONTIME_MASK               (0x06000000U)
#define CSL_GPMC_CONFIG1_5_CLKACTIVATIONTIME_SHIFT              (25U)
#define CSL_GPMC_CONFIG1_5_CLKACTIVATIONTIME_RESETVAL           (0x00000000U)
#define CSL_GPMC_CONFIG1_5_CLKACTIVATIONTIME_EN_0X0             (0x00000000U)
#define CSL_GPMC_CONFIG1_5_CLKACTIVATIONTIME_EN_0X2             (0x00000002U)
#define CSL_GPMC_CONFIG1_5_CLKACTIVATIONTIME_EN_0X3             (0x00000003U)
#define CSL_GPMC_CONFIG1_5_CLKACTIVATIONTIME_EN_0X1             (0x00000001U)

#define CSL_GPMC_CONFIG1_5_WRITETYPE_MASK                       (0x08000000U)
#define CSL_GPMC_CONFIG1_5_WRITETYPE_SHIFT                      (27U)
#define CSL_GPMC_CONFIG1_5_WRITETYPE_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WRITETYPE_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WRITETYPE_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_5_WRITEMULTIPLE_MASK                   (0x10000000U)
#define CSL_GPMC_CONFIG1_5_WRITEMULTIPLE_SHIFT                  (28U)
#define CSL_GPMC_CONFIG1_5_WRITEMULTIPLE_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WRITEMULTIPLE_EN_0X0                 (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WRITEMULTIPLE_EN_0X1                 (0x00000001U)

#define CSL_GPMC_CONFIG1_5_READTYPE_MASK                        (0x20000000U)
#define CSL_GPMC_CONFIG1_5_READTYPE_SHIFT                       (29U)
#define CSL_GPMC_CONFIG1_5_READTYPE_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG1_5_READTYPE_EN_0X1                      (0x00000001U)
#define CSL_GPMC_CONFIG1_5_READTYPE_EN_0X0                      (0x00000000U)

#define CSL_GPMC_CONFIG1_5_READMULTIPLE_MASK                    (0x40000000U)
#define CSL_GPMC_CONFIG1_5_READMULTIPLE_SHIFT                   (30U)
#define CSL_GPMC_CONFIG1_5_READMULTIPLE_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG1_5_READMULTIPLE_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG1_5_READMULTIPLE_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG1_5_WRAPBURST_MASK                       (0x80000000U)
#define CSL_GPMC_CONFIG1_5_WRAPBURST_SHIFT                      (31U)
#define CSL_GPMC_CONFIG1_5_WRAPBURST_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WRAPBURST_EN_0X0                     (0x00000000U)
#define CSL_GPMC_CONFIG1_5_WRAPBURST_EN_0X1                     (0x00000001U)

#define CSL_GPMC_CONFIG1_5_RESETVAL                             (0x00000000U)

/* NAND_COMMAND_3 */

#define CSL_GPMC_NAND_COMMAND_3_GPMC_NAND_COMMAND_3_MASK        (0xFFFFFFFFU)
#define CSL_GPMC_NAND_COMMAND_3_GPMC_NAND_COMMAND_3_SHIFT       (0U)
#define CSL_GPMC_NAND_COMMAND_3_GPMC_NAND_COMMAND_3_RESETVAL    (0x00000000U)
#define CSL_GPMC_NAND_COMMAND_3_GPMC_NAND_COMMAND_3_MAX         (0xffffffffU)

#define CSL_GPMC_NAND_COMMAND_3_RESETVAL                        (0x00000000U)

/* BCH_RESULT1_3 */

#define CSL_GPMC_BCH_RESULT1_3_BCH_RESULT1_3_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT1_3_BCH_RESULT1_3_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT1_3_BCH_RESULT1_3_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT1_3_BCH_RESULT1_3_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT1_3_RESETVAL                         (0x00000000U)

/* CONFIG4_2 */

#define CSL_GPMC_CONFIG4_2_OEONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG4_2_OEONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG4_2_OEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_2_OEAADMUXONTIME_MASK                  (0x00000070U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXONTIME_SHIFT                 (4U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXONTIME_RESETVAL              (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXONTIME_EN_0X0                (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXONTIME_EN_0X1                (0x00000001U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXONTIME_EN_0X7                (0x00000007U)

#define CSL_GPMC_CONFIG4_2_OEEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG4_2_OEEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG4_2_OEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG4_2_OEOFFTIME_MASK                       (0x00001F00U)
#define CSL_GPMC_CONFIG4_2_OEOFFTIME_SHIFT                      (8U)
#define CSL_GPMC_CONFIG4_2_OEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_2_OEAADMUXOFFTIME_MASK                 (0x0000E000U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXOFFTIME_SHIFT                (13U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXOFFTIME_RESETVAL             (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXOFFTIME_EN_0X0               (0x00000000U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXOFFTIME_EN_0X1               (0x00000001U)
#define CSL_GPMC_CONFIG4_2_OEAADMUXOFFTIME_EN_0X7               (0x00000007U)

#define CSL_GPMC_CONFIG4_2_WEONTIME_MASK                        (0x000F0000U)
#define CSL_GPMC_CONFIG4_2_WEONTIME_SHIFT                       (16U)
#define CSL_GPMC_CONFIG4_2_WEONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG4_2_WEONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG4_2_WEEXTRADELAY_MASK                    (0x00800000U)
#define CSL_GPMC_CONFIG4_2_WEEXTRADELAY_SHIFT                   (23U)
#define CSL_GPMC_CONFIG4_2_WEEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG4_2_WEEXTRADELAY_EN_0X1                  (0x00000001U)
#define CSL_GPMC_CONFIG4_2_WEEXTRADELAY_EN_0X0                  (0x00000000U)

#define CSL_GPMC_CONFIG4_2_WEOFFTIME_MASK                       (0x1F000000U)
#define CSL_GPMC_CONFIG4_2_WEOFFTIME_SHIFT                      (24U)
#define CSL_GPMC_CONFIG4_2_WEOFFTIME_RESETVAL                   (0x00000000U)
#define CSL_GPMC_CONFIG4_2_WEOFFTIME_MAX                        (0x0000001fU)

#define CSL_GPMC_CONFIG4_2_RESETVAL                             (0x00000000U)

/* BCH_RESULT1_1 */

#define CSL_GPMC_BCH_RESULT1_1_BCH_RESULT1_1_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT1_1_BCH_RESULT1_1_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT1_1_BCH_RESULT1_1_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT1_1_BCH_RESULT1_1_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT1_1_RESETVAL                         (0x00000000U)

/* CONFIG6_4 */

#define CSL_GPMC_CONFIG6_4_BUSTURNAROUND_MASK                   (0x0000000FU)
#define CSL_GPMC_CONFIG6_4_BUSTURNAROUND_SHIFT                  (0U)
#define CSL_GPMC_CONFIG6_4_BUSTURNAROUND_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG6_4_BUSTURNAROUND_MAX                    (0x0000000fU)

#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDIFFCSEN_MASK             (0x00000040U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDIFFCSEN_SHIFT            (6U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDIFFCSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDIFFCSEN_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDIFFCSEN_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLESAMECSEN_MASK             (0x00000080U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLESAMECSEN_SHIFT            (7U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLESAMECSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLESAMECSEN_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLESAMECSEN_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDELAY_MASK                (0x00000F00U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDELAY_SHIFT               (8U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDELAY_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_4_CYCLE2CYCLEDELAY_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_4_WRDATAONADMUXBUS_MASK                (0x000F0000U)
#define CSL_GPMC_CONFIG6_4_WRDATAONADMUXBUS_SHIFT               (16U)
#define CSL_GPMC_CONFIG6_4_WRDATAONADMUXBUS_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_4_WRDATAONADMUXBUS_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_4_WRACCESSTIME_MASK                    (0x1F000000U)
#define CSL_GPMC_CONFIG6_4_WRACCESSTIME_SHIFT                   (24U)
#define CSL_GPMC_CONFIG6_4_WRACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG6_4_WRACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG6_4_RESETVAL                             (0x00000000U)

/* NAND_COMMAND_6 */

#define CSL_GPMC_NAND_COMMAND_6_GPMC_NAND_COMMAND_6_MASK        (0xFFFFFFFFU)
#define CSL_GPMC_NAND_COMMAND_6_GPMC_NAND_COMMAND_6_SHIFT       (0U)
#define CSL_GPMC_NAND_COMMAND_6_GPMC_NAND_COMMAND_6_RESETVAL    (0x00000000U)
#define CSL_GPMC_NAND_COMMAND_6_GPMC_NAND_COMMAND_6_MAX         (0xffffffffU)

#define CSL_GPMC_NAND_COMMAND_6_RESETVAL                        (0x00000000U)

/* NAND_DATA_3 */

#define CSL_GPMC_NAND_DATA_3_GPMC_NAND_DATA_3_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_DATA_3_GPMC_NAND_DATA_3_SHIFT             (0U)
#define CSL_GPMC_NAND_DATA_3_GPMC_NAND_DATA_3_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_DATA_3_GPMC_NAND_DATA_3_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_DATA_3_RESETVAL                           (0x00000000U)

/* CONFIG7_1 */

#define CSL_GPMC_CONFIG7_1_BASEADDR_MASK                        (0x0000003FU)
#define CSL_GPMC_CONFIG7_1_BASEADDR_SHIFT                       (0U)
#define CSL_GPMC_CONFIG7_1_BASEADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_1_BASEADDR_MAX                         (0x0000003fU)

#define CSL_GPMC_CONFIG7_1_CSVALID_MASK                         (0x00000040U)
#define CSL_GPMC_CONFIG7_1_CSVALID_SHIFT                        (6U)
#define CSL_GPMC_CONFIG7_1_CSVALID_RESETVAL                     (0x00000000U)
#define CSL_GPMC_CONFIG7_1_CSVALID_EN_0X0                       (0x00000000U)
#define CSL_GPMC_CONFIG7_1_CSVALID_EN_0X1                       (0x00000001U)

#define CSL_GPMC_CONFIG7_1_MASKADDR_MASK                        (0x00000F00U)
#define CSL_GPMC_CONFIG7_1_MASKADDR_SHIFT                       (8U)
#define CSL_GPMC_CONFIG7_1_MASKADDR_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG7_1_MASKADDR_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG7_1_RESETVAL                             (0x00000000U)

/* TIMEOUT_CTRL */

#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTEN_MASK                    (0x00000001U)
#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTEN_SHIFT                   (0U)
#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTEN_RESETVAL                (0x00000000U)
#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTEN_EN_0X0                  (0x00000000U)
#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTEN_EN_0X1                  (0x00000001U)

#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTSTARTVALUE_MASK            (0x00001FF0U)
#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTSTARTVALUE_SHIFT           (4U)
#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTSTARTVALUE_RESETVAL        (0x00000000U)
#define CSL_GPMC_TIMEOUT_CTRL_TIMEOUTSTARTVALUE_MAX             (0x000001ffU)

#define CSL_GPMC_TIMEOUT_CTRL_RESETVAL                          (0x00000000U)

/* CONFIG2_4 */

#define CSL_GPMC_CONFIG2_4_CSONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG2_4_CSONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG2_4_CSONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG2_4_CSONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG2_4_CSEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG2_4_CSEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG2_4_CSEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG2_4_CSEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG2_4_CSEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG2_4_CSRDOFFTIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG2_4_CSRDOFFTIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG2_4_CSRDOFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_4_CSRDOFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_4_CSWROFFTIME_MASK                     (0x001F0000U)
#define CSL_GPMC_CONFIG2_4_CSWROFFTIME_SHIFT                    (16U)
#define CSL_GPMC_CONFIG2_4_CSWROFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_4_CSWROFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_4_RESETVAL                             (0x00000000U)

/* CONFIG2_2 */

#define CSL_GPMC_CONFIG2_2_CSONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG2_2_CSONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG2_2_CSONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG2_2_CSONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG2_2_CSEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG2_2_CSEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG2_2_CSEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG2_2_CSEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG2_2_CSEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG2_2_CSRDOFFTIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG2_2_CSRDOFFTIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG2_2_CSRDOFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_2_CSRDOFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_2_CSWROFFTIME_MASK                     (0x001F0000U)
#define CSL_GPMC_CONFIG2_2_CSWROFFTIME_SHIFT                    (16U)
#define CSL_GPMC_CONFIG2_2_CSWROFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_2_CSWROFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_2_RESETVAL                             (0x00000000U)

/* BCH_RESULT5_5 */

#define CSL_GPMC_BCH_RESULT5_5_BCH_RESULT5_5_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT5_5_BCH_RESULT5_5_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT5_5_BCH_RESULT5_5_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT5_5_BCH_RESULT5_5_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT5_5_RESETVAL                         (0x00000000U)

/* CONFIG6_0 */

#define CSL_GPMC_CONFIG6_0_BUSTURNAROUND_MASK                   (0x0000000FU)
#define CSL_GPMC_CONFIG6_0_BUSTURNAROUND_SHIFT                  (0U)
#define CSL_GPMC_CONFIG6_0_BUSTURNAROUND_RESETVAL               (0x00000000U)
#define CSL_GPMC_CONFIG6_0_BUSTURNAROUND_MAX                    (0x0000000fU)

#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDIFFCSEN_MASK             (0x00000040U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDIFFCSEN_SHIFT            (6U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDIFFCSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDIFFCSEN_EN_0X0           (0x00000000U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDIFFCSEN_EN_0X1           (0x00000001U)

#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLESAMECSEN_MASK             (0x00000080U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLESAMECSEN_SHIFT            (7U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLESAMECSEN_RESETVAL         (0x00000000U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLESAMECSEN_EN_0X1           (0x00000001U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLESAMECSEN_EN_0X0           (0x00000000U)

#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDELAY_MASK                (0x00000F00U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDELAY_SHIFT               (8U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDELAY_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_0_CYCLE2CYCLEDELAY_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_0_WRDATAONADMUXBUS_MASK                (0x000F0000U)
#define CSL_GPMC_CONFIG6_0_WRDATAONADMUXBUS_SHIFT               (16U)
#define CSL_GPMC_CONFIG6_0_WRDATAONADMUXBUS_RESETVAL            (0x00000000U)
#define CSL_GPMC_CONFIG6_0_WRDATAONADMUXBUS_MAX                 (0x0000000fU)

#define CSL_GPMC_CONFIG6_0_WRACCESSTIME_MASK                    (0x1F000000U)
#define CSL_GPMC_CONFIG6_0_WRACCESSTIME_SHIFT                   (24U)
#define CSL_GPMC_CONFIG6_0_WRACCESSTIME_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG6_0_WRACCESSTIME_MAX                     (0x0000001fU)

#define CSL_GPMC_CONFIG6_0_RESETVAL                             (0x00000000U)

/* CONFIG2_5 */

#define CSL_GPMC_CONFIG2_5_CSONTIME_MASK                        (0x0000000FU)
#define CSL_GPMC_CONFIG2_5_CSONTIME_SHIFT                       (0U)
#define CSL_GPMC_CONFIG2_5_CSONTIME_RESETVAL                    (0x00000000U)
#define CSL_GPMC_CONFIG2_5_CSONTIME_MAX                         (0x0000000fU)

#define CSL_GPMC_CONFIG2_5_CSEXTRADELAY_MASK                    (0x00000080U)
#define CSL_GPMC_CONFIG2_5_CSEXTRADELAY_SHIFT                   (7U)
#define CSL_GPMC_CONFIG2_5_CSEXTRADELAY_RESETVAL                (0x00000000U)
#define CSL_GPMC_CONFIG2_5_CSEXTRADELAY_EN_0X0                  (0x00000000U)
#define CSL_GPMC_CONFIG2_5_CSEXTRADELAY_EN_0X1                  (0x00000001U)

#define CSL_GPMC_CONFIG2_5_CSRDOFFTIME_MASK                     (0x00001F00U)
#define CSL_GPMC_CONFIG2_5_CSRDOFFTIME_SHIFT                    (8U)
#define CSL_GPMC_CONFIG2_5_CSRDOFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_5_CSRDOFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_5_CSWROFFTIME_MASK                     (0x001F0000U)
#define CSL_GPMC_CONFIG2_5_CSWROFFTIME_SHIFT                    (16U)
#define CSL_GPMC_CONFIG2_5_CSWROFFTIME_RESETVAL                 (0x00000000U)
#define CSL_GPMC_CONFIG2_5_CSWROFFTIME_MAX                      (0x0000001fU)

#define CSL_GPMC_CONFIG2_5_RESETVAL                             (0x00000000U)

/* NAND_DATA_5 */

#define CSL_GPMC_NAND_DATA_5_GPMC_NAND_DATA_5_MASK              (0xFFFFFFFFU)
#define CSL_GPMC_NAND_DATA_5_GPMC_NAND_DATA_5_SHIFT             (0U)
#define CSL_GPMC_NAND_DATA_5_GPMC_NAND_DATA_5_RESETVAL          (0x00000000U)
#define CSL_GPMC_NAND_DATA_5_GPMC_NAND_DATA_5_MAX               (0xffffffffU)

#define CSL_GPMC_NAND_DATA_5_RESETVAL                           (0x00000000U)

/* NAND_COMMAND_1 */

#define CSL_GPMC_NAND_COMMAND_1_GPMC_NAND_COMMAND_1_MASK        (0xFFFFFFFFU)
#define CSL_GPMC_NAND_COMMAND_1_GPMC_NAND_COMMAND_1_SHIFT       (0U)
#define CSL_GPMC_NAND_COMMAND_1_GPMC_NAND_COMMAND_1_RESETVAL    (0x00000000U)
#define CSL_GPMC_NAND_COMMAND_1_GPMC_NAND_COMMAND_1_MAX         (0xffffffffU)

#define CSL_GPMC_NAND_COMMAND_1_RESETVAL                        (0x00000000U)

/* BCH_RESULT2_0 */

#define CSL_GPMC_BCH_RESULT2_0_BCH_RESULT2_0_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT2_0_BCH_RESULT2_0_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT2_0_BCH_RESULT2_0_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT2_0_BCH_RESULT2_0_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT2_0_RESETVAL                         (0x00000000U)

/* BCH_RESULT6_2 */

#define CSL_GPMC_BCH_RESULT6_2_BCH_RESULT6_2_MASK               (0xFFFFFFFFU)
#define CSL_GPMC_BCH_RESULT6_2_BCH_RESULT6_2_SHIFT              (0U)
#define CSL_GPMC_BCH_RESULT6_2_BCH_RESULT6_2_RESETVAL           (0x00000000U)
#define CSL_GPMC_BCH_RESULT6_2_BCH_RESULT6_2_MAX                (0xffffffffU)

#define CSL_GPMC_BCH_RESULT6_2_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
