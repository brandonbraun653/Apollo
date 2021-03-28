/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2014
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
 */

/**
 * \file    pmlib_videopll_data.c
 *
 * \brief   PMLIB Videopll Data Base .
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include "pmlib_videopll_data.h"
#include "pm_utils.h"
#include "pmhal_cm.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*  none */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**< Minimum and Maximun range of Videopll feat param Elements  */
const uint64_t         gPmlibPllMinmMaxVal[PMLIB_VIDEOPLL_FEAT_NUMBER_OF_PARAMS
][
    PMLIB_VIDEOPLL_FEAT_ATTRIBUTES_OF_PARAMS] =
{
    /* PixelClock */
    {1U,        209250000U                 },
    /* RefClock. Should be in range of 0.15 to 52 MHz*/
    {150000U,   52000000U                  },
    /* DcoFrequency. Range of 40 to 280 MHz*/
    {40000000U, 2800000000U                },
    /* Divider value range */
    {1U,        ((uint64_t) 1U << 8U) - 1U },
    /* Multiplier value range */
    {1U,        ((uint64_t) 1U << 11U) - 1U},
    /* hdDivider Range.*/
    {0U,        ((uint64_t) 1U << 5U) - 1U },
};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** Table containing pre calculated values of the divider and multipliers */
const videopllConfig_t gVidPllPreCalcTbl[] =
{
    {116928U, 1637U, 40U, 14U},
    {207900U, 421U,  8U,  8U }
};

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API gets the Video Params
 *        viz multiplier divider and HS Divider
 *
 *  NOTE : The m,n and HS Divider returned from the api may not
 *         be optimal and may have jitter.
 *
 * \param freq            Frequency for which params need to be calculated.
 * \param maxOrMinMN      This parameter allows the API to calculate the
 *                        maximum value of M and N for the given frequency or
 *                        minimum value of M and N for the given frequency.
 *                        0U - Minimum value of M and N.
 *                        1U - Maximum value of M and N.
 * \param pllConf         VideoPll configuration structure.
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *         PM_SUCCESS       Indicates the operation is success
 *         PM_FAIL          Indicates the API failed for desired functionality
 */
static int32_t PmlibVideopllCalculateParams(uint32_t          freq,
                                            uint32_t          maxOrMinMN,
                                            videopllConfig_t *pllConf);

/**
 * \brief This API returns the divider round up value
 *
 * \param n         Values to be rounded off
 * \param d         nearest value to be rounded to.
 *
 * \retval uint32_t value of n rounded to nearest d
 *
 */
static uint32_t PmlibVideopllDivRoundUp(uint32_t n, uint32_t d);

/**
 * \brief This API returns the minimum of two value
 *
 * \param a         input parameter A
 * \param b         input parameter B
 *
 * \retval uint32_t value minimum of A and B
 *
 */
static uint32_t PmlibVideopllMinCalc(uint32_t a, uint32_t b);

/**
 * \brief This API returns the maximum of two value
 *
 * \param a         input parameter A
 * \param b         input parameter B
 *
 * \retval uint32_t value Maximum of A and B
 *
 */
static uint32_t PmlibVideopllMaxCalc(uint32_t a, uint32_t b);

/**
 * \brief This API returns the maximum value of Video pll config params
 *
 * \param index     index of the parameter which is to be got.
 *
 * \retval uint32_t value Maximum of parameter
 *
 */
static uint32_t PmlibVideopllGetParamMax(uint32_t index);

/**
 * \brief This API returns the minimum value of Video pll config params
 *
 * \param index     index of the parameter which is to be got.
 *
 * \retval uint32_t value minimum of parameter
 *
 */
static uint32_t PmlibVideopllGetParamMin(uint32_t index);

/**
 * \brief This API verifies gets the Video Params
 *        viz multiplier
 *
 *  NOTE : The m,n and HS Divider returned from the api may not
 *         be optimal and may have jitter.
 *
 * \param clkin           Input clock frequency.
 * \param refClock        Reference clock frequency after div by N.
 * \param freq            Frequency for which params need to be calculated.
 * \param pllConf         VideoPll configuration structure which is updated.
 * \param maxOrMinMN      This parameter allows the API to calculate the
 *                        maximum value of M and N for the given frequency or
 *                        minimum value of M and N for the given frequency.
 *                        0U - Minimum value of M and N.
 *                        1U - Maximum value of M and N.
 * \param pllDeviation    Deviation from requested frequency and current
 *                        calculated frequency.
 *
 * \retval errorStatus    Status of the API call. Can be any of the following,
 *         PM_SUCCESS     Indicates the operation is success
 *         PM_FAIL        Indicates the API failed for desired functionality
 */
static int32_t PmlibVideopllCalculateM(uint32_t          clkin,
                                       uint32_t          refClock,
                                       uint32_t          freq,
                                       videopllConfig_t *pllConf,
                                       uint32_t          maxOrMinMN,
                                       uint32_t         *pllDeviation);

/**
 * \brief This API verifies gets the Video Params
 *        viz HS Divider
 *
 *  NOTE : The m,n and HS Divider returned from the api may not
 *         be optimal and may have jitter.
 *
 * \param freq            Frequency for which params need to be calculated.
 *
 * \param pllConf         VideoPll configuration structure which is updated.
 *
 * \retval errorStatus    Status of the API call. Can be any of the following,
 *         PM_SUCCESS     Indicates the operation is success
 *         PM_FAIL        Indicates the API failed for desired functionality
 */
static int32_t PmlibVideopllCalculateHSD(uint32_t          clkin,
                                         uint32_t          outputPll,
                                         uint32_t          freq,
                                         videopllConfig_t *pllConf,
                                         uint32_t         *pllDeviation);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PmlibVideopllGetpllStructure(uint32_t               freq,
                                     uint32_t               maxOrMinMN,
                                     pmhalVideopllConfig_t *pVideoPllConfigure)
{
    int32_t          retVal          = PM_FAIL;
    uint32_t         configNum       = 0U;
    videopllConfig_t videoPllConfVal = {0};

    if (NULL != pVideoPllConfigure)
    {
        /* Try searching for the frequency in the pre calculated table*/
        for (configNum = 0U;
             configNum < PM_UTIL_VSIZE_TYPE(gVidPllPreCalcTbl, videopllConfig_t);
             configNum++)
        {
            if (freq == gVidPllPreCalcTbl[configNum].frequency)
            {
                pVideoPllConfigure->multiplier = gVidPllPreCalcTbl[configNum].
                                                 multiplier;
                pVideoPllConfigure->divider =
                    gVidPllPreCalcTbl[configNum].
                    divider;

                pVideoPllConfigure->postDivConfList[0].postDivId =
                    PMHAL_PRCM_DPLL_POST_DIV_M4;
                pVideoPllConfigure->postDivConfList[0].configValue =
                    gVidPllPreCalcTbl[configNum].
                    m2Divider;
                pVideoPllConfigure->postDivConfList[1].postDivId =
                    PMHAL_PRCM_DPLL_POST_DIV_M6;
                pVideoPllConfigure->postDivConfList[1].configValue =
                    gVidPllPreCalcTbl[configNum].m2Divider;
                pVideoPllConfigure->maxPostDivElems =
                    PMLIB_VIDEOPLL_DATA_MAX_POST_DIV_ID;

                retVal = PM_SUCCESS;
                break;
            }
        }

        if (PM_SUCCESS != retVal)
        {
            retVal = PmlibVideopllCalculateParams(freq * 1000U, maxOrMinMN,
                                                  &videoPllConfVal);

            if (PM_SUCCESS == retVal)
            {
                pVideoPllConfigure->multiplier = videoPllConfVal.multiplier;
                pVideoPllConfigure->divider    = videoPllConfVal.divider;

                pVideoPllConfigure->postDivConfList[0].postDivId =
                    PMHAL_PRCM_DPLL_POST_DIV_M4;
                pVideoPllConfigure->postDivConfList[0].configValue =
                    videoPllConfVal.m2Divider;
                pVideoPllConfigure->postDivConfList[1].postDivId =
                    PMHAL_PRCM_DPLL_POST_DIV_M6;
                pVideoPllConfigure->postDivConfList[1].configValue =
                    videoPllConfVal.m2Divider;
                pVideoPllConfigure->maxPostDivElems =
                    PMLIB_VIDEOPLL_DATA_MAX_POST_DIV_ID;
            }
        }
    }
    else
    {
        retVal = PM_BADARGS;
    }
    return retVal;
}

static int32_t PmlibVideopllCalculateParams(uint32_t          freq,
                                            uint32_t          maxOrMinMN,
                                            videopllConfig_t *pllConf)
{
    int32_t  retVal       = PM_VIDEOPLL_CALC_PARAMS_FAILED;
    uint32_t pllDeviation = 999U;
    uint32_t refClockHwMax;
    uint32_t refClockHwMin;
    uint32_t regn, regnStart, regnStop, fractionalFreq;
    uint32_t clkin;
    uint32_t regnMax;
    uint32_t refClock;

    refClockHwMax = PmlibVideopllGetParamMax(PMLIB_VIDEOPLL_FEAT_PARAM_DSS_FINT);
    refClockHwMin = PmlibVideopllGetParamMin(PMLIB_VIDEOPLL_FEAT_PARAM_DSS_FINT);
    regnMax       = PmlibVideopllGetParamMax(PMLIB_VIDEOPLL_FEAT_PARAM_DSS_REGN);
    clkin         = PMHALCMGetSysClockFreq() * 1000U;

    regnStart = PmlibVideopllMaxCalc(
        ((uint32_t) PmlibVideopllGetParamMin(
             PMLIB_VIDEOPLL_FEAT_PARAM_DSS_REGN) + 1U),
        (uint32_t) PmlibVideopllDivRoundUp(clkin, refClockHwMax));

    regnStop = PmlibVideopllMinCalc(clkin / refClockHwMin, regnMax);
    if (NULL != pllConf)
    {
        /* Calculate maximum M and N values for the given frequency */
        if ((uint32_t) maxOrMinMN ==
            (uint32_t) PMLIB_VIDEO_PLL_CALC_MAX_MN)
        {
            /* Iterate over all the possible values of n */
            for (regn = regnStop; regn >= regnStart; regn--)
            {
                if(regn != 0U)
                {
                    /* ref clock for a particular value of N*/
                    refClock = clkin / regn;
                    /* Calculate M and m2Divider values for this N*/
                    retVal = PmlibVideopllCalculateM(clkin,
                                                    refClock,
                                                    freq,
                                                    pllConf,
                                                    maxOrMinMN,
                                                    &pllDeviation);
                    /* If we are able to find multiplier and m2Divider
                    * with deviation less then current, update N*/
                    if (PM_SUCCESS == retVal)
                    {
                        pllConf->divider = regn;
                        retVal           = PM_SUCCESS;
                        if (pllDeviation == 0U)
                        {
                            /* m and n value are obtained
                            * verify its not a fractional value.
                            * if found fractional dont break calculate */
                            fractionalFreq =
                                (((clkin / 1000U) * 2U * pllConf->multiplier) %
                                (pllConf->divider * pllConf->m2Divider));
                            if (fractionalFreq == 0U)
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    retVal = PM_BADARGS;
                }
            }
        }
        else
        {
            /* Calculate minimum M and N values for the given frequency */
            /* Iterate over all the possible values of n */
            for (regn = regnStart; regn <= regnStop; regn++)
            {
                /* ref clock for a particular value of N*/
                refClock = clkin / regn;
                /* Calculate M and m2Divider values for this N*/
                retVal = PmlibVideopllCalculateM(clkin,
                                                 refClock,
                                                 freq,
                                                 pllConf,
                                                 maxOrMinMN,
                                                 &pllDeviation);
                /* If we are able to find multiplier and m2Divider
                 * with deviation less then current, update N*/
                if (PM_SUCCESS == retVal)
                {
                    pllConf->divider = regn;
                    retVal           = PM_SUCCESS;
                    if (pllDeviation == 0U)
                    {
                        /* m and n value are obtained
                         * verify its not a fractional value.
                         * if found fractional dont break calculate */
                        fractionalFreq =
                            (((clkin / 1000U) * 2U * pllConf->multiplier) %
                             (pllConf->divider * pllConf->m2Divider));
                        if (fractionalFreq == 0U)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    else
    {
        retVal = PM_BADARGS;
    }

    return retVal;
}

static int32_t PmlibVideopllCalculateM(uint32_t          clkin,
                                       uint32_t          refClock,
                                       uint32_t          freq,
                                       videopllConfig_t *pllConf,
                                       uint32_t          maxOrMinMN,
                                       uint32_t         *pllDeviation)
{
    int32_t  retVal = PM_VIDEOPLL_CALC_PARAMS_FAILED;
    uint32_t pllMin = PmlibVideopllGetParamMin(
        PMLIB_VIDEOPLL_FEAT_PARAM_DSS_DCOFREQ);
    uint32_t pllMax = PmlibVideopllGetParamMax(
        PMLIB_VIDEOPLL_FEAT_PARAM_DSS_DCOFREQ);
    uint32_t regmMax = PmlibVideopllGetParamMax(
        PMLIB_VIDEOPLL_FEAT_PARAM_DSS_REGM);
    uint32_t regmMin = PmlibVideopllGetParamMin(
        PMLIB_VIDEOPLL_FEAT_PARAM_DSS_REGM);
    uint32_t regmStart, regmStop, regm;
    uint32_t outputPll;

    pllMin = PmlibVideopllMaxCalc(pllMin, freq);
    /* Output should be in the range of 40 to 2800MHz */
    regmStart =
        PmlibVideopllMaxCalc(PmlibVideopllDivRoundUp(PmlibVideopllDivRoundUp(
                                                         pllMin,
                                                         refClock),
                                                     (uint32_t) 2U),
                             regmMin);
    regmStop = PmlibVideopllMinCalc(pllMax / (refClock * 2U), regmMax);
    /* Calculate maximum M and N values for the given frequency */
    if ((uint32_t) maxOrMinMN ==
        (uint32_t) PMLIB_VIDEO_PLL_CALC_MAX_MN)
    {
        /* For each possible value of M, calculate HSD*/
        for (regm = regmStop; regm >= regmStart; regm--)
        {
            outputPll = refClock * 2U * regm;
            /* Calculate m2Divider corrosponding to this value of M */
            retVal = PmlibVideopllCalculateHSD(clkin,
                                               outputPll,
                                               freq,
                                               pllConf,
                                               pllDeviation);
            /* If we m2Divider found with deviation less then the existing,
             * update M*/
            if (PM_SUCCESS == retVal)
            {
                pllConf->multiplier = regm;
                retVal = PM_SUCCESS;
                if (*pllDeviation == 0U)
                {
                    break;
                }
            }
        }
    }
    else
    {
        /* Calculate minimum M and N values for the given frequency */
        /* For each possible value of M, calculate HSD*/
        for (regm = regmStart; regm <= regmStop; regm++)
        {
            outputPll = refClock * 2U * regm;
            /* Calculate m2Divider corrosponding to this value of M */
            retVal = PmlibVideopllCalculateHSD(clkin,
                                               outputPll,
                                               freq,
                                               pllConf,
                                               pllDeviation);
            /* If we m2Divider found with deviation less then the existing,
             * update M*/
            if (PM_SUCCESS == retVal)
            {
                pllConf->multiplier = regm;
                retVal = PM_SUCCESS;
                if (*pllDeviation == 0U)
                {
                    break;
                }
            }
        }
    }
    return retVal;
}

static int32_t PmlibVideopllCalculateHSD(uint32_t          clkin,
                                         uint32_t          outputPll,
                                         uint32_t          freq,
                                         videopllConfig_t *pllConf,
                                         uint32_t         *pllDeviation)
{
    int32_t  retVal = PM_VIDEOPLL_CALC_PARAMS_FAILED;
    uint32_t hsdStart, hsdStop, hsd, deviation;
    uint32_t outMax = PmlibVideopllGetParamMax(
        PMLIB_VIDEOPLL_FEAT_PARAM_DSS_PCLK);
    uint32_t outMin = PmlibVideopllGetParamMin(
        PMLIB_VIDEOPLL_FEAT_PARAM_DSS_PCLK);
    hsdStart = PmlibVideopllMaxCalc(
        outputPll / outMax,
        PmlibVideopllGetParamMin(PMLIB_VIDEOPLL_FEAT_PARAM_DSS_HSDIV));
    hsdStop = PmlibVideopllMinCalc(
        outputPll / outMin,
        PmlibVideopllGetParamMax(PMLIB_VIDEOPLL_FEAT_PARAM_DSS_HSDIV));
    /* Calculate the HS Divider required for output PLL*/
    hsd       = outputPll / freq;
    deviation = outputPll - (freq * hsd);
    /* If the deviation is less then the current deviation, update the
     *m2Divider, M and N*/
    if ((deviation < *pllDeviation) || (deviation == 0U))
    {
        *pllDeviation      = outputPll - (freq * hsd);
        pllConf->m2Divider = hsd;
        /* m2Divider should be in the required range*/

        if ((pllConf->m2Divider < hsdStop) && (pllConf->m2Divider > hsdStart))
        {
            retVal = PM_SUCCESS;
        }
    }
    return retVal;
}

static uint32_t PmlibVideopllDivRoundUp(uint32_t n, uint32_t d)
{
    return (((n + d) - 1U) / d);
}

static uint32_t PmlibVideopllMinCalc(uint32_t a, uint32_t b)
{
    return ((a) > (b) ? (b) : (a));
}

static uint32_t PmlibVideopllMaxCalc(uint32_t a, uint32_t b)
{
    return ((a) > (b) ? (a) : (b));
}

static uint32_t PmlibVideopllGetParamMin(uint32_t index)
{
    uint32_t retval = 0;
    if (index < PMLIB_VIDEOPLL_FEAT_NUMBER_OF_PARAMS)
    {
        retval = (uint32_t) gPmlibPllMinmMaxVal[index][0];
    }
    return retval;
}

static uint32_t PmlibVideopllGetParamMax(uint32_t index)
{
    uint32_t retval = 0;
    if (index < PMLIB_VIDEOPLL_FEAT_NUMBER_OF_PARAMS)
    {
        retval = (uint32_t) gPmlibPllMinmMaxVal[index][1];
    }
    return retval;
}

