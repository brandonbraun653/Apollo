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
#ifndef CSLR_CGEMSYSTEM_H
#define CSLR_CGEMSYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for TURING_FUNC_REG_BLOCK
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint32 HWINFO;
    volatile Uint32 SYSCONFIG;
    volatile Uint32 STAT;
    volatile Uint32 DISC_CONFIG;
    volatile Uint32 BUS_CONFIG;
    volatile Uint32 MMU_CONFIG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 IRQWAKEEN0;
    volatile Uint32 IRQWAKEEN1;
    volatile Uint8  RSVD1[8];
    volatile Uint32 DMAWAKEEN0;
    volatile Uint32 DMAWAKEEN1;
    volatile Uint8  RSVD2[8];
    volatile Uint32 EVTOUT_SET;
    volatile Uint32 EVTOUT_CLR;
    volatile Uint32 EVTOUT_PULSE;
    volatile Uint8  RSVD3[4];
    volatile Uint32 ERRINT_IRQSTATUS_RAW;
    volatile Uint32 ERRINT_IRQSTATUS;
    volatile Uint32 ERRINT_IRQENABLE_SET;
    volatile Uint32 ERRINT_IRQENABLE_CLR;
    volatile Uint32 EDMAWAKE0_IRQSTATUS_RAW;
    volatile Uint32 EDMAWAKE0_IRQSTATUS;
    volatile Uint32 EDMAWAKE0_IRQENABLE_SET;
    volatile Uint32 EDMAWAKE0_IRQENABLE_CLR;
    volatile Uint32 EDMAWAKE1_IRQSTATUS_RAW;
    volatile Uint32 EDMAWAKE1_IRQSTATUS;
    volatile Uint32 EDMAWAKE1_IRQENABLE_SET;
    volatile Uint32 EDMAWAKE1_IRQENABLE_CLR;
    volatile Uint8  RSVD4[96];
    volatile Uint32 SECURE_ENABLE0;
    volatile Uint32 SECURE_ENABLE1;
    volatile Uint8  RSVD5[16];
    volatile Uint32 HW_DBGOUT_SEL;
    volatile Uint32 HW_DBGOUT_VAL;
} CSL_CgemSystemRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* REVISION */
#define CSL_CGEMSYSTEM_REVISION                                 (0x0U)

/* HWINFO */
#define CSL_CGEMSYSTEM_HWINFO                                   (0x4U)

/* SYSCONFIG */
#define CSL_CGEMSYSTEM_SYSCONFIG                                (0x8U)

/* This register is intended to provide indication to software (including a 
 * remote host) as to whether the DSP is able to enter a low power mode. */
#define CSL_CGEMSYSTEM_STAT                                     (0xCU)

/* This register is used to manually disconnect the OCP busses. */
#define CSL_CGEMSYSTEM_DISC_CONFIG                              (0x10U)

/* This register controls the burst and priority settings for the internal 
 * initiators. */
#define CSL_CGEMSYSTEM_BUS_CONFIG                               (0x14U)

/* This register is used to enable the subsystem MMUs. */
#define CSL_CGEMSYSTEM_MMU_CONFIG                               (0x18U)

/* The register provides a global interrupt wakeup enable bit vector that 
 * defines which input interrupts are used to cause a wake from powerdown 
 * state (via the IDLE handshake). IRQWAKEEN0 is for interrupt inputs 63 thru 
 * 32, and IRQWAKEEN1 is for interrupt inputs 95 thru 64. Internal interrupts 
 * cannot cause a wake condition since in this state there is no guaranteed 
 * clock and all sub-modules should be in idle state. Software can write 1 to 
 * set and 0 to clear the corresponding bit (i.e., enable the corresponding 
 * interrupt for wakeup). Reads of this register return the actual state of 
 * the enable register. */
#define CSL_CGEMSYSTEM_IRQWAKEEN0                               (0x20U)

/* The register provides a global interrupt wakeup enable bit vector that 
 * defines which input interrupts are used to cause a wake from powerdown 
 * state (via the IDLE handshake). IRQWAKEEN0 is for interrupt inputs 63 thru 
 * 32, and IRQWAKEEN1 is for interrupt inputs 95 thru 64. Internal interrupts 
 * cannot cause a wake condition since in this state there is no guaranteed 
 * clock and all sub-modules should be in idle state. Software can write 1 to 
 * set and 0 to clear the corresponding bit (i.e., enable the corresponding 
 * interrupt for wakeup). Reads of this register return the actual state of 
 * the enable register. */
#define CSL_CGEMSYSTEM_IRQWAKEEN1                               (0x24U)

/* The register provides a global dma event wakeup enable bit vector that 
 * defines which input dma events are used to cause a wake from powerdown 
 * state (via the IDLE handshake). DMAWAKEEN0 is for dma event inputs 31 thru 
 * 0, and DMAWAKEEN1 is for dma event inputs 63 thru 32. Software can write 1 
 * to set and 0 to clear the corresponding bit (i.e., enable the corresponding 
 * dma event for wakeup). Reads of this register return the actual state of 
 * the enable register. */
#define CSL_CGEMSYSTEM_DMAWAKEEN0                               (0x30U)

/* The register provides a global dma event wakeup enable bit vector that 
 * defines which input dma events are used to cause a wake from powerdown 
 * state (via the IDLE handshake). DMAWAKEEN0 is for dma event inputs 31 thru 
 * 0, and DMAWAKEEN1 is for dma event inputs 63 thru 32. Software can write 1 
 * to set and 0 to clear the corresponding bit (i.e., enable the corresponding 
 * dma event for wakeup). Reads of this register return the actual state of 
 * the enable register. */
#define CSL_CGEMSYSTEM_DMAWAKEEN1                               (0x34U)

/* These registers can be used to drive event outputs from the Turing 
 * subsystem to a desired state. */
#define CSL_CGEMSYSTEM_EVTOUT_SET                               (0x40U)

/* These registers can be used to drive event outputs from the Turing 
 * subsystem to a desired state. */
#define CSL_CGEMSYSTEM_EVTOUT_CLR                               (0x44U)

/* These registers can be used to drive event outputs from the Turing 
 * subsystem to a desired state. */
#define CSL_CGEMSYSTEM_EVTOUT_PULSE                             (0x48U)

/* This register provides a per-event raw interrupt status vector */
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_RAW                     (0x50U)

/* This register provides a per-event enabled interrupt status vector. */
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS                         (0x54U)

/* This register provides a per-event interrupt enable bit vector. */
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_SET                     (0x58U)

/* This register provides a per-event interrupt enable bit vector. */
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_CLR                     (0x5CU)

/* This register provides a per-event raw interrupt status vector */
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_RAW                  (0x60U)

/* This register provides a per-event enabled interrupt status vector. */
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS                      (0x64U)

/* This register provides a per-event interrupt enable bit vector. */
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_SET                  (0x68U)

/* This register provides a per-event interrupt enable bit vector. */
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_CLR                  (0x6CU)

/* This register provides a per-event raw interrupt status vector */
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_RAW                  (0x70U)

/* This register provides a per-event enabled interrupt status vector. */
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS                      (0x74U)

/* This register provides a per-event interrupt enable bit vector. */
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_SET                  (0x78U)

/* This register provides a per-event interrupt enable bit vector. */
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_CLR                  (0x7CU)

/* This register is used on a secure device to selectively restrict access to 
 * the System Module registers to initiators with secure access indicator. */
#define CSL_CGEMSYSTEM_SECURE_ENABLE0                           (0xE0U)

/* This register is used on a secure device to selectively restrict access to 
 * the System Module registers to initiators with secure access indicator. */
#define CSL_CGEMSYSTEM_SECURE_ENABLE1                           (0xE4U)

/* THis register is used to select which group of internal signals are mapped 
 * to the hw_dbgout output bus. */
#define CSL_CGEMSYSTEM_HW_DBGOUT_SEL                            (0xF8U)

/* This register is used to read the value of the currently selected debug 
 * output group. */
#define CSL_CGEMSYSTEM_HW_DBGOUT_VAL                            (0xFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_CGEMSYSTEM_REVISION_MINOR_MASK                      (0x0000003FU)
#define CSL_CGEMSYSTEM_REVISION_MINOR_SHIFT                     (0U)
#define CSL_CGEMSYSTEM_REVISION_MINOR_RESETVAL                  (0x00000000U)
#define CSL_CGEMSYSTEM_REVISION_MINOR_MAX                       (0x0000003fU)

#define CSL_CGEMSYSTEM_REVISION_CUSTOM_MASK                     (0x000000C0U)
#define CSL_CGEMSYSTEM_REVISION_CUSTOM_SHIFT                    (6U)
#define CSL_CGEMSYSTEM_REVISION_CUSTOM_RESETVAL                 (0x00000000U)
#define CSL_CGEMSYSTEM_REVISION_CUSTOM_MAX                      (0x00000003U)

#define CSL_CGEMSYSTEM_REVISION_MAJOR_MASK                      (0x00000700U)
#define CSL_CGEMSYSTEM_REVISION_MAJOR_SHIFT                     (8U)
#define CSL_CGEMSYSTEM_REVISION_MAJOR_RESETVAL                  (0x00000001U)
#define CSL_CGEMSYSTEM_REVISION_MAJOR_MAX                       (0x00000007U)

#define CSL_CGEMSYSTEM_REVISION_RTL_MASK                        (0x0000F800U)
#define CSL_CGEMSYSTEM_REVISION_RTL_SHIFT                       (11U)
#define CSL_CGEMSYSTEM_REVISION_RTL_RESETVAL                    (0x00000000U)
#define CSL_CGEMSYSTEM_REVISION_RTL_MAX                         (0x0000001fU)

#define CSL_CGEMSYSTEM_REVISION_FUNC_MASK                       (0x0FFF0000U)
#define CSL_CGEMSYSTEM_REVISION_FUNC_SHIFT                      (16U)
#define CSL_CGEMSYSTEM_REVISION_FUNC_RESETVAL                   (0x00000f90U)
#define CSL_CGEMSYSTEM_REVISION_FUNC_MAX                        (0x00000fffU)

#define CSL_CGEMSYSTEM_REVISION_SCHEME_MASK                     (0xC0000000U)
#define CSL_CGEMSYSTEM_REVISION_SCHEME_SHIFT                    (30U)
#define CSL_CGEMSYSTEM_REVISION_SCHEME_RESETVAL                 (0x00000001U)
#define CSL_CGEMSYSTEM_REVISION_SCHEME_MAX                      (0x00000003U)

#define CSL_CGEMSYSTEM_REVISION_RESETVAL                        (0x4f900100U)

/* HWINFO */

#define CSL_CGEMSYSTEM_HWINFO_NUM_MASK                          (0x0000000FU)
#define CSL_CGEMSYSTEM_HWINFO_NUM_SHIFT                         (0U)
#define CSL_CGEMSYSTEM_HWINFO_NUM_RESETVAL                      (0x00000000U)
#define CSL_CGEMSYSTEM_HWINFO_NUM_MAX                           (0x0000000fU)

#define CSL_CGEMSYSTEM_HWINFO_INFO_MASK                         (0xFFFFFFF0U)
#define CSL_CGEMSYSTEM_HWINFO_INFO_SHIFT                        (4U)
#define CSL_CGEMSYSTEM_HWINFO_INFO_RESETVAL                     (0x00000000U)
#define CSL_CGEMSYSTEM_HWINFO_INFO_MAX                          (0x0fffffffU)

#define CSL_CGEMSYSTEM_HWINFO_RESETVAL                          (0x00000000U)

/* SYSCONFIG */

#define CSL_CGEMSYSTEM_SYSCONFIG_SOFTRESET_MASK                 (0x00000001U)
#define CSL_CGEMSYSTEM_SYSCONFIG_SOFTRESET_SHIFT                (0U)
#define CSL_CGEMSYSTEM_SYSCONFIG_SOFTRESET_RESETVAL             (0x00000000U)
#define CSL_CGEMSYSTEM_SYSCONFIG_SOFTRESET_MAX                  (0x00000001U)

#define CSL_CGEMSYSTEM_SYSCONFIG_FREE_EMU_MASK                  (0x00000002U)
#define CSL_CGEMSYSTEM_SYSCONFIG_FREE_EMU_SHIFT                 (1U)
#define CSL_CGEMSYSTEM_SYSCONFIG_FREE_EMU_RESETVAL              (0x00000000U)
#define CSL_CGEMSYSTEM_SYSCONFIG_FREE_EMU_MAX                   (0x00000001U)

#define CSL_CGEMSYSTEM_SYSCONFIG_IDLEMODE_MASK                  (0x0000000CU)
#define CSL_CGEMSYSTEM_SYSCONFIG_IDLEMODE_SHIFT                 (2U)
#define CSL_CGEMSYSTEM_SYSCONFIG_IDLEMODE_RESETVAL              (0x00000002U)
#define CSL_CGEMSYSTEM_SYSCONFIG_IDLEMODE_SMARTIDLEWKUP         (0x00000003U)
#define CSL_CGEMSYSTEM_SYSCONFIG_IDLEMODE_FORCE_IDLE            (0x00000000U)
#define CSL_CGEMSYSTEM_SYSCONFIG_IDLEMODE_NO_IDLE               (0x00000001U)
#define CSL_CGEMSYSTEM_SYSCONFIG_IDLEMODE_SMART_IDLE            (0x00000002U)

#define CSL_CGEMSYSTEM_SYSCONFIG_STANDBYMODE_MASK               (0x00000030U)
#define CSL_CGEMSYSTEM_SYSCONFIG_STANDBYMODE_SHIFT              (4U)
#define CSL_CGEMSYSTEM_SYSCONFIG_STANDBYMODE_RESETVAL           (0x00000002U)
#define CSL_CGEMSYSTEM_SYSCONFIG_STANDBYMODE_SMART_STANDBY_WKUP  (0x00000003U)
#define CSL_CGEMSYSTEM_SYSCONFIG_STANDBYMODE_SMART_STAND_BY     (0x00000002U)
#define CSL_CGEMSYSTEM_SYSCONFIG_STANDBYMODE_FORCE_STANDBY      (0x00000000U)
#define CSL_CGEMSYSTEM_SYSCONFIG_STANDBYMODE_NO_STANDBY         (0x00000001U)

#define CSL_CGEMSYSTEM_SYSCONFIG_DSP_IDLEREQ_MASK               (0x00000100U)
#define CSL_CGEMSYSTEM_SYSCONFIG_DSP_IDLEREQ_SHIFT              (8U)
#define CSL_CGEMSYSTEM_SYSCONFIG_DSP_IDLEREQ_RESETVAL           (0x00000000U)
#define CSL_CGEMSYSTEM_SYSCONFIG_DSP_IDLEREQ_NOREQ              (0x00000000U)
#define CSL_CGEMSYSTEM_SYSCONFIG_DSP_IDLEREQ_IDLEREQ            (0x00000001U)

#define CSL_CGEMSYSTEM_SYSCONFIG_RESETVAL                       (0x000000a8U)

/* STAT */

#define CSL_CGEMSYSTEM_STAT_C66X_STAT_MASK                      (0x00000001U)
#define CSL_CGEMSYSTEM_STAT_C66X_STAT_SHIFT                     (0U)
#define CSL_CGEMSYSTEM_STAT_C66X_STAT_RESETVAL                  (0x00000001U)
#define CSL_CGEMSYSTEM_STAT_C66X_STAT_IDLE                      (0x00000000U)
#define CSL_CGEMSYSTEM_STAT_C66X_STAT_ACTIVE                    (0x00000001U)

#define CSL_CGEMSYSTEM_STAT_TC0_STAT_MASK                       (0x00000002U)
#define CSL_CGEMSYSTEM_STAT_TC0_STAT_SHIFT                      (1U)
#define CSL_CGEMSYSTEM_STAT_TC0_STAT_RESETVAL                   (0x00000001U)
#define CSL_CGEMSYSTEM_STAT_TC0_STAT_IDLE                       (0x00000000U)
#define CSL_CGEMSYSTEM_STAT_TC0_STAT_ACTIVE                     (0x00000001U)

#define CSL_CGEMSYSTEM_STAT_TC1_STAT_MASK                       (0x00000004U)
#define CSL_CGEMSYSTEM_STAT_TC1_STAT_SHIFT                      (2U)
#define CSL_CGEMSYSTEM_STAT_TC1_STAT_RESETVAL                   (0x00000001U)
#define CSL_CGEMSYSTEM_STAT_TC1_STAT_IDLE                       (0x00000000U)
#define CSL_CGEMSYSTEM_STAT_TC1_STAT_ACTIVE                     (0x00000001U)

#define CSL_CGEMSYSTEM_STAT_OCPI_DISC_STAT_MASK                 (0x00000030U)
#define CSL_CGEMSYSTEM_STAT_OCPI_DISC_STAT_SHIFT                (4U)
#define CSL_CGEMSYSTEM_STAT_OCPI_DISC_STAT_RESETVAL             (0x00000002U)
#define CSL_CGEMSYSTEM_STAT_OCPI_DISC_STAT_OCP_INITIATOR_DISCONNECT  (0x00000000U)
#define CSL_CGEMSYSTEM_STAT_OCPI_DISC_STAT_OCP_TRYING_TO_DISCONNECT  (0x00000001U)
#define CSL_CGEMSYSTEM_STAT_OCPI_DISC_STAT_OCP_INITIATOR_ACTIVE  (0x00000002U)

#define CSL_CGEMSYSTEM_STAT_RESETVAL                            (0x00000027U)

/* DISC_CONFIG */

#define CSL_CGEMSYSTEM_DISC_CONFIG_OCPI_DISC_MASK               (0x00000001U)
#define CSL_CGEMSYSTEM_DISC_CONFIG_OCPI_DISC_SHIFT              (0U)
#define CSL_CGEMSYSTEM_DISC_CONFIG_OCPI_DISC_RESETVAL           (0x00000000U)
#define CSL_CGEMSYSTEM_DISC_CONFIG_OCPI_DISC_WRITE0             (0x00000000U)
#define CSL_CGEMSYSTEM_DISC_CONFIG_OCPI_DISC_WRITE1             (0x00000001U)
#define CSL_CGEMSYSTEM_DISC_CONFIG_OCPI_DISC_READ0              (0x00000000U)
#define CSL_CGEMSYSTEM_DISC_CONFIG_OCPI_DISC_READ1              (0x00000001U)

#define CSL_CGEMSYSTEM_DISC_CONFIG_RESETVAL                     (0x00000000U)

/* BUS_CONFIG */

#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_DBS_MASK                  (0x00000003U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_DBS_SHIFT                 (0U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_DBS_RESETVAL              (0x00000003U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_DBS_BYTE_16               (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_DBS_BYTE_32               (0x00000001U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_DBS_BYTE_64               (0x00000002U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_DBS_BYTE_128              (0x00000003U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_DBS_MASK                  (0x00000030U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_DBS_SHIFT                 (4U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_DBS_RESETVAL              (0x00000003U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_DBS_BYTE_16               (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_DBS_BYTE_32               (0x00000001U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_DBS_BYTE_64               (0x00000002U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_DBS_BYTE_128              (0x00000003U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_L2PRES_MASK               (0x00000300U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_L2PRES_SHIFT              (8U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_L2PRES_RESETVAL           (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_L2PRES_LOW                (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_L2PRES_MED                (0x00000001U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC0_L2PRES_HIGH               (0x00000003U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_L2PRES_MASK               (0x00003000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_L2PRES_SHIFT              (12U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_L2PRES_RESETVAL           (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_L2PRES_LOW                (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_L2PRES_MED                (0x00000001U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_TC1_L2PRES_HIGH               (0x00000003U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_CFG_L2PRES_MASK               (0x00030000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_CFG_L2PRES_SHIFT              (16U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_CFG_L2PRES_RESETVAL           (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_CFG_L2PRES_LOW                (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_CFG_L2PRES_MED                (0x00000001U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_CFG_L2PRES_HIGH               (0x00000003U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_L2PRES_MASK              (0x00300000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_L2PRES_SHIFT             (20U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_L2PRES_RESETVAL          (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_L2PRES_LOW               (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_L2PRES_MED               (0x00000001U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_L2PRES_HIGH              (0x00000003U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_NOPOSTOVERRIDE_MASK           (0x01000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_NOPOSTOVERRIDE_SHIFT          (24U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_NOPOSTOVERRIDE_RESETVAL       (0x00000001U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_NOPOSTOVERRIDE_MIX            (0x00000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_NOPOSTOVERRIDE_NOPOST         (0x00000001U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_PRI_MASK                 (0x70000000U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_PRI_SHIFT                (28U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_PRI_RESETVAL             (0x00000004U)
#define CSL_CGEMSYSTEM_BUS_CONFIG_SDMA_PRI_MAX                  (0x00000007U)

#define CSL_CGEMSYSTEM_BUS_CONFIG_RESETVAL                      (0x41000033U)

/* MMU_CONFIG */

#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_EN_MASK                  (0x00000001U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_EN_SHIFT                 (0U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_EN_RESETVAL              (0x00000001U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_EN_DISABLED              (0x00000000U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_EN_ENABLED               (0x00000001U)

#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_EN_MASK                  (0x00000010U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_EN_SHIFT                 (4U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_EN_RESETVAL              (0x00000001U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_EN_DISABLED              (0x00000000U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_EN_ENABLED               (0x00000001U)

#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_ABORT_MASK               (0x00000100U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_ABORT_SHIFT              (8U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_ABORT_RESETVAL           (0x00000000U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_ABORT_NOABORT            (0x00000000U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU0_ABORT_ABORT              (0x00000001U)

#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_ABORT_MASK               (0x00001000U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_ABORT_SHIFT              (12U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_ABORT_RESETVAL           (0x00000000U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_ABORT_NOABORT            (0x00000000U)
#define CSL_CGEMSYSTEM_MMU_CONFIG_MMU1_ABORT_ABORT              (0x00000001U)

#define CSL_CGEMSYSTEM_MMU_CONFIG_RESETVAL                      (0x00000011U)

/* IRQWAKEEN0 */

#define CSL_CGEMSYSTEM_IRQWAKEEN0_ENABLE_MASK                   (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_IRQWAKEEN0_ENABLE_SHIFT                  (0U)
#define CSL_CGEMSYSTEM_IRQWAKEEN0_ENABLE_RESETVAL               (0x00000000U)
#define CSL_CGEMSYSTEM_IRQWAKEEN0_ENABLE_MAX                    (0xffffffffU)

#define CSL_CGEMSYSTEM_IRQWAKEEN0_RESETVAL                      (0x00000000U)

/* IRQWAKEEN1 */

#define CSL_CGEMSYSTEM_IRQWAKEEN1_ENABLE_MASK                   (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_IRQWAKEEN1_ENABLE_SHIFT                  (0U)
#define CSL_CGEMSYSTEM_IRQWAKEEN1_ENABLE_RESETVAL               (0x00000000U)
#define CSL_CGEMSYSTEM_IRQWAKEEN1_ENABLE_MAX                    (0xffffffffU)

#define CSL_CGEMSYSTEM_IRQWAKEEN1_RESETVAL                      (0x00000000U)

/* DMAWAKEEN0 */

#define CSL_CGEMSYSTEM_DMAWAKEEN0_ENABLE_MASK                   (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_DMAWAKEEN0_ENABLE_SHIFT                  (0U)
#define CSL_CGEMSYSTEM_DMAWAKEEN0_ENABLE_RESETVAL               (0x00000000U)
#define CSL_CGEMSYSTEM_DMAWAKEEN0_ENABLE_MAX                    (0xffffffffU)

#define CSL_CGEMSYSTEM_DMAWAKEEN0_RESETVAL                      (0x00000000U)

/* DMAWAKEEN1 */

#define CSL_CGEMSYSTEM_DMAWAKEEN1_ENABLE_MASK                   (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_DMAWAKEEN1_ENABLE_SHIFT                  (0U)
#define CSL_CGEMSYSTEM_DMAWAKEEN1_ENABLE_RESETVAL               (0x00000000U)
#define CSL_CGEMSYSTEM_DMAWAKEEN1_ENABLE_MAX                    (0xffffffffU)

#define CSL_CGEMSYSTEM_DMAWAKEEN1_RESETVAL                      (0x00000000U)

/* EVTOUT_SET */

#define CSL_CGEMSYSTEM_EVTOUT_SET_EVENT_MASK                    (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EVTOUT_SET_EVENT_SHIFT                   (0U)
#define CSL_CGEMSYSTEM_EVTOUT_SET_EVENT_RESETVAL                (0x00000000U)
#define CSL_CGEMSYSTEM_EVTOUT_SET_EVENT_MAX                     (0xffffffffU)

#define CSL_CGEMSYSTEM_EVTOUT_SET_RESETVAL                      (0x00000000U)

/* EVTOUT_CLR */

#define CSL_CGEMSYSTEM_EVTOUT_CLR_EVENT_MASK                    (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EVTOUT_CLR_EVENT_SHIFT                   (0U)
#define CSL_CGEMSYSTEM_EVTOUT_CLR_EVENT_RESETVAL                (0x00000000U)
#define CSL_CGEMSYSTEM_EVTOUT_CLR_EVENT_MAX                     (0xffffffffU)

#define CSL_CGEMSYSTEM_EVTOUT_CLR_RESETVAL                      (0x00000000U)

/* EVTOUT_PULSE */

#define CSL_CGEMSYSTEM_EVTOUT_PULSE_EVENT_MASK                  (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EVTOUT_PULSE_EVENT_SHIFT                 (0U)
#define CSL_CGEMSYSTEM_EVTOUT_PULSE_EVENT_RESETVAL              (0x00000000U)
#define CSL_CGEMSYSTEM_EVTOUT_PULSE_EVENT_MAX                   (0xffffffffU)

#define CSL_CGEMSYSTEM_EVTOUT_PULSE_RESETVAL                    (0x00000000U)

/* ERRINT_IRQSTATUS_RAW */

#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_RAW_EVENT_MASK          (0x007FFFFFU)
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_RAW_EVENT_SHIFT         (0U)
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_RAW_EVENT_RESETVAL      (0x00000000U)
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_RAW_EVENT_MAX           (0x007fffffU)

#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_RAW_RESETVAL            (0x00000000U)

/* ERRINT_IRQSTATUS */

#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_EVENT_MASK              (0x007FFFFFU)
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_EVENT_SHIFT             (0U)
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_EVENT_RESETVAL          (0x00000000U)
#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_EVENT_MAX               (0x007fffffU)

#define CSL_CGEMSYSTEM_ERRINT_IRQSTATUS_RESETVAL                (0x00000000U)

/* ERRINT_IRQENABLE_SET */

#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_SET_ENABLE_MASK         (0x007FFFFFU)
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_SET_ENABLE_SHIFT        (0U)
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_SET_ENABLE_RESETVAL     (0x00000000U)
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_SET_ENABLE_MAX          (0x007fffffU)

#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_SET_RESETVAL            (0x00000000U)

/* ERRINT_IRQENABLE_CLR */

#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_CLR_ENABLE_MASK         (0x007FFFFFU)
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_CLR_ENABLE_SHIFT        (0U)
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_CLR_ENABLE_RESETVAL     (0x00000000U)
#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_CLR_ENABLE_MAX          (0x007fffffU)

#define CSL_CGEMSYSTEM_ERRINT_IRQENABLE_CLR_RESETVAL            (0x00000000U)

/* EDMAWAKE0_IRQSTATUS_RAW */

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_RAW_EVENT_MASK       (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_RAW_EVENT_SHIFT      (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_RAW_EVENT_RESETVAL   (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_RAW_EVENT_MAX        (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_RAW_RESETVAL         (0x00000000U)

/* EDMAWAKE0_IRQSTATUS */

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_EVENT_MASK           (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_EVENT_SHIFT          (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_EVENT_RESETVAL       (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_EVENT_MAX            (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQSTATUS_RESETVAL             (0x00000000U)

/* EDMAWAKE0_IRQENABLE_SET */

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_SET_ENABLE_MASK      (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_SET_ENABLE_SHIFT     (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_SET_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_SET_ENABLE_MAX       (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_SET_RESETVAL         (0x00000000U)

/* EDMAWAKE0_IRQENABLE_CLR */

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_CLR_ENABLE_MASK      (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_CLR_ENABLE_SHIFT     (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_CLR_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_CLR_ENABLE_MAX       (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE0_IRQENABLE_CLR_RESETVAL         (0x00000000U)

/* EDMAWAKE1_IRQSTATUS_RAW */

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_RAW_EVENT_MASK       (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_RAW_EVENT_SHIFT      (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_RAW_EVENT_RESETVAL   (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_RAW_EVENT_MAX        (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_RAW_RESETVAL         (0x00000000U)

/* EDMAWAKE1_IRQSTATUS */

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_EVENT_MASK           (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_EVENT_SHIFT          (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_EVENT_RESETVAL       (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_EVENT_MAX            (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQSTATUS_RESETVAL             (0x00000000U)

/* EDMAWAKE1_IRQENABLE_SET */

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_SET_ENABLE_MASK      (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_SET_ENABLE_SHIFT     (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_SET_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_SET_ENABLE_MAX       (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_SET_RESETVAL         (0x00000000U)

/* EDMAWAKE1_IRQENABLE_CLR */

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_CLR_ENABLE_MASK      (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_CLR_ENABLE_SHIFT     (0U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_CLR_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_CLR_ENABLE_MAX       (0xffffffffU)

#define CSL_CGEMSYSTEM_EDMAWAKE1_IRQENABLE_CLR_RESETVAL         (0x00000000U)

/* SECURE_ENABLE0 */

#define CSL_CGEMSYSTEM_SECURE_ENABLE0_ENABLE_MASK               (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_SECURE_ENABLE0_ENABLE_SHIFT              (0U)
#define CSL_CGEMSYSTEM_SECURE_ENABLE0_ENABLE_RESETVAL           (0xffffffffU)
#define CSL_CGEMSYSTEM_SECURE_ENABLE0_ENABLE_MAX                (0xffffffffU)

#define CSL_CGEMSYSTEM_SECURE_ENABLE0_RESETVAL                  (0xffffffffU)

/* SECURE_ENABLE1 */

#define CSL_CGEMSYSTEM_SECURE_ENABLE1_ENABLE_MASK               (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_SECURE_ENABLE1_ENABLE_SHIFT              (0U)
#define CSL_CGEMSYSTEM_SECURE_ENABLE1_ENABLE_RESETVAL           (0xffffffffU)
#define CSL_CGEMSYSTEM_SECURE_ENABLE1_ENABLE_MAX                (0xffffffffU)

#define CSL_CGEMSYSTEM_SECURE_ENABLE1_RESETVAL                  (0xffffffffU)

/* HW_DBGOUT_SEL */

#define CSL_CGEMSYSTEM_HW_DBGOUT_SEL_GROUP_MASK                 (0x0000000FU)
#define CSL_CGEMSYSTEM_HW_DBGOUT_SEL_GROUP_SHIFT                (0U)
#define CSL_CGEMSYSTEM_HW_DBGOUT_SEL_GROUP_RESETVAL             (0x00000000U)
#define CSL_CGEMSYSTEM_HW_DBGOUT_SEL_GROUP_MAX                  (0x0000000fU)

#define CSL_CGEMSYSTEM_HW_DBGOUT_SEL_RESETVAL                   (0x00000000U)

/* HW_DBGOUT_VAL */

#define CSL_CGEMSYSTEM_HW_DBGOUT_VAL_VALUE_MASK                 (0xFFFFFFFFU)
#define CSL_CGEMSYSTEM_HW_DBGOUT_VAL_VALUE_SHIFT                (0U)
#define CSL_CGEMSYSTEM_HW_DBGOUT_VAL_VALUE_RESETVAL             (0x00000000U)
#define CSL_CGEMSYSTEM_HW_DBGOUT_VAL_VALUE_MAX                  (0xffffffffU)

#define CSL_CGEMSYSTEM_HW_DBGOUT_VAL_RESETVAL                   (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
