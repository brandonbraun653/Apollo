
/**
 *  @Component:   PMIC
 *
 *  @Filename:    hw_tps65218.h
 *
 ============================================================================ */
/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef TPS65218_H__
#define TPS65218_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* Address of TPS65218(pmic) over I2C0 */
#define  PMIC_TPS65218_I2C_SLAVE_ADDR   (0x24)


/* Registers */
#define CHIPID                          (0x00)
#define INTERRUPT1                      (0x01)
#define INTERRUPT2                      (0x02)
#define INT_MASK1                       (0x03)
#define INT_MASK2                       (0x04)
#define STATUS                          (0x05)
#define CONTROL                         (0x06)
#define FLAG                            (0x07)
#define PASSWORD                        (0x10)
#define ENABLE1                         (0x11)
#define ENABLE2                         (0x12)
#define CONFIG1                         (0x13)
#define CONFIG2                         (0x14)
#define CONFIG3                         (0x15)
#define DCDC1                           (0x16)
#define DCDC2                           (0x17)
#define DCDC3                           (0x18)
#define DCDC4                           (0x19)
#define SLEW                            (0x1A)
#define LDO1                            (0x1B)
#define SEQ1                            (0x20)
#define SEQ2                            (0x21)
#define SEQ3                            (0x22)
#define SEQ4                            (0x23)
#define SEQ5                            (0x24)
#define SEQ6                            (0x25)
#define SEQ7                            (0x26)

#define POWER_PATH_USB_EN_MASK          (0x10U)
#define POWER_PATH_USB_EN_SHIFT         (4U)
#define POWER_PATH_USB_EN_ON            (1U)
#define POWER_PATH_USB_EN_OFF           (0U)
#define POWER_PATH_IUSB_MASK            (0x03U)
#define POWER_PATH_IUSB_SHIFT           (0U)
#define POWER_PATH_IUSB_100MA           (0U)
#define POWER_PATH_IUSB_500MA           (1U)
#define POWER_PATH_IUSB_1300MA          (2U)
#define POWER_PATH_IUSB_2500MA          (3U)
#define POWER_PATH_AC_EN_MASK           (0x20U)
#define POWER_PATH_AC_EN_SHIFT          (5U)
#define POWER_PATH_AC_EN_ON             (1U)
#define POWER_PATH_AC_EN_OFF            (0U)
#define POWER_PATH_IAC_MASK             (0x0CU)
#define POWER_PATH_IAC_SHIFT            (2U)

#define DCDC_OP_VOLT_MASK               (0x3FU)
#define DCDC_OP_VOLT_SHIFT              (0U)

#define DCDC_GO_MASK                    (0x80)
#define DCDC_GO_SHIFT                   (7U)
#define DCDC_GO_INITIATE                (1U)
#define DCDC_GO_NO_CHANGE               (0U)

#define PASSWORD_LOCK_FOR_WRITE         (0x00)
#define PASSWORD_UNLOCK                 (0x7D)

#ifdef __cplusplus
}
#endif

#endif
