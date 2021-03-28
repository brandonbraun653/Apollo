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
 *  ======== rsc_table_basic.h ========
 *
 *  Include this table in each base image, which is read from remoteproc on
 *  host side.
 *
 */

#ifndef RSC_TABLE_BASIC_H_
#define RSC_TABLE_BASIC_H_
#include <stdint.h>

/* Common Resource Structure Types */
struct resource_table {
    uint32_t ver;
    uint32_t num;
    uint32_t reserved[2];
};

struct my_resource_table {
    struct resource_table base;
};

#pragma DATA_SECTION(ti_basic_ResourceTable, ".resource_table")
#pragma DATA_ALIGN(ti_basic_ResourceTable, 4096)
#pragma RETAIN(ti_basic_ResourceTable)

const struct my_resource_table ti_basic_ResourceTable = {
    {
        1, /* we're the first version that implements this */

        0,

        0, 0, /* reserved, must be zero */
    }
    /* offsets to entries */

};

#endif /* RSC_TABLE_BASIC_H_ */
