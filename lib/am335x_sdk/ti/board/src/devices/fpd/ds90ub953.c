/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 * \file  ds90ub953.c
 *
 * \brief This file contains the API's for configuring the ds90ub953 deserailizer.
 *
 */
#include "ds90ub953.h"

Board_I2cRegProgObj Board_FpdUb953PGCfg0[] =
{
    /* Indirect Pattern Gen Registers */
    {0xB0,0x00, 0x1},
    /* PGEN_CTL */
    {0xB1,0x01, 0x1},
    {0xB2,0x01, 0x1},
    /* PGEN_CFG */
    {0xB1,0x02, 0x1},
    {0xB2,0x33, 0x1},
    /* PGEN_CSI_DI */
    {0xB1,0x03, 0x1},
    /* RGB888 */
    {0xB2,0x24, 0x1},
    /* PGEN_LINE_SIZE1 */
    {0xB1,0x04, 0x1},
    {0xB2,0x16, 0x1},
    /* PGEN_LINE_SIZE0 */
    {0xB1,0x05, 0x1},
    {0xB2,0x80, 0x1},
    /* PGEN_BAR_SIZE1 */
    {0xB1,0x06, 0x1},
    {0xB2,0x02, 0x1},
    /* PGEN_BAR_SIZE0 */
    {0xB1,0x07, 0x1},
    {0xB2,0xD0, 0x1},
    /* PGEN_ACT_LPF1 */
    {0xB1,0x08, 0x1},
    {0xB2,0x04, 0x1},
    /* PGEN_ACT_LPF0 */
    {0xB1,0x09, 0x1},
    {0xB2,0x38, 0x1},
    /* PGEN_TOT_LPF1 */
    {0xB1,0x0A, 0x1},
    {0xB2,0x04, 0x1},
    /* PGEN_TOT_LPF0 */
    {0xB1,0x0B, 0x1},
    {0xB2,0x65, 0x1},
    /* PGEN_LINE_PD1 */
    {0xB1,0x0C, 0x1},
    {0xB2,0x0B, 0x1},
    /* PGEN_LINE_PD0 */
    {0xB1,0x0D, 0x1},
    {0xB2,0x93, 0x1},
    /* PGEN_VBP */
    {0xB1,0x0E, 0x1},
    {0xB2,0x21, 0x1},
    /* PGEN_VFP */
    {0xB1,0x0F, 0x1},
    {0xB2,0x0A, 0x1},
    {BOARD_DEVICES_CONFIG_END}
};

Board_I2cRegProgObj Board_FpdUb953PGCfg1[] =
{
    /** reset */
    {0x01, 0x01, 0x80},
    {0x02, 0x72, 0x10},
    {0x06, 0x21, 0x1},
    {0x07, 0x28, 0x1},
    {0xB0, 0x00, 0x1},   /* Indirect Pattern Gen Registers */
    {0xB1, 0x01, 0x1},   /* PGEN_CTL */
    {0xB2, 0x01, 0x1},
    {0xB1, 0x02, 0x1},   /* PGEN_CFG */
    {0xB2, 0x33, 0x1},
    {0xB1, 0x03, 0x1},   /* PGEN_CSI_DI */
    {0xB2, 0x2C, 0x1},
    {0xB1, 0x04, 0x1},   /* PGEN_LINE_SIZE1 */
    {0xB2, 0x0B, 0x1},
    {0xB1, 0x05, 0x1},   /* PGEN_LINE_SIZE0 */
    {0xB2, 0x40, 0x1},
    {0xB1, 0x06, 0x1},   /* PGEN_BAR_SIZE1 */
    {0xB2, 0x01, 0x1},
    {0xB1, 0x07, 0x1},   /* PGEN_BAR_SIZE0 */
    {0xB2, 0x68, 0x1},
    {0xB1, 0x08, 0x1},   /* PGEN_ACT_LPF1 */
    {0xB2, 0x04, 0x1},
    {0xB1, 0x09, 0x1},   /* PGEN_ACT_LPF0 */
    {0xB2, 0x38, 0x1},
    {0xB1, 0x0A, 0x1},   /* PGEN_TOT_LPF1 */
    {0xB2, 0x07, 0x1},
    {0xB1, 0x0B, 0x1},   /* PGEN_TOT_LPF0 */
    {0xB2, 0x08, 0x1},
    {0xB1, 0x0C, 0x1},   /* PGEN_LINE_PD1 */
    {0xB2, 0x0C, 0x1},
    {0xB1, 0x0D, 0x1},   /* PGEN_LINE_PD0 */
    {0xB2, 0x67, 0x1},
    {0xB1, 0x0E, 0x1},   /* PGEN_VBP */
    {0xB2, 0x21, 0x1},
    {0xB1, 0x0F, 0x1},   /* PGEN_VFP */
    {0xB2, 0x0A, 0x1},
    {BOARD_DEVICES_CONFIG_END}
};

Board_I2cRegProgObj *Board_FpdUB953PGCfg[BOARD_FPD_UB953_PG_MAX] =
{
    &Board_FpdUb953PGCfg0[0U],       /* RGB888 1280x720 30fps */
    &Board_FpdUb953PGCfg1[0U],       /* RGB888 1920x1080 30fps */
};

Board_I2cRegProgObj Board_FpdUb953CfgObj[10] =
{
    /** reset */
    {0x01, 0x01, 0x80},
    {0x02, 0x72, 0x10},

    {0x06, 0x21, 0x1},
    {0x07, 0x28, 0x1},

    {0x0D, 0x01, 0x1},
    {0x0E, 0xF0, 0x1},
    {0xB0, 0x04, 0x1},
    {0xB1, 0x08, 0x1},
    {0xB2, 0x07, 0x1},
    {BOARD_DEVICES_CONFIG_END}
};

Board_I2cRegProgObj Board_FpdUb953CfgObjTIDA1130[10] =
{
    {0x02, 0x52, 0x10},
    {0x06, 0x41, 0x1},
    {0x07, 0x28, 0x1},
    {0x0E, 0xF0, 0x1},
    {0x0D, 0x00, 0x1},
    {0x0D, 0x0C, 0x1},
    {BOARD_DEVICES_CONFIG_END}
};

/**
 * \brief  FPD ub953 pattern generation configurations.
 *
 * This function is used for configuring the pattern generator for FPD UB953
 *
 * \param   handle          [IN]  Low level driver handle
 * \param   fpdModParams    [IN]  FPD module params
 * \param   pgType          [IN]  Pattern Generation Type
 *                                See \ref DESUB953_patternType for details.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb953CfgPG(void *handle,
                                 Board_FpdModuleObj *fpdModParams,
                                 uint32_t pgType)
{
    Board_STATUS ret = BOARD_SOK;

    if((handle == NULL) && (pgType >= BOARD_FPD_UB953_PG_MAX))
    {
        ret = BOARD_INVALID_PARAM;
    }

    if (ret == BOARD_SOK)
    {
        ret = Board_fpdUb953Cfg(handle,
                                fpdModParams,
                                Board_FpdUB953PGCfg[pgType]);
    }

    return (ret);
}

/**
 * \brief  Initializes the FPD UB953 module.
 *
 * This function is used to initialize the fpd ub953 module
 *
 * \param   handle           [IN]  Low level driver handle
 * \param   fpdModParams     [IN]  FPD module params
 * \param   fpdRmtDevParams  [IN]  FPD remote device params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb953SerInit(void *handle,
                                   Board_FpdModuleObj *fpdModParams)
{
    Board_STATUS ret = BOARD_SOK;
    uint16_t index = 1;
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
    uint8_t rdData;
#endif

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    BOARD_DEVICES_STS_LOG("Configuring the remote serializer with slave address - 0x%x...\n\r", fpdModParams->serDesAliasAddr);

    while(Board_FpdUb953CfgObj[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
        BOARD_DEVICES_STS_LOG("regAddr - 0x%2x --- regData - 0x%2x", (uint8_t)Board_FpdUb953CfgObj[index].regAddr, Board_FpdUb953CfgObj[index].regData);
#endif
        ret = Board_i2c8BitRegWr(handle,
                                 fpdModParams->serDesAliasAddr,
                                 (uint8_t)Board_FpdUb953CfgObj[index].regAddr,
                                 (uint8_t *)(&Board_FpdUb953CfgObj[index].regData),
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        if(Board_FpdUb953CfgObj[index].i2cDelay != 0)
            Board_delay(Board_FpdUb953CfgObj[index].i2cDelay);

#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
        ret = Board_i2c8BitRegRd(handle,
                                 fpdModParams->serDesAliasAddr,
                                 (uint8_t)Board_FpdUb953CfgObj[index].regAddr,
                                 &rdData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        BOARD_DEVICES_STS_LOG(" --- read back data - 0x%2x\n\r", rdData);
#endif
        index++;
    }

    return BOARD_SOK;
}

Board_STATUS Board_fpdUb953DesInitFusionBoardTIDA1130(void *handle,
                                            Board_FpdModuleObj *fpdModParams)
{
    Board_STATUS ret = BOARD_SOK;
    uint16_t index = 1;
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
    uint8_t rdData;
#endif

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    BOARD_DEVICES_STS_LOG("Configuring the remote serializer with slave address - 0x%x...\n\r", fpdModParams->serDesAliasAddr);

    while(Board_FpdUb953CfgObjTIDA1130[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
        BOARD_DEVICES_STS_LOG("regAddr - 0x%2x --- regData - 0x%2x", (uint8_t)Board_FpdUb953CfgObjTIDA1130[index].regAddr, Board_FpdUb953CfgObjTIDA1130[index].regData);
#endif
        ret = Board_i2c8BitRegWr(handle,
                                 fpdModParams->serDesAliasAddr,
                                 (uint8_t)Board_FpdUb953CfgObjTIDA1130[index].regAddr,
                                 (uint8_t *)(&Board_FpdUb953CfgObjTIDA1130[index].regData),
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        if(Board_FpdUb953CfgObjTIDA1130[index].i2cDelay != 0)
            Board_delay(Board_FpdUb953CfgObjTIDA1130[index].i2cDelay);

#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
        ret = Board_i2c8BitRegRd(handle,
                                 fpdModParams->serDesAliasAddr,
                                 (uint8_t)Board_FpdUb953CfgObjTIDA1130[index].regAddr,
                                 &rdData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        BOARD_DEVICES_STS_LOG(" --- read back data - 0x%2x\n\r", rdData);
#endif
        index++;
    }

    return BOARD_SOK;
}

/**
 * \brief  FPD ub953 pattern generation configurations.
 *
 * This function is used for configuring the pattern generator for FPD UB953
 *
 * \param   handle          [IN]  Low level driver handle
 * \param   fpdModParams    [IN]  FPD module params
 * \param   ub953Cfg        [IN]  Configuration Info
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb953Cfg(void *handle,
                               Board_FpdModuleObj *fpdModParams,
                               Board_I2cRegProgObj *ub953Cfg)
{
    Board_STATUS ret = BOARD_SOK;
    uint16_t index = 0;
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
    uint8_t rdData;
#endif

    if (handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    BOARD_DEVICES_STS_LOG("PG configurations for serializer with slave address - 0x%x...\n\r", fpdModParams->serDesAliasAddr);
    while(ub953Cfg[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
        BOARD_DEVICES_STS_LOG("regAddr - 0x%2x --- regData - 0x%2x", (uint8_t)ub953Cfg[index].regAddr, ub953Cfg[index].regData);
#endif
        ret = Board_i2c8BitRegWr(handle,
                                 fpdModParams->serDesAliasAddr,
                                 (uint8_t)ub953Cfg[index].regAddr,
                                 (uint8_t *)(&ub953Cfg[index].regData),
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        if(ub953Cfg[index].i2cDelay != 0)
            Board_delay(ub953Cfg[index].i2cDelay);

#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
        ret = Board_i2c8BitRegRd(handle,
                                 fpdModParams->serDesAliasAddr,
                                 (uint8_t)(ub953Cfg[index].regAddr),
                                 &rdData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        BOARD_DEVICES_STS_LOG(" --- read back data - 0x%2x\n\r", rdData);
#endif
        index++;
    }

    return BOARD_SOK;
}
