/**
 * @file   pruicss_soc.c
 *
 * @brief  This is device specific configuration file .
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
PRUICSS_HwAttrs prussInitCfg[3] =
{
    {
       CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE,                 /* baseAddr */
       0,                                                 /* version */
       CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_BASE,                /* prussPru0CtrlRegBase */
       CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_BASE,                /* prussPru1CtrlRegBase */
       CSL_PRU_ICSSG0_PR1_ICSS_INTC_INTC_SLV_BASE,        /* prussIntcRegBase */
       CSL_PRU_ICSSG0_PR1_CFG_SLV_BASE,                   /* prussCfgRegBase */
       CSL_PRU_ICSSG0_PR1_ICSS_UART_UART_SLV_BASE,        /* prussUartRegBase */
       CSL_PRU_ICSSG0_IEP0_BASE,                          /* prussIepRegBase */
       CSL_PRU_ICSSG0_PR1_ICSS_ECAP0_ECAP_SLV_BASE,       /* prussEcapRegBase */
       CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_CFG_BASE,     /* prussMiiRtCfgRegBase */
       CSL_PRU_ICSSG0_PR1_MDIO_V1P7_MDIO_BASE,            /* prussMiiMdioRegBase */
       CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE,                 /* prussPru0DramBase */
       CSL_PRU_ICSSG0_DRAM1_SLV_RAM_BASE,                 /* prussPru1DramBase */
       CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_RAM_BASE,            /* prussPru0IramBase */
       CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_RAM_BASE,            /* prussPru1IramBase */
       CSL_PRU_ICSSG0_RAM_SLV_RAM_BASE,                   /* prussSharedDramBase */
       CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_RAM_BASE,    /* prussRtu0IramBase */
       CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_RAM_BASE,    /* prussRtu1IramBase */
       CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_BASE,        /* prussRtu0CtrlRegBase */
       CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_BASE,        /* prussRtu1CtrlRegBase */
       CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_BASE,          /* prussTxPru0CtrlRegBase */
       CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_BASE,          /* prussTxPru1CtrlRegBase */
       CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_RAM_BASE,      /* prussTxPru0IramBase */
       CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_RAM_BASE,      /* prussTxPru1IramBase */
       CSL_PRU_ICSSG0_DRAM0_SLV_RAM_SIZE,                 /* prussPru0DramSize */
       CSL_PRU_ICSSG0_DRAM1_SLV_RAM_SIZE,                 /* prussPru1DramSize */
       CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_SIZE,                /* prussPru0IramSize */
       CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_SIZE,                /* prussPru1IramSize */
       CSL_PRU_ICSSG0_RAM_SLV_RAM_SIZE,                   /* prussSharedDramSize */
       CSL_PRU_ICSSG0_PR1_RTU0_PR1_RTU0_IRAM_RAM_SIZE,    /* prussRtu0IramSize */
       CSL_PRU_ICSSG0_PR1_RTU1_PR1_RTU1_IRAM_RAM_SIZE,    /* prussRtu1IramSize */
       CSL_PRU_ICSSG0_PR1_TX0_PR1_TX0_IRAM_RAM_SIZE,      /* prussTxPru0IramSize */
       CSL_PRU_ICSSG0_PR1_TX1_PR1_TX1_IRAM_RAM_SIZE       /* prussTxPru1IramSize */
    },
    {
       CSL_PRU_ICSSG1_DRAM0_SLV_RAM_BASE,                 /* baseAddr */
       0,                                                 /* version */
       CSL_PRU_ICSSG1_PR1_PDSP0_IRAM_BASE,                /* prussPru0CtrlRegBase */
       CSL_PRU_ICSSG1_PR1_PDSP1_IRAM_BASE,                /* prussPru1CtrlRegBase */
       CSL_PRU_ICSSG1_PR1_ICSS_INTC_INTC_SLV_BASE,        /* prussIntcRegBase */
       CSL_PRU_ICSSG1_PR1_CFG_SLV_BASE,                   /* prussCfgRegBase */
       CSL_PRU_ICSSG1_PR1_ICSS_UART_UART_SLV_BASE,        /* prussUartRegBase */
       CSL_PRU_ICSSG1_IEP0_BASE,                          /* prussIepRegBase */
       CSL_PRU_ICSSG1_PR1_ICSS_ECAP0_ECAP_SLV_BASE,       /* prussEcapRegBase */
       CSL_PRU_ICSSG1_PR1_MII_RT_PR1_MII_RT_CFG_BASE,     /* prussMiiRtCfgRegBase */
       CSL_PRU_ICSSG1_PR1_MDIO_V1P7_MDIO_BASE,            /* prussMiiMdioRegBase */
       CSL_PRU_ICSSG1_DRAM0_SLV_RAM_BASE,                 /* prussPru0DramBase */
       CSL_PRU_ICSSG1_DRAM1_SLV_RAM_BASE,                 /* prussPru1DramBase */
       CSL_PRU_ICSSG1_PR1_PDSP0_IRAM_RAM_BASE,            /* prussPru0IramBase */
       CSL_PRU_ICSSG1_PR1_PDSP1_IRAM_RAM_BASE,            /* prussPru1IramBase */
       CSL_PRU_ICSSG1_RAM_SLV_RAM_BASE,                   /* prussSharedDramBase */
       CSL_PRU_ICSSG1_PR1_RTU0_PR1_RTU0_IRAM_RAM_BASE,    /* prussRtu0IramBase */
       CSL_PRU_ICSSG1_PR1_RTU1_PR1_RTU1_IRAM_RAM_BASE,    /* prussRtu1IramBase */
       CSL_PRU_ICSSG1_PR1_RTU0_PR1_RTU0_IRAM_BASE,        /* prussRtu0CtrlRegBase */
       CSL_PRU_ICSSG1_PR1_RTU1_PR1_RTU1_IRAM_BASE,        /* prussRtu1CtrlRegBase */
       CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_BASE,          /* prussTxPru0CtrlRegBase */
       CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_BASE,          /* prussTxPru1CtrlRegBase */
       CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_RAM_BASE,      /* prussTxPru0IramBase */
       CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_RAM_BASE,      /* prussTxPru1IramBase */
       CSL_PRU_ICSSG1_DRAM0_SLV_RAM_SIZE,                 /* prussPru0DramSize */
       CSL_PRU_ICSSG1_DRAM1_SLV_RAM_SIZE,                 /* prussPru1DramSize */
       CSL_PRU_ICSSG1_PR1_PDSP0_IRAM_SIZE,                /* prussPru0IramSize */
       CSL_PRU_ICSSG1_PR1_PDSP1_IRAM_SIZE,                /* prussPru1IramSize */
       CSL_PRU_ICSSG1_RAM_SLV_RAM_SIZE,                   /* prussSharedDramSize */
       CSL_PRU_ICSSG1_PR1_RTU0_PR1_RTU0_IRAM_RAM_SIZE,    /* prussRtu0IramSize */
       CSL_PRU_ICSSG1_PR1_RTU1_PR1_RTU1_IRAM_RAM_SIZE,    /* prussRtu1IramSize */
       CSL_PRU_ICSSG1_PR1_TX0_PR1_TX0_IRAM_RAM_SIZE,      /* prussTxPru0IramSize */
       CSL_PRU_ICSSG1_PR1_TX1_PR1_TX1_IRAM_RAM_SIZE       /* prussTxPru1IramSize */
    },
    {
       CSL_PRU_ICSSG2_DRAM0_SLV_RAM_BASE,                 /* baseAddr */
       0,                                                 /* version */
       CSL_PRU_ICSSG2_PR1_PDSP0_IRAM_BASE,                /* prussPru0CtrlRegBase */
       CSL_PRU_ICSSG2_PR1_PDSP1_IRAM_BASE,                /* prussPru1CtrlRegBase */
       CSL_PRU_ICSSG2_PR1_ICSS_INTC_INTC_SLV_BASE,        /* prussIntcRegBase */
       CSL_PRU_ICSSG2_PR1_CFG_SLV_BASE,                   /* prussCfgRegBase */
       CSL_PRU_ICSSG2_PR1_ICSS_UART_UART_SLV_BASE,        /* prussUartRegBase */
       CSL_PRU_ICSSG2_IEP0_BASE,                          /* prussIepRegBase */
       CSL_PRU_ICSSG2_PR1_ICSS_ECAP0_ECAP_SLV_BASE,       /* prussEcapRegBase */
       CSL_PRU_ICSSG2_PR1_MII_RT_PR1_MII_RT_CFG_BASE,     /* prussMiiRtCfgRegBase */
       CSL_PRU_ICSSG2_PR1_MDIO_V1P7_MDIO_BASE,            /* prussMiiMdioRegBase */
       CSL_PRU_ICSSG2_DRAM0_SLV_RAM_BASE,                 /* prussPru0DramBase */
       CSL_PRU_ICSSG2_DRAM1_SLV_RAM_BASE,                 /* prussPru1DramBase */
       CSL_PRU_ICSSG2_PR1_PDSP0_IRAM_RAM_BASE,            /* prussPru0IramBase */
       CSL_PRU_ICSSG2_PR1_PDSP1_IRAM_RAM_BASE,            /* prussPru1IramBase */
       CSL_PRU_ICSSG2_RAM_SLV_RAM_BASE,                   /* prussSharedDramBase */
       CSL_PRU_ICSSG2_PR1_RTU0_PR1_RTU0_IRAM_RAM_BASE,    /* prussRtu0IramBase */
       CSL_PRU_ICSSG2_PR1_RTU1_PR1_RTU1_IRAM_RAM_BASE,    /* prussRtu1IramBase */
       CSL_PRU_ICSSG2_PR1_RTU0_PR1_RTU0_IRAM_BASE,        /* prussRtu0CtrlRegBase */
       CSL_PRU_ICSSG2_PR1_RTU1_PR1_RTU1_IRAM_BASE,        /* prussRtu1CtrlRegBase */
       CSL_PRU_ICSSG2_PR1_TX0_PR1_TX0_IRAM_BASE,          /* prussTxPru0CtrlRegBase */
       CSL_PRU_ICSSG2_PR1_TX1_PR1_TX1_IRAM_BASE,          /* prussTxPru1CtrlRegBase */
       CSL_PRU_ICSSG2_PR1_TX0_PR1_TX0_IRAM_RAM_BASE,      /* prussTxPru0IramBase */
       CSL_PRU_ICSSG2_PR1_TX1_PR1_TX1_IRAM_RAM_BASE,      /* prussTxPru1IramBase */
       CSL_PRU_ICSSG2_DRAM0_SLV_RAM_SIZE,                 /* prussPru0DramSize */
       CSL_PRU_ICSSG2_DRAM1_SLV_RAM_SIZE,                 /* prussPru1DramSize */
       CSL_PRU_ICSSG2_PR1_PDSP0_IRAM_SIZE,                /* prussPru0IramSize */
       CSL_PRU_ICSSG2_PR1_PDSP1_IRAM_SIZE,                /* prussPru1IramSize */
       CSL_PRU_ICSSG2_RAM_SLV_RAM_SIZE,                   /* prussSharedDramSize */
       CSL_PRU_ICSSG2_PR1_RTU0_PR1_RTU0_IRAM_RAM_SIZE,    /* prussRtu0IramSize */
       CSL_PRU_ICSSG2_PR1_RTU1_PR1_RTU1_IRAM_RAM_SIZE,    /* prussRtu1IramSize */
       CSL_PRU_ICSSG2_PR1_TX0_PR1_TX0_IRAM_RAM_SIZE,      /* prussTxPru0IramSize */
       CSL_PRU_ICSSG2_PR1_TX1_PR1_TX1_IRAM_RAM_SIZE       /* prussTxPru1IramSize */
    }
};

/* PRUICSS objects */
PRUICSS_V1_Object prussObjects[PRUICCSS_INSTANCE_MAX-1];

/* PRUICSS configuration structure */
PRUICSS_Config pruss_config[PRUICCSS_INSTANCE_MAX-1] = {
    {
        &prussObjects[0],
        &prussInitCfg[0]
    },
    {
        &prussObjects[1],
        &prussInitCfg[1]
    },
    {
        &prussObjects[2],
        &prussInitCfg[2]
    }
};



