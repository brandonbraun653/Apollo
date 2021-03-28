/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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

/**
 *
 *  \file  evmk2g_dss.c
 *
 *  \brief This file contains DSS specific functions.
 *
 ******************************************************************************/

#include "platform_internal.h"
#ifdef DISPLAY_LOGO
#include "ti_logo.h"
#endif
#if (PLATFORM_DSS_IN)

volatile Uint32 *pFrameBuffer = (volatile Uint32 *)(DDR_FRAME_ADDRESS_START);
volatile Uint32 count = 0;
volatile Uint32 count_underflow[11];
volatile Uint32 uf_index = 0;

#define ENABLE        (1)
#define DISABLE       (0)

/**
 *  \brief    Writes 32 bit value to a register/memory
 *
 *  This function write a given 32 bit data to the passed address.
 *  This function is mainly used to configure the registers of DSS
 *
 *  \param    baseAddr   [IN]   Base address
 *  \param    writeData [IN]   write data to be written to the address.
 *
 *  \return    - NONE
 */
static void reg_wr_32(Uint32 baseAddr,Uint32 writeData)
{
  (*(Uint32 *) (baseAddr)) = writeData;
}

/**
 *  \brief    Read 32 bit value from a register/memory
 *
 *  This function reads a 32 bit data from the given address.
 *  This function is mainly used to validate/read the status of the DSS
 *  registers.
 *
 *  \param    baseAddr   [IN]   Base address
 *
 *  \return    - read_data - 32 bit value read from the address
 */
static Uint32 reg_rd_32(Uint32 baseAddr)
{
  Uint32 read_data;
  read_data = (*(Uint32 *) (baseAddr));
  return read_data;
}

/**
 *  \brief    Puts the given color to the frame buffer
 *
 *  This function puts the color passed as parameter to the
 *  frame buffer to display the given color. This function is
 *  used to test the LCD, frame buffer by passing any desired
 *  color.
 *
 *  \param    plcdCfg   [IN]   pointer to lcdCfg to get height and width
 *  \param    color     [IN]   color to be displayed on the Display panel
 *
 *  \return   NONE
 */
void dssFrameBufferColor(lcdCfg_t *plcdCfg, Uint32 color)
{
  unsigned int x,y;

  for (y = 0; y < plcdCfg->LcdHeight; y++)
    for (x = 0; x < plcdCfg->LcdWidth; x++)
        *(pFrameBuffer + (y * plcdCfg->LcdWidth) + (x) ) = color;

}

/**
 *  \brief    Puts the given pic array to the frame buffer
 *
 *  This function puts the array passed as parameter to the
 *  frame buffer to display the given image.
 *
 *  \param    plcdCfg   [IN]   pointer to lcdCfg to get height and width
 *  \param    array     [IN]   array to be displayed on the Display panel
 *
 *  \return   NONE
 */
#ifdef DISPLAY_LOGO
void dssFillFrameBuffer(void)
{
	memcpy(TI_logo_rgb32,(const void *) 0x88000000, sizeof(TI_logo_rgb32));
}
#endif

/**
 *  \brief    Initialize the Frame buffer
 *
 *  This function performs initialization of frame buffer, loading of color bar
 *  information to the frame buffer or loading a constant value to the frame
 *  buffer.
 *
 *  \param    mode   [IN]   mode of operation for frame buffer
 *  \param    height [IN]   height of the frame buffer
 *  \param    width  [IN]   width of the frame buffer
 *
 *  \return   NONE
 */
void dssInitFrameBuffer(Uint32 mode, Uint32 width, Uint32 height) {

    Uint32 i = 0;
    Uint32 j = 0;
    Uint32 count = 0;
    Uint32 secondCount = 0;
    Uint32 currentColor = RED;

    switch (mode) {
        case RGB888_CONSTANT:
            for (j = 0; j < (height * width); j++) {
                *(pFrameBuffer + j) = 0xAAAAAA;
            }
            break;
        case RGB888_GENERATE:
            for(i = 0; i < (height * width); i++){
                if ((i % width) == 0) {
                    count = count + 1;
                }
                if (count == height/6) {
                    count = 0;
                    secondCount = secondCount + 1;
                    if (secondCount == 1){
                        currentColor = GREEN;
                    }
                    else if (secondCount == 2){
                        currentColor = BLUE;
                    }
                    else if (secondCount == 3){
                        currentColor = PURPLE;
                    }
                    else if (secondCount == 4){
                        currentColor = YELLOW;
                    }
                    else if (secondCount == 5){
                        currentColor = PINK;
                    }
                }
                *(pFrameBuffer + i) = currentColor;
            }

            break;
        case RGB888_ADDRESS:
            for (j = 0; j < (height * width); j++) {
                *(pFrameBuffer + j) = (0x88000000+(j*4));
            }
            break;
        default:
            break;
    }
}

/**
 *  \brief    Configures DISPC_GLOBAL_MFLAG_ATTRIBUTE Register
 *
 *  This function configures the Mflag attribute configuratin
 *
 *  \param    baseAddr   [IN]   base address of DSSUL Common cfg register
 *  \param    start      [IN]   value of MFlag START to be configured
 *  \param    control    [IN]   value of MFlag control to be configured
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 *
 */
DSS_RET dssDispcMflagAttributeCfg(Uint32 baseAddr, Uint32 start, Uint32 control)
{
    DSS_RET status = DSS_RET_FAILED;
    Uint32 value = 0;
    Uint32 value_start = 0;
    Uint32 value_control = 0;

    value_start = ((start << \
           CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_START_SHIFT) \
        & (CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_START_MASK));

    if ((start == CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_START_MFLAGNORMALSTARTMODE) ||
        (start == CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_START_MFLAGFORCESTARTMODE))
    {
        value_start = start;
        status = DSS_RET_OK;
    }

    value_control = ((control << CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_CTRL_SHIFT) \
                      & (CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_CTRL_MASK));
    if ((control == CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_CTRL_MFLAGDIS) || \
        (control == CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_CTRL_MFLAGFORCE) ||\
        (control == CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE_MFLAG_CTRL_MFLAGEN))
    {
        value_control = control;
        status = DSS_RET_OK;
    }

    if (status == DSS_RET_OK)
    {
        value = value_start | value_control;
        reg_wr_32(baseAddr + CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE, value);
    }
    return status;
}

/**
 *  \brief    Configures DISPC_GLOBAL_MFLAG_ATTRIBUTE Register
 *
 *  This function configures the Mflag attribute configuratin
 *
 *  \param    baseAddr     [IN]   base address of DSSUL Video config register
 *  \param    lo_threshold [IN]   value of low threshold
 *  \param    hi_threshold [IN]   value of high threshold
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcMflagThresholdCfg(Uint32 baseAddr,
                                  Uint32 lo_threshold,
                                  Uint32 hi_threshold)
{
    DSS_RET status = DSS_RET_OK;
    Uint32 value = 0;

    if ((lo_threshold > CSL_DSSVID_MFLAG_THRESHOLD_LT_MFLAG_MAX) ||
       (hi_threshold > CSL_DSSVID_MFLAG_THRESHOLD_HT_MFLAG_MAX))
    {
		IFPRINT(UART_printf("ERROR %s: Invalid values for \
								thresholds\n", __FUNCTION__));
        status = DSS_RET_FAILED;
    }
    else
    {
        /* Program X position */
        value = ((lo_threshold << CSL_DSSVID_MFLAG_THRESHOLD_LT_MFLAG_SHIFT) &
            (CSL_DSSVID_MFLAG_THRESHOLD_LT_MFLAG_MASK));
        /* Program Y position */
        value |= ((hi_threshold << CSL_DSSVID_MFLAG_THRESHOLD_HT_MFLAG_SHIFT) &
            (CSL_DSSVID_MFLAG_THRESHOLD_HT_MFLAG_MASK));
        reg_wr_32(baseAddr + CSL_DSSVID_MFLAG_THRESHOLD, value);
    }

    return status;
}

/**
 *  \brief    Configures the DSS initiator priority
 *
 *  This function configures the DSS Initiator priority
 *
 *  \param    baseAddr      [IN]   base address of DSSUL Video config register
 *  \param    lo_priority   [IN]   value of low priority
 *  \param    hi_priority   [IN]   value of high priority
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssInitiatorPriorityCfg(Uint32 baseAddr, Uint32 lo_priority,
                                Uint32 hi_priority)
{
    DSS_RET status = DSS_RET_OK;
    Uint32 value = 0;

    reg_wr_32(KICK0_BASE_ADDRESS, KICK0_UNLOCK);
    reg_wr_32(KICK1_BASE_ADDRESS, KICK1_UNLOCK);

    if (hi_priority > 0x1) {
		IFPRINT (UART_printf("Warning: DSS initiator hi priority is being \
								set to greater than 0x1 \n"));
	}

    if ((lo_priority > 0x7) || (hi_priority > 0x7)) {
        status = DSS_RET_FAILED;
		IFPRINT (UART_printf("DSS initiator priority cannot be greater than\
								0x7\n"));
    }
    else {
        /* Program dss_pri_lo of DSS in Initiator Priority Control Register 1 */
        value = ((lo_priority << DSS_INITIATOR_LOPRI_SHIFT) & (DSS_INITIATOR_LOPRI_MASK));
        /* Program dss_pri_hi of DSS in Initiator Priority Control Register 1 */
        value |= ((hi_priority << DSS_INITIATOR_HIPRI_SHIFT) & (DSS_INITIATOR_HIPRI_MASK));
        reg_wr_32(baseAddr + INITIATOR_PRIORITY_1_OFFSET, value);
    }
    return status ;
}

/**
 *  \brief    Configures panel specific timing parameters
 *
 *  This function configures the DSS Initiator priority
 *
 *  \param    baseAddr  [IN]   base address of DSSUL Video port register
 *  \param    pLcdCfg   [IN]   pointer to LCD configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcLcdPanelCfg(Uint32 baseAddr, lcdCfg_t *pLcdCfg)
{
    Uint32 value = 0;
    DSS_RET status = DSS_RET_OK;

    if (pLcdCfg == NULL)
    {
		IFPRINT(UART_printf("ERROR %s: LCD configuration \
								pointer is NULL\n", __FUNCTION__));
        return DSS_RET_FAILED;
    }

    /* Program pixels per line */
    value = (((pLcdCfg->LcdWidth - 1U) <<
              CSL_DSSVP_SIZE_SCREEN_PPL_SHIFT) &
              (CSL_DSSVP_SIZE_SCREEN_PPL_MASK));

    /* Program lines per panel */
    value |= (((pLcdCfg->LcdHeight - 1U) <<
               CSL_DSSVP_SIZE_SCREEN_LPP_SHIFT) &
              (CSL_DSSVP_SIZE_SCREEN_LPP_MASK));

    reg_wr_32(baseAddr + CSL_DSSVP_SIZE_SCREEN, value);

    /* Program hsw value */
    value = (((pLcdCfg->HsyncWidth - 1U) << CSL_DSSVP_TIMING_H_HSW_SHIFT) &
        (CSL_DSSVP_TIMING_H_HSW_MASK));

    /* Program hfp value */
    value |= (((pLcdCfg->HFrontPorch - 1U) << CSL_DSSVP_TIMING_H_HFP_SHIFT) &
        (CSL_DSSVP_TIMING_H_HFP_MASK));

    /* Program hbp value */
    value |= (((pLcdCfg->HBackPorch - 1U) << CSL_DSSVP_TIMING_H_HBP_SHIFT) &
        (CSL_DSSVP_TIMING_H_HBP_MASK));
    reg_wr_32(baseAddr + CSL_DSSVP_TIMING_H, value);

    /* Program vsw value */
    value = (((pLcdCfg->VsyncWidth - 1U) << CSL_DSSVP_TIMING_V_VSW_SHIFT) &
        (CSL_DSSVP_TIMING_V_VSW_MASK));

    /* Program hfp value */
    value |= ((pLcdCfg->VFrontPorch << CSL_DSSVP_TIMING_V_VFP_SHIFT) &
        (CSL_DSSVP_TIMING_V_VFP_MASK));

    /* Program hbp value */
    value |= ((pLcdCfg->VBackPorch << CSL_DSSVP_TIMING_V_VBP_SHIFT) &
        (CSL_DSSVP_TIMING_V_VBP_MASK));
    reg_wr_32(baseAddr + CSL_DSSVP_TIMING_V, value);

    return status;
}

/**
 *  \brief    Configures LCD color attributes
 *
 *  This function configures the LCD color attributes
 *
 *  \param    baseAddr   [IN]   base address of DSSUL Video port register
 *  \param    pDispCfg   [IN]   pointer to LCD configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcLcdDisplayAttribCfg(Uint32 baseAddr,
                                   dispCfg_t *pDispCfg)
{
    DSS_RET status = DSS_RET_OK;
    Uint32 value  = 0;

    /* Clear display type, monoColor, data lines, mono8bit fields */
    value = reg_rd_32(baseAddr + CSL_DSSVP_CONTROL);

    value &= (~(CSL_DSSVP_CONTROL_STN_MASK | CSL_DSSVP_CONTROL_MONOCOLOR_MASK |
            CSL_DSSVP_CONTROL_VPPROGLINENUMBERMODULO_MASK | CSL_DSSVP_CONTROL_M8B_MASK));

    if (NULL != pDispCfg)
    {
        /* Configure LCD Data Lines */
        value |= ((pDispCfg->dataLines << CSL_DSSVP_CONTROL_DATALINES_SHIFT) &
                    (CSL_DSSVP_CONTROL_DATALINES_MASK));

        /* Configure passive matrix display specific parameters */
        if(DSS_LCD_TYPE_PASSIVE == pDispCfg->displayType)
        {
            /* Configure Color or Monochrome */
            value |= ((pDispCfg->colorMode << CSL_DSSVP_CONTROL_MONOCOLOR_SHIFT) &
                (CSL_DSSVP_CONTROL_MONOCOLOR_MASK));
            /* Configure Mono8 or Mono4 bit */
            if(DSS_LCD_DISPLAY_MONO == pDispCfg->colorMode)
            {
                value |= ((pDispCfg->mono8Bit << CSL_DSSVP_CONTROL_M8B_SHIFT) &
                    (CSL_DSSVP_CONTROL_M8B_MASK));
            }
        }
        reg_wr_32(baseAddr + CSL_DSSVP_CONTROL, value);
    }
    else
    {
		IFPRINT(UART_printf("ERROR %s: LCD configuration \
								pointer is NULL\n", __FUNCTION__));
        status = DSS_RET_FAILED;
    }

    return status;
}

/**
 *  \brief    Configures control signal polarities
 *
 *  This function configures the control signal polarities
 *
 *  \param    baseAddr   [IN]   base address of DSSUL Video port register
 *  \param    pTmgCfg   [IN]   pointer to timing configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcLcdTimingCfg(Uint32 baseAddr,
                            tmgCfg_t *pTmgCfg)
{
    DSS_RET status = DSS_RET_OK;
    Uint32 value = 0;

    //reg_wr_32(baseAddr + CSL_DSSVP_POL_FREQ, 0x4000);
    if (NULL != pTmgCfg)
    {
        /* Program hsync polarity value */
        value = ((pTmgCfg->hsyncPolarity << CSL_DSSVP_POL_FREQ_IHS_SHIFT) &
            (CSL_DSSVP_POL_FREQ_IHS_MASK));
        /* Program vsync polarity value */
        value |= ((pTmgCfg->vsyncPolarity << CSL_DSSVP_POL_FREQ_IVS_SHIFT) &
            (CSL_DSSVP_POL_FREQ_IVS_MASK));
        /* Program sync edge type */
        value |= ((pTmgCfg->syncEdge << CSL_DSSVP_POL_FREQ_RF_SHIFT) &
            (CSL_DSSVP_POL_FREQ_RF_MASK));
        /* Program sync edge control */
        value |= ((pTmgCfg->syncEdgeCtrl << CSL_DSSVP_POL_FREQ_ONOFF_SHIFT) &
            (CSL_DSSVP_POL_FREQ_ONOFF_MASK));
        /* Program Output enable polarity */
        value |= ((pTmgCfg->outputEnablePolarity << CSL_DSSVP_POL_FREQ_IEO_SHIFT) &
            (CSL_DSSVP_POL_FREQ_IEO_MASK));
        /* program acb pin frequency */
        value |= ((pTmgCfg->acbFrequency << CSL_DSSVP_POL_FREQ_ACB_SHIFT) &
            (CSL_DSSVP_POL_FREQ_ACB_MASK));
        /* program acb pin transitions per interrupt */
        value |= ((pTmgCfg->acbi << CSL_DSSVP_POL_FREQ_ACBI_SHIFT) &
            (CSL_DSSVP_POL_FREQ_ACBI_MASK));
        /* program pixel clock polarity */
        value |= ((pTmgCfg->pclkPolarity << CSL_DSSVP_POL_FREQ_IPC_SHIFT) &
            (CSL_DSSVP_POL_FREQ_IPC_MASK));
        /* Write into the register */
        reg_wr_32(baseAddr + CSL_DSSVP_POL_FREQ, value);

        /* Clear clock gated control for sync, acb and pixel clock */
        value = reg_rd_32(baseAddr + CSL_DSSVP_CONFIG);
        value &= (~(CSL_DSSVP_CONFIG_EXTERNALSYNCEN_MASK | CSL_DSSVP_CONFIG_HSYNCGATED_MASK |
                CSL_DSSVP_CONFIG_VSYNCGATED_MASK | CSL_DSSVP_CONFIG_PIXELGATED_MASK));

        /* Program hsync clock gated control */
        value |= ((pTmgCfg->hsyncGated << CSL_DSSVP_CONFIG_HSYNCGATED_SHIFT) &
            (CSL_DSSVP_CONFIG_HSYNCGATED_MASK));
        /* Program vsync clock gated control */
        value |= ((pTmgCfg->vsyncGated << CSL_DSSVP_CONFIG_VSYNCGATED_SHIFT) &
            (CSL_DSSVP_CONFIG_VSYNCGATED_MASK));
        /* Program acb clock gated control */
        value |= ((pTmgCfg->acbGated << CSL_DSSVP_CONFIG_EXTERNALSYNCEN_SHIFT) &   //No gated macro for ACBIAS, these should still work. Need to confirm
            (CSL_DSSVP_CONFIG_EXTERNALSYNCEN_MASK));
        /* Program pixel clock gated control */
        value |= ((pTmgCfg->pixelClkGated << CSL_DSSVP_CONFIG_PIXELCLOCKGATED_SHIFT) &
                CSL_DSSVP_CONFIG_PIXELCLOCKGATED_MASK);
        reg_wr_32(baseAddr + CSL_DSSVP_CONFIG, value);
    }
    else
    {
		IFPRINT(UART_printf("ERROR %s: Timing configuration \
								pointer is NULL\n", __FUNCTION__));
        status = DSS_RET_FAILED;
    }
    return status;
}

/**
 *  \brief    Disables ST Dithering
 *
 *  This function Disables ST Dithering
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *
 *  \return
 *          NONE
 */
void dssDispcSTDitheringDisable(Uint32 baseAddr)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSSVP_CONTROL) & (~CSL_DSSVP_CONTROL_STDITHERENABLE_MASK);
    reg_wr_32(baseAddr + CSL_DSSVP_CONTROL, value);
}

/**
 *  \brief    Bypasses RFBI mode
 *
 *  This function bypasses RFBI mode
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *
 *  \return
 *          NONE
 */
void dssDispcRfbiModeBypass(Uint32 baseAddr)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSSRFBI_RFBI_CONTROL);

    value |= CSL_DSSRFBI_RFBI_CONTROL_BYPASSMODE_BYPASS;
    reg_wr_32(baseAddr + CSL_DSSRFBI_RFBI_CONTROL, value);
}

/**
 *  \brief    Clear existing interrupts
 *
 *  This function clears the interrupt status
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *  \param    intFlag    [IN]   interrupt flag to be cleared
 *
 *  \return
 *          NONE
 */
void dssDispcIntStatusClearEx(Uint32 baseAddr, Uint32 intFlag)
{
    reg_wr_32(baseAddr + CSL_DSSVP_IRQSTATUS, intFlag);
}

/**
 *  \brief    Configures the line number that generates interrupt
 *
 *  This function configures the line number that generates interrupt
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *  \param    lineNumber [IN]   line number that generates interrupt
 *
 *  \return
 *          NONE
 */
void dssDispcProgLineNumberSet(Uint32 baseAddr, Uint32 lineNumber)
{
    Uint32 value = 0;

    /* Clear the line number field */
    value = reg_rd_32(baseAddr + CSL_DSSVP_LINE_NUMBER) & (~CSL_DSSVP_LINE_NUMBER_LINENUMBER_MASK);

    /* Program the line number field */
    value |= ((lineNumber << CSL_DSSVP_LINE_NUMBER_LINENUMBER_SHIFT) & CSL_DSSVP_LINE_NUMBER_LINENUMBER_MASK);
    reg_wr_32(baseAddr + CSL_DSSVP_LINE_NUMBER, value);
}

/**
 *  \brief    Enable/Disable DPI Control
 *
 *  This function enables/disables DPI interface from the registers
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDpiCtrl(Uint32 baseAddr,
                Uint32 enableFlag)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSS_DSS_DPI_CTRL);

    if (TRUE == enableFlag)
    {
        /* Enable DPI interface */
        value |= ((1 << CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_SHIFT) &
            (CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_MASK));
    }
    else
    {
        /* Disable DPI interface */
        value &= (~CSL_DSS_DSS_DPI_CTRL_DPI_ENABLE_MASK);
    }
    reg_wr_32(baseAddr + CSL_DSS_DSS_DPI_CTRL, value);
}

/**
 *  \brief    Enable LCD output
 *
 *  This function enables/disables LCD output
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcLcdOutputEnableCtrl(Uint32 baseAddr, Uint32 enableFlag)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSSVP_CONTROL);

    if (TRUE == enableFlag)
    {
        /* Enable LCD output */
        value |= ((1 << CSL_DSSVP_CONTROL_LCDEN_SHIFT) &
            (CSL_DSSVP_CONTROL_LCDEN_MASK));
    }
    else
    {
        /* Disable LCD output */
        value &= (~CSL_DSSVP_CONTROL_LCDEN_MASK);
    }
    reg_wr_32(baseAddr + CSL_DSSVP_CONTROL, value);
}

/**
 *  \brief    Performs software reset of the Display Controller
 *
 *  This function performs software reset of the display controller.
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *
 *  \return
 *          NONE
 */
void dssDispcSoftReset(Uint32 baseAddr)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_SYSCONFIG);

    value |= ((CSL_DSSCOMMON_DISPC_SYSCONFIG_SOFTRESET << CSL_DSSCOMMON_DISPC_SYSCONFIG_SOFTRESET_SHIFT) &
        (CSL_DSSCOMMON_DISPC_SYSCONFIG_SOFTRESET_MASK));

    /* Performing Software Reset of the module */
    reg_wr_32(baseAddr + CSL_DSSCOMMON_DISPC_SYSCONFIG, value);

    /* Wait until the process of Module Reset is complete */
    while(!((reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_SYSSTATUS)) &
        (CSL_DSSCOMMON_DISPC_SYSSTATUS_DISPC_FUNC_RESETDONE_MASK)));
}

/**
 *  \brief    Enable/Disable the auto-idle function
 *
 *  This function enables/disables the auto idle function of the Display
 *  controller
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcAutoIdleEnableCtrl(Uint32 baseAddr, Uint32 enableFlag)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_SYSCONFIG);

    if (TRUE == enableFlag)
    {
        /* Enable auto idle mechanism */
        value |= ((CSL_DSSCOMMON_DISPC_SYSCONFIG_AUTOIDLE_CLKGATED <<
                CSL_DSSCOMMON_DISPC_SYSCONFIG_AUTOIDLE_SHIFT) & (CSL_DSSCOMMON_DISPC_SYSCONFIG_AUTOIDLE_MASK));
    }
    else
    {
        /* Disable auto idle mechanism */
        value &= (~CSL_DSSCOMMON_DISPC_SYSCONFIG_AUTOIDLE_MASK);
    }
    reg_wr_32(baseAddr + CSL_DSSCOMMON_DISPC_SYSCONFIG, value);
}

/**
 *  \brief    Configure video pipeline DMA specific parameters
 *
 *  This function configures video pipeline DMA specific parameters
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    pDmaCfg    [IN]   pointer to DMA configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcVidDMAConfig(Uint32 baseAddr,
                            dmaCfg_t *pDmaCfg)
{
    DSS_RET status = DSS_RET_OK;
    Uint32 cfgValue = 0;

    if(NULL != pDmaCfg)
    {
        cfgValue = reg_rd_32(baseAddr + CSL_DSSVID_ATTRIBUTES);

        /* Clear the burst size and preload select fields */
        cfgValue &= ~(CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_MASK);
        /* Program the preload selection field */
        cfgValue |= ((pDmaCfg->preloadSelect <<
                CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_SHIFT) &
                CSL_DSSVID_ATTRIBUTES_BUFPRELOAD_MASK);
        reg_wr_32(baseAddr + CSL_DSSVID_ATTRIBUTES, cfgValue);

        /* program the low threshold field */
        cfgValue = ((pDmaCfg->fifoLoThr << CSL_DSSVID_BUF_THRESHOLD_BUFLOWTHRESHOLD_SHIFT) &
            (CSL_DSSVID_BUF_THRESHOLD_BUFLOWTHRESHOLD_MASK));
        /* Program the high threshold field */
        cfgValue |= ((pDmaCfg->fifoHiThr << CSL_DSSVID_BUF_THRESHOLD_BUFHIGHTHRESHOLD_SHIFT) &
            (CSL_DSSVID_BUF_THRESHOLD_BUFHIGHTHRESHOLD_MASK));
        reg_wr_32(baseAddr + CSL_DSSVID_BUF_THRESHOLD, cfgValue);

        /* Program row increment value */
        cfgValue = ((pDmaCfg->rowInc << CSL_DSSVID_ROW_INC_ROWINC_SHIFT) &
                CSL_DSSVID_ROW_INC_ROWINC_MASK);
        reg_wr_32(baseAddr + CSL_DSSVID_ROW_INC, cfgValue);
        /* Program pixel increment value */
        cfgValue = ((pDmaCfg->pixelInc << CSL_DSSVID_PIXEL_INC_PIXELINC_SHIFT) &
            (CSL_DSSVID_PIXEL_INC_PIXELINC_MASK));
        reg_wr_32(baseAddr + CSL_DSSVID_PIXEL_INC, cfgValue);
    }
    else
    {
		IFPRINT(UART_printf("ERROR %s: DMA configuration \
								pointer is NULL\n", __FUNCTION__));
        status = DSS_RET_FAILED;
    }

    return status;
}

/**
 *  \brief    Video pipeline interrupt enable
 *
 *  This function enables video pipeline interrupt
 *
 *  \param    baseAddr [IN]   base address of Video pipeline register
 *  \param    intFlag  [IN]   interrupt flag to enable
 *
 *  \return
 *          NONE
 */
void dssDispcVidIntEnable(Uint32 baseAddr, Uint32 intFlag)
{
    Uint32 value = 0;

    value = (reg_rd_32(baseAddr + CSL_DSSVID_IRQENABLE) | (intFlag));
    reg_wr_32(baseAddr + CSL_DSSVID_IRQENABLE, value);
}

/**
 *  \brief    Video pipeline interrupt disable
 *
 *  This function disables video pipeline interrupt
 *
 *  \param    baseAddr [IN]   base address of Video pipeline register
 *  \param    intFlag  [IN]   interrupt flag to disable
 *
 *  \return
 *          NONE
 */
void dssDispcVidIntDisable(Uint32 baseAddr, Uint32 intFlag)
{
    Uint32 value = 0;

    value = (reg_rd_32(baseAddr + CSL_DSSVID_IRQENABLE) & ~(intFlag));
    reg_wr_32(baseAddr + CSL_DSSVID_IRQENABLE, value);
}

/**
 *  \brief    Enable the video pipeline
 *
 *  This function enables/disables the video pipeline
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcVidEnableCtrl(Uint32 baseAddr,
                           Uint32 enableFlag)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSSVID_ATTRIBUTES);
    if(TRUE == enableFlag)
    {
        /* Enable video pipeline */
        value |= ((CSL_DSSVID_ATTRIBUTES_ENABLE_VIDEOENB << CSL_DSSVID_ATTRIBUTES_ENABLE_SHIFT) &
            (CSL_DSSVID_ATTRIBUTES_ENABLE_MASK));
    }
    else
    {
        /* Disable video pipeline */
        value &= (~CSL_DSSVID_ATTRIBUTES_ENABLE_MASK);
    }
    reg_wr_32(baseAddr + CSL_DSSVID_ATTRIBUTES, value);
}

/**
 *  \brief    VP interrupt enable
 *
 *  This function enables VP interrupt
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    intFlag    [IN]   interrupt flag to be enabled
 *
 *  \return
 *          NONE
 */
void dssDispcVPIntEnable(Uint32 baseAddr, Uint32 intFlag)
{
    Uint32 value = 0;

    value = (reg_rd_32(baseAddr + CSL_DSSVP_IRQENABLE) | (intFlag));
    reg_wr_32(baseAddr + CSL_DSSVP_IRQENABLE, value);
}

/**
 *  \brief    VP interrupt disable
 *
 *  This function disables VP interrupt
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    intFlag    [IN]   interrupt flag to be disabled
 *
 *  \return
 *          NONE
 */
void dssDispcVPIntDisable(Uint32 baseAddr, Uint32 intFlag)
{
    Uint32 value = 0;

    value = (reg_rd_32(baseAddr + CSL_DSSVP_IRQENABLE) & ~(intFlag));
    reg_wr_32(baseAddr + CSL_DSSVP_IRQENABLE, value);
}

/**
 *  \brief    Enable interrupts to VID or VP
 *
 *  This function enables interrupts to VID or VP
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    intFlag    [IN]   interrupt flag to be enabled
 *
 *  \return
 *          NONE
 */
void dssDispcCommonIntEnable(Uint32 baseAddr,
                           Uint32 intFlag)
{
    Uint32 value = 0;

    value = (reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_IRQENABLE_SET) | (intFlag));
    reg_wr_32(baseAddr + CSL_DSSCOMMON_DISPC_IRQENABLE_SET, value);
}

/**
 *  \brief    Disable interrupts to VID or VP
 *
 *  This function disables interrupts to VID or VP
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    intFlag    [IN]   interrupt flag to be disabled
 *
 *  \return
 *          NONE
 */
void dssDispcCommonIntDisable(Uint32 baseAddr,
                           Uint32 intFlag)
{
    Uint32 value = 0;

    value = (reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_IRQENABLE_CLR) | (intFlag));
    reg_wr_32(baseAddr + CSL_DSSCOMMON_DISPC_IRQENABLE_CLR, value);
}

/**
 *  \brief    Update shadow registers, set the Go bit
 *
 *  This function updates shadow registers and sets the GO bit
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *
 *  \return
 *          NONE
 */
void dssDispcShadowCfgEnable(Uint32 baseAddr)
{
    Uint32 value = 0;

    /* Check to ensure that GOLCD bit is clear */
    while((reg_rd_32(baseAddr + CSL_DSSVP_CONTROL)) & (CSL_DSSVP_CONTROL_GOBIT_MASK));

    value = reg_rd_32(baseAddr + CSL_DSSVP_CONTROL);

    /* Set the GoLCD bit */
    value |= ((1 << CSL_DSSVP_CONTROL_GOBIT_SHIFT) & (CSL_DSSVP_CONTROL_GOBIT_MASK));
    reg_wr_32(baseAddr + CSL_DSSVP_CONTROL, value);
}

/**
 *  \brief    Erase frame buffer
 *
 *  \param    pLcdCfg   [IN]   pointer to LCD Configuration
 *
 *  \return
 *          NONE
 */
void dssEraseBuffer(lcdCfg_t *pLcdCfg)
{
    unsigned int x,y;

    for (y = 0; y < pLcdCfg->LcdHeight; y++)
        for (x = 0; x < pLcdCfg->LcdWidth; x++)
            *(pFrameBuffer + (y*pLcdCfg->LcdWidth) + (x) ) = BLACK;
}

/**
 *  \brief    Set priority of Vid DMA
 *
 *  This function set the priority of Video DMA
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    priorityFlag [IN]   flag to indicate priority
 *
 *  \return
 *          NONE
 */
void dssDispcVidPrioritySet(Uint32 baseAddr, Uint32 priorityFlag)
{
    Uint32  value = 0;

    /* Clear the priority field */
    value = ((reg_rd_32(baseAddr + CSL_DSSVID_ATTRIBUTES)) &
        (~CSL_DSSVID_ATTRIBUTES_ARBITRATION_MASK));

    /* Program the priority field */
    value |= ((priorityFlag << CSL_DSSVID_ATTRIBUTES_ARBITRATION_SHIFT) &
            CSL_DSSVID_ATTRIBUTES_ARBITRATION_MASK);
    reg_wr_32(baseAddr + CSL_DSSVID_ATTRIBUTES, value);
}

/**
 *  \brief    Enable/Disable self refresh
 *
 *  This function enables/disables the self refresh
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcVidSelfRefEnableCtrl(Uint32 baseAddr, Uint32 enableFlag)
{
    Uint32 value = 0;

    value =  reg_rd_32(baseAddr + CSL_DSSVID_ATTRIBUTES);

    if (TRUE == enableFlag)
    {
        /* Enable self refresh */
        value |= ((1 << CSL_DSSVID_ATTRIBUTES_SELFREFRESH_SHIFT) &
                CSL_DSSVID_ATTRIBUTES_SELFREFRESH_MASK);
    }
    else
    {
        /* Disable self refresh */
        value &= (~CSL_DSSVID_ATTRIBUTES_SELFREFRESH_MASK);
    }
    reg_wr_32(baseAddr + CSL_DSSVID_ATTRIBUTES, value);
}

/**
 *  \brief    Configure base address of frame buffer
 *
 *  This function configures the base address of frame buffer
 *
 *  \param    baseAddr      [IN]   base address of Video Port register
 *  \param    bufAddr       [IN]   buffer address
 *  \param    bufSelectFlag [IN]   buffer select flag
 *
 *  \return
 *          NONE
 */
void dssDispcVidSetBufAddr(Uint32 baseAddr,
                           Uint32 bufAddr,
                           Uint32 bufSelectFlag)
{
   reg_wr_32(baseAddr + CSL_DSSVID_BA(bufSelectFlag), bufAddr);
}

/**
 *  \brief    Configure video window position
 *
 *  This function configures the video window position
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    xPos       [IN]   X position of video window
 *  \param    yPos       [IN]   Y position of video window
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcVidOvlyPositionCfg(Uint32 baseAddr,
                                  Uint32 xPos,
                                  Uint32 yPos)
{
    DSS_RET status = DSS_RET_OK;
    Uint32 value = 0;

    if ((xPos > DSS_DISPC_VID_WINDOW_XPOS_MAX) ||
       (yPos > DSS_DISPC_VID_WINDOW_YPOS_MAX))
    {
		IFPRINT(UART_printf("ERROR %s: Invalid values for \
								x,y position\n", __FUNCTION__, __LINE__));
        status = DSS_RET_FAILED;
    }
    else
    {
        /* Program X position */
        value = ((xPos << CSL_DSSVID_POSITION_POSX_SHIFT) &
            (CSL_DSSVID_POSITION_POSX_MASK));
        /* Program Y position */
        value |= ((yPos << CSL_DSSVID_POSITION_POSY_SHIFT) &
            (CSL_DSSVID_POSITION_POSY_MASK));
        reg_wr_32(baseAddr + CSL_DSSVID_POSITION, value);
    }

    return status;
}

/**
 *  \brief    Configure video window size
 *
 *  This function configures the video window size
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    width      [IN]   Video width
 *  \param    height     [IN]   Video height
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */

DSS_RET dssDispcVidSizeCfg(Uint32 baseAddr,
                          Uint32 height,
                          Uint32 width)
{
    DSS_RET status = DSS_RET_OK;
    Uint32 value = 0;

    if ((width < DSS_DISPC_VID_SIZE_X_MIN) ||
        (width > DSS_DISPC_VID_SIZE_X_MAX) ||
        (height < DSS_DISPC_VID_SIZE_Y_MIN) ||
        (height > DSS_DISPC_VID_SIZE_Y_MAX))
    {
		IFPRINT(UART_printf("ERROR %s: Invalid values for video height and \
								width\n", __FUNCTION__, __LINE__));
        status = DSS_RET_FAILED;
    }
    else
    {
        /* Program Y size(width) */
        value = (((width - 1) << CSL_DSSVID_SIZE_SIZEY_SHIFT) &
                CSL_DSSVID_SIZE_SIZEY_MASK);
        /* Program X size (height) */
        value |= (((height - 1) << CSL_DSSVID_SIZE_SIZEX_SHIFT) &
                CSL_DSSVID_SIZE_SIZEX_MASK);
        reg_wr_32(baseAddr + CSL_DSSVID_SIZE, value);

        /* UG: Program Picture_Size */
        /* Program Y size (width) */
        value = (((width - 1) << CSL_DSSVID_PICTURE_SIZE_MEMSIZEY_SHIFT) &
                CSL_DSSVID_PICTURE_SIZE_MEMSIZEY_MASK);

        /* Program X size (height) */
        value |= (((height - 1) << CSL_DSSVID_PICTURE_SIZE_MEMSIZEX_SHIFT) &
                CSL_DSSVID_PICTURE_SIZE_MEMSIZEX_MASK);
        reg_wr_32(baseAddr + CSL_DSSVID_PICTURE_SIZE, value);
    }
    return status;
}

/**
 *  \brief    Configure video window data format
 *
 *  This function configures the video window data format
 *
 *  \param    baseAddr    [IN]   base address of Video Port register
 *  \param    format      [IN]   format to be configured
 *  \param    nibbleModen [IN]   Nibble mode
 *
 *  \return
 *          NONE
 */
void dssDispcVidFormatSet(Uint32 baseAddr,
                          Uint32 format,
                          Uint32 nibbleModen)
{
    Uint32 value = 0;

    value = reg_rd_32(baseAddr + CSL_DSSVID_ATTRIBUTES);

    /* Clear format, endianness, nibble mode, replication fields */
    value &= (~(CSL_DSSVID_ATTRIBUTES_FORMAT_MASK |
        CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_MASK));

    /* Program the graphics format field */
    value |= ((format << CSL_DSSVID_ATTRIBUTES_FORMAT_SHIFT) & CSL_DSSVID_ATTRIBUTES_FORMAT_MASK);
    /* Program the nibble mode field */
    value |= ((nibbleModen << CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_SHIFT) &
            CSL_DSSVID_ATTRIBUTES_NIBBLEMODE_MASK);

    reg_wr_32(baseAddr + CSL_DSSVID_ATTRIBUTES, value);
}

/**
 *  \brief    DSS Interrupt Handler
 *
 *  This is the DSS Interrupt Handler
 *
 *  \return
 *          NONE
 */
void dssIsr(void)
{
    Uint32 vidIrqStatus = 0;
    Uint32 vpIrqStatus = 0;

    vidIrqStatus = reg_rd_32(CSL_DSSUL_0_CFG_REGS + CSL_DSSVID_IRQSTATUS);
    vpIrqStatus = reg_rd_32(CSL_DSSUL_0_CFG_REGS + CSL_DSSVP_IRQSTATUS);

    /*
     * Check for Video pipeline interrupts
     */
    if(vidIrqStatus != 0x0)
    {
        if(vidIrqStatus & CSL_DSSVID_IRQSTATUS_VIDBUFFERUNDERFLOW_IRQ_MASK)
        {
            /* Clear the interrupt */
            reg_wr_32(CSL_DSSUL_0_CFG_REGS + CSL_DSSVID_IRQSTATUS, vidIrqStatus | CSL_DSSVID_IRQSTATUS_VIDBUFFERUNDERFLOW_IRQ_MASK);

            count_underflow[uf_index] = count;
            uf_index++;
            if (uf_index == 10){
                uf_index = 0;
            }

        }else if(vidIrqStatus & CSL_DSSVID_IRQSTATUS_VIDENDWINDOW_IRQ_MASK)
        {
            /* Clear the interrupt */
            reg_wr_32(CSL_DSSUL_0_CFG_REGS + CSL_DSSVID_IRQSTATUS, vidIrqStatus | CSL_DSSVID_IRQSTATUS_VIDENDWINDOW_IRQ_MASK);
        }
    }

    /*
     * Check for VP pipeline interrupts
     */
    if(vpIrqStatus != 0x0)
    {
        /* Synchronization lost interrupt? */
        if(vpIrqStatus && CSL_DSSVP_IRQSTATUS_VPSYNCLOST_IRQ_MASK)
        {
            /* Clear the interrupt */
            reg_wr_32(CSL_DSSUL_0_CFG_REGS + CSL_DSSVP_IRQSTATUS, vpIrqStatus | CSL_DSSVP_IRQSTATUS_VPSYNCLOST_IRQ_MASK);

        /* Programmed line number interrupt? */
        }else if(vpIrqStatus && CSL_DSSVP_IRQSTATUS_VPPROGRAMMEDLINENUMBER_IRQ_MASK)
        {
            /* Clear the interrupt */
            reg_wr_32(CSL_DSSUL_0_CFG_REGS + CSL_DSSVP_IRQSTATUS, vpIrqStatus | CSL_DSSVP_IRQSTATUS_VPPROGRAMMEDLINENUMBER_IRQ_MASK);

        /* Frame done interrupt? */
        }else if(vpIrqStatus && CSL_DSSVP_IRQSTATUS_VPFRAMEDONE_IRQ_MASK)
        {
            /* Clear the interrupt */
            reg_wr_32(CSL_DSSUL_0_CFG_REGS + CSL_DSSVP_IRQSTATUS, vpIrqStatus | CSL_DSSVP_IRQSTATUS_VPFRAMEDONE_IRQ_MASK);
            count++;
        }
    }
}
/**
 *  \brief    DSS Register Dump
 *
 *  This function dumps the DSS module register values
 *
 *  \param    dssInfo    [IN]   dssInfo structure passed from LCD panel init
 *
 *  \return   none
 *
 */
#if (PLATFORM_DEBUG)
void dssDumpReg(dssInfo_t *dssInfo)
{
	Uint32 baseAddr = 0;
	Uint32 value = 0;

    lcdCfg_t  lcdCfg;
    dispCfg_t dispCfg;
    tmgCfg_t  tmgCfg;
    dmaCfg_t  vidDmaCfg;

    lcdCfg = dssInfo->lcdCfg;
    dispCfg = dssInfo->dispCfg;
    tmgCfg = dssInfo->tmgCfg;
    vidDmaCfg = dssInfo->vidDmaCfg;

    IFPRINT(UART_printf("%s: LcdWidth-%d\n\n",__FUNCTION__, lcdCfg.LcdWidth));
    IFPRINT(UART_printf("%s: LcdHeight-%d\n\n",__FUNCTION__, lcdCfg.LcdHeight));
    IFPRINT(UART_printf("%s: LcdPclk-%d\n\n",__FUNCTION__, lcdCfg.LcdPclk));
    IFPRINT(UART_printf("%s: HsyncWidth-%d\n\n",__FUNCTION__, lcdCfg.HsyncWidth));
    IFPRINT(UART_printf("%s: HFrontPorch-%d\n\n",__FUNCTION__, lcdCfg.HFrontPorch));
    IFPRINT(UART_printf("%s: HBackPorch-%d\n\n",__FUNCTION__, lcdCfg.HBackPorch));
    IFPRINT(UART_printf("%s: VsyncWidth-%d\n\n",__FUNCTION__, lcdCfg.VsyncWidth));
    IFPRINT(UART_printf("%s: VFrontPorch-%d\n\n",__FUNCTION__, lcdCfg.VFrontPorch));
    IFPRINT(UART_printf("%s: VBackPorch-%d\n\n",__FUNCTION__, lcdCfg.VBackPorch));

    IFPRINT(UART_printf("%s: displayType-%d\n\n",__FUNCTION__, dispCfg.displayType));
    IFPRINT(UART_printf("%s: colorMode-%d\n\n",__FUNCTION__, dispCfg.colorMode));
    IFPRINT(UART_printf("%s: dataLines-%d\n\n",__FUNCTION__, dispCfg.dataLines));
    IFPRINT(UART_printf("%s: mono8Bit-%d\n\n",__FUNCTION__, dispCfg.mono8Bit));

    IFPRINT(UART_printf("%s: hsyncPolarity-%d\n\n",__FUNCTION__, tmgCfg.hsyncPolarity));
    IFPRINT(UART_printf("%s: vsyncPolarity-%d\n\n",__FUNCTION__, tmgCfg.vsyncPolarity));
    IFPRINT(UART_printf("%s: syncEdge-%d\n\n",__FUNCTION__, tmgCfg.syncEdge));
    IFPRINT(UART_printf("%s: syncEdgeCtrl-%d\n\n",__FUNCTION__, tmgCfg.syncEdgeCtrl));
    IFPRINT(UART_printf("%s: pclkPolarity-%d\n\n",__FUNCTION__, tmgCfg.pclkPolarity));
    IFPRINT(UART_printf("%s: acbFrequency-%d\n\n",__FUNCTION__, tmgCfg.acbFrequency));
    IFPRINT(UART_printf("%s: acbi-%d\n\n",__FUNCTION__, tmgCfg.acbi));
    IFPRINT(UART_printf("%s: hsyncGated-%d\n\n",__FUNCTION__, tmgCfg.hsyncGated));
    IFPRINT(UART_printf("%s: vsyncGated-%d\n\n",__FUNCTION__, tmgCfg.vsyncGated));
    IFPRINT(UART_printf("%s: acbGated-%d\n\n",__FUNCTION__, tmgCfg.acbGated));
    IFPRINT(UART_printf("%s: pixelClkGated-%d\n\n",__FUNCTION__, tmgCfg.pixelClkGated));

    IFPRINT(UART_printf("%s: fifoLoThr-%d\n\n",__FUNCTION__, vidDmaCfg.fifoLoThr));
    IFPRINT(UART_printf("%s: fifoHiThr-%d\n\n",__FUNCTION__, vidDmaCfg.fifoHiThr));
    IFPRINT(UART_printf("%s: pixelInc-%d\n\n",__FUNCTION__, vidDmaCfg.pixelInc));
    IFPRINT(UART_printf("%s: rowInc-%d\n\n",__FUNCTION__, vidDmaCfg.rowInc));
    IFPRINT(UART_printf("%s: preloadSelect-%d\n\n",__FUNCTION__, vidDmaCfg.preloadSelect));
    IFPRINT(UART_printf("%s: mflagLoThr-%d\n\n",__FUNCTION__, vidDmaCfg.mflagLoThr));
    IFPRINT(UART_printf("%s: mflagHiThr-%d\n\n",__FUNCTION__, vidDmaCfg.mflagHiThr));
    IFPRINT(UART_printf("%s: mflagAttrControl-%d\n\n",__FUNCTION__, vidDmaCfg.mflagAttrControl));
    IFPRINT(UART_printf("%s: mflagAttrStart-%d\n\n",__FUNCTION__, vidDmaCfg.mflagAttrStart));
    IFPRINT(UART_printf("%s: dssInitiatorPri_Hi-%d\n\n",__FUNCTION__, vidDmaCfg.dssInitiatorPri_Hi));
    IFPRINT(UART_printf("%s: dssInitiatorPri_Lo-%d\n\n",__FUNCTION__, vidDmaCfg.dssInitiatorPri_Lo));

	baseAddr = DSS_DISPC_BASE_ADDRESS;
	IFPRINT(UART_printf("%s (line%d): Base Address = 0x%x\n", __FUNCTION__, __LINE__, baseAddr));

	/*Bit 1 is softreset*/
	value = reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_SYSCONFIG);
	IFPRINT(UART_printf("%s (line%d): Value at (DISPC_SYSCONFIG-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSCOMMON_DISPC_SYSCONFIG) , value));

	/*Bit 0 is module reset complete*/
	value = reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_SYSSTATUS);
	IFPRINT(UART_printf("%s (line%d): Value at (DISPC_SYSSTATUS-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSCOMMON_DISPC_SYSSTATUS), value));

	value = reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE);
	IFPRINT(UART_printf("%s (line%d): Value at (DISPC_GLOBAL_MFLAG_ATTRIBUTE-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSCOMMON_DISPC_GLOBAL_MFLAG_ATTRIBUTE), value));

	value = reg_rd_32(baseAddr + CSL_DSSCOMMON_DISPC_IRQENABLE_SET);
	IFPRINT(UART_printf("%s (line%d): Value at (DISPC_IRQENABLE_SET-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSCOMMON_DISPC_IRQENABLE_SET), value));

	baseAddr = DSS_VID_BASE_ADDRESS;
	IFPRINT(UART_printf("%s (line%d): Base Address = 0x%x\n", __FUNCTION__, __LINE__, baseAddr));

	value = reg_rd_32(baseAddr + CSL_DSSVID_MFLAG_THRESHOLD);
	IFPRINT(UART_printf("%s (line%d): Value at (MFLAG_THRESHOLD-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_MFLAG_THRESHOLD), value));

	value = reg_rd_32(baseAddr + CSL_DSSVID_ATTRIBUTES);
	IFPRINT(UART_printf("%s (line%d): Value at (ATTRIBUTES-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_ATTRIBUTES), value));

	value = reg_rd_32(baseAddr + CSL_DSSVID_BA(0));
	IFPRINT(UART_printf("%s (line%d): Value at (DSSVID_BA(0)-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_BA(0)), value));

	value = reg_rd_32(baseAddr + CSL_DSSVID_BA(1));
	IFPRINT(UART_printf("%s (line%d): Value at (DSSVID_BA(1)-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_BA(1)), value));

	value = reg_rd_32(baseAddr + CSL_DSSVID_POSITION);
	IFPRINT(UART_printf("%s (line%d): Value at (VID_POSITION-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_POSITION), value));

	value = reg_rd_32(baseAddr + CSL_DSSVID_PICTURE_SIZE);
	IFPRINT(UART_printf("%s (line%d): Value at (VID_PICTURE_SIZE-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_PICTURE_SIZE), value));

	value = reg_rd_32(baseAddr + CSL_DSSVID_IRQENABLE);
	IFPRINT(UART_printf("%s (line%d): Value at (VID_IRQENABLE-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_IRQENABLE), value));

	value = reg_rd_32(baseAddr + CSL_DSSVID_ATTRIBUTES);
	IFPRINT(UART_printf("%s (line%d): Value at (ATTRIBUTES-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVID_ATTRIBUTES), value));

	baseAddr = DSS_VP_BASE_ADDRESS;
	IFPRINT(UART_printf("%s (line%d): Base Address = 0x%x\n", __FUNCTION__, __LINE__, baseAddr));

	value = reg_rd_32(baseAddr + CSL_DSSVP_SIZE_SCREEN);
	IFPRINT(UART_printf("%s (line%d): Value at (VP_SIZE_SCREEN-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVP_SIZE_SCREEN), value));

	value = reg_rd_32(baseAddr + CSL_DSSVP_TIMING_H);
	IFPRINT(UART_printf("%s (line%d): Value at (VP_TIMING_H-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVP_TIMING_H), value));

	value = reg_rd_32(baseAddr + CSL_DSSVP_TIMING_V);
	IFPRINT(UART_printf("%s (line%d): Value at (VP_TIMING_V-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVP_TIMING_V), value));

	value = reg_rd_32(baseAddr + CSL_DSSVP_POL_FREQ);
	IFPRINT(UART_printf("%s (line%d): Value at (VP_POL_FREQ-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVP_POL_FREQ), value));

	value = reg_rd_32(baseAddr + CSL_DSSVP_IRQSTATUS);
	IFPRINT(UART_printf("%s (line%d): Value at (VP_IRQSTATUS-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVP_IRQSTATUS), value));

	value = reg_rd_32(baseAddr + CSL_DSSVP_IRQENABLE);
	IFPRINT(UART_printf("%s (line%d): Value at (VP_IRQENABLE-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVP_IRQENABLE), value));

	value = reg_rd_32(baseAddr + CSL_DSSVP_CONTROL);
	IFPRINT(UART_printf("%s (line%d): Value at (VP_CONTROL-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSSVP_CONTROL), value));

	baseAddr = DSS_BASE_ADDRESS;
	IFPRINT(UART_printf("%s (line%d): Base Address = 0x%x\n", __FUNCTION__, __LINE__, baseAddr));

	value = reg_rd_32(baseAddr + CSL_DSS_DSS_DPI_CTRL);
	IFPRINT(UART_printf("%s (line%d): Value at (DSS_DSS_DPI_CTRL-0x%x) is 0x%x\n", __FUNCTION__, __LINE__, (baseAddr + CSL_DSS_DSS_DPI_CTRL), value));

}
#endif
/**
 *  \brief    DSS Initialization
 *
 *  This function initializes the DSS module with the given LCD panel
 *  information, Timing configuration, Display configuration and DMA
 *  configuration.
 *
 *  \param    dssInfo    [IN]   dssInfo structure passed from LCD panel init
 *
 *  \return
 *           DSS_RET_OK -    status to indicate success
 *           DSS_RET_FAILED - if DSS failed to initialize, returns failure.
 *
 */
DSS_RET dssInit(dssInfo_t *dssInfo)
{
    lcdCfg_t  lcdCfg;
    dispCfg_t dispCfg;
    tmgCfg_t  tmgCfg;
    dmaCfg_t  vidDmaCfg;
    DSS_RET     status = DSS_RET_FAILED;

    lcdCfg = dssInfo->lcdCfg;
    dispCfg = dssInfo->dispCfg;
    tmgCfg = dssInfo->tmgCfg;
    vidDmaCfg = dssInfo->vidDmaCfg;

    /* Erase the frame buffer */
    dssEraseBuffer(&lcdCfg);

    /* Initialize Frame Buffer */
    dssInitFrameBuffer(RGB888_ADDRESS, lcdCfg.LcdWidth, lcdCfg.LcdHeight);

    /* Perform soft reset of DISPC module*/
    dssDispcSoftReset(DSS_DISPC_BASE_ADDRESS);

    /* Enable auto-idle */
    dssDispcAutoIdleEnableCtrl(DSS_DISPC_BASE_ADDRESS, ENABLE);

    status = dssInitiatorPriorityCfg (CSL_BOOT_CFG_REGS, vidDmaCfg.dssInitiatorPri_Lo, vidDmaCfg.dssInitiatorPri_Hi);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring DSS initiator \
								priority failed\n"));
        return status;
    }

    status = dssDispcMflagAttributeCfg(DSS_DISPC_BASE_ADDRESS, vidDmaCfg.mflagAttrStart, vidDmaCfg.mflagAttrControl);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring DMA attributes failed\n"));
        return status;
    }

    status = dssDispcMflagThresholdCfg(DSS_VID_BASE_ADDRESS, vidDmaCfg.mflagLoThr, vidDmaCfg.mflagHiThr);

    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring thresholds failed\n"));
        return status;
    }

    /* Configure video pipeline DMA parameters*/
    status = dssDispcVidDMAConfig(DSS_VID_BASE_ADDRESS, &vidDmaCfg);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring Video Pipeline \
								DMA failed\n"));
        return status;
    }

    /* Configure VID arbitration priority */
    dssDispcVidPrioritySet(DSS_VID_BASE_ADDRESS, DSS_DISPC_VID_PRIORITY_HIGH);

    /* Disable self refresh */
    dssDispcVidSelfRefEnableCtrl(DSS_VID_BASE_ADDRESS, DISABLE);

    /* Configure frame buffer base address */
    dssDispcVidSetBufAddr(DSS_VID_BASE_ADDRESS, /*&frameBuffer*/((Uint32)pFrameBuffer), DSS_DISPC_VID_BUFFER0);

    /* Configure position of the video window */
    status = dssDispcVidOvlyPositionCfg(DSS_VID_BASE_ADDRESS, 0, 0);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring video window \
								position failed\n"));
        return status;
    }

    /* Configure video window size */
    status = dssDispcVidSizeCfg(DSS_VID_BASE_ADDRESS, lcdCfg.LcdWidth, lcdCfg.LcdHeight);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring video window \
								size failed\n"));
        return status;
    }

    /* Configure Vid data format */
    dssDispcVidFormatSet(DSS_VID_BASE_ADDRESS, DSS_DISPC_VID_FMT_ABGR32U, DSS_DISPC_VID_NIBBLE_MODE_DISABLE);

    /* Configure LCD color attributes */
    status = dssDispcLcdDisplayAttribCfg(DSS_VP_BASE_ADDRESS, &dispCfg);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring LCD color \
								attributes failed\n"));
        return status;
    }

    /* Configure LCD panel timing parameters */
    status = dssDispcLcdPanelCfg(DSS_VP_BASE_ADDRESS, &lcdCfg);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring LCD panel \
								timing parameters failed\n"));
        return status;
    }

    /* Configure LCD control signal polarities */
    status = dssDispcLcdTimingCfg(DSS_VP_BASE_ADDRESS, &tmgCfg);
    if (status == DSS_RET_FAILED)
    {
		IFPRINT(UART_printf("ERROR: Configuring LCD control \
								signal polarities failed\n"));
        return status;
    }

    /* Clear status of all the interrupts */
    dssDispcIntStatusClearEx(DSS_VP_BASE_ADDRESS, 0x1FFFF);

    /* Configure the programmable line number which generates interrupt */
//  dssDispcProgLineNumberSet(CSL_DSSUL_0_CFG_REGS, DSS_PROG_LINE_NUMBER);  //This can be used for future testing if necessary

    /* Enable the DPI interface */
    dssDpiCtrl(DSS_BASE_ADDRESS, ENABLE);

    /* Enable interrupts to the VID and VP pipelines */
    dssDispcCommonIntEnable(DSS_DISPC_BASE_ADDRESS, CSL_DSSCOMMON_DISPC_IRQENABLE_SET_SET_VID1_IRQ_MASK | CSL_DSSCOMMON_DISPC_IRQENABLE_SET_SET_VP1_IRQ_MASK);

    /* Enable the Frame Done interrupt */
    dssDispcVPIntEnable(DSS_VP_BASE_ADDRESS, CSL_DSSVP_IRQENABLE_VPFRAMEDONE_EN_MASK);

    /* Enable VID1 buffer underflow and end of window interrupts */
    dssDispcVidIntEnable(DSS_VID_BASE_ADDRESS, CSL_DSSVID_IRQENABLE_VIDBUFFERUNDERFLOW_EN_GENINT | CSL_DSSVID_IRQENABLE_VIDENDWINDOW_EN_GENINT);

    /* Enable VID1 pipeline */
    dssDispcVidEnableCtrl(DSS_VID_BASE_ADDRESS, TRUE);

    /* Set the GO bit */
    dssDispcShadowCfgEnable(DSS_VP_BASE_ADDRESS);

    /* Enable LCD output */
    dssDispcLcdOutputEnableCtrl(DSS_VP_BASE_ADDRESS, ENABLE);

    return status;
}

#endif /* #if (PLATFORM_DSS_IN) */

/* Nothing past this point */
