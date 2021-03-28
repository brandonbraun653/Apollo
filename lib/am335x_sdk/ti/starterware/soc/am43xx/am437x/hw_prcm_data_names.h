/**
 *  @file      hw_prcm_data_names.h
 *
 *  @brief     This file contains macros to select module names.
 *              
 *  @warning   This file is auto generated. So avoid manual changes. 
 *              If manual changes are required the implications of the 
 *              change in this and other auto generated files has to be 
 *              completely understood.
 */

/* Copyright (c) 2013 Texas Instruments Inc - http://www.ti.com */

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


#ifndef HW_PRCM_DATA_NAMES_H 
#define HW_PRCM_DATA_NAMES_H

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */
#include "hw_prcm_data.h"


/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/*
 * Macros for internal use
 */
#define IS_ENUM_INRANGE_(en, id) \
    ( (en##_MIN <= (id)) && ((id) < en##_MAX) )

#define CALC_ENUM_OFFSET_(en, id) \
    (IS_ENUM_INRANGE_(en, (id))? (id) - en##_MIN: en##_UNDEF)

#define NAME_(x)  #x

#ifdef NDEBUG
  #define GET_ENUM_NAME_(en, id) "[name is only available in debug mode (NDEBUG=0)"
  #define GET_NODE_NAME_(en, id) "[name is only available in debug mode (NDEBUG=0)"

#else 
  /* Name vector for PRCM elements */
  #define VNAME_PRCM_VD_        {voltageDomainList.type}_names 
  #define VNAME_PRCM_PD_        {powerDomainList.type}_names 
  #define VNAME_PRCM_CLK_       {clockList.type}_names 
  #define VNAME_PRCM_RG_        {resetGroupList.type}_names 
  #define VNAME_PRCM_RESET_     {resetList.type}_names 
  #define VNAME_PRCM_MEM_       {physicalMemoryList.type}_names 
  #define VNAME_PRCM_NODE_      {nodeList.type}_names 
  #define VNAME_PRCM_ROOT_CLK_  VNAME_PRCM_NODE_
  #define VNAME_PRCM_MUX_       VNAME_PRCM_NODE_
  #define VNAME_PRCM_DIV_       VNAME_PRCM_NODE_
  #define VNAME_PRCM_DPLL_      VNAME_PRCM_NODE_
  #define VNAME_PRCM_MOD_       VNAME_PRCM_NODE_

  /* Minimum index of vector for PRCM elements */
  #define VMIN_PRCM_VD_         PRCM_VD_MIN
  #define VMIN_PRCM_PD_         PRCM_PD_MIN
  #define VMIN_PRCM_CLK_        PRCM_CLK_MIN
  #define VMIN_PRCM_RG_         PRCM_RG_MIN
  #define VMIN_PRCM_RESET_      PRCM_RESET_MIN
  #define VMIN_PRCM_MEM_        PRCM_MEM_MIN
  #define VMIN_PRCM_NODE_       PRCM_NODE_MIN
  #define VMIN_PRCM_ROOT_CLK_   VMIN_PRCM_NODE_ 
  #define VMIN_PRCM_MUX_        VMIN_PRCM_NODE_
  #define VMIN_PRCM_DIV_        VMIN_PRCM_NODE_
  #define VMIN_PRCM_DPLL_       VMIN_PRCM_NODE_
  #define VMIN_PRCM_MOD_        VMIN_PRCM_NODE_

  #define GET_ENUM_NAME_(en, id) \n    (IS_##en? VNAME_##en##_[ (id) - VMIN_##en##_]: NAME_(en##_UNDEF))

#endif /* NDEBUG */

/*
 * Macros to confirm membership of a group
 */
#define IS_PRCM_VD(id)               IS_ENUM_INRANGE_(PRCM_VD, id)
#define IS_PRCM_PD(id)               IS_ENUM_INRANGE_(PRCM_PD, id)
#define IS_PRCM_CD(id)               IS_ENUM_INRANGE_(PRCM_CD, id)
#define IS_PRCM_CLK(id)              IS_ENUM_INRANGE_(PRCM_CLK, id)
#define IS_PRCM_MUX(id)              IS_ENUM_INRANGE_(PRCM_MUX, id)
#define IS_PRCM_DIV(id)              IS_ENUM_INRANGE_(PRCM_DIV, id)
#define IS_PRCM_ROOT_CLK(id)         IS_ENUM_INRANGE_(PRCM_ROOT_CLK, id)
#define IS_PRCM_DPLL(id)             IS_ENUM_INRANGE_(PRCM_DPLL, id)
#define IS_PRCM_MOD(id)              IS_ENUM_INRANGE_(PRCM_MOD, id)
#define IS_PRCM_NODE(id)             (IS_ENUM_INRANGE_(PRCM_NODE, id) || IS_ENUM_INRANGE_(PRCM_MOD))

/*
 * Macros to calculate offset within a group
 */
#define GET_PRCM_VD_OFFSET(id)       CALC_ENUM_OFFSET_(PRCM_VD, id)
#define GET_PRCM_PD_OFFSET(id)       CALC_ENUM_OFFSET_(PRCM_PD, id)
#define GET_PRCM_CD_OFFSET(id)       CALC_ENUM_OFFSET_(PRCM_CD, id)
#define GET_PRCM_CLK_OFFSET(id)      CALC_ENUM_OFFSET_(PRCM_CLK, id)
#define GET_PRCM_ROOT_CLK_OFFSET(id) CALC_ENUM_OFFSET_(PRCM_ROOT_CLK, id)
#define GET_PRCM_MUX_OFFSET(id)      CALC_ENUM_OFFSET_(PRCM_MUX, id)
#define GET_PRCM_DIV_OFFSET(id)      CALC_ENUM_OFFSET_(PRCM_DIV, id)
#define GET_PRCM_DPLL_OFFSET(id)     CALC_ENUM_OFFSET_(PRCM_DPLL, id)
#define GET_PRCM_MOD_OFFSET(id)      CALC_ENUM_OFFSET_(PRCM_MOD, id)

/*
 * Macros to determine name of the given ID.
 * Note: Enabled only in debug mode
 */
#define PRCM_GET_VD_NAME(id)        GET_ENUM_NAME_(PRCM_VD, id)
#define PRCM_GET_PD_NAME(id)        GET_ENUM_NAME_(PRCM_PD, id)
#define PRCM_GET_CD_NAME(id)        GET_ENUM_NAME_(PRCM_CD, id)
#define PRCM_GET_CLK_NAME(id)       GET_ENUM_NAME_(PRCM_CLK, id)
#define PRCM_GET_ROOT_CLK_NAME(id)  GET_NODE_NAME_(PRCM_ROOT_CLK, id) 
#define PRCM_GET_MUX_NAME(id)       GET_NODE_NAME_(PRCM_MUX, id) 
#define PRCM_GET_DIV_NAME(id)       GET_NODE_NAME_(PRCM_DIV, id) 
#define PRCM_GET_DPLL_NAME(id)      GET_NODE_NAME_(PRCM_DPLL, id) 
#define PRCM_GET_MOD_NAME(id)       GET_NODE_NAME_(PRCM_MOD, id) 
#define PRCM_GET_NODE_NAME(id)      GET_NODE_NAME_(PRCM_NODE, id)  

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/* ========================================================================== */
/*                        Global Variables Declarations                       */
/* ========================================================================== */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern const char *prcmVoltageDomain_t_names[PRCM_VD_MAX + 1];
extern const char *prcmPowerDomain_t_names[PRCM_PD_MAX + 1];
extern const char *prcmClkDomain_t_names[PRCM_CD_MAX + 1];
extern const char *clockList_names[PRCM_CLK_MAX + 1];
extern const char *resetGroupList_names[PRCM_RG_MAX + 1];
extern const char *resetList_names[PRCM_RST_MAX + 1];
extern const char *prcmPhysicalMemory_t_names[PRCM_PHY_MEM_MAX + 1];
extern const char *nodeList_names[PRCM_MOD_MAX + 1];

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

#endif /* HW_PRCM_DATA_NAMES_H */

