/**
 *  \file  qspi_app.h
 *
 *  \brief This file contains structure for qspi app object
 *         and contains the init function for QSPI which is generic for
 *         all the applications. This file is also used by the
 *         QSPI bootloader.
 *
 *
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef QSPI_APP_H_
#define QSPI_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief QSPI device instance number */
#define QSPI_APP_DEV_INST_NUM    (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**< /brief Structure holdig the QSPI instance related data for nor flash */
typedef struct qspiAppObj
{
    uint32_t chipSelect;
    /**< QSPI chip select number */
    uint32_t instNum;
    /**< QSPI instance number */
    uint32_t instAddr;
    /**< QSPI instance address */
    uint32_t devId;
    /**< QSPI device ID*/
    uint32_t length;
    /**< Length of data to be transferred */
    qspiLibInfo_t qspiLibInfo;
    /**< configurable parameters for the qspi flash device and controller */
}qspiAppObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   QSPI IP configuration initialization api.
 *
 * \param   pQspiObj        Pointer to the QSPI object.
 * \retval S_PASS App init successful
 * \retval E_FAIL App init failed
 */
int32_t QSPIAppInit(qspiAppObj_t *pQspiObj);

/**
 * \brief This API gets the board info like instance and chip select.
 *
 * \param pQspiObj Pointer to the flash device object
 *
 * \retval S_PASS    BOARD info successfully retrieved. QSPI is connected to
 *                   serial flash on this board.
 *
 * \retval E_FAIL    This board does not support this application
 *                   - Serial Flash device may not be present on this board.
 *                   - Serial flash may not be connected to QSPI controller.
 *
 */

int32_t QSPIAppBoardInfoGet(qspiAppObj_t *pQspiObj);

/**
 * \brief  This API gots the soc info - base address of the QSPI instance
 *
 * \param  pQspiObj     Pointer to the flash device object.
 *
 * \retval S_PASS Example is supported on this SOC.
 *         E_FAIL This example is not supported on this SOC.
 */

int32_t QSPIAppSocInfoGet(qspiAppObj_t *pQspiObj);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef QSPI_APP_H_ */
