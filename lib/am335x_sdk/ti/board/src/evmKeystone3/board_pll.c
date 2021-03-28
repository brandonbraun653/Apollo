/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 * \file   board_pll.c
 *
 * \brief  board pll configurations
 *
 * Phase-Locked Loop circuitries (PLLs) in the device are clock generator PLLs,
 * which multiply the lowerfrequency reference clock up to the operating 
 * frequency of the respective subsystem(s).
 * There are total two PLLs domains in the device:
 * (1) WKUP/MCU PLL domain
 *       - Again WKUP/MCU PLL is categorized as MCU PLL0 and MCU PLL1 
 * (2) MAIN PLL Domain
 *       - MAIN PLL is categorized as seven PLLs. i.e,MAIN PLL, PER0 PLL,
 *         PER1 PLL, DDR PLL, DSS PLL, ARM0 PLL and ARM1 PLL.
 * To generate high-frequency clocks, the device supports multiple on-chip 
 * PLLs controlled directly by the Clocking Management. 
 * They are of two types:
 * (1) Type A PLLs
 * (2) Type B PLLs
 * Board PLL configures the Main PLLs and MCU PLLs controller modules based on
 * different multplier and divider configurations.  
 *
 */

#include "board_internal.h"
#include "keystone3_pll.h"
#include <ti/drv/sciclient/sciclient.h>

uint32_t read_pid = 0;
#define DELAY   (500)
#define ENABLE_PLL_CONFIG (1)

#ifdef ENABLE_PLL_CONFIG
/**
 * \brief  PLL setup function
 *
 * Enables the CLKOUTLDO and places it in bypass mode (ADPLLLJM)
 * Enables the CLKOUTX2 and CLKOUTHIF (ADPLLM)
 *
 * \param   pll_base_addr   [IN]    PLL base address
 * \param   pll_type_adpllm [IN]    PLL type
 *          Enables the CLKOUTLDO or CLKOUTX,CLKOUTHIF  based on the PLL type
 *
 * \return  None
 */
static void Board_PLLSetup (uint32_t pll_base_addr, uint32_t pll_type_adpllm )
{
    /* Enable PLL clocks */
    if(!pll_type_adpllm)
    {
        /* bit 5 (CLKOUTLDO_EN) of PLL_CTRL set to 1 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)), 
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKOUTLDO_EN, 1);
        /*
        poll bit 5 (CLKOUTLDO_EN_ACK) of PLL_STAT for 1 
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_CLKOUTLDO_EN_ACK));
        */
    }

    /* bit 0 (CLKOUTBYPASS_EN) of PLL_CTRL set to 1 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKOUTBYPASS_EN, 1);
  
    /* poll bit 0 (CLKOUTBYPASS_EN_ACK) of PLL_STAT for 1 */
    while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_CLKOUTBYPASS_EN_ACK));

    if(pll_type_adpllm)
    {
        /* bit 2 (CLKOUTX2_EN) of PLL_CTRL set to 1 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKOUTX2_EN, 1);

        /* poll bit 2 (CLKOUTX2_EN_ACK) of PLL_STAT for 1  */
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_CLKOUTX2_EN_ACK));
    }

    /* bit 1 (CLKOUTHIF_EN) of PLL_CTRL set to 1 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKOUTHIF_EN, 1);

    /*
    poll bit 1 (CLKOUTHIF_EN_ACK) of PLL_STAT for 1
    while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_CLKOUTHIF_EN_ACK));
    */

    /* Bit 3 (CLKOUT_EN) of PLL set to 1 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKOUT_EN, 1);

    /* For the CPSW PLL, explicitly enable the DCO clock so the
       HSDIVs will work */
    /* CLKDCOLDO_EN of PLL set to 1   */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKDCOLDO_EN, 1);

  }

/**
 * \brief  PLL controller setup function
 *
 * This function keeps the controller in normal operation mode 
 *
 * \param  ctrl_base_addr   [IN]    PLL controller base address
 *
 * \return None
 */
static void Board_PLLCtrlSetup (uint32_t ctrl_base_addr )
{
    /* make sure PLL controller in reset for programming 
       bit 3 PLLRST set to 1 */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCTL_OFFSET)), 1, 1, 3); 

    /* for bypass mode control 
       bit 5 (PLLENSRC) of PLLCTL set to 0 */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCTL_OFFSET)), 0, 1, 5);

    /* take ctrl out of 'bypass' mode (normal operation) 
       bit 0 (PLLEN) of PLLCTL set to 1 */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCTL_OFFSET)), 1, 1, 0);
}

/**
 *
 * \brief  Secondary pll setup function
 *
 * This function puts the PLL in bypass mode if PLL HSDIV exist
 * and put PLL controller in reset for programming if it exists
 *
 * \param   pll_base_addr       [IN]    PLL base address
 * \param   ctrl_base_addr      [IN]    control base address
 * \param   ctrl_exist          [IN]    Control exist status
 *          If controller exist status is true then
 *          put the PLL controller in reset for programming
 *
 * \return  None
 */
static void Board_PLLSecondarySetup (uint32_t pll_base_addr,
                                     uint32_t ctrl_base_addr,
                                     uint32_t ctrl_exist,
                                     uint32_t pll_type_adpllm)
{
     volatile uint32_t index;

    /* bit 7 (IDLE) of PLL_CTRL set to 1 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_IDLE, 1);

    /* poll bit 7 (BYPASS_ACK) of PLL_STAT for 1 */
    while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_BYPASS_ACK));

    /* Enable PLL clock LDO */
    if(!pll_type_adpllm)
    {
        /* bit 5 (CLKOUTLDO_EN) of PLL_CTRL set to 1 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKOUTLDO_EN, 1);
    }

    if(ctrl_exist)
    {
        /* bit 3 PLLRST set to 1 */
        SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCTL_OFFSET)),
                1, 1, 3);
        for(index = 0; index < DELAY; index++);
    }

    /* Bit 3 (CLKOUT_EN) of PLL set to 1 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKOUT_EN, 1);

    /* For the CPSW PLL, explicitly enable the DCO clock so the
       HSDIVs will work */
    /* CLKDCOLDO_EN of PLL set to 1   */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_CLKDCOLDO_EN, 1);
}

/**
 * \brief  PLL programming function
 *
 * This function configures the multiplier/divider values to PLL registers 
 * based on PLL type and programs the PLL registers
 *  
 * \param  pllcConfig *data [IN] PLL config structure pointer
 *
 * \return None
 */
static void Board_PLLProgram (const pllcConfig *data)
{
    float temp1;
    float clkin_val;

    uint32_t sd_div_val = 0;
    uint32_t m_int_mult_val;
    uint32_t m_frac_mult_val;
    uint32_t n_div_val;
    uint32_t m1_div_val;
    uint32_t m2_div_val;
    uint32_t m3_div_val = 0;
    uint32_t pllhsdiv4_val = 0;
    uint32_t pllhsdiv3_val = 0;
    uint32_t pllhsdiv2_val = 0;
    uint32_t pllhsdiv1_val = 0;
    uint32_t pll_base_addr;
    volatile uint32_t index;

    /**
     *  Initalize variables
     *  All clock values in MHz
     *  Assume some dividers are implemented in reality as +1 
     *  (prevents dividing by zero) 
     *
     */
    clkin_val = 25;
    if(read_pid != PSC_PID)
    {
        pll_base_addr   = keystoneM3PllcRegs[data->pll].pllbaseaddrs;
    }
    else
    {
        pll_base_addr   = keystonePllcRegs[data->pll].pllbaseaddrs;
    }


    /* MCU PLL & CPSW PLL */
    if((data->pll == CSL_MCU_PLL) || (data->pll == CSL_CPSW_PLL))
    {
        m_frac_mult_val = data->m_frac_mult;
        m_int_mult_val = data->m_int_mult; 
        n_div_val = data->n_div;

        m1_div_val = data->m1_div;
        m2_div_val = data->m2_div;  
        m3_div_val = data->m3_div;
        pllhsdiv4_val = data->hsdiv4; 
        pllhsdiv3_val = data->hsdiv3; 
        pllhsdiv2_val = data->hsdiv2; 
        pllhsdiv1_val = data->hsdiv1; 
  
    }
    /* MAIN PLL & PER1 PLL */
    else if((data->pll == CSL_MAIN_PLL ) || (data->pll == CSL_PER1_PLL))
    {
        m_frac_mult_val = data->m_frac_mult;
        sd_div_val = data->sd_div;
        
        m_int_mult_val = data->m_int_mult; 
        n_div_val = data->n_div;

        m1_div_val = data->m1_div;
        m2_div_val = data->m2_div;  
        pllhsdiv4_val = data->hsdiv4; 
        pllhsdiv3_val = data->hsdiv3; 
        pllhsdiv2_val = data->hsdiv2; 
        pllhsdiv1_val = data->hsdiv1; 

    }
    /* ARM0 PLL & ARM1 PLL */
    else if((data->pll == CSL_ARM0_PLL) ||(data->pll == CSL_ARM1_PLL))
    {
        m_frac_mult_val = data->m_frac_mult;
    
        m_int_mult_val = data->m_int_mult; 
        n_div_val = data->n_div;

        m1_div_val = data->m1_div;
        m2_div_val = data->m2_div;  
        m3_div_val = data->m3_div;
    }
    else  /* DDR PLL ,PER0 PLL & DSS PLL */
    {
        m_frac_mult_val = data->m_frac_mult;
        sd_div_val = data->sd_div;
        
        m_int_mult_val = data->m_int_mult; 
        n_div_val = data->n_div;

        m1_div_val = data->m1_div;
        m2_div_val = data->m2_div;  
    }

    /* set dc corrector if clkout frequency greater than 1.4GHz,
       only for ADPLLM */
    if(data->pll_type)
    {
        temp1 = ((float) clkin_val*(m_int_mult_val + m_frac_mult_val))/
                ((n_div_val+1)*(m2_div_val));
        if(temp1 >= (float) 1400)
        {
            /* bit 27 (DC_CORRECTOR_EN) of PLL_CTRL set to 1 */
            CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
                    MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_DC_CORRECTOR_EN, 1);
        }
    }

    /* Initiate programming sequence by clearning programming bits */
    /* bits 1:0 (PROG_SM) of PLL_PROG set to 00 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TINIT_Z, 0);
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)), 
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TENABLE, 0);

    /* bit 8 (DIV_PROG) of PLL_PROG set to 0, null operation */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TENABLEDIV, 0);
    

    /* write multiplier/divider values to registers independent of PLL type */
    /* bits 17:0 (M_FRAC_MULT) of PLL_FREQ_CTRL1  NQ */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL1_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL1_M_FRAC_MULT, m_frac_mult_val);


    /* write multiplier/divider values to registers based on PLL type */
    if(data->pll_type)
    {
        /* write values to freq ctrl 0 register */
        
        /* bits 18:8 (M_INT_MULT) of PLL_FREQ_CTRL0 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL0_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL0_M_INT_MULT, m_int_mult_val);
        
        /* bits 6:0 (N_DIV) of PLL_FREQ_CTRL0 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL0_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL0_NDIV, n_div_val);

        /* write M1/M2 values to clkdiv register */
        
        /* bits 3:0 (M1_DIV) of PLL_CLKDIV */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CLK_DIV_M1_DIV, m1_div_val);
        
        /* bits 12:8 (M2_DIV) of PLL_CLKDIV */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CLK_DIV_M2_DIV, m2_div_val);
        
        /* bits 20:16 (M3_DIV) of PLL_CLKDIV */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CLK_DIV_M3_DIV, m3_div_val);
        
    }else/* PLLLJM */
    {
        /* write values to freq ctrl 0 register */
        
        /* bits 31:24 (SD_DIV) of PLL_FREQ_CTRL0 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL0_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL0_SD_DIV, sd_div_val);
        
        /* bits 19:8 (M_INT_MULT) of PLL_FREQ_CTRL0   */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL0_OFFSET)),
              MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL0_M_INT_MULT, m_int_mult_val);

        /* bits 7:0 (N_DIV) of PLL_FREQ_CTRL0 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL0_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL0_NDIV, n_div_val);

        /* determine correct SEL_FREQ_DCO value and write value to freq
           ctrl 1 register */
        temp1 = ((float) clkin_val*(m_int_mult_val + m_frac_mult_val))/
                (n_div_val+1);

        if(temp1 >= (float) 1375 && temp1 <= (float) 2500)
        {
            /* bits 26:24 (SEL_FREQ_DCO) of PLL_FREQ_CTRL1 set to 100 */
            CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL1_OFFSET)),
                    MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL1_SEL_FREQ_DCO, 0x04);

        }else {
            /* bits 26:24 (SEL_FREQ_DCO) of PLL_FREQ_CTRL1 set to 010 */
            CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_FREQ_CTRL1_OFFSET)),
                    MAIN_PLL_MMR_CFG_PLL0_PLL_FREQ_CTL1_SEL_FREQ_DCO, 0x02);
            }
        
        /* bits 3:0 (M1_DIV) of PLL_CLKDIV */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CLK_DIV_M1_DIV, m1_div_val);
        
        /* bits 14:8 (M2_DIV) of PLL_CLKDIV */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_PLL_CLK_DIV_M2_DIV, m2_div_val);
  
    }
    /* program all values into register  */
    
    /* bits 1:0 (PROG_SM) of PLL_PROG set to 10  */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TINIT_Z, 0);
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TENABLE, 1);
 
    /* bit 8 (DIV_PROG) of PLL_PROG set to 1  */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TENABLEDIV, 1);

    for(index = 0; index < DELAY; index++);


    /* bit 8 (DIV_PROG) of PLL_PROG set to 0, null operation */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
    MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TENABLEDIV, 0);

    /* initiate locking sequence */
    
    /* bits 1:0 (PROG_SM) of PLL_PROG set to 11 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TINIT_Z, 1);
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_PROG_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_PROG_TENABLE, 1);
    
    /* bit 7 (IDLE) of PLL_CTRL set to 0 */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_CTRL_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_CTRL_IDLE, 0);
    


    /* poll bit 7 (BYPASS_ACK) of PLL_STAT for 0 */
    while(CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
                   MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_BYPASS_ACK));
    /* poll bit 25 (FREQLOCK) of PLL_STAT for 1 */
    while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
                    MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_FREQLOCK));
    /* poll bit 24 (PHASELOCK) of PLL_STAT for 1 */
    while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_STAT_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_PHASELOCK));
  
    if(data->hsdiv_exist)
    {
        /* clear programming bit */
        
        /* bit 31 (TENABLEDIV) of HSDIV_CTRL set to 0, null   operation */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL_TENABLEDIV, 0);
        
        /* wait until HSDIV is locked,then program div values into registers */
        /* poll bit 15 (LOCK) of HSDIV_STAT for 1 */
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + 
            PLL_HSDIV_STAT_OFFSET)),MAIN_PLL_MMR_CFG_PLL0_HSDIV_STAT_LOCK));
        
        /* bits 29:24 (HSDIV4) of HSDIV_CLKDIV */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CLKDIV_HSDIV4, pllhsdiv4_val);
        
        /* bit 21:16 (HSDIV3) of HSDIV_CLKDIV */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CLKDIV_HSDIV3, pllhsdiv3_val);
        
        /* bits 13:8 (HSDIV2) of HSDIV_CLKDIV  */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CLKDIV_HSDIV2, pllhsdiv2_val);
        
        /* bits 5:0 (HSDIV1) of HSDIV_CLKDIV  */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CLKDIV_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CLKDIV_HSDIV1, pllhsdiv1_val);
        
        /* bit 31 (TENABLEDIV) of HSDIV_CTRL set to 1  */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL_TENABLEDIV, 1U); 

        /* Enable HSDIV clks now that div values have been programmed  */
        
        /* bit 3 (CLKOUT4_EN) of HSDIV_CTRL set to 1 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL_CLKOUT4_EN, 1);
        /* poll bit 3 (CLKOUT4_EN_ACK) of HSDIV_STAT for 1  */
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_STAT_CLKOUT4_EN_ACK));
        
        /* bit 2 (CLKOUT3_EN) of HSDIV_CTRL set to 1 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL_CLKOUT3_EN, 1);
        /* poll bit 2 (CLKOUT3_EN_ACK) of HSDIV_STAT for 1 */
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_STAT_CLKOUT3_EN_ACK));
        
        /* bit 1 (CLKOUT2_EN) of HSDIV_CTRL set to 1 */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL_CLKOUT2_EN, 1);
        
        /* poll bit 1 (CLKOUT2_EN_ACK) of HSDIV_STAT for 1 */
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_STAT_CLKOUT2_EN_ACK));
        
        /* bit 0 (CLKOUT1_EN) of HSDIV_CTRL set to 1  */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL_CLKOUT1_EN, 1);
        
        /* poll bit 0 (CLKOUT1_EN_ACK) of HSDIV_STAT for 1 */
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_STAT_CLKOUT1_EN_ACK));

        /* wait for HSDIV to relock */

        /* poll bit 15 (LOCK) of HSDIV_STAT for 1 */
        while(!CSL_FEXT((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_STAT_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_STAT_LOCK));

        /* clear programming bit again  */
        
        /* bit 31 (TENABLEDIV) of HSDIV_CTRL set to 0, null operation */
        CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_HSDIV_CTRL_OFFSET)),
                MAIN_PLL_MMR_CFG_PLL0_HSDIV_CTRL_TENABLEDIV, 0);
    }

}

/**
 * \brief  PLL Controller programming function
 *
 * Initializes the control register values and sets the controller dividers
 * and intiates the GO operation.
 * The GO operation is required to change the divider ratios of the 
 * PLLDIVn registers
 *  
 * \param  data [IN] PLL config structure pointer
 *
 * \return None
 */
static void Board_PLLCtrlProgram(const pllcConfig *data)
{
    uint32_t pllctrl_bpdiv_val;
    uint32_t pllctrl_od1_val;
    uint32_t pllctrl_div1_val;
    uint32_t ctrl_base_addr;

    /* initialize variables */ 
    pllctrl_bpdiv_val = data->bpdiv_val; 
    pllctrl_od1_val   = data->od1_val; 
    pllctrl_div1_val  = data->div1_val; 
    ctrl_base_addr    = keystonePllcRegs[data->pll].ctrlbaseaddrs;

    /* write values to PLL controller registers */
    /* bits 7:0 (RATIO) of BPDIV */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_BPDIV_OFFSET)),
            pllctrl_bpdiv_val, 8, 0); 

    /* bits 7:0 (RATIO) of OSCDIV1 */ 
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_OSCDIV1_OFFSET)),
            pllctrl_od1_val, 8, 0);

    /* clear programming bit */
    /* bit 0 (GOSET) of PLLCMD set to 0, null operation */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCMD_OFFSET)), 0, 1, 0);

    /* wait until no other GOSET operation in progress, the program PLL 
       controller values */
  
    /* poll bit 0 (GOSTAT) of PLLSTAT for 0 */
    while(READBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLSTAT_OFFSET)),
            1, 0)) ;
  
    /* bits 7:0 (RATIO) of PLLDIV1 */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLDIV1_OFFSET)),
            pllctrl_div1_val, 8, 0); 

    /* bit 0 (ALN1) of ALNCTL set to 0, free */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_ALNCTL_OFFSET)),
            0, 1, 0);

    /* bit 0 (GOSET) of PLLCMD set to 1 */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCMD_OFFSET)),
            1, 1, 0);

    /* poll bit 0 (GOSTAT) of PLLSTAT for 0 */
    while(READBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLSTAT_OFFSET)),
            1, 0));

    /* bit 0 (GOSET) of PLLCMD set to 0, null operation */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCMD_OFFSET)), 0, 1, 0); 
    
    /* turn off PLL controller reset */
    /* bit 3 (PLLRST) of PLLCTL set to 0 */
    SETBITS((*(volatile uint32_t *)(ctrl_base_addr + PLL_CTRL_PLLCTL_OFFSET)), 0, 1, 3);

}

/**
 * \brief  PLL initialization function
 *
 * Configures different PLL controller modules.
 * After reset,PLL initialization procedures must be done properly 
 * to set up the PLLs and PLL Controllers
 *  
 * \param  data [IN] PLL config structure pointer
 *
 * \return None
 */
static void Board_PLLConfig(const pllcConfig *data)
{
  
    uint32_t pll_base_addr;
    uint32_t ctrl_base_addr;
    uint32_t pll_type_adpllm;
    uint32_t ctrl_exist;

    read_pid = *(uint32_t *)MAIN_PSC_BASE;
    if(read_pid != PSC_PID)
    {
        pll_base_addr   = keystoneM3PllcRegs[data->pll].pllbaseaddrs;
        ctrl_base_addr  = keystoneM3PllcRegs[data->pll].ctrlbaseaddrs;
    }
    else
    {
        pll_base_addr   = keystonePllcRegs[data->pll].pllbaseaddrs;
        ctrl_base_addr  = keystonePllcRegs[data->pll].ctrlbaseaddrs;
    }

    pll_type_adpllm = data->pll_type;
    ctrl_exist      = data->ctrl_exist;

    /* unlock registers */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_KICK0_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_KICK0_KICK0_VAL, KICK0_UNLOCK);
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_KICK1_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_KICK1_KICK1_VAL, KICK1_UNLOCK);

    /* if BYPASS_ACK = 1, then started in bypass mode, 
       need to perform 1st time setup */
    /* read bit 7 (BYPASS_ACK) of   register PLL_STAT */
    if(CSL_FEXT((pll_base_addr + PLL_STAT_OFFSET),
                MAIN_PLL_MMR_CFG_PLL0_PLL_STAT_BYPASS_ACK))
    {

        /* set needed registers for PLL/HSDIV operation */
        Board_PLLSetup(pll_base_addr, pll_type_adpllm );

        /* set needed registers for PLL controller operation if it exisits */
        if(ctrl_exist)
        {
            Board_PLLCtrlSetup(ctrl_base_addr);
        }

    }else /* not in bypass mode, initial setup already done */
    {
        /* place PLL and HSDIV in bypass mode and put PLL ctrl in reset,
           disable HSDIV output clocks for programming */
        Board_PLLSecondarySetup(pll_base_addr, ctrl_base_addr, ctrl_exist, pll_type_adpllm);

    }

    /* program multiplier/divider values into PLL/HSDIV */
    Board_PLLProgram(data);

    /* program multiplier/divider values into PLL CTRL if it exists */
    if(ctrl_exist)
    {
        Board_PLLCtrlProgram(data);
    }

    /* relock kick registers */
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_KICK0_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_KICK0_KICK0_VAL, KICK_LOCK);
    CSL_FINS((*(volatile uint32_t *)(pll_base_addr + PLL_KICK1_OFFSET)),
            MAIN_PLL_MMR_CFG_PLL0_KICK1_KICK1_VAL, KICK_LOCK);

}
#endif
/**
 * \brief  PLL clock enable
 *
 * This function is used to set the PLL Module clock frequency
 *
 * \param  moduleId [IN]  Module for which the state should be set.
 *                        Refer Sciclient_PmDeviceIds in sciclient_fmwMsgParams.h
 * \param  clockId  [IN]  Clock Id for the module.
 *                        Refer Sciclient_PmModuleClockIds in sciclient_fmwMsgParams.h
 * \param  clkRate  [IN]  Value of the clock frequency to be set
 *
 * \return int32_t
 *                CSL_PASS - on Success
 *                CSL_EFAIL - on Failure
 *
 */
static int32_t Board_PLLSetModuleClkFreq(uint32_t modId,
                                         uint32_t clkId,
                                         uint64_t clkRate)
{
    uint8_t parentId = 0;
    uint32_t i = 0U;
    int32_t status   = 0;
    uint64_t respClkRate = 0;
    uint32_t clockBaseId = 0U;
    uint32_t numParents = 0U;
    uint32_t clockStatus;

    status = Sciclient_pmQueryModuleClkFreq(modId,
                                        clkId,
                                        clkRate,
                                        &respClkRate,
                                        SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status == CSL_PASS)
    {
        /* Check if the clock is enabled or not */
        status = Sciclient_pmModuleGetClkStatus(modId,
                                                clkId,
                                                &clockStatus,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
    }

    if(status == CSL_PASS)
    {
        /* Check if the clock is enabled or not */
        status = Sciclient_pmGetModuleClkNumParent(modId,
                                                clkId,
                                                &numParents,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
    }

    if ((status == CSL_PASS) && (respClkRate == clkRate))
    {
        status = Sciclient_pmSetModuleClkFreq(
                                modId,
                                clkId,
                                clkRate,
                                TISCI_MSG_FLAG_CLOCK_ALLOW_FREQ_CHANGE,
                                SCICLIENT_SERVICE_WAIT_FOREVER);
        if (status == CSL_PASS)
        {
            if (clockStatus == TISCI_MSG_VALUE_CLOCK_SW_STATE_UNREQ)
            {
                /* Enable the clock */
                status = Sciclient_pmModuleClkRequest(
                                                    modId,
                                                    clkId,
                                                    TISCI_MSG_VALUE_CLOCK_SW_STATE_REQ,
                                                    0U,
                                                    SCICLIENT_SERVICE_WAIT_FOREVER);
            }
        }
    }
    else if (status == CSL_PASS)
    {
        /* Try to loop and change parents of the clock */
        for(i = 0U; i < numParents; i++)
        {
            /* Disabling the clock */
            status = Sciclient_pmModuleClkRequest(modId,
                                                  clkId,
                                                  TISCI_MSG_VALUE_CLOCK_SW_STATE_UNREQ,
                                                  0U,
                                                  SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status == CSL_PASS)
            {
                clockStatus = TISCI_MSG_VALUE_CLOCK_SW_STATE_UNREQ;
                /* Setting the new parent */
                status = Sciclient_pmSetModuleClkParent(
                                        modId,
                                        clkId,
                                        clkId+i+1,
                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            }
            /* Check if the clock can be set to desirable freq. */
            if (status == CSL_PASS)
            {
                status = Sciclient_pmQueryModuleClkFreq(modId,
                                                        clkId,
                                                        clkRate,
                                                        &respClkRate,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            }
            if (status == CSL_PASS)
            {
                if(respClkRate == clkRate)
                {
                    break;
                }
                else
                {
                    status = CSL_EFAIL;
                }
            }
            parentId++;
            clockBaseId++;
        }

        if (status == CSL_PASS)
        {   
            /* Set the clock at the desirable frequency*/
            status = Sciclient_pmSetModuleClkFreq(
                                    modId,
                                    clkId,
                                    clkRate,
                                    TISCI_MSG_FLAG_CLOCK_ALLOW_FREQ_CHANGE,
                                    SCICLIENT_SERVICE_WAIT_FOREVER);
        }
        if((status == CSL_PASS) && (clockStatus == TISCI_MSG_VALUE_CLOCK_SW_STATE_UNREQ))
        {
            /*Enable the clock again */
            status = Sciclient_pmModuleClkRequest(
                                                modId,
                                                clkId,
                                                TISCI_MSG_VALUE_CLOCK_SW_STATE_REQ,
                                                0U,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
        }
    }

    return status;
}

/**
 * \brief  Function to initialize module clock frequency
 *
 * \param  moduleId [IN]  Module for which the state should be set.
 *                        Refer Sciclient_PmDeviceIds in sciclient_fmwMsgParams.h
 * \param  clockId  [IN]  Clock Id for the module.
 *                        Refer Sciclient_PmModuleClockIds in sciclient_fmwMsgParams.h
 * \param  clkRate  [IN]  Value of the clock frequency to be set

 * \return Board_STATUS
 */
Board_STATUS Board_PLLInit(uint32_t modId,
                           uint32_t clkId,
                           uint64_t clkRate)
{
    int32_t  status = CSL_EFAIL;

    status = Board_PLLSetModuleClkFreq(modId, clkId, clkRate);
    if(status != CSL_PASS)
    {
        return BOARD_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  Function to initialize all the PLL clocks with default values
 *
 * \return Board_STATUS
 */
Board_STATUS Board_PLLInitAll(void)
{
    Board_STATUS  status = CSL_PASS;
    uint8_t index;
    uint32_t loopCount;

    const uint32_t dev_id[] =
    {
        TISCI_DEV_SERDES0,      //CSL_MAIN_PLL*/
        TISCI_DEV_DDRSS0,       //CSL_DDR_PLL
        TISCI_DEV_SA2_UL0,      //CSL_PER1_PLL
        TISCI_DEV_OLDI_TX_CORE_MAIN_0 //CSL_DSS_PLL
    };

    const uint32_t clock_id[] =
    {
        TISCI_DEV_SERDES0_BUS_LI_REFCLK,
        TISCI_DEV_DDRSS0_BUS_DDRSS_BYP_4X_CLK,
        TISCI_DEV_SA2_UL0_BUS_PKA_IN_CLK,
        TISCI_DEV_OLDI_TX_CORE_MAIN_0_BUS_OLDI_PLL_CLK
    };

    const uint32_t pll_freq_hz[] =
    {
        CSL_MAIN_PLL_CLK_FREQ,
        CSL_DDR_PLL_CLK_FREQ,
        CSL_PER1_PLL_CLK_FREQ,
        CSL_DSS_PLL_CLK_FREQ
    };

    loopCount = sizeof (pll_freq_hz)/sizeof(uint32_t);

    for (index = 0; index < loopCount; index++)
    {
        status = Board_PLLInit(dev_id[index],
                               clock_id[index],
                               pll_freq_hz[index]);
        if(status != BOARD_SOK)
        {
            return BOARD_FAIL;
        }
    }

    Board_PLLConfig(&pllcConfigs[CSL_PER0_PLL]);
    Board_PLLConfig(&pllcConfigs[CSL_MCU_PLL]);
    Board_PLLConfig(&pllcConfigs[CSL_CPSW_PLL]);

    return status;
}
