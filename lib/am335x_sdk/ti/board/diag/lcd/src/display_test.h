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
 *
 * \file   display_test.h
 *
 * \brief  This is the header file for display diagnostic test.
 *
 */
#ifndef _DISPLAY_TEST_H_
#define _DISPLAY_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/csl/csl_dss.h>
#include <ti/csl/csl_gpio.h>
#include <ti/board/board.h>
#include <ti/csl/cslr_ecap.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/cslr.h>

#include <ti/board/board.h>
#include <ti/board/src/evmKeystone3/include/board_i2c_io_exp.h>
#include <ti/csl/arch/csl_arch.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#if defined(am65xx_evm)
#include "src/am65xx_evm/am65xx_evm_pinmux.h"
#elif defined(am65xx_idk)
#include "src/am65xx_idk/am65xx_idk_pinmux.h"
#endif

#include "lcd_touch_test.h"
#include "diag_common_cfg.h"
#include "board_internal.h"

#if defined(SOC_AM65XX)
#include "board_i2c_io_exp.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/
/* Number of Pipes should be 1 when loading buffers at run time.
 * Test Pipe Id should be VID1 when number of pipes is 2.
 */
#define BUFFERS_RUNTIME                (0U)
#define TEST_VID_PIPE                  (CSL_DSS_VID_PIPE_ID_VID1)
#define NUM_VID_PIPES                  (2U)
#define UPSCALING_ENABLE               (0U)
#define DOWNSCALING_ENABLE             (1U)

/* OLDI can be tested using VP1 */
#define TEST_VP_INSTANCE               (CSL_DSS_VP_ID_1)
#define DSS_RUN_COUNT                  (30000U)
#define PWM_GPIO_PIN                   (86U)

#define NUM_BYTES_PER_PIXEL            (4U)

#define NUM_BUFFERS                    (1U)
#define BUFF_WIDTH_1080P               (1920U)
#define BUFF_HEIGHT_1080P              (1080U)
#define BUFF_WIDTH_480P                (720U)
#define BUFF_HEIGHT_480P               (480U)

#define MAX_BUFFER_SIZE                (NUM_BUFFERS * NUM_BYTES_PER_PIXEL * \
                                        BUFF_HEIGHT_480P * \
                                        BUFF_WIDTH_480P)

/*ECAP register offsets*/
#define ECAP_TSCTR         (0x00U)
#define ECAP_CTRPHS        (0x04U)
#define ECAP_CAP1          (0x08U)
#define ECAP_CAP2          (0x0CU)
#define ECAP_CAP3          (0x10U)
#define ECAP_CAP4          (0x14U)
#define ECAP_ECCTL1        (0x28U)
#define ECAP_ECCTL2        (0x2AU)
#define ECAP_ECEINT        (0x2CU)
#define ECAP_ECFLG         (0x2EU)
#define ECAP_ECCLR         (0x30U)
#define ECAP_ECFRC         (0x32U)
#define ECAP_REVID         (0x5CU)

#define ECAP_ECCTL2_APWM_MODE            (0x1U)
#define ECAP_ECCTL2_APWM_MODE_DISABLE   (0x0U)
#define ECAP_TSCTR_COUNT                (0x10000U)
#define ECAP_ECCTL2_APWM_POLARITY       (0x1U)
#define ECAP_ECCTL2_FREERUN_ENABLE      (0x1U)
#define ECAP_CAP1_APRD_VALUE            (0x100000U)
#define ECAP_CAP2_ACMP_VALUE            (0x50000U)
#define ECAP_ECCTL2_SYNCO_SEL_DISABLE   (0x3U)

/** Macros definitons for error and success */
#define ECAP_ERR                        (-1)
#define ECAP_SUCCESS                    (0)

#define PWM_ECAP_CLK_EN                 (0x01)
#define ECAP_PRESCALE_6                 (0x03)

/** Frame address  */
#define DDR_FRAME_ADDRESS_START         (0x88000000)
#define DDR_FRAME_ADDRESS_END           (0x88FFFFFF)

/* Possible values for VLAB: CSL_DSS_VP_ID_1 and CSL_DSS_VP_ID_2.
   On EVM one can test DPI only using VP2 */
#define TEST_VP_INSTANCE               (CSL_DSS_VP_ID_1)

#define BUFF_WIDTH_1080P               (1920U)
#define BUFF_HEIGHT_1080P              (1080U)
#define BUFF_WIDTH_480P                (720U)
#define BUFF_HEIGHT_480P               (480U)

//#define MAX_BUFFER_SIZE                (NUM_BUFFERS * NUM_BUFFERS * BUFF_HEIGHT_1080P * BUFF_WIDTH_1080P)

#define LCD_WIDTH                      (1920U)
#define LCD_HEIGHT                     (1080U)
#define LCD_H_FRONT_PORCH              (48U)
#define LCD_H_BACK_PORCH		       (80U)
#define LCD_H_SYNCLEN                  (32U)
#define LCD_V_FRONT_PORCH     		   (3U)
#define LCD_V_BACK_PORCH   			   (23U)
#define LCD_V_SYNC_LEN        		   (5U)

#define BACK_GROUND_COLOUR             (0xc8c800U)

/* Copy image buffer */
#define LCD_BLACK   			       (0x00000000)
#define LCD_WHITE   			       (0x00FFFFFF)
#define LCD_BLUE    			       (0x00FF0000)
#define LCD_GREEN   			       (0x0000FF00)
#define LCD_RED     			       (0x000000FF)
#define LCD_PURPLE  			       (0x00F020A0)
#define LCD_PINK                       (0x00CBC0FF)
#define LCD_YELLOW                     (0x0000FFFF)

#define COLOUR_BAR_MAX    	           (8U)

#define DELAY_COUNT                    (50000U)

#define MODE_PIN_MASK                  (0xFU)

#define TEST_PASS                      (0U) 
#define TEST_FAIL                      (1U)

/* OLDI can be tested using VP1 */
#define TEST_VP_INSTANCE               (CSL_DSS_VP_ID_1)

#define DSS_RUN_COUNT                  (30000U)

#define PWM_GPIO_PIN                   (86U)

/** Handle to access ECAP registers */
typedef CSL_EcapRegs *hEcapHandle;

/*---------------------------------------------------------------------------*/
/* Data Structure                                                            */
/*---------------------------------------------------------------------------*/
/*
 * Configuration parameters specific to each LCD panel
 */
typedef struct _lcdCfg_t
{
    Uint32 LcdWidth;        /**< Pixels per line (PPL)       */
    Uint32 LcdHeight;       /**< Lines per panel (LPP)       */
    Uint32 LcdPclk;         /**< Pixel clock (PCLK)          */
    Uint32 HsyncWidth;      /**< Horizontal Sync Width (HSW) */
    Uint32 HFrontPorch;     /**< Horizontal front porch (HFP)*/
    Uint32 HBackPorch;      /**< Horizontal back porch (HBP)*/
    Uint32 VsyncWidth;      /**< Vertical sync width (VSW)  */
    Uint32 VFrontPorch;     /**< Vertical front porch (VFP) */
    Uint32 VBackPorch;      /**< Vertical back porch (VBP)  */
}lcdCfg_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DISPLAY_TEST_H_ */
