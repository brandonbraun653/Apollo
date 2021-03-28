/*
 * Copyright (c) 2011-2017, Texas Instruments Incorporated
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

#ifndef _EVMC66X_PLLC_H_
#define _EVMC66X_PLLC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * \file  evmc66x_pllc.h
 *
 * \brief This contains PLL Control specific functions and defines
 *		  prototypes.
 *
 ******************************************************************************/

#define PLLC_DIVEN_PLLDIV2    (1)
#define PLLC_DIVDS_PLLDIV2    (0)
#define PLLC_DIVEN_PLLDIV3    (1)
#define PLLC_DIVDS_PLLDIV3    (0)

/***********************************************************************
 *                  PLL clock dividers and multipliers                 *
 ***********************************************************************/

/******************* Main PLL divider and multipliers *******************/
/* Divider and multiplier macros for main PLL clock indicates
   actual values. Value 2 means divide/multiply by 2 */
/* PREDIV - PLL divider value */
#define PLATFORM_PLL_PREDIV_val  (1)

/* POSTDIV - PLL output divider value */
#define PLATFORM_PLL_POSTDIV_val (4)

/* Default PLL PLLM value (24/1*(100/4)) = 600MHz) */
#define  PLATFORM_PLL1_PLLM_val  (100)

/* 1/x-rate clock for gem_trace_clk. Divider to generate SYSCLK2 from PLLOUT */
#define  PLATFORM_PLLDIV2_val    (3)
/* 1/y-rate clock for STMXPT_CLK. Divider to generate SYSCLK3 from PLLOUT */
#define  PLATFORM_PLLDIV3_val    (5)

/* Divider and multiplier macros for module PLL clock indicates
   value written to the register. Value 1 means divide/multiply by 2 */
/******************* NSS PLL divider and multipliers *******************/
/* NSS PLL settings for 1000 MHz */
#define PLLM_NSS     (249)  // Multiply by 250
#define PLLD_NSS     (2)    // Divide by 3
#define CLKOD_NSS    (1)    // Divide by 2

/******************* DDR PLL divider and multipliers *******************/
/* DDR3 PLL settings for 200 MHz */

/* DDR3 clock settings used when input clock is provided by DDRCLKP */
#define DDRCLKP_PLLM_DDR3    (59)   // Multiply by 60
#define DDRCLKP_PLLD_DDR3    (2)   // Divide by 3
#define DDRCLKP_PLLOD_DDR3   (9)   // Divide by 10

/* DDR3 clock settings used when input clock is provided by DDRCLKP */
#define PLLM_DDR3    (249)  // Multiply by 250
#define PLLD_DDR3    (2)   // Divide by 3
#define PLLOD_DDR3   (9)   // Divide by 10


/******************* DSS PLL divider and multipliers *******************/
/* DSS PLL settings for 74.2 MHz */
#define PLLM_DSS     (197)  // Multiply by 198
#define PLLD_DSS     (3)   // Divide by 4
#define CLKOD_DSS    (15)   // Divide by 16

/******************* ICSS PLL divider and multipliers *******************/
/* ICSS PLL settings for 200 MHz */
#define PLLM_ICSS    (249)  // Multiply by 250
#define PLLD_ICSS    (2)   // Divide by 3
#define CLKOD_ICSS   (9)   // Divide by 10

/******************* UART PLL divider and multipliers *******************/
/* UART PLL settings for 384 MHz UART PLL output clock */
#define PLLM_UART    (127)  // Multiply by 128
#define PLLD_UART    (0)   // Divide by 1
#define CLKOD_UART   (7)   // Divide by 8

/* Value of the PLL input clock rate in MHz */
#define PLATFORM_BASE_CLK_RATE_MHZ (24u)    /* External 24 MHz clock */

/********************************************************************************************
 *                     PLL controller register local Declarations                          *
 *******************************************************************************************/
#define   MAINPLLCTL0_REG        (*((volatile uint32_t *) 0x02620350))
#define   MAINPLLCTL1_REG        (*((volatile uint32_t *) 0x02620354))

/* NSS PLL control registers */
#define   NSSPLLCTL0_REG         (*((volatile uint32_t *) 0x02620358))
#define   NSSPLLCTL1_REG         (*((volatile uint32_t *) 0x0262035C))

/* DDR3A and DDR3B PLL control registers */
#define   DDR3PLLCTL0_REG(x)     (*((volatile uint32_t *) (0x02620360+(8*x))))
#define   DDR3PLLCTL1_REG(x)     (*((volatile uint32_t *) (0x02620364+(8*x))))

/* DSS PLL control registers */
#define   DSSPLLCTL0_REG         (*((volatile uint32_t *) 0x02620380))
#define   DSSPLLCTL1_REG         (*((volatile uint32_t *) 0x02620384))

/* ICSS PLL control registers */
#define   ICSSPLLCTL0_REG        (*((volatile uint32_t *) 0x02620388))
#define   ICSSPLLCTL1_REG        (*((volatile uint32_t *) 0x0262038C))

/* UART PLL control registers */
#define   UARTPLLCTL0_REG        (*((volatile uint32_t *) 0x02620390))
#define   UARTPLLCTL1_REG        (*((volatile uint32_t *) 0x02620394))

#define   OBSCLCTL_REG           (*((volatile uint32_t *) 0x026203AC))

/* PLL controller registers */
#define   PLLCTL_REG            (*((volatile uint32_t *) 0x02310100))
#define   SECCTL_REG            (*((volatile uint32_t *) 0x02310108))
#define   PLLM_REG              (*((volatile uint32_t *) 0x02310110))
#define   PLLCMD_REG            (*((volatile uint32_t *) 0x02310138))
#define   PLLSTAT_REG           (*((volatile uint32_t *) 0x0231013C))
#define   PLLALNCTL_REG         (*((volatile uint32_t *) 0x02310140))
#define   PLLDIV2_REG           (*((volatile uint32_t *) 0x0231011C))
#define   PLLDIV3_REG           (*((volatile uint32_t *) 0x02310120))

/* NSS PLL Registers */
#define NSS_PLL_CLKM_MASK   (0x0007FFC0) /* Tells the multiplier value for the NSS PLL */
#define NSS_PLL_CLKD_MASK   (0x0000003F) /* Tells the divider value for the NSS PLL */
#define NSS_PLL_CLKOD_MASK  (0x00780000) /* Tells the output divider value for the NSS PLL */

/* PLL multiplier mask value */
#define MODULE_PLL_CLKM_MASK   (0x0007FFC0)
/* PLL divider mask value */
#define MODULE_PLL_CLKD_MASK   (0x0000003F)
/* PLL output divider mask value */
#define MODULE_PLL_CLKOD_MASK  (0x00780000)

#define PLL1_BASE                (0x02310000)
#define PLL1_PLLCTL              (*(unsigned int*)(PLL1_BASE + 0x100))   // PLL1 Control
#define PLL1_SECCTL              (*(unsigned int*)(PLL1_BASE + 0x108))   // PLL1 Sec Control
#define PLL1_PLLM                (*(unsigned int*)(PLL1_BASE + 0x110))   // PLL1 Multiplier
#define PLL1_DIV1                (*(unsigned int*)(PLL1_BASE + 0x118))   // DIV1 divider
#define PLL1_DIV2                (*(unsigned int*)(PLL1_BASE + 0x11C))   // DIV2 divider
#define PLL1_DIV3                (*(unsigned int*)(PLL1_BASE + 0x120))   // DIV3 divider
#define PLL1_CMD                 (*(unsigned int*)(PLL1_BASE + 0x138))   // CMD control
#define PLL1_STAT                (*(unsigned int*)(PLL1_BASE + 0x13C))   // STAT control
#define PLL1_ALNCTL              (*(unsigned int*)(PLL1_BASE + 0x140))   // ALNCTL control
#define PLL1_DCHANGE             (*(unsigned int*)(PLL1_BASE + 0x144))   // DCHANGE status
#define PLL1_CKEN                (*(unsigned int*)(PLL1_BASE + 0x148))   // CKEN control
#define PLL1_CKSTAT              (*(unsigned int*)(PLL1_BASE + 0x14C))   // CKSTAT status
#define PLL1_SYSTAT              (*(unsigned int*)(PLL1_BASE + 0x150))   // SYSTAT status
#define PLL1_DIV4                (*(unsigned int*)(PLL1_BASE + 0x160))   // DIV4 divider
#define PLL1_DIV5                (*(unsigned int*)(PLL1_BASE + 0x164))   // DIV5 divider
#define PLL1_DIV6                (*(unsigned int*)(PLL1_BASE + 0x168))   // DIV6 divider
#define PLL1_DIV7                (*(unsigned int*)(PLL1_BASE + 0x16C))   // DIV7 divider
#define PLL1_DIV8                (*(unsigned int*)(PLL1_BASE + 0x170))   // DIV8 divider
#define PLL1_DIV9                (*(unsigned int*)(PLL1_BASE + 0x174))   // DIV9 divider
#define PLL1_DIV10               (*(unsigned int*)(PLL1_BASE + 0x178))   // DIV10 divider
#define PLL1_DIV11               (*(unsigned int*)(PLL1_BASE + 0x17C))   // DIV11 divider
#define PLL1_DIV12               (*(unsigned int*)(PLL1_BASE + 0x180))   // DIV12 divider
#define PLL1_DIV13               (*(unsigned int*)(PLL1_BASE + 0x184))   // DIV13 divider
#define PLL1_DIV14               (*(unsigned int*)(PLL1_BASE + 0x188))   // DIV14 divider
#define PLL1_DIV15               (*(unsigned int*)(PLL1_BASE + 0x18C))   // DIV15 divider
#define PLL1_DIV16               (*(unsigned int*)(PLL1_BASE + 0x190))   // DIV16 divider

/* Shift values for PLL control register bits */
#define BWADJ_BIT_SHIFT     (24)
#define BYPASS_BIT_SHIFT    (23)
#define CLKF_BIT_SHIFT      (6)

#define ENSAT_BIT_SHIFT     (6)
#define RESET_BIT_SHIFT     (14)
#define PLLSEL_BIT_SHIFT    (13)

/* UART internal divider value */
#define UART_INT_DIV (2)

/* DSS PLL Register mask values */
#define DSS_PLL_CLKM_MASK   (0x0007FFC0) /* Tells the multiplier value for the DSS PLL */
#define DSS_PLL_CLKD_MASK   (0x0000003F) /* Tells the divider value for the DSS PLL */
#define DSS_PLL_CLKOD_MASK  (0x00780000) /* Tells the output divider value for the DSS PLL */

/* ICSS PLL Registers mask values */
#define ICSS_PLL_CLKM_MASK   (0x0007FFC0) /* Tells the multiplier value for the ICSS PLL */
#define ICSS_PLL_CLKD_MASK   (0x0000003F) /* Tells the divider value for the ICSS PLL */
#define ICSS_PLL_CLKOD_MASK  (0x00780000) /* Tells the output divider value for the ICSS PLL */

/* UART PLL Registers mask values */
#define UART_PLL_CLKM_MASK   (0x0007FFC0) /* Tells the multiplier value for the UART PLL */
#define UART_PLL_CLKD_MASK   (0x0000003F) /* Tells the divider value for the UART PLL */
#define UART_PLL_CLKOD_MASK  (0x00780000) /* Tells the output divider value for the UART PLL */

/* UART input clock rate */
#define PLATFORM_UART_INPUT_CLOCK_RATE ((uint32_t)(PLATFORM_BASE_CLK_RATE_MHZ * (PLLM_UART + 1) * 1000000)/((PLLD_UART + 1) * (CLKOD_UART + 1) * UART_INT_DIV))

/* PLL identifiers */
enum pll_type_e
{
	DDR3A_PLL
};

/* PLL observation clock selection */
typedef enum _PllObsClk
{
	OBSCLK_BAW_OSC = 0,
    OBSCLK_MAIN_PLL,
    OBSCLK_DSS_PLL,
    OBSCLK_ARM_PLL,
    OBSCLK_UART_PLL,
    OBSCLK_ICSS_PLL,
    OBSCLK_DDR3A_PLL,
    OBSCLK_PLLCTRL,
    OBSCLK_NSS_PLL,
    OBSCLK_HF_OSC,
    OBSCLK_RC_OSC

} PllObsClk;

typedef struct PllcHwSetup {
    /** \brief Divider Enable/Disable
     *  \param CSL_BitMask32
     */
    CSL_BitMask32 divEnable;
    /** \brief PLL Multiplier
     *  \param Uint32
     */
    Uint32        pllM;
    /** \brief PLL Divider 2
     *  \param Uint32
     */
    Uint32        pllDiv2;
    /** \brief PLL Divider 2
     *  \param Uint32
     */
    Uint32        pllDiv3;
    /** \brief PLL Divider 3
     *  \param Uint32
     */
    Uint32        preDiv;
    /** \brief post Divider value
     *  \param Uint32
     */
    Uint32        postDiv;
    /** \brief Setup that can be used for future implementation
     *  \param void*
     */
    void*         extendSetup;
} PllcHwSetup;

/* PLL configuration data */
typedef struct pll_init_data {
	uint32_t pll;
	uint32_t pll_m;		/* PLL Multiplier */
	uint32_t pll_d;		/* PLL divider */
	uint32_t pll_od;	/* PLL output divider    */
} pll_init_data;

CSL_Status  CorePllcGetHwSetup (PllcHwSetup*);
CSL_Status  CorePllcHwSetup (PllcHwSetup*);
CSL_Status  corePllcInit (void *);
CSL_Status SetNssPllConfig (pll_init_data *data);
CSL_Status SetDssPllConfig (pll_init_data *data);
CSL_Status SetIcssPllConfig (pll_init_data *data);
CSL_Status SetUartPllConfig (pll_init_data *data);
CSL_Status  SetDDR3PllConfig (pll_init_data *data);
void configPllClkSelection (uint8_t sysClkSel);
void enablePllObsClk (PllObsClk obsClk);

#ifdef __cplusplus
}
#endif

#endif /* _EVMC66X_PLLC_H_ */

/* Nothing past this point */
