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
;  manufactured by or for TI (" Devices”)"No hardware patent is licensed hereunder.
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
;  THIS SOFTWARE IS PROVIDED BY TI AND TI'LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   eSPI_slave_registers.h
;
; brief:  This files contains the slave register table with default values
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;

	.if    !$defined("__eSPI_slave_registers_h")
__eSPI_slave_registers_h    .set 1

;;; INCLUDES ;;;
	.include "eSPI_pru_y_defines.h"

;;; MACROS ;;;
;-------------------------------------------------------------------
; Macro Name: INIT_SHARED_MEMORY
; Description: set up the shared memory address register
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
INIT_SHARED_MEMORY	.macro
	LDI32	r_SharedMemoryBase, g_SharedMemoryBaseAddr
	.endm
	
;-------------------------------------------------------------------
; Macro Name: RESET_SLAVE_REGISTERS
; Description: reset slave registers to default values
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
RESET_SLAVE_REGISTERS	.macro
	;; See icss_espi.h for slave register descriptions
	LDI32	r_Work0, 0x00000001 ; Device ID
	LDI32	r_Work1, 0x13000001 ; General Capabilities and Configurations
	LDI32	r_Work2, 0x00001111 ; Channel 0 Capabilities and Configurations
	LDI32	r_Work3, 0x00000000 ; Channel 1 Capabilities and Configurations
	LDI32	r_Work4, 0x00000110 ; Channel 2 Capabilities and Configurations
	LDI32	r_Work5, 0x00001124 ; Channel 3 Capabilities and Configurations
	SBBO	&r_Work0, r_SharedMemoryBase, ICSS_ESPI_SLAVE_REGISTERS_BASE, 24

	;; Set local slave regs
	MOV	r_DeviceId, r_Work0
	MOV	r_GeneralCapCon, r_Work1
	MOV	r_Ch0CapCon, r_Work2
	.endm

;-------------------------------------------------------------------
; Macro Name: RESET_STATUS_REGISTER
; Description: reset status register to default values
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
RESET_STATUS_REGISTER	.macro
	LDI32	r_Work0, g_DefaultStatusRegVal ; Status Register
	SBBO	&r_Work0, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	.endm

;-------------------------------------------------------------------
; Macro Name: RESET_INTERNAL_SLAVE_REGISTERS
; Description: reset internal slave registers to default values
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
RESET_INTERNAL_SLAVE_REGISTERS	.macro
	LDI32	r_Work0, 0x00000000 ; Internal Status Register
	LDI32	r_Work1, 0x00000000 ; IPC Register
	SBBO	&r_Work0, r_SharedMemoryBase, ICSS_ESPI_INTERNAL_SLAVE_REGISTERS_BASE, 8
	.endm
	

;;; DATA ;;;
;-------------------------------------------------------------------
; Table Name: espi_slave_registers
; Description: All slave register memory with explicity defined default values
;-------------------------------------------------------------------
 	;; .data
;; 	.align  1
;; ||espi_slave_registers||:
;; 	.uint	0x00000000		; 0x000 RESERVED
;; 	.uint	0x00000000		; 0x004 Device Identification
;; 	.uint	0x13000001		; 0x008 General Capabilities and Configurations
;; 	.uint	0x00000000		; 0x00C RESERVED
;; 	.uint	0x00001111		; 0x010 Channel 0 Capabilities and Configurations
;; 	.uint	0x00000000		; 0x014 RESERVED
;; 	.uint	0x00000000		; 0x018 RESERVED
;; 	.uint	0x00000000		; 0x01C RESERVED
;; 	.uint	0x00000000		; 0x020 Channel 1 Capabilities and Configurations
;; 	.uint	0x00000000		; 0x024 RESERVED
;; 	.uint	0x00000000		; 0x028 RESERVED
;; 	.uint	0x00000000		; 0x02C RESERVED
;; 	.uint	0x00000100		; 0x030 Channel 2 Capabilities and Configurations
;; 	.uint	0x00000000		; 0x034 RESERVED
;; 	.uint	0x00000000		; 0x038 RESERVED
;; 	.uint	0x00000000		; 0x03C RESERVED
;; 	.uint	0x00001104		; 0x040 Channel 3 Capabilities and Configurations
;; 	.uint	0x00000000		; 0x044 RESERVED
;; 	.uint	0x00000000		; 0x048 RESERVED
;; 	.uint	0x00000000		; 0x04C RESERVED
;; 	.uint	0x00000000		; 0x050 RESERVED
;; 	;; .uint   0x00000000              ; 0x054 RESERVED
;; 	;; .uint   0x00000000              ; 0x058 RESERVED
;; 	;; .uint   0x00000000              ; 0x05c RESERVED
;; 	;; .uint   0x00000000              ; 0x060 RESERVED
;; 	;; .uint   0x00000000              ; 0x064 RESERVED
;; 	;; .uint   0x00000000              ; 0x068 RESERVED
;; 	;; .uint   0x00000000              ; 0x06c RESERVED
;; 	;; .uint   0x00000000              ; 0x070 RESERVED
;; 	;; .uint   0x00000000              ; 0x074 RESERVED
;; 	;; .uint   0x00000000              ; 0x078 RESERVED
;; 	;; .uint   0x00000000              ; 0x07c RESERVED
;; 	;; .uint   0x00000000              ; 0x080 RESERVED
;; 	;; .uint   0x00000000              ; 0x084 RESERVED
;; 	;; .uint   0x00000000              ; 0x088 RESERVED
;; 	;; .uint   0x00000000              ; 0x08c RESERVED
;; 	;; .uint   0x00000000              ; 0x090 RESERVED
;; 	;; .uint   0x00000000              ; 0x094 RESERVED
;; 	;; .uint   0x00000000              ; 0x098 RESERVED
;; 	;; .uint   0x00000000              ; 0x09c RESERVED
;; 	;; .uint   0x00000000              ; 0x0a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x0a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x0a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x0ac RESERVED
;; 	;; .uint   0x00000000              ; 0x0b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x0b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x0b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x0bc RESERVED
;; 	;; .uint   0x00000000              ; 0x0c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x0c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x0c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x0cc RESERVED
;; 	;; .uint   0x00000000              ; 0x0d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x0d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x0d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x0dc RESERVED
;; 	;; .uint   0x00000000              ; 0x0e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x0e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x0e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x0ec RESERVED
;; 	;; .uint   0x00000000              ; 0x0f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x0f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x0f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x0fc RESERVED
;; 	;; .uint   0x00000000              ; 0x100 RESERVED
;; 	;; .uint   0x00000000              ; 0x104 RESERVED
;; 	;; .uint   0x00000000              ; 0x108 RESERVED
;; 	;; .uint   0x00000000              ; 0x10c RESERVED
;; 	;; .uint   0x00000000              ; 0x110 RESERVED
;; 	;; .uint   0x00000000              ; 0x114 RESERVED
;; 	;; .uint   0x00000000              ; 0x118 RESERVED
;; 	;; .uint   0x00000000              ; 0x11c RESERVED
;; 	;; .uint   0x00000000              ; 0x120 RESERVED
;; 	;; .uint   0x00000000              ; 0x124 RESERVED
;; 	;; .uint   0x00000000              ; 0x128 RESERVED
;; 	;; .uint   0x00000000              ; 0x12c RESERVED
;; 	;; .uint   0x00000000              ; 0x130 RESERVED
;; 	;; .uint   0x00000000              ; 0x134 RESERVED
;; 	;; .uint   0x00000000              ; 0x138 RESERVED
;; 	;; .uint   0x00000000              ; 0x13c RESERVED
;; 	;; .uint   0x00000000              ; 0x140 RESERVED
;; 	;; .uint   0x00000000              ; 0x144 RESERVED
;; 	;; .uint   0x00000000              ; 0x148 RESERVED
;; 	;; .uint   0x00000000              ; 0x14c RESERVED
;; 	;; .uint   0x00000000              ; 0x150 RESERVED
;; 	;; .uint   0x00000000              ; 0x154 RESERVED
;; 	;; .uint   0x00000000              ; 0x158 RESERVED
;; 	;; .uint   0x00000000              ; 0x15c RESERVED
;; 	;; .uint   0x00000000              ; 0x160 RESERVED
;; 	;; .uint   0x00000000              ; 0x164 RESERVED
;; 	;; .uint   0x00000000              ; 0x168 RESERVED
;; 	;; .uint   0x00000000              ; 0x16c RESERVED
;; 	;; .uint   0x00000000              ; 0x170 RESERVED
;; 	;; .uint   0x00000000              ; 0x174 RESERVED
;; 	;; .uint   0x00000000              ; 0x178 RESERVED
;; 	;; .uint   0x00000000              ; 0x17c RESERVED
;; 	;; .uint   0x00000000              ; 0x180 RESERVED
;; 	;; .uint   0x00000000              ; 0x184 RESERVED
;; 	;; .uint   0x00000000              ; 0x188 RESERVED
;; 	;; .uint   0x00000000              ; 0x18c RESERVED
;; 	;; .uint   0x00000000              ; 0x190 RESERVED
;; 	;; .uint   0x00000000              ; 0x194 RESERVED
;; 	;; .uint   0x00000000              ; 0x198 RESERVED
;; 	;; .uint   0x00000000              ; 0x19c RESERVED
;; 	;; .uint   0x00000000              ; 0x1a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x1a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x1a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x1ac RESERVED
;; 	;; .uint   0x00000000              ; 0x1b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x1b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x1b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x1bc RESERVED
;; 	;; .uint   0x00000000              ; 0x1c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x1c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x1c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x1cc RESERVED
;; 	;; .uint   0x00000000              ; 0x1d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x1d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x1d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x1dc RESERVED
;; 	;; .uint   0x00000000              ; 0x1e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x1e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x1e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x1ec RESERVED
;; 	;; .uint   0x00000000              ; 0x1f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x1f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x1f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x1fc RESERVED
;; 	;; .uint   0x00000000              ; 0x200 RESERVED
;; 	;; .uint   0x00000000              ; 0x204 RESERVED
;; 	;; .uint   0x00000000              ; 0x208 RESERVED
;; 	;; .uint   0x00000000              ; 0x20c RESERVED
;; 	;; .uint   0x00000000              ; 0x210 RESERVED
;; 	;; .uint   0x00000000              ; 0x214 RESERVED
;; 	;; .uint   0x00000000              ; 0x218 RESERVED
;; 	;; .uint   0x00000000              ; 0x21c RESERVED
;; 	;; .uint   0x00000000              ; 0x220 RESERVED
;; 	;; .uint   0x00000000              ; 0x224 RESERVED
;; 	;; .uint   0x00000000              ; 0x228 RESERVED
;; 	;; .uint   0x00000000              ; 0x22c RESERVED
;; 	;; .uint   0x00000000              ; 0x230 RESERVED
;; 	;; .uint   0x00000000              ; 0x234 RESERVED
;; 	;; .uint   0x00000000              ; 0x238 RESERVED
;; 	;; .uint   0x00000000              ; 0x23c RESERVED
;; 	;; .uint   0x00000000              ; 0x240 RESERVED
;; 	;; .uint   0x00000000              ; 0x244 RESERVED
;; 	;; .uint   0x00000000              ; 0x248 RESERVED
;; 	;; .uint   0x00000000              ; 0x24c RESERVED
;; 	;; .uint   0x00000000              ; 0x250 RESERVED
;; 	;; .uint   0x00000000              ; 0x254 RESERVED
;; 	;; .uint   0x00000000              ; 0x258 RESERVED
;; 	;; .uint   0x00000000              ; 0x25c RESERVED
;; 	;; .uint   0x00000000              ; 0x260 RESERVED
;; 	;; .uint   0x00000000              ; 0x264 RESERVED
;; 	;; .uint   0x00000000              ; 0x268 RESERVED
;; 	;; .uint   0x00000000              ; 0x26c RESERVED
;; 	;; .uint   0x00000000              ; 0x270 RESERVED
;; 	;; .uint   0x00000000              ; 0x274 RESERVED
;; 	;; .uint   0x00000000              ; 0x278 RESERVED
;; 	;; .uint   0x00000000              ; 0x27c RESERVED
;; 	;; .uint   0x00000000              ; 0x280 RESERVED
;; 	;; .uint   0x00000000              ; 0x284 RESERVED
;; 	;; .uint   0x00000000              ; 0x288 RESERVED
;; 	;; .uint   0x00000000              ; 0x28c RESERVED
;; 	;; .uint   0x00000000              ; 0x290 RESERVED
;; 	;; .uint   0x00000000              ; 0x294 RESERVED
;; 	;; .uint   0x00000000              ; 0x298 RESERVED
;; 	;; .uint   0x00000000              ; 0x29c RESERVED
;; 	;; .uint   0x00000000              ; 0x2a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x2a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x2a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x2ac RESERVED
;; 	;; .uint   0x00000000              ; 0x2b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x2b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x2b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x2bc RESERVED
;; 	;; .uint   0x00000000              ; 0x2c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x2c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x2c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x2cc RESERVED
;; 	;; .uint   0x00000000              ; 0x2d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x2d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x2d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x2dc RESERVED
;; 	;; .uint   0x00000000              ; 0x2e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x2e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x2e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x2ec RESERVED
;; 	;; .uint   0x00000000              ; 0x2f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x2f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x2f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x2fc RESERVED
;; 	;; .uint   0x00000000              ; 0x300 RESERVED
;; 	;; .uint   0x00000000              ; 0x304 RESERVED
;; 	;; .uint   0x00000000              ; 0x308 RESERVED
;; 	;; .uint   0x00000000              ; 0x30c RESERVED
;; 	;; .uint   0x00000000              ; 0x310 RESERVED
;; 	;; .uint   0x00000000              ; 0x314 RESERVED
;; 	;; .uint   0x00000000              ; 0x318 RESERVED
;; 	;; .uint   0x00000000              ; 0x31c RESERVED
;; 	;; .uint   0x00000000              ; 0x320 RESERVED
;; 	;; .uint   0x00000000              ; 0x324 RESERVED
;; 	;; .uint   0x00000000              ; 0x328 RESERVED
;; 	;; .uint   0x00000000              ; 0x32c RESERVED
;; 	;; .uint   0x00000000              ; 0x330 RESERVED
;; 	;; .uint   0x00000000              ; 0x334 RESERVED
;; 	;; .uint   0x00000000              ; 0x338 RESERVED
;; 	;; .uint   0x00000000              ; 0x33c RESERVED
;; 	;; .uint   0x00000000              ; 0x340 RESERVED
;; 	;; .uint   0x00000000              ; 0x344 RESERVED
;; 	;; .uint   0x00000000              ; 0x348 RESERVED
;; 	;; .uint   0x00000000              ; 0x34c RESERVED
;; 	;; .uint   0x00000000              ; 0x350 RESERVED
;; 	;; .uint   0x00000000              ; 0x354 RESERVED
;; 	;; .uint   0x00000000              ; 0x358 RESERVED
;; 	;; .uint   0x00000000              ; 0x35c RESERVED
;; 	;; .uint   0x00000000              ; 0x360 RESERVED
;; 	;; .uint   0x00000000              ; 0x364 RESERVED
;; 	;; .uint   0x00000000              ; 0x368 RESERVED
;; 	;; .uint   0x00000000              ; 0x36c RESERVED
;; 	;; .uint   0x00000000              ; 0x370 RESERVED
;; 	;; .uint   0x00000000              ; 0x374 RESERVED
;; 	;; .uint   0x00000000              ; 0x378 RESERVED
;; 	;; .uint   0x00000000              ; 0x37c RESERVED
;; 	;; .uint   0x00000000              ; 0x380 RESERVED
;; 	;; .uint   0x00000000              ; 0x384 RESERVED
;; 	;; .uint   0x00000000              ; 0x388 RESERVED
;; 	;; .uint   0x00000000              ; 0x38c RESERVED
;; 	;; .uint   0x00000000              ; 0x390 RESERVED
;; 	;; .uint   0x00000000              ; 0x394 RESERVED
;; 	;; .uint   0x00000000              ; 0x398 RESERVED
;; 	;; .uint   0x00000000              ; 0x39c RESERVED
;; 	;; .uint   0x00000000              ; 0x3a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x3a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x3a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x3ac RESERVED
;; 	;; .uint   0x00000000              ; 0x3b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x3b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x3b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x3bc RESERVED
;; 	;; .uint   0x00000000              ; 0x3c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x3c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x3c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x3cc RESERVED
;; 	;; .uint   0x00000000              ; 0x3d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x3d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x3d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x3dc RESERVED
;; 	;; .uint   0x00000000              ; 0x3e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x3e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x3e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x3ec RESERVED
;; 	;; .uint   0x00000000              ; 0x3f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x3f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x3f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x3fc RESERVED
;; 	;; .uint   0x00000000              ; 0x400 RESERVED
;; 	;; .uint   0x00000000              ; 0x404 RESERVED
;; 	;; .uint   0x00000000              ; 0x408 RESERVED
;; 	;; .uint   0x00000000              ; 0x40c RESERVED
;; 	;; .uint   0x00000000              ; 0x410 RESERVED
;; 	;; .uint   0x00000000              ; 0x414 RESERVED
;; 	;; .uint   0x00000000              ; 0x418 RESERVED
;; 	;; .uint   0x00000000              ; 0x41c RESERVED
;; 	;; .uint   0x00000000              ; 0x420 RESERVED
;; 	;; .uint   0x00000000              ; 0x424 RESERVED
;; 	;; .uint   0x00000000              ; 0x428 RESERVED
;; 	;; .uint   0x00000000              ; 0x42c RESERVED
;; 	;; .uint   0x00000000              ; 0x430 RESERVED
;; 	;; .uint   0x00000000              ; 0x434 RESERVED
;; 	;; .uint   0x00000000              ; 0x438 RESERVED
;; 	;; .uint   0x00000000              ; 0x43c RESERVED
;; 	;; .uint   0x00000000              ; 0x440 RESERVED
;; 	;; .uint   0x00000000              ; 0x444 RESERVED
;; 	;; .uint   0x00000000              ; 0x448 RESERVED
;; 	;; .uint   0x00000000              ; 0x44c RESERVED
;; 	;; .uint   0x00000000              ; 0x450 RESERVED
;; 	;; .uint   0x00000000              ; 0x454 RESERVED
;; 	;; .uint   0x00000000              ; 0x458 RESERVED
;; 	;; .uint   0x00000000              ; 0x45c RESERVED
;; 	;; .uint   0x00000000              ; 0x460 RESERVED
;; 	;; .uint   0x00000000              ; 0x464 RESERVED
;; 	;; .uint   0x00000000              ; 0x468 RESERVED
;; 	;; .uint   0x00000000              ; 0x46c RESERVED
;; 	;; .uint   0x00000000              ; 0x470 RESERVED
;; 	;; .uint   0x00000000              ; 0x474 RESERVED
;; 	;; .uint   0x00000000              ; 0x478 RESERVED
;; 	;; .uint   0x00000000              ; 0x47c RESERVED
;; 	;; .uint   0x00000000              ; 0x480 RESERVED
;; 	;; .uint   0x00000000              ; 0x484 RESERVED
;; 	;; .uint   0x00000000              ; 0x488 RESERVED
;; 	;; .uint   0x00000000              ; 0x48c RESERVED
;; 	;; .uint   0x00000000              ; 0x490 RESERVED
;; 	;; .uint   0x00000000              ; 0x494 RESERVED
;; 	;; .uint   0x00000000              ; 0x498 RESERVED
;; 	;; .uint   0x00000000              ; 0x49c RESERVED
;; 	;; .uint   0x00000000              ; 0x4a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x4a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x4a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x4ac RESERVED
;; 	;; .uint   0x00000000              ; 0x4b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x4b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x4b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x4bc RESERVED
;; 	;; .uint   0x00000000              ; 0x4c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x4c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x4c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x4cc RESERVED
;; 	;; .uint   0x00000000              ; 0x4d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x4d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x4d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x4dc RESERVED
;; 	;; .uint   0x00000000              ; 0x4e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x4e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x4e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x4ec RESERVED
;; 	;; .uint   0x00000000              ; 0x4f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x4f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x4f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x4fc RESERVED
;; 	;; .uint   0x00000000              ; 0x500 RESERVED
;; 	;; .uint   0x00000000              ; 0x504 RESERVED
;; 	;; .uint   0x00000000              ; 0x508 RESERVED
;; 	;; .uint   0x00000000              ; 0x50c RESERVED
;; 	;; .uint   0x00000000              ; 0x510 RESERVED
;; 	;; .uint   0x00000000              ; 0x514 RESERVED
;; 	;; .uint   0x00000000              ; 0x518 RESERVED
;; 	;; .uint   0x00000000              ; 0x51c RESERVED
;; 	;; .uint   0x00000000              ; 0x520 RESERVED
;; 	;; .uint   0x00000000              ; 0x524 RESERVED
;; 	;; .uint   0x00000000              ; 0x528 RESERVED
;; 	;; .uint   0x00000000              ; 0x52c RESERVED
;; 	;; .uint   0x00000000              ; 0x530 RESERVED
;; 	;; .uint   0x00000000              ; 0x534 RESERVED
;; 	;; .uint   0x00000000              ; 0x538 RESERVED
;; 	;; .uint   0x00000000              ; 0x53c RESERVED
;; 	;; .uint   0x00000000              ; 0x540 RESERVED
;; 	;; .uint   0x00000000              ; 0x544 RESERVED
;; 	;; .uint   0x00000000              ; 0x548 RESERVED
;; 	;; .uint   0x00000000              ; 0x54c RESERVED
;; 	;; .uint   0x00000000              ; 0x550 RESERVED
;; 	;; .uint   0x00000000              ; 0x554 RESERVED
;; 	;; .uint   0x00000000              ; 0x558 RESERVED
;; 	;; .uint   0x00000000              ; 0x55c RESERVED
;; 	;; .uint   0x00000000              ; 0x560 RESERVED
;; 	;; .uint   0x00000000              ; 0x564 RESERVED
;; 	;; .uint   0x00000000              ; 0x568 RESERVED
;; 	;; .uint   0x00000000              ; 0x56c RESERVED
;; 	;; .uint   0x00000000              ; 0x570 RESERVED
;; 	;; .uint   0x00000000              ; 0x574 RESERVED
;; 	;; .uint   0x00000000              ; 0x578 RESERVED
;; 	;; .uint   0x00000000              ; 0x57c RESERVED
;; 	;; .uint   0x00000000              ; 0x580 RESERVED
;; 	;; .uint   0x00000000              ; 0x584 RESERVED
;; 	;; .uint   0x00000000              ; 0x588 RESERVED
;; 	;; .uint   0x00000000              ; 0x58c RESERVED
;; 	;; .uint   0x00000000              ; 0x590 RESERVED
;; 	;; .uint   0x00000000              ; 0x594 RESERVED
;; 	;; .uint   0x00000000              ; 0x598 RESERVED
;; 	;; .uint   0x00000000              ; 0x59c RESERVED
;; 	;; .uint   0x00000000              ; 0x5a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x5a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x5a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x5ac RESERVED
;; 	;; .uint   0x00000000              ; 0x5b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x5b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x5b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x5bc RESERVED
;; 	;; .uint   0x00000000              ; 0x5c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x5c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x5c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x5cc RESERVED
;; 	;; .uint   0x00000000              ; 0x5d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x5d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x5d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x5dc RESERVED
;; 	;; .uint   0x00000000              ; 0x5e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x5e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x5e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x5ec RESERVED
;; 	;; .uint   0x00000000              ; 0x5f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x5f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x5f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x5fc RESERVED
;; 	;; .uint   0x00000000              ; 0x600 RESERVED
;; 	;; .uint   0x00000000              ; 0x604 RESERVED
;; 	;; .uint   0x00000000              ; 0x608 RESERVED
;; 	;; .uint   0x00000000              ; 0x60c RESERVED
;; 	;; .uint   0x00000000              ; 0x610 RESERVED
;; 	;; .uint   0x00000000              ; 0x614 RESERVED
;; 	;; .uint   0x00000000              ; 0x618 RESERVED
;; 	;; .uint   0x00000000              ; 0x61c RESERVED
;; 	;; .uint   0x00000000              ; 0x620 RESERVED
;; 	;; .uint   0x00000000              ; 0x624 RESERVED
;; 	;; .uint   0x00000000              ; 0x628 RESERVED
;; 	;; .uint   0x00000000              ; 0x62c RESERVED
;; 	;; .uint   0x00000000              ; 0x630 RESERVED
;; 	;; .uint   0x00000000              ; 0x634 RESERVED
;; 	;; .uint   0x00000000              ; 0x638 RESERVED
;; 	;; .uint   0x00000000              ; 0x63c RESERVED
;; 	;; .uint   0x00000000              ; 0x640 RESERVED
;; 	;; .uint   0x00000000              ; 0x644 RESERVED
;; 	;; .uint   0x00000000              ; 0x648 RESERVED
;; 	;; .uint   0x00000000              ; 0x64c RESERVED
;; 	;; .uint   0x00000000              ; 0x650 RESERVED
;; 	;; .uint   0x00000000              ; 0x654 RESERVED
;; 	;; .uint   0x00000000              ; 0x658 RESERVED
;; 	;; .uint   0x00000000              ; 0x65c RESERVED
;; 	;; .uint   0x00000000              ; 0x660 RESERVED
;; 	;; .uint   0x00000000              ; 0x664 RESERVED
;; 	;; .uint   0x00000000              ; 0x668 RESERVED
;; 	;; .uint   0x00000000              ; 0x66c RESERVED
;; 	;; .uint   0x00000000              ; 0x670 RESERVED
;; 	;; .uint   0x00000000              ; 0x674 RESERVED
;; 	;; .uint   0x00000000              ; 0x678 RESERVED
;; 	;; .uint   0x00000000              ; 0x67c RESERVED
;; 	;; .uint   0x00000000              ; 0x680 RESERVED
;; 	;; .uint   0x00000000              ; 0x684 RESERVED
;; 	;; .uint   0x00000000              ; 0x688 RESERVED
;; 	;; .uint   0x00000000              ; 0x68c RESERVED
;; 	;; .uint   0x00000000              ; 0x690 RESERVED
;; 	;; .uint   0x00000000              ; 0x694 RESERVED
;; 	;; .uint   0x00000000              ; 0x698 RESERVED
;; 	;; .uint   0x00000000              ; 0x69c RESERVED
;; 	;; .uint   0x00000000              ; 0x6a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x6a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x6a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x6ac RESERVED
;; 	;; .uint   0x00000000              ; 0x6b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x6b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x6b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x6bc RESERVED
;; 	;; .uint   0x00000000              ; 0x6c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x6c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x6c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x6cc RESERVED
;; 	;; .uint   0x00000000              ; 0x6d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x6d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x6d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x6dc RESERVED
;; 	;; .uint   0x00000000              ; 0x6e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x6e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x6e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x6ec RESERVED
;; 	;; .uint   0x00000000              ; 0x6f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x6f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x6f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x6fc RESERVED
;; 	;; .uint   0x00000000              ; 0x700 RESERVED
;; 	;; .uint   0x00000000              ; 0x704 RESERVED
;; 	;; .uint   0x00000000              ; 0x708 RESERVED
;; 	;; .uint   0x00000000              ; 0x70c RESERVED
;; 	;; .uint   0x00000000              ; 0x710 RESERVED
;; 	;; .uint   0x00000000              ; 0x714 RESERVED
;; 	;; .uint   0x00000000              ; 0x718 RESERVED
;; 	;; .uint   0x00000000              ; 0x71c RESERVED
;; 	;; .uint   0x00000000              ; 0x720 RESERVED
;; 	;; .uint   0x00000000              ; 0x724 RESERVED
;; 	;; .uint   0x00000000              ; 0x728 RESERVED
;; 	;; .uint   0x00000000              ; 0x72c RESERVED
;; 	;; .uint   0x00000000              ; 0x730 RESERVED
;; 	;; .uint   0x00000000              ; 0x734 RESERVED
;; 	;; .uint   0x00000000              ; 0x738 RESERVED
;; 	;; .uint   0x00000000              ; 0x73c RESERVED
;; 	;; .uint   0x00000000              ; 0x740 RESERVED
;; 	;; .uint   0x00000000              ; 0x744 RESERVED
;; 	;; .uint   0x00000000              ; 0x748 RESERVED
;; 	;; .uint   0x00000000              ; 0x74c RESERVED
;; 	;; .uint   0x00000000              ; 0x750 RESERVED
;; 	;; .uint   0x00000000              ; 0x754 RESERVED
;; 	;; .uint   0x00000000              ; 0x758 RESERVED
;; 	;; .uint   0x00000000              ; 0x75c RESERVED
;; 	;; .uint   0x00000000              ; 0x760 RESERVED
;; 	;; .uint   0x00000000              ; 0x764 RESERVED
;; 	;; .uint   0x00000000              ; 0x768 RESERVED
;; 	;; .uint   0x00000000              ; 0x76c RESERVED
;; 	;; .uint   0x00000000              ; 0x770 RESERVED
;; 	;; .uint   0x00000000              ; 0x774 RESERVED
;; 	;; .uint   0x00000000              ; 0x778 RESERVED
;; 	;; .uint   0x00000000              ; 0x77c RESERVED
;; 	;; .uint   0x00000000              ; 0x780 RESERVED
;; 	;; .uint   0x00000000              ; 0x784 RESERVED
;; 	;; .uint   0x00000000              ; 0x788 RESERVED
;; 	;; .uint   0x00000000              ; 0x78c RESERVED
;; 	;; .uint   0x00000000              ; 0x790 RESERVED
;; 	;; .uint   0x00000000              ; 0x794 RESERVED
;; 	;; .uint   0x00000000              ; 0x798 RESERVED
;; 	;; .uint   0x00000000              ; 0x79c RESERVED
;; 	;; .uint   0x00000000              ; 0x7a0 RESERVED
;; 	;; .uint   0x00000000              ; 0x7a4 RESERVED
;; 	;; .uint   0x00000000              ; 0x7a8 RESERVED
;; 	;; .uint   0x00000000              ; 0x7ac RESERVED
;; 	;; .uint   0x00000000              ; 0x7b0 RESERVED
;; 	;; .uint   0x00000000              ; 0x7b4 RESERVED
;; 	;; .uint   0x00000000              ; 0x7b8 RESERVED
;; 	;; .uint   0x00000000              ; 0x7bc RESERVED
;; 	;; .uint   0x00000000              ; 0x7c0 RESERVED
;; 	;; .uint   0x00000000              ; 0x7c4 RESERVED
;; 	;; .uint   0x00000000              ; 0x7c8 RESERVED
;; 	;; .uint   0x00000000              ; 0x7cc RESERVED
;; 	;; .uint   0x00000000              ; 0x7d0 RESERVED
;; 	;; .uint   0x00000000              ; 0x7d4 RESERVED
;; 	;; .uint   0x00000000              ; 0x7d8 RESERVED
;; 	;; .uint   0x00000000              ; 0x7dc RESERVED
;; 	;; .uint   0x00000000              ; 0x7e0 RESERVED
;; 	;; .uint   0x00000000              ; 0x7e4 RESERVED
;; 	;; .uint   0x00000000              ; 0x7e8 RESERVED
;; 	;; .uint   0x00000000              ; 0x7ec RESERVED
;; 	;; .uint   0x00000000              ; 0x7f0 RESERVED
;; 	;; .uint   0x00000000              ; 0x7f4 RESERVED
;; 	;; .uint   0x00000000              ; 0x7f8 RESERVED
;; 	;; .uint   0x00000000              ; 0x7fc RESERVED
;; 	;; .uint   0x00000000              ; 0x800 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x804 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x808 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x80c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x810 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x814 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x818 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x81c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x820 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x824 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x828 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x82c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x830 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x834 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x838 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x83c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x840 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x844 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x848 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x84c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x850 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x854 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x858 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x85c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x860 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x864 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x868 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x86c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x870 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x874 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x878 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x87c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x880 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x884 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x888 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x88c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x890 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x894 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x898 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x89c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8a0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8a4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8a8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8ac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8b0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8b4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8b8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8bc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8c0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8c4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8c8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8cc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8d0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8d4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8d8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8dc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8e0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8e4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8e8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8ec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8f0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8f4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8f8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x8fc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x900 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x904 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x908 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x90c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x910 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x914 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x918 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x91c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x920 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x924 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x928 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x92c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x930 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x934 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x938 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x93c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x940 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x944 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x948 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x94c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x950 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x954 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x958 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x95c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x960 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x964 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x968 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x96c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x970 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x974 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x978 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x97c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x980 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x984 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x988 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x98c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x990 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x994 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x998 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x99c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9a0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9a4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9a8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9ac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9b0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9b4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9b8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9bc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9c0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9c4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9c8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9cc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9d0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9d4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9d8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9dc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9e0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9e4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9e8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9ec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9f0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9f4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9f8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0x9fc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa00 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa04 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa08 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa0c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa10 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa14 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa18 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa1c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa20 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa24 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa28 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa2c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa30 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa34 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa38 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa3c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa40 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa44 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa48 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa4c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa50 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa54 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa58 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa5c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa60 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa64 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa68 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa6c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa70 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa74 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa78 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa7c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa80 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa84 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa88 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa8c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa90 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa94 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa98 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xa9c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaa0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaa4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaa8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xab0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xab4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xab8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xabc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xac0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xac4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xac8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xacc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xad0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xad4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xad8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xadc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xae0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xae4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xae8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaf0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaf4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xaf8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xafc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb00 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb04 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb08 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb0c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb10 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb14 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb18 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb1c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb20 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb24 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb28 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb2c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb30 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb34 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb38 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb3c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb40 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb44 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb48 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb4c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb50 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb54 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb58 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb5c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb60 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb64 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb68 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb6c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb70 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb74 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb78 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb7c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb80 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb84 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb88 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb8c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb90 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb94 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb98 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xb9c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xba0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xba4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xba8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbb0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbb4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbb8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbbc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbc0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbc4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbc8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbcc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbd0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbd4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbd8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbdc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbe0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbe4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbe8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbf0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbf4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbf8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xbfc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc00 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc04 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc08 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc0c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc10 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc14 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc18 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc1c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc20 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc24 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc28 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc2c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc30 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc34 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc38 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc3c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc40 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc44 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc48 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc4c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc50 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc54 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc58 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc5c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc60 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc64 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc68 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc6c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc70 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc74 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc78 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc7c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc80 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc84 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc88 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc8c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc90 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc94 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc98 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xc9c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xca0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xca4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xca8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcb0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcb4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcb8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcbc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcc0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcc4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcc8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xccc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcd0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcd4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcd8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcdc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xce0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xce4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xce8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcf0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcf4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcf8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xcfc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd00 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd04 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd08 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd0c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd10 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd14 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd18 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd1c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd20 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd24 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd28 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd2c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd30 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd34 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd38 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd3c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd40 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd44 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd48 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd4c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd50 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd54 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd58 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd5c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd60 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd64 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd68 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd6c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd70 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd74 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd78 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd7c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd80 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd84 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd88 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd8c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd90 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd94 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd98 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xd9c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xda0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xda4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xda8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdb0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdb4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdb8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdbc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdc0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdc4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdc8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdcc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdd0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdd4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdd8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xddc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xde0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xde4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xde8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdf0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdf4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdf8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xdfc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe00 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe04 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe08 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe0c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe10 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe14 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe18 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe1c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe20 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe24 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe28 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe2c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe30 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe34 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe38 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe3c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe40 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe44 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe48 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe4c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe50 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe54 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe58 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe5c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe60 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe64 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe68 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe6c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe70 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe74 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe78 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe7c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe80 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe84 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe88 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe8c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe90 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe94 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe98 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xe9c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xea0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xea4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xea8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xeac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xeb0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xeb4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xeb8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xebc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xec0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xec4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xec8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xecc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xed0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xed4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xed8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xedc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xee0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xee4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xee8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xeec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xef0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xef4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xef8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xefc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf00 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf04 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf08 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf0c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf10 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf14 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf18 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf1c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf20 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf24 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf28 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf2c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf30 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf34 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf38 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf3c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf40 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf44 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf48 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf4c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf50 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf54 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf58 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf5c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf60 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf64 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf68 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf6c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf70 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf74 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf78 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf7c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf80 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf84 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf88 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf8c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf90 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf94 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf98 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xf9c PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfa0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfa4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfa8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfac PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfb0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfb4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfb8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfbc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfc0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfc4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfc8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfcc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfd0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfd4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfd8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfdc PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfe0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfe4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfe8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xfec PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xff0 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xff4 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xff8 PLATFORM SPECIFIC
;; 	;; .uint   0x00000000              ; 0xffc PLATFORM SPECIFIC

	.endif  ;__eSPI_slave_registers_h
