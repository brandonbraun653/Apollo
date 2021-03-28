/*
 * Copyright (C) 2002-2015 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
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
 *   @file  csl_emac.h
 *
 *   PATH:  \$(CSLPATH)\\inc
 *
 *   @brief  EMAC CSL Implementation on DSP side
 *
 *  NOTE:
 *   When used in an multitasking environment, no EMAC function may be
 *   called while another EMAC function is operating on the same device
 *   handle in another thread. It is the responsibility of the application
 *   to assure adherence to this restriction.
 *
 */

/* =============================================================================
 *  Revision History
 *  ===============
 *  07-Oct-05 XXX File created
 *  14-Mar-06 PSK Added multi core support
 *  22-May-07 PSK Removed multi core support to support new SoC
 *  16-July-2008 Update for Doxygen
 * =============================================================================
 */

/** @defgroup CSL_EMAC_API EMAC
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * The Ethernet Media Access Controller (EMAC) module provides an interface
 * between the C6457 DSP core processor and the networked community. The EMAC
 * supports 10Base-T (10 Mbits/second [Mbps]), and 100BaseTX (100 Mbps), in
 * either half- or full-duplex mode, and 1000BaseT (1000 Mbps) in full-duplex
 * mode, with hardware flow control and quality-of-service (QOS) support. There
 * are two ports of EMAC on C6457 DSP. The EMAC module conforms to the IEEE
 * 802.3-2002 standard, describing the "Carrier Sense Multiple Access with
 * Collision Detection (CSMA/CD) Access Method and Physical Layer"
 * specifications. The IEEE 802.3 standard has also been adopted by ISO/IEC and
 * re-designated as ISO/IEC 8802-3:2000(E). Deviation from this standard, the
 * EMAC module does not use the Transmit Coding Error signal MTXER. Instead of
 * driving the error pin when an underflow condition occurs on a transmitted
 * frame, the EMAC will intentionally generate an incorrect checksum by
 * inverting the frame CRC, so that the transmitted frame will be detected as
 * an error by the network.
 *
 * The EMAC control module is the main interface between the device core
 * processor, the MDIO module, and the EMAC module. The EMAC control module
 * contains the necessary components to allow the EMAC to make efficient use of
 * device memory, plus it controls device interrupts. The EMAC control module
 * incorporates 8K-bytes of internal RAM to hold EMAC buffer descriptors.
 *
 * @subsection References
 *   -# EMAC/MDIO User's Guide SPRUFC4.pdf (May 2008)
 *
 * @subsection Assumptions
 *    The abbreviations EMAC, emac and Emac have been used throughout this
 *    document to refer to Ethernet Media Access Controller and MDIO or mdio
 *    or Mdio refer to Management Data Input/Output.
 */

#ifndef CSL_EMAC_TOP_H
#define CSL_EMAC_TOP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>
#include <ti/csl/tistdtypes.h>

#if defined (SOC_C6657) || defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
#include <ti/csl/src/ip/emac/V3/csl_emac.h>
#endif

#ifdef __cplusplus
}
#endif
#endif


