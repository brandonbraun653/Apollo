/**
 *  \file   j7200/GPIO_soc.c
 *
 *  \brief  J7200 SOC specific GPIO hardware attributes.
 *
 *   This file contains the GPIO hardware attributes like base address and
 *   interrupt ids.
 */

/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <string.h>
#include <ti/csl/csl_utils.h>
#include <ti/csl/soc/j7200/src/cslr_soc.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/csl/csl_clec.h>

/** \brief Number of gpio pins for each port */
#define GPIO_NUM_PINS_PER_PORT           (128U)

/** \brief Number of gpio ports present in the soc */
#define GPIO_NUM_PORTS                   (4U)

/* CLEC input event # offset for GIC SPI */
#define GPIO_CLEC_GIC_SPI_IN_EVT_OFFSET (1024U - 32U)

/* GPIO Pin interrupt configurations */
GPIO_IntCfg GPIO_intCfgs[GPIO_NUM_PORTS][GPIO_NUM_PINS_PER_PORT] =
{
    {
        /* GPIO port 0 pin 0 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,        /* CIC not used for GPIO pin 0 */
            0,
            0
        },
        /* GPIO port 0 pin 1 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 2 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 3 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 4 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 5 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 6 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 7 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 8 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 9 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 10 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 11 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 12 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 13 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 14 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 15 */
        {
#if defined (BUILD_MPU)
            /* main domain */
            CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8, /* main int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
#if defined (BUILD_MCU)
            /* mcu domain */
            CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0,  /* main 2 mcu int router output interrupt number */
            0, /* GPIO pin interrupt event */
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
    },
};

/* GPIO Driver hardware attributes */
GPIO_v0_hwAttrsList GPIO_v0_hwAttrs =
{
    {
        (uint32_t)CSL_GPIO0_BASE,
        &GPIO_intCfgs[0][0],
        &GPIO_socConfigIntrPath
    },
    {
        (uint32_t)CSL_GPIO2_BASE,
        &GPIO_intCfgs[1][0],
        &GPIO_socConfigIntrPath
    },
    {
        (uint32_t)CSL_GPIO4_BASE,
        &GPIO_intCfgs[2][0],
        &GPIO_socConfigIntrPath
    },
    {
        (uint32_t)CSL_GPIO6_BASE,
        &GPIO_intCfgs[3][0],
        &GPIO_socConfigIntrPath
    },
    {
        0U,
        NULL,
        NULL
    },
    {
        0U,
        NULL,
        NULL
    },
    {
        0U,
        NULL,
        NULL
    },
    {
        0U,
        NULL,
        NULL
    }
};

/* GPIO configuration structure */
CSL_PUBLIC_CONST GPIOConfigList GPIO_config =
{
    {
        &GPIO_FxnTable_v0,
        NULL,
        &GPIO_v0_hwAttrs[0]
    },

    {
        &GPIO_FxnTable_v0,
        NULL,
        &GPIO_v0_hwAttrs[1]
    },

    {
        NULL,
        NULL,
        NULL
    }
};

/**
 * \brief  This API gets the SoC level of GPIO intial configuration
 *
 * \param  idx       GPIO instance index.
 * \param  cfg       Pointer to GPIO SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t GPIO_socGetInitCfg(uint32_t idx, GPIO_v0_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (idx < GPIO_NUM_PORTS)
    {
        *cfg = GPIO_v0_hwAttrs[idx];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of GPIO intial configuration
 *
 * \param  idx       GPIO instance index.
 * \param  cfg       Pointer to GPIO SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t GPIO_socSetInitCfg(uint32_t idx, const GPIO_v0_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (idx < GPIO_NUM_PORTS)
    {
        GPIO_v0_hwAttrs[idx] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API gets the number of GPIO pins per port
 *         and GPIO number of ports
 *
 * \param  numPins     pointer to numPins variable.
 * \param  numPorts    pointer to numPorts variable.
 *
 * \return none
 *
 */
void GPIO_socGetNumPinsPorts(uint32_t *numPins, uint32_t *numPorts)
{
    *numPins = GPIO_NUM_PINS_PER_PORT;
    *numPorts = GPIO_NUM_PORTS;
}

void MuxIntcP_clearInEvent(int32_t muxNum, int32_t muxInEvent)
{
    (void)muxNum;
    (void)muxInEvent;

    return;
}


MuxIntcP_Status MuxIntcP_create(MuxIntcP_inParams *inParams, MuxIntcP_outParams *outParams)
{
    inParams = inParams;
    outParams = outParams;

    return (MuxIntcP_OK);
}

/* A count kept for each bank usage/ 16 pins share a bank */
#define GPIO_NUM_BANKS        ((GPIO_NUM_PINS_PER_PORT + 15U) / 16U)
uint32_t GPIO_PinBankUsageCount[GPIO_NUM_PORTS][GPIO_NUM_BANKS] = {0U, };

/**
 * \brief  This function sets/clears the soc interrupt path including the \n
 *         interrupt routers (GPIO_RTR,MAIN2MCU_RTR) etc and GPIO number of ports
 *
 * \param  portNum     The GPIO port number to configure the interrupt path.
 * \param  pinNum      The GPIO pin number to configure the interrupt path.
 * \param  hwAttrs     The GPIO_v0_HwAttrs for this SOC
 *  \param  setIntrPath TRUE - set the interrupt path, FALSE - clear the interrupt path
 * \return CSL_PASS if successful, CSL_FAIL if failed
 *
 */
int32_t GPIO_socConfigIntrPath(uint32_t portNum, uint32_t pinNum,void *hwAttrs,bool setIntrPath)
{

    GPIO_v0_HwAttrs *cfg = (GPIO_v0_HwAttrs *)hwAttrs;
    GPIO_IntCfg       *intCfg;
    uint32_t           bankNum;
	int32_t retVal=CSL_PASS;
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined(BUILD_MCU3_1)
    CSL_ArmR5CPUInfo r5CpuInfo;
#endif
    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;
    struct tisci_msg_rm_irq_release_req rmIrqRelease;
    uint16_t src_id,src_index,dst_id,dst_host_irq;

    intCfg = cfg->intCfg;
    cfg->baseAddr = (uint32_t)CSL_WKUP_GPIO0_BASE; /* For AM65x GP EVM */

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1) || defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined(BUILD_MCU3_1)
    CSL_armR5GetCpuID(&r5CpuInfo);
#endif
    /* Input parameter validation */
    bankNum = pinNum/16U; /* Each GPIO bank has 16 pins */

    /* We route bank interrupts to the cpu interrupts */
    switch (cfg->baseAddr)
    {
        case (uint32_t)CSL_WKUP_GPIO0_BASE:
            src_id = TISCI_DEV_WKUP_GPIO0;
            src_index = (uint16_t)bankNum;  /* This is the bus_gpio_bank (0-5) mentioned in DMSC firmware guide for J721E_DEV_WKUP_GPIO0 */
            break;
        case (uint32_t)CSL_WKUP_GPIO1_BASE:
            src_id = TISCI_DEV_WKUP_GPIO1;
            src_index = (uint16_t)bankNum;  /* This is the bus_gpio_bank (0-5) mentioned in DMSC firmware guide for J721E_DEV_WKUP_GPIO1 */
            break;
        case (uint32_t)CSL_GPIO0_BASE:
            src_id = TISCI_DEV_GPIO0;
            src_index = (uint16_t)bankNum;  /* This is the bus_gpio_bank (0-7) mentioned in DMSC firmware guide  for J721E_DEV_GPIO0 */
            break;
        case (uint32_t)CSL_GPIO2_BASE:
            src_id = TISCI_DEV_GPIO2;
            src_index = (uint16_t)bankNum;  /* This is the bus_gpio_bank (0-7) mentioned in DMSC firmware guide  for J721E_DEV_GPIO2 */
            break;
        case (uint32_t)CSL_GPIO4_BASE:
            src_id = TISCI_DEV_GPIO4;
            src_index = (uint16_t)bankNum;  /* This is the bus_gpio_bank (0-7) mentioned in DMSC firmware guide  for J721E_DEV_GPIO4 */
            break;
        case (uint32_t)CSL_GPIO6_BASE:
            src_id = TISCI_DEV_GPIO6;
            src_index = (uint16_t)bankNum;  /* This is the bus_gpio_bank (0-7) mentioned in DMSC firmware guide  for J721E_DEV_GPIO6 */
            break;
        default:
            break;
    }

    /* GPIO uses bank interrupts. So choose the bank interrupts from bus_gpio_bank with valid values from
     * the DMSC firmware user guide */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1)
     if(r5CpuInfo.cpuID == 0U) {
       dst_id = TISCI_DEV_MCU_R5FSS0_CORE0;
       dst_host_irq = (uint16_t)intCfg[pinNum].intNum;
     } else {
       dst_id = TISCI_DEV_MCU_R5FSS0_CORE1;
       dst_host_irq = (uint16_t)intCfg[pinNum].intNum;
     }
#elif defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
     if(r5CpuInfo.cpuID == 0U) {
       dst_id = TISCI_DEV_R5FSS0_CORE0;
       dst_host_irq = (uint16_t)intCfg[pinNum].intNum;
     } else {
       dst_id = TISCI_DEV_R5FSS0_CORE1;
       dst_host_irq = (uint16_t)intCfg[pinNum].intNum;
     }
#elif defined(BUILD_MCU3_0) || defined(BUILD_MCU3_1)
     if(r5CpuInfo.cpuID == 0U) {
       dst_id = TISCI_DEV_R5FSS1_CORE0;
       dst_host_irq = (uint16_t)intCfg[pinNum].intNum;
     } else {
       dst_id = TISCI_DEV_R5FSS1_CORE1;
       dst_host_irq = (uint16_t)intCfg[pinNum].intNum;
     }
#elif defined(BUILD_MPU1_0) || defined(BUILD_MPU1_1)
    dst_id = TISCI_DEV_COMPUTE_CLUSTER0_GIC500SS;
    dst_host_irq = (uint16_t)intCfg[pinNum].intNum;
#endif

    if(setIntrPath) {
      (void)memset (&rmIrqReq,0,sizeof(rmIrqReq));

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
   } else  {
      (void)memset (&rmIrqRelease,0,sizeof(rmIrqRelease));

      rmIrqRelease.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
      rmIrqRelease.src_id = src_id;
      rmIrqRelease.src_index = src_index;  /* This is the event coming out of the peripheral */

      /* Set the destination interrupt */
      rmIrqRelease.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
      rmIrqRelease.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

       /* Set the destination based on the core */
       rmIrqRelease.dst_id       = dst_id;
       rmIrqRelease.dst_host_irq = dst_host_irq;
   }

    /* Config event */
    if(setIntrPath) {
       if(GPIO_PinBankUsageCount[portNum][bankNum] == 0U) {
         retVal = Sciclient_rmIrqSet(
                    (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq,
                     &rmIrqResp,
                     SCICLIENT_SERVICE_WAIT_FOREVER);

          if(retVal==CSL_PASS) {
            /* Increase the bank usage count for this port */
			GPIO_PinBankUsageCount[portNum][bankNum]++;
		  }
        } else {
			/* The interrupt path is already allocated, no need to re-allocate it */
			retVal = CSL_PASS;
		}
    } else {
       retVal = Sciclient_rmIrqRelease(
                    (const struct tisci_msg_rm_irq_release_req *)&rmIrqRelease,
                     SCICLIENT_SERVICE_WAIT_FOREVER);

        if(retVal==CSL_PASS) {
            /* Increase the bank usage count for this port */
  		  GPIO_PinBankUsageCount[portNum][bankNum]--;
		}
    }


  return(retVal);
}
