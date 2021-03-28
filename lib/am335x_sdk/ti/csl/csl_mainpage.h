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
 *   \file  csl/csl_mainpage.h
 *
 *   \brief  This file contains the main page doxygen details for CSL
 *
 */

/**
 * \mainpage  Chip Support Library
 *
 * \par IMPORTANT NOTE
 *   <b>
 *   The interfaces defined in this package are bound to change.
 *   Kindly treat the interfaces as work in progress.
 *   Release notes/user guide list the additional limitation/restriction
 *   of this module/interfaces.
 *   </b> See also \ref TI_DISCLAIMER.
 *
 *
 * Chip Support Library(CSL) provides a no-OS platform support for
 * multi-core SoCs. CSL provides CSL Functional Layer (CSL-FL) libraries and
 * CSL Register Layer (CSL-R) along with peripheral/board level sample/demo
 * examples that demonstrate the capabilities of the peripherals.
 *
 * <b>
 * Also refer to top level user guide for detailed features,
 * limitations and usage description.
 * </b>
 *
 * <b>
 * The below listed is a superset of all the CSL-FL modules,
 * for certain SDK release, it may include only a subset of these modules.
 * </b>
 *
 * The CSL-FL includes the following modules/drivers
 * - <b> HW Type Defines </b> (See \ref HW_TYPES) <br>
 *  In-line functions required to read/write values from/to the hardware registers
 *
 * - <b> IP's </b> <br>
 *     - <b> Video Module</b> <br>
 *         - <b> DSS </b> (See \ref CSL_DSS) <br>
 *     - <b> System Module</b> <br>
 *         - <b> EDMA </b> (See \ref CSL_EDMA) <br>
 *         - <b> EPWM </b> (See \ref CSL_EPWM) <br>
 *         - <b> GPIO </b> (See \ref CSL_GPIO) <br>
 *         - <b> Mailbox </b> (See \ref CSL_MAILBOX) <br>
 *         - <b> MMU </b> (See \ref CSL_MMU) <br>
 *         - <b> Spinlock </b> (See \ref CSL_SPINLOCK) <br>
 *         - <b> Timer </b> (See \ref CSL_TIMER) <br>
 *         - <b> WD Timer </b> (See \ref CSL_WD_TIMER) <br>
 *     - <b> Safety/Security Module</b> <br>
 *         - <b> ADC </b> (See \ref CSL_ADC) <br>
 *         - <b> CRC </b> (See \ref CSL_CRC) <br>
 *         - <b> DCC </b> (See \ref CSL_DCC) <br>
 *         - <b> ESM </b> (See \ref CSL_ESM) <br>
 *         - <b> L4 Firewall </b> (See \ref CSL_L3_FIREWALL) <br>
 *         - <b> L4 Firewall </b> (See \ref CSL_L4_FIREWALL) <br>
 *         - <b> Tesoc </b> (See \ref CSL_TESOC) <br>
 *         - <b> RTI </b> (See \ref CSL_RTI) <br>
 *     - <b> Serial Module</b> <br>
 *         - <b> DCAN </b> (See \ref CSL_DCAN) <br>
 *         - <b> I2C </b> (See \ref CSL_I2C) <br>
 *         - <b> MCAN </b> (See \ref CSL_MCAN) <br>
 *         - <b> McSPI </b> (See \ref CSL_MCSPI) <br>
 *         - <b> QSPI </b> (See \ref CSL_QSPI) <br>
 *         - <b> UART </b> (See \ref CSL_UART) <br>
 *         - <b> PCIe </b> (See \ref CSL_PCIE) <br>
 *     - <b> Memory Controller</b> <br>
 *         - <b> EMIF </b> (See \ref CSL_EMIF) <br>
 *         - <b> GPMC </b> (See \ref CSL_GPMC) <br>
 *         - <b> OCMC </b> (See \ref CSL_IP_MODULE_OCMC) <br>
 *     - <b> Memory/Storage</b> <br>
 *         - <b> MMCSD </b> (See \ref CSL_MMCSD) <br>
 *
 * - <b> SOC Module </b> <br>
 *  This Module contain the SOC level configuration API's such as cross bar configuration, cross bar defines, SOC defines
 *     - <b> Device Common API's</b> (See \ref CSL_DEVICE_COMMON) <br>
 *     - <b> TDA2EX</b> (See \ref SOC_TDA2EX) <br>
 *     - <b> TDA2PX</b> (See \ref SOC_TDA2PX) <br>
 *     - <b> TDA2XX</b> (See \ref SOC_TDA2XX) <br>
 *     - <b> TDA3XX</b> (See \ref SOC_TDA3XX) <br>
 *
 * - <b> ARCH Module </b> <br>
 *  This Module contain the core specific configuration API's such as Interrupt, Cache, ECC
 *     - <b> A15</b> (See \ref CSL_ARCH_A15) <br>
 *     - <b> A53</b> (See \ref CSL_A53_API) <br>
 *     - <b> R5 Core </b> (See \ref CSL_ARM_R5_API) <br>
 *     - <b> R5 CCM </b> (See \ref CSL_MCU_ARMSS_CCMR5_API) <br>
 *     - <b> R5 VIM </b> (See \ref CSL_VIM_API) <br>
 *     - <b> DSP-C66x</b> (See \ref CSL_ARCH_C66X) <br>
 *     - <b> M4</b> (See \ref CSL_ARCH_M4) <br>
 *     - <b> EVE</b> (See \ref CSL_ARCH_ARP32) <br>
 */

/**
 *  \page  TI_DISCLAIMER  TI Disclaimer
 *
 *  \htmlinclude docs/ti_disclaim.htm
 */
