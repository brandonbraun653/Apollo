/******************************************************************************/
/* usb_dev_audio.c - Main routines for audio device example.                  */
/******************************************************************************/
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2017
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

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

#include <ti/board/board.h>

#if defined (idkAM572x) || defined (evmAM572x)
#include <ti/csl/soc/am572x/src/csl_device_xbar.h>
#endif

#include "ti/drv/usb/example/common/hardware.h"

#include <ti/drv/usb/usb_drv.h>
#include <ti/drv/usb/usb_osal.h>

#include "types.h"

#include "usb_drv.h"
#include "usblib.h"
#include "usbdaudio.h"
#include "usb_audio_structs.h"

//****************************************************************************
//
//! \addtogroup example_list
//! <h1>USB Audio Device (usb_dev_audio)</h1>
//!
//! This example application makes the evaluation board a USB audio device
//! that supports a single 16 bit stereo audio stream at 48 kHz sample rate.
//! The application can also receive volume control and mute changes and apply
//! them to the sound driver.  These changes will only affect the headphone
//! output and not the line output because the audio DAC used on this board
//! only allows volume changes to the headphones.
//!
//! The USB audio device example will work on any operating system that
//! supports USB audio class devices natively.  There should be no addition
//! operating system specific drivers required to use the example.   The
//! application's main task is to pass buffers to the  the USB library's audio
//! device class, receive them back with audio data and pass the buffers on to
//! the sound driver for this board.
//
//*****************************************************************************

//******************************************************************************
//
// The DMA control structure table.
//
//******************************************************************************

//****************************************************************************
//
// Buffer management and flags.  The AUDIO_PACKET_SIZE is actually twice the
// size of a singled packet to cause the DMA to span two frames and interrupt
// half as often.
//
//****************************************************************************
#define AUDIO_PACKET_SIZE       (((48000*4)/1000) * 2)
#define AUDIO_BUFFER_SIZE       (AUDIO_PACKET_SIZE*20)

#define SBUFFER_FLAGS_PLAYING   0x00000001
#define SBUFFER_FLAGS_FILLING   0x00000002
#define SBUFFER_FLAGS_RECORDING   0x00000003

#define CACHELINE_SIZE_MAX 		128
#pragma DATA_ALIGN(g_sBuffer, CACHELINE_SIZE_MAX);
struct
{
    //
    // The main buffer used by both the USB audio class and the sound driver.
    //
    volatile unsigned char pucBuffer[AUDIO_BUFFER_SIZE];

    //
    // The current location of the play pointer.
    //
    volatile unsigned char *pucPlay;

    //
    // The current location of the USB fill pointer.
    //
    volatile unsigned char *pucFill;

    //
    // The amount of sample rate adjustment currently in affect.  This value
    // can only be +1, 0, or -1.
    //
    volatile int iAdjust;

    //
    // Saves the play state for e
    volatile unsigned long ulFlags;
} g_sBuffer;

#pragma DATA_ALIGN(g_sBufferRec, CACHELINE_SIZE_MAX);
struct
{
    //
    // The main buffer used by both the USB audio class and the sound driver.
    //
    volatile unsigned char pucBuffer[AUDIO_BUFFER_SIZE];

    //
    // The current location of the Rec pointer.
    //
    volatile unsigned char *pucRec;

    //
    // The current location of the USB fill pointer.
    //
    volatile unsigned char *pucFill;

    //
    // The amount of sample rate adjustment currently in affect.  This value
    // can only be +1, 0, or -1.
    //
    volatile int iAdjust;

    //
    // Saves the play state for e
    volatile unsigned long ulFlags;
} g_sBufferRec;

//****************************************************************************
//
// This macro is used to convert the 16 bit signed 8.8 fixed point number to
// a number that ranges from 0 - 100.
//
//****************************************************************************
#define CONVERT_TO_PERCENT(dbVolume)                                         \
    ((dbVolume - (short)VOLUME_MAX + (short)VOLUME_MIN) * 100) /             \
    ((short)VOLUME_MAX - (short)VOLUME_MIN) + 100;

//****************************************************************************
//
// The current volume setting.
//
//****************************************************************************
short g_sVolume;

//
// A volume update is pending.
//
#define FLAG_VOLUME_UPDATE      0

//
// A mute update is pending.
//
#define FLAG_MUTE_UPDATE        1

//
// The current state of the mute flag.
//
#define FLAG_MUTED              2

//
// A flag used to indicate whether or not we are currently connected to the USB
// host.
//
#define FLAG_CONNECTED          3
volatile unsigned long g_ulFlags;

extern tAudioInstance g_sAudioInstance;

void USBBufferCallback(void);
void USBBufferCallbackRec(void);

//****************************************************************************
//
// This function is used to modify the MCLK used by the I2S interface by a
// given amount.
//
// \param iMClkAdjust is the amount to shift the MCLK divisor expressed as a
// signed 8.4 fixed point number.
//
// This function can be used to make adjustments to the current playback rate
// for the I2S interface without stopping playback.  The adjustment is
// specified in the \e iMClkAdjust parameter and is an 8.4 signed fixed point
// number.  Some care should be used as only small changes should be made to
// prevent noise that may occur due to a rapid change in rate.  This is not
// meant to be a sample rate conversion, it is used to correct for small
// errors in sample rate.
//
// \return None.
//
//****************************************************************************
void
SysCtlI2SMClkAdjust(int iMClkAdjust)
{
    ///unsigned long ulCurrentSetting;
    ///int iCurrentDivisor;

    //
    // Get the current setting for mclk divisors.
    //
    ///ulCurrentSetting = HWREG(SYSCTL_I2SMCLKCFG);

    //
    // Adjust the clock setting.
    //
    ///iCurrentDivisor = (SYSCTL_I2SMCLKCFG_TXI_M | SYSCTL_I2SMCLKCFG_TXF_M) &
    ///                   ulCurrentSetting;
    ///iCurrentDivisor += iMClkAdjust;

    //
    // Clear out the previous settings for the transmit divisor.
    //
    ///ulCurrentSetting &= ~(SYSCTL_I2SMCLKCFG_TXI_M | SYSCTL_I2SMCLKCFG_TXF_M |
    ///                      SYSCTL_I2SMCLKCFG_RXI_M | SYSCTL_I2SMCLKCFG_RXF_M);

    //
    // Add in the new transmit divisor and save it to the register.
    //
    ///HWREG(SYSCTL_I2SMCLKCFG) = ulCurrentSetting |
    ///                           (unsigned long)iCurrentDivisor |
    ///                           ((unsigned long)iCurrentDivisor <<
    ///                            SYSCTL_I2SMCLKCFG_RXF_S);
}

//****************************************************************************
//
// This function updates the mute area of the status bar.
//
//****************************************************************************
void
UpdateMute(void)
{
    short sVolume;

    //
    // See if the current state is muted or not.
    //
    if(HWREGBITW(&g_ulFlags, FLAG_MUTED))
    {
        //
        // Set the volume to 0.
        //
        ///SoundVolumeSet(0);
    }
    else
    {
        //
        // Reset the volume to previous setting.
        //
        sVolume = CONVERT_TO_PERCENT(g_sVolume);
        ///SoundVolumeSet(sVolume);
    }
}

//****************************************************************************
//
// This function updates the volume as well as the volume status bar.
//
//****************************************************************************
void
UpdateVolume(void)
{
    short sVolume;

    //
    // Get the current volume in percentage.
    //
    sVolume = CONVERT_TO_PERCENT(g_sVolume);

    //
    // Don't update the actual volume if muted.
    //
    if(HWREGBITW(&g_ulFlags, FLAG_MUTED) == 0)
    {
        //
        // Set the volume to the current setting.
        //
        ///SoundVolumeSet(sVolume);
    }
}

//****************************************************************************
//
// This function updates the status area of the screen.  It uses the current
// state of the application to print the status bar.
//
//****************************************************************************
void
UpdateStatus(void)
{

    //
    // Update the status on the screen.
    //
    if(HWREGBITW(&g_ulFlags, FLAG_CONNECTED))
    {
        //
        // Update the current mute setting.
        //
        UpdateMute();

        //
        // Update the current volume setting.
        //
        UpdateVolume();
    }
}

void audio_buffer_init(void)
{
	//
	// Initialize the OUT buffer.
	//
	g_sBuffer.pucFill = g_sBuffer.pucBuffer;
	g_sBuffer.pucPlay = g_sBuffer.pucBuffer;
	g_sBuffer.ulFlags = SBUFFER_FLAGS_FILLING;

	g_sAudioInstance.ucInterfaceAudioCDMAPlayInitFlag = 0;
    g_sAudioInstance.ucInterfaceAudioCDMARecInitFlag = 0;
    USBAudioBufferOut(&g_sAudioInstance, (unsigned char *)g_sBuffer.pucFill,
                     AUDIO_PACKET_SIZE, (tUSBAudioBufferCallback)USBBufferCallback);

	//
	// Initialize the IN buffer.
	//
	g_sBufferRec.pucFill = g_sBufferRec.pucBuffer;
	g_sBufferRec.pucRec = g_sBufferRec.pucBuffer;
	g_sBufferRec.ulFlags = SBUFFER_FLAGS_RECORDING;

	///memset((uint8_t *)g_sBufferRec.pucBuffer, 0, sizeof(g_sBufferRec.pucBuffer));

    USBAudioBufferIn(&g_sAudioInstance, (unsigned char *)g_sBufferRec.pucRec,
    		ISOC_IN_EP_MAX_SIZE, (tUSBAudioBufferCallback)USBBufferCallbackRec);
}

void
SoundBufferPlay(void *pvBuffer, unsigned long ulEvent)
{
    uint32_t *pdst, i;
    uint16_t *psrc;

	//
	// If the buffers ever match then its time to stop playing and reset
	// the state.
	//
	if (g_sBuffer.pucPlay == g_sBuffer.pucFill)
	{
		///g_sBuffer.ulFlags = SBUFFER_FLAGS_FILLING;
		g_sBuffer.pucPlay = g_sBuffer.pucBuffer;
		g_sBuffer.pucFill = g_sBuffer.pucBuffer;
		g_sBuffer.iAdjust = 0;

		// there is nothing to play
		memset(pvBuffer, 0, AUDIO_PACKET_SIZE);
	}
	else
	{
		if (g_sBuffer.ulFlags!=SBUFFER_FLAGS_PLAYING)
		{
			// waiting fill to the mid point
			memset(pvBuffer, 0, AUDIO_PACKET_SIZE);
		} else
		{
			//
			// Start playing the next buffer. 16 bit to 32 bit conversion
			//
			pdst = (uint32_t *)pvBuffer;
			psrc = (uint16_t *)g_sBuffer.pucPlay;
			for (i=0 ; i<AUDIO_PACKET_SIZE/4; i++)
			{
				pdst[i] = psrc[i]<<16;;
			}

			//
			// Increment the play buffer.
			//
			g_sBuffer.pucPlay += AUDIO_PACKET_SIZE;

			//
			// Wrap the play buffer back to the beginning.
			//
			if((g_sBuffer.pucPlay - g_sBuffer.pucBuffer) == AUDIO_BUFFER_SIZE)
			{
				g_sBuffer.pucPlay = g_sBuffer.pucBuffer;
			}
		}
	}
	
	usb_osalCacheWb(&g_sBuffer, sizeof(g_sBuffer));
}

void
SoundBufferRec(void *pvBuffer, unsigned long ulEvent)
{
    uint16_t *pdst;
    uint32_t *psrc, i;

	//
	// Start to fill the record buffer. 32 bit to 16 bit conversion
	//
	psrc = (uint32_t *)pvBuffer;
	pdst = (uint16_t *)g_sBufferRec.pucFill;
	for (i=0 ; i<AUDIO_PACKET_SIZE/4; i++)
	{
		pdst[i] = psrc[i]>>16;
	}

	//
	// Increment the pucFill.
	//
	g_sBufferRec.pucFill += AUDIO_PACKET_SIZE;

	//
	// Wrap the pucFill back to the beginning.
	//
	if((g_sBufferRec.pucFill - g_sBufferRec.pucBuffer) == AUDIO_BUFFER_SIZE)
	{
		g_sBufferRec.pucFill = g_sBufferRec.pucBuffer;
	}
	usb_osalCacheWb(&g_sBufferRec, sizeof(g_sBufferRec));
}

//****************************************************************************
//
// Handler for buffers coming from the USB audio device class.
//
//****************************************************************************
void USBBufferCallback(void)
{
    //
    // Increment the fill pointer.
    //
    g_sBuffer.pucFill += AUDIO_PACKET_SIZE;

    //
    // At the mid point of the fill buffer check for sample rate drift.
    //
    if((g_sBuffer.pucFill - g_sBuffer.pucBuffer) == (AUDIO_BUFFER_SIZE >> 1))
    {
    	// if we have fill the audio buffer to the mid point
    	// then start playing
    	if (g_sBuffer.ulFlags==SBUFFER_FLAGS_FILLING)
    		g_sBuffer.ulFlags=SBUFFER_FLAGS_PLAYING;

        //
        // See if we are running slow or fast.
        //
        if(g_sBuffer.pucPlay > g_sBuffer.pucFill)
        {
            //
            // See if the play buffer has fallen behind enough to trigger
            // adjusting the sample rate.
            //
            if((g_sBuffer.pucBuffer + AUDIO_BUFFER_SIZE -
                (AUDIO_PACKET_SIZE * 2)) > g_sBuffer.pucPlay)
            {
                //
                // Only allow an adjustment of at most one fractional bit.
                //
                if(g_sBuffer.iAdjust >= 0)
                {
                    //
                    // Adjust the sample rate down slightly
                    //
                    SysCtlI2SMClkAdjust(-1);
                    g_sBuffer.iAdjust--;
                }
            }
        }
        else
        {
            //
            // See if the play buffer has started leading by enough to trigger
            // adjusting the sample rate.
            //
            if((g_sBuffer.pucBuffer + (AUDIO_PACKET_SIZE * 2)) <
               g_sBuffer.pucPlay)
            {
                //
                // Only allow an adjustment of at most one fractional bit.
                //
                if(g_sBuffer.iAdjust <= 0)
                {
                    //
                    // Adjust the sample rate up slightly
                    //
                    SysCtlI2SMClkAdjust(1);
                    g_sBuffer.iAdjust++;
                }
            }
        }
    }

    //
    // Wrap the buffer back to the beginning.
    //
    if((g_sBuffer.pucFill - g_sBuffer.pucBuffer) == AUDIO_BUFFER_SIZE)
    {
        g_sBuffer.pucFill = g_sBuffer.pucBuffer;
    }

    //
    // Allow the USB audio class to fill the next buffer.
    //
    USBAudioBufferOut((void *)&g_sAudioInstance, (unsigned char *)g_sBuffer.pucFill,
                      AUDIO_PACKET_SIZE, (tUSBAudioBufferCallback)USBBufferCallback);
	
    return;
}

//****************************************************************************
//
// Handler for data outgoing to the USB host.
//
//****************************************************************************

void USBBufferCallbackRec(void)
{
    //
    // Increment the record pointer.
    //
    g_sBufferRec.pucRec += AUDIO_PACKET_SIZE;

    //
    // Wrap the buffer back to the beginning.
    //
    if((g_sBufferRec.pucRec - g_sBufferRec.pucBuffer) == AUDIO_BUFFER_SIZE)
    {
        g_sBufferRec.pucRec = g_sBufferRec.pucBuffer;
    }

    //
    // Allow the USB audio class to send the next buffer.
    //
    USBAudioBufferIn((void *)&g_sAudioInstance, (unsigned char *)g_sBufferRec.pucRec,
                      ISOC_IN_EP_MAX_SIZE, (tUSBAudioBufferCallback)USBBufferCallbackRec);
	
    return;
}

