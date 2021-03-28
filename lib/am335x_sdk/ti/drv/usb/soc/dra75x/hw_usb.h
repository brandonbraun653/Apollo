/**
 * \file  dra75x/hw_usb.h
 *
 * \brief Macros for use in accessing the USB registers.
 */

/*
* Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef PDK__HW_USB_H
#define PDK__HW_USB_H




/******************************************************************************
 *
 * The following are defines for the Univeral Serial Bus register offsets.
 *
 *****************************************************************************/

#if defined(SOC_DRA75x)
#define USB0_DWC_WRAPPER_BASE_ADDR      ((uint32_t)0x48880000U)
#define USB1_DWC_WRAPPER_BASE_ADDR      ((uint32_t)0x488C0000U)
#define USB_DWC_CORE_OFFSET             ((uint32_t)0x10000U)

#define USB0_USB_PHY_BASE_ADDR          ((uint32_t)0x4A084000U)
#define USB1_USB_PHY_BASE_ADDR          ((uint32_t)0x4A085000U)


#define USB_DWC3_WRAPPER_BASE_ADDR(n)   (((n)==0)?(USB0_DWC_WRAPPER_BASE_ADDR):\
                                         (USB1_DWC_WRAPPER_BASE_ADDR))

/* interrupt numbers */
#define SYS_INT_USB0                    ((uint32_t)108U) /* USB1_IRQ_INTR0 (main MPU_IRQ_76) */
#define SYS_INT_USBSS0INT               ((uint32_t)109U) /* USB1_IRQ_INTR1 (misc MPU_IRQ_77) */

#define SYS_INT_USB1                    ((uint32_t)110U) /* USB2 IRQ_INTR0 (main MPU_IRQ_78) */
#define SYS_INT_USBSS1INT               ((uint32_t)124U) /* USB2 IRQ_INTR1 (misc MPU_IRQ_92) */


#define USB_WRAPPER_REVISION            ((uint32_t)0x0000U)
#define USB_WRAPPER_SYSCONFIG           ((uint32_t)0x0010U)
#define USB_WRAPPER_IRQ_EOI             ((uint32_t)0x0020U)
#define USB_WRAPPER_IRQSTATUS_RAW_0     ((uint32_t)0x0024U)
#define USB_WRAPPER_IRQSTATUS_0         ((uint32_t)0x0028U)
#define USB_WRAPPER_IRQENABLE_SET_0     ((uint32_t)0x002CU)
#define USB_WRAPPER_IRQENABLE_CLR_0     ((uint32_t)0x0030U)
#define USB_WRAPPER_IRQSTATUS_RAW_1     ((uint32_t)0x0034U)
#define USB_WRAPPER_IRQSTATUS_1         ((uint32_t)0x0038U)
#define USB_WRAPPER_IRQENABLE_SET_1     ((uint32_t)0x003CU)
#define USB_WRAPPER_IRQENABLE_CLR_1     ((uint32_t)0x0040U)
#define USB_WRAPPER_UTMI_OTG_CTRL       ((uint32_t)0x0080U)
#define USB_WRAPPER_UTMI_OTG_STATUS     ((uint32_t)0x0084U)
#define USB_WRAPPER_MMRAM_OFFSET        ((uint32_t)0x0100U)
#define USB_WRAPPER_FLADJ               ((uint32_t)0x0104U)
#define USB_WRAPPER_DEBUG_CFG           ((uint32_t)0x0108U)
#define USB_WRAPPER_DEBUG_DATA          ((uint32_t)0x010CU)
#define USB_WRAPPER_DEV_EBC_EN          ((uint32_t)0x0110U)


#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_SHIFT        ((uint32_t)0U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_MASK         ((uint32_t)0x00000001U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_DISABLED     ((uint32_t)0U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_NOACTION     ((uint32_t)0U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN              ((uint32_t)1U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_ENABLED      ((uint32_t)1U)

#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_SHIFT        ((uint32_t)0U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_MASK         ((uint32_t)0x00000001U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_DISABLED     ((uint32_t)0U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_NOACTION     ((uint32_t)0U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_CLEAR        ((uint32_t)1U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_ENABLED      ((uint32_t)1U)

#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_SHIFT            ((uint32_t)0U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_MASK             ((uint32_t)0x00000001U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_NONE             ((uint32_t)0U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_NOACTION         ((uint32_t)0U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_CLR              ((uint32_t)1U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_PENDING          ((uint32_t)1U)

#define USB_WRAPPER_IRQ_EOI_EOI0_SHIFT                      ((uint32_t)0U)
#define USB_WRAPPER_IRQ_EOI_EOI0_MASK                       ((uint32_t)0x00000001U)
#define USB_WRAPPER_IRQ_EOI_EOI0_READ0                      ((uint32_t)0U)
#define USB_WRAPPER_IRQ_EOI_EOI0                            ((uint32_t)1U)
#define USB_WRAPPER_IRQ_EOI_EOI0_NOOP                       ((uint32_t)0U)



#define USB_USB2PHY_TERMINATION_CONTROL ((uint32_t)0x0000U)
#define USB_USB2PHY_AD_INTERFACE_REG3   ((uint32_t)0x0048U)
#define USB_USB2PHY_ANA_CONFIG1         ((uint32_t)0x004CU)
#define USB_USB2PHY_ANA_CONFIG2         ((uint32_t)0x0050U)


#endif /* SOC_DRA75x */




#endif /* PDK__HW_USB_H */
