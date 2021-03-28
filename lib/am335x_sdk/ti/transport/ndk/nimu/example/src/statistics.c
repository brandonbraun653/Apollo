/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ti/ndk/inc/stkmain.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v4/emac_drv_v4.h>
#include <ti/board/board.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

void app_stats(UArg arg0, UArg arg1);

void app_stats(UArg arg0, UArg arg1)
{
    EMAC_STATISTICS_T stats;
    EMAC_DRV_ERR_E ret = EMAC_DRV_RESULT_OK;

    while (TRUE) {
        memset(&stats, 0, sizeof(EMAC_STATISTICS_T));

        /* Read EMAC statistics */
        ret = emac_get_statistics(0, &stats);

        if (ret != EMAC_DRV_RESULT_OK) {
            UART_printf("Failed to retrieve EMAC stats: %d\n", ret);
            continue;
        }

        UART_printf("--------------------------------------------------------------------------------------\n");
        UART_printf(" RX |     Good:%8d |   Bcast:%8d |    Mcast:%8d |    Oct:%12d |\n",
                    stats.RxGoodFrames,
                    stats.RxBCastFrames,
                    stats.RxMCastFrames,
                    stats.RxOctets);
        UART_printf(" RX |    Pause:%8d |     CRC:%8d | AlignErr:%8d | Oversz:%12d |\n",
                    stats.RxPauseFrames,
                    stats.RxCRCErrors,
                    stats.RxAlignCodeErrors,
                    stats.RxOversized);
        UART_printf(" RX |   Jabber:%8d | Undersz:%8d |     Frag:%8d |   Filt:%12d |\n",
                    stats.RxJabber,
                    stats.RxUndersized,
                    stats.RxFragments,
                    stats.RxFiltered);
        UART_printf(" RX |      QoS:%8d |  SOFOvr:%8d |   MOFOvr:%8d | DMAOvr:%12d |\n",
                    stats.RxQOSFiltered,
                    stats.RxSOFOverruns,
                    stats.RxMOFOverruns,
                    stats.RxDMAOverruns);
        UART_printf(" TX |     Good:%8d |   Bcast:%8d |    Mcast:%8d |    Oct:%12d |\n",
                    stats.TxGoodFrames,
                    stats.TxBCastFrames,
                    stats.TxMCastFrames,
                    stats.TxOctets);
        UART_printf(" TX |    Pause:%8d | Deferred:%7d |     Coll:%8d |   Udrn:%12d |\n",
                    stats.TxPauseFrames,
                    stats.TxDeferred,
                    stats.TxCollision,
                    stats.TxUnderrun);

        UART_printf("--------------------------------------------------------------------------------------\n");

        Task_sleep(10000);
    }
}
