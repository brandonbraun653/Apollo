/**
 *  \file   emac_utils.c
 *
 *  \brief  EMAC Driver utility file.
 *
 *   This file contains helper functions internal to EMAC driver.
 */

/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdint.h>
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>
#include <ti/drv/emac/emac_ioctl.h>


/* utility to return lower 16 bits of 32 bit crc on array of 8 bytes */
uint16_t emac_util_crc64( uint8_t input[8])
{
    int32_t i;
    uint16_t res = 0x0000;
    int32_t j;
    int32_t k=0;

    uint8_t emac_this_c[64];
    uint8_t emac_this_d[64];
    uint8_t emac_next_c[64];

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            emac_this_d[k] =  (input[i] & (1<<j)) ?  1 : 0;
            emac_this_c[k] = 0;
            k+=1;
        }
    }

    emac_next_c[ 0] = emac_this_c[  0] ^ emac_this_c[  2] ^ emac_this_c[  5] ^ emac_this_c[ 12] ^ emac_this_c[ 13] ^ emac_this_c[ 15] ^
                 emac_this_c[ 16] ^ emac_this_c[ 18] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^ emac_this_c[ 23] ^ emac_this_c[ 26] ^
                 emac_this_c[ 28] ^ emac_this_c[ 29] ^ emac_this_c[ 31] ^ emac_this_d[ 63] ^ emac_this_d[ 57] ^ emac_this_d[ 54] ^
                 emac_this_d[ 53] ^ emac_this_d[ 51] ^ emac_this_d[ 47] ^ emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 37] ^
                 emac_this_d[ 35] ^ emac_this_d[ 34] ^ emac_this_d[ 33] ^ emac_this_d[ 32] ^ emac_this_d[ 31] ^ emac_this_d[ 29] ^
                 emac_this_d[ 26] ^ emac_this_d[ 19] ^ emac_this_d[ 18] ^ emac_this_d[ 16] ^ emac_this_d[ 15] ^ emac_this_d[ 13] ^
                 emac_this_d[ 10] ^ emac_this_d[  9] ^ emac_this_d[  8] ^ emac_this_d[  5] ^ emac_this_d[  3] ^ emac_this_d[  2] ^
                 emac_this_d[  0];                                                                       
    emac_next_c[ 1] = emac_this_c[  1] ^ emac_this_c[  2] ^ emac_this_c[  3] ^ emac_this_c[  5] ^ emac_this_c[  6] ^ emac_this_c[ 12] ^
                 emac_this_c[ 14] ^ emac_this_c[ 15] ^ emac_this_c[ 17] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 21] ^
                 emac_this_c[ 24] ^ emac_this_c[ 26] ^ emac_this_c[ 27] ^ emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_c[ 31] ^
                 emac_this_d[ 63] ^ emac_this_d[ 62] ^ emac_this_d[ 57] ^ emac_this_d[ 56] ^ emac_this_d[ 54] ^ emac_this_d[ 52] ^
                 emac_this_d[ 51] ^ emac_this_d[ 50] ^ emac_this_d[ 47] ^ emac_this_d[ 46] ^ emac_this_d[ 39] ^ emac_this_d[ 36] ^
                 emac_this_d[ 35] ^ emac_this_d[ 30] ^ emac_this_d[ 29] ^ emac_this_d[ 28] ^ emac_this_d[ 26] ^ emac_this_d[ 25] ^
                 emac_this_d[ 19] ^ emac_this_d[ 17] ^ emac_this_d[ 16] ^ emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^
                 emac_this_d[ 10] ^ emac_this_d[  7] ^ emac_this_d[  5] ^ emac_this_d[  4] ^ emac_this_d[  3] ^ emac_this_d[  1] ^
                 emac_this_d[  0];                                                                       
    emac_next_c[ 2] = emac_this_c[  0] ^ emac_this_c[  3] ^ emac_this_c[  4] ^ emac_this_c[  5] ^ emac_this_c[  6] ^ emac_this_c[  7] ^
                 emac_this_c[ 12] ^ emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 23] ^ emac_this_c[ 25] ^
                 emac_this_c[ 26] ^ emac_this_c[ 27] ^ emac_this_d[ 63] ^ emac_this_d[ 62] ^ emac_this_d[ 61] ^ emac_this_d[ 57] ^
                 emac_this_d[ 56] ^ emac_this_d[ 55] ^ emac_this_d[ 54] ^ emac_this_d[ 50] ^ emac_this_d[ 49] ^ emac_this_d[ 47] ^
                 emac_this_d[ 46] ^ emac_this_d[ 45] ^ emac_this_d[ 39] ^ emac_this_d[ 37] ^ emac_this_d[ 33] ^ emac_this_d[ 32] ^
                 emac_this_d[ 31] ^ emac_this_d[ 28] ^ emac_this_d[ 27] ^ emac_this_d[ 26] ^ emac_this_d[ 25] ^ emac_this_d[ 24] ^
                 emac_this_d[ 19] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  8] ^ emac_this_d[  6] ^
                 emac_this_d[  5] ^ emac_this_d[  4];                                                         
    emac_next_c[ 3] = emac_this_c[  0] ^ emac_this_c[  1] ^ emac_this_c[  4] ^ emac_this_c[  5] ^ emac_this_c[  6] ^ emac_this_c[  7] ^
                 emac_this_c[  8] ^ emac_this_c[ 13] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^ emac_this_c[ 24] ^
                 emac_this_c[ 26] ^ emac_this_c[ 27] ^ emac_this_c[ 28] ^ emac_this_d[ 62] ^ emac_this_d[ 61] ^ emac_this_d[ 60] ^
                 emac_this_d[ 56] ^ emac_this_d[ 55] ^ emac_this_d[ 54] ^ emac_this_d[ 53] ^ emac_this_d[ 49] ^ emac_this_d[ 48] ^
                 emac_this_d[ 46] ^ emac_this_d[ 45] ^ emac_this_d[ 44] ^ emac_this_d[ 38] ^ emac_this_d[ 36] ^ emac_this_d[ 32] ^
                 emac_this_d[ 31] ^ emac_this_d[ 30] ^ emac_this_d[ 27] ^ emac_this_d[ 26] ^ emac_this_d[ 25] ^ emac_this_d[ 24] ^
                 emac_this_d[ 23] ^ emac_this_d[ 18] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  9] ^ emac_this_d[  7] ^
                 emac_this_d[  5] ^ emac_this_d[  4] ^ emac_this_d[  3];                                           
    emac_next_c[ 4] = emac_this_c[  1] ^ emac_this_c[  6] ^ emac_this_c[  7] ^ emac_this_c[  8] ^ emac_this_c[  9] ^ emac_this_c[ 12] ^
                 emac_this_c[ 13] ^ emac_this_c[ 14] ^ emac_this_c[ 15] ^ emac_this_c[ 16] ^ emac_this_c[ 18] ^ emac_this_c[ 25] ^
                 emac_this_c[ 26] ^ emac_this_c[ 27] ^ emac_this_c[ 31] ^ emac_this_d[ 63] ^ emac_this_d[ 61] ^ emac_this_d[ 60] ^
                 emac_this_d[ 59] ^ emac_this_d[ 57] ^ emac_this_d[ 55] ^ emac_this_d[ 52] ^ emac_this_d[ 51] ^ emac_this_d[ 48] ^
                 emac_this_d[ 45] ^ emac_this_d[ 44] ^ emac_this_d[ 43] ^ emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 34] ^
                 emac_this_d[ 33] ^ emac_this_d[ 32] ^ emac_this_d[ 30] ^ emac_this_d[ 25] ^ emac_this_d[ 24] ^ emac_this_d[ 23] ^
                 emac_this_d[ 22] ^ emac_this_d[ 19] ^ emac_this_d[ 18] ^ emac_this_d[ 17] ^ emac_this_d[ 16] ^ emac_this_d[ 15] ^
                 emac_this_d[ 13] ^ emac_this_d[  6] ^ emac_this_d[  5] ^ emac_this_d[  4] ^ emac_this_d[  0];               
    emac_next_c[ 5] = emac_this_c[  5] ^ emac_this_c[  7] ^ emac_this_c[  8] ^ emac_this_c[  9] ^ emac_this_c[ 10] ^ emac_this_c[ 12] ^
                 emac_this_c[ 14] ^ emac_this_c[ 17] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^
                 emac_this_c[ 23] ^ emac_this_c[ 27] ^ emac_this_c[ 29] ^ emac_this_c[ 31] ^ emac_this_d[ 63] ^ emac_this_d[ 62] ^
                 emac_this_d[ 60] ^ emac_this_d[ 59] ^ emac_this_d[ 58] ^ emac_this_d[ 57] ^ emac_this_d[ 56] ^ emac_this_d[ 53] ^
                 emac_this_d[ 50] ^ emac_this_d[ 44] ^ emac_this_d[ 43] ^ emac_this_d[ 42] ^ emac_this_d[ 39] ^ emac_this_d[ 35] ^
                 emac_this_d[ 34] ^ emac_this_d[ 26] ^ emac_this_d[ 24] ^ emac_this_d[ 23] ^ emac_this_d[ 22] ^ emac_this_d[ 21] ^
                 emac_this_d[ 19] ^ emac_this_d[ 17] ^ emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[ 10] ^
                 emac_this_d[  9] ^ emac_this_d[  8] ^ emac_this_d[  4] ^ emac_this_d[  2] ^ emac_this_d[  0];               
    emac_next_c[ 6] = emac_this_c[  6] ^ emac_this_c[  8] ^ emac_this_c[  9] ^ emac_this_c[ 10] ^ emac_this_c[ 11] ^ emac_this_c[ 13] ^
                 emac_this_c[ 15] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 22] ^ emac_this_c[ 23] ^
                 emac_this_c[ 24] ^ emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_d[ 62] ^ emac_this_d[ 61] ^ emac_this_d[ 59] ^
                 emac_this_d[ 58] ^ emac_this_d[ 57] ^ emac_this_d[ 56] ^ emac_this_d[ 55] ^ emac_this_d[ 52] ^ emac_this_d[ 49] ^
                 emac_this_d[ 43] ^ emac_this_d[ 42] ^ emac_this_d[ 41] ^ emac_this_d[ 38] ^ emac_this_d[ 34] ^ emac_this_d[ 33] ^
                 emac_this_d[ 25] ^ emac_this_d[ 23] ^ emac_this_d[ 22] ^ emac_this_d[ 21] ^ emac_this_d[ 20] ^ emac_this_d[ 18] ^
                 emac_this_d[ 16] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[  9] ^ emac_this_d[  8] ^
                 emac_this_d[  7] ^ emac_this_d[  3] ^ emac_this_d[  1];                                           
    emac_next_c[ 7] = emac_this_c[  0] ^ emac_this_c[  2] ^ emac_this_c[  5] ^ emac_this_c[  7] ^ emac_this_c[  9] ^ emac_this_c[ 10] ^
                 emac_this_c[ 11] ^ emac_this_c[ 13] ^ emac_this_c[ 14] ^ emac_this_c[ 15] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^
                 emac_this_c[ 20] ^ emac_this_c[ 22] ^ emac_this_c[ 24] ^ emac_this_c[ 25] ^ emac_this_c[ 26] ^ emac_this_c[ 28] ^
                 emac_this_d[ 63] ^ emac_this_d[ 61] ^ emac_this_d[ 60] ^ emac_this_d[ 58] ^ emac_this_d[ 56] ^ emac_this_d[ 55] ^
                 emac_this_d[ 53] ^ emac_this_d[ 48] ^ emac_this_d[ 47] ^ emac_this_d[ 42] ^ emac_this_d[ 41] ^ emac_this_d[ 40] ^
                 emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 35] ^ emac_this_d[ 34] ^ emac_this_d[ 31] ^ emac_this_d[ 29] ^
                 emac_this_d[ 26] ^ emac_this_d[ 24] ^ emac_this_d[ 22] ^ emac_this_d[ 21] ^ emac_this_d[ 20] ^ emac_this_d[ 18] ^
                 emac_this_d[ 17] ^ emac_this_d[ 16] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[  9] ^
                 emac_this_d[  7] ^ emac_this_d[  6] ^ emac_this_d[  5] ^ emac_this_d[  3];                             
    emac_next_c[ 8] = emac_this_c[  0] ^ emac_this_c[  1] ^ emac_this_c[  2] ^ emac_this_c[  3] ^ emac_this_c[  5] ^ emac_this_c[  6] ^
                 emac_this_c[  8] ^ emac_this_c[ 10] ^ emac_this_c[ 11] ^ emac_this_c[ 13] ^ emac_this_c[ 14] ^ emac_this_c[ 18] ^
                 emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 22] ^ emac_this_c[ 25] ^ emac_this_c[ 27] ^ emac_this_c[ 28] ^
                 emac_this_c[ 31] ^ emac_this_d[ 63] ^ emac_this_d[ 62] ^ emac_this_d[ 60] ^ emac_this_d[ 59] ^ emac_this_d[ 55] ^
                 emac_this_d[ 53] ^ emac_this_d[ 52] ^ emac_this_d[ 51] ^ emac_this_d[ 46] ^ emac_this_d[ 41] ^ emac_this_d[ 40] ^
                 emac_this_d[ 35] ^ emac_this_d[ 32] ^ emac_this_d[ 31] ^ emac_this_d[ 30] ^ emac_this_d[ 29] ^ emac_this_d[ 28] ^
                 emac_this_d[ 26] ^ emac_this_d[ 25] ^ emac_this_d[ 23] ^ emac_this_d[ 21] ^ emac_this_d[ 20] ^ emac_this_d[ 18] ^
                 emac_this_d[ 17] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[  9] ^ emac_this_d[  6] ^
                 emac_this_d[  4] ^ emac_this_d[  3] ^ emac_this_d[  0];                                           
    emac_next_c[ 9] = emac_this_c[  0] ^ emac_this_c[  1] ^ emac_this_c[  2] ^ emac_this_c[  3] ^ emac_this_c[  4] ^ emac_this_c[  6] ^
                 emac_this_c[  7] ^ emac_this_c[  9] ^ emac_this_c[ 11] ^ emac_this_c[ 12] ^ emac_this_c[ 14] ^ emac_this_c[ 15] ^
                 emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 23] ^ emac_this_c[ 26] ^ emac_this_c[ 28] ^
                 emac_this_c[ 29] ^ emac_this_d[ 62] ^ emac_this_d[ 61] ^ emac_this_d[ 59] ^ emac_this_d[ 58] ^ emac_this_d[ 54] ^
                 emac_this_d[ 52] ^ emac_this_d[ 51] ^ emac_this_d[ 50] ^ emac_this_d[ 45] ^ emac_this_d[ 40] ^ emac_this_d[ 39] ^
                 emac_this_d[ 34] ^ emac_this_d[ 31] ^ emac_this_d[ 30] ^ emac_this_d[ 29] ^ emac_this_d[ 28] ^ emac_this_d[ 27] ^
                 emac_this_d[ 25] ^ emac_this_d[ 24] ^ emac_this_d[ 22] ^ emac_this_d[ 20] ^ emac_this_d[ 19] ^ emac_this_d[ 17] ^
                 emac_this_d[ 16] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  8] ^ emac_this_d[  5] ^
                 emac_this_d[  3] ^ emac_this_d[  2];                                                         
    emac_next_c[10] = emac_this_c[  0] ^ emac_this_c[  1] ^ emac_this_c[  3] ^ emac_this_c[  4] ^ emac_this_c[  7] ^ emac_this_c[  8] ^
                 emac_this_c[ 10] ^ emac_this_c[ 18] ^ emac_this_c[ 20] ^ emac_this_c[ 23] ^ emac_this_c[ 24] ^ emac_this_c[ 26] ^
                 emac_this_c[ 27] ^ emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_c[ 31] ^ emac_this_d[ 63] ^ emac_this_d[ 61] ^
                 emac_this_d[ 60] ^ emac_this_d[ 58] ^ emac_this_d[ 54] ^ emac_this_d[ 50] ^ emac_this_d[ 49] ^ emac_this_d[ 47] ^
                 emac_this_d[ 44] ^ emac_this_d[ 37] ^ emac_this_d[ 35] ^ emac_this_d[ 34] ^ emac_this_d[ 32] ^ emac_this_d[ 31] ^
                 emac_this_d[ 30] ^ emac_this_d[ 28] ^ emac_this_d[ 27] ^ emac_this_d[ 24] ^ emac_this_d[ 23] ^ emac_this_d[ 21] ^
                 emac_this_d[ 13] ^ emac_this_d[ 11] ^ emac_this_d[  8] ^ emac_this_d[  7] ^ emac_this_d[  5] ^ emac_this_d[  4] ^
                 emac_this_d[  3] ^ emac_this_d[  1] ^ emac_this_d[  0];                                           
    emac_next_c[11] = emac_this_c[  1] ^ emac_this_c[  4] ^ emac_this_c[  8] ^ emac_this_c[  9] ^ emac_this_c[ 11] ^ emac_this_c[ 12] ^
                 emac_this_c[ 13] ^ emac_this_c[ 15] ^ emac_this_c[ 16] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 22] ^
                 emac_this_c[ 23] ^ emac_this_c[ 24] ^ emac_this_c[ 25] ^ emac_this_c[ 26] ^ emac_this_c[ 27] ^ emac_this_d[ 63] ^
                 emac_this_d[ 62] ^ emac_this_d[ 60] ^ emac_this_d[ 59] ^ emac_this_d[ 54] ^ emac_this_d[ 51] ^ emac_this_d[ 49] ^
                 emac_this_d[ 48] ^ emac_this_d[ 47] ^ emac_this_d[ 46] ^ emac_this_d[ 43] ^ emac_this_d[ 39] ^ emac_this_d[ 38] ^
                 emac_this_d[ 37] ^ emac_this_d[ 36] ^ emac_this_d[ 35] ^ emac_this_d[ 32] ^ emac_this_d[ 30] ^ emac_this_d[ 27] ^
                 emac_this_d[ 23] ^ emac_this_d[ 22] ^ emac_this_d[ 20] ^ emac_this_d[ 19] ^ emac_this_d[ 18] ^ emac_this_d[ 16] ^
                 emac_this_d[ 15] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[  9] ^ emac_this_d[  8] ^ emac_this_d[  7] ^
                 emac_this_d[  6] ^ emac_this_d[  5] ^ emac_this_d[  4];                                           
    emac_next_c[12] = emac_this_c[  9] ^ emac_this_c[ 10] ^ emac_this_c[ 14] ^ emac_this_c[ 15] ^ emac_this_c[ 17] ^ emac_this_c[ 18] ^
                 emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^ emac_this_c[ 24] ^ emac_this_c[ 25] ^
                 emac_this_c[ 27] ^ emac_this_c[ 29] ^ emac_this_c[ 31] ^ emac_this_d[ 63] ^ emac_this_d[ 62] ^ emac_this_d[ 61] ^
                 emac_this_d[ 59] ^ emac_this_d[ 58] ^ emac_this_d[ 57] ^ emac_this_d[ 54] ^ emac_this_d[ 51] ^ emac_this_d[ 50] ^
                 emac_this_d[ 48] ^ emac_this_d[ 46] ^ emac_this_d[ 45] ^ emac_this_d[ 42] ^ emac_this_d[ 39] ^ emac_this_d[ 36] ^
                 emac_this_d[ 33] ^ emac_this_d[ 32] ^ emac_this_d[ 22] ^ emac_this_d[ 21] ^ emac_this_d[ 17] ^ emac_this_d[ 16] ^
                 emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  9] ^
                 emac_this_d[  7] ^ emac_this_d[  6] ^ emac_this_d[  4] ^ emac_this_d[  2] ^ emac_this_d[  0];               
    emac_next_c[13] = emac_this_c[  0] ^ emac_this_c[ 10] ^ emac_this_c[ 11] ^ emac_this_c[ 15] ^ emac_this_c[ 16] ^ emac_this_c[ 18] ^
                 emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^ emac_this_c[ 23] ^ emac_this_c[ 25] ^
                 emac_this_c[ 26] ^ emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_d[ 62] ^ emac_this_d[ 61] ^ emac_this_d[ 60] ^
                 emac_this_d[ 58] ^ emac_this_d[ 57] ^ emac_this_d[ 56] ^ emac_this_d[ 53] ^ emac_this_d[ 50] ^ emac_this_d[ 49] ^
                 emac_this_d[ 47] ^ emac_this_d[ 45] ^ emac_this_d[ 44] ^ emac_this_d[ 41] ^ emac_this_d[ 38] ^ emac_this_d[ 35] ^
                 emac_this_d[ 32] ^ emac_this_d[ 31] ^ emac_this_d[ 21] ^ emac_this_d[ 20] ^ emac_this_d[ 16] ^ emac_this_d[ 15] ^
                 emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  9] ^ emac_this_d[  8] ^
                 emac_this_d[  6] ^ emac_this_d[  5] ^ emac_this_d[  3] ^ emac_this_d[  1];                             
    emac_next_c[14] = emac_this_c[  0] ^ emac_this_c[  1] ^ emac_this_c[ 11] ^ emac_this_c[ 12] ^ emac_this_c[ 16] ^ emac_this_c[ 17] ^
                 emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^ emac_this_c[ 23] ^ emac_this_c[ 24] ^
                 emac_this_c[ 26] ^ emac_this_c[ 27] ^ emac_this_c[ 29] ^ emac_this_c[ 31] ^ emac_this_d[ 61] ^ emac_this_d[ 60] ^
                 emac_this_d[ 59] ^ emac_this_d[ 57] ^ emac_this_d[ 56] ^ emac_this_d[ 55] ^ emac_this_d[ 52] ^ emac_this_d[ 49] ^
                 emac_this_d[ 48] ^ emac_this_d[ 46] ^ emac_this_d[ 44] ^ emac_this_d[ 43] ^ emac_this_d[ 40] ^ emac_this_d[ 37] ^
                 emac_this_d[ 34] ^ emac_this_d[ 31] ^ emac_this_d[ 30] ^ emac_this_d[ 20] ^ emac_this_d[ 19] ^ emac_this_d[ 15] ^
                 emac_this_d[ 14] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  9] ^ emac_this_d[  8] ^
                 emac_this_d[  7] ^ emac_this_d[  5] ^ emac_this_d[  4] ^ emac_this_d[  2] ^ emac_this_d[  0];               
    emac_next_c[15] = emac_this_c[  1] ^ emac_this_c[  2] ^ emac_this_c[ 12] ^ emac_this_c[ 13] ^ emac_this_c[ 17] ^ emac_this_c[ 18] ^
                 emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^ emac_this_c[ 23] ^ emac_this_c[ 24] ^ emac_this_c[ 25] ^
                 emac_this_c[ 27] ^ emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_d[ 60] ^ emac_this_d[ 59] ^ emac_this_d[ 58] ^
                 emac_this_d[ 56] ^ emac_this_d[ 55] ^ emac_this_d[ 54] ^ emac_this_d[ 51] ^ emac_this_d[ 48] ^ emac_this_d[ 47] ^
                 emac_this_d[ 45] ^ emac_this_d[ 43] ^ emac_this_d[ 42] ^ emac_this_d[ 39] ^ emac_this_d[ 36] ^ emac_this_d[ 33] ^
                 emac_this_d[ 30] ^ emac_this_d[ 29] ^ emac_this_d[ 19] ^ emac_this_d[ 18] ^ emac_this_d[ 14] ^ emac_this_d[ 13] ^
                 emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  9] ^ emac_this_d[  8] ^ emac_this_d[  7] ^ emac_this_d[  6] ^
                 emac_this_d[  4] ^ emac_this_d[  3] ^ emac_this_d[  1];                                           
    emac_next_c[16] = emac_this_c[  0] ^ emac_this_c[  3] ^ emac_this_c[  5] ^ emac_this_c[ 12] ^ emac_this_c[ 14] ^ emac_this_c[ 15] ^
                 emac_this_c[ 16] ^ emac_this_c[ 19] ^ emac_this_c[ 24] ^ emac_this_c[ 25] ^ emac_this_d[ 63] ^ emac_this_d[ 59] ^
                 emac_this_d[ 58] ^ emac_this_d[ 55] ^ emac_this_d[ 51] ^ emac_this_d[ 50] ^ emac_this_d[ 46] ^ emac_this_d[ 44] ^
                 emac_this_d[ 42] ^ emac_this_d[ 41] ^ emac_this_d[ 39] ^ emac_this_d[ 37] ^ emac_this_d[ 34] ^ emac_this_d[ 33] ^
                 emac_this_d[ 31] ^ emac_this_d[ 28] ^ emac_this_d[ 26] ^ emac_this_d[ 19] ^ emac_this_d[ 17] ^ emac_this_d[ 16] ^
                 emac_this_d[ 15] ^ emac_this_d[ 12] ^ emac_this_d[  7] ^ emac_this_d[  6];                             
    emac_next_c[17] = emac_this_c[  1] ^ emac_this_c[  4] ^ emac_this_c[  6] ^ emac_this_c[ 13] ^ emac_this_c[ 15] ^ emac_this_c[ 16] ^
                 emac_this_c[ 17] ^ emac_this_c[ 20] ^ emac_this_c[ 25] ^ emac_this_c[ 26] ^ emac_this_d[ 62] ^ emac_this_d[ 58] ^
                 emac_this_d[ 57] ^ emac_this_d[ 54] ^ emac_this_d[ 50] ^ emac_this_d[ 49] ^ emac_this_d[ 45] ^ emac_this_d[ 43] ^
                 emac_this_d[ 41] ^ emac_this_d[ 40] ^ emac_this_d[ 38] ^ emac_this_d[ 36] ^ emac_this_d[ 33] ^ emac_this_d[ 32] ^
                 emac_this_d[ 30] ^ emac_this_d[ 27] ^ emac_this_d[ 25] ^ emac_this_d[ 18] ^ emac_this_d[ 16] ^ emac_this_d[ 15] ^
                 emac_this_d[ 14] ^ emac_this_d[ 11] ^ emac_this_d[  6] ^ emac_this_d[  5];                             
    emac_next_c[18] = emac_this_c[  0] ^ emac_this_c[  2] ^ emac_this_c[  5] ^ emac_this_c[  7] ^ emac_this_c[ 14] ^ emac_this_c[ 16] ^
                 emac_this_c[ 17] ^ emac_this_c[ 18] ^ emac_this_c[ 21] ^ emac_this_c[ 26] ^ emac_this_c[ 27] ^ emac_this_d[ 61] ^
                 emac_this_d[ 57] ^ emac_this_d[ 56] ^ emac_this_d[ 53] ^ emac_this_d[ 49] ^ emac_this_d[ 48] ^ emac_this_d[ 44] ^
                 emac_this_d[ 42] ^ emac_this_d[ 40] ^ emac_this_d[ 39] ^ emac_this_d[ 37] ^ emac_this_d[ 35] ^ emac_this_d[ 32] ^
                 emac_this_d[ 31] ^ emac_this_d[ 29] ^ emac_this_d[ 26] ^ emac_this_d[ 24] ^ emac_this_d[ 17] ^ emac_this_d[ 15] ^
                 emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[ 10] ^ emac_this_d[  5] ^ emac_this_d[  4];               
    emac_next_c[19] = emac_this_c[  0] ^ emac_this_c[  1] ^ emac_this_c[  3] ^ emac_this_c[  6] ^ emac_this_c[  8] ^ emac_this_c[ 15] ^
                 emac_this_c[ 17] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 22] ^ emac_this_c[ 27] ^ emac_this_c[ 28] ^
                 emac_this_d[ 60] ^ emac_this_d[ 56] ^ emac_this_d[ 55] ^ emac_this_d[ 52] ^ emac_this_d[ 48] ^ emac_this_d[ 47] ^
                 emac_this_d[ 43] ^ emac_this_d[ 41] ^ emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 36] ^ emac_this_d[ 34] ^
                 emac_this_d[ 31] ^ emac_this_d[ 30] ^ emac_this_d[ 28] ^ emac_this_d[ 25] ^ emac_this_d[ 23] ^ emac_this_d[ 16] ^
                 emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[  9] ^ emac_this_d[  4] ^ emac_this_d[  3]; 
    emac_next_c[20] = emac_this_c[  1] ^ emac_this_c[  2] ^ emac_this_c[  4] ^ emac_this_c[  7] ^ emac_this_c[  9] ^ emac_this_c[ 16] ^
                 emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 23] ^ emac_this_c[ 28] ^ emac_this_c[ 29] ^
                 emac_this_d[ 59] ^ emac_this_d[ 55] ^ emac_this_d[ 54] ^ emac_this_d[ 51] ^ emac_this_d[ 47] ^ emac_this_d[ 46] ^
                 emac_this_d[ 42] ^ emac_this_d[ 40] ^ emac_this_d[ 38] ^ emac_this_d[ 37] ^ emac_this_d[ 35] ^ emac_this_d[ 33] ^
                 emac_this_d[ 30] ^ emac_this_d[ 29] ^ emac_this_d[ 27] ^ emac_this_d[ 24] ^ emac_this_d[ 22] ^ emac_this_d[ 15] ^
                 emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[  8] ^ emac_this_d[  3] ^ emac_this_d[  2]; 
    emac_next_c[21] = emac_this_c[  2] ^ emac_this_c[  3] ^ emac_this_c[  5] ^ emac_this_c[  8] ^ emac_this_c[ 10] ^ emac_this_c[ 17] ^
                 emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 24] ^ emac_this_c[ 29] ^ emac_this_c[ 30] ^
                 emac_this_d[ 58] ^ emac_this_d[ 54] ^ emac_this_d[ 53] ^ emac_this_d[ 50] ^ emac_this_d[ 46] ^ emac_this_d[ 45] ^
                 emac_this_d[ 41] ^ emac_this_d[ 39] ^ emac_this_d[ 37] ^ emac_this_d[ 36] ^ emac_this_d[ 34] ^ emac_this_d[ 32] ^
                 emac_this_d[ 29] ^ emac_this_d[ 28] ^ emac_this_d[ 26] ^ emac_this_d[ 23] ^ emac_this_d[ 21] ^ emac_this_d[ 14] ^
                 emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  7] ^ emac_this_d[  2] ^ emac_this_d[  1]; 
    emac_next_c[22] = emac_this_c[  2] ^ emac_this_c[  3] ^ emac_this_c[  4] ^ emac_this_c[  5] ^ emac_this_c[  6] ^ emac_this_c[  9] ^
                 emac_this_c[ 11] ^ emac_this_c[ 12] ^ emac_this_c[ 13] ^ emac_this_c[ 15] ^ emac_this_c[ 16] ^ emac_this_c[ 20] ^
                 emac_this_c[ 23] ^ emac_this_c[ 25] ^ emac_this_c[ 26] ^ emac_this_c[ 28] ^ emac_this_c[ 29] ^ emac_this_c[ 30] ^
                 emac_this_d[ 63] ^ emac_this_d[ 54] ^ emac_this_d[ 52] ^ emac_this_d[ 51] ^ emac_this_d[ 49] ^ emac_this_d[ 47] ^
                 emac_this_d[ 45] ^ emac_this_d[ 44] ^ emac_this_d[ 40] ^ emac_this_d[ 39] ^ emac_this_d[ 37] ^ emac_this_d[ 36] ^
                 emac_this_d[ 34] ^ emac_this_d[ 32] ^ emac_this_d[ 29] ^ emac_this_d[ 28] ^ emac_this_d[ 27] ^ emac_this_d[ 26] ^
                 emac_this_d[ 25] ^ emac_this_d[ 22] ^ emac_this_d[ 20] ^ emac_this_d[ 19] ^ emac_this_d[ 18] ^ emac_this_d[ 16] ^
                 emac_this_d[ 15] ^ emac_this_d[ 11] ^ emac_this_d[  8] ^ emac_this_d[  6] ^ emac_this_d[  5] ^ emac_this_d[  3] ^
                 emac_this_d[  2] ^ emac_this_d[  1];                                                         
    emac_next_c[23] = emac_this_c[  2] ^ emac_this_c[  3] ^ emac_this_c[  4] ^ emac_this_c[  6] ^ emac_this_c[  7] ^ emac_this_c[ 10] ^
                 emac_this_c[ 14] ^ emac_this_c[ 15] ^ emac_this_c[ 17] ^ emac_this_c[ 18] ^ emac_this_c[ 22] ^ emac_this_c[ 23] ^
                 emac_this_c[ 24] ^ emac_this_c[ 27] ^ emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_d[ 63] ^ emac_this_d[ 62] ^
                 emac_this_d[ 57] ^ emac_this_d[ 54] ^ emac_this_d[ 50] ^ emac_this_d[ 48] ^ emac_this_d[ 47] ^ emac_this_d[ 46] ^
                 emac_this_d[ 44] ^ emac_this_d[ 43] ^ emac_this_d[ 37] ^ emac_this_d[ 36] ^ emac_this_d[ 34] ^ emac_this_d[ 32] ^
                 emac_this_d[ 29] ^ emac_this_d[ 28] ^ emac_this_d[ 27] ^ emac_this_d[ 25] ^ emac_this_d[ 24] ^ emac_this_d[ 21] ^
                 emac_this_d[ 17] ^ emac_this_d[ 16] ^ emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[  9] ^ emac_this_d[  8] ^
                 emac_this_d[  7] ^ emac_this_d[  4] ^ emac_this_d[  3] ^ emac_this_d[  1];                             
    emac_next_c[24] = emac_this_c[  0] ^ emac_this_c[  3] ^ emac_this_c[  4] ^ emac_this_c[  5] ^ emac_this_c[  7] ^ emac_this_c[  8] ^
                 emac_this_c[ 11] ^ emac_this_c[ 15] ^ emac_this_c[ 16] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 23] ^
                 emac_this_c[ 24] ^ emac_this_c[ 25] ^ emac_this_c[ 28] ^ emac_this_c[ 29] ^ emac_this_c[ 31] ^ emac_this_d[ 62] ^
                 emac_this_d[ 61] ^ emac_this_d[ 56] ^ emac_this_d[ 53] ^ emac_this_d[ 49] ^ emac_this_d[ 47] ^ emac_this_d[ 46] ^
                 emac_this_d[ 45] ^ emac_this_d[ 43] ^ emac_this_d[ 42] ^ emac_this_d[ 36] ^ emac_this_d[ 35] ^ emac_this_d[ 33] ^
                 emac_this_d[ 31] ^ emac_this_d[ 28] ^ emac_this_d[ 27] ^ emac_this_d[ 26] ^ emac_this_d[ 24] ^ emac_this_d[ 23] ^
                 emac_this_d[ 20] ^ emac_this_d[ 16] ^ emac_this_d[ 15] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[  8] ^
                 emac_this_d[  7] ^ emac_this_d[  6] ^ emac_this_d[  3] ^ emac_this_d[  2] ^ emac_this_d[  0];               
    emac_next_c[25] = emac_this_c[  1] ^ emac_this_c[  4] ^ emac_this_c[  5] ^ emac_this_c[  6] ^ emac_this_c[  8] ^ emac_this_c[  9] ^
                 emac_this_c[ 12] ^ emac_this_c[ 16] ^ emac_this_c[ 17] ^ emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 24] ^
                 emac_this_c[ 25] ^ emac_this_c[ 26] ^ emac_this_c[ 29] ^ emac_this_c[ 30] ^ emac_this_d[ 61] ^ emac_this_d[ 60] ^
                 emac_this_d[ 55] ^ emac_this_d[ 52] ^ emac_this_d[ 48] ^ emac_this_d[ 46] ^ emac_this_d[ 45] ^ emac_this_d[ 44] ^
                 emac_this_d[ 42] ^ emac_this_d[ 41] ^ emac_this_d[ 35] ^ emac_this_d[ 34] ^ emac_this_d[ 32] ^ emac_this_d[ 30] ^
                 emac_this_d[ 27] ^ emac_this_d[ 26] ^ emac_this_d[ 25] ^ emac_this_d[ 23] ^ emac_this_d[ 22] ^ emac_this_d[ 19] ^
                 emac_this_d[ 15] ^ emac_this_d[ 14] ^ emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[  7] ^ emac_this_d[  6] ^
                 emac_this_d[  5] ^ emac_this_d[  2] ^ emac_this_d[  1];                                           
    emac_next_c[26] = emac_this_c[  6] ^ emac_this_c[  7] ^ emac_this_c[  9] ^ emac_this_c[ 10] ^ emac_this_c[ 12] ^ emac_this_c[ 15] ^
                 emac_this_c[ 16] ^ emac_this_c[ 17] ^ emac_this_c[ 20] ^ emac_this_c[ 22] ^ emac_this_c[ 23] ^ emac_this_c[ 25] ^
                 emac_this_c[ 27] ^ emac_this_c[ 28] ^ emac_this_c[ 29] ^ emac_this_c[ 30] ^ emac_this_d[ 63] ^ emac_this_d[ 60] ^
                 emac_this_d[ 59] ^ emac_this_d[ 57] ^ emac_this_d[ 53] ^ emac_this_d[ 45] ^ emac_this_d[ 44] ^ emac_this_d[ 43] ^
                 emac_this_d[ 41] ^ emac_this_d[ 40] ^ emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 37] ^ emac_this_d[ 35] ^
                 emac_this_d[ 32] ^ emac_this_d[ 25] ^ emac_this_d[ 24] ^ emac_this_d[ 22] ^ emac_this_d[ 21] ^ emac_this_d[ 19] ^
                 emac_this_d[ 16] ^ emac_this_d[ 15] ^ emac_this_d[ 14] ^ emac_this_d[ 11] ^ emac_this_d[  9] ^ emac_this_d[  8] ^
                 emac_this_d[  6] ^ emac_this_d[  4] ^ emac_this_d[  3] ^ emac_this_d[  2] ^ emac_this_d[  1];               
    emac_next_c[27] = emac_this_c[  0] ^ emac_this_c[  7] ^ emac_this_c[  8] ^ emac_this_c[ 10] ^ emac_this_c[ 11] ^ emac_this_c[ 13] ^
                 emac_this_c[ 16] ^ emac_this_c[ 17] ^ emac_this_c[ 18] ^ emac_this_c[ 21] ^ emac_this_c[ 23] ^ emac_this_c[ 24] ^
                 emac_this_c[ 26] ^ emac_this_c[ 28] ^ emac_this_c[ 29] ^ emac_this_c[ 30] ^ emac_this_c[ 31] ^ emac_this_d[ 62] ^
                 emac_this_d[ 59] ^ emac_this_d[ 58] ^ emac_this_d[ 56] ^ emac_this_d[ 52] ^ emac_this_d[ 44] ^ emac_this_d[ 43] ^
                 emac_this_d[ 42] ^ emac_this_d[ 40] ^ emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 37] ^ emac_this_d[ 36] ^
                 emac_this_d[ 34] ^ emac_this_d[ 31] ^ emac_this_d[ 24] ^ emac_this_d[ 23] ^ emac_this_d[ 21] ^ emac_this_d[ 20] ^
                 emac_this_d[ 18] ^ emac_this_d[ 15] ^ emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[ 10] ^ emac_this_d[  8] ^
                 emac_this_d[  7] ^ emac_this_d[  5] ^ emac_this_d[  3] ^ emac_this_d[  2] ^ emac_this_d[  1] ^ emac_this_d[  0]; 
    emac_next_c[28] = emac_this_c[  1] ^ emac_this_c[  8] ^ emac_this_c[  9] ^ emac_this_c[ 11] ^ emac_this_c[ 12] ^ emac_this_c[ 14] ^
                 emac_this_c[ 17] ^ emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 22] ^ emac_this_c[ 24] ^ emac_this_c[ 25] ^
                 emac_this_c[ 27] ^ emac_this_c[ 29] ^ emac_this_c[ 30] ^ emac_this_c[ 31] ^ emac_this_d[ 61] ^ emac_this_d[ 58] ^
                 emac_this_d[ 57] ^ emac_this_d[ 55] ^ emac_this_d[ 51] ^ emac_this_d[ 43] ^ emac_this_d[ 42] ^ emac_this_d[ 41] ^
                 emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 37] ^ emac_this_d[ 36] ^ emac_this_d[ 35] ^ emac_this_d[ 33] ^
                 emac_this_d[ 30] ^ emac_this_d[ 23] ^ emac_this_d[ 22] ^ emac_this_d[ 20] ^ emac_this_d[ 19] ^ emac_this_d[ 17] ^
                 emac_this_d[ 14] ^ emac_this_d[ 13] ^ emac_this_d[ 12] ^ emac_this_d[  9] ^ emac_this_d[  7] ^ emac_this_d[  6] ^
                 emac_this_d[  4] ^ emac_this_d[  2] ^ emac_this_d[  1] ^ emac_this_d[  0];
    emac_next_c[29] = emac_this_c[  2] ^ emac_this_c[  9] ^ emac_this_c[ 10] ^ emac_this_c[ 12] ^ emac_this_c[ 13] ^ emac_this_c[ 15] ^
                 emac_this_c[ 18] ^ emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 23] ^ emac_this_c[ 25] ^ emac_this_c[ 26] ^
                 emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_c[ 31] ^ emac_this_d[ 60] ^ emac_this_d[ 57] ^ emac_this_d[ 56] ^
                 emac_this_d[ 54] ^ emac_this_d[ 50] ^ emac_this_d[ 42] ^ emac_this_d[ 41] ^ emac_this_d[ 40] ^ emac_this_d[ 38] ^
                 emac_this_d[ 37] ^ emac_this_d[ 36] ^ emac_this_d[ 35] ^ emac_this_d[ 34] ^ emac_this_d[ 32] ^ emac_this_d[ 29] ^
                 emac_this_d[ 22] ^ emac_this_d[ 21] ^ emac_this_d[ 19] ^ emac_this_d[ 18] ^ emac_this_d[ 16] ^ emac_this_d[ 13] ^
                 emac_this_d[ 12] ^ emac_this_d[ 11] ^ emac_this_d[  8] ^ emac_this_d[  6] ^ emac_this_d[  5] ^ emac_this_d[  3] ^
                 emac_this_d[  1] ^ emac_this_d[  0];
    emac_next_c[30] = emac_this_c[  0] ^ emac_this_c[  3] ^ emac_this_c[ 10] ^ emac_this_c[ 11] ^ emac_this_c[ 13] ^ emac_this_c[ 14] ^
                 emac_this_c[ 16] ^ emac_this_c[ 19] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 24] ^ emac_this_c[ 26] ^
                 emac_this_c[ 27] ^ emac_this_c[ 29] ^ emac_this_c[ 31] ^ emac_this_d[ 59] ^ emac_this_d[ 56] ^ emac_this_d[ 55] ^
                 emac_this_d[ 53] ^ emac_this_d[ 49] ^ emac_this_d[ 41] ^ emac_this_d[ 40] ^ emac_this_d[ 39] ^ emac_this_d[ 37] ^
                 emac_this_d[ 36] ^ emac_this_d[ 35] ^ emac_this_d[ 34] ^ emac_this_d[ 33] ^ emac_this_d[ 31] ^ emac_this_d[ 28] ^
                 emac_this_d[ 21] ^ emac_this_d[ 20] ^ emac_this_d[ 18] ^ emac_this_d[ 17] ^ emac_this_d[ 15] ^ emac_this_d[ 12] ^
                 emac_this_d[ 11] ^ emac_this_d[ 10] ^ emac_this_d[  7] ^ emac_this_d[  5] ^ emac_this_d[  4] ^ emac_this_d[  2] ^
                 emac_this_d[  0];
    emac_next_c[31] = emac_this_c[  1] ^ emac_this_c[  4] ^ emac_this_c[ 11] ^ emac_this_c[ 12] ^ emac_this_c[ 14] ^ emac_this_c[ 15] ^
                 emac_this_c[ 17] ^ emac_this_c[ 20] ^ emac_this_c[ 21] ^ emac_this_c[ 22] ^ emac_this_c[ 25] ^ emac_this_c[ 27] ^
                 emac_this_c[ 28] ^ emac_this_c[ 30] ^ emac_this_d[ 58] ^ emac_this_d[ 55] ^ emac_this_d[ 54] ^ emac_this_d[ 52] ^
                 emac_this_d[ 48] ^ emac_this_d[ 40] ^ emac_this_d[ 39] ^ emac_this_d[ 38] ^ emac_this_d[ 36] ^ emac_this_d[ 35] ^
                 emac_this_d[ 34] ^ emac_this_d[ 33] ^ emac_this_d[ 32] ^ emac_this_d[ 30] ^ emac_this_d[ 27] ^ emac_this_d[ 20] ^
                 emac_this_d[ 19] ^ emac_this_d[ 17] ^ emac_this_d[ 16] ^ emac_this_d[ 14] ^ emac_this_d[ 11] ^ emac_this_d[ 10] ^
                 emac_this_d[  9] ^ emac_this_d[  6] ^ emac_this_d[  4] ^ emac_this_d[  3] ^ emac_this_d[  1];

  /* assign crc_result = emac_next_c[15:0]; */
  /* so we walk the lower 16 bytes and pack into 16 bits */
    for(i=0;i<16;i++) 
    {
        res |= (emac_next_c[i] ? (1<<i): 0) ;
    }
    return res;
}



/*************************************************************************************
 * \brief emac_util_fdb_helper: return broad-side slot to use for fdb entry
 *        also return the 8 bit fid to populate as part of the entry
 *
 * \param vlan_table pointer to base of vlan table. 
 * \param vlan_id
 * \param mac 6 byte mac address
 * \param p_fid pointer to uint8_t where we ruturn the fid
 *
   \retval return broad-side slot to use for fdb entry
 * NOTE: only supports the 2048 entry x 4 entries/broadside slot fdb configuration
 **************************************************************************************/
uint16_t emac_util_fdb_helper(uintptr_t vlan_table, uint16_t vlan_id,  uint8_t mac[], uint8_t * p_fid)
{
    uint16_t* pTable = (uint16_t*)vlan_table;
    uint8_t input_64[8];  //64 bit input
    *p_fid = (pTable[vlan_id]&0xff00)>>8;

    /* juggle input be->le */
    input_64[0] = mac[0];
    input_64[1] = mac[1];
    input_64[2] = mac[2];
    input_64[3] = mac[3];
    input_64[4] = mac[4];
    input_64[5] = mac[5];

    input_64[6] = *p_fid;
    input_64[7] = 0x00;
    return (0x1ff&emac_util_crc64(input_64));  
}

/* commands to program ICSSG R30 registers */
static uint32_t emac_R30_bitmask[EMAC_PORT_MAX_COMMANDS][EMAC_MAC_PORTS_PER_ICSS][EMAC_MAX_ICSS-1][3] =
{
    {    /* EMAC_PORT_DISABLE */
        {{0xffff0004, EMAC_NONE, EMAC_NONE}, {EMAC_NONE, 0xffff0100, 0xffff0100}},
        {{EMAC_NONE, 0xffff0100, 0xffff0100}, {0xffff0004, EMAC_NONE, EMAC_NONE}},
    },
    {   /* EMAC_PORT_BLOCK */
        {{0xfffb0040, EMAC_NONE, EMAC_NONE}, {EMAC_NONE, 0xfeff0200, 0xfeff0200}},
        {{EMAC_NONE, 0xfeff0200, 0xfeff0200}, {0xfffb0040, EMAC_NONE, EMAC_NONE}},
    },
    {   /* EMAC_PORT_FORWARD */
        {{0xffbb0000, EMAC_NONE, EMAC_NONE}, {EMAC_NONE, 0xfcff0000, 0xdcff0000}},
        {{EMAC_NONE, 0xfcff0000, 0xdcff0000}, {0xffbb0000, EMAC_NONE, EMAC_NONE}},
    },
    {   /*EMAC_PORT_FORWARD_WO_LEARNING */
        {{0xffbb0000, EMAC_NONE, EMAC_NONE}, {EMAC_NONE, 0xfcff0000, 0xfcff2000}},
        {{EMAC_NONE, 0xfcff0000, 0xfcff2000}, {0xffbb0000, EMAC_NONE, EMAC_NONE}},
    },
    {   /* ACCEPT ALL */
        {{0xffff0001, EMAC_NONE, EMAC_NONE}, {EMAC_NONE, EMAC_NONE, EMAC_NONE}},
        {{EMAC_NONE, EMAC_NONE, EMAC_NONE}, {0xffff0001, EMAC_NONE, EMAC_NONE}},
    },
    {   /* ACCEPT TAGGED */
        {{0xfffe0002, EMAC_NONE, EMAC_NONE}, {EMAC_NONE, EMAC_NONE, EMAC_NONE}},
        {{EMAC_NONE, EMAC_NONE, EMAC_NONE}, {0xfffe0002, EMAC_NONE, EMAC_NONE}},
    },
    {   /*ACCEPT UNTAGGED and PRIO */
        {{0xfffc0000, EMAC_NONE, EMAC_NONE}, {EMAC_NONE, EMAC_NONE, EMAC_NONE}},
        {{EMAC_NONE, EMAC_NONE, EMAC_NONE}, {0xfffc0000, EMAC_NONE, EMAC_NONE}},
    },
    {   /*TAS Trigger List change */
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE }, { EMAC_NONE, 0xffff0020, EMAC_NONE}},
        {{ EMAC_NONE, 0xffff0020, EMAC_NONE}, { EMAC_NONE, EMAC_NONE, EMAC_NONE }},
    },
    {   /*TAS set state ENABLE*/
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE }, { EMAC_NONE, 0xdfff1000, EMAC_NONE}},
        {{ EMAC_NONE, 0xdfff1000, EMAC_NONE}, { EMAC_NONE, EMAC_NONE, EMAC_NONE }},
    },
    {   /*TAS set state RESET*/
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE }, { EMAC_NONE, 0xefff2000, EMAC_NONE}},
        {{ EMAC_NONE, 0xefff2000, EMAC_NONE}, { EMAC_NONE, EMAC_NONE, EMAC_NONE }},
    },
    {   /*TAS set state DISABLE*/
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE }, { EMAC_NONE, 0xcfff0000, EMAC_NONE}},
        {{ EMAC_NONE, 0xcfff0000, EMAC_NONE}, { EMAC_NONE, EMAC_NONE, EMAC_NONE }},
    },
    {   /*UC flooding ENABLE*/
        {{ EMAC_NONE, EMAC_NONE, 0xffff0400}, { EMAC_NONE, EMAC_NONE, EMAC_NONE}},
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE},  { EMAC_NONE, EMAC_NONE, 0xffff0400}},
    },
    {   /*UC flooding DISABLE*/
        {{ EMAC_NONE, EMAC_NONE, 0xfbff0000}, { EMAC_NONE, EMAC_NONE, EMAC_NONE}},
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE }, { EMAC_NONE, EMAC_NONE, 0xfbff0000}},
    },
    {   /*Premption on Tx ENABLE*/
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE}, { EMAC_NONE, 0xffff4000, EMAC_NONE}},
        {{ EMAC_NONE, 0xffff4000, EMAC_NONE},  { EMAC_NONE, EMAC_NONE, EMAC_NONE}},
    },
    {   /*Premption on Tx DISABLE*/
        {{ EMAC_NONE, EMAC_NONE, EMAC_NONE}, { EMAC_NONE, 0xbfff0000, EMAC_NONE}},
        {{ EMAC_NONE, 0xbfff0000, EMAC_NONE }, { EMAC_NONE, EMAC_NONE, EMAC_NONE}},
    },
};

/* utility to return command to be sent to FW over PSI management interface */
uint32_t *emac_util_get_R30_info(EMAC_IOctlR30Cmd cmd, uint32_t port, EMAC_IcssgInstance icssg)
{
    return emac_R30_bitmask[cmd][port][icssg];
}

/*
 *  ======== emac_hw_mem_write ========
 */
void emac_hw_mem_write(uint32_t addr, const void *ptr, uint32_t element_count)
{
    uint32_t  i;
    volatile uint32_t *dst = (volatile uint32_t *)(uintptr_t)addr;
    uint32_t *src = (uint32_t *)ptr;
    for (i = 0; i < element_count; i++)
    {
        *dst++ = *src++;
    }
}

