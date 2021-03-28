/**
 *  @file   lcdkOMAPL138_ddr.c
 *
 *  @brief  DDR initialization routines for OMAPL138 LCDK
 *
 *  ============================================================================
 */
/******************************************************************************
 * Copyright (c) 2017 Texas Instruments Incorporated - http://www.ti.com
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


#include "board_internal.h"

/*
 *  \brief  Set the desired DDR3 configuration
 *  
 *  \return None
 */
Board_STATUS Board_DDR3Init(void)
{
    uint32_t j;
    uint32_t tmp_SDCR;
    uint32_t freq = 150;
    uint32_t VTPIOCtlReg = 0;

    Board_moduleClockEnable(CSL_PSC_DDR);
    
    /* Begin VTP Calibration */
    CSL_SysCfg1ReadReg(VtpIOCTL, &VTPIOCtlReg);

    /* Clear POWERDN */
    VTPIOCtlReg &= ~0x00000040;
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);

    VTPIOCtlReg &= ~0x00000080;       /* Clear LOCK */
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);

    VTPIOCtlReg |=  0x00002000;       /* Set CLKRZ in case it was cleared before (VTP looks for CLKRZ edge transition) */
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);

    VTPIOCtlReg &= ~0x00002000;       /* Clear CLKRZ (Use read-modify-write to ensure 1 VTP cycle wait for previous instruction) */
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);

    VTPIOCtlReg |=  0x00002000;       /* Set CLKRZ (Use read-modify-write to ensure 1 VTP cycle wait for previous instruction) */
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);

    j = 0;
    /* Polling READY bit to see when VTP calibration is done */
    do
    {
        CSL_SysCfg1ReadReg(VtpIOCTL, &VTPIOCtlReg);
        if( j++ > VTP_TIMEOUT ) 
        {
            return (BOARD_INIT_DDR_FAIL);
        }

    } while((VTPIOCtlReg & 0x00008000) == 0);

    VTPIOCtlReg |= 0x00000080;       /* Set LOCK bit for static calibration mode */
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);

    VTPIOCtlReg |= 0x00000040;       /* Set POWERDN bit to power down VTP module */
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);
    /* End VTP Calibration */

    VTPIOCtlReg |= 0x00004000;       /* Set IOPWRDN to allow powerdown of input receivers when PWRDNEN is set */
    CSL_SysCfg1WriteReg(VtpIOCTL, VTPIOCtlReg);

    /* Setting based 1Gb DDR2 Samsung K4T1G164QF-BCF8 */
    /* Config DDR timings */
    hDDR2Cfg->DRPYC1R     = (0x0               << 8)   |  // Reserved
                            (0x1               << 7)   |  // EXT_STRBEN
                            (0x1               << 6)   |  // PWRDNEN
                            (0x0               << 3)   |  // Reserved
                            (0x4               << 0);     // RL
    /* DRPYC1R Value = 0x000000C4 */

    hDDR2Cfg->SDCR |= 0x00800000; /* Set BOOTUNLOCK */

    /* Settings depending on DDR2 */
    tmp_SDCR = (0x0 << 25)  |  /* MSDRAMEN */
               (0x1 << 20);    /* DDR2EN */

    hDDR2Cfg->SDCR = tmp_SDCR                    |  /* Settings that change depending on DDR2 or MDDR */
                     (hDDR2Cfg->SDCR & 0xF0000000) |  /* Reserved */
                     (0x0               << 27)   |  /* DDR2TERM1 */
                     (0x0               << 26)   |  /* IBANK_POS */
                     (0x0               << 24)   |  /* DDRDRIVE1 */
                     (0x0               << 23)   |  /* BOOTUNLOCK */
                     (0x0               << 22)   |  /* DDR2DDQS */
                     (0x0               << 21)   |  /* DDR2TERM0 */
                     (0x0               << 19)   |  /* DDRDLL_DIS */
                     (0x0               << 18)   |  /* DDRDRIVE0 */
                     (0x1               << 17)   |  /* DDREN */
                     (0x1               << 16)   |  /* SDRAMEN */
                     (0x1               << 15)   |  /* TIMUNLOCK */
                     (0x1               << 14)   |  /* NM */
                     (0x0               << 12)   |  /* Reserved */
                     (0x4               << 9)    |  /* CL */
                     (0x0               << 7)    |  /* Reserved */
                     (0x3               << 4)    |  /* IBANK */
                     (0x0               << 3)    |  /* Reserved */
                     (0x2               << 0);      /* PAGESIZE */
    
    hDDR2Cfg->SDCR2   = 0x00000000;  /* IBANK_POS set to 0 so this register does not apply */

    /* Let float -> integer truncate handle minus 1; Safer to round up for timings */
    hDDR2Cfg->SDTIMR1 = (((uint32_t) (127.5 * freq / 1000))  << 25)  |  /* tRFC */
                        (((uint32_t) (13.13 * freq / 1000))  << 22)  |  /* tRP */
                        (((uint32_t) (13.13 * freq / 1000))  << 19)  |  /* tRCD */
                        (((uint32_t) ( 15.0 * freq / 1000))  << 16)  |  /* tWR */
                        (((uint32_t) ( 45.0 * freq / 1000))  << 11)  |  /* tRAS */
                        (((uint32_t) (58.13 * freq / 1000))  << 6)   |  /* tRC */
                        (((uint32_t) (  7.5 * freq / 1000))  << 3)   |  /* tRRD */
                        (hDDR2Cfg->SDTIMR1 & 0x4)                          |  /* Reserved */
                        ((2 - 1)                                 << 0);     /* tWTR */
    
    hDDR2Cfg->SDTIMR2 = (hDDR2Cfg->SDTIMR2 & 0x80000000)                    |  /* Reserved */
                        (((uint32_t) ((70000 / 7800) - 1))   << 27)   |  /* tRASMAX (original 3400) */
                        ((0x3-1)                                 << 25)   |  /* tXP (Should be 6-1 per MT46H64M16LFBF-6 datasheet, but field only goes up to 0b11) */
                        (0x0                                     << 23)   |  /* tODT (Not supported) */
                        (((uint32_t) (137.5 * freq / 1000))  << 16)   |  /* tXSNR (tXSR for mDDR) */
                        ((200-1)  							   << 8)    |  /* tXSRD (tXSR for mDDR) */
                        ((2 - 1)                                 << 5)    |  /* tRTP */
                        ((3 - 1)                                 << 0);      /* tCKE */
  
    hDDR2Cfg->SDCR   &= ~0x00008000; /* Clear TIMUNLOCK */

    /* Let float -> integer truncate handle RR round-down; Safer to round down for refresh rate */
    hDDR2Cfg->SDRCR   = (0x1                                  << 31)  |  /* LPMODEN (Required for LPSC SyncReset/Enable) */
                        (0x1                                  << 30)  |  /* MCLKSTOPEN (Required for LPSC SyncReset/Enable) */
                        (0x0                                  << 24)  |  /* Reserved */
                        (0x0                                  << 23)  |  /* SR_PD */
                        (0x0                                  << 16)  |  /* Reserved */
                        (((uint32_t) (7.8 * freq))  	    << 0);     /* RR  (original 7.8125) */

    /* SyncReset the Clock to EMIFDDR SDRAM */
    Board_moduleClockSyncReset(CSL_PSC_DDR);
    Board_moduleClockEnable(CSL_PSC_DDR);

    /* Disable self-refresh */
    hDDR2Cfg->SDRCR &= ~0xC0000000;
    hDDR2Cfg->PBBPR = 0x30;
    
    return (BOARD_SOK);
}
