/* ============================================================= */
/**
 *  file:  hw_usb_depcmd.h
 *
 *  Register-level header file for USBDEPCMD
 *
 *  ============================================================
 *  Copyright (c) Texas Instruments Incorporated 2015i-2016
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


#ifndef HW_USB_DEPCMD_H_
#define HW_USB_DEPCMD_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG                                 (0x4U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG                                 (0x8U)
#define DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG                             (0x18U)
#define DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER                            (0x24U)
#define DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER                            (0x28U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_SHIFT                                       (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_MASK                                        (0x0000001fU)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_INT0                                         (0U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_SHIFT                                    (8U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_MASK                                     (0x00000100U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_DIS                                       (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_EN                                        (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_SHIFT                                  (9U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_MASK                                   (0x00000200U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_DIS                                     (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_EN                                      (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_SHIFT                                    (10U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_MASK                                     (0x00000400U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_DIS                                       (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_EN                                        (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_SHIFT                                 (11U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_MASK                                  (0x00000800U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_DIS                                    (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_EN                                     (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_SHIFT                                   (13U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_MASK                                    (0x00002000U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_DIS                                      (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_EN                                       (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_BINTERVAL_M1_SHIFT                                  (16U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_BINTERVAL_M1_MASK                                   (0x00ff0000U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_SHIFT                                       (24U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_MASK                                        (0x01000000U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_NOTCAP                                       (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_CAP                                          (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_SHIFT                                   (25U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_MASK                                    (0x02000000U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_OUT                                      (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_IN                                       (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER_SHIFT                                      (26U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER_MASK                                       (0x3c000000U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_SHIFT                                     (30U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_MASK                                      (0x40000000U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_DEFAULT                                    (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_BBISOC                                     (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_SHIFT                            (31U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_MASK                             (0x80000000U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_DISABLED                          (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_ENABLED                           (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_SHIFT                         (15U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_MASK                          (0x00008000U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_DIS                            (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_EBC                            (1U)

#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_SHIFT                                        (1U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_MASK                                         (0x00000006U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_CTRL                                          (0U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_ISOC                                          (1U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_BULK                                          (2U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_INT                                           (3U)

#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS_SHIFT                                           (3U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS_MASK                                            (0x00003ff8U)

#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM_SHIFT                                       (17U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM_MASK                                        (0x003e0000U)

#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_SHIFT                                       (22U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_MASK                                        (0x03c00000U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_MIN                                          (0U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_MAX                                          (15U)

#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_DSEQNUM_SHIFT                                       (26U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_DSEQNUM_MASK                                        (0x7c000000U)

#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_SHIFT                                  (31U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_MASK                                   (0x80000000U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_RESET                                   (0U)
#define DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_IGNORE                                  (1U)

#define DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_SHIFT                                (0U)
#define DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_MASK                                 (0x0000ffffU)
#define DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_ONE                                   (1U)

#define DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER_TDADDR_LOW_SHIFT                               (0U)
#define DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER_TDADDR_LOW_MASK                                (0xffffffffU)

#define DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER_TDADDR_HIGH_SHIFT                              (0U)
#define DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER_TDADDR_HIGH_MASK                               (0xffffffffU)

#ifdef __cplusplus
}
#endif
#endif  /* HW_USB_DEPCMD_H_ */

