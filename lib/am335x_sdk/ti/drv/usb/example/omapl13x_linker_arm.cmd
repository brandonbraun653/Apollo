/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

-e Entry
-heap  0x10000
-stack 0x16000

MEMORY
{
    L3_CBA_RAM (RWX) : org = 0x80000000, len = 0x20000
    APP_CODE_MEM : org = 0xc3001000, len = 0x1ff000
    APP_CACHED_DATA_MEM : org = 0xc3200000, len = 0x400000
    APP_UNCACHED_DATA_BLK3_MEM : org = 0xc3d00000, len = 0x200000
    APP_CACHED_DATA_BLK1_MEM : org = 0xc3600000, len = 0x400000
    APP_CACHED_DATA_BLK2_MEM : org = 0xc3a00000, len = 0x200000
}

SECTIONS
{
    .text: load >> APP_CODE_MEM
    .ti.decompress: load > APP_CODE_MEM
    .stack: load > APP_CACHED_DATA_MEM
    GROUP: load > APP_CACHED_DATA_MEM
    {
        .bss:
		{
    	bss_start = . ;
    	*(.bss)
		bss_end = . ;
        }
        .neardata:
        .rodata:
    }
    .cinit: load > APP_CACHED_DATA_MEM
    .pinit: load >> APP_CACHED_DATA_MEM
    .init_array: load > APP_CACHED_DATA_MEM
    .const: load >> APP_CACHED_DATA_MEM
    .data: load >> APP_CACHED_DATA_MEM
    .fardata: load >> APP_CACHED_DATA_MEM
    .switch: load >> APP_CACHED_DATA_MEM
    .sysmem: load > APP_CACHED_DATA_MEM
    .far: load >> APP_CACHED_DATA_MEM
    .args: load > APP_CACHED_DATA_MEM align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> APP_CACHED_DATA_MEM
    .ti.handler_table: load > APP_CACHED_DATA_MEM
    .bss:extMemCache:ramdisk: load > APP_CACHED_DATA_BLK2_MEM, type = NOLOAD
    .vecs: load > APP_CODE_MEM

}
