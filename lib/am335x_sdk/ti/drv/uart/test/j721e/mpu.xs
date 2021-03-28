/*
 * Copyright (c) 2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== event_MPU.xs ========
 *  MPU Settings for J721E device's Cortex-R5F
 */

/*
 *  -------------------------------------------------------------------------------------------------------------
 * | Id | Base Address | Size | En | Cacheable                                 | XN | AccPerm             | Mask |
 * |----|--------------|------|----|-------------------------------------------|----|---------------------|------|
 * | 0  | 0x00000000   | 4GB  | T  | uncacheable, Shareable                    | F  | RW at PL 1 & PL 2   | 0x0  |
 * |----|--------------|------|----|-------------------------------------------|----|---------------------|------|
 * | 1  | 0 (local TCM)| 32K  | T  | Write-Back, Write-Allocate, Non-Shareable | F  | RW at PL 1          | 0x0  |
 * |----|--------------|------|----|-------------------------------------------|----|---------------------|------|
 * | 2  | 0x41000000   | 32K  | T  | Write-Back, Write-Allocate, Non-Shareable | F  | RW at PL 1          | 0x0  |
 * |----|--------------|------|----|-------------------------------------------|----|---------------------|------|
 * | 3  | 0x41010000   | 32K  | T  | Write-Back, Write-Allocate, Non-Shareable | F  | RW at PL 1          | 0x0  |
 * |----|--------------|------|----|-------------------------------------------|----|---------------------|------|
 * | 4  | 0x41C00000   | 1MB  | T  | Write-Back, Write-Allocate, Non-Shareable | F  | RW at PL 1          | 0x0  |
 *  -------------------------------------------------------------------------------------------------------------
 * | 5  | 0x70000000   | 8MB  | T  | MSMC Ram - Cachable                       | F  | RW at PL 1          | 0x0  |
 *  -------------------------------------------------------------------------------------------------------------
 * | 6  | 0x80000000   | 2GB  | T  | DDR - Strongly Ordered, Shareable         | F  | RW at PL 1 & PL 3   | 0x0  |
 *  -------------------------------------------------------------------------------------------------------------
 * | 7  | 0xAA000000   | 32MB | T  | DDR (VRing Buffer) - Uncacheble           | F  | RW at PL 1 & PL 3   | 0x0  |
 * |-------------------------------------------------------------------------------------------------------------|
 */

/*
 * Note: Marking a region as shareable will cause the region to behave as outer shareable with write through
 *       no write-allocate caching policy irrespective of the actual cache policy set. Therefore, only select
 *       regions that are actually shared outside the R5 CPUSS must be marked as shared.
 */

var MPU = xdc.useModule('ti.sysbios.family.arm.MPU');
MPU.enableMPU = true;
MPU.enableBackgroundRegion = true;

var attrs = new MPU.RegionAttrs();
MPU.initRegionAttrsMeta(attrs);

/* This entry covers the whole 32 bit memory range
   Address: 0x00000000-0xffffffff */
attrs.enable = true;
attrs.bufferable = false;
attrs.cacheable = false;
attrs.shareable = true;
attrs.noExecute = true;
attrs.accPerm = 1;          /* RW at PL1 */
attrs.tex = 0;
attrs.subregionDisableMask = 0;
MPU.setRegionMeta(0, 0x00000000, MPU.RegionSize_4G, attrs);

/* This entry covers the ATCM mapped to 0 */
attrs.enable = true;
attrs.bufferable = true;
attrs.cacheable = true;
attrs.shareable = true;
attrs.noExecute = false;
attrs.accPerm = 1;          /* RW at PL1 */
attrs.tex = 1;
attrs.subregionDisableMask = 0;
MPU.setRegionMeta(1, 0x00000000, MPU.RegionSize_32K, attrs);

/* This entry covers ATCM if mapped to 0x41000000 */
attrs.enable = true;
attrs.bufferable = true;
attrs.cacheable = true;
attrs.shareable = false;
attrs.noExecute = false;
attrs.accPerm = 1;          /* RW at PL1 */
attrs.tex = 1;
attrs.subregionDisableMask = 0;
MPU.setRegionMeta(2, 0x41000000, MPU.RegionSize_32K, attrs);

/* This entry covers BTCM if mapped to 0x41010000 */
attrs.enable = true;
attrs.bufferable = true;
attrs.cacheable = true;
attrs.shareable = false;
attrs.noExecute = false;
attrs.accPerm = 1;          /* RW at PL1 */
attrs.tex = 1;
attrs.subregionDisableMask = 0x0;
MPU.setRegionMeta(3, 0x41010000, MPU.RegionSize_32K, attrs);

/* This entry covers RAM0 */
attrs.enable = true;
attrs.bufferable = true;
attrs.cacheable = true;
attrs.shareable = false;
attrs.noExecute = false;
attrs.accPerm = 1;          /* RW at PL1 */
attrs.tex = 1;
attrs.subregionDisableMask = 0;
MPU.setRegionMeta(4, 0x41C00000, MPU.RegionSize_1M, attrs);

/* This entry covers MSMC SRAM */
attrs.enable = true;
attrs.bufferable = true;
attrs.cacheable = true;
attrs.shareable = false;
attrs.noExecute = false;
attrs.accPerm = 1;          /* RW at PL1 */
attrs.tex = 1;
attrs.subregionDisableMask = 0;
MPU.setRegionMeta(5, 0x70000000, MPU.RegionSize_8M, attrs);

/* This entry covers DDR memory */
attrs.enable = true;
attrs.bufferable = true;
attrs.cacheable = true;
attrs.shareable = false;
attrs.noExecute = false;
attrs.accPerm = 0x3;          /* RW at PL1 & PL2 */
attrs.tex = 1;
attrs.subregionDisableMask = 0;
MPU.setRegionMeta(6, 0x80000000, MPU.RegionSize_2G, attrs);

/* Ring Buffer uncached.... */
attrs.enable = true;
attrs.bufferable = false;
attrs.cacheable = false;
attrs.shareable = true;
attrs.noExecute = true;
attrs.accPerm = 3;          /* RW at PL1 */
attrs.tex = 0;
attrs.subregionDisableMask = 0;
MPU.setRegionMeta(7, 0xAA000000, MPU.RegionSize_32M, attrs);
