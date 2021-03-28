/**
 *  \file  dss_coefficients.c
 *
 *  \brief This file contains the default coefficient values of
 *         color space conversion and video resizer(up and down sampling)
 *         corresponding to the display controller.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "dss.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Color space conversion default coefficient values. */
const dssDispcCscCoeff_t CSCCOEFF_DEFAULT =
    {298, 409, 0, 298, -208, -100, 298, 0, 17, 0};


/** \brief Default values of Horizontal up sampling coefficients of
           video resizer. */
const dssDispcHorzResizeCoeff_t
    HORZUPSAMPLECOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES] = {
    {  0,   0, 128,   0,  0 },
    { -1,  13, 124,  -8,  0 },
    { -2,  30, 112, -11, -1 },
    { -5,  51,  95, -11, -2 },
    {  0,  -9,  73,  73, -9 },
    { -2, -11,  95,  51, -5 },
    { -1, -11, 112,  30, -2 },
    {  0,  -8, 124,  13, -1 },
};


/** \brief Default values of Vertical up sampling coefficients in 3 tap
           configuration of video resizer. */
const dssDispcVertResizeCoeff_t
    VERTUPSAMPLE3TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES] = {
    { 0,  0, 128,  0, 0 },
    { 0,  3, 123,  2, 0 },
    { 0, 12, 111,  5, 0 },
    { 0, 32,  89,  7, 0 },
    { 0,  0,  64, 64, 0 },
    { 0,  7,  89, 32, 0 },
    { 0,  5, 111, 12, 0 },
    { 0,  2, 123,  3, 0 },
};


/** \brief Default values of Vertical up sampling coefficients in 5 tap
           configuration of video resizer. */
const dssDispcVertResizeCoeff_t
    VERTUPSAMPLE5TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES] = {
    {  0,   0, 128,   0,  0 },
    { -1,  13, 124,  -8,  0 },
    { -2,  30, 112, -11, -1 },
    { -5,  51,  95, -11, -2 },
    {  0,  -9,  73,  73, -9 },
    { -2, -11,  95,  51, -5 },
    { -1, -11, 112,  30, -2 },
    {  0,  -8, 124,  13, -1 },
};


/** \brief Default values of Horizontal down sampling coefficients of
           video resizer. */
const dssDispcHorzResizeCoeff_t
    HORZDOWNSAMPLECOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES] = {
    {   0, 36, 56, 36,  0 },
    {   4, 40, 55, 31, -2 },
    {   8, 44, 54, 27, -5 },
    {  12, 48, 53, 22, -7 },
    {  -9, 17, 52, 51, 17 },
    {  -7, 22, 53, 48, 12 },
    {  -5, 27, 54, 44,  8 },
    {  -2, 31, 55, 40,  4 },
};


/** \brief Default values of Vertical down sampling coefficients in 3 tap
           configuration of video resizer. */
const dssDispcVertResizeCoeff_t
    VERTDOWNSAMPLE3TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES] = {
    { 0, 36, 56, 36, 0 },
    { 0, 40, 57, 31, 0 },
    { 0, 45, 56, 27, 0 },
    { 0, 50, 55, 23, 0 },
    { 0, 18, 55, 55, 0 },
    { 0, 23, 55, 50, 0 },
    { 0, 27, 56, 45, 0 },
    { 0, 31, 57, 40, 0 },
};


/** \brief Default values of Vertical down sampling coefficients in 5 tap
           configuration of video resizer. */
const dssDispcVertResizeCoeff_t
    VERTDOWNSAMPLE5TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES] = {
    {   0, 36, 56, 36,  0 },
    {   4, 40, 55, 31, -2 },
    {   8, 44, 54, 27, -5 },
    {  12, 48, 53, 22, -7 },
    {  -9, 17, 52, 51, 17 },
    {  -7, 22, 53, 48, 12 },
    {  -5, 27, 54, 44,  8 },
    {  -2, 31, 55, 40,  4 },
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* None */
