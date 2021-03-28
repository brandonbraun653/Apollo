/**
 * @file   pruicss_soc.c
 *
 * @brief  This is soc specific configuration file .
 */
/*
 * Copyright (c) 2017-2019, Texas Instruments Incorporated
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
#if defined (__TI_ARM_V7M4__)
    {
       0x4b200000,
       0,
       CSL_IPU_PRUSS1_U_PRU0_CTRL_REGS,
       CSL_IPU_PRUSS1_U_PRU1_CTRL_REGS,
       CSL_IPU_PRUSS1_U_INTC_REGS,
       CSL_IPU_PRUSS1_U_CFG_REGS,
       CSL_IPU_PRUSS1_U_UART_REGS,
       CSL_IPU_PRUSS1_U_IEP_REGS,
       CSL_IPU_PRUSS1_U_ECAP_REGS,
       CSL_IPU_PRUSS1_U_MII_RT_CFG_REGS,
       CSL_IPU_PRUSS1_U_MII_MDIO_REGS,
       CSL_IPU_PRUSS1_U_DATA_RAM0_8KB_REGS,
       CSL_IPU_PRUSS1_U_DATA_RAM1_8KB_REGS,
       CSL_IPU_PRUSS1_U_INST_RAM0_12KB_REGS,
       CSL_IPU_PRUSS1_U_INST_RAM1_12KB_REGS,
       CSL_IPU_PRUSS1_U_DATA_RAM_32KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_IPU_PRUSS1_U_DATA_RAM0_8KB_SIZE,
       CSL_IPU_PRUSS1_U_DATA_RAM1_8KB_SIZE,
       CSL_IPU_PRUSS1_U_INST_RAM0_12KB_SIZE,
       CSL_IPU_PRUSS1_U_INST_RAM1_12KB_SIZE,
       CSL_IPU_PRUSS1_U_DATA_RAM_32KB_SIZE,
       0U,
       0U,
       0U,
       0U
    },
    {
       0x4b280000,
       0,
       CSL_IPU_PRUSS2_U_PRU0_CTRL_REGS,
       CSL_IPU_PRUSS2_U_PRU1_CTRL_REGS,
       CSL_IPU_PRUSS2_U_INTC_REGS,
       CSL_IPU_PRUSS2_U_CFG_REGS,
       CSL_IPU_PRUSS2_U_UART_REGS,
       CSL_IPU_PRUSS2_U_IEP_REGS,
       CSL_IPU_PRUSS2_U_ECAP_REGS,
       CSL_IPU_PRUSS2_U_MII_RT_CFG_REGS,
       CSL_IPU_PRUSS2_U_MII_MDIO_REGS,
       CSL_IPU_PRUSS2_U_DATA_RAM0_8KB_REGS,
       CSL_IPU_PRUSS2_U_DATA_RAM1_8KB_REGS,
       CSL_IPU_PRUSS2_U_INST_RAM0_12KB_REGS,
       CSL_IPU_PRUSS2_U_INST_RAM1_12KB_REGS,
       CSL_IPU_PRUSS2_U_DATA_RAM_32KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_IPU_PRUSS2_U_DATA_RAM0_8KB_SIZE,
       CSL_IPU_PRUSS2_U_DATA_RAM1_8KB_SIZE,
       CSL_IPU_PRUSS2_U_INST_RAM0_12KB_SIZE,
       CSL_IPU_PRUSS2_U_INST_RAM1_12KB_SIZE,
       CSL_IPU_PRUSS2_U_DATA_RAM_32KB_SIZE,
       0U,
       0U,
       0U,
       0U
     }
#elif defined (__TMS320C6X__)
    {
       0x4b200000,
       0,
       CSL_DSP_PRUSS1_U_PRU0_CTRL_REGS,
       CSL_DSP_PRUSS1_U_PRU1_CTRL_REGS,
       CSL_DSP_PRUSS1_U_INTC_REGS,
       CSL_DSP_PRUSS1_U_CFG_REGS,
       CSL_DSP_PRUSS1_U_UART_REGS,
       CSL_DSP_PRUSS1_U_IEP_REGS,
       CSL_DSP_PRUSS1_U_ECAP_REGS,
       CSL_DSP_PRUSS1_U_MII_RT_CFG_REGS,
       CSL_DSP_PRUSS1_U_MII_MDIO_REGS,
       CSL_DSP_PRUSS1_U_DATA_RAM0_8KB_REGS,
       CSL_DSP_PRUSS1_U_DATA_RAM1_8KB_REGS,
       CSL_DSP_PRUSS1_U_INST_RAM0_12KB_REGS,
       CSL_DSP_PRUSS1_U_INST_RAM1_12KB_REGS,
       CSL_DSP_PRUSS1_U_DATA_RAM_32KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_DSP_PRUSS1_U_DATA_RAM0_8KB_SIZE,
       CSL_DSP_PRUSS1_U_DATA_RAM1_8KB_SIZE,
       CSL_DSP_PRUSS1_U_INST_RAM0_12KB_SIZE,
       CSL_DSP_PRUSS1_U_INST_RAM1_12KB_SIZE,
       CSL_DSP_PRUSS1_U_DATA_RAM_32KB_SIZE,
       0U,
       0U,
       0U,
       0U
    },
    {
       0x4b280000,
       0,
       CSL_DSP_PRUSS2_U_PRU0_CTRL_REGS,
       CSL_DSP_PRUSS2_U_PRU1_CTRL_REGS,
       CSL_DSP_PRUSS2_U_INTC_REGS,
       CSL_DSP_PRUSS2_U_CFG_REGS,
       CSL_DSP_PRUSS2_U_UART_REGS,
       CSL_DSP_PRUSS2_U_IEP_REGS,
       CSL_DSP_PRUSS2_U_ECAP_REGS,
       CSL_DSP_PRUSS2_U_MII_RT_CFG_REGS,
       CSL_DSP_PRUSS2_U_MII_MDIO_REGS,
       CSL_DSP_PRUSS2_U_DATA_RAM0_8KB_REGS,
       CSL_DSP_PRUSS2_U_DATA_RAM1_8KB_REGS,
       CSL_DSP_PRUSS2_U_INST_RAM0_12KB_REGS,
       CSL_DSP_PRUSS2_U_INST_RAM1_12KB_REGS,
       CSL_DSP_PRUSS2_U_DATA_RAM_32KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_DSP_PRUSS2_U_DATA_RAM0_8KB_SIZE,
       CSL_DSP_PRUSS2_U_DATA_RAM1_8KB_SIZE,
       CSL_DSP_PRUSS2_U_INST_RAM0_12KB_SIZE,
       CSL_DSP_PRUSS2_U_INST_RAM1_12KB_SIZE,
       CSL_DSP_PRUSS2_U_DATA_RAM_32KB_SIZE,
       0U,
       0U,
       0U,
       0U
     }
#else
    {
       0x4b200000,
       0,
       CSL_MPU_PRUSS1_U_PRU0_CTRL_REGS,
       CSL_MPU_PRUSS1_U_PRU1_CTRL_REGS,
       CSL_MPU_PRUSS1_U_INTC_REGS,
       CSL_MPU_PRUSS1_U_CFG_REGS,
       CSL_MPU_PRUSS1_U_UART_REGS,
       CSL_MPU_PRUSS1_U_IEP_REGS,
       CSL_MPU_PRUSS1_U_ECAP_REGS,
       CSL_MPU_PRUSS1_U_MII_RT_CFG_REGS,
       CSL_MPU_PRUSS1_U_MII_MDIO_REGS,
       CSL_MPU_PRUSS1_U_DATA_RAM0_8KB_REGS,
       CSL_MPU_PRUSS1_U_DATA_RAM1_8KB_REGS,
       CSL_MPU_PRUSS1_U_INST_RAM0_12KB_REGS,
       CSL_MPU_PRUSS1_U_INST_RAM1_12KB_REGS,
       CSL_MPU_PRUSS1_U_DATA_RAM_32KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_MPU_PRUSS1_U_DATA_RAM0_8KB_SIZE,
       CSL_MPU_PRUSS1_U_DATA_RAM1_8KB_SIZE,
       CSL_MPU_PRUSS1_U_INST_RAM0_12KB_SIZE,
       CSL_MPU_PRUSS1_U_INST_RAM1_12KB_SIZE,
       CSL_MPU_PRUSS1_U_DATA_RAM_32KB_SIZE,
       0U,
       0U,
       0U,
       0U
    },
    {
       0x4b280000,
       0,
       CSL_MPU_PRUSS2_U_PRU0_CTRL_REGS,
       CSL_MPU_PRUSS2_U_PRU1_CTRL_REGS,
       CSL_MPU_PRUSS2_U_INTC_REGS,
       CSL_MPU_PRUSS2_U_CFG_REGS,
       CSL_MPU_PRUSS2_U_UART_REGS,
       CSL_MPU_PRUSS2_U_IEP_REGS,
       CSL_MPU_PRUSS2_U_ECAP_REGS,
       CSL_MPU_PRUSS2_U_MII_RT_CFG_REGS,
       CSL_MPU_PRUSS2_U_MII_MDIO_REGS,
       CSL_MPU_PRUSS2_U_DATA_RAM0_8KB_REGS,
       CSL_MPU_PRUSS2_U_DATA_RAM1_8KB_REGS,
       CSL_MPU_PRUSS2_U_INST_RAM0_12KB_REGS,
       CSL_MPU_PRUSS2_U_INST_RAM1_12KB_REGS,
       CSL_MPU_PRUSS2_U_DATA_RAM_32KB_REGS,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       0U,
       CSL_MPU_PRUSS2_U_DATA_RAM0_8KB_SIZE,
       CSL_MPU_PRUSS2_U_DATA_RAM1_8KB_SIZE,
       CSL_MPU_PRUSS2_U_INST_RAM0_12KB_SIZE,
       CSL_MPU_PRUSS2_U_INST_RAM1_12KB_SIZE,
       CSL_MPU_PRUSS2_U_DATA_RAM_32KB_SIZE,
       0U,
       0U,
       0U,
       0U
     }
#endif
};

/* PRUICSS objects */
PRUICSS_V1_Object prussObjects[PRUICCSS_INSTANCE_MAX-1];

/* PRUICSS configuration structure */
PRUICSS_Config pruss_config[PRUICCSS_INSTANCE_MAX] = {
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
