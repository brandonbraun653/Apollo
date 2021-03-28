/**
 * @file   pruicss_device.c
 *
 * @brief  This is device specific configuration file .
 */
/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
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
 */
/** ============================================================================*/

#include <ti/csl/soc.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>

/* PRUICSS configuration structure */
PRUICSS_HwAttrs prussInitCfg[2] =
{
    {
       CSL_ICSS_0_DATA_RAM_8KB_0_REGS,
       0,
       CSL_ICSS_0_PRU_CTRL_0_REGS,
       CSL_ICSS_0_PRU_CTRL_1_REGS,
       CSL_ICSS_0_INTC_REGS,
       CSL_ICSS_0_CFG_REGS,
       CSL_ICSS_0_UART_REGS,
       CSL_ICSS_0_IEP_REGS,
       CSL_ICSS_0_ECAP_REGS,
       CSL_ICSS_0_MII_RT_CFG_REGS,
       CSL_ICSS_0_MII_MDIO_REGS,
       CSL_ICSS_0_DATA_RAM_8KB_0_REGS,
       CSL_ICSS_0_DATA_RAM_8KB_1_REGS,
       CSL_ICSS_0_INST_RAM_16KB_0_REGS,
       CSL_ICSS_0_INST_RAM_16KB_1_REGS,
       CSL_ICSS_0_DATA_RAM_64KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_ICSS_0_DATA_RAM_8KB_0_REGS_SIZE,
       CSL_ICSS_0_DATA_RAM_8KB_1_REGS_SIZE,
       CSL_ICSS_0_INST_RAM_16KB_0_REGS_SIZE,
       CSL_ICSS_0_INST_RAM_16KB_1_REGS_SIZE,
       CSL_ICSS_0_DATA_RAM_64KB_REGS_SIZE,
       0U,
       0U,
       0U,
       0U,
     },
    {
       CSL_ICSS_1_DATA_RAM_8KB_0_REGS,
       0,
       CSL_ICSS_1_PRU_CTRL_0_REGS,
       CSL_ICSS_1_PRU_CTRL_1_REGS,
       CSL_ICSS_1_INTC_REGS,
       CSL_ICSS_1_CFG_REGS,
       CSL_ICSS_1_UART_REGS,
       CSL_ICSS_1_IEP_REGS,
       CSL_ICSS_1_ECAP_REGS,
       CSL_ICSS_1_MII_RT_CFG_REGS,
       CSL_ICSS_1_MII_MDIO_REGS,
       CSL_ICSS_1_DATA_RAM_8KB_0_REGS,
       CSL_ICSS_1_DATA_RAM_8KB_1_REGS,
       CSL_ICSS_1_INST_RAM_16KB_0_REGS,
       CSL_ICSS_1_INST_RAM_16KB_1_REGS,
       CSL_ICSS_1_DATA_RAM_64KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_ICSS_1_DATA_RAM_8KB_0_REGS_SIZE,
       CSL_ICSS_1_DATA_RAM_8KB_1_REGS_SIZE,
       CSL_ICSS_1_INST_RAM_16KB_0_REGS_SIZE,
       CSL_ICSS_1_INST_RAM_16KB_1_REGS_SIZE,
       CSL_ICSS_1_DATA_RAM_64KB_REGS_SIZE,
       0U,
       0U,
       0U,
       0U
     }
};

/* PRUICSS objects */
PRUICSS_V1_Object prussObjects[2];

/* PRUICSS configuration structure */
PRUICSS_Config pruss_config[2 + 1] = {
    {

        &prussObjects[0],
        &prussInitCfg[0]
    },

    {

         &prussObjects[1],
         &prussInitCfg[1]
    },

    {NULL, NULL}


};



