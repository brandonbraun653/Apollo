/**
 *  \file    sbl_flash_offset_cfg.h
 *
 *  \brief   Header file to define the location of application and  
 *           other load binaries in flash used by SBL.
 */

/**
 *  \copyright Copyright (C) 2017 - 2018 Texas Instruments Incorporated -
 *             http://www.ti.com/
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

 #ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define SBL_MCSPI_IMAGE_OFFSET                   (128U * 1024U)

#define SBL_MCSPI_TIESC_EEPROM_OFFSET            (64U * 1024U)
#define SBL_MCSPI_HOST_INTERFACE_OFFSET          (80U * 1024U)
#define SBL_MCSPI_FRAME_HANDLER_OFFSET           (100U * 1024U)
 
 /** \brief Offset of Binary Images other than application */
#ifdef BIN_INSTALL
#define NUM_BIN_IMAGES                         3

const unsigned int sbl_binOffsets[NUM_BIN_IMAGES] = {
				SBL_MCSPI_TIESC_EEPROM_OFFSET,
				SBL_MCSPI_HOST_INTERFACE_OFFSET,
				SBL_MCSPI_FRAME_HANDLER_OFFSET
};
				   
#endif

#ifdef __cplusplus
}
#endif
