/**
 *  \file  pm_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the PM.
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

#ifndef PM_APP_H_
#define PM_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding the frequency and voltage pair values
           forming the OPP. */
typedef struct pmAppOppTable
{
    uint32_t mpuFreq;
    /**< Frequency value forming the OPP. */
    uint32_t voltage;
    /**< Voltage value forming the OPP. */
    uint32_t oppVal;
    /**< The value defining the OPP pair value. */
}pmAppOppTable_t;

/** \brief Enumerates the different OPP values supported */
typedef enum pmAppOpp
{
    PM_APP_OPP_MIN = 0U,
    /**< Macro defining the minimum OPP value. */
    PM_APP_OPP_50 = PM_APP_OPP_MIN,
    /**< Macro defining the OPP50 value. */
    PM_APP_OPP_100,
    /**< Macro defining the OPP100 value. */
    PM_APP_OPP_120,
    /**< Macro defining the OPP120 value. */
    PM_APP_OPP_TURBO,
    /**< Macro defining the OPPTURBO value. */
    PM_APP_OPP_NITRO,
    /**< Macro defining the OPPNITRO value. */
    PM_APP_OPP_MAX = PM_APP_OPP_NITRO
    /**< Macro defining the maximum OPP value. */
}pmAppOppVal_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  Configure the Minimum OPP for the device.
 *
 */
void PMAppMinOppConfig();

/**
 *  \brief  Configure the desired OPP value passed to this API.
 *
 *  \Note:  This API does not take consider the previous value of OPP
 *          configured. This condition will have to be considered
 *          before changing the OPP.
 */
void PMAppOppConfig(uint32_t oppVal);

/**
 * \brief  Set the specified MPU frequency for the device.
 *
 */
void PMAppSetMpuFreq(uint32_t mpuFreq);

/**
 * \brief    Get the Specified voltage and frequency pair for
 *           the OPP value specified.
 *
 *  \param   oppVal    The OPP pair value.
 *
 *  \retval  pOppVal   Pointer to the voltage frequency pair for the
 *                     OPP value.
 */
pmAppOppTable_t* PMAppGetOpp(uint32_t oppVal);

/**
 * \brief    Get the Specified voltage and frequency pair for
 *           the OPP value specified.
 *
 *  \retval  pOppVal   Pointer to the voltage frequency pair for the
 *                     OPP value.
 */
void PMAppSavePeripheralCntxt(uint32_t slpMode, uint32_t wakeSource);

/**
 * \brief    Get the Specified voltage and frequency pair for
 *           the OPP value specified.
 *
 *  \retval  pOppVal   Pointer to the voltage frequency pair for the
 *                     OPP value.
 */
void PMAppRestorePeripheralCntxt(uint32_t slpMode, uint32_t wakeSource);

/**
 * \brief    Save the Context of the Utils used by the system.
 *
 */
void PmAppSaveUtilsCntxt(void);

/**
 * \brief    Restore the Context of the Utils used by the system.
 *
 */
void PmAppRestoreUtilsCntxt(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef PM_APP_H_ */
