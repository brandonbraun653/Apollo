/**
 * \file chipdb.c
 *
 * \brief   Chip DB API Implementation
 *
 *          Chip DB API uses the pair (moduleID, instance) to uniquely
 *          identify a resource. The moduleID is unique across multiple SOCs.
 *          To make the implementation straight forward, the above pair is
 *          converted into a unique Resource ID to query the database.
 *
 *
 *
 * \version 0.0 (Aug 2013) : [AE] First version
 *
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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
#include <types.h>
#include <hw_types.h>
#include <soc_am335x.h>
#include <hw_control_am335x.h>
#include <chipdb.h>
#include <chipdb_defs.h>
#include "hw_am335x_chipdb.h"
#include "hw_am335x_chipdb_interrupt.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *
 * \brief The Base Part Number encoding that indicates the superset
 *        device. Normally the silicon samples are efused with this base PN.
 *
 */
#define CHIPDB_PN_ENABLE_ALL_ENCODING    (0xFF)

/**
 *
 * \brief The Speed Grade encoding that indicates the nominal speed grade.
 *        Normally the initial silicon samples are efused with this SG.
 *
 */
#define CHIPDB_DEFAULT_SG_ENCODING       (23U)

/**
 *
 * \brief The default junction temperature encoding. Used when the ChipDB
 *        is disabled.
 *
 */
#define CHIPDB_DEFAULT_JT_ENCODING       (0U)

/**
 *
 * \brief The default package encoding. Used when the ChipDB is disabled.
 *
 */
#define CHIPDB_DEFAULT_PACKAGE_ENCODING  (1U)

/**
 *
 * \brief The default device revision encoding. Used when the ChipDB is
 *        disabled.
 *
 */
#define CHIPDB_DEFAULT_REVISION_ENCODING (0U)

/**
 *
 * \brief Macro to get the maximum instance count of a given module.
 *
 */
#define CHIPDB_GET_MAX_INST(moduleID)  (gChipDBResourceIDMap[moduleID+1] -  \
                                        gChipDBResourceIDMap[moduleID])

/**
 *
 * \brief Exract the value of the specific bit from the given 32-bit bitmap.
 *
 */
#define CHIPDB_BIT_VALUE(value, bit) (((uint32_t)value >> bit) & 0x1)

/**
 *
 * \brief Lookup the bitmap value of the given resource ID.
 *
 */
#define CHIPDB_IS_RESOURCE_PRESENT(basePN, resID) \
           (CHIPDB_BIT_VALUE(gChipDBResourceTable[basePN][resID/32], resID%32))


/**
 *
 * \brief Device Min/Max Junction Temperature Values
 *        0 - Industrial: -40C to 105C
 *        1 - Automotive: -40C to 125C
 */
#define CHIPDB_INDUSTRIAL_MIN_TEMP        (-40)
#define CHIPDB_INDUSTRIAL_MAX_TEMP        (105)
#define CHIPDB_AUTOMOTIVE_MIN_TEMP        (-40)
#define CHIPDB_AUTOMOTIVE_MAX_TEMP        (125)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *
 * \brief Device Security Levels for AM335x
 *
 */
typedef enum chipdbSecurityLevelAm335x
{
  CHIPDB_SL_AM335X_MIN     = 0x0,
  /**< Indicates the minimum supported value in this enum */
  CHIPDB_SL_AM335X_TEST    = CHIPDB_SL_MIN,
  /**< Test Device */
  CHIPDB_SL_AM335X_EMU     = 0x1,
  /**< Emulation Device */
  CHIPDB_SL_AM335X_HS      = 0x2,
  /**< High Security Device */
  CHIPDB_SL_AM335X_GP      = 0x3,
  /**< General Purpose Device */
  CHIPDB_SL_AM335X_BAD     = 0x7,
  /**< General Purpose Device */
  CHIPDB_SL_AM335X_MAX     = CHIPDB_SL_AM335X_BAD,
  /**< Indicates the maximum supported value in this enum */
} chipdbSecurityLevelAm335x_t;


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/**
 *
 * \brief Flag to enable or disable Chip DB functionality. Can be used for
 *        debugging or to workaround issues.
 *
 *        The initial values is set to enable Chip DB.
 */
static uint32_t gChipDBEnabled = TRUE;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *
 * \brief Read the Base Part Number from the device.
 *
 * \retval Device base part number         If ChipDB is enabled.
 *         CHIPDB_PN_ENABLE_ALL_ENCODING   If ChipDB is disabled.
 *
 */
static uint32_t ChipDBReadBasePNEncoding(void);


/**
 *
 * \brief Read the speed grade from the device.
 *
 * \retval Device speed grade                   If ChipDB is enabled.
 *         CHIPDB_DEFAULT_SG_ENCODING      If ChipDB is disabled.
 *
 */
static uint32_t ChipDBReadSGEncoding(void);

/**
 *
 * \brief Read the device junction temperature range
 *
 * \retval Device Junction Temperature         If ChipDB is enabled.
 *         CHIPDB_DEFAULT_JT_ENCODING          If ChipDB is disabled.
 *
 */
static uint32_t ChipDBReadJTEncoding(void);

/**
 *
 * \brief Read the device package type
 *
 * \retval Device package type                  If ChipDB is enabled.
 *         CHIPDB_DEFAULT_PACKAGE_ENCODING      If ChipDB is disabled.
 *
 */
static uint32_t ChipDBReadPackageEncoding(void);

/**
 *
 * \brief Read the device revision
 *
 * \retval Device revision                      If ChipDB is enabled.
 *         CHIPDB_DEFAULT_REVISION_ENCODING     If ChipDB is disabled.
 *
 */
static uint32_t ChipDBReadRevisionEncoding(void);

/**
 *
 * \brief Read the device security level
 *
 * \retval Device security level                If ChipDB is enabled.
 *         CHIPDB_SL_GP                         If ChipDB is disabled.
 *
 */
static chipdbSecurityLevel_t ChipDBReadSecurityLevel(void);


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void CHIPDBEnable()
{
    gChipDBEnabled = TRUE;
}


void CHIPDBDisable()
{
    gChipDBEnabled = FALSE;
}


uint32_t CHIPDBModuleMaxInstanceNumber(const chipdbModuleID_t moduleID)
{
    uint32_t maxInst = 0;

    if (moduleID < CHIPDB_MOD_ID_COUNT)
    {
        maxInst = CHIPDB_GET_MAX_INST(moduleID);
    }

    return maxInst;
}


uint32_t CHIPDBIsResourcePresent(const chipdbModuleID_t moduleID,
                                 const uint32_t         instance)
{
    uint32_t resID;
    uint32_t basePN;
    uint32_t present = FALSE;

    if ((moduleID < CHIPDB_MOD_ID_COUNT)&&
        (CHIPDB_GET_MAX_INST(moduleID) > instance))
    {
        resID = CHIPDB_GET_RESOURCEID(moduleID, instance);

        if (resID < CHIPDB_RESOURCE_COUNT)
        {
            basePN = ChipDBReadBasePNEncoding();
            if (basePN == CHIPDB_PN_ENABLE_ALL_ENCODING)
            {
                present = TRUE;
            }
            else if (basePN < CHIPDB_DEVICE_COUNT)
            {
                present = CHIPDB_IS_RESOURCE_PRESENT(basePN, resID);
#ifndef DDRLESS
                /*
                 * For non-secure devices return false for secure IPs.
                 */
                if (CHIPDBIsSecureModule(moduleID) &&
                        CHIPDBSecurityLevel() != CHIPDB_SL_HS)
                {
                    present = FALSE;
                }
#endif
            }
        }
    }

    return present;
}


uint32_t CHIPDBResourceMaxFrequency(const chipdbModuleID_t moduleID)
{
   uint32_t speedGradeProcID;
   uint32_t speedGrade;
   uint32_t maxFreq = CHIPDB_INVALID_FREQUENCY;

   if (moduleID < CHIPDB_MOD_ID_COUNT &&
       CHIPDBIsResourcePresent(moduleID,0) == TRUE)
   {
       speedGradeProcID = CHIPDBSpeedGradeProcID(moduleID);

       if (speedGradeProcID < CHIPDB_SG_MODULE_COUNT)
       {
           speedGrade = ChipDBReadSGEncoding();

           if (speedGrade < CHIPDB_SG_COUNT)
           {
               maxFreq = gChipDBSpeedGrade[speedGrade][speedGradeProcID];
           }
       }
   }

   return maxFreq;
}


int32_t CHIPDBMaxJunctionTemperature(void)
{
    uint32_t tempEncoding = ChipDBReadJTEncoding();
    int32_t  maxT;

    /*
     * Junction Temperature Encoding
     * 0 - Industrial: -40C to 105C
     * 1 - Automotive: -40C to 125C
     *
     * If encoding outside of the above value, return Industrial values.
     */
    if (tempEncoding == 0x1)
        maxT = CHIPDB_AUTOMOTIVE_MAX_TEMP;
    else
        maxT = CHIPDB_INDUSTRIAL_MAX_TEMP;

    return maxT;
}


int32_t CHIPDBMinJunctionTemperature(void)
{
    uint32_t tempEncoding = ChipDBReadJTEncoding();
    uint32_t minT;

    /*
     * Junction Temperature Encoding
     * 0 - Industrial: -40C to 105C
     * 1 - Automotive: -40C to 125C
     *
     * If encoding outside of the above value, return Industrial values.
     */
    if (tempEncoding == 0x1)
        minT = CHIPDB_AUTOMOTIVE_MIN_TEMP;
    else
        minT = CHIPDB_INDUSTRIAL_MIN_TEMP;

    return minT;
}


chipdbPackageType_t CHIPDBPackageType(void)
{
    uint32_t packageEncoding = ChipDBReadPackageEncoding();
    chipdbPackageType_t package;

    /*
     * Packaging Type Encoding
     * 0 - not defined
     * 1 - AAS 17x17 Solder Flip Chip
     * 2 - ABC 23x23 Solder Flip Chip
     * 3 - not defined
     */
    if (packageEncoding == 0x1)
        package = CHIPDB_PT_17x17;
    else if (packageEncoding == 0x2)
        package = CHIPDB_PT_23x23;
    else
        package = CHIPDB_PT_INVALID;

    return package;
}


chipdbDeviceRevision_t CHIPDBDeviceRevision(void)
{
    return (chipdbDeviceRevision_t) ChipDBReadRevisionEncoding();
}


chipdbSecurityLevel_t CHIPDBSecurityLevel(void)
{
    return ChipDBReadSecurityLevel();
}


uint32_t CHIPDBBaseAddress(const chipdbModuleID_t moduleID,
                           const uint32_t         instance)
{
    uint32_t baseAddr = CHIPDB_INVALID_ADDRESS;
    uint32_t resID;

    /*
     * Check if the input parameters for out of bound values
     */
    if (moduleID < CHIPDB_MOD_ID_COUNT)
    {
        resID = CHIPDB_GET_RESOURCEID(moduleID, instance);

        if (resID < CHIPDB_RESOURCE_COUNT)
        {
            baseAddr = gChipDBBaseAddrTable[resID];
        }
    }

    return baseAddr;
}


uint32_t ChipDBInterruptNum(const chipdbModuleID_t moduleID,
                            const uint32_t         instance,
                            const uint32_t         intSignal)
{
    uint32_t resID;
    uint32_t intNum = CHIPDB_INVALID_INTERRUPT_NUM;

    if (moduleID < CHIPDB_MOD_ID_COUNT)
    {
        resID = CHIPDB_GET_RESOURCEID(moduleID, instance);

        if ((resID < CHIPDB_RESOURCE_COUNT) &&
            gChipDBInterruptTables[resID] != NULL)
        {
            intNum = (uint32_t) (gChipDBInterruptTables[resID])[intSignal];
        }
    }

    return intNum;
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t ChipDBReadBasePNEncoding(void)
{
    /* Only GP device is supported for now. TBD: Check for Crypto. */
    return (CHIPDB_PN_GP);
}


static uint32_t ChipDBReadSGEncoding(void)
{
    uint32_t speedGrade = CHIPDB_DEFAULT_SG_ENCODING;
#if 0 /* TBD: Update */
    uint32_t addr = SOC_CONTROL_REGS + CONTROL_DEV_ATTRIBUTE;
    uint32_t regVal;

    if (gChipDBEnabled == TRUE)
    {
        regVal = HW_RD_REG32(addr);
        speedGrade = HW_GET_FIELD(regVal, TBD);
    }
#endif /* if 0 */ /* Update for AM335x */

    return speedGrade;
}

static uint32_t ChipDBReadJTEncoding(void)
{
    uint32_t junctionT = CHIPDB_DEFAULT_JT_ENCODING;
#if 0 /* TBD: Update */
    uint32_t addr = SOC_CONTROL_REGS + CONTROL_DEV_ATTRIBUTE;
    uint32_t regVal;

    if (gChipDBEnabled == TRUE)
    {
        regVal = HW_RD_REG32(addr);
        junctionT = HW_GET_FIELD(regVal, TBD);
    }
#endif /* if 0 */ /* Update for AM335x */

    return junctionT;
}

static uint32_t ChipDBReadPackageEncoding(void)
{
    uint32_t package = CHIPDB_DEFAULT_PACKAGE_ENCODING;
#if 0 /* TBD: Update */
    uint32_t addr = SOC_CONTROL_REGS + CONTROL_DEV_ATTRIBUTE;
    uint32_t regVal;

    if (gChipDBEnabled == TRUE)
    {
        regVal = HW_RD_REG32(addr);
        package = HW_GET_FIELD(regVal, TBD);
    }
#endif /* if 0 */ /* Update for AM335x */

    return package;
}

static uint32_t ChipDBReadRevisionEncoding(void)
{
    uint32_t revision = CHIPDB_DEFAULT_REVISION_ENCODING;
    uint32_t addr = SOC_CONTROL_REGS + CONTROL_DEVICE_ID;
    uint32_t regVal;

    if (gChipDBEnabled == TRUE)
    {
        regVal = HW_RD_REG32(addr);
        revision = HW_GET_FIELD(regVal, CONTROL_DEVICE_ID_DEVREV);
    }

    return revision;
}

static chipdbSecurityLevel_t ChipDBReadSecurityLevel(void)
{
    chipdbSecurityLevel_t sl = CHIPDB_SL_GP;
    chipdbSecurityLevelAm335x_t slType = CHIPDB_SL_AM335X_GP;
    uint32_t addr = SOC_CONTROL_REGS + CONTROL_STATUS;
    uint32_t regVal;

    if (gChipDBEnabled == TRUE)
    {
        regVal = HW_RD_REG32(addr);
        sl = HW_GET_FIELD(regVal, CONTROL_STATUS_DEVTYPE);

        switch(slType)
        {
            case CHIPDB_SL_AM335X_TEST:
                sl = CHIPDB_SL_TEST;
                break;

            case CHIPDB_SL_AM335X_EMU:
                sl = CHIPDB_SL_EMU;
                break;

            case CHIPDB_SL_AM335X_HS:
                sl = CHIPDB_SL_HS;
                break;

            case CHIPDB_SL_AM335X_GP:
                sl = CHIPDB_SL_GP;
                break;

            case CHIPDB_SL_AM335X_BAD:
            default:
                sl = CHIPDB_SL_INVALID;
                break;
        }
    }

    return sl;
}
