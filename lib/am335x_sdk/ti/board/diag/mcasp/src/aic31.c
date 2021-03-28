/*
* Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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
*/

/**
 * \file  aic31.c
 *
 * \brief APIs to configure the AIC31 codec.
 *
 */

#include "codecif.h"
#include "aic31.h"



/******************************************************************************
**                          FUNCTION DEFINITIONS
*******************************************************************************/
/**
 * \brief   Resets the AIC31 Codec
 *
 * \param   baseAddr     Base Address of the interface connected to AIC31
 *
 * \return  None.
 *
 **/
void BoardDiag_AIC31Reset(unsigned int baseAddr)
{
    /* Select Page 0 */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG0, 0);
    /* Reset the codec */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG1, AIC31_RESET);
}

/**
 * \brief   Configures the data format and slot width
 *
 * \param   baseAddr     Base Address of the interface connected to AIC31
 * \param   dataType     Data type for the codec operation
 * \param   slotWidth    Slot width in bits
 * \param   dataOff      The number of clocks from the word clock rising edge
 *                       to capture the actual data
 *            dataType can take the values \n
 *               AIC31_DATATYPE_I2S - for I2S mode \n
 *               AIC31_DATATYPE_DSP - for DSP mode \n
 *               AIC31_DATATYPE_RIGHTJ - for right aligned data \n
 *               AIC31_DATATYPE_LEFTJ - for left aligned data \n
 *
 * \return  None.
 *
 **/
void BoardDiag_AIC31DataConfig(unsigned int baseAddr, unsigned char dataType,
                               unsigned char slotWidth, unsigned char dataOff)
{
    /* Write the data type and  slot width */
#if defined (SOC_K2G) || defined (SOC_AM65XX)
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG9, dataType);
#else
       unsigned char slot;

    switch(slotWidth)
    {
        case 16:
            slot = AIC31_SLOT_WIDTH_16;
        break;

        case 20:
            slot = AIC31_SLOT_WIDTH_20;
        break;

        case 24:
            slot = AIC31_SLOT_WIDTH_24;
        break;

        case 32:
            slot = AIC31_SLOT_WIDTH_32;
        break;

        default:
            slot = AIC31_SLOT_WIDTH_16;
        break;
    }

    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG9, (dataType | slot));
#endif
    /* valid data after dataOff number of clock cycles */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG10, dataOff);
}

/**
 * \brief   Configures the data format and slot width
 *
 * \param   baseAddr     Base Address of the interface connected to AIC31
 * \param   mode         section of the codec (ADC/DAC) for which the sample
 *                       rate needs to be configured
 * \param   sampleRate   Sample rate in samples per second
 *              mode can take the values \n
 *                AIC31_MODE_ADC - for selecting ADC \n
 *                AIC31_MODE_DAC - for selecting DAC \n
 *                AIC31_MODE_BOTH - for both ADC and DAC \n
 *              sampleRate can be \n
 *                 8000, 11025, 16000, 22050, 24000, 32000, 44100, 
 *                 48000 or  96000. \n
 *          The fs is derived from the equation 
 *                fs = (PLL_IN * [pllJval.pllDval] * pllRval) /(2048 * pllPval). 
 *          So the values are set for PLL_IN = 24576 kHz 
 *
 * \return  None.
 *
 **/
void BoardDiag_AIC31SampleRateConfig(unsigned int baseAddr, unsigned int mode,
                                     unsigned int sampleRate)
{
    unsigned char fs;
    unsigned char ref = 0x0Au;

    unsigned char temp = 0;
    unsigned char pllPval = 4u;
    unsigned char pllRval = 1u;
    unsigned char pllJval = 16u; 
    unsigned short pllDval = 0u;

    /* Select the configuration for the given sampling rate */
    switch(sampleRate)
    {
        case 8000:
            fs = 0xAAu;
        break;

        case 11025:
            fs = 0x66u;
            ref = 0x8Au;
            pllJval = 14u;
            pllDval = 7000u;
        break;

        case 16000:
            fs = 0x44u;
        break;

        case 22050:
            fs = 0x22u;
            ref = 0x8Au;
            pllJval = 14u;
            pllDval = 7000u;
        break;

        case 24000:
            fs = 0x22u;
        break;
    
        case 32000:
            fs = 0x11u;
        break;

        case 44100:
            ref = 0x8Au;
            fs = 0x00u;
            pllJval = 14u;
            pllDval = 7000u;
        break;

        case 48000:
            fs = 0x00u;
        break;

        case 96000:
            ref = 0x6Au;
            fs = 0x00u;
        break;

        default:
            fs = 0x00u;
        break;
    }
    

#if defined (SOC_K2G) || defined (SOC_AM65XX)
    pllPval = pllPval;
    pllRval = pllRval;
    pllJval = pllJval;
    pllDval = pllDval;
    fs = fs;
    temp = temp;

    /* Enable the codec to be slave for fs and bclk */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG8, 0x00);

    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG7, ref);
#else
    temp = (mode & fs);
    /* Set the sample Rate */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG2, temp);

    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG3, 0x80 | pllPval);
    /* use PLL_CLK_IN as MCLK */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG102, 0x08);

    /* Use PLL DIV OUT as codec CLK IN */
    BoardDiag_CodecRegBitClr(baseAddr, AIC31_P0_REG101, 0x01);

    /* Select GPIO to output the divided PLL IN */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG98, 0x20);

    temp = (pllJval << 2);
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG4, temp);

    /* Configure the PLL divide registers */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG5, (pllDval >> 6) & 0xFF);
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG6, (pllDval & 0x3F) << 2);

    temp = pllRval;
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG11, temp);

    /* Enable the codec to be master for fs and bclk */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG8, 0xD0);

    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG7, ref);
#endif
}

/**
 * \brief   Initializes the ADC section of the AIC31 Codec
 *
 * \param   baseAddr     Base Address of the interface connected to AIC31
 *
 * \return  None.
 *
 **/
void BoardDiag_AIC31ADCInit(unsigned int baseAddr)
{
    /* enable the programmable PGA for left and right ADC  */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG15, 0x00);
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG16, 0x00);

    /* MIC3L/R is not connected to the left ADC PGA */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG17, 0xFF);

    /* MIC3L/R is not connected to the right ADC PGA */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG18, 0xFF);

    /* power on the Line L1R */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG19, 0x04);

    /* power on the Line LIL */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG22, 0x04);
}

/**
 * \brief   Initializes the DAC section of the AIC31 Codec
 *
 * \param   baseAddr     Base Address of the interface connected to AIC31
 * \param   chanCfg      DAC output channel configuration
 *
 * \return  None.
 *
 **/
void BoardDiag_AIC31DACInit(unsigned int baseAddr,unsigned int chanCfg)
{
    /* power up the left and right DACs */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG37, 0xE0);

    /* select the DAC L1 R1 Paths */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG41, 0x02);
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG42, 0x6C);

    switch(chanCfg)
    {
        case HEADPHONE_L:
            /* DAC L to HPLOUT Is connected */
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG47, 0x80);
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG51, 0x09);

            /* DAC R to HPROUT is connected */
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG64, 0x00);
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG65, 0x00);
            break;

        case HEADPHONE_R:
            /* DAC L to HPLOUT Is connected */
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG47, 0x00);
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG51, 0x00);

            /* DAC R to HPROUT is connected */
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG64, 0x80);
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG65, 0x09);
            break;

        case HEADPHONE_LR:
            /* DAC L to HPLOUT Is connected */
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG47, 0x80);
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG51, 0x09);

            /* DAC R to HPROUT is connected */
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG64, 0x80);
            BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG65, 0x09);
            break;
    }

    /* DACL1 connected to LINE1 LOUT */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG82, 0x80);
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG86, 0x09);

    /* DACR1 connected to LINE1 ROUT */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG92, 0x80);
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG93, 0x09);

    /* unmute the DAC */
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG43, 0x00);
    BoardDiag_CodecRegWrite(baseAddr, AIC31_P0_REG44, 0x00);
}



/***************************** End Of File ***********************************/
