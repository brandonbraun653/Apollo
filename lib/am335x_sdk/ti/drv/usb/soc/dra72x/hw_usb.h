/**
 * \file  dra72x/hw_usb.h
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

#if defined(SOC_DRA72x)
#define USB0_DWC_WRAPPER_BASE_ADDR      (0x48880000)
#define USB1_DWC_WRAPPER_BASE_ADDR      (0x488C0000)
#define USB_DWC_CORE_OFFSET             (0x10000)

#define USB0_USB_PHY_BASE_ADDR          (0x4A084000)
#define USB1_USB_PHY_BASE_ADDR          (0x4A085000)


#define USB_DWC3_WRAPPER_BASE_ADDR(n)   (((n)==0)?(USB0_DWC_WRAPPER_BASE_ADDR):\
                                         (USB1_DWC_WRAPPER_BASE_ADDR))

/* interrupt numbers */
#define SYS_INT_USB0                    (108) /* USB1_IRQ_INTR0 (main MPU_IRQ_76) */
#define SYS_INT_USBSS0INT               (109) /* USB1_IRQ_INTR1 (misc MPU_IRQ_77) */

#define SYS_INT_USB1                    (110) /* USB2 IRQ_INTR0 (main MPU_IRQ_78) */
#define SYS_INT_USBSS1INT               (124) /* USB2 IRQ_INTR1 (misc MPU_IRQ_92) */


#define USB_WRAPPER_REVISION            (0x0000)
#define USB_WRAPPER_SYSCONFIG           (0x0010)
#define USB_WRAPPER_IRQ_EOI             (0x0020)
#define USB_WRAPPER_IRQSTATUS_RAW_0     (0x0024)
#define USB_WRAPPER_IRQSTATUS_0         (0x0028)
#define USB_WRAPPER_IRQENABLE_SET_0     (0x002C)
#define USB_WRAPPER_IRQENABLE_CLR_0     (0x0030)
#define USB_WRAPPER_IRQSTATUS_RAW_1     (0x0034)
#define USB_WRAPPER_IRQSTATUS_1         (0x0038)
#define USB_WRAPPER_IRQENABLE_SET_1     (0x003C)
#define USB_WRAPPER_IRQENABLE_CLR_1     (0x0040)
#define USB_WRAPPER_UTMI_OTG_CTRL       (0x0080)
#define USB_WRAPPER_UTMI_OTG_STATUS     (0x0084)
#define USB_WRAPPER_MMRAM_OFFSET        (0x0100)
#define USB_WRAPPER_FLADJ               (0x0104)
#define USB_WRAPPER_DEBUG_CFG           (0x0108)
#define USB_WRAPPER_DEBUG_DATA          (0x010C)
#define USB_WRAPPER_DEV_EBC_EN          (0x0110)


#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_SHIFT  (0U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_MASK  (0x00000001U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_DISABLED  (0U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_NOACTION  (0U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN      (1U)
#define USB_WRAPPER_IRQENABLE_SET_0_COREIRQ_EN_ENABLED  (1U)

#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_SHIFT  (0U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_MASK  (0x00000001U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_DISABLED  (0U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_NOACTION  (0U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_CLEAR  (1U)
#define USB_WRAPPER_IRQENABLE_CLR_0_COREIRQ_EN_ENABLED  (1U)

#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_SHIFT   (0U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_MASK    (0x00000001U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_NONE     (0U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_NOACTION  (0U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_CLR      (1U)
#define USB_WRAPPER_IRQSTATUS_0_COREIRQ_ST_PENDING  (1U)

#define USB_WRAPPER_IRQ_EOI_EOI0_SHIFT             (0U)
#define USB_WRAPPER_IRQ_EOI_EOI0_MASK              (0x00000001U)
#define USB_WRAPPER_IRQ_EOI_EOI0_READ0              (0U)
#define USB_WRAPPER_IRQ_EOI_EOI0                    (1U)
#define USB_WRAPPER_IRQ_EOI_EOI0_NOOP               (0U)



#define USB_USB2PHY_TERMINATION_CONTROL (0x0000)
#define USB_USB2PHY_AD_INTERFACE_REG3   (0x0048)
#define USB_USB2PHY_ANA_CONFIG1         (0x004C)
#define USB_USB2PHY_ANA_CONFIG2         (0x0050)


#endif /* SOC_DRA72x */




#endif /* PDK__HW_USB_H */
