/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_BB2D_H_
#define CSLR_BB2D_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 AQHICLOCKCONTROL;
    volatile Uint32 AQHIIDLE;
    volatile Uint32 AQAXICONFIG;
    volatile Uint32 AQAXISTATUS;
    volatile Uint32 AQINTRACKNOWLEDGE;
    volatile Uint32 AQINTRENBL;
    volatile Uint32 AQIDENT;
    volatile Uint32 GCFEATURES;
    volatile Uint32 GCCHIPID;
    volatile Uint32 GCCHIPREV;
    volatile Uint32 GCCHIPDATE;
    volatile Uint32 GCCHIPTIME;
    volatile Uint32 GCCHIPCUSTOMER;
    volatile Uint32 GCMINORFEATURES0;
    volatile Uint8  RSVD0[4];
    volatile Uint32 GCRESETMEMCOUNTERS;
    volatile Uint32 GCTOTALREADS;
    volatile Uint32 GCTOTALWRITES;
    volatile Uint32 GCCHIPSPECS;
    volatile Uint32 GCTOTALWRITEBURSTS;
    volatile Uint32 GCTOTALWRITEREQS;
    volatile Uint32 GCTOTALWRITELASTS;
    volatile Uint32 GCTOTALREADBURSTS;
    volatile Uint32 GCTOTALREADREQS;
    volatile Uint32 GCTOTALREADLASTS;
    volatile Uint32 GCGPOUT0;
    volatile Uint32 GCGPOUT1;
    volatile Uint32 GCGPOUT2;
    volatile Uint32 GCAXICONTROL;
    volatile Uint32 GCMINORFEATURES1;
    volatile Uint32 GCTOTALCYCLES;
    volatile Uint32 GCTOTALIDLECYCLES;
    volatile Uint32 GCCHIPSPECS2;
    volatile Uint32 GCMINORFEATURES2;
    volatile Uint8  RSVD1[120];
    volatile Uint32 GCMODULEPOWERCONTROLS;
    volatile Uint32 GCMODULEPOWERMODULECONTROL;
    volatile Uint32 GCMODULEPOWERMODULESTATUS;
    volatile Uint8  RSVD2[124];
    volatile Uint32 GCREGMMUSTATUS;
    volatile Uint32 GCREGMMUCONTROL;
    volatile Uint32 GCREGMMUEXCEPTION0;
    volatile Uint32 GCREGMMUEXCEPTION1;
    volatile Uint32 GCREGMMUEXCEPTION2;
    volatile Uint32 GCREGMMUEXCEPTION3;
    volatile Uint8  RSVD3[628];
    volatile Uint32 AQMEMORYDEBUG;
    volatile Uint8  RSVD4[20];
    volatile Uint32 AQREGISTERTIMINGCONTROL;
    volatile Uint32 GCMEMORYRESERVED;
    volatile Uint32 GCDISPLAYPRIORITY;
    volatile Uint32 GCDBGCYCLECOUNTER;
    volatile Uint32 GCOUTSTANDINGREADS0;
    volatile Uint32 GCOUTSTANDINGREADS1;
    volatile Uint32 GCOUTSTANDINGWRITES;
    volatile Uint32 GCDEBUGSIGNALSRA;
    volatile Uint32 GCDEBUGSIGNALSTX;
    volatile Uint32 GCDEBUGSIGNALSFE;
    volatile Uint32 GCDEBUGSIGNALSPE;
    volatile Uint32 GCDEBUGSIGNALSDE;
    volatile Uint32 GCDEBUGSIGNALSSH;
    volatile Uint32 GCDEBUGSIGNALSPA;
    volatile Uint32 GCDEBUGSIGNALSSE;
    volatile Uint32 GCDEBUGSIGNALSMC;
    volatile Uint32 GCDEBUGSIGNALSHI;
    volatile Uint32 GCDEBUGCONTROL0;
    volatile Uint32 GCDEBUGCONTROL1;
    volatile Uint32 GCDEBUGCONTROL2;
    volatile Uint32 GCDEBUGCONTROL3;
    volatile Uint32 GCBUSCONTROL;
    volatile Uint32 GCREGENDIANNESS0;
    volatile Uint32 GCREGENDIANNESS1;
    volatile Uint32 GCREGENDIANNESS2;
    volatile Uint32 GCREGDRAWPRIMITIVESTARTTIMESTAMP;
    volatile Uint32 GCREGDRAWPRIMITIVEENDTIMESTAMP;
    volatile Uint8  RSVD5[192];
    volatile Uint32 GCREGCONTROL0;
    volatile Uint8  RSVD6[248];
    volatile Uint32 AQCMDBUFFERADDR;
    volatile Uint32 AQCMDBUFFERCTRL;
    volatile Uint32 AQFESTATUS;
    volatile Uint32 AQFEDEBUGSTATE;
    volatile Uint32 AQFEDEBUGCURCMDADR;
    volatile Uint32 AQFEDEBUGCMDLOWREG;
    volatile Uint32 AQFEDEBUGCMDHIREG;
} CSL_Bb2dRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Description: Clock control register. */
#define CSL_BB2D_AQHICLOCKCONTROL                               (0x0U)

/* Description: Idle status register. */
#define CSL_BB2D_AQHIIDLE                                       (0x4U)

/* Description: */
#define CSL_BB2D_AQAXICONFIG                                    (0x8U)

/* Description: */
#define CSL_BB2D_AQAXISTATUS                                    (0xCU)

/* Description: Interrupt acknowledge register. Each bit represents a
 * corresponding event being triggered. Reading frmo this register clears the
 * outstanding interrupt. */
#define CSL_BB2D_AQINTRACKNOWLEDGE                              (0x10U)

/* Description: Interrupt enable register. Each bit enables a corresponding
 * event. */
#define CSL_BB2D_AQINTRENBL                                     (0x14U)

/* Description: Identification register. This register has no set reset value.
 * It varies with the implementation. */
#define CSL_BB2D_AQIDENT                                        (0x18U)

/* Description: Shows which features are enabled in this chip. This register
 * has no set reset value. It varies with the implementation. 0 => NONE 1 =>
 * AVAILABLE */
#define CSL_BB2D_GCFEATURES                                     (0x1CU)

/* Description: Shows the ID for the chip in BCD. This register has no set
 * reset value. It varies with the implementation. */
#define CSL_BB2D_GCCHIPID                                       (0x20U)

/* Description: Shows the revision for the chip in BCD. This register has no
 * set reset value. It varies with the implementation. */
#define CSL_BB2D_GCCHIPREV                                      (0x24U)

/* Description: Shows the release date for the IP. This register has no set
 * reset value. It varies with the implementation. */
#define CSL_BB2D_GCCHIPDATE                                     (0x28U)

/* Description: Shows the release time for the IP. This register has no set
 * reset value. It varies with the implementation. */
#define CSL_BB2D_GCCHIPTIME                                     (0x2CU)

/* Description: Shows the customer and group for the IP. This register has no
 * set reset value. It varies with the implementation. */
#define CSL_BB2D_GCCHIPCUSTOMER                                 (0x30U)

/* Description: Shows which minor features are enabled in this chip. This
 * register has no set reset value. It varies with the implementation. 0 =>
 * NONE 1 => AVAILABLE */
#define CSL_BB2D_GCMINORFEATURES0                               (0x34U)

/* Description: Writing 1 will reset the counters and stop counting. Write 0
 * to start counting again. This register is write only so it has no reset
 * value. */
#define CSL_BB2D_GCRESETMEMCOUNTERS                             (0x3CU)

/* Description: Total reads in terms of 64bits. */
#define CSL_BB2D_GCTOTALREADS                                   (0x40U)

/* Description: Total writes in terms of 64bits. */
#define CSL_BB2D_GCTOTALWRITES                                  (0x44U)

/* Description: Specs for the chip. This register has no set reset value. It
 * varies with the implementation. */
#define CSL_BB2D_GCCHIPSPECS                                    (0x48U)

/* Description: Total write Data Count in terms of 64bits. This register has
 * no reset value. */
#define CSL_BB2D_GCTOTALWRITEBURSTS                             (0x4CU)

/* Description: Total write Request Count. This register has no reset value. */
#define CSL_BB2D_GCTOTALWRITEREQS                               (0x50U)

/* Description: Total WLAST Count. This is used to match with
 * GCTotalWriteReqs. This register has no reset value. */
#define CSL_BB2D_GCTOTALWRITELASTS                              (0x54U)

/* Description: Total Read Data Count in terms of 64bits. This register has no
 * reset value. */
#define CSL_BB2D_GCTOTALREADBURSTS                              (0x58U)

/* Description: Total Read Request Count. This register has no reset value. */
#define CSL_BB2D_GCTOTALREADREQS                                (0x5CU)

/* Description: Total RLAST Count. This is used to match with GCTotalReadReqs.
 * This register has no reset value. */
#define CSL_BB2D_GCTOTALREADLASTS                               (0x60U)

/* Description: General Purpose output register. R/W but not connected to
 * anywhere */
#define CSL_BB2D_GCGPOUT0                                       (0x64U)

/* Description: General Purpose output register. R/W but not connected to
 * anywhere */
#define CSL_BB2D_GCGPOUT1                                       (0x68U)

/* Description: General Purpose output register. R/W but not connected to
 * anywhere */
#define CSL_BB2D_GCGPOUT2                                       (0x6CU)

/* Description: Special Handling on AXI Bus */
#define CSL_BB2D_GCAXICONTROL                                   (0x70U)

/* Description: Shows which features are enabled in this chip. This register
 * has no set reset value. It varies with the implementation. 0 => NONE 1 =>
 * AVAILABLE */
#define CSL_BB2D_GCMINORFEATURES1                               (0x74U)

/* Description: Total cycles. This register is a free running counter. It can
 * be reset by writing 0 to it. */
#define CSL_BB2D_GCTOTALCYCLES                                  (0x78U)

/* Description: Total cycles where the GPU is idle. It is reset when
 * gcTotalCycles register is written to. It looks at all the blocks but FE
 * when determining the IP is idle. */
#define CSL_BB2D_GCTOTALIDLECYCLES                              (0x7CU)

/* Description: Specs for the chip. This register has no set reset value. It
 * varies with the implementation. */
#define CSL_BB2D_GCCHIPSPECS2                                   (0x80U)

/* Description: Shows which features are enabled in this chip. This register
 * has no set reset value. It varies with the implementation. 0 => NONE 1 =>
 * AVAILABLE */
#define CSL_BB2D_GCMINORFEATURES2                               (0x84U)

/* Description: Control register for module level power controls. */
#define CSL_BB2D_GCMODULEPOWERCONTROLS                          (0x100U)

/* Description: Module level control registers. */
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL                     (0x104U)

/* Description: Module level control status */
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS                      (0x108U)

/* Description: Status register that holds which MMU generated an exception */
#define CSL_BB2D_GCREGMMUSTATUS                                 (0x188U)

/* Description: Control register that enables the MMU (only time shot). */
#define CSL_BB2D_GCREGMMUCONTROL                                (0x18CU)

/* Description: Holds the original address that generated an exception */
#define CSL_BB2D_GCREGMMUEXCEPTION0                             (0x190U)

/* Description: Holds the original address that generated an exception */
#define CSL_BB2D_GCREGMMUEXCEPTION1                             (0x194U)

/* Description: Holds the original address that generated an exception */
#define CSL_BB2D_GCREGMMUEXCEPTION2                             (0x198U)

/* Description: Holds the original address that generated an exception */
#define CSL_BB2D_GCREGMMUEXCEPTION3                             (0x19CU)

/* Description: */
#define CSL_BB2D_AQMEMORYDEBUG                                  (0x414U)

/* Description: */
#define CSL_BB2D_AQREGISTERTIMINGCONTROL                        (0x42CU)

/* Description: This is reserved for future expansion. */
#define CSL_BB2D_GCMEMORYRESERVED                               (0x430U)

/* Description: Controls the priority of the display controller requests. This
 * works like a PWM. One register gives the period, and the other gives the ON
 * time. When PWM is ON, display requests are accepted if both display and the
 * other request is valid. If it is OFF, the other request will be accepted.
 * If only one request is valid, it takes the bus regardless of the PWM bit. */
#define CSL_BB2D_GCDISPLAYPRIORITY                              (0x434U)

/* Description: Increments every cycle. */
#define CSL_BB2D_GCDBGCYCLECOUNTER                              (0x438U)

/* Description: Number of outstanding reads per client in multiples of 8B. */
#define CSL_BB2D_GCOUTSTANDINGREADS0                            (0x43CU)

/* Description: Number of outstanding reads per client in multiples of 8B. */
#define CSL_BB2D_GCOUTSTANDINGREADS1                            (0x440U)

/* Description: Number of outstanding writes per client. */
#define CSL_BB2D_GCOUTSTANDINGWRITES                            (0x444U)

/* Description: 32 bit debug signal from Ra. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSRA                               (0x448U)

/* Description: 32 bit debug signal from Tx. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSTX                               (0x44CU)

/* Description: 32 bit debug signal from Fe. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSFE                               (0x450U)

/* Description: 32 bit debug signal from Pe. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSPE                               (0x454U)

/* Description: 32 bit debug signal from De. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSDE                               (0x458U)

/* Description: 32 bit debug signal from Sh. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSSH                               (0x45CU)

/* Description: 32 bit debug signal from Pa. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSPA                               (0x460U)

/* Description: 32 bit debug signal from Se. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSSE                               (0x464U)

/* Description: 32 bit debug signal from Mc. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSMC                               (0x468U)

/* Description: 32 bit debug signal from Hi. This register has no reset value. */
#define CSL_BB2D_GCDEBUGSIGNALSHI                               (0x46CU)

/* Description: */
#define CSL_BB2D_GCDEBUGCONTROL0                                (0x470U)

/* Description: */
#define CSL_BB2D_GCDEBUGCONTROL1                                (0x474U)

/* Description: */
#define CSL_BB2D_GCDEBUGCONTROL2                                (0x478U)

/* Description: */
#define CSL_BB2D_GCDEBUGCONTROL3                                (0x47CU)

/* Description: Shows which features are enabled in this chip. This register
 * has no set reset value. It varies with the implementation. 0 => NONE 1 =>
 * AVAILABLE */
#define CSL_BB2D_GCBUSCONTROL                                   (0x480U)

/* Description: */
#define CSL_BB2D_GCREGENDIANNESS0                               (0x484U)

/* Description: */
#define CSL_BB2D_GCREGENDIANNESS1                               (0x488U)

/* Description: */
#define CSL_BB2D_GCREGENDIANNESS2                               (0x48CU)

/* Description: */
#define CSL_BB2D_GCREGDRAWPRIMITIVESTARTTIMESTAMP               (0x490U)

/* Description: */
#define CSL_BB2D_GCREGDRAWPRIMITIVEENDTIMESTAMP                 (0x494U)

/* Description: Composition trigger. */
#define CSL_BB2D_GCREGCONTROL0                                  (0x558U)

/* Description: Base address for the command buffer. The address must be
 * 64-bit aligned and it is always physical. To use addresses above
 * 0x8000_0000, program AQMemoryFE with the appropriate offset. Also, this
 * register cannot be read. To check the value of the current fetch address
 * use AQFEDebugCurCmdAdr. Since this is a write only register is has no reset
 * value. */
#define CSL_BB2D_AQCMDBUFFERADDR                                (0x654U)

/* Description: Since this is a write only register is has no reset value. */
#define CSL_BB2D_AQCMDBUFFERCTRL                                (0x658U)

/* Description: */
#define CSL_BB2D_AQFESTATUS                                     (0x65CU)

/* Description: Reserved. */
#define CSL_BB2D_AQFEDEBUGSTATE                                 (0x660U)

/* Description: This is the command decoder address. The address is always
 * physical so the MSB should always be 0. It has no reset value. */
#define CSL_BB2D_AQFEDEBUGCURCMDADR                             (0x664U)

/* Description: Reserved. No reset value */
#define CSL_BB2D_AQFEDEBUGCMDLOWREG                             (0x668U)

/* Description: Reserved. No reset value */
#define CSL_BB2D_AQFEDEBUGCMDHIREG                              (0x66CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* AQHICLOCKCONTROL */

#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_MASK  (0x00000400U)
#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_SHIFT  (10U)
#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_MAX  (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_IDLE2_D_MASK                  (0x00020000U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE2_D_SHIFT                 (17U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE2_D_RESETVAL              (0x00000001U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE2_D_MAX                   (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT_MASK    (0x00F00000U)
#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT_SHIFT   (20U)
#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_REG_SELECT_MAX     (0x0000000fU)

#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI_MASK  (0x0F000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI_SHIFT  (24U)
#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_MULTI_PIPE_USE_SINGLE_AXI_MAX  (0x0000000fU)

#define CSL_BB2D_AQHICLOCKCONTROL_IDLE3_D_MASK                  (0x00010000U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE3_D_SHIFT                 (16U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE3_D_RESETVAL              (0x00000001U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE3_D_MAX                   (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_ISOLATE_GPU_MASK              (0x00080000U)
#define CSL_BB2D_AQHICLOCKCONTROL_ISOLATE_GPU_SHIFT             (19U)
#define CSL_BB2D_AQHICLOCKCONTROL_ISOLATE_GPU_RESETVAL          (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_ISOLATE_GPU_MAX               (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_CLK3D_DIS_MASK                (0x00000001U)
#define CSL_BB2D_AQHICLOCKCONTROL_CLK3D_DIS_SHIFT               (0U)
#define CSL_BB2D_AQHICLOCKCONTROL_CLK3D_DIS_RESETVAL            (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_CLK3D_DIS_MAX                 (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_CLK2D_DIS_MASK                (0x00000002U)
#define CSL_BB2D_AQHICLOCKCONTROL_CLK2D_DIS_SHIFT               (1U)
#define CSL_BB2D_AQHICLOCKCONTROL_CLK2D_DIS_RESETVAL            (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_CLK2D_DIS_MAX                 (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_VAL_MASK               (0x000001FCU)
#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_VAL_SHIFT              (2U)
#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_VAL_RESETVAL           (0x00000040U)
#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_VAL_MAX                (0x0000007fU)

#define CSL_BB2D_AQHICLOCKCONTROL_IDLE_VG_MASK                  (0x00040000U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE_VG_SHIFT                 (18U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE_VG_RESETVAL              (0x00000001U)
#define CSL_BB2D_AQHICLOCKCONTROL_IDLE_VG_MAX                   (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_MASK          (0x00000200U)
#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_SHIFT         (9U)
#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_RESETVAL      (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_MAX           (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_MASK  (0x00000800U)
#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_SHIFT  (11U)
#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_MAX   (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_SOFT_RESET_MASK               (0x00001000U)
#define CSL_BB2D_AQHICLOCKCONTROL_SOFT_RESET_SHIFT              (12U)
#define CSL_BB2D_AQHICLOCKCONTROL_SOFT_RESET_RESETVAL           (0x00000000U)
#define CSL_BB2D_AQHICLOCKCONTROL_SOFT_RESET_MAX                (0x00000001U)

#define CSL_BB2D_AQHICLOCKCONTROL_RESETVAL                      (0x00070100U)

/* AQHIIDLE */

#define CSL_BB2D_AQHIIDLE_IDLE_FP_MASK                          (0x00000400U)
#define CSL_BB2D_AQHIIDLE_IDLE_FP_SHIFT                         (10U)
#define CSL_BB2D_AQHIIDLE_IDLE_FP_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_FP_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_PA_MASK                          (0x00000010U)
#define CSL_BB2D_AQHIIDLE_IDLE_PA_SHIFT                         (4U)
#define CSL_BB2D_AQHIIDLE_IDLE_PA_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_PA_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_PE_MASK                          (0x00000004U)
#define CSL_BB2D_AQHIIDLE_IDLE_PE_SHIFT                         (2U)
#define CSL_BB2D_AQHIIDLE_IDLE_PE_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_PE_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_UNUSED_MASK                           (0x7FFFF000U)
#define CSL_BB2D_AQHIIDLE_UNUSED_SHIFT                          (12U)
#define CSL_BB2D_AQHIIDLE_UNUSED_RESETVAL                       (0x0007ffffU)
#define CSL_BB2D_AQHIIDLE_UNUSED_MAX                            (0x0007ffffU)

#define CSL_BB2D_AQHIIDLE_IDLE_SE_MASK                          (0x00000020U)
#define CSL_BB2D_AQHIIDLE_IDLE_SE_SHIFT                         (5U)
#define CSL_BB2D_AQHIIDLE_IDLE_SE_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_SE_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_IM_MASK                          (0x00000200U)
#define CSL_BB2D_AQHIIDLE_IDLE_IM_SHIFT                         (9U)
#define CSL_BB2D_AQHIIDLE_IDLE_IM_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_IM_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_AXI_LP_MASK                           (0x80000000U)
#define CSL_BB2D_AQHIIDLE_AXI_LP_SHIFT                          (31U)
#define CSL_BB2D_AQHIIDLE_AXI_LP_RESETVAL                       (0x00000000U)
#define CSL_BB2D_AQHIIDLE_AXI_LP_MAX                            (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_TS_MASK                          (0x00000800U)
#define CSL_BB2D_AQHIIDLE_IDLE_TS_SHIFT                         (11U)
#define CSL_BB2D_AQHIIDLE_IDLE_TS_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_TS_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_VG_MASK                          (0x00000100U)
#define CSL_BB2D_AQHIIDLE_IDLE_VG_SHIFT                         (8U)
#define CSL_BB2D_AQHIIDLE_IDLE_VG_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_VG_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_RA_MASK                          (0x00000040U)
#define CSL_BB2D_AQHIIDLE_IDLE_RA_SHIFT                         (6U)
#define CSL_BB2D_AQHIIDLE_IDLE_RA_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_RA_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_SH_MASK                          (0x00000008U)
#define CSL_BB2D_AQHIIDLE_IDLE_SH_SHIFT                         (3U)
#define CSL_BB2D_AQHIIDLE_IDLE_SH_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_SH_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_TX_MASK                          (0x00000080U)
#define CSL_BB2D_AQHIIDLE_IDLE_TX_SHIFT                         (7U)
#define CSL_BB2D_AQHIIDLE_IDLE_TX_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_TX_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_FE_MASK                          (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_FE_SHIFT                         (0U)
#define CSL_BB2D_AQHIIDLE_IDLE_FE_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_FE_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_IDLE_DE_MASK                          (0x00000002U)
#define CSL_BB2D_AQHIIDLE_IDLE_DE_SHIFT                         (1U)
#define CSL_BB2D_AQHIIDLE_IDLE_DE_RESETVAL                      (0x00000001U)
#define CSL_BB2D_AQHIIDLE_IDLE_DE_MAX                           (0x00000001U)

#define CSL_BB2D_AQHIIDLE_RESETVAL                              (0x7fffffffU)

/* AQAXICONFIG */

#define CSL_BB2D_AQAXICONFIG_ARCACHE_MASK                       (0x0000F000U)
#define CSL_BB2D_AQAXICONFIG_ARCACHE_SHIFT                      (12U)
#define CSL_BB2D_AQAXICONFIG_ARCACHE_RESETVAL                   (0x00000000U)
#define CSL_BB2D_AQAXICONFIG_ARCACHE_MAX                        (0x0000000fU)

#define CSL_BB2D_AQAXICONFIG_AWCACHE_MASK                       (0x00000F00U)
#define CSL_BB2D_AQAXICONFIG_AWCACHE_SHIFT                      (8U)
#define CSL_BB2D_AQAXICONFIG_AWCACHE_RESETVAL                   (0x00000000U)
#define CSL_BB2D_AQAXICONFIG_AWCACHE_MAX                        (0x0000000fU)

#define CSL_BB2D_AQAXICONFIG_AWID_MASK                          (0x0000000FU)
#define CSL_BB2D_AQAXICONFIG_AWID_SHIFT                         (0U)
#define CSL_BB2D_AQAXICONFIG_AWID_RESETVAL                      (0x00000000U)
#define CSL_BB2D_AQAXICONFIG_AWID_MAX                           (0x0000000fU)

#define CSL_BB2D_AQAXICONFIG_ARID_MASK                          (0x000000F0U)
#define CSL_BB2D_AQAXICONFIG_ARID_SHIFT                         (4U)
#define CSL_BB2D_AQAXICONFIG_ARID_RESETVAL                      (0x00000000U)
#define CSL_BB2D_AQAXICONFIG_ARID_MAX                           (0x0000000fU)

#define CSL_BB2D_AQAXICONFIG_RESETVAL                           (0x00000000U)

/* AQAXISTATUS */

#define CSL_BB2D_AQAXISTATUS_WR_ERR_ID_MASK                     (0x0000000FU)
#define CSL_BB2D_AQAXISTATUS_WR_ERR_ID_SHIFT                    (0U)
#define CSL_BB2D_AQAXISTATUS_WR_ERR_ID_RESETVAL                 (0x00000000U)
#define CSL_BB2D_AQAXISTATUS_WR_ERR_ID_MAX                      (0x0000000fU)

#define CSL_BB2D_AQAXISTATUS_DET_WR_ERR_MASK                    (0x00000100U)
#define CSL_BB2D_AQAXISTATUS_DET_WR_ERR_SHIFT                   (8U)
#define CSL_BB2D_AQAXISTATUS_DET_WR_ERR_RESETVAL                (0x00000000U)
#define CSL_BB2D_AQAXISTATUS_DET_WR_ERR_MAX                     (0x00000001U)

#define CSL_BB2D_AQAXISTATUS_DET_RD_ERR_MASK                    (0x00000200U)
#define CSL_BB2D_AQAXISTATUS_DET_RD_ERR_SHIFT                   (9U)
#define CSL_BB2D_AQAXISTATUS_DET_RD_ERR_RESETVAL                (0x00000000U)
#define CSL_BB2D_AQAXISTATUS_DET_RD_ERR_MAX                     (0x00000001U)

#define CSL_BB2D_AQAXISTATUS_RD_ERR_ID_MASK                     (0x000000F0U)
#define CSL_BB2D_AQAXISTATUS_RD_ERR_ID_SHIFT                    (4U)
#define CSL_BB2D_AQAXISTATUS_RD_ERR_ID_RESETVAL                 (0x00000000U)
#define CSL_BB2D_AQAXISTATUS_RD_ERR_ID_MAX                      (0x0000000fU)

#define CSL_BB2D_AQAXISTATUS_RESETVAL                           (0x00000000U)

/* AQINTRACKNOWLEDGE */

#define CSL_BB2D_AQINTRACKNOWLEDGE_INTR_VEC_MASK                (0xFFFFFFFFU)
#define CSL_BB2D_AQINTRACKNOWLEDGE_INTR_VEC_SHIFT               (0U)
#define CSL_BB2D_AQINTRACKNOWLEDGE_INTR_VEC_RESETVAL            (0x00000000U)
#define CSL_BB2D_AQINTRACKNOWLEDGE_INTR_VEC_MAX                 (0xffffffffU)

#define CSL_BB2D_AQINTRACKNOWLEDGE_RESETVAL                     (0x00000000U)

/* AQINTRENBL */

#define CSL_BB2D_AQINTRENBL_INTR_ENBL_VEC_MASK                  (0xFFFFFFFFU)
#define CSL_BB2D_AQINTRENBL_INTR_ENBL_VEC_SHIFT                 (0U)
#define CSL_BB2D_AQINTRENBL_INTR_ENBL_VEC_RESETVAL              (0x00000000U)
#define CSL_BB2D_AQINTRENBL_INTR_ENBL_VEC_MAX                   (0xffffffffU)

#define CSL_BB2D_AQINTRENBL_RESETVAL                            (0x00000000U)

/* AQIDENT */

#define CSL_BB2D_AQIDENT_PRODUCT_MASK                           (0x00FF0000U)
#define CSL_BB2D_AQIDENT_PRODUCT_SHIFT                          (16U)
#define CSL_BB2D_AQIDENT_PRODUCT_RESETVAL                       (0x00000001U)
#define CSL_BB2D_AQIDENT_PRODUCT_MAX                            (0x000000ffU)

#define CSL_BB2D_AQIDENT_TECHNOLOGY_MASK                        (0x00000F00U)
#define CSL_BB2D_AQIDENT_TECHNOLOGY_SHIFT                       (8U)
#define CSL_BB2D_AQIDENT_TECHNOLOGY_RESETVAL                    (0x00000000U)
#define CSL_BB2D_AQIDENT_TECHNOLOGY_MAX                         (0x0000000fU)

#define CSL_BB2D_AQIDENT_REVISION_MASK                          (0x0000F000U)
#define CSL_BB2D_AQIDENT_REVISION_SHIFT                         (12U)
#define CSL_BB2D_AQIDENT_REVISION_RESETVAL                      (0x00000000U)
#define CSL_BB2D_AQIDENT_REVISION_MAX                           (0x0000000fU)

#define CSL_BB2D_AQIDENT_CUSTOMER_MASK                          (0x000000FFU)
#define CSL_BB2D_AQIDENT_CUSTOMER_SHIFT                         (0U)
#define CSL_BB2D_AQIDENT_CUSTOMER_RESETVAL                      (0x00000000U)
#define CSL_BB2D_AQIDENT_CUSTOMER_MAX                           (0x000000ffU)

#define CSL_BB2D_AQIDENT_FAMILY_MASK                            (0xFF000000U)
#define CSL_BB2D_AQIDENT_FAMILY_SHIFT                           (24U)
#define CSL_BB2D_AQIDENT_FAMILY_RESETVAL                        (0x00000014U)
#define CSL_BB2D_AQIDENT_FAMILY_MAX                             (0x000000ffU)

#define CSL_BB2D_AQIDENT_RESETVAL                               (0x14010000U)

/* GCFEATURES */

#define CSL_BB2D_GCFEATURES_ETC1_TEXTURE_COMPRESSION_MASK       (0x00000400U)
#define CSL_BB2D_GCFEATURES_ETC1_TEXTURE_COMPRESSION_SHIFT      (10U)
#define CSL_BB2D_GCFEATURES_ETC1_TEXTURE_COMPRESSION_RESETVAL   (0x00000001U)
#define CSL_BB2D_GCFEATURES_ETC1_TEXTURE_COMPRESSION_MAX        (0x00000001U)

#define CSL_BB2D_GCFEATURES_HIGH_DYNAMIC_RANGE_MASK             (0x00001000U)
#define CSL_BB2D_GCFEATURES_HIGH_DYNAMIC_RANGE_SHIFT            (12U)
#define CSL_BB2D_GCFEATURES_HIGH_DYNAMIC_RANGE_RESETVAL         (0x00000001U)
#define CSL_BB2D_GCFEATURES_HIGH_DYNAMIC_RANGE_MAX              (0x00000001U)

#define CSL_BB2D_GCFEATURES_SPECIAL_ANTI_ALIASING_MASK          (0x00000002U)
#define CSL_BB2D_GCFEATURES_SPECIAL_ANTI_ALIASING_SHIFT         (1U)
#define CSL_BB2D_GCFEATURES_SPECIAL_ANTI_ALIASING_RESETVAL      (0x00000001U)
#define CSL_BB2D_GCFEATURES_SPECIAL_ANTI_ALIASING_MAX           (0x00000001U)

#define CSL_BB2D_GCFEATURES_BUFFER_INTERLEAVING_MASK            (0x00040000U)
#define CSL_BB2D_GCFEATURES_BUFFER_INTERLEAVING_SHIFT           (18U)
#define CSL_BB2D_GCFEATURES_BUFFER_INTERLEAVING_RESETVAL        (0x00000001U)
#define CSL_BB2D_GCFEATURES_BUFFER_INTERLEAVING_MAX             (0x00000001U)

#define CSL_BB2D_GCFEATURES_NO_EZ_MASK                          (0x00010000U)
#define CSL_BB2D_GCFEATURES_NO_EZ_SHIFT                         (16U)
#define CSL_BB2D_GCFEATURES_NO_EZ_RESETVAL                      (0x00000000U)
#define CSL_BB2D_GCFEATURES_NO_EZ_MAX                           (0x00000001U)

#define CSL_BB2D_GCFEATURES_DEBUG_MODE_MASK                     (0x00000010U)
#define CSL_BB2D_GCFEATURES_DEBUG_MODE_SHIFT                    (4U)
#define CSL_BB2D_GCFEATURES_DEBUG_MODE_RESETVAL                 (0x00000000U)
#define CSL_BB2D_GCFEATURES_DEBUG_MODE_MAX                      (0x00000001U)

#define CSL_BB2D_GCFEATURES_HALF_TX_CACHE_MASK                  (0x00800000U)
#define CSL_BB2D_GCFEATURES_HALF_TX_CACHE_SHIFT                 (23U)
#define CSL_BB2D_GCFEATURES_HALF_TX_CACHE_RESETVAL              (0x00000000U)
#define CSL_BB2D_GCFEATURES_HALF_TX_CACHE_MAX                   (0x00000001U)

#define CSL_BB2D_GCFEATURES_DC_MASK                             (0x00000100U)
#define CSL_BB2D_GCFEATURES_DC_SHIFT                            (8U)
#define CSL_BB2D_GCFEATURES_DC_RESETVAL                         (0x00000000U)
#define CSL_BB2D_GCFEATURES_DC_MAX                              (0x00000001U)

#define CSL_BB2D_GCFEATURES_BYTE_WRITE_3D_MASK                  (0x20000000U)
#define CSL_BB2D_GCFEATURES_BYTE_WRITE_3D_SHIFT                 (29U)
#define CSL_BB2D_GCFEATURES_BYTE_WRITE_3D_RESETVAL              (0x00000001U)
#define CSL_BB2D_GCFEATURES_BYTE_WRITE_3D_MAX                   (0x00000001U)

#define CSL_BB2D_GCFEATURES_MSAA_MASK                           (0x00000080U)
#define CSL_BB2D_GCFEATURES_MSAA_SHIFT                          (7U)
#define CSL_BB2D_GCFEATURES_MSAA_RESETVAL                       (0x00000001U)
#define CSL_BB2D_GCFEATURES_MSAA_MAX                            (0x00000001U)

#define CSL_BB2D_GCFEATURES_NO422_TEXTURE_MASK                  (0x00020000U)
#define CSL_BB2D_GCFEATURES_NO422_TEXTURE_SHIFT                 (17U)
#define CSL_BB2D_GCFEATURES_NO422_TEXTURE_RESETVAL              (0x00000000U)
#define CSL_BB2D_GCFEATURES_NO422_TEXTURE_MAX                   (0x00000001U)

#define CSL_BB2D_GCFEATURES_YUY2_RENDER_TARGET_MASK             (0x01000000U)
#define CSL_BB2D_GCFEATURES_YUY2_RENDER_TARGET_SHIFT            (24U)
#define CSL_BB2D_GCFEATURES_YUY2_RENDER_TARGET_RESETVAL         (0x00000000U)
#define CSL_BB2D_GCFEATURES_YUY2_RENDER_TARGET_MAX              (0x00000001U)

#define CSL_BB2D_GCFEATURES_FE20_MASK                           (0x10000000U)
#define CSL_BB2D_GCFEATURES_FE20_SHIFT                          (28U)
#define CSL_BB2D_GCFEATURES_FE20_RESETVAL                       (0x00000000U)
#define CSL_BB2D_GCFEATURES_FE20_MAX                            (0x00000001U)

#define CSL_BB2D_GCFEATURES_RS_YUV_TARGET_MASK                  (0x40000000U)
#define CSL_BB2D_GCFEATURES_RS_YUV_TARGET_SHIFT                 (30U)
#define CSL_BB2D_GCFEATURES_RS_YUV_TARGET_RESETVAL              (0x00000001U)
#define CSL_BB2D_GCFEATURES_RS_YUV_TARGET_MAX                   (0x00000001U)

#define CSL_BB2D_GCFEATURES_DXT_TEXTURE_COMPRESSION_MASK        (0x00000008U)
#define CSL_BB2D_GCFEATURES_DXT_TEXTURE_COMPRESSION_SHIFT       (3U)
#define CSL_BB2D_GCFEATURES_DXT_TEXTURE_COMPRESSION_RESETVAL    (0x00000001U)
#define CSL_BB2D_GCFEATURES_DXT_TEXTURE_COMPRESSION_MAX         (0x00000001U)

#define CSL_BB2D_GCFEATURES_FAST_SCALER_MASK                    (0x00000800U)
#define CSL_BB2D_GCFEATURES_FAST_SCALER_SHIFT                   (11U)
#define CSL_BB2D_GCFEATURES_FAST_SCALER_RESETVAL                (0x00000001U)
#define CSL_BB2D_GCFEATURES_FAST_SCALER_MAX                     (0x00000001U)

#define CSL_BB2D_GCFEATURES_MIN_AREA_MASK                       (0x00008000U)
#define CSL_BB2D_GCFEATURES_MIN_AREA_SHIFT                      (15U)
#define CSL_BB2D_GCFEATURES_MIN_AREA_RESETVAL                   (0x00000000U)
#define CSL_BB2D_GCFEATURES_MIN_AREA_MAX                        (0x00000001U)

#define CSL_BB2D_GCFEATURES_HALF_PE_CACHE_MASK                  (0x00400000U)
#define CSL_BB2D_GCFEATURES_HALF_PE_CACHE_SHIFT                 (22U)
#define CSL_BB2D_GCFEATURES_HALF_PE_CACHE_RESETVAL              (0x00000000U)
#define CSL_BB2D_GCFEATURES_HALF_PE_CACHE_MAX                   (0x00000001U)

#define CSL_BB2D_GCFEATURES_PIPE_2D_MASK                        (0x00000200U)
#define CSL_BB2D_GCFEATURES_PIPE_2D_SHIFT                       (9U)
#define CSL_BB2D_GCFEATURES_PIPE_2D_RESETVAL                    (0x00000001U)
#define CSL_BB2D_GCFEATURES_PIPE_2D_MAX                         (0x00000001U)

#define CSL_BB2D_GCFEATURES_PIPE_VG_MASK                        (0x04000000U)
#define CSL_BB2D_GCFEATURES_PIPE_VG_SHIFT                       (26U)
#define CSL_BB2D_GCFEATURES_PIPE_VG_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCFEATURES_PIPE_VG_MAX                         (0x00000001U)

#define CSL_BB2D_GCFEATURES_FAST_CLEAR_MASK                     (0x00000001U)
#define CSL_BB2D_GCFEATURES_FAST_CLEAR_SHIFT                    (0U)
#define CSL_BB2D_GCFEATURES_FAST_CLEAR_RESETVAL                 (0x00000000U)
#define CSL_BB2D_GCFEATURES_FAST_CLEAR_MAX                      (0x00000001U)

#define CSL_BB2D_GCFEATURES_FE20_BIT_INDEX_MASK                 (0x80000000U)
#define CSL_BB2D_GCFEATURES_FE20_BIT_INDEX_SHIFT                (31U)
#define CSL_BB2D_GCFEATURES_FE20_BIT_INDEX_RESETVAL             (0x00000001U)
#define CSL_BB2D_GCFEATURES_FE20_BIT_INDEX_MAX                  (0x00000001U)

#define CSL_BB2D_GCFEATURES_YUY2_AVERAGING_MASK                 (0x00200000U)
#define CSL_BB2D_GCFEATURES_YUY2_AVERAGING_SHIFT                (21U)
#define CSL_BB2D_GCFEATURES_YUY2_AVERAGING_RESETVAL             (0x00000001U)
#define CSL_BB2D_GCFEATURES_YUY2_AVERAGING_MAX                  (0x00000001U)

#define CSL_BB2D_GCFEATURES_YUV420_FILTER_MASK                  (0x00000040U)
#define CSL_BB2D_GCFEATURES_YUV420_FILTER_SHIFT                 (6U)
#define CSL_BB2D_GCFEATURES_YUV420_FILTER_RESETVAL              (0x00000001U)
#define CSL_BB2D_GCFEATURES_YUV420_FILTER_MAX                   (0x00000001U)

#define CSL_BB2D_GCFEATURES_NO_SCALER_MASK                      (0x00100000U)
#define CSL_BB2D_GCFEATURES_NO_SCALER_SHIFT                     (20U)
#define CSL_BB2D_GCFEATURES_NO_SCALER_RESETVAL                  (0x00000000U)
#define CSL_BB2D_GCFEATURES_NO_SCALER_MAX                       (0x00000001U)

#define CSL_BB2D_GCFEATURES_MODULE_CG_MASK                      (0x00004000U)
#define CSL_BB2D_GCFEATURES_MODULE_CG_SHIFT                     (14U)
#define CSL_BB2D_GCFEATURES_MODULE_CG_RESETVAL                  (0x00000001U)
#define CSL_BB2D_GCFEATURES_MODULE_CG_MAX                       (0x00000001U)

#define CSL_BB2D_GCFEATURES_MEM32_BIT_SUPPORT_MASK              (0x02000000U)
#define CSL_BB2D_GCFEATURES_MEM32_BIT_SUPPORT_SHIFT             (25U)
#define CSL_BB2D_GCFEATURES_MEM32_BIT_SUPPORT_RESETVAL          (0x00000000U)
#define CSL_BB2D_GCFEATURES_MEM32_BIT_SUPPORT_MAX               (0x00000001U)

#define CSL_BB2D_GCFEATURES_ZCOMPRESSION_MASK                   (0x00000020U)
#define CSL_BB2D_GCFEATURES_ZCOMPRESSION_SHIFT                  (5U)
#define CSL_BB2D_GCFEATURES_ZCOMPRESSION_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCFEATURES_ZCOMPRESSION_MAX                    (0x00000001U)

#define CSL_BB2D_GCFEATURES_YUV420_TILER_MASK                   (0x00002000U)
#define CSL_BB2D_GCFEATURES_YUV420_TILER_SHIFT                  (13U)
#define CSL_BB2D_GCFEATURES_YUV420_TILER_RESETVAL               (0x00000001U)
#define CSL_BB2D_GCFEATURES_YUV420_TILER_MAX                    (0x00000001U)

#define CSL_BB2D_GCFEATURES_BYTE_WRITE_2D_MASK                  (0x00080000U)
#define CSL_BB2D_GCFEATURES_BYTE_WRITE_2D_SHIFT                 (19U)
#define CSL_BB2D_GCFEATURES_BYTE_WRITE_2D_RESETVAL              (0x00000001U)
#define CSL_BB2D_GCFEATURES_BYTE_WRITE_2D_MAX                   (0x00000001U)

#define CSL_BB2D_GCFEATURES_PIPE_3D_MASK                        (0x00000004U)
#define CSL_BB2D_GCFEATURES_PIPE_3D_SHIFT                       (2U)
#define CSL_BB2D_GCFEATURES_PIPE_3D_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCFEATURES_PIPE_3D_MAX                         (0x00000001U)

#define CSL_BB2D_GCFEATURES_VGTS_MASK                           (0x08000000U)
#define CSL_BB2D_GCFEATURES_VGTS_SHIFT                          (27U)
#define CSL_BB2D_GCFEATURES_VGTS_RESETVAL                       (0x00000000U)
#define CSL_BB2D_GCFEATURES_VGTS_MAX                            (0x00000001U)

#define CSL_BB2D_GCFEATURES_RESETVAL                            (0xe02c7ecaU)

/* GCCHIPID */

#define CSL_BB2D_GCCHIPID_ID_MASK                               (0xFFFFFFFFU)
#define CSL_BB2D_GCCHIPID_ID_SHIFT                              (0U)
#define CSL_BB2D_GCCHIPID_ID_RESETVAL                           (0x00000320U)
#define CSL_BB2D_GCCHIPID_ID_MAX                                (0xffffffffU)

#define CSL_BB2D_GCCHIPID_RESETVAL                              (0x00000320U)

/* GCCHIPREV */

#define CSL_BB2D_GCCHIPREV_REV_MASK                             (0xFFFFFFFFU)
#define CSL_BB2D_GCCHIPREV_REV_SHIFT                            (0U)
#define CSL_BB2D_GCCHIPREV_REV_RESETVAL                         (0x00005301U)
#define CSL_BB2D_GCCHIPREV_REV_MAX                              (0xffffffffU)

#define CSL_BB2D_GCCHIPREV_RESETVAL                             (0x00005301U)

/* GCCHIPDATE */

#define CSL_BB2D_GCCHIPDATE_DATE_MASK                           (0xFFFFFFFFU)
#define CSL_BB2D_GCCHIPDATE_DATE_SHIFT                          (0U)
#define CSL_BB2D_GCCHIPDATE_DATE_RESETVAL                       (0x20111103U)
#define CSL_BB2D_GCCHIPDATE_DATE_MAX                            (0xffffffffU)

#define CSL_BB2D_GCCHIPDATE_RESETVAL                            (0x20111103U)

/* GCCHIPTIME */

#define CSL_BB2D_GCCHIPTIME_TIME_MASK                           (0xFFFFFFFFU)
#define CSL_BB2D_GCCHIPTIME_TIME_SHIFT                          (0U)
#define CSL_BB2D_GCCHIPTIME_TIME_RESETVAL                       (0x00140300U)
#define CSL_BB2D_GCCHIPTIME_TIME_MAX                            (0xffffffffU)

#define CSL_BB2D_GCCHIPTIME_RESETVAL                            (0x00140300U)

/* GCCHIPCUSTOMER */

#define CSL_BB2D_GCCHIPCUSTOMER_GROUP_MASK                      (0x0000FFFFU)
#define CSL_BB2D_GCCHIPCUSTOMER_GROUP_SHIFT                     (0U)
#define CSL_BB2D_GCCHIPCUSTOMER_GROUP_RESETVAL                  (0x00000000U)
#define CSL_BB2D_GCCHIPCUSTOMER_GROUP_MAX                       (0x0000ffffU)

#define CSL_BB2D_GCCHIPCUSTOMER_COMPANY_MASK                    (0xFFFF0000U)
#define CSL_BB2D_GCCHIPCUSTOMER_COMPANY_SHIFT                   (16U)
#define CSL_BB2D_GCCHIPCUSTOMER_COMPANY_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCCHIPCUSTOMER_COMPANY_MAX                     (0x0000ffffU)

#define CSL_BB2D_GCCHIPCUSTOMER_RESETVAL                        (0x00000000U)

/* GCMINORFEATURES0 */

#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1_MASK  (0x00100000U)
#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1_SHIFT  (20U)
#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS1_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_VG_FILTER_MASK                (0x00020000U)
#define CSL_BB2D_GCMINORFEATURES0_VG_FILTER_SHIFT               (17U)
#define CSL_BB2D_GCMINORFEATURES0_VG_FILTER_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_VG_FILTER_MAX                 (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_SHADER_MSAA_SIDEBAND_MASK     (0x00800000U)
#define CSL_BB2D_GCMINORFEATURES0_SHADER_MSAA_SIDEBAND_SHIFT    (23U)
#define CSL_BB2D_GCMINORFEATURES0_SHADER_MSAA_SIDEBAND_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_SHADER_MSAA_SIDEBAND_MAX      (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0_MASK  (0x00010000U)
#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0_SHIFT  (16U)
#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_EXTRA_SHADER_INSTRUCTIONS0_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_MC_20_MASK                    (0x00400000U)
#define CSL_BB2D_GCMINORFEATURES0_MC_20_SHIFT                   (22U)
#define CSL_BB2D_GCMINORFEATURES0_MC_20_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_MC_20_MAX                     (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_COMPRESSION_FIFO_FIXED_MASK   (0x00008000U)
#define CSL_BB2D_GCMINORFEATURES0_COMPRESSION_FIFO_FIXED_SHIFT  (15U)
#define CSL_BB2D_GCMINORFEATURES0_COMPRESSION_FIFO_FIXED_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_COMPRESSION_FIFO_FIXED_MAX    (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_VG_20_MASK                    (0x00002000U)
#define CSL_BB2D_GCMINORFEATURES0_VG_20_SHIFT                   (13U)
#define CSL_BB2D_GCMINORFEATURES0_VG_20_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_VG_20_MAX                     (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_RENDER_8K_MASK                (0x00000200U)
#define CSL_BB2D_GCMINORFEATURES0_RENDER_8K_SHIFT               (9U)
#define CSL_BB2D_GCMINORFEATURES0_RENDER_8K_RESETVAL            (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_RENDER_8K_MAX                 (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_CORRECT_STENCIL_MASK          (0x40000000U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_STENCIL_SHIFT         (30U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_STENCIL_RESETVAL      (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_STENCIL_MAX           (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_TS_EXTENDED_COMMANDS_MASK     (0x00004000U)
#define CSL_BB2D_GCMINORFEATURES0_TS_EXTENDED_COMMANDS_SHIFT    (14U)
#define CSL_BB2D_GCMINORFEATURES0_TS_EXTENDED_COMMANDS_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_TS_EXTENDED_COMMANDS_MAX      (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_DEFAULT_REG0_MASK             (0x00200000U)
#define CSL_BB2D_GCMINORFEATURES0_DEFAULT_REG0_SHIFT            (21U)
#define CSL_BB2D_GCMINORFEATURES0_DEFAULT_REG0_RESETVAL         (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_DEFAULT_REG0_MAX              (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_HIERARCHICAL_Z_MASK           (0x08000000U)
#define CSL_BB2D_GCMINORFEATURES0_HIERARCHICAL_Z_SHIFT          (27U)
#define CSL_BB2D_GCMINORFEATURES0_HIERARCHICAL_Z_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_HIERARCHICAL_Z_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_DUAL_RETURN_BUS_MASK          (0x00000002U)
#define CSL_BB2D_GCMINORFEATURES0_DUAL_RETURN_BUS_SHIFT         (1U)
#define CSL_BB2D_GCMINORFEATURES0_DUAL_RETURN_BUS_RESETVAL      (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_DUAL_RETURN_BUS_MAX           (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_PE20_2D_MASK                  (0x00000080U)
#define CSL_BB2D_GCMINORFEATURES0_PE20_2D_SHIFT                 (7U)
#define CSL_BB2D_GCMINORFEATURES0_PE20_2D_RESETVAL              (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_PE20_2D_MAX                   (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_ENHANCE_VR_MASK               (0x80000000U)
#define CSL_BB2D_GCMINORFEATURES0_ENHANCE_VR_SHIFT              (31U)
#define CSL_BB2D_GCMINORFEATURES0_ENHANCE_VR_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_ENHANCE_VR_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_TEXTURE8_K_MASK               (0x00000008U)
#define CSL_BB2D_GCMINORFEATURES0_TEXTURE8_K_SHIFT              (3U)
#define CSL_BB2D_GCMINORFEATURES0_TEXTURE8_K_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_TEXTURE8_K_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_SHADER_GETS_W_MASK            (0x00080000U)
#define CSL_BB2D_GCMINORFEATURES0_SHADER_GETS_W_SHIFT           (19U)
#define CSL_BB2D_GCMINORFEATURES0_SHADER_GETS_W_RESETVAL        (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_SHADER_GETS_W_MAX             (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_TILE_STATUS_2BITS_MASK        (0x00000400U)
#define CSL_BB2D_GCMINORFEATURES0_TILE_STATUS_2BITS_SHIFT       (10U)
#define CSL_BB2D_GCMINORFEATURES0_TILE_STATUS_2BITS_RESETVAL    (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_TILE_STATUS_2BITS_MAX         (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_FLIP_Y_MASK                   (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_FLIP_Y_SHIFT                  (0U)
#define CSL_BB2D_GCMINORFEATURES0_FLIP_Y_RESETVAL               (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_FLIP_Y_MAX                    (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_VAA_MASK                      (0x02000000U)
#define CSL_BB2D_GCMINORFEATURES0_VAA_SHIFT                     (25U)
#define CSL_BB2D_GCMINORFEATURES0_VAA_RESETVAL                  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_VAA_MAX                       (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_SUPER_TILED_32X32_MASK        (0x00001000U)
#define CSL_BB2D_GCMINORFEATURES0_SUPER_TILED_32X32_SHIFT       (12U)
#define CSL_BB2D_GCMINORFEATURES0_SUPER_TILED_32X32_RESETVAL    (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_SUPER_TILED_32X32_MAX         (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_BYPASS_IN_MSAA_MASK           (0x04000000U)
#define CSL_BB2D_GCMINORFEATURES0_BYPASS_IN_MSAA_SHIFT          (26U)
#define CSL_BB2D_GCMINORFEATURES0_BYPASS_IN_MSAA_RESETVAL       (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_BYPASS_IN_MSAA_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_VG_21_MASK                    (0x00040000U)
#define CSL_BB2D_GCMINORFEATURES0_VG_21_SHIFT                   (18U)
#define CSL_BB2D_GCMINORFEATURES0_VG_21_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_VG_21_MAX                     (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_CORRECT_TEXTURE_CONVERTER_MASK  (0x00000010U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_TEXTURE_CONVERTER_SHIFT  (4U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_TEXTURE_CONVERTER_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_TEXTURE_CONVERTER_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_FAST_CLEAR_FLUSH_MASK         (0x00000040U)
#define CSL_BB2D_GCMINORFEATURES0_FAST_CLEAR_FLUSH_SHIFT        (6U)
#define CSL_BB2D_GCMINORFEATURES0_FAST_CLEAR_FLUSH_RESETVAL     (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_FAST_CLEAR_FLUSH_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_CORRECT_AUTO_DISABLE_MASK     (0x00000100U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_AUTO_DISABLE_SHIFT    (8U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_AUTO_DISABLE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_CORRECT_AUTO_DISABLE_MAX      (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_MASK  (0x00000800U)
#define CSL_BB2D_GCMINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_SHIFT  (11U)
#define CSL_BB2D_GCMINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_NEW_TEXTURE_MASK              (0x10000000U)
#define CSL_BB2D_GCMINORFEATURES0_NEW_TEXTURE_SHIFT             (28U)
#define CSL_BB2D_GCMINORFEATURES0_NEW_TEXTURE_RESETVAL          (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_NEW_TEXTURE_MAX               (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_A8_TARGET_SUPPORT_MASK        (0x20000000U)
#define CSL_BB2D_GCMINORFEATURES0_A8_TARGET_SUPPORT_SHIFT       (29U)
#define CSL_BB2D_GCMINORFEATURES0_A8_TARGET_SUPPORT_RESETVAL    (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES0_A8_TARGET_SUPPORT_MAX         (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_ENDIANNESS_CONFIG_MASK        (0x00000004U)
#define CSL_BB2D_GCMINORFEATURES0_ENDIANNESS_CONFIG_SHIFT       (2U)
#define CSL_BB2D_GCMINORFEATURES0_ENDIANNESS_CONFIG_RESETVAL    (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_ENDIANNESS_CONFIG_MAX         (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_SPECIAL_MSAA_LOD_MASK         (0x00000020U)
#define CSL_BB2D_GCMINORFEATURES0_SPECIAL_MSAA_LOD_SHIFT        (5U)
#define CSL_BB2D_GCMINORFEATURES0_SPECIAL_MSAA_LOD_RESETVAL     (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_SPECIAL_MSAA_LOD_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_BUG_FIXES0_MASK               (0x01000000U)
#define CSL_BB2D_GCMINORFEATURES0_BUG_FIXES0_SHIFT              (24U)
#define CSL_BB2D_GCMINORFEATURES0_BUG_FIXES0_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES0_BUG_FIXES0_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES0_RESETVAL                      (0xc9399effU)

/* GCRESETMEMCOUNTERS */

#define CSL_BB2D_GCRESETMEMCOUNTERS_RESET_MASK                  (0x00000001U)
#define CSL_BB2D_GCRESETMEMCOUNTERS_RESET_SHIFT                 (0U)
#define CSL_BB2D_GCRESETMEMCOUNTERS_RESET_RESETVAL              (0x00000001U)
#define CSL_BB2D_GCRESETMEMCOUNTERS_RESET_MAX                   (0x00000001U)

#define CSL_BB2D_GCRESETMEMCOUNTERS_RESETVAL                    (0xc9399effU)

/* GCTOTALREADS */

#define CSL_BB2D_GCTOTALREADS_COUNT_MASK                        (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALREADS_COUNT_SHIFT                       (0U)
#define CSL_BB2D_GCTOTALREADS_COUNT_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCTOTALREADS_COUNT_MAX                         (0xffffffffU)

#define CSL_BB2D_GCTOTALREADS_RESETVAL                          (0x00000000U)

/* GCTOTALWRITES */

#define CSL_BB2D_GCTOTALWRITES_COUNT_MASK                       (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALWRITES_COUNT_SHIFT                      (0U)
#define CSL_BB2D_GCTOTALWRITES_COUNT_RESETVAL                   (0x00000000U)
#define CSL_BB2D_GCTOTALWRITES_COUNT_MAX                        (0xffffffffU)

#define CSL_BB2D_GCTOTALWRITES_RESETVAL                         (0x00000000U)

/* GCCHIPSPECS */

#define CSL_BB2D_GCCHIPSPECS_THREAD_COUNT_MASK                  (0x00000F00U)
#define CSL_BB2D_GCCHIPSPECS_THREAD_COUNT_SHIFT                 (8U)
#define CSL_BB2D_GCCHIPSPECS_THREAD_COUNT_RESETVAL              (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS_THREAD_COUNT_MAX                   (0x0000000fU)

#define CSL_BB2D_GCCHIPSPECS_TEMP_REGISTERS_MASK                (0x000000F0U)
#define CSL_BB2D_GCCHIPSPECS_TEMP_REGISTERS_SHIFT               (4U)
#define CSL_BB2D_GCCHIPSPECS_TEMP_REGISTERS_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS_TEMP_REGISTERS_MAX                 (0x0000000fU)

#define CSL_BB2D_GCCHIPSPECS_NUM_PIXEL_PIPES_MASK               (0x0E000000U)
#define CSL_BB2D_GCCHIPSPECS_NUM_PIXEL_PIPES_SHIFT              (25U)
#define CSL_BB2D_GCCHIPSPECS_NUM_PIXEL_PIPES_RESETVAL           (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS_NUM_PIXEL_PIPES_MAX                (0x00000007U)

#define CSL_BB2D_GCCHIPSPECS_VERTEX_CACHE_SIZE_MASK             (0x0001F000U)
#define CSL_BB2D_GCCHIPSPECS_VERTEX_CACHE_SIZE_SHIFT            (12U)
#define CSL_BB2D_GCCHIPSPECS_VERTEX_CACHE_SIZE_RESETVAL         (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS_VERTEX_CACHE_SIZE_MAX              (0x0000001fU)

#define CSL_BB2D_GCCHIPSPECS_NUM_SHADER_CORES_MASK              (0x01F00000U)
#define CSL_BB2D_GCCHIPSPECS_NUM_SHADER_CORES_SHIFT             (20U)
#define CSL_BB2D_GCCHIPSPECS_NUM_SHADER_CORES_RESETVAL          (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS_NUM_SHADER_CORES_MAX               (0x0000001fU)

#define CSL_BB2D_GCCHIPSPECS_STREAMS_MASK                       (0x0000000FU)
#define CSL_BB2D_GCCHIPSPECS_STREAMS_SHIFT                      (0U)
#define CSL_BB2D_GCCHIPSPECS_STREAMS_RESETVAL                   (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS_STREAMS_MAX                        (0x0000000fU)

#define CSL_BB2D_GCCHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE_MASK     (0xF0000000U)
#define CSL_BB2D_GCCHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE_SHIFT    (28U)
#define CSL_BB2D_GCCHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS_VERTEX_OUTPUT_BUFFER_SIZE_MAX      (0x0000000fU)

#define CSL_BB2D_GCCHIPSPECS_RESETVAL                           (0x00000000U)

/* GCTOTALWRITEBURSTS */

#define CSL_BB2D_GCTOTALWRITEBURSTS_COUNT_MASK                  (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALWRITEBURSTS_COUNT_SHIFT                 (0U)
#define CSL_BB2D_GCTOTALWRITEBURSTS_COUNT_RESETVAL              (0x00000000U)
#define CSL_BB2D_GCTOTALWRITEBURSTS_COUNT_MAX                   (0xffffffffU)

#define CSL_BB2D_GCTOTALWRITEBURSTS_RESETVAL                    (0x00000000U)

/* GCTOTALWRITEREQS */

#define CSL_BB2D_GCTOTALWRITEREQS_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALWRITEREQS_COUNT_SHIFT                   (0U)
#define CSL_BB2D_GCTOTALWRITEREQS_COUNT_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCTOTALWRITEREQS_COUNT_MAX                     (0xffffffffU)

#define CSL_BB2D_GCTOTALWRITEREQS_RESETVAL                      (0x00000000U)

/* GCTOTALWRITELASTS */

#define CSL_BB2D_GCTOTALWRITELASTS_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALWRITELASTS_COUNT_SHIFT                  (0U)
#define CSL_BB2D_GCTOTALWRITELASTS_COUNT_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCTOTALWRITELASTS_COUNT_MAX                    (0xffffffffU)

#define CSL_BB2D_GCTOTALWRITELASTS_RESETVAL                     (0x00000000U)

/* GCTOTALREADBURSTS */

#define CSL_BB2D_GCTOTALREADBURSTS_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALREADBURSTS_COUNT_SHIFT                  (0U)
#define CSL_BB2D_GCTOTALREADBURSTS_COUNT_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCTOTALREADBURSTS_COUNT_MAX                    (0xffffffffU)

#define CSL_BB2D_GCTOTALREADBURSTS_RESETVAL                     (0x00000000U)

/* GCTOTALREADREQS */

#define CSL_BB2D_GCTOTALREADREQS_COUNT_MASK                     (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALREADREQS_COUNT_SHIFT                    (0U)
#define CSL_BB2D_GCTOTALREADREQS_COUNT_RESETVAL                 (0x00000000U)
#define CSL_BB2D_GCTOTALREADREQS_COUNT_MAX                      (0xffffffffU)

#define CSL_BB2D_GCTOTALREADREQS_RESETVAL                       (0x00000000U)

/* GCTOTALREADLASTS */

#define CSL_BB2D_GCTOTALREADLASTS_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALREADLASTS_COUNT_SHIFT                   (0U)
#define CSL_BB2D_GCTOTALREADLASTS_COUNT_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCTOTALREADLASTS_COUNT_MAX                     (0xffffffffU)

#define CSL_BB2D_GCTOTALREADLASTS_RESETVAL                      (0x00000000U)

/* GCGPOUT0 */

#define CSL_BB2D_GCGPOUT0_COUNT_MASK                            (0xFFFFFFFEU)
#define CSL_BB2D_GCGPOUT0_COUNT_SHIFT                           (1U)
#define CSL_BB2D_GCGPOUT0_COUNT_RESETVAL                        (0x00000000U)
#define CSL_BB2D_GCGPOUT0_COUNT_MAX                             (0x7fffffffU)

#define CSL_BB2D_GCGPOUT0_GCHOLD_MASK                           (0x00000001U)
#define CSL_BB2D_GCGPOUT0_GCHOLD_SHIFT                          (0U)
#define CSL_BB2D_GCGPOUT0_GCHOLD_RESETVAL                       (0x00000000U)
#define CSL_BB2D_GCGPOUT0_GCHOLD_MAX                            (0x00000001U)

#define CSL_BB2D_GCGPOUT0_RESETVAL                              (0x00000000U)

/* GCGPOUT1 */

#define CSL_BB2D_GCGPOUT1_COUNT_MASK                            (0xFFFFFFFFU)
#define CSL_BB2D_GCGPOUT1_COUNT_SHIFT                           (0U)
#define CSL_BB2D_GCGPOUT1_COUNT_RESETVAL                        (0x00000000U)
#define CSL_BB2D_GCGPOUT1_COUNT_MAX                             (0xffffffffU)

#define CSL_BB2D_GCGPOUT1_RESETVAL                              (0x00000000U)

/* GCGPOUT2 */

#define CSL_BB2D_GCGPOUT2_COUNT_MASK                            (0xFFFFFFFFU)
#define CSL_BB2D_GCGPOUT2_COUNT_SHIFT                           (0U)
#define CSL_BB2D_GCGPOUT2_COUNT_RESETVAL                        (0x00000000U)
#define CSL_BB2D_GCGPOUT2_COUNT_MAX                             (0xffffffffU)

#define CSL_BB2D_GCGPOUT2_RESETVAL                              (0x00000000U)

/* GCAXICONTROL */

#define CSL_BB2D_GCAXICONTROL_WR_FULL_BURST_MODE_MASK           (0x00000001U)
#define CSL_BB2D_GCAXICONTROL_WR_FULL_BURST_MODE_SHIFT          (0U)
#define CSL_BB2D_GCAXICONTROL_WR_FULL_BURST_MODE_RESETVAL       (0x00000000U)
#define CSL_BB2D_GCAXICONTROL_WR_FULL_BURST_MODE_MAX            (0x00000001U)

#define CSL_BB2D_GCAXICONTROL_RESETVAL                          (0x00000000U)

/* GCMINORFEATURES1 */

#define CSL_BB2D_GCMINORFEATURES1_CORRECT_OVERFLOW_VG_MASK      (0x01000000U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_OVERFLOW_VG_SHIFT     (24U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_OVERFLOW_VG_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_OVERFLOW_VG_MAX       (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_LINEAR_TEXTURE_SUPPORT_MASK   (0x00400000U)
#define CSL_BB2D_GCMINORFEATURES1_LINEAR_TEXTURE_SUPPORT_SHIFT  (22U)
#define CSL_BB2D_GCMINORFEATURES1_LINEAR_TEXTURE_SUPPORT_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_LINEAR_TEXTURE_SUPPORT_MAX    (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_PIXEL_DITHER_MASK             (0x00001000U)
#define CSL_BB2D_GCMINORFEATURES1_PIXEL_DITHER_SHIFT            (12U)
#define CSL_BB2D_GCMINORFEATURES1_PIXEL_DITHER_RESETVAL         (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_PIXEL_DITHER_MAX              (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_TWO_STENCIL_REFERENCE_MASK    (0x00002000U)
#define CSL_BB2D_GCMINORFEATURES1_TWO_STENCIL_REFERENCE_SHIFT   (13U)
#define CSL_BB2D_GCMINORFEATURES1_TWO_STENCIL_REFERENCE_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_TWO_STENCIL_REFERENCE_MAX     (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_FC_FLUSH_STALL_MASK           (0x80000000U)
#define CSL_BB2D_GCMINORFEATURES1_FC_FLUSH_STALL_SHIFT          (31U)
#define CSL_BB2D_GCMINORFEATURES1_FC_FLUSH_STALL_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_FC_FLUSH_STALL_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_AUTO_RESTART_TS_MASK          (0x00000100U)
#define CSL_BB2D_GCMINORFEATURES1_AUTO_RESTART_TS_SHIFT         (8U)
#define CSL_BB2D_GCMINORFEATURES1_AUTO_RESTART_TS_RESETVAL      (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_AUTO_RESTART_TS_MAX           (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_MASK  (0x00010000U)
#define CSL_BB2D_GCMINORFEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_SHIFT  (16U)
#define CSL_BB2D_GCMINORFEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_VG_DOUBLE_BUFFER_MASK         (0x00000004U)
#define CSL_BB2D_GCMINORFEATURES1_VG_DOUBLE_BUFFER_SHIFT        (2U)
#define CSL_BB2D_GCMINORFEATURES1_VG_DOUBLE_BUFFER_RESETVAL     (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_VG_DOUBLE_BUFFER_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_CORRECT_MIN_MAX_DEPTH_MASK    (0x00008000U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_MIN_MAX_DEPTH_SHIFT   (15U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_MIN_MAX_DEPTH_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_MIN_MAX_DEPTH_MAX     (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES5_MASK               (0x00020000U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES5_SHIFT              (17U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES5_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES5_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_RSUV_SWIZZLE_MASK             (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_RSUV_SWIZZLE_SHIFT            (0U)
#define CSL_BB2D_GCMINORFEATURES1_RSUV_SWIZZLE_RESETVAL         (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_RSUV_SWIZZLE_MAX              (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_RESOLVE_OFFSET_MASK           (0x04000000U)
#define CSL_BB2D_GCMINORFEATURES1_RESOLVE_OFFSET_SHIFT          (26U)
#define CSL_BB2D_GCMINORFEATURES1_RESOLVE_OFFSET_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_RESOLVE_OFFSET_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES2_MASK               (0x00000010U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES2_SHIFT              (4U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES2_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES2_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_HALTI0_MASK                   (0x00800000U)
#define CSL_BB2D_GCMINORFEATURES1_HALTI0_SHIFT                  (23U)
#define CSL_BB2D_GCMINORFEATURES1_HALTI0_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_HALTI0_MAX                    (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES3_MASK               (0x00000040U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES3_SHIFT              (6U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES3_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES3_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_NEW_FLOATING_POINT_ARITHMETIC_MASK  (0x00080000U)
#define CSL_BB2D_GCMINORFEATURES1_NEW_FLOATING_POINT_ARITHMETIC_SHIFT  (19U)
#define CSL_BB2D_GCMINORFEATURES1_NEW_FLOATING_POINT_ARITHMETIC_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_NEW_FLOATING_POINT_ARITHMETIC_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_STRIDE_MASK           (0x00000020U)
#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_STRIDE_SHIFT          (5U)
#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_STRIDE_RESETVAL       (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_STRIDE_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_NEW_2D_MASK                   (0x00040000U)
#define CSL_BB2D_GCMINORFEATURES1_NEW_2D_SHIFT                  (18U)
#define CSL_BB2D_GCMINORFEATURES1_NEW_2D_RESETVAL               (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_NEW_2D_MAX                    (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES4_MASK               (0x00000200U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES4_SHIFT              (9U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES4_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES4_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_MMU_MASK                      (0x10000000U)
#define CSL_BB2D_GCMINORFEATURES1_MMU_SHIFT                     (28U)
#define CSL_BB2D_GCMINORFEATURES1_MMU_RESETVAL                  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_MMU_MAX                       (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_OK_TO_GATE_AXI_CLOCK_MASK     (0x08000000U)
#define CSL_BB2D_GCMINORFEATURES1_OK_TO_GATE_AXI_CLOCK_SHIFT    (27U)
#define CSL_BB2D_GCMINORFEATURES1_OK_TO_GATE_AXI_CLOCK_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_OK_TO_GATE_AXI_CLOCK_MAX      (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_NON_POWER_OF_TWO_MASK         (0x00200000U)
#define CSL_BB2D_GCMINORFEATURES1_NON_POWER_OF_TWO_SHIFT        (21U)
#define CSL_BB2D_GCMINORFEATURES1_NON_POWER_OF_TWO_RESETVAL     (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_NON_POWER_OF_TWO_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_EXTENDED_PIXEL_FORMAT_MASK    (0x00004000U)
#define CSL_BB2D_GCMINORFEATURES1_EXTENDED_PIXEL_FORMAT_SHIFT   (14U)
#define CSL_BB2D_GCMINORFEATURES1_EXTENDED_PIXEL_FORMAT_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_EXTENDED_PIXEL_FORMAT_MAX     (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_MASK  (0x00100000U)
#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_SHIFT  (20U)
#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES1_MASK               (0x00000008U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES1_SHIFT              (3U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES1_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES1_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES6_MASK               (0x40000000U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES6_SHIFT              (30U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES6_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_BUG_FIXES6_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_V2_COMPRESSION_MASK           (0x00000002U)
#define CSL_BB2D_GCMINORFEATURES1_V2_COMPRESSION_SHIFT          (1U)
#define CSL_BB2D_GCMINORFEATURES1_V2_COMPRESSION_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_V2_COMPRESSION_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_L2_WINDOWING_MASK             (0x00000400U)
#define CSL_BB2D_GCMINORFEATURES1_L2_WINDOWING_SHIFT            (10U)
#define CSL_BB2D_GCMINORFEATURES1_L2_WINDOWING_RESETVAL         (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_L2_WINDOWING_MAX              (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_HALF_FLOAT_PIPE_MASK          (0x00000800U)
#define CSL_BB2D_GCMINORFEATURES1_HALF_FLOAT_PIPE_SHIFT         (11U)
#define CSL_BB2D_GCMINORFEATURES1_HALF_FLOAT_PIPE_RESETVAL      (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES1_HALF_FLOAT_PIPE_MAX           (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_WIDE_LINE_MASK                (0x20000000U)
#define CSL_BB2D_GCMINORFEATURES1_WIDE_LINE_SHIFT               (29U)
#define CSL_BB2D_GCMINORFEATURES1_WIDE_LINE_RESETVAL            (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_WIDE_LINE_MAX                 (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_CORRECT_AUTO_DISABLE_MASK     (0x00000080U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_AUTO_DISABLE_SHIFT    (7U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_AUTO_DISABLE_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_CORRECT_AUTO_DISABLE_MAX      (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_NEGATIVE_LOG_FIX_MASK         (0x02000000U)
#define CSL_BB2D_GCMINORFEATURES1_NEGATIVE_LOG_FIX_SHIFT        (25U)
#define CSL_BB2D_GCMINORFEATURES1_NEGATIVE_LOG_FIX_RESETVAL     (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES1_NEGATIVE_LOG_FIX_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES1_RESETVAL                      (0xfe1fb2dbU)

/* GCTOTALCYCLES */

#define CSL_BB2D_GCTOTALCYCLES_CYCLES_MASK                      (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALCYCLES_CYCLES_SHIFT                     (0U)
#define CSL_BB2D_GCTOTALCYCLES_CYCLES_RESETVAL                  (0x00001de2U)
#define CSL_BB2D_GCTOTALCYCLES_CYCLES_MAX                       (0xffffffffU)

#define CSL_BB2D_GCTOTALCYCLES_RESETVAL                         (0x00001de2U)

/* GCTOTALIDLECYCLES */

#define CSL_BB2D_GCTOTALIDLECYCLES_CYCLES_MASK                  (0xFFFFFFFFU)
#define CSL_BB2D_GCTOTALIDLECYCLES_CYCLES_SHIFT                 (0U)
#define CSL_BB2D_GCTOTALIDLECYCLES_CYCLES_RESETVAL              (0x00001e08U)
#define CSL_BB2D_GCTOTALIDLECYCLES_CYCLES_MAX                   (0xffffffffU)

#define CSL_BB2D_GCTOTALIDLECYCLES_RESETVAL                     (0x00001e08U)

/* GCCHIPSPECS2 */

#define CSL_BB2D_GCCHIPSPECS2_NUMBER_OF_CONSTANTS_MASK          (0xFFFF0000U)
#define CSL_BB2D_GCCHIPSPECS2_NUMBER_OF_CONSTANTS_SHIFT         (16U)
#define CSL_BB2D_GCCHIPSPECS2_NUMBER_OF_CONSTANTS_RESETVAL      (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS2_NUMBER_OF_CONSTANTS_MAX           (0x0000ffffU)

#define CSL_BB2D_GCCHIPSPECS2_INSTRUCTION_COUNT_MASK            (0x0000FF00U)
#define CSL_BB2D_GCCHIPSPECS2_INSTRUCTION_COUNT_SHIFT           (8U)
#define CSL_BB2D_GCCHIPSPECS2_INSTRUCTION_COUNT_RESETVAL        (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS2_INSTRUCTION_COUNT_MAX             (0x000000ffU)

#define CSL_BB2D_GCCHIPSPECS2_BUFFER_SIZE_MASK                  (0x000000FFU)
#define CSL_BB2D_GCCHIPSPECS2_BUFFER_SIZE_SHIFT                 (0U)
#define CSL_BB2D_GCCHIPSPECS2_BUFFER_SIZE_RESETVAL              (0x00000000U)
#define CSL_BB2D_GCCHIPSPECS2_BUFFER_SIZE_MAX                   (0x000000ffU)

#define CSL_BB2D_GCCHIPSPECS2_RESETVAL                          (0x00000000U)

/* GCMINORFEATURES2 */

#define CSL_BB2D_GCMINORFEATURES2_BUG_FIXES8_MASK               (0x80000000U)
#define CSL_BB2D_GCMINORFEATURES2_BUG_FIXES8_SHIFT              (31U)
#define CSL_BB2D_GCMINORFEATURES2_BUG_FIXES8_RESETVAL           (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_BUG_FIXES8_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_END_EVENT_MASK                (0x00000200U)
#define CSL_BB2D_GCMINORFEATURES2_END_EVENT_SHIFT               (9U)
#define CSL_BB2D_GCMINORFEATURES2_END_EVENT_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_END_EVENT_MAX                 (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_INTERLEAVER_MASK              (0x01000000U)
#define CSL_BB2D_GCMINORFEATURES2_INTERLEAVER_SHIFT             (24U)
#define CSL_BB2D_GCMINORFEATURES2_INTERLEAVER_RESETVAL          (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_INTERLEAVER_MAX               (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_PE_SWIZZLE_MASK               (0x00000100U)
#define CSL_BB2D_GCMINORFEATURES2_PE_SWIZZLE_SHIFT              (8U)
#define CSL_BB2D_GCMINORFEATURES2_PE_SWIZZLE_RESETVAL           (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_PE_SWIZZLE_MAX                (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_MIXED_STREAMS_MASK            (0x02000000U)
#define CSL_BB2D_GCMINORFEATURES2_MIXED_STREAMS_SHIFT           (25U)
#define CSL_BB2D_GCMINORFEATURES2_MIXED_STREAMS_RESETVAL        (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_MIXED_STREAMS_MAX             (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_FLUSH_FIXED_2D_MASK           (0x00800000U)
#define CSL_BB2D_GCMINORFEATURES2_FLUSH_FIXED_2D_SHIFT          (23U)
#define CSL_BB2D_GCMINORFEATURES2_FLUSH_FIXED_2D_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_FLUSH_FIXED_2D_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_TX_YUV_ASSEMBLER_MASK         (0x00002000U)
#define CSL_BB2D_GCMINORFEATURES2_TX_YUV_ASSEMBLER_SHIFT        (13U)
#define CSL_BB2D_GCMINORFEATURES2_TX_YUV_ASSEMBLER_RESETVAL     (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_TX_YUV_ASSEMBLER_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_ONE_PASS_2D_FILTER_MASK       (0x00020000U)
#define CSL_BB2D_GCMINORFEATURES2_ONE_PASS_2D_FILTER_SHIFT      (17U)
#define CSL_BB2D_GCMINORFEATURES2_ONE_PASS_2D_FILTER_RESETVAL   (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_ONE_PASS_2D_FILTER_MAX        (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_SUPER_TILED_TEXTURE_MASK      (0x00000008U)
#define CSL_BB2D_GCMINORFEATURES2_SUPER_TILED_TEXTURE_SHIFT     (3U)
#define CSL_BB2D_GCMINORFEATURES2_SUPER_TILED_TEXTURE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_SUPER_TILED_TEXTURE_MAX       (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_HALTI1_MASK                   (0x00000800U)
#define CSL_BB2D_GCMINORFEATURES2_HALTI1_SHIFT                  (11U)
#define CSL_BB2D_GCMINORFEATURES2_HALTI1_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_HALTI1_MAX                    (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_S1S8_MASK                     (0x00000400U)
#define CSL_BB2D_GCMINORFEATURES2_S1S8_SHIFT                    (10U)
#define CSL_BB2D_GCMINORFEATURES2_S1S8_RESETVAL                 (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_S1S8_MAX                      (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_SEAMLESS_CUBE_MAP_MASK        (0x00000004U)
#define CSL_BB2D_GCMINORFEATURES2_SEAMLESS_CUBE_MAP_SHIFT       (2U)
#define CSL_BB2D_GCMINORFEATURES2_SEAMLESS_CUBE_MAP_RESETVAL    (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_SEAMLESS_CUBE_MAP_MAX         (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_RGB888_MASK                   (0x00001000U)
#define CSL_BB2D_GCMINORFEATURES2_RGB888_SHIFT                  (12U)
#define CSL_BB2D_GCMINORFEATURES2_RGB888_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_RGB888_MAX                    (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_MASK  (0x00000080U)
#define CSL_BB2D_GCMINORFEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_SHIFT  (7U)
#define CSL_BB2D_GCMINORFEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_TILE_FILLER_MASK              (0x00080000U)
#define CSL_BB2D_GCMINORFEATURES2_TILE_FILLER_SHIFT             (19U)
#define CSL_BB2D_GCMINORFEATURES2_TILE_FILLER_RESETVAL          (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_TILE_FILLER_MAX               (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_NO_INDEX_PATTERN_MASK         (0x10000000U)
#define CSL_BB2D_GCMINORFEATURES2_NO_INDEX_PATTERN_SHIFT        (28U)
#define CSL_BB2D_GCMINORFEATURES2_NO_INDEX_PATTERN_RESETVAL     (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_NO_INDEX_PATTERN_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_TEXTURE_TILE_STATUS_MASK      (0x20000000U)
#define CSL_BB2D_GCMINORFEATURES2_TEXTURE_TILE_STATUS_SHIFT     (29U)
#define CSL_BB2D_GCMINORFEATURES2_TEXTURE_TILE_STATUS_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_TEXTURE_TILE_STATUS_MAX       (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_MULTI_SOURCE_BLT_MASK         (0x00200000U)
#define CSL_BB2D_GCMINORFEATURES2_MULTI_SOURCE_BLT_SHIFT        (21U)
#define CSL_BB2D_GCMINORFEATURES2_MULTI_SOURCE_BLT_RESETVAL     (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_MULTI_SOURCE_BLT_MAX          (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_TX_FILTER_MASK                (0x00008000U)
#define CSL_BB2D_GCMINORFEATURES2_TX_FILTER_SHIFT               (15U)
#define CSL_BB2D_GCMINORFEATURES2_TX_FILTER_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_TX_FILTER_MAX                 (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_THREAD_WALKER_IN_PS_MASK      (0x00040000U)
#define CSL_BB2D_GCMINORFEATURES2_THREAD_WALKER_IN_PS_SHIFT     (18U)
#define CSL_BB2D_GCMINORFEATURES2_THREAD_WALKER_IN_PS_RESETVAL  (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_THREAD_WALKER_IN_PS_MAX       (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_LINEAR_PE_MASK                (0x00000010U)
#define CSL_BB2D_GCMINORFEATURES2_LINEAR_PE_SHIFT               (4U)
#define CSL_BB2D_GCMINORFEATURES2_LINEAR_PE_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_LINEAR_PE_MAX                 (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_NOT_USED_MASK                 (0x04000000U)
#define CSL_BB2D_GCMINORFEATURES2_NOT_USED_SHIFT                (26U)
#define CSL_BB2D_GCMINORFEATURES2_NOT_USED_RESETVAL             (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_NOT_USED_MAX                  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_YUV_CONVERSION_MASK           (0x00400000U)
#define CSL_BB2D_GCMINORFEATURES2_YUV_CONVERSION_SHIFT          (22U)
#define CSL_BB2D_GCMINORFEATURES2_YUV_CONVERSION_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_YUV_CONVERSION_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_RECT_PRIMITIVE_MASK           (0x00000020U)
#define CSL_BB2D_GCMINORFEATURES2_RECT_PRIMITIVE_SHIFT          (5U)
#define CSL_BB2D_GCMINORFEATURES2_RECT_PRIMITIVE_RESETVAL       (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_RECT_PRIMITIVE_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_YUV_STANDARD_MASK             (0x00100000U)
#define CSL_BB2D_GCMINORFEATURES2_YUV_STANDARD_SHIFT            (20U)
#define CSL_BB2D_GCMINORFEATURES2_YUV_STANDARD_RESETVAL         (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_YUV_STANDARD_MAX              (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_LINE_LOOP_MASK                (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_LINE_LOOP_SHIFT               (0U)
#define CSL_BB2D_GCMINORFEATURES2_LINE_LOOP_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_LINE_LOOP_MAX                 (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_DYNAMIC_FREQUENCY_SCALING_MASK  (0x00004000U)
#define CSL_BB2D_GCMINORFEATURES2_DYNAMIC_FREQUENCY_SCALING_SHIFT  (14U)
#define CSL_BB2D_GCMINORFEATURES2_DYNAMIC_FREQUENCY_SCALING_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_DYNAMIC_FREQUENCY_SCALING_MAX  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_COMPOSITION_MASK              (0x00000040U)
#define CSL_BB2D_GCMINORFEATURES2_COMPOSITION_SHIFT             (6U)
#define CSL_BB2D_GCMINORFEATURES2_COMPOSITION_RESETVAL          (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_COMPOSITION_MAX               (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_FULL_DIRECT_FB_MASK           (0x00010000U)
#define CSL_BB2D_GCMINORFEATURES2_FULL_DIRECT_FB_SHIFT          (16U)
#define CSL_BB2D_GCMINORFEATURES2_FULL_DIRECT_FB_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_FULL_DIRECT_FB_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_DECOMPRESS_Z16_MASK           (0x40000000U)
#define CSL_BB2D_GCMINORFEATURES2_DECOMPRESS_Z16_SHIFT          (30U)
#define CSL_BB2D_GCMINORFEATURES2_DECOMPRESS_Z16_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCMINORFEATURES2_DECOMPRESS_Z16_MAX            (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_LOGIC_OP_MASK                 (0x00000002U)
#define CSL_BB2D_GCMINORFEATURES2_LOGIC_OP_SHIFT                (1U)
#define CSL_BB2D_GCMINORFEATURES2_LOGIC_OP_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCMINORFEATURES2_LOGIC_OP_MAX                  (0x00000001U)

#define CSL_BB2D_GCMINORFEATURES2_RESETVAL                      (0xdeff0080U)

/* GCMODULEPOWERCONTROLS */

#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_MASK    (0xFFFF0000U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_SHIFT   (16U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_RESETVAL  (0x00000014U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_MAX     (0x0000ffffU)

#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_MASK     (0x000000F0U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_SHIFT    (4U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_RESETVAL  (0x00000002U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_MAX      (0x0000000fU)

#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_MASK  (0x00000004U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_SHIFT  (2U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_MASK  (0x00000002U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_SHIFT  (1U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING_MASK  (0x00000001U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING_SHIFT  (0U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CLOCK_GATING_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERCONTROLS_RESETVAL                 (0x00140020U)

/* GCMODULEPOWERMODULECONTROL */

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE_MASK  (0x00000020U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE_SHIFT  (5U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE_MASK  (0x00000004U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE_SHIFT  (2U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH_MASK  (0x00000008U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH_SHIFT  (3U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_SH_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA_MASK  (0x00000010U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA_SHIFT  (4U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_PA_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX_MASK  (0x00000080U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX_SHIFT  (7U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_TX_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA_MASK  (0x00000040U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA_SHIFT  (6U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_RA_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE_MASK  (0x00000001U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE_SHIFT  (0U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_FE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE_MASK  (0x00000002U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE_SHIFT  (1U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CLOCK_GATING_DE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULECONTROL_RESETVAL            (0x00000000U)

/* GCMODULEPOWERMODULESTATUS */

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE_MASK  (0x00000002U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE_SHIFT  (1U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_DE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE_MASK  (0x00000020U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE_SHIFT  (5U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH_MASK  (0x00000008U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH_SHIFT  (3U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_SH_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE_MASK  (0x00000004U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE_SHIFT  (2U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA_MASK  (0x00000010U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA_SHIFT  (4U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_PA_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA_MASK  (0x00000040U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA_SHIFT  (6U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_RA_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX_MASK  (0x00000080U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX_SHIFT  (7U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_TX_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE_MASK  (0x00000001U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE_SHIFT  (0U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_MODULE_CLOCK_GATED_FE_MAX  (0x00000001U)

#define CSL_BB2D_GCMODULEPOWERMODULESTATUS_RESETVAL             (0x00000000U)

/* GCREGMMUSTATUS */

#define CSL_BB2D_GCREGMMUSTATUS_NA3_MASK                        (0xFFFFC000U)
#define CSL_BB2D_GCREGMMUSTATUS_NA3_SHIFT                       (14U)
#define CSL_BB2D_GCREGMMUSTATUS_NA3_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_NA3_MAX                         (0x0003ffffU)

#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION0_MASK                 (0x00000003U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION0_SHIFT                (0U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION0_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION0_MAX                  (0x00000003U)

#define CSL_BB2D_GCREGMMUSTATUS_NA2_MASK                        (0x00000C00U)
#define CSL_BB2D_GCREGMMUSTATUS_NA2_SHIFT                       (10U)
#define CSL_BB2D_GCREGMMUSTATUS_NA2_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_NA2_MAX                         (0x00000003U)

#define CSL_BB2D_GCREGMMUSTATUS_NA0_MASK                        (0x0000000CU)
#define CSL_BB2D_GCREGMMUSTATUS_NA0_SHIFT                       (2U)
#define CSL_BB2D_GCREGMMUSTATUS_NA0_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_NA0_MAX                         (0x00000003U)

#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION1_MASK                 (0x00000030U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION1_SHIFT                (4U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION1_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION1_MAX                  (0x00000003U)

#define CSL_BB2D_GCREGMMUSTATUS_NA1_MASK                        (0x000000C0U)
#define CSL_BB2D_GCREGMMUSTATUS_NA1_SHIFT                       (6U)
#define CSL_BB2D_GCREGMMUSTATUS_NA1_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_NA1_MAX                         (0x00000003U)

#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION2_MASK                 (0x00000300U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION2_SHIFT                (8U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION2_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION2_MAX                  (0x00000003U)

#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION3_MASK                 (0x00003000U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION3_SHIFT                (12U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION3_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCREGMMUSTATUS_EXCEPTION3_MAX                  (0x00000003U)

#define CSL_BB2D_GCREGMMUSTATUS_RESETVAL                        (0x00000000U)

/* GCREGMMUCONTROL */

#define CSL_BB2D_GCREGMMUCONTROL_ENABLE_MASK                    (0x00000001U)
#define CSL_BB2D_GCREGMMUCONTROL_ENABLE_SHIFT                   (0U)
#define CSL_BB2D_GCREGMMUCONTROL_ENABLE_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCREGMMUCONTROL_ENABLE_MAX                     (0x00000001U)

#define CSL_BB2D_GCREGMMUCONTROL_NA_MASK                        (0xFFFFFFFEU)
#define CSL_BB2D_GCREGMMUCONTROL_NA_SHIFT                       (1U)
#define CSL_BB2D_GCREGMMUCONTROL_NA_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCREGMMUCONTROL_NA_MAX                         (0x7fffffffU)

#define CSL_BB2D_GCREGMMUCONTROL_RESETVAL                       (0x00000000U)

/* GCREGMMUEXCEPTION0 */

#define CSL_BB2D_GCREGMMUEXCEPTION0_ADDRESS_MASK                (0xFFFFFFFFU)
#define CSL_BB2D_GCREGMMUEXCEPTION0_ADDRESS_SHIFT               (0U)
#define CSL_BB2D_GCREGMMUEXCEPTION0_ADDRESS_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCREGMMUEXCEPTION0_ADDRESS_MAX                 (0xffffffffU)

#define CSL_BB2D_GCREGMMUEXCEPTION0_RESETVAL                    (0x00000000U)

/* GCREGMMUEXCEPTION1 */

#define CSL_BB2D_GCREGMMUEXCEPTION1_ADDRESS_MASK                (0xFFFFFFFFU)
#define CSL_BB2D_GCREGMMUEXCEPTION1_ADDRESS_SHIFT               (0U)
#define CSL_BB2D_GCREGMMUEXCEPTION1_ADDRESS_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCREGMMUEXCEPTION1_ADDRESS_MAX                 (0xffffffffU)

#define CSL_BB2D_GCREGMMUEXCEPTION1_RESETVAL                    (0x00000000U)

/* GCREGMMUEXCEPTION2 */

#define CSL_BB2D_GCREGMMUEXCEPTION2_ADDRESS_MASK                (0xFFFFFFFFU)
#define CSL_BB2D_GCREGMMUEXCEPTION2_ADDRESS_SHIFT               (0U)
#define CSL_BB2D_GCREGMMUEXCEPTION2_ADDRESS_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCREGMMUEXCEPTION2_ADDRESS_MAX                 (0xffffffffU)

#define CSL_BB2D_GCREGMMUEXCEPTION2_RESETVAL                    (0x00000000U)

/* GCREGMMUEXCEPTION3 */

#define CSL_BB2D_GCREGMMUEXCEPTION3_ADDRESS_MASK                (0xFFFFFFFFU)
#define CSL_BB2D_GCREGMMUEXCEPTION3_ADDRESS_SHIFT               (0U)
#define CSL_BB2D_GCREGMMUEXCEPTION3_ADDRESS_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCREGMMUEXCEPTION3_ADDRESS_MAX                 (0xffffffffU)

#define CSL_BB2D_GCREGMMUEXCEPTION3_RESETVAL                    (0x00000000U)

/* AQMEMORYDEBUG */

#define CSL_BB2D_AQMEMORYDEBUG_ZCOMP_LIMIT_MASK                 (0x3F000000U)
#define CSL_BB2D_AQMEMORYDEBUG_ZCOMP_LIMIT_SHIFT                (24U)
#define CSL_BB2D_AQMEMORYDEBUG_ZCOMP_LIMIT_RESETVAL             (0x0000003cU)
#define CSL_BB2D_AQMEMORYDEBUG_ZCOMP_LIMIT_MAX                  (0x0000003fU)

#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_WRITE_DATA_SPEEDUP_MASK  (0x00800000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_WRITE_DATA_SPEEDUP_SHIFT  (23U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_WRITE_DATA_SPEEDUP_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_WRITE_DATA_SPEEDUP_MAX   (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_ZCOMPRESSION_MASK        (0x00200000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_ZCOMPRESSION_SHIFT       (21U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_ZCOMPRESSION_RESETVAL    (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_ZCOMPRESSION_MAX         (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE_MASK  (0x00020000U)
#define CSL_BB2D_AQMEMORYDEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE_SHIFT  (17U)
#define CSL_BB2D_AQMEMORYDEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE_MAX  (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS_MASK  (0x40000000U)
#define CSL_BB2D_AQMEMORYDEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS_SHIFT  (30U)
#define CSL_BB2D_AQMEMORYDEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS_MAX  (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_MINI_MMU_CACHE_MASK      (0x00004000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_MINI_MMU_CACHE_SHIFT     (14U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_MINI_MMU_CACHE_RESETVAL  (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_MINI_MMU_CACHE_MAX       (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_MASK       (0x000000FFU)
#define CSL_BB2D_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_SHIFT      (0U)
#define CSL_BB2D_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_RESETVAL   (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_MAX        (0x000000ffU)

#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_STALL_READS_MASK         (0x00400000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_STALL_READS_SHIFT        (22U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_STALL_READS_RESETVAL     (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_STALL_READS_MAX          (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_FAST_CLEAR_MASK          (0x00100000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_FAST_CLEAR_SHIFT         (20U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_FAST_CLEAR_RESETVAL      (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_DISABLE_FAST_CLEAR_MAX           (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_LIMIT_CONTROL_MASK               (0x00080000U)
#define CSL_BB2D_AQMEMORYDEBUG_LIMIT_CONTROL_SHIFT              (19U)
#define CSL_BB2D_AQMEMORYDEBUG_LIMIT_CONTROL_RESETVAL           (0x00000000U)
#define CSL_BB2D_AQMEMORYDEBUG_LIMIT_CONTROL_MAX                (0x00000001U)

#define CSL_BB2D_AQMEMORYDEBUG_RESETVAL                         (0x3c000000U)

/* AQREGISTERTIMINGCONTROL */

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_RTC_MASK          (0x00030000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_RTC_SHIFT         (16U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_RTC_RESETVAL      (0x00000003U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_RTC_MAX           (0x00000003U)

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_WTC_MASK          (0x000C0000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_WTC_SHIFT         (18U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_WTC_RESETVAL      (0x00000000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FAST_WTC_MAX           (0x00000003U)

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF2P_MASK          (0x0000FF00U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF2P_SHIFT         (8U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF2P_RESETVAL      (0x00000000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF2P_MAX           (0x000000ffU)

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF1P_MASK          (0x000000FFU)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF1P_SHIFT         (0U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF1P_RESETVAL      (0x00000000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_FOR_RF1P_MAX           (0x000000ffU)

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_MASK        (0x00200000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_SHIFT       (21U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_RESETVAL    (0x00000000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_MAX         (0x00000001U)

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_MASK       (0x00400000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_SHIFT      (22U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_RESETVAL   (0x00000000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_MAX        (0x00000001U)

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_POWER_DOWN_MASK        (0x00100000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_POWER_DOWN_SHIFT       (20U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_POWER_DOWN_RESETVAL    (0x00000000U)
#define CSL_BB2D_AQREGISTERTIMINGCONTROL_POWER_DOWN_MAX         (0x00000001U)

#define CSL_BB2D_AQREGISTERTIMINGCONTROL_RESETVAL               (0x00030000U)

/* GCMEMORYRESERVED */

#define CSL_BB2D_GCMEMORYRESERVED_RESETVAL                      (0x00000000U)

/* GCDISPLAYPRIORITY */

#define CSL_BB2D_GCDISPLAYPRIORITY_HIGH_MASK                    (0x0000FF00U)
#define CSL_BB2D_GCDISPLAYPRIORITY_HIGH_SHIFT                   (8U)
#define CSL_BB2D_GCDISPLAYPRIORITY_HIGH_RESETVAL                (0x00000001U)
#define CSL_BB2D_GCDISPLAYPRIORITY_HIGH_MAX                     (0x000000ffU)

#define CSL_BB2D_GCDISPLAYPRIORITY_PERIOD_MASK                  (0x000000FFU)
#define CSL_BB2D_GCDISPLAYPRIORITY_PERIOD_SHIFT                 (0U)
#define CSL_BB2D_GCDISPLAYPRIORITY_PERIOD_RESETVAL              (0x00000002U)
#define CSL_BB2D_GCDISPLAYPRIORITY_PERIOD_MAX                   (0x000000ffU)

#define CSL_BB2D_GCDISPLAYPRIORITY_RESETVAL                     (0x00000102U)

/* GCDBGCYCLECOUNTER */

#define CSL_BB2D_GCDBGCYCLECOUNTER_COUNT_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDBGCYCLECOUNTER_COUNT_SHIFT                  (0U)
#define CSL_BB2D_GCDBGCYCLECOUNTER_COUNT_RESETVAL               (0x00001c5eU)
#define CSL_BB2D_GCDBGCYCLECOUNTER_COUNT_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDBGCYCLECOUNTER_RESETVAL                     (0x00001c5eU)

/* GCOUTSTANDINGREADS0 */

#define CSL_BB2D_GCOUTSTANDINGREADS0_PEC_MASK                   (0x000000FFU)
#define CSL_BB2D_GCOUTSTANDINGREADS0_PEC_SHIFT                  (0U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_PEC_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_PEC_MAX                    (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS0_PEZ_MASK                   (0x0000FF00U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_PEZ_SHIFT                  (8U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_PEZ_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_PEZ_MAX                    (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS0_FE_MASK                    (0x00FF0000U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_FE_SHIFT                   (16U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_FE_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_FE_MAX                     (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS0_MMU_MASK                   (0xFF000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_MMU_SHIFT                  (24U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_MMU_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS0_MMU_MAX                    (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS0_RESETVAL                   (0x00000000U)

/* GCOUTSTANDINGREADS1 */

#define CSL_BB2D_GCOUTSTANDINGREADS1_TOTAL_MASK                 (0xFF000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_TOTAL_SHIFT                (24U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_TOTAL_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_TOTAL_MAX                  (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS1_FC_MASK                    (0x00FF0000U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_FC_SHIFT                   (16U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_FC_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_FC_MAX                     (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS1_TX_MASK                    (0x0000FF00U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_TX_SHIFT                   (8U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_TX_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_TX_MAX                     (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS1_RA_MASK                    (0x000000FFU)
#define CSL_BB2D_GCOUTSTANDINGREADS1_RA_SHIFT                   (0U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_RA_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGREADS1_RA_MAX                     (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGREADS1_RESETVAL                   (0x00000000U)

/* GCOUTSTANDINGWRITES */

#define CSL_BB2D_GCOUTSTANDINGWRITES_TOTAL_MASK                 (0xFF000000U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_TOTAL_SHIFT                (24U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_TOTAL_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_TOTAL_MAX                  (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGWRITES_FC_MASK                    (0x00FF0000U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_FC_SHIFT                   (16U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_FC_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_FC_MAX                     (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGWRITES_PEC_MASK                   (0x000000FFU)
#define CSL_BB2D_GCOUTSTANDINGWRITES_PEC_SHIFT                  (0U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_PEC_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_PEC_MAX                    (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGWRITES_PEZ_MASK                   (0x0000FF00U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_PEZ_SHIFT                  (8U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_PEZ_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCOUTSTANDINGWRITES_PEZ_MAX                    (0x000000ffU)

#define CSL_BB2D_GCOUTSTANDINGWRITES_RESETVAL                   (0x00000000U)

/* GCDEBUGSIGNALSRA */

#define CSL_BB2D_GCDEBUGSIGNALSRA_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSRA_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSRA_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSRA_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSRA_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSTX */

#define CSL_BB2D_GCDEBUGSIGNALSTX_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSTX_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSTX_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSTX_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSTX_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSFE */

#define CSL_BB2D_GCDEBUGSIGNALSFE_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSFE_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSFE_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSFE_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSFE_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSPE */

#define CSL_BB2D_GCDEBUGSIGNALSPE_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSPE_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSPE_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSPE_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSPE_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSDE */

#define CSL_BB2D_GCDEBUGSIGNALSDE_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSDE_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSDE_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSDE_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSDE_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSSH */

#define CSL_BB2D_GCDEBUGSIGNALSSH_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSSH_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSSH_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSSH_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSSH_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSPA */

#define CSL_BB2D_GCDEBUGSIGNALSPA_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSPA_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSPA_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSPA_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSPA_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSSE */

#define CSL_BB2D_GCDEBUGSIGNALSSE_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSSE_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSSE_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSSE_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSSE_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSMC */

#define CSL_BB2D_GCDEBUGSIGNALSMC_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSMC_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSMC_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSMC_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSMC_RESETVAL                      (0x00000000U)

/* GCDEBUGSIGNALSHI */

#define CSL_BB2D_GCDEBUGSIGNALSHI_SIGNAL_MASK                   (0xFFFFFFFFU)
#define CSL_BB2D_GCDEBUGSIGNALSHI_SIGNAL_SHIFT                  (0U)
#define CSL_BB2D_GCDEBUGSIGNALSHI_SIGNAL_RESETVAL               (0x00000000U)
#define CSL_BB2D_GCDEBUGSIGNALSHI_SIGNAL_MAX                    (0xffffffffU)

#define CSL_BB2D_GCDEBUGSIGNALSHI_RESETVAL                      (0x00000000U)

/* GCDEBUGCONTROL0 */

#define CSL_BB2D_GCDEBUGCONTROL0_SH_MASK                        (0x0F000000U)
#define CSL_BB2D_GCDEBUGCONTROL0_SH_SHIFT                       (24U)
#define CSL_BB2D_GCDEBUGCONTROL0_SH_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL0_SH_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL0_DE_MASK                        (0x00000F00U)
#define CSL_BB2D_GCDEBUGCONTROL0_DE_SHIFT                       (8U)
#define CSL_BB2D_GCDEBUGCONTROL0_DE_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL0_DE_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL0_PE_MASK                        (0x000F0000U)
#define CSL_BB2D_GCDEBUGCONTROL0_PE_SHIFT                       (16U)
#define CSL_BB2D_GCDEBUGCONTROL0_PE_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL0_PE_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL0_FE_MASK                        (0x0000000FU)
#define CSL_BB2D_GCDEBUGCONTROL0_FE_SHIFT                       (0U)
#define CSL_BB2D_GCDEBUGCONTROL0_FE_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL0_FE_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL0_RESETVAL                       (0x00000000U)

/* GCDEBUGCONTROL1 */

#define CSL_BB2D_GCDEBUGCONTROL1_SE_MASK                        (0x00000F00U)
#define CSL_BB2D_GCDEBUGCONTROL1_SE_SHIFT                       (8U)
#define CSL_BB2D_GCDEBUGCONTROL1_SE_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL1_SE_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL1_TX_MASK                        (0x0F000000U)
#define CSL_BB2D_GCDEBUGCONTROL1_TX_SHIFT                       (24U)
#define CSL_BB2D_GCDEBUGCONTROL1_TX_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL1_TX_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL1_PA_MASK                        (0x0000000FU)
#define CSL_BB2D_GCDEBUGCONTROL1_PA_SHIFT                       (0U)
#define CSL_BB2D_GCDEBUGCONTROL1_PA_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL1_PA_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL1_RA_MASK                        (0x000F0000U)
#define CSL_BB2D_GCDEBUGCONTROL1_RA_SHIFT                       (16U)
#define CSL_BB2D_GCDEBUGCONTROL1_RA_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL1_RA_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL1_RESETVAL                       (0x00000000U)

/* GCDEBUGCONTROL2 */

#define CSL_BB2D_GCDEBUGCONTROL2_HI_MASK                        (0x00000F00U)
#define CSL_BB2D_GCDEBUGCONTROL2_HI_SHIFT                       (8U)
#define CSL_BB2D_GCDEBUGCONTROL2_HI_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL2_HI_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL2_MC_MASK                        (0x0000000FU)
#define CSL_BB2D_GCDEBUGCONTROL2_MC_SHIFT                       (0U)
#define CSL_BB2D_GCDEBUGCONTROL2_MC_RESETVAL                    (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL2_MC_MAX                         (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL2_RESETVAL                       (0x00000000U)

/* GCDEBUGCONTROL3 */

#define CSL_BB2D_GCDEBUGCONTROL3_PROBE0_MASK                    (0x0000000FU)
#define CSL_BB2D_GCDEBUGCONTROL3_PROBE0_SHIFT                   (0U)
#define CSL_BB2D_GCDEBUGCONTROL3_PROBE0_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL3_PROBE0_MAX                     (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL3_PROBE1_MASK                    (0x00000F00U)
#define CSL_BB2D_GCDEBUGCONTROL3_PROBE1_SHIFT                   (8U)
#define CSL_BB2D_GCDEBUGCONTROL3_PROBE1_RESETVAL                (0x00000000U)
#define CSL_BB2D_GCDEBUGCONTROL3_PROBE1_MAX                     (0x0000000fU)

#define CSL_BB2D_GCDEBUGCONTROL3_RESETVAL                       (0x00000000U)

/* GCBUSCONTROL */

#define CSL_BB2D_GCBUSCONTROL_FCC_MASK                          (0x00000100U)
#define CSL_BB2D_GCBUSCONTROL_FCC_SHIFT                         (8U)
#define CSL_BB2D_GCBUSCONTROL_FCC_RESETVAL                      (0x00000000U)
#define CSL_BB2D_GCBUSCONTROL_FCC_MAX                           (0x00000001U)

#define CSL_BB2D_GCBUSCONTROL_FC_MASK                           (0x00000040U)
#define CSL_BB2D_GCBUSCONTROL_FC_SHIFT                          (6U)
#define CSL_BB2D_GCBUSCONTROL_FC_RESETVAL                       (0x00000000U)
#define CSL_BB2D_GCBUSCONTROL_FC_MAX                            (0x00000001U)

#define CSL_BB2D_GCBUSCONTROL_PEZ_MASK                          (0x00000002U)
#define CSL_BB2D_GCBUSCONTROL_PEZ_SHIFT                         (1U)
#define CSL_BB2D_GCBUSCONTROL_PEZ_RESETVAL                      (0x00000000U)
#define CSL_BB2D_GCBUSCONTROL_PEZ_MAX                           (0x00000001U)

#define CSL_BB2D_GCBUSCONTROL_TX_MASK                           (0x00000080U)
#define CSL_BB2D_GCBUSCONTROL_TX_SHIFT                          (7U)
#define CSL_BB2D_GCBUSCONTROL_TX_RESETVAL                       (0x00000001U)
#define CSL_BB2D_GCBUSCONTROL_TX_MAX                            (0x00000001U)

#define CSL_BB2D_GCBUSCONTROL_MMU_MASK                          (0x00000020U)
#define CSL_BB2D_GCBUSCONTROL_MMU_SHIFT                         (5U)
#define CSL_BB2D_GCBUSCONTROL_MMU_RESETVAL                      (0x00000001U)
#define CSL_BB2D_GCBUSCONTROL_MMU_MAX                           (0x00000001U)

#define CSL_BB2D_GCBUSCONTROL_PEC_MASK                          (0x00000001U)
#define CSL_BB2D_GCBUSCONTROL_PEC_SHIFT                         (0U)
#define CSL_BB2D_GCBUSCONTROL_PEC_RESETVAL                      (0x00000000U)
#define CSL_BB2D_GCBUSCONTROL_PEC_MAX                           (0x00000001U)

#define CSL_BB2D_GCBUSCONTROL_FE_MASK                           (0x00000008U)
#define CSL_BB2D_GCBUSCONTROL_FE_SHIFT                          (3U)
#define CSL_BB2D_GCBUSCONTROL_FE_RESETVAL                       (0x00000001U)
#define CSL_BB2D_GCBUSCONTROL_FE_MAX                            (0x00000001U)

#define CSL_BB2D_GCBUSCONTROL_RESETVAL                          (0x000000a8U)

/* GCREGENDIANNESS0 */

#define CSL_BB2D_GCREGENDIANNESS0_WORD_SWAP_MASK                (0xFFFFFFFFU)
#define CSL_BB2D_GCREGENDIANNESS0_WORD_SWAP_SHIFT               (0U)
#define CSL_BB2D_GCREGENDIANNESS0_WORD_SWAP_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCREGENDIANNESS0_WORD_SWAP_MAX                 (0xffffffffU)

#define CSL_BB2D_GCREGENDIANNESS0_RESETVAL                      (0x00000000U)

/* GCREGENDIANNESS1 */

#define CSL_BB2D_GCREGENDIANNESS1_BYTE_SWAP_MASK                (0xFFFFFFFFU)
#define CSL_BB2D_GCREGENDIANNESS1_BYTE_SWAP_SHIFT               (0U)
#define CSL_BB2D_GCREGENDIANNESS1_BYTE_SWAP_RESETVAL            (0x00000000U)
#define CSL_BB2D_GCREGENDIANNESS1_BYTE_SWAP_MAX                 (0xffffffffU)

#define CSL_BB2D_GCREGENDIANNESS1_RESETVAL                      (0x00000000U)

/* GCREGENDIANNESS2 */

#define CSL_BB2D_GCREGENDIANNESS2_BIT_SWAP_MASK                 (0xFFFFFFFFU)
#define CSL_BB2D_GCREGENDIANNESS2_BIT_SWAP_SHIFT                (0U)
#define CSL_BB2D_GCREGENDIANNESS2_BIT_SWAP_RESETVAL             (0x00000000U)
#define CSL_BB2D_GCREGENDIANNESS2_BIT_SWAP_MAX                  (0xffffffffU)

#define CSL_BB2D_GCREGENDIANNESS2_RESETVAL                      (0x00000000U)

/* GCREGDRAWPRIMITIVESTARTTIMESTAMP */

#define CSL_BB2D_GCREGDRAWPRIMITIVESTARTTIMESTAMP_START_TIME_MASK  (0xFFFFFFFFU)
#define CSL_BB2D_GCREGDRAWPRIMITIVESTARTTIMESTAMP_START_TIME_SHIFT  (0U)
#define CSL_BB2D_GCREGDRAWPRIMITIVESTARTTIMESTAMP_START_TIME_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCREGDRAWPRIMITIVESTARTTIMESTAMP_START_TIME_MAX  (0xffffffffU)

#define CSL_BB2D_GCREGDRAWPRIMITIVESTARTTIMESTAMP_RESETVAL      (0x00000000U)

/* GCREGDRAWPRIMITIVEENDTIMESTAMP */

#define CSL_BB2D_GCREGDRAWPRIMITIVEENDTIMESTAMP_END_TIME_MASK   (0xFFFFFFFFU)
#define CSL_BB2D_GCREGDRAWPRIMITIVEENDTIMESTAMP_END_TIME_SHIFT  (0U)
#define CSL_BB2D_GCREGDRAWPRIMITIVEENDTIMESTAMP_END_TIME_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCREGDRAWPRIMITIVEENDTIMESTAMP_END_TIME_MAX    (0xffffffffU)

#define CSL_BB2D_GCREGDRAWPRIMITIVEENDTIMESTAMP_RESETVAL        (0x00000000U)

/* GCREGCONTROL0 */

#define CSL_BB2D_GCREGCONTROL0_ENABLE_READ_MERGE_MASK           (0x00000001U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_READ_MERGE_SHIFT          (0U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_READ_MERGE_RESETVAL       (0x00000001U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_READ_MERGE_MAX            (0x00000001U)

#define CSL_BB2D_GCREGCONTROL0_OUTSTANDING_READS_PER_CHANNEL_MASK  (0x03FF0000U)
#define CSL_BB2D_GCREGCONTROL0_OUTSTANDING_READS_PER_CHANNEL_SHIFT  (16U)
#define CSL_BB2D_GCREGCONTROL0_OUTSTANDING_READS_PER_CHANNEL_RESETVAL  (0x00000080U)
#define CSL_BB2D_GCREGCONTROL0_OUTSTANDING_READS_PER_CHANNEL_MAX  (0x000003ffU)

#define CSL_BB2D_GCREGCONTROL0_MISC0_MASK                       (0x0000FFF0U)
#define CSL_BB2D_GCREGCONTROL0_MISC0_SHIFT                      (4U)
#define CSL_BB2D_GCREGCONTROL0_MISC0_RESETVAL                   (0x00000000U)
#define CSL_BB2D_GCREGCONTROL0_MISC0_MAX                        (0x00000fffU)

#define CSL_BB2D_GCREGCONTROL0_ENABLE_WRITE_MERGE_MASK          (0x00000004U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_WRITE_MERGE_SHIFT         (2U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_WRITE_MERGE_RESETVAL      (0x00000001U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_WRITE_MERGE_MAX           (0x00000001U)

#define CSL_BB2D_GCREGCONTROL0_MISC1_MASK                       (0xFC000000U)
#define CSL_BB2D_GCREGCONTROL0_MISC1_SHIFT                      (26U)
#define CSL_BB2D_GCREGCONTROL0_MISC1_RESETVAL                   (0x00000000U)
#define CSL_BB2D_GCREGCONTROL0_MISC1_MAX                        (0x0000003fU)

#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_MERGE_MASK      (0x00000002U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_MERGE_SHIFT     (1U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_MERGE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_MERGE_MAX       (0x00000001U)

#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_MASK  (0x00000008U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_SHIFT  (3U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_RESETVAL  (0x00000000U)
#define CSL_BB2D_GCREGCONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_MAX  (0x00000001U)

#define CSL_BB2D_GCREGCONTROL0_RESETVAL                         (0x00800005U)

/* AQCMDBUFFERADDR */

#define CSL_BB2D_AQCMDBUFFERADDR_TYPE_MASK                      (0x80000000U)
#define CSL_BB2D_AQCMDBUFFERADDR_TYPE_SHIFT                     (31U)
#define CSL_BB2D_AQCMDBUFFERADDR_TYPE_RESETVAL                  (0x00000000U)
#define CSL_BB2D_AQCMDBUFFERADDR_TYPE_MAX                       (0x00000001U)

#define CSL_BB2D_AQCMDBUFFERADDR_ADDRESS_MASK                   (0x7FFFFFFFU)
#define CSL_BB2D_AQCMDBUFFERADDR_ADDRESS_SHIFT                  (0U)
#define CSL_BB2D_AQCMDBUFFERADDR_ADDRESS_RESETVAL               (0x00000000U)
#define CSL_BB2D_AQCMDBUFFERADDR_ADDRESS_MAX                    (0x7fffffffU)

#define CSL_BB2D_AQCMDBUFFERADDR_RESETVAL                       (0x00000000U)

/* AQCMDBUFFERCTRL */

#define CSL_BB2D_AQCMDBUFFERCTRL_PREFETCH_MASK                  (0x0000FFFFU)
#define CSL_BB2D_AQCMDBUFFERCTRL_PREFETCH_SHIFT                 (0U)
#define CSL_BB2D_AQCMDBUFFERCTRL_PREFETCH_RESETVAL              (0x00000000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_PREFETCH_MAX                   (0x0000ffffU)

#define CSL_BB2D_AQCMDBUFFERCTRL_ENDIAN_CONTROL_MASK            (0x00300000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_ENDIAN_CONTROL_SHIFT           (20U)
#define CSL_BB2D_AQCMDBUFFERCTRL_ENDIAN_CONTROL_RESETVAL        (0x00000000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_ENDIAN_CONTROL_MAX             (0x00000003U)

#define CSL_BB2D_AQCMDBUFFERCTRL_ENABLE_MASK                    (0x00010000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_ENABLE_SHIFT                   (16U)
#define CSL_BB2D_AQCMDBUFFERCTRL_ENABLE_RESETVAL                (0x00000000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_ENABLE_MAX                     (0x00000001U)

#define CSL_BB2D_AQCMDBUFFERCTRL_NA1_MASK                       (0xFFC00000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_NA1_SHIFT                      (22U)
#define CSL_BB2D_AQCMDBUFFERCTRL_NA1_RESETVAL                   (0x00000000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_NA1_MAX                        (0x000003ffU)

#define CSL_BB2D_AQCMDBUFFERCTRL_NA_MASK                        (0x000E0000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_NA_SHIFT                       (17U)
#define CSL_BB2D_AQCMDBUFFERCTRL_NA_RESETVAL                    (0x00000000U)
#define CSL_BB2D_AQCMDBUFFERCTRL_NA_MAX                         (0x00000007U)

#define CSL_BB2D_AQCMDBUFFERCTRL_RESETVAL                       (0x00000000U)

/* AQFESTATUS */

#define CSL_BB2D_AQFESTATUS_COMMAND_DATA_MASK                   (0x00000001U)
#define CSL_BB2D_AQFESTATUS_COMMAND_DATA_SHIFT                  (0U)
#define CSL_BB2D_AQFESTATUS_COMMAND_DATA_RESETVAL               (0x00000000U)
#define CSL_BB2D_AQFESTATUS_COMMAND_DATA_MAX                    (0x00000001U)

#define CSL_BB2D_AQFESTATUS_RESETVAL                            (0x00000000U)

/* AQFEDEBUGSTATE */

#define CSL_BB2D_AQFEDEBUGSTATE_CMD_FETCH_STATE_MASK            (0x00000C00U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_FETCH_STATE_SHIFT           (10U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_FETCH_STATE_RESETVAL        (0x00000000U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_FETCH_STATE_MAX             (0x00000003U)

#define CSL_BB2D_AQFEDEBUGSTATE_CMD_STATE_MASK                  (0x0000001FU)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_STATE_SHIFT                 (0U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_STATE_RESETVAL              (0x00000000U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_STATE_MAX                   (0x0000001fU)

#define CSL_BB2D_AQFEDEBUGSTATE_CMD_DMA_STATE_MASK              (0x00000300U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_DMA_STATE_SHIFT             (8U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_DMA_STATE_RESETVAL          (0x00000000U)
#define CSL_BB2D_AQFEDEBUGSTATE_CMD_DMA_STATE_MAX               (0x00000003U)

#define CSL_BB2D_AQFEDEBUGSTATE_VE_REQ_STATE_MASK               (0x00030000U)
#define CSL_BB2D_AQFEDEBUGSTATE_VE_REQ_STATE_SHIFT              (16U)
#define CSL_BB2D_AQFEDEBUGSTATE_VE_REQ_STATE_RESETVAL           (0x00000000U)
#define CSL_BB2D_AQFEDEBUGSTATE_VE_REQ_STATE_MAX                (0x00000003U)

#define CSL_BB2D_AQFEDEBUGSTATE_CAL_STATE_MASK                  (0x0000C000U)
#define CSL_BB2D_AQFEDEBUGSTATE_CAL_STATE_SHIFT                 (14U)
#define CSL_BB2D_AQFEDEBUGSTATE_CAL_STATE_RESETVAL              (0x00000000U)
#define CSL_BB2D_AQFEDEBUGSTATE_CAL_STATE_MAX                   (0x00000003U)

#define CSL_BB2D_AQFEDEBUGSTATE_REQ_DMA_STATE_MASK              (0x00003000U)
#define CSL_BB2D_AQFEDEBUGSTATE_REQ_DMA_STATE_SHIFT             (12U)
#define CSL_BB2D_AQFEDEBUGSTATE_REQ_DMA_STATE_RESETVAL          (0x00000000U)
#define CSL_BB2D_AQFEDEBUGSTATE_REQ_DMA_STATE_MAX               (0x00000003U)

#define CSL_BB2D_AQFEDEBUGSTATE_RESETVAL                        (0x00000000U)

/* AQFEDEBUGCURCMDADR */

#define CSL_BB2D_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_MASK            (0xFFFFFFF8U)
#define CSL_BB2D_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_SHIFT           (3U)
#define CSL_BB2D_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_RESETVAL        (0x00000000U)
#define CSL_BB2D_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_MAX             (0x1fffffffU)

#define CSL_BB2D_AQFEDEBUGCURCMDADR_RESETVAL                    (0x00000000U)

/* AQFEDEBUGCMDLOWREG */

#define CSL_BB2D_AQFEDEBUGCMDLOWREG_CMD_LOW_REG_MASK            (0xFFFFFFFFU)
#define CSL_BB2D_AQFEDEBUGCMDLOWREG_CMD_LOW_REG_SHIFT           (0U)
#define CSL_BB2D_AQFEDEBUGCMDLOWREG_CMD_LOW_REG_RESETVAL        (0x00000000U)
#define CSL_BB2D_AQFEDEBUGCMDLOWREG_CMD_LOW_REG_MAX             (0xffffffffU)

#define CSL_BB2D_AQFEDEBUGCMDLOWREG_RESETVAL                    (0x00000000U)

/* AQFEDEBUGCMDHIREG */

#define CSL_BB2D_AQFEDEBUGCMDHIREG_CMD_HI_REG_MASK              (0xFFFFFFFFU)
#define CSL_BB2D_AQFEDEBUGCMDHIREG_CMD_HI_REG_SHIFT             (0U)
#define CSL_BB2D_AQFEDEBUGCMDHIREG_CMD_HI_REG_RESETVAL          (0x00000000U)
#define CSL_BB2D_AQFEDEBUGCMDHIREG_CMD_HI_REG_MAX               (0xffffffffU)

#define CSL_BB2D_AQFEDEBUGCMDHIREG_RESETVAL                     (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
