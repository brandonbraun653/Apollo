/**
 * \file   error.h
 *
 * \brief  This files contains the macros for commonly used error code in
 *         StarterWare. These error codes are not specific to any module.
 *
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
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


#ifndef ERROR_H__
#define ERROR_H__

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/**
 *  \name Invalid definitions
 *
 *  Definitions of different invalid identifiers.
 *
 */

/** @{ */

/** \brief Invalid ID  */
#define INVALID_ID              (UINT32_MAX)
/** \brief Invalid instance number  */
#define INVALID_INST_NUM        (UINT32_MAX)
/** \brief Invalid information  */
#define INVALID_INFO            (UINT32_MAX)

/** @} */


/**
 *  \name Status codes
 *
 *  Defines codes for different types of success and failures
 *
 */

/** @{ */

/** \brief Successful completion of the functionality.  */
#define S_PASS                  (0)
/** \brief Generic failure code.                        */
#define E_FAIL                  (-1)
/** \brief Invalid parameter                            */
#define E_INVALID_PARAM         (-2)
/** \brief Invalid operation                            */
#define E_INVALID_OPERATION     (-3)
/** \brief Invalid index                                */
#define E_INVALID_INDEX         (-4)
/** \brief Interrupt number not supported               */
#define E_INTR_NOT_SUPP         (-5)
/** \brief Instance number not supported                */
#define E_INST_NOT_SUPP         (-6)
/** \brief Invalid address                              */
#define E_INVALID_ADDR          (-7)
/** \brief Invalid profile                              */
#define E_INVALID_PROFILE       (-8)
/** \brief Invalid Chip Select                          */
#define E_INVALID_CHIP_SEL      (-9)
/** \brief Initialization not done                      */
#define E_NOT_INITIALIZED       (-10)
/** \brief Mode Not Supported                           */
#define E_MODE_NOT_SUPP         (-11)
/** \brief Time Out condition                           */
#define E_TIMEOUT               (-12)
/** \brief No Acknowledgement from I2C device           */
#define E_I2C_NAK_ERR           (-13)
/** \brief Invalid Module Id                            */
#define E_INVALID_MODULE_ID     (-14)
/** \brief Buffer Over Run                              */
#define E_BUF_OVERRUN           (-15)



/* host driver error codes */
/* lower word of the error code is the xhci completion code */
#define NO_ERROR                            (0x00000000U)
#define ERR_USB_HOST_UNEXPECTED_TRB_TYPE    (0x00ff0000U)
#define ERR_USB_HOST_CONFIG_EP_FAILED       (0x00010000U)
#define ERR_USB_HOST_GET_DEV_DESC           (0x00020000U)
#define ERR_USB_HOST_GET_CONF_DESC          (0x00030000U) 
#define ERR_USB_HOST_WRITE                  (0x00040000U)
#define ERR_USB_HOST_READ                   (0x00050000U)
#define ERR_USB_HOST_SET_ADDRESS_FAILED     (0x00060000U)
#define ERR_USB_HOST_DISABLE_SLOT_FAILED    (0x00070000U)
#define ERR_USB_HOST_DEVICE_RESET_FAILED    (0x00080000U)
#define ERR_USB_HOST_DEVICE_CONNECT_FAILED  (0x00090000U)
#define ERR_USB_HOST_DEVICE_GET_SLOT_FAILED (0x000A0000U)
#define ERR_USB_HOST_SET_CONF_DESC          (0x000B0000U)
#define ERR_USB_HOST_CTRL_TRANSFER_FAILED   (0x000C0000U)
#define ERR_USB_HOST_BAD_DATA               (0x000D0000U)
#define ERR_USB_HOST_PSC_HANDLING_FAILED    (0x000E0000U)
#define ERROR_USB_HOST_DEVICE_NOTSUPPORTED  (0x000F0000U)
#define ERROR_USB_HOST_GET_INTERFACE_FAILED (0x00100000U)
#define NO_DEVICE_CONNECTED                 (0x00110000U)

/** @} */

#ifdef __cplusplus
}
#endif

#endif
