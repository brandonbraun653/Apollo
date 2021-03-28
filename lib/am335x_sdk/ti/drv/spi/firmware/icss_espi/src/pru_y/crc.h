;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
; 
;  Copyright (c) 2018 Texas Instruments Incorporated
; 
;  All rights reserved not granted herein.
;  
;  Limited License.  
; 
;  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive 
;  license under copyrights and patents it now or hereafter owns or controls to 
;  make, have made, use, import, offer to sell and sell ("Utilize") this software 
;  subject to the terms herein.  With respect to the foregoing patent license, 
;  such license is granted  solely to the extent that any such patent is necessary 
;  to Utilize the software alone.  The patent license shall not apply to any 
;  combinations which include this software, other than combinations with devices 
;  manufactured by or for TI ("TI Devices").  No hardware patent is licensed hereunder.
; 
;  Redistributions must preserve existing copyright notices and reproduce this license 
;  (including the above copyright notice and the disclaimer and (if applicable) source 
;  code license limitations below) in the documentation and/or other materials provided 
;  with the distribution.
;  
;  Redistribution and use in binary form, without modification, are permitted provided 
;  that the following conditions are met:
;  No reverse engineering, decompilation, or disassembly of this software is 
;  permitted with respect to any software provided in binary form.
;  Any redistribution and use are licensed by TI for use only with TI Devices.
;  Nothing shall obligate TI to provide you with source code for the software 
;  licensed and provided to you in object code.
;  
;  If software source code is provided to you, modification and redistribution of the 
;  source code are permitted provided that the following conditions are met:
;  Any redistribution and use of the source code, including any resulting derivative 
;  works, are licensed by TI for use only with TI Devices.
;  Any redistribution and use of any object code compiled from the source code
;  and any resulting derivative works, are licensed by TI for use only with TI Devices.
; 
;  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
;  may be used to endorse or promote products derived from this software without 
;  specific prior written permission.
; 
;  DISCLAIMER.
; 
;  THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   eSPI_cmd_table.h
;
; brief:  This files contains the CMD subroutine jump locations
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
				;

	.if    !$defined("__crc_h")
__crc_h    .set 1

;;; INCLUDES ;;;
	.include "eSPI_pru_y_defines.h"

;;; GLOBAL REFS ;;;
	.global ERROR_CRC_MISMATCH

;;; MACROS ;;;
;-------------------------------------------------------------------
; Macro Name: INIT_CRC_TABLE
; Description: set up the global CRC table register
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
INIT_CRC_TABLE	.macro
	LDI	r_CrcTableBase,	||crc_table||
	.endm

;-------------------------------------------------------------------
; Macro Name: CLEAR_CRC
; Description: clear the CRC register
; Input Parameters: Local CRC register
; Output Parameters: none
;-------------------------------------------------------------------
CLEAR_CRC	.macro	CrcCalc
	LDI	CrcCalc,	0x00
	.endm

;-------------------------------------------------------------------
; Macro Name: INIT_CRC
; Description: set up the local CRC register with first CRC byte
; Input Parameters: Local CRC register
; Output Parameters: none
;-------------------------------------------------------------------
INIT_CRC	.macro	CrcCalc, FirstByte
	LBBO	&CrcCalc, r_CrcTableBase, FirstByte, 1
	.endm
	
;-------------------------------------------------------------------
; Macro Name: CALC_CRC_BYTE
; Description: calculate next CRC byte
; Input Parameters: CRC calculation byte up to this point
; Input Parameters: next byte to add to CRC
; Output Parameters: none
;-------------------------------------------------------------------
    .sslist
CALC_CRC_BYTE	.macro	CrcCalc, Byte
	XOR	CrcCalc, CrcCalc, Byte
	LBBO	&CrcCalc, r_CrcTableBase, CrcCalc, 1
	.endm

;-------------------------------------------------------------------
; Macro Name: CHECK_CRC
; Description: make sure the CRC is valid
; Input Parameters: CRC calculation byte up to this point
; Input Parameters: CRC as read from the Master
; Output Parameters: none
;-------------------------------------------------------------------
CHECK_CRC   .macro  CrcCalc, CrcRead
   QBBC	   end?, r_GeneralCapCon, GENERAL_CAP_CON_CRC_CHECKING_ENABLE_OFFSET
   QBNE    ERROR_CRC_MISMATCH, CrcCalc, CrcRead
end?:
    .endm

;;; DATA ;;;
;-------------------------------------------------------------------
; Table Name: crc_table
; Description: Pre-calculated CRC xor values (polynomial: 0x07, seed: 0x00)
;-------------------------------------------------------------------
	.data
	.align  1
||crc_table||:
       .byte   0x0             ; crc_table[0]
       .byte   0x7             ; crc_table[1]
       .byte   0xe             ; crc_table[2]
       .byte   0x9             ; crc_table[3]
       .byte   0x1c            ; crc_table[4]
       .byte   0x1b            ; crc_table[5]
       .byte   0x12            ; crc_table[6]
       .byte   0x15            ; crc_table[7]
       .byte   0x38            ; crc_table[8]
       .byte   0x3f            ; crc_table[9]
       .byte   0x36            ; crc_table[10]
       .byte   0x31            ; crc_table[11]
       .byte   0x24            ; crc_table[12]
       .byte   0x23            ; crc_table[13]
       .byte   0x2a            ; crc_table[14]
       .byte   0x2d            ; crc_table[15]
       .byte   0x70            ; crc_table[16]
       .byte   0x77            ; crc_table[17]
       .byte   0x7e            ; crc_table[18]
       .byte   0x79            ; crc_table[19]
       .byte   0x6c            ; crc_table[20]
       .byte   0x6b            ; crc_table[21]
       .byte   0x62            ; crc_table[22]
       .byte   0x65            ; crc_table[23]
       .byte   0x48            ; crc_table[24]
       .byte   0x4f            ; crc_table[25]
       .byte   0x46            ; crc_table[26]
       .byte   0x41            ; crc_table[27]
       .byte   0x54            ; crc_table[28]
       .byte   0x53            ; crc_table[29]
       .byte   0x5a            ; crc_table[30]
       .byte   0x5d            ; crc_table[31]
       .byte   0xe0            ; crc_table[32]
       .byte   0xe7            ; crc_table[33]
       .byte   0xee            ; crc_table[34]
       .byte   0xe9            ; crc_table[35]
       .byte   0xfc            ; crc_table[36]
       .byte   0xfb            ; crc_table[37]
       .byte   0xf2            ; crc_table[38]
       .byte   0xf5            ; crc_table[39]
       .byte   0xd8            ; crc_table[40]
       .byte   0xdf            ; crc_table[41]
       .byte   0xd6            ; crc_table[42]
       .byte   0xd1            ; crc_table[43]
       .byte   0xc4            ; crc_table[44]
       .byte   0xc3            ; crc_table[45]
       .byte   0xca            ; crc_table[46]
       .byte   0xcd            ; crc_table[47]
       .byte   0x90            ; crc_table[48]
       .byte   0x97            ; crc_table[49]
       .byte   0x9e            ; crc_table[50]
       .byte   0x99            ; crc_table[51]
       .byte   0x8c            ; crc_table[52]
       .byte   0x8b            ; crc_table[53]
       .byte   0x82            ; crc_table[54]
       .byte   0x85            ; crc_table[55]
       .byte   0xa8            ; crc_table[56]
       .byte   0xaf            ; crc_table[57]
       .byte   0xa6            ; crc_table[58]
       .byte   0xa1            ; crc_table[59]
       .byte   0xb4            ; crc_table[60]
       .byte   0xb3            ; crc_table[61]
       .byte   0xba            ; crc_table[62]
       .byte   0xbd            ; crc_table[63]
       .byte   0xc7            ; crc_table[64]
       .byte   0xc0            ; crc_table[65]
       .byte   0xc9            ; crc_table[66]
       .byte   0xce            ; crc_table[67]
       .byte   0xdb            ; crc_table[68]
       .byte   0xdc            ; crc_table[69]
       .byte   0xd5            ; crc_table[70]
       .byte   0xd2            ; crc_table[71]
       .byte   0xff            ; crc_table[72]
       .byte   0xf8            ; crc_table[73]
       .byte   0xf1            ; crc_table[74]
       .byte   0xf6            ; crc_table[75]
       .byte   0xe3            ; crc_table[76]
       .byte   0xe4            ; crc_table[77]
       .byte   0xed            ; crc_table[78]
       .byte   0xea            ; crc_table[79]
       .byte   0xb7            ; crc_table[80]
       .byte   0xb0            ; crc_table[81]
       .byte   0xb9            ; crc_table[82]
       .byte   0xbe            ; crc_table[83]
       .byte   0xab            ; crc_table[84]
       .byte   0xac            ; crc_table[85]
       .byte   0xa5            ; crc_table[86]
       .byte   0xa2            ; crc_table[87]
       .byte   0x8f            ; crc_table[88]
       .byte   0x88            ; crc_table[89]
       .byte   0x81            ; crc_table[90]
       .byte   0x86            ; crc_table[91]
       .byte   0x93            ; crc_table[92]
       .byte   0x94            ; crc_table[93]
       .byte   0x9d            ; crc_table[94]
       .byte   0x9a            ; crc_table[95]
       .byte   0x27            ; crc_table[96]
       .byte   0x20            ; crc_table[97]
       .byte   0x29            ; crc_table[98]
       .byte   0x2e            ; crc_table[99]
       .byte   0x3b            ; crc_table[100]
       .byte   0x3c            ; crc_table[101]
       .byte   0x35            ; crc_table[102]
       .byte   0x32            ; crc_table[103]
       .byte   0x1f            ; crc_table[104]
       .byte   0x18            ; crc_table[105]
       .byte   0x11            ; crc_table[106]
       .byte   0x16            ; crc_table[107]
       .byte   0x3             ; crc_table[108]
       .byte   0x4             ; crc_table[109]
       .byte   0xd             ; crc_table[110]
       .byte   0xa             ; crc_table[111]
       .byte   0x57            ; crc_table[112]
       .byte   0x50            ; crc_table[113]
       .byte   0x59            ; crc_table[114]
       .byte   0x5e            ; crc_table[115]
       .byte   0x4b            ; crc_table[116]
       .byte   0x4c            ; crc_table[117]
       .byte   0x45            ; crc_table[118]
       .byte   0x42            ; crc_table[119]
       .byte   0x6f            ; crc_table[120]
       .byte   0x68            ; crc_table[121]
       .byte   0x61            ; crc_table[122]
       .byte   0x66            ; crc_table[123]
       .byte   0x73            ; crc_table[124]
       .byte   0x74            ; crc_table[125]
       .byte   0x7d            ; crc_table[126]
       .byte   0x7a            ; crc_table[127]
       .byte   0x89            ; crc_table[128]
       .byte   0x8e            ; crc_table[129]
       .byte   0x87            ; crc_table[130]
       .byte   0x80            ; crc_table[131]
       .byte   0x95            ; crc_table[132]
       .byte   0x92            ; crc_table[133]
       .byte   0x9b            ; crc_table[134]
       .byte   0x9c            ; crc_table[135]
       .byte   0xb1            ; crc_table[136]
       .byte   0xb6            ; crc_table[137]
       .byte   0xbf            ; crc_table[138]
       .byte   0xb8            ; crc_table[139]
       .byte   0xad            ; crc_table[140]
       .byte   0xaa            ; crc_table[141]
       .byte   0xa3            ; crc_table[142]
       .byte   0xa4            ; crc_table[143]
       .byte   0xf9            ; crc_table[144]
       .byte   0xfe            ; crc_table[145]
       .byte   0xf7            ; crc_table[146]
       .byte   0xf0            ; crc_table[147]
       .byte   0xe5            ; crc_table[148]
       .byte   0xe2            ; crc_table[149]
       .byte   0xeb            ; crc_table[150]
       .byte   0xec            ; crc_table[151]
       .byte   0xc1            ; crc_table[152]
       .byte   0xc6            ; crc_table[153]
       .byte   0xcf            ; crc_table[154]
       .byte   0xc8            ; crc_table[155]
       .byte   0xdd            ; crc_table[156]
       .byte   0xda            ; crc_table[157]
       .byte   0xd3            ; crc_table[158]
       .byte   0xd4            ; crc_table[159]
       .byte   0x69            ; crc_table[160]
       .byte   0x6e            ; crc_table[161]
       .byte   0x67            ; crc_table[162]
       .byte   0x60            ; crc_table[163]
       .byte   0x75            ; crc_table[164]
       .byte   0x72            ; crc_table[165]
       .byte   0x7b            ; crc_table[166]
       .byte   0x7c            ; crc_table[167]
       .byte   0x51            ; crc_table[168]
       .byte   0x56            ; crc_table[169]
       .byte   0x5f            ; crc_table[170]
       .byte   0x58            ; crc_table[171]
       .byte   0x4d            ; crc_table[172]
       .byte   0x4a            ; crc_table[173]
       .byte   0x43            ; crc_table[174]
       .byte   0x44            ; crc_table[175]
       .byte   0x19            ; crc_table[176]
       .byte   0x1e            ; crc_table[177]
       .byte   0x17            ; crc_table[178]
       .byte   0x10            ; crc_table[179]
       .byte   0x5             ; crc_table[180]
       .byte   0x2             ; crc_table[181]
       .byte   0xb             ; crc_table[182]
       .byte   0xc             ; crc_table[183]
       .byte   0x21            ; crc_table[184]
       .byte   0x26            ; crc_table[185]
       .byte   0x2f            ; crc_table[186]
       .byte   0x28            ; crc_table[187]
       .byte   0x3d            ; crc_table[188]
       .byte   0x3a            ; crc_table[189]
       .byte   0x33            ; crc_table[190]
       .byte   0x34            ; crc_table[191]
       .byte   0x4e            ; crc_table[192]
       .byte   0x49            ; crc_table[193]
       .byte   0x40            ; crc_table[194]
       .byte   0x47            ; crc_table[195]
       .byte   0x52            ; crc_table[196]
       .byte   0x55            ; crc_table[197]
       .byte   0x5c            ; crc_table[198]
       .byte   0x5b            ; crc_table[199]
       .byte   0x76            ; crc_table[200]
       .byte   0x71            ; crc_table[201]
       .byte   0x78            ; crc_table[202]
       .byte   0x7f            ; crc_table[203]
       .byte   0x6a            ; crc_table[204]
       .byte   0x6d            ; crc_table[205]
       .byte   0x64            ; crc_table[206]
       .byte   0x63            ; crc_table[207]
       .byte   0x3e            ; crc_table[208]
       .byte   0x39            ; crc_table[209]
       .byte   0x30            ; crc_table[210]
       .byte   0x37            ; crc_table[211]
       .byte   0x22            ; crc_table[212]
       .byte   0x25            ; crc_table[213]
       .byte   0x2c            ; crc_table[214]
       .byte   0x2b            ; crc_table[215]
       .byte   0x6             ; crc_table[216]
       .byte   0x1             ; crc_table[217]
       .byte   0x8             ; crc_table[218]
       .byte   0xf             ; crc_table[219]
       .byte   0x1a            ; crc_table[220]
       .byte   0x1d            ; crc_table[221]
       .byte   0x14            ; crc_table[222]
       .byte   0x13            ; crc_table[223]
       .byte   0xae            ; crc_table[224]
       .byte   0xa9            ; crc_table[225]
       .byte   0xa0            ; crc_table[226]
       .byte   0xa7            ; crc_table[227]
       .byte   0xb2            ; crc_table[228]
       .byte   0xb5            ; crc_table[229]
       .byte   0xbc            ; crc_table[230]
       .byte   0xbb            ; crc_table[231]
       .byte   0x96            ; crc_table[232]
       .byte   0x91            ; crc_table[233]
       .byte   0x98            ; crc_table[234]
       .byte   0x9f            ; crc_table[235]
       .byte   0x8a            ; crc_table[236]
       .byte   0x8d            ; crc_table[237]
       .byte   0x84            ; crc_table[238]
       .byte   0x83            ; crc_table[239]
       .byte   0xde            ; crc_table[240]
       .byte   0xd9            ; crc_table[241]
       .byte   0xd0            ; crc_table[242]
       .byte   0xd7            ; crc_table[243]
       .byte   0xc2            ; crc_table[244]
       .byte   0xc5            ; crc_table[245]
       .byte   0xcc            ; crc_table[246]
       .byte   0xcb            ; crc_table[247]
       .byte   0xe6            ; crc_table[248]
       .byte   0xe1            ; crc_table[249]
       .byte   0xe8            ; crc_table[250]
       .byte   0xef            ; crc_table[251]
       .byte   0xfa            ; crc_table[252]
       .byte   0xfd            ; crc_table[253]
       .byte   0xf4            ; crc_table[254]
       .byte   0xf3            ; crc_table[255]

    .endif  ; __crc_h
