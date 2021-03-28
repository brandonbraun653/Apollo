/**
 *   @file  csl_emif4a.h
 *
 *   @brief
 *      This is the main header file for the EMIF4F Module which defines
 *      all the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
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

/** @defgroup CSL_EMIF4F_API EMIF4F
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

#ifndef CSL_EMIF4A_H_
#define CSL_EMIF4A_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_emif4f.h>

/**
@defgroup CSL_EMIF4F_SYMBOL  EMIF4F Symbols Defined
@ingroup CSL_EMIF4F_API
*/
/**
@defgroup CSL_EMIF4F_DATASTRUCT  EMIF4F Data Structures
@ingroup CSL_EMIF4F_API
*/
/**
@defgroup CSL_EMIF4F_FUNCTION  EMIF4F Functions
@ingroup CSL_EMIF4F_API
*/

/**
@addtogroup CSL_EMIF4F_SYMBOL
@{
*/

/**
 *  Handle to access EMIF4F registers accessible through config bus.
 */
#define hEmif     ((CSL_EmifaRegs*)CSL_EMIFA_0_REGS)

/**
@}
*/

/** @addtogroup CSL_EMIF4F_DATASTRUCT
 @{ */

/** @brief This is the handle to the MPU Register */
typedef volatile CSL_EmifaRegs*   CSL_Emif4fHandle;

/** @brief EMIF4F SDRAM Configuration
 *
 * This structure is used to define the EMIF4F SDRAM
 * Configuration
 */
typedef struct EMIF4F_SDRAM_CONFIG
{
    Uint8   sr;
    Uint8   pd;
    Uint8   pdwr;
    Uint8   nm;
    Uint8   cl;
    Uint8   bit11_9Lock;
    Uint8   iBank;
    Uint8   eBank;
    Uint8   pageSize;

    Uint8   NVMEnable;
    Uint8   eBankPos;
    Uint8   rdbNum;
    Uint8   rdbSize;
}EMIF4F_SDRAM_CONFIG;

/** @brief EMIF4F Asynchronous1 Configuration
 *
 * This structure is used to define the EMIF4F Asynchronous1
 * Configuration
 */
typedef struct EMIF4F_ASYNC1_CONFIG
{
	Uint8	ss;
    Uint8   ew;
    Uint8   w_setup;
    Uint8   w_strobe;
    Uint8   w_hold;
    Uint8   r_setup;
    Uint8   r_strobe;
	Uint8   r_hold;
    Uint8   ta;
    Uint8   aSize;
}EMIF4F_ASYNC1_CONFIG;

/** @brief EMIF4F Asynchronous2 Configuration
 *
 * This structure is used to define the EMIF4F Asynchronous2
 * Configuration
 */
typedef struct EMIF4F_ASYNC2_CONFIG
{
	Uint8	ss;
    Uint8   ew;
    Uint8   w_setup;
    Uint8   w_strobe;
    Uint8   w_hold;
    Uint8   r_setup;
    Uint8   r_strobe;
	Uint8   r_hold;
    Uint8   ta;
    Uint8   aSize;
}EMIF4F_ASYNC2_CONFIG;

/** @brief EMIF4F Asynchronous3 Configuration
 *
 * This structure is used to define the EMIF4F Asynchronous3
 * Configuration
 */
typedef struct EMIF4F_ASYNC3_CONFIG
{
	Uint8	ss;
    Uint8   ew;
    Uint8   w_setup;
    Uint8   w_strobe;
    Uint8   w_hold;
    Uint8   r_setup;
    Uint8   r_strobe;
	Uint8   r_hold;
    Uint8   ta;
    Uint8   aSize;
}EMIF4F_ASYNC3_CONFIG;

/** @brief EMIF4F Asynchronous4 Configuration
 *
 * This structure is used to define the EMIF4F Asynchronous4
 * Configuration
 */
typedef struct EMIF4F_ASYNC4_CONFIG
{
	Uint8	ss;
    Uint8   ew;
    Uint8   w_setup;
    Uint8   w_strobe;
    Uint8   w_hold;
    Uint8   r_setup;
    Uint8   r_strobe;
	Uint8   r_hold;
    Uint8   ta;
    Uint8   aSize;
}EMIF4F_ASYNC4_CONFIG;

/** @brief EMIF4F Timing Configuration
 *
 * This structure is used to define the EMIF4F Timing
 * Configuration
 */
typedef struct EMIF4F_TIMING_CONFIG
{
	Uint8	t_rfc;
    Uint8   t_rp;
    Uint8   t_rcd;
    Uint8   t_wr;
    Uint8   t_ras;
    Uint8   t_rc;
    Uint8   t_rrd;
}EMIF4F_TIMING_CONFIG;

/** @brief EMIF4F NANDFCR Configuration
 *
 * This structure is used to define the EMIF4F NANDFCR
 * Configuration
 */

typedef struct EMIF4F_NANDFCR_CONFIG
{
    Uint8   biteccAddCalcStart;
    Uint8   biteccStart;
    Uint16  cs5ecc;
    Uint16  cs4ecc;
    Uint8   cs3ecc;
    Uint8   cs2ecc;
	Uint16  bitEccSel;
    Uint16  cs5nand;
    Uint8   cs3nand;
    Uint8   cs2nand;
}EMIF4F_NANDFCR_CONFIG;


/** @brief NAND Flash Status
 *
 * This structure is used to define the NAND Flash Status
 */
typedef struct EMIF4F_NANDFSR_STAT
{
    Uint8   eccErrNum;
    Uint8   eccState;
    Uint8   waitst;
}EMIF4F_NANDFSR_STAT;

/** @brief NAND Flash 1 ECC Register
 *
 * This structure is used to define the NAND Flash 1 ECC Register
 */
typedef struct EMIF4F_NANDF1ECC_REG
{
    Uint8   p2048o;
    Uint8   p1204o;
    Uint8   p512o;
    Uint8   p256o;
    Uint8   p128o;
    Uint8   p64o;
    Uint8   p32o;
	Uint8   p16o;
    Uint8   p8o;
    Uint8   p4o;
    Uint8   p2o;
    Uint8   p1o;
    Uint8   p2948e;
    Uint8   p102e;
	Uint8   p512e;
    Uint8   p256e;
	Uint8   p128e;
    Uint8   p64e;
	Uint8   p32e;
    Uint8   p16e;
	Uint8   p8e;
    Uint8   p4e;
	Uint8   p2e;
	Uint8   p1e;
}EMIF4F_NANDF1ECC_REG;

/** @brief NAND Flash 2 ECC Register
 *
 * This structure is used to define the NAND Flash 2 ECC Register
 */
typedef struct EMIF4F_NANDF2ECC_REG
{
    Uint8   p2048o;
    Uint8   p1204o;
    Uint8   p512o;
    Uint8   p256o;
    Uint8   p128o;
    Uint8   p64o;
    Uint8   p32o;
	Uint8   p16o;
    Uint8   p8o;
    Uint8   p4o;
    Uint8   p2o;
    Uint8   p1o;
    Uint8   p2948e;
    Uint8   p102e;
	Uint8   p512e;
    Uint8   p256e;
	Uint8   p128e;
    Uint8   p64e;
	Uint8   p32e;
    Uint8   p16e;
	Uint8   p8e;
    Uint8   p4e;
	Uint8   p2e;
	Uint8   p1e;
}EMIF4F_NANDF2ECC_REG;

/** @brief NAND Flash 3 ECC Register
 *
 * This structure is used to define the NAND Flash 3 ECC Register
 */
typedef struct EMIF4F_NANDF3ECC_REG
{
    Uint8   p2048o;
    Uint8   p1204o;
    Uint8   p512o;
    Uint8   p256o;
    Uint8   p128o;
    Uint8   p64o;
    Uint8   p32o;
	Uint8   p16o;
    Uint8   p8o;
    Uint8   p4o;
    Uint8   p2o;
    Uint8   p1o;
    Uint8   p2948e;
    Uint8   p102e;
	Uint8   p512e;
    Uint8   p256e;
	Uint8   p128e;
    Uint8   p64e;
	Uint8   p32e;
    Uint8   p16e;
	Uint8   p8e;
    Uint8   p4e;
	Uint8   p2e;
	Uint8   p1e;
}EMIF4F_NANDF3ECC_REG;

/** @brief NAND Flash 4 ECC Register
 *
 * This structure is used to define the NAND Flash 4 ECC Register
 */
typedef struct EMIF4F_NANDF4ECC_REG
{
    Uint8   p2048o;
    Uint8   p1204o;
    Uint8   p512o;
    Uint8   p256o;
    Uint8   p128o;
    Uint8   p64o;
    Uint8   p32o;
	Uint8   p16o;
    Uint8   p8o;
    Uint8   p4o;
    Uint8   p2o;
    Uint8   p1o;
    Uint8   p2948e;
    Uint8   p102e;
	Uint8   p512e;
    Uint8   p256e;
	Uint8   p128e;
    Uint8   p64e;
	Uint8   p32e;
    Uint8   p16e;
	Uint8   p8e;
    Uint8   p4e;
	Uint8   p2e;
	Uint8   p1e;
}EMIF4F_NANDF4ECC_REG;

/** @brief NAND Flash 4-Bit ECC LOAD Register
 *
 * This structure is used to define the NAND Flash 4-Bit ECC LOAD Register.
 */
typedef struct EMIF4F_NAND4BITECCLOAD_REG
{
    Uint16  bitEccLoad;
}EMIF4F_NAND4BITECCLOAD_REG;

/** @brief NAND Flash 4-Bit ECC Register 1
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Register 1
 */
typedef struct EMIF4F_NAND4BITECC1_REG
{
    Uint16 bitEccVal2;
	Uint16 bitEccVal1;
}EMIF4F_NAND4BITECC1_REG;

/** @brief NAND Flash 4-Bit ECC Register 2
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Register 2
 */
typedef struct EMIF4F_NAND4BITECC2_REG
{
    Uint16 bitEccVal4;
	Uint16 bitEccVal3;
}EMIF4F_NAND4BITECC2_REG;

/** @brief NAND Flash 4-Bit ECC Register 3
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Register 3
 */
typedef struct EMIF4F_NAND4BITECC3_REG
{
    Uint16 bitEccVal6;
	Uint16 bitEccVal5;
}EMIF4F_NAND4BITECC3_REG;

/** @brief NAND Flash 4-Bit ECC Register 4
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Register 4
 */
typedef struct EMIF4F_NAND4BITECC4_REG
{
    Uint16 bitEccVal8;
	Uint16 bitEccVal7;
}EMIF4F_NAND4BITECC4_REG;

/** @brief NAND Flash 4-Bit ECC Error Address Register 1
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Error Address Register 1
 */
typedef struct EMIF4F_NANDERRADD1_REG
{
    Uint16 bitEccErrAdd2;
	Uint16 bitEccErrAdd1;
}EMIF4F_NANDERRADD1_REG;

/** @brief NAND Flash 4-Bit ECC Error Address Register 2
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Error Address Register 2
 */
typedef struct EMIF4F_NANDERRADD2_REG
{
    Uint16 bitEccErrAdd4;
	Uint16 bitEccErrAdd3;
}EMIF4F_NANDERRADD2_REG;

/** @brief NAND Flash 4-Bit ECC Error Value Register 1
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Error Value Register 1
 */
typedef struct EMIF4F_NANDERRVAL1_VALUE
{
    Uint16 bitEccErrVal2;
	Uint16 bitEccErrVal1;
}EMIF4F_NANDERRADD1_VALUE;

/** @brief NAND Flash 4-Bit ECC Error Value Register 2
 *
 * This structure is used to define the NAND Flash 4-Bit ECC Error Value Register 2
 */
typedef struct EMIF4F_NANDERRVAL2_VALUE
{
    Uint16 bitEccErrVal4;
	Uint16 bitEccErrVal3;
}EMIF4F_NANDERRADD2_VALUE;


/* @} */

/** @addtogroup CSL_EMIF4F_FUNCTION
 @{ */

/* @} */


#ifdef __cplusplus
}
#endif
#endif /* CSL_EMIF4F_H_ */
