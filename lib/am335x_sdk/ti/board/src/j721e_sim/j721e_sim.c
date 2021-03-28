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
/**
 *  \file   j721e_sim.c
 *
 *  \brief  j721e_sim Board library main file
 *
 *  This is a dummy function for simulator so that application can call this
 *  independent of whether it is running from sim or EVM
 *
 *
 */
#include <ti/csl/tistdtypes.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>

#include <ti/board/board.h>
#include <ti/drv/sciclient/sciclient.h>

/**
 * \brief   This function initializes the default UART instance for use for
 *          console operations.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_uartStdioInit(void)
{
    UART_HwAttrs uart_cfg;

    /* Disable the UART interrupt */
    UART_socGetInitCfg(BOARD_UART_INSTANCE, &uart_cfg);
    uart_cfg.enableInterrupt = FALSE;
    UART_socSetInitCfg(BOARD_UART_INSTANCE, &uart_cfg);

    UART_stdioInit(BOARD_UART_INSTANCE);
    return BOARD_SOK;
}

/**
 * \brief  Board library initialization function
 *
 * This is a dummy function for simulator so that application can call this
 * independent of whether it is running from sim or EVM
 *
 * \param   cfg [IN]    Board configuration flags
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS            ret = BOARD_SOK;
    Sciclient_ConfigPrms_t  sciClientCfg;

#if !defined (QT_BUILD)
    if (cfg & BOARD_INIT_UART_STDIO)
        ret = Board_uartStdioInit();
    if (ret != BOARD_SOK)
        return ret;
#endif

    Sciclient_configPrmsInit(&sciClientCfg);
    Sciclient_init(&sciClientCfg);

    return ret;
}

