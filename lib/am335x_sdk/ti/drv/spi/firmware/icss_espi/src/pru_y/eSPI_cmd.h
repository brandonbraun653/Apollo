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
; file:   eSPI_cmd.h
;
; brief:  This files contains the CMD subroutine jump locations
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;

	.if    !$defined("__eSPI_cmd_h")
__eSPI_cmd_h    .set 1

;;; INCLUDES ;;;
	.include "eSPI_pru_y_defines.h"

;;; GLOBAL DEFINES ;;;
	.global PUT_PC
	.global PUT_NP
	.global GET_PC
	.global GET_NP
	.global PUT_IORD_SHORT_1
	.global PUT_IORD_SHORT_2
	.global PUT_IORD_SHORT_4
	.global PUT_IOWR_SHORT_1
	.global PUT_IOWR_SHORT_2
	.global PUT_IOWR_SHORT_4
	.global PUT_MEMRD32_SHORT_1
	.global PUT_MEMRD32_SHORT_2
	.global PUT_MEMRD32_SHORT_4
	.global PUT_MEMWR32_SHORT_1
	.global PUT_MEMWR32_SHORT_2
	.global PUT_MEMWR32_SHORT_4
	.global PUT_VWIRE
	.global GET_VWIRE
	.global PUT_OOB
	.global GET_OOB
	.global PUT_FLASH_C
	.global GET_FLASH_NP
	.global GET_STATUS
	.global SET_CONFIGURATION
	.global GET_CONFIGURATION
	.global RESET
	.global NO_RESPONSE

;;; MACROS ;;;
;-------------------------------------------------------------------
; Macro Name: INIT_CMD_TABLE
; Description: set up the global CMD table register
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
INIT_CMD_TABLE	.macro
	LDI	r_CmdTableBase,	||espi_cmd_table||
	.endm


;;; DATA ;;;
;-------------------------------------------------------------------
; Table Name: espi_cmd_table
; Description: CMD jump locaitons (addressable labels)
;-------------------------------------------------------------------
	.data
	.align  2
||espi_cmd_table||:
	.uhalf   $CODE(PUT_PC)	              ; espi_cmd_table[0x0] 
	.uhalf   $CODE(GET_PC)                ; espi_cmd_table[0x1] 
	.uhalf   $CODE(PUT_NP)                ; espi_cmd_table[0x2] 
	.uhalf   $CODE(GET_NP)                ; espi_cmd_table[0x3] 
	.uhalf   $CODE(PUT_VWIRE)             ; espi_cmd_table[0x4] 
	.uhalf   $CODE(GET_VWIRE)             ; espi_cmd_table[0x5] 
	.uhalf   $CODE(PUT_OOB)               ; espi_cmd_table[0x6] 
	.uhalf   $CODE(GET_OOB)               ; espi_cmd_table[0x7] 
	.uhalf   $CODE(PUT_FLASH_C)           ; espi_cmd_table[0x8] 
	.uhalf   $CODE(GET_FLASH_NP)          ; espi_cmd_table[0x9] 
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa] 
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb] 
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc] 
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd] 
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe] 
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf] 
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x10]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x11]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x12]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x13]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x14]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x15]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x16]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x17]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x18]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x19]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x1a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x1b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x1c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x1d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x1e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x1f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x20]
	.uhalf   $CODE(GET_CONFIGURATION)     ; espi_cmd_table[0x21]
	.uhalf   $CODE(SET_CONFIGURATION)     ; espi_cmd_table[0x22]
	.uhalf   $CODE(NO_RESPONSE)            ; espi_cmd_table[0x23]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x24]
	.uhalf   $CODE(GET_STATUS)           ; espi_cmd_table[0x25]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x26]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x27]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x28]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x29]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x2a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x2b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x2c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x2d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x2e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x2f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x30]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x31]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x32]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x33]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x34]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x35]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x36]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x37]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x38]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x39]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x3a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x3b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x3c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x3d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x3e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x3f]
	.uhalf   $CODE(PUT_IORD_SHORT_1)      ; espi_cmd_table[0x40]
	.uhalf   $CODE(PUT_IORD_SHORT_2)      ; espi_cmd_table[0x41]
	.uhalf   $CODE(NO_RESPONSE)	      ; espi_cmd_table[0x42]
	.uhalf   $CODE(PUT_IORD_SHORT_4)      ; espi_cmd_table[0x43]
	.uhalf   $CODE(PUT_IOWR_SHORT_1)      ; espi_cmd_table[0x44]
	.uhalf   $CODE(PUT_IOWR_SHORT_2)      ; espi_cmd_table[0x45]
	.uhalf   $CODE(NO_RESPONSE)	      ; espi_cmd_table[0x46]
	.uhalf   $CODE(PUT_IOWR_SHORT_4)      ; espi_cmd_table[0x47]
	.uhalf   $CODE(PUT_MEMRD32_SHORT_1)   ; espi_cmd_table[0x48]
	.uhalf   $CODE(PUT_MEMRD32_SHORT_2)   ; espi_cmd_table[0x49]
	.uhalf   $CODE(NO_RESPONSE)	      ; espi_cmd_table[0x4a]
	.uhalf   $CODE(PUT_MEMRD32_SHORT_4)   ; espi_cmd_table[0x4b]
	.uhalf   $CODE(PUT_MEMWR32_SHORT_1)   ; espi_cmd_table[0x4c]
	.uhalf   $CODE(PUT_MEMWR32_SHORT_2)   ; espi_cmd_table[0x4d]
	.uhalf   $CODE(NO_RESPONSE)	      ; espi_cmd_table[0x4e]
	.uhalf   $CODE(PUT_MEMWR32_SHORT_4)   ; espi_cmd_table[0x4f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x50]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x51]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x52]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x53]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x54]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x55]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x56]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x57]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x58]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x59]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x5a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x5b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x5c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x5d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x5e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x5f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x60]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x61]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x62]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x63]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x64]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x65]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x66]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x67]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x68]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x69]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x6a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x6b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x6c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x6d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x6e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x6f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x70]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x71]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x72]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x73]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x74]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x75]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x76]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x77]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x78]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x79]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x7a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x7b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x7c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x7d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x7e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x7f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x80]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x81]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x82]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x83]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x84]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x85]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x86]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x87]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x88]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x89]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x8a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x8b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x8c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x8d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x8e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x8f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x90]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x91]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x92]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x93]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x94]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x95]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x96]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x97]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x98]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x99]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x9a]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x9b]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x9c]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x9d]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x9e]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0x9f]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa0]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa1]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa2]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa3]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa4]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa5]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa6]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa7]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa8]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xa9]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xaa]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xab]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xac]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xad]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xae]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xaf]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb0]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb1]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb2]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb3]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb4]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb5]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb6]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb7]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb8]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xb9]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xba]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xbb]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xbc]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xbd]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xbe]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xbf]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc0]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc1]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc2]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc3]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc4]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc5]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc6]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc7]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc8]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xc9]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xca]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xcb]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xcc]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xcd]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xce]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xcf]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd0]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd1]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd2]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd3]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd4]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd5]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd6]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd7]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd8]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xd9]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xda]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xdb]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xdc]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xdd]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xde]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xdf]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe0]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe1]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe2]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe3]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe4]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe5]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe6]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe7]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe8]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xe9]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xea]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xeb]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xec]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xed]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xee]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xef]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf0]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf1]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf2]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf3]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf4]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf5]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf6]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf7]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf8]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xf9]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xfa]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xfb]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xfc]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xfd]
	.uhalf   $CODE(NO_RESPONSE)           ; espi_cmd_table[0xfe]
	.uhalf   $CODE(RESET)                 ; espi_cmd_table[0xff]
	
	.endif  ;__eSPI_cmd_h
