/********************************************************************
 * Copyright ((uint32_t)C) 2013-2020 Texas Instruments Incorporated.
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
#ifndef CSLR_SPI_H
#define CSLR_SPI_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for TOP_LEVEL
**************************************************************************/
typedef struct {
    volatile Uint32 SPIGCR0;
    volatile Uint32 SPIGCR1;
    volatile Uint32 SPIINT0;
    volatile Uint32 SPILVL;
    volatile Uint32 SPIFLG;
    volatile Uint32 SPIPC0;
    volatile Uint32 SPIPC1;
    volatile Uint32 SPIPC2;
    volatile Uint32 SPIPC3;
    volatile Uint32 SPIPC4;
    volatile Uint32 SPIPC5;
    volatile Uint32 SPIPC6;
    volatile Uint32 SPIPC7;
    volatile Uint32 SPIPC8;
    volatile Uint32 SPIDAT0;
    volatile Uint32 SPIDAT1;
    volatile Uint32 SPIBUF;
    volatile Uint32 SPIEMU;
    volatile Uint32 SPIDELAY;
    volatile Uint32 SPIDEF;
    volatile Uint32 SPIFMT[4];
    volatile Uint32 INTVEC[2];
    volatile Uint32 SPISRSEL;
    volatile Uint32 SPIPMCTRL;
    volatile Uint32 MIBSPIE;
    volatile Uint32 TGITENST;
    volatile Uint32 TGITENCR;
    volatile Uint8  RSVD0[4];
    volatile Uint32 TGITLVST;
    volatile Uint32 TGITLVCR;
    volatile Uint8  RSVD1[8];
    volatile Uint32 TGINTFLAG;
    volatile Uint32 LTGPEND;
    volatile Uint32 TGCTRL[4];
    volatile Uint8  RSVD2[48];
    volatile Uint32 DMACTRL[4];
    volatile Uint8  RSVD3[16];
    volatile Uint32 DMACOUNT[8];
    volatile Uint32 DMA0CNTL;
    volatile Uint8  RSVD4[4];
    volatile Uint32 UERRCTRL;
    volatile Uint32 UERRSTAT;
    volatile Uint32 UERRADDR1;
    volatile Uint32 UERRADDR0;
    volatile Uint32 RXOVRN_BUF_ADDR;
    volatile Uint32 IOLPBKTSTCR;
    volatile Uint8  RSVD5[196];
    volatile Uint32 SPIREV;
} CSL_SpiRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_SPI_SPIGCR0                                         ((uint32_t)0x0U)
#define CSL_SPI_SPIGCR1                                         ((uint32_t)0x4U)
#define CSL_SPI_SPIINT0                                         ((uint32_t)0x8U)
#define CSL_SPI_SPILVL                                          ((uint32_t)0xCU)
#define CSL_SPI_SPIFLG                                          ((uint32_t)0x10U)
#define CSL_SPI_SPIPC0                                          ((uint32_t)0x14U)
#define CSL_SPI_SPIPC1                                          ((uint32_t)0x18U)
#define CSL_SPI_SPIPC2                                          ((uint32_t)0x1CU)
#define CSL_SPI_SPIPC3                                          ((uint32_t)0x20U)
#define CSL_SPI_SPIPC4                                          ((uint32_t)0x24U)
#define CSL_SPI_SPIPC5                                          ((uint32_t)0x28U)
#define CSL_SPI_SPIPC6                                          ((uint32_t)0x2CU)
#define CSL_SPI_SPIPC7                                          ((uint32_t)0x30U)
#define CSL_SPI_SPIPC8                                          ((uint32_t)0x34U)
#define CSL_SPI_SPIDAT0                                         ((uint32_t)0x38U)
#define CSL_SPI_SPIDAT1                                         ((uint32_t)0x3CU)
#define CSL_SPI_SPIBUF                                          ((uint32_t)0x40U)
#define CSL_SPI_SPIEMU                                          ((uint32_t)0x44U)
#define CSL_SPI_SPIDELAY                                        ((uint32_t)0x48U)
#define CSL_SPI_SPIDEF                                          ((uint32_t)0x4CU)
#define CSL_SPI_SPIFMT(i)                                       ((uint32_t)0x50U + ((i) * 4U))
#define CSL_SPI_INTVEC(i)                                       ((uint32_t)0x60U + ((i) * 4U))
#define CSL_SPI_SPISRSEL                                        ((uint32_t)0x68U)
#define CSL_SPI_SPIPMCTRL                                       ((uint32_t)0x6CU)
#define CSL_SPI_MIBSPIE                                         ((uint32_t)0x70U)
#define CSL_SPI_TGITENST                                        ((uint32_t)0x74U)
#define CSL_SPI_TGITENCR                                        ((uint32_t)0x78U)
#define CSL_SPI_TGITLVST                                        ((uint32_t)0x80U)
#define CSL_SPI_TGITLVCR                                        ((uint32_t)0x84U)
#define CSL_SPI_TGINTFLAG                                       ((uint32_t)0x90U)
#define CSL_SPI_LTGPEND                                         ((uint32_t)0x94U)
#define CSL_SPI_TGCTRL(i)                                       ((uint32_t)0x98U + ((i) * 4U))
#define CSL_SPI_DMACTRL(i)                                      ((uint32_t)0xD8U + ((i) * 4U))
#define CSL_SPI_DMACOUNT(i)                                     ((uint32_t)0xF8U + ((i) * 4U))
#define CSL_SPI_DMA0CNTL                                        ((uint32_t)0x118U)
#define CSL_SPI_UERRCTRL                                        ((uint32_t)0x120U)
#define CSL_SPI_UERRSTAT                                        ((uint32_t)0x124U)
#define CSL_SPI_UERRADDR1                                       ((uint32_t)0x128U)
#define CSL_SPI_UERRADDR0                                       ((uint32_t)0x12CU)
#define CSL_SPI_RXOVRN_BUF_ADDR                                 ((uint32_t)0x130U)
#define CSL_SPI_IOLPBKTSTCR                                     ((uint32_t)0x134U)
#define CSL_SPI_SPIREV                                          ((uint32_t)0x1FCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* SPIGCR0 */


#define CSL_SPI_SPIGCR0_RESET_MASK       			((uint32_t)0x00000001u)
#define CSL_SPI_SPIGCR0_RESET_SHIFT      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR0_RESET_RESETVAL   			((uint32_t)0x00000000u)
/*----RESET Tokens----*/
#define CSL_SPI_SPIGCR0_RESET_IN_RESET   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR0_RESET_OUT_OF_RESET 			((uint32_t)0x00000001u)

#define CSL_SPI_SPIGCR0_RESETVAL         			((uint32_t)0x00000000u)

/* SPIGCR1 */


#define CSL_SPI_SPIGCR1_ENABLE_MASK      			((uint32_t)0x01000000u)
#define CSL_SPI_SPIGCR1_ENABLE_SHIFT     			((uint32_t)0x00000018u)
#define CSL_SPI_SPIGCR1_ENABLE_RESETVAL  			((uint32_t)0x00000000u)
/*----ENABLE Tokens----*/
#define CSL_SPI_SPIGCR1_ENABLE_DISABLE   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR1_ENABLE_ENABLE    			((uint32_t)0x00000001u)


#define CSL_SPI_SPIGCR1_LOOPBACK_MASK    			((uint32_t)0x00010000u)
#define CSL_SPI_SPIGCR1_LOOPBACK_SHIFT   			((uint32_t)0x00000010u)
#define CSL_SPI_SPIGCR1_LOOPBACK_RESETVAL 			((uint32_t)0x00000000u)
/*----LOOPBACK Tokens----*/
#define CSL_SPI_SPIGCR1_LOOPBACK_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR1_LOOPBACK_ENABLE  			((uint32_t)0x00000001u)


#define CSL_SPI_SPIGCR1_POWERDOWN_MASK   			((uint32_t)0x00000100u)
#define CSL_SPI_SPIGCR1_POWERDOWN_SHIFT  			((uint32_t)0x00000008u)
#define CSL_SPI_SPIGCR1_POWERDOWN_RESETVAL 			((uint32_t)0x00000000u)
/*----POWERDOWN Tokens----*/
#define CSL_SPI_SPIGCR1_POWERDOWN_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR1_POWERDOWN_ENABLE 			((uint32_t)0x00000001u)


#define CSL_SPI_SPIGCR1_CLKMOD_MASK      			((uint32_t)0x00000002u)
#define CSL_SPI_SPIGCR1_CLKMOD_SHIFT     			((uint32_t)0x00000001u)
#define CSL_SPI_SPIGCR1_CLKMOD_RESETVAL  			((uint32_t)0x00000000u)
/*----CLKMOD Tokens----*/
#define CSL_SPI_SPIGCR1_CLKMOD_EXTERNAL  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR1_CLKMOD_INTERNAL  			((uint32_t)0x00000001u)

#define CSL_SPI_SPIGCR1_MASTER_MASK      			((uint32_t)0x00000001u)
#define CSL_SPI_SPIGCR1_MASTER_SHIFT     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR1_MASTER_RESETVAL  			((uint32_t)0x00000000u)
/*----MASTER Tokens----*/
#define CSL_SPI_SPIGCR1_MASTER_SLAVE     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIGCR1_MASTER_MASTER    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIGCR1_RESETVAL         			((uint32_t)0x00000000u)

/* SPIINT0 */


#define CSL_SPI_SPIINT0_ENABLEHIGHZ_MASK 			((uint32_t)0x01000000u)
#define CSL_SPI_SPIINT0_ENABLEHIGHZ_SHIFT 			((uint32_t)0x00000018u)
#define CSL_SPI_SPIINT0_ENABLEHIGHZ_RESETVAL 			((uint32_t)0x00000000u)
/*----ENABLEHIGHZ Tokens----*/
#define CSL_SPI_SPIINT0_ENABLEHIGHZ_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_ENABLEHIGHZ_ENABLE 			((uint32_t)0x00000001u)


#define CSL_SPI_SPIINT0_DMAREQEN_MASK    			((uint32_t)0x00010000u)
#define CSL_SPI_SPIINT0_DMAREQEN_SHIFT   			((uint32_t)0x00000010u)
#define CSL_SPI_SPIINT0_DMAREQEN_RESETVAL 			((uint32_t)0x00000000u)
/*----DMAREQEN Tokens----*/
#define CSL_SPI_SPIINT0_DMAREQEN_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_DMAREQEN_ENABLE  			((uint32_t)0x00000001u)


#define CSL_SPI_SPIINT0_TXINTENA_MASK    			((uint32_t)0x00000200u)
#define CSL_SPI_SPIINT0_TXINTENA_SHIFT   			((uint32_t)0x00000009u)
#define CSL_SPI_SPIINT0_TXINTENA_RESETVAL 			((uint32_t)0x00000000u)
/*----TXINTENA Tokens----*/
#define CSL_SPI_SPIINT0_TXINTENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_TXINTENA_ENABLE  			((uint32_t)0x00000001u)

#define CSL_SPI_SPIINT0_RXINTENA_MASK    			((uint32_t)0x00000100u)
#define CSL_SPI_SPIINT0_RXINTENA_SHIFT   			((uint32_t)0x00000008u)
#define CSL_SPI_SPIINT0_RXINTENA_RESETVAL 			((uint32_t)0x00000000u)
/*----RXINTENA Tokens----*/
#define CSL_SPI_SPIINT0_RXINTENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_RXINTENA_ENABLE  			((uint32_t)0x00000001u)


#define CSL_SPI_SPIINT0_OVRNINTENA_MASK  			((uint32_t)0x00000040u)
#define CSL_SPI_SPIINT0_OVRNINTENA_SHIFT 			((uint32_t)0x00000006u)
#define CSL_SPI_SPIINT0_OVRNINTENA_RESETVAL 			((uint32_t)0x00000000u)
/*----OVRNINTENA Tokens----*/
#define CSL_SPI_SPIINT0_OVRNINTENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_OVRNINTENA_ENABLE 			((uint32_t)0x00000001u)


#define CSL_SPI_SPIINT0_BITERRENA_MASK   			((uint32_t)0x00000010u)
#define CSL_SPI_SPIINT0_BITERRENA_SHIFT  			((uint32_t)0x00000004u)
#define CSL_SPI_SPIINT0_BITERRENA_RESETVAL 			((uint32_t)0x00000000u)
/*----BITERRENA Tokens----*/
#define CSL_SPI_SPIINT0_BITERRENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_BITERRENA_ENABLE 			((uint32_t)0x00000001u)

#define CSL_SPI_SPIINT0_DESYNCENA_MASK   			((uint32_t)0x00000008u)
#define CSL_SPI_SPIINT0_DESYNCENA_SHIFT  			((uint32_t)0x00000003u)
#define CSL_SPI_SPIINT0_DESYNCENA_RESETVAL 			((uint32_t)0x00000000u)
/*----DESYNCENA Tokens----*/
#define CSL_SPI_SPIINT0_DESYNCENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_DESYNCENA_ENABLE 			((uint32_t)0x00000001u)

#define CSL_SPI_SPIINT0_PARERRENA_MASK   			((uint32_t)0x00000004u)
#define CSL_SPI_SPIINT0_PARERRENA_SHIFT  			((uint32_t)0x00000002u)
#define CSL_SPI_SPIINT0_PARERRENA_RESETVAL 			((uint32_t)0x00000000u)
/*----PARERRENA Tokens----*/
#define CSL_SPI_SPIINT0_PARERRENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_PARERRENA_ENABLE 			((uint32_t)0x00000001u)

#define CSL_SPI_SPIINT0_TIMEOUTENA_MASK  			((uint32_t)0x00000002u)
#define CSL_SPI_SPIINT0_TIMEOUTENA_SHIFT 			((uint32_t)0x00000001u)
#define CSL_SPI_SPIINT0_TIMEOUTENA_RESETVAL 			((uint32_t)0x00000000u)
/*----TIMEOUTENA Tokens----*/
#define CSL_SPI_SPIINT0_TIMEOUTENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_TIMEOUTENA_ENABLE 			((uint32_t)0x00000001u)

#define CSL_SPI_SPIINT0_DLENERRENA_MASK  			((uint32_t)0x00000001u)
#define CSL_SPI_SPIINT0_DLENERRENA_SHIFT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_DLENERRENA_RESETVAL 			((uint32_t)0x00000000u)
/*----DLENERRENA Tokens----*/
#define CSL_SPI_SPIINT0_DLENERRENA_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIINT0_DLENERRENA_ENABLE 			((uint32_t)0x00000001u)

#define CSL_SPI_SPIINT0_RESETVAL         			((uint32_t)0x00000000u)

/* SPILVL */


#define CSL_SPI_SPILVL_TXINTLVL_MASK     			((uint32_t)0x00000200u)
#define CSL_SPI_SPILVL_TXINTLVL_SHIFT    			((uint32_t)0x00000009u)
#define CSL_SPI_SPILVL_TXINTLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----TXINTLVL Tokens----*/
#define CSL_SPI_SPILVL_TXINTLVL_INT0     			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_TXINTLVL_INT1     			((uint32_t)0x00000001u)

#define CSL_SPI_SPILVL_RXINTLVL_MASK     			((uint32_t)0x00000100u)
#define CSL_SPI_SPILVL_RXINTLVL_SHIFT    			((uint32_t)0x00000008u)
#define CSL_SPI_SPILVL_RXINTLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----RXINTLVL Tokens----*/
#define CSL_SPI_SPILVL_RXINTLVL_INT0     			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_RXINTLVL_INT1     			((uint32_t)0x00000001u)


#define CSL_SPI_SPILVL_OVRNINTLVL_MASK   			((uint32_t)0x00000040u)
#define CSL_SPI_SPILVL_OVRNINTLVL_SHIFT  			((uint32_t)0x00000006u)
#define CSL_SPI_SPILVL_OVRNINTLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----OVRNINTLVL Tokens----*/
#define CSL_SPI_SPILVL_OVRNINTLVL_INT0   			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_OVRNINTLVL_INT1   			((uint32_t)0x00000001u)


#define CSL_SPI_SPILVL_BITERRLVL_MASK    			((uint32_t)0x00000010u)
#define CSL_SPI_SPILVL_BITERRLVL_SHIFT   			((uint32_t)0x00000004u)
#define CSL_SPI_SPILVL_BITERRLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----BITERRLVL Tokens----*/
#define CSL_SPI_SPILVL_BITERRLVL_INT0    			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_BITERRLVL_INT1    			((uint32_t)0x00000001u)

#define CSL_SPI_SPILVL_DESYNCLVL_MASK    			((uint32_t)0x00000008u)
#define CSL_SPI_SPILVL_DESYNCLVL_SHIFT   			((uint32_t)0x00000003u)
#define CSL_SPI_SPILVL_DESYNCLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----DESYNCLVL Tokens----*/
#define CSL_SPI_SPILVL_DESYNCLVL_INT0    			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_DESYNCLVL_INT1    			((uint32_t)0x00000001u)

#define CSL_SPI_SPILVL_PARERRLVL_MASK    			((uint32_t)0x00000004u)
#define CSL_SPI_SPILVL_PARERRLVL_SHIFT   			((uint32_t)0x00000002u)
#define CSL_SPI_SPILVL_PARERRLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----PARERRLVL Tokens----*/
#define CSL_SPI_SPILVL_PARERRLVL_INT0    			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_PARERRLVL_INT1    			((uint32_t)0x00000001u)

#define CSL_SPI_SPILVL_TIMEOUTLVL_MASK   			((uint32_t)0x00000002u)
#define CSL_SPI_SPILVL_TIMEOUTLVL_SHIFT  			((uint32_t)0x00000001u)
#define CSL_SPI_SPILVL_TIMEOUTLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----TIMEOUTLVL Tokens----*/
#define CSL_SPI_SPILVL_TIMEOUTLVL_INT0   			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_TIMEOUTLVL_INT1   			((uint32_t)0x00000001u)

#define CSL_SPI_SPILVL_DLENERRLVL_MASK   			((uint32_t)0x00000001u)
#define CSL_SPI_SPILVL_DLENERRLVL_SHIFT  			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_DLENERRLVL_RESETVAL 			((uint32_t)0x00000000u)
/*----DLENERRLVL Tokens----*/
#define CSL_SPI_SPILVL_DLENERRLVL_INT0   			((uint32_t)0x00000000u)
#define CSL_SPI_SPILVL_DLENERRLVL_INT1   			((uint32_t)0x00000001u)

#define CSL_SPI_SPILVL_RESETVAL          			((uint32_t)0x00000000u)

/* SPIFLG */


#define CSL_SPI_SPIFLG_TXINTFLG_MASK     			((uint32_t)0x00000200u)
#define CSL_SPI_SPIFLG_TXINTFLG_SHIFT    			((uint32_t)0x00000009u)
#define CSL_SPI_SPIFLG_TXINTFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----TXINTFLG Tokens----*/
#define CSL_SPI_SPIFLG_TXINTFLG_NO_EMPTY 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_TXINTFLG_EMPTY    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFLG_RXINTFLG_MASK     			((uint32_t)0x00000100u)
#define CSL_SPI_SPIFLG_RXINTFLG_SHIFT    			((uint32_t)0x00000008u)
#define CSL_SPI_SPIFLG_RXINTFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----RXINTFLG Tokens----*/
#define CSL_SPI_SPIFLG_RXINTFLG_NO_FULL  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_RXINTFLG_FULL     			((uint32_t)0x00000001u)


#define CSL_SPI_SPIFLG_OVRNINTFLG_MASK   			((uint32_t)0x00000040u)
#define CSL_SPI_SPIFLG_OVRNINTFLG_SHIFT  			((uint32_t)0x00000006u)
#define CSL_SPI_SPIFLG_OVRNINTFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----OVRNINTFLG Tokens----*/
#define CSL_SPI_SPIFLG_OVRNINTFLG_NO_ERROR 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_OVRNINTFLG_ERROR  			((uint32_t)0x00000001u)


#define CSL_SPI_SPIFLG_BITERRFLG_MASK    			((uint32_t)0x00000010u)
#define CSL_SPI_SPIFLG_BITERRFLG_SHIFT   			((uint32_t)0x00000004u)
#define CSL_SPI_SPIFLG_BITERRFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----BITERRFLG Tokens----*/
#define CSL_SPI_SPIFLG_BITERRFLG_NO_ERROR 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_BITERRFLG_ERROR   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFLG_DESYNCFLG_MASK    			((uint32_t)0x00000008u)
#define CSL_SPI_SPIFLG_DESYNCFLG_SHIFT   			((uint32_t)0x00000003u)
#define CSL_SPI_SPIFLG_DESYNCFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----DESYNCFLG Tokens----*/
#define CSL_SPI_SPIFLG_DESYNCFLG_NO_ERROR 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_DESYNCFLG_ERROR   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFLG_PARERRFLG_MASK    			((uint32_t)0x00000004u)
#define CSL_SPI_SPIFLG_PARERRFLG_SHIFT   			((uint32_t)0x00000002u)
#define CSL_SPI_SPIFLG_PARERRFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----PARERRFLG Tokens----*/
#define CSL_SPI_SPIFLG_PARERRFLG_NO_ERROR 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_PARERRFLG_ERROR   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFLG_TIMEOUTFLG_MASK   			((uint32_t)0x00000002u)
#define CSL_SPI_SPIFLG_TIMEOUTFLG_SHIFT  			((uint32_t)0x00000001u)
#define CSL_SPI_SPIFLG_TIMEOUTFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----TIMEOUTFLG Tokens----*/
#define CSL_SPI_SPIFLG_TIMEOUTFLG_NO_ERROR 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_TIMEOUTFLG_ERROR  			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFLG_DLENERRFLG_MASK   			((uint32_t)0x00000001u)
#define CSL_SPI_SPIFLG_DLENERRFLG_SHIFT  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_DLENERRFLG_RESETVAL 			((uint32_t)0x00000000u)
/*----DLENERRFLG Tokens----*/
#define CSL_SPI_SPIFLG_DLENERRFLG_NO_ERROR 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFLG_DLENERRFLG_ERROR  			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFLG_RESETVAL          			((uint32_t)0x00000000u)

/* SPIPC0 */


#define CSL_SPI_SPIPC0_SOMIFUN_MASK      			((uint32_t)0x00000800u)
#define CSL_SPI_SPIPC0_SOMIFUN_SHIFT     			((uint32_t)0x0000000Bu)
#define CSL_SPI_SPIPC0_SOMIFUN_RESETVAL  			((uint32_t)0x00000000u)
/*----SOMIFUN Tokens----*/
#define CSL_SPI_SPIPC0_SOMIFUN_GPIO      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SOMIFUN_SPI       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SIMOFUN_MASK      			((uint32_t)0x00000400u)
#define CSL_SPI_SPIPC0_SIMOFUN_SHIFT     			((uint32_t)0x0000000Au)
#define CSL_SPI_SPIPC0_SIMOFUN_RESETVAL  			((uint32_t)0x00000000u)
/*----SIMOFUN Tokens----*/
#define CSL_SPI_SPIPC0_SIMOFUN_GPIO      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SIMOFUN_SPI       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_CLKFUN_MASK       			((uint32_t)0x00000200u)
#define CSL_SPI_SPIPC0_CLKFUN_SHIFT      			((uint32_t)0x00000009u)
#define CSL_SPI_SPIPC0_CLKFUN_RESETVAL   			((uint32_t)0x00000000u)
/*----CLKFUN Tokens----*/
#define CSL_SPI_SPIPC0_CLKFUN_GPIO       			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_CLKFUN_SPI        			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_ENAFUN_MASK       			((uint32_t)0x00000100u)
#define CSL_SPI_SPIPC0_ENAFUN_SHIFT      			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC0_ENAFUN_RESETVAL   			((uint32_t)0x00000000u)
/*----ENAFUN Tokens----*/
#define CSL_SPI_SPIPC0_ENAFUN_GPIO       			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_ENAFUN_SPI        			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN7_MASK     			((uint32_t)0x00000080u)
#define CSL_SPI_SPIPC0_SCS0FUN7_SHIFT    			((uint32_t)0x00000007u)
#define CSL_SPI_SPIPC0_SCS0FUN7_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN7 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN7_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN7_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN6_MASK     			((uint32_t)0x00000040u)
#define CSL_SPI_SPIPC0_SCS0FUN6_SHIFT    			((uint32_t)0x00000006u)
#define CSL_SPI_SPIPC0_SCS0FUN6_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN6 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN6_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN6_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN5_MASK     			((uint32_t)0x00000020u)
#define CSL_SPI_SPIPC0_SCS0FUN5_SHIFT    			((uint32_t)0x00000005u)
#define CSL_SPI_SPIPC0_SCS0FUN5_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN5 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN5_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN5_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN4_MASK     			((uint32_t)0x00000010u)
#define CSL_SPI_SPIPC0_SCS0FUN4_SHIFT    			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC0_SCS0FUN4_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN4 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN4_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN4_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN3_MASK     			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC0_SCS0FUN3_SHIFT    			((uint32_t)0x00000003u)
#define CSL_SPI_SPIPC0_SCS0FUN3_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN3 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN3_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN3_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN2_MASK     			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC0_SCS0FUN2_SHIFT    			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC0_SCS0FUN2_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN2 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN2_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN2_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN1_MASK     			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC0_SCS0FUN1_SHIFT    			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC0_SCS0FUN1_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN1 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN1_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN1_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_SCS0FUN0_MASK     			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC0_SCS0FUN0_SHIFT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN0_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0FUN0 Tokens----*/
#define CSL_SPI_SPIPC0_SCS0FUN0_GPIO     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC0_SCS0FUN0_SPI      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC0_RESETVAL          			((uint32_t)0x00000000u)

/* SPIPC1 */


#define CSL_SPI_SPIPC1_SOMIDIR_MASK      			((uint32_t)0x00000800u)
#define CSL_SPI_SPIPC1_SOMIDIR_SHIFT     			((uint32_t)0x0000000Bu)
#define CSL_SPI_SPIPC1_SOMIDIR_RESETVAL  			((uint32_t)0x00000000u)
/*----SOMIDIR Tokens----*/
#define CSL_SPI_SPIPC1_SOMIDIR_INPUT     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SOMIDIR_OUTPUT    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SIMODIR_MASK      			((uint32_t)0x00000400u)
#define CSL_SPI_SPIPC1_SIMODIR_SHIFT     			((uint32_t)0x0000000Au)
#define CSL_SPI_SPIPC1_SIMODIR_RESETVAL  			((uint32_t)0x00000000u)
/*----SIMODIR Tokens----*/
#define CSL_SPI_SPIPC1_SIMODIR_INPUT     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SIMODIR_OUTPUT    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_CLKDIR_MASK       			((uint32_t)0x00000200u)
#define CSL_SPI_SPIPC1_CLKDIR_SHIFT      			((uint32_t)0x00000009u)
#define CSL_SPI_SPIPC1_CLKDIR_RESETVAL   			((uint32_t)0x00000000u)
/*----CLKDIR Tokens----*/
#define CSL_SPI_SPIPC1_CLKDIR_INPUT      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_CLKDIR_OUTPUT     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_ENADIR_MASK       			((uint32_t)0x00000100u)
#define CSL_SPI_SPIPC1_ENADIR_SHIFT      			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC1_ENADIR_RESETVAL   			((uint32_t)0x00000000u)
/*----ENADIR Tokens----*/
#define CSL_SPI_SPIPC1_ENADIR_INPUT      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_ENADIR_OUTPUT     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR7_MASK     			((uint32_t)0x00000080u)
#define CSL_SPI_SPIPC1_SCS0DIR7_SHIFT    			((uint32_t)0x00000007u)
#define CSL_SPI_SPIPC1_SCS0DIR7_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR7 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR7_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR7_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR6_MASK     			((uint32_t)0x00000040u)
#define CSL_SPI_SPIPC1_SCS0DIR6_SHIFT    			((uint32_t)0x00000006u)
#define CSL_SPI_SPIPC1_SCS0DIR6_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR6 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR6_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR6_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR5_MASK     			((uint32_t)0x00000020u)
#define CSL_SPI_SPIPC1_SCS0DIR5_SHIFT    			((uint32_t)0x00000005u)
#define CSL_SPI_SPIPC1_SCS0DIR5_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR5 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR5_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR5_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR4_MASK     			((uint32_t)0x00000010u)
#define CSL_SPI_SPIPC1_SCS0DIR4_SHIFT    			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC1_SCS0DIR4_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR4 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR4_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR4_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR3_MASK     			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC1_SCS0DIR3_SHIFT    			((uint32_t)0x00000003u)
#define CSL_SPI_SPIPC1_SCS0DIR3_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR3 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR3_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR3_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR2_MASK     			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC1_SCS0DIR2_SHIFT    			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC1_SCS0DIR2_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR2 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR2_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR2_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR1_MASK     			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC1_SCS0DIR1_SHIFT    			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC1_SCS0DIR1_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR1 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR1_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR1_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_SCS0DIR0_MASK     			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC1_SCS0DIR0_SHIFT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR0_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIR0 Tokens----*/
#define CSL_SPI_SPIPC1_SCS0DIR0_INPUT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC1_SCS0DIR0_OUTPUT   			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC1_RESETVAL          			((uint32_t)0x00000000u)

/* SPIPC2 */


#define CSL_SPI_SPIPC2_SOMIDIN_MASK      			((uint32_t)0x00000800u)
#define CSL_SPI_SPIPC2_SOMIDIN_SHIFT     			((uint32_t)0x0000000Bu)
#define CSL_SPI_SPIPC2_SOMIDIN_RESETVAL  			((uint32_t)0x00000000u)
/*----SOMIDIN Tokens----*/
#define CSL_SPI_SPIPC2_SOMIDIN_LOW       			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SOMIDIN_HIGH      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SIMODIN_MASK      			((uint32_t)0x00000400u)
#define CSL_SPI_SPIPC2_SIMODIN_SHIFT     			((uint32_t)0x0000000Au)
#define CSL_SPI_SPIPC2_SIMODIN_RESETVAL  			((uint32_t)0x00000000u)
/*----SIMODIN Tokens----*/
#define CSL_SPI_SPIPC2_SIMODIN_LOW       			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SIMODIN_HIGH      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_CLKDIN_MASK       			((uint32_t)0x00000200u)
#define CSL_SPI_SPIPC2_CLKDIN_SHIFT      			((uint32_t)0x00000009u)
#define CSL_SPI_SPIPC2_CLKDIN_RESETVAL   			((uint32_t)0x00000000u)
/*----CLKDIN Tokens----*/
#define CSL_SPI_SPIPC2_CLKDIN_LOW        			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_CLKDIN_HIGH       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_ENADIN_MASK       			((uint32_t)0x00000100u)
#define CSL_SPI_SPIPC2_ENADIN_SHIFT      			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC2_ENADIN_RESETVAL   			((uint32_t)0x00000000u)
/*----ENADIN Tokens----*/
#define CSL_SPI_SPIPC2_ENADIN_LOW        			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_ENADIN_HIGH       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN7_MASK     			((uint32_t)0x00000080u)
#define CSL_SPI_SPIPC2_SCS0DIN7_SHIFT    			((uint32_t)0x00000007u)
#define CSL_SPI_SPIPC2_SCS0DIN7_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN7 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN7_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN7_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN6_MASK     			((uint32_t)0x00000040u)
#define CSL_SPI_SPIPC2_SCS0DIN6_SHIFT    			((uint32_t)0x00000006u)
#define CSL_SPI_SPIPC2_SCS0DIN6_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN6 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN6_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN6_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN5_MASK     			((uint32_t)0x00000020u)
#define CSL_SPI_SPIPC2_SCS0DIN5_SHIFT    			((uint32_t)0x00000005u)
#define CSL_SPI_SPIPC2_SCS0DIN5_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN5 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN5_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN5_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN4_MASK     			((uint32_t)0x00000010u)
#define CSL_SPI_SPIPC2_SCS0DIN4_SHIFT    			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC2_SCS0DIN4_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN4 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN4_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN4_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN3_MASK     			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC2_SCS0DIN3_SHIFT    			((uint32_t)0x00000003u)
#define CSL_SPI_SPIPC2_SCS0DIN3_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN3 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN3_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN3_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN2_MASK     			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC2_SCS0DIN2_SHIFT    			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC2_SCS0DIN2_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN2 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN2_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN2_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN1_MASK     			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC2_SCS0DIN1_SHIFT    			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC2_SCS0DIN1_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN1 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN1_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN1_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_SCS0DIN0_MASK     			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC2_SCS0DIN0_SHIFT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN0_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DIN0 Tokens----*/
#define CSL_SPI_SPIPC2_SCS0DIN0_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC2_SCS0DIN0_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC2_RESETVAL          			((uint32_t)0x00000000u)

/* SPIPC3 */


#define CSL_SPI_SPIPC3_SOMIDOUT_MASK     			((uint32_t)0x00000800u)
#define CSL_SPI_SPIPC3_SOMIDOUT_SHIFT    			((uint32_t)0x0000000Bu)
#define CSL_SPI_SPIPC3_SOMIDOUT_RESETVAL 			((uint32_t)0x00000000u)
/*----SOMIDOUT Tokens----*/
#define CSL_SPI_SPIPC3_SOMIDOUT_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SOMIDOUT_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SIMODOUT_MASK     			((uint32_t)0x00000400u)
#define CSL_SPI_SPIPC3_SIMODOUT_SHIFT    			((uint32_t)0x0000000Au)
#define CSL_SPI_SPIPC3_SIMODOUT_RESETVAL 			((uint32_t)0x00000000u)
/*----SIMODOUT Tokens----*/
#define CSL_SPI_SPIPC3_SIMODOUT_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SIMODOUT_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_CLKDOUT_MASK      			((uint32_t)0x00000200u)
#define CSL_SPI_SPIPC3_CLKDOUT_SHIFT     			((uint32_t)0x00000009u)
#define CSL_SPI_SPIPC3_CLKDOUT_RESETVAL  			((uint32_t)0x00000000u)
/*----CLKDOUT Tokens----*/
#define CSL_SPI_SPIPC3_CLKDOUT_LOW       			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_CLKDOUT_HIGH      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_ENADOUT_MASK      			((uint32_t)0x00000100u)
#define CSL_SPI_SPIPC3_ENADOUT_SHIFT     			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC3_ENADOUT_RESETVAL  			((uint32_t)0x00000000u)
/*----ENADOUT Tokens----*/
#define CSL_SPI_SPIPC3_ENADOUT_LOW       			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_ENADOUT_HIGH      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT7_MASK    			((uint32_t)0x00000080u)
#define CSL_SPI_SPIPC3_SCS0DOUT7_SHIFT   			((uint32_t)0x00000007u)
#define CSL_SPI_SPIPC3_SCS0DOUT7_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT7 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT7_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT7_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT6_MASK    			((uint32_t)0x00000040u)
#define CSL_SPI_SPIPC3_SCS0DOUT6_SHIFT   			((uint32_t)0x00000006u)
#define CSL_SPI_SPIPC3_SCS0DOUT6_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT6 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT6_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT6_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT5_MASK    			((uint32_t)0x00000020u)
#define CSL_SPI_SPIPC3_SCS0DOUT5_SHIFT   			((uint32_t)0x00000005u)
#define CSL_SPI_SPIPC3_SCS0DOUT5_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT5 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT5_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT5_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT4_MASK    			((uint32_t)0x00000010u)
#define CSL_SPI_SPIPC3_SCS0DOUT4_SHIFT   			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC3_SCS0DOUT4_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT4 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT4_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT4_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT3_MASK    			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC3_SCS0DOUT3_SHIFT   			((uint32_t)0x00000003u)
#define CSL_SPI_SPIPC3_SCS0DOUT3_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT3 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT3_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT3_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT2_MASK    			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC3_SCS0DOUT2_SHIFT   			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC3_SCS0DOUT2_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT2 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT2_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT2_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT1_MASK    			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC3_SCS0DOUT1_SHIFT   			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC3_SCS0DOUT1_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT1 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT1_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT1_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_SCS0DOUT0_MASK    			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC3_SCS0DOUT0_SHIFT   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT0_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0DOUT0 Tokens----*/
#define CSL_SPI_SPIPC3_SCS0DOUT0_LOW     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC3_SCS0DOUT0_HIGH    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC3_RESETVAL          			((uint32_t)0x00000000u)

/* SPIPC4 */


#define CSL_SPI_SPIPC4_SOMISET_MASK      			((uint32_t)0x00000800u)
#define CSL_SPI_SPIPC4_SOMISET_SHIFT     			((uint32_t)0x0000000Bu)
#define CSL_SPI_SPIPC4_SOMISET_RESETVAL  			((uint32_t)0x00000000u)
/*----SOMISET Tokens----*/
#define CSL_SPI_SPIPC4_SOMISET_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SOMISET_SET       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SIMOSET_MASK      			((uint32_t)0x00000400u)
#define CSL_SPI_SPIPC4_SIMOSET_SHIFT     			((uint32_t)0x0000000Au)
#define CSL_SPI_SPIPC4_SIMOSET_RESETVAL  			((uint32_t)0x00000000u)
/*----SIMOSET Tokens----*/
#define CSL_SPI_SPIPC4_SIMOSET_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SIMOSET_SET       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_CLKSET_MASK       			((uint32_t)0x00000200u)
#define CSL_SPI_SPIPC4_CLKSET_SHIFT      			((uint32_t)0x00000009u)
#define CSL_SPI_SPIPC4_CLKSET_RESETVAL   			((uint32_t)0x00000000u)
/*----CLKSET Tokens----*/
#define CSL_SPI_SPIPC4_CLKSET_NO_EFFECT  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_CLKSET_SET        			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_ENASET_MASK       			((uint32_t)0x00000100u)
#define CSL_SPI_SPIPC4_ENASET_SHIFT      			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC4_ENASET_RESETVAL   			((uint32_t)0x00000000u)
/*----ENASET Tokens----*/
#define CSL_SPI_SPIPC4_ENASET_NO_EFFECT  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_ENASET_SET        			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET7_MASK     			((uint32_t)0x00000080u)
#define CSL_SPI_SPIPC4_SCS0SET7_SHIFT    			((uint32_t)0x00000007u)
#define CSL_SPI_SPIPC4_SCS0SET7_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET7 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET7_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET7_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET6_MASK     			((uint32_t)0x00000040u)
#define CSL_SPI_SPIPC4_SCS0SET6_SHIFT    			((uint32_t)0x00000006u)
#define CSL_SPI_SPIPC4_SCS0SET6_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET6 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET6_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET6_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET5_MASK     			((uint32_t)0x00000020u)
#define CSL_SPI_SPIPC4_SCS0SET5_SHIFT    			((uint32_t)0x00000005u)
#define CSL_SPI_SPIPC4_SCS0SET5_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET5 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET5_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET5_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET4_MASK     			((uint32_t)0x00000010u)
#define CSL_SPI_SPIPC4_SCS0SET4_SHIFT    			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC4_SCS0SET4_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET4 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET4_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET4_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET3_MASK     			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC4_SCS0SET3_SHIFT    			((uint32_t)0x00000003u)
#define CSL_SPI_SPIPC4_SCS0SET3_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET3 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET3_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET3_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET2_MASK     			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC4_SCS0SET2_SHIFT    			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC4_SCS0SET2_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET2 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET2_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET2_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET1_MASK     			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC4_SCS0SET1_SHIFT    			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC4_SCS0SET1_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET1 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET1_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET1_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_SCS0SET0_MASK     			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC4_SCS0SET0_SHIFT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET0_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0SET0 Tokens----*/
#define CSL_SPI_SPIPC4_SCS0SET0_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC4_SCS0SET0_SET      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC4_RESETVAL          			((uint32_t)0x00000000u)

/* SPIPC5 */


#define CSL_SPI_SPIPC5_SOMICLR_MASK      			((uint32_t)0x00000800u)
#define CSL_SPI_SPIPC5_SOMICLR_SHIFT     			((uint32_t)0x0000000Bu)
#define CSL_SPI_SPIPC5_SOMICLR_RESETVAL  			((uint32_t)0x00000000u)
/*----SOMICLR Tokens----*/
#define CSL_SPI_SPIPC5_SOMICLR_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SOMICLR_CLEAR     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SIMOCLR_MASK      			((uint32_t)0x00000400u)
#define CSL_SPI_SPIPC5_SIMOCLR_SHIFT     			((uint32_t)0x0000000Au)
#define CSL_SPI_SPIPC5_SIMOCLR_RESETVAL  			((uint32_t)0x00000000u)
/*----SIMOCLR Tokens----*/
#define CSL_SPI_SPIPC5_SIMOCLR_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SIMOCLR_CLEAR     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_CLKCLR_MASK       			((uint32_t)0x00000200u)
#define CSL_SPI_SPIPC5_CLKCLR_SHIFT      			((uint32_t)0x00000009u)
#define CSL_SPI_SPIPC5_CLKCLR_RESETVAL   			((uint32_t)0x00000000u)
/*----CLKCLR Tokens----*/
#define CSL_SPI_SPIPC5_CLKCLR_NO_EFFECT  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_CLKCLR_CLEAR      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_ENACLR_MASK       			((uint32_t)0x00000100u)
#define CSL_SPI_SPIPC5_ENACLR_SHIFT      			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC5_ENACLR_RESETVAL   			((uint32_t)0x00000000u)
/*----ENACLR Tokens----*/
#define CSL_SPI_SPIPC5_ENACLR_NO_EFFECT  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_ENACLR_CLEAR      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR7_MASK     			((uint32_t)0x00000080u)
#define CSL_SPI_SPIPC5_SCS0CLR7_SHIFT    			((uint32_t)0x00000007u)
#define CSL_SPI_SPIPC5_SCS0CLR7_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR7 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR7_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR7_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR6_MASK     			((uint32_t)0x00000040u)
#define CSL_SPI_SPIPC5_SCS0CLR6_SHIFT    			((uint32_t)0x00000006u)
#define CSL_SPI_SPIPC5_SCS0CLR6_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR6 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR6_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR6_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR5_MASK     			((uint32_t)0x00000020u)
#define CSL_SPI_SPIPC5_SCS0CLR5_SHIFT    			((uint32_t)0x00000005u)
#define CSL_SPI_SPIPC5_SCS0CLR5_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR5 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR5_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR5_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR4_MASK     			((uint32_t)0x00000010u)
#define CSL_SPI_SPIPC5_SCS0CLR4_SHIFT    			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC5_SCS0CLR4_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR4 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR4_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR4_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR3_MASK     			((uint32_t)0x00000008u)
#define CSL_SPI_SPIPC5_SCS0CLR3_SHIFT    			((uint32_t)0x00000003u)
#define CSL_SPI_SPIPC5_SCS0CLR3_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR3 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR3_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR3_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR2_MASK     			((uint32_t)0x00000004u)
#define CSL_SPI_SPIPC5_SCS0CLR2_SHIFT    			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC5_SCS0CLR2_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR2 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR2_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR2_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR1_MASK     			((uint32_t)0x00000002u)
#define CSL_SPI_SPIPC5_SCS0CLR1_SHIFT    			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC5_SCS0CLR1_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR1 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR1_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR1_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_SCS0CLR0_MASK     			((uint32_t)0x00000001u)
#define CSL_SPI_SPIPC5_SCS0CLR0_SHIFT    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR0_RESETVAL 			((uint32_t)0x00000000u)
/*----SCS0CLR0 Tokens----*/
#define CSL_SPI_SPIPC5_SCS0CLR0_NO_EFFECT 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIPC5_SCS0CLR0_CLEAR    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIPC5_RESETVAL          			((uint32_t)0x00000000u)

/* SPIDAT0 */


#define CSL_SPI_SPIDAT0_TXDATA_MASK      			((uint32_t)0x0000FFFFu)
#define CSL_SPI_SPIDAT0_TXDATA_SHIFT     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDAT0_TXDATA_RESETVAL  			((uint32_t)0x00000000u)

#define CSL_SPI_SPIDAT0_RESETVAL         			((uint32_t)0x00000000u)

/* SPIDAT1 */


#define CSL_SPI_SPIDAT1_CSHOLD_MASK      			((uint32_t)0x10000000u)
#define CSL_SPI_SPIDAT1_CSHOLD_SHIFT     			((uint32_t)0x0000001Cu)
#define CSL_SPI_SPIDAT1_CSHOLD_RESETVAL  			((uint32_t)0x00000000u)
/*----CSHOLD Tokens----*/
#define CSL_SPI_SPIDAT1_CSHOLD_DISABLE   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDAT1_CSHOLD_ENABLE    			((uint32_t)0x00000001u)


#define CSL_SPI_SPIDAT1_WDEL_MASK        			((uint32_t)0x04000000u)
#define CSL_SPI_SPIDAT1_WDEL_SHIFT       			((uint32_t)0x0000001Au)
#define CSL_SPI_SPIDAT1_WDEL_RESETVAL    			((uint32_t)0x00000000u)
/*----WDEL Tokens----*/
#define CSL_SPI_SPIDAT1_WDEL_DISABLE     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDAT1_WDEL_ENABLE      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIDAT1_DFSEL_MASK       			((uint32_t)0x03000000u)
#define CSL_SPI_SPIDAT1_DFSEL_SHIFT      			((uint32_t)0x00000018u)
#define CSL_SPI_SPIDAT1_DFSEL_RESETVAL   			((uint32_t)0x00000000u)
/*----DFSEL Tokens----*/
#define CSL_SPI_SPIDAT1_DFSEL_FORMAT0    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDAT1_DFSEL_FORMAT1    			((uint32_t)0x00000001u)
#define CSL_SPI_SPIDAT1_DFSEL_FORMAT2    			((uint32_t)0x00000002u)
#define CSL_SPI_SPIDAT1_DFSEL_FORMAT3    			((uint32_t)0x00000003u)

#define CSL_SPI_SPIDAT1_CSNR_MASK        			((uint32_t)0x00FF0000u)
#define CSL_SPI_SPIDAT1_CSNR_SHIFT       			((uint32_t)0x00000010u)
#define CSL_SPI_SPIDAT1_CSNR_RESETVAL    			((uint32_t)0x00000000u)

#define CSL_SPI_SPIDAT1_TXDATA_MASK      			((uint32_t)0x0000FFFFu)
#define CSL_SPI_SPIDAT1_TXDATA_SHIFT     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDAT1_TXDATA_RESETVAL  			((uint32_t)0x00000000u)

#define CSL_SPI_SPIDAT1_RESETVAL         			((uint32_t)0x00000000u)

/* SPIBUF */

#define CSL_SPI_SPIBUF_RXEMPTY_MASK      			((uint32_t)0x80000000u)
#define CSL_SPI_SPIBUF_RXEMPTY_SHIFT     			((uint32_t)0x0000001Fu)
#define CSL_SPI_SPIBUF_RXEMPTY_RESETVAL  			((uint32_t)0x00000001u)
/*----RXEMPTY Tokens----*/
#define CSL_SPI_SPIBUF_RXEMPTY_NO_EMPTY  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_RXEMPTY_EMPTY     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIBUF_RXOVR_MASK        			((uint32_t)0x40000000u)
#define CSL_SPI_SPIBUF_RXOVR_SHIFT       			((uint32_t)0x0000001Eu)
#define CSL_SPI_SPIBUF_RXOVR_RESETVAL    			((uint32_t)0x00000000u)
/*----RXOVR Tokens----*/
#define CSL_SPI_SPIBUF_RXOVR_NO_ERROR    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_RXOVR_ERROR       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIBUF_TXFULL_MASK       			((uint32_t)0x20000000u)
#define CSL_SPI_SPIBUF_TXFULL_SHIFT      			((uint32_t)0x0000001Du)
#define CSL_SPI_SPIBUF_TXFULL_RESETVAL   			((uint32_t)0x00000000u)
/*----TXFULL Tokens----*/
#define CSL_SPI_SPIBUF_TXFULL_NO_FULL    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_TXFULL_FULL       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIBUF_BITERR_MASK       			((uint32_t)0x10000000u)
#define CSL_SPI_SPIBUF_BITERR_SHIFT      			((uint32_t)0x0000001Cu)
#define CSL_SPI_SPIBUF_BITERR_RESETVAL   			((uint32_t)0x00000000u)
/*----BITERR Tokens----*/
#define CSL_SPI_SPIBUF_BITERR_NO_ERROR   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_BITERR_ERROR      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIBUF_DESYNC_MASK       			((uint32_t)0x08000000u)
#define CSL_SPI_SPIBUF_DESYNC_SHIFT      			((uint32_t)0x0000001Bu)
#define CSL_SPI_SPIBUF_DESYNC_RESETVAL   			((uint32_t)0x00000000u)
/*----DESYNC Tokens----*/
#define CSL_SPI_SPIBUF_DESYNC_NO_ERROR   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_DESYNC_ERROR      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIBUF_PARERR_MASK       			((uint32_t)0x04000000u)
#define CSL_SPI_SPIBUF_PARERR_SHIFT      			((uint32_t)0x0000001Au)
#define CSL_SPI_SPIBUF_PARERR_RESETVAL   			((uint32_t)0x00000000u)
/*----PARERR Tokens----*/
#define CSL_SPI_SPIBUF_PARERR_NO_ERROR   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_PARERR_ERROR      			((uint32_t)0x00000001u)

#define CSL_SPI_SPIBUF_TIMEOUT_MASK      			((uint32_t)0x02000000u)
#define CSL_SPI_SPIBUF_TIMEOUT_SHIFT     			((uint32_t)0x00000019u)
#define CSL_SPI_SPIBUF_TIMEOUT_RESETVAL  			((uint32_t)0x00000000u)
/*----TIMEOUT Tokens----*/
#define CSL_SPI_SPIBUF_TIMEOUT_NO_ERROR  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_TIMEOUT_ERROR     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIBUF_DLENERR_MASK      			((uint32_t)0x01000000u)
#define CSL_SPI_SPIBUF_DLENERR_SHIFT     			((uint32_t)0x00000018u)
#define CSL_SPI_SPIBUF_DLENERR_RESETVAL  			((uint32_t)0x00000000u)
/*----DLENERR Tokens----*/
#define CSL_SPI_SPIBUF_DLENERR_NO_ERROR  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_DLENERR_ERROR     			((uint32_t)0x00000001u)


#define CSL_SPI_SPIBUF_RXDATA_MASK       			((uint32_t)0x0000FFFFu)
#define CSL_SPI_SPIBUF_RXDATA_SHIFT      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIBUF_RXDATA_RESETVAL   			((uint32_t)0x00000000u)

#define CSL_SPI_SPIBUF_RESETVAL          			((uint32_t)0x80000000u)

/* SPIEMU */


#define CSL_SPI_SPIEMU_RXDATA_MASK       			((uint32_t)0x0000FFFFu)
#define CSL_SPI_SPIEMU_RXDATA_SHIFT      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIEMU_RXDATA_RESETVAL   			((uint32_t)0x00000000u)

#define CSL_SPI_SPIEMU_RESETVAL          			((uint32_t)0x00000000u)

/* SPIDELAY */

#define CSL_SPI_SPIDELAY_C2TDELAY_MASK   			((uint32_t)0xFF000000u)
#define CSL_SPI_SPIDELAY_C2TDELAY_SHIFT  			((uint32_t)0x00000018u)
#define CSL_SPI_SPIDELAY_C2TDELAY_RESETVAL 			((uint32_t)0x00000000u)

#define CSL_SPI_SPIDELAY_T2CDELAY_MASK   			((uint32_t)0x00FF0000u)
#define CSL_SPI_SPIDELAY_T2CDELAY_SHIFT  			((uint32_t)0x00000010u)
#define CSL_SPI_SPIDELAY_T2CDELAY_RESETVAL 			((uint32_t)0x00000000u)

#define CSL_SPI_SPIDELAY_T2EDELAY_MASK   			((uint32_t)0x0000FF00u)
#define CSL_SPI_SPIDELAY_T2EDELAY_SHIFT  			((uint32_t)0x00000008u)
#define CSL_SPI_SPIDELAY_T2EDELAY_RESETVAL 			((uint32_t)0x00000000u)

#define CSL_SPI_SPIDELAY_C2EDELAY_MASK   			((uint32_t)0x000000FFu)
#define CSL_SPI_SPIDELAY_C2EDELAY_SHIFT  			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDELAY_C2EDELAY_RESETVAL 			((uint32_t)0x00000000u)

#define CSL_SPI_SPIDELAY_RESETVAL        			((uint32_t)0x00000000u)

/* SPIDEF */


#define CSL_SPI_SPIDEF_CSDEF0_MASK       			((uint32_t)0x00000001u)
#define CSL_SPI_SPIDEF_CSDEF0_SHIFT      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDEF_CSDEF0_RESETVAL   			((uint32_t)0x00000001u)
/*----CSDEF0 Tokens----*/
#define CSL_SPI_SPIDEF_CSDEF0_LOW        			((uint32_t)0x00000000u)
#define CSL_SPI_SPIDEF_CSDEF0_HIGH       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIDEF_RESETVAL          			((uint32_t)0x00000001u)

/* SPIFMT */


#define CSL_SPI_SPIFMT_WDELAY_MASK       			((uint32_t)0x3F000000u)
#define CSL_SPI_SPIFMT_WDELAY_SHIFT      			((uint32_t)0x00000018u)
#define CSL_SPI_SPIFMT_WDELAY_RESETVAL   			((uint32_t)0x00000000u)

#define CSL_SPI_SPIFMT_PARPOL_MASK       			((uint32_t)0x00800000u)
#define CSL_SPI_SPIFMT_PARPOL_SHIFT      			((uint32_t)0x00000017u)
#define CSL_SPI_SPIFMT_PARPOL_RESETVAL   			((uint32_t)0x00000000u)
/*----PARPOL Tokens----*/
#define CSL_SPI_SPIFMT_PARPOL_EVEN       			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_PARPOL_ODD        			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFMT_PARENA_MASK       			((uint32_t)0x00400000u)
#define CSL_SPI_SPIFMT_PARENA_SHIFT      			((uint32_t)0x00000016u)
#define CSL_SPI_SPIFMT_PARENA_RESETVAL   			((uint32_t)0x00000000u)
/*----PARENA Tokens----*/
#define CSL_SPI_SPIFMT_PARENA_DISABLE    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_PARENA_ENABLE     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFMT_WAITENA_MASK      			((uint32_t)0x00200000u)
#define CSL_SPI_SPIFMT_WAITENA_SHIFT     			((uint32_t)0x00000015u)
#define CSL_SPI_SPIFMT_WAITENA_RESETVAL  			((uint32_t)0x00000000u)
/*----WAITENA Tokens----*/
#define CSL_SPI_SPIFMT_WAITENA_DISABLE   			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_WAITENA_ENABLE    			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFMT_SHIFTDIR_MASK     			((uint32_t)0x00100000u)
#define CSL_SPI_SPIFMT_SHIFTDIR_SHIFT    			((uint32_t)0x00000014u)
#define CSL_SPI_SPIFMT_SHIFTDIR_RESETVAL 			((uint32_t)0x00000000u)
/*----SHIFTDIR Tokens----*/
#define CSL_SPI_SPIFMT_SHIFTDIR_MSB      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_SHIFTDIR_LSB      			((uint32_t)0x00000001u)


#define CSL_SPI_SPIFMT_DISCSTIMERS_MASK  			((uint32_t)0x00040000u)
#define CSL_SPI_SPIFMT_DISCSTIMERS_SHIFT 			((uint32_t)0x00000012u)
#define CSL_SPI_SPIFMT_DISCSTIMERS_RESETVAL 			((uint32_t)0x00000000u)
/*----DISCSTIMERS Tokens----*/
#define CSL_SPI_SPIFMT_DISCSTIMERS_DISABLE 			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_DISCSTIMERS_ENABLE 			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFMT_POLARITY_MASK     			((uint32_t)0x00020000u)
#define CSL_SPI_SPIFMT_POLARITY_SHIFT    			((uint32_t)0x00000011u)
#define CSL_SPI_SPIFMT_POLARITY_RESETVAL 			((uint32_t)0x00000000u)
/*----POLARITY Tokens----*/
#define CSL_SPI_SPIFMT_POLARITY_LOW      			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_POLARITY_HIGH     			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFMT_PHASE_MASK        			((uint32_t)0x00010000u)
#define CSL_SPI_SPIFMT_PHASE_SHIFT       			((uint32_t)0x00000010u)
#define CSL_SPI_SPIFMT_PHASE_RESETVAL    			((uint32_t)0x00000000u)
/*----PHASE Tokens----*/
#define CSL_SPI_SPIFMT_PHASE_NO_DELAY    			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_PHASE_DELAY       			((uint32_t)0x00000001u)

#define CSL_SPI_SPIFMT_PRESCALE_MASK     			((uint32_t)0x0000FF00u)
#define CSL_SPI_SPIFMT_PRESCALE_SHIFT    			((uint32_t)0x00000008u)
#define CSL_SPI_SPIFMT_PRESCALE_RESETVAL 			((uint32_t)0x00000000u)


#define CSL_SPI_SPIFMT_CHARLEN_MASK      			((uint32_t)0x0000001Fu)
#define CSL_SPI_SPIFMT_CHARLEN_SHIFT     			((uint32_t)0x00000000u)
#define CSL_SPI_SPIFMT_CHARLEN_RESETVAL  			((uint32_t)0x00000000u)

#define CSL_SPI_SPIFMT_RESETVAL          			((uint32_t)0x00000000u)

/* INTVEC */


#define CSL_SPI_INTVEC_INTVECT_MASK      			((uint32_t)0x0000003Eu)
#define CSL_SPI_INTVEC_INTVECT_SHIFT     			((uint32_t)0x00000001u)
#define CSL_SPI_INTVEC_INTVECT_RESETVAL  			((uint32_t)0x00000000u)


#define CSL_SPI_INTVEC_RESETVAL                                 ((uint32_t)0x00000000u)
/* SPISRSEL */

#define CSL_SPI_SPISRSEL_SCS9PSRS_SHIFT                         ((uint32_t)0u)
#define CSL_SPI_SPISRSEL_SCS9PSRS_MASK                          ((uint32_t)0x000000FFu)
#define CSL_SPI_SPISRSEL_SCS9PSRS_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_SPI_SPISRSEL_SCS9PSRS_MAX                           ((uint32_t)0x000000ffu)

#define CSL_SPI_SPISRSEL_ENAPSRS_SHIFT                          ((uint32_t)8u)
#define CSL_SPI_SPISRSEL_ENAPSRS_MASK                           ((uint32_t)0x00000100u)
#define CSL_SPI_SPISRSEL_ENAPSRS_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPISRSEL_ENAPSRS_MAX                            ((uint32_t)0x00000001u)

#define CSL_SPI_SPISRSEL_CLKPSRS_SHIFT                          ((uint32_t)9u)
#define CSL_SPI_SPISRSEL_CLKPSRS_MASK                           ((uint32_t)0x00000200u)
#define CSL_SPI_SPISRSEL_CLKPSRS_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPISRSEL_CLKPSRS_MAX                            ((uint32_t)0x00000001u)

#define CSL_SPI_SPISRSEL_SOMIPSRS_SHIFT                         ((uint32_t)10u)
#define CSL_SPI_SPISRSEL_SOMIPSRS_MASK                          ((uint32_t)0x00000400u)
#define CSL_SPI_SPISRSEL_SOMIPSRS_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_SPI_SPISRSEL_SOMIPSRS_MAX                           ((uint32_t)0x00000001u)

#define CSL_SPI_SPISRSEL_SOMOPSRS_SHIFT                         ((uint32_t)11u)
#define CSL_SPI_SPISRSEL_SOMOPSRS_MASK                          ((uint32_t)0x00000800u)
#define CSL_SPI_SPISRSEL_SOMOPSRS_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_SPI_SPISRSEL_SOMOPSRS_MAX                           ((uint32_t)0x00000001u)

#define CSL_SPI_SPISRSEL_SOMO9PSRS_SHIFT                        ((uint32_t)16u)
#define CSL_SPI_SPISRSEL_SOMO9PSRS_MASK                         ((uint32_t)0x00FF0000u)
#define CSL_SPI_SPISRSEL_SOMO9PSRS_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_SPI_SPISRSEL_SOMO9PSRS_MAX                          ((uint32_t)0x000000ffu)

#define CSL_SPI_SPISRSEL_SOMI9PSRS_SHIFT                        ((uint32_t)24u)
#define CSL_SPI_SPISRSEL_SOMI9PSRS_MASK                         ((uint32_t)0xFF000000u)
#define CSL_SPI_SPISRSEL_SOMI9PSRS_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_SPI_SPISRSEL_SOMI9PSRS_MAX                          ((uint32_t)0x000000ffu)

#define CSL_SPI_SPISRSEL_RESETVAL                               ((uint32_t)0x00000000u)

/* SPIPMCTRL */

#define CSL_SPI_SPIPMCTRL_PMODE0_SHIFT                          ((uint32_t)0u)
#define CSL_SPI_SPIPMCTRL_PMODE0_MASK                           ((uint32_t)0x00000003u)
#define CSL_SPI_SPIPMCTRL_PMODE0_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_PMODE0_MAX                            ((uint32_t)0x00000003u)

#define CSL_SPI_SPIPMCTRL_MMODE0_SHIFT                          ((uint32_t)2u)
#define CSL_SPI_SPIPMCTRL_MMODE0_MASK                           ((uint32_t)0x0000001Cu)
#define CSL_SPI_SPIPMCTRL_MMODE0_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MMODE0_MAX                            ((uint32_t)0x00000007u)

#define CSL_SPI_SPIPMCTRL_MODECLKPOL0_SHIFT                     ((uint32_t)5u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL0_MASK                      ((uint32_t)0x00000020u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL0_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL0_MAX                       ((uint32_t)0x00000001u)

#define CSL_SPI_SPIPMCTRL_PMODE1_SHIFT                          ((uint32_t)8u)
#define CSL_SPI_SPIPMCTRL_PMODE1_MASK                           ((uint32_t)0x00000300u)
#define CSL_SPI_SPIPMCTRL_PMODE1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_PMODE1_MAX                            ((uint32_t)0x00000003u)

#define CSL_SPI_SPIPMCTRL_MMODE1_SHIFT                          ((uint32_t)10u)
#define CSL_SPI_SPIPMCTRL_MMODE1_MASK                           ((uint32_t)0x00001C00u)
#define CSL_SPI_SPIPMCTRL_MMODE1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MMODE1_MAX                            ((uint32_t)0x00000007u)

#define CSL_SPI_SPIPMCTRL_MODECLKPOL1_SHIFT                     ((uint32_t)13u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL1_MASK                      ((uint32_t)0x00002000u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL1_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL1_MAX                       ((uint32_t)0x00000001u)

#define CSL_SPI_SPIPMCTRL_PMODE2_SHIFT                          ((uint32_t)16u)
#define CSL_SPI_SPIPMCTRL_PMODE2_MASK                           ((uint32_t)0x00030000u)
#define CSL_SPI_SPIPMCTRL_PMODE2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_PMODE2_MAX                            ((uint32_t)0x00000003u)

#define CSL_SPI_SPIPMCTRL_MMODE2_SHIFT                          ((uint32_t)18u)
#define CSL_SPI_SPIPMCTRL_MMODE2_MASK                           ((uint32_t)0x001C0000u)
#define CSL_SPI_SPIPMCTRL_MMODE2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MMODE2_MAX                            ((uint32_t)0x00000007u)

#define CSL_SPI_SPIPMCTRL_MODECLKPOL2_SHIFT                     ((uint32_t)21u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL2_MASK                      ((uint32_t)0x00200000u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL2_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL2_MAX                       ((uint32_t)0x00000001u)

#define CSL_SPI_SPIPMCTRL_PMODE3_SHIFT                          ((uint32_t)24u)
#define CSL_SPI_SPIPMCTRL_PMODE3_MASK                           ((uint32_t)0x03000000u)
#define CSL_SPI_SPIPMCTRL_PMODE3_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_PMODE3_MAX                            ((uint32_t)0x00000003u)

#define CSL_SPI_SPIPMCTRL_MMODE3_SHIFT                          ((uint32_t)26u)
#define CSL_SPI_SPIPMCTRL_MMODE3_MASK                           ((uint32_t)0x1C000000u)
#define CSL_SPI_SPIPMCTRL_MMODE3_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MMODE3_MAX                            ((uint32_t)0x00000007u)

#define CSL_SPI_SPIPMCTRL_MODECLKPOL3_SHIFT                     ((uint32_t)29u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL3_MASK                      ((uint32_t)0x20000000u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL3_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_SPIPMCTRL_MODECLKPOL3_MAX                       ((uint32_t)0x00000001u)

#define CSL_SPI_SPIPMCTRL_RESETVAL                              ((uint32_t)0x00000000u)

/* MIBSPIE */

#define CSL_SPI_MIBSPIE_MSPIENA_SHIFT                           ((uint32_t)0u)
#define CSL_SPI_MIBSPIE_MSPIENA_MASK                            ((uint32_t)0x00000001u)
#define CSL_SPI_MIBSPIE_MSPIENA_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_SPI_MIBSPIE_MSPIENA_MAX                             ((uint32_t)0x00000001u)

#define CSL_SPI_MIBSPIE_RXRAMACCESS_SHIFT                       ((uint32_t)16u)
#define CSL_SPI_MIBSPIE_RXRAMACCESS_MASK                        ((uint32_t)0x00010000u)
#define CSL_SPI_MIBSPIE_RXRAMACCESS_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_SPI_MIBSPIE_RXRAMACCESS_MAX                         ((uint32_t)0x00000001u)

#define CSL_SPI_MIBSPIE_RESETVAL                                ((uint32_t)0x00000000u)

/* TGITENST */

#define CSL_SPI_TGITENST_SETINTENSUS_SHIFT                      ((uint32_t)0u)
#define CSL_SPI_TGITENST_SETINTENSUS_MASK                       ((uint32_t)0x0000FFFFu)
#define CSL_SPI_TGITENST_SETINTENSUS_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_SPI_TGITENST_SETINTENSUS_MAX                        ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITENST_SETINTENRDY_SHIFT                      ((uint32_t)16u)
#define CSL_SPI_TGITENST_SETINTENRDY_MASK                       ((uint32_t)0xFFFF0000u)
#define CSL_SPI_TGITENST_SETINTENRDY_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_SPI_TGITENST_SETINTENRDY_MAX                        ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITENST_RESETVAL                               ((uint32_t)0x00000000u)

/* TGITENCR */

#define CSL_SPI_TGITENCR_CLRINTENSUS_SHIFT                      ((uint32_t)0u)
#define CSL_SPI_TGITENCR_CLRINTENSUS_MASK                       ((uint32_t)0x0000FFFFu)
#define CSL_SPI_TGITENCR_CLRINTENSUS_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_SPI_TGITENCR_CLRINTENSUS_MAX                        ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITENCR_CLRINTENRDY_SHIFT                      ((uint32_t)16u)
#define CSL_SPI_TGITENCR_CLRINTENRDY_MASK                       ((uint32_t)0xFFFF0000u)
#define CSL_SPI_TGITENCR_CLRINTENRDY_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_SPI_TGITENCR_CLRINTENRDY_MAX                        ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITENCR_RESETVAL                               ((uint32_t)0x00000000u)

/* TGITLVST */

#define CSL_SPI_TGITLVST_SETINTLVLSUS_SHIFT                     ((uint32_t)0u)
#define CSL_SPI_TGITLVST_SETINTLVLSUS_MASK                      ((uint32_t)0x0000FFFFu)
#define CSL_SPI_TGITLVST_SETINTLVLSUS_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_TGITLVST_SETINTLVLSUS_MAX                       ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITLVST_SETINTLVLRDY_SHIFT                     ((uint32_t)16u)
#define CSL_SPI_TGITLVST_SETINTLVLRDY_MASK                      ((uint32_t)0xFFFF0000u)
#define CSL_SPI_TGITLVST_SETINTLVLRDY_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_TGITLVST_SETINTLVLRDY_MAX                       ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITLVST_RESETVAL                               ((uint32_t)0x00000000u)

/* TGITLVCR */

#define CSL_SPI_TGITLVCR_CLRINTLVLSUS_SHIFT                     ((uint32_t)0u)
#define CSL_SPI_TGITLVCR_CLRINTLVLSUS_MASK                      ((uint32_t)0x0000FFFFu)
#define CSL_SPI_TGITLVCR_CLRINTLVLSUS_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_TGITLVCR_CLRINTLVLSUS_MAX                       ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITLVCR_CLRINTLVLRDY_SHIFT                     ((uint32_t)16u)
#define CSL_SPI_TGITLVCR_CLRINTLVLRDY_MASK                      ((uint32_t)0xFFFF0000u)
#define CSL_SPI_TGITLVCR_CLRINTLVLRDY_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_TGITLVCR_CLRINTLVLRDY_MAX                       ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGITLVCR_RESETVAL                               ((uint32_t)0x00000000u)

/* TGINTFLAG */

#define CSL_SPI_TGINTFLAG_TICKVALUE_SHIFT                       ((uint32_t)0u)
#define CSL_SPI_TGINTFLAG_TICKVALUE_MASK                        ((uint32_t)0x0000FFFFu)
#define CSL_SPI_TGINTFLAG_TICKVALUE_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_SPI_TGINTFLAG_TICKVALUE_MAX                         ((uint32_t)0x0000ffffu)

#define CSL_SPI_TGINTFLAG_CLKCTRL_SHIFT                         ((uint32_t)28u)
#define CSL_SPI_TGINTFLAG_CLKCTRL_MASK                          ((uint32_t)0x30000000u)
#define CSL_SPI_TGINTFLAG_CLKCTRL_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_SPI_TGINTFLAG_CLKCTRL_MAX                           ((uint32_t)0x00000003u)

#define CSL_SPI_TGINTFLAG_RELOAD_SHIFT                          ((uint32_t)30u)
#define CSL_SPI_TGINTFLAG_RELOAD_MASK                           ((uint32_t)0x40000000u)
#define CSL_SPI_TGINTFLAG_RELOAD_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_TGINTFLAG_RELOAD_MAX                            ((uint32_t)0x00000001u)

#define CSL_SPI_TGINTFLAG_TICKEN_SHIFT                          ((uint32_t)31u)
#define CSL_SPI_TGINTFLAG_TICKEN_MASK                           ((uint32_t)0x80000000u)
#define CSL_SPI_TGINTFLAG_TICKEN_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_TGINTFLAG_TICKEN_MAX                            ((uint32_t)0x00000001u)

#define CSL_SPI_TGINTFLAG_RESETVAL                              ((uint32_t)0x00000000u)

/* LTGPEND */

#define CSL_SPI_LTGPEND_LPEND_SHIFT                             ((uint32_t)8u)
#define CSL_SPI_LTGPEND_LPEND_MASK                              ((uint32_t)0x00007F00u)
#define CSL_SPI_LTGPEND_LPEND_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_LTGPEND_LPEND_MAX                               ((uint32_t)0x0000007fu)

#define CSL_SPI_LTGPEND_TGINSERVICE_SHIFT                       ((uint32_t)24u)
#define CSL_SPI_LTGPEND_TGINSERVICE_MASK                        ((uint32_t)0x1F000000u)
#define CSL_SPI_LTGPEND_TGINSERVICE_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_SPI_LTGPEND_TGINSERVICE_MAX                         ((uint32_t)0x0000001fu)

#define CSL_SPI_LTGPEND_RESETVAL                                ((uint32_t)0x00000000u)

/* TGCTRL */

#define CSL_SPI_TGCTRL_PCURRENT_SHIFT                           ((uint32_t)0u)
#define CSL_SPI_TGCTRL_PCURRENT_MASK                            ((uint32_t)0x0000007Fu)
#define CSL_SPI_TGCTRL_PCURRENT_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_PCURRENT_MAX                             ((uint32_t)0x0000007fu)

#define CSL_SPI_TGCTRL_PSTART_SHIFT                             ((uint32_t)8u)
#define CSL_SPI_TGCTRL_PSTART_MASK                              ((uint32_t)0x00007F00u)
#define CSL_SPI_TGCTRL_PSTART_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_PSTART_MAX                               ((uint32_t)0x0000007fu)

#define CSL_SPI_TGCTRL_TRIGSRC_SHIFT                            ((uint32_t)16u)
#define CSL_SPI_TGCTRL_TRIGSRC_MASK                             ((uint32_t)0x000F0000u)
#define CSL_SPI_TGCTRL_TRIGSRC_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_TRIGSRC_MAX                              ((uint32_t)0x0000000fu)

#define CSL_SPI_TGCTRL_TRGEVT_SHIFT                             ((uint32_t)20u)
#define CSL_SPI_TGCTRL_TRGEVT_MASK                              ((uint32_t)0x00F00000u)
#define CSL_SPI_TGCTRL_TRGEVT_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_TRGEVT_MAX                               ((uint32_t)0x0000000fu)

#define CSL_SPI_TGCTRL_TGTD_SHIFT                               ((uint32_t)28u)
#define CSL_SPI_TGCTRL_TGTD_MASK                                ((uint32_t)0x10000000u)
#define CSL_SPI_TGCTRL_TGTD_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_TGTD_MAX                                 ((uint32_t)0x00000001u)

#define CSL_SPI_TGCTRL_PRST_SHIFT                               ((uint32_t)29u)
#define CSL_SPI_TGCTRL_PRST_MASK                                ((uint32_t)0x20000000u)
#define CSL_SPI_TGCTRL_PRST_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_PRST_MAX                                 ((uint32_t)0x00000001u)

#define CSL_SPI_TGCTRL_ONESHOT_SHIFT                            ((uint32_t)30u)
#define CSL_SPI_TGCTRL_ONESHOT_MASK                             ((uint32_t)0x40000000u)
#define CSL_SPI_TGCTRL_ONESHOT_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_ONESHOT_MAX                              ((uint32_t)0x00000001u)

#define CSL_SPI_TGCTRL_TGENA_SHIFT                              ((uint32_t)31u)
#define CSL_SPI_TGCTRL_TGENA_MASK                               ((uint32_t)0x80000000u)
#define CSL_SPI_TGCTRL_TGENA_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_SPI_TGCTRL_TGENA_MAX                                ((uint32_t)0x00000001u)

#define CSL_SPI_TGCTRL_RESETVAL                                 ((uint32_t)0x00000000u)

/* DMACTRL */

#define CSL_SPI_DMACTRL_COUNT_SHIFT                             ((uint32_t)0u)
#define CSL_SPI_DMACTRL_COUNT_MASK                              ((uint32_t)0x0000003Fu)
#define CSL_SPI_DMACTRL_COUNT_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_COUNT_MAX                               ((uint32_t)0x0000003fu)

#define CSL_SPI_DMACTRL_COUNTBIT17_SHIFT                        ((uint32_t)6u)
#define CSL_SPI_DMACTRL_COUNTBIT17_MASK                         ((uint32_t)0x00000040u)
#define CSL_SPI_DMACTRL_COUNTBIT17_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_COUNTBIT17_MAX                          ((uint32_t)0x00000001u)

#define CSL_SPI_DMACTRL_ICOUNT_SHIFT                            ((uint32_t)8u)
#define CSL_SPI_DMACTRL_ICOUNT_MASK                             ((uint32_t)0x00001F00u)
#define CSL_SPI_DMACTRL_ICOUNT_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_ICOUNT_MAX                              ((uint32_t)0x0000001fu)

#define CSL_SPI_DMACTRL_NOBRK_SHIFT                             ((uint32_t)13u)
#define CSL_SPI_DMACTRL_NOBRK_MASK                              ((uint32_t)0x00002000u)
#define CSL_SPI_DMACTRL_NOBRK_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_NOBRK_MAX                               ((uint32_t)0x00000001u)

#define CSL_SPI_DMACTRL_TXDMAENA_SHIFT                          ((uint32_t)14u)
#define CSL_SPI_DMACTRL_TXDMAENA_MASK                           ((uint32_t)0x00004000u)
#define CSL_SPI_DMACTRL_TXDMAENA_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_TXDMAENA_MAX                            ((uint32_t)0x00000001u)

#define CSL_SPI_DMACTRL_RXDMAENA_SHIFT                          ((uint32_t)15u)
#define CSL_SPI_DMACTRL_RXDMAENA_MASK                           ((uint32_t)0x00008000u)
#define CSL_SPI_DMACTRL_RXDMAENA_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_RXDMAENA_MAX                            ((uint32_t)0x00000001u)

#define CSL_SPI_DMACTRL_TXDMA_MAP_SHIFT                         ((uint32_t)16u)
#define CSL_SPI_DMACTRL_TXDMA_MAP_MASK                          ((uint32_t)0x000F0000u)
#define CSL_SPI_DMACTRL_TXDMA_MAP_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_TXDMA_MAP_MAX                           ((uint32_t)0x0000000fu)

#define CSL_SPI_DMACTRL_RXDMA_MAP_SHIFT                         ((uint32_t)20u)
#define CSL_SPI_DMACTRL_RXDMA_MAP_MASK                          ((uint32_t)0x00F00000u)
#define CSL_SPI_DMACTRL_RXDMA_MAP_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_RXDMA_MAP_MAX                           ((uint32_t)0x0000000fu)

#define CSL_SPI_DMACTRL_BUFID_SHIFT                             ((uint32_t)24u)
#define CSL_SPI_DMACTRL_BUFID_MASK                              ((uint32_t)0x7F000000u)
#define CSL_SPI_DMACTRL_BUFID_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_BUFID_MAX                               ((uint32_t)0x0000007fu)

#define CSL_SPI_DMACTRL_ONESHOT_SHIFT                           ((uint32_t)31u)
#define CSL_SPI_DMACTRL_ONESHOT_MASK                            ((uint32_t)0x80000000u)
#define CSL_SPI_DMACTRL_ONESHOT_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_SPI_DMACTRL_ONESHOT_MAX                             ((uint32_t)0x00000001u)

#define CSL_SPI_DMACTRL_RESETVAL                                ((uint32_t)0x00000000u)

/* DMACOUNT */

#define CSL_SPI_DMACOUNT_COUNT_SHIFT                            ((uint32_t)0u)
#define CSL_SPI_DMACOUNT_COUNT_MASK                             ((uint32_t)0x0000FFFFu)
#define CSL_SPI_DMACOUNT_COUNT_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_SPI_DMACOUNT_COUNT_MAX                              ((uint32_t)0x0000ffffu)

#define CSL_SPI_DMACOUNT_ICOUNT_SHIFT                           ((uint32_t)16u)
#define CSL_SPI_DMACOUNT_ICOUNT_MASK                            ((uint32_t)0xFFFF0000u)
#define CSL_SPI_DMACOUNT_ICOUNT_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_SPI_DMACOUNT_ICOUNT_MAX                             ((uint32_t)0x0000ffffu)

#define CSL_SPI_DMACOUNT_RESETVAL                               ((uint32_t)0x00000000u)

/* DMA0CNTL */

#define CSL_SPI_DMA0CNTL_LARGECOUNT_SHIFT                       ((uint32_t)0u)
#define CSL_SPI_DMA0CNTL_LARGECOUNT_MASK                        ((uint32_t)0x00000001u)
#define CSL_SPI_DMA0CNTL_LARGECOUNT_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_SPI_DMA0CNTL_LARGECOUNT_MAX                         ((uint32_t)0x00000001u)

#define CSL_SPI_DMA0CNTL_RESETVAL                               ((uint32_t)0x00000000u)

/* UERRCTRL */

#define CSL_SPI_UERRCTRL_EDEN_SHIFT                             ((uint32_t)0u)
#define CSL_SPI_UERRCTRL_EDEN_MASK                              ((uint32_t)0x0000000Fu)
#define CSL_SPI_UERRCTRL_EDEN_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_UERRCTRL_EDEN_MAX                               ((uint32_t)0x0000000fu)

#define CSL_SPI_UERRCTRL_PTESTEN_SHIFT                          ((uint32_t)8u)
#define CSL_SPI_UERRCTRL_PTESTEN_MASK                           ((uint32_t)0x00000100u)
#define CSL_SPI_UERRCTRL_PTESTEN_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_SPI_UERRCTRL_PTESTEN_MAX                            ((uint32_t)0x00000001u)

#define CSL_SPI_UERRCTRL_RESETVAL                               ((uint32_t)0x00000000u)

/* UERRSTAT */

#define CSL_SPI_UERRSTAT_EDFLG0_SHIFT                           ((uint32_t)0u)
#define CSL_SPI_UERRSTAT_EDFLG0_MASK                            ((uint32_t)0x00000001u)
#define CSL_SPI_UERRSTAT_EDFLG0_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_SPI_UERRSTAT_EDFLG0_MAX                             ((uint32_t)0x00000001u)

#define CSL_SPI_UERRSTAT_EDFLG1_SHIFT                           ((uint32_t)1u)
#define CSL_SPI_UERRSTAT_EDFLG1_MASK                            ((uint32_t)0x00000002u)
#define CSL_SPI_UERRSTAT_EDFLG1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_SPI_UERRSTAT_EDFLG1_MAX                             ((uint32_t)0x00000001u)

#define CSL_SPI_UERRSTAT_RESETVAL                               ((uint32_t)0x00000000u)

/* UERRADDR1 */

#define CSL_SPI_UERRADDR1_UERRADDR1_SHIFT                       ((uint32_t)0u)
#define CSL_SPI_UERRADDR1_UERRADDR1_MASK                        ((uint32_t)0x000003FFu)
#define CSL_SPI_UERRADDR1_UERRADDR1_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_SPI_UERRADDR1_UERRADDR1_MAX                         ((uint32_t)0x000003ffu)

#define CSL_SPI_UERRADDR1_RESETVAL                              ((uint32_t)0x00000000u)

/* UERRADDR0 */

#define CSL_SPI_UERRADDR0_UERRADDR0_SHIFT                       ((uint32_t)0u)
#define CSL_SPI_UERRADDR0_UERRADDR0_MASK                        ((uint32_t)0x000001FFu)
#define CSL_SPI_UERRADDR0_UERRADDR0_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_SPI_UERRADDR0_UERRADDR0_MAX                         ((uint32_t)0x000001ffu)

#define CSL_SPI_UERRADDR0_RESETVAL                              ((uint32_t)0x00000000u)

/* RXOVRN_BUF_ADDR */

#define CSL_SPI_RXOVRN_BUF_ADDR_RXOVRN_BUF_ADDR_SHIFT           ((uint32_t)0u)
#define CSL_SPI_RXOVRN_BUF_ADDR_RXOVRN_BUF_ADDR_MASK            ((uint32_t)0x000003FFu)
#define CSL_SPI_RXOVRN_BUF_ADDR_RXOVRN_BUF_ADDR_RESETVAL        ((uint32_t)0x00000000u)
#define CSL_SPI_RXOVRN_BUF_ADDR_RXOVRN_BUF_ADDR_MAX             ((uint32_t)0x000003ffu)

#define CSL_SPI_RXOVRN_BUF_ADDR_RESETVAL                        ((uint32_t)0x00000000u)

/* IOLPBKTSTCR */

#define CSL_SPI_IOLPBKTSTCR_RXPENA_SHIFT                        ((uint32_t)0u)
#define CSL_SPI_IOLPBKTSTCR_RXPENA_MASK                         ((uint32_t)0x00000001u)
#define CSL_SPI_IOLPBKTSTCR_RXPENA_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_RXPENA_MAX                          ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_LPBKTYPE_SHIFT                      ((uint32_t)1u)
#define CSL_SPI_IOLPBKTSTCR_LPBKTYPE_MASK                       ((uint32_t)0x00000002u)
#define CSL_SPI_IOLPBKTSTCR_LPBKTYPE_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_LPBKTYPE_MAX                        ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_CTRLSCSPINERR_SHIFT                 ((uint32_t)2u)
#define CSL_SPI_IOLPBKTSTCR_CTRLSCSPINERR_MASK                  ((uint32_t)0x00000004u)
#define CSL_SPI_IOLPBKTSTCR_CTRLSCSPINERR_RESETVAL              ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLSCSPINERR_MAX                   ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_ERRSCSPIN_SHIFT                     ((uint32_t)3u)
#define CSL_SPI_IOLPBKTSTCR_ERRSCSPIN_MASK                      ((uint32_t)0x00000078u)
#define CSL_SPI_IOLPBKTSTCR_ERRSCSPIN_RESETVAL                  ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_ERRSCSPIN_MAX                       ((uint32_t)0x0000000fu)

#define CSL_SPI_IOLPBKTSTCR_IPLPBKTSTENA_SHIFT                  ((uint32_t)8u)
#define CSL_SPI_IOLPBKTSTCR_IPLPBKTSTENA_MASK                   ((uint32_t)0x00000F00u)
#define CSL_SPI_IOLPBKTSTCR_IPLPBKTSTENA_RESETVAL               ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_IPLPBKTSTENA_MAX                    ((uint32_t)0x0000000fu)

#define CSL_SPI_IOLPBKTSTCR_CTRLDLENERR_SHIFT                   ((uint32_t)16u)
#define CSL_SPI_IOLPBKTSTCR_CTRLDLENERR_MASK                    ((uint32_t)0x00010000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLDLENERR_RESETVAL                ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLDLENERR_MAX                     ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_CTRLTIMEOUT_SHIFT                   ((uint32_t)17u)
#define CSL_SPI_IOLPBKTSTCR_CTRLTIMEOUT_MASK                    ((uint32_t)0x00020000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLTIMEOUT_RESETVAL                ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLTIMEOUT_MAX                     ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_CTRLPARERR_SHIFT                    ((uint32_t)18u)
#define CSL_SPI_IOLPBKTSTCR_CTRLPARERR_MASK                     ((uint32_t)0x00040000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLPARERR_RESETVAL                 ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLPARERR_MAX                      ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_CTRLDESYNC_SHIFT                    ((uint32_t)19u)
#define CSL_SPI_IOLPBKTSTCR_CTRLDESYNC_MASK                     ((uint32_t)0x00080000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLDESYNC_RESETVAL                 ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLDESYNC_MAX                      ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_CTRLBITERR_SHIFT                    ((uint32_t)20u)
#define CSL_SPI_IOLPBKTSTCR_CTRLBITERR_MASK                     ((uint32_t)0x00100000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLBITERR_RESETVAL                 ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_CTRLBITERR_MAX                      ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_SCSFAILFLG_SHIFT                    ((uint32_t)24u)
#define CSL_SPI_IOLPBKTSTCR_SCSFAILFLG_MASK                     ((uint32_t)0x01000000u)
#define CSL_SPI_IOLPBKTSTCR_SCSFAILFLG_RESETVAL                 ((uint32_t)0x00000000u)
#define CSL_SPI_IOLPBKTSTCR_SCSFAILFLG_MAX                      ((uint32_t)0x00000001u)

#define CSL_SPI_IOLPBKTSTCR_RESETVAL                            ((uint32_t)0x00000000u)

/* SPIREV */

#define CSL_SPI_SPIREV_MINOR_SHIFT                              ((uint32_t)0u)
#define CSL_SPI_SPIREV_MINOR_MASK                               ((uint32_t)0x0000003Fu)
#define CSL_SPI_SPIREV_MINOR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_SPI_SPIREV_MINOR_MAX                                ((uint32_t)0x0000003fu)

#define CSL_SPI_SPIREV_CUSTOM_SHIFT                             ((uint32_t)6u)
#define CSL_SPI_SPIREV_CUSTOM_MASK                              ((uint32_t)0x000000C0u)
#define CSL_SPI_SPIREV_CUSTOM_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_SPIREV_CUSTOM_MAX                               ((uint32_t)0x00000003u)

#define CSL_SPI_SPIREV_MAJOR_SHIFT                              ((uint32_t)8u)
#define CSL_SPI_SPIREV_MAJOR_MASK                               ((uint32_t)0x00000700u)
#define CSL_SPI_SPIREV_MAJOR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_SPI_SPIREV_MAJOR_MAX                                ((uint32_t)0x00000007u)

#define CSL_SPI_SPIREV_RTL_SHIFT                                ((uint32_t)11u)
#define CSL_SPI_SPIREV_RTL_MASK                                 ((uint32_t)0x0000F800u)
#define CSL_SPI_SPIREV_RTL_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_SPI_SPIREV_RTL_MAX                                  ((uint32_t)0x0000001fu)

#define CSL_SPI_SPIREV_FUNC_SHIFT                               ((uint32_t)16u)
#define CSL_SPI_SPIREV_FUNC_MASK                                ((uint32_t)0x0FFF0000u)
#define CSL_SPI_SPIREV_FUNC_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_SPI_SPIREV_FUNC_MAX                                 ((uint32_t)0x00000fffu)

#define CSL_SPI_SPIREV_SCHEME_SHIFT                             ((uint32_t)30u)
#define CSL_SPI_SPIREV_SCHEME_MASK                              ((uint32_t)0xC0000000u)
#define CSL_SPI_SPIREV_SCHEME_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_SPI_SPIREV_SCHEME_MAX                               ((uint32_t)0x00000003u)

#define CSL_SPI_SPIREV_RESETVAL                                 ((uint32_t)0x00000000u)

#ifdef __cplusplus
}
#endif
#endif
