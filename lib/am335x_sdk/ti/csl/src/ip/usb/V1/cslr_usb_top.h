/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_USBTOP_H_
#define CSLR_USBTOP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for IRQ_HST_DEV
**************************************************************************/
typedef struct {
    volatile Uint32 IRQSTATUS_RAW_0;
    volatile Uint32 IRQSTATUS_0;
    volatile Uint32 IRQENABLE_SET_0;
    volatile Uint32 IRQENABLE_CLR_0;
} CSL_UsbtopIrq_hst_devRegs;


/**************************************************************************
* Register Overlay Structure for IRQ_MISC
**************************************************************************/
typedef struct {
    volatile Uint32 IRQSTATUS_RAW_1;
    volatile Uint32 IRQSTATUS_1;
    volatile Uint32 IRQENABLE_SET_1;
    volatile Uint32 IRQENABLE_CLR_1;
} CSL_UsbtopIrq_miscRegs;


/**************************************************************************
* Register Overlay Structure for WBU_SPECIFIC
**************************************************************************/
typedef struct {
    volatile Uint32 UTMI_OTG_CTRL;
    volatile Uint32 UTMI_OTG_STATUS;
} CSL_UsbtopWbu_specificRegs;


/**************************************************************************
* Register Overlay Structure for MISC
**************************************************************************/
typedef struct {
    volatile Uint32 MMRAM_OFFSET;
    volatile Uint32 FLADJ;
    volatile Uint32 DEBUG_CFG;
    volatile Uint32 DEBUG_DATA;
    volatile Uint32 DEV_EBC_EN;
} CSL_UsbtopMiscRegs;


/**************************************************************************
* Register Overlay Structure for IRQ_EOI_MISC
**************************************************************************/
typedef struct {
    volatile Uint32 IRQ_EOI_MISC;
} CSL_UsbtopIrq_eoi_miscRegs;


/**************************************************************************
* Register Overlay Structure for IRQ_OABS
**************************************************************************/
typedef struct {
    volatile Uint32 IRQ_EOI_OABS;
    volatile Uint32 IRQ_STATUS_RAW_OABS;
    volatile Uint32 IRQ_STATUS_OABS;
    volatile Uint32 IRQ_ENABLE_SET_OABS;
    volatile Uint32 IRQ_ENABLE_CLR_OABS;
} CSL_UsbtopIrq_oabsRegs;


/**************************************************************************
* Register Overlay Structure for FIFO_DEPTHS
**************************************************************************/
typedef struct {
    volatile Uint32 TXFIFO_DEPTH;
    volatile Uint32 RXFIFO_DEPTH;
} CSL_UsbtopFifo_depthsRegs;


/**************************************************************************
* Register Overlay Structure for DSPS_SPECIFIC
**************************************************************************/
typedef struct {
    volatile Uint32 SER_CONTROL;
    volatile Uint32 SER_STATUS;
    volatile Uint32 SER_ADDRESS;
    volatile Uint32 PHY2CONFIG;
    volatile Uint32 PHY3CONFIG;
} CSL_UsbtopDsps_specificRegs;


/**************************************************************************
* Register Overlay Structure for NG_SPECIFIC
**************************************************************************/
typedef struct {
    volatile Uint32 HOST_CTRL;
    volatile Uint32 HOST_STATUS;
} CSL_UsbtopNg_specificRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD1[12];
    volatile Uint32 IRQ_EOI;
    CSL_UsbtopIrq_hst_devRegs	IRQ_HST_DEV;
    CSL_UsbtopIrq_miscRegs	IRQ_MISC;
    volatile Uint8  RSVD2[60];
    CSL_UsbtopWbu_specificRegs	WBU_SPECIFIC;
    volatile Uint8  RSVD3[120];
    CSL_UsbtopMiscRegs	MISC;
    volatile Uint8  RSVD4[792];
    volatile Uint8  RSVD5[32];
    volatile Uint8  RSVD6[188];
    volatile Uint8  RSVD7[248];
    volatile Uint8  RSVD8[276];
} CSL_UsbTopRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier (X.Y.R) Used by software to track features, bugs, 
 * and compatibility */
#define CSL_USBTOP_REVISION                                     (0x0U)

/* Controls various parameters of the master and slave interfaces. */
#define CSL_USBTOP_SYSCONFIG                                    (0x10U)

/* Software End-Of-Interrupt: Allows the generation of further pulses on the 
 * interrupt line, if an new interrupt event is pending, when using the pulsed 
 * output. Unused when using the level interrupt line (depending on module 
 * integration). */
#define CSL_USBTOP_IRQ_EOI                                      (0x20U)

/* Raw status of host/device interrupt line. Is set even if event is not 
 * enabled. Write 1 to set, used mostly for debug (regular status also gets 
 * set if enabled). */
#define CSL_USBTOP_IRQSTATUS_RAW_0                              (0x24U)

/* "regular" status of main core interrupt request. Set only when enabled, 
 * self-cleared unless it was set by writing to STATUS_RAW, for debug. Write 1 
 * to clear (raw status also gets cleared). */
#define CSL_USBTOP_IRQSTATUS_0                                  (0x28U)

/* Enable of main core interrupt request. Write 1 to set (i.e. to enable 
 * interrupt). Readout is the same as corresponding _CLR register. */
#define CSL_USBTOP_IRQENABLE_SET_0                              (0x2CU)

/* Enable of main core interrupt request. Write 1 to clear (i.e. to disable 
 * interrupt). Readout is the same as corresponding _SET register. */
#define CSL_USBTOP_IRQENABLE_CLR_0                              (0x30U)

/* Raw status of secondary interrupt requests. Set even if event is not 
 * enabled. Write 1 to set the (raw) status, mostly for debug (regular status 
 * also gets set). */
#define CSL_USBTOP_IRQSTATUS_RAW_1                              (0x34U)

/* "regular" status of secondary interrupt requests. Set only when enabled. 
 * Write 1 to clear after interrupt has been serviced (raw status also gets 
 * cleared). */
#define CSL_USBTOP_IRQSTATUS_1                                  (0x38U)

/* Enable of secondary interrupt requests. Write 1 to set (i.e. to disable 
 * interrupt). Readout is the same as corresponding _CLR register. */
#define CSL_USBTOP_IRQENABLE_SET_1                              (0x3CU)

/* Enable of secondary interrupt requests. Write 1 to clear (i.e. to disable 
 * interrupt). Readout is the same as corresponding _SET register. */
#define CSL_USBTOP_IRQENABLE_CLR_1                              (0x40U)

/* UTMI_OTG_CTRL */
#define CSL_USBTOP_UTMI_OTG_CTRL                                (0x80U)

/* UTMI_OTG_STATUS */
#define CSL_USBTOP_UTMI_OTG_STATUS                              (0x84U)

/* Offset of Memory-mapped RAM accesses. Page is remapped from 0x8000 to 
 * 0xFFFF (32 kbyte) */
#define CSL_USBTOP_MMRAM_OFFSET                                 (0x100U)

/* Jitter adjustment and other pseudo-static parameters */
#define CSL_USBTOP_FLADJ                                        (0x104U)

/* data currently visible on DEBUG output (observability) port depends on mode 
 * given in DEBUG_CFG.sel , shown only for sel = (1;2;3) all bits are tied low 
 * (0) when sel=0 */
#define CSL_USBTOP_DEBUG_DATA                                   (0x10CU)

/* Configuration of debug output (observability) */
#define CSL_USBTOP_DEBUG_CFG                                    (0x108U)

/* Enable External Buffer Control (EBC) for selected endpoints. Device mode 
 * only. */
#define CSL_USBTOP_DEV_EBC_EN                                   (0x110U)

/* IRQ_EOI_MISC */
#define CSL_USBTOP_IRQ_EOI_MISC(n)                              (0x42CU + ((n) * (0x4U)))

/* IRQ_EOI_OABS */
#define CSL_USBTOP_IRQ_EOI_OABS(n)                              (0x44CU + ((n) * (0x14U)))

/* IRQ_STATUS_RAW_OABS */
#define CSL_USBTOP_IRQ_STATUS_RAW_OABS(n)                       (0x450U + ((n) * (0x14U)))

/* IRQ_STATUS_OABS */
#define CSL_USBTOP_IRQ_STATUS_OABS(n)                           (0x454U + ((n) * (0x14U)))

/* IRQ_ENABLE_SET_OABS */
#define CSL_USBTOP_IRQ_ENABLE_SET_OABS(n)                       (0x458U + ((n) * (0x14U)))

/* IRQ_ENABLE_CLR_OABS */
#define CSL_USBTOP_IRQ_ENABLE_CLR_OABS(n)                       (0x45CU + ((n) * (0x14U)))

/* TXFIFO_DEPTH */
#define CSL_USBTOP_TXFIFO_DEPTH(n)                              (0x508U + ((n) * (0x8U)))

/* RXFIFO_DEPTH */
#define CSL_USBTOP_RXFIFO_DEPTH(n)                              (0x50CU + ((n) * (0x8U)))

/* Soft Error Rate control */
#define CSL_USBTOP_SER_CONTROL(n)                               (0x600U + ((n) * (0x14U)))

/* Soft Error Rate status */
#define CSL_USBTOP_SER_STATUS(n)                                (0x604U + ((n) * (0x14U)))

/* Soft Error Rate address */
#define CSL_USBTOP_SER_ADDRESS(n)                               (0x608U + ((n) * (0x14U)))

/* USB2 transceiver configuration */
#define CSL_USBTOP_PHY2CONFIG(n)                                (0x60CU + ((n) * (0x14U)))

/* USB3 transceiver configuration */
#define CSL_USBTOP_PHY3CONFIG(n)                                (0x610U + ((n) * (0x14U)))

/* HOST_CTRL */
#define CSL_USBTOP_HOST_CTRL(n)                                 (0x714U + ((n) * (0x8U)))

/* HOST_STATUS */
#define CSL_USBTOP_HOST_STATUS(n)                               (0x718U + ((n) * (0x8U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_USBTOP_REVISION_Y_MINOR_MASK                        (0x0000003FU)
#define CSL_USBTOP_REVISION_Y_MINOR_SHIFT                       (0U)
#define CSL_USBTOP_REVISION_Y_MINOR_RESETVAL                    (0x00000000U)
#define CSL_USBTOP_REVISION_Y_MINOR_MAX                         (0x0000003fU)

#define CSL_USBTOP_REVISION_CUSTOM_MASK                         (0x000000C0U)
#define CSL_USBTOP_REVISION_CUSTOM_SHIFT                        (6U)
#define CSL_USBTOP_REVISION_CUSTOM_RESETVAL                     (0x00000000U)
#define CSL_USBTOP_REVISION_CUSTOM_STANDARD                     (0x00000000U)

#define CSL_USBTOP_REVISION_X_MAJOR_MASK                        (0x00000700U)
#define CSL_USBTOP_REVISION_X_MAJOR_SHIFT                       (8U)
#define CSL_USBTOP_REVISION_X_MAJOR_RESETVAL                    (0x00000002U)
#define CSL_USBTOP_REVISION_X_MAJOR_V10                         (0x00000001U)
#define CSL_USBTOP_REVISION_X_MAJOR_V20                         (0x00000002U)

#define CSL_USBTOP_REVISION_R_RTL_MASK                          (0x0000F800U)
#define CSL_USBTOP_REVISION_R_RTL_SHIFT                         (11U)
#define CSL_USBTOP_REVISION_R_RTL_RESETVAL                      (0x00000000U)
#define CSL_USBTOP_REVISION_R_RTL_MAX                           (0x0000001fU)

#define CSL_USBTOP_REVISION_FUNC_MASK                           (0x0FFF0000U)
#define CSL_USBTOP_REVISION_FUNC_SHIFT                          (16U)
#define CSL_USBTOP_REVISION_FUNC_RESETVAL                       (0x0000000aU)
#define CSL_USBTOP_REVISION_FUNC_MAX                            (0x00000fffU)

#define CSL_USBTOP_REVISION_SCHEME_MASK                         (0xC0000000U)
#define CSL_USBTOP_REVISION_SCHEME_SHIFT                        (30U)
#define CSL_USBTOP_REVISION_SCHEME_RESETVAL                     (0x00000001U)
#define CSL_USBTOP_REVISION_SCHEME_H08                          (0x00000001U)
#define CSL_USBTOP_REVISION_SCHEME_LEGACY                       (0x00000000U)

#define CSL_USBTOP_REVISION_BU_MASK                             (0x30000000U)
#define CSL_USBTOP_REVISION_BU_SHIFT                            (28U)
#define CSL_USBTOP_REVISION_BU_RESETVAL                         (0x00000001U)
#define CSL_USBTOP_REVISION_BU_WBU                              (0x00000001U)
#define CSL_USBTOP_REVISION_BU_DSPS                             (0x00000000U)

#define CSL_USBTOP_REVISION_RESETVAL                            (0x500a0200U)

/* SYSCONFIG */

#define CSL_USBTOP_SYSCONFIG_IDLEMODE_MASK                      (0x0000000CU)
#define CSL_USBTOP_SYSCONFIG_IDLEMODE_SHIFT                     (2U)
#define CSL_USBTOP_SYSCONFIG_IDLEMODE_RESETVAL                  (0x00000002U)
#define CSL_USBTOP_SYSCONFIG_IDLEMODE_FORCE                     (0x00000000U)
#define CSL_USBTOP_SYSCONFIG_IDLEMODE_NO                        (0x00000001U)
#define CSL_USBTOP_SYSCONFIG_IDLEMODE_SMART                     (0x00000002U)
#define CSL_USBTOP_SYSCONFIG_IDLEMODE_SMART_WAKEUP              (0x00000003U)

#define CSL_USBTOP_SYSCONFIG_STANDBYMODE_MASK                   (0x00000030U)
#define CSL_USBTOP_SYSCONFIG_STANDBYMODE_SHIFT                  (4U)
#define CSL_USBTOP_SYSCONFIG_STANDBYMODE_RESETVAL               (0x00000002U)
#define CSL_USBTOP_SYSCONFIG_STANDBYMODE_FORCE                  (0x00000000U)
#define CSL_USBTOP_SYSCONFIG_STANDBYMODE_NO                     (0x00000001U)
#define CSL_USBTOP_SYSCONFIG_STANDBYMODE_SMART                  (0x00000002U)
#define CSL_USBTOP_SYSCONFIG_STANDBYMODE_SMART_WAKEUP           (0x00000003U)

#define CSL_USBTOP_SYSCONFIG_DMADISABLE_MASK                    (0x00010000U)
#define CSL_USBTOP_SYSCONFIG_DMADISABLE_SHIFT                   (16U)
#define CSL_USBTOP_SYSCONFIG_DMADISABLE_RESETVAL                (0x00000001U)
#define CSL_USBTOP_SYSCONFIG_DMADISABLE_DISABLED                (0x00000001U)
#define CSL_USBTOP_SYSCONFIG_DMADISABLE_ENABLED                 (0x00000000U)
#define CSL_USBTOP_SYSCONFIG_DMADISABLE_DISABLE                 (0x00000001U)
#define CSL_USBTOP_SYSCONFIG_DMADISABLE_ENABLE                  (0x00000000U)

#define CSL_USBTOP_SYSCONFIG_WRAPRESET_MASK                     (0x00020000U)
#define CSL_USBTOP_SYSCONFIG_WRAPRESET_SHIFT                    (17U)
#define CSL_USBTOP_SYSCONFIG_WRAPRESET_RESETVAL                 (0x00000000U)
#define CSL_USBTOP_SYSCONFIG_WRAPRESET_DORST                    (0x00000001U)
#define CSL_USBTOP_SYSCONFIG_WRAPRESET_NOOP                     (0x00000000U)
#define CSL_USBTOP_SYSCONFIG_WRAPRESET_ACTIVE                   (0x00000001U)
#define CSL_USBTOP_SYSCONFIG_WRAPRESET_DONE                     (0x00000000U)

#define CSL_USBTOP_SYSCONFIG_RESETVAL                           (0x00010028U)

/* IRQ_EOI */

#define CSL_USBTOP_IRQ_EOI_LINE_NUMBER_MASK                     (0x0000001FU)
#define CSL_USBTOP_IRQ_EOI_LINE_NUMBER_SHIFT                    (0U)
#define CSL_USBTOP_IRQ_EOI_LINE_NUMBER_RESETVAL                 (0x00000000U)
#define CSL_USBTOP_IRQ_EOI_LINE_NUMBER_MAX                      (0x0000001fU)

#define CSL_USBTOP_IRQ_EOI_RESETVAL                             (0x00000000U)

/* IRQSTATUS_RAW_0 */

#define CSL_USBTOP_IRQSTATUS_RAW_0_COREIRQ_ST_MASK              (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_0_COREIRQ_ST_SHIFT             (0U)
#define CSL_USBTOP_IRQSTATUS_RAW_0_COREIRQ_ST_RESETVAL          (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_0_COREIRQ_ST_NONE              (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_0_COREIRQ_ST_PENDING           (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_0_COREIRQ_ST_NOACTION          (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_0_COREIRQ_ST_SET               (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_0_RESETVAL                     (0x00000000U)

/* IRQSTATUS_0 */

#define CSL_USBTOP_IRQSTATUS_0_COREIRQ_ST_MASK                  (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_0_COREIRQ_ST_SHIFT                 (0U)
#define CSL_USBTOP_IRQSTATUS_0_COREIRQ_ST_RESETVAL              (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_0_COREIRQ_ST_NONE                  (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_0_COREIRQ_ST_PENDING               (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_0_COREIRQ_ST_NOACTION              (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_0_COREIRQ_ST_CLEAR                 (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_0_RESETVAL                         (0x00000000U)

/* IRQENABLE_SET_0 */

#define CSL_USBTOP_IRQENABLE_SET_0_COREIRQ_EN_MASK              (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_0_COREIRQ_EN_SHIFT             (0U)
#define CSL_USBTOP_IRQENABLE_SET_0_COREIRQ_EN_RESETVAL          (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_0_COREIRQ_EN_DISABLED          (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_0_COREIRQ_EN_ENABLED           (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_0_COREIRQ_EN_NOACTION          (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_0_COREIRQ_EN_SET               (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_0_RESETVAL                     (0x00000000U)

/* IRQENABLE_CLR_0 */

#define CSL_USBTOP_IRQENABLE_CLR_0_COREIRQ_EN_MASK              (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_0_COREIRQ_EN_SHIFT             (0U)
#define CSL_USBTOP_IRQENABLE_CLR_0_COREIRQ_EN_RESETVAL          (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_0_COREIRQ_EN_DISABLED          (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_0_COREIRQ_EN_ENABLED           (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_0_COREIRQ_EN_NOACTION          (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_0_COREIRQ_EN_CLEAR             (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_0_RESETVAL                     (0x00000000U)

/* IRQSTATUS_RAW_1 */

#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_RISE_MASK           (0x00000100U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_RISE_SHIFT          (8U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_RISE_RESETVAL       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_RISE_NONE           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_RISE_PENDING        (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_RISE_NOACTION       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_RISE_SET            (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_RISE_MASK        (0x00000800U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_RISE_SHIFT       (11U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_RISE_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_RISE_NONE        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_RISE_PENDING     (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_RISE_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_RISE_SET         (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_RISE_MASK           (0x00001000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_RISE_SHIFT          (12U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_RISE_RESETVAL       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_RISE_NONE           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_RISE_PENDING        (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_RISE_NOACTION       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_RISE_SET            (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_RISE_MASK            (0x00002000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_RISE_SHIFT           (13U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_RISE_RESETVAL        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_RISE_NONE            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_RISE_PENDING         (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_RISE_NOACTION        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_RISE_SET             (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_FALL_MASK           (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_FALL_SHIFT          (0U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_FALL_RESETVAL       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_FALL_NONE           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_FALL_PENDING        (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_FALL_NOACTION       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_IDPULLUP_FALL_SET            (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_FALL_MASK        (0x00000008U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_FALL_SHIFT       (3U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_FALL_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_FALL_NONE        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_FALL_PENDING     (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_FALL_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DISCHRGVBUS_FALL_SET         (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_FALL_MASK           (0x00000010U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_FALL_SHIFT          (4U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_FALL_RESETVAL       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_FALL_NONE           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_FALL_PENDING        (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_FALL_NOACTION       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_CHRGVBUS_FALL_SET            (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_FALL_MASK            (0x00000020U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_FALL_SHIFT           (5U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_FALL_RESETVAL        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_FALL_NONE            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_FALL_PENDING         (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_FALL_NOACTION        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DRVVBUS_FALL_SET             (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_OEVT_MASK                    (0x00010000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_OEVT_SHIFT                   (16U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_OEVT_RESETVAL                (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_OEVT_NONE                    (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_OEVT_PENDING                 (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_OEVT_NOACTION                (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_OEVT_SET                     (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_DMADISABLECLR_MASK           (0x00020000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DMADISABLECLR_SHIFT          (17U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DMADISABLECLR_RESETVAL       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DMADISABLECLR_NONE           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DMADISABLECLR_PENDING        (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DMADISABLECLR_NOACTION       (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_RAW_1_DMADISABLECLR_SET            (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_RAW_1_RESETVAL                     (0x00000000U)

/* IRQSTATUS_1 */

#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_RISE_MASK               (0x00000100U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_RISE_SHIFT              (8U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_RISE_RESETVAL           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_RISE_NONE               (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_RISE_PENDING            (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_RISE_NOACTION           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_RISE_CLEAR              (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_RISE_MASK            (0x00000800U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_RISE_SHIFT           (11U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_RISE_RESETVAL        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_RISE_NONE            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_RISE_PENDING         (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_RISE_NOACTION        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_RISE_CLEAR           (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_RISE_MASK               (0x00001000U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_RISE_SHIFT              (12U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_RISE_RESETVAL           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_RISE_NONE               (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_RISE_PENDING            (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_RISE_NOACTION           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_RISE_CLEAR              (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_RISE_MASK                (0x00002000U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_RISE_SHIFT               (13U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_RISE_RESETVAL            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_RISE_NONE                (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_RISE_PENDING             (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_RISE_NOACTION            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_RISE_CLEAR               (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_FALL_MASK               (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_FALL_SHIFT              (0U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_FALL_RESETVAL           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_FALL_NONE               (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_FALL_PENDING            (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_FALL_NOACTION           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_IDPULLUP_FALL_CLEAR              (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_FALL_MASK            (0x00000008U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_FALL_SHIFT           (3U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_FALL_RESETVAL        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_FALL_NONE            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_FALL_PENDING         (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_FALL_NOACTION        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DISCHRGVBUS_FALL_CLEAR           (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_FALL_MASK               (0x00000010U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_FALL_SHIFT              (4U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_FALL_RESETVAL           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_FALL_NONE               (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_FALL_PENDING            (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_FALL_NOACTION           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_CHRGVBUS_FALL_CLEAR              (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_FALL_MASK                (0x00000020U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_FALL_SHIFT               (5U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_FALL_RESETVAL            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_FALL_NONE                (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_FALL_PENDING             (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_FALL_NOACTION            (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DRVVBUS_FALL_CLEAR               (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_OEVT_MASK                        (0x00010000U)
#define CSL_USBTOP_IRQSTATUS_1_OEVT_SHIFT                       (16U)
#define CSL_USBTOP_IRQSTATUS_1_OEVT_RESETVAL                    (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_OEVT_NONE                        (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_OEVT_PENDING                     (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_OEVT_NOACTION                    (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_OEVT_CLEAR                       (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_DMADISABLECLR_MASK               (0x00020000U)
#define CSL_USBTOP_IRQSTATUS_1_DMADISABLECLR_SHIFT              (17U)
#define CSL_USBTOP_IRQSTATUS_1_DMADISABLECLR_RESETVAL           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DMADISABLECLR_NONE               (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DMADISABLECLR_PENDING            (0x00000001U)
#define CSL_USBTOP_IRQSTATUS_1_DMADISABLECLR_NOACTION           (0x00000000U)
#define CSL_USBTOP_IRQSTATUS_1_DMADISABLECLR_CLEAR              (0x00000001U)

#define CSL_USBTOP_IRQSTATUS_1_RESETVAL                         (0x00000000U)

/* IRQENABLE_SET_1 */

#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_FALL_EN_MASK        (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_FALL_EN_SHIFT       (0U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_FALL_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_FALL_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_FALL_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_FALL_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_FALL_EN_SET         (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_FALL_EN_MASK     (0x00000008U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_FALL_EN_SHIFT    (3U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_FALL_EN_RESETVAL  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_FALL_EN_DISABLED  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_FALL_EN_ENABLED  (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_FALL_EN_NOACTION  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_FALL_EN_SET      (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_FALL_EN_MASK        (0x00000010U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_FALL_EN_SHIFT       (4U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_FALL_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_FALL_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_FALL_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_FALL_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_FALL_EN_SET         (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_FALL_EN_MASK         (0x00000020U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_FALL_EN_SHIFT        (5U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_FALL_EN_RESETVAL     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_FALL_EN_DISABLED     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_FALL_EN_ENABLED      (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_FALL_EN_NOACTION     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_FALL_EN_SET          (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_RISE_EN_MASK        (0x00000100U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_RISE_EN_SHIFT       (8U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_RISE_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_RISE_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_RISE_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_RISE_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_IDPULLUP_RISE_EN_SET         (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_RISE_EN_MASK     (0x00000800U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_RISE_EN_SHIFT    (11U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_RISE_EN_RESETVAL  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_RISE_EN_DISABLED  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_RISE_EN_ENABLED  (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_RISE_EN_NOACTION  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DISCHRGVBUS_RISE_EN_SET      (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_RISE_EN_MASK        (0x00001000U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_RISE_EN_SHIFT       (12U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_RISE_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_RISE_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_RISE_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_RISE_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_CHRGVBUS_RISE_EN_SET         (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_RISE_EN_MASK         (0x00002000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_RISE_EN_SHIFT        (13U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_RISE_EN_RESETVAL     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_RISE_EN_DISABLED     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_RISE_EN_ENABLED      (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_RISE_EN_NOACTION     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DRVVBUS_RISE_EN_SET          (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_OEVT_EN_MASK                 (0x00010000U)
#define CSL_USBTOP_IRQENABLE_SET_1_OEVT_EN_SHIFT                (16U)
#define CSL_USBTOP_IRQENABLE_SET_1_OEVT_EN_RESETVAL             (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_OEVT_EN_DISABLED             (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_OEVT_EN_ENABLED              (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_OEVT_EN_NOACTION             (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_OEVT_EN_SET                  (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_DMADISABLECLR_EN_MASK        (0x00020000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DMADISABLECLR_EN_SHIFT       (17U)
#define CSL_USBTOP_IRQENABLE_SET_1_DMADISABLECLR_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DMADISABLECLR_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DMADISABLECLR_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_SET_1_DMADISABLECLR_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_SET_1_DMADISABLECLR_EN_SET         (0x00000001U)

#define CSL_USBTOP_IRQENABLE_SET_1_RESETVAL                     (0x00000000U)

/* IRQENABLE_CLR_1 */

#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_FALL_EN_MASK        (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_FALL_EN_SHIFT       (0U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_FALL_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_FALL_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_FALL_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_FALL_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_FALL_EN_CLEAR       (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_FALL_EN_MASK     (0x00000008U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_FALL_EN_SHIFT    (3U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_FALL_EN_RESETVAL  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_FALL_EN_DISABLED  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_FALL_EN_ENABLED  (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_FALL_EN_NOACTION  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_FALL_EN_CLEAR    (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_FALL_EN_MASK        (0x00000010U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_FALL_EN_SHIFT       (4U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_FALL_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_FALL_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_FALL_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_FALL_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_FALL_EN_CLEAR       (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_FALL_EN_MASK         (0x00000020U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_FALL_EN_SHIFT        (5U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_FALL_EN_RESETVAL     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_FALL_EN_DISABLED     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_FALL_EN_ENABLED      (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_FALL_EN_NOACTION     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_FALL_EN_CLEAR        (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_RISE_EN_MASK        (0x00000100U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_RISE_EN_SHIFT       (8U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_RISE_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_RISE_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_RISE_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_RISE_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_IDPULLUP_RISE_EN_CLEAR       (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_RISE_EN_MASK     (0x00000800U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_RISE_EN_SHIFT    (11U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_RISE_EN_RESETVAL  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_RISE_EN_DISABLED  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_RISE_EN_ENABLED  (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_RISE_EN_NOACTION  (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DISCHRGVBUS_RISE_EN_CLEAR    (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_RISE_EN_MASK        (0x00001000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_RISE_EN_SHIFT       (12U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_RISE_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_RISE_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_RISE_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_RISE_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_CHRGVBUS_RISE_EN_CLEAR       (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_RISE_EN_MASK         (0x00002000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_RISE_EN_SHIFT        (13U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_RISE_EN_RESETVAL     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_RISE_EN_DISABLED     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_RISE_EN_ENABLED      (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_RISE_EN_NOACTION     (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DRVVBUS_RISE_EN_CLEAR        (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_OEVT_EN_MASK                 (0x00010000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_OEVT_EN_SHIFT                (16U)
#define CSL_USBTOP_IRQENABLE_CLR_1_OEVT_EN_RESETVAL             (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_OEVT_EN_DISABLED             (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_OEVT_EN_ENABLED              (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_OEVT_EN_NOACTION             (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_OEVT_EN_CLEAR                (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_DMADISABLECLR_EN_MASK        (0x00020000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DMADISABLECLR_EN_SHIFT       (17U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DMADISABLECLR_EN_RESETVAL    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DMADISABLECLR_EN_DISABLED    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DMADISABLECLR_EN_ENABLED     (0x00000001U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DMADISABLECLR_EN_NOACTION    (0x00000000U)
#define CSL_USBTOP_IRQENABLE_CLR_1_DMADISABLECLR_EN_CLEAR       (0x00000001U)

#define CSL_USBTOP_IRQENABLE_CLR_1_RESETVAL                     (0x00000000U)

/* UTMI_OTG_CTRL */

#define CSL_USBTOP_UTMI_OTG_CTRL_IDPULLUP_MASK                  (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_CTRL_IDPULLUP_SHIFT                 (0U)
#define CSL_USBTOP_UTMI_OTG_CTRL_IDPULLUP_RESETVAL              (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_CTRL_IDPULLUP_DISABLE               (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_CTRL_IDPULLUP_ENABLE                (0x00000001U)

#define CSL_USBTOP_UTMI_OTG_CTRL_DISCHRGVBUS_MASK               (0x00000008U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DISCHRGVBUS_SHIFT              (3U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DISCHRGVBUS_RESETVAL           (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DISCHRGVBUS_DISCHARGE          (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DISCHRGVBUS_NOACTION           (0x00000000U)

#define CSL_USBTOP_UTMI_OTG_CTRL_CHRGVBUS_MASK                  (0x00000010U)
#define CSL_USBTOP_UTMI_OTG_CTRL_CHRGVBUS_SHIFT                 (4U)
#define CSL_USBTOP_UTMI_OTG_CTRL_CHRGVBUS_RESETVAL              (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_CTRL_CHRGVBUS_CHARGE                (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_CTRL_CHRGVBUS_NOACTION              (0x00000000U)

#define CSL_USBTOP_UTMI_OTG_CTRL_DRVVBUS_MASK                   (0x00000020U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DRVVBUS_SHIFT                  (5U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DRVVBUS_RESETVAL               (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DRVVBUS_DRIVE                  (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_CTRL_DRVVBUS_NOACTION               (0x00000000U)

#define CSL_USBTOP_UTMI_OTG_CTRL_RESETVAL                       (0x00000001U)

/* UTMI_OTG_STATUS */

#define CSL_USBTOP_UTMI_OTG_STATUS_SW_MODE_MASK                 (0x80000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SW_MODE_SHIFT                (31U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SW_MODE_RESETVAL             (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SW_MODE_IO                   (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SW_MODE_SW                   (0x00000001U)

#define CSL_USBTOP_UTMI_OTG_STATUS_VBUSVALID_MASK               (0x00000002U)
#define CSL_USBTOP_UTMI_OTG_STATUS_VBUSVALID_SHIFT              (1U)
#define CSL_USBTOP_UTMI_OTG_STATUS_VBUSVALID_RESETVAL           (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_VBUSVALID_VALID              (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_STATUS_VBUSVALID_NOTVALID           (0x00000000U)

#define CSL_USBTOP_UTMI_OTG_STATUS_SESSVALID_MASK               (0x00000004U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSVALID_SHIFT              (2U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSVALID_RESETVAL           (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSVALID_NOTVALID           (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSVALID_VALID              (0x00000001U)

#define CSL_USBTOP_UTMI_OTG_STATUS_SESSEND_MASK                 (0x00000008U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSEND_SHIFT                (3U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSEND_RESETVAL             (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSEND_ENDED                (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_STATUS_SESSEND_NOTENDED             (0x00000000U)

#define CSL_USBTOP_UTMI_OTG_STATUS_IDDIG_MASK                   (0x00000010U)
#define CSL_USBTOP_UTMI_OTG_STATUS_IDDIG_SHIFT                  (4U)
#define CSL_USBTOP_UTMI_OTG_STATUS_IDDIG_RESETVAL               (0x00000001U)
#define CSL_USBTOP_UTMI_OTG_STATUS_IDDIG_IDA                    (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_IDDIG_IDB                    (0x00000001U)

#define CSL_USBTOP_UTMI_OTG_STATUS_TXBITSTUFFENABLE_MASK        (0x00000100U)
#define CSL_USBTOP_UTMI_OTG_STATUS_TXBITSTUFFENABLE_SHIFT       (8U)
#define CSL_USBTOP_UTMI_OTG_STATUS_TXBITSTUFFENABLE_RESETVAL    (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_TXBITSTUFFENABLE_NOBS        (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_TXBITSTUFFENABLE_BS          (0x00000001U)

#define CSL_USBTOP_UTMI_OTG_STATUS_POWERPRESENT_MASK            (0x00000200U)
#define CSL_USBTOP_UTMI_OTG_STATUS_POWERPRESENT_SHIFT           (9U)
#define CSL_USBTOP_UTMI_OTG_STATUS_POWERPRESENT_RESETVAL        (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_POWERPRESENT_MAX             (0x00000001U)

#define CSL_USBTOP_UTMI_OTG_STATUS_PORT_OVERCURRENT_MASK        (0x00000400U)
#define CSL_USBTOP_UTMI_OTG_STATUS_PORT_OVERCURRENT_SHIFT       (10U)
#define CSL_USBTOP_UTMI_OTG_STATUS_PORT_OVERCURRENT_RESETVAL    (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_PORT_OVERCURRENT_NONE        (0x00000000U)
#define CSL_USBTOP_UTMI_OTG_STATUS_PORT_OVERCURRENT_OC          (0x00000001U)

#define CSL_USBTOP_UTMI_OTG_STATUS_RESETVAL                     (0x80000018U)

/* MMRAM_OFFSET */

#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_MSB_MASK                 (0x000F8000U)
#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_MSB_SHIFT                (15U)
#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_MSB_RESETVAL             (0x00000008U)
#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_MSB_MAX                  (0x0000001fU)

#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_LSB_MASK                 (0x00007FFFU)
#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_LSB_SHIFT                (0U)
#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_LSB_RESETVAL             (0x00000000U)
#define CSL_USBTOP_MMRAM_OFFSET_OFFSET_LSB_MAX                  (0x00007fffU)

#define CSL_USBTOP_MMRAM_OFFSET_RESETVAL                        (0x00040000U)

/* FLADJ */

#define CSL_USBTOP_FLADJ_FLADJ_30MHZ_MASK                       (0x07E00000U)
#define CSL_USBTOP_FLADJ_FLADJ_30MHZ_SHIFT                      (21U)
#define CSL_USBTOP_FLADJ_FLADJ_30MHZ_RESETVAL                   (0x00000020U)
#define CSL_USBTOP_FLADJ_FLADJ_30MHZ_MAX                        (0x0000003fU)

#define CSL_USBTOP_FLADJ_HOST_U2_PORT_DISABLE_MASK              (0x08000000U)
#define CSL_USBTOP_FLADJ_HOST_U2_PORT_DISABLE_SHIFT             (27U)
#define CSL_USBTOP_FLADJ_HOST_U2_PORT_DISABLE_RESETVAL          (0x00000000U)
#define CSL_USBTOP_FLADJ_HOST_U2_PORT_DISABLE_EN                (0x00000000U)
#define CSL_USBTOP_FLADJ_HOST_U2_PORT_DISABLE_DIS               (0x00000001U)

#define CSL_USBTOP_FLADJ_HOST_U3_PORT_DISABLE_MASK              (0x10000000U)
#define CSL_USBTOP_FLADJ_HOST_U3_PORT_DISABLE_SHIFT             (28U)
#define CSL_USBTOP_FLADJ_HOST_U3_PORT_DISABLE_RESETVAL          (0x00000000U)
#define CSL_USBTOP_FLADJ_HOST_U3_PORT_DISABLE_EN                (0x00000000U)
#define CSL_USBTOP_FLADJ_HOST_U3_PORT_DISABLE_DIS               (0x00000001U)

#define CSL_USBTOP_FLADJ_XHCI_REVISION_MASK                     (0x20000000U)
#define CSL_USBTOP_FLADJ_XHCI_REVISION_SHIFT                    (29U)
#define CSL_USBTOP_FLADJ_XHCI_REVISION_RESETVAL                 (0x00000001U)
#define CSL_USBTOP_FLADJ_XHCI_REVISION__0_96                    (0x00000000U)
#define CSL_USBTOP_FLADJ_XHCI_REVISION__1_0                     (0x00000001U)

#define CSL_USBTOP_FLADJ_CORE_SW_RESET_MASK                     (0x80000000U)
#define CSL_USBTOP_FLADJ_CORE_SW_RESET_SHIFT                    (31U)
#define CSL_USBTOP_FLADJ_CORE_SW_RESET_RESETVAL                 (0x00000000U)
#define CSL_USBTOP_FLADJ_CORE_SW_RESET_NORESET                  (0x00000000U)
#define CSL_USBTOP_FLADJ_CORE_SW_RESET_RESET                    (0x00000001U)

#define CSL_USBTOP_FLADJ_RESETVAL                               (0x24000000U)

/* DEBUG_DATA */

#define CSL_USBTOP_DEBUG_DATA_DEBUG0_MASK                       (0x00000001U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG0_SHIFT                      (0U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG0_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG0_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG1_MASK                       (0x00000002U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG1_SHIFT                      (1U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG1_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG1_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG2_MASK                       (0x00000004U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG2_SHIFT                      (2U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG2_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG2_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG3_MASK                       (0x00000008U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG3_SHIFT                      (3U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG3_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG3_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG4_MASK                       (0x00000010U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG4_SHIFT                      (4U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG4_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG4_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG5_MASK                       (0x00000020U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG5_SHIFT                      (5U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG5_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG5_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG6_MASK                       (0x00000040U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG6_SHIFT                      (6U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG6_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG6_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG7_MASK                       (0x00000080U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG7_SHIFT                      (7U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG7_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG7_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG8_MASK                       (0x00000100U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG8_SHIFT                      (8U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG8_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG8_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG9_MASK                       (0x00000200U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG9_SHIFT                      (9U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG9_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG9_MAX                        (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG10_MASK                      (0x00000400U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG10_SHIFT                     (10U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG10_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG10_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG11_MASK                      (0x00000800U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG11_SHIFT                     (11U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG11_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG11_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG12_MASK                      (0x00001000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG12_SHIFT                     (12U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG12_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG12_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG13_MASK                      (0x00002000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG13_SHIFT                     (13U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG13_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG13_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG14_MASK                      (0x00004000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG14_SHIFT                     (14U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG14_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG14_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG15_MASK                      (0x00008000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG15_SHIFT                     (15U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG15_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG15_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG16_MASK                      (0x00010000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG16_SHIFT                     (16U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG16_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG16_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG17_MASK                      (0x00020000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG17_SHIFT                     (17U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG17_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG17_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG18_MASK                      (0x00040000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG18_SHIFT                     (18U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG18_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG18_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG19_MASK                      (0x00080000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG19_SHIFT                     (19U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG19_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG19_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG20_MASK                      (0x00100000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG20_SHIFT                     (20U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG20_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG20_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG21_MASK                      (0x00200000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG21_SHIFT                     (21U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG21_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG21_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG22_MASK                      (0x00400000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG22_SHIFT                     (22U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG22_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG22_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG23_MASK                      (0x00800000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG23_SHIFT                     (23U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG23_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG23_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG24_MASK                      (0x01000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG24_SHIFT                     (24U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG24_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG24_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG25_MASK                      (0x02000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG25_SHIFT                     (25U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG25_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG25_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG26_MASK                      (0x04000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG26_SHIFT                     (26U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG26_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG26_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG27_MASK                      (0x08000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG27_SHIFT                     (27U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG27_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG27_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG28_MASK                      (0x10000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG28_SHIFT                     (28U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG28_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG28_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG29_MASK                      (0x20000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG29_SHIFT                     (29U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG29_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG29_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG30_MASK                      (0x40000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG30_SHIFT                     (30U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG30_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG30_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_DEBUG31_MASK                      (0x80000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG31_SHIFT                     (31U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG31_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEBUG_DATA_DEBUG31_MAX                       (0x00000001U)

#define CSL_USBTOP_DEBUG_DATA_RESETVAL                          (0x00000000U)

/* DEBUG_CFG */

#define CSL_USBTOP_DEBUG_CFG_SEL_MASK                           (0x00000007U)
#define CSL_USBTOP_DEBUG_CFG_SEL_SHIFT                          (0U)
#define CSL_USBTOP_DEBUG_CFG_SEL_RESETVAL                       (0x00000000U)
#define CSL_USBTOP_DEBUG_CFG_SEL_TIELO                          (0x00000000U)
#define CSL_USBTOP_DEBUG_CFG_SEL_UTMI                           (0x00000001U)
#define CSL_USBTOP_DEBUG_CFG_SEL_PIPE                           (0x00000002U)
#define CSL_USBTOP_DEBUG_CFG_SEL_CORE                           (0x00000003U)
#define CSL_USBTOP_DEBUG_CFG_SEL_TRACE_LO                       (0x00000004U)
#define CSL_USBTOP_DEBUG_CFG_SEL_TRACE_HI                       (0x00000005U)

#define CSL_USBTOP_DEBUG_CFG_RESETVAL                           (0x00000000U)

/* DEV_EBC_EN */

#define CSL_USBTOP_DEV_EBC_EN_INEP15_MASK                       (0x00008000U)
#define CSL_USBTOP_DEV_EBC_EN_INEP15_SHIFT                      (15U)
#define CSL_USBTOP_DEV_EBC_EN_INEP15_RESETVAL                   (0x00000000U)
#define CSL_USBTOP_DEV_EBC_EN_INEP15_DIS                        (0x00000000U)
#define CSL_USBTOP_DEV_EBC_EN_INEP15_EN                         (0x00000001U)

#define CSL_USBTOP_DEV_EBC_EN_OUTEP15_MASK                      (0x80000000U)
#define CSL_USBTOP_DEV_EBC_EN_OUTEP15_SHIFT                     (31U)
#define CSL_USBTOP_DEV_EBC_EN_OUTEP15_RESETVAL                  (0x00000000U)
#define CSL_USBTOP_DEV_EBC_EN_OUTEP15_DIS                       (0x00000000U)
#define CSL_USBTOP_DEV_EBC_EN_OUTEP15_EN                        (0x00000001U)

#define CSL_USBTOP_DEV_EBC_EN_RESETVAL                          (0x00000000U)

/* IRQ_EOI_MISC */

#define CSL_USBTOP_IRQ_EOI_MISC_LINE_NUMBER_MASK                (0x00000001U)
#define CSL_USBTOP_IRQ_EOI_MISC_LINE_NUMBER_SHIFT               (0U)
#define CSL_USBTOP_IRQ_EOI_MISC_LINE_NUMBER_RESETVAL            (0x00000000U)
#define CSL_USBTOP_IRQ_EOI_MISC_LINE_NUMBER_READ0               (0x00000000U)
#define CSL_USBTOP_IRQ_EOI_MISC_LINE_NUMBER_EOI_MISC            (0x00000000U)

#define CSL_USBTOP_IRQ_EOI_MISC_RESETVAL                        (0x00000000U)

/* IRQ_EOI_OABS */

#define CSL_USBTOP_IRQ_EOI_OABS_LINE_NUMBER_MASK                (0x00000001U)
#define CSL_USBTOP_IRQ_EOI_OABS_LINE_NUMBER_SHIFT               (0U)
#define CSL_USBTOP_IRQ_EOI_OABS_LINE_NUMBER_RESETVAL            (0x00000000U)
#define CSL_USBTOP_IRQ_EOI_OABS_LINE_NUMBER_READ0               (0x00000000U)
#define CSL_USBTOP_IRQ_EOI_OABS_LINE_NUMBER_EOI_OABS            (0x00000000U)

#define CSL_USBTOP_IRQ_EOI_OABS_RESETVAL                        (0x00000000U)

/* IRQ_STATUS_RAW_OABS */

#define CSL_USBTOP_IRQ_STATUS_RAW_OABS_IRQ_STATUS_RAW_OABS_MASK  (0xFFFFFFFFU)
#define CSL_USBTOP_IRQ_STATUS_RAW_OABS_IRQ_STATUS_RAW_OABS_SHIFT  (0U)
#define CSL_USBTOP_IRQ_STATUS_RAW_OABS_IRQ_STATUS_RAW_OABS_RESETVAL  (0x00000000U)
#define CSL_USBTOP_IRQ_STATUS_RAW_OABS_IRQ_STATUS_RAW_OABS_MAX  (0xffffffffU)

#define CSL_USBTOP_IRQ_STATUS_RAW_OABS_RESETVAL                 (0x00000000U)

/* IRQ_STATUS_OABS */

#define CSL_USBTOP_IRQ_STATUS_OABS_IRQ_STATUS_OABS_MASK         (0xFFFFFFFFU)
#define CSL_USBTOP_IRQ_STATUS_OABS_IRQ_STATUS_OABS_SHIFT        (0U)
#define CSL_USBTOP_IRQ_STATUS_OABS_IRQ_STATUS_OABS_RESETVAL     (0x00000000U)
#define CSL_USBTOP_IRQ_STATUS_OABS_IRQ_STATUS_OABS_MAX          (0xffffffffU)

#define CSL_USBTOP_IRQ_STATUS_OABS_RESETVAL                     (0x00000000U)

/* IRQ_ENABLE_SET_OABS */

#define CSL_USBTOP_IRQ_ENABLE_SET_OABS_IRQ_ENABLE_SET_OABS_MASK  (0xFFFFFFFFU)
#define CSL_USBTOP_IRQ_ENABLE_SET_OABS_IRQ_ENABLE_SET_OABS_SHIFT  (0U)
#define CSL_USBTOP_IRQ_ENABLE_SET_OABS_IRQ_ENABLE_SET_OABS_RESETVAL  (0x00000000U)
#define CSL_USBTOP_IRQ_ENABLE_SET_OABS_IRQ_ENABLE_SET_OABS_MAX  (0xffffffffU)

#define CSL_USBTOP_IRQ_ENABLE_SET_OABS_RESETVAL                 (0x00000000U)

/* IRQ_ENABLE_CLR_OABS */

#define CSL_USBTOP_IRQ_ENABLE_CLR_OABS_IRQ_ENABLE_CLR_OABS_MASK  (0xFFFFFFFFU)
#define CSL_USBTOP_IRQ_ENABLE_CLR_OABS_IRQ_ENABLE_CLR_OABS_SHIFT  (0U)
#define CSL_USBTOP_IRQ_ENABLE_CLR_OABS_IRQ_ENABLE_CLR_OABS_RESETVAL  (0x00000000U)
#define CSL_USBTOP_IRQ_ENABLE_CLR_OABS_IRQ_ENABLE_CLR_OABS_MAX  (0xffffffffU)

#define CSL_USBTOP_IRQ_ENABLE_CLR_OABS_RESETVAL                 (0x00000000U)

/* TXFIFO_DEPTH */

#define CSL_USBTOP_TXFIFO_DEPTH_TXFIFO_DEPTH_MASK               (0xFFFFFFFFU)
#define CSL_USBTOP_TXFIFO_DEPTH_TXFIFO_DEPTH_SHIFT              (0U)
#define CSL_USBTOP_TXFIFO_DEPTH_TXFIFO_DEPTH_RESETVAL           (0x00000000U)
#define CSL_USBTOP_TXFIFO_DEPTH_TXFIFO_DEPTH_MAX                (0xffffffffU)

#define CSL_USBTOP_TXFIFO_DEPTH_RESETVAL                        (0x00000000U)

/* RXFIFO_DEPTH */

#define CSL_USBTOP_RXFIFO_DEPTH_RXFIFO_DEPTH_MASK               (0xFFFFFFFFU)
#define CSL_USBTOP_RXFIFO_DEPTH_RXFIFO_DEPTH_SHIFT              (0U)
#define CSL_USBTOP_RXFIFO_DEPTH_RXFIFO_DEPTH_RESETVAL           (0x00000000U)
#define CSL_USBTOP_RXFIFO_DEPTH_RXFIFO_DEPTH_MAX                (0xffffffffU)

#define CSL_USBTOP_RXFIFO_DEPTH_RESETVAL                        (0x00000000U)

/* SER_CONTROL */

#define CSL_USBTOP_SER_CONTROL_SER_CONTROL_MASK                 (0xFFFFFFFFU)
#define CSL_USBTOP_SER_CONTROL_SER_CONTROL_SHIFT                (0U)
#define CSL_USBTOP_SER_CONTROL_SER_CONTROL_RESETVAL             (0x00000000U)
#define CSL_USBTOP_SER_CONTROL_SER_CONTROL_MAX                  (0xffffffffU)

#define CSL_USBTOP_SER_CONTROL_RESETVAL                         (0x00000000U)

/* SER_STATUS */

#define CSL_USBTOP_SER_STATUS_SER_STATUS_MASK                   (0xFFFFFFFFU)
#define CSL_USBTOP_SER_STATUS_SER_STATUS_SHIFT                  (0U)
#define CSL_USBTOP_SER_STATUS_SER_STATUS_RESETVAL               (0x00000000U)
#define CSL_USBTOP_SER_STATUS_SER_STATUS_MAX                    (0xffffffffU)

#define CSL_USBTOP_SER_STATUS_RESETVAL                          (0x00000000U)

/* SER_ADDRESS */

#define CSL_USBTOP_SER_ADDRESS_SER_ADDRESS_MASK                 (0xFFFFFFFFU)
#define CSL_USBTOP_SER_ADDRESS_SER_ADDRESS_SHIFT                (0U)
#define CSL_USBTOP_SER_ADDRESS_SER_ADDRESS_RESETVAL             (0x00000000U)
#define CSL_USBTOP_SER_ADDRESS_SER_ADDRESS_MAX                  (0xffffffffU)

#define CSL_USBTOP_SER_ADDRESS_RESETVAL                         (0x00000000U)

/* PHY2CONFIG */

#define CSL_USBTOP_PHY2CONFIG_PHY2CONFIG_MASK                   (0xFFFFFFFFU)
#define CSL_USBTOP_PHY2CONFIG_PHY2CONFIG_SHIFT                  (0U)
#define CSL_USBTOP_PHY2CONFIG_PHY2CONFIG_RESETVAL               (0x00000000U)
#define CSL_USBTOP_PHY2CONFIG_PHY2CONFIG_MAX                    (0xffffffffU)

#define CSL_USBTOP_PHY2CONFIG_RESETVAL                          (0x00000000U)

/* PHY3CONFIG */

#define CSL_USBTOP_PHY3CONFIG_PHY2CONFIG_MASK                   (0xFFFFFFFFU)
#define CSL_USBTOP_PHY3CONFIG_PHY2CONFIG_SHIFT                  (0U)
#define CSL_USBTOP_PHY3CONFIG_PHY2CONFIG_RESETVAL               (0x00000000U)
#define CSL_USBTOP_PHY3CONFIG_PHY2CONFIG_MAX                    (0xffffffffU)

#define CSL_USBTOP_PHY3CONFIG_RESETVAL                          (0x00000000U)

/* HOST_CTRL */

#define CSL_USBTOP_HOST_CTRL_HOST_CTRL_MASK                     (0xFFFFFFFFU)
#define CSL_USBTOP_HOST_CTRL_HOST_CTRL_SHIFT                    (0U)
#define CSL_USBTOP_HOST_CTRL_HOST_CTRL_RESETVAL                 (0x00000000U)
#define CSL_USBTOP_HOST_CTRL_HOST_CTRL_MAX                      (0xffffffffU)

#define CSL_USBTOP_HOST_CTRL_RESETVAL                           (0x00000000U)

/* HOST_STATUS */

#define CSL_USBTOP_HOST_STATUS_HOST_STATUS_MASK                 (0xFFFFFFFFU)
#define CSL_USBTOP_HOST_STATUS_HOST_STATUS_SHIFT                (0U)
#define CSL_USBTOP_HOST_STATUS_HOST_STATUS_RESETVAL             (0x00000000U)
#define CSL_USBTOP_HOST_STATUS_HOST_STATUS_MAX                  (0xffffffffU)

#define CSL_USBTOP_HOST_STATUS_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
