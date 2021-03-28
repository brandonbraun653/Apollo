/**
 * \file   eeprom_read_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case.
 *
 */

/**
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "console_utils.h"
#include "i2c_app.h"
#include "cache.h"
#include "mmu.h"
#include "example_utils_mmu.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief EEPROM device instance number */
#define I2C_EEPROM_INST_NUM         (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding EEPROM Read use-case specific parameters. */
typedef struct i2cAppEepromCfg
{
    uint8_t             *pOffset;
    /**< Pointer to the offset from where to read/write from the device */
    uint32_t             offsetSize;
    /**< The size of the offset value passed */
    uint32_t             bufLen;
    /**< Length of the buffer passed */
    uint8_t              *pBuf;
    /**< pointer to a buffer to hold the data */
}i2cAppEepromCfg_t;

/** \brief  This is the main application data structure. */
typedef struct i2cAppEepromRead
{
    i2cAppEepromCfg_t     eepromCfgParams;
    /**< I2C EEPROM Read use case data structure. */
    i2cAppCfgObj_t        i2cAppCfgObj;
    /**< I2C configuration parameters structure. */
}i2cAppEepromRead_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   Gets the Board related information like instance numner
 *           and slave address of the EEPROM device.
 *
 *  \param   pI2cObj  pointer to a structure which holds the application
 *                    configuration parameters.
 *
 *  \retval  S_PASS  on success.
 *  \retval  E_FAIL  on failure.
 */
static int32_t I2cAppBoardInfoGet(i2cAppCfgObj_t  *pI2cObj);

/**
 *  \brief   Updates the SOC related information like baseAddress, interrupt
 *           line number.
 *
 *  \param   pI2cObj  pointer to a structure which holds the application
 *                    configuration parameters.
 *
 *  \retval  S_PASS  on success.
 *  \retval  E_FAIL  on failure.
 */
static int32_t I2cAppSocInfoGet(i2cAppCfgObj_t  *pI2cObj);

/**
 * \brief   EEPROM Read API used to read the specified number of bytes from
 *          the EEPROM device attached.
 *
 * \param   pEepromCfg   pointer to Structure holding eeprom configuration
 */
static int32_t I2cAppEepromRead(i2cAppEepromRead_t *pEepromCfg);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Data buffer where the data read from EEPROM needs to be stored */
uint8_t gEepromReadAppDataBuf[100U];

/** \brief Offset value from where the data has to be read */
uint8_t gEepromReadAppOffset[2U] = {0x00U, 0x00U};

/** \brief Application default configuration */
static const i2cAppEepromRead_t I2CAPP_EEPROM_DEFAULT =
{
    {
        gEepromReadAppOffset,           /* pOffset */
        2U,                             /* offsetSize */
        50U,                            /* bufLen */
        gEepromReadAppDataBuf           /* pBuf */
    },  /* i2cAppEepromCfg_t */
    {
        0U,                             /* instId */
        0U,                             /* instAddr */
        /* The instance Id and baseAddress shall be updated by ChipDB */
        0x50U,                          /* slaveAddr */
        {
            100U,                       /* busSpeed */
            I2C_ADDRMODE_7BIT,          /* addrMode */
            I2C_APP_OPMODE_POLLING,     /* opMode */
            0U,                         /* rxThreshold */
            0U                          /* txThreshold */
        },  /* i2cAppCfg */
        {
            INTC_TRIG_HIGH_LEVEL,       /* trigType */
            0U,                         /* intrLine */
            /* The interrupt line shall be updated using ChipDB */
            0x20U,                      /* intrPriority */
            FALSE,                      /* isIntrSecure */
            NULL,                       /* pFnIntrhandler */
        }  /* i2cAppIntrCfg  */
    }   /* i2cAppCfgObj_t */
};      /* i2cAppEepromRead_t */

/** \brief Global object for the I2C EEPROM Read Application */
static i2cAppEepromRead_t    gEepromReadApp;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


int main()
{
    int32_t status = S_PASS;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    gEepromReadApp = I2CAPP_EEPROM_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\r\n StarterWare EEPROM Read Application \r\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get Board Info */
    status = I2cAppBoardInfoGet(&gEepromReadApp.i2cAppCfgObj);
    if (S_PASS == status)
    {
        /* Update SoC info */
        status = I2cAppSocInfoGet(&gEepromReadApp.i2cAppCfgObj);

        if(S_PASS == status)
        {
            /* I2C clock/pin mux and IP configuration */
            status = I2CAppModuleInit(&gEepromReadApp.i2cAppCfgObj);

            if(S_PASS != status)
            {
                CONSOLEUtilsPrintf("Initialization failed!!\n");
            }
            else
            {
                status = I2CAppCtrlInit(&gEepromReadApp.i2cAppCfgObj);

                if( S_PASS != status)
                {
                    CONSOLEUtilsPrintf("Controller Initialization failed %d\r\n"
                                        ,status);
                }
                else
                {
                    /* Call the EEPROM Read function */
                    status = I2cAppEepromRead(&gEepromReadApp);

                    if(S_PASS == status)
                    {
                        CONSOLEUtilsPrintf("EEPROM read success!\r\n");
                    }
                    else
                    {
                        CONSOLEUtilsPrintf("EEPROM read Failed! %d\r\n"
                                            ,status);
                    }
                }
            }
        }
        else
        {
            CONSOLEUtilsPrintf("Instance is not present on the device!\r\n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this board!\n");
    }

    return (1);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t I2cAppBoardInfoGet(i2cAppCfgObj_t  *pI2cObj)
{
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t  i2cInstNum;
    uint32_t  slaveAddr;

    /* Get the I2C data for EEPROM from the board data */
    modId = BOARDGetDeviceCtrlModId(DEVICE_ID_EEPROM, I2C_EEPROM_INST_NUM);

    if (CHIPDB_MOD_ID_INVALID == modId)
    {
        CONSOLEUtilsPrintf("Device is not available on this board!\n");
    }
    else if (CHIPDB_MOD_ID_I2C == modId)
    {
        i2cInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_EEPROM,
                                                    I2C_EEPROM_INST_NUM);
        slaveAddr = BOARDGetDeviceCtrlInfo(DEVICE_ID_EEPROM, I2C_EEPROM_INST_NUM);

        if ((INVALID_INST_NUM == i2cInstNum) || (INVALID_INFO == slaveAddr))
        {
            CONSOLEUtilsPrintf("Invalid I2C board data!\n");
        }
        else
        {
            CONSOLEUtilsPrintf("I2C Instance number: %d\n", i2cInstNum);
            CONSOLEUtilsPrintf("Slave Address of EEPROM: %x\n", slaveAddr);
            pI2cObj->i2cInstNum = i2cInstNum;
            pI2cObj->slaveAddr = slaveAddr;
            status = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Device is not connected to I2C!\n");
    }

    return (status);

}

static int32_t I2cAppSocInfoGet(i2cAppCfgObj_t  *pI2cObj)
{
    int32_t status = S_PASS;

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_I2C, pI2cObj->i2cInstNum))
    {
        pI2cObj->i2cBaseAddr =
                        CHIPDBBaseAddress(CHIPDB_MOD_ID_I2C, pI2cObj->i2cInstNum);

        /* Update the Interrupt Line number */
        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            pI2cObj->i2cAppIntrCfg.intrLine = 102U;
        }
        else
        {
            pI2cObj->i2cAppIntrCfg.intrLine = 70U;
        }
        /* TODO: Need to update the interrupt Numberdata base of ChipDB */
        /*
        pI2cObj->i2cAppIntrCfg.intrLine = ChipDBInterruptNum(CHIPDB_MOD_ID_I2C,
                                          pI2cObj->instNum, 0);
        */
    }
    else
    {
        status = E_FAIL;
    }

    return status;
}

static int32_t I2cAppEepromRead(i2cAppEepromRead_t *pEepromCfg)
{
    int32_t status = S_PASS;
    uint32_t index = 0U;
    uint8_t byte;

    /* Call write function to transmit the offset */
    status = I2CAppWrite(&pEepromCfg->i2cAppCfgObj,
                        pEepromCfg->eepromCfgParams.pOffset,
                        pEepromCfg->eepromCfgParams.offsetSize);

    if(S_PASS == status)
    {
        /* Call I2C read function to read the actual data from EEPROM*/
        status = I2CAppRead(&pEepromCfg->i2cAppCfgObj,
                             pEepromCfg->eepromCfgParams.pBuf,
                             pEepromCfg->eepromCfgParams.bufLen);
    }

    if(S_PASS == status)
    {
        CONSOLEUtilsPrintf("the data Read from EEPROM is: ");

        for(index = 0; index < pEepromCfg->eepromCfgParams.bufLen; index++)
        {
            /* Collecting the Most Significant Nibble of the data byte. */
            byte = *(pEepromCfg->eepromCfgParams.pBuf + index);

            CONSOLEUtilsPrintf("%x,", byte);
        }
        CONSOLEUtilsPrintf("\r\n");
     }
    return status;
}
