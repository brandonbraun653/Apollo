/**
 * \file  pruss_drv.h
 *
 * \brief This file contains the function prototypes for the device
 *        abstraction layer for PRUSS. It also contains some
 *        related macro definitions and some files to be included.
 */


/*
* Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef __PRUSS_DRV_H__
#define __PRUSS_DRV_H__

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*           PRUSS Register Offsets for AM33X SOC                             */
/* ========================================================================== */

#define PRUSS_IRAM_SIZE                 8192
#define PRUSS_MMAP_SIZE                 0x40000
#define AM33XX_PRUSS0_BASE		0x4a300000
#define AM43XX_PRUSS0_BASE		0x54440000		// ICSS_L
#define AM43XX_PRUSS1_BASE		0x54400000		// ICSS_M

/* ========================================================================== */
/*           For IRQ handler PRUSS0                                           */
/* ========================================================================== */

#define PRU_EVTOUT_0            0
#define PRU_EVTOUT_1            1
#define PRU_EVTOUT_2            2
#define PRU_EVTOUT_3            3
#define PRU_EVTOUT_4            4
#define PRU_EVTOUT_5            5
#define PRU_EVTOUT_6            6
#define PRU_EVTOUT_7            7
/* 
 * PRUSS Interrupt Controller (PRUSS INTC) Registers Offsets
 */
 
#define PRU_INTC_REVID_REG  0x000
#define PRU_INTC_CR_REG     0x004
#define PRU_INTC_HCR_REG    0x00C
#define PRU_INTC_GER_REG    0x010
#define PRU_INTC_GNLR_REG   0x01C
#define PRU_INTC_SISR_REG   0x020
#define PRU_INTC_SICR_REG   0x024
#define PRU_INTC_EISR_REG   0x028
#define PRU_INTC_EICR_REG   0x02C
#define PRU_INTC_HIEISR_REG 0x034
#define PRU_INTC_HIDISR_REG 0x038
#define PRU_INTC_GPIR_REG   0x080

#define PRU_INTC_SRSR1_REG  0x200
#define PRU_INTC_SRSR2_REG  0x204

#define PRU_INTC_SECR1_REG  0x280
#define PRU_INTC_SECR2_REG  0x284

#define PRU_INTC_ESR1_REG   0x300
#define PRU_INTC_ESR2_REG   0x304

#define PRU_INTC_ECR1_REG   0x380
#define PRU_INTC_ECR2_REG   0x384

#define PRU_INTC_CMR1_REG   0x400
#define PRU_INTC_CMR2_REG   0x404
#define PRU_INTC_CMR3_REG   0x408
#define PRU_INTC_CMR4_REG   0x40C
#define PRU_INTC_CMR5_REG   0x410
#define PRU_INTC_CMR6_REG   0x414
#define PRU_INTC_CMR7_REG   0x418
#define PRU_INTC_CMR8_REG   0x41C
#define PRU_INTC_CMR9_REG   0x420
#define PRU_INTC_CMR10_REG  0x424
#define PRU_INTC_CMR11_REG  0x428
#define PRU_INTC_CMR12_REG  0x42C
#define PRU_INTC_CMR13_REG  0x430
#define PRU_INTC_CMR14_REG  0x434
#define PRU_INTC_CMR15_REG  0x438
#define PRU_INTC_CMR16_REG  0x43C

#define PRU_INTC_HMR1_REG   0x800
#define PRU_INTC_HMR2_REG   0x804
#define PRU_INTC_HMR3_REG   0x808

#define PRU_INTC_SIPR1_REG  0xD00
#define PRU_INTC_SIPR2_REG  0xD04

#define PRU_INTC_SITR1_REG  0xD80
#define PRU_INTC_SITR2_REG  0xD84

#define PRU_INTC_HIER_REG   0x1500

/* ========================================================================== */
/*          Macros representing PRU Memory locations                          */
/* ========================================================================== */

#define PRU0_DATARAM           0
#define PRU1_DATARAM           1
#define PRU0_IRAM              2
#define PRU1_IRAM              3
#define PRUSS_SHARED_DATARAM   4
#define	PRUSS_CFG              5
#define	PRUSS_UART             6
#define	PRUSS_IEP              7
#define	PRUSS_ECAP             8
#define	PRUSS_MII_RT           9
#define	PRUSS_MDIO            10

/* ========================================================================== */
/*          Macros representing Interrupt-Channel-Host sizes                  */
/* ========================================================================== */

#define MAX_HOSTS_SUPPORTED   10
#define NUM_PRU_HOSTS         10
#define NUM_PRU_CHANNELS      10
#define NUM_PRU_SYS_EVTS      64

/* ========================================================================== */
/*          Macros to support dynamic chip detecting feature                  */
/* ========================================================================== */

#define AM33XX_INTC_PHYS_BASE	     0x4a320000
#define AM33XX_DATARAM0_PHYS_BASE    0x4a300000
#define AM33XX_PRUSS_INTC_REV	     0x4E82A900

#define AM43XX_INTC_PHYS_BASE	     0x54420000
#define AM43XX_DATARAM0_PHYS_BASE    0x54400000
#define AM43XX_PRUSS_INTC_REV	     0x4E82A900

#define PRUSS_V1                     1
#define PRUSS_V2                     2

#define	PRU0		             0
#define	PRU1		             1

#define PRUSSDRV_PRU_RESET           0
#define PRUSSDRV_PRU_DISABLE         1
#define PRUSSDRV_PRU_ENABLE          2

#define PRUSSDRV_MAX_WAIT_EVENTS     7

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief System event to channel map structure
 *
 */
typedef struct prussSysEvtToChannelMap
{
    uint8_t sysevt;
    /**< System event number */
    uint8_t channel;
    /**< Channel number */
    uint8_t polarity;
    /**< Interrupt polarity [ 0 - active low , 1 - active high ] */
    uint8_t type;
    /**< Interrupt type[0 - level or pulse interrupt , 1 - edge interrupt] */
}prussSysEvtToChannelMap_t;
 
typedef struct prussChannelToHostMap
{
     short channel;
     short host;
}prussChannelToHostMap_t;
 
typedef struct prussIntcInitData
{
    /**
     * Enabled SYSEVTs - Range:0..63
     * {-1} indicates end of list
     */
    char sysEvtsEnabled[NUM_PRU_SYS_EVTS];
 
    /**
     * SysEvt to Channel map. SYSEVTs - Range:0..63 Channels -Range: 0..9
     *{-1, -1} indicates end of list
     */
    prussSysEvtToChannelMap_t sysEvttoChannelMap[NUM_PRU_SYS_EVTS];
     
    /**
     * Channel to Host map.Channels -Range: 0..9  HOSTs - Range:0..9
     * {-1, -1} indicates end of list
     */
    prussChannelToHostMap_t channelToHostMap[NUM_PRU_CHANNELS];
 
    /**< 10-bit mask - Enable Host0-9{Host0/1:PRU0/1, Host2..9:PRUEVT_OUT0..7}*/
    uint32_t hostEnableBitMask;
}prussIntcInitData_t;
 
typedef void (*PRUSSDRV_IRQ_HANDLER)(void);

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief    Resets PRU
 *
 * \param    pruNum          PRU instance number[0 or 1].
 * \param    baseAddr        baseAddress of PRUSSn
 *
 * \return   0 in case of successful reset, -1 otherwise.
 **/
int32_t PRUSSDrvPruReset(uint8_t pruNum, uint32_t baseAddr);

/**
 * \brief    Disables PRU
 *
 * \param    pruNum          PRU instance number[0 or 1].
 * \param    baseAddr        baseAddress of PRUSSn
 *
 * \return   0 in case of successful disable, -1 otherwise.
 **/
int32_t PRUSSDrvPruDisable(uint8_t pruNum, uint32_t baseAddr);

/**
 * \brief    Enables PRU
 *
 * \param    pruNum          PRU instance number[0 or 1].
 * \param    baseAddr            baseAddress of PRUSSn
 *
 * \return   0 in case of successful enable, -1 otherwise.
 **/
int32_t PRUSSDrvPruEnable(uint8_t pruNum,uint32_t baseAddr);

/**
 *
 *  \brief   This function writes the given data to PRU memory
 *
 * \param     pruMem         PRU Memory Macro [DATARAM0_PHYS_BASE
 * \param     wordOffSet     Offset at which the write will happen.
 * \param     sourceMem     Source memory[ Array of uint32_tegers ]
 * \param     byteLength     Total number of bytes to be writen
 * \param     baseAddr       baseAddress of PRUSSn
 *
 * pruMem can have values
 *            PRU0_DATARAM\n
 *            PRU0_IRAM\n
 *            PRU1_DATARAM\n
 *            PRU1_IRAM\n
 *            PRUSS_SHARED_DATARAM
 * \return    0 in case of successful transition, -1 otherwise.
 *
 **/
uint32_t PRUSSDrvPruWriteMemory(uint32_t pruMem,
                                uint32_t wordOfffSet,
                                uint32_t *sourceMem,
                                uint32_t byteLength,
				uint32_t baseAddr);

/**
 * \brief  This function Generates an INTC event
 *
 * \param   eventNum   The INTC Event number
 * \param   baseAddr   baseAddress of PRUSSn
 *
 * \return  0 in case of successful transition, -1 otherwise
 **/
int32_t PRUSSDrvPruSendEvent(uint32_t eventNum,uint32_t baseAddr);

/**
 * \brief  This function clears an INTC event
 *
 * \param   eventNum   The INTC Event number
 *
 * \return  0 in case of successful transition, -1 otherwise
 **/
int32_t PRUSSDrvPruClearEvent(uint32_t eventNum,uint32_t baseAddr);

/**
 * \brief  This function returns the address of PRU components.
 *
 * \param   perId       PRU component's Id.
 * \param   address      Memory to which address to be copied.
 * \param   baseAddr     baseAddress of PRUSS
 *
 * \return  0 in case of success, -1 otherwise.
 **/
int32_t PRUSSDrvMapPruMem(uint32_t pruRamId,
                          void **address,
                          uint32_t baseAddr);

/**
 * \brief  This function returns the base address of peripheral IO modules.
 *
 * \param   perId   Peripheral Module's Id.
 *
 * \param   address  Memory to which address to be copied.
 * \param   baseAddr     baseAddress of PRUSSn
 *
 * \return  0 in case of success, -1 otherwise. \n
 **/
int32_t PRUSSDrvMapPeripheralIo(uint32_t perId,
                                void **address,
                                uint32_t baseAddr);


void PRUSSEnableOcpMasterAccess(uint32_t baseAddr );

/**
 * \brief    Detects the Chip Type
 *
 * \param    None
 *
 * \return   None
 */
uint32_t PRUSSDetectHwVersion(void);

#ifdef __cplusplus
}
#endif
#endif
