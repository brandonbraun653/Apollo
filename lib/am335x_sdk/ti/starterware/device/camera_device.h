/**
 *  \file  camera_device.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the camera sensor devices.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef CAMERA_DEVICE_H_
#define CAMERA_DEVICE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief I2C Slave address for camera sensor OmniVision OV2659 */
#define OV2659_CAMERA_SLAVE_ADDR         (0x30)

/* OmniVision OV2659 registers */
/** \brief Software Standby register for camera sensor OmniVision OV2659 */
#define OV2659_SOFTWARE_STANDBY          (0x0100)
/** \brief Software Reset register for camera sensor OmniVision OV2659 */
#define OV2659_SOFTWARE_RESET            (0x0103)
/** \brief IO Control0 register for camera sensor OmniVision OV2659 */
#define OV2659_IO_CTRL00                 (0x3000)
/** \brief IO Control1 register for camera sensor OmniVision OV2659 */
#define OV2659_IO_CTRL01                 (0x3001)
/** \brief IO Control2 register for camera sensor OmniVision OV2659 */
#define OV2659_IO_CTRL02                 (0x3002)
/** \brief Output Value0 register for camera sensor OmniVision OV2659 */
#define OV2659_OUTPUT_VALUE00            (0x3008)
/** \brief Output Value1 register for camera sensor OmniVision OV2659 */
#define OV2659_OUTPUT_VALUE01            (0x3009)
/** \brief Output Value2 register for camera sensor OmniVision OV2659 */
#define OV2659_OUTPUT_VALUE02            (0x300D)
/** \brief Output Select0 register for camera sensor OmniVision OV2659 */
#define OV2659_OUTPUT_SELECT00           (0x300E)
/** \brief Output Select1 register for camera sensor OmniVision OV2659 */
#define OV2659_OUTPUT_SELECT01           (0x300F)
/** \brief Output Select2 register for camera sensor OmniVision OV2659 */
#define OV2659_OUTPUT_SELECT02           (0x3010)
/** \brief Output Drive register for camera sensor OmniVision OV2659 */
#define OV2659_OUTPUT_DRIVE              (0x3011)
/** \brief Input Readout0 register for camera sensor OmniVision OV2659 */
#define OV2659_INPUT_READOUT00           (0x302D)
/** \brief Input Readout1 register for camera sensor OmniVision OV2659 */
#define OV2659_INPUT_READOUT01           (0x302E)
/** \brief Input Readout2 register for camera sensor OmniVision OV2659 */
#define OV2659_INPUT_READOUT02           (0x302F)

/** \brief SC PLL Control0 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_PLL_CTRL0              (0x3003)
/** \brief SC PLL Control1 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_PLL_CTRL1              (0x3004)
/** \brief SC PLL Control2 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_PLL_CTRL2              (0x3005)
/** \brief SC PLL Control2 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_PLL_CTRL3              (0x3006)
/** \brief SC Chip-ID High register for camera sensor OmniVision OV2659 */
#define OV2659_SC_CHIP_ID_H              (0x300A)
/** \brief SC Chip-ID Low register for camera sensor OmniVision OV2659 */
#define OV2659_SC_CHIP_ID_L              (0x300B)
/** \brief SC PWC register for camera sensor OmniVision OV2659 */
#define OV2659_SC_PWC                    (0x3014)
/** \brief SC ClkRst0 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_CLKRST0                (0x301A)
/** \brief SC ClkRst1 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_CLKRST1                (0x301B)
/** \brief SC ClkRst2 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_CLKRST2                (0x301C)
/** \brief SC ClkRst3 register for camera sensor OmniVision OV2659 */
#define OV2659_SC_CLKRST3                (0x301D)
/** \brief SC Sub ID register for camera sensor OmniVision OV2659 */
#define OV2659_SC_SUB_ID                 (0x302A)
/** \brief SC SCCB ID register for camera sensor OmniVision OV2659 */
#define OV2659_SC_SCCB_ID                (0x302B)

/** \brief Group Address0 register for camera sensor OmniVision OV2659 */
#define OV2659_GROUP_ADDRESS_00          (0x3200)
/** \brief Group Address1 register for camera sensor OmniVision OV2659 */
#define OV2659_GROUP_ADDRESS_01          (0x3201)
/** \brief Group Address2 register for camera sensor OmniVision OV2659 */
#define OV2659_GROUP_ADDRESS_02          (0x3202)
/** \brief Group Address3 register for camera sensor OmniVision OV2659 */
#define OV2659_GROUP_ADDRESS_03          (0x3203)
/** \brief Group Access register for camera sensor OmniVision OV2659 */
#define OV2659_GROUP_ACCESS              (0x3208)

/** \brief AWB R-Gain High register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_R_GAIN_H              (0x3400)
/** \brief AWB R-Gain Low register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_R_GAIN_L              (0x3401)
/** \brief AWB G-Gain High register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_G_GAIN_H              (0x3402)
/** \brief AWB G-Gain Low register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_G_GAIN_L              (0x3403)
/** \brief AWB B-Gain High register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_B_GAIN_H              (0x3404)
/** \brief AWB B-Gain Low register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_B_GAIN_L              (0x3405)
/** \brief AWB Manual Control register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_MANUAL_CONTROL        (0x3406)

/** \brief Timing HS High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HS_H               (0x3800)
/** \brief Timing HS Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HS_L               (0x3801)
/** \brief Timing VS High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VS_H               (0x3802)
/** \brief Timing VS Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VS_L               (0x3803)
/** \brief Timing HW High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HW_H               (0x3804)
/** \brief Timing HW Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HW_L               (0x3805)
/** \brief Timing VH High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VH_H               (0x3806)
/** \brief Timing VH Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VH_L               (0x3807)
/** \brief Timing DVPHO High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_DVPHO_H            (0x3808)
/** \brief Timing DVPHO Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_DVPHO_L            (0x3809)
/** \brief Timing DVPVO High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_DVPVO_H            (0x380A)
/** \brief Timing DVPVO Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_DVPVO_L            (0x380B)
/** \brief Timing HTS High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HTS_H              (0x380C)
/** \brief Timing HTS Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HTS_L              (0x380D)
/** \brief Timing VTS High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VTS_H              (0x380E)
/** \brief Timing VTS Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VTS_L              (0x380F)
/** \brief Timing HOFFS High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HOFFS_H            (0x3810)
/** \brief Timing HOFFS Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HOFFS_L            (0x3811)
/** \brief Timing Voffs High register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VOFFS_H            (0x3812)
/** \brief Timing VOFFS Low register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VOFFS_L            (0x3813)
/** \brief Timing XINC register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_XINC               (0x3814)
/** \brief Timing YINC register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_YINC               (0x3815)
/** \brief Timing Vertical format register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_VERT_FORMAT        (0x3820)
/** \brief Timing Horizontal format register for camera sensor OmniVision OV2659 */
#define OV2659_TIMING_HORIZ_FORMAT       (0x3821)

/** \brief AEC PK Exposure High register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_PK_EXPOSURE_H         (0x3500)
/** \brief AEC PK Exposure M register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_PK_EXPOSURE_M         (0x3501)
/** \brief AEC PK Exposure L register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_PK_EXPOSURE_L         (0x3502)
/** \brief AEC PK Manual register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_PK_MANUAL             (0x3503)
/** \brief AEC Manual Gain H register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_MANUAL_GAIN_H         (0x3504)
/** \brief AEC Manual Gain L register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_MANUAL_GAIN_L         (0x3505)
/** \brief AEC Add VTS H register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_ADD_VTS_H             (0x3506)
/** \brief AEC Add VTS L register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_ADD_VTS_L             (0x3507)
/** \brief AEK PK Control8 register for camera sensor OmniVision OV2659 */
#define OV2659_AEK_PK_CTRL_08            (0x3508)
/** \brief AEK PK Control9 register for camera sensor OmniVision OV2659 */
#define OV2659_AEK_PK_CTRL_09            (0x3509)
/** \brief AEC PK Real Gain High register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_PK_REAL_GAIN_H        (0x350A)
/** \brief AEC PK Real Gain Low register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_PK_REAL_GAIN_L        (0x350B)
/** \brief AEC Real Gain Read H register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_REAL_GAIN_READ_H      (0x3510)
/** \brief AEC Real Gain Read L register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_REAL_GAIN_READ_L      (0x3511)
/** \brief AEC SNR Gain Read H register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_SNR_GAIN_READ_H       (0x3512)
/** \brief AEC SNR Gain Read L register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_SNR_GAIN_READ_L       (0x3513)
/** \brief AEC control register for camera sensor OmniVision OV2659 */
#define OV2659_AEC_CTRL(num)             (0x3A00 + num)

/** \brief Frame Control0 register for camera sensor OmniVision OV2659 */
#define OV2659_FRAME_CTRL00              (0x4201)
/** \brief Frame Control1 register for camera sensor OmniVision OV2659 */
#define OV2659_FRAME_CTRL01              (0x4202)
/** \brief Format Control0 register for camera sensor OmniVision OV2659 */
#define OV2659_FORMAT_CTRL00             (0x4300)
/** \brief Clipping Control register for camera sensor OmniVision OV2659 */
#define OV2659_CLIPPING_CTRL             (0x4301)

/** \brief VFifo Read Control register for camera sensor OmniVision OV2659 */
#define OV2659_VFIFO_READ_CTRL           (0x4601)
/** \brief VFifo Control5 register for camera sensor OmniVision OV2659 */
#define OV2659_VFIFO_CTRL05              (0x4605)
/** \brief Vfifo Read Start H register for camera sensor OmniVision OV2659 */
#define OV2659_VFIFO_READ_START_H        (0x4608)
/** \brief Vfifo Read Start L register for camera sensor OmniVision OV2659 */
#define OV2659_VFIFO_READ_START_L        (0x4609)

/** \brief DVP Control1 register for camera sensor OmniVision OV2659 */
#define OV2659_DVP_CTRL01                (0x4704)
/** \brief DVP Control2 register for camera sensor OmniVision OV2659 */
#define OV2659_DVP_CTRL02                (0x4708)
/** \brief DVP Control3 register for camera sensor OmniVision OV2659 */
#define OV2659_DVP_CTRL03                (0x4709)

/** \brief ISP Control 0 register for camera sensor OmniVision OV2659 */
#define OV2659_ISP_CTRL00                (0x5000)
/** \brief ISP Control 1 register for camera sensor OmniVision OV2659 */
#define OV2659_ISP_CTRL01                (0x5001)
/** \brief ISP Control 2 register for camera sensor OmniVision OV2659 */
#define OV2659_ISP_CTRL02                (0x5002)
/** \brief ISP Control 7 register for camera sensor OmniVision OV2659 */
#define OV2659_ISP_CTRL07                (0x5007)
/** \brief ISP Pre Control 0 register for camera sensor OmniVision OV2659 */
#define OV2659_ISP_PRE_CTRL00            (0x50A0)

/** \brief BLC Control 0 register for camera sensor OmniVision OV2659 */
#define OV2659_BLC_CTRL00                (0x4000)
/** \brief BLC Start Line register for camera sensor OmniVision OV2659 */
#define OV2659_BLC_START_LINE            (0x4001)
/** \brief BLC Control 2 register for camera sensor OmniVision OV2659 */
#define OV2659_BLC_CTRL02                (0x4002)
/** \brief BLC Control 3 register for camera sensor OmniVision OV2659 */
#define OV2659_BLC_CTRL03                (0x4003)
/** \brief BLC Line Num register for camera sensor OmniVision OV2659 */
#define OV2659_BLC_LINE_NUM              (0x4004)
/** \brief BLC target register for camera sensor OmniVision OV2659 */
#define OV2659_BLC_TARGET                (0x4009)

/** \brief LENC Red X0 H register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_RED_X0_H             (0x500C)
/** \brief LENC Red X0 L register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_RED_X0_L             (0x500D)
/** \brief LENC Red Y0 H register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_RED_Y0_H             (0x500E)
/** \brief LENC Red Y0 L register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_RED_Y0_L             (0x500F)
/** \brief LENC Red A1 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_RED_A1               (0x5010)
/** \brief LENC Red B1 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_RED_B1               (0x5011)
/** \brief LENC Red A2-B2 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_RED_A2_B2            (0x5012)
/** \brief LENC Green X0 H register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_GREEN_X0_H           (0x5013)
/** \brief LENC Green X0 L register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_GREEN_X0_L           (0x5014)
/** \brief LENC Green Y0 H register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_GREEN_Y0_H           (0x5015)
/** \brief LENC Green Y0 L register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_GREEN_Y0_L           (0x5016)
/** \brief LENC Green A1 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_GREEN_A1             (0x5017)
/** \brief LENC Green B1 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_GREEN_B1             (0x5018)
/** \brief LENC Green A2-B2 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_GREEN_A2_B2          (0x5019)
/** \brief LENC Blue X0 H register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_BLUE_X0_H            (0x501A)
/** \brief LENC Blue X0 L register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_BLUE_X0_L            (0x501B)
/** \brief LENC Blue Y0 H register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_BLUE_Y0_H            (0x501C)
/** \brief LENC Blue Y0 L register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_BLUE_Y0_L            (0x501D)
/** \brief LENC Blue A1 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_BLUE_A1              (0x501E)
/** \brief LENC Blue B1 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_BLUE_B1              (0x501F)
/** \brief LENC Blue A2-B2 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_BLUE_A2_B2           (0x5020)
/** \brief LENC Control0 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_CTRL00               (0x5021)
/** \brief LENC Control1 register for camera sensor OmniVision OV2659 */
#define OV2659_LENC_CTRL01               (0x5021)

/** \brief Coefficient threshold register for camera sensor OmniVision OV2659 */
#define OV2659_COEFFICIENT_THRESH        (0x5023)
/** \brief Coefficient manual value register for camera sensor OmniVision OV2659 */
#define OV2659_COEFFICIENT_MANUAL_VAL    (0x5024)

/** \brief Gamma YST register for camera sensor OmniVision OV2659 */
#define OV2659_GAMMA_YST(num)            (0x5025 + (num - 1))
/** \brief Gamma YSLP register for camera sensor OmniVision OV2659 */
#define OV2659_GAMMA_YSLP                (0x5034)

/** \brief AWB Control0 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL00                (0x5035)
/** \brief AWB Control1 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL01                (0x5036)
/** \brief AWB Control2 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL02                (0x5037)
/** \brief AWB Control3 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL03                (0x5038)
/** \brief AWB Control4 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL04                (0x5039)
/** \brief AWB Local Limit register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_LOCAL_LIMIT           (0x503A)
/** \brief AWB Control12 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL12                (0x5049)
/** \brief AWB Control13 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL13                (0x504A)
/** \brief AWB Control14 register for camera sensor OmniVision OV2659 */
#define OV2659_AWB_CTRL14                (0x504B)

/** \brief AVG Control register for camera sensor OmniVision OV2659 */
#define OV2659_AVG_CTRL(num)             (0x5060 + num)
/** \brief AVG ReadOut register for camera sensor OmniVision OV2659 */
#define OV2659_AVG_READOUT               (0x5237)

/** \brief Sharpenmt threshold 1 register for camera sensor OmniVision OV2659 */
#define OV2659_SHARPENMT_THRESH1         (0x5064)
/** \brief Sharpenmt threshold 2 register for camera sensor OmniVision OV2659 */
#define OV2659_SHARPENMT_THRESH2         (0x5065)
/** \brief Sharpenmt offset1 register for camera sensor OmniVision OV2659 */
#define OV2659_SHARPENMT_OFFSET1         (0x5066)
/** \brief Sharpenmt offset2 register for camera sensor OmniVision OV2659 */
#define OV2659_SHARPENMT_OFFSET2         (0x5067)
/** \brief Denoise threshold1 register for camera sensor OmniVision OV2659 */
#define OV2659_DENOISE_THRESH1           (0x5068)
/** \brief Denoise threshold2 register for camera sensor OmniVision OV2659 */
#define OV2659_DENOISE_THRESH2           (0x5069)
/** \brief Denoise offset1 register for camera sensor OmniVision OV2659 */
#define OV2659_DENOISE_OFFSET1           (0x506A)
/** \brief Denoise offset2 register for camera sensor OmniVision OV2659 */
#define OV2659_DENOISE_OFFSET2           (0x506B)
/** \brief Sharpen threshold1 register for camera sensor OmniVision OV2659 */
#define OV2659_SHARPEN_THRESH1           (0x506C)
/** \brief Sharpen threshold2 register for camera sensor OmniVision OV2659 */
#define OV2659_SHARPEN_THRESH2           (0x506D)
/** \brief CIP Control0 register for camera sensor OmniVision OV2659 */
#define OV2659_CIP_CTRL00                (0x506E)
/** \brief CIP Control1 register for camera sensor OmniVision OV2659 */
#define OV2659_CIP_CTRL01                (0x506F)

/** \brief CMX register for camera sensor OmniVision OV2659 */
#define OV2659_CMX(num)                  (0x5070 + (num - 1))
/** \brief CMX Sign register for camera sensor OmniVision OV2659 */
#define OV2659_CMX_SIGN                  (0x5079)
/** \brief CMX Misc control register for camera sensor OmniVision OV2659 */
#define OV2659_CMX_MISC_CTRL             (0x507A)

/** \brief SDE control register for camera sensor OmniVision OV2659 */
#define OV2659_SDE_CTRL(num)             (0x507B + num)

/** \brief Scale control0 register for camera sensor OmniVision OV2659 */
#define OV2659_SCALE_CTRL0               (0x5600)
/** \brief Scale control1 register for camera sensor OmniVision OV2659 */
#define OV2659_SCALE_CTRL1               (0x5601)
/** \brief XSC H register for camera sensor OmniVision OV2659 */
#define OV2659_XSC_H                     (0x5602)
/** \brief XSC L register for camera sensor OmniVision OV2659 */
#define OV2659_XSC_L                     (0x5603)
/** \brief YSC H register for camera sensor OmniVision OV2659 */
#define OV2659_YSC_H                     (0x5604)
/** \brief YSC L register for camera sensor OmniVision OV2659 */
#define OV2659_YSC_L                     (0x5605)
/** \brief VOffset register for camera sensor OmniVision OV2659 */
#define OV2659_VOFFSET                   (0x5606)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding the camera sensor configuration parameters. */
typedef struct cameraDeviceData
{
    uint32_t devId;
    /**< CAMERA sensor device ID. */
}cameraDeviceData_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API returns the CAMERA SENSOR related data according to the
 *        camera sensor that is connected to the board.
 *
 * \param devId The device id of the device that is connected to DSS.
 *
 * \retval CAMERA_Device_Data Pointer to the camera sensor device data.
 */
cameraDeviceData_t *CAMERAGetDeviceData(uint32_t devId);

/**
 * \brief This API returns the list of Camera sensor devices available.
 *
 * \retval camera_device_id_list Pointer to the Camera device ID list
 */
uint32_t * CAMERAGetDeviceIdList(void);

/**
 * \brief This API initializes the camera sensor using i2c interface. This will
 *        write register configuration values of the sensor through i2c
 *        interface.
 *
 * \param cameraInstance   Instance number of the camera used.
 * \param i2cInstNum       I2C instance number to which sensor control interface
 *                         is connected.
 * \param devId            Camera sensor device ID.
 * \param frmWidth         Input image frame width in number of pixels per line.
 * \param frmHeight        Input image height in number of liner per panel.
 * \param frmFormat        Input pixel format.
 *
 * \retval S_PASS Camera sensor configuration is successful.
 * \retval E_FAIL Camera sensor configuration is failed.
 */
int32_t CAMERADeviceInit(uint32_t cameraInstance,
                         uint32_t i2cInstNum,
                         uint32_t devId,
                         uint32_t frmWidth,
                         uint32_t frmHeight,
                         uint32_t frmFormat);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CAMERA_DEVICE_H_ */
