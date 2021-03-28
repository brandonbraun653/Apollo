/**
 *  \file  read_write_app.h
 *
 *  \brief This file contains structure for nand app object
 *         and contains the init function for NAND which is generic for
 *         all the applications.
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

#ifndef READ_WRITE_APP_H_
#define READ_WRITE_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief NAND device instance number */
#define NAND_APP_DEV_INST_NUM    (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**< \brief Structure holding the NAND instance related data for NAND flash */
typedef struct nandAppObj
{
    uint32_t nandFlashId;
    /**< NAND Flash device ID. */
    nandLibInfo_t nandLibInfo;
    /**< Configurable parameters for the NAND Flash device and controller */
}nandAppObj_t;

/**< \brief Structure holding the NAND use case parameters. */
typedef struct nandAppReadWriteObj
{
    nandLibMemCtrlr_t    memCtrlr;
    /**< Memory Controller to be used to interface with the NAND. */
    nandLibEccAlgo_t     eccAlgo;
    /**< ECC Algorithm to be used for NAND device access. */
    nandLibXferMode_t    xferMode;
    /**< Operational mode to access the NAND device. */
    uint32_t             blockNum;
    /**< Block Number of the NAND device. */
    uint32_t             pageNum;
    /**< Page Number of the NAND device. */
}nandAppReadWriteObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef READ_WRITE_APP_H_ */
