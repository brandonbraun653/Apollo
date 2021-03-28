/**
 * \file      nand_device.h
 *
 * \brief     This file contains information pertaining to Nand flash
 *            devices MT29F4G08AB and MT29F2G08AB
 */

/**
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

#ifndef NAND_DEVICE_H_
#define NAND_DEVICE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief Macro defining the Page Size and Block Size of the NAND device. */
#ifdef AM335X_FAMILY_BUILD
#define PAGE_SIZE                                   (2048U)
#define BLOCK_SIZE                                  (128 * 1024)
#elif AM43XX_FAMILY_BUILD
#define PAGE_SIZE                                   (4096U)
#define BLOCK_SIZE                                  (256 * 1024)
#endif

/* ========================================================================== */
/*                          Structures and Enums                              */
/* ========================================================================== */

/** \brief Structure holding the NAND Flash timing parameters. */
typedef struct nandTimingParams
{
    uint32_t    csOnTime;
    /**< Chip Select assertion time. */
    uint32_t    csRdOffTime;
    /**< Chip Select Read de-assertion time. */
    uint32_t    csWrOffTime;
    /**< Chip Select Write de-assertion time. */
    uint32_t    advOnTime;
    /**< Assertion time. */
    uint32_t    advRdOffTime;
    /**< Read de-assertion time. */
    uint32_t    advWrOffTime;
    /**< Write de-assertion time. */
    uint32_t    weOnTtime;
    /**< WE assertion time. */
    uint32_t    weOffTime;
    /**< WE de-assertion time. */
    uint32_t    oeOnTime;
    /**< OE assertion time. */
    uint32_t    oeOffTime;
    /**< OE de-assertion time. */
    uint32_t    pageBurstAccess;
    /**< Multiple access word delay. */
    uint32_t    rdAccessTime;
    /**< Start-cycle to first valid delay. */
    uint32_t    wrAcessTime;
    /**< Delay from StartAccessTime to the CLK rising edge. */
    uint32_t    rdCycleTime;
    /**< Total read cycle time. */
    uint32_t    wrCycleTime;
    /**< Total write cycle time. */
    uint32_t    wrDataOnMuxBusTime;
    /**< Write Data on Mux Bus Time. */
    uint32_t    cycleDelay;
    /**< Chip Select high pulse delay between two successive accesses. */
}nandTimingParams_t;

/** \brief Structure holding the NAND device Parameters. */
typedef struct nandDeviceData
{
    uint32_t    flashId;
    /**< NAND flash Id. */
    uint32_t    busWidth;
    /**< Bus Width of the Nand device. */
    uint32_t    waitPinPol;
    /**< Polarity of the Ready/Busy signal connected to the wait pin. */
    uint32_t    writeProtectPinLvl;
    /**< Write Protect Pin Level Polarity. */
    nandTimingParams_t timingParams;
    /**< Nand device Timing Values for Read/Write. */
}nandDeviceData_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API returns the NAND flash related data according to the device
 *          that is connected to the board.
 *
 * \param   devId   The device id of the device connected to the GPMC controller
 *
 * \retval NANDDevicedata Pointer to the NAND device data.
 */
nandDeviceData_t *NANDGetDeviceData(uint32_t devId);

/**
 * \brief This API returns the list of NAND devices available.
 *
 * \retval nandDeviceIdList Pointer to the NAND device ID list
 */
uint32_t * NANDGetDeviceIdList(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef NAND_DEVICE_H_ */
