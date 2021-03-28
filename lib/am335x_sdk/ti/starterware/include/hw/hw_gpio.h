/*
* hw_gpio.h
*
* Register-level header file for GPIO
*
* Copyright (C) 2013 - 2019 Texas Instruments Incorporated - http://www.ti.com/
*
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

#ifndef HW_GPIO_H_
#define HW_GPIO_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define GPIO_REVISION                                               (0x0U)
#define GPIO_SYSCONFIG                                              (0x10U)
#define GPIO_EOI                                                    (0x20U)
#define GPIO_IRQSTS_RAW(n)                                          (0x24U + ((n) * 0x4U))
#define GPIO_IRQSTS(n)                                              (0x2cU + ((n) * 0x4U))
#define GPIO_IRQSTS_SET(n)                                          (0x34U + ((n) * 0x4U))
#define GPIO_IRQSTS_CLR(n)                                          (0x3cU + ((n) * 0x4U))
#define GPIO_IRQWAKEN(n)                                            (0x44U + ((n) * 0x4U))
#define GPIO_SYSSTS                                                 (0x114U)
#define GPIO_IRQSTS1                                                (0x118U)
#define GPIO_IRQEN1                                                 (0x11cU)
#define GPIO_WAKEUPEN                                               (0x120U)
#define GPIO_IRQSTS2                                                (0x128U)
#define GPIO_IRQEN2                                                 (0x12cU)
#define GPIO_CTRL                                                   (0x130U)
#define GPIO_OE                                                     (0x134U)
#define GPIO_DATAIN                                                 (0x138U)
#define GPIO_DATAOUT                                                (0x13cU)
#define GPIO_LEVELDETECT(n)                                         (0x140U + ((n) * 0x4U))
#define GPIO_RISINGDETECT                                           (0x148U)
#define GPIO_FALLINGDETECT                                          (0x14cU)
#define GPIO_DEBOUNCEN                                              (0x150U)
#define GPIO_DEBOUNCINGTIME                                         (0x154U)
#define GPIO_CLRIRQEN1                                              (0x160U)
#define GPIO_SETIRQEN1                                              (0x164U)
#define GPIO_CLRIRQEN2                                              (0x170U)
#define GPIO_SETIRQEN2                                              (0x174U)
#define GPIO_CLRWKUPENA                                             (0x180U)
#define GPIO_SETWKUENA                                              (0x184U)
#define GPIO_CLRDATAOUT                                             (0x190U)
#define GPIO_SETDATAOUT                                             (0x194U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define GPIO_REVISION_MINOR_SHIFT                                                       (0U)
#define GPIO_REVISION_MINOR_MASK                                                        (0x0000003fU)

#define GPIO_REVISION_CUSTOM_SHIFT                                                      (6U)
#define GPIO_REVISION_CUSTOM_MASK                                                       (0x000000c0U)

#define GPIO_REVISION_MAJOR_SHIFT                                                       (8U)
#define GPIO_REVISION_MAJOR_MASK                                                        (0x00000700U)

#define GPIO_REVISION_RTL_SHIFT                                                         (11U)
#define GPIO_REVISION_RTL_MASK                                                          (0x0000f800U)

#define GPIO_REVISION_FUNC_SHIFT                                                        (16U)
#define GPIO_REVISION_FUNC_MASK                                                         (0x0fff0000U)

#define GPIO_REVISION_SCHEME_SHIFT                                                      (30U)
#define GPIO_REVISION_SCHEME_MASK                                                       (0xc0000000U)

#define GPIO_SYSCONFIG_AUTOIDLE_SHIFT                                                   (0U)
#define GPIO_SYSCONFIG_AUTOIDLE_MASK                                                    (0x00000001U)
#define GPIO_SYSCONFIG_AUTOIDLE_FREERUN                                                  (0U)
#define GPIO_SYSCONFIG_AUTOIDLE_AUTOMATIC                                                (1U)

#define GPIO_SYSCONFIG_SOFTRESET_SHIFT                                                  (1U)
#define GPIO_SYSCONFIG_SOFTRESET_MASK                                                   (0x00000002U)
#define GPIO_SYSCONFIG_SOFTRESET_NORMAL                                                  (0U)
#define GPIO_SYSCONFIG_SOFTRESET_RESET                                                   (1U)

#define GPIO_SYSCONFIG_ENAWAKEUP_SHIFT                                                  (2U)
#define GPIO_SYSCONFIG_ENAWAKEUP_MASK                                                   (0x00000004U)
#define GPIO_SYSCONFIG_ENAWAKEUP_DISABLE                                                 (0U)
#define GPIO_SYSCONFIG_ENAWAKEUP_ENABLE                                                  (1U)

#define GPIO_SYSCONFIG_IDLEMODE_SHIFT                                                   (3U)
#define GPIO_SYSCONFIG_IDLEMODE_MASK                                                    (0x00000018U)
#define GPIO_SYSCONFIG_IDLEMODE_FORCEIDLE                                                (0U)
#define GPIO_SYSCONFIG_IDLEMODE_NOIDLE                                                   (1U)
#define GPIO_SYSCONFIG_IDLEMODE_SMARTIDLE                                                (2U)
#define GPIO_SYSCONFIG_IDLEMODE_SMARTIDLEWAKEUP                                          (3U)

#define GPIO_EOI_DMAEVT_ACK_SHIFT                                                       (0U)
#define GPIO_EOI_DMAEVT_ACK_MASK                                                        (0x00000001U)
#define GPIO_EOI_DMAEVT_ACK_0                                                            (0U)
#define GPIO_EOI_DMAEVT_ACK_1                                                            (1U)

#define GPIO_IRQSTS_RAW_INTLINE_N_SHIFT                                                 (0U)
#define GPIO_IRQSTS_RAW_INTLINE_N_MASK                                                  (0xffffffffU)
#define GPIO_IRQSTS_RAW_INTLINE_N_NOEFFECT                                               (0U)
#define GPIO_IRQSTS_RAW_INTLINE_N_IRQTRIGGER                                             (1U)

#define GPIO_IRQSTS_INTLINE_N_SHIFT                                                     (0U)
#define GPIO_IRQSTS_INTLINE_N_MASK                                                      (0xffffffffU)
#define GPIO_IRQSTS_INTLINE_N_WRITE0                                                     (0U)
#define GPIO_IRQSTS_INTLINE_N_WRITE1                                                     (1U)
#define GPIO_IRQSTS_INTLINE_N_READ1                                                      (1U)
#define GPIO_IRQSTS_INTLINE_N_READ0                                                      (0U)

#define GPIO_IRQSTS_SET_INTLINE_N_SHIFT                                                 (0U)
#define GPIO_IRQSTS_SET_INTLINE_N_MASK                                                  (0xffffffffU)

#define GPIO_IRQSTS_CLR_INTLINE_N_SHIFT                                                 (0U)
#define GPIO_IRQSTS_CLR_INTLINE_N_MASK                                                  (0xffffffffU)

#define GPIO_IRQWAKEN_INTLINE_SHIFT                                                     (0U)
#define GPIO_IRQWAKEN_INTLINE_MASK                                                      (0xffffffffU)

#define GPIO_SYSSTS_RESETDONE_SHIFT                                                     (0U)
#define GPIO_SYSSTS_RESETDONE_MASK                                                      (0x00000001U)
#define GPIO_SYSSTS_RESETDONE_INPROGRESS                                                 (0U)
#define GPIO_SYSSTS_RESETDONE_COMPLETE                                                   (1U)

#define GPIO_IRQSTS1_INTLINE_SHIFT                                                      (0U)
#define GPIO_IRQSTS1_INTLINE_MASK                                                       (0xffffffffU)
#define GPIO_IRQSTS1_INTLINE_NOTSET                                                      (0U)
#define GPIO_IRQSTS1_INTLINE_SET                                                         (1U)

#define GPIO_IRQEN1_INTLINE_SHIFT                                                       (0U)
#define GPIO_IRQEN1_INTLINE_MASK                                                        (0xffffffffU)
#define GPIO_IRQEN1_INTLINE_DISABLED                                                     (0U)
#define GPIO_IRQEN1_INTLINE_ENABLED                                                      (1U)

#define GPIO_WAKEUPEN_INTLINE_SHIFT                                                     (0U)
#define GPIO_WAKEUPEN_INTLINE_MASK                                                      (0xffffffffU)
#define GPIO_WAKEUPEN_INTLINE_DISABLED                                                   (0U)
#define GPIO_WAKEUPEN_INTLINE_ENABLED                                                    (1U)

#define GPIO_IRQSTS2_INTLINE_SHIFT                                                      (0U)
#define GPIO_IRQSTS2_INTLINE_MASK                                                       (0xffffffffU)
#define GPIO_IRQSTS2_INTLINE_NOTSET                                                      (0U)
#define GPIO_IRQSTS2_INTLINE_SET                                                         (1U)

#define GPIO_IRQEN2_INTLINE_SHIFT                                                       (0U)
#define GPIO_IRQEN2_INTLINE_MASK                                                        (0xffffffffU)
#define GPIO_IRQEN2_INTLINE_DISABLED                                                     (0U)
#define GPIO_IRQEN2_INTLINE_ENABLED                                                      (1U)

#define GPIO_CTRL_DISABLEMODULE_SHIFT                                                   (0U)
#define GPIO_CTRL_DISABLEMODULE_MASK                                                    (0x00000001U)
#define GPIO_CTRL_DISABLEMODULE_ENABLED                                                  (0U)
#define GPIO_CTRL_DISABLEMODULE_DISABLED                                                 (1U)

#define GPIO_CTRL_GATINGRATIO_SHIFT                                                     (1U)
#define GPIO_CTRL_GATINGRATIO_MASK                                                      (0x00000006U)
#define GPIO_CTRL_GATINGRATIO_N_1                                                        (0U)
#define GPIO_CTRL_GATINGRATIO_N_2                                                        (1U)
#define GPIO_CTRL_GATINGRATIO_N_4                                                        (2U)
#define GPIO_CTRL_GATINGRATIO_N_8                                                        (3U)

#define GPIO_OE_OUTPUTEN_N_SHIFT                                                        (0U)
#define GPIO_OE_OUTPUTEN_N_MASK                                                         (0xffffffffU)
#define GPIO_OE_OUTPUTEN_N_ENABLED                                                       (0U)
#define GPIO_OE_OUTPUTEN_N_DISABLED                                                      (1U)

#define GPIO_DATAIN_SHIFT                                                               (0U)
#define GPIO_DATAIN_MASK                                                                (0xffffffffU)

#define GPIO_DATAOUT_SHIFT                                                              (0U)
#define GPIO_DATAOUT_MASK                                                               (0xffffffffU)

#define GPIO_LEVELDETECT_N_SHIFT                                                        (0U)
#define GPIO_LEVELDETECT_N_MASK                                                         (0xffffffffU)

#define GPIO_RISINGDETECT_N_SHIFT                                                       (0U)
#define GPIO_RISINGDETECT_N_MASK                                                        (0xffffffffU)

#define GPIO_FALLINGDETECT_N_SHIFT                                                      (0U)
#define GPIO_FALLINGDETECT_N_MASK                                                       (0xffffffffU)

#define GPIO_DEBOUNCEN_DEBOUNCEEN_N_SHIFT                                               (0U)
#define GPIO_DEBOUNCEN_DEBOUNCEEN_N_MASK                                                (0xffffffffU)
#define GPIO_DEBOUNCEN_DEBOUNCEEN_N_NODEBOUNCE                                           (0U)
#define GPIO_DEBOUNCEN_DEBOUNCEEN_N_DEBOUNCE                                             (1U)

#define GPIO_DEBOUNCINGTIME_DEBOUNCETIME_SHIFT                                          (0U)
#define GPIO_DEBOUNCINGTIME_DEBOUNCETIME_MASK                                           (0x000000ffU)

#define GPIO_CLRIRQEN1_INTLINE_SHIFT                                                    (0U)
#define GPIO_CLRIRQEN1_INTLINE_MASK                                                     (0xffffffffU)
#define GPIO_CLRIRQEN1_INTLINE_NOEFFECT                                                  (0U)
#define GPIO_CLRIRQEN1_INTLINE_CLEAR                                                     (1U)

#define GPIO_SETIRQEN1_INTLINE_SHIFT                                                    (0U)
#define GPIO_SETIRQEN1_INTLINE_MASK                                                     (0xffffffffU)
#define GPIO_SETIRQEN1_INTLINE_NOEFFECT                                                  (0U)
#define GPIO_SETIRQEN1_INTLINE_SET                                                       (1U)

#define GPIO_CLRIRQEN2_INTLINE_SHIFT                                                    (0U)
#define GPIO_CLRIRQEN2_INTLINE_MASK                                                     (0xffffffffU)
#define GPIO_CLRIRQEN2_INTLINE_NOEFFECT                                                  (0U)
#define GPIO_CLRIRQEN2_INTLINE_CLEAR                                                     (1U)

#define GPIO_SETIRQEN2_INTLINE_SHIFT                                                    (0U)
#define GPIO_SETIRQEN2_INTLINE_MASK                                                     (0xffffffffU)
#define GPIO_SETIRQEN2_INTLINE_NOEFFECT                                                  (0U)
#define GPIO_SETIRQEN2_INTLINE_SET                                                       (1U)

#define GPIO_CLRWKUPENA_INTLINE_SHIFT                                                   (0U)
#define GPIO_CLRWKUPENA_INTLINE_MASK                                                    (0xffffffffU)
#define GPIO_CLRWKUPENA_INTLINE_NOEFFECT                                                 (0U)
#define GPIO_CLRWKUPENA_INTLINE_CLEAR                                                    (1U)

#define GPIO_SETWKUENA_INTLINE_SHIFT                                                    (0U)
#define GPIO_SETWKUENA_INTLINE_MASK                                                     (0xffffffffU)
#define GPIO_SETWKUENA_INTLINE_NOEFFECT                                                  (0U)
#define GPIO_SETWKUENA_INTLINE_SET                                                       (1U)

#define GPIO_CLRDATAOUT_INTLINE_N_SHIFT                                                 (0U)
#define GPIO_CLRDATAOUT_INTLINE_N_MASK                                                  (0xffffffffU)

#define GPIO_SETDATAOUT_INTLINE_N_SHIFT                                                 (0U)
#define GPIO_SETDATAOUT_INTLINE_N_MASK                                                  (0xffffffffU)

#ifdef __cplusplus
}
#endif
#endif  /* HW_GPIO_H_ */