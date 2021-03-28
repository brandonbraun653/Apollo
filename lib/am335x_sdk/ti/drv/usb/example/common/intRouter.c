/**
 * \file   intRouter.c
 *
 * \brief  Code to setup interrupt router for AM65xx
 */

/*
* Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
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

#if (defined (SOC_AM65XX) || defined(SOC_AM65xx) || defined(SOC_J721E))
#include "csl_intr_router.h"
#include "hw_types.h"
#include <ti/csl/arch/csl_arch.h>
#include <ti/drv/sciclient/sciclient.h>

/* following values are MAIN2 MCU interrupt numbers and number of interrupts */
#define MAIN2MCU_LVL_INTRTR0_NUM_INTPUT_INTRS   (192u)
#define MAIN2MCU_LVL_INTRTR0_NUM_OUTPUT_INTRS   (64u)
#define MAIN2MCU_USB0_INT                       (132u)
#define MAIN2MCU_USB1_INT                       (152u)


/*  USB_0_INT[0] - AM6 USB interrupt */
/* Calculate src_index . src_index is usually calculated using
 * the 'irq_sources' mentioned in the system-firmware-public-documentation.
 * In this example, we use the 'bus_i00_lvl' interrupt  which is
 * USB_0_INT[0] */
#define TISCI_BUS_I00_LVL_IDX                   (19U)

/* J7 USB SRC Indexes. 
 * USB has 7 interrupt lines. We use irq[0] for xhci - host mode IRQ
 * while irq[6] is used for device mode IRQ */
#define TISCI_USB_IRQ_SRC_IDX                   (6) /* device mode IRQ */
#define TISCI_USB_HOST_IRQ_SRC_IDX              (0) /* host mode IRQ */

extern void consolePrintf(const char *pcString, ...);

/* This function will configure the interrupt path to the destination CPU
*  using DMSC firmware via sciclient. if setIntrPath is set to TRUE, 
*  a path is set, else the interrupt path is released
*/



#if defined(SOC_AM65XX)
void usb_configIntRouter(uint32_t portNum, tBoolean setIntrPath)
{
   /* The interrupt path is established using the DMSC firmware */
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1) || defined(BUILD_MCU)
    CSL_ArmR5CPUInfo r5CpuInfo;
#endif
	int32_t retVal;
    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;
    struct tisci_msg_rm_irq_release_req rmIrqRelease;
    int32_t src_id,src_index,dst_id,dst_host_irq;
    
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1) || defined(BUILD_MCU)
    CSL_armR5GetCpuID(&r5CpuInfo);
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU1_1) || defined(BUILD_MCU)
    if(r5CpuInfo.cpuID == 0) {
        dst_id       = TISCI_DEV_MCU_ARMSS0_CPU0;
    } else {
        dst_id       = TISCI_DEV_MCU_ARMSS0_CPU1;
    }
#elif defined(BUILD_MPU1_0) || defined(BUILD_MPU1_1) || defined(BUILD_MPU)
     dst_id       = TISCI_DEV_GIC0;
#endif
    
    if(portNum==0) {
        src_id = TISCI_DEV_USB3SS0;
        dst_host_irq = SYS_INT_USB0;
    } else {
        src_id = TISCI_DEV_USB3SS1;
        dst_host_irq = SYS_INT_USB1;
    }

    src_index   =  TISCI_BUS_I00_LVL_IDX;


    if(setIntrPath) {
	  memset (&rmIrqReq,0,sizeof(rmIrqReq));
	   
      rmIrqReq.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
      rmIrqReq.src_id = src_id;
      rmIrqReq.src_index = src_index;  /* This is the event coming out of 
      the peripheral */

      /* Set the destination interrupt */ 
      rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
      rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

      /* Set the destination based on the core */
      rmIrqReq.dst_id       = dst_id;
      rmIrqReq.dst_host_irq = dst_host_irq;
    } else {
      memset (&rmIrqRelease,0,sizeof(rmIrqRelease));
      
      rmIrqRelease.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
      rmIrqRelease.src_id         = src_id;
      rmIrqRelease.src_index      = src_index;  /* This is the event coming out of
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
	   consolePrintf("\n Interrupt Router setup FAILED for src_id[%d], src_index[%d],dst_id[%d],dst_host_irq[%d]",
                    src_id,src_index,dst_id,dst_host_irq);
	}
}

#elif defined(SOC_J721E)

void usb_configIntRouter(uint32_t portNum, tBoolean setIntrPath)
{
#if defined (BUILD_MCU)
    /* The interrupt path is established using the DMSC firmware - 
     * USB interrupts can only reach MCU cores via the Interrupt Router 
     * Thus we need to configure interrupt router when using MCU core only.
     */
    CSL_ArmR5CPUInfo r5CpuInfo;

	int32_t retVal;
    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;
    struct tisci_msg_rm_irq_release_req rmIrqRelease;
    int32_t src_id,src_index,dst_id,dst_host_irq;
    
    CSL_armR5GetCpuID(&r5CpuInfo);

    if (r5CpuInfo.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0) /* MCU R5 */
    {
        if(r5CpuInfo.cpuID == 0U)
        {
            dst_id = TISCI_DEV_MCU_R5FSS0_CORE0; /* MCU R5 -SS0 - CPU0 */
        }
        else
        {
            dst_id = TISCI_DEV_MCU_R5FSS0_CORE1; /* MCU R5 -SS0 - CPU1 */
        }
    } else if (r5CpuInfo.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_1) /* MAIN R5 SS0 */
    {
        if(r5CpuInfo.cpuID == 0U)
        {
            dst_id = TISCI_DEV_R5FSS0_CORE0; /* Main R5 -SS0 - CPU0 */
        }
        else
        {
            dst_id = TISCI_DEV_R5FSS0_CORE1;/* Main R5 -SS0 - CPU1*/

        }
    }
    else if (r5CpuInfo.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_2) /* MAIN R5 SS1 */
    {
        if(r5CpuInfo.cpuID == 0U)
        {
            dst_id = TISCI_DEV_R5FSS1_CORE0;/* Main R5 -SS1 - CPU0*/
        }
        else
        {
            dst_id = TISCI_DEV_R5FSS1_CORE1; /* Main R5 -SS1 - CPU1*/
        }
    }

     if(portNum==0) {
         src_id = TISCI_DEV_USB0;
         dst_host_irq = SYS_INT_USB0;
     } else {
         src_id = TISCI_DEV_USB1;
         dst_host_irq = SYS_INT_USB1;
     }

     src_index   =  TISCI_USB_IRQ_SRC_IDX; 

    if(setIntrPath) {
	  memset (&rmIrqReq,0,sizeof(rmIrqReq));
	   
      rmIrqReq.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
      rmIrqReq.src_id = src_id;
      rmIrqReq.src_index = src_index;  /* This is the event coming out of 
      the peripheral */

      /* Set the destination interrupt */ 
      rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
      rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

      /* Set the destination based on the core */
      rmIrqReq.dst_id       = dst_id;
      rmIrqReq.dst_host_irq = dst_host_irq;
    } else {
      memset (&rmIrqRelease,0,sizeof(rmIrqRelease));
      
      rmIrqRelease.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
      rmIrqRelease.src_id         = src_id;
      rmIrqRelease.src_index      = src_index;  /* This is the event coming out of
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
    
        /* on J7 we need 2 IRQs (USB host and USB device modes) 
         * so calling SciClient again for second IRQ */
        rmIrqReq.dst_host_irq = ((portNum==0) ? SYS_INT_USB0_HOST:SYS_INT_USB1_HOST);
        rmIrqReq.src_index = TISCI_USB_HOST_IRQ_SRC_IDX;
        if (retVal == CSL_PASS)
        {
            retVal = Sciclient_rmIrqSet(
                    (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq, 
                     &rmIrqResp, 
                     SCICLIENT_SERVICE_WAIT_FOREVER);
        }
     } else {
       retVal = Sciclient_rmIrqRelease(
                    (const struct tisci_msg_rm_irq_release_req *)&rmIrqRelease,
                     SCICLIENT_SERVICE_WAIT_FOREVER);

        /* on J7 we need 2 IRQs (USB host and USB device modes) 
         * so calling SciClient again for second IRQ - Host IRQ */
        rmIrqRelease.dst_host_irq = ((portNum==0) ? SYS_INT_USB0_HOST:SYS_INT_USB1_HOST);
        rmIrqRelease.src_index = TISCI_USB_HOST_IRQ_SRC_IDX;

        if (retVal == CSL_PASS)
        {
            retVal = Sciclient_rmIrqRelease(
                    (const struct tisci_msg_rm_irq_release_req *)&rmIrqRelease,
                     SCICLIENT_SERVICE_WAIT_FOREVER);
        }
	 }               
    if(CSL_PASS != retVal)
    {
	   consolePrintf("\n Interrupt Router setup FAILED for src_id[%d], src_index[%d],dst_id[%d],dst_host_irq[%d]",
                    src_id,src_index,dst_id,dst_host_irq);
	}
#endif
}
#else
    #warning "unsupported SOC"
#endif

#endif

