/*
 * audio_evmInit.c
 *
 * This file contains Audio application related EVM (platform) specific routines
 * implementation. 
 * This is part of the EVM Initialization library (evmInit) which contains pinmux
 * enabling routines for peripherals used by the application, and may contain 
 * related device pre-driver initialization routines.
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   audio_evmInit.c
 *
 *  \brief  This file contains the board specific code for enabling the use of
 *          audio driver.
 *
 *  (C) Copyright 2009, Texas Instruments, Inc
 *
 */

#include <xdc/std.h>
#include <stdio.h>
#define SW_I2C
#ifndef SW_I2C
#include <i2c/include/I2c.h>
#endif

#include <Audio_evmInit.h>
#include <mcasp_cfg.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/soc.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <ti/board/board.h>
#include <ti/drv/udma/udma.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART_stdio.h>
#include "MCASP_log.h"

/*============================================================================*/
/*                          MACRO DEFINITIONS                                 */
/*============================================================================*/

/* ========================================================================== */
/*                           MACRO DEFINTIONS                                 */
/* ========================================================================== */

#define PINMUX_WKUP_REGION_OFFSET       (0x1C000)
#define PINMUX_MAIN_REGION_OFFSET       (0x1C000)

#define PINMUX_TB_WKUP_REG_BASE         (0x02c40000u)
#define PINMUX_TB_MAIN_REG_BASE         (0x02c41000u)

#ifndef TBARM9CORE
#define PINMUX_WKUP_REG_BASE            (CSL_WKUP_CTRL_MMR0_CFG0_BASE + PINMUX_WKUP_REGION_OFFSET)
#define PINMUX_MAIN_REG_BASE            (CSL_CTRL_MMR0_CFG0_BASE + PINMUX_MAIN_REGION_OFFSET)
#else
#define PINMUX_WKUP_REG_BASE            (PINMUX_TB_WKUP_REG_BASE)
#define PINMUX_MAIN_REG_BASE            (PINMUX_TB_MAIN_REG_BASE)
#endif

#define PINMUX_DEFAULT_REG_VALUE        (0x00040000)
#define PINMUX_TB_DEFAULT_REG_VALUE     (0x00000007)
#define PINMUX_DEFAULT                  (0xff)

#define PINMUX_MUX_MODE_0               (0x0)
#define PINMUX_MUX_MODE_1               (0x1)
#define PINMUX_MUX_MODE_2               (0x2)
#define PINMUX_MUX_MODE_3               (0x3)
#define PINMUX_MUX_MODE_4               (0x4)
#define PINMUX_MUX_MODE_5               (0x5)
#define PINMUX_MUX_MODE_6               (0x6)
#define PINMUX_MUX_MODE_7               (0x7)
#define PINMUX_MUX_MODE_8               (0x8) //Reserved?

#define PINMUX_PD                       (0x0)
#define PINMUX_PU                       (0x2)
#define PINMUX_DP                       (0x1)

#define PINMUX_SLEWRATE_0               (0x0)
#define PINMUX_SLEWRATE_1               (0x1)
#define PINMUX_SLEWRATE_2               (0x2)
#define PINMUX_SLEWRATE_3               (0x3)

#define PINMUX_DS_OVRD_DISABLE          (0x0)
#define PINMUX_DS_OVRD_EN               (0x1)

#define PINMUX_DS_OUT_0                 (0x0)
#define PINMUX_DS_OUT_1                 (0x1)

#define PINMUX_DS_PU                    (0x2)
#define PINMUX_DS_PD                    (0x0)
#define PINMUX_DS_DP                    (0x1)

#define PINMUX_WKUP_DISABLE             (0x0)
#define PINMUX_WKUP_EN                  (0x1)

#define PINMUX_UNLOCK                   (0x0)
#define PINMUX_LOCK                     (0x1)

typedef struct{
    uint32_t mmrBaseAddress;
    uint32_t pinmuxRegOffset;
    uint8_t  muxmode;
    uint8_t  pu_pd;
    uint8_t  slew;
    uint8_t  ds_ovrd;
    uint8_t  ds_out;
    uint8_t  ds_pu_pd;
    uint8_t  wkup;
    uint8_t  lock;
} pinmux_t;


#define CSL2PTR (uint32_t *)(uintptr_t)
#define KICK0_UNLOCK_VAL 0x68EF3490
#define KICK1_UNLOCK_VAL 0xD172BC5A
#define KICK_LOCK_VAL    0x00000000
#define MCU_MMR_BASE_ADDRESS    CSL_MCU_CTRL_MMR0_CFG0_BASE

uint32_t MMR_unlock_one(uint32_t * kick0, uint32_t * kick1)
{
    // initialize the status variable
    uint32_t status = 1;

    // if either of the kick lock registers are locked
    if (!(*kick0 & 0x1) | !(*kick1 & 0x1))
    {
        // unlock the partition by writing the unlock values to the kick lock registers
        *kick0 = KICK0_UNLOCK_VAL;
        *kick1 = KICK1_UNLOCK_VAL;
    }

    // check to see if either of the kick registers are unlocked.
    if (!(*kick0 & 0x1))
    {
        status = 0;
    }

    // return the status to the calling program
    return status;

}

uint32_t MMR_lock_one(uint32_t * kick0, uint32_t * kick1)
{
    // create status return variable
    uint32_t status = 1;

    // check to see if either of the kick registers are unlocked.
    if ((*kick0 & 0x1))
    {
        // write the kick lock value to the kick lock registers to lock the partition
        *kick0 = KICK_LOCK_VAL;
        *kick1 = KICK_LOCK_VAL;
    }

    // check to see if either of the kick registers are still unlocked.
    if ((*kick0 & 0x1))
    {
        status = 0;
    }
    // return success or failure
    return status;
}

//Loops through an array of pinmux_t's, setting the MMRs for each one.
//arraysize is the size of the whole array of structs in bytes.
//Leaves registers unchanged for PINMUX_DEFAULT configurations; so make sure that is the start state.
//Does not check if MMRs are unlocked before writing.
uint32_t set_pinmux(pinmux_t *Array, uint8_t arraysize){
    uint32_t c = 0;
    uint32_t i = 0;
    uint32_t mmr_reg_value = 0;

    //Pointer for loop
    pinmux_t * arrayPtr = NULL;
    arrayPtr = Array;


    //Loop on each pinmux_t struct
    for (i = 0; i < arraysize; i++){
        //Set PADCONFIG register to defined PINMUX_DEFAULTs
        #ifdef TBARM9CORE
        *(volatile uint32_t *)(uintptr_t)(arrayPtr->mmrBaseAddress + arrayPtr->pinmuxRegOffset) = PINMUX_TB_DEFAULT_REG_VALUE;
        #else
        *(volatile uint32_t *)(uintptr_t)(arrayPtr->mmrBaseAddress + arrayPtr->pinmuxRegOffset) = PINMUX_DEFAULT_REG_VALUE;
        #endif

        //Read the PADCONFIG register
        mmr_reg_value = *(volatile uint32_t *)(uintptr_t)(arrayPtr->mmrBaseAddress + arrayPtr->pinmuxRegOffset);

        //Mux mode slection
        if(arrayPtr->muxmode != PINMUX_DEFAULT){
            mmr_reg_value  &= (0xFFFFFFF0);     // Mux mode
            mmr_reg_value  |= (arrayPtr->muxmode & 0x0000000F);
        }

        //PU-PD Selection
        if(arrayPtr->pu_pd != PINMUX_DEFAULT){
            mmr_reg_value &= (0xFFFCFFFF);       // PU-PD
            mmr_reg_value |= ((arrayPtr->pu_pd) << 16);
        }

        //Slew Rate selection
        if(arrayPtr->slew != PINMUX_DEFAULT){
            mmr_reg_value &= (0xFFE7FFFF);       // Slew Rate
            mmr_reg_value |= ((arrayPtr->slew) << 19);
        }

        //Deep sleep overried enable
        if(arrayPtr->ds_ovrd != PINMUX_DEFAULT){
            mmr_reg_value &= (0xFEFFFFFF);     // Deepsleep override enable
            mmr_reg_value |= ((arrayPtr->ds_ovrd) << 24);
        }

        //Deep sleep OUT selection
        if(arrayPtr->ds_out != PINMUX_DEFAULT){
            mmr_reg_value &= (0xFBFFFFFF);     // Deepsleep output
            mmr_reg_value |= ((arrayPtr->ds_out) << 26);
        }

        //Deep sleep PU-PD enable
        if(arrayPtr->ds_pu_pd != PINMUX_DEFAULT){
            mmr_reg_value &= (0xE7FFFFFF);    // Deepsleep PU-PD
            mmr_reg_value |= ((arrayPtr->ds_pu_pd) << 27);
        }

        //Wakeup programming
        if(arrayPtr->wkup != PINMUX_DEFAULT){
            mmr_reg_value &= (0xDFFFFFFF);        // Wakeup
            mmr_reg_value |= ((arrayPtr->wkup) << 29);
        }

        //Lock padconfig register from further programming
        if(arrayPtr->lock != PINMUX_DEFAULT){
            mmr_reg_value &= (0x7FFFFFFF);       // Lock
            mmr_reg_value |= ((arrayPtr->lock) << 31);
        }

        //Writing to Padconfig register
        *(volatile uint32_t *)(uintptr_t)(arrayPtr->mmrBaseAddress + arrayPtr->pinmuxRegOffset) = mmr_reg_value;

        for(c = 0; c < 20; c++);

        //Verify write
        if((*(volatile uint32_t *)(uintptr_t)(arrayPtr->mmrBaseAddress + arrayPtr->pinmuxRegOffset)) != mmr_reg_value) return 0;

        arrayPtr++;
    }
    return 1;
}

pinmux_t PINMUX_MCASP0_APP0_array [] = {
//pinmux reg base,  Reg offset, Muxmode,  PUPD,    Slew,    DS_OVR,  DS_Out_Val, DS_PUPD, WKP_Info, Lock_Info

{PINMUX_MAIN_REG_BASE, 0x01F4, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0CLK ; PIN ->MCU_OSPI0CLK ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x01F8, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0LBCLKO ; PIN ->MCU_OSPI0LBCLKO ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0200, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0DQS ; PIN ->MCU_OSPI0DQS ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0204, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D0 ; PIN ->MCU_OSPI0D0 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0208, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D1 ; PIN ->MCU_OSPI0D1 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x020C, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D2 ; PIN ->MCU_OSPI0D2 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0210, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D3 ; PIN ->MCU_OSPI0D3 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0214, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D4 ; PIN ->MCU_OSPI0D4 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0218, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D5 ; PIN ->MCU_OSPI0D5 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x021C, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D6 ; PIN ->MCU_OSPI0D6 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0220, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0D7 ; PIN ->MCU_OSPI0D7 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0224, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0CSN0 ; PIN ->MCU_OSPI0CSN0 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x0228, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI0CSN1 ; PIN ->MCU_OSPI0CSN1 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_0
{PINMUX_MAIN_REG_BASE, 0x022C, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI1LBCLKO ; PIN ->MCU_OSPI0CSN2 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_1
{PINMUX_MAIN_REG_BASE, 0x0230, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI1DQS ; PIN ->MCU_OSPI0CSN3 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_1
{PINMUX_MAIN_REG_BASE, 0x0234, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT },//PAD ->MCU_OSPI1DQS ; PIN ->MCU_OSPI0CSN3 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_1
{PINMUX_MAIN_REG_BASE, 0x0238, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI1DQS ; PIN ->MCU_OSPI0CSN3 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_1
{PINMUX_MAIN_REG_BASE, 0x023C, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI1DQS ; PIN ->MCU_OSPI0CSN3 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_1
{PINMUX_MAIN_REG_BASE, 0x0240, PINMUX_MUX_MODE_5, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT, PINMUX_DEFAULT }, //PAD ->MCU_OSPI1DQS ; PIN ->MCU_OSPI0CSN3 ; PINMUX_MUX_MODE_ ->PINMUX_MUX_MODE_1
};

//Setup padconfigs
uint32_t mcasp_configPinmux ()
{
    //Setup lock pointers
//    uint32_t partition = 7;
//    uint32_t partition_offset = 0x4000;
//    uint32_t * lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0 + (partition * partition_offset));
//    uint32_t * lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0 + (partition * partition_offset) + 4);

    uint32_t * lock0 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK7_KICK0  );
    uint32_t * lock1 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK7_KICK1 );

   //Unlock mmrs, write pinmux, then lock again
    MMR_unlock_one(lock0, lock1);

    set_pinmux(PINMUX_MCASP0_APP0_array, (sizeof(PINMUX_MCASP0_APP0_array)/sizeof(pinmux_t))); 

    MMR_lock_one(lock0, lock1);
    
    return 0;
}


void MCASP_PrintRegs(uint32_t instance)
{
#if 0
   uint8_t *base = (uint8_t *)(0x02B00000 + instance*0x10000);
   printf("\n");
   printf("MCASP[%d][%x]  MCASP_TXSTAT=%x\n",instance,0xC0,*((uint32_t *)(base + 0xC0)));
   printf("MCASP[%d][%x]  MCASP_RXSTAT=%x\n",instance,0x80,*((uint32_t *)(base + 0x80)));
   
   printf("MCASP[%d][%x]  MCASP_XRSCTL0=%x\n",instance,0x180,*((uint32_t *)(base + 0x180)));
   printf("MCASP[%d][%x]  MCASP_XRSCTL1=%x\n",instance,0x184,*((uint32_t *)(base + 0x184)));

   printf("MCASP[%d][%x]  MCASP_WFIFOSTS=%x\n",instance,0x1004,*((uint32_t *)(base + 0x1004)));
   printf("MCASP[%d][%x]  MCASP_RFIFOSTS=%x\n",instance,0x100C,*((uint32_t *)(base + 0x100C)));
#endif   
}

/**
 *  \brief    Initializes platform specific modules
 *
 *  This function initializes the modules like PLL, DDR, I2C etc
 *  which are required for audio processing. Need to call this function
 *  before doing any HW related operations.
 *
 *  \return    Platform_EOK on Success or error code
 */



extern Board_STATUS Board_init(Board_initCfg);
void McASP_Enable(void);

//#define HW_WR_REG32(addr, data)   *(unsigned int*)(addr) =(unsigned int)(data)

/*
 * Function to enable the pinmux for the mcasp and i2c devices in the soc.
 *
 */
 #define BOARD_FUNCTIONAL_AM65XX
void configureAudio(void)
{
	
#if defined(SOC_AM65XX) || defined(SOC_J721E)
    Sciclient_ConfigPrms_t  sciClientCfg;
#endif
    	
#ifdef BOARD_FUNCTIONAL_AM65XX
	Board_STATUS stat = BOARD_SOK;
	Board_initCfg arg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO;

	stat = Board_init(arg);
	if(stat!=BOARD_SOK) {
	  MCASP_log("Board init failed!!");
	}
#else

//	mcasp_configPinmux ();
#endif

#if defined(SOC_AM65XX) || defined(SOC_J721E)
    Sciclient_configPrmsInit(&sciClientCfg);
    Sciclient_init(&sciClientCfg);
#endif


		mcasp_configPinmux ();
	McASP_Enable();
	
	MCASP_log("\n Pinmux Config complete");
	
}

#define MCASP0_CLKSRC_ARM1_PLL 4  /* 200 Mhz input */
#define MCASP0_CLKSRC_PER2_PLL 3  /* 100 Mhz */

// #define MCASP0_CLKSRC MCASP0_CLKSRC_ARM1_PLL
#define MCASP0_CLKSRC MCASP0_CLKSRC_PER2_PLL
volatile uint32_t mcasp_clksrc=MCASP0_CLKSRC;
void McASP_Enable(void)
{
   
   /* Use the peripheral clock PER1HSDIV_CLKOUT2PERLL */
   
   /* Configure the MMR registers CTRLMMR_MCASP0_CLKSEL , the */
   
   /* Unlock the register by writing in to the kick register */
   volatile uint32_t *kickRegister=(volatile uint32_t *)0x109008;
   volatile uint32_t *CTRLMMR_MCASP0_CLKSEL=(volatile uint32_t *)0x108060;
   /* Write the kick value 
     0x68EF3490 
     0xD172BC5A
     */
    *((volatile uint32_t*)0x109008)=0x68EF3490;
    *((volatile uint32_t*)0x10900C)=0xD172BC5A;

		while(*(kickRegister)!=0x68EF3491);
   
    /* 2-0 AUXCLK_SEL R/W 0h Selects the McASP0 auxclk clock source Reserved values default */
   /*
   Selects the McASP0 auxclk clock source Reserved values default to
HFOSC1_CLK
0h - HFOSC1_CLK
1h - HFOSC0_CLK
2h - MCU_EXT_REFCLK0
3h - PER1HSDIV_CLKOUT2
4h - Divided ARM1_PLL_CLKOUT (see clkdiv)
5h - EXT_REFCLK1
6h - reserved (HFOSC1_CLK)
7h - reserved (HFOSC1_CLK)
*/
        *CTRLMMR_MCASP0_CLKSEL = (((*CTRLMMR_MCASP0_CLKSEL & (~(0x7)))) | mcasp_clksrc);
        while( (*CTRLMMR_MCASP0_CLKSEL & 0x7) !=mcasp_clksrc);
    /* Write back the kickback registers */
    *((uint32_t*)0x109008)=0;
    *((uint32_t*)0x10900C)=0;

     while(*kickRegister!=0);
     MCASP_log("Clock configured with CTRL MMR = %x\n",*CTRLMMR_MCASP0_CLKSEL);
}



/*
 * Function to configure SOC specific parameters. This includes SOC
 * specific parameters such as interrupt configuration using Muxes,
 * interrupt configuration etc.
 */
void configMcASP_SocHwInfo()
{
  /* Configure the interrupts for the McASP Instance MCASP_NUM */
  /* ON Keystone, it involves CIC programming as well.
   * The McASP does that internally, if configured with the correct parameters.
   * Such as muxNum, muxInEvent, muxOutEvent,
   * cpuInEventNum, cpuIntNum
  */
    Mcasp_HwInfo hwInfo;

    Mcasp_socGetInitCfg(MCASP_NUM, &hwInfo);

     /* Write back */
    Mcasp_socSetInitCfg(MCASP_NUM,&hwInfo);
}
/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
