/**
 *  \file    pmic_device.h
 *
 *  \brief   The file contains the declaration for pmic data structure.
 *
 */

/*
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __PMIC_DEVICE_H
#define __PMIC_DEVICE_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* TPS659039 */
#define TPS659039_I2C_SLAVE_ADDR            0x58
#define TPS659039_REG_ADDR_SMPS12           0x23
#define TPS659039_REG_ADDR_SMPS45           0x2B
#define TPS659039_REG_ADDR_SMPS6            0x2F
#define TPS659039_REG_ADDR_SMPS7            0x33
#define TPS659039_REG_ADDR_SMPS8            0x37

typedef struct pmic_data {
    uint32_t base_offset;
    uint32_t step;
    uint32_t start_code;
    uint32_t slave_addr;
    uint32_t dev_instance;
    void (*pmic_device_open)(uint32_t instance);
    bool (*pmic_write)(uint32_t slaveAddr, uint8_t reg_addr, uint8_t value);
    uint32_t (*pmic_get_offset)(uint32_t volt_offset, struct pmic_data *pmic);
    void (*pmic_device_close)();
}pmic_data_t;

/**
 *  \brief    This API returns the pointer to the structure holding PMIC data.
 *
 *  \param    pPmicData   Pointer to the PMIC data structure.
 */
pmic_data_t* Board_GetPmicData();

#ifdef __cplusplus /* If this is a C++ compiler, end C linkage */
}
#endif

#endif /*__PMIC_DEVICE_H*/
