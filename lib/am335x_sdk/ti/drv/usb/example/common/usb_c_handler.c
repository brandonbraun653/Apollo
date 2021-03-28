/**
 * \file   usb_c_handler.c
 *
 * \brief  Code to handle USB-C related operation
 *         J721e EVM has a USB-C connector on USB#0.
 *         This USB-C connector and its circuit communicate USB-C 
 *         direction via a GPIO pin. 
 */

/*
* Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
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
#include <types.h>
#include <string.h>
#include "intRouter.h"
#include "hardware.h"

#if (defined (SOC_J721E) || defined(SOC_J721e))
#include "csl_intr_router.h"
#include "hw_types.h"
#include <ti/csl/arch/csl_arch.h>
#include <ti/drv/sciclient/sciclient.h>
#include "usb_wrapper.h"

/* GPIO related includes */
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>


/* ===========================================================
 * GPIO config for our USB-C_DIR GPIO pin. The GPIO driver
 * needs this config to init.
 * 
 * =========================================================== */
#define GPIO_USBC_DIR_PIN_NUM   (3)     /* pin #3 bit #3 */
#define GPIO_USBC_DIR_PORT_NUM  (1)     /* GPIO1_3 */

#define GPIO_USBC_DIR_PIN_IDX   (0)     /* index to the first gpioPinConfigs */
#define GPIO_PIN_VAL_HIGH       (1)
#define GPIO_PIN_VAL_LOWi       (0)


/* GPIO Driver board specific pin configuration structure */
/* We currently only needs 1 GPIO pin, so only 1 item here. Add more necessary */
GPIO_PinConfig gpioPinConfigs[] =
{
    /* Input pin with interrupt enabled */
    GPIO_DEVICE_CONFIG(GPIO_USBC_DIR_PORT_NUM, GPIO_USBC_DIR_PIN_NUM) |
            GPIO_CFG_IN_INT_RISING | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] =
{
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config =
{
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
#ifdef __TI_ARM_V7R4__
    0x8U
#else
    0x20U
#endif
};

extern void consolePrintf(const char *pcString, ...);

/* Main domain GPIO interrupt events */
#define MAIN_GPIO_INTRTR_GPIO0_BANK0_INT (0x000000C0) /* GPIO port 0 bank 0 interrupt event #, input to MAIN_GPIO_INTRTR */
#define MAIN_GPIO_INTRTR_GPIO1_BANK0_INT (0x000000C8) /* GPIO port 1 bank 0 interrupt event #, input to MAIN_GPIO_INTRTR */

/* Main domain GPIO interrupt events */
#define WKUP_GPIO_INTRTR_GPIO0_BANK0_INT (0x0000003C) /* GPIO port 0 bank 0 interrupt event #, input to WKUP_GPIO_INTRTR */

/* Main to MCU GPIO interrupt router mux output events */
#define CSL_MAIN2MCU_INTRTR_PLS_GPIOMUX_INT0_DFLT_PLS  (0x00000000)
#define CSL_MAIN2MCU_INTRTR_PLS_GPIOMUX_INT31_DFLT_PLS (0x0000001F)



/* GPIO interrupts go to Interrupt router. The outputs of Interrupt router
 * goes to A72 or to another router to go to R5 cores
 * We use SciClient to program the routers.
 * SciClient only supports GPIO bank interrupts at the moment so we use 
 * GPIO bank interrupt instead. Each bank has 16 pins 
 */
int32_t GPIO_configIntRouter(uint32_t portNum, uint32_t pinNum, uint32_t gpioIntRtrOutIntNum, GPIO_v0_HwAttrs *cfg, uint32_t setIntrPath)
{
    GPIO_IntCfg       *intCfg;
    uint32_t          bankNum;
    int32_t           retVal = CSL_PASS;

    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;
    struct tisci_msg_rm_irq_release_req rmIrqRelease;
    int32_t src_id,src_index,dst_id,dst_host_irq;

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1)
    CSL_ArmR5CPUInfo r5CpuInfo;
#endif

    intCfg = cfg->intCfg;

    /* remove the default interrupt path configuration */
    cfg->socConfigIntrPath = 0;

    bankNum = pinNum / 16;

    /* GPIO1_3 is used for USB type C cable orientation detection */
    cfg->baseAddr = CSL_GPIO1_BASE;

    /* WKUP GPIO int router input interrupt is the GPIO bank interrupt */
#if (BUILD_MPU)
    intCfg[pinNum].intNum = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_GPIOMUX_INTRTR0_OUTP_8 + bankNum;
#else
    intCfg[pinNum].intNum = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0 + bankNum;
#endif
    intCfg[pinNum].eventId = 0;
    intCfg[pinNum].intcMuxNum = INVALID_INTC_MUX_NUM;
    intCfg[pinNum].intcMuxInEvent = 0;
    intCfg[pinNum].intcMuxOutEvent = 0;

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1)
    CSL_armR5GetCpuID(&r5CpuInfo);    
#endif

    /* We route bank interrupts to the cpu interrupts */
    src_id = TISCI_DEV_GPIO1;
    src_index = bankNum;    /* bank number */

    /* GPIO uses bank interrupts. So choose the bank interrupts from bus_gpio_bank with valid values from 
     * the DMSC firmware user guide */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1)     
    if(r5CpuInfo.cpuID == 0) {
        dst_id = TISCI_DEV_MCU_R5FSS0_CORE0;
    } else {
        dst_id = TISCI_DEV_MCU_R5FSS0_CORE1;
    }
#elif defined(BUILD_MPU1_0) || defined(BUILD_MPU1_1)
    dst_id = TISCI_DEV_COMPUTE_CLUSTER0_GIC500SS;
#endif

    dst_host_irq = intCfg[pinNum].intNum;
      
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
   } else  {
      memset (&rmIrqRelease,0,sizeof(rmIrqRelease));

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
         retVal = Sciclient_rmIrqSet(
                    (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq, 
                     &rmIrqResp, 
                     SCICLIENT_SERVICE_WAIT_FOREVER);
                     
    } else {
       retVal = Sciclient_rmIrqRelease(
                    (const struct tisci_msg_rm_irq_release_req *)&rmIrqRelease,
                     SCICLIENT_SERVICE_WAIT_FOREVER);
        
    }  
   
    /* Setup interrupt router configuration for gpio port/pin */
    consolePrintf("\nIntConfig:  portNum[%d],pinNum[%d], bankNum=%d, intNum[%d]",
                 portNum, pinNum, bankNum, intCfg[pinNum].intNum);

    return retVal;
}


/* GPIO interrupt call back function
 * when this happens, the USBC_DIR pin changes.
 * That means the USBC cable is flipped
 */
void usbcGpioIntr(void)
{
    uint32_t usbPort;

    /* USBC cable has flipped its direction */
    /* check to see if it's up or down and program the SERDES lane swap
       accordingly */
    if (GPIO_read(GPIO_USBC_DIR_PIN_IDX) == GPIO_PIN_VAL_HIGH)
    {
        /* this GPIO is tied to USB-C DIR signal on USB port 0 */
        usbPort = 0;

        usbcLaneSwap(usbPort);
    }
}

/* Return the current USBC direction 
 * (ie. if it's plugged-in in up or down orientation)
 * we do this by reading the USBC GPIO pin
 */
uint32_t usbcGetDir(void)
{
   return GPIO_read(GPIO_USBC_DIR_PIN_IDX);
}

/* Setup the GPIO pin for USB-C cable orientation detection
 * pin mux for GPIO is done by Board component */
void usbcGpioInit()
{
    GPIO_v0_HwAttrs gpio_cfg;

    consolePrintf("Enabling USB-C DIR detection\n");

    /* get the current GPIO config */
    GPIO_socGetInitCfg(GPIO_USBC_DIR_PORT_NUM, &gpio_cfg);
    

    /* GPIO interrupt only goes to Int router. Therefore we need to route
       GPIO interrupts we need to the A72 or R5 cores */
    GPIO_configIntRouter(GPIO_USBC_DIR_PORT_NUM, GPIO_USBC_DIR_PIN_NUM, 0, &gpio_cfg, TRUE);

    /* Set the default GPIO init configurations */
    GPIO_socSetInitCfg(GPIO_USBC_DIR_PORT_NUM, &gpio_cfg);

    GPIO_init();

    /* Set the callback function */
    GPIO_setCallback(GPIO_USBC_DIR_PIN_IDX, usbcGpioIntr);

    /* Enable GPIO interrupt on the specifi gpio pin */
    GPIO_enableInt(GPIO_USBC_DIR_PIN_IDX);

}

#endif
