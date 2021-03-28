/**
 * \file   diskImage.h
 *
 * \brief  This file contains simplified image of a FAT16 
 * formatted disk. The 16MB disk was formatted with mkfs.fat under Linux
 * and a file called readme.txt was copied to it. The non-zero data
 * of the disk image are copied here under various blocks
 *
 */

/*
* Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
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

#ifndef USB_DISKIMG_H
#define USB_DISKIMG_H

/* only copy the non-zero data of the Boot Sector / BPB */
uint32_t img_mbr[] =   {
                        /* MBR for 16MB */
                        0x6D903CEB, 0x2E73666B, 0x00746166, 0x00010402,
                        0x00020002, 0x0020F880, 0x00010020, 0x00000000,
                        0x00000000, 0x51290180, 0x00B5D3C2, 0x00000000, 
                        0x00000000, 0x41460000, 0x20363154, 0x1F0E2020, 
                        0xAC7C5BBE, 0x0B74C022, 0xBB0EB456, 0x10CD0007, 
                        0x32F0EB5E, 0xCD16CDE4, 0x54FEEB19, 0x20736968, 
                        0x6E207369, 0x6120746F, 0x6F6F6220, 0x6C626174, 
                        0x69642065, 0x202E6B73, 0x656C5020, 0x20657361, 
                        0x65736E69, 0x61207472, 0x6F6F6220, 0x6C626174, 
                        0x6C662065, 0x7970706F, 0x646E6120, 0x72700A0D, 
                        0x20737365, 0x20796E61, 0x2079656B, 0x74206F74, 
                        0x61207972, 0x6E696167, 0x2E2E2E20, 0x000A0D20
						};

uint32_t img_rd[] =    {0x2D4B4450,	0x44425355, 0x08005645, 0xB6860000, 
                        0x4A994A99, 0xB6860000, 0x00004A99, 0x00000000, 
                        0x65007241, 0x64006100, 0x0F006D00, 0x00657300, 
                        0x0074002E, 0x00740078, 0x00000000, 0xFFFFFFFF, 
                        0x44414552, 0x2020454D, 0x20545854, 0xB6A46400, 
                        0x4A994A99, 0xB6A40000, 0x00034A99, 0x0000006E};



uint8_t img_fc[] =      "Hello\r\nThis is a simple text file just for "
                        "testing purpose.\r\nIf you can read this, congrats, "
                        "your USB device mode example is working\r\n";


#endif
