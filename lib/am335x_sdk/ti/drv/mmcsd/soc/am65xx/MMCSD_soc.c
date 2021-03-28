/**
 *  \file   MMCSD_soc.c
 *
 *  \brief  AM65XX SoC specific MMCSD hardware attributes.
 *
 *   This file contains the hardware attributes of MMCSD peripheral like
 *   base address, interrupt number etc.
 */

/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdint.h>
#include <string.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_mmcsd.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/csl/arch/csl_arch.h>

/* MMCSD configuration structure */
MMCSD_v2_HwAttrs MMCSDInitCfg[MMCSD_CNT] =
{
    {
        1,
#if defined (__aarch64__)
        CSL_MMC0_CTL_CFG_BASE, /* Controller Registers */
        CSL_MMC0_SS_CFG_BASE , /* SS Registers */
        CSL_MMC0_SS_CFG_BASE + 0x100 ,/* PHY  Registers */
        CSL_GIC0_INTR_MMC0_BUS_EMMCSDSS_INTR, /* Corresponds to GIC500_SPI_INT_IN_168 */
		0,  /* Event ID is not used */
#else
        CSL_MMC0_CTL_CFG_BASE,
        CSL_MMC0_SS_CFG_BASE , /* SS Registers */
        CSL_MMC0_SS_CFG_BASE + 0x100,/* PHY  Registers */
        CSL_MCU0_INTR_MAIN2MCU_LVL_INTR0_OUTL_0 +21, /* intNum: Choosing random values 21 & 22 */
        0, /* eventNum:   Corresponds to MAIN2MCU_INTRTR_LVL_IN_28, or bus_emmcsdss_intr (0) for DMSC firmware  */
#endif
		200000000U,
        25000000U,
        MMCSD_CARD_EMMC,
        MMCSD_BUS_WIDTH_8BIT,
		(MMCSD_BUS_VOLTAGE_1_8V | MMCSD_BUS_VOLTAGE_3_3V),
        1,
        0,
        NULL, /* ioDelay Fn */
		NULL,
		NULL, // MMCSD_inputClockControl,
        0,  /*Disable DMA by default */
        0, /* edmaChRx */
        0, /* edmaChTx */
        0U,
        0U,
        0U,
        0U,
        0U,
        NULL,
#if defined (__aarch64__)
		0, /* Crossbar default for IPU1 */
        0, /* Crossbar mux in */
		0,  /* Cross bar instance number for IRQ66 used in eventNum */ 
#else
		0, /* Crossbar default for MPU */
        0,/* Crossbar mux in */
		0, /* Cross bar instance number for IRQ83 used in eventNum */ 
#endif	
        MMCSD_SUPPORT_MMC_ALL, /* Supported modes */
        MMCSD_configSocIntrPath
    },
    {
        2,
#if defined (__aarch64__)
        CSL_MMC1_CTL_CFG_BASE,
        CSL_MMC1_SS_CFG_BASE , /* SS Registers */
        CSL_MMC1_SS_CFG_BASE + 0x100,
        CSL_GIC0_INTR_MMC1_BUS_EMMCSDSS_INTR, /* Corresponds to MPU_IRQ_86 (32 + MPU_IRQ_86) */
		0,
#else
        CSL_MMC1_CTL_CFG_BASE,
        CSL_MMC1_SS_CFG_BASE , /* SS Registers */
        CSL_MMC1_SS_CFG_BASE +  0x100,
        CSL_MCU0_INTR_MAIN2MCU_LVL_INTR0_OUTL_0 +22, /* intNum: Choosing random values 21 & 22 */
		0, /* eventNum:   Corresponds to MAIN2MCU_INTRTR_LVL_IN_28, or bus_emmcsdss_intr (0) for DMSC firmware  */
#endif
		200000000U,
        25000000U,
        MMCSD_CARD_SD,
        (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT),
		(MMCSD_BUS_VOLTAGE_3_3V), /* For PG 1.0 versions, 1.8v switching is disabled */
        1,
        0,
        NULL, /* ioDelay Fn */
		NULL,
		NULL, // MMCSD_inputClockControl,
        0,  /*Disable DMA by default */
        0, /* edmaChRx */
        0, /* edmaChTx */
        0U,
        0U,
        0U,
        0U,
        0U,
		NULL,
#if defined (__aarch64__)
		0, /* Crossbar default for IPU1 */
        0, /* Crossbar mux in */
		0,  /* Cross bar instance number for IRQ67 used in eventNum */ 
#else
		0, /* Crossbar default for MPU */
        0,/* Crossbar mux in */
		0, /* Cross bar instance number for IRQ84 used in eventNum */ 
#endif	
		(MMCSD_SUPPORT_SD_DS | MMCSD_SUPPORT_SD_HS), /* Supported modes.*/
		MMCSD_configSocIntrPath,
    },
 
};


/* MMCSD objects */
MMCSD_v2_Object MMCSDObjects[MMCSD_CNT];


/* MMC configuration structure */
const MMCSD_Config_list MMCSD_config = {
    {
        &MMCSD_v2_FxnTable,
        &MMCSDObjects[0],
        &MMCSDInitCfg[0]
    },

    {
        &MMCSD_v2_FxnTable,
        &MMCSDObjects[1],
        &MMCSDInitCfg[1]
    },

    {NULL, NULL, NULL}
};

/* This function converts the local L2 address to a global address and
*  will be used for DMA transactions which need a global addresses.
*/
uint32_t MMCSD_soc_l2_global_addr (uint32_t addr)
{
  return addr;
}

/* This function will configure the interrupt path to the destination CPU
*  using DMSC firmware via sciclient. if setIntrPath is set to TRUE, 
*  a path is set, else the interrupt path is released
 */
MMCSD_Error MMCSD_configSocIntrPath(const void *hwAttrs_ptr, bool setIntrPath)
{
   MMCSD_Error ret=MMCSD_OK;
   /* The interrupt path is established using the DMSC firmware */
#if defined(BUILD_MCU)
    CSL_ArmR5CPUInfo r5CpuInfo;
	int32_t retVal;
    MMCSD_v2_HwAttrs const *hwAttrs = (MMCSD_v2_HwAttrs const *)(hwAttrs_ptr);
    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;
    struct tisci_msg_rm_irq_release_req rmIrqRelease;
    int32_t src_id,src_index,dst_id,dst_host_irq;


    CSL_armR5GetCpuID(&r5CpuInfo);

     if(hwAttrs->instNum==2) {
       src_id = TISCI_DEV_MMCSD0;
     } else {
       src_id = TISCI_DEV_MMCSD1;
	 }  

    if(r5CpuInfo.cpuID == 0) {
      dst_id       = TISCI_DEV_MCU_ARMSS0_CPU0;
    } else {
      dst_id       = TISCI_DEV_MCU_ARMSS0_CPU1;
    }
    
    src_index = hwAttrs->eventId;  /* This is the event coming out of */
    dst_host_irq = hwAttrs->intNum;

      
   if(setIntrPath) {
    memset (&rmIrqReq,0,sizeof(rmIrqReq));	   

    rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
    rmIrqReq.src_id = src_id;
    rmIrqReq.src_index = src_index;  /* This is the event coming out of 
    the peripheral */

    /* Set the destination interrupt */ 
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

    /* Set the destination based on the core */
    rmIrqReq.dst_id       = dst_id;
    rmIrqReq.dst_host_irq       = dst_host_irq;

   } else 
   {
      memset (&rmIrqRelease,0,sizeof(rmIrqRelease));

      rmIrqRelease.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
      rmIrqRelease.src_id = src_id;
      rmIrqRelease.src_index = src_index;  /* This is the event coming out of 
    the peripheral */

      /* Set the destination interrupt */ 
      rmIrqRelease.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
      rmIrqRelease.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

     /* Set the destination based on the core */
     rmIrqRelease.dst_id       = dst_id;
     rmIrqRelease.dst_host_irq = dst_host_irq;
   } 
    

    /* Config event */
    if(setIntrPath) {
       retVal = Sciclient_rmIrqSet(
                    (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq, 
                     &rmIrqResp, 
                     SCICLIENT_SERVICE_WAIT_FOREVER);
     } else {
       retVal = Sciclient_rmIrqRelease(
                    (const struct tisci_msg_rm_irq_release_req *)&rmIrqRelease,
                     SCICLIENT_SERVICE_WAIT_FOREVER);
	 }               
    if(CSL_PASS != retVal)
    {
	   ret = MMCSD_ERR_SET_SOC_INTERRUPT_PATH;
	}
#endif
 	return(ret);
}

#ifdef BUILD_MCU
/**
 * \brief  This API update the default SoC level of configurations
 *         based on the core and domain
 *
 *         uartInitCfg table configures MCU domain's UART instances by
 *         default for R5, UART_socInit() is called UART_init() to
 *         overwrite the defaut configurations with the configurations
 *         of Main domain's UART instances if R5 is on the Main domain
 *
 * \param  none
 *
 * \return none
 *
 */
MMCSD_Error MMCSD_socInit(void)
{
	return MMCSD_OK;
}
#endif

/* Initializes PHY */
MMCSD_Error MMCSD_socPhyInit(MMCSD_v2_HwAttrs const *hwAttrs)
{
	MMCSD_Error ret = MMCSD_OK;
    HSMMCSDPhyInit(hwAttrs->phyBaseAddr);
	return (ret);
}

/* Initializes PHY */
MMCSD_Error MMCSD_socPhyDisableDLL(MMCSD_v2_HwAttrs const *hwAttrs)
{
	MMCSD_Error ret = MMCSD_OK;
    HSMMCSDPhyDisableDLL (hwAttrs->phyBaseAddr);
	return (ret);
}


/* Configures PHY */
MMCSD_Error MMCSD_socPhyConfigure(MMCSD_v2_HwAttrs const *hwAttrs,uint32_t phyMode, uint32_t phy_clk_freq, uint32_t phyDriverType)
{
	MMCSD_Error ret = MMCSD_OK;
    ret = HSMMCSDPhyConfigure(hwAttrs->phyBaseAddr, phyMode, phy_clk_freq, phyDriverType);
	return (ret);
}

/* Manual tuning functions */
MMCSD_Error mmcsd_tuning_procedure_SD_manual(MMCSD_Handle handle)
{
	return MMCSD_ERR; /* Not supported for AM65x */
}


/* Manual tuning functions */
MMCSD_Error mmcsd_tuning_procedure_EMMC_manual(MMCSD_Handle handle)
{
	return MMCSD_ERR; /* Not supported for AM65x */
}
