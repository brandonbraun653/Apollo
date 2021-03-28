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
#ifndef CSLR_SHA_H_
#define CSLR_SHA_H_

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
    volatile Uint32 S_ODIGEST_A;
    volatile Uint32 S_ODIGEST_B;
    volatile Uint32 S_ODIGEST_C;
    volatile Uint32 S_ODIGEST_D;
    volatile Uint32 S_ODIGEST_E;
    volatile Uint32 S_ODIGEST_F;
    volatile Uint32 S_ODIGEST_G;
    volatile Uint32 S_ODIGEST_H;
    volatile Uint32 S_IDIGEST_A;
    volatile Uint32 S_IDIGEST_B;
    volatile Uint32 S_IDIGEST_C;
    volatile Uint32 S_IDIGEST_D;
    volatile Uint32 S_IDIGEST_E;
    volatile Uint32 S_IDIGEST_F;
    volatile Uint32 S_IDIGEST_G;
    volatile Uint32 S_IDIGEST_H;
    volatile Uint32 S_DIGEST_COUNT;
    volatile Uint32 S_MODE;
    volatile Uint32 S_LENGTH;
    volatile Uint8  RSVD0[52];
    volatile Uint32 S_DATA0_IN;
    volatile Uint32 S_DATA1_IN;
    volatile Uint32 S_DATA2_IN;
    volatile Uint32 S_DATA3_IN;
    volatile Uint32 S_DATA4_IN;
    volatile Uint32 S_DATA5_IN;
    volatile Uint32 S_DATA6_IN;
    volatile Uint32 S_DATA7_IN;
    volatile Uint32 S_DATA8_IN;
    volatile Uint32 S_DATA9_IN;
    volatile Uint32 S_DATA10_IN;
    volatile Uint32 S_DATA11_IN;
    volatile Uint32 S_DATA12_IN;
    volatile Uint32 S_DATA13_IN;
    volatile Uint32 S_DATA14_IN;
    volatile Uint32 S_DATA15_IN;
    volatile Uint32 S_DATA16_IN;
    volatile Uint32 S_DATA17_IN;
    volatile Uint32 S_DATA18_IN;
    volatile Uint32 S_DATA19_IN;
    volatile Uint32 S_DATA20_IN;
    volatile Uint32 S_DATA21_IN;
    volatile Uint32 S_DATA22_IN;
    volatile Uint32 S_DATA23_IN;
    volatile Uint32 S_DATA24_IN;
    volatile Uint32 S_DATA25_IN;
    volatile Uint32 S_DATA26_IN;
    volatile Uint32 S_DATA27_IN;
    volatile Uint32 S_DATA28_IN;
    volatile Uint32 S_DATA29_IN;
    volatile Uint32 S_DATA30_IN;
    volatile Uint32 S_DATA31_IN;
    volatile Uint32 S_REVISION;
    volatile Uint8  RSVD1[12];
    volatile Uint32 S_SYSCONFIG;
    volatile Uint32 S_SYSSTS;
    volatile Uint32 S_IRQSTS;
    volatile Uint32 S_IRQEN;
    volatile Uint8  RSVD2[32];
    volatile Uint32 S_XSSTS;
    volatile Uint32 S_LOCKDOWN;
    volatile Uint8  RSVD3[184];
    volatile Uint32 SHA512_S_ODIGEST_A;
    volatile Uint32 SHA512_S_ODIGEST_B;
    volatile Uint32 SHA512_S_ODIGEST_C;
    volatile Uint32 SHA512_S_ODIGEST_D;
    volatile Uint32 SHA512_S_ODIGEST_E;
    volatile Uint32 SHA512_S_ODIGEST_F;
    volatile Uint32 SHA512_S_ODIGEST_G;
    volatile Uint32 SHA512_S_ODIGEST_H;
    volatile Uint32 SHA512_S_ODIGEST_I;
    volatile Uint32 SHA512_S_ODIGEST_J;
    volatile Uint32 SHA512_S_ODIGEST_K;
    volatile Uint32 SHA512_S_ODIGEST_L;
    volatile Uint32 SHA512_S_ODIGEST_M;
    volatile Uint32 SHA512_S_ODIGEST_N;
    volatile Uint32 SHA512_S_ODIGEST_O;
    volatile Uint32 SHA512_S_ODIGEST_P;
    volatile Uint32 SHA512_S_IDIGEST_A;
    volatile Uint32 SHA512_S_IDIGEST_B;
    volatile Uint32 SHA512_S_IDIGEST_C;
    volatile Uint32 SHA512_S_IDIGEST_D;
    volatile Uint32 SHA512_S_IDIGEST_E;
    volatile Uint32 SHA512_S_IDIGEST_F;
    volatile Uint32 SHA512_S_IDIGEST_G;
    volatile Uint32 SHA512_S_IDIGEST_H;
    volatile Uint32 SHA512_S_IDIGEST_I;
    volatile Uint32 SHA512_S_IDIGEST_J;
    volatile Uint32 SHA512_S_IDIGEST_K;
    volatile Uint32 SHA512_S_IDIGEST_L;
    volatile Uint32 SHA512_S_IDIGEST_M;
    volatile Uint32 SHA512_S_IDIGEST_N;
    volatile Uint32 SHA512_S_IDIGEST_O;
    volatile Uint32 SHA512_S_IDIGEST_P;
    volatile Uint32 SHA512_S_DIGEST_COUNT;
    volatile Uint32 SHA512_S_MODE;
    volatile Uint32 SHA512_S_LENGTH;
    volatile Uint8  RSVD4[1047924];
    volatile Uint32 P_ODIGEST_A;
    volatile Uint32 P_ODIGEST_B;
    volatile Uint32 P_ODIGEST_C;
    volatile Uint32 P_ODIGEST_D;
    volatile Uint32 P_ODIGEST_E;
    volatile Uint32 P_ODIGEST_F;
    volatile Uint32 P_ODIGEST_G;
    volatile Uint32 P_ODIGEST_H;
    volatile Uint32 P_IDIGEST_A;
    volatile Uint32 P_IDIGEST_B;
    volatile Uint32 P_IDIGEST_C;
    volatile Uint32 P_IDIGEST_D;
    volatile Uint32 P_IDIGEST_E;
    volatile Uint32 P_IDIGEST_F;
    volatile Uint32 P_IDIGEST_G;
    volatile Uint32 P_IDIGEST_H;
    volatile Uint32 P_DIGEST_COUNT;
    volatile Uint32 P_MODE;
    volatile Uint32 P_LENGTH;
    volatile Uint8  RSVD5[52];
    volatile Uint32 P_DATA0_IN;
    volatile Uint32 P_DATA1_IN;
    volatile Uint32 P_DATA2_IN;
    volatile Uint32 P_DATA3_IN;
    volatile Uint32 P_DATA4_IN;
    volatile Uint32 P_DATA5_IN;
    volatile Uint32 P_DATA6_IN;
    volatile Uint32 P_DATA7_IN;
    volatile Uint32 P_DATA8_IN;
    volatile Uint32 P_DATA9_IN;
    volatile Uint32 P_DATA10_IN;
    volatile Uint32 P_DATA11_IN;
    volatile Uint32 P_DATA12_IN;
    volatile Uint32 P_DATA13_IN;
    volatile Uint32 P_DATA14_IN;
    volatile Uint32 P_DATA15_IN;
    volatile Uint32 P_DATA16_IN;
    volatile Uint32 P_DATA17_IN;
    volatile Uint32 P_DATA18_IN;
    volatile Uint32 P_DATA19_IN;
    volatile Uint32 P_DATA20_IN;
    volatile Uint32 P_DATA21_IN;
    volatile Uint32 P_DATA22_IN;
    volatile Uint32 P_DATA23_IN;
    volatile Uint32 P_DATA24_IN;
    volatile Uint32 P_DATA25_IN;
    volatile Uint32 P_DATA26_IN;
    volatile Uint32 P_DATA27_IN;
    volatile Uint32 P_DATA28_IN;
    volatile Uint32 P_DATA29_IN;
    volatile Uint32 P_DATA30_IN;
    volatile Uint32 P_DATA31_IN;
    volatile Uint32 P_REVISION;
    volatile Uint8  RSVD6[12];
    volatile Uint32 P_SYSCONFIG;
    volatile Uint32 P_SYSSTS;
    volatile Uint32 P_IRQSTS;
    volatile Uint32 P_IRQEN;
    volatile Uint8  RSVD7[224];
    volatile Uint32 SHA512_P_ODIGEST_A;
    volatile Uint32 SHA512_P_ODIGEST_B;
    volatile Uint32 SHA512_P_ODIGEST_C;
    volatile Uint32 SHA512_P_ODIGEST_D;
    volatile Uint32 SHA512_P_ODIGEST_E;
    volatile Uint32 SHA512_P_ODIGEST_F;
    volatile Uint32 SHA512_P_ODIGEST_G;
    volatile Uint32 SHA512_P_ODIGEST_H;
    volatile Uint32 SHA512_P_ODIGEST_I;
    volatile Uint32 SHA512_P_ODIGEST_J;
    volatile Uint32 SHA512_P_ODIGEST_K;
    volatile Uint32 SHA512_P_ODIGEST_L;
    volatile Uint32 SHA512_P_ODIGEST_M;
    volatile Uint32 SHA512_P_ODIGEST_N;
    volatile Uint32 SHA512_P_ODIGEST_O;
    volatile Uint32 SHA512_P_ODIGEST;
    volatile Uint32 SHA512_P_IDIGEST_A;
    volatile Uint32 SHA512_P_IDIGEST_B;
    volatile Uint32 SHA512_P_IDIGEST_C;
    volatile Uint32 SHA512_P_IDIGEST_D;
    volatile Uint32 SHA512_P_IDIGEST_E;
    volatile Uint32 SHA512_P_IDIGEST_F;
    volatile Uint32 SHA512_P_IDIGEST_G;
    volatile Uint32 SHA512_P_IDIGEST_H;
    volatile Uint32 SHA512_P_IDIGEST_I;
    volatile Uint32 SHA512_P_IDIGEST_J;
    volatile Uint32 SHA512_P_IDIGEST_K;
    volatile Uint32 SHA512_P_IDIGEST_L;
    volatile Uint32 SHA512_P_IDIGEST_M;
    volatile Uint32 SHA512_P_IDIGEST_N;
    volatile Uint32 SHA512_P_IDIGEST_O;
    volatile Uint32 SHA512_P_IDIGEST;
    volatile Uint32 SHA512_P_DIGEST_COUNT;
    volatile Uint32 SHA512_P_MODE;
    volatile Uint32 SHA512_P_LENGTH;
} CSL_ShaRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* WRITE: Outer Digest [127:96] for MD5, [159:128] for SHA-1, [255:224] for
 * SHA-2 / HMAC Key [31:0] for HMAC key proc READ: Outer Digest [127:96] for
 * MD5, [159:128] for SHA-1, [255:224] for SHA-2 */
#define CSL_SHA_S_ODIGEST_A                                     (0x0U)

/* WRITE: Outer Digest [95:64] for MD5, [127:96] for SHA-1, [223:192] for
 * SHA-2 / HMAC Key [63:32] for HMAC key proc READ: Outer Digest [95:64] for
 * MD5 [127:96] for SHA-1, [223:192] for SHA-2 */
#define CSL_SHA_S_ODIGEST_B                                     (0x4U)

/* WRITE: Outer Digest [63:32] for MD5, [95:64] for SHA-1, [191:160] for SHA-2
 * / HMAC Key [95:64] for HMAC key proc READ: Outer Digest [63:32] for MD5
 * [95:64] for SHA-1, [191:160] for SHA-2 */
#define CSL_SHA_S_ODIGEST_C                                     (0x8U)

/* WRITE: Outer Digest [31:0] for MD5 [63:31] for SHA-1, [159:128] for SHA-2 /
 * HMAC Key [127:96] for HMAC key proc READ: Outer Digest [31:0] for MD5
 * [63:32] for SHA-1, [159:128] for SHA-2 */
#define CSL_SHA_S_ODIGEST_D                                     (0xCU)

/* WRITE: Outer Digest [31:0] for SHA-1, [127:96] for SHA-2 / HMAC Key
 * [159:128] for HMAC key proc READ: Outer Digest [31:0] for SHA-1, [127:96]
 * for SHA-2 */
#define CSL_SHA_S_ODIGEST_E                                     (0x10U)

/* WRITE: Outer Digest [95:64] for SHA-2 / HMAC Key [191:160] for HMAC key
 * proc READ: Outer Digest [95:64] for SHA-2 */
#define CSL_SHA_S_ODIGEST_F                                     (0x14U)

/* WRITE: Outer Digest [63:32] for SHA-2 / HMAC Key [223:192] for HMAC key
 * proc READ: Outer Digest [63:32] for SHA-2 */
#define CSL_SHA_S_ODIGEST_G                                     (0x18U)

/* WRITE: Outer Digest [31:0] for SHA-2 / HMAC Key [255:224] for HMAC key proc
 * READ: Outer Digest [31:0] for SHA-2 */
#define CSL_SHA_S_ODIGEST_H                                     (0x1CU)

/* WRITE: Inner / Initial Digest [127:96] for MD5 [159:128] for SHA-1,
 * [255:224] for SHA-2 / HMAC Key [287:256] for HMAC key proc READ:
 * Intermediate / Inner Digest [127:96] for MD5 [159:128] for SHA-1, [255:224]
 * for SHA-2 / Result Digest/MAC [127:96] for MD5 [159:128] for SHA-1,
 * [223:192] for SHA-2 224, [255:224] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_A                                     (0x20U)

/* WRITE: Inner / Initial Digest [95:64] for MD5 [127:96] for SHA-1, [223:192]
 * for SHA-2 / HMAC Key [319:288] for HMAC key proc READ: Intermediate / Inner
 * Digest [95:64] for MD5 [127:96] for SHA-1, [223:192] for SHA-2 / Result
 * Digest/MAC [95:64] for MD5 [127:96] for SHA-1, [191:160] for SHA-2 224,
 * [223:192] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_B                                     (0x24U)

/* WRITE: Inner / Initial Digest [63:32] for MD5 [95:64] for SHA-1, [191:160]
 * for SHA- 2 / HMAC Key [351:320] for HMAC key proc READ: Intermediate /
 * Inner Digest [63:32] for MD5 [95:64] for SHA-1, [191:160] for SHA-2 /
 * Result Digest/MAC [63:32] for MD5 [95:64] for SHA-1, [159:128] for SHA-2
 * 224, [191:160] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_C                                     (0x28U)

/* WRITE: Inner / Initial Digest [31:0] for MD5 [63:32] for SHA-1, [159:128]
 * for SHA-2 / HMAC Key [383:352] for HMAC key proc READ: Intermediate / Inner
 * Digest [31:0] for MD5 [63:32] for SHA-1, [159:128] for SHA-2 / Result
 * Digest/MAC [31:0] for MD5 [63:32] for SHA-1, [127:96] for SHA-2 224,
 * [159:128] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_D                                     (0x2CU)

/* WRITE: Inner / Initial Digest [31:0] for SHA-1, [127:96] for SHA-2 / HMAC
 * Key [415:384] for HMAC key proc READ: Intermediate / Inner Digest [31:0]
 * for SHA-1, [127:96] for SHA-2 / Result Digest/MAC [31:0] for SHA-1, [95:64]
 * for SHA-2 224, [127:96] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_E                                     (0x30U)

/* WRITE: Inner / Initial Digest [95:64] for SHA-2 / HMAC Key [447:416] for
 * HMAC key proc READ: Intermediate / Inner Digest [95:64] for SHA-2 / Result
 * Digest/MAC [63:32] for SHA-2 224, [95:64] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_F                                     (0x34U)

/* WRITE: Inner / Initial Digest [63:32] for SHA-2 / HMAC Key [479:448] for
 * HMAC key proc READ: Intermediate / Inner Digest [63:32] for SHA-2 / Result
 * Digest/MAC [31:0] for SHA-2 224, [63:32] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_G                                     (0x38U)

/* WRITE: Inner / Initial Digest [31:0] for SHA-2 / HMAC Key [511:480] for
 * HMAC key proc READ: Intermediate / Inner Digest [31:0] for SHA-2 / Result
 * Digest/MAC [31:0] for SHA-2 256 */
#define CSL_SHA_S_IDIGEST_H                                     (0x3CU)

/* WRITE: Initial Digest Count ([31:6] only, [5:0] assumed 0) READ: Result /
 * IntermediateDigest Count The initial digest byte count for hash/HMAC
 * continue operations (HMAC Key Processing = 0 and Use Algorithm Constants =
 * 0) on the Secure World must be written to this register prior to starting
 * the operation by writing to SHA_S_MODE. When either HMAC Key Processing is
 * 1 or Use Algorithm Constants is 1, this register does not need to be
 * written, it will be overwritten with 64 (1 hash block of key XOR ipad) or 0
 * respectively, automatically. When starting a HMAC operation from
 * pre-computes (HMAC Key Processing is 0), then the value 64 must be written
 * here to compensate for the appended key XOR ipad block. Note that the value
 * written should always be a 64 byte multiple, the lower 6 bits written are
 * ignored. The updated digest byte count (initial digest byte count + bytes
 * processed) can be read from this register when the status register
 * indicates that the operation is done or suspended due to a context switch
 * request, or when a Secure World context out DMA is requested. In Advanced
 * DMA mode, when not suspended with a partial result, reading the
 * SHA_S_DIGEST_COUNT register triggers the Hash/HMAC Engine to start the next
 * context input DMA. Therefore, reading the SHA_S_DIGEST_COUNT register
 * should always be the last context-read action if not suspended with a
 * partial result (i.e. PartHashReady interrupt not pending). */
#define CSL_SHA_S_DIGEST_COUNT                                  (0x40U)

/* Register SHA_MODE */
#define CSL_SHA_S_MODE                                          (0x44U)

/* WRITE: Block Length / Remaining Byte Count (bytes) READ: Remaining Byte
 * Count. The value programmed MUST be a 64-byte multiple if Close Hash is set
 * to 0. This register is also the trigger to start processing: once this
 * register is written, the core will commence requesting input data via DMA
 * or IRQ (if programmed length > 0) and start processing. The remaining byte
 * count for the active operation can be read from this register when the
 * interrupt status register indicates that the operation is suspended due to
 * a context switch request. */
#define CSL_SHA_S_LENGTH                                        (0x48U)

/* Data input message 0 */
#define CSL_SHA_S_DATA0_IN                                      (0x80U)

/* Data input message 1 */
#define CSL_SHA_S_DATA1_IN                                      (0x84U)

/* Data input message 2 */
#define CSL_SHA_S_DATA2_IN                                      (0x88U)

/* Data input message 3 */
#define CSL_SHA_S_DATA3_IN                                      (0x8CU)

/* Data input message 4 */
#define CSL_SHA_S_DATA4_IN                                      (0x90U)

/* Data input message 5 */
#define CSL_SHA_S_DATA5_IN                                      (0x94U)

/* Data input message 6 */
#define CSL_SHA_S_DATA6_IN                                      (0x98U)

/* Data input message 7 */
#define CSL_SHA_S_DATA7_IN                                      (0x9CU)

/* Data input message 8 */
#define CSL_SHA_S_DATA8_IN                                      (0xA0U)

/* Data input message 9 */
#define CSL_SHA_S_DATA9_IN                                      (0xA4U)

/* Data input message 10 */
#define CSL_SHA_S_DATA10_IN                                     (0xA8U)

/* Data input message 11 */
#define CSL_SHA_S_DATA11_IN                                     (0xACU)

/* Data input message 12 */
#define CSL_SHA_S_DATA12_IN                                     (0xB0U)

/* Data input message 13 */
#define CSL_SHA_S_DATA13_IN                                     (0xB4U)

/* Data input message 14 */
#define CSL_SHA_S_DATA14_IN                                     (0xB8U)

/* Data input message 15 */
#define CSL_SHA_S_DATA15_IN                                     (0xBCU)

/* Data input message 16 */
#define CSL_SHA_S_DATA16_IN                                     (0xC0U)

/* Data input message 17 */
#define CSL_SHA_S_DATA17_IN                                     (0xC4U)

/* Data input message 18 */
#define CSL_SHA_S_DATA18_IN                                     (0xC8U)

/* Data input message 19 */
#define CSL_SHA_S_DATA19_IN                                     (0xCCU)

/* Data input message 20 */
#define CSL_SHA_S_DATA20_IN                                     (0xD0U)

/* Data input message 21 */
#define CSL_SHA_S_DATA21_IN                                     (0xD4U)

/* Data input message 22 */
#define CSL_SHA_S_DATA22_IN                                     (0xD8U)

/* Data input message 23 */
#define CSL_SHA_S_DATA23_IN                                     (0xDCU)

/* Data input message 24 */
#define CSL_SHA_S_DATA24_IN                                     (0xE0U)

/* Data input message 25 */
#define CSL_SHA_S_DATA25_IN                                     (0xE4U)

/* Data input message 26 */
#define CSL_SHA_S_DATA26_IN                                     (0xE8U)

/* Data input message 27 */
#define CSL_SHA_S_DATA27_IN                                     (0xECU)

/* Data input message 28 */
#define CSL_SHA_S_DATA28_IN                                     (0xF0U)

/* Data input message 29 */
#define CSL_SHA_S_DATA29_IN                                     (0xF4U)

/* Data input message 30 */
#define CSL_SHA_S_DATA30_IN                                     (0xF8U)

/* Data input message 31 */
#define CSL_SHA_S_DATA31_IN                                     (0xFCU)

/* Register SHA_REVISION */
#define CSL_SHA_S_REVISION                                      (0x100U)

/* Register SHA_SYSCONFIG */
#define CSL_SHA_S_SYSCONFIG                                     (0x110U)

/* Register SHA_S_SYSSTATUS */
#define CSL_SHA_S_SYSSTS                                        (0x114U)

/* Register SHA_S_IRQSTATUS */
#define CSL_SHA_S_IRQSTS                                        (0x118U)

/* Register SHA_S_IRQENABLE. The SHA_S_IRQENABLE register contains an enable
 * bit for each unique interrupt for the secure side. An interrupt is enabled
 * when both the global enable in SHA_S_SYSCONFIG (SIT_en) and the bit in this
 * register are both set to 1. An interrupt that is enabled is propagated to
 * the SINTREQUEST_S output. Please note that the dedicated partial hash
 * output (SINTREQUEST_PART_S) is not affected by this register, it is only
 * affected by the global enable SHA_S_SYSCONFIG (SIT_en). */
#define CSL_SHA_S_IRQEN                                         (0x11CU)

/* Register SHA_S_XSSTATUS */
#define CSL_SHA_S_XSSTS                                         (0x140U)

/* Register SHA_S_LOCKDOWN. The SHA_S_LOCKDOWN register contains 'lock' bits
 * that, when set, prevent certain Public World context and control fields
 * from being overwritten. Since only the Secure World can access the
 * SHA_S_LOCKDOWN register, this prevents the Public World from touching these
 * fields. */
#define CSL_SHA_S_LOCKDOWN                                      (0x144U)

/* W: Outer Digest [511:480] for SHA-384 and SHA-512 / SHA512_HMAC Key [31:0]
 * for HMAC key proc R: Outer Digest [511:480] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_A                              (0x200U)

/* W: Outer Digest [479:448] for SHA-384 and SHA-512 / SHA512_HMAC Key [63:32]
 * for HMAC key proc R: Outer Digest [479:448] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_B                              (0x204U)

/* W: Outer Digest [447:416] for SHA-384 and SHA-512 / SHA512_HMAC Key [95:64]
 * for HMAC key proc R: Outer Digest [447:416] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_C                              (0x208U)

/* W: Outer Digest [415:384] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [127:96] for HMAC key proc R: Outer Digest [415:384] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_D                              (0x20CU)

/* W: Outer Digest [383:352] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [159:128] for HMAC key proc R: Outer Digest [383:352] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_E                              (0x210U)

/* W: Outer Digest [351:320] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [191:160] for HMAC key proc R: Outer Digest [351:320] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_F                              (0x214U)

/* W: Outer Digest [319:288] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [223:192] for HMAC key proc R: Outer Digest [319:288] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_G                              (0x218U)

/* W: Outer Digest [287:256] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [255:244] for HMAC key proc R: Outer Digest [287:256] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_H                              (0x21CU)

/* W: Outer Digest [255:224] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [287:256] for HMAC key proc R: Outer Digest [255:224] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_I                              (0x220U)

/* W: Outer Digest [223:192] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [319:288] for HMAC key proc R: Outer Digest [223:129] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_J                              (0x224U)

/* W: Outer Digest [191:160] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [351:320] for HMAC key proc R: Outer Digest [191:160] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_K                              (0x228U)

/* W: Outer Digest [159:128] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [383:352] for HMAC key proc R: Outer Digest [159:128] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_L                              (0x22CU)

/* W: Outer Digest [128:96] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [415:384] for HMAC key proc R: Outer Digest [128:96] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_M                              (0x230U)

/* W: Outer Digest [95:64] for SHA-384 and SHA-512 / SHA512_HMAC Key [447:416]
 * for HMAC key proc R: Outer Digest [95:64] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_N                              (0x234U)

/* W: Outer Digest [63:32] for SHA-384 and SHA-512 / SHA512_HMAC Key [479:448]
 * for HMAC key proc R: Outer Digest [63:32] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_O                              (0x238U)

/* W: Outer Digest [31:0] for SHA-384 and SHA-512 / SHA512_HMAC Key [511:480]
 * for HMAC key proc R: Outer Digest [31:0] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_S_ODIGEST_P                              (0x23CU)

/* W: Inner / Initial Digest [383:352] for SHA-384 and [511:480] for SHA-512 /
 * SHA512_HMAC Key [543:512] for HMAC key proc R: Intermediate / Inner Digest
 * [383:352] for SHA-384 and [511:480] for SHA-512 Result Digest/MAC Digest
 * [383:352] for SHA-384 and [511:480] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_A                              (0x240U)

/* W: Inner / Initial Digest [351:320] for SHA-384 and [479:448] for SHA-512 /
 * SHA512_HMAC Key [575:544] for HMAC key proc R: Intermediate / Inner Digest
 * [351:320] for SHA-384 and [479:448] for SHA-512 Result Digest/MAC Digest
 * [351:320] for SHA-384 and [479:448] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_B                              (0x244U)

/* W: Inner / Initial Digest [319:288] for SHA-384 and [447:416] for SHA-512 /
 * SHA512_HMAC Key [607:576] for HMAC key proc R: Intermediate / Inner Digest
 * [319:288] for SHA-384 and [447:416] for SHA-512 Result Digest/MAC Digest
 * [319:288] for SHA-384 and [447:416] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_C                              (0x248U)

/* W: Inner / Initial Digest [287:256] for SHA-384 and [415:384] for SHA-512 /
 * SHA512_HMAC Key [639:608] for HMAC key proc R: Intermediate / Inner Digest
 * [287:256] for SHA-384 and [415:384] for SHA-512 Result Digest/MAC Digest
 * [287:256] for SHA-384 and [415:384] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_D                              (0x24CU)

/* W: Inner / Initial Digest [255:224] for SHA-384 and [383:352] for SHA-512 /
 * SHA512_HMAC Key [671:640] for HMAC key proc R: Intermediate / Inner Digest
 * [255:224] for SHA-384 and [383:352] for SHA-512 Result Digest/MAC Digest
 * [255:224] for SHA-384 and [383:352] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_E                              (0x250U)

/* W: Inner / Initial Digest [223:192] for SHA-384 and [351:320] for SHA-512 /
 * SHA512_HMAC Key [703:672] for HMAC key proc R: Intermediate / Inner Digest
 * [223:192] for SHA-384 and [351:320] for SHA-512 Result Digest/MAC Digest
 * [223:192] for SHA-384 and [351:320] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_F                              (0x254U)

/* W: Inner / Initial Digest [191:160] for SHA-384 and [319:288] for SHA-512 /
 * SHA512_HMAC Key [735:704] for HMAC key proc R: Intermediate / Inner Digest
 * [191:160] for SHA-384 and [319:288] for SHA-512 Result Digest/MAC Digest
 * [191:160] for SHA-384 and [319:288] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_G                              (0x258U)

/* W: Inner / Initial Digest [159:128] for SHA-384 and [287:256] for SHA-512 /
 * SHA512_HMAC Key [767:736] for HMAC key proc R: Intermediate / Inner Digest
 * [159:128] for SHA-384 and [287:256] for SHA-512 Result Digest/MAC Digest
 * [159:128] for SHA-384 and [287:256] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_H                              (0x25CU)

/* W: Inner / Initial Digest [127:96] for SHA-384 and [255:224] for SHA-512 /
 * SHA512_HMAC Key [799:768] for HMAC key proc R: Intermediate / Inner Digest
 * [127:96] for SHA-384 and [255:224] for SHA-512 Result Digest/MAC Digest
 * [127:96] for SHA-384 and [255:224] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_I                              (0x260U)

/* W: Inner / Initial Digest [95:64] for SHA-384 and [223:192] for SHA-512 /
 * SHA512_HMAC Key [831:800] for HMAC key proc R: Intermediate / Inner Digest
 * [95:64] for SHA-384 and [223:192] for SHA-512 Result Digest/MAC Digest
 * [95:64] for SHA-384 and [223:192] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_J                              (0x264U)

/* W: Inner / Initial Digest [63:32] for SHA-384 and [191:160] for SHA-512 /
 * SHA512_HMAC Key [863:832] for HMAC key proc R: Intermediate / Inner Digest
 * [63:32] for SHA-384 and [191:160] for SHA-512 Result Digest/MAC Digest
 * [63:32] for SHA-384 and [191:160] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_K                              (0x268U)

/* W: Inner / Initial Digest [31:0] for SHA-384 and [159:128] for SHA-512 /
 * SHA512_HMAC Key [895:864] for HMAC key proc R: Intermediate / Inner Digest
 * [31:0] for SHA-384 and [159:128] for SHA-512 Result Digest/MAC Digest
 * [31:0] for SHA-384 and [159:128] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_L                              (0x26CU)

/* W: Inner / Initial Digest [127:96] for SHA-512 / SHA512_HMAC Key [927:896]
 * for HMAC key proc R: Intermediate / Inner Digest [127:96] for SHA-512
 * Result Digest/MAC Digest [127:96] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_M                              (0x270U)

/* W: Inner / Initial Digest [95:64] for SHA-512 / SHA512_HMAC Key [959:928]
 * for HMAC key proc R: Intermediate / Inner Digest [95:64] for SHA-512 Result
 * Digest/MAC Digest [95:64] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_N                              (0x274U)

/* W: Inner / Initial Digest [63:32] for SHA-512 / SHA512_HMAC Key [991:960]
 * for HMAC key proc R: Intermediate / Inner Digest [63:32] for SHA-512 Result
 * Digest/MAC Digest [63:32] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_O                              (0x278U)

/* W: Inner / Initial Digest [31:0] for SHA-512 / SHA512_HMAC Key [1023:992]
 * for HMAC key proc R: Intermediate / Inner Digest [31:0] for SHA-512 Result
 * Digest/MAC Digest [31:0] for SHA-512 */
#define CSL_SHA_SHA512_S_IDIGEST_P                              (0x27CU)

/* W: Initial Digest Count ([31:7] only, [6:0] assumed 0) R: Result /
 * IntermediateDigest Count The initial digest byte count for hash/HMAC
 * continue operations (HMAC Key Processing = 0 and Use Algorithm Constants =
 * 0) on the Secure World must be written to this register prior to starting
 * the operation by writing to SHA_S_MODE. When either HMAC Key Processing is
 * 1 or Use Algorithm Constants is 1, this register does not need to be
 * written, it will be overwritten with 128 (1 hash block of key XOR ipad) or
 * 0 respectively, automatically. When starting a HMAC operation from
 * pre-computes (HMAC Key Processing is 0), then the value 128 must be written
 * here to compensate for the appended key XOR ipad block. Note that the value
 * written should always be a 128 byte multiple, the lower 7 bits written are
 * ignored. The updated digest byte count (initial digest byte count + bytes
 * processed) can be read from this register when the status register
 * indicates that the operation is done or suspended due to a context switch
 * request, or when a Secure World context out DMA is requested. In Advanced
 * DMA mode, when not suspended with a partial result, reading the
 * SHA512_S_DIGEST_COUNT register triggers the Hash/HMAC Engine to start the
 * next context input DMA. Therefore, reading the SHA512_S_DIGEST_COUNT
 * register should always be the last context-read action if not suspended
 * with a partial result (i.e. PartHashReady interrupt not pending). */
#define CSL_SHA_SHA512_S_DIGEST_COUNT                           (0x280U)

/* Register SHA_MODE. Configures the operation to be performed */
#define CSL_SHA_SHA512_S_MODE                                   (0x284U)

/* W: Block Length / Remaining Byte Count (bytes) R: Remaining Byte Count The
 * length of the block to be processed, in bytes, for hash/HMAC operations on
 * the HIB1 must be written to this register prior to starting the operation
 * by writing to SHA512_S_MODE. The value programmed MUST be a 128-byte
 * multiple if Close Hash is set to 0. This register is also the trigger to
 * start processing: once this register is written, the core will commence
 * requesting input data via DMA or interrupt (if programmed length > 0) and
 * start processing. The assertion of the input data DMA and/or interrupt will
 * happen for both DMA modes (Advanced and 'Legacy'), if enabled. */
#define CSL_SHA_SHA512_S_LENGTH                                 (0x288U)

/* WRITE: Outer Digest [127:96] for MD5, [159:128] for SHA-1, [255:224] for
 * SHA-2 / HMAC Key [31:0] for HMAC key proc READ: Outer Digest [127:96] for
 * MD5, [159:128] for SHA-1, [255:224] for SHA-2 */
#define CSL_SHA_P_ODIGEST_A                                     (0x100000U)

/* WRITE: Outer Digest [95:64] for MD5, [127:96] for SHA-1, [223:192] for
 * SHA-2 / HMAC Key [63:32] for HMAC key proc READ: Outer Digest [95:64] for
 * MD5 [127:96] for SHA-1, [223:192] for SHA-2 */
#define CSL_SHA_P_ODIGEST_B                                     (0x100004U)

/* WRITE: Outer Digest [63:32] for MD5, [95:64] for SHA-1, [191:160] for SHA-2
 * / HMAC Key [95:64] for HMAC key proc READ: Outer Digest [63:32] for MD5
 * [95:64] for SHA-1, [191:160] for SHA-2 */
#define CSL_SHA_P_ODIGEST_C                                     (0x100008U)

/* WRITE: Outer Digest [31:0] for MD5 [63:31] for SHA-1, [159:128] for SHA-2 /
 * HMAC Key [127:96] for HMAC key proc READ: Outer Digest [31:0] for MD5
 * [63:32] for SHA-1, [159:128] for SHA-2 */
#define CSL_SHA_P_ODIGEST_D                                     (0x10000CU)

/* WRITE: Outer Digest [31:0] for SHA-1, [127:96] for SHA-2 / HMAC Key
 * [159:128] for HMAC key proc READ: Outer Digest [31:0] for SHA-1, [127:96]
 * for SHA-2 */
#define CSL_SHA_P_ODIGEST_E                                     (0x100010U)

/* WRITE: Outer Digest [95:64] for SHA-2 / HMAC Key [191:160] for HMAC key
 * proc READ: Outer Digest [95:64] for SHA-2 */
#define CSL_SHA_P_ODIGEST_F                                     (0x100014U)

/* WRITE: Outer Digest [63:32] for SHA-2 / HMAC Key [223:192] for HMAC key
 * proc READ: Outer Digest [63:32] for SHA-2 */
#define CSL_SHA_P_ODIGEST_G                                     (0x100018U)

/* WRITE: Outer Digest [31:0] for SHA-2 / HMAC Key [255:224] for HMAC key proc
 * READ: Outer Digest [31:0] for SHA-2 */
#define CSL_SHA_P_ODIGEST_H                                     (0x10001CU)

/* WRITE: Inner / Initial Digest [127:96] for MD5 [159:128] for SHA-1,
 * [255:224] for SHA-2 / HMAC Key [287:256] for HMAC key proc READ:
 * Intermediate / Inner Digest [127:96] for MD5 [159:128] for SHA-1, [255:224]
 * for SHA-2 / Result Digest/MAC [127:96] for MD5 [159:128] for SHA-1,
 * [223:192] for SHA-2 224, [255:224] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_A                                     (0x100020U)

/* WRITE: Inner / Initial Digest [95:64] for MD5 [127:96] for SHA-1, [223:192]
 * for SHA-2 / HMAC Key [319:288] for HMAC key proc READ: Intermediate / Inner
 * Digest [95:64] for MD5 [127:96] for SHA-1, [223:192] for SHA-2 / Result
 * Digest/MAC [95:64] for MD5 [127:96] for SHA-1, [191:160] for SHA-2 224,
 * [223:192] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_B                                     (0x100024U)

/* WRITE: Inner / Initial Digest [63:32] for MD5 [95:64] for SHA-1, [191:160]
 * for SHA- 2 / HMAC Key [351:320] for HMAC key proc READ: Intermediate /
 * Inner Digest [63:32] for MD5 [95:64] for SHA-1, [191:160] for SHA-2 /
 * Result Digest/MAC [63:32] for MD5 [95:64] for SHA-1, [159:128] for SHA-2
 * 224, [191:160] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_C                                     (0x100028U)

/* WRITE: Inner / Initial Digest [31:0] for MD5 [63:32] for SHA-1, [159:128]
 * for SHA-2 / HMAC Key [383:352] for HMAC key proc READ: Intermediate / Inner
 * Digest [31:0] for MD5 [63:32] for SHA-1, [159:128] for SHA-2 / Result
 * Digest/MAC [31:0] for MD5 [63:32] for SHA-1, [127:96] for SHA-2 224,
 * [159:128] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_D                                     (0x10002CU)

/* WRITE: Inner / Initial Digest [31:0] for SHA-1, [127:96] for SHA-2 / HMAC
 * Key [415:384] for HMAC key proc READ: Intermediate / Inner Digest [31:0]
 * for SHA-1, [127:96] for SHA-2 / Result Digest/MAC [31:0] for SHA-1, [95:64]
 * for SHA-2 224, [127:96] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_E                                     (0x100030U)

/* WRITE: Inner / Initial Digest [95:64] for SHA-2 / HMAC Key [447:416] for
 * HMAC key proc READ: Intermediate / Inner Digest [95:64] for SHA-2 / Result
 * Digest/MAC [63:32] for SHA-2 224, [95:64] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_F                                     (0x100034U)

/* WRITE: Inner / Initial Digest [63:32] for SHA-2 / HMAC Key [479:448] for
 * HMAC key proc READ: Intermediate / Inner Digest [63:32] for SHA-2 / Result
 * Digest/MAC [31:0] for SHA-2 224, [63:32] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_G                                     (0x100038U)

/* WRITE: Inner / Initial Digest [31:0] for SHA-2 / HMAC Key [511:480] for
 * HMAC key proc READ: Intermediate / Inner Digest [31:0] for SHA-2 / Result
 * Digest/MAC [31:0] for SHA-2 256 */
#define CSL_SHA_P_IDIGEST_H                                     (0x10003CU)

/* WRITE: Initial Digest Count ([31:6] only, [5:0] assumed 0) READ: Result /
 * IntermediateDigest Count The initial digest byte count for hash/HMAC
 * continue operations (HMAC Key Processing = 0 and Use Algorithm Constants =
 * 0) on the Public World must be written to this register prior to starting
 * the operation by writing to SHA_P_MODE. When either HMAC Key Processing is
 * 1 or Use Algorithm Constants is 1, this register does not need to be
 * written, it will be overwritten with 64 (1 hash block of key XOR ipad) or 0
 * respectively, automatically. When starting a HMAC operation from
 * pre-computes (HMAC Key Processing is 0), then the value 64 must be written
 * here to compensate for the appended key XOR ipad block. Note that the value
 * written should always be a 64 byte multiple, the lower 6 bits written are
 * ignored. The updated digest byte count (initial digest byte count + bytes
 * processed) can be read from this register when the status register
 * indicates that the operation is done or suspended due to a context switch
 * request, or when a Secure World context out DMA is requested. In Advanced
 * DMA mode, when not suspended with a partial result, reading the
 * SHA_P_DIGEST_COUNT register triggers the Hash/HMAC Engine to start the next
 * context input DMA. Therefore, reading the SHA_P_DIGEST_COUNT register
 * should always be the last context-read action if not suspended with a
 * partial result (i.e. PartHashReady interrupt not pending). */
#define CSL_SHA_P_DIGEST_COUNT                                  (0x100040U)

/* Register SHA_MODE */
#define CSL_SHA_P_MODE                                          (0x100044U)

/* WRITE: Block Length / Remaining Byte Count (bytes) READ: Remaining Byte
 * Count. The value programmed MUST be a 64-byte multiple if Close Hash is set
 * to 0. This register is also the trigger to start processing: once this
 * register is written, the core will commence requesting input data via DMA
 * or IRQ (if programmed length > 0) and start processing. The remaining byte
 * count for the active operation can be read from this register when the
 * interrupt status register indicates that the operation is suspended due to
 * a context switch request. */
#define CSL_SHA_P_LENGTH                                        (0x100048U)

/* Data input message 0 */
#define CSL_SHA_P_DATA0_IN                                      (0x100080U)

/* Data input message 1 */
#define CSL_SHA_P_DATA1_IN                                      (0x100084U)

/* Data input message 2 */
#define CSL_SHA_P_DATA2_IN                                      (0x100088U)

/* Data input message 3 */
#define CSL_SHA_P_DATA3_IN                                      (0x10008CU)

/* Data input message 4 */
#define CSL_SHA_P_DATA4_IN                                      (0x100090U)

/* Data input message 5 */
#define CSL_SHA_P_DATA5_IN                                      (0x100094U)

/* Data input message 6 */
#define CSL_SHA_P_DATA6_IN                                      (0x100098U)

/* Data input message 7 */
#define CSL_SHA_P_DATA7_IN                                      (0x10009CU)

/* Data input message 8 */
#define CSL_SHA_P_DATA8_IN                                      (0x1000A0U)

/* Data input message 9 */
#define CSL_SHA_P_DATA9_IN                                      (0x1000A4U)

/* Data input message 10 */
#define CSL_SHA_P_DATA10_IN                                     (0x1000A8U)

/* Data input message 11 */
#define CSL_SHA_P_DATA11_IN                                     (0x1000ACU)

/* Data input message 12 */
#define CSL_SHA_P_DATA12_IN                                     (0x1000B0U)

/* Data input message 13 */
#define CSL_SHA_P_DATA13_IN                                     (0x1000B4U)

/* Data input message 14 */
#define CSL_SHA_P_DATA14_IN                                     (0x1000B8U)

/* Data input message 15 */
#define CSL_SHA_P_DATA15_IN                                     (0x1000BCU)

/* Data input message 16 */
#define CSL_SHA_P_DATA16_IN                                     (0x1000C0U)

/* Data input message 17 */
#define CSL_SHA_P_DATA17_IN                                     (0x1000C4U)

/* Data input message 18 */
#define CSL_SHA_P_DATA18_IN                                     (0x1000C8U)

/* Data input message 19 */
#define CSL_SHA_P_DATA19_IN                                     (0x1000CCU)

/* Data input message 20 */
#define CSL_SHA_P_DATA20_IN                                     (0x1000D0U)

/* Data input message 21 */
#define CSL_SHA_P_DATA21_IN                                     (0x1000D4U)

/* Data input message 22 */
#define CSL_SHA_P_DATA22_IN                                     (0x1000D8U)

/* Data input message 23 */
#define CSL_SHA_P_DATA23_IN                                     (0x1000DCU)

/* Data input message 24 */
#define CSL_SHA_P_DATA24_IN                                     (0x1000E0U)

/* Data input message 25 */
#define CSL_SHA_P_DATA25_IN                                     (0x1000E4U)

/* Data input message 26 */
#define CSL_SHA_P_DATA26_IN                                     (0x1000E8U)

/* Data input message 27 */
#define CSL_SHA_P_DATA27_IN                                     (0x1000ECU)

/* Data input message 28 */
#define CSL_SHA_P_DATA28_IN                                     (0x1000F0U)

/* Data input message 29 */
#define CSL_SHA_P_DATA29_IN                                     (0x1000F4U)

/* Data input message 30 */
#define CSL_SHA_P_DATA30_IN                                     (0x1000F8U)

/* Data input message 31 */
#define CSL_SHA_P_DATA31_IN                                     (0x1000FCU)

/* Register SHA_REV */
#define CSL_SHA_P_REVISION                                      (0x100100U)

/* Register SHA_SYSCONFIG */
#define CSL_SHA_P_SYSCONFIG                                     (0x100110U)

/* Register SHA_SYSSTATUS */
#define CSL_SHA_P_SYSSTS                                        (0x100114U)

/* Register SHA_IRQSTATUS */
#define CSL_SHA_P_IRQSTS                                        (0x100118U)

/* Register SHA_P_IRQENABLE. The SHA_P_IRQENABLE register contains an enable
 * bit for each unique interrupt for the public side. An interrupt is enabled
 * when both the global enable in SHA_P_SYSCONFIG (PIT_en) and the bit in this
 * register are both set to 1. An interrupt that is enabled is propagated to
 * the SINTREQUEST_P output. Please note that the dedicated partial hash
 * output (SINTREQUEST_PART_P) is not affected by this register, it is only
 * affected by the global enable SHA_P_SYSCONFIG (PIT_en). */
#define CSL_SHA_P_IRQEN                                         (0x10011CU)

/* W: Outer Digest [511:480] for SHA-384 and SHA-512 / SHA512_HMAC Key [31:0]
 * for HMAC key proc R: Outer Digest [511:480] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_A                              (0x100200U)

/* W: Outer Digest [479:448] for SHA-384 and SHA-512 / SHA512_HMAC Key [63:32]
 * for HMAC key proc R: Outer Digest [479:448] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_B                              (0x100204U)

/* W: Outer Digest [447:416] for SHA-384 and SHA-512 / SHA512_HMAC Key [95:64]
 * for HMAC key proc R: Outer Digest [447:416] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_C                              (0x100208U)

/* W: Outer Digest [415:384] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [127:96] for HMAC key proc R: Outer Digest [415:384] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_D                              (0x10020CU)

/* W: Outer Digest [383:352] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [159:128] for HMAC key proc R: Outer Digest [383:352] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_E                              (0x100210U)

/* W: Outer Digest [351:320] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [191:160] for HMAC key proc R: Outer Digest [351:320] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_F                              (0x100214U)

/* W: Outer Digest [319:288] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [223:192] for HMAC key proc R: Outer Digest [319:288] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_G                              (0x100218U)

/* W: Outer Digest [287:256] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [255:244] for HMAC key proc R: Outer Digest [287:256] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_H                              (0x10021CU)

/* W: Outer Digest [255:224] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [287:256] for HMAC key proc R: Outer Digest [255:224] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_I                              (0x100220U)

/* W: Outer Digest [223:192] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [319:288] for HMAC key proc R: Outer Digest [223:129] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_J                              (0x100224U)

/* W: Outer Digest [191:160] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [351:320] for HMAC key proc R: Outer Digest [191:160] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_K                              (0x100228U)

/* W: Outer Digest [159:128] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [383:352] for HMAC key proc R: Outer Digest [159:128] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_L                              (0x10022CU)

/* W: Outer Digest [128:96] for SHA-384 and SHA-512 / SHA512_HMAC Key
 * [415:384] for HMAC key proc R: Outer Digest [128:96] for SHA-384 and
 * SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_M                              (0x100230U)

/* W: Outer Digest [95:64] for SHA-384 and SHA-512 / SHA512_HMAC Key [447:416]
 * for HMAC key proc R: Outer Digest [95:64] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_N                              (0x100234U)

/* W: Outer Digest [63:32] for SHA-384 and SHA-512 / SHA512_HMAC Key [479:448]
 * for HMAC key proc R: Outer Digest [63:32] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST_O                              (0x100238U)

/* W: Outer Digest [31:0] for SHA-384 and SHA-512 / SHA512_HMAC Key [511:480]
 * for HMAC key proc R: Outer Digest [31:0] for SHA-384 and SHA-512 */
#define CSL_SHA_SHA512_P_ODIGEST                                (0x10023CU)

/* W: Inner / Initial Digest [383:352] for SHA-384 and [511:480] for SHA-512 /
 * SHA512_HMAC Key [543:512] for HMAC key proc R: Intermediate / Inner Digest
 * [383:352] for SHA-384 and [511:480] for SHA-512 Result Digest/MAC Digest
 * [383:352] for SHA-384 and [511:480] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_A                              (0x100240U)

/* W: Inner / Initial Digest [351:320] for SHA-384 and [479:448] for SHA-512 /
 * SHA512_HMAC Key [575:544] for HMAC key proc R: Intermediate / Inner Digest
 * [351:320] for SHA-384 and [479:448] for SHA-512 Result Digest/MAC Digest
 * [351:320] for SHA-384 and [479:448] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_B                              (0x100244U)

/* W: Inner / Initial Digest [319:288] for SHA-384 and [447:416] for SHA-512 /
 * SHA512_HMAC Key [607:576] for HMAC key proc R: Intermediate / Inner Digest
 * [319:288] for SHA-384 and [447:416] for SHA-512 Result Digest/MAC Digest
 * [319:288] for SHA-384 and [447:416] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_C                              (0x100248U)

/* W: Inner / Initial Digest [287:256] for SHA-384 and [415:384] for SHA-512 /
 * SHA512_HMAC Key [639:608] for HMAC key proc R: Intermediate / Inner Digest
 * [287:256] for SHA-384 and [415:384] for SHA-512 Result Digest/MAC Digest
 * [287:256] for SHA-384 and [415:384] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_D                              (0x10024CU)

/* W: Inner / Initial Digest [255:224] for SHA-384 and [383:352] for SHA-512 /
 * SHA512_HMAC Key [671:640] for HMAC key proc R: Intermediate / Inner Digest
 * [255:224] for SHA-384 and [383:352] for SHA-512 Result Digest/MAC Digest
 * [255:224] for SHA-384 and [383:352] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_E                              (0x100250U)

/* W: Inner / Initial Digest [223:192] for SHA-384 and [351:320] for SHA-512 /
 * SHA512_HMAC Key [703:672] for HMAC key proc R: Intermediate / Inner Digest
 * [223:192] for SHA-384 and [351:320] for SHA-512 Result Digest/MAC Digest
 * [223:192] for SHA-384 and [351:320] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_F                              (0x100254U)

/* W: Inner / Initial Digest [191:160] for SHA-384 and [319:288] for SHA-512 /
 * SHA512_HMAC Key [735:704] for HMAC key proc R: Intermediate / Inner Digest
 * [191:160] for SHA-384 and [319:288] for SHA-512 Result Digest/MAC Digest
 * [191:160] for SHA-384 and [319:288] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_G                              (0x100258U)

/* W: Inner / Initial Digest [159:128] for SHA-384 and [287:256] for SHA-512 /
 * SHA512_HMAC Key [767:736] for HMAC key proc R: Intermediate / Inner Digest
 * [159:128] for SHA-384 and [287:256] for SHA-512 Result Digest/MAC Digest
 * [159:128] for SHA-384 and [287:256] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_H                              (0x10025CU)

/* W: Inner / Initial Digest [127:96] for SHA-384 and [255:224] for SHA-512 /
 * SHA512_HMAC Key [799:768] for HMAC key proc R: Intermediate / Inner Digest
 * [127:96] for SHA-384 and [255:224] for SHA-512 Result Digest/MAC Digest
 * [127:96] for SHA-384 and [255:224] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_I                              (0x100260U)

/* W: Inner / Initial Digest [95:64] for SHA-384 and [223:192] for SHA-512 /
 * SHA512_HMAC Key [831:800] for HMAC key proc R: Intermediate / Inner Digest
 * [95:64] for SHA-384 and [223:192] for SHA-512 Result Digest/MAC Digest
 * [95:64] for SHA-384 and [223:192] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_J                              (0x100264U)

/* W: Inner / Initial Digest [63:32] for SHA-384 and [191:160] for SHA-512 /
 * SHA512_HMAC Key [863:832] for HMAC key proc R: Intermediate / Inner Digest
 * [63:32] for SHA-384 and [191:160] for SHA-512 Result Digest/MAC Digest
 * [63:32] for SHA-384 and [191:160] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_K                              (0x100268U)

/* W: Inner / Initial Digest [31:0] for SHA-384 and [159:128] for SHA-512 /
 * SHA512_HMAC Key [895:864] for HMAC key proc R: Intermediate / Inner Digest
 * [31:0] for SHA-384 and [159:128] for SHA-512 Result Digest/MAC Digest
 * [31:0] for SHA-384 and [159:128] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_L                              (0x10026CU)

/* W: Inner / Initial Digest [127:96] for SHA-512 / SHA512_HMAC Key [927:896]
 * for HMAC key proc R: Intermediate / Inner Digest [127:96] for SHA-512
 * Result Digest/MAC Digest [127:96] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_M                              (0x100270U)

/* W: Inner / Initial Digest [95:64] for SHA-512 / SHA512_HMAC Key [959:928]
 * for HMAC key proc R: Intermediate / Inner Digest [95:64] for SHA-512 Result
 * Digest/MAC Digest [95:64] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_N                              (0x100274U)

/* W: Inner / Initial Digest [63:32] for SHA-512 / SHA512_HMAC Key [991:960]
 * for HMAC key proc R: Intermediate / Inner Digest [63:32] for SHA-512 Result
 * Digest/MAC Digest [63:32] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST_O                              (0x100278U)

/* W: Inner / Initial Digest [31:0] for SHA-512 / SHA512_HMAC Key [1023:992]
 * for HMAC key proc R: Intermediate / Inner Digest [31:0] for SHA-512 Result
 * Digest/MAC Digest [31:0] for SHA-512 */
#define CSL_SHA_SHA512_P_IDIGEST                                (0x10027CU)

/* W: Initial Digest Count ([31:7] only, [6:0] assumed 0) R: Result /
 * IntermediateDigest Count The initial digest byte count for hash/HMAC
 * continue operations (HMAC Key Processing = 0 and Use Algorithm Constants =
 * 0) on the Public World must be written to this register prior to starting
 * the operation by writing to SHA512_P_MODE. When either HMAC Key Processing
 * is '1' or Use Algorithm Constants is '1', this register does not need to be
 * written, it will be overwritten with 128 (1 hash block of key XOR ipad) or
 * 0 respectively, automatically. When starting a HMAC operation from
 * pre-computes (HMAC Key Processing is '0'), then the value 128 must be
 * written here to compensate for the appended key XOR ipad block. Note that
 * the value written should always be a 128 byte multiple, the lower 7 bits
 * written are ignored. The updated digest byte count (initial digest byte
 * count + bytes processed) can be read from this register when the status
 * register indicates that the operation is done or suspended due to a context
 * switch request, or when a Secure World context out DMA is requested. The
 * SHA512_P_DIGEST_COUNT is also forced to 128 if 'Reuse HMAC Key' in
 * SHA512_P_MODE is set to '1' (i.e. similar to HMAC Key Preprocessing). In
 * Advanced DMA mode, when not suspended with a partial result, reading the
 * SHA512_P_DIGEST_COUNT register triggers the Hash/HMAC Engine to start the
 * next context input DMA. Therefore, reading the SHA512_P_DIGEST_COUNT
 * register should always be the last context-read action if not suspended
 * with a partial result (i.e. PartHashReady interrupt not pending). */
#define CSL_SHA_SHA512_P_DIGEST_COUNT                           (0x100280U)

/* Register SHA_MODE */
#define CSL_SHA_SHA512_P_MODE                                   (0x100284U)

/* W: Block Length / Remaining Byte Count (bytes) R: Remaining Byte Count The
 * length of the block to be processed, in bytes, for hash/HMAC operations on
 * the HIB2 must be written to this register prior to starting the operation
 * by writing to SHA512_P_MODE. The value programmed MUST be a 128-byte
 * multiple if Close Hash is set to 0. This register is also the trigger to
 * start processing. Once this register is written, the core will commence
 * requesting input data via DMA or interrupt (if programmed length > 0) and
 * start processing. The assertion of the input data DMA and/or interrupt will
 * happen for both DMA modes (Advanced and 'Legacy'), if enabled. */
#define CSL_SHA_SHA512_P_LENGTH                                 (0x100288U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* S_ODIGEST_A */

#define CSL_SHA_S_ODIGEST_A_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_A_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_A_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_A_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_A_RESETVAL                            (0x00000000U)

/* S_ODIGEST_B */

#define CSL_SHA_S_ODIGEST_B_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_B_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_B_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_B_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_B_RESETVAL                            (0x00000000U)

/* S_ODIGEST_C */

#define CSL_SHA_S_ODIGEST_C_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_C_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_C_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_C_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_C_RESETVAL                            (0x00000000U)

/* S_ODIGEST_D */

#define CSL_SHA_S_ODIGEST_D_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_D_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_D_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_D_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_D_RESETVAL                            (0x00000000U)

/* S_ODIGEST_E */

#define CSL_SHA_S_ODIGEST_E_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_E_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_E_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_E_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_E_RESETVAL                            (0x00000000U)

/* S_ODIGEST_F */

#define CSL_SHA_S_ODIGEST_F_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_F_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_F_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_F_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_F_RESETVAL                            (0x00000000U)

/* S_ODIGEST_G */

#define CSL_SHA_S_ODIGEST_G_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_G_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_G_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_G_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_G_RESETVAL                            (0x00000000U)

/* S_ODIGEST_H */

#define CSL_SHA_S_ODIGEST_H_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_ODIGEST_H_DATA_SHIFT                          (0U)
#define CSL_SHA_S_ODIGEST_H_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_ODIGEST_H_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_ODIGEST_H_RESETVAL                            (0x00000000U)

/* S_IDIGEST_A */

#define CSL_SHA_S_IDIGEST_A_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_A_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_A_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_A_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_A_RESETVAL                            (0x00000000U)

/* S_IDIGEST_B */

#define CSL_SHA_S_IDIGEST_B_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_B_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_B_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_B_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_B_RESETVAL                            (0x00000000U)

/* S_IDIGEST_C */

#define CSL_SHA_S_IDIGEST_C_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_C_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_C_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_C_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_C_RESETVAL                            (0x00000000U)

/* S_IDIGEST_D */

#define CSL_SHA_S_IDIGEST_D_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_D_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_D_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_D_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_D_RESETVAL                            (0x00000000U)

/* S_IDIGEST_E */

#define CSL_SHA_S_IDIGEST_E_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_E_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_E_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_E_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_E_RESETVAL                            (0x00000000U)

/* S_IDIGEST_F */

#define CSL_SHA_S_IDIGEST_F_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_F_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_F_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_F_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_F_RESETVAL                            (0x00000000U)

/* S_IDIGEST_G */

#define CSL_SHA_S_IDIGEST_G_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_G_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_G_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_G_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_G_RESETVAL                            (0x00000000U)

/* S_IDIGEST_H */

#define CSL_SHA_S_IDIGEST_H_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_S_IDIGEST_H_DATA_SHIFT                          (0U)
#define CSL_SHA_S_IDIGEST_H_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_IDIGEST_H_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_S_IDIGEST_H_RESETVAL                            (0x00000000U)

/* S_DIGEST_COUNT */

#define CSL_SHA_S_DIGEST_COUNT_COUNT_MASK                       (0xFFFFFFFFU)
#define CSL_SHA_S_DIGEST_COUNT_COUNT_SHIFT                      (0U)
#define CSL_SHA_S_DIGEST_COUNT_COUNT_RESETVAL                   (0x00000000U)
#define CSL_SHA_S_DIGEST_COUNT_COUNT_MAX                        (0xffffffffU)

#define CSL_SHA_S_DIGEST_COUNT_RESETVAL                         (0x00000000U)

/* S_MODE */

#define CSL_SHA_S_MODE_ALGO_MASK                                (0x00000007U)
#define CSL_SHA_S_MODE_ALGO_SHIFT                               (0U)
#define CSL_SHA_S_MODE_ALGO_RESETVAL                            (0x00000000U)
#define CSL_SHA_S_MODE_ALGO_MD5_128                             (0x00000000U)
#define CSL_SHA_S_MODE_ALGO_SHA1_160                            (0x00000002U)
#define CSL_SHA_S_MODE_ALGO_SHA2_224                            (0x00000004U)
#define CSL_SHA_S_MODE_ALGO_SHA2_256                            (0x00000006U)
#define CSL_SHA_S_MODE_ALGO_SHA2_384                            (0x00000001U)
#define CSL_SHA_S_MODE_ALGO_SHA2_512                            (0x00000003U)

#define CSL_SHA_S_MODE_ALGO_CONSTANT_MASK                       (0x00000008U)
#define CSL_SHA_S_MODE_ALGO_CONSTANT_SHIFT                      (3U)
#define CSL_SHA_S_MODE_ALGO_CONSTANT_RESETVAL                   (0x00000000U)
#define CSL_SHA_S_MODE_ALGO_CONSTANT_CALC_DIGEST                (0x00000000U)
#define CSL_SHA_S_MODE_ALGO_CONSTANT_ALGO_DIGEST                (0x00000001U)

#define CSL_SHA_S_MODE_CLOSE_HASH_MASK                          (0x00000010U)
#define CSL_SHA_S_MODE_CLOSE_HASH_SHIFT                         (4U)
#define CSL_SHA_S_MODE_CLOSE_HASH_RESETVAL                      (0x00000000U)
#define CSL_SHA_S_MODE_CLOSE_HASH_NO_CLOSE                      (0x00000000U)
#define CSL_SHA_S_MODE_CLOSE_HASH_CLOSE                         (0x00000001U)

#define CSL_SHA_S_MODE_HMAC_KEY_PROC_MASK                       (0x00000020U)
#define CSL_SHA_S_MODE_HMAC_KEY_PROC_SHIFT                      (5U)
#define CSL_SHA_S_MODE_HMAC_KEY_PROC_RESETVAL                   (0x00000000U)
#define CSL_SHA_S_MODE_HMAC_KEY_PROC_NO_HMAC                    (0x00000000U)
#define CSL_SHA_S_MODE_HMAC_KEY_PROC_HMAC                       (0x00000001U)

#define CSL_SHA_S_MODE_HMAC_OUTER_HASH_MASK                     (0x00000080U)
#define CSL_SHA_S_MODE_HMAC_OUTER_HASH_SHIFT                    (7U)
#define CSL_SHA_S_MODE_HMAC_OUTER_HASH_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_MODE_HMAC_OUTER_HASH_NO_HMAC                  (0x00000000U)
#define CSL_SHA_S_MODE_HMAC_OUTER_HASH_HMAC                     (0x00000001U)

#define CSL_SHA_S_MODE_RESETVAL                                 (0x00000000U)

/* S_LENGTH */

#define CSL_SHA_S_LENGTH_LENGTH_MASK                            (0xFFFFFFFFU)
#define CSL_SHA_S_LENGTH_LENGTH_SHIFT                           (0U)
#define CSL_SHA_S_LENGTH_LENGTH_RESETVAL                        (0x00000000U)
#define CSL_SHA_S_LENGTH_LENGTH_MAX                             (0xffffffffU)

#define CSL_SHA_S_LENGTH_RESETVAL                               (0x00000000U)

/* S_DATA0_IN */

#define CSL_SHA_S_DATA0_IN_DATA0_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA0_IN_DATA0_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA0_IN_DATA0_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA0_IN_DATA0_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA0_IN_RESETVAL                             (0x00000000U)

/* S_DATA1_IN */

#define CSL_SHA_S_DATA1_IN_DATA1_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA1_IN_DATA1_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA1_IN_DATA1_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA1_IN_DATA1_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA1_IN_RESETVAL                             (0x00000000U)

/* S_DATA2_IN */

#define CSL_SHA_S_DATA2_IN_DATA2_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA2_IN_DATA2_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA2_IN_DATA2_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA2_IN_DATA2_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA2_IN_RESETVAL                             (0x00000000U)

/* S_DATA3_IN */

#define CSL_SHA_S_DATA3_IN_DATA3_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA3_IN_DATA3_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA3_IN_DATA3_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA3_IN_DATA3_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA3_IN_RESETVAL                             (0x00000000U)

/* S_DATA4_IN */

#define CSL_SHA_S_DATA4_IN_DATA4_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA4_IN_DATA4_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA4_IN_DATA4_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA4_IN_DATA4_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA4_IN_RESETVAL                             (0x00000000U)

/* S_DATA5_IN */

#define CSL_SHA_S_DATA5_IN_DATA5_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA5_IN_DATA5_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA5_IN_DATA5_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA5_IN_DATA5_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA5_IN_RESETVAL                             (0x00000000U)

/* S_DATA6_IN */

#define CSL_SHA_S_DATA6_IN_DATA6_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA6_IN_DATA6_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA6_IN_DATA6_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA6_IN_DATA6_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA6_IN_RESETVAL                             (0x00000000U)

/* S_DATA7_IN */

#define CSL_SHA_S_DATA7_IN_DATA7_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA7_IN_DATA7_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA7_IN_DATA7_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA7_IN_DATA7_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA7_IN_RESETVAL                             (0x00000000U)

/* S_DATA8_IN */

#define CSL_SHA_S_DATA8_IN_DATA8_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA8_IN_DATA8_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA8_IN_DATA8_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA8_IN_DATA8_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA8_IN_RESETVAL                             (0x00000000U)

/* S_DATA9_IN */

#define CSL_SHA_S_DATA9_IN_DATA9_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_S_DATA9_IN_DATA9_IN_SHIFT                       (0U)
#define CSL_SHA_S_DATA9_IN_DATA9_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_DATA9_IN_DATA9_IN_MAX                         (0xffffffffU)

#define CSL_SHA_S_DATA9_IN_RESETVAL                             (0x00000000U)

/* S_DATA10_IN */

#define CSL_SHA_S_DATA10_IN_DATA10_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA10_IN_DATA10_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA10_IN_DATA10_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA10_IN_DATA10_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA10_IN_RESETVAL                            (0x00000000U)

/* S_DATA11_IN */

#define CSL_SHA_S_DATA11_IN_DATA11_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA11_IN_DATA11_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA11_IN_DATA11_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA11_IN_DATA11_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA11_IN_RESETVAL                            (0x00000000U)

/* S_DATA12_IN */

#define CSL_SHA_S_DATA12_IN_DATA12_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA12_IN_DATA12_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA12_IN_DATA12_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA12_IN_DATA12_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA12_IN_RESETVAL                            (0x00000000U)

/* S_DATA13_IN */

#define CSL_SHA_S_DATA13_IN_DATA13_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA13_IN_DATA13_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA13_IN_DATA13_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA13_IN_DATA13_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA13_IN_RESETVAL                            (0x00000000U)

/* S_DATA14_IN */

#define CSL_SHA_S_DATA14_IN_DATA14_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA14_IN_DATA14_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA14_IN_DATA14_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA14_IN_DATA14_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA14_IN_RESETVAL                            (0x00000000U)

/* S_DATA15_IN */

#define CSL_SHA_S_DATA15_IN_DATA15_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA15_IN_DATA15_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA15_IN_DATA15_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA15_IN_DATA15_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA15_IN_RESETVAL                            (0x00000000U)

/* S_DATA16_IN */

#define CSL_SHA_S_DATA16_IN_DATA16_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA16_IN_DATA16_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA16_IN_DATA16_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA16_IN_DATA16_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA16_IN_RESETVAL                            (0x00000000U)

/* S_DATA17_IN */

#define CSL_SHA_S_DATA17_IN_DATA17_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA17_IN_DATA17_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA17_IN_DATA17_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA17_IN_DATA17_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA17_IN_RESETVAL                            (0x00000000U)

/* S_DATA18_IN */

#define CSL_SHA_S_DATA18_IN_DATA18_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA18_IN_DATA18_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA18_IN_DATA18_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA18_IN_DATA18_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA18_IN_RESETVAL                            (0x00000000U)

/* S_DATA19_IN */

#define CSL_SHA_S_DATA19_IN_DATA19_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA19_IN_DATA19_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA19_IN_DATA19_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA19_IN_DATA19_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA19_IN_RESETVAL                            (0x00000000U)

/* S_DATA20_IN */

#define CSL_SHA_S_DATA20_IN_DATA20_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA20_IN_DATA20_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA20_IN_DATA20_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA20_IN_DATA20_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA20_IN_RESETVAL                            (0x00000000U)

/* S_DATA21_IN */

#define CSL_SHA_S_DATA21_IN_DATA21_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA21_IN_DATA21_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA21_IN_DATA21_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA21_IN_DATA21_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA21_IN_RESETVAL                            (0x00000000U)

/* S_DATA22_IN */

#define CSL_SHA_S_DATA22_IN_DATA22_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA22_IN_DATA22_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA22_IN_DATA22_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA22_IN_DATA22_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA22_IN_RESETVAL                            (0x00000000U)

/* S_DATA23_IN */

#define CSL_SHA_S_DATA23_IN_DATA23_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA23_IN_DATA23_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA23_IN_DATA23_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA23_IN_DATA23_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA23_IN_RESETVAL                            (0x00000000U)

/* S_DATA24_IN */

#define CSL_SHA_S_DATA24_IN_DATA24_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA24_IN_DATA24_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA24_IN_DATA24_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA24_IN_DATA24_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA24_IN_RESETVAL                            (0x00000000U)

/* S_DATA25_IN */

#define CSL_SHA_S_DATA25_IN_DATA25_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA25_IN_DATA25_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA25_IN_DATA25_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA25_IN_DATA25_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA25_IN_RESETVAL                            (0x00000000U)

/* S_DATA26_IN */

#define CSL_SHA_S_DATA26_IN_DATA26_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA26_IN_DATA26_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA26_IN_DATA26_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA26_IN_DATA26_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA26_IN_RESETVAL                            (0x00000000U)

/* S_DATA27_IN */

#define CSL_SHA_S_DATA27_IN_DATA27_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA27_IN_DATA27_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA27_IN_DATA27_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA27_IN_DATA27_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA27_IN_RESETVAL                            (0x00000000U)

/* S_DATA28_IN */

#define CSL_SHA_S_DATA28_IN_DATA28_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA28_IN_DATA28_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA28_IN_DATA28_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA28_IN_DATA28_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA28_IN_RESETVAL                            (0x00000000U)

/* S_DATA29_IN */

#define CSL_SHA_S_DATA29_IN_DATA29_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA29_IN_DATA29_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA29_IN_DATA29_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA29_IN_DATA29_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA29_IN_RESETVAL                            (0x00000000U)

/* S_DATA30_IN */

#define CSL_SHA_S_DATA30_IN_DATA30_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA30_IN_DATA30_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA30_IN_DATA30_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA30_IN_DATA30_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA30_IN_RESETVAL                            (0x00000000U)

/* S_DATA31_IN */

#define CSL_SHA_S_DATA31_IN_DATA31_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_S_DATA31_IN_DATA31_IN_SHIFT                     (0U)
#define CSL_SHA_S_DATA31_IN_DATA31_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_DATA31_IN_DATA31_IN_MAX                       (0xffffffffU)

#define CSL_SHA_S_DATA31_IN_RESETVAL                            (0x00000000U)

/* S_REVISION */

#define CSL_SHA_S_REVISION_Y_MINOR_MASK                         (0x0000003FU)
#define CSL_SHA_S_REVISION_Y_MINOR_SHIFT                        (0U)
#define CSL_SHA_S_REVISION_Y_MINOR_RESETVAL                     (0x00000000U)
#define CSL_SHA_S_REVISION_Y_MINOR_MAX                          (0x0000003fU)

#define CSL_SHA_S_REVISION_CUSTOM_MASK                          (0x000000C0U)
#define CSL_SHA_S_REVISION_CUSTOM_SHIFT                         (6U)
#define CSL_SHA_S_REVISION_CUSTOM_RESETVAL                      (0x00000000U)
#define CSL_SHA_S_REVISION_CUSTOM_STANDARD                      (0x00000000U)

#define CSL_SHA_S_REVISION_X_MAJOR_MASK                         (0x00000700U)
#define CSL_SHA_S_REVISION_X_MAJOR_SHIFT                        (8U)
#define CSL_SHA_S_REVISION_X_MAJOR_RESETVAL                     (0x00000000U)
#define CSL_SHA_S_REVISION_X_MAJOR_MAX                          (0x00000007U)

#define CSL_SHA_S_REVISION_R_RTL_MASK                           (0x0000F800U)
#define CSL_SHA_S_REVISION_R_RTL_SHIFT                          (11U)
#define CSL_SHA_S_REVISION_R_RTL_RESETVAL                       (0x00000000U)
#define CSL_SHA_S_REVISION_R_RTL_MAX                            (0x0000001fU)

#define CSL_SHA_S_REVISION_FUNC_MASK                            (0x0FFF0000U)
#define CSL_SHA_S_REVISION_FUNC_SHIFT                           (16U)
#define CSL_SHA_S_REVISION_FUNC_RESETVAL                        (0x00000000U)
#define CSL_SHA_S_REVISION_FUNC_MAX                             (0x00000fffU)

#define CSL_SHA_S_REVISION_SCHEME_MASK                          (0xC0000000U)
#define CSL_SHA_S_REVISION_SCHEME_SHIFT                         (30U)
#define CSL_SHA_S_REVISION_SCHEME_RESETVAL                      (0x00000000U)
#define CSL_SHA_S_REVISION_SCHEME_H08                           (0x00000001U)
#define CSL_SHA_S_REVISION_SCHEME_LEGACY                        (0x00000000U)

#define CSL_SHA_S_REVISION_RESETVAL                             (0x00000000U)

/* S_SYSCONFIG */

#define CSL_SHA_S_SYSCONFIG_AUTOIDLE_MASK                       (0x00000001U)
#define CSL_SHA_S_SYSCONFIG_AUTOIDLE_SHIFT                      (0U)
#define CSL_SHA_S_SYSCONFIG_AUTOIDLE_RESETVAL                   (0x00000001U)
#define CSL_SHA_S_SYSCONFIG_AUTOIDLE_CLOCKS_ON                  (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_AUTOIDLE_CLOCKS_OFF                 (0x00000001U)

#define CSL_SHA_S_SYSCONFIG_SOFTRESET_MASK                      (0x00000002U)
#define CSL_SHA_S_SYSCONFIG_SOFTRESET_SHIFT                     (1U)
#define CSL_SHA_S_SYSCONFIG_SOFTRESET_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SOFTRESET_NOOP                      (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SOFTRESET_SOFRESET                  (0x00000001U)

#define CSL_SHA_S_SYSCONFIG_SIT_EN_MASK                         (0x00000004U)
#define CSL_SHA_S_SYSCONFIG_SIT_EN_SHIFT                        (2U)
#define CSL_SHA_S_SYSCONFIG_SIT_EN_RESETVAL                     (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SIT_EN_IT_EN                        (0x00000001U)
#define CSL_SHA_S_SYSCONFIG_SIT_EN_IT_DISEN                     (0x00000000U)

#define CSL_SHA_S_SYSCONFIG_SIDLE_MASK                          (0x00000030U)
#define CSL_SHA_S_SYSCONFIG_SIDLE_SHIFT                         (4U)
#define CSL_SHA_S_SYSCONFIG_SIDLE_RESETVAL                      (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SIDLE_FORCEIDLE                     (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SIDLE_NOIDLE                        (0x00000001U)
#define CSL_SHA_S_SYSCONFIG_SIDLE_SMARTIDLE                     (0x00000002U)
#define CSL_SHA_S_SYSCONFIG_SIDLE_RESERVED                      (0x00000003U)

#define CSL_SHA_S_SYSCONFIG_SCONT_SWT_MASK                      (0x00000040U)
#define CSL_SHA_S_SYSCONFIG_SCONT_SWT_SHIFT                     (6U)
#define CSL_SHA_S_SYSCONFIG_SCONT_SWT_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SCONT_SWT_MAX                       (0x00000001U)

#define CSL_SHA_S_SYSCONFIG_SDMA_EN_MASK                        (0x00000008U)
#define CSL_SHA_S_SYSCONFIG_SDMA_EN_SHIFT                       (3U)
#define CSL_SHA_S_SYSCONFIG_SDMA_EN_RESETVAL                    (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SDMA_EN_DMA_EN                      (0x00000001U)
#define CSL_SHA_S_SYSCONFIG_SDMA_EN_DMA_DISEN                   (0x00000000U)

#define CSL_SHA_S_SYSCONFIG_SADVANCED_MASK                      (0x00000080U)
#define CSL_SHA_S_SYSCONFIG_SADVANCED_SHIFT                     (7U)
#define CSL_SHA_S_SYSCONFIG_SADVANCED_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_SYSCONFIG_SADVANCED_MAX                       (0x00000001U)

#define CSL_SHA_S_SYSCONFIG_RESETVAL                            (0x00000001U)

/* S_SYSSTS */

#define CSL_SHA_S_SYSSTS_RESETDONE_MASK                         (0x00000001U)
#define CSL_SHA_S_SYSSTS_RESETDONE_SHIFT                        (0U)
#define CSL_SHA_S_SYSSTS_RESETDONE_RESETVAL                     (0x00000001U)
#define CSL_SHA_S_SYSSTS_RESETDONE_MAX                          (0x00000001U)

#define CSL_SHA_S_SYSSTS_RESETVAL                               (0x00000001U)

/* S_IRQSTS */

#define CSL_SHA_S_IRQSTS_OUTPUT_READY_MASK                      (0x00000001U)
#define CSL_SHA_S_IRQSTS_OUTPUT_READY_SHIFT                     (0U)
#define CSL_SHA_S_IRQSTS_OUTPUT_READY_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_IRQSTS_OUTPUT_READY_MAX                       (0x00000001U)

#define CSL_SHA_S_IRQSTS_INPUT_READY_MASK                       (0x00000002U)
#define CSL_SHA_S_IRQSTS_INPUT_READY_SHIFT                      (1U)
#define CSL_SHA_S_IRQSTS_INPUT_READY_RESETVAL                   (0x00000000U)
#define CSL_SHA_S_IRQSTS_INPUT_READY_MAX                        (0x00000001U)

#define CSL_SHA_S_IRQSTS_PARTHASH_READY_MASK                    (0x00000004U)
#define CSL_SHA_S_IRQSTS_PARTHASH_READY_SHIFT                   (2U)
#define CSL_SHA_S_IRQSTS_PARTHASH_READY_RESETVAL                (0x00000000U)
#define CSL_SHA_S_IRQSTS_PARTHASH_READY_MAX                     (0x00000001U)

#define CSL_SHA_S_IRQSTS_CONTEXT_READY_MASK                     (0x00000008U)
#define CSL_SHA_S_IRQSTS_CONTEXT_READY_SHIFT                    (3U)
#define CSL_SHA_S_IRQSTS_CONTEXT_READY_RESETVAL                 (0x00000001U)
#define CSL_SHA_S_IRQSTS_CONTEXT_READY_MAX                      (0x00000001U)

#define CSL_SHA_S_IRQSTS_RESETVAL                               (0x00000008U)

/* S_IRQEN */

#define CSL_SHA_S_IRQEN_M_OUTPUT_READY_MASK                     (0x00000001U)
#define CSL_SHA_S_IRQEN_M_OUTPUT_READY_SHIFT                    (0U)
#define CSL_SHA_S_IRQEN_M_OUTPUT_READY_RESETVAL                 (0x00000001U)
#define CSL_SHA_S_IRQEN_M_OUTPUT_READY_MAX                      (0x00000001U)

#define CSL_SHA_S_IRQEN_M_INPUT_READY_MASK                      (0x00000002U)
#define CSL_SHA_S_IRQEN_M_INPUT_READY_SHIFT                     (1U)
#define CSL_SHA_S_IRQEN_M_INPUT_READY_RESETVAL                  (0x00000001U)
#define CSL_SHA_S_IRQEN_M_INPUT_READY_MAX                       (0x00000001U)

#define CSL_SHA_S_IRQEN_M_PARTHASH_READY_MASK                   (0x00000004U)
#define CSL_SHA_S_IRQEN_M_PARTHASH_READY_SHIFT                  (2U)
#define CSL_SHA_S_IRQEN_M_PARTHASH_READY_RESETVAL               (0x00000001U)
#define CSL_SHA_S_IRQEN_M_PARTHASH_READY_MAX                    (0x00000001U)

#define CSL_SHA_S_IRQEN_M_CONTEXT_READY_MASK                    (0x00000008U)
#define CSL_SHA_S_IRQEN_M_CONTEXT_READY_SHIFT                   (3U)
#define CSL_SHA_S_IRQEN_M_CONTEXT_READY_RESETVAL                (0x00000000U)
#define CSL_SHA_S_IRQEN_M_CONTEXT_READY_MAX                     (0x00000001U)

#define CSL_SHA_S_IRQEN_RESETVAL                                (0x00000007U)

/* S_XSSTS */

#define CSL_SHA_S_XSSTS_SACCESSED_MASK                          (0x00000001U)
#define CSL_SHA_S_XSSTS_SACCESSED_SHIFT                         (0U)
#define CSL_SHA_S_XSSTS_SACCESSED_RESETVAL                      (0x00000000U)
#define CSL_SHA_S_XSSTS_SACCESSED_MAX                           (0x00000001U)

#define CSL_SHA_S_XSSTS_SDIRTY_MASK                             (0x00000002U)
#define CSL_SHA_S_XSSTS_SDIRTY_SHIFT                            (1U)
#define CSL_SHA_S_XSSTS_SDIRTY_RESETVAL                         (0x00000000U)
#define CSL_SHA_S_XSSTS_SDIRTY_MAX                              (0x00000001U)

#define CSL_SHA_S_XSSTS_PACCESSED_MASK                          (0x00000004U)
#define CSL_SHA_S_XSSTS_PACCESSED_SHIFT                         (2U)
#define CSL_SHA_S_XSSTS_PACCESSED_RESETVAL                      (0x00000000U)
#define CSL_SHA_S_XSSTS_PACCESSED_MAX                           (0x00000001U)

#define CSL_SHA_S_XSSTS_PDIRTY_MASK                             (0x00000008U)
#define CSL_SHA_S_XSSTS_PDIRTY_SHIFT                            (3U)
#define CSL_SHA_S_XSSTS_PDIRTY_RESETVAL                         (0x00000000U)
#define CSL_SHA_S_XSSTS_PDIRTY_MAX                              (0x00000001U)

#define CSL_SHA_S_XSSTS_RESETVAL                                (0x00000000U)

/* S_LOCKDOWN */

#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_MASK                       (0x00000007U)
#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_SHIFT                      (0U)
#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_RESETVAL                   (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_MAX                        (0x00000007U)

#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_CST_MASK                   (0x00000008U)
#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_CST_SHIFT                  (3U)
#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_CST_RESETVAL               (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_ALGO_CST_MAX                    (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE_MASK                      (0x00000010U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE_SHIFT                     (4U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE_RESETVAL                  (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE_MAX                       (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE1_MASK                     (0x00000020U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE1_SHIFT                    (5U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE1_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE1_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE2_MASK                     (0x00000040U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE2_SHIFT                    (6U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE2_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE2_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE3_MASK                     (0x00000080U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE3_SHIFT                    (7U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE3_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE3_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE4_MASK                     (0x01000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE4_SHIFT                    (24U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE4_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE4_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE5_MASK                     (0x02000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE5_SHIFT                    (25U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE5_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE5_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE6_MASK                     (0x04000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE6_SHIFT                    (26U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE6_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE6_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE7_MASK                     (0x08000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE7_SHIFT                    (27U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE7_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE7_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE8_MASK                     (0x10000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE8_SHIFT                    (28U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE8_RESETVAL                 (0x00000000U)
#define CSL_SHA_S_LOCKDOWN_LOCK_CLOSE8_MAX                      (0x00000001U)

#define CSL_SHA_S_LOCKDOWN_RESETVAL                             (0x00000000U)

/* SHA512_S_ODIGEST_A */

#define CSL_SHA_SHA512_S_ODIGEST_A_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_A_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_A_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_A_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_A_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_B */

#define CSL_SHA_SHA512_S_ODIGEST_B_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_B_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_B_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_B_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_B_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_C */

#define CSL_SHA_SHA512_S_ODIGEST_C_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_C_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_C_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_C_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_C_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_D */

#define CSL_SHA_SHA512_S_ODIGEST_D_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_D_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_D_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_D_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_D_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_E */

#define CSL_SHA_SHA512_S_ODIGEST_E_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_E_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_E_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_E_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_E_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_F */

#define CSL_SHA_SHA512_S_ODIGEST_F_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_F_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_F_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_F_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_F_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_G */

#define CSL_SHA_SHA512_S_ODIGEST_G_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_G_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_G_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_G_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_G_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_H */

#define CSL_SHA_SHA512_S_ODIGEST_H_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_H_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_H_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_H_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_H_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_I */

#define CSL_SHA_SHA512_S_ODIGEST_I_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_I_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_I_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_I_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_I_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_J */

#define CSL_SHA_SHA512_S_ODIGEST_J_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_J_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_J_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_J_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_J_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_K */

#define CSL_SHA_SHA512_S_ODIGEST_K_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_K_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_K_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_K_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_K_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_L */

#define CSL_SHA_SHA512_S_ODIGEST_L_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_L_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_L_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_L_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_L_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_M */

#define CSL_SHA_SHA512_S_ODIGEST_M_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_M_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_M_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_M_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_M_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_N */

#define CSL_SHA_SHA512_S_ODIGEST_N_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_N_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_N_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_N_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_N_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_O */

#define CSL_SHA_SHA512_S_ODIGEST_O_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_O_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_O_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_O_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_O_RESETVAL                     (0x00000000U)

/* SHA512_S_ODIGEST_P */

#define CSL_SHA_SHA512_S_ODIGEST_P_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_ODIGEST_P_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_ODIGEST_P_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_ODIGEST_P_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_ODIGEST_P_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_A */

#define CSL_SHA_SHA512_S_IDIGEST_A_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_A_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_A_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_A_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_A_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_B */

#define CSL_SHA_SHA512_S_IDIGEST_B_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_B_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_B_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_B_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_B_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_C */

#define CSL_SHA_SHA512_S_IDIGEST_C_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_C_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_C_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_C_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_C_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_D */

#define CSL_SHA_SHA512_S_IDIGEST_D_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_D_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_D_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_D_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_D_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_E */

#define CSL_SHA_SHA512_S_IDIGEST_E_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_E_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_E_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_E_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_E_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_F */

#define CSL_SHA_SHA512_S_IDIGEST_F_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_F_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_F_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_F_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_F_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_G */

#define CSL_SHA_SHA512_S_IDIGEST_G_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_G_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_G_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_G_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_G_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_H */

#define CSL_SHA_SHA512_S_IDIGEST_H_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_H_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_H_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_H_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_H_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_I */

#define CSL_SHA_SHA512_S_IDIGEST_I_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_I_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_I_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_I_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_I_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_J */

#define CSL_SHA_SHA512_S_IDIGEST_J_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_J_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_J_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_J_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_J_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_K */

#define CSL_SHA_SHA512_S_IDIGEST_K_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_K_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_K_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_K_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_K_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_L */

#define CSL_SHA_SHA512_S_IDIGEST_L_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_L_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_L_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_L_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_L_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_M */

#define CSL_SHA_SHA512_S_IDIGEST_M_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_M_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_M_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_M_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_M_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_N */

#define CSL_SHA_SHA512_S_IDIGEST_N_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_N_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_N_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_N_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_N_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_O */

#define CSL_SHA_SHA512_S_IDIGEST_O_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_O_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_O_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_O_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_O_RESETVAL                     (0x00000000U)

/* SHA512_S_IDIGEST_P */

#define CSL_SHA_SHA512_S_IDIGEST_P_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_IDIGEST_P_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_S_IDIGEST_P_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_S_IDIGEST_P_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_S_IDIGEST_P_RESETVAL                     (0x00000000U)

/* SHA512_S_DIGEST_COUNT */

#define CSL_SHA_SHA512_S_DIGEST_COUNT_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_DIGEST_COUNT_COUNT_SHIFT               (0U)
#define CSL_SHA_SHA512_S_DIGEST_COUNT_COUNT_RESETVAL            (0x00000000U)
#define CSL_SHA_SHA512_S_DIGEST_COUNT_COUNT_MAX                 (0xffffffffU)

#define CSL_SHA_SHA512_S_DIGEST_COUNT_RESETVAL                  (0x00000000U)

/* SHA512_S_MODE */

#define CSL_SHA_SHA512_S_MODE_ALGO_MASK                         (0x00000007U)
#define CSL_SHA_SHA512_S_MODE_ALGO_SHIFT                        (0U)
#define CSL_SHA_SHA512_S_MODE_ALGO_RESETVAL                     (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_ALGO_MD5_128                      (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_ALGO_SHA1_160                     (0x00000002U)
#define CSL_SHA_SHA512_S_MODE_ALGO_SHA2_224                     (0x00000004U)
#define CSL_SHA_SHA512_S_MODE_ALGO_SHA2_256                     (0x00000006U)
#define CSL_SHA_SHA512_S_MODE_ALGO_SHA2_384                     (0x00000001U)
#define CSL_SHA_SHA512_S_MODE_ALGO_SHA2_512                     (0x00000003U)

#define CSL_SHA_SHA512_S_MODE_ALGO_CONSTANT_MASK                (0x00000008U)
#define CSL_SHA_SHA512_S_MODE_ALGO_CONSTANT_SHIFT               (3U)
#define CSL_SHA_SHA512_S_MODE_ALGO_CONSTANT_RESETVAL            (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_ALGO_CONSTANT_CALC_DIGEST         (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_ALGO_CONSTANT_ALGO_DIGEST         (0x00000001U)

#define CSL_SHA_SHA512_S_MODE_CLOSE_HASH_MASK                   (0x00000010U)
#define CSL_SHA_SHA512_S_MODE_CLOSE_HASH_SHIFT                  (4U)
#define CSL_SHA_SHA512_S_MODE_CLOSE_HASH_RESETVAL               (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_CLOSE_HASH_NO_CLOSE               (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_CLOSE_HASH_CLOSE                  (0x00000001U)

#define CSL_SHA_SHA512_S_MODE_HMAC_KEY_PROC_MASK                (0x00000020U)
#define CSL_SHA_SHA512_S_MODE_HMAC_KEY_PROC_SHIFT               (5U)
#define CSL_SHA_SHA512_S_MODE_HMAC_KEY_PROC_RESETVAL            (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_HMAC_KEY_PROC_NO_HMAC             (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_HMAC_KEY_PROC_HMAC                (0x00000001U)

#define CSL_SHA_SHA512_S_MODE_HMAC_OUTER_HASH_MASK              (0x00000080U)
#define CSL_SHA_SHA512_S_MODE_HMAC_OUTER_HASH_SHIFT             (7U)
#define CSL_SHA_SHA512_S_MODE_HMAC_OUTER_HASH_RESETVAL          (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_HMAC_OUTER_HASH_NO_HMAC           (0x00000000U)
#define CSL_SHA_SHA512_S_MODE_HMAC_OUTER_HASH_HMAC              (0x00000001U)

#define CSL_SHA_SHA512_S_MODE_RESETVAL                          (0x00000000U)

/* SHA512_S_LENGTH */

#define CSL_SHA_SHA512_S_LENGTH_LENGTH_MASK                     (0xFFFFFFFFU)
#define CSL_SHA_SHA512_S_LENGTH_LENGTH_SHIFT                    (0U)
#define CSL_SHA_SHA512_S_LENGTH_LENGTH_RESETVAL                 (0x00000000U)
#define CSL_SHA_SHA512_S_LENGTH_LENGTH_MAX                      (0xffffffffU)

#define CSL_SHA_SHA512_S_LENGTH_RESETVAL                        (0x00000000U)

/* P_ODIGEST_A */

#define CSL_SHA_P_ODIGEST_A_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_A_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_A_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_A_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_A_RESETVAL                            (0x00000000U)

/* P_ODIGEST_B */

#define CSL_SHA_P_ODIGEST_B_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_B_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_B_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_B_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_B_RESETVAL                            (0x00000000U)

/* P_ODIGEST_C */

#define CSL_SHA_P_ODIGEST_C_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_C_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_C_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_C_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_C_RESETVAL                            (0x00000000U)

/* P_ODIGEST_D */

#define CSL_SHA_P_ODIGEST_D_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_D_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_D_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_D_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_D_RESETVAL                            (0x00000000U)

/* P_ODIGEST_E */

#define CSL_SHA_P_ODIGEST_E_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_E_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_E_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_E_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_E_RESETVAL                            (0x00000000U)

/* P_ODIGEST_F */

#define CSL_SHA_P_ODIGEST_F_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_F_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_F_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_F_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_F_RESETVAL                            (0x00000000U)

/* P_ODIGEST_G */

#define CSL_SHA_P_ODIGEST_G_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_G_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_G_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_G_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_G_RESETVAL                            (0x00000000U)

/* P_ODIGEST_H */

#define CSL_SHA_P_ODIGEST_H_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_ODIGEST_H_DATA_SHIFT                          (0U)
#define CSL_SHA_P_ODIGEST_H_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_ODIGEST_H_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_ODIGEST_H_RESETVAL                            (0x00000000U)

/* P_IDIGEST_A */

#define CSL_SHA_P_IDIGEST_A_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_A_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_A_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_A_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_A_RESETVAL                            (0x00000000U)

/* P_IDIGEST_B */

#define CSL_SHA_P_IDIGEST_B_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_B_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_B_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_B_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_B_RESETVAL                            (0x00000000U)

/* P_IDIGEST_C */

#define CSL_SHA_P_IDIGEST_C_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_C_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_C_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_C_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_C_RESETVAL                            (0x00000000U)

/* P_IDIGEST_D */

#define CSL_SHA_P_IDIGEST_D_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_D_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_D_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_D_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_D_RESETVAL                            (0x00000000U)

/* P_IDIGEST_E */

#define CSL_SHA_P_IDIGEST_E_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_E_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_E_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_E_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_E_RESETVAL                            (0x00000000U)

/* P_IDIGEST_F */

#define CSL_SHA_P_IDIGEST_F_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_F_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_F_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_F_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_F_RESETVAL                            (0x00000000U)

/* P_IDIGEST_G */

#define CSL_SHA_P_IDIGEST_G_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_G_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_G_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_G_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_G_RESETVAL                            (0x00000000U)

/* P_IDIGEST_H */

#define CSL_SHA_P_IDIGEST_H_DATA_MASK                           (0xFFFFFFFFU)
#define CSL_SHA_P_IDIGEST_H_DATA_SHIFT                          (0U)
#define CSL_SHA_P_IDIGEST_H_DATA_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_IDIGEST_H_DATA_MAX                            (0xffffffffU)

#define CSL_SHA_P_IDIGEST_H_RESETVAL                            (0x00000000U)

/* P_DIGEST_COUNT */

#define CSL_SHA_P_DIGEST_COUNT_DATA_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DIGEST_COUNT_DATA_SHIFT                       (0U)
#define CSL_SHA_P_DIGEST_COUNT_DATA_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DIGEST_COUNT_DATA_MAX                         (0xffffffffU)

#define CSL_SHA_P_DIGEST_COUNT_RESETVAL                         (0x00000000U)

/* P_MODE */

#define CSL_SHA_P_MODE_ALGO_MASK                                (0x00000007U)
#define CSL_SHA_P_MODE_ALGO_SHIFT                               (0U)
#define CSL_SHA_P_MODE_ALGO_RESETVAL                            (0x00000000U)
#define CSL_SHA_P_MODE_ALGO_MD5_128                             (0x00000000U)
#define CSL_SHA_P_MODE_ALGO_SHA1_160                            (0x00000002U)
#define CSL_SHA_P_MODE_ALGO_SHA2_224                            (0x00000004U)
#define CSL_SHA_P_MODE_ALGO_SHA2_256                            (0x00000006U)
#define CSL_SHA_P_MODE_ALGO_SHA2_384                            (0x00000001U)
#define CSL_SHA_P_MODE_ALGO_SHA2_512                            (0x00000003U)

#define CSL_SHA_P_MODE_ALGO_CONSTANT_MASK                       (0x00000008U)
#define CSL_SHA_P_MODE_ALGO_CONSTANT_SHIFT                      (3U)
#define CSL_SHA_P_MODE_ALGO_CONSTANT_RESETVAL                   (0x00000000U)
#define CSL_SHA_P_MODE_ALGO_CONSTANT_CALC_DIGEST                (0x00000000U)
#define CSL_SHA_P_MODE_ALGO_CONSTANT_ALGO_DIGEST                (0x00000001U)

#define CSL_SHA_P_MODE_CLOSE_HASH_MASK                          (0x00000010U)
#define CSL_SHA_P_MODE_CLOSE_HASH_SHIFT                         (4U)
#define CSL_SHA_P_MODE_CLOSE_HASH_RESETVAL                      (0x00000000U)
#define CSL_SHA_P_MODE_CLOSE_HASH_NO_CLOSE                      (0x00000000U)
#define CSL_SHA_P_MODE_CLOSE_HASH_CLOSE                         (0x00000001U)

#define CSL_SHA_P_MODE_HMAC_KEY_PROC_MASK                       (0x00000020U)
#define CSL_SHA_P_MODE_HMAC_KEY_PROC_SHIFT                      (5U)
#define CSL_SHA_P_MODE_HMAC_KEY_PROC_RESETVAL                   (0x00000000U)
#define CSL_SHA_P_MODE_HMAC_KEY_PROC_NO_HMAC                    (0x00000000U)
#define CSL_SHA_P_MODE_HMAC_KEY_PROC_HMAC                       (0x00000001U)

#define CSL_SHA_P_MODE_HMAC_OUTER_HASH_MASK                     (0x00000080U)
#define CSL_SHA_P_MODE_HMAC_OUTER_HASH_SHIFT                    (7U)
#define CSL_SHA_P_MODE_HMAC_OUTER_HASH_RESETVAL                 (0x00000000U)
#define CSL_SHA_P_MODE_HMAC_OUTER_HASH_NO_HMAC                  (0x00000000U)
#define CSL_SHA_P_MODE_HMAC_OUTER_HASH_HMAC                     (0x00000001U)

#define CSL_SHA_P_MODE_REUSE_HMAC_KEY_MASK                      (0x00000040U)
#define CSL_SHA_P_MODE_REUSE_HMAC_KEY_SHIFT                     (6U)
#define CSL_SHA_P_MODE_REUSE_HMAC_KEY_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_MODE_REUSE_HMAC_KEY_MAX                       (0x00000001U)

#define CSL_SHA_P_MODE_RESETVAL                                 (0x00000000U)

/* P_LENGTH */

#define CSL_SHA_P_LENGTH_DATA_MASK                              (0xFFFFFFFFU)
#define CSL_SHA_P_LENGTH_DATA_SHIFT                             (0U)
#define CSL_SHA_P_LENGTH_DATA_RESETVAL                          (0x00000000U)
#define CSL_SHA_P_LENGTH_DATA_MAX                               (0xffffffffU)

#define CSL_SHA_P_LENGTH_RESETVAL                               (0x00000000U)

/* P_DATA0_IN */

#define CSL_SHA_P_DATA0_IN_DATA0_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA0_IN_DATA0_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA0_IN_DATA0_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA0_IN_DATA0_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA0_IN_RESETVAL                             (0x00000000U)

/* P_DATA1_IN */

#define CSL_SHA_P_DATA1_IN_DATA1_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA1_IN_DATA1_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA1_IN_DATA1_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA1_IN_DATA1_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA1_IN_RESETVAL                             (0x00000000U)

/* P_DATA2_IN */

#define CSL_SHA_P_DATA2_IN_DATA2_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA2_IN_DATA2_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA2_IN_DATA2_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA2_IN_DATA2_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA2_IN_RESETVAL                             (0x00000000U)

/* P_DATA3_IN */

#define CSL_SHA_P_DATA3_IN_DATA3_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA3_IN_DATA3_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA3_IN_DATA3_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA3_IN_DATA3_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA3_IN_RESETVAL                             (0x00000000U)

/* P_DATA4_IN */

#define CSL_SHA_P_DATA4_IN_DATA4_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA4_IN_DATA4_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA4_IN_DATA4_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA4_IN_DATA4_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA4_IN_RESETVAL                             (0x00000000U)

/* P_DATA5_IN */

#define CSL_SHA_P_DATA5_IN_DATA5_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA5_IN_DATA5_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA5_IN_DATA5_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA5_IN_DATA5_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA5_IN_RESETVAL                             (0x00000000U)

/* P_DATA6_IN */

#define CSL_SHA_P_DATA6_IN_DATA6_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA6_IN_DATA6_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA6_IN_DATA6_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA6_IN_DATA6_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA6_IN_RESETVAL                             (0x00000000U)

/* P_DATA7_IN */

#define CSL_SHA_P_DATA7_IN_DATA7_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA7_IN_DATA7_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA7_IN_DATA7_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA7_IN_DATA7_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA7_IN_RESETVAL                             (0x00000000U)

/* P_DATA8_IN */

#define CSL_SHA_P_DATA8_IN_DATA8_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA8_IN_DATA8_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA8_IN_DATA8_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA8_IN_DATA8_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA8_IN_RESETVAL                             (0x00000000U)

/* P_DATA9_IN */

#define CSL_SHA_P_DATA9_IN_DATA9_IN_MASK                        (0xFFFFFFFFU)
#define CSL_SHA_P_DATA9_IN_DATA9_IN_SHIFT                       (0U)
#define CSL_SHA_P_DATA9_IN_DATA9_IN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_DATA9_IN_DATA9_IN_MAX                         (0xffffffffU)

#define CSL_SHA_P_DATA9_IN_RESETVAL                             (0x00000000U)

/* P_DATA10_IN */

#define CSL_SHA_P_DATA10_IN_DATA10_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA10_IN_DATA10_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA10_IN_DATA10_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA10_IN_DATA10_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA10_IN_RESETVAL                            (0x00000000U)

/* P_DATA11_IN */

#define CSL_SHA_P_DATA11_IN_DATA11_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA11_IN_DATA11_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA11_IN_DATA11_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA11_IN_DATA11_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA11_IN_RESETVAL                            (0x00000000U)

/* P_DATA12_IN */

#define CSL_SHA_P_DATA12_IN_DATA12_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA12_IN_DATA12_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA12_IN_DATA12_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA12_IN_DATA12_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA12_IN_RESETVAL                            (0x00000000U)

/* P_DATA13_IN */

#define CSL_SHA_P_DATA13_IN_DATA13_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA13_IN_DATA13_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA13_IN_DATA13_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA13_IN_DATA13_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA13_IN_RESETVAL                            (0x00000000U)

/* P_DATA14_IN */

#define CSL_SHA_P_DATA14_IN_DATA14_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA14_IN_DATA14_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA14_IN_DATA14_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA14_IN_DATA14_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA14_IN_RESETVAL                            (0x00000000U)

/* P_DATA15_IN */

#define CSL_SHA_P_DATA15_IN_DATA15_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA15_IN_DATA15_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA15_IN_DATA15_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA15_IN_DATA15_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA15_IN_RESETVAL                            (0x00000000U)

/* P_DATA16_IN */

#define CSL_SHA_P_DATA16_IN_DATA16_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA16_IN_DATA16_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA16_IN_DATA16_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA16_IN_DATA16_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA16_IN_RESETVAL                            (0x00000000U)

/* P_DATA17_IN */

#define CSL_SHA_P_DATA17_IN_DATA17_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA17_IN_DATA17_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA17_IN_DATA17_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA17_IN_DATA17_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA17_IN_RESETVAL                            (0x00000000U)

/* P_DATA18_IN */

#define CSL_SHA_P_DATA18_IN_DATA18_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA18_IN_DATA18_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA18_IN_DATA18_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA18_IN_DATA18_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA18_IN_RESETVAL                            (0x00000000U)

/* P_DATA19_IN */

#define CSL_SHA_P_DATA19_IN_DATA19_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA19_IN_DATA19_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA19_IN_DATA19_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA19_IN_DATA19_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA19_IN_RESETVAL                            (0x00000000U)

/* P_DATA20_IN */

#define CSL_SHA_P_DATA20_IN_DATA20_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA20_IN_DATA20_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA20_IN_DATA20_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA20_IN_DATA20_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA20_IN_RESETVAL                            (0x00000000U)

/* P_DATA21_IN */

#define CSL_SHA_P_DATA21_IN_DATA21_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA21_IN_DATA21_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA21_IN_DATA21_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA21_IN_DATA21_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA21_IN_RESETVAL                            (0x00000000U)

/* P_DATA22_IN */

#define CSL_SHA_P_DATA22_IN_DATA22_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA22_IN_DATA22_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA22_IN_DATA22_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA22_IN_DATA22_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA22_IN_RESETVAL                            (0x00000000U)

/* P_DATA23_IN */

#define CSL_SHA_P_DATA23_IN_DATA23_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA23_IN_DATA23_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA23_IN_DATA23_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA23_IN_DATA23_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA23_IN_RESETVAL                            (0x00000000U)

/* P_DATA24_IN */

#define CSL_SHA_P_DATA24_IN_DATA24_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA24_IN_DATA24_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA24_IN_DATA24_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA24_IN_DATA24_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA24_IN_RESETVAL                            (0x00000000U)

/* P_DATA25_IN */

#define CSL_SHA_P_DATA25_IN_DATA25_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA25_IN_DATA25_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA25_IN_DATA25_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA25_IN_DATA25_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA25_IN_RESETVAL                            (0x00000000U)

/* P_DATA26_IN */

#define CSL_SHA_P_DATA26_IN_DATA26_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA26_IN_DATA26_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA26_IN_DATA26_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA26_IN_DATA26_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA26_IN_RESETVAL                            (0x00000000U)

/* P_DATA27_IN */

#define CSL_SHA_P_DATA27_IN_DATA27_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA27_IN_DATA27_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA27_IN_DATA27_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA27_IN_DATA27_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA27_IN_RESETVAL                            (0x00000000U)

/* P_DATA28_IN */

#define CSL_SHA_P_DATA28_IN_DATA28_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA28_IN_DATA28_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA28_IN_DATA28_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA28_IN_DATA28_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA28_IN_RESETVAL                            (0x00000000U)

/* P_DATA29_IN */

#define CSL_SHA_P_DATA29_IN_DATA29_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA29_IN_DATA29_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA29_IN_DATA29_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA29_IN_DATA29_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA29_IN_RESETVAL                            (0x00000000U)

/* P_DATA30_IN */

#define CSL_SHA_P_DATA30_IN_DATA30_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA30_IN_DATA30_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA30_IN_DATA30_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA30_IN_DATA30_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA30_IN_RESETVAL                            (0x00000000U)

/* P_DATA31_IN */

#define CSL_SHA_P_DATA31_IN_DATA31_IN_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_P_DATA31_IN_DATA31_IN_SHIFT                     (0U)
#define CSL_SHA_P_DATA31_IN_DATA31_IN_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_DATA31_IN_DATA31_IN_MAX                       (0xffffffffU)

#define CSL_SHA_P_DATA31_IN_RESETVAL                            (0x00000000U)

/* P_REVISION */

#define CSL_SHA_P_REVISION_Y_MINOR_MASK                         (0x0000003FU)
#define CSL_SHA_P_REVISION_Y_MINOR_SHIFT                        (0U)
#define CSL_SHA_P_REVISION_Y_MINOR_RESETVAL                     (0x00000000U)
#define CSL_SHA_P_REVISION_Y_MINOR_MAX                          (0x0000003fU)

#define CSL_SHA_P_REVISION_CUSTOM_MASK                          (0x000000C0U)
#define CSL_SHA_P_REVISION_CUSTOM_SHIFT                         (6U)
#define CSL_SHA_P_REVISION_CUSTOM_RESETVAL                      (0x00000000U)
#define CSL_SHA_P_REVISION_CUSTOM_STANDARD                      (0x00000000U)

#define CSL_SHA_P_REVISION_X_MAJOR_MASK                         (0x00000700U)
#define CSL_SHA_P_REVISION_X_MAJOR_SHIFT                        (8U)
#define CSL_SHA_P_REVISION_X_MAJOR_RESETVAL                     (0x00000000U)
#define CSL_SHA_P_REVISION_X_MAJOR_MAX                          (0x00000007U)

#define CSL_SHA_P_REVISION_R_RTL_MASK                           (0x0000F800U)
#define CSL_SHA_P_REVISION_R_RTL_SHIFT                          (11U)
#define CSL_SHA_P_REVISION_R_RTL_RESETVAL                       (0x00000000U)
#define CSL_SHA_P_REVISION_R_RTL_MAX                            (0x0000001fU)

#define CSL_SHA_P_REVISION_FUNC_MASK                            (0x0FFF0000U)
#define CSL_SHA_P_REVISION_FUNC_SHIFT                           (16U)
#define CSL_SHA_P_REVISION_FUNC_RESETVAL                        (0x00000000U)
#define CSL_SHA_P_REVISION_FUNC_MAX                             (0x00000fffU)

#define CSL_SHA_P_REVISION_SCHEME_MASK                          (0xC0000000U)
#define CSL_SHA_P_REVISION_SCHEME_SHIFT                         (30U)
#define CSL_SHA_P_REVISION_SCHEME_RESETVAL                      (0x00000000U)
#define CSL_SHA_P_REVISION_SCHEME_H08                           (0x00000001U)
#define CSL_SHA_P_REVISION_SCHEME_LEGACY                        (0x00000000U)

#define CSL_SHA_P_REVISION_RESETVAL                             (0x00000000U)

/* P_SYSCONFIG */

#define CSL_SHA_P_SYSCONFIG_PIT_EN_MASK                         (0x00000004U)
#define CSL_SHA_P_SYSCONFIG_PIT_EN_SHIFT                        (2U)
#define CSL_SHA_P_SYSCONFIG_PIT_EN_RESETVAL                     (0x00000000U)
#define CSL_SHA_P_SYSCONFIG_PIT_EN_IT_EN                        (0x00000001U)
#define CSL_SHA_P_SYSCONFIG_PIT_EN_IT_DISEN                     (0x00000000U)

#define CSL_SHA_P_SYSCONFIG_PCONT_SWT_MASK                      (0x00000040U)
#define CSL_SHA_P_SYSCONFIG_PCONT_SWT_SHIFT                     (6U)
#define CSL_SHA_P_SYSCONFIG_PCONT_SWT_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_SYSCONFIG_PCONT_SWT_MAX                       (0x00000001U)

#define CSL_SHA_P_SYSCONFIG_PDMA_EN_MASK                        (0x00000008U)
#define CSL_SHA_P_SYSCONFIG_PDMA_EN_SHIFT                       (3U)
#define CSL_SHA_P_SYSCONFIG_PDMA_EN_RESETVAL                    (0x00000000U)
#define CSL_SHA_P_SYSCONFIG_PDMA_EN_DMA_EN                      (0x00000001U)
#define CSL_SHA_P_SYSCONFIG_PDMA_EN_DMA_DISEN                   (0x00000000U)

#define CSL_SHA_P_SYSCONFIG_PADVANCED_MASK                      (0x00000080U)
#define CSL_SHA_P_SYSCONFIG_PADVANCED_SHIFT                     (7U)
#define CSL_SHA_P_SYSCONFIG_PADVANCED_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_SYSCONFIG_PADVANCED_MAX                       (0x00000001U)

#define CSL_SHA_P_SYSCONFIG_RESETVAL                            (0x00000000U)

/* P_SYSSTS */

#define CSL_SHA_P_SYSSTS_RESETDONE_MASK                         (0x00000001U)
#define CSL_SHA_P_SYSSTS_RESETDONE_SHIFT                        (0U)
#define CSL_SHA_P_SYSSTS_RESETDONE_RESETVAL                     (0x00000001U)
#define CSL_SHA_P_SYSSTS_RESETDONE_MAX                          (0x00000001U)

#define CSL_SHA_P_SYSSTS_RESETVAL                               (0x00000001U)

/* P_IRQSTS */

#define CSL_SHA_P_IRQSTS_OUTPUT_READY_MASK                      (0x00000001U)
#define CSL_SHA_P_IRQSTS_OUTPUT_READY_SHIFT                     (0U)
#define CSL_SHA_P_IRQSTS_OUTPUT_READY_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_IRQSTS_OUTPUT_READY_MAX                       (0x00000001U)

#define CSL_SHA_P_IRQSTS_INPUT_READY_MASK                       (0x00000002U)
#define CSL_SHA_P_IRQSTS_INPUT_READY_SHIFT                      (1U)
#define CSL_SHA_P_IRQSTS_INPUT_READY_RESETVAL                   (0x00000000U)
#define CSL_SHA_P_IRQSTS_INPUT_READY_MAX                        (0x00000001U)

#define CSL_SHA_P_IRQSTS_PARTHASH_READY_MASK                    (0x00000004U)
#define CSL_SHA_P_IRQSTS_PARTHASH_READY_SHIFT                   (2U)
#define CSL_SHA_P_IRQSTS_PARTHASH_READY_RESETVAL                (0x00000000U)
#define CSL_SHA_P_IRQSTS_PARTHASH_READY_MAX                     (0x00000001U)

#define CSL_SHA_P_IRQSTS_CONTEXT_READY_MASK                     (0x00000008U)
#define CSL_SHA_P_IRQSTS_CONTEXT_READY_SHIFT                    (3U)
#define CSL_SHA_P_IRQSTS_CONTEXT_READY_RESETVAL                 (0x00000001U)
#define CSL_SHA_P_IRQSTS_CONTEXT_READY_MAX                      (0x00000001U)

#define CSL_SHA_P_IRQSTS_RESETVAL                               (0x00000008U)

/* P_IRQEN */

#define CSL_SHA_P_IRQEN_M_OUTPUT_READY_MASK                     (0x00000001U)
#define CSL_SHA_P_IRQEN_M_OUTPUT_READY_SHIFT                    (0U)
#define CSL_SHA_P_IRQEN_M_OUTPUT_READY_RESETVAL                 (0x00000000U)
#define CSL_SHA_P_IRQEN_M_OUTPUT_READY_MAX                      (0x00000001U)

#define CSL_SHA_P_IRQEN_M_INPUT_READY_MASK                      (0x00000002U)
#define CSL_SHA_P_IRQEN_M_INPUT_READY_SHIFT                     (1U)
#define CSL_SHA_P_IRQEN_M_INPUT_READY_RESETVAL                  (0x00000000U)
#define CSL_SHA_P_IRQEN_M_INPUT_READY_MAX                       (0x00000001U)

#define CSL_SHA_P_IRQEN_M_PARTHASH_READY_MASK                   (0x00000004U)
#define CSL_SHA_P_IRQEN_M_PARTHASH_READY_SHIFT                  (2U)
#define CSL_SHA_P_IRQEN_M_PARTHASH_READY_RESETVAL               (0x00000000U)
#define CSL_SHA_P_IRQEN_M_PARTHASH_READY_MAX                    (0x00000001U)

#define CSL_SHA_P_IRQEN_M_CONTEXT_READY_MASK                    (0x00000008U)
#define CSL_SHA_P_IRQEN_M_CONTEXT_READY_SHIFT                   (3U)
#define CSL_SHA_P_IRQEN_M_CONTEXT_READY_RESETVAL                (0x00000000U)
#define CSL_SHA_P_IRQEN_M_CONTEXT_READY_MAX                     (0x00000001U)

#define CSL_SHA_P_IRQEN_RESETVAL                                (0x00000000U)

/* SHA512_P_ODIGEST_A */

#define CSL_SHA_SHA512_P_ODIGEST_A_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_A_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_A_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_A_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_A_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_B */

#define CSL_SHA_SHA512_P_ODIGEST_B_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_B_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_B_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_B_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_B_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_C */

#define CSL_SHA_SHA512_P_ODIGEST_C_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_C_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_C_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_C_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_C_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_D */

#define CSL_SHA_SHA512_P_ODIGEST_D_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_D_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_D_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_D_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_D_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_E */

#define CSL_SHA_SHA512_P_ODIGEST_E_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_E_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_E_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_E_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_E_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_F */

#define CSL_SHA_SHA512_P_ODIGEST_F_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_F_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_F_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_F_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_F_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_G */

#define CSL_SHA_SHA512_P_ODIGEST_G_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_G_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_G_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_G_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_G_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_H */

#define CSL_SHA_SHA512_P_ODIGEST_H_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_H_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_H_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_H_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_H_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_I */

#define CSL_SHA_SHA512_P_ODIGEST_I_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_I_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_I_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_I_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_I_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_J */

#define CSL_SHA_SHA512_P_ODIGEST_J_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_J_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_J_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_J_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_J_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_K */

#define CSL_SHA_SHA512_P_ODIGEST_K_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_K_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_K_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_K_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_K_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_L */

#define CSL_SHA_SHA512_P_ODIGEST_L_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_L_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_L_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_L_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_L_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_M */

#define CSL_SHA_SHA512_P_ODIGEST_M_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_M_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_M_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_M_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_M_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_N */

#define CSL_SHA_SHA512_P_ODIGEST_N_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_N_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_N_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_N_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_N_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST_O */

#define CSL_SHA_SHA512_P_ODIGEST_O_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_O_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_ODIGEST_O_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_O_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_O_RESETVAL                     (0x00000000U)

/* SHA512_P_ODIGEST */

#define CSL_SHA_SHA512_P_ODIGEST_DATA_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_ODIGEST_DATA_SHIFT                     (0U)
#define CSL_SHA_SHA512_P_ODIGEST_DATA_RESETVAL                  (0x00000000U)
#define CSL_SHA_SHA512_P_ODIGEST_DATA_MAX                       (0xffffffffU)

#define CSL_SHA_SHA512_P_ODIGEST_RESETVAL                       (0x00000000U)

/* SHA512_P_IDIGEST_A */

#define CSL_SHA_SHA512_P_IDIGEST_A_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_A_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_A_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_A_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_A_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_B */

#define CSL_SHA_SHA512_P_IDIGEST_B_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_B_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_B_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_B_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_B_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_C */

#define CSL_SHA_SHA512_P_IDIGEST_C_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_C_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_C_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_C_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_C_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_D */

#define CSL_SHA_SHA512_P_IDIGEST_D_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_D_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_D_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_D_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_D_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_E */

#define CSL_SHA_SHA512_P_IDIGEST_E_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_E_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_E_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_E_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_E_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_F */

#define CSL_SHA_SHA512_P_IDIGEST_F_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_F_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_F_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_F_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_F_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_G */

#define CSL_SHA_SHA512_P_IDIGEST_G_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_G_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_G_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_G_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_G_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_H */

#define CSL_SHA_SHA512_P_IDIGEST_H_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_H_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_H_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_H_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_H_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_I */

#define CSL_SHA_SHA512_P_IDIGEST_I_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_I_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_I_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_I_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_I_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_J */

#define CSL_SHA_SHA512_P_IDIGEST_J_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_J_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_J_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_J_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_J_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_K */

#define CSL_SHA_SHA512_P_IDIGEST_K_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_K_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_K_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_K_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_K_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_L */

#define CSL_SHA_SHA512_P_IDIGEST_L_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_L_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_L_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_L_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_L_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_M */

#define CSL_SHA_SHA512_P_IDIGEST_M_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_M_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_M_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_M_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_M_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_N */

#define CSL_SHA_SHA512_P_IDIGEST_N_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_N_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_N_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_N_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_N_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST_O */

#define CSL_SHA_SHA512_P_IDIGEST_O_DATA_MASK                    (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_O_DATA_SHIFT                   (0U)
#define CSL_SHA_SHA512_P_IDIGEST_O_DATA_RESETVAL                (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_O_DATA_MAX                     (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_O_RESETVAL                     (0x00000000U)

/* SHA512_P_IDIGEST */

#define CSL_SHA_SHA512_P_IDIGEST_DATA_MASK                      (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_IDIGEST_DATA_SHIFT                     (0U)
#define CSL_SHA_SHA512_P_IDIGEST_DATA_RESETVAL                  (0x00000000U)
#define CSL_SHA_SHA512_P_IDIGEST_DATA_MAX                       (0xffffffffU)

#define CSL_SHA_SHA512_P_IDIGEST_RESETVAL                       (0x00000000U)

/* SHA512_P_DIGEST_COUNT */

#define CSL_SHA_SHA512_P_DIGEST_COUNT_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_DIGEST_COUNT_COUNT_SHIFT               (0U)
#define CSL_SHA_SHA512_P_DIGEST_COUNT_COUNT_RESETVAL            (0x00000000U)
#define CSL_SHA_SHA512_P_DIGEST_COUNT_COUNT_MAX                 (0xffffffffU)

#define CSL_SHA_SHA512_P_DIGEST_COUNT_RESETVAL                  (0x00000000U)

/* SHA512_P_MODE */

#define CSL_SHA_SHA512_P_MODE_ALGO_MASK                         (0x00000007U)
#define CSL_SHA_SHA512_P_MODE_ALGO_SHIFT                        (0U)
#define CSL_SHA_SHA512_P_MODE_ALGO_RESETVAL                     (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_ALGO_MD5_128                      (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_ALGO_SHA1_160                     (0x00000002U)
#define CSL_SHA_SHA512_P_MODE_ALGO_SHA2_224                     (0x00000004U)
#define CSL_SHA_SHA512_P_MODE_ALGO_SHA2_256                     (0x00000006U)
#define CSL_SHA_SHA512_P_MODE_ALGO_SHA2_384                     (0x00000001U)
#define CSL_SHA_SHA512_P_MODE_ALGO_SHA2_512                     (0x00000003U)

#define CSL_SHA_SHA512_P_MODE_ALGO_CONSTANT_MASK                (0x00000008U)
#define CSL_SHA_SHA512_P_MODE_ALGO_CONSTANT_SHIFT               (3U)
#define CSL_SHA_SHA512_P_MODE_ALGO_CONSTANT_RESETVAL            (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_ALGO_CONSTANT_CALC_DIGEST         (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_ALGO_CONSTANT_ALGO_DIGEST         (0x00000001U)

#define CSL_SHA_SHA512_P_MODE_CLOSE_HASH_MASK                   (0x00000010U)
#define CSL_SHA_SHA512_P_MODE_CLOSE_HASH_SHIFT                  (4U)
#define CSL_SHA_SHA512_P_MODE_CLOSE_HASH_RESETVAL               (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_CLOSE_HASH_NO_CLOSE               (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_CLOSE_HASH_CLOSE                  (0x00000001U)

#define CSL_SHA_SHA512_P_MODE_HMAC_KEY_PROC_MASK                (0x00000020U)
#define CSL_SHA_SHA512_P_MODE_HMAC_KEY_PROC_SHIFT               (5U)
#define CSL_SHA_SHA512_P_MODE_HMAC_KEY_PROC_RESETVAL            (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_HMAC_KEY_PROC_NO_HMAC             (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_HMAC_KEY_PROC_HMAC                (0x00000001U)

#define CSL_SHA_SHA512_P_MODE_HMAC_OUTER_HASH_MASK              (0x00000080U)
#define CSL_SHA_SHA512_P_MODE_HMAC_OUTER_HASH_SHIFT             (7U)
#define CSL_SHA_SHA512_P_MODE_HMAC_OUTER_HASH_RESETVAL          (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_HMAC_OUTER_HASH_NO_HMAC           (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_HMAC_OUTER_HASH_HMAC              (0x00000001U)

#define CSL_SHA_SHA512_P_MODE_REUSE_HMAC_KEY_MASK               (0x00000040U)
#define CSL_SHA_SHA512_P_MODE_REUSE_HMAC_KEY_SHIFT              (6U)
#define CSL_SHA_SHA512_P_MODE_REUSE_HMAC_KEY_RESETVAL           (0x00000000U)
#define CSL_SHA_SHA512_P_MODE_REUSE_HMAC_KEY_MAX                (0x00000001U)

#define CSL_SHA_SHA512_P_MODE_RESETVAL                          (0x00000000U)

/* SHA512_P_LENGTH */

#define CSL_SHA_SHA512_P_LENGTH_LENGTH_MASK                     (0xFFFFFFFFU)
#define CSL_SHA_SHA512_P_LENGTH_LENGTH_SHIFT                    (0U)
#define CSL_SHA_SHA512_P_LENGTH_LENGTH_RESETVAL                 (0x00000000U)
#define CSL_SHA_SHA512_P_LENGTH_LENGTH_MAX                      (0xffffffffU)

#define CSL_SHA_SHA512_P_LENGTH_RESETVAL                        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
