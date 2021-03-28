/*  ============================================================================
 *  Copyright (c) Texas Instruments Incorporated 2019
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
/** ============================================================================
 *   \file  csl2_mainpage.h
 *
 *   \brief  This file contains the main page doxygen details for CSL2
 *
 */

/**
 * \mainpage  Chip Support Library
 *
 * \par IMPORTANT NOTE
 *   <b>
 *   Release notes/user guide list the additional limitation/restriction
 *   of this module/interfaces.
 *   </b> See also \ref TI_DISCLAIMER.
 *
 *
 * The Chip Support Library (CSL) provides low-level hardware abstraction
 * software and API to configure and control different parts of the SoC.
 * The Chip Support Library constitutes a set of well-defined API that abstract
 * low-level details of the underlying SoC device so that a user can configure,
 * control (start/stop, etc.) and have read/write access to peripherals without
 * having to worry about register bit-field details.
 * The CSL services are implemented as distinct modules that correspond with
 * the underlying SoC device modules themselves.
 * By design, CSL API follow a consistent style, uniformly across different
 * processor architectures and are independent of the Operating System.
 * This helps in improving portability of code written using the CSL.
 *
 * CSL is realized as twin-layer – a basic register-layer and a more abstracted
 * functional-layer. The lower register layer comprises of a very basic set of
 * macros and type definitions. The upper functional layer comprises of “C” 
 * functions that provide an increased degree of abstraction, but intended to
 * provide “directed” control of underlying hardware.
 *
 * It is important to note that CSL does not manage data-movement over underlying
 * hardware devices. Such functionality is considered a prerogative of a
 * device-driver and serious effort is made to not blur the boundary between
 * device-driver and CSL services in this regard.
 * Device drivers are written on top of the CSL.
 *
 * CSL does not model the device state machine. However, should there exist a
 * mandatory sequence of register reads/writes dictated by the hardware,
 * CSL does indeed support services for such operations.
 *
 * The CSL services are decomposed into modules, each following the twin-layer
 * of abstraction described above. The API of each such module are completely
 * orthogonal (one module’s API does not internally call API of another module)
 * and do not allocate memory dynamically from within. This is key to keeping
 * CSL scalable to fit various usage scenarios.
 *
 * <b>
 * Please refer to top level Software User Guide and Release Notes for detailed
 * features, limitations and usage description.
 * </b>
 *
 *
 * The CSL-FL includes the following modules/drivers
 * - <b> HW Type Defines </b> (See \ref HW_TYPES) <br>
 *  In-line functions required to read/write values from/to the hardware registers
 *
 * - <b> IP's </b> <br>
 *     - <b> Safety/Security Module</b> <br>
 *         - <b> ECC AGGREGATOR </b> (See \ref CSL_ECC_AGGR_API) <br>
 *         - <b> ESM </b> (See \ref CSL_ESM_API) <br>
 *         - <b> CRC </b> (See \ref CSL_CRC_API) <br>
 *         - <b> CBASS ERROR </b> (See \ref CSL_CBASS_ERR_API) <br>
 *         - <b> CBASS QOS </b> (See \ref CSL_CBASS_QOS_API) <br>
 *         - <b> RTI </b> (See \ref CSL_RTI) <br>
 *         - <b> TIMER </b> (See \ref CSL_TIMER) <br>
 *
 * - <b> ARCH Module </b> <br>
 *  This Module contain the core specific configuration API's such as Interrupt, Cache, ECC
 *     - <b> R5 MPU </b> (See \ref CSL_ARM_R5_MPU_API) <br>
 *     - <b> R5 Hard Error Cache </b> (See \ref CSL_ARM_R5_HARD_ERR_CACHE_API) <br>
 *     - <b> R5 PMU </b> (See \ref CSL_ARM_R5_PMU_API) <br>
 *     - <b> R5 CCM </b> (See \ref CSL_MCU_ARMSS_CCMR5_API) <br>
 *     - <b> R5 VIM </b> (See \ref CSL_VIM_API) <br>
 *     - <b> R5 RAT </b> (See \ref CSL_RAT_API) <br>
 */

/**
 *  \page  TI_DISCLAIMER  TI Disclaimer
 *
 *  \htmlinclude ti_disclaim.htm
 */
