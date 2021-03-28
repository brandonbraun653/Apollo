/**
 *   @file  csl_emif4.h
 *
 *   @brief
 *      This is the main header file for the EMIF4F Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2013, Texas Instruments, Inc.
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

/** @defgroup CSL_EMIF4D5_API EMIF4F
 *
 * @section Introduction
 *  The External Memory Interface (EMIF) is a TI developed re-usable IP component
 *  targeted for SOC designs. The EMIF is a VBUSM slave peripheral providing an
 *  interface to a wide variety of DDR SDRAM. This memory controller is a soft
 *  macro and must be used with the DDR PHY hard macros to interface to the
 *  DDR SDRAM.
 *
 * @subsection References
 *   -# EMIF4F Functional Specification
 */

#ifndef CSL_EMIF4D5_V2_H_
#define CSL_EMIF4D5_V2_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/src/ip/emif4/V2/cslr_emif4d5.h>

/**
@defgroup CSL_EMIF4D5_SYMBOL  EMIF4F Symbols Defined
@ingroup CSL_EMIF4D5_API
*/
/**
@defgroup CSL_EMIF4D5_DATASTRUCT  EMIF4F Data Structures
@ingroup CSL_EMIF4D5_API
*/
/**
@defgroup CSL_EMIF4D5_FUNCTION  EMIF4F Functions
@ingroup CSL_EMIF4D5_API
*/

/**
@addtogroup CSL_EMIF4D5_SYMBOL
@{
*/

/**
@}
*/

/** @addtogroup CSL_EMIF4D5_DATASTRUCT
 @{ */

/** @brief EMIF4D5 DDR configuration parameters
 *
 * This structure is used to define the EMIF4D5 DDR Configuration Parameters
 */
typedef struct
{
    /**< DDR phy control register value. */
    Uint32 ddrPhyCtrl;
    /**< SDRAM timing1 register value. */
    Uint32 sdramTim1;
    /**< SDRAM timing2 register value. */
    Uint32 sdramTim2;
    /**< SDRAM timing3 register value. */
    Uint32 sdramTim3;
    /**< SDRAM config register value. */
    Uint32 sdramCfg;
    /**< SDRAM config register value. */
    Uint32 sdramCfg2;
    /**< SDRAM ref control register value. */
    Uint32 sdramRefCtrl;
    /**< ZQ config register value. */
    Uint32 zqConfig;
    /**< SDRAM timing3 register value. */
    Uint32 sdramPwrMngtCtrl;
}CSL_emifDdrParam;

/** @brief EMIF4D5 DDR PHY configuration parameters
 *
 * This structure is used to define the EMIF4D5 DDR PHY Configuration Parameters
 */
typedef struct
{
    /**< Use RANKo delay. */
    Uint32 ctrlSlaveRatio;
    /**< Write DQS slave ratio. */
    Uint32 gateLevelRatio;
    /**< Write DQS slave ratio. */
    Uint32 writeLevelInitRatio;
    /**< Write DQS slave ratio. */
    Uint32 writeDqsSlaveRatio;
    /**< FIFO write enable slave ratio. */
    Uint32 fifoWeSlaveRatio;
    /**< Use RANKo delay. */
    Uint32 useRank0Delays;
    /**< FIFO write enable slave ratio. */
    Uint32 fifoWeInDelay;
    /**< Use RANKo delay. */
    Uint32 ctrlSlaveDelay;
    /**< Write DQS slave ratio. */
    Uint32 readDqsSlaveDelay;
    /**< Write DQS slave ratio. */
    Uint32 writeDqsSlaveDelay;
    /**< FIFO write enable slave ratio. */
    Uint32 dqOffset;
    /**< Use RANKo delay. */
    Uint32 gateLevelInitMode;
    /**< Use RANKo delay. */
    Uint32 writeDataSlaveDelay;
    /**< Write DQS slave ratio. */
    Uint32 gateLevelNumDq0;
    /**< Write DQS slave ratio. */
    Uint32 writeLevelNumDq0;
}CSL_emifDdrPhyParam;

/** @brief EMIF4D5 DDR Configuration
 *
 * This structure is used to define the EMIF4D5 DDR Configuration
 */
typedef struct
{
    CSL_emifDdrParam    emifDdrParam;
    /**< DDR Emif config registers. */
    CSL_emifDdrPhyParam emifDdrPhyParam;
    /**< EMIF phy config registers. */
}CSL_emifDdrConfig;

typedef volatile CSL_Emif4d5Regs             *CSL_emifRegsOvly;

/**
 * @brief EMIF module interface Structure.
 */
typedef struct
{
    /** Pointer to the register overlay structure of the EMIF */
    CSL_emifRegsOvly regs;
} CSL_emifObj;

/**
 * @brief This data type is used to return the handle to the CSL of the EMIF
 */
typedef CSL_emifObj *CSL_emifHandle;

/* @} */

/** @addtogroup CSL_EMIF4D5_FUNCTION
 @{ */

/* @} */


#ifdef __cplusplus
}
#endif
#endif /* CSL_EMIF4D5_V2_H_ */
